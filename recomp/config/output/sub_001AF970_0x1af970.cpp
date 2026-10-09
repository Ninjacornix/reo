#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001AF970
// Address: 0x1af970 - 0x1af9c0
void sub_001AF970_0x1af970(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001AF970_0x1af970");
#endif

    ctx->pc = 0x1af970u;

    // 0x1af970: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1af970u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1af974: 0x3c05002c  lui         $a1, 0x2C
    ctx->pc = 0x1af974u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)44 << 16));
    // 0x1af978: 0x8c238e4c  lw          $v1, -0x71B4($at)
    ctx->pc = 0x1af978u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294938188)));
    // 0x1af97c: 0x24a58e40  addiu       $a1, $a1, -0x71C0
    ctx->pc = 0x1af97cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294938176));
    // 0x1af980: 0x64182b  sltu        $v1, $v1, $a0
    ctx->pc = 0x1af980u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x1af984: 0x14600009  bnez        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1AF984u;
    {
        const bool branch_taken_0x1af984 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1AF988u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1AF984u;
            // 0x1af988: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1af984) {
            ctx->pc = 0x1AF9ACu;
            goto label_1af9ac;
        }
    }
    ctx->pc = 0x1AF98Cu;
    // 0x1af98c: 0x8ca20000  lw          $v0, 0x0($a1)
    ctx->pc = 0x1af98cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1af990: 0x8ca30008  lw          $v1, 0x8($a1)
    ctx->pc = 0x1af990u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 8)));
    // 0x1af994: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1af994u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1af998: 0x641821  addu        $v1, $v1, $a0
    ctx->pc = 0x1af998u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1af99c: 0xaca30008  sw          $v1, 0x8($a1)
    ctx->pc = 0x1af99cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 3));
    // 0x1af9a0: 0x8ca3000c  lw          $v1, 0xC($a1)
    ctx->pc = 0x1af9a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 5), 12)));
    // 0x1af9a4: 0x641823  subu        $v1, $v1, $a0
    ctx->pc = 0x1af9a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1af9a8: 0xaca3000c  sw          $v1, 0xC($a1)
    ctx->pc = 0x1af9a8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 3));
label_1af9ac:
    // 0x1af9ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1AF9ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1AF9ACu: goto label_1af9ac;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1AF9B4u;
    // 0x1af9b4: 0x0  nop
    ctx->pc = 0x1af9b4u;
    // NOP
    // 0x1af9b8: 0x0  nop
    ctx->pc = 0x1af9b8u;
    // NOP
    // 0x1af9bc: 0x0  nop
    ctx->pc = 0x1af9bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
