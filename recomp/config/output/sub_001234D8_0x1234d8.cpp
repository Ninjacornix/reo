#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001234D8
// Address: 0x1234d8 - 0x123a40
void sub_001234D8_0x1234d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001234D8_0x1234d8");
#endif

    switch (ctx->pc) {
        case 0x123548u: goto label_123548;
        case 0x123654u: goto label_123654;
        case 0x123700u: goto label_123700;
        case 0x123734u: goto label_123734;
        case 0x123754u: goto label_123754;
        case 0x1237b0u: goto label_1237b0;
        case 0x123808u: goto label_123808;
        case 0x123878u: goto label_123878;
        case 0x123898u: goto label_123898;
        case 0x1238ccu: goto label_1238cc;
        case 0x1238ecu: goto label_1238ec;
        case 0x123948u: goto label_123948;
        case 0x123998u: goto label_123998;
        case 0x1239f8u: goto label_1239f8;
        default: break;
    }

    ctx->pc = 0x1234d8u;

label_1234d8:
    // 0x1234d8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1234d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1234dc: 0x28a21000  slti        $v0, $a1, 0x1000
    ctx->pc = 0x1234dcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)4096) ? 1 : 0);
    // 0x1234e0: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x1234e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1234e4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1234e4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1234e8: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x1234e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x1234ec: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x1234ecu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1234f0: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x1234f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1234f4: 0x140902d  daddu       $s2, $t2, $zero
    ctx->pc = 0x1234f4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1234f8: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x1234f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x1234fc: 0x160982d  daddu       $s3, $t3, $zero
    ctx->pc = 0x1234fcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123500: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x123500u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x123504: 0x100a02d  daddu       $s4, $t0, $zero
    ctx->pc = 0x123504u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123508: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x123508u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x12350c: 0xe0a82d  daddu       $s5, $a3, $zero
    ctx->pc = 0x12350cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123510: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x123510u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x123514: 0x120b02d  daddu       $s6, $t1, $zero
    ctx->pc = 0x123514u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123518: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x123518u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x12351c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x12351cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123520: 0x27a60004  addiu       $a2, $sp, 0x4
    ctx->pc = 0x123520u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x123524: 0x27a8000c  addiu       $t0, $sp, 0xC
    ctx->pc = 0x123524u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 12));
    // 0x123528: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x123528u;
    {
        const bool branch_taken_0x123528 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x12352Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123528u;
            // 0x12352c: 0x27a70008  addiu       $a3, $sp, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123528) {
            ctx->pc = 0x123540u;
            goto label_123540;
        }
    }
    ctx->pc = 0x123530u;
    // 0x123530: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x123530u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x123534: 0x10000022  b           . + 4 + (0x22 << 2)
    ctx->pc = 0x123534u;
    {
        const bool branch_taken_0x123534 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x123538u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123534u;
            // 0x123538: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123534) {
            ctx->pc = 0x1235C0u;
            goto label_1235c0;
        }
    }
    ctx->pc = 0x12353Cu;
    // 0x12353c: 0x0  nop
    ctx->pc = 0x12353cu;
    // NOP
label_123540:
    // 0x123540: 0xc048c38  jal         func_1230E0
    ctx->pc = 0x123540u;
    SET_GPR_U32(ctx, 31, 0x123548u);
    ctx->pc = 0x1230E0u;
    if (runtime->hasFunction(0x1230E0u)) {
        auto targetFn = runtime->lookupFunction(0x1230E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x123548u; }
        if (ctx->pc != 0x123548u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001230E0_0x1230e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x123548u; }
        if (ctx->pc != 0x123548u) { return; }
    }
    ctx->pc = 0x123548u;
label_123548:
    // 0x123548: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x123548u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12354c: 0x1060001c  beqz        $v1, . + 4 + (0x1C << 2)
    ctx->pc = 0x12354Cu;
    {
        const bool branch_taken_0x12354c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x123550u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12354Cu;
            // 0x123550: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12354c) {
            ctx->pc = 0x1235C0u;
            goto label_1235c0;
        }
    }
    ctx->pc = 0x123554u;
    // 0x123554: 0x701823  subu        $v1, $v1, $s0
    ctx->pc = 0x123554u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x123558: 0x32400  sll         $a0, $v1, 16
    ctx->pc = 0x123558u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x12355c: 0x18800018  blez        $a0, . + 4 + (0x18 << 2)
    ctx->pc = 0x12355Cu;
    {
        const bool branch_taken_0x12355c = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x123560u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12355Cu;
            // 0x123560: 0xa6230000  sh          $v1, 0x0($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12355c) {
            ctx->pc = 0x1235C0u;
            goto label_1235c0;
        }
    }
    ctx->pc = 0x123564u;
    // 0x123564: 0x93a30004  lbu         $v1, 0x4($sp)
    ctx->pc = 0x123564u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x123568: 0x2407ffff  addiu       $a3, $zero, -0x1
    ctx->pc = 0x123568u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x12356c: 0x8fa60000  lw          $a2, 0x0($sp)
    ctx->pc = 0x12356cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x123570: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x123570u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x123574: 0x93a40008  lbu         $a0, 0x8($sp)
    ctx->pc = 0x123574u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x123578: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x123578u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12357c: 0xae660000  sw          $a2, 0x0($s3)
    ctx->pc = 0x12357cu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 6));
    // 0x123580: 0x8fa5000c  lw          $a1, 0xC($sp)
    ctx->pc = 0x123580u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x123584: 0xa2430000  sb          $v1, 0x0($s2)
    ctx->pc = 0x123584u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x123588: 0xa2840000  sb          $a0, 0x0($s4)
    ctx->pc = 0x123588u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x12358c: 0x8fa30050  lw          $v1, 0x50($sp)
    ctx->pc = 0x12358cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x123590: 0xac650000  sw          $a1, 0x0($v1)
    ctx->pc = 0x123590u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 5));
    // 0x123594: 0xa2a70000  sb          $a3, 0x0($s5)
    ctx->pc = 0x123594u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 7));
    // 0x123598: 0x82840000  lb          $a0, 0x0($s4)
    ctx->pc = 0x123598u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x12359c: 0x82430000  lb          $v1, 0x0($s2)
    ctx->pc = 0x12359cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1235a0: 0x641818  mult        $v1, $v1, $a0
    ctx->pc = 0x1235a0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x1235a4: 0x28640000  slti        $a0, $v1, 0x0
    ctx->pc = 0x1235a4u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1235a8: 0x24650007  addiu       $a1, $v1, 0x7
    ctx->pc = 0x1235a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 7));
    // 0x1235ac: 0xa4180b  movn        $v1, $a1, $a0
    ctx->pc = 0x1235acu;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 5));
    // 0x1235b0: 0x8fa40058  lw          $a0, 0x58($sp)
    ctx->pc = 0x1235b0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x1235b4: 0x318c3  sra         $v1, $v1, 3
    ctx->pc = 0x1235b4u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 3));
    // 0x1235b8: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1235b8u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1235bc: 0xac880000  sw          $t0, 0x0($a0)
    ctx->pc = 0x1235bcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 8));
