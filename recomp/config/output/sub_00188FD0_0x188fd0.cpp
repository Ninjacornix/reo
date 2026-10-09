#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00188FD0
// Address: 0x188fd0 - 0x189040
void sub_00188FD0_0x188fd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00188FD0_0x188fd0");
#endif

    switch (ctx->pc) {
        case 0x189018u: goto label_189018;
        case 0x18902cu: goto label_18902c;
        default: break;
    }

    ctx->pc = 0x188fd0u;

    // 0x188fd0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x188fd0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x188fd4: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x188fd4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x188fd8: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x188fd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x188fdc: 0x3c030029  lui         $v1, 0x29
    ctx->pc = 0x188fdcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)41 << 16));
    // 0x188fe0: 0x24500c00  addiu       $s0, $v0, 0xC00
    ctx->pc = 0x188fe0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 3072));
    // 0x188fe4: 0xac440c00  sw          $a0, 0xC00($v0)
    ctx->pc = 0x188fe4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3072), GPR_U32(ctx, 4));
    // 0x188fe8: 0x3c058000  lui         $a1, 0x8000
    ctx->pc = 0x188fe8u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)32768 << 16));
    // 0x188fec: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x188fecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x188ff0: 0x24640b88  addiu       $a0, $v1, 0xB88
    ctx->pc = 0x188ff0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), 2952));
    // 0x188ff4: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x188ff4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x188ff8: 0x34a51315  ori         $a1, $a1, 0x1315
    ctx->pc = 0x188ff8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)4885);
    // 0x188ffc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x188ffcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189000: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x189000u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189004: 0x24080280  addiu       $t0, $zero, 0x280
    ctx->pc = 0x189004u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x189008: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x189008u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18900c: 0x240a0280  addiu       $t2, $zero, 0x280
    ctx->pc = 0x18900cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 640));
    // 0x189010: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x189010u;
    SET_GPR_U32(ctx, 31, 0x189018u);
    ctx->pc = 0x189014u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189010u;
            // 0x189014: 0x582d  daddu       $t3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189018u; }
        if (ctx->pc != 0x189018u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189018u; }
        if (ctx->pc != 0x189018u) { return; }
    }
    ctx->pc = 0x189018u;
label_189018:
    // 0x189018: 0x4430005  bgezl       $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x189018u;
    {
        const bool branch_taken_0x189018 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x189018) {
            ctx->pc = 0x18901Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x189018u;
            // 0x18901c: 0x8e020004  lw          $v0, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x189030u;
            goto label_189030;
        }
    }
    ctx->pc = 0x189020u;
    // 0x189020: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x189020u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x189024: 0xc0625f6  jal         func_1897D8
    ctx->pc = 0x189024u;
    SET_GPR_U32(ctx, 31, 0x18902Cu);
    ctx->pc = 0x189028u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189024u;
            // 0x189028: 0x24841980  addiu       $a0, $a0, 0x1980 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 6528));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1897D8u;
    if (runtime->hasFunction(0x1897D8u)) {
        auto targetFn = runtime->lookupFunction(0x1897D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18902Cu; }
        if (ctx->pc != 0x18902Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001897D8_0x1897d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18902Cu; }
        if (ctx->pc != 0x18902Cu) { return; }
    }
    ctx->pc = 0x18902Cu;
label_18902c:
    // 0x18902c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x18902cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_189030:
    // 0x189030: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x189030u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x189034: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x189034u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x189038: 0x3e00008  jr          $ra
    ctx->pc = 0x189038u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18903Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189038u;
            // 0x18903c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189018u: goto label_189018;
            case 0x18902Cu: goto label_18902c;
            case 0x189030u: goto label_189030;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189040u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
