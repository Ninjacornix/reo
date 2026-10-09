#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00131190
// Address: 0x131190 - 0x131338
void sub_00131190_0x131190(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00131190_0x131190");
#endif

    switch (ctx->pc) {
        case 0x1311bcu: goto label_1311bc;
        case 0x1311d8u: goto label_1311d8;
        case 0x131230u: goto label_131230;
        case 0x131240u: goto label_131240;
        case 0x131280u: goto label_131280;
        case 0x1312a8u: goto label_1312a8;
        default: break;
    }

    ctx->pc = 0x131190u;

    // 0x131190: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x131190u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x131194: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x131194u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131198: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x131198u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13119c: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x13119cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1311a0: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1311A0u;
    {
        const bool branch_taken_0x1311a0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1311A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1311A0u;
            // 0x1311a4: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1311a0) {
            ctx->pc = 0x1311C8u;
            goto label_1311c8;
        }
    }
    ctx->pc = 0x1311A8u;
    // 0x1311a8: 0x8c470004  lw          $a3, 0x4($v0)
    ctx->pc = 0x1311a8u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1311ac: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1311acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1311b0: 0x8c450008  lw          $a1, 0x8($v0)
    ctx->pc = 0x1311b0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x1311b4: 0xc04eaac  jal         func_13AAB0
    ctx->pc = 0x1311B4u;
    SET_GPR_U32(ctx, 31, 0x1311BCu);
    ctx->pc = 0x1311B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1311B4u;
            // 0x1311b8: 0x8c46000c  lw          $a2, 0xC($v0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AAB0u;
    if (runtime->hasFunction(0x13AAB0u)) {
        auto targetFn = runtime->lookupFunction(0x13AAB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1311BCu; }
        if (ctx->pc != 0x1311BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AAB0_0x13aab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1311BCu; }
        if (ctx->pc != 0x1311BCu) { return; }
    }
    ctx->pc = 0x1311BCu;
label_1311bc:
    // 0x1311bc: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1311BCu;
    {
        const bool branch_taken_0x1311bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1311C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1311BCu;
            // 0x1311c0: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1311bc) {
            ctx->pc = 0x1311D8u;
            goto label_1311d8;
        }
    }
    ctx->pc = 0x1311C4u;
    // 0x1311c4: 0x0  nop
    ctx->pc = 0x1311c4u;
    // NOP
label_1311c8:
    // 0x1311c8: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1311c8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1311cc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1311ccu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1311d0: 0xc04eaac  jal         func_13AAB0
    ctx->pc = 0x1311D0u;
    SET_GPR_U32(ctx, 31, 0x1311D8u);
    ctx->pc = 0x1311D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1311D0u;
            // 0x1311d4: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AAB0u;
    if (runtime->hasFunction(0x13AAB0u)) {
        auto targetFn = runtime->lookupFunction(0x13AAB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1311D8u; }
        if (ctx->pc != 0x1311D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AAB0_0x13aab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1311D8u; }
        if (ctx->pc != 0x1311D8u) { return; }
    }
    ctx->pc = 0x1311D8u;
label_1311d8:
    // 0x1311d8: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1311d8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1311dc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1311dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1311e0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1311e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1311e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1311E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1311E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1311E4u;
            // 0x1311e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1311BCu: goto label_1311bc;
            case 0x1311C8u: goto label_1311c8;
            case 0x1311D8u: goto label_1311d8;
            case 0x131230u: goto label_131230;
            case 0x131238u: goto label_131238;
            case 0x131240u: goto label_131240;
            case 0x131280u: goto label_131280;
            case 0x131298u: goto label_131298;
            case 0x1312A8u: goto label_1312a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1311ECu;
    // 0x1311ec: 0x0  nop
    ctx->pc = 0x1311ecu;
    // NOP
    // 0x1311f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1311f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1311f4: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1311f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1311f8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1311f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1311fc: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1311fcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131200: 0xa0182d  daddu       $v1, $a1, $zero
    ctx->pc = 0x131200u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131204: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x131204u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131208: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x131208u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13120c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x13120cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131210: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x131210u;
    {
        const bool branch_taken_0x131210 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x131214u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131210u;
            // 0x131214: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131210) {
            ctx->pc = 0x131238u;
            goto label_131238;
        }
    }
    ctx->pc = 0x131218u;
    // 0x131218: 0xe0282d  daddu       $a1, $a3, $zero
    ctx->pc = 0x131218u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13121c: 0x8c47000c  lw          $a3, 0xC($v0)
    ctx->pc = 0x13121cu;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x131220: 0x8c480004  lw          $t0, 0x4($v0)
    ctx->pc = 0x131220u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x131224: 0x60202d  daddu       $a0, $v1, $zero
    ctx->pc = 0x131224u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131228: 0xc04eb18  jal         func_13AC60
    ctx->pc = 0x131228u;
    SET_GPR_U32(ctx, 31, 0x131230u);
    ctx->pc = 0x13122Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131228u;
            // 0x13122c: 0x8c460008  lw          $a2, 0x8($v0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AC60u;
    if (runtime->hasFunction(0x13AC60u)) {
        auto targetFn = runtime->lookupFunction(0x13AC60u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131230u; }
        if (ctx->pc != 0x131230u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AC60_0x13ac60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131230u; }
        if (ctx->pc != 0x131230u) { return; }
    }
    ctx->pc = 0x131230u;
