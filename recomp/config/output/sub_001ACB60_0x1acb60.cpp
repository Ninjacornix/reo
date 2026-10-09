#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001ACB60
// Address: 0x1acb60 - 0x1acea0
void sub_001ACB60_0x1acb60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001ACB60_0x1acb60");
#endif

    switch (ctx->pc) {
        case 0x1acbf4u: goto label_1acbf4;
        case 0x1acc3cu: goto label_1acc3c;
        case 0x1acc58u: goto label_1acc58;
        case 0x1acc9cu: goto label_1acc9c;
        case 0x1accc4u: goto label_1accc4;
        case 0x1acdd8u: goto label_1acdd8;
        case 0x1ace1cu: goto label_1ace1c;
        default: break;
    }

    ctx->pc = 0x1acb60u;

    // 0x1acb60: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x1acb60u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x1acb64: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x1acb64u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1acb68: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x1acb68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x1acb6c: 0x443021  addu        $a2, $v0, $a0
    ctx->pc = 0x1acb6cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1acb70: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x1acb70u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x1acb74: 0x51040  sll         $v0, $a1, 1
    ctx->pc = 0x1acb74u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1acb78: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1acb78u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1acb7c: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1acb7cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1acb80: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1acb80u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1acb84: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1acb84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1acb88: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1acb88u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1acb8c: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x1acb8cu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1acb90: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1acb90u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1acb94: 0x24633950  addiu       $v1, $v1, 0x3950
    ctx->pc = 0x1acb94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 14672));
    // 0x1acb98: 0x62a40  sll         $a1, $a2, 9
    ctx->pc = 0x1acb98u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 6), 9));
    // 0x1acb9c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1acb9cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1acba0: 0x65b821  addu        $s7, $v1, $a1
    ctx->pc = 0x1acba0u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1acba4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1acba4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1acba8: 0x2e29021  addu        $s2, $s7, $v0
    ctx->pc = 0x1acba8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 2)));
    // 0x1acbac: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1acbacu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1acbb0: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1acbb0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1acbb4: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1acbb4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1acbb8: 0x24423934  addiu       $v0, $v0, 0x3934
    ctx->pc = 0x1acbb8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 14644));
    // 0x1acbbc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1acbbcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1acbc0: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1acbc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1acbc4: 0xe0a82d  daddu       $s5, $a3, $zero
    ctx->pc = 0x1acbc4u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1acbc8: 0x90420000  lbu         $v0, 0x0($v0)
    ctx->pc = 0x1acbc8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1acbcc: 0x100a02d  daddu       $s4, $t0, $zero
    ctx->pc = 0x1acbccu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1acbd0: 0x104000a3  beqz        $v0, . + 4 + (0xA3 << 2)
    ctx->pc = 0x1ACBD0u;
    {
        const bool branch_taken_0x1acbd0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ACBD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACBD0u;
            // 0x1acbd4: 0x24633840  addiu       $v1, $v1, 0x3840 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 14400));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1acbd0) {
            ctx->pc = 0x1ACE60u;
            goto label_1ace60;
        }
    }
    ctx->pc = 0x1ACBD8u;
    // 0x1acbd8: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1acbd8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1acbdc: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1acbdcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1acbe0: 0x906300e4  lbu         $v1, 0xE4($v1)
    ctx->pc = 0x1acbe0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 228)));
    // 0x1acbe4: 0x1062009f  beq         $v1, $v0, . + 4 + (0x9F << 2)
    ctx->pc = 0x1ACBE4u;
    {
        const bool branch_taken_0x1acbe4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1ACBE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACBE4u;
            // 0x1acbe8: 0x3082007f  andi        $v0, $a0, 0x7F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)127);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1acbe4) {
            ctx->pc = 0x1ACE64u;
            goto label_1ace64;
        }
    }
    ctx->pc = 0x1ACBECu;
    // 0x1acbec: 0x1000009f  b           . + 4 + (0x9F << 2)
    ctx->pc = 0x1ACBECu;
    {
        const bool branch_taken_0x1acbec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ACBF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACBECu;
            // 0x1acbf0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1acbec) {
            ctx->pc = 0x1ACE6Cu;
            goto label_1ace6c;
        }
    }
    ctx->pc = 0x1ACBF4u;
