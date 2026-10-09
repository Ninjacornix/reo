#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AC7F0
// Address: 0x1ac7f0 - 0x1acb60
void sub_001AC7F0_0x1ac7f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AC7F0_0x1ac7f0");
#endif

    switch (ctx->pc) {
        case 0x1ac88cu: goto label_1ac88c;
        case 0x1ac8d4u: goto label_1ac8d4;
        case 0x1ac8f0u: goto label_1ac8f0;
        case 0x1ac934u: goto label_1ac934;
        case 0x1ac95cu: goto label_1ac95c;
        case 0x1aca8cu: goto label_1aca8c;
        case 0x1acad0u: goto label_1acad0;
        default: break;
    }

    ctx->pc = 0x1ac7f0u;

    // 0x1ac7f0: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1ac7f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1ac7f4: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x1ac7f4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1ac7f8: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x1ac7f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x1ac7fc: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1ac7fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1ac800: 0x7fbe0080  sq          $fp, 0x80($sp)
    ctx->pc = 0x1ac800u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 30));
    // 0x1ac804: 0x23240  sll         $a2, $v0, 9
    ctx->pc = 0x1ac804u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 2), 9));
    // 0x1ac808: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x1ac808u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x1ac80c: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1ac80cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1ac810: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1ac810u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1ac814: 0x51040  sll         $v0, $a1, 1
    ctx->pc = 0x1ac814u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1ac818: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1ac818u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1ac81c: 0x24633950  addiu       $v1, $v1, 0x3950
    ctx->pc = 0x1ac81cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 14672));
    // 0x1ac820: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1ac820u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1ac824: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1ac824u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1ac828: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1ac828u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1ac82c: 0x66b821  addu        $s7, $v1, $a2
    ctx->pc = 0x1ac82cu;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1ac830: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1ac830u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1ac834: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1ac834u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1ac838: 0x2e29021  addu        $s2, $s7, $v0
    ctx->pc = 0x1ac838u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 2)));
    // 0x1ac83c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ac83cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ac840: 0x3c02002b  lui         $v0, 0x2B
    ctx->pc = 0x1ac840u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)43 << 16));
    // 0x1ac844: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1ac844u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1ac848: 0x24423934  addiu       $v0, $v0, 0x3934
    ctx->pc = 0x1ac848u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 14644));
    // 0x1ac84c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ac84cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ac850: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1ac850u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1ac854: 0xe0a82d  daddu       $s5, $a3, $zero
    ctx->pc = 0x1ac854u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ac858: 0x90420000  lbu         $v0, 0x0($v0)
    ctx->pc = 0x1ac858u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ac85c: 0x100a02d  daddu       $s4, $t0, $zero
    ctx->pc = 0x1ac85cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ac860: 0x140f02d  daddu       $fp, $t2, $zero
    ctx->pc = 0x1ac860u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ac864: 0xa0b02d  daddu       $s6, $a1, $zero
    ctx->pc = 0x1ac864u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ac868: 0x104000ad  beqz        $v0, . + 4 + (0xAD << 2)
    ctx->pc = 0x1AC868u;
    {
        const bool branch_taken_0x1ac868 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC86Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC868u;
            // 0x1ac86c: 0x24633840  addiu       $v1, $v1, 0x3840 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 14400));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac868) {
            ctx->pc = 0x1ACB20u;
            goto label_1acb20;
        }
    }
    ctx->pc = 0x1AC870u;
    // 0x1ac870: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x1ac870u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1ac874: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1ac874u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ac878: 0x906300e4  lbu         $v1, 0xE4($v1)
    ctx->pc = 0x1ac878u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 228)));
    // 0x1ac87c: 0x106200a9  beq         $v1, $v0, . + 4 + (0xA9 << 2)
    ctx->pc = 0x1AC87Cu;
    {
        const bool branch_taken_0x1ac87c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1AC880u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC87Cu;
            // 0x1ac880: 0x3082007f  andi        $v0, $a0, 0x7F (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)127);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac87c) {
            ctx->pc = 0x1ACB24u;
            goto label_1acb24;
        }
    }
    ctx->pc = 0x1AC884u;
    // 0x1ac884: 0x100000a9  b           . + 4 + (0xA9 << 2)
    ctx->pc = 0x1AC884u;
    {
        const bool branch_taken_0x1ac884 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC884u;
            // 0x1ac888: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac884) {
            ctx->pc = 0x1ACB2Cu;
            goto label_1acb2c;
        }
    }
    ctx->pc = 0x1AC88Cu;
