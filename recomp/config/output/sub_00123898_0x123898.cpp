#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00123898
// Address: 0x123898 - 0x123a18
void sub_00123898_0x123898(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00123898_0x123898");
#endif

    switch (ctx->pc) {
        case 0x1238ccu: goto label_1238cc;
        case 0x1238ecu: goto label_1238ec;
        case 0x123948u: goto label_123948;
        case 0x123998u: goto label_123998;
        case 0x1239f8u: goto label_1239f8;
        default: break;
    }

    ctx->pc = 0x123898u;

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
            case 0x1238CCu: goto label_1238cc;
            case 0x1238ECu: goto label_1238ec;
            case 0x123948u: goto label_123948;
            case 0x123988u: goto label_123988;
            case 0x123998u: goto label_123998;
            case 0x1239BCu: goto label_1239bc;
            case 0x1239D8u: goto label_1239d8;
            case 0x1239F8u: goto label_1239f8;
            case 0x123A04u: goto label_123a04;
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
            case 0x1238CCu: goto label_1238cc;
            case 0x1238ECu: goto label_1238ec;
            case 0x123948u: goto label_123948;
            case 0x123988u: goto label_123988;
            case 0x123998u: goto label_123998;
            case 0x1239BCu: goto label_1239bc;
            case 0x1239D8u: goto label_1239d8;
            case 0x1239F8u: goto label_1239f8;
            case 0x123A04u: goto label_123a04;
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
            case 0x1238CCu: goto label_1238cc;
            case 0x1238ECu: goto label_1238ec;
            case 0x123948u: goto label_123948;
            case 0x123988u: goto label_123988;
            case 0x123998u: goto label_123998;
            case 0x1239BCu: goto label_1239bc;
            case 0x1239D8u: goto label_1239d8;
            case 0x1239F8u: goto label_1239f8;
            case 0x123A04u: goto label_123a04;
            default: break;
        }
        return;
    }
    ctx->pc = 0x123A18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
