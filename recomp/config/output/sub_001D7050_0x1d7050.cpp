#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D7050
// Address: 0x1d7050 - 0x1d7260
void sub_001D7050_0x1d7050(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D7050_0x1d7050");
#endif

    switch (ctx->pc) {
        case 0x1d7068u: goto label_1d7068;
        default: break;
    }

    ctx->pc = 0x1d7050u;

    // 0x1d7050: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d7050u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d7054: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d7054u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d7058: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d7058u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d705c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1d705cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d7060: 0xc076264  jal         func_1D8990
    ctx->pc = 0x1D7060u;
    SET_GPR_U32(ctx, 31, 0x1D7068u);
    ctx->pc = 0x1D7064u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7060u;
            // 0x1d7064: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D8990u;
    if (runtime->hasFunction(0x1D8990u)) {
        auto targetFn = runtime->lookupFunction(0x1D8990u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7068u; }
        if (ctx->pc != 0x1D7068u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8990_0x1d8990(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D7068u; }
        if (ctx->pc != 0x1D7068u) { return; }
    }
    ctx->pc = 0x1D7068u;
label_1d7068:
    // 0x1d7068: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d7068u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d706c: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d706cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d7070: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D7070u;
    {
        const bool branch_taken_0x1d7070 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1d7070) {
            ctx->pc = 0x1D7080u;
            goto label_1d7080;
        }
    }
    ctx->pc = 0x1D7078u;
    // 0x1d7078: 0x10000075  b           . + 4 + (0x75 << 2)
    ctx->pc = 0x1D7078u;
    {
        const bool branch_taken_0x1d7078 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d7078) {
            ctx->pc = 0x1D7250u;
            goto label_1d7250;
        }
    }
    ctx->pc = 0x1D7080u;
label_1d7080:
    // 0x1d7080: 0x8fa30020  lw          $v1, 0x20($sp)
    ctx->pc = 0x1d7080u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d7084: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x1d7084u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x1d7088: 0x8fa30024  lw          $v1, 0x24($sp)
    ctx->pc = 0x1d7088u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1d708c: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x1d708cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x1d7090: 0x87a30028  lh          $v1, 0x28($sp)
    ctx->pc = 0x1d7090u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1d7094: 0x2c61000a  sltiu       $at, $v1, 0xA
    ctx->pc = 0x1d7094u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x1d7098: 0x10200025  beqz        $at, . + 4 + (0x25 << 2)
    ctx->pc = 0x1D7098u;
    {
        const bool branch_taken_0x1d7098 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D709Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7098u;
            // 0x1d709c: 0x3c040025  lui         $a0, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d7098) {
            ctx->pc = 0x1D7130u;
            goto label_1d7130;
        }
    }
    ctx->pc = 0x1D70A0u;
    // 0x1d70a0: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1d70a0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d70a4: 0x24847c70  addiu       $a0, $a0, 0x7C70
    ctx->pc = 0x1d70a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 31856));
    // 0x1d70a8: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1d70a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d70ac: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1d70acu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d70b0: 0x600008  jr          $v1
    ctx->pc = 0x1D70B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D70B8u: goto label_1d70b8;
            case 0x1D70C0u: goto label_1d70c0;
            case 0x1D70D0u: goto label_1d70d0;
            case 0x1D70E0u: goto label_1d70e0;
            case 0x1D70F0u: goto label_1d70f0;
            case 0x1D7100u: goto label_1d7100;
            case 0x1D7110u: goto label_1d7110;
            case 0x1D7120u: goto label_1d7120;
            case 0x1D7130u: goto label_1d7130;
            case 0x1D7140u: goto label_1d7140;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D70B8u;
label_1d70b8:
    // 0x1d70b8: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1D70B8u;
    {
        const bool branch_taken_0x1d70b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D70BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D70B8u;
            // 0x1d70bc: 0xa600000c  sh          $zero, 0xC($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d70b8) {
            ctx->pc = 0x1D7148u;
            goto label_1d7148;
        }
    }
    ctx->pc = 0x1D70C0u;
