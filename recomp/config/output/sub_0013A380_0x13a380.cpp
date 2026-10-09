#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013A380
// Address: 0x13a380 - 0x13a418
void sub_0013A380_0x13a380(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013A380_0x13a380");
#endif

    switch (ctx->pc) {
        case 0x13a3a4u: goto label_13a3a4;
        case 0x13a3b0u: goto label_13a3b0;
        case 0x13a3b8u: goto label_13a3b8;
        case 0x13a3d0u: goto label_13a3d0;
        case 0x13a3e4u: goto label_13a3e4;
        default: break;
    }

    ctx->pc = 0x13a380u;

    // 0x13a380: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13a380u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13a384: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13a384u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13a388: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x13a388u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a38c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13a38cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13a390: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13a390u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13a394: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13a394u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13a398: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x13a398u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x13a39c: 0xc042c56  jal         func_10B158
    ctx->pc = 0x13A39Cu;
    SET_GPR_U32(ctx, 31, 0x13A3A4u);
    ctx->pc = 0x13A3A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A39Cu;
            // 0x13a3a0: 0x80982d  daddu       $s3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A3A4u; }
        if (ctx->pc != 0x13A3A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A3A4u; }
        if (ctx->pc != 0x13A3A4u) { return; }
    }
    ctx->pc = 0x13A3A4u;
label_13a3a4:
    // 0x13a3a4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x13a3a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a3a8: 0xc042c56  jal         func_10B158
    ctx->pc = 0x13A3A8u;
    SET_GPR_U32(ctx, 31, 0x13A3B0u);
    ctx->pc = 0x13A3ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A3A8u;
            // 0x13a3ac: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A3B0u; }
        if (ctx->pc != 0x13A3B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A3B0u; }
        if (ctx->pc != 0x13A3B0u) { return; }
    }
    ctx->pc = 0x13A3B0u;
label_13a3b0:
    // 0x13a3b0: 0x12220003  beq         $s1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x13A3B0u;
    {
        const bool branch_taken_0x13a3b0 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        if (branch_taken_0x13a3b0) {
            ctx->pc = 0x13A3C0u;
            goto label_13a3c0;
        }
    }
    ctx->pc = 0x13A3B8u;
label_13a3b8:
    // 0x13a3b8: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x13A3B8u;
    {
        const bool branch_taken_0x13a3b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13A3BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A3B8u;
            // 0x13a3bc: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a3b8) {
            ctx->pc = 0x13A3F8u;
            goto label_13a3f8;
        }
    }
    ctx->pc = 0x13A3C0u;
label_13a3c0:
    // 0x13a3c0: 0x1a20000c  blez        $s1, . + 4 + (0xC << 2)
    ctx->pc = 0x13A3C0u;
    {
        const bool branch_taken_0x13a3c0 = (GPR_S64(ctx, 17) <= 0);
        ctx->pc = 0x13A3C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A3C0u;
            // 0x13a3c4: 0x802d  daddu       $s0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a3c0) {
            ctx->pc = 0x13A3F4u;
            goto label_13a3f4;
        }
    }
    ctx->pc = 0x13A3C8u;
    // 0x13a3c8: 0x2501821  addu        $v1, $s2, $s0
    ctx->pc = 0x13a3c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
    // 0x13a3cc: 0x0  nop
    ctx->pc = 0x13a3ccu;
    // NOP
label_13a3d0:
    // 0x13a3d0: 0x2701021  addu        $v0, $s3, $s0
    ctx->pc = 0x13a3d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 16)));
    // 0x13a3d4: 0x80650000  lb          $a1, 0x0($v1)
    ctx->pc = 0x13a3d4u;
    SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13a3d8: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x13a3d8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x13a3dc: 0xc04e8ca  jal         func_13A328
    ctx->pc = 0x13A3DCu;
    SET_GPR_U32(ctx, 31, 0x13A3E4u);
    ctx->pc = 0x13A3E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13A3DCu;
            // 0x13a3e0: 0x80440000  lb          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13A328u;
    if (runtime->hasFunction(0x13A328u)) {
        auto targetFn = runtime->lookupFunction(0x13A328u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A3E4u; }
        if (ctx->pc != 0x13A3E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013A328_0x13a328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A3E4u; }
        if (ctx->pc != 0x13A3E4u) { return; }
    }
    ctx->pc = 0x13A3E4u;
label_13a3e4:
    // 0x13a3e4: 0x1440fff4  bnez        $v0, . + 4 + (-0xC << 2)
    ctx->pc = 0x13A3E4u;
    {
        const bool branch_taken_0x13a3e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13A3E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A3E4u;
            // 0x13a3e8: 0x211182a  slt         $v1, $s0, $s1 (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a3e4) {
            ctx->pc = 0x13A3B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13a3b8;
        }
    }
    ctx->pc = 0x13A3ECu;
    // 0x13a3ec: 0x1460fff8  bnez        $v1, . + 4 + (-0x8 << 2)
    ctx->pc = 0x13A3ECu;
    {
        const bool branch_taken_0x13a3ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x13A3F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A3ECu;
            // 0x13a3f0: 0x2501821  addu        $v1, $s2, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a3ec) {
            ctx->pc = 0x13A3D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13a3d0;
        }
    }
    ctx->pc = 0x13A3F4u;
label_13a3f4:
    // 0x13a3f4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13a3f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_13a3f8:
    // 0x13a3f8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13a3f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13a3fc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13a3fcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13a400: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13a400u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13a404: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13a404u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13a408: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x13a408u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13a40c: 0x3e00008  jr          $ra
    ctx->pc = 0x13A40Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13A410u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A40Cu;
            // 0x13a410: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13A3A4u: goto label_13a3a4;
            case 0x13A3B0u: goto label_13a3b0;
            case 0x13A3B8u: goto label_13a3b8;
            case 0x13A3C0u: goto label_13a3c0;
            case 0x13A3D0u: goto label_13a3d0;
            case 0x13A3E4u: goto label_13a3e4;
            case 0x13A3F4u: goto label_13a3f4;
            case 0x13A3F8u: goto label_13a3f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13A414u;
    // 0x13a414: 0x0  nop
    ctx->pc = 0x13a414u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
