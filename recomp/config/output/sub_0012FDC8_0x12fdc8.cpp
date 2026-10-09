#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012FDC8
// Address: 0x12fdc8 - 0x12fde4
void sub_0012FDC8_0x12fdc8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012FDC8_0x12fdc8");
#endif

    ctx->pc = 0x12fdc8u;

    // 0x12fdc8: 0x51080  sll         $v0, $a1, 2
    ctx->pc = 0x12fdc8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x12fdcc: 0x2ca50002  sltiu       $a1, $a1, 0x2
    ctx->pc = 0x12fdccu;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 5) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x12fdd0: 0x10a00002  beqz        $a1, . + 4 + (0x2 << 2)
    ctx->pc = 0x12FDD0u;
    {
        const bool branch_taken_0x12fdd0 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        ctx->pc = 0x12FDD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FDD0u;
            // 0x12fdd4: 0x822021  addu        $a0, $a0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fdd0) {
            ctx->pc = 0x12FDDCu;
            goto label_12fddc;
        }
    }
    ctx->pc = 0x12FDD8u;
    // 0x12fdd8: 0xac860004  sw          $a2, 0x4($a0)
    ctx->pc = 0x12fdd8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 6));
label_12fddc:
    // 0x12fddc: 0x3e00008  jr          $ra
    ctx->pc = 0x12FDDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12FDDCu: goto label_12fddc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12FDE4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
