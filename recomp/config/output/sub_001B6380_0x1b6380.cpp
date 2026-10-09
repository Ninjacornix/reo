#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001B6380
// Address: 0x1b6380 - 0x1b6460
void sub_001B6380_0x1b6380(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001B6380_0x1b6380");
#endif

    ctx->pc = 0x1b6380u;

    // 0x1b6380: 0x41202  srl         $v0, $a0, 8
    ctx->pc = 0x1b6380u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 4), 8));
    // 0x1b6384: 0x304500ff  andi        $a1, $v0, 0xFF
    ctx->pc = 0x1b6384u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)255);
    // 0x1b6388: 0x28a20081  slti        $v0, $a1, 0x81
    ctx->pc = 0x1b6388u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)129) ? 1 : 0);
    // 0x1b638c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B638Cu;
    {
        const bool branch_taken_0x1b638c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B6390u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B638Cu;
            // 0x1b6390: 0x308400ff  andi        $a0, $a0, 0xFF (Delay Slot)
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)255);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b638c) {
            ctx->pc = 0x1B63A8u;
            goto label_1b63a8;
        }
    }
    ctx->pc = 0x1B6394u;
    // 0x1b6394: 0x28a100a0  slti        $at, $a1, 0xA0
    ctx->pc = 0x1b6394u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)160) ? 1 : 0);
    // 0x1b6398: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B6398u;
    {
        const bool branch_taken_0x1b6398 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B639Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6398u;
            // 0x1b639c: 0x28a200e0  slti        $v0, $a1, 0xE0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)224) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6398) {
            ctx->pc = 0x1B63ACu;
            goto label_1b63ac;
        }
    }
    ctx->pc = 0x1B63A0u;
    // 0x1b63a0: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1B63A0u;
    {
        const bool branch_taken_0x1b63a0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B63A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B63A0u;
            // 0x1b63a4: 0x24a5ff7f  addiu       $a1, $a1, -0x81 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967167));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b63a0) {
            ctx->pc = 0x1B63C8u;
            goto label_1b63c8;
        }
    }
    ctx->pc = 0x1B63A8u;
label_1b63a8:
    // 0x1b63a8: 0x28a200e0  slti        $v0, $a1, 0xE0
    ctx->pc = 0x1b63a8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)224) ? 1 : 0);
label_1b63ac:
    // 0x1b63ac: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1B63ACu;
    {
        const bool branch_taken_0x1b63ac = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B63B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B63ACu;
            // 0x1b63b0: 0x4183c  dsll32      $v1, $a0, 0 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b63ac) {
            ctx->pc = 0x1B63CCu;
            goto label_1b63cc;
        }
    }
    ctx->pc = 0x1B63B4u;
    // 0x1b63b4: 0x28a100f0  slti        $at, $a1, 0xF0
    ctx->pc = 0x1b63b4u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)240) ? 1 : 0);
    // 0x1b63b8: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1B63B8u;
    {
        const bool branch_taken_0x1b63b8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B63BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B63B8u;
            // 0x1b63bc: 0x64a2ff3f  daddiu      $v0, $a1, -0xC1 (Delay Slot)
        SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 5) + (int64_t)(int32_t)4294967103);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b63b8) {
            ctx->pc = 0x1B63C8u;
            goto label_1b63c8;
        }
    }
    ctx->pc = 0x1B63C0u;
    // 0x1b63c0: 0x2283c  dsll32      $a1, $v0, 0
    ctx->pc = 0x1b63c0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b63c4: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x1b63c4u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
label_1b63c8:
    // 0x1b63c8: 0x4183c  dsll32      $v1, $a0, 0
    ctx->pc = 0x1b63c8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) << (32 + 0));
label_1b63cc:
    // 0x1b63cc: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x1b63ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x1b63d0: 0x28620040  slti        $v0, $v1, 0x40
    ctx->pc = 0x1b63d0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)64) ? 1 : 0);
    // 0x1b63d4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1B63D4u;
    {
        const bool branch_taken_0x1b63d4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B63D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B63D4u;
            // 0x1b63d8: 0x52840  sll         $a1, $a1, 1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b63d4) {
            ctx->pc = 0x1B63F0u;
            goto label_1b63f0;
        }
    }
    ctx->pc = 0x1B63DCu;
    // 0x1b63dc: 0x2861007f  slti        $at, $v1, 0x7F
    ctx->pc = 0x1b63dcu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)127) ? 1 : 0);
    // 0x1b63e0: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B63E0u;
    {
        const bool branch_taken_0x1b63e0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B63E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B63E0u;
            // 0x1b63e4: 0x28620080  slti        $v0, $v1, 0x80 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)128) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b63e0) {
            ctx->pc = 0x1B63F4u;
            goto label_1b63f4;
        }
    }
    ctx->pc = 0x1B63E8u;
    // 0x1b63e8: 0x10000011  b           . + 4 + (0x11 << 2)
    ctx->pc = 0x1B63E8u;
    {
        const bool branch_taken_0x1b63e8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B63ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B63E8u;
            // 0x1b63ec: 0x2484ffc0  addiu       $a0, $a0, -0x40 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967232));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b63e8) {
            ctx->pc = 0x1B6430u;
            goto label_1b6430;
        }
    }
    ctx->pc = 0x1B63F0u;
