#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AE1E0
// Address: 0x1ae1e0 - 0x1ae2e0
void sub_001AE1E0_0x1ae1e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AE1E0_0x1ae1e0");
#endif

    switch (ctx->pc) {
        case 0x1ae1f4u: goto label_1ae1f4;
        case 0x1ae218u: goto label_1ae218;
        case 0x1ae248u: goto label_1ae248;
        case 0x1ae250u: goto label_1ae250;
        case 0x1ae290u: goto label_1ae290;
        case 0x1ae2b4u: goto label_1ae2b4;
        default: break;
    }

    ctx->pc = 0x1ae1e0u;

    // 0x1ae1e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1ae1e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1ae1e4: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x1ae1e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1ae1e8: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ae1e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ae1ec: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ae1ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ae1f0: 0x882d  daddu       $s1, $zero, $zero
    ctx->pc = 0x1ae1f0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ae1f4:
    // 0x1ae1f4: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1ae1f4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1ae1f8: 0x112080  sll         $a0, $s1, 2
    ctx->pc = 0x1ae1f8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 17), 2));
    // 0x1ae1fc: 0x24638dc8  addiu       $v1, $v1, -0x7238
    ctx->pc = 0x1ae1fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938056));
    // 0x1ae200: 0x648021  addu        $s0, $v1, $a0
    ctx->pc = 0x1ae200u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1ae204: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1ae204u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1ae208: 0x10800011  beqz        $a0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1AE208u;
    {
        const bool branch_taken_0x1ae208 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ae208) {
            ctx->pc = 0x1AE250u;
            goto label_1ae250;
        }
    }
    ctx->pc = 0x1AE210u;
    // 0x1ae210: 0xc04c7be  jal         func_131EF8
    ctx->pc = 0x1AE210u;
    SET_GPR_U32(ctx, 31, 0x1AE218u);
    ctx->pc = 0x131EF8u;
    if (runtime->hasFunction(0x131EF8u)) {
        auto targetFn = runtime->lookupFunction(0x131EF8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE218u; }
        if (ctx->pc != 0x1AE218u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131EF8_0x131ef8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE218u; }
        if (ctx->pc != 0x1AE218u) { return; }
    }
    ctx->pc = 0x1AE218u;
label_1ae218:
    // 0x1ae218: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1ae218u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1ae21c: 0x1443000c  bne         $v0, $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1AE21Cu;
    {
        const bool branch_taken_0x1ae21c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1AE220u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE21Cu;
            // 0x1ae220: 0x111840  sll         $v1, $s1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 17), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae21c) {
            ctx->pc = 0x1AE250u;
            goto label_1ae250;
        }
    }
    ctx->pc = 0x1AE224u;
    // 0x1ae224: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae224u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae228: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x1ae228u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1ae22c: 0x24428d70  addiu       $v0, $v0, -0x7290
    ctx->pc = 0x1ae22cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294937968));
    // 0x1ae230: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x1ae230u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x1ae234: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ae234u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ae238: 0xa0400000  sb          $zero, 0x0($v0)
    ctx->pc = 0x1ae238u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ae23c: 0x8e040000  lw          $a0, 0x0($s0)
    ctx->pc = 0x1ae23cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1ae240: 0xc04cb94  jal         func_132E50
    ctx->pc = 0x1AE240u;
    SET_GPR_U32(ctx, 31, 0x1AE248u);
    ctx->pc = 0x1AE244u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE240u;
            // 0x1ae244: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132E50u;
    if (runtime->hasFunction(0x132E50u)) {
        auto targetFn = runtime->lookupFunction(0x132E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE248u; }
        if (ctx->pc != 0x1AE248u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132E50_0x132e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE248u; }
        if (ctx->pc != 0x1AE248u) { return; }
    }
    ctx->pc = 0x1AE248u;
label_1ae248:
    // 0x1ae248: 0xc04c78e  jal         func_131E38
    ctx->pc = 0x1AE248u;
    SET_GPR_U32(ctx, 31, 0x1AE250u);
    ctx->pc = 0x1AE24Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE248u;
            // 0x1ae24c: 0x8e040000  lw          $a0, 0x0($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x131E38u;
    if (runtime->hasFunction(0x131E38u)) {
        auto targetFn = runtime->lookupFunction(0x131E38u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE250u; }
        if (ctx->pc != 0x1AE250u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00131E38_0x131e38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE250u; }
        if (ctx->pc != 0x1AE250u) { return; }
    }
    ctx->pc = 0x1AE250u;
