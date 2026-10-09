#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00132788
// Address: 0x132788 - 0x1327b8
void sub_00132788_0x132788(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00132788_0x132788");
#endif

    switch (ctx->pc) {
        case 0x1327a0u: goto label_1327a0;
        default: break;
    }

    ctx->pc = 0x132788u;

    // 0x132788: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x132788u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13278c: 0x14800006  bnez        $a0, . + 4 + (0x6 << 2)
    ctx->pc = 0x13278Cu;
    {
        const bool branch_taken_0x13278c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x132790u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13278Cu;
            // 0x132790: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x13278c) {
            ctx->pc = 0x1327A8u;
            goto label_1327a8;
        }
    }
    ctx->pc = 0x132794u;
    // 0x132794: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x132794u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x132798: 0xc04a034  jal         func_1280D0
    ctx->pc = 0x132798u;
    SET_GPR_U32(ctx, 31, 0x1327A0u);
    ctx->pc = 0x13279Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x132798u;
            // 0x13279c: 0x2484b148  addiu       $a0, $a0, -0x4EB8 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294947144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1280D0u;
    if (runtime->hasFunction(0x1280D0u)) {
        auto targetFn = runtime->lookupFunction(0x1280D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1327A0u; }
        if (ctx->pc != 0x1327A0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1327A0u; }
        if (ctx->pc != 0x1327A0u) { return; }
    }
    ctx->pc = 0x1327A0u;
label_1327a0:
    // 0x1327a0: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1327A0u;
    {
        const bool branch_taken_0x1327a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1327A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1327A0u;
            // 0x1327a4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1327a0) {
            ctx->pc = 0x1327ACu;
            goto label_1327ac;
        }
    }
    ctx->pc = 0x1327A8u;
label_1327a8:
    // 0x1327a8: 0x84820046  lh          $v0, 0x46($a0)
    ctx->pc = 0x1327a8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 70)));
label_1327ac:
    // 0x1327ac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1327acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1327b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1327B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1327B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1327B0u;
            // 0x1327b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1327A0u: goto label_1327a0;
            case 0x1327A8u: goto label_1327a8;
            case 0x1327ACu: goto label_1327ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1327B8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
