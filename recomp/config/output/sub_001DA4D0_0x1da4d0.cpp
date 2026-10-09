#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001DA4D0
// Address: 0x1da4d0 - 0x1da51c
void sub_001DA4D0_0x1da4d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001DA4D0_0x1da4d0");
#endif

    switch (ctx->pc) {
        case 0x1da504u: goto label_1da504;
        default: break;
    }

    ctx->pc = 0x1da4d0u;

    // 0x1da4d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1da4d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1da4d4: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1da4d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1da4d8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1da4d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1da4dc: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1da4dcu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da4e0: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1da4e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1da4e4: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1da4e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da4e8: 0xa7c20004  sh          $v0, 0x4($fp)
    ctx->pc = 0x1da4e8u;
    WRITE16(ADD32(GPR_U32(ctx, 30), 4), (uint16_t)GPR_U32(ctx, 2));
    // 0x1da4ec: 0x97c20004  lhu         $v0, 0x4($fp)
    ctx->pc = 0x1da4ecu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1da4f0: 0x8fc40000  lw          $a0, 0x0($fp)
    ctx->pc = 0x1da4f0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1da4f4: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1da4f4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da4f8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1da4f8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da4fc: 0xc076947  jal         func_1DA51C
    ctx->pc = 0x1DA4FCu;
    SET_GPR_U32(ctx, 31, 0x1DA504u);
    ctx->pc = 0x1DA51Cu;
    if (runtime->hasFunction(0x1DA51Cu)) {
        auto targetFn = runtime->lookupFunction(0x1DA51Cu);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA504u; }
        if (ctx->pc != 0x1DA504u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001DA51C_0x1da51c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DA504u; }
        if (ctx->pc != 0x1DA504u) { return; }
    }
    ctx->pc = 0x1DA504u;
label_1da504:
    // 0x1da504: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1da504u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1da508: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1da508u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1da50c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1da50cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1da510: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1da510u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1da514: 0x3e00008  jr          $ra
    ctx->pc = 0x1DA514u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DA504u: goto label_1da504;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DA51Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
