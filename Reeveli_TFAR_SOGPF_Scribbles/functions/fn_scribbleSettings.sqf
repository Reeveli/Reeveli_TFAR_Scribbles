/*
 * Author: Reeveli
 * Part of Reeveli's TFAR SOG:PF Scribbles.
 * Function to create CBA addon options.
 * Called an extended preinit function fron mod config.
 *
 * Arguments: NONE
 *
 * Return Value: NONE
 *
*/

#define SCRIBBLE_SETTINGS "TFAR Scribbles"

//Handhelds
//M252
[
  "Rev_TFAR_252"
  ,"CHECKBOX"
  ,["M252","Enable scribbles for Field telephone M252"]
  ,[SCRIBBLE_SETTINGS,"Handheld Radios"]
  ,true
  ,1
  ,{}
  ,false
] call CBA_fnc_addSetting;

//URC 10
[
  "Rev_TFAR_10"
  ,"CHECKBOX"
  ,["URC-10","Enable scribbles for URC 10"]
  ,[SCRIBBLE_SETTINGS,"Handheld Radios"]
  ,true
  ,1
  ,{}
  ,false
] call CBA_fnc_addSetting;


//Backpacks

//VRC12
[
  "Rev_TFAR_VRC12"
  ,"CHECKBOX"
  ,["AN/VRC-12","Enable scribbles for AN/VRC-12"]
  ,[SCRIBBLE_SETTINGS,"Long Wave Radios"]
  ,true
  ,1
  ,{}
  ,false
] call CBA_fnc_addSetting;

//PRC 77
[
  "Rev_TFAR_77"
  ,"CHECKBOX"
  ,["PRC-77","Enable scribbles for PRC 77"]
  ,[SCRIBBLE_SETTINGS,"Long Wave Radios"]
  ,true
  ,1
  ,{}
  ,false
] call CBA_fnc_addSetting;

//Type 102E
[
  "Rev_TFAR_102E"
  ,"CHECKBOX"
  ,["Type 102E","Enable scribbles for Type 102E"]
  ,[SCRIBBLE_SETTINGS,"Long Wave Radios"]
  ,true
  ,1
  ,{}
  ,false
] call CBA_fnc_addSetting;

//Type 884
[
  "Rev_TFAR_884"
  ,"CHECKBOX"
  ,["Type 884","Enable scribbles for Type 884"]
  ,[SCRIBBLE_SETTINGS,"Long Wave Radios"]
  ,true
  ,1
  ,{}
  ,false
] call CBA_fnc_addSetting;