#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C388
// Address: 0x12c388 - 0x12c434
void sub_0012C388_0x12c388(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C388_0x12c388");
#endif

    switch (ctx->pc) {
        case 0x12c3b0u: goto label_12c3b0;
        case 0x12c3b8u: goto label_12c3b8;
        case 0x12c3c0u: goto label_12c3c0;
        case 0x12c3c8u: goto label_12c3c8;
        case 0x12c3d0u: goto label_12c3d0;
        case 0x12c3d8u: goto label_12c3d8;
        case 0x12c3e0u: goto label_12c3e0;
        case 0x12c3f8u: goto label_12c3f8;
        case 0x12c404u: goto label_12c404;
        case 0x12c410u: goto label_12c410;
        default: break;
    }

    ctx->pc = 0x12c388u;

    // 0x12c388: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c388u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c38c: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12c38cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12c390: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c390u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c394: 0x24630454  addiu       $v1, $v1, 0x454
    ctx->pc = 0x12c394u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1108));
    // 0x12c398: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x12c398u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12c39c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x12c39cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x12c3a0: 0x14400021  bnez        $v0, . + 4 + (0x21 << 2)
    ctx->pc = 0x12C3A0u;
    {
        const bool branch_taken_0x12c3a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12c3a0) {
            ctx->pc = 0x12C428u;
            goto label_12c428;
        }
    }
    ctx->pc = 0x12C3A8u;
    // 0x12c3a8: 0xc04adec  jal         func_12B7B0
    ctx->pc = 0x12C3A8u;
    SET_GPR_U32(ctx, 31, 0x12C3B0u);
    ctx->pc = 0x12B7B0u;
    if (runtime->hasFunction(0x12B7B0u)) {
        auto targetFn = runtime->lookupFunction(0x12B7B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3B0u; }
        if (ctx->pc != 0x12C3B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B7B0_0x12b7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3B0u; }
        if (ctx->pc != 0x12C3B0u) { return; }
    }
    ctx->pc = 0x12C3B0u;
label_12c3b0:
    // 0x12c3b0: 0xc04ae26  jal         func_12B898
    ctx->pc = 0x12C3B0u;
    SET_GPR_U32(ctx, 31, 0x12C3B8u);
    ctx->pc = 0x12B898u;
    if (runtime->hasFunction(0x12B898u)) {
        auto targetFn = runtime->lookupFunction(0x12B898u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3B8u; }
        if (ctx->pc != 0x12C3B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B898_0x12b898(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3B8u; }
        if (ctx->pc != 0x12C3B8u) { return; }
    }
    ctx->pc = 0x12C3B8u;
label_12c3b8:
    // 0x12c3b8: 0xc04ae5a  jal         func_12B968
    ctx->pc = 0x12C3B8u;
    SET_GPR_U32(ctx, 31, 0x12C3C0u);
    ctx->pc = 0x12B968u;
    if (runtime->hasFunction(0x12B968u)) {
        auto targetFn = runtime->lookupFunction(0x12B968u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3C0u; }
        if (ctx->pc != 0x12C3C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B968_0x12b968(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3C0u; }
        if (ctx->pc != 0x12C3C0u) { return; }
    }
    ctx->pc = 0x12C3C0u;
label_12c3c0:
    // 0x12c3c0: 0xc04aec2  jal         func_12BB08
    ctx->pc = 0x12C3C0u;
    SET_GPR_U32(ctx, 31, 0x12C3C8u);
    ctx->pc = 0x12BB08u;
    if (runtime->hasFunction(0x12BB08u)) {
        auto targetFn = runtime->lookupFunction(0x12BB08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3C8u; }
        if (ctx->pc != 0x12C3C8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BB08_0x12bb08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3C8u; }
        if (ctx->pc != 0x12C3C8u) { return; }
    }
    ctx->pc = 0x12C3C8u;
label_12c3c8:
    // 0x12c3c8: 0xc04ae8e  jal         func_12BA38
    ctx->pc = 0x12C3C8u;
    SET_GPR_U32(ctx, 31, 0x12C3D0u);
    ctx->pc = 0x12BA38u;
    if (runtime->hasFunction(0x12BA38u)) {
        auto targetFn = runtime->lookupFunction(0x12BA38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3D0u; }
        if (ctx->pc != 0x12C3D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BA38_0x12ba38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3D0u; }
        if (ctx->pc != 0x12C3D0u) { return; }
    }
    ctx->pc = 0x12C3D0u;
label_12c3d0:
    // 0x12c3d0: 0xc04aef6  jal         func_12BBD8
    ctx->pc = 0x12C3D0u;
    SET_GPR_U32(ctx, 31, 0x12C3D8u);
    ctx->pc = 0x12BBD8u;
    if (runtime->hasFunction(0x12BBD8u)) {
        auto targetFn = runtime->lookupFunction(0x12BBD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3D8u; }
        if (ctx->pc != 0x12C3D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BBD8_0x12bbd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3D8u; }
        if (ctx->pc != 0x12C3D8u) { return; }
    }
    ctx->pc = 0x12C3D8u;
label_12c3d8:
    // 0x12c3d8: 0xc04af2a  jal         func_12BCA8
    ctx->pc = 0x12C3D8u;
    SET_GPR_U32(ctx, 31, 0x12C3E0u);
    ctx->pc = 0x12BCA8u;
    if (runtime->hasFunction(0x12BCA8u)) {
        auto targetFn = runtime->lookupFunction(0x12BCA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3E0u; }
        if (ctx->pc != 0x12C3E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BCA8_0x12bca8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3E0u; }
        if (ctx->pc != 0x12C3E0u) { return; }
    }
    ctx->pc = 0x12C3E0u;
label_12c3e0:
    // 0x12c3e0: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12c3e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12c3e4: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x12c3e4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x12c3e8: 0x244204e8  addiu       $v0, $v0, 0x4E8
    ctx->pc = 0x12c3e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1256));
    // 0x12c3ec: 0x8c657d78  lw          $a1, 0x7D78($v1)
    ctx->pc = 0x12c3ecu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 32120)));
    // 0x12c3f0: 0xc04512c  jal         func_1144B0
    ctx->pc = 0x12C3F0u;
    SET_GPR_U32(ctx, 31, 0x12C3F8u);
    ctx->pc = 0x12C3F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C3F0u;
            // 0x12c3f4: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1144B0u;
    if (runtime->hasFunction(0x1144B0u)) {
        auto targetFn = runtime->lookupFunction(0x1144B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3F8u; }
        if (ctx->pc != 0x12C3F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3F8u; }
        if (ctx->pc != 0x12C3F8u) { return; }
    }
    ctx->pc = 0x12C3F8u;
