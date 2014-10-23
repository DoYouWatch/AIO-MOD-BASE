/*        <AIO MOD> (c) by <De Battista Clint - (http://doyou.watch)         */
/*                                                                           */
/*                       <AIO MOD> is licensed under a                       */
/* Creative Commons Attribution-NonCommercial-NoDerivs 4.0 Unported License. */
/*																			 */
/*      You should have received a copy of the license along with this       */
/*  work.  If not, see <http://creativecommons.org/licenses/by-nc-nd/4.0/>.  */
//***************************************************************************//
//***************************************************************************//
//*******************************AIO MOD EVENTS******************************//
//***************************************************************************//
//***************************************************************************//

//***********************************//
//***********PARAMETERS**************//
//***********************************//

//Customs/Others
new EngineVersion:C_events_engine_version;

/**********************************************************************************************************************/
/************************************************* EVENTS GAMES SOURCE ************************************************/
/**********************************************************************************************************************/

/***********************************************************/
/******************** WHEN PLUGIN START ********************/
/***********************************************************/
public OnPluginStartEvents() 
{
	C_events_engine_version = GetEngineVersion();
	switch (C_events_engine_version)
	{
		case Engine_CSGO:
		{
			HookEvent("bot_takeover",		Event_BotTakeOver,		EventHookMode_Pre);
			HookEvent("round_prestart",		Event_RoundPreStart,	EventHookMode_Pre);
			HookEvent("round_poststart",	Event_RoundPostStart,	EventHookMode_Pre);
		}
	}
	
	HookEvent("player_spawn",		Event_PlayerSpawn,		EventHookMode_Pre);
	HookEvent("player_death",		Event_PlayerDeath,		EventHookMode_Pre);
	HookEvent("player_hurt",		Event_PlayerHurt,		EventHookMode_Pre);
	HookEvent("player_footstep",	Event_PlayerFootStep,	EventHookMode_Pre);
	HookEvent("player_team",		Event_PlayerTeam,		EventHookMode_Pre);
	
	HookEvent("bomb_pickup",		Event_BombPickup,		EventHookMode_Pre);
	HookEvent("bomb_dropped",		Event_BombDropped,		EventHookMode_Pre);
	HookEvent("bomb_planted",		Event_BombPlanted,		EventHookMode_Pre);
	HookEvent("bomb_abortplant",	Event_BombAbortPlant,	EventHookMode_Pre);
	
	
	HookEvent("round_start",		Event_RoundStart,		EventHookMode_Pre);
	HookEvent("round_freeze_end",	Event_RoundFreezeEnd,	EventHookMode_Pre);
	
	HookEvent("round_end",			Event_RoundEnd,			EventHookMode_Pre);
}

/***********************************************************/
/******************** WHEN PLAYER SPAWN ********************/
/***********************************************************/
public Action:Event_PlayerSpawn(Handle:event, const String:name[], bool:dontBroadcast)
{
	switch (C_events_engine_version)
	{
		case Engine_CSGO:
		{
			#if defined START_WEAPONS_CSGO_LOADED
				//#include "aio/plugins/csgo/start_weapons"
				Event_PlayerSpawnStartWeaponCsgo(event, name, dontBroadcast);
			#endif
			
			#if defined AFK_MANAGER_CSGO_LOADED
				//#include "aio/plugins/csgo/afk_manager"
				Event_PlayerSpawnAfkManagerCsgo(event, name, dontBroadcast);
			#endif
		}
	}
}

/***********************************************************/
/***************** WHEN PLAYER CHANGE TEAM *****************/
/***********************************************************/
public Action:Event_PlayerTeam(Handle:event, const String:name[], bool:dontBroadcast)
{
	switch (C_events_engine_version)
	{
		case Engine_CSGO:
		{
			#if defined AFK_MANAGER_CSGO_LOADED
				//#include "aio/plugins/csgo/afk_manager"
				Event_PlayerTeamAfkManagerCsgo(event, name, dontBroadcast);
			#endif
		}
	}
}

