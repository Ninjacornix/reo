#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F870
// Address: 0x15f870 - 0x15f8e0
void sub_0015F870_0x15f870(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F870_0x15f870");
#endif

    switch (ctx->pc) {
        case 0x15f894u: goto label_15f894;
        case 0x15f8a8u: goto label_15f8a8;
        case 0x15f8b0u: goto label_15f8b0;
        case 0x15f8c4u: goto label_15f8c4;
        case 0x15f8ccu: goto label_15f8cc;
        default: break;
    }

    ctx->pc = 0x15f870u;

    // 0x15f870: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x15f870u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x15f874: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x15f874u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x15f878: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f878u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f87c: 0x2450ef48  addiu       $s0, $v0, -0x10B8
    ctx->pc = 0x15f87cu;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294963016));
    // 0x15f880: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x15f880u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x15f884: 0x10600012  beqz        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x15F884u;
    {
        const bool branch_taken_0x15f884 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x15F888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F884u;
            // 0x15f888: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15f884) {
            ctx->pc = 0x15F8D0u;
            goto label_15f8d0;
        }
    }
    ctx->pc = 0x15F88Cu;
    // 0x15f88c: 0xc057e38  jal         func_15F8E0
    ctx->pc = 0x15F88Cu;
    SET_GPR_U32(ctx, 31, 0x15F894u);
    ctx->pc = 0x15F8E0u;
    if (runtime->hasFunction(0x15F8E0u)) {
        auto targetFn = runtime->lookupFunction(0x15F8E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F894u; }
        if (ctx->pc != 0x15F894u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F8E0_0x15f8e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F894u; }
        if (ctx->pc != 0x15F894u) { return; }
    }
    ctx->pc = 0x15F894u;
label_15f894:
    // 0x15f894: 0x3c060027  lui         $a2, 0x27
    ctx->pc = 0x15f894u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)39 << 16));
    // 0x15f898: 0x24c6c640  addiu       $a2, $a2, -0x39C0
    ctx->pc = 0x15f898u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294952512));
    // 0x15f89c: 0x24054000  addiu       $a1, $zero, 0x4000
    ctx->pc = 0x15f89cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x15f8a0: 0xc057e40  jal         func_15F900
    ctx->pc = 0x15F8A0u;
    SET_GPR_U32(ctx, 31, 0x15F8A8u);
    ctx->pc = 0x15F8A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F8A0u;
            // 0x15f8a4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F900u;
    if (runtime->hasFunction(0x15F900u)) {
        auto targetFn = runtime->lookupFunction(0x15F900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F8A8u; }
        if (ctx->pc != 0x15F8A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F900_0x15f900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F8A8u; }
        if (ctx->pc != 0x15F8A8u) { return; }
    }
    ctx->pc = 0x15F8A8u;
label_15f8a8:
    // 0x15f8a8: 0xc057e74  jal         func_15F9D0
    ctx->pc = 0x15F8A8u;
    SET_GPR_U32(ctx, 31, 0x15F8B0u);
    ctx->pc = 0x15F8ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F8A8u;
            // 0x15f8ac: 0x24040008  addiu       $a0, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F9D0u;
    if (runtime->hasFunction(0x15F9D0u)) {
        auto targetFn = runtime->lookupFunction(0x15F9D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F8B0u; }
        if (ctx->pc != 0x15F8B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F9D0_0x15f9d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F8B0u; }
        if (ctx->pc != 0x15F8B0u) { return; }
    }
    ctx->pc = 0x15F8B0u;
label_15f8b0:
    // 0x15f8b0: 0x3c040027  lui         $a0, 0x27
    ctx->pc = 0x15f8b0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)39 << 16));
    // 0x15f8b4: 0x24848640  addiu       $a0, $a0, -0x79C0
    ctx->pc = 0x15f8b4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936128));
    // 0x15f8b8: 0x24054000  addiu       $a1, $zero, 0x4000
    ctx->pc = 0x15f8b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x15f8bc: 0xc057e5a  jal         func_15F968
    ctx->pc = 0x15F8BCu;
    SET_GPR_U32(ctx, 31, 0x15F8C4u);
    ctx->pc = 0x15F8C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F8BCu;
            // 0x15f8c0: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F968u;
    if (runtime->hasFunction(0x15F968u)) {
        auto targetFn = runtime->lookupFunction(0x15F968u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F8C4u; }
        if (ctx->pc != 0x15F8C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F968_0x15f968(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F8C4u; }
        if (ctx->pc != 0x15F8C4u) { return; }
    }
    ctx->pc = 0x15F8C4u;
label_15f8c4:
    // 0x15f8c4: 0xc057e74  jal         func_15F9D0
    ctx->pc = 0x15F8C4u;
    SET_GPR_U32(ctx, 31, 0x15F8CCu);
    ctx->pc = 0x15F8C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F8C4u;
            // 0x15f8c8: 0x24040009  addiu       $a0, $zero, 0x9 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 9));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F9D0u;
    if (runtime->hasFunction(0x15F9D0u)) {
        auto targetFn = runtime->lookupFunction(0x15F9D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F8CCu; }
        if (ctx->pc != 0x15F8CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F9D0_0x15f9d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F8CCu; }
        if (ctx->pc != 0x15F8CCu) { return; }
    }
    ctx->pc = 0x15F8CCu;
label_15f8cc:
    // 0x15f8cc: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x15f8ccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
label_15f8d0:
    // 0x15f8d0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f8d0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f8d4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x15f8d4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f8d8: 0x3e00008  jr          $ra
    ctx->pc = 0x15F8D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15F8DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15F8D8u;
            // 0x15f8dc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15F894u: goto label_15f894;
            case 0x15F8A8u: goto label_15f8a8;
            case 0x15F8B0u: goto label_15f8b0;
            case 0x15F8C4u: goto label_15f8c4;
            case 0x15F8CCu: goto label_15f8cc;
            case 0x15F8D0u: goto label_15f8d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15F8E0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
