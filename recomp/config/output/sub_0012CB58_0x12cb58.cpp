#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012CB58
// Address: 0x12cb58 - 0x12cbb8
void sub_0012CB58_0x12cb58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012CB58_0x12cb58");
#endif

    switch (ctx->pc) {
        case 0x12cb80u: goto label_12cb80;
        case 0x12cb88u: goto label_12cb88;
        case 0x12cb98u: goto label_12cb98;
        default: break;
    }

    ctx->pc = 0x12cb58u;

    // 0x12cb58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12cb58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12cb5c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12cb5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12cb60: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12cb60u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cb64: 0x12000010  beqz        $s0, . + 4 + (0x10 << 2)
    ctx->pc = 0x12CB64u;
    {
        const bool branch_taken_0x12cb64 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x12CB68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CB64u;
            // 0x12cb68: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12cb64) {
            ctx->pc = 0x12CBA8u;
            goto label_12cba8;
        }
    }
    ctx->pc = 0x12CB6Cu;
    // 0x12cb6c: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x12cb6cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x12cb70: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x12CB70u;
    {
        const bool branch_taken_0x12cb70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12CB74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CB70u;
            // 0x12cb74: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12cb70) {
            ctx->pc = 0x12CB80u;
            goto label_12cb80;
        }
    }
    ctx->pc = 0x12CB78u;
    // 0x12cb78: 0xc049268  jal         func_1249A0
    ctx->pc = 0x12CB78u;
    SET_GPR_U32(ctx, 31, 0x12CB80u);
    ctx->pc = 0x12CB7Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CB78u;
            // 0x12cb7c: 0xae000004  sw          $zero, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1249A0u;
    if (runtime->hasFunction(0x1249A0u)) {
        auto targetFn = runtime->lookupFunction(0x1249A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CB80u; }
        if (ctx->pc != 0x12CB80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001249A0_0x1249a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CB80u; }
        if (ctx->pc != 0x12CB80u) { return; }
    }
    ctx->pc = 0x12CB80u;
label_12cb80:
    // 0x12cb80: 0xc049938  jal         func_1264E0
    ctx->pc = 0x12CB80u;
    SET_GPR_U32(ctx, 31, 0x12CB88u);
    ctx->pc = 0x1264E0u;
    if (runtime->hasFunction(0x1264E0u)) {
        auto targetFn = runtime->lookupFunction(0x1264E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CB88u; }
        if (ctx->pc != 0x12CB88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CB88u; }
        if (ctx->pc != 0x12CB88u) { return; }
    }
    ctx->pc = 0x12CB88u;
label_12cb88:
    // 0x12cb88: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12cb88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cb8c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12cb8cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12cb90: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x12CB90u;
    SET_GPR_U32(ctx, 31, 0x12CB98u);
    ctx->pc = 0x12CB94u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CB90u;
            // 0x12cb94: 0x2406009c  addiu       $a2, $zero, 0x9C (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 156));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CB98u; }
        if (ctx->pc != 0x12CB98u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CB98u; }
        if (ctx->pc != 0x12CB98u) { return; }
    }
    ctx->pc = 0x12CB98u;
label_12cb98:
    // 0x12cb98: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12cb98u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12cb9c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12cb9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12cba0: 0x804993e  j           func_1264F8
    ctx->pc = 0x12CBA0u;
    ctx->pc = 0x12CBA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CBA0u;
            // 0x12cba4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1264F8u;
    if (runtime->hasFunction(0x1264F8u)) {
        auto targetFn = runtime->lookupFunction(0x1264F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001264F8_0x1264f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12CBA8u;
label_12cba8:
    // 0x12cba8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12cba8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12cbac: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12cbacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12cbb0: 0x3e00008  jr          $ra
    ctx->pc = 0x12CBB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12CBB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CBB0u;
            // 0x12cbb4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12CB80u: goto label_12cb80;
            case 0x12CB88u: goto label_12cb88;
            case 0x12CB98u: goto label_12cb98;
            case 0x12CBA8u: goto label_12cba8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12CBB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
