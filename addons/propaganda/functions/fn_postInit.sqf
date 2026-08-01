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

        [
            {
                [ ["<img image='%1' size=5></img><br/>%2", QPATHTOF(data\cvo_stencil_white_ca.paa), "You recieved the Care-Package!"], 4 ] call ace_common_fnc_displayTextStructured;
                [player, "cvo_raven_caw", 25, false, false, 0.15] call CBA_fnc_globalSay3D;
            },
            nil,
            _delay
        ] call CBA_fnc_waitAndExecute;
    };
};

// Delayed Execution
[ _code, [], 15 + random 3 ] call CBA_fnc_waitAndExecute;
