#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001E7E88
// Address: 0x1e7e88 - 0x1e7ed0
void sub_001E7E88_0x1e7e88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001E7E88_0x1e7e88");
#endif

    switch (ctx->pc) {
        case 0x1e7eb8u: goto label_1e7eb8;
        default: break;
    }

    ctx->pc = 0x1e7e88u;

    // 0x1e7e88: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1e7e88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1e7e8c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1e7e8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1e7e90: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1e7e90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1e7e94: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1e7e94u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7e98: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1e7e98u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1e7e9c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1e7e9cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7ea0: 0xafc60008  sw          $a2, 0x8($fp)
    ctx->pc = 0x1e7ea0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 6));
    // 0x1e7ea4: 0xa7c20004  sh          $v0, 0x4($fp)
    ctx->pc = 0x1e7ea4u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1e7ea8: 0x8fc20008  lw          $v0, 0x8($fp)
    ctx->pc = 0x1e7ea8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1e7eac: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1e7eacu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1e7eb0: 0xc045194  jal         func_114650
    ctx->pc = 0x1E7EB0u;
    SET_GPR_U32(ctx, 31, 0x1E7EB8u);
    ctx->pc = 0x114650u;
    if (runtime->hasFunction(0x114650u)) {
        auto targetFn = runtime->lookupFunction(0x114650u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7EB8u; }
        if (ctx->pc != 0x1E7EB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114650_0x114650(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1E7EB8u; }
        if (ctx->pc != 0x1E7EB8u) { return; }
    }
    ctx->pc = 0x1E7EB8u;
label_1e7eb8:
    // 0x1e7eb8: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1e7eb8u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1e7ebc: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1e7ebcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1e7ec0: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1e7ec0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1e7ec4: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1e7ec4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1e7ec8: 0x3e00008  jr          $ra
    ctx->pc = 0x1E7EC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1E7EB8u: goto label_1e7eb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1E7ED0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
