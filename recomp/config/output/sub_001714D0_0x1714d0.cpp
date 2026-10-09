#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001714D0
// Address: 0x1714d0 - 0x171520
void sub_001714D0_0x1714d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001714D0_0x1714d0");
#endif

    switch (ctx->pc) {
        case 0x1714e8u: goto label_1714e8;
        default: break;
    }

    ctx->pc = 0x1714d0u;

    // 0x1714d0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1714d0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1714d4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1714d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1714d8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1714d8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1714dc: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x1714dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x1714e0: 0xc045198  jal         func_114660
    ctx->pc = 0x1714E0u;
    SET_GPR_U32(ctx, 31, 0x1714E8u);
    ctx->pc = 0x1714E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1714E0u;
            // 0x1714e4: 0x8e040040  lw          $a0, 0x40($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114660u;
    if (runtime->hasFunction(0x114660u)) {
        auto targetFn = runtime->lookupFunction(0x114660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1714E8u; }
        if (ctx->pc != 0x1714E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1714E8u; }
        if (ctx->pc != 0x1714E8u) { return; }
    }
    ctx->pc = 0x1714E8u;
label_1714e8:
    // 0x1714e8: 0x8e030014  lw          $v1, 0x14($s0)
    ctx->pc = 0x1714e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 20)));
    // 0x1714ec: 0x8e040040  lw          $a0, 0x40($s0)
    ctx->pc = 0x1714ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x1714f0: 0x24620803  addiu       $v0, $v1, 0x803
    ctx->pc = 0x1714f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 2051));
    // 0x1714f4: 0x24631002  addiu       $v1, $v1, 0x1002
    ctx->pc = 0x1714f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4098));
    // 0x1714f8: 0x28450000  slti        $a1, $v0, 0x0
    ctx->pc = 0x1714f8u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1714fc: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x1714fcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x171500: 0x65100b  movn        $v0, $v1, $a1
    ctx->pc = 0x171500u;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
    // 0x171504: 0x212c3  sra         $v0, $v0, 11
    ctx->pc = 0x171504u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 11));
    // 0x171508: 0x212c0  sll         $v0, $v0, 11
    ctx->pc = 0x171508u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 11));
    // 0x17150c: 0xae020014  sw          $v0, 0x14($s0)
    ctx->pc = 0x17150cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 20), GPR_U32(ctx, 2));
    // 0x171510: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x171510u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x171514: 0x8045190  j           func_114640
    ctx->pc = 0x171514u;
    ctx->pc = 0x171518u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x171514u;
            // 0x171518: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x114640u;
    if (runtime->hasFunction(0x114640u)) {
        auto targetFn = runtime->lookupFunction(0x114640u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00114640_0x114640(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x17151Cu;
    // 0x17151c: 0x0  nop
    ctx->pc = 0x17151cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
