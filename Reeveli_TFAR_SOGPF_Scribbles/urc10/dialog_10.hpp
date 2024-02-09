/*
 * Author: Reeveli
 * Part of Reeveli's TFAR SOG:PF Radio scribbles.
 * UI for URC-10.
1.2
	Fixed scribble edit field font color during night
1.1
	Added nigh time text colors for relevant controls
*/


class vn_rscdisplay_urc10
{
	idd = 200812;
	onLoad = "_this call VN_fnc_URC10_onLoad;call Rev_TFAR_fnc_getSwAlt";
	onUnload="[TF_sw_dialog_radio, [ctrlText 8009,ctrlText 8010,ctrlText 8011,ctrlText 8012,ctrlText 8013,ctrlText 8014,ctrlText 8015,ctrlText 8016]] call Rev_TFAR_fnc_saveScribble;";
	class controlsBackground
	{
		class RadioImage: RscPicture
		{
			idc = -1;
			text = "\vn\ui_f_vietnam\ui\radios\URC10_ca.paa";
			colorText[] = {1,1,1,1};
			x = "(((11*-1) + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((11*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(11 * (((getResolution select 4) min 1.2) / 40))";
			h = "(22 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "params ['_control','_config']; if (sunOrMoon < 1) then {_control ctrlSetTextColor [0.12,0.12,0.12,1]};";
		};
		class NotepadImage: RadioImage
		{
			idc = -1;
			text = "\vn\ui_f_vietnam\ui\radios\radio_notepad_ca.paa";
			x = "((0.5 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((9*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(10 * (((getResolution select 4) min 1.2) / 40))";
			h = "(20 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
		};
		class DTG_Observed: vn_RscText
		{
			idc = 200;
			text = "0815 2NOV69";
			colorText[] = {0.38,0.44,0.61,0.95};
			font = "Caveat";
			sizeEx = "(((((getResolution select 4) min 1.2) / 1.2) / 25) * 0.95)";
			x = "((5.2 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((3.5*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(5 * (((getResolution select 4) min 1.2) / 40))";
			h = "(1 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "params ['_control','_config']; if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Location: DTG_Observed
		{
			idc = 201;
			text = "644633";
			y = "(((2.8*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
		};
		class Oriented: DTG_Observed
		{
			idc = 202;
			text = "N S";
			y = "(((2.1*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
		};
		class Surface: DTG_Observed
		{
			idc = 203;
			text = "CLAY HARD PACKED";
			x = "((5.2 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((1.5*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(6 * (((getResolution select 4) min 1.2) / 40))";
			sizeEx = "(((((getResolution select 4) min 1.2) / 1.2) / 25) * 0.8)";
		};
		class HowRecentlyUsed: DTG_Observed
		{
			idc = 204;
			text = "UNKNOWN";
			x = "((6.5 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((0.9*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			sizeEx = "(((((getResolution select 4) min 1.2) / 1.2) / 25) * 0.8)";
		};
		class Width: DTG_Observed
		{
			idc = 205;
			text = "18''";
			y = "(((0.3*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
		};
		class ConcealmentFMAir: DTG_Observed
		{
			idc = 206;
			text = "NONE";
			x = "((6.6 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "((0.4 + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			sizeEx = "(((((getResolution select 4) min 1.2) / 1.2) / 25) * 0.8)";
		};
		class VisibilitySides: DTG_Observed
		{
			idc = 207;
			text = "500";
			y = "((1 + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
		};
		class VisibilityUpDownTrail: DTG_Observed
		{
			idc = 208;
			text = "1000";
			x = "((7.7 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "((1.6 + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
		};
		class TrailMarkings: DTG_Observed
		{
			idc = 209;
			text = "NONE";
			sizeEx = "(((((getResolution select 4) min 1.2) / 1.2) / 25) * 0.8)";
			x = "((5.5 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "((2.3 + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
		};
		class TypeCanopy: DTG_Observed
		{
			idc = 210;
			text = "NONE";
			sizeEx = "(((((getResolution select 4) min 1.2) / 1.2) / 25) * 0.8)";
			y = "((3 + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
		};
		class TracksFootprints: DTG_Observed
		{
			idc = 211;
			text = "NONE";
			x = "((6.5 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "((4.2 + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
		};
		class Rev_list: RscBackPicture
		{
			idc=8000;
			x = (9 + 20) * REV_TFARSOG_X;
			y = ((8.3*-1) + 12.5) * REV_TFARSOG_Y;
			w = 17 * REV_TFARSOG_W;
			h = 18.6 * REV_TFARSOG_H
			text = "\Reeveli_TFAR_SOGPF_Scribbles\urc10\Rev_urc10.paa";
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_10',false]);if (sunOrMoon < 1) then {_control ctrlSetTextColor [0.12,0.12,0.12,1]};";
		};
			




	};
	class controls
	{
		class VolumeUp: vn_RscButton
		{
			idc = 100;
			tooltip = "Increase volume";
			x = "(((11*-1) + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((6.4*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(1.5 * (((getResolution select 4) min 1.2) / 40))";
			h = "(1.2 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			colorBackground[] = {0,0,0,0};
			colorBackgroundActive[] = {0,0,0,0};
			colorBackgroundDisabled[] = {0,0,0,0};
			colorBorder[] = {0,0,0,0};
			colorDisabled[] = {0,0,0,0};
			colorFocused[] = {0,0,0,0};
			colorShadow[] = {0,0,0,0};
			colorText[] = {0,0,0,0};
		};
		class VolumeDown: VolumeUp
		{
			idc = 101;
			tooltip = "Decrease volume";
			y = "(((4.7*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
		};
		class Stereo: VolumeUp
		{
			idc = 102;
			tooltip = "Stereo settings";
			y = "(((3.5*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			h = "(4.5 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
		};
		class ChannelRotator: VolumeUp
		{
			idc = 103;
			tooltip = "Previous channel | Next channel";
			x = "(((3*-1) + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((10.5*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(3 * (((getResolution select 4) min 1.2) / 40))";
			h = "(4.4 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
		};
		class Channel: vn_RscText
		{
			idc = 1604;
			text = "Ch.1";
			x = "((1.6 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((8*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.7 * (((getResolution select 4) min 1.2) / 40))";
			h = "(1 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			font = "tt2020style_e_vn";
			colorText[] = {0.41,0.23,0.22,0.75};
			onLoad = "params ['_control','_config']; if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Frequency: vn_RscEdit
		{
			idc = 1400;
			style = "0x01 + 0x200";
			colorBackground[] = {0,0,0,0};
			shadow = 0;
			colorText[] = {0.38,0.44,0.61,0.95};
			sizeEx = "(((((getResolution select 4) min 1.2) / 1.2) / 25) * 1.1)";
			font = "Caveat";
			x = "((3.1 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((7.1*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.7 * (((getResolution select 4) min 1.2) / 40))";
			h = "(1 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onKeyUp="if (_this select 1 in [28,156]) then {private _channel = ((TF_sw_dialog_radio) call TFAR_fnc_getSwSettings) select 0;[_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getSwFrq;};";
			maxChars = 5;
			onLoad = "params ['_control','_config']; if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class FrameLeftSet: vn_RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\right_angle_bottomleft_ca.paa";
			colorText[] = {0.38,0.44,0.61,0.95};
			x = "((1.7 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((6*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(1 * (((getResolution select 4) min 1.2) / 40))";
			h = "(1 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "params ['_control','_config']; if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class FrameRightSet: FrameLeftSet
		{
			text = "\vn\ui_f_vietnam\ui\radios\right_angle_topright_ca.paa";
			x = "((5 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
		};
		class Set: vn_RscButton
		{
			idc = 106;
			style = 2;
			text = "SET";
			font = "Caveat";
			colorText[] = {0.38,0.44,0.61,0.95};
			colorBackground[] = {0,0,0,0};
			tooltip = "Set frequency";
			x = "((1.7 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((6*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4.3 * (((getResolution select 4) min 1.2) / 40))";
			h = "(1 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick="private _channel = ((TF_sw_dialog_radio) call TFAR_fnc_getSwSettings) select 0;[_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getSwFrq;";
			onLoad = "params ['_control','_config']; if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class FrameLeftClear: FrameLeftSet
		{
			x = "((6 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
		};
		class FrameRightClear: FrameRightSet
		{
			x = "((9.4 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
		};
		class Clear: Set
		{
			idc = 107;
			text = "CLEAR";
			tooltip = "Clear frequency";
			x = "((6 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			w = "(4.4 * (((getResolution select 4) min 1.2) / 40))";
		};
		class FrameLeftAdditional: FrameLeftSet
		{
			x = "((3.6 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((5*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
		};
		class FrameRightAdditional: FrameRightSet
		{
			x = "((7.6 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((5*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
		};
		class Additional: Set
		{
			idc = 108;
			text = "ADDITIONAL";
			tooltip = "Set additional channel";
			x = "((3.6 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((5*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(5 * (((getResolution select 4) min 1.2) / 40))";
			onButtonClick = "call Rev_TFAR_fnc_getSwAlt";
		};		
		class Rev_text_slot: vn_RscText
		{
			text = "SLOT";
			colorText[] = {0.38,0.44,0.61,0.95};
			font = "Caveat";
			style = 2; //ST_CENTER
			sizeEx = "(((((getResolution select 4) min 1.2) / 1.2) / 25) * 1.2)"; //0.95
			x = (11 + 20) * REV_TFARSOG_X;
			y = ((7.5*-1) + 12.5) * REV_TFARSOG_Y;
			w = 2 * REV_TFARSOG_W;
			h = "(1 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_10',false]);if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_slot_1: Rev_text_slot
		{
			text = "1 |";
			sizeEx = "(((((getResolution select 4) min 1.2) / 1.2) / 25) * 1.1)";
			y = ((5.5*-1) + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_slot_2: Rev_slot_1
		{
			text = "2 |";
			y = ((3.5*-1) + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_slot_3: Rev_slot_1
		{
			text = "3 |";
			y = ((1.5*-1) + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_slot_4: Rev_slot_1
		{
			text = "4 |";
			y = (0.5 + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_slot_5: Rev_slot_1
		{
			text = "5 |";
			y = (2.5 + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_slot_6: Rev_slot_1
		{
			text = "6 |";
			y = (4.5 + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_slot_7: Rev_slot_1
		{
			text = "7 |";
			y = (6.5 + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_slot_8: Rev_slot_1
		{
			text = "8 |";
			y = (8.5 + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_text_Mhz: Rev_text_slot
		{
			text = "MHz";
			x = (13 + 20) * REV_TFARSOG_X;
			w = 3 * REV_TFARSOG_W;
		};
		class Rev_freq_1: Rev_slot_1
		{
			idc=8001;
			text = "";
			x = (13 + 20) * REV_TFARSOG_X;
			w = 3 * REV_TFARSOG_W;
			y = ((5.5*-1) + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_10',false]); [1,_control] call Rev_TFAR_fnc_getSwFrq;";
		};
		class Rev_freq_2: Rev_freq_1
		{
			idc=8002;
			y = ((3.5*-1) + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_10',false]); [2,_control] call Rev_TFAR_fnc_getSwFrq;";
		};
		class Rev_freq_3: Rev_freq_1
		{
			idc=8003;
			y = ((1.5*-1) + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_10',false]); [3,_control] call Rev_TFAR_fnc_getSwFrq;";
		};
		class Rev_freq_4: Rev_freq_1
		{
			idc=8004;
			y = (0.5 + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_10',false]); [4,_control] call Rev_TFAR_fnc_getSwFrq;";
		};
		class Rev_freq_5: Rev_freq_1
		{
			idc=8005;
			y = (2.5 + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_10',false]); [5,_control] call Rev_TFAR_fnc_getSwFrq;";
		};
		class Rev_freq_6: Rev_freq_1
		{
			idc=8006;
			y = (4.5 + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_10',false]); [6,_control] call Rev_TFAR_fnc_getSwFrq;";
		};
		class Rev_freq_7: Rev_freq_1
		{
			idc=8007;
			y = (6.5 + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_10',false]); [7,_control] call Rev_TFAR_fnc_getSwFrq;";
		};
		class Rev_freq_8: Rev_freq_1
		{
			idc=8008;
			y = (8.5 + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_10',false]); [8,_control] call Rev_TFAR_fnc_getSwFrq;";
		};
		class Rev_text_desc: Rev_text_slot
		{
			text = "DESC";
			style = 0;
			x = (16 + 20) * REV_TFARSOG_X;
			w = 5 * REV_TFARSOG_W;
		};
		class Rev_desc_1: Frequency
		{
			idc = 8009;
			text = "";
			style = "0x00 + 0x200";
			colorText[] = {0.38,0.44,0.61,0.95};
			sizeEx = "(((((getResolution select 4) min 1.2) / 1.2) / 25) * 1.1)";
			x = (16 + 20) * REV_TFARSOG_X;
			y = ((5.5*-1) + 12.5) * REV_TFARSOG_Y;
			w = 5 * REV_TFARSOG_W;
			h = "(1 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			maxChars = 50;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_10',false]);[TF_sw_dialog_radio, 1, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_2: Rev_desc_1
		{
			idc = 8010;
			y = ((3.5*-1) + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_10',false]);[TF_sw_dialog_radio, 2, _control] call Rev_TFAR_fnc_loadScribble;";
		};
		class Rev_desc_3: Rev_desc_1
		{
			idc = 8011;
			y = ((1.5*-1) + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_10',false]);[TF_sw_dialog_radio, 3, _control] call Rev_TFAR_fnc_loadScribble;";
		};
		class Rev_desc_4: Rev_desc_1
		{
			idc = 8012;
			y = (0.5 + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_10',false]);[TF_sw_dialog_radio, 4, _control] call Rev_TFAR_fnc_loadScribble;";
		};
		class Rev_desc_5: Rev_desc_1
		{
			idc = 8013;
			y = (2.5 + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_10',false]);[TF_sw_dialog_radio, 5, _control] call Rev_TFAR_fnc_loadScribble;";
		};
		class Rev_desc_6: Rev_desc_1
		{
			idc = 8014;
			y = (4.5 + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_10',false]);[TF_sw_dialog_radio, 6, _control] call Rev_TFAR_fnc_loadScribble;";
		};
		class Rev_desc_7: Rev_desc_1
		{
			idc = 8015;
			y = (6.5 + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_10',false]);[TF_sw_dialog_radio, 7, _control] call Rev_TFAR_fnc_loadScribble;";
		};
		class Rev_desc_8: Rev_desc_1
		{
			idc = 8016;
			y = (8.5 + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_10',false]);[TF_sw_dialog_radio, 8, _control] call Rev_TFAR_fnc_loadScribble;";
		};
		class Rev_text_Alt: Rev_text_Mhz
		{
			text = "ALT";
			x = (21 + 20) * REV_TFARSOG_X;
			w = 2 * REV_TFARSOG_W;
		};
		class Rev_alt_1: Rev_slot_1
		{
			idc=8020;
			text = "";
			x = (21 + 20) * REV_TFARSOG_X;
			w = 2 * REV_TFARSOG_W;
			y = ((5.5*-1) + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_10',false]);";
		};
		class Rev_alt_2: Rev_alt_1
		{
			idc=8021;
			y = ((3.5*-1) + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_alt_3: Rev_alt_1
		{
			idc=8022;
			y = ((1.5*-1) + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_alt_4: Rev_alt_1
		{
			idc=8023;
			y = (0.5 + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_alt_5: Rev_alt_1
		{
			idc=8024;
			y = (2.5 + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_alt_6: Rev_alt_1
		{
			idc=8025;
			y = (4.5 + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_alt_7: Rev_alt_1
		{
			idc=8026;
			y = (6.5 + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_alt_8: Rev_alt_1
		{
			idc=8027;
			y = (8.5 + 12.5) * REV_TFARSOG_Y;
		};
	};
};