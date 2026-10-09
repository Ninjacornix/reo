#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140D80
// Address: 0x140d80 - 0x140dcc
void sub_00140D80_0x140d80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140D80_0x140d80");
#endif

    ctx->pc = 0x140d80u;

    // 0x140d80: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140d80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x140d84: 0xc0482d  daddu       $t1, $a2, $zero
    ctx->pc = 0x140d84u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140d88: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x140d88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x140d8c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x140d8cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x140d90: 0x24424600  addiu       $v0, $v0, 0x4600
    ctx->pc = 0x140d90u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17920));
    // 0x140d94: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x140d94u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x140d98: 0x8d230000  lw          $v1, 0x0($t1)
    ctx->pc = 0x140d98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x140d9c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x140d9cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140da0: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x140da0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x140da4: 0x24040028  addiu       $a0, $zero, 0x28
    ctx->pc = 0x140da4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 40));
    // 0x140da8: 0xac450004  sw          $a1, 0x4($v0)
    ctx->pc = 0x140da8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 5));
    // 0x140dac: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x140dacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140db0: 0xac430008  sw          $v1, 0x8($v0)
    ctx->pc = 0x140db0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 3));
    // 0x140db4: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x140db4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140db8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x140db8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140dbc: 0x8d230004  lw          $v1, 0x4($t1)
    ctx->pc = 0x140dbcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 4)));
    // 0x140dc0: 0xac43000c  sw          $v1, 0xC($v0)
    ctx->pc = 0x140dc0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 3));
    // 0x140dc4: 0x804e518  j           func_139460
    ctx->pc = 0x140DC4u;
    ctx->pc = 0x140DC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140DC4u;
            // 0x140dc8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00139460_0x139460(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x140DCCu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
