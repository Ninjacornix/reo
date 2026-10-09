#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00113488
// Address: 0x113488 - 0x1137a0
void sub_00113488_0x113488(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00113488_0x113488");
#endif

    switch (ctx->pc) {
        case 0x1134c0u: goto label_1134c0;
        case 0x113500u: goto label_113500;
        case 0x113550u: goto label_113550;
        case 0x113580u: goto label_113580;
        case 0x1135c0u: goto label_1135c0;
        case 0x113624u: goto label_113624;
        case 0x11363cu: goto label_11363c;
        case 0x113654u: goto label_113654;
        case 0x11366cu: goto label_11366c;
        case 0x113684u: goto label_113684;
        case 0x11369cu: goto label_11369c;
        case 0x1136b4u: goto label_1136b4;
        case 0x1136ccu: goto label_1136cc;
        case 0x1136e4u: goto label_1136e4;
        case 0x1136fcu: goto label_1136fc;
        case 0x113714u: goto label_113714;
        default: break;
    }

    ctx->pc = 0x113488u;

    // 0x113488: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x113488u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11348c: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x11348cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113490: 0x148000a2  bnez        $a0, . + 4 + (0xA2 << 2)
    ctx->pc = 0x113490u;
    {
        const bool branch_taken_0x113490 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x113494u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113490u;
            // 0x113494: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113490) {
            ctx->pc = 0x11371Cu;
            goto label_11371c;
        }
    }
    ctx->pc = 0x113498u;
    // 0x113498: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x113498u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x11349c: 0x34429000  ori         $v0, $v0, 0x9000
    ctx->pc = 0x11349cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36864);
    // 0x1134a0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1134a0u;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x1134a4: 0x30630100  andi        $v1, $v1, 0x100
    ctx->pc = 0x1134a4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)256);
    // 0x1134a8: 0x1060000c  beqz        $v1, . + 4 + (0xC << 2)
    ctx->pc = 0x1134A8u;
    {
        const bool branch_taken_0x1134a8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1134ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1134A8u;
            // 0x1134ac: 0x3c031000  lui         $v1, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1134a8) {
            ctx->pc = 0x1134DCu;
            goto label_1134dc;
        }
    }
    ctx->pc = 0x1134B0u;
    // 0x1134b0: 0x3c040100  lui         $a0, 0x100
    ctx->pc = 0x1134b0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)256 << 16));
    // 0x1134b4: 0x34639000  ori         $v1, $v1, 0x9000
    ctx->pc = 0x1134b4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)36864);
    // 0x1134b8: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1134b8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1134bc: 0x0  nop
    ctx->pc = 0x1134bcu;
    // NOP
label_1134c0:
    // 0x1134c0: 0x82102b  sltu        $v0, $a0, $v0
    ctx->pc = 0x1134c0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1134c4: 0x14400047  bnez        $v0, . + 4 + (0x47 << 2)
    ctx->pc = 0x1134C4u;
    {
        const bool branch_taken_0x1134c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1134C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1134C4u;
            // 0x1134c8: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1134c4) {
            ctx->pc = 0x1135E4u;
            goto label_1135e4;
        }
    }
    ctx->pc = 0x1134CCu;
    // 0x1134cc: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1134ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1134d0: 0x30420100  andi        $v0, $v0, 0x100
    ctx->pc = 0x1134d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x1134d4: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1134D4u;
    {
        const bool branch_taken_0x1134d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1134D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1134D4u;
            // 0x1134d8: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1134d4) {
            ctx->pc = 0x1134C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1134c0;
        }
    }
    ctx->pc = 0x1134DCu;
