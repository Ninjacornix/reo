#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016E230
// Address: 0x16e230 - 0x16e360
void sub_0016E230_0x16e230(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016E230_0x16e230");
#endif

    switch (ctx->pc) {
        case 0x16e284u: goto label_16e284;
        case 0x16e29cu: goto label_16e29c;
        case 0x16e2b8u: goto label_16e2b8;
        case 0x16e2c4u: goto label_16e2c4;
        case 0x16e2e0u: goto label_16e2e0;
        case 0x16e318u: goto label_16e318;
        case 0x16e32cu: goto label_16e32c;
        case 0x16e338u: goto label_16e338;
        default: break;
    }

    ctx->pc = 0x16e230u;

    // 0x16e230: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x16e230u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x16e234: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x16e234u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e238: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x16e238u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x16e23c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x16e23cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e240: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x16e240u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x16e244: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x16e244u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e248: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x16e248u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x16e24c: 0x2612090c  addiu       $s2, $s0, 0x90C
    ctx->pc = 0x16e24cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 2316));
    // 0x16e250: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x16e250u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x16e254: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x16e254u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e258: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x16e258u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x16e25c: 0xc0a82d  daddu       $s5, $a2, $zero
    ctx->pc = 0x16e25cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e260: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x16e260u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x16e264: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x16e264u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e268: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x16e268u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x16e26c: 0x3a0282d  daddu       $a1, $sp, $zero
    ctx->pc = 0x16e26cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e270: 0x8e430010  lw          $v1, 0x10($s2)
    ctx->pc = 0x16e270u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x16e274: 0x14600030  bnez        $v1, . + 4 + (0x30 << 2)
    ctx->pc = 0x16E274u;
    {
        const bool branch_taken_0x16e274 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x16E278u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E274u;
            // 0x16e278: 0x8e131b30  lw          $s3, 0x1B30($s0) (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 6960)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e274) {
            ctx->pc = 0x16E338u;
            goto label_16e338;
        }
    }
    ctx->pc = 0x16E27Cu;
    // 0x16e27c: 0xc0564c6  jal         func_159318
    ctx->pc = 0x16E27Cu;
    SET_GPR_U32(ctx, 31, 0x16E284u);
    ctx->pc = 0x159318u;
    if (runtime->hasFunction(0x159318u)) {
        auto targetFn = runtime->lookupFunction(0x159318u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E284u; }
        if (ctx->pc != 0x16E284u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00159318_0x159318(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E284u; }
        if (ctx->pc != 0x16E284u) { return; }
    }
    ctx->pc = 0x16E284u;
label_16e284:
    // 0x16e284: 0x10400008  beqz        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x16E284u;
    {
        const bool branch_taken_0x16e284 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16E288u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E284u;
            // 0x16e288: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e284) {
            ctx->pc = 0x16E2A8u;
            goto label_16e2a8;
        }
    }
    ctx->pc = 0x16E28Cu;
    // 0x16e28c: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16e28cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16e290: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16e290u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e294: 0xc05a704  jal         func_169C10
    ctx->pc = 0x16E294u;
    SET_GPR_U32(ctx, 31, 0x16E29Cu);
    ctx->pc = 0x16E298u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E294u;
            // 0x16e298: 0x34a50f16  ori         $a1, $a1, 0xF16 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3862);
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E29Cu; }
        if (ctx->pc != 0x16E29Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E29Cu; }
        if (ctx->pc != 0x16E29Cu) { return; }
    }
    ctx->pc = 0x16E29Cu;
label_16e29c:
    // 0x16e29c: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x16E29Cu;
    {
        const bool branch_taken_0x16e29c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16E2A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E29Cu;
            // 0x16e2a0: 0xdfb00010  ld          $s0, 0x10($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e29c) {
            ctx->pc = 0x16E33Cu;
            goto label_16e33c;
        }
    }
    ctx->pc = 0x16E2A4u;
    // 0x16e2a4: 0x0  nop
    ctx->pc = 0x16e2a4u;
    // NOP
