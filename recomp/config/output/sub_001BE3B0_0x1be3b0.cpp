#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BE3B0
// Address: 0x1be3b0 - 0x1be400
void sub_001BE3B0_0x1be3b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BE3B0_0x1be3b0");
#endif

    switch (ctx->pc) {
        case 0x1be3d4u: goto label_1be3d4;
        case 0x1be3f0u: goto label_1be3f0;
        default: break;
    }

    ctx->pc = 0x1be3b0u;

    // 0x1be3b0: 0x27bdfee0  addiu       $sp, $sp, -0x120
    ctx->pc = 0x1be3b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967008));
    // 0x1be3b4: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1be3b4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1be3b8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1be3b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1be3bc: 0x24a50440  addiu       $a1, $a1, 0x440
    ctx->pc = 0x1be3bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1088));
    // 0x1be3c0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1be3c0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1be3c4: 0x24061234  addiu       $a2, $zero, 0x1234
    ctx->pc = 0x1be3c4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4660));
    // 0x1be3c8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1be3c8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1be3cc: 0xc06f918  jal         func_1BE460
    ctx->pc = 0x1BE3CCu;
    SET_GPR_U32(ctx, 31, 0x1BE3D4u);
    ctx->pc = 0x1BE3D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE3CCu;
            // 0x1be3d0: 0x27a40020  addiu       $a0, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1BE460u;
    if (runtime->hasFunction(0x1BE460u)) {
        auto targetFn = runtime->lookupFunction(0x1BE460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE3D4u; }
        if (ctx->pc != 0x1BE3D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001BE460_0x1be460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE3D4u; }
        if (ctx->pc != 0x1BE3D4u) { return; }
    }
    ctx->pc = 0x1BE3D4u;
label_1be3d4:
    // 0x1be3d4: 0x3c040025  lui         $a0, 0x25
    ctx->pc = 0x1be3d4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)37 << 16));
    // 0x1be3d8: 0x36060004  ori         $a2, $s0, 0x4
    ctx->pc = 0x1be3d8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 16) | (uint64_t)(uint16_t)4);
    // 0x1be3dc: 0x24840498  addiu       $a0, $a0, 0x498
    ctx->pc = 0x1be3dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1176));
    // 0x1be3e0: 0x27a50020  addiu       $a1, $sp, 0x20
    ctx->pc = 0x1be3e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1be3e4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1be3e4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1be3e8: 0xc046b60  jal         func_11AD80
    ctx->pc = 0x1BE3E8u;
    SET_GPR_U32(ctx, 31, 0x1BE3F0u);
    ctx->pc = 0x1BE3ECu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE3E8u;
            // 0x1be3ec: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11AD80u;
    if (runtime->hasFunction(0x11AD80u)) {
        auto targetFn = runtime->lookupFunction(0x11AD80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE3F0u; }
        if (ctx->pc != 0x1BE3F0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011AD80_0x11ad80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BE3F0u; }
        if (ctx->pc != 0x1BE3F0u) { return; }
    }
    ctx->pc = 0x1BE3F0u;
label_1be3f0:
    // 0x1be3f0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1be3f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1be3f4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1be3f4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1be3f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1BE3F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BE3FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BE3F8u;
            // 0x1be3fc: 0x27bd0120  addiu       $sp, $sp, 0x120 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 288));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BE3D4u: goto label_1be3d4;
            case 0x1BE3F0u: goto label_1be3f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BE400u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
