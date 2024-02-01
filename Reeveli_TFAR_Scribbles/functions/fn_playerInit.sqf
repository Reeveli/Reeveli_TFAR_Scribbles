/*
 * Author: Reeveli
 * Part of Reeveli's TFAR Scribbles.
 * Client side function to create custom namespace if not created by the server. We also set variable for controlling Lw scribble locality.
 * Called as an extended postinit function.
 *
 * Arguments: NONE
 *
 * Return Value: BOOLEAN
 *
 1.0.1
	Fixed typo in header
 */

if (!isMultiplayer) exitWith {false};
if (!hasInterface) exitWith {false};
if (!isNil {Rev_TFAR_scribbleNamespace}) exitWith {
	diag_log "Rev_TFAR_fnc_playerInit: Rev_TFAR_scribbleNamespace found, created by server";
	Rev_TFAR_locality = true;
	false
};

Rev_TFAR_scribbleNamespace = false call CBA_fnc_createNamespace;
diag_log "Rev_TFAR_fnc_playerInit: Rev_TFAR_scribbleNamespace not found from server, created locally";
Rev_TFAR_locality = false;

true;