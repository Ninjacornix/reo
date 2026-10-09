#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001305C0
// Address: 0x1305c0 - 0x130608
void sub_001305C0_0x1305c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001305C0_0x1305c0");
#endif

    ctx->pc = 0x1305c0u;

    // 0x1305c0: 0x80382d  daddu       $a3, $a0, $zero
    ctx->pc = 0x1305c0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1305c4: 0x512c0  sll         $v0, $a1, 11
    ctx->pc = 0x1305c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 11));
    // 0x1305c8: 0x8ce60010  lw          $a2, 0x10($a3)
    ctx->pc = 0x1305c8u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x1305cc: 0xace50054  sw          $a1, 0x54($a3)
    ctx->pc = 0x1305ccu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 84), GPR_U32(ctx, 5));
    // 0x1305d0: 0x24c407ff  addiu       $a0, $a2, 0x7FF
    ctx->pc = 0x1305d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), 2047));
    // 0x1305d4: 0x28c30000  slti        $v1, $a2, 0x0
    ctx->pc = 0x1305d4u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1305d8: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x1305d8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1305dc: 0xc2102a  slt         $v0, $a2, $v0
    ctx->pc = 0x1305dcu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1305e0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1305E0u;
    {
        const bool branch_taken_0x1305e0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1305E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1305E0u;
            // 0x1305e4: 0x83280b  movn        $a1, $a0, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1305e0) {
            ctx->pc = 0x130600u;
            goto label_130600;
        }
    }
    ctx->pc = 0x1305E8u;
    // 0x1305e8: 0x51ac3  sra         $v1, $a1, 11
    ctx->pc = 0x1305e8u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 5), 11));
    // 0x1305ec: 0x312c0  sll         $v0, $v1, 11
    ctx->pc = 0x1305ecu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 11));
    // 0x1305f0: 0xc21023  subu        $v0, $a2, $v0
    ctx->pc = 0x1305f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1305f4: 0x2102a  slt         $v0, $zero, $v0
    ctx->pc = 0x1305f4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1305f8: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x1305f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1305fc: 0xace30054  sw          $v1, 0x54($a3)
    ctx->pc = 0x1305fcu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 84), GPR_U32(ctx, 3));
label_130600:
    // 0x130600: 0x3e00008  jr          $ra
    ctx->pc = 0x130600u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x130600u;
            // 0x130604: 0x8ce20054  lw          $v0, 0x54($a3) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 7), 84)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130600u: goto label_130600;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130608u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
