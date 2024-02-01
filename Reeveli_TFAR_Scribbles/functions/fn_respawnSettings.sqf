/*
 * Author: Reeveli
 * Part of Reeveli's TFAR Scribbles.
 * Client side function to save radio settings on death to restore when respawned.
 * Called as a postinit function.
 *
 * Arguments: NONE
 *
 * Return Value: BOOLEAN
 *
 * Example:
 * call Rev_TFAR_fnc_respawnSettings
 *
 */

if (!isMultiplayer) exitWith {false};
if (!hasInterface) exitWith {false};
if (!Rev_TFAR_radioSettings) exitWith {false};

player addEventHandler ["Killed", {
	params ["_unit", "_killer", "_instigator", "_useEffects"];
	
	if (call TFAR_fnc_haveSWRadio) then
	{
		player setVariable ["SW_radio_settings",(call TFAR_fnc_activeSwRadio) call TFAR_fnc_getSwSettings];
		diag_log "Rev_TFAR_fnc_respawnSettings: SW settings saved on 'Killed', EH ID31";
	};

	if (call TFAR_fnc_haveLRRadio) then
	{
		player setVariable ["LR_radio_settings",(call TFAR_fnc_activeLRRadio) call TFAR_fnc_getLrSettings];
		diag_log "Rev_TFAR_fnc_respawnSettings: LR settings saved on 'Killed', EH ID32";
	};
}];


player addEventHandler ["Respawn", {
	params ["_unit", "_corpse"];
	//LW
	[
		{!isNil {player call TFAR_fnc_backpackLR}},
		{
			private _settings = player getVariable ["LR_radio_settings",[]];
			if (count _settings > 0) then {[call TFAR_fnc_activeLrRadio, _settings] call TFAR_fnc_setLrSettings;};
			diag_log "Rev_TFAR_fnc_respawnSettings: LR settings restored on 'Respawn', EH ID33";	
		},
		[],
		5
	] call CBA_fnc_waitUntilAndExecute;
			

	//SW, exit if unique or no radio in inventory (unique radios should retain settings even over respawn)
	private _condition = {getNumber (configfile >> "CfgWeapons" >> _x >> "tf_prototype") isEqualTo 1};	
	if (!("ItemRadio" in assignedItems player) AND (_condition count assignedItems player < 1)) exitWith {
		diag_log "Rev_TFAR_fnc_respawnSettings: Either no radio or unique radio in inventory on 'Respawn', EH ID34";
	};
	 
	[
		"Rev_TFAR_RestoreSwRespawn",
		"OnRadiosReceived",
		{
			params ["_unit","_radio"];
			if (_unit != player) exitWith {};
			private _settings = player getVariable ["SW_radio_settings",[]];
			if (count _settings > 0) then {[call TFAR_fnc_activeSwRadio, _settings] call TFAR_fnc_setSwSettings;};
			//Remove EH after use
			["Rev_TFAR_RestoreSwRespawn", "OnRadiosReceived", player] call TFAR_fnc_removeEventHandler;
			diag_log "Rev_TFAR_fnc_respawnSettings: SW settings restored on 'Rev_TFAR_RestoreSwRespawn', EH ID35";
		},
		Player
	] call TFAR_fnc_addEventHandler;
}];

true;