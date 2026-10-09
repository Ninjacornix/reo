#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0015D7C8
// Address: 0x15d7c8 - 0x15d820
void sub_0015D7C8_0x15d7c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0015D7C8_0x15d7c8");
#endif

    switch (ctx->pc) {
        case 0x15d7e4u: goto label_15d7e4;
        default: break;
    }

    ctx->pc = 0x15d7c8u;

    // 0x15d7c8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x15d7c8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x15d7cc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15d7ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x15d7d0: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x15d7d0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x15d7d4: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x15d7d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x15d7d8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x15d7d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x15d7dc: 0xc057ff0  jal         func_15FFC0
    ctx->pc = 0x15D7DCu;
    SET_GPR_U32(ctx, 31, 0x15D7E4u);
    ctx->pc = 0x15D7E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D7DCu;
            // 0x15d7e0: 0xa0882d  daddu       $s1, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x15FFC0u;
    if (runtime->hasFunction(0x15FFC0u)) {
        auto targetFn = runtime->lookupFunction(0x15FFC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D7E4u; }
        if (ctx->pc != 0x15D7E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FFC0_0x15ffc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x15D7E4u; }
        if (ctx->pc != 0x15D7E4u) { return; }
    }
    ctx->pc = 0x15D7E4u;
label_15d7e4:
    // 0x15d7e4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x15d7e4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x15d7e8: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x15D7E8u;
    {
        const bool branch_taken_0x15d7e8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x15D7ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D7E8u;
            // 0x15d7ec: 0x2484ebf0  addiu       $a0, $a0, -0x1410 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294962160));
        ctx->in_delay_slot = false;
        if (branch_taken_0x15d7e8) {
            ctx->pc = 0x15D808u;
            goto label_15d808;
        }
    }
    ctx->pc = 0x15D7F0u;
    // 0x15d7f0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15d7f0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15d7f4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15d7f4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15d7f8: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15d7f8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15d7fc: 0x8058dd4  j           func_163750
    ctx->pc = 0x15D7FCu;
    ctx->pc = 0x15D800u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x15D7FCu;
            // 0x15d800: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x163750u;
    if (runtime->hasFunction(0x163750u)) {
        auto targetFn = runtime->lookupFunction(0x163750u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00163750_0x163750(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x15D804u;
    // 0x15d804: 0x0  nop
    ctx->pc = 0x15d804u;
    // NOP
label_15d808:
    // 0x15d808: 0xae110054  sw          $s1, 0x54($s0)
    ctx->pc = 0x15d808u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 17));
    // 0x15d80c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x15d80cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x15d810: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x15d810u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15d814: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x15d814u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x15d818: 0x3e00008  jr          $ra
    ctx->pc = 0x15D818u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x15D81Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x15D818u;
            // 0x15d81c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x15D7E4u: goto label_15d7e4;
            case 0x15D808u: goto label_15d808;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15D820u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
