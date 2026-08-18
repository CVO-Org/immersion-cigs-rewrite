#include "..\..\script_component.hpp"

/*
* Author: Zorn
* Function to be triggered by the aiCigs Module
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

diag_log format ['[CVO](debug)(fn_aiCigs_module) _this: %1', _this];

params [
	["_logic", objNull, [objNull]],		// Argument 0 is module logic
	["_units", [], [[]]],				// Argument 1 is a list of affected units (affected by value selected in the 'class Units' argument))
	["_activated", true, [true]]		// True when the module was activated, false when it is deactivated (i.e., synced triggers are no longer active)
];

// Get and Validate Input
private _west = _logic getVariable [QEGVAR(aiCigs,west), ""] splitString " ," select { getNumber (configFile >> "CfgMagazines" >> _x >> QPVAR(isPack)) isEqualTo 1 };
private _east = _logic getVariable [QEGVAR(aiCigs,east), ""] splitString " ," select { getNumber (configFile >> "CfgMagazines" >> _x >> QPVAR(isPack)) isEqualTo 1 };
private _guer = _logic getVariable [QEGVAR(aiCigs,guer), ""] splitString " ," select { getNumber (configFile >> "CfgMagazines" >> _x >> QPVAR(isPack)) isEqualTo 1 };
private _civ  = _logic getVariable [QEGVAR(aiCigs,civ),  ""] splitString " ," select { getNumber (configFile >> "CfgMagazines" >> _x >> QPVAR(isPack)) isEqualTo 1 };

// Create hashmap, but only if there's any actual values
private "_map";
{
	_x params ["_key", "_value"];
	if (_value isEqualTo []) then { continue };
	if (isNil "_map") then { _map = createHashMap; };
	_map set [_key, _value];

} forEach [["WEST",_west], ["EAST", _east], ["GUER", _guer], ["CIV", _civ]];

if (isNil "_map") exitWith { INFO("Immersive Cigs - aiCigs Module has not been stored - no valid input"); };

missionNamespace setVariable [QEGVAR(aiCigs,module), _map];
INFO_1("Immersive Cigs - aiCigs Module has been stored: %1",_map);
