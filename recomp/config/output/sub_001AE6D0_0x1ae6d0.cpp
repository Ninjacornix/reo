#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AE6D0
// Address: 0x1ae6d0 - 0x1ae740
void sub_001AE6D0_0x1ae6d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AE6D0_0x1ae6d0");
#endif

    switch (ctx->pc) {
        case 0x1ae718u: goto label_1ae718;
        default: break;
    }

    ctx->pc = 0x1ae6d0u;

    // 0x1ae6d0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1ae6d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1ae6d4: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x1ae6d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1ae6d8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1ae6d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1ae6dc: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1ae6dcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1ae6e0: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ae6e0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ae6e4: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1ae6e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1ae6e8: 0x280c0  sll         $s0, $v0, 3
    ctx->pc = 0x1ae6e8u;
    SET_GPR_S32(ctx, 16, (int32_t)SLL32(GPR_U32(ctx, 2), 3));
    // 0x1ae6ec: 0x24638d72  addiu       $v1, $v1, -0x728E
    ctx->pc = 0x1ae6ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294937970));
    // 0x1ae6f0: 0x702821  addu        $a1, $v1, $s0
    ctx->pc = 0x1ae6f0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1ae6f4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ae6f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ae6f8: 0xa0a20000  sb          $v0, 0x0($a1)
    ctx->pc = 0x1ae6f8u;
    WRITE8(ADD32(GPR_U32(ctx, 5), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ae6fc: 0x41880  sll         $v1, $a0, 2
    ctx->pc = 0x1ae6fcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 2));
    // 0x1ae700: 0x3c02002c  lui         $v0, 0x2C
    ctx->pc = 0x1ae700u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)44 << 16));
    // 0x1ae704: 0x24428dc8  addiu       $v0, $v0, -0x7238
    ctx->pc = 0x1ae704u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294938056));
    // 0x1ae708: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1ae708u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1ae70c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1ae70cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1ae710: 0xc04cb7c  jal         func_132DF0
    ctx->pc = 0x1AE710u;
    SET_GPR_U32(ctx, 31, 0x1AE718u);
    ctx->pc = 0x1AE714u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE710u;
            // 0x1ae714: 0x80a50000  lb          $a1, 0x0($a1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x132DF0u;
    if (runtime->hasFunction(0x132DF0u)) {
        auto targetFn = runtime->lookupFunction(0x132DF0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE718u; }
        if (ctx->pc != 0x1AE718u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00132DF0_0x132df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1AE718u; }
        if (ctx->pc != 0x1AE718u) { return; }
    }
    ctx->pc = 0x1AE718u;
label_1ae718:
    // 0x1ae718: 0x3c03002c  lui         $v1, 0x2C
    ctx->pc = 0x1ae718u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)44 << 16));
    // 0x1ae71c: 0x24638d73  addiu       $v1, $v1, -0x728D
    ctx->pc = 0x1ae71cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294937971));
    // 0x1ae720: 0x701821  addu        $v1, $v1, $s0
    ctx->pc = 0x1ae720u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1ae724: 0xa0600000  sb          $zero, 0x0($v1)
    ctx->pc = 0x1ae724u;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ae728: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1ae728u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ae72c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ae72cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ae730: 0x3e00008  jr          $ra
    ctx->pc = 0x1AE730u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1AE734u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AE730u;
            // 0x1ae734: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AE718u: goto label_1ae718;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AE738u;
    // 0x1ae738: 0x0  nop
    ctx->pc = 0x1ae738u;
    // NOP
    // 0x1ae73c: 0x0  nop
    ctx->pc = 0x1ae73cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
