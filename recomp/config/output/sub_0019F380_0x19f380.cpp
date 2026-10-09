#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019F380
// Address: 0x19f380 - 0x19f430
void sub_0019F380_0x19f380(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019F380_0x19f380");
#endif

    switch (ctx->pc) {
        case 0x19f390u: goto label_19f390;
        case 0x19f3a8u: goto label_19f3a8;
        case 0x19f3c4u: goto label_19f3c4;
        case 0x19f3dcu: goto label_19f3dc;
        case 0x19f3e8u: goto label_19f3e8;
        case 0x19f3f0u: goto label_19f3f0;
        case 0x19f3f8u: goto label_19f3f8;
        default: break;
    }

    ctx->pc = 0x19f380u;

    // 0x19f380: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x19f380u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x19f384: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x19f384u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x19f388: 0xc067d54  jal         func_19F550
    ctx->pc = 0x19F388u;
    SET_GPR_U32(ctx, 31, 0x19F390u);
    ctx->pc = 0x19F550u;
    if (runtime->hasFunction(0x19F550u)) {
        auto targetFn = runtime->lookupFunction(0x19F550u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F390u; }
        if (ctx->pc != 0x19F390u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019F550_0x19f550(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F390u; }
        if (ctx->pc != 0x19F390u) { return; }
    }
    ctx->pc = 0x19F390u;
label_19f390:
    // 0x19f390: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x19F390u;
    {
        const bool branch_taken_0x19f390 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x19f390) {
            ctx->pc = 0x19F3A0u;
            goto label_19f3a0;
        }
    }
    ctx->pc = 0x19F398u;
    // 0x19f398: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x19F398u;
    {
        const bool branch_taken_0x19f398 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F39Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F398u;
            // 0x19f39c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f398) {
            ctx->pc = 0x19F424u;
            goto label_19f424;
        }
    }
    ctx->pc = 0x19F3A0u;
label_19f3a0:
    // 0x19f3a0: 0xc063738  jal         func_18DCE0
    ctx->pc = 0x19F3A0u;
    SET_GPR_U32(ctx, 31, 0x19F3A8u);
    ctx->pc = 0x18DCE0u;
    if (runtime->hasFunction(0x18DCE0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F3A8u; }
        if (ctx->pc != 0x19F3A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCE0_0x18dce0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F3A8u; }
        if (ctx->pc != 0x19F3A8u) { return; }
    }
    ctx->pc = 0x19F3A8u;
