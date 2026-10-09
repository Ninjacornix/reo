#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010B7B8
// Address: 0x10b7b8 - 0x10b808
void sub_0010B7B8_0x10b7b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010B7B8_0x10b7b8");
#endif

    switch (ctx->pc) {
        case 0x10b7d0u: goto label_10b7d0;
        default: break;
    }

    ctx->pc = 0x10b7b8u;

    // 0x10b7b8: 0x90830000  lbu         $v1, 0x0($a0)
    ctx->pc = 0x10b7b8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10b7bc: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x10b7bcu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x10b7c0: 0x52e03  sra         $a1, $a1, 24
    ctx->pc = 0x10b7c0u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 24));
    // 0x10b7c4: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x10b7c4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10b7c8: 0x10600009  beqz        $v1, . + 4 + (0x9 << 2)
    ctx->pc = 0x10B7C8u;
    {
        const bool branch_taken_0x10b7c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10B7CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B7C8u;
            // 0x10b7cc: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b7c8) {
            ctx->pc = 0x10B7F0u;
            goto label_10b7f0;
        }
    }
    ctx->pc = 0x10B7D0u;
label_10b7d0:
    // 0x10b7d0: 0x21600  sll         $v0, $v0, 24
    ctx->pc = 0x10b7d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x10b7d4: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x10b7d4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x10b7d8: 0x451026  xor         $v0, $v0, $a1
    ctx->pc = 0x10b7d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ GPR_U64(ctx, 5));
    // 0x10b7dc: 0x82300a  movz        $a2, $a0, $v0
    ctx->pc = 0x10b7dcu;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 4));
    // 0x10b7e0: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x10b7e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x10b7e4: 0x90830000  lbu         $v1, 0x0($a0)
    ctx->pc = 0x10b7e4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10b7e8: 0x1460fff9  bnez        $v1, . + 4 + (-0x7 << 2)
    ctx->pc = 0x10B7E8u;
    {
        const bool branch_taken_0x10b7e8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x10B7ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B7E8u;
            // 0x10b7ec: 0x60102d  daddu       $v0, $v1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10b7e8) {
            ctx->pc = 0x10B7D0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10b7d0;
        }
    }
    ctx->pc = 0x10B7F0u;
label_10b7f0:
    // 0x10b7f0: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x10b7f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x10b7f4: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x10b7f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10b7f8: 0x31e03  sra         $v1, $v1, 24
    ctx->pc = 0x10b7f8u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 24));
    // 0x10b7fc: 0x651826  xor         $v1, $v1, $a1
    ctx->pc = 0x10b7fcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 5));
    // 0x10b800: 0x3e00008  jr          $ra
    ctx->pc = 0x10B800u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10B804u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10B800u;
            // 0x10b804: 0xc3100b  movn        $v0, $a2, $v1 (Delay Slot)
        if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 6));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10B7D0u: goto label_10b7d0;
            case 0x10B7F0u: goto label_10b7f0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10B808u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
