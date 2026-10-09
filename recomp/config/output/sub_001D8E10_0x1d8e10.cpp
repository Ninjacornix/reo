#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D8E10
// Address: 0x1d8e10 - 0x1d8e70
void sub_001D8E10_0x1d8e10(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D8E10_0x1d8e10");
#endif

    switch (ctx->pc) {
        case 0x1d8e24u: goto label_1d8e24;
        case 0x1d8e44u: goto label_1d8e44;
        case 0x1d8e5cu: goto label_1d8e5c;
        default: break;
    }

    ctx->pc = 0x1d8e10u;

    // 0x1d8e10: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d8e10u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1d8e14: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d8e14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d8e18: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d8e18u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d8e1c: 0xc075e38  jal         func_1D78E0
    ctx->pc = 0x1D8E1Cu;
    SET_GPR_U32(ctx, 31, 0x1D8E24u);
    ctx->pc = 0x1D8E20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8E1Cu;
            // 0x1d8e20: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78E0u;
    if (runtime->hasFunction(0x1D78E0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8E24u; }
        if (ctx->pc != 0x1D8E24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78E0_0x1d78e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8E24u; }
        if (ctx->pc != 0x1D8E24u) { return; }
    }
    ctx->pc = 0x1D8E24u;
label_1d8e24:
    // 0x1d8e24: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d8e24u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
    // 0x1d8e28: 0x3c070034  lui         $a3, 0x34
    ctx->pc = 0x1d8e28u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)52 << 16));
    // 0x1d8e2c: 0x2404002e  addiu       $a0, $zero, 0x2E
    ctx->pc = 0x1d8e2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 46));
    // 0x1d8e30: 0x24a57280  addiu       $a1, $a1, 0x7280
    ctx->pc = 0x1d8e30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 29312));
    // 0x1d8e34: 0x24060020  addiu       $a2, $zero, 0x20
    ctx->pc = 0x1d8e34u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1d8e38: 0x24e76280  addiu       $a3, $a3, 0x6280
    ctx->pc = 0x1d8e38u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 25216));
    // 0x1d8e3c: 0xc075e40  jal         func_1D7900
    ctx->pc = 0x1D8E3Cu;
    SET_GPR_U32(ctx, 31, 0x1D8E44u);
    ctx->pc = 0x1D8E40u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8E3Cu;
            // 0x1d8e40: 0x24080024  addiu       $t0, $zero, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7900u;
    if (runtime->hasFunction(0x1D7900u)) {
        auto targetFn = runtime->lookupFunction(0x1D7900u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8E44u; }
        if (ctx->pc != 0x1D8E44u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7900_0x1d7900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8E44u; }
        if (ctx->pc != 0x1D8E44u) { return; }
    }
    ctx->pc = 0x1D8E44u;
label_1d8e44:
    // 0x1d8e44: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d8e44u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d8e48: 0x8c22629c  lw          $v0, 0x629C($at)
    ctx->pc = 0x1d8e48u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 25244)));
    // 0x1d8e4c: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x1d8e4cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x1d8e50: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d8e50u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1d8e54: 0xc075e3c  jal         func_1D78F0
    ctx->pc = 0x1D8E54u;
    SET_GPR_U32(ctx, 31, 0x1D8E5Cu);
    ctx->pc = 0x1D8E58u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8E54u;
            // 0x1d8e58: 0x84306298  lh          $s0, 0x6298($at) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 25240)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D78F0u;
    if (runtime->hasFunction(0x1D78F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D78F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8E5Cu; }
        if (ctx->pc != 0x1D8E5Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D78F0_0x1d78f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D8E5Cu; }
        if (ctx->pc != 0x1D8E5Cu) { return; }
    }
    ctx->pc = 0x1D8E5Cu;
label_1d8e5c:
    // 0x1d8e5c: 0x200102d  daddu       $v0, $s0, $zero
    ctx->pc = 0x1d8e5cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d8e60: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d8e60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d8e64: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d8e64u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d8e68: 0x3e00008  jr          $ra
    ctx->pc = 0x1D8E68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D8E6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D8E68u;
            // 0x1d8e6c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D8E24u: goto label_1d8e24;
            case 0x1D8E44u: goto label_1d8e44;
            case 0x1D8E5Cu: goto label_1d8e5c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D8E70u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
