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
private _className = toLowerANSI (_arr joinString "_");

private _map = missionNamespace getVariable QEGVAR(aiCigs,settings);

if ( isNil "_map" && { _value isEqualTo false } ) exitWith {};
if ( isNil "_map" ) then {
    _map = createHashMap;
    EGVAR(aiCigs,settings) = _map;
};

private _array = _map getOrDefault [_sideStr, [], true];

switch (_value) do {
    case true:  { _array pushBackUnique _className };
    case false: {
        private _index = _array find _className;
        if (_index isNotEqualTo -1) then { _array deleteAt _index };
    };
};

// Cleanup when applicable
if (_value isEqualTo false) then {
    private _cleanUp = true;
    { if (_y isNotEqualTo []) exitWith { _cleanup = false }; } forEach _map;
    if _cleanUp then { EGVAR(aiCigs,settings) = nil };
};
