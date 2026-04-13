To-Do for editor
-----
[ ] Check Character Parent Struct 
 - Problem: Might have story_character_entry_info_bitmask digits mixed up
 - Problem: character_story_entries[x].field_0x3 may have default values?
 - Problem: character->0x7cc2 offset may have default value in engine
 - [x] Default Skill Values
 - [x] FIX: CPU Struct, should be able to fit 10?
 - - [x] Unroll the array due to misaligned struct sizes
 - [ ] Identify guard flag structures
[ ] Check System Parent Struct
- [ ] FIX: Character names start in the middle of action list
- [ ] Default Skill Values
[ ] Create/Check Stage Parent Struct
 - [ ] Default Skill Values
[ ] Create/Check Demo Parent Struct
 - [ ] Default Skill Values
[ ] kgtSound struct
[ ] Confirm skill type structures
 - [ ] RP
 - [ ] DB
 - [ ] Cancel
 - [ ] COM
[ ] Identify source of time_method_number
[ ] Confirm kgtFile types
 - [ ] System
 - [ ] Character
 - [ ] Stage
 - - Problem: kgt_stage file write is very small in engine?
 - [ ] Demo
[ ] Rename all structures before export to engine
 - [ ] Character
 - [ ] Demo
 - [ ] Stage
 - [ ] System

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
| idx | index |


Important Functions
----
- 

Important Information
--
Editor Character Info Ptr is 0x007d7b80
Editor Stage Info Ptr is 0x007757e0
Editor Demo info Ptr is 0x00607440
Editor System info is 0x0062ed80