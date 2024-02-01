/*
 * Author: Reeveli
 * Part of Reeveli's TFAR Scribbles.
 * UI for Assault Bussole.

2.0 Update
	New UI background image
	New dynamic controls for showing alt channel
		Added function call to alt channel button and onLoad EH for new alt channel functionality
*/


//Notebook x, y, w, h in addon common defines

class bussole_radio_dialog
{
	idd = 8666;
	movingEnable = 1;
	controls[] = {"background","Rev_list","Rev_fr_1","Rev_fr_2","Rev_fr_3","Rev_fr_4","Rev_fr_5","Rev_fr_6","Rev_fr_7","Rev_fr_8","Rev_desc_1","Rev_desc_2","Rev_desc_3","Rev_desc_4","Rev_desc_5","Rev_desc_6","Rev_desc_7","Rev_desc_8","Rev_alt_1","Rev_alt_2","Rev_alt_3","Rev_alt_4","Rev_alt_5","Rev_alt_6","Rev_alt_7","Rev_alt_8","enter","channel_edit","edit","clear","prev_channel","next_channel","volume_Switch","stereo","additional","speakers","channel_01","channel_02","channel_03","channel_04","channel_05","channel_06","channel_07","channel_08","channel_09"};
	controlsBackground[] = {};
	onUnload = "['OnRadioOpen', [player, TF_lr_dialog_radio, true, 'bussole_radio_dialog', false]] call TFAR_fnc_fireEventHandlers;[TF_lr_dialog_radio # 0, [ctrlText 8009,ctrlText 8010,ctrlText 8011,ctrlText 8012,ctrlText 8013,ctrlText 8014,ctrlText 8015,ctrlText 8016]] call Rev_TFAR_fnc_saveScribble";
	onLoad = "if(sunOrMoon < 0.2) then {((_this select 0) displayCtrl 67676) ctrlSetText '\z\tfar\addons\backpacks\bussole\ui\bussole_n.paa';((_this select 0) displayCtrl 8000) ctrlSetTextColor [0.12,0.12,0.12,1]};call Rev_TFAR_fnc_getLwAlt;";
	class background: RscBackPicture
	{
		idc = 67676;
		text = "\z\tfar\addons\backpacks\bussole\ui\bussole.paa";
		x = "0.0864688 * safezoneW + safezoneX";
		y = "-0.1182 * safezoneH + safezoneY";
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
		text="\Reeveli_TFAR_Scribbles\notebook\Rev_notebook_6.paa";
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_bussole',false]);";
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
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_bussole',false]); [1,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_2: Rev_fr_1
	{
		idc = 8002;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.382;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_bussole',false]); [2,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_3: Rev_fr_1
	{
		idc = 8003;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.427;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_bussole',false]); [3,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_4: Rev_fr_1
	{
		idc = 8004;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.472;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_bussole',false]); [4,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_5: Rev_fr_1
	{
		idc = 8005;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.512;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_bussole',false]); [5,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_6: Rev_fr_1
	{
		idc = 8006;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.557;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_bussole',false]); [6,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_7: Rev_fr_1
	{
		idc = 8007;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.602;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_bussole',false]); [7,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_8: Rev_fr_1
	{
		idc = 8008;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.647;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_bussole',false]); [8,_control] call Rev_TFAR_fnc_getLwFrq;";
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
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_bussole',false]);[TF_lr_dialog_radio # 0, 1, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_2: Rev_desc_1
	{
		idc = 8010;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.382;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_bussole',false]);[TF_lr_dialog_radio # 0, 2, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_3: Rev_desc_1
	{
		idc = 8011;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.427;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_bussole',false]);[TF_lr_dialog_radio # 0, 3, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_4: Rev_desc_1
	{
		idc = 8012;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.472;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_bussole',false]);[TF_lr_dialog_radio # 0, 4, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_5: Rev_desc_1
	{
		idc = 8013;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.512;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_bussole',false]);[TF_lr_dialog_radio # 0, 5, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_6: Rev_desc_1
	{
		idc = 8014;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.557;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_bussole',false]);[TF_lr_dialog_radio # 0, 6, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_7: Rev_desc_1
	{
		idc = 8015;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.602;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_bussole',false]);[TF_lr_dialog_radio # 0, 7, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_8: Rev_desc_1
	{
		idc = 8016;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.647;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_bussole',false]);[TF_lr_dialog_radio # 0, 8, _control] call Rev_TFAR_fnc_loadScribble;";
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
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_bussole',false]);";
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
		x = "0.324781 * safezoneW + safezoneX";
		y = "0.291915 * safezoneH + safezoneY";
		w = "0.05775 * safezoneW";
		h = "0.1155 * safezoneH";
		font = "TFAR_font_segments";
		tooltip = "Current channel";
		moving = 1;
		canModify = 0;
		sizeEx = 0.06;
	};
	class edit: RscEditLCD
	{
		idc = 1410;
		x = "0.375218 * safezoneW + safezoneX";
		y = "0.2921 * safezoneH + safezoneY";
		w = "0.0546562 * safezoneW";
		h = "0.1155 * safezoneH";
		font = "TFAR_font_segments";
		tooltip = "Current frequency";
		moving = 1;
		canModify = 1;
		sizeEx = 0.06;
		onKeyUp = "if (_this select 1 in [28,156]) then { [((ctrlParent (_this select 0))) displayCtrl 1410] call TFAR_backpacks_fnc_onButtonClick_Enter;private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;};";
		onLoad = "params ['_control','_config']; ctrlSetFocus _control";
	};
	class enter: HiddenButton
	{
		idc = 8667;
		x = "0.469578 * safezoneW + safezoneX";
		y = "0.5616 * safezoneH + safezoneY";
		w = "0.0211406 * safezoneW";
		h = "0.0286 * safezoneH";
		tooltip = "Set frequency";
		onButtonClick = "[((ctrlParent (_this select 0))) displayCtrl 1410] call TFAR_backpacks_fnc_onButtonClick_Enter;private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;";
		action = "";
	};
	class clear: HiddenButton
	{
		idc = 8668;
		x = "0.470094 * safezoneW + safezoneX";
		y = "0.5209 * safezoneH + safezoneY";
		w = "0.020625 * safezoneW";
		h = "0.0286 * safezoneH";
		tooltip = "Clear frequency";
		action = "ctrlSetText [1410,'']; ctrlSetFocus ((findDisplay 8666) displayCtrl 1410);";
	};
	class prev_channel: HiddenButton
	{
		idc = 8669;
		x = "0.440187 * safezoneW + safezoneX";
		y = "0.5627 * safezoneH + safezoneY";
		w = "0.0216562 * safezoneW";
		h = "0.0275 * safezoneH";
		tooltip = "Previous channel";
		action = "[0, true] call TFAR_fnc_setChannelViaDialog;";
	};
	class next_channel: HiddenButton
	{
		idc = 8670;
		x = "0.439672 * safezoneW + safezoneX";
		y = "0.5209 * safezoneH + safezoneY";
		w = "0.0226875 * safezoneW";
		h = "0.0275 * safezoneH";
		tooltip = "Next channel";
		action = "[1, true] call TFAR_fnc_setChannelViaDialog;";
	};
	class volume_Switch: HiddenRotator
	{
		idc = 8671;
		x = "0.315922 * safezoneW + safezoneX";
		y = "0.5209 * safezoneH + safezoneY";
		w = "0.0216562 * safezoneW";
		h = "0.0286 * safezoneH";
		tooltip = "Decrease volume | Increase volume";
		onMouseButtonDown = "[_this select 1, true] call TFAR_fnc_setVolumeViaDialog;";
	};
	class stereo: HiddenButton
	{
		idc = 8672;
		x = "0.315922 * safezoneW + safezoneX";
		y = "0.5605 * safezoneH + safezoneY";
		w = "0.0211406 * safezoneW";
		h = "0.0308 * safezoneH";
		action = "[TF_lr_dialog_radio,((TF_lr_dialog_radio call TFAR_fnc_getCurrentLrStereo) + 1) mod 3] call TFAR_fnc_setLrStereo; [TF_lr_dialog_radio] call TFAR_fnc_showRadioVolume;";
		tooltip = "Stereo settings";
	};
	class additional: HiddenButton
	{
		idc = 12345;
		x = "0.469062 * safezoneW + safezoneX";
		y = "0.4747 * safezoneH + safezoneY";
		w = "0.0216562 * safezoneW";
		h = "0.0297 * safezoneH";
		tooltip = "Set additional channel";
		action = "[TF_lr_dialog_radio,TF_lr_dialog_radio call TFAR_fnc_getLrChannel] call TFAR_fnc_setAdditionalLrChannel; call TFAR_fnc_updateLRDialogToChannel; [TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo; call Rev_TFAR_fnc_getLwAlt;";
	};
	class speakers: HiddenButton
	{
		idc = 123456;
		x = "0.440187 * safezoneW + safezoneX";
		y = "0.4769 * safezoneH + safezoneY";
		w = "0.0216562 * safezoneW";
		h = "0.0275 * safezoneH";
		tooltip = "Speakers";
		action = "TF_lr_dialog_radio call TFAR_fnc_setLrSpeakers;[TF_lr_dialog_radio] call TFAR_fnc_showRadioSpeakers;";
	};
	class channel_01: HiddenButton
	{
		idc = 8673;
		x = "0.345828 * safezoneW + safezoneX";
		y = "0.4747 * safezoneH + safezoneY";
		w = "0.0216562 * safezoneW";
		h = "0.0297 * safezoneH";
		action = "[TF_lr_dialog_radio, 0] call TFAR_fnc_setLrChannel; [""CH%1""] call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 1";
	};
	class channel_02: HiddenButton
	{
		idc = 8674;
		x = "0.37625 * safezoneW + safezoneX";
		y = "0.4758 * safezoneH + safezoneY";
		w = "0.0216562 * safezoneW";
		h = "0.0297 * safezoneH";
		action = "[TF_lr_dialog_radio, 1] call TFAR_fnc_setLrChannel; [""CH%1""] call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 2";
	};
	class channel_03: HiddenButton
	{
		idc = 8675;
		x = "0.40925 * safezoneW + safezoneX";
		y = "0.4758 * safezoneH + safezoneY";
		w = "0.0216562 * safezoneW";
		h = "0.0297 * safezoneH";
		action = "[TF_lr_dialog_radio, 2] call TFAR_fnc_setLrChannel; [""PRE %1""] call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 3";
	};
	class channel_04: HiddenButton
	{
		idc = 8676;
		x = "0.345312 * safezoneW + safezoneX";
		y = "0.5198 * safezoneH + safezoneY";
		w = "0.0221719 * safezoneW";
		h = "0.0308 * safezoneH";
		action = "[TF_lr_dialog_radio, 3] call TFAR_fnc_setLrChannel; [""PRE %1""] call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 4";
	};
	class channel_05: HiddenButton
	{
		idc = 8677;
		x = "0.376766 * safezoneW + safezoneX";
		y = "0.5198 * safezoneH + safezoneY";
		w = "0.0216562 * safezoneW";
		h = "0.0297 * safezoneH";
		action = "[TF_lr_dialog_radio, 4] call TFAR_fnc_setLrChannel; [""PRE %1""] call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 5";
	};
	class channel_06: HiddenButton
	{
		idc = 8678;
		x = "0.40925 * safezoneW + safezoneX";
		y = "0.5198 * safezoneH + safezoneY";
		w = "0.0216562 * safezoneW";
		h = "0.0297 * safezoneH";
		action = "[TF_lr_dialog_radio, 5] call TFAR_fnc_setLrChannel; [""PRE %1""] call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 6";
	};
	class channel_07: HiddenButton
	{
		idc = 8679;
		x = "0.345828 * safezoneW + safezoneX";
		y = "0.5605 * safezoneH + safezoneY";
		w = "0.0216562 * safezoneW";
		h = "0.0297 * safezoneH";
		action = "[TF_lr_dialog_radio, 6] call TFAR_fnc_setLrChannel; [""PRE %1""] call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 7";
	};
	class channel_08: HiddenButton
	{
		idc = 8680;
		x = "0.37625 * safezoneW + safezoneX";
		y = "0.5605 * safezoneH + safezoneY";
		w = "0.0216562 * safezoneW";
		h = "0.0297 * safezoneH";
		action = "[TF_lr_dialog_radio, 7] call TFAR_fnc_setLrChannel; [""PRE %1""] call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 8";
	};
	class channel_09: HiddenButton
	{
		idc = 8681;
		x = "0.409766 * safezoneW + safezoneX";
		y = "0.5616 * safezoneH + safezoneY";
		w = "0.0216562 * safezoneW";
		h = "0.0297 * safezoneH";
		action = "[TF_lr_dialog_radio, 8] call TFAR_fnc_setLrChannel; [""PRE %1""] call TFAR_fnc_updateLRDialogToChannel;[TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo;";
		tooltip = "Channel 9";
	};
};