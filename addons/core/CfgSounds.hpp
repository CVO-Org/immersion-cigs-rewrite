#define SOUND(name,volume,pitch,distance)\
class PVAR(name) {\
    sound[] = {QPATHTOF(data\sounds\name##.ogg), volume, pitch, distance};\
    titles[] = {};\
}

class CfgSounds {
    sounds[] = {};

    SOUND(unwrap_01,4,1,30);

    SOUND(matches_01,4,1,30);
    SOUND(matches_02,4,1,30);

    SOUND(lighter_01,4,1,30);
    SOUND(lighter_02,4,1,30);

    SOUND(eat_01,4,1,30);
    SOUND(eat_02,4,1,30);
    SOUND(eat_03,4,1,30);
    SOUND(eat_04,4,1,30);
    SOUND(eat_05,4,1,30);
    SOUND(eat_06,4,1,30);
    SOUND(eat_07,4,1,30);

    SOUND(eat_bread_1,4,1,30);
    SOUND(eat_bread_2,4,1,30);
    SOUND(eat_bread_3,4,1,30);
    SOUND(eat_bread_4,4,1,30);
    SOUND(eat_bread_5,4,1,30);

    SOUND(smoke_3,3,1,10);
    SOUND(smoke_4,3,1,10);

    SOUND(verpuffung_00,4,1,100);
    SOUND(verpuffung_01,4,1,100);
    SOUND(verpuffung_02,4,1,100);
    SOUND(verpuffung_03,4,1,100);
    SOUND(verpuffung_04,4,1,100);

    // DayZ Mod LDP (ADPL-SA) // TODO
    SOUND(cough_0,4,1,75);
    SOUND(cough_1,4,1,75);
    SOUND(cough_2,4,1,75);
};
