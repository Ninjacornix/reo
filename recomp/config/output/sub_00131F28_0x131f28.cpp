#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00131F28
// Address: 0x131f28 - 0x131f60
void sub_00131F28_0x131f28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00131F28_0x131f28");
#endif

    ctx->pc = 0x131f28u;

    // 0x131f28: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x131f28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x131f2c: 0x54820004  bnel        $a0, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x131F2Cu;
    {
        const bool branch_taken_0x131f2c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x131f2c) {
            ctx->pc = 0x131F30u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131F2Cu;
            // 0x131f30: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x131F40u;
            goto label_131f40;
        }
    }
    ctx->pc = 0x131F34u;
    // 0x131f34: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x131f34u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x131f38: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x131F38u;
    {
        const bool branch_taken_0x131f38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x131F3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131F38u;
            // 0x131f3c: 0x2402176a  addiu       $v0, $zero, 0x176A (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5994));
        ctx->in_delay_slot = false;
        if (branch_taken_0x131f38) {
            ctx->pc = 0x131F50u;
            goto label_131f50;
        }
    }
    ctx->pc = 0x131F40u;
label_131f40:
    // 0x131f40: 0x54820005  bnel        $a0, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x131F40u;
    {
        const bool branch_taken_0x131f40 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x131f40) {
            ctx->pc = 0x131F44u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x131F40u;
            // 0x131f44: 0x3c020022  lui         $v0, 0x22 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
        ctx->in_delay_slot = false;
            ctx->pc = 0x131F58u;
            goto label_131f58;
        }
    }
    ctx->pc = 0x131F48u;
    // 0x131f48: 0x3c030022  lui         $v1, 0x22
    ctx->pc = 0x131f48u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)34 << 16));
    // 0x131f4c: 0x24021388  addiu       $v0, $zero, 0x1388
    ctx->pc = 0x131f4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5000));
label_131f50:
    // 0x131f50: 0xac62b788  sw          $v0, -0x4878($v1)
    ctx->pc = 0x131f50u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294948744), GPR_U32(ctx, 2));
    // 0x131f54: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x131f54u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
label_131f58:
    // 0x131f58: 0x3e00008  jr          $ra
    ctx->pc = 0x131F58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x131F5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x131F58u;
            // 0x131f5c: 0xac44b750  sw          $a0, -0x48B0($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294948688), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x131F40u: goto label_131f40;
            case 0x131F50u: goto label_131f50;
            case 0x131F58u: goto label_131f58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x131F60u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
