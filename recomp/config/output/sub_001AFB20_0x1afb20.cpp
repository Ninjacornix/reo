#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AFB20
// Address: 0x1afb20 - 0x1afce0
void sub_001AFB20_0x1afb20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AFB20_0x1afb20");
#endif

    switch (ctx->pc) {
        case 0x1afb34u: goto label_1afb34;
        case 0x1afb48u: goto label_1afb48;
        case 0x1afb54u: goto label_1afb54;
        case 0x1afb94u: goto label_1afb94;
        case 0x1afbccu: goto label_1afbcc;
        case 0x1afbdcu: goto label_1afbdc;
        case 0x1afc00u: goto label_1afc00;
        case 0x1afc38u: goto label_1afc38;
        case 0x1afc48u: goto label_1afc48;
        case 0x1afc80u: goto label_1afc80;
        case 0x1afcc4u: goto label_1afcc4;
        case 0x1afcd4u: goto label_1afcd4;
        default: break;
    }

    ctx->pc = 0x1afb20u;

    // 0x1afb20: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1afb20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1afb24: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1afb24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1afb28: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1afb28u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1afb2c: 0xc06c8b0  jal         func_1B22C0
    ctx->pc = 0x1AFB2Cu;
    SET_GPR_U32(ctx, 31, 0x1AFB34u);
    ctx->pc = 0x1AFB30u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFB2Cu;
            // 0x1afb30: 0x7fb00000  sq          $s0, 0x0($sp) (Delay Slot)
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B22C0u;
    if (runtime->hasFunction(0x1B22C0u)) {
        auto targetFn = runtime->lookupFunction(0x1B22C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFB34u; }
        if (ctx->pc != 0x1AFB34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B22C0_0x1b22c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFB34u; }
        if (ctx->pc != 0x1AFB34u) { return; }
    }
    ctx->pc = 0x1AFB34u;
label_1afb34:
    // 0x1afb34: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1afb34u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1afb38: 0x3c11002c  lui         $s1, 0x2C
    ctx->pc = 0x1afb38u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)44 << 16));
    // 0x1afb3c: 0x8c308e10  lw          $s0, -0x71F0($at)
    ctx->pc = 0x1afb3cu;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294938128)));
    // 0x1afb40: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1AFB40u;
    {
        const bool branch_taken_0x1afb40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFB44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFB40u;
            // 0x1afb44: 0x26318e20  addiu       $s1, $s1, -0x71E0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294938144));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afb40) {
            ctx->pc = 0x1AFB5Cu;
            goto label_1afb5c;
        }
    }
    ctx->pc = 0x1AFB48u;
label_1afb48:
    // 0x1afb48: 0x8e220000  lw          $v0, 0x0($s1)
    ctx->pc = 0x1afb48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1afb4c: 0x40f809  jalr        $v0
    ctx->pc = 0x1AFB4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1AFB54u);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1AFB54u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFB34u: goto label_1afb34;
            case 0x1AFB48u: goto label_1afb48;
            case 0x1AFB54u: goto label_1afb54;
            case 0x1AFB5Cu: goto label_1afb5c;
            case 0x1AFB94u: goto label_1afb94;
            case 0x1AFBC4u: goto label_1afbc4;
            case 0x1AFBCCu: goto label_1afbcc;
            case 0x1AFBD4u: goto label_1afbd4;
            case 0x1AFBDCu: goto label_1afbdc;
            case 0x1AFBE0u: goto label_1afbe0;
            case 0x1AFC00u: goto label_1afc00;
            case 0x1AFC30u: goto label_1afc30;
            case 0x1AFC38u: goto label_1afc38;
            case 0x1AFC40u: goto label_1afc40;
            case 0x1AFC48u: goto label_1afc48;
            case 0x1AFC4Cu: goto label_1afc4c;
            case 0x1AFC80u: goto label_1afc80;
            case 0x1AFCB0u: goto label_1afcb0;
            case 0x1AFCC4u: goto label_1afcc4;
            case 0x1AFCCCu: goto label_1afccc;
            case 0x1AFCD4u: goto label_1afcd4;
            case 0x1AFCD8u: goto label_1afcd8;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1AFB54u; }
            if (ctx->pc != 0x1AFB54u) { return; }
        }
        }
    }
    ctx->pc = 0x1AFB54u;
label_1afb54:
    // 0x1afb54: 0x2610ffff  addiu       $s0, $s0, -0x1
    ctx->pc = 0x1afb54u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 4294967295));
    // 0x1afb58: 0x26310004  addiu       $s1, $s1, 0x4
    ctx->pc = 0x1afb58u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4));
