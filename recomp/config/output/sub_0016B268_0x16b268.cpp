#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016B268
// Address: 0x16b268 - 0x16b2b8
void sub_0016B268_0x16b268(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016B268_0x16b268");
#endif

    switch (ctx->pc) {
        case 0x16b284u: goto label_16b284;
        case 0x16b28cu: goto label_16b28c;
        case 0x16b294u: goto label_16b294;
        case 0x16b29cu: goto label_16b29c;
        case 0x16b2a4u: goto label_16b2a4;
        default: break;
    }

    ctx->pc = 0x16b268u;

    // 0x16b268: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x16b268u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16b26c: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16b26cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x16b270: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16b270u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b274: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x16b274u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16b278: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x16b278u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x16b27c: 0xc05ad4e  jal         func_16B538
    ctx->pc = 0x16B27Cu;
    SET_GPR_U32(ctx, 31, 0x16B284u);
    ctx->pc = 0x16B280u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B27Cu;
            // 0x16b280: 0x27a60004  addiu       $a2, $sp, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16B538u;
    if (runtime->hasFunction(0x16B538u)) {
        auto targetFn = runtime->lookupFunction(0x16B538u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B284u; }
        if (ctx->pc != 0x16B284u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016B538_0x16b538(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B284u; }
        if (ctx->pc != 0x16B284u) { return; }
    }
    ctx->pc = 0x16B284u;
label_16b284:
    // 0x16b284: 0xc05acae  jal         func_16B2B8
    ctx->pc = 0x16B284u;
    SET_GPR_U32(ctx, 31, 0x16B28Cu);
    ctx->pc = 0x16B288u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B284u;
            // 0x16b288: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16B2B8u;
    if (runtime->hasFunction(0x16B2B8u)) {
        auto targetFn = runtime->lookupFunction(0x16B2B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B28Cu; }
        if (ctx->pc != 0x16B28Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016B2B8_0x16b2b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B28Cu; }
        if (ctx->pc != 0x16B28Cu) { return; }
    }
    ctx->pc = 0x16B28Cu;
label_16b28c:
    // 0x16b28c: 0xc05ad7a  jal         func_16B5E8
    ctx->pc = 0x16B28Cu;
    SET_GPR_U32(ctx, 31, 0x16B294u);
    ctx->pc = 0x16B290u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B28Cu;
            // 0x16b290: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16B5E8u;
    if (runtime->hasFunction(0x16B5E8u)) {
        auto targetFn = runtime->lookupFunction(0x16B5E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B294u; }
        if (ctx->pc != 0x16B294u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016B5E8_0x16b5e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B294u; }
        if (ctx->pc != 0x16B294u) { return; }
    }
    ctx->pc = 0x16B294u;
label_16b294:
    // 0x16b294: 0xc05ad1c  jal         func_16B470
    ctx->pc = 0x16B294u;
    SET_GPR_U32(ctx, 31, 0x16B29Cu);
    ctx->pc = 0x16B298u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B294u;
            // 0x16b298: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16B470u;
    if (runtime->hasFunction(0x16B470u)) {
        auto targetFn = runtime->lookupFunction(0x16B470u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B29Cu; }
        if (ctx->pc != 0x16B29Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016B470_0x16b470(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B29Cu; }
        if (ctx->pc != 0x16B29Cu) { return; }
    }
    ctx->pc = 0x16B29Cu;
label_16b29c:
    // 0x16b29c: 0xc05ada0  jal         func_16B680
    ctx->pc = 0x16B29Cu;
    SET_GPR_U32(ctx, 31, 0x16B2A4u);
    ctx->pc = 0x16B2A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16B29Cu;
            // 0x16b2a0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16B680u;
    if (runtime->hasFunction(0x16B680u)) {
        auto targetFn = runtime->lookupFunction(0x16B680u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B2A4u; }
        if (ctx->pc != 0x16B2A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016B680_0x16b680(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16B2A4u; }
        if (ctx->pc != 0x16B2A4u) { return; }
    }
    ctx->pc = 0x16B2A4u;
label_16b2a4:
    // 0x16b2a4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16b2a4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16b2a8: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x16b2a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16b2ac: 0x3e00008  jr          $ra
    ctx->pc = 0x16B2ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16B2B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16B2ACu;
            // 0x16b2b0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16B284u: goto label_16b284;
            case 0x16B28Cu: goto label_16b28c;
            case 0x16B294u: goto label_16b294;
            case 0x16B29Cu: goto label_16b29c;
            case 0x16B2A4u: goto label_16b2a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16B2B4u;
    // 0x16b2b4: 0x0  nop
    ctx->pc = 0x16b2b4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
