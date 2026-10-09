#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012C680
// Address: 0x12c680 - 0x12c6e8
void sub_0012C680_0x12c680(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012C680_0x12c680");
#endif

    switch (ctx->pc) {
        case 0x12c698u: goto label_12c698;
        case 0x12c6a4u: goto label_12c6a4;
        default: break;
    }

    ctx->pc = 0x12c680u;

    // 0x12c680: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c680u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c684: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12c684u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c688: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12c688u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12c68c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x12c68cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12c690: 0xc04fb14  jal         func_13EC50
    ctx->pc = 0x12C690u;
    SET_GPR_U32(ctx, 31, 0x12C698u);
    ctx->pc = 0x12C694u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C690u;
            // 0x12c694: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13EC50u;
    if (runtime->hasFunction(0x13EC50u)) {
        auto targetFn = runtime->lookupFunction(0x13EC50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C698u; }
        if (ctx->pc != 0x12C698u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013EC50_0x13ec50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C698u; }
        if (ctx->pc != 0x12C698u) { return; }
    }
    ctx->pc = 0x12C698u;
label_12c698:
    // 0x12c698: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12c698u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c69c: 0xc04faf6  jal         func_13EBD8
    ctx->pc = 0x12C69Cu;
    SET_GPR_U32(ctx, 31, 0x12C6A4u);
    ctx->pc = 0x12C6A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C69Cu;
            // 0x12c6a0: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13EBD8u;
    if (runtime->hasFunction(0x13EBD8u)) {
        auto targetFn = runtime->lookupFunction(0x13EBD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C6A4u; }
        if (ctx->pc != 0x12C6A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013EBD8_0x13ebd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C6A4u; }
        if (ctx->pc != 0x12C6A4u) { return; }
    }
    ctx->pc = 0x12C6A4u;
label_12c6a4:
    // 0x12c6a4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x12c6a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c6a8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12c6a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12c6ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12c6acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c6b0: 0x804fab0  j           func_13EAC0
    ctx->pc = 0x12C6B0u;
    ctx->pc = 0x12C6B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C6B0u;
            // 0x12c6b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13EAC0u;
    if (runtime->hasFunction(0x13EAC0u)) {
        auto targetFn = runtime->lookupFunction(0x13EAC0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013EAC0_0x13eac0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C6B8u;
    // 0x12c6b8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c6b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c6bc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c6bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c6c0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c6c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c6c4: 0x804fae2  j           func_13EB88
    ctx->pc = 0x12C6C4u;
    ctx->pc = 0x12C6C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C6C4u;
            // 0x12c6c8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13EB88u;
    if (runtime->hasFunction(0x13EB88u)) {
        auto targetFn = runtime->lookupFunction(0x13EB88u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013EB88_0x13eb88(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12C6CCu;
    // 0x12c6cc: 0x0  nop
    ctx->pc = 0x12c6ccu;
    // NOP
    // 0x12c6d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12c6d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c6d4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12c6d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c6d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12c6d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c6dc: 0x804faea  j           func_13EBA8
    ctx->pc = 0x12C6DCu;
    ctx->pc = 0x12C6E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12C6DCu;
            // 0x12c6e0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13EBA8u;
    {
        auto targetFn = runtime->lookupFunction(0x13EBA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x12C6E4u;
    // 0x12c6e4: 0x0  nop
    ctx->pc = 0x12c6e4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
