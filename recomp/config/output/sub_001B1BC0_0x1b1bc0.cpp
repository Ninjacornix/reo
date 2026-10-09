#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B1BC0
// Address: 0x1b1bc0 - 0x1b1c10
void sub_001B1BC0_0x1b1bc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B1BC0_0x1b1bc0");
#endif

    switch (ctx->pc) {
        case 0x1b1be0u: goto label_1b1be0;
        case 0x1b1bf0u: goto label_1b1bf0;
        default: break;
    }

    ctx->pc = 0x1b1bc0u;

    // 0x1b1bc0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b1bc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b1bc4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b1bc4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1bc8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b1bc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b1bcc: 0x240607d0  addiu       $a2, $zero, 0x7D0
    ctx->pc = 0x1b1bccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2000));
    // 0x1b1bd0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b1bd0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b1bd4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1b1bd4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1bd8: 0xc06c6d0  jal         func_1B1B40
    ctx->pc = 0x1B1BD8u;
    SET_GPR_U32(ctx, 31, 0x1B1BE0u);
    ctx->pc = 0x1B1BDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1BD8u;
            // 0x1b1bdc: 0x26040004  addiu       $a0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1B40u;
    if (runtime->hasFunction(0x1B1B40u)) {
        auto targetFn = runtime->lookupFunction(0x1B1B40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1BE0u; }
        if (ctx->pc != 0x1B1BE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1B40_0x1b1b40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1BE0u; }
        if (ctx->pc != 0x1B1BE0u) { return; }
    }
    ctx->pc = 0x1B1BE0u;
label_1b1be0:
    // 0x1b1be0: 0x26040fa4  addiu       $a0, $s0, 0xFA4
    ctx->pc = 0x1b1be0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4004));
    // 0x1b1be4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1b1be4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b1be8: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1B1BE8u;
    SET_GPR_U32(ctx, 31, 0x1B1BF0u);
    ctx->pc = 0x1B1BECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1BE8u;
            // 0x1b1bec: 0x24060fa0  addiu       $a2, $zero, 0xFA0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4000));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1BF0u; }
        if (ctx->pc != 0x1B1BF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B1BF0u; }
        if (ctx->pc != 0x1B1BF0u) { return; }
    }
    ctx->pc = 0x1B1BF0u;
label_1b1bf0:
    // 0x1b1bf0: 0xa2000001  sb          $zero, 0x1($s0)
    ctx->pc = 0x1b1bf0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b1bf4: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1b1bf4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b1bf8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b1bf8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b1bfc: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b1bfcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b1c00: 0x3e00008  jr          $ra
    ctx->pc = 0x1B1C00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B1C04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B1C00u;
            // 0x1b1c04: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B1BE0u: goto label_1b1be0;
            case 0x1B1BF0u: goto label_1b1bf0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B1C08u;
    // 0x1b1c08: 0x0  nop
    ctx->pc = 0x1b1c08u;
    // NOP
    // 0x1b1c0c: 0x0  nop
    ctx->pc = 0x1b1c0cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