/***********************************************************/
/******************** WHEN PLAYER DEATH ********************/
/***********************************************************/
public Action:Event_PlayerDeath(Handle:event, const String:name[], bool:dontBroadcast)
{
	C_events_engine_version = GetEngineVersion();
	
	switch (C_events_engine_version)
	{
		case Engine_CSGO:
		{
			#if defined START_WEAPONS_CSGO_LOADED
				//#include "aio/plugins/csgo/start_weapons"
				Event_PlayerDeathStartWeaponCsgo(event, name, dontBroadcast);
			#endif
			
			#if defined SOUNDS_KILL_CSGO_LOADED
				//#include "aio/plugins/csgo/sounds_kill"
				Event_PlayerDeathSoundsKillCsgo(event, name, dontBroadcast);
			#endif
			
			#if defined AFK_MANAGER_CSGO_LOADED
				//#include "aio/plugins/csgo/afk_manager"
				Event_PlayerDeathAfkManagerCsgo(event, name, dontBroadcast);
			#endif
		}
	}
}

/***********************************************************/
/******************** WHEN PLAYER HURTED *******************/
/***********************************************************/
public Action:Event_PlayerHurt(Handle:event, const String:name[], bool:dontBroadcast)
{
	C_events_engine_version = GetEngineVersion();
	
	switch (C_events_engine_version)
	{
		case Engine_CSGO:
		{
			#if defined SHOW_DAMAGE_CSGO_LOADED
				//#include "aio/plugins/csgo/show_damage"
				Event_PlayerHurtShowDamageCsgo(event, name, dontBroadcast);
			#endif
		}
	}
}

/***********************************************************/
/***************** WHEN PLAYER TAKEOVER BOT ****************/
/***********************************************************/
public Action:Event_BotTakeOver(Handle:event, const String:name[], bool:dontBroadcast)
{
	C_events_engine_version = GetEngineVersion();
	
	switch (C_events_engine_version)
	{
		case Engine_CSGO:
		{
			#if defined START_WEAPONS_CSGO_LOADED
				//#include "aio/plugins/csgo/start_weapons"
				Event_BotTakeOverStartWeaponCsgo(event, name, dontBroadcast);
			#endif
		}
	}
}

/***********************************************************/
/********************* WHEN PLAYER WALK ********************/
/***********************************************************/
public Action:Event_PlayerFootStep(Handle:event, const String:name[], bool:dontBroadcast)
{
	C_events_engine_version = GetEngineVersion();
	
	switch (C_events_engine_version)
	{
		case Engine_CSGO:
		{

		}
	}
}

/***********************************************************/
/******************** WHEN ROUND START *********************/
/***********************************************************/
public Action:Event_RoundStart(Handle:event, const String:name[], bool:dontBroadcast)
{
	C_events_engine_version = GetEngineVersion();
	
	switch (C_events_engine_version)
	{
		case Engine_CSGO:
		{
			#if defined START_WEAPONS_CSGO_LOADED
				//#include "aio/plugins/csgo/start_weapons"
				Event_RoundStartStartWeaponCsgo(event, name, dontBroadcast);
			#endif
			
			#if defined TRACK_BOMB_CSGO_LOADED
				//#include "aio/plugins/csgo/track_bomb"
				Event_RoundStartTrackBombCsgo(event, name, dontBroadcast);
			#endif
			
			#if defined SOUNDS_KILL_CSGO_LOADED
				//#include "aio/plugins/csgo/sounds_kill"
				Event_RoundStartoundsKillCsgo(event, name, dontBroadcast);
			#endif
		}
	}
}

/***********************************************************/
/******************* WHEN ROUND PRESTART *******************/
/***********************************************************/
public Action:Event_RoundPreStart(Handle:event, const String:name[], bool:dontBroadcast)
{
	C_events_engine_version = GetEngineVersion();
	
	switch (C_events_engine_version)
	{
		case Engine_CSGO:
		{
			#if defined TRACK_BOMB_CSGO_LOADED
				//#include "aio/plugins/csgo/track_bomb"
				Event_RoundPreStartTrackBombCsgo(event, name, dontBroadcast);
			#endif
		}
	}
}

/***********************************************************/
/****************** WHEN ROUND POSTSTART *******************/
/***********************************************************/
public Action:Event_RoundPostStart(Handle:event, const String:name[], bool:dontBroadcast)
{
	C_events_engine_version = GetEngineVersion();
	
	switch (C_events_engine_version)
	{
		case Engine_CSGO:
		{

		}
	}
}

