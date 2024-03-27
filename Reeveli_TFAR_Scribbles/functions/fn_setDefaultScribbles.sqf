/*
 * Author: Reeveli
 * Part of Reeveli's TFAR Scribbles.
 * Client side function to apply default scribbles via callable function.
 * Needs to be (remotely) executed on all clients that should get the benefits.
 *
 * Arguments:
 * 0: Radio type, true = Sw, false = Lw <BOOLEAN> (default: true)
 * 1: Scribbles, array of strings <ARRAY>
 *
 * Return Value: BOOLEAN
 *
 * Example:
 * [true, ["Scribble 1","Scribble 2"]] remoteExecCall ["Rev_TFAR_fnc_setDefaultScribbles",0]
 *
 1.1
    Replaced Rev_TFAR_LwScribbles with Rev_radio_settings to account for new system for tracking LW radio identifiers introduced in mod v2.3
 */

if (!hasInterface) exitWith {false};
if (!isMultiplayer) exitWith {diag_log "Rev_TFAR_fnc_setDefaultScribbles: TFAR only works in multiplayer";false};

params
[
	["_type",true,[false]],
	["_scribbles",["Scribble 1","Scribble 2","Scribble 3"],[[]]]
];

//Safety check to turn all scribble array elements into strings
private _checked = _scribbles apply {if !(typeName _x isEqualTo "STRING") then {str _x} else {_x}};

//Sw
if (_type) exitWith {

	if (call TFAR_fnc_haveSWRadio) then
	{
		private _radio = call TFAR_fnc_activeSwRadio;
		Rev_TFAR_scribbleNamespace setVariable [_radio, _checked];
        systemChat "Sw scribbles changed via function call";
		diag_log "Rev_TFAR_fnc_setDefaultScribbles: Sw radio scribbles changed via function, EH ID44";
	};
};

//Lw
if (call TFAR_fnc_haveLRRadio) then
{
    private _LRradio = (call TFAR_fnc_activeLrRadio) # 0;
	_LRradio setVariable ["Rev_radio_settings", _checked, Rev_TFAR_locality];
    systemChat "Lw scribbles changed via function call";
	diag_log "Rev_TFAR_fnc_setDefaultScribbles: Lw radio scribbles changed via function, EH ID45";
};

true;