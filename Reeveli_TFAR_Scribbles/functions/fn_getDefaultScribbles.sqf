/*
 * Author: Reeveli
 * Part of Reeveli's TFAR Scribbles.
 * Client side function to apply any editor defined scribbles to players (if relevant radios present).
 * Called as a postInit function.
 *
 * Arguments: NONE
 *
 * Return Value: BOOLEAN
 *
 * Example:
 * call Rev_TFAR_fnc_getDefaultScribbles
 *
 1.1
    Rewritten to account for CBA settings now also having way to add default scribbles
 */

if (!hasInterface) exitWith {false};
if (!isMultiplayer) exitWith {diag_log "Rev_TFAR_fnc_getDefaultScribbles: TFAR only works in multiplayer";false};

private _SR = switch (side player) do {
            case WEST: {
                Rev_TFAR_settings_SR_B;
            };
            case EAST: {
                Rev_TFAR_settings_SR_O;
            };
            case INDEPENDENT: {
                Rev_TFAR_settings_SR_I;
            };
		};	

private _LR = switch (side player) do {
            case WEST: {
                Rev_TFAR_settings_LR_B;
            };
            case EAST: {
                Rev_TFAR_settings_LR_O;
            };
            case INDEPENDENT: {
                Rev_TFAR_settings_LR_I;
            };
		};	        
	


private _Sw = vehicle player getVariable ['TFAR_scribbles_Sw',nil];
private _Lw = vehicle player getVariable ['TFAR_scribbles_Lw',nil];


//Global scribbles should only apply if object specific ones are not present
if (isNil "_Sw") then {vehicle player setVariable ['TFAR_scribbles_Sw',_SR splitString ','];};
if (isNil "_Lw") then {vehicle player setVariable ['TFAR_scribbles_Lw',_LR splitString ','];};


//Unique SW
private _condition = {getNumber (configfile >> "CfgWeapons" >> _x >> "tf_radio") isEqualTo 1};	
if (_condition count assignedItems player > 0) then {
    private _value1 = vehicle player getVariable ['TFAR_scribbles_Sw',nil];
    Rev_TFAR_scribbleNamespace setVariable [call TFAR_fnc_activeSwRadio, _value1];
    diag_log "Rev_TFAR_fnc_getDefaultScribbles: Default Sw radio scribbles applied, EH ID36";
};

//Prototype or vanilla item
private _condition2 = {getNumber (configfile >> "CfgWeapons" >> _x >> "tf_prototype") isEqualTo 1};	
if (("ItemRadio" in assignedItems player) OR (_condition2 count assignedItems player > 0)) then {	 
    [
        "Rev_TFAR_defaultScribblesEH",
        "OnRadiosReceived",
        {
            params ["_unit","_radio"];
            private _scribbles = vehicle player getVariable ['TFAR_scribbles_Sw',nil];
            Rev_TFAR_scribbleNamespace setVariable [call TFAR_fnc_activeSwRadio, _scribbles];
            //Remove EH after use
            ["Rev_TFAR_defaultScribblesEH", "OnRadiosReceived", player] call TFAR_fnc_removeEventHandler;
            diag_log "Rev_TFAR_fnc_getDefaultScribbles: Default Sw radio scribbles applied, EH ID37";
        },
        Player
    ] call TFAR_fnc_addEventHandler;
};



//We need delay to give TFAR time to assign Lw radio to player if present on mission start
[
    {
        if (call TFAR_fnc_haveLRRadio) then
        {
            private _LRradio = (call TFAR_fnc_activeLrRadio) # 0;
            private _value2 = vehicle player getVariable ['TFAR_scribbles_Lw',nil];
            //Not transmitted globally, when the radio owner closes their UI first time scribbles are saved globally
            _LRradio setVariable ["Rev_TFAR_LwScribbles", _value2, false];
            diag_log "Rev_TFAR_fnc_getDefaultScribbles: Default Lw radio scribbles applied, EH ID38";
        };
    },
    [],
    3
] call CBA_fnc_waitAndExecute;

diag_log "Rev_TFAR_fnc_getDefaultScribbles: Function closed, EH ID39";
true;