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
typedef struct file_stage file_stage, *Pfile_stage;

typedef struct kgt_skill_info_struct kgt_skill_info_struct, *Pkgt_skill_info_struct;

typedef char INT8;

typedef struct kgt_skill_step_struct kgt_skill_step_struct, *Pkgt_skill_step_struct;

typedef struct kgt_probably_images_struct kgt_probably_images_struct, *Pkgt_probably_images_struct;

typedef struct kgt_pal_color kgt_pal_color, *Pkgt_pal_color;

typedef struct kgt_sound_struct kgt_sound_struct, *Pkgt_sound_struct;

struct kgt_sound_struct {
    void *buffer;
    char name[32];
    int buffer_size;
    undefined field3_0x28;
    undefined field4_0x29;
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

struct kgt_probably_images_struct {
    int *ptr_bytes;
    int height;
    int width;
    int unk;
    int size;
};

struct kgt_pal_color {
    char b;
    char g;
    char r;
    char field3_0x3;
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
    byte unk_or_empty_d[5];
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
    byte unk_or_empty_f[2];
    char system_bitmask; /* editor won't read file = +0x1, offset = +0x02, story mode +0x04, vs mode +0x08, vs team mode +0x10, numbers shown on life +0x20, cursor stays +0x40 */
    byte unk_or_empty_g[3];
    char common_images[200][32];
    byte unk_or_empty_h[264];
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
    byte unk_or_empty_i[996];
};

typedef struct file_demo file_demo, *Pfile_demo;

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

typedef struct file_character file_character, *Pfile_character;

typedef struct character_file_command_struct character_file_command_struct, *Pcharacter_file_command_struct;

typedef struct character_hit_junction_info character_hit_junction_info, *Pcharacter_hit_junction_info;

typedef struct character_file_common_images_struct character_file_common_images_struct, *Pcharacter_file_common_images_struct;

typedef struct character_cpu_command_struct character_cpu_command_struct, *Pcharacter_cpu_command_struct;

typedef struct character_story_entry character_story_entry, *Pcharacter_story_entry;

typedef struct character_cpu_command_skill character_cpu_command_skill, *Pcharacter_cpu_command_skill;

typedef struct character_story_entry_cpu character_story_entry_cpu, *Pcharacter_story_entry_cpu;

struct character_cpu_command_skill {
    char directional; /* starts at 1 = no direction, continues starting at right, ending at up-right */
    char continue_flag; /* 30 = go to next skill, 20 = end skill, 10 = inactive? unsure. */
    short skill_idx;
    short skill_timing;
    undefined field4_0x6;
};

struct character_file_common_images_struct {
    short e_number;
    short x_movement;
    short y_movement;
};

struct character_hit_junction_info {
    short allottment_idx;
    short spark_idx;
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

struct character_cpu_command_struct {
    char CPU_section;
    undefined field1_0x1;
    undefined field2_0x2;
    undefined field3_0x3;
    undefined field4_0x4;
    undefined field5_0x5;
    undefined field6_0x6;
    undefined field7_0x7;
    undefined field8_0x8;
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
    undefined field24_0x6e;
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

struct file_character {
    char header_start_string[12];
    int actions_loaded_flag;
    char character_name[256];
    int skill_info_amount;
    struct kgt_skill_info_struct skill_info_array[1023];
    char too_many_skills_check;
    byte field6_0x9cee[31];
    char skill_steps_array_amt;
    byte field8_0x9d0e[6];
    int skill_steps_array_amount_int;
    struct kgt_skill_step_struct skill_steps_array[65536];
    struct kgt_probably_images_struct images[8192];
    struct kgt_pal_color field12_0x131d18[256];
    struct kgt_pal_color field13_0x132118[256];
    struct kgt_pal_color field14_0x132518[256];
    struct kgt_pal_color field15_0x132918[256];
    struct kgt_pal_color field16_0x132d18[256];
    struct kgt_pal_color field17_0x133118[256];
    struct kgt_pal_color field18_0x133518[256];
    struct kgt_pal_color field19_0x133918[256];
    byte field20_0x133d18[256];
    int sound_amount;
    struct kgt_sound_struct field22_0x133e1c[256];
    int four_zeros;
    int command_struct_amount;
    struct character_file_command_struct command_struct_array[100];
    int hit_junction_amount;
    struct character_hit_junction_info hit_junction_info[200];
    int common_images_amount;
    struct character_file_common_images_struct common_images_struct[200];
    struct character_cpu_command_struct CPU_commands[100];
    byte field31_0x13bb60[10];
    char start_of_section_b;
    byte field33_0x13bb6b[85];
    short age;
    byte field35_0x13bbc2[2];
    char gender; /* 00 = male, 01 = female, 02 = both, 03 = none */
    byte field37_0x13bbc5[1740];
    short y_pos_of_SideHP;
    short interv;
    char shave_ratio;
    char life_rev_y_start_pos;
    char life_rev_correction;
    char character_rev;
    char guard_button; /* 00 = A, 05 = F */
    short life_gauge_max;
    byte field46_0x13c29c[2];
    short special_stock_gauge_max;
    byte field48_0x13c2a0[2];
    short special_stock_max;
    byte field50_0x13c2a4[2];
    char guard_button_bool; /* 00 = false, 08 = true */
    byte field52_0x13c2a7[7];
    short special_gauge_increase_on_attack;
    short special_gauge_increase_on_hit;
    byte field55_0x13c2b2[3];
    char start_of_section_c;
    byte field57_0x13c2b6[3];
    struct character_story_entry story_entries[100];
    char start_of_section_d;
    byte field60_0x141332[4524];
};

