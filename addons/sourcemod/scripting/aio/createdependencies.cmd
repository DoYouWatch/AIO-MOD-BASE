@Echo off
Cls

set root_path=%cd%

pushd ..
set scripting_path=%cd%\
set compiled_path=%cd%\compiled\

	pushd ..
	set plugin_path=%cd%\plugins\
	popd

popd
set plugin_path_csgo=\plugins\csgo\
set dependencies_path=\dependencies\csgo\

set afk_manager=afk_manager.inc
set afk_manager_dependencies=afk_manager.dep
set afk_manager_path=%root_path%%plugin_path_csgo%%afk_manager%
set afk_manager_dependencies_path=%root_path%%dependencies_path%%afk_manager_dependencies%

set bot_names=bot_names.inc
set bot_names_dependencies=bot_names.dep
set bot_names_path=%root_path%%plugin_path_csgo%%bot_names%
set bot_names_dependencies_path=%root_path%%dependencies_path%%bot_names_dependencies%

set high_ping_kicker=high_ping_kicker.inc
set high_ping_kicker_dependencies=high_ping_kicker.dep
set high_ping_kicker_path=%root_path%%plugin_path_csgo%%high_ping_kicker%
set high_ping_kicker_dependencies_path=%root_path%%dependencies_path%%high_ping_kicker_dependencies%

set only_hs=only_hs.inc
set only_hs_dependencies=only_hs.dep
set only_hs_path=%root_path%%plugin_path_csgo%%only_hs%
set only_hs_dependencies_path=%root_path%%dependencies_path%%only_hs_dependencies%

set show_damage=show_damage.inc
set show_damage_dependencies=show_damage.dep
set show_damage_path=%root_path%%plugin_path_csgo%%show_damage%
set show_damage_dependencies_path=%root_path%%dependencies_path%%show_damage_dependencies%

set sounds_kill=sounds_kill.inc
set sounds_kill_dependencies=sounds_kill.dep
set sounds_kill_path=%root_path%%plugin_path_csgo%%sounds_kill%
set sounds_kill_dependencies_path=%root_path%%dependencies_path%%sounds_kill_dependencies%

set start_weapons=start_weapons.inc
set start_weapons_dependencies=start_weapons.dep
set start_weapons_path=%root_path%%plugin_path_csgo%%start_weapons%
set start_weapons_dependencies_path=%root_path%%dependencies_path%%start_weapons_dependencies%

set track_bomb=track_bomb.inc
set track_bomb_dependencies=track_bomb.dep
set track_bomb_path=%root_path%%plugin_path_csgo%%track_bomb%
set track_bomb_dependencies_path=%root_path%%dependencies_path%%track_bomb_dependencies%

set win_or_die=win_or_die.inc
set win_or_die_dependencies=win_or_die.dep
set win_or_die_path=%root_path%%plugin_path_csgo%%win_or_die%
set win_or_die_dependencies_path=%root_path%%dependencies_path%%win_or_die_dependencies%



REM AFK MANAGER
IF EXIST %afk_manager_path% (
@echo #define AFK_MANAGER_CSGO_LOADED > %afk_manager_dependencies_path%
) ELSE (
@echo //#define AFK_MANAGER_CSGO_LOADED > %afk_manager_dependencies_path%
)

REM BOT_NAMES
IF EXIST %bot_names_path% (
@echo #define BOT_NAMES_CSGO_LOADED > %bot_names_dependencies_path%
) ELSE (
@echo //#define BOT_NAMES_CSGO_LOADED > %bot_names_dependencies_path%
)

REM HIGH_PING_KICKER
IF EXIST %high_ping_kicker_path% (
@echo #define HIGH_PING_KICKER_CSGO_LOADED > %high_ping_kicker_dependencies_path%
) ELSE (
@echo //#define HIGH_PING_KICKER_CSGO_LOADED > %high_ping_kicker_dependencies_path%
)

REM ONLY_HS
IF EXIST %only_hs_path% (
@echo #define ONLY_HS_CSGO_LOADED > %only_hs_dependencies_path%
) ELSE (
@echo //#define ONLY_HS_CSGO_LOADED > %only_hs_dependencies_path%
)

REM SHOW_DAMAGE
IF EXIST %show_damage_path% (
@echo #define SHOW_DAMAGE_CSGO_LOADED > %show_damage_dependencies_path%
) ELSE (
@echo //#define SHOW_DAMAGE_CSGO_LOADED > %show_damage_dependencies_path%
)

REM SOUNDS_KILL
IF EXIST %sounds_kill_path% (
@echo #define SOUNDS_KILL_CSGO_LOADED > %sounds_kill_dependencies_path%
) ELSE (
@echo //#define SOUNDS_KILL_CSGO_LOADED > %sounds_kill_dependencies_path%
)

REM START_WEAPONS
IF EXIST %start_weapons_path% (
@echo #define START_WEAPONS_CSGO_LOADED > %start_weapons_dependencies_path%
) ELSE (
@echo //#define START_WEAPONS_CSGO_LOADED > %start_weapons_dependencies_path%
)

REM TRACK_BOMB
IF EXIST %track_bomb_path% (
@echo #define TRACK_BOMB_CSGO_LOADED > %track_bomb_dependencies_path%
) ELSE (
@echo //#define TRACK_BOMB_CSGO_LOADED > %track_bomb_dependencies_path%
)

REM WIN_OR_DIE
IF EXIST %win_or_die_path% (
@echo #define WIN_OR_DIE_CSGO_LOADED > %win_or_die_dependencies_path%
) ELSE (
@echo //#define WIN_OR_DIE_CSGO_LOADED > %win_or_die_dependencies_path%
)

REM COMPILE
cd %scripting_path%
spcomp aio.sp
cd %root_path%

REM MOVE PLUGIN
move %scripting_path%aio.smx %plugin_path%aio.smx

Pause