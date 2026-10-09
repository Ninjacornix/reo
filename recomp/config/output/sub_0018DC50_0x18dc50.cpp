#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0018DC50
// Address: 0x18dc50 - 0x18dc90
void sub_0018DC50_0x18dc50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0018DC50_0x18dc50");
#endif

    switch (ctx->pc) {
        case 0x18dc64u: goto label_18dc64;
        case 0x18dc74u: goto label_18dc74;
        case 0x18dc7cu: goto label_18dc7c;
        default: break;
    }

    ctx->pc = 0x18dc50u;

    // 0x18dc50: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x18dc50u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x18dc54: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x18dc54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x18dc58: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x18dc58u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18dc5c: 0xc068350  jal         func_1A0D40
    ctx->pc = 0x18DC5Cu;
    SET_GPR_U32(ctx, 31, 0x18DC64u);
    ctx->pc = 0x18DC60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DC5Cu;
            // 0x18dc60: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A0D40u;
    if (runtime->hasFunction(0x1A0D40u)) {
        auto targetFn = runtime->lookupFunction(0x1A0D40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DC64u; }
        if (ctx->pc != 0x18DC64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A0D40_0x1a0d40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DC64u; }
        if (ctx->pc != 0x18DC64u) { return; }
    }
    ctx->pc = 0x18DC64u;
label_18dc64:
    // 0x18dc64: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x18DC64u;
    {
        const bool branch_taken_0x18dc64 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x18dc64) {
            ctx->pc = 0x18DC7Cu;
            goto label_18dc7c;
        }
    }
    ctx->pc = 0x18DC6Cu;
    // 0x18dc6c: 0xc06372c  jal         func_18DCB0
    ctx->pc = 0x18DC6Cu;
    SET_GPR_U32(ctx, 31, 0x18DC74u);
    ctx->pc = 0x18DCB0u;
    if (runtime->hasFunction(0x18DCB0u)) {
        auto targetFn = runtime->lookupFunction(0x18DCB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DC74u; }
        if (ctx->pc != 0x18DC74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DC74u; }
        if (ctx->pc != 0x18DC74u) { return; }
    }
    ctx->pc = 0x18DC74u;
label_18dc74:
    // 0x18dc74: 0xc068354  jal         func_1A0D50
    ctx->pc = 0x18DC74u;
    SET_GPR_U32(ctx, 31, 0x18DC7Cu);
    ctx->pc = 0x18DC78u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x18DC74u;
            // 0x18dc78: 0x200202d  daddu       $a0, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1A0D50u;
    if (runtime->hasFunction(0x1A0D50u)) {
        auto targetFn = runtime->lookupFunction(0x1A0D50u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DC7Cu; }
        if (ctx->pc != 0x18DC7Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001A0D50_0x1a0d50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DC7Cu; }
        if (ctx->pc != 0x18DC7Cu) { return; }
    }
    ctx->pc = 0x18DC7Cu;
label_18dc7c:
    // 0x18dc7c: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x18dc7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18dc80: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x18dc80u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18dc84: 0x3e00008  jr          $ra
    ctx->pc = 0x18DC84u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18DC88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x18DC84u;
            // 0x18dc88: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18DC64u: goto label_18dc64;
            case 0x18DC74u: goto label_18dc74;
            case 0x18DC7Cu: goto label_18dc7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18DC8Cu;
    // 0x18dc8c: 0x0  nop
    ctx->pc = 0x18dc8cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
