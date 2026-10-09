#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0010C7F8
// Address: 0x10c7f8 - 0x10cb18
void sub_0010C7F8_0x10c7f8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0010C7F8_0x10c7f8");
#endif

    switch (ctx->pc) {
        case 0x10c830u: goto label_10c830;
        case 0x10c848u: goto label_10c848;
        case 0x10c890u: goto label_10c890;
        case 0x10c8a0u: goto label_10c8a0;
        case 0x10c928u: goto label_10c928;
        case 0x10c9ecu: goto label_10c9ec;
        case 0x10ca00u: goto label_10ca00;
        case 0x10ca10u: goto label_10ca10;
        case 0x10ca50u: goto label_10ca50;
        default: break;
    }

    ctx->pc = 0x10c7f8u;

    // 0x10c7f8: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x10c7f8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x10c7fc: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x10c7fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x10c800: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x10c800u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x10c804: 0x8c4697f0  lw          $a2, -0x6810($v0)
    ctx->pc = 0x10c804u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294940656)));
    // 0x10c808: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x10c808u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10c80c: 0x24c6005c  addiu       $a2, $a2, 0x5C
    ctx->pc = 0x10c80cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 92));
    // 0x10c810: 0x8043206  j           func_10C818
    ctx->pc = 0x10C810u;
    ctx->pc = 0x10C814u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C810u;
            // 0x10c814: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10C818u;
    goto label_10c818;
    ctx->pc = 0x10C818u;
label_10c818:
    // 0x10c818: 0x14800005  bnez        $a0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10C818u;
    {
        const bool branch_taken_0x10c818 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x10C81Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C818u;
            // 0x10c81c: 0xa0382d  daddu       $a3, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c818) {
            ctx->pc = 0x10C830u;
            goto label_10c830;
        }
    }
    ctx->pc = 0x10C820u;
    // 0x10c820: 0x8cc40000  lw          $a0, 0x0($a2)
    ctx->pc = 0x10c820u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x10c824: 0x1080002c  beqz        $a0, . + 4 + (0x2C << 2)
    ctx->pc = 0x10C824u;
    {
        const bool branch_taken_0x10c824 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x10C828u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C824u;
            // 0x10c828: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c824) {
            ctx->pc = 0x10C8D8u;
            goto label_10c8d8;
        }
    }
    ctx->pc = 0x10C82Cu;
    // 0x10c82c: 0xa0382d  daddu       $a3, $a1, $zero
    ctx->pc = 0x10c82cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_10c830:
    // 0x10c830: 0x80880000  lb          $t0, 0x0($a0)
    ctx->pc = 0x10c830u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10c834: 0x80e30000  lb          $v1, 0x0($a3)
    ctx->pc = 0x10c834u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x10c838: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x10c838u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x10c83c: 0x1060000d  beqz        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x10C83Cu;
    {
        const bool branch_taken_0x10c83c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x10C840u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C83Cu;
            // 0x10c840: 0x24840001  addiu       $a0, $a0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c83c) {
            ctx->pc = 0x10C874u;
            goto label_10c874;
        }
    }
    ctx->pc = 0x10C844u;
    // 0x10c844: 0x0  nop
    ctx->pc = 0x10c844u;
    // NOP
label_10c848:
    // 0x10c848: 0x0  nop
    ctx->pc = 0x10c848u;
    // NOP
    // 0x10c84c: 0x0  nop
    ctx->pc = 0x10c84cu;
    // NOP
    // 0x10c850: 0x5103fff7  beql        $t0, $v1, . + 4 + (-0x9 << 2)
    ctx->pc = 0x10C850u;
    {
        const bool branch_taken_0x10c850 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 3));
        if (branch_taken_0x10c850) {
            ctx->pc = 0x10C854u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10C850u;
            // 0x10c854: 0xa0382d  daddu       $a3, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10C830u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10c830;
        }
    }
    ctx->pc = 0x10C858u;
    // 0x10c858: 0x80e30000  lb          $v1, 0x0($a3)
    ctx->pc = 0x10c858u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x10c85c: 0x0  nop
    ctx->pc = 0x10c85cu;
    // NOP
    // 0x10c860: 0x0  nop
    ctx->pc = 0x10c860u;
    // NOP
    // 0x10c864: 0x0  nop
    ctx->pc = 0x10c864u;
    // NOP
    // 0x10c868: 0x0  nop
    ctx->pc = 0x10c868u;
    // NOP
    // 0x10c86c: 0x1460fff6  bnez        $v1, . + 4 + (-0xA << 2)
    ctx->pc = 0x10C86Cu;
    {
        const bool branch_taken_0x10c86c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x10C870u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C86Cu;
            // 0x10c870: 0x24e70001  addiu       $a3, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c86c) {
            ctx->pc = 0x10C848u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10c848;
        }
    }
    ctx->pc = 0x10C874u;
