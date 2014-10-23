/*        <AIO MOD> (c) by <De Battista Clint - (http://doyou.watch)         */
/*                                                                           */
/*                       <AIO MOD> is licensed under a                       */
/* Creative Commons Attribution-NonCommercial-NoDerivs 4.0 Unported License. */
/*																			 */
/*      You should have received a copy of the license along with this       */
/*  work.  If not, see <http://creativecommons.org/licenses/by-nc-nd/4.0/>.  */
//***************************************************************************//
//***************************************************************************//
//*****************************AIO MOD MENUS INIT****************************//
//***************************************************************************//
//***************************************************************************//

//***********************************//
//***********PARAMETERS**************//
//***********************************//

//Customs/Others
new EngineVersion:C_engine_menu_init_version;

/***********************************************************/
/*********************** PLUGIN START **********************/
/***********************************************************/
public OnPluginStartMenuInit()
{
	C_engine_menu_init_version = GetEngineVersion();
	switch (C_engine_menu_init_version)
	{
		case Engine_CSGO:
		{
			//#include "aio/menus/csgo/general"
			OnPluginStartMenuGeneralCsgo();
		}
	}	

}

/***********************************************************/
/******************** WHEN CVARS CHANGE ********************/
/***********************************************************/
public Event_CvarChangeStartMenuInit(Handle:cvar, const String:oldValue[], const String:newValue[])
{
	switch (C_engine_menu_init_version)
	{
		case Engine_CSGO:
		{
			//#include "aio/menus/csgo/general"
			Event_CvarChangeStartMenuGeneralCsgo(cvar, oldValue, newValue);
		}
	}
}

/***********************************************************/
/******************* WHEN CONFIG EXECUTED ******************/
/***********************************************************/
public OnConfigsExecutedMenuInit()
{
	switch (C_engine_menu_init_version)
	{
		case Engine_CSGO:
		{
			//#include "aio/menus/csgo/general"
			//OnConfigsExecutedMenuGeneralCsgo();
		}
	}
}

/***********************************************************/
/********************* WHEN MAP START **********************/
/***********************************************************/
public OnMapStartMenuInit()
{
	switch (C_engine_menu_init_version)
	{
		case Engine_CSGO:
		{
			//#include "aio/menus/csgo/general"
			OnMapStartMenuGeneralCsgo();
		}
	}
}

