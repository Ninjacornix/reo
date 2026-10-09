#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015D470
// Address: 0x15d470 - 0x15d4c0
void sub_0015D470_0x15d470(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015D470_0x15d470");
#endif

    ctx->pc = 0x15d470u;

    // 0x15d470: 0x8c820004  lw          $v0, 0x4($a0)
    ctx->pc = 0x15d470u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x15d474: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x15D474u;
    {
        const bool branch_taken_0x15d474 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15D478u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D474u;
            // 0x15d478: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d474) {
            ctx->pc = 0x15D4A0u;
            goto label_15d4a0;
        }
    }
    ctx->pc = 0x15D47Cu;
    // 0x15d47c: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x15d47cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x15d480: 0x1040000c  beqz        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x15D480u;
    {
        const bool branch_taken_0x15d480 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x15D484u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D480u;
            // 0x15d484: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d480) {
            ctx->pc = 0x15D4B4u;
            goto label_15d4b4;
        }
    }
    ctx->pc = 0x15D488u;
    // 0x15d488: 0x8c82000c  lw          $v0, 0xC($a0)
    ctx->pc = 0x15d488u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x15d48c: 0x50400008  beql        $v0, $zero, . + 4 + (0x8 << 2)
    ctx->pc = 0x15D48Cu;
    {
        const bool branch_taken_0x15d48c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x15d48c) {
            ctx->pc = 0x15D490u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x15D48Cu;
            // 0x15d490: 0x24050002  addiu       $a1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
            ctx->pc = 0x15D4B0u;
            goto label_15d4b0;
        }
    }
    ctx->pc = 0x15D494u;
    // 0x15d494: 0x3e00008  jr          $ra
    ctx->pc = 0x15D494u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15D498u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D494u;
            // 0x15d498: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D4A0u: goto label_15d4a0;
            case 0x15D4B0u: goto label_15d4b0;
            case 0x15D4B4u: goto label_15d4b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D49Cu;
    // 0x15d49c: 0x0  nop
    ctx->pc = 0x15d49cu;
    // NOP
label_15d4a0:
    // 0x15d4a0: 0x8c83000c  lw          $v1, 0xC($a0)
    ctx->pc = 0x15d4a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x15d4a4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x15d4a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x15d4a8: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x15d4a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x15d4ac: 0x43280b  movn        $a1, $v0, $v1
    ctx->pc = 0x15d4acu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 2));
label_15d4b0:
    // 0x15d4b0: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x15d4b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_15d4b4:
    // 0x15d4b4: 0x3e00008  jr          $ra
    ctx->pc = 0x15D4B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D4A0u: goto label_15d4a0;
            case 0x15D4B0u: goto label_15d4b0;
            case 0x15D4B4u: goto label_15d4b4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D4BCu;
    // 0x15d4bc: 0x0  nop
    ctx->pc = 0x15d4bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