label_10c874:
    // 0x10c874: 0x55000004  bnel        $t0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x10C874u;
    {
        const bool branch_taken_0x10c874 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        if (branch_taken_0x10c874) {
            ctx->pc = 0x10C878u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10C874u;
            // 0x10c878: 0x2482ffff  addiu       $v0, $a0, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10C888u;
            goto label_10c888;
        }
    }
    ctx->pc = 0x10C87Cu;
    // 0x10c87c: 0xacc00000  sw          $zero, 0x0($a2)
    ctx->pc = 0x10c87cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
    // 0x10c880: 0x3e00008  jr          $ra
    ctx->pc = 0x10C880u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10C884u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C880u;
            // 0x10c884: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10C818u: goto label_10c818;
            case 0x10C830u: goto label_10c830;
            case 0x10C848u: goto label_10c848;
            case 0x10C874u: goto label_10c874;
            case 0x10C888u: goto label_10c888;
            case 0x10C890u: goto label_10c890;
            case 0x10C8A0u: goto label_10c8a0;
            case 0x10C8B4u: goto label_10c8b4;
            case 0x10C8C0u: goto label_10c8c0;
            case 0x10C8D8u: goto label_10c8d8;
            case 0x10C928u: goto label_10c928;
            case 0x10C968u: goto label_10c968;
            case 0x10C978u: goto label_10c978;
            case 0x10C988u: goto label_10c988;
            case 0x10C9A8u: goto label_10c9a8;
            case 0x10C9B4u: goto label_10c9b4;
            case 0x10C9C8u: goto label_10c9c8;
            case 0x10C9ECu: goto label_10c9ec;
            case 0x10CA00u: goto label_10ca00;
            case 0x10CA10u: goto label_10ca10;
            case 0x10CA40u: goto label_10ca40;
            case 0x10CA48u: goto label_10ca48;
            case 0x10CA50u: goto label_10ca50;
            case 0x10CA58u: goto label_10ca58;
            case 0x10CA60u: goto label_10ca60;
            case 0x10CA80u: goto label_10ca80;
            case 0x10CAA0u: goto label_10caa0;
            case 0x10CAD0u: goto label_10cad0;
            case 0x10CAD4u: goto label_10cad4;
            case 0x10CAE4u: goto label_10cae4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10C888u;
label_10c888:
    // 0x10c888: 0x80880000  lb          $t0, 0x0($a0)
    ctx->pc = 0x10c888u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x10c88c: 0x0  nop
    ctx->pc = 0x10c88cu;
    // NOP
label_10c890:
    // 0x10c890: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x10c890u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x10c894: 0xa0382d  daddu       $a3, $a1, $zero
    ctx->pc = 0x10c894u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c898: 0x80e30000  lb          $v1, 0x0($a3)
    ctx->pc = 0x10c898u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x10c89c: 0x0  nop
    ctx->pc = 0x10c89cu;
    // NOP
