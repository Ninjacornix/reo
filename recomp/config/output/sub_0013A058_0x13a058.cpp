#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013A058
// Address: 0x13a058 - 0x13a078
void sub_0013A058_0x13a058(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013A058_0x13a058");
#endif

    ctx->pc = 0x13a058u;

    // 0x13a058: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13a058u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x13a05c: 0x2c830002  sltiu       $v1, $a0, 0x2
    ctx->pc = 0x13a05cu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)2) ? 1 : 0);
    // 0x13a060: 0x2442cbec  addiu       $v0, $v0, -0x3414
    ctx->pc = 0x13a060u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294953964));
    // 0x13a064: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x13A064u;
    {
        const bool branch_taken_0x13a064 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x13A068u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13A064u;
            // 0x13a068: 0xac440000  sw          $a0, 0x0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13a064) {
            ctx->pc = 0x13A070u;
            goto label_13a070;
        }
    }
    ctx->pc = 0x13A06Cu;
    // 0x13a06c: 0xac400000  sw          $zero, 0x0($v0)
    ctx->pc = 0x13a06cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
label_13a070:
    // 0x13a070: 0x3e00008  jr          $ra
    ctx->pc = 0x13A070u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13A070u: goto label_13a070;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13A078u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
