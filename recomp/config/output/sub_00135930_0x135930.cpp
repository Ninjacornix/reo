#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00135930
// Address: 0x135930 - 0x135a58
void sub_00135930_0x135930(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00135930_0x135930");
#endif

    switch (ctx->pc) {
        case 0x13597cu: goto label_13597c;
        case 0x135998u: goto label_135998;
        case 0x1359bcu: goto label_1359bc;
        case 0x1359ccu: goto label_1359cc;
        case 0x1359f0u: goto label_1359f0;
        case 0x135a00u: goto label_135a00;
        case 0x135a24u: goto label_135a24;
        case 0x135a34u: goto label_135a34;
        default: break;
    }

    ctx->pc = 0x135930u;

    // 0x135930: 0x27bdfd70  addiu       $sp, $sp, -0x290
    ctx->pc = 0x135930u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294966640));
    // 0x135934: 0xffb10268  sd          $s1, 0x268($sp)
    ctx->pc = 0x135934u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 616), GPR_U64(ctx, 17));
    // 0x135938: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x135938u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13593c: 0xffb30278  sd          $s3, 0x278($sp)
    ctx->pc = 0x13593cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 632), GPR_U64(ctx, 19));
    // 0x135940: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x135940u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135944: 0xffb40280  sd          $s4, 0x280($sp)
    ctx->pc = 0x135944u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 640), GPR_U64(ctx, 20));
    // 0x135948: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x135948u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13594c: 0xffb00260  sd          $s0, 0x260($sp)
    ctx->pc = 0x13594cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 608), GPR_U64(ctx, 16));
    // 0x135950: 0xffb20270  sd          $s2, 0x270($sp)
    ctx->pc = 0x135950u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 624), GPR_U64(ctx, 18));
    // 0x135954: 0x16200004  bnez        $s1, . + 4 + (0x4 << 2)
    ctx->pc = 0x135954u;
    {
        const bool branch_taken_0x135954 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        ctx->pc = 0x135958u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135954u;
            // 0x135958: 0xffbf0288  sd          $ra, 0x288($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 648), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135954) {
            ctx->pc = 0x135968u;
            goto label_135968;
        }
    }
    ctx->pc = 0x13595Cu;
    // 0x13595c: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x13595cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x135960: 0x10000032  b           . + 4 + (0x32 << 2)
    ctx->pc = 0x135960u;
    {
        const bool branch_taken_0x135960 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x135964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135960u;
            // 0x135964: 0x2484b8a0  addiu       $a0, $a0, -0x4760 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949024));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135960) {
            ctx->pc = 0x135A2Cu;
            goto label_135a2c;
        }
    }
    ctx->pc = 0x135968u;
label_135968:
    // 0x135968: 0x27b20130  addiu       $s2, $sp, 0x130
    ctx->pc = 0x135968u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 29), 304));
    // 0x13596c: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x13596cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135970: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x135970u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x135974: 0xc04d6b4  jal         func_135AD0
    ctx->pc = 0x135974u;
    SET_GPR_U32(ctx, 31, 0x13597Cu);
    ctx->pc = 0x135978u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135974u;
            // 0x135978: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AD0u;
    if (runtime->hasFunction(0x135AD0u)) {
        auto targetFn = runtime->lookupFunction(0x135AD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13597Cu; }
        if (ctx->pc != 0x13597Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AD0_0x135ad0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13597Cu; }
        if (ctx->pc != 0x13597Cu) { return; }
    }
    ctx->pc = 0x13597Cu;
label_13597c:
    // 0x13597c: 0x83a20130  lb          $v0, 0x130($sp)
    ctx->pc = 0x13597cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x135980: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x135980u;
    {
        const bool branch_taken_0x135980 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x135984u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135980u;
            // 0x135984: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135980) {
            ctx->pc = 0x135990u;
            goto label_135990;
        }
    }
    ctx->pc = 0x135988u;
    // 0x135988: 0x10000028  b           . + 4 + (0x28 << 2)
    ctx->pc = 0x135988u;
    {
        const bool branch_taken_0x135988 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x13598Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135988u;
            // 0x13598c: 0x2484b8a0  addiu       $a0, $a0, -0x4760 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949024));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135988) {
            ctx->pc = 0x135A2Cu;
            goto label_135a2c;
        }
    }
    ctx->pc = 0x135990u;
label_135990:
    // 0x135990: 0xc04d696  jal         func_135A58
    ctx->pc = 0x135990u;
    SET_GPR_U32(ctx, 31, 0x135998u);
    ctx->pc = 0x135A58u;
    if (runtime->hasFunction(0x135A58u)) {
        auto targetFn = runtime->lookupFunction(0x135A58u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135998u; }
        if (ctx->pc != 0x135998u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135A58_0x135a58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135998u; }
        if (ctx->pc != 0x135998u) { return; }
    }
    ctx->pc = 0x135998u;
