#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015E3F0
// Address: 0x15e3f0 - 0x15e478
void sub_0015E3F0_0x15e3f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015E3F0_0x15e3f0");
#endif

    switch (ctx->pc) {
        case 0x15e404u: goto label_15e404;
        case 0x15e418u: goto label_15e418;
        case 0x15e438u: goto label_15e438;
        default: break;
    }

    ctx->pc = 0x15e3f0u;

    // 0x15e3f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15e3f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15e3f4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15e3f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15e3f8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x15e3f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x15e3fc: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15E3FCu;
    SET_GPR_U32(ctx, 31, 0x15E404u);
    ctx->pc = 0x15E400u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E3FCu;
            // 0x15e400: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E404u; }
        if (ctx->pc != 0x15E404u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E404u; }
        if (ctx->pc != 0x15E404u) { return; }
    }
    ctx->pc = 0x15E404u;
label_15e404:
    // 0x15e404: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x15E404u;
    {
        const bool branch_taken_0x15e404 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15E408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E404u;
            // 0x15e408: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e404) {
            ctx->pc = 0x15E430u;
            goto label_15e430;
        }
    }
    ctx->pc = 0x15E40Cu;
    // 0x15e40c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15e40cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15e410: 0xc058dd4  jal         func_163750
    ctx->pc = 0x15E410u;
    SET_GPR_U32(ctx, 31, 0x15E418u);
    ctx->pc = 0x15E414u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E410u;
            // 0x15e414: 0x2484ed58  addiu       $a0, $a0, -0x12A8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962520));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E418u; }
        if (ctx->pc != 0x15E418u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163750_0x163750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E418u; }
        if (ctx->pc != 0x15E418u) { return; }
    }
    ctx->pc = 0x15E418u;
label_15e418:
    // 0x15e418: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x15e418u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e41c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15e41cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15e420: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15e420u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15e424: 0x3e00008  jr          $ra
    ctx->pc = 0x15E424u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E428u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E424u;
            // 0x15e428: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15E404u: goto label_15e404;
            case 0x15E418u: goto label_15e418;
            case 0x15E430u: goto label_15e430;
            case 0x15E438u: goto label_15e438;
            case 0x15E470u: goto label_15e470;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15E42Cu;
    // 0x15e42c: 0x0  nop
    ctx->pc = 0x15e42cu;
    // NOP
label_15e430:
    // 0x15e430: 0xc057ec8  jal         func_15FB20
    ctx->pc = 0x15E430u;
    SET_GPR_U32(ctx, 31, 0x15E438u);
    ctx->pc = 0x15FB20u;
    if (runtime->hasFunction(0x15FB20u)) {
        auto targetFn = runtime->lookupFunction(0x15FB20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E438u; }
        if (ctx->pc != 0x15E438u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FB20_0x15fb20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15E438u; }
        if (ctx->pc != 0x15E438u) { return; }
    }
    ctx->pc = 0x15E438u;
label_15e438:
    // 0x15e438: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15e438u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15e43c: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x15e43cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e440: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15e440u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15e444: 0x805affc  j           func_16BFF0
    ctx->pc = 0x15E444u;
    ctx->pc = 0x15E448u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15E444u;
            // 0x15e448: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16BFF0u;
    if (runtime->hasFunction(0x16BFF0u)) {
        auto targetFn = runtime->lookupFunction(0x16BFF0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0016BFF0_0x16bff0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15E44Cu;
    // 0x15e44c: 0x0  nop
    ctx->pc = 0x15e44cu;
    // NOP
    // 0x15e450: 0x8c850080  lw          $a1, 0x80($a0)
    ctx->pc = 0x15e450u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 128)));
    // 0x15e454: 0x8c82007c  lw          $v0, 0x7C($a0)
    ctx->pc = 0x15e454u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 124)));
    // 0x15e458: 0x24a40001  addiu       $a0, $a1, 0x1
    ctx->pc = 0x15e458u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x15e45c: 0xa2182a  slt         $v1, $a1, $v0
    ctx->pc = 0x15e45cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x15e460: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x15E460u;
    {
        const bool branch_taken_0x15e460 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x15E464u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E460u;
            // 0x15e464: 0x451026  xor         $v0, $v0, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e460) {
            ctx->pc = 0x15E470u;
            goto label_15e470;
        }
    }
    ctx->pc = 0x15E468u;
    // 0x15e468: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x15e468u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15e46c: 0xa2200a  movz        $a0, $a1, $v0
    ctx->pc = 0x15e46cu;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 5));
label_15e470:
    // 0x15e470: 0x3e00008  jr          $ra
    ctx->pc = 0x15E470u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E474u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E470u;
            // 0x15e474: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15E404u: goto label_15e404;
            case 0x15E418u: goto label_15e418;
            case 0x15E430u: goto label_15e430;
            case 0x15E438u: goto label_15e438;
            case 0x15E470u: goto label_15e470;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15E478u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
