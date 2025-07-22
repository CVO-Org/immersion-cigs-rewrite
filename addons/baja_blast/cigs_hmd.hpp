class CfgWeapons {

    class EGVAR(base,cigBase_nv);

    class GVAR(cig0_nv): EGVAR(base,cigBase_nv) {

        scope = 2;
        author = CSTRING(author);

        displayName = CSTRING(cigarette);
        descriptionShort = ECSTRING(core,hmd_stage0);

        model = QPATH_BASE_MODEL_CIG0;
        picture = QPATHTOF(data\ui\gear_cig0_x_ca.paa);

        // Texture paths for the hiddenSelections are defined in an array in the same order as listed in hiddenSelections:
        hiddenSelectionsTextures[] = {  QPATH_TEXTURE, QPATH_TEXTURE };
        hiddenSelectionsMaterials[] = {  QPATH_BASE_RVMAT, QPATH_BASE_RVMAT_LIT };

        PVAR(maxTime) = MAXTIME;
        PVAR(initStateTime) = INITSTATETIME_VARIANT_0;
        PVAR(nextState) = QGVAR(cig1_nv);

        class ItemInfo {
            type = 616;
            hmdType = 0;
            uniformModel = QPATH_BASE_MODEL_CIG0;
            modelOff = QPATH_BASE_MODEL_CIG0;
            mass = 0.02;

            hiddenSelections[]={"Camo","CamoB"};
            hiddenSelectionsTextures[] = {  QPATH_TEXTURE, QPATH_TEXTURE };
            hiddenSelectionsMaterials[] = {  QPATH_BASE_RVMAT, QPATH_BASE_RVMAT_LIT };
        };
    };

    class GVAR(cig1_nv): GVAR(cig0_nv) {
        scope = _DEBUG_SCOPE_;

        descriptionShort = ECSTRING(core,hmd_stage1);

        model = QPATH_BASE_MODEL_CIG1;
        picture = QPATHTOF(data\ui\gear_cig1_x_ca.paa);

        PVAR(initStateTime) = INITSTATETIME_VARIANT_1;
        PVAR(nextState) = QGVAR(cig2_nv);

        class ItemInfo: ItemInfo {
            uniformModel = QPATH_BASE_MODEL_CIG1;
            modelOff = QPATH_BASE_MODEL_CIG1;
        };
    };

    class GVAR(cig2_nv): GVAR(cig1_nv) {

        descriptionShort = ECSTRING(core,hmd_stage2);

        model = QPATH_BASE_MODEL_CIG1;
        picture = QPATHTOF(data\ui\gear_cig1_x_ca.paa);

        PVAR(initStateTime) = INITSTATETIME_VARIANT_2;
        PVAR(nextState) = QGVAR(cig3_nv);

        class ItemInfo: ItemInfo {
            uniformModel = QPATH_BASE_MODEL_CIG2;
            modelOff = QPATH_BASE_MODEL_CIG2;
        };
    };

    class GVAR(cig3_nv): GVAR(cig1_nv) {
        scope = _DEBUG_SCOPE_;

        descriptionShort = ECSTRING(core,hmd_stage3);

        model = QPATH_BASE_MODEL_CIG1;
        picture = QPATHTOF(data\ui\gear_cig3_x_ca.paa);

        PVAR(initStateTime) = INITSTATETIME_VARIANT_3;
        PVAR(nextState) = QGVAR(cig4_nv);

        class ItemInfo: ItemInfo {
            uniformModel = QPATH_BASE_MODEL_CIG3;
            modelOff = QPATH_BASE_MODEL_CIG3;
        };
    };

    class GVAR(cig4_nv): GVAR(cig1_nv) {
        scope = _DEBUG_SCOPE_;

        descriptionShort = ECSTRING(core,hmd_stage4);

        model = QPATH_BASE_MODEL_CIG1;
        picture = QPATHTOF(data\ui\gear_cig4_x_ca.paa);

        PVAR(initStateTime) = INITSTATETIME_VARIANT_4;
        PVAR(nextState) = "";

        class ItemInfo: ItemInfo {
            uniformModel = QPATH_BASE_MODEL_CIG4;
            modelOff = QPATH_BASE_MODEL_CIG4;
        };
    };
};
