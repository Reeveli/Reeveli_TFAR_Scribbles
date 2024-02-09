/*
 * Author: Reeveli
 * Part of Reeveli's TFAR SOG:PF Radio scribbles.
 * UI for AN/VRC-12.
*/

class VN_RadioDialog_VRC12
{
	idd = 10001;
	onLoad = "_this call VN_fnc_VRC12_onLoad;call Rev_TFAR_fnc_getLwAlt;";
	onUnload = "if (call VN_fnc_TFAR_isOldVersion) then { ['OnRadioOpen', player, [TF_lr_dialog_radio, true, 'VN_RadioDialog_VRC12', false]] call TFAR_fnc_fireEventHandlers; } else { ['OnRadioOpen', [player, TF_lr_dialog_radio, true, 'VN_RadioDialog_VRC12', false]] call TFAR_fnc_fireEventHandlers; };[TF_lr_dialog_radio # 0, [ctrlText 8009,ctrlText 8010,ctrlText 8011,ctrlText 8012,ctrlText 8013,ctrlText 8014,ctrlText 8015,ctrlText 8016]] call Rev_TFAR_fnc_saveScribble;";
	onMouseButtonDown = "uiNamespace setVariable ['@VN_RadioDialog_VRC12_State', _this select [4,3]]";
	onMouseButtonUp = "uiNamespace setVariable ['@VN_RadioDialog_VRC12_State', _this select [4,3]]";
	onKeyDown = "call VN_fnc_VRC12_onUpdate";
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
			text = "\vn\ui_f_vietnam\ui\radios\vn_vrc12_radio_ca.paa";
			x = "0.5 - (62 * (((getResolution select 4) min 1.2) / 40)) / 2";
			y = "0.5 - ((34 * (((getResolution select 4) min 1.2) / 40)) * (4 / 3)) / 2";
			w = "(62 * (((getResolution select 4) min 1.2) / 40))";
			h = "(34 * (((getResolution select 4) min 1.2) / 40)) * (4 / 3)";
			onLoad = "params ['_control','_config']; if (sunOrMoon < 1) then {_control ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class AudioDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_vrc12_dial_3_marked_ca.paa";
			x = "(24.7 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(-1 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.5 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4.5 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_VRC12_AudioDial', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class AudioDialButton: _INVISIBLE_BUTTON
		{
			x = "(24.7 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(-1 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.5 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4.5 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_VRC12_State', [false,false,false]])) call VN_fnc_VRC12_setAudio";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_VRC12_setAudio }";
		};
		class AdditionalDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_vrc12_dial_3_marked_ca.paa";
			x = "(15.8 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(-0.3 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(3.2 * (((getResolution select 4) min 1.2) / 40))";
			h = "(3.2 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_VRC12_AdditionalDial', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class AdditionalDialButton: _INVISIBLE_BUTTON
		{
			x = "(15.8 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(-0.3 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(3.2 * (((getResolution select 4) min 1.2) / 40))";
			h = "(3.2 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_VRC12_State', [false,false,false]])) call VN_fnc_VRC12_setAdditional;call Rev_TFAR_fnc_getLwAlt;";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_VRC12_setAdditional; call Rev_TFAR_fnc_getLwAlt;}";
		};
		class ChannelDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_vrc12_dial_3_marked_ca.paa";
			x = "(-2.9 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(13 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.6 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4.6 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_VRC12_ChannelDial', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class ChannelDialButton: _INVISIBLE_BUTTON
		{
			x = "(-2.9 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(13 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.6 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4.6 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_VRC12_State', [false,false,false]])) call VN_fnc_VRC12_setChannel";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_VRC12_setChannel }";
		};
		class VolumeDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_vrc12_dial_3_marked_ca.paa";
			x = "(4.1 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(13.6 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(3.6 * (((getResolution select 4) min 1.2) / 40))";
			h = "(3.6 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_VRC12_VolumeDial', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class VolumeDialButton: _INVISIBLE_BUTTON
		{
			x = "(4.1 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(13.6 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(3.6 * (((getResolution select 4) min 1.2) / 40))";
			h = "(3.6 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_VRC12_State', [false,false,false]])) call VN_fnc_VRC12_setVolume";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_VRC12_setVolume }";
		};
		class StereoDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_vrc12_dial_3_marked_ca.paa";
			x = "(14 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(4.1 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.7 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4.7 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_VRC12_StereoDial', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class StereoDialButton: _INVISIBLE_BUTTON
		{
			x = "(14 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(4.1 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.7 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4.7 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_VRC12_State', [false,false,false]])) call VN_fnc_VRC12_setStereo";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_VRC12_setStereo }";
		};
		class BandDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_vrc12_dial_1_marked_ca.paa";
			x = "(-5.3 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(-2.4 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(6 * (((getResolution select 4) min 1.2) / 40))";
			h = "(6 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "(_this#0) ctrlSetAngle [284, 0.5, 0.5, true]; uiNamespace setVariable ['#VN_Radio_VRC12_BandDial', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class TuneMHzDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_vrc12_dial_2_ca.paa";
			x = "(-5 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(3.6 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(6.5 * (((getResolution select 4) min 1.2) / 40))";
			h = "(6.5 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_VRC12_MHzKnob', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class TuneMHzDialButton: _INVISIBLE_BUTTON
		{
			x = "(-5 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(3.6 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(6.5 * (((getResolution select 4) min 1.2) / 40))";
			h = "(6.5 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_VRC12_State', [false,false,false]])) call VN_fnc_VRC12_setMHz;private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_VRC12_setMHz;private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;}";
			tooltip = "Increments by 1 the MHz. By 5 if you maintain <CTRL>, by 10 if you maintain <SHIFT>, and by 15 if you maintain <CTRL+SHIFT>";
		};
		class TuneKHzDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_vrc12_dial_3_ca.paa";
			x = "(1.5 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(3.9 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.7 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4.7 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_VRC12_KHzKnob', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class TuneKHzDialButton: TuneMHzDialButton
		{
			x = "(1.5 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(3.9 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.7 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4.7 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_VRC12_State', [false,false,false]])) call VN_fnc_VRC12_setKHz;private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_VRC12_setKHz;private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;}";
			tooltip = "";
		};
		class FrequencyDisplay: vn_RscText
		{
			x = "(-8.2 * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(6.3 * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(3.3 * (((getResolution select 4) min 1.2) / 40))";
			h = "(1.3 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			text = "00.00";
			style = 1;
			sizeEx = "(((((getResolution select 4) min 1.2) / 1.2) / 25) * 0.8)";
			font = "EtelkaMonospacePro";
			colorText[] = {1,1,1,0.8};
			onLoad = "uiNamespace setVariable ['#VN_Radio_VRC12_FrequencyDisplay', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.35,0.35,0.35,1]};";
		};
		class Rev_background: RscPicture
		{
			idc=8000;
			x = TFAR_notebook_X + TFAR_notebook_W * 0.75;
			y = TFAR_notebook_Y;
			w = TFAR_notebook_W;
			h = TFAR_notebook_H;
			text="\Reeveli_TFAR_SOGPF_Scribbles\Map_case\Rev_mapCase_base_1.paa";
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_VRC12',false]);if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class Rev_text_slot: vn_RscText
		{
			text = "Ch";
			colorText[] = {0.38,0.44,0.61,0.95};
			font = "Caveat";
			style = 2;
			sizeEx = TFAR_notebook_H * 0.03;
			x = TFAR_notebook_X + TFAR_notebook_W * (0.75 + 0.335);
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.29;
			w = TFAR_notebook_W * 0.04;
			h = TFAR_notebook_H * 0.03;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_VRC12',false]);if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_ch_1: RscText
		{
			text = "1.";
			font = "Caveat";
			sizeEx = TFAR_notebook_H * 0.03;	
			colorText[] = {0.38,0.44,0.61,0.95};
			shadow = 0;
			x = TFAR_notebook_X + TFAR_notebook_W * (0.75 + 0.335);
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.337;
			w = TFAR_notebook_W * 0.04;
			h = TFAR_notebook_H * 0.03;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_VRC12',false]);if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_ch_2: Rev_ch_1
		{
			text = "2.";
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.382;
		};
		class Rev_ch_3: Rev_ch_1
		{
			text = "3.";
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.427;
		};
		class Rev_ch_4: Rev_ch_1
		{
			text = "4.";
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.472;
		};
		class Rev_ch_5: Rev_ch_1
		{
			text = "5.";
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.512;
		};
		class Rev_ch_6: Rev_ch_1
		{
			text = "6.";
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.557;
		};
		class Rev_ch_7: Rev_ch_1
		{
			text = "7.";
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.602;
		};
		class Rev_ch_8: Rev_ch_1
		{
			text = "8.";
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.647;
		};
		class Rev_text_Mhz: Rev_text_slot
		{
			text = "MHz";
			x = TFAR_notebook_X + TFAR_notebook_W * (0.75 + 0.38);
			w = TFAR_notebook_W * 0.08;
		};
		class Rev_fr_1: Rev_ch_1
		{
			idc = 8001;
			text = "";
			x = TFAR_notebook_X + TFAR_notebook_W * (0.75 + 0.38);
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.337;
			w = TFAR_notebook_W * 0.08;
			h = TFAR_notebook_H * 0.03;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_VRC12',false]); [1,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_2: Rev_fr_1
		{
			idc = 8002;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.382;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_VRC12',false]); [2,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_3: Rev_fr_1
		{
			idc = 8003;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.427;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_VRC12',false]); [3,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_4: Rev_fr_1
		{
			idc = 8004;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.472;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_VRC12',false]); [4,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_5: Rev_fr_1
		{
			idc = 8005;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.512;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_VRC12',false]); [5,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_6: Rev_fr_1
		{
			idc = 8006;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.557;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_VRC12',false]); [6,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_7: Rev_fr_1
		{
			idc = 8007;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.602;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_VRC12',false]); [7,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_8: Rev_fr_1
		{
			idc = 8008;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.647;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_VRC12',false]); [8,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_text_notes: Rev_text_slot
		{
			text = "Notes";
			x = TFAR_notebook_X + TFAR_notebook_W * (0.75 + 0.465);
			w = TFAR_notebook_W * 0.15;
		};
		class Rev_desc_1: RscEdit
		{
			idc = 8009;
			text = "";
			font = "Caveat";	
			sizeEx = TFAR_notebook_H * 0.03;
			colorText[] = {0.38,0.44,0.61,0.95};
			shadow = 0;
			style = 512;
			x = TFAR_notebook_X + TFAR_notebook_W * (0.75 + 0.465);
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.337;
			w = TFAR_notebook_W * 0.15;
			h = TFAR_notebook_H * 0.03;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_VRC12',false]);[TF_lr_dialog_radio # 0, 1, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_2: Rev_desc_1
		{
			idc = 8010;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.382;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_VRC12',false]);[TF_lr_dialog_radio # 0, 2, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_3: Rev_desc_1
		{
			idc = 8011;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.427;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_VRC12',false]);[TF_lr_dialog_radio # 0, 3, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_4: Rev_desc_1
		{
			idc = 8012;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.472;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_VRC12',false]);[TF_lr_dialog_radio # 0, 4, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_5: Rev_desc_1
		{
			idc = 8013;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.512;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_VRC12',false]);[TF_lr_dialog_radio # 0, 5, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_6: Rev_desc_1
		{
			idc = 8014;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.557;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_VRC12',false]);[TF_lr_dialog_radio # 0, 6, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_7: Rev_desc_1
		{
			idc = 8015;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.602;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_VRC12',false]);[TF_lr_dialog_radio # 0, 7, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_8: Rev_desc_1
		{
			idc = 8016;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.647;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_VRC12',false]);[TF_lr_dialog_radio # 0, 8, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_text_alt: Rev_text_slot
		{
			text = "Alt";
			x = TFAR_notebook_X + TFAR_notebook_W * (0.75 + 0.624);
			w = TFAR_notebook_W * 0.04;
		};
		class Rev_alt_1: Rev_fr_1
		{
			idc=8020;
			text = "";
			font = "Caveat";
			sizeEx = TFAR_notebook_H * 0.03;
			colorText[] = {0.38,0.44,0.61,0.95};
			shadow = 0;
			x = TFAR_notebook_X + TFAR_notebook_W * (0.75 + 0.624);
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.337;
			w = TFAR_notebook_W * 0.04;
			h = TFAR_notebook_H * 0.03;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_VRC12',false]);";
		};
		class Rev_alt_2: Rev_alt_1
		{
			idc=8021;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.382;
		};
		class Rev_alt_3: Rev_alt_1
		{
			idc=8022;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.427;
		};
		class Rev_alt_4: Rev_alt_1
		{
			idc=8023;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.472;
		};
		class Rev_alt_5: Rev_alt_1
		{
			idc=8024;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.512;
		};
		class Rev_alt_6: Rev_alt_1
		{
			idc=8025;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.557;
		};
		class Rev_alt_7: Rev_alt_1
		{
			idc=8026;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.602;
		};
		class Rev_alt_8: Rev_alt_1
		{
			idc=8027;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.647;
		};
		class Rev_frontGround: Rev_background
		{
			idc=8050;
			text="\Reeveli_TFAR_SOGPF_Scribbles\Map_case\Rev_mapCase_front_4.paa";
		};
	};
};