label_1b63f0:
    // 0x1b63f0: 0x28620080  slti        $v0, $v1, 0x80
    ctx->pc = 0x1b63f0u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)128) ? 1 : 0);
label_1b63f4:
    // 0x1b63f4: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1B63F4u;
    {
        const bool branch_taken_0x1b63f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B63F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B63F4u;
            // 0x1b63f8: 0x2862009f  slti        $v0, $v1, 0x9F (Delay Slot)
        SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)159) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b63f4) {
            ctx->pc = 0x1B6418u;
            goto label_1b6418;
        }
    }
    ctx->pc = 0x1B63FCu;
    // 0x1b63fc: 0x2861009f  slti        $at, $v1, 0x9F
    ctx->pc = 0x1b63fcu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)159) ? 1 : 0);
    // 0x1b6400: 0x10200005  beqz        $at, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B6400u;
    {
        const bool branch_taken_0x1b6400 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1b6400) {
            ctx->pc = 0x1B6418u;
            goto label_1b6418;
        }
    }
    ctx->pc = 0x1B6408u;
    // 0x1b6408: 0x6462ffbf  daddiu      $v0, $v1, -0x41
    ctx->pc = 0x1b6408u;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 3) + (int64_t)(int32_t)4294967231);
    // 0x1b640c: 0x2203c  dsll32      $a0, $v0, 0
    ctx->pc = 0x1b640cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b6410: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1B6410u;
    {
        const bool branch_taken_0x1b6410 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6414u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6410u;
            // 0x1b6414: 0x4203f  dsra32      $a0, $a0, 0 (Delay Slot)
        SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6410) {
            ctx->pc = 0x1B6430u;
            goto label_1b6430;
        }
    }
    ctx->pc = 0x1B6418u;
label_1b6418:
    // 0x1b6418: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1B6418u;
    {
        const bool branch_taken_0x1b6418 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1B641Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6418u;
            // 0x1b641c: 0x286100fd  slti        $at, $v1, 0xFD (Delay Slot)
        SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)253) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6418) {
            ctx->pc = 0x1B6430u;
            goto label_1b6430;
        }
    }
    ctx->pc = 0x1B6420u;
    // 0x1b6420: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1B6420u;
    {
        const bool branch_taken_0x1b6420 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1B6424u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6420u;
            // 0x1b6424: 0x5183c  dsll32      $v1, $a1, 0 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) << (32 + 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1b6420) {
            ctx->pc = 0x1B6434u;
            goto label_1b6434;
        }
    }
    ctx->pc = 0x1B6428u;
    // 0x1b6428: 0x2484ff61  addiu       $a0, $a0, -0x9F
    ctx->pc = 0x1b6428u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294967137));
    // 0x1b642c: 0x24a50001  addiu       $a1, $a1, 0x1
    ctx->pc = 0x1b642cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 1));
label_1b6430:
    // 0x1b6430: 0x5183c  dsll32      $v1, $a1, 0
    ctx->pc = 0x1b6430u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) << (32 + 0));
label_1b6434:
    // 0x1b6434: 0x4103c  dsll32      $v0, $a0, 0
    ctx->pc = 0x1b6434u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) << (32 + 0));
    // 0x1b6438: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x1b6438u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x1b643c: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x1b643cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1b6440: 0x64630001  daddiu      $v1, $v1, 0x1
    ctx->pc = 0x1b6440u;
    SET_GPR_S64(ctx, 3, (int64_t)GPR_S64(ctx, 3) + (int64_t)(int32_t)1);
    // 0x1b6444: 0x31a38  dsll        $v1, $v1, 8
    ctx->pc = 0x1b6444u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 8);
    // 0x1b6448: 0x62102d  daddu       $v0, $v1, $v0
    ctx->pc = 0x1b6448u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 2));
    // 0x1b644c: 0x64422021  daddiu      $v0, $v0, 0x2021
    ctx->pc = 0x1b644cu;
    SET_GPR_S64(ctx, 2, (int64_t)GPR_S64(ctx, 2) + (int64_t)(int32_t)8225);
    // 0x1b6450: 0x2103c  dsll32      $v0, $v0, 0
    ctx->pc = 0x1b6450u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b6454: 0x3e00008  jr          $ra
    ctx->pc = 0x1B6454u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B6458u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1B6454u;
            // 0x1b6458: 0x2103f  dsra32      $v0, $v0, 0 (Delay Slot)
        SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B63A8u: goto label_1b63a8;
            case 0x1B63ACu: goto label_1b63ac;
            case 0x1B63C8u: goto label_1b63c8;
            case 0x1B63CCu: goto label_1b63cc;
            case 0x1B63F0u: goto label_1b63f0;
            case 0x1B63F4u: goto label_1b63f4;
            case 0x1B6418u: goto label_1b6418;
            case 0x1B6430u: goto label_1b6430;
            case 0x1B6434u: goto label_1b6434;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B645Cu;
    // 0x1b645c: 0x0  nop
    ctx->pc = 0x1b645cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
