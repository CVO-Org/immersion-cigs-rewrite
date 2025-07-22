class CfgMagazines {
    class CA_Magazine;

    class PVAR(matches): CA_Magazine {
        author = CSTRING(author);
        scope = 2;

        displayName = CSTRING(matches);
        descriptionShort = CSTRING(matches_desc);
        model = QPATHTOF(data\matches\matches.p3d);
        picture = QPATHTOF(data\ui\gear_matches_x_ca.paa);

        ammo = "";
        count = 10;
        initSpeed = 0;
        tracersEvery = 0;
        lastRoundsTracer = 0;
        mass = 1;

        ACE_asItem = 1;

        PVAR(isLighter) = 1;
        PVAR(LighterSound)[] = {QPVAR(matches_01),QPVAR(matches_02)};     // CfgSounds Class
    };

    class PVAR(lighter): PVAR(matches) {

        displayName = CSTRING(lighter);
        descriptionShort = CSTRING(lighter_desc);
        model = QPATHTOF(data\lighter\lighter.p3d);
        picture = QPATHTOF(data\ui\gear_lighter_x_ca.paa);

        count = 100;
        initSpeed = 0;
        mass = 2;

        ACE_asItem = 1;

        PVAR(isLighter) = 1;
        PVAR(LighterSound)[] = {QPVAR(lighter_01),QPVAR(lighter_02)};     // CfgSounds Class
    };
};
