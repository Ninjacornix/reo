#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D5498
// Address: 0x1d5498 - 0x1d5730
void sub_001D5498_0x1d5498(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D5498_0x1d5498");
#endif

    switch (ctx->pc) {
        case 0x1d54f4u: goto label_1d54f4;
        case 0x1d5528u: goto label_1d5528;
        case 0x1d553cu: goto label_1d553c;
        case 0x1d55d4u: goto label_1d55d4;
        case 0x1d5608u: goto label_1d5608;
        case 0x1d561cu: goto label_1d561c;
        case 0x1d56b4u: goto label_1d56b4;
        case 0x1d56e8u: goto label_1d56e8;
        case 0x1d56fcu: goto label_1d56fc;
        default: break;
    }

    ctx->pc = 0x1d5498u;

    // 0x1d5498: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1d5498u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1d549c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d549cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d54a0: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x1d54a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x1d54a4: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d54a4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d54a8: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x1d54a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x1d54ac: 0x8c446998  lw          $a0, 0x6998($v0)
    ctx->pc = 0x1d54acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 27032)));
    // 0x1d54b0: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1d54b0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d54b4: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1d54b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1d54b8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d54b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d54bc: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x1d54bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1d54c0: 0x10820025  beq         $a0, $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x1D54C0u;
    {
        const bool branch_taken_0x1d54c0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D54C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D54C0u;
            // 0x1d54c4: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d54c0) {
            ctx->pc = 0x1D5558u;
            goto label_1d5558;
        }
    }
    ctx->pc = 0x1D54C8u;
    // 0x1d54c8: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1d54c8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1d54cc: 0x8c622840  lw          $v0, 0x2840($v1)
    ctx->pc = 0x1d54ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10304)));
    // 0x1d54d0: 0x222102b  sltu        $v0, $s1, $v0
    ctx->pc = 0x1d54d0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 17) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1d54d4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D54D4u;
    {
        const bool branch_taken_0x1d54d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D54D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D54D4u;
            // 0x1d54d8: 0x24722840  addiu       $s2, $v1, 0x2840 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), 10304));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d54d4) {
            ctx->pc = 0x1D54E4u;
            goto label_1d54e4;
        }
    }
    ctx->pc = 0x1D54DCu;
    // 0x1d54dc: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1D54DCu;
    {
        const bool branch_taken_0x1d54dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D54E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D54DCu;
            // 0x1d54e0: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d54dc) {
            ctx->pc = 0x1D5558u;
            goto label_1d5558;
        }
    }
    ctx->pc = 0x1D54E4u;
label_1d54e4:
    // 0x1d54e4: 0x3c100034  lui         $s0, 0x34
    ctx->pc = 0x1d54e4u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)52 << 16));
    // 0x1d54e8: 0xa2112940  sb          $s1, 0x2940($s0)
    ctx->pc = 0x1d54e8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 10560), (uint8_t)GPR_U32(ctx, 17));
    // 0x1d54ec: 0xc045198  jal         func_114660
    ctx->pc = 0x1D54ECu;
    SET_GPR_U32(ctx, 31, 0x1D54F4u);
    ctx->pc = 0x1D54F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D54ECu;
            // 0x1d54f0: 0x26102940  addiu       $s0, $s0, 0x2940 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 10560));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D54F4u; }
        if (ctx->pc != 0x1D54F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D54F4u; }
        if (ctx->pc != 0x1D54F4u) { return; }
    }
    ctx->pc = 0x1D54F4u;
