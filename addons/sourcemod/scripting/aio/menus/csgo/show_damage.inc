/*        <AIO MOD> (c) by <De Battista Clint - (http://doyou.watch)         */
/*                                                                           */
/*                       <AIO MOD> is licensed under a                       */
/* Creative Commons Attribution-NonCommercial-NoDerivs 4.0 Unported License. */
/*																			 */
/*      You should have received a copy of the license along with this       */
/*  work.  If not, see <http://creativecommons.org/licenses/by-nc-nd/4.0/>.  */
//***************************************************************************//
//***************************************************************************//
//**************************AIO MOD MENU SHOW DAMAGE*************************//
//***************************************************************************//
//***************************************************************************//

BuildSettingsMenuShowDamageCsgo(client)
{
	decl String:title[40], String:show_damage[40], String:status[40];
	new Handle:menu = CreateMenu(SettingsMenuShowDamageCsgo_Menu);
	SetMenuExitBackButton(menu, true);

	Format(status, sizeof(status), "%T", (C_show_damage_csgo[client]) ? "Enabled" : "Disabled", client);
	
	Format(show_damage, sizeof(show_damage), "%T", "Show damage menu settings message", client, status);
	AddMenuItem(menu, "M_show_damage", show_damage);
	
	Format(title, sizeof(title), "%T", "Show damage menu settings", client);
	SetMenuTitle(menu, title);
	DisplayMenu(menu, client, MENU_TIME_FOREVER);
}

public SettingsMenuShowDamageCsgo_Menu(Handle:menu, MenuAction:action, param1, param2)
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
			if(StrEqual(menu1, "M_show_damage"))
			{
				if(C_show_damage_csgo[param1])
				{
					C_show_damage_csgo[param1] = false;
					SetClientCookie(param1, H_cookie_show_damage_csgo, "0");
					BuildSettingsMenuShowDamageCsgo(param1);
				}
				else
				{
					C_show_damage_csgo[param1] = true;
					SetClientCookie(param1, H_cookie_show_damage_csgo, "1");
					BuildSettingsMenuShowDamageCsgo(param1);
				}
			}	
		}
	}
}