label_1235c0:
    // 0x1235c0: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1235c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1235c4: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x1235c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1235c8: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x1235c8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1235cc: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x1235ccu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1235d0: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x1235d0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1235d4: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x1235d4u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1235d8: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x1235d8u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1235dc: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x1235dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1235e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1235E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1235E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1235E0u;
            // 0x1235e4: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1234D8u: goto label_1234d8;
            case 0x123540u: goto label_123540;
            case 0x123548u: goto label_123548;
            case 0x1235C0u: goto label_1235c0;
            case 0x123654u: goto label_123654;
            case 0x123668u: goto label_123668;
            case 0x1236D8u: goto label_1236d8;
            case 0x1236DCu: goto label_1236dc;
            case 0x123700u: goto label_123700;
            case 0x123734u: goto label_123734;
            case 0x123754u: goto label_123754;
            case 0x1237B0u: goto label_1237b0;
            case 0x123800u: goto label_123800;
            case 0x123808u: goto label_123808;
            case 0x123838u: goto label_123838;
            case 0x123858u: goto label_123858;
            case 0x123878u: goto label_123878;
            case 0x123884u: goto label_123884;
            case 0x123898u: goto label_123898;
            case 0x1238CCu: goto label_1238cc;
            case 0x1238ECu: goto label_1238ec;
            case 0x123948u: goto label_123948;
            case 0x123988u: goto label_123988;
            case 0x123998u: goto label_123998;
            case 0x1239BCu: goto label_1239bc;
            case 0x1239D8u: goto label_1239d8;
            case 0x1239F8u: goto label_1239f8;
            case 0x123A04u: goto label_123a04;
            case 0x123A38u: goto label_123a38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1235E8u;
    // 0x1235e8: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1235e8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1235ec: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x1235ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x1235f0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1235f0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1235f4: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x1235f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x1235f8: 0x24150001  addiu       $s5, $zero, 0x1
    ctx->pc = 0x1235f8u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1235fc: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x1235fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x123600: 0x2611000e  addiu       $s1, $s0, 0xE
    ctx->pc = 0x123600u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 14));
    // 0x123604: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x123604u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x123608: 0x2612000f  addiu       $s2, $s0, 0xF
    ctx->pc = 0x123608u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 15));
    // 0x12360c: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x12360cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x123610: 0x26130010  addiu       $s3, $s0, 0x10
    ctx->pc = 0x123610u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x123614: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x123614u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x123618: 0x2614000d  addiu       $s4, $s0, 0xD
    ctx->pc = 0x123618u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 16), 13));
    // 0x12361c: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x12361cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x123620: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x123620u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123624: 0xa6150002  sh          $s5, 0x2($s0)
    ctx->pc = 0x123624u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 21));
    // 0x123628: 0x26020018  addiu       $v0, $s0, 0x18
    ctx->pc = 0x123628u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x12362c: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x12362cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123630: 0x27a60010  addiu       $a2, $sp, 0x10
    ctx->pc = 0x123630u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
    // 0x123634: 0x2607000c  addiu       $a3, $s0, 0xC
    ctx->pc = 0x123634u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    // 0x123638: 0x280402d  daddu       $t0, $s4, $zero
    ctx->pc = 0x123638u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12363c: 0x240482d  daddu       $t1, $s2, $zero
    ctx->pc = 0x12363cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123640: 0x220502d  daddu       $t2, $s1, $zero
    ctx->pc = 0x123640u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123644: 0x260b0014  addiu       $t3, $s0, 0x14
    ctx->pc = 0x123644u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x123648: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x123648u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x12364c: 0xc048d36  jal         func_1234D8
    ctx->pc = 0x12364Cu;
    SET_GPR_U32(ctx, 31, 0x123654u);
    ctx->pc = 0x123650u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12364Cu;
            // 0x123650: 0xafb30008  sw          $s3, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1234D8u;
    goto label_1234d8;
    ctx->pc = 0x123654u;
label_123654:
    // 0x123654: 0x4410004  bgez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x123654u;
    {
        const bool branch_taken_0x123654 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x123658u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123654u;
            // 0x123658: 0x24070008  addiu       $a3, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123654) {
            ctx->pc = 0x123668u;
            goto label_123668;
        }
    }
    ctx->pc = 0x12365Cu;
    // 0x12365c: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x12365Cu;
    {
        const bool branch_taken_0x12365c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x123660u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12365Cu;
            // 0x123660: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12365c) {
            ctx->pc = 0x1236DCu;
            goto label_1236dc;
        }
    }
    ctx->pc = 0x123664u;
    // 0x123664: 0x0  nop
    ctx->pc = 0x123664u;
    // NOP