label_16e2a8:
    // 0x16e2a8: 0x27a50004  addiu       $a1, $sp, 0x4
    ctx->pc = 0x16e2a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x16e2ac: 0x27a60008  addiu       $a2, $sp, 0x8
    ctx->pc = 0x16e2acu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
    // 0x16e2b0: 0xc0564de  jal         func_159378
    ctx->pc = 0x16E2B0u;
    SET_GPR_U32(ctx, 31, 0x16E2B8u);
    ctx->pc = 0x16E2B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E2B0u;
            // 0x16e2b4: 0x27a7000c  addiu       $a3, $sp, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 12));
        ctx->in_delay_slot = false;
    ctx->pc = 0x159378u;
    if (runtime->hasFunction(0x159378u)) {
        auto targetFn = runtime->lookupFunction(0x159378u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E2B8u; }
        if (ctx->pc != 0x16E2B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00159378_0x159378(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E2B8u; }
        if (ctx->pc != 0x16E2B8u) { return; }
    }
    ctx->pc = 0x16E2B8u;
label_16e2b8:
    // 0x16e2b8: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16e2b8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e2bc: 0xc05d58a  jal         func_175628
    ctx->pc = 0x16E2BCu;
    SET_GPR_U32(ctx, 31, 0x16E2C4u);
    ctx->pc = 0x16E2C0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E2BCu;
            // 0x16e2c0: 0x2405003c  addiu       $a1, $zero, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E2C4u; }
        if (ctx->pc != 0x16E2C4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E2C4u; }
        if (ctx->pc != 0x16E2C4u) { return; }
    }
    ctx->pc = 0x16E2C4u;
label_16e2c4:
    // 0x16e2c4: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16e2c4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e2c8: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x16E2C8u;
    {
        const bool branch_taken_0x16e2c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x16E2CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E2C8u;
            // 0x16e2cc: 0x24050001  addiu       $a1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e2c8) {
            ctx->pc = 0x16E2D8u;
            goto label_16e2d8;
        }
    }
    ctx->pc = 0x16E2D0u;
    // 0x16e2d0: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x16E2D0u;
    {
        const bool branch_taken_0x16e2d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x16E2D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E2D0u;
            // 0x16e2d4: 0xae6000e8  sw          $zero, 0xE8($s3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 19), 232), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e2d0) {
            ctx->pc = 0x16E308u;
            goto label_16e308;
        }
    }
    ctx->pc = 0x16E2D8u;
label_16e2d8:
    // 0x16e2d8: 0xc059d42  jal         func_167508
    ctx->pc = 0x16E2D8u;
    SET_GPR_U32(ctx, 31, 0x16E2E0u);
    ctx->pc = 0x167508u;
    if (runtime->hasFunction(0x167508u)) {
        auto targetFn = runtime->lookupFunction(0x167508u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E2E0u; }
        if (ctx->pc != 0x16E2E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00167508_0x167508(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E2E0u; }
        if (ctx->pc != 0x16E2E0u) { return; }
    }
    ctx->pc = 0x16E2E0u;
label_16e2e0:
    // 0x16e2e0: 0x8fa3000c  lw          $v1, 0xC($sp)
    ctx->pc = 0x16e2e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x16e2e4: 0x40202d  daddu       $a0, $v0, $zero
    ctx->pc = 0x16e2e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e2e8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x16e2e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x16e2ec: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x16E2ECu;
    {
        const bool branch_taken_0x16e2ec = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x16E2F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E2ECu;
            // 0x16e2f0: 0x64102a  slt         $v0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x16e2ec) {
            ctx->pc = 0x16E300u;
            goto label_16e300;
        }
    }
    ctx->pc = 0x16E2F4u;
    // 0x16e2f4: 0x8fa30004  lw          $v1, 0x4($sp)
    ctx->pc = 0x16e2f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x16e2f8: 0xafa3000c  sw          $v1, 0xC($sp)
    ctx->pc = 0x16e2f8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 3));
    // 0x16e2fc: 0x64102a  slt         $v0, $v1, $a0
    ctx->pc = 0x16e2fcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
