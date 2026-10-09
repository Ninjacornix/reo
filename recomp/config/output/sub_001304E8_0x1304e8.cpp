#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001304E8
// Address: 0x1304e8 - 0x130520
void sub_001304E8_0x1304e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001304E8_0x1304e8");
#endif

    switch (ctx->pc) {
        case 0x1304fcu: goto label_1304fc;
        case 0x130500u: goto label_130500;
        case 0x130508u: goto label_130508;
        default: break;
    }

    ctx->pc = 0x1304e8u;

    // 0x1304e8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1304e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1304ec: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1304ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1304f0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1304f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1304f4: 0xc04c11e  jal         func_130478
    ctx->pc = 0x1304F4u;
    SET_GPR_U32(ctx, 31, 0x1304FCu);
    ctx->pc = 0x1304F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1304F4u;
            // 0x1304f8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130478u;
    if (runtime->hasFunction(0x130478u)) {
        auto targetFn = runtime->lookupFunction(0x130478u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1304FCu; }
        if (ctx->pc != 0x1304FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130478_0x130478(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1304FCu; }
        if (ctx->pc != 0x1304FCu) { return; }
    }
    ctx->pc = 0x1304FCu;
label_1304fc:
    // 0x1304fc: 0x0  nop
    ctx->pc = 0x1304fcu;
    // NOP
label_130500:
    // 0x130500: 0xc04a808  jal         func_12A020
    ctx->pc = 0x130500u;
    SET_GPR_U32(ctx, 31, 0x130508u);
    ctx->pc = 0x12A020u;
    if (runtime->hasFunction(0x12A020u)) {
        auto targetFn = runtime->lookupFunction(0x12A020u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130508u; }
        if (ctx->pc != 0x130508u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A020_0x12a020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130508u; }
        if (ctx->pc != 0x130508u) { return; }
    }
    ctx->pc = 0x130508u;
label_130508:
    // 0x130508: 0x82020041  lb          $v0, 0x41($s0)
    ctx->pc = 0x130508u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 65)));
    // 0x13050c: 0x1440fffc  bnez        $v0, . + 4 + (-0x4 << 2)
    ctx->pc = 0x13050Cu;
    {
        const bool branch_taken_0x13050c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x130510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13050Cu;
            // 0x130510: 0xdfbf0008  ld          $ra, 0x8($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13050c) {
            ctx->pc = 0x130500u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_130500;
        }
    }
    ctx->pc = 0x130514u;
    // 0x130514: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x130514u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x130518: 0x3e00008  jr          $ra
    ctx->pc = 0x130518u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13051Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130518u;
            // 0x13051c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1304FCu: goto label_1304fc;
            case 0x130500u: goto label_130500;
            case 0x130508u: goto label_130508;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130520u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
