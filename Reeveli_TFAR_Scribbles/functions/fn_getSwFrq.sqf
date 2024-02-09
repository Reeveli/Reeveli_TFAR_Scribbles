/*
 * Author: Reeveli
 * Part of Reeveli's TFAR Scribbles.
 * Function to return the string of any SW channel frequency. If control is provided control text is also set.
 * Called by radio UI dialog controls.
 *
 * Arguments:
 * 0: Channel number (1 - 8) <NUMBER>
 * 1: Optional: Control <CONTROL>
 *
 * Return Value: Frequency <STRING>
 *
 * Example:
 * [1,_control] call Rev_TFAR_fnc_getSwFrq
 *
 1.2
	Added code for night time coloring
 1.1
	Added multiplayer check
 */


if (!isMultiplayer) exitWith {};

params [
	["_channel", -1, [0]],
	["_control",controlNull,[controlNull]]
];

if ((_channel < 1) OR _channel > 8) exitWith {

	diag_log "Rev_TFAR_fnc_getSwFrq: Invalid channel provided";
	false;
};

private _channels = (TF_sw_dialog_radio call TFAR_fnc_getSwSettings) select 2;
private _freq = _channels select (_channel -1);

if (!isNull _control) then {
	_control ctrlSetText _freq;
	if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};
};

_freq;