#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00138238
// Address: 0x138238 - 0x138274
void sub_00138238_0x138238(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00138238_0x138238");
#endif

    ctx->pc = 0x138238u;

    // 0x138238: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x138238u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13823c: 0x3c020022  lui         $v0, 0x22
    ctx->pc = 0x13823cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)34 << 16));
    // 0x138240: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x138240u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x138244: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x138244u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x138248: 0x14830007  bne         $a0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x138248u;
    {
        const bool branch_taken_0x138248 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 3));
        ctx->pc = 0x13824Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x138248u;
            // 0x13824c: 0xac44bbf8  sw          $a0, -0x4408($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294949880), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x138248) {
            ctx->pc = 0x138268u;
            goto label_138268;
        }
    }
    ctx->pc = 0x138250u;
    // 0x138250: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x138250u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x138254: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x138254u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138258: 0x2484c6c8  addiu       $a0, $a0, -0x3938
    ctx->pc = 0x138258u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294952648));
    // 0x13825c: 0x8045a12  j           func_116848
    ctx->pc = 0x13825Cu;
    ctx->pc = 0x138260u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x13825Cu;
            // 0x138260: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00116848_0x116848(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x138264u;
    // 0x138264: 0x0  nop
    ctx->pc = 0x138264u;
    // NOP
label_138268:
    // 0x138268: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x138268u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13826c: 0x3e00008  jr          $ra
    ctx->pc = 0x13826Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138270u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13826Cu;
            // 0x138270: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138268u: goto label_138268;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138274u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
