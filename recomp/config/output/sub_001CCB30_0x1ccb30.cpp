#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001CCB30
// Address: 0x1ccb30 - 0x1ccb90
void sub_001CCB30_0x1ccb30(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001CCB30_0x1ccb30");
#endif

    switch (ctx->pc) {
        case 0x1ccb40u: goto label_1ccb40;
        default: break;
    }

    ctx->pc = 0x1ccb30u;

    // 0x1ccb30: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1ccb30u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1ccb34: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1ccb34u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ccb38: 0x1000000d  b           . + 4 + (0xD << 2)
    ctx->pc = 0x1CCB38u;
    {
        const bool branch_taken_0x1ccb38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CCB3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CCB38u;
            // 0x1ccb3c: 0x24421640  addiu       $v0, $v0, 0x1640 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 5696));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ccb38) {
            ctx->pc = 0x1CCB70u;
            goto label_1ccb70;
        }
    }
    ctx->pc = 0x1CCB40u;
label_1ccb40:
    // 0x1ccb40: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1ccb40u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ccb44: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1CCB44u;
    {
        const bool branch_taken_0x1ccb44 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ccb44) {
            ctx->pc = 0x1CCB68u;
            goto label_1ccb68;
        }
    }
    ctx->pc = 0x1CCB4Cu;
    // 0x1ccb4c: 0x8c430004  lw          $v1, 0x4($v0)
    ctx->pc = 0x1ccb4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1ccb50: 0x14640005  bne         $v1, $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1CCB50u;
    {
        const bool branch_taken_0x1ccb50 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        if (branch_taken_0x1ccb50) {
            ctx->pc = 0x1CCB68u;
            goto label_1ccb68;
        }
    }
    ctx->pc = 0x1CCB58u;
    // 0x1ccb58: 0x8443000e  lh          $v1, 0xE($v0)
    ctx->pc = 0x1ccb58u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 14)));
    // 0x1ccb5c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1ccb5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ccb60: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1CCB60u;
    {
        const bool branch_taken_0x1ccb60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CCB64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CCB60u;
            // 0x1ccb64: 0xa443000e  sh          $v1, 0xE($v0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 2), 14), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ccb60) {
            ctx->pc = 0x1CCB80u;
            goto label_1ccb80;
        }
    }
    ctx->pc = 0x1CCB68u;
label_1ccb68:
    // 0x1ccb68: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1ccb68u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x1ccb6c: 0x24420010  addiu       $v0, $v0, 0x10
    ctx->pc = 0x1ccb6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 16));
label_1ccb70:
    // 0x1ccb70: 0x28a30100  slti        $v1, $a1, 0x100
    ctx->pc = 0x1ccb70u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)256) ? 1 : 0);
    // 0x1ccb74: 0x1460fff2  bnez        $v1, . + 4 + (-0xE << 2)
    ctx->pc = 0x1CCB74u;
    {
        const bool branch_taken_0x1ccb74 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ccb74) {
            ctx->pc = 0x1CCB40u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1ccb40;
        }
    }
    ctx->pc = 0x1CCB7Cu;
    // 0x1ccb7c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ccb7cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ccb80:
    // 0x1ccb80: 0x3e00008  jr          $ra
    ctx->pc = 0x1CCB80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1CCB40u: goto label_1ccb40;
            case 0x1CCB68u: goto label_1ccb68;
            case 0x1CCB70u: goto label_1ccb70;
            case 0x1CCB80u: goto label_1ccb80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CCB88u;
    // 0x1ccb88: 0x0  nop
    ctx->pc = 0x1ccb88u;
    // NOP
    // 0x1ccb8c: 0x0  nop
    ctx->pc = 0x1ccb8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