label_10c8a0:
    // 0x10c8a0: 0x14680007  bne         $v1, $t0, . + 4 + (0x7 << 2)
    ctx->pc = 0x10C8A0u;
    {
        const bool branch_taken_0x10c8a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 8));
        ctx->pc = 0x10C8A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C8A0u;
            // 0x10c8a4: 0x24e70001  addiu       $a3, $a3, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c8a0) {
            ctx->pc = 0x10C8C0u;
            goto label_10c8c0;
        }
    }
    ctx->pc = 0x10C8A8u;
    // 0x10c8a8: 0x54600002  bnel        $v1, $zero, . + 4 + (0x2 << 2)
    ctx->pc = 0x10C8A8u;
    {
        const bool branch_taken_0x10c8a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x10c8a8) {
            ctx->pc = 0x10C8ACu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10C8A8u;
            // 0x10c8ac: 0xa080ffff  sb          $zero, -0x1($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 4294967295), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10C8B4u;
            goto label_10c8b4;
        }
    }
    ctx->pc = 0x10C8B0u;
    // 0x10c8b0: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x10c8b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_10c8b4:
    // 0x10c8b4: 0x3e00008  jr          $ra
    ctx->pc = 0x10C8B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10C8B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C8B4u;
            // 0x10c8b8: 0xacc40000  sw          $a0, 0x0($a2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10C818u: goto label_10c818;
            case 0x10C830u: goto label_10c830;
            case 0x10C848u: goto label_10c848;
            case 0x10C874u: goto label_10c874;
            case 0x10C888u: goto label_10c888;
            case 0x10C890u: goto label_10c890;
            case 0x10C8A0u: goto label_10c8a0;
            case 0x10C8B4u: goto label_10c8b4;
            case 0x10C8C0u: goto label_10c8c0;
            case 0x10C8D8u: goto label_10c8d8;
            case 0x10C928u: goto label_10c928;
            case 0x10C968u: goto label_10c968;
            case 0x10C978u: goto label_10c978;
            case 0x10C988u: goto label_10c988;
            case 0x10C9A8u: goto label_10c9a8;
            case 0x10C9B4u: goto label_10c9b4;
            case 0x10C9C8u: goto label_10c9c8;
            case 0x10C9ECu: goto label_10c9ec;
            case 0x10CA00u: goto label_10ca00;
            case 0x10CA10u: goto label_10ca10;
            case 0x10CA40u: goto label_10ca40;
            case 0x10CA48u: goto label_10ca48;
            case 0x10CA50u: goto label_10ca50;
            case 0x10CA58u: goto label_10ca58;
            case 0x10CA60u: goto label_10ca60;
            case 0x10CA80u: goto label_10ca80;
            case 0x10CAA0u: goto label_10caa0;
            case 0x10CAD0u: goto label_10cad0;
            case 0x10CAD4u: goto label_10cad4;
            case 0x10CAE4u: goto label_10cae4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10C8BCu;
    // 0x10c8bc: 0x0  nop
    ctx->pc = 0x10c8bcu;
    // NOP
label_10c8c0:
    // 0x10c8c0: 0x0  nop
    ctx->pc = 0x10c8c0u;
    // NOP
    // 0x10c8c4: 0x0  nop
    ctx->pc = 0x10c8c4u;
    // NOP
    // 0x10c8c8: 0x5460fff5  bnel        $v1, $zero, . + 4 + (-0xB << 2)
    ctx->pc = 0x10C8C8u;
    {
        const bool branch_taken_0x10c8c8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        if (branch_taken_0x10c8c8) {
            ctx->pc = 0x10C8CCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10C8C8u;
            // 0x10c8cc: 0x80e30000  lb          $v1, 0x0($a3) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10C8A0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10c8a0;
        }
    }
    ctx->pc = 0x10C8D0u;
    // 0x10c8d0: 0x1000ffef  b           . + 4 + (-0x11 << 2)
    ctx->pc = 0x10C8D0u;
    {
        const bool branch_taken_0x10c8d0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10C8D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C8D0u;
            // 0x10c8d4: 0x80880000  lb          $t0, 0x0($a0) (Delay Slot)
        SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c8d0) {
            ctx->pc = 0x10C890u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10c890;
        }
    }
    ctx->pc = 0x10C8D8u;
label_10c8d8:
    // 0x10c8d8: 0x3e00008  jr          $ra
    ctx->pc = 0x10C8D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10C818u: goto label_10c818;
            case 0x10C830u: goto label_10c830;
            case 0x10C848u: goto label_10c848;
            case 0x10C874u: goto label_10c874;
            case 0x10C888u: goto label_10c888;
            case 0x10C890u: goto label_10c890;
            case 0x10C8A0u: goto label_10c8a0;
            case 0x10C8B4u: goto label_10c8b4;
            case 0x10C8C0u: goto label_10c8c0;
            case 0x10C8D8u: goto label_10c8d8;
            case 0x10C928u: goto label_10c928;
            case 0x10C968u: goto label_10c968;
            case 0x10C978u: goto label_10c978;
            case 0x10C988u: goto label_10c988;
            case 0x10C9A8u: goto label_10c9a8;
            case 0x10C9B4u: goto label_10c9b4;
            case 0x10C9C8u: goto label_10c9c8;
            case 0x10C9ECu: goto label_10c9ec;
            case 0x10CA00u: goto label_10ca00;
            case 0x10CA10u: goto label_10ca10;
            case 0x10CA40u: goto label_10ca40;
            case 0x10CA48u: goto label_10ca48;
            case 0x10CA50u: goto label_10ca50;
            case 0x10CA58u: goto label_10ca58;
            case 0x10CA60u: goto label_10ca60;
            case 0x10CA80u: goto label_10ca80;
            case 0x10CAA0u: goto label_10caa0;
            case 0x10CAD0u: goto label_10cad0;
            case 0x10CAD4u: goto label_10cad4;
            case 0x10CAE4u: goto label_10cae4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10C8E0u;
    // 0x10c8e0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x10c8e0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x10c8e4: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x10c8e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x10c8e8: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x10c8e8u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c8ec: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x10c8ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x10c8f0: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x10c8f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x10c8f4: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x10c8f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x10c8f8: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x10c8f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x10c8fc: 0xffbf0058  sd          $ra, 0x58($sp)
    ctx->pc = 0x10c8fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x10c900: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x10c900u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x10c904: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x10c904u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x10c908: 0x2a0902d  daddu       $s2, $s5, $zero
    ctx->pc = 0x10c908u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c90c: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x10c90cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x10c910: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x10c910u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c914: 0xffb70048  sd          $s7, 0x48($sp)
    ctx->pc = 0x10c914u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x10c918: 0xb82d  daddu       $s7, $zero, $zero
    ctx->pc = 0x10c918u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c91c: 0xffbe0050  sd          $fp, 0x50($sp)
    ctx->pc = 0x10c91cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x10c920: 0xc0f02d  daddu       $fp, $a2, $zero
    ctx->pc = 0x10c920u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c924: 0x0  nop
    ctx->pc = 0x10c924u;
    // NOP
