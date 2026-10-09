#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011EC90
// Address: 0x11ec90 - 0x11ecdc
void sub_0011EC90_0x11ec90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011EC90_0x11ec90");
#endif

    switch (ctx->pc) {
        case 0x11eca8u: goto label_11eca8;
        case 0x11ecb4u: goto label_11ecb4;
        case 0x11ecc4u: goto label_11ecc4;
        default: break;
    }

    ctx->pc = 0x11ec90u;

    // 0x11ec90: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11ec90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11ec94: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11ec94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11ec98: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11ec98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11ec9c: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11ec9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11eca0: 0xc047598  jal         func_11D660
    ctx->pc = 0x11ECA0u;
    SET_GPR_U32(ctx, 31, 0x11ECA8u);
    ctx->pc = 0x11ECA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11ECA0u;
            // 0x11eca4: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ECA8u; }
        if (ctx->pc != 0x11ECA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ECA8u; }
        if (ctx->pc != 0x11ECA8u) { return; }
    }
    ctx->pc = 0x11ECA8u;
label_11eca8:
    // 0x11eca8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11eca8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ecac: 0xc047af2  jal         func_11EBC8
    ctx->pc = 0x11ECACu;
    SET_GPR_U32(ctx, 31, 0x11ECB4u);
    ctx->pc = 0x11ECB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11ECACu;
            // 0x11ecb0: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11EBC8u;
    if (runtime->hasFunction(0x11EBC8u)) {
        auto targetFn = runtime->lookupFunction(0x11EBC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ECB4u; }
        if (ctx->pc != 0x11ECB4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011EBC8_0x11ebc8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ECB4u; }
        if (ctx->pc != 0x11ECB4u) { return; }
    }
    ctx->pc = 0x11ECB4u;
label_11ecb4:
    // 0x11ecb4: 0x12200003  beqz        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x11ECB4u;
    {
        const bool branch_taken_0x11ecb4 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x11ECB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ECB4u;
            // 0x11ecb8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11ecb4) {
            ctx->pc = 0x11ECC4u;
            goto label_11ecc4;
        }
    }
    ctx->pc = 0x11ECBCu;
    // 0x11ecbc: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11ECBCu;
    SET_GPR_U32(ctx, 31, 0x11ECC4u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ECC4u; }
        if (ctx->pc != 0x11ECC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11ECC4u; }
        if (ctx->pc != 0x11ECC4u) { return; }
    }
    ctx->pc = 0x11ECC4u;
label_11ecc4:
    // 0x11ecc4: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x11ecc4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11ecc8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11ecc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11eccc: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11ecccu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11ecd0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11ecd0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11ecd4: 0x3e00008  jr          $ra
    ctx->pc = 0x11ECD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11ECD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11ECD4u;
            // 0x11ecd8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11ECA8u: goto label_11eca8;
            case 0x11ECB4u: goto label_11ecb4;
            case 0x11ECC4u: goto label_11ecc4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11ECDCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
