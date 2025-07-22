// NVG's are defined within CfgWeapons
// The Facewear Version is defined in CfgGlasses

class CfgGlasses {
    class EGVAR(base,cigBase);

    class GVAR(cigar0): EGVAR(base,cigBase) {
        scope = 2;
        author = CSTRING(author);

        displayName = CSTRING(cigar);
        descriptionShort = ECSTRING(core,glasses_stage0);

        model = QPATHTOF(data\cigars\cigar0.p3d);
        picture = QPATHTOF(data\ui\gear_cigar0_x_ca.paa); 

        hiddenSelections[]={ };
        hiddenSelectionsTextures[] = { };
        hiddenSelectionsMaterials[] = { };

        PVAR(maxTime) = MAXTIME;
        PVAR(initStateTime) = INITSTATETIME_VARIANT_0;
        PVAR(nextState) = QGVAR(cigar1);
    };

    class GVAR(cigar1): GVAR(cigar0) {
        scope = _DEBUG_SCOPE_;
        descriptionShort = ECSTRING(core,glasses_stage1);

        model = QPATHTOF(data\cigars\cigar1.p3d);
        picture = QPATHTOF(data\ui\gear_cigar1_x_ca.paa);

        PVAR(initStateTime) = INITSTATETIME_VARIANT_1;
        PVAR(nextState) = QGVAR(cigar2);
    };

    class GVAR(cigar2): GVAR(cigar1) {

        descriptionShort = ECSTRING(core,glasses_stage2);

        model = QPATHTOF(data\cigars\cigar2.p3d);
        picture = QPATHTOF(data\ui\gear_cigar2_x_ca.paa);

        PVAR(initStateTime) = INITSTATETIME_VARIANT_2;
        PVAR(nextState) = QGVAR(cigar3);
    };

    class GVAR(cigar3): GVAR(cigar1) {
        descriptionShort = ECSTRING(core,glasses_stage3);

        model = QPATHTOF(data\cigars\cigar3.p3d);
        picture = QPATHTOF(data\ui\gear_cigar3_x_ca.paa);

        PVAR(initStateTime) = INITSTATETIME_VARIANT_3;
        PVAR(nextState) = QGVAR(cigar4);
    };

    class GVAR(cigar4): GVAR(cigar1) {
        descriptionShort = ECSTRING(core,glasses_stage4);

        model = QPATHTOF(data\cigars\cigar4.p3d);
        picture = QPATHTOF(data\ui\gear_cigar4_x_ca.paa);

        PVAR(initStateTime) = INITSTATETIME_VARIANT_4;
        PVAR(nextState) = "";
    };
};