label_10c928:
    // 0x10c928: 0x82510000  lb          $s1, 0x0($s2)
    ctx->pc = 0x10c928u;
    SET_GPR_S32(ctx, 17, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x10c92c: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x10c92cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x10c930: 0x511021  addu        $v0, $v0, $s1
    ctx->pc = 0x10c930u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x10c934: 0x90427769  lbu         $v0, 0x7769($v0)
    ctx->pc = 0x10c934u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 30569)));
    // 0x10c938: 0x30420008  andi        $v0, $v0, 0x8
    ctx->pc = 0x10c938u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)8);
    // 0x10c93c: 0x0  nop
    ctx->pc = 0x10c93cu;
    // NOP
    // 0x10c940: 0x0  nop
    ctx->pc = 0x10c940u;
    // NOP
    // 0x10c944: 0x1440fff8  bnez        $v0, . + 4 + (-0x8 << 2)
    ctx->pc = 0x10C944u;
    {
        const bool branch_taken_0x10c944 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x10C948u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C944u;
            // 0x10c948: 0x26520001  addiu       $s2, $s2, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c944) {
            ctx->pc = 0x10C928u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10c928;
        }
    }
    ctx->pc = 0x10C94Cu;
    // 0x10c94c: 0x2402002d  addiu       $v0, $zero, 0x2D
    ctx->pc = 0x10c94cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 45));
    // 0x10c950: 0x16220005  bne         $s1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x10C950u;
    {
        const bool branch_taken_0x10c950 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x10C954u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C950u;
            // 0x10c954: 0x2402002b  addiu       $v0, $zero, 0x2B (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 43));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c950) {
            ctx->pc = 0x10C968u;
            goto label_10c968;
        }
    }
    ctx->pc = 0x10C958u;
    // 0x10c958: 0x82510000  lb          $s1, 0x0($s2)
    ctx->pc = 0x10c958u;
    SET_GPR_S32(ctx, 17, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x10c95c: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x10c95cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
    // 0x10c960: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x10C960u;
    {
        const bool branch_taken_0x10c960 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10C964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C960u;
            // 0x10c964: 0x24170001  addiu       $s7, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c960) {
            ctx->pc = 0x10C978u;
            goto label_10c978;
        }
    }
    ctx->pc = 0x10C968u;
label_10c968:
    // 0x10c968: 0x16220003  bne         $s1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10C968u;
    {
        const bool branch_taken_0x10c968 = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        if (branch_taken_0x10c968) {
            ctx->pc = 0x10C978u;
            goto label_10c978;
        }
    }
    ctx->pc = 0x10C970u;
    // 0x10c970: 0x82510000  lb          $s1, 0x0($s2)
    ctx->pc = 0x10c970u;
    SET_GPR_S32(ctx, 17, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x10c974: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x10c974u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_10c978:
    // 0x10c978: 0x12600003  beqz        $s3, . + 4 + (0x3 << 2)
    ctx->pc = 0x10C978u;
    {
        const bool branch_taken_0x10c978 = (GPR_U64(ctx, 19) == GPR_U64(ctx, 0));
        ctx->pc = 0x10C97Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C978u;
            // 0x10c97c: 0x24020010  addiu       $v0, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c978) {
            ctx->pc = 0x10C988u;
            goto label_10c988;
        }
    }
    ctx->pc = 0x10C980u;
    // 0x10c980: 0x1662000c  bne         $s3, $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x10C980u;
    {
        const bool branch_taken_0x10c980 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 2));
        if (branch_taken_0x10c980) {
            ctx->pc = 0x10C9B4u;
            goto label_10c9b4;
        }
    }
    ctx->pc = 0x10C988u;
