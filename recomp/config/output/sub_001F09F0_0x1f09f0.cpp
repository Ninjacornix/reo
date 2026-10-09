#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F09F0
// Address: 0x1f09f0 - 0x1f0a3c
void sub_001F09F0_0x1f09f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F09F0_0x1f09f0");
#endif

    switch (ctx->pc) {
        case 0x1f0a20u: goto label_1f0a20;
        default: break;
    }

    ctx->pc = 0x1f09f0u;

    // 0x1f09f0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f09f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f09f4: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f09f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f09f8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f09f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f09fc: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f09fcu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0a00: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f0a00u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f0a04: 0xa7c00004  sh          $zero, 0x4($fp)
    ctx->pc = 0x1f0a04u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 4), (uint16_t)GPR_U32(ctx, 0));
    // 0x1f0a08: 0x27c20004  addiu       $v0, $fp, 0x4
    ctx->pc = 0x1f0a08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 30), 4));
    // 0x1f0a0c: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1f0a0cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f0a10: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f0a10u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0a14: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1f0a14u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1f0a18: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F0A18u;
    SET_GPR_U32(ctx, 31, 0x1F0A20u);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0A20u; }
        if (ctx->pc != 0x1F0A20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F0A20u; }
        if (ctx->pc != 0x1F0A20u) { return; }
    }
    ctx->pc = 0x1F0A20u;
label_1f0a20:
    // 0x1f0a20: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f0a20u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0a24: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f0a24u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f0a28: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f0a28u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f0a2c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f0a2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f0a30: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f0a30u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f0a34: 0x3e00008  jr          $ra
    ctx->pc = 0x1F0A34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F0A20u: goto label_1f0a20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F0A3Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
