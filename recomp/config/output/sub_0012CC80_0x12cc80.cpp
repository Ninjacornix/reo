#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012CC80
// Address: 0x12cc80 - 0x12ccb0
void sub_0012CC80_0x12cc80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012CC80_0x12cc80");
#endif

    switch (ctx->pc) {
        case 0x12cc94u: goto label_12cc94;
        default: break;
    }

    ctx->pc = 0x12cc80u;

    // 0x12cc80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12cc80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12cc84: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x12cc84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12cc88: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x12cc88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12cc8c: 0xc04b268  jal         func_12C9A0
    ctx->pc = 0x12CC8Cu;
    SET_GPR_U32(ctx, 31, 0x12CC94u);
    ctx->pc = 0x12CC90u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12CC8Cu;
            // 0x12cc90: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12C9A0u;
    if (runtime->hasFunction(0x12C9A0u)) {
        auto targetFn = runtime->lookupFunction(0x12C9A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CC94u; }
        if (ctx->pc != 0x12CC94u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C9A0_0x12c9a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12CC94u; }
        if (ctx->pc != 0x12CC94u) { return; }
    }
    ctx->pc = 0x12CC94u;
label_12cc94:
    // 0x12cc94: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12cc94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12cc98: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x12cc98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12cc9c: 0xa2020001  sb          $v0, 0x1($s0)
    ctx->pc = 0x12cc9cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 2));
    // 0x12cca0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x12cca0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12cca4: 0x3e00008  jr          $ra
    ctx->pc = 0x12CCA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12CCA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12CCA4u;
            // 0x12cca8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12CC94u: goto label_12cc94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12CCACu;
    // 0x12ccac: 0x0  nop
    ctx->pc = 0x12ccacu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
