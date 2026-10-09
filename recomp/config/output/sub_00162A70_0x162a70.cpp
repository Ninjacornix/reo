#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00162A70
// Address: 0x162a70 - 0x162af8
void sub_00162A70_0x162a70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00162A70_0x162a70");
#endif

    switch (ctx->pc) {
        case 0x162a80u: goto label_162a80;
        case 0x162ae0u: goto label_162ae0;
        default: break;
    }

    ctx->pc = 0x162a70u;

    // 0x162a70: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162a70u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162a74: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x162a74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x162a78: 0xc04f428  jal         func_13D0A0
    ctx->pc = 0x162A78u;
    SET_GPR_U32(ctx, 31, 0x162A80u);
    ctx->pc = 0x13D0A0u;
    if (runtime->hasFunction(0x13D0A0u)) {
        auto targetFn = runtime->lookupFunction(0x13D0A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162A80u; }
        if (ctx->pc != 0x162A80u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D0A0_0x13d0a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162A80u; }
        if (ctx->pc != 0x162A80u) { return; }
    }
    ctx->pc = 0x162A80u;
label_162a80:
    // 0x162a80: 0x38420003  xori        $v0, $v0, 0x3
    ctx->pc = 0x162a80u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)3);
    // 0x162a84: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162a84u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162a88: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x162a88u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x162a8c: 0x3e00008  jr          $ra
    ctx->pc = 0x162A8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162A90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162A8Cu;
            // 0x162a90: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162A80u: goto label_162a80;
            case 0x162AB8u: goto label_162ab8;
            case 0x162AE0u: goto label_162ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162A94u;
    // 0x162a94: 0x0  nop
    ctx->pc = 0x162a94u;
    // NOP
    // 0x162a98: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162a98u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162a9c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x162a9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x162aa0: 0x8c82004c  lw          $v0, 0x4C($a0)
    ctx->pc = 0x162aa0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 76)));
    // 0x162aa4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x162AA4u;
    {
        const bool branch_taken_0x162aa4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x162AA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162AA4u;
            // 0x162aa8: 0x40202d  daddu       $a0, $v0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x162aa4) {
            ctx->pc = 0x162AB8u;
            goto label_162ab8;
        }
    }
    ctx->pc = 0x162AACu;
    // 0x162aac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162aacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162ab0: 0x804f4d6  j           func_13D358
    ctx->pc = 0x162AB0u;
    ctx->pc = 0x162AB4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162AB0u;
            // 0x162ab4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D358u;
    if (runtime->hasFunction(0x13D358u)) {
        auto targetFn = runtime->lookupFunction(0x13D358u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0013D358_0x13d358(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x162AB8u;
label_162ab8:
    // 0x162ab8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x162ab8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162abc: 0x3e00008  jr          $ra
    ctx->pc = 0x162ABCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162AC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162ABCu;
            // 0x162ac0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162A80u: goto label_162a80;
            case 0x162AB8u: goto label_162ab8;
            case 0x162AE0u: goto label_162ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162AC4u;
    // 0x162ac4: 0x0  nop
    ctx->pc = 0x162ac4u;
    // NOP
    // 0x162ac8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x162ac8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x162acc: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x162accu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x162ad0: 0xa0802d  daddu       $s0, $a1, $zero
    ctx->pc = 0x162ad0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x162ad4: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x162ad4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x162ad8: 0xc04f4f0  jal         func_13D3C0
    ctx->pc = 0x162AD8u;
    SET_GPR_U32(ctx, 31, 0x162AE0u);
    ctx->pc = 0x162ADCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x162AD8u;
            // 0x162adc: 0x8c84004c  lw          $a0, 0x4C($a0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 76)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x13D3C0u;
    if (runtime->hasFunction(0x13D3C0u)) {
        auto targetFn = runtime->lookupFunction(0x13D3C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162AE0u; }
        if (ctx->pc != 0x162AE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0013D3C0_0x13d3c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x162AE0u; }
        if (ctx->pc != 0x162AE0u) { return; }
    }
    ctx->pc = 0x162AE0u;
label_162ae0:
    // 0x162ae0: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x162ae0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x162ae4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x162ae4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x162ae8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x162ae8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x162aec: 0x3e00008  jr          $ra
    ctx->pc = 0x162AECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x162AF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x162AECu;
            // 0x162af0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x162A80u: goto label_162a80;
            case 0x162AB8u: goto label_162ab8;
            case 0x162AE0u: goto label_162ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x162AF4u;
    // 0x162af4: 0x0  nop
    ctx->pc = 0x162af4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
