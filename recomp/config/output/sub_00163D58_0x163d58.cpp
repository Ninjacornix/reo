#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00163D58
// Address: 0x163d58 - 0x163d9c
void sub_00163D58_0x163d58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00163D58_0x163d58");
#endif

    switch (ctx->pc) {
        case 0x163d6cu: goto label_163d6c;
        case 0x163d84u: goto label_163d84;
        default: break;
    }

    ctx->pc = 0x163d58u;

    // 0x163d58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x163d58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x163d5c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x163d5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x163d60: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x163d60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x163d64: 0xc04ad84  jal         func_12B610
    ctx->pc = 0x163D64u;
    SET_GPR_U32(ctx, 31, 0x163D6Cu);
    ctx->pc = 0x163D68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x163D64u;
            // 0x163d68: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x12B610u;
    if (runtime->hasFunction(0x12B610u)) {
        auto targetFn = runtime->lookupFunction(0x12B610u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163D6Cu; }
        if (ctx->pc != 0x163D6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B610_0x12b610(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163D6Cu; }
        if (ctx->pc != 0x163D6Cu) { return; }
    }
    ctx->pc = 0x163D6Cu;
label_163d6c:
    // 0x163d6c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x163d6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x163d70: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x163d70u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163d74: 0x14430004  bne         $v0, $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x163D74u;
    {
        const bool branch_taken_0x163d74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x163D78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163D74u;
            // 0x163d78: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x163d74) {
            ctx->pc = 0x163D88u;
            goto label_163d88;
        }
    }
    ctx->pc = 0x163D7Cu;
    // 0x163d7c: 0xc058faa  jal         func_163EA8
    ctx->pc = 0x163D7Cu;
    SET_GPR_U32(ctx, 31, 0x163D84u);
    ctx->pc = 0x163EA8u;
    if (runtime->hasFunction(0x163EA8u)) {
        auto targetFn = runtime->lookupFunction(0x163EA8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163D84u; }
        if (ctx->pc != 0x163D84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00163EA8_0x163ea8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x163D84u; }
        if (ctx->pc != 0x163D84u) { return; }
    }
    ctx->pc = 0x163D84u;
label_163d84:
    // 0x163d84: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x163d84u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_163d88:
    // 0x163d88: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x163d88u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x163d8c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x163d8cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x163d90: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x163d90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x163d94: 0x3e00008  jr          $ra
    ctx->pc = 0x163D94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x163D98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x163D94u;
            // 0x163d98: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x163D6Cu: goto label_163d6c;
            case 0x163D84u: goto label_163d84;
            case 0x163D88u: goto label_163d88;
            default: break;
        }
        return;
    }
    ctx->pc = 0x163D9Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