label_1acbf4:
    // 0x1acbf4: 0x2ec10080  sltiu       $at, $s6, 0x80
    ctx->pc = 0x1acbf4u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 22) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x1acbf8: 0x10200097  beqz        $at, . + 4 + (0x97 << 2)
    ctx->pc = 0x1ACBF8u;
    {
        const bool branch_taken_0x1acbf8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ACBFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACBF8u;
            // 0x1acbfc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1acbf8) {
            ctx->pc = 0x1ACE58u;
            goto label_1ace58;
        }
    }
    ctx->pc = 0x1ACC00u;
    // 0x1acc00: 0x92430000  lbu         $v1, 0x0($s2)
    ctx->pc = 0x1acc00u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1acc04: 0x14600078  bnez        $v1, . + 4 + (0x78 << 2)
    ctx->pc = 0x1ACC04u;
    {
        const bool branch_taken_0x1acc04 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1ACC08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACC04u;
            // 0x1acc08: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1acc04) {
            ctx->pc = 0x1ACDE8u;
            goto label_1acde8;
        }
    }
    ctx->pc = 0x1ACC0Cu;
    // 0x1acc0c: 0x92430005  lbu         $v1, 0x5($s2)
    ctx->pc = 0x1acc0cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 5)));
    // 0x1acc10: 0x240200ff  addiu       $v0, $zero, 0xFF
    ctx->pc = 0x1acc10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1acc14: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1ACC14u;
    {
        const bool branch_taken_0x1acc14 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1ACC18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACC14u;
            // 0x1acc18: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1acc14) {
            ctx->pc = 0x1ACC24u;
            goto label_1acc24;
        }
    }
    ctx->pc = 0x1ACC1Cu;
    // 0x1acc1c: 0x16820002  bne         $s4, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1ACC1Cu;
    {
        const bool branch_taken_0x1acc1c = (GPR_U64(ctx, 20) != GPR_U64(ctx, 2));
        if (branch_taken_0x1acc1c) {
            ctx->pc = 0x1ACC28u;
            goto label_1acc28;
        }
    }
    ctx->pc = 0x1ACC24u;
label_1acc24:
    // 0x1acc24: 0x307400ff  andi        $s4, $v1, 0xFF
    ctx->pc = 0x1acc24u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
label_1acc28:
    // 0x1acc28: 0x92420007  lbu         $v0, 0x7($s2)
    ctx->pc = 0x1acc28u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 7)));
    // 0x1acc2c: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1ACC2Cu;
    {
        const bool branch_taken_0x1acc2c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ACC30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACC2Cu;
            // 0x1acc30: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1acc2c) {
            ctx->pc = 0x1ACC88u;
            goto label_1acc88;
        }
    }
    ctx->pc = 0x1ACC34u;
    // 0x1acc34: 0xc06bb20  jal         func_1AEC80
    ctx->pc = 0x1ACC34u;
    SET_GPR_U32(ctx, 31, 0x1ACC3Cu);
    ctx->pc = 0x1AEC80u;
    if (runtime->hasFunction(0x1AEC80u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ACC3Cu; }
        if (ctx->pc != 0x1ACC3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC80_0x1aec80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ACC3Cu; }
        if (ctx->pc != 0x1ACC3Cu) { return; }
    }
    ctx->pc = 0x1ACC3Cu;
label_1acc3c:
    // 0x1acc3c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1acc3cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1acc40: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x1acc40u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1acc44: 0x30430001  andi        $v1, $v0, 0x1
    ctx->pc = 0x1acc44u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x1acc48: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1acc48u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1acc4c: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1acc4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1acc50: 0xc06bb20  jal         func_1AEC80
    ctx->pc = 0x1ACC50u;
    SET_GPR_U32(ctx, 31, 0x1ACC58u);
    ctx->pc = 0x1ACC54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACC50u;
            // 0x1acc54: 0x43880a  movz        $s1, $v0, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 17, GPR_VEC(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AEC80u;
    if (runtime->hasFunction(0x1AEC80u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ACC58u; }
        if (ctx->pc != 0x1ACC58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC80_0x1aec80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ACC58u; }
        if (ctx->pc != 0x1ACC58u) { return; }
    }
    ctx->pc = 0x1ACC58u;