label_12c3f8:
    // 0x12c3f8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x12c3f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c3fc: 0xc05077c  jal         func_141DF0
    ctx->pc = 0x12C3FCu;
    SET_GPR_U32(ctx, 31, 0x12C404u);
    ctx->pc = 0x12C400u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C3FCu;
            // 0x12c400: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141DF0u;
    if (runtime->hasFunction(0x141DF0u)) {
        auto targetFn = runtime->lookupFunction(0x141DF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C404u; }
        if (ctx->pc != 0x12C404u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141DF0_0x141df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C404u; }
        if (ctx->pc != 0x12C404u) { return; }
    }
    ctx->pc = 0x12C404u;
label_12c404:
    // 0x12c404: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x12c404u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c408: 0xc050782  jal         func_141E08
    ctx->pc = 0x12C408u;
    SET_GPR_U32(ctx, 31, 0x12C410u);
    ctx->pc = 0x12C40Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C408u;
            // 0x12c40c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141E08u;
    if (runtime->hasFunction(0x141E08u)) {
        auto targetFn = runtime->lookupFunction(0x141E08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C410u; }
        if (ctx->pc != 0x12C410u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141E08_0x141e08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C410u; }
        if (ctx->pc != 0x12C410u) { return; }
    }
    ctx->pc = 0x12C410u;
label_12c410:
    // 0x12c410: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x12c410u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x12c414: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c414u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c418: 0x0  nop
    ctx->pc = 0x12c418u;
    // NOP
    // 0x12c41c: 0x805084e  j           func_142138
    ctx->pc = 0x12C41Cu;
    ctx->pc = 0x12C420u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C41Cu;
            // 0x12c420: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142138u;
    if (runtime->hasFunction(0x142138u)) {
        auto targetFn = runtime->lookupFunction(0x142138u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00142138_0x142138(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C424u;
    // 0x12c424: 0x0  nop
    ctx->pc = 0x12c424u;
    // NOP
label_12c428:
    // 0x12c428: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c428u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c42c: 0x3e00008  jr          $ra
    ctx->pc = 0x12C42Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C430u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12C42Cu;
            // 0x12c430: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C3B0u: goto label_12c3b0;
            case 0x12C3B8u: goto label_12c3b8;
            case 0x12C3C0u: goto label_12c3c0;
            case 0x12C3C8u: goto label_12c3c8;
            case 0x12C3D0u: goto label_12c3d0;
            case 0x12C3D8u: goto label_12c3d8;
            case 0x12C3E0u: goto label_12c3e0;
            case 0x12C3F8u: goto label_12c3f8;
            case 0x12C404u: goto label_12c404;
            case 0x12C410u: goto label_12c410;
            case 0x12C428u: goto label_12c428;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C434u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
