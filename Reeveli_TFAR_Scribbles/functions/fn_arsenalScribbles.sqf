/*
 * Author: Reeveli
 * Part of Reeveli's TFAR Scribbles.
 * Client side function to save and restore radio scribbles when using BI or ACE arsenals.
 * Called as a postinit function.
 *
 * Arguments: NONE
 *
 * Return Value: BOOLEAN
 *
 * Example:
 * call Rev_TFAR_fnc_arsenalScribbles
 *
 */

if (!isMultiplayer) exitWith {false};
if (!hasInterface) exitWith {false};
if (!Rev_TFAR_saveScribbles) exitWith {false};

//BI arsenal
[missionNamespace, "arsenalOpened", {	

	//LW
	if (call TFAR_fnc_haveLRRadio) then
	{
		private _LRradio = (call TFAR_fnc_activeLrRadio) # 0;
		if (isnil {_LRradio getVariable ["Rev_TFAR_LwScribbles",nil]}) exitwith {
			diag_log "Rev_TFAR_fnc_arsenalScribbles: No Lw radio scribbles found on entering BI Arsenal, EH ID1"
		};
		private _scribbles = _LRradio getVariable ["Rev_TFAR_LwScribbles",nil];
		Rev_TFAR_scribbleNamespace setVariable ["Rev_TFAR_localLwScribbles", _scribbles];
		diag_log "Rev_TFAR_fnc_arsenalScribbles: Lw radio scribbles saved on BI arsenal opening, EH ID2"
	};

	//SW
	if (call TFAR_fnc_haveSWRadio) then
	{
		private _radio = call TFAR_fnc_activeSwRadio;
		if (isnil {Rev_TFAR_scribbleNamespace getVariable [_radio,nil]}) exitwith {
			diag_log "Rev_TFAR_fnc_arsenalScribbles: No Sw radio scribbles found on entering BI Arsenal, EH ID3"
		};
		private _scribbles = Rev_TFAR_scribbleNamespace getVariable [_radio,nil];
		Rev_TFAR_scribbleNamespace setVariable ["Rev_TFAR_localSwScribbles", _scribbles];
		diag_log "Rev_TFAR_fnc_arsenalScribbles: SW radio scribbles saved on BI arsenal opening, EH ID4"
	};

}] call BIS_fnc_addScriptedEventHandler;


[missionNamespace, "arsenalClosed" , {

	//LW
	if (call TFAR_fnc_haveLRRadio) then
	{ 
		private _scribbles = Rev_TFAR_scribbleNamespace getVariable "Rev_TFAR_localLwScribbles";
		private _LRradio = (call TFAR_fnc_activeLrRadio) # 0;
		_LRradio setVariable ["Rev_TFAR_LwScribbles", _scribbles, Rev_TFAR_locality];
		diag_log "Rev_TFAR_fnc_arsenalScribbles: LW scribbles restored on exiting BI arsenal, EH ID5";
	} else {
		Rev_TFAR_scribbleNamespace setVariable ["Rev_TFAR_localLwScribbles", nil];
	};

	//SW, exit if unique or no radio in inventory
	private _condition = {getNumber (configfile >> "CfgWeapons" >> _x >> "tf_prototype") isEqualTo 1};	
	if (!("ItemRadio" in assignedItems player) AND (_condition count assignedItems player < 1)) exitWith {
		diag_log "Rev_TFAR_fnc_arsenalScribbles: Either no radio or unique radio in inventory when exiting arsenal, EH ID6";
		Rev_TFAR_scribbleNamespace setVariable ["Rev_TFAR_localSwScribbles", nil];
	};
	 
	[
		"Rev_TFAR_RestoreSwArsenal",
		"OnRadiosReceived",
		{
			params ["_unit","_radio"];
			if (_unit != player) exitWith {};
			private _scribbles = Rev_TFAR_scribbleNamespace getVariable "Rev_TFAR_localSwScribbles";
			Rev_TFAR_scribbleNamespace setVariable [call TFAR_fnc_activeSwRadio, _scribbles];
			//Remove EH after use
			["Rev_TFAR_RestoreSwArsenal", "OnRadiosReceived", player] call TFAR_fnc_removeEventHandler;
			diag_log "Rev_TFAR_fnc_arsenalScribbles: SW scribbles restored on 'Rev_TFAR_RestoreSwArsenal, EH ID7'";
			Rev_TFAR_scribbleNamespace setVariable ["Rev_TFAR_localSwScribbles", nil];
		},
		Player
	] call TFAR_fnc_addEventHandler;

}] call BIS_fnc_addScriptedEventHandler;



