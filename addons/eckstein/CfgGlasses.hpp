// NVG's are defined within CfgWeapons
// The Facewear Version is defined in CfgGlasses

class CfgGlasses {
    class None;

    class GVAR(cig0): None {
        scope = 2;
        author = CSTRING(author);
        mass = 0.02;
        displayName = CSTRING(cigarette);
        descriptionShort = ECSTRING(core,glasses_stage0);

        model = QPATHTOF(data\cigs\cig0.p3d);
        picture = QPATHTOF(data\ui\gear_cig0_x_ca.paa);
        identityTypes[] = {};

        PVAR(maxTime) = MAXTIME;
        PVAR(initStateTime) = INITSTATETIME_VARIANT_0;
        PVAR(nextState) = QGVAR(cig1);

        PVAR(isSmokable) = 1;
        PVAR(smokeMultiplier) = 1;

        KJW_Imposters_SuspicionAmount = 0;
    };

    class GVAR(cig1): GVAR(cig0) {
        scope = _DEBUG_SCOPE_;
        author = CSTRING(author);
        displayName = CSTRING(cigarette);
        descriptionShort = ECSTRING(core,glasses_stage1);

        model = QPATHTOF(data\cigs\cig1.p3d);
        picture = QPATHTOF(data\ui\gear_cig1_x_ca.paa);

        PVAR(initStateTime) = INITSTATETIME_VARIANT_1;
        PVAR(nextState) = QGVAR(cig2);
        PVAR(isSmokable) = 1;
    };

    class GVAR(cig2): GVAR(cig0) {
        scope = _DEBUG_SCOPE_;
        author = CSTRING(author);
        displayName = CSTRING(cigarette);
        descriptionShort = ECSTRING(core,glasses_stage2);

        model = QPATHTOF(data\cigs\cig2.p3d);
        picture = QPATHTOF(data\ui\gear_cig2_x_ca.paa);

        PVAR(initStateTime) = INITSTATETIME_VARIANT_2;
        PVAR(nextState) = QGVAR(cig3);
        PVAR(isSmokable) = 1;
    };

    class GVAR(cig3): GVAR(cig0) {
        scope = _DEBUG_SCOPE_;
        author = CSTRING(author);
        displayName = CSTRING(cigarette);
        descriptionShort = ECSTRING(core,glasses_stage3);

        model = QPATHTOF(data\cigs\cig3.p3d);
        picture = QPATHTOF(data\ui\gear_cig3_x_ca.paa);

        PVAR(initStateTime) = INITSTATETIME_VARIANT_3;
        PVAR(nextState) = QGVAR(cig4);
        PVAR(isSmokable) = 1;
    };

    class GVAR(cig4): GVAR(cig0) {
        scope = _DEBUG_SCOPE_;
        author = CSTRING(author);
        displayName = CSTRING(cigarette);
        descriptionShort = ECSTRING(core,glasses_stage4);

        model = QPATHTOF(data\cigs\cig4.p3d);
        picture = QPATHTOF(data\ui\gear_cig4_x_ca.paa);

        PVAR(initStateTime) = INITSTATETIME_VARIANT_4;
        PVAR(nextState) = "";
        PVAR(isSmokable) = 1;
    };
};
