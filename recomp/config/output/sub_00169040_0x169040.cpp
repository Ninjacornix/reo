#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00169040
// Address: 0x169040 - 0x169068
void sub_00169040_0x169040(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00169040_0x169040");
#endif

    switch (ctx->pc) {
        case 0x169050u: goto label_169050;
        default: break;
    }

    ctx->pc = 0x169040u;

    // 0x169040: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x169040u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x169044: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x169044u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x169048: 0xc05a41a  jal         func_169068
    ctx->pc = 0x169048u;
    SET_GPR_U32(ctx, 31, 0x169050u);
    ctx->pc = 0x169068u;
    if (runtime->hasFunction(0x169068u)) {
        auto targetFn = runtime->lookupFunction(0x169068u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169050u; }
        if (ctx->pc != 0x169050u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00169068_0x169068(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x169050u; }
        if (ctx->pc != 0x169050u) { return; }
    }
    ctx->pc = 0x169050u;
label_169050:
    // 0x169050: 0x384201bf  xori        $v0, $v0, 0x1BF
    ctx->pc = 0x169050u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)447);
    // 0x169054: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x169054u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x169058: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x169058u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x16905c: 0x3e00008  jr          $ra
    ctx->pc = 0x16905Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x169060u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16905Cu;
            // 0x169060: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x169050u: goto label_169050;
            default: break;
        }
        return;
    }
    ctx->pc = 0x169064u;
    // 0x169064: 0x0  nop
    ctx->pc = 0x169064u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
