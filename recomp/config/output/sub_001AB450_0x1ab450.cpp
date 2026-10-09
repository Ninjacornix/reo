#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AB450
// Address: 0x1ab450 - 0x1ab4f0
void sub_001AB450_0x1ab450(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AB450_0x1ab450");
#endif

    switch (ctx->pc) {
        case 0x1ab478u: goto label_1ab478;
        case 0x1ab480u: goto label_1ab480;
        case 0x1ab4b4u: goto label_1ab4b4;
        case 0x1ab4bcu: goto label_1ab4bc;
        default: break;
    }

    ctx->pc = 0x1ab450u;

    // 0x1ab450: 0x27bdfed0  addiu       $sp, $sp, -0x130
    ctx->pc = 0x1ab450u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966992));
    // 0x1ab454: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1ab454u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab458: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1ab458u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1ab45c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1ab45cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1ab460: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ab460u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ab464: 0x24a5fd10  addiu       $a1, $a1, -0x2F0
    ctx->pc = 0x1ab464u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294966544));
    // 0x1ab468: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1ab468u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab46c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ab46cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ab470: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1AB470u;
    SET_GPR_U32(ctx, 31, 0x1AB478u);
    ctx->pc = 0x1AB474u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB470u;
            // 0x1ab474: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB478u; }
        if (ctx->pc != 0x1AB478u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB478u; }
        if (ctx->pc != 0x1AB478u) { return; }
    }
    ctx->pc = 0x1AB478u;
label_1ab478:
    // 0x1ab478: 0xc06acbc  jal         func_1AB2F0
    ctx->pc = 0x1AB478u;
    SET_GPR_U32(ctx, 31, 0x1AB480u);
    ctx->pc = 0x1AB47Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB478u;
            // 0x1ab47c: 0x27a40030  addiu       $a0, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AB2F0u;
    if (runtime->hasFunction(0x1AB2F0u)) {
        auto targetFn = runtime->lookupFunction(0x1AB2F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB480u; }
        if (ctx->pc != 0x1AB480u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB2F0_0x1ab2f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB480u; }
        if (ctx->pc != 0x1AB480u) { return; }
    }
    ctx->pc = 0x1AB480u;
label_1ab480:
    // 0x1ab480: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AB480u;
    {
        const bool branch_taken_0x1ab480 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1AB484u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB480u;
            // 0x1ab484: 0x3c010032  lui         $at, 0x32 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab480) {
            ctx->pc = 0x1AB490u;
            goto label_1ab490;
        }
    }
    ctx->pc = 0x1AB488u;
    // 0x1ab488: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1AB488u;
    {
        const bool branch_taken_0x1ab488 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AB48Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB488u;
            // 0x1ab48c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ab488) {
            ctx->pc = 0x1AB4D4u;
            goto label_1ab4d4;
        }
    }
    ctx->pc = 0x1AB490u;
label_1ab490:
    // 0x1ab490: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1ab490u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab494: 0x8c234468  lw          $v1, 0x4468($at)
    ctx->pc = 0x1ab494u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17512)));
    // 0x1ab498: 0x240210c0  addiu       $v0, $zero, 0x10C0
    ctx->pc = 0x1ab498u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4288));
    // 0x1ab49c: 0x511018  mult        $v0, $v0, $s1
    ctx->pc = 0x1ab49cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 17); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1ab4a0: 0x26300005  addiu       $s0, $s1, 0x5
    ctx->pc = 0x1ab4a0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 17), 5));
    // 0x1ab4a4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1ab4a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ab4a8: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x1ab4a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1ab4ac: 0xc04a1ce  jal         func_128738
    ctx->pc = 0x1AB4ACu;
    SET_GPR_U32(ctx, 31, 0x1AB4B4u);
    ctx->pc = 0x1AB4B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB4ACu;
            // 0x1ab4b0: 0x623821  addu        $a3, $v1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128738u;
    if (runtime->hasFunction(0x128738u)) {
        auto targetFn = runtime->lookupFunction(0x128738u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB4B4u; }
        if (ctx->pc != 0x1AB4B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128738_0x128738(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB4B4u; }
        if (ctx->pc != 0x1AB4B4u) { return; }
    }
    ctx->pc = 0x1AB4B4u;
label_1ab4b4:
    // 0x1ab4b4: 0xc04a2c6  jal         func_128B18
    ctx->pc = 0x1AB4B4u;
    SET_GPR_U32(ctx, 31, 0x1AB4BCu);
    ctx->pc = 0x1AB4B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB4B4u;
            // 0x1ab4b8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x128B18u;
    if (runtime->hasFunction(0x128B18u)) {
        auto targetFn = runtime->lookupFunction(0x128B18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB4BCu; }
        if (ctx->pc != 0x1AB4BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00128B18_0x128b18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AB4BCu; }
        if (ctx->pc != 0x1AB4BCu) { return; }
    }
    ctx->pc = 0x1AB4BCu;
label_1ab4bc:
    // 0x1ab4bc: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1ab4bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1ab4c0: 0x0  nop
    ctx->pc = 0x1ab4c0u;
    // NOP
    // 0x1ab4c4: 0x0  nop
    ctx->pc = 0x1ab4c4u;
    // NOP
    // 0x1ab4c8: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1AB4C8u;
    {
        const bool branch_taken_0x1ab4c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1ab4c8) {
            ctx->pc = 0x1AB4B4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ab4b4;
        }
    }
    ctx->pc = 0x1AB4D0u;
    // 0x1ab4d0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ab4d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1ab4d4:
    // 0x1ab4d4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1ab4d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ab4d8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ab4d8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ab4dc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ab4dcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ab4e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1AB4E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AB4E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AB4E0u;
            // 0x1ab4e4: 0x27bd0130  addiu       $sp, $sp, 0x130 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AB478u: goto label_1ab478;
            case 0x1AB480u: goto label_1ab480;
            case 0x1AB490u: goto label_1ab490;
            case 0x1AB4B4u: goto label_1ab4b4;
            case 0x1AB4BCu: goto label_1ab4bc;
            case 0x1AB4D4u: goto label_1ab4d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AB4E8u;
    // 0x1ab4e8: 0x0  nop
    ctx->pc = 0x1ab4e8u;
    // NOP
    // 0x1ab4ec: 0x0  nop
    ctx->pc = 0x1ab4ecu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
