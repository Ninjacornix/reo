#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D6D0
// Address: 0x11d6d0 - 0x11d728
void sub_0011D6D0_0x11d6d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D6D0_0x11d6d0");
#endif

    switch (ctx->pc) {
        case 0x11d6f4u: goto label_11d6f4;
        case 0x11d704u: goto label_11d704;
        default: break;
    }

    ctx->pc = 0x11d6d0u;

    // 0x11d6d0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x11d6d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x11d6d4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x11d6d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x11d6d8: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x11d6d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x11d6dc: 0x3a0202d  daddu       $a0, $sp, $zero
    ctx->pc = 0x11d6dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11d6e0: 0xafa20028  sw          $v0, 0x28($sp)
    ctx->pc = 0x11d6e0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 2));
    // 0x11d6e4: 0xafa20004  sw          $v0, 0x4($sp)
    ctx->pc = 0x11d6e4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x11d6e8: 0xafa20008  sw          $v0, 0x8($sp)
    ctx->pc = 0x11d6e8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
    // 0x11d6ec: 0xc045188  jal         func_114620
    ctx->pc = 0x11D6ECu;
    SET_GPR_U32(ctx, 31, 0x11D6F4u);
    ctx->pc = 0x11D6F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D6ECu;
            // 0x11d6f0: 0xafa20024  sw          $v0, 0x24($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D6F4u; }
        if (ctx->pc != 0x11D6F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D6F4u; }
        if (ctx->pc != 0x11D6F4u) { return; }
    }
    ctx->pc = 0x11D6F4u;
label_11d6f4:
    // 0x11d6f4: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11d6f4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11d6f8: 0x27a40020  addiu       $a0, $sp, 0x20
    ctx->pc = 0x11d6f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x11d6fc: 0xc045188  jal         func_114620
    ctx->pc = 0x11D6FCu;
    SET_GPR_U32(ctx, 31, 0x11D704u);
    ctx->pc = 0x11D700u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11D6FCu;
            // 0x11d700: 0xac62a470  sw          $v0, -0x5B90($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294943856), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114620u;
    if (runtime->hasFunction(0x114620u)) {
        auto targetFn = runtime->lookupFunction(0x114620u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D704u; }
        if (ctx->pc != 0x11D704u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114620_0x114620(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11D704u; }
        if (ctx->pc != 0x11D704u) { return; }
    }
    ctx->pc = 0x11D704u;
label_11d704:
    // 0x11d704: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11d704u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11d708: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x11d708u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x11d70c: 0xac62a474  sw          $v0, -0x5B8C($v1)
    ctx->pc = 0x11d70cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294943860), GPR_U32(ctx, 2));
    // 0x11d710: 0x3e00008  jr          $ra
    ctx->pc = 0x11D710u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11D714u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D710u;
            // 0x11d714: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11D6F4u: goto label_11d6f4;
            case 0x11D704u: goto label_11d704;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11D718u;
    // 0x11d718: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x11d718u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x11d71c: 0x3e00008  jr          $ra
    ctx->pc = 0x11D71Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11D720u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11D71Cu;
            // 0x11d720: 0x8c62a474  lw          $v0, -0x5B8C($v1) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 4294943860)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11D6F4u: goto label_11d6f4;
            case 0x11D704u: goto label_11d704;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11D724u;
    // 0x11d724: 0x0  nop
    ctx->pc = 0x11d724u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
