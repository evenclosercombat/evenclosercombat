To-Do for editor
-----
- [x] Check Character Parent Struct 
 - - [x] Problem: Might have story_character_entry_info_bitmask digits mixed up
 - - [x] Problem: character_story_entries[x].field_0x3 may have default values? 
 - - [x] Problem: character->0x7cc2 offset may have default value in engine 
 - - [x] Default Skill Values
 - - [x] FIX: CPU Struct, should be able to fit 10?
 - - - [x] Unroll the array due to misaligned struct sizes
 - - [x] Identify guard flag structures
- [x] Check System Parent Struct
- - [x] FIX: Character names start in the middle of action list
- - [x] Default Skill Values
- [x] Create/Check Stage Parent Struct
- - [x] Default Skill Values
- - - There doesn't seem to be any, unlike character and system.
- [x] Create/Check Demo Parent Struct
- - [x] Default Skill Values
- - - There doesn't seem to be any, unlike character and system.
- [x] kgtSound struct
- [x] Confirm skill type structures
 - - [x] RP
 - - [x] DB
 - - [x] Cancel
 - - [x] COM
- [x] Identify source of time_method_number
- [x] Confirm kgtFile types
 - - [x] System
 - - [x] Character
 - - [x] Stage
 - - [x] Demo
- [x] Rename all structures before export to engine
 - - [x] Character
 - - [x] Demo
 - - [x] Stage
 - - [x] System

To-Do for Engine
-----
- [ ] DirectX structures
- - [ ] Sound
- - [ ] Draw
- - [ ] Input?
- - [ ] Play
- [ ] BEFORE EXPORT: Final adjust of all offset types
- [ ] BEFORE EXPORT: List of important functions to achieve parity with

To-do to get to compile
----
- [ ] Explicit cast structs for script types, object types?

To-do various
----
- [ ] Look at COM skill again, double-check for mistakes.
 

Naming Decisions/Changes
-----
- Parent structs in editor -> kgtEditor_ prefix
- Action -> Skill
- ActionScript -> SkillScript
- File -> kgtFile
- KGT MAIN references -> KGT SYSTEM references

| data type    | prefix |
|--------------|--------|
| 2DFM structs | kgt    |
| int          | i      |
| char         | c      |
| string | s | 
| short | sh |
| globals | g (followed by variable type prefix) |

| abbreviation | definition | 
|--------------|--------|
| idx | index |

| comment prefix | definition | 
|--------------|--------|
| To-Do | Fix after export to .c files |
| Bug | Used to denote possible bugs, or known sources of confirmed bugs | 

Important Functions
----
| Memory Address | Function Name | 
|--------------|--------|
| 0x00405ce0 | wWinMain |
| 0x004056c0 | vInitializeWindowsAndMemory |
| 0x004148e0 | vLoadKgt2kConfig | 
| 0x00414930 | vLoadGameConfig | 
| 0x00403300 | vMemzero | 
| 0x00416530 | vRegisterInputWindowClasses |


Important Information
--
Editor Character Info Ptr is 0x007d7b80

Editor Stage Info Ptr is 0x007757e0

Editor Demo info Ptr is 0x00607440

Editor System info is 0x0062ed80

Default skill values seem to come right after common_images

