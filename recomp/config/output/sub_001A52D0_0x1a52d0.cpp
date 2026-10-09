#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A52D0
// Address: 0x1a52d0 - 0x1a5570
void sub_001A52D0_0x1a52d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A52D0_0x1a52d0");
#endif

    switch (ctx->pc) {
        case 0x1a52f4u: goto label_1a52f4;
        case 0x1a530cu: goto label_1a530c;
        case 0x1a5364u: goto label_1a5364;
        default: break;
    }

    ctx->pc = 0x1a52d0u;

    // 0x1a52d0: 0x27bdffc0  addiu       $sp, $sp, -0x40
    ctx->pc = 0x1a52d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1a52d4: 0xffbf0030  sd          $ra, 0x30($sp)
    ctx->pc = 0x1a52d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1a52d8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1a52d8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1a52dc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1a52dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1a52e0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1a52e0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1a52e4: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1a52e4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a52e8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1a52e8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a52ec: 0xc0695ec  jal         func_1A57B0
    ctx->pc = 0x1A52ECu;
    SET_GPR_U32(ctx, 31, 0x1A52F4u);
    ctx->pc = 0x1A52F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A52ECu;
            // 0x1a52f0: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A57B0u;
    if (runtime->hasFunction(0x1A57B0u)) {
        auto targetFn = runtime->lookupFunction(0x1A57B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A52F4u; }
        if (ctx->pc != 0x1A52F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A57B0_0x1a57b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A52F4u; }
        if (ctx->pc != 0x1A52F4u) { return; }
    }
    ctx->pc = 0x1A52F4u;
label_1a52f4:
    // 0x1a52f4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A52F4u;
    {
        const bool branch_taken_0x1a52f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1A52F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A52F4u;
            // 0x1a52f8: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a52f4) {
            ctx->pc = 0x1A5304u;
            goto label_1a5304;
        }
    }
    ctx->pc = 0x1A52FCu;
    // 0x1a52fc: 0x10000096  b           . + 4 + (0x96 << 2)
    ctx->pc = 0x1A52FCu;
    {
        const bool branch_taken_0x1a52fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A52FCu;
            // 0x1a5300: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a52fc) {
            ctx->pc = 0x1A5558u;
            goto label_1a5558;
        }
    }
    ctx->pc = 0x1A5304u;
label_1a5304:
    // 0x1a5304: 0xc069630  jal         func_1A58C0
    ctx->pc = 0x1A5304u;
    SET_GPR_U32(ctx, 31, 0x1A530Cu);
    ctx->pc = 0x1A5308u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5304u;
            // 0x1a5308: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A58C0u;
    if (runtime->hasFunction(0x1A58C0u)) {
        auto targetFn = runtime->lookupFunction(0x1A58C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A530Cu; }
        if (ctx->pc != 0x1A530Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A58C0_0x1a58c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A530Cu; }
        if (ctx->pc != 0x1A530Cu) { return; }
    }
    ctx->pc = 0x1A530Cu;
label_1a530c:
    // 0x1a530c: 0x90430011  lbu         $v1, 0x11($v0)
    ctx->pc = 0x1a530cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 17)));
    // 0x1a5310: 0x28610008  slti        $at, $v1, 0x8
    ctx->pc = 0x1a5310u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x1a5314: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A5314u;
    {
        const bool branch_taken_0x1a5314 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a5314) {
            ctx->pc = 0x1A5324u;
            goto label_1a5324;
        }
    }
    ctx->pc = 0x1A531Cu;
    // 0x1a531c: 0x1000008e  b           . + 4 + (0x8E << 2)
    ctx->pc = 0x1A531Cu;
    {
        const bool branch_taken_0x1a531c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5320u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A531Cu;
            // 0x1a5320: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a531c) {
            ctx->pc = 0x1A5558u;
            goto label_1a5558;
        }
    }
    ctx->pc = 0x1A5324u;
