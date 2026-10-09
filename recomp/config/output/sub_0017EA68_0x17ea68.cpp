#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017EA68
// Address: 0x17ea68 - 0x17eaa4
void sub_0017EA68_0x17ea68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017EA68_0x17ea68");
#endif

    ctx->pc = 0x17ea68u;

    // 0x17ea68: 0xdc870008  ld          $a3, 0x8($a0)
    ctx->pc = 0x17ea68u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x17ea6c: 0xdc880010  ld          $t0, 0x10($a0)
    ctx->pc = 0x17ea6cu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x17ea70: 0xdc860000  ld          $a2, 0x0($a0)
    ctx->pc = 0x17ea70u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17ea74: 0xa7482a  slt         $t1, $a1, $a3
    ctx->pc = 0x17ea74u;
    SET_GPR_U64(ctx, 9, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x17ea78: 0x8c830018  lw          $v1, 0x18($a0)
    ctx->pc = 0x17ea78u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x17ea7c: 0x105102a  slt         $v0, $t0, $a1
    ctx->pc = 0x17ea7cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x17ea80: 0xa2400b  movn        $t0, $a1, $v0
    ctx->pc = 0x17ea80u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 8, GPR_VEC(ctx, 5));
    // 0x17ea84: 0xc5302d  daddu       $a2, $a2, $a1
    ctx->pc = 0x17ea84u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 5));
    // 0x17ea88: 0xa9380b  movn        $a3, $a1, $t1
    ctx->pc = 0x17ea88u;
    if (GPR_U64(ctx, 9) != 0) SET_GPR_VEC(ctx, 7, GPR_VEC(ctx, 5));
    // 0x17ea8c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x17ea8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x17ea90: 0xac830018  sw          $v1, 0x18($a0)
    ctx->pc = 0x17ea90u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 3));
    // 0x17ea94: 0xfc860000  sd          $a2, 0x0($a0)
    ctx->pc = 0x17ea94u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 6));
    // 0x17ea98: 0xfc870008  sd          $a3, 0x8($a0)
    ctx->pc = 0x17ea98u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 8), GPR_U64(ctx, 7));
    // 0x17ea9c: 0x3e00008  jr          $ra
    ctx->pc = 0x17EA9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17EAA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17EA9Cu;
            // 0x17eaa0: 0xfc880010  sd          $t0, 0x10($a0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 4), 16), GPR_U64(ctx, 8));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x17EAA4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
