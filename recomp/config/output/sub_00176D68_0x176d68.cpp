#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00176D68
// Address: 0x176d68 - 0x176db0
void sub_00176D68_0x176d68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00176D68_0x176d68");
#endif

    switch (ctx->pc) {
        case 0x176d88u: goto label_176d88;
        default: break;
    }

    ctx->pc = 0x176d68u;

    // 0x176d68: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x176d68u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x176d6c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x176d6cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x176d70: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x176d70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x176d74: 0x24900cc0  addiu       $s0, $a0, 0xCC0
    ctx->pc = 0x176d74u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), 3264));
    // 0x176d78: 0x8c44f140  lw          $a0, -0xEC0($v0)
    ctx->pc = 0x176d78u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294963520)));
    // 0x176d7c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x176d7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x176d80: 0xc056ea0  jal         func_15BA80
    ctx->pc = 0x176D80u;
    SET_GPR_U32(ctx, 31, 0x176D88u);
    ctx->pc = 0x15BA80u;
    if (runtime->hasFunction(0x15BA80u)) {
        auto targetFn = runtime->lookupFunction(0x15BA80u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176D88u; }
        if (ctx->pc != 0x176D88u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015BA80_0x15ba80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x176D88u; }
        if (ctx->pc != 0x176D88u) { return; }
    }
    ctx->pc = 0x176D88u;
label_176d88:
    // 0x176d88: 0x8e030264  lw          $v1, 0x264($s0)
    ctx->pc = 0x176d88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 612)));
    // 0x176d8c: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x176d8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x176d90: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x176d90u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x176d94: 0xae030264  sw          $v1, 0x264($s0)
    ctx->pc = 0x176d94u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 612), GPR_U32(ctx, 3));
    // 0x176d98: 0x8e040288  lw          $a0, 0x288($s0)
    ctx->pc = 0x176d98u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 648)));
    // 0x176d9c: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x176d9cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x176da0: 0xae040288  sw          $a0, 0x288($s0)
    ctx->pc = 0x176da0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 648), GPR_U32(ctx, 4));
    // 0x176da4: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x176da4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x176da8: 0x3e00008  jr          $ra
    ctx->pc = 0x176DA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x176DACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x176DA8u;
            // 0x176dac: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x176D88u: goto label_176d88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x176DB0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
