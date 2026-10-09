#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163598
// Address: 0x163598 - 0x1635e8
void sub_00163598_0x163598(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163598_0x163598");
#endif

    switch (ctx->pc) {
        case 0x1635d4u: goto label_1635d4;
        default: break;
    }

    ctx->pc = 0x163598u;

    // 0x163598: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163598u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16359c: 0x3c020027  lui         $v0, 0x27
    ctx->pc = 0x16359cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)39 << 16));
    // 0x1635a0: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1635a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1635a4: 0x24040002  addiu       $a0, $zero, 0x2
    ctx->pc = 0x1635a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1635a8: 0x8c450744  lw          $a1, 0x744($v0)
    ctx->pc = 0x1635a8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1860)));
    // 0x1635ac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1635acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1635b0: 0x80506f8  j           func_141BE0
    ctx->pc = 0x1635B0u;
    ctx->pc = 0x1635B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1635B0u;
            // 0x1635b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141BE0u;
    if (runtime->hasFunction(0x141BE0u)) {
        auto targetFn = runtime->lookupFunction(0x141BE0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141BE0_0x141be0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1635B8u;
    // 0x1635b8: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1635b8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1635bc: 0x24040006  addiu       $a0, $zero, 0x6
    ctx->pc = 0x1635bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1635c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1635c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1635c4: 0xa0302d  daddu       $a2, $a1, $zero
    ctx->pc = 0x1635c4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1635c8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1635c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1635cc: 0xc0506c4  jal         func_141B10
    ctx->pc = 0x1635CCu;
    SET_GPR_U32(ctx, 31, 0x1635D4u);
    ctx->pc = 0x1635D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1635CCu;
            // 0x1635d0: 0x40282d  daddu       $a1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141B10u;
    if (runtime->hasFunction(0x141B10u)) {
        auto targetFn = runtime->lookupFunction(0x141B10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1635D4u; }
        if (ctx->pc != 0x1635D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00141B10_0x141b10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1635D4u; }
        if (ctx->pc != 0x1635D4u) { return; }
    }
    ctx->pc = 0x1635D4u;
label_1635d4:
    // 0x1635d4: 0x3c030027  lui         $v1, 0x27
    ctx->pc = 0x1635d4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)39 << 16));
    // 0x1635d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1635d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1635dc: 0xac620748  sw          $v0, 0x748($v1)
    ctx->pc = 0x1635dcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1864), GPR_U32(ctx, 2));
    // 0x1635e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1635E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1635E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1635E0u;
            // 0x1635e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1635D4u: goto label_1635d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1635E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
