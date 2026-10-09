#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00175E00
// Address: 0x175e00 - 0x175e50
void sub_00175E00_0x175e00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00175E00_0x175e00");
#endif

    switch (ctx->pc) {
        case 0x175e14u: goto label_175e14;
        case 0x175e20u: goto label_175e20;
        default: break;
    }

    ctx->pc = 0x175e00u;

    // 0x175e00: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x175e00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x175e04: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x175e04u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x175e08: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x175e08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x175e0c: 0xc05d794  jal         func_175E50
    ctx->pc = 0x175E0Cu;
    SET_GPR_U32(ctx, 31, 0x175E14u);
    ctx->pc = 0x175E10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175E0Cu;
            // 0x175e10: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175E50u;
    if (runtime->hasFunction(0x175E50u)) {
        auto targetFn = runtime->lookupFunction(0x175E50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175E14u; }
        if (ctx->pc != 0x175E14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175E50_0x175e50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175E14u; }
        if (ctx->pc != 0x175E14u) { return; }
    }
    ctx->pc = 0x175E14u;
label_175e14:
    // 0x175e14: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x175e14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x175e18: 0xc05d58a  jal         func_175628
    ctx->pc = 0x175E18u;
    SET_GPR_U32(ctx, 31, 0x175E20u);
    ctx->pc = 0x175E1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175E18u;
            // 0x175e1c: 0x24050047  addiu       $a1, $zero, 0x47 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 71));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175E20u; }
        if (ctx->pc != 0x175E20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x175E20u; }
        if (ctx->pc != 0x175E20u) { return; }
    }
    ctx->pc = 0x175E20u;
label_175e20:
    // 0x175e20: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x175e20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x175e24: 0x14430006  bne         $v0, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x175E24u;
    {
        const bool branch_taken_0x175e24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x175E28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175E24u;
            // 0x175e28: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x175e24) {
            ctx->pc = 0x175E40u;
            goto label_175e40;
        }
    }
    ctx->pc = 0x175E2Cu;
    // 0x175e2c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x175e2cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x175e30: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x175e30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x175e34: 0x805da4c  j           func_176930
    ctx->pc = 0x175E34u;
    ctx->pc = 0x175E38u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x175E34u;
            // 0x175e38: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x176930u;
    if (runtime->hasFunction(0x176930u)) {
        auto targetFn = runtime->lookupFunction(0x176930u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00176930_0x176930(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x175E3Cu;
    // 0x175e3c: 0x0  nop
    ctx->pc = 0x175e3cu;
    // NOP
label_175e40:
    // 0x175e40: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x175e40u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x175e44: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x175e44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x175e48: 0x3e00008  jr          $ra
    ctx->pc = 0x175E48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x175E4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x175E48u;
            // 0x175e4c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x175E14u: goto label_175e14;
            case 0x175E20u: goto label_175e20;
            case 0x175E40u: goto label_175e40;
            default: break;
        }
        return;
    }
    ctx->pc = 0x175E50u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
