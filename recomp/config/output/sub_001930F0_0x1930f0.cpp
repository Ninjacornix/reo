#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001930F0
// Address: 0x1930f0 - 0x193134
void sub_001930F0_0x1930f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001930F0_0x1930f0");
#endif

    switch (ctx->pc) {
        case 0x19310cu: goto label_19310c;
        case 0x19311cu: goto label_19311c;
        default: break;
    }

    ctx->pc = 0x1930f0u;

    // 0x1930f0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1930f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1930f4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1930f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1930f8: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x1930f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1930fc: 0xe7b40000  swc1        $f20, 0x0($sp)
    ctx->pc = 0x1930fcu;
    { float f = ctx->f[20]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 0), bits); }
    // 0x193100: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x193100u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193104: 0xc064b44  jal         func_192D10
    ctx->pc = 0x193104u;
    SET_GPR_U32(ctx, 31, 0x19310Cu);
    ctx->pc = 0x193108u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193104u;
            // 0x193108: 0x46006506  mov.s       $f20, $f12 (Delay Slot)
        ctx->f[20] = FPU_MOV_S(ctx->f[12]);
        ctx->in_delay_slot = false;
    ctx->pc = 0x192D10u;
    if (runtime->hasFunction(0x192D10u)) {
        auto targetFn = runtime->lookupFunction(0x192D10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19310Cu; }
        if (ctx->pc != 0x19310Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00192D10_0x192d10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19310Cu; }
        if (ctx->pc != 0x19310Cu) { return; }
    }
    ctx->pc = 0x19310Cu;
label_19310c:
    // 0x19310c: 0x4600a306  mov.s       $f12, $f20
    ctx->pc = 0x19310cu;
    ctx->f[12] = FPU_MOV_S(ctx->f[20]);
    // 0x193110: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x193110u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x193114: 0xc064c50  jal         func_193140
    ctx->pc = 0x193114u;
    SET_GPR_U32(ctx, 31, 0x19311Cu);
    ctx->pc = 0x193118u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x193114u;
            // 0x193118: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x193140u;
    if (runtime->hasFunction(0x193140u)) {
        auto targetFn = runtime->lookupFunction(0x193140u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19311Cu; }
        if (ctx->pc != 0x19311Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00193140_0x193140(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19311Cu; }
        if (ctx->pc != 0x19311Cu) { return; }
    }
    ctx->pc = 0x19311Cu;
label_19311c:
    // 0x19311c: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x19311cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x193120: 0xc7b40000  lwc1        $f20, 0x0($sp)
    ctx->pc = 0x193120u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 29), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[20] = f; }
    // 0x193124: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x193124u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x193128: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x193128u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19312c: 0x3e00008  jr          $ra
    ctx->pc = 0x19312Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x193130u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19312Cu;
            // 0x193130: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19310Cu: goto label_19310c;
            case 0x19311Cu: goto label_19311c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x193134u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