label_123668:
    // 0x123668: 0xae000034  sw          $zero, 0x34($s0)
    ctx->pc = 0x123668u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x12366c: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x12366cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x123670: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x123670u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x123674: 0xae000028  sw          $zero, 0x28($s0)
    ctx->pc = 0x123674u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 0));
    // 0x123678: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x123678u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x12367c: 0xa600001c  sh          $zero, 0x1C($s0)
    ctx->pc = 0x12367cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 28), (uint16_t)GPR_U32(ctx, 0));
    // 0x123680: 0xa6000026  sh          $zero, 0x26($s0)
    ctx->pc = 0x123680u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 38), (uint16_t)GPR_U32(ctx, 0));
    // 0x123684: 0xa6000024  sh          $zero, 0x24($s0)
    ctx->pc = 0x123684u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 36), (uint16_t)GPR_U32(ctx, 0));
    // 0x123688: 0x8e04003c  lw          $a0, 0x3C($s0)
    ctx->pc = 0x123688u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x12368c: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x12368cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x123690: 0x8e050040  lw          $a1, 0x40($s0)
    ctx->pc = 0x123690u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x123694: 0xae020050  sw          $v0, 0x50($s0)
    ctx->pc = 0x123694u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 2));
    // 0x123698: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x123698u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x12369c: 0x8e060044  lw          $a2, 0x44($s0)
    ctx->pc = 0x12369cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x1236a0: 0x82430000  lb          $v1, 0x0($s2)
    ctx->pc = 0x1236a0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1236a4: 0xae04005c  sw          $a0, 0x5C($s0)
    ctx->pc = 0x1236a4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 92), GPR_U32(ctx, 4));
    // 0x1236a8: 0xae030054  sw          $v1, 0x54($s0)
    ctx->pc = 0x1236a8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 3));
    // 0x1236ac: 0xa6020098  sh          $v0, 0x98($s0)
    ctx->pc = 0x1236acu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 152), (uint16_t)GPR_U32(ctx, 2));
    // 0x1236b0: 0x8e630000  lw          $v1, 0x0($s3)
    ctx->pc = 0x1236b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1236b4: 0xae050060  sw          $a1, 0x60($s0)
    ctx->pc = 0x1236b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 96), GPR_U32(ctx, 5));
    // 0x1236b8: 0xae030058  sw          $v1, 0x58($s0)
    ctx->pc = 0x1236b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 88), GPR_U32(ctx, 3));
    // 0x1236bc: 0xae060064  sw          $a2, 0x64($s0)
    ctx->pc = 0x1236bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 100), GPR_U32(ctx, 6));
    // 0x1236c0: 0xae00008c  sw          $zero, 0x8C($s0)
    ctx->pc = 0x1236c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 0));
    // 0x1236c4: 0xae000088  sw          $zero, 0x88($s0)
    ctx->pc = 0x1236c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 136), GPR_U32(ctx, 0));
    // 0x1236c8: 0x82820000  lb          $v0, 0x0($s4)
    ctx->pc = 0x1236c8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1236cc: 0x54470002  bnel        $v0, $a3, . + 4 + (0x2 << 2)
    ctx->pc = 0x1236CCu;
    {
        const bool branch_taken_0x1236cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 7));
        if (branch_taken_0x1236cc) {
            ctx->pc = 0x1236D0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1236CCu;
            // 0x1236d0: 0xa600009a  sh          $zero, 0x9A($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 154), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1236D8u;
            goto label_1236d8;
        }
    }
    ctx->pc = 0x1236D4u;
    // 0x1236d4: 0xa615009a  sh          $s5, 0x9A($s0)
    ctx->pc = 0x1236d4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 154), (uint16_t)GPR_U32(ctx, 21));
label_1236d8:
    // 0x1236d8: 0x87a20010  lh          $v0, 0x10($sp)
    ctx->pc = 0x1236d8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 16)));
label_1236dc:
    // 0x1236dc: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x1236dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1236e0: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x1236e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1236e4: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x1236e4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1236e8: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x1236e8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1236ec: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x1236ecu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1236f0: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x1236f0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x1236f4: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1236f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1236f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1236F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1236FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1236F8u;
            // 0x1236fc: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1234D8u: goto label_1234d8;
            case 0x123540u: goto label_123540;
            case 0x123548u: goto label_123548;
            case 0x1235C0u: goto label_1235c0;
            case 0x123654u: goto label_123654;
            case 0x123668u: goto label_123668;
            case 0x1236D8u: goto label_1236d8;
            case 0x1236DCu: goto label_1236dc;
            case 0x123700u: goto label_123700;
            case 0x123734u: goto label_123734;
            case 0x123754u: goto label_123754;
            case 0x1237B0u: goto label_1237b0;
            case 0x123800u: goto label_123800;
            case 0x123808u: goto label_123808;
            case 0x123838u: goto label_123838;
            case 0x123858u: goto label_123858;
            case 0x123878u: goto label_123878;
            case 0x123884u: goto label_123884;
            case 0x123898u: goto label_123898;
            case 0x1238CCu: goto label_1238cc;
            case 0x1238ECu: goto label_1238ec;
            case 0x123948u: goto label_123948;
            case 0x123988u: goto label_123988;
            case 0x123998u: goto label_123998;
            case 0x1239BCu: goto label_1239bc;
            case 0x1239D8u: goto label_1239d8;
            case 0x1239F8u: goto label_1239f8;
            case 0x123A04u: goto label_123a04;
            case 0x123A38u: goto label_123a38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x123700u;
