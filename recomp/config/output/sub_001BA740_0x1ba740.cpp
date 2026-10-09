#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001BA740
// Address: 0x1ba740 - 0x1ba840
void sub_001BA740_0x1ba740(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001BA740_0x1ba740");
#endif

    ctx->pc = 0x1ba740u;

    // 0x1ba740: 0x41840  sll         $v1, $a0, 1
    ctx->pc = 0x1ba740u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x1ba744: 0x3c05002b  lui         $a1, 0x2B
    ctx->pc = 0x1ba744u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)43 << 16));
    // 0x1ba748: 0x642021  addu        $a0, $v1, $a0
    ctx->pc = 0x1ba748u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1ba74c: 0x3c060031  lui         $a2, 0x31
    ctx->pc = 0x1ba74cu;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49 << 16));
    // 0x1ba750: 0x24a50a10  addiu       $a1, $a1, 0xA10
    ctx->pc = 0x1ba750u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2576));
    // 0x1ba754: 0x420c0  sll         $a0, $a0, 3
    ctx->pc = 0x1ba754u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 3));
    // 0x1ba758: 0xa42021  addu        $a0, $a1, $a0
    ctx->pc = 0x1ba758u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x1ba75c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1ba75cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ba760: 0x90840000  lbu         $a0, 0x0($a0)
    ctx->pc = 0x1ba760u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ba764: 0x10830007  beq         $a0, $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1BA764u;
    {
        const bool branch_taken_0x1ba764 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1BA768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA764u;
            // 0x1ba768: 0x24c66570  addiu       $a2, $a2, 0x6570 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 25968));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba764) {
            ctx->pc = 0x1BA784u;
            goto label_1ba784;
        }
    }
    ctx->pc = 0x1BA76Cu;
    // 0x1ba76c: 0xa0c00000  sb          $zero, 0x0($a2)
    ctx->pc = 0x1ba76cu;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ba770: 0xa4c0000c  sh          $zero, 0xC($a2)
    ctx->pc = 0x1ba770u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 12), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ba774: 0xa4c0000e  sh          $zero, 0xE($a2)
    ctx->pc = 0x1ba774u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 14), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ba778: 0xacc00010  sw          $zero, 0x10($a2)
    ctx->pc = 0x1ba778u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 0));
    // 0x1ba77c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1BA77Cu;
    {
        const bool branch_taken_0x1ba77c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA780u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA77Cu;
            // 0x1ba780: 0xa0c00001  sb          $zero, 0x1($a2) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 6), 1), (uint8_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba77c) {
            ctx->pc = 0x1BA788u;
            goto label_1ba788;
        }
    }
    ctx->pc = 0x1BA784u;
label_1ba784:
    // 0x1ba784: 0xa0c30000  sb          $v1, 0x0($a2)
    ctx->pc = 0x1ba784u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 3));
label_1ba788:
    // 0x1ba788: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA788u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA784u: goto label_1ba784;
            case 0x1BA788u: goto label_1ba788;
            case 0x1BA7DCu: goto label_1ba7dc;
            case 0x1BA834u: goto label_1ba834;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA790u;
    // 0x1ba790: 0x3c010032  lui         $at, 0x32
    ctx->pc = 0x1ba790u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)50 << 16));
    // 0x1ba794: 0x3c060031  lui         $a2, 0x31
    ctx->pc = 0x1ba794u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49 << 16));
    // 0x1ba798: 0x902343ef  lbu         $v1, 0x43EF($at)
    ctx->pc = 0x1ba798u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17391)));
    // 0x1ba79c: 0x1060000f  beqz        $v1, . + 4 + (0xF << 2)
    ctx->pc = 0x1BA79Cu;
    {
        const bool branch_taken_0x1ba79c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA7A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA79Cu;
            // 0x1ba7a0: 0x24c66570  addiu       $a2, $a2, 0x6570 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 25968));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba79c) {
            ctx->pc = 0x1BA7DCu;
            goto label_1ba7dc;
        }
    }
    ctx->pc = 0x1BA7A4u;
    // 0x1ba7a4: 0x90c30000  lbu         $v1, 0x0($a2)
    ctx->pc = 0x1ba7a4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1ba7a8: 0x1060000c  beqz        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1BA7A8u;
    {
        const bool branch_taken_0x1ba7a8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA7ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA7A8u;
            // 0x1ba7ac: 0x28a10009  slti        $at, $a1, 0x9 (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)9) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba7a8) {
            ctx->pc = 0x1BA7DCu;
            goto label_1ba7dc;
        }
    }
    ctx->pc = 0x1BA7B0u;
    // 0x1ba7b0: 0x1020000a  beqz        $at, . + 4 + (0xA << 2)
    ctx->pc = 0x1BA7B0u;
    {
        const bool branch_taken_0x1ba7b0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA7B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA7B0u;
            // 0x1ba7b4: 0x3c030023  lui         $v1, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba7b0) {
            ctx->pc = 0x1BA7DCu;
            goto label_1ba7dc;
        }
    }
    ctx->pc = 0x1BA7B8u;
    // 0x1ba7b8: 0x52080  sll         $a0, $a1, 2
    ctx->pc = 0x1ba7b8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1ba7bc: 0x24634da0  addiu       $v1, $v1, 0x4DA0
    ctx->pc = 0x1ba7bcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19872));
    // 0x1ba7c0: 0x642021  addu        $a0, $v1, $a0
    ctx->pc = 0x1ba7c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1ba7c4: 0x8c840000  lw          $a0, 0x0($a0)
    ctx->pc = 0x1ba7c4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ba7c8: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1ba7c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ba7cc: 0xacc40010  sw          $a0, 0x10($a2)
    ctx->pc = 0x1ba7ccu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 4));
    // 0x1ba7d0: 0xa4c0000e  sh          $zero, 0xE($a2)
    ctx->pc = 0x1ba7d0u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 14), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ba7d4: 0xa4c3000c  sh          $v1, 0xC($a2)
    ctx->pc = 0x1ba7d4u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 12), (uint16_t)GPR_U32(ctx, 3));
    // 0x1ba7d8: 0xa0c30001  sb          $v1, 0x1($a2)
    ctx->pc = 0x1ba7d8u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 1), (uint8_t)GPR_U32(ctx, 3));
