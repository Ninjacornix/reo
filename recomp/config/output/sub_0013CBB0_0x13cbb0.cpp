#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013CBB0
// Address: 0x13cbb0 - 0x13ccb8
void sub_0013CBB0_0x13cbb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013CBB0_0x13cbb0");
#endif

    switch (ctx->pc) {
        case 0x13cbd8u: goto label_13cbd8;
        case 0x13cbe8u: goto label_13cbe8;
        case 0x13cbf0u: goto label_13cbf0;
        case 0x13cc08u: goto label_13cc08;
        case 0x13cc28u: goto label_13cc28;
        case 0x13cc40u: goto label_13cc40;
        case 0x13cc70u: goto label_13cc70;
        case 0x13cc9cu: goto label_13cc9c;
        default: break;
    }

    ctx->pc = 0x13cbb0u;

    // 0x13cbb0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13cbb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13cbb4: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x13cbb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x13cbb8: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x13cbb8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13cbbc: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x13cbbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x13cbc0: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x13cbc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x13cbc4: 0x16200006  bnez        $s1, . + 4 + (0x6 << 2)
    ctx->pc = 0x13CBC4u;
    {
        const bool branch_taken_0x13cbc4 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x13CBC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CBC4u;
            // 0x13cbc8: 0xffbf0028  sd          $ra, 0x28($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13cbc4) {
            ctx->pc = 0x13CBE0u;
            goto label_13cbe0;
        }
    }
    ctx->pc = 0x13CBCCu;
    // 0x13cbcc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13cbccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13cbd0: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13CBD0u;
    SET_GPR_U32(ctx, 31, 0x13CBD8u);
    ctx->pc = 0x13CBD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13CBD0u;
            // 0x13cbd4: 0x2484d308  addiu       $a0, $a0, -0x2CF8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955784));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CBD8u; }
        if (ctx->pc != 0x13CBD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CBD8u; }
        if (ctx->pc != 0x13CBD8u) { return; }
    }
    ctx->pc = 0x13CBD8u;
label_13cbd8:
    // 0x13cbd8: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x13CBD8u;
    {
        const bool branch_taken_0x13cbd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13CBDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CBD8u;
            // 0x13cbdc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13cbd8) {
            ctx->pc = 0x13CCA0u;
            goto label_13cca0;
        }
    }
    ctx->pc = 0x13CBE0u;
label_13cbe0:
    // 0x13cbe0: 0xc04f526  jal         func_13D498
    ctx->pc = 0x13CBE0u;
    SET_GPR_U32(ctx, 31, 0x13CBE8u);
    ctx->pc = 0x13CBE4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13CBE0u;
            // 0x13cbe4: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D498u;
    if (runtime->hasFunction(0x13D498u)) {
        auto targetFn = runtime->lookupFunction(0x13D498u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CBE8u; }
        if (ctx->pc != 0x13CBE8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D498_0x13d498(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CBE8u; }
        if (ctx->pc != 0x13CBE8u) { return; }
    }
    ctx->pc = 0x13CBE8u;
label_13cbe8:
    // 0x13cbe8: 0xc04f2d4  jal         func_13CB50
    ctx->pc = 0x13CBE8u;
    SET_GPR_U32(ctx, 31, 0x13CBF0u);
    ctx->pc = 0x13CB50u;
    if (runtime->hasFunction(0x13CB50u)) {
        auto targetFn = runtime->lookupFunction(0x13CB50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CBF0u; }
        if (ctx->pc != 0x13CBF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CB50_0x13cb50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CBF0u; }
        if (ctx->pc != 0x13CBF0u) { return; }
    }
    ctx->pc = 0x13CBF0u;
label_13cbf0:
    // 0x13cbf0: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x13cbf0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13cbf4: 0x56400006  bnel        $s2, $zero, . + 4 + (0x6 << 2)
    ctx->pc = 0x13CBF4u;
    {
        const bool branch_taken_0x13cbf4 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x13cbf4) {
            ctx->pc = 0x13CBF8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13CBF4u;
            // 0x13cbf8: 0xa2400001  sb          $zero, 0x1($s2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13CC10u;
            goto label_13cc10;
        }
    }
    ctx->pc = 0x13CBFCu;
    // 0x13cbfc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13cbfcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x13cc00: 0xc04f53e  jal         func_13D4F8
    ctx->pc = 0x13CC00u;
    SET_GPR_U32(ctx, 31, 0x13CC08u);
    ctx->pc = 0x13CC04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13CC00u;
            // 0x13cc04: 0x2484d338  addiu       $a0, $a0, -0x2CC8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294955832));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CC08u; }
        if (ctx->pc != 0x13CC08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CC08u; }
        if (ctx->pc != 0x13CC08u) { return; }
    }
    ctx->pc = 0x13CC08u;
