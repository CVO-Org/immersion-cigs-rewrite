class CfgWeapons {

    class NVGoggles;

    class GVAR(cigBase_nv): NVGoggles {
        visionMode[] = {"Normal"};
        thermalMode[] = {0};
        modelOptics[] = {};
        opticsPPEffects[] = {};

        scope = 0;
        author = CSTRING(author);
        mass = 0.02;

        displayName = CSTRING(cigarette);
        descriptionShort = ECSTRING(core,hmd_stage0);

        model = "";
        picture = "";

        // Camo is cigarette body, CamoB is lit portion. Defined in p3d. These names are in OFP2_ManSkeleton, no model.cfg change is needed.
        hiddenSelections[] = { "Camo", "CamoB" };

        // Texture paths for the hiddenSelections are defined in an array in the same order as listed in hiddenSelections:
        hiddenSelectionsTextures[] = {  QPATH_TEXTURE, QPATH_TEXTURE };
        hiddenSelectionsMaterials[] = {  QPATH_BASE_RVMAT, QPATH_BASE_RVMAT_LIT };

        PVAR(maxTime) = MAXTIME;
        PVAR(initStateTime) = INITSTATETIME_VARIANT_0;
        PVAR(nextState) = QGVAR(cig1_nv);

        PVAR(isSmokable) = 1;
        PVAR(smokeMultiplier) = 1;
        PVAR(smokeSound)[] = {QPVAR(smoke_3),QPVAR(smoke_4)};

        class ItemInfo
        {
            type = 616;
            hmdType = 0;
            uniformModel = "";
            modelOff = "";
            mass = 0.02;

            hiddenSelections[]={"Camo","CamoB"};
            hiddenSelectionsTextures[] = {  QPATH_TEXTURE, QPATH_TEXTURE };
            hiddenSelectionsMaterials[] = {  QPATH_BASE_RVMAT, QPATH_BASE_RVMAT_LIT };
        };

        KJW_Imposters_SuspicionAmount = 0;
        hoa_sling_slingWithHelmet = 0;
    };
};
