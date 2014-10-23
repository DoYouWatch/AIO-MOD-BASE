/*        <AIO MOD> (c) by <De Battista Clint - (http://doyou.watch)         */
/*                                                                           */
/*                       <AIO MOD> is licensed under a                       */
/* Creative Commons Attribution-NonCommercial-NoDerivs 4.0 Unported License. */
/*																			 */
/*      You should have received a copy of the license along with this       */
/*  work.  If not, see <http://creativecommons.org/licenses/by-nc-nd/4.0/>.  */
//***************************************************************************//
//***************************************************************************//
//**************************AIO MOD MENU SOUNDS KILL*************************//
//***************************************************************************//
//***************************************************************************//

BuildSettingsMenuSoundsKillCsgo(client)
{
	decl String:title[40], String:sounds_kill_text[40], String:sounds_kill_sound[40], String:status_text[40], String:status_sound[40], String:set_name[40];
	new Handle:menu = CreateMenu(SettingsMenuSoundsKillCsgo_Menu);
	SetMenuExitBackButton(menu, true);

	Format(status_text, sizeof(status_text), "%T", (C_text_preference[client]) ? "Enabled" : "Disabled", client);
	Format(status_sound, sizeof(status_sound), "%T", "Disabled", client);
	
	Format(sounds_kill_text, sizeof(sounds_kill_text), "%T", "Sounds Kill menu settings text", client, status_text);
	AddMenuItem(menu, "M_sounds_kill_text", sounds_kill_text);

	new String:S_sets_name_menu_csgo[MAX_NUM_SETS_CSGO][PLATFORM_MAX_PATH];
	new String:S_buffer_string[PLATFORM_MAX_PATH];
	new Handle:H_sound_set_key = CreateKeyValues("List");
	
	BuildPath(Path_SM,S_buffer_string, PLATFORM_MAX_PATH, "configs/aio/sounds_kill/setslist.cfg");
	if(FileToKeyValues(H_sound_set_key, S_buffer_string))
	{
		if(KvJumpToKey(H_sound_set_key,"sets"))
		{
			new C_num_menu_sets = 0;
			for(new i = 0; i < MAX_NUM_SETS_CSGO; i++)
			{
				Format(S_buffer_string, PLATFORM_MAX_PATH, "set %i", (i+1));
				KvGetString(H_sound_set_key, S_buffer_string, S_sets_name_menu_csgo[i], PLATFORM_MAX_PATH);
				if(!StrEqual(S_sets_name_menu_csgo[i], ""))
				{
					Format(set_name, sizeof(set_name), "%T", S_sets_name_menu_csgo[i], client);
					
					if(C_sound_preference[client] == C_num_menu_sets)
					{
						Format(sounds_kill_sound, sizeof(sounds_kill_sound), "%T", "Sounds Kill menu settings sound", client, set_name);
					}
					else if(C_sound_preference[client] == -1)
					{
						Format(sounds_kill_sound, sizeof(sounds_kill_sound), "%T", "Sounds Kill menu settings sound", client, status_sound);
					}
					C_num_menu_sets++;
				}
			}
		}
		else
		{
			CloseHandle(H_sound_set_key);
			return;
		}
	}
	else
	{
		CloseHandle(H_sound_set_key);
	}
	CloseHandle(H_sound_set_key);



	
	AddMenuItem(menu, "M_sounds_kill_sound", sounds_kill_sound);
	
	Format(title, sizeof(title), "%T", "Sounds Kill settings", client);
	SetMenuTitle(menu, title);
	DisplayMenu(menu, client, MENU_TIME_FOREVER);
}

public SettingsMenuSoundsKillCsgo_Menu(Handle:menu, MenuAction:action, param1, param2)
{
	switch(action)
	{
		case MenuAction_End:
		{
			CloseHandle(menu);	
		}
		case MenuAction_Cancel:
		{
			if (param2 == MenuCancel_ExitBack)
			{	
				BuildMenuGeneralCsgo(param1);
			}
		}
		case MenuAction_Select:
		{
			new String:menu1[56];
			GetMenuItem(menu, param2, menu1, sizeof(menu1));
			if(StrEqual(menu1, "M_sounds_kill_text"))
			{
				if(C_text_preference[param1])
				{
					C_text_preference[param1] = false;
					SetClientCookie(param1, H_cookie_sounds_kill_text_csgo, "0");
					BuildSettingsMenuSoundsKillCsgo(param1);
				}
				else
				{
					C_text_preference[param1] = true;
					SetClientCookie(param1, H_cookie_sounds_kill_text_csgo, "1");
					BuildSettingsMenuSoundsKillCsgo(param1);
				}
			}	
			else if(StrEqual(menu1, "M_sounds_kill_sound"))
			{
				BuildSettingsMenuSoundsKillSetsCsgo(param1);
			}
		}
	}
}

