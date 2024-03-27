/*
 * Author: Reeveli
 * Part of Reeveli's TFAR Scribbles.
 * Client side function to return any specific radio scribble stored in Rev_TFAR_scribbleNamespace.
 * Called from individual radio dialog control onLoad EHs.
 *
 * Arguments:
 * 0: Radio type "Sw" or "Lw" (default: "Sw") <STRING>
 * 1: Channel number (1 - 9) <NUMBER>
 * 2: Control <CONTROL>
 *
 * Return Value: Scribble (default: ""), FALSE if function called when no correct radio present <STRING, BOOLEAN>
 *
 * Example:
 * ['Sw', 1, _control] call Rev_TFAR_fnc_loadScribble
 *
3.2
	Lw portion updated to account for radio settings identifiers
	Fixed header and comments referring to only 8 channels
3.1
	Added code for night time text color
3.0
	Function rewritten to solve issues with vehicle radios
2.0
	Function rewritten for client side operation only

 */

if (!hasInterface) exitWith {};
if (!isMultiplayer) exitWith {diag_log "Rev_TFAR_fnc_loadScribble: TFAR only works in multiplayer";};

params [
	["_radio","",["",objNull]],
	["_index", -1, [0]],
	["_control",controlNull,[controlNull]]
];


//Lw scribbles loaded from object
if ((typeName _radio) isEqualTo "OBJECT") exitWith {	
	private _settings = TF_lr_dialog_radio # 1;
	
	//If no scribbles for this identifier we can exit
	private _scribbles = _radio getVariable ("Rev_" + _settings);
	if (isnil "_scribbles") exitWith {""};
	
	//Safety check if array is smaller than called channel, not all radio dialogs have full 9 slots for scribbles
	if (count _scribbles < (_index - 1)) exitWith {""};
	private _text = _scribbles select (_index - 1);
	if (!isNull _control) then {
		_control ctrlSetText _text;
		if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};
	};
	_text;
};


//Sw
private _unique = Rev_TFAR_scribbleNamespace getVariable [_radio, nil];
if (!isNil "_unique") exitWith
{
	//Safety check if array is smaller than called channel, not all radio dialogs have full 9 slots for scribbles
	if (count _unique < (_index - 1)) exitWith {""};

	private _text = _unique select (_index - 1);
	if (!isNull _control) then {
		_control ctrlSetText _text;
		if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};
	};
	_text;
};


//Return empty string if no exists
"";