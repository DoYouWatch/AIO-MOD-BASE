/*        <AIO MOD> (c) by <De Battista Clint - (http://doyou.watch)         */
/*                                                                           */
/*                       <AIO MOD> is licensed under a                       */
/* Creative Commons Attribution-NonCommercial-NoDerivs 4.0 Unported License. */
/*																			 */
/*      You should have received a copy of the license along with this       */
/*  work.  If not, see <http://creativecommons.org/licenses/by-nc-nd/4.0/>.  */
//***************************************************************************//
//***************************************************************************//
//*****************************AIO MOD DEPENDENCIES**************************//
//***************************************************************************//
//***************************************************************************//

//***********************************//
//*************DEFINES***************//
//***********************************//
#define PATH_PLUGINS_CSGO 		"addons/sourcemod/scripting/aio/plugins/csgo/"
#define PATH_DEPENDENCIES_CSGO 	"addons/sourcemod/scripting/aio/dependencies/csgo/"


#include "aio/dependencies/csgo/afk_manager.dep"
#include "aio/dependencies/csgo/bot_names.dep"
#include "aio/dependencies/csgo/high_ping_kicker.dep"
#include "aio/dependencies/csgo/only_hs.dep"
#include "aio/dependencies/csgo/show_damage.dep"
#include "aio/dependencies/csgo/sounds_kill.dep"
#include "aio/dependencies/csgo/start_weapons.dep"
#include "aio/dependencies/csgo/track_bomb.dep"
#include "aio/dependencies/csgo/win_or_die.dep"

/***********************************************************/
/******************** BEFORE PLUGIN START ******************/
/***********************************************************/
public APLRes:AskPluginLoad2Dependencies(Handle:myself, bool:late, String:error[], err_max)
{
	//PluginInfosPath("afk_manager.inc");
}

stock bool:PluginInfosPath(String:S_plugin_name[])
{
	new String:S_path[PLATFORM_MAX_PATH];
	Format(S_path, PLATFORM_MAX_PATH, "%s%s", PATH_PLUGINS_CSGO, S_plugin_name);
	
	if(FileExists(S_path))
	{
		LogMessage("File:%s exist", S_path);
		return true;
	}
	LogMessage("File:%s do not exist", S_path);
	return false;
}