label_16e300:
    // 0x16e300: 0x82180a  movz        $v1, $a0, $v0
    ctx->pc = 0x16e300u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 4));
    // 0x16e304: 0xae6300e8  sw          $v1, 0xE8($s3)
    ctx->pc = 0x16e304u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 232), GPR_U32(ctx, 3));
label_16e308:
    // 0x16e308: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x16e308u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16e30c: 0x280302d  daddu       $a2, $s4, $zero
    ctx->pc = 0x16e30cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e310: 0xc05b8d8  jal         func_16E360
    ctx->pc = 0x16E310u;
    SET_GPR_U32(ctx, 31, 0x16E318u);
    ctx->pc = 0x16E314u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E310u;
            // 0x16e314: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16E360u;
    if (runtime->hasFunction(0x16E360u)) {
        auto targetFn = runtime->lookupFunction(0x16E360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E318u; }
        if (ctx->pc != 0x16E318u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016E360_0x16e360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E318u; }
        if (ctx->pc != 0x16E318u) { return; }
    }
    ctx->pc = 0x16E318u;
label_16e318:
    // 0x16e318: 0x240202d  daddu       $a0, $s2, $zero
    ctx->pc = 0x16e318u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e31c: 0x8fa50000  lw          $a1, 0x0($sp)
    ctx->pc = 0x16e31cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16e320: 0x2a0302d  daddu       $a2, $s5, $zero
    ctx->pc = 0x16e320u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e324: 0xc05b91e  jal         func_16E478
    ctx->pc = 0x16E324u;
    SET_GPR_U32(ctx, 31, 0x16E32Cu);
    ctx->pc = 0x16E328u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E324u;
            // 0x16e328: 0x8fa70004  lw          $a3, 0x4($sp) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16E478u;
    if (runtime->hasFunction(0x16E478u)) {
        auto targetFn = runtime->lookupFunction(0x16E478u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E32Cu; }
        if (ctx->pc != 0x16E32Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016E478_0x16e478(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E32Cu; }
        if (ctx->pc != 0x16E32Cu) { return; }
    }
    ctx->pc = 0x16E32Cu;
label_16e32c:
    // 0x16e32c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x16e32cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16e330: 0xc05b92c  jal         func_16E4B0
    ctx->pc = 0x16E330u;
    SET_GPR_U32(ctx, 31, 0x16E338u);
    ctx->pc = 0x16E334u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16E330u;
            // 0x16e334: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x16E4B0u;
    if (runtime->hasFunction(0x16E4B0u)) {
        auto targetFn = runtime->lookupFunction(0x16E4B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E338u; }
        if (ctx->pc != 0x16E338u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016E4B0_0x16e4b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16E338u; }
        if (ctx->pc != 0x16E338u) { return; }
    }
    ctx->pc = 0x16E338u;
label_16e338:
    // 0x16e338: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x16e338u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_16e33c:
    // 0x16e33c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x16e33cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16e340: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x16e340u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16e344: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x16e344u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16e348: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x16e348u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x16e34c: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x16e34cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x16e350: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x16e350u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x16e354: 0x3e00008  jr          $ra
    ctx->pc = 0x16E354u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16E358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16E354u;
            // 0x16e358: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16E284u: goto label_16e284;
            case 0x16E29Cu: goto label_16e29c;
            case 0x16E2A8u: goto label_16e2a8;
            case 0x16E2B8u: goto label_16e2b8;
            case 0x16E2C4u: goto label_16e2c4;
            case 0x16E2D8u: goto label_16e2d8;
            case 0x16E2E0u: goto label_16e2e0;
            case 0x16E300u: goto label_16e300;
            case 0x16E308u: goto label_16e308;
            case 0x16E318u: goto label_16e318;
            case 0x16E32Cu: goto label_16e32c;
            case 0x16E338u: goto label_16e338;
            case 0x16E33Cu: goto label_16e33c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16E35Cu;
    // 0x16e35c: 0x0  nop
    ctx->pc = 0x16e35cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
