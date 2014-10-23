/*        <AIO MOD> (c) by <De Battista Clint - (http://doyou.watch)         */
/*                                                                           */
/*                       <AIO MOD> is licensed under a                       */
/* Creative Commons Attribution-NonCommercial-NoDerivs 4.0 Unported License. */
/*																			 */
/*      You should have received a copy of the license along with this       */
/*  work.  If not, see <http://creativecommons.org/licenses/by-nc-nd/4.0/>.  */
//***************************************************************************//
//***************************************************************************//
//***************************AIO MOD COOKIE GENERAL**************************//
//***************************************************************************//
//***************************************************************************//


/***********************************************************/
/******************** BEFORE PLUGIN START ******************/
/***********************************************************/
public APLRes:AskPluginLoad2CookieGeneralCsgo(Handle:myself, bool:late, String:error[], err_max)
{
	#if defined TRACK_BOMB_CSGO_LOADED
		AskPluginLoad2CookieTrackBombCsgo(myself, late, error, err_max);
	#endif
	
	#if defined SHOW_DAMAGE_CSGO_LOADED
		AskPluginLoad2CookieShowDamageCsgo(myself, late, error, err_max);
	#endif
	
	#if defined SOUNDS_KILL_CSGO_LOADED
		AskPluginLoad2CookieSoundsKillCsgo(myself, late, error, err_max);
	#endif
}

/***********************************************************/
/*********************** PLUGIN START **********************/
/***********************************************************/
public OnPluginStartCookieGeneralCsgo()
{
	#if defined TRACK_BOMB_CSGO_LOADED
		//#include "aio/cookies/csgo/track_bomb"
		OnPluginStartCookieTrackBombCsgo();
	#endif	
		
	#if defined SHOW_DAMAGE_CSGO_LOADED
		//#include "aio/cookies/csgo/show_damage"
		OnPluginStartCookieShowDamageCsgo();
	#endif	
	
	#if defined SOUNDS_KILL_CSGO_LOADED
		//#include "aio/cookies/csgo/sounds_kill"
		OnPluginStartCookieSoundsKillCsgo();
	#endif	
	
	SetCookieMenuItem(CookieGeneralPrefMenuGeneralCsgo, 0, "AIO MOD");
}

/***********************************************************/
/******************** WHEN CVARS CHANGE ********************/
/***********************************************************/
public Event_CvarChangeCookieGeneralCsgo(Handle:cvar, const String:oldValue[], const String:newValue[])
{
	#if defined TRACK_BOMB_CSGO_LOADED
		//#include "aio/cookies/csgo/track_bomb"
		Event_CvarChangeCookieTrackBombCsgo(cvar, oldValue, newValue);
	#endif	
	
	#if defined	SHOW_DAMAGE_CSGO_LOADED
		//#include "aio/cookies/csgo/show_damage"
		Event_CvarChangeCookieShowDamageCsgo(cvar, oldValue, newValue);
	#endif	
	
	#if defined	SOUNDS_KILL_CSGO_LOADED
		//#include "aio/cookies/csgo/sounds_kill"
		Event_CvarChangeCookieSoundsKillCsgo(cvar, oldValue, newValue);
	#endif	
}

/***********************************************************/
/******************* WHEN CONFIG EXECUTED ******************/
/***********************************************************/
public OnConfigsExecutedCookieGeneralCsgo()
{
	#if defined TRACK_BOMB_CSGO_LOADED
		//#include "aio/cookies/csgo/track_bomb"
		OnConfigsExecutedCookieTrackBombCsgo();
	#endif	
	
	#if defined SHOW_DAMAGE_CSGO_LOADED
		//#include "aio/cookies/csgo/show_damage"
		OnConfigsExecutedCookieShowDamageCsgo();
	#endif	
	
	#if defined	SOUNDS_KILL_CSGO_LOADED
		//#include "aio/cookies/csgo/sounds_kill"
		OnConfigsExecutedCookieSoundsKillCsgo();
	#endif	
}

/***********************************************************/
/********************* WHEN MAP START **********************/
/***********************************************************/
public OnMapStartCookieGeneralCsgo()
{
	#if defined TRACK_BOMB_CSGO_LOADED
		//#include "aio/cookies/csgo/track_bomb"
		OnMapStartCookieTrackBombCsgo();
	#endif	
	
	#if defined SHOW_DAMAGE_CSGO_LOADED	
		//#include "aio/cookies/csgo/show_damage"
		OnMapStartCookieShowDamageCsgo();
	#endif	
	
	#if defined	SOUNDS_KILL_CSGO_LOADED
		//#include "aio/cookies/csgo/sounds_kill"
		OnMapStartCookieSoundsKillCsgo();
	#endif	
}

/***********************************************************/
/**************** WHEN CLIENT PUT IN SERVER ****************/
/***********************************************************/
public OnClientPutInServerCookieGeneralCsgo(client)
{
	#if defined TRACK_BOMB_CSGO_LOADED
		//#include "aio/cookies/csgo/track_bomb"
		OnClientPutInServerCookieTrackBombCsgo(client);
	#endif	
	
	#if defined SHOW_DAMAGE_CSGO_LOADED	
		//#include "aio/cookies/csgo/show_damage"
		OnClientPutInServerCookieShowDamageCsgo(client);
	#endif	
	
	#if defined	SOUNDS_KILL_CSGO_LOADED
		//#include "aio/cookies/csgo/sounds_kill"
		OnClientPutInServerCookieSoundsKillCsgo(client);
	#endif	
}
/***********************************************************/
/******************** WHEN COOKIE CACHED *******************/
/***********************************************************/
public OnClientCookiesCachedCookieGeneralCsgo(client)
{
	#if defined TRACK_BOMB_CSGO_LOADED
		//#include "aio/cookies/csgo/track_bomb"
		OnClientCookiesCachedTrackBombCsgo(client);
	#endif	
	
	#if defined SHOW_DAMAGE_CSGO_LOADED	
		//#include "aio/cookies/csgo/show_damage"
		OnClientCookiesCachedShowDamageCsgo(client);
	#endif	
	
	#if defined	SOUNDS_KILL_CSGO_LOADED
		//#include "aio/cookies/csgo/sounds_kill"
		OnClientCookiesCachedSoundsKillCsgo(client);
	#endif	
}

/***********************************************************/
/******************* COMMANDE !SETTINGS ********************/
/***********************************************************/
public CookieGeneralPrefMenuGeneralCsgo(client,CookieMenuAction:action,any:info,String:buffer[],maxlen)
{
	if(action == CookieMenuAction_SelectOption)
	{
		BuildMenuGeneralCsgo(client);
	}
}
