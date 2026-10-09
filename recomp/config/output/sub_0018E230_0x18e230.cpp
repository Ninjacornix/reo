#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018E230
// Address: 0x18e230 - 0x18e3b0
void sub_0018E230_0x18e230(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018E230_0x18e230");
#endif

    switch (ctx->pc) {
        case 0x18e258u: goto label_18e258;
        case 0x18e288u: goto label_18e288;
        case 0x18e2b4u: goto label_18e2b4;
        case 0x18e2c0u: goto label_18e2c0;
        case 0x18e2ccu: goto label_18e2cc;
        case 0x18e2d8u: goto label_18e2d8;
        case 0x18e300u: goto label_18e300;
        case 0x18e308u: goto label_18e308;
        case 0x18e388u: goto label_18e388;
        default: break;
    }

    ctx->pc = 0x18e230u;

    // 0x18e230: 0x27bdff50  addiu       $sp, $sp, -0xB0
    ctx->pc = 0x18e230u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x18e234: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x18e234u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x18e238: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x18e238u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x18e23c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x18e23cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x18e240: 0x80a02d  daddu       $s4, $a0, $zero
    ctx->pc = 0x18e240u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e244: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x18e244u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x18e248: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x18e248u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x18e24c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18e24cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18e250: 0xc067448  jal         func_19D120
    ctx->pc = 0x18E250u;
    SET_GPR_U32(ctx, 31, 0x18E258u);
    ctx->pc = 0x18E254u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18E250u;
            // 0x18e254: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19D120u;
    if (runtime->hasFunction(0x19D120u)) {
        auto targetFn = runtime->lookupFunction(0x19D120u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E258u; }
        if (ctx->pc != 0x18E258u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D120_0x19d120(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E258u; }
        if (ctx->pc != 0x18E258u) { return; }
    }
    ctx->pc = 0x18E258u;
label_18e258:
    // 0x18e258: 0x40982d  daddu       $s3, $v0, $zero
    ctx->pc = 0x18e258u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e25c: 0x27a40060  addiu       $a0, $sp, 0x60
    ctx->pc = 0x18e25cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
    // 0x18e260: 0x3042ffff  andi        $v0, $v0, 0xFFFF
    ctx->pc = 0x18e260u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)65535);
    // 0x18e264: 0x2445ffff  addiu       $a1, $v0, -0x1
    ctx->pc = 0x18e264u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x18e268: 0x518c0  sll         $v1, $a1, 3
    ctx->pc = 0x18e268u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x18e26c: 0x3c02002a  lui         $v0, 0x2A
    ctx->pc = 0x18e26cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)42 << 16));
    // 0x18e270: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x18e270u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x18e274: 0x24428680  addiu       $v0, $v0, -0x7980
    ctx->pc = 0x18e274u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294936192));
    // 0x18e278: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x18e278u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x18e27c: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x18e27cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e280: 0xc06931c  jal         func_1A4C70
    ctx->pc = 0x18E280u;
    SET_GPR_U32(ctx, 31, 0x18E288u);
    ctx->pc = 0x18E284u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18E280u;
            // 0x18e284: 0x439021  addu        $s2, $v0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A4C70u;
    if (runtime->hasFunction(0x1A4C70u)) {
        auto targetFn = runtime->lookupFunction(0x1A4C70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E288u; }
        if (ctx->pc != 0x18E288u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A4C70_0x1a4c70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E288u; }
        if (ctx->pc != 0x18E288u) { return; }
    }
    ctx->pc = 0x18E288u;
label_18e288:
    // 0x18e288: 0x27b10074  addiu       $s1, $sp, 0x74
    ctx->pc = 0x18e288u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 29), 116));
    // 0x18e28c: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x18e28cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x18e290: 0x8e230000  lw          $v1, 0x0($s1)
    ctx->pc = 0x18e290u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x18e294: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x18E294u;
    {
        const bool branch_taken_0x18e294 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x18E298u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E294u;
            // 0x18e298: 0x27a40060  addiu       $a0, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e294) {
            ctx->pc = 0x18E2A4u;
            goto label_18e2a4;
        }
    }
    ctx->pc = 0x18E29Cu;
    // 0x18e29c: 0x1000003b  b           . + 4 + (0x3B << 2)
    ctx->pc = 0x18E29Cu;
    {
        const bool branch_taken_0x18e29c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18E2A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E29Cu;
            // 0x18e2a0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e29c) {
            ctx->pc = 0x18E38Cu;
            goto label_18e38c;
        }
    }
    ctx->pc = 0x18E2A4u;
