#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173A70
// Address: 0x173a70 - 0x173af0
void sub_00173A70_0x173a70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173A70_0x173a70");
#endif

    switch (ctx->pc) {
        case 0x173a84u: goto label_173a84;
        case 0x173ab0u: goto label_173ab0;
        case 0x173ac4u: goto label_173ac4;
        case 0x173ad8u: goto label_173ad8;
        default: break;
    }

    ctx->pc = 0x173a70u;

    // 0x173a70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x173a70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x173a74: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x173a74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x173a78: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x173a78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x173a7c: 0xc05a78c  jal         func_169E30
    ctx->pc = 0x173A7Cu;
    SET_GPR_U32(ctx, 31, 0x173A84u);
    ctx->pc = 0x173A80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173A7Cu;
            // 0x173a80: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169E30u;
    if (runtime->hasFunction(0x169E30u)) {
        auto targetFn = runtime->lookupFunction(0x169E30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173A84u; }
        if (ctx->pc != 0x173A84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173A84u; }
        if (ctx->pc != 0x173A84u) { return; }
    }
    ctx->pc = 0x173A84u;
label_173a84:
    // 0x173a84: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x173a84u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x173a88: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x173a88u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173a8c: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x173A8Cu;
    {
        const bool branch_taken_0x173a8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x173A90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173A8Cu;
            // 0x173a90: 0x34a50132  ori         $a1, $a1, 0x132 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)306);
        ctx->in_delay_slot = false;
        if (branch_taken_0x173a8c) {
            ctx->pc = 0x173AA8u;
            goto label_173aa8;
        }
    }
    ctx->pc = 0x173A94u;
    // 0x173a94: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x173a94u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173a98: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x173a98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173a9c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x173a9cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173aa0: 0x805a704  j           func_169C10
    ctx->pc = 0x173AA0u;
    ctx->pc = 0x173AA4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173AA0u;
            // 0x173aa4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x173AA8u;
label_173aa8:
    // 0x173aa8: 0xc05d58a  jal         func_175628
    ctx->pc = 0x173AA8u;
    SET_GPR_U32(ctx, 31, 0x173AB0u);
    ctx->pc = 0x173AACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173AA8u;
            // 0x173aac: 0x2405002f  addiu       $a1, $zero, 0x2F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 47));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173AB0u; }
        if (ctx->pc != 0x173AB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173AB0u; }
        if (ctx->pc != 0x173AB0u) { return; }
    }
    ctx->pc = 0x173AB0u;
label_173ab0:
    // 0x173ab0: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x173ab0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x173ab4: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x173AB4u;
    {
        const bool branch_taken_0x173ab4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x173AB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173AB4u;
            // 0x173ab8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173ab4) {
            ctx->pc = 0x173AD0u;
            goto label_173ad0;
        }
    }
    ctx->pc = 0x173ABCu;
    // 0x173abc: 0xc05c8b0  jal         func_1722C0
    ctx->pc = 0x173ABCu;
    SET_GPR_U32(ctx, 31, 0x173AC4u);
    ctx->pc = 0x1722C0u;
    if (runtime->hasFunction(0x1722C0u)) {
        auto targetFn = runtime->lookupFunction(0x1722C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173AC4u; }
        if (ctx->pc != 0x173AC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001722C0_0x1722c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173AC4u; }
        if (ctx->pc != 0x173AC4u) { return; }
    }
    ctx->pc = 0x173AC4u;
label_173ac4:
    // 0x173ac4: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x173AC4u;
    {
        const bool branch_taken_0x173ac4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x173AC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173AC4u;
            // 0x173ac8: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173ac4) {
            ctx->pc = 0x173ADCu;
            goto label_173adc;
        }
    }
    ctx->pc = 0x173ACCu;
    // 0x173acc: 0x0  nop
    ctx->pc = 0x173accu;
    // NOP
label_173ad0:
    // 0x173ad0: 0xc05cebc  jal         func_173AF0
    ctx->pc = 0x173AD0u;
    SET_GPR_U32(ctx, 31, 0x173AD8u);
    ctx->pc = 0x173AF0u;
    if (runtime->hasFunction(0x173AF0u)) {
        auto targetFn = runtime->lookupFunction(0x173AF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173AD8u; }
        if (ctx->pc != 0x173AD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173AF0_0x173af0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173AD8u; }
        if (ctx->pc != 0x173AD8u) { return; }
    }
    ctx->pc = 0x173AD8u;
label_173ad8:
    // 0x173ad8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x173ad8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_173adc:
    // 0x173adc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x173adcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x173ae0: 0xae030044  sw          $v1, 0x44($s0)
    ctx->pc = 0x173ae0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 3));
    // 0x173ae4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x173ae4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x173ae8: 0x3e00008  jr          $ra
    ctx->pc = 0x173AE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x173AECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173AE8u;
            // 0x173aec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x173A84u: goto label_173a84;
            case 0x173AA8u: goto label_173aa8;
            case 0x173AB0u: goto label_173ab0;
            case 0x173AC4u: goto label_173ac4;
            case 0x173AD0u: goto label_173ad0;
            case 0x173AD8u: goto label_173ad8;
            case 0x173ADCu: goto label_173adc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x173AF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
