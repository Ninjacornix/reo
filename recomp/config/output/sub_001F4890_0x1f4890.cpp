#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F4890
// Address: 0x1f4890 - 0x1f4910
void sub_001F4890_0x1f4890(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F4890_0x1f4890");
#endif

    switch (ctx->pc) {
        case 0x1f48b8u: goto label_1f48b8;
        default: break;
    }

    ctx->pc = 0x1f4890u;

    // 0x1f4890: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f4890u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f4894: 0x24060004  addiu       $a2, $zero, 0x4
    ctx->pc = 0x1f4894u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1f4898: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f4898u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f489c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f489cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f48a0: 0x94830034  lhu         $v1, 0x34($a0)
    ctx->pc = 0x1f48a0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 52)));
    // 0x1f48a4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1f48a4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f48a8: 0x8c820028  lw          $v0, 0x28($a0)
    ctx->pc = 0x1f48a8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x1f48ac: 0x432821  addu        $a1, $v0, $v1
    ctx->pc = 0x1f48acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1f48b0: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F48B0u;
    SET_GPR_U32(ctx, 31, 0x1F48B8u);
    ctx->pc = 0x1F48B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F48B0u;
            // 0x1f48b4: 0x27a4002c  addiu       $a0, $sp, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F48B8u; }
        if (ctx->pc != 0x1F48B8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F48B8u; }
        if (ctx->pc != 0x1F48B8u) { return; }
    }
    ctx->pc = 0x1F48B8u;
label_1f48b8:
    // 0x1f48b8: 0x96060034  lhu         $a2, 0x34($s0)
    ctx->pc = 0x1f48b8u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x1f48bc: 0x3c0300ff  lui         $v1, 0xFF
    ctx->pc = 0x1f48bcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)255 << 16));
    // 0x1f48c0: 0x8fa7002c  lw          $a3, 0x2C($sp)
    ctx->pc = 0x1f48c0u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1f48c4: 0x3c02ff00  lui         $v0, 0xFF00
    ctx->pc = 0x1f48c4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)65280 << 16));
    // 0x1f48c8: 0x24c60004  addiu       $a2, $a2, 0x4
    ctx->pc = 0x1f48c8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4));
    // 0x1f48cc: 0xa6060034  sh          $a2, 0x34($s0)
    ctx->pc = 0x1f48ccu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 52), (uint16_t)GPR_U32(ctx, 6));
    // 0x1f48d0: 0x72e02  srl         $a1, $a3, 24
    ctx->pc = 0x1f48d0u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 7), 24));
    // 0x1f48d4: 0x72202  srl         $a0, $a3, 8
    ctx->pc = 0x1f48d4u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 7), 8));
    // 0x1f48d8: 0x30a500ff  andi        $a1, $a1, 0xFF
    ctx->pc = 0x1f48d8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)255);
    // 0x1f48dc: 0x3084ff00  andi        $a0, $a0, 0xFF00
    ctx->pc = 0x1f48dcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)65280);
    // 0x1f48e0: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f48e0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f48e4: 0xa42825  or          $a1, $a1, $a0
    ctx->pc = 0x1f48e4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1f48e8: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f48e8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f48ec: 0x72200  sll         $a0, $a3, 8
    ctx->pc = 0x1f48ecu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 7), 8));
    // 0x1f48f0: 0x832024  and         $a0, $a0, $v1
    ctx->pc = 0x1f48f0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & GPR_U64(ctx, 3));
    // 0x1f48f4: 0x71e00  sll         $v1, $a3, 24
    ctx->pc = 0x1f48f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 24));
    // 0x1f48f8: 0x852025  or          $a0, $a0, $a1
    ctx->pc = 0x1f48f8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x1f48fc: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x1f48fcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x1f4900: 0x441025  or          $v0, $v0, $a0
    ctx->pc = 0x1f4900u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 4));
    // 0x1f4904: 0x3e00008  jr          $ra
    ctx->pc = 0x1F4904u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F4908u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4904u;
            // 0x1f4908: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F48B8u: goto label_1f48b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F490Cu;
    // 0x1f490c: 0x0  nop
    ctx->pc = 0x1f490cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
