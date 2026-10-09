#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CC240
// Address: 0x1cc240 - 0x1cc25c
void sub_001CC240_0x1cc240(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CC240_0x1cc240");
#endif

    ctx->pc = 0x1cc240u;

    // 0x1cc240: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc240u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc244: 0x8c220ac4  lw          $v0, 0xAC4($at)
    ctx->pc = 0x1cc244u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2756)));
    // 0x1cc248: 0xa4820002  sh          $v0, 0x2($a0)
    ctx->pc = 0x1cc248u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x1cc24c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cc24cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cc250: 0x8c250ac4  lw          $a1, 0xAC4($at)
    ctx->pc = 0x1cc250u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2756)));
    // 0x1cc254: 0x806bde0  j           func_1AF780
    ctx->pc = 0x1CC254u;
    ctx->pc = 0x1CC258u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CC254u;
            // 0x1cc258: 0x24040004  addiu       $a0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1AF780u;
    if (runtime->hasFunction(0x1AF780u)) {
        auto targetFn = runtime->lookupFunction(0x1AF780u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_001AF780_0x1af780(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1CC25Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
