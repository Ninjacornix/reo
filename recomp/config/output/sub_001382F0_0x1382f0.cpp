#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001382F0
// Address: 0x1382f0 - 0x138328
void sub_001382F0_0x1382f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001382F0_0x1382f0");
#endif

    ctx->pc = 0x1382f0u;

    // 0x1382f0: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x1382f0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x1382f4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1382f4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1382f8: 0x8c43bbfc  lw          $v1, -0x4404($v0)
    ctx->pc = 0x1382f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294949884)));
    // 0x1382fc: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1382fcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x138300: 0x14640005  bne         $v1, $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x138300u;
    {
        const bool branch_taken_0x138300 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 4));
        ctx->pc = 0x138304u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138300u;
            // 0x138304: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138300) {
            ctx->pc = 0x138318u;
            goto label_138318;
        }
    }
    ctx->pc = 0x138308u;
    // 0x138308: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x138308u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13830c: 0x80505cc  j           func_141730
    ctx->pc = 0x13830Cu;
    ctx->pc = 0x138310u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13830Cu;
            // 0x138310: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x141730u;
    if (runtime->hasFunction(0x141730u)) {
        auto targetFn = runtime->lookupFunction(0x141730u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00141730_0x141730(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x138314u;
    // 0x138314: 0x0  nop
    ctx->pc = 0x138314u;
    // NOP
label_138318:
    // 0x138318: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x138318u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13831c: 0x3e00008  jr          $ra
    ctx->pc = 0x13831Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138320u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13831Cu;
            // 0x138320: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138318u: goto label_138318;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138324u;
    // 0x138324: 0x0  nop
    ctx->pc = 0x138324u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
