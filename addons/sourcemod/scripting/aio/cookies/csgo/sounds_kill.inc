/*        <AIO MOD> (c) by <De Battista Clint - (http://doyou.watch)         */
/*                                                                           */
/*                       <AIO MOD> is licensed under a                       */
/* Creative Commons Attribution-NonCommercial-NoDerivs 4.0 Unported License. */
/*																			 */
/*      You should have received a copy of the license along with this       */
/*  work.  If not, see <http://creativecommons.org/licenses/by-nc-nd/4.0/>.  */
//***************************************************************************//
//***************************************************************************//
//*************************AIO MOD COOKIE SOUNDS KILL************************//
//***************************************************************************//
//***************************************************************************//

#define MAX_NUM_SETS_CSGO 5

//***********************************//
//***********PARAMETERS**************//
//***********************************//

//Handle
new Handle:cvar_active_sounds_kill_text_csgo;
new Handle:cvar_active_sounds_kill_sound_csgo;


new Handle:H_cookie_sounds_kill_text_csgo;
new Handle:H_cookie_sounds_kill_sound_csgo;

//Bool
new bool:B_cookie_sounds_kill_loat_late = false;

//Customs/Others
new C_active_sounds_kill_text_csgo;
new C_active_sounds_kill_sound_csgo;
new C_text_preference[MAXPLAYERS+1];
new C_sound_preference[MAXPLAYERS+1];

/***********************************************************/
/******************** BEFORE PLUGIN START ******************/
/***********************************************************/
public APLRes:AskPluginLoad2CookieSoundsKillCsgo(Handle:myself, bool:late, String:error[], err_max)
{
	B_cookie_sounds_kill_loat_late = late;
}

/***********************************************************/
/*********************** PLUGIN START **********************/
/***********************************************************/
public OnPluginStartCookieSoundsKillCsgo()
{
	cvar_active_sounds_kill_text_csgo 					= CreateConVar("active_sounds_kill_text_csgo",  				"1", 					"Enable/Disable Client Sounds Kill texts", 			DEFAULT_FLAGS, 		true, 0.0, 		true, 1.0);
	cvar_active_sounds_kill_sound_csgo 					= CreateConVar("active_sounds_kill_sound_csgo",  				"1", 					"Enable/Disable Client Sounds Kill sounds", 		DEFAULT_FLAGS, 		true, 0.0, 		true, 1.0);
	
	H_cookie_sounds_kill_text_csgo 						= RegClientCookie("SoundsKillTexts", 		"Preference for Sounds Kill texts", 		CookieAccess_Private);
	H_cookie_sounds_kill_sound_csgo 					= RegClientCookie("SoundsKillSounds", 		"Preference for Sounds Kill sounds", 		CookieAccess_Private);
	
	HookEventsCookieSoundsKillCsgo();
	if(B_cookie_sounds_kill_loat_late)
	{
		LoadClientsCookieSoundsKillCsgo();
	}
}

/***********************************************************/
/******************** WHEN CVAR CHANGED ********************/
/***********************************************************/
HookEventsCookieSoundsKillCsgo()
{
	HookConVarChange(cvar_active_sounds_kill_text_csgo, 				Event_CvarChangeCookieSoundsKillCsgo);
	HookConVarChange(cvar_active_sounds_kill_sound_csgo, 				Event_CvarChangeCookieSoundsKillCsgo);
}

/***********************************************************/
/******************** WHEN CVARS CHANGE ********************/
/***********************************************************/
public Event_CvarChangeCookieSoundsKillCsgo(Handle:cvar, const String:oldValue[], const String:newValue[])
{
	UpdateStateCookieSoundsKillCsgo();
}

/***********************************************************/
/*********************** UPDATE STATE **********************/
/***********************************************************/
UpdateStateCookieSoundsKillCsgo()
{
	C_active_sounds_kill_text_csgo 			= GetConVarInt(cvar_active_sounds_kill_text_csgo);
	C_active_sounds_kill_sound_csgo 		= GetConVarInt(cvar_active_sounds_kill_sound_csgo);
}

/***********************************************************/
/******************* WHEN CONFIG EXECUTED ******************/
/***********************************************************/
public OnConfigsExecutedCookieSoundsKillCsgo()
{
	//UpdateStateCookieSoundsKill();
}

/***********************************************************/
/********************* WHEN MAP START **********************/
/***********************************************************/
public OnMapStartCookieSoundsKillCsgo()
{
	UpdateStateCookieSoundsKillCsgo();
}

/***********************************************************/
/******************** WHEN COOKIE CACHED *******************/
/***********************************************************/
/* Call when we deconnect? */
public OnClientCookiesCachedSoundsKillCsgo(client)
{
	if(IsClientInGame(client) && !IsFakeClient(client))
	{
		LoadClientCookieSoundsKillCsgo(client);
	}
}

public OnClientPutInServerCookieSoundsKillCsgo(client)
{
	if(!IsFakeClient(client))
	{
		//new new_value = GetConVarInt(cvar_active_sounds_kill_text_csgo);
		C_text_preference[client] 	= C_active_sounds_kill_text_csgo;
		C_sound_preference[client]	= C_active_sounds_kill_sound_csgo - 1;
		if(AreClientCookiesCached(client))
		{
			LoadClientCookieSoundsKillCsgo(client);
		}
	}
	else
	{
		C_text_preference[client] = 0;
		C_sound_preference[client] = -1;
	}
}

public LoadClientsCookieSoundsKillCsgo()
{
	for(new c=1;c<MaxClients;++c)
	{
		if(IsClientInGame(c) && !IsFakeClient(c))
		{
			//new new_value = GetConVarInt(cvar_active_sounds_kill_text_csgo);
			C_text_preference[c] 	= C_active_sounds_kill_text_csgo;
			C_sound_preference[c]	= C_active_sounds_kill_sound_csgo - 1;
			
			if(AreClientCookiesCached(c))
			{
				LoadClientCookieSoundsKillCsgo(c);
			}
		}
		else
		{
			C_text_preference[c]  = 0;
			C_sound_preference[c] = -1;
		}
	}
}

public LoadClientCookieSoundsKillCsgo(client)
{
	new String:value[16];
	GetClientCookie(client, H_cookie_sounds_kill_text_csgo, value, sizeof(value));
	if(strlen(value) > 0) C_text_preference[client] = StringToInt(value);
	
	GetClientCookie(client, H_cookie_sounds_kill_sound_csgo, value, sizeof(value));
	if(strlen(value) > 0) C_sound_preference[client] = StringToInt(value);
}

