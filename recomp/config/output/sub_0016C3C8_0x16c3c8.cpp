#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016C3C8
// Address: 0x16c3c8 - 0x16c438
void sub_0016C3C8_0x16c3c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016C3C8_0x16c3c8");
#endif

    switch (ctx->pc) {
        case 0x16c3e0u: goto label_16c3e0;
        case 0x16c3f0u: goto label_16c3f0;
        default: break;
    }

    ctx->pc = 0x16c3c8u;

    // 0x16c3c8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16c3c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16c3cc: 0x2405001c  addiu       $a1, $zero, 0x1C
    ctx->pc = 0x16c3ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 28));
    // 0x16c3d0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x16c3d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16c3d4: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x16c3d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x16c3d8: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16C3D8u;
    SET_GPR_U32(ctx, 31, 0x16C3E0u);
    ctx->pc = 0x16C3DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C3D8u;
            // 0x16c3dc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C3E0u; }
        if (ctx->pc != 0x16C3E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C3E0u; }
        if (ctx->pc != 0x16C3E0u) { return; }
    }
    ctx->pc = 0x16C3E0u;
label_16c3e0:
    // 0x16c3e0: 0x10400011  beqz        $v0, . + 4 + (0x11 << 2)
    ctx->pc = 0x16C3E0u;
    {
        const bool branch_taken_0x16c3e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16C3E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C3E0u;
            // 0x16c3e4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c3e0) {
            ctx->pc = 0x16C428u;
            goto label_16c428;
        }
    }
    ctx->pc = 0x16C3E8u;
    // 0x16c3e8: 0xc05a66e  jal         func_1699B8
    ctx->pc = 0x16C3E8u;
    SET_GPR_U32(ctx, 31, 0x16C3F0u);
    ctx->pc = 0x1699B8u;
    if (runtime->hasFunction(0x1699B8u)) {
        auto targetFn = runtime->lookupFunction(0x1699B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C3F0u; }
        if (ctx->pc != 0x16C3F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001699B8_0x1699b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C3F0u; }
        if (ctx->pc != 0x16C3F0u) { return; }
    }
    ctx->pc = 0x16C3F0u;
label_16c3f0:
    // 0x16c3f0: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x16c3f0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x16c3f4: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x16c3f4u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c3f8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16c3f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c3fc: 0x10600006  beqz        $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x16C3FCu;
    {
        const bool branch_taken_0x16c3fc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x16C400u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C3FCu;
            // 0x16c400: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c3fc) {
            ctx->pc = 0x16C418u;
            goto label_16c418;
        }
    }
    ctx->pc = 0x16C404u;
    // 0x16c404: 0x1c600004  bgtz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x16C404u;
    {
        const bool branch_taken_0x16c404 = (GPR_S64(ctx, 3) > 0);
        ctx->pc = 0x16C408u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C404u;
            // 0x16c408: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c404) {
            ctx->pc = 0x16C418u;
            goto label_16c418;
        }
    }
    ctx->pc = 0x16C40Cu;
    // 0x16c40c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x16c40cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x16c410: 0x10620006  beq         $v1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16C410u;
    {
        const bool branch_taken_0x16c410 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x16C414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C410u;
            // 0x16c414: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16c410) {
            ctx->pc = 0x16C42Cu;
            goto label_16c42c;
        }
    }
    ctx->pc = 0x16C418u;
label_16c418:
    // 0x16c418: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16c418u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c41c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16c41cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c420: 0x805afb2  j           func_16BEC8
    ctx->pc = 0x16C420u;
    ctx->pc = 0x16C424u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16C420u;
            // 0x16c424: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16BEC8u;
    if (runtime->hasFunction(0x16BEC8u)) {
        auto targetFn = runtime->lookupFunction(0x16BEC8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0016BEC8_0x16bec8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16C428u;
label_16c428:
    // 0x16c428: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16c428u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_16c42c:
    // 0x16c42c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x16c42cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c430: 0x3e00008  jr          $ra
    ctx->pc = 0x16C430u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16C434u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16C430u;
            // 0x16c434: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16C3E0u: goto label_16c3e0;
            case 0x16C3F0u: goto label_16c3f0;
            case 0x16C418u: goto label_16c418;
            case 0x16C428u: goto label_16c428;
            case 0x16C42Cu: goto label_16c42c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16C438u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
