/*        <AIO MOD> (c) by <De Battista Clint - (http://doyou.watch)         */
/*                                                                           */
/*                       <AIO MOD> is licensed under a                       */
/* Creative Commons Attribution-NonCommercial-NoDerivs 4.0 Unported License. */
/*																			 */
/*      You should have received a copy of the license along with this       */
/*  work.  If not, see <http://creativecommons.org/licenses/by-nc-nd/4.0/>.  */
//***************************************************************************//
//***************************************************************************//
//**************************AIO MOD MENU TRACK BOMB**************************//
//***************************************************************************//
//***************************************************************************//

BuildSettingsMenuTrackBombCsgo(client)
{
	decl String:title[40], String:track_bomb[40], String:status[40];
	new Handle:menu = CreateMenu(SettingsMenuTrackBombCsgo_Menu);
	SetMenuExitBackButton(menu, true);

	Format(status, sizeof(status), "%T", (C_sounds_of_track_bomb_csgo[client]) ? "Enabled" : "Disabled", client);
	
	Format(track_bomb, sizeof(track_bomb), "%T", "Track Bomb menu settings sound", client, status);
	AddMenuItem(menu, "M_track_bomb_sound", track_bomb);
	
	Format(title, sizeof(title), "%T", "Menu Track bomb settings", client);
	SetMenuTitle(menu, title);
	DisplayMenu(menu, client, MENU_TIME_FOREVER);
}

public SettingsMenuTrackBombCsgo_Menu(Handle:menu, MenuAction:action, param1, param2)
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
			if(StrEqual(menu1, "M_track_bomb_sound"))
			{
				if(C_sounds_of_track_bomb_csgo[param1])
				{
					C_sounds_of_track_bomb_csgo[param1] = false;
					SetClientCookie(param1, H_cookie_track_bomb_sounds_csgo, "0");
					BuildSettingsMenuTrackBombCsgo(param1);
				}
				else
				{
					C_sounds_of_track_bomb_csgo[param1] = true;
					SetClientCookie(param1, H_cookie_track_bomb_sounds_csgo, "1");
					BuildSettingsMenuTrackBombCsgo(param1);
				}
			}	
		}
	}
}