label_1134dc:
    // 0x1134dc: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x1134dcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x1134e0: 0x3442a000  ori         $v0, $v0, 0xA000
    ctx->pc = 0x1134e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)40960);
    // 0x1134e4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1134e4u;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x1134e8: 0x30630100  andi        $v1, $v1, 0x100
    ctx->pc = 0x1134e8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)256);
    // 0x1134ec: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x1134ECu;
    {
        const bool branch_taken_0x1134ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1134F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1134ECu;
            // 0x1134f0: 0x3c031000  lui         $v1, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1134ec) {
            ctx->pc = 0x11351Cu;
            goto label_11351c;
        }
    }
    ctx->pc = 0x1134F4u;
    // 0x1134f4: 0x3c040100  lui         $a0, 0x100
    ctx->pc = 0x1134f4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)256 << 16));
    // 0x1134f8: 0x3463a000  ori         $v1, $v1, 0xA000
    ctx->pc = 0x1134f8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)40960);
    // 0x1134fc: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1134fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_113500:
    // 0x113500: 0x82102b  sltu        $v0, $a0, $v0
    ctx->pc = 0x113500u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x113504: 0x1440003a  bnez        $v0, . + 4 + (0x3A << 2)
    ctx->pc = 0x113504u;
    {
        const bool branch_taken_0x113504 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x113508u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113504u;
            // 0x113508: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113504) {
            ctx->pc = 0x1135F0u;
            goto label_1135f0;
        }
    }
    ctx->pc = 0x11350Cu;
    // 0x11350c: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x11350cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x113510: 0x30420100  andi        $v0, $v0, 0x100
    ctx->pc = 0x113510u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x113514: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x113514u;
    {
        const bool branch_taken_0x113514 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x113518u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113514u;
            // 0x113518: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113514) {
            ctx->pc = 0x113500u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_113500;
        }
    }
    ctx->pc = 0x11351Cu;
label_11351c:
    // 0x11351c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x11351cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x113520: 0x3c041f00  lui         $a0, 0x1F00
    ctx->pc = 0x113520u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)7936 << 16));
    // 0x113524: 0x34423c00  ori         $v0, $v0, 0x3C00
    ctx->pc = 0x113524u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)15360);
    // 0x113528: 0x34840003  ori         $a0, $a0, 0x3
    ctx->pc = 0x113528u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)3);
    // 0x11352c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x11352cu;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x113530: 0x641824  and         $v1, $v1, $a0
    ctx->pc = 0x113530u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 4));
    // 0x113534: 0x1060000d  beqz        $v1, . + 4 + (0xD << 2)
    ctx->pc = 0x113534u;
    {
        const bool branch_taken_0x113534 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x113538u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113534u;
            // 0x113538: 0x3c031f00  lui         $v1, 0x1F00 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)7936 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113534) {
            ctx->pc = 0x11356Cu;
            goto label_11356c;
        }
    }
    ctx->pc = 0x11353Cu;
    // 0x11353c: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x11353cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x113540: 0x3c060100  lui         $a2, 0x100
    ctx->pc = 0x113540u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)256 << 16));
    // 0x113544: 0x34843c00  ori         $a0, $a0, 0x3C00
    ctx->pc = 0x113544u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)15360);
    // 0x113548: 0x34630003  ori         $v1, $v1, 0x3
    ctx->pc = 0x113548u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)3);
    // 0x11354c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x11354cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_113550:
    // 0x113550: 0xc2102b  sltu        $v0, $a2, $v0
    ctx->pc = 0x113550u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 6) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x113554: 0x14400029  bnez        $v0, . + 4 + (0x29 << 2)
    ctx->pc = 0x113554u;
    {
        const bool branch_taken_0x113554 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x113558u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113554u;
            // 0x113558: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113554) {
            ctx->pc = 0x1135FCu;
            goto label_1135fc;
        }
    }
    ctx->pc = 0x11355Cu;
    // 0x11355c: 0x8c820000  lw          $v0, 0x0($a0)
    ctx->pc = 0x11355cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x113560: 0x431024  and         $v0, $v0, $v1
    ctx->pc = 0x113560u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & GPR_U64(ctx, 3));
    // 0x113564: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x113564u;
    {
        const bool branch_taken_0x113564 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x113568u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113564u;
            // 0x113568: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113564) {
            ctx->pc = 0x113550u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_113550;
        }
    }
    ctx->pc = 0x11356Cu;
