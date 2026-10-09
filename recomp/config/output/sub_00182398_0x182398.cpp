#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00182398
// Address: 0x182398 - 0x182520
void sub_00182398_0x182398(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00182398_0x182398");
#endif

    switch (ctx->pc) {
        case 0x1823c0u: goto label_1823c0;
        case 0x1823d0u: goto label_1823d0;
        case 0x1823e0u: goto label_1823e0;
        case 0x182400u: goto label_182400;
        case 0x182440u: goto label_182440;
        case 0x182444u: goto label_182444;
        case 0x182488u: goto label_182488;
        case 0x182494u: goto label_182494;
        case 0x1824b0u: goto label_1824b0;
        case 0x1824d4u: goto label_1824d4;
        case 0x1824e4u: goto label_1824e4;
        case 0x182500u: goto label_182500;
        default: break;
    }

    ctx->pc = 0x182398u;

label_182398:
    // 0x182398: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x182398u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x18239c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x18239cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1823a0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1823a0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1823a4: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1823a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1823a8: 0x80982d  daddu       $s3, $a0, $zero
    ctx->pc = 0x1823a8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1823ac: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1823acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1823b0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1823b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1823b4: 0x10000044  b           . + 4 + (0x44 << 2)
    ctx->pc = 0x1823B4u;
    {
        const bool branch_taken_0x1823b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1823B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1823B4u;
            // 0x1823b8: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1823b4) {
            ctx->pc = 0x1824C8u;
            goto label_1824c8;
        }
    }
    ctx->pc = 0x1823BCu;
    // 0x1823bc: 0x0  nop
    ctx->pc = 0x1823bcu;
    // NOP
label_1823c0:
    // 0x1823c0: 0x4600003  bltz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1823C0u;
    {
        const bool branch_taken_0x1823c0 = (GPR_S64(ctx, 3) < 0);
        ctx->pc = 0x1823C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1823C0u;
            // 0x1823c4: 0x240802d  daddu       $s0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1823c0) {
            ctx->pc = 0x1823D0u;
            goto label_1823d0;
        }
    }
    ctx->pc = 0x1823C8u;
    // 0x1823c8: 0x243102a  slt         $v0, $s2, $v1
    ctx->pc = 0x1823c8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 18) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1823cc: 0x62800a  movz        $s0, $v1, $v0
    ctx->pc = 0x1823ccu;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 16, GPR_VEC(ctx, 3));
label_1823d0:
    // 0x1823d0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1823d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1823d4: 0x260282d  daddu       $a1, $s3, $zero
    ctx->pc = 0x1823d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1823d8: 0xc042d10  jal         func_10B440
    ctx->pc = 0x1823D8u;
    SET_GPR_U32(ctx, 31, 0x1823E0u);
    ctx->pc = 0x1823DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1823D8u;
            // 0x1823dc: 0x200302d  daddu       $a2, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1823E0u; }
        if (ctx->pc != 0x1823E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1823E0u; }
        if (ctx->pc != 0x1823E0u) { return; }
    }
    ctx->pc = 0x1823E0u;
label_1823e0:
    // 0x1823e0: 0x14400037  bnez        $v0, . + 4 + (0x37 << 2)
    ctx->pc = 0x1823E0u;
    {
        const bool branch_taken_0x1823e0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1823E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1823E0u;
            // 0x1823e4: 0x2308821  addu        $s1, $s1, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1823e0) {
            ctx->pc = 0x1824C0u;
            goto label_1824c0;
        }
    }
    ctx->pc = 0x1823E8u;
    // 0x1823e8: 0x2403003f  addiu       $v1, $zero, 0x3F
    ctx->pc = 0x1823e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
    // 0x1823ec: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x1823ecu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1823f0: 0x2709821  addu        $s3, $s3, $s0
    ctx->pc = 0x1823f0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 16)));
    // 0x1823f4: 0x1443000b  bne         $v0, $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x1823F4u;
    {
        const bool branch_taken_0x1823f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1823F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1823F4u;
            // 0x1823f8: 0x92250000  lbu         $a1, 0x0($s1) (Delay Slot)
        SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1823f4) {
            ctx->pc = 0x182424u;
            goto label_182424;
        }
    }
    ctx->pc = 0x1823FCu;
    // 0x1823fc: 0x2404003f  addiu       $a0, $zero, 0x3F
    ctx->pc = 0x1823fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
