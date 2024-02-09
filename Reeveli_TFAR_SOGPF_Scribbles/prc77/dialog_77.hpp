/*
 * Author: Reeveli
 * Part of Reeveli's TFAR SOG:PF Radio scribbles.
 * UI for PRC-77.
 1.2
	Fixed scribble edit field night time text color
 1.1
	Code for night time
	Added missing visibility checks for channel text controls
*/

class VN_RadioDialog_PRC77
{
	idd = 10000;
	onLoad = "_this call VN_fnc_PRC77_onLoad;call Rev_TFAR_fnc_getLwAlt;";
	onUnload = "if (call VN_fnc_TFAR_isOldVersion) then { ['OnRadioOpen', player, [TF_lr_dialog_radio, true, 'VN_RadioDialog_PRC77', false]] call TFAR_fnc_fireEventHandlers; } else { ['OnRadioOpen', [player, TF_lr_dialog_radio, true, 'VN_RadioDialog_PRC77', false]] call TFAR_fnc_fireEventHandlers; };[TF_lr_dialog_radio # 0, [ctrlText 8009,ctrlText 8010,ctrlText 8011,ctrlText 8012,ctrlText 8013,ctrlText 8014,ctrlText 8015,ctrlText 8016]] call Rev_TFAR_fnc_saveScribble";
	onMouseButtonDown = "uiNamespace setVariable ['@VN_RadioDialog_PRC77_State', _this select [4,3]]";
	onMouseButtonUp = "uiNamespace setVariable ['@VN_RadioDialog_PRC77_State', _this select [4,3]]";
	onKeyDown = "call VN_fnc_PRC77_onUpdate";
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
			x = 0;
			y = 0;
			w = 0;
			h = 0;
		};
		class Radio: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\vn_radio_prc77_ca.paa";
			x = "(((safeZoneW / 2) + safeZoneX) - ((safeZoneW * (3 / 4)) / 2))";
			y = "(((safeZoneH / 2) + safeZoneY) - (((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) / 2))";
			w = "(safeZoneW * (3 / 4))";
			h = "((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3)";
			onLoad = "params ['_control','_config']; if (sunOrMoon < 1) then {_control ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class AudioSwitch: _INVISIBLE_BUTTON
		{
			x = "((((safeZoneW / 2) + safeZoneX) - ((safeZoneW * (3 / 4)) / 2)) + (safeZoneW * (3 / 4)) * (929 / (1711)))";
			y = "((((safeZoneH / 2) + safeZoneY) - (((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) / 2)) + ((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (131 / (855)))";
			w = "((safeZoneW * (3 / 4)) * (83 / (1711)))";
			h = "(((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (83 / (855)))";
			tooltip = "Changes radio speaker mode";
			onButtonClick = "_this call VN_fnc_PRC77_setAudio";
		};
		class AdditionalSwitch: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\switch_ca.paa";
			x = "((((safeZoneW / 2) + safeZoneX) - ((safeZoneW * (3 / 4)) / 2)) + (safeZoneW * (3 / 4)) * (667 / (1711)))";
			y = "((((safeZoneH / 2) + safeZoneY) - (((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) / 2)) + ((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (119 / (855)))";
			w = "((safeZoneW * (3 / 4)) * (40 / (1711)))";
			h = "(((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (40 / (855)))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_PRC77_AdditionalSwitch', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class AdditionalSwitchButton: _INVISIBLE_BUTTON
		{
			x = "((((safeZoneW / 2) + safeZoneX) - ((safeZoneW * (3 / 4)) / 2)) + (safeZoneW * (3 / 4)) * (667 / (1711)))";
			y = "((((safeZoneH / 2) + safeZoneY) - (((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) / 2)) + ((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (119 / (855)))";
			w = "((safeZoneW * (3 / 4)) * (40 / (1711)))";
			h = "(((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (40 / (855)))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_PRC77_State', [false,false,false]])) call VN_fnc_PRC77_setAdditional;call Rev_TFAR_fnc_getLwAlt;";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_PRC77_setAdditional;call Rev_TFAR_fnc_getLwAlt;}";
		};
		class ChannelDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\dial_2_marked_ca.paa";
			x = "((((safeZoneW / 2) + safeZoneX) - ((safeZoneW * (3 / 4)) / 2)) + (safeZoneW * (3 / 4)) * (254 / (1711)))";
			y = "((((safeZoneH / 2) + safeZoneY) - (((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) / 2)) + ((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (119 / (855)))";
			w = "((safeZoneW * (3 / 4)) * (107 / (1711)))";
			h = "(((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (107 / (855)))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_PRC77_ChannelDial', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class ChannelDialButton: _INVISIBLE_BUTTON
		{
			x = "((((safeZoneW / 2) + safeZoneX) - ((safeZoneW * (3 / 4)) / 2)) + (safeZoneW * (3 / 4)) * (254 / (1711)))";
			y = "((((safeZoneH / 2) + safeZoneY) - (((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) / 2)) + ((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (119 / (855)))";
			w = "((safeZoneW * (3 / 4)) * (107 / (1711)))";
			h = "(((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (107 / (855)))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_PRC77_State', [false,false,false]])) call VN_fnc_PRC77_setChannel";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_PRC77_setChannel }";
		};
		class VolumeDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\dial_2_marked_ca.paa";
			x = "((((safeZoneW / 2) + safeZoneX) - ((safeZoneW * (3 / 4)) / 2)) + (safeZoneW * (3 / 4)) * (1026 / (1711)))";
			y = "((((safeZoneH / 2) + safeZoneY) - (((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) / 2)) + ((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (225 / (855)))";
			w = "((safeZoneW * (3 / 4)) * (107 / (1711)))";
			h = "(((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (107 / (855)))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_PRC77_VolumeDial', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class VolumeDialButton: _INVISIBLE_BUTTON
		{
			x = "((((safeZoneW / 2) + safeZoneX) - ((safeZoneW * (3 / 4)) / 2)) + (safeZoneW * (3 / 4)) * (1026 / (1711)))";
			y = "((((safeZoneH / 2) + safeZoneY) - (((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) / 2)) + ((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (225 / (855)))";
			w = "((safeZoneW * (3 / 4)) * (107 / (1711)))";
			h = "(((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (107 / (855)))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_PRC77_State', [false,false,false]])) call VN_fnc_PRC77_setVolume";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_PRC77_setVolume }";
		};
		class StereoDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\dial_3_marked_ca.paa";
			x = "((((safeZoneW / 2) + safeZoneX) - ((safeZoneW * (3 / 4)) / 2)) + (safeZoneW * (3 / 4)) * (1012 / (1711)))";
			y = "((((safeZoneH / 2) + safeZoneY) - (((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) / 2)) + ((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (369 / (855)))";
			w = "((safeZoneW * (3 / 4)) * (131 / (1711)))";
			h = "(((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (131 / (855)))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_PRC77_StereoDial', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class StereoDialButton: _INVISIBLE_BUTTON
		{
			x = "((((safeZoneW / 2) + safeZoneX) - ((safeZoneW * (3 / 4)) / 2)) + (safeZoneW * (3 / 4)) * (1012 / (1711)))";
			y = "((((safeZoneH / 2) + safeZoneY) - (((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) / 2)) + ((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (369 / (855)))";
			w = "((safeZoneW * (3 / 4)) * (131 / (1711)))";
			h = "(((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (131 / (855)))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_PRC77_State', [false,false,false]])) call VN_fnc_PRC77_setStereo";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_PRC77_setStereo }";
		};
		class BandDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\dial_3_marked_ca.paa";
			x = "((((safeZoneW / 2) + safeZoneX) - ((safeZoneW * (3 / 4)) / 2)) + (safeZoneW * (3 / 4)) * (297 / (1711)))";
			y = "((((safeZoneH / 2) + safeZoneY) - (((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) / 2)) + ((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (364 / (855)))";
			w = "((safeZoneW * (3 / 4)) * (107 / (1711)))";
			h = "(((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (107 / (855)))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_PRC77_BandDial', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class TuneMHzDial: RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\dial_1_ca.paa";
			x = "((((safeZoneW / 2) + safeZoneX) - ((safeZoneW * (3 / 4)) / 2)) + (safeZoneW * (3 / 4)) * (458 / (1711)))";
			y = "((((safeZoneH / 2) + safeZoneY) - (((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) / 2)) + ((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (264 / (855)))";
			w = "((safeZoneW * (3 / 4)) * (116 / (1711)))";
			h = "(((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (116 / (855)))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_PRC77_MHzKnob', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class TuneMHzDialButton: _INVISIBLE_BUTTON
		{
			x = "((((safeZoneW / 2) + safeZoneX) - ((safeZoneW * (3 / 4)) / 2)) + (safeZoneW * (3 / 4)) * (458 / (1711)))";
			y = "((((safeZoneH / 2) + safeZoneY) - (((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) / 2)) + ((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (264 / (855)))";
			w = "((safeZoneW * (3 / 4)) * (116 / (1711)))";
			h = "(((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (116 / (855)))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_PRC77_State', [false,false,false]])) call VN_fnc_PRC77_setMHz;private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_PRC77_setMHz; private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;}";
			tooltip = "Increments by 1 the MHz. By 5 if you maintain <CTRL>, by 10 if you maintain <SHIFT>, and by 15 if you maintain <CTRL+SHIFT>";
		};
		class TuneKHzDial: TuneMHzDial
		{
			x = "((((safeZoneW / 2) + safeZoneX) - ((safeZoneW * (3 / 4)) / 2)) + (safeZoneW * (3 / 4)) * (769 / (1711)))";
			onLoad = "uiNamespace setVariable ['#VN_Radio_PRC77_KHzKnob', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class TuneKHzDialButton: TuneMHzDialButton
		{
			x = "((((safeZoneW / 2) + safeZoneX) - ((safeZoneW * (3 / 4)) / 2)) + (safeZoneW * (3 / 4)) * (769 / (1711)))";
			onButtonClick = "([_this#0,0,0,0] + (uiNamespace getVariable ['@VN_RadioDialog_PRC77_State', [false,false,false]])) call VN_fnc_PRC77_setKHz; private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;";
			onMouseButtonDown = "if ((_this#1) isEqualTo 1) then { _this call VN_fnc_PRC77_setKHz; private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;}";
			tooltip = "";
		};
		class MHzFreq3052Band: vn_RscText
		{
			x = "((((safeZoneW / 2) + safeZoneX) - ((safeZoneW * (3 / 4)) / 2)) + (safeZoneW * (3 / 4)) * (624 / (1711)))";
			y = "((((safeZoneH / 2) + safeZoneY) - (((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) / 2)) + ((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (280 / (855)))";
			w = "((safeZoneW * (3 / 4)) * (31 / (1711)))";
			h = "(((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (31 / (855)))";
			text = "00";
			style = 1;
			font = "EtelkaMonospacePro";
			onLoad = "uiNamespace setVariable ['#VN_Radio_PRC77_MHzDisplay3052', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.35,0.35,0.35,1]};";
			sizeEX = "(((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (23.5 / (855))) - 0.008";
		};
		class MHzFreq5375Band: MHzFreq3052Band
		{
			x = "((((safeZoneW / 2) + safeZoneX) - ((safeZoneW * (3 / 4)) / 2)) + (safeZoneW * (3 / 4)) * (648 / (1711)))";
			text = "00";
			style = 0;
			onLoad = "uiNamespace setVariable ['#VN_Radio_PRC77_MHzDisplay5375', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.35,0.35,0.35,1]};";
		};
		class KHzFreq: MHzFreq5375Band
		{
			x = "((((safeZoneW / 2) + safeZoneX) - ((safeZoneW * (3 / 4)) / 2)) + (safeZoneW * (3 / 4)) * (676 / (1711)))";
			y = "((((safeZoneH / 2) + safeZoneY) - (((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) / 2)) + ((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (280 / (855)))";
			w = "((safeZoneW * (3 / 4)) * (26 / (1711)))";
			h = "(((safeZoneW * (3 / 4)) / ((1711) / (855))) * (4 / 3) * (21 / (855)))";
			text = "00";
			font = "EtelkaMonospacePro";
			onLoad = "uiNamespace setVariable ['#VN_Radio_PRC77_KHzDisplay', (_this#0)];if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.35,0.35,0.35,1]};";
		};
		class Rev_background: RscPicture
		{
			idc=8000;
			x = TFAR_notebook_X + TFAR_notebook_W * 0.75;
			y = TFAR_notebook_Y;
			w = TFAR_notebook_W;
			h = TFAR_notebook_H;
			text="\Reeveli_TFAR_SOGPF_Scribbles\Map_case\Rev_mapCase_base_1.paa";
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_77',false]);if (sunOrMoon < 1) then {_this#0 ctrlSetTextColor [0.18,0.18,0.18,1]};";
		};
		class Rev_text_slot: vn_RscText
		{
			text = "Ch.";
			colorText[] = {0.38,0.44,0.61,0.95};
			font = "Caveat";
			style = 2;
			sizeEx = TFAR_notebook_H * 0.03;
			x = TFAR_notebook_X + TFAR_notebook_W * (0.75 + 0.335);
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.29;
			w = TFAR_notebook_W * 0.04;
			h = TFAR_notebook_H * 0.03;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_77',false]);if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
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
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_77',false]);if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
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
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_77',false]); [1,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_2: Rev_fr_1
		{
			idc = 8002;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.382;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_77',false]); [2,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_3: Rev_fr_1
		{
			idc = 8003;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.427;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_77',false]); [3,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_4: Rev_fr_1
		{
			idc = 8004;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.472;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_77',false]); [4,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_5: Rev_fr_1
		{
			idc = 8005;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.512;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_77',false]); [5,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_6: Rev_fr_1
		{
			idc = 8006;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.557;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_77',false]); [6,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_7: Rev_fr_1
		{
			idc = 8007;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.602;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_77',false]); [7,_control] call Rev_TFAR_fnc_getLwFrq;";
		};
		class Rev_fr_8: Rev_fr_1
		{
			idc = 8008;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.647;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_77',false]); [8,_control] call Rev_TFAR_fnc_getLwFrq;";
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
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_77',false]);[TF_lr_dialog_radio # 0, 1, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_2: Rev_desc_1
		{
			idc = 8010;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.382;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_77',false]);[TF_lr_dialog_radio # 0, 2, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_3: Rev_desc_1
		{
			idc = 8011;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.427;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_77',false]);[TF_lr_dialog_radio # 0, 3, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_4: Rev_desc_1
		{
			idc = 8012;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.472;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_77',false]);[TF_lr_dialog_radio # 0, 4, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_5: Rev_desc_1
		{
			idc = 8013;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.512;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_77',false]);[TF_lr_dialog_radio # 0, 5, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_6: Rev_desc_1
		{
			idc = 8014;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.557;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_77',false]);[TF_lr_dialog_radio # 0, 6, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_7: Rev_desc_1
		{
			idc = 8015;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.602;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_77',false]);[TF_lr_dialog_radio # 0, 7, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_8: Rev_desc_1
		{
			idc = 8016;
			y = TFAR_notebook_Y + TFAR_notebook_H * 0.647;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_77',false]);[TF_lr_dialog_radio # 0, 8, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_text_alt: Rev_text_slot
		{
			text = "Alt.";
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
			onLoad = "params ['_control','_config']; _control ctrlShow (missionNameSpace getvariable ['Rev_TFAR_77',false]);";
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