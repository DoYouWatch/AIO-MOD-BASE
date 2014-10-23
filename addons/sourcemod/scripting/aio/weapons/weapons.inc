/*        <AIO MOD> (c) by <De Battista Clint - (http://doyou.watch)         */
/*                                                                           */
/*                       <AIO MOD> is licensed under a                       */
/* Creative Commons Attribution-NonCommercial-NoDerivs 4.0 Unported License. */
/*																			 */
/*      You should have received a copy of the license along with this       */
/*  work.  If not, see <http://creativecommons.org/licenses/by-nc-nd/4.0/>.  */
//***************************************************************************//
//***************************************************************************//
//******************************AIO MOD WEAPONS******************************//
//***************************************************************************//
//***************************************************************************//

//***********************************//
//*************DEFINES***************//
//***********************************//

#define	TAG_WEAPON					"[AIO WEAPONS] - "
#define HE_GRENADE_OFFSET			13	// (11 * 4)
#define FLASHBANG_OFFSET 			14	// (12 * 4)
#define SMOKEGRENADE_OFFSET			15	// (13 * 4)
#define	MOLOTOV_OFFSET				16	// (14 * 4) Also Molotovs
#define	DECOY_OFFSET				17	// (15 * 4)

#define DMG_KNIFE_CSGO 				4100
#define DMG_HE_CSGO					4
#define DMG_MOLOTOV_CSGO			8
#define DMG_HS_CSGO 				1073745922
#define DMG_SHOT_CSGO 				4098

//***********************************//
//***********PARAMETERS**************//
//***********************************//

#if defined START_WEAPONS_CSGO_LOADED
//Customs/Others
//new m_iAmmo;
new m_bHasDefuser;
new m_bHasHelmet;
//new m_bHasNightVision;
new m_ArmorValue;

#endif


/***********************************************************/
/******************** WHEN PLUGIN START ********************/
/***********************************************************/
public OnPluginStartWeapons() 
{
	#if defined START_WEAPONS_CSGO_LOADED
		//m_iAmmo 			= FindSendPropOffs("CCSPlayer", "m_iAmmo");
		m_bHasDefuser 		= FindSendPropOffs("CCSPlayer", "m_bHasDefuser");
		m_bHasHelmet 		= FindSendPropOffs("CCSPlayer", "m_bHasHelmet");
		//m_bHasNightVision 	= FindSendPropOffs("CCSPlayer", "m_bHasNightVision");
		m_ArmorValue 		= FindSendPropOffs("CCSPlayer", "m_ArmorValue");
	#endif
}
