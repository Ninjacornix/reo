#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001672E0
// Address: 0x1672e0 - 0x1673d8
void sub_001672E0_0x1672e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001672E0_0x1672e0");
#endif

    switch (ctx->pc) {
        case 0x167318u: goto label_167318;
        case 0x16733cu: goto label_16733c;
        case 0x16736cu: goto label_16736c;
        case 0x167384u: goto label_167384;
        case 0x1673b0u: goto label_1673b0;
        default: break;
    }

    ctx->pc = 0x1672e0u;

    // 0x1672e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1672e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1672e4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1672e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1672e8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1672e8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1672ec: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1672ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1672f0: 0xe0882d  daddu       $s1, $a3, $zero
    ctx->pc = 0x1672f0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1672f4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1672f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1672f8: 0xa0902d  daddu       $s2, $a1, $zero
    ctx->pc = 0x1672f8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1672fc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1672fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x167300: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x167300u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x167304: 0xffbf0028  sd          $ra, 0x28($sp)
    ctx->pc = 0x167304u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x167308: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x167308u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x16730c: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x16730cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x167310: 0x40f809  jalr        $v0
    ctx->pc = 0x167310u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x167318u);
        ctx->pc = 0x167314u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167310u;
            // 0x167314: 0xc0982d  daddu       $s3, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x167318u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167318u: goto label_167318;
            case 0x16733Cu: goto label_16733c;
            case 0x16736Cu: goto label_16736c;
            case 0x167384u: goto label_167384;
            case 0x167390u: goto label_167390;
            case 0x16739Cu: goto label_16739c;
            case 0x1673B0u: goto label_1673b0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x167318u; }
            if (ctx->pc != 0x167318u) { return; }
        }
        }
    }
    ctx->pc = 0x167318u;
label_167318:
    // 0x167318: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x167318u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x16731c: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x16731cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167320: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x167320u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x167324: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x167324u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167328: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x167328u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16732c: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x16732cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x167330: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x167330u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x167334: 0x60f809  jalr        $v1
    ctx->pc = 0x167334u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x16733Cu);
        ctx->pc = 0x167338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167334u;
            // 0x167338: 0x260382d  daddu       $a3, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x16733Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167318u: goto label_167318;
            case 0x16733Cu: goto label_16733c;
            case 0x16736Cu: goto label_16736c;
            case 0x167384u: goto label_167384;
            case 0x167390u: goto label_167390;
            case 0x16739Cu: goto label_16739c;
            case 0x1673B0u: goto label_1673b0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16733Cu; }
            if (ctx->pc != 0x16733Cu) { return; }
        }
        }
    }
    ctx->pc = 0x16733Cu;
label_16733c:
    // 0x16733c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16733cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167340: 0x8e620004  lw          $v0, 0x4($s3)
    ctx->pc = 0x167340u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 19), 4)));
    // 0x167344: 0x3c067fff  lui         $a2, 0x7FFF
    ctx->pc = 0x167344u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)32767 << 16));
    // 0x167348: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x167348u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16734c: 0x34c6ffff  ori         $a2, $a2, 0xFFFF
    ctx->pc = 0x16734cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)65535);
    // 0x167350: 0x54102a  slt         $v0, $v0, $s4
    ctx->pc = 0x167350u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 20)) ? 1 : 0);
    // 0x167354: 0x1040000e  beqz        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x167354u;
    {
        const bool branch_taken_0x167354 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x167358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167354u;
            // 0x167358: 0x220382d  daddu       $a3, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167354) {
            ctx->pc = 0x167390u;
            goto label_167390;
        }
    }
    ctx->pc = 0x16735Cu;
    // 0x16735c: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x16735cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x167360: 0x8c430018  lw          $v1, 0x18($v0)
    ctx->pc = 0x167360u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 24)));
    // 0x167364: 0x60f809  jalr        $v1
    ctx->pc = 0x167364u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x16736Cu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x16736Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167318u: goto label_167318;
            case 0x16733Cu: goto label_16733c;
            case 0x16736Cu: goto label_16736c;
            case 0x167384u: goto label_167384;
            case 0x167390u: goto label_167390;
            case 0x16739Cu: goto label_16739c;
            case 0x1673B0u: goto label_1673b0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16736Cu; }
            if (ctx->pc != 0x16736Cu) { return; }
        }
        }
    }
    ctx->pc = 0x16736Cu;
