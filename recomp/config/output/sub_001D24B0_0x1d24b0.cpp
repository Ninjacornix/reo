#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D24B0
// Address: 0x1d24b0 - 0x1d24e4
void sub_001D24B0_0x1d24b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D24B0_0x1d24b0");
#endif

    switch (ctx->pc) {
        case 0x1d24d8u: goto label_1d24d8;
        default: break;
    }

    ctx->pc = 0x1d24b0u;

    // 0x1d24b0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1d24b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d24b4: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d24b4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d24b8: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d24b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d24bc: 0x802343d7  lb          $v1, 0x43D7($at)
    ctx->pc = 0x1d24bcu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d24c0: 0x14600005  bnez        $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x1D24C0u;
    {
        const bool branch_taken_0x1d24c0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d24c0) {
            ctx->pc = 0x1D24D8u;
            goto label_1d24d8;
        }
    }
    ctx->pc = 0x1D24C8u;
    // 0x1d24c8: 0x3082ffff  andi        $v0, $a0, 0xFFFF
    ctx->pc = 0x1d24c8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65535);
    // 0x1d24cc: 0x24052a00  addiu       $a1, $zero, 0x2A00
    ctx->pc = 0x1d24ccu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 10752));
    // 0x1d24d0: 0xc073784  jal         func_1CDE10
    ctx->pc = 0x1D24D0u;
    SET_GPR_U32(ctx, 31, 0x1D24D8u);
    ctx->pc = 0x1D24D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D24D0u;
            // 0x1d24d4: 0x22400  sll         $a0, $v0, 16 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CDE10u;
    if (runtime->hasFunction(0x1CDE10u)) {
        auto targetFn = runtime->lookupFunction(0x1CDE10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D24D8u; }
        if (ctx->pc != 0x1D24D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CDE10_0x1cde10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D24D8u; }
        if (ctx->pc != 0x1D24D8u) { return; }
    }
    ctx->pc = 0x1D24D8u;
label_1d24d8:
    // 0x1d24d8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d24d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d24dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1D24DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D24E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D24DCu;
            // 0x1d24e0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D24D8u: goto label_1d24d8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D24E4u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
