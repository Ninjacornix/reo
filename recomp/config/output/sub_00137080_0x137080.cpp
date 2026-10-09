#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00137080
// Address: 0x137080 - 0x1370a0
void sub_00137080_0x137080(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00137080_0x137080");
#endif

    switch (ctx->pc) {
        case 0x137090u: goto label_137090;
        default: break;
    }

    ctx->pc = 0x137080u;

    // 0x137080: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x137080u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x137084: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x137084u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x137088: 0xc04d558  jal         func_135560
    ctx->pc = 0x137088u;
    SET_GPR_U32(ctx, 31, 0x137090u);
    ctx->pc = 0x135560u;
    if (runtime->hasFunction(0x135560u)) {
        auto targetFn = runtime->lookupFunction(0x135560u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137090u; }
        if (ctx->pc != 0x137090u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137090u; }
        if (ctx->pc != 0x137090u) { return; }
    }
    ctx->pc = 0x137090u;
label_137090:
    // 0x137090: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x137090u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x137094: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x137094u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x137098: 0x3e00008  jr          $ra
    ctx->pc = 0x137098u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13709Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x137098u;
            // 0x13709c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x137090u: goto label_137090;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1370A0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
