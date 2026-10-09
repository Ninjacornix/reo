#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00187798
// Address: 0x187798 - 0x187838
void sub_00187798_0x187798(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00187798_0x187798");
#endif

    switch (ctx->pc) {
        case 0x1877b8u: goto label_1877b8;
        case 0x1877c4u: goto label_1877c4;
        case 0x1877dcu: goto label_1877dc;
        case 0x187820u: goto label_187820;
        default: break;
    }

    ctx->pc = 0x187798u;

    // 0x187798: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x187798u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18779c: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x18779cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x1877a0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1877a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1877a4: 0x2451d980  addiu       $s1, $v0, -0x2680
    ctx->pc = 0x1877a4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294957440));
    // 0x1877a8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1877a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1877ac: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1877acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1877b0: 0xc062230  jal         func_1888C0
    ctx->pc = 0x1877B0u;
    SET_GPR_U32(ctx, 31, 0x1877B8u);
    ctx->pc = 0x1877B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1877B0u;
            // 0x1877b4: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1888C0u;
    if (runtime->hasFunction(0x1888C0u)) {
        auto targetFn = runtime->lookupFunction(0x1888C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1877B8u; }
        if (ctx->pc != 0x1877B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001888C0_0x1888c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1877B8u; }
        if (ctx->pc != 0x1877B8u) { return; }
    }
    ctx->pc = 0x1877B8u;
label_1877b8:
    // 0x1877b8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1877b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1877bc: 0xc0453c6  jal         func_114F18
    ctx->pc = 0x1877BCu;
    SET_GPR_U32(ctx, 31, 0x1877C4u);
    ctx->pc = 0x1877C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1877BCu;
            // 0x1877c0: 0x2625007f  addiu       $a1, $s1, 0x7F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 17), 127));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114F18u;
    if (runtime->hasFunction(0x114F18u)) {
        auto targetFn = runtime->lookupFunction(0x114F18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1877C4u; }
        if (ctx->pc != 0x1877C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114F18_0x114f18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1877C4u; }
        if (ctx->pc != 0x1877C4u) { return; }
    }
    ctx->pc = 0x1877C4u;
label_1877c4:
    // 0x1877c4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1877c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1877c8: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x1877c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1877cc: 0x1c600009  bgtz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1877CCu;
    {
        const bool branch_taken_0x1877cc = (GPR_S64(ctx, 3) > 0);
        ctx->pc = 0x1877D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1877CCu;
            // 0x1877d0: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1877cc) {
            ctx->pc = 0x1877F4u;
            goto label_1877f4;
        }
    }
    ctx->pc = 0x1877D4u;
    // 0x1877d4: 0xc0623b6  jal         func_188ED8
    ctx->pc = 0x1877D4u;
    SET_GPR_U32(ctx, 31, 0x1877DCu);
    ctx->pc = 0x188ED8u;
    if (runtime->hasFunction(0x188ED8u)) {
        auto targetFn = runtime->lookupFunction(0x188ED8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1877DCu; }
        if (ctx->pc != 0x1877DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188ED8_0x188ed8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1877DCu; }
        if (ctx->pc != 0x1877DCu) { return; }
    }
    ctx->pc = 0x1877DCu;
label_1877dc:
    // 0x1877dc: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1877dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1877e0: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1877E0u;
    {
        const bool branch_taken_0x1877e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1877E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1877E0u;
            // 0x1877e4: 0xae200008  sw          $zero, 0x8($s1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1877e0) {
            ctx->pc = 0x1877F0u;
            goto label_1877f0;
        }
    }
    ctx->pc = 0x1877E8u;
    // 0x1877e8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1877E8u;
    {
        const bool branch_taken_0x1877e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1877ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1877E8u;
            // 0x1877ec: 0x220102d  daddu       $v0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1877e8) {
            ctx->pc = 0x1877F4u;
            goto label_1877f4;
        }
    }
    ctx->pc = 0x1877F0u;
label_1877f0:
    // 0x1877f0: 0x220102d  daddu       $v0, $s1, $zero
    ctx->pc = 0x1877f0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_1877f4:
    // 0x1877f4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1877f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1877f8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1877f8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1877fc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1877fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x187800: 0x3e00008  jr          $ra
    ctx->pc = 0x187800u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x187804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x187800u;
            // 0x187804: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1877B8u: goto label_1877b8;
            case 0x1877C4u: goto label_1877c4;
            case 0x1877DCu: goto label_1877dc;
            case 0x1877F0u: goto label_1877f0;
            case 0x1877F4u: goto label_1877f4;
            case 0x187820u: goto label_187820;
            default: break;
        }
        return;
    }
    ctx->pc = 0x187808u;
    // 0x187808: 0x3c020029  lui         $v0, 0x29
    ctx->pc = 0x187808u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)41 << 16));
    // 0x18780c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x18780cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x187810: 0x8c44b8c4  lw          $a0, -0x473C($v0)
    ctx->pc = 0x187810u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294949060)));
    // 0x187814: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x187814u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x187818: 0xc045194  jal         func_114650
    ctx->pc = 0x187818u;
    SET_GPR_U32(ctx, 31, 0x187820u);
    ctx->pc = 0x114650u;
    if (runtime->hasFunction(0x114650u)) {
        auto targetFn = runtime->lookupFunction(0x114650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187820u; }
        if (ctx->pc != 0x187820u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114650_0x114650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187820u; }
        if (ctx->pc != 0x187820u) { return; }
    }
    ctx->pc = 0x187820u;
label_187820:
    // 0x187820: 0xf  sync
    ctx->pc = 0x187820u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x187824: 0x42000038  ei
    ctx->pc = 0x187824u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x187828: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x187828u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18782c: 0x3e00008  jr          $ra
    ctx->pc = 0x18782Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x187830u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18782Cu;
            // 0x187830: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1877B8u: goto label_1877b8;
            case 0x1877C4u: goto label_1877c4;
            case 0x1877DCu: goto label_1877dc;
            case 0x1877F0u: goto label_1877f0;
            case 0x1877F4u: goto label_1877f4;
            case 0x187820u: goto label_187820;
            default: break;
        }
        return;
    }
    ctx->pc = 0x187834u;
    // 0x187834: 0x0  nop
    ctx->pc = 0x187834u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
