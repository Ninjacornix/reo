#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0017E5A8
// Address: 0x17e5a8 - 0x17e5e8
void sub_0017E5A8_0x17e5a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0017E5A8_0x17e5a8");
#endif

    switch (ctx->pc) {
        case 0x17e5d8u: goto label_17e5d8;
        default: break;
    }

    ctx->pc = 0x17e5a8u;

    // 0x17e5a8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x17e5a8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17e5ac: 0x10800003  beqz        $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x17E5ACu;
    {
        const bool branch_taken_0x17e5ac = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x17E5B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E5ACu;
            // 0x17e5b0: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e5ac) {
            ctx->pc = 0x17E5BCu;
            goto label_17e5bc;
        }
    }
    ctx->pc = 0x17E5B4u;
    // 0x17e5b4: 0x4a10004  bgez        $a1, . + 4 + (0x4 << 2)
    ctx->pc = 0x17E5B4u;
    {
        const bool branch_taken_0x17e5b4 = (GPR_S64(ctx, 5) >= 0);
        ctx->pc = 0x17E5B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E5B4u;
            // 0x17e5b8: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e5b4) {
            ctx->pc = 0x17E5C8u;
            goto label_17e5c8;
        }
    }
    ctx->pc = 0x17E5BCu;
label_17e5bc:
    // 0x17e5bc: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x17E5BCu;
    {
        const bool branch_taken_0x17e5bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x17E5C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E5BCu;
            // 0x17e5c0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x17e5bc) {
            ctx->pc = 0x17E5DCu;
            goto label_17e5dc;
        }
    }
    ctx->pc = 0x17E5C4u;
    // 0x17e5c4: 0x0  nop
    ctx->pc = 0x17e5c4u;
    // NOP
label_17e5c8:
    // 0x17e5c8: 0x24840012  addiu       $a0, $a0, 0x12
    ctx->pc = 0x17e5c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 18));
    // 0x17e5cc: 0x24a51530  addiu       $a1, $a1, 0x1530
    ctx->pc = 0x17e5ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 5424));
    // 0x17e5d0: 0xc042d10  jal         func_10B440
    ctx->pc = 0x17E5D0u;
    SET_GPR_U32(ctx, 31, 0x17E5D8u);
    ctx->pc = 0x17E5D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x17E5D0u;
            // 0x17e5d4: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10B440u;
    if (runtime->hasFunction(0x10B440u)) {
        auto targetFn = runtime->lookupFunction(0x10B440u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E5D8u; }
        if (ctx->pc != 0x17E5D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B440_0x10b440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17E5D8u; }
        if (ctx->pc != 0x17E5D8u) { return; }
    }
    ctx->pc = 0x17E5D8u;
label_17e5d8:
    // 0x17e5d8: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x17e5d8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
label_17e5dc:
    // 0x17e5dc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x17e5dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x17e5e0: 0x3e00008  jr          $ra
    ctx->pc = 0x17E5E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x17E5E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x17E5E0u;
            // 0x17e5e4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17E5BCu: goto label_17e5bc;
            case 0x17E5C8u: goto label_17e5c8;
            case 0x17E5D8u: goto label_17e5d8;
            case 0x17E5DCu: goto label_17e5dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17E5E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
