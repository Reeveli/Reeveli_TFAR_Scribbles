/*
 * Author: Reeveli
 * Part of Reeveli's TFAR Scribbles.
 * Server side function to create custom namespace. Called as an extended preinit function.
 *
 * Arguments: NONE
 *
 * Return Value: NONE
 *
 */

if (!isServer) exitWith {};
if (!isMultiplayer) exitWith {};
Rev_TFAR_scribbleNamespace = true call CBA_fnc_createNamespace;
publicVariable "Rev_TFAR_scribbleNamespace";