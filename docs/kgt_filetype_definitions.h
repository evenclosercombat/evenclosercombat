typedef unsigned char   undefined;

typedef unsigned char    bool;
typedef unsigned char    byte;
typedef unsigned int    dword;
typedef unsigned long long    GUID;
typedef pointer32 ImageBaseOffset32;

typedef long long    longlong;
typedef unsigned long long    qword;
typedef int    sdword;
typedef unsigned char    uchar;
typedef unsigned int    uint;
typedef unsigned long    ulong;
typedef unsigned long long    ulonglong;
typedef unsigned char    undefined1;
typedef unsigned short    undefined2;
typedef unsigned int    undefined3;
typedef unsigned int    undefined4;
typedef unsigned long long    undefined5;
typedef unsigned long long    undefined6;
typedef unsigned long long    undefined8;
typedef unsigned short    ushort;
typedef unsigned short    wchar16;
typedef short    wchar_t;
typedef unsigned short    word;
typedef struct kgtFileCharacter kgtFileCharacter, *PkgtFileCharacter;

typedef struct kgtSkillHeader kgtSkillHeader, *PkgtSkillHeader;

typedef struct kgtSkill kgtSkill, *PkgtSkill;

typedef struct kgtImageHeader kgtImageHeader, *PkgtImageHeader;

typedef struct kgtPallette kgtPallette, *PkgtPallette;

typedef struct kgtSound kgtSound, *PkgtSound;

typedef struct kgtCharacterCommand kgtCharacterCommand, *PkgtCharacterCommand;

typedef struct kgtCharacterHitJunction kgtCharacterHitJunction, *PkgtCharacterHitJunction;

typedef struct kgtCommonImage kgtCommonImage, *PkgtCommonImage;

typedef struct kgtCpuCommand kgtCpuCommand, *PkgtCpuCommand;

typedef struct kgtStoryEntry kgtStoryEntry, *PkgtStoryEntry;

typedef struct kgtCharacterCPUCommandSkillFull kgtCharacterCPUCommandSkillFull, *PkgtCharacterCPUCommandSkillFull;

typedef struct kgtCharacterCPUCommandSkillShort kgtCharacterCPUCommandSkillShort, *PkgtCharacterCPUCommandSkillShort;

typedef struct kgtStoryEntryCpu kgtStoryEntryCpu, *PkgtStoryEntryCpu;

struct kgtSound {
    void *pAlloc;
    char sName[32];
    int iSize;
    undefined field3_0x28;
    undefined field4_0x29;
};

struct kgtPallette {
    char b;
    char g;
    char r;
    char field3_0x3; /* This is always '01' */
};

struct kgtStoryEntryCpu {
    short shBitmask; /* Right-digit: show life = +0x1, time = +0x2, life = +0x4 win pause leave = +0x20, win pause appear = +0x40, from 1st = +0x0, effect is player = +0x80 left digit: effect none = 0x0, last hit = 0x1, player ignore = +0x2 */
    undefined field1_0x2;
    undefined field2_0x3;
    char cCharacterIdx;
    char cCpuLevel;
    char cEnemyBitmask; /* player = 0x01 */
    short shStartPos;
    undefined field7_0x9;
    undefined field8_0xa;
    char cTimeMethodNumber;
    char cTimeMethodNumberRandom;
    char cLifeMethodTarget; /* 0x0 = player */
    char cLifeMethodAmount;
    char cVictoryPointsAmount;
    char cEffectLifeIncrease;
    char cEffectSpecialIncrease;
    char cVictoryPointsTarget; /* 0x0 = last attacker, 0x1 = player */
    char cWhenTimeTarget; /* 0x0 = player */
    undefined field18_0x14;
    char cWhenTimeNumber;
    undefined field20_0x16;
    undefined field21_0x17;
    undefined field22_0x18;
    char end_of_story_character_entry;
};

