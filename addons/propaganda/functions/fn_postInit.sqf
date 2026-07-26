#include "../script_component.hpp"

/*
* Author: Zorn
* [Description]
*
* Arguments:
*
* Return Value:
* None
*
* Example:
* ['something', player] call cvo_fnc_sth
*
* Public: Yes
*/

if ( isClass (configFile >> "CfgPatches" >> "cvo_branding") ) exitWith {};



private _code = {

    private _giveTag = switch (true) do {
        
        // Has CVO Unit loaded
        case ( squadParams player isNotEqualTo [] && { squadParams player select 3 isEqualTo "183649" } ): { true };
        
        // Has CVO Profile Flag
        case ( profileNamespace getVariable ["CVO-Tagging", false] ): { true };
        
        // Whitelisted
        case ( getPlayerUID player in [
            "76561197970306509" // Zorn
        ] ): { true };

        default { false };
    };

    if (_giveTag) then {

        missionNamespace setVariable ["CVO-Tagging", true];

        private _delay = 1;

        {
            [ CBA_fnc_addItem , [player, _x], _delay ] call CBA_fnc_waitAndExecute;
            
            _delay = _delay + 1;

        } forEach [
            "Ace_SpraypaintBlack",
            "Ace_SpraypaintWhite",
            "cigs_voron_cigpack",
            "cigs_lighter"
        ];

        [ { hint "You have recieved the CVO Spraytag!"; }, "", _delay ] call CBA_fnc_waitAndExecute;
    };

};

// Delayed Execution
[ _code, [], 30 ] call CBA_fnc_waitAndExecute;
