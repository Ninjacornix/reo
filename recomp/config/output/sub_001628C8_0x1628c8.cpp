#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001628C8
// Address: 0x1628c8 - 0x162950
void sub_001628C8_0x1628c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001628C8_0x1628c8");
#endif

    switch (ctx->pc) {
        case 0x1628ecu: goto label_1628ec;
        case 0x162918u: goto label_162918;
        case 0x162928u: goto label_162928;
        case 0x162934u: goto label_162934;
        default: break;
    }

    ctx->pc = 0x1628c8u;

    // 0x1628c8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1628c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1628cc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1628ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1628d0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1628d0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1628d4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1628d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1628d8: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1628d8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1628dc: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1628dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1628e0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1628e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1628e4: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x1628E4u;
    SET_GPR_U32(ctx, 31, 0x1628ECu);
    ctx->pc = 0x1628E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1628E4u;
            // 0x1628e8: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1628ECu; }
        if (ctx->pc != 0x1628ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1628ECu; }
        if (ctx->pc != 0x1628ECu) { return; }
    }
    ctx->pc = 0x1628ECu;
label_1628ec:
    // 0x1628ec: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1628ECu;
    {
        const bool branch_taken_0x1628ec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1628F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1628ECu;
            // 0x1628f0: 0xdfbf0018  ld          $ra, 0x18($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1628ec) {
            ctx->pc = 0x162910u;
            goto label_162910;
        }
    }
    ctx->pc = 0x1628F4u;
    // 0x1628f4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1628f4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1628f8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1628f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1628fc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1628fcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162900: 0x24840330  addiu       $a0, $a0, 0x330
    ctx->pc = 0x162900u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 816));
    // 0x162904: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x162904u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x162908: 0x8058dd4  j           func_163750
    ctx->pc = 0x162908u;
    ctx->pc = 0x16290Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162908u;
            // 0x16290c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162910u;
label_162910:
    // 0x162910: 0xc04f3de  jal         func_13CF78
    ctx->pc = 0x162910u;
    SET_GPR_U32(ctx, 31, 0x162918u);
    ctx->pc = 0x162914u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162910u;
            // 0x162914: 0x8e04004c  lw          $a0, 0x4C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 76)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CF78u;
    if (runtime->hasFunction(0x13CF78u)) {
        auto targetFn = runtime->lookupFunction(0x13CF78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162918u; }
        if (ctx->pc != 0x162918u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CF78_0x13cf78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162918u; }
        if (ctx->pc != 0x162918u) { return; }
    }
    ctx->pc = 0x162918u;
label_162918:
    // 0x162918: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x162918u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16291c: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x16291cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162920: 0xc058a02  jal         func_162808
    ctx->pc = 0x162920u;
    SET_GPR_U32(ctx, 31, 0x162928u);
    ctx->pc = 0x162924u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162920u;
            // 0x162924: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162808u;
    if (runtime->hasFunction(0x162808u)) {
        auto targetFn = runtime->lookupFunction(0x162808u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162928u; }
        if (ctx->pc != 0x162928u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162808_0x162808(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162928u; }
        if (ctx->pc != 0x162928u) { return; }
    }
    ctx->pc = 0x162928u;
label_162928:
    // 0x162928: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x162928u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16292c: 0xc058998  jal         func_162660
    ctx->pc = 0x16292Cu;
    SET_GPR_U32(ctx, 31, 0x162934u);
    ctx->pc = 0x162930u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16292Cu;
            // 0x162930: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x162660u;
    if (runtime->hasFunction(0x162660u)) {
        auto targetFn = runtime->lookupFunction(0x162660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162934u; }
        if (ctx->pc != 0x162934u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00162660_0x162660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162934u; }
        if (ctx->pc != 0x162934u) { return; }
    }
    ctx->pc = 0x162934u;
label_162934:
    // 0x162934: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x162934u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162938: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x162938u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16293c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x16293cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162940: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x162940u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x162944: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x162944u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x162948: 0x8058974  j           func_1625D0
    ctx->pc = 0x162948u;
    ctx->pc = 0x16294Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162948u;
            // 0x16294c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1625D0u;
    if (runtime->hasFunction(0x1625D0u)) {
        auto targetFn = runtime->lookupFunction(0x1625D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001625D0_0x1625d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162950u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
