#include "../../script_component.hpp"

/*
* Author: Zorn
* Function to Take a Cigarette from a box
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

params [
    "_player",
    ["_class_cigpack", QEGVAR(morley,cigpack), [""]]
];

[_player, _class_cigpack] call FUNC(removeItemFromMag);

private _sound = [ configFile >> "CfgMagazines" >> _class_cigpack >> QPVAR(unpackSound) ] call CBA_fnc_getCfgDataRandom;
if (_sound != "") then { [_unit, _sound, nil, true, true, true] call CBA_fnc_globalSay3D; };

private _item_glasses = [(configFile >> "CfgMagazines" >> _class_cigpack >> QPVAR(item_glasses))] call CBA_fnc_getCfgDataRandom;
private _item_hmd =     [(configFile >> "CfgMagazines" >> _class_cigpack >> QPVAR(item_hmd)    )] call CBA_fnc_getCfgDataRandom;

switch (true) do {
    case (goggles _player == ""): { _player addGoggles _item_glasses };
    case (    hmd _player == ""): { _player addItem _item_hmd; _player assignItem _item_hmd; };
    default { _player addItem _item_glasses; };
};

