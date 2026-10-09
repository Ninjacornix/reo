#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00190020
// Address: 0x190020 - 0x190060
void sub_00190020_0x190020(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00190020_0x190020");
#endif

    switch (ctx->pc) {
        case 0x190044u: goto label_190044;
        case 0x190050u: goto label_190050;
        default: break;
    }

    ctx->pc = 0x190020u;

    // 0x190020: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x190020u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x190024: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x190024u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x190028: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x190028u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19002c: 0xc4ac0000  lwc1        $f12, 0x0($a1)
    ctx->pc = 0x19002cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x190030: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x190030u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x190034: 0xc4ad0004  lwc1        $f13, 0x4($a1)
    ctx->pc = 0x190034u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 4)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[13] = f; }
    // 0x190038: 0xc4ae0008  lwc1        $f14, 0x8($a1)
    ctx->pc = 0x190038u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 8)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[14] = f; }
    // 0x19003c: 0xc063fac  jal         func_18FEB0
    ctx->pc = 0x19003Cu;
    SET_GPR_U32(ctx, 31, 0x190044u);
    ctx->pc = 0x190040u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19003Cu;
            // 0x190040: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18FEB0u;
    if (runtime->hasFunction(0x18FEB0u)) {
        auto targetFn = runtime->lookupFunction(0x18FEB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190044u; }
        if (ctx->pc != 0x190044u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018FEB0_0x18feb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190044u; }
        if (ctx->pc != 0x190044u) { return; }
    }
    ctx->pc = 0x190044u;
label_190044:
    // 0x190044: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x190044u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x190048: 0xc0644f8  jal         func_1913E0
    ctx->pc = 0x190048u;
    SET_GPR_U32(ctx, 31, 0x190050u);
    ctx->pc = 0x19004Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x190048u;
            // 0x19004c: 0x27a50020  addiu       $a1, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1913E0u;
    if (runtime->hasFunction(0x1913E0u)) {
        auto targetFn = runtime->lookupFunction(0x1913E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190050u; }
        if (ctx->pc != 0x190050u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001913E0_0x1913e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x190050u; }
        if (ctx->pc != 0x190050u) { return; }
    }
    ctx->pc = 0x190050u;
label_190050:
    // 0x190050: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x190050u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x190054: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x190054u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x190058: 0x3e00008  jr          $ra
    ctx->pc = 0x190058u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19005Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x190058u;
            // 0x19005c: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x190044u: goto label_190044;
            case 0x190050u: goto label_190050;
            default: break;
        }
        return;
    }
    ctx->pc = 0x190060u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