label_11356c:
    // 0x11356c: 0x4846e800  cfc2.ni     $a2, $vi29
    ctx->pc = 0x11356cu;
    SET_GPR_U32(ctx, 6, ctx->vu0_top);
    // 0x113570: 0x30c20100  andi        $v0, $a2, 0x100
    ctx->pc = 0x113570u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)256);
    // 0x113574: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x113574u;
    {
        const bool branch_taken_0x113574 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x113578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113574u;
            // 0x113578: 0x3c030100  lui         $v1, 0x100 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)256 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113574) {
            ctx->pc = 0x11359Cu;
            goto label_11359c;
        }
    }
    ctx->pc = 0x11357Cu;
    // 0x11357c: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x11357cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_113580:
    // 0x113580: 0x62102b  sltu        $v0, $v1, $v0
    ctx->pc = 0x113580u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x113584: 0x14400020  bnez        $v0, . + 4 + (0x20 << 2)
    ctx->pc = 0x113584u;
    {
        const bool branch_taken_0x113584 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x113588u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113584u;
            // 0x113588: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113584) {
            ctx->pc = 0x113608u;
            goto label_113608;
        }
    }
    ctx->pc = 0x11358Cu;
    // 0x11358c: 0x4846e800  cfc2.ni     $a2, $vi29
    ctx->pc = 0x11358cu;
    SET_GPR_U32(ctx, 6, ctx->vu0_top);
    // 0x113590: 0x30c20100  andi        $v0, $a2, 0x100
    ctx->pc = 0x113590u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)256);
    // 0x113594: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x113594u;
    {
        const bool branch_taken_0x113594 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x113598u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113594u;
            // 0x113598: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113594) {
            ctx->pc = 0x113580u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_113580;
        }
    }
    ctx->pc = 0x11359Cu;
label_11359c:
    // 0x11359c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x11359cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x1135a0: 0x34423020  ori         $v0, $v0, 0x3020
    ctx->pc = 0x1135a0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)12320);
    // 0x1135a4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1135a4u;
    SET_GPR_S32(ctx, 3, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x1135a8: 0x30630c00  andi        $v1, $v1, 0xC00
    ctx->pc = 0x1135a8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)3072);
    // 0x1135ac: 0x1060000b  beqz        $v1, . + 4 + (0xB << 2)
    ctx->pc = 0x1135ACu;
    {
        const bool branch_taken_0x1135ac = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1135B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1135ACu;
            // 0x1135b0: 0x3c031000  lui         $v1, 0x1000 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1135ac) {
            ctx->pc = 0x1135DCu;
            goto label_1135dc;
        }
    }
    ctx->pc = 0x1135B4u;
    // 0x1135b4: 0x3c040100  lui         $a0, 0x100
    ctx->pc = 0x1135b4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)256 << 16));
    // 0x1135b8: 0x34633020  ori         $v1, $v1, 0x3020
    ctx->pc = 0x1135b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)12320);
    // 0x1135bc: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1135bcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_1135c0:
    // 0x1135c0: 0x82102b  sltu        $v0, $a0, $v0
    ctx->pc = 0x1135c0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 4) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1135c4: 0x14400013  bnez        $v0, . + 4 + (0x13 << 2)
    ctx->pc = 0x1135C4u;
    {
        const bool branch_taken_0x1135c4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1135C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1135C4u;
            // 0x1135c8: 0x24a50001  addiu       $a1, $a1, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1135c4) {
            ctx->pc = 0x113614u;
            goto label_113614;
        }
    }
    ctx->pc = 0x1135CCu;
    // 0x1135cc: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x1135ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1135d0: 0x30420c00  andi        $v0, $v0, 0xC00
    ctx->pc = 0x1135d0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)3072);
    // 0x1135d4: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x1135D4u;
    {
        const bool branch_taken_0x1135d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1135D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1135D4u;
            // 0x1135d8: 0xa0102d  daddu       $v0, $a1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1135d4) {
            ctx->pc = 0x1135C0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1135c0;
        }
    }
    ctx->pc = 0x1135DCu;
label_1135dc:
    // 0x1135dc: 0x1000006c  b           . + 4 + (0x6C << 2)
    ctx->pc = 0x1135DCu;
    {
        const bool branch_taken_0x1135dc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1135E0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1135DCu;
            // 0x1135e0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1135dc) {
            ctx->pc = 0x113790u;
            goto label_113790;
        }
    }
    ctx->pc = 0x1135E4u;
