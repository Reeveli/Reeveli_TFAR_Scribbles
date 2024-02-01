/*
 * Author: Reeveli
 * Part of Reeveli's TFAR Scribbles.
 * Function to create CBA addon options.
 * Called an extended preinit function fron mod config.
 *
 * Arguments: NONE
 *
 * Return Value: NONE
 *
1.2
  Added settings for default side scribbles
1.1
  Added proper function header
1.0.1
  Fixed typo in Radio settings saving -addon option

*/
#define SCRIBBLE_SETTINGS "TFAR Scribbles"

//General settings
[
  "Rev_TFAR_radioSettings"
  ,"CHECKBOX"
  ,["Radio settings saving","When enabled radio settings are kept saved and restored when after respawn and exiting arsenal"]
  ,[SCRIBBLE_SETTINGS,"General Settings"]
  ,true
  ,1
  ,{}
  ,true
] call CBA_fnc_addSetting;

[
  "Rev_TFAR_saveScribbles"
  ,"CHECKBOX"
  ,["Scribble saving","When enabled radio scribbles are kept saved and restored when after respawn and exiting arsenal"]
  ,[SCRIBBLE_SETTINGS,"General Settings"]
  ,true
  ,1
  ,{}
  ,true
] call CBA_fnc_addSetting;


//Starting sribbles
//Blufor
[
  "Rev_TFAR_settings_SR_B"
  ,"EDITBOX"
  ,["Starting BLUFOR SR-scribbles","Default starting SR scribbles for blufor, e.g. Text1,Text2,Text3. Unit MUST HAVE RADIO in inventory for setting to take effect"]
  ,[SCRIBBLE_SETTINGS,"General Settings"]
  ,""
  ,1
  ,{}
  ,true
] call CBA_fnc_addSetting;
[
  "Rev_TFAR_settings_LR_B"
  ,"EDITBOX"
  ,["Starting BLUFOR LR-scribbles","Default starting LR scribbles for blufor, e.g. Text1,Text2,Text3. Unit MUST HAVE RADIO in inventory for setting to take effect"]
  ,[SCRIBBLE_SETTINGS,"General Settings"]
  ,""
  ,1
  ,{}
  ,true
] call CBA_fnc_addSetting;

//Redfor
[
  "Rev_TFAR_settings_SR_O"
  ,"EDITBOX"
  ,["Starting OPFOR SR-scribbles","Default starting SR scribbles for opfor, e.g. Text1,Text2,Text3. Unit MUST HAVE RADIO in inventory for setting to take effect"]
  ,[SCRIBBLE_SETTINGS,"General Settings"]
  ,""
  ,1
  ,{}
  ,true
] call CBA_fnc_addSetting;
[
  "Rev_TFAR_settings_LR_O"
  ,"EDITBOX"
  ,["Starting OPFOR LR-scribbles","Default starting LR scribbles for opfor, e.g. Text1,Text2,Text3. Unit MUST HAVE RADIO in inventory for setting to take effect"]
  ,[SCRIBBLE_SETTINGS,"General Settings"]
  ,""
  ,1
  ,{}
  ,true
] call CBA_fnc_addSetting;

//Indfor
[
  "Rev_TFAR_settings_SR_I"
  ,"EDITBOX"
  ,["Starting INDFOR SR-scribbles","Default starting SR scribbles for indfor, e.g. Text1,Text2,Text3. Unit MUST HAVE RADIO in inventory for setting to take effect"]
  ,[SCRIBBLE_SETTINGS,"General Settings"]
  ,""
  ,1
  ,{}
  ,true
] call CBA_fnc_addSetting;
[
  "Rev_TFAR_settings_LR_I"
  ,"EDITBOX"
  ,["Starting INDFOR LR-scribbles","Default starting LR scribbles for indfor, e.g. Text1,Text2,Text3. Unit MUST HAVE RADIO in inventory for setting to take effect"]
  ,[SCRIBBLE_SETTINGS,"General Settings"]
  ,""
  ,1
  ,{}
  ,true
] call CBA_fnc_addSetting;


//Handhelds
//ANPRC 148
[
  "Rev_TFAR_148"
  ,"CHECKBOX"
  ,["AN/PRC-148 JEM","Enable scribbles for ANPRC 148"]
  ,[SCRIBBLE_SETTINGS,"Handheld Radios"]
  ,true
  ,1
  ,{}
  ,false
] call CBA_fnc_addSetting;

//ANPRC 152
[
  "Rev_TFAR_152"
  ,"CHECKBOX"
  ,["AN/PRC-152","Enable scribbles for ANPRC 152"]
  ,[SCRIBBLE_SETTINGS,"Handheld Radios"]
  ,true
  ,1
  ,{}
  ,false
] call CBA_fnc_addSetting;

//FADAK
[
  "Rev_TFAR_FADAK"
  ,"CHECKBOX"
  ,["FADAK","Enable scribbles for FADAK"]
  ,[SCRIBBLE_SETTINGS,"Handheld Radios"]
  ,true
  ,1
  ,{}
  ,false
] call CBA_fnc_addSetting;


//Backpacks
//ANARC 164
[
  "Rev_TFAR_164"
  ,"CHECKBOX"
  ,["AN/ARC-164","Enable scribbles for ANARC 164"]
  ,[SCRIBBLE_SETTINGS,"Long Wave Radios"]
  ,true
  ,1
  ,{}
  ,false
] call CBA_fnc_addSetting;
//ANARC 210
[
  "Rev_TFAR_210"
  ,"CHECKBOX"
  ,["AN/ARC-210","Enable scribbles for ANARC 210"]
  ,[SCRIBBLE_SETTINGS,"Long Wave Radios"]
  ,true
  ,1
  ,{}
  ,false
] call CBA_fnc_addSetting;
//ANPRC 155
[
  "Rev_TFAR_155"
  ,"CHECKBOX"
  ,["AN/PRC-155 variants","Enable scribbles for ANPRC 155 variants"]
  ,[SCRIBBLE_SETTINGS,"Long Wave Radios"]
  ,true
  ,1
  ,{}
  ,false
] call CBA_fnc_addSetting;
//Bussole
[
  "Rev_TFAR_bussole"
  ,"CHECKBOX"
  ,["Assault Pack Bussole","Enable scribbles for Assault Pack Bussole"]
  ,[SCRIBBLE_SETTINGS,"Long Wave Radios"]
  ,true
  ,1
  ,{}
  ,false
] call CBA_fnc_addSetting;
//RT 1523G
[
  "Rev_TFAR_rt1523g"
  ,"CHECKBOX"
  ,["RT-1523G variants","Enable scribbles for all RT-1523G variants"]
  ,[SCRIBBLE_SETTINGS,"Long Wave Radios"]
  ,true
  ,1
  ,{}
  ,false
] call CBA_fnc_addSetting;
//MR3000
[
  "Rev_TFAR_mr3000"
  ,"CHECKBOX"
  ,["MR3000 variants","Enable scribbles for all MR3000 variants"]
  ,[SCRIBBLE_SETTINGS,"Long Wave Radios"]
  ,true
  ,1
  ,{}
  ,false
] call CBA_fnc_addSetting;
//MR6000L
[
  "Rev_TFAR_mr6000l"
  ,"CHECKBOX"
  ,["MR6000L","Enable scribbles for MR6000L"]
  ,[SCRIBBLE_SETTINGS,"Long Wave Radios"]
  ,true
  ,1
  ,{}
  ,false
] call CBA_fnc_addSetting;