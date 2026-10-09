#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AFA00
// Address: 0x1afa00 - 0x1afa70
void sub_001AFA00_0x1afa00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AFA00_0x1afa00");
#endif

    switch (ctx->pc) {
        case 0x1afa18u: goto label_1afa18;
        default: break;
    }

    ctx->pc = 0x1afa00u;

    // 0x1afa00: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1afa00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1afa04: 0x3c05002c  lui         $a1, 0x2C
    ctx->pc = 0x1afa04u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)44 << 16));
    // 0x1afa08: 0x8c268e10  lw          $a2, -0x71F0($at)
    ctx->pc = 0x1afa08u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294938128)));
    // 0x1afa0c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1afa0cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1afa10: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1AFA10u;
    {
        const bool branch_taken_0x1afa10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1AFA14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFA10u;
            // 0x1afa14: 0x24a58e20  addiu       $a1, $a1, -0x71E0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294938144));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afa10) {
            ctx->pc = 0x1AFA2Cu;
            goto label_1afa2c;
        }
    }
    ctx->pc = 0x1AFA18u;
label_1afa18:
    // 0x1afa18: 0xa31821  addu        $v1, $a1, $v1
    ctx->pc = 0x1afa18u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1afa1c: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1afa1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1afa20: 0x10640011  beq         $v1, $a0, . + 4 + (0x11 << 2)
    ctx->pc = 0x1AFA20u;
    {
        const bool branch_taken_0x1afa20 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1afa20) {
            ctx->pc = 0x1AFA68u;
            goto label_1afa68;
        }
    }
    ctx->pc = 0x1AFA28u;
    // 0x1afa28: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x1afa28u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
label_1afa2c:
    // 0x1afa2c: 0xe6182a  slt         $v1, $a3, $a2
    ctx->pc = 0x1afa2cu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x1afa30: 0x1460fff9  bnez        $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x1AFA30u;
    {
        const bool branch_taken_0x1afa30 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AFA34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFA30u;
            // 0x1afa34: 0x71880  sll         $v1, $a3, 2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afa30) {
            ctx->pc = 0x1AFA18u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1afa18;
        }
    }
    ctx->pc = 0x1AFA38u;
    // 0x1afa38: 0x24030008  addiu       $v1, $zero, 0x8
    ctx->pc = 0x1afa38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1afa3c: 0x10c3000a  beq         $a2, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x1AFA3Cu;
    {
        const bool branch_taken_0x1afa3c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 3));
        ctx->pc = 0x1AFA40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AFA3Cu;
            // 0x1afa40: 0x3c03002c  lui         $v1, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1afa3c) {
            ctx->pc = 0x1AFA68u;
            goto label_1afa68;
        }
    }
    ctx->pc = 0x1AFA44u;
    // 0x1afa44: 0x62880  sll         $a1, $a2, 2
    ctx->pc = 0x1afa44u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 6), 2));
    // 0x1afa48: 0x24638e20  addiu       $v1, $v1, -0x71E0
    ctx->pc = 0x1afa48u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294938144));
    // 0x1afa4c: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1afa4cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1afa50: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x1afa50u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1afa54: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x1afa54u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
    // 0x1afa58: 0x8c238e10  lw          $v1, -0x71F0($at)
    ctx->pc = 0x1afa58u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294938128)));
    // 0x1afa5c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1afa5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1afa60: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1afa60u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1afa64: 0xac238e10  sw          $v1, -0x71F0($at)
    ctx->pc = 0x1afa64u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294938128), GPR_U32(ctx, 3));
label_1afa68:
    // 0x1afa68: 0x3e00008  jr          $ra
    ctx->pc = 0x1AFA68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AFA18u: goto label_1afa18;
            case 0x1AFA2Cu: goto label_1afa2c;
            case 0x1AFA68u: goto label_1afa68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AFA70u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
