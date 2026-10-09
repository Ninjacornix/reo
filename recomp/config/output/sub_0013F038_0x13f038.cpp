#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F038
// Address: 0x13f038 - 0x13f054
void sub_0013F038_0x13f038(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F038_0x13f038");
#endif

    ctx->pc = 0x13f038u;

    // 0x13f038: 0x5102a  slt         $v0, $zero, $a1
    ctx->pc = 0x13f038u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x13f03c: 0x2406fc19  addiu       $a2, $zero, -0x3E7
    ctx->pc = 0x13f03cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294966297));
    // 0x13f040: 0x2280b  movn        $a1, $zero, $v0
    ctx->pc = 0x13f040u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 0));
    // 0x13f044: 0x28a3fc19  slti        $v1, $a1, -0x3E7
    ctx->pc = 0x13f044u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)4294966297) ? 1 : 0);
    // 0x13f048: 0xc3280b  movn        $a1, $a2, $v1
    ctx->pc = 0x13f048u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 6));
    // 0x13f04c: 0x3e00008  jr          $ra
    ctx->pc = 0x13F04Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F04Cu;
            // 0x13f050: 0xac850030  sw          $a1, 0x30($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 48), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13F054u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
