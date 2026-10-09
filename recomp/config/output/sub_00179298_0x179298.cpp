#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00179298
// Address: 0x179298 - 0x1792e0
void sub_00179298_0x179298(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00179298_0x179298");
#endif

    switch (ctx->pc) {
        case 0x1792acu: goto label_1792ac;
        default: break;
    }

    ctx->pc = 0x179298u;

    // 0x179298: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x179298u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x17929c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x17929cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1792a0: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1792a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1792a4: 0xc05e4b8  jal         func_1792E0
    ctx->pc = 0x1792A4u;
    SET_GPR_U32(ctx, 31, 0x1792ACu);
    ctx->pc = 0x1792A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1792A4u;
            // 0x1792a8: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1792E0u;
    if (runtime->hasFunction(0x1792E0u)) {
        auto targetFn = runtime->lookupFunction(0x1792E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1792ACu; }
        if (ctx->pc != 0x1792ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001792E0_0x1792e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1792ACu; }
        if (ctx->pc != 0x1792ACu) { return; }
    }
    ctx->pc = 0x1792ACu;
label_1792ac:
    // 0x1792ac: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1792ACu;
    {
        const bool branch_taken_0x1792ac = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1792B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1792ACu;
            // 0x1792b0: 0x2404006b  addiu       $a0, $zero, 0x6B (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 107));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1792ac) {
            ctx->pc = 0x1792CCu;
            goto label_1792cc;
        }
    }
    ctx->pc = 0x1792B4u;
    // 0x1792b4: 0x8e02000c  lw          $v0, 0xC($s0)
    ctx->pc = 0x1792b4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1792b8: 0x10440003  beq         $v0, $a0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1792B8u;
    {
        const bool branch_taken_0x1792b8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 4));
        ctx->pc = 0x1792BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1792B8u;
            // 0x1792bc: 0x2843006e  slti        $v1, $v0, 0x6E (Delay Slot)
        SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)110) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1792b8) {
            ctx->pc = 0x1792C8u;
            goto label_1792c8;
        }
    }
    ctx->pc = 0x1792C0u;
    // 0x1792c0: 0x14600002  bnez        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1792C0u;
    {
        const bool branch_taken_0x1792c0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1792C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1792C0u;
            // 0x1792c4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1792c0) {
            ctx->pc = 0x1792CCu;
            goto label_1792cc;
        }
    }
    ctx->pc = 0x1792C8u;
label_1792c8:
    // 0x1792c8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1792c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1792cc:
    // 0x1792cc: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1792ccu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1792d0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1792d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1792d4: 0x3e00008  jr          $ra
    ctx->pc = 0x1792D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1792D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1792D4u;
            // 0x1792d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1792ACu: goto label_1792ac;
            case 0x1792C8u: goto label_1792c8;
            case 0x1792CCu: goto label_1792cc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1792DCu;
    // 0x1792dc: 0x0  nop
    ctx->pc = 0x1792dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