label_1d54f4:
    // 0x1d54f4: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1d54f4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1d54f8: 0x3c090034  lui         $t1, 0x34
    ctx->pc = 0x1d54f8u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)52 << 16));
    // 0x1d54fc: 0x3c0b001d  lui         $t3, 0x1D
    ctx->pc = 0x1d54fcu;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)29 << 16));
    // 0x1d5500: 0x248428e0  addiu       $a0, $a0, 0x28E0
    ctx->pc = 0x1d5500u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10464));
    // 0x1d5504: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x1d5504u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5508: 0x25292980  addiu       $t1, $t1, 0x2980
    ctx->pc = 0x1d5508u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 10624));
    // 0x1d550c: 0x256b59b8  addiu       $t3, $t3, 0x59B8
    ctx->pc = 0x1d550cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 22968));
    // 0x1d5510: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x1d5510u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x1d5514: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1d5514u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d5518: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d5518u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d551c: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x1d551cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1d5520: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x1D5520u;
    SET_GPR_U32(ctx, 31, 0x1D5528u);
    ctx->pc = 0x1D5524u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5520u;
            // 0x1d5524: 0x240a0050  addiu       $t2, $zero, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5528u; }
        if (ctx->pc != 0x1D5528u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5528u; }
        if (ctx->pc != 0x1D5528u) { return; }
    }
    ctx->pc = 0x1D5528u;
label_1d5528:
    // 0x1d5528: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D5528u;
    {
        const bool branch_taken_0x1d5528 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D552Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5528u;
            // 0x1d552c: 0x3c040025  lui         $a0, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5528) {
            ctx->pc = 0x1D5544u;
            goto label_1d5544;
        }
    }
    ctx->pc = 0x1D5530u;
    // 0x1d5530: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1d5530u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5534: 0xc045a12  jal         func_116848
    ctx->pc = 0x1D5534u;
    SET_GPR_U32(ctx, 31, 0x1D553Cu);
    ctx->pc = 0x1D5538u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5534u;
            // 0x1d5538: 0x24846e88  addiu       $a0, $a0, 0x6E88 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 28296));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D553Cu; }
        if (ctx->pc != 0x1D553Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D553Cu; }
        if (ctx->pc != 0x1D553Cu) { return; }
    }
    ctx->pc = 0x1D553Cu;
label_1d553c:
    // 0x1d553c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1D553Cu;
    {
        const bool branch_taken_0x1d553c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5540u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D553Cu;
            // 0x1d5540: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d553c) {
            ctx->pc = 0x1D5558u;
            goto label_1d5558;
        }
    }
    ctx->pc = 0x1D5544u;