struct kgtStoryEntry {
    char cStoryType; /* 1 = Fight, 2 = Demo, 3 = Jump/Divergence, 4 = End */
    char cStageIdx; /* For demo entries, this chooses demo. For divergance entries, this chooses divergance type. 00 = not, 01 = front stage, 02 = life gauge based, 03 = winning all the fight */
    char cRoundsAmount; /* For divergence, this is the health for divergence type 02. */
    char bFirstLifeCarryOver;
    char cLifeRecovery;
    char cWhenDefeatAndFirstRoundBitmask; /* For divergence, this is 'appointment', to indicate how many entries to jump. For fight, +0x01 = game over, +0x02 = carry_over */
    short shTime;
    short shPlayerStartXPos;
    undefined field8_0xa;
    undefined field9_0xb;
    char cOptionsBitmask; /* show round # = 0x01, fighting spirit indicate = 0x02, WALL = 0x04 */
    undefined field11_0xd;
    undefined field12_0xe;
    undefined field13_0xf;
    char cWhenTimeOver; /* 0 = cpu1... */
    char cWhenTimeOverNumber;
    char cCpuWins; /* 2 = cpu1... 1 = player, 0 = character who hit last */
    char cCpuWinsNumber;
    undefined field18_0x14;
    undefined field19_0x15;
    undefined field20_0x16;
    undefined field21_0x17;
    struct kgtStoryEntryCpu kgtStoryEntryCPUs[7];
};

struct kgtCommonImage {
    short shE_Number;
    short shX_Movement;
    short shY_Movement;
};

struct kgtCharacterHitJunction {
    short shAllottmentIdx;
    short shSparkIdx;
};

