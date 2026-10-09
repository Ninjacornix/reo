#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B2D00
// Address: 0x1b2d00 - 0x1b2d7c
void sub_001B2D00_0x1b2d00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B2D00_0x1b2d00");
#endif

    switch (ctx->pc) {
        case 0x1b2d44u: goto label_1b2d44;
        case 0x1b2d70u: goto label_1b2d70;
        default: break;
    }

    ctx->pc = 0x1b2d00u;

    // 0x1b2d00: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1b2d00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1b2d04: 0x3c03004c  lui         $v1, 0x4C
    ctx->pc = 0x1b2d04u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)76 << 16));
    // 0x1b2d08: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1b2d08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1b2d0c: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2d0cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2d10: 0x9425a828  lhu         $a1, -0x57D8($at)
    ctx->pc = 0x1b2d10u;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294944808)));
    // 0x1b2d14: 0x2463a420  addiu       $v1, $v1, -0x5BE0
    ctx->pc = 0x1b2d14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294943776));
    // 0x1b2d18: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b2d18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b2d1c: 0x942443dc  lhu         $a0, 0x43DC($at)
    ctx->pc = 0x1b2d1cu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1b2d20: 0x42040  sll         $a0, $a0, 1
    ctx->pc = 0x1b2d20u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1b2d24: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1b2d24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b2d28: 0x94630000  lhu         $v1, 0x0($v1)
    ctx->pc = 0x1b2d28u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b2d2c: 0x10650010  beq         $v1, $a1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1B2D2Cu;
    {
        const bool branch_taken_0x1b2d2c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        if (branch_taken_0x1b2d2c) {
            ctx->pc = 0x1B2D70u;
            goto label_1b2d70;
        }
    }
    ctx->pc = 0x1B2D34u;
    // 0x1b2d34: 0x10a00003  beqz        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B2D34u;
    {
        const bool branch_taken_0x1b2d34 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b2d34) {
            ctx->pc = 0x1B2D44u;
            goto label_1b2d44;
        }
    }
    ctx->pc = 0x1B2D3Cu;
    // 0x1b2d3c: 0xc06c788  jal         func_1B1E20
    ctx->pc = 0x1B2D3Cu;
    SET_GPR_U32(ctx, 31, 0x1B2D44u);
    ctx->pc = 0x1B1E20u;
    if (runtime->hasFunction(0x1B1E20u)) {
        auto targetFn = runtime->lookupFunction(0x1B1E20u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2D44u; }
        if (ctx->pc != 0x1B2D44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1E20_0x1b1e20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2D44u; }
        if (ctx->pc != 0x1B2D44u) { return; }
    }
    ctx->pc = 0x1B2D44u;
label_1b2d44:
    // 0x1b2d44: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b2d44u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b2d48: 0x3c02004c  lui         $v0, 0x4C
    ctx->pc = 0x1b2d48u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)76 << 16));
    // 0x1b2d4c: 0x942343dc  lhu         $v1, 0x43DC($at)
    ctx->pc = 0x1b2d4cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17372)));
    // 0x1b2d50: 0x2442a420  addiu       $v0, $v0, -0x5BE0
    ctx->pc = 0x1b2d50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294943776));
    // 0x1b2d54: 0x31840  sll         $v1, $v1, 1
    ctx->pc = 0x1b2d54u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 1));
    // 0x1b2d58: 0x3c01004c  lui         $at, 0x4C
    ctx->pc = 0x1b2d58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)76 << 16));
    // 0x1b2d5c: 0x431821  addu        $v1, $v0, $v1
    ctx->pc = 0x1b2d5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b2d60: 0x94620000  lhu         $v0, 0x0($v1)
    ctx->pc = 0x1b2d60u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1b2d64: 0xa422a828  sh          $v0, -0x57D8($at)
    ctx->pc = 0x1b2d64u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294944808), (uint16_t)GPR_U32(ctx, 2));
    // 0x1b2d68: 0xc0746c4  jal         func_1D1B10
    ctx->pc = 0x1B2D68u;
    SET_GPR_U32(ctx, 31, 0x1B2D70u);
    ctx->pc = 0x1B2D6Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2D68u;
            // 0x1b2d6c: 0x94640000  lhu         $a0, 0x0($v1) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D1B10u;
    if (runtime->hasFunction(0x1D1B10u)) {
        auto targetFn = runtime->lookupFunction(0x1D1B10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2D70u; }
        if (ctx->pc != 0x1B2D70u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D1B10_0x1d1b10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B2D70u; }
        if (ctx->pc != 0x1B2D70u) { return; }
    }
    ctx->pc = 0x1B2D70u;
label_1b2d70:
    // 0x1b2d70: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1b2d70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b2d74: 0x3e00008  jr          $ra
    ctx->pc = 0x1B2D74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B2D78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2D74u;
            // 0x1b2d78: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B2D44u: goto label_1b2d44;
            case 0x1B2D70u: goto label_1b2d70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B2D7Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
