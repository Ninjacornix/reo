#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001A77D0
// Address: 0x1a77d0 - 0x1a7900
void sub_001A77D0_0x1a77d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001A77D0_0x1a77d0");
#endif

    ctx->pc = 0x1a77d0u;

    // 0x1a77d0: 0x24ab000f  addiu       $t3, $a1, 0xF
    ctx->pc = 0x1a77d0u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 5), 15));
    // 0x1a77d4: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a77d4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a77d8: 0x2405fff0  addiu       $a1, $zero, -0x10
    ctx->pc = 0x1a77d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967280));
    // 0x1a77dc: 0x3c03002b  lui         $v1, 0x2B
    ctx->pc = 0x1a77dcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)43 << 16));
    // 0x1a77e0: 0x1652824  and         $a1, $t3, $a1
    ctx->pc = 0x1a77e0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 11) & GPR_U64(ctx, 5));
    // 0x1a77e4: 0x8c2c0a68  lw          $t4, 0xA68($at)
    ctx->pc = 0x1a77e4u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 2664)));
    // 0x1a77e8: 0x55903  sra         $t3, $a1, 4
    ctx->pc = 0x1a77e8u;
    SET_GPR_S32(ctx, 11, SRA32(GPR_S32(ctx, 5), 4));
    // 0x1a77ec: 0x3c0a4f00  lui         $t2, 0x4F00
    ctx->pc = 0x1a77ecu;
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)20224 << 16));
    // 0x1a77f0: 0x52d03  sra         $a1, $a1, 20
    ctx->pc = 0x1a77f0u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 20));
    // 0x1a77f4: 0x24630a80  addiu       $v1, $v1, 0xA80
    ctx->pc = 0x1a77f4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 2688));
    // 0x1a77f8: 0x852825  or          $a1, $a0, $a1
    ctx->pc = 0x1a77f8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 4) | GPR_U64(ctx, 5));
    // 0x1a77fc: 0xb223c  dsll32      $a0, $t3, 8
    ctx->pc = 0x1a77fcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 11) << (32 + 8));
    // 0x1a7800: 0x4223e  dsrl32      $a0, $a0, 8
    ctx->pc = 0x1a7800u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) >> (32 + 8));
    // 0x1a7804: 0x8a5825  or          $t3, $a0, $t2
    ctx->pc = 0x1a7804u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 4) | GPR_U64(ctx, 10));
    // 0x1a7808: 0xc2040  sll         $a0, $t4, 1
    ctx->pc = 0x1a7808u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 12), 1));
    // 0x1a780c: 0x8c5021  addu        $t2, $a0, $t4
    ctx->pc = 0x1a780cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 12)));
    // 0x1a7810: 0xa5080  sll         $t2, $t2, 2
    ctx->pc = 0x1a7810u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 2));
    // 0x1a7814: 0x25840001  addiu       $a0, $t4, 0x1
    ctx->pc = 0x1a7814u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 12), 1));
    // 0x1a7818: 0x6a5021  addu        $t2, $v1, $t2
    ctx->pc = 0x1a7818u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x1a781c: 0x308c001f  andi        $t4, $a0, 0x1F
    ctx->pc = 0x1a781cu;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)31);
    // 0x1a7820: 0xad4b0000  sw          $t3, 0x0($t2)
    ctx->pc = 0x1a7820u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 0), GPR_U32(ctx, 11));
    // 0x1a7824: 0x4810004  bgez        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A7824u;
    {
        const bool branch_taken_0x1a7824 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x1A7828u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7824u;
            // 0x1a7828: 0xad450004  sw          $a1, 0x4($t2) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 10), 4), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7824) {
            ctx->pc = 0x1A7838u;
            goto label_1a7838;
        }
    }
    ctx->pc = 0x1A782Cu;
    // 0x1a782c: 0x11800003  beqz        $t4, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A782Cu;
    {
        const bool branch_taken_0x1a782c = (GPR_U64(ctx, 12) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7830u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A782Cu;
            // 0x1a7830: 0x24e5000f  addiu       $a1, $a3, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), 15));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a782c) {
            ctx->pc = 0x1A783Cu;
            goto label_1a783c;
        }
    }
    ctx->pc = 0x1A7834u;
    // 0x1a7834: 0x258cffe0  addiu       $t4, $t4, -0x20
    ctx->pc = 0x1a7834u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 4294967264));
