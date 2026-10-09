#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015E270
// Address: 0x15e270 - 0x15e2b0
void sub_0015E270_0x15e270(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015E270_0x15e270");
#endif

    ctx->pc = 0x15e270u;

    // 0x15e270: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x15e270u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x15e274: 0x2c850003  sltiu       $a1, $a0, 0x3
    ctx->pc = 0x15e274u;
    SET_GPR_U64(ctx, 5, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)(int64_t)(int32_t)3) ? 1 : 0);
    // 0x15e278: 0x1082000a  beq         $a0, $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x15E278u;
    {
        const bool branch_taken_0x15e278 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x15E27Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E278u;
            // 0x15e27c: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e278) {
            ctx->pc = 0x15E2A4u;
            goto label_15e2a4;
        }
    }
    ctx->pc = 0x15E280u;
    // 0x15e280: 0x50a00005  beql        $a1, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x15E280u;
    {
        const bool branch_taken_0x15e280 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x15e280) {
            ctx->pc = 0x15E284u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15E280u;
            // 0x15e284: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15E298u;
            goto label_15e298;
        }
    }
    ctx->pc = 0x15E288u;
    // 0x15e288: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15e288u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15e28c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x15E28Cu;
    {
        const bool branch_taken_0x15e28c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x15E290u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E28Cu;
            // 0x15e290: 0x24030001  addiu       $v1, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15e28c) {
            ctx->pc = 0x15E29Cu;
            goto label_15e29c;
        }
    }
    ctx->pc = 0x15E294u;
    // 0x15e294: 0x0  nop
    ctx->pc = 0x15e294u;
    // NOP
label_15e298:
    // 0x15e298: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x15e298u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_15e29c:
    // 0x15e29c: 0x54820001  bnel        $a0, $v0, . + 4 + (0x1 << 2)
    ctx->pc = 0x15E29Cu;
    {
        const bool branch_taken_0x15e29c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 2));
        if (branch_taken_0x15e29c) {
            ctx->pc = 0x15E2A0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15E29Cu;
            // 0x15e2a0: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15E2A4u;
            goto label_15e2a4;
        }
    }
    ctx->pc = 0x15E2A4u;
label_15e2a4:
    // 0x15e2a4: 0x3e00008  jr          $ra
    ctx->pc = 0x15E2A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15E2A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15E2A4u;
            // 0x15e2a8: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15E298u: goto label_15e298;
            case 0x15E29Cu: goto label_15e29c;
            case 0x15E2A4u: goto label_15e2a4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15E2ACu;
    // 0x15e2ac: 0x0  nop
    ctx->pc = 0x15e2acu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
