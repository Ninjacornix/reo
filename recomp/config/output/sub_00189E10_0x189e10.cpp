#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00189E10
// Address: 0x189e10 - 0x189ed0
void sub_00189E10_0x189e10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00189E10_0x189e10");
#endif

    switch (ctx->pc) {
        case 0x189e2cu: goto label_189e2c;
        case 0x189e4cu: goto label_189e4c;
        case 0x189e58u: goto label_189e58;
        case 0x189e64u: goto label_189e64;
        case 0x189e6cu: goto label_189e6c;
        case 0x189e8cu: goto label_189e8c;
        default: break;
    }

    ctx->pc = 0x189e10u;

    // 0x189e10: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x189e10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x189e14: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x189e14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x189e18: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x189e18u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x189e1c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x189e1cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x189e20: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x189e20u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189e24: 0xc066320  jal         func_198C80
    ctx->pc = 0x189E24u;
    SET_GPR_U32(ctx, 31, 0x189E2Cu);
    ctx->pc = 0x189E28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189E24u;
            // 0x189e28: 0xa0802d  daddu       $s0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x198C80u;
    if (runtime->hasFunction(0x198C80u)) {
        auto targetFn = runtime->lookupFunction(0x198C80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189E2Cu; }
        if (ctx->pc != 0x189E2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00198C80_0x198c80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189E2Cu; }
        if (ctx->pc != 0x189E2Cu) { return; }
    }
    ctx->pc = 0x189E2Cu;
label_189e2c:
    // 0x189e2c: 0x8e230048  lw          $v1, 0x48($s1)
    ctx->pc = 0x189e2cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 72)));
    // 0x189e30: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x189e30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x189e34: 0x10620017  beq         $v1, $v0, . + 4 + (0x17 << 2)
    ctx->pc = 0x189E34u;
    {
        const bool branch_taken_0x189e34 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x189E38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189E34u;
            // 0x189e38: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189e34) {
            ctx->pc = 0x189E94u;
            goto label_189e94;
        }
    }
    ctx->pc = 0x189E3Cu;
    // 0x189e3c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x189e3cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189e40: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x189e40u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189e44: 0xc0627d0  jal         func_189F40
    ctx->pc = 0x189E44u;
    SET_GPR_U32(ctx, 31, 0x189E4Cu);
    ctx->pc = 0x189E48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189E44u;
            // 0x189e48: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x189F40u;
    if (runtime->hasFunction(0x189F40u)) {
        auto targetFn = runtime->lookupFunction(0x189F40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189E4Cu; }
        if (ctx->pc != 0x189E4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00189F40_0x189f40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189E4Cu; }
        if (ctx->pc != 0x189E4Cu) { return; }
    }
    ctx->pc = 0x189E4Cu;
label_189e4c:
    // 0x189e4c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x189e4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189e50: 0xc062898  jal         func_18A260
    ctx->pc = 0x189E50u;
    SET_GPR_U32(ctx, 31, 0x189E58u);
    ctx->pc = 0x189E54u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189E50u;
            // 0x189e54: 0x220282d  daddu       $a1, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18A260u;
    if (runtime->hasFunction(0x18A260u)) {
        auto targetFn = runtime->lookupFunction(0x18A260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189E58u; }
        if (ctx->pc != 0x189E58u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018A260_0x18a260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189E58u; }
        if (ctx->pc != 0x189E58u) { return; }
    }
    ctx->pc = 0x189E58u;
label_189e58:
    // 0x189e58: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x189e58u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189e5c: 0xc062fd0  jal         func_18BF40
    ctx->pc = 0x189E5Cu;
    SET_GPR_U32(ctx, 31, 0x189E64u);
    ctx->pc = 0x189E60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189E5Cu;
            // 0x189e60: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18BF40u;
    if (runtime->hasFunction(0x18BF40u)) {
        auto targetFn = runtime->lookupFunction(0x18BF40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189E64u; }
        if (ctx->pc != 0x189E64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BF40_0x18bf40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189E64u; }
        if (ctx->pc != 0x189E64u) { return; }
    }
    ctx->pc = 0x189E64u;
