#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013F058
// Address: 0x13f058 - 0x13f080
void sub_0013F058_0x13f058(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013F058_0x13f058");
#endif

    ctx->pc = 0x13f058u;

    // 0x13f058: 0x28c3fff1  slti        $v1, $a2, -0xF
    ctx->pc = 0x13f058u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)4294967281) ? 1 : 0);
    // 0x13f05c: 0x2402fff1  addiu       $v0, $zero, -0xF
    ctx->pc = 0x13f05cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967281));
    // 0x13f060: 0xc3100a  movz        $v0, $a2, $v1
    ctx->pc = 0x13f060u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 6));
    // 0x13f064: 0x2406000f  addiu       $a2, $zero, 0xF
    ctx->pc = 0x13f064u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x13f068: 0x52880  sll         $a1, $a1, 2
    ctx->pc = 0x13f068u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x13f06c: 0x28430010  slti        $v1, $v0, 0x10
    ctx->pc = 0x13f06cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)16) ? 1 : 0);
    // 0x13f070: 0xa42821  addu        $a1, $a1, $a0
    ctx->pc = 0x13f070u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x13f074: 0xc3100a  movz        $v0, $a2, $v1
    ctx->pc = 0x13f074u;
    if (GPR_U64(ctx, 3) == 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 6));
    // 0x13f078: 0x3e00008  jr          $ra
    ctx->pc = 0x13F078u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13F07Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13F078u;
            // 0x13f07c: 0xaca20038  sw          $v0, 0x38($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 56), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x13F080u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