label_1afb5c:
    // 0x1afb5c: 0x0  nop
    ctx->pc = 0x1afb5cu;
    // NOP
    // 0x1afb60: 0x1600fff9  bnez        $s0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1AFB60u;
    {
        const bool branch_taken_0x1afb60 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1afb60) {
            ctx->pc = 0x1AFB48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1afb48;
        }
    }
    ctx->pc = 0x1AFB68u;
    // 0x1afb68: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1afb68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1afb6c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1afb6cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1afb70: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1afb70u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1afb74: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFB74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AFB78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFB74u;
            // 0x1afb78: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFB34u: goto label_1afb34;
            case 0x1AFB48u: goto label_1afb48;
            case 0x1AFB54u: goto label_1afb54;
            case 0x1AFB5Cu: goto label_1afb5c;
            case 0x1AFB94u: goto label_1afb94;
            case 0x1AFBC4u: goto label_1afbc4;
            case 0x1AFBCCu: goto label_1afbcc;
            case 0x1AFBD4u: goto label_1afbd4;
            case 0x1AFBDCu: goto label_1afbdc;
            case 0x1AFBE0u: goto label_1afbe0;
            case 0x1AFC00u: goto label_1afc00;
            case 0x1AFC30u: goto label_1afc30;
            case 0x1AFC38u: goto label_1afc38;
            case 0x1AFC40u: goto label_1afc40;
            case 0x1AFC48u: goto label_1afc48;
            case 0x1AFC4Cu: goto label_1afc4c;
            case 0x1AFC80u: goto label_1afc80;
            case 0x1AFCB0u: goto label_1afcb0;
            case 0x1AFCC4u: goto label_1afcc4;
            case 0x1AFCCCu: goto label_1afccc;
            case 0x1AFCD4u: goto label_1afcd4;
            case 0x1AFCD8u: goto label_1afcd8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFB7Cu;
    // 0x1afb7c: 0x0  nop
    ctx->pc = 0x1afb7cu;
    // NOP
    // 0x1afb80: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1afb80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1afb84: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1afb84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1afb88: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1afb88u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1afb8c: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1AFB8Cu;
    SET_GPR_U32(ctx, 31, 0x1AFB94u);
    ctx->pc = 0x1AFB90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFB8Cu;
            // 0x1afb90: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFB94u; }
        if (ctx->pc != 0x1AFB94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFB94u; }
        if (ctx->pc != 0x1AFB94u) { return; }
    }
    ctx->pc = 0x1AFB94u;
label_1afb94:
    // 0x1afb94: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1afb94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1afb98: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1AFB98u;
    {
        const bool branch_taken_0x1afb98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFB9Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFB98u;
            // 0x1afb9c: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afb98) {
            ctx->pc = 0x1AFBDCu;
            goto label_1afbdc;
        }
    }
    ctx->pc = 0x1AFBA0u;
    // 0x1afba0: 0x1043000e  beq         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1AFBA0u;
    {
        const bool branch_taken_0x1afba0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afba0) {
            ctx->pc = 0x1AFBDCu;
            goto label_1afbdc;
        }
    }
    ctx->pc = 0x1AFBA8u;
    // 0x1afba8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1afba8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1afbac: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AFBACu;
    {
        const bool branch_taken_0x1afbac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFBB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFBACu;
            // 0x1afbb0: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afbac) {
            ctx->pc = 0x1AFBD4u;
            goto label_1afbd4;
        }
    }
    ctx->pc = 0x1AFBB4u;
    // 0x1afbb4: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFBB4u;
    {
        const bool branch_taken_0x1afbb4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFBB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFBB4u;
            // 0x1afbb8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afbb4) {
            ctx->pc = 0x1AFBC4u;
            goto label_1afbc4;
        }
    }
    ctx->pc = 0x1AFBBCu;
    // 0x1afbbc: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1AFBBCu;
    {
        const bool branch_taken_0x1afbbc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFBC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFBBCu;
            // 0x1afbc0: 0xdfbf0010  ld          $ra, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afbbc) {
            ctx->pc = 0x1AFBE0u;
            goto label_1afbe0;
        }
    }
    ctx->pc = 0x1AFBC4u;
label_1afbc4:
    // 0x1afbc4: 0xc204074  jal         func_8101D0
    ctx->pc = 0x1AFBC4u;
    SET_GPR_U32(ctx, 31, 0x1AFBCCu);
    ctx->pc = 0x8101D0u;
    {
        auto targetFn = runtime->lookupFunction(0x8101D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFBCCu; }
        if (ctx->pc != 0x1AFBCCu) { return; }
    }
    ctx->pc = 0x1AFBCCu;
