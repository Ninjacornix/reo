#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177D90
// Address: 0x177d90 - 0x177dd0
void sub_00177D90_0x177d90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177D90_0x177d90");
#endif

    switch (ctx->pc) {
        case 0x177db0u: goto label_177db0;
        default: break;
    }

    ctx->pc = 0x177d90u;

    // 0x177d90: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x177d90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x177d94: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x177d94u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177d98: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x177d98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x177d9c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x177d9cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177da0: 0x26040018  addiu       $a0, $s0, 0x18
    ctx->pc = 0x177da0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x177da4: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x177da4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x177da8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x177DA8u;
    SET_GPR_U32(ctx, 31, 0x177DB0u);
    ctx->pc = 0x177DACu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x177DA8u;
            // 0x177dac: 0x240600f0  addiu       $a2, $zero, 0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 240));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177DB0u; }
        if (ctx->pc != 0x177DB0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177DB0u; }
        if (ctx->pc != 0x177DB0u) { return; }
    }
    ctx->pc = 0x177DB0u;
label_177db0:
    // 0x177db0: 0x8e02019c  lw          $v0, 0x19C($s0)
    ctx->pc = 0x177db0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 412)));
    // 0x177db4: 0xae000014  sw          $zero, 0x14($s0)
    ctx->pc = 0x177db4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 0));
    // 0x177db8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x177db8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x177dbc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x177dbcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x177dc0: 0xae02019c  sw          $v0, 0x19C($s0)
    ctx->pc = 0x177dc0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 412), GPR_U32(ctx, 2));
    // 0x177dc4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x177dc4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x177dc8: 0x3e00008  jr          $ra
    ctx->pc = 0x177DC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177DCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177DC8u;
            // 0x177dcc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x177DB0u: goto label_177db0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x177DD0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