label_182400:
    // 0x182400: 0x82630000  lb          $v1, 0x0($s3)
    ctx->pc = 0x182400u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x182404: 0x26730001  addiu       $s3, $s3, 0x1
    ctx->pc = 0x182404u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
    // 0x182408: 0x1060003e  beqz        $v1, . + 4 + (0x3E << 2)
    ctx->pc = 0x182408u;
    {
        const bool branch_taken_0x182408 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x18240Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182408u;
            // 0x18240c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182408) {
            ctx->pc = 0x182504u;
            goto label_182504;
        }
    }
    ctx->pc = 0x182410u;
    // 0x182410: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x182410u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x182414: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x182414u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x182418: 0x0  nop
    ctx->pc = 0x182418u;
    // NOP
    // 0x18241c: 0x1044fff8  beq         $v0, $a0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x18241Cu;
    {
        const bool branch_taken_0x18241c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x182420u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18241Cu;
            // 0x182420: 0x92250000  lbu         $a1, 0x0($s1) (Delay Slot)
        SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18241c) {
            ctx->pc = 0x182400u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_182400;
        }
    }
    ctx->pc = 0x182424u;
label_182424:
    // 0x182424: 0x51600  sll         $v0, $a1, 24
    ctx->pc = 0x182424u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x182428: 0x2403002a  addiu       $v1, $zero, 0x2A
    ctx->pc = 0x182428u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 42));
    // 0x18242c: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x18242cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x182430: 0x54430026  bnel        $v0, $v1, . + 4 + (0x26 << 2)
    ctx->pc = 0x182430u;
    {
        const bool branch_taken_0x182430 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        if (branch_taken_0x182430) {
            ctx->pc = 0x182434u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x182430u;
            // 0x182434: 0x2405003f  addiu       $a1, $zero, 0x3F (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1824CCu;
            goto label_1824cc;
        }
    }
    ctx->pc = 0x182438u;
    // 0x182438: 0x2402002a  addiu       $v0, $zero, 0x2A
    ctx->pc = 0x182438u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 42));
    // 0x18243c: 0x2404003f  addiu       $a0, $zero, 0x3F
    ctx->pc = 0x18243cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
label_182440:
    // 0x182440: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x182440u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
label_182444:
    // 0x182444: 0x82230000  lb          $v1, 0x0($s1)
    ctx->pc = 0x182444u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x182448: 0x0  nop
    ctx->pc = 0x182448u;
    // NOP
    // 0x18244c: 0x0  nop
    ctx->pc = 0x18244cu;
    // NOP
    // 0x182450: 0x0  nop
    ctx->pc = 0x182450u;
    // NOP
    // 0x182454: 0x1062fffa  beq         $v1, $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x182454u;
    {
        const bool branch_taken_0x182454 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x182458u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182454u;
            // 0x182458: 0x92250000  lbu         $a1, 0x0($s1) (Delay Slot)
        SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182454) {
            ctx->pc = 0x182440u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_182440;
        }
    }
    ctx->pc = 0x18245Cu;
    // 0x18245c: 0x0  nop
    ctx->pc = 0x18245cu;
    // NOP
    // 0x182460: 0x0  nop
    ctx->pc = 0x182460u;
    // NOP
    // 0x182464: 0x0  nop
    ctx->pc = 0x182464u;
    // NOP
    // 0x182468: 0x0  nop
    ctx->pc = 0x182468u;
    // NOP
    // 0x18246c: 0x5064fff5  beql        $v1, $a0, . + 4 + (-0xB << 2)
    ctx->pc = 0x18246Cu;
    {
        const bool branch_taken_0x18246c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x18246c) {
            ctx->pc = 0x182470u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x18246Cu;
            // 0x182470: 0x26310001  addiu       $s1, $s1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
            ctx->pc = 0x182444u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_182444;
        }
    }
    ctx->pc = 0x182474u;
    // 0x182474: 0x10600023  beqz        $v1, . + 4 + (0x23 << 2)
    ctx->pc = 0x182474u;
    {
        const bool branch_taken_0x182474 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x182478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182474u;
            // 0x182478: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182474) {
            ctx->pc = 0x182504u;
            goto label_182504;
        }
    }
    ctx->pc = 0x18247Cu;
    // 0x18247c: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x18247Cu;
    {
        const bool branch_taken_0x18247c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x182480u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18247Cu;
            // 0x182480: 0x24120001  addiu       $s2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18247c) {
            ctx->pc = 0x1824A0u;
            goto label_1824a0;
        }
    }
    ctx->pc = 0x182484u;
    // 0x182484: 0x0  nop
    ctx->pc = 0x182484u;
    // NOP