label_16736c:
    // 0x16736c: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x16736cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x167370: 0x220302d  daddu       $a2, $s1, $zero
    ctx->pc = 0x167370u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167374: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x167374u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x167378: 0x8ca2001c  lw          $v0, 0x1C($a1)
    ctx->pc = 0x167378u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 28)));
    // 0x16737c: 0x40f809  jalr        $v0
    ctx->pc = 0x16737Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x167384u);
        ctx->pc = 0x167380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16737Cu;
            // 0x167380: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x167384u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167318u: goto label_167318;
            case 0x16733Cu: goto label_16733c;
            case 0x16736Cu: goto label_16736c;
            case 0x167384u: goto label_167384;
            case 0x167390u: goto label_167390;
            case 0x16739Cu: goto label_16739c;
            case 0x1673B0u: goto label_1673b0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x167384u; }
            if (ctx->pc != 0x167384u) { return; }
        }
        }
    }
    ctx->pc = 0x167384u;
label_167384:
    // 0x167384: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x167384u;
    {
        const bool branch_taken_0x167384 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x167388u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x167384u;
            // 0x167388: 0x8e030000  lw          $v1, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x167384) {
            ctx->pc = 0x16739Cu;
            goto label_16739c;
        }
    }
    ctx->pc = 0x16738Cu;
    // 0x16738c: 0x0  nop
    ctx->pc = 0x16738cu;
    // NOP
label_167390:
    // 0x167390: 0xae200004  sw          $zero, 0x4($s1)
    ctx->pc = 0x167390u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
    // 0x167394: 0xae200000  sw          $zero, 0x0($s1)
    ctx->pc = 0x167394u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x167398: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x167398u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_16739c:
    // 0x16739c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16739cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1673a0: 0x240282d  daddu       $a1, $s2, $zero
    ctx->pc = 0x1673a0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1673a4: 0x8c62001c  lw          $v0, 0x1C($v1)
    ctx->pc = 0x1673a4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 28)));
    // 0x1673a8: 0x40f809  jalr        $v0
    ctx->pc = 0x1673A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1673B0u);
        ctx->pc = 0x1673ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1673A8u;
            // 0x1673ac: 0x260302d  daddu       $a2, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1673B0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167318u: goto label_167318;
            case 0x16733Cu: goto label_16733c;
            case 0x16736Cu: goto label_16736c;
            case 0x167384u: goto label_167384;
            case 0x167390u: goto label_167390;
            case 0x16739Cu: goto label_16739c;
            case 0x1673B0u: goto label_1673b0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1673B0u; }
            if (ctx->pc != 0x1673B0u) { return; }
        }
        }
    }
    ctx->pc = 0x1673B0u;
label_1673b0:
    // 0x1673b0: 0x280102d  daddu       $v0, $s4, $zero
    ctx->pc = 0x1673b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1673b4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1673b4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1673b8: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1673b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1673bc: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1673bcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1673c0: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x1673c0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1673c4: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x1673c4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1673c8: 0xdfbf0028  ld          $ra, 0x28($sp)
    ctx->pc = 0x1673c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1673cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1673CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1673D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1673CCu;
            // 0x1673d0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x167318u: goto label_167318;
            case 0x16733Cu: goto label_16733c;
            case 0x16736Cu: goto label_16736c;
            case 0x167384u: goto label_167384;
            case 0x167390u: goto label_167390;
            case 0x16739Cu: goto label_16739c;
            case 0x1673B0u: goto label_1673b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1673D4u;
    // 0x1673d4: 0x0  nop
    ctx->pc = 0x1673d4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
