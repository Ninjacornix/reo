#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C52B0
// Address: 0x1c52b0 - 0x1c5300
void sub_001C52B0_0x1c52b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C52B0_0x1c52b0");
#endif

    switch (ctx->pc) {
        case 0x1c52d4u: goto label_1c52d4;
        default: break;
    }

    ctx->pc = 0x1c52b0u;

    // 0x1c52b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c52b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c52b4: 0x3c050032  lui         $a1, 0x32
    ctx->pc = 0x1c52b4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)50 << 16));
    // 0x1c52b8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c52b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c52bc: 0x24a541a0  addiu       $a1, $a1, 0x41A0
    ctx->pc = 0x1c52bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 16800));
    // 0x1c52c0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c52c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c52c4: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x1c52c4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1c52c8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1c52c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c52cc: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1C52CCu;
    SET_GPR_U32(ctx, 31, 0x1C52D4u);
    ctx->pc = 0x1C52D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C52CCu;
            // 0x1c52d0: 0x26040008  addiu       $a0, $s0, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C52D4u; }
        if (ctx->pc != 0x1C52D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C52D4u; }
        if (ctx->pc != 0x1C52D4u) { return; }
    }
    ctx->pc = 0x1C52D4u;
label_1c52d4:
    // 0x1c52d4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1c52d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1c52d8: 0x90234476  lbu         $v1, 0x4476($at)
    ctx->pc = 0x1c52d8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17526)));
    // 0x1c52dc: 0xa2030018  sb          $v1, 0x18($s0)
    ctx->pc = 0x1c52dcu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 24), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c52e0: 0xa2000019  sb          $zero, 0x19($s0)
    ctx->pc = 0x1c52e0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 25), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c52e4: 0xa200001b  sb          $zero, 0x1B($s0)
    ctx->pc = 0x1c52e4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 27), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c52e8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c52e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c52ec: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c52ecu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c52f0: 0x3e00008  jr          $ra
    ctx->pc = 0x1C52F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C52F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C52F0u;
            // 0x1c52f4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C52D4u: goto label_1c52d4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C52F8u;
    // 0x1c52f8: 0x0  nop
    ctx->pc = 0x1c52f8u;
    // NOP
    // 0x1c52fc: 0x0  nop
    ctx->pc = 0x1c52fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
