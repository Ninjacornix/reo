#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019F600
// Address: 0x19f600 - 0x19f6b4
void sub_0019F600_0x19f600(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019F600_0x19f600");
#endif

    switch (ctx->pc) {
        case 0x19f698u: goto label_19f698;
        case 0x19f6a0u: goto label_19f6a0;
        default: break;
    }

    ctx->pc = 0x19f600u;

    // 0x19f600: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x19f600u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x19f604: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f604u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f608: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x19f608u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x19f60c: 0x8c24fa0c  lw          $a0, -0x5F4($at)
    ctx->pc = 0x19f60cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965772)));
    // 0x19f610: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19f610u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19f614: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x19f614u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x19f618: 0x8c234170  lw          $v1, 0x4170($at)
    ctx->pc = 0x19f618u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16752)));
    // 0x19f61c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f61cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f620: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x19f620u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x19f624: 0x8c22fa04  lw          $v0, -0x5FC($at)
    ctx->pc = 0x19f624u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965764)));
    // 0x19f628: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f628u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f62c: 0xac24fa0c  sw          $a0, -0x5F4($at)
    ctx->pc = 0x19f62cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965772), GPR_U32(ctx, 4));
    // 0x19f630: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x19f630u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x19f634: 0xac234170  sw          $v1, 0x4170($at)
    ctx->pc = 0x19f634u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16752), GPR_U32(ctx, 3));
    // 0x19f638: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f638u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f63c: 0x8c23fa0c  lw          $v1, -0x5F4($at)
    ctx->pc = 0x19f63cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965772)));
    // 0x19f640: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x19f640u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x19f644: 0x10200014  beqz        $at, . + 4 + (0x14 << 2)
    ctx->pc = 0x19F644u;
    {
        const bool branch_taken_0x19f644 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x19F648u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F644u;
            // 0x19f648: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19f644) {
            ctx->pc = 0x19F698u;
            goto label_19f698;
        }
    }
    ctx->pc = 0x19F64Cu;
    // 0x19f64c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x19f64cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x19f650: 0x8c23fa10  lw          $v1, -0x5F0($at)
    ctx->pc = 0x19f650u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965776)));
    // 0x19f654: 0x14620010  bne         $v1, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x19F654u;
    {
        const bool branch_taken_0x19f654 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x19f654) {
            ctx->pc = 0x19F698u;
            goto label_19f698;
        }
    }
    ctx->pc = 0x19F65Cu;
    // 0x19f65c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f65cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f660: 0xac20fa10  sw          $zero, -0x5F0($at)
    ctx->pc = 0x19f660u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965776), GPR_U32(ctx, 0));
    // 0x19f664: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f664u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f668: 0x8c23fa08  lw          $v1, -0x5F8($at)
    ctx->pc = 0x19f668u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965768)));
    // 0x19f66c: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f66cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f670: 0x8c22fa00  lw          $v0, -0x600($at)
    ctx->pc = 0x19f670u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965760)));
    // 0x19f674: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f674u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f678: 0x38420001  xori        $v0, $v0, 0x1
    ctx->pc = 0x19f678u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)1);
    // 0x19f67c: 0xac23fa04  sw          $v1, -0x5FC($at)
    ctx->pc = 0x19f67cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965764), GPR_U32(ctx, 3));
    // 0x19f680: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f680u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f684: 0xac22fa00  sw          $v0, -0x600($at)
    ctx->pc = 0x19f684u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965760), GPR_U32(ctx, 2));
    // 0x19f688: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19f688u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19f68c: 0x8c24fa00  lw          $a0, -0x600($at)
    ctx->pc = 0x19f68cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965760)));
    // 0x19f690: 0xc0680d4  jal         func_1A0350
    ctx->pc = 0x19F690u;
    SET_GPR_U32(ctx, 31, 0x19F698u);
    ctx->pc = 0x19F694u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x19F690u;
            // 0x19f694: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A0350u;
    if (runtime->hasFunction(0x1A0350u)) {
        auto targetFn = runtime->lookupFunction(0x1A0350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F698u; }
        if (ctx->pc != 0x19F698u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A0350_0x1a0350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F698u; }
        if (ctx->pc != 0x19F698u) { return; }
    }
    ctx->pc = 0x19F698u;
label_19f698:
    // 0x19f698: 0xc06a410  jal         func_1A9040
    ctx->pc = 0x19F698u;
    SET_GPR_U32(ctx, 31, 0x19F6A0u);
    ctx->pc = 0x1A9040u;
    if (runtime->hasFunction(0x1A9040u)) {
        auto targetFn = runtime->lookupFunction(0x1A9040u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F6A0u; }
        if (ctx->pc != 0x19F6A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9040_0x1a9040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19F6A0u; }
        if (ctx->pc != 0x19F6A0u) { return; }
    }
    ctx->pc = 0x19F6A0u;
label_19f6a0:
    // 0x19f6a0: 0xf  sync
    ctx->pc = 0x19f6a0u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x19f6a4: 0x42000038  ei
    ctx->pc = 0x19f6a4u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x19f6a8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x19f6a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19f6ac: 0x3e00008  jr          $ra
    ctx->pc = 0x19F6ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19F6B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19F6ACu;
            // 0x19f6b0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19F698u: goto label_19f698;
            case 0x19F6A0u: goto label_19f6a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19F6B4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
