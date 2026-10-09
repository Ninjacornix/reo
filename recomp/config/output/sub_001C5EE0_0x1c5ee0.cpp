#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C5EE0
// Address: 0x1c5ee0 - 0x1c5f30
void sub_001C5EE0_0x1c5ee0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C5EE0_0x1c5ee0");
#endif

    switch (ctx->pc) {
        case 0x1c5f04u: goto label_1c5f04;
        case 0x1c5f18u: goto label_1c5f18;
        case 0x1c5f20u: goto label_1c5f20;
        default: break;
    }

    ctx->pc = 0x1c5ee0u;

    // 0x1c5ee0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1c5ee0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1c5ee4: 0x3c050033  lui         $a1, 0x33
    ctx->pc = 0x1c5ee4u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)51 << 16));
    // 0x1c5ee8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1c5ee8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1c5eec: 0x24a58f20  addiu       $a1, $a1, -0x70E0
    ctx->pc = 0x1c5eecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294938400));
    // 0x1c5ef0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c5ef0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c5ef4: 0x24062000  addiu       $a2, $zero, 0x2000
    ctx->pc = 0x1c5ef4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
    // 0x1c5ef8: 0xa48001cc  sh          $zero, 0x1CC($a0)
    ctx->pc = 0x1c5ef8u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 460), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c5efc: 0xc07224c  jal         func_1C8930
    ctx->pc = 0x1C5EFCu;
    SET_GPR_U32(ctx, 31, 0x1C5F04u);
    ctx->pc = 0x1C5F00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5EFCu;
            // 0x1c5f00: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8930u;
    if (runtime->hasFunction(0x1C8930u)) {
        auto targetFn = runtime->lookupFunction(0x1C8930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5F04u; }
        if (ctx->pc != 0x1C5F04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8930_0x1c8930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5F04u; }
        if (ctx->pc != 0x1C5F04u) { return; }
    }
    ctx->pc = 0x1C5F04u;
label_1c5f04:
    // 0x1c5f04: 0x3c050032  lui         $a1, 0x32
    ctx->pc = 0x1c5f04u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)50 << 16));
    // 0x1c5f08: 0x26040014  addiu       $a0, $s0, 0x14
    ctx->pc = 0x1c5f08u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x1c5f0c: 0x24a56f20  addiu       $a1, $a1, 0x6F20
    ctx->pc = 0x1c5f0cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 28448));
    // 0x1c5f10: 0xc07224c  jal         func_1C8930
    ctx->pc = 0x1C5F10u;
    SET_GPR_U32(ctx, 31, 0x1C5F18u);
    ctx->pc = 0x1C5F14u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5F10u;
            // 0x1c5f14: 0x24062000  addiu       $a2, $zero, 0x2000 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 8192));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C8930u;
    if (runtime->hasFunction(0x1C8930u)) {
        auto targetFn = runtime->lookupFunction(0x1C8930u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5F18u; }
        if (ctx->pc != 0x1C5F18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C8930_0x1c8930(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5F18u; }
        if (ctx->pc != 0x1C5F18u) { return; }
    }
    ctx->pc = 0x1C5F18u;
label_1c5f18:
    // 0x1c5f18: 0xc0720b4  jal         func_1C82D0
    ctx->pc = 0x1C5F18u;
    SET_GPR_U32(ctx, 31, 0x1C5F20u);
    ctx->pc = 0x1C5F1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5F18u;
            // 0x1c5f1c: 0x26040028  addiu       $a0, $s0, 0x28 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 16), 40));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C82D0u;
    if (runtime->hasFunction(0x1C82D0u)) {
        auto targetFn = runtime->lookupFunction(0x1C82D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5F20u; }
        if (ctx->pc != 0x1C5F20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C82D0_0x1c82d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C5F20u; }
        if (ctx->pc != 0x1C5F20u) { return; }
    }
    ctx->pc = 0x1C5F20u;
label_1c5f20:
    // 0x1c5f20: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1c5f20u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c5f24: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1c5f24u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1c5f28: 0x3e00008  jr          $ra
    ctx->pc = 0x1C5F28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C5F2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C5F28u;
            // 0x1c5f2c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C5F04u: goto label_1c5f04;
            case 0x1C5F18u: goto label_1c5f18;
            case 0x1C5F20u: goto label_1c5f20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C5F30u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
