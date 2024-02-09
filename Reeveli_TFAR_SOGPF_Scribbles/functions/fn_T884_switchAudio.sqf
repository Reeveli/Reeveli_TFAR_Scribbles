/*
 * Author: Reeveli
 * Part of Reeveli's TFAR SOG:PF Scribbles.
 * Function to return to set correct night time color for T884 radio speaker light.
 * Called by radio UI dialog control.
 *
 * Arguments: NONE
 *
 * Return Value: NONE
 *
 * Example:
 * call Rev_TFAR_SOGPF_fnc_T884_switchAudio
 *
 */


private _activeRadio = TF_lr_dialog_radio;
private _speaker = _activeRadio call TFAR_fnc_getLrSpeakers;
private _speakerControl = uiNamespace getVariable ['#VN_Radio_T884_AudioSwitch', controlNull];

if ((sunOrMoon < 1) AND (!_speaker)) then {_speakerControl ctrlSetTextColor [0.18,0.18,0.18,1]}
else {_speakerControl ctrlSetTextColor [1,1,1,1]};