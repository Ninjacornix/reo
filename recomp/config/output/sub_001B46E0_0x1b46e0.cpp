#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B46E0
// Address: 0x1b46e0 - 0x1b4820
void sub_001B46E0_0x1b46e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B46E0_0x1b46e0");
#endif

    switch (ctx->pc) {
        case 0x1b4734u: goto label_1b4734;
        case 0x1b4750u: goto label_1b4750;
        case 0x1b476cu: goto label_1b476c;
        case 0x1b47c4u: goto label_1b47c4;
        default: break;
    }

    ctx->pc = 0x1b46e0u;

    // 0x1b46e0: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x1b46e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x1b46e4: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x1b46e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x1b46e8: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x1b46e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x1b46ec: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1b46ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1b46f0: 0xe0b82d  daddu       $s7, $a3, $zero
    ctx->pc = 0x1b46f0u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b46f4: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1b46f4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1b46f8: 0x3c160031  lui         $s6, 0x31
    ctx->pc = 0x1b46f8u;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)49 << 16));
    // 0x1b46fc: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1b46fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1b4700: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x1b4700u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4704: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1b4704u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1b4708: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x1b4708u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b470c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1b470cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1b4710: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x1b4710u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4714: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1b4714u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1b4718: 0x100902d  daddu       $s2, $t0, $zero
    ctx->pc = 0x1b4718u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b471c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b471cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b4720: 0x120882d  daddu       $s1, $t1, $zero
    ctx->pc = 0x1b4720u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4724: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x1b4724u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4728: 0x140802d  daddu       $s0, $t2, $zero
    ctx->pc = 0x1b4728u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b472c: 0xc06d164  jal         func_1B4590
    ctx->pc = 0x1B472Cu;
    SET_GPR_U32(ctx, 31, 0x1B4734u);
    ctx->pc = 0x1B4730u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B472Cu;
            // 0x1b4730: 0x26d651c0  addiu       $s6, $s6, 0x51C0 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 20928));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B4590u;
    if (runtime->hasFunction(0x1B4590u)) {
        auto targetFn = runtime->lookupFunction(0x1B4590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4734u; }
        if (ctx->pc != 0x1B4734u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B4590_0x1b4590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4734u; }
        if (ctx->pc != 0x1B4734u) { return; }
    }
    ctx->pc = 0x1B4734u;
label_1b4734:
    // 0x1b4734: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B4734u;
    {
        const bool branch_taken_0x1b4734 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B4738u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4734u;
            // 0x1b4738: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4734) {
            ctx->pc = 0x1B4744u;
            goto label_1b4744;
        }
    }
    ctx->pc = 0x1B473Cu;
    // 0x1b473c: 0x1000002c  b           . + 4 + (0x2C << 2)
    ctx->pc = 0x1B473Cu;
    {
        const bool branch_taken_0x1b473c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B4740u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B473Cu;
            // 0x1b4740: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b473c) {
            ctx->pc = 0x1B47F0u;
            goto label_1b47f0;
        }
    }
    ctx->pc = 0x1B4744u;
label_1b4744:
    // 0x1b4744: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1b4744u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b4748: 0xc06d194  jal         func_1B4650
    ctx->pc = 0x1B4748u;
    SET_GPR_U32(ctx, 31, 0x1B4750u);
    ctx->pc = 0x1B474Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4748u;
            // 0x1b474c: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B4650u;
    if (runtime->hasFunction(0x1B4650u)) {
        auto targetFn = runtime->lookupFunction(0x1B4650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4750u; }
        if (ctx->pc != 0x1B4750u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B4650_0x1b4650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B4750u; }
        if (ctx->pc != 0x1B4750u) { return; }
    }
    ctx->pc = 0x1B4750u;
