/*
 * Author: Reeveli
 * Part of Reeveli's TFAR Scribbles.
 * Cfg3Den attributes to enable setting object specific default scribbles.
 * Called an extended preinit function fron mod config.

1.1
	Added header
	Empty values are now resolved as nil
1.0.1
	Added colons to attribute display names

*/
class Cfg3DEN
{
	class Object
	{
		class AttributeCategories
		{
			class TFAR_attributes
			{
				displayName="$STR_tfar_core_3DEN_Properties";
				collapsed=1;
				class Attributes
				{
					class TFAR_scribbles_Sw
					{
						displayName="Default SR-scribbles:";
						tooltip="Default SR-scribbles for this entity, will overwrite any scribbles from addon options";
						property="TFAR_scribbles_Sw";
						control="Edit";
						expression = "if (_value isEqualTo '' || _value isEqualTo []) exitWith {};_this setVariable ['%s',(_value splitString ','),true];";
						defaultValue="''";
						typeName="STRING";
						unique=0;
						condition="objectControllable + logicModule";
					};
					class TFAR_scribbles_Lw
					{
						displayName="Default LR-scribbles:";
						tooltip="Default LR-scribbles for this entity, will overwrite any scribbles from addon options";
						property="TFAR_scribbles_Lw";
						control="Edit";
						expression = "if (_value isEqualTo '' || _value isEqualTo []) exitWith {};_this setVariable ['%s',(_value splitString ','),true];";
						defaultValue="''";
						typeName="STRING";
						unique=0;
						condition="objectControllable + logicModule";
					};
				};
			};
		};
	};
	class Group
	{
		class AttributeCategories
		{
			class TFAR_attributes
			{
				displayName="$STR_tfar_core_3DEN_Properties";
				collapsed=1;
				class Attributes
				{
					class TFAR_scribbles_Sw
					{
						displayName="Default SR-scribbles:";
						tooltip="Default SR-scribbles for this entity, will overwrite any scribbles from addon options";
						property="TFAR_scribbles_Sw";
						control="Edit";
						expression = "if (_value isEqualTo '' || _value isEqualTo []) exitWith {};_this setVariable ['%s',(_value splitString ','),true];";
						defaultValue="''";
						typeName="STRING";
						unique=0;
					};
					class TFAR_scribbles_Lw
					{
						displayName="Default LR-scribbles:";
						tooltip="Default LR-scribbles for this entity, will overwrite any scribbles from addon options";
						property="TFAR_scribbles_Lw";
						control="Edit";
						expression = "if (_value isEqualTo '' || _value isEqualTo []) exitWith {};_this setVariable ['%s',(_value splitString ','),true];";
						defaultValue="''";
						typeName="STRING";
						unique=0;
					};
				};
			};
		};
	};
};