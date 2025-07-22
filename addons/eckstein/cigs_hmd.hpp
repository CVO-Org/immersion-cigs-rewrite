class CfgWeapons {

    class EGVAR(base,cigBase_nv);

    class GVAR(cig0_nv): EGVAR(base,cigBase_nv) {

        scope = 2;
        author = CSTRING(author);

        displayName = CSTRING(cigarette);
        descriptionShort = ECSTRING(core,hmd_stage0);

        model = QPATHTOF(data\cigs\cig0.p3d);
        picture = QPATHTOF(data\ui\gear_cig0_x_ca.paa);

        // Texture paths for the hiddenSelections are defined in an array in the same order as listed in hiddenSelections:
        hiddenSelections[]={ };
        hiddenSelectionsTextures[] = { };
        hiddenSelectionsMaterials[] = { };

        PVAR(maxTime) = MAXTIME;
        PVAR(initStateTime) = INITSTATETIME_VARIANT_0;
        PVAR(nextState) = QGVAR(cig1_nv);

        class ItemInfo {
            type = 616;
            hmdType = 0;
            uniformModel = QPATHTOF(data\cigs\cig0.p3d);
            modelOff = QPATHTOF(data\cigs\cig0.p3d);
            mass = 0.02;

            hiddenSelections[]={ };
            hiddenSelectionsTextures[] = { };
            hiddenSelectionsMaterials[] = { };
        };
    };

    class GVAR(cig1_nv): GVAR(cig0_nv) {
        scope = _DEBUG_SCOPE_;

        descriptionShort = ECSTRING(core,hmd_stage1);

        model = QPATHTOF(data\cigs\cig1.p3d);
        picture = QPATHTOF(data\ui\gear_cig1_x_ca.paa);

        PVAR(initStateTime) = INITSTATETIME_VARIANT_1;
        PVAR(nextState) = QGVAR(cig2_nv);

        class ItemInfo: ItemInfo {
            uniformModel = QPATHTOF(data\cigs\cig1.p3d);
            modelOff = QPATHTOF(data\cigs\cig1.p3d);
        };
    };

    class GVAR(cig2_nv): GVAR(cig1_nv) {

        descriptionShort = ECSTRING(core,hmd_stage2);

        model = QPATHTOF(data\cigs\cig2.p3d);
        picture = QPATHTOF(data\ui\gear_cig2_x_ca.paa);

        PVAR(initStateTime) = INITSTATETIME_VARIANT_2;
        PVAR(nextState) = QGVAR(cig3_nv);

        class ItemInfo: ItemInfo {
            uniformModel = QPATHTOF(data\cigs\cig2.p3d);
            modelOff = QPATHTOF(data\cigs\cig2.p3d);
        };
    };

    class GVAR(cig3_nv): GVAR(cig1_nv) {
        scope = _DEBUG_SCOPE_;

        descriptionShort = ECSTRING(core,hmd_stage3);

        model = QPATHTOF(data\cigs\cig3.p3d);
        picture = QPATHTOF(data\ui\gear_cig3_x_ca.paa);

        PVAR(initStateTime) = INITSTATETIME_VARIANT_3;
        PVAR(nextState) = QGVAR(cig4_nv);

        class ItemInfo: ItemInfo {
            uniformModel = QPATHTOF(data\cigs\cig3.p3d);
            modelOff = QPATHTOF(data\cigs\cig3.p3d);
        };
    };

    class GVAR(cig4_nv): GVAR(cig1_nv) {
        scope = _DEBUG_SCOPE_;

        descriptionShort = ECSTRING(core,hmd_stage4);

        model = QPATHTOF(data\cigs\cig4.p3d);
        picture = QPATHTOF(data\ui\gear_cig4_x_ca.paa);

        PVAR(initStateTime) = INITSTATETIME_VARIANT_4;
        PVAR(nextState) = "";

        class ItemInfo: ItemInfo {
            uniformModel = QPATHTOF(data\cigs\cig4.p3d);
            modelOff = QPATHTOF(data\cigs\cig4.p3d);
        };
    };
};
