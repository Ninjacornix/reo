#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001766C0
// Address: 0x1766c0 - 0x17671c
void sub_001766C0_0x1766c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001766C0_0x1766c0");
#endif

    switch (ctx->pc) {
        case 0x1766d4u: goto label_1766d4;
        default: break;
    }

    ctx->pc = 0x1766c0u;

    // 0x1766c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1766c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1766c4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1766c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1766c8: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1766c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1766cc: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x1766CCu;
    SET_GPR_U32(ctx, 31, 0x1766D4u);
    ctx->pc = 0x1766D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1766CCu;
            // 0x1766d0: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1766D4u; }
        if (ctx->pc != 0x1766D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1766D4u; }
        if (ctx->pc != 0x1766D4u) { return; }
    }
    ctx->pc = 0x1766D4u;
label_1766d4:
    // 0x1766d4: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x1766d4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x1766d8: 0x26060cc0  addiu       $a2, $s0, 0xCC0
    ctx->pc = 0x1766d8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 3264));
    // 0x1766dc: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1766dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1766e0: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1766E0u;
    {
        const bool branch_taken_0x1766e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1766E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1766E0u;
            // 0x1766e4: 0x34a50122  ori         $a1, $a1, 0x122 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)290);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1766e0) {
            ctx->pc = 0x1766F8u;
            goto label_1766f8;
        }
    }
    ctx->pc = 0x1766E8u;
    // 0x1766e8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1766e8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1766ec: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1766ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1766f0: 0x805a704  j           func_169C10
    ctx->pc = 0x1766F0u;
    ctx->pc = 0x1766F4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1766F0u;
            // 0x1766f4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1766F8u;
label_1766f8:
    // 0x1766f8: 0x8cc30260  lw          $v1, 0x260($a2)
    ctx->pc = 0x1766f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 608)));
    // 0x1766fc: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1766fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x176700: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x176700u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176704: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x176704u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x176708: 0xacc30260  sw          $v1, 0x260($a2)
    ctx->pc = 0x176708u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 608), GPR_U32(ctx, 3));
    // 0x17670c: 0xae040044  sw          $a0, 0x44($s0)
    ctx->pc = 0x17670cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 4));
    // 0x176710: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x176710u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176714: 0x3e00008  jr          $ra
    ctx->pc = 0x176714u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176718u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176714u;
            // 0x176718: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1766D4u: goto label_1766d4;
            case 0x1766F8u: goto label_1766f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17671Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
