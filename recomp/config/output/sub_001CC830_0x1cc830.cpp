#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CC830
// Address: 0x1cc830 - 0x1cc8a0
void sub_001CC830_0x1cc830(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CC830_0x1cc830");
#endif

    switch (ctx->pc) {
        case 0x1cc854u: goto label_1cc854;
        case 0x1cc870u: goto label_1cc870;
        case 0x1cc88cu: goto label_1cc88c;
        default: break;
    }

    ctx->pc = 0x1cc830u;

    // 0x1cc830: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1cc830u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1cc834: 0x3c024000  lui         $v0, 0x4000
    ctx->pc = 0x1cc834u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16384 << 16));
    // 0x1cc838: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1cc838u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1cc83c: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x1cc83cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x1cc840: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cc840u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cc844: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1cc844u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc848: 0xac222000  sw          $v0, 0x2000($at)
    ctx->pc = 0x1cc848u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8192), GPR_U32(ctx, 2)); // MMIO: 0x10002000
    // 0x1cc84c: 0xc044fb4  jal         func_113ED0
    ctx->pc = 0x1CC84Cu;
    SET_GPR_U32(ctx, 31, 0x1CC854u);
    ctx->pc = 0x1CC850u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC84Cu;
            // 0x1cc850: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113ED0u;
    if (runtime->hasFunction(0x113ED0u)) {
        auto targetFn = runtime->lookupFunction(0x113ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC854u; }
        if (ctx->pc != 0x1CC854u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113ED0_0x113ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC854u; }
        if (ctx->pc != 0x1CC854u) { return; }
    }
    ctx->pc = 0x1CC854u;
label_1cc854:
    // 0x1cc854: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x1cc854u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x1cc858: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1cc858u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc85c: 0x8c222000  lw          $v0, 0x2000($at)
    ctx->pc = 0x1cc85cu;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8192))); // MMIO: 0x10002000
    // 0x1cc860: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1cc860u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc864: 0x21602  srl         $v0, $v0, 24
    ctx->pc = 0x1cc864u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 24));
    // 0x1cc868: 0xc044fb4  jal         func_113ED0
    ctx->pc = 0x1CC868u;
    SET_GPR_U32(ctx, 31, 0x1CC870u);
    ctx->pc = 0x1CC86Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC868u;
            // 0x1cc86c: 0x305000ff  andi        $s0, $v0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
    ctx->pc = 0x113ED0u;
    if (runtime->hasFunction(0x113ED0u)) {
        auto targetFn = runtime->lookupFunction(0x113ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC870u; }
        if (ctx->pc != 0x1CC870u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113ED0_0x113ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC870u; }
        if (ctx->pc != 0x1CC870u) { return; }
    }
    ctx->pc = 0x1CC870u;
label_1cc870:
    // 0x1cc870: 0x3c024000  lui         $v0, 0x4000
    ctx->pc = 0x1cc870u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)16384 << 16));
    // 0x1cc874: 0x3c011000  lui         $at, 0x1000
    ctx->pc = 0x1cc874u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)4096 << 16));
    // 0x1cc878: 0x34420008  ori         $v0, $v0, 0x8
    ctx->pc = 0x1cc878u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8);
    // 0x1cc87c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1cc87cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc880: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1cc880u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc884: 0xc044fb4  jal         func_113ED0
    ctx->pc = 0x1CC884u;
    SET_GPR_U32(ctx, 31, 0x1CC88Cu);
    ctx->pc = 0x1CC888u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC884u;
            // 0x1cc888: 0xac222000  sw          $v0, 0x2000($at) (Delay Slot)
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8192), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x113ED0u;
    if (runtime->hasFunction(0x113ED0u)) {
        auto targetFn = runtime->lookupFunction(0x113ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC88Cu; }
        if (ctx->pc != 0x1CC88Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00113ED0_0x113ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CC88Cu; }
        if (ctx->pc != 0x1CC88Cu) { return; }
    }
    ctx->pc = 0x1CC88Cu;
label_1cc88c:
    // 0x1cc88c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1cc88cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cc890: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1cc890u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cc894: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cc894u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cc898: 0x3e00008  jr          $ra
    ctx->pc = 0x1CC898u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CC89Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC898u;
            // 0x1cc89c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CC854u: goto label_1cc854;
            case 0x1CC870u: goto label_1cc870;
            case 0x1CC88Cu: goto label_1cc88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CC8A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
