#include "../../script_component.hpp"

/*
* Author: Zorn
* Function to handle the smoke particles
*
* Arguments:
*
* Return Value:
* None
*
* Example:
* ['something', player] call prefix_component_fnc_functionname
*
* Public: No
*/


params ["_unit", "_cigConfig"];

if !(lifeState _unit in ["HEALTHY", "INJURED"]) exitWith {};


private _sound = [_cigConfig >> QPVAR(smokeSound)] call CBA_fnc_getCfgDataRandom;

if (isNil "_sound") then { _sound = selectRandom [QPVAR(smoke_3),QPVAR(smoke_4)] };

[_unit, _sound, 15, true, false, true] call CBA_fnc_globalSay3d;

[
    {
        params ["_unit", "_cigConfig"];

        private _multiplier = getNumber (_cigConfig >> QPVAR(smokeMultiplier));

        private _source = "#particleSource" createVehicleLocal getPosATL _unit;

        _source setParticleParams [
            "\A3\data_f\cl_basic",
            "",
            "Billboard",
            0.5,
            2,
            [0, 0, 0],
            [0, 0.1, -0.1],
            1,
            1.2,
            1,
            0.1,
            [0.1 * _multiplier, 0.2 * _multiplier, 0.1 * _multiplier],
            [[0.2 * _multiplier, 0.2 * _multiplier, 0.2 * _multiplier, 0.3 * _multiplier], [0, 0, 0, 0.01], [1, 1, 1, 0]],
            [500],
            1,
            0.04,
            "",
            "",
            _source
        ];

        _source setParticleRandom [2, [0, 0, 0], [0.25, 0.25, 0.25], 0, 0.5, [0, 0, 0, 0.1], 0, 0, 10];
        _source setDropInterval linearConversion [0, 1, SET(smoke_particles), 0.025, 0.005, true];

        _source attachTo [_unit, [0, 0.06, 0], "head"];

        [{
            params ["_source"];
            deleteVehicle _source;
        }, [_source], 0.5] call CBA_fnc_waitAndExecute;
    },
    _this,
    2.5
] call CBA_fnc_waitAndExecute;