label_123700:
    // 0x123700: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x123700u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x123704: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x123704u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x123708: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x123708u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12370c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x12370cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123710: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x123710u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x123714: 0x26110048  addiu       $s1, $s0, 0x48
    ctx->pc = 0x123714u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
    // 0x123718: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x123718u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12371c: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x12371cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x123720: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x123720u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x123724: 0x1462004c  bne         $v1, $v0, . + 4 + (0x4C << 2)
    ctx->pc = 0x123724u;
    {
        const bool branch_taken_0x123724 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x123728u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123724u;
            // 0x123728: 0x8e320000  lw          $s2, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123724) {
            ctx->pc = 0x123858u;
            goto label_123858;
        }
    }
    ctx->pc = 0x12372Cu;
    // 0x12372c: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x12372Cu;
    SET_GPR_U32(ctx, 31, 0x123734u);
    ctx->pc = 0x123730u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12372Cu;
            // 0x123730: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x123734u; }
        if (ctx->pc != 0x123734u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x123734u; }
        if (ctx->pc != 0x123734u) { return; }
    }
    ctx->pc = 0x123734u;
label_123734:
    // 0x123734: 0x54400048  bnel        $v0, $zero, . + 4 + (0x48 << 2)
    ctx->pc = 0x123734u;
    {
        const bool branch_taken_0x123734 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x123734) {
            ctx->pc = 0x123738u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x123734u;
            // 0x123738: 0x8e030004  lw          $v1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x123858u;
            goto label_123858;
        }
    }
    ctx->pc = 0x12373Cu;
    // 0x12373c: 0x8e04007c  lw          $a0, 0x7C($s0)
    ctx->pc = 0x12373cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x123740: 0x26050068  addiu       $a1, $s0, 0x68
    ctx->pc = 0x123740u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 104));
    // 0x123744: 0x8e020078  lw          $v0, 0x78($s0)
    ctx->pc = 0x123744u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x123748: 0x2606006c  addiu       $a2, $s0, 0x6C
    ctx->pc = 0x123748u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 108));
    // 0x12374c: 0x40f809  jalr        $v0
    ctx->pc = 0x12374Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x123754u);
        ctx->pc = 0x123750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12374Cu;
            // 0x123750: 0x26070070  addiu       $a3, $s0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x123754u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1234D8u: goto label_1234d8;
            case 0x123540u: goto label_123540;
            case 0x123548u: goto label_123548;
            case 0x1235C0u: goto label_1235c0;
            case 0x123654u: goto label_123654;
            case 0x123668u: goto label_123668;
            case 0x1236D8u: goto label_1236d8;
            case 0x1236DCu: goto label_1236dc;
            case 0x123700u: goto label_123700;
            case 0x123734u: goto label_123734;
            case 0x123754u: goto label_123754;
            case 0x1237B0u: goto label_1237b0;
            case 0x123800u: goto label_123800;
            case 0x123808u: goto label_123808;
            case 0x123838u: goto label_123838;
            case 0x123858u: goto label_123858;
            case 0x123878u: goto label_123878;
            case 0x123884u: goto label_123884;
            case 0x123898u: goto label_123898;
            case 0x1238CCu: goto label_1238cc;
            case 0x1238ECu: goto label_1238ec;
            case 0x123948u: goto label_123948;
            case 0x123988u: goto label_123988;
            case 0x123998u: goto label_123998;
            case 0x1239BCu: goto label_1239bc;
            case 0x1239D8u: goto label_1239d8;
            case 0x1239F8u: goto label_1239f8;
            case 0x123A04u: goto label_123a04;
            case 0x123A38u: goto label_123a38;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x123754u; }
            if (ctx->pc != 0x123754u) { return; }
        }
        }
    }
    ctx->pc = 0x123754u;
label_123754:
    // 0x123754: 0x8e240018  lw          $a0, 0x18($s1)
    ctx->pc = 0x123754u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x123758: 0x8e270020  lw          $a3, 0x20($s1)
    ctx->pc = 0x123758u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x12375c: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x12375cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x123760: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x123760u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x123764: 0x874823  subu        $t1, $a0, $a3
    ctx->pc = 0x123764u;
    SET_GPR_S32(ctx, 9, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x123768: 0x8204000e  lb          $a0, 0xE($s0)
    ctx->pc = 0x123768u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x12376c: 0x69102a  slt         $v0, $v1, $t1
    ctx->pc = 0x12376cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x123770: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x123770u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x123774: 0x62480b  movn        $t1, $v1, $v0
    ctx->pc = 0x123774u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 3));
    // 0x123778: 0x71840  sll         $v1, $a3, 1
    ctx->pc = 0x123778u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x12377c: 0x8e2b0014  lw          $t3, 0x14($s1)
    ctx->pc = 0x12377cu;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x123780: 0xa9102a  slt         $v0, $a1, $t1
    ctx->pc = 0x123780u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x123784: 0xa2480b  movn        $t1, $a1, $v0
    ctx->pc = 0x123784u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 5));
    // 0x123788: 0x1635021  addu        $t2, $t3, $v1
    ctx->pc = 0x123788u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 3)));
    // 0x12378c: 0x1486001c  bne         $a0, $a2, . + 4 + (0x1C << 2)
    ctx->pc = 0x12378Cu;
    {
        const bool branch_taken_0x12378c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        ctx->pc = 0x123790u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12378Cu;
            // 0x123790: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12378c) {
            ctx->pc = 0x123800u;
            goto label_123800;
        }
    }
    ctx->pc = 0x123794u;
    // 0x123794: 0x8e22001c  lw          $v0, 0x1C($s1)
    ctx->pc = 0x123794u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x123798: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x123798u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12379c: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x12379cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x1237a0: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1237a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1237a4: 0x19200024  blez        $t1, . + 4 + (0x24 << 2)
    ctx->pc = 0x1237A4u;
    {
        const bool branch_taken_0x1237a4 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x1237A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1237A4u;
            // 0x1237a8: 0x1625821  addu        $t3, $t3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1237a4) {
            ctx->pc = 0x123838u;
            goto label_123838;
        }
    }
    ctx->pc = 0x1237ACu;
    // 0x1237ac: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x1237acu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_1237b0:
    // 0x1237b0: 0x94e20000  lhu         $v0, 0x0($a3)
    ctx->pc = 0x1237b0u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1237b4: 0x82040  sll         $a0, $t0, 1
    ctx->pc = 0x1237b4u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x1237b8: 0x8a2821  addu        $a1, $a0, $t2
    ctx->pc = 0x1237b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 10)));
    // 0x1237bc: 0x8b2021  addu        $a0, $a0, $t3
    ctx->pc = 0x1237bcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
    // 0x1237c0: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x1237c0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1237c4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1237c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1237c8: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1237c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1237cc: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1237ccu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1237d0: 0xa4a20000  sh          $v0, 0x0($a1)
    ctx->pc = 0x1237d0u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1237d4: 0x109302a  slt         $a2, $t0, $t1
    ctx->pc = 0x1237d4u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x1237d8: 0x94e20002  lhu         $v0, 0x2($a3)
    ctx->pc = 0x1237d8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x1237dc: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x1237dcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x1237e0: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x1237e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1237e4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1237e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1237e8: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1237e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1237ec: 0x14c0fff0  bnez        $a2, . + 4 + (-0x10 << 2)
    ctx->pc = 0x1237ECu;
    {
        const bool branch_taken_0x1237ec = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1237F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1237ECu;
            // 0x1237f0: 0xa4820000  sh          $v0, 0x0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1237ec) {
            ctx->pc = 0x1237B0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1237b0;
        }
    }
    ctx->pc = 0x1237F4u;
    // 0x1237f4: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1237F4u;
    {
        const bool branch_taken_0x1237f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1237F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1237F4u;
            // 0x1237f8: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1237f4) {
            ctx->pc = 0x123838u;
            goto label_123838;
        }
    }
    ctx->pc = 0x1237FCu;
    // 0x1237fc: 0x0  nop
    ctx->pc = 0x1237fcu;
    // NOP
