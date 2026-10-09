#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00148680
// Address: 0x148680 - 0x148700
void sub_00148680_0x148680(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00148680_0x148680");
#endif

    switch (ctx->pc) {
        case 0x1486a8u: goto label_1486a8;
        case 0x1486d0u: goto label_1486d0;
        case 0x1486e8u: goto label_1486e8;
        default: break;
    }

    ctx->pc = 0x148680u;

    // 0x148680: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x148680u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x148684: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x148684u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x148688: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x148688u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x14868c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x14868cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148690: 0x8e020138  lw          $v0, 0x138($s0)
    ctx->pc = 0x148690u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 312)));
    // 0x148694: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x148694u;
    {
        const bool branch_taken_0x148694 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x148698u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x148694u;
            // 0x148698: 0x8e060130  lw          $a2, 0x130($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 304)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x148694) {
            ctx->pc = 0x1486B0u;
            goto label_1486b0;
        }
    }
    ctx->pc = 0x14869Cu;
    // 0x14869c: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x14869cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x1486a0: 0xc05221c  jal         func_148870
    ctx->pc = 0x1486A0u;
    SET_GPR_U32(ctx, 31, 0x1486A8u);
    ctx->pc = 0x1486A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1486A0u;
            // 0x1486a4: 0x24a5e118  addiu       $a1, $a1, -0x1EE8 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294959384));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148870u;
    if (runtime->hasFunction(0x148870u)) {
        auto targetFn = runtime->lookupFunction(0x148870u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1486A8u; }
        if (ctx->pc != 0x1486A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1486A8u; }
        if (ctx->pc != 0x1486A8u) { return; }
    }
    ctx->pc = 0x1486A8u;
label_1486a8:
    // 0x1486a8: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1486A8u;
    {
        const bool branch_taken_0x1486a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1486ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1486A8u;
            // 0x1486ac: 0xae000138  sw          $zero, 0x138($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 312), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1486a8) {
            ctx->pc = 0x1486ECu;
            goto label_1486ec;
        }
    }
    ctx->pc = 0x1486B0u;
label_1486b0:
    // 0x1486b0: 0x8e03018c  lw          $v1, 0x18C($s0)
    ctx->pc = 0x1486b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 396)));
    // 0x1486b4: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1486b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1486b8: 0x14620007  bne         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1486B8u;
    {
        const bool branch_taken_0x1486b8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1486BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1486B8u;
            // 0x1486bc: 0x24c7ffff  addiu       $a3, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1486b8) {
            ctx->pc = 0x1486D8u;
            goto label_1486d8;
        }
    }
    ctx->pc = 0x1486C0u;
    // 0x1486c0: 0x8e0501d4  lw          $a1, 0x1D4($s0)
    ctx->pc = 0x1486c0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 468)));
    // 0x1486c4: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x1486c4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x1486c8: 0xc051b76  jal         func_146DD8
    ctx->pc = 0x1486C8u;
    SET_GPR_U32(ctx, 31, 0x1486D0u);
    ctx->pc = 0x1486CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1486C8u;
            // 0x1486cc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x146DD8u;
    if (runtime->hasFunction(0x146DD8u)) {
        auto targetFn = runtime->lookupFunction(0x146DD8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1486D0u; }
        if (ctx->pc != 0x1486D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00146DD8_0x146dd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1486D0u; }
        if (ctx->pc != 0x1486D0u) { return; }
    }
    ctx->pc = 0x1486D0u;
label_1486d0:
    // 0x1486d0: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1486D0u;
    {
        const bool branch_taken_0x1486d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1486D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1486D0u;
            // 0x1486d4: 0xae000138  sw          $zero, 0x138($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 312), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1486d0) {
            ctx->pc = 0x1486ECu;
            goto label_1486ec;
        }
    }
    ctx->pc = 0x1486D8u;
label_1486d8:
    // 0x1486d8: 0x8e0501e4  lw          $a1, 0x1E4($s0)
    ctx->pc = 0x1486d8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 484)));
    // 0x1486dc: 0x8e0601f4  lw          $a2, 0x1F4($s0)
    ctx->pc = 0x1486dcu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 500)));
    // 0x1486e0: 0xc051bba  jal         func_146EE8
    ctx->pc = 0x1486E0u;
    SET_GPR_U32(ctx, 31, 0x1486E8u);
    ctx->pc = 0x1486E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1486E0u;
            // 0x1486e4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x146EE8u;
    if (runtime->hasFunction(0x146EE8u)) {
        auto targetFn = runtime->lookupFunction(0x146EE8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1486E8u; }
        if (ctx->pc != 0x1486E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00146EE8_0x146ee8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1486E8u; }
        if (ctx->pc != 0x1486E8u) { return; }
    }
    ctx->pc = 0x1486E8u;
label_1486e8:
    // 0x1486e8: 0xae000138  sw          $zero, 0x138($s0)
    ctx->pc = 0x1486e8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 312), GPR_U32(ctx, 0));
label_1486ec:
    // 0x1486ec: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1486ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1486f0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1486f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1486f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1486F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1486F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1486F4u;
            // 0x1486f8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1486A8u: goto label_1486a8;
            case 0x1486B0u: goto label_1486b0;
            case 0x1486D0u: goto label_1486d0;
            case 0x1486D8u: goto label_1486d8;
            case 0x1486E8u: goto label_1486e8;
            case 0x1486ECu: goto label_1486ec;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1486FCu;
    // 0x1486fc: 0x0  nop
    ctx->pc = 0x1486fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
