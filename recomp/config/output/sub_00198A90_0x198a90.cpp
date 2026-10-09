#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00198A90
// Address: 0x198a90 - 0x198ad0
void sub_00198A90_0x198a90(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00198A90_0x198a90");
#endif

    ctx->pc = 0x198a90u;

    // 0x198a90: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x198a90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x198a94: 0x8423fd60  lh          $v1, -0x2A0($at)
    ctx->pc = 0x198a94u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294966624)));
    // 0x198a98: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x198a98u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x198a9c: 0x831823  subu        $v1, $a0, $v1
    ctx->pc = 0x198a9cu;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x198aa0: 0x8c22f9b4  lw          $v0, -0x64C($at)
    ctx->pc = 0x198aa0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965684)));
    // 0x198aa4: 0x3243c  dsll32      $a0, $v1, 16
    ctx->pc = 0x198aa4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << (32 + 16));
    // 0x198aa8: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x198AA8u;
    {
        const bool branch_taken_0x198aa8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x198AACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198AA8u;
            // 0x198aac: 0x4243f  dsra32      $a0, $a0, 16 (Delay Slot)
        SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x198aa8) {
            ctx->pc = 0x198ABCu;
            goto label_198abc;
        }
    }
    ctx->pc = 0x198AB0u;
    // 0x198ab0: 0x41043  sra         $v0, $a0, 1
    ctx->pc = 0x198ab0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 4), 1));
    // 0x198ab4: 0x2243c  dsll32      $a0, $v0, 16
    ctx->pc = 0x198ab4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 16));
    // 0x198ab8: 0x4243f  dsra32      $a0, $a0, 16
    ctx->pc = 0x198ab8u;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 16));
label_198abc:
    // 0x198abc: 0x3e00008  jr          $ra
    ctx->pc = 0x198ABCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x198AC0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x198ABCu;
            // 0x198ac0: 0x80102d  daddu       $v0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x198ABCu: goto label_198abc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x198AC4u;
    // 0x198ac4: 0x0  nop
    ctx->pc = 0x198ac4u;
    // NOP
    // 0x198ac8: 0x0  nop
    ctx->pc = 0x198ac8u;
    // NOP
    // 0x198acc: 0x0  nop
    ctx->pc = 0x198accu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
