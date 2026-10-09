#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00117310
// Address: 0x117310 - 0x117340
void sub_00117310_0x117310(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00117310_0x117310");
#endif

    ctx->pc = 0x117310u;

    // 0x117310: 0x8c850024  lw          $a1, 0x24($a0)
    ctx->pc = 0x117310u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 36)));
    // 0x117314: 0x8c830018  lw          $v1, 0x18($a0)
    ctx->pc = 0x117314u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x117318: 0xa3001a  div         $zero, $a1, $v1
    ctx->pc = 0x117318u;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 5);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x11731c: 0x50600001  beql        $v1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x11731Cu;
    {
        const bool branch_taken_0x11731c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x11731c) {
            ctx->pc = 0x117320u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11731Cu;
            // 0x117320: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x117324u;
            goto label_117324;
        }
    }
    ctx->pc = 0x117324u;
label_117324:
    // 0x117324: 0x8c850014  lw          $a1, 0x14($a0)
    ctx->pc = 0x117324u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x117328: 0x1010  mfhi        $v0
    ctx->pc = 0x117328u;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x11732c: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x11732cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x117330: 0x21180  sll         $v0, $v0, 6
    ctx->pc = 0x117330u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 6));
    // 0x117334: 0xac830024  sw          $v1, 0x24($a0)
    ctx->pc = 0x117334u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 3));
    // 0x117338: 0x3e00008  jr          $ra
    ctx->pc = 0x117338u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11733Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x117338u;
            // 0x11733c: 0xa21021  addu        $v0, $a1, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x117324u: goto label_117324;
            default: break;
        }
        return;
    }
    ctx->pc = 0x117340u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