struct kgtSkill {
    char cSkillType; /* 00 = start of new skill, 0B = SC, 19 = FD, 0C = I */
    undefined field1_0x1;
    undefined field2_0x2;
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

struct kgtCharacterCommand {
    char sName[30];
    undefined field1_0x1e;
    undefined field2_0x1f;
    short shCommandTimeMilliseconds;
    short shAirCommandSet;
    short shStandNearCommandSet;
    short shStandFarCommandSet;
    short shCrouchedCommandSet;
    short shCommandInputs[10]; /* Byte 1: Right digit: Arrow - 0 for 'free', 1 for dot, 09 for up right, 0A-0D for multi-arrows starting at left.   Leftt-digit: Buttons A through D are stored in the left digit, bitmask-style. Byte 2: Left-digit -  Continue to next input = +0x30 End at this input = +0x20 No repeat/hold/black button = +0x00 Repeat = +0x40 Hold = +0x80 Black = +0xC0  Right-digit: Buttons E (binary 1) and F (binary 2) */
    short shCommandInputTimings[10];
};

struct kgtImageHeader {
    int *pAlloc;
    int iHeight;
    int iWidth;
    int unk;
    int iSize;
};

struct kgtCharacterCPUCommandSkillFull {
    char directional; /* starts at 1 = no direction, continues starting at right, ending at up-right */
    char continue_flag; /* 30 = go to next skill, 20 = end skill, 10 = inactive? unsure. */
    short skill_idx;
    short skill_timing;
    undefined field4_0x6;
};

struct kgtCharacterCPUCommandSkillShort {
    char last_cpu_command_directional; /* The final CPU command is one byte less? */
    char last_cpu_command_continute_flag;
    short last_cpu_command_directional_skill_idx;
    short last_cpu_command_directional_skill_timing;
};

struct kgtCpuCommand {
    char sName[30];
    undefined field1_0x1e;
    undefined field2_0x1f;
    char cIsFighterAirborneBitmask; /* 1 = Character in air, 2 = Enemy in air, 3 = both? */
    char cProbability;
    short shIntervalEmpty;
    short shIntervalInside;
    undefined field7_0x26;
    undefined field8_0x27;
    undefined field9_0x28;
    undefined field10_0x29;
    struct kgtCharacterCPUCommandSkillFull kgtCharacterCPUCommandSkill_1;
    struct kgtCharacterCPUCommandSkillFull kgtCharacterCPUCommandSkill_2;
    struct kgtCharacterCPUCommandSkillFull kgtCharacterCPUCommandSkill_3;
    struct kgtCharacterCPUCommandSkillFull kgtCharacterCPUCommandSkill_4;
    struct kgtCharacterCPUCommandSkillFull kgtCharacterCPUCommandSkill_5;
    struct kgtCharacterCPUCommandSkillFull kgtCharacterCPUCommandSkill_6;
    struct kgtCharacterCPUCommandSkillFull kgtCharacterCPUCommandSkill_7;
    struct kgtCharacterCPUCommandSkillFull kgtCharacterCPUCommandSkill_8;
    struct kgtCharacterCPUCommandSkillFull kgtCharacterCPUCommandSkill_9;
    struct kgtCharacterCPUCommandSkillShort kgtCharacterCPUCommandSkill_A; /* Finaly CPU command is one byte shorter than the rest. */
};

struct kgtSkillHeader {
    char cName[32];
    short shStartingStepIdx;
    undefined field2_0x22;
    undefined field3_0x23;
    char cDefaultScriptGroup; /* Used for skills that are required by the engine/built-in by default. */
    undefined field5_0x25;
    undefined field6_0x26;
};

struct kgtFileCharacter {
    char sHeaderStart[12];
    int iActionsLoadedFlag;
    char sName[256];
    int iSkillHeaderCount;
    struct kgtSkillHeader kgtSkillHeaders[1023];
    char too_many_skills_check; /* Not an actual variable */
    byte field6_0x9cee[31];
    char iSkillStepsOverallCount_redundant;
    byte field8_0x9d0e[6];
    int iSkillStepOverallCount;
    struct kgtSkill kgtSkillSteps[65536];
    int iImageStructCount; /* Always 8192 */
    struct kgtImageHeader kgtImageHeaders[8192];
    struct kgtPallette kgtPalletteA[256];
    struct kgtPallette kgtPalletteB[256];
    struct kgtPallette kgtPalletteC[256];
    struct kgtPallette kgtPalletteD[256];
    struct kgtPallette kgtPalletteE[256];
    struct kgtPallette kgtPalletteF[256];
    struct kgtPallette kgtPalletteG[256];
    struct kgtPallette kgtPalletteH[256];
    struct kgtPallette kgtPalletteExtra[64];
    int iSoundCount;
    struct kgtSound kgtSounds[256];
    int four_zeros; /* Not an actual variable */
    int iCommandStructArrayCount;
    struct kgtCharacterCommand kgtCharacterCommands[100];
    int iHitJunctionCount;
    struct kgtCharacterHitJunction kgtHitJunctions[200];
    int iCommonImagesCount;
    struct kgtCommonImage kgtCommonImages[200];
    struct kgtCpuCommand kgtCpuCommands[100];
    short shSkillIdxStanding; /* Beginning of default engine skill indexes */
    short shSkillIdxForward;
    short shSkillIdxBackward;
    short shSkillIdxJumpUp;
    short shSkillIdxFrontJump;
    short shSkillIdxBackJump;
    short shSkillIdxFalling;
    short shSkillIdxMidCrouch;
    short shSkillIdxCrouching;
    short shSkillIdxStandFromCrouch;
    short shSkillIdxCrouchAdvance;
    short shSkillIdxCrouchRetreat;
    short shSkillIdxTurnStanding;
    short shSkillIdxTurnCrouching;
    short shSkillIdxButtonGuardStand;
    short shSkillIdxButtonGuardCrouch;
    short shSkillIdxButtonGuardAir;
    short shSkillIdxStart;
    short shSkillIdxVictory;
    short shSkillIdxLoss;
    short shSkillIdxDraw;
    short shSkillIdxCharSelectPic;
    short shSkillIdxStageFacePic;
    short shSkillIdxRI;
    byte field56_0x13bb94[38];
    short shAge;
    undefined field58_0x13bbbc;
    undefined field59_0x13bbbd;
    char cGender; /* 00 = male, 01 = female, 02 = both, 03 = none */
    byte field61_0x13bbbf[1740];
    short shYPosOfSideHp;
    short shInterv;
    char cShaveRatio;
    char cLifeRevYStartPos;
    char cLifeRevCorrection;
    char cCharacterRev;
    char cGuardButton; /* 00 = A, 05 = F */
    short shLifeGuageMax;
    undefined field70_0x13c296;
    undefined field71_0x13c297;
    short shSpecialGuageStockMax;
    undefined field73_0x13c29a;
    undefined field74_0x13c29b;
    short shSpecialStockMax;
    undefined field76_0x13c29e;
    undefined field77_0x13c29f;
    char cIsGuardButtonActive; /* 00 = false, 08 = true */
    byte field79_0x13c2a1[7];
    short shSpecialGuageIncreaseOnAttack;
    short shSpecialGuageIncreaseOnHit;
    char cStartingStock;
    byte field83_0x13c2ad[6];
    struct kgtStoryEntry kgtStoryEntries[100];
    byte field85_0x14132b[4534];
};

typedef struct kgtFileDemo kgtFileDemo, *PkgtFileDemo;

struct kgtFileDemo {
    char sHeaderStart[12];
    int iLoadedFlag;
    char sName[256];
    struct kgtSkillHeader kgtSkillHeaders[1023];
    char too_many_skills_check;
    byte field5_0x9cea[31];
    char cSkillStepsCount_redundant;
    byte field7_0x9d0a[6];
    int iSkillStepsCount;
    struct kgtSkill kgtSkillSteps[65536];
    int iImagesCount; /* Always 8192 */
    struct kgtImageHeader kgtImageHeaders[8192];
    struct kgtPallette kgtPalletteA[256];
    struct kgtPallette kgtPalletteB[256];
    struct kgtPallette kgtPalletteC[256];
    struct kgtPallette kgtPalletteD[256];
    struct kgtPallette kgtPalletteE[256];
    struct kgtPallette kgtPalletteF[256];
    struct kgtPallette kgtPalletteG[256];
    struct kgtPallette kgtPallletteH[256];
    struct kgtPallette kgtPalletteExtra[64];
    int iSoundCount;
    struct kgtSound kgtSounds[256];
    int four_zeros;
    char cBGM;
    char bSkipWithInput;
    undefined field26_0x136822;
    undefined field27_0x136823;
    int iTime;
    byte field29_0x136828[1025];
};

typedef struct kgtFileStage kgtFileStage, *PkgtFileStage;

struct kgtFileStage {
    char sHeaderStart[12];
    int iLoadedFlag;
    char sName[256];
    struct kgtSkillHeader kgtSkillHeaders[1023];
    char too_many_skills_check;
    byte field5_0x9cea[31];
    char cSkillStepsCount_redundant;
    byte field7_0x9d0a[6];
    int iSkillStepsCount;
    struct kgtSkill kgtSkillSteps[65536];
    int iImagesCount; /* Always 8192 */
    struct kgtImageHeader kgtImageHeaders[8192];
    struct kgtPallette kgtPalletteA[256];
    struct kgtPallette kgtPalletteB[256];
    struct kgtPallette kgtPalletteC[256];
    struct kgtPallette kgtPalletteD[256];
    struct kgtPallette kgtPalletteE[256];
    struct kgtPallette kgtPalletteF[256];
    struct kgtPallette kgtPalletteG[256];
    struct kgtPallette kgtPallletteH[256];
    struct kgtPallette kgtPalletteExtra[64];
    int iSoundCount;
    struct kgtSound kgtSounds[256];
    int four_zeros;
    char cBGM;
    char bSkipWithInput;
    byte field26_0x136822[1031];
};

typedef struct kgtFileSystem kgtFileSystem, *PkgtFileSystem;

typedef struct kgtSystemHitJunction kgtSystemHitJunction, *PkgtSystemHitJunction;

struct kgtSystemHitJunction {
    char sName[30];
    undefined field1_0x1e;
    undefined field2_0x1f;
    char cDoing;
    undefined field4_0x21;
    undefined field5_0x22;
    undefined field6_0x23;
};

struct kgtFileSystem {
    char sHeaderStart[12];
    int iLoadedFlag;
    char cName[256];
    int iSkillHeaderCount;
    struct kgtSkillHeader kgtSkillHeaders[1023]; /* Actual size written is (skill_info_amount+1)*0x27, which includes the following 0x27 bytes */
    char too_many_skills_check;
    byte unk_or_empty_a[31];
    char cSkillStepsCount_Redundant;
    byte unk_or_empty_b[6];
    int iSkillStepsCount; /* Written twice, probably by accident */
    struct kgtSkill kgtSkillSteps[65536]; /* Skill_steps_array_amount_int*0x10 is the actual size written */
    int iImageHeaderCount; /* Always going to be "8192" */
    struct kgtImageHeader kgtImageHeaders[8192]; /* image of size 'size' will always be written after each image_struct */
    struct kgtPallette kgtPalletteA[256];
    struct kgtPallette kgtPalletteB[256];
    struct kgtPallette kgtPalletteC[256];
    struct kgtPallette kgtPalletteD[256];
    struct kgtPallette kgtPalletteE[256];
    struct kgtPallette kgtPalletteF[256];
    struct kgtPallette kgtPalletteG[256];
    struct kgtPallette kgtPalletteH[256];
    struct kgtPallette kgtPalletteExtras[64];
    int iSoundCount;
    struct kgtSound kgtSounds[256]; /* actual sound of size 'size' is written after each sound_struct */
    int four_zeros; /* acts as a buffer between areas that are written for all kgt filetypes and specific areas */
    char sCharacterNames[50][256];
    struct kgtSystemHitJunction kgtHitJunctions[200];
    char cUnknown0x2; /* default value is 2, currently marked as char */
    undefined field28_0x13b645;
    undefined field29_0x13b646;
    undefined field30_0x13b647;
    undefined field31_0x13b648;
    char cStiffTimeHit;
    char cStiffTimeGuard;
    char cStiffTimeOffset;
    char sStageNames[50][256];
    char sDemoNames[50][256];
    byte field37_0x141a4c[12800];
    char cTitleDemoIdx;
    char c1pDemoIdx;
    char cVsSingleDemoIdx;
    char cVsTeamDemoIdx;
    char cGameOverDemoIdx;
    char cOpeningDemoIdx;
    char default_0x18_char; /* default value is 0x18, marked as char */
    char default_0x19_char; /* default value is 0x19, marked as char */
    char cSystemBitmask; /* editor won't read file = +0x1, offset = +0x02, story mode +0x04, vs mode +0x08, vs team mode +0x10, numbers shown on life +0x20, cursor stays +0x40 */
    undefined field47_0x144c55;
    undefined field48_0x144c56;
    undefined field49_0x144c57;
    char sCommonImages[200][32];
    short shSkillIdxNone; /* Following are the indexes in the skill info list for the required KGT skills Not always referenced, which leads to some glitches. */
    short shSkillIdxHitLetterHit;
    short shSkillIdxHitNumber0;
    short shSkillIdxHitNumber1;
    short shSkillIdxHitNumber2;
    short shSkillIdxHitNumber3;
    short shSkillIdxHitNumber4;
    short shSkillIdxHitNumber5;
    short shSkillIdxHitNumber6;
    short shSkillIdxHitNumber7;
    short shSkillIdxHitNumber8;
    short shSkillIdxHitNumber9;
    short shSkillIdxOffsetHitMark;
    short shSkillIdxRoundAniStarttime;
    short shSkillIdxRoundAniEndtime;
    short shSkillIdxRound1;
    short shSkillIdxRound2;
    short shSkillIdxRound3;
    short shSkillIdxRound4;
    short shSkillIdxRound5;
    short shSkillIdxRound6;
    short shSkillIdxRound7;
    short shSkillIdxRound8;
    short shSkillIdxRound9;
    short shSkillIdxRoundFinal;
    short shSkillIdxSpirits;
    short shSkillIdxKO;
    short shSkillIdxPerfect;
    short shSkillIdxYouWin;
    short shSkillIdxYouLose;
    short shSkillIdx1pWins;
    short shSkillIdx2pWins;
    short shSkillIdxDraw;
    short shSkillIdxDoubleKo;
    short shSkillIdxUnlimitedSign;
    short shSkillIdxTimeNumber0;
    short shSkillIdxTimeNumber1;
    short shSkillIdxTimeNumber2;
    short shSkillIdxTimeNumber3;
    short shSkillIdxTimeNumber4;
    short shSkillIdxTimeNumber5;
    short shSkillIdxTimeNumber6;
    short shSkillIdxTimeNumber7;
    short shSkillIdxTimeNumber8;
    short shSkillIdxTimeNumber9;
    short shSkillIdxVictoryMarkOn;
    short shSkillIdxVictoryMarkOff;
    short shSkillIdxStageLayout1;
    short shSkillIdxStageLayout2;
    short shSkillIdxStageLayout3;
    short shSkillIdxStageLayout4;
    short shSkillIdxStageLayout5;
    short shSkillIdxStageLayout6;
    short shSkillIdxStageLayout7;
    short shSkillIdxStageLayout8;
    short shSkillIdxStageLayout9;
    short shSkillIdxStageLayout10;
    short shSkillIdx1pLifeGauge;
    short shSkillIdx2pLifeGauge;
    short shSkillIdx1pSpecialGauge;
    short shSkillIdx2pSpecialGauge;
    short shSkillIdxPositionTimer;
    short shSkillIdxPos1pFace;
    short shSkillIdxPos2pFace;
    short shSkillIdxPosSpecialStock1p;
    short shSkillIdxPosSpecialStock2p;
    short shSkillIdxPosVictoryMark1p;
    short shSkillIdxVPosVictoryMark2p;
    short shSkillIdxTitleCursor;
    short shSkillIdxPositionForStoryMode;
    short shSkillIdxPositionForVsMode;
    short shSkillIdxContinuteCursor;
    short shSkillIdxPositionCursorItDoes;
    short shSkillIdxPositionCursorItDoesNot;
    short shSkillIdx1pVsScreenCursor;
    short shSkillIdx2pVsScreenCursor;
    short shSkillIdx1pVsScreenCursorAfterInput;
    short shSkillIdx2pVsScreenCursorAfterInput;
    short shSkillIdxPosCursorForTeamBattle;
    short shSkillIdxPause;
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
    byte field145_0x146614[76];
    short shCharacterSelectStartX;
    short shCharacterSelectStartY;
    short shDistanceBetweenCharactersX;
    short shDistanceBetweenCharactersY;
    short shSelectScreenColumnsCount;
    short shSelectScreenRowsCount;
    short shPlayer1CursorX;
    short shPlayer1CursorY;
    short shPlayer1SelectionWidth;
    short shPlayer1SelectionHeight;
    short shPlayer2CursorX;
    short shPlayer2CursorY;
    short shPlayer2SelectionWidth;
    short shPlayer2SelectionHeight;
    char cCharacterModeSettings[50]; /* +0x1 = Has story mode, +0x2 = Has VS mode, corresponding to character idx */
    byte field161_0x1466ae[942];
};

