class Man;
class CAManBase: Man
{
    class ACE_Actions
    {
        class ACE_Head
        {
            class PVAR(start_cig_their)
            {
                displayName = CSTRING(start_cig_their);
                condition = Q([_player] call FUNC(hasLighter) && [_target] call FUNC(canStartSmoking));
                statement = Q(call FUNC(start_cig_their));
                showDisabled = 0;
                exceptions[] = {"isNotInside", "isNotSitting"};
                icon = QPATHTOF(data\ui\light_cig.paa);
            };        
        };
    };

    class ACE_SelfActions
    {
        class ACE_Equipment {
            // Take from Pack
            class PVAR(take_from_pack)
            {
                displayName = CSTRING(take_from_pack);
                condition = Q([_player] call FUNC(canTakeFromPack));
                statement = "";
                insertChildren = Q([_player] call FUNC(action_pack_children));
                showDisabled = 0;
                exceptions[] = {"isNotInside", "isNotSitting"};
                icon = QPATHTOF(data\ui\take_cig.paa);
            };

            // Smokable Actions
            class PVAR(start_cig_own)
            {
                displayName = CSTRING(start_cig_own);
                condition = Q([_player] call FUNC(canStartSmoking));
                statement = Q([_player] call FUNC(start_cig_your));
                showDisabled = 0;
                exceptions[] = {"isNotInside", "isNotSitting"};
                icon = QPATHTOF(data\ui\light_cig.paa);
            };
            class PVAR(stop_cig)
            {
                displayName = CSTRING(stop_cig);
                condition = Q([_player] call FUNC(canStopSmoking));
                statement = Q([_player] call FUNC(stop_cig));
                showDisabled = 0;
                exceptions[] = {"isNotInside", "isNotSitting"};
                icon = QPATHTOF(data\ui\light_cig.paa);
            };

            // Suckable Actions
            class PVAR(start_suck)
            {
                displayName = CSTRING(start_sucking);
                condition = Q([_player] call FUNC(canStartSucking));
                statement = Q([_player] call FUNC(start_suck_self));
                showDisabled = 0;
                exceptions[] = {"isNotInside", "isNotSitting"};
                icon = QPATHTOF(data\ui\pop_consume.paa);
            };
            class PVAR(stop_suck)
            {
                displayName = CSTRING(stop_sucking);
                condition = Q([_player] call FUNC(canStopSucking));
                statement = Q([_player] call FUNC(stop_sucking));
                showDisabled = 0;
                exceptions[] = {"isNotInside", "isNotSitting"};
                icon = QPATHTOF(data\ui\pop_consume.paa);
            };
        };
    };
};