label_1b4750:
    // 0x1b4750: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B4750u;
    {
        const bool branch_taken_0x1b4750 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b4750) {
            ctx->pc = 0x1B4760u;
            goto label_1b4760;
        }
    }
    ctx->pc = 0x1B4758u;
    // 0x1b4758: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1B4758u;
    {
        const bool branch_taken_0x1b4758 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B475Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4758u;
            // 0x1b475c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4758) {
            ctx->pc = 0x1B47F0u;
            goto label_1b47f0;
        }
    }
    ctx->pc = 0x1B4760u;
label_1b4760:
    // 0x1b4760: 0x26d60010  addiu       $s6, $s6, 0x10
    ctx->pc = 0x1b4760u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 16));
    // 0x1b4764: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1B4764u;
    {
        const bool branch_taken_0x1b4764 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B4768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4764u;
            // 0x1b4768: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4764) {
            ctx->pc = 0x1B4780u;
            goto label_1b4780;
        }
    }
    ctx->pc = 0x1B476Cu;
label_1b476c:
    // 0x1b476c: 0x86c20000  lh          $v0, 0x0($s6)
    ctx->pc = 0x1b476cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x1b4770: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B4770u;
    {
        const bool branch_taken_0x1b4770 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B4774u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4770u;
            // 0x1b4774: 0x24020020  addiu       $v0, $zero, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4770) {
            ctx->pc = 0x1B4790u;
            goto label_1b4790;
        }
    }
    ctx->pc = 0x1B4778u;
    // 0x1b4778: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1b4778u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1b477c: 0x26d6008c  addiu       $s6, $s6, 0x8C
    ctx->pc = 0x1b477cu;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 140));
label_1b4780:
    // 0x1b4780: 0x28620020  slti        $v0, $v1, 0x20
    ctx->pc = 0x1b4780u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)32) ? 1 : 0);
    // 0x1b4784: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1B4784u;
    {
        const bool branch_taken_0x1b4784 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1b4784) {
            ctx->pc = 0x1B476Cu;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1b476c;
        }
    }
    ctx->pc = 0x1B478Cu;
    // 0x1b478c: 0x24020020  addiu       $v0, $zero, 0x20
    ctx->pc = 0x1b478cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
label_1b4790:
    // 0x1b4790: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B4790u;
    {
        const bool branch_taken_0x1b4790 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1B4794u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4790u;
            // 0x1b4794: 0x24040001  addiu       $a0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4790) {
            ctx->pc = 0x1B47A0u;
            goto label_1b47a0;
        }
    }
    ctx->pc = 0x1B4798u;
    // 0x1b4798: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1B4798u;
    {
        const bool branch_taken_0x1b4798 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B479Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4798u;
            // 0x1b479c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b4798) {
            ctx->pc = 0x1B47F0u;
            goto label_1b47f0;
        }
    }
    ctx->pc = 0x1B47A0u;
label_1b47a0:
    // 0x1b47a0: 0x3283fffe  andi        $v1, $s4, 0xFFFE
    ctx->pc = 0x1b47a0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 20) & (uint64_t)(uint16_t)65534);
    // 0x1b47a4: 0xa6c40000  sh          $a0, 0x0($s6)
    ctx->pc = 0x1b47a4u;
    WRITE16(ADD32(GPR_U32(ctx, 22), 0), (uint16_t)GPR_U32(ctx, 4));
    // 0x1b47a8: 0x3262fffe  andi        $v0, $s3, 0xFFFE
    ctx->pc = 0x1b47a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 19) & (uint64_t)(uint16_t)65534);
    // 0x1b47ac: 0xa2d5000b  sb          $s5, 0xB($s6)
    ctx->pc = 0x1b47acu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 11), (uint8_t)GPR_U32(ctx, 21));
    // 0x1b47b0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1b47b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b47b4: 0xa6c30002  sh          $v1, 0x2($s6)
    ctx->pc = 0x1b47b4u;
    WRITE16(ADD32(GPR_U32(ctx, 22), 2), (uint16_t)GPR_U32(ctx, 3));
    // 0x1b47b8: 0x26c4000c  addiu       $a0, $s6, 0xC
    ctx->pc = 0x1b47b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 22), 12));
    // 0x1b47bc: 0xc042bf0  jal         func_10AFC0
    ctx->pc = 0x1B47BCu;
    SET_GPR_U32(ctx, 31, 0x1B47C4u);
    ctx->pc = 0x1B47C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B47BCu;
            // 0x1b47c0: 0xa6c20004  sh          $v0, 0x4($s6) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 22), 4), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AFC0u;
    if (runtime->hasFunction(0x10AFC0u)) {
        auto targetFn = runtime->lookupFunction(0x10AFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B47C4u; }
        if (ctx->pc != 0x1B47C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B47C4u; }
        if (ctx->pc != 0x1B47C4u) { return; }
    }
    ctx->pc = 0x1B47C4u;
