#include "../../script_component.hpp"

/*
* Author: Zorn
* Function to create the hashmap and add/remove entries.
* Key: side as string
* Value: Array of classnames
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


params ["_setting", "_value"];

if !("set_aiCigs_custom_#" in _setting) exitWith {};

private _arr = _setting splitString "#" select 1 splitString "_";
private _sideStr = _arr deleteAt 0;
private _className = _arr joinString "_";

private _map = missionNamespace getVariable QEGVAR(aiCigs,settings);

if (isNil "_map" && {isNil "_value"}) exitWith {};

if (isNil "_map") then {
    _map = createHashMap;
    missionNamespace setVariable [QEGVAR(aiCigs,settings), _map];
};

private _array = _map getOrDefault [_sideStr, [], true];

switch (_value) do {
    case true:  { _array pushBackUnique _className };
    case false: { _array = _array - [_className] };
};