label_1d5544:
    // 0x1d5544: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1d5544u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d5548: 0xae530098  sw          $s3, 0x98($s2)
    ctx->pc = 0x1d5548u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 152), GPR_U32(ctx, 19));
    // 0x1d554c: 0xae420090  sw          $v0, 0x90($s2)
    ctx->pc = 0x1d554cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 144), GPR_U32(ctx, 2));
    // 0x1d5550: 0xae510094  sw          $s1, 0x94($s2)
    ctx->pc = 0x1d5550u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 148), GPR_U32(ctx, 17));
    // 0x1d5554: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d5554u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d5558:
    // 0x1d5558: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1d5558u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d555c: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x1d555cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d5560: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x1d5560u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d5564: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x1d5564u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d5568: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1d5568u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d556c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D556Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D5570u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D556Cu;
            // 0x1d5570: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D54E4u: goto label_1d54e4;
            case 0x1D54F4u: goto label_1d54f4;
            case 0x1D5528u: goto label_1d5528;
            case 0x1D553Cu: goto label_1d553c;
            case 0x1D5544u: goto label_1d5544;
            case 0x1D5558u: goto label_1d5558;
            case 0x1D55C4u: goto label_1d55c4;
            case 0x1D55D4u: goto label_1d55d4;
            case 0x1D5608u: goto label_1d5608;
            case 0x1D561Cu: goto label_1d561c;
            case 0x1D5624u: goto label_1d5624;
            case 0x1D5638u: goto label_1d5638;
            case 0x1D56A0u: goto label_1d56a0;
            case 0x1D56B4u: goto label_1d56b4;
            case 0x1D56E8u: goto label_1d56e8;
            case 0x1D56FCu: goto label_1d56fc;
            case 0x1D5704u: goto label_1d5704;
            case 0x1D5718u: goto label_1d5718;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D5574u;
    // 0x1d5574: 0x0  nop
    ctx->pc = 0x1d5574u;
    // NOP
    // 0x1d5578: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x1d5578u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x1d557c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d557cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d5580: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x1d5580u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x1d5584: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d5584u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5588: 0xffb30040  sd          $s3, 0x40($sp)
    ctx->pc = 0x1d5588u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x1d558c: 0x8c446998  lw          $a0, 0x6998($v0)
    ctx->pc = 0x1d558cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 27032)));
    // 0x1d5590: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1d5590u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5594: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x1d5594u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1d5598: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d5598u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d559c: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x1d559cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1d55a0: 0x10820025  beq         $a0, $v0, . + 4 + (0x25 << 2)
    ctx->pc = 0x1D55A0u;
    {
        const bool branch_taken_0x1d55a0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D55A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D55A0u;
            // 0x1d55a4: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d55a0) {
            ctx->pc = 0x1D5638u;
            goto label_1d5638;
        }
    }
    ctx->pc = 0x1D55A8u;
    // 0x1d55a8: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1d55a8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1d55ac: 0x8c622840  lw          $v0, 0x2840($v1)
    ctx->pc = 0x1d55acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10304)));
    // 0x1d55b0: 0x222102a  slt         $v0, $s1, $v0
    ctx->pc = 0x1d55b0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d55b4: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D55B4u;
    {
        const bool branch_taken_0x1d55b4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D55B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D55B4u;
            // 0x1d55b8: 0x24722840  addiu       $s2, $v1, 0x2840 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), 10304));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d55b4) {
            ctx->pc = 0x1D55C4u;
            goto label_1d55c4;
        }
    }
    ctx->pc = 0x1D55BCu;
    // 0x1d55bc: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1D55BCu;
    {
        const bool branch_taken_0x1d55bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D55C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D55BCu;
            // 0x1d55c0: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d55bc) {
            ctx->pc = 0x1D5638u;
            goto label_1d5638;
        }
    }
    ctx->pc = 0x1D55C4u;
label_1d55c4:
    // 0x1d55c4: 0x3c100034  lui         $s0, 0x34
    ctx->pc = 0x1d55c4u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)52 << 16));
    // 0x1d55c8: 0xa2112940  sb          $s1, 0x2940($s0)
    ctx->pc = 0x1d55c8u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 10560), (uint8_t)GPR_U32(ctx, 17));
    // 0x1d55cc: 0xc045198  jal         func_114660
    ctx->pc = 0x1D55CCu;
    SET_GPR_U32(ctx, 31, 0x1D55D4u);
    ctx->pc = 0x1D55D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D55CCu;
            // 0x1d55d0: 0x26102940  addiu       $s0, $s0, 0x2940 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 10560));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D55D4u; }
        if (ctx->pc != 0x1D55D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D55D4u; }
        if (ctx->pc != 0x1D55D4u) { return; }
    }
    ctx->pc = 0x1D55D4u;
label_1d55d4:
    // 0x1d55d4: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1d55d4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1d55d8: 0x3c090034  lui         $t1, 0x34
    ctx->pc = 0x1d55d8u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)52 << 16));
    // 0x1d55dc: 0x3c0b001d  lui         $t3, 0x1D
    ctx->pc = 0x1d55dcu;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)29 << 16));
    // 0x1d55e0: 0x248428e0  addiu       $a0, $a0, 0x28E0
    ctx->pc = 0x1d55e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10464));
    // 0x1d55e4: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x1d55e4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d55e8: 0x25292980  addiu       $t1, $t1, 0x2980
    ctx->pc = 0x1d55e8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 10624));
    // 0x1d55ec: 0x256b59b8  addiu       $t3, $t3, 0x59B8
    ctx->pc = 0x1d55ecu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 22968));
    // 0x1d55f0: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x1d55f0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x1d55f4: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x1d55f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d55f8: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d55f8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d55fc: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x1d55fcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1d5600: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x1D5600u;
    SET_GPR_U32(ctx, 31, 0x1D5608u);
    ctx->pc = 0x1D5604u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5600u;
            // 0x1d5604: 0x240a0010  addiu       $t2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5608u; }
        if (ctx->pc != 0x1D5608u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5608u; }
        if (ctx->pc != 0x1D5608u) { return; }
    }
    ctx->pc = 0x1D5608u;
