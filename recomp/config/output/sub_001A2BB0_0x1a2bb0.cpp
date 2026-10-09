#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A2BB0
// Address: 0x1a2bb0 - 0x1a2be0
void sub_001A2BB0_0x1a2bb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A2BB0_0x1a2bb0");
#endif

    switch (ctx->pc) {
        case 0x1a2bc4u: goto label_1a2bc4;
        case 0x1a2bd0u: goto label_1a2bd0;
        default: break;
    }

    ctx->pc = 0x1a2bb0u;

    // 0x1a2bb0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1a2bb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1a2bb4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1a2bb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1a2bb8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a2bb8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a2bbc: 0xc068ad8  jal         func_1A2B60
    ctx->pc = 0x1A2BBCu;
    SET_GPR_U32(ctx, 31, 0x1A2BC4u);
    ctx->pc = 0x1A2BC0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2BBCu;
            // 0x1a2bc0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2B60u;
    if (runtime->hasFunction(0x1A2B60u)) {
        auto targetFn = runtime->lookupFunction(0x1A2B60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2BC4u; }
        if (ctx->pc != 0x1A2BC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2B60_0x1a2b60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2BC4u; }
        if (ctx->pc != 0x1A2BC4u) { return; }
    }
    ctx->pc = 0x1A2BC4u;
label_1a2bc4:
    // 0x1a2bc4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1a2bc4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a2bc8: 0xc068af8  jal         func_1A2BE0
    ctx->pc = 0x1A2BC8u;
    SET_GPR_U32(ctx, 31, 0x1A2BD0u);
    ctx->pc = 0x1A2BCCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2BC8u;
            // 0x1a2bcc: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A2BE0u;
    if (runtime->hasFunction(0x1A2BE0u)) {
        auto targetFn = runtime->lookupFunction(0x1A2BE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2BD0u; }
        if (ctx->pc != 0x1A2BD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A2BE0_0x1a2be0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A2BD0u; }
        if (ctx->pc != 0x1A2BD0u) { return; }
    }
    ctx->pc = 0x1A2BD0u;
label_1a2bd0:
    // 0x1a2bd0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1a2bd0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a2bd4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a2bd4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a2bd8: 0x3e00008  jr          $ra
    ctx->pc = 0x1A2BD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A2BDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A2BD8u;
            // 0x1a2bdc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A2BC4u: goto label_1a2bc4;
            case 0x1A2BD0u: goto label_1a2bd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A2BE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
