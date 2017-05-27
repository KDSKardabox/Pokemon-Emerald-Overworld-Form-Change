#include "defines.h"

void *shaymin_script();
void *hoopa_script();
void *therain_trio_script();
void *kyurem_script();


void run_script_from_item_shaymin(int taskID)
{
    script_env2_enable(taskID);
    script_run(shaymin_script);
    task_delete(taskID);
}

void run_script_from_item_hoopa(int taskID)
{
    script_env2_enable(taskID);
    script_run(hoopa_script);
    task_delete(taskID);
}

void run_script_from_item_genies(int taskID)
{
    script_env2_enable(taskID);
    script_run(therain_trio_script);
    task_delete(taskID);
}

void run_script_from_item_dna_splicers(int taskID)
{
    script_env2_enable(taskID);
    script_run(kyurem_script);
    task_delete(taskID);
}

void item_forme_change_handler_gracidea()
{
    routine_to_run_after_graphics = (void *) &run_script_from_item_shaymin;
    run_after_graphics();
}

void item_forme_change_handler_prison_bottle()
{
    routine_to_run_after_graphics = (void *) &run_script_from_item_hoopa;
    run_after_graphics();
}

void item_forme_change_handler_dna_splicers()
{
    routine_to_run_after_graphics = (void *) &run_script_from_item_dna_splicers;
    run_after_graphics();
}

void item_forme_change_handler_reveal_glas()
{
    routine_to_run_after_graphics = (void *) &run_script_from_item_genies;
    run_after_graphics();
}


// shaymin //

void shaymin_change_species()
{
    u8 i=var_8004;
    u16 target_species=SHAYMIN_FLY;
    struct pokemon* poke = &party_player[i];
    set_attributes(poke,ATTR_SPECIES,&target_species);
    calculate_stats_pokekmon(poke);
}

void check_shaymin()
{
    struct pokemon* poke = &party_player[var_8004];
    u16 species = get_attributes(poke,ATTR_SPECIES,0);
    if(species==SHAYMIN_LAND)
    {
        var_800D_lastresult=1;
    }
    else
    {
        var_800D_lastresult=0;
    }
}

// hoopa //

void check_hoopa()
{
    struct pokemon* poke = &party_player[var_8004];
	u16 species = get_attributes(poke,ATTR_SPECIES,0);
	if (species==HOOPA_CONFINED)
	{
		var_800D_lastresult=1;
	}
	else
	{
		var_800D_lastresult=0;
	}
}

void hoopa_change_species()
{
    u8 i=var_8004;
    u16 target_species=HOOPA_UNBOUND;
    struct pokemon* poke = &party_player[i];
    set_attributes(poke,ATTR_SPECIES,&target_species);
    calculate_stats_pokekmon(poke);
}


// Therain trio //

void check_therain_trio()
{
	struct pokemon* poke = &party_player[var_8004];
	u16 species = get_attributes(poke,ATTR_SPECIES,0);
	u16 target_species=0;

	switch (species)
	{
    case TORNADUS_INCARNATE:
		target_species = TORNADUS_THERIAN;
		break;

    case TORNADUS_THERIAN:
		target_species = TORNADUS_INCARNATE;
		break;

    case THUNDURUS_INCARNATE:
		target_species = THUNDURUS_THERIAN;
		break;

    case THUNDURUS_THERIAN:
		target_species = THUNDURUS_INCARNATE;
		break;

    case LANDORUS_INCARNATE:
		target_species = LANDORUS_THERIAN;
		break;

    case LANDORUS_THERIAN:
		target_species = LANDORUS_INCARNATE;
		break;
	}

	if(target_species)
    {
        set_attributes(poke,ATTR_SPECIES,&target_species);
        calculate_stats_pokekmon(poke);
        var_800D_lastresult=1;
    }
    else
    {
        var_800D_lastresult=0;
    }
}


// Kyurem //

u8 kyurem_slot_in_party()
{
    u8 i=6;
    for(i=0;i<6;i++)
    {
        if(POKE_KYUREM==get_attributes(&party_player[i],ATTR_SPECIES,0))
        {
            break;
        }
    }
    return i;
}

u8 pokemon_move_slot(struct pokemon* poke, u16 move)
{
    u8 move_slot=4;
    for(u8 i=0;i<4;i++)
    {
        u16 move_in_slot = get_attributes(poke,ATTR_ATTACK_1+i,0);
        if(move_in_slot==0)
        {
            break;
        }
        else if(move_in_slot==move)
        {
            move_slot=i;
            break;
        }
    }
    return move_slot;
}

void check_and_fuse_kyurem()
{
    if(SAVE_FUSEE)
    {
        var_800D_lastresult=0;
        struct pokemon* poke = &party_player[var_8004];
        u16 species = get_attributes(poke,ATTR_SPECIES,0);
        u16 target_species;
        u16 glaciate_replacement;
        void *fusee_data = (void *)SAVE_FUSEE;
        if(species==POKE_RESHIRAM || species==POKE_ZEKROM)
        {
            u8 kyurem_slot = kyurem_slot_in_party();
            if(*((u32 *)fusee_data)!=0)
            {
                var_800D_lastresult=3;
            }
            else if(kyurem_slot==6)
            {
                var_800D_lastresult=2;
            }
            else
            {
                if(species==POKE_RESHIRAM)
                {
                    target_species = POKE_KYUREM_WHITE;
                    glaciate_replacement = MOVE_ICE_BURN;
                }
                else
                {
                    target_species = POKE_KYUREM_BLACK;
                    glaciate_replacement = MOVE_FREEZE_SHOCK;
                }
                memcpy(fusee_data,(void *)poke,0x64);

                struct pokemon* kyurem = &party_player[kyurem_slot];
                set_attributes(kyurem,ATTR_SPECIES,&target_species);
                calculate_stats_pokekmon(kyurem);

                u8 slot_of_glaciate=pokemon_move_slot(kyurem, MOVE_GLACIATE);
                var_8004= kyurem_slot;
                if(slot_of_glaciate!=4)
                {
                    var_8005= slot_of_glaciate;
                    Special_E0_delete_move();

                    teach_move_in_available_slot(kyurem,glaciate_replacement);
                }
                pokemon_slot_purge(poke);
                party_move_up_no_free_slots_in_between();
                count_pokemon = count_pokemon-1;
                var_800D_lastresult=1;
            }
        }
        else if (species ==POKE_KYUREM_BLACK || species == POKE_KYUREM_WHITE)
        {
            if (count_pokemon <6)
            {
                target_species = POKE_KYUREM;
                set_attributes(poke, ATTR_SPECIES,&target_species);
                calculate_stats_pokekmon(poke);
                u8 slot_of_ice_burn=pokemon_move_slot(poke, MOVE_ICE_BURN);
                u8 slot_of_freeze_shock=pokemon_move_slot(poke, MOVE_FREEZE_SHOCK);
                if ((slot_of_ice_burn!=4) || (slot_of_freeze_shock!=4))
                {
                    if (slot_of_ice_burn!=4)
                    {
                        var_8005 = slot_of_ice_burn;
                    }
                    else
                    {
                        var_8005 = slot_of_freeze_shock;
                    }
                    Special_E0_delete_move();
                    teach_move_in_available_slot(poke, MOVE_GLACIATE);
                }
                memcpy(&party_player[count_pokemon],fusee_data,0x64);
                memset(fusee_data,0,0x64);
                count_pokemon= count_pokemon+1;
                var_800D_lastresult=4;
            }
	    else
	    {
            var_800D_lastresult=5;
	    }
        }
    }
}