label_1ac88c:
    // 0x1ac88c: 0x2ec10080  sltiu       $at, $s6, 0x80
    ctx->pc = 0x1ac88cu;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 22) < (uint64_t)(int64_t)(int32_t)128) ? 1 : 0);
    // 0x1ac890: 0x102000a1  beqz        $at, . + 4 + (0xA1 << 2)
    ctx->pc = 0x1AC890u;
    {
        const bool branch_taken_0x1ac890 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC894u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC890u;
            // 0x1ac894: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac890) {
            ctx->pc = 0x1ACB18u;
            goto label_1acb18;
        }
    }
    ctx->pc = 0x1AC898u;
    // 0x1ac898: 0x92430000  lbu         $v1, 0x0($s2)
    ctx->pc = 0x1ac898u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1ac89c: 0x1460007f  bnez        $v1, . + 4 + (0x7F << 2)
    ctx->pc = 0x1AC89Cu;
    {
        const bool branch_taken_0x1ac89c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AC8A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC89Cu;
            // 0x1ac8a0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac89c) {
            ctx->pc = 0x1ACA9Cu;
            goto label_1aca9c;
        }
    }
    ctx->pc = 0x1AC8A4u;
    // 0x1ac8a4: 0x92430005  lbu         $v1, 0x5($s2)
    ctx->pc = 0x1ac8a4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 5)));
    // 0x1ac8a8: 0x240200ff  addiu       $v0, $zero, 0xFF
    ctx->pc = 0x1ac8a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1ac8ac: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AC8ACu;
    {
        const bool branch_taken_0x1ac8ac = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1AC8B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC8ACu;
            // 0x1ac8b0: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac8ac) {
            ctx->pc = 0x1AC8BCu;
            goto label_1ac8bc;
        }
    }
    ctx->pc = 0x1AC8B4u;
    // 0x1ac8b4: 0x16820002  bne         $s4, $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1AC8B4u;
    {
        const bool branch_taken_0x1ac8b4 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 2));
        if (branch_taken_0x1ac8b4) {
            ctx->pc = 0x1AC8C0u;
            goto label_1ac8c0;
        }
    }
    ctx->pc = 0x1AC8BCu;
label_1ac8bc:
    // 0x1ac8bc: 0x307400ff  andi        $s4, $v1, 0xFF
    ctx->pc = 0x1ac8bcu;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
label_1ac8c0:
    // 0x1ac8c0: 0x92420007  lbu         $v0, 0x7($s2)
    ctx->pc = 0x1ac8c0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 7)));
    // 0x1ac8c4: 0x10400016  beqz        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1AC8C4u;
    {
        const bool branch_taken_0x1ac8c4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC8C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC8C4u;
            // 0x1ac8c8: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac8c4) {
            ctx->pc = 0x1AC920u;
            goto label_1ac920;
        }
    }
    ctx->pc = 0x1AC8CCu;
    // 0x1ac8cc: 0xc06bb20  jal         func_1AEC80
    ctx->pc = 0x1AC8CCu;
    SET_GPR_U32(ctx, 31, 0x1AC8D4u);
    ctx->pc = 0x1AEC80u;
    if (runtime->hasFunction(0x1AEC80u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC8D4u; }
        if (ctx->pc != 0x1AC8D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC80_0x1aec80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC8D4u; }
        if (ctx->pc != 0x1AC8D4u) { return; }
    }
    ctx->pc = 0x1AC8D4u;
label_1ac8d4:
    // 0x1ac8d4: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1ac8d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1ac8d8: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x1ac8d8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ac8dc: 0x30430001  andi        $v1, $v0, 0x1
    ctx->pc = 0x1ac8dcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x1ac8e0: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1ac8e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ac8e4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1ac8e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1ac8e8: 0xc06bb20  jal         func_1AEC80
    ctx->pc = 0x1AC8E8u;
    SET_GPR_U32(ctx, 31, 0x1AC8F0u);
    ctx->pc = 0x1AC8ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC8E8u;
            // 0x1ac8ec: 0x43880a  movz        $s1, $v0, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 17, GPR_VEC(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AEC80u;
    if (runtime->hasFunction(0x1AEC80u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC8F0u; }
        if (ctx->pc != 0x1AC8F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC80_0x1aec80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC8F0u; }
        if (ctx->pc != 0x1AC8F0u) { return; }
    }
    ctx->pc = 0x1AC8F0u;