label_1d70c0:
    // 0x1d70c0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d70c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d70c4: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x1D70C4u;
    {
        const bool branch_taken_0x1d70c4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D70C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D70C4u;
            // 0x1d70c8: 0xa603000c  sh          $v1, 0xC($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d70c4) {
            ctx->pc = 0x1D7148u;
            goto label_1d7148;
        }
    }
    ctx->pc = 0x1D70CCu;
    // 0x1d70cc: 0x0  nop
    ctx->pc = 0x1d70ccu;
    // NOP
label_1d70d0:
    // 0x1d70d0: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1d70d0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d70d4: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1D70D4u;
    {
        const bool branch_taken_0x1d70d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D70D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D70D4u;
            // 0x1d70d8: 0xa603000c  sh          $v1, 0xC($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d70d4) {
            ctx->pc = 0x1D7148u;
            goto label_1d7148;
        }
    }
    ctx->pc = 0x1D70DCu;
    // 0x1d70dc: 0x0  nop
    ctx->pc = 0x1d70dcu;
    // NOP
label_1d70e0:
    // 0x1d70e0: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1d70e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d70e4: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1D70E4u;
    {
        const bool branch_taken_0x1d70e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D70E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D70E4u;
            // 0x1d70e8: 0xa603000c  sh          $v1, 0xC($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d70e4) {
            ctx->pc = 0x1D7148u;
            goto label_1d7148;
        }
    }
    ctx->pc = 0x1D70ECu;
    // 0x1d70ec: 0x0  nop
    ctx->pc = 0x1d70ecu;
    // NOP
label_1d70f0:
    // 0x1d70f0: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1d70f0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d70f4: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1D70F4u;
    {
        const bool branch_taken_0x1d70f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D70F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D70F4u;
            // 0x1d70f8: 0xa603000c  sh          $v1, 0xC($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d70f4) {
            ctx->pc = 0x1D7148u;
            goto label_1d7148;
        }
    }
    ctx->pc = 0x1D70FCu;
    // 0x1d70fc: 0x0  nop
    ctx->pc = 0x1d70fcu;
    // NOP
label_1d7100:
    // 0x1d7100: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1d7100u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1d7104: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1D7104u;
    {
        const bool branch_taken_0x1d7104 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D7108u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7104u;
            // 0x1d7108: 0xa603000c  sh          $v1, 0xC($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d7104) {
            ctx->pc = 0x1D7148u;
            goto label_1d7148;
        }
    }
    ctx->pc = 0x1D710Cu;
    // 0x1d710c: 0x0  nop
    ctx->pc = 0x1d710cu;
    // NOP
label_1d7110:
    // 0x1d7110: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x1d7110u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1d7114: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1D7114u;
    {
        const bool branch_taken_0x1d7114 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D7118u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7114u;
            // 0x1d7118: 0xa603000c  sh          $v1, 0xC($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d7114) {
            ctx->pc = 0x1D7148u;
            goto label_1d7148;
        }
    }
    ctx->pc = 0x1D711Cu;
    // 0x1d711c: 0x0  nop
    ctx->pc = 0x1d711cu;
    // NOP
label_1d7120:
    // 0x1d7120: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1d7120u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1d7124: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1D7124u;
    {
        const bool branch_taken_0x1d7124 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D7128u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7124u;
            // 0x1d7128: 0xa603000c  sh          $v1, 0xC($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d7124) {
            ctx->pc = 0x1D7148u;
            goto label_1d7148;
        }
    }
    ctx->pc = 0x1D712Cu;
    // 0x1d712c: 0x0  nop
    ctx->pc = 0x1d712cu;
    // NOP
label_1d7130:
    // 0x1d7130: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x1d7130u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1d7134: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1D7134u;
    {
        const bool branch_taken_0x1d7134 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D7138u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7134u;
            // 0x1d7138: 0xa603000c  sh          $v1, 0xC($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d7134) {
            ctx->pc = 0x1D7148u;
            goto label_1d7148;
        }
    }
    ctx->pc = 0x1D713Cu;
    // 0x1d713c: 0x0  nop
    ctx->pc = 0x1d713cu;
    // NOP
