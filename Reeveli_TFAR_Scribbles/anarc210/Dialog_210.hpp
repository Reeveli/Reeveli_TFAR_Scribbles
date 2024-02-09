/*
 * Author: Reeveli
 * Part of Reeveli's TFAR Scribbles.
 * UI for ANARC 210.
 
2.1
	Increased nigh time threshold to <1
2.0.1
	Updated notebook graphic to v7

2.0 Update
	New UI background image
	New dynamic controls for showing alt channel
		Added function call to alt channel button and onLoad EH for new alt channel functionality
*/

class anarc210_radio_dialog
{
	idd = 8423;
	movingEnable = 1;
	onUnload = "['OnRadioOpen', [player, TF_lr_dialog_radio, true, 'anarc210_radio_dialog', false]] call TFAR_fnc_fireEventHandlers;[TF_lr_dialog_radio # 0, [ctrlText 8009,ctrlText 8010,ctrlText 8011,ctrlText 8012,ctrlText 8013,ctrlText 8014,ctrlText 8015,ctrlText 8016]] call Rev_TFAR_fnc_saveScribble";
	onLoad = "if ((sunOrMoon < 1) AND (isNull objectParent player)) then {((_this select 0) displayCtrl 67676) ctrlSetTextColor [0.12,0.12,0.12,1];((_this select 0) displayCtrl 8000) ctrlSetTextColor [0.12,0.12,0.12,1]};call Rev_TFAR_fnc_getLwAlt;";
	controls[] = {"background","Rev_list","Rev_fr_1","Rev_fr_2","Rev_fr_3","Rev_fr_4","Rev_fr_5","Rev_fr_6","Rev_fr_7","Rev_fr_8","Rev_desc_1","Rev_desc_2","Rev_desc_3","Rev_desc_4","Rev_desc_5","Rev_desc_6","Rev_desc_7","Rev_desc_8","Rev_alt_1","Rev_alt_2","Rev_alt_3","Rev_alt_4","Rev_alt_5","Rev_alt_6","Rev_alt_7","Rev_alt_8","channel_edit","edit","enter","clear","increase_volume","stereo","channel_01","channel_02","channel_03","channel_04","channel_05","channel_06","channel_07","channel_08","channel_09","additional","speakers","channel_Switch"};
	controlsBackground[] = {};
	class background: RscBackPicture
	{
		idc = 67676;
		text = "\z\tfar\addons\backpacks\anarc210\ui\anarc210.paa";
		x = "0.0880156 * safezoneW + safezoneX";
		y = "-0.1677 * safezoneH + safezoneY";
		w = "0.634594 * safezoneW";
		h = "1.10205 * safezoneH";
		moving = 1;
	};
	class Rev_list: background
	{
		idc=8000;
		x = TFAR_notebook_X + TFAR_notebook_W * 0.75;
		y = TFAR_notebook_Y;
		w = TFAR_notebook_W;
		h = TFAR_notebook_H;
		text="\Reeveli_TFAR_Scribbles\notebook\Rev_notebook_7.paa";
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_210',false]);";
	};
	class Rev_fr_1: RscText
	{
		idc = 8001;
		text = "";
		font = "Caveat";
		sizeEx = TFAR_notebook_H * 0.03;	
		colorText[] = {0,0,0,1};
		shadow = 0;
		x = TFAR_notebook_X + TFAR_notebook_W * (0.75 + 0.38);
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.337;
		w = TFAR_notebook_W * 0.08;
		h = TFAR_notebook_H * 0.03;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_210',false]); [1,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_2: Rev_fr_1
	{
		idc = 8002;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.382;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_210',false]); [2,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_3: Rev_fr_1
	{
		idc = 8003;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.427;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_210',false]); [3,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_4: Rev_fr_1
	{
		idc = 8004;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.472;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_210',false]); [4,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_5: Rev_fr_1
	{
		idc = 8005;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.512;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_210',false]); [5,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_6: Rev_fr_1
	{
		idc = 8006;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.557;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_210',false]); [6,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_7: Rev_fr_1
	{
		idc = 8007;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.602;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_210',false]); [7,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_8: Rev_fr_1
	{
		idc = 8008;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.647;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_210',false]); [8,_control] call Rev_TFAR_fnc_getLwFrq;";
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
		x = TFAR_notebook_X + TFAR_notebook_W * (0.75 + 0.465);
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.337;
		w = TFAR_notebook_W * 0.15;
		h = TFAR_notebook_H * 0.03;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_210',false]);[TF_lr_dialog_radio # 0, 1, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_2: Rev_desc_1
	{
		idc = 8010;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.382;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_210',false]);[TF_lr_dialog_radio # 0, 2, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_3: Rev_desc_1
	{
		idc = 8011;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.427;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_210',false]);[TF_lr_dialog_radio # 0, 3, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_4: Rev_desc_1
	{
		idc = 8012;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.472;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_210',false]);[TF_lr_dialog_radio # 0, 4, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_5: Rev_desc_1
	{
		idc = 8013;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.512;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_210',false]);[TF_lr_dialog_radio # 0, 5, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_6: Rev_desc_1
	{
		idc = 8014;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.557;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_210',false]);[TF_lr_dialog_radio # 0, 6, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_7: Rev_desc_1
	{
		idc = 8015;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.602;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_210',false]);[TF_lr_dialog_radio # 0, 7, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_8: Rev_desc_1
	{
		idc = 8016;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.647;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_210',false]);[TF_lr_dialog_radio # 0, 8, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_alt_1: Rev_fr_1
	{
		idc=8020;
		text = "";
		font = "Caveat";
		sizeEx = TFAR_notebook_H * 0.03;	
		colorText[] = {0,0,0,1};
		shadow = 0;
		x = TFAR_notebook_X + TFAR_notebook_W * (0.75 + 0.624);
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.337;
		w = TFAR_notebook_W * 0.04;
		h = TFAR_notebook_H * 0.03;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_210',false]);";
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
	class channel_edit: RscEditLCD
	{
		idc = 1411;
		text = "";
		x = "0.360781 * safezoneW + safezoneX";
		y = "0.2305 * safezoneH + safezoneY";
		w = "0.0485625 * safezoneW";
		h = "0.0658147 * safezoneH";
		colorBackground[] = {0,0,0,0};
		colorText[] = {1,0.5,0,1};
		font = "TFAR_font_segments";
		shadow = 1;
		sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 32) * 1.2)";
		tooltip = "Current channel";
		canModify = 0;
	};
	class edit: RscEditLCD
	{
		idc = 1410;
		text = "";
		x = "0.4093435 * safezoneW + safezoneX";
		y = "0.2305 * safezoneH + safezoneY";
		w = "0.0585934 * safezoneW";
		h = "0.0682 * safezoneH";
		colorBackground[] = {0,0,0,0};
		colorText[] = {1,0.5,0,1};
		font = "TFAR_font_segments";
		shadow = 1;
		sizeEx = "(((((safezoneW / safezoneH) min 1.2) / 1.2) / 32) * 1.2)";
		tooltip = "Current frequency";
		canModify = 1;
		onKeyUp = "if (_this select 1 in [28,156]) then { [((ctrlParent (_this select 0))) displayCtrl 1410] call TFAR_backpacks_fnc_onButtonClick_Enter; private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;};";
		onLoad = "params ['_control','_config']; ctrlSetFocus _control";
	};
	class enter: HiddenButton
	{
		idc = 3552;
		x = "0.490203 * safezoneW + safezoneX";
		y = "0.3394 * safezoneH + safezoneY";
		w = "0.03 * safezoneW";
		h = "0.05 * safezoneH";
		tooltip = "Set frequency";
		onButtonClick = "[((ctrlParent (_this select 0))) displayCtrl 1410] call TFAR_backpacks_fnc_onButtonClick_Enter;private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;";
		action = "";
	};
	class clear: HiddenButton
	{
		idc = 3553;
		x = "0.354078 * safezoneW + safezoneX";
		y = "0.522 * safezoneH + safezoneY";
		w = "0.03 * safezoneW";
		h = "0.05 * safezoneH";
		tooltip = "Clear frequency";
		action = "ctrlSetText [1410,'']; ctrlSetFocus ((findDisplay 8423) displayCtrl 1410);";
	};
	class increase_volume: HiddenRotator
	{
		idc = 3556;
		x = "0.539187 * safezoneW + safezoneX";
		y = "0.5176 * safezoneH + safezoneY";
		w = "0.04 * safezoneW";
		h = "0.06 * safezoneH";
		tooltip = "Decrease volume | Increase volume";
		onMouseButtonDown = "[_this select 1,true] call TFAR_fnc_setVolumeViaDialog;";
	};
	class stereo: HiddenButton
	{
		idc = 3557;
		x = "0.444828 * safezoneW + safezoneX";
		y = "0.5253 * safezoneH + safezoneY";
		w = "0.03 * safezoneW";
		h = "0.05 * safezoneH";
		action = "[TF_lr_dialog_radio,((TF_lr_dialog_radio call TFAR_fnc_getCurrentLrStereo) + 1) mod 3] call TFAR_fnc_setLrStereo; [TF_lr_dialog_radio] call TFAR_fnc_showRadioVolume;";
		tooltip = "Stereo settings";
	};
	class channel_01: HiddenButton
	{
		idc = 3558;
		x = "0.353562 * safezoneW + safezoneX";
		y = "0.3394 * safezoneH + safezoneY";
		w = "0.0335156 * safezoneW";
		h = "0.0484 * safezoneH";
		action = "[TF_lr_dialog_radio, 0] call TFAR_fnc_setLrChannel;[""CH%1""] call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 1";
	};
	class channel_02: HiddenButton
	{
		idc = 3559;
		x = "0.399453 * safezoneW + safezoneX";
		y = "0.3416 * safezoneH + safezoneY";
		w = "0.0335156 * safezoneW";
		h = "0.0484 * safezoneH";
		action = "[TF_lr_dialog_radio, 1] call TFAR_fnc_setLrChannel;[""CH%1""] call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 2";
	};
	class channel_03: HiddenButton
	{
		idc = 3560;
		x = "0.443797 * safezoneW + safezoneX";
		y = "0.3416 * safezoneH + safezoneY";
		w = "0.0335156 * safezoneW";
		h = "0.0484 * safezoneH";
		action = "[TF_lr_dialog_radio, 2] call TFAR_fnc_setLrChannel;[""CH%1""] call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 3";
	};
	class channel_04: HiddenButton
	{
		idc = 3561;
		x = "0.353047 * safezoneW + safezoneX";
		y = "0.4032 * safezoneH + safezoneY";
		w = "0.0335156 * safezoneW";
		h = "0.0484 * safezoneH";
		action = "[TF_lr_dialog_radio, 3] call TFAR_fnc_setLrChannel;[""CH%1""] call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 4";
	};
	class channel_05: HiddenButton
	{
		idc = 3562;
		x = "0.397906 * safezoneW + safezoneX";
		y = "0.4021 * safezoneH + safezoneY";
		w = "0.0335156 * safezoneW";
		h = "0.0484 * safezoneH";
		action = "[TF_lr_dialog_radio, 4] call TFAR_fnc_setLrChannel;[""CH%1""] call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 5";
	};
	class channel_06: HiddenButton
	{
		idc = 3563;
		x = "0.443281 * safezoneW + safezoneX";
		y = "0.3999 * safezoneH + safezoneY";
		w = "0.0335156 * safezoneW";
		h = "0.0484 * safezoneH";
		action = "[TF_lr_dialog_radio, 5] call TFAR_fnc_setLrChannel;[""CH%1""] call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 6";
	};
	class channel_07: HiddenButton
	{
		idc = 3564;
		x = "0.353562 * safezoneW + safezoneX";
		y = "0.4637 * safezoneH + safezoneY";
		w = "0.0335156 * safezoneW";
		h = "0.0484 * safezoneH";
		action = "[TF_lr_dialog_radio, 6] call TFAR_fnc_setLrChannel;[""CH%1""] call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 7";
	};
	class channel_08: HiddenButton
	{
		idc = 3565;
		x = "0.398422 * safezoneW + safezoneX";
		y = "0.4659 * safezoneH + safezoneY";
		w = "0.0335156 * safezoneW";
		h = "0.0484 * safezoneH";
		action = "[TF_lr_dialog_radio, 7] call TFAR_fnc_setLrChannel;[""CH%1""] call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 8";
	};
	class channel_09: HiddenButton
	{
		idc = 3566;
		x = "0.442766 * safezoneW + safezoneX";
		y = "0.4659 * safezoneH + safezoneY";
		w = "0.0335156 * safezoneW";
		h = "0.0484 * safezoneH";
		action = "[TF_lr_dialog_radio, 8] call TFAR_fnc_setLrChannel;[""CH%1""] call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 9";
	};
	class channel_Switch: HiddenRotator
	{
		idc = 3554;
		x = "0.245797 * safezoneW + safezoneX";
		y = "0.2547 * safezoneH + safezoneY";
		w = "0.0510469 * safezoneW";
		h = "0.0957 * safezoneH";
		tooltip = "Previous channel | Next channel";
		onMouseButtonDown = "[_this select 1, true] call TFAR_fnc_setChannelViaDialog;";
	};
	class additional: HiddenButton
	{
		idc = 12345;
		x = "0.486594 * safezoneW + safezoneX";
		y = "0.4021 * safezoneH + safezoneY";
		w = "0.0367463 * safezoneW";
		h = "0.0462103 * safezoneH";
		tooltip = "Set additional channel";
		action = "[TF_lr_dialog_radio,TF_lr_dialog_radio call TFAR_fnc_getLrChannel] call TFAR_fnc_setAdditionalLrChannel;call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo; call Rev_TFAR_fnc_getLwAlt;";
	};
	class speakers: HiddenButton
	{
		idc = 123456;
		x = "0.398422 * safezoneW + safezoneX";
		y = "0.5231 * safezoneH + safezoneY";
		w = "0.0304219 * safezoneW";
		h = "0.0495 * safezoneH";
		tooltip = "Speakers";
		action = "playSound 'TFAR_rotatorPush';TF_lr_dialog_radio call TFAR_fnc_setLrSpeakers;[TF_lr_dialog_radio] call TFAR_fnc_showRadioSpeakers";
	};
};