label_1acc58:
    // 0x1acc58: 0x92430007  lbu         $v1, 0x7($s2)
    ctx->pc = 0x1acc58u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 7)));
    // 0x1acc5c: 0x3044ffff  andi        $a0, $v0, 0xFFFF
    ctx->pc = 0x1acc5cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1acc60: 0x96420002  lhu         $v0, 0x2($s2)
    ctx->pc = 0x1acc60u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2)));
    // 0x1acc64: 0x83001a  div         $zero, $a0, $v1
    ctx->pc = 0x1acc64u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1acc68: 0x24422000  addiu       $v0, $v0, 0x2000
    ctx->pc = 0x1acc68u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8192));
    // 0x1acc6c: 0x0  nop
    ctx->pc = 0x1acc6cu;
    // NOP
    // 0x1acc70: 0x1810  mfhi        $v1
    ctx->pc = 0x1acc70u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x1acc74: 0x2231818  mult        $v1, $s1, $v1
    ctx->pc = 0x1acc74u;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1acc78: 0x31940  sll         $v1, $v1, 5
    ctx->pc = 0x1acc78u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x1acc7c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1acc7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1acc80: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1ACC80u;
    {
        const bool branch_taken_0x1acc80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ACC84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACC80u;
            // 0x1acc84: 0x30533fff  andi        $s3, $v0, 0x3FFF (Delay Slot)
        SET_GPR_U64(ctx, 19, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)16383);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1acc80) {
            ctx->pc = 0x1ACC94u;
            goto label_1acc94;
        }
    }
    ctx->pc = 0x1ACC88u;
label_1acc88:
    // 0x1acc88: 0x96420002  lhu         $v0, 0x2($s2)
    ctx->pc = 0x1acc88u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2)));
    // 0x1acc8c: 0x24422000  addiu       $v0, $v0, 0x2000
    ctx->pc = 0x1acc8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8192));
    // 0x1acc90: 0x30533fff  andi        $s3, $v0, 0x3FFF
    ctx->pc = 0x1acc90u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)16383);
label_1acc94:
    // 0x1acc94: 0xc06bb20  jal         func_1AEC80
    ctx->pc = 0x1ACC94u;
    SET_GPR_U32(ctx, 31, 0x1ACC9Cu);
    ctx->pc = 0x1ACC98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACC94u;
            // 0x1acc98: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AEC80u;
    if (runtime->hasFunction(0x1AEC80u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ACC9Cu; }
        if (ctx->pc != 0x1ACC9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC80_0x1aec80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ACC9Cu; }
        if (ctx->pc != 0x1ACC9Cu) { return; }
    }
    ctx->pc = 0x1ACC9Cu;
label_1acc9c:
    // 0x1acc9c: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1acc9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1acca0: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x1acca0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1acca4: 0x30430001  andi        $v1, $v0, 0x1
    ctx->pc = 0x1acca4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x1acca8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1acca8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1accac: 0x43880a  movz        $s1, $v0, $v1
    ctx->pc = 0x1accacu;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 17, GPR_VEC(ctx, 2));
    // 0x1accb0: 0x92420006  lbu         $v0, 0x6($s2)
    ctx->pc = 0x1accb0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 6)));
    // 0x1accb4: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1ACCB4u;
    {
        const bool branch_taken_0x1accb4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ACCB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACCB4u;
            // 0x1accb8: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1accb4) {
            ctx->pc = 0x1ACCECu;
            goto label_1accec;
        }
    }
    ctx->pc = 0x1ACCBCu;
    // 0x1accbc: 0xc06bb20  jal         func_1AEC80
    ctx->pc = 0x1ACCBCu;
    SET_GPR_U32(ctx, 31, 0x1ACCC4u);
    ctx->pc = 0x1AEC80u;
    if (runtime->hasFunction(0x1AEC80u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ACCC4u; }
        if (ctx->pc != 0x1ACCC4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC80_0x1aec80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ACCC4u; }
        if (ctx->pc != 0x1ACCC4u) { return; }
    }
    ctx->pc = 0x1ACCC4u;