/***********************************************************/
/****************** WHEN ROUND POSTSTART *******************/
/***********************************************************/
public Action:Event_RoundFreezeEnd(Handle:event, const String:name[], bool:dontBroadcast)
{
	C_events_engine_version = GetEngineVersion();
	
	switch (C_events_engine_version)
	{
		case Engine_CSGO:
		{
			#if defined TRACK_BOMB_CSGO_LOADED
				//#include "aio/plugins/csgo/track_bomb"
				Event_RoundFreezeEndTrackBombCsgo(event, name, dontBroadcast);
			#endif
			
			#if defined SOUNDS_KILL_CSGO_LOADED
				//#include "aio/plugins/csgo/sounds_kill"
				Event_RoundFreezeEndSoundsKillCsgo(event, name, dontBroadcast);
			#endif
		}
	}
}

/***********************************************************/
/********************* WHEN ROUND END **********************/
/***********************************************************/
public Action:Event_RoundEnd(Handle:event, const String:name[], bool:dontBroadcast)
{
	C_events_engine_version = GetEngineVersion();
	
	switch (C_events_engine_version)
	{
		case Engine_CSGO:
		{
			#if defined START_WEAPONS_CSGO_LOADED
				//#include "aio/plugins/csgo/start_weapons"
				Event_RoundEndStartWeaponCsgo(event, name, dontBroadcast);
			#endif
			
			#if defined WIN_OR_DIE_CSGO_LOADED
				//#include "aio/plugins/csgo/win_or_die"
				Event_RoundEndWODCsgo(event, name, dontBroadcast);
			#endif
		}
	}
}

/***********************************************************/
/****************** WHEN PLAYER PICKUP BOMB ****************/
/***********************************************************/
public Action:Event_BombPickup(Handle:event, const String:name[], bool:dontBroadcast)
{
	C_events_engine_version = GetEngineVersion();
	
	switch (C_events_engine_version)
	{
		case Engine_CSGO:
		{
			#if defined START_WEAPONS_CSGO_LOADED
				//#include "aio/plugins/csgo/start_weapons"
				Event_BombPickupStartWeaponCsgo(event, name, dontBroadcast);
			#endif
			
			#if defined TRACK_BOMB_CSGO_LOADED
				//#include "aio/plugins/csgo/track_bomb"
				Event_BombPickupTrackBombCsgo(event, name, dontBroadcast);
			#endif
		}
	}
}

/***********************************************************/
/****************** WHEN PLAYER DROP BOMB ****************/
/***********************************************************/
public Action:Event_BombDropped(Handle:event, const String:name[], bool:dontBroadcast)
{
	C_events_engine_version = GetEngineVersion();
	
	switch (C_events_engine_version)
	{
		case Engine_CSGO:
		{
			#if defined TRACK_BOMB_CSGO_LOADED
				//#include "aio/plugins/csgo/track_bomb"
				Event_BombDroppedTrackBombCsgo(event, name, dontBroadcast);
			#endif
		}
	}
}

/***********************************************************/
/****************** WHEN PLAYER PLANT BOMB *****************/
/***********************************************************/
public Action:Event_BombPlanted(Handle:event, const String:name[], bool:dontBroadcast)
{
	C_events_engine_version = GetEngineVersion();
	
	switch (C_events_engine_version)
	{
		case Engine_CSGO:
		{
			#if defined TRACK_BOMB_CSGO_LOADED
				//#include "aio/plugins/csgo/track_bomb"
				Event_BombPlantedTrackBombCsgo(event, name, dontBroadcast);
			#endif
		}
	}
}

/***********************************************************/
/****************** WHEN PLAYER ABORT BOMB *****************/
/***********************************************************/
public Action:Event_BombAbortPlant(Handle:event, const String:name[], bool:dontBroadcast)
{
	C_events_engine_version = GetEngineVersion();
	
	switch (C_events_engine_version)
	{
		case Engine_CSGO:
		{
			#if defined TRACK_BOMB_CSGO_LOADED
				//#include "aio/plugins/csgo/track_bomb"
				Event_BombAbortPlantTrackBombCsgo(event, name, dontBroadcast);
			#endif
		}
	}
}