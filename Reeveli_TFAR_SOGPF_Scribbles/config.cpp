class CfgPatches
{
	class Reeveli_TFAR_SOGPF_scribbles
	{
		requiredVersion=2.14;
		requiredAddons[]=
		{
			"loadorder_f_vietnam",
			"Reeveli_TFAR_scribbles"
		};
		author="Reeveli";
		authors[]= {"Reeveli"};		
		name = "TFAR SOGPF Scribbles";
		license = "https://www.bohemia.net/community/licenses/arma-public-license-share-alike";
		url = "https://www.youtube.com/@Reeveli";			
        version = 1.0;
        versionStr = "1.0.2";
        versionAr[] = {1, 0, 2};
		units[]={};
		weapons[]={};
		skipWhenMissingDependencies = 1;
	};
};


class Extended_PreInit_EventHandlers
{
	class Rev_TFAR_SOGPF_Settings {init = "call compile preprocessFileLineNumbers '\Reeveli_TFAR_SOGPF_Scribbles\functions\fn_scribbleSettings.sqf'";};
};


#include "defines.hpp"

//dialogs
#include "102E\dialog_102E.hpp"
#include "m252\dialog_252.hpp"
#include "prc77\dialog_77.hpp"
#include "T884\dialog_884.hpp"
#include "urc10\dialog_10.hpp"
#include "vrc12\dialog_12.hpp"


class CfgFunctions
{
	class Rev_TFAR_SOGPF
	{
		class Radio
		{
			file="\Reeveli_TFAR_SOGPF_Scribbles\functions";
			class T884_switchAlt;
			class T884_switchAudio;
		};
	};
};