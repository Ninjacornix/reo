#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00128620
// Address: 0x128620 - 0x1286bc
void sub_00128620_0x128620(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00128620_0x128620");
#endif

    switch (ctx->pc) {
        case 0x128664u: goto label_128664;
        case 0x128678u: goto label_128678;
        case 0x128680u: goto label_128680;
        case 0x128688u: goto label_128688;
        case 0x128690u: goto label_128690;
        default: break;
    }

    ctx->pc = 0x128620u;

    // 0x128620: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x128620u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x128624: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x128624u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128628: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x128628u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12862c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x12862cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128630: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x128630u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x128634: 0x804a190  j           func_128640
    ctx->pc = 0x128634u;
    ctx->pc = 0x128638u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128634u;
            // 0x128638: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128640u;
    goto label_128640;
    ctx->pc = 0x12863Cu;
    // 0x12863c: 0x0  nop
    ctx->pc = 0x12863cu;
    // NOP
label_128640:
    // 0x128640: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x128640u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x128644: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x128644u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x128648: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x128648u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12864c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x12864cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x128650: 0x24110004  addiu       $s1, $zero, 0x4
    ctx->pc = 0x128650u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x128654: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x128654u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x128658: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x128658u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x12865c: 0xc04a1b0  jal         func_1286C0
    ctx->pc = 0x12865Cu;
    SET_GPR_U32(ctx, 31, 0x128664u);
    ctx->pc = 0x128660u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12865Cu;
            // 0x128660: 0x24120003  addiu       $s2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1286C0u;
    if (runtime->hasFunction(0x1286C0u)) {
        auto targetFn = runtime->lookupFunction(0x1286C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128664u; }
        if (ctx->pc != 0x128664u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001286C0_0x1286c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128664u; }
        if (ctx->pc != 0x128664u) { return; }
    }
    ctx->pc = 0x128664u;
label_128664:
    // 0x128664: 0x4410008  bgez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x128664u;
    {
        const bool branch_taken_0x128664 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x128664) {
            ctx->pc = 0x128688u;
            goto label_128688;
        }
    }
    ctx->pc = 0x12866Cu;
    // 0x12866c: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x12866Cu;
    {
        const bool branch_taken_0x12866c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x128670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12866Cu;
            // 0x128670: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12866c) {
            ctx->pc = 0x1286A8u;
            goto label_1286a8;
        }
    }
    ctx->pc = 0x128674u;
    // 0x128674: 0x0  nop
    ctx->pc = 0x128674u;
    // NOP
label_128678:
    // 0x128678: 0xc04afbe  jal         func_12BEF8
    ctx->pc = 0x128678u;
    SET_GPR_U32(ctx, 31, 0x128680u);
    ctx->pc = 0x12BEF8u;
    if (runtime->hasFunction(0x12BEF8u)) {
        auto targetFn = runtime->lookupFunction(0x12BEF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128680u; }
        if (ctx->pc != 0x128680u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BEF8_0x12bef8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128680u; }
        if (ctx->pc != 0x128680u) { return; }
    }
    ctx->pc = 0x128680u;
label_128680:
    // 0x128680: 0xc04a16a  jal         func_1285A8
    ctx->pc = 0x128680u;
    SET_GPR_U32(ctx, 31, 0x128688u);
    ctx->pc = 0x1285A8u;
    if (runtime->hasFunction(0x1285A8u)) {
        auto targetFn = runtime->lookupFunction(0x1285A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128688u; }
        if (ctx->pc != 0x128688u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001285A8_0x1285a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128688u; }
        if (ctx->pc != 0x128688u) { return; }
    }
    ctx->pc = 0x128688u;
label_128688:
    // 0x128688: 0xc04a2c6  jal         func_128B18
    ctx->pc = 0x128688u;
    SET_GPR_U32(ctx, 31, 0x128690u);
    ctx->pc = 0x12868Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x128688u;
            // 0x12868c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128B18u;
    if (runtime->hasFunction(0x128B18u)) {
        auto targetFn = runtime->lookupFunction(0x128B18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128690u; }
        if (ctx->pc != 0x128690u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128B18_0x128b18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128690u; }
        if (ctx->pc != 0x128690u) { return; }
    }
    ctx->pc = 0x128690u;
label_128690:
    // 0x128690: 0x10520003  beq         $v0, $s2, . + 4 + (0x3 << 2)
    ctx->pc = 0x128690u;
    {
        const bool branch_taken_0x128690 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 18));
        ctx->pc = 0x128694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128690u;
            // 0x128694: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128690) {
            ctx->pc = 0x1286A0u;
            goto label_1286a0;
        }
    }
    ctx->pc = 0x128698u;
    // 0x128698: 0x1451fff7  bne         $v0, $s1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x128698u;
    {
        const bool branch_taken_0x128698 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 17));
        ctx->pc = 0x12869Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x128698u;
            // 0x12869c: 0x2403ffff  addiu       $v1, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x128698) {
            ctx->pc = 0x128678u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_128678;
        }
    }
    ctx->pc = 0x1286A0u;
label_1286a0:
    // 0x1286a0: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1286a0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1286a4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1286a4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1286a8:
    // 0x1286a8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1286a8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1286ac: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1286acu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1286b0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1286b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1286b4: 0x3e00008  jr          $ra
    ctx->pc = 0x1286B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1286B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1286B4u;
            // 0x1286b8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x128640u: goto label_128640;
            case 0x128664u: goto label_128664;
            case 0x128678u: goto label_128678;
            case 0x128680u: goto label_128680;
            case 0x128688u: goto label_128688;
            case 0x128690u: goto label_128690;
            case 0x1286A0u: goto label_1286a0;
            case 0x1286A8u: goto label_1286a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1286BCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
