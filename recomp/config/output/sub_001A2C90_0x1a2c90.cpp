#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A2C90
// Address: 0x1a2c90 - 0x1a2cf0
void sub_001A2C90_0x1a2c90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A2C90_0x1a2c90");
#endif

    switch (ctx->pc) {
        case 0x1a2ca0u: goto label_1a2ca0;
        case 0x1a2cb0u: goto label_1a2cb0;
        default: break;
    }

    ctx->pc = 0x1a2c90u;

    // 0x1a2c90: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a2c90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a2c94: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a2c94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a2c98: 0xc068b20  jal         func_1A2C80
    ctx->pc = 0x1A2C98u;
    SET_GPR_U32(ctx, 31, 0x1A2CA0u);
    ctx->pc = 0x1A2C80u;
    if (runtime->hasFunction(0x1A2C80u)) {
        auto targetFn = runtime->lookupFunction(0x1A2C80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2CA0u; }
        if (ctx->pc != 0x1A2CA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2C80_0x1a2c80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2CA0u; }
        if (ctx->pc != 0x1A2CA0u) { return; }
    }
    ctx->pc = 0x1A2CA0u;
label_1a2ca0:
    // 0x1a2ca0: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1a2ca0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1a2ca4: 0x2484000c  addiu       $a0, $a0, 0xC
    ctx->pc = 0x1a2ca4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 12));
    // 0x1a2ca8: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1A2CA8u;
    {
        const bool branch_taken_0x1a2ca8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2CACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2CA8u;
            // 0x1a2cac: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2ca8) {
            ctx->pc = 0x1A2CD0u;
            goto label_1a2cd0;
        }
    }
    ctx->pc = 0x1A2CB0u;
label_1a2cb0:
    // 0x1a2cb0: 0x90820000  lbu         $v0, 0x0($a0)
    ctx->pc = 0x1a2cb0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a2cb4: 0x14450003  bne         $v0, $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A2CB4u;
    {
        const bool branch_taken_0x1a2cb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        ctx->pc = 0x1A2CB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2CB4u;
            // 0x1a2cb8: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2cb4) {
            ctx->pc = 0x1A2CC4u;
            goto label_1a2cc4;
        }
    }
    ctx->pc = 0x1A2CBCu;
    // 0x1a2cbc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1A2CBCu;
    {
        const bool branch_taken_0x1a2cbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A2CC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2CBCu;
            // 0x1a2cc0: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2cbc) {
            ctx->pc = 0x1A2CE0u;
            goto label_1a2ce0;
        }
    }
    ctx->pc = 0x1A2CC4u;
label_1a2cc4:
    // 0x1a2cc4: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x1a2cc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1a2cc8: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x1a2cc8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1a2ccc: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1a2cccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_1a2cd0:
    // 0x1a2cd0: 0xc3102b  sltu        $v0, $a2, $v1
    ctx->pc = 0x1a2cd0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x1a2cd4: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x1A2CD4u;
    {
        const bool branch_taken_0x1a2cd4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A2CD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2CD4u;
            // 0x1a2cd8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a2cd4) {
            ctx->pc = 0x1A2CB0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a2cb0;
        }
    }
    ctx->pc = 0x1A2CDCu;
    // 0x1a2cdc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a2cdcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1a2ce0:
    // 0x1a2ce0: 0x3e00008  jr          $ra
    ctx->pc = 0x1A2CE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A2CE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2CE0u;
            // 0x1a2ce4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A2CA0u: goto label_1a2ca0;
            case 0x1A2CB0u: goto label_1a2cb0;
            case 0x1A2CC4u: goto label_1a2cc4;
            case 0x1A2CD0u: goto label_1a2cd0;
            case 0x1A2CE0u: goto label_1a2ce0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A2CE8u;
    // 0x1a2ce8: 0x0  nop
    ctx->pc = 0x1a2ce8u;
    // NOP
    // 0x1a2cec: 0x0  nop
    ctx->pc = 0x1a2cecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