label_1accc4:
    // 0x1accc4: 0x92430006  lbu         $v1, 0x6($s2)
    ctx->pc = 0x1accc4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 6)));
    // 0x1accc8: 0x3044ffff  andi        $a0, $v0, 0xFFFF
    ctx->pc = 0x1accc8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1acccc: 0x92420004  lbu         $v0, 0x4($s2)
    ctx->pc = 0x1accccu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x1accd0: 0x83001a  div         $zero, $a0, $v1
    ctx->pc = 0x1accd0u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1accd4: 0x0  nop
    ctx->pc = 0x1accd4u;
    // NOP
    // 0x1accd8: 0x0  nop
    ctx->pc = 0x1accd8u;
    // NOP
    // 0x1accdc: 0x1810  mfhi        $v1
    ctx->pc = 0x1accdcu;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x1acce0: 0x2231818  mult        $v1, $s1, $v1
    ctx->pc = 0x1acce0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1acce4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1ACCE4u;
    {
        const bool branch_taken_0x1acce4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ACCE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACCE4u;
            // 0x1acce8: 0x431021  addu        $v0, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1acce4) {
            ctx->pc = 0x1ACCF0u;
            goto label_1accf0;
        }
    }
    ctx->pc = 0x1ACCECu;
label_1accec:
    // 0x1accec: 0x92420004  lbu         $v0, 0x4($s2)
    ctx->pc = 0x1accecu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 4)));
label_1accf0:
    // 0x1accf0: 0x4410003  bgez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1ACCF0u;
    {
        const bool branch_taken_0x1accf0 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1ACCF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACCF0u;
            // 0x1accf4: 0x28410080  slti        $at, $v0, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)128) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1accf0) {
            ctx->pc = 0x1ACD00u;
            goto label_1acd00;
        }
    }
    ctx->pc = 0x1ACCF8u;
    // 0x1accf8: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1ACCF8u;
    {
        const bool branch_taken_0x1accf8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ACCFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACCF8u;
            // 0x1accfc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1accf8) {
            ctx->pc = 0x1ACD0Cu;
            goto label_1acd0c;
        }
    }
    ctx->pc = 0x1ACD00u;
label_1acd00:
    // 0x1acd00: 0x14200002  bnez        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1ACD00u;
    {
        const bool branch_taken_0x1acd00 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1acd00) {
            ctx->pc = 0x1ACD0Cu;
            goto label_1acd0c;
        }
    }
    ctx->pc = 0x1ACD08u;
    // 0x1acd08: 0x2402007f  addiu       $v0, $zero, 0x7F
    ctx->pc = 0x1acd08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
label_1acd0c:
    // 0x1acd0c: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1acd0cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1acd10: 0x6a00004  bltz        $s5, . + 4 + (0x4 << 2)
    ctx->pc = 0x1ACD10u;
    {
        const bool branch_taken_0x1acd10 = (GPR_S64(ctx, 21) < 0);
        ctx->pc = 0x1ACD14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACD10u;
            // 0x1acd14: 0x468000e0  cvt.s.w     $f3, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[3] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1acd10) {
            ctx->pc = 0x1ACD24u;
            goto label_1acd24;
        }
    }
    ctx->pc = 0x1ACD18u;
    // 0x1acd18: 0x44950000  mtc1        $s5, $f0
    ctx->pc = 0x1acd18u;
    { uint32_t bits = GPR_U32(ctx, 21); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1acd1c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1ACD1Cu;
    {
        const bool branch_taken_0x1acd1c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ACD20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACD1Cu;
            // 0x1acd20: 0x468000a0  cvt.s.w     $f2, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1acd1c) {
            ctx->pc = 0x1ACD40u;
            goto label_1acd40;
        }
    }
    ctx->pc = 0x1ACD24u;
label_1acd24:
    // 0x1acd24: 0x151842  srl         $v1, $s5, 1
    ctx->pc = 0x1acd24u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 21), 1));
    // 0x1acd28: 0x32a20001  andi        $v0, $s5, 0x1
    ctx->pc = 0x1acd28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 21) & (uint64_t)(uint16_t)1);
    // 0x1acd2c: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1acd2cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1acd30: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1acd30u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1acd34: 0x0  nop
    ctx->pc = 0x1acd34u;
    // NOP
    // 0x1acd38: 0x468000a0  cvt.s.w     $f2, $f0
    ctx->pc = 0x1acd38u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x1acd3c: 0x46021080  add.s       $f2, $f2, $f2
    ctx->pc = 0x1acd3cu;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[2]);
