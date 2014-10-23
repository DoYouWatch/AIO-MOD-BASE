/*        <AIO MOD> (c) by <De Battista Clint - (http://doyou.watch)         */
/*                                                                           */
/*                       <AIO MOD> is licensed under a                       */
/* Creative Commons Attribution-NonCommercial-NoDerivs 4.0 Unported License. */
/*																			 */
/*      You should have received a copy of the license along with this       */
/*  work.  If not, see <http://creativecommons.org/licenses/by-nc-nd/4.0/>.  */
//***************************************************************************//
//***************************************************************************//
//*****************************AIO MOD OBJECTIVES****************************//
//***************************************************************************//
//***************************************************************************//

//***********************************//
//*************DEFINE****************//
//***********************************//
#define TAG_OBJECTIFS_CSGO "[AIO OBJECTIFS] - "

//***********************************//
//***********PARAMETERS**************//
//***********************************//

//Handle
new Handle:cvar_active_objectifs_dev;

//String
new String:S_map_objectif[64];

//Bool
new bool:B_active_objectifs_dev 			= false;
new bool:B_map_buyzone						= false;

/**********************************************************************************************************************/
/************************************************** EVENTS SOURCEMOD **************************************************/
/**********************************************************************************************************************/


/***********************************************************/
/*********************** PLUGIN START **********************/
/***********************************************************/
public OnPluginStartObjectifs()
{
	cvar_active_objectifs_dev		= CreateConVar("active_objectifs_dev",		"0", 		"Enable/Disable Objectifs Dev Mod", 		DEFAULT_FLAGS, 		true, 0.0, 		true, 1.0);
	HookConVarChange(cvar_active_objectifs_dev, Event_CvarChangeObjectifs);
}

/***********************************************************/
/******************** WHEN CVARS CHANGE ********************/
/***********************************************************/
public Event_CvarChangeObjectifs(Handle:cvar, const String:oldValue[], const String:newValue[])
{
	UpdateStateObjectifs();
}

/***********************************************************/
/*********************** UPDATE STATE **********************/
/***********************************************************/
UpdateStateObjectifs()
{
	B_active_objectifs_dev 	= GetConVarBool(cvar_active_objectifs_dev);
}

/***********************************************************/
/******************* WHEN CONFIG EXECUTED ******************/
/***********************************************************/
public OnConfigsExecutedObjectifs()
{
	UpdateStateObjectifs();
}

/***********************************************************/
/********************* WHEN MAP START **********************/
/***********************************************************/
public OnMapStartObjectifs()
{
	UpdateStateObjectifs();
	GetObjectifMap();
	GetBuyZoneMap();
}

/***********************************************************/
/******************* GET OBJECTIF OF MAP *******************/
/***********************************************************/
stock GetObjectifMap()
{
	new maxEntities = GetMaxEntities();
	decl String:class[24];
	
	for (new i = MaxClients + 1; i < maxEntities; i++)
	{
		if (IsValidEdict(i))
		{
			GetEdictClassname(i, class, sizeof(class));
			if (StrEqual(class, "func_bomb_target", false))
			{
				S_map_objectif = "bomb";			
			}
			else if (StrEqual(class, "func_hostage_rescue", false))
			{
				S_map_objectif = "hostage";		
			}
			/*else if(StrEqual(S_map_objectif, "bomb", false) || StrEqual(S_map_objectif, "hostage", false))
			{
				S_map_objectif = "none";
			}*/

		}
	}
	if(B_active_objectifs_dev)
	{
		if(StrEqual(S_map_objectif, "bomb", false))
		{
			LogMessage("%sObjective Map: bomb", TAG_OBJECTIFS_CSGO);
		}
		else if(StrEqual(S_map_objectif, "hostage", false))
		{
			LogMessage("%sObjective Map: hostage", TAG_OBJECTIFS_CSGO);
		}
		/*else if(StrEqual(S_map_objectif, "bomb", false) || StrEqual(S_map_objectif, "hostage", false))
		{
			LogMessage("%sObjective Map: free", TAG_OBJECTIFS_CSGO);
		}*/
	}
} 

