#include "defines.h"
#include "config.h"

/// Keldeo Forme Change ///

void check_if_slot_keldeo()
{
	var_800D_lastresult = 0;
	if (get_attributes(&party_player[var_8004], ATTR_SPECIES, 0) == KELDEO)
    	{
            var_800D_lastresult = 1;
    	}
}

void check_free_move()
{
	var_8005 = 0;
	if (var_800D_lastresult == 1)
	{
		for(u8 j=0; j<4; j++)
            	{
                	u16 moveset_move=get_attributes(&party_player[var_8004], ATTR_ATTACK_1+j, 0);
               		if(moveset_move == 0)
                	{
                    		var_8005 = 1;
                	}
		}
		
	}
}

void teach_secret_sword()
{
	struct pokemon* poke = &party_player[var_8004];
	u16 keldeo = KELDEO_RESOLUTE;
        teach_move_in_available_slot(poke, MOVE_SECRET_SWORD);
	set_attributes(poke, ATTR_SPECIES, &keldeo);
	calculate_stats_pokekmon(poke);
}
