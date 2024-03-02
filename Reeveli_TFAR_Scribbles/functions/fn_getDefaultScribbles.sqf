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
 1.2.2
    Bug fix for Lw object scribbles not working, (!isNil "_Lw") was missing !
 1.2.1
    Removed some dead code
 1.2
    Major restructuring to fix critical bug with virtual curator entities
 1.1
    Rewritten to account for CBA settings now also having way to add default scribbles
 */

if (!hasInterface) exitWith {false};
if (!isMultiplayer) exitWith {diag_log "Rev_TFAR_fnc_getDefaultScribbles: TFAR only works in multiplayer";false};


//In-line functions to set sribbles for Sw radio (e.g. curator module gets assigned multiple at game start)
fnc_sw_logic = {
	params ["_object"];
    private _scribbles = switch (getText (configfile >> "CfgWeapons" >> _object >> "tf_encryptionCode")) do {
        case "tf_west_radio_code": {Rev_TFAR_settings_SR_B};
        case "tf_east_radio_code": {Rev_TFAR_settings_SR_O};
        case "tf_independent_radio_code": {Rev_TFAR_settings_SR_I};
        default {''};
    };
    private _Sw = vehicle player getVariable ['TFAR_scribbles_Sw',nil];
    //Global scribbles should only apply if object specific ones are not present
    if (!isNil "_Sw") then {_scribbles = _Sw} else {_scribbles = _scribbles splitString ','};
    Rev_TFAR_scribbleNamespace setVariable [_object, _scribbles];
};

fnc_sw_unit = {
	params ["_object"];
    private _scribbles = switch (side player) do {
        case WEST: {Rev_TFAR_settings_SR_B;};
        case EAST: {Rev_TFAR_settings_SR_O;};
        case INDEPENDENT: {Rev_TFAR_settings_SR_I;};
        default {''};
    };
    private _Sw = vehicle player getVariable ['TFAR_scribbles_Sw',nil];
    //Global scribbles should only apply if object specific ones are not present
    if (!isNil "_Sw") then {_scribbles = _Sw} else {_scribbles = _scribbles splitString ','};
    Rev_TFAR_scribbleNamespace setVariable [_object, _scribbles];
};

fnc_lw = {
	params ["_object"];
    private _scribbles = switch (side player) do {
        case WEST: { Rev_TFAR_settings_LR_B;  };
        case EAST: {Rev_TFAR_settings_LR_O; };
        case INDEPENDENT: {  Rev_TFAR_settings_LR_I;};
        default {''};
    };
    private _Lw = vehicle player getVariable ['TFAR_scribbles_Lw',nil];
    //Global scribbles should only apply if object specific ones are not present
    if (!isNil "_Lw") then {_scribbles = _Lw} else {_scribbles = _scribbles splitString ','};
    //Transmitted only locally, when the radio owner closes their UI first time scribbles are saved globally
    _object setVariable ["Rev_TFAR_LwScribbles", _scribbles , false];
};

//TFAR or vanilla item
private _condition2 = {isNumber (configfile >> "CfgWeapons" >> _x >> "tf_prototype")};	
if (("ItemRadio" in assignedItems player) OR (_condition2 count assignedItems player > 0)) then {	 
    [
        "Rev_TFAR_defaultScribblesEH",
        "OnRadiosReceived",
        {
            params ["_unit","_radio"];
           if (vehicle player iskindof "VirtualCurator_F") then { {[_x] call fnc_sw_logic} forEach _radio;}
           else { {[_x] call fnc_sw_unit} forEach _radio;};
           
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
        if (call TFAR_fnc_haveLRRadio && !(vehicle player iskindof "VirtualCurator_F")) then
        {
            private _LRradio = (call TFAR_fnc_activeLrRadio) # 0;
            [_LRradio] call fnc_lw;
            diag_log "Rev_TFAR_fnc_getDefaultScribbles: Default Lw radio scribbles applied, EH ID38";
        };
    },
    [],
    3
] call CBA_fnc_waitAndExecute;

diag_log "Rev_TFAR_fnc_getDefaultScribbles: Function closed, EH ID39";
true;