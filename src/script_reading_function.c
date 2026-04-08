
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void script_reading_logic(void)

{
  char cVar1;
  short sVar2;
  short sVar3;
  undefined2 uVar4;
  ushort uVar5;
  kgt_skill_step_struct *pkVar6;
  undefined3 uVar7;
  char cVar8;
  uint uVar9;
  int time_rand;
  int *other_player_poss_relating;
  uint uVar10;
  int stage_unk_var_b;
  int image_wait_frames;
  int player_x_momentum;
  int player_y_momentum;
  int add_to_special;
  OBJ_STRUCT_ptr_64_undefined1 PS_obj;
  int rand;
  byte bVar11;
  byte is_if_failed;
  int 0x650_idx;
  int char_idx;
  int 0650_size_offset;
  OBJ_STRUCT *pOVar12;
  int new_special_gauge;
  kgt_pal_color kVar13;
  int i20;
  int player_ignore_flag_flag;
  kgt_character_struct *object_addy;
  int ps_i;
  OBJ_STRUCT *current_obj;
  OBJ_STRUCT **ppOVar14;
  kgt_skill_step_struct *skill;
  kgt_character_struct_ptr_57077_int PS_players;
  bool is_1p_story;
  bool missing_x_flags_flag;
  uint local_11c;
  int ps_i3;
  int ps_i2;
  short *char_i;
  int local_108;
  void *local_104;
  char local_100 [256];
  int player_file_buff_idx2;
  int player_file_buff_idx3;
  int temp_5f04860c28;
  uint game_round;
  int stage_unk_poss_action_idx;
  int unk_actionscript_final_0x10;
  int mystery_val_sub_bool;
  int stage_unk_poss_action;
  OBJ_STRUCT *piVar16;
  character_story_entry_cpu *puVar1;
  int current_player_poss_relating;
  bool match_found;
  int current_time;
  int initial_y_val;
  kgt_skill_step_struct *hitbox;
  int current_skill_idx;
  byte mvmt_flags;
  byte m_val;
  byte RC_flags;
  ushort skill_id;
  byte command_id;
  uint skill_id_2;
  int actionscript_idx;
  int sc_command_id;
  ushort image_wait;
  byte pallette_flash;
  int flash_player_buffer;
  ushort flash_duration;
  int flash_opponent_buffer;
  ushort opp_flash_duration;
  ushort GS_skill_idx;
  int GS_player_buffer;
  ushort GL_skill_idx;
  OBJ_STRUCT *opp_obj_ptr;
  byte RP_flags;
  int RP_player_direction;
  int GC_player_buffer;
  short GC_life_opp;
  int random_skillcommand;
  uint DB_input;
  int db_player_buffer;
  short FA_width;
  int *FA_m_number;
  byte FA_flags;
  byte player_down_time;
  int PS_player_buffer;
  byte PS_opponent_down_time;
  int PS_player_cpu;
  char cancel_empty;
  byte var_LHS_long;
  byte var_lhs;
  byte var_flags;
  ushort COM_skill_idx;
  int COM_new_skillscript_idx;
  undefined1 cancel_flags;
  undefined1 cancel_skill_idx;
  kgt_obj_type curr_obj_type;
  GAME_MODES game_mode;
  byte life_recover_number;
  kgt_skill_struct *pActionAlloc;
  int player_file_buff_idx;
  int special_stock_gauge_max;
  
  current_obj = PTR_POSS_CURRENT_OBJ;
  object_addy = local_104;
  switch(PTR_POSS_CURRENT_OBJ->obj_type) {
  case 0:
  case 1:
  case player_file:
    object_addy = PLAYER_KGT_BUFFER + PTR_POSS_CURRENT_OBJ->player_file_buffer;
    break;
  case main_kgt_file:
                    /* DON'T FORGET TO CHANGE THIS BACK TO PROPER FILE TYPE */
    object_addy = &DAT_KGT_FILE_BUFFER_00433240;
    break;
  case demo_file:
    object_addy = (kgt_character_struct *)&UNK_DEMO_FILE_BUFFER_00425a60;
    break;
  case stage_file:
    object_addy = (kgt_character_struct *)&UNK_STAGE_FILES_00445740;
  }
  if (PTR_POSS_CURRENT_OBJ->object_process_step == 0) {
    PTR_POSS_CURRENT_OBJ->object_process_step = 1;
    game_mode = GAME_STATE.GAME_MODE;
    switch(current_obj->obj_type) {
    case 0:
      is_1p_story = GAME_STATE.GAME_MODE == 1P_story;
      current_obj->param2_maybe_50_or_46 = (&INT_0041f130)[*(uint *)&current_obj->2_or_3 & 1];
      if (is_1p_story) {
        special_stock_gauge_max = (&POSS_STORY_ARRAY)[STORY_MODE_IDX];
        player_file_buff_idx = current_obj->player_file_buffer;
        if (player_file_buff_idx == 0) {
          cVar8 = PLAYER_KGT_BUFFER[0].character_story_entries[special_stock_gauge_max].field_0x3;
          if (GAME_STATE.poss_current_round_count == 1) {
            if (cVar8 == '\0') {
                    /* Probably_health assigned starting_health? */
              object_addy->health = *(int *)&object_addy->life_gauge_max;
            }
          }
          else if (cVar8 == '\0') {
            object_addy->health = *(int *)&object_addy->life_gauge_max;
          }
          else {
            life_recover_number =
                 PLAYER_KGT_BUFFER[0].character_story_entries[special_stock_gauge_max].
                 life_recover_number;
            if (life_recover_number == 100) {
              object_addy->health = *(int *)&object_addy->life_gauge_max;
            }
            else if (life_recover_number != 0) {
              uVar9 = object_addy->health +
                      ((uint)life_recover_number * *(int *)&object_addy->life_gauge_max) / 100;
              object_addy->health = uVar9;
              uVar10._0_2_ = object_addy->life_gauge_max;
              uVar10._2_1_ = object_addy->field1823_0x7cac[0];
              uVar10._3_1_ = object_addy->field1823_0x7cac[1];
              if (uVar10 < uVar9) {
                object_addy->health = uVar10;
              }
            }
          }
                    /* Checking the player ignore bit on each cpu enemy */
          *(undefined4 *)&object_addy->enemy_bitmask = 0xfffffffe;
          if (((undefined1  [26])
               PLAYER_KGT_BUFFER[0].character_story_entries[special_stock_gauge_max].
               character_story_entry_cpu_array[0] & (undefined1  [26])0x200) !=
              (undefined1  [26])0x0) {
            *(undefined4 *)&object_addy->enemy_bitmask = 0xfffffffc;
          }
          if (((undefined1  [26])
               PLAYER_KGT_BUFFER[0].character_story_entries[special_stock_gauge_max].
               character_story_entry_cpu_array[1] & (undefined1  [26])0x200) !=
              (undefined1  [26])0x0) {
            *(uint *)&object_addy->enemy_bitmask = *(uint *)&object_addy->enemy_bitmask & 0xfffffffb
            ;
          }
          if (((undefined1  [26])
               PLAYER_KGT_BUFFER[0].character_story_entries[special_stock_gauge_max].
               character_story_entry_cpu_array[2] & (undefined1  [26])0x200) !=
              (undefined1  [26])0x0) {
            *(uint *)&object_addy->enemy_bitmask = *(uint *)&object_addy->enemy_bitmask & 0xfffffff7
            ;
          }
          if (((undefined1  [26])
               PLAYER_KGT_BUFFER[0].character_story_entries[special_stock_gauge_max].
               character_story_entry_cpu_array[3] & (undefined1  [26])0x200) !=
              (undefined1  [26])0x0) {
            *(uint *)&object_addy->enemy_bitmask = *(uint *)&object_addy->enemy_bitmask & 0xffffffef
            ;
          }
          if (((undefined1  [26])
               PLAYER_KGT_BUFFER[0].character_story_entries[special_stock_gauge_max].
               character_story_entry_cpu_array[4] & (undefined1  [26])0x200) !=
              (undefined1  [26])0x0) {
            *(uint *)&object_addy->enemy_bitmask = *(uint *)&object_addy->enemy_bitmask & 0xffffffdf
            ;
          }
          if (((undefined1  [26])
               PLAYER_KGT_BUFFER[0].character_story_entries[special_stock_gauge_max].
               character_story_entry_cpu_array[5] & (undefined1  [26])0x200) !=
              (undefined1  [26])0x0) {
            *(uint *)&object_addy->enemy_bitmask = *(uint *)&object_addy->enemy_bitmask & 0xffffffbf
            ;
          }
          if (((undefined1  [26])
               PLAYER_KGT_BUFFER[0].character_story_entries[special_stock_gauge_max].
               character_story_entry_cpu_array[6] & (undefined1  [26])0x200) !=
              (undefined1  [26])0x0) {
            *(uint *)&object_addy->enemy_bitmask = *(uint *)&object_addy->enemy_bitmask & 0xffffff7f
            ;
          }
          object_addy->show_life = 1;
          object_addy->round_start_var_c = 0;
        }
        else {
          object_addy->health = *(int *)&object_addy->life_gauge_max;
          puVar1 = (character_story_entry_cpu *)
                   (special_stock_gauge_max * 0xce + 0x4d9a47 + player_file_buff_idx * 0x1a);
          uVar10 = *(uint *)puVar1;
                    /* I might have the left and right digits mixed up for
                       story_character_entry_info_bitmask */
          object_addy->show_life = (short)(uVar10 & 1);
          object_addy->round_start_var_c = (short)((uVar10 & 1) >> 0x10);
          *(uint *)&object_addy->enemy_bitmask = (uint)(byte)puVar1->enemy_bitmask;
          uVar10 = *(uint *)puVar1 >> 1 & 3;
                    /* If character entry info bitmask has the time bit set */
          if (uVar10 == 1) {
            *(uint *)&current_obj->time_method_number_in_frames =
                 (uint)(byte)puVar1->time_method_number * 100;
            if (puVar1->time_method_number_random != '\0') {
              time_rand = _rand();
              *(int *)&current_obj->time_method_number_in_frames =
                   *(int *)&current_obj->time_method_number_in_frames +
                   (time_rand % (int)(uint)(byte)puVar1->time_method_number_random) * 100;
              current_obj = PTR_POSS_CURRENT_OBJ;
            }
          }
          else {
                    /* If it has the life bit set */
            if ((uVar10 == 2) &&
               ((int)(uint)(byte)puVar1->life_method_life_amount <=
                PLAYER_KGT_BUFFER[(byte)puVar1->life_method_target].health)) {
              current_obj->object_process_step = 0;
              return;
            }
          }
          object_addy->poss_relating_to_player_idx = -1;
                    /* Currently do not have recorded use for this variable. Likely a 0 */
          object_addy->special_gauge_tokens = (int)object_addy->field1831_0x7cc2[0];
          object_addy->special_gauge = 0;
          if (((undefined1  [26])*puVar1 & (undefined1  [26])0x200) == (undefined1  [26])0x0) {
            current_obj->pos_player_direction = 1;
          }
        }
        current_obj->player_file_buffer_2 = current_obj->player_file_buffer;
      }
      else if ((0 < (int)game_mode) && ((int)game_mode < 3)) {
        player_file_buff_idx2 = current_obj->player_file_buffer;
        object_addy->health = *(int *)&object_addy->life_gauge_max;
        current_obj->player_file_buffer_2 = player_file_buff_idx2;
        player_file_buff_idx3 = current_obj->player_file_buffer;
                    /* player_file_buff_idx3 -> ceiling 31 -> multiply by two? */
        *(int *)&object_addy->enemy_bitmask = -1 - (1 << ((byte)player_file_buff_idx3 & 0x1f));
        if (player_file_buff_idx3 != 0) {
          *(undefined4 *)&object_addy->player_buff_idx_is_not_0 = 1;
          current_obj->pos_player_direction = 1;
        }
        if (current_obj->player_file_buffer == 0) {
          current_obj->param_3 = 0x1860000;
          object_addy->pos_x_pos = 0x1860000;
        }
        else {
          current_obj->param_3 = 0x37a0000;
          object_addy->pos_x_pos = 0x37a0000;
        }
      }
      temp_5f04860c28 = current_obj->param_4;
      object_addy->pos_x_pos = current_obj->param_3;
      object_addy->pos_y_pos = temp_5f04860c28;
      object_addy->life_gauge_max2 = *(int *)&object_addy->life_gauge_max;
      game_round = GAME_STATE.poss_current_round_count;
      object_addy->field6357_0xdf01 = 0;
      if ((int)game_round < 2) {
        object_addy->special_gauge_tokens = (int)object_addy->field1831_0x7cc2[0];
        object_addy->special_gauge = 0;
      }
      object_addy->special_stock_max2 = object_addy->special_stock_max;
      object_addy->special_stock_gauge_max2 = *(int *)&object_addy->special_stock_gauge_max;
      object_addy->field6367_0xdf25 = 0;
      object_addy->field6368_0xdf29 = 0;
      object_addy->CPU = (int)current_obj;
      object_addy->poss_opponent_obj_ptr = (OBJ_STRUCT *)0x0;
      object_addy->poss_opponent_obj_ptr_2? = (OBJ_STRUCT *)0x0;
      object_addy->field6401_0xdf6d = 0;
      object_addy->field6402_0xdf71 = 0;
      object_addy->cpu_command_idx = 0;
      object_addy->winpoint = 0;
      *(undefined4 *)&object_addy->field_0xdf7d = 0;
      object_addy->script_reading_0x14 = 0x14;
      object_addy->script_reading_01_field5 = 1;
      object_addy->field6392_0xdf55 = 0;
      object_addy->field6455_0xdfef = 0;
      object_addy->w_ko_unk_var = 0;
      object_addy->field6384_0xdf49 = 0;
      object_addy->field6356_0xdefd = 0;
      object_addy->unk_image_wait_flag = 0;
      object_addy->something_to_do_with_starting_health2 = 0;
      object_addy->has_crouch_advance = 0;
      object_addy->has_crouch_retreat = 0;
      pActionAlloc = (object_addy->kgt_core).p_actions_alloc;
      if ((ushort)pActionAlloc[(ushort)object_addy->skill_idx_crouch_advance].starting_step_idx + 1
          < (uint)(ushort)pActionAlloc[(ushort)object_addy->skill_idx_crouch_advance + 1].
                          starting_step_idx) {
        object_addy->has_crouch_advance = 1;
      }
      pActionAlloc = (object_addy->kgt_core).p_actions_alloc;
                    /* Checking for crouch retreat vs turn standing */
      if ((ushort)pActionAlloc[(ushort)object_addy->skill_idx_crouch_retreat].starting_step_idx + 1
          < (uint)(ushort)pActionAlloc[(ushort)object_addy->skill_idx_crouch_retreat + 1].
                          starting_step_idx) {
        object_addy->has_crouch_retreat = 1;
      }
      current_player_poss_relating =
           PLAYER_KGT_BUFFER[current_obj->player_file_buffer].poss_relating_to_player_idx;
      if (current_player_poss_relating == -1) {
        current_player_poss_relating = 0;
      }
      char_i = (short *)0x0;
      do {
        match_found = false;
        char_idx = 0;
        other_player_poss_relating = &PLAYER_KGT_BUFFER[0].poss_relating_to_player_idx;
        do {
          if ((current_obj->player_file_buffer != char_idx) &&
             (current_player_poss_relating == *other_player_poss_relating)) {
            match_found = true;
          }
          other_player_poss_relating = (int *)((int)other_player_poss_relating + 0xe03f);
          char_idx = char_idx + 1;
        } while ((int)other_player_poss_relating < 0x54ff83);
        if (!match_found) {
          PLAYER_KGT_BUFFER[current_obj->player_file_buffer].poss_relating_to_player_idx =
               current_player_poss_relating;
          break;
        }
        current_player_poss_relating = current_player_poss_relating + 1U & 0x80000007;
        if (current_player_poss_relating < 0) {
          current_player_poss_relating = (current_player_poss_relating - 1U | 0xfffffff8) + 1;
        }
        char_i = (short *)((int)char_i + 1);
      } while ((int)char_i < 8);
      player_file_buff_idx = GAME_STATE.field166_0xf8;
      special_stock_gauge_max = GAME_STATE.field165_0xf4;
      if ((GAME_STATE.GAME_MODE == VS_team) &&
         (GAME_STATE.field163_0xec == current_obj->player_file_buffer)) {
        object_addy->health = GAME_STATE.field164_0xf0;
        object_addy->special_gauge_tokens = special_stock_gauge_max;
        object_addy->special_gauge = player_file_buff_idx;
      }
      pActionAlloc = (object_addy->kgt_core).p_actions_alloc;
      if ((ushort)pActionAlloc[(ushort)object_addy->skill_idx_R1].starting_step_idx + 1 <
          (uint)(ushort)pActionAlloc[(ushort)object_addy->skill_idx_R1 + 1].starting_step_idx) {
        pOVar12 = FIND_EMPTY_OBJ(current_obj->jmp_idx,0xd,0,0);
        current_obj = PTR_POSS_CURRENT_OBJ;
        pOVar12->obj_type = player_file;
        uVar5 = object_addy->skill_idx_R1;
        pOVar12->player_file_buffer = current_obj->player_file_buffer;
        pOVar12->action_idx = (uint)uVar5;
        *(uint *)&pOVar12->actionscript_idx =
             (uint)(ushort)(object_addy->kgt_core).p_actions_alloc[uVar5].starting_step_idx;
      }
      else {
        current_obj->unk_bitmask = current_obj->unk_bitmask | 0x80000000;
      }
      switch_current_object_action((uint)(ushort)object_addy->skill_idx_start);
      current_obj = PTR_POSS_CURRENT_OBJ;
      PTR_POSS_CURRENT_OBJ->obj_ptr_b =
           (OBJ_STRUCT *)((uint)PTR_POSS_CURRENT_OBJ->obj_ptr_b & 0xfffffff7 | 4);
      memzero(INPUT_BUFFER_A + current_obj->player_file_buffer,0x1000);
      memzero(&object_addy->start_of_0x6,6);
      memzero(&object_addy->variable_A,0x20);
      memzero(&object_addy->start_of_0x2c,0x2c);
      current_obj = PTR_POSS_CURRENT_OBJ;
      PTR_POSS_CURRENT_OBJ->unk_bitmask = PTR_POSS_CURRENT_OBJ->unk_bitmask | 0x40000000;
      ppOVar14 = object_addy->object_mNumbers;
      for (special_stock_gauge_max = 10; special_stock_gauge_max != 0;
          special_stock_gauge_max = special_stock_gauge_max + -1) {
        *ppOVar14 = (OBJ_STRUCT *)0x0;
        ppOVar14 = ppOVar14 + 1;
      }
      break;
    case 1:
      current_obj->player_file_buffer_2 = current_obj->player_file_buffer;
      break;
    case stage_file:
      current_obj->stage_action_idx = current_obj->action_idx;
      current_obj->stage_skillscript_idx = *(int *)&current_obj->actionscript_idx;
      break;
    case player_file:
      current_obj->unk_bitmask = current_obj->unk_bitmask | 0x40000000;
    }
    current_obj->skill_idx_2 = current_obj->action_idx;
  }
  else if (PTR_POSS_CURRENT_OBJ->object_process_step != 1) {
    return;
  }
                    /* Everything after this is after the initial frame */
  if ((current_obj->2_or_3 & 1) == 0) {
    current_obj->compare_to_param_4 = 0x3980000;
  }
  else {
    current_obj->compare_to_param_4 = 0x3520000;
  }
  if ((GAME_STATE.pause_flag != 0) &&
     (curr_obj_type = current_obj->obj_type, -1 < (int)curr_obj_type)) {
    if ((int)curr_obj_type < 2) {
      return;
    }
    if (curr_obj_type == player_file) {
      return;
    }
  }
                    /* I can't find anywhere where this variable is assigned to something other than
                       0 */
  if (current_obj->0x650_index != 0) {
    uVar10 = (uint)(byte)current_obj->0x650_index;
    0650_size_offset = uVar10 * 0x650;
    if (*(char *)((int)UNK_STAGE_FILES_00445740.kgt_core.pallette_extra_bytes[uVar10 * 0x194 + 0x37]
                 + 4) != '\0') {
      stage_unk_poss_action_idx =
           *(int *)(UNK_STAGE_FILES_00445740.kgt_core.pallette_extra_bytes + uVar10 * 0x194 + 0x36);
      unk_actionscript_final_0x10 =
           (int)((object_addy->kgt_core).p_actionscripts_alloc +
                *(int *)&current_obj->actionscript_idx + -1);
      stage_unk_var_b =
           (int)UNK_STAGE_FILES_00445740.kgt_core.pallette_extra_bytes[uVar10 * 0x194 + 0x38] + -1;
      UNK_STAGE_FILES_00445740.kgt_core.pallette_extra_bytes[uVar10 * 0x194 + 0x38] =
           (kgt_pal_color)stage_unk_var_b;
      if (stage_unk_var_b < 0) {
        kVar13.g = '\0';
        kVar13.r = '\0';
        kVar13.field3_0x3 = '\0';
        kVar13.b = *(byte *)((int)UNK_STAGE_FILES_00445740.kgt_core.pallette_extra_bytes
                                  [uVar10 * 0x194 + 0x37] + 4);
        UNK_STAGE_FILES_00445740.kgt_core.pallette_extra_bytes[uVar10 * 0x194 + 0x38] = kVar13;
        *(int *)((stage_unk_poss_action_idx + 1) * 0x10 + 0x447930 + 0650_size_offset) =
             current_obj->param_3;
        stage_unk_poss_action = stage_unk_poss_action_idx * 0x10 + 0x447930 + 0650_size_offset;
        mystery_val_sub_bool = current_obj->pos_player_direction;
        *(int *)(stage_unk_poss_action + 0x14) = current_obj->param_4;
        *(uint *)(stage_unk_poss_action + 0x18) =
             ((*(ushort *)(unk_actionscript_final_0x10 + 3) & 0x4000) >> 0xe) +
             mystery_val_sub_bool * 4;
        *(int *)(stage_unk_poss_action + 0x1c) = unk_actionscript_final_0x10;
        UNK_STAGE_FILES_00445740.kgt_core.pallette_extra_bytes[uVar10 * 0x194 + 0x36] =
             (kgt_pal_color)
             (((int)UNK_STAGE_FILES_00445740.kgt_core.pallette_extra_bytes[uVar10 * 0x194 + 0x36] +
              1) % 100);
      }
    }
  }
  if (current_obj->hit_junction_idx != 0) {
    current_obj->action_idx = -1;
    assign_action_and_reset_some_data(current_obj->hit_junction_idx & 0xffff);
    current_obj = PTR_POSS_CURRENT_OBJ;
    *(uint *)&PTR_POSS_CURRENT_OBJ->actionscript_idx =
         *(int *)&PTR_POSS_CURRENT_OBJ->actionscript_idx +
         ((uint)PTR_POSS_CURRENT_OBJ->hit_junction_idx >> 0x10);
    current_obj->hit_junction_idx = 0;
    current_obj->loop_frequency = 0;
    obj_reset_values();
    obj_0x129_to_0(PTR_POSS_CURRENT_OBJ);
    memzero_mystery_arrays(PTR_POSS_CURRENT_OBJ);
    current_obj = PTR_POSS_CURRENT_OBJ;
    goto LAB_00412564;
  }
                    /* Countdown the clock */
  current_time = *(int *)&current_obj->time_method_number_in_frames;
  if (current_time != 0) {
    if (current_time == -1) {
      return;
    }
    *(int *)&current_obj->time_method_number_in_frames = current_time + -1;
    return;
  }
  curr_obj_type = current_obj->obj_type;
  if (curr_obj_type == 0) {
    PLAYER_KGT_BUFFER[current_obj->player_file_buffer].field6465_0xdfff = 0;
    FUN_0040e5c0();
    FUN_00411810();
    if (object_addy->field6367_0xdf25 != 0) {
      if (object_addy->field6368_0xdf29 == 0) {
        object_addy->field6367_0xdf25 = object_addy->field6367_0xdf25 + -1;
      }
      else {
        object_addy->field6368_0xdf29 = object_addy->field6368_0xdf29 + -1;
      }
    }
    current_obj = PTR_POSS_CURRENT_OBJ;
    initial_y_val = PTR_POSS_CURRENT_OBJ->param_4;
    object_addy->pos_x_pos = PTR_POSS_CURRENT_OBJ->param_3;
    object_addy->pos_y_pos = initial_y_val;
    goto LAB_00412564;
  }
  if (curr_obj_type != 1) {
    if (curr_obj_type == player_file) {
      piVar16 = current_obj->parent_obj;
      if (piVar16->jmp_idx == reset_index) {
switchD_0041270c_default:
        FUN_0040e4a0();
        return;
      }
      if (piVar16->drawing_flag != -1) {
        return;
      }
      current_obj->param_3 = piVar16->param_3;
      current_obj->param_4 = current_obj->parent_obj->compare_to_param_4;
      current_obj->pos_player_direction = current_obj->parent_obj->pos_player_direction;
    }
    goto LAB_00412564;
  }
  if ((current_obj->compare_to_param_4 <= current_obj->param_4) && (0 < current_obj->y_momentum)) {
    current_obj->param_4 = current_obj->compare_to_param_4;
    current_obj->x_gravity = 0;
    current_obj->x_momentum = 0;
    current_obj->y_gravity = 0;
    current_obj->y_momentum = 0;
    current_obj->obj_ptr_b = (OBJ_STRUCT *)((uint)current_obj->obj_ptr_b & 0xfffffffc);
    current_obj->action_idx = -1;
    if (current_obj->stage_action_idx == 0) {
      FUN_0040e580();
      current_obj = PTR_POSS_CURRENT_OBJ;
      PTR_POSS_CURRENT_OBJ->obj_ptr_b =
           (OBJ_STRUCT *)((uint)PTR_POSS_CURRENT_OBJ->obj_ptr_b & 0xffffffe3);
    }
    else {
      uVar10 = current_obj->stage_action_idx & 0xffff;
      current_obj->action_idx = uVar10;
      *(uint *)&current_obj->actionscript_idx =
           (uint)(ushort)PLAYER_KGT_BUFFER[current_obj->player_file_buffer].kgt_core.p_actions_alloc
                         [uVar10].starting_step_idx + ((uint)current_obj->stage_action_idx >> 0x10);
      current_obj->stage_action_idx = 0;
      current_obj->image_wait_frames = 0;
      memzero_mystery_arrays(current_obj);
      current_obj = PTR_POSS_CURRENT_OBJ;
    }
  }
  if ((((current_obj->param_3 < -0x320000) || (0x5320000 < current_obj->param_3)) ||
      (current_obj->param_4 < -0x320000)) || (0x3f20000 < current_obj->param_4)) {
    if ((current_obj->unk_bitmask & 0x20000000U) == 0) {
      FUN_0040e4a0();
      current_obj = PTR_POSS_CURRENT_OBJ;
      goto LAB_004124fb;
    }
  }
  else {
LAB_004124fb:
    if ((current_obj->unk_bitmask & 0x20000000U) == 0) goto LAB_00412564;
  }
  if (current_obj->parent_obj->jmp_idx == reset_index) {
    FUN_0040e4a0();
    current_obj = PTR_POSS_CURRENT_OBJ;
  }
LAB_00412564:
  if ((current_obj->image_wait_frames < 0) ||
     (special_stock_gauge_max = current_obj->image_wait_frames + -100,
     current_obj->image_wait_frames = special_stock_gauge_max, -1 < special_stock_gauge_max)) {
    return;
  }
  local_108 = 1;
  hitbox = (kgt_skill_step_struct *)(current_obj->hitbox_attack_array + 0x13);
  i20 = 20;
  do {
    if ((*(int *)hitbox != 0) && ((*(byte *)(*(int *)hitbox + 10) & 2) != 0)) {
      current_obj->obj_ptr_b = (OBJ_STRUCT *)((uint)current_obj->obj_ptr_b & 0xffffffef);
    }
    i20 = i20 + -1;
    hitbox = (kgt_skill_step_struct *)&hitbox[-1].field_0xc;
  } while (i20 != 0);
Pre_Script_reading_switch_statement:
                    /* *** WHERE READING THE ACTIONSCRIPT SEEMS TO BEGIN *** */
  current_skill_idx = current_obj->action_idx;
  local_108 = local_108 + 1;
  if (local_108 < 301) {
    if ((int)(uint)(ushort)(object_addy->kgt_core).p_actions_alloc[current_skill_idx + 1].
                           starting_step_idx <= *(int *)&current_obj->actionscript_idx)
    goto script_switch_statement_case_0x29;
Script_reading_switch_statement:
    skill = (object_addy->kgt_core).p_actionscripts_alloc + *(int *)&current_obj->actionscript_idx;
                    /* First byte is type of script
                       
                       01 - M
                       02 - DS
                       03 - S
                       04 - O
                       05 - E
                       07 - RC
                       09 - SF
                       0A - SG
                       0B - SC
                       0C - I
                       0E - EB
                       10 - GS
                       11 - GL
                       14 - RP
                       15 - GC
                       16 - DB
                       17 - REACTION
                       18 - FA
                       19 - FD
                       1A - PS
                       1E - C
                       1F - V
                       20 - RANDOM
                       23 COL OBJ
                       24 - COMMAND DIVERGENCE
                       25 - AI */
    switch(skill->skill_step_type) {
    case 1:
      goto switchD_00412610_compute_momentum;
    case 2:
                    /* ----------------------------------
                       - DS - Conditional Branch -
                       ----------------------------------
                       0 - Type
                       1 - Condition (UNSIGNED)
                       2 - Skill ID (low, UNSIGNED)
                       3 - Skill ID (high, UNSIGNED)
                       4 - Command ID (UNSIGNED)
                       
                       - Conditions -
                       0 - not
                       1 - Landing
                       2 - Attack hits
                       3 - Defending
                       4 - Hit to wall
                       5 - in offset
                       6 - while throw do */
      if (skill->field_0x1 == '\0') goto switchD_00412610_advance_skillscript;
      special_stock_gauge_max = (uint)(byte)skill->field_0x4 * 0x10000 + (uint)*(ushort *)&skill->02
      ;
      switch(skill->field_0x1) {
      case 1:
        current_obj->stage_action_idx = special_stock_gauge_max;
        *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
        break;
      case 2:
        current_obj->case2_var_b = special_stock_gauge_max;
        *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
        break;
      case 3:
        current_obj->stage_skillscript_idx = special_stock_gauge_max;
        *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
        break;
      case 4:
        current_obj->case2_var_d = special_stock_gauge_max;
        *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
        break;
      case 5:
        current_obj->case2_var_e = special_stock_gauge_max;
        *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
        break;
      case 6:
        current_obj->case2_var_f = special_stock_gauge_max;
        *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
        break;
      default:
        goto switchD_00412610_advance_skillscript;
      }
      goto LAB_004125ae;
    case 3:
                    /* ----------------------------------
                       - S - Sound -
                       ----------------------------------
                       0 - Type
                       1 - unk
                       2 - Sound ID (low)
                       3 - Sound ID (high) */
      Handle_Sound_Skillscript_block
                ((object_addy->kgt_core).p_sound_structs + *(ushort *)&skill->02);
      current_obj = PTR_POSS_CURRENT_OBJ;
      *(int *)&PTR_POSS_CURRENT_OBJ->actionscript_idx =
           *(int *)&PTR_POSS_CURRENT_OBJ->actionscript_idx + 1;
      goto LAB_004125ae;
    case 4:
                    /* ----------------------------------
                       - O - Object -
                       ----------------------------------
                       0 - Type
                       1 - Flags
                       2 - Skill ID (low)
                       3 - Skill ID (high)
                       4 - Command ID
                       5 - It's out skill ID (low)
                       6 - It's out skill ID (high)
                       7 - It's out command ID
                       8 - X position (low)
                       9 - X position (high)
                       A - Y position (low)
                       B - Y position (high)
                       C - M. value
                       D - Depth apin
                       
                       - Flags -
                       0 - DEPTH_MASK
                       1 - DEPTH_MASK
                       2 - UnCond
                       3 - Shadow
                       4 - unk
                       5 - Parent
                       6 - Pic. X Y
                       
                       - Depths -
                       0 - IN
                       1 - Fore
                       2 - P() */
      if ((1 < (int)current_obj->obj_type) || ((skill->field_0x1 & 4) != 0)) goto LAB_00412b0a;
      m_val = skill->field_0xc;
      if (object_addy->object_mNumbers[m_val] == (OBJ_STRUCT *)0x0) goto LAB_00412b0a;
      special_stock_gauge_max = 0;
      pOVar12 = OBJ_ARRAY;
      goto OBJECT_BLOCK_LOOP;
    case 5:
    case 0x29:
                    /* 05 is END
                       29 in editor is SB (Super background) which seems unused. Code is interpreted
                       as END? */
      if (current_obj->obj_type != 0) goto switchD_0041270c_default;
script_switch_statement_case_0x29:
      if (current_obj->return_skill_idx == 0) {
        if (current_obj->loop_frequency == '\0') {
          current_obj->image_wait_frames = 0;
          obj_reset_values();
          current_obj = PTR_POSS_CURRENT_OBJ;
          PTR_POSS_CURRENT_OBJ->obj_ptr_b =
               (OBJ_STRUCT *)((uint)PTR_POSS_CURRENT_OBJ->obj_ptr_b & 0xffffffef);
          switch(current_obj->obj_type) {
          case 0:
            *(undefined4 *)&object_addy->currect_action_cancellable_flag = 0;
            object_addy->field6357_0xdf01 = 0;
            current_obj->action_idx = -1;
            object_addy->field6455_0xdfef = 0;
            FUN_00411a80();
            current_obj = PTR_POSS_CURRENT_OBJ;
            break;
          case 1:
            uVar10 = current_obj->skill_idx_2;
            if (uVar10 == (ushort)object_addy->character_select_pic_skill_idx) {
              if (current_obj->drawing_flag == 0) {
                FUN_0040e4a0();
                return;
              }
              goto LAB_004127c3;
            }
            if ((uVar10 != (ushort)object_addy->SectionE_default_0x19) ||
               (current_obj->drawing_flag == 0)) goto switchD_0041270c_default;
            current_obj->action_idx = uVar10;
            *(uint *)&current_obj->actionscript_idx =
                 (uint)(ushort)(object_addy->kgt_core).p_actions_alloc[uVar10].starting_step_idx;
            break;
          case main_kgt_file:
            if (((object_addy->kgt_core).p_actions_alloc[current_obj->skill_idx_2].field_0x23 & 0x20
                ) != 0) goto switchD_0041270c_default;
          case demo_file:
          case stage_file:
          case player_file:
            if (current_obj->drawing_flag == 0) goto switchD_0041270c_default;
            uVar10 = current_obj->skill_idx_2;
LAB_004127c3:
            pActionAlloc = (object_addy->kgt_core).p_actions_alloc;
            current_obj->action_idx = uVar10;
            *(uint *)&current_obj->actionscript_idx =
                 (uint)(ushort)pActionAlloc[uVar10].starting_step_idx;
            break;
          default:
            goto switchD_0041270c_default;
          }
        }
        else {
          cVar8 = current_obj->loop_frequency + -1;
          current_obj->loop_frequency = cVar8;
          if (cVar8 == '\0') {
            pActionAlloc = (object_addy->kgt_core).p_actions_alloc;
            uVar10 = *(uint *)&current_obj->loop_skillscript_idx & 0xffff;
            current_obj->action_idx = uVar10;
            *(uint *)&current_obj->actionscript_idx =
                 (ushort)pActionAlloc[uVar10].starting_step_idx + 1 +
                 (*(int *)&current_obj->loop_skillscript_idx >> 0x10);
          }
          else {
            pActionAlloc = (object_addy->kgt_core).p_actions_alloc;
            uVar10 = *(uint *)&current_obj->field_0x7d & 0xffff;
            current_obj->action_idx = uVar10;
            *(uint *)&current_obj->actionscript_idx =
                 (uint)(ushort)pActionAlloc[uVar10].starting_step_idx +
                 (*(int *)&current_obj->field_0x7d >> 0x10);
          }
        }
      }
      else {
        uVar10 = current_obj->return_skill_idx & 0xffff;
        current_obj->action_idx = uVar10;
        *(uint *)&current_obj->actionscript_idx =
             (ushort)(object_addy->kgt_core).p_actions_alloc[uVar10].starting_step_idx + 1 +
             (current_obj->return_skill_idx >> 0x10);
        current_obj->return_skill_idx = 0;
      }
      goto Script_reading_switch_statement;
    default:
      goto switchD_00412610_advance_skillscript;
    case 7:
                    /* ----------------------------------
                       - RC - Coor.*picture -
                       ----------------------------------
                       0 - Type
                       1 - Flags
                       2 - Throwing reaction (low)
                       3 - Throwing reaction (high)
                       4 - X (low)
                       5 - X (high)
                       6 - Y (low)
                       7 - Y (high)
                       
                       - Flags -
                       0 - Depth add (if unset, use forw)
                       1 - unk
                       2 - X turn
                       3 - Y turn
                       4 - same */
      if (((current_obj->obj_type != 0) || (*(short *)&skill->02 == 0)) ||
         (pOVar12 = object_addy->poss_opponent_obj_ptr, pOVar12 == (OBJ_STRUCT *)0x0))
      goto switchD_00412610_advance_skillscript;
      RC_flags = skill->field_0x1;
      if ((RC_flags & 1) == 0) {
                    /* If not depth add */
        uVar10 = *(uint *)&pOVar12->2_or_3;
        current_obj->param2_maybe_50_or_46 = (&INT_0041f130)[*(uint *)&current_obj->2_or_3 & 1] + -1
        ;
        special_stock_gauge_max = (&INT_0041f130)[uVar10 & 1] + 1;
      }
      else {
        uVar10 = *(uint *)&pOVar12->2_or_3;
        current_obj->param2_maybe_50_or_46 = (&INT_0041f130)[*(uint *)&current_obj->2_or_3 & 1] + 1;
        special_stock_gauge_max = (&INT_0041f130)[uVar10 & 1] + -1;
      }
      player_file_buff_idx = current_obj->pos_player_direction;
      pOVar12->param2_maybe_50_or_46 = special_stock_gauge_max;
      if ((player_file_buff_idx & 1) == 0) {
                    /* Y turn flag? */
        pOVar12->param_3 = *(short *)&skill->field_0x4 * 0x10000 + current_obj->param_3;
        if ((RC_flags & 4) == 0) goto LAB_00412f3d;
        pOVar12->pos_player_direction = 0;
      }
      else {
        pOVar12->param_3 = current_obj->param_3 + *(short *)&skill->field_0x4 * -0x10000;
        if ((RC_flags & 4) == 0) {
          pOVar12->pos_player_direction = 0;
        }
        else {
LAB_00412f3d:
          pOVar12->pos_player_direction = 1;
        }
      }
      pOVar12->param_4 = *(short *)&skill->field_0x6 * 0x10000 + current_obj->param_4;
      memzero_mystery_arrays(current_obj);
      pOVar12->x_momentum = 0;
      pOVar12->y_momentum = 0;
      pOVar12->x_gravity = 0;
      pOVar12->y_gravity = 0;
      if (pOVar12->obj_type == 0) {
        special_stock_gauge_max = pOVar12->player_file_buffer;
        uVar5 = *(ushort *)&skill->02;
        pkVar6 = PLAYER_KGT_BUFFER[special_stock_gauge_max].kgt_core.p_actionscripts_alloc;
        pOVar12->drawing_flag = -1;
        *(ushort *)&pkVar6->field_0x3 =
             *(ushort *)(special_stock_gauge_max * 0xe03f + 0x4d8e4a + (uint)uVar5 * 6) & 0x1fff |
             (ushort)(skill->field_0x1 & 0xc) << 0xc;
        uVar5 = *(ushort *)&skill->02;
        pkVar6->skill_step_type = 0xc;
        pOVar12->action_idx = 0;
        *(undefined4 *)&pOVar12->actionscript_idx = 1;
        sVar2 = PLAYER_KGT_BUFFER[special_stock_gauge_max].common_images[uVar5].y_movement;
        *(short *)&pkVar6->field_0x5 =
             PLAYER_KGT_BUFFER[special_stock_gauge_max].common_images[uVar5].x_movement;
        *(short *)&pkVar6->field_0x7 = sVar2;
        memzero_mystery_arrays(pOVar12);
        obj_0x129_to_0(pOVar12);
        sVar2 = *(short *)&skill->field_0x4;
        sVar3 = *(short *)&skill->field_0x6;
        object_addy->field6455_0xdfef = (byte)skill->field_0x1 | 0x20;
        current_obj = pOVar12->obj_ptr_b;
        *(int *)((int)&object_addy->script_obj_var_d + 2) = (int)sVar2 << 0x10;
        *(int *)&object_addy->field_0xdffb = (int)sVar3 << 0x10;
        pOVar12->obj_ptr_b = (OBJ_STRUCT *)((uint)current_obj & 0xfffffffa | 10);
      }
      current_obj = PTR_POSS_CURRENT_OBJ;
      *(undefined4 *)&pOVar12->time_method_number_in_frames = 0xffffffff;
      *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
      goto LAB_004125ae;
    case 9:
                    /* ----------------------------------
                       - SF - Loop -
                       ----------------------------------
                       0 - Type
                       1 - Frequency
                       2 - Skill ID (low)
                       3 - Skill ID (high)
                       4 - Command ID */
      if ((skill->field_0x1 == '\0') || (skill_id = *(ushort *)&skill->02, skill_id == 0))
      goto switchD_00412610_advance_skillscript;
      pActionAlloc = (object_addy->kgt_core).p_actions_alloc;
      command_id = skill->field_0x4;
      *(uint *)&current_obj->loop_skillscript_idx =
           (*(int *)&current_obj->actionscript_idx -
           (uint)(ushort)pActionAlloc[current_obj->action_idx].starting_step_idx) * 0x10000 +
           current_obj->action_idx;
      current_obj->loop_frequency = skill->field_0x1;
      skill_id_2 = (uint)skill_id;
      *(uint *)&current_obj->field_0x7d = (uint)command_id * 0x10000 + skill_id_2;
      current_obj->action_idx = skill_id_2;
      actionscript_idx = ((ushort)pActionAlloc[skill_id_2].starting_step_idx - 1) + (uint)command_id
      ;
      *(int *)&current_obj->actionscript_idx = actionscript_idx;
      *(int *)&current_obj->actionscript_idx = actionscript_idx + 1;
      goto LAB_004125ae;
    case 10:
                    /* ----------------------------------
                       - SG - GoTo -
                       ----------------------------------
                       0 - Type
                       1 - Skill ID (low)
                       2 - Skill ID (high)
                       3 - Command ID */
      if (*(ushort *)&skill->field_0x1 != 0) {
        pActionAlloc = (object_addy->kgt_core).p_actions_alloc;
        uVar10 = (uint)*(ushort *)&skill->field_0x1;
        current_obj->action_idx = uVar10;
        goto LAB_0041298b;
      }
      goto switchD_00412610_advance_skillscript;
    case 0xb:
                    /* ----------------------------------
                       - SC - Call -
                       ----------------------------------
                       0 - Type
                       1 - Skill ID (low)
                       2 - Skill ID (high)
                       3 - Command ID */
      if (*(short *)&skill->field_0x1 == 0) goto switchD_00412610_advance_skillscript;
      pActionAlloc = (object_addy->kgt_core).p_actions_alloc;
      current_obj->return_skill_idx =
           (*(int *)&current_obj->actionscript_idx -
           (uint)(ushort)pActionAlloc[current_obj->action_idx].starting_step_idx) * 0x10000 +
           current_obj->action_idx;
      uVar10 = (uint)*(ushort *)&skill->field_0x1;
      current_obj->action_idx = uVar10;
LAB_0041298b:
      sc_command_id =
           ((ushort)pActionAlloc[uVar10].starting_step_idx - 1) + (uint)(byte)skill->field_0x3;
      *(int *)&current_obj->actionscript_idx = sc_command_id;
      *(int *)&current_obj->actionscript_idx = sc_command_id + 1;
      goto LAB_004125ae;
    case 0xc:
                    /* ----------------------------------
                       - I - Image -
                       ----------------------------------
                       0 - Type
                       1 - Wait (low)
                       2 - Wait (high)
                       3 - Image ID (low)
                       4 - Image ID (high), Flags
                       5 - X offset (low)
                       6 - X offset (high)
                       7 - Y offset (low)
                       8 - Y offset (high)
                       9 - Ignore direction (bool)
                       
                       - Flags -
                       0 - Image ID high byte
                       1 - Image ID high byte
                       2 - Image ID high byte
                       3 - Image ID high byte
                       4 - Image ID high byte
                       5 - Image ID high byte
                       6 - X flip
                       7 - Y flip
                        */
      if (current_obj->obj_type == 0) {
        object_addy->unk_image_wait_flag = 1;
      }
      image_wait = *(ushort *)&skill->field_0x1;
      image_wait_frames = -1;
      current_obj->drawing_flag = -1;
      if (image_wait != 0) {
        image_wait_frames = current_obj->image_wait_frames + (uint)image_wait * DAT_LIKELY_FPS;
      }
      current_obj->image_wait_frames = image_wait_frames;
      local_108 = 0;
      *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
      goto LAB_004125ae;
    case 0xe:
                    /* ----------------------------------
                       - EB - Pallet Animation*sway -
                       ----------------------------------
                       0 - Type
                       1 - Palette flash
                       2 - Red (SIGNED)
                       3 - Green (SIGNED)
                       4 - Blue (SIGNED)
                       5 - Alpha (UNSIGNED)
                       6 - Duration (low, UNSIGNED)
                       7 - Duration (high, UNSIGNED)
                       8 - Flags
                       9 - Pic Sway X
                       A - X shak
                       B - X Duration
                       C - Pic Sway Y
                       D - Y shak
                       E - Y Duration
                       
                       - Palette flash -
                       0 - unused
                       1 - Smooth fading
                       2 - Chika chika fading
                       3 - Random
                       
                       - Flags -
                       0 - ownside
                       1 - oppside
                       2 - BG
                       3 - System
                       
                       - Pic Sway -
                       0 - unused
                       1 - Shaky fading out
                       2 - Shaky fading in
                       3 - Shaky fix
                       4 - Random
                        */
      pallette_flash = skill->field_0x1;
      if (pallette_flash != 0) {
        if ((skill->field_0x8 & 1) != 0) {
                    /* OWNSIDE flag */
          flash_player_buffer = current_obj->player_file_buffer;
          *(uint *)&PLAYER_KGT_BUFFER[flash_player_buffer].start_of_0x2c = (uint)pallette_flash;
          *(int *)&PLAYER_KGT_BUFFER[flash_player_buffer].flash_red = (int)skill->02;
          *(int *)&PLAYER_KGT_BUFFER[flash_player_buffer].flash_green = (int)(char)skill->field_0x3;
          *(int *)&PLAYER_KGT_BUFFER[flash_player_buffer].flash_blue = (int)(char)skill->field_0x4;
          *(int *)&PLAYER_KGT_BUFFER[flash_player_buffer].flash_alpha = (int)(char)skill->field_0x5;
          *(int *)&PLAYER_KGT_BUFFER[flash_player_buffer].flash_var_a = current_obj->color_red;
          *(int *)&PLAYER_KGT_BUFFER[flash_player_buffer].flash_var_b = current_obj->color_green;
          *(int *)&PLAYER_KGT_BUFFER[flash_player_buffer].flash_var_c = current_obj->color_blue;
          uVar7 = *(undefined3 *)&current_obj->field_0x51;
          PLAYER_KGT_BUFFER[flash_player_buffer].flash_var_d = current_obj->color_alpha;
          *(undefined3 *)&PLAYER_KGT_BUFFER[flash_player_buffer].field_0xe038 = uVar7;
          flash_duration = *(ushort *)&skill->field_0x6;
          *(uint *)&PLAYER_KGT_BUFFER[flash_player_buffer].flash_duration_a = (uint)flash_duration;
          *(uint *)&PLAYER_KGT_BUFFER[flash_player_buffer].flash_duration_b = (uint)flash_duration;
        }
        if (((skill->field_0x8 & 2) != 0) &&
           (object_addy->poss_opponent_obj_ptr != (OBJ_STRUCT *)0x0)) {
                    /* OPPSIDE flag */
          flash_opponent_buffer = object_addy->poss_opponent_obj_ptr->player_file_buffer;
          *(uint *)&PLAYER_KGT_BUFFER[flash_opponent_buffer].start_of_0x2c = (uint)pallette_flash;
          *(int *)&PLAYER_KGT_BUFFER[flash_opponent_buffer].flash_red = (int)skill->02;
          *(int *)&PLAYER_KGT_BUFFER[flash_opponent_buffer].flash_green =
               (int)(char)skill->field_0x3;
          *(int *)&PLAYER_KGT_BUFFER[flash_opponent_buffer].flash_blue = (int)(char)skill->field_0x4
          ;
          *(int *)&PLAYER_KGT_BUFFER[flash_opponent_buffer].flash_alpha =
               (int)(char)skill->field_0x5;
          *(undefined4 *)&PLAYER_KGT_BUFFER[flash_opponent_buffer].flash_var_a = 0;
          *(undefined4 *)&PLAYER_KGT_BUFFER[flash_opponent_buffer].flash_var_b = 0;
          *(undefined4 *)&PLAYER_KGT_BUFFER[flash_opponent_buffer].flash_var_c = 0;
          *(undefined4 *)&PLAYER_KGT_BUFFER[flash_opponent_buffer].flash_var_d = 0;
          opp_flash_duration = *(ushort *)&skill->field_0x6;
          *(uint *)&PLAYER_KGT_BUFFER[flash_opponent_buffer].flash_duration_a =
               (uint)opp_flash_duration;
          *(uint *)&PLAYER_KGT_BUFFER[flash_opponent_buffer].flash_duration_b =
               (uint)opp_flash_duration;
        }
        if ((skill->field_0x8 & 4) != 0) {
                    /* BG flag */
          UNK_STAGE_FILES_00445740.pallette_flash = (int)pallette_flash;
          UNK_STAGE_FILES_00445740.script_read_var_a = 0;
          UNK_STAGE_FILES_00445740.script_read_var_b = 0;
          UNK_STAGE_FILES_00445740.pallette_flash_red = (int)skill->02;
          UNK_STAGE_FILES_00445740.script_read_var_c = 0;
          UNK_STAGE_FILES_00445740.pallette_flash_green = (int)(char)skill->field_0x3;
          UNK_STAGE_FILES_00445740.script_read_var_d = 0;
          UNK_STAGE_FILES_00445740.pallette_flash_blue = (int)(char)skill->field_0x4;
          UNK_STAGE_FILES_00445740.pallette_flash_alpha = (int)(char)skill->field_0x5;
          UNK_STAGE_FILES_00445740.pallette_flash_duration = (int)*(ushort *)&skill->field_0x6;
          UNK_STAGE_FILES_00445740.pallette_flash_duration_b =
               UNK_STAGE_FILES_00445740.pallette_flash_duration;
        }
        if ((skill->field_0x8 & 8) != 0) {
                    /* SYSTEM flag */
          _system_flash_red = (int)skill->02;
          _system_flash_blue = (int)(char)skill->field_0x4;
          _system_flash = (uint)pallette_flash;
          _system_flash_alpha = (int)(char)skill->field_0x5;
          _system_flash_green = (int)(char)skill->field_0x3;
          _system_flash_duration = (uint)*(ushort *)&skill->field_0x6;
          _DAT_004456e8 = 0;
          _DAT_004456ec = 0;
          _DAT_004456f0 = 0;
          _DAT_004456f4 = 0;
          _system_flash_2 = _system_flash_duration;
        }
      }
      if (skill->field_0x9 != 0) {
                    /* Pic sway X */
        UNK_STAGE_FILES_00445740.pic_sway_x = (int)(byte)skill->field_0x9;
        UNK_STAGE_FILES_00445740.x_shake = (int)(byte)skill->field_0xa;
        UNK_STAGE_FILES_00445740.field1046_0x266d = 0;
        UNK_STAGE_FILES_00445740.pic_sway_x_duration = (int)(byte)skill->field_0xb;
        UNK_STAGE_FILES_00445740.pic_sway_x_duration_2 =
             UNK_STAGE_FILES_00445740.pic_sway_x_duration;
      }
      if (skill->field_0xc == 0) goto switchD_00412610_advance_skillscript;
                    /* Pic sway Y */
      UNK_STAGE_FILES_00445740.pic_sway_y = (int)(byte)skill->field_0xc;
      UNK_STAGE_FILES_00445740.field1051_0x2681 = 0;
      UNK_STAGE_FILES_00445740.y_shake = (int)(byte)skill->field_0xd;
      UNK_STAGE_FILES_00445740.pic_sway_y_duration = (int)(byte)skill->field_0xe;
      UNK_STAGE_FILES_00445740.pic_sway_y_duration_2 = UNK_STAGE_FILES_00445740.pic_sway_y_duration;
      *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
      goto LAB_004125ae;
    case 0x10:
                    /* ----------------------------------
                       - GS - Special life gauge check -
                       ----------------------------------
                       0 - Type
                       1 - unk
                       2 - Skill ID (low, UNSIGNED)
                       3 - Skill ID (high, UNSIGNED)
                       4 - Command ID
                       5 - when Alot (if unset, when Little)
                       6 - from (SIGNED)
                       7 - add to advance */
      if ((skill->field_0x5 & 1) == 0) {
                    /* When little? */
        if ((PLAYER_KGT_BUFFER[current_obj->player_file_buffer].special_gauge_tokens <
             (int)(uint)(byte)skill->field_0x6) ||
           (GS_skill_idx = *(ushort *)&skill->02, GS_skill_idx == 0))
        goto switchD_00412610_advance_skillscript;
        current_obj->action_idx = (uint)GS_skill_idx;
        if (GS_skill_idx == 0) {
          special_stock_gauge_max =
               PLAYER_KGT_BUFFER[current_obj->player_file_buffer].field6392_0xdf55;
LAB_004135a7:
          special_stock_gauge_max = FUN_00410060(special_stock_gauge_max);
          current_obj = PTR_POSS_CURRENT_OBJ;
          if (special_stock_gauge_max != 0) {
            PTR_POSS_CURRENT_OBJ->action_idx = special_stock_gauge_max;
          }
        }
      }
      else {
                    /* When alot */
        if ((int)(uint)(byte)skill->field_0x6 <
            PLAYER_KGT_BUFFER[current_obj->player_file_buffer].special_gauge_tokens) {
          GS_player_buffer = current_obj->player_file_buffer;
          add_to_special =
               FUN_00414860(CONCAT31((int3)(skill->skill_step_type - 1 >> 8),skill->field_0x7));
          new_special_gauge =
               PLAYER_KGT_BUFFER[GS_player_buffer].special_gauge_tokens + add_to_special;
          PLAYER_KGT_BUFFER[GS_player_buffer].special_gauge_tokens = new_special_gauge;
          if (new_special_gauge < 0) {
            PLAYER_KGT_BUFFER[GS_player_buffer].special_gauge_tokens = 0;
          }
          current_obj = PTR_POSS_CURRENT_OBJ;
          if ((uint)PLAYER_KGT_BUFFER[GS_player_buffer].special_gauge_tokens <
              (uint)PLAYER_KGT_BUFFER[GS_player_buffer].special_stock_max)
          goto switchD_00412610_advance_skillscript;
                    /* Enforce special gauge max */
          PLAYER_KGT_BUFFER[GS_player_buffer].special_gauge_tokens =
               PLAYER_KGT_BUFFER[GS_player_buffer].special_stock_max;
          PLAYER_KGT_BUFFER[GS_player_buffer].special_gauge = 0;
          current_obj = PTR_POSS_CURRENT_OBJ;
          *(int *)&PTR_POSS_CURRENT_OBJ->actionscript_idx =
               *(int *)&PTR_POSS_CURRENT_OBJ->actionscript_idx + 1;
          goto LAB_004125ae;
        }
        uVar5 = *(ushort *)&skill->02;
        current_obj->action_idx = (uint)uVar5;
        if (uVar5 == 0) {
          special_stock_gauge_max =
               PLAYER_KGT_BUFFER[current_obj->player_file_buffer].field6392_0xdf55;
          goto LAB_004135a7;
        }
      }
      uVar10 = current_obj->action_idx;
      goto LAB_004135bf;
    case 0x11:
                    /* ----------------------------------
                       - GL - Life Gauge Check -
                       ----------------------------------
                       0 - Type
                       1 - unk
                       2 - Skill ID (low, UNSIGNED)
                       3 - Skill ID (high, UNSIGNED)
                       4 - Command ID
                       5 - when Alot (if unset, when Little)
                       6 - from (low, UNSIGNED)
                       7 - from (high, UNSIGNED) */
      if ((skill->field_0x5 & 1) == 0) {
        if ((object_addy->health < (int)(uint)*(ushort *)&skill->field_0x6) ||
           (*(short *)&skill->02 == 0)) goto switchD_00412610_advance_skillscript;
      }
      else if ((int)(uint)*(ushort *)&skill->field_0x6 < object_addy->health)
      goto switchD_00412610_advance_skillscript;
      pActionAlloc = (object_addy->kgt_core).p_actions_alloc;
      GL_skill_idx = *(ushort *)&skill->02;
      current_obj->action_idx = (uint)GL_skill_idx;
      *(uint *)&current_obj->actionscript_idx =
           ((ushort)pActionAlloc[GL_skill_idx].starting_step_idx - 1) + (uint)(byte)skill->field_0x4
      ;
      if ((current_obj->action_idx != 0) ||
         (special_stock_gauge_max = FUN_00410060(object_addy->field6392_0xdf55),
         current_obj = PTR_POSS_CURRENT_OBJ, special_stock_gauge_max == 0))
      goto switchD_00412610_advance_skillscript;
      pActionAlloc = (object_addy->kgt_core).p_actions_alloc;
      PTR_POSS_CURRENT_OBJ->action_idx = special_stock_gauge_max;
      uVar10 = (uint)(ushort)pActionAlloc[special_stock_gauge_max].starting_step_idx;
      *(uint *)&current_obj->actionscript_idx = uVar10 - 1;
      *(uint *)&current_obj->actionscript_idx = uVar10;
      goto LAB_004125ae;
    case 0x14:
                    /* ----------------------------------
                       - RP - Partner:script mod.
                       ----------------------------------
                       0 - Type
                       1 - Flags
                       2 - Hit junction ID (low...?, UNSIGNED)
                       3 - unk
                       4 - X (low, SIGNED)
                       5 - X (high, SIGNED)
                       6 - Y (low, SIGNED)
                       7 - Y (high, SIGNED)
                       
                       - Flags -
                       0 - In (if unset, depth is Forw)
                       1 - unk
                       2 - L.R reverse
                        */
      if ((current_obj->obj_type != 0) ||
         (opp_obj_ptr = object_addy->poss_opponent_obj_ptr, opp_obj_ptr == (OBJ_STRUCT *)0x0))
      goto switchD_00412610_advance_skillscript;
      RP_flags = skill->field_0x1;
      if ((RP_flags & 1) == 0) {
        uVar10 = *(uint *)&opp_obj_ptr->2_or_3;
        current_obj->param2_maybe_50_or_46 = (&INT_0041f130)[*(uint *)&current_obj->2_or_3 & 1] + -1
        ;
        special_stock_gauge_max = (&INT_0041f130)[uVar10 & 1] + 1;
      }
      else {
        uVar10 = *(uint *)&opp_obj_ptr->2_or_3;
        current_obj->param2_maybe_50_or_46 = (&INT_0041f130)[*(uint *)&current_obj->2_or_3 & 1] + 1;
        special_stock_gauge_max = (&INT_0041f130)[uVar10 & 1] + -1;
      }
      RP_player_direction = current_obj->pos_player_direction;
      opp_obj_ptr->param2_maybe_50_or_46 = special_stock_gauge_max;
      if ((RP_player_direction & 1) == 0) {
                    /* Move X value */
        opp_obj_ptr->param_3 = *(short *)&skill->field_0x4 * 0x10000 + current_obj->param_3;
        if ((RP_flags & 4) == 0) goto LAB_004130e8;
        opp_obj_ptr->pos_player_direction = 0;
      }
      else {
        opp_obj_ptr->param_3 = current_obj->param_3 + *(short *)&skill->field_0x4 * -0x10000;
        if ((RP_flags & 4) == 0) {
          opp_obj_ptr->pos_player_direction = 0;
        }
        else {
LAB_004130e8:
          opp_obj_ptr->pos_player_direction = 1;
        }
      }
                    /* Move Y pos */
      opp_obj_ptr->param_4 = *(short *)&skill->field_0x6 * 0x10000 + current_obj->param_4;
      memzero_mystery_arrays(current_obj);
      current_obj = PTR_POSS_CURRENT_OBJ;
      if (opp_obj_ptr->obj_type != 0) goto switchD_00412610_advance_skillscript;
      if ((byte)skill->02 != 0) {
                    /* Lands at start of hit_junction_info */
        opp_obj_ptr->hit_junction_idx =
             (uint)*(ushort *)
                    (opp_obj_ptr->player_file_buffer * 0xe03f + 0x4d8b2a + (uint)(byte)skill->02 * 4
                    );
      }
      current_obj = PTR_POSS_CURRENT_OBJ;
      pOVar12 = opp_obj_ptr->obj_ptr_b;
      *(undefined4 *)&opp_obj_ptr->time_method_number_in_frames = 0;
      object_addy->field6455_0xdfef = 0;
      opp_obj_ptr->obj_ptr_b = (OBJ_STRUCT *)((uint)pOVar12 & 0xfffffffa | 10);
      *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
      goto LAB_004125ae;
    case 0x15:
                    /* ----------------------------------
                       - GC - Gauge MOD.
                       ----------------------------------
                       0 - Type
                       1 - unk
                       2 - Life, self (low, SIGNED)
                       3 - Life, self (high, SIGNED)
                       4 - Special, self (low, SIGNED)
                       5 - Special, self (high, SIGNED)
                       6 - Life, part (low, SIGNED)
                       7 - Life, part (high, SIGNED)
                       8 - Special, part (low, SIGNED)
                       9 - Special, part (high, SIGNED) */
      GC_player_buffer = current_obj->player_file_buffer;
      GC_life_opp = *(short *)&skill->field_0x6;
      if (*(short *)&skill->02 != 0) {
        add_to_health(PLAYER_KGT_BUFFER + GC_player_buffer,(int)*(short *)&skill->02);
        current_obj = PTR_POSS_CURRENT_OBJ;
      }
      add_to_special_gauge(current_obj->player_file_buffer,(int)*(short *)&skill->field_0x4);
      current_obj = PTR_POSS_CURRENT_OBJ;
      if (PLAYER_KGT_BUFFER[GC_player_buffer].poss_opponent_obj_ptr == (OBJ_STRUCT *)0x0) {
        if (PLAYER_KGT_BUFFER[GC_player_buffer].poss_opponent_obj_ptr_2? == (OBJ_STRUCT *)0x0)
        goto switchD_00412610_advance_skillscript;
        special_stock_gauge_max =
             (PLAYER_KGT_BUFFER[GC_player_buffer].poss_opponent_obj_ptr_2?)->player_file_buffer;
      }
      else {
        special_stock_gauge_max =
             (PLAYER_KGT_BUFFER[GC_player_buffer].poss_opponent_obj_ptr)->player_file_buffer;
      }
      if (PLAYER_KGT_BUFFER + special_stock_gauge_max != (kgt_character_struct *)0x0) {
        if (GC_life_opp != 0) {
          add_to_health(PLAYER_KGT_BUFFER + special_stock_gauge_max,(int)GC_life_opp);
        }
        add_to_special_gauge
                  (*(undefined4 *)(PLAYER_KGT_BUFFER[special_stock_gauge_max].CPU + 0x156),
                   (int)*(short *)&skill->field_0x8);
        current_obj = PTR_POSS_CURRENT_OBJ;
      }
      goto switchD_00412610_advance_skillscript;
    case 0x16:
                    /* ----------------------------------
                       - DB - Cond. Branching
                       ----------------------------------
                       0 - Type
                       1 - If fail (otherwise, Formed)
                       2 - Skill ID (low, UNSIGNED)
                       3 - Skill ID (high, UNSIGNED)
                       4 - Command ID (UNSIGNED)
                       5 - unk
                       6 - unk
                       7 - Condition
                       
                       - Conditions -
                       0 - "its not"
                       1 - On the ground
                       2 - Standing
                       3 - Squating.
                       4 - Front surface.
                       5 - Rear surface.
                       6 - Upper Part Surface.
                       7 - Lower Part Surfae */
      is_if_failed = skill->field_0x1 & 1;
      if ((skill->field_0x1 & 2) != 0) goto switchD_00412de4_default;
      db_player_buffer = current_obj->player_file_buffer;
      DB_input = INPUT_BUFFER_A[db_player_buffer][INPUT_BUFFER_POS];
      switch(skill->field_0x7) {
      case 1:
        if (current_obj->param_4 < current_obj->compare_to_param_4) break;
        goto LAB_00412e5f;
      case 2:
        if (current_obj->compare_to_param_4 <= current_obj->param_4) {
          uVar10 = DB_input & 8;
          goto joined_r0x00412e5d;
        }
        break;
      case 3:
        if (current_obj->compare_to_param_4 <= current_obj->param_4) goto switchD_00412de4_caseD_7;
        break;
      case 4:
        if (((PLAYER_KGT_BUFFER[db_player_buffer].guard_button_flag & 8U) == 0) ||
           (current_obj->pos_player_direction == 0)) {
LAB_00412e4c:
          uVar10 = DB_input & 2;
          goto joined_r0x00412e56;
        }
        goto LAB_00412e2f;
      case 5:
        if (((PLAYER_KGT_BUFFER[db_player_buffer].guard_button_flag & 8U) != 0) &&
           (current_obj->pos_player_direction != 0)) goto LAB_00412e4c;
LAB_00412e2f:
        uVar10 = DB_input & 1;
joined_r0x00412e32:
        if (uVar10 == 0) break;
LAB_00412e5f:
        if (is_if_failed == 0) goto LAB_00412e79;
        goto switchD_00412610_advance_skillscript;
      case 6:
        uVar10 = DB_input & 4;
joined_r0x00412e56:
        if (uVar10 != 0) goto LAB_00412e5f;
        break;
      case 7:
switchD_00412de4_caseD_7:
        uVar10 = DB_input & 8;
        goto joined_r0x00412e32;
      case 8:
        uVar10 = DB_input & 0xf;
joined_r0x00412e5d:
        if (uVar10 == 0) goto LAB_00412e5f;
      }
switchD_00412de4_default:
      if (is_if_failed == 0) goto switchD_00412610_advance_skillscript;
LAB_00412e79:
      if (*(ushort *)&skill->02 == 0) goto switchD_00412610_advance_skillscript;
      uVar10 = (uint)*(ushort *)&skill->02;
      current_obj->action_idx = uVar10;
LAB_004135bf:
      special_stock_gauge_max =
           ((ushort)(object_addy->kgt_core).p_actions_alloc[uVar10].starting_step_idx - 1) +
           (uint)(byte)skill->field_0x4;
      *(int *)&current_obj->actionscript_idx = special_stock_gauge_max;
      *(int *)&current_obj->actionscript_idx = special_stock_gauge_max + 1;
      goto LAB_004125ae;
    case 0x17:
                    /* ----------------------------------
                       - R - Reaction
                       ----------------------------------
                       0 - Type
                       1 - Hit, Stand (low, UNSIGNED)
                       2 - Hit, Stand (high, UNSIGNED)
                       3 - Hit, Crouched (low, UNSIGNED)
                       4 - Hit, Crouched (high, UNSIGNED)
                       5 - Hit, Sky (low, UNSIGNED)
                       6 - Hit, Sky (high, UNSIGNED)
                       7 - Guard, Stand (low, UNSIGNED)
                       8 - Guard, Stand (high, UNSIGNED)
                       9 - Guard, Crouched (low, UNSIGNED)
                       A - Guard, Crouched (high, UNSIGNED)
                       B - Guard, Sky (low, UNSIGNED)
                       C - Guard, Sky (high, UNSIGNED) */
      current_obj->reaction_skillblock = skill;
      *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
      goto LAB_004125ae;
    case 0x18:
                    /* ----------------------------------
                       - FA - Attack
                       ----------------------------------
                       0 - Type
                       1 - X position (low, SIGNED)
                       2 - X position (high, SIGNED)
                       3 - Y position (low, SIGNED)
                       4 - Y position (high, SIGNED)
                       5 - Width (low, SIGNED)
                       6 - Width (high, SIGNED)
                       7 - Height (low, SIGNED)
                       8 - Height (high, SIGNED)
                       9 - M number (UNSIGNED)
                       A - Flags
                       B - unk
                       C - Power (UNSIGNED)
                       
                       - Flags -
                       0 - Cancel
                       1 - Cont. Hit
                       2 - Shav
                       3 - While Guard
                       4 - No Decision
                       5 - No Sky Decision
                       6 - Guard Fail
                       7 - While Receiving */
      FA_width = *(short *)&skill->field_0x5;
      FA_m_number = current_obj->hitbox_attack_array + (byte)skill->field_0x9;
      *FA_m_number = (int)skill;
      if ((FA_width == 0) || (*(short *)&skill->field_0x7 == 0)) goto LAB_00412d83;
      if (current_obj->obj_type != 0) goto switchD_00412610_advance_skillscript;
      FA_flags = skill->field_0xa;
      if ((FA_flags & 1) == 0) {
        *(undefined4 *)&object_addy->currect_action_cancellable_flag = 0;
      }
      else {
        *(undefined4 *)&object_addy->currect_action_cancellable_flag = 1;
      }
      if ((FA_flags & 2) == 0) goto switchD_00412610_advance_skillscript;
      current_obj->obj_ptr_b = (OBJ_STRUCT *)((uint)current_obj->obj_ptr_b & 0xffffffef);
      *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
      goto LAB_004125ae;
    case 0x19:
                    /* ----------------------------------
                       - FD - Defense
                       ----------------------------------
                       0 - Type
                       1 - X position (low, SIGNED)
                       2 - X position (high, SIGNED)
                       3 - Y position (low, SIGNED)
                       4 - Y position (high, SIGNED)
                       5 - Width (low, SIGNED)
                       6 - Width (high, SIGNED)
                       7 - Height (low, SIGNED)
                       8 - Height (high, SIGNED)
                       9 - M number (UNSIGNED)
                       A - Flags
                       B - Damage ratio (UNSIGNED)
                       
                       - Flags -
                       0 - Striking
                       1 - Doing
                       2 - Throwing */
      sVar2 = *(short *)&skill->field_0x5;
      FA_m_number = current_obj->hitbox_guard_array + (byte)skill->field_0x9;
      *FA_m_number = (int)skill;
      if ((sVar2 != 0) && (*(short *)&skill->field_0x7 != 0))
      goto switchD_00412610_advance_skillscript;
LAB_00412d83:
      *FA_m_number = 0;
      *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
      goto LAB_004125ae;
    case 0x1a:
                    /* ----------------------------------
                       - PS - Player: Stop
                       ----------------------------------
                       0 - Type
                       1 - Your Down Time (UNSIGNED)
                       2 - Part Down Time (UNSIGNED) */
      if ((current_obj->obj_type == 0) &&
         (player_down_time = skill->field_0x1, player_down_time != 0)) {
        *(uint *)&current_obj->time_method_number_in_frames =
             *(int *)&current_obj->time_method_number_in_frames + (uint)player_down_time;
        PS_player_buffer = current_obj->player_file_buffer;
        *(int *)&PLAYER_KGT_BUFFER[PS_player_buffer].input_storage =
             INPUT_BUFFER_A[PS_player_buffer][INPUT_BUFFER_POS];
        PLAYER_KGT_BUFFER[PS_player_buffer].field6465_0xdfff = 1;
        PS_obj = &OBJ_ARRAY[0].time_method_number_in_frames;
        ps_i = 0x400;
        do {
          if (((ADJ(PS_obj).jmp_idx == 4) && (ADJ(PS_obj)->player_file_buffer == PS_player_buffer))
             && ((ADJ(PS_obj)->unk_bitmask & 0x20000000) != 0)) {
            *(uint *)PS_obj = *(int *)PS_obj + (uint)player_down_time;
          }
          PS_obj = PS_obj + 0x17e;
          ps_i = ps_i + -1;
        } while (ps_i != 0);
      }
      PS_opponent_down_time = skill->02;
      if (PS_opponent_down_time == 0) goto switchD_00412610_advance_skillscript;
      ps_i2 = 0;
      PS_players = &PLAYER_KGT_BUFFER[0].CPU;
      do {
        if ((ps_i2 != current_obj->player_file_buffer) &&
           (ADJ(PS_players)->script_reading_01_field5 != 0)) {
          PS_player_cpu = ADJ(PS_players)->CPU;
          ps_i3 = 0x400;
          *(uint *)(PS_player_cpu + 0x40) =
               *(int *)(PS_player_cpu + 0x40) + (uint)PS_opponent_down_time;
          *(int *)&ADJ(PS_players)->input_storage =
               INPUT_BUFFER_A[*(int *)(PS_player_cpu + 0x156)][INPUT_BUFFER_POS];
          ADJ(PS_players)->field6465_0xdfff = 1;
          other_player_poss_relating = (int *)&OBJ_ARRAY[0].time_method_number_in_frames;
          do {
            if (((other_player_poss_relating[-0x10] == 4) &&
                (*(int *)((int)other_player_poss_relating + 0x116) ==
                 *(int *)(ADJ(PS_players)->CPU + 0x156))) &&
               ((other_player_poss_relating[-6] & 0x20000000U) != 0)) {
              *other_player_poss_relating =
                   *other_player_poss_relating + (uint)PS_opponent_down_time;
            }
            other_player_poss_relating = (int *)((int)other_player_poss_relating + 0x17e);
            ps_i3 = ps_i3 + -1;
          } while (ps_i3 != 0);
        }
        PS_players = (kgt_character_struct_ptr_57077_int)((int)PS_players + 0xe03f);
        ps_i2 = ps_i2 + 1;
      } while ((int)PS_players < 0x54fe6d);
      *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
      goto LAB_004125ae;
    case 0x1e:
                    /* ----------------------------------
                       - C - Cancel Cond. -
                       ----------------------------------
                       0 - Type
                       1 - Cancel, flags
                       2 - mpty (UNSIGNED)
                       3 - Skill ID (low, UNSIGNED)
                       4 - Skill ID (high, UNSIGNED)
                       5 - ween (UNSIGNED)
                       
                       - Cancels -
                       0 - Fail
                       1 - Hit
                       2 - UnCond
                       
                       - Flags -
                       0 - CANCEL_MASK 
                       1 - CANCEL_MASK
                       2 - CANCEL_MASK
                       3 - Skill */
      cancel_flags = skill->field_0x1;
      cancel_empty = skill->02;
      cancel_skill_idx = skill->field_0x3;
      uVar4 = *(undefined2 *)&skill->field_0x4;
      object_addy->start_of_0x6 = skill->skill_step_type;
      object_addy->field_0xdf92 = cancel_flags;
      object_addy->field_0xdf93 = cancel_empty;
      object_addy->field_0xdf94 = cancel_skill_idx;
      *(undefined2 *)&object_addy->field_0xdf95 = uVar4;
      *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
      goto LAB_004125ae;
    case 0x1f:
                    /* ----------------------------------
                       - V - Variable -
                       ----------------------------------
                       0 - Type
                       1 - Branch skill ID (low, UNSIGNED)
                       2 - Branch skill ID (high, UNSIGNED)
                       3 - Branch Command ID (UNSIGNED)
                       4 - Var. LHS
                       5 - Operation, branch condition, operation flags
                       6 - Var. RHS 
                       7 - Value (low, SIGNED)
                       8 - Value (high, SIGNED)
                       9 - Compare (low, SIGNED)
                       A - Compare (high, SIGNED)
                       
                       - Variables -
                       0x - Variable index (A - P)
                       x0 - Source (0 is Task, 4 is Character, 8 is System. Only players may access
                       character variables.)
                       
                       - Operations -
                       0 - Nothing
                       1 - Set
                       2 - Add
                       
                       - Branch conditions -
                       0 - No Cond branch
                       1 - It's the same
                       2 - It's Above
                       3 - It's Below
                       
                       - Operation flags
                       0 - OPERATION_MASK
                       1 - OPERATION_MASK
                       2 - BRANCH_CONDITION_MASK
                       3 - BRANCH_CONDITION_MASK
                       4 - unk
                       5 - unk
                       6 - unk
                       7 - Use Var */
      var_LHS_long = skill->field_0x4;
      var_lhs = var_LHS_long >> 6;
      if (var_lhs == 0) {
        char_i = (short *)((int)current_obj->hitbox_guard_array + (var_LHS_long & 0x3f) * 2 + 0x58);
      }
      else if (var_lhs == 1) {
        char_i = (short *)((int)object_addy->object_mNumbers + (var_LHS_long & 0x3f) * 2 + -0x28);
      }
      else if (var_lhs == 2) {
        char_i = SYSTEM_VARIABLES + (var_LHS_long & 0x3f);
      }
      var_flags = skill->field_0x5;
      if ((var_flags & 0x80) == 0) {
        local_11c = (uint)*(ushort *)&skill->field_0x7;
        goto switchD_0041380c_default;
      }
      life_recover_number = skill->field_0x6;
      switch(life_recover_number >> 6) {
      case 0:
        local_11c = (uint)*(ushort *)
                           ((int)current_obj->hitbox_guard_array +
                           (life_recover_number & 0x3f) * 2 + 0x58);
        break;
      case 1:
        local_11c = (uint)*(ushort *)
                           ((int)object_addy->object_mNumbers +
                           (life_recover_number & 0x3f) * 2 + -0x28);
        break;
      case 2:
        local_11c = (uint)(ushort)SYSTEM_VARIABLES[life_recover_number & 0x3f];
        break;
      case 3:
        switch(life_recover_number & 0x3f) {
        case 0:
          special_stock_gauge_max = current_obj->param_3;
          goto LAB_00413865;
        case 1:
          special_stock_gauge_max = current_obj->param_4;
          goto LAB_00413865;
        case 2:
          local_11c = unk_y_position;
          break;
        case 3:
          local_11c = unk_x_position;
          break;
        case 4:
          special_stock_gauge_max = current_obj->parent_obj->param_3;
          goto LAB_00413865;
        case 5:
          special_stock_gauge_max = current_obj->parent_obj->param_4;
LAB_00413865:
          local_11c = (int)((special_stock_gauge_max >> 0x1f & 0xffffU) + special_stock_gauge_max)
                      >> 0x10;
          break;
        case 6:
          local_11c = GAME_STATE.gameTimerInFrames / 100;
          break;
        case 7:
          local_11c = GAME_STATE.poss_current_round_count;
        }
      }
switchD_0041380c_default:
      if ((var_flags & 3) == 1) {
        *char_i = (short)local_11c;
      }
      else if ((var_flags & 3) == 2) {
        special_stock_gauge_max = (int)*char_i + (int)(short)local_11c;
        if (special_stock_gauge_max < -30000) {
          *char_i = -30000;
        }
        else {
          if (30000 < special_stock_gauge_max) {
            special_stock_gauge_max = 30000;
          }
          *char_i = (short)special_stock_gauge_max;
        }
      }
      life_recover_number = var_flags >> 2 & 3;
      if (life_recover_number == 1) {
        if (*char_i != *(short *)&skill->field_0x9) goto switchD_00412610_advance_skillscript;
      }
      else if (life_recover_number == 2) {
        if (*char_i <= *(short *)&skill->field_0x9) goto switchD_00412610_advance_skillscript;
      }
      else if ((life_recover_number != 3) || (*(short *)&skill->field_0x9 <= *char_i))
      goto switchD_00412610_advance_skillscript;
      uVar5 = *(ushort *)&skill->field_0x1;
      if (uVar5 == 0) goto switchD_00412610_advance_skillscript;
      pActionAlloc = (object_addy->kgt_core).p_actions_alloc;
      current_obj->action_idx = (uint)uVar5;
      special_stock_gauge_max =
           ((ushort)pActionAlloc[uVar5].starting_step_idx - 1) + (uint)(byte)skill->field_0x3;
      *(int *)&current_obj->actionscript_idx = special_stock_gauge_max;
      *(int *)&current_obj->actionscript_idx = special_stock_gauge_max + 1;
      goto LAB_004125ae;
    case 0x20:
                    /* ----------------------------------
                       - R - Random -
                       ----------------------------------
                       0 - Type
                       1 - Var (low, UNSIGNED)
                       2 - Var (high, UNSIGNED)
                       3 - When its above (low, UNSIGNED)
                       4 - When its above (high, UNSIGNED)
                       5 - unk
                       6 - Skill ID (low, UNSIGNED)
                       7 - Skill ID (high, UNSIGNED)
                       8 - Command ID
                        */
      rand = _rand();
      current_obj = PTR_POSS_CURRENT_OBJ;
      if ((rand % (int)(*(ushort *)&skill->field_0x1 + 1) <= (int)(uint)*(ushort *)&skill->field_0x3
          ) || (uVar5 = *(ushort *)&skill->field_0x6, uVar5 == 0))
      goto switchD_00412610_advance_skillscript;
      pActionAlloc = (object_addy->kgt_core).p_actions_alloc;
      PTR_POSS_CURRENT_OBJ->action_idx = (uint)uVar5;
      random_skillcommand =
           ((ushort)pActionAlloc[uVar5].starting_step_idx - 1) + (uint)(byte)skill->field_0x8;
      *(int *)&current_obj->actionscript_idx = random_skillcommand;
      *(int *)&current_obj->actionscript_idx = random_skillcommand + 1;
      goto LAB_004125ae;
    case 0x23:
                    /* ----------------------------------
                       - COLOR - Color -
                       ----------------------------------
                       0 - Type
                       1 - Blend type
                       2 - Red (SIGNED)
                       3 - Green (SIGNED)
                       4 - Blue (SIGNED)
                       5 - Alpha (UNSIGNED)
                       
                       - Blend types -
                       0 - 0% transparent
                       1 - 50% transparent
                       2 - Additive
                       3 - Subtractive
                       4 - Transparent (with custom alpha this time) */
      cVar8 = skill->02;
      cVar1 = skill->field_0x3;
      *(uint *)&current_obj->color_blendtype = (uint)(byte)skill->field_0x1;
      current_obj->color_red = (int)cVar8;
      cVar8 = skill->field_0x4;
      current_obj->color_green = (int)cVar1;
      current_obj->color_blue = (int)cVar8;
      if (*(int *)&current_obj->color_blendtype == 4) {
        *(int *)&current_obj->color_alpha = (int)(char)skill->field_0x5;
        *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
      }
      else {
        *(undefined4 *)&current_obj->color_alpha = 0;
        *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
      }
      goto LAB_004125ae;
    case 0x24:
                    /* ----------------------------------
                       - COM - Command input -
                       ----------------------------------
                       0 - Type
                       1 - Skill ID (low, UNSIGNED)
                       2 - Skill ID (low, UNSIGNED)
                       3 - Command ID (UNSIGNED)
                       4 - Command Time (UNSIGNED)
                       5 - Input 1 Data (low)
                       6 - Input 1 Data (high)
                       7 - Input 2 Data (low)
                       8 - Input 2 Data (high)
                       9 - Input 3 Data (low)
                       A - Input 3 Data (high)
                       B - Input 4 Data (low)
                       C - Input 4 Data (high)
                       D - Input 5 Data (low)
                       E - Input 5 Data (high)
                       
                       - Motions -
                       0 - Free
                       1 - 5
                       2 - 6
                       3 - 3
                       4 - 2
                       5 - 1
                       6 - 4
                       7 - 7
                       8 - 8
                       9 - 9
                       A - 1 | 4 | 7
                       B - 7 | 8 | 9
                       C - 3 | 6 | 9
                       D - 1 | 2 | 3
                       
                       - Types -
                       0 - Standard
                       1 - Repeat (?)
                       2 - Hold (?)
                       3 - 360 (?)
                       
                       - COMMAND DATA -
                       0 - MOTION_MASK
                       1 - MOTION_MASK
                       2 - MOTION_MASK
                       3 - MOTION_MASK
                       4 - A button
                       5 - B button
                       6 - C button
                       7 - D button
                       8 - E button
                       9 - F button
                       A - unk
                       B - unk
                       C - Continue flag (if unset, this is the end of the input step)
                       D - Editable flag (if unset, this input step is greyed out in editor...)
                       E - TYPE_MASK (not used by skills)
                       F - TYPE_MASK (not used by skills) */
      special_stock_gauge_max = process_COM_skillblock(skill);
      current_obj = PTR_POSS_CURRENT_OBJ;
      if (special_stock_gauge_max == 0) goto switchD_00412610_advance_skillscript;
      COM_skill_idx = *(ushort *)&skill->field_0x1;
      PTR_POSS_CURRENT_OBJ->action_idx = (uint)COM_skill_idx;
      COM_new_skillscript_idx =
           ((ushort)(object_addy->kgt_core).p_actions_alloc[COM_skill_idx].starting_step_idx - 1) +
           (uint)(byte)skill->field_0x3;
      *(int *)&current_obj->actionscript_idx = COM_new_skillscript_idx;
      *(int *)&current_obj->actionscript_idx = COM_new_skillscript_idx + 1;
      goto LAB_004125ae;
    case 0x25:
                    /* ----------------------------------
                       - AI - AfterI -
                       ----------------------------------
                       0 - Type
                       1 - unk
                       2 - unk
                       3 - Quantity (UNSIGNED)
                       4 - Interval (UNSIGNED)
                       5 - Blend type
                       6 - Fade type
                       7 - Red (SIGNED)
                       8 - Green (SIGNED)
                       9 - Blue (SIGNED)
                       A - Alpha (SIGNED)
                       
                       - Fade type -
                       0 - Unused
                       1 - Fixing
                       2 - Smooth fadng
                       3 - Chika Chika fading
                       4 - Random */
      if (current_obj->0x650_index == 0) {
        0x650_idx = 0;
        other_player_poss_relating = &DAT_00447f80;
        goto AI_0x650_is_0;
      }
      0x650_idx = (byte)current_obj->0x650_index - 1;
      if ((skill->field_0x3 != '\0') && (skill->field_0x4 != '\0')) goto AI_quantity_interval_not_0;
      current_obj->0x650_index = 0;
      special_stock_gauge_max = *(int *)&current_obj->actionscript_idx;
      (&DAT_00447f80)[0x650_idx * 0x194] = 0;
      *(int *)&current_obj->actionscript_idx = special_stock_gauge_max + 1;
      goto LAB_004125ae;
    }
  }
  _sprintf(local_100,s_ScriptMainLoopError_%d_%d_-_nd:%_0041f230,current_obj->player_file_buffer,
           current_obj->obj_type,current_skill_idx,
           *(int *)&current_obj->actionscript_idx -
           (uint)(ushort)(object_addy->kgt_core).p_actions_alloc[current_skill_idx + 1].
                         starting_step_idx);
  SET_DEBUG_INFO(local_100,0x8080ff);
  goto switchD_0041270c_default;
  while( true ) {
    other_player_poss_relating = other_player_poss_relating + 0x194;
    0x650_idx = 0x650_idx + 1;
                    /* AI 0x650_index is 0 */
    if (0x46f6bf < (int)other_player_poss_relating) break;
AI_0x650_is_0:
    if (*other_player_poss_relating == 0) {
      (&DAT_00447f80)[0x650_idx * 0x194] = 1;
      current_obj->0x650_index = (char)0x650_idx + '\x01';
      break;
    }
  }
AI_quantity_interval_not_0:
                    /* AI Quantity and interval isn't 0 */
  if (0x650_idx != 100) {
    (&INT_00447f84)[0x650_idx * 0x194] = 0;
    (&INT_00447f88)[0x650_idx * 0x194] = (int)skill;
    (&INT_00447f8c)[0x650_idx * 0x194] = 0;
    other_player_poss_relating = &INT_00447f90 + 0x650_idx * 0x194;
    for (special_stock_gauge_max = 400; special_stock_gauge_max != 0;
        special_stock_gauge_max = special_stock_gauge_max + -1) {
      *other_player_poss_relating = 0;
      other_player_poss_relating = other_player_poss_relating + 1;
    }
    *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
    goto LAB_004125ae;
  }
  SET_DEBUG_INFO(s_HAN_KATAKANA#_0041f274,&DAT_004444ff);
  current_obj = PTR_POSS_CURRENT_OBJ;
  goto switchD_00412610_advance_skillscript;
  while( true ) {
    special_stock_gauge_max = special_stock_gauge_max + 1;
    pOVar12 = pOVar12 + 1;
    if (0x3ff < special_stock_gauge_max) break;
OBJECT_BLOCK_LOOP:
    if (pOVar12 == object_addy->object_mNumbers[m_val]) {
      uVar5 = *(ushort *)&skill->field_0x5;
      if (uVar5 != 0) {
        pActionAlloc = (object_addy->kgt_core).p_actions_alloc;
        current_obj->action_idx = (uint)uVar5;
        special_stock_gauge_max =
             ((ushort)pActionAlloc[uVar5].starting_step_idx - 1) + (uint)(byte)skill->field_0x7;
        *(int *)&current_obj->actionscript_idx = special_stock_gauge_max;
        *(int *)&current_obj->actionscript_idx = special_stock_gauge_max + 1;
        goto LAB_004125ae;
      }
      pOVar12->jmp_idx = reset_index;
      object_addy->object_mNumbers[m_val] = (OBJ_STRUCT *)0x0;
      break;
    }
  }
LAB_00412b0a:
  if (*(ushort *)&skill->02 != 0) {
    curr_obj_type = current_obj->obj_type;
    life_recover_number = skill->field_0x1;
    bVar11 = life_recover_number & 0x40;
    if (curr_obj_type == main_kgt_file) {
      if (((object_addy->kgt_core).p_actions_alloc[*(ushort *)&skill->02].field_0x23 & 9) != 0) {
        bVar11 = 0;
        goto LAB_00412b9c;
      }
LAB_00412b66:
      bVar11 = 1;
LAB_00412b6e:
      special_stock_gauge_max = (int)*(short *)&skill->field_0x8 << 0x10;
      player_file_buff_idx = (int)*(short *)&skill->field_0xa << 0x10;
    }
    else {
      if (curr_obj_type == demo_file) goto LAB_00412b66;
      if (curr_obj_type != stage_file) {
        if ((life_recover_number & 0x40) == 0) goto LAB_00412b9c;
        goto LAB_00412b6e;
      }
      bVar11 = 0;
LAB_00412b9c:
      if ((current_obj->pos_player_direction & 1) == 0) {
        special_stock_gauge_max = *(short *)&skill->field_0x8 * 0x10000 + current_obj->param_3;
        player_file_buff_idx = *(short *)&skill->field_0xa * 0x10000 + current_obj->param_4;
      }
      else {
        special_stock_gauge_max = current_obj->param_3 + *(short *)&skill->field_0x8 * -0x10000;
        player_file_buff_idx = *(short *)&skill->field_0xa * 0x10000 + current_obj->param_4;
      }
    }
    uVar10 = current_obj->param2_maybe_50_or_46;
    if ((life_recover_number & 3) == 0) {
      uVar10 = uVar10 - 1;
      if ((int)uVar10 < 10) {
        uVar10 = 10;
      }
    }
    else if ((life_recover_number & 3) == 1) {
      uVar10 = uVar10 + 1;
      if (0x7f < (int)uVar10) {
        uVar10 = 0x7f;
      }
    }
    else if ((life_recover_number & 3) == 2) {
      uVar10 = (uint)(byte)skill->field_0xd;
    }
    pOVar12 = FIND_EMPTY_OBJ(current_obj->jmp_idx,uVar10,special_stock_gauge_max,
                             player_file_buff_idx);
    current_obj = PTR_POSS_CURRENT_OBJ;
    pOVar12->obj_type = 1;
    pOVar12->player_file_buffer = current_obj->player_file_buffer;
    switch(current_obj->obj_type) {
    case 0:
    case 1:
    case player_file:
      pOVar12->obj_type = 1;
      break;
    case main_kgt_file:
      pOVar12->obj_type = main_kgt_file;
      break;
    case demo_file:
      pOVar12->obj_type = demo_file;
      break;
    case stage_file:
      pOVar12->obj_type = stage_file;
    }
    uVar7 = *(undefined3 *)&current_obj->field_0x15;
    special_stock_gauge_max = current_obj->pos_player_direction;
    pOVar12->2_or_3 = current_obj->2_or_3;
    *(undefined3 *)&pOVar12->field_0x15 = uVar7;
    uVar5 = *(ushort *)&skill->02;
    pOVar12->pos_player_direction = special_stock_gauge_max;
    pOVar12->action_idx = (uint)uVar5;
    *(uint *)&pOVar12->actionscript_idx =
         (uint)(ushort)(object_addy->kgt_core).p_actions_alloc[uVar5].starting_step_idx +
         (uint)(byte)skill->field_0x4;
    if (bVar11 == 0) {
      pOVar12->unk_bitmask = pOVar12->unk_bitmask | 0x40000000;
    }
    if ((int)current_obj->obj_type < 2) {
      life_recover_number = skill->field_0x1;
      if ((life_recover_number & 4) == 0) {
        object_addy->object_mNumbers[(byte)skill->field_0xc] = pOVar12;
      }
      if ((life_recover_number & 8) != 0) {
        pOVar12->unk_bitmask = pOVar12->unk_bitmask | 0x80000000;
      }
    }
    if ((skill->field_0x1 & 0x20) != 0) {
      *(undefined2 *)&pOVar12->field_0x12f = *(undefined2 *)&skill->field_0xa;
      pOVar12->unk_bitmask = pOVar12->unk_bitmask | 0x20000000;
      *(undefined2 *)&pOVar12->field_0x12d = *(undefined2 *)&skill->field_0x8;
      *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
      goto LAB_004125ae;
    }
  }
switchD_00412610_advance_skillscript:
  *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
LAB_004125ae:
  if (local_108 == 0) {
    return;
  }
  goto Pre_Script_reading_switch_statement;
switchD_00412610_compute_momentum:
                    /* ----------------------------------
                       - M - Move -
                       ----------------------------------
                       0 - Type
                       1 - X gravity (high, SIGNED)
                       2 - X gravity (low, SIGNED)
                       3 - X momentum (high, SIGNED)
                       4 - X momentum (low, SIGNED)
                       5 - Y momentum (high, SIGNED)
                       6 - Y momentum (low, SIGNED)
                       7 - Y gravity (high, SIGNED)
                       8 - Y gravity (low, SIGNED)
                       9 - Flags
                       
                       - Flags -
                       0 - Add (if unset, set values. If set, add values.)
                       1 - X momentum stop flag (what does this do...?) 
                       2 - Y momentum stop flag (ditto) 
                       3 - X gravity stop flag (ditto) 
                       4 - Y gravity stop flag (ditto) 
                       
                       Double check the flag values for movement skill blocks. */
  player_ignore_flag_flag = 1;
  if (current_obj->pos_player_direction != 0) {
                    /* Possibly direction player is facing */
    player_ignore_flag_flag = -1;
  }
  mvmt_flags = skill->field_0x9;
  missing_x_flags_flag = (mvmt_flags & 1) == 0;
  player_x_momentum = *(short *)&skill->field_0x3 * player_momentum_scalar * player_ignore_flag_flag
  ;
  if ((mvmt_flags & 2) == 0) {
                    /* Does not have Y momentum stop flag or X gravity stop flag */
    if (missing_x_flags_flag) {
      current_obj->x_momentum = player_x_momentum;
    }
    else {
      current_obj->x_momentum = current_obj->x_momentum + player_x_momentum;
    }
  }
  player_y_momentum = *(short *)&skill->field_0x5 * player_momentum_scalar;
  if ((mvmt_flags & 4) == 0) {
                    /* Y gravity stop flag */
    if (missing_x_flags_flag) {
      current_obj->y_momentum = player_y_momentum;
    }
    else {
      current_obj->y_momentum = current_obj->y_momentum + player_y_momentum;
    }
  }
  special_stock_gauge_max = *(short *)&skill->field_0x1 * gravity_scalar * player_ignore_flag_flag;
  if ((mvmt_flags & 8) == 0) {
    if (missing_x_flags_flag) {
      current_obj->x_gravity = special_stock_gauge_max;
    }
    else {
      current_obj->x_gravity = current_obj->x_gravity + special_stock_gauge_max;
    }
  }
  special_stock_gauge_max = *(short *)&skill->field_0x7 * gravity_scalar;
  if ((mvmt_flags & 0x10) == 0) {
    if (missing_x_flags_flag) {
      current_obj->y_gravity = special_stock_gauge_max;
      *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
    }
    else {
      current_obj->y_gravity = current_obj->y_gravity + special_stock_gauge_max;
      *(int *)&current_obj->actionscript_idx = *(int *)&current_obj->actionscript_idx + 1;
    }
    goto LAB_004125ae;
  }
  goto switchD_00412610_advance_skillscript;
}

