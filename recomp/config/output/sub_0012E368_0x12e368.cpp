#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012E368
// Address: 0x12e368 - 0x12e3c0
void sub_0012E368_0x12e368(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012E368_0x12e368");
#endif

    switch (ctx->pc) {
        case 0x12e390u: goto label_12e390;
        case 0x12e3a0u: goto label_12e3a0;
        case 0x12e3b0u: goto label_12e3b0;
        default: break;
    }

    ctx->pc = 0x12e368u;

    // 0x12e368: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x12e368u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12e36c: 0x51400  sll         $v0, $a1, 16
    ctx->pc = 0x12e36cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 16));
    // 0x12e370: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x12e370u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x12e374: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12e374u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e378: 0x27a70002  addiu       $a3, $sp, 0x2
    ctx->pc = 0x12e378u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 2));
    // 0x12e37c: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x12e37cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e380: 0x22403  sra         $a0, $v0, 16
    ctx->pc = 0x12e380u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 2), 16));
    // 0x12e384: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x12e384u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x12e388: 0xc049944  jal         func_126510
    ctx->pc = 0x12E388u;
    SET_GPR_U32(ctx, 31, 0x12E390u);
    ctx->pc = 0x12E38Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12E388u;
            // 0x12e38c: 0x3a0302d  daddu       $a2, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x126510u;
    if (runtime->hasFunction(0x126510u)) {
        auto targetFn = runtime->lookupFunction(0x126510u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12E390u; }
        if (ctx->pc != 0x12E390u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00126510_0x126510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12E390u; }
        if (ctx->pc != 0x12E390u) { return; }
    }
    ctx->pc = 0x12E390u;
label_12e390:
    // 0x12e390: 0x87a50000  lh          $a1, 0x0($sp)
    ctx->pc = 0x12e390u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12e394: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12e394u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12e398: 0xc04b8d6  jal         func_12E358
    ctx->pc = 0x12E398u;
    SET_GPR_U32(ctx, 31, 0x12E3A0u);
    ctx->pc = 0x12E39Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12E398u;
            // 0x12e39c: 0x87a60002  lh          $a2, 0x2($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12E358u;
    if (runtime->hasFunction(0x12E358u)) {
        auto targetFn = runtime->lookupFunction(0x12E358u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12E3A0u; }
        if (ctx->pc != 0x12E3A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012E358_0x12e358(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12E3A0u; }
        if (ctx->pc != 0x12E3A0u) { return; }
    }
    ctx->pc = 0x12E3A0u;
label_12e3a0:
    // 0x12e3a0: 0x8e040088  lw          $a0, 0x88($s0)
    ctx->pc = 0x12e3a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 136)));
    // 0x12e3a4: 0x87a50000  lh          $a1, 0x0($sp)
    ctx->pc = 0x12e3a4u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12e3a8: 0xc04b874  jal         func_12E1D0
    ctx->pc = 0x12E3A8u;
    SET_GPR_U32(ctx, 31, 0x12E3B0u);
    ctx->pc = 0x12E3ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12E3A8u;
            // 0x12e3ac: 0x87a60002  lh          $a2, 0x2($sp) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 2)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12E1D0u;
    if (runtime->hasFunction(0x12E1D0u)) {
        auto targetFn = runtime->lookupFunction(0x12E1D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12E3B0u; }
        if (ctx->pc != 0x12E3B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012E1D0_0x12e1d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12E3B0u; }
        if (ctx->pc != 0x12E3B0u) { return; }
    }
    ctx->pc = 0x12E3B0u;
label_12e3b0:
    // 0x12e3b0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x12e3b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12e3b4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12e3b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12e3b8: 0x3e00008  jr          $ra
    ctx->pc = 0x12E3B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12E3BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12E3B8u;
            // 0x12e3bc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12E390u: goto label_12e390;
            case 0x12E3A0u: goto label_12e3a0;
            case 0x12E3B0u: goto label_12e3b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12E3C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