label_1ac8f0:
    // 0x1ac8f0: 0x92430007  lbu         $v1, 0x7($s2)
    ctx->pc = 0x1ac8f0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 7)));
    // 0x1ac8f4: 0x3044ffff  andi        $a0, $v0, 0xFFFF
    ctx->pc = 0x1ac8f4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1ac8f8: 0x96420002  lhu         $v0, 0x2($s2)
    ctx->pc = 0x1ac8f8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2)));
    // 0x1ac8fc: 0x83001a  div         $zero, $a0, $v1
    ctx->pc = 0x1ac8fcu;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1ac900: 0x24422000  addiu       $v0, $v0, 0x2000
    ctx->pc = 0x1ac900u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8192));
    // 0x1ac904: 0x0  nop
    ctx->pc = 0x1ac904u;
    // NOP
    // 0x1ac908: 0x1810  mfhi        $v1
    ctx->pc = 0x1ac908u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x1ac90c: 0x2231818  mult        $v1, $s1, $v1
    ctx->pc = 0x1ac90cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1ac910: 0x31940  sll         $v1, $v1, 5
    ctx->pc = 0x1ac910u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 5));
    // 0x1ac914: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ac914u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ac918: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1AC918u;
    {
        const bool branch_taken_0x1ac918 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC91Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC918u;
            // 0x1ac91c: 0x30533fff  andi        $s3, $v0, 0x3FFF (Delay Slot)
        SET_GPR_U64(ctx, 19, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)16383);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac918) {
            ctx->pc = 0x1AC92Cu;
            goto label_1ac92c;
        }
    }
    ctx->pc = 0x1AC920u;
label_1ac920:
    // 0x1ac920: 0x96420002  lhu         $v0, 0x2($s2)
    ctx->pc = 0x1ac920u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 2)));
    // 0x1ac924: 0x24422000  addiu       $v0, $v0, 0x2000
    ctx->pc = 0x1ac924u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 8192));
    // 0x1ac928: 0x30533fff  andi        $s3, $v0, 0x3FFF
    ctx->pc = 0x1ac928u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)16383);
label_1ac92c:
    // 0x1ac92c: 0xc06bb20  jal         func_1AEC80
    ctx->pc = 0x1AC92Cu;
    SET_GPR_U32(ctx, 31, 0x1AC934u);
    ctx->pc = 0x1AC930u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC92Cu;
            // 0x1ac930: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AEC80u;
    if (runtime->hasFunction(0x1AEC80u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC934u; }
        if (ctx->pc != 0x1AC934u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC80_0x1aec80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC934u; }
        if (ctx->pc != 0x1AC934u) { return; }
    }
    ctx->pc = 0x1AC934u;
label_1ac934:
    // 0x1ac934: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x1ac934u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1ac938: 0x24110001  addiu       $s1, $zero, 0x1
    ctx->pc = 0x1ac938u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ac93c: 0x30430001  andi        $v1, $v0, 0x1
    ctx->pc = 0x1ac93cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)1);
    // 0x1ac940: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1ac940u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1ac944: 0x43880a  movz        $s1, $v0, $v1
    ctx->pc = 0x1ac944u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 17, GPR_VEC(ctx, 2));
    // 0x1ac948: 0x92420006  lbu         $v0, 0x6($s2)
    ctx->pc = 0x1ac948u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 6)));
    // 0x1ac94c: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1AC94Cu;
    {
        const bool branch_taken_0x1ac94c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC950u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC94Cu;
            // 0x1ac950: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac94c) {
            ctx->pc = 0x1AC984u;
            goto label_1ac984;
        }
    }
    ctx->pc = 0x1AC954u;
    // 0x1ac954: 0xc06bb20  jal         func_1AEC80
    ctx->pc = 0x1AC954u;
    SET_GPR_U32(ctx, 31, 0x1AC95Cu);
    ctx->pc = 0x1AEC80u;
    if (runtime->hasFunction(0x1AEC80u)) {
        auto targetFn = runtime->lookupFunction(0x1AEC80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC95Cu; }
        if (ctx->pc != 0x1AC95Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEC80_0x1aec80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AC95Cu; }
        if (ctx->pc != 0x1AC95Cu) { return; }
    }
    ctx->pc = 0x1AC95Cu;
