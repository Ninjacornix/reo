#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C5760
// Address: 0x1c5760 - 0x1c58c0
void sub_001C5760_0x1c5760(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C5760_0x1c5760");
#endif

    switch (ctx->pc) {
        case 0x1c5798u: goto label_1c5798;
        case 0x1c5840u: goto label_1c5840;
        case 0x1c584cu: goto label_1c584c;
        case 0x1c5864u: goto label_1c5864;
        case 0x1c5874u: goto label_1c5874;
        case 0x1c587cu: goto label_1c587c;
        case 0x1c5898u: goto label_1c5898;
        case 0x1c58a0u: goto label_1c58a0;
        default: break;
    }

    ctx->pc = 0x1c5760u;

    // 0x1c5760: 0x94830000  lhu         $v1, 0x0($a0)
    ctx->pc = 0x1c5760u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c5764: 0x24025963  addiu       $v0, $zero, 0x5963
    ctx->pc = 0x1c5764u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 22883));
    // 0x1c5768: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C5768u;
    {
        const bool branch_taken_0x1c5768 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C576Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5768u;
            // 0x1c576c: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5768) {
            ctx->pc = 0x1C5778u;
            goto label_1c5778;
        }
    }
    ctx->pc = 0x1C5770u;
    // 0x1c5770: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x1C5770u;
    {
        const bool branch_taken_0x1c5770 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c5770) {
            ctx->pc = 0x1C5810u;
            goto label_1c5810;
        }
    }
    ctx->pc = 0x1C5778u;
label_1c5778:
    // 0x1c5778: 0x94870002  lhu         $a3, 0x2($a0)
    ctx->pc = 0x1c5778u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x1c577c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1c577cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5780: 0x94890004  lhu         $t1, 0x4($a0)
    ctx->pc = 0x1c5780u;
    SET_GPR_U32(ctx, 9, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1c5784: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x1c5784u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5788: 0x24840008  addiu       $a0, $a0, 0x8
    ctx->pc = 0x1c5788u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 8));
    // 0x1c578c: 0x3c020001  lui         $v0, 0x1
    ctx->pc = 0x1c578cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)1 << 16));
    // 0x1c5790: 0x3406ff53  ori         $a2, $zero, 0xFF53
    ctx->pc = 0x1c5790u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65363);
    // 0x1c5794: 0x3443fe5c  ori         $v1, $v0, 0xFE5C
    ctx->pc = 0x1c5794u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65116);
label_1c5798:
    // 0x1c5798: 0x94850000  lhu         $a1, 0x0($a0)
    ctx->pc = 0x1c5798u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c579c: 0x30e2ffff  andi        $v0, $a3, 0xFFFF
    ctx->pc = 0x1c579cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)65535);
    // 0x1c57a0: 0xa72826  xor         $a1, $a1, $a3
    ctx->pc = 0x1c57a0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) ^ GPR_U64(ctx, 7));
    // 0x1c57a4: 0xa4850000  sh          $a1, 0x0($a0)
    ctx->pc = 0x1c57a4u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x1c57a8: 0x94850000  lhu         $a1, 0x0($a0)
    ctx->pc = 0x1c57a8u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c57ac: 0x1052821  addu        $a1, $t0, $a1
    ctx->pc = 0x1c57acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 5)));
    // 0x1c57b0: 0x24840002  addiu       $a0, $a0, 0x2
    ctx->pc = 0x1c57b0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
    // 0x1c57b4: 0x14400002  bnez        $v0, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C57B4u;
    {
        const bool branch_taken_0x1c57b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C57B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C57B4u;
            // 0x1c57b8: 0x30a8ffff  andi        $t0, $a1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 8, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c57b4) {
            ctx->pc = 0x1C57C0u;
            goto label_1c57c0;
        }
    }
    ctx->pc = 0x1C57BCu;
    // 0x1c57bc: 0x64070001  daddiu      $a3, $zero, 0x1
    ctx->pc = 0x1c57bcu;
    SET_GPR_S64(ctx, 7, (int64_t)GPR_S64(ctx, 0) + (int64_t)(int32_t)1);
