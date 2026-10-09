#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F16B8
// Address: 0x1f16b8 - 0x1f1700
void sub_001F16B8_0x1f16b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F16B8_0x1f16b8");
#endif

    switch (ctx->pc) {
        case 0x1f16e0u: goto label_1f16e0;
        default: break;
    }

    ctx->pc = 0x1f16b8u;

    // 0x1f16b8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f16b8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f16bc: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f16bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f16c0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f16c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f16c4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f16c4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f16c8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f16c8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f16cc: 0xafc00004  sw          $zero, 0x4($fp)
    ctx->pc = 0x1f16ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 0));
    // 0x1f16d0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f16d0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f16d4: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1f16d4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f16d8: 0xc07c725  jal         func_1F1C94
    ctx->pc = 0x1F16D8u;
    SET_GPR_U32(ctx, 31, 0x1F16E0u);
    ctx->pc = 0x1F1C94u;
    if (runtime->hasFunction(0x1F1C94u)) {
        auto targetFn = runtime->lookupFunction(0x1F1C94u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F16E0u; }
        if (ctx->pc != 0x1F16E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1C94_0x1f1c94(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F16E0u; }
        if (ctx->pc != 0x1F16E0u) { return; }
    }
    ctx->pc = 0x1F16E0u;
label_1f16e0:
    // 0x1f16e0: 0xafc20004  sw          $v0, 0x4($fp)
    ctx->pc = 0x1f16e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1f16e4: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1f16e4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f16e8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f16e8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f16ec: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f16ecu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f16f0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f16f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f16f4: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f16f4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f16f8: 0x3e00008  jr          $ra
    ctx->pc = 0x1F16F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F16E0u: goto label_1f16e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F1700u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
