#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0016A0A0
// Address: 0x16a0a0 - 0x16a110
void sub_0016A0A0_0x16a0a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0016A0A0_0x16a0a0");
#endif

    switch (ctx->pc) {
        case 0x16a0b0u: goto label_16a0b0;
        case 0x16a0b8u: goto label_16a0b8;
        case 0x16a0e4u: goto label_16a0e4;
        default: break;
    }

    ctx->pc = 0x16a0a0u;

    // 0x16a0a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x16a0a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16a0a4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x16a0a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16a0a8: 0xc05a844  jal         func_16A110
    ctx->pc = 0x16A0A8u;
    SET_GPR_U32(ctx, 31, 0x16A0B0u);
    ctx->pc = 0x16A110u;
    if (runtime->hasFunction(0x16A110u)) {
        auto targetFn = runtime->lookupFunction(0x16A110u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A0B0u; }
        if (ctx->pc != 0x16A0B0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0016A110_0x16a110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A0B0u; }
        if (ctx->pc != 0x16A0B0u) { return; }
    }
    ctx->pc = 0x16A0B0u;
label_16a0b0:
    // 0x16a0b0: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x16A0B0u;
    {
        const bool branch_taken_0x16a0b0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A0B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A0B0u;
            // 0x16a0b4: 0x3c050027  lui         $a1, 0x27 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)39 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a0b0) {
            ctx->pc = 0x16A0D8u;
            goto label_16a0d8;
        }
    }
    ctx->pc = 0x16A0B8u;
label_16a0b8:
    // 0x16a0b8: 0x0  nop
    ctx->pc = 0x16a0b8u;
    // NOP
    // 0x16a0bc: 0x0  nop
    ctx->pc = 0x16a0bcu;
    // NOP
    // 0x16a0c0: 0x0  nop
    ctx->pc = 0x16a0c0u;
    // NOP
    // 0x16a0c4: 0x0  nop
    ctx->pc = 0x16a0c4u;
    // NOP
    // 0x16a0c8: 0x0  nop
    ctx->pc = 0x16a0c8u;
    // NOP
    // 0x16a0cc: 0x1000fffa  b           . + 4 + (-0x6 << 2)
    ctx->pc = 0x16A0CCu;
    {
        const bool branch_taken_0x16a0cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x16a0cc) {
            ctx->pc = 0x16A0B8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_16a0b8;
        }
    }
    ctx->pc = 0x16A0D4u;
    // 0x16a0d4: 0x0  nop
    ctx->pc = 0x16a0d4u;
    // NOP
label_16a0d8:
    // 0x16a0d8: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x16a0d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x16a0dc: 0xc05600c  jal         func_158030
    ctx->pc = 0x16A0DCu;
    SET_GPR_U32(ctx, 31, 0x16A0E4u);
    ctx->pc = 0x16A0E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A0DCu;
            // 0x16a0e0: 0x24a51a18  addiu       $a1, $a1, 0x1A18 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 6680));
        ctx->in_delay_slot = false;
    ctx->pc = 0x158030u;
    if (runtime->hasFunction(0x158030u)) {
        auto targetFn = runtime->lookupFunction(0x158030u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A0E4u; }
        if (ctx->pc != 0x16A0E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00158030_0x158030(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A0E4u; }
        if (ctx->pc != 0x16A0E4u) { return; }
    }
    ctx->pc = 0x16A0E4u;
label_16a0e4:
    // 0x16a0e4: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x16A0E4u;
    {
        const bool branch_taken_0x16a0e4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x16A0E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A0E4u;
            // 0x16a0e8: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x16a0e4) {
            ctx->pc = 0x16A100u;
            goto label_16a100;
        }
    }
    ctx->pc = 0x16A0ECu;
    // 0x16a0ec: 0x3c05ff00  lui         $a1, 0xFF00
    ctx->pc = 0x16a0ecu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)65280 << 16));
    // 0x16a0f0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x16a0f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a0f4: 0x34a50d01  ori         $a1, $a1, 0xD01
    ctx->pc = 0x16a0f4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)3329);
    // 0x16a0f8: 0x805a704  j           func_169C10
    ctx->pc = 0x16A0F8u;
    ctx->pc = 0x16A0FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x16A0F8u;
            // 0x16a0fc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x169C10u;
    if (runtime->hasFunction(0x169C10u)) {
        auto targetFn = runtime->lookupFunction(0x169C10u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x16A100u;
label_16a100:
    // 0x16a100: 0x3c030023  lui         $v1, 0x23
    ctx->pc = 0x16a100u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
    // 0x16a104: 0xac60f1b0  sw          $zero, -0xE50($v1)
    ctx->pc = 0x16a104u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294963632), GPR_U32(ctx, 0));
    // 0x16a108: 0x3e00008  jr          $ra
    ctx->pc = 0x16A108u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16A10Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x16A108u;
            // 0x16a10c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16A0B0u: goto label_16a0b0;
            case 0x16A0B8u: goto label_16a0b8;
            case 0x16A0D8u: goto label_16a0d8;
            case 0x16A0E4u: goto label_16a0e4;
            case 0x16A100u: goto label_16a100;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16A110u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
