class CfgPatches
{
	class Reeveli_TFAR_scribbles
	{
		name = "TFAR Scribbles";
		requiredVersion=2.0;
		requiredAddons[]=
		{
			"cba_main",
			"cba_events",
			"cba_settings",
			"CBA_Extended_EventHandlers",
			"tfar_handhelds",
			"tfar_backpacks"
		};
		author="Reeveli";
		authors[]= {"Reeveli"};
		license = "https://www.bohemia.net/community/licenses/arma-public-license-share-alike";
		url = "https://www.youtube.com/@Reeveli";			
        version = 2.2;
        versionStr = "2.2.1";
        versionAr[] = {2, 2, 1};
		units[]={};
		weapons[]={};
	};
};


class Extended_PreInit_EventHandlers
{
	class Rev_TFAR {init = "call compile preprocessFileLineNumbers '\Reeveli_TFAR_Scribbles\functions\fn_preInit.sqf'";};
	class Rev_TFAR_Settings {init = "call compile preprocessFileLineNumbers '\Reeveli_TFAR_Scribbles\functions\fn_scribbleSettings.sqf'";};
};


#include "Cfg3Den.hpp"

#include "defines.hpp"

//dialogs
#include "anarc164\Dialog_164.hpp"
#include "anarc210\Dialog_210.hpp"
#include "anprc148jem\Dialog_148.hpp"
#include "anprc152\Dialog_152.hpp"
#include "anprc155\Dialog_155.hpp"
#include "bussole\Dialog_bussole.hpp"
#include "fadak\Dialog_fadak.hpp"
#include "mr3000\Dialog_3000.hpp"
#include "mr6000l\Dialog_6000.hpp"
#include "rt1523g\Dialog_1523g.hpp"

//List order determines call order, don't arrange alphapethically
class CfgFunctions
{
	class Rev_TFAR
	{
		class Radio
		{
			file="\Reeveli_TFAR_Scribbles\functions";
        	class arsenalScribbles {postInit=1;};
        	class arsenalSettings {postInit=1;};
			class getLwAlt;
			class getLwFrq;		
			class getSwAlt;	
			class getSwFrq;	
			class loadScribble;	
			class playerInit {postInit=1;};	
        	class respawnScribbles {postInit=1;};
        	class respawnSettings {postInit=1;};
			class saveScribble;
			class getDefaultScribbles {postInit=1;};
			class setDefaultScribbles;
		};
	};
};