#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DB1A8
// Address: 0x1db1a8 - 0x1db1fc
void sub_001DB1A8_0x1db1a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DB1A8_0x1db1a8");
#endif

    switch (ctx->pc) {
        case 0x1db1e0u: goto label_1db1e0;
        default: break;
    }

    ctx->pc = 0x1db1a8u;

    // 0x1db1a8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1db1a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1db1ac: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1db1acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1db1b0: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1db1b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1db1b4: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1db1b4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db1b8: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1db1b8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1db1bc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1db1bcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1db1c0: 0x27c30004  addiu       $v1, $fp, 0x4
    ctx->pc = 0x1db1c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 30), 4));
    // 0x1db1c4: 0x8c440520  lw          $a0, 0x520($v0)
    ctx->pc = 0x1db1c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1db1c8: 0x60282d  daddu       $a1, $v1, $zero
    ctx->pc = 0x1db1c8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db1cc: 0x24060380  addiu       $a2, $zero, 0x380
    ctx->pc = 0x1db1ccu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 896));
    // 0x1db1d0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1db1d0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db1d4: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1db1d4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1db1d8: 0xc07c80a  jal         func_1F2028
    ctx->pc = 0x1DB1D8u;
    SET_GPR_U32(ctx, 31, 0x1DB1E0u);
    ctx->pc = 0x1F2028u;
    if (runtime->hasFunction(0x1F2028u)) {
        auto targetFn = runtime->lookupFunction(0x1F2028u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB1E0u; }
        if (ctx->pc != 0x1DB1E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2028_0x1f2028(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DB1E0u; }
        if (ctx->pc != 0x1DB1E0u) { return; }
    }
    ctx->pc = 0x1DB1E0u;
label_1db1e0:
    // 0x1db1e0: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x1db1e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1db1e4: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1db1e4u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1db1e8: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1db1e8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1db1ec: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1db1ecu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1db1f0: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1db1f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1db1f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1DB1F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DB1E0u: goto label_1db1e0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DB1FCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
