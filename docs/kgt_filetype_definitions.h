typedef unsigned char   undefined;

typedef unsigned char    byte;
typedef unsigned int    dword;
typedef unsigned long long    GUID;
typedef pointer32 ImageBaseOffset32;

typedef int    sdword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    wchar16;
typedef short    wchar_t;
typedef unsigned short    word;
typedef struct file_character file_character, *Pfile_character;

typedef struct kgt_skill_info_struct kgt_skill_info_struct, *Pkgt_skill_info_struct;

typedef struct kgt_skill_step_struct kgt_skill_step_struct, *Pkgt_skill_step_struct;

typedef struct kgt_probably_images_struct kgt_probably_images_struct, *Pkgt_probably_images_struct;

typedef struct kgt_pal_color kgt_pal_color, *Pkgt_pal_color;

typedef struct kgt_sound_struct kgt_sound_struct, *Pkgt_sound_struct;

typedef struct character_file_command_struct character_file_command_struct, *Pcharacter_file_command_struct;

typedef struct character_hit_junction_info character_hit_junction_info, *Pcharacter_hit_junction_info;

typedef struct character_file_common_images_struct character_file_common_images_struct, *Pcharacter_file_common_images_struct;

typedef struct character_cpu_command_struct character_cpu_command_struct, *Pcharacter_cpu_command_struct;

typedef struct character_story_entry character_story_entry, *Pcharacter_story_entry;

typedef struct character_cpu_command_skill character_cpu_command_skill, *Pcharacter_cpu_command_skill;

typedef struct character_story_entry_cpu character_story_entry_cpu, *Pcharacter_story_entry_cpu;

struct character_file_common_images_struct {
    short e_number;
    short x_movement;
    short y_movement;
};

struct kgt_pal_color {
    char b;
    char g;
    char r;
    char field3_0x3; /* This is always '01' */
};

struct character_story_entry_cpu {
    short story_character_entry_info_bitmask; /* Left-digit: show life = +0x1, time = +0x2, life = +0x4 win pause leave = +0x20, win pause appear = +0x40, from 1st = +0x0, effect is player = +0x80 right digit: effect none = 0x0, last hit = 0x1, player ignore = +0x2 */
    undefined field1_0x2;
    undefined field2_0x3;
    char character;
    char cpu_level;
    char enemy_bitmask; /* player = 0x01 */
    short start_pos;
    undefined field7_0x9;
    undefined field8_0xa;
    char time_method_number;
    char time_method_number_random;
    char life_method_target; /* 0x0 = player */
    char life_method_life_amount;
    char victory_points_amount;
    char effect_life_increase;
    char effect_special_increase;
    char victory_points_target; /* 0x0 = last attacker, 0x1 = player */
    char when_time_target; /* 0x0 = player */
    undefined field18_0x14;
    char when_time_number;
    undefined field20_0x16;
    undefined field21_0x17;
    undefined field22_0x18;
    char end_of_story_character_entry;
};

struct character_story_entry {
    char story_entry_type; /* 1 = Fight, 2 = Demo, 3 = Jump/Divergence, 4 = End */
    char stage; /* For demo entries, this chooses demo. For divergance entries, this chooses divergance type. 00 = not, 01 = front stage, 02 = life gauge based, 03 = winning all the fight */
    char number_of_rounds; /* For divergence, this is the health for divergence type 02. */
    undefined field3_0x3;
    char life_recover_number;
    char when_defeat_and_1st_round_bitmask; /* For divergence, this is 'appointment', to indicate how many entries to jump. For fight, +0x01 = game over, +0x2 = carry_over */
    short time;
    short player_start_x_pos;
    undefined field8_0xa;
    undefined field9_0xb;
    char options_bitmask; /* show round # = 0x01, fighting spirit indicate = 0x02, WALL = 0x04 */
    undefined field11_0xd;
    undefined field12_0xe;
    undefined field13_0xf;
    char when_time_over; /* 0 = cpu1... */
    char when_time_over_number;
    char cpu_winpns; /* 2 = cpu1... 1 = player, 0 = character who hit last */
    char cpu_winpns_number;
    undefined field18_0x14;
    undefined field19_0x15;
    undefined field20_0x16;
    undefined field21_0x17;
    struct character_story_entry_cpu field22_0x18[7];
};

