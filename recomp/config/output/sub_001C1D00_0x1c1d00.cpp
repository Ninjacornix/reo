#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C1D00
// Address: 0x1c1d00 - 0x1c1da0
void sub_001C1D00_0x1c1d00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C1D00_0x1c1d00");
#endif

    switch (ctx->pc) {
        case 0x1c1d40u: goto label_1c1d40;
        case 0x1c1d70u: goto label_1c1d70;
        default: break;
    }

    ctx->pc = 0x1c1d00u;

    // 0x1c1d00: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1c1d00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1c1d04: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c1d04u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c1d08: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1c1d08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1c1d0c: 0x410c0  sll         $v0, $a0, 3
    ctx->pc = 0x1c1d0cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1c1d10: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1c1d10u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1c1d14: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c1d14u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c1d18: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c1d18u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c1d1c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c1d1cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c1d20: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1c1d20u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c1d24: 0x8c33443c  lw          $s3, 0x443C($at)
    ctx->pc = 0x1c1d24u;
    SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17468)));
    // 0x1c1d28: 0x26630004  addiu       $v1, $s3, 0x4
    ctx->pc = 0x1c1d28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 19), 4));
    // 0x1c1d2c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1c1d2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1c1d30: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1c1d30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1c1d34: 0x8c700004  lw          $s0, 0x4($v1)
    ctx->pc = 0x1c1d34u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1c1d38: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1C1D38u;
    {
        const bool branch_taken_0x1c1d38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C1D3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1D38u;
            // 0x1c1d3c: 0x2629021  addu        $s2, $s3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1d38) {
            ctx->pc = 0x1C1D74u;
            goto label_1c1d74;
        }
    }
    ctx->pc = 0x1C1D40u;
label_1c1d40:
    // 0x1c1d40: 0x1118c0  sll         $v1, $s1, 3
    ctx->pc = 0x1c1d40u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x1c1d44: 0x2421021  addu        $v0, $s2, $v0
    ctx->pc = 0x1c1d44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x1c1d48: 0x711823  subu        $v1, $v1, $s1
    ctx->pc = 0x1c1d48u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1c1d4c: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1c1d4cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c1d50: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1c1d50u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1c1d54: 0x2466017c  addiu       $a2, $v1, 0x17C
    ctx->pc = 0x1c1d54u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 380));
    // 0x1c1d58: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1c1d58u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c1d5c: 0x24050050  addiu       $a1, $zero, 0x50
    ctx->pc = 0x1c1d5cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
    // 0x1c1d60: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1c1d60u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c1d64: 0x24080018  addiu       $t0, $zero, 0x18
    ctx->pc = 0x1c1d64u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1c1d68: 0xc06d208  jal         func_1B4820
    ctx->pc = 0x1C1D68u;
    SET_GPR_U32(ctx, 31, 0x1C1D70u);
    ctx->pc = 0x1C1D6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1D68u;
            // 0x1c1d6c: 0x2624821  addu        $t1, $s3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B4820u;
    if (runtime->hasFunction(0x1B4820u)) {
        auto targetFn = runtime->lookupFunction(0x1B4820u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1D70u; }
        if (ctx->pc != 0x1C1D70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B4820_0x1b4820(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C1D70u; }
        if (ctx->pc != 0x1C1D70u) { return; }
    }
    ctx->pc = 0x1C1D70u;
label_1c1d70:
    // 0x1c1d70: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1c1d70u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_1c1d74:
    // 0x1c1d74: 0x230102a  slt         $v0, $s1, $s0
    ctx->pc = 0x1c1d74u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 16)) ? 1 : 0);
    // 0x1c1d78: 0x1440fff1  bnez        $v0, . + 4 + (-0xF << 2)
    ctx->pc = 0x1C1D78u;
    {
        const bool branch_taken_0x1c1d78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C1D7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1D78u;
            // 0x1c1d7c: 0x111080  sll         $v0, $s1, 2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c1d78) {
            ctx->pc = 0x1C1D40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c1d40;
        }
    }
    ctx->pc = 0x1C1D80u;
    // 0x1c1d80: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x1c1d80u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c1d84: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1c1d84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1c1d88: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1c1d88u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c1d8c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c1d8cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c1d90: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c1d90u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c1d94: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c1d94u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c1d98: 0x3e00008  jr          $ra
    ctx->pc = 0x1C1D98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C1D9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C1D98u;
            // 0x1c1d9c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C1D40u: goto label_1c1d40;
            case 0x1C1D70u: goto label_1c1d70;
            case 0x1C1D74u: goto label_1c1d74;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C1DA0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
