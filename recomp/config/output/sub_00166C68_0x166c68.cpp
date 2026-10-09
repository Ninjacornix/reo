#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00166C68
// Address: 0x166c68 - 0x166cb8
void sub_00166C68_0x166c68(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00166C68_0x166c68");
#endif

    switch (ctx->pc) {
        case 0x166ca0u: goto label_166ca0;
        default: break;
    }

    ctx->pc = 0x166c68u;

    // 0x166c68: 0x710c0  sll         $v0, $a3, 3
    ctx->pc = 0x166c68u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x166c6c: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x166c6cu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x166c70: 0x471023  subu        $v0, $v0, $a3
    ctx->pc = 0x166c70u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x166c74: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x166c74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x166c78: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x166c78u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x166c7c: 0x24050003  addiu       $a1, $zero, 0x3
    ctx->pc = 0x166c7cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x166c80: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x166c80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x166c84: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x166c84u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x166c88: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x166c88u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x166c8c: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x166c8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x166c90: 0x828021  addu        $s0, $a0, $v0
    ctx->pc = 0x166c90u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x166c94: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x166c94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166c98: 0xc059b2e  jal         func_166CB8
    ctx->pc = 0x166C98u;
    SET_GPR_U32(ctx, 31, 0x166CA0u);
    ctx->pc = 0x166C9Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166C98u;
            // 0x166c9c: 0x26100010  addiu       $s0, $s0, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166CB8u;
    if (runtime->hasFunction(0x166CB8u)) {
        auto targetFn = runtime->lookupFunction(0x166CB8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166CA0u; }
        if (ctx->pc != 0x166CA0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00166CB8_0x166cb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x166CA0u; }
        if (ctx->pc != 0x166CA0u) { return; }
    }
    ctx->pc = 0x166CA0u;
label_166ca0:
    // 0x166ca0: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x166ca0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x166ca4: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x166ca4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x166ca8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x166ca8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x166cac: 0x8059b36  j           func_166CD8
    ctx->pc = 0x166CACu;
    ctx->pc = 0x166CB0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x166CACu;
            // 0x166cb0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x166CD8u;
    if (runtime->hasFunction(0x166CD8u)) {
        auto targetFn = runtime->lookupFunction(0x166CD8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00166CD8_0x166cd8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x166CB4u;
    // 0x166cb4: 0x0  nop
    ctx->pc = 0x166cb4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