label_123800:
    // 0x123800: 0x1920000d  blez        $t1, . + 4 + (0xD << 2)
    ctx->pc = 0x123800u;
    {
        const bool branch_taken_0x123800 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x123804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123800u;
            // 0x123804: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123800) {
            ctx->pc = 0x123838u;
            goto label_123838;
        }
    }
    ctx->pc = 0x123808u;
label_123808:
    // 0x123808: 0x82040  sll         $a0, $t0, 1
    ctx->pc = 0x123808u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x12380c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x12380cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x123810: 0x921021  addu        $v0, $a0, $s2
    ctx->pc = 0x123810u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 18)));
    // 0x123814: 0x8a2021  addu        $a0, $a0, $t2
    ctx->pc = 0x123814u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 10)));
    // 0x123818: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x123818u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12381c: 0x109282a  slt         $a1, $t0, $t1
    ctx->pc = 0x12381cu;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x123820: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x123820u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x123824: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x123824u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x123828: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x123828u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x12382c: 0x14a0fff6  bnez        $a1, . + 4 + (-0xA << 2)
    ctx->pc = 0x12382Cu;
    {
        const bool branch_taken_0x12382c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x123830u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12382Cu;
            // 0x123830: 0xa4820000  sh          $v0, 0x0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12382c) {
            ctx->pc = 0x123808u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_123808;
        }
    }
    ctx->pc = 0x123834u;
    // 0x123834: 0x9203000e  lbu         $v1, 0xE($s0)
    ctx->pc = 0x123834u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_123838:
    // 0x123838: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x123838u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x12383c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x12383cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x123840: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x123840u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x123844: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x123844u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x123848: 0x1221018  mult        $v0, $t1, $v0
    ctx->pc = 0x123848u;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x12384c: 0xae090090  sw          $t1, 0x90($s0)
    ctx->pc = 0x12384cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 9));
    // 0x123850: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x123850u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x123854: 0xae020094  sw          $v0, 0x94($s0)
    ctx->pc = 0x123854u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
label_123858:
    // 0x123858: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x123858u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12385c: 0x54620009  bnel        $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x12385Cu;
    {
        const bool branch_taken_0x12385c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x12385c) {
            ctx->pc = 0x123860u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12385Cu;
            // 0x123860: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x123884u;
            goto label_123884;
        }
    }
    ctx->pc = 0x123864u;
    // 0x123864: 0x8e030080  lw          $v1, 0x80($s0)
    ctx->pc = 0x123864u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x123868: 0x8e040084  lw          $a0, 0x84($s0)
    ctx->pc = 0x123868u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x12386c: 0x8e050094  lw          $a1, 0x94($s0)
    ctx->pc = 0x12386cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x123870: 0x60f809  jalr        $v1
    ctx->pc = 0x123870u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x123878u);
        ctx->pc = 0x123874u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123870u;
            // 0x123874: 0x8e060090  lw          $a2, 0x90($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x123878u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1234D8u: goto label_1234d8;
            case 0x123540u: goto label_123540;
            case 0x123548u: goto label_123548;
            case 0x1235C0u: goto label_1235c0;
            case 0x123654u: goto label_123654;
            case 0x123668u: goto label_123668;
            case 0x1236D8u: goto label_1236d8;
            case 0x1236DCu: goto label_1236dc;
            case 0x123700u: goto label_123700;
            case 0x123734u: goto label_123734;
            case 0x123754u: goto label_123754;
            case 0x1237B0u: goto label_1237b0;
            case 0x123800u: goto label_123800;
            case 0x123808u: goto label_123808;
            case 0x123838u: goto label_123838;
            case 0x123858u: goto label_123858;
            case 0x123878u: goto label_123878;
            case 0x123884u: goto label_123884;
            case 0x123898u: goto label_123898;
            case 0x1238CCu: goto label_1238cc;
            case 0x1238ECu: goto label_1238ec;
            case 0x123948u: goto label_123948;
            case 0x123988u: goto label_123988;
            case 0x123998u: goto label_123998;
            case 0x1239BCu: goto label_1239bc;
            case 0x1239D8u: goto label_1239d8;
            case 0x1239F8u: goto label_1239f8;
            case 0x123A04u: goto label_123a04;
            case 0x123A38u: goto label_123a38;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x123878u; }
            if (ctx->pc != 0x123878u) { return; }
        }
        }
    }
    ctx->pc = 0x123878u;