label_1afbcc:
    // 0x1afbcc: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFBCCu;
    {
        const bool branch_taken_0x1afbcc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afbcc) {
            ctx->pc = 0x1AFBDCu;
            goto label_1afbdc;
        }
    }
    ctx->pc = 0x1AFBD4u;
label_1afbd4:
    // 0x1afbd4: 0xc2046ec  jal         func_811BB0
    ctx->pc = 0x1AFBD4u;
    SET_GPR_U32(ctx, 31, 0x1AFBDCu);
    ctx->pc = 0x811BB0u;
    {
        auto targetFn = runtime->lookupFunction(0x811BB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFBDCu; }
        if (ctx->pc != 0x1AFBDCu) { return; }
    }
    ctx->pc = 0x1AFBDCu;
label_1afbdc:
    // 0x1afbdc: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1afbdcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1afbe0:
    // 0x1afbe0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1afbe0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1afbe4: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFBE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AFBE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFBE4u;
            // 0x1afbe8: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFB34u: goto label_1afb34;
            case 0x1AFB48u: goto label_1afb48;
            case 0x1AFB54u: goto label_1afb54;
            case 0x1AFB5Cu: goto label_1afb5c;
            case 0x1AFB94u: goto label_1afb94;
            case 0x1AFBC4u: goto label_1afbc4;
            case 0x1AFBCCu: goto label_1afbcc;
            case 0x1AFBD4u: goto label_1afbd4;
            case 0x1AFBDCu: goto label_1afbdc;
            case 0x1AFBE0u: goto label_1afbe0;
            case 0x1AFC00u: goto label_1afc00;
            case 0x1AFC30u: goto label_1afc30;
            case 0x1AFC38u: goto label_1afc38;
            case 0x1AFC40u: goto label_1afc40;
            case 0x1AFC48u: goto label_1afc48;
            case 0x1AFC4Cu: goto label_1afc4c;
            case 0x1AFC80u: goto label_1afc80;
            case 0x1AFCB0u: goto label_1afcb0;
            case 0x1AFCC4u: goto label_1afcc4;
            case 0x1AFCCCu: goto label_1afccc;
            case 0x1AFCD4u: goto label_1afcd4;
            case 0x1AFCD8u: goto label_1afcd8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFBECu;
    // 0x1afbec: 0x0  nop
    ctx->pc = 0x1afbecu;
    // NOP
    // 0x1afbf0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1afbf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1afbf4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1afbf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1afbf8: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1AFBF8u;
    SET_GPR_U32(ctx, 31, 0x1AFC00u);
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFC00u; }
        if (ctx->pc != 0x1AFC00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFC00u; }
        if (ctx->pc != 0x1AFC00u) { return; }
    }
    ctx->pc = 0x1AFC00u;
label_1afc00:
    // 0x1afc00: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1afc00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1afc04: 0x10430010  beq         $v0, $v1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1AFC04u;
    {
        const bool branch_taken_0x1afc04 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFC08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFC04u;
            // 0x1afc08: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afc04) {
            ctx->pc = 0x1AFC48u;
            goto label_1afc48;
        }
    }
    ctx->pc = 0x1AFC0Cu;
    // 0x1afc0c: 0x1043000e  beq         $v0, $v1, . + 4 + (0xE << 2)
    ctx->pc = 0x1AFC0Cu;
    {
        const bool branch_taken_0x1afc0c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afc0c) {
            ctx->pc = 0x1AFC48u;
            goto label_1afc48;
        }
    }
    ctx->pc = 0x1AFC14u;
    // 0x1afc14: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1afc14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1afc18: 0x10430009  beq         $v0, $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AFC18u;
    {
        const bool branch_taken_0x1afc18 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afc18) {
            ctx->pc = 0x1AFC40u;
            goto label_1afc40;
        }
    }
    ctx->pc = 0x1AFC20u;
    // 0x1afc20: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFC20u;
    {
        const bool branch_taken_0x1afc20 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afc20) {
            ctx->pc = 0x1AFC30u;
            goto label_1afc30;
        }
    }
    ctx->pc = 0x1AFC28u;
    // 0x1afc28: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1AFC28u;
    {
        const bool branch_taken_0x1afc28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFC2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFC28u;
            // 0x1afc2c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afc28) {
            ctx->pc = 0x1AFC4Cu;
            goto label_1afc4c;
        }
    }
    ctx->pc = 0x1AFC30u;
