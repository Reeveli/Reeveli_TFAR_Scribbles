/*
 * Author: Reeveli
 * Part of Reeveli's TFAR SOG:PF Radio scribbles.
 * UI for Type 884.
*/

#define REV_TFAR_LEATHER_X  			TFAR_notebook_X + TFAR_notebook_W * 0.1
#define REV_TFAR_LEATHER_Y  			TFAR_notebook_Y + TFAR_notebook_H * 0.1

class VN_RadioDialog_T884
{
	idd = 10001;
	onLoad = "_this call VN_fnc_T884_onLoad;call Rev_TFAR_fnc_getLwAlt;";
	onUnload = "if (call VN_fnc_TFAR_isOldVersion) then { ['OnRadioOpen', player, [TF_lr_dialog_radio, true, 'VN_RadioDialog_T884', false]] call TFAR_fnc_fireEventHandlers; } else { ['OnRadioOpen', [player, TF_lr_dialog_radio, true, 'VN_RadioDialog_T884', false]] call TFAR_fnc_fireEventHandlers; };[TF_lr_dialog_radio # 0, [ctrlText 8009,ctrlText 8010,ctrlText 8011,ctrlText 8012,ctrlText 8013,ctrlText 8014,ctrlText 8015,ctrlText 8016]] call Rev_TFAR_fnc_saveScribble;";
	onMouseButtonDown = "uiNamespace setVariable ['@VN_RadioDialog_T884_State', _this select [4,3]]";
	onMouseButtonUp = "uiNamespace setVariable ['@VN_RadioDialog_T884_State', _this select [4,3]]";
	onKeyDown = "call VN_fnc_T884_onUpdate";
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
			text = "\vn\ui_f_vietnam\ui\radios\vn_t884_radio_ca.paa";
			x = "0.5 - (62 * (((getResolution select 4) min 1.2) / 40)) / 2";
			y = "0.5 - ((28 * (((getResolution select 4) min 1.2) / 40)) * (4 / 3)) / 2";
			w = "(62 * (((getResolution select 4) min 1.2) / 40))";
			h = "(28 * (((getResolution select 4) min 1.2) / 40)) * (4 / 3)";
			onLoad = "params ['_control','_config']; if (sunOrMoon < 1) then {_control ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class AudioSwitch: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\on_ca.paa";
			x = "(11.6 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(2.3 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(1.4 * (((getResolution select 4) min 1.2) / 40))";
			h = "(1.4 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_T884_AudioSwitch', (_this#0)];call Rev_TFAR_SOGPF_fnc_T884_switchAudio;";
		};
		class AudioSwitchButton: _INVISIBLE_BUTTON
		{
			x = "(11.6 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(2.3 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(1.4 * (((getResolution select 4) min 1.2) / 40))";
			h = "(1.4 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_T884_State', [false,false,false]])) call VN_fnc_T884_setAudio;call Rev_TFAR_SOGPF_fnc_T884_switchAudio;";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_T884_setAudio;call Rev_TFAR_SOGPF_fnc_T884_switchAudio;}";
		};
		class AdditionalSwitch: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\off_ca.paa";
			x = "(8.5 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(2.3 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(1.4 * (((getResolution select 4) min 1.2) / 40))";
			h = "(1.4 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_T884_AdditionalSwitch', (_this#0)];call Rev_TFAR_SOGPF_fnc_T884_switchAlt;";
		};
		class AdditionalSwitchButton: _INVISIBLE_BUTTON
		{
			x = "(8.5 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(2.3 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(1.4 * (((getResolution select 4) min 1.2) / 40))";
			h = "(1.4 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_T884_State', [false,false,false]])) call VN_fnc_T884_setAdditional;call Rev_TFAR_fnc_getLwAlt;call Rev_TFAR_SOGPF_fnc_T884_switchAlt";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_T884_setAdditional; call Rev_TFAR_fnc_getLwAlt;call Rev_TFAR_SOGPF_fnc_T884_switchAlt}";
		};
		class ChannelDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_t884_dial_3_ca.paa";
			x = "(-4.6 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(14 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(7 * (((getResolution select 4) min 1.2) / 40))";
			h = "(7 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_T884_ChannelDial', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class ChannelDialButton: _INVISIBLE_BUTTON
		{
			x = "(-4.6 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(14 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(7 * (((getResolution select 4) min 1.2) / 40))";
			h = "(7 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_T884_State', [false,false,false]])) call VN_fnc_T884_setChannel";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_T884_setChannel }";
		};
		class VolumeDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_t884_dial_3_ca.paa";
			x = "(-5 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(3.3 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(7 * (((getResolution select 4) min 1.2) / 40))";
			h = "(7 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_T884_VolumeDial', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class VolumeDialButton: _INVISIBLE_BUTTON
		{
			x = "(-5 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(3.3 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(7 * (((getResolution select 4) min 1.2) / 40))";
			h = "(7 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_T884_State', [false,false,false]])) call VN_fnc_T884_setVolume";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_T884_setVolume }";
		};
		class StereoSwitch: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\blr_button_ca.paa";
			x = "(29 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(2.5 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(1 * (((getResolution select 4) min 1.2) / 40))";
			h = "(1 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_T884_StereoSwitch', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class StereoSwitchButton: _INVISIBLE_BUTTON
		{
			x = "(28.2 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(2.5 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(2 * (((getResolution select 4) min 1.2) / 40))";
			h = "(2 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_T884_State', [false,false,false]])) call VN_fnc_T884_setStereo";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_T884_setStereo }";
		};
		class TuneMHzDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_t884_dial_1_ca.paa";
			x = "(25 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(5.8 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(9.5 * (((getResolution select 4) min 1.2) / 40))";
			h = "(9.5 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_T884_MHzKnob', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class TuneMHzDialButton: _INVISIBLE_BUTTON
		{
			x = "(25 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(5.8 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(9.5 * (((getResolution select 4) min 1.2) / 40))";
			h = "(9.5 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_T884_State', [false,false,false]])) call VN_fnc_T884_setMHz;private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_T884_setMHz; private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;}";
			tooltip = "Increments by 1 the MHz. By 5 if you maintain <CTRL>, by 10 if you maintain <SHIFT>, and by 15 if you maintain <CTRL+SHIFT>";
		};
		class TuneKHzDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_t884_dial_2_ca";
			x = "(29 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(16.7 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_T884_KHzKnob', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class TuneKHzDialButton: TuneMHzDialButton
		{
			x = "(29 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(16.7 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_T884_State', [false,false,false]])) call VN_fnc_T884_setKHz;private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_T884_setKHz; private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;}";
			tooltip = "";
		};
		class FrequencyDisplay: vn_RscText
		{
			x = "(12.4 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(11.2 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(3.3 * (((getResolution select 4) min 1.2) / 40))";
			h = "(1.3 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			text = "00.00";
			style = 1;
			sizeEx = "(((((getResolution select 4) min 1.2) / 1.2) / 25) * 0.8)";
			font = "EtelkaMonospacePro";
			colorText[] = {"98 / 255","116 / 255","142 / 255",1};
			onLoad = "uiNamespace setVariable ['#VN_Radio_T884_FrequencyDisplay', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.35,0.35,0.35,1]};";
		};
		class Rev_background: RscPicture
		{
			idc=8000;
			x = REV_TFAR_LEATHER_X + TFAR_notebook_W * 0.85;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.1;
			w = TFAR_notebook_W;
			h = TFAR_notebook_H;
			text="images\leather_case_3.paa";
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_884',false]);if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class Rev_text_slot: vn_RscText
		{
			text = "Kênh";
			colorText[] = {0,0,0,1};
			font = "Caveat";
			style = 2;
			sizeEx = TFAR_notebook_H * 0.03;
			x = REV_TFAR_LEATHER_X + TFAR_notebook_W * (0.85 + 0.335);
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.41; //0.29
			w = TFAR_notebook_W * 0.04;
			h = TFAR_notebook_H * 0.03;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_884',false]);if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_ch_1: RscText
		{
			text = "1.";
			font = "Caveat";
			sizeEx = TFAR_notebook_H * 0.03;	
			colorText[] = {0,0,0,1};
			shadow = 0;
			x = REV_TFAR_LEATHER_X + TFAR_notebook_W * (0.85 + 0.335);
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.457;
			w = TFAR_notebook_W * 0.04;
			h = TFAR_notebook_H * 0.03;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_884',false]);if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_ch_2: Rev_ch_1
		{
			text = "2.";
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.502;
		};
		class Rev_ch_3: Rev_ch_1
		{
			text = "3.";
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.547;
		};
		class Rev_ch_4: Rev_ch_1
		{
			text = "4.";
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.592;
		};
		class Rev_ch_5: Rev_ch_1
		{
			text = "5.";
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.632;
		};
		class Rev_ch_6: Rev_ch_1
		{
			text = "6.";
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.677;
		};
		class Rev_ch_7: Rev_ch_1
		{
			text = "7.";
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.722;
		};
		class Rev_ch_8: Rev_ch_1
		{
			text = "8.";
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.767;
		};
		class Rev_text_Mhz: Rev_text_slot
		{
			text = "Mhc";
			x = REV_TFAR_LEATHER_X + TFAR_notebook_W * (0.85 + 0.38);
			w = TFAR_notebook_W * 0.08;
		};
		class Rev_fr_1: Rev_ch_1
		{
			idc = 8001;
			text = "";
			x = REV_TFAR_LEATHER_X + TFAR_notebook_W * (0.85 + 0.38);
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.457;
			w = TFAR_notebook_W * 0.08;
			h = TFAR_notebook_H * 0.03;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_884',false]); [1,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_2: Rev_fr_1
		{
			idc = 8002;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.502;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_884',false]); [2,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_3: Rev_fr_1
		{
			idc = 8003;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.547;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_884',false]); [3,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_4: Rev_fr_1
		{
			idc = 8004;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.592;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_884',false]); [4,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_5: Rev_fr_1
		{
			idc = 8005;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.632;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_884',false]); [5,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_6: Rev_fr_1
		{
			idc = 8006;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.677;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_884',false]); [6,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_7: Rev_fr_1
		{
			idc = 8007;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.722;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_884',false]); [7,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_8: Rev_fr_1
		{
			idc = 8008;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.767;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_884',false]); [8,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_text_notes: Rev_text_slot
		{
			text = "Nho*";
			x = REV_TFAR_LEATHER_X + TFAR_notebook_W * (0.85 + 0.465);
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.413; //0.41
			w = TFAR_notebook_W * 0.15;
		};
		class Rev_desc_1: RscEdit
		{
			idc = 8009;
			text = "";
			font = "Caveat";	
			sizeEx = TFAR_notebook_H * 0.03;
			colorText[] = {0,0,0,1};
			shadow = 0;
			style = 512;
			x = REV_TFAR_LEATHER_X + TFAR_notebook_W * (0.85 + 0.465);
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.457;
			w = TFAR_notebook_W * 0.15;
			h = TFAR_notebook_H * 0.03;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_884',false]);[TF_lr_dialog_radio # 0, 1, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_2: Rev_desc_1
		{
			idc = 8010;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.502;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_884',false]);[TF_lr_dialog_radio # 0, 2, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_3: Rev_desc_1
		{
			idc = 8011;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.547;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_884',false]);[TF_lr_dialog_radio # 0, 3, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_4: Rev_desc_1
		{
			idc = 8012;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.592;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_884',false]);[TF_lr_dialog_radio # 0, 4, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_5: Rev_desc_1
		{
			idc = 8013;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.632;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_884',false]);[TF_lr_dialog_radio # 0, 5, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_6: Rev_desc_1
		{
			idc = 8014;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.677;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_884',false]);[TF_lr_dialog_radio # 0, 6, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_7: Rev_desc_1
		{
			idc = 8015;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.722;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_884',false]);[TF_lr_dialog_radio # 0, 7, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_8: Rev_desc_1
		{
			idc = 8016;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.767;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_884',false]);[TF_lr_dialog_radio # 0, 8, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_text_alt: Rev_text_slot
		{
			text = "Thêm";
			style = 0; //2
			x = REV_TFAR_LEATHER_X + TFAR_notebook_W * (0.85 + 0.612); //(0.85 + 0.624)
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.418; //0.41
			w = TFAR_notebook_W * 0.06;
		};
		class Rev_alt_1: Rev_fr_1
		{
			idc=8020;
			text = "";
			font = "Caveat";
			sizeEx = TFAR_notebook_H * 0.03;
			colorText[] = {0,0,0,1};
			shadow = 0;
			x = REV_TFAR_LEATHER_X + TFAR_notebook_W * (0.85 + 0.624);
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.457;
			w = TFAR_notebook_W * 0.04;
			h = TFAR_notebook_H * 0.03;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_884',false]);";
		};
		class Rev_alt_2: Rev_alt_1
		{
			idc=8021;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.502;
		};
		class Rev_alt_3: Rev_alt_1
		{
			idc=8022;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.547;
		};
		class Rev_alt_4: Rev_alt_1
		{
			idc=8023;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.592;
		};
		class Rev_alt_5: Rev_alt_1
		{
			idc=8024;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.632;
		};
		class Rev_alt_6: Rev_alt_1
		{
			idc=8025;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.677;
		};
		class Rev_alt_7: Rev_alt_1
		{
			idc=8026;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.722;
		};
		class Rev_alt_8: Rev_alt_1
		{
			idc=8027;
			y = REV_TFAR_LEATHER_Y + TFAR_notebook_H * 0.767;
		};
	};
};