label_1a5324:
    // 0x1a5324: 0x944c0014  lhu         $t4, 0x14($v0)
    ctx->pc = 0x1a5324u;
    SET_GPR_U32(ctx, 12, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 20)));
    // 0x1a5328: 0x682d  daddu       $t5, $zero, $zero
    ctx->pc = 0x1a5328u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a532c: 0x944b0016  lhu         $t3, 0x16($v0)
    ctx->pc = 0x1a532cu;
    SET_GPR_U32(ctx, 11, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 22)));
    // 0x1a5330: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1a5330u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1a5334: 0x24070005  addiu       $a3, $zero, 0x5
    ctx->pc = 0x1a5334u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1a5338: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1a5338u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a533c: 0x24090002  addiu       $t1, $zero, 0x2
    ctx->pc = 0x1a533cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a5340: 0x240a0003  addiu       $t2, $zero, 0x3
    ctx->pc = 0x1a5340u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1a5344: 0x24120008  addiu       $s2, $zero, 0x8
    ctx->pc = 0x1a5344u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1a5348: 0x24110010  addiu       $s1, $zero, 0x10
    ctx->pc = 0x1a5348u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1a534c: 0x241900ff  addiu       $t9, $zero, 0xFF
    ctx->pc = 0x1a534cu;
    SET_GPR_S32(ctx, 25, (int32_t)ADD32(GPR_U32(ctx, 0), 255));
    // 0x1a5350: 0x240f0018  addiu       $t7, $zero, 0x18
    ctx->pc = 0x1a5350u;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1a5354: 0x2405000a  addiu       $a1, $zero, 0xA
    ctx->pc = 0x1a5354u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1a5358: 0x2404001f  addiu       $a0, $zero, 0x1F
    ctx->pc = 0x1a5358u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x1a535c: 0x10000079  b           . + 4 + (0x79 << 2)
    ctx->pc = 0x1A535Cu;
    {
        const bool branch_taken_0x1a535c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5360u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A535Cu;
            // 0x1a5360: 0x2403000f  addiu       $v1, $zero, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a535c) {
            ctx->pc = 0x1A5544u;
            goto label_1a5544;
        }
    }
    ctx->pc = 0x1A5364u;
label_1a5364:
    // 0x1a5364: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x1a5364u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1a5368: 0xae0c0004  sw          $t4, 0x4($s0)
    ctx->pc = 0x1a5368u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 12));
    // 0x1a536c: 0xae0b0008  sw          $t3, 0x8($s0)
    ctx->pc = 0x1a536cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 11));
    // 0x1a5370: 0x904e0013  lbu         $t6, 0x13($v0)
    ctx->pc = 0x1a5370u;
    SET_GPR_U32(ctx, 14, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 19)));
    // 0x1a5374: 0x11ca005c  beq         $t6, $t2, . + 4 + (0x5C << 2)
    ctx->pc = 0x1A5374u;
    {
        const bool branch_taken_0x1a5374 = (GPR_U64(ctx, 14) == GPR_U64(ctx, 10));
        if (branch_taken_0x1a5374) {
            ctx->pc = 0x1A54E8u;
            goto label_1a54e8;
        }
    }
    ctx->pc = 0x1A537Cu;
    // 0x1a537c: 0x11c90046  beq         $t6, $t1, . + 4 + (0x46 << 2)
    ctx->pc = 0x1A537Cu;
    {
        const bool branch_taken_0x1a537c = (GPR_U64(ctx, 14) == GPR_U64(ctx, 9));
        if (branch_taken_0x1a537c) {
            ctx->pc = 0x1A5498u;
            goto label_1a5498;
        }
    }
    ctx->pc = 0x1A5384u;
    // 0x1a5384: 0x11c80030  beq         $t6, $t0, . + 4 + (0x30 << 2)
    ctx->pc = 0x1A5384u;
    {
        const bool branch_taken_0x1a5384 = (GPR_U64(ctx, 14) == GPR_U64(ctx, 8));
        if (branch_taken_0x1a5384) {
            ctx->pc = 0x1A5448u;
            goto label_1a5448;
        }
    }
    ctx->pc = 0x1A538Cu;
    // 0x1a538c: 0x11c70019  beq         $t6, $a3, . + 4 + (0x19 << 2)
    ctx->pc = 0x1A538Cu;
    {
        const bool branch_taken_0x1a538c = (GPR_U64(ctx, 14) == GPR_U64(ctx, 7));
        if (branch_taken_0x1a538c) {
            ctx->pc = 0x1A53F4u;
            goto label_1a53f4;
        }
    }
    ctx->pc = 0x1A5394u;
    // 0x1a5394: 0x11c60003  beq         $t6, $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A5394u;
    {
        const bool branch_taken_0x1a5394 = (GPR_U64(ctx, 14) == GPR_U64(ctx, 6));
        if (branch_taken_0x1a5394) {
            ctx->pc = 0x1A53A4u;
            goto label_1a53a4;
        }
    }
    ctx->pc = 0x1A539Cu;
    // 0x1a539c: 0x10000066  b           . + 4 + (0x66 << 2)
    ctx->pc = 0x1A539Cu;
    {
        const bool branch_taken_0x1a539c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A53A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A539Cu;
            // 0x1a53a0: 0x26100048  addiu       $s0, $s0, 0x48 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a539c) {
            ctx->pc = 0x1A5538u;
            goto label_1a5538;
        }
    }
    ctx->pc = 0x1A53A4u;