label_1c57c0:
    // 0x1c57c0: 0x30e7ffff  andi        $a3, $a3, 0xFFFF
    ctx->pc = 0x1c57c0u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)65535);
    // 0x1c57c4: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x1c57c4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x1c57c8: 0x72880  sll         $a1, $a3, 2
    ctx->pc = 0x1c57c8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
    // 0x1c57cc: 0x143102a  slt         $v0, $t2, $v1
    ctx->pc = 0x1c57ccu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1c57d0: 0xa72821  addu        $a1, $a1, $a3
    ctx->pc = 0x1c57d0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x1c57d4: 0x52840  sll         $a1, $a1, 1
    ctx->pc = 0x1c57d4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x1c57d8: 0xa72821  addu        $a1, $a1, $a3
    ctx->pc = 0x1c57d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 7)));
    // 0x1c57dc: 0x52900  sll         $a1, $a1, 4
    ctx->pc = 0x1c57dcu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x1c57e0: 0xa6001a  div         $zero, $a1, $a2
    ctx->pc = 0x1c57e0u;
    { int32_t divisor = GPR_S32(ctx, 6);    int32_t dividend = GPR_S32(ctx, 5);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1c57e4: 0x0  nop
    ctx->pc = 0x1c57e4u;
    // NOP
    // 0x1c57e8: 0x0  nop
    ctx->pc = 0x1c57e8u;
    // NOP
    // 0x1c57ec: 0x2810  mfhi        $a1
    ctx->pc = 0x1c57ecu;
    SET_GPR_U64(ctx, 5, ctx->hi);
    // 0x1c57f0: 0x1440ffe9  bnez        $v0, . + 4 + (-0x17 << 2)
    ctx->pc = 0x1C57F0u;
    {
        const bool branch_taken_0x1c57f0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C57F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C57F0u;
            // 0x1c57f4: 0x30a7ffff  andi        $a3, $a1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 7, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c57f0) {
            ctx->pc = 0x1C5798u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c5798;
        }
    }
    ctx->pc = 0x1C57F8u;
    // 0x1c57f8: 0x3123ffff  andi        $v1, $t1, 0xFFFF
    ctx->pc = 0x1c57f8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)65535);
    // 0x1c57fc: 0x3102ffff  andi        $v0, $t0, 0xFFFF
    ctx->pc = 0x1c57fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)65535);
    // 0x1c5800: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C5800u;
    {
        const bool branch_taken_0x1c5800 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C5804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5800u;
            // 0x1c5804: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5800) {
            ctx->pc = 0x1C5810u;
            goto label_1c5810;
        }
    }
    ctx->pc = 0x1C5808u;
    // 0x1c5808: 0x10000001  b           . + 4 + (0x1 << 2)
    ctx->pc = 0x1C5808u;
    {
        const bool branch_taken_0x1c5808 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C580Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5808u;
            // 0x1c580c: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c5808) {
            ctx->pc = 0x1C5810u;
            goto label_1c5810;
        }
    }
    ctx->pc = 0x1C5810u;
label_1c5810:
    // 0x1c5810: 0x3e00008  jr          $ra
    ctx->pc = 0x1C5810u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C5778u: goto label_1c5778;
            case 0x1C5798u: goto label_1c5798;
            case 0x1C57C0u: goto label_1c57c0;
            case 0x1C5810u: goto label_1c5810;
            case 0x1C5840u: goto label_1c5840;
            case 0x1C584Cu: goto label_1c584c;
            case 0x1C5864u: goto label_1c5864;
            case 0x1C5874u: goto label_1c5874;
            case 0x1C587Cu: goto label_1c587c;
            case 0x1C5898u: goto label_1c5898;
            case 0x1C58A0u: goto label_1c58a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C5818u;
    // 0x1c5818: 0x0  nop
    ctx->pc = 0x1c5818u;
    // NOP
    // 0x1c581c: 0x0  nop
    ctx->pc = 0x1c581cu;
    // NOP
    // 0x1c5820: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1c5820u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1c5824: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1c5824u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1c5828: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c5828u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c582c: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c582cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c5830: 0x80902d  daddu       $s2, $a0, $zero
    ctx->pc = 0x1c5830u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5834: 0x3c110025  lui         $s1, 0x25
    ctx->pc = 0x1c5834u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)37 << 16));
    // 0x1c5838: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c5838u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c583c: 0x26312d60  addiu       $s1, $s1, 0x2D60
    ctx->pc = 0x1c583cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 11616));
label_1c5840:
    // 0x1c5840: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1c5840u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5844: 0xc04a432  jal         func_1290C8
    ctx->pc = 0x1C5844u;
    SET_GPR_U32(ctx, 31, 0x1C584Cu);
    ctx->pc = 0x1C5848u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5844u;
            // 0x1c5848: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1290C8u;
    if (runtime->hasFunction(0x1290C8u)) {
        auto targetFn = runtime->lookupFunction(0x1290C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C584Cu; }
        if (ctx->pc != 0x1C584Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001290C8_0x1290c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C584Cu; }
        if (ctx->pc != 0x1C584Cu) { return; }
    }
    ctx->pc = 0x1C584Cu;