label_131230:
    // 0x131230: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x131230u;
    {
        const bool branch_taken_0x131230 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x131234u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131230u;
            // 0x131234: 0x40802d  daddu       $s0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131230) {
            ctx->pc = 0x131240u;
            goto label_131240;
        }
    }
    ctx->pc = 0x131238u;
label_131238:
    // 0x131238: 0xc04eaac  jal         func_13AAB0
    ctx->pc = 0x131238u;
    SET_GPR_U32(ctx, 31, 0x131240u);
    ctx->pc = 0x13123Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131238u;
            // 0x13123c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AAB0u;
    if (runtime->hasFunction(0x13AAB0u)) {
        auto targetFn = runtime->lookupFunction(0x13AAB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131240u; }
        if (ctx->pc != 0x131240u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013AAB0_0x13aab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131240u; }
        if (ctx->pc != 0x131240u) { return; }
    }
    ctx->pc = 0x131240u;
label_131240:
    // 0x131240: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x131240u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131244: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x131244u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131248: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x131248u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13124c: 0x3e00008  jr          $ra
    ctx->pc = 0x13124Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x131250u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13124Cu;
            // 0x131250: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1311BCu: goto label_1311bc;
            case 0x1311C8u: goto label_1311c8;
            case 0x1311D8u: goto label_1311d8;
            case 0x131230u: goto label_131230;
            case 0x131238u: goto label_131238;
            case 0x131240u: goto label_131240;
            case 0x131280u: goto label_131280;
            case 0x131298u: goto label_131298;
            case 0x1312A8u: goto label_1312a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x131254u;
    // 0x131254: 0x0  nop
    ctx->pc = 0x131254u;
    // NOP
    // 0x131258: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x131258u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13125c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x13125cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x131260: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x131260u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131264: 0x1200000c  beqz        $s0, . + 4 + (0xC << 2)
    ctx->pc = 0x131264u;
    {
        const bool branch_taken_0x131264 = (GPR_U64(ctx, 16) == GPR_U64(ctx, 0));
        ctx->pc = 0x131268u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131264u;
            // 0x131268: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131264) {
            ctx->pc = 0x131298u;
            goto label_131298;
        }
    }
    ctx->pc = 0x13126Cu;
    // 0x13126c: 0x8e040008  lw          $a0, 0x8($s0)
    ctx->pc = 0x13126cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x131270: 0x8e05000c  lw          $a1, 0xC($s0)
    ctx->pc = 0x131270u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x131274: 0x8e060010  lw          $a2, 0x10($s0)
    ctx->pc = 0x131274u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x131278: 0xc04eb7c  jal         func_13ADF0
    ctx->pc = 0x131278u;
    SET_GPR_U32(ctx, 31, 0x131280u);
    ctx->pc = 0x13127Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131278u;
            // 0x13127c: 0x8e070004  lw          $a3, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13ADF0u;
    if (runtime->hasFunction(0x13ADF0u)) {
        auto targetFn = runtime->lookupFunction(0x13ADF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131280u; }
        if (ctx->pc != 0x131280u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013ADF0_0x13adf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131280u; }
        if (ctx->pc != 0x131280u) { return; }
    }
    ctx->pc = 0x131280u;
