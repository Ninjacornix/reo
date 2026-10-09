#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00108590
// Address: 0x108590 - 0x1086e8
void sub_00108590_0x108590(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00108590_0x108590");
#endif

    switch (ctx->pc) {
        case 0x1085e0u: goto label_1085e0;
        case 0x108604u: goto label_108604;
        case 0x108618u: goto label_108618;
        case 0x108658u: goto label_108658;
        case 0x108690u: goto label_108690;
        case 0x1086c0u: goto label_1086c0;
        default: break;
    }

    ctx->pc = 0x108590u;

    // 0x108590: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x108590u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x108594: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x108594u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x108598: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x108598u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10859c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x10859cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1085a0: 0x108943  sra         $s1, $s0, 5
    ctx->pc = 0x1085a0u;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 16), 5));
    // 0x1085a4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1085a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1085a8: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1085a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1085ac: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1085acu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1085b0: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x1085b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x1085b4: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x1085b4u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1085b8: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x1085b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x1085bc: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1085bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1085c0: 0x8e630010  lw          $v1, 0x10($s3)
    ctx->pc = 0x1085c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x1085c4: 0x8e660008  lw          $a2, 0x8($s3)
    ctx->pc = 0x1085c4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x1085c8: 0x2231821  addu        $v1, $s1, $v1
    ctx->pc = 0x1085c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x1085cc: 0x24720001  addiu       $s2, $v1, 0x1
    ctx->pc = 0x1085ccu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1085d0: 0xd2102a  slt         $v0, $a2, $s2
    ctx->pc = 0x1085d0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x1085d4: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1085D4u;
    {
        const bool branch_taken_0x1085d4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1085D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1085D4u;
            // 0x1085d8: 0x8e650004  lw          $a1, 0x4($s3) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1085d4) {
            ctx->pc = 0x1085FCu;
            goto label_1085fc;
        }
    }
    ctx->pc = 0x1085DCu;
    // 0x1085dc: 0x0  nop
    ctx->pc = 0x1085dcu;
    // NOP
label_1085e0:
    // 0x1085e0: 0x63040  sll         $a2, $a2, 1
    ctx->pc = 0x1085e0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
    // 0x1085e4: 0xd2102a  slt         $v0, $a2, $s2
    ctx->pc = 0x1085e4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 18)) ? 1 : 0);
    // 0x1085e8: 0x0  nop
    ctx->pc = 0x1085e8u;
    // NOP
    // 0x1085ec: 0x0  nop
    ctx->pc = 0x1085ecu;
    // NOP
    // 0x1085f0: 0x0  nop
    ctx->pc = 0x1085f0u;
    // NOP
    // 0x1085f4: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1085F4u;
    {
        const bool branch_taken_0x1085f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1085F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1085F4u;
            // 0x1085f8: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1085f4) {
            ctx->pc = 0x1085E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1085e0;
        }
    }
    ctx->pc = 0x1085FCu;
label_1085fc:
    // 0x1085fc: 0xc041f7e  jal         func_107DF8
    ctx->pc = 0x1085FCu;
    SET_GPR_U32(ctx, 31, 0x108604u);
    ctx->pc = 0x108600u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1085FCu;
            // 0x108600: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107DF8u;
    if (runtime->hasFunction(0x107DF8u)) {
        auto targetFn = runtime->lookupFunction(0x107DF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108604u; }
        if (ctx->pc != 0x108604u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DF8_0x107df8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x108604u; }
        if (ctx->pc != 0x108604u) { return; }
    }
    ctx->pc = 0x108604u;
label_108604:
    // 0x108604: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x108604u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108608: 0x1a20000a  blez        $s1, . + 4 + (0xA << 2)
    ctx->pc = 0x108608u;
    {
        const bool branch_taken_0x108608 = (GPR_S64(ctx, 17) <= 0);
        ctx->pc = 0x10860Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108608u;
            // 0x10860c: 0x26870014  addiu       $a3, $s4, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 20), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108608) {
            ctx->pc = 0x108634u;
            goto label_108634;
        }
    }
    ctx->pc = 0x108610u;
    // 0x108610: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x108610u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108614: 0x0  nop
    ctx->pc = 0x108614u;
    // NOP
label_108618:
    // 0x108618: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x108618u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x10861c: 0xace00000  sw          $zero, 0x0($a3)
    ctx->pc = 0x10861cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 0));
    // 0x108620: 0x0  nop
    ctx->pc = 0x108620u;
    // NOP
    // 0x108624: 0x0  nop
    ctx->pc = 0x108624u;
    // NOP
    // 0x108628: 0x0  nop
    ctx->pc = 0x108628u;
    // NOP
    // 0x10862c: 0x14c0fffa  bnez        $a2, . + 4 + (-0x6 << 2)
    ctx->pc = 0x10862Cu;
    {
        const bool branch_taken_0x10862c = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x108630u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10862Cu;
            // 0x108630: 0x24e70004  addiu       $a3, $a3, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10862c) {
            ctx->pc = 0x108618u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_108618;
        }
    }
    ctx->pc = 0x108634u;
