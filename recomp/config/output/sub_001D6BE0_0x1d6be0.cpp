#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D6BE0
// Address: 0x1d6be0 - 0x1d6c20
void sub_001D6BE0_0x1d6be0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D6BE0_0x1d6be0");
#endif

    switch (ctx->pc) {
        case 0x1d6bf0u: goto label_1d6bf0;
        default: break;
    }

    ctx->pc = 0x1d6be0u;

    // 0x1d6be0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d6be0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d6be4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d6be4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d6be8: 0xc075e78  jal         func_1D79E0
    ctx->pc = 0x1D6BE8u;
    SET_GPR_U32(ctx, 31, 0x1D6BF0u);
    ctx->pc = 0x1D79E0u;
    if (runtime->hasFunction(0x1D79E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D79E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6BF0u; }
        if (ctx->pc != 0x1D6BF0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D79E0_0x1d79e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D6BF0u; }
        if (ctx->pc != 0x1D6BF0u) { return; }
    }
    ctx->pc = 0x1D6BF0u;
label_1d6bf0:
    // 0x1d6bf0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d6bf0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d6bf4: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1d6bf4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1d6bf8: 0xa0204600  sb          $zero, 0x4600($at)
    ctx->pc = 0x1d6bf8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 17920), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d6bfc: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1d6bfcu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1d6c00: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d6c00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d6c04: 0xac2045e8  sw          $zero, 0x45E8($at)
    ctx->pc = 0x1d6c04u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17896), GPR_U32(ctx, 0));
    // 0x1d6c08: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d6c08u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d6c0c: 0xac2045f8  sw          $zero, 0x45F8($at)
    ctx->pc = 0x1d6c0cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17912), GPR_U32(ctx, 0));
    // 0x1d6c10: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d6c10u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d6c14: 0x3e00008  jr          $ra
    ctx->pc = 0x1D6C14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D6C18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D6C14u;
            // 0x1d6c18: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D6BF0u: goto label_1d6bf0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D6C1Cu;
    // 0x1d6c1c: 0x0  nop
    ctx->pc = 0x1d6c1cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