////////////////////ACE Arsenal////////////////////
if (!isClass (configFile >> "CfgPatches" >> "ace_arsenal")) exitWith {};

//Save radio settings
["ace_arsenal_displayOpened", {	

	//LW
	if (call TFAR_fnc_haveLRRadio) then
	{
		private _LRradio = (call TFAR_fnc_activeLrRadio) # 0;
		if (isnil {_LRradio getVariable ["Rev_TFAR_LwScribbles",nil]}) exitwith {
			diag_log "Rev_TFAR_fnc_arsenalScribbles: No Lw radio scribbles found on entering ACE Arsenal, EH ID8"
		};
		private _scribbles = _LRradio getVariable ["Rev_TFAR_LwScribbles",nil];
		Rev_TFAR_scribbleNamespace setVariable ["Rev_TFAR_localLwScribbles", _scribbles];
		diag_log "Rev_TFAR_fnc_arsenalScribbles: Lw radio scribbles saved on ACE arsenal opening, EH ID9"
	};

	//SW
	if (call TFAR_fnc_haveSWRadio) then
	{
		private _radio = call TFAR_fnc_activeSwRadio;
		if (isnil {Rev_TFAR_scribbleNamespace getVariable [_radio,nil]}) exitwith {
			diag_log "Rev_TFAR_fnc_arsenalScribbles: No Sw radio scribbles found on entering ACE Arsenal, EH ID10"
		};
		private _scribbles = Rev_TFAR_scribbleNamespace getVariable [_radio,nil];
		Rev_TFAR_scribbleNamespace setVariable ["Rev_TFAR_localSwScribbles", _scribbles];
		diag_log "Rev_TFAR_fnc_arsenalScribbles: SW radio scribbles saved on ACE arsenal opening, EH ID11"
	};

}] call CBA_fnc_addEventHandler;


//Restore radio settings
["ace_arsenal_displayClosed", {

	//LW
	if (call TFAR_fnc_haveLRRadio) then
	{ 
		private _scribbles = Rev_TFAR_scribbleNamespace getVariable "Rev_TFAR_localLwScribbles";
		private _LRradio = (call TFAR_fnc_activeLrRadio) # 0;
		_LRradio setVariable ["Rev_TFAR_LwScribbles", _scribbles, Rev_TFAR_locality];
		diag_log "Rev_TFAR_fnc_arsenalScribbles: LW scribbles restored on exiting ACE arsenal, EH ID12";
	} else {
		Rev_TFAR_scribbleNamespace setVariable ["Rev_TFAR_localLwScribbles", nil];
	};

	//SW, exit if unique or no radio in inventory
	private _condition = {getNumber (configfile >> "CfgWeapons" >> _x >> "tf_prototype") isEqualTo 1};	
	if (!("ItemRadio" in assignedItems player) AND (_condition count assignedItems player < 1)) exitWith {
		diag_log "Rev_TFAR_fnc_arsenalScribbles: Either no radio or unique radio in inventory when exiting arsenal, EH ID13";
		Rev_TFAR_scribbleNamespace setVariable ["Rev_TFAR_localSwScribbles", nil];
	};
	 
	[
		"Rev_TFAR_RestoreSwArsenal",
		"OnRadiosReceived",
		{
			params ["_unit","_radio"];
			if (_unit != player) exitWith {};
			private _scribbles = Rev_TFAR_scribbleNamespace getVariable "Rev_TFAR_localSwScribbles";
			Rev_TFAR_scribbleNamespace setVariable [call TFAR_fnc_activeSwRadio, _scribbles];
			//Remove EH after use
			["Rev_TFAR_RestoreSwArsenal", "OnRadiosReceived", player] call TFAR_fnc_removeEventHandler;
			diag_log "Rev_TFAR_fnc_arsenalScribbles: SW scribbles restored on 'Rev_TFAR_RestoreSwArsenal, EH ID14'";
			Rev_TFAR_scribbleNamespace setVariable ["Rev_TFAR_localSwScribbles", nil];
		},
		Player
	] call TFAR_fnc_addEventHandler;

}] call CBA_fnc_addEventHandler;

true;