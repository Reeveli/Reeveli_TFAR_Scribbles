/*
 * Author: Reeveli
 * Part of Reeveli's TFAR Scribbles.
 * Function to facilitate LW alt channel marking for TFAR Scribble UIs.
 * Previous mark is removed and new one added. Note that function only supports 8 (not the max nine that TFAR has) controls from this mod.
 * Called by radio UI dialog main onLoad EH.
 *
 * Arguments: NONE
 *
 * Return Value: BOOLEAN
 *
 * Example:
 * call Rev_TFAR_fnc_getLwAlt
 *
 1.3.1
	Updated header documentation	
 1.3
	Fixed a bug where alt channel would not be removed (safety check exited at -1)
 1.2
	Added code for night time coloring	
 1.1
	Added multiplayer check
	Added return value
 */


if (!isMultiplayer) exitWith {false};

private _alt = (TF_lr_dialog_radio call TFAR_fnc_getAdditionalLrChannel);

//Removing previous alt mark
{ctrlSetText [_x,""]} forEach [8020,8021,8022,8023,8024,8025,8026,8027];
//Setting new alt mark
private _control = 8020 + _alt;
//Delay needed for control to be created
[{ctrlSetText [_this # 0,"X"]}, [_control], 0.1] call CBA_fnc_waitAndExecute;
//Night time color set
if (sunOrMoon < 1) then {(displayCtrl _control) ctrlSetTextColor [0,0,0,1]};

true;