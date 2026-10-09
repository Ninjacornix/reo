#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BA360
// Address: 0x1ba360 - 0x1ba420
void sub_001BA360_0x1ba360(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BA360_0x1ba360");
#endif

    switch (ctx->pc) {
        case 0x1ba380u: goto label_1ba380;
        case 0x1ba388u: goto label_1ba388;
        case 0x1ba3b8u: goto label_1ba3b8;
        case 0x1ba3d0u: goto label_1ba3d0;
        case 0x1ba3fcu: goto label_1ba3fc;
        case 0x1ba40cu: goto label_1ba40c;
        default: break;
    }

    ctx->pc = 0x1ba360u;

    // 0x1ba360: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ba360u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ba364: 0x3c020059  lui         $v0, 0x59
    ctx->pc = 0x1ba364u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)89 << 16));
    // 0x1ba368: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1ba368u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1ba36c: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1ba36cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1ba370: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ba370u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ba374: 0x2442ed70  addiu       $v0, $v0, -0x1290
    ctx->pc = 0x1ba374u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294962544));
    // 0x1ba378: 0xc06b3dc  jal         func_1ACF70
    ctx->pc = 0x1BA378u;
    SET_GPR_U32(ctx, 31, 0x1BA380u);
    ctx->pc = 0x1BA37Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA378u;
            // 0x1ba37c: 0x438021  addu        $s0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ACF70u;
    if (runtime->hasFunction(0x1ACF70u)) {
        auto targetFn = runtime->lookupFunction(0x1ACF70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA380u; }
        if (ctx->pc != 0x1BA380u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACF70_0x1acf70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA380u; }
        if (ctx->pc != 0x1BA380u) { return; }
    }
    ctx->pc = 0x1BA380u;
label_1ba380:
    // 0x1ba380: 0xc06b878  jal         func_1AE1E0
    ctx->pc = 0x1BA380u;
    SET_GPR_U32(ctx, 31, 0x1BA388u);
    ctx->pc = 0x1AE1E0u;
    if (runtime->hasFunction(0x1AE1E0u)) {
        auto targetFn = runtime->lookupFunction(0x1AE1E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA388u; }
        if (ctx->pc != 0x1BA388u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AE1E0_0x1ae1e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA388u; }
        if (ctx->pc != 0x1BA388u) { return; }
    }
    ctx->pc = 0x1BA388u;
label_1ba388:
    // 0x1ba388: 0x86040000  lh          $a0, 0x0($s0)
    ctx->pc = 0x1ba388u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1ba38c: 0x2c81000c  sltiu       $at, $a0, 0xC
    ctx->pc = 0x1ba38cu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)12) ? 1 : 0);
    // 0x1ba390: 0x1020001e  beqz        $at, . + 4 + (0x1E << 2)
    ctx->pc = 0x1BA390u;
    {
        const bool branch_taken_0x1ba390 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA394u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA390u;
            // 0x1ba394: 0x3c030025  lui         $v1, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba390) {
            ctx->pc = 0x1BA40Cu;
            goto label_1ba40c;
        }
    }
    ctx->pc = 0x1BA398u;
    // 0x1ba398: 0x41080  sll         $v0, $a0, 2
    ctx->pc = 0x1ba398u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1ba39c: 0x246301f0  addiu       $v1, $v1, 0x1F0
    ctx->pc = 0x1ba39cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 496));
    // 0x1ba3a0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ba3a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ba3a4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1ba3a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ba3a8: 0x400008  jr          $v0
    ctx->pc = 0x1BA3A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA3B0u: goto label_1ba3b0;
            case 0x1BA3C0u: goto label_1ba3c0;
            case 0x1BA3D8u: goto label_1ba3d8;
            case 0x1BA40Cu: goto label_1ba40c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA3B0u;
label_1ba3b0:
    // 0x1ba3b0: 0xc06e214  jal         func_1B8850
    ctx->pc = 0x1BA3B0u;
    SET_GPR_U32(ctx, 31, 0x1BA3B8u);
    ctx->pc = 0x1BA3B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA3B0u;
            // 0x1ba3b4: 0x86040002  lh          $a0, 0x2($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B8850u;
    if (runtime->hasFunction(0x1B8850u)) {
        auto targetFn = runtime->lookupFunction(0x1B8850u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA3B8u; }
        if (ctx->pc != 0x1BA3B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B8850_0x1b8850(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA3B8u; }
        if (ctx->pc != 0x1BA3B8u) { return; }
    }
    ctx->pc = 0x1BA3B8u;
label_1ba3b8:
    // 0x1ba3b8: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1BA3B8u;
    {
        const bool branch_taken_0x1ba3b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA3BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA3B8u;
            // 0x1ba3bc: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba3b8) {
            ctx->pc = 0x1BA410u;
            goto label_1ba410;
        }
    }
    ctx->pc = 0x1BA3C0u;
