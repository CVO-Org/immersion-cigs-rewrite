class CfgGlasses {

    class None;
    class GVAR(cigBase): None {
        scope = 0;
        author = CSTRING(author);
        mass = 0.02;
        displayName = CSTRING(cigarette);
        descriptionShort = ECSTRING(core,glasses_stage0);

        model = "";
        picture = "";
        identityTypes[] = {};

        // Camo is cigarette body, CamoB is lit portion. Defined in p3d. These names are in OFP2_ManSkeleton, no model.cfg change is needed.
        hiddenSelections[] = { "Camo", "CamoB" };

        // Texture paths for the hiddenSelections are defined in an array in the same order as listed in hiddenSelections:
        hiddenSelectionsTextures[] =  { QPATH_TEXTURE, QPATH_TEXTURE };
        hiddenSelectionsMaterials[] = { QPATH_BASE_RVMAT, QPATH_BASE_RVMAT_LIT };

        PVAR(maxTime) = 0;
        PVAR(initStateTime) = 0;
        PVAR(nextState) = "";

        PVAR(isSmokable) = 1;
        PVAR(smokeMultiplier) = 1;

        PVAR(smokeSound)[] = {QPVAR(smoke_3),QPVAR(smoke_4)};

        KJW_Imposters_SuspicionAmount = 0;
    };
};