label_1afc30:
    // 0x1afc30: 0xc2042b0  jal         func_810AC0
    ctx->pc = 0x1AFC30u;
    SET_GPR_U32(ctx, 31, 0x1AFC38u);
    ctx->pc = 0x810AC0u;
    {
        auto targetFn = runtime->lookupFunction(0x810AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFC38u; }
        if (ctx->pc != 0x1AFC38u) { return; }
    }
    ctx->pc = 0x1AFC38u;
label_1afc38:
    // 0x1afc38: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFC38u;
    {
        const bool branch_taken_0x1afc38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afc38) {
            ctx->pc = 0x1AFC48u;
            goto label_1afc48;
        }
    }
    ctx->pc = 0x1AFC40u;
label_1afc40:
    // 0x1afc40: 0xc204ae0  jal         func_812B80
    ctx->pc = 0x1AFC40u;
    SET_GPR_U32(ctx, 31, 0x1AFC48u);
    ctx->pc = 0x812B80u;
    {
        auto targetFn = runtime->lookupFunction(0x812B80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFC48u; }
        if (ctx->pc != 0x1AFC48u) { return; }
    }
    ctx->pc = 0x1AFC48u;
label_1afc48:
    // 0x1afc48: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1afc48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1afc4c:
    // 0x1afc4c: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFC4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AFC50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFC4Cu;
            // 0x1afc50: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFB34u: goto label_1afb34;
            case 0x1AFB48u: goto label_1afb48;
            case 0x1AFB54u: goto label_1afb54;
            case 0x1AFB5Cu: goto label_1afb5c;
            case 0x1AFB94u: goto label_1afb94;
            case 0x1AFBC4u: goto label_1afbc4;
            case 0x1AFBCCu: goto label_1afbcc;
            case 0x1AFBD4u: goto label_1afbd4;
            case 0x1AFBDCu: goto label_1afbdc;
            case 0x1AFBE0u: goto label_1afbe0;
            case 0x1AFC00u: goto label_1afc00;
            case 0x1AFC30u: goto label_1afc30;
            case 0x1AFC38u: goto label_1afc38;
            case 0x1AFC40u: goto label_1afc40;
            case 0x1AFC48u: goto label_1afc48;
            case 0x1AFC4Cu: goto label_1afc4c;
            case 0x1AFC80u: goto label_1afc80;
            case 0x1AFCB0u: goto label_1afcb0;
            case 0x1AFCC4u: goto label_1afcc4;
            case 0x1AFCCCu: goto label_1afccc;
            case 0x1AFCD4u: goto label_1afcd4;
            case 0x1AFCD8u: goto label_1afcd8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFC54u;
    // 0x1afc54: 0x0  nop
    ctx->pc = 0x1afc54u;
    // NOP
    // 0x1afc58: 0x0  nop
    ctx->pc = 0x1afc58u;
    // NOP
    // 0x1afc5c: 0x0  nop
    ctx->pc = 0x1afc5cu;
    // NOP
    // 0x1afc60: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1afc60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1afc64: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1afc64u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1afc68: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1afc68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1afc6c: 0x902343fa  lbu         $v1, 0x43FA($at)
    ctx->pc = 0x1afc6cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17402)));
    // 0x1afc70: 0x10600018  beqz        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x1AFC70u;
    {
        const bool branch_taken_0x1afc70 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afc70) {
            ctx->pc = 0x1AFCD4u;
            goto label_1afcd4;
        }
    }
    ctx->pc = 0x1AFC78u;
    // 0x1afc78: 0xc06c0c0  jal         func_1B0300
    ctx->pc = 0x1AFC78u;
    SET_GPR_U32(ctx, 31, 0x1AFC80u);
    ctx->pc = 0x1B0300u;
    if (runtime->hasFunction(0x1B0300u)) {
        auto targetFn = runtime->lookupFunction(0x1B0300u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFC80u; }
        if (ctx->pc != 0x1AFC80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0300_0x1b0300(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFC80u; }
        if (ctx->pc != 0x1AFC80u) { return; }
    }
    ctx->pc = 0x1AFC80u;
label_1afc80:
    // 0x1afc80: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1afc80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1afc84: 0x10430013  beq         $v0, $v1, . + 4 + (0x13 << 2)
    ctx->pc = 0x1AFC84u;
    {
        const bool branch_taken_0x1afc84 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFC88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFC84u;
            // 0x1afc88: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afc84) {
            ctx->pc = 0x1AFCD4u;
            goto label_1afcd4;
        }
    }
    ctx->pc = 0x1AFC8Cu;
    // 0x1afc8c: 0x10430011  beq         $v0, $v1, . + 4 + (0x11 << 2)
    ctx->pc = 0x1AFC8Cu;
    {
        const bool branch_taken_0x1afc8c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afc8c) {
            ctx->pc = 0x1AFCD4u;
            goto label_1afcd4;
        }
    }
    ctx->pc = 0x1AFC94u;
    // 0x1afc94: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1afc94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1afc98: 0x1043000c  beq         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1AFC98u;
    {
        const bool branch_taken_0x1afc98 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        if (branch_taken_0x1afc98) {
            ctx->pc = 0x1AFCCCu;
            goto label_1afccc;
        }
    }
    ctx->pc = 0x1AFCA0u;
    // 0x1afca0: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFCA0u;
    {
        const bool branch_taken_0x1afca0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFCA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFCA0u;
            // 0x1afca4: 0x3c01004c  lui         $at, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afca0) {
            ctx->pc = 0x1AFCB0u;
            goto label_1afcb0;
        }
    }
    ctx->pc = 0x1AFCA8u;
    // 0x1afca8: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1AFCA8u;
    {
        const bool branch_taken_0x1afca8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFCACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFCA8u;
            // 0x1afcac: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afca8) {
            ctx->pc = 0x1AFCD8u;
            goto label_1afcd8;
        }
    }
    ctx->pc = 0x1AFCB0u;