label_1a53a4:
    // 0x1a53a4: 0x8e0e0000  lw          $t6, 0x0($s0)
    ctx->pc = 0x1a53a4u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1a53a8: 0x35ce0014  ori         $t6, $t6, 0x14
    ctx->pc = 0x1a53a8u;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 14) | (uint64_t)(uint16_t)20);
    // 0x1a53ac: 0xae0e0000  sw          $t6, 0x0($s0)
    ctx->pc = 0x1a53acu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 14));
    // 0x1a53b0: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x1a53b0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x1a53b4: 0x8e0e0004  lw          $t6, 0x4($s0)
    ctx->pc = 0x1a53b4u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1a53b8: 0xe7043  sra         $t6, $t6, 1
    ctx->pc = 0x1a53b8u;
    SET_GPR_S32(ctx, 14, SRA32(GPR_S32(ctx, 14), 1));
    // 0x1a53bc: 0xae0e000c  sw          $t6, 0xC($s0)
    ctx->pc = 0x1a53bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 14));
    // 0x1a53c0: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x1a53c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
    // 0x1a53c4: 0xae000018  sw          $zero, 0x18($s0)
    ctx->pc = 0x1a53c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x1a53c8: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x1a53c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x1a53cc: 0xae000028  sw          $zero, 0x28($s0)
    ctx->pc = 0x1a53ccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 0));
    // 0x1a53d0: 0xae000024  sw          $zero, 0x24($s0)
    ctx->pc = 0x1a53d0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
    // 0x1a53d4: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x1a53d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x1a53d8: 0xae000034  sw          $zero, 0x34($s0)
    ctx->pc = 0x1a53d8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x1a53dc: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x1a53dcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x1a53e0: 0xae000038  sw          $zero, 0x38($s0)
    ctx->pc = 0x1a53e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 0));
    // 0x1a53e4: 0xae000040  sw          $zero, 0x40($s0)
    ctx->pc = 0x1a53e4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 64), GPR_U32(ctx, 0));
    // 0x1a53e8: 0xae00003c  sw          $zero, 0x3C($s0)
    ctx->pc = 0x1a53e8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
    // 0x1a53ec: 0x10000051  b           . + 4 + (0x51 << 2)
    ctx->pc = 0x1A53ECu;
    {
        const bool branch_taken_0x1a53ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A53F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A53ECu;
            // 0x1a53f0: 0xae000044  sw          $zero, 0x44($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a53ec) {
            ctx->pc = 0x1A5534u;
            goto label_1a5534;
        }
    }
    ctx->pc = 0x1A53F4u;