struct character_cpu_command_skill {
    char directional; /* starts at 1 = no direction, continues starting at right, ending at up-right */
    char continue_flag; /* 30 = go to next skill, 20 = end skill, 10 = inactive? unsure. */
    short skill_idx;
    short skill_timing;
    undefined field4_0x6;
};

struct character_cpu_command_struct {
    char field0_0x0;
    char 0x1_default_1; /* This is 1 by default except for the very first entry in the array. */
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    char 0x6_empty_1; /* This is 1 by default for every empty entry except for the very first empty one (which has 0x1 and 0x8 set to 1) */
    undefined field7_0x7;
    char 0x8_default_1; /* This is 1 by default except for the very first entry in the array. */
    undefined field9_0x9;
    char name[30];
    undefined field11_0x28;
    undefined field12_0x29;
    char character_or_enemy_in_air_bitmask; /* 1 = Character in air, 2 = Enemy in air, 3 = both? */
    char probability;
    short interval_empty;
    short interval_inside;
    undefined field17_0x30;
    undefined field18_0x31;
    undefined field19_0x32;
    undefined field20_0x33;
    struct character_cpu_command_skill command_skill_array[8]; /* I should be able to fit 10 in here somehow? */
    undefined field22_0x6c;
    undefined field23_0x6d;
    char 0x6e_empty_1; /* This is 1 by default for every empty entry except for the very first empty one (which has 0x1 and 0x8 set to 1) */
};

struct kgt_skill_step_struct {
    char skill_step_type; /* 00 = start of new skill, 0B = SC, 19 = FD, 0C = I */
    undefined field1_0x1;
    char sk_level;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
    undefined field9_0x9;
    undefined field10_0xa;
    undefined field11_0xb;
    undefined field12_0xc;
    undefined field13_0xd;
    undefined field14_0xe;
    undefined field15_0xf;
};

struct kgt_skill_info_struct {
    char field0_0x0[30];
    undefined field1_0x1e;
    undefined field2_0x1f;
    short unk_one-up;
    undefined field4_0x22;
    undefined field5_0x23;
    undefined field6_0x24;
    undefined field7_0x25;
    undefined field8_0x26;
};

struct character_file_command_struct {
    char name[30];
    undefined field1_0x1e;
    undefined field2_0x1f;
    short command_time_ms;
    short air_command_set_likely;
    short stand_command_set_likely;
    short stand_far_command_set_likely;
    short crouched_command_set_likely;
    short command_inputs[10]; /* Byte 1: Right digit: Arrow - 0 for 'free', 1 for dot, 09 for up right, 0A-0D for multi-arrows starting at left.   Leftt-digit: Buttons A through D are stored in the left digit, bitmask-style. Byte 2: Left-digit -  Continue to next input = +0x30 End at this input = +0x20 No repeat/hold/black button = +0x00 Repeat = +0x40 Hold = +0x80 Black = +0xC0  Right-digit: Buttons E (binary 1) and F (binary 2) */
    short command_input_timings[10];
};

struct character_hit_junction_info {
    short allottment_idx;
    short spark_idx;
};

struct kgt_probably_images_struct {
    int *ptr_bytes;
    int height;
    int width;
    int unk;
    int size;
};

struct kgt_sound_struct {
    void *buffer;
    char name[32];
    int buffer_size;
    undefined field3_0x28;
    undefined field4_0x29;
};

