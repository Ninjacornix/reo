#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017BE88
// Address: 0x17be88 - 0x17bed8
void sub_0017BE88_0x17be88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017BE88_0x17be88");
#endif

    ctx->pc = 0x17be88u;

    // 0x17be88: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17be88u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17be8c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x17be8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x17be90: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x17be90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x17be94: 0xc0202d  daddu       $a0, $a2, $zero
    ctx->pc = 0x17be94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17be98: 0x100302d  daddu       $a2, $t0, $zero
    ctx->pc = 0x17be98u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17be9c: 0x8ca30074  lw          $v1, 0x74($a1)
    ctx->pc = 0x17be9cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 116)));
    // 0x17bea0: 0x14620007  bne         $v1, $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x17BEA0u;
    {
        const bool branch_taken_0x17bea0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x17BEA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17BEA0u;
            // 0x17bea4: 0xe0282d  daddu       $a1, $a3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17bea0) {
            ctx->pc = 0x17BEC0u;
            goto label_17bec0;
        }
    }
    ctx->pc = 0x17BEA8u;
    // 0x17bea8: 0x10c00003  beqz        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x17BEA8u;
    {
        const bool branch_taken_0x17bea8 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x17BEACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17BEA8u;
            // 0x17beac: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17bea8) {
            ctx->pc = 0x17BEB8u;
            goto label_17beb8;
        }
    }
    ctx->pc = 0x17BEB0u;
    // 0x17beb0: 0x8053fd2  j           func_14FF48
    ctx->pc = 0x17BEB0u;
    ctx->pc = 0x17BEB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17BEB0u;
            // 0x17beb4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x14FF48u;
    {
        auto targetFn = runtime->lookupFunction(0x14FF48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x17BEB8u;
label_17beb8:
    // 0x17beb8: 0x80524a0  j           func_149280
    ctx->pc = 0x17BEB8u;
    ctx->pc = 0x17BEBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17BEB8u;
            // 0x17bebc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x149280u;
    {
        auto targetFn = runtime->lookupFunction(0x149280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x17BEC0u;
label_17bec0:
    // 0x17bec0: 0x10c00003  beqz        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x17BEC0u;
    {
        const bool branch_taken_0x17bec0 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x17BEC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17BEC0u;
            // 0x17bec4: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17bec0) {
            ctx->pc = 0x17BED0u;
            goto label_17bed0;
        }
    }
    ctx->pc = 0x17BEC8u;
    // 0x17bec8: 0x8053fd2  j           func_14FF48
    ctx->pc = 0x17BEC8u;
    ctx->pc = 0x17BECCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17BEC8u;
            // 0x17becc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x14FF48u;
    {
        auto targetFn = runtime->lookupFunction(0x14FF48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x17BED0u;
label_17bed0:
    // 0x17bed0: 0x80524a0  j           func_149280
    ctx->pc = 0x17BED0u;
    ctx->pc = 0x17BED4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17BED0u;
            // 0x17bed4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x149280u;
    {
        auto targetFn = runtime->lookupFunction(0x149280u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        return;
    }
    ctx->pc = 0x17BED8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
