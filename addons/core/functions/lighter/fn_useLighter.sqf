#include "../../script_component.hpp"

/*
* Author: Zorn
* Function to use the lighter, play sound and remove 1 unit from "magazine type lighters"
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


// Why check if it can be checked before ?
/*
if (!(QPVAR(matches) in (magazines _unit)) && !(QPVAR(lighter) in (magazines _unit))) exitWith {
    [QGVAR(EH_notify), [LLSTRING(no_matches_or_lighter), 2.5], _unit] call CBA_fnc_targetEvent;
    false
};
*/

params [ "_unit", ["_forced", false, [true]] ];

[ _unit ] call FUNC(getLighter) params [ "_className", "_type" ];

if ( _className isEqualTo false && {!_forced} ) exitWith {};

// Reduce Magazine Size if its a Magazine
if ( _type isEqualTo "typeMagazine" ) then { [ _unit, _className ] call FUNC(removeItemFromMag); };

// Play sound get From Lighter Class)
private _sound = switch (_type) do {
    case "typeMagazine": { [ configFile >> "CfgMagazines" >> _className >> QPVAR(LighterSound) ] call CBA_fnc_getCfgDataRandom };
    case "typeItem":     { [ configFile >> "CfgWeapons"   >> _className >> QPVAR(LighterSound) ] call CBA_fnc_getCfgDataRandom };
    default { QGVAR(matches_01) };
};


[ CBA_fnc_serverEvent , [QGVAR(EH_useLighter), [_unit] ], 1.5 ] call CBA_fnc_waitAndExecute;

[_unit, _sound, nil, true, true, true] call CBA_fnc_globalSay3D;

[QGVAR(API_useLighter_local),  [_unit, _className, _type]] call CBA_fnc_localEvent;
[QGVAR(API_useLighter_server), [_unit, _className, _type]] call CBA_fnc_serverEvent;
