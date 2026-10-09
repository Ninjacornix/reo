#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F7100
// Address: 0x1f7100 - 0x1f7154
void sub_001F7100_0x1f7100(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F7100_0x1f7100");
#endif

    ctx->pc = 0x1f7100u;

    // 0x1f7100: 0x8c850024  lw          $a1, 0x24($a0)
    ctx->pc = 0x1f7100u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x1f7104: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1f7104u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1f7108: 0xafa0000c  sw          $zero, 0xC($sp)
    ctx->pc = 0x1f7108u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 0));
    // 0x1f710c: 0x8c82008c  lw          $v0, 0x8C($a0)
    ctx->pc = 0x1f710cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 140)));
    // 0x1f7110: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1F7110u;
    {
        const bool branch_taken_0x1f7110 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F7114u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7110u;
            // 0x1f7114: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f7110) {
            ctx->pc = 0x1F7128u;
            goto label_1f7128;
        }
    }
    ctx->pc = 0x1F7118u;
    // 0x1f7118: 0xa0820000  sb          $v0, 0x0($a0)
    ctx->pc = 0x1f7118u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1f711c: 0xa0800001  sb          $zero, 0x1($a0)
    ctx->pc = 0x1f711cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1f7120: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1F7120u;
    {
        const bool branch_taken_0x1f7120 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F7124u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F7120u;
            // 0x1f7124: 0xa4800004  sh          $zero, 0x4($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 4), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f7120) {
            ctx->pc = 0x1F7148u;
            goto label_1f7148;
        }
    }
    ctx->pc = 0x1F7128u;
label_1f7128:
    // 0x1f7128: 0x90a30002  lbu         $v1, 0x2($a1)
    ctx->pc = 0x1f7128u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 2)));
    // 0x1f712c: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1f712cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1f7130: 0xa3a3000e  sb          $v1, 0xE($sp)
    ctx->pc = 0x1f7130u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 14), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f7134: 0x90a30003  lbu         $v1, 0x3($a1)
    ctx->pc = 0x1f7134u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 3)));
    // 0x1f7138: 0xa3a3000d  sb          $v1, 0xD($sp)
    ctx->pc = 0x1f7138u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 13), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f713c: 0x90a30004  lbu         $v1, 0x4($a1)
    ctx->pc = 0x1f713cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 4)));
    // 0x1f7140: 0xa3a3000c  sb          $v1, 0xC($sp)
    ctx->pc = 0x1f7140u;
    WRITE8(ADD32(GPR_U32(ctx, 29), 12), (uint8_t)GPR_U32(ctx, 3));
    // 0x1f7144: 0xac820088  sw          $v0, 0x88($a0)
    ctx->pc = 0x1f7144u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 136), GPR_U32(ctx, 2));
label_1f7148:
    // 0x1f7148: 0x8fa2000c  lw          $v0, 0xC($sp)
    ctx->pc = 0x1f7148u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x1f714c: 0x3e00008  jr          $ra
    ctx->pc = 0x1F714Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F7150u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F714Cu;
            // 0x1f7150: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F7128u: goto label_1f7128;
            case 0x1F7148u: goto label_1f7148;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F7154u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