label_1135e4:
    // 0x1135e4: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1135e4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1135e8: 0x1000000c  b           . + 4 + (0xC << 2)
    ctx->pc = 0x1135E8u;
    {
        const bool branch_taken_0x1135e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1135ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1135E8u;
            // 0x1135ec: 0x24848630  addiu       $a0, $a0, -0x79D0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936112));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1135e8) {
            ctx->pc = 0x11361Cu;
            goto label_11361c;
        }
    }
    ctx->pc = 0x1135F0u;
label_1135f0:
    // 0x1135f0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1135f0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1135f4: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1135F4u;
    {
        const bool branch_taken_0x1135f4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1135F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1135F4u;
            // 0x1135f8: 0x24848710  addiu       $a0, $a0, -0x78F0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936336));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1135f4) {
            ctx->pc = 0x11361Cu;
            goto label_11361c;
        }
    }
    ctx->pc = 0x1135FCu;
label_1135fc:
    // 0x1135fc: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1135fcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x113600: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x113600u;
    {
        const bool branch_taken_0x113600 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x113604u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113600u;
            // 0x113604: 0x24848740  addiu       $a0, $a0, -0x78C0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936384));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113600) {
            ctx->pc = 0x11361Cu;
            goto label_11361c;
        }
    }
    ctx->pc = 0x113608u;
label_113608:
    // 0x113608: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x113608u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x11360c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x11360Cu;
    {
        const bool branch_taken_0x11360c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x113610u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x11360Cu;
            // 0x113610: 0x24848770  addiu       $a0, $a0, -0x7890 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936432));
        ctx->in_delay_slot = false;
        if (branch_taken_0x11360c) {
            ctx->pc = 0x11361Cu;
            goto label_11361c;
        }
    }
    ctx->pc = 0x113614u;
label_113614:
    // 0x113614: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x113614u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x113618: 0x24848798  addiu       $a0, $a0, -0x7868
    ctx->pc = 0x113618u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936472));
label_11361c:
    // 0x11361c: 0xc045a12  jal         func_116848
    ctx->pc = 0x11361Cu;
    SET_GPR_U32(ctx, 31, 0x113624u);
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113624u; }
        if (ctx->pc != 0x113624u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113624u; }
        if (ctx->pc != 0x113624u) { return; }
    }
    ctx->pc = 0x113624u;
label_113624:
    // 0x113624: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x113624u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x113628: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x113628u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x11362c: 0x34429000  ori         $v0, $v0, 0x9000
    ctx->pc = 0x11362cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36864);
    // 0x113630: 0x24848660  addiu       $a0, $a0, -0x79A0
    ctx->pc = 0x113630u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936160));
    // 0x113634: 0xc045a12  jal         func_116848
    ctx->pc = 0x113634u;
    SET_GPR_U32(ctx, 31, 0x11363Cu);
    ctx->pc = 0x113638u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x113634u;
            // 0x113638: 0x8c450000  lw          $a1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11363Cu; }
        if (ctx->pc != 0x11363Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11363Cu; }
        if (ctx->pc != 0x11363Cu) { return; }
    }
    ctx->pc = 0x11363Cu;
label_11363c:
    // 0x11363c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x11363cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x113640: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x113640u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x113644: 0x34429030  ori         $v0, $v0, 0x9030
    ctx->pc = 0x113644u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36912);
    // 0x113648: 0x24848670  addiu       $a0, $a0, -0x7990
    ctx->pc = 0x113648u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936176));
    // 0x11364c: 0xc045a12  jal         func_116848
    ctx->pc = 0x11364Cu;
    SET_GPR_U32(ctx, 31, 0x113654u);
    ctx->pc = 0x113650u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11364Cu;
            // 0x113650: 0x8c450000  lw          $a1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113654u; }
        if (ctx->pc != 0x113654u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113654u; }
        if (ctx->pc != 0x113654u) { return; }
    }
    ctx->pc = 0x113654u;
