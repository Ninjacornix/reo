#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F590
// Address: 0x13f590 - 0x13f628
void sub_0013F590_0x13f590(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F590_0x13f590");
#endif

    switch (ctx->pc) {
        case 0x13f5ccu: goto label_13f5cc;
        case 0x13f5f8u: goto label_13f5f8;
        default: break;
    }

    ctx->pc = 0x13f590u;

    // 0x13f590: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x13f590u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13f594: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13f594u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13f598: 0xc0802d  daddu       $s0, $a2, $zero
    ctx->pc = 0x13f598u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f59c: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13f59cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13f5a0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x13f5a0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13f5a4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13f5a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13f5a8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x13f5a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x13f5ac: 0x8e020004  lw          $v0, 0x4($s0)
    ctx->pc = 0x13f5acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x13f5b0: 0x18400017  blez        $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x13F5B0u;
    {
        const bool branch_taken_0x13f5b0 = (GPR_S64(ctx, 2) <= 0);
        ctx->pc = 0x13F5B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F5B0u;
            // 0x13f5b4: 0x80902d  daddu       $s2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f5b0) {
            ctx->pc = 0x13F610u;
            goto label_13f610;
        }
    }
    ctx->pc = 0x13F5B8u;
    // 0x13f5b8: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x13f5b8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13f5bc: 0x50400015  beql        $v0, $zero, . + 4 + (0x15 << 2)
    ctx->pc = 0x13F5BCu;
    {
        const bool branch_taken_0x13f5bc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x13f5bc) {
            ctx->pc = 0x13F5C0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13F5BCu;
            // 0x13f5c0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13F614u;
            goto label_13f614;
        }
    }
    ctx->pc = 0x13F5C4u;
    // 0x13f5c4: 0xc04fc96  jal         func_13F258
    ctx->pc = 0x13F5C4u;
    SET_GPR_U32(ctx, 31, 0x13F5CCu);
    ctx->pc = 0x13F258u;
    if (runtime->hasFunction(0x13F258u)) {
        auto targetFn = runtime->lookupFunction(0x13F258u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F5CCu; }
        if (ctx->pc != 0x13F5CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013F258_0x13f258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13F5CCu; }
        if (ctx->pc != 0x13F5CCu) { return; }
    }
    ctx->pc = 0x13F5CCu;
label_13f5cc:
    // 0x13f5cc: 0x1220000a  beqz        $s1, . + 4 + (0xA << 2)
    ctx->pc = 0x13F5CCu;
    {
        const bool branch_taken_0x13f5cc = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F5D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F5CCu;
            // 0x13f5d0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f5cc) {
            ctx->pc = 0x13F5F8u;
            goto label_13f5f8;
        }
    }
    ctx->pc = 0x13F5D4u;
    // 0x13f5d4: 0x52220009  beql        $s1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x13F5D4u;
    {
        const bool branch_taken_0x13f5d4 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        if (branch_taken_0x13f5d4) {
            ctx->pc = 0x13F5D8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13F5D4u;
            // 0x13f5d8: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13F5FCu;
            goto label_13f5fc;
        }
    }
    ctx->pc = 0x13F5DCu;
    // 0x13f5dc: 0x8e42001c  lw          $v0, 0x1C($s2)
    ctx->pc = 0x13f5dcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 28)));
    // 0x13f5e0: 0xae000000  sw          $zero, 0x0($s0)
    ctx->pc = 0x13f5e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x13f5e4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x13F5E4u;
    {
        const bool branch_taken_0x13f5e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13F5E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F5E4u;
            // 0x13f5e8: 0xae000004  sw          $zero, 0x4($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13f5e4) {
            ctx->pc = 0x13F5F8u;
            goto label_13f5f8;
        }
    }
    ctx->pc = 0x13F5ECu;
    // 0x13f5ec: 0x8e440020  lw          $a0, 0x20($s2)
    ctx->pc = 0x13f5ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 32)));
    // 0x13f5f0: 0x40f809  jalr        $v0
    ctx->pc = 0x13F5F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13F5F8u);
        ctx->pc = 0x13F5F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F5F0u;
            // 0x13f5f4: 0x2405fffd  addiu       $a1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13F5F8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F5CCu: goto label_13f5cc;
            case 0x13F5F8u: goto label_13f5f8;
            case 0x13F5FCu: goto label_13f5fc;
            case 0x13F610u: goto label_13f610;
            case 0x13F614u: goto label_13f614;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13F5F8u; }
            if (ctx->pc != 0x13F5F8u) { return; }
        }
        }
    }
    ctx->pc = 0x13F5F8u;
label_13f5f8:
    // 0x13f5f8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13f5f8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13f5fc:
    // 0x13f5fc: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13f5fcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13f600: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13f600u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13f604: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13f604u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13f608: 0x804fc9c  j           func_13F270
    ctx->pc = 0x13F608u;
    ctx->pc = 0x13F60Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13F608u;
            // 0x13f60c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13F270u;
    if (runtime->hasFunction(0x13F270u)) {
        auto targetFn = runtime->lookupFunction(0x13F270u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013F270_0x13f270(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13F610u;
label_13f610:
    // 0x13f610: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13f610u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_13f614:
    // 0x13f614: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13f614u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13f618: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13f618u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13f61c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x13f61cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13f620: 0x3e00008  jr          $ra
    ctx->pc = 0x13F620u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F624u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F620u;
            // 0x13f624: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13F5CCu: goto label_13f5cc;
            case 0x13F5F8u: goto label_13f5f8;
            case 0x13F5FCu: goto label_13f5fc;
            case 0x13F610u: goto label_13f610;
            case 0x13F614u: goto label_13f614;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13F628u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
