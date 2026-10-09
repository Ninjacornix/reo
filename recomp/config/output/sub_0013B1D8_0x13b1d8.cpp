#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013B1D8
// Address: 0x13b1d8 - 0x13b330
void sub_0013B1D8_0x13b1d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013B1D8_0x13b1d8");
#endif

    switch (ctx->pc) {
        case 0x13b1fcu: goto label_13b1fc;
        case 0x13b210u: goto label_13b210;
        case 0x13b224u: goto label_13b224;
        case 0x13b28cu: goto label_13b28c;
        case 0x13b2acu: goto label_13b2ac;
        case 0x13b2b4u: goto label_13b2b4;
        case 0x13b2c0u: goto label_13b2c0;
        case 0x13b2ccu: goto label_13b2cc;
        case 0x13b2e0u: goto label_13b2e0;
        case 0x13b2e8u: goto label_13b2e8;
        case 0x13b2f0u: goto label_13b2f0;
        case 0x13b318u: goto label_13b318;
        default: break;
    }

    ctx->pc = 0x13b1d8u;

    // 0x13b1d8: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13b1d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13b1dc: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x13b1dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x13b1e0: 0x3c130022  lui         $s3, 0x22
    ctx->pc = 0x13b1e0u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)34 << 16));
    // 0x13b1e4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13b1e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13b1e8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x13b1e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13b1ec: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x13b1ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13b1f0: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x13b1f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x13b1f4: 0xc050864  jal         func_142190
    ctx->pc = 0x13B1F4u;
    SET_GPR_U32(ctx, 31, 0x13B1FCu);
    ctx->pc = 0x13B1F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B1F4u;
            // 0x13b1f8: 0x2664da84  addiu       $a0, $s3, -0x257C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 19), 4294957700));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142190u;
    if (runtime->hasFunction(0x142190u)) {
        auto targetFn = runtime->lookupFunction(0x142190u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B1FCu; }
        if (ctx->pc != 0x13B1FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142190_0x142190(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B1FCu; }
        if (ctx->pc != 0x13B1FCu) { return; }
    }
    ctx->pc = 0x13B1FCu;
label_13b1fc:
    // 0x13b1fc: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x13B1FCu;
    {
        const bool branch_taken_0x13b1fc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B1FCu;
            // 0x13b200: 0x3c020022  lui         $v0, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b1fc) {
            ctx->pc = 0x13B234u;
            goto label_13b234;
        }
    }
    ctx->pc = 0x13B204u;
    // 0x13b204: 0x24120001  addiu       $s2, $zero, 0x1
    ctx->pc = 0x13b204u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x13b208: 0x2450daf0  addiu       $s0, $v0, -0x2510
    ctx->pc = 0x13b208u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294957808));
    // 0x13b20c: 0x2411000c  addiu       $s1, $zero, 0xC
    ctx->pc = 0x13b20cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
label_13b210:
    // 0x13b210: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x13b210u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x13b214: 0x54520004  bnel        $v0, $s2, . + 4 + (0x4 << 2)
    ctx->pc = 0x13B214u;
    {
        const bool branch_taken_0x13b214 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 18));
        if (branch_taken_0x13b214) {
            ctx->pc = 0x13B218u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x13B214u;
            // 0x13b218: 0x2631ffff  addiu       $s1, $s1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x13B228u;
            goto label_13b228;
        }
    }
    ctx->pc = 0x13B21Cu;
    // 0x13b21c: 0xc04ec44  jal         func_13B110
    ctx->pc = 0x13B21Cu;
    SET_GPR_U32(ctx, 31, 0x13B224u);
    ctx->pc = 0x13B220u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B21Cu;
            // 0x13b220: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13B110u;
    if (runtime->hasFunction(0x13B110u)) {
        auto targetFn = runtime->lookupFunction(0x13B110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B224u; }
        if (ctx->pc != 0x13B224u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013B110_0x13b110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B224u; }
        if (ctx->pc != 0x13B224u) { return; }
    }
    ctx->pc = 0x13B224u;
label_13b224:
    // 0x13b224: 0x2631ffff  addiu       $s1, $s1, -0x1
    ctx->pc = 0x13b224u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967295));
