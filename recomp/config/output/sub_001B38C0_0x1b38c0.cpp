#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B38C0
// Address: 0x1b38c0 - 0x1b3920
void sub_001B38C0_0x1b38c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B38C0_0x1b38c0");
#endif

    ctx->pc = 0x1b38c0u;

    // 0x1b38c0: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1b38c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1b38c4: 0x94234414  lhu         $v1, 0x4414($at)
    ctx->pc = 0x1b38c4u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17428)));
    // 0x1b38c8: 0x10600012  beqz        $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x1B38C8u;
    {
        const bool branch_taken_0x1b38c8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B38CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B38C8u;
            // 0x1b38cc: 0x42e02  srl         $a1, $a0, 24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 4), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b38c8) {
            ctx->pc = 0x1B3914u;
            goto label_1b3914;
        }
    }
    ctx->pc = 0x1B38D0u;
    // 0x1b38d0: 0x308300ff  andi        $v1, $a0, 0xFF
    ctx->pc = 0x1b38d0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
    // 0x1b38d4: 0x30a50080  andi        $a1, $a1, 0x80
    ctx->pc = 0x1b38d4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)128);
    // 0x1b38d8: 0x31842  srl         $v1, $v1, 1
    ctx->pc = 0x1b38d8u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 1));
    // 0x1b38dc: 0x52e00  sll         $a1, $a1, 24
    ctx->pc = 0x1b38dcu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 24));
    // 0x1b38e0: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x1b38e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x1b38e4: 0xa33025  or          $a2, $a1, $v1
    ctx->pc = 0x1b38e4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x1b38e8: 0x3c01002c  lui         $at, 0x2C
    ctx->pc = 0x1b38e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)44 << 16));
    // 0x1b38ec: 0x41a02  srl         $v1, $a0, 8
    ctx->pc = 0x1b38ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 4), 8));
    // 0x1b38f0: 0x306500ff  andi        $a1, $v1, 0xFF
    ctx->pc = 0x1b38f0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1b38f4: 0x41c02  srl         $v1, $a0, 16
    ctx->pc = 0x1b38f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 4), 16));
    // 0x1b38f8: 0x52042  srl         $a0, $a1, 1
    ctx->pc = 0x1b38f8u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 5), 1));
    // 0x1b38fc: 0x306300ff  andi        $v1, $v1, 0xFF
    ctx->pc = 0x1b38fcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)255);
    // 0x1b3900: 0x42200  sll         $a0, $a0, 8
    ctx->pc = 0x1b3900u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 8));
    // 0x1b3904: 0x31842  srl         $v1, $v1, 1
    ctx->pc = 0x1b3904u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 3), 1));
    // 0x1b3908: 0x862025  or          $a0, $a0, $a2
    ctx->pc = 0x1b3908u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 6));
    // 0x1b390c: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x1b390cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x1b3910: 0xac23a9f4  sw          $v1, -0x560C($at)
    ctx->pc = 0x1b3910u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294945268), GPR_U32(ctx, 3));
label_1b3914:
    // 0x1b3914: 0x3e00008  jr          $ra
    ctx->pc = 0x1B3914u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B3914u: goto label_1b3914;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B391Cu;
    // 0x1b391c: 0x0  nop
    ctx->pc = 0x1b391cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