label_113654:
    // 0x113654: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x113654u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x113658: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x113658u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x11365c: 0x34429010  ori         $v0, $v0, 0x9010
    ctx->pc = 0x11365cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36880);
    // 0x113660: 0x24848680  addiu       $a0, $a0, -0x7980
    ctx->pc = 0x113660u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936192));
    // 0x113664: 0xc045a12  jal         func_116848
    ctx->pc = 0x113664u;
    SET_GPR_U32(ctx, 31, 0x11366Cu);
    ctx->pc = 0x113668u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x113664u;
            // 0x113668: 0x8c450000  lw          $a1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11366Cu; }
        if (ctx->pc != 0x11366Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11366Cu; }
        if (ctx->pc != 0x11366Cu) { return; }
    }
    ctx->pc = 0x11366Cu;
label_11366c:
    // 0x11366c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x11366cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x113670: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x113670u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x113674: 0x34429020  ori         $v0, $v0, 0x9020
    ctx->pc = 0x113674u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)36896);
    // 0x113678: 0x24848690  addiu       $a0, $a0, -0x7970
    ctx->pc = 0x113678u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936208));
    // 0x11367c: 0xc045a12  jal         func_116848
    ctx->pc = 0x11367Cu;
    SET_GPR_U32(ctx, 31, 0x113684u);
    ctx->pc = 0x113680u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11367Cu;
            // 0x113680: 0x8c450000  lw          $a1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113684u; }
        if (ctx->pc != 0x113684u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113684u; }
        if (ctx->pc != 0x113684u) { return; }
    }
    ctx->pc = 0x113684u;
label_113684:
    // 0x113684: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x113684u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x113688: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x113688u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x11368c: 0x3442a000  ori         $v0, $v0, 0xA000
    ctx->pc = 0x11368cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)40960);
    // 0x113690: 0x248486a0  addiu       $a0, $a0, -0x7960
    ctx->pc = 0x113690u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936224));
    // 0x113694: 0xc045a12  jal         func_116848
    ctx->pc = 0x113694u;
    SET_GPR_U32(ctx, 31, 0x11369Cu);
    ctx->pc = 0x113698u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x113694u;
            // 0x113698: 0x8c450000  lw          $a1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11369Cu; }
        if (ctx->pc != 0x11369Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11369Cu; }
        if (ctx->pc != 0x11369Cu) { return; }
    }
    ctx->pc = 0x11369Cu;
label_11369c:
    // 0x11369c: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x11369cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x1136a0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1136a0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1136a4: 0x3442a030  ori         $v0, $v0, 0xA030
    ctx->pc = 0x1136a4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)41008);
    // 0x1136a8: 0x248486b0  addiu       $a0, $a0, -0x7950
    ctx->pc = 0x1136a8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936240));
    // 0x1136ac: 0xc045a12  jal         func_116848
    ctx->pc = 0x1136ACu;
    SET_GPR_U32(ctx, 31, 0x1136B4u);
    ctx->pc = 0x1136B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1136ACu;
            // 0x1136b0: 0x8c450000  lw          $a1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1136B4u; }
        if (ctx->pc != 0x1136B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1136B4u; }
        if (ctx->pc != 0x1136B4u) { return; }
    }
    ctx->pc = 0x1136B4u;
label_1136b4:
    // 0x1136b4: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x1136b4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x1136b8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1136b8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1136bc: 0x3442a010  ori         $v0, $v0, 0xA010
    ctx->pc = 0x1136bcu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)40976);
    // 0x1136c0: 0x248486c0  addiu       $a0, $a0, -0x7940
    ctx->pc = 0x1136c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936256));
    // 0x1136c4: 0xc045a12  jal         func_116848
    ctx->pc = 0x1136C4u;
    SET_GPR_U32(ctx, 31, 0x1136CCu);
    ctx->pc = 0x1136C8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1136C4u;
            // 0x1136c8: 0x8c450000  lw          $a1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1136CCu; }
        if (ctx->pc != 0x1136CCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1136CCu; }
        if (ctx->pc != 0x1136CCu) { return; }
    }
    ctx->pc = 0x1136CCu;