label_10c988:
    // 0x10c988: 0x24020030  addiu       $v0, $zero, 0x30
    ctx->pc = 0x10c988u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x10c98c: 0x16220009  bne         $s1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x10C98Cu;
    {
        const bool branch_taken_0x10c98c = (GPR_U64(ctx, 17) != GPR_U64(ctx, 2));
        ctx->pc = 0x10C990u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C98Cu;
            // 0x10c990: 0x24020078  addiu       $v0, $zero, 0x78 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 120));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c98c) {
            ctx->pc = 0x10C9B4u;
            goto label_10c9b4;
        }
    }
    ctx->pc = 0x10C994u;
    // 0x10c994: 0x82430000  lb          $v1, 0x0($s2)
    ctx->pc = 0x10c994u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x10c998: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10C998u;
    {
        const bool branch_taken_0x10c998 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x10C99Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C998u;
            // 0x10c99c: 0x24020058  addiu       $v0, $zero, 0x58 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 88));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c998) {
            ctx->pc = 0x10C9A8u;
            goto label_10c9a8;
        }
    }
    ctx->pc = 0x10C9A0u;
    // 0x10c9a0: 0x14620004  bne         $v1, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x10C9A0u;
    {
        const bool branch_taken_0x10c9a0 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x10c9a0) {
            ctx->pc = 0x10C9B4u;
            goto label_10c9b4;
        }
    }
    ctx->pc = 0x10C9A8u;
label_10c9a8:
    // 0x10c9a8: 0x82510001  lb          $s1, 0x1($s2)
    ctx->pc = 0x10c9a8u;
    SET_GPR_S32(ctx, 17, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 1)));
    // 0x10c9ac: 0x26520002  addiu       $s2, $s2, 0x2
    ctx->pc = 0x10c9acu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 2));
    // 0x10c9b0: 0x24130010  addiu       $s3, $zero, 0x10
    ctx->pc = 0x10c9b0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
label_10c9b4:
    // 0x10c9b4: 0x16600004  bnez        $s3, . + 4 + (0x4 << 2)
    ctx->pc = 0x10C9B4u;
    {
        const bool branch_taken_0x10c9b4 = (GPR_U64(ctx, 19) != GPR_U64(ctx, 0));
        ctx->pc = 0x10C9B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10C9B4u;
            // 0x10c9b8: 0x2403000a  addiu       $v1, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10c9b4) {
            ctx->pc = 0x10C9C8u;
            goto label_10c9c8;
        }
    }
    ctx->pc = 0x10C9BCu;
    // 0x10c9bc: 0x24130008  addiu       $s3, $zero, 0x8
    ctx->pc = 0x10c9bcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x10c9c0: 0x3a220030  xori        $v0, $s1, 0x30
    ctx->pc = 0x10c9c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) ^ (uint64_t)(uint16_t)48);
    // 0x10c9c4: 0x62980b  movn        $s3, $v1, $v0
    ctx->pc = 0x10c9c4u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 19, GPR_VEC(ctx, 3));
label_10c9c8:
    // 0x10c9c8: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x10c9c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10c9cc: 0x2107a  dsrl        $v0, $v0, 1
    ctx->pc = 0x10c9ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 1);
    // 0x10c9d0: 0x34148000  ori         $s4, $zero, 0x8000
    ctx->pc = 0x10c9d0u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x10c9d4: 0x14a43c  dsll32      $s4, $s4, 16
    ctx->pc = 0x10c9d4u;
    SET_GPR_U64(ctx, 20, GPR_U64(ctx, 20) << (32 + 16));
    // 0x10c9d8: 0x57a00a  movz        $s4, $v0, $s7
    ctx->pc = 0x10c9d8u;
    if (GPR_U64(ctx, 23) == 0) SET_GPR_VEC(ctx, 20, GPR_VEC(ctx, 2));
    // 0x10c9dc: 0x260802d  daddu       $s0, $s3, $zero
    ctx->pc = 0x10c9dcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c9e0: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x10c9e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c9e4: 0xc044370  jal         func_110DC0
    ctx->pc = 0x10C9E4u;
    SET_GPR_U32(ctx, 31, 0x10C9ECu);
    ctx->pc = 0x10C9E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C9E4u;
            // 0x10c9e8: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x110DC0u;
    if (runtime->hasFunction(0x110DC0u)) {
        auto targetFn = runtime->lookupFunction(0x110DC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C9ECu; }
        if (ctx->pc != 0x10C9ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00110DC0_0x110dc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10C9ECu; }
        if (ctx->pc != 0x10C9ECu) { return; }
    }
    ctx->pc = 0x10C9ECu;
