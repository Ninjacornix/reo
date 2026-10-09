#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001F47E0
// Address: 0x1f47e0 - 0x1f4830
void sub_001F47E0_0x1f47e0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001F47E0_0x1f47e0");
#endif

    switch (ctx->pc) {
        case 0x1f4808u: goto label_1f4808;
        default: break;
    }

    ctx->pc = 0x1f47e0u;

    // 0x1f47e0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1f47e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1f47e4: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1f47e4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1f47e8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1f47e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1f47ec: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1f47ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1f47f0: 0x94830034  lhu         $v1, 0x34($a0)
    ctx->pc = 0x1f47f0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 52)));
    // 0x1f47f4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1f47f4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1f47f8: 0x8c820028  lw          $v0, 0x28($a0)
    ctx->pc = 0x1f47f8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 40)));
    // 0x1f47fc: 0x432821  addu        $a1, $v0, $v1
    ctx->pc = 0x1f47fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1f4800: 0xc041eac  jal         func_107AB0
    ctx->pc = 0x1F4800u;
    SET_GPR_U32(ctx, 31, 0x1F4808u);
    ctx->pc = 0x1F4804u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4800u;
            // 0x1f4804: 0x27a4002f  addiu       $a0, $sp, 0x2F (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 47));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4808u; }
        if (ctx->pc != 0x1F4808u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1F4808u; }
        if (ctx->pc != 0x1F4808u) { return; }
    }
    ctx->pc = 0x1F4808u;
label_1f4808:
    // 0x1f4808: 0x96020034  lhu         $v0, 0x34($s0)
    ctx->pc = 0x1f4808u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x1f480c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1f480cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1f4810: 0xa6020034  sh          $v0, 0x34($s0)
    ctx->pc = 0x1f4810u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 52), (uint16_t)GPR_U32(ctx, 2));
    // 0x1f4814: 0x93a2002f  lbu         $v0, 0x2F($sp)
    ctx->pc = 0x1f4814u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 47)));
    // 0x1f4818: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1f4818u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1f481c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1f481cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1f4820: 0x3e00008  jr          $ra
    ctx->pc = 0x1F4820u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1F4824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1F4820u;
            // 0x1f4824: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1F4808u: goto label_1f4808;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1F4828u;
    // 0x1f4828: 0x0  nop
    ctx->pc = 0x1f4828u;
    // NOP
    // 0x1f482c: 0x0  nop
    ctx->pc = 0x1f482cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
