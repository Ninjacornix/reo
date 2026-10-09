#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00173B80
// Address: 0x173b80 - 0x173bf0
void sub_00173B80_0x173b80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00173B80_0x173b80");
#endif

    switch (ctx->pc) {
        case 0x173ba8u: goto label_173ba8;
        case 0x173bb8u: goto label_173bb8;
        case 0x173bc0u: goto label_173bc0;
        case 0x173bc8u: goto label_173bc8;
        case 0x173bd4u: goto label_173bd4;
        case 0x173bdcu: goto label_173bdc;
        default: break;
    }

    ctx->pc = 0x173b80u;

    // 0x173b80: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x173b80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x173b84: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x173b84u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x173b88: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x173b88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x173b8c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x173b8cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173b90: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x173b90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x173b94: 0x8e030048  lw          $v1, 0x48($s0)
    ctx->pc = 0x173b94u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 72)));
    // 0x173b98: 0x10650011  beq         $v1, $a1, . + 4 + (0x11 << 2)
    ctx->pc = 0x173B98u;
    {
        const bool branch_taken_0x173b98 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x173B9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173B98u;
            // 0x173b9c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173b98) {
            ctx->pc = 0x173BE0u;
            goto label_173be0;
        }
    }
    ctx->pc = 0x173BA0u;
    // 0x173ba0: 0xc05cf04  jal         func_173C10
    ctx->pc = 0x173BA0u;
    SET_GPR_U32(ctx, 31, 0x173BA8u);
    ctx->pc = 0x173C10u;
    if (runtime->hasFunction(0x173C10u)) {
        auto targetFn = runtime->lookupFunction(0x173C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173BA8u; }
        if (ctx->pc != 0x173BA8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173C10_0x173c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173BA8u; }
        if (ctx->pc != 0x173BA8u) { return; }
    }
    ctx->pc = 0x173BA8u;
label_173ba8:
    // 0x173ba8: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x173BA8u;
    {
        const bool branch_taken_0x173ba8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x173BACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173BA8u;
            // 0x173bac: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x173ba8) {
            ctx->pc = 0x173BE0u;
            goto label_173be0;
        }
    }
    ctx->pc = 0x173BB0u;
    // 0x173bb0: 0xc05a7b2  jal         func_169EC8
    ctx->pc = 0x173BB0u;
    SET_GPR_U32(ctx, 31, 0x173BB8u);
    ctx->pc = 0x169EC8u;
    if (runtime->hasFunction(0x169EC8u)) {
        auto targetFn = runtime->lookupFunction(0x169EC8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173BB8u; }
        if (ctx->pc != 0x173BB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EC8_0x169ec8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173BB8u; }
        if (ctx->pc != 0x173BB8u) { return; }
    }
    ctx->pc = 0x173BB8u;
label_173bb8:
    // 0x173bb8: 0xc05cefc  jal         func_173BF0
    ctx->pc = 0x173BB8u;
    SET_GPR_U32(ctx, 31, 0x173BC0u);
    ctx->pc = 0x173BBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173BB8u;
            // 0x173bbc: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173BF0u;
    if (runtime->hasFunction(0x173BF0u)) {
        auto targetFn = runtime->lookupFunction(0x173BF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173BC0u; }
        if (ctx->pc != 0x173BC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173BF0_0x173bf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173BC0u; }
        if (ctx->pc != 0x173BC0u) { return; }
    }
    ctx->pc = 0x173BC0u;
label_173bc0:
    // 0x173bc0: 0xc05cf1c  jal         func_173C70
    ctx->pc = 0x173BC0u;
    SET_GPR_U32(ctx, 31, 0x173BC8u);
    ctx->pc = 0x173BC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173BC0u;
            // 0x173bc4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173C70u;
    if (runtime->hasFunction(0x173C70u)) {
        auto targetFn = runtime->lookupFunction(0x173C70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173BC8u; }
        if (ctx->pc != 0x173BC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173C70_0x173c70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173BC8u; }
        if (ctx->pc != 0x173BC8u) { return; }
    }
    ctx->pc = 0x173BC8u;
label_173bc8:
    // 0x173bc8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x173bc8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x173bcc: 0xc05cefc  jal         func_173BF0
    ctx->pc = 0x173BCCu;
    SET_GPR_U32(ctx, 31, 0x173BD4u);
    ctx->pc = 0x173BD0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173BCCu;
            // 0x173bd0: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x173BF0u;
    if (runtime->hasFunction(0x173BF0u)) {
        auto targetFn = runtime->lookupFunction(0x173BF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173BD4u; }
        if (ctx->pc != 0x173BD4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00173BF0_0x173bf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173BD4u; }
        if (ctx->pc != 0x173BD4u) { return; }
    }
    ctx->pc = 0x173BD4u;
label_173bd4:
    // 0x173bd4: 0xc05a7b8  jal         func_169EE0
    ctx->pc = 0x173BD4u;
    SET_GPR_U32(ctx, 31, 0x173BDCu);
    ctx->pc = 0x173BD8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x173BD4u;
            // 0x173bd8: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169EE0u;
    if (runtime->hasFunction(0x169EE0u)) {
        auto targetFn = runtime->lookupFunction(0x169EE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173BDCu; }
        if (ctx->pc != 0x173BDCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169EE0_0x169ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x173BDCu; }
        if (ctx->pc != 0x173BDCu) { return; }
    }
    ctx->pc = 0x173BDCu;
label_173bdc:
    // 0x173bdc: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x173bdcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_173be0:
    // 0x173be0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x173be0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x173be4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x173be4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x173be8: 0x3e00008  jr          $ra
    ctx->pc = 0x173BE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x173BECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x173BE8u;
            // 0x173bec: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x173BA8u: goto label_173ba8;
            case 0x173BB8u: goto label_173bb8;
            case 0x173BC0u: goto label_173bc0;
            case 0x173BC8u: goto label_173bc8;
            case 0x173BD4u: goto label_173bd4;
            case 0x173BDCu: goto label_173bdc;
            case 0x173BE0u: goto label_173be0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x173BF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
