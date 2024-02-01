/*
 * Author: Reeveli
 * Part of Reeveli's TFAR Scribbles.
 * Function to facilitate Sw alt channel marking for TFAR Scribble UIs.
 * If proper alt channel (0-7) is found then previous mark is removed and new one added
 * Called by radio UI dialog main onLoad EH.
 *
 * Arguments: NONE
 *
 * Return Value: NONE
 *
 * Example:
 * call Rev_TFAR_fnc_getSwAlt
 *
 1.1
	Added multiplayer check
	Added return value
 */


if (!isMultiplayer) exitWith {false};

private _alt = (TF_sw_dialog_radio call TFAR_fnc_getAdditionalSwChannel);
if ((_alt < 0) OR (_alt > 8)) exitWith {
	diag_log "Rev_TFAR_fnc_getSwAlt: Invalid TF_sw_dialog_radio";
};

//Removing previous alt mark
{ctrlSetText [_x,""]} forEach [8020,8021,8022,8023,8024,8025,8026,8027];
//Setting new alt mark
private _control = 8020 + _alt;
//dekay needed for control to be created
[{ctrlSetText [_this # 0,"X"]}, [_control], 0.1] call CBA_fnc_waitAndExecute;

true;