label_1a53f4:
    // 0x1a53f4: 0x8e0e0000  lw          $t6, 0x0($s0)
    ctx->pc = 0x1a53f4u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1a53f8: 0x35ce0004  ori         $t6, $t6, 0x4
    ctx->pc = 0x1a53f8u;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 14) | (uint64_t)(uint16_t)4);
    // 0x1a53fc: 0xae0e0000  sw          $t6, 0x0($s0)
    ctx->pc = 0x1a53fcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 14));
    // 0x1a5400: 0xae080014  sw          $t0, 0x14($s0)
    ctx->pc = 0x1a5400u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 8));
    // 0x1a5404: 0x8e180014  lw          $t8, 0x14($s0)
    ctx->pc = 0x1a5404u;
    SET_GPR_S32(ctx, 24, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1a5408: 0x8e0e0004  lw          $t6, 0x4($s0)
    ctx->pc = 0x1a5408u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1a540c: 0x30e7018  mult        $t6, $t8, $t6
    ctx->pc = 0x1a540cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 24) * (int64_t)GPR_S32(ctx, 14); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 14, (int32_t)result); }
    // 0x1a5410: 0xae0e000c  sw          $t6, 0xC($s0)
    ctx->pc = 0x1a5410u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 14));
    // 0x1a5414: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x1a5414u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
    // 0x1a5418: 0xae000018  sw          $zero, 0x18($s0)
    ctx->pc = 0x1a5418u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 0));
    // 0x1a541c: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x1a541cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x1a5420: 0xae000028  sw          $zero, 0x28($s0)
    ctx->pc = 0x1a5420u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 0));
    // 0x1a5424: 0xae000024  sw          $zero, 0x24($s0)
    ctx->pc = 0x1a5424u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 0));
    // 0x1a5428: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x1a5428u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x1a542c: 0xae000034  sw          $zero, 0x34($s0)
    ctx->pc = 0x1a542cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x1a5430: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x1a5430u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x1a5434: 0xae000038  sw          $zero, 0x38($s0)
    ctx->pc = 0x1a5434u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 0));
    // 0x1a5438: 0xae000040  sw          $zero, 0x40($s0)
    ctx->pc = 0x1a5438u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 64), GPR_U32(ctx, 0));
    // 0x1a543c: 0xae00003c  sw          $zero, 0x3C($s0)
    ctx->pc = 0x1a543cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
    // 0x1a5440: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x1A5440u;
    {
        const bool branch_taken_0x1a5440 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5444u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5440u;
            // 0x1a5444: 0xae000044  sw          $zero, 0x44($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5440) {
            ctx->pc = 0x1A5534u;
            goto label_1a5534;
        }
    }
    ctx->pc = 0x1A5448u;
label_1a5448:
    // 0x1a5448: 0xae090014  sw          $t1, 0x14($s0)
    ctx->pc = 0x1a5448u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 9));
    // 0x1a544c: 0x8e180014  lw          $t8, 0x14($s0)
    ctx->pc = 0x1a544cu;
    SET_GPR_S32(ctx, 24, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1a5450: 0x8e0e0004  lw          $t6, 0x4($s0)
    ctx->pc = 0x1a5450u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1a5454: 0x30e7018  mult        $t6, $t8, $t6
    ctx->pc = 0x1a5454u;
    { int64_t result = (int64_t)GPR_S32(ctx, 24) * (int64_t)GPR_S32(ctx, 14); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 14, (int32_t)result); }
    // 0x1a5458: 0xae0e000c  sw          $t6, 0xC($s0)
    ctx->pc = 0x1a5458u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 14));
    // 0x1a545c: 0xae070018  sw          $a3, 0x18($s0)
    ctx->pc = 0x1a545cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 7));
    // 0x1a5460: 0xae05001c  sw          $a1, 0x1C($s0)
    ctx->pc = 0x1a5460u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 5));
    // 0x1a5464: 0xae040020  sw          $a0, 0x20($s0)
    ctx->pc = 0x1a5464u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 4));
    // 0x1a5468: 0xae070024  sw          $a3, 0x24($s0)
    ctx->pc = 0x1a5468u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 7));
    // 0x1a546c: 0xae070028  sw          $a3, 0x28($s0)
    ctx->pc = 0x1a546cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 7));
    // 0x1a5470: 0xae04002c  sw          $a0, 0x2C($s0)
    ctx->pc = 0x1a5470u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 4));
    // 0x1a5474: 0xae070030  sw          $a3, 0x30($s0)
    ctx->pc = 0x1a5474u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 7));
    // 0x1a5478: 0xae000034  sw          $zero, 0x34($s0)
    ctx->pc = 0x1a5478u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x1a547c: 0xae040038  sw          $a0, 0x38($s0)
    ctx->pc = 0x1a547cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 4));
    // 0x1a5480: 0xae08003c  sw          $t0, 0x3C($s0)
    ctx->pc = 0x1a5480u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 8));
    // 0x1a5484: 0xae030040  sw          $v1, 0x40($s0)
    ctx->pc = 0x1a5484u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 64), GPR_U32(ctx, 3));
    // 0x1a5488: 0xae080044  sw          $t0, 0x44($s0)
    ctx->pc = 0x1a5488u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 8));
    // 0x1a548c: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x1a548cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
    // 0x1a5490: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x1A5490u;
    {
        const bool branch_taken_0x1a5490 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A5494u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5490u;
            // 0x1a5494: 0xae050034  sw          $a1, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a5490) {
            ctx->pc = 0x1A5534u;
            goto label_1a5534;
        }
    }
    ctx->pc = 0x1A5498u;
