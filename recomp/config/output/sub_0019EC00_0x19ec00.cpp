#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0019EC00
// Address: 0x19ec00 - 0x19ec50
void sub_0019EC00_0x19ec00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0019EC00_0x19ec00");
#endif

    ctx->pc = 0x19ec00u;

    // 0x19ec00: 0x10800004  beqz        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x19EC00u;
    {
        const bool branch_taken_0x19ec00 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x19EC04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EC00u;
            // 0x19ec04: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19ec00) {
            ctx->pc = 0x19EC14u;
            goto label_19ec14;
        }
    }
    ctx->pc = 0x19EC08u;
    // 0x19ec08: 0x8c860004  lw          $a2, 0x4($a0)
    ctx->pc = 0x19ec08u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x19ec0c: 0x1000000a  b           . + 4 + (0xA << 2)
    ctx->pc = 0x19EC0Cu;
    {
        const bool branch_taken_0x19ec0c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19EC10u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EC0Cu;
            // 0x19ec10: 0xac850004  sw          $a1, 0x4($a0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19ec0c) {
            ctx->pc = 0x19EC38u;
            goto label_19ec38;
        }
    }
    ctx->pc = 0x19EC14u;
label_19ec14:
    // 0x19ec14: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19ec14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19ec18: 0x8c23bed0  lw          $v1, -0x4130($at)
    ctx->pc = 0x19ec18u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294950608)));
    // 0x19ec1c: 0x14600004  bnez        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x19EC1Cu;
    {
        const bool branch_taken_0x19ec1c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x19EC20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EC1Cu;
            // 0x19ec20: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19ec1c) {
            ctx->pc = 0x19EC30u;
            goto label_19ec30;
        }
    }
    ctx->pc = 0x19EC24u;
    // 0x19ec24: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x19ec24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x19ec28: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x19EC28u;
    {
        const bool branch_taken_0x19ec28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19EC2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EC28u;
            // 0x19ec2c: 0xac25bed0  sw          $a1, -0x4130($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294950608), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19ec28) {
            ctx->pc = 0x19EC38u;
            goto label_19ec38;
        }
    }
    ctx->pc = 0x19EC30u;
label_19ec30:
    // 0x19ec30: 0x60302d  daddu       $a2, $v1, $zero
    ctx->pc = 0x19ec30u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ec34: 0xac25bed0  sw          $a1, -0x4130($at)
    ctx->pc = 0x19ec34u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294950608), GPR_U32(ctx, 5));
label_19ec38:
    // 0x19ec38: 0xaca40000  sw          $a0, 0x0($a1)
    ctx->pc = 0x19ec38u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 4));
    // 0x19ec3c: 0x10c00002  beqz        $a2, . + 4 + (0x2 << 2)
    ctx->pc = 0x19EC3Cu;
    {
        const bool branch_taken_0x19ec3c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x19EC40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x19EC3Cu;
            // 0x19ec40: 0xaca60004  sw          $a2, 0x4($a1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x19ec3c) {
            ctx->pc = 0x19EC48u;
            goto label_19ec48;
        }
    }
    ctx->pc = 0x19EC44u;
    // 0x19ec44: 0xacc50000  sw          $a1, 0x0($a2)
    ctx->pc = 0x19ec44u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 5));
label_19ec48:
    // 0x19ec48: 0x3e00008  jr          $ra
    ctx->pc = 0x19EC48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19EC14u: goto label_19ec14;
            case 0x19EC30u: goto label_19ec30;
            case 0x19EC38u: goto label_19ec38;
            case 0x19EC48u: goto label_19ec48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19EC50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
