#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176DB0
// Address: 0x176db0 - 0x176de8
void sub_00176DB0_0x176db0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176DB0_0x176db0");
#endif

    switch (ctx->pc) {
        case 0x176dc8u: goto label_176dc8;
        default: break;
    }

    ctx->pc = 0x176db0u;

    // 0x176db0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x176db0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x176db4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x176db4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x176db8: 0x24900cc0  addiu       $s0, $a0, 0xCC0
    ctx->pc = 0x176db8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 3264));
    // 0x176dbc: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x176dbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x176dc0: 0xc056ea0  jal         func_15BA80
    ctx->pc = 0x176DC0u;
    SET_GPR_U32(ctx, 31, 0x176DC8u);
    ctx->pc = 0x176DC4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x176DC0u;
            // 0x176dc4: 0x8e04029c  lw          $a0, 0x29C($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 668)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15BA80u;
    if (runtime->hasFunction(0x15BA80u)) {
        auto targetFn = runtime->lookupFunction(0x15BA80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176DC8u; }
        if (ctx->pc != 0x176DC8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BA80_0x15ba80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176DC8u; }
        if (ctx->pc != 0x176DC8u) { return; }
    }
    ctx->pc = 0x176DC8u;
label_176dc8:
    // 0x176dc8: 0x8e030298  lw          $v1, 0x298($s0)
    ctx->pc = 0x176dc8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 664)));
    // 0x176dcc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x176dccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176dd0: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x176dd0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x176dd4: 0xae030298  sw          $v1, 0x298($s0)
    ctx->pc = 0x176dd4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 664), GPR_U32(ctx, 3));
    // 0x176dd8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x176dd8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176ddc: 0x3e00008  jr          $ra
    ctx->pc = 0x176DDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176DE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176DDCu;
            // 0x176de0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176DC8u: goto label_176dc8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176DE4u;
    // 0x176de4: 0x0  nop
    ctx->pc = 0x176de4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