label_1ac95c:
    // 0x1ac95c: 0x92430006  lbu         $v1, 0x6($s2)
    ctx->pc = 0x1ac95cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 6)));
    // 0x1ac960: 0x3044ffff  andi        $a0, $v0, 0xFFFF
    ctx->pc = 0x1ac960u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x1ac964: 0x92420004  lbu         $v0, 0x4($s2)
    ctx->pc = 0x1ac964u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x1ac968: 0x83001a  div         $zero, $a0, $v1
    ctx->pc = 0x1ac968u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 4);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1ac96c: 0x0  nop
    ctx->pc = 0x1ac96cu;
    // NOP
    // 0x1ac970: 0x0  nop
    ctx->pc = 0x1ac970u;
    // NOP
    // 0x1ac974: 0x1810  mfhi        $v1
    ctx->pc = 0x1ac974u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x1ac978: 0x2231818  mult        $v1, $s1, $v1
    ctx->pc = 0x1ac978u;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1ac97c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1AC97Cu;
    {
        const bool branch_taken_0x1ac97c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC97Cu;
            // 0x1ac980: 0x431821  addu        $v1, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac97c) {
            ctx->pc = 0x1AC988u;
            goto label_1ac988;
        }
    }
    ctx->pc = 0x1AC984u;
label_1ac984:
    // 0x1ac984: 0x92430004  lbu         $v1, 0x4($s2)
    ctx->pc = 0x1ac984u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 4)));
label_1ac988:
    // 0x1ac988: 0x4610003  bgez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AC988u;
    {
        const bool branch_taken_0x1ac988 = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1AC98Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC988u;
            // 0x1ac98c: 0x28610080  slti        $at, $v1, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)128) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac988) {
            ctx->pc = 0x1AC998u;
            goto label_1ac998;
        }
    }
    ctx->pc = 0x1AC990u;
    // 0x1ac990: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x1AC990u;
    {
        const bool branch_taken_0x1ac990 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC994u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC990u;
            // 0x1ac994: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac990) {
            ctx->pc = 0x1AC9A4u;
            goto label_1ac9a4;
        }
    }
    ctx->pc = 0x1AC998u;
label_1ac998:
    // 0x1ac998: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AC998u;
    {
        const bool branch_taken_0x1ac998 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AC99Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC998u;
            // 0x1ac99c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac998) {
            ctx->pc = 0x1AC9A8u;
            goto label_1ac9a8;
        }
    }
    ctx->pc = 0x1AC9A0u;
    // 0x1ac9a0: 0x2403007f  addiu       $v1, $zero, 0x7F
    ctx->pc = 0x1ac9a0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 127));
label_1ac9a4:
    // 0x1ac9a4: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1ac9a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1ac9a8:
    // 0x1ac9a8: 0x16a20003  bne         $s5, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AC9A8u;
    {
        const bool branch_taken_0x1ac9a8 = (GPR_U64(ctx, 21) != GPR_U64(ctx, 2));
        if (branch_taken_0x1ac9a8) {
            ctx->pc = 0x1AC9B8u;
            goto label_1ac9b8;
        }
    }
    ctx->pc = 0x1AC9B0u;
    // 0x1ac9b0: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x1AC9B0u;
    {
        const bool branch_taken_0x1ac9b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC9B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC9B0u;
            // 0x1ac9b4: 0x60a82d  daddu       $s5, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac9b0) {
            ctx->pc = 0x1ACA40u;
            goto label_1aca40;
        }
    }
    ctx->pc = 0x1AC9B8u;