label_1d7140:
    // 0x1d7140: 0x24030009  addiu       $v1, $zero, 0x9
    ctx->pc = 0x1d7140u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1d7144: 0xa603000c  sh          $v1, 0xC($s0)
    ctx->pc = 0x1d7144u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 12), (uint16_t)GPR_U32(ctx, 3));
label_1d7148:
    // 0x1d7148: 0x8fa3002c  lw          $v1, 0x2C($sp)
    ctx->pc = 0x1d7148u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1d714c: 0xae030008  sw          $v1, 0x8($s0)
    ctx->pc = 0x1d714cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 3));
    // 0x1d7150: 0x87a30030  lh          $v1, 0x30($sp)
    ctx->pc = 0x1d7150u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d7154: 0xa603000e  sh          $v1, 0xE($s0)
    ctx->pc = 0x1d7154u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 14), (uint16_t)GPR_U32(ctx, 3));
    // 0x1d7158: 0x87a30032  lh          $v1, 0x32($sp)
    ctx->pc = 0x1d7158u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 50)));
    // 0x1d715c: 0x2c61000e  sltiu       $at, $v1, 0xE
    ctx->pc = 0x1d715cu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)(int64_t)(int32_t)14) ? 1 : 0);
    // 0x1d7160: 0x10200031  beqz        $at, . + 4 + (0x31 << 2)
    ctx->pc = 0x1D7160u;
    {
        const bool branch_taken_0x1d7160 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D7164u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7160u;
            // 0x1d7164: 0x3c040025  lui         $a0, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d7160) {
            ctx->pc = 0x1D7228u;
            goto label_1d7228;
        }
    }
    ctx->pc = 0x1D7168u;
    // 0x1d7168: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1d7168u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d716c: 0x24847c30  addiu       $a0, $a0, 0x7C30
    ctx->pc = 0x1d716cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 31792));
    // 0x1d7170: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1d7170u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d7174: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1d7174u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d7178: 0x600008  jr          $v1
    ctx->pc = 0x1D7178u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D7180u: goto label_1d7180;
            case 0x1D7188u: goto label_1d7188;
            case 0x1D7198u: goto label_1d7198;
            case 0x1D71A8u: goto label_1d71a8;
            case 0x1D71B8u: goto label_1d71b8;
            case 0x1D71C8u: goto label_1d71c8;
            case 0x1D71D8u: goto label_1d71d8;
            case 0x1D71E8u: goto label_1d71e8;
            case 0x1D71F8u: goto label_1d71f8;
            case 0x1D7208u: goto label_1d7208;
            case 0x1D7218u: goto label_1d7218;
            case 0x1D7228u: goto label_1d7228;
            case 0x1D7238u: goto label_1d7238;
            case 0x1D7248u: goto label_1d7248;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D7180u;
label_1d7180:
    // 0x1d7180: 0x10000033  b           . + 4 + (0x33 << 2)
    ctx->pc = 0x1D7180u;
    {
        const bool branch_taken_0x1d7180 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D7184u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7180u;
            // 0x1d7184: 0xa6000010  sh          $zero, 0x10($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 16), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d7180) {
            ctx->pc = 0x1D7250u;
            goto label_1d7250;
        }
    }
    ctx->pc = 0x1D7188u;
label_1d7188:
    // 0x1d7188: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d7188u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d718c: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x1D718Cu;
    {
        const bool branch_taken_0x1d718c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D7190u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D718Cu;
            // 0x1d7190: 0xa6030010  sh          $v1, 0x10($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 16), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d718c) {
            ctx->pc = 0x1D7250u;
            goto label_1d7250;
        }
    }
    ctx->pc = 0x1D7194u;
    // 0x1d7194: 0x0  nop
    ctx->pc = 0x1d7194u;
    // NOP
label_1d7198:
    // 0x1d7198: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1d7198u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d719c: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x1D719Cu;
    {
        const bool branch_taken_0x1d719c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D71A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D719Cu;
            // 0x1d71a0: 0xa6030010  sh          $v1, 0x10($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 16), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d719c) {
            ctx->pc = 0x1D7250u;
            goto label_1d7250;
        }
    }
    ctx->pc = 0x1D71A4u;
    // 0x1d71a4: 0x0  nop
    ctx->pc = 0x1d71a4u;
    // NOP