label_1d5608:
    // 0x1d5608: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D5608u;
    {
        const bool branch_taken_0x1d5608 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D560Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5608u;
            // 0x1d560c: 0x3c040025  lui         $a0, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5608) {
            ctx->pc = 0x1D5624u;
            goto label_1d5624;
        }
    }
    ctx->pc = 0x1D5610u;
    // 0x1d5610: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1d5610u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d5614: 0xc045a12  jal         func_116848
    ctx->pc = 0x1D5614u;
    SET_GPR_U32(ctx, 31, 0x1D561Cu);
    ctx->pc = 0x1D5618u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5614u;
            // 0x1d5618: 0x24846eb0  addiu       $a0, $a0, 0x6EB0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 28336));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D561Cu; }
        if (ctx->pc != 0x1D561Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D561Cu; }
        if (ctx->pc != 0x1D561Cu) { return; }
    }
    ctx->pc = 0x1D561Cu;
label_1d561c:
    // 0x1d561c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1D561Cu;
    {
        const bool branch_taken_0x1d561c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5620u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D561Cu;
            // 0x1d5620: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d561c) {
            ctx->pc = 0x1D5638u;
            goto label_1d5638;
        }
    }
    ctx->pc = 0x1D5624u;
label_1d5624:
    // 0x1d5624: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1d5624u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d5628: 0xae530098  sw          $s3, 0x98($s2)
    ctx->pc = 0x1d5628u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 152), GPR_U32(ctx, 19));
    // 0x1d562c: 0xae420090  sw          $v0, 0x90($s2)
    ctx->pc = 0x1d562cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 144), GPR_U32(ctx, 2));
    // 0x1d5630: 0xae510094  sw          $s1, 0x94($s2)
    ctx->pc = 0x1d5630u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 148), GPR_U32(ctx, 17));
    // 0x1d5634: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d5634u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d5638:
    // 0x1d5638: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x1d5638u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d563c: 0xdfb30040  ld          $s3, 0x40($sp)
    ctx->pc = 0x1d563cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d5640: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x1d5640u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d5644: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x1d5644u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d5648: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1d5648u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d564c: 0x3e00008  jr          $ra
    ctx->pc = 0x1D564Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D5650u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D564Cu;
            // 0x1d5650: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D54E4u: goto label_1d54e4;
            case 0x1D54F4u: goto label_1d54f4;
            case 0x1D5528u: goto label_1d5528;
            case 0x1D553Cu: goto label_1d553c;
            case 0x1D5544u: goto label_1d5544;
            case 0x1D5558u: goto label_1d5558;
            case 0x1D55C4u: goto label_1d55c4;
            case 0x1D55D4u: goto label_1d55d4;
            case 0x1D5608u: goto label_1d5608;
            case 0x1D561Cu: goto label_1d561c;
            case 0x1D5624u: goto label_1d5624;
            case 0x1D5638u: goto label_1d5638;
            case 0x1D56A0u: goto label_1d56a0;
            case 0x1D56B4u: goto label_1d56b4;
            case 0x1D56E8u: goto label_1d56e8;
            case 0x1D56FCu: goto label_1d56fc;
            case 0x1D5704u: goto label_1d5704;
            case 0x1D5718u: goto label_1d5718;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D5654u;
    // 0x1d5654: 0x0  nop
    ctx->pc = 0x1d5654u;
    // NOP
    // 0x1d5658: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d5658u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1d565c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d565cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1d5660: 0xffb10020  sd          $s1, 0x20($sp)
    ctx->pc = 0x1d5660u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x1d5664: 0x30a500ff  andi        $a1, $a1, 0xFF
    ctx->pc = 0x1d5664u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1d5668: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1d5668u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d566c: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d566cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x1d5670: 0x8c446998  lw          $a0, 0x6998($v0)
    ctx->pc = 0x1d5670u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 27032)));
    // 0x1d5674: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x1d5674u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1d5678: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x1d5678u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d567c: 0x10820026  beq         $a0, $v0, . + 4 + (0x26 << 2)
    ctx->pc = 0x1D567Cu;
    {
        const bool branch_taken_0x1d567c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1D5680u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D567Cu;
            // 0x1d5680: 0xffb00010  sd          $s0, 0x10($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d567c) {
            ctx->pc = 0x1D5718u;
            goto label_1d5718;
        }
    }
    ctx->pc = 0x1D5684u;
    // 0x1d5684: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1d5684u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1d5688: 0x8c622840  lw          $v0, 0x2840($v1)
    ctx->pc = 0x1d5688u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 10304)));
    // 0x1d568c: 0x222102a  slt         $v0, $s1, $v0
    ctx->pc = 0x1d568cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1d5690: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D5690u;
    {
        const bool branch_taken_0x1d5690 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D5694u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5690u;
            // 0x1d5694: 0x24722840  addiu       $s2, $v1, 0x2840 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 3), 10304));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5690) {
            ctx->pc = 0x1D56A0u;
            goto label_1d56a0;
        }
    }
    ctx->pc = 0x1D5698u;
    // 0x1d5698: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1D5698u;
    {
        const bool branch_taken_0x1d5698 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D569Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5698u;
            // 0x1d569c: 0x2402fff5  addiu       $v0, $zero, -0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967285));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5698) {
            ctx->pc = 0x1D5718u;
            goto label_1d5718;
        }
    }
    ctx->pc = 0x1D56A0u;