label_1a5498:
    // 0x1a5498: 0xae0a0014  sw          $t2, 0x14($s0)
    ctx->pc = 0x1a5498u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 10));
    // 0x1a549c: 0x8e180014  lw          $t8, 0x14($s0)
    ctx->pc = 0x1a549cu;
    SET_GPR_S32(ctx, 24, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1a54a0: 0x8e0e0004  lw          $t6, 0x4($s0)
    ctx->pc = 0x1a54a0u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1a54a4: 0x30e7018  mult        $t6, $t8, $t6
    ctx->pc = 0x1a54a4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 24) * (int64_t)GPR_S32(ctx, 14); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 14, (int32_t)result); }
    // 0x1a54a8: 0xae0e000c  sw          $t6, 0xC($s0)
    ctx->pc = 0x1a54a8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 14));
    // 0x1a54ac: 0xae120018  sw          $s2, 0x18($s0)
    ctx->pc = 0x1a54acu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 18));
    // 0x1a54b0: 0xae11001c  sw          $s1, 0x1C($s0)
    ctx->pc = 0x1a54b0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 17));
    // 0x1a54b4: 0xae190020  sw          $t9, 0x20($s0)
    ctx->pc = 0x1a54b4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 25));
    // 0x1a54b8: 0xae120024  sw          $s2, 0x24($s0)
    ctx->pc = 0x1a54b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 18));
    // 0x1a54bc: 0xae120028  sw          $s2, 0x28($s0)
    ctx->pc = 0x1a54bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 18));
    // 0x1a54c0: 0xae19002c  sw          $t9, 0x2C($s0)
    ctx->pc = 0x1a54c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 25));
    // 0x1a54c4: 0xae120030  sw          $s2, 0x30($s0)
    ctx->pc = 0x1a54c4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 18));
    // 0x1a54c8: 0xae000034  sw          $zero, 0x34($s0)
    ctx->pc = 0x1a54c8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x1a54cc: 0xae190038  sw          $t9, 0x38($s0)
    ctx->pc = 0x1a54ccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 25));
    // 0x1a54d0: 0xae00003c  sw          $zero, 0x3C($s0)
    ctx->pc = 0x1a54d0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 0));
    // 0x1a54d4: 0xae000040  sw          $zero, 0x40($s0)
    ctx->pc = 0x1a54d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 64), GPR_U32(ctx, 0));
    // 0x1a54d8: 0xae000044  sw          $zero, 0x44($s0)
    ctx->pc = 0x1a54d8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 0));
    // 0x1a54dc: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x1a54dcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
    // 0x1a54e0: 0x10000014  b           . + 4 + (0x14 << 2)
    ctx->pc = 0x1A54E0u;
    {
        const bool branch_taken_0x1a54e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A54E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A54E0u;
            // 0x1a54e4: 0xae110034  sw          $s1, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 17));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a54e0) {
            ctx->pc = 0x1A5534u;
            goto label_1a5534;
        }
    }
    ctx->pc = 0x1A54E8u;
label_1a54e8:
    // 0x1a54e8: 0xae060014  sw          $a2, 0x14($s0)
    ctx->pc = 0x1a54e8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 6));
    // 0x1a54ec: 0x8e180014  lw          $t8, 0x14($s0)
    ctx->pc = 0x1a54ecu;
    SET_GPR_S32(ctx, 24, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1a54f0: 0x8e0e0004  lw          $t6, 0x4($s0)
    ctx->pc = 0x1a54f0u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1a54f4: 0x30e7018  mult        $t6, $t8, $t6
    ctx->pc = 0x1a54f4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 24) * (int64_t)GPR_S32(ctx, 14); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 14, (int32_t)result); }
    // 0x1a54f8: 0xae0e000c  sw          $t6, 0xC($s0)
    ctx->pc = 0x1a54f8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 14));
    // 0x1a54fc: 0xae120018  sw          $s2, 0x18($s0)
    ctx->pc = 0x1a54fcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 24), GPR_U32(ctx, 18));
    // 0x1a5500: 0xae11001c  sw          $s1, 0x1C($s0)
    ctx->pc = 0x1a5500u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 17));
    // 0x1a5504: 0xae190020  sw          $t9, 0x20($s0)
    ctx->pc = 0x1a5504u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 25));
    // 0x1a5508: 0xae120024  sw          $s2, 0x24($s0)
    ctx->pc = 0x1a5508u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 18));
    // 0x1a550c: 0xae120028  sw          $s2, 0x28($s0)
    ctx->pc = 0x1a550cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 18));
    // 0x1a5510: 0xae19002c  sw          $t9, 0x2C($s0)
    ctx->pc = 0x1a5510u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 25));
    // 0x1a5514: 0xae120030  sw          $s2, 0x30($s0)
    ctx->pc = 0x1a5514u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 18));
    // 0x1a5518: 0xae000034  sw          $zero, 0x34($s0)
    ctx->pc = 0x1a5518u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
    // 0x1a551c: 0xae190038  sw          $t9, 0x38($s0)
    ctx->pc = 0x1a551cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 56), GPR_U32(ctx, 25));
    // 0x1a5520: 0xae12003c  sw          $s2, 0x3C($s0)
    ctx->pc = 0x1a5520u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 60), GPR_U32(ctx, 18));
    // 0x1a5524: 0xae0f0040  sw          $t7, 0x40($s0)
    ctx->pc = 0x1a5524u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 64), GPR_U32(ctx, 15));
    // 0x1a5528: 0xae190044  sw          $t9, 0x44($s0)
    ctx->pc = 0x1a5528u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 25));
    // 0x1a552c: 0xae00001c  sw          $zero, 0x1C($s0)
    ctx->pc = 0x1a552cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 28), GPR_U32(ctx, 0));
    // 0x1a5530: 0xae110034  sw          $s1, 0x34($s0)
    ctx->pc = 0x1a5530u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 17));
