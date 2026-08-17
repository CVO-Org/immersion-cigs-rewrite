#include "../../script_component.hpp"

/*
* Author: Zorn
* This function will add a CBA Setting for the defined Side 
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

params [ "_cfg", "_side"];

private _className = configName _cfg;
private _displayName = getText (_cfg >> "displayName");

[
    [Q(ADDON), "set", "aiCigs", "custom", "#", _side, _className] joinString "_",
    "CHECKBOX",
    [_displayName, format ["%1 will be distributed randomly across %2", _displayName, str _side]],
    [LSTRING(set_mainCat_ai), format ["%1 - %2", LLSTRING(set_subCat_cigsonai_sides), _side]],            //    _category    - Category for the settings menu + optional sub-category <STRING, ARRAY>
    false,
    1,
    {},
    false
] call CBA_fnc_addSetting;
