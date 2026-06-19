
/* WARNING: Unable to use type for symbol cancel_empty */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void script_reading_logic(void)

{
  char cVar1;
  short sVar2;
  short sVar3;
  ushort uVar4;
  kgtSkill *pkVar5;
  undefined3 uVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  uint uVar9;
  int time_rand;
  int *iColorIntOtherPlayer;
  uint uVar10;
  int stage_unk_var_b;
  int image_wait_frames;
  int player_x_momentum;
  int player_y_momentum;
  int add_to_special;
  OBJ_STRUCT_ptr_64_undefined1 PS_obj;
  int rand;
  byte bVar11;
  byte bisIfFailed;
  int 0x650_idx;
  int char_idx;
  int 0650_size_offset;
  kgtEngineObject *pkVar12;
  int new_special_gauge;
  kgtPallette kVar13;
  int i20;
  int player_ignore_flag_flag;
  int iRpUnkParam2Val;
  kgt_character_struct *kgtTargetStructure;
  int ps_i;
  kgtEngineObject *pkgtoCurrentEngineObject;
  kgtEngineObject **ppkVar14;
  kgtSkill *skill;
  kgt_character_struct_ptr_57077_int PS_players;
  bool bIsStory;
  bool missing_x_flags_flag;
  uint local_11c;
  int ps_i3;
  int ps_i2;
  short *char_i;
  int local_108;
  void *local_104;
  char local_100 [256];
  int iPlayerBuffer_2;
  int iPlayerBuffer_3;
  int temp_5f04860c28;
  uint game_round;
  int stage_unk_poss_action_idx;
  int unk_actionscript_final_0x10;
  int mystery_val_sub_bool;
  int stage_unk_poss_action;
  kgtEngineObject *piVar16;
  int itemp_specialGauge;
  int itemp_SpecialGaugeTokens;
  kgtStoryEntryCpu *puVar1;
  int iColorInt;
  bool match_found;
  int iOpponentDownTime;
  int initial_y_val;
  kgtSkill *hitbox;
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
  kgtEngineObject *opp_obj_ptr;
  byte iRpFlags;
  int iRpPlayerLookingRight;
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
  undefined1 cancel_empty;
  byte var_LHS_long;
  byte var_lhs;
  byte var_flags;
  ushort COM_skill_idx;
  int COM_new_skillscript_idx;
  char bCarryOver;
  byte cLifeRecovery;
  undefined1 cancel_flags;
  undefined1 cancel_skill_idx;
  kgtEngineObjectTypes curr_obj_type;
  GAME_MODES game_mode;
  int iCurrentStoryStep;
  int iPlayerIdx;
  kgtSkillHeader *pSkillsAlloc;
  
  pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
  kgtTargetStructure = local_104;
  switch(gpkgtCurrentEngineObject->iObjectType) {
  case PLAYER_ENGINE_OBJECT:
  case STORY?_ENGINE_OBJECT:
  case CHARACTER_ENGINE_OBJECT:
    kgtTargetStructure = gkgtLoadedCharacter + gpkgtCurrentEngineObject->iPlayerIdx;
    break;
  case SYSTEM_ENGINE_OBJECT:
                    /* DON'T FORGET TO CHANGE THIS BACK TO PROPER VARIABLE TYPE */
    kgtTargetStructure = (kgt_character_struct *)&gkgtKgtSystem;
    break;
  case DEMO_ENGINE_OBJECT:
    kgtTargetStructure = (kgt_character_struct *)&gkgtLoadedDemo;
    break;
  case STAGE_ENGINE_OBJECT:
    kgtTargetStructure = (kgt_character_struct *)&gkgtLoadedStage;
  }
  if (gpkgtCurrentEngineObject->iProcessStep == 0) {
    gpkgtCurrentEngineObject->iProcessStep = 1;
    game_mode = gkgtGameState.kgtGameMode;
    switch(pkgtoCurrentEngineObject->iObjectType) {
    case PLAYER_ENGINE_OBJECT:
      bIsStory = gkgtGameState.kgtGameMode == 1P_story;
      pkgtoCurrentEngineObject->iParam2 =
           (&INT_0041f130)[*(uint *)&pkgtoCurrentEngineObject->2_or_3 & 1];
      if (bIsStory) {
        iCurrentStoryStep = giCurrentStoryStep[giStoryModePlayerIdx_2];
        iPlayerIdx = pkgtoCurrentEngineObject->iPlayerIdx;
        if (iPlayerIdx == 0) {
          bCarryOver = gkgtLoadedCharacter[0].kgtStoryEntries[iCurrentStoryStep].bFirstLifeCarryO ver
          ;
          if (gkgtGameState.iCurrentRound == 1) {
            if (bCarryOver == '\0') {
                    /* Probably_health assigned starting_health? */
              kgtTargetStructure->iHealth = *(int *)&kgtTargetStructure->shLifeGuageMax;
            }
          }
          else if (bCarryOver == '\0') {
            kgtTargetStructure->iHealth = *(int *)&kgtTargetStructure->shLifeGuageMax;
          }
          else {
            cLifeRecovery = gkgtLoadedCharacter[0].kgtStoryEntries[iCurrentStoryStep].cLifeRecove ry;
            if (cLifeRecovery == 100) {
              kgtTargetStructure->iHealth = *(int *)&kgtTargetStructure->shLifeGuageMax;
            }
            else if (cLifeRecovery != 0) {
              uVar9 = kgtTargetStructure->iHealth +
                      ((uint)cLifeRecovery * *(int *)&kgtTargetStructure->shLifeGuageMax) / 100;
              kgtTargetStructure->iHealth = uVar9;
                    /* Typecasting short to an int? */
              uVar10._0_2_ = kgtTargetStructure->shLifeGuageMax;
              uVar10._2_1_ = kgtTargetStructure->field1823_0x7cac[0];
              uVar10._3_1_ = kgtTargetStructure->field1823_0x7cac[1];
              if (uVar10 < uVar9) {
                kgtTargetStructure->iHealth = uVar10;
              }
            }
          }
                    /* Checking the player ignore bit on each cpu enemy */
          *(undefined4 *)&kgtTargetStructure->cEnemyBitmask = 0xfffffffe;
          if (((undefined1  [26])
               gkgtLoadedCharacter[0].kgtStoryEntries[iCurrentStoryStep].kgtStoryEntryCPUs[0] &
              (undefined1  [26])0x200) != (undefined1  [26])0x0) {
            *(undefined4 *)&kgtTargetStructure->cEnemyBitmask = 0xfffffffc;
          }
          if (((undefined1  [26])
               gkgtLoadedCharacter[0].kgtStoryEntries[iCurrentStoryStep].kgtStoryEntryCPUs[1] &
              (undefined1  [26])0x200) != (undefined1  [26])0x0) {
            *(uint *)&kgtTargetStructure->cEnemyBitmask =
                 *(uint *)&kgtTargetStructure->cEnemyBitmask & 0xfffffffb;
          }
          if (((undefined1  [26])
               gkgtLoadedCharacter[0].kgtStoryEntries[iCurrentStoryStep].kgtStoryEntryCPUs[2] &
              (undefined1  [26])0x200) != (undefined1  [26])0x0) {
            *(uint *)&kgtTargetStructure->cEnemyBitmask =
                 *(uint *)&kgtTargetStructure->cEnemyBitmask & 0xfffffff7;
          }
          if (((undefined1  [26])
               gkgtLoadedCharacter[0].kgtStoryEntries[iCurrentStoryStep].kgtStoryEntryCPUs[3] &
              (undefined1  [26])0x200) != (undefined1  [26])0x0) {
            *(uint *)&kgtTargetStructure->cEnemyBitmask =
                 *(uint *)&kgtTargetStructure->cEnemyBitmask & 0xffffffef;
          }
          if (((undefined1  [26])
               gkgtLoadedCharacter[0].kgtStoryEntries[iCurrentStoryStep].kgtStoryEntryCPUs[4] &
              (undefined1  [26])0x200) != (undefined1  [26])0x0) {
            *(uint *)&kgtTargetStructure->cEnemyBitmask =
                 *(uint *)&kgtTargetStructure->cEnemyBitmask & 0xffffffdf;
          }
          if (((undefined1  [26])
               gkgtLoadedCharacter[0].kgtStoryEntries[iCurrentStoryStep].kgtStoryEntryCPUs[5] &
              (undefined1  [26])0x200) != (undefined1  [26])0x0) {
            *(uint *)&kgtTargetStructure->cEnemyBitmask =
                 *(uint *)&kgtTargetStructure->cEnemyBitmask & 0xffffffbf;
          }
          if (((undefined1  [26])
               gkgtLoadedCharacter[0].kgtStoryEntries[iCurrentStoryStep].kgtStoryEntryCPUs[6] &
              (undefined1  [26])0x200) != (undefined1  [26])0x0) {
            *(uint *)&kgtTargetStructure->cEnemyBitmask =
                 *(uint *)&kgtTargetStructure->cEnemyBitmask & 0xffffff7f;
          }
          kgtTargetStructure->bShowLife = 1;
          kgtTargetStructure->round_start_var_c = 0;
        }
        else {
          kgtTargetStructure->iHealth = *(int *)&kgtTargetStructure->shLifeGuageMax;
          puVar1 = (kgtStoryEntryCpu *)(iCurrentStoryStep * 0xce + 0x4d9a47 + iPlayerIdx * 0x1a);
          uVar10 = *(uint *)puVar1;
                    /* I might have the left and right digits mixed up for
                       story_character_entry_info_bitmask */
          kgtTargetStructure->bShowLife = (short)(uVar10 & 1);
          kgtTargetStructure->round_start_var_c = (short)((uVar10 & 1) >> 0x10);
          *(uint *)&kgtTargetStructure->cEnemyBitmask = (uint)(byte)puVar1->cEnemyBitmask;
          uVar10 = *(uint *)puVar1 >> 1 & 3;
                    /* If character entry info bitmask has the time bit set */
          if (uVar10 == 1) {
            *(uint *)&pkgtoCurrentEngineObject->iOpponentDowntimeInFrames =
                 (uint)(byte)puVar1->cTimeMethodNumber * 100;
            if (puVar1->cTimeMethodNumberRandom != '\0') {
              time_rand = _rand();
              *(int *)&pkgtoCurrentEngineObject->iOpponentDowntimeInFrames =
                   *(int *)&pkgtoCurrentEngineObject->iOpponentDowntimeInFrames +
                   (time_rand % (int)(uint)(byte)puVar1->cTimeMethodNumberRandom) * 100;
              pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
            }
          }
          else {
                    /* If it has the life bit set */
            if ((uVar10 == 2) &&
               ((int)(uint)(byte)puVar1->cLifeMethodAmount <=
                gkgtLoadedCharacter[(byte)puVar1->cLifeMethodTarget].iHealth)) {
              pkgtoCurrentEngineObject->iProcessStep = 0;
              return;
            }
          }
          kgtTargetStructure->iColorInt = -1;
          kgtTargetStructure->iSpecialGaugeTokens = (int)kgtTargetStructure->cStartingStock;
          kgtTargetStructure->iSpecialGauge = 0;
          if (((undefined1  [26])*puVar1 & (undefined1  [26])0x200) == (undefined1  [26])0x0) {
            pkgtoCurrentEngineObject->iPlayerLookingRight = 1;
          }
        }
        pkgtoCurrentEngineObject->iPlayerBuffer_2 = pkgtoCurrentEngineObject->iPlayerIdx;
      }
      else {
                    /* STORY MODE PROCESSING END */
        if ((0 < (int)game_mode) && ((int)game_mode < 3)) {
          iPlayerBuffer_2 = pkgtoCurrentEngineObject->iPlayerIdx;
          kgtTargetStructure->iHealth = *(int *)&kgtTargetStructure->shLifeGuageMax;
          pkgtoCurrentEngineObject->iPlayerBuffer_2 = iPlayerBuffer_2;
          iPlayerBuffer_3 = pkgtoCurrentEngineObject->iPlayerIdx;
                    /* player_file_buff_idx3 -> ceiling 31 -> multiply by two? */
          *(int *)&kgtTargetStructure->cEnemyBitmask = -1 - (1 << ((byte)iPlayerBuffer_3 & 0x1f)) ;
          if (iPlayerBuffer_3 != 0) {
            *(undefined4 *)&kgtTargetStructure->bPlayerIdxIsNotZero = 1;
            pkgtoCurrentEngineObject->iPlayerLookingRight = 1;
          }
          if (pkgtoCurrentEngineObject->iPlayerIdx == 0) {
            pkgtoCurrentEngineObject->iParam3 = 0x1860000;
            kgtTargetStructure->iCurrentXPos = 0x1860000;
          }
          else {
            pkgtoCurrentEngineObject->iParam3 = 0x37a0000;
            kgtTargetStructure->iCurrentXPos = 0x37a0000;
          }
        }
      }
      temp_5f04860c28 = pkgtoCurrentEngineObject->iParam4;
      kgtTargetStructure->iCurrentXPos = pkgtoCurrentEngineObject->iParam3;
      kgtTargetStructure->iCurrentYPos = temp_5f04860c28;
      kgtTargetStructure->iLifeGaugeMax_2 = *(int *)&kgtTargetStructure->shLifeGuageMax;
      game_round = gkgtGameState.iCurrentRound;
      kgtTargetStructure->field6362_0xdf01 = 0;
      if ((int)game_round < 2) {
        kgtTargetStructure->iSpecialGaugeTokens = (int)kgtTargetStructure->cStartingStock;
        kgtTargetStructure->iSpecialGauge = 0;
      }
      kgtTargetStructure->iSpecialStockMax_2 = kgtTargetStructure->iSpecialStockMax;
      kgtTargetStructure->iSpecialStockGaugeMax_2 =
           *(int *)&kgtTargetStructure->shSpecialGuageStockMax;
      kgtTargetStructure->iLifeAddUnk1 = 0;
      kgtTargetStructure->field6373_0xdf29 = 0;
      kgtTargetStructure->pkgtoSelf = pkgtoCurrentEngineObject;
      kgtTargetStructure->poss_opponent_obj_ptr = (kgtEngineObject *)0x0;
      kgtTargetStructure->poss_opponent_obj_ptr_2? = (kgtEngineObject *)0x0;
      kgtTargetStructure->field6397_0xdf6d = 0;
      kgtTargetStructure->field6398_0xdf71 = 0;
      kgtTargetStructure->iCpuCommandIdx = 0;
      kgtTargetStructure->iWinPoint = 0;
      kgtTargetStructure->iCpuCommandTimer = 0;
      kgtTargetStructure->script_reading_0x14 = 0x14;
      kgtTargetStructure->unknown_online_var_a = 1;
      kgtTargetStructure->iUnknownCommandInputVar = 0;
      kgtTargetStructure->field6442_0xdfef = 0;
      kgtTargetStructure->iDoubleKoWinnerDeterminer = 0;
      kgtTargetStructure->field6383_0xdf49 = 0;
      kgtTargetStructure->field6361_0xdefd = 0;
      kgtTargetStructure->unk_image_wait_flag = 0;
      kgtTargetStructure->something_to_do_with_starting_health2 = 0;
      kgtTargetStructure->iHasCrouchAdvance = 0;
      kgtTargetStructure->iHasCrouchRetreat = 0;
      pSkillsAlloc = (kgtTargetStructure->kgtCore).pSkillsAlloc;
      if ((ushort)pSkillsAlloc[(ushort)kgtTargetStructure->shSkillIdxCrouchAdvance].
                  shStartingStepIdx + 1 <
          (uint)(ushort)pSkillsAlloc[(ushort)kgtTargetStructure->shSkillIdxCrouchAdvance + 1].
                        shStartingStepIdx) {
        kgtTargetStructure->iHasCrouchAdvance = 1;
      }
      pSkillsAlloc = (kgtTargetStructure->kgtCore).pSkillsAlloc;
                    /* Checking for crouch retreat vs turn standing */
      if ((ushort)pSkillsAlloc[(ushort)kgtTargetStructure->shSkillIdxCrouchRetreat].
                  shStartingStepIdx + 1 <
          (uint)(ushort)pSkillsAlloc[(ushort)kgtTargetStructure->shSkillIdxCrouchRetreat + 1].
                        shStartingStepIdx) {
        kgtTargetStructure->iHasCrouchRetreat = 1;
      }
                    /* Decide on player colors */
      iColorInt = gkgtLoadedCharacter[pkgtoCurrentEngineObject->iPlayerIdx].iColorInt;
      if (iColorInt == -1) {
        iColorInt = 0;
      }
      char_i = (short *)0x0;
      do {
        match_found = false;
        char_idx = 0;
        iColorIntOtherPlayer = &gkgtLoadedCharacter[0].iColorInt;
        do {
          if ((pkgtoCurrentEngineObject->iPlayerIdx != char_idx) &&
             (iColorInt == *iColorIntOtherPlayer)) {
            match_found = true;
          }
          iColorIntOtherPlayer = (int *)((int)iColorIntOtherPlayer + 0xe03f);
          char_idx = char_idx + 1;
        } while ((int)iColorIntOtherPlayer < 0x54ff83);
        if (!match_found) {
          gkgtLoadedCharacter[pkgtoCurrentEngineObject->iPlayerIdx].iColorInt = iColorInt;
          break;
        }
        iColorInt = iColorInt + 1U & 0x80000007;
        if (iColorInt < 0) {
          iColorInt = (iColorInt - 1U | 0xfffffff8) + 1;
        }
        char_i = (short *)((int)char_i + 1);
      } while ((int)char_i < 8);
      itemp_specialGauge = gkgtGameState.iTempSpecialGauge;
      itemp_SpecialGaugeTokens = gkgtGameState.iTempSpecialGaugeTokens;
      if ((gkgtGameState.kgtGameMode == VS_team) &&
         (gkgtGameState.unk_player_buffer_a == pkgtoCurrentEngineObject->iPlayerIdx)) {
        kgtTargetStructure->iHealth = gkgtGameState.iTempHealth;
        kgtTargetStructure->iSpecialGaugeTokens = itemp_SpecialGaugeTokens;
        kgtTargetStructure->iSpecialGauge = itemp_specialGauge;
      }
      pSkillsAlloc = (kgtTargetStructure->kgtCore).pSkillsAlloc;
      if ((ushort)pSkillsAlloc[(ushort)kgtTargetStructure->shSkillIdxR1].shStartingStepIdx + 1 <
          (uint)(ushort)pSkillsAlloc[(ushort)kgtTargetStructure->shSkillIdxR1 + 1].shStartingStep Idx
         ) {
        pkVar12 = kgtoNewEngineObject(pkgtoCurrentEngineObject->iJumpIdx,0xd,0,0);
        pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
        pkVar12->iObjectType = CHARACTER_ENGINE_OBJECT;
        uVar4 = kgtTargetStructure->shSkillIdxR1;
        pkVar12->iPlayerIdx = pkgtoCurrentEngineObject->iPlayerIdx;
        pkVar12->iSkillIdx = (uint)uVar4;
        *(uint *)&pkVar12->iSkillScriptIdx =
             (uint)(ushort)(kgtTargetStructure->kgtCore).pSkillsAlloc[uVar4].shStartingStepIdx;
      }
      else {
        pkgtoCurrentEngineObject->unk_bitmask = pkgtoCurrentEngineObject->unk_bitmask | 0x800000 00;
      }
      iSwitchCurrentObjectSkill((uint)(ushort)kgtTargetStructure->shSkillIdxStart);
      pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
      gpkgtCurrentEngineObject->obj_ptr_b =
           (kgtEngineObject *)((uint)gpkgtCurrentEngineObject->obj_ptr_b & 0xfffffff7 | 4);
      vMemzero(giInputBufferA + pkgtoCurrentEngineObject->iPlayerIdx,0x1000);
      vMemzero(&kgtTargetStructure->start_of_0x6,6);
      vMemzero(&kgtTargetStructure->variable_A,0x20);
      vMemzero(&kgtTargetStructure->start_of_0x2c,0x2c);
      pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
      gpkgtCurrentEngineObject->unk_bitmask = gpkgtCurrentEngineObject->unk_bitmask | 0x40000000 ;
      ppkVar14 = kgtTargetStructure->object_mNumbers;
      for (iCurrentStoryStep = 10; iCurrentStoryStep != 0;
          iCurrentStoryStep = iCurrentStoryStep + -1) {
        *ppkVar14 = (kgtEngineObject *)0x0;
        ppkVar14 = ppkVar14 + 1;
      }
      break;
    case STORY?_ENGINE_OBJECT:
      pkgtoCurrentEngineObject->iPlayerBuffer_2 = pkgtoCurrentEngineObject->iPlayerIdx;
      break;
    case STAGE_ENGINE_OBJECT:
      pkgtoCurrentEngineObject->iDsLandingSkillIdx = pkgtoCurrentEngineObject->iSkillIdx;
      pkgtoCurrentEngineObject->iStageSkillstepIdx =
           *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx;
      break;
    case CHARACTER_ENGINE_OBJECT:
      pkgtoCurrentEngineObject->unk_bitmask = pkgtoCurrentEngineObject->unk_bitmask | 0x40000000 ;
    }
    pkgtoCurrentEngineObject->iSkillIdx_2 = pkgtoCurrentEngineObject->iSkillIdx;
  }
  else if (gpkgtCurrentEngineObject->iProcessStep != 1) {
    return;
  }
                    /* Everything after this is after the initial frame */
  if ((pkgtoCurrentEngineObject->2_or_3 & 1) == 0) {
    pkgtoCurrentEngineObject->compare_to_param_4 = 0x3980000;
  }
  else {
    pkgtoCurrentEngineObject->compare_to_param_4 = 0x3520000;
  }
  if ((gkgtGameState.iIsPausedFlag != 0) &&
     (curr_obj_type = pkgtoCurrentEngineObject->iObjectType, -1 < (int)curr_obj_type)) {
    if ((int)curr_obj_type < 2) {
      return;
    }
    if (curr_obj_type == CHARACTER_ENGINE_OBJECT) {
      return;
    }
  }
  if (pkgtoCurrentEngineObject->0x650_index != 0) {
    uVar10 = (uint)(byte)pkgtoCurrentEngineObject->0x650_index;
    0650_size_offset = uVar10 * 0x650;
    if (*(char *)((int)gkgtLoadedStage.kgt_core.pallette_extra_bytes[uVar10 * 0x194 + 0x37] + 4)  !=
        '\0') {
      stage_unk_poss_action_idx =
           *(int *)(gkgtLoadedStage.kgt_core.pallette_extra_bytes + uVar10 * 0x194 + 0x36);
      unk_actionscript_final_0x10 =
           (int)((kgtTargetStructure->kgtCore).pSkillScriptsAlloc +
                *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + -1);
      stage_unk_var_b =
           (int)gkgtLoadedStage.kgt_core.pallette_extra_bytes[uVar10 * 0x194 + 0x38] + -1;
      gkgtLoadedStage.kgt_core.pallette_extra_bytes[uVar10 * 0x194 + 0x38] =
           (kgtPallette)stage_unk_var_b;
      if (stage_unk_var_b < 0) {
        kVar13.g = '\0';
        kVar13.r = '\0';
        kVar13.field3_0x3 = '\0';
        kVar13.b = *(byte *)((int)gkgtLoadedStage.kgt_core.pallette_extra_bytes
                                  [uVar10 * 0x194 + 0x37] + 4);
        gkgtLoadedStage.kgt_core.pallette_extra_bytes[uVar10 * 0x194 + 0x38] = kVar13;
        *(int *)((stage_unk_poss_action_idx + 1) * 0x10 + 0x447930 + 0650_size_offset) =
             pkgtoCurrentEngineObject->iParam3;
        stage_unk_poss_action = stage_unk_poss_action_idx * 0x10 + 0x447930 + 0650_size_offset;
        mystery_val_sub_bool = pkgtoCurrentEngineObject->iPlayerLookingRight;
        *(int *)(stage_unk_poss_action + 0x14) = pkgtoCurrentEngineObject->iParam4;
        *(uint *)(stage_unk_poss_action + 0x18) =
             ((*(ushort *)(unk_actionscript_final_0x10 + 3) & 0x4000) >> 0xe) +
             mystery_val_sub_bool * 4;
        *(int *)(stage_unk_poss_action + 0x1c) = unk_actionscript_final_0x10;
        gkgtLoadedStage.kgt_core.pallette_extra_bytes[uVar10 * 0x194 + 0x36] =
             (kgtPallette)
             (((int)gkgtLoadedStage.kgt_core.pallette_extra_bytes[uVar10 * 0x194 + 0x36] + 1) % 1 00)
        ;
      }
    }
  }
  if (pkgtoCurrentEngineObject->iHitJunctionIdx != 0) {
    pkgtoCurrentEngineObject->iSkillIdx = -1;
    vAssignSkillAndResetOtherValues(pkgtoCurrentEngineObject->iHitJunctionIdx & 0xffff);
    pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
    *(uint *)&gpkgtCurrentEngineObject->iSkillScriptIdx =
         *(int *)&gpkgtCurrentEngineObject->iSkillScriptIdx +
         ((uint)gpkgtCurrentEngineObject->iHitJunctionIdx >> 0x10);
    pkgtoCurrentEngineObject->iHitJunctionIdx = 0;
    pkgtoCurrentEngineObject->iLoopFrequency = 0;
    iResetDsSkillIndices();
    vResetReactionSkillBlock(gpkgtCurrentEngineObject);
    vMemzeroHitboxArrays(gpkgtCurrentEngineObject);
    pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
    goto check_image_wait_frames;
  }
  iOpponentDownTime = *(int *)&pkgtoCurrentEngineObject->iOpponentDowntimeInFrames;
  if (iOpponentDownTime != 0) {
    if (iOpponentDownTime == -1) {
      return;
    }
    *(int *)&pkgtoCurrentEngineObject->iOpponentDowntimeInFrames = iOpponentDownTime + -1;
    return;
  }
  curr_obj_type = pkgtoCurrentEngineObject->iObjectType;
  if (curr_obj_type == PLAYER_ENGINE_OBJECT) {
    gkgtLoadedCharacter[pkgtoCurrentEngineObject->iPlayerIdx].field6452_0xdfff = 0;
    vUnkXDistanceHandling();
    vProcessInputsIntoSkills();
    if (kgtTargetStructure->iLifeAddUnk1 != 0) {
      if (kgtTargetStructure->field6373_0xdf29 == 0) {
        kgtTargetStructure->iLifeAddUnk1 = kgtTargetStructure->iLifeAddUnk1 + -1;
      }
      else {
        kgtTargetStructure->field6373_0xdf29 = kgtTargetStructure->field6373_0xdf29 + -1;
      }
    }
    pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
    initial_y_val = gpkgtCurrentEngineObject->iParam4;
    kgtTargetStructure->iCurrentXPos = gpkgtCurrentEngineObject->iParam3;
    kgtTargetStructure->iCurrentYPos = initial_y_val;
    goto check_image_wait_frames;
  }
  if (curr_obj_type != STORY?_ENGINE_OBJECT) {
    if (curr_obj_type == CHARACTER_ENGINE_OBJECT) {
      piVar16 = pkgtoCurrentEngineObject->parent_obj;
      if (piVar16->iJumpIdx == RESET_IDX) {
switchD_0041270c_default:
        vStoryHitboxCheck();
        return;
      }
      if (piVar16->iDrawFlag != -1) {
        return;
      }
      pkgtoCurrentEngineObject->iParam3 = piVar16->iParam3;
      pkgtoCurrentEngineObject->iParam4 = pkgtoCurrentEngineObject->parent_obj->compare_to_param _4;
      pkgtoCurrentEngineObject->iPlayerLookingRight =
           pkgtoCurrentEngineObject->parent_obj->iPlayerLookingRight;
    }
    goto check_image_wait_frames;
  }
  if ((pkgtoCurrentEngineObject->compare_to_param_4 <= pkgtoCurrentEngineObject->iParam4) &&
     (0 < pkgtoCurrentEngineObject->iYMomentum)) {
    pkgtoCurrentEngineObject->iParam4 = pkgtoCurrentEngineObject->compare_to_param_4;
    pkgtoCurrentEngineObject->iXGravity = 0;
    pkgtoCurrentEngineObject->iXMomentum = 0;
    pkgtoCurrentEngineObject->iYGravity = 0;
    pkgtoCurrentEngineObject->iYMomentum = 0;
    pkgtoCurrentEngineObject->obj_ptr_b =
         (kgtEngineObject *)((uint)pkgtoCurrentEngineObject->obj_ptr_b & 0xfffffffc);
    pkgtoCurrentEngineObject->iSkillIdx = -1;
    if (pkgtoCurrentEngineObject->iDsLandingSkillIdx == 0) {
      iAssignPlayerLookingRight();
      pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
      gpkgtCurrentEngineObject->obj_ptr_b =
           (kgtEngineObject *)((uint)gpkgtCurrentEngineObject->obj_ptr_b & 0xffffffe3);
    }
    else {
      uVar10 = pkgtoCurrentEngineObject->iDsLandingSkillIdx & 0xffff;
      pkgtoCurrentEngineObject->iSkillIdx = uVar10;
      *(uint *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
           (uint)(ushort)gkgtLoadedCharacter[pkgtoCurrentEngineObject->iPlayerIdx].kgtCore.
                         pSkillsAlloc[uVar10].shStartingStepIdx +
           ((uint)pkgtoCurrentEngineObject->iDsLandingSkillIdx >> 0x10);
      pkgtoCurrentEngineObject->iDsLandingSkillIdx = 0;
      pkgtoCurrentEngineObject->iImageWaitFrames = 0;
      vMemzeroHitboxArrays(pkgtoCurrentEngineObject);
      pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
    }
  }
  if ((((pkgtoCurrentEngineObject->iParam3 < -0x320000) ||
       (0x5320000 < pkgtoCurrentEngineObject->iParam3)) ||
      (pkgtoCurrentEngineObject->iParam4 < -0x320000)) ||
     (0x3f20000 < pkgtoCurrentEngineObject->iParam4)) {
    if ((pkgtoCurrentEngineObject->unk_bitmask & 0x20000000U) == 0) {
      vStoryHitboxCheck();
      pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
      goto LAB_004124fb;
    }
  }
  else {
LAB_004124fb:
    if ((pkgtoCurrentEngineObject->unk_bitmask & 0x20000000U) == 0) goto check_image_wait_frames ;
  }
  if (pkgtoCurrentEngineObject->parent_obj->iJumpIdx == RESET_IDX) {
    vStoryHitboxCheck();
    pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
  }
check_image_wait_frames:
  if ((pkgtoCurrentEngineObject->iImageWaitFrames < 0) ||
     (iCurrentStoryStep = pkgtoCurrentEngineObject->iImageWaitFrames + -100,
     pkgtoCurrentEngineObject->iImageWaitFrames = iCurrentStoryStep, -1 < iCurrentStoryStep)) {
    return;
  }
  local_108 = 1;
  hitbox = (kgtSkill *)(pkgtoCurrentEngineObject->kgtHitboxAttacks + 0x13);
  i20 = 20;
  do {
    if ((*(int *)hitbox != 0) && ((*(byte *)(*(int *)hitbox + 10) & 2) != 0)) {
      pkgtoCurrentEngineObject->obj_ptr_b =
           (kgtEngineObject *)((uint)pkgtoCurrentEngineObject->obj_ptr_b & 0xffffffef);
    }
    i20 = i20 + -1;
    hitbox = (kgtSkill *)&hitbox[-1].field_0xc;
  } while (i20 != 0);
Pre_Script_reading_switch_statement:
                    /* *** WHERE READING THE ACTIONSCRIPT SEEMS TO BEGIN *** */
  current_skill_idx = pkgtoCurrentEngineObject->iSkillIdx;
  local_108 = local_108 + 1;
  if (local_108 < 301) {
    if ((int)(uint)(ushort)(kgtTargetStructure->kgtCore).pSkillsAlloc[current_skill_idx + 1].
                           shStartingStepIdx <= *(int *)&pkgtoCurrentEngineObject->iSkillScriptId x)
    goto script_switch_statement_case_0x29;
Script_reading_switch_statement:
    skill = (kgtTargetStructure->kgtCore).pSkillScriptsAlloc +
            *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx;
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
    switch(skill->cSkillType) {
    case '\x01':
      goto switchD_00412610_compute_momentum;
    case '\x02':
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
      iCurrentStoryStep =
           (uint)(byte)skill->field_0x4 * 0x10000 + (uint)*(ushort *)&skill->field_0x2;
      switch(skill->field_0x1) {
      case 1:
        pkgtoCurrentEngineObject->iDsLandingSkillIdx = iCurrentStoryStep;
        *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
             *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
        break;
      case 2:
        pkgtoCurrentEngineObject->iDsAttackHitsSkillIdx = iCurrentStoryStep;
        *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
             *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
        break;
      case 3:
        pkgtoCurrentEngineObject->iStageSkillstepIdx = iCurrentStoryStep;
        *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
             *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
        break;
      case 4:
        pkgtoCurrentEngineObject->iDsHotToWallIdx = iCurrentStoryStep;
        *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
             *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
        break;
      case 5:
        pkgtoCurrentEngineObject->iDsInOffsetSkillIdx = iCurrentStoryStep;
        *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
             *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
        break;
      case 6:
        pkgtoCurrentEngineObject->iDsWhileThrowDo = iCurrentStoryStep;
        *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
             *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
        break;
      default:
        goto switchD_00412610_advance_skillscript;
      }
      goto LAB_004125ae;
    case '\x03':
                    /* ----------------------------------
                       - S - Sound -
                       ----------------------------------
                       0 - Type
                       1 - unk
                       2 - Sound ID (low)
                       3 - Sound ID (high) */
      vHandleLoadingSound((kgtTargetStructure->kgtCore).pkgtSounds + *(ushort *)&skill->field_0x 2);
      pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
      *(int *)&gpkgtCurrentEngineObject->iSkillScriptIdx =
           *(int *)&gpkgtCurrentEngineObject->iSkillScriptIdx + 1;
      goto LAB_004125ae;
    case '\x04':
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
      if ((1 < (int)pkgtoCurrentEngineObject->iObjectType) || ((skill->field_0x1 & 4) != 0))
      goto LAB_00412b0a;
      m_val = skill->field_0xc;
      if (kgtTargetStructure->object_mNumbers[m_val] == (kgtEngineObject *)0x0) goto LAB_00412b0 a;
      iCurrentStoryStep = 0;
      pkVar12 = kgtEngineObjects;
      goto OBJECT_BLOCK_LOOP;
    case '\x05':
    case ')':
                    /* 05 is END
                       29 in editor is SB (Super background) which seems unused. Code is interprete d
                       as END? */
      if (pkgtoCurrentEngineObject->iObjectType != PLAYER_ENGINE_OBJECT)
      goto switchD_0041270c_default;
script_switch_statement_case_0x29:
      if (pkgtoCurrentEngineObject->iReturnSkillIdx == 0) {
        if (pkgtoCurrentEngineObject->iLoopFrequency == '\0') {
          pkgtoCurrentEngineObject->iImageWaitFrames = 0;
          iResetDsSkillIndices();
          pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
          gpkgtCurrentEngineObject->obj_ptr_b =
               (kgtEngineObject *)((uint)gpkgtCurrentEngineObject->obj_ptr_b & 0xffffffef);
          switch(pkgtoCurrentEngineObject->iObjectType) {
          case PLAYER_ENGINE_OBJECT:
            kgtTargetStructure->iCurrentActionCancellableFlag = 0;
            kgtTargetStructure->field6362_0xdf01 = 0;
            pkgtoCurrentEngineObject->iSkillIdx = -1;
            kgtTargetStructure->field6442_0xdfef = 0;
            vCheckIfDrawThenMove();
            pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
            break;
          case STORY?_ENGINE_OBJECT:
            uVar10 = pkgtoCurrentEngineObject->iSkillIdx_2;
            if (uVar10 == (ushort)kgtTargetStructure->shSkillIdxCharSelectPic) {
              if (pkgtoCurrentEngineObject->iDrawFlag == 0) {
                vStoryHitboxCheck();
                return;
              }
              goto LAB_004127c3;
            }
            if ((uVar10 != (ushort)kgtTargetStructure->shSkillIdxStageFacePic) ||
               (pkgtoCurrentEngineObject->iDrawFlag == 0)) goto switchD_0041270c_default;
            pkgtoCurrentEngineObject->iSkillIdx = uVar10;
            *(uint *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
                 (uint)(ushort)(kgtTargetStructure->kgtCore).pSkillsAlloc[uVar10].shStartingStepI dx;
            break;
          case SYSTEM_ENGINE_OBJECT:
            if (((kgtTargetStructure->kgtCore).pSkillsAlloc[pkgtoCurrentEngineObject->iSkillIdx_ 2].
                 cDemoDefaultScriptGroup & 0x20U) != 0) goto switchD_0041270c_default;
          case DEMO_ENGINE_OBJECT:
          case STAGE_ENGINE_OBJECT:
          case CHARACTER_ENGINE_OBJECT:
            if (pkgtoCurrentEngineObject->iDrawFlag == 0) goto switchD_0041270c_default;
            uVar10 = pkgtoCurrentEngineObject->iSkillIdx_2;
LAB_004127c3:
            pSkillsAlloc = (kgtTargetStructure->kgtCore).pSkillsAlloc;
            pkgtoCurrentEngineObject->iSkillIdx = uVar10;
            *(uint *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
                 (uint)(ushort)pSkillsAlloc[uVar10].shStartingStepIdx;
            break;
          default:
            goto switchD_0041270c_default;
          }
        }
        else {
          bCarryOver = pkgtoCurrentEngineObject->iLoopFrequency + -1;
          pkgtoCurrentEngineObject->iLoopFrequency = bCarryOver;
          if (bCarryOver == '\0') {
            pSkillsAlloc = (kgtTargetStructure->kgtCore).pSkillsAlloc;
            uVar10 = *(uint *)&pkgtoCurrentEngineObject->loop_skillscript_idx & 0xffff;
            pkgtoCurrentEngineObject->iSkillIdx = uVar10;
            *(uint *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
                 (ushort)pSkillsAlloc[uVar10].shStartingStepIdx + 1 +
                 (*(int *)&pkgtoCurrentEngineObject->loop_skillscript_idx >> 0x10);
          }
          else {
            pSkillsAlloc = (kgtTargetStructure->kgtCore).pSkillsAlloc;
            uVar10 = *(uint *)&pkgtoCurrentEngineObject->field_0x7d & 0xffff;
            pkgtoCurrentEngineObject->iSkillIdx = uVar10;
            *(uint *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
                 (uint)(ushort)pSkillsAlloc[uVar10].shStartingStepIdx +
                 (*(int *)&pkgtoCurrentEngineObject->field_0x7d >> 0x10);
          }
        }
      }
      else {
        uVar10 = pkgtoCurrentEngineObject->iReturnSkillIdx & 0xffff;
        pkgtoCurrentEngineObject->iSkillIdx = uVar10;
        *(uint *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
             (ushort)(kgtTargetStructure->kgtCore).pSkillsAlloc[uVar10].shStartingStepIdx + 1 +
             (pkgtoCurrentEngineObject->iReturnSkillIdx >> 0x10);
        pkgtoCurrentEngineObject->iReturnSkillIdx = 0;
      }
      goto Script_reading_switch_statement;
    default:
      goto switchD_00412610_advance_skillscript;
    case '\a':
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
      if (((pkgtoCurrentEngineObject->iObjectType != PLAYER_ENGINE_OBJECT) ||
          (*(short *)&skill->field_0x2 == 0)) ||
         (pkVar12 = kgtTargetStructure->poss_opponent_obj_ptr, pkVar12 == (kgtEngineObject *)0x0 ))
      goto switchD_00412610_advance_skillscript;
      RC_flags = skill->field_0x1;
      if ((RC_flags & 1) == 0) {
                    /* If not depth add */
        uVar10 = *(uint *)&pkVar12->2_or_3;
        pkgtoCurrentEngineObject->iParam2 =
             (&INT_0041f130)[*(uint *)&pkgtoCurrentEngineObject->2_or_3 & 1] + -1;
        iCurrentStoryStep = (&INT_0041f130)[uVar10 & 1] + 1;
      }
      else {
        uVar10 = *(uint *)&pkVar12->2_or_3;
        pkgtoCurrentEngineObject->iParam2 =
             (&INT_0041f130)[*(uint *)&pkgtoCurrentEngineObject->2_or_3 & 1] + 1;
        iCurrentStoryStep = (&INT_0041f130)[uVar10 & 1] + -1;
      }
      iPlayerIdx = pkgtoCurrentEngineObject->iPlayerLookingRight;
      pkVar12->iParam2 = iCurrentStoryStep;
      if ((iPlayerIdx & 1) == 0) {
                    /* Y turn flag? */
        pkVar12->iParam3 = *(short *)&skill->field_0x4 * 0x10000 + pkgtoCurrentEngineObject->iPa ram3
        ;
        if ((RC_flags & 4) == 0) goto LAB_00412f3d;
        pkVar12->iPlayerLookingRight = 0;
      }
      else {
        pkVar12->iParam3 =
             pkgtoCurrentEngineObject->iParam3 + *(short *)&skill->field_0x4 * -0x10000;
        if ((RC_flags & 4) == 0) {
          pkVar12->iPlayerLookingRight = 0;
        }
        else {
LAB_00412f3d:
          pkVar12->iPlayerLookingRight = 1;
        }
      }
      pkVar12->iParam4 = *(short *)&skill->field_0x6 * 0x10000 + pkgtoCurrentEngineObject->iPara m4;
      vMemzeroHitboxArrays(pkgtoCurrentEngineObject);
      pkVar12->iXMomentum = 0;
      pkVar12->iYMomentum = 0;
      pkVar12->iXGravity = 0;
      pkVar12->iYGravity = 0;
      if (pkVar12->iObjectType == PLAYER_ENGINE_OBJECT) {
        iCurrentStoryStep = pkVar12->iPlayerIdx;
        uVar4 = *(ushort *)&skill->field_0x2;
        pkVar5 = gkgtLoadedCharacter[iCurrentStoryStep].kgtCore.pSkillScriptsAlloc;
        pkVar12->iDrawFlag = -1;
        *(ushort *)&pkVar5->field_0x3 =
             *(ushort *)(iCurrentStoryStep * 0xe03f + 0x4d8e4a + (uint)uVar4 * 6) & 0x1fff |
             (ushort)(skill->field_0x1 & 0xc) << 0xc;
        uVar4 = *(ushort *)&skill->field_0x2;
        pkVar5->cSkillType = '\f';
        pkVar12->iSkillIdx = 0;
        *(undefined4 *)&pkVar12->iSkillScriptIdx = 1;
        sVar2 = gkgtLoadedCharacter[iCurrentStoryStep].kgtCommonImages[uVar4].shY_Movement;
        *(short *)&pkVar5->field_0x5 =
             gkgtLoadedCharacter[iCurrentStoryStep].kgtCommonImages[uVar4].shX_Movement;
        *(short *)&pkVar5->field_0x7 = sVar2;
        vMemzeroHitboxArrays(pkVar12);
        vResetReactionSkillBlock(pkVar12);
        sVar2 = *(short *)&skill->field_0x4;
        sVar3 = *(short *)&skill->field_0x6;
        kgtTargetStructure->field6442_0xdfef = (byte)skill->field_0x1 | 0x20;
        pkgtoCurrentEngineObject = pkVar12->obj_ptr_b;
        *(int *)((int)&kgtTargetStructure->script_obj_var_d + 2) = (int)sVar2 << 0x10;
        *(int *)&kgtTargetStructure->field_0xdffb = (int)sVar3 << 0x10;
        pkVar12->obj_ptr_b = (kgtEngineObject *)((uint)pkgtoCurrentEngineObject & 0xfffffffa | 1 0);
      }
      pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
      *(undefined4 *)&pkVar12->iOpponentDowntimeInFrames = 0xffffffff;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
           *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
      goto LAB_004125ae;
    case '\t':
                    /* ----------------------------------
                       - SF - Loop -
                       ----------------------------------
                       0 - Type
                       1 - Frequency
                       2 - Skill ID (low)
                       3 - Skill ID (high)
                       4 - Command ID */
      if ((skill->field_0x1 == '\0') || (skill_id = *(ushort *)&skill->field_0x2, skill_id == 0) )
      goto switchD_00412610_advance_skillscript;
      pSkillsAlloc = (kgtTargetStructure->kgtCore).pSkillsAlloc;
      command_id = skill->field_0x4;
      *(uint *)&pkgtoCurrentEngineObject->loop_skillscript_idx =
           (*(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx -
           (uint)(ushort)pSkillsAlloc[pkgtoCurrentEngineObject->iSkillIdx].shStartingStepIdx) *
           0x10000 + pkgtoCurrentEngineObject->iSkillIdx;
      pkgtoCurrentEngineObject->iLoopFrequency = skill->field_0x1;
      skill_id_2 = (uint)skill_id;
      *(uint *)&pkgtoCurrentEngineObject->field_0x7d = (uint)command_id * 0x10000 + skill_id_2;
      pkgtoCurrentEngineObject->iSkillIdx = skill_id_2;
      actionscript_idx = ((ushort)pSkillsAlloc[skill_id_2].shStartingStepIdx - 1) + (uint)command _id
      ;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx = actionscript_idx;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx = actionscript_idx + 1;
      goto LAB_004125ae;
    case '\n':
                    /* ----------------------------------
                       - SG - GoTo -
                       ----------------------------------
                       0 - Type
                       1 - Skill ID (low)
                       2 - Skill ID (high)
                       3 - Command ID */
      if (*(ushort *)&skill->field_0x1 != 0) {
        pSkillsAlloc = (kgtTargetStructure->kgtCore).pSkillsAlloc;
        uVar10 = (uint)*(ushort *)&skill->field_0x1;
        pkgtoCurrentEngineObject->iSkillIdx = uVar10;
        goto LAB_0041298b;
      }
      goto switchD_00412610_advance_skillscript;
    case '\v':
                    /* ----------------------------------
                       - SC - Call -
                       ----------------------------------
                       0 - Type
                       1 - Skill ID (low)
                       2 - Skill ID (high)
                       3 - Command ID */
      if (*(short *)&skill->field_0x1 == 0) goto switchD_00412610_advance_skillscript;
      pSkillsAlloc = (kgtTargetStructure->kgtCore).pSkillsAlloc;
      pkgtoCurrentEngineObject->iReturnSkillIdx =
           (*(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx -
           (uint)(ushort)pSkillsAlloc[pkgtoCurrentEngineObject->iSkillIdx].shStartingStepIdx) *
           0x10000 + pkgtoCurrentEngineObject->iSkillIdx;
      uVar10 = (uint)*(ushort *)&skill->field_0x1;
      pkgtoCurrentEngineObject->iSkillIdx = uVar10;
LAB_0041298b:
      sc_command_id =
           ((ushort)pSkillsAlloc[uVar10].shStartingStepIdx - 1) + (uint)(byte)skill->field_0x3;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx = sc_command_id;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx = sc_command_id + 1;
      goto LAB_004125ae;
    case '\f':
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
      if (pkgtoCurrentEngineObject->iObjectType == PLAYER_ENGINE_OBJECT) {
        kgtTargetStructure->unk_image_wait_flag = 1;
      }
      image_wait = *(ushort *)&skill->field_0x1;
      image_wait_frames = -1;
      pkgtoCurrentEngineObject->iDrawFlag = -1;
      if (image_wait != 0) {
        image_wait_frames =
             pkgtoCurrentEngineObject->iImageWaitFrames + (uint)image_wait * giGamespeedFrames;
      }
      pkgtoCurrentEngineObject->iImageWaitFrames = image_wait_frames;
      local_108 = 0;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
           *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
      goto LAB_004125ae;
    case '\x0e':
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
          flash_player_buffer = pkgtoCurrentEngineObject->iPlayerIdx;
          *(uint *)&gkgtLoadedCharacter[flash_player_buffer].start_of_0x2c = (uint)pallette_flash ;
          *(int *)&gkgtLoadedCharacter[flash_player_buffer].flash_red = (int)(char)skill->field_0 x2;
          *(int *)&gkgtLoadedCharacter[flash_player_buffer].flash_green =
               (int)(char)skill->field_0x3;
          *(int *)&gkgtLoadedCharacter[flash_player_buffer].flash_blue = (int)(char)skill->field_ 0x4
          ;
          *(int *)&gkgtLoadedCharacter[flash_player_buffer].flash_alpha =
               (int)(char)skill->field_0x5;
          *(int *)&gkgtLoadedCharacter[flash_player_buffer].flash_var_a =
               pkgtoCurrentEngineObject->iColorRed;
          *(int *)&gkgtLoadedCharacter[flash_player_buffer].flash_var_b =
               pkgtoCurrentEngineObject->iColorGreen;
          *(int *)&gkgtLoadedCharacter[flash_player_buffer].flash_var_c =
               pkgtoCurrentEngineObject->iColorBlue;
          uVar6 = *(undefined3 *)&pkgtoCurrentEngineObject->field_0x51;
          gkgtLoadedCharacter[flash_player_buffer].flash_var_d =
               pkgtoCurrentEngineObject->color_alpha;
          *(undefined3 *)&gkgtLoadedCharacter[flash_player_buffer].field_0xe038 = uVar6;
          flash_duration = *(ushort *)&skill->field_0x6;
          *(uint *)&gkgtLoadedCharacter[flash_player_buffer].flash_duration_a = (uint)flash_durat ion
          ;
          *(uint *)&gkgtLoadedCharacter[flash_player_buffer].flash_duration_b = (uint)flash_durat ion
          ;
        }
        if (((skill->field_0x8 & 2) != 0) &&
           (kgtTargetStructure->poss_opponent_obj_ptr != (kgtEngineObject *)0x0)) {
                    /* OPPSIDE flag */
          flash_opponent_buffer = kgtTargetStructure->poss_opponent_obj_ptr->iPlayerIdx;
          *(uint *)&gkgtLoadedCharacter[flash_opponent_buffer].start_of_0x2c = (uint)pallette_fla sh;
          *(int *)&gkgtLoadedCharacter[flash_opponent_buffer].flash_red =
               (int)(char)skill->field_0x2;
          *(int *)&gkgtLoadedCharacter[flash_opponent_buffer].flash_green =
               (int)(char)skill->field_0x3;
          *(int *)&gkgtLoadedCharacter[flash_opponent_buffer].flash_blue =
               (int)(char)skill->field_0x4;
          *(int *)&gkgtLoadedCharacter[flash_opponent_buffer].flash_alpha =
               (int)(char)skill->field_0x5;
          *(undefined4 *)&gkgtLoadedCharacter[flash_opponent_buffer].flash_var_a = 0;
          *(undefined4 *)&gkgtLoadedCharacter[flash_opponent_buffer].flash_var_b = 0;
          *(undefined4 *)&gkgtLoadedCharacter[flash_opponent_buffer].flash_var_c = 0;
          *(undefined4 *)&gkgtLoadedCharacter[flash_opponent_buffer].flash_var_d = 0;
          opp_flash_duration = *(ushort *)&skill->field_0x6;
          *(uint *)&gkgtLoadedCharacter[flash_opponent_buffer].flash_duration_a =
               (uint)opp_flash_duration;
          *(uint *)&gkgtLoadedCharacter[flash_opponent_buffer].flash_duration_b =
               (uint)opp_flash_duration;
        }
        if ((skill->field_0x8 & 4) != 0) {
                    /* BG flag */
          giPalletteFlash = (int)pallette_flash;
          INT_00447d95 = 0;
          INT_00447d99 = 0;
          giPalletteFlashRed = (int)(char)skill->field_0x2;
          INT_00447d9d = 0;
          giPalletteFlashGreen = (int)(char)skill->field_0x3;
          INT_00447da1 = 0;
          giPalletteFlashBlue = (int)(char)skill->field_0x4;
          giPalletteFlashAlpha = (int)(char)skill->field_0x5;
          giPalletteFlashDuration = (int)*(ushort *)&skill->field_0x6;
          giPalletteFlashDuration_B = giPalletteFlashDuration;
        }
        if ((skill->field_0x8 & 8) != 0) {
                    /* SYSTEM flag */
          _system_flash_red = (int)(char)skill->field_0x2;
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
        giPicSwayX = (int)(byte)skill->field_0x9;
        giPicShakeX = (int)(byte)skill->field_0xa;
        giShakeX = 0;
        giPicSwayXDuration = (int)(byte)skill->field_0xb;
        giPicSwayXDuration_2 = giPicSwayXDuration;
      }
      if (skill->field_0xc == 0) goto switchD_00412610_advance_skillscript;
                    /* Pic sway Y */
      giPicSwayY = (int)(byte)skill->field_0xc;
      giShakeY = 0;
      giPicShakeY = (int)(byte)skill->field_0xd;
      giPicSwayYDuration = (int)(byte)skill->field_0xe;
      giPicSwayYDuration_2 = giPicSwayYDuration;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
           *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
      goto LAB_004125ae;
    case '\x10':
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
        if ((gkgtLoadedCharacter[pkgtoCurrentEngineObject->iPlayerIdx].iSpecialGaugeTokens <
             (int)(uint)(byte)skill->field_0x6) ||
           (GS_skill_idx = *(ushort *)&skill->field_0x2, GS_skill_idx == 0))
        goto switchD_00412610_advance_skillscript;
        pkgtoCurrentEngineObject->iSkillIdx = (uint)GS_skill_idx;
        if (GS_skill_idx == 0) {
          iCurrentStoryStep =
               gkgtLoadedCharacter[pkgtoCurrentEngineObject->iPlayerIdx].iUnknownCommandInputVar ;
LAB_004135a7:
          iCurrentStoryStep = sHandlePlayerCommandSequence(iCurrentStoryStep);
          pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
          if (iCurrentStoryStep != 0) {
            gpkgtCurrentEngineObject->iSkillIdx = iCurrentStoryStep;
          }
        }
      }
      else {
                    /* When alot */
        if ((int)(uint)(byte)skill->field_0x6 <
            gkgtLoadedCharacter[pkgtoCurrentEngineObject->iPlayerIdx].iSpecialGaugeTokens) {
          GS_player_buffer = pkgtoCurrentEngineObject->iPlayerIdx;
          add_to_special =
               iSubtractTwoFiftySixIfAboveOneTwentySeven
                         (CONCAT31((int3)((byte)skill->cSkillType - 1 >> 8),skill->field_0x7));
          new_special_gauge =
               gkgtLoadedCharacter[GS_player_buffer].iSpecialGaugeTokens + add_to_special;
          gkgtLoadedCharacter[GS_player_buffer].iSpecialGaugeTokens = new_special_gauge;
          if (new_special_gauge < 0) {
            gkgtLoadedCharacter[GS_player_buffer].iSpecialGaugeTokens = 0;
          }
          pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
          if ((uint)gkgtLoadedCharacter[GS_player_buffer].iSpecialGaugeTokens <
              (uint)gkgtLoadedCharacter[GS_player_buffer].iSpecialStockMax)
          goto switchD_00412610_advance_skillscript;
                    /* Enforce special gauge max */
          gkgtLoadedCharacter[GS_player_buffer].iSpecialGaugeTokens =
               gkgtLoadedCharacter[GS_player_buffer].iSpecialStockMax;
          gkgtLoadedCharacter[GS_player_buffer].iSpecialGauge = 0;
          pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
          *(int *)&gpkgtCurrentEngineObject->iSkillScriptIdx =
               *(int *)&gpkgtCurrentEngineObject->iSkillScriptIdx + 1;
          goto LAB_004125ae;
        }
        uVar4 = *(ushort *)&skill->field_0x2;
        pkgtoCurrentEngineObject->iSkillIdx = (uint)uVar4;
        if (uVar4 == 0) {
          iCurrentStoryStep =
               gkgtLoadedCharacter[pkgtoCurrentEngineObject->iPlayerIdx].iUnknownCommandInputVar ;
          goto LAB_004135a7;
        }
      }
      uVar10 = pkgtoCurrentEngineObject->iSkillIdx;
      goto LAB_004135bf;
    case '\x11':
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
        if ((kgtTargetStructure->iHealth < (int)(uint)*(ushort *)&skill->field_0x6) ||
           (*(short *)&skill->field_0x2 == 0)) goto switchD_00412610_advance_skillscript;
      }
      else if ((int)(uint)*(ushort *)&skill->field_0x6 < kgtTargetStructure->iHealth)
      goto switchD_00412610_advance_skillscript;
      pSkillsAlloc = (kgtTargetStructure->kgtCore).pSkillsAlloc;
      GL_skill_idx = *(ushort *)&skill->field_0x2;
      pkgtoCurrentEngineObject->iSkillIdx = (uint)GL_skill_idx;
      *(uint *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
           ((ushort)pSkillsAlloc[GL_skill_idx].shStartingStepIdx - 1) + (uint)(byte)skill->field_ 0x4
      ;
      if ((pkgtoCurrentEngineObject->iSkillIdx != 0) ||
         (iCurrentStoryStep =
               sHandlePlayerCommandSequence(kgtTargetStructure->iUnknownCommandInputVar),
         pkgtoCurrentEngineObject = gpkgtCurrentEngineObject, iCurrentStoryStep == 0))
      goto switchD_00412610_advance_skillscript;
      pSkillsAlloc = (kgtTargetStructure->kgtCore).pSkillsAlloc;
      gpkgtCurrentEngineObject->iSkillIdx = iCurrentStoryStep;
      uVar10 = (uint)(ushort)pSkillsAlloc[iCurrentStoryStep].shStartingStepIdx;
      *(uint *)&pkgtoCurrentEngineObject->iSkillScriptIdx = uVar10 - 1;
      *(uint *)&pkgtoCurrentEngineObject->iSkillScriptIdx = uVar10;
      goto LAB_004125ae;
    case '\x14':
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
                       +0x1 = 'In' (unset is 'Out')
                       +0x4 = 'Turn X' */
      if ((pkgtoCurrentEngineObject->iObjectType != PLAYER_ENGINE_OBJECT) ||
         (opp_obj_ptr = kgtTargetStructure->poss_opponent_obj_ptr,
         opp_obj_ptr == (kgtEngineObject *)0x0)) goto switchD_00412610_advance_skillscript;
      iRpFlags = skill->field_0x1;
      if ((iRpFlags & 1) == 0) {
        uVar10 = *(uint *)&opp_obj_ptr->2_or_3;
        pkgtoCurrentEngineObject->iParam2 =
             (&INT_0041f130)[*(uint *)&pkgtoCurrentEngineObject->2_or_3 & 1] + -1;
        iRpUnkParam2Val = (&INT_0041f130)[uVar10 & 1] + 1;
      }
      else {
        uVar10 = *(uint *)&opp_obj_ptr->2_or_3;
        pkgtoCurrentEngineObject->iParam2 =
             (&INT_0041f130)[*(uint *)&pkgtoCurrentEngineObject->2_or_3 & 1] + 1;
        iRpUnkParam2Val = (&INT_0041f130)[uVar10 & 1] + -1;
      }
      iRpPlayerLookingRight = pkgtoCurrentEngineObject->iPlayerLookingRight;
      opp_obj_ptr->iParam2 = iRpUnkParam2Val;
      if ((iRpPlayerLookingRight & 1) == 0) {
                    /* Move X value */
        opp_obj_ptr->iParam3 =
             *(short *)&skill->field_0x4 * 0x10000 + pkgtoCurrentEngineObject->iParam3;
        if ((iRpFlags & 4) == 0) goto LAB_004130e8;
        opp_obj_ptr->iPlayerLookingRight = 0;
      }
      else {
        opp_obj_ptr->iParam3 =
             pkgtoCurrentEngineObject->iParam3 + *(short *)&skill->field_0x4 * -0x10000;
        if ((iRpFlags & 4) == 0) {
          opp_obj_ptr->iPlayerLookingRight = 0;
        }
        else {
LAB_004130e8:
          opp_obj_ptr->iPlayerLookingRight = 1;
        }
      }
                    /* Move Y pos */
      opp_obj_ptr->iParam4 =
           *(short *)&skill->field_0x6 * 0x10000 + pkgtoCurrentEngineObject->iParam4;
      vMemzeroHitboxArrays(pkgtoCurrentEngineObject);
      pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
      if (opp_obj_ptr->iObjectType != PLAYER_ENGINE_OBJECT)
      goto switchD_00412610_advance_skillscript;
      if ((byte)skill->field_0x2 != 0) {
                    /* Lands at start of hit_junction_info */
        opp_obj_ptr->iHitJunctionIdx =
             (uint)*(ushort *)
                    (opp_obj_ptr->iPlayerIdx * 0xe03f + 0x4d8b2a + (uint)(byte)skill->field_0x2 *  4)
        ;
      }
      pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
      pkVar12 = opp_obj_ptr->obj_ptr_b;
      *(undefined4 *)&opp_obj_ptr->iOpponentDowntimeInFrames = 0;
      kgtTargetStructure->field6442_0xdfef = 0;
      opp_obj_ptr->obj_ptr_b = (kgtEngineObject *)((uint)pkVar12 & 0xfffffffa | 10);
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
           *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
      goto LAB_004125ae;
    case '\x15':
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
      GC_player_buffer = pkgtoCurrentEngineObject->iPlayerIdx;
      GC_life_opp = *(short *)&skill->field_0x6;
      if (*(short *)&skill->field_0x2 != 0) {
        vAddToHealth(gkgtLoadedCharacter + GC_player_buffer,(int)*(short *)&skill->field_0x2);
        pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
      }
      vAddToSpecialGauge(pkgtoCurrentEngineObject->iPlayerIdx,(int)*(short *)&skill->field_0x4);
      pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
      if (gkgtLoadedCharacter[GC_player_buffer].poss_opponent_obj_ptr == (kgtEngineObject *)0x0)  {
        if (gkgtLoadedCharacter[GC_player_buffer].poss_opponent_obj_ptr_2? == (kgtEngineObject * )0x0
           ) goto switchD_00412610_advance_skillscript;
        iCurrentStoryStep =
             (gkgtLoadedCharacter[GC_player_buffer].poss_opponent_obj_ptr_2?)->iPlayerIdx;
      }
      else {
        iCurrentStoryStep =
             (gkgtLoadedCharacter[GC_player_buffer].poss_opponent_obj_ptr)->iPlayerIdx;
      }
      if (gkgtLoadedCharacter + iCurrentStoryStep != (kgt_character_struct *)0x0) {
        if (GC_life_opp != 0) {
          vAddToHealth(gkgtLoadedCharacter + iCurrentStoryStep,(int)GC_life_opp);
        }
        vAddToSpecialGauge((gkgtLoadedCharacter[iCurrentStoryStep].pkgtoSelf)->iPlayerIdx,
                           (int)*(short *)&skill->field_0x8);
        pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
      }
      goto switchD_00412610_advance_skillscript;
    case '\x16':
                    /* ----------------------------------
                       - DB - Cond. Branching
                       ----------------------------------
                       0 - Type
                       1 - If fail (otherwise, Formed)
                       2 - Skill ID (low, UNSIGNED)
                       3 - Skill ID (high, UNSIGNED)
                       4 - Skill Step
                       5 - unk
                       6 - unk
                       7 - Setting
                       
                       - Conditions -
                       0 - "its not"
                       1 - Guarding
                       2 - Standing
                       3 - Crouching
                       4 - If Forward is tapped
                       5 - If Back is tapped
                       6 - If Up is tapped
                       7 - IF Down is tapped */
      bisIfFailed = skill->field_0x1 & 1;
      if ((skill->field_0x1 & 2) != 0) goto switchD_00412de4_default;
      db_player_buffer = pkgtoCurrentEngineObject->iPlayerIdx;
      DB_input = giInputBufferA[db_player_buffer][giInputBufferPos];
      switch(skill->field_0x7) {
      case 1:
        if (pkgtoCurrentEngineObject->iParam4 < pkgtoCurrentEngineObject->compare_to_param_4) br eak;
        goto LAB_00412e5f;
      case 2:
        if (pkgtoCurrentEngineObject->compare_to_param_4 <= pkgtoCurrentEngineObject->iParam4) {
          uVar10 = DB_input & 8;
          goto joined_r0x00412e5d;
        }
        break;
      case 3:
        if (pkgtoCurrentEngineObject->compare_to_param_4 <= pkgtoCurrentEngineObject->iParam4)
        goto switchD_00412de4_caseD_7;
        break;
      case 4:
        if (((gkgtLoadedCharacter[db_player_buffer].cIsGuardButtonActive & 8) == 0) ||
           (pkgtoCurrentEngineObject->iPlayerLookingRight == 0)) {
LAB_00412e4c:
          uVar10 = DB_input & 2;
          goto joined_r0x00412e56;
        }
        goto LAB_00412e2f;
      case 5:
        if (((gkgtLoadedCharacter[db_player_buffer].cIsGuardButtonActive & 8) != 0) &&
           (pkgtoCurrentEngineObject->iPlayerLookingRight != 0)) goto LAB_00412e4c;
LAB_00412e2f:
        uVar10 = DB_input & 1;
joined_r0x00412e32:
        if (uVar10 == 0) break;
LAB_00412e5f:
        if (bisIfFailed == 0) goto LAB_00412e79;
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
      if (bisIfFailed == 0) goto switchD_00412610_advance_skillscript;
LAB_00412e79:
      if (*(ushort *)&skill->field_0x2 == 0) goto switchD_00412610_advance_skillscript;
      uVar10 = (uint)*(ushort *)&skill->field_0x2;
      pkgtoCurrentEngineObject->iSkillIdx = uVar10;
LAB_004135bf:
      iCurrentStoryStep =
           ((ushort)(kgtTargetStructure->kgtCore).pSkillsAlloc[uVar10].shStartingStepIdx - 1) +
           (uint)(byte)skill->field_0x4;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx = iCurrentStoryStep;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx = iCurrentStoryStep + 1;
      goto LAB_004125ae;
    case '\x17':
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
      pkgtoCurrentEngineObject->reaction_skillblock = skill;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
           *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
      goto LAB_004125ae;
    case '\x18':
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
      FA_m_number = pkgtoCurrentEngineObject->kgtHitboxAttacks + (byte)skill->field_0x9;
      *FA_m_number = (int)skill;
      if ((FA_width == 0) || (*(short *)&skill->field_0x7 == 0)) goto LAB_00412d83;
      if (pkgtoCurrentEngineObject->iObjectType != PLAYER_ENGINE_OBJECT)
      goto switchD_00412610_advance_skillscript;
      FA_flags = skill->field_0xa;
      if ((FA_flags & 1) == 0) {
        kgtTargetStructure->iCurrentActionCancellableFlag = 0;
      }
      else {
        kgtTargetStructure->iCurrentActionCancellableFlag = 1;
      }
      if ((FA_flags & 2) == 0) goto switchD_00412610_advance_skillscript;
      pkgtoCurrentEngineObject->obj_ptr_b =
           (kgtEngineObject *)((uint)pkgtoCurrentEngineObject->obj_ptr_b & 0xffffffef);
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
           *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
      goto LAB_004125ae;
    case '\x19':
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
      FA_m_number = pkgtoCurrentEngineObject->hitbox_guard_array + (byte)skill->field_0x9;
      *FA_m_number = (int)skill;
      if ((sVar2 != 0) && (*(short *)&skill->field_0x7 != 0))
      goto switchD_00412610_advance_skillscript;
LAB_00412d83:
      *FA_m_number = 0;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
           *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
      goto LAB_004125ae;
    case '\x1a':
                    /* ----------------------------------
                       - PS - Player: Stop
                       ----------------------------------
                       0 - Type
                       1 - Your Down Time (UNSIGNED)
                       2 - Part Down Time (UNSIGNED) */
      if ((pkgtoCurrentEngineObject->iObjectType == PLAYER_ENGINE_OBJECT) &&
         (player_down_time = skill->field_0x1, player_down_time != 0)) {
        *(uint *)&pkgtoCurrentEngineObject->iOpponentDowntimeInFrames =
             *(int *)&pkgtoCurrentEngineObject->iOpponentDowntimeInFrames + (uint)player_down_tim e;
        PS_player_buffer = pkgtoCurrentEngineObject->iPlayerIdx;
        *(int *)&gkgtLoadedCharacter[PS_player_buffer].input_storage =
             giInputBufferA[PS_player_buffer][giInputBufferPos];
        gkgtLoadedCharacter[PS_player_buffer].field6452_0xdfff = 1;
        PS_obj = &kgtEngineObjects[0].iOpponentDowntimeInFrames;
        ps_i = 0x400;
        do {
          if (((ADJ(PS_obj).iJumpIdx == READ_SCRIPT) &&
              (ADJ(PS_obj)->iPlayerIdx == PS_player_buffer)) &&
             ((ADJ(PS_obj)->unk_bitmask & 0x20000000) != 0)) {
            *(uint *)PS_obj = *(int *)PS_obj + (uint)player_down_time;
          }
          PS_obj = PS_obj + 0x17e;
          ps_i = ps_i + -1;
        } while (ps_i != 0);
      }
      PS_opponent_down_time = skill->field_0x2;
      if (PS_opponent_down_time == 0) goto switchD_00412610_advance_skillscript;
      ps_i2 = 0;
      PS_players = &gkgtLoadedCharacter[0].pkgtoSelf;
      do {
        if ((ps_i2 != pkgtoCurrentEngineObject->iPlayerIdx) &&
           (ADJ(PS_players)->unknown_online_var_a != 0)) {
          PS_player_cpu = (int)ADJ(PS_players)->pkgtoSelf;
          ps_i3 = 0x400;
          *(uint *)(PS_player_cpu + 0x40) =
               *(int *)(PS_player_cpu + 0x40) + (uint)PS_opponent_down_time;
          *(int *)&ADJ(PS_players)->input_storage =
               giInputBufferA[*(int *)(PS_player_cpu + 0x156)][giInputBufferPos];
          ADJ(PS_players)->field6452_0xdfff = 1;
          iColorIntOtherPlayer = (int *)&kgtEngineObjects[0].iOpponentDowntimeInFrames;
          do {
            if (((iColorIntOtherPlayer[-0x10] == 4) &&
                (*(int *)((int)iColorIntOtherPlayer + 0x116) ==
                 ADJ(PS_players)->pkgtoSelf->iPlayerIdx)) &&
               ((iColorIntOtherPlayer[-6] & 0x20000000U) != 0)) {
              *iColorIntOtherPlayer = *iColorIntOtherPlayer + (uint)PS_opponent_down_time;
            }
            iColorIntOtherPlayer = (int *)((int)iColorIntOtherPlayer + 0x17e);
            ps_i3 = ps_i3 + -1;
          } while (ps_i3 != 0);
        }
        PS_players = (kgt_character_struct_ptr_57077_int)((int)PS_players + 0xe03f);
        ps_i2 = ps_i2 + 1;
      } while ((int)PS_players < 0x54fe6d);
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
           *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
      goto LAB_004125ae;
    case '\x1e':
                    /* ----------------------------------
                       - C - Cancel Cond. -
                       ----------------------------------
                       0 - Type
                       1 - Cancel, flags
                       2 - Level empty (UNSIGNED)
                       3 - Skill ID mod 255 (remainder, UNSIGNED)
                       4 - Skill ID mod 255 (division amount, UNSIGNED)
                       5 - Level ween (UNSIGNED)
                       
                       Skill ID mod 255 remainder + Skill ID mod 255 * 255 = Actual Skill ID
                       
                       - Cancels -
                       +0x00 - Fail
                       +0x01 - Hit
                       +0x02 - UnCond
                       +0x08 - Cancel condition is skill (otherwise is level)
                       
                       - Flags -
                       0 - CANCEL_MASK 
                       1 - CANCEL_MASK
                       2 - CANCEL_MASK
                       3 - Skill */
      cancel_flags = skill->field_0x1;
      cancel_empty = skill->field_0x2;
      cancel_skill_idx = skill->field_0x3;
      uVar7 = skill->field_0x4;
      uVar8 = skill->field_0x5;
      kgtTargetStructure->start_of_0x6 = skill->cSkillType;
      kgtTargetStructure->CancelSkillBlockFlags = cancel_flags;
      kgtTargetStructure->CancelSkillBlockEmpty = cancel_empty;
      kgtTargetStructure->CancelSkillIdxMod255Remainder = cancel_skill_idx;
      kgtTargetStructure->CancelSkillBlock255DivisionAmount = uVar7;
      kgtTargetStructure->CancelSkillBlockLevelWeen = uVar8;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
           *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
      goto LAB_004125ae;
    case '\x1f':
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
        char_i = (short *)((int)pkgtoCurrentEngineObject->hitbox_guard_array +
                          (var_LHS_long & 0x3f) * 2 + 0x58);
      }
      else if (var_lhs == 1) {
        char_i = (short *)((int)kgtTargetStructure->object_mNumbers +
                          (var_LHS_long & 0x3f) * 2 + -0x28);
      }
      else if (var_lhs == 2) {
        char_i = (short *)(&SYSTEM_VARIABLES + (var_LHS_long & 0x3f) * 2);
      }
      var_flags = skill->field_0x5;
      if ((var_flags & 0x80) == 0) {
        local_11c = (uint)*(ushort *)&skill->field_0x7;
        goto switchD_0041380c_default;
      }
      cLifeRecovery = skill->field_0x6;
      switch(cLifeRecovery >> 6) {
      case 0:
        local_11c = (uint)*(ushort *)
                           ((int)pkgtoCurrentEngineObject->hitbox_guard_array +
                           (cLifeRecovery & 0x3f) * 2 + 0x58);
        break;
      case 1:
        local_11c = (uint)*(ushort *)
                           ((int)kgtTargetStructure->object_mNumbers +
                           (cLifeRecovery & 0x3f) * 2 + -0x28);
        break;
      case 2:
        local_11c = (uint)*(ushort *)(&SYSTEM_VARIABLES + (cLifeRecovery & 0x3f) * 2);
        break;
      case 3:
        switch(cLifeRecovery & 0x3f) {
        case 0:
          iCurrentStoryStep = pkgtoCurrentEngineObject->iParam3;
          goto LAB_00413865;
        case 1:
          iCurrentStoryStep = pkgtoCurrentEngineObject->iParam4;
          goto LAB_00413865;
        case 2:
          local_11c = unk_x_position;
          break;
        case 3:
          local_11c = unk_y_pos2;
          break;
        case 4:
          iCurrentStoryStep = pkgtoCurrentEngineObject->parent_obj->iParam3;
          goto LAB_00413865;
        case 5:
          iCurrentStoryStep = pkgtoCurrentEngineObject->parent_obj->iParam4;
LAB_00413865:
          local_11c = (int)((iCurrentStoryStep >> 0x1f & 0xffffU) + iCurrentStoryStep) >> 0x10;
          break;
        case 6:
          local_11c = gkgtGameState.iGameTimerInFrames / 100;
          break;
        case 7:
          local_11c = gkgtGameState.iCurrentRound;
        }
      }
switchD_0041380c_default:
      if ((var_flags & 3) == 1) {
        *char_i = (short)local_11c;
      }
      else if ((var_flags & 3) == 2) {
        iCurrentStoryStep = (int)*char_i + (int)(short)local_11c;
        if (iCurrentStoryStep < -30000) {
          *char_i = -30000;
        }
        else {
          if (30000 < iCurrentStoryStep) {
            iCurrentStoryStep = 30000;
          }
          *char_i = (short)iCurrentStoryStep;
        }
      }
      cLifeRecovery = var_flags >> 2 & 3;
      if (cLifeRecovery == 1) {
        if (*char_i != *(short *)&skill->field_0x9) goto switchD_00412610_advance_skillscript;
      }
      else if (cLifeRecovery == 2) {
        if (*char_i <= *(short *)&skill->field_0x9) goto switchD_00412610_advance_skillscript;
      }
      else if ((cLifeRecovery != 3) || (*(short *)&skill->field_0x9 <= *char_i))
      goto switchD_00412610_advance_skillscript;
      uVar4 = *(ushort *)&skill->field_0x1;
      if (uVar4 == 0) goto switchD_00412610_advance_skillscript;
      pSkillsAlloc = (kgtTargetStructure->kgtCore).pSkillsAlloc;
      pkgtoCurrentEngineObject->iSkillIdx = (uint)uVar4;
      iCurrentStoryStep =
           ((ushort)pSkillsAlloc[uVar4].shStartingStepIdx - 1) + (uint)(byte)skill->field_0x3;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx = iCurrentStoryStep;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx = iCurrentStoryStep + 1;
      goto LAB_004125ae;
    case ' ':
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
      pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
      if ((rand % (int)(*(ushort *)&skill->field_0x1 + 1) <= (int)(uint)*(ushort *)&skill->field_ 0x3
          ) || (uVar4 = *(ushort *)&skill->field_0x6, uVar4 == 0))
      goto switchD_00412610_advance_skillscript;
      pSkillsAlloc = (kgtTargetStructure->kgtCore).pSkillsAlloc;
      gpkgtCurrentEngineObject->iSkillIdx = (uint)uVar4;
      random_skillcommand =
           ((ushort)pSkillsAlloc[uVar4].shStartingStepIdx - 1) + (uint)(byte)skill->field_0x8;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx = random_skillcommand;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx = random_skillcommand + 1;
      goto LAB_004125ae;
    case '#':
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
      bCarryOver = skill->field_0x2;
      cVar1 = skill->field_0x3;
      *(uint *)&pkgtoCurrentEngineObject->iColorBlendtype = (uint)(byte)skill->field_0x1;
      pkgtoCurrentEngineObject->iColorRed = (int)bCarryOver;
      bCarryOver = skill->field_0x4;
      pkgtoCurrentEngineObject->iColorGreen = (int)cVar1;
      pkgtoCurrentEngineObject->iColorBlue = (int)bCarryOver;
      if (*(int *)&pkgtoCurrentEngineObject->iColorBlendtype == 4) {
        *(int *)&pkgtoCurrentEngineObject->color_alpha = (int)(char)skill->field_0x5;
        *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
             *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
      }
      else {
        *(undefined4 *)&pkgtoCurrentEngineObject->color_alpha = 0;
        *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
             *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
      }
      goto LAB_004125ae;
    case '$':
                    /* ----------------------------------
                       - COM - Command input -
                       ----------------------------------
                       0 - Type (0x24)
                       1 - Skill ID (low, UNSIGNED)
                       2 - Skill ID (low, UNSIGNED)
                       3 - Skill Step ID (UNSIGNED)
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
                       
                       - Inputs -
                       No input - +0x0
                       Numpad 5 - +0x1 
                       Numpad 6 - +0x2
                       Numpad 3 - +0x3
                       Numpad 2 - +0x4
                       Numpad 1 - +0x5
                       Numpad 4 - +0x6
                       Numpad 7 - +0x7
                       Numpad 8 - +0x8
                       Numpad 9 - +0x9
                       Numpad 7/4/1 - +0xA
                       Numpad 7/8/9 - +0xB
                       Numpad 9/6/3 - +0xC
                       Numpad 1/2/3 - +0xD
                       A - +0x10
                       B - +0x20
                       C - +0x40
                       D - +0x80
                       E - +0x1 (high bit)
                       F - +0x2 (high bit)
                       
                       End flags
                       -------
                       Inactive - +0x10 (high bit)
                       End command - +0x20 (high bit)
                       Continue past this command - +0x30 (high bit) */
      iCurrentStoryStep = process_COM_skillblock(skill);
      pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
      if (iCurrentStoryStep == 0) goto switchD_00412610_advance_skillscript;
      COM_skill_idx = *(ushort *)&skill->field_0x1;
      gpkgtCurrentEngineObject->iSkillIdx = (uint)COM_skill_idx;
      COM_new_skillscript_idx =
           ((ushort)(kgtTargetStructure->kgtCore).pSkillsAlloc[COM_skill_idx].shStartingStepIdx - 1)
           + (uint)(byte)skill->field_0x3;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx = COM_new_skillscript_idx;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx = COM_new_skillscript_idx + 1;
      goto LAB_004125ae;
    case '%':
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
      if (pkgtoCurrentEngineObject->0x650_index == 0) {
        0x650_idx = 0;
        iColorIntOtherPlayer = &DAT_00447f80;
        goto AI_0x650_is_0;
      }
      0x650_idx = (byte)pkgtoCurrentEngineObject->0x650_index - 1;
      if ((skill->field_0x3 != '\0') && (skill->field_0x4 != '\0')) goto AI_quantity_interval_not _0;
      pkgtoCurrentEngineObject->0x650_index = 0;
      iCurrentStoryStep = *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx;
      (&DAT_00447f80)[0x650_idx * 0x194] = 0;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx = iCurrentStoryStep + 1;
      goto LAB_004125ae;
    }
  }
  _sprintf(local_100,s_ScriptMainLoopError_%d_%d_-_nd:%_0041f230,
           pkgtoCurrentEngineObject->iPlayerIdx,pkgtoCurrentEngineObject->iObjectType,
           current_skill_idx,
           *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx -
           (uint)(ushort)(kgtTargetStructure->kgtCore).pSkillsAlloc[current_skill_idx + 1].
                         shStartingStepIdx);
  iSetDebugInfo(local_100,0x8080ff);
  goto switchD_0041270c_default;
  while( true ) {
    iColorIntOtherPlayer = iColorIntOtherPlayer + 0x194;
    0x650_idx = 0x650_idx + 1;
                    /* AI 0x650_index is 0 */
    if (0x46f6bf < (int)iColorIntOtherPlayer) break;
AI_0x650_is_0:
    if (*iColorIntOtherPlayer == 0) {
      (&DAT_00447f80)[0x650_idx * 0x194] = 1;
      pkgtoCurrentEngineObject->0x650_index = (char)0x650_idx + '\x01';
      break;
    }
  }
AI_quantity_interval_not_0:
                    /* AI Quantity and interval isn't 0 */
  if (0x650_idx != 100) {
    (&INT_00447f84)[0x650_idx * 0x194] = 0;
    (&INT_00447f88)[0x650_idx * 0x194] = (int)skill;
    (&INT_00447f8c)[0x650_idx * 0x194] = 0;
    iColorIntOtherPlayer = &INT_00447f90 + 0x650_idx * 0x194;
    for (iCurrentStoryStep = 400; iCurrentStoryStep != 0; iCurrentStoryStep = iCurrentStoryStep + -1
        ) {
      *iColorIntOtherPlayer = 0;
      iColorIntOtherPlayer = iColorIntOtherPlayer + 1;
    }
    *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
         *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
    goto LAB_004125ae;
  }
  iSetDebugInfo(s_HAN_KATAKANA#_0041f274,&DAT_004444ff);
  pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
  goto switchD_00412610_advance_skillscript;
  while( true ) {
    iCurrentStoryStep = iCurrentStoryStep + 1;
    pkVar12 = pkVar12 + 1;
    if (0x3ff < iCurrentStoryStep) break;
OBJECT_BLOCK_LOOP:
    if (pkVar12 == kgtTargetStructure->object_mNumbers[m_val]) {
      uVar4 = *(ushort *)&skill->field_0x5;
      if (uVar4 != 0) {
        pSkillsAlloc = (kgtTargetStructure->kgtCore).pSkillsAlloc;
        pkgtoCurrentEngineObject->iSkillIdx = (uint)uVar4;
        iCurrentStoryStep =
             ((ushort)pSkillsAlloc[uVar4].shStartingStepIdx - 1) + (uint)(byte)skill->field_0x7;
        *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx = iCurrentStoryStep;
        *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx = iCurrentStoryStep + 1;
        goto LAB_004125ae;
      }
      pkVar12->iJumpIdx = RESET_IDX;
      kgtTargetStructure->object_mNumbers[m_val] = (kgtEngineObject *)0x0;
      break;
    }
  }
LAB_00412b0a:
  if (*(ushort *)&skill->field_0x2 != 0) {
    curr_obj_type = pkgtoCurrentEngineObject->iObjectType;
    cLifeRecovery = skill->field_0x1;
    bVar11 = cLifeRecovery & 0x40;
    if (curr_obj_type == SYSTEM_ENGINE_OBJECT) {
      if (((kgtTargetStructure->kgtCore).pSkillsAlloc[*(ushort *)&skill->field_0x2].
           cDemoDefaultScriptGroup & 9U) != 0) {
        bVar11 = 0;
        goto LAB_00412b9c;
      }
LAB_00412b66:
      bVar11 = 1;
LAB_00412b6e:
      iCurrentStoryStep = (int)*(short *)&skill->field_0x8 << 0x10;
      iPlayerIdx = (int)*(short *)&skill->field_0xa << 0x10;
    }
    else {
      if (curr_obj_type == DEMO_ENGINE_OBJECT) goto LAB_00412b66;
      if (curr_obj_type != STAGE_ENGINE_OBJECT) {
        if ((cLifeRecovery & 0x40) == 0) goto LAB_00412b9c;
        goto LAB_00412b6e;
      }
      bVar11 = 0;
LAB_00412b9c:
      if ((pkgtoCurrentEngineObject->iPlayerLookingRight & 1) == 0) {
        iCurrentStoryStep =
             *(short *)&skill->field_0x8 * 0x10000 + pkgtoCurrentEngineObject->iParam3;
        iPlayerIdx = *(short *)&skill->field_0xa * 0x10000 + pkgtoCurrentEngineObject->iParam4;
      }
      else {
        iCurrentStoryStep =
             pkgtoCurrentEngineObject->iParam3 + *(short *)&skill->field_0x8 * -0x10000;
        iPlayerIdx = *(short *)&skill->field_0xa * 0x10000 + pkgtoCurrentEngineObject->iParam4;
      }
    }
    uVar10 = pkgtoCurrentEngineObject->iParam2;
    if ((cLifeRecovery & 3) == 0) {
      uVar10 = uVar10 - 1;
      if ((int)uVar10 < 10) {
        uVar10 = 10;
      }
    }
    else if ((cLifeRecovery & 3) == 1) {
      uVar10 = uVar10 + 1;
      if (0x7f < (int)uVar10) {
        uVar10 = 0x7f;
      }
    }
    else if ((cLifeRecovery & 3) == 2) {
      uVar10 = (uint)(byte)skill->field_0xd;
    }
    pkVar12 = kgtoNewEngineObject(pkgtoCurrentEngineObject->iJumpIdx,uVar10,iCurrentStoryStep,
                                  iPlayerIdx);
    pkgtoCurrentEngineObject = gpkgtCurrentEngineObject;
    pkVar12->iObjectType = STORY?_ENGINE_OBJECT;
    pkVar12->iPlayerIdx = pkgtoCurrentEngineObject->iPlayerIdx;
    switch(pkgtoCurrentEngineObject->iObjectType) {
    case PLAYER_ENGINE_OBJECT:
    case STORY?_ENGINE_OBJECT:
    case CHARACTER_ENGINE_OBJECT:
      pkVar12->iObjectType = STORY?_ENGINE_OBJECT;
      break;
    case SYSTEM_ENGINE_OBJECT:
      pkVar12->iObjectType = SYSTEM_ENGINE_OBJECT;
      break;
    case DEMO_ENGINE_OBJECT:
      pkVar12->iObjectType = DEMO_ENGINE_OBJECT;
      break;
    case STAGE_ENGINE_OBJECT:
      pkVar12->iObjectType = STAGE_ENGINE_OBJECT;
    }
    uVar6 = *(undefined3 *)&pkgtoCurrentEngineObject->field_0x15;
    iCurrentStoryStep = pkgtoCurrentEngineObject->iPlayerLookingRight;
    pkVar12->2_or_3 = pkgtoCurrentEngineObject->2_or_3;
    *(undefined3 *)&pkVar12->field_0x15 = uVar6;
    uVar4 = *(ushort *)&skill->field_0x2;
    pkVar12->iPlayerLookingRight = iCurrentStoryStep;
    pkVar12->iSkillIdx = (uint)uVar4;
    *(uint *)&pkVar12->iSkillScriptIdx =
         (uint)(ushort)(kgtTargetStructure->kgtCore).pSkillsAlloc[uVar4].shStartingStepIdx +
         (uint)(byte)skill->field_0x4;
    if (bVar11 == 0) {
      pkVar12->unk_bitmask = pkVar12->unk_bitmask | 0x40000000;
    }
    if ((int)pkgtoCurrentEngineObject->iObjectType < 2) {
      cLifeRecovery = skill->field_0x1;
      if ((cLifeRecovery & 4) == 0) {
        kgtTargetStructure->object_mNumbers[(byte)skill->field_0xc] = pkVar12;
      }
      if ((cLifeRecovery & 8) != 0) {
        pkVar12->unk_bitmask = pkVar12->unk_bitmask | 0x80000000;
      }
    }
    if ((skill->field_0x1 & 0x20) != 0) {
      *(undefined2 *)&pkVar12->field_0x12f = *(undefined2 *)&skill->field_0xa;
      pkVar12->unk_bitmask = pkVar12->unk_bitmask | 0x20000000;
      *(undefined2 *)&pkVar12->field_0x12d = *(undefined2 *)&skill->field_0x8;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
           *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
      goto LAB_004125ae;
    }
  }
switchD_00412610_advance_skillscript:
  *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
       *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
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
  if (pkgtoCurrentEngineObject->iPlayerLookingRight != 0) {
                    /* Possibly direction player is facing */
    player_ignore_flag_flag = -1;
  }
  mvmt_flags = skill->field_0x9;
  missing_x_flags_flag = (mvmt_flags & 1) == 0;
  player_x_momentum = *(short *)&skill->field_0x3 * giPlayerMomentumScalar * player_ignore_flag_f lag
  ;
  if ((mvmt_flags & 2) == 0) {
                    /* Does not have Y momentum stop flag or X gravity stop flag */
    if (missing_x_flags_flag) {
      pkgtoCurrentEngineObject->iXMomentum = player_x_momentum;
    }
    else {
      pkgtoCurrentEngineObject->iXMomentum =
           pkgtoCurrentEngineObject->iXMomentum + player_x_momentum;
    }
  }
  player_y_momentum = *(short *)&skill->field_0x5 * giPlayerMomentumScalar;
  if ((mvmt_flags & 4) == 0) {
                    /* Y gravity stop flag */
    if (missing_x_flags_flag) {
      pkgtoCurrentEngineObject->iYMomentum = player_y_momentum;
    }
    else {
      pkgtoCurrentEngineObject->iYMomentum =
           pkgtoCurrentEngineObject->iYMomentum + player_y_momentum;
    }
  }
  iCurrentStoryStep = *(short *)&skill->field_0x1 * giGravityScalar * player_ignore_flag_flag;
  if ((mvmt_flags & 8) == 0) {
    if (missing_x_flags_flag) {
      pkgtoCurrentEngineObject->iXGravity = iCurrentStoryStep;
    }
    else {
      pkgtoCurrentEngineObject->iXGravity = pkgtoCurrentEngineObject->iXGravity + iCurrentStoryS tep;
    }
  }
  iCurrentStoryStep = *(short *)&skill->field_0x7 * giGravityScalar;
  if ((mvmt_flags & 0x10) == 0) {
    if (missing_x_flags_flag) {
      pkgtoCurrentEngineObject->iYGravity = iCurrentStoryStep;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
           *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
    }
    else {
      pkgtoCurrentEngineObject->iYGravity = pkgtoCurrentEngineObject->iYGravity + iCurrentStoryS tep;
      *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx =
           *(int *)&pkgtoCurrentEngineObject->iSkillScriptIdx + 1;
    }
    goto LAB_004125ae;
  }
  goto switchD_00412610_advance_skillscript;
}