label_123878:
    // 0x123878: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x123878u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x12387c: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x12387cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x123880: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x123880u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_123884:
    // 0x123884: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x123884u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x123888: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x123888u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12388c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12388cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x123890: 0x3e00008  jr          $ra
    ctx->pc = 0x123890u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x123894u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123890u;
            // 0x123894: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1234D8u: goto label_1234d8;
            case 0x123540u: goto label_123540;
            case 0x123548u: goto label_123548;
            case 0x1235C0u: goto label_1235c0;
            case 0x123654u: goto label_123654;
            case 0x123668u: goto label_123668;
            case 0x1236D8u: goto label_1236d8;
            case 0x1236DCu: goto label_1236dc;
            case 0x123700u: goto label_123700;
            case 0x123734u: goto label_123734;
            case 0x123754u: goto label_123754;
            case 0x1237B0u: goto label_1237b0;
            case 0x123800u: goto label_123800;
            case 0x123808u: goto label_123808;
            case 0x123838u: goto label_123838;
            case 0x123858u: goto label_123858;
            case 0x123878u: goto label_123878;
            case 0x123884u: goto label_123884;
            case 0x123898u: goto label_123898;
            case 0x1238CCu: goto label_1238cc;
            case 0x1238ECu: goto label_1238ec;
            case 0x123948u: goto label_123948;
            case 0x123988u: goto label_123988;
            case 0x123998u: goto label_123998;
            case 0x1239BCu: goto label_1239bc;
            case 0x1239D8u: goto label_1239d8;
            case 0x1239F8u: goto label_1239f8;
            case 0x123A04u: goto label_123a04;
            case 0x123A38u: goto label_123a38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x123898u;
label_123898:
    // 0x123898: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x123898u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12389c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12389cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1238a0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1238a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1238a4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1238a4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1238a8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1238a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1238ac: 0x26110048  addiu       $s1, $s0, 0x48
    ctx->pc = 0x1238acu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
    // 0x1238b0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1238b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1238b4: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1238b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1238b8: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1238b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1238bc: 0x14620046  bne         $v1, $v0, . + 4 + (0x46 << 2)
    ctx->pc = 0x1238BCu;
    {
        const bool branch_taken_0x1238bc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1238C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1238BCu;
            // 0x1238c0: 0x8e320000  lw          $s2, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1238bc) {
            ctx->pc = 0x1239D8u;
            goto label_1239d8;
        }
    }
    ctx->pc = 0x1238C4u;
    // 0x1238c4: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x1238C4u;
    SET_GPR_U32(ctx, 31, 0x1238CCu);
    ctx->pc = 0x1238C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1238C4u;
            // 0x1238c8: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1238CCu; }
        if (ctx->pc != 0x1238CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1238CCu; }
        if (ctx->pc != 0x1238CCu) { return; }
    }
    ctx->pc = 0x1238CCu;
label_1238cc:
    // 0x1238cc: 0x54400042  bnel        $v0, $zero, . + 4 + (0x42 << 2)
    ctx->pc = 0x1238CCu;
    {
        const bool branch_taken_0x1238cc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1238cc) {
            ctx->pc = 0x1238D0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1238CCu;
            // 0x1238d0: 0x8e030004  lw          $v1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1239D8u;
            goto label_1239d8;
        }
    }
    ctx->pc = 0x1238D4u;
    // 0x1238d4: 0x8e04007c  lw          $a0, 0x7C($s0)
    ctx->pc = 0x1238d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x1238d8: 0x26050068  addiu       $a1, $s0, 0x68
    ctx->pc = 0x1238d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 104));
    // 0x1238dc: 0x8e020078  lw          $v0, 0x78($s0)
    ctx->pc = 0x1238dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x1238e0: 0x2606006c  addiu       $a2, $s0, 0x6C
    ctx->pc = 0x1238e0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 108));
    // 0x1238e4: 0x40f809  jalr        $v0
    ctx->pc = 0x1238E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1238ECu);
        ctx->pc = 0x1238E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1238E4u;
            // 0x1238e8: 0x26070070  addiu       $a3, $s0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1238ECu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1234D8u: goto label_1234d8;
            case 0x123540u: goto label_123540;
            case 0x123548u: goto label_123548;
            case 0x1235C0u: goto label_1235c0;
            case 0x123654u: goto label_123654;
            case 0x123668u: goto label_123668;
            case 0x1236D8u: goto label_1236d8;
            case 0x1236DCu: goto label_1236dc;
            case 0x123700u: goto label_123700;
            case 0x123734u: goto label_123734;
            case 0x123754u: goto label_123754;
            case 0x1237B0u: goto label_1237b0;
            case 0x123800u: goto label_123800;
            case 0x123808u: goto label_123808;
            case 0x123838u: goto label_123838;
            case 0x123858u: goto label_123858;
            case 0x123878u: goto label_123878;
            case 0x123884u: goto label_123884;
            case 0x123898u: goto label_123898;
            case 0x1238CCu: goto label_1238cc;
            case 0x1238ECu: goto label_1238ec;
            case 0x123948u: goto label_123948;
            case 0x123988u: goto label_123988;
            case 0x123998u: goto label_123998;
            case 0x1239BCu: goto label_1239bc;
            case 0x1239D8u: goto label_1239d8;
            case 0x1239F8u: goto label_1239f8;
            case 0x123A04u: goto label_123a04;
            case 0x123A38u: goto label_123a38;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1238ECu; }
            if (ctx->pc != 0x1238ECu) { return; }
        }
        }
    }
    ctx->pc = 0x1238ECu;