label_1a7838:
    // 0x1a7838: 0x24e5000f  addiu       $a1, $a3, 0xF
    ctx->pc = 0x1a7838u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), 15));
label_1a783c:
    // 0x1a783c: 0x2404fff0  addiu       $a0, $zero, -0x10
    ctx->pc = 0x1a783cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967280));
    // 0x1a7840: 0xa43824  and         $a3, $a1, $a0
    ctx->pc = 0x1a7840u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 5) & GPR_U64(ctx, 4));
    // 0x1a7844: 0xc2040  sll         $a0, $t4, 1
    ctx->pc = 0x1a7844u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 12), 1));
    // 0x1a7848: 0x8c2821  addu        $a1, $a0, $t4
    ctx->pc = 0x1a7848u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 12)));
    // 0x1a784c: 0x55080  sll         $t2, $a1, 2
    ctx->pc = 0x1a784cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1a7850: 0x25840001  addiu       $a0, $t4, 0x1
    ctx->pc = 0x1a7850u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 12), 1));
    // 0x1a7854: 0x72903  sra         $a1, $a3, 4
    ctx->pc = 0x1a7854u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 7), 4));
    // 0x1a7858: 0x6a5821  addu        $t3, $v1, $t2
    ctx->pc = 0x1a7858u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x1a785c: 0x5523c  dsll32      $t2, $a1, 8
    ctx->pc = 0x1a785cu;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 5) << (32 + 8));
    // 0x1a7860: 0x72d03  sra         $a1, $a3, 20
    ctx->pc = 0x1a7860u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 7), 20));
    // 0x1a7864: 0xa523e  dsrl32      $t2, $t2, 8
    ctx->pc = 0x1a7864u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 10) >> (32 + 8));
    // 0x1a7868: 0x3c074f00  lui         $a3, 0x4F00
    ctx->pc = 0x1a7868u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)20224 << 16));
    // 0x1a786c: 0xc52825  or          $a1, $a2, $a1
    ctx->pc = 0x1a786cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 6) | GPR_U64(ctx, 5));
    // 0x1a7870: 0x1473825  or          $a3, $t2, $a3
    ctx->pc = 0x1a7870u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 10) | GPR_U64(ctx, 7));
    // 0x1a7874: 0x3086001f  andi        $a2, $a0, 0x1F
    ctx->pc = 0x1a7874u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)31);
    // 0x1a7878: 0xad670000  sw          $a3, 0x0($t3)
    ctx->pc = 0x1a7878u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 0), GPR_U32(ctx, 7));
    // 0x1a787c: 0x4810004  bgez        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A787Cu;
    {
        const bool branch_taken_0x1a787c = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x1A7880u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A787Cu;
            // 0x1a7880: 0xad650004  sw          $a1, 0x4($t3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 11), 4), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a787c) {
            ctx->pc = 0x1A7890u;
            goto label_1a7890;
        }
    }
    ctx->pc = 0x1A7884u;
    // 0x1a7884: 0x10c00003  beqz        $a2, . + 4 + (0x3 << 2)
    ctx->pc = 0x1A7884u;
    {
        const bool branch_taken_0x1a7884 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x1A7888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A7884u;
            // 0x1a7888: 0x2525000f  addiu       $a1, $t1, 0xF (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 9), 15));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a7884) {
            ctx->pc = 0x1A7894u;
            goto label_1a7894;
        }
    }
    ctx->pc = 0x1A788Cu;
    // 0x1a788c: 0x24c6ffe0  addiu       $a2, $a2, -0x20
    ctx->pc = 0x1a788cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967264));
label_1a7890:
    // 0x1a7890: 0x2525000f  addiu       $a1, $t1, 0xF
    ctx->pc = 0x1a7890u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 9), 15));