label_1136cc:
    // 0x1136cc: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x1136ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x1136d0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1136d0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1136d4: 0x3442a020  ori         $v0, $v0, 0xA020
    ctx->pc = 0x1136d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)40992);
    // 0x1136d8: 0x248486d0  addiu       $a0, $a0, -0x7930
    ctx->pc = 0x1136d8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936272));
    // 0x1136dc: 0xc045a12  jal         func_116848
    ctx->pc = 0x1136DCu;
    SET_GPR_U32(ctx, 31, 0x1136E4u);
    ctx->pc = 0x1136E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1136DCu;
            // 0x1136e0: 0x8c450000  lw          $a1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1136E4u; }
        if (ctx->pc != 0x1136E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1136E4u; }
        if (ctx->pc != 0x1136E4u) { return; }
    }
    ctx->pc = 0x1136E4u;
label_1136e4:
    // 0x1136e4: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x1136e4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x1136e8: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1136e8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1136ec: 0x34423c00  ori         $v0, $v0, 0x3C00
    ctx->pc = 0x1136ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)15360);
    // 0x1136f0: 0x248486e0  addiu       $a0, $a0, -0x7920
    ctx->pc = 0x1136f0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936288));
    // 0x1136f4: 0xc045a12  jal         func_116848
    ctx->pc = 0x1136F4u;
    SET_GPR_U32(ctx, 31, 0x1136FCu);
    ctx->pc = 0x1136F8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1136F4u;
            // 0x1136f8: 0x8c450000  lw          $a1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1136FCu; }
        if (ctx->pc != 0x1136FCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1136FCu; }
        if (ctx->pc != 0x1136FCu) { return; }
    }
    ctx->pc = 0x1136FCu;
label_1136fc:
    // 0x1136fc: 0x3c021000  lui         $v0, 0x1000
    ctx->pc = 0x1136fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)4096 << 16));
    // 0x113700: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x113700u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x113704: 0x34423020  ori         $v0, $v0, 0x3020
    ctx->pc = 0x113704u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)12320);
    // 0x113708: 0x248486f8  addiu       $a0, $a0, -0x7908
    ctx->pc = 0x113708u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294936312));
    // 0x11370c: 0xc045a12  jal         func_116848
    ctx->pc = 0x11370Cu;
    SET_GPR_U32(ctx, 31, 0x113714u);
    ctx->pc = 0x113710u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x11370Cu;
            // 0x113710: 0x8c450000  lw          $a1, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x116848u;
    if (runtime->hasFunction(0x116848u)) {
        auto targetFn = runtime->lookupFunction(0x116848u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113714u; }
        if (ctx->pc != 0x113714u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113714u; }
        if (ctx->pc != 0x113714u) { return; }
    }
    ctx->pc = 0x113714u;
label_113714:
    // 0x113714: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x113714u;
    {
        const bool branch_taken_0x113714 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x113718u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113714u;
            // 0x113718: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x113714) {
            ctx->pc = 0x113790u;
            goto label_113790;
        }
    }
    ctx->pc = 0x11371Cu;