label_1acd40:
    // 0x1acd40: 0x3c034300  lui         $v1, 0x4300
    ctx->pc = 0x1acd40u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17152 << 16));
    // 0x1acd44: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1acd44u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1acd48: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x1acd48u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1acd4c: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1acd4cu;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1acd50: 0x0  nop
    ctx->pc = 0x1acd50u;
    // NOP
    // 0x1acd54: 0x46011043  div.s       $f1, $f2, $f1
    ctx->pc = 0x1acd54u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[1] = std::bit_cast<float>(__maxf); } else ctx->f[1] = ctx->f[2] / ctx->f[1];
    // 0x1acd58: 0x0  nop
    ctx->pc = 0x1acd58u;
    // NOP
    // 0x1acd5c: 0x46011842  mul.s       $f1, $f3, $f1
    ctx->pc = 0x1acd5cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[3], ctx->f[1]);
    // 0x1acd60: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1acd60u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1acd64: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1ACD64u;
    {
        const bool branch_taken_0x1acd64 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1acd64) {
            ctx->pc = 0x1ACD7Cu;
            goto label_1acd7c;
        }
    }
    ctx->pc = 0x1ACD6Cu;
    // 0x1acd6c: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1acd6cu;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1acd70: 0x44150800  mfc1        $s5, $f1
    ctx->pc = 0x1acd70u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 21, bits); }
    // 0x1acd74: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1ACD74u;
    {
        const bool branch_taken_0x1acd74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ACD78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACD74u;
            // 0x1acd78: 0x92440009  lbu         $a0, 0x9($s2) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 9)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1acd74) {
            ctx->pc = 0x1ACD98u;
            goto label_1acd98;
        }
    }
    ctx->pc = 0x1ACD7Cu;
label_1acd7c:
    // 0x1acd7c: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1acd7cu;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1acd80: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1acd80u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1acd84: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1acd84u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1acd88: 0x44150800  mfc1        $s5, $f1
    ctx->pc = 0x1acd88u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 21, bits); }
    // 0x1acd8c: 0x0  nop
    ctx->pc = 0x1acd8cu;
    // NOP
    // 0x1acd90: 0x2a2a825  or          $s5, $s5, $v0
    ctx->pc = 0x1acd90u;
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 21) | GPR_U64(ctx, 2));
    // 0x1acd94: 0x92440009  lbu         $a0, 0x9($s2)
    ctx->pc = 0x1acd94u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 9)));
label_1acd98:
    // 0x1acd98: 0x32c2007f  andi        $v0, $s6, 0x7F
    ctx->pc = 0x1acd98u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 22) & (uint64_t)(uint16_t)127);
    // 0x1acd9c: 0x92430008  lbu         $v1, 0x8($s2)
    ctx->pc = 0x1acd9cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x1acda0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1acda0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1acda4: 0x133c3c  dsll32      $a3, $s3, 16
    ctx->pc = 0x1acda4u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 19) << (32 + 16));
    // 0x1acda8: 0x152e3c  dsll32      $a1, $s5, 24
    ctx->pc = 0x1acda8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 21) << (32 + 24));
    // 0x1acdac: 0x14363c  dsll32      $a2, $s4, 24
    ctx->pc = 0x1acdacu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 20) << (32 + 24));
    // 0x1acdb0: 0x2021025  or          $v0, $s0, $v0
    ctx->pc = 0x1acdb0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1acdb4: 0x73c3f  dsra32      $a3, $a3, 16
    ctx->pc = 0x1acdb4u;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 16));
    // 0x1acdb8: 0x52e3f  dsra32      $a1, $a1, 24
    ctx->pc = 0x1acdb8u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 24));
    // 0x1acdbc: 0x6363f  dsra32      $a2, $a2, 24
    ctx->pc = 0x1acdbcu;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 24));
    // 0x1acdc0: 0x30840001  andi        $a0, $a0, 0x1
    ctx->pc = 0x1acdc0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x1acdc4: 0x421c0  sll         $a0, $a0, 7
    ctx->pc = 0x1acdc4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 7));
    // 0x1acdc8: 0x3063007f  andi        $v1, $v1, 0x7F
    ctx->pc = 0x1acdc8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)127);
    // 0x1acdcc: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1acdccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1acdd0: 0xc069d54  jal         func_1A7550
    ctx->pc = 0x1ACDD0u;
    SET_GPR_U32(ctx, 31, 0x1ACDD8u);
    ctx->pc = 0x1ACDD4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACDD0u;
            // 0x1acdd4: 0x432025  or          $a0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A7550u;
    if (runtime->hasFunction(0x1A7550u)) {
        auto targetFn = runtime->lookupFunction(0x1A7550u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ACDD8u; }
        if (ctx->pc != 0x1ACDD8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A7550_0x1a7550(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ACDD8u; }
        if (ctx->pc != 0x1ACDD8u) { return; }
    }
    ctx->pc = 0x1ACDD8u;
label_1acdd8:
    // 0x1acdd8: 0x4410016  bgez        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1ACDD8u;
    {
        const bool branch_taken_0x1acdd8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1acdd8) {
            ctx->pc = 0x1ACE34u;
            goto label_1ace34;
        }
    }
    ctx->pc = 0x1ACDE0u;
    // 0x1acde0: 0x1000001c  b           . + 4 + (0x1C << 2)
    ctx->pc = 0x1ACDE0u;
    {
        const bool branch_taken_0x1acde0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1acde0) {
            ctx->pc = 0x1ACE54u;
            goto label_1ace54;
        }
    }
    ctx->pc = 0x1ACDE8u;
