#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0012FC90
// Address: 0x12fc90 - 0x12fce0
void sub_0012FC90_0x12fc90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0012FC90_0x12fc90");
#endif

    ctx->pc = 0x12fc90u;

    // 0x12fc90: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x12fc90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12fc94: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x12fc94u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fc98: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x12fc98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12fc9c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x12fc9cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x12fca0: 0x80e202d6  lb          $v0, 0x2D6($a3)
    ctx->pc = 0x12fca0u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 726)));
    // 0x12fca4: 0x14430005  bne         $v0, $v1, . + 4 + (0x5 << 2)
    ctx->pc = 0x12FCA4u;
    {
        const bool branch_taken_0x12fca4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x12FCA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12FCA4u;
            // 0x12fca8: 0x24e402d7  addiu       $a0, $a3, 0x2D7 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), 727));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12fca4) {
            ctx->pc = 0x12FCBCu;
            goto label_12fcbc;
        }
    }
    ctx->pc = 0x12FCACu;
    // 0x12fcac: 0x8ce20048  lw          $v0, 0x48($a3)
    ctx->pc = 0x12fcacu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 72)));
    // 0x12fcb0: 0xa0e002d6  sb          $zero, 0x2D6($a3)
    ctx->pc = 0x12fcb0u;
    WRITE8(ADD32(GPR_U32(ctx, 7), 726), (uint8_t)GPR_U32(ctx, 0));
    // 0x12fcb4: 0x24420024  addiu       $v0, $v0, 0x24
    ctx->pc = 0x12fcb4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 36));
    // 0x12fcb8: 0xace20048  sw          $v0, 0x48($a3)
    ctx->pc = 0x12fcb8u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 72), GPR_U32(ctx, 2));
label_12fcbc:
    // 0x12fcbc: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x12fcbcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12fcc0: 0x2402ff80  addiu       $v0, $zero, -0x80
    ctx->pc = 0x12fcc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967168));
    // 0x12fcc4: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x12fcc4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12fcc8: 0x24060010  addiu       $a2, $zero, 0x10
    ctx->pc = 0x12fcc8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x12fccc: 0xa4e002e8  sh          $zero, 0x2E8($a3)
    ctx->pc = 0x12fcccu;
    WRITE16(ADD32(GPR_U32(ctx, 7), 744), (uint16_t)GPR_U32(ctx, 0));
    // 0x12fcd0: 0xa4e202ec  sh          $v0, 0x2EC($a3)
    ctx->pc = 0x12fcd0u;
    WRITE16(ADD32(GPR_U32(ctx, 7), 748), (uint16_t)GPR_U32(ctx, 2));
    // 0x12fcd4: 0xa4e202ea  sh          $v0, 0x2EA($a3)
    ctx->pc = 0x12fcd4u;
    WRITE16(ADD32(GPR_U32(ctx, 7), 746), (uint16_t)GPR_U32(ctx, 2));
    // 0x12fcd8: 0x8041f1a  j           func_107C68
    ctx->pc = 0x12FCD8u;
    ctx->pc = 0x12FCDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12FCD8u;
            // 0x12fcdc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        targetFn(rdram, ctx, runtime); return;
    } else {
        sub_00107C68_0x107c68(rdram, ctx, runtime); return;
    }
    ctx->pc = 0x12FCE0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
