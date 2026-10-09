#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00198A30
// Address: 0x198a30 - 0x198a70
void sub_00198A30_0x198a30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00198A30_0x198a30");
#endif

    ctx->pc = 0x198a30u;

    // 0x198a30: 0x8487001a  lh          $a3, 0x1A($a0)
    ctx->pc = 0x198a30u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 26)));
    // 0x198a34: 0x94a30000  lhu         $v1, 0x0($a1)
    ctx->pc = 0x198a34u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x198a38: 0xe3082a  slt         $at, $a3, $v1
    ctx->pc = 0x198a38u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x198a3c: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x198A3Cu;
    {
        const bool branch_taken_0x198a3c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x198a3c) {
            ctx->pc = 0x198A48u;
            goto label_198a48;
        }
    }
    ctx->pc = 0x198A44u;
    // 0x198a44: 0xa4a70000  sh          $a3, 0x0($a1)
    ctx->pc = 0x198a44u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 7));
label_198a48:
    // 0x198a48: 0x8484001c  lh          $a0, 0x1C($a0)
    ctx->pc = 0x198a48u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x198a4c: 0x94c30000  lhu         $v1, 0x0($a2)
    ctx->pc = 0x198a4cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x198a50: 0x83082a  slt         $at, $a0, $v1
    ctx->pc = 0x198a50u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 4) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x198a54: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x198A54u;
    {
        const bool branch_taken_0x198a54 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x198a54) {
            ctx->pc = 0x198A60u;
            goto label_198a60;
        }
    }
    ctx->pc = 0x198A5Cu;
    // 0x198a5c: 0xa4c40000  sh          $a0, 0x0($a2)
    ctx->pc = 0x198a5cu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 4));
label_198a60:
    // 0x198a60: 0x3e00008  jr          $ra
    ctx->pc = 0x198A60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x198A48u: goto label_198a48;
            case 0x198A60u: goto label_198a60;
            default: break;
        }
        return;
    }
    ctx->pc = 0x198A68u;
    // 0x198a68: 0x0  nop
    ctx->pc = 0x198a68u;
    // NOP
    // 0x198a6c: 0x0  nop
    ctx->pc = 0x198a6cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
