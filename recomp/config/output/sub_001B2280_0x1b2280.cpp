#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B2280
// Address: 0x1b2280 - 0x1b22b4
void sub_001B2280_0x1b2280(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B2280_0x1b2280");
#endif

    switch (ctx->pc) {
        case 0x1b22a0u: goto label_1b22a0;
        default: break;
    }

    ctx->pc = 0x1b2280u;

    // 0x1b2280: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1b2280u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1b2284: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1b2284u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1b2288: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1b2288u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1b228c: 0x80830000  lb          $v1, 0x0($a0)
    ctx->pc = 0x1b228cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1b2290: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B2290u;
    {
        const bool branch_taken_0x1b2290 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B2294u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2290u;
            // 0x1b2294: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b2290) {
            ctx->pc = 0x1B22A0u;
            goto label_1b22a0;
        }
    }
    ctx->pc = 0x1B2298u;
    // 0x1b2298: 0xc06c608  jal         func_1B1820
    ctx->pc = 0x1B2298u;
    SET_GPR_U32(ctx, 31, 0x1B22A0u);
    ctx->pc = 0x1B229Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1B2298u;
            // 0x1b229c: 0x26040004  addiu       $a0, $s0, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1B1820u;
    if (runtime->hasFunction(0x1B1820u)) {
        auto targetFn = runtime->lookupFunction(0x1B1820u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B22A0u; }
        if (ctx->pc != 0x1B22A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001B1820_0x1b1820(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B22A0u; }
        if (ctx->pc != 0x1B22A0u) { return; }
    }
    ctx->pc = 0x1B22A0u;
label_1b22a0:
    // 0x1b22a0: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1b22a0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1b22a4: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1b22a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b22a8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1b22a8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1b22ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1B22ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B22B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B22ACu;
            // 0x1b22b0: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B22A0u: goto label_1b22a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B22B4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