label_1ba7dc:
    // 0x1ba7dc: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA7DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA784u: goto label_1ba784;
            case 0x1BA788u: goto label_1ba788;
            case 0x1BA7DCu: goto label_1ba7dc;
            case 0x1BA834u: goto label_1ba834;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA7E4u;
    // 0x1ba7e4: 0x0  nop
    ctx->pc = 0x1ba7e4u;
    // NOP
    // 0x1ba7e8: 0x0  nop
    ctx->pc = 0x1ba7e8u;
    // NOP
    // 0x1ba7ec: 0x0  nop
    ctx->pc = 0x1ba7ecu;
    // NOP
    // 0x1ba7f0: 0x3c010031  lui         $at, 0x31
    ctx->pc = 0x1ba7f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)49 << 16));
    // 0x1ba7f4: 0x3c060031  lui         $a2, 0x31
    ctx->pc = 0x1ba7f4u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)49 << 16));
    // 0x1ba7f8: 0x90236570  lbu         $v1, 0x6570($at)
    ctx->pc = 0x1ba7f8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 25968)));
    // 0x1ba7fc: 0x1060000d  beqz        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x1BA7FCu;
    {
        const bool branch_taken_0x1ba7fc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA800u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA7FCu;
            // 0x1ba800: 0x24c66570  addiu       $a2, $a2, 0x6570 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 25968));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba7fc) {
            ctx->pc = 0x1BA834u;
            goto label_1ba834;
        }
    }
    ctx->pc = 0x1BA804u;
    // 0x1ba804: 0x28a10009  slti        $at, $a1, 0x9
    ctx->pc = 0x1ba804u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)9) ? 1 : 0);
    // 0x1ba808: 0x1020000a  beqz        $at, . + 4 + (0xA << 2)
    ctx->pc = 0x1BA808u;
    {
        const bool branch_taken_0x1ba808 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1BA80Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1BA808u;
            // 0x1ba80c: 0x3c030023  lui         $v1, 0x23 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)35 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ba808) {
            ctx->pc = 0x1BA834u;
            goto label_1ba834;
        }
    }
    ctx->pc = 0x1BA810u;
    // 0x1ba810: 0x52080  sll         $a0, $a1, 2
    ctx->pc = 0x1ba810u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 5), 2));
    // 0x1ba814: 0x24634da0  addiu       $v1, $v1, 0x4DA0
    ctx->pc = 0x1ba814u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19872));
    // 0x1ba818: 0x642021  addu        $a0, $v1, $a0
    ctx->pc = 0x1ba818u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1ba81c: 0x8c840000  lw          $a0, 0x0($a0)
    ctx->pc = 0x1ba81cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1ba820: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1ba820u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ba824: 0xacc40010  sw          $a0, 0x10($a2)
    ctx->pc = 0x1ba824u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 4));
    // 0x1ba828: 0xa4c0000e  sh          $zero, 0xE($a2)
    ctx->pc = 0x1ba828u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 14), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ba82c: 0xa4c3000c  sh          $v1, 0xC($a2)
    ctx->pc = 0x1ba82cu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 12), (uint16_t)GPR_U32(ctx, 3));
    // 0x1ba830: 0xa0c30001  sb          $v1, 0x1($a2)
    ctx->pc = 0x1ba830u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 1), (uint8_t)GPR_U32(ctx, 3));
label_1ba834:
    // 0x1ba834: 0x3e00008  jr          $ra
    ctx->pc = 0x1BA834u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BA784u: goto label_1ba784;
            case 0x1BA788u: goto label_1ba788;
            case 0x1BA7DCu: goto label_1ba7dc;
            case 0x1BA834u: goto label_1ba834;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BA83Cu;
    // 0x1ba83c: 0x0  nop
    ctx->pc = 0x1ba83cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
