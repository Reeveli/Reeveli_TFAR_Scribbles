/*
 * Author: Reeveli
 * Part of Reeveli's TFAR SOG:PF Scribbles.
 * Function to return to set correct night time color for T884 radio additional light.
 * Called by radio UI dialog control.
 *
 * Arguments: NONE
 *
 * Return Value: NONE
 *
 * Example:
 * call Rev_TFAR_SOGPF_fnc_T884_switchAlt
 *
 */


private _activeRadio = TF_lr_dialog_radio;
private _channel = _activeRadio call TFAR_fnc_getLrChannel;
private _additional = _activeRadio call TFAR_fnc_getAdditionalLrChannel;
private _isAdditional = _additional isEqualTo _channel;
private _additionalControl = uiNamespace getVariable ['#VN_Radio_T884_AdditionalSwitch', controlNull];

if ((sunOrMoon < 1) AND (!_isAdditional)) then {_additionalControl ctrlSetTextColor [0.18,0.18,0.18,1]}
else {_additionalControl ctrlSetTextColor [1,1,1,1]};