label_189e64:
    // 0x189e64: 0xc063728  jal         func_18DCA0
    ctx->pc = 0x189E64u;
    SET_GPR_U32(ctx, 31, 0x189E6Cu);
    ctx->pc = 0x189E68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189E64u;
            // 0x189e68: 0x8e24001c  lw          $a0, 0x1C($s1) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DCA0u;
    if (runtime->hasFunction(0x18DCA0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189E6Cu; }
        if (ctx->pc != 0x189E6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189E6Cu; }
        if (ctx->pc != 0x189E6Cu) { return; }
    }
    ctx->pc = 0x189E6Cu;
label_189e6c:
    // 0x189e6c: 0x8e260024  lw          $a2, 0x24($s1)
    ctx->pc = 0x189e6cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x189e70: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x189e70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x189e74: 0x8e23004c  lw          $v1, 0x4C($s1)
    ctx->pc = 0x189e74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 76)));
    // 0x189e78: 0x8e250034  lw          $a1, 0x34($s1)
    ctx->pc = 0x189e78u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 52)));
    // 0x189e7c: 0xc23821  addu        $a3, $a2, $v0
    ctx->pc = 0x189e7cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x189e80: 0x8c660014  lw          $a2, 0x14($v1)
    ctx->pc = 0x189e80u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 20)));
    // 0x189e84: 0xc062cec  jal         func_18B3B0
    ctx->pc = 0x189E84u;
    SET_GPR_U32(ctx, 31, 0x189E8Cu);
    ctx->pc = 0x189E88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x189E84u;
            // 0x189e88: 0x26280060  addiu       $t0, $s1, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 17), 96));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18B3B0u;
    if (runtime->hasFunction(0x18B3B0u)) {
        auto targetFn = runtime->lookupFunction(0x18B3B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189E8Cu; }
        if (ctx->pc != 0x189E8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B3B0_0x18b3b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x189E8Cu; }
        if (ctx->pc != 0x189E8Cu) { return; }
    }
    ctx->pc = 0x189E8Cu;
label_189e8c:
    // 0x189e8c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x189E8Cu;
    {
        const bool branch_taken_0x189e8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x189E90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189E8Cu;
            // 0x189e90: 0x3c010029  lui         $at, 0x29 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189e8c) {
            ctx->pc = 0x189E9Cu;
            goto label_189e9c;
        }
    }
    ctx->pc = 0x189E94u;
label_189e94:
    // 0x189e94: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x189E94u;
    {
        const bool branch_taken_0x189e94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x189E98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189E94u;
            // 0x189e98: 0xdfbf0020  ld          $ra, 0x20($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x189e94) {
            ctx->pc = 0x189EB4u;
            goto label_189eb4;
        }
    }
    ctx->pc = 0x189E9Cu;
label_189e9c:
    // 0x189e9c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x189e9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x189ea0: 0x8c234198  lw          $v1, 0x4198($at)
    ctx->pc = 0x189ea0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 16792)));
    // 0x189ea4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x189ea4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x189ea8: 0x3c010029  lui         $at, 0x29
    ctx->pc = 0x189ea8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)41 << 16));
    // 0x189eac: 0xac234198  sw          $v1, 0x4198($at)
    ctx->pc = 0x189eacu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16792), GPR_U32(ctx, 3));
    // 0x189eb0: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x189eb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_189eb4:
    // 0x189eb4: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x189eb4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x189eb8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x189eb8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x189ebc: 0x3e00008  jr          $ra
    ctx->pc = 0x189EBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x189EC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x189EBCu;
            // 0x189ec0: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x189E2Cu: goto label_189e2c;
            case 0x189E4Cu: goto label_189e4c;
            case 0x189E58u: goto label_189e58;
            case 0x189E64u: goto label_189e64;
            case 0x189E6Cu: goto label_189e6c;
            case 0x189E8Cu: goto label_189e8c;
            case 0x189E94u: goto label_189e94;
            case 0x189E9Cu: goto label_189e9c;
            case 0x189EB4u: goto label_189eb4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x189EC4u;
    // 0x189ec4: 0x0  nop
    ctx->pc = 0x189ec4u;
    // NOP
    // 0x189ec8: 0x0  nop
    ctx->pc = 0x189ec8u;
    // NOP
    // 0x189ecc: 0x0  nop
    ctx->pc = 0x189eccu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
