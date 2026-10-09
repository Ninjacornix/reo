#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6E30
// Address: 0x1d6e30 - 0x1d6eb0
void sub_001D6E30_0x1d6e30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6E30_0x1d6e30");
#endif

    switch (ctx->pc) {
        case 0x1d6e48u: goto label_1d6e48;
        default: break;
    }

    ctx->pc = 0x1d6e30u;

    // 0x1d6e30: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d6e30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d6e34: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d6e34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d6e38: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d6e38u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d6e3c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1d6e3cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d6e40: 0xc076264  jal         func_1D8990
    ctx->pc = 0x1D6E40u;
    SET_GPR_U32(ctx, 31, 0x1D6E48u);
    ctx->pc = 0x1D6E44u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6E40u;
            // 0x1d6e44: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D8990u;
    if (runtime->hasFunction(0x1D8990u)) {
        auto targetFn = runtime->lookupFunction(0x1D8990u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6E48u; }
        if (ctx->pc != 0x1D6E48u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D8990_0x1d8990(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6E48u; }
        if (ctx->pc != 0x1D6E48u) { return; }
    }
    ctx->pc = 0x1D6E48u;
label_1d6e48:
    // 0x1d6e48: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d6e48u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d6e4c: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d6e4cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d6e50: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D6E50u;
    {
        const bool branch_taken_0x1d6e50 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1d6e50) {
            ctx->pc = 0x1D6E60u;
            goto label_1d6e60;
        }
    }
    ctx->pc = 0x1D6E58u;
    // 0x1d6e58: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1D6E58u;
    {
        const bool branch_taken_0x1d6e58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d6e58) {
            ctx->pc = 0x1D6E98u;
            goto label_1d6e98;
        }
    }
    ctx->pc = 0x1D6E60u;
label_1d6e60:
    // 0x1d6e60: 0x8fa30024  lw          $v1, 0x24($sp)
    ctx->pc = 0x1d6e60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x1d6e64: 0x27a40034  addiu       $a0, $sp, 0x34
    ctx->pc = 0x1d6e64u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 52));
    // 0x1d6e68: 0xae030000  sw          $v1, 0x0($s0)
    ctx->pc = 0x1d6e68u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x1d6e6c: 0x8fa30020  lw          $v1, 0x20($sp)
    ctx->pc = 0x1d6e6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d6e70: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x1d6e70u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x1d6e74: 0x8c830010  lw          $v1, 0x10($a0)
    ctx->pc = 0x1d6e74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x1d6e78: 0xae030008  sw          $v1, 0x8($s0)
    ctx->pc = 0x1d6e78u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 3));
    // 0x1d6e7c: 0x8c830014  lw          $v1, 0x14($a0)
    ctx->pc = 0x1d6e7cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x1d6e80: 0xae03000c  sw          $v1, 0xC($s0)
    ctx->pc = 0x1d6e80u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 3));
    // 0x1d6e84: 0x8c830008  lw          $v1, 0x8($a0)
    ctx->pc = 0x1d6e84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1d6e88: 0xae030010  sw          $v1, 0x10($s0)
    ctx->pc = 0x1d6e88u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
    // 0x1d6e8c: 0x8c83000c  lw          $v1, 0xC($a0)
    ctx->pc = 0x1d6e8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1d6e90: 0xae030014  sw          $v1, 0x14($s0)
    ctx->pc = 0x1d6e90u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 3));
    // 0x1d6e94: 0x0  nop
    ctx->pc = 0x1d6e94u;
    // NOP
label_1d6e98:
    // 0x1d6e98: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d6e98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d6e9c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d6e9cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d6ea0: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6EA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6EA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6EA0u;
            // 0x1d6ea4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D6E48u: goto label_1d6e48;
            case 0x1D6E60u: goto label_1d6e60;
            case 0x1D6E98u: goto label_1d6e98;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6EA8u;
    // 0x1d6ea8: 0x0  nop
    ctx->pc = 0x1d6ea8u;
    // NOP
    // 0x1d6eac: 0x0  nop
    ctx->pc = 0x1d6eacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