label_13b228:
    // 0x13b228: 0x621fff9  bgez        $s1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x13B228u;
    {
        const bool branch_taken_0x13b228 = (GPR_S64(ctx, 17) >= 0);
        ctx->pc = 0x13B22Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B228u;
            // 0x13b22c: 0x26100030  addiu       $s0, $s0, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 48));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b228) {
            ctx->pc = 0x13B210u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_13b210;
        }
    }
    ctx->pc = 0x13B230u;
    // 0x13b230: 0xae60da84  sw          $zero, -0x257C($s3)
    ctx->pc = 0x13b230u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4294957700), GPR_U32(ctx, 0));
label_13b234:
    // 0x13b234: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x13b234u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13b238: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x13b238u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13b23c: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x13b23cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13b240: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x13b240u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13b244: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x13b244u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13b248: 0x3e00008  jr          $ra
    ctx->pc = 0x13B248u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13B24Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B248u;
            // 0x13b24c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13B1FCu: goto label_13b1fc;
            case 0x13B210u: goto label_13b210;
            case 0x13B224u: goto label_13b224;
            case 0x13B228u: goto label_13b228;
            case 0x13B234u: goto label_13b234;
            case 0x13B28Cu: goto label_13b28c;
            case 0x13B2ACu: goto label_13b2ac;
            case 0x13B2B4u: goto label_13b2b4;
            case 0x13B2C0u: goto label_13b2c0;
            case 0x13B2CCu: goto label_13b2cc;
            case 0x13B2E0u: goto label_13b2e0;
            case 0x13B2E8u: goto label_13b2e8;
            case 0x13B2F0u: goto label_13b2f0;
            case 0x13B2F4u: goto label_13b2f4;
            case 0x13B318u: goto label_13b318;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13B250u;
    // 0x13b250: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13b250u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13b254: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x13b254u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x13b258: 0xac44da7c  sw          $a0, -0x2584($v0)
    ctx->pc = 0x13b258u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294957692), GPR_U32(ctx, 4));
    // 0x13b25c: 0x3e00008  jr          $ra
    ctx->pc = 0x13B25Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13B260u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B25Cu;
            // 0x13b260: 0xac65da80  sw          $a1, -0x2580($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294957696), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13B1FCu: goto label_13b1fc;
            case 0x13B210u: goto label_13b210;
            case 0x13B224u: goto label_13b224;
            case 0x13B228u: goto label_13b228;
            case 0x13B234u: goto label_13b234;
            case 0x13B28Cu: goto label_13b28c;
            case 0x13B2ACu: goto label_13b2ac;
            case 0x13B2B4u: goto label_13b2b4;
            case 0x13B2C0u: goto label_13b2c0;
            case 0x13B2CCu: goto label_13b2cc;
            case 0x13B2E0u: goto label_13b2e0;
            case 0x13B2E8u: goto label_13b2e8;
            case 0x13B2F0u: goto label_13b2f0;
            case 0x13B2F4u: goto label_13b2f4;
            case 0x13B318u: goto label_13b318;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13B264u;
    // 0x13b264: 0x0  nop
    ctx->pc = 0x13b264u;
    // NOP
    // 0x13b268: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x13b268u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x13b26c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x13b26cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b270: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x13b270u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x13b274: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x13b274u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b278: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x13b278u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x13b27c: 0x1200001d  beqz        $s0, . + 4 + (0x1D << 2)
    ctx->pc = 0x13B27Cu;
    {
        const bool branch_taken_0x13b27c = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x13B280u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B27Cu;
            // 0x13b280: 0xffbf0020  sd          $ra, 0x20($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b27c) {
            ctx->pc = 0x13B2F4u;
            goto label_13b2f4;
        }
    }
    ctx->pc = 0x13B284u;
    // 0x13b284: 0xc04f1fa  jal         func_13C7E8
    ctx->pc = 0x13B284u;
    SET_GPR_U32(ctx, 31, 0x13B28Cu);
    ctx->pc = 0x13B288u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B284u;
            // 0x13b288: 0x3a0282d  daddu       $a1, $sp, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13C7E8u;
    if (runtime->hasFunction(0x13C7E8u)) {
        auto targetFn = runtime->lookupFunction(0x13C7E8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B28Cu; }
        if (ctx->pc != 0x13B28Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013C7E8_0x13c7e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B28Cu; }
        if (ctx->pc != 0x13B28Cu) { return; }
    }
    ctx->pc = 0x13B28Cu;