label_135998:
    // 0x135998: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x135998u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13599c: 0x16000004  bnez        $s0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13599Cu;
    {
        const bool branch_taken_0x13599c = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        ctx->pc = 0x1359A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13599Cu;
            // 0x1359a0: 0x220302d  daddu       $a2, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13599c) {
            ctx->pc = 0x1359B0u;
            goto label_1359b0;
        }
    }
    ctx->pc = 0x1359A4u;
    // 0x1359a4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1359a4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1359a8: 0x10000020  b           . + 4 + (0x20 << 2)
    ctx->pc = 0x1359A8u;
    {
        const bool branch_taken_0x1359a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1359ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1359A8u;
            // 0x1359ac: 0x2484b8c0  addiu       $a0, $a0, -0x4740 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949056));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1359a8) {
            ctx->pc = 0x135A2Cu;
            goto label_135a2c;
        }
    }
    ctx->pc = 0x1359B0u;
label_1359b0:
    // 0x1359b0: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x1359b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1359b4: 0xc04d622  jal         func_135888
    ctx->pc = 0x1359B4u;
    SET_GPR_U32(ctx, 31, 0x1359BCu);
    ctx->pc = 0x1359B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1359B4u;
            // 0x1359b8: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135888u;
    if (runtime->hasFunction(0x135888u)) {
        auto targetFn = runtime->lookupFunction(0x135888u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1359BCu; }
        if (ctx->pc != 0x1359BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135888_0x135888(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1359BCu; }
        if (ctx->pc != 0x1359BCu) { return; }
    }
    ctx->pc = 0x1359BCu;
label_1359bc:
    // 0x1359bc: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1359BCu;
    {
        const bool branch_taken_0x1359bc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1359C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1359BCu;
            // 0x1359c0: 0xae020000  sw          $v0, 0x0($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1359bc) {
            ctx->pc = 0x1359D8u;
            goto label_1359d8;
        }
    }
    ctx->pc = 0x1359C4u;
    // 0x1359c4: 0xc04d6b0  jal         func_135AC0
    ctx->pc = 0x1359C4u;
    SET_GPR_U32(ctx, 31, 0x1359CCu);
    ctx->pc = 0x1359C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1359C4u;
            // 0x1359c8: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AC0u;
    if (runtime->hasFunction(0x135AC0u)) {
        auto targetFn = runtime->lookupFunction(0x135AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1359CCu; }
        if (ctx->pc != 0x1359CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AC0_0x135ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1359CCu; }
        if (ctx->pc != 0x1359CCu) { return; }
    }
    ctx->pc = 0x1359CCu;
label_1359cc:
    // 0x1359cc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1359ccu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1359d0: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x1359D0u;
    {
        const bool branch_taken_0x1359d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1359D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1359D0u;
            // 0x1359d4: 0x2484b908  addiu       $a0, $a0, -0x46F8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949128));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1359d0) {
            ctx->pc = 0x135A2Cu;
            goto label_135a2c;
        }
    }
    ctx->pc = 0x1359D8u;
label_1359d8:
    // 0x1359d8: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1359d8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1359dc: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1359DCu;
    {
        const bool branch_taken_0x1359dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1359E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1359DCu;
            // 0x1359e0: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1359dc) {
            ctx->pc = 0x1359F8u;
            goto label_1359f8;
        }
    }
    ctx->pc = 0x1359E4u;
    // 0x1359e4: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x1359e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1359e8: 0x40f809  jalr        $v0
    ctx->pc = 0x1359E8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1359F0u);
        ctx->pc = 0x1359ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1359E8u;
            // 0x1359ec: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1359F0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135968u: goto label_135968;
            case 0x13597Cu: goto label_13597c;
            case 0x135990u: goto label_135990;
            case 0x135998u: goto label_135998;
            case 0x1359B0u: goto label_1359b0;
            case 0x1359BCu: goto label_1359bc;
            case 0x1359CCu: goto label_1359cc;
            case 0x1359D8u: goto label_1359d8;
            case 0x1359F0u: goto label_1359f0;
            case 0x1359F8u: goto label_1359f8;
            case 0x135A00u: goto label_135a00;
            case 0x135A10u: goto label_135a10;
            case 0x135A24u: goto label_135a24;
            case 0x135A2Cu: goto label_135a2c;
            case 0x135A34u: goto label_135a34;
            case 0x135A38u: goto label_135a38;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1359F0u; }
            if (ctx->pc != 0x1359F0u) { return; }
        }
        }
    }
    ctx->pc = 0x1359F0u;
label_1359f0:
    // 0x1359f0: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1359F0u;
    {
        const bool branch_taken_0x1359f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1359F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1359F0u;
            // 0x1359f4: 0xae020004  sw          $v0, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1359f0) {
            ctx->pc = 0x135A10u;
            goto label_135a10;
        }
    }
    ctx->pc = 0x1359F8u;