label_1a7894:
    // 0x1a7894: 0x2404fff0  addiu       $a0, $zero, -0x10
    ctx->pc = 0x1a7894u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967280));
    // 0x1a7898: 0xa44824  and         $t1, $a1, $a0
    ctx->pc = 0x1a7898u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 5) & GPR_U64(ctx, 4));
    // 0x1a789c: 0x62040  sll         $a0, $a2, 1
    ctx->pc = 0x1a789cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
    // 0x1a78a0: 0x862821  addu        $a1, $a0, $a2
    ctx->pc = 0x1a78a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x1a78a4: 0x24c40001  addiu       $a0, $a2, 0x1
    ctx->pc = 0x1a78a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x1a78a8: 0x53080  sll         $a2, $a1, 2
    ctx->pc = 0x1a78a8u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1a78ac: 0x663821  addu        $a3, $v1, $a2
    ctx->pc = 0x1a78acu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x1a78b0: 0x92903  sra         $a1, $t1, 4
    ctx->pc = 0x1a78b0u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 9), 4));
    // 0x1a78b4: 0x5323c  dsll32      $a2, $a1, 8
    ctx->pc = 0x1a78b4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 5) << (32 + 8));
    // 0x1a78b8: 0x91d03  sra         $v1, $t1, 20
    ctx->pc = 0x1a78b8u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 9), 20));
    // 0x1a78bc: 0x6323e  dsrl32      $a2, $a2, 8
    ctx->pc = 0x1a78bcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 8));
    // 0x1a78c0: 0x3c054f00  lui         $a1, 0x4F00
    ctx->pc = 0x1a78c0u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)20224 << 16));
    // 0x1a78c4: 0xc53025  or          $a2, $a2, $a1
    ctx->pc = 0x1a78c4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) | GPR_U64(ctx, 5));
    // 0x1a78c8: 0x1032825  or          $a1, $t0, $v1
    ctx->pc = 0x1a78c8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x1a78cc: 0xace60000  sw          $a2, 0x0($a3)
    ctx->pc = 0x1a78ccu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 6));
    // 0x1a78d0: 0x3083001f  andi        $v1, $a0, 0x1F
    ctx->pc = 0x1a78d0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)31);
    // 0x1a78d4: 0x4810004  bgez        $a0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1A78D4u;
    {
        const bool branch_taken_0x1a78d4 = (GPR_S64(ctx, 4) >= 0);
        ctx->pc = 0x1A78D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A78D4u;
            // 0x1a78d8: 0xace50004  sw          $a1, 0x4($a3) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 7), 4), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1a78d4) {
            ctx->pc = 0x1A78E8u;
            goto label_1a78e8;
        }
    }
    ctx->pc = 0x1A78DCu;
    // 0x1a78dc: 0x10600002  beqz        $v1, . + 4 + (0x2 << 2)
    ctx->pc = 0x1A78DCu;
    {
        const bool branch_taken_0x1a78dc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1a78dc) {
            ctx->pc = 0x1A78E8u;
            goto label_1a78e8;
        }
    }
    ctx->pc = 0x1A78E4u;
    // 0x1a78e4: 0x2463ffe0  addiu       $v1, $v1, -0x20
    ctx->pc = 0x1a78e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967264));
label_1a78e8:
    // 0x1a78e8: 0x3c01002b  lui         $at, 0x2B
    ctx->pc = 0x1a78e8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)43 << 16));
    // 0x1a78ec: 0x3e00008  jr          $ra
    ctx->pc = 0x1A78ECu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A78F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1A78ECu;
            // 0x1a78f0: 0xac230a68  sw          $v1, 0xA68($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 2664), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A7838u: goto label_1a7838;
            case 0x1A783Cu: goto label_1a783c;
            case 0x1A7890u: goto label_1a7890;
            case 0x1A7894u: goto label_1a7894;
            case 0x1A78E8u: goto label_1a78e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A78F4u;
    // 0x1a78f4: 0x0  nop
    ctx->pc = 0x1a78f4u;
    // NOP
    // 0x1a78f8: 0x0  nop
    ctx->pc = 0x1a78f8u;
    // NOP
    // 0x1a78fc: 0x0  nop
    ctx->pc = 0x1a78fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
