/*
 * Author: Reeveli
 * Part of Reeveli's TFAR SOG:PF Radio scribbles.
 * UI for field telephone M252.

 1.1
	Added nigh time text colors for relevant controls
*/


class vn_rscdisplay_m252
{
	idd = 200814;
	onLoad = "_this call vn_fnc_M252_onLoad;call Rev_TFAR_fnc_getSwAlt";
	onUnload="[TF_sw_dialog_radio, [ctrlText 8009,ctrlText 8010,ctrlText 8011,ctrlText 8012,ctrlText 8013,ctrlText 8014,ctrlText 8015,ctrlText 8016]] call Rev_TFAR_fnc_saveScribble;";
	class controlsBackground
	{
		class RadioImage: vn_RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\m252_ca.paa";
			x = "(((20*-1) + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((12.5*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(25 * (((getResolution select 4) min 1.2) / 40))";
			h = "(25 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "params ['_control','_config']; if (sunOrMoon < 1) then {_control ctrlSetTextColor [0.12,0.12,0.12,1]};";
		};
		class NotepadImage: RadioImage
		{
			text = "\vn\ui_f_vietnam\ui\radios\notepad_vietnamese_ca.paa";
			x = "((3 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			w = "(12.5 * (((getResolution select 4) min 1.2) / 40))";
		};
		class Rev_list: RscBackPicture
		{
			idc=8000;
			x = (14.5 + 20) * REV_TFARSOG_X;
			y = ((9.2*-1) + 12.5) * REV_TFARSOG_Y;
			w = 17 * REV_TFARSOG_W;
			h = 18.6 * REV_TFARSOG_H;
			text = "\Reeveli_TFAR_SOGPF_Scribbles\m252\Rev_m252_6.paa";
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_252',false]); if (sunOrMoon < 1) then {_control ctrlSetTextColor [0.12,0.12,0.12,1]};";
		};
	};
	class controls
	{
		class Stereo: vn_RscButton
		{
			idc = 100;
			x = "(((7*-1) + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((9*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(6 * (((getResolution select 4) min 1.2) / 40))";
			h = "(6 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			tooltip = "Stereo settings";
			colorBackground[] = {0,0,0,0};
			colorBackgroundActive[] = {0,0,0,0};
			colorBackgroundDisabled[] = {0,0,0,0};
			colorBorder[] = {0,0,0,0};
			colorDisabled[] = {0,0,0,0};
			colorFocused[] = {0,0,0,0};
			colorShadow[] = {0,0,0,0};
			colorText[] = {0,0,0,0};
		};
		class Volume: Stereo
		{
			idc = 101;
			tooltip = "Decrease volume | Increase volume";
			x = "(((1*-1) + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((9*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(1.5 * (((getResolution select 4) min 1.2) / 40))";
			h = "(1.5 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
		};
		class ChannelRotator: Volume
		{
			idc = 102;
			tooltip = "Previous channel | Next channel";
			y = "(((6.8*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
		};
		class Channel: vn_RscText
		{
			idc = 1604;
			text = "Ch.1";
			x = "((3 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((7.5*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(5 * (((getResolution select 4) min 1.2) / 40))";
			h = "(1 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			colorText[] = {0,0,0,1};
		};
		class TextFrequency: Channel
		{
			text = "Frequency:";
			x = "((3 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((6.7*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(4 * (((getResolution select 4) min 1.2) / 40))";
			h = "(1 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
		};
		class Frequency: vn_RscEdit
		{
			idc = 1400;
			text = "100.5";
			x = "((7 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((6.9*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(3 * (((getResolution select 4) min 1.2) / 40))";
			h = "(1 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			colorBackground[] = {0,0,0,0};
			colorText[] = {0.38,0.44,0.61,0.95};
			shadow = 0;
			style = "0x02 + 0x200";
			maxChars = 5;
			font = "Caveat";
			sizeEx = "(((((getResolution select 4) min 1.2) / 1.2) / 25) * 1.1)";
			onLoad = "params ['_control','_config']; if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class UnderlineFrequency: vn_RscText
		{
			x = "((7 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((5.9*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(3 * (((getResolution select 4) min 1.2) / 40))";
			h = "pixelH";
			colorBackground[] = {0,0,0,1};
		};
		class Mhz: TextFrequency
		{
			text = "MHz";
			x = "((10 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
		};
		class FrameLeftSet: vn_RscPicture
		{
			text = "\vn\ui_f_vietnam\ui\radios\right_angle_bottomleft_ca.paa";
			colorText[] = {0.38,0.44,0.61,0.95};
			x = "((3.2 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((5.5*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(1 * (((getResolution select 4) min 1.2) / 40))";
			h = "(1 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "params ['_control','_config']; if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class FrameRightSet: FrameLeftSet
		{
			text = "\vn\ui_f_vietnam\ui\radios\right_angle_topright_ca.paa";
			x = "((8.2 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
		};
		class Set: vn_RscButton
		{
			idc = 105;
			style = 2;
			text = "SET";
			font = "Caveat";
			colorText[] = {0.38,0.44,0.61,0.95};
			colorBackground[] = {0,0,0,0};
			tooltip = "";
			x = "((3.2 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((5.5*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(6 * (((getResolution select 4) min 1.2) / 40))";
			h = "(1 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onButtonClick="private _channel = ((TF_sw_dialog_radio) call TFAR_fnc_getSwSettings) select 0;[_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getSwFrq;";
			onLoad = "params ['_control','_config']; if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class FrameLeftClear: FrameLeftSet
		{
			x = "((9.2 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
		};
		class FrameRightClear: FrameRightSet
		{
			x = "((14.2 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
		};
		class Clear: Set
		{
			show = 1;
			idc = 106;
			text = "CLEAR";
			tooltip = "Clear frequency";
			x = "((9.2 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
		};
		class FrameAdditionalLeft: FrameLeftSet
		{
			x = "((6.2 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((4.5*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
		};
		class FrameAdditionalRight: FrameRightSet
		{
			x = "((11.2 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((4.5*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
		};
		class Additional: Set
		{
			idc = 107;
			text = "ADDITIONAL";
			tooltip = "Set additional channel";
			x = "((6.2 + 20) * (((getResolution select 4) min 1.2) / 40) + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2))";
			y = "(((4.5*-1) + 12.5) * ((((getResolution select 4) min 1.2) / 1.2) / 25) + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2))";
			w = "(6 * (((getResolution select 4) min 1.2) / 40))";
			onButtonClick = "call Rev_TFAR_fnc_getSwAlt";
		};		
		class Rev_text_slot: vn_RscText
		{
			text = "Kênh";
			colorText[] = {0.38,0.44,0.61,0.95};
			font = "Caveat";
			style = 2; //ST_CENTER
			sizeEx = "(((((getResolution select 4) min 1.2) / 1.2) / 25) * 1.2)";
			x = (16.5 + 20) * REV_TFARSOG_X;
			y = ((8.6*-1) + 12.5) * REV_TFARSOG_Y;
			w = 2 * REV_TFARSOG_W;
			h = "(1 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_252',false]); if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_slot_1: Rev_text_slot
		{
			text = "1 |";
			sizeEx = "(((((getResolution select 4) min 1.2) / 1.2) / 25) * 1.1)";
			y = ((6.6*-1) + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_slot_2: Rev_slot_1
		{
			text = "2 |";
			y = ((4.6*-1) + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_slot_3: Rev_slot_1
		{
			text = "3 |";
			y = ((2.6*-1) + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_slot_4: Rev_slot_1
		{
			text = "4 |";
			y = ((0.6*-1) + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_slot_5: Rev_slot_1
		{
			text = "5 |";
			y = (1.4 + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_slot_6: Rev_slot_1
		{
			text = "6 |";
			y = (3.4 + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_slot_7: Rev_slot_1
		{
			text = "7 |";
			y = (5.4 + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_slot_8: Rev_slot_1
		{
			text = "8 |";
			y = (7.4 + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_text_Mhz: Rev_text_slot
		{
			text = "Mhc";
			x = (18.5 + 20) * REV_TFARSOG_X;
			w = 3 * REV_TFARSOG_W;
		};
		class Rev_freq_1: Rev_slot_1
		{
			idc=8001;
			text = "";
			x = (18.5 + 20) * REV_TFARSOG_X;
			y = ((6.6*-1) + 12.5) * REV_TFARSOG_Y;
			w = 3 * REV_TFARSOG_W;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_252',false]); [1,_control] call Rev_TFAR_fnc_getSwFrq;";
		};
		class Rev_freq_2: Rev_freq_1
		{
			idc=8002;
			y = ((4.6*-1) + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_252',false]); [2,_control] call Rev_TFAR_fnc_getSwFrq;";
		};
		class Rev_freq_3: Rev_freq_1
		{
			idc=8003;
			y = ((2.6*-1) + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_252',false]); [3,_control] call Rev_TFAR_fnc_getSwFrq;";
		};
		class Rev_freq_4: Rev_freq_1
		{
			idc=8004;
			y = ((0.6*-1) + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_252',false]); [4,_control] call Rev_TFAR_fnc_getSwFrq;";
		};
		class Rev_freq_5: Rev_freq_1
		{
			idc=8005;
			y = (1.4 + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_252',false]); [5,_control] call Rev_TFAR_fnc_getSwFrq;";
		};
		class Rev_freq_6: Rev_freq_1
		{
			idc=8006;
			y = (3.4 + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_252',false]); [6,_control] call Rev_TFAR_fnc_getSwFrq;";
		};
		class Rev_freq_7: Rev_freq_1
		{
			idc=8007;
			y = (5.4 + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_252',false]); [7,_control] call Rev_TFAR_fnc_getSwFrq;";
		};
		class Rev_freq_8: Rev_freq_1
		{
			idc=8008;
			y = (7.4 + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_252',false]); [8,_control] call Rev_TFAR_fnc_getSwFrq;";
		};
		class Rev_text_desc: Rev_text_slot
		{
			text = "Nho*";
			style = 0;
			x = (21.5 + 20) * REV_TFARSOG_X;
			w = 5 * REV_TFARSOG_W;
		};
		class Rev_desc_1: Frequency
		{
			idc = 8009;
			text = "";
			style = "0x00 + 0x200";
			colorText[] = {0.38,0.44,0.61,0.95};
			sizeEx = "(((((getResolution select 4) min 1.2) / 1.2) / 25) * 1.1)";
			x = (21.5 + 20) * REV_TFARSOG_X;
			y = ((6.6*-1) + 12.5) * REV_TFARSOG_Y;
			w = 5 * REV_TFARSOG_W;
			h = "(1 * ((((getResolution select 4) min 1.2) / 1.2) / 25))";
			maxChars = 50;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_252',false]);[TF_sw_dialog_radio, 1, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_2: Rev_desc_1
		{
			idc = 8010;
			y = ((4.6*-1) + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_252',false]);[TF_sw_dialog_radio, 2, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_3: Rev_desc_1
		{
			idc = 8011;
			y = ((2.6*-1) + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_252',false]);[TF_sw_dialog_radio, 3, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_4: Rev_desc_1
		{
			idc = 8012;
			y = ((0.6*-1) + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_252',false]);[TF_sw_dialog_radio, 4, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_5: Rev_desc_1
		{
			idc = 8013;
			y = (1.4 + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_252',false]);[TF_sw_dialog_radio, 5, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_6: Rev_desc_1
		{
			idc = 8014;
			y = (3.4 + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_252',false]);[TF_sw_dialog_radio, 6, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_7: Rev_desc_1
		{
			idc = 8015;
			y = (5.4 + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_252',false]);[TF_sw_dialog_radio, 7, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_desc_8: Rev_desc_1
		{
			idc = 8016;
			y = (7.4 + 12.5) * REV_TFARSOG_Y;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_252',false]);[TF_sw_dialog_radio, 8, _control] call Rev_TFAR_fnc_loadScribble;if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_text_Alt: Rev_text_Mhz
		{
			text = "Thêm";
			x = (26.5 + 20) * REV_TFARSOG_X;
			w = 2 * REV_TFARSOG_W;
		};
		class Rev_alt_1: Rev_slot_1
		{
			idc=8020;
			text = "";
			x = (26.5 + 20) * REV_TFARSOG_X;
			y = ((6.6*-1) + 12.5) * REV_TFARSOG_Y;
			w = 2 * REV_TFARSOG_W;
			onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_252',false]); if (sunOrMoon < 1) then {_control ctrlSetTextColor [0,0,0,1]};";
		};
		class Rev_alt_2: Rev_alt_1
		{
			idc=8021;
			y = ((4.6*-1) + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_alt_3: Rev_alt_1
		{
			idc=8022;
			y = ((2.6*-1) + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_alt_4: Rev_alt_1
		{
			idc=8023;
			y = ((0.6*-1) + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_alt_5: Rev_alt_1
		{
			idc=8024;
			y = (1.4 + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_alt_6: Rev_alt_1
		{
			idc=8025;
			y = (3.4 + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_alt_7: Rev_alt_1
		{
			idc=8026;
			y = (5.4 + 12.5) * REV_TFARSOG_Y;
		};
		class Rev_alt_8: Rev_alt_1
		{
			idc=8027;
			y = (7.4 + 12.5) * REV_TFARSOG_Y;
		};
	};
};