label_1ac9b8:
    // 0x1ac9b8: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1ac9b8u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ac9bc: 0x6a00004  bltz        $s5, . + 4 + (0x4 << 2)
    ctx->pc = 0x1AC9BCu;
    {
        const bool branch_taken_0x1ac9bc = (GPR_S64(ctx, 21) < 0);
        ctx->pc = 0x1AC9C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC9BCu;
            // 0x1ac9c0: 0x468000e0  cvt.s.w     $f3, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[3] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac9bc) {
            ctx->pc = 0x1AC9D0u;
            goto label_1ac9d0;
        }
    }
    ctx->pc = 0x1AC9C4u;
    // 0x1ac9c4: 0x44950000  mtc1        $s5, $f0
    ctx->pc = 0x1ac9c4u;
    { uint32_t bits = GPR_U32(ctx, 21); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ac9c8: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1AC9C8u;
    {
        const bool branch_taken_0x1ac9c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AC9CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AC9C8u;
            // 0x1ac9cc: 0x468000a0  cvt.s.w     $f2, $f0 (Delay Slot)
        { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ac9c8) {
            ctx->pc = 0x1AC9ECu;
            goto label_1ac9ec;
        }
    }
    ctx->pc = 0x1AC9D0u;
label_1ac9d0:
    // 0x1ac9d0: 0x151842  srl         $v1, $s5, 1
    ctx->pc = 0x1ac9d0u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 21), 1));
    // 0x1ac9d4: 0x32a20001  andi        $v0, $s5, 0x1
    ctx->pc = 0x1ac9d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 21) & (uint64_t)(uint16_t)1);
    // 0x1ac9d8: 0x621825  or          $v1, $v1, $v0
    ctx->pc = 0x1ac9d8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1ac9dc: 0x44830000  mtc1        $v1, $f0
    ctx->pc = 0x1ac9dcu;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ac9e0: 0x0  nop
    ctx->pc = 0x1ac9e0u;
    // NOP
    // 0x1ac9e4: 0x468000a0  cvt.s.w     $f2, $f0
    ctx->pc = 0x1ac9e4u;
    { int32_t tmp; std::memcpy(&tmp, &ctx->f[0], sizeof(tmp)); ctx->f[2] = FPU_CVT_S_W(tmp); }
    // 0x1ac9e8: 0x46021080  add.s       $f2, $f2, $f2
    ctx->pc = 0x1ac9e8u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[2]);
label_1ac9ec:
    // 0x1ac9ec: 0x3c034300  lui         $v1, 0x4300
    ctx->pc = 0x1ac9ecu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)17152 << 16));
    // 0x1ac9f0: 0x3c024f00  lui         $v0, 0x4F00
    ctx->pc = 0x1ac9f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)20224 << 16));
    // 0x1ac9f4: 0x44830800  mtc1        $v1, $f1
    ctx->pc = 0x1ac9f4u;
    { uint32_t bits = GPR_U32(ctx, 3); std::memcpy(&ctx->f[1], &bits, sizeof(bits)); }
    // 0x1ac9f8: 0x44820000  mtc1        $v0, $f0
    ctx->pc = 0x1ac9f8u;
    { uint32_t bits = GPR_U32(ctx, 2); std::memcpy(&ctx->f[0], &bits, sizeof(bits)); }
    // 0x1ac9fc: 0x0  nop
    ctx->pc = 0x1ac9fcu;
    // NOP
    // 0x1aca00: 0x46011043  div.s       $f1, $f2, $f1
    ctx->pc = 0x1aca00u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ uint32_t __sign = (std::bit_cast<uint32_t>(ctx->f[2]) ^ std::bit_cast<uint32_t>(ctx->f[1])) & 0x80000000u; uint32_t __maxf = 0x7F7FFFFFu | __sign; ctx->f[1] = std::bit_cast<float>(__maxf); } else ctx->f[1] = ctx->f[2] / ctx->f[1];
    // 0x1aca04: 0x0  nop
    ctx->pc = 0x1aca04u;
    // NOP
    // 0x1aca08: 0x46011842  mul.s       $f1, $f3, $f1
    ctx->pc = 0x1aca08u;
    ctx->f[1] = FPU_MUL_S(ctx->f[3], ctx->f[1]);
    // 0x1aca0c: 0x46010036  c.le.s      $f0, $f1
    ctx->pc = 0x1aca0cu;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1aca10: 0x45010005  bc1t        . + 4 + (0x5 << 2)
    ctx->pc = 0x1ACA10u;
    {
        const bool branch_taken_0x1aca10 = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1aca10) {
            ctx->pc = 0x1ACA28u;
            goto label_1aca28;
        }
    }
    ctx->pc = 0x1ACA18u;
    // 0x1aca18: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1aca18u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1aca1c: 0x44150800  mfc1        $s5, $f1
    ctx->pc = 0x1aca1cu;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 21, bits); }
    // 0x1aca20: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1ACA20u;
    {
        const bool branch_taken_0x1aca20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aca20) {
            ctx->pc = 0x1ACA40u;
            goto label_1aca40;
        }
    }
    ctx->pc = 0x1ACA28u;
