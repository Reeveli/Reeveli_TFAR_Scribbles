/*
 * Author: Reeveli
 * Part of Reeveli's TFAR SOG:PF Radio scribbles.
 * UI for Type 102E transmitter.
1.0.1
	Cleaned missing semi-colon
*/

#define REV_T102E_W			(62 * (((getResolution select 4) min 1.2) / 40))
#define REV_T102E_H			(34 * (((getResolution select 4) min 1.2) / 40)) * (4 / 3)
#define REV_T102E_X			0.5 - (REV_T102E_W / 2)
#define REV_T102E_Y			0.5 - (REV_T102E_H / 2)

#define REV_102NOTE_W			REV_T102E_W * 0.20905
#define REV_102NOTE_H			REV_T102E_H * 0.38
#define REV_102NOTE_X			REV_T102E_X + 0.061 * REV_T102E_W
#define REV_102NOTE_Y			REV_T102E_Y + 0.55 * REV_T102E_H


class VN_RadioDialog_T102E
{
	idd = 10001;
	onLoad = "_this call VN_fnc_T102E_onLoad";
	onUnload = "if (call VN_fnc_TFAR_isOldVersion) then { ['OnRadioOpen', player, [TF_lr_dialog_radio, true, 'VN_RadioDialog_T102E', false]] call TFAR_fnc_fireEventHandlers; } else { ['OnRadioOpen', [player, TF_lr_dialog_radio, true, 'VN_RadioDialog_T102E', false]] call TFAR_fnc_fireEventHandlers; };[TF_lr_dialog_radio # 0, [ctrlText 8009,ctrlText 8010,ctrlText 8011,ctrlText 8012,ctrlText 8013,ctrlText 8014,ctrlText 8015,ctrlText 8016]] call Rev_TFAR_fnc_saveScribble";
	onMouseButtonDown = "uiNamespace setVariable ['@VN_RadioDialog_T102E_State', _this select [4,3]]";
	onMouseButtonUp = "uiNamespace setVariable ['@VN_RadioDialog_T102E_State', _this select [4,3]]";
	onKeyDown = "call VN_fnc_T102E_onUpdate";
	class Controls
	{
		class _INVISIBLE_BUTTON: RscButton
		{
			colorBackground[] = {0,0,0,0};
			colorBackgroundActive[] = {0,0,0,0};
			colorBackgroundDisabled[] = {0,0,0,0};
			colorBorder[] = {0,0,0,0};
			colorDisabled[] = {0,0,0,0};
			colorFocused[] = {0,0,0,0};
			colorShadow[] = {0,0,0,0};
			colorText[] = {0,0,0,0};
			soundEnter[] = {"",0.1,1};
			soundPush[] = {"",0.1,1};
			soundClick[] = {"",0.1,1};
			soundEscape[] = {"",0.1,1};
		};
		class Radio: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_T102E_radio_ca.paa";
			x = "0.5 - (62 * (((getResolution select 4) min 1.2) / 40)) / 2";
			y = "0.5 - ((34 * (((getResolution select 4) min 1.2) / 40)) * (4 / 3)) / 2";
			w = "(62 * (((getResolution select 4) min 1.2) / 40))";
			h = "(34 * (((getResolution select 4) min 1.2) / 40)) * (4 / 3)";
			onLoad = "if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class AudioDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_t102e_dial_1_ca.paa";
			x = "(43 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(4.5 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.7 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4.7 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_T102E_AudioDial', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class AudioDialButton: _INVISIBLE_BUTTON
		{
			x = "(43 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(4.5 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.7 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4.7 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_T102E_State', [false,false,false]])) call VN_fnc_T102E_setAudio";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_T102E_setAudio }";
		};
		class AdditionalDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_t102e_dial_1_ca.paa";
			x = "(22.2 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(13.2 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.5 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4.5 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_T102E_AdditionalDial', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class AdditionalDialButton: _INVISIBLE_BUTTON
		{
			x = "(22.2 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(13.2 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.5 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4.5 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_T102E_State', [false,false,false]])) call VN_fnc_T102E_setAdditional;call Rev_TFAR_fnc_getLwAlt;";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_T102E_setAdditional;call Rev_TFAR_fnc_getLwAlt;}";
		};
		class ChannelDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_t102e_dial_1_ca.paa";
			x = "(8 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(3 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.6 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4.6 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_T102E_ChannelDial', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class ChannelDialButton: _INVISIBLE_BUTTON
		{
			x = "(8 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(3 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.6 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4.6 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_T102E_State', [false,false,false]])) call VN_fnc_T102E_setChannel";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_T102E_setChannel }";
		};
		class VolumeDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_t102e_dial_1_ca.paa";
			x = "(-0.7 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(4 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.6 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4.6 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_T102E_VolumeDial', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class VolumeDialButton: _INVISIBLE_BUTTON
		{
			x = "(-0.7 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(4 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.6 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4.6 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_T102E_State', [false,false,false]])) call VN_fnc_T102E_setVolume";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_T102E_setVolume }";
		};
		class StereoDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_t102e_dial_1_ca.paa";
			x = "(35 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(4.5 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.7 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4.7 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_T102E_StereoDial', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class StereoDialButton: _INVISIBLE_BUTTON
		{
			x = "(35 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(4.5 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.7 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4.7 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_T102E_State', [false,false,false]])) call VN_fnc_T102E_setStereo";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_T102E_setStereo }";
		};
		class TuneMHzDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_T102E_dial_2_ca.paa";
			x = "(14.5 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(15 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(7 * (((getResolution select 4) min 1.2) / 40))";
			h = "(7 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_T102E_MHzKnob', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class TuneMHzDialButton: _INVISIBLE_BUTTON
		{
			x = "(14.5 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(15 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(7 * (((getResolution select 4) min 1.2) / 40))";
			h = "(7 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_T102E_State', [false,false,false]])) call VN_fnc_T102E_setMHz;private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_T102E_setMHz;private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;}";
			tooltip = "Increments by 1 the MHz. By 5 if you maintain <CTRL>, by 10 if you maintain <SHIFT>, and by 15 if you maintain <CTRL+SHIFT>";
		};
		class TuneKHzDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_T102E_dial_2_ca.paa";
			x = "(34.5 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(19 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(7 * (((getResolution select 4) min 1.2) / 40))";
			h = "(7 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_T102E_KHzKnob', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class TuneKHzDialButton: TuneMHzDialButton
		{
			x = "(34.5 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(19 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(7 * (((getResolution select 4) min 1.2) / 40))";
			h = "(7 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_T102E_State', [false,false,false]])) call VN_fnc_T102E_setKHz;private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_T102E_setKHz;private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;}";
			tooltip = "";
		};
		class FrequencyDisplay: vn_RscText
		{
			x = "(15.7 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(1.5 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(7.3 * (((getResolution select 4) min 1.2) / 40))";
			h = "(1.3 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			text = "00.00";
			style = 2;
			sizeEx = "(((((getResolution select 4) min 1.2) / 1.2) / 25) * 1)";
			font = "EtelkaMonospacePro";
			colorText[] = {1,1,1,0.8};
			onLoad = "uiNamespace setVariable ['#VN_Radio_T102E_FrequencyDisplay', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.35,0.35,0.35,1]};";
		};
		class Rev_background: RscPicture
		{
			idc=8000;
			x = REV_102NOTE_X;
			y = REV_102NOTE_Y;
			w = REV_102NOTE_W;
			h = REV_102NOTE_H;
			text="\Reeveli_TFAR_SOGPF_Scribbles\102E\Rev_T102E_4.paa";
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_102E',false]);if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};		
		class Rev_slot_1: RscText
		{
			text = "1";
			colorText[] = {0,0,0,1};
			font = "Caveat";
			style = 2; //ST_CENTER
			shadow = 0;
			sizeEx = "(((((getResolution select 4) min 1.2) / 1.2) / 25) * 1.6)";
			x = REV_102NOTE_X + 0.07 * REV_102NOTE_W;
			y = REV_102NOTE_Y + 0.15 * REV_102NOTE_H;
			w = 0.09 * REV_102NOTE_W;
			h = 0.08 * REV_102NOTE_H;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_102E',false]);";
		};		
		class Rev_slot_2: Rev_slot_1
		{
			text = "2";
			y = REV_102NOTE_Y + 0.245 * REV_102NOTE_H;
		};	
		class Rev_slot_3: Rev_slot_1
		{
			text = "3";
			y = REV_102NOTE_Y + 0.335 * REV_102NOTE_H;
		};	
		class Rev_slot_4: Rev_slot_1
		{
			text = "4";
			y = REV_102NOTE_Y + 0.425 * REV_102NOTE_H;
		};	
		class Rev_slot_5: Rev_slot_1
		{
			text = "5";
			y = REV_102NOTE_Y + 0.515 * REV_102NOTE_H;
		};	
		class Rev_slot_6: Rev_slot_1
		{
			text = "6";
			y = REV_102NOTE_Y + 0.61 * REV_102NOTE_H;
		};	
		class Rev_slot_7: Rev_slot_1
		{
			text = "7";
			y = REV_102NOTE_Y + 0.7 * REV_102NOTE_H;
		};	
		class Rev_slot_8: Rev_slot_1
		{
			text = "8";
			y = REV_102NOTE_Y + 0.79 * REV_102NOTE_H;
		};
		class Rev_freq_1: Rev_slot_1
		{
			idc=8001;
			text = "";
			x = REV_102NOTE_X + 0.18 * REV_102NOTE_W;
			w = 0.27 * REV_102NOTE_W;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_102E',false]); [1,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_freq_2: Rev_freq_1
		{
			idc=8002;
			y = REV_102NOTE_Y + 0.245 * REV_102NOTE_H;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_102E',false]); [2,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_freq_3: Rev_freq_1
		{
			idc=8003;
			y = REV_102NOTE_Y + 0.335 * REV_102NOTE_H;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_102E',false]); [3,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_freq_4: Rev_freq_1
		{
			idc=8004;
			y = REV_102NOTE_Y + 0.425 * REV_102NOTE_H;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_102E',false]); [4,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_freq_5: Rev_freq_1
		{
			idc=8005;
			y = REV_102NOTE_Y + 0.515 * REV_102NOTE_H;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_102E',false]); [5,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_freq_6: Rev_freq_1
		{
			idc=8006;
			y = REV_102NOTE_Y + 0.61 * REV_102NOTE_H;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_102E',false]); [6,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_freq_7: Rev_freq_1
		{
			idc=8007;
			y = REV_102NOTE_Y + 0.7 * REV_102NOTE_H;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_102E',false]); [7,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_freq_8: Rev_freq_1
		{
			idc=8008;
			y = REV_102NOTE_Y + 0.79 * REV_102NOTE_H;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_102E',false]); [8,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_desc_1: RscEdit
		{
			idc = 8009;
			text = "";
			font = "Caveat";
			sizeEx = "(((((getResolution select 4) min 1.2) / 1.2) / 25) * 1.4)";
			colorText[] = {0,0,0,1};
			shadow = 0;
			style = 512;
			x = REV_102NOTE_X + 0.47 * REV_102NOTE_W;
			y = REV_102NOTE_Y + 0.15 * REV_102NOTE_H;
			w = 0.45 * REV_102NOTE_W;
			h = 0.08 * REV_102NOTE_H;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_102E',false]);[TF_lr_dialog_radio # 0, 1, _control] call Rev_TFAR_fnc_loadScribble;";
		};
		class Rev_desc_2: Rev_desc_1
		{
			idc = 8010;
			y = REV_102NOTE_Y + 0.245 * REV_102NOTE_H;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_102E',false]);[TF_lr_dialog_radio # 0, 2, _control] call Rev_TFAR_fnc_loadScribble;";
		};
		class Rev_desc_3: Rev_desc_1
		{
			idc = 8011;
			y = REV_102NOTE_Y + 0.335 * REV_102NOTE_H;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_102E',false]);[TF_lr_dialog_radio # 0, 3, _control] call Rev_TFAR_fnc_loadScribble;";
		};
		class Rev_desc_4: Rev_desc_1
		{
			idc = 8012;
			y = REV_102NOTE_Y + 0.425 * REV_102NOTE_H;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_102E',false]);[TF_lr_dialog_radio # 0, 4, _control] call Rev_TFAR_fnc_loadScribble;";
		};
		class Rev_desc_5: Rev_desc_1
		{
			idc = 8013;
			y = REV_102NOTE_Y + 0.515 * REV_102NOTE_H;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_102E',false]);[TF_lr_dialog_radio # 0, 5, _control] call Rev_TFAR_fnc_loadScribble;";
		};
		class Rev_desc_6: Rev_desc_1
		{
			idc = 8014;
			y = REV_102NOTE_Y + 0.61 * REV_102NOTE_H;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_102E',false]);[TF_lr_dialog_radio # 0, 6, _control] call Rev_TFAR_fnc_loadScribble;";
		};
		class Rev_desc_7: Rev_desc_1
		{
			idc = 8015;
			y = REV_102NOTE_Y + 0.7 * REV_102NOTE_H;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_102E',false]);[TF_lr_dialog_radio # 0, 7, _control] call Rev_TFAR_fnc_loadScribble;";
		};
		class Rev_desc_8: Rev_desc_1
		{
			idc = 8016;
			y = REV_102NOTE_Y + 0.79 * REV_102NOTE_H;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_102E',false]);[TF_lr_dialog_radio # 0, 8, _control] call Rev_TFAR_fnc_loadScribble;";
		};
	};
};