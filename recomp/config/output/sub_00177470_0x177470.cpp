#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177470
// Address: 0x177470 - 0x1774b0
void sub_00177470_0x177470(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177470_0x177470");
#endif

    ctx->pc = 0x177470u;

    // 0x177470: 0xdc870008  ld          $a3, 0x8($a0)
    ctx->pc = 0x177470u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x177474: 0xdc880010  ld          $t0, 0x10($a0)
    ctx->pc = 0x177474u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x177478: 0xdc860000  ld          $a2, 0x0($a0)
    ctx->pc = 0x177478u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x17747c: 0xa7482a  slt         $t1, $a1, $a3
    ctx->pc = 0x17747cu;
    SET_GPR_U64(ctx, 9, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 7)) ? 1 : 0);
    // 0x177480: 0x8c830018  lw          $v1, 0x18($a0)
    ctx->pc = 0x177480u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x177484: 0x105102a  slt         $v0, $t0, $a1
    ctx->pc = 0x177484u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x177488: 0xa2400b  movn        $t0, $a1, $v0
    ctx->pc = 0x177488u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 8, GPR_VEC(ctx, 5));
    // 0x17748c: 0xc5302d  daddu       $a2, $a2, $a1
    ctx->pc = 0x17748cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 5));
    // 0x177490: 0xa9380b  movn        $a3, $a1, $t1
    ctx->pc = 0x177490u;
    if (GPR_U64(ctx, 9) != 0) SET_GPR_VEC(ctx, 7, GPR_VEC(ctx, 5));
    // 0x177494: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x177494u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x177498: 0xac830018  sw          $v1, 0x18($a0)
    ctx->pc = 0x177498u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 3));
    // 0x17749c: 0xfc860000  sd          $a2, 0x0($a0)
    ctx->pc = 0x17749cu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 6));
    // 0x1774a0: 0xfc870008  sd          $a3, 0x8($a0)
    ctx->pc = 0x1774a0u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 8), GPR_U64(ctx, 7));
    // 0x1774a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1774A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1774A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1774A4u;
            // 0x1774a8: 0xfc880010  sd          $t0, 0x10($a0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 4), 16), GPR_U64(ctx, 8));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1774ACu;
    // 0x1774ac: 0x0  nop
    ctx->pc = 0x1774acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