label_10c9ec:
    // 0x10c9ec: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x10c9ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10c9f0: 0x2b03c  dsll32      $s6, $v0, 0
    ctx->pc = 0x10c9f0u;
    SET_GPR_U64(ctx, 22, GPR_U64(ctx, 2) << (32 + 0));
    // 0x10c9f4: 0x16b03f  dsra32      $s6, $s6, 0
    ctx->pc = 0x10c9f4u;
    SET_GPR_S64(ctx, 22, GPR_S64(ctx, 22) >> (32 + 0));
    // 0x10c9f8: 0xc044210  jal         func_110840
    ctx->pc = 0x10C9F8u;
    SET_GPR_U32(ctx, 31, 0x10CA00u);
    ctx->pc = 0x10C9FCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10C9F8u;
            // 0x10c9fc: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x110840u;
    if (runtime->hasFunction(0x110840u)) {
        auto targetFn = runtime->lookupFunction(0x110840u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10CA00u; }
        if (ctx->pc != 0x10CA00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00110840_0x110840(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10CA00u; }
        if (ctx->pc != 0x10CA00u) { return; }
    }
    ctx->pc = 0x10CA00u;
label_10ca00:
    // 0x10ca00: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x10ca00u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ca04: 0x40a02d  daddu       $s4, $v0, $zero
    ctx->pc = 0x10ca04u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ca08: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x10CA08u;
    {
        const bool branch_taken_0x10ca08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CA0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CA08u;
            // 0x10ca0c: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ca08) {
            ctx->pc = 0x10CA60u;
            goto label_10ca60;
        }
    }
    ctx->pc = 0x10CA10u;
label_10ca10:
    // 0x10ca10: 0x233102a  slt         $v0, $s1, $s3
    ctx->pc = 0x10ca10u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 17) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x10ca14: 0x10400022  beqz        $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x10CA14u;
    {
        const bool branch_taken_0x10ca14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10ca14) {
            ctx->pc = 0x10CAA0u;
            goto label_10caa0;
        }
    }
    ctx->pc = 0x10CA1Cu;
    // 0x10ca1c: 0x4c00008  bltz        $a2, . + 4 + (0x8 << 2)
    ctx->pc = 0x10CA1Cu;
    {
        const bool branch_taken_0x10ca1c = (GPR_S64(ctx, 6) < 0);
        ctx->pc = 0x10CA20u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CA1Cu;
            // 0x10ca20: 0x285102b  sltu        $v0, $s4, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 20) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ca1c) {
            ctx->pc = 0x10CA40u;
            goto label_10ca40;
        }
    }
    ctx->pc = 0x10CA24u;
    // 0x10ca24: 0x5440000c  bnel        $v0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x10CA24u;
    {
        const bool branch_taken_0x10ca24 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x10ca24) {
            ctx->pc = 0x10CA28u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x10CA24u;
            // 0x10ca28: 0x2406ffff  addiu       $a2, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x10CA58u;
            goto label_10ca58;
        }
    }
    ctx->pc = 0x10CA2Cu;
    // 0x10ca2c: 0x14b40006  bne         $a1, $s4, . + 4 + (0x6 << 2)
    ctx->pc = 0x10CA2Cu;
    {
        const bool branch_taken_0x10ca2c = (GPR_U64(ctx, 5) != GPR_U64(ctx, 20));
        ctx->pc = 0x10CA30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CA2Cu;
            // 0x10ca30: 0xa0202d  daddu       $a0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ca2c) {
            ctx->pc = 0x10CA48u;
            goto label_10ca48;
        }
    }
    ctx->pc = 0x10CA34u;
    // 0x10ca34: 0x2d1102a  slt         $v0, $s6, $s1
    ctx->pc = 0x10ca34u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 22) < (int64_t)GPR_S64(ctx, 17)) ? 1 : 0);
    // 0x10ca38: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10CA38u;
    {
        const bool branch_taken_0x10ca38 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x10ca38) {
            ctx->pc = 0x10CA48u;
            goto label_10ca48;
        }
    }
    ctx->pc = 0x10CA40u;
label_10ca40:
    // 0x10ca40: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x10CA40u;
    {
        const bool branch_taken_0x10ca40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CA44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CA40u;
            // 0x10ca44: 0x2406ffff  addiu       $a2, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ca40) {
            ctx->pc = 0x10CA58u;
            goto label_10ca58;
        }
    }
    ctx->pc = 0x10CA48u;