BuildSettingsMenuSoundsKillSetsCsgo(client)
{
	decl String:title[40], String:set_name[40], String:set_name_menu[40], String:disabled[40], String:no_sound[40];
	new Handle:menu = CreateMenu(SettingsMenuSoundsKillSetsCsgo_Menu);
	SetMenuExitBackButton(menu, true);

	if(C_sound_preference[client] < 0)
	{
		Format(disabled, sizeof(disabled), "%T", "Disabled", client);
		AddMenuItem(menu, "M_sounds_kill_sound_set_name", disabled, ITEMDRAW_DISABLED);
	}
	else
	{
		Format(no_sound, sizeof(no_sound), "%T", "Sounds Kill menu no sound", client);
		AddMenuItem(menu, "M_sounds_kill_sound_set_name", no_sound);
	}
	
	new String:S_sets_name_menu_csgo[MAX_NUM_SETS_CSGO][PLATFORM_MAX_PATH];
	new String:S_buffer_string[PLATFORM_MAX_PATH];
	new Handle:H_sound_set_key = CreateKeyValues("List");
	
	BuildPath(Path_SM,S_buffer_string, PLATFORM_MAX_PATH, "configs/aio/sounds_kill/setslist.cfg");
	if(FileToKeyValues(H_sound_set_key, S_buffer_string))
	{
		if(KvJumpToKey(H_sound_set_key,"sets"))
		{
			new C_num_menu_sets = 0;
			for(new i = 0; i < MAX_NUM_SETS_CSGO; i++)
			{
				Format(S_buffer_string, PLATFORM_MAX_PATH, "set %i", (i+1));
				KvGetString(H_sound_set_key, S_buffer_string, S_sets_name_menu_csgo[i], PLATFORM_MAX_PATH);
				if(!StrEqual(S_sets_name_menu_csgo[i], ""))
				{
					Format(set_name, sizeof(set_name), "%T", S_sets_name_menu_csgo[i], client);
					
					Format(set_name_menu, sizeof(set_name_menu), "%T", "Sounds Kill menu settings sound set name", client, set_name);
					AddMenuItem(menu, "M_sounds_kill_sound_set_name", set_name_menu);
					
					C_num_menu_sets++;
				}
			}
		}
		else
		{
			CloseHandle(H_sound_set_key);
			return;
		}
	}
	else
	{
		CloseHandle(H_sound_set_key);
	}
	CloseHandle(H_sound_set_key);
	
	Format(title, sizeof(title), "%T", "Sounds Kill settings", client);
	SetMenuTitle(menu, title);
	DisplayMenu(menu, client, MENU_TIME_FOREVER);
}

public SettingsMenuSoundsKillSetsCsgo_Menu(Handle:menu, MenuAction:action, param1, param2)
{
	switch(action)
	{
		case MenuAction_End:
		{
			CloseHandle(menu);	
		}
		case MenuAction_Cancel:
		{
			if (param2 == MenuCancel_ExitBack)
			{	
				BuildSettingsMenuSoundsKillCsgo(param1);
			}
		}
		case MenuAction_Select:
		{
			new String:menu1[56];
			GetMenuItem(menu, param2, menu1, sizeof(menu1));
			
			if(StrEqual(menu1, "M_sounds_kill_sound_set_name"))
			{
			
				C_sound_preference[param1] = param2 - 1;

				new String:buffer[5];
				IntToString(C_sound_preference[param1], buffer, 5);
				SetClientCookie(param1, H_cookie_sounds_kill_sound_csgo, buffer);
				BuildSettingsMenuSoundsKillCsgo(param1);
			}
		}
	}
}