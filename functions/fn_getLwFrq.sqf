/*
 * Author: Reeveli
 * Part of Reeveli's TFAR radio scribbles.
 * Function to return the string of any LW channel frequency. If control is provided control text is also set.
 * Called from long range radio dialog control eventhandlers.
 *
 * Arguments:
 * 0: Channel number (1 - 8) <NUMBER>
 * 1: Optional: Control <CONTROL>
 *
 * Return Value: Frequency <STRING>
 *
 * Example:
 * [1] call Rev_TFAR_fnc_getLwFrq
 *
 */


params [
	["_channel", -1, [0]],
	["_control",controlNull,[controlNull]]
];

if ((_channel < 1) OR _channel > 8) exitWith {

	diag_log "Rev_TFAR_fnc_getLwFrq: Invalid channel provided";
	false;
};

private _channels = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 2;
private _freq = _channels select (_channel -1);

if (!isNull _control) then {
	_control ctrlSetText _freq;
};

_freq;