label_18e2a4:
    // 0x18e2a4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x18e2a4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x18e2a8: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x18e2a8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e2ac: 0xc0672cc  jal         func_19CB30
    ctx->pc = 0x18E2ACu;
    SET_GPR_U32(ctx, 31, 0x18E2B4u);
    ctx->pc = 0x18E2B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18E2ACu;
            // 0x18e2b0: 0x200382d  daddu       $a3, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19CB30u;
    if (runtime->hasFunction(0x19CB30u)) {
        auto targetFn = runtime->lookupFunction(0x19CB30u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E2B4u; }
        if (ctx->pc != 0x18E2B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019CB30_0x19cb30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E2B4u; }
        if (ctx->pc != 0x18E2B4u) { return; }
    }
    ctx->pc = 0x18E2B4u;
label_18e2b4:
    // 0x18e2b4: 0x8e440008  lw          $a0, 0x8($s2)
    ctx->pc = 0x18e2b4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x18e2b8: 0xc063714  jal         func_18DC50
    ctx->pc = 0x18E2B8u;
    SET_GPR_U32(ctx, 31, 0x18E2C0u);
    ctx->pc = 0x18E2BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18E2B8u;
            // 0x18e2bc: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DC50u;
    if (runtime->hasFunction(0x18DC50u)) {
        auto targetFn = runtime->lookupFunction(0x18DC50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E2C0u; }
        if (ctx->pc != 0x18E2C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC50_0x18dc50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E2C0u; }
        if (ctx->pc != 0x18E2C0u) { return; }
    }
    ctx->pc = 0x18E2C0u;
label_18e2c0:
    // 0x18e2c0: 0xae420024  sw          $v0, 0x24($s2)
    ctx->pc = 0x18e2c0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 36), GPR_U32(ctx, 2));
    // 0x18e2c4: 0xc063728  jal         func_18DCA0
    ctx->pc = 0x18E2C4u;
    SET_GPR_U32(ctx, 31, 0x18E2CCu);
    ctx->pc = 0x18E2C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18E2C4u;
            // 0x18e2c8: 0x8e440024  lw          $a0, 0x24($s2) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 36)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DCA0u;
    if (runtime->hasFunction(0x18DCA0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E2CCu; }
        if (ctx->pc != 0x18E2CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E2CCu; }
        if (ctx->pc != 0x18E2CCu) { return; }
    }
    ctx->pc = 0x18E2CCu;
label_18e2cc:
    // 0x18e2cc: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x18e2ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e2d0: 0xc069354  jal         func_1A4D50
    ctx->pc = 0x18E2D0u;
    SET_GPR_U32(ctx, 31, 0x18E2D8u);
    ctx->pc = 0x18E2D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18E2D0u;
            // 0x18e2d4: 0x40902d  daddu       $s2, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A4D50u;
    if (runtime->hasFunction(0x1A4D50u)) {
        auto targetFn = runtime->lookupFunction(0x1A4D50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E2D8u; }
        if (ctx->pc != 0x18E2D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A4D50_0x1a4d50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E2D8u; }
        if (ctx->pc != 0x18E2D8u) { return; }
    }
    ctx->pc = 0x18E2D8u;
