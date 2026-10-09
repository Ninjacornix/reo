#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BBAD0
// Address: 0x1bbad0 - 0x1bbb08
void sub_001BBAD0_0x1bbad0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BBAD0_0x1bbad0");
#endif

    ctx->pc = 0x1bbad0u;

    // 0x1bbad0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbad0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbad4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1bbad4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1bbad8: 0xac246624  sw          $a0, 0x6624($at)
    ctx->pc = 0x1bbad8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26148), GPR_U32(ctx, 4));
    // 0x1bbadc: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbadcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbae0: 0xac246628  sw          $a0, 0x6628($at)
    ctx->pc = 0x1bbae0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26152), GPR_U32(ctx, 4));
    // 0x1bbae4: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbae4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbae8: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1bbae8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1bbaec: 0xac206634  sw          $zero, 0x6634($at)
    ctx->pc = 0x1bbaecu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26164), GPR_U32(ctx, 0));
    // 0x1bbaf0: 0x65200b  movn        $a0, $v1, $a1
    ctx->pc = 0x1bbaf0u;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
    // 0x1bbaf4: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbaf4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbaf8: 0xac206640  sw          $zero, 0x6640($at)
    ctx->pc = 0x1bbaf8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 26176), GPR_U32(ctx, 0));
    // 0x1bbafc: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1bbafcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1bbb00: 0x3e00008  jr          $ra
    ctx->pc = 0x1BBB00u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BBB04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BBB00u;
            // 0x1bbb04: 0xa0246620  sb          $a0, 0x6620($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 26144), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1BBB08u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
