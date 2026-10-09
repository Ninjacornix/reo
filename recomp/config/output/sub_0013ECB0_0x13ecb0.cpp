#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0013ECB0
// Address: 0x13ecb0 - 0x13ecf0
void sub_0013ECB0_0x13ecb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0013ECB0_0x13ecb0");
#endif

    switch (ctx->pc) {
        case 0x13ecd0u: goto label_13ecd0;
        default: break;
    }

    ctx->pc = 0x13ecb0u;

    // 0x13ecb0: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x13ecb0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x13ecb4: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x13ecb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x13ecb8: 0x8c820008  lw          $v0, 0x8($a0)
    ctx->pc = 0x13ecb8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x13ecbc: 0x8c440008  lw          $a0, 0x8($v0)
    ctx->pc = 0x13ecbcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x13ecc0: 0x8c830000  lw          $v1, 0x0($a0)
    ctx->pc = 0x13ecc0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13ecc4: 0x8c620024  lw          $v0, 0x24($v1)
    ctx->pc = 0x13ecc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 36)));
    // 0x13ecc8: 0x40f809  jalr        $v0
    ctx->pc = 0x13ECC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x13ECD0u);
        ctx->pc = 0x13ECCCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ECC8u;
            // 0x13eccc: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x13ECD0u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ECD0u: goto label_13ecd0;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x13ECD0u; }
            if (ctx->pc != 0x13ECD0u) { return; }
        }
        }
    }
    ctx->pc = 0x13ECD0u;
label_13ecd0:
    // 0x13ecd0: 0x24034000  addiu       $v1, $zero, 0x4000
    ctx->pc = 0x13ecd0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 16384));
    // 0x13ecd4: 0x621823  subu        $v1, $v1, $v0
    ctx->pc = 0x13ecd4u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13ecd8: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x13ecd8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13ecdc: 0x317c2  srl         $v0, $v1, 31
    ctx->pc = 0x13ecdcu;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 3), 31));
    // 0x13ece0: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x13ece0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x13ece4: 0x31043  sra         $v0, $v1, 1
    ctx->pc = 0x13ece4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 1));
    // 0x13ece8: 0x3e00008  jr          $ra
    ctx->pc = 0x13ECE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13ECECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x13ECE8u;
            // 0x13ecec: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13ECD0u: goto label_13ecd0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13ECF0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
