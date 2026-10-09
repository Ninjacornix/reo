#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001492D8
// Address: 0x1492d8 - 0x14a850
void sub_001492D8_0x1492d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001492D8_0x1492d8");
#endif

    switch (ctx->pc) {
        case 0x149320u: goto label_149320;
        case 0x149330u: goto label_149330;
        default: break;
    }

    ctx->pc = 0x1492d8u;

    // 0x1492d8: 0xa0482d  daddu       $t1, $a1, $zero
    ctx->pc = 0x1492d8u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1492dc: 0xc0402d  daddu       $t0, $a2, $zero
    ctx->pc = 0x1492dcu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1492e0: 0x8d230010  lw          $v1, 0x10($t1)
    ctx->pc = 0x1492e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 16)));
    // 0x1492e4: 0x8d250014  lw          $a1, 0x14($t1)
    ctx->pc = 0x1492e4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 20)));
    // 0x1492e8: 0x28620000  slti        $v0, $v1, 0x0
    ctx->pc = 0x1492e8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1492ec: 0x2466000f  addiu       $a2, $v1, 0xF
    ctx->pc = 0x1492ecu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), 15));
    // 0x1492f0: 0xc2180b  movn        $v1, $a2, $v0
    ctx->pc = 0x1492f0u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 6));
    // 0x1492f4: 0x28a20000  slti        $v0, $a1, 0x0
    ctx->pc = 0x1492f4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x1492f8: 0x24a7000f  addiu       $a3, $a1, 0xF
    ctx->pc = 0x1492f8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 5), 15));
    // 0x1492fc: 0x31903  sra         $v1, $v1, 4
    ctx->pc = 0x1492fcu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 4));
    // 0x149300: 0xe2280b  movn        $a1, $a3, $v0
    ctx->pc = 0x149300u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 7));
    // 0x149304: 0x8c870000  lw          $a3, 0x0($a0)
    ctx->pc = 0x149304u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x149308: 0x52903  sra         $a1, $a1, 4
    ctx->pc = 0x149308u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 4));
    // 0x14930c: 0x1860054d  blez        $v1, . + 4 + (0x54D << 2)
    ctx->pc = 0x14930Cu;
    {
        const bool branch_taken_0x14930c = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x149310u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14930Cu;
            // 0x149310: 0x8d2b0004  lw          $t3, 0x4($t1) (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 4)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14930c) {
            ctx->pc = 0x14A844u;
            goto label_14a844;
        }
    }
    ctx->pc = 0x149314u;
    // 0x149314: 0x60602d  daddu       $t4, $v1, $zero
    ctx->pc = 0x149314u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x149318: 0x56a80  sll         $t5, $a1, 10
    ctx->pc = 0x149318u;
    SET_GPR_S32(ctx, 13, (int32_t)SLL32(GPR_U32(ctx, 5), 10));
    // 0x14931c: 0x0  nop
    ctx->pc = 0x14931cu;
    // NOP