label_1a5534:
    // 0x1a5534: 0x26100048  addiu       $s0, $s0, 0x48
    ctx->pc = 0x1a5534u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
label_1a5538:
    // 0x1a5538: 0xc6043  sra         $t4, $t4, 1
    ctx->pc = 0x1a5538u;
    SET_GPR_S32(ctx, 12, SRA32(GPR_S32(ctx, 12), 1));
    // 0x1a553c: 0xb5843  sra         $t3, $t3, 1
    ctx->pc = 0x1a553cu;
    SET_GPR_S32(ctx, 11, SRA32(GPR_S32(ctx, 11), 1));
    // 0x1a5540: 0x25ad0001  addiu       $t5, $t5, 0x1
    ctx->pc = 0x1a5540u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 1));
label_1a5544:
    // 0x1a5544: 0x904e0011  lbu         $t6, 0x11($v0)
    ctx->pc = 0x1a5544u;
    SET_GPR_U32(ctx, 14, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 17)));
    // 0x1a5548: 0x1ae702a  slt         $t6, $t5, $t6
    ctx->pc = 0x1a5548u;
    SET_GPR_U64(ctx, 14, ((int64_t)GPR_S64(ctx, 13) < (int64_t)GPR_S64(ctx, 14)) ? 1 : 0);
    // 0x1a554c: 0x15c0ff85  bnez        $t6, . + 4 + (-0x7B << 2)
    ctx->pc = 0x1A554Cu;
    {
        const bool branch_taken_0x1a554c = (GPR_U64(ctx, 14) != GPR_U64(ctx, 0));
        if (branch_taken_0x1a554c) {
            ctx->pc = 0x1A5364u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1a5364;
        }
    }
    ctx->pc = 0x1A5554u;
    // 0x1a5554: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1a5554u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1a5558:
    // 0x1a5558: 0xdfbf0030  ld          $ra, 0x30($sp)
    ctx->pc = 0x1a5558u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1a555c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1a555cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1a5560: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1a5560u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a5564: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1a5564u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a5568: 0x3e00008  jr          $ra
    ctx->pc = 0x1A5568u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A556Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A5568u;
            // 0x1a556c: 0x27bd0040  addiu       $sp, $sp, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 64));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A52F4u: goto label_1a52f4;
            case 0x1A5304u: goto label_1a5304;
            case 0x1A530Cu: goto label_1a530c;
            case 0x1A5324u: goto label_1a5324;
            case 0x1A5364u: goto label_1a5364;
            case 0x1A53A4u: goto label_1a53a4;
            case 0x1A53F4u: goto label_1a53f4;
            case 0x1A5448u: goto label_1a5448;
            case 0x1A5498u: goto label_1a5498;
            case 0x1A54E8u: goto label_1a54e8;
            case 0x1A5534u: goto label_1a5534;
            case 0x1A5538u: goto label_1a5538;
            case 0x1A5544u: goto label_1a5544;
            case 0x1A5558u: goto label_1a5558;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A5570u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