label_131280:
    // 0x131280: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x131280u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x131284: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x131284u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x131288: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x131288u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13128c: 0x804eb84  j           func_13AE10
    ctx->pc = 0x13128Cu;
    ctx->pc = 0x131290u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13128Cu;
            // 0x131290: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AE10u;
    if (runtime->hasFunction(0x13AE10u)) {
        auto targetFn = runtime->lookupFunction(0x13AE10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013AE10_0x13ae10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x131294u;
    // 0x131294: 0x0  nop
    ctx->pc = 0x131294u;
    // NOP
label_131298:
    // 0x131298: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x131298u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13129c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x13129cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1312a0: 0xc04eb7c  jal         func_13ADF0
    ctx->pc = 0x1312A0u;
    SET_GPR_U32(ctx, 31, 0x1312A8u);
    ctx->pc = 0x1312A4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1312A0u;
            // 0x1312a4: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13ADF0u;
    if (runtime->hasFunction(0x13ADF0u)) {
        auto targetFn = runtime->lookupFunction(0x13ADF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1312A8u; }
        if (ctx->pc != 0x1312A8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013ADF0_0x13adf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1312A8u; }
        if (ctx->pc != 0x1312A8u) { return; }
    }
    ctx->pc = 0x1312A8u;
label_1312a8:
    // 0x1312a8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1312a8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1312ac: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1312acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1312b0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1312b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1312b4: 0x804eb84  j           func_13AE10
    ctx->pc = 0x1312B4u;
    ctx->pc = 0x1312B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1312B4u;
            // 0x1312b8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AE10u;
    if (runtime->hasFunction(0x13AE10u)) {
        auto targetFn = runtime->lookupFunction(0x13AE10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013AE10_0x13ae10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1312BCu;
    // 0x1312bc: 0x0  nop
    ctx->pc = 0x1312bcu;
    // NOP
    // 0x1312c0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1312c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1312c4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1312c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1312c8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1312c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1312cc: 0x804eb72  j           func_13ADC8
    ctx->pc = 0x1312CCu;
    ctx->pc = 0x1312D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1312CCu;
            // 0x1312d0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13ADC8u;
    if (runtime->hasFunction(0x13ADC8u)) {
        auto targetFn = runtime->lookupFunction(0x13ADC8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013ADC8_0x13adc8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1312D4u;
    // 0x1312d4: 0x0  nop
    ctx->pc = 0x1312d4u;
    // NOP
    // 0x1312d8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1312d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1312dc: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1312dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1312e0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1312e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1312e4: 0x804e816  j           func_13A058
    ctx->pc = 0x1312E4u;
    ctx->pc = 0x1312E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1312E4u;
            // 0x1312e8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13A058u;
    {
        auto targetFn = runtime->lookupFunction(0x13A058u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x1312ECu;
    // 0x1312ec: 0x0  nop
    ctx->pc = 0x1312ecu;
    // NOP
    // 0x1312f0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1312f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1312f4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1312f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1312f8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1312f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1312fc: 0x804e81e  j           func_13A078
    ctx->pc = 0x1312FCu;
    ctx->pc = 0x131300u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1312FCu;
            // 0x131300: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13A078u;
    {
        auto targetFn = runtime->lookupFunction(0x13A078u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x131304u;
    // 0x131304: 0x0  nop
    ctx->pc = 0x131304u;
    // NOP
    // 0x131308: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x131308u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13130c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13130cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x131310: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x131310u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131314: 0x804ebba  j           func_13AEE8
    ctx->pc = 0x131314u;
    ctx->pc = 0x131318u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131314u;
            // 0x131318: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13AEE8u;
    if (runtime->hasFunction(0x13AEE8u)) {
        auto targetFn = runtime->lookupFunction(0x13AEE8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013AEE8_0x13aee8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x13131Cu;
    // 0x13131c: 0x0  nop
    ctx->pc = 0x13131cu;
    // NOP
    // 0x131320: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x131320u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x131324: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x131324u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131328: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x131328u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13132c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13132cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131330: 0x804a034  j           func_1280D0
    ctx->pc = 0x131330u;
    ctx->pc = 0x131334u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x131330u;
            // 0x131334: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x131338u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