struct file_character {
    char header_start_string[12]; /* '2DKGT' */
    int actions_loaded_flag;
    char character_name[256];
    int skill_info_amount;
    struct kgt_skill_info_struct skill_info_array[1023];
    char too_many_skills_check;
    byte field6_0x9cee[31];
    char skill_steps_array_amt;
    byte field8_0x9d0e[6];
    int skill_steps_array_amount_int; /* Written twice, likely unintentionally. */
    struct kgt_skill_step_struct skill_steps_array[65536];
    struct kgt_probably_images_struct images[8192];
    struct kgt_pal_color pallette_1[256];
    struct kgt_pal_color pallette_2[256];
    struct kgt_pal_color pallette_3[256];
    struct kgt_pal_color pallette_4[256];
    struct kgt_pal_color pallette_5[256];
    struct kgt_pal_color pallette_6[256];
    struct kgt_pal_color pallette_7[256];
    struct kgt_pal_color pallette_8[256];
    byte palllette_leftovers[256];
    int sound_amount;
    struct kgt_sound_struct sound_struct_array[256];
    int four_zeros;
    int command_struct_amount;
    struct character_file_command_struct command_struct_array[100];
    int hit_junction_amount;
    struct character_hit_junction_info hit_junction_info[200];
    int common_images_amount;
    struct character_file_common_images_struct common_images_struct[200];
    struct character_cpu_command_struct CPU_commands[100]; /* Writes 0x2b66 bytes here, resulting in the following 10 extra bytes. */
    undefined field31_0x13bb60;
    undefined field32_0x13bb61;
    undefined field33_0x13bb62;
    undefined field34_0x13bb63;
    undefined field35_0x13bb64;
    char default_1_char;
    undefined field37_0x13bb66;
    undefined field38_0x13bb67;
    undefined field39_0x13bb68;
    undefined field40_0x13bb69;
    short SectionB_default_1; /* Start of section B, default value is 1. Following entries all have default values in hex. */
    short SectionB_default_2;
    short SectionB_default_3;
    short SectionB_default_4;
    short SectionB_default_5;
    short SectionB_default_6;
    short SectionB_default_9;
    short SectionB_default_0xa;
    short SectionB_default_0xb;
    short SectionB_default_0xc;
    short SectionB_default_0xd;
    short SectionB_default_0xe;
    short SectionB_default_0xf;
    short SectionB_default_0x10;
    short SectionB_default_0x11;
    short SectionB_default_0x12;
    short SectionB_default_0x13;
    short SectionB_default_0x27;
    short SectionB_default_0x2c;
    short SectionB_default_0x2f;
    short SectionB_default_0x30;
    short SectionB_default_0x32;
    short SectionB_default_0x19;
    short SectionB_default_0x1a;
    byte field65_0x13bb9a[38];
    short age;
    byte field67_0x13bbc2[2];
    char gender; /* 00 = male, 01 = female, 02 = both, 03 = none */
    byte field69_0x13bbc5[1740];
    short y_pos_of_SideHP;
    short interv;
    char shave_ratio;
    char life_rev_y_start_pos;
    char life_rev_correction;
    char character_rev;
    char guard_button; /* 00 = A, 05 = F */
    short life_gauge_max;
    byte field78_0x13c29c[2];
    short special_stock_gauge_max;
    byte field80_0x13c2a0[2];
    short special_stock_max;
    byte field82_0x13c2a4[2];
    char guard_button_bool; /* 00 = false, 08 = true */
    byte field84_0x13c2a7[7];
    short special_gauge_increase_on_attack;
    short special_gauge_increase_on_hit;
    byte field87_0x13c2b2[3];
    char start_of_section_c;
    byte field89_0x13c2b6[3];
    struct character_story_entry story_entries[100];
    char start_of_section_d;
    byte field92_0x141332[4524];
};

typedef struct file_demo file_demo, *Pfile_demo;

typedef char INT8;

struct file_demo {
    char header_start_string[12];
    int loaded_flag;
    char demo_name[256];
    struct kgt_skill_info_struct skill_info_array[1023];
    char too_many_skills_check;
    INT8 field5_0x9cea;
    struct kgt_skill_step_struct skill_steps_array[65536];
    struct kgt_probably_images_struct images_struct[8192];
    struct kgt_pal_color pal_1[256];
    struct kgt_pal_color pal_2[256];
    struct kgt_pal_color pal_3[256];
    struct kgt_pal_color pal_4[256];
    struct kgt_pal_color pal_5[256];
    struct kgt_pal_color pal_6[256];
    struct kgt_pal_color pal_7[256];
    struct kgt_pal_color pal_8[256];
    struct kgt_sound_struct field16_0x133ceb[256];
    undefined field17_0x1366eb;
    int four_zeros;
    char BGM_selection;
    char skip_with_input;
    undefined field21_0x1366f2;
    undefined field22_0x1366f3;
    int time;
};

typedef struct file_kgt file_kgt, *Pfile_kgt;

typedef struct kgt_file_hit_junctions kgt_file_hit_junctions, *Pkgt_file_hit_junctions;