label_18e2d8:
    // 0x18e2d8: 0x8e240000  lw          $a0, 0x0($s1)
    ctx->pc = 0x18e2d8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x18e2dc: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x18e2dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x18e2e0: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x18E2E0u;
    {
        const bool branch_taken_0x18e2e0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x18E2E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E2E0u;
            // 0x18e2e4: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e2e0) {
            ctx->pc = 0x18E2F0u;
            goto label_18e2f0;
        }
    }
    ctx->pc = 0x18E2E8u;
    // 0x18e2e8: 0x10000023  b           . + 4 + (0x23 << 2)
    ctx->pc = 0x18E2E8u;
    {
        const bool branch_taken_0x18e2e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18E2ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E2E8u;
            // 0x18e2ec: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e2e8) {
            ctx->pc = 0x18E378u;
            goto label_18e378;
        }
    }
    ctx->pc = 0x18E2F0u;
label_18e2f0:
    // 0x18e2f0: 0x27a40068  addiu       $a0, $sp, 0x68
    ctx->pc = 0x18e2f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 104));
    // 0x18e2f4: 0x27a3006c  addiu       $v1, $sp, 0x6C
    ctx->pc = 0x18e2f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 108));
    // 0x18e2f8: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x18E2F8u;
    {
        const bool branch_taken_0x18e2f8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18E2FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E2F8u;
            // 0x18e2fc: 0x27a90064  addiu       $t1, $sp, 0x64 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 29), 100));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e2f8) {
            ctx->pc = 0x18E360u;
            goto label_18e360;
        }
    }
    ctx->pc = 0x18E300u;
label_18e300:
    // 0x18e300: 0x10000012  b           . + 4 + (0x12 << 2)
    ctx->pc = 0x18E300u;
    {
        const bool branch_taken_0x18e300 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18E304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E300u;
            // 0x18e304: 0x502d  daddu       $t2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e300) {
            ctx->pc = 0x18E34Cu;
            goto label_18e34c;
        }
    }
    ctx->pc = 0x18E308u;
label_18e308:
    // 0x18e308: 0x8c880000  lw          $t0, 0x0($a0)
    ctx->pc = 0x18e308u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18e30c: 0x8e260000  lw          $a2, 0x0($s1)
    ctx->pc = 0x18e30cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x18e310: 0x8c670000  lw          $a3, 0x0($v1)
    ctx->pc = 0x18e310u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x18e314: 0x2508ffff  addiu       $t0, $t0, -0x1
    ctx->pc = 0x18e314u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294967295));
    // 0x18e318: 0x1054023  subu        $t0, $t0, $a1
    ctx->pc = 0x18e318u;
    SET_GPR_S32(ctx, 8, (int32_t)SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 5)));
    // 0x18e31c: 0x71463018  mult1       $a2, $t2, $a2
    ctx->pc = 0x18e31cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 10) * (int64_t)GPR_S32(ctx, 6); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 6, (int32_t)result); }
    // 0x18e320: 0xe83818  mult        $a3, $a3, $t0
    ctx->pc = 0x18e320u;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 7, (int32_t)result); }
    // 0x18e324: 0x463021  addu        $a2, $v0, $a2
    ctx->pc = 0x18e324u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x18e328: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x18e328u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x18e32c: 0xc73021  addu        $a2, $a2, $a3
    ctx->pc = 0x18e32cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x18e330: 0x90c80000  lbu         $t0, 0x0($a2)
    ctx->pc = 0x18e330u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x18e334: 0x90c70001  lbu         $a3, 0x1($a2)
    ctx->pc = 0x18e334u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 1)));
    // 0x18e338: 0x90c60002  lbu         $a2, 0x2($a2)
    ctx->pc = 0x18e338u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 2)));
    // 0x18e33c: 0xa2460000  sb          $a2, 0x0($s2)
    ctx->pc = 0x18e33cu;
    WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 6));
    // 0x18e340: 0xa2470001  sb          $a3, 0x1($s2)
    ctx->pc = 0x18e340u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 1), (uint8_t)GPR_U32(ctx, 7));
    // 0x18e344: 0xa2480002  sb          $t0, 0x2($s2)
    ctx->pc = 0x18e344u;
    WRITE8(ADD32(GPR_U32(ctx, 18), 2), (uint8_t)GPR_U32(ctx, 8));
    // 0x18e348: 0x26520003  addiu       $s2, $s2, 0x3
    ctx->pc = 0x18e348u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 3));