label_1d71a8:
    // 0x1d71a8: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1d71a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d71ac: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1D71ACu;
    {
        const bool branch_taken_0x1d71ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D71B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D71ACu;
            // 0x1d71b0: 0xa6030010  sh          $v1, 0x10($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 16), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d71ac) {
            ctx->pc = 0x1D7250u;
            goto label_1d7250;
        }
    }
    ctx->pc = 0x1D71B4u;
    // 0x1d71b4: 0x0  nop
    ctx->pc = 0x1d71b4u;
    // NOP
label_1d71b8:
    // 0x1d71b8: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1d71b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d71bc: 0x10000024  b           . + 4 + (0x24 << 2)
    ctx->pc = 0x1D71BCu;
    {
        const bool branch_taken_0x1d71bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D71C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D71BCu;
            // 0x1d71c0: 0xa6030010  sh          $v1, 0x10($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 16), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d71bc) {
            ctx->pc = 0x1D7250u;
            goto label_1d7250;
        }
    }
    ctx->pc = 0x1D71C4u;
    // 0x1d71c4: 0x0  nop
    ctx->pc = 0x1d71c4u;
    // NOP
label_1d71c8:
    // 0x1d71c8: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1d71c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1d71cc: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x1D71CCu;
    {
        const bool branch_taken_0x1d71cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D71D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D71CCu;
            // 0x1d71d0: 0xa6030010  sh          $v1, 0x10($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 16), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d71cc) {
            ctx->pc = 0x1D7250u;
            goto label_1d7250;
        }
    }
    ctx->pc = 0x1D71D4u;
    // 0x1d71d4: 0x0  nop
    ctx->pc = 0x1d71d4u;
    // NOP
label_1d71d8:
    // 0x1d71d8: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x1d71d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1d71dc: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1D71DCu;
    {
        const bool branch_taken_0x1d71dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D71E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D71DCu;
            // 0x1d71e0: 0xa6030010  sh          $v1, 0x10($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 16), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d71dc) {
            ctx->pc = 0x1D7250u;
            goto label_1d7250;
        }
    }
    ctx->pc = 0x1D71E4u;
    // 0x1d71e4: 0x0  nop
    ctx->pc = 0x1d71e4u;
    // NOP
label_1d71e8:
    // 0x1d71e8: 0x24030007  addiu       $v1, $zero, 0x7
    ctx->pc = 0x1d71e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1d71ec: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1D71ECu;
    {
        const bool branch_taken_0x1d71ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D71F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D71ECu;
            // 0x1d71f0: 0xa6030010  sh          $v1, 0x10($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 16), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d71ec) {
            ctx->pc = 0x1D7250u;
            goto label_1d7250;
        }
    }
    ctx->pc = 0x1D71F4u;
    // 0x1d71f4: 0x0  nop
    ctx->pc = 0x1d71f4u;
    // NOP
label_1d71f8:
    // 0x1d71f8: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x1d71f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1d71fc: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1D71FCu;
    {
        const bool branch_taken_0x1d71fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D7200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D71FCu;
            // 0x1d7200: 0xa6030010  sh          $v1, 0x10($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 16), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d71fc) {
            ctx->pc = 0x1D7250u;
            goto label_1d7250;
        }
    }
    ctx->pc = 0x1D7204u;
    // 0x1d7204: 0x0  nop
    ctx->pc = 0x1d7204u;
    // NOP
label_1d7208:
    // 0x1d7208: 0x24030009  addiu       $v1, $zero, 0x9
    ctx->pc = 0x1d7208u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
    // 0x1d720c: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1D720Cu;
    {
        const bool branch_taken_0x1d720c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D7210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D720Cu;
            // 0x1d7210: 0xa6030010  sh          $v1, 0x10($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 16), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d720c) {
            ctx->pc = 0x1D7250u;
            goto label_1d7250;
        }
    }
    ctx->pc = 0x1D7214u;
    // 0x1d7214: 0x0  nop
    ctx->pc = 0x1d7214u;
    // NOP