label_182488:
    // 0x182488: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x182488u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18248c: 0xc0608e6  jal         func_182398
    ctx->pc = 0x18248Cu;
    SET_GPR_U32(ctx, 31, 0x182494u);
    ctx->pc = 0x182490u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18248Cu;
            // 0x182490: 0x26730001  addiu       $s3, $s3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182398u;
    goto label_182398;
    ctx->pc = 0x182494u;
label_182494:
    // 0x182494: 0x1052001c  beq         $v0, $s2, . + 4 + (0x1C << 2)
    ctx->pc = 0x182494u;
    {
        const bool branch_taken_0x182494 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 18));
        ctx->pc = 0x182498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182494u;
            // 0x182498: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x182494) {
            ctx->pc = 0x182508u;
            goto label_182508;
        }
    }
    ctx->pc = 0x18249Cu;
    // 0x18249c: 0x92250000  lbu         $a1, 0x0($s1)
    ctx->pc = 0x18249cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
label_1824a0:
    // 0x1824a0: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x1824a0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x1824a4: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1824a4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1824a8: 0xc060866  jal         func_182198
    ctx->pc = 0x1824A8u;
    SET_GPR_U32(ctx, 31, 0x1824B0u);
    ctx->pc = 0x1824ACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1824A8u;
            // 0x1824ac: 0x52e03  sra         $a1, $a1, 24 (Delay Slot)
        SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 24));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182198u;
    if (runtime->hasFunction(0x182198u)) {
        auto targetFn = runtime->lookupFunction(0x182198u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1824B0u; }
        if (ctx->pc != 0x1824B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182198_0x182198(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1824B0u; }
        if (ctx->pc != 0x1824B0u) { return; }
    }
    ctx->pc = 0x1824B0u;
label_1824b0:
    // 0x1824b0: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x1824b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1824b4: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1824b4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1824b8: 0x601fff3  bgez        $s0, . + 4 + (-0xD << 2)
    ctx->pc = 0x1824B8u;
    {
        const bool branch_taken_0x1824b8 = (GPR_S64(ctx, 16) >= 0);
        ctx->pc = 0x1824BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1824B8u;
            // 0x1824bc: 0x2709821  addu        $s3, $s3, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1824b8) {
            ctx->pc = 0x182488u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_182488;
        }
    }
    ctx->pc = 0x1824C0u;
label_1824c0:
    // 0x1824c0: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1824C0u;
    {
        const bool branch_taken_0x1824c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1824C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1824C0u;
            // 0x1824c4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1824c0) {
            ctx->pc = 0x182504u;
            goto label_182504;
        }
    }
    ctx->pc = 0x1824C8u;
label_1824c8:
    // 0x1824c8: 0x2405003f  addiu       $a1, $zero, 0x3F
    ctx->pc = 0x1824c8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 63));
