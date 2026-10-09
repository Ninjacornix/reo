#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001420F8
// Address: 0x1420f8 - 0x142138
void sub_001420F8_0x1420f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001420F8_0x1420f8");
#endif

    switch (ctx->pc) {
        case 0x14211cu: goto label_14211c;
        default: break;
    }

    ctx->pc = 0x1420f8u;

    // 0x1420f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1420f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1420fc: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1420fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x142100: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x142100u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x142104: 0x2450a5ec  addiu       $s0, $v0, -0x5A14
    ctx->pc = 0x142104u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 2), 4294944236));
    // 0x142108: 0x8e030000  lw          $v1, 0x0($s0)
    ctx->pc = 0x142108u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x14210c: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x14210Cu;
    {
        const bool branch_taken_0x14210c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x142110u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14210Cu;
            // 0x142110: 0xffbf0008  sd          $ra, 0x8($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14210c) {
            ctx->pc = 0x14211Cu;
            goto label_14211c;
        }
    }
    ctx->pc = 0x142114u;
    // 0x142114: 0xc05081e  jal         func_142078
    ctx->pc = 0x142114u;
    SET_GPR_U32(ctx, 31, 0x14211Cu);
    ctx->pc = 0x142078u;
    if (runtime->hasFunction(0x142078u)) {
        auto targetFn = runtime->lookupFunction(0x142078u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14211Cu; }
        if (ctx->pc != 0x14211Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142078_0x142078(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14211Cu; }
        if (ctx->pc != 0x14211Cu) { return; }
    }
    ctx->pc = 0x14211Cu;
label_14211c:
    // 0x14211c: 0x8e020000  lw          $v0, 0x0($s0)
    ctx->pc = 0x14211cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x142120: 0xdfbf0008  ld          $ra, 0x8($sp)
    ctx->pc = 0x142120u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x142124: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x142124u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x142128: 0xae020000  sw          $v0, 0x0($s0)
    ctx->pc = 0x142128u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x14212c: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x14212cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x142130: 0x3e00008  jr          $ra
    ctx->pc = 0x142130u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x142134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142130u;
            // 0x142134: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14211Cu: goto label_14211c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x142138u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
