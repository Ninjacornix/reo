#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D1E00
// Address: 0x1d1e00 - 0x1d1e70
void sub_001D1E00_0x1d1e00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D1E00_0x1d1e00");
#endif

    switch (ctx->pc) {
        case 0x1d1e2cu: goto label_1d1e2c;
        case 0x1d1e40u: goto label_1d1e40;
        case 0x1d1e60u: goto label_1d1e60;
        default: break;
    }

    ctx->pc = 0x1d1e00u;

    // 0x1d1e00: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1d1e00u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1d1e04: 0xa0382d  daddu       $a3, $a1, $zero
    ctx->pc = 0x1d1e04u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1e08: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d1e08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d1e0c: 0x80302d  daddu       $a2, $a0, $zero
    ctx->pc = 0x1d1e0cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1e10: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d1e10u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d1e14: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1d1e14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1d1e18: 0x8c30440c  lw          $s0, 0x440C($at)
    ctx->pc = 0x1d1e18u;
    SET_GPR_S32(ctx, 16, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d1e1c: 0x3c050025  lui         $a1, 0x25
    ctx->pc = 0x1d1e1cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)37 << 16));
    // 0x1d1e20: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d1e20u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d1e24: 0xc042a0c  jal         func_10A830
    ctx->pc = 0x1D1E24u;
    SET_GPR_U32(ctx, 31, 0x1D1E2Cu);
    ctx->pc = 0x1D1E28u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1E24u;
            // 0x1d1e28: 0x24a564c0  addiu       $a1, $a1, 0x64C0 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 25792));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10A830u;
    if (runtime->hasFunction(0x10A830u)) {
        auto targetFn = runtime->lookupFunction(0x10A830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1E2Cu; }
        if (ctx->pc != 0x1D1E2Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1E2Cu; }
        if (ctx->pc != 0x1D1E2Cu) { return; }
    }
    ctx->pc = 0x1D1E2Cu;
label_1d1e2c:
    // 0x1d1e2c: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x1d1e2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d1e30: 0x200282d  daddu       $a1, $s0, $zero
    ctx->pc = 0x1d1e30u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1e34: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1d1e34u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d1e38: 0xc07323c  jal         func_1CC8F0
    ctx->pc = 0x1D1E38u;
    SET_GPR_U32(ctx, 31, 0x1D1E40u);
    ctx->pc = 0x1D1E3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1E38u;
            // 0x1d1e3c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CC8F0u;
    if (runtime->hasFunction(0x1CC8F0u)) {
        auto targetFn = runtime->lookupFunction(0x1CC8F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1E40u; }
        if (ctx->pc != 0x1D1E40u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1E40u; }
        if (ctx->pc != 0x1D1E40u) { return; }
    }
    ctx->pc = 0x1D1E40u;
label_1d1e40:
    // 0x1d1e40: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1d1e40u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1e44: 0x18c00006  blez        $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x1D1E44u;
    {
        const bool branch_taken_0x1d1e44 = (GPR_S64(ctx, 6) <= 0);
        ctx->pc = 0x1D1E48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1E44u;
            // 0x1d1e48: 0x3c05004c  lui         $a1, 0x4C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)76 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d1e44) {
            ctx->pc = 0x1D1E60u;
            goto label_1d1e60;
        }
    }
    ctx->pc = 0x1D1E4Cu;
    // 0x1d1e4c: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x1d1e4cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d1e50: 0x24a5aef0  addiu       $a1, $a1, -0x5110
    ctx->pc = 0x1d1e50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294946544));
    // 0x1d1e54: 0x240700c8  addiu       $a3, $zero, 0xC8
    ctx->pc = 0x1d1e54u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 200));
    // 0x1d1e58: 0xc074658  jal         func_1D1960
    ctx->pc = 0x1D1E58u;
    SET_GPR_U32(ctx, 31, 0x1D1E60u);
    ctx->pc = 0x1D1E5Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1E58u;
            // 0x1d1e5c: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D1960u;
    if (runtime->hasFunction(0x1D1960u)) {
        auto targetFn = runtime->lookupFunction(0x1D1960u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1E60u; }
        if (ctx->pc != 0x1D1E60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D1960_0x1d1960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D1E60u; }
        if (ctx->pc != 0x1D1E60u) { return; }
    }
    ctx->pc = 0x1D1E60u;
label_1d1e60:
    // 0x1d1e60: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d1e60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d1e64: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d1e64u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d1e68: 0x3e00008  jr          $ra
    ctx->pc = 0x1D1E68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D1E6Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D1E68u;
            // 0x1d1e6c: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D1E2Cu: goto label_1d1e2c;
            case 0x1D1E40u: goto label_1d1e40;
            case 0x1D1E60u: goto label_1d1e60;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D1E70u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
