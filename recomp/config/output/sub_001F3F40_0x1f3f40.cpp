#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F3F40
// Address: 0x1f3f40 - 0x1f3f80
void sub_001F3F40_0x1f3f40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F3F40_0x1f3f40");
#endif

    switch (ctx->pc) {
        case 0x1f3f48u: goto label_1f3f48;
        default: break;
    }

    ctx->pc = 0x1f3f40u;

    // 0x1f3f40: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1F3F40u;
    {
        const bool branch_taken_0x1f3f40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F3F44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F3F40u;
            // 0x1f3f44: 0x182d  daddu       $v1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f3f40) {
            ctx->pc = 0x1F3F68u;
            goto label_1f3f68;
        }
    }
    ctx->pc = 0x1F3F48u;
label_1f3f48:
    // 0x1f3f48: 0x80420e0d  lb          $v0, 0xE0D($v0)
    ctx->pc = 0x1f3f48u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 3597)));
    // 0x1f3f4c: 0x4400003  bltz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F3F4Cu;
    {
        const bool branch_taken_0x1f3f4c = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1F3F50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F3F4Cu;
            // 0x1f3f50: 0x28410003  slti        $at, $v0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f3f4c) {
            ctx->pc = 0x1F3F5Cu;
            goto label_1f3f5c;
        }
    }
    ctx->pc = 0x1F3F54u;
    // 0x1f3f54: 0x14200003  bnez        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1F3F54u;
    {
        const bool branch_taken_0x1f3f54 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1f3f54) {
            ctx->pc = 0x1F3F64u;
            goto label_1f3f64;
        }
    }
    ctx->pc = 0x1F3F5Cu;
label_1f3f5c:
    // 0x1f3f5c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1F3F5Cu;
    {
        const bool branch_taken_0x1f3f5c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1F3F60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F3F5Cu;
            // 0x1f3f60: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f3f5c) {
            ctx->pc = 0x1F3F78u;
            goto label_1f3f78;
        }
    }
    ctx->pc = 0x1F3F64u;
label_1f3f64:
    // 0x1f3f64: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1f3f64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
label_1f3f68:
    // 0x1f3f68: 0x28620010  slti        $v0, $v1, 0x10
    ctx->pc = 0x1f3f68u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x1f3f6c: 0x1440fff6  bnez        $v0, . + 4 + (-0xA << 2)
    ctx->pc = 0x1F3F6Cu;
    {
        const bool branch_taken_0x1f3f6c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1F3F70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F3F6Cu;
            // 0x1f3f70: 0x831021  addu        $v0, $a0, $v1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1f3f6c) {
            ctx->pc = 0x1F3F48u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1f3f48;
        }
    }
    ctx->pc = 0x1F3F74u;
    // 0x1f3f74: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1f3f74u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1f3f78:
    // 0x1f3f78: 0x3e00008  jr          $ra
    ctx->pc = 0x1F3F78u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F3F48u: goto label_1f3f48;
            case 0x1F3F5Cu: goto label_1f3f5c;
            case 0x1F3F64u: goto label_1f3f64;
            case 0x1F3F68u: goto label_1f3f68;
            case 0x1F3F78u: goto label_1f3f78;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F3F80u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