label_1238ec:
    // 0x1238ec: 0x8e240018  lw          $a0, 0x18($s1)
    ctx->pc = 0x1238ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1238f0: 0x8e290020  lw          $t1, 0x20($s1)
    ctx->pc = 0x1238f0u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x1238f4: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1238f4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1238f8: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x1238f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x1238fc: 0x894023  subu        $t0, $a0, $t1
    ctx->pc = 0x1238fcu;
    SET_GPR_S32(ctx, 8, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 9)));
    // 0x123900: 0x8204000e  lb          $a0, 0xE($s0)
    ctx->pc = 0x123900u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x123904: 0x68102a  slt         $v0, $v1, $t0
    ctx->pc = 0x123904u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x123908: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x123908u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x12390c: 0x62400b  movn        $t0, $v1, $v0
    ctx->pc = 0x12390cu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 8, GPR_VEC(ctx, 3));
    // 0x123910: 0x91840  sll         $v1, $t1, 1
    ctx->pc = 0x123910u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
    // 0x123914: 0x8e2b0014  lw          $t3, 0x14($s1)
    ctx->pc = 0x123914u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x123918: 0xa8102a  slt         $v0, $a1, $t0
    ctx->pc = 0x123918u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x12391c: 0xa2400b  movn        $t0, $a1, $v0
    ctx->pc = 0x12391cu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 8, GPR_VEC(ctx, 5));
    // 0x123920: 0x1635021  addu        $t2, $t3, $v1
    ctx->pc = 0x123920u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 3)));
    // 0x123924: 0x14860018  bne         $a0, $a2, . + 4 + (0x18 << 2)
    ctx->pc = 0x123924u;
    {
        const bool branch_taken_0x123924 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        ctx->pc = 0x123928u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123924u;
            // 0x123928: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123924) {
            ctx->pc = 0x123988u;
            goto label_123988;
        }
    }
    ctx->pc = 0x12392Cu;
    // 0x12392c: 0x8e22001c  lw          $v0, 0x1C($s1)
    ctx->pc = 0x12392cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x123930: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x123930u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123934: 0x491021  addu        $v0, $v0, $t1
    ctx->pc = 0x123934u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x123938: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x123938u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x12393c: 0x1900001f  blez        $t0, . + 4 + (0x1F << 2)
    ctx->pc = 0x12393Cu;
    {
        const bool branch_taken_0x12393c = (GPR_S64(ctx, 8) <= 0);
        ctx->pc = 0x123940u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12393Cu;
            // 0x123940: 0x1624821  addu        $t1, $t3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12393c) {
            ctx->pc = 0x1239BCu;
            goto label_1239bc;
        }
    }
    ctx->pc = 0x123944u;
    // 0x123944: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x123944u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_123948:
    // 0x123948: 0x90c20000  lbu         $v0, 0x0($a2)
    ctx->pc = 0x123948u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x12394c: 0x71840  sll         $v1, $a3, 1
    ctx->pc = 0x12394cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x123950: 0x6a2021  addu        $a0, $v1, $t2
    ctx->pc = 0x123950u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x123954: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x123954u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x123958: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x123958u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x12395c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x12395cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x123960: 0xa4820000  sh          $v0, 0x0($a0)
    ctx->pc = 0x123960u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x123964: 0xe8282a  slt         $a1, $a3, $t0
    ctx->pc = 0x123964u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x123968: 0x90c20001  lbu         $v0, 0x1($a2)
    ctx->pc = 0x123968u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 1)));
    // 0x12396c: 0x24c60002  addiu       $a2, $a2, 0x2
    ctx->pc = 0x12396cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
    // 0x123970: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x123970u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x123974: 0x14a0fff4  bnez        $a1, . + 4 + (-0xC << 2)
    ctx->pc = 0x123974u;
    {
        const bool branch_taken_0x123974 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x123978u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123974u;
            // 0x123978: 0xa4620000  sh          $v0, 0x0($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123974) {
            ctx->pc = 0x123948u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_123948;
        }
    }
    ctx->pc = 0x12397Cu;
    // 0x12397c: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x12397Cu;
    {
        const bool branch_taken_0x12397c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x123980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12397Cu;
            // 0x123980: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12397c) {
            ctx->pc = 0x1239BCu;
            goto label_1239bc;
        }
    }
    ctx->pc = 0x123984u;
    // 0x123984: 0x0  nop
    ctx->pc = 0x123984u;
    // NOP
label_123988:
    // 0x123988: 0x1900000c  blez        $t0, . + 4 + (0xC << 2)
    ctx->pc = 0x123988u;
    {
        const bool branch_taken_0x123988 = (GPR_S64(ctx, 8) <= 0);
        ctx->pc = 0x12398Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123988u;
            // 0x12398c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123988) {
            ctx->pc = 0x1239BCu;
            goto label_1239bc;
        }
    }
    ctx->pc = 0x123990u;
    // 0x123990: 0x140282d  daddu       $a1, $t2, $zero
    ctx->pc = 0x123990u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123994: 0x0  nop
    ctx->pc = 0x123994u;
    // NOP
label_123998:
    // 0x123998: 0x2471021  addu        $v0, $s2, $a3
    ctx->pc = 0x123998u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 7)));
    // 0x12399c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x12399cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x1239a0: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x1239a0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1239a4: 0xe8202a  slt         $a0, $a3, $t0
    ctx->pc = 0x1239a4u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x1239a8: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1239a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1239ac: 0xa4a30000  sh          $v1, 0x0($a1)
    ctx->pc = 0x1239acu;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1239b0: 0x1480fff9  bnez        $a0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1239B0u;
    {
        const bool branch_taken_0x1239b0 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x1239B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1239B0u;
            // 0x1239b4: 0x24a50002  addiu       $a1, $a1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1239b0) {
            ctx->pc = 0x123998u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_123998;
        }
    }
    ctx->pc = 0x1239B8u;
    // 0x1239b8: 0x9203000e  lbu         $v1, 0xE($s0)
    ctx->pc = 0x1239b8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_1239bc:
    // 0x1239bc: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x1239bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1239c0: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1239c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1239c4: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x1239c4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x1239c8: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x1239c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x1239cc: 0x1021018  mult        $v0, $t0, $v0
    ctx->pc = 0x1239ccu;
    { int64_t result = (int64_t)GPR_S32(ctx, 8) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1239d0: 0xae080090  sw          $t0, 0x90($s0)
    ctx->pc = 0x1239d0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 8));
    // 0x1239d4: 0xae020094  sw          $v0, 0x94($s0)
    ctx->pc = 0x1239d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