label_13b28c:
    // 0x13b28c: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13b28cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13b290: 0x2451dd60  addiu       $s1, $v0, -0x22A0
    ctx->pc = 0x13b290u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 2), 4294958432));
    // 0x13b294: 0x8fa20004  lw          $v0, 0x4($sp)
    ctx->pc = 0x13b294u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x13b298: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x13b298u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b29c: 0x14400014  bnez        $v0, . + 4 + (0x14 << 2)
    ctx->pc = 0x13B29Cu;
    {
        const bool branch_taken_0x13b29c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x13B2A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B29Cu;
            // 0x13b2a0: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b29c) {
            ctx->pc = 0x13B2F0u;
            goto label_13b2f0;
        }
    }
    ctx->pc = 0x13B2A4u;
    // 0x13b2a4: 0xc04efa0  jal         func_13BE80
    ctx->pc = 0x13B2A4u;
    SET_GPR_U32(ctx, 31, 0x13B2ACu);
    ctx->pc = 0x13BE80u;
    if (runtime->hasFunction(0x13BE80u)) {
        auto targetFn = runtime->lookupFunction(0x13BE80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2ACu; }
        if (ctx->pc != 0x13B2ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013BE80_0x13be80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2ACu; }
        if (ctx->pc != 0x13B2ACu) { return; }
    }
    ctx->pc = 0x13B2ACu;
label_13b2ac:
    // 0x13b2ac: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B2ACu;
    SET_GPR_U32(ctx, 31, 0x13B2B4u);
    ctx->pc = 0x13B2B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B2ACu;
            // 0x13b2b0: 0x24044200  addiu       $a0, $zero, 0x4200 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16896));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2B4u; }
        if (ctx->pc != 0x13B2B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2B4u; }
        if (ctx->pc != 0x13B2B4u) { return; }
    }
    ctx->pc = 0x13B2B4u;
label_13b2b4:
    // 0x13b2b4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x13b2b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13b2b8: 0xc04e146  jal         func_138518
    ctx->pc = 0x13B2B8u;
    SET_GPR_U32(ctx, 31, 0x13B2C0u);
    ctx->pc = 0x13B2BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B2B8u;
            // 0x13b2bc: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138518u;
    if (runtime->hasFunction(0x138518u)) {
        auto targetFn = runtime->lookupFunction(0x138518u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2C0u; }
        if (ctx->pc != 0x13B2C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138518_0x138518(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2C0u; }
        if (ctx->pc != 0x13B2C0u) { return; }
    }
    ctx->pc = 0x13B2C0u;
label_13b2c0:
    // 0x13b2c0: 0x24044201  addiu       $a0, $zero, 0x4201
    ctx->pc = 0x13b2c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16897));
    // 0x13b2c4: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B2C4u;
    SET_GPR_U32(ctx, 31, 0x13B2CCu);
    ctx->pc = 0x13B2C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B2C4u;
            // 0x13b2c8: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2CCu; }
        if (ctx->pc != 0x13B2CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2CCu; }
        if (ctx->pc != 0x13B2CCu) { return; }
    }
    ctx->pc = 0x13B2CCu;
label_13b2cc:
    // 0x13b2cc: 0x24044300  addiu       $a0, $zero, 0x4300
    ctx->pc = 0x13b2ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17152));
    // 0x13b2d0: 0x6000008  bltz        $s0, . + 4 + (0x8 << 2)
    ctx->pc = 0x13B2D0u;
    {
        const bool branch_taken_0x13b2d0 = (GPR_S64(ctx, 16) < 0);
        ctx->pc = 0x13B2D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B2D0u;
            // 0x13b2d4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13b2d0) {
            ctx->pc = 0x13B2F4u;
            goto label_13b2f4;
        }
    }
    ctx->pc = 0x13B2D8u;
    // 0x13b2d8: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B2D8u;
    SET_GPR_U32(ctx, 31, 0x13B2E0u);
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2E0u; }
        if (ctx->pc != 0x13B2E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2E0u; }
        if (ctx->pc != 0x13B2E0u) { return; }
    }
    ctx->pc = 0x13B2E0u;