label_1b47c4:
    // 0x1b47c4: 0xa6d70006  sh          $s7, 0x6($s6)
    ctx->pc = 0x1b47c4u;
    WRITE16(ADD32(GPR_U32(ctx, 22), 6), (uint16_t)GPR_U32(ctx, 23));
    // 0x1b47c8: 0x16000004  bnez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B47C8u;
    {
        const bool branch_taken_0x1b47c8 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B47CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B47C8u;
            // 0x1b47cc: 0xa2d20008  sb          $s2, 0x8($s6) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 22), 8), (uint8_t)GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b47c8) {
            ctx->pc = 0x1B47DCu;
            goto label_1b47dc;
        }
    }
    ctx->pc = 0x1B47D0u;
    // 0x1b47d0: 0x24020080  addiu       $v0, $zero, 0x80
    ctx->pc = 0x1b47d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 128));
    // 0x1b47d4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1B47D4u;
    {
        const bool branch_taken_0x1b47d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B47D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B47D4u;
            // 0x1b47d8: 0xa2c2000a  sb          $v0, 0xA($s6) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 22), 10), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b47d4) {
            ctx->pc = 0x1B47E0u;
            goto label_1b47e0;
        }
    }
    ctx->pc = 0x1B47DCu;
label_1b47dc:
    // 0x1b47dc: 0xa2c0000a  sb          $zero, 0xA($s6)
    ctx->pc = 0x1b47dcu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 10), (uint8_t)GPR_U32(ctx, 0));
label_1b47e0:
    // 0x1b47e0: 0x101c3c  dsll32      $v1, $s0, 16
    ctx->pc = 0x1b47e0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) << (32 + 16));
    // 0x1b47e4: 0x26c2000a  addiu       $v0, $s6, 0xA
    ctx->pc = 0x1b47e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 22), 10));
    // 0x1b47e8: 0x31c3f  dsra32      $v1, $v1, 16
    ctx->pc = 0x1b47e8u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x1b47ec: 0xa2c30009  sb          $v1, 0x9($s6)
    ctx->pc = 0x1b47ecu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 9), (uint8_t)GPR_U32(ctx, 3));
label_1b47f0:
    // 0x1b47f0: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x1b47f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1b47f4: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x1b47f4u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1b47f8: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1b47f8u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1b47fc: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1b47fcu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1b4800: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1b4800u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1b4804: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1b4804u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b4808: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1b4808u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b480c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1b480cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b4810: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b4810u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b4814: 0x3e00008  jr          $ra
    ctx->pc = 0x1B4814u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B4818u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B4814u;
            // 0x1b4818: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B4734u: goto label_1b4734;
            case 0x1B4744u: goto label_1b4744;
            case 0x1B4750u: goto label_1b4750;
            case 0x1B4760u: goto label_1b4760;
            case 0x1B476Cu: goto label_1b476c;
            case 0x1B4780u: goto label_1b4780;
            case 0x1B4790u: goto label_1b4790;
            case 0x1B47A0u: goto label_1b47a0;
            case 0x1B47C4u: goto label_1b47c4;
            case 0x1B47DCu: goto label_1b47dc;
            case 0x1B47E0u: goto label_1b47e0;
            case 0x1B47F0u: goto label_1b47f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B481Cu;
    // 0x1b481c: 0x0  nop
    ctx->pc = 0x1b481cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