label_1ba3c0:
    // 0x1ba3c0: 0x86050002  lh          $a1, 0x2($s0)
    ctx->pc = 0x1ba3c0u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1ba3c4: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1ba3c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba3c8: 0xc06b688  jal         func_1ADA20
    ctx->pc = 0x1BA3C8u;
    SET_GPR_U32(ctx, 31, 0x1BA3D0u);
    ctx->pc = 0x1BA3CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA3C8u;
            // 0x1ba3cc: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADA20u;
    if (runtime->hasFunction(0x1ADA20u)) {
        auto targetFn = runtime->lookupFunction(0x1ADA20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA3D0u; }
        if (ctx->pc != 0x1BA3D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADA20_0x1ada20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA3D0u; }
        if (ctx->pc != 0x1BA3D0u) { return; }
    }
    ctx->pc = 0x1BA3D0u;
label_1ba3d0:
    // 0x1ba3d0: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1BA3D0u;
    {
        const bool branch_taken_0x1ba3d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ba3d0) {
            ctx->pc = 0x1BA40Cu;
            goto label_1ba40c;
        }
    }
    ctx->pc = 0x1BA3D8u;
label_1ba3d8:
    // 0x1ba3d8: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1ba3d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1ba3dc: 0x9023ae71  lbu         $v1, -0x518F($at)
    ctx->pc = 0x1ba3dcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946417)));
    // 0x1ba3e0: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1BA3E0u;
    {
        const bool branch_taken_0x1ba3e0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA3E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA3E0u;
            // 0x1ba3e4: 0x2485fffc  addiu       $a1, $a0, -0x4 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967292));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba3e0) {
            ctx->pc = 0x1BA3F4u;
            goto label_1ba3f4;
        }
    }
    ctx->pc = 0x1BA3E8u;
    // 0x1ba3e8: 0x2482fffd  addiu       $v0, $a0, -0x3
    ctx->pc = 0x1ba3e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967293));
    // 0x1ba3ec: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1BA3ECu;
    {
        const bool branch_taken_0x1ba3ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1ba3ec) {
            ctx->pc = 0x1BA3FCu;
            goto label_1ba3fc;
        }
    }
    ctx->pc = 0x1BA3F4u;
label_1ba3f4:
    // 0x1ba3f4: 0xc06e910  jal         func_1BA440
    ctx->pc = 0x1BA3F4u;
    SET_GPR_U32(ctx, 31, 0x1BA3FCu);
    ctx->pc = 0x1BA3F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA3F4u;
            // 0x1ba3f8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BA440u;
    if (runtime->hasFunction(0x1BA440u)) {
        auto targetFn = runtime->lookupFunction(0x1BA440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA3FCu; }
        if (ctx->pc != 0x1BA3FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BA440_0x1ba440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA3FCu; }
        if (ctx->pc != 0x1BA3FCu) { return; }
    }
    ctx->pc = 0x1BA3FCu;
label_1ba3fc:
    // 0x1ba3fc: 0x86050002  lh          $a1, 0x2($s0)
    ctx->pc = 0x1ba3fcu;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x1ba400: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1ba400u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ba404: 0xc06b688  jal         func_1ADA20
    ctx->pc = 0x1BA404u;
    SET_GPR_U32(ctx, 31, 0x1BA40Cu);
    ctx->pc = 0x1BA408u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA404u;
            // 0x1ba408: 0x24060005  addiu       $a2, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1ADA20u;
    if (runtime->hasFunction(0x1ADA20u)) {
        auto targetFn = runtime->lookupFunction(0x1ADA20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA40Cu; }
        if (ctx->pc != 0x1BA40Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001ADA20_0x1ada20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BA40Cu; }
        if (ctx->pc != 0x1BA40Cu) { return; }
    }
    ctx->pc = 0x1BA40Cu;
label_1ba40c:
    // 0x1ba40c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1ba40cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1ba410:
    // 0x1ba410: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ba410u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ba414: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ba414u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ba418: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA418u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BA41Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA418u;
            // 0x1ba41c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA380u: goto label_1ba380;
            case 0x1BA388u: goto label_1ba388;
            case 0x1BA3B0u: goto label_1ba3b0;
            case 0x1BA3B8u: goto label_1ba3b8;
            case 0x1BA3C0u: goto label_1ba3c0;
            case 0x1BA3D0u: goto label_1ba3d0;
            case 0x1BA3D8u: goto label_1ba3d8;
            case 0x1BA3F4u: goto label_1ba3f4;
            case 0x1BA3FCu: goto label_1ba3fc;
            case 0x1BA40Cu: goto label_1ba40c;
            case 0x1BA410u: goto label_1ba410;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA420u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