label_18e34c:
    // 0x18e34c: 0x8d260000  lw          $a2, 0x0($t1)
    ctx->pc = 0x18e34cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x18e350: 0x146302a  slt         $a2, $t2, $a2
    ctx->pc = 0x18e350u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 10) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x18e354: 0x14c0ffec  bnez        $a2, . + 4 + (-0x14 << 2)
    ctx->pc = 0x18E354u;
    {
        const bool branch_taken_0x18e354 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        if (branch_taken_0x18e354) {
            ctx->pc = 0x18E308u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18e308;
        }
    }
    ctx->pc = 0x18E35Cu;
    // 0x18e35c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x18e35cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_18e360:
    // 0x18e360: 0x8c860000  lw          $a2, 0x0($a0)
    ctx->pc = 0x18e360u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x18e364: 0xa6302a  slt         $a2, $a1, $a2
    ctx->pc = 0x18e364u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x18e368: 0x14c0ffe5  bnez        $a2, . + 4 + (-0x1B << 2)
    ctx->pc = 0x18E368u;
    {
        const bool branch_taken_0x18e368 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        if (branch_taken_0x18e368) {
            ctx->pc = 0x18E300u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_18e300;
        }
    }
    ctx->pc = 0x18E370u;
    // 0x18e370: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x18E370u;
    {
        const bool branch_taken_0x18e370 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18E374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E370u;
            // 0x18e374: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e370) {
            ctx->pc = 0x18E380u;
            goto label_18e380;
        }
    }
    ctx->pc = 0x18E378u;
label_18e378:
    // 0x18e378: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x18E378u;
    {
        const bool branch_taken_0x18e378 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x18E37Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E378u;
            // 0x18e37c: 0xdfbf0050  ld          $ra, 0x50($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x18e378) {
            ctx->pc = 0x18E390u;
            goto label_18e390;
        }
    }
    ctx->pc = 0x18E380u;
label_18e380:
    // 0x18e380: 0xc067350  jal         func_19CD40
    ctx->pc = 0x18E380u;
    SET_GPR_U32(ctx, 31, 0x18E388u);
    ctx->pc = 0x18E384u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18E380u;
            // 0x18e384: 0x260202d  daddu       $a0, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x19CD40u;
    if (runtime->hasFunction(0x19CD40u)) {
        auto targetFn = runtime->lookupFunction(0x19CD40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E388u; }
        if (ctx->pc != 0x18E388u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0019CD40_0x19cd40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E388u; }
        if (ctx->pc != 0x18E388u) { return; }
    }
    ctx->pc = 0x18E388u;
label_18e388:
    // 0x18e388: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x18e388u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
label_18e38c:
    // 0x18e38c: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x18e38cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
label_18e390:
    // 0x18e390: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x18e390u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x18e394: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x18e394u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18e398: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x18e398u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18e39c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x18e39cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18e3a0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18e3a0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18e3a4: 0x3e00008  jr          $ra
    ctx->pc = 0x18E3A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18E3A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18E3A4u;
            // 0x18e3a8: 0x27bd00b0  addiu       $sp, $sp, 0xB0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 176));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18E258u: goto label_18e258;
            case 0x18E288u: goto label_18e288;
            case 0x18E2A4u: goto label_18e2a4;
            case 0x18E2B4u: goto label_18e2b4;
            case 0x18E2C0u: goto label_18e2c0;
            case 0x18E2CCu: goto label_18e2cc;
            case 0x18E2D8u: goto label_18e2d8;
            case 0x18E2F0u: goto label_18e2f0;
            case 0x18E300u: goto label_18e300;
            case 0x18E308u: goto label_18e308;
            case 0x18E34Cu: goto label_18e34c;
            case 0x18E360u: goto label_18e360;
            case 0x18E378u: goto label_18e378;
            case 0x18E380u: goto label_18e380;
            case 0x18E388u: goto label_18e388;
            case 0x18E38Cu: goto label_18e38c;
            case 0x18E390u: goto label_18e390;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18E3ACu;
    // 0x18e3ac: 0x0  nop
    ctx->pc = 0x18e3acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