label_108634:
    // 0x108634: 0x8e620010  lw          $v0, 0x10($s3)
    ctx->pc = 0x108634u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 16)));
    // 0x108638: 0x26640014  addiu       $a0, $s3, 0x14
    ctx->pc = 0x108638u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 20));
    // 0x10863c: 0x3210001f  andi        $s0, $s0, 0x1F
    ctx->pc = 0x10863cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) & (uint64_t)(uint16_t)31);
    // 0x108640: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x108640u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x108644: 0x12000012  beqz        $s0, . + 4 + (0x12 << 2)
    ctx->pc = 0x108644u;
    {
        const bool branch_taken_0x108644 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x108648u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108644u;
            // 0x108648: 0x823021  addu        $a2, $a0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108644) {
            ctx->pc = 0x108690u;
            goto label_108690;
        }
    }
    ctx->pc = 0x10864Cu;
    // 0x10864c: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x10864cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x108650: 0x182d  daddu       $v1, $zero, $zero
    ctx->pc = 0x108650u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x108654: 0x502823  subu        $a1, $v0, $s0
    ctx->pc = 0x108654u;
    SET_GPR_S32(ctx, 5, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
label_108658:
    // 0x108658: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x108658u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10865c: 0x2021004  sllv        $v0, $v0, $s0
    ctx->pc = 0x10865cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), GPR_U32(ctx, 16) & 0x1F));
    // 0x108660: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x108660u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x108664: 0xace20000  sw          $v0, 0x0($a3)
    ctx->pc = 0x108664u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
    // 0x108668: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x108668u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x10866c: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x10866cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x108670: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x108670u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x108674: 0x86102b  sltu        $v0, $a0, $a2
    ctx->pc = 0x108674u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x108678: 0x1440fff7  bnez        $v0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x108678u;
    {
        const bool branch_taken_0x108678 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10867Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108678u;
            // 0x10867c: 0xa31806  srlv        $v1, $v1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), GPR_U32(ctx, 5) & 0x1F));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108678) {
            ctx->pc = 0x108658u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_108658;
        }
    }
    ctx->pc = 0x108680u;
    // 0x108680: 0x1060000a  beqz        $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x108680u;
    {
        const bool branch_taken_0x108680 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x108684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108680u;
            // 0x108684: 0xace30000  sw          $v1, 0x0($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108680) {
            ctx->pc = 0x1086ACu;
            goto label_1086ac;
        }
    }
    ctx->pc = 0x108688u;
    // 0x108688: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x108688u;
    {
        const bool branch_taken_0x108688 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10868Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x108688u;
            // 0x10868c: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x108688) {
            ctx->pc = 0x1086ACu;
            goto label_1086ac;
        }
    }
    ctx->pc = 0x108690u;
label_108690:
    // 0x108690: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x108690u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x108694: 0x24840004  addiu       $a0, $a0, 0x4
    ctx->pc = 0x108694u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4));
    // 0x108698: 0x86182b  sltu        $v1, $a0, $a2
    ctx->pc = 0x108698u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x10869c: 0xace20000  sw          $v0, 0x0($a3)
    ctx->pc = 0x10869cu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
    // 0x1086a0: 0x0  nop
    ctx->pc = 0x1086a0u;
    // NOP
    // 0x1086a4: 0x1460fffa  bnez        $v1, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1086A4u;
    {
        const bool branch_taken_0x1086a4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1086A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1086A4u;
            // 0x1086a8: 0x24e70004  addiu       $a3, $a3, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1086a4) {
            ctx->pc = 0x108690u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_108690;
        }
    }
    ctx->pc = 0x1086ACu;
label_1086ac:
    // 0x1086ac: 0x2642ffff  addiu       $v0, $s2, -0x1
    ctx->pc = 0x1086acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
    // 0x1086b0: 0x2a0202d  daddu       $a0, $s5, $zero
    ctx->pc = 0x1086b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1086b4: 0xae820010  sw          $v0, 0x10($s4)
    ctx->pc = 0x1086b4u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 16), GPR_U32(ctx, 2));
    // 0x1086b8: 0xc041fa8  jal         func_107EA0
    ctx->pc = 0x1086B8u;
    SET_GPR_U32(ctx, 31, 0x1086C0u);
    ctx->pc = 0x1086BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1086B8u;
            // 0x1086bc: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107EA0u;
    if (runtime->hasFunction(0x107EA0u)) {
        auto targetFn = runtime->lookupFunction(0x107EA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1086C0u; }
        if (ctx->pc != 0x1086C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107EA0_0x107ea0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1086C0u; }
        if (ctx->pc != 0x1086C0u) { return; }
    }
    ctx->pc = 0x1086C0u;
label_1086c0:
    // 0x1086c0: 0x280102d  daddu       $v0, $s4, $zero
    ctx->pc = 0x1086c0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1086c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1086c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1086c8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1086c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1086cc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1086ccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1086d0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1086d0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1086d4: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1086d4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1086d8: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x1086d8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1086dc: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1086dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1086e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1086E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1086E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1086E0u;
            // 0x1086e4: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1085E0u: goto label_1085e0;
            case 0x1085FCu: goto label_1085fc;
            case 0x108604u: goto label_108604;
            case 0x108618u: goto label_108618;
            case 0x108634u: goto label_108634;
            case 0x108658u: goto label_108658;
            case 0x108690u: goto label_108690;
            case 0x1086ACu: goto label_1086ac;
            case 0x1086C0u: goto label_1086c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1086E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
