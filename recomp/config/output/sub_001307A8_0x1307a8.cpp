#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001307A8
// Address: 0x1307a8 - 0x1307e8
void sub_001307A8_0x1307a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001307A8_0x1307a8");
#endif

    ctx->pc = 0x1307a8u;

    // 0x1307a8: 0x4a00003  bltz        $a1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1307A8u;
    {
        const bool branch_taken_0x1307a8 = (GPR_S64(ctx, 5) < 0);
        ctx->pc = 0x1307ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1307A8u;
            // 0x1307ac: 0x80302d  daddu       $a2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1307a8) {
            ctx->pc = 0x1307B8u;
            goto label_1307b8;
        }
    }
    ctx->pc = 0x1307B0u;
    // 0x1307b0: 0x3e00008  jr          $ra
    ctx->pc = 0x1307B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1307B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1307B0u;
            // 0x1307b4: 0xacc5002c  sw          $a1, 0x2C($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 44), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1307B8u: goto label_1307b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1307B8u;
label_1307b8:
    // 0x1307b8: 0x8cc30010  lw          $v1, 0x10($a2)
    ctx->pc = 0x1307b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 16)));
    // 0x1307bc: 0x28640000  slti        $a0, $v1, 0x0
    ctx->pc = 0x1307bcu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1307c0: 0x246507ff  addiu       $a1, $v1, 0x7FF
    ctx->pc = 0x1307c0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 2047));
    // 0x1307c4: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1307c4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1307c8: 0xa4100b  movn        $v0, $a1, $a0
    ctx->pc = 0x1307c8u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
    // 0x1307cc: 0x212c3  sra         $v0, $v0, 11
    ctx->pc = 0x1307ccu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 11));
    // 0x1307d0: 0x222c0  sll         $a0, $v0, 11
    ctx->pc = 0x1307d0u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 2), 11));
    // 0x1307d4: 0x641823  subu        $v1, $v1, $a0
    ctx->pc = 0x1307d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1307d8: 0x3182a  slt         $v1, $zero, $v1
    ctx->pc = 0x1307d8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1307dc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1307dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1307e0: 0x3e00008  jr          $ra
    ctx->pc = 0x1307E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1307E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1307E0u;
            // 0x1307e4: 0xacc2002c  sw          $v0, 0x2C($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 44), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1307B8u: goto label_1307b8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1307E8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
