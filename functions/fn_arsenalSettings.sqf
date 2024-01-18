/*
 * Author: Reeveli
 * Part of Reeveli's TFAR radio scribbles.
 * Client side function to save and restore radio settings when using BI or ACE arsenals.
 * Called as a postinit function.
 *
 * Arguments: NONE
 *
 * Return Value: BOOLEAN
 *
 * Example:
 * call Rev_TFAR_fnc_arsenalSettings
 *
 */

if (!isMultiplayer) exitWith {false;};
if (!hasInterface) exitWith {false};
if (!Rev_TFAR_radioSettings) exitWith {false};

//BI arsenal
[missionNamespace, "arsenalOpened", {	
	if (call TFAR_fnc_haveSWRadio) then
	{
		private _radio = call TFAR_fnc_activeSwRadio;
		player setVariable ["SW_radio_settings",(call TFAR_fnc_activeSwRadio) call TFAR_fnc_getSwSettings];
		diag_log "Rev_TFAR_fnc_arsenalSettings: SW radio settings saved on BI arsenal opening, EH ID15";
	};

	if (call TFAR_fnc_haveLRRadio) then
	{
		private _LRradio = call TFAR_fnc_activeLRRadio;
		player setVariable ["LR_radio_settings",(call TFAR_fnc_activeLRRadio) call TFAR_fnc_getLrSettings];
		diag_log "Rev_TFAR_fnc_arsenalSettings: LR radio settings saved on BI arsenal opening, EH ID16";
	};
}] call BIS_fnc_addScriptedEventHandler;


[missionNamespace, "arsenalClosed" , {

	//LW
	if (!isNil {player call TFAR_fnc_backpackLR}) then
	{ 
		private _settings = player getVariable ["LR_radio_settings",[]];
		if (count _settings > 0) then {[call TFAR_fnc_activeLrRadio, _settings] call TFAR_fnc_setLrSettings;};
		diag_log "Rev_TFAR_fnc_arsenalSettings: LR settings restored on exiting ACE arsenal, EH ID17";
	};

	//SW, exit if unique or no radio in inventory
	private _condition = {getNumber (configfile >> "CfgWeapons" >> _x >> "tf_prototype") isEqualTo 1};	
	if (!("ItemRadio" in assignedItems player) AND (_condition count assignedItems player < 1)) exitWith {
		diag_log "Rev_TFAR_fnc_arsenalSettings: Either no radio or unique radio in inventory when exiting arsenal, EH ID18";
	};
	 
	[
		"Rev_TFAR_RestoreSwArsenal",
		"OnRadiosReceived",
		{
			params ["_unit","_radio"];
			if (_unit != player) exitWith {};
			private _settings = player getVariable ["SW_radio_settings",[]];
			if (count _settings > 0) then {[call TFAR_fnc_activeSwRadio, _settings] call TFAR_fnc_setSwSettings;};
			//Remove EH after use
			["Rev_TFAR_RestoreSwArsenal", "OnRadiosReceived", player] call TFAR_fnc_removeEventHandler;
			diag_log "Rev_TFAR_fnc_arsenalSettings: SW settings restored on 'Rev_TFAR_RestoreSwArsenal', EH ID19";
		},
		Player
	] call TFAR_fnc_addEventHandler;

}] call BIS_fnc_addScriptedEventHandler;


////////////////////ACE Arsenal////////////////////
if (!isClass (configFile >> "CfgPatches" >> "ace_arsenal")) exitWith {};

//Save radio settings
["ace_arsenal_displayOpened", {	
	
	if (call TFAR_fnc_haveSWRadio) then
	{
		private _radio = call TFAR_fnc_activeSwRadio;
		player setVariable ["SW_radio_settings",(call TFAR_fnc_activeSwRadio) call TFAR_fnc_getSwSettings];
		diag_log "Rev_TFAR_fnc_arsenalSettings: SW radio settings saved on ACE arsenal opening, EH ID20";
	};

	if (call TFAR_fnc_haveLRRadio) then
	{
		private _LRradio = call TFAR_fnc_activeLRRadio;
		player setVariable ["LR_radio_settings",(call TFAR_fnc_activeLRRadio) call TFAR_fnc_getLrSettings];
		diag_log "Rev_TFAR_fnc_arsenalSettings: LR radio settings saved on ACE arsenal opening, EH ID21";
	};

}] call CBA_fnc_addEventHandler;


//Restore radio settings
["ace_arsenal_displayClosed", {

	//LW
	if (!isNil {player call TFAR_fnc_backpackLR}) then
	{ 
		private _settings = player getVariable ["LR_radio_settings",[]];
		if (count _settings > 0) then {[call TFAR_fnc_activeLrRadio, _settings] call TFAR_fnc_setLrSettings;};
		diag_log "Rev_TFAR_fnc_arsenalSettings: LR settings restored on exiting ACE arsenal, EH ID22";
	};


	//SW, exit if unique or no radio in inventory
	private _condition = {getNumber (configfile >> "CfgWeapons" >> _x >> "tf_prototype") isEqualTo 1};	
	if (!("ItemRadio" in assignedItems player) AND (_condition count assignedItems player < 1)) exitWith {
		diag_log "Rev_TFAR_fnc_arsenalSettings: Either no radio or unique radio in inventory when exiting arsenal, EH ID23";
	};
	 
	[
		"Rev_TFAR_RestoreSwArsenal",
		"OnRadiosReceived",
		{
			params ["_unit","_radio"];
			if (_unit != player) exitWith {};
			private _settings = player getVariable ["SW_radio_settings",[]];
			if (count _settings > 0) then {[call TFAR_fnc_activeSwRadio, _settings] call TFAR_fnc_setSwSettings;};
			//Remove EH after use
			["Rev_TFAR_RestoreSwArsenal", "OnRadiosReceived", player] call TFAR_fnc_removeEventHandler;
			diag_log "Rev_TFAR_fnc_arsenalSettings: SW settings restored on 'Rev_TFAR_RestoreSwArsenal', EH ID24";
		},
		Player
	] call TFAR_fnc_addEventHandler;

}] call CBA_fnc_addEventHandler;

true;