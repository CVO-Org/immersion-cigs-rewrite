#include "../../script_component.hpp"

/*
* Author: Zorn
* Recursive Function - will handle the 
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

params ["_unit","_currentTime","_itemType","_maxTime"];

////////////////////////////////////////
// Update Current variables
////////////////////////////////////////
private ["_currentItem", "_itemConfig"];

switch (_itemType) do {
    case ("GOGGLES"): {
        _currentItem = goggles _unit;
        _itemConfig = configFile >> "CfgGlasses" >> _currentItem;
    };
    case ("HMD"): {
        _currentItem = hmd _unit;
        _itemConfig = configFile >> "CfgWeapons" >> _currentItem;
    };
};


////////////////////////////////////////
// Sound Effects
////////////////////////////////////////
private _sound = [(_itemConfig >> PVAR(sounds))] call CBA_fnc_getCfgDataRandom;
[_unit, _sound, nil, true, true, true] call CBA_fnc_globalSay3D;


////////////////////////////////////////
// Get NextCigState
////////////////////////////////////////
private _newItem = "";
private _nextItemState = getText (_itemConfig >> QPVAR(nextState));


private _nextItemStateTime = 0;

//If newItemState is defined, get nextItemStateTime - otherwise, use _maxTime.
if (_nextItemState != "") then {
    switch (_itemType) do {
        case ("GOGGLES"): { _nextItemStateTime = getNumber (configFile >> "CfgGlasses" >> _nextItemState >> QPVAR(initStateTime));  };
        case ("HMD"):     { _nextItemStateTime = getNumber (configFile >> "CfgWeapons" >> _nextItemState >> QPVAR(initStateTime));  };
    };
} else {
    _nextItemStateTime = _maxTime;
};

// If Current Time exeeds the nextItemState, define new Item
if (_currentTime >= _nextItemStateTime) then { _newItem = _nextItemState; };

// If new Item is defined, replace the current one with the new one
if (_newItem != "") then {
    switch (_itemType) do {
        case ("GOGGLES"): {
            removeGoggles _unit;
            _unit addGoggles _newItem;
            _itemConfig = configFile >> "CfgGlasses" >> _newItem;
        };
        case ("HMD"): {
            _unit removeWeapon _currentItem;
            _unit addWeapon  _newItem;
            _itemConfig = configFile >> "CfgWeapons" >> _newItem;
        };
    };

    _currentItem = _newItem;
};

////////////////////////////////////////
// API 
////////////////////////////////////////
[QGVAR(EH_sucking_local),  [_unit, _currentTime, _currentItem, _itemType]] call CBA_fnc_localEvent;
[QGVAR(EH_sucking_server), [_unit, _currentTime, _currentItem, _itemType]] call CBA_fnc_serverEvent;


////////////////////////////////////////
// Define Delay and Timers
////////////////////////////////////////
private _delay = (20 + random 10);
_currentTime = _currentTime + _delay;


_code = {

    params ["_unit","_currentTime","_currentItem","_itemType","_maxTime"];


    if ( [_unit, _itemType, _currentItem, _currentTime, _maxTime] call FUNC(canKeepSucking) ) then {
        [_unit,_currentTime,_itemType,_maxTime] call FUNC(sucking);
    } else {
        // IF fail condition detected
        [_unit, QEGVAR(anim,cig_out), 1] call FUNC(anim);
        _unit setVariable [QPVAR(isSucking), false, true];

        // Only remove the current suckable when its "fully consumed"
        if (_currentTime >= _maxTime) then {
            switch (_itemType) do {
                case ("GOGGLES"): { removeGoggles _unit; };
                case ("HMD"):     { _unit removeWeapon (hmd _unit); };
            };
        };
    };
};

[_code, [_unit,_currentTime,_currentItem,_itemType,_maxTime], _delay] call CBA_fnc_waitAndExecute;

