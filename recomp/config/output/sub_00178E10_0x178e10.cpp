#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00178E10
// Address: 0x178e10 - 0x178e58
void sub_00178E10_0x178e10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00178E10_0x178e10");
#endif

    switch (ctx->pc) {
        case 0x178e28u: goto label_178e28;
        case 0x178e40u: goto label_178e40;
        default: break;
    }

    ctx->pc = 0x178e10u;

    // 0x178e10: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x178e10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x178e14: 0x2405000f  addiu       $a1, $zero, 0xF
    ctx->pc = 0x178e14u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 15));
    // 0x178e18: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x178e18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x178e1c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x178e1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x178e20: 0xc05d58a  jal         func_175628
    ctx->pc = 0x178E20u;
    SET_GPR_U32(ctx, 31, 0x178E28u);
    ctx->pc = 0x178E24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x178E20u;
            // 0x178e24: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x175628u;
    if (runtime->hasFunction(0x175628u)) {
        auto targetFn = runtime->lookupFunction(0x175628u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178E28u; }
        if (ctx->pc != 0x178E28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00175628_0x175628(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178E28u; }
        if (ctx->pc != 0x178E28u) { return; }
    }
    ctx->pc = 0x178E28u;
label_178e28:
    // 0x178e28: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x178E28u;
    {
        const bool branch_taken_0x178e28 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x178E2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178E28u;
            // 0x178e2c: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178e28) {
            ctx->pc = 0x178E38u;
            goto label_178e38;
        }
    }
    ctx->pc = 0x178E30u;
    // 0x178e30: 0x10000004  b           . + 4 + (0x4 << 2)
    ctx->pc = 0x178E30u;
    {
        const bool branch_taken_0x178e30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x178E34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178E30u;
            // 0x178e34: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x178e30) {
            ctx->pc = 0x178E44u;
            goto label_178e44;
        }
    }
    ctx->pc = 0x178E38u;
label_178e38:
    // 0x178e38: 0xc05dcea  jal         func_1773A8
    ctx->pc = 0x178E38u;
    SET_GPR_U32(ctx, 31, 0x178E40u);
    ctx->pc = 0x1773A8u;
    if (runtime->hasFunction(0x1773A8u)) {
        auto targetFn = runtime->lookupFunction(0x1773A8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178E40u; }
        if (ctx->pc != 0x178E40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001773A8_0x1773a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178E40u; }
        if (ctx->pc != 0x178E40u) { return; }
    }
    ctx->pc = 0x178E40u;
label_178e40:
    // 0x178e40: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x178e40u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_178e44:
    // 0x178e44: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x178e44u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178e48: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x178e48u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x178e4c: 0x3e00008  jr          $ra
    ctx->pc = 0x178E4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178E50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x178E4Cu;
            // 0x178e50: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x178E28u: goto label_178e28;
            case 0x178E38u: goto label_178e38;
            case 0x178E40u: goto label_178e40;
            case 0x178E44u: goto label_178e44;
            default: break;
        }
        return;
    }
    ctx->pc = 0x178E54u;
    // 0x178e54: 0x0  nop
    ctx->pc = 0x178e54u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
