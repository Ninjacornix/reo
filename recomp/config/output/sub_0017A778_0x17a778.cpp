#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017A778
// Address: 0x17a778 - 0x17a7b4
void sub_0017A778_0x17a778(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017A778_0x17a778");
#endif

    switch (ctx->pc) {
        case 0x17a7a0u: goto label_17a7a0;
        default: break;
    }

    ctx->pc = 0x17a778u;

    // 0x17a778: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17a778u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17a77c: 0xc0382d  daddu       $a3, $a2, $zero
    ctx->pc = 0x17a77cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a780: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17a780u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x17a784: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x17a784u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17a788: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x17a788u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x17a78c: 0x26020008  addiu       $v0, $s0, 0x8
    ctx->pc = 0x17a78cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 8));
    // 0x17a790: 0x8c460008  lw          $a2, 0x8($v0)
    ctx->pc = 0x17a790u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x17a794: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x17a794u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x17a798: 0xc053e42  jal         func_14F908
    ctx->pc = 0x17A798u;
    SET_GPR_U32(ctx, 31, 0x17A7A0u);
    ctx->pc = 0x17A79Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17A798u;
            // 0x17a79c: 0x8c450004  lw          $a1, 0x4($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x14F908u;
    if (runtime->hasFunction(0x14F908u)) {
        auto targetFn = runtime->lookupFunction(0x14F908u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A7A0u; }
        if (ctx->pc != 0x17A7A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0014F908_0x14f908(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17A7A0u; }
        if (ctx->pc != 0x17A7A0u) { return; }
    }
    ctx->pc = 0x17A7A0u;
label_17a7a0:
    // 0x17a7a0: 0xae000004  sw          $zero, 0x4($s0)
    ctx->pc = 0x17a7a0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 0));
    // 0x17a7a4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x17a7a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17a7a8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x17a7a8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17a7ac: 0x3e00008  jr          $ra
    ctx->pc = 0x17A7ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17A7B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17A7ACu;
            // 0x17a7b0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17A7A0u: goto label_17a7a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17A7B4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