label_149320:
    // 0x149320: 0x160302d  daddu       $a2, $t3, $zero
    ctx->pc = 0x149320u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x149324: 0x18a00544  blez        $a1, . + 4 + (0x544 << 2)
    ctx->pc = 0x149324u;
    {
        const bool branch_taken_0x149324 = (GPR_S64(ctx, 5) <= 0);
        ctx->pc = 0x149328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x149324u;
            // 0x149328: 0xed3821  addu        $a3, $a3, $t5 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 13)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x149324) {
            ctx->pc = 0x14A838u;
            goto label_14a838;
        }
    }
    ctx->pc = 0x14932Cu;
    // 0x14932c: 0xa0502d  daddu       $t2, $a1, $zero
    ctx->pc = 0x14932cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_149330:
    // 0x149330: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x149330u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x149334: 0x254affff  addiu       $t2, $t2, -0x1
    ctx->pc = 0x149334u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 4294967295));
    // 0x149338: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149338u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14933c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14933cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149340: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149340u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149344: 0xacc30000  sw          $v1, 0x0($a2)
    ctx->pc = 0x149344u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 3));
    // 0x149348: 0x90e20004  lbu         $v0, 0x4($a3)
    ctx->pc = 0x149348u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x14934c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14934cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149350: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149350u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149354: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149354u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149358: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x149358u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x14935c: 0x90e20008  lbu         $v0, 0x8($a3)
    ctx->pc = 0x14935cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x149360: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149360u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149364: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149364u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149368: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149368u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14936c: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x14936cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x149370: 0x90e2000c  lbu         $v0, 0xC($a3)
    ctx->pc = 0x149370u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x149374: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149374u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149378: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149378u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14937c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14937cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149380: 0xacc3000c  sw          $v1, 0xC($a2)
    ctx->pc = 0x149380u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 3));
    // 0x149384: 0x90e20010  lbu         $v0, 0x10($a3)
    ctx->pc = 0x149384u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x149388: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149388u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14938c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14938cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149390: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149390u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149394: 0xacc30010  sw          $v1, 0x10($a2)
    ctx->pc = 0x149394u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 3));
    // 0x149398: 0x90e20014  lbu         $v0, 0x14($a3)
    ctx->pc = 0x149398u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 20)));
    // 0x14939c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14939cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1493a0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1493a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1493a4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1493a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1493a8: 0xacc30014  sw          $v1, 0x14($a2)
    ctx->pc = 0x1493a8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 20), GPR_U32(ctx, 3));
    // 0x1493ac: 0x90e20018  lbu         $v0, 0x18($a3)
    ctx->pc = 0x1493acu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 24)));
    // 0x1493b0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1493b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1493b4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1493b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1493b8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1493b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1493bc: 0xacc30018  sw          $v1, 0x18($a2)
    ctx->pc = 0x1493bcu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 24), GPR_U32(ctx, 3));
    // 0x1493c0: 0x90e2001c  lbu         $v0, 0x1C($a3)
    ctx->pc = 0x1493c0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 28)));
    // 0x1493c4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1493c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1493c8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1493c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1493cc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1493ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1493d0: 0xacc3001c  sw          $v1, 0x1C($a2)
    ctx->pc = 0x1493d0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 28), GPR_U32(ctx, 3));
    // 0x1493d4: 0x90e20020  lbu         $v0, 0x20($a3)
    ctx->pc = 0x1493d4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x1493d8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1493d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1493dc: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1493dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1493e0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1493e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1493e4: 0xacc30020  sw          $v1, 0x20($a2)
    ctx->pc = 0x1493e4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 32), GPR_U32(ctx, 3));
    // 0x1493e8: 0x90e20024  lbu         $v0, 0x24($a3)
    ctx->pc = 0x1493e8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x1493ec: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1493ecu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1493f0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1493f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1493f4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1493f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1493f8: 0xacc30024  sw          $v1, 0x24($a2)
    ctx->pc = 0x1493f8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 36), GPR_U32(ctx, 3));
    // 0x1493fc: 0x90e20028  lbu         $v0, 0x28($a3)
    ctx->pc = 0x1493fcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x149400: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149400u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149404: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149404u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149408: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149408u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14940c: 0xacc30028  sw          $v1, 0x28($a2)
    ctx->pc = 0x14940cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 40), GPR_U32(ctx, 3));
    // 0x149410: 0x90e2002c  lbu         $v0, 0x2C($a3)
    ctx->pc = 0x149410u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 44)));
    // 0x149414: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149414u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149418: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149418u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14941c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14941cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149420: 0xacc3002c  sw          $v1, 0x2C($a2)
    ctx->pc = 0x149420u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 44), GPR_U32(ctx, 3));
    // 0x149424: 0x90e20030  lbu         $v0, 0x30($a3)
    ctx->pc = 0x149424u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 48)));
    // 0x149428: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149428u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14942c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14942cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149430: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149430u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149434: 0xacc30030  sw          $v1, 0x30($a2)
    ctx->pc = 0x149434u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 3));
    // 0x149438: 0x90e20034  lbu         $v0, 0x34($a3)
    ctx->pc = 0x149438u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 52)));
    // 0x14943c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14943cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149440: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149440u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149444: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149444u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149448: 0xacc30034  sw          $v1, 0x34($a2)
    ctx->pc = 0x149448u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 52), GPR_U32(ctx, 3));
    // 0x14944c: 0x90e20038  lbu         $v0, 0x38($a3)
    ctx->pc = 0x14944cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 56)));
    // 0x149450: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149450u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149454: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149454u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149458: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149458u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14945c: 0xacc30038  sw          $v1, 0x38($a2)
    ctx->pc = 0x14945cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 56), GPR_U32(ctx, 3));
    // 0x149460: 0x90e2003c  lbu         $v0, 0x3C($a3)
    ctx->pc = 0x149460u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 60)));
    // 0x149464: 0x24e70040  addiu       $a3, $a3, 0x40
    ctx->pc = 0x149464u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 64));
    // 0x149468: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149468u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14946c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14946cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149470: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149470u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149474: 0xacc3003c  sw          $v1, 0x3C($a2)
    ctx->pc = 0x149474u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 60), GPR_U32(ctx, 3));
    // 0x149478: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x149478u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14947c: 0x8d230008  lw          $v1, 0x8($t1)
    ctx->pc = 0x14947cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x149480: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149480u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149484: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149484u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149488: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x149488u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x14948c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x14948cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149490: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x149490u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x149494: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x149494u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x149498: 0x90e20004  lbu         $v0, 0x4($a3)
    ctx->pc = 0x149498u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x14949c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14949cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1494a0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1494a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1494a4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1494a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1494a8: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x1494a8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x1494ac: 0x90e20008  lbu         $v0, 0x8($a3)
    ctx->pc = 0x1494acu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x1494b0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1494b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1494b4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1494b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1494b8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1494b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1494bc: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x1494bcu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x1494c0: 0x90e2000c  lbu         $v0, 0xC($a3)
    ctx->pc = 0x1494c0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x1494c4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1494c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1494c8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1494c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1494cc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1494ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1494d0: 0xacc3000c  sw          $v1, 0xC($a2)
    ctx->pc = 0x1494d0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 3));
    // 0x1494d4: 0x90e20010  lbu         $v0, 0x10($a3)
    ctx->pc = 0x1494d4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x1494d8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1494d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1494dc: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1494dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1494e0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1494e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1494e4: 0xacc30010  sw          $v1, 0x10($a2)
    ctx->pc = 0x1494e4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 3));
    // 0x1494e8: 0x90e20014  lbu         $v0, 0x14($a3)
    ctx->pc = 0x1494e8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 20)));
    // 0x1494ec: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1494ecu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1494f0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1494f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1494f4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1494f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1494f8: 0xacc30014  sw          $v1, 0x14($a2)
    ctx->pc = 0x1494f8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 20), GPR_U32(ctx, 3));
    // 0x1494fc: 0x90e20018  lbu         $v0, 0x18($a3)
    ctx->pc = 0x1494fcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 24)));
    // 0x149500: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149500u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149504: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149504u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149508: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149508u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14950c: 0xacc30018  sw          $v1, 0x18($a2)
    ctx->pc = 0x14950cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 24), GPR_U32(ctx, 3));
    // 0x149510: 0x90e2001c  lbu         $v0, 0x1C($a3)
    ctx->pc = 0x149510u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 28)));
    // 0x149514: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149514u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149518: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149518u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14951c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14951cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149520: 0xacc3001c  sw          $v1, 0x1C($a2)
    ctx->pc = 0x149520u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 28), GPR_U32(ctx, 3));
    // 0x149524: 0x90e20020  lbu         $v0, 0x20($a3)
    ctx->pc = 0x149524u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x149528: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149528u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14952c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14952cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149530: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149530u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149534: 0xacc30020  sw          $v1, 0x20($a2)
    ctx->pc = 0x149534u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 32), GPR_U32(ctx, 3));
    // 0x149538: 0x90e20024  lbu         $v0, 0x24($a3)
    ctx->pc = 0x149538u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x14953c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14953cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149540: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149540u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149544: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149544u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149548: 0xacc30024  sw          $v1, 0x24($a2)
    ctx->pc = 0x149548u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 36), GPR_U32(ctx, 3));
    // 0x14954c: 0x90e20028  lbu         $v0, 0x28($a3)
    ctx->pc = 0x14954cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x149550: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149550u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149554: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149554u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149558: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149558u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14955c: 0xacc30028  sw          $v1, 0x28($a2)
    ctx->pc = 0x14955cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 40), GPR_U32(ctx, 3));
    // 0x149560: 0x90e2002c  lbu         $v0, 0x2C($a3)
    ctx->pc = 0x149560u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 44)));
    // 0x149564: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149564u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149568: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149568u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14956c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14956cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149570: 0xacc3002c  sw          $v1, 0x2C($a2)
    ctx->pc = 0x149570u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 44), GPR_U32(ctx, 3));
    // 0x149574: 0x90e20030  lbu         $v0, 0x30($a3)
    ctx->pc = 0x149574u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 48)));
    // 0x149578: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149578u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14957c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14957cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149580: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149580u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149584: 0xacc30030  sw          $v1, 0x30($a2)
    ctx->pc = 0x149584u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 3));
    // 0x149588: 0x90e20034  lbu         $v0, 0x34($a3)
    ctx->pc = 0x149588u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 52)));
    // 0x14958c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14958cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149590: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149590u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149594: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149594u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149598: 0xacc30034  sw          $v1, 0x34($a2)
    ctx->pc = 0x149598u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 52), GPR_U32(ctx, 3));
    // 0x14959c: 0x90e20038  lbu         $v0, 0x38($a3)
    ctx->pc = 0x14959cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 56)));
    // 0x1495a0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1495a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1495a4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1495a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1495a8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1495a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1495ac: 0xacc30038  sw          $v1, 0x38($a2)
    ctx->pc = 0x1495acu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 56), GPR_U32(ctx, 3));
    // 0x1495b0: 0x90e2003c  lbu         $v0, 0x3C($a3)
    ctx->pc = 0x1495b0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 60)));
    // 0x1495b4: 0x24e70040  addiu       $a3, $a3, 0x40
    ctx->pc = 0x1495b4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 64));
    // 0x1495b8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1495b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1495bc: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1495bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1495c0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1495c0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1495c4: 0xacc3003c  sw          $v1, 0x3C($a2)
    ctx->pc = 0x1495c4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 60), GPR_U32(ctx, 3));
    // 0x1495c8: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x1495c8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1495cc: 0x8d230008  lw          $v1, 0x8($t1)
    ctx->pc = 0x1495ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x1495d0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1495d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1495d4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1495d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1495d8: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1495d8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1495dc: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1495dcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1495e0: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x1495e0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x1495e4: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x1495e4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x1495e8: 0x90e20004  lbu         $v0, 0x4($a3)
    ctx->pc = 0x1495e8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x1495ec: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1495ecu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1495f0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1495f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1495f4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1495f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1495f8: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x1495f8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x1495fc: 0x90e20008  lbu         $v0, 0x8($a3)
    ctx->pc = 0x1495fcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x149600: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149600u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149604: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149604u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149608: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149608u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14960c: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x14960cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x149610: 0x90e2000c  lbu         $v0, 0xC($a3)
    ctx->pc = 0x149610u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x149614: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149614u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149618: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149618u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14961c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14961cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149620: 0xacc3000c  sw          $v1, 0xC($a2)
    ctx->pc = 0x149620u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 3));
    // 0x149624: 0x90e20010  lbu         $v0, 0x10($a3)
    ctx->pc = 0x149624u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x149628: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149628u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14962c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14962cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149630: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149630u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149634: 0xacc30010  sw          $v1, 0x10($a2)
    ctx->pc = 0x149634u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 3));
    // 0x149638: 0x90e20014  lbu         $v0, 0x14($a3)
    ctx->pc = 0x149638u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 20)));
    // 0x14963c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14963cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149640: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149640u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149644: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149644u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149648: 0xacc30014  sw          $v1, 0x14($a2)
    ctx->pc = 0x149648u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 20), GPR_U32(ctx, 3));
    // 0x14964c: 0x90e20018  lbu         $v0, 0x18($a3)
    ctx->pc = 0x14964cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 24)));
    // 0x149650: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149650u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149654: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149654u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149658: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149658u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14965c: 0xacc30018  sw          $v1, 0x18($a2)
    ctx->pc = 0x14965cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 24), GPR_U32(ctx, 3));
    // 0x149660: 0x90e2001c  lbu         $v0, 0x1C($a3)
    ctx->pc = 0x149660u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 28)));
    // 0x149664: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149664u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149668: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149668u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14966c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14966cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149670: 0xacc3001c  sw          $v1, 0x1C($a2)
    ctx->pc = 0x149670u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 28), GPR_U32(ctx, 3));
    // 0x149674: 0x90e20020  lbu         $v0, 0x20($a3)
    ctx->pc = 0x149674u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x149678: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149678u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14967c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14967cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149680: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149680u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149684: 0xacc30020  sw          $v1, 0x20($a2)
    ctx->pc = 0x149684u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 32), GPR_U32(ctx, 3));
    // 0x149688: 0x90e20024  lbu         $v0, 0x24($a3)
    ctx->pc = 0x149688u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x14968c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14968cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149690: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149690u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149694: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149694u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149698: 0xacc30024  sw          $v1, 0x24($a2)
    ctx->pc = 0x149698u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 36), GPR_U32(ctx, 3));
    // 0x14969c: 0x90e20028  lbu         $v0, 0x28($a3)
    ctx->pc = 0x14969cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x1496a0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1496a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1496a4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1496a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1496a8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1496a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1496ac: 0xacc30028  sw          $v1, 0x28($a2)
    ctx->pc = 0x1496acu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 40), GPR_U32(ctx, 3));
    // 0x1496b0: 0x90e2002c  lbu         $v0, 0x2C($a3)
    ctx->pc = 0x1496b0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 44)));
    // 0x1496b4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1496b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1496b8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1496b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1496bc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1496bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1496c0: 0xacc3002c  sw          $v1, 0x2C($a2)
    ctx->pc = 0x1496c0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 44), GPR_U32(ctx, 3));
    // 0x1496c4: 0x90e20030  lbu         $v0, 0x30($a3)
    ctx->pc = 0x1496c4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 48)));
    // 0x1496c8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1496c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1496cc: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1496ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1496d0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1496d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1496d4: 0xacc30030  sw          $v1, 0x30($a2)
    ctx->pc = 0x1496d4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 3));
    // 0x1496d8: 0x90e20034  lbu         $v0, 0x34($a3)
    ctx->pc = 0x1496d8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 52)));
    // 0x1496dc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1496dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1496e0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1496e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1496e4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1496e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1496e8: 0xacc30034  sw          $v1, 0x34($a2)
    ctx->pc = 0x1496e8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 52), GPR_U32(ctx, 3));
    // 0x1496ec: 0x90e20038  lbu         $v0, 0x38($a3)
    ctx->pc = 0x1496ecu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 56)));
    // 0x1496f0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1496f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1496f4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1496f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1496f8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1496f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1496fc: 0xacc30038  sw          $v1, 0x38($a2)
    ctx->pc = 0x1496fcu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 56), GPR_U32(ctx, 3));
    // 0x149700: 0x90e2003c  lbu         $v0, 0x3C($a3)
    ctx->pc = 0x149700u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 60)));
    // 0x149704: 0x24e70040  addiu       $a3, $a3, 0x40
    ctx->pc = 0x149704u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 64));
    // 0x149708: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149708u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14970c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14970cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149710: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149710u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149714: 0xacc3003c  sw          $v1, 0x3C($a2)
    ctx->pc = 0x149714u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 60), GPR_U32(ctx, 3));
    // 0x149718: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x149718u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14971c: 0x8d230008  lw          $v1, 0x8($t1)
    ctx->pc = 0x14971cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x149720: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149720u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149724: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149724u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149728: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x149728u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x14972c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x14972cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149730: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x149730u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x149734: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x149734u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x149738: 0x90e20004  lbu         $v0, 0x4($a3)
    ctx->pc = 0x149738u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x14973c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14973cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149740: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149740u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149744: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149744u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149748: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x149748u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x14974c: 0x90e20008  lbu         $v0, 0x8($a3)
    ctx->pc = 0x14974cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x149750: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149750u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149754: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149754u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149758: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149758u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14975c: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x14975cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x149760: 0x90e2000c  lbu         $v0, 0xC($a3)
    ctx->pc = 0x149760u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x149764: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149764u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149768: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149768u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14976c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14976cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149770: 0xacc3000c  sw          $v1, 0xC($a2)
    ctx->pc = 0x149770u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 3));
    // 0x149774: 0x90e20010  lbu         $v0, 0x10($a3)
    ctx->pc = 0x149774u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x149778: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149778u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14977c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14977cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149780: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149780u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149784: 0xacc30010  sw          $v1, 0x10($a2)
    ctx->pc = 0x149784u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 3));
    // 0x149788: 0x90e20014  lbu         $v0, 0x14($a3)
    ctx->pc = 0x149788u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 20)));
    // 0x14978c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14978cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149790: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149790u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149794: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149794u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149798: 0xacc30014  sw          $v1, 0x14($a2)
    ctx->pc = 0x149798u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 20), GPR_U32(ctx, 3));
    // 0x14979c: 0x90e20018  lbu         $v0, 0x18($a3)
    ctx->pc = 0x14979cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 24)));
    // 0x1497a0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1497a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1497a4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1497a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1497a8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1497a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1497ac: 0xacc30018  sw          $v1, 0x18($a2)
    ctx->pc = 0x1497acu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 24), GPR_U32(ctx, 3));
    // 0x1497b0: 0x90e2001c  lbu         $v0, 0x1C($a3)
    ctx->pc = 0x1497b0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 28)));
    // 0x1497b4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1497b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1497b8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1497b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1497bc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1497bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1497c0: 0xacc3001c  sw          $v1, 0x1C($a2)
    ctx->pc = 0x1497c0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 28), GPR_U32(ctx, 3));
    // 0x1497c4: 0x90e20020  lbu         $v0, 0x20($a3)
    ctx->pc = 0x1497c4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x1497c8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1497c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1497cc: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1497ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1497d0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1497d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1497d4: 0xacc30020  sw          $v1, 0x20($a2)
    ctx->pc = 0x1497d4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 32), GPR_U32(ctx, 3));
    // 0x1497d8: 0x90e20024  lbu         $v0, 0x24($a3)
    ctx->pc = 0x1497d8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x1497dc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1497dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1497e0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1497e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1497e4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1497e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1497e8: 0xacc30024  sw          $v1, 0x24($a2)
    ctx->pc = 0x1497e8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 36), GPR_U32(ctx, 3));
    // 0x1497ec: 0x90e20028  lbu         $v0, 0x28($a3)
    ctx->pc = 0x1497ecu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x1497f0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1497f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1497f4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1497f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1497f8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1497f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1497fc: 0xacc30028  sw          $v1, 0x28($a2)
    ctx->pc = 0x1497fcu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 40), GPR_U32(ctx, 3));
    // 0x149800: 0x90e2002c  lbu         $v0, 0x2C($a3)
    ctx->pc = 0x149800u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 44)));
    // 0x149804: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149804u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149808: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149808u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14980c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14980cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149810: 0xacc3002c  sw          $v1, 0x2C($a2)
    ctx->pc = 0x149810u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 44), GPR_U32(ctx, 3));
    // 0x149814: 0x90e20030  lbu         $v0, 0x30($a3)
    ctx->pc = 0x149814u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 48)));
    // 0x149818: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149818u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14981c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14981cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149820: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149820u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149824: 0xacc30030  sw          $v1, 0x30($a2)
    ctx->pc = 0x149824u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 3));
    // 0x149828: 0x90e20034  lbu         $v0, 0x34($a3)
    ctx->pc = 0x149828u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 52)));
    // 0x14982c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14982cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149830: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149830u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149834: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149834u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149838: 0xacc30034  sw          $v1, 0x34($a2)
    ctx->pc = 0x149838u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 52), GPR_U32(ctx, 3));
    // 0x14983c: 0x90e20038  lbu         $v0, 0x38($a3)
    ctx->pc = 0x14983cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 56)));
    // 0x149840: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149840u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149844: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149844u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149848: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149848u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14984c: 0xacc30038  sw          $v1, 0x38($a2)
    ctx->pc = 0x14984cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 56), GPR_U32(ctx, 3));
    // 0x149850: 0x90e2003c  lbu         $v0, 0x3C($a3)
    ctx->pc = 0x149850u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 60)));
    // 0x149854: 0x24e70040  addiu       $a3, $a3, 0x40
    ctx->pc = 0x149854u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 64));
    // 0x149858: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149858u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14985c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14985cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149860: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149860u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149864: 0xacc3003c  sw          $v1, 0x3C($a2)
    ctx->pc = 0x149864u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 60), GPR_U32(ctx, 3));
    // 0x149868: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x149868u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14986c: 0x8d230008  lw          $v1, 0x8($t1)
    ctx->pc = 0x14986cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x149870: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149870u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149874: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149874u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149878: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x149878u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x14987c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x14987cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149880: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x149880u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x149884: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x149884u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x149888: 0x90e20004  lbu         $v0, 0x4($a3)
    ctx->pc = 0x149888u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x14988c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14988cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149890: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149890u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149894: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149894u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149898: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x149898u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x14989c: 0x90e20008  lbu         $v0, 0x8($a3)
    ctx->pc = 0x14989cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x1498a0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1498a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1498a4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1498a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1498a8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1498a8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1498ac: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x1498acu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x1498b0: 0x90e2000c  lbu         $v0, 0xC($a3)
    ctx->pc = 0x1498b0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x1498b4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1498b4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1498b8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1498b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1498bc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1498bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1498c0: 0xacc3000c  sw          $v1, 0xC($a2)
    ctx->pc = 0x1498c0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 3));
    // 0x1498c4: 0x90e20010  lbu         $v0, 0x10($a3)
    ctx->pc = 0x1498c4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x1498c8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1498c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1498cc: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1498ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1498d0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1498d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1498d4: 0xacc30010  sw          $v1, 0x10($a2)
    ctx->pc = 0x1498d4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 3));
    // 0x1498d8: 0x90e20014  lbu         $v0, 0x14($a3)
    ctx->pc = 0x1498d8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 20)));
    // 0x1498dc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1498dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1498e0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1498e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1498e4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1498e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1498e8: 0xacc30014  sw          $v1, 0x14($a2)
    ctx->pc = 0x1498e8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 20), GPR_U32(ctx, 3));
    // 0x1498ec: 0x90e20018  lbu         $v0, 0x18($a3)
    ctx->pc = 0x1498ecu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 24)));
    // 0x1498f0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1498f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1498f4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1498f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1498f8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1498f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1498fc: 0xacc30018  sw          $v1, 0x18($a2)
    ctx->pc = 0x1498fcu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 24), GPR_U32(ctx, 3));
    // 0x149900: 0x90e2001c  lbu         $v0, 0x1C($a3)
    ctx->pc = 0x149900u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 28)));
    // 0x149904: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149904u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149908: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149908u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14990c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14990cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149910: 0xacc3001c  sw          $v1, 0x1C($a2)
    ctx->pc = 0x149910u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 28), GPR_U32(ctx, 3));
    // 0x149914: 0x90e20020  lbu         $v0, 0x20($a3)
    ctx->pc = 0x149914u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x149918: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149918u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14991c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14991cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149920: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149920u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149924: 0xacc30020  sw          $v1, 0x20($a2)
    ctx->pc = 0x149924u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 32), GPR_U32(ctx, 3));
    // 0x149928: 0x90e20024  lbu         $v0, 0x24($a3)
    ctx->pc = 0x149928u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x14992c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14992cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149930: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149930u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149934: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149934u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149938: 0xacc30024  sw          $v1, 0x24($a2)
    ctx->pc = 0x149938u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 36), GPR_U32(ctx, 3));
    // 0x14993c: 0x90e20028  lbu         $v0, 0x28($a3)
    ctx->pc = 0x14993cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x149940: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149940u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149944: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149944u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149948: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149948u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14994c: 0xacc30028  sw          $v1, 0x28($a2)
    ctx->pc = 0x14994cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 40), GPR_U32(ctx, 3));
    // 0x149950: 0x90e2002c  lbu         $v0, 0x2C($a3)
    ctx->pc = 0x149950u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 44)));
    // 0x149954: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149954u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149958: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149958u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14995c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14995cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149960: 0xacc3002c  sw          $v1, 0x2C($a2)
    ctx->pc = 0x149960u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 44), GPR_U32(ctx, 3));
    // 0x149964: 0x90e20030  lbu         $v0, 0x30($a3)
    ctx->pc = 0x149964u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 48)));
    // 0x149968: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149968u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14996c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14996cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149970: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149970u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149974: 0xacc30030  sw          $v1, 0x30($a2)
    ctx->pc = 0x149974u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 3));
    // 0x149978: 0x90e20034  lbu         $v0, 0x34($a3)
    ctx->pc = 0x149978u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 52)));
    // 0x14997c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14997cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149980: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149980u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149984: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149984u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149988: 0xacc30034  sw          $v1, 0x34($a2)
    ctx->pc = 0x149988u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 52), GPR_U32(ctx, 3));
    // 0x14998c: 0x90e20038  lbu         $v0, 0x38($a3)
    ctx->pc = 0x14998cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 56)));
    // 0x149990: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149990u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149994: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149994u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149998: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149998u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14999c: 0xacc30038  sw          $v1, 0x38($a2)
    ctx->pc = 0x14999cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 56), GPR_U32(ctx, 3));
    // 0x1499a0: 0x90e2003c  lbu         $v0, 0x3C($a3)
    ctx->pc = 0x1499a0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 60)));
    // 0x1499a4: 0x24e70040  addiu       $a3, $a3, 0x40
    ctx->pc = 0x1499a4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 64));
    // 0x1499a8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1499a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1499ac: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1499acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1499b0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1499b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1499b4: 0xacc3003c  sw          $v1, 0x3C($a2)
    ctx->pc = 0x1499b4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 60), GPR_U32(ctx, 3));
    // 0x1499b8: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x1499b8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1499bc: 0x8d230008  lw          $v1, 0x8($t1)
    ctx->pc = 0x1499bcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x1499c0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1499c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1499c4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1499c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1499c8: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1499c8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1499cc: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1499ccu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1499d0: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x1499d0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x1499d4: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x1499d4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x1499d8: 0x90e20004  lbu         $v0, 0x4($a3)
    ctx->pc = 0x1499d8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x1499dc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1499dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1499e0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1499e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1499e4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1499e4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1499e8: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x1499e8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x1499ec: 0x90e20008  lbu         $v0, 0x8($a3)
    ctx->pc = 0x1499ecu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x1499f0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1499f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1499f4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x1499f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1499f8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x1499f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1499fc: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x1499fcu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x149a00: 0x90e2000c  lbu         $v0, 0xC($a3)
    ctx->pc = 0x149a00u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x149a04: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149a04u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149a08: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149a08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149a0c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149a0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149a10: 0xacc3000c  sw          $v1, 0xC($a2)
    ctx->pc = 0x149a10u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 3));
    // 0x149a14: 0x90e20010  lbu         $v0, 0x10($a3)
    ctx->pc = 0x149a14u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x149a18: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149a18u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149a1c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149a1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149a20: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149a20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149a24: 0xacc30010  sw          $v1, 0x10($a2)
    ctx->pc = 0x149a24u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 3));
    // 0x149a28: 0x90e20014  lbu         $v0, 0x14($a3)
    ctx->pc = 0x149a28u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 20)));
    // 0x149a2c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149a2cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149a30: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149a30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149a34: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149a34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149a38: 0xacc30014  sw          $v1, 0x14($a2)
    ctx->pc = 0x149a38u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 20), GPR_U32(ctx, 3));
    // 0x149a3c: 0x90e20018  lbu         $v0, 0x18($a3)
    ctx->pc = 0x149a3cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 24)));
    // 0x149a40: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149a40u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149a44: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149a44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149a48: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149a48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149a4c: 0xacc30018  sw          $v1, 0x18($a2)
    ctx->pc = 0x149a4cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 24), GPR_U32(ctx, 3));
    // 0x149a50: 0x90e2001c  lbu         $v0, 0x1C($a3)
    ctx->pc = 0x149a50u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 28)));
    // 0x149a54: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149a54u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149a58: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149a58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149a5c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149a5cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149a60: 0xacc3001c  sw          $v1, 0x1C($a2)
    ctx->pc = 0x149a60u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 28), GPR_U32(ctx, 3));
    // 0x149a64: 0x90e20020  lbu         $v0, 0x20($a3)
    ctx->pc = 0x149a64u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x149a68: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149a68u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149a6c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149a6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149a70: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149a70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149a74: 0xacc30020  sw          $v1, 0x20($a2)
    ctx->pc = 0x149a74u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 32), GPR_U32(ctx, 3));
    // 0x149a78: 0x90e20024  lbu         $v0, 0x24($a3)
    ctx->pc = 0x149a78u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x149a7c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149a7cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149a80: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149a80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149a84: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149a84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149a88: 0xacc30024  sw          $v1, 0x24($a2)
    ctx->pc = 0x149a88u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 36), GPR_U32(ctx, 3));
    // 0x149a8c: 0x90e20028  lbu         $v0, 0x28($a3)
    ctx->pc = 0x149a8cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x149a90: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149a90u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149a94: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149a94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149a98: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149a98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149a9c: 0xacc30028  sw          $v1, 0x28($a2)
    ctx->pc = 0x149a9cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 40), GPR_U32(ctx, 3));
    // 0x149aa0: 0x90e2002c  lbu         $v0, 0x2C($a3)
    ctx->pc = 0x149aa0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 44)));
    // 0x149aa4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149aa4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149aa8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149aa8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149aac: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149aacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149ab0: 0xacc3002c  sw          $v1, 0x2C($a2)
    ctx->pc = 0x149ab0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 44), GPR_U32(ctx, 3));
    // 0x149ab4: 0x90e20030  lbu         $v0, 0x30($a3)
    ctx->pc = 0x149ab4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 48)));
    // 0x149ab8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149ab8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149abc: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149abcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149ac0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149ac0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149ac4: 0xacc30030  sw          $v1, 0x30($a2)
    ctx->pc = 0x149ac4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 3));
    // 0x149ac8: 0x90e20034  lbu         $v0, 0x34($a3)
    ctx->pc = 0x149ac8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 52)));
    // 0x149acc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149accu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149ad0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149ad4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149ad4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149ad8: 0xacc30034  sw          $v1, 0x34($a2)
    ctx->pc = 0x149ad8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 52), GPR_U32(ctx, 3));
    // 0x149adc: 0x90e20038  lbu         $v0, 0x38($a3)
    ctx->pc = 0x149adcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 56)));
    // 0x149ae0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149ae0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149ae4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149ae4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149ae8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149ae8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149aec: 0xacc30038  sw          $v1, 0x38($a2)
    ctx->pc = 0x149aecu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 56), GPR_U32(ctx, 3));
    // 0x149af0: 0x90e2003c  lbu         $v0, 0x3C($a3)
    ctx->pc = 0x149af0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 60)));
    // 0x149af4: 0x24e70040  addiu       $a3, $a3, 0x40
    ctx->pc = 0x149af4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 64));
    // 0x149af8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149af8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149afc: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149afcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149b00: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149b00u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149b04: 0xacc3003c  sw          $v1, 0x3C($a2)
    ctx->pc = 0x149b04u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 60), GPR_U32(ctx, 3));
    // 0x149b08: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x149b08u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x149b0c: 0x8d230008  lw          $v1, 0x8($t1)
    ctx->pc = 0x149b0cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x149b10: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149b10u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149b14: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149b14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149b18: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x149b18u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x149b1c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x149b1cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149b20: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x149b20u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x149b24: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x149b24u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x149b28: 0x90e20004  lbu         $v0, 0x4($a3)
    ctx->pc = 0x149b28u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x149b2c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149b2cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149b30: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149b30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149b34: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149b34u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149b38: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x149b38u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x149b3c: 0x90e20008  lbu         $v0, 0x8($a3)
    ctx->pc = 0x149b3cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x149b40: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149b40u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149b44: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149b44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149b48: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149b48u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149b4c: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x149b4cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x149b50: 0x90e2000c  lbu         $v0, 0xC($a3)
    ctx->pc = 0x149b50u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x149b54: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149b54u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149b58: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149b58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149b5c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149b5cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149b60: 0xacc3000c  sw          $v1, 0xC($a2)
    ctx->pc = 0x149b60u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 3));
    // 0x149b64: 0x90e20010  lbu         $v0, 0x10($a3)
    ctx->pc = 0x149b64u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x149b68: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149b68u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149b6c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149b6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149b70: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149b70u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149b74: 0xacc30010  sw          $v1, 0x10($a2)
    ctx->pc = 0x149b74u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 3));
    // 0x149b78: 0x90e20014  lbu         $v0, 0x14($a3)
    ctx->pc = 0x149b78u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 20)));
    // 0x149b7c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149b7cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149b80: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149b80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149b84: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149b84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149b88: 0xacc30014  sw          $v1, 0x14($a2)
    ctx->pc = 0x149b88u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 20), GPR_U32(ctx, 3));
    // 0x149b8c: 0x90e20018  lbu         $v0, 0x18($a3)
    ctx->pc = 0x149b8cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 24)));
    // 0x149b90: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149b90u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149b94: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149b94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149b98: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149b98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149b9c: 0xacc30018  sw          $v1, 0x18($a2)
    ctx->pc = 0x149b9cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 24), GPR_U32(ctx, 3));
    // 0x149ba0: 0x90e2001c  lbu         $v0, 0x1C($a3)
    ctx->pc = 0x149ba0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 28)));
    // 0x149ba4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149ba4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149ba8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149ba8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149bac: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149bacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149bb0: 0xacc3001c  sw          $v1, 0x1C($a2)
    ctx->pc = 0x149bb0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 28), GPR_U32(ctx, 3));
    // 0x149bb4: 0x90e20020  lbu         $v0, 0x20($a3)
    ctx->pc = 0x149bb4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x149bb8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149bb8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149bbc: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149bbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149bc0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149bc0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149bc4: 0xacc30020  sw          $v1, 0x20($a2)
    ctx->pc = 0x149bc4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 32), GPR_U32(ctx, 3));
    // 0x149bc8: 0x90e20024  lbu         $v0, 0x24($a3)
    ctx->pc = 0x149bc8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x149bcc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149bccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149bd0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149bd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149bd4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149bd4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149bd8: 0xacc30024  sw          $v1, 0x24($a2)
    ctx->pc = 0x149bd8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 36), GPR_U32(ctx, 3));
    // 0x149bdc: 0x90e20028  lbu         $v0, 0x28($a3)
    ctx->pc = 0x149bdcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x149be0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149be0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149be4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149be4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149be8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149be8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149bec: 0xacc30028  sw          $v1, 0x28($a2)
    ctx->pc = 0x149becu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 40), GPR_U32(ctx, 3));
    // 0x149bf0: 0x90e2002c  lbu         $v0, 0x2C($a3)
    ctx->pc = 0x149bf0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 44)));
    // 0x149bf4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149bf4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149bf8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149bf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149bfc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149bfcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149c00: 0xacc3002c  sw          $v1, 0x2C($a2)
    ctx->pc = 0x149c00u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 44), GPR_U32(ctx, 3));
    // 0x149c04: 0x90e20030  lbu         $v0, 0x30($a3)
    ctx->pc = 0x149c04u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 48)));
    // 0x149c08: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149c08u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149c0c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149c0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149c10: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149c10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149c14: 0xacc30030  sw          $v1, 0x30($a2)
    ctx->pc = 0x149c14u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 3));
    // 0x149c18: 0x90e20034  lbu         $v0, 0x34($a3)
    ctx->pc = 0x149c18u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 52)));
    // 0x149c1c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149c1cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149c20: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149c20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149c24: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149c24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149c28: 0xacc30034  sw          $v1, 0x34($a2)
    ctx->pc = 0x149c28u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 52), GPR_U32(ctx, 3));
    // 0x149c2c: 0x90e20038  lbu         $v0, 0x38($a3)
    ctx->pc = 0x149c2cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 56)));
    // 0x149c30: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149c30u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149c34: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149c34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149c38: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149c38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149c3c: 0xacc30038  sw          $v1, 0x38($a2)
    ctx->pc = 0x149c3cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 56), GPR_U32(ctx, 3));
    // 0x149c40: 0x90e2003c  lbu         $v0, 0x3C($a3)
    ctx->pc = 0x149c40u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 60)));
    // 0x149c44: 0x24e70040  addiu       $a3, $a3, 0x40
    ctx->pc = 0x149c44u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 64));
    // 0x149c48: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149c48u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149c4c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149c4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149c50: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149c50u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149c54: 0xacc3003c  sw          $v1, 0x3C($a2)
    ctx->pc = 0x149c54u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 60), GPR_U32(ctx, 3));
    // 0x149c58: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x149c58u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x149c5c: 0x8d230008  lw          $v1, 0x8($t1)
    ctx->pc = 0x149c5cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x149c60: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149c60u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149c64: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149c64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149c68: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x149c68u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x149c6c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x149c6cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149c70: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x149c70u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x149c74: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x149c74u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x149c78: 0x90e20004  lbu         $v0, 0x4($a3)
    ctx->pc = 0x149c78u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x149c7c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149c7cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149c80: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149c80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149c84: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149c84u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149c88: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x149c88u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x149c8c: 0x90e20008  lbu         $v0, 0x8($a3)
    ctx->pc = 0x149c8cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x149c90: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149c90u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149c94: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149c94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149c98: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149c98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149c9c: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x149c9cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x149ca0: 0x90e2000c  lbu         $v0, 0xC($a3)
    ctx->pc = 0x149ca0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x149ca4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149ca4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149ca8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149ca8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149cac: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149cacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149cb0: 0xacc3000c  sw          $v1, 0xC($a2)
    ctx->pc = 0x149cb0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 3));
    // 0x149cb4: 0x90e20010  lbu         $v0, 0x10($a3)
    ctx->pc = 0x149cb4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x149cb8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149cb8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149cbc: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149cbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149cc0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149cc0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149cc4: 0xacc30010  sw          $v1, 0x10($a2)
    ctx->pc = 0x149cc4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 3));
    // 0x149cc8: 0x90e20014  lbu         $v0, 0x14($a3)
    ctx->pc = 0x149cc8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 20)));
    // 0x149ccc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149cccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149cd0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149cd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149cd4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149cd4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149cd8: 0xacc30014  sw          $v1, 0x14($a2)
    ctx->pc = 0x149cd8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 20), GPR_U32(ctx, 3));
    // 0x149cdc: 0x90e20018  lbu         $v0, 0x18($a3)
    ctx->pc = 0x149cdcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 24)));
    // 0x149ce0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149ce0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149ce4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149ce4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149ce8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149ce8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149cec: 0xacc30018  sw          $v1, 0x18($a2)
    ctx->pc = 0x149cecu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 24), GPR_U32(ctx, 3));
    // 0x149cf0: 0x90e2001c  lbu         $v0, 0x1C($a3)
    ctx->pc = 0x149cf0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 28)));
    // 0x149cf4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149cf4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149cf8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149cf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149cfc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149cfcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149d00: 0xacc3001c  sw          $v1, 0x1C($a2)
    ctx->pc = 0x149d00u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 28), GPR_U32(ctx, 3));
    // 0x149d04: 0x90e20020  lbu         $v0, 0x20($a3)
    ctx->pc = 0x149d04u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x149d08: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149d08u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149d0c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149d0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149d10: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149d10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149d14: 0xacc30020  sw          $v1, 0x20($a2)
    ctx->pc = 0x149d14u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 32), GPR_U32(ctx, 3));
    // 0x149d18: 0x90e20024  lbu         $v0, 0x24($a3)
    ctx->pc = 0x149d18u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x149d1c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149d1cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149d20: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149d20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149d24: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149d24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149d28: 0xacc30024  sw          $v1, 0x24($a2)
    ctx->pc = 0x149d28u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 36), GPR_U32(ctx, 3));
    // 0x149d2c: 0x90e20028  lbu         $v0, 0x28($a3)
    ctx->pc = 0x149d2cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x149d30: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149d30u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149d34: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149d34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149d38: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149d38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149d3c: 0xacc30028  sw          $v1, 0x28($a2)
    ctx->pc = 0x149d3cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 40), GPR_U32(ctx, 3));
    // 0x149d40: 0x90e2002c  lbu         $v0, 0x2C($a3)
    ctx->pc = 0x149d40u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 44)));
    // 0x149d44: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149d44u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149d48: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149d48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149d4c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149d4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149d50: 0xacc3002c  sw          $v1, 0x2C($a2)
    ctx->pc = 0x149d50u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 44), GPR_U32(ctx, 3));
    // 0x149d54: 0x90e20030  lbu         $v0, 0x30($a3)
    ctx->pc = 0x149d54u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 48)));
    // 0x149d58: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149d58u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149d5c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149d5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149d60: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149d60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149d64: 0xacc30030  sw          $v1, 0x30($a2)
    ctx->pc = 0x149d64u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 3));
    // 0x149d68: 0x90e20034  lbu         $v0, 0x34($a3)
    ctx->pc = 0x149d68u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 52)));
    // 0x149d6c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149d6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149d70: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149d70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149d74: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149d74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149d78: 0xacc30034  sw          $v1, 0x34($a2)
    ctx->pc = 0x149d78u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 52), GPR_U32(ctx, 3));
    // 0x149d7c: 0x90e20038  lbu         $v0, 0x38($a3)
    ctx->pc = 0x149d7cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 56)));
    // 0x149d80: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149d80u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149d84: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149d84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149d88: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149d88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149d8c: 0xacc30038  sw          $v1, 0x38($a2)
    ctx->pc = 0x149d8cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 56), GPR_U32(ctx, 3));
    // 0x149d90: 0x90e2003c  lbu         $v0, 0x3C($a3)
    ctx->pc = 0x149d90u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 60)));
    // 0x149d94: 0x24e70040  addiu       $a3, $a3, 0x40
    ctx->pc = 0x149d94u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 64));
    // 0x149d98: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149d98u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149d9c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149d9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149da0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149da0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149da4: 0xacc3003c  sw          $v1, 0x3C($a2)
    ctx->pc = 0x149da4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 60), GPR_U32(ctx, 3));
    // 0x149da8: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x149da8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x149dac: 0x8d230008  lw          $v1, 0x8($t1)
    ctx->pc = 0x149dacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x149db0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149db0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149db4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149db4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149db8: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x149db8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x149dbc: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x149dbcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149dc0: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x149dc0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x149dc4: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x149dc4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x149dc8: 0x90e20004  lbu         $v0, 0x4($a3)
    ctx->pc = 0x149dc8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x149dcc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149dccu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149dd0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149dd0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149dd4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149dd4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149dd8: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x149dd8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x149ddc: 0x90e20008  lbu         $v0, 0x8($a3)
    ctx->pc = 0x149ddcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x149de0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149de0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149de4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149de4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149de8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149de8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149dec: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x149decu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x149df0: 0x90e2000c  lbu         $v0, 0xC($a3)
    ctx->pc = 0x149df0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x149df4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149df4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149df8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149df8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149dfc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149dfcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149e00: 0xacc3000c  sw          $v1, 0xC($a2)
    ctx->pc = 0x149e00u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 3));
    // 0x149e04: 0x90e20010  lbu         $v0, 0x10($a3)
    ctx->pc = 0x149e04u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x149e08: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149e08u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149e0c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149e0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149e10: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149e10u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149e14: 0xacc30010  sw          $v1, 0x10($a2)
    ctx->pc = 0x149e14u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 3));
    // 0x149e18: 0x90e20014  lbu         $v0, 0x14($a3)
    ctx->pc = 0x149e18u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 20)));
    // 0x149e1c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149e1cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149e20: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149e20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149e24: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149e24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149e28: 0xacc30014  sw          $v1, 0x14($a2)
    ctx->pc = 0x149e28u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 20), GPR_U32(ctx, 3));
    // 0x149e2c: 0x90e20018  lbu         $v0, 0x18($a3)
    ctx->pc = 0x149e2cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 24)));
    // 0x149e30: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149e30u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149e34: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149e34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149e38: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149e38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149e3c: 0xacc30018  sw          $v1, 0x18($a2)
    ctx->pc = 0x149e3cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 24), GPR_U32(ctx, 3));
    // 0x149e40: 0x90e2001c  lbu         $v0, 0x1C($a3)
    ctx->pc = 0x149e40u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 28)));
    // 0x149e44: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149e44u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149e48: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149e48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149e4c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149e4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149e50: 0xacc3001c  sw          $v1, 0x1C($a2)
    ctx->pc = 0x149e50u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 28), GPR_U32(ctx, 3));
    // 0x149e54: 0x90e20020  lbu         $v0, 0x20($a3)
    ctx->pc = 0x149e54u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x149e58: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149e58u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149e5c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149e5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149e60: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149e60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149e64: 0xacc30020  sw          $v1, 0x20($a2)
    ctx->pc = 0x149e64u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 32), GPR_U32(ctx, 3));
    // 0x149e68: 0x90e20024  lbu         $v0, 0x24($a3)
    ctx->pc = 0x149e68u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x149e6c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149e6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149e70: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149e70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149e74: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149e74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149e78: 0xacc30024  sw          $v1, 0x24($a2)
    ctx->pc = 0x149e78u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 36), GPR_U32(ctx, 3));
    // 0x149e7c: 0x90e20028  lbu         $v0, 0x28($a3)
    ctx->pc = 0x149e7cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x149e80: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149e80u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149e84: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149e84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149e88: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149e88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149e8c: 0xacc30028  sw          $v1, 0x28($a2)
    ctx->pc = 0x149e8cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 40), GPR_U32(ctx, 3));
    // 0x149e90: 0x90e2002c  lbu         $v0, 0x2C($a3)
    ctx->pc = 0x149e90u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 44)));
    // 0x149e94: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149e94u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149e98: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149e98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149e9c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149e9cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149ea0: 0xacc3002c  sw          $v1, 0x2C($a2)
    ctx->pc = 0x149ea0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 44), GPR_U32(ctx, 3));
    // 0x149ea4: 0x90e20030  lbu         $v0, 0x30($a3)
    ctx->pc = 0x149ea4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 48)));
    // 0x149ea8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149ea8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149eac: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149eacu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149eb0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149eb0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149eb4: 0xacc30030  sw          $v1, 0x30($a2)
    ctx->pc = 0x149eb4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 3));
    // 0x149eb8: 0x90e20034  lbu         $v0, 0x34($a3)
    ctx->pc = 0x149eb8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 52)));
    // 0x149ebc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149ebcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149ec0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149ec0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149ec4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149ec4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149ec8: 0xacc30034  sw          $v1, 0x34($a2)
    ctx->pc = 0x149ec8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 52), GPR_U32(ctx, 3));
    // 0x149ecc: 0x90e20038  lbu         $v0, 0x38($a3)
    ctx->pc = 0x149eccu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 56)));
    // 0x149ed0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149ed0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149ed4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149ed4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149ed8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149ed8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149edc: 0xacc30038  sw          $v1, 0x38($a2)
    ctx->pc = 0x149edcu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 56), GPR_U32(ctx, 3));
    // 0x149ee0: 0x90e2003c  lbu         $v0, 0x3C($a3)
    ctx->pc = 0x149ee0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 60)));
    // 0x149ee4: 0x24e70040  addiu       $a3, $a3, 0x40
    ctx->pc = 0x149ee4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 64));
    // 0x149ee8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149ee8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149eec: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149eecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149ef0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149ef0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149ef4: 0xacc3003c  sw          $v1, 0x3C($a2)
    ctx->pc = 0x149ef4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 60), GPR_U32(ctx, 3));
    // 0x149ef8: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x149ef8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x149efc: 0x8d230008  lw          $v1, 0x8($t1)
    ctx->pc = 0x149efcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x149f00: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149f00u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149f04: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149f04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149f08: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x149f08u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x149f0c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x149f0cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149f10: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x149f10u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x149f14: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x149f14u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x149f18: 0x90e20004  lbu         $v0, 0x4($a3)
    ctx->pc = 0x149f18u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x149f1c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149f1cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149f20: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149f20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149f24: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149f24u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149f28: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x149f28u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x149f2c: 0x90e20008  lbu         $v0, 0x8($a3)
    ctx->pc = 0x149f2cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x149f30: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149f30u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149f34: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149f34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149f38: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149f38u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149f3c: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x149f3cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x149f40: 0x90e2000c  lbu         $v0, 0xC($a3)
    ctx->pc = 0x149f40u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x149f44: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149f44u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149f48: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149f48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149f4c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149f4cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149f50: 0xacc3000c  sw          $v1, 0xC($a2)
    ctx->pc = 0x149f50u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 3));
    // 0x149f54: 0x90e20010  lbu         $v0, 0x10($a3)
    ctx->pc = 0x149f54u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x149f58: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149f58u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149f5c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149f5cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149f60: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149f60u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149f64: 0xacc30010  sw          $v1, 0x10($a2)
    ctx->pc = 0x149f64u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 3));
    // 0x149f68: 0x90e20014  lbu         $v0, 0x14($a3)
    ctx->pc = 0x149f68u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 20)));
    // 0x149f6c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149f6cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149f70: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149f70u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149f74: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149f74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149f78: 0xacc30014  sw          $v1, 0x14($a2)
    ctx->pc = 0x149f78u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 20), GPR_U32(ctx, 3));
    // 0x149f7c: 0x90e20018  lbu         $v0, 0x18($a3)
    ctx->pc = 0x149f7cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 24)));
    // 0x149f80: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149f80u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149f84: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149f84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149f88: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149f88u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149f8c: 0xacc30018  sw          $v1, 0x18($a2)
    ctx->pc = 0x149f8cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 24), GPR_U32(ctx, 3));
    // 0x149f90: 0x90e2001c  lbu         $v0, 0x1C($a3)
    ctx->pc = 0x149f90u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 28)));
    // 0x149f94: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149f94u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149f98: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149f98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149f9c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149f9cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149fa0: 0xacc3001c  sw          $v1, 0x1C($a2)
    ctx->pc = 0x149fa0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 28), GPR_U32(ctx, 3));
    // 0x149fa4: 0x90e20020  lbu         $v0, 0x20($a3)
    ctx->pc = 0x149fa4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x149fa8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149fa8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149fac: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149facu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149fb0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149fb0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149fb4: 0xacc30020  sw          $v1, 0x20($a2)
    ctx->pc = 0x149fb4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 32), GPR_U32(ctx, 3));
    // 0x149fb8: 0x90e20024  lbu         $v0, 0x24($a3)
    ctx->pc = 0x149fb8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x149fbc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149fbcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149fc0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149fc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149fc4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149fc4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149fc8: 0xacc30024  sw          $v1, 0x24($a2)
    ctx->pc = 0x149fc8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 36), GPR_U32(ctx, 3));
    // 0x149fcc: 0x90e20028  lbu         $v0, 0x28($a3)
    ctx->pc = 0x149fccu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x149fd0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149fd0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149fd4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149fd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149fd8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149fd8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149fdc: 0xacc30028  sw          $v1, 0x28($a2)
    ctx->pc = 0x149fdcu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 40), GPR_U32(ctx, 3));
    // 0x149fe0: 0x90e2002c  lbu         $v0, 0x2C($a3)
    ctx->pc = 0x149fe0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 44)));
    // 0x149fe4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149fe4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149fe8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149fe8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x149fec: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x149fecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x149ff0: 0xacc3002c  sw          $v1, 0x2C($a2)
    ctx->pc = 0x149ff0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 44), GPR_U32(ctx, 3));
    // 0x149ff4: 0x90e20030  lbu         $v0, 0x30($a3)
    ctx->pc = 0x149ff4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 48)));
    // 0x149ff8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x149ff8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x149ffc: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x149ffcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a000: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a000u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a004: 0xacc30030  sw          $v1, 0x30($a2)
    ctx->pc = 0x14a004u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 3));
    // 0x14a008: 0x90e20034  lbu         $v0, 0x34($a3)
    ctx->pc = 0x14a008u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 52)));
    // 0x14a00c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a00cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a010: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a010u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a014: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a014u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a018: 0xacc30034  sw          $v1, 0x34($a2)
    ctx->pc = 0x14a018u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 52), GPR_U32(ctx, 3));
    // 0x14a01c: 0x90e20038  lbu         $v0, 0x38($a3)
    ctx->pc = 0x14a01cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 56)));
    // 0x14a020: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a020u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a024: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a024u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a028: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a028u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a02c: 0xacc30038  sw          $v1, 0x38($a2)
    ctx->pc = 0x14a02cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 56), GPR_U32(ctx, 3));
    // 0x14a030: 0x90e2003c  lbu         $v0, 0x3C($a3)
    ctx->pc = 0x14a030u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 60)));
    // 0x14a034: 0x24e70040  addiu       $a3, $a3, 0x40
    ctx->pc = 0x14a034u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 64));
    // 0x14a038: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a038u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a03c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a03cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a040: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a040u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a044: 0xacc3003c  sw          $v1, 0x3C($a2)
    ctx->pc = 0x14a044u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 60), GPR_U32(ctx, 3));
    // 0x14a048: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x14a048u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14a04c: 0x8d230008  lw          $v1, 0x8($t1)
    ctx->pc = 0x14a04cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x14a050: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a050u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a054: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a054u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a058: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x14a058u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x14a05c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x14a05cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a060: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x14a060u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14a064: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x14a064u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x14a068: 0x90e20004  lbu         $v0, 0x4($a3)
    ctx->pc = 0x14a068u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x14a06c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a06cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a070: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a070u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a074: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a074u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a078: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x14a078u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x14a07c: 0x90e20008  lbu         $v0, 0x8($a3)
    ctx->pc = 0x14a07cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x14a080: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a080u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a084: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a084u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a088: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a088u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a08c: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x14a08cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x14a090: 0x90e2000c  lbu         $v0, 0xC($a3)
    ctx->pc = 0x14a090u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x14a094: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a094u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a098: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a098u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a09c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a09cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a0a0: 0xacc3000c  sw          $v1, 0xC($a2)
    ctx->pc = 0x14a0a0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 3));
    // 0x14a0a4: 0x90e20010  lbu         $v0, 0x10($a3)
    ctx->pc = 0x14a0a4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x14a0a8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a0a8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a0ac: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a0acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a0b0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a0b0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a0b4: 0xacc30010  sw          $v1, 0x10($a2)
    ctx->pc = 0x14a0b4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 3));
    // 0x14a0b8: 0x90e20014  lbu         $v0, 0x14($a3)
    ctx->pc = 0x14a0b8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 20)));
    // 0x14a0bc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a0bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a0c0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a0c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a0c4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a0c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a0c8: 0xacc30014  sw          $v1, 0x14($a2)
    ctx->pc = 0x14a0c8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 20), GPR_U32(ctx, 3));
    // 0x14a0cc: 0x90e20018  lbu         $v0, 0x18($a3)
    ctx->pc = 0x14a0ccu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 24)));
    // 0x14a0d0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a0d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a0d4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a0d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a0d8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a0d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a0dc: 0xacc30018  sw          $v1, 0x18($a2)
    ctx->pc = 0x14a0dcu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 24), GPR_U32(ctx, 3));
    // 0x14a0e0: 0x90e2001c  lbu         $v0, 0x1C($a3)
    ctx->pc = 0x14a0e0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 28)));
    // 0x14a0e4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a0e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a0e8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a0e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a0ec: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a0ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a0f0: 0xacc3001c  sw          $v1, 0x1C($a2)
    ctx->pc = 0x14a0f0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 28), GPR_U32(ctx, 3));
    // 0x14a0f4: 0x90e20020  lbu         $v0, 0x20($a3)
    ctx->pc = 0x14a0f4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x14a0f8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a0f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a0fc: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a0fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a100: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a100u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a104: 0xacc30020  sw          $v1, 0x20($a2)
    ctx->pc = 0x14a104u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 32), GPR_U32(ctx, 3));
    // 0x14a108: 0x90e20024  lbu         $v0, 0x24($a3)
    ctx->pc = 0x14a108u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x14a10c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a10cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a110: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a110u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a114: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a114u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a118: 0xacc30024  sw          $v1, 0x24($a2)
    ctx->pc = 0x14a118u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 36), GPR_U32(ctx, 3));
    // 0x14a11c: 0x90e20028  lbu         $v0, 0x28($a3)
    ctx->pc = 0x14a11cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x14a120: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a120u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a124: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a124u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a128: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a128u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a12c: 0xacc30028  sw          $v1, 0x28($a2)
    ctx->pc = 0x14a12cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 40), GPR_U32(ctx, 3));
    // 0x14a130: 0x90e2002c  lbu         $v0, 0x2C($a3)
    ctx->pc = 0x14a130u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 44)));
    // 0x14a134: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a134u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a138: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a138u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a13c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a13cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a140: 0xacc3002c  sw          $v1, 0x2C($a2)
    ctx->pc = 0x14a140u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 44), GPR_U32(ctx, 3));
    // 0x14a144: 0x90e20030  lbu         $v0, 0x30($a3)
    ctx->pc = 0x14a144u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 48)));
    // 0x14a148: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a148u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a14c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a14cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a150: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a150u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a154: 0xacc30030  sw          $v1, 0x30($a2)
    ctx->pc = 0x14a154u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 3));
    // 0x14a158: 0x90e20034  lbu         $v0, 0x34($a3)
    ctx->pc = 0x14a158u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 52)));
    // 0x14a15c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a15cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a160: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a160u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a164: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a164u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a168: 0xacc30034  sw          $v1, 0x34($a2)
    ctx->pc = 0x14a168u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 52), GPR_U32(ctx, 3));
    // 0x14a16c: 0x90e20038  lbu         $v0, 0x38($a3)
    ctx->pc = 0x14a16cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 56)));
    // 0x14a170: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a170u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a174: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a174u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a178: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a178u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a17c: 0xacc30038  sw          $v1, 0x38($a2)
    ctx->pc = 0x14a17cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 56), GPR_U32(ctx, 3));
    // 0x14a180: 0x90e2003c  lbu         $v0, 0x3C($a3)
    ctx->pc = 0x14a180u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 60)));
    // 0x14a184: 0x24e70040  addiu       $a3, $a3, 0x40
    ctx->pc = 0x14a184u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 64));
    // 0x14a188: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a188u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a18c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a18cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a190: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a190u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a194: 0xacc3003c  sw          $v1, 0x3C($a2)
    ctx->pc = 0x14a194u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 60), GPR_U32(ctx, 3));
    // 0x14a198: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x14a198u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14a19c: 0x8d230008  lw          $v1, 0x8($t1)
    ctx->pc = 0x14a19cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x14a1a0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a1a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a1a4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a1a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a1a8: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x14a1a8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x14a1ac: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x14a1acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a1b0: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x14a1b0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14a1b4: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x14a1b4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x14a1b8: 0x90e20004  lbu         $v0, 0x4($a3)
    ctx->pc = 0x14a1b8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x14a1bc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a1bcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a1c0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a1c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a1c4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a1c4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a1c8: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x14a1c8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x14a1cc: 0x90e20008  lbu         $v0, 0x8($a3)
    ctx->pc = 0x14a1ccu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x14a1d0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a1d0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a1d4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a1d4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a1d8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a1d8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a1dc: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x14a1dcu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x14a1e0: 0x90e2000c  lbu         $v0, 0xC($a3)
    ctx->pc = 0x14a1e0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x14a1e4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a1e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a1e8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a1e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a1ec: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a1ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a1f0: 0xacc3000c  sw          $v1, 0xC($a2)
    ctx->pc = 0x14a1f0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 3));
    // 0x14a1f4: 0x90e20010  lbu         $v0, 0x10($a3)
    ctx->pc = 0x14a1f4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x14a1f8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a1f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a1fc: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a1fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a200: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a200u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a204: 0xacc30010  sw          $v1, 0x10($a2)
    ctx->pc = 0x14a204u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 3));
    // 0x14a208: 0x90e20014  lbu         $v0, 0x14($a3)
    ctx->pc = 0x14a208u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 20)));
    // 0x14a20c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a20cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a210: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a210u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a214: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a214u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a218: 0xacc30014  sw          $v1, 0x14($a2)
    ctx->pc = 0x14a218u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 20), GPR_U32(ctx, 3));
    // 0x14a21c: 0x90e20018  lbu         $v0, 0x18($a3)
    ctx->pc = 0x14a21cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 24)));
    // 0x14a220: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a220u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a224: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a224u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a228: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a228u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a22c: 0xacc30018  sw          $v1, 0x18($a2)
    ctx->pc = 0x14a22cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 24), GPR_U32(ctx, 3));
    // 0x14a230: 0x90e2001c  lbu         $v0, 0x1C($a3)
    ctx->pc = 0x14a230u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 28)));
    // 0x14a234: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a234u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a238: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a238u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a23c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a23cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a240: 0xacc3001c  sw          $v1, 0x1C($a2)
    ctx->pc = 0x14a240u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 28), GPR_U32(ctx, 3));
    // 0x14a244: 0x90e20020  lbu         $v0, 0x20($a3)
    ctx->pc = 0x14a244u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x14a248: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a248u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a24c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a24cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a250: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a250u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a254: 0xacc30020  sw          $v1, 0x20($a2)
    ctx->pc = 0x14a254u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 32), GPR_U32(ctx, 3));
    // 0x14a258: 0x90e20024  lbu         $v0, 0x24($a3)
    ctx->pc = 0x14a258u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x14a25c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a25cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a260: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a260u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a264: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a264u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a268: 0xacc30024  sw          $v1, 0x24($a2)
    ctx->pc = 0x14a268u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 36), GPR_U32(ctx, 3));
    // 0x14a26c: 0x90e20028  lbu         $v0, 0x28($a3)
    ctx->pc = 0x14a26cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x14a270: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a270u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a274: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a274u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a278: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a278u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a27c: 0xacc30028  sw          $v1, 0x28($a2)
    ctx->pc = 0x14a27cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 40), GPR_U32(ctx, 3));
    // 0x14a280: 0x90e2002c  lbu         $v0, 0x2C($a3)
    ctx->pc = 0x14a280u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 44)));
    // 0x14a284: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a284u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a288: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a288u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a28c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a28cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a290: 0xacc3002c  sw          $v1, 0x2C($a2)
    ctx->pc = 0x14a290u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 44), GPR_U32(ctx, 3));
    // 0x14a294: 0x90e20030  lbu         $v0, 0x30($a3)
    ctx->pc = 0x14a294u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 48)));
    // 0x14a298: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a298u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a29c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a29cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a2a0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a2a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a2a4: 0xacc30030  sw          $v1, 0x30($a2)
    ctx->pc = 0x14a2a4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 3));
    // 0x14a2a8: 0x90e20034  lbu         $v0, 0x34($a3)
    ctx->pc = 0x14a2a8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 52)));
    // 0x14a2ac: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a2acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a2b0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a2b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a2b4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a2b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a2b8: 0xacc30034  sw          $v1, 0x34($a2)
    ctx->pc = 0x14a2b8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 52), GPR_U32(ctx, 3));
    // 0x14a2bc: 0x90e20038  lbu         $v0, 0x38($a3)
    ctx->pc = 0x14a2bcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 56)));
    // 0x14a2c0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a2c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a2c4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a2c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a2c8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a2c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a2cc: 0xacc30038  sw          $v1, 0x38($a2)
    ctx->pc = 0x14a2ccu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 56), GPR_U32(ctx, 3));
    // 0x14a2d0: 0x90e2003c  lbu         $v0, 0x3C($a3)
    ctx->pc = 0x14a2d0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 60)));
    // 0x14a2d4: 0x24e70040  addiu       $a3, $a3, 0x40
    ctx->pc = 0x14a2d4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 64));
    // 0x14a2d8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a2d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a2dc: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a2dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a2e0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a2e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a2e4: 0xacc3003c  sw          $v1, 0x3C($a2)
    ctx->pc = 0x14a2e4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 60), GPR_U32(ctx, 3));
    // 0x14a2e8: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x14a2e8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14a2ec: 0x8d230008  lw          $v1, 0x8($t1)
    ctx->pc = 0x14a2ecu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x14a2f0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a2f0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a2f4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a2f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a2f8: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x14a2f8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x14a2fc: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x14a2fcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a300: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x14a300u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14a304: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x14a304u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x14a308: 0x90e20004  lbu         $v0, 0x4($a3)
    ctx->pc = 0x14a308u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x14a30c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a30cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a310: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a310u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a314: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a314u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a318: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x14a318u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x14a31c: 0x90e20008  lbu         $v0, 0x8($a3)
    ctx->pc = 0x14a31cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x14a320: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a320u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a324: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a324u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a328: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a328u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a32c: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x14a32cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x14a330: 0x90e2000c  lbu         $v0, 0xC($a3)
    ctx->pc = 0x14a330u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x14a334: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a334u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a338: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a338u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a33c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a33cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a340: 0xacc3000c  sw          $v1, 0xC($a2)
    ctx->pc = 0x14a340u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 3));
    // 0x14a344: 0x90e20010  lbu         $v0, 0x10($a3)
    ctx->pc = 0x14a344u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x14a348: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a348u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a34c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a34cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a350: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a350u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a354: 0xacc30010  sw          $v1, 0x10($a2)
    ctx->pc = 0x14a354u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 3));
    // 0x14a358: 0x90e20014  lbu         $v0, 0x14($a3)
    ctx->pc = 0x14a358u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 20)));
    // 0x14a35c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a35cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a360: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a360u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a364: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a364u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a368: 0xacc30014  sw          $v1, 0x14($a2)
    ctx->pc = 0x14a368u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 20), GPR_U32(ctx, 3));
    // 0x14a36c: 0x90e20018  lbu         $v0, 0x18($a3)
    ctx->pc = 0x14a36cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 24)));
    // 0x14a370: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a370u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a374: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a374u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a378: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a378u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a37c: 0xacc30018  sw          $v1, 0x18($a2)
    ctx->pc = 0x14a37cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 24), GPR_U32(ctx, 3));
    // 0x14a380: 0x90e2001c  lbu         $v0, 0x1C($a3)
    ctx->pc = 0x14a380u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 28)));
    // 0x14a384: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a384u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a388: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a388u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a38c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a38cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a390: 0xacc3001c  sw          $v1, 0x1C($a2)
    ctx->pc = 0x14a390u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 28), GPR_U32(ctx, 3));
    // 0x14a394: 0x90e20020  lbu         $v0, 0x20($a3)
    ctx->pc = 0x14a394u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x14a398: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a398u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a39c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a39cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a3a0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a3a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a3a4: 0xacc30020  sw          $v1, 0x20($a2)
    ctx->pc = 0x14a3a4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 32), GPR_U32(ctx, 3));
    // 0x14a3a8: 0x90e20024  lbu         $v0, 0x24($a3)
    ctx->pc = 0x14a3a8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x14a3ac: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a3acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a3b0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a3b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a3b4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a3b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a3b8: 0xacc30024  sw          $v1, 0x24($a2)
    ctx->pc = 0x14a3b8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 36), GPR_U32(ctx, 3));
    // 0x14a3bc: 0x90e20028  lbu         $v0, 0x28($a3)
    ctx->pc = 0x14a3bcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x14a3c0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a3c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a3c4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a3c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a3c8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a3c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a3cc: 0xacc30028  sw          $v1, 0x28($a2)
    ctx->pc = 0x14a3ccu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 40), GPR_U32(ctx, 3));
    // 0x14a3d0: 0x90e2002c  lbu         $v0, 0x2C($a3)
    ctx->pc = 0x14a3d0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 44)));
    // 0x14a3d4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a3d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a3d8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a3d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a3dc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a3dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a3e0: 0xacc3002c  sw          $v1, 0x2C($a2)
    ctx->pc = 0x14a3e0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 44), GPR_U32(ctx, 3));
    // 0x14a3e4: 0x90e20030  lbu         $v0, 0x30($a3)
    ctx->pc = 0x14a3e4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 48)));
    // 0x14a3e8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a3e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a3ec: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a3ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a3f0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a3f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a3f4: 0xacc30030  sw          $v1, 0x30($a2)
    ctx->pc = 0x14a3f4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 3));
    // 0x14a3f8: 0x90e20034  lbu         $v0, 0x34($a3)
    ctx->pc = 0x14a3f8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 52)));
    // 0x14a3fc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a3fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a400: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a400u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a404: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a404u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a408: 0xacc30034  sw          $v1, 0x34($a2)
    ctx->pc = 0x14a408u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 52), GPR_U32(ctx, 3));
    // 0x14a40c: 0x90e20038  lbu         $v0, 0x38($a3)
    ctx->pc = 0x14a40cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 56)));
    // 0x14a410: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a410u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a414: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a414u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a418: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a418u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a41c: 0xacc30038  sw          $v1, 0x38($a2)
    ctx->pc = 0x14a41cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 56), GPR_U32(ctx, 3));
    // 0x14a420: 0x90e2003c  lbu         $v0, 0x3C($a3)
    ctx->pc = 0x14a420u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 60)));
    // 0x14a424: 0x24e70040  addiu       $a3, $a3, 0x40
    ctx->pc = 0x14a424u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 64));
    // 0x14a428: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a428u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a42c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a42cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a430: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a430u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a434: 0xacc3003c  sw          $v1, 0x3C($a2)
    ctx->pc = 0x14a434u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 60), GPR_U32(ctx, 3));
    // 0x14a438: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x14a438u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14a43c: 0x8d230008  lw          $v1, 0x8($t1)
    ctx->pc = 0x14a43cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x14a440: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a440u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a444: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a444u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a448: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x14a448u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x14a44c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x14a44cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a450: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x14a450u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14a454: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x14a454u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x14a458: 0x90e20004  lbu         $v0, 0x4($a3)
    ctx->pc = 0x14a458u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x14a45c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a45cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a460: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a460u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a464: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a464u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a468: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x14a468u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x14a46c: 0x90e20008  lbu         $v0, 0x8($a3)
    ctx->pc = 0x14a46cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x14a470: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a470u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a474: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a474u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a478: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a478u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a47c: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x14a47cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x14a480: 0x90e2000c  lbu         $v0, 0xC($a3)
    ctx->pc = 0x14a480u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x14a484: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a484u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a488: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a488u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a48c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a48cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a490: 0xacc3000c  sw          $v1, 0xC($a2)
    ctx->pc = 0x14a490u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 3));
    // 0x14a494: 0x90e20010  lbu         $v0, 0x10($a3)
    ctx->pc = 0x14a494u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x14a498: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a498u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a49c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a49cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a4a0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a4a0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a4a4: 0xacc30010  sw          $v1, 0x10($a2)
    ctx->pc = 0x14a4a4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 3));
    // 0x14a4a8: 0x90e20014  lbu         $v0, 0x14($a3)
    ctx->pc = 0x14a4a8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 20)));
    // 0x14a4ac: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a4acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a4b0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a4b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a4b4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a4b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a4b8: 0xacc30014  sw          $v1, 0x14($a2)
    ctx->pc = 0x14a4b8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 20), GPR_U32(ctx, 3));
    // 0x14a4bc: 0x90e20018  lbu         $v0, 0x18($a3)
    ctx->pc = 0x14a4bcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 24)));
    // 0x14a4c0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a4c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a4c4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a4c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a4c8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a4c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a4cc: 0xacc30018  sw          $v1, 0x18($a2)
    ctx->pc = 0x14a4ccu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 24), GPR_U32(ctx, 3));
    // 0x14a4d0: 0x90e2001c  lbu         $v0, 0x1C($a3)
    ctx->pc = 0x14a4d0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 28)));
    // 0x14a4d4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a4d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a4d8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a4d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a4dc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a4dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a4e0: 0xacc3001c  sw          $v1, 0x1C($a2)
    ctx->pc = 0x14a4e0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 28), GPR_U32(ctx, 3));
    // 0x14a4e4: 0x90e20020  lbu         $v0, 0x20($a3)
    ctx->pc = 0x14a4e4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x14a4e8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a4e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a4ec: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a4ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a4f0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a4f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a4f4: 0xacc30020  sw          $v1, 0x20($a2)
    ctx->pc = 0x14a4f4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 32), GPR_U32(ctx, 3));
    // 0x14a4f8: 0x90e20024  lbu         $v0, 0x24($a3)
    ctx->pc = 0x14a4f8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x14a4fc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a4fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a500: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a500u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a504: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a504u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a508: 0xacc30024  sw          $v1, 0x24($a2)
    ctx->pc = 0x14a508u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 36), GPR_U32(ctx, 3));
    // 0x14a50c: 0x90e20028  lbu         $v0, 0x28($a3)
    ctx->pc = 0x14a50cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x14a510: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a510u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a514: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a514u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a518: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a518u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a51c: 0xacc30028  sw          $v1, 0x28($a2)
    ctx->pc = 0x14a51cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 40), GPR_U32(ctx, 3));
    // 0x14a520: 0x90e2002c  lbu         $v0, 0x2C($a3)
    ctx->pc = 0x14a520u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 44)));
    // 0x14a524: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a524u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a528: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a528u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a52c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a52cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a530: 0xacc3002c  sw          $v1, 0x2C($a2)
    ctx->pc = 0x14a530u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 44), GPR_U32(ctx, 3));
    // 0x14a534: 0x90e20030  lbu         $v0, 0x30($a3)
    ctx->pc = 0x14a534u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 48)));
    // 0x14a538: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a538u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a53c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a53cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a540: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a540u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a544: 0xacc30030  sw          $v1, 0x30($a2)
    ctx->pc = 0x14a544u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 3));
    // 0x14a548: 0x90e20034  lbu         $v0, 0x34($a3)
    ctx->pc = 0x14a548u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 52)));
    // 0x14a54c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a54cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a550: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a550u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a554: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a554u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a558: 0xacc30034  sw          $v1, 0x34($a2)
    ctx->pc = 0x14a558u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 52), GPR_U32(ctx, 3));
    // 0x14a55c: 0x90e20038  lbu         $v0, 0x38($a3)
    ctx->pc = 0x14a55cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 56)));
    // 0x14a560: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a560u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a564: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a564u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a568: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a568u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a56c: 0xacc30038  sw          $v1, 0x38($a2)
    ctx->pc = 0x14a56cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 56), GPR_U32(ctx, 3));
    // 0x14a570: 0x90e2003c  lbu         $v0, 0x3C($a3)
    ctx->pc = 0x14a570u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 60)));
    // 0x14a574: 0x24e70040  addiu       $a3, $a3, 0x40
    ctx->pc = 0x14a574u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 64));
    // 0x14a578: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a578u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a57c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a57cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a580: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a580u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a584: 0xacc3003c  sw          $v1, 0x3C($a2)
    ctx->pc = 0x14a584u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 60), GPR_U32(ctx, 3));
    // 0x14a588: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x14a588u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14a58c: 0x8d230008  lw          $v1, 0x8($t1)
    ctx->pc = 0x14a58cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x14a590: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a590u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a594: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a594u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a598: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x14a598u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x14a59c: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x14a59cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a5a0: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x14a5a0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14a5a4: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x14a5a4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x14a5a8: 0x90e20004  lbu         $v0, 0x4($a3)
    ctx->pc = 0x14a5a8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x14a5ac: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a5acu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a5b0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a5b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a5b4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a5b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a5b8: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x14a5b8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x14a5bc: 0x90e20008  lbu         $v0, 0x8($a3)
    ctx->pc = 0x14a5bcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x14a5c0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a5c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a5c4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a5c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a5c8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a5c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a5cc: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x14a5ccu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x14a5d0: 0x90e2000c  lbu         $v0, 0xC($a3)
    ctx->pc = 0x14a5d0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x14a5d4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a5d4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a5d8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a5d8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a5dc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a5dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a5e0: 0xacc3000c  sw          $v1, 0xC($a2)
    ctx->pc = 0x14a5e0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 3));
    // 0x14a5e4: 0x90e20010  lbu         $v0, 0x10($a3)
    ctx->pc = 0x14a5e4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x14a5e8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a5e8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a5ec: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a5ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a5f0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a5f0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a5f4: 0xacc30010  sw          $v1, 0x10($a2)
    ctx->pc = 0x14a5f4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 3));
    // 0x14a5f8: 0x90e20014  lbu         $v0, 0x14($a3)
    ctx->pc = 0x14a5f8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 20)));
    // 0x14a5fc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a5fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a600: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a600u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a604: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a604u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a608: 0xacc30014  sw          $v1, 0x14($a2)
    ctx->pc = 0x14a608u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 20), GPR_U32(ctx, 3));
    // 0x14a60c: 0x90e20018  lbu         $v0, 0x18($a3)
    ctx->pc = 0x14a60cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 24)));
    // 0x14a610: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a610u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a614: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a614u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a618: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a618u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a61c: 0xacc30018  sw          $v1, 0x18($a2)
    ctx->pc = 0x14a61cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 24), GPR_U32(ctx, 3));
    // 0x14a620: 0x90e2001c  lbu         $v0, 0x1C($a3)
    ctx->pc = 0x14a620u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 28)));
    // 0x14a624: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a624u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a628: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a628u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a62c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a62cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a630: 0xacc3001c  sw          $v1, 0x1C($a2)
    ctx->pc = 0x14a630u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 28), GPR_U32(ctx, 3));
    // 0x14a634: 0x90e20020  lbu         $v0, 0x20($a3)
    ctx->pc = 0x14a634u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x14a638: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a638u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a63c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a63cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a640: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a640u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a644: 0xacc30020  sw          $v1, 0x20($a2)
    ctx->pc = 0x14a644u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 32), GPR_U32(ctx, 3));
    // 0x14a648: 0x90e20024  lbu         $v0, 0x24($a3)
    ctx->pc = 0x14a648u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x14a64c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a64cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a650: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a650u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a654: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a654u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a658: 0xacc30024  sw          $v1, 0x24($a2)
    ctx->pc = 0x14a658u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 36), GPR_U32(ctx, 3));
    // 0x14a65c: 0x90e20028  lbu         $v0, 0x28($a3)
    ctx->pc = 0x14a65cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x14a660: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a660u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a664: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a664u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a668: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a668u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a66c: 0xacc30028  sw          $v1, 0x28($a2)
    ctx->pc = 0x14a66cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 40), GPR_U32(ctx, 3));
    // 0x14a670: 0x90e2002c  lbu         $v0, 0x2C($a3)
    ctx->pc = 0x14a670u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 44)));
    // 0x14a674: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a674u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a678: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a678u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a67c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a67cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a680: 0xacc3002c  sw          $v1, 0x2C($a2)
    ctx->pc = 0x14a680u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 44), GPR_U32(ctx, 3));
    // 0x14a684: 0x90e20030  lbu         $v0, 0x30($a3)
    ctx->pc = 0x14a684u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 48)));
    // 0x14a688: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a688u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a68c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a68cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a690: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a690u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a694: 0xacc30030  sw          $v1, 0x30($a2)
    ctx->pc = 0x14a694u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 3));
    // 0x14a698: 0x90e20034  lbu         $v0, 0x34($a3)
    ctx->pc = 0x14a698u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 52)));
    // 0x14a69c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a69cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a6a0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a6a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a6a4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a6a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a6a8: 0xacc30034  sw          $v1, 0x34($a2)
    ctx->pc = 0x14a6a8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 52), GPR_U32(ctx, 3));
    // 0x14a6ac: 0x90e20038  lbu         $v0, 0x38($a3)
    ctx->pc = 0x14a6acu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 56)));
    // 0x14a6b0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a6b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a6b4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a6b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a6b8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a6b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a6bc: 0xacc30038  sw          $v1, 0x38($a2)
    ctx->pc = 0x14a6bcu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 56), GPR_U32(ctx, 3));
    // 0x14a6c0: 0x90e2003c  lbu         $v0, 0x3C($a3)
    ctx->pc = 0x14a6c0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 60)));
    // 0x14a6c4: 0x24e70040  addiu       $a3, $a3, 0x40
    ctx->pc = 0x14a6c4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 64));
    // 0x14a6c8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a6c8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a6cc: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a6ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a6d0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a6d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a6d4: 0xacc3003c  sw          $v1, 0x3C($a2)
    ctx->pc = 0x14a6d4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 60), GPR_U32(ctx, 3));
    // 0x14a6d8: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x14a6d8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14a6dc: 0x8d230008  lw          $v1, 0x8($t1)
    ctx->pc = 0x14a6dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x14a6e0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a6e0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a6e4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a6e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a6e8: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x14a6e8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x14a6ec: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x14a6ecu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a6f0: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x14a6f0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14a6f4: 0xacc40000  sw          $a0, 0x0($a2)
    ctx->pc = 0x14a6f4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x14a6f8: 0x90e20004  lbu         $v0, 0x4($a3)
    ctx->pc = 0x14a6f8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x14a6fc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a6fcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a700: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a700u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a704: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a704u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a708: 0xacc30004  sw          $v1, 0x4($a2)
    ctx->pc = 0x14a708u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x14a70c: 0x90e20008  lbu         $v0, 0x8($a3)
    ctx->pc = 0x14a70cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 8)));
    // 0x14a710: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a710u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a714: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a714u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a718: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a718u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a71c: 0xacc30008  sw          $v1, 0x8($a2)
    ctx->pc = 0x14a71cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 8), GPR_U32(ctx, 3));
    // 0x14a720: 0x90e2000c  lbu         $v0, 0xC($a3)
    ctx->pc = 0x14a720u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 12)));
    // 0x14a724: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a724u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a728: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a728u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a72c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a72cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a730: 0xacc3000c  sw          $v1, 0xC($a2)
    ctx->pc = 0x14a730u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 12), GPR_U32(ctx, 3));
    // 0x14a734: 0x90e20010  lbu         $v0, 0x10($a3)
    ctx->pc = 0x14a734u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 16)));
    // 0x14a738: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a738u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a73c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a73cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a740: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a740u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a744: 0xacc30010  sw          $v1, 0x10($a2)
    ctx->pc = 0x14a744u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 16), GPR_U32(ctx, 3));
    // 0x14a748: 0x90e20014  lbu         $v0, 0x14($a3)
    ctx->pc = 0x14a748u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 20)));
    // 0x14a74c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a74cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a750: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a750u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a754: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a754u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a758: 0xacc30014  sw          $v1, 0x14($a2)
    ctx->pc = 0x14a758u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 20), GPR_U32(ctx, 3));
    // 0x14a75c: 0x90e20018  lbu         $v0, 0x18($a3)
    ctx->pc = 0x14a75cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 24)));
    // 0x14a760: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a760u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a764: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a764u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a768: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a768u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a76c: 0xacc30018  sw          $v1, 0x18($a2)
    ctx->pc = 0x14a76cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 24), GPR_U32(ctx, 3));
    // 0x14a770: 0x90e2001c  lbu         $v0, 0x1C($a3)
    ctx->pc = 0x14a770u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 28)));
    // 0x14a774: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a774u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a778: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a778u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a77c: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a77cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a780: 0xacc3001c  sw          $v1, 0x1C($a2)
    ctx->pc = 0x14a780u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 28), GPR_U32(ctx, 3));
    // 0x14a784: 0x90e20020  lbu         $v0, 0x20($a3)
    ctx->pc = 0x14a784u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 32)));
    // 0x14a788: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a788u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a78c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a78cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a790: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a790u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a794: 0xacc30020  sw          $v1, 0x20($a2)
    ctx->pc = 0x14a794u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 32), GPR_U32(ctx, 3));
    // 0x14a798: 0x90e20024  lbu         $v0, 0x24($a3)
    ctx->pc = 0x14a798u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 36)));
    // 0x14a79c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a79cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a7a0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a7a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a7a4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a7a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a7a8: 0xacc30024  sw          $v1, 0x24($a2)
    ctx->pc = 0x14a7a8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 36), GPR_U32(ctx, 3));
    // 0x14a7ac: 0x90e20028  lbu         $v0, 0x28($a3)
    ctx->pc = 0x14a7acu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 40)));
    // 0x14a7b0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a7b0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a7b4: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a7b4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a7b8: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a7b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a7bc: 0xacc30028  sw          $v1, 0x28($a2)
    ctx->pc = 0x14a7bcu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 40), GPR_U32(ctx, 3));
    // 0x14a7c0: 0x90e2002c  lbu         $v0, 0x2C($a3)
    ctx->pc = 0x14a7c0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 44)));
    // 0x14a7c4: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a7c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a7c8: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a7c8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a7cc: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a7ccu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a7d0: 0xacc3002c  sw          $v1, 0x2C($a2)
    ctx->pc = 0x14a7d0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 44), GPR_U32(ctx, 3));
    // 0x14a7d4: 0x90e20030  lbu         $v0, 0x30($a3)
    ctx->pc = 0x14a7d4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 48)));
    // 0x14a7d8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a7d8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a7dc: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a7dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a7e0: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a7e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a7e4: 0xacc30030  sw          $v1, 0x30($a2)
    ctx->pc = 0x14a7e4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 48), GPR_U32(ctx, 3));
    // 0x14a7e8: 0x90e20034  lbu         $v0, 0x34($a3)
    ctx->pc = 0x14a7e8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 52)));
    // 0x14a7ec: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a7ecu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a7f0: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a7f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a7f4: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a7f4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a7f8: 0xacc30034  sw          $v1, 0x34($a2)
    ctx->pc = 0x14a7f8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 52), GPR_U32(ctx, 3));
    // 0x14a7fc: 0x90e20038  lbu         $v0, 0x38($a3)
    ctx->pc = 0x14a7fcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 56)));
    // 0x14a800: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a800u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a804: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a804u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a808: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a808u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a80c: 0xacc30038  sw          $v1, 0x38($a2)
    ctx->pc = 0x14a80cu;
    WRITE32(ADD32(GPR_U32(ctx, 6), 56), GPR_U32(ctx, 3));
    // 0x14a810: 0x90e2003c  lbu         $v0, 0x3C($a3)
    ctx->pc = 0x14a810u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 60)));
    // 0x14a814: 0x24e70040  addiu       $a3, $a3, 0x40
    ctx->pc = 0x14a814u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 64));
    // 0x14a818: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a818u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a81c: 0x481021  addu        $v0, $v0, $t0
    ctx->pc = 0x14a81cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x14a820: 0x8c430000  lw          $v1, 0x0($v0)
    ctx->pc = 0x14a820u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x14a824: 0xacc3003c  sw          $v1, 0x3C($a2)
    ctx->pc = 0x14a824u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 60), GPR_U32(ctx, 3));
    // 0x14a828: 0x8d220008  lw          $v0, 0x8($t1)
    ctx->pc = 0x14a828u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 9), 8)));
    // 0x14a82c: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x14a82cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14a830: 0x1540fabf  bnez        $t2, . + 4 + (-0x541 << 2)
    ctx->pc = 0x14A830u;
    {
        const bool branch_taken_0x14a830 = (GPR_U64(ctx, 10) != GPR_U64(ctx, 0));
        ctx->pc = 0x14A834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14A830u;
            // 0x14a834: 0xc23021  addu        $a2, $a2, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14a830) {
            ctx->pc = 0x149330u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_149330;
        }
    }
    ctx->pc = 0x14A838u;
label_14a838:
    // 0x14a838: 0x258cffff  addiu       $t4, $t4, -0x1
    ctx->pc = 0x14a838u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 12), 4294967295));
    // 0x14a83c: 0x1580fab8  bnez        $t4, . + 4 + (-0x548 << 2)
    ctx->pc = 0x14A83Cu;
    {
        const bool branch_taken_0x14a83c = (GPR_U64(ctx, 12) != GPR_U64(ctx, 0));
        ctx->pc = 0x14A840u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14A83Cu;
            // 0x14a840: 0x256b0040  addiu       $t3, $t3, 0x40 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), 64));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14a83c) {
            ctx->pc = 0x149320u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_149320;
        }
    }
    ctx->pc = 0x14A844u;
label_14a844:
    // 0x14a844: 0x3e00008  jr          $ra
    ctx->pc = 0x14A844u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x149320u: goto label_149320;
            case 0x149330u: goto label_149330;
            case 0x14A838u: goto label_14a838;
            case 0x14A844u: goto label_14a844;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14A84Cu;
    // 0x14a84c: 0x0  nop
    ctx->pc = 0x14a84cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
