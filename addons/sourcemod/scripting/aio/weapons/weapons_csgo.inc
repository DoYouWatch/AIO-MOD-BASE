/*        <AIO MOD> (c) by <De Battista Clint - (http://doyou.watch)         */
/*                                                                           */
/*                       <AIO MOD> is licensed under a                       */
/* Creative Commons Attribution-NonCommercial-NoDerivs 4.0 Unported License. */
/*																			 */
/*      You should have received a copy of the license along with this       */
/*  work.  If not, see <http://creativecommons.org/licenses/by-nc-nd/4.0/>.  */
//***************************************************************************//
//***************************************************************************//
//****************************AIO MOD WEAPONS CSGO***************************//
//***************************************************************************//
//***************************************************************************//

//***********************************//
//*************DEFINES***************//
//***********************************//

#define WEAPON_PISTOLS_CSGO		8
#define WEAPON_HEAVY_CSGO		6
#define WEAPON_SMGS_CSGO		7
#define WEAPON_RIFLES_CSGO		11
#define WEAPON_KNIFE_CSGO		10
#define WEAPON_GRENADE_CSGO		5
#define WEAPON_C4_CSGO			1
#define WEAPON_DEFUSE_CSGO		1
#define WEAPON_ARMOR_CSGO		2

//***********************************//
//********LIST WEAPONS CSGO**********//
//***********************************//
#if defined START_WEAPONS_CSGO_LOADED
	//Weapons Pistols
	new String:S_weapons_pistols_csgo[WEAPON_PISTOLS_CSGO][]		= {
																		"weapon_usp_silencer",
																		"weapon_glock",
																		"weapon_p250",
																		"weapon_fiveseven",
																		"weapon_deagle",
																		"weapon_elite",
																		"weapon_hkp2000",
																		"weapon_tek9"
																	};

	//Weapons Heavy
	new String:S_weapons_heavy_csgo[WEAPON_HEAVY_CSGO][]			= {
																		"weapon_nova",
																		"weapon_xm1014",
																		"weapon_mag7",
																		"weapon_sawedoff",
																		"weapon_m249",
																		"weapon_negev"
																	};

	//Weapons SMGs
	new String:S_weapons_smgs_csgo[WEAPON_SMGS_CSGO][]				= {
																		"weapon_mp9",
																		"weapon_mac10",
																		"weapon_mag7",
																		"weapon_mp7",
																		"weapon_ump45",
																		"weapon_p90",
																		"weapon_bizon"
																	};															
	//Weapons Rifles
	new String:S_weapons_rifles_csgo[WEAPON_RIFLES_CSGO][]			= {
																		"weapon_famas",
																		"weapon_m4a1",
																		"weapon_m4a1_silencer",
																		"weapon_galilar",
																		"weapon_ak47",
																		"weapon_ssg08",
																		"weapon_aug",
																		"weapon_sg556",
																		"weapon_awp",
																		"weapon_scar20",
																		"weapon_g3sg1"
																	};
	//Weapons Knife
	new String:S_weapons_knife_csgo[WEAPON_KNIFE_CSGO][]			= {
																		"weapon_taser",
																		"weapon_knife",
																		"weapon_bayonet",
																		"weapon_knife_gut",
																		"weapon_knife_flip",
																		"weapon_knife_m9_bayonet",
																		"weapon_knife_karambit",
																		"weapon_knife_tactical",
																		"weapon_knife_butterfly",
																		"weapon_knifegg"
																	};
																	/*
	//Weapons Grenades
	new String:S_weapons_grenades_csgo[WEAPON_GRENADE_CSGO][]		= {
																		"weapon_hegrenade",
																		"weapon_flashbang",
																		"weapon_smokegrenade",
																		"weapon_molotov",
																		"weapon_decoy"
																	};
	*/
	//Weapons C4
	new String:S_weapons_c4_csgo[WEAPON_C4_CSGO][]					= {
																		"weapon_c4"
																	};
	//Weapons Defuse
	new String:S_weapons_defuse_csgo[WEAPON_DEFUSE_CSGO][]			= {
																		"item_defuser"
																	};
	//Weapons Gear
	new String:S_weapons_armor_csgo[WEAPON_ARMOR_CSGO][]			= {
																		"item_kelvar",
																		"item_assaultsuit"
																	};
#endif