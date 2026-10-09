#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013D618
// Address: 0x13d618 - 0x13d800
void sub_0013D618_0x13d618(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013D618_0x13d618");
#endif

    switch (ctx->pc) {
        case 0x13d658u: goto label_13d658;
        case 0x13d66cu: goto label_13d66c;
        case 0x13d688u: goto label_13d688;
        case 0x13d690u: goto label_13d690;
        case 0x13d710u: goto label_13d710;
        case 0x13d718u: goto label_13d718;
        case 0x13d724u: goto label_13d724;
        case 0x13d738u: goto label_13d738;
        case 0x13d798u: goto label_13d798;
        case 0x13d7a4u: goto label_13d7a4;
        case 0x13d7c4u: goto label_13d7c4;
        case 0x13d7d0u: goto label_13d7d0;
        case 0x13d7d8u: goto label_13d7d8;
        default: break;
    }

    ctx->pc = 0x13d618u;

    // 0x13d618: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13d618u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13d61c: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13d61cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13d620: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13d620u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13d624: 0x2463e108  addiu       $v1, $v1, -0x1EF8
    ctx->pc = 0x13d624u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294959368));
    // 0x13d628: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13d628u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13d62c: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13d62cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13d630: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13d630u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13d634: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x13d634u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x13d638: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x13d638u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13d63c: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x13d63cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x13d640: 0x1440001d  bnez        $v0, . + 4 + (0x1D << 2)
    ctx->pc = 0x13D640u;
    {
        const bool branch_taken_0x13d640 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13D644u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D640u;
            // 0x13d644: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d640) {
            ctx->pc = 0x13D6B8u;
            goto label_13d6b8;
        }
    }
    ctx->pc = 0x13D648u;
    // 0x13d648: 0x3c130022  lui         $s3, 0x22
    ctx->pc = 0x13d648u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)34 << 16));
    // 0x13d64c: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x13d64cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13d650: 0x2670e110  addiu       $s0, $s3, -0x1EF0
    ctx->pc = 0x13d650u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 19), 4294959376));
    // 0x13d654: 0x2411000f  addiu       $s1, $zero, 0xF
    ctx->pc = 0x13d654u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
label_13d658:
    // 0x13d658: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x13d658u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13d65c: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x13D65Cu;
    {
        const bool branch_taken_0x13d65c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x13d65c) {
            ctx->pc = 0x13D660u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13D65Cu;
            // 0x13d660: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13D670u;
            goto label_13d670;
        }
    }
    ctx->pc = 0x13D664u;
    // 0x13d664: 0xc04f32e  jal         func_13CCB8
    ctx->pc = 0x13D664u;
    SET_GPR_U32(ctx, 31, 0x13D66Cu);
    ctx->pc = 0x13D668u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D664u;
            // 0x13d668: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13CCB8u;
    if (runtime->hasFunction(0x13CCB8u)) {
        auto targetFn = runtime->lookupFunction(0x13CCB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D66Cu; }
        if (ctx->pc != 0x13D66Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013CCB8_0x13ccb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D66Cu; }
        if (ctx->pc != 0x13D66Cu) { return; }
    }
    ctx->pc = 0x13D66Cu;
label_13d66c:
    // 0x13d66c: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x13d66cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_13d670:
    // 0x13d670: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x13D670u;
    {
        const bool branch_taken_0x13d670 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x13D674u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D670u;
            // 0x13d674: 0x26100238  addiu       $s0, $s0, 0x238 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 568));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d670) {
            ctx->pc = 0x13D658u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13d658;
        }
    }
    ctx->pc = 0x13D678u;
    // 0x13d678: 0x2664e110  addiu       $a0, $s3, -0x1EF0
    ctx->pc = 0x13d678u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 4294959376));
    // 0x13d67c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13d67cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d680: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x13D680u;
    SET_GPR_U32(ctx, 31, 0x13D688u);
    ctx->pc = 0x13D684u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D680u;
            // 0x13d684: 0x24062380  addiu       $a2, $zero, 0x2380 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 9088));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D688u; }
        if (ctx->pc != 0x13D688u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D688u; }
        if (ctx->pc != 0x13D688u) { return; }
    }
    ctx->pc = 0x13D688u;
label_13d688:
    // 0x13d688: 0xc04f564  jal         func_13D590
    ctx->pc = 0x13D688u;
    SET_GPR_U32(ctx, 31, 0x13D690u);
    ctx->pc = 0x13D590u;
    if (runtime->hasFunction(0x13D590u)) {
        auto targetFn = runtime->lookupFunction(0x13D590u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D690u; }
        if (ctx->pc != 0x13D690u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D590_0x13d590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D690u; }
        if (ctx->pc != 0x13D690u) { return; }
    }
    ctx->pc = 0x13D690u;