label_13cc08:
    // 0x13cc08: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x13CC08u;
    {
        const bool branch_taken_0x13cc08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x13cc08) {
            ctx->pc = 0x13CC94u;
            goto label_13cc94;
        }
    }
    ctx->pc = 0x13CC10u;
label_13cc10:
    // 0x13cc10: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13cc10u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13cc14: 0xae510008  sw          $s1, 0x8($s2)
    ctx->pc = 0x13cc14u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 8), GPR_U32(ctx, 17));
    // 0x13cc18: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x13cc18u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13cc1c: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x13cc1cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x13cc20: 0x40f809  jalr        $v0
    ctx->pc = 0x13CC20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13CC28u);
        ctx->pc = 0x13CC24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CC20u;
            // 0x13cc24: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13CC28u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CBD8u: goto label_13cbd8;
            case 0x13CBE0u: goto label_13cbe0;
            case 0x13CBE8u: goto label_13cbe8;
            case 0x13CBF0u: goto label_13cbf0;
            case 0x13CC08u: goto label_13cc08;
            case 0x13CC10u: goto label_13cc10;
            case 0x13CC28u: goto label_13cc28;
            case 0x13CC40u: goto label_13cc40;
            case 0x13CC60u: goto label_13cc60;
            case 0x13CC70u: goto label_13cc70;
            case 0x13CC94u: goto label_13cc94;
            case 0x13CC9Cu: goto label_13cc9c;
            case 0x13CCA0u: goto label_13cca0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13CC28u; }
            if (ctx->pc != 0x13CC28u) { return; }
        }
        }
    }
    ctx->pc = 0x13CC28u;
label_13cc28:
    // 0x13cc28: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x13cc28u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x13cc2c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x13cc2cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13cc30: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13cc30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13cc34: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x13cc34u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x13cc38: 0x40f809  jalr        $v0
    ctx->pc = 0x13CC38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13CC40u);
        ctx->pc = 0x13CC3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CC38u;
            // 0x13cc3c: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13CC40u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CBD8u: goto label_13cbd8;
            case 0x13CBE0u: goto label_13cbe0;
            case 0x13CBE8u: goto label_13cbe8;
            case 0x13CBF0u: goto label_13cbf0;
            case 0x13CC08u: goto label_13cc08;
            case 0x13CC10u: goto label_13cc10;
            case 0x13CC28u: goto label_13cc28;
            case 0x13CC40u: goto label_13cc40;
            case 0x13CC60u: goto label_13cc60;
            case 0x13CC70u: goto label_13cc70;
            case 0x13CC94u: goto label_13cc94;
            case 0x13CC9Cu: goto label_13cc9c;
            case 0x13CCA0u: goto label_13cca0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13CC40u; }
            if (ctx->pc != 0x13CC40u) { return; }
        }
        }
    }
    ctx->pc = 0x13CC40u;
