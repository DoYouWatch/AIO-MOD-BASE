/*        <AIO MOD> (c) by <De Battista Clint - (http://doyou.watch)         */
/*                                                                           */
/*                       <AIO MOD> is licensed under a                       */
/* Creative Commons Attribution-NonCommercial-NoDerivs 4.0 Unported License. */
/*																			 */
/*      You should have received a copy of the license along with this       */
/*  work.  If not, see <http://creativecommons.org/licenses/by-nc-nd/4.0/>.  */
//***************************************************************************//
//***************************************************************************//
//*************************AIO MOD COOKIE TRACK BOMB*************************//
//***************************************************************************//
//***************************************************************************//

//***********************************//
//***********PARAMETERS**************//
//***********************************//

//Handle
new Handle:cvar_active_track_bomb_sounds_csgo;


new Handle:H_cookie_track_bomb_sounds_csgo;

//Bool
new bool:B_cookie_track_bomb_loat_late = false;

//Customs/Others
new C_active_track_bomb_sound_csgo;
new C_sounds_of_track_bomb_csgo[MAXPLAYERS+1];

/***********************************************************/
/******************** BEFORE PLUGIN START ******************/
/***********************************************************/
public APLRes:AskPluginLoad2CookieTrackBombCsgo(Handle:myself, bool:late, String:error[], err_max)
{
	B_cookie_track_bomb_loat_late = late;
}

/***********************************************************/
/*********************** PLUGIN START **********************/
/***********************************************************/
public OnPluginStartCookieTrackBombCsgo()
{
	cvar_active_track_bomb_sounds_csgo 					= CreateConVar("active_track_bomb_sound_csgo",  				"1", 					"Enable/Disable Client Track the bomb sound", 			DEFAULT_FLAGS, 		true, 0.0, 		true, 1.0);
	
	H_cookie_track_bomb_sounds_csgo 					= RegClientCookie("TrackBombSounds", 		"Preference for Tack Bomb Sounds", 		CookieAccess_Private);
	
	HookEventsCookieTrackBombCsgo();
	if(B_cookie_track_bomb_loat_late)
	{
		LoadClientsCookieTrackBombCsgo();
	}
}

/***********************************************************/
/******************** WHEN CVAR CHANGED ********************/
/***********************************************************/
HookEventsCookieTrackBombCsgo()
{
	HookConVarChange(cvar_active_track_bomb_sounds_csgo, 				Event_CvarChangeCookieTrackBombCsgo);
}

/***********************************************************/
/******************** WHEN CVARS CHANGE ********************/
/***********************************************************/
public Event_CvarChangeCookieTrackBombCsgo(Handle:cvar, const String:oldValue[], const String:newValue[])
{
	UpdateStateCookieTrackBombCsgo();
}

/***********************************************************/
/*********************** UPDATE STATE **********************/
/***********************************************************/
UpdateStateCookieTrackBombCsgo()
{
	C_active_track_bomb_sound_csgo 			= GetConVarInt(cvar_active_track_bomb_sounds_csgo);
}

/***********************************************************/
/******************* WHEN CONFIG EXECUTED ******************/
/***********************************************************/
public OnConfigsExecutedCookieTrackBombCsgo()
{
	//UpdateStateCookieTrackBomb();
}

/***********************************************************/
/********************* WHEN MAP START **********************/
/***********************************************************/
public OnMapStartCookieTrackBombCsgo()
{
	UpdateStateCookieTrackBombCsgo();
}

/***********************************************************/
/******************** WHEN COOKIE CACHED *******************/
/***********************************************************/
/* Call when we deconnect? */
public OnClientCookiesCachedTrackBombCsgo(client)
{
	if(IsClientInGame(client) && !IsFakeClient(client))
	{
		LoadClientCookieTrackBombCsgo(client);
	}
}

public OnClientPutInServerCookieTrackBombCsgo(client)
{
	if(!IsFakeClient(client))
	{
		//new new_value = GetConVarInt(cvar_active_track_bomb_sounds_csgo);
		C_sounds_of_track_bomb_csgo[client] = C_active_track_bomb_sound_csgo;
		if(AreClientCookiesCached(client))
		{
			LoadClientCookieTrackBombCsgo(client);
		}
	}
	else
	{
		C_sounds_of_track_bomb_csgo[client] = 0;
	}
}

public LoadClientsCookieTrackBombCsgo()
{
	for(new c=1;c<MaxClients;++c)
	{
		if(IsClientInGame(c) && !IsFakeClient(c))
		{
			//new new_value = GetConVarInt(cvar_active_track_bomb_sounds_csgo);
			C_sounds_of_track_bomb_csgo[c] = C_active_track_bomb_sound_csgo;
			
			if(AreClientCookiesCached(c))
			{
				LoadClientCookieTrackBombCsgo(c);
			}
		}
		else
		{
			C_sounds_of_track_bomb_csgo[c]  = 0;
		}
	}
}

public LoadClientCookieTrackBombCsgo(client)
{
	new String:value[16];
	GetClientCookie(client, H_cookie_track_bomb_sounds_csgo, value, sizeof(value));
	if(strlen(value) > 0) C_sounds_of_track_bomb_csgo[client] = StringToInt(value);
}