label_1d7218:
    // 0x1d7218: 0x2403000a  addiu       $v1, $zero, 0xA
    ctx->pc = 0x1d7218u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1d721c: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1D721Cu;
    {
        const bool branch_taken_0x1d721c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D7220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D721Cu;
            // 0x1d7220: 0xa6030010  sh          $v1, 0x10($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 16), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d721c) {
            ctx->pc = 0x1D7250u;
            goto label_1d7250;
        }
    }
    ctx->pc = 0x1D7224u;
    // 0x1d7224: 0x0  nop
    ctx->pc = 0x1d7224u;
    // NOP
label_1d7228:
    // 0x1d7228: 0x2403000b  addiu       $v1, $zero, 0xB
    ctx->pc = 0x1d7228u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x1d722c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1D722Cu;
    {
        const bool branch_taken_0x1d722c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D7230u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D722Cu;
            // 0x1d7230: 0xa6030010  sh          $v1, 0x10($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 16), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d722c) {
            ctx->pc = 0x1D7250u;
            goto label_1d7250;
        }
    }
    ctx->pc = 0x1D7234u;
    // 0x1d7234: 0x0  nop
    ctx->pc = 0x1d7234u;
    // NOP
label_1d7238:
    // 0x1d7238: 0x2403000c  addiu       $v1, $zero, 0xC
    ctx->pc = 0x1d7238u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1d723c: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1D723Cu;
    {
        const bool branch_taken_0x1d723c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D7240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D723Cu;
            // 0x1d7240: 0xa6030010  sh          $v1, 0x10($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 16), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d723c) {
            ctx->pc = 0x1D7250u;
            goto label_1d7250;
        }
    }
    ctx->pc = 0x1D7244u;
    // 0x1d7244: 0x0  nop
    ctx->pc = 0x1d7244u;
    // NOP
label_1d7248:
    // 0x1d7248: 0x2403000d  addiu       $v1, $zero, 0xD
    ctx->pc = 0x1d7248u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1d724c: 0xa6030010  sh          $v1, 0x10($s0)
    ctx->pc = 0x1d724cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 16), (uint16_t)GPR_U32(ctx, 3));
label_1d7250:
    // 0x1d7250: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d7250u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d7254: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d7254u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d7258: 0x3e00008  jr          $ra
    ctx->pc = 0x1D7258u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D725Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D7258u;
            // 0x1d725c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D7068u: goto label_1d7068;
            case 0x1D7080u: goto label_1d7080;
            case 0x1D70B8u: goto label_1d70b8;
            case 0x1D70C0u: goto label_1d70c0;
            case 0x1D70D0u: goto label_1d70d0;
            case 0x1D70E0u: goto label_1d70e0;
            case 0x1D70F0u: goto label_1d70f0;
            case 0x1D7100u: goto label_1d7100;
            case 0x1D7110u: goto label_1d7110;
            case 0x1D7120u: goto label_1d7120;
            case 0x1D7130u: goto label_1d7130;
            case 0x1D7140u: goto label_1d7140;
            case 0x1D7148u: goto label_1d7148;
            case 0x1D7180u: goto label_1d7180;
            case 0x1D7188u: goto label_1d7188;
            case 0x1D7198u: goto label_1d7198;
            case 0x1D71A8u: goto label_1d71a8;
            case 0x1D71B8u: goto label_1d71b8;
            case 0x1D71C8u: goto label_1d71c8;
            case 0x1D71D8u: goto label_1d71d8;
            case 0x1D71E8u: goto label_1d71e8;
            case 0x1D71F8u: goto label_1d71f8;
            case 0x1D7208u: goto label_1d7208;
            case 0x1D7218u: goto label_1d7218;
            case 0x1D7228u: goto label_1d7228;
            case 0x1D7238u: goto label_1d7238;
            case 0x1D7248u: goto label_1d7248;
            case 0x1D7250u: goto label_1d7250;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D7260u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