label_10ca48:
    // 0x10ca48: 0xc043ea8  jal         func_10FAA0
    ctx->pc = 0x10CA48u;
    SET_GPR_U32(ctx, 31, 0x10CA50u);
    ctx->pc = 0x10CA4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x10CA48u;
            // 0x10ca4c: 0x200282d  daddu       $a1, $s0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x10FAA0u;
    if (runtime->hasFunction(0x10FAA0u)) {
        auto targetFn = runtime->lookupFunction(0x10FAA0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10CA50u; }
        if (ctx->pc != 0x10CA50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10CA50u; }
        if (ctx->pc != 0x10CA50u) { return; }
    }
    ctx->pc = 0x10CA50u;
label_10ca50:
    // 0x10ca50: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x10ca50u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x10ca54: 0x222282d  daddu       $a1, $s1, $v0
    ctx->pc = 0x10ca54u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 2));
label_10ca58:
    // 0x10ca58: 0x82510000  lb          $s1, 0x0($s2)
    ctx->pc = 0x10ca58u;
    SET_GPR_S32(ctx, 17, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x10ca5c: 0x26520001  addiu       $s2, $s2, 0x1
    ctx->pc = 0x10ca5cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 18), 1));
label_10ca60:
    // 0x10ca60: 0x3c040023  lui         $a0, 0x23
    ctx->pc = 0x10ca60u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)35 << 16));
    // 0x10ca64: 0x912021  addu        $a0, $a0, $s1
    ctx->pc = 0x10ca64u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x10ca68: 0x90847769  lbu         $a0, 0x7769($a0)
    ctx->pc = 0x10ca68u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 30569)));
    // 0x10ca6c: 0x30820004  andi        $v0, $a0, 0x4
    ctx->pc = 0x10ca6cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)4);
    // 0x10ca70: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x10CA70u;
    {
        const bool branch_taken_0x10ca70 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CA74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CA70u;
            // 0x10ca74: 0x30820003  andi        $v0, $a0, 0x3 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)3);
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ca70) {
            ctx->pc = 0x10CA80u;
            goto label_10ca80;
        }
    }
    ctx->pc = 0x10CA78u;
    // 0x10ca78: 0x1000ffe5  b           . + 4 + (-0x1B << 2)
    ctx->pc = 0x10CA78u;
    {
        const bool branch_taken_0x10ca78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CA7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CA78u;
            // 0x10ca7c: 0x2631ffd0  addiu       $s1, $s1, -0x30 (Delay Slot)
        SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967248));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ca78) {
            ctx->pc = 0x10CA10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10ca10;
        }
    }
    ctx->pc = 0x10CA80u;
label_10ca80:
    // 0x10ca80: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x10CA80u;
    {
        const bool branch_taken_0x10ca80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CA84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CA80u;
            // 0x10ca84: 0x2622ffc9  addiu       $v0, $s1, -0x37 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967241));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ca80) {
            ctx->pc = 0x10CAA0u;
            goto label_10caa0;
        }
    }
    ctx->pc = 0x10CA88u;
    // 0x10ca88: 0x2623ffa9  addiu       $v1, $s1, -0x57
    ctx->pc = 0x10ca88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 17), 4294967209));
    // 0x10ca8c: 0x30840001  andi        $a0, $a0, 0x1
    ctx->pc = 0x10ca8cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)1);
    // 0x10ca90: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x10ca90u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10ca94: 0x1000ffde  b           . + 4 + (-0x22 << 2)
    ctx->pc = 0x10CA94u;
    {
        const bool branch_taken_0x10ca94 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CA98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CA94u;
            // 0x10ca98: 0x64880a  movz        $s1, $v1, $a0 (Delay Slot)
        if (GPR_U64(ctx, 4) == 0) SET_GPR_VEC(ctx, 17, GPR_VEC(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10ca94) {
            ctx->pc = 0x10CA10u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_10ca10;
        }
    }
    ctx->pc = 0x10CA9Cu;
    // 0x10ca9c: 0x0  nop
    ctx->pc = 0x10ca9cu;
    // NOP
label_10caa0:
    // 0x10caa0: 0x4c1000b  bgez        $a2, . + 4 + (0xB << 2)
    ctx->pc = 0x10CAA0u;
    {
        const bool branch_taken_0x10caa0 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x10CAA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CAA0u;
            // 0x10caa4: 0x5102f  dsubu       $v0, $zero, $a1 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) - GPR_U64(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10caa0) {
            ctx->pc = 0x10CAD0u;
            goto label_10cad0;
        }
    }
    ctx->pc = 0x10CAA8u;
    // 0x10caa8: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x10caa8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x10caac: 0x3187a  dsrl        $v1, $v1, 1
    ctx->pc = 0x10caacu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> 1);
    // 0x10cab0: 0x34058000  ori         $a1, $zero, 0x8000
    ctx->pc = 0x10cab0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x10cab4: 0x52c3c  dsll32      $a1, $a1, 16
    ctx->pc = 0x10cab4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 16));
    // 0x10cab8: 0x77280a  movz        $a1, $v1, $s7
    ctx->pc = 0x10cab8u;
    if (GPR_U64(ctx, 23) == 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 3));
    // 0x10cabc: 0x8fa30000  lw          $v1, 0x0($sp)
    ctx->pc = 0x10cabcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x10cac0: 0x24020022  addiu       $v0, $zero, 0x22
    ctx->pc = 0x10cac0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 34));
    // 0x10cac4: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x10CAC4u;
    {
        const bool branch_taken_0x10cac4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CAC8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CAC4u;
            // 0x10cac8: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10cac4) {
            ctx->pc = 0x10CAD4u;
            goto label_10cad4;
        }
    }
    ctx->pc = 0x10CACCu;
    // 0x10cacc: 0x0  nop
    ctx->pc = 0x10caccu;
    // NOP
