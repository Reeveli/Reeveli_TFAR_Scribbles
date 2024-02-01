/*
 * Author: Reeveli
 * Part of Reeveli's TFAR Scribbles.
 * UI for ANPRC 148.
*/


#define TFAR_148_X  				0.0447031 * safezoneW + safezoneX
#define TFAR_148_Y  				-1.0488 * safezoneH + safezoneY
#define TFAR_148_W  				0.302156 * safezoneW
#define TFAR_148_H  				2.0537 * safezoneH
#define TFAR_148_TEXT_S				TFAR_148_H * 0.02

class anprc148jem_radio_dialog
{
	idd = 6000;
	movingEnable = 1;
	objects[] = {};
	controls[] = {"background","Rev_list","Rev_ch_1","Rev_ch_2","Rev_ch_3","Rev_ch_4","Rev_ch_5","Rev_fr_1","Rev_fr_2","Rev_fr_3","Rev_fr_4","Rev_fr_5","Rev_desc_1","Rev_desc_2","Rev_desc_3","Rev_desc_4","Rev_desc_5","enter","clear","edit","channel_edit","prev_channel","next_channel","additional","speakers","stereo","volume_Switch","channel_Switch"};
	controlsBackground[] = {};
	onUnload = "['OnRadioOpen', [player, TF_sw_dialog_radio, false, 'anprc148jem_radio_dialog', false]] call TFAR_fnc_fireEventHandlers;[TF_sw_dialog_radio, [ctrlText 8009,ctrlText 8010,ctrlText 8011,ctrlText 8012,ctrlText 8013]] call Rev_TFAR_fnc_saveScribble;";
	onLoad = "if (sunOrMoon < 0.2) then {((_this select 0) displayCtrl 67676) ctrlSetText '\z\tfar\addons\handhelds\anprc148jem\ui\148_n.paa';((_this select 0) displayCtrl 8000) ctrlSetTextColor [0.12,0.12,0.12,1]};";
	class background: RscBackPicture
	{
		idc = 67676;
		text = "\z\tfar\addons\handhelds\anprc148jem\ui\148.paa";
		x = "0.0447031 * safezoneW + safezoneX";
		y = "-1.0488 * safezoneH + safezoneY";
		w = "0.302156 * safezoneW";
		h = "2.0537 * safezoneH";
		moving = 1;
	};
	class Rev_list: background
	{
		idc=8000;
		text="\Reeveli_TFAR_Scribbles\anprc148jem\Rev_anprc148jem.paa";
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_148',false]);";
	};
	class Rev_ch_1: RscText
	{
		text = "1 /";
		font = "Caveat";
		sizeEx = TFAR_148_H * 0.016;	
		colorText[] = {0,0,0,1};
		shadow = 0;
		x = TFAR_148_X + TFAR_148_W * 0.214;
		y = TFAR_148_Y + TFAR_148_H * 0.862;
		w = TFAR_148_W * 0.078;
		h = TFAR_148_H * 0.013;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_148',false]);";
	};
	class Rev_fr_1: RscText
	{
		idc = 8001;
		font = "Caveat";
		sizeEx = TFAR_148_TEXT_S;	
		colorText[] = {0,0,0,1};
		shadow = 0;
		x = TFAR_148_X + TFAR_148_W * 0.282;
		y = TFAR_148_Y + TFAR_148_H * 0.862;
		w = TFAR_148_W * 0.128;
		h = TFAR_148_H * 0.013;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_148',false]); [1,_control] call Rev_TFAR_fnc_getSwFrq;";
	};
	class Rev_desc_1: RscEdit
	{
		idc = 8009;
		text = "";
		font = "Caveat";	
		sizeEx = TFAR_148_H * 0.017;
		colorText[] = {0,0,0,1};
		shadow = 0;
		style = 512;
		x = TFAR_148_X + TFAR_148_W * 0.40;
		y = TFAR_148_Y + TFAR_148_H * 0.862;
		w = TFAR_148_W * 0.27;
		h = TFAR_148_H * 0.013;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_148',false]);[TF_sw_dialog_radio, 1, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_ch_2: Rev_ch_1
	{
		text = "2 /";
		y = TFAR_148_Y + TFAR_148_H * 0.886;
	};
	class Rev_fr_2: Rev_fr_1
	{
		idc = 8002;
		y = TFAR_148_Y + TFAR_148_H * 0.886;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_148',false]); [2,_control] call Rev_TFAR_fnc_getSwFrq;";
	};
	class Rev_desc_2: Rev_desc_1
	{
		idc = 8010;
		y = TFAR_148_Y + TFAR_148_H * 0.886;
		w = TFAR_148_W * 0.241;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_148',false]);[TF_sw_dialog_radio, 2, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_ch_3: Rev_ch_1
	{
		text = "3 /";
		y = TFAR_148_Y + TFAR_148_H * 0.91;
	};
	class Rev_fr_3: Rev_fr_1
	{
		idc = 8003;
		y = TFAR_148_Y + TFAR_148_H * 0.91;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_148',false]); [3,_control] call Rev_TFAR_fnc_getSwFrq;";
	};
	class Rev_desc_3: Rev_desc_1
	{
		idc = 8011;
		y = TFAR_148_Y + TFAR_148_H * 0.91;
		w = TFAR_148_W * 0.275;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_148',false]);[TF_sw_dialog_radio, 3, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_ch_4: Rev_ch_1
	{
		text = "4 /";
		y = TFAR_148_Y + TFAR_148_H * 0.934;
	};
	class Rev_fr_4: Rev_fr_1
	{
		idc = 8004;
		y = TFAR_148_Y + TFAR_148_H * 0.934;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_148',false]); [4,_control] call Rev_TFAR_fnc_getSwFrq;";
	};
	class Rev_desc_4: Rev_desc_1
	{
		idc = 8012;
		y = TFAR_148_Y + TFAR_148_H * 0.934;
		w = TFAR_148_W * 0.275;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_148',false]);[TF_sw_dialog_radio, 4, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_ch_5: Rev_ch_1
	{
		text = "5 /";
		y = TFAR_148_Y + TFAR_148_H * 0.959;
	};
	class Rev_fr_5: Rev_fr_1
	{
		idc = 8005;
		y = TFAR_148_Y + TFAR_148_H * 0.959;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_148',false]); [5,_control] call Rev_TFAR_fnc_getSwFrq;";
	};
	class Rev_desc_5: Rev_desc_1
	{
		idc = 8013;
		y = TFAR_148_Y + TFAR_148_H * 0.959;
		w = TFAR_148_W * 0.265;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_148',false]);[TF_sw_dialog_radio, 5, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class enter: HiddenButton
	{
		idc = 6468;
		x = "0.204031 * safezoneW + safezoneX";
		y = "0.5352 * safezoneH + safezoneY";
		w = "0.0275625 * safezoneW";
		h = "0.0266059 * safezoneH";
		tooltip = "Set frequency";
		onButtonClick = "[((ctrlParent (_this select 0))) displayCtrl 1400] call TFAR_handhelds_fnc_onButtonClick_Enter;";
		action = "";
	};
	class clear: HiddenButton
	{
		idc = 6469;
		x = "0.204031 * safezoneW + safezoneX";
		y = "0.5011 * safezoneH + safezoneY";
		w = "0.0249375 * safezoneW";
		h = "0.0280062 * safezoneH";
		tooltip = "Clear frequency";
		action = "ctrlSetText [1400,'']; ctrlSetFocus ((findDisplay 6000) displayCtrl 1400);";
	};
	class edit: RscEditLCD
	{
		idc = 1400;
		x = "0.163812 * safezoneW + safezoneX";
		y = "0.4021 * safezoneH + safezoneY";
		w = "0.0634219 * safezoneW";
		h = "0.0682 * safezoneH";
		font = "TFAR_font_dots";
		shadow = 2;
		tooltip = "Current frequency";
		canModify = 1;
		moving = 1;
		onKeyUp = "if (_this select 1 in [28,156]) then { [((ctrlParent (_this select 0))) displayCtrl 1400] call TFAR_handhelds_fnc_onButtonClick_Enter; private _channel = ((TF_sw_dialog_radio) call TFAR_fnc_getSwSettings) select 0;[_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getSwFrq;};";
		onLoad = "params ['_control','_config']; ctrlSetFocus _control";
	};
	class channel_edit: RscEditLCD
	{
		idc = 1604;
		x = "0.134422 * safezoneW + safezoneX";
		y = "0.402215 * safezoneH + safezoneY";
		w = "0.0304219 * safezoneW";
		h = "0.0682 * safezoneH";
		font = "TFAR_font_dots";
		shadow = 2;
		tooltip = "Current channel";
		canModify = 0;
		moving = 1;
	};
	class prev_channel: HiddenButton
	{
		idc = 6470;
		x = "0.131328 * safezoneW + safezoneX";
		y = "0.5319 * safezoneH + safezoneY";
		w = "0.023625 * safezoneW";
		h = "0.0280062 * safezoneH";
		tooltip = "Previous channel";
		action = "[0, false] call TFAR_fnc_setChannelViaDialog;";
	};
	class next_channel: HiddenButton
	{
		idc = 6471;
		x = "0.168453 * safezoneW + safezoneX";
		y = "0.5341 * safezoneH + safezoneY";
		w = "0.0249375 * safezoneW";
		h = "0.0280062 * safezoneH";
		tooltip = "Next channel";
		action = "[1, false] call TFAR_fnc_setChannelViaDialog;";
	};
	class additional: HiddenButton
	{
		idc = 6472;
		x = "0.168969 * safezoneW + safezoneX";
		y = "0.5011 * safezoneH + safezoneY";
		w = "0.0242813 * safezoneW";
		h = "0.0294066 * safezoneH";
		tooltip = "Set additional channel";
		action = "[TF_sw_dialog_radio, TF_sw_dialog_radio call TFAR_fnc_getSwChannel] call TFAR_fnc_setAdditionalSwChannel; call TFAR_fnc_updateSWDialogToChannel; [TF_sw_dialog_radio, false] call TFAR_fnc_showRadioInfo;";
	};
	class speakers: HiddenButton
	{
		idc = 6473;
		x = "0.132359 * safezoneW + safezoneX";
		y = "0.5022 * safezoneH + safezoneY";
		w = "0.0269063 * safezoneW";
		h = "0.0266059 * safezoneH";
		tooltip = "Speakers";
		action = "[TF_sw_dialog_radio] call TFAR_fnc_setSwSpeakers;[TF_sw_dialog_radio] call TFAR_fnc_showRadioSpeakers;";
	};
	class stereo: HiddenButton
	{
		idc = 6474;
		x = "0.128234 * safezoneW + safezoneX";
		y = "0.5726 * safezoneH + safezoneY";
		w = "0.0201094 * safezoneW";
		h = "0.0363 * safezoneH";
		action = "[TF_sw_dialog_radio,((TF_sw_dialog_radio call TFAR_fnc_getCurrentSwStereo) + 1) mod 3] call TFAR_fnc_setSwStereo; [TF_sw_dialog_radio] call TFAR_fnc_showRadioVolume;";
		tooltip = "Stereo settings";
	};
	class volume_Switch: HiddenRotator
	{
		idc = 12345;
		x = "0.191656 * safezoneW + safezoneX";
		y = "0.1139 * safezoneH + safezoneY";
		w = "0.045375 * safezoneW";
		h = "0.0539 * safezoneH";
		tooltip = "Decrease volume | Increase volume";
		onMouseButtonDown = "[_this select 1, false] call TFAR_fnc_setVolumeViaDialog;";
	};
	class channel_Switch: HiddenRotator
	{
		idc = 123456;
		x = "0.11225 * safezoneW + safezoneX";
		y = "0.1458 * safezoneH + safezoneY";
		w = "0.0293906 * safezoneW";
		h = "0.0407 * safezoneH";
		tooltip = "Previous channel | Next channel";
		onMouseButtonDown = "[_this select 1, false] call TFAR_fnc_setChannelViaDialog;";
	};
};