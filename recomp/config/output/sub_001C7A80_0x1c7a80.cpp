#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C7A80
// Address: 0x1c7a80 - 0x1c7ac0
void sub_001C7A80_0x1c7a80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C7A80_0x1c7a80");
#endif

    ctx->pc = 0x1c7a80u;

    // 0x1c7a80: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7a80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7a84: 0xa0245056  sb          $a0, 0x5056($at)
    ctx->pc = 0x1c7a84u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 20566), (uint8_t)GPR_U32(ctx, 4));
    // 0x1c7a88: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7a88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7a8c: 0xa0205059  sb          $zero, 0x5059($at)
    ctx->pc = 0x1c7a8cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 20569), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c7a90: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7a90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7a94: 0xa0205058  sb          $zero, 0x5058($at)
    ctx->pc = 0x1c7a94u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 20568), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c7a98: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7a98u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7a9c: 0xa0205057  sb          $zero, 0x5057($at)
    ctx->pc = 0x1c7a9cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 20567), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c7aa0: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7aa0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7aa4: 0xa420505c  sh          $zero, 0x505C($at)
    ctx->pc = 0x1c7aa4u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 20572), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c7aa8: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7aa8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7aac: 0xa420505a  sh          $zero, 0x505A($at)
    ctx->pc = 0x1c7aacu;
    WRITE16(ADD32(GPR_U32(ctx, 1), 20570), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c7ab0: 0x3c010033  lui         $at, 0x33
    ctx->pc = 0x1c7ab0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)51 << 16));
    // 0x1c7ab4: 0x3e00008  jr          $ra
    ctx->pc = 0x1C7AB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C7AB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C7AB4u;
            // 0x1c7ab8: 0xac205074  sw          $zero, 0x5074($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 20596), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1C7ABCu;
    // 0x1c7abc: 0x0  nop
    ctx->pc = 0x1c7abcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
