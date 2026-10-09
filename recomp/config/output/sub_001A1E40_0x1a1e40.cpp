#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A1E40
// Address: 0x1a1e40 - 0x1a1ed0
void sub_001A1E40_0x1a1e40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A1E40_0x1a1e40");
#endif

    switch (ctx->pc) {
        case 0x1a1e60u: goto label_1a1e60;
        case 0x1a1e74u: goto label_1a1e74;
        case 0x1a1e7cu: goto label_1a1e7c;
        case 0x1a1e94u: goto label_1a1e94;
        default: break;
    }

    ctx->pc = 0x1a1e40u;

    // 0x1a1e40: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1a1e40u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1a1e44: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1a1e44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1a1e48: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1a1e48u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1a1e4c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1a1e4cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1a1e50: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a1e50u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a1e54: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a1e54u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a1e58: 0xc068ab4  jal         func_1A2AD0
    ctx->pc = 0x1A1E58u;
    SET_GPR_U32(ctx, 31, 0x1A1E60u);
    ctx->pc = 0x1A1E5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1E58u;
            // 0x1a1e5c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2AD0u;
    if (runtime->hasFunction(0x1A2AD0u)) {
        auto targetFn = runtime->lookupFunction(0x1A2AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1E60u; }
        if (ctx->pc != 0x1A1E60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2AD0_0x1a2ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1E60u; }
        if (ctx->pc != 0x1A1E60u) { return; }
    }
    ctx->pc = 0x1A1E60u;
label_1a1e60:
    // 0x1a1e60: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1a1e60u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1e64: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x1a1e64u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1e68: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1a1e68u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1a1e6c: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1A1E6Cu;
    {
        const bool branch_taken_0x1a1e6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A1E70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1E6Cu;
            // 0x1a1e70: 0x24510020  addiu       $s1, $v0, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1e6c) {
            ctx->pc = 0x1A1E9Cu;
            goto label_1a1e9c;
        }
    }
    ctx->pc = 0x1A1E74u;
label_1a1e74:
    // 0x1a1e74: 0xc06876c  jal         func_1A1DB0
    ctx->pc = 0x1A1E74u;
    SET_GPR_U32(ctx, 31, 0x1A1E7Cu);
    ctx->pc = 0x1A1E78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1E74u;
            // 0x1a1e78: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1DB0u;
    if (runtime->hasFunction(0x1A1DB0u)) {
        auto targetFn = runtime->lookupFunction(0x1A1DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1E7Cu; }
        if (ctx->pc != 0x1A1E7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1DB0_0x1a1db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1E7Cu; }
        if (ctx->pc != 0x1A1E7Cu) { return; }
    }
    ctx->pc = 0x1A1E7Cu;
label_1a1e7c:
    // 0x1a1e7c: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1a1e7cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1a1e80: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x1a1e80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1e84: 0x26310008  addiu       $s1, $s1, 0x8
    ctx->pc = 0x1a1e84u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 8));
    // 0x1a1e88: 0x310c0  sll         $v0, $v1, 3
    ctx->pc = 0x1a1e88u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1a1e8c: 0xc0687b4  jal         func_1A1ED0
    ctx->pc = 0x1A1E8Cu;
    SET_GPR_U32(ctx, 31, 0x1A1E94u);
    ctx->pc = 0x1A1E90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1E8Cu;
            // 0x1a1e90: 0x2228821  addu        $s1, $s1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A1ED0u;
    if (runtime->hasFunction(0x1A1ED0u)) {
        auto targetFn = runtime->lookupFunction(0x1A1ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1E94u; }
        if (ctx->pc != 0x1A1E94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1ED0_0x1a1ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A1E94u; }
        if (ctx->pc != 0x1A1E94u) { return; }
    }
    ctx->pc = 0x1A1E94u;
label_1a1e94:
    // 0x1a1e94: 0x2228821  addu        $s1, $s1, $v0
    ctx->pc = 0x1a1e94u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
    // 0x1a1e98: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x1a1e98u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
label_1a1e9c:
    // 0x1a1e9c: 0x272102a  slt         $v0, $s3, $s2
    ctx->pc = 0x1a1e9cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 19) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x1a1ea0: 0x1440fff4  bnez        $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x1A1EA0u;
    {
        const bool branch_taken_0x1a1ea0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A1EA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1EA0u;
            // 0x1a1ea4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a1ea0) {
            ctx->pc = 0x1A1E74u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a1e74;
        }
    }
    ctx->pc = 0x1A1EA8u;
    // 0x1a1ea8: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x1a1ea8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a1eac: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1a1eacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1a1eb0: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1a1eb0u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a1eb4: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1a1eb4u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a1eb8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a1eb8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a1ebc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a1ebcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a1ec0: 0x3e00008  jr          $ra
    ctx->pc = 0x1A1EC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A1EC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A1EC0u;
            // 0x1a1ec4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A1E60u: goto label_1a1e60;
            case 0x1A1E74u: goto label_1a1e74;
            case 0x1A1E7Cu: goto label_1a1e7c;
            case 0x1A1E94u: goto label_1a1e94;
            case 0x1A1E9Cu: goto label_1a1e9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A1EC8u;
    // 0x1a1ec8: 0x0  nop
    ctx->pc = 0x1a1ec8u;
    // NOP
    // 0x1a1ecc: 0x0  nop
    ctx->pc = 0x1a1eccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
