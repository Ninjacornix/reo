#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D50C0
// Address: 0x1d50c0 - 0x1d5130
void sub_001D50C0_0x1d50c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D50C0_0x1d50c0");
#endif

    switch (ctx->pc) {
        case 0x1d50dcu: goto label_1d50dc;
        case 0x1d50f4u: goto label_1d50f4;
        default: break;
    }

    ctx->pc = 0x1d50c0u;

    // 0x1d50c0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d50c0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d50c4: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d50c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d50c8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d50c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d50cc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1d50ccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d50d0: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1d50d0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1d50d4: 0xc0754fc  jal         func_1D53F0
    ctx->pc = 0x1D50D4u;
    SET_GPR_U32(ctx, 31, 0x1D50DCu);
    ctx->pc = 0x1D50D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D50D4u;
            // 0x1d50d8: 0x24842720  addiu       $a0, $a0, 0x2720 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10016));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D53F0u;
    if (runtime->hasFunction(0x1D53F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D53F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D50DCu; }
        if (ctx->pc != 0x1D50DCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D53F0_0x1d53f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D50DCu; }
        if (ctx->pc != 0x1D50DCu) { return; }
    }
    ctx->pc = 0x1D50DCu;
label_1d50dc:
    // 0x1d50dc: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D50DCu;
    {
        const bool branch_taken_0x1d50dc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D50E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D50DCu;
            // 0x1d50e0: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d50dc) {
            ctx->pc = 0x1D50ECu;
            goto label_1d50ec;
        }
    }
    ctx->pc = 0x1D50E4u;
    // 0x1d50e4: 0x1000000e  b           . + 4 + (0xE << 2)
    ctx->pc = 0x1D50E4u;
    {
        const bool branch_taken_0x1d50e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D50E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D50E4u;
            // 0x1d50e8: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d50e4) {
            ctx->pc = 0x1D5120u;
            goto label_1d5120;
        }
    }
    ctx->pc = 0x1D50ECu;
label_1d50ec:
    // 0x1d50ec: 0xc075646  jal         func_1D5918
    ctx->pc = 0x1D50ECu;
    SET_GPR_U32(ctx, 31, 0x1D50F4u);
    ctx->pc = 0x1D50F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D50ECu;
            // 0x1d50f0: 0x27a5002c  addiu       $a1, $sp, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D5918u;
    if (runtime->hasFunction(0x1D5918u)) {
        auto targetFn = runtime->lookupFunction(0x1D5918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D50F4u; }
        if (ctx->pc != 0x1D50F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D5918_0x1d5918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D50F4u; }
        if (ctx->pc != 0x1D50F4u) { return; }
    }
    ctx->pc = 0x1D50F4u;
label_1d50f4:
    // 0x1d50f4: 0x8fa2002c  lw          $v0, 0x2C($sp)
    ctx->pc = 0x1d50f4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1d50f8: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1D50F8u;
    {
        const bool branch_taken_0x1d50f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D50FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D50F8u;
            // 0x1d50fc: 0x3c020034  lui         $v0, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d50f8) {
            ctx->pc = 0x1D5108u;
            goto label_1d5108;
        }
    }
    ctx->pc = 0x1D5100u;
    // 0x1d5100: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1D5100u;
    {
        const bool branch_taken_0x1d5100 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5104u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5100u;
            // 0x1d5104: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5100) {
            ctx->pc = 0x1D5120u;
            goto label_1d5120;
        }
    }
    ctx->pc = 0x1D5108u;
label_1d5108:
    // 0x1d5108: 0x24422728  addiu       $v0, $v0, 0x2728
    ctx->pc = 0x1d5108u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 10024));
    // 0x1d510c: 0x501021  addu        $v0, $v0, $s0
    ctx->pc = 0x1d510cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1d5110: 0x90420000  lbu         $v0, 0x0($v0)
    ctx->pc = 0x1d5110u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d5114: 0x401026  xor         $v0, $v0, $zero
    ctx->pc = 0x1d5114u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 0));
    // 0x1d5118: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x1d5118u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x1d511c: 0x21023  negu        $v0, $v0
    ctx->pc = 0x1d511cu;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
label_1d5120:
    // 0x1d5120: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d5120u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d5124: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d5124u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d5128: 0x3e00008  jr          $ra
    ctx->pc = 0x1D5128u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D512Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5128u;
            // 0x1d512c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D50DCu: goto label_1d50dc;
            case 0x1D50ECu: goto label_1d50ec;
            case 0x1D50F4u: goto label_1d50f4;
            case 0x1D5108u: goto label_1d5108;
            case 0x1D5120u: goto label_1d5120;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D5130u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