label_13d690:
    // 0x13d690: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13d690u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d694: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x13d694u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d698: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13d698u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13d69c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13d69cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d6a0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13d6a0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13d6a4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13d6a4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13d6a8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x13d6a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13d6ac: 0x804f534  j           func_13D4D0
    ctx->pc = 0x13D6ACu;
    ctx->pc = 0x13D6B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D6ACu;
            // 0x13d6b0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4D0u;
    if (runtime->hasFunction(0x13D4D0u)) {
        auto targetFn = runtime->lookupFunction(0x13D4D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013D4D0_0x13d4d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13D6B4u;
    // 0x13d6b4: 0x0  nop
    ctx->pc = 0x13d6b4u;
    // NOP
label_13d6b8:
    // 0x13d6b8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13d6b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d6bc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13d6bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13d6c0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13d6c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13d6c4: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13d6c4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13d6c8: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x13d6c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13d6cc: 0x3e00008  jr          $ra
    ctx->pc = 0x13D6CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D6D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D6CCu;
            // 0x13d6d0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D658u: goto label_13d658;
            case 0x13D66Cu: goto label_13d66c;
            case 0x13D670u: goto label_13d670;
            case 0x13D688u: goto label_13d688;
            case 0x13D690u: goto label_13d690;
            case 0x13D6B8u: goto label_13d6b8;
            case 0x13D710u: goto label_13d710;
            case 0x13D718u: goto label_13d718;
            case 0x13D724u: goto label_13d724;
            case 0x13D738u: goto label_13d738;
            case 0x13D754u: goto label_13d754;
            case 0x13D780u: goto label_13d780;
            case 0x13D798u: goto label_13d798;
            case 0x13D7A4u: goto label_13d7a4;
            case 0x13D7C4u: goto label_13d7c4;
            case 0x13D7D0u: goto label_13d7d0;
            case 0x13D7D8u: goto label_13d7d8;
            case 0x13D7E8u: goto label_13d7e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D6D4u;
    // 0x13d6d4: 0x0  nop
    ctx->pc = 0x13d6d4u;
    // NOP
    // 0x13d6d8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13d6d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13d6dc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13d6dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13d6e0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13d6e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d6e4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13d6e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13d6e8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13d6e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13d6ec: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x13d6ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x13d6f0: 0x8e020020  lw          $v0, 0x20($s0)
    ctx->pc = 0x13d6f0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13d6f4: 0x8e030024  lw          $v1, 0x24($s0)
    ctx->pc = 0x13d6f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x13d6f8: 0x21140  sll         $v0, $v0, 5
    ctx->pc = 0x13d6f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 5));
    // 0x13d6fc: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x13d6fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x13d700: 0x18600039  blez        $v1, . + 4 + (0x39 << 2)
    ctx->pc = 0x13D700u;
    {
        const bool branch_taken_0x13d700 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x13D704u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D700u;
            // 0x13d704: 0x24510038  addiu       $s1, $v0, 0x38 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 56));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d700) {
            ctx->pc = 0x13D7E8u;
            goto label_13d7e8;
        }
    }
    ctx->pc = 0x13D708u;
    // 0x13d708: 0xc04c1b8  jal         func_1306E0
    ctx->pc = 0x13D708u;
    SET_GPR_U32(ctx, 31, 0x13D710u);
    ctx->pc = 0x13D70Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D708u;
            // 0x13d70c: 0x8e040028  lw          $a0, 0x28($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1306E0u;
    if (runtime->hasFunction(0x1306E0u)) {
        auto targetFn = runtime->lookupFunction(0x1306E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D710u; }
        if (ctx->pc != 0x13D710u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001306E0_0x1306e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D710u; }
        if (ctx->pc != 0x13D710u) { return; }
    }
    ctx->pc = 0x13D710u;
label_13d710:
    // 0x13d710: 0xc04c148  jal         func_130520
    ctx->pc = 0x13D710u;
    SET_GPR_U32(ctx, 31, 0x13D718u);
    ctx->pc = 0x13D714u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D710u;
            // 0x13d714: 0x8e040028  lw          $a0, 0x28($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130520u;
    if (runtime->hasFunction(0x130520u)) {
        auto targetFn = runtime->lookupFunction(0x130520u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D718u; }
        if (ctx->pc != 0x13D718u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130520_0x130520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D718u; }
        if (ctx->pc != 0x13D718u) { return; }
    }
    ctx->pc = 0x13D718u;
label_13d718:
    // 0x13d718: 0x8e320004  lw          $s2, 0x4($s1)
    ctx->pc = 0x13d718u;
    SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13d71c: 0xc042c56  jal         func_10B158
    ctx->pc = 0x13D71Cu;
    SET_GPR_U32(ctx, 31, 0x13D724u);
    ctx->pc = 0x13D720u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D71Cu;
            // 0x13d720: 0x240202d  daddu       $a0, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B158u;
    if (runtime->hasFunction(0x10B158u)) {
        auto targetFn = runtime->lookupFunction(0x10B158u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D724u; }
        if (ctx->pc != 0x13D724u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D724u; }
        if (ctx->pc != 0x13D724u) { return; }
    }
    ctx->pc = 0x13D724u;
