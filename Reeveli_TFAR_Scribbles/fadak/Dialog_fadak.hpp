/*
 * Author: Reeveli
 * Part of Reeveli's TFAR Scribbles.
 * UI for Fadak.
 
1.1
	Increased nigh time threshold to <1
	Updated Rev_list to v2 graphic
	Removed holdover placeholdet text from Rev_fr_1

*/


#define TFAR_FADAK_X  				0.0142813 * safezoneW + safezoneX
#define TFAR_FADAK_Y  				-0.1314 * safezoneH + safezoneY
#define TFAR_FADAK_W  				0.332062 * safezoneW
#define TFAR_FADAK_H  				1.1198 * safezoneH



class fadak_radio_dialog
{
	idd = 7777;
	movingEnable = 1;
	objects[] = {};
	controls[] = {"background","Rev_list","Rev_fr_1","Rev_fr_2","Rev_fr_3","Rev_fr_4","Rev_fr_5","Rev_fr_6","Rev_fr_7","Rev_fr_8","Rev_desc_1","Rev_desc_2","Rev_desc_3","Rev_desc_4","Rev_desc_5","Rev_desc_6","Rev_desc_7","Rev_desc_8","enter","clear","channel_switch","increase_volume","decrease_volume","edit","channel_edit","stereo","additional","speakers"};
	controlsBackground[] = {};
	onUnload = "['OnRadioOpen', [player, TF_sw_dialog_radio, false, 'fadak_radio_dialog', false]] call TFAR_fnc_fireEventHandlers; [TF_sw_dialog_radio, [ctrlText 8009,ctrlText 8010,ctrlText 8011,ctrlText 8012,ctrlText 8013,ctrlText 8014,ctrlText 8015,ctrlText 8016]] call Rev_TFAR_fnc_saveScribble;";
	onLoad = "if (sunOrMoon < 1) then { ((_this select 0) displayCtrl 67676) ctrlSetText '\z\tfar\addons\handhelds\fadak\ui\fadak_n.paa'; ((_this select 0) displayCtrl 8000) ctrlSetTextColor [0.18,0.18,0.18,1]};";
	class background: RscBackPicture
	{
		idc = 67676;
		text = "\z\tfar\addons\handhelds\fadak\ui\fadak.paa";
		x = "0.0142813 * safezoneW + safezoneX";
		y = "-0.1314 * safezoneH + safezoneY";
		w = "0.332062 * safezoneW";
		h = "1.1198 * safezoneH";
		moving = 1;
	};
	class Rev_list: background
	{
		idc=8000;
		text="\Reeveli_TFAR_Scribbles\fadak\Rev_fadak_2.paa";
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_FADAK',false]);";
	};
	class Rev_fr_1: RscText
	{
		idc = 8001;
		text = "";
		font = "Caveat";
		sizeEx = TFAR_FADAK_H * 0.020;	
		colorText[] = {0,0,0,1};
		shadow = 0;
		x = TFAR_FADAK_X + TFAR_FADAK_W * 0.383; //0.385
		y = TFAR_FADAK_Y + TFAR_FADAK_H * 0.821;
		w = TFAR_FADAK_W * 0.081;
		h = TFAR_FADAK_H * 0.016;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_FADAK',false]); [1,_control] call Rev_TFAR_fnc_getSwFrq;";
	};
	class Rev_fr_2: Rev_fr_1
	{
		idc = 8002;
		y = TFAR_FADAK_Y + TFAR_FADAK_H * 0.84;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_FADAK',false]);[2,_control] call Rev_TFAR_fnc_getSwFrq;";
	};
	class Rev_fr_3: Rev_fr_1
	{
		idc = 8003;
		y = TFAR_FADAK_Y + TFAR_FADAK_H * 0.859;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_FADAK',false]);[3,_control] call Rev_TFAR_fnc_getSwFrq;";
	};
	class Rev_fr_4: Rev_fr_1
	{
		idc = 8004;
		y = TFAR_FADAK_Y + TFAR_FADAK_H * 0.878;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_FADAK',false]);[4,_control] call Rev_TFAR_fnc_getSwFrq;";
	};
	class Rev_fr_5: Rev_fr_1
	{
		idc = 8005;
		y = TFAR_FADAK_Y + TFAR_FADAK_H * 0.897;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_FADAK',false]);[5,_control] call Rev_TFAR_fnc_getSwFrq;";
	};
	class Rev_fr_6: Rev_fr_1
	{
		idc = 8006;
		y = TFAR_FADAK_Y + TFAR_FADAK_H * 0.915;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_FADAK',false]);[6,_control] call Rev_TFAR_fnc_getSwFrq;";
	};
	class Rev_fr_7: Rev_fr_1
	{
		idc = 8007;
		y = TFAR_FADAK_Y + TFAR_FADAK_H * 0.934;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_FADAK',false]);[7,_control] call Rev_TFAR_fnc_getSwFrq;";
	};
	class Rev_fr_8: Rev_fr_1
	{
		idc = 8008;
		y = TFAR_FADAK_Y + TFAR_FADAK_H * 0.952;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_FADAK',false]);[8,_control] call Rev_TFAR_fnc_getSwFrq;";
	};
	class Rev_desc_1: RscEdit
	{
		idc = 8009;
		text = "";
		font = "Caveat";	
		size = TFAR_152_H * 0.009;
		sizeEx = TFAR_152_H * 0.009;
		colorText[] = {0,0,0,1};
		shadow = 0;
		style = 512;
		x = TFAR_FADAK_X + TFAR_FADAK_W * 0.468; //0.47
		y = TFAR_FADAK_Y + TFAR_FADAK_H * 0.821;
		w = TFAR_FADAK_W * 0.16;
		h = TFAR_FADAK_H * 0.016;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_FADAK',false]);[TF_sw_dialog_radio, 1, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_2: Rev_desc_1
	{
		idc = 8010;
		y = TFAR_FADAK_Y + TFAR_FADAK_H * 0.84;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_FADAK',false]);[TF_sw_dialog_radio, 2, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_3: Rev_desc_1
	{
		idc = 8011;
		y = TFAR_FADAK_Y + TFAR_FADAK_H * 0.859;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_FADAK',false]);[TF_sw_dialog_radio, 3, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_4: Rev_desc_1
	{
		idc = 8012;
		y = TFAR_FADAK_Y + TFAR_FADAK_H * 0.878;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_FADAK',false]);[TF_sw_dialog_radio, 4, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_5: Rev_desc_1
	{
		idc = 8013;
		y = TFAR_FADAK_Y + TFAR_FADAK_H * 0.897;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_FADAK',false]);[TF_sw_dialog_radio, 5, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_6: Rev_desc_1
	{
		idc = 8014;
		y = TFAR_FADAK_Y + TFAR_FADAK_H * 0.915;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_FADAK',false]);[TF_sw_dialog_radio, 6, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_7: Rev_desc_1
	{
		idc = 8015;
		y = TFAR_FADAK_Y + TFAR_FADAK_H * 0.934;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_FADAK',false]);[TF_sw_dialog_radio, 7, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_8: Rev_desc_1
	{
		idc = 8016;
		y = TFAR_FADAK_Y + TFAR_FADAK_H * 0.952;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_FADAK',false]);[TF_sw_dialog_radio, 8, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class enter: HiddenButton
	{
		idc = 2616;
		x = "0.196812 * safezoneW + safezoneX";
		y = "0.577 * safezoneH + safezoneY";
		w = "0.0170625 * safezoneW";
		h = "0.0252056 * safezoneH";
		tooltip = "Set frequency";
		onButtonClick = "[((ctrlParent (_this select 0))) displayCtrl 1400] call TFAR_handhelds_fnc_onButtonClick_Enter; private _channel = ((TF_sw_dialog_radio) call TFAR_fnc_getSwSettings) select 0;[_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getSwFrq;";
		onLoad = "params ['_control','_config']; ctrlSetFocus _control";
		action = "";
	};
	class clear: HiddenButton
	{
		idc = 2617;
		x = "0.196812 * safezoneW + safezoneX";
		y = "0.6078 * safezoneH + safezoneY";
		w = "0.0150938 * safezoneW";
		h = "0.0280062 * safezoneH";
		tooltip = "Clear frequency";
		action = "ctrlSetText [1400,'']; ctrlSetFocus ((findDisplay 7777) displayCtrl 1400);";
	};
	class additional: HiddenButton
	{
		idc = 12345;
		x = "0.196297 * safezoneW + safezoneX";
		y = "0.643 * safezoneH + safezoneY";
		w = "0.0164063 * safezoneW";
		h = "0.0238053 * safezoneH";
		tooltip = "Set additional channel";
		action = "[TF_sw_dialog_radio, TF_sw_dialog_radio call TFAR_fnc_getSwChannel] call TFAR_fnc_setAdditionalSwChannel; call TFAR_fnc_updateSWDialogToChannel; [TF_sw_dialog_radio, false] call TFAR_fnc_showRadioInfo;";
	};
	class previous_channel: HiddenButton
	{
		idc = 2619;
		x = "0.196297 * safezoneW + safezoneX";
		y = "0.6749 * safezoneH + safezoneY";
		w = "0.0150938 * safezoneW";
		h = "0.022405 * safezoneH";
		tooltip = "Previous channel";
		action = "[0, false] call TFAR_fnc_setChannelViaDialog;";
	};
	class increase_volume: HiddenButton
	{
		idc = 2620;
		x = "0.176187 * safezoneW + safezoneX";
		y = "0.6738 * safezoneH + safezoneY";
		w = "0.0164063 * safezoneW";
		h = "0.0252056 * safezoneH";
		action = "[1, false] call TFAR_fnc_setVolumeViaDialog;";
		tooltip = "Increase volume";
	};
	class decrease_volume: HiddenButton
	{
		idc = 2621;
		x = "0.137 * safezoneW + safezoneX";
		y = "0.6727 * safezoneH + safezoneY";
		w = "0.0164063 * safezoneW";
		h = "0.0252056 * safezoneH";
		action = "[0, false] call TFAR_fnc_setVolumeViaDialog;";
		tooltip = "Decrease volume";
	};
	class edit: RscEditLCD
	{
		idc = 1400;
		x = "0.162781 * safezoneW + safezoneX";
		y = "0.401 * safezoneH + safezoneY";
		w = "0.0505312 * safezoneW";
		h = "0.0539 * safezoneH";
		font = "TFAR_font_segments";
		shadow = 1;
		tooltip = "Current frequency";
		canModify = 1;
		onKeyUp = "if (_this select 1 in [28,156]) then { [((ctrlParent (_this select 0))) displayCtrl 1400] call TFAR_handhelds_fnc_onButtonClick_Enter; private _channel = ((TF_sw_dialog_radio) call TFAR_fnc_getSwSettings) select 0;[_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getSwFrq;};";
	};
	class channel_edit: RscEditLCD
	{
		idc = 1604;
		x = "0.140094 * safezoneW + safezoneX";
		y = "0.401 * safezoneH + safezoneY";
		w = "0.0257812 * safezoneW";
		h = "0.0539 * safezoneH";
		font = "TFAR_font_segments";
		shadow = 1;
		tooltip = "Current channel";
		canModify = 0;
	};
	class stereo: HiddenButton
	{
		idc = 2622;
		x = "0.157625 * safezoneW + safezoneX";
		y = "0.6738 * safezoneH + safezoneY";
		w = "0.0164063 * safezoneW";
		h = "0.0252056 * safezoneH";
		action = "[TF_sw_dialog_radio,((TF_sw_dialog_radio call TFAR_fnc_getCurrentSwStereo) + 1) mod 3] call TFAR_fnc_setSwStereo; [TF_sw_dialog_radio] call TFAR_fnc_showRadioVolume;";
		tooltip = "Stereo settings";
	};
	class channel_switch: HiddenRotator
	{
		idc = 2618;
		x = "0.167937 * safezoneW + safezoneX";
		y = "0.2624 * safezoneH + safezoneY";
		w = "0.0236227 * safezoneW";
		h = "0.0518116 * safezoneH";
		tooltip = "Previous channel | Next channel";
		onMouseButtonDown = "[_this select 1, false] call TFAR_fnc_setChannelViaDialog;";
	};
	class speakers: HiddenButton
	{
		idc = 123456;
		x = "0.156078 * safezoneW + safezoneX";
		y = "0.61 * safezoneH + safezoneY";
		w = "0.0175312 * safezoneW";
		h = "0.0319 * safezoneH";
		tooltip = "Speakers";
		action = "[TF_sw_dialog_radio] call TFAR_fnc_setSwSpeakers;[TF_sw_dialog_radio] call TFAR_fnc_showRadioSpeakers;";
	};
};