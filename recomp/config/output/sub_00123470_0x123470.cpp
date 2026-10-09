#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00123470
// Address: 0x123470 - 0x1234d8
void sub_00123470_0x123470(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00123470_0x123470");
#endif

    switch (ctx->pc) {
        case 0x123490u: goto label_123490;
        case 0x1234acu: goto label_1234ac;
        default: break;
    }

    ctx->pc = 0x123470u;

    // 0x123470: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x123470u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x123474: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x123474u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x123478: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x123478u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x12347c: 0x24a59310  addiu       $a1, $a1, -0x6CF0
    ctx->pc = 0x12347cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294939408));
    // 0x123480: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x123480u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x123484: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x123484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x123488: 0xc041e86  jal         func_107A18
    ctx->pc = 0x123488u;
    SET_GPR_U32(ctx, 31, 0x123490u);
    ctx->pc = 0x12348Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x123488u;
            // 0x12348c: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107A18u;
    if (runtime->hasFunction(0x107A18u)) {
        auto targetFn = runtime->lookupFunction(0x107A18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x123490u; }
        if (ctx->pc != 0x123490u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107A18_0x107a18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x123490u; }
        if (ctx->pc != 0x123490u) { return; }
    }
    ctx->pc = 0x123490u;
label_123490:
    // 0x123490: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x123490u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x123494: 0x26040008  addiu       $a0, $s0, 0x8
    ctx->pc = 0x123494u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x123498: 0x24a59318  addiu       $a1, $a1, -0x6CE8
    ctx->pc = 0x123498u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294939416));
    // 0x12349c: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x12349Cu;
    {
        const bool branch_taken_0x12349c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1234A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12349Cu;
            // 0x1234a0: 0x24060004  addiu       $a2, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12349c) {
            ctx->pc = 0x1234C0u;
            goto label_1234c0;
        }
    }
    ctx->pc = 0x1234A4u;
    // 0x1234a4: 0xc041e86  jal         func_107A18
    ctx->pc = 0x1234A4u;
    SET_GPR_U32(ctx, 31, 0x1234ACu);
    ctx->pc = 0x107A18u;
    if (runtime->hasFunction(0x107A18u)) {
        auto targetFn = runtime->lookupFunction(0x107A18u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1234ACu; }
        if (ctx->pc != 0x1234ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107A18_0x107a18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1234ACu; }
        if (ctx->pc != 0x1234ACu) { return; }
    }
    ctx->pc = 0x1234ACu;
label_1234ac:
    // 0x1234ac: 0x54400005  bnel        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x1234ACu;
    {
        const bool branch_taken_0x1234ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1234ac) {
            ctx->pc = 0x1234B0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1234ACu;
            // 0x1234b0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1234C4u;
            goto label_1234c4;
        }
    }
    ctx->pc = 0x1234B4u;
    // 0x1234b4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1234B4u;
    {
        const bool branch_taken_0x1234b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1234B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1234B4u;
            // 0x1234b8: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1234b4) {
            ctx->pc = 0x1234C4u;
            goto label_1234c4;
        }
    }
    ctx->pc = 0x1234BCu;
    // 0x1234bc: 0x0  nop
    ctx->pc = 0x1234bcu;
    // NOP
label_1234c0:
    // 0x1234c0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1234c0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1234c4:
    // 0x1234c4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1234c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1234c8: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1234c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1234cc: 0x3e00008  jr          $ra
    ctx->pc = 0x1234CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1234D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1234CCu;
            // 0x1234d0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123490u: goto label_123490;
            case 0x1234ACu: goto label_1234ac;
            case 0x1234C0u: goto label_1234c0;
            case 0x1234C4u: goto label_1234c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1234D4u;
    // 0x1234d4: 0x0  nop
    ctx->pc = 0x1234d4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
