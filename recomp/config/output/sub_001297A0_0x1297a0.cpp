#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001297A0
// Address: 0x1297a0 - 0x1297e0
void sub_001297A0_0x1297a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001297A0_0x1297a0");
#endif

    switch (ctx->pc) {
        case 0x1297bcu: goto label_1297bc;
        default: break;
    }

    ctx->pc = 0x1297a0u;

    // 0x1297a0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1297a0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1297a4: 0x30c2003f  andi        $v0, $a2, 0x3F
    ctx->pc = 0x1297a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)63);
    // 0x1297a8: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1297A8u;
    {
        const bool branch_taken_0x1297a8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1297ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1297A8u;
            // 0x1297ac: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1297a8) {
            ctx->pc = 0x1297D0u;
            goto label_1297d0;
        }
    }
    ctx->pc = 0x1297B0u;
    // 0x1297b0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1297b0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1297b4: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x1297B4u;
    SET_GPR_U32(ctx, 31, 0x1297BCu);
    ctx->pc = 0x1297B8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1297B4u;
            // 0x1297b8: 0x2484a020  addiu       $a0, $a0, -0x5FE0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294942752));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1297BCu; }
        if (ctx->pc != 0x1297BCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1297BCu; }
        if (ctx->pc != 0x1297BCu) { return; }
    }
    ctx->pc = 0x1297BCu;
label_1297bc:
    // 0x1297bc: 0x2402fffd  addiu       $v0, $zero, -0x3
    ctx->pc = 0x1297bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
    // 0x1297c0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1297c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1297c4: 0x3e00008  jr          $ra
    ctx->pc = 0x1297C4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1297C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1297C4u;
            // 0x1297c8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1297BCu: goto label_1297bc;
            case 0x1297D0u: goto label_1297d0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1297CCu;
    // 0x1297cc: 0x0  nop
    ctx->pc = 0x1297ccu;
    // NOP
label_1297d0:
    // 0x1297d0: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1297d0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1297d4: 0x804a584  j           func_129610
    ctx->pc = 0x1297D4u;
    ctx->pc = 0x1297D8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1297D4u;
            // 0x1297d8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x129610u;
    if (runtime->hasFunction(0x129610u)) {
        auto targetFn = runtime->lookupFunction(0x129610u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00129610_0x129610(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x1297DCu;
    // 0x1297dc: 0x0  nop
    ctx->pc = 0x1297dcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
