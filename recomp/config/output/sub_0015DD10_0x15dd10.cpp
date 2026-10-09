#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015DD10
// Address: 0x15dd10 - 0x15dd50
void sub_0015DD10_0x15dd10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015DD10_0x15dd10");
#endif

    ctx->pc = 0x15dd10u;

    // 0x15dd10: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x15dd10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x15dd14: 0x2c850003  sltiu       $a1, $a0, 0x3
    ctx->pc = 0x15dd14u;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x15dd18: 0x1082000a  beq         $a0, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x15DD18u;
    {
        const bool branch_taken_0x15dd18 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x15DD1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DD18u;
            // 0x15dd1c: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15dd18) {
            ctx->pc = 0x15DD44u;
            goto label_15dd44;
        }
    }
    ctx->pc = 0x15DD20u;
    // 0x15dd20: 0x50a00005  beql        $a1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x15DD20u;
    {
        const bool branch_taken_0x15dd20 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x15dd20) {
            ctx->pc = 0x15DD24u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15DD20u;
            // 0x15dd24: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15DD38u;
            goto label_15dd38;
        }
    }
    ctx->pc = 0x15DD28u;
    // 0x15dd28: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15dd28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15dd2c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x15DD2Cu;
    {
        const bool branch_taken_0x15dd2c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15DD30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DD2Cu;
            // 0x15dd30: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15dd2c) {
            ctx->pc = 0x15DD3Cu;
            goto label_15dd3c;
        }
    }
    ctx->pc = 0x15DD34u;
    // 0x15dd34: 0x0  nop
    ctx->pc = 0x15dd34u;
    // NOP
label_15dd38:
    // 0x15dd38: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x15dd38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_15dd3c:
    // 0x15dd3c: 0x54820001  bnel        $a0, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x15DD3Cu;
    {
        const bool branch_taken_0x15dd3c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x15dd3c) {
            ctx->pc = 0x15DD40u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15DD3Cu;
            // 0x15dd40: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15DD44u;
            goto label_15dd44;
        }
    }
    ctx->pc = 0x15DD44u;
label_15dd44:
    // 0x15dd44: 0x3e00008  jr          $ra
    ctx->pc = 0x15DD44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15DD48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15DD44u;
            // 0x15dd48: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15DD38u: goto label_15dd38;
            case 0x15DD3Cu: goto label_15dd3c;
            case 0x15DD44u: goto label_15dd44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15DD4Cu;
    // 0x15dd4c: 0x0  nop
    ctx->pc = 0x15dd4cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