label_19f3a8:
    // 0x19f3a8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f3a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f3ac: 0xac20fa04  sw          $zero, -0x5FC($at)
    ctx->pc = 0x19f3acu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965764), GPR_U32(ctx, 0));
    // 0x19f3b0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f3b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f3b4: 0xac20fa08  sw          $zero, -0x5F8($at)
    ctx->pc = 0x19f3b4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965768), GPR_U32(ctx, 0));
    // 0x19f3b8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f3b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f3bc: 0xc067dd4  jal         func_19F750
    ctx->pc = 0x19F3BCu;
    SET_GPR_U32(ctx, 31, 0x19F3C4u);
    ctx->pc = 0x19F3C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19F3BCu;
            // 0x19f3c0: 0xac20fa0c  sw          $zero, -0x5F4($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294965772), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19F750u;
    if (runtime->hasFunction(0x19F750u)) {
        auto targetFn = runtime->lookupFunction(0x19F750u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F3C4u; }
        if (ctx->pc != 0x19F3C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019F750_0x19f750(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F3C4u; }
        if (ctx->pc != 0x19F3C4u) { return; }
    }
    ctx->pc = 0x19F3C4u;
label_19f3c4:
    // 0x19f3c4: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x19f3c4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x19f3c8: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x19f3c8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19f3cc: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x19f3ccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19f3d0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x19f3d0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19f3d4: 0xc067e04  jal         func_19F810
    ctx->pc = 0x19F3D4u;
    SET_GPR_U32(ctx, 31, 0x19F3DCu);
    ctx->pc = 0x19F3D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19F3D4u;
            // 0x19f3d8: 0xc0402d  daddu       $t0, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19F810u;
    if (runtime->hasFunction(0x19F810u)) {
        auto targetFn = runtime->lookupFunction(0x19F810u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F3DCu; }
        if (ctx->pc != 0x19F3DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019F810_0x19f810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F3DCu; }
        if (ctx->pc != 0x19F3DCu) { return; }
    }
    ctx->pc = 0x19F3DCu;
label_19f3dc:
    // 0x19f3dc: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x19f3dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19f3e0: 0xc0680d4  jal         func_1A0350
    ctx->pc = 0x19F3E0u;
    SET_GPR_U32(ctx, 31, 0x19F3E8u);
    ctx->pc = 0x19F3E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19F3E0u;
            // 0x19f3e4: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A0350u;
    if (runtime->hasFunction(0x1A0350u)) {
        auto targetFn = runtime->lookupFunction(0x1A0350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F3E8u; }
        if (ctx->pc != 0x19F3E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A0350_0x1a0350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F3E8u; }
        if (ctx->pc != 0x19F3E8u) { return; }
    }
    ctx->pc = 0x19F3E8u;
label_19f3e8:
    // 0x19f3e8: 0xc068624  jal         func_1A1890
    ctx->pc = 0x19F3E8u;
    SET_GPR_U32(ctx, 31, 0x19F3F0u);
    ctx->pc = 0x1A1890u;
    if (runtime->hasFunction(0x1A1890u)) {
        auto targetFn = runtime->lookupFunction(0x1A1890u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F3F0u; }
        if (ctx->pc != 0x19F3F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A1890_0x1a1890(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F3F0u; }
        if (ctx->pc != 0x19F3F0u) { return; }
    }
    ctx->pc = 0x19F3F0u;
label_19f3f0:
    // 0x19f3f0: 0xc044cfc  jal         func_1133F0
    ctx->pc = 0x19F3F0u;
    SET_GPR_U32(ctx, 31, 0x19F3F8u);
    ctx->pc = 0x19F3F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19F3F0u;
            // 0x19f3f4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1133F0u;
    if (runtime->hasFunction(0x1133F0u)) {
        auto targetFn = runtime->lookupFunction(0x1133F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F3F8u; }
        if (ctx->pc != 0x19F3F8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001133F0_0x1133f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F3F8u; }
        if (ctx->pc != 0x19F3F8u) { return; }
    }
    ctx->pc = 0x19F3F8u;
label_19f3f8:
    // 0x19f3f8: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f3f8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f3fc: 0xac22f9fc  sw          $v0, -0x604($at)
    ctx->pc = 0x19f3fcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965756), GPR_U32(ctx, 2));
    // 0x19f400: 0x0  nop
    ctx->pc = 0x19f400u;
    // NOP
    // 0x19f404: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x19F404u;
    {
        const bool branch_taken_0x19f404 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x19f404) {
            ctx->pc = 0x19F3F0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_19f3f0;
        }
    }
    ctx->pc = 0x19F40Cu;
    // 0x19f40c: 0x24030080  addiu       $v1, $zero, 0x80
    ctx->pc = 0x19f40cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x19f410: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x19f410u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x19f414: 0xac230810  sw          $v1, 0x810($at)
    ctx->pc = 0x19f414u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 2064), GPR_U32(ctx, 3)); // MMIO: 0x10000810
    // 0x19f418: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19f418u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19f41c: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x19f41cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x19f420: 0xac200800  sw          $zero, 0x800($at)
    ctx->pc = 0x19f420u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 2048), GPR_U32(ctx, 0)); // MMIO: 0x10000800
label_19f424:
    // 0x19f424: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x19f424u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19f428: 0x3e00008  jr          $ra
    ctx->pc = 0x19F428u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19F42Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F428u;
            // 0x19f42c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19F390u: goto label_19f390;
            case 0x19F3A0u: goto label_19f3a0;
            case 0x19F3A8u: goto label_19f3a8;
            case 0x19F3C4u: goto label_19f3c4;
            case 0x19F3DCu: goto label_19f3dc;
            case 0x19F3E8u: goto label_19f3e8;
            case 0x19F3F0u: goto label_19f3f0;
            case 0x19F3F8u: goto label_19f3f8;
            case 0x19F424u: goto label_19f424;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19F430u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
