#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00140B48
// Address: 0x140b48 - 0x140b98
void sub_00140B48_0x140b48(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00140B48_0x140b48");
#endif

    switch (ctx->pc) {
        case 0x140b84u: goto label_140b84;
        default: break;
    }

    ctx->pc = 0x140b48u;

    // 0x140b48: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x140b48u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x140b4c: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x140b4cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x140b50: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x140b50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x140b54: 0x3c100026  lui         $s0, 0x26
    ctx->pc = 0x140b54u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)38 << 16));
    // 0x140b58: 0x24424600  addiu       $v0, $v0, 0x4600
    ctx->pc = 0x140b58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 17920));
    // 0x140b5c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x140b5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x140b60: 0x26104700  addiu       $s0, $s0, 0x4700
    ctx->pc = 0x140b60u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 18176));
    // 0x140b64: 0xac440000  sw          $a0, 0x0($v0)
    ctx->pc = 0x140b64u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x140b68: 0xac450004  sw          $a1, 0x4($v0)
    ctx->pc = 0x140b68u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 5));
    // 0x140b6c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x140b6cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140b70: 0x200382d  daddu       $a3, $s0, $zero
    ctx->pc = 0x140b70u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x140b74: 0x24040021  addiu       $a0, $zero, 0x21
    ctx->pc = 0x140b74u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 33));
    // 0x140b78: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x140b78u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x140b7c: 0xc04e518  jal         func_139460
    ctx->pc = 0x140B7Cu;
    SET_GPR_U32(ctx, 31, 0x140B84u);
    ctx->pc = 0x140B80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x140B7Cu;
            // 0x140b80: 0x24080001  addiu       $t0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
    ctx->pc = 0x139460u;
    if (runtime->hasFunction(0x139460u)) {
        auto targetFn = runtime->lookupFunction(0x139460u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140B84u; }
        if (ctx->pc != 0x140B84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00139460_0x139460(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x140B84u; }
        if (ctx->pc != 0x140B84u) { return; }
    }
    ctx->pc = 0x140B84u;
label_140b84:
    // 0x140b84: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x140b84u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x140b88: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x140b88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x140b8c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x140b8cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x140b90: 0x3e00008  jr          $ra
    ctx->pc = 0x140B90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x140B94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x140B90u;
            // 0x140b94: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x140B84u: goto label_140b84;
            default: break;
        }
        return;
    }
    ctx->pc = 0x140B98u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