label_1aca28:
    // 0x1aca28: 0x46000841  sub.s       $f1, $f1, $f0
    ctx->pc = 0x1aca28u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1aca2c: 0x3c028000  lui         $v0, 0x8000
    ctx->pc = 0x1aca2cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)32768 << 16));
    // 0x1aca30: 0x46000864  .word       0x46000864                   # cvt.w.s     $f1, $f1 # 00000000 <InstrIdType: CPU_COP1_FPUS>
    ctx->pc = 0x1aca30u;
    { int32_t tmp = FPU_CVT_W_S(ctx->f[1]); std::memcpy(&ctx->f[1], &tmp, sizeof(tmp)); }
    // 0x1aca34: 0x44150800  mfc1        $s5, $f1
    ctx->pc = 0x1aca34u;
    { uint32_t bits; std::memcpy(&bits, &ctx->f[1], sizeof(bits)); SET_GPR_U32(ctx, 21, bits); }
    // 0x1aca38: 0x0  nop
    ctx->pc = 0x1aca38u;
    // NOP
    // 0x1aca3c: 0x2a2a825  or          $s5, $s5, $v0
    ctx->pc = 0x1aca3cu;
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 21) | GPR_U64(ctx, 2));
label_1aca40:
    // 0x1aca40: 0x92440009  lbu         $a0, 0x9($s2)
    ctx->pc = 0x1aca40u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 9)));
    // 0x1aca44: 0x32c2007f  andi        $v0, $s6, 0x7F
    ctx->pc = 0x1aca44u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 22) & (uint64_t)(uint16_t)127);
    // 0x1aca48: 0x92430008  lbu         $v1, 0x8($s2)
    ctx->pc = 0x1aca48u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x1aca4c: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1aca4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1aca50: 0x133c3c  dsll32      $a3, $s3, 16
    ctx->pc = 0x1aca50u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 19) << (32 + 16));
    // 0x1aca54: 0x152e3c  dsll32      $a1, $s5, 24
    ctx->pc = 0x1aca54u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 21) << (32 + 24));
    // 0x1aca58: 0x14363c  dsll32      $a2, $s4, 24
    ctx->pc = 0x1aca58u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 20) << (32 + 24));
    // 0x1aca5c: 0x1e463c  dsll32      $t0, $fp, 24
    ctx->pc = 0x1aca5cu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 30) << (32 + 24));
    // 0x1aca60: 0x2021025  or          $v0, $s0, $v0
    ctx->pc = 0x1aca60u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1aca64: 0x73c3f  dsra32      $a3, $a3, 16
    ctx->pc = 0x1aca64u;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 16));
    // 0x1aca68: 0x52e3f  dsra32      $a1, $a1, 24
    ctx->pc = 0x1aca68u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 24));
    // 0x1aca6c: 0x6363f  dsra32      $a2, $a2, 24
    ctx->pc = 0x1aca6cu;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 24));
    // 0x1aca70: 0x30840001  andi        $a0, $a0, 0x1
    ctx->pc = 0x1aca70u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x1aca74: 0x8463f  dsra32      $t0, $t0, 24
    ctx->pc = 0x1aca74u;
    SET_GPR_S64(ctx, 8, GPR_S64(ctx, 8) >> (32 + 24));
    // 0x1aca78: 0x421c0  sll         $a0, $a0, 7
    ctx->pc = 0x1aca78u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 7));
    // 0x1aca7c: 0x3063007f  andi        $v1, $v1, 0x7F
    ctx->pc = 0x1aca7cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)127);
    // 0x1aca80: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1aca80u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1aca84: 0xc069cc4  jal         func_1A7310
    ctx->pc = 0x1ACA84u;
    SET_GPR_U32(ctx, 31, 0x1ACA8Cu);
    ctx->pc = 0x1ACA88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACA84u;
            // 0x1aca88: 0x432025  or          $a0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A7310u;
    if (runtime->hasFunction(0x1A7310u)) {
        auto targetFn = runtime->lookupFunction(0x1A7310u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ACA8Cu; }
        if (ctx->pc != 0x1ACA8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A7310_0x1a7310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ACA8Cu; }
        if (ctx->pc != 0x1ACA8Cu) { return; }
    }
    ctx->pc = 0x1ACA8Cu;
