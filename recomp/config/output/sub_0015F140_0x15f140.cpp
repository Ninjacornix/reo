#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015F140
// Address: 0x15f140 - 0x15f1c0
void sub_0015F140_0x15f140(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015F140_0x15f140");
#endif

    switch (ctx->pc) {
        case 0x15f174u: goto label_15f174;
        case 0x15f17cu: goto label_15f17c;
        case 0x15f188u: goto label_15f188;
        case 0x15f198u: goto label_15f198;
        default: break;
    }

    ctx->pc = 0x15f140u;

    // 0x15f140: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x15f140u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x15f144: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15f144u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15f148: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15f148u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f14c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15f14cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15f150: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x15f150u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f154: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x15f154u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15f158: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x15f158u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f15c: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x15f15cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x15f160: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x15f160u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f164: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x15f164u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x15f168: 0x8e02012c  lw          $v0, 0x12C($s0)
    ctx->pc = 0x15f168u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 300)));
    // 0x15f16c: 0xc057cbc  jal         func_15F2F0
    ctx->pc = 0x15F16Cu;
    SET_GPR_U32(ctx, 31, 0x15F174u);
    ctx->pc = 0x15F170u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F16Cu;
            // 0x15f170: 0xae020128  sw          $v0, 0x128($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 296), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F2F0u;
    if (runtime->hasFunction(0x15F2F0u)) {
        auto targetFn = runtime->lookupFunction(0x15F2F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F174u; }
        if (ctx->pc != 0x15F174u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F2F0_0x15f2f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F174u; }
        if (ctx->pc != 0x15F174u) { return; }
    }
    ctx->pc = 0x15F174u;
label_15f174:
    // 0x15f174: 0xc057bee  jal         func_15EFB8
    ctx->pc = 0x15F174u;
    SET_GPR_U32(ctx, 31, 0x15F17Cu);
    ctx->pc = 0x15F178u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F174u;
            // 0x15f178: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15EFB8u;
    if (runtime->hasFunction(0x15EFB8u)) {
        auto targetFn = runtime->lookupFunction(0x15EFB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F17Cu; }
        if (ctx->pc != 0x15F17Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015EFB8_0x15efb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F17Cu; }
        if (ctx->pc != 0x15F17Cu) { return; }
    }
    ctx->pc = 0x15F17Cu;
label_15f17c:
    // 0x15f17c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f17cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f180: 0xc057db6  jal         func_15F6D8
    ctx->pc = 0x15F180u;
    SET_GPR_U32(ctx, 31, 0x15F188u);
    ctx->pc = 0x15F184u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F180u;
            // 0x15f184: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15F6D8u;
    if (runtime->hasFunction(0x15F6D8u)) {
        auto targetFn = runtime->lookupFunction(0x15F6D8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F188u; }
        if (ctx->pc != 0x15F188u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015F6D8_0x15f6d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F188u; }
        if (ctx->pc != 0x15F188u) { return; }
    }
    ctx->pc = 0x15F188u;
label_15f188:
    // 0x15f188: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f188u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f18c: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x15f18cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f190: 0xc057eaa  jal         func_15FAA8
    ctx->pc = 0x15F190u;
    SET_GPR_U32(ctx, 31, 0x15F198u);
    ctx->pc = 0x15F194u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F190u;
            // 0x15f194: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FAA8u;
    if (runtime->hasFunction(0x15FAA8u)) {
        auto targetFn = runtime->lookupFunction(0x15FAA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F198u; }
        if (ctx->pc != 0x15F198u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FAA8_0x15faa8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15F198u; }
        if (ctx->pc != 0x15F198u) { return; }
    }
    ctx->pc = 0x15F198u;
label_15f198:
    // 0x15f198: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x15f198u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f19c: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x15f19cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f1a0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x15f1a0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15f1a4: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x15f1a4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15f1a8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x15f1a8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15f1ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15f1acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15f1b0: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15f1b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15f1b4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x15f1b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x15f1b8: 0x8057eac  j           func_15FAB0
    ctx->pc = 0x15F1B8u;
    ctx->pc = 0x15F1BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15F1B8u;
            // 0x15f1bc: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FAB0u;
    if (runtime->hasFunction(0x15FAB0u)) {
        auto targetFn = runtime->lookupFunction(0x15FAB0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0015FAB0_0x15fab0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15F1C0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
