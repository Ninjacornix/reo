#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BB160
// Address: 0x1bb160 - 0x1bb1c0
void sub_001BB160_0x1bb160(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BB160_0x1bb160");
#endif

    switch (ctx->pc) {
        case 0x1bb170u: goto label_1bb170;
        case 0x1bb17cu: goto label_1bb17c;
        case 0x1bb188u: goto label_1bb188;
        case 0x1bb194u: goto label_1bb194;
        case 0x1bb1a0u: goto label_1bb1a0;
        case 0x1bb1a8u: goto label_1bb1a8;
        default: break;
    }

    ctx->pc = 0x1bb160u;

    // 0x1bb160: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1bb160u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bb164: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1bb164u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bb168: 0xc06c1bc  jal         func_1B06F0
    ctx->pc = 0x1BB168u;
    SET_GPR_U32(ctx, 31, 0x1BB170u);
    ctx->pc = 0x1B06F0u;
    if (runtime->hasFunction(0x1B06F0u)) {
        auto targetFn = runtime->lookupFunction(0x1B06F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB170u; }
        if (ctx->pc != 0x1BB170u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B06F0_0x1b06f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB170u; }
        if (ctx->pc != 0x1BB170u) { return; }
    }
    ctx->pc = 0x1BB170u;
label_1bb170:
    // 0x1bb170: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1bb170u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1bb174: 0xc06c260  jal         func_1B0980
    ctx->pc = 0x1BB174u;
    SET_GPR_U32(ctx, 31, 0x1BB17Cu);
    ctx->pc = 0x1BB178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB174u;
            // 0x1bb178: 0x24844300  addiu       $a0, $a0, 0x4300 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17152));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0980u;
    if (runtime->hasFunction(0x1B0980u)) {
        auto targetFn = runtime->lookupFunction(0x1B0980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB17Cu; }
        if (ctx->pc != 0x1BB17Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0980_0x1b0980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB17Cu; }
        if (ctx->pc != 0x1BB17Cu) { return; }
    }
    ctx->pc = 0x1BB17Cu;
label_1bb17c:
    // 0x1bb17c: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1bb17cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1bb180: 0xc06c260  jal         func_1B0980
    ctx->pc = 0x1BB180u;
    SET_GPR_U32(ctx, 31, 0x1BB188u);
    ctx->pc = 0x1BB184u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB180u;
            // 0x1bb184: 0x24844330  addiu       $a0, $a0, 0x4330 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17200));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0980u;
    if (runtime->hasFunction(0x1B0980u)) {
        auto targetFn = runtime->lookupFunction(0x1B0980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB188u; }
        if (ctx->pc != 0x1BB188u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0980_0x1b0980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB188u; }
        if (ctx->pc != 0x1BB188u) { return; }
    }
    ctx->pc = 0x1BB188u;
label_1bb188:
    // 0x1bb188: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1bb188u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1bb18c: 0xc06c260  jal         func_1B0980
    ctx->pc = 0x1BB18Cu;
    SET_GPR_U32(ctx, 31, 0x1BB194u);
    ctx->pc = 0x1BB190u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB18Cu;
            // 0x1bb190: 0x24844360  addiu       $a0, $a0, 0x4360 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17248));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0980u;
    if (runtime->hasFunction(0x1B0980u)) {
        auto targetFn = runtime->lookupFunction(0x1B0980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB194u; }
        if (ctx->pc != 0x1BB194u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0980_0x1b0980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB194u; }
        if (ctx->pc != 0x1BB194u) { return; }
    }
    ctx->pc = 0x1BB194u;
label_1bb194:
    // 0x1bb194: 0x3c040032  lui         $a0, 0x32
    ctx->pc = 0x1bb194u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)50 << 16));
    // 0x1bb198: 0xc06c260  jal         func_1B0980
    ctx->pc = 0x1BB198u;
    SET_GPR_U32(ctx, 31, 0x1BB1A0u);
    ctx->pc = 0x1BB19Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB198u;
            // 0x1bb19c: 0x24844390  addiu       $a0, $a0, 0x4390 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 17296));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0980u;
    if (runtime->hasFunction(0x1B0980u)) {
        auto targetFn = runtime->lookupFunction(0x1B0980u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB1A0u; }
        if (ctx->pc != 0x1BB1A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0980_0x1b0980(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB1A0u; }
        if (ctx->pc != 0x1BB1A0u) { return; }
    }
    ctx->pc = 0x1BB1A0u;
label_1bb1a0:
    // 0x1bb1a0: 0xc06c36c  jal         func_1B0DB0
    ctx->pc = 0x1BB1A0u;
    SET_GPR_U32(ctx, 31, 0x1BB1A8u);
    ctx->pc = 0x1B0DB0u;
    if (runtime->hasFunction(0x1B0DB0u)) {
        auto targetFn = runtime->lookupFunction(0x1B0DB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB1A8u; }
        if (ctx->pc != 0x1BB1A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0DB0_0x1b0db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB1A8u; }
        if (ctx->pc != 0x1BB1A8u) { return; }
    }
    ctx->pc = 0x1BB1A8u;
label_1bb1a8:
    // 0x1bb1a8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1bb1a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bb1ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1BB1ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BB1B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BB1ACu;
            // 0x1bb1b0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BB170u: goto label_1bb170;
            case 0x1BB17Cu: goto label_1bb17c;
            case 0x1BB188u: goto label_1bb188;
            case 0x1BB194u: goto label_1bb194;
            case 0x1BB1A0u: goto label_1bb1a0;
            case 0x1BB1A8u: goto label_1bb1a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BB1B4u;
    // 0x1bb1b4: 0x0  nop
    ctx->pc = 0x1bb1b4u;
    // NOP
    // 0x1bb1b8: 0x0  nop
    ctx->pc = 0x1bb1b8u;
    // NOP
    // 0x1bb1bc: 0x0  nop
    ctx->pc = 0x1bb1bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
