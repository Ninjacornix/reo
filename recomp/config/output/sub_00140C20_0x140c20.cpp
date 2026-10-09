#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140C20
// Address: 0x140c20 - 0x140c90
void sub_00140C20_0x140c20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140C20_0x140c20");
#endif

    switch (ctx->pc) {
        case 0x140c54u: goto label_140c54;
        default: break;
    }

    ctx->pc = 0x140c20u;

    // 0x140c20: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140c20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x140c24: 0x3c050026  lui         $a1, 0x26
    ctx->pc = 0x140c24u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)38 << 16));
    // 0x140c28: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x140c28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x140c2c: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x140c2cu;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x140c30: 0x24a54600  addiu       $a1, $a1, 0x4600
    ctx->pc = 0x140c30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 17920));
    // 0x140c34: 0x26104700  addiu       $s0, $s0, 0x4700
    ctx->pc = 0x140c34u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18176));
    // 0x140c38: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x140c38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x140c3c: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x140c3cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140c40: 0xaca40000  sw          $a0, 0x0($a1)
    ctx->pc = 0x140c40u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 4));
    // 0x140c44: 0x24040024  addiu       $a0, $zero, 0x24
    ctx->pc = 0x140c44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 36));
    // 0x140c48: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x140c48u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x140c4c: 0xc04e518  jal         func_139460
    ctx->pc = 0x140C4Cu;
    SET_GPR_U32(ctx, 31, 0x140C54u);
    ctx->pc = 0x140C50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140C4Cu;
            // 0x140c50: 0x24080004  addiu       $t0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140C54u; }
        if (ctx->pc != 0x140C54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140C54u; }
        if (ctx->pc != 0x140C54u) { return; }
    }
    ctx->pc = 0x140C54u;
label_140c54:
    // 0x140c54: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x140c54u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x140c58: 0x8e07000c  lw          $a3, 0xC($s0)
    ctx->pc = 0x140c58u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x140c5c: 0x246345c0  addiu       $v1, $v1, 0x45C0
    ctx->pc = 0x140c5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 17856));
    // 0x140c60: 0x8e060000  lw          $a2, 0x0($s0)
    ctx->pc = 0x140c60u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x140c64: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x140c64u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140c68: 0x8e040004  lw          $a0, 0x4($s0)
    ctx->pc = 0x140c68u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x140c6c: 0x8e050008  lw          $a1, 0x8($s0)
    ctx->pc = 0x140c6cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x140c70: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x140c70u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x140c74: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x140c74u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140c78: 0xac660000  sw          $a2, 0x0($v1)
    ctx->pc = 0x140c78u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 6));
    // 0x140c7c: 0xac640004  sw          $a0, 0x4($v1)
    ctx->pc = 0x140c7cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4), GPR_U32(ctx, 4));
    // 0x140c80: 0xac650008  sw          $a1, 0x8($v1)
    ctx->pc = 0x140c80u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 8), GPR_U32(ctx, 5));
    // 0x140c84: 0xac67000c  sw          $a3, 0xC($v1)
    ctx->pc = 0x140c84u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 12), GPR_U32(ctx, 7));
    // 0x140c88: 0x3e00008  jr          $ra
    ctx->pc = 0x140C88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140C8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140C88u;
            // 0x140c8c: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140C54u: goto label_140c54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140C90u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
