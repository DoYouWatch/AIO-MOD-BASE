/*        <AIO MOD> (c) by <De Battista Clint - (http://doyou.watch)         */
/*                                                                           */
/*                       <AIO MOD> is licensed under a                       */
/* Creative Commons Attribution-NonCommercial-NoDerivs 4.0 Unported License. */
/*																			 */
/*      You should have received a copy of the license along with this       */
/*  work.  If not, see <http://creativecommons.org/licenses/by-nc-nd/4.0/>.  */
//***************************************************************************//
//***************************************************************************//
//****************************AIO MOD COOKIES INIT****************************//
//***************************************************************************//
//***************************************************************************//

//***********************************//
//***********PARAMETERS**************//
//***********************************//

//Customs/Others
new EngineVersion:C_engine_cookie_init_version;

/***********************************************************/
/******************** BEFORE PLUGIN START ******************/
/***********************************************************/
public APLRes:AskPluginLoad2CookieInit(Handle:myself, bool:late, String:error[], err_max)
{
	AskPluginLoad2CookieGeneralCsgo(myself, late, error, err_max);
}

/***********************************************************/
/*********************** PLUGIN START **********************/
/***********************************************************/
public OnPluginStartCookieInit()
{
	C_engine_cookie_init_version = GetEngineVersion();
	switch (C_engine_cookie_init_version)
	{
		case Engine_CSGO:
		{
			//#include "aio/cookies/csgo/general"
			OnPluginStartCookieGeneralCsgo();
		}
	}
}

/***********************************************************/
/******************** WHEN CVARS CHANGE ********************/
/***********************************************************/
public Event_CvarChangeCookieInit(Handle:cvar, const String:oldValue[], const String:newValue[])
{
	switch (C_engine_cookie_init_version)
	{
		case Engine_CSGO:
		{
			//#include "aio/cookies/csgo/general"
			Event_CvarChangeCookieGeneralCsgo(cvar, oldValue, newValue);
		}
	}
}

/***********************************************************/
/******************* WHEN CONFIG EXECUTED ******************/
/***********************************************************/
public OnConfigsExecutedCookieInit()
{
	switch (C_engine_cookie_init_version)
	{
		case Engine_CSGO:
		{
			//#include "aio/cookies/csgo/general"
			OnConfigsExecutedCookieGeneralCsgo();
		}
	}
}

/***********************************************************/
/********************* WHEN MAP START **********************/
/***********************************************************/
public OnMapStartCookieInit()
{
	switch (C_engine_cookie_init_version)
	{
		case Engine_CSGO:
		{
			//#include "aio/cookies/csgo/general"
			OnMapStartCookieGeneralCsgo();
		}
	}
}

/***********************************************************/
/**************** WHEN CLIENT PUT IN SERVER ****************/
/***********************************************************/
public OnClientPutInServerCookieInit(client)
{
	switch (C_engine_cookie_init_version)
	{
		case Engine_CSGO:
		{
			//#include "aio/cookies/csgo/general"
			OnClientPutInServerCookieGeneralCsgo(client);
		}
	}
}
/***********************************************************/
/******************** WHEN COOKIE CACHED *******************/
/***********************************************************/
public OnClientCookiesCachedCookieInit(client)
{
	switch (C_engine_cookie_init_version)
	{
		case Engine_CSGO:
		{
			//#include "aio/cookies/csgo/general"
			OnClientCookiesCachedCookieGeneralCsgo(client);
		}
	}
}

/***********************************************************/
/*********************** COOKIE PREF ***********************/
/***********************************************************/
public CookieGeneralPref(client,CookieMenuAction:action,any:info,String:buffer[],maxlen)
{
	switch (C_engine_cookie_init_version)
	{
		case Engine_CSGO:
		{
			//#include "aio/menus/csgo/general"
			CookieGeneralPrefMenuGeneralCsgo(client, action, info, buffer,maxlen);
		}
	}
}