struct kgt_file_hit_junctions {
    char name[30];
    undefined field1_0x1e;
    undefined field2_0x1f;
    char doing;
    undefined field4_0x21;
    undefined field5_0x22;
    undefined field6_0x23;
};

struct file_kgt {
    char header_start_string[12];
    int loaded_flag;
    char game_name[256];
    int skill_info_amount;
    struct kgt_skill_info_struct skill_info_array[1023]; /* Actual size written is (skill_info_amount+1)*0x27, which includes the following 0x27 bytes */
    char too_many_skills_check;
    byte unk_or_empty_a[31];
    char skill_steps_array_amount;
    byte unk_or_empty_b[6];
    int skill_steps_array_amount_int; /* Written twice, probably by accident */
    struct kgt_skill_step_struct skill_steps_array[65536]; /* Skill_steps_array_amount_int*0x10 is the actual size written */
    int images_amount; /* Always going to be "8192" */
    struct kgt_probably_images_struct images_struct[8192]; /* image of size 'size' will always be written after each image_struct */
    struct kgt_pal_color pal_1[256];
    struct kgt_pal_color pal_2[256];
    struct kgt_pal_color pal_3[256];
    struct kgt_pal_color pal_4[256];
    struct kgt_pal_color pal_5[256];
    struct kgt_pal_color pal_6[256];
    struct kgt_pal_color pal_7[256];
    struct kgt_pal_color pal_8[256];
    struct kgt_pal_color pal_9[64];
    struct kgt_sound_struct sound_struct[256]; /* actual sound of size 'size' is written after each sound_struct */
    int four_zeros; /* acts as a buffer between areas that are written for all kgt filetypes and specific areas */
    char character_namelist[32][256];
    byte unk_or_empty_c[4608];
    struct kgt_file_hit_junctions hit_junctions[200];
    char default_2_char; /* default value is 2, currently marked as char */
    undefined field28_0x13b641;
    undefined field29_0x13b642;
    undefined field30_0x13b643;
    undefined field31_0x13b644;
    char stiff_time_hit;
    char stiff_time_guard;
    char stiff_time_offset;
    char stage_names[50][256];
    char demo_names[50][256];
    byte unk_or_empty_e[12800];
    char demo_sel_title;
    char demo_sel_selective_1p;
    char demo_sel_selective_vs_single;
    char demo_sel_selective_vs_team;
    char demo_sel_game_over;
    char demo_sel_opening_demo;
    char default_0x18_char; /* default value is 0x18, marked as char */
    char default_0x19_char; /* default value is 0x19, marked as char */
    char system_bitmask; /* editor won't read file = +0x1, offset = +0x02, story mode +0x04, vs mode +0x08, vs team mode +0x10, numbers shown on life +0x20, cursor stays +0x40 */
    undefined field47_0x144c51;
    undefined field48_0x144c52;
    undefined field49_0x144c53;
    char common_images[200][32];
    short skill_idx_none; /* Following are the indexes in the skill info list for the required KGT skills Not always referenced, which leads to some glitches. */
    short skill_idx_hit_letter_hit;
    short skill_idx_hit_number_0;
    short skill_idx_hit_number_1;
    short skill_idx_hit_number_2;
    short skill_idx_hit_number_3;
    short skill_idx_hit_number_4;
    short skill_idx_hit_number_5;
    short skill_idx_hit_number_6;
    short skill_idx_hit_number_7;
    short skill_idx_hit_number_8;
    short skill_idx_hit_number_9;
    short skill_idx__offset_hit_mark;
    short skill_idx__round_ani_starttime;
    short skill_idx_round_ani_endtime;
    short skill_idx_round_1;
    short skill_idx_round_2;
    short skill_idx_round_3;
    short skill_idx_round_4;
    short skill_idx_round_5;
    short skill_idx_round_6;
    short skill_idx_round_7;
    short skill_idx_round_8;
    short skill_idx_round_9;
    short skill_idx_round_final;
    short skill_idx_spirits;
    short skill_idx_KO;
    short skill_idx_perfect;
    short skill_idx_you_win;
    short skill_idx_you_lose;
    short skill_idx_1P_wins;
    short skill_idx_2P_wins;
    short skill_idx_draw;
    short skill_idx_double_KO;
    short skill_idx_unlimited_sign;
    short skill_idx_time_number_0;
    short skill_idx_time_number_1;
    short skill_idx_time_number_2;
    short skill_idx_time_number_3;
    short skill_idx_time_number_4;
    short skill_idx_time_number_5;
    short skill_idx_time_number_6;
    short skill_idx_time_number_7;
    short skill_idx_time_number_8;
    short skill_idx_time_number_9;
    short skill_idx_victory_mark_on;
    short skill_idx_victory_mark_off;
    short skill_idx_stage_layout_1;
    short skill_idx_stage_layout_2;
    short skill_idx_stage_layout_3;
    short skill_idx_stage_layout_4;
    short skill_idx_stage_layout_5;
    short skill_idx_stage_layout_6;
    short skill_idx_stage_layout_7;
    short skill_idx_stage_layout_8;
    short skill_idx_stage_layout_9;
    short skill_idx_stage_layout_10;
    short skill_idx_1p_life_gauge;
    short skill_idx_2p_life_gauge;
    short skill_idx_1p_special_gauge;
    short skill_idx_2p_special_gauge;
    short skill_idx_position_timer;
    short skill_idx_pos_1p_face;
    short skill_idx_pos_2p_face;
    short skill_idx_pos_special_stock_1p;
    short skill_idx_pos_special_stock_2p;
    short skill_idx_pos_victory_mark_1p;
    short skill_idx_pos_victory_mark_2p;
    short skill_idx__title_cursor;
    short skill_idx_position_for_story_mode;
    short skill_idx_position_for_vs_mode;
    short skill_idx_continue_cursor;
    short skill_idx_position_cursor_it_does;
    short skill_idx_position_cursor_it_does_not;
    short skill_idx_1p_vs_screen_cursor;
    short skill_idx_2p_vs_screen_cursor;
    short skill_idx_1p_vs_screen_cursor_after_input;
    short skill_idx_2p_vs_screen_cursor_after_input;
    short skill_idx_pos_cursor_for_team_battle;
    short skill_idx_pause;
    short skill_idx_spare6; /* From this point on these skills may not be built-ins. Could be tracked by accident. */
    short skill_idx_spare7;
    short skill_idx_spare8;
    short skill_idx_spare9;
    short skill_idx_spare10;
    short skill_idx_spare11;
    short skill_idx_spare12;
    short skill_idx_spare13;
    short skill_idx_spare14;
    short skill_idx_spare15;
    short skill_idx_spare16;
    short skill_idx_spare17;
    short skill_idx_spare18;
    short skill_idx_spare19;
    byte field145_0x146610[76];
    short character_select_start_x;
    short character_select_start_y;
    short distance_between_characters_x;
    short distance_between_characters_y;
    short columns_in_select_screen;
    short rows_in_select_screen;
    short player1_cursor_x;
    short player1_cursor_y;
    short player1_selection_width;
    short player1_selection_height;
    short player2_cursor_x;
    short player2_cursor_y;
    short player2_selection_width;
    short player2_selection_height;
    char story_mode-setting_check[21]; /* Looks like '3' if set properly, in-engine will throw an error otherwise. Likely more than 21. */
    byte field161_0x14668d[975];
};

typedef struct file_stage file_stage, *Pfile_stage;

struct file_stage {
    char header_start_string[12];
    int loaded_flag;
    char stage_name[256]; /* This has two names in it...? */
    struct kgt_skill_info_struct skill_info_array[1023];
    char too_many_skills_check;
    INT8 field5_0x9cea;
    struct kgt_skill_step_struct skill_steps_array[65536];
    struct kgt_probably_images_struct images_struct[8192];
    struct kgt_pal_color pal_1[256];
    struct kgt_pal_color pal_2[256];
    struct kgt_pal_color pal_3[256];
    struct kgt_pal_color pal_4[256];
    struct kgt_pal_color pal_5[256];
    struct kgt_pal_color pal_6[256];
    struct kgt_pal_color pal_7[256];
    struct kgt_pal_color pal_8[256];
    struct kgt_sound_struct field16_0x133ceb[256];
    undefined field17_0x1366eb;
    int four_zeros;
    char BGM_selection;
    undefined field20_0x1366f1;
    undefined field21_0x1366f2;
    undefined field22_0x1366f3;
};