label_1aca8c:
    // 0x1aca8c: 0x4410016  bgez        $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1ACA8Cu;
    {
        const bool branch_taken_0x1aca8c = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1aca8c) {
            ctx->pc = 0x1ACAE8u;
            goto label_1acae8;
        }
    }
    ctx->pc = 0x1ACA94u;
    // 0x1aca94: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1ACA94u;
    {
        const bool branch_taken_0x1aca94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1aca94) {
            ctx->pc = 0x1ACB14u;
            goto label_1acb14;
        }
    }
    ctx->pc = 0x1ACA9Cu;
label_1aca9c:
    // 0x1aca9c: 0x14620010  bne         $v1, $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x1ACA9Cu;
    {
        const bool branch_taken_0x1aca9c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1aca9c) {
            ctx->pc = 0x1ACAE0u;
            goto label_1acae0;
        }
    }
    ctx->pc = 0x1ACAA4u;
    // 0x1acaa4: 0x92440009  lbu         $a0, 0x9($s2)
    ctx->pc = 0x1acaa4u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 9)));
    // 0x1acaa8: 0x32c2007f  andi        $v0, $s6, 0x7F
    ctx->pc = 0x1acaa8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 22) & (uint64_t)(uint16_t)127);
    // 0x1acaac: 0x92430008  lbu         $v1, 0x8($s2)
    ctx->pc = 0x1acaacu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x1acab0: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x1acab0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1acab4: 0x2021025  or          $v0, $s0, $v0
    ctx->pc = 0x1acab4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 16) | GPR_U64(ctx, 2));
    // 0x1acab8: 0x30840001  andi        $a0, $a0, 0x1
    ctx->pc = 0x1acab8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x1acabc: 0x421c0  sll         $a0, $a0, 7
    ctx->pc = 0x1acabcu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 7));
    // 0x1acac0: 0x3063007f  andi        $v1, $v1, 0x7F
    ctx->pc = 0x1acac0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)127);
    // 0x1acac4: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x1acac4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1acac8: 0xc069d0c  jal         func_1A7430
    ctx->pc = 0x1ACAC8u;
    SET_GPR_U32(ctx, 31, 0x1ACAD0u);
    ctx->pc = 0x1ACACCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACAC8u;
            // 0x1acacc: 0x432025  or          $a0, $v0, $v1 (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A7430u;
    if (runtime->hasFunction(0x1A7430u)) {
        auto targetFn = runtime->lookupFunction(0x1A7430u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ACAD0u; }
        if (ctx->pc != 0x1ACAD0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A7430_0x1a7430(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1ACAD0u; }
        if (ctx->pc != 0x1ACAD0u) { return; }
    }
    ctx->pc = 0x1ACAD0u;
label_1acad0:
    // 0x1acad0: 0x4410005  bgez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1ACAD0u;
    {
        const bool branch_taken_0x1acad0 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1acad0) {
            ctx->pc = 0x1ACAE8u;
            goto label_1acae8;
        }
    }
    ctx->pc = 0x1ACAD8u;
    // 0x1acad8: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1ACAD8u;
    {
        const bool branch_taken_0x1acad8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1acad8) {
            ctx->pc = 0x1ACB14u;
            goto label_1acb14;
        }
    }
    ctx->pc = 0x1ACAE0u;
label_1acae0:
    // 0x1acae0: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x1ACAE0u;
    {
        const bool branch_taken_0x1acae0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ACAE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACAE0u;
            // 0x1acae4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1acae0) {
            ctx->pc = 0x1ACB2Cu;
            goto label_1acb2c;
        }
    }
    ctx->pc = 0x1ACAE8u;
label_1acae8:
    // 0x1acae8: 0x9243000b  lbu         $v1, 0xB($s2)
    ctx->pc = 0x1acae8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 18), 11)));
    // 0x1acaec: 0x240200ff  addiu       $v0, $zero, 0xFF
    ctx->pc = 0x1acaecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1acaf0: 0x10620008  beq         $v1, $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1ACAF0u;
    {
        const bool branch_taken_0x1acaf0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1acaf0) {
            ctx->pc = 0x1ACB14u;
            goto label_1acb14;
        }
    }
    ctx->pc = 0x1ACAF8u;
    // 0x1acaf8: 0x10760006  beq         $v1, $s6, . + 4 + (0x6 << 2)
    ctx->pc = 0x1ACAF8u;
    {
        const bool branch_taken_0x1acaf8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 22));
        ctx->pc = 0x1ACAFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACAF8u;
            // 0x1acafc: 0x31040  sll         $v0, $v1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1acaf8) {
            ctx->pc = 0x1ACB14u;
            goto label_1acb14;
        }
    }
    ctx->pc = 0x1ACB00u;
    // 0x1acb00: 0x60b02d  daddu       $s6, $v1, $zero
    ctx->pc = 0x1acb00u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1acb04: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1acb04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1acb08: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1acb08u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1acb0c: 0x1000ff5f  b           . + 4 + (-0xA1 << 2)
    ctx->pc = 0x1ACB0Cu;
    {
        const bool branch_taken_0x1acb0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ACB10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACB0Cu;
            // 0x1acb10: 0x2e29021  addu        $s2, $s7, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1acb0c) {
            ctx->pc = 0x1AC88Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ac88c;
        }
    }
    ctx->pc = 0x1ACB14u;