label_1824cc:
    // 0x1824cc: 0xc060866  jal         func_182198
    ctx->pc = 0x1824CCu;
    SET_GPR_U32(ctx, 31, 0x1824D4u);
    ctx->pc = 0x1824D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1824CCu;
            // 0x1824d0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182198u;
    if (runtime->hasFunction(0x182198u)) {
        auto targetFn = runtime->lookupFunction(0x182198u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1824D4u; }
        if (ctx->pc != 0x1824D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182198_0x182198(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1824D4u; }
        if (ctx->pc != 0x1824D4u) { return; }
    }
    ctx->pc = 0x1824D4u;
label_1824d4:
    // 0x1824d4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1824d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1824d8: 0x2405002a  addiu       $a1, $zero, 0x2A
    ctx->pc = 0x1824d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 42));
    // 0x1824dc: 0xc060866  jal         func_182198
    ctx->pc = 0x1824DCu;
    SET_GPR_U32(ctx, 31, 0x1824E4u);
    ctx->pc = 0x1824E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1824DCu;
            // 0x1824e0: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x182198u;
    if (runtime->hasFunction(0x182198u)) {
        auto targetFn = runtime->lookupFunction(0x182198u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1824E4u; }
        if (ctx->pc != 0x1824E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00182198_0x182198(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1824E4u; }
        if (ctx->pc != 0x1824E4u) { return; }
    }
    ctx->pc = 0x1824E4u;
label_1824e4:
    // 0x1824e4: 0x641ffb6  bgez        $s2, . + 4 + (-0x4A << 2)
    ctx->pc = 0x1824E4u;
    {
        const bool branch_taken_0x1824e4 = (GPR_S64(ctx, 18) >= 0);
        ctx->pc = 0x1824E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1824E4u;
            // 0x1824e8: 0x40182d  daddu       $v1, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1824e4) {
            ctx->pc = 0x1823C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1823c0;
        }
    }
    ctx->pc = 0x1824ECu;
    // 0x1824ec: 0x461ffb8  bgez        $v1, . + 4 + (-0x48 << 2)
    ctx->pc = 0x1824ECu;
    {
        const bool branch_taken_0x1824ec = (GPR_S64(ctx, 3) >= 0);
        ctx->pc = 0x1824F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1824ECu;
            // 0x1824f0: 0x60802d  daddu       $s0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1824ec) {
            ctx->pc = 0x1823D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1823d0;
        }
    }
    ctx->pc = 0x1824F4u;
    // 0x1824f4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1824f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1824f8: 0xc042b9e  jal         func_10AE78
    ctx->pc = 0x1824F8u;
    SET_GPR_U32(ctx, 31, 0x182500u);
    ctx->pc = 0x1824FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1824F8u;
            // 0x1824fc: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10AE78u;
    if (runtime->hasFunction(0x10AE78u)) {
        auto targetFn = runtime->lookupFunction(0x10AE78u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182500u; }
        if (ctx->pc != 0x182500u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AE78_0x10ae78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x182500u; }
        if (ctx->pc != 0x182500u) { return; }
    }
    ctx->pc = 0x182500u;
label_182500:
    // 0x182500: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x182500u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_182504:
    // 0x182504: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x182504u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_182508:
    // 0x182508: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x182508u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x18250c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x18250cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x182510: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x182510u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x182514: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x182514u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x182518: 0x3e00008  jr          $ra
    ctx->pc = 0x182518u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18251Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x182518u;
            // 0x18251c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x182398u: goto label_182398;
            case 0x1823C0u: goto label_1823c0;
            case 0x1823D0u: goto label_1823d0;
            case 0x1823E0u: goto label_1823e0;
            case 0x182400u: goto label_182400;
            case 0x182424u: goto label_182424;
            case 0x182440u: goto label_182440;
            case 0x182444u: goto label_182444;
            case 0x182488u: goto label_182488;
            case 0x182494u: goto label_182494;
            case 0x1824A0u: goto label_1824a0;
            case 0x1824B0u: goto label_1824b0;
            case 0x1824C0u: goto label_1824c0;
            case 0x1824C8u: goto label_1824c8;
            case 0x1824CCu: goto label_1824cc;
            case 0x1824D4u: goto label_1824d4;
            case 0x1824E4u: goto label_1824e4;
            case 0x182500u: goto label_182500;
            case 0x182504u: goto label_182504;
            case 0x182508u: goto label_182508;
            default: break;
        }
        return;
    }
    ctx->pc = 0x182520u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
