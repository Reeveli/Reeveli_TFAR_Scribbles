/*
 * Author: Reeveli
 * Part of Reeveli's TFAR Scribbles.
 * UI for RT-1523G.

2.0 Update
	New UI background image
	New dynamic controls for showing alt channel
		Added function call to alt channel button and onLoad EH for new alt channel functionality
*/


//Notebook x, y, w, h in addon common defines

class rt1523g_radio_dialog
{
	idd = 1666;
	movingEnable = 1;
	controls[] = {"background","Rev_list","Rev_fr_1","Rev_fr_2","Rev_fr_3","Rev_fr_4","Rev_fr_5","Rev_fr_6","Rev_fr_7","Rev_fr_8","Rev_desc_1","Rev_desc_2","Rev_desc_3","Rev_desc_4","Rev_desc_5","Rev_desc_6","Rev_desc_7","Rev_desc_8","Rev_alt_1","Rev_alt_2","Rev_alt_3","Rev_alt_4","Rev_alt_5","Rev_alt_6","Rev_alt_7","Rev_alt_8","enter","edit","channel_edit","clear","channel01","channel02","channel03","channel04","channel05","channel06","channel07","channel08","channel09","increase_volume","decrease_volume","stereo","additional","speakers"};
	controlsBackground[] = {};
	objects[] = {};
	onUnload = "['OnRadioOpen', [player, TF_lr_dialog_radio, true, 'rt1523g_radio_dialog', false]] call TFAR_fnc_fireEventHandlers;[TF_lr_dialog_radio # 0, [ctrlText 8009,ctrlText 8010,ctrlText 8011,ctrlText 8012,ctrlText 8013,ctrlText 8014,ctrlText 8015,ctrlText 8016]] call Rev_TFAR_fnc_saveScribble";
	onLoad = "if (sunOrMoon < 0.2) then {((_this select 0) displayCtrl 67676) ctrlSetText '\z\tfar\addons\backpacks\rt1523g\ui\rt1523g_n.paa';((_this select 0) displayCtrl 8000) ctrlSetTextColor [0.12,0.12,0.12,1]};call Rev_TFAR_fnc_getLwAlt;";
	class background: RscBackPicture
	{
		idc = 67676;
		text = "\z\tfar\addons\backpacks\rt1523g\ui\rt1523g.paa";
		x = "0.0935937 * safezoneW + safezoneX";
		y = "0.0252042 * safezoneH + safezoneY";
		w = "0.510056 * safezoneW";
		h = "0.942975 * safezoneH";
		moving = 1;
	};
	class Rev_list: background
	{
		idc=8000;
		x = TFAR_notebook_X + TFAR_notebook_W * 0.75;
		y = TFAR_notebook_Y;
		w = TFAR_notebook_W;
		h = TFAR_notebook_H;
		text="\Reeveli_TFAR_Scribbles\notebook\Rev_notebook_6.paa";
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_rt1523g',false]);";
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
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_rt1523g',false]); [1,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_2: Rev_fr_1
	{
		idc = 8002;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.382;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_rt1523g',false]); [2,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_3: Rev_fr_1
	{
		idc = 8003;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.427;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_rt1523g',false]); [3,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_4: Rev_fr_1
	{
		idc = 8004;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.472;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_rt1523g',false]); [4,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_5: Rev_fr_1
	{
		idc = 8005;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.512;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_rt1523g',false]); [5,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_6: Rev_fr_1
	{
		idc = 8006;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.557;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_rt1523g',false]); [6,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_7: Rev_fr_1
	{
		idc = 8007;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.602;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_rt1523g',false]); [7,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_8: Rev_fr_1
	{
		idc = 8008;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.647;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_rt1523g',false]); [8,_control] call Rev_TFAR_fnc_getLwFrq;";
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
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_rt1523g',false]);[TF_lr_dialog_radio # 0, 1, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_2: Rev_desc_1
	{
		idc = 8010;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.382;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_rt1523g',false]);[TF_lr_dialog_radio # 0, 2, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_3: Rev_desc_1
	{
		idc = 8011;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.427;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_rt1523g',false]);[TF_lr_dialog_radio # 0, 3, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_4: Rev_desc_1
	{
		idc = 8012;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.472;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_rt1523g',false]);[TF_lr_dialog_radio # 0, 4, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_5: Rev_desc_1
	{
		idc = 8013;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.512;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_rt1523g',false]);[TF_lr_dialog_radio # 0, 5, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_6: Rev_desc_1
	{
		idc = 8014;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.557;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_rt1523g',false]);[TF_lr_dialog_radio # 0, 6, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_7: Rev_desc_1
	{
		idc = 8015;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.602;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_rt1523g',false]);[TF_lr_dialog_radio # 0, 7, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_8: Rev_desc_1
	{
		idc = 8016;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.647;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_rt1523g',false]);[TF_lr_dialog_radio # 0, 8, _control] call Rev_TFAR_fnc_loadScribble;";
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
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_rt1523g',false]);";
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
	class edit: RscEditLCD
	{
		moving = 1;
		idc = 1410;
		x = "0.356037 * safezoneW + safezoneX";
		y = "0.363875 * safezoneH + safezoneY";
		w = "0.0600188 * safezoneW";
		h = "0.055 * safezoneH";
		font = "TFAR_font_dots";
		shadow = 2;
		tooltip = "Current frequency";
		canModify = 1;
		onKeyUp = "if (_this select 1 in [28,156]) then { [((ctrlParent (_this select 0))) displayCtrl 1410] call TFAR_backpacks_fnc_onButtonClick_Enter;private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;};";
		onLoad = "params ['_control','_config']; ctrlSetFocus _control";
	};
	class channel_edit: RscEditLCD
	{
		moving = 1;
		idc = 1411;
		x = "0.29354 * safezoneW + safezoneX";
		y = "0.3636 * safezoneH + safezoneY";
		w = "0.0443218 * safezoneW";
		h = "0.05335 * safezoneH";
		font = "TFAR_font_dots";
		shadow = 2;
		tooltip = "Current channel";
		canModify = 0;
	};
	class clear: HiddenButton
	{
		idc = 1611;
		x = "0.263806 * safezoneW + safezoneX";
		y = "0.623256 * safezoneH + safezoneY";
		w = "0.036975 * safezoneW";
		h = "0.0403769 * safezoneH";
		tooltip = "Clear frequency";
		action = "ctrlSetText [1410,'']; ctrlSetFocus ((findDisplay 1666) displayCtrl 1410);";
	};
	class enter: HiddenButton
	{
		idc = 1610;
		x = "0.400869 * safezoneW + safezoneX";
		y = "0.470249 * safezoneH + safezoneY";
		w = "0.0357 * safezoneW";
		h = "0.0378267 * safezoneH";
		tooltip = "Set frequency";
		onButtonClick = "[((ctrlParent (_this select 0))) displayCtrl 1410] call TFAR_backpacks_fnc_onButtonClick_Enter; private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;";
		action = "";
	};
	class channel01: HiddenButton
	{
		idc = 1701;
		x = "0.266994 * safezoneW + safezoneX";
		y = "0.472799 * safezoneH + safezoneY";
		w = "0.0306 * safezoneW";
		h = "0.0378267 * safezoneH";
		action = "[TF_lr_dialog_radio, 0] call TFAR_fnc_setLrChannel;call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 1";
	};
	class channel02: HiddenButton
	{
		idc = 1702;
		x = "0.310344 * safezoneW + safezoneX";
		y = "0.474499 * safezoneH + safezoneY";
		w = "0.0334688 * safezoneW";
		h = "0.0365517 * safezoneH";
		action = "[TF_lr_dialog_radio, 1] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 2";
	};
	class channel03: HiddenButton
	{
		idc = 1703;
		x = "0.356881 * safezoneW + safezoneX";
		y = "0.475774 * safezoneH + safezoneY";
		w = "0.031875 * safezoneW";
		h = "0.0340016 * safezoneH";
		action = "[TF_lr_dialog_radio, 2] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 3";
	};
	class channel04: HiddenButton
	{
		idc = 1704;
		x = "0.266356 * safezoneW + safezoneX";
		y = "0.525076 * safezoneH + safezoneY";
		w = "0.0306 * safezoneW";
		h = "0.0314514 * safezoneH";
		action = "[TF_lr_dialog_radio, 3] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 4";
	};
	class channel05: HiddenButton
	{
		idc = 1705;
		x = "0.310344 * safezoneW + safezoneX";
		y = "0.525076 * safezoneH + safezoneY";
		w = "0.0328313 * safezoneW";
		h = "0.0340016 * safezoneH";
		action = "[TF_lr_dialog_radio, 4] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 5";
	};
	class channel06: HiddenButton
	{
		idc = 1706;
		x = "0.357519 * safezoneW + safezoneX";
		y = "0.525076 * safezoneH + safezoneY";
		w = "0.0306 * safezoneW";
		h = "0.0340016 * safezoneH";
		action = "[TF_lr_dialog_radio, 5] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 6";
	};
	class channel07: HiddenButton
	{
		idc = 1707;
		x = "0.266356 * safezoneW + safezoneX";
		y = "0.574378 * safezoneH + safezoneY";
		w = "0.0312375 * safezoneW";
		h = "0.0340016 * safezoneH";
		action = "[TF_lr_dialog_radio, 6] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 7";
	};
	class channel08: HiddenButton
	{
		idc = 1708;
		x = "0.311938 * safezoneW + safezoneX";
		y = "0.575653 * safezoneH + safezoneY";
		w = "0.0312375 * safezoneW";
		h = "0.0327265 * safezoneH";
		action = "[TF_lr_dialog_radio, 7] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 8";
	};
	class channel09: HiddenButton
	{
		idc = 1709;
		x = "0.358156 * safezoneW + safezoneX";
		y = "0.574378 * safezoneH + safezoneY";
		w = "0.0312375 * safezoneW";
		h = "0.0340016 * safezoneH";
		action = "[TF_lr_dialog_radio, 8] call TFAR_fnc_setLrChannel; call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 9";
	};
	class increase_volume: HiddenButton
	{
		idc = 1612;
		x = "0.4031 * safezoneW + safezoneX";
		y = "0.576079 * safezoneH + safezoneY";
		w = "0.0312375 * safezoneW";
		h = "0.0327265 * safezoneH";
		action = "[1, true] call TFAR_fnc_setVolumeViaDialog;";
		tooltip = "Increase volume";
	};
	class decrease_volume: HiddenButton
	{
		idc = 1613;
		x = "0.4031 * safezoneW + safezoneX";
		y = "0.628356 * safezoneH + safezoneY";
		w = "0.0302813 * safezoneW";
		h = "0.0323015 * safezoneH";
		action = "[0, true] call TFAR_fnc_setVolumeViaDialog;";
		tooltip = "Decrease volume";
	};
	class stereo: HiddenButton
	{
		idc = 1710;
		x = "0.357725 * safezoneW + safezoneX";
		y = "0.627078 * safezoneH + safezoneY";
		w = "0.030975 * safezoneW";
		h = "0.0318571 * safezoneH";
		action = "[TF_lr_dialog_radio,((TF_lr_dialog_radio call TFAR_fnc_getCurrentLrStereo) + 1) mod 3] call TFAR_fnc_setLrStereo; [TF_lr_dialog_radio] call TFAR_fnc_showRadioVolume;";
		tooltip = "Stereo settings";
	};
	class additional: HiddenButton
	{
		idc = 12345;
		x = "0.40131 * safezoneW + safezoneX";
		y = "0.523805 * safezoneH + safezoneY";
		w = "0.035434 * safezoneW";
		h = "0.0385086 * safezoneH";
		tooltip = "Set additional channel";
		action = "[TF_lr_dialog_radio,TF_lr_dialog_radio call TFAR_fnc_getLrChannel] call TFAR_fnc_setAdditionalLrChannel; call TFAR_fnc_updateLRDialogToChannel; [TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo; call Rev_TFAR_fnc_getLwAlt;";
	};
	class speakers: HiddenButton
	{
		idc = 123456;
		x = "0.309932 * safezoneW + safezoneX";
		y = "0.622912 * safezoneH + safezoneY";
		w = "0.0366943 * safezoneW";
		h = "0.0420706 * safezoneH";
		tooltip = "Speakers";
		action = "TF_lr_dialog_radio call TFAR_fnc_setLrSpeakers;[TF_lr_dialog_radio] call TFAR_fnc_showRadioSpeakers;";
	};
};