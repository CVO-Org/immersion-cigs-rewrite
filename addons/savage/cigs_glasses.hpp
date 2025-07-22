// NVG's are defined within CfgWeapons
// The Facewear Version is defined in CfgGlasses

class CfgGlasses {
    class EGVAR(base,cigBase);

    class GVAR(cig0): EGVAR(base,cigBase) {
        scope = 2;
        author = CSTRING(author);

        displayName = CSTRING(cigarette);
        descriptionShort = ECSTRING(core,glasses_stage0);

        model = QPATH_BASE_MODEL_CIG0;  // From Base
        picture = QPATHTOF(data\ui\gear_cig0_x_ca.paa); // From Addon

        hiddenSelectionsTextures[] =  { QPATH_TEXTURE, QPATH_TEXTURE }; // From Addon

        PVAR(maxTime) = MAXTIME;
        PVAR(initStateTime) = INITSTATETIME_VARIANT_0;
        PVAR(nextState) = QGVAR(cig1);
    };

    class GVAR(cig1): GVAR(cig0) {
        scope = _DEBUG_SCOPE_;
        descriptionShort = ECSTRING(core,glasses_stage1);

        model = QPATH_BASE_MODEL_CIG1;
        picture = QPATHTOF(data\ui\gear_cig1_x_ca.paa);

        PVAR(initStateTime) = INITSTATETIME_VARIANT_1;
        PVAR(nextState) = QGVAR(cig2);
    };

    class GVAR(cig2): GVAR(cig1) {

        descriptionShort = ECSTRING(core,glasses_stage2);

        model = QPATH_BASE_MODEL_CIG2;
        picture = QPATHTOF(data\ui\gear_cig2_x_ca.paa);

        PVAR(initStateTime) = INITSTATETIME_VARIANT_2;
        PVAR(nextState) = QGVAR(cig3);
    };

    class GVAR(cig3): GVAR(cig1) {
        descriptionShort = ECSTRING(core,glasses_stage3);

        model = QPATH_BASE_MODEL_CIG3;
        picture = QPATHTOF(data\ui\gear_cig3_x_ca.paa);

        PVAR(initStateTime) = INITSTATETIME_VARIANT_3;
        PVAR(nextState) = QGVAR(cig4);
    };

    class GVAR(cig4): GVAR(cig1) {
        descriptionShort = ECSTRING(core,glasses_stage4);

        model = QPATH_BASE_MODEL_CIG4;
        picture = QPATHTOF(data\ui\gear_cig4_x_ca.paa);

        PVAR(initStateTime) = INITSTATETIME_VARIANT_4;
        PVAR(nextState) = "";
    };
};