label_1acde8:
    // 0x1acde8: 0x14620010  bne         $v1, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x1ACDE8u;
    {
        const bool branch_taken_0x1acde8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1acde8) {
            ctx->pc = 0x1ACE2Cu;
            goto label_1ace2c;
        }
    }
    ctx->pc = 0x1ACDF0u;
    // 0x1acdf0: 0x92440009  lbu         $a0, 0x9($s2)
    ctx->pc = 0x1acdf0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 9)));
    // 0x1acdf4: 0x32c2007f  andi        $v0, $s6, 0x7F
    ctx->pc = 0x1acdf4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 22) & (uint64_t)(uint16_t)127);
    // 0x1acdf8: 0x92430008  lbu         $v1, 0x8($s2)
    ctx->pc = 0x1acdf8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x1acdfc: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1acdfcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1ace00: 0x2021025  or          $v0, $s0, $v0
    ctx->pc = 0x1ace00u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1ace04: 0x30840001  andi        $a0, $a0, 0x1
    ctx->pc = 0x1ace04u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x1ace08: 0x421c0  sll         $a0, $a0, 7
    ctx->pc = 0x1ace08u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 7));
    // 0x1ace0c: 0x3063007f  andi        $v1, $v1, 0x7F
    ctx->pc = 0x1ace0cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)127);
    // 0x1ace10: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1ace10u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1ace14: 0xc069d0c  jal         func_1A7430
    ctx->pc = 0x1ACE14u;
    SET_GPR_U32(ctx, 31, 0x1ACE1Cu);
    ctx->pc = 0x1ACE18u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACE14u;
            // 0x1ace18: 0x432025  or          $a0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A7430u;
    if (runtime->hasFunction(0x1A7430u)) {
        auto targetFn = runtime->lookupFunction(0x1A7430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ACE1Cu; }
        if (ctx->pc != 0x1ACE1Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A7430_0x1a7430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ACE1Cu; }
        if (ctx->pc != 0x1ACE1Cu) { return; }
    }
    ctx->pc = 0x1ACE1Cu;
label_1ace1c:
    // 0x1ace1c: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1ACE1Cu;
    {
        const bool branch_taken_0x1ace1c = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1ace1c) {
            ctx->pc = 0x1ACE34u;
            goto label_1ace34;
        }
    }
    ctx->pc = 0x1ACE24u;
    // 0x1ace24: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x1ACE24u;
    {
        const bool branch_taken_0x1ace24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ace24) {
            ctx->pc = 0x1ACE54u;
            goto label_1ace54;
        }
    }
    ctx->pc = 0x1ACE2Cu;
label_1ace2c:
    // 0x1ace2c: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1ACE2Cu;
    {
        const bool branch_taken_0x1ace2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ACE30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACE2Cu;
            // 0x1ace30: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ace2c) {
            ctx->pc = 0x1ACE6Cu;
            goto label_1ace6c;
        }
    }
    ctx->pc = 0x1ACE34u;
