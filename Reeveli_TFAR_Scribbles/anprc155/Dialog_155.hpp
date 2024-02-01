/*
 * Author: Reeveli
 * Part of Reeveli's TFAR Scribbles.
 * UI for ANPRC 155.

2.0 Update
	New UI background image
	New dynamic controls for showing alt channel
		Added function call to alt channel button and onLoad EH for new alt channel functionality
*/

//Notebook x, y, w, h in addon common defines
class anprc155_radio_dialog
{
	idd = 7666;
	movingEnable = 1;
	controls[] = {"background","Rev_list","Rev_fr_1","Rev_fr_2","Rev_fr_3","Rev_fr_4","Rev_fr_5","Rev_fr_6","Rev_fr_7","Rev_fr_8","Rev_desc_1","Rev_desc_2","Rev_desc_3","Rev_desc_4","Rev_desc_5","Rev_desc_6","Rev_desc_7","Rev_desc_8","Rev_alt_1","Rev_alt_2","Rev_alt_3","Rev_alt_4","Rev_alt_5","Rev_alt_6","Rev_alt_7","Rev_alt_8","enter","channel_edit","edit","clear","prev_channel","next_channel","volume_Switch","stereo","additional","speakers"};
	controlsBackground[] = {};
	onUnload = "['OnRadioOpen', [player, TF_lr_dialog_radio, true, 'anprc155_radio_dialog', false]] call TFAR_fnc_fireEventHandlers;[TF_lr_dialog_radio # 0, [ctrlText 8009,ctrlText 8010,ctrlText 8011,ctrlText 8012,ctrlText 8013,ctrlText 8014,ctrlText 8015,ctrlText 8016]] call Rev_TFAR_fnc_saveScribble";
	onLoad = "if(sunOrMoon < 0.2) then {((_this select 0) displayCtrl 67676) ctrlSetText '\z\tfar\addons\backpacks\anprc155\ui\155_n.paa';((_this select 0) displayCtrl 8000) ctrlSetTextColor [0.12,0.12,0.12,1]};call Rev_TFAR_fnc_getLwAlt;";
	class background: RscBackPicture
	{
		idc = 67676;
		text = "\z\tfar\addons\backpacks\anprc155\ui\155.paa";
		x = "0.0869844 * safezoneW + safezoneX";
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
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_155',false]);";
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
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_155',false]); [1,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_2: Rev_fr_1
	{
		idc = 8002;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.382;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_155',false]); [2,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_3: Rev_fr_1
	{
		idc = 8003;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.427;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_155',false]); [3,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_4: Rev_fr_1
	{
		idc = 8004;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.472;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_155',false]); [4,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_5: Rev_fr_1
	{
		idc = 8005;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.512;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_155',false]); [5,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_6: Rev_fr_1
	{
		idc = 8006;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.557;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_155',false]); [6,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_7: Rev_fr_1
	{
		idc = 8007;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.602;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_155',false]); [7,_control] call Rev_TFAR_fnc_getLwFrq;";
	};
	class Rev_fr_8: Rev_fr_1
	{
		idc = 8008;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.647;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_155',false]); [8,_control] call Rev_TFAR_fnc_getLwFrq;";
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
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_155',false]);[TF_lr_dialog_radio # 0, 1, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_2: Rev_desc_1
	{
		idc = 8010;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.382;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_155',false]);[TF_lr_dialog_radio # 0, 2, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_3: Rev_desc_1
	{
		idc = 8011;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.427;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_155',false]);[TF_lr_dialog_radio # 0, 3, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_4: Rev_desc_1
	{
		idc = 8012;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.472;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_155',false]);[TF_lr_dialog_radio # 0, 4, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_5: Rev_desc_1
	{
		idc = 8013;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.512;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_155',false]);[TF_lr_dialog_radio # 0, 5, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_6: Rev_desc_1
	{
		idc = 8014;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.557;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_155',false]);[TF_lr_dialog_radio # 0, 6, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_7: Rev_desc_1
	{
		idc = 8015;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.602;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_155',false]);[TF_lr_dialog_radio # 0, 7, _control] call Rev_TFAR_fnc_loadScribble;";
	};
	class Rev_desc_8: Rev_desc_1
	{
		idc = 8016;
		y = TFAR_notebook_Y + TFAR_notebook_H * 0.647;
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_155',false]);[TF_lr_dialog_radio # 0, 8, _control] call Rev_TFAR_fnc_loadScribble;";
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
		onLoad = "params ['_control','_config']; _control ctrlShow (missionnameSpace getvariable ['Rev_TFAR_155',false]);";
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
		x = "0.327 * safezoneW + safezoneX";
		y = "0.3416 * safezoneH + safezoneY";
		w = "0.0485625 * safezoneW";
		h = "0.0658147 * safezoneH";
		font = "TFAR_font_segments";
		tooltip = "Current channel";
		moving = 1;
		canModify = 0;
	};
	class edit: RscEditLCD
	{
		idc = 1410;
		x = "0.374187 * safezoneW + safezoneX";
		y = "0.3416 * safezoneH + safezoneY";
		w = "0.06 * safezoneW";
		h = "0.066 * safezoneH";
		font = "TFAR_font_segments";
		tooltip = "Current frequency";
		moving = 1;
		canModify = 1;
		onKeyUp = "if (_this select 1 in [28,156]) then { [((ctrlParent (_this select 0))) displayCtrl 1410] call TFAR_backpacks_fnc_onButtonClick_Enter;private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;};";
		onLoad = "params ['_control','_config']; ctrlSetFocus _control";
	};
	class enter: HiddenButton
	{
		idc = 3606;
		x = "0.4175 * safezoneW + safezoneX";
		y = "0.5066 * safezoneH + safezoneY";
		w = "0.0185625 * safezoneW";
		h = "0.0209 * safezoneH";
		tooltip = "Set frequency";
		onButtonClick = "[((ctrlParent (_this select 0))) displayCtrl 1410] call TFAR_backpacks_fnc_onButtonClick_Enter;private _channel = ((TF_lr_dialog_radio) call TFAR_fnc_getLrSettings) # 0; [_channel + 1, displayCtrl (8000 + _channel + 1)] call Rev_TFAR_fnc_getLwFrq;";
		action = "";
	};
	class clear: HiddenButton
	{
		idc = 3607;
		x = "0.408781 * safezoneW + safezoneX";
		y = "0.473394 * safezoneH + safezoneY";
		w = "0.0180469 * safezoneW";
		h = "0.0286 * safezoneH";
		tooltip = "Clear frequency";
		action = "ctrlSetText [1410,'']; ctrlSetFocus ((findDisplay 7666) displayCtrl 1410);";
	};
	class prev_channel: HiddenButton
	{
		idc = 3608;
		x = "0.362844 * safezoneW + safezoneX";
		y = "0.537808 * safezoneH + safezoneY";
		w = "0.02625 * safezoneW";
		h = "0.0294066 * safezoneH";
		tooltip = "Previous channel";
		action = "[0, true] call TFAR_fnc_setChannelViaDialog;";
	};
	class next_channel: HiddenButton
	{
		idc = 3609;
		x = "0.362844 * safezoneW + safezoneX";
		y = "0.470593 * safezoneH + safezoneY";
		w = "0.0249375 * safezoneW";
		h = "0.0280062 * safezoneH";
		tooltip = "Next channel";
		action = "[1, true] call TFAR_fnc_setChannelViaDialog;";
	};
	class volume_Switch: HiddenRotator
	{
		idc = 3610;
		x = "0.224656 * safezoneW + safezoneX";
		y = "0.2987 * safezoneH + safezoneY";
		w = "0.0458906 * safezoneW";
		h = "0.0836 * safezoneH";
		tooltip = "Decrease volume | Increase volume";
		onMouseButtonDown = "[_this select 1, true] call TFAR_fnc_setVolumeViaDialog;";
	};
	class stereo: HiddenButton
	{
		idc = 3611;
		x = "0.324687 * safezoneW + safezoneX";
		y = "0.5363 * safezoneH + safezoneY";
		w = "0.0180469 * safezoneW";
		h = "0.0275 * safezoneH";
		action = "[TF_lr_dialog_radio,((TF_lr_dialog_radio call TFAR_fnc_getCurrentLrStereo) + 1) mod 3] call TFAR_fnc_setLrStereo; [TF_lr_dialog_radio] call TFAR_fnc_showRadioVolume;";
		tooltip = "Stereo settings";
	};
	class additional: HiddenButton
	{
		idc = 12345;
		x = "0.315406 * safezoneW + safezoneX";
		y = "0.5055 * safezoneH + safezoneY";
		w = "0.0190781 * safezoneW";
		h = "0.0275 * safezoneH";
		tooltip = "Set additional channel";
		action = "[TF_lr_dialog_radio,TF_lr_dialog_radio call TFAR_fnc_getLrChannel] call TFAR_fnc_setAdditionalLrChannel; call TFAR_fnc_updateLRDialogToChannel; [TF_lr_dialog_radio, true] call TFAR_fnc_showRadioInfo; call Rev_TFAR_fnc_getLwAlt;";
	};
	class speakers: HiddenButton
	{
		idc = 123456;
		x = "0.408219 * safezoneW + safezoneX";
		y = "0.5374 * safezoneH + safezoneY";
		w = "0.0190781 * safezoneW";
		h = "0.0242 * safezoneH";
		tooltip = "Speakers";
		action = "TF_lr_dialog_radio call TFAR_fnc_setLrSpeakers;[TF_lr_dialog_radio] call TFAR_fnc_showRadioSpeakers;";
	};
};