label_1239d8:
    // 0x1239d8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1239d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1239dc: 0x54620009  bnel        $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1239DCu;
    {
        const bool branch_taken_0x1239dc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x1239dc) {
            ctx->pc = 0x1239E0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1239DCu;
            // 0x1239e0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x123A04u;
            goto label_123a04;
        }
    }
    ctx->pc = 0x1239E4u;
    // 0x1239e4: 0x8e030080  lw          $v1, 0x80($s0)
    ctx->pc = 0x1239e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x1239e8: 0x8e040084  lw          $a0, 0x84($s0)
    ctx->pc = 0x1239e8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x1239ec: 0x8e050094  lw          $a1, 0x94($s0)
    ctx->pc = 0x1239ecu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x1239f0: 0x60f809  jalr        $v1
    ctx->pc = 0x1239F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1239F8u);
        ctx->pc = 0x1239F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1239F0u;
            // 0x1239f4: 0x8e060090  lw          $a2, 0x90($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1239F8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1234D8u: goto label_1234d8;
            case 0x123540u: goto label_123540;
            case 0x123548u: goto label_123548;
            case 0x1235C0u: goto label_1235c0;
            case 0x123654u: goto label_123654;
            case 0x123668u: goto label_123668;
            case 0x1236D8u: goto label_1236d8;
            case 0x1236DCu: goto label_1236dc;
            case 0x123700u: goto label_123700;
            case 0x123734u: goto label_123734;
            case 0x123754u: goto label_123754;
            case 0x1237B0u: goto label_1237b0;
            case 0x123800u: goto label_123800;
            case 0x123808u: goto label_123808;
            case 0x123838u: goto label_123838;
            case 0x123858u: goto label_123858;
            case 0x123878u: goto label_123878;
            case 0x123884u: goto label_123884;
            case 0x123898u: goto label_123898;
            case 0x1238CCu: goto label_1238cc;
            case 0x1238ECu: goto label_1238ec;
            case 0x123948u: goto label_123948;
            case 0x123988u: goto label_123988;
            case 0x123998u: goto label_123998;
            case 0x1239BCu: goto label_1239bc;
            case 0x1239D8u: goto label_1239d8;
            case 0x1239F8u: goto label_1239f8;
            case 0x123A04u: goto label_123a04;
            case 0x123A38u: goto label_123a38;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1239F8u; }
            if (ctx->pc != 0x1239F8u) { return; }
        }
        }
    }
    ctx->pc = 0x1239F8u;
label_1239f8:
    // 0x1239f8: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1239f8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1239fc: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x1239fcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x123a00: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x123a00u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_123a04:
    // 0x123a04: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x123a04u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x123a08: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x123a08u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x123a0c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x123a0cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x123a10: 0x3e00008  jr          $ra
    ctx->pc = 0x123A10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x123A14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123A10u;
            // 0x123a14: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1234D8u: goto label_1234d8;
            case 0x123540u: goto label_123540;
            case 0x123548u: goto label_123548;
            case 0x1235C0u: goto label_1235c0;
            case 0x123654u: goto label_123654;
            case 0x123668u: goto label_123668;
            case 0x1236D8u: goto label_1236d8;
            case 0x1236DCu: goto label_1236dc;
            case 0x123700u: goto label_123700;
            case 0x123734u: goto label_123734;
            case 0x123754u: goto label_123754;
            case 0x1237B0u: goto label_1237b0;
            case 0x123800u: goto label_123800;
            case 0x123808u: goto label_123808;
            case 0x123838u: goto label_123838;
            case 0x123858u: goto label_123858;
            case 0x123878u: goto label_123878;
            case 0x123884u: goto label_123884;
            case 0x123898u: goto label_123898;
            case 0x1238CCu: goto label_1238cc;
            case 0x1238ECu: goto label_1238ec;
            case 0x123948u: goto label_123948;
            case 0x123988u: goto label_123988;
            case 0x123998u: goto label_123998;
            case 0x1239BCu: goto label_1239bc;
            case 0x1239D8u: goto label_1239d8;
            case 0x1239F8u: goto label_1239f8;
            case 0x123A04u: goto label_123a04;
            case 0x123A38u: goto label_123a38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x123A18u;
    // 0x123a18: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x123a18u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x123a1c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x123a1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x123a20: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x123a20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x123a24: 0x8483009a  lh          $v1, 0x9A($a0)
    ctx->pc = 0x123a24u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 154)));
    // 0x123a28: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x123A28u;
    {
        const bool branch_taken_0x123a28 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x123A2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123A28u;
            // 0x123a2c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123a28) {
            ctx->pc = 0x123A38u;
            goto label_123a38;
        }
    }
    ctx->pc = 0x123A30u;
    // 0x123a30: 0x8048e26  j           func_123898
    ctx->pc = 0x123A30u;
    ctx->pc = 0x123A34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x123A30u;
            // 0x123a34: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x123898u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_123898;
    ctx->pc = 0x123A38u;
label_123a38:
    // 0x123a38: 0x8048dc0  j           func_123700
    ctx->pc = 0x123A38u;
    ctx->pc = 0x123A3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x123A38u;
            // 0x123a3c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x123700u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_123700;
    ctx->pc = 0x123A40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
