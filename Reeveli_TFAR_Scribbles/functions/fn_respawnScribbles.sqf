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
 * call Rev_TFAR_fnc_respawnScribbles
 *
 */

if (!isMultiplayer) exitWith {false};
if (!hasInterface) exitWith {false};
if (!Rev_TFAR_saveScribbles) exitWith {false};

player addEventHandler ["Killed", {
	params ["_unit", "_killer", "_instigator", "_useEffects"];
	
	//LW
	if (call TFAR_fnc_haveLRRadio) then
	{
		private _LRradio = (call TFAR_fnc_activeLrRadio) # 0;
		if (isnil {_LRradio getVariable ["Rev_TFAR_LwScribbles",nil]}) exitwith {
			diag_log "Rev_TFAR_fnc_respawnScribbles: No Lw radio scribbles found on 'Killed', EH ID25";
		};
		private _scribbles = _LRradio getVariable ["Rev_TFAR_LwScribbles",nil];
		Rev_TFAR_scribbleNamespace setVariable ["Rev_TFAR_localLwScribbles", _scribbles];
		diag_log "Rev_TFAR_fnc_respawnScribbles: Lw radio scribbles saved on 'Killed', EH ID26";
	};

	//SW
	if (call TFAR_fnc_haveSWRadio) then
	{
		private _radio = call TFAR_fnc_activeSwRadio;
		if (isnil {Rev_TFAR_scribbleNamespace getVariable [_radio,nil]}) exitwith {
			diag_log "Rev_TFAR_fnc_respawnScribbles: No Sw radio scribbles found on 'Killed', EH ID27"
		};
		private _scribbles = Rev_TFAR_scribbleNamespace getVariable [_radio,nil];
		Rev_TFAR_scribbleNamespace setVariable ["Rev_TFAR_localSwScribbles", _scribbles];
		diag_log "Rev_TFAR_fnc_respawnScribbles: SW radio scribbles saved on 'Killed', EH ID28"
	};
}];


player addEventHandler ["Respawn", {
	params ["_unit", "_corpse"];
	
	private _Sw = Rev_TFAR_scribbleNamespace getVariable ['Rev_TFAR_localSwScribbles',nil];
	private _Lw = Rev_TFAR_scribbleNamespace getVariable ['Rev_TFAR_localLwScribbles',nil];
	
	//LW
	if (!isNil "_Lw") then {
		//We need delay to give TFAR time to assign Lw radio to player
		[
			{
				if (call TFAR_fnc_haveLRRadio) then
				{
					private _LRradio = (call TFAR_fnc_activeLrRadio) # 0;
					_LRradio setVariable ["Rev_TFAR_LwScribbles", _this, Rev_TFAR_locality];
					Rev_TFAR_scribbleNamespace setVariable ["Rev_TFAR_localLwScribbles",nil];
					diag_log "Rev_TFAR_fnc_respawnScribbles: Lw radio scribbles applied on respawn, EH ID29";
				};
			},
			_Lw,
			2
		] call CBA_fnc_waitAndExecute;
	};
			

	//SW, exit if unique or no radio in inventory (unique radios should retain settings even over respawn)
	if (!isNil "_Sw") then {
		[
			{
				//SW if radio in inventory
				private _condition = {isText (configFile >> "CfgWeapons" >> _x >> "tf_subtype")};	
				if (("ItemRadio" in assignedItems player) OR (_condition count assignedItems player > 0)) then {	 
					[
						"Rev_TFAR_respawnScribblesEH",
						"OnRadiosReceived",
						{
							params ["_unit","_radio"];
							private _scribbles = Rev_TFAR_scribbleNamespace getVariable ['Rev_TFAR_localSwScribbles',nil];
							Rev_TFAR_scribbleNamespace setVariable [_radio # 0, _scribbles];
							//Remove EH after use
							["Rev_TFAR_respawnScribblesEH", "OnRadiosReceived", player] call TFAR_fnc_removeEventHandler;
							diag_log "Rev_TFAR_fnc_respawnScribbles: Sw radio scribbles applied on respawn, EH ID30";
						},
						Player
					] call TFAR_fnc_addEventHandler;
				};
			},
			[],
			2
		] call CBA_fnc_waitAndExecute;
		
	};
}];

true;