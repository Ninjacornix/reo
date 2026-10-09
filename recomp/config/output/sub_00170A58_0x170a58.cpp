#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00170A58
// Address: 0x170a58 - 0x170ac0
void sub_00170A58_0x170a58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00170A58_0x170a58");
#endif

    switch (ctx->pc) {
        case 0x170a6cu: goto label_170a6c;
        default: break;
    }

    ctx->pc = 0x170a58u;

    // 0x170a58: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x170a58u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x170a5c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x170a5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x170a60: 0xffbf0008  sd          $ra, 0x8($sp)
    ctx->pc = 0x170a60u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x170a64: 0xc047598  jal         func_11D660
    ctx->pc = 0x170A64u;
    SET_GPR_U32(ctx, 31, 0x170A6Cu);
    ctx->pc = 0x170A68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170A64u;
            // 0x170a68: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D660u;
    if (runtime->hasFunction(0x11D660u)) {
        auto targetFn = runtime->lookupFunction(0x11D660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170A6Cu; }
        if (ctx->pc != 0x170A6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170A6Cu; }
        if (ctx->pc != 0x170A6Cu) { return; }
    }
    ctx->pc = 0x170A6Cu;
label_170a6c:
    // 0x170a6c: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x170a6cu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x170a70: 0x3c070001  lui         $a3, 0x1
    ctx->pc = 0x170a70u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)1 << 16));
    // 0x170a74: 0x34a5f520  ori         $a1, $a1, 0xF520
    ctx->pc = 0x170a74u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)62752);
    // 0x170a78: 0x3c061000  lui         $a2, 0x1000
    ctx->pc = 0x170a78u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)4096 << 16));
    // 0x170a7c: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x170a7cu;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0))); // MMIO: 0x10000000
    // 0x170a80: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x170a80u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x170a84: 0x34c6f590  ori         $a2, $a2, 0xF590
    ctx->pc = 0x170a84u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | (uint64_t)(uint16_t)62864);
    // 0x170a88: 0x3484b400  ori         $a0, $a0, 0xB400
    ctx->pc = 0x170a88u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)46080);
    // 0x170a8c: 0x471025  or          $v0, $v0, $a3
    ctx->pc = 0x170a8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 7));
    // 0x170a90: 0x3c03fffe  lui         $v1, 0xFFFE
    ctx->pc = 0x170a90u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65534 << 16));
    // 0x170a94: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x170a94u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x170a98: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x170a98u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x170a9c: 0xac900000  sw          $s0, 0x0($a0)
    ctx->pc = 0x170a9cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 16));
    // 0x170aa0: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x170aa0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x170aa4: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x170aa4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x170aa8: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x170aa8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x170aac: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x170aacu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x170ab0: 0xacc20000  sw          $v0, 0x0($a2)
    ctx->pc = 0x170ab0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x170ab4: 0x80475ae  j           func_11D6B8
    ctx->pc = 0x170AB4u;
    ctx->pc = 0x170AB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x170AB4u;
            // 0x170ab8: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x11D6B8u;
    if (runtime->hasFunction(0x11D6B8u)) {
        auto targetFn = runtime->lookupFunction(0x11D6B8u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x170ABCu;
    // 0x170abc: 0x0  nop
    ctx->pc = 0x170abcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