label_1ae250:
    // 0x1ae250: 0x26310001  addiu       $s1, $s1, 0x1
    ctx->pc = 0x1ae250u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 1));
    // 0x1ae254: 0x2a230003  slti        $v1, $s1, 0x3
    ctx->pc = 0x1ae254u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 17) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1ae258: 0x1460ffe6  bnez        $v1, . + 4 + (-0x1A << 2)
    ctx->pc = 0x1AE258u;
    {
        const bool branch_taken_0x1ae258 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ae258) {
            ctx->pc = 0x1AE1F4u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ae1f4;
        }
    }
    ctx->pc = 0x1AE260u;
    // 0x1ae260: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1ae260u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ae264: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ae264u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ae268: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ae268u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ae26c: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE26Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AE270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE26Cu;
            // 0x1ae270: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE1F4u: goto label_1ae1f4;
            case 0x1AE218u: goto label_1ae218;
            case 0x1AE248u: goto label_1ae248;
            case 0x1AE250u: goto label_1ae250;
            case 0x1AE290u: goto label_1ae290;
            case 0x1AE2B4u: goto label_1ae2b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AE274u;
    // 0x1ae274: 0x0  nop
    ctx->pc = 0x1ae274u;
    // NOP
    // 0x1ae278: 0x0  nop
    ctx->pc = 0x1ae278u;
    // NOP
    // 0x1ae27c: 0x0  nop
    ctx->pc = 0x1ae27cu;
    // NOP
    // 0x1ae280: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ae280u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ae284: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1ae284u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1ae288: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ae288u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ae28c: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1ae28cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ae290:
    // 0x1ae290: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1ae290u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1ae294: 0x102080  sll         $a0, $s0, 2
    ctx->pc = 0x1ae294u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 16), 2));
    // 0x1ae298: 0x24638dc8  addiu       $v1, $v1, -0x7238
    ctx->pc = 0x1ae298u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938056));
    // 0x1ae29c: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1ae29cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1ae2a0: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x1ae2a0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1ae2a4: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1AE2A4u;
    {
        const bool branch_taken_0x1ae2a4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AE2A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE2A4u;
            // 0x1ae2a8: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ae2a4) {
            ctx->pc = 0x1AE2B4u;
            goto label_1ae2b4;
        }
    }
    ctx->pc = 0x1AE2ACu;
    // 0x1ae2ac: 0xc04cb94  jal         func_132E50
    ctx->pc = 0x1AE2ACu;
    SET_GPR_U32(ctx, 31, 0x1AE2B4u);
    ctx->pc = 0x132E50u;
    if (runtime->hasFunction(0x132E50u)) {
        auto targetFn = runtime->lookupFunction(0x132E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE2B4u; }
        if (ctx->pc != 0x1AE2B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132E50_0x132e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE2B4u; }
        if (ctx->pc != 0x1AE2B4u) { return; }
    }
    ctx->pc = 0x1AE2B4u;
label_1ae2b4:
    // 0x1ae2b4: 0x26100001  addiu       $s0, $s0, 0x1
    ctx->pc = 0x1ae2b4u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 1));
    // 0x1ae2b8: 0x2a030003  slti        $v1, $s0, 0x3
    ctx->pc = 0x1ae2b8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 16) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1ae2bc: 0x1460fff4  bnez        $v1, . + 4 + (-0xC << 2)
    ctx->pc = 0x1AE2BCu;
    {
        const bool branch_taken_0x1ae2bc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ae2bc) {
            ctx->pc = 0x1AE290u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ae290;
        }
    }
    ctx->pc = 0x1AE2C4u;
    // 0x1ae2c4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1ae2c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ae2c8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ae2c8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ae2cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE2CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AE2D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE2CCu;
            // 0x1ae2d0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE1F4u: goto label_1ae1f4;
            case 0x1AE218u: goto label_1ae218;
            case 0x1AE248u: goto label_1ae248;
            case 0x1AE250u: goto label_1ae250;
            case 0x1AE290u: goto label_1ae290;
            case 0x1AE2B4u: goto label_1ae2b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AE2D4u;
    // 0x1ae2d4: 0x0  nop
    ctx->pc = 0x1ae2d4u;
    // NOP
    // 0x1ae2d8: 0x0  nop
    ctx->pc = 0x1ae2d8u;
    // NOP
    // 0x1ae2dc: 0x0  nop
    ctx->pc = 0x1ae2dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