label_1c584c:
    // 0x1c584c: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1c584cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5850: 0x0  nop
    ctx->pc = 0x1c5850u;
    // NOP
    // 0x1c5854: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1C5854u;
    {
        const bool branch_taken_0x1c5854 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c5854) {
            ctx->pc = 0x1C5840u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c5840;
        }
    }
    ctx->pc = 0x1C585Cu;
    // 0x1c585c: 0xc04a702  jal         func_129C08
    ctx->pc = 0x1C585Cu;
    SET_GPR_U32(ctx, 31, 0x1C5864u);
    ctx->pc = 0x1C5860u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C585Cu;
            // 0x1c5860: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129C08u;
    if (runtime->hasFunction(0x129C08u)) {
        auto targetFn = runtime->lookupFunction(0x129C08u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5864u; }
        if (ctx->pc != 0x1C5864u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129C08_0x129c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5864u; }
        if (ctx->pc != 0x1C5864u) { return; }
    }
    ctx->pc = 0x1C5864u;
label_1c5864:
    // 0x1c5864: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1c5864u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c5868: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1c5868u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c586c: 0xc04a5e8  jal         func_1297A0
    ctx->pc = 0x1C586Cu;
    SET_GPR_U32(ctx, 31, 0x1C5874u);
    ctx->pc = 0x1C5870u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C586Cu;
            // 0x1c5870: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1297A0u;
    if (runtime->hasFunction(0x1297A0u)) {
        auto targetFn = runtime->lookupFunction(0x1297A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5874u; }
        if (ctx->pc != 0x1C5874u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001297A0_0x1297a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5874u; }
        if (ctx->pc != 0x1C5874u) { return; }
    }
    ctx->pc = 0x1C5874u;
label_1c5874:
    // 0x1c5874: 0xc04a752  jal         func_129D48
    ctx->pc = 0x1C5874u;
    SET_GPR_U32(ctx, 31, 0x1C587Cu);
    ctx->pc = 0x1C5878u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5874u;
            // 0x1c5878: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129D48u;
    if (runtime->hasFunction(0x129D48u)) {
        auto targetFn = runtime->lookupFunction(0x129D48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C587Cu; }
        if (ctx->pc != 0x1C587Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129D48_0x129d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C587Cu; }
        if (ctx->pc != 0x1C587Cu) { return; }
    }
    ctx->pc = 0x1C587Cu;
label_1c587c:
    // 0x1c587c: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c587cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c5880: 0x0  nop
    ctx->pc = 0x1c5880u;
    // NOP
    // 0x1c5884: 0x0  nop
    ctx->pc = 0x1c5884u;
    // NOP
    // 0x1c5888: 0x1443fffa  bne         $v0, $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1C5888u;
    {
        const bool branch_taken_0x1c5888 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x1c5888) {
            ctx->pc = 0x1C5874u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1c5874;
        }
    }
    ctx->pc = 0x1C5890u;
    // 0x1c5890: 0xc04a4d4  jal         func_129350
    ctx->pc = 0x1C5890u;
    SET_GPR_U32(ctx, 31, 0x1C5898u);
    ctx->pc = 0x1C5894u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5890u;
            // 0x1c5894: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129350u;
    if (runtime->hasFunction(0x129350u)) {
        auto targetFn = runtime->lookupFunction(0x129350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5898u; }
        if (ctx->pc != 0x1C5898u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00129350_0x129350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5898u; }
        if (ctx->pc != 0x1C5898u) { return; }
    }
    ctx->pc = 0x1C5898u;
label_1c5898:
    // 0x1c5898: 0xc0704b0  jal         func_1C12C0
    ctx->pc = 0x1C5898u;
    SET_GPR_U32(ctx, 31, 0x1C58A0u);
    ctx->pc = 0x1C589Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5898u;
            // 0x1c589c: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C12C0u;
    if (runtime->hasFunction(0x1C12C0u)) {
        auto targetFn = runtime->lookupFunction(0x1C12C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C58A0u; }
        if (ctx->pc != 0x1C58A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C12C0_0x1c12c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C58A0u; }
        if (ctx->pc != 0x1C58A0u) { return; }
    }
    ctx->pc = 0x1C58A0u;
label_1c58a0:
    // 0x1c58a0: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1c58a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c58a4: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1c58a4u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c58a8: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1c58a8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c58ac: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c58acu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c58b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C58B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C58B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C58B0u;
            // 0x1c58b4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C5778u: goto label_1c5778;
            case 0x1C5798u: goto label_1c5798;
            case 0x1C57C0u: goto label_1c57c0;
            case 0x1C5810u: goto label_1c5810;
            case 0x1C5840u: goto label_1c5840;
            case 0x1C584Cu: goto label_1c584c;
            case 0x1C5864u: goto label_1c5864;
            case 0x1C5874u: goto label_1c5874;
            case 0x1C587Cu: goto label_1c587c;
            case 0x1C5898u: goto label_1c5898;
            case 0x1C58A0u: goto label_1c58a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C58B8u;
    // 0x1c58b8: 0x0  nop
    ctx->pc = 0x1c58b8u;
    // NOP
    // 0x1c58bc: 0x0  nop
    ctx->pc = 0x1c58bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