label_1359f8:
    // 0x1359f8: 0xc04d6b0  jal         func_135AC0
    ctx->pc = 0x1359F8u;
    SET_GPR_U32(ctx, 31, 0x135A00u);
    ctx->pc = 0x1359FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1359F8u;
            // 0x1359fc: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AC0u;
    if (runtime->hasFunction(0x135AC0u)) {
        auto targetFn = runtime->lookupFunction(0x135AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135A00u; }
        if (ctx->pc != 0x135A00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AC0_0x135ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135A00u; }
        if (ctx->pc != 0x135A00u) { return; }
    }
    ctx->pc = 0x135A00u;
label_135a00:
    // 0x135a00: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x135a00u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x135a04: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x135A04u;
    {
        const bool branch_taken_0x135a04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x135A08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135A04u;
            // 0x135a08: 0x2484b928  addiu       $a0, $a0, -0x46D8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949160));
        ctx->in_delay_slot = false;
        if (branch_taken_0x135a04) {
            ctx->pc = 0x135A2Cu;
            goto label_135a2c;
        }
    }
    ctx->pc = 0x135A0Cu;
    // 0x135a0c: 0x0  nop
    ctx->pc = 0x135a0cu;
    // NOP
label_135a10:
    // 0x135a10: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x135a10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x135a14: 0x54400008  bnel        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x135A14u;
    {
        const bool branch_taken_0x135a14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x135a14) {
            ctx->pc = 0x135A18u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x135A14u;
            // 0x135a18: 0x200102d  daddu       $v0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x135A38u;
            goto label_135a38;
        }
    }
    ctx->pc = 0x135A1Cu;
    // 0x135a1c: 0xc04d6b0  jal         func_135AC0
    ctx->pc = 0x135A1Cu;
    SET_GPR_U32(ctx, 31, 0x135A24u);
    ctx->pc = 0x135A20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x135A1Cu;
            // 0x135a20: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x135AC0u;
    if (runtime->hasFunction(0x135AC0u)) {
        auto targetFn = runtime->lookupFunction(0x135AC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135A24u; }
        if (ctx->pc != 0x135A24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135AC0_0x135ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135A24u; }
        if (ctx->pc != 0x135A24u) { return; }
    }
    ctx->pc = 0x135A24u;
label_135a24:
    // 0x135a24: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x135a24u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x135a28: 0x2484b940  addiu       $a0, $a0, -0x46C0
    ctx->pc = 0x135a28u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294949184));
label_135a2c:
    // 0x135a2c: 0xc04d480  jal         func_135200
    ctx->pc = 0x135A2Cu;
    SET_GPR_U32(ctx, 31, 0x135A34u);
    ctx->pc = 0x135200u;
    if (runtime->hasFunction(0x135200u)) {
        auto targetFn = runtime->lookupFunction(0x135200u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135A34u; }
        if (ctx->pc != 0x135A34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x135A34u; }
        if (ctx->pc != 0x135A34u) { return; }
    }
    ctx->pc = 0x135A34u;
label_135a34:
    // 0x135a34: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x135a34u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_135a38:
    // 0x135a38: 0xdfb00260  ld          $s0, 0x260($sp)
    ctx->pc = 0x135a38u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 608)));
    // 0x135a3c: 0xdfb10268  ld          $s1, 0x268($sp)
    ctx->pc = 0x135a3cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 616)));
    // 0x135a40: 0xdfb20270  ld          $s2, 0x270($sp)
    ctx->pc = 0x135a40u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 624)));
    // 0x135a44: 0xdfb30278  ld          $s3, 0x278($sp)
    ctx->pc = 0x135a44u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 632)));
    // 0x135a48: 0xdfb40280  ld          $s4, 0x280($sp)
    ctx->pc = 0x135a48u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 640)));
    // 0x135a4c: 0xdfbf0288  ld          $ra, 0x288($sp)
    ctx->pc = 0x135a4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 648)));
    // 0x135a50: 0x3e00008  jr          $ra
    ctx->pc = 0x135A50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x135A54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x135A50u;
            // 0x135a54: 0x27bd0290  addiu       $sp, $sp, 0x290 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 656));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x135968u: goto label_135968;
            case 0x13597Cu: goto label_13597c;
            case 0x135990u: goto label_135990;
            case 0x135998u: goto label_135998;
            case 0x1359B0u: goto label_1359b0;
            case 0x1359BCu: goto label_1359bc;
            case 0x1359CCu: goto label_1359cc;
            case 0x1359D8u: goto label_1359d8;
            case 0x1359F0u: goto label_1359f0;
            case 0x1359F8u: goto label_1359f8;
            case 0x135A00u: goto label_135a00;
            case 0x135A10u: goto label_135a10;
            case 0x135A24u: goto label_135a24;
            case 0x135A2Cu: goto label_135a2c;
            case 0x135A34u: goto label_135a34;
            case 0x135A38u: goto label_135a38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x135A58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
