#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011EEB8
// Address: 0x11eeb8 - 0x11ef04
void sub_0011EEB8_0x11eeb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011EEB8_0x11eeb8");
#endif

    switch (ctx->pc) {
        case 0x11eed0u: goto label_11eed0;
        case 0x11eedcu: goto label_11eedc;
        case 0x11eeecu: goto label_11eeec;
        default: break;
    }

    ctx->pc = 0x11eeb8u;

    // 0x11eeb8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x11eeb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x11eebc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x11eebcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11eec0: 0xffb10010  sd          $s1, 0x10($sp)
    ctx->pc = 0x11eec0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11eec4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x11eec4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x11eec8: 0xc047598  jal         func_11D660
    ctx->pc = 0x11EEC8u;
    SET_GPR_U32(ctx, 31, 0x11EED0u);
    ctx->pc = 0x11EECCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11EEC8u;
            // 0x11eecc: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EED0u; }
        if (ctx->pc != 0x11EED0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EED0u; }
        if (ctx->pc != 0x11EED0u) { return; }
    }
    ctx->pc = 0x11EED0u;
label_11eed0:
    // 0x11eed0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x11eed0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11eed4: 0xc047b92  jal         func_11EE48
    ctx->pc = 0x11EED4u;
    SET_GPR_U32(ctx, 31, 0x11EEDCu);
    ctx->pc = 0x11EED8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11EED4u;
            // 0x11eed8: 0x40882d  daddu       $s1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11EE48u;
    if (runtime->hasFunction(0x11EE48u)) {
        auto targetFn = runtime->lookupFunction(0x11EE48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EEDCu; }
        if (ctx->pc != 0x11EEDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011EE48_0x11ee48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EEDCu; }
        if (ctx->pc != 0x11EEDCu) { return; }
    }
    ctx->pc = 0x11EEDCu;
label_11eedc:
    // 0x11eedc: 0x12200003  beqz        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x11EEDCu;
    {
        const bool branch_taken_0x11eedc = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x11EEE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EEDCu;
            // 0x11eee0: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11eedc) {
            ctx->pc = 0x11EEECu;
            goto label_11eeec;
        }
    }
    ctx->pc = 0x11EEE4u;
    // 0x11eee4: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x11EEE4u;
    SET_GPR_U32(ctx, 31, 0x11EEECu);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EEECu; }
        if (ctx->pc != 0x11EEECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11EEECu; }
        if (ctx->pc != 0x11EEECu) { return; }
    }
    ctx->pc = 0x11EEECu;
label_11eeec:
    // 0x11eeec: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x11eeecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11eef0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x11eef0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11eef4: 0xdfb10010  ld          $s1, 0x10($sp)
    ctx->pc = 0x11eef4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11eef8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x11eef8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11eefc: 0x3e00008  jr          $ra
    ctx->pc = 0x11EEFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11EF00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11EEFCu;
            // 0x11ef00: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11EED0u: goto label_11eed0;
            case 0x11EEDCu: goto label_11eedc;
            case 0x11EEECu: goto label_11eeec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11EF04u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
