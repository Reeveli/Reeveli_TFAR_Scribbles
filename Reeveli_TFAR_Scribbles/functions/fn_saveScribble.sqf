/*
 * Author: Reeveli
 * Part of Reeveli's TFAR Scribbles.
 * Function to save radio scribbles from closed radio interface to Rev_TFAR_scribbleNamespace
 *
 * Arguments:
 * 0: Unique radio <STRING>
 * 1: Scribbles <ARRAY>
 *
 * Return Value: Saved scribbles in array form <ARRAY>
 *
 * Example:
 * [TF_sw_dialog_radio, [ctrlText 8009,ctrlText 8010,ctrlText 8011,ctrlText 8012,ctrlText 8013,ctrlText 8014,ctrlText 8015,ctrlText 8016]] call Rev_TFAR_fnc_saveScribble
 *
 1.1
	Lw portion updated to keep track of radio settings identifier
 */


if (!isMultiplayer) exitWith {
	diag_log "Rev_TFAR_fnc_saveScribble: Radio scribbles are only saved in multiplayer";
	systemChat "Radio scribbles are only saved in multiplayer";
};

params
[
	["_radio","",["",objNull]],
	["_scribbles",[],[[]]]
];

//Lw scribbles have must be saved to object, can't use string in namespace
if ((typeName _radio) isEqualTo "OBJECT") exitWith {
	private _settings = TF_lr_dialog_radio select 1;
	_radio setVariable ["Rev_" + _settings, _scribbles, Rev_TFAR_locality];

	diag_log format ["Rev_TFAR_fnc_saveScribble: %1, %2: %3",_radio,_settings,_scribbles];
	[_settings,_scribbles]
};

Rev_TFAR_scribbleNamespace setVariable [_radio, _scribbles];
diag_log format ["Rev_TFAR_fnc_saveScribble: %1: %2",_radio,_scribbles];

_scribbles


//Kuinka tallentaa settings id to Lw radio variables in a way that wont overwrite other crew positions existign scribbles

//isnil {[1,nil,2] select 1}