label_10cad0:
    // 0x10cad0: 0x57280b  movn        $a1, $v0, $s7
    ctx->pc = 0x10cad0u;
    if (GPR_U64(ctx, 23) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 2));
label_10cad4:
    // 0x10cad4: 0x13c00003  beqz        $fp, . + 4 + (0x3 << 2)
    ctx->pc = 0x10CAD4u;
    {
        const bool branch_taken_0x10cad4 = (GPR_U64(ctx, 30) == GPR_U64(ctx, 0));
        ctx->pc = 0x10CAD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CAD4u;
            // 0x10cad8: 0x2642ffff  addiu       $v0, $s2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x10cad4) {
            ctx->pc = 0x10CAE4u;
            goto label_10cae4;
        }
    }
    ctx->pc = 0x10CADCu;
    // 0x10cadc: 0x46a80b  movn        $s5, $v0, $a2
    ctx->pc = 0x10cadcu;
    if (GPR_U64(ctx, 6) != 0) SET_GPR_VEC(ctx, 21, GPR_VEC(ctx, 2));
    // 0x10cae0: 0xafd50000  sw          $s5, 0x0($fp)
    ctx->pc = 0x10cae0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 21));
label_10cae4:
    // 0x10cae4: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x10cae4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x10cae8: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x10cae8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x10caec: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x10caecu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x10caf0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x10caf0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x10caf4: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x10caf4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x10caf8: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x10caf8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x10cafc: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x10cafcu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x10cb00: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x10cb00u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x10cb04: 0xdfb70048  ld          $s7, 0x48($sp)
    ctx->pc = 0x10cb04u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x10cb08: 0xdfbe0050  ld          $fp, 0x50($sp)
    ctx->pc = 0x10cb08u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x10cb0c: 0xdfbf0058  ld          $ra, 0x58($sp)
    ctx->pc = 0x10cb0cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x10cb10: 0x3e00008  jr          $ra
    ctx->pc = 0x10CB10u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x10CB14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x10CB10u;
            // 0x10cb14: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x10C818u: goto label_10c818;
            case 0x10C830u: goto label_10c830;
            case 0x10C848u: goto label_10c848;
            case 0x10C874u: goto label_10c874;
            case 0x10C888u: goto label_10c888;
            case 0x10C890u: goto label_10c890;
            case 0x10C8A0u: goto label_10c8a0;
            case 0x10C8B4u: goto label_10c8b4;
            case 0x10C8C0u: goto label_10c8c0;
            case 0x10C8D8u: goto label_10c8d8;
            case 0x10C928u: goto label_10c928;
            case 0x10C968u: goto label_10c968;
            case 0x10C978u: goto label_10c978;
            case 0x10C988u: goto label_10c988;
            case 0x10C9A8u: goto label_10c9a8;
            case 0x10C9B4u: goto label_10c9b4;
            case 0x10C9C8u: goto label_10c9c8;
            case 0x10C9ECu: goto label_10c9ec;
            case 0x10CA00u: goto label_10ca00;
            case 0x10CA10u: goto label_10ca10;
            case 0x10CA40u: goto label_10ca40;
            case 0x10CA48u: goto label_10ca48;
            case 0x10CA50u: goto label_10ca50;
            case 0x10CA58u: goto label_10ca58;
            case 0x10CA60u: goto label_10ca60;
            case 0x10CA80u: goto label_10ca80;
            case 0x10CAA0u: goto label_10caa0;
            case 0x10CAD0u: goto label_10cad0;
            case 0x10CAD4u: goto label_10cad4;
            case 0x10CAE4u: goto label_10cae4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x10CB18u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
