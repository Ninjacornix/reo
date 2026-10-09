#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00114AB0
// Address: 0x114ab0 - 0x114b40
void sub_00114AB0_0x114ab0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00114AB0_0x114ab0");
#endif

    switch (ctx->pc) {
        case 0x114ac0u: goto label_114ac0;
        case 0x114ae4u: goto label_114ae4;
        case 0x114af0u: goto label_114af0;
        case 0x114b14u: goto label_114b14;
        default: break;
    }

    ctx->pc = 0x114ab0u;

    // 0x114ab0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x114ab0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x114ab4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x114ab4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x114ab8: 0xc047598  jal         func_11D660
    ctx->pc = 0x114AB8u;
    SET_GPR_U32(ctx, 31, 0x114AC0u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114AC0u; }
        if (ctx->pc != 0x114AC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114AC0u; }
        if (ctx->pc != 0x114AC0u) { return; }
    }
    ctx->pc = 0x114AC0u;
label_114ac0:
    // 0x114ac0: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x114ac0u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x114ac4: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x114ac4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x114ac8: 0x3463f000  ori         $v1, $v1, 0xF000
    ctx->pc = 0x114ac8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)61440);
    // 0x114acc: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x114accu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x114ad0: 0xf  sync
    ctx->pc = 0x114ad0u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x114ad4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x114AD4u;
    {
        const bool branch_taken_0x114ad4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x114AD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114AD4u;
            // 0x114ad8: 0x3c031000  lui         $v1, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x114ad4) {
            ctx->pc = 0x114AE8u;
            goto label_114ae8;
        }
    }
    ctx->pc = 0x114ADCu;
    // 0x114adc: 0xc0475ae  jal         func_11D6B8
    ctx->pc = 0x114ADCu;
    SET_GPR_U32(ctx, 31, 0x114AE4u);
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114AE4u; }
        if (ctx->pc != 0x114AE4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114AE4u; }
        if (ctx->pc != 0x114AE4u) { return; }
    }
    ctx->pc = 0x114AE4u;
label_114ae4:
    // 0x114ae4: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x114ae4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
label_114ae8:
    // 0x114ae8: 0x3463f000  ori         $v1, $v1, 0xF000
    ctx->pc = 0x114ae8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)61440);
    // 0x114aec: 0x0  nop
    ctx->pc = 0x114aecu;
    // NOP
label_114af0:
    // 0x114af0: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x114af0u;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x114af4: 0x30420004  andi        $v0, $v0, 0x4
    ctx->pc = 0x114af4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)4);
    // 0x114af8: 0x0  nop
    ctx->pc = 0x114af8u;
    // NOP
    // 0x114afc: 0x0  nop
    ctx->pc = 0x114afcu;
    // NOP
    // 0x114b00: 0x0  nop
    ctx->pc = 0x114b00u;
    // NOP
    // 0x114b04: 0x1040fffa  beqz        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x114B04u;
    {
        const bool branch_taken_0x114b04 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x114b04) {
            ctx->pc = 0x114AF0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_114af0;
        }
    }
    ctx->pc = 0x114B0Cu;
    // 0x114b0c: 0xc047598  jal         func_11D660
    ctx->pc = 0x114B0Cu;
    SET_GPR_U32(ctx, 31, 0x114B14u);
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114B14u; }
        if (ctx->pc != 0x114B14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x114B14u; }
        if (ctx->pc != 0x114B14u) { return; }
    }
    ctx->pc = 0x114B14u;
label_114b14:
    // 0x114b14: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x114b14u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x114b18: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x114b18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x114b1c: 0x3463f000  ori         $v1, $v1, 0xF000
    ctx->pc = 0x114b1cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)61440);
    // 0x114b20: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x114b20u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x114b24: 0xf  sync
    ctx->pc = 0x114b24u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x114b28: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x114B28u;
    {
        const bool branch_taken_0x114b28 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x114B2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114B28u;
            // 0x114b2c: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x114b28) {
            ctx->pc = 0x114B38u;
            goto label_114b38;
        }
    }
    ctx->pc = 0x114B30u;
    // 0x114b30: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x114B30u;
    ctx->pc = 0x114B34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x114B30u;
            // 0x114b34: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x114B38u;
label_114b38:
    // 0x114b38: 0x3e00008  jr          $ra
    ctx->pc = 0x114B38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x114B3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x114B38u;
            // 0x114b3c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x114AC0u: goto label_114ac0;
            case 0x114AE4u: goto label_114ae4;
            case 0x114AE8u: goto label_114ae8;
            case 0x114AF0u: goto label_114af0;
            case 0x114B14u: goto label_114b14;
            case 0x114B38u: goto label_114b38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x114B40u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
