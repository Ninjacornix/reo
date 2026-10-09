#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A97C0
// Address: 0x1a97c0 - 0x1a9870
void sub_001A97C0_0x1a97c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A97C0_0x1a97c0");
#endif

    switch (ctx->pc) {
        case 0x1a97d4u: goto label_1a97d4;
        case 0x1a97ecu: goto label_1a97ec;
        case 0x1a9820u: goto label_1a9820;
        case 0x1a9860u: goto label_1a9860;
        default: break;
    }

    ctx->pc = 0x1a97c0u;

    // 0x1a97c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a97c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a97c4: 0x14800007  bnez        $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1A97C4u;
    {
        const bool branch_taken_0x1a97c4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A97C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A97C4u;
            // 0x1a97c8: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a97c4) {
            ctx->pc = 0x1A97E4u;
            goto label_1a97e4;
        }
    }
    ctx->pc = 0x1A97CCu;
    // 0x1a97cc: 0xc06a568  jal         func_1A95A0
    ctx->pc = 0x1A97CCu;
    SET_GPR_U32(ctx, 31, 0x1A97D4u);
    ctx->pc = 0x1A97D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A97CCu;
            // 0x1a97d0: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A95A0u;
    if (runtime->hasFunction(0x1A95A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A95A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A97D4u; }
        if (ctx->pc != 0x1A97D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A95A0_0x1a95a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A97D4u; }
        if (ctx->pc != 0x1A97D4u) { return; }
    }
    ctx->pc = 0x1A97D4u;
label_1a97d4:
    // 0x1a97d4: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x1a97d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1a97d8: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1a97d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1a97dc: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1A97DCu;
    {
        const bool branch_taken_0x1a97dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A97E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A97DCu;
            // 0x1a97e0: 0xa023448a  sb          $v1, 0x448A($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 17546), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a97dc) {
            ctx->pc = 0x1A97F8u;
            goto label_1a97f8;
        }
    }
    ctx->pc = 0x1A97E4u;
label_1a97e4:
    // 0x1a97e4: 0xc06a568  jal         func_1A95A0
    ctx->pc = 0x1A97E4u;
    SET_GPR_U32(ctx, 31, 0x1A97ECu);
    ctx->pc = 0x1A97E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A97E4u;
            // 0x1a97e8: 0x24040005  addiu       $a0, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A95A0u;
    if (runtime->hasFunction(0x1A95A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A95A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A97ECu; }
        if (ctx->pc != 0x1A97ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A95A0_0x1a95a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A97ECu; }
        if (ctx->pc != 0x1A97ECu) { return; }
    }
    ctx->pc = 0x1A97ECu;
label_1a97ec:
    // 0x1a97ec: 0x24030005  addiu       $v1, $zero, 0x5
    ctx->pc = 0x1a97ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1a97f0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1a97f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1a97f4: 0xa023448a  sb          $v1, 0x448A($at)
    ctx->pc = 0x1a97f4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17546), (uint8_t)GPR_U32(ctx, 3));
label_1a97f8:
    // 0x1a97f8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a97f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a97fc: 0x3e00008  jr          $ra
    ctx->pc = 0x1A97FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A9800u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A97FCu;
            // 0x1a9800: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A97D4u: goto label_1a97d4;
            case 0x1A97E4u: goto label_1a97e4;
            case 0x1A97ECu: goto label_1a97ec;
            case 0x1A97F8u: goto label_1a97f8;
            case 0x1A9820u: goto label_1a9820;
            case 0x1A9860u: goto label_1a9860;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A9804u;
    // 0x1a9804: 0x0  nop
    ctx->pc = 0x1a9804u;
    // NOP
    // 0x1a9808: 0x0  nop
    ctx->pc = 0x1a9808u;
    // NOP
    // 0x1a980c: 0x0  nop
    ctx->pc = 0x1a980cu;
    // NOP
    // 0x1a9810: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a9810u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a9814: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a9814u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a9818: 0xc06a568  jal         func_1A95A0
    ctx->pc = 0x1A9818u;
    SET_GPR_U32(ctx, 31, 0x1A9820u);
    ctx->pc = 0x1A981Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9818u;
            // 0x1a981c: 0x24040006  addiu       $a0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A95A0u;
    if (runtime->hasFunction(0x1A95A0u)) {
        auto targetFn = runtime->lookupFunction(0x1A95A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9820u; }
        if (ctx->pc != 0x1A9820u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A95A0_0x1a95a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9820u; }
        if (ctx->pc != 0x1A9820u) { return; }
    }
    ctx->pc = 0x1A9820u;
label_1a9820:
    // 0x1a9820: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x1a9820u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1a9824: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1a9824u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1a9828: 0xa023448a  sb          $v1, 0x448A($at)
    ctx->pc = 0x1a9828u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17546), (uint8_t)GPR_U32(ctx, 3));
    // 0x1a982c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a982cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a9830: 0x3e00008  jr          $ra
    ctx->pc = 0x1A9830u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A9834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9830u;
            // 0x1a9834: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A97D4u: goto label_1a97d4;
            case 0x1A97E4u: goto label_1a97e4;
            case 0x1A97ECu: goto label_1a97ec;
            case 0x1A97F8u: goto label_1a97f8;
            case 0x1A9820u: goto label_1a9820;
            case 0x1A9860u: goto label_1a9860;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A9838u;
    // 0x1a9838: 0x0  nop
    ctx->pc = 0x1a9838u;
    // NOP
    // 0x1a983c: 0x0  nop
    ctx->pc = 0x1a983cu;
    // NOP
    // 0x1a9840: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1a9840u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a9844: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a9844u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a9848: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1a9848u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a984c: 0x8c2416a8  lw          $a0, 0x16A8($at)
    ctx->pc = 0x1a984cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 5800)));
    // 0x1a9850: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A9850u;
    {
        const bool branch_taken_0x1a9850 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a9850) {
            ctx->pc = 0x1A9860u;
            goto label_1a9860;
        }
    }
    ctx->pc = 0x1A9858u;
    // 0x1a9858: 0xc04a5f8  jal         func_1297E0
    ctx->pc = 0x1A9858u;
    SET_GPR_U32(ctx, 31, 0x1A9860u);
    ctx->pc = 0x1297E0u;
    if (runtime->hasFunction(0x1297E0u)) {
        auto targetFn = runtime->lookupFunction(0x1297E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9860u; }
        if (ctx->pc != 0x1A9860u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001297E0_0x1297e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9860u; }
        if (ctx->pc != 0x1A9860u) { return; }
    }
    ctx->pc = 0x1A9860u;
label_1a9860:
    // 0x1a9860: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1a9860u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a9864: 0x3e00008  jr          $ra
    ctx->pc = 0x1A9864u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A9868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A9864u;
            // 0x1a9868: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A97D4u: goto label_1a97d4;
            case 0x1A97E4u: goto label_1a97e4;
            case 0x1A97ECu: goto label_1a97ec;
            case 0x1A97F8u: goto label_1a97f8;
            case 0x1A9820u: goto label_1a9820;
            case 0x1A9860u: goto label_1a9860;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A986Cu;
    // 0x1a986c: 0x0  nop
    ctx->pc = 0x1a986cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