label_1afcb0:
    // 0x1afcb0: 0x9023ae94  lbu         $v1, -0x516C($at)
    ctx->pc = 0x1afcb0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294946452)));
    // 0x1afcb4: 0x14600007  bnez        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1AFCB4u;
    {
        const bool branch_taken_0x1afcb4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1afcb4) {
            ctx->pc = 0x1AFCD4u;
            goto label_1afcd4;
        }
    }
    ctx->pc = 0x1AFCBCu;
    // 0x1afcbc: 0xc204080  jal         func_810200
    ctx->pc = 0x1AFCBCu;
    SET_GPR_U32(ctx, 31, 0x1AFCC4u);
    ctx->pc = 0x810200u;
    {
        auto targetFn = runtime->lookupFunction(0x810200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFCC4u; }
        if (ctx->pc != 0x1AFCC4u) { return; }
    }
    ctx->pc = 0x1AFCC4u;
label_1afcc4:
    // 0x1afcc4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1AFCC4u;
    {
        const bool branch_taken_0x1afcc4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1afcc4) {
            ctx->pc = 0x1AFCD4u;
            goto label_1afcd4;
        }
    }
    ctx->pc = 0x1AFCCCu;
label_1afccc:
    // 0x1afccc: 0xc204778  jal         func_811DE0
    ctx->pc = 0x1AFCCCu;
    SET_GPR_U32(ctx, 31, 0x1AFCD4u);
    ctx->pc = 0x811DE0u;
    {
        auto targetFn = runtime->lookupFunction(0x811DE0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AFCD4u; }
        if (ctx->pc != 0x1AFCD4u) { return; }
    }
    ctx->pc = 0x1AFCD4u;
label_1afcd4:
    // 0x1afcd4: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1afcd4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1afcd8:
    // 0x1afcd8: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFCD8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AFCDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFCD8u;
            // 0x1afcdc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFB34u: goto label_1afb34;
            case 0x1AFB48u: goto label_1afb48;
            case 0x1AFB54u: goto label_1afb54;
            case 0x1AFB5Cu: goto label_1afb5c;
            case 0x1AFB94u: goto label_1afb94;
            case 0x1AFBC4u: goto label_1afbc4;
            case 0x1AFBCCu: goto label_1afbcc;
            case 0x1AFBD4u: goto label_1afbd4;
            case 0x1AFBDCu: goto label_1afbdc;
            case 0x1AFBE0u: goto label_1afbe0;
            case 0x1AFC00u: goto label_1afc00;
            case 0x1AFC30u: goto label_1afc30;
            case 0x1AFC38u: goto label_1afc38;
            case 0x1AFC40u: goto label_1afc40;
            case 0x1AFC48u: goto label_1afc48;
            case 0x1AFC4Cu: goto label_1afc4c;
            case 0x1AFC80u: goto label_1afc80;
            case 0x1AFCB0u: goto label_1afcb0;
            case 0x1AFCC4u: goto label_1afcc4;
            case 0x1AFCCCu: goto label_1afccc;
            case 0x1AFCD4u: goto label_1afcd4;
            case 0x1AFCD8u: goto label_1afcd8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFCE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