label_1ace34:
    // 0x1ace34: 0x9256000b  lbu         $s6, 0xB($s2)
    ctx->pc = 0x1ace34u;
    SET_GPR_U32(ctx, 22, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 11)));
    // 0x1ace38: 0x240200ff  addiu       $v0, $zero, 0xFF
    ctx->pc = 0x1ace38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1ace3c: 0x12c20005  beq         $s6, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1ACE3Cu;
    {
        const bool branch_taken_0x1ace3c = (GPR_U64(ctx, 22) == GPR_U64(ctx, 2));
        ctx->pc = 0x1ACE40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACE3Cu;
            // 0x1ace40: 0x161040  sll         $v0, $s6, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 22), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ace3c) {
            ctx->pc = 0x1ACE54u;
            goto label_1ace54;
        }
    }
    ctx->pc = 0x1ACE44u;
    // 0x1ace44: 0x561021  addu        $v0, $v0, $s6
    ctx->pc = 0x1ace44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 22)));
    // 0x1ace48: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1ace48u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1ace4c: 0x1000ff69  b           . + 4 + (-0x97 << 2)
    ctx->pc = 0x1ACE4Cu;
    {
        const bool branch_taken_0x1ace4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ACE50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACE4Cu;
            // 0x1ace50: 0x2e29021  addu        $s2, $s7, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ace4c) {
            ctx->pc = 0x1ACBF4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1acbf4;
        }
    }
    ctx->pc = 0x1ACE54u;
label_1ace54:
    // 0x1ace54: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ace54u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ace58:
    // 0x1ace58: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1ACE58u;
    {
        const bool branch_taken_0x1ace58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ACE5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACE58u;
            // 0x1ace5c: 0xdfbf0080  ld          $ra, 0x80($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ace58) {
            ctx->pc = 0x1ACE70u;
            goto label_1ace70;
        }
    }
    ctx->pc = 0x1ACE60u;
label_1ace60:
    // 0x1ace60: 0x3082007f  andi        $v0, $a0, 0x7F
    ctx->pc = 0x1ace60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)127);
label_1ace64:
    // 0x1ace64: 0x1000ff63  b           . + 4 + (-0x9D << 2)
    ctx->pc = 0x1ACE64u;
    {
        const bool branch_taken_0x1ace64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ACE68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACE64u;
            // 0x1ace68: 0x28400  sll         $s0, $v0, 16 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ace64) {
            ctx->pc = 0x1ACBF4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1acbf4;
        }
    }
    ctx->pc = 0x1ACE6Cu;
label_1ace6c:
    // 0x1ace6c: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x1ace6cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
label_1ace70:
    // 0x1ace70: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x1ace70u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1ace74: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1ace74u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1ace78: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1ace78u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1ace7c: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1ace7cu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1ace80: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1ace80u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1ace84: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1ace84u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ace88: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ace88u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ace8c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ace8cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ace90: 0x3e00008  jr          $ra
    ctx->pc = 0x1ACE90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1ACE94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACE90u;
            // 0x1ace94: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1ACBF4u: goto label_1acbf4;
            case 0x1ACC24u: goto label_1acc24;
            case 0x1ACC28u: goto label_1acc28;
            case 0x1ACC3Cu: goto label_1acc3c;
            case 0x1ACC58u: goto label_1acc58;
            case 0x1ACC88u: goto label_1acc88;
            case 0x1ACC94u: goto label_1acc94;
            case 0x1ACC9Cu: goto label_1acc9c;
            case 0x1ACCC4u: goto label_1accc4;
            case 0x1ACCECu: goto label_1accec;
            case 0x1ACCF0u: goto label_1accf0;
            case 0x1ACD00u: goto label_1acd00;
            case 0x1ACD0Cu: goto label_1acd0c;
            case 0x1ACD24u: goto label_1acd24;
            case 0x1ACD40u: goto label_1acd40;
            case 0x1ACD7Cu: goto label_1acd7c;
            case 0x1ACD98u: goto label_1acd98;
            case 0x1ACDD8u: goto label_1acdd8;
            case 0x1ACDE8u: goto label_1acde8;
            case 0x1ACE1Cu: goto label_1ace1c;
            case 0x1ACE2Cu: goto label_1ace2c;
            case 0x1ACE34u: goto label_1ace34;
            case 0x1ACE54u: goto label_1ace54;
            case 0x1ACE58u: goto label_1ace58;
            case 0x1ACE60u: goto label_1ace60;
            case 0x1ACE64u: goto label_1ace64;
            case 0x1ACE6Cu: goto label_1ace6c;
            case 0x1ACE70u: goto label_1ace70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1ACE98u;
    // 0x1ace98: 0x0  nop
    ctx->pc = 0x1ace98u;
    // NOP
    // 0x1ace9c: 0x0  nop
    ctx->pc = 0x1ace9cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
