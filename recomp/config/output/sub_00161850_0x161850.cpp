#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00161850
// Address: 0x161850 - 0x1618ac
void sub_00161850_0x161850(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00161850_0x161850");
#endif

    switch (ctx->pc) {
        case 0x161864u: goto label_161864;
        case 0x161878u: goto label_161878;
        case 0x161898u: goto label_161898;
        default: break;
    }

    ctx->pc = 0x161850u;

    // 0x161850: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x161850u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x161854: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x161854u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x161858: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x161858u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x16185c: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x16185Cu;
    SET_GPR_U32(ctx, 31, 0x161864u);
    ctx->pc = 0x161860u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16185Cu;
            // 0x161860: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161864u; }
        if (ctx->pc != 0x161864u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161864u; }
        if (ctx->pc != 0x161864u) { return; }
    }
    ctx->pc = 0x161864u;
label_161864:
    // 0x161864: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x161864u;
    {
        const bool branch_taken_0x161864 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x161868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161864u;
            // 0x161868: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x161864) {
            ctx->pc = 0x161890u;
            goto label_161890;
        }
    }
    ctx->pc = 0x16186Cu;
    // 0x16186c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x16186cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x161870: 0xc058dd4  jal         func_163750
    ctx->pc = 0x161870u;
    SET_GPR_U32(ctx, 31, 0x161878u);
    ctx->pc = 0x161874u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x161870u;
            // 0x161874: 0x2484fe48  addiu       $a0, $a0, -0x1B8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294966856));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161878u; }
        if (ctx->pc != 0x161878u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161878u; }
        if (ctx->pc != 0x161878u) { return; }
    }
    ctx->pc = 0x161878u;
label_161878:
    // 0x161878: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x161878u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16187c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16187cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x161880: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x161880u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x161884: 0x3e00008  jr          $ra
    ctx->pc = 0x161884u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x161888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x161884u;
            // 0x161888: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x161864u: goto label_161864;
            case 0x161878u: goto label_161878;
            case 0x161890u: goto label_161890;
            case 0x161898u: goto label_161898;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16188Cu;
    // 0x16188c: 0x0  nop
    ctx->pc = 0x16188cu;
    // NOP
label_161890:
    // 0x161890: 0xc0582e4  jal         func_160B90
    ctx->pc = 0x161890u;
    SET_GPR_U32(ctx, 31, 0x161898u);
    ctx->pc = 0x160B90u;
    if (runtime->hasFunction(0x160B90u)) {
        auto targetFn = runtime->lookupFunction(0x160B90u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161898u; }
        if (ctx->pc != 0x161898u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00160B90_0x160b90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x161898u; }
        if (ctx->pc != 0x161898u) { return; }
    }
    ctx->pc = 0x161898u;
label_161898:
    // 0x161898: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x161898u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16189c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x16189cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1618a0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1618a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1618a4: 0x805f4f6  j           func_17D3D8
    ctx->pc = 0x1618A4u;
    ctx->pc = 0x1618A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1618A4u;
            // 0x1618a8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17D3D8u;
    if (runtime->hasFunction(0x17D3D8u)) {
        auto targetFn = runtime->lookupFunction(0x17D3D8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017D3D8_0x17d3d8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1618ACu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