label_1d56a0:
    // 0x1d56a0: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d56a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1d56a4: 0x24502940  addiu       $s0, $v0, 0x2940
    ctx->pc = 0x1d56a4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 10560));
    // 0x1d56a8: 0xa0512940  sb          $s1, 0x2940($v0)
    ctx->pc = 0x1d56a8u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 10560), (uint8_t)GPR_U32(ctx, 17));
    // 0x1d56ac: 0xc045198  jal         func_114660
    ctx->pc = 0x1D56ACu;
    SET_GPR_U32(ctx, 31, 0x1D56B4u);
    ctx->pc = 0x1D56B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D56ACu;
            // 0x1d56b0: 0xa2050001  sb          $a1, 0x1($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D56B4u; }
        if (ctx->pc != 0x1D56B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D56B4u; }
        if (ctx->pc != 0x1D56B4u) { return; }
    }
    ctx->pc = 0x1D56B4u;
label_1d56b4:
    // 0x1d56b4: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1d56b4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1d56b8: 0x3c090034  lui         $t1, 0x34
    ctx->pc = 0x1d56b8u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)52 << 16));
    // 0x1d56bc: 0x3c0b001d  lui         $t3, 0x1D
    ctx->pc = 0x1d56bcu;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)29 << 16));
    // 0x1d56c0: 0x248428e0  addiu       $a0, $a0, 0x28E0
    ctx->pc = 0x1d56c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10464));
    // 0x1d56c4: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x1d56c4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d56c8: 0x25292980  addiu       $t1, $t1, 0x2980
    ctx->pc = 0x1d56c8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 10624));
    // 0x1d56cc: 0x256b59b8  addiu       $t3, $t3, 0x59B8
    ctx->pc = 0x1d56ccu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 22968));
    // 0x1d56d0: 0xafa00000  sw          $zero, 0x0($sp)
    ctx->pc = 0x1d56d0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    // 0x1d56d4: 0x24050004  addiu       $a1, $zero, 0x4
    ctx->pc = 0x1d56d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d56d8: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d56d8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d56dc: 0x24080010  addiu       $t0, $zero, 0x10
    ctx->pc = 0x1d56dcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1d56e0: 0xc045e7a  jal         func_1179E8
    ctx->pc = 0x1D56E0u;
    SET_GPR_U32(ctx, 31, 0x1D56E8u);
    ctx->pc = 0x1D56E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D56E0u;
            // 0x1d56e4: 0x240a0010  addiu       $t2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1179E8u;
    if (runtime->hasFunction(0x1179E8u)) {
        auto targetFn = runtime->lookupFunction(0x1179E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D56E8u; }
        if (ctx->pc != 0x1D56E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D56E8u; }
        if (ctx->pc != 0x1D56E8u) { return; }
    }
    ctx->pc = 0x1D56E8u;
