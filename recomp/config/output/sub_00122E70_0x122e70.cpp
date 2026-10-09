#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00122E70
// Address: 0x122e70 - 0x122e90
void sub_00122E70_0x122e70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00122E70_0x122e70");
#endif

    ctx->pc = 0x122e70u;

    // 0x122e70: 0x24020600  addiu       $v0, $zero, 0x600
    ctx->pc = 0x122e70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1536));
    // 0x122e74: 0xac8500c0  sw          $a1, 0xC0($a0)
    ctx->pc = 0x122e74u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 192), GPR_U32(ctx, 5));
    // 0x122e78: 0xa2001a  div         $zero, $a1, $v0
    ctx->pc = 0x122e78u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 5);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x122e7c: 0x50400001  beql        $v0, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x122E7Cu;
    {
        const bool branch_taken_0x122e7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x122e7c) {
            ctx->pc = 0x122E80u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x122E7Cu;
            // 0x122e80: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x122E84u;
            goto label_122e84;
        }
    }
    ctx->pc = 0x122E84u;
label_122e84:
    // 0x122e84: 0x1812  mflo        $v1
    ctx->pc = 0x122e84u;
    SET_GPR_U64(ctx, 3, ctx->lo);
    // 0x122e88: 0x3e00008  jr          $ra
    ctx->pc = 0x122E88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x122E8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x122E88u;
            // 0x122e8c: 0xac8300c4  sw          $v1, 0xC4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 196), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x122E84u: goto label_122e84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x122E90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