label_13cc40:
    // 0x13cc40: 0x2403000a  addiu       $v1, $zero, 0xA
    ctx->pc = 0x13cc40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x13cc44: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x13cc44u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x13cc48: 0x2404000f  addiu       $a0, $zero, 0xF
    ctx->pc = 0x13cc48u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x13cc4c: 0x1010c0  sll         $v0, $s0, 3
    ctx->pc = 0x13cc4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 16), 3));
    // 0x13cc50: 0xae500018  sw          $s0, 0x18($s2)
    ctx->pc = 0x13cc50u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 24), GPR_U32(ctx, 16));
    // 0x13cc54: 0x43001a  div         $zero, $v0, $v1
    ctx->pc = 0x13cc54u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x13cc58: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x13CC58u;
    {
        const bool branch_taken_0x13cc58 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x13cc58) {
            ctx->pc = 0x13CC5Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13CC58u;
            // 0x13cc5c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x13CC60u;
            goto label_13cc60;
        }
    }
    ctx->pc = 0x13CC60u;
label_13cc60:
    // 0x13cc60: 0x26430230  addiu       $v1, $s2, 0x230
    ctx->pc = 0x13cc60u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), 560));
    // 0x13cc64: 0x1012  mflo        $v0
    ctx->pc = 0x13cc64u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x13cc68: 0xae420014  sw          $v0, 0x14($s2)
    ctx->pc = 0x13cc68u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 2));
    // 0x13cc6c: 0x0  nop
    ctx->pc = 0x13cc6cu;
    // NOP
label_13cc70:
    // 0x13cc70: 0x2484ffff  addiu       $a0, $a0, -0x1
    ctx->pc = 0x13cc70u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x13cc74: 0xac600000  sw          $zero, 0x0($v1)
    ctx->pc = 0x13cc74u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x13cc78: 0x0  nop
    ctx->pc = 0x13cc78u;
    // NOP
    // 0x13cc7c: 0x0  nop
    ctx->pc = 0x13cc7cu;
    // NOP
    // 0x13cc80: 0x0  nop
    ctx->pc = 0x13cc80u;
    // NOP
    // 0x13cc84: 0x481fffa  bgez        $a0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x13CC84u;
    {
        const bool branch_taken_0x13cc84 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x13CC88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CC84u;
            // 0x13cc88: 0x2463ffe0  addiu       $v1, $v1, -0x20 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967264));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13cc84) {
            ctx->pc = 0x13CC70u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13cc70;
        }
    }
    ctx->pc = 0x13CC8Cu;
    // 0x13cc8c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13cc8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13cc90: 0xa2420000  sb          $v0, 0x0($s2)
    ctx->pc = 0x13cc90u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 2));
label_13cc94:
    // 0x13cc94: 0xc04f52e  jal         func_13D4B8
    ctx->pc = 0x13CC94u;
    SET_GPR_U32(ctx, 31, 0x13CC9Cu);
    ctx->pc = 0x13CC98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13CC94u;
            // 0x13cc98: 0x3a0202d  daddu       $a0, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4B8u;
    if (runtime->hasFunction(0x13D4B8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CC9Cu; }
        if (ctx->pc != 0x13CC9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D4B8_0x13d4b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13CC9Cu; }
        if (ctx->pc != 0x13CC9Cu) { return; }
    }
    ctx->pc = 0x13CC9Cu;
label_13cc9c:
    // 0x13cc9c: 0x240102d  daddu       $v0, $s2, $zero
    ctx->pc = 0x13cc9cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_13cca0:
    // 0x13cca0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x13cca0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13cca4: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x13cca4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13cca8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x13cca8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13ccac: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x13ccacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13ccb0: 0x3e00008  jr          $ra
    ctx->pc = 0x13CCB0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13CCB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13CCB0u;
            // 0x13ccb4: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13CBD8u: goto label_13cbd8;
            case 0x13CBE0u: goto label_13cbe0;
            case 0x13CBE8u: goto label_13cbe8;
            case 0x13CBF0u: goto label_13cbf0;
            case 0x13CC08u: goto label_13cc08;
            case 0x13CC10u: goto label_13cc10;
            case 0x13CC28u: goto label_13cc28;
            case 0x13CC40u: goto label_13cc40;
            case 0x13CC60u: goto label_13cc60;
            case 0x13CC70u: goto label_13cc70;
            case 0x13CC94u: goto label_13cc94;
            case 0x13CC9Cu: goto label_13cc9c;
            case 0x13CCA0u: goto label_13cca0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13CCB8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
