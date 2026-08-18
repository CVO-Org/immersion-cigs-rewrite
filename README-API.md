# Readme for Mission and Mod Makers

## Public API Events
| Event Key                | Parameters                                      | Locality | Type   | Description            |
| ------------------------ | ----------------------------------------------- | -------- | ------ | ---------------------- |
| `cigs_api_takeFromPack`  | _unit, _class_cigpack, _item_glasses, _item_hmd | Local    | Listen | Sucking Loop           |
| `cigs_api_useLighter`    | _unit, _className, _type                        | Local    | Listen | Using a Lighter        |
| `cigs_api_eatCig`        | _unit, _item, _slot                             | Local    | Listen | Eating a Cigarette     |
| `cigs_api_startsSmoking` | _unit, _item, _slot                             | Local    | Listen | Starts Smoking         |
| `cigs_api_smoking`       | _unit, _currentTime, _currentItem, _itemType    | Local    | Listen | Smoking Loop           |
| `cigs_api_stopsSmoking`  | _unit, _currentTime, _currentItem, _itemType    | Local    | Listen | Stops Smoking          |
| `cigs_api_startsSucking` | _unit, _item, _slot                             | Local    | Listen | Starts Sucking         |
| `cigs_api_sucking`       | _unit, _currentTime, _currentItem, _itemType    | Local    | Listen | Sucking Loop           |
| `cigs_api_stopsSucking`  | _unit, _currentTime, _currentItem, _itemType    | Local    | Listen | Stops Sucking          |
| `cigs_api_respectPayed`  | _player, _target                                | Local    | Listen | Respect has beed given |

As of v3.0.7, API Event Keys have been renamed from `cigs_core_api` to `cigs_api`. 

## Unit Variable APIs
The following APIs can be used by `_unit setVariable [_apiKey, _value, true];`.
Make sure to broadcast the variable as the checks will be on the individual clients.

| ApiKey                         | Values | Desc                                                 |
| ------------------------------ | ------ | ---------------------------------------------------- |
| `cigs_api_blockAnimations`     | true   | Will block all cigs related animations on said unit. |
| `cigs_api_blockDynamicSmoking` | true   | Will block unit from smoking dynamically.            |
| `cigs_api_blockAiCigs`       | true   | Will block unit from getting cig items dynamically.  |


## Useful Functions
- `[_unit] call cigs_core_fnc_smoking_start;` - Lets a Unit - AI or Players - Start Smoking - Requires Smokeable Item in Glasses or HMD Slot
- `["PACKAGES"] call cigs_core_fnc_getAllItems;` - To retrieve all Packages classnames
- `["LIGHTERS"] call cigs_core_fnc_getAllItems;` - To retrieve all Lighters classnames
- `["ALL"] call cigs_core_fnc_getAllItems;` - To retrieve Both


## Ai Cigs Distribution
There are multiple ways to define which side will have which cigarettes.

The following is ordered by priority.

### Global Variable `cigs_aiCigs_api`

This global variable must be defined on the server and contain a hashmap.
The following keys will be checked: `"WEST", "EAST", "GUER", "CIV"`.
The value of each key must be an array with classnames of pop/cigs_packages.

If the GVAR is defined but empty, aiCigs will be effectively disabled.

### 3den Module `cigs_aiCigs_module`
When placed, this 3den Module lets you provide classnames of pop/cigs_packages per side.
If the module is placed but empty, no packages will be distributed.

### CBA Settings 
Per side, each cigarette brand has its own setting, which can be enabled or disabled.
By default, every setting is disabled and will not be considered for the distribution of packages on AI.
Once a single setting is enabled, the CBA Settings system will be activated and in effect.
If only one side has settings enabled while others are left disabled, those other sides will not receive any cigarettes.

### Default Setup
The Mod will come with a default distribution of packages.
This only takes effect when none of the other methods above are in use.
