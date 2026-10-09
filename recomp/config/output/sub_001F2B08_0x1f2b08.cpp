#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F2B08
// Address: 0x1f2b08 - 0x1f2b58
void sub_001F2B08_0x1f2b08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F2B08_0x1f2b08");
#endif

    switch (ctx->pc) {
        case 0x1f2b3cu: goto label_1f2b3c;
        default: break;
    }

    ctx->pc = 0x1f2b08u;

    // 0x1f2b08: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1f2b08u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1f2b0c: 0xffbe0010  sd          $fp, 0x10($sp)
    ctx->pc = 0x1f2b0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 30));
    // 0x1f2b10: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1f2b10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1f2b14: 0x3a0f02d  daddu       $fp, $sp, $zero
    ctx->pc = 0x1f2b14u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2b18: 0xafc40000  sw          $a0, 0x0($fp)
    ctx->pc = 0x1f2b18u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1f2b1c: 0xafc50004  sw          $a1, 0x4($fp)
    ctx->pc = 0x1f2b1cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1f2b20: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1f2b20u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1f2b24: 0x2442003c  addiu       $v0, $v0, 0x3C
    ctx->pc = 0x1f2b24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 60));
    // 0x1f2b28: 0x8fc40004  lw          $a0, 0x4($fp)
    ctx->pc = 0x1f2b28u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1f2b2c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x1f2b2cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2b30: 0x24060034  addiu       $a2, $zero, 0x34
    ctx->pc = 0x1f2b30u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 52));
    // 0x1f2b34: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F2B34u;
    SET_GPR_U32(ctx, 31, 0x1F2B3Cu);
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2B3Cu; }
        if (ctx->pc != 0x1F2B3Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F2B3Cu; }
        if (ctx->pc != 0x1F2B3Cu) { return; }
    }
    ctx->pc = 0x1F2B3Cu;
label_1f2b3c:
    // 0x1f2b3c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f2b3cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2b40: 0x3c0e82d  daddu       $sp, $fp, $zero
    ctx->pc = 0x1f2b40u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f2b44: 0xdfbe0010  ld          $fp, 0x10($sp)
    ctx->pc = 0x1f2b44u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f2b48: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1f2b48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1f2b4c: 0x27bd0020  addiu       $sp, $sp, 0x20
    ctx->pc = 0x1f2b4cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1f2b50: 0x3e00008  jr          $ra
    ctx->pc = 0x1F2B50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F2B3Cu: goto label_1f2b3c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F2B58u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