label_1acb14:
    // 0x1acb14: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1acb14u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1acb18:
    // 0x1acb18: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1ACB18u;
    {
        const bool branch_taken_0x1acb18 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ACB1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACB18u;
            // 0x1acb1c: 0xdfbf0090  ld          $ra, 0x90($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1acb18) {
            ctx->pc = 0x1ACB30u;
            goto label_1acb30;
        }
    }
    ctx->pc = 0x1ACB20u;
label_1acb20:
    // 0x1acb20: 0x3082007f  andi        $v0, $a0, 0x7F
    ctx->pc = 0x1acb20u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)127);
label_1acb24:
    // 0x1acb24: 0x1000ff59  b           . + 4 + (-0xA7 << 2)
    ctx->pc = 0x1ACB24u;
    {
        const bool branch_taken_0x1acb24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1ACB28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACB24u;
            // 0x1acb28: 0x28400  sll         $s0, $v0, 16 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1acb24) {
            ctx->pc = 0x1AC88Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ac88c;
        }
    }
    ctx->pc = 0x1ACB2Cu;
label_1acb2c:
    // 0x1acb2c: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x1acb2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_1acb30:
    // 0x1acb30: 0x7bbe0080  lq          $fp, 0x80($sp)
    ctx->pc = 0x1acb30u;
    SET_GPR_VEC(ctx, 30, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1acb34: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x1acb34u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1acb38: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1acb38u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1acb3c: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1acb3cu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1acb40: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1acb40u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1acb44: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1acb44u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1acb48: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1acb48u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1acb4c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1acb4cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1acb50: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1acb50u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1acb54: 0x3e00008  jr          $ra
    ctx->pc = 0x1ACB54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1ACB58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1ACB54u;
            // 0x1acb58: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AC88Cu: goto label_1ac88c;
            case 0x1AC8BCu: goto label_1ac8bc;
            case 0x1AC8C0u: goto label_1ac8c0;
            case 0x1AC8D4u: goto label_1ac8d4;
            case 0x1AC8F0u: goto label_1ac8f0;
            case 0x1AC920u: goto label_1ac920;
            case 0x1AC92Cu: goto label_1ac92c;
            case 0x1AC934u: goto label_1ac934;
            case 0x1AC95Cu: goto label_1ac95c;
            case 0x1AC984u: goto label_1ac984;
            case 0x1AC988u: goto label_1ac988;
            case 0x1AC998u: goto label_1ac998;
            case 0x1AC9A4u: goto label_1ac9a4;
            case 0x1AC9A8u: goto label_1ac9a8;
            case 0x1AC9B8u: goto label_1ac9b8;
            case 0x1AC9D0u: goto label_1ac9d0;
            case 0x1AC9ECu: goto label_1ac9ec;
            case 0x1ACA28u: goto label_1aca28;
            case 0x1ACA40u: goto label_1aca40;
            case 0x1ACA8Cu: goto label_1aca8c;
            case 0x1ACA9Cu: goto label_1aca9c;
            case 0x1ACAD0u: goto label_1acad0;
            case 0x1ACAE0u: goto label_1acae0;
            case 0x1ACAE8u: goto label_1acae8;
            case 0x1ACB14u: goto label_1acb14;
            case 0x1ACB18u: goto label_1acb18;
            case 0x1ACB20u: goto label_1acb20;
            case 0x1ACB24u: goto label_1acb24;
            case 0x1ACB2Cu: goto label_1acb2c;
            case 0x1ACB30u: goto label_1acb30;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1ACB5Cu;
    // 0x1acb5c: 0x0  nop
    ctx->pc = 0x1acb5cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