label_13d724:
    // 0x13d724: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x13d724u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d728: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x13d728u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d72c: 0x10c00009  beqz        $a2, . + 4 + (0x9 << 2)
    ctx->pc = 0x13D72Cu;
    {
        const bool branch_taken_0x13d72c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x13D730u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D72Cu;
            // 0x13d730: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d72c) {
            ctx->pc = 0x13D754u;
            goto label_13d754;
        }
    }
    ctx->pc = 0x13D734u;
    // 0x13d734: 0x0  nop
    ctx->pc = 0x13d734u;
    // NOP
label_13d738:
    // 0x13d738: 0x2451021  addu        $v0, $s2, $a1
    ctx->pc = 0x13d738u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
    // 0x13d73c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x13d73cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x13d740: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x13d740u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x13d744: 0xa6202b  sltu        $a0, $a1, $a2
    ctx->pc = 0x13d744u;
    SET_GPR_U64(ctx, 4, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x13d748: 0x0  nop
    ctx->pc = 0x13d748u;
    // NOP
    // 0x13d74c: 0x1480fffa  bnez        $a0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x13D74Cu;
    {
        const bool branch_taken_0x13d74c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x13D750u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D74Cu;
            // 0x13d750: 0xe33821  addu        $a3, $a3, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d74c) {
            ctx->pc = 0x13D738u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13d738;
        }
    }
    ctx->pc = 0x13D754u;