/***********************************************************/
/******************* SET OBJECTIF OF MAP *******************/
/***********************************************************/
stock SetObjectifMap(const String:status[])
{
	new maxEntities = GetMaxEntities();
	decl String:class[24];
	
	for (new i = MaxClients + 1; i < maxEntities; i++)
	{
		if (IsValidEdict(i))
		{
			GetEdictClassname(i, class, sizeof(class));
			if (StrEqual(class, "func_bomb_target") || StrEqual(class, "func_hostage_rescue"))
			{
				AcceptEntityInput(i, status);
				if(B_active_objectifs_dev)
				{
					LogMessage("%sObjective map is now: %s", TAG_OBJECTIFS_CSGO, status);
				}
			}
		}
	}
}

/***********************************************************/
/********************* REMOVE HOSTAGES *********************/
/***********************************************************/
stock RemoveHostages()
{
	new maxEntities = GetMaxEntities();
	decl String:class[24];
	
	for (new i = MaxClients + 1; i < maxEntities; i++)
	{
		if (IsValidEdict(i))
		{
			GetEdictClassname(i, class, sizeof(class));
			if (StrEqual(class, "hostage_entity"))
			{
				AcceptEntityInput(i, "Kill");
				if(B_active_objectifs_dev)
				{
					LogMessage("%Hostages has been deleted", TAG_OBJECTIFS_CSGO);
				}
			}
		}
	}
}

/***********************************************************/
/*********************** REMOVE C4 *************************/
/***********************************************************/
stock RemoveC4()
{
	for (new i = 1; i <= MaxClients; i++)
	{
		if (StripC4(i))
			break;
	}
}

/***********************************************************/
/************************ STRIP C4 *************************/
/***********************************************************/
stock bool:StripC4(client)
{
	if (IsClientValid(client) && (Teams:GetClientTeam(client) == TeamT))
	{
		new c4Index = GetPlayerWeaponSlot(client, _:SlotC4);
		if (c4Index != -1)
		{
			decl String:weapon[24];
			GetClientWeapon(client, weapon, sizeof(weapon));
			// If the player is holding C4, switch to the best weapon before removing it.
			if (StrEqual(weapon, "weapon_c4"))
			{
				if (GetPlayerWeaponSlot(client, _:SlotPrimary) != -1)
					ClientCommand(client, "slot1");
				else if (GetPlayerWeaponSlot(client, _:SlotSecondary) != -1)
					ClientCommand(client, "slot2");
				else
					ClientCommand(client, "slot3");
				
			}
			RemovePlayerItem(client, c4Index);
			AcceptEntityInput(c4Index, "Kill");
			if(B_active_objectifs_dev)
			{
				LogMessage("%sC4 has been striped", TAG_OBJECTIFS_CSGO);
			}
			return true;
		}
	}
	return false;
}

/***********************************************************/
/******************* GET OBJECTIF OF MAP *******************/
/***********************************************************/
stock GetBuyZoneMap()
{
	B_map_buyzone = false;
	decl String:szClass[65];
	for (new i = MaxClients; i <= GetMaxEntities(); i++)
	{
		if(IsValidEdict(i) && IsValidEntity(i))
		{
			GetEdictClassname(i, szClass, sizeof(szClass));
			if(StrEqual("func_buyzone", szClass))
            {
                B_map_buyzone = true;
            }
		}
	} 
	
	if(B_active_objectifs_dev)
	{
		if(B_map_buyzone)
		{
			LogMessage("%sBuyzone Map: yes", TAG_OBJECTIFS_CSGO);
		}
		else
		{
			LogMessage("%sBuyzone Map: no", TAG_OBJECTIFS_CSGO);
		}

	}
} 

/***********************************************************/
/******************* REMOVE BUYZONE OF MAP ********************/
/***********************************************************/
stock RemoveBuyZoneMap()
{
	decl String:szClass[65];
	for (new i = MaxClients; i <= GetMaxEntities(); i++)
	{
		if(IsValidEdict(i) && IsValidEntity(i))
		{
			GetEdictClassname(i, szClass, sizeof(szClass));
			if(StrEqual("func_buyzone", szClass))
			{
				RemoveEdict(i);
				if(B_active_objectifs_dev)
				{
					LogMessage("%sBuyzone has been deleted", TAG_OBJECTIFS_CSGO);
				}
            }
		}
	} 
}