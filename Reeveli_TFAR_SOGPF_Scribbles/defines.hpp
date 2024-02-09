class RscBackPicture;
class RscButton;
class RscEdit;
class RscEditLCD;
class RscPicture;
class RscText;
class HiddenButton;
class HiddenRotator;
class HiddenFlip;



class vn_RscButton;
class vn_RscEdit;
class vn_RscPicture;
class vn_RscText;


#define TFAR_notebook_X  			0.0935937 * safezoneW + safezoneX
#define TFAR_notebook_Y  			0.0252042 * safezoneH + safezoneY
#define TFAR_notebook_W  			0.510056 * safezoneW
#define TFAR_notebook_H  			0.942975 * safezoneH


#define REV_TFARSOG_W			(((getResolution select 4) min 1.2) / 40)
#define REV_TFARSOG_H			((((getResolution select 4) min 1.2) / 1.2) / 25)
#define REV_TFARSOG_X			REV_TFARSOG_W + (safezoneX + (safezoneW - ((getResolution select 7) min 1.2))/2)
#define REV_TFARSOG_Y			REV_TFARSOG_H + (safezoneY + (safezoneH - (((getResolution select 7) min 1.2) / 1.2))/2)