label_13d754:
    // 0x13d754: 0x8e220008  lw          $v0, 0x8($s1)
    ctx->pc = 0x13d754u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x13d758: 0x10e20009  beq         $a3, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x13D758u;
    {
        const bool branch_taken_0x13d758 = (GPR_U64(ctx, 7) == GPR_U64(ctx, 2));
        ctx->pc = 0x13D75Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D758u;
            // 0x13d75c: 0x3c040024  lui         $a0, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13d758) {
            ctx->pc = 0x13D780u;
            goto label_13d780;
        }
    }
    ctx->pc = 0x13D760u;
    // 0x13d760: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x13d760u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13d764: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13d764u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d768: 0x2484d458  addiu       $a0, $a0, -0x2BA8
    ctx->pc = 0x13d768u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294956120));
    // 0x13d76c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13d76cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13d770: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13d770u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13d774: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13d774u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13d778: 0x804f53e  j           func_13D4F8
    ctx->pc = 0x13D778u;
    ctx->pc = 0x13D77Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D778u;
            // 0x13d77c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D4F8u;
    if (runtime->hasFunction(0x13D4F8u)) {
        auto targetFn = runtime->lookupFunction(0x13D4F8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013D4F8_0x13d4f8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13D780u;
label_13d780:
    // 0x13d780: 0x8e270010  lw          $a3, 0x10($s1)
    ctx->pc = 0x13d780u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x13d784: 0x8e280014  lw          $t0, 0x14($s1)
    ctx->pc = 0x13d784u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x13d788: 0x8e26000c  lw          $a2, 0xC($s1)
    ctx->pc = 0x13d788u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x13d78c: 0x8e040028  lw          $a0, 0x28($s0)
    ctx->pc = 0x13d78cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x13d790: 0xc04c11e  jal         func_130478
    ctx->pc = 0x13D790u;
    SET_GPR_U32(ctx, 31, 0x13D798u);
    ctx->pc = 0x13D794u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D790u;
            // 0x13d794: 0x8e250004  lw          $a1, 0x4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130478u;
    if (runtime->hasFunction(0x130478u)) {
        auto targetFn = runtime->lookupFunction(0x130478u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D798u; }
        if (ctx->pc != 0x13D798u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130478_0x130478(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D798u; }
        if (ctx->pc != 0x13D798u) { return; }
    }
    ctx->pc = 0x13D798u;
label_13d798:
    // 0x13d798: 0x8e040028  lw          $a0, 0x28($s0)
    ctx->pc = 0x13d798u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x13d79c: 0xc04c1ea  jal         func_1307A8
    ctx->pc = 0x13D79Cu;
    SET_GPR_U32(ctx, 31, 0x13D7A4u);
    ctx->pc = 0x13D7A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D79Cu;
            // 0x13d7a0: 0x8e250014  lw          $a1, 0x14($s1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1307A8u;
    if (runtime->hasFunction(0x1307A8u)) {
        auto targetFn = runtime->lookupFunction(0x1307A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D7A4u; }
        if (ctx->pc != 0x13D7A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001307A8_0x1307a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D7A4u; }
        if (ctx->pc != 0x13D7A4u) { return; }
    }
    ctx->pc = 0x13D7A4u;
label_13d7a4:
    // 0x13d7a4: 0x8e220014  lw          $v0, 0x14($s1)
    ctx->pc = 0x13d7a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x13d7a8: 0x8e040028  lw          $a0, 0x28($s0)
    ctx->pc = 0x13d7a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x13d7ac: 0xae02002c  sw          $v0, 0x2C($s0)
    ctx->pc = 0x13d7acu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x13d7b0: 0xae20001c  sw          $zero, 0x1C($s1)
    ctx->pc = 0x13d7b0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 28), GPR_U32(ctx, 0));
    // 0x13d7b4: 0xa2000002  sb          $zero, 0x2($s0)
    ctx->pc = 0x13d7b4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x13d7b8: 0x8e060018  lw          $a2, 0x18($s0)
    ctx->pc = 0x13d7b8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x13d7bc: 0xc04c386  jal         func_130E18
    ctx->pc = 0x13D7BCu;
    SET_GPR_U32(ctx, 31, 0x13D7C4u);
    ctx->pc = 0x13D7C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D7BCu;
            // 0x13d7c0: 0x8e050014  lw          $a1, 0x14($s0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130E18u;
    if (runtime->hasFunction(0x130E18u)) {
        auto targetFn = runtime->lookupFunction(0x130E18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D7C4u; }
        if (ctx->pc != 0x13D7C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130E18_0x130e18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D7C4u; }
        if (ctx->pc != 0x13D7C4u) { return; }
    }
    ctx->pc = 0x13D7C4u;
label_13d7c4:
    // 0x13d7c4: 0x8e040028  lw          $a0, 0x28($s0)
    ctx->pc = 0x13d7c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x13d7c8: 0xc04c170  jal         func_1305C0
    ctx->pc = 0x13D7C8u;
    SET_GPR_U32(ctx, 31, 0x13D7D0u);
    ctx->pc = 0x13D7CCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D7C8u;
            // 0x13d7cc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1305C0u;
    if (runtime->hasFunction(0x1305C0u)) {
        auto targetFn = runtime->lookupFunction(0x1305C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D7D0u; }
        if (ctx->pc != 0x13D7D0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001305C0_0x1305c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D7D0u; }
        if (ctx->pc != 0x13D7D0u) { return; }
    }
    ctx->pc = 0x13D7D0u;
label_13d7d0:
    // 0x13d7d0: 0xc04c196  jal         func_130658
    ctx->pc = 0x13D7D0u;
    SET_GPR_U32(ctx, 31, 0x13D7D8u);
    ctx->pc = 0x13D7D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13D7D0u;
            // 0x13d7d4: 0x8e040028  lw          $a0, 0x28($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 40)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x130658u;
    if (runtime->hasFunction(0x130658u)) {
        auto targetFn = runtime->lookupFunction(0x130658u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D7D8u; }
        if (ctx->pc != 0x13D7D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00130658_0x130658(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D7D8u; }
        if (ctx->pc != 0x13D7D8u) { return; }
    }
    ctx->pc = 0x13D7D8u;
label_13d7d8:
    // 0x13d7d8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x13d7d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13d7dc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13d7dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13d7e0: 0xa2030002  sb          $v1, 0x2($s0)
    ctx->pc = 0x13d7e0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x13d7e4: 0xae220018  sw          $v0, 0x18($s1)
    ctx->pc = 0x13d7e4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 2));
label_13d7e8:
    // 0x13d7e8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13d7e8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d7ec: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13d7ecu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13d7f0: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13d7f0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13d7f4: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13d7f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13d7f8: 0x3e00008  jr          $ra
    ctx->pc = 0x13D7F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D7FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13D7F8u;
            // 0x13d7fc: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D658u: goto label_13d658;
            case 0x13D66Cu: goto label_13d66c;
            case 0x13D670u: goto label_13d670;
            case 0x13D688u: goto label_13d688;
            case 0x13D690u: goto label_13d690;
            case 0x13D6B8u: goto label_13d6b8;
            case 0x13D710u: goto label_13d710;
            case 0x13D718u: goto label_13d718;
            case 0x13D724u: goto label_13d724;
            case 0x13D738u: goto label_13d738;
            case 0x13D754u: goto label_13d754;
            case 0x13D780u: goto label_13d780;
            case 0x13D798u: goto label_13d798;
            case 0x13D7A4u: goto label_13d7a4;
            case 0x13D7C4u: goto label_13d7c4;
            case 0x13D7D0u: goto label_13d7d0;
            case 0x13D7D8u: goto label_13d7d8;
            case 0x13D7E8u: goto label_13d7e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D800u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
