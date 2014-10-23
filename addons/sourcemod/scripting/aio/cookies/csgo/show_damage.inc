/*        <AIO MOD> (c) by <De Battista Clint - (http://doyou.watch)         */
/*                                                                           */
/*                       <AIO MOD> is licensed under a                       */
/* Creative Commons Attribution-NonCommercial-NoDerivs 4.0 Unported License. */
/*																			 */
/*      You should have received a copy of the license along with this       */
/*  work.  If not, see <http://creativecommons.org/licenses/by-nc-nd/4.0/>.  */
//***************************************************************************//
//***************************************************************************//
//*************************AIO MOD COOKIE SHOW DAMAGE************************//
//***************************************************************************//
//***************************************************************************//

//***********************************//
//***********PARAMETERS**************//
//***********************************//

//Handle
new Handle:cvar_active_show_damage_msg_csgo;


new Handle:H_cookie_show_damage_csgo;

//Bool
new bool:B_cookie_show_damage_loat_late = false;

//Customs/Others
new C_active_show_damage_msg_csgo;
new C_show_damage_csgo[MAXPLAYERS+1];


/***********************************************************/
/******************** BEFORE PLUGIN START ******************/
/***********************************************************/
public APLRes:AskPluginLoad2CookieShowDamageCsgo(Handle:myself, bool:late, String:error[], err_max)
{
	B_cookie_show_damage_loat_late = late;
}

/***********************************************************/
/*********************** PLUGIN START **********************/
/***********************************************************/
public OnPluginStartCookieShowDamageCsgo()
{
	cvar_active_show_damage_msg_csgo 					= CreateConVar("active_show_damage_msg_csgo",  				"1", 					"Enable/Disable Client Show Damage message", 			DEFAULT_FLAGS, 		true, 0.0, 		true, 1.0);
	
	H_cookie_show_damage_csgo 							= RegClientCookie("ShowDamage", 		"Preference for Show Damage", 		CookieAccess_Private);
	
	HookEventsCookieShowDamageCsgo();
	if(B_cookie_show_damage_loat_late)
	{
		LoadClientsCookieShowDamageCsgo();
	}
}

/***********************************************************/
/******************** WHEN CVAR CHANGED ********************/
/***********************************************************/
HookEventsCookieShowDamageCsgo()
{
	HookConVarChange(cvar_active_show_damage_msg_csgo, 				Event_CvarChangeCookieShowDamageCsgo);
}

/***********************************************************/
/******************** WHEN CVARS CHANGE ********************/
/***********************************************************/
public Event_CvarChangeCookieShowDamageCsgo(Handle:cvar, const String:oldValue[], const String:newValue[])
{
	UpdateStateCookieShowDamageCsgo();
}

/***********************************************************/
/*********************** UPDATE STATE **********************/
/***********************************************************/
UpdateStateCookieShowDamageCsgo()
{
	C_active_show_damage_msg_csgo 			= GetConVarInt(cvar_active_show_damage_msg_csgo);
}

/***********************************************************/
/******************* WHEN CONFIG EXECUTED ******************/
/***********************************************************/
public OnConfigsExecutedCookieShowDamageCsgo()
{
	//UpdateStateCookieShowDamage();
}

/***********************************************************/
/********************* WHEN MAP START **********************/
/***********************************************************/
public OnMapStartCookieShowDamageCsgo()
{
	UpdateStateCookieShowDamageCsgo();
}

/***********************************************************/
/******************** WHEN COOKIE CACHED *******************/
/***********************************************************/
/* Call when we deconnect? */
public OnClientCookiesCachedShowDamageCsgo(client)
{
	if(IsClientInGame(client) && !IsFakeClient(client))
	{
		LoadClientCookieShowDamageCsgo(client);
	}
}

public OnClientPutInServerCookieShowDamageCsgo(client)
{
	if(!IsFakeClient(client))
	{
		//new new_value = GetConVarInt(cvar_active_show_damage_msg_csgo);
		C_show_damage_csgo[client] = C_active_show_damage_msg_csgo;
		if(AreClientCookiesCached(client))
		{
			LoadClientCookieShowDamageCsgo(client);
		}
	}
	else
	{
		C_show_damage_csgo[client] = 0;
	}
}

public LoadClientsCookieShowDamageCsgo()
{
	for(new c=1;c<MaxClients;++c)
	{
		if(IsClientInGame(c) && !IsFakeClient(c))
		{
			//new new_value = GetConVarInt(cvar_active_show_damage_msg_csgo);
			C_show_damage_csgo[c] = C_active_show_damage_msg_csgo;
			
			if(AreClientCookiesCached(c))
			{
				LoadClientCookieShowDamageCsgo(c);
			}
		}
		else
		{
			C_show_damage_csgo[c]  = 0;
		}
	}
}

public LoadClientCookieShowDamageCsgo(client)
{
	new String:value[16];
	GetClientCookie(client, H_cookie_show_damage_csgo, value, sizeof(value));
	if(strlen(value) > 0) C_show_damage_csgo[client] = StringToInt(value);
}