label_1d56e8:
    // 0x1d56e8: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D56E8u;
    {
        const bool branch_taken_0x1d56e8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D56ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D56E8u;
            // 0x1d56ec: 0x3c040025  lui         $a0, 0x25 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d56e8) {
            ctx->pc = 0x1D5704u;
            goto label_1d5704;
        }
    }
    ctx->pc = 0x1D56F0u;
    // 0x1d56f0: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1d56f0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d56f4: 0xc045a12  jal         func_116848
    ctx->pc = 0x1D56F4u;
    SET_GPR_U32(ctx, 31, 0x1D56FCu);
    ctx->pc = 0x1D56F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D56F4u;
            // 0x1d56f8: 0x24846ee0  addiu       $a0, $a0, 0x6EE0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 28384));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D56FCu; }
        if (ctx->pc != 0x1D56FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D56FCu; }
        if (ctx->pc != 0x1D56FCu) { return; }
    }
    ctx->pc = 0x1D56FCu;
label_1d56fc:
    // 0x1d56fc: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1D56FCu;
    {
        const bool branch_taken_0x1d56fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5700u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D56FCu;
            // 0x1d5700: 0x2402fffe  addiu       $v0, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d56fc) {
            ctx->pc = 0x1D5718u;
            goto label_1d5718;
        }
    }
    ctx->pc = 0x1D5704u;
label_1d5704:
    // 0x1d5704: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1d5704u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d5708: 0xae510094  sw          $s1, 0x94($s2)
    ctx->pc = 0x1d5708u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 148), GPR_U32(ctx, 17));
    // 0x1d570c: 0xae420090  sw          $v0, 0x90($s2)
    ctx->pc = 0x1d570cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 144), GPR_U32(ctx, 2));
    // 0x1d5710: 0xae400098  sw          $zero, 0x98($s2)
    ctx->pc = 0x1d5710u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 152), GPR_U32(ctx, 0));
    // 0x1d5714: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d5714u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d5718:
    // 0x1d5718: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d5718u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d571c: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x1d571cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d5720: 0xdfb10020  ld          $s1, 0x20($sp)
    ctx->pc = 0x1d5720u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d5724: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x1d5724u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d5728: 0x3e00008  jr          $ra
    ctx->pc = 0x1D5728u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D572Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5728u;
            // 0x1d572c: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D54E4u: goto label_1d54e4;
            case 0x1D54F4u: goto label_1d54f4;
            case 0x1D5528u: goto label_1d5528;
            case 0x1D553Cu: goto label_1d553c;
            case 0x1D5544u: goto label_1d5544;
            case 0x1D5558u: goto label_1d5558;
            case 0x1D55C4u: goto label_1d55c4;
            case 0x1D55D4u: goto label_1d55d4;
            case 0x1D5608u: goto label_1d5608;
            case 0x1D561Cu: goto label_1d561c;
            case 0x1D5624u: goto label_1d5624;
            case 0x1D5638u: goto label_1d5638;
            case 0x1D56A0u: goto label_1d56a0;
            case 0x1D56B4u: goto label_1d56b4;
            case 0x1D56E8u: goto label_1d56e8;
            case 0x1D56FCu: goto label_1d56fc;
            case 0x1D5704u: goto label_1d5704;
            case 0x1D5718u: goto label_1d5718;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D5730u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
