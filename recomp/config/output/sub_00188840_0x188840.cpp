#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00188840
// Address: 0x188840 - 0x188880
void sub_00188840_0x188840(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00188840_0x188840");
#endif

    switch (ctx->pc) {
        case 0x188868u: goto label_188868;
        default: break;
    }

    ctx->pc = 0x188840u;

    // 0x188840: 0x410c0  sll         $v0, $a0, 3
    ctx->pc = 0x188840u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x188844: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x188844u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x188848: 0x441023  subu        $v0, $v0, $a0
    ctx->pc = 0x188848u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x18884c: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x18884cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x188850: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x188850u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x188854: 0x3c040029  lui         $a0, 0x29
    ctx->pc = 0x188854u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)41 << 16));
    // 0x188858: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x188858u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x18885c: 0x8c84b8cc  lw          $a0, -0x4734($a0)
    ctx->pc = 0x18885cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 4294949068)));
    // 0x188860: 0xc0623b6  jal         func_188ED8
    ctx->pc = 0x188860u;
    SET_GPR_U32(ctx, 31, 0x188868u);
    ctx->pc = 0x188ED8u;
    if (runtime->hasFunction(0x188ED8u)) {
        auto targetFn = runtime->lookupFunction(0x188ED8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188868u; }
        if (ctx->pc != 0x188868u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00188ED8_0x188ed8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188868u; }
        if (ctx->pc != 0x188868u) { return; }
    }
    ctx->pc = 0x188868u;
label_188868:
    // 0x188868: 0x38420003  xori        $v0, $v0, 0x3
    ctx->pc = 0x188868u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)3);
    // 0x18886c: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x18886cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x188870: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x188870u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x188874: 0x3e00008  jr          $ra
    ctx->pc = 0x188874u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x188878u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x188874u;
            // 0x188878: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x188868u: goto label_188868;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18887Cu;
    // 0x18887c: 0x0  nop
    ctx->pc = 0x18887cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