label_13b2e0:
    // 0x13b2e0: 0xc04e160  jal         func_138580
    ctx->pc = 0x13B2E0u;
    SET_GPR_U32(ctx, 31, 0x13B2E8u);
    ctx->pc = 0x13B2E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B2E0u;
            // 0x13b2e4: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138580u;
    if (runtime->hasFunction(0x138580u)) {
        auto targetFn = runtime->lookupFunction(0x138580u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2E8u; }
        if (ctx->pc != 0x13B2E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138580_0x138580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2E8u; }
        if (ctx->pc != 0x13B2E8u) { return; }
    }
    ctx->pc = 0x13B2E8u;
label_13b2e8:
    // 0x13b2e8: 0xc04e082  jal         func_138208
    ctx->pc = 0x13B2E8u;
    SET_GPR_U32(ctx, 31, 0x13B2F0u);
    ctx->pc = 0x13B2ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13B2E8u;
            // 0x13b2ec: 0x24044301  addiu       $a0, $zero, 0x4301 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 17153));
        ctx->in_delay_slot = false;
    ctx->pc = 0x138208u;
    if (runtime->hasFunction(0x138208u)) {
        auto targetFn = runtime->lookupFunction(0x138208u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2F0u; }
        if (ctx->pc != 0x13B2F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B2F0u; }
        if (ctx->pc != 0x13B2F0u) { return; }
    }
    ctx->pc = 0x13B2F0u;
label_13b2f0:
    // 0x13b2f0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x13b2f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_13b2f4:
    // 0x13b2f4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x13b2f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13b2f8: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x13b2f8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13b2fc: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x13b2fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13b300: 0x3e00008  jr          $ra
    ctx->pc = 0x13B300u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13B304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B300u;
            // 0x13b304: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13B1FCu: goto label_13b1fc;
            case 0x13B210u: goto label_13b210;
            case 0x13B224u: goto label_13b224;
            case 0x13B228u: goto label_13b228;
            case 0x13B234u: goto label_13b234;
            case 0x13B28Cu: goto label_13b28c;
            case 0x13B2ACu: goto label_13b2ac;
            case 0x13B2B4u: goto label_13b2b4;
            case 0x13B2C0u: goto label_13b2c0;
            case 0x13B2CCu: goto label_13b2cc;
            case 0x13B2E0u: goto label_13b2e0;
            case 0x13B2E8u: goto label_13b2e8;
            case 0x13B2F0u: goto label_13b2f0;
            case 0x13B2F4u: goto label_13b2f4;
            case 0x13B318u: goto label_13b318;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13B308u;
    // 0x13b308: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13b308u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13b30c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13b30cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13b310: 0xc04eccc  jal         func_13B330
    ctx->pc = 0x13B310u;
    SET_GPR_U32(ctx, 31, 0x13B318u);
    ctx->pc = 0x13B330u;
    if (runtime->hasFunction(0x13B330u)) {
        auto targetFn = runtime->lookupFunction(0x13B330u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B318u; }
        if (ctx->pc != 0x13B318u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013B330_0x13b330(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13B318u; }
        if (ctx->pc != 0x13B318u) { return; }
    }
    ctx->pc = 0x13B318u;
label_13b318:
    // 0x13b318: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13b318u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13b31c: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x13b31cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x13b320: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x13b320u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x13b324: 0x3e00008  jr          $ra
    ctx->pc = 0x13B324u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13B328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13B324u;
            // 0x13b328: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13B1FCu: goto label_13b1fc;
            case 0x13B210u: goto label_13b210;
            case 0x13B224u: goto label_13b224;
            case 0x13B228u: goto label_13b228;
            case 0x13B234u: goto label_13b234;
            case 0x13B28Cu: goto label_13b28c;
            case 0x13B2ACu: goto label_13b2ac;
            case 0x13B2B4u: goto label_13b2b4;
            case 0x13B2C0u: goto label_13b2c0;
            case 0x13B2CCu: goto label_13b2cc;
            case 0x13B2E0u: goto label_13b2e0;
            case 0x13B2E8u: goto label_13b2e8;
            case 0x13B2F0u: goto label_13b2f0;
            case 0x13B2F4u: goto label_13b2f4;
            case 0x13B318u: goto label_13b318;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13B32Cu;
    // 0x13b32c: 0x0  nop
    ctx->pc = 0x13b32cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
