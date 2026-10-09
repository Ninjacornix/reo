#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0020A660
// Address: 0x20a660 - 0x20a720
void sub_0020A660_0x20a660(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0020A660_0x20a660");
#endif

    switch (ctx->pc) {
        case 0x20a688u: goto label_20a688;
        default: break;
    }

    ctx->pc = 0x20a660u;

    // 0x20a660: 0x3c06bc00  lui         $a2, 0xBC00
    ctx->pc = 0x20a660u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)48128 << 16));
    // 0x20a664: 0x8cc603c0  lw          $a2, 0x3C0($a2)
    ctx->pc = 0x20a664u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 960)));
    // 0x20a668: 0x10c00011  beqz        $a2, . + 4 + (0x11 << 2)
    ctx->pc = 0x20A668u;
    {
        const bool branch_taken_0x20a668 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x20A66Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A668u;
            // 0x20a66c: 0x3c088007  lui         $t0, 0x8007 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)32775 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20a668) {
            ctx->pc = 0x20A6B0u;
            goto label_20a6b0;
        }
    }
    ctx->pc = 0x20A670u;
    // 0x20a670: 0x3c02bc00  lui         $v0, 0xBC00
    ctx->pc = 0x20a670u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)48128 << 16));
    // 0x20a674: 0xc23021  addu        $a2, $a2, $v0
    ctx->pc = 0x20a674u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x20a678: 0x25074700  addiu       $a3, $t0, 0x4700
    ctx->pc = 0x20a678u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 8), 18176));
    // 0x20a67c: 0x24c6000f  addiu       $a2, $a2, 0xF
    ctx->pc = 0x20a67cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 15));
    // 0x20a680: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x20a680u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x20a684: 0x0  nop
    ctx->pc = 0x20a684u;
    // NOP
label_20a688:
    // 0x20a688: 0xc51021  addu        $v0, $a2, $a1
    ctx->pc = 0x20a688u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
    // 0x20a68c: 0xe52021  addu        $a0, $a3, $a1
    ctx->pc = 0x20a68cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x20a690: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x20a690u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x20a694: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x20a694u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
    // 0x20a698: 0x28a20026  slti        $v0, $a1, 0x26
    ctx->pc = 0x20a698u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)38) ? 1 : 0);
    // 0x20a69c: 0xa0830000  sb          $v1, 0x0($a0)
    ctx->pc = 0x20a69cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x20a6a0: 0x1440fff9  bnez        $v0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x20A6A0u;
    {
        const bool branch_taken_0x20a6a0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x20a6a0) {
            ctx->pc = 0x20A688u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_20a688;
        }
    }
    ctx->pc = 0x20A6A8u;
    // 0x20a6a8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x20A6A8u;
    {
        const bool branch_taken_0x20a6a8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x20A6ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x20A6A8u;
            // 0x20a6ac: 0xdd034700  ld          $v1, 0x4700($t0) (Delay Slot)
        SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 8), 18176)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x20a6a8) {
            ctx->pc = 0x20A6B4u;
            goto label_20a6b4;
        }
    }
    ctx->pc = 0x20A6B0u;
label_20a6b0:
    // 0x20a6b0: 0xdd034700  ld          $v1, 0x4700($t0)
    ctx->pc = 0x20a6b0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 8), 18176)));
label_20a6b4:
    // 0x20a6b4: 0x316b8  dsll        $v0, $v1, 26
    ctx->pc = 0x20a6b4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) << 26);
    // 0x20a6b8: 0x2103f  dsra32      $v0, $v0, 0
    ctx->pc = 0x20a6b8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x20a6bc: 0x30420007  andi        $v0, $v0, 0x7
    ctx->pc = 0x20a6bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)7);
    // 0x20a6c0: 0x14400015  bnez        $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x20A6C0u;
    {
        const bool branch_taken_0x20a6c0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x20a6c0) {
            ctx->pc = 0x20A718u;
            goto label_20a718;
        }
    }
    ctx->pc = 0x20A6C8u;
    // 0x20a6c8: 0x2402feff  addiu       $v0, $zero, -0x101
    ctx->pc = 0x20a6c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967039));
    // 0x20a6cc: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x20a6ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x20a6d0: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x20a6d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x20a6d4: 0x21438  dsll        $v0, $v0, 16
    ctx->pc = 0x20a6d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x20a6d8: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x20a6d8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x20a6dc: 0x2404f3ff  addiu       $a0, $zero, -0xC01
    ctx->pc = 0x20a6dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294964223));
    // 0x20a6e0: 0x42438  dsll        $a0, $a0, 16
    ctx->pc = 0x20a6e0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 16);
    // 0x20a6e4: 0x3484ffff  ori         $a0, $a0, 0xFFFF
    ctx->pc = 0x20a6e4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)65535);
    // 0x20a6e8: 0x42438  dsll        $a0, $a0, 16
    ctx->pc = 0x20a6e8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 16);
    // 0x20a6ec: 0x3484ffff  ori         $a0, $a0, 0xFFFF
    ctx->pc = 0x20a6ecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)65535);
    // 0x20a6f0: 0x621024  and         $v0, $v1, $v0
    ctx->pc = 0x20a6f0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & GPR_U64(ctx, 2));
    // 0x20a6f4: 0x3c03ffff  lui         $v1, 0xFFFF
    ctx->pc = 0x20a6f4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65535 << 16));
    // 0x20a6f8: 0x34630fff  ori         $v1, $v1, 0xFFF
    ctx->pc = 0x20a6f8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)4095);
    // 0x20a6fc: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x20a6fcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x20a700: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x20a700u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x20a704: 0x31c38  dsll        $v1, $v1, 16
    ctx->pc = 0x20a704u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 16);
    // 0x20a708: 0x3463ffff  ori         $v1, $v1, 0xFFFF
    ctx->pc = 0x20a708u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)65535);
    // 0x20a70c: 0x441024  and         $v0, $v0, $a0
    ctx->pc = 0x20a70cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 4));
    // 0x20a710: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x20a710u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x20a714: 0xfd024700  sd          $v0, 0x4700($t0)
    ctx->pc = 0x20a714u;
    WRITE64(ADD32(GPR_U32(ctx, 8), 18176), GPR_U64(ctx, 2));
label_20a718:
    // 0x20a718: 0x3e00008  jr          $ra
    ctx->pc = 0x20A718u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x20A688u: goto label_20a688;
            case 0x20A6B0u: goto label_20a6b0;
            case 0x20A6B4u: goto label_20a6b4;
            case 0x20A718u: goto label_20a718;
            default: break;
        }
        return;
    }
    ctx->pc = 0x20A720u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