label_11371c:
    // 0x11371c: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x11371cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x113720: 0x3c051000  lui         $a1, 0x1000
    ctx->pc = 0x113720u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4096 << 16));
    // 0x113724: 0x34639000  ori         $v1, $v1, 0x9000
    ctx->pc = 0x113724u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)36864);
    // 0x113728: 0x34a5a000  ori         $a1, $a1, 0xA000
    ctx->pc = 0x113728u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | (uint64_t)(uint16_t)40960);
    // 0x11372c: 0x8c620000  lw          $v0, 0x0($v1)
    ctx->pc = 0x11372cu;
    SET_GPR_S32(ctx, 2, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x113730: 0x3c041000  lui         $a0, 0x1000
    ctx->pc = 0x113730u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)4096 << 16));
    // 0x113734: 0x8ca60000  lw          $a2, 0x0($a1)
    ctx->pc = 0x113734u;
    SET_GPR_S32(ctx, 6, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0))); // MMIO: 0x10000000
    // 0x113738: 0x34843c00  ori         $a0, $a0, 0x3C00
    ctx->pc = 0x113738u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | (uint64_t)(uint16_t)15360);
    // 0x11373c: 0x30420100  andi        $v0, $v0, 0x100
    ctx->pc = 0x11373cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)256);
    // 0x113740: 0x8c850000  lw          $a1, 0x0($a0)
    ctx->pc = 0x113740u;
    SET_GPR_S32(ctx, 5, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0))); // MMIO: 0x10000000
    // 0x113744: 0x2102b  sltu        $v0, $zero, $v0
    ctx->pc = 0x113744u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x113748: 0x30c60100  andi        $a2, $a2, 0x100
    ctx->pc = 0x113748u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)256);
    // 0x11374c: 0x34440002  ori         $a0, $v0, 0x2
    ctx->pc = 0x11374cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)2);
    // 0x113750: 0x3c031f00  lui         $v1, 0x1F00
    ctx->pc = 0x113750u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)7936 << 16));
    // 0x113754: 0x86100b  movn        $v0, $a0, $a2
    ctx->pc = 0x113754u;
    if (GPR_U64(ctx, 6) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
    // 0x113758: 0x34630003  ori         $v1, $v1, 0x3
    ctx->pc = 0x113758u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)3);
    // 0x11375c: 0xa32824  and         $a1, $a1, $v1
    ctx->pc = 0x11375cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) & GPR_U64(ctx, 3));
    // 0x113760: 0x34440004  ori         $a0, $v0, 0x4
    ctx->pc = 0x113760u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)4);
    // 0x113764: 0x85100b  movn        $v0, $a0, $a1
    ctx->pc = 0x113764u;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 4));
    // 0x113768: 0x4846e800  cfc2.ni     $a2, $vi29
    ctx->pc = 0x113768u;
    SET_GPR_U32(ctx, 6, ctx->vu0_top);
    // 0x11376c: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x11376cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x113770: 0x30c60100  andi        $a2, $a2, 0x100
    ctx->pc = 0x113770u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)256);
    // 0x113774: 0x34633020  ori         $v1, $v1, 0x3020
    ctx->pc = 0x113774u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)12320);
    // 0x113778: 0x34450008  ori         $a1, $v0, 0x8
    ctx->pc = 0x113778u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)8);
    // 0x11377c: 0x8c640000  lw          $a0, 0x0($v1)
    ctx->pc = 0x11377cu;
    SET_GPR_S32(ctx, 4, (int32_t)runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x113780: 0xa6100b  movn        $v0, $a1, $a2
    ctx->pc = 0x113780u;
    if (GPR_U64(ctx, 6) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 5));
    // 0x113784: 0x34430010  ori         $v1, $v0, 0x10
    ctx->pc = 0x113784u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)16);
    // 0x113788: 0x30840c00  andi        $a0, $a0, 0xC00
    ctx->pc = 0x113788u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)3072);
    // 0x11378c: 0x64100b  movn        $v0, $v1, $a0
    ctx->pc = 0x11378cu;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
label_113790:
    // 0x113790: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x113790u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x113794: 0x3e00008  jr          $ra
    ctx->pc = 0x113794u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x113798u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x113794u;
            // 0x113798: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1134C0u: goto label_1134c0;
            case 0x1134DCu: goto label_1134dc;
            case 0x113500u: goto label_113500;
            case 0x11351Cu: goto label_11351c;
            case 0x113550u: goto label_113550;
            case 0x11356Cu: goto label_11356c;
            case 0x113580u: goto label_113580;
            case 0x11359Cu: goto label_11359c;
            case 0x1135C0u: goto label_1135c0;
            case 0x1135DCu: goto label_1135dc;
            case 0x1135E4u: goto label_1135e4;
            case 0x1135F0u: goto label_1135f0;
            case 0x1135FCu: goto label_1135fc;
            case 0x113608u: goto label_113608;
            case 0x113614u: goto label_113614;
            case 0x11361Cu: goto label_11361c;
            case 0x113624u: goto label_113624;
            case 0x11363Cu: goto label_11363c;
            case 0x113654u: goto label_113654;
            case 0x11366Cu: goto label_11366c;
            case 0x113684u: goto label_113684;
            case 0x11369Cu: goto label_11369c;
            case 0x1136B4u: goto label_1136b4;
            case 0x1136CCu: goto label_1136cc;
            case 0x1136E4u: goto label_1136e4;
            case 0x1136FCu: goto label_1136fc;
            case 0x113714u: goto label_113714;
            case 0x11371Cu: goto label_11371c;
            case 0x113790u: goto label_113790;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11379Cu;
    // 0x11379c: 0x0  nop
    ctx->pc = 0x11379cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
