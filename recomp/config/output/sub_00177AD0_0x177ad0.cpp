#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00177AD0
// Address: 0x177ad0 - 0x177b0c
void sub_00177AD0_0x177ad0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00177AD0_0x177ad0");
#endif

    ctx->pc = 0x177ad0u;

    // 0x177ad0: 0x710c0  sll         $v0, $a3, 3
    ctx->pc = 0x177ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x177ad4: 0x51900  sll         $v1, $a1, 4
    ctx->pc = 0x177ad4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 5), 4));
    // 0x177ad8: 0x471023  subu        $v0, $v0, $a3
    ctx->pc = 0x177ad8u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x177adc: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x177adcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x177ae0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x177ae0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x177ae4: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x177ae4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x177ae8: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x177ae8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x177aec: 0x831821  addu        $v1, $a0, $v1
    ctx->pc = 0x177aecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x177af0: 0x63080  sll         $a2, $a2, 2
    ctx->pc = 0x177af0u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x177af4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x177af4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x177af8: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x177af8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x177afc: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x177afcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x177b00: 0xacc71ab4  sw          $a3, 0x1AB4($a2)
    ctx->pc = 0x177b00u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 6836), GPR_U32(ctx, 7));
    // 0x177b04: 0x3e00008  jr          $ra
    ctx->pc = 0x177B04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177B08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x177B04u;
            // 0x177b08: 0xac85118c  sw          $a1, 0x118C($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4492), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x177B0Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
