// NVG's are defined within CfgWeapons
// The Facewear Version is defined in CfgGlasses

class CfgGlasses {
    class None;

    class GVAR(popBase): None {
        scope = 0;

        author = CSTRING(author);
        mass = 0.2;

        displayName = "";
        descriptionShort = "";

        model = "";
        picture = "";
        identityTypes[] = {};        

        PVAR(maxTime) = 0;
        PVAR(initStateTime) = 0;
        PVAR(nextState) = "";

        PVAR(isSuckable) = 1;

        PVAR(flavour)[] = {};
        PVAR(sounds)[] = {QPVAR(eat_01), QPVAR(eat_02), QPVAR(eat_03), QPVAR(eat_04), QPVAR(eat_05), QPVAR(eat_06), QPVAR(eat_07)};

        // Compat Data
        KJW_Imposters_SuspicionAmount = 0;
    };

    class GVAR(pop0): GVAR(popBase) {
        // Vanilla Data
        scope = 2;
        author = CSTRING(author);

        displayName = CSTRING(pop);
        descriptionShort = ECSTRING(core,glasses_stage0);

        model = QPATHTOF(data\pop\pop.p3d);
        picture = QPATHTOF(data\ui\gear_pop0_x_ca.paa);

        PVAR(maxTime) = MAXTIME;
        PVAR(initStateTime) = INITSTATETIME_VARIANT_0;

        PVAR(flavour)[] = {"banana", "cherry", "strawberry", "raspberry", "bacon", "nicotine", "tomato", "chocolate", "lemon", "cola"}; 
    };
};
