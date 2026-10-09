#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017F780
// Address: 0x17f780 - 0x17f7d0
void sub_0017F780_0x17f780(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017F780_0x17f780");
#endif

    switch (ctx->pc) {
        case 0x17f7a0u: goto label_17f7a0;
        case 0x17f7b0u: goto label_17f7b0;
        default: break;
    }

    ctx->pc = 0x17f780u;

    // 0x17f780: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x17f780u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x17f784: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x17f784u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x17f788: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17f788u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17f78c: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x17f78cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f790: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x17f790u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x17f794: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17f794u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f798: 0xc05fd28  jal         func_17F4A0
    ctx->pc = 0x17F798u;
    SET_GPR_U32(ctx, 31, 0x17F7A0u);
    ctx->pc = 0x17F79Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F798u;
            // 0x17f79c: 0xc62c0008  lwc1        $f12, 0x8($s1) (Delay Slot)
        { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F4A0u;
    if (runtime->hasFunction(0x17F4A0u)) {
        auto targetFn = runtime->lookupFunction(0x17F4A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F7A0u; }
        if (ctx->pc != 0x17F7A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F4A0_0x17f4a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F7A0u; }
        if (ctx->pc != 0x17F7A0u) { return; }
    }
    ctx->pc = 0x17F7A0u;
label_17f7a0:
    // 0x17f7a0: 0xc62c0004  lwc1        $f12, 0x4($s1)
    ctx->pc = 0x17f7a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x17f7a4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17f7a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f7a8: 0xc05fda2  jal         func_17F688
    ctx->pc = 0x17F7A8u;
    SET_GPR_U32(ctx, 31, 0x17F7B0u);
    ctx->pc = 0x17F7ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F7A8u;
            // 0x17f7ac: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F688u;
    if (runtime->hasFunction(0x17F688u)) {
        auto targetFn = runtime->lookupFunction(0x17F688u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F7B0u; }
        if (ctx->pc != 0x17F7B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0017F688_0x17f688(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17F7B0u; }
        if (ctx->pc != 0x17F7B0u) { return; }
    }
    ctx->pc = 0x17F7B0u;
label_17f7b0:
    // 0x17f7b0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x17f7b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f7b4: 0xc62c0000  lwc1        $f12, 0x0($s1)
    ctx->pc = 0x17f7b4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x17f7b8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x17f7b8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x17f7bc: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x17f7bcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17f7c0: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x17f7c0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17f7c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17f7c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17f7c8: 0x805fd64  j           func_17F590
    ctx->pc = 0x17F7C8u;
    ctx->pc = 0x17F7CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17F7C8u;
            // 0x17f7cc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x17F590u;
    if (runtime->hasFunction(0x17F590u)) {
        auto targetFn = runtime->lookupFunction(0x17F590u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0017F590_0x17f590(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17F7D0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
