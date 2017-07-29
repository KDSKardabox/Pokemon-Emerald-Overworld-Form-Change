#ifndef CONFIG_H
#define CONFIG_H

#include "types.h"

#define ALL_POKES       412     //number of all pokemon
#define ALL_ITEMS       377     //number of all items
#define NUM_OF_EVOS     5       //number of evolutions per pokemon
#define SAVE_FUSEE 0x0          //offset to for saving the fused reshiram

//////////////////////////////////////////////////////////////////////////////
////                       GIRATINA CONFIG                                ////
//////////////////////////////////////////////////////////////////////////////
#define POKE_GIRATINA 3000
#define POKE_GIRATINA_O 3001


//////////////////////////////////////////////////////////////////////////////
////                       SHAYMIN CONFIG                                 ////
//////////////////////////////////////////////////////////////////////////////

#define SHAYMIN_FLY 3002
#define SHAYMIN_LAND 3003


//////////////////////////////////////////////////////////////////////////////
////                       KELDEO CONFIG                                 ////
//////////////////////////////////////////////////////////////////////////////

#define KELDEO 3130
#define KELDEO_RESOLUTE 3130


//////////////////////////////////////////////////////////////////////////////
////                       HOOPA CONFIG                                   ////
//////////////////////////////////////////////////////////////////////////////

#define HOOPA_UNBOUND 3004
#define HOOPA_CONFINED 3005


//////////////////////////////////////////////////////////////////////////////
////                       FORCES OF NATURE CONFIG                        ////
//////////////////////////////////////////////////////////////////////////////

#define TORNADUS_INCARNATE 3006
#define TORNADUS_THERIAN 3007
#define THUNDURUS_INCARNATE 3008
#define THUNDURUS_THERIAN 3009
#define LANDORUS_INCARNATE 3010
#define LANDORUS_THERIAN 3011


//////////////////////////////////////////////////////////////////////////////
////                       KYUREM CONFIG                                  ////
//////////////////////////////////////////////////////////////////////////////

#define POKE_RESHIRAM 3012
#define POKE_ZEKROM 3013
#define POKE_KYUREM 3014
#define POKE_KYUREM_BLACK 3015
#define POKE_KYUREM_WHITE 3016


//////////////////////////////////////////////////////////////////////////////
////                       ARCEUS CONFIG                                  ////
//////////////////////////////////////////////////////////////////////////////

#define POKE_ARCEUS 3017
enum arceus_formes_idx {
    POKE_ARCEUS_FIGHTING = 3018,  // This a enum. The subsequent value of indexes will be 1302, 1303 etc.
    POKE_ARCEUS_FLYING,
    POKE_ARCEUS_POISON,
    POKE_ARCEUS_GROUND,
    POKE_ARCEUS_ROCK,
    POKE_ARCEUS_BUG,
    POKE_ARCEUS_GHOST,
    POKE_ARCEUS_STEEL,
    POKE_ARCEUS_FIRE,
    POKE_ARCEUS_WATER,
    POKE_ARCEUS_GRASS,
    POKE_ARCEUS_ELECTRIC,
    POKE_ARCEUS_PSYCHIC,
    POKE_ARCEUS_ICE,
    POKE_ARCEUS_DRAGON,
    POKE_ARCEUS_DARK,
    POKE_ARCEUS_FAIRY,
};

//////////////////////////////////////////////////////////////////////////////
////                       SILVALLY CONFIG                                ////
//////////////////////////////////////////////////////////////////////////////
#define ABILITY_RKS_SYSTEM 240
#define POKE_SILVALLY 3040
enum silvally_forms_idx {
    POKE_SILVALLY_FIGHTING = 3041,
    POKE_SILVALLY_FLYING,
    POKE_SILVALLY_POISON,
    POKE_SILVALLY_GROUND,
    POKE_SILVALLY_ROCK,
    POKE_SILVALLY_BUG,
    POKE_SILVALLY_GHOST,
    POKE_SILVALLY_STEEL,
    POKE_SILVALLY_FIRE,
    POKE_SILVALLY_WATER,
    POKE_SILVALLY_GRASS,
    POKE_SILVALLY_ELECTRIC,
    POKE_SILVALLY_PSYCHIC,
    POKE_SILVALLY_ICE,
    POKE_SILVALLY_DRAGON,
    POKE_SILVALLY_DARK,
    POKE_SILVALLY_FAIRY,
};

//////////////////////////////////////////////////////////////////////////////
////                       GENESECT CONFIG                                ////
//////////////////////////////////////////////////////////////////////////////
#define POKE_GENESECT 3100
enum genesect_formes{
    POKE_GENESECT_DOUSE = 3101,
    POKE_GENESECT_BURN,
    POKE_GENESECT_CHILL,
    POKE_GENESECT_SHOCK
};

enum drives
{
    DOUSE_DRIVE_EFFECT=1,
    BURN_DRIVE_EFFECT,
    CHILL_DRIVE_EFFECT,
    SHOCK_DRIVE_EFFECT
};


//////////////////////////////////////////////////////////////////////////////
////                        ROTOM CONFIG                                  ////
//////////////////////////////////////////////////////////////////////////////
#define POKE_ROTOM 3110

enum rotom_forms
{
    POKE_ROTOM_HEAT=3111,
    POKE_ROTOM_WASH,
    POKE_ROTOM_FROST,
    POKE_ROTOM_FAN,
    POKE_ROTOM_MOW
};

//////////////////////////////////////////////////////////////////////////////
////                        DEOXYS CONFIG                                 ////
//////////////////////////////////////////////////////////////////////////////
enum deoxys_forms
{
    POKE_DEOXYS_ATTACK=3120,
    POKE_DEOXYS_DEFENSE,
    POKE_DEOXYS_SPEED,
};

#endif /* CONFIG_H */
