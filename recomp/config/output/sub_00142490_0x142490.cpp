#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00142490
// Address: 0x142490 - 0x142b98
void sub_00142490_0x142490(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00142490_0x142490");
#endif

    switch (ctx->pc) {
        case 0x1425acu: goto label_1425ac;
        case 0x1425ecu: goto label_1425ec;
        case 0x142618u: goto label_142618;
        case 0x142658u: goto label_142658;
        case 0x142694u: goto label_142694;
        case 0x1426d4u: goto label_1426d4;
        case 0x14271cu: goto label_14271c;
        case 0x142820u: goto label_142820;
        case 0x1428c0u: goto label_1428c0;
        case 0x142908u: goto label_142908;
        case 0x142958u: goto label_142958;
        case 0x142970u: goto label_142970;
        case 0x142a14u: goto label_142a14;
        case 0x142a54u: goto label_142a54;
        case 0x142aacu: goto label_142aac;
        case 0x142b04u: goto label_142b04;
        case 0x142b4cu: goto label_142b4c;
        case 0x142b64u: goto label_142b64;
        default: break;
    }

    ctx->pc = 0x142490u;

    // 0x142490: 0x27bdff10  addiu       $sp, $sp, -0xF0
    ctx->pc = 0x142490u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967056));
    // 0x142494: 0x24030140  addiu       $v1, $zero, 0x140
    ctx->pc = 0x142494u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 320));
    // 0x142498: 0xffbe00d0  sd          $fp, 0xD0($sp)
    ctx->pc = 0x142498u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 208), GPR_U64(ctx, 30));
    // 0x14249c: 0xffb600b0  sd          $s6, 0xB0($sp)
    ctx->pc = 0x14249cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 22));
    // 0x1424a0: 0x140f02d  daddu       $fp, $t2, $zero
    ctx->pc = 0x1424a0u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1424a4: 0xffb500a0  sd          $s5, 0xA0($sp)
    ctx->pc = 0x1424a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 21));
    // 0x1424a8: 0xc0b02d  daddu       $s6, $a2, $zero
    ctx->pc = 0x1424a8u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1424ac: 0xffb40090  sd          $s4, 0x90($sp)
    ctx->pc = 0x1424acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 20));
    // 0x1424b0: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x1424b0u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1424b4: 0xffb30080  sd          $s3, 0x80($sp)
    ctx->pc = 0x1424b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 19));
    // 0x1424b8: 0x100a02d  daddu       $s4, $t0, $zero
    ctx->pc = 0x1424b8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1424bc: 0xffb20070  sd          $s2, 0x70($sp)
    ctx->pc = 0x1424bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 18));
    // 0x1424c0: 0x24130001  addiu       $s3, $zero, 0x1
    ctx->pc = 0x1424c0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1424c4: 0xffb10060  sd          $s1, 0x60($sp)
    ctx->pc = 0x1424c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 17));
    // 0x1424c8: 0x120902d  daddu       $s2, $t1, $zero
    ctx->pc = 0x1424c8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1424cc: 0xffb00050  sd          $s0, 0x50($sp)
    ctx->pc = 0x1424ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 16));
    // 0x1424d0: 0x80882d  daddu       $s1, $a0, $zero
    ctx->pc = 0x1424d0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1424d4: 0xffbf00e0  sd          $ra, 0xE0($sp)
    ctx->pc = 0x1424d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 224), GPR_U64(ctx, 31));
    // 0x1424d8: 0x802d  daddu       $s0, $zero, $zero
    ctx->pc = 0x1424d8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1424dc: 0xffb700c0  sd          $s7, 0xC0($sp)
    ctx->pc = 0x1424dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 23));
    // 0x1424e0: 0x8e220828  lw          $v0, 0x828($s1)
    ctx->pc = 0x1424e0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 2088)));
    // 0x1424e4: 0xafa70040  sw          $a3, 0x40($sp)
    ctx->pc = 0x1424e4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 7));
    // 0x1424e8: 0x432018  mult        $a0, $v0, $v1
    ctx->pc = 0x1424e8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x1424ec: 0x30ec0008  andi        $t4, $a3, 0x8
    ctx->pc = 0x1424ecu;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)8);
    // 0x1424f0: 0x911021  addu        $v0, $a0, $s1
    ctx->pc = 0x1424f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1424f4: 0x15800005  bnez        $t4, . + 4 + (0x5 << 2)
    ctx->pc = 0x1424F4u;
    {
        const bool branch_taken_0x1424f4 = (GPR_U64(ctx, 12) != GPR_U64(ctx, 0));
        ctx->pc = 0x1424F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1424F4u;
            // 0x1424f8: 0xac4006d4  sw          $zero, 0x6D4($v0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 2), 1748), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1424f4) {
            ctx->pc = 0x14250Cu;
            goto label_14250c;
        }
    }
    ctx->pc = 0x1424FCu;
    // 0x1424fc: 0x8e230168  lw          $v1, 0x168($s1)
    ctx->pc = 0x1424fcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 360)));
    // 0x142500: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x142500u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x142504: 0x1462011c  bne         $v1, $v0, . + 4 + (0x11C << 2)
    ctx->pc = 0x142504u;
    {
        const bool branch_taken_0x142504 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x142508u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142504u;
            // 0x142508: 0x8fa40040  lw          $a0, 0x40($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142504) {
            ctx->pc = 0x142978u;
            goto label_142978;
        }
    }
    ctx->pc = 0x14250Cu;
label_14250c:
    // 0x14250c: 0x8e23018c  lw          $v1, 0x18C($s1)
    ctx->pc = 0x14250cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 396)));
    // 0x142510: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x142510u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x142514: 0x14620083  bne         $v1, $v0, . + 4 + (0x83 << 2)
    ctx->pc = 0x142514u;
    {
        const bool branch_taken_0x142514 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x142518u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142514u;
            // 0x142518: 0x38620002  xori        $v0, $v1, 0x2 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)2);
        ctx->in_delay_slot = false;
        if (branch_taken_0x142514) {
            ctx->pc = 0x142724u;
            goto label_142724;
        }
    }
    ctx->pc = 0x14251Cu;
    // 0x14251c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x14251cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x142520: 0x52820004  beql        $s4, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x142520u;
    {
        const bool branch_taken_0x142520 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 2));
        if (branch_taken_0x142520) {
            ctx->pc = 0x142524u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x142520u;
            // 0x142524: 0x8e420000  lw          $v0, 0x0($s2) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x142534u;
            goto label_142534;
        }
    }
    ctx->pc = 0x142528u;
    // 0x142528: 0x1580000f  bnez        $t4, . + 4 + (0xF << 2)
    ctx->pc = 0x142528u;
    {
        const bool branch_taken_0x142528 = (GPR_U64(ctx, 12) != GPR_U64(ctx, 0));
        if (branch_taken_0x142528) {
            ctx->pc = 0x142568u;
            goto label_142568;
        }
    }
    ctx->pc = 0x142530u;
    // 0x142530: 0x8e420000  lw          $v0, 0x0($s2)
    ctx->pc = 0x142530u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_142534:
    // 0x142534: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x142534u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142538: 0x8e430004  lw          $v1, 0x4($s2)
    ctx->pc = 0x142538u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x14253c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x14253cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142540: 0x8e2501d0  lw          $a1, 0x1D0($s1)
    ctx->pc = 0x142540u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 464)));
    // 0x142544: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x142544u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142548: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x142548u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x14254c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x14254cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142550: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x142550u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x142554: 0x24090010  addiu       $t1, $zero, 0x10
    ctx->pc = 0x142554u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x142558: 0xafa00010  sw          $zero, 0x10($sp)
    ctx->pc = 0x142558u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x14255c: 0x2a0502d  daddu       $t2, $s5, $zero
    ctx->pc = 0x14255cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142560: 0x100000fb  b           . + 4 + (0xFB << 2)
    ctx->pc = 0x142560u;
    {
        const bool branch_taken_0x142560 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x142564u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142560u;
            // 0x142564: 0xafa00018  sw          $zero, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142560) {
            ctx->pc = 0x142950u;
            goto label_142950;
        }
    }
    ctx->pc = 0x142568u;
label_142568:
    // 0x142568: 0x16930022  bne         $s4, $s3, . + 4 + (0x22 << 2)
    ctx->pc = 0x142568u;
    {
        const bool branch_taken_0x142568 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 19));
        ctx->pc = 0x14256Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142568u;
            // 0x14256c: 0x220202d  daddu       $a0, $s1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142568) {
            ctx->pc = 0x1425F4u;
            goto label_1425f4;
        }
    }
    ctx->pc = 0x142570u;
    // 0x142570: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x142570u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x142574: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x142574u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x142578: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x142578u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14257c: 0x8e2501d0  lw          $a1, 0x1D0($s1)
    ctx->pc = 0x14257cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 464)));
    // 0x142580: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x142580u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x142584: 0x8fc60000  lw          $a2, 0x0($fp)
    ctx->pc = 0x142584u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x142588: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x142588u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14258c: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x14258cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x142590: 0x24090008  addiu       $t1, $zero, 0x8
    ctx->pc = 0x142590u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x142594: 0xafa20008  sw          $v0, 0x8($sp)
    ctx->pc = 0x142594u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
    // 0x142598: 0x2a0502d  daddu       $t2, $s5, $zero
    ctx->pc = 0x142598u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14259c: 0xafb40010  sw          $s4, 0x10($sp)
    ctx->pc = 0x14259cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 20));
    // 0x1425a0: 0x2c0582d  daddu       $t3, $s6, $zero
    ctx->pc = 0x1425a0u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1425a4: 0xc050ae6  jal         func_142B98
    ctx->pc = 0x1425A4u;
    SET_GPR_U32(ctx, 31, 0x1425ACu);
    ctx->pc = 0x1425A8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1425A4u;
            // 0x1425a8: 0xafa00018  sw          $zero, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142B98u;
    if (runtime->hasFunction(0x142B98u)) {
        auto targetFn = runtime->lookupFunction(0x142B98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1425ACu; }
        if (ctx->pc != 0x1425ACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142B98_0x142b98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1425ACu; }
        if (ctx->pc != 0x1425ACu) { return; }
    }
    ctx->pc = 0x1425ACu;
label_1425ac:
    // 0x1425ac: 0x8e420014  lw          $v0, 0x14($s2)
    ctx->pc = 0x1425acu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 20)));
    // 0x1425b0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1425b0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1425b4: 0x8e430010  lw          $v1, 0x10($s2)
    ctx->pc = 0x1425b4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x1425b8: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1425b8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1425bc: 0x8e2501d0  lw          $a1, 0x1D0($s1)
    ctx->pc = 0x1425bcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 464)));
    // 0x1425c0: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x1425c0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x1425c4: 0x8fc60008  lw          $a2, 0x8($fp)
    ctx->pc = 0x1425c4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1425c8: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1425c8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1425cc: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x1425ccu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x1425d0: 0x24090008  addiu       $t1, $zero, 0x8
    ctx->pc = 0x1425d0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1425d4: 0xafa20008  sw          $v0, 0x8($sp)
    ctx->pc = 0x1425d4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
    // 0x1425d8: 0x2a0502d  daddu       $t2, $s5, $zero
    ctx->pc = 0x1425d8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1425dc: 0xafb40010  sw          $s4, 0x10($sp)
    ctx->pc = 0x1425dcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 20));
    // 0x1425e0: 0x2c0582d  daddu       $t3, $s6, $zero
    ctx->pc = 0x1425e0u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1425e4: 0xc050ae6  jal         func_142B98
    ctx->pc = 0x1425E4u;
    SET_GPR_U32(ctx, 31, 0x1425ECu);
    ctx->pc = 0x1425E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1425E4u;
            // 0x1425e8: 0xafa00018  sw          $zero, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142B98u;
    if (runtime->hasFunction(0x142B98u)) {
        auto targetFn = runtime->lookupFunction(0x142B98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1425ECu; }
        if (ctx->pc != 0x1425ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142B98_0x142b98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1425ECu; }
        if (ctx->pc != 0x1425ECu) { return; }
    }
    ctx->pc = 0x1425ECu;
label_1425ec:
    // 0x1425ec: 0x100000e1  b           . + 4 + (0xE1 << 2)
    ctx->pc = 0x1425ECu;
    {
        const bool branch_taken_0x1425ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1425F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1425ECu;
            // 0x1425f0: 0x24100001  addiu       $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1425ec) {
            ctx->pc = 0x142974u;
            goto label_142974;
        }
    }
    ctx->pc = 0x1425F4u;
label_1425f4:
    // 0x1425f4: 0x16830045  bne         $s4, $v1, . + 4 + (0x45 << 2)
    ctx->pc = 0x1425F4u;
    {
        const bool branch_taken_0x1425f4 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 3));
        ctx->pc = 0x1425F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1425F4u;
            // 0x1425f8: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1425f4) {
            ctx->pc = 0x14270Cu;
            goto label_14270c;
        }
    }
    ctx->pc = 0x1425FCu;
    // 0x1425fc: 0x8e480004  lw          $t0, 0x4($s2)
    ctx->pc = 0x1425fcu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x142600: 0x160302d  daddu       $a2, $t3, $zero
    ctx->pc = 0x142600u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142604: 0x8e470000  lw          $a3, 0x0($s2)
    ctx->pc = 0x142604u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x142608: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x142608u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14260c: 0x84043  sra         $t0, $t0, 1
    ctx->pc = 0x14260cu;
    SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 8), 1));
    // 0x142610: 0xc05109a  jal         func_144268
    ctx->pc = 0x142610u;
    SET_GPR_U32(ctx, 31, 0x142618u);
    ctx->pc = 0x142614u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x142610u;
            // 0x142614: 0x27a50020  addiu       $a1, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x144268u;
    if (runtime->hasFunction(0x144268u)) {
        auto targetFn = runtime->lookupFunction(0x144268u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142618u; }
        if (ctx->pc != 0x142618u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00144268_0x144268(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142618u; }
        if (ctx->pc != 0x142618u) { return; }
    }
    ctx->pc = 0x142618u;
label_142618:
    // 0x142618: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x142618u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x14261c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x14261cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142620: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x142620u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x142624: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x142624u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142628: 0x8e2501d0  lw          $a1, 0x1D0($s1)
    ctx->pc = 0x142628u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 464)));
    // 0x14262c: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x14262cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x142630: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x142630u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x142634: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x142634u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142638: 0xafa20008  sw          $v0, 0x8($sp)
    ctx->pc = 0x142638u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
    // 0x14263c: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x14263cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142640: 0xafb30010  sw          $s3, 0x10($sp)
    ctx->pc = 0x142640u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 19));
    // 0x142644: 0x24090008  addiu       $t1, $zero, 0x8
    ctx->pc = 0x142644u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x142648: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x142648u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x14264c: 0x2a0502d  daddu       $t2, $s5, $zero
    ctx->pc = 0x14264cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142650: 0xc050ae6  jal         func_142B98
    ctx->pc = 0x142650u;
    SET_GPR_U32(ctx, 31, 0x142658u);
    ctx->pc = 0x142654u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x142650u;
            // 0x142654: 0x2c0582d  daddu       $t3, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142B98u;
    if (runtime->hasFunction(0x142B98u)) {
        auto targetFn = runtime->lookupFunction(0x142B98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142658u; }
        if (ctx->pc != 0x142658u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142B98_0x142b98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142658u; }
        if (ctx->pc != 0x142658u) { return; }
    }
    ctx->pc = 0x142658u;
label_142658:
    // 0x142658: 0x8fa20020  lw          $v0, 0x20($sp)
    ctx->pc = 0x142658u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x14265c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x14265cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142660: 0x8fa30024  lw          $v1, 0x24($sp)
    ctx->pc = 0x142660u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x142664: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x142664u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x142668: 0x8e2501d0  lw          $a1, 0x1D0($s1)
    ctx->pc = 0x142668u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 464)));
    // 0x14266c: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x14266cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142670: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x142670u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x142674: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x142674u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142678: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x142678u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x14267c: 0x24090008  addiu       $t1, $zero, 0x8
    ctx->pc = 0x14267cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x142680: 0xafb30010  sw          $s3, 0x10($sp)
    ctx->pc = 0x142680u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 19));
    // 0x142684: 0x2a0502d  daddu       $t2, $s5, $zero
    ctx->pc = 0x142684u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142688: 0xafb30018  sw          $s3, 0x18($sp)
    ctx->pc = 0x142688u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 19));
    // 0x14268c: 0xc050ae6  jal         func_142B98
    ctx->pc = 0x14268Cu;
    SET_GPR_U32(ctx, 31, 0x142694u);
    ctx->pc = 0x142690u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x14268Cu;
            // 0x142690: 0x2c0582d  daddu       $t3, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142B98u;
    if (runtime->hasFunction(0x142B98u)) {
        auto targetFn = runtime->lookupFunction(0x142B98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142694u; }
        if (ctx->pc != 0x142694u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142B98_0x142b98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142694u; }
        if (ctx->pc != 0x142694u) { return; }
    }
    ctx->pc = 0x142694u;
label_142694:
    // 0x142694: 0x8e420004  lw          $v0, 0x4($s2)
    ctx->pc = 0x142694u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x142698: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x142698u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14269c: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x14269cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1426a0: 0x24060001  addiu       $a2, $zero, 0x1
    ctx->pc = 0x1426a0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1426a4: 0x8e2501d0  lw          $a1, 0x1D0($s1)
    ctx->pc = 0x1426a4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 464)));
    // 0x1426a8: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x1426a8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x1426ac: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x1426acu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x1426b0: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1426b0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1426b4: 0xafa20008  sw          $v0, 0x8($sp)
    ctx->pc = 0x1426b4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
    // 0x1426b8: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1426b8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1426bc: 0xafb30010  sw          $s3, 0x10($sp)
    ctx->pc = 0x1426bcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 19));
    // 0x1426c0: 0x24090008  addiu       $t1, $zero, 0x8
    ctx->pc = 0x1426c0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1426c4: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x1426c4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x1426c8: 0x2a0502d  daddu       $t2, $s5, $zero
    ctx->pc = 0x1426c8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1426cc: 0xc050ae6  jal         func_142B98
    ctx->pc = 0x1426CCu;
    SET_GPR_U32(ctx, 31, 0x1426D4u);
    ctx->pc = 0x1426D0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1426CCu;
            // 0x1426d0: 0x2c0582d  daddu       $t3, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142B98u;
    if (runtime->hasFunction(0x142B98u)) {
        auto targetFn = runtime->lookupFunction(0x142B98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1426D4u; }
        if (ctx->pc != 0x1426D4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142B98_0x142b98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1426D4u; }
        if (ctx->pc != 0x1426D4u) { return; }
    }
    ctx->pc = 0x1426D4u;
label_1426d4:
    // 0x1426d4: 0x8fa20028  lw          $v0, 0x28($sp)
    ctx->pc = 0x1426d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1426d8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1426d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1426dc: 0x8fa3002c  lw          $v1, 0x2C($sp)
    ctx->pc = 0x1426dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
    // 0x1426e0: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1426e0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1426e4: 0x8e2501d0  lw          $a1, 0x1D0($s1)
    ctx->pc = 0x1426e4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 464)));
    // 0x1426e8: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x1426e8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1426ec: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x1426ecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x1426f0: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1426f0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1426f4: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x1426f4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x1426f8: 0x24090008  addiu       $t1, $zero, 0x8
    ctx->pc = 0x1426f8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1426fc: 0xafb30018  sw          $s3, 0x18($sp)
    ctx->pc = 0x1426fcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 19));
    // 0x142700: 0x2a0502d  daddu       $t2, $s5, $zero
    ctx->pc = 0x142700u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142704: 0x10000092  b           . + 4 + (0x92 << 2)
    ctx->pc = 0x142704u;
    {
        const bool branch_taken_0x142704 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x142708u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142704u;
            // 0x142708: 0xafb30010  sw          $s3, 0x10($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 19));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142704) {
            ctx->pc = 0x142950u;
            goto label_142950;
        }
    }
    ctx->pc = 0x14270Cu;
label_14270c:
    // 0x14270c: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x14270cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142710: 0x24a5dd50  addiu       $a1, $a1, -0x22B0
    ctx->pc = 0x142710u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294958416));
    // 0x142714: 0xc05220e  jal         func_148838
    ctx->pc = 0x142714u;
    SET_GPR_U32(ctx, 31, 0x14271Cu);
    ctx->pc = 0x142718u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x142714u;
            // 0x142718: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148838u;
    if (runtime->hasFunction(0x148838u)) {
        auto targetFn = runtime->lookupFunction(0x148838u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14271Cu; }
        if (ctx->pc != 0x14271Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148838_0x148838(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14271Cu; }
        if (ctx->pc != 0x14271Cu) { return; }
    }
    ctx->pc = 0x14271Cu;
label_14271c:
    // 0x14271c: 0x10000095  b           . + 4 + (0x95 << 2)
    ctx->pc = 0x14271Cu;
    {
        const bool branch_taken_0x14271c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x142720u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14271Cu;
            // 0x142720: 0x24100001  addiu       $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14271c) {
            ctx->pc = 0x142974u;
            goto label_142974;
        }
    }
    ctx->pc = 0x142724u;
label_142724:
    // 0x142724: 0x8e2701e0  lw          $a3, 0x1E0($s1)
    ctx->pc = 0x142724u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 480)));
    // 0x142728: 0x8e2501f0  lw          $a1, 0x1F0($s1)
    ctx->pc = 0x142728u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 496)));
    // 0x14272c: 0x2c570001  sltiu       $s7, $v0, 0x1
    ctx->pc = 0x14272cu;
    SET_GPR_U64(ctx, 23, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x142730: 0x8e2401e4  lw          $a0, 0x1E4($s1)
    ctx->pc = 0x142730u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 484)));
    // 0x142734: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x142734u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x142738: 0x8e2301f4  lw          $v1, 0x1F4($s1)
    ctx->pc = 0x142738u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 500)));
    // 0x14273c: 0x982d  daddu       $s3, $zero, $zero
    ctx->pc = 0x14273cu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142740: 0x8e220168  lw          $v0, 0x168($s1)
    ctx->pc = 0x142740u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 360)));
    // 0x142744: 0xafa70030  sw          $a3, 0x30($sp)
    ctx->pc = 0x142744u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 7));
    // 0x142748: 0xafa50034  sw          $a1, 0x34($sp)
    ctx->pc = 0x142748u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 52), GPR_U32(ctx, 5));
    // 0x14274c: 0xafa40038  sw          $a0, 0x38($sp)
    ctx->pc = 0x14274cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 4));
    // 0x142750: 0x14460007  bne         $v0, $a2, . + 4 + (0x7 << 2)
    ctx->pc = 0x142750u;
    {
        const bool branch_taken_0x142750 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 6));
        ctx->pc = 0x142754u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142750u;
            // 0x142754: 0xafa3003c  sw          $v1, 0x3C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 60), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142750) {
            ctx->pc = 0x142770u;
            goto label_142770;
        }
    }
    ctx->pc = 0x142758u;
    // 0x142758: 0x8e220138  lw          $v0, 0x138($s1)
    ctx->pc = 0x142758u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 312)));
    // 0x14275c: 0x10400005  beqz        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x14275Cu;
    {
        const bool branch_taken_0x14275c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x142760u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14275Cu;
            // 0x142760: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14275c) {
            ctx->pc = 0x142774u;
            goto label_142774;
        }
    }
    ctx->pc = 0x142764u;
    // 0x142764: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x142764u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x142768: 0x2e21026  xor         $v0, $s7, $v0
    ctx->pc = 0x142768u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) ^ GPR_U64(ctx, 2));
    // 0x14276c: 0x2982b  sltu        $s3, $zero, $v0
    ctx->pc = 0x14276cu;
    SET_GPR_U64(ctx, 19, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
label_142770:
    // 0x142770: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x142770u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_142774:
    // 0x142774: 0x52820004  beql        $s4, $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x142774u;
    {
        const bool branch_taken_0x142774 = (GPR_U64(ctx, 20) == GPR_U64(ctx, 2));
        if (branch_taken_0x142774) {
            ctx->pc = 0x142778u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x142774u;
            // 0x142778: 0x8fc20000  lw          $v0, 0x0($fp) (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x142788u;
            goto label_142788;
        }
    }
    ctx->pc = 0x14277Cu;
    // 0x14277c: 0x15800011  bnez        $t4, . + 4 + (0x11 << 2)
    ctx->pc = 0x14277Cu;
    {
        const bool branch_taken_0x14277c = (GPR_U64(ctx, 12) != GPR_U64(ctx, 0));
        ctx->pc = 0x142780u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14277Cu;
            // 0x142780: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14277c) {
            ctx->pc = 0x1427C4u;
            goto label_1427c4;
        }
    }
    ctx->pc = 0x142784u;
    // 0x142784: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x142784u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
label_142788:
    // 0x142788: 0x1318c0  sll         $v1, $s3, 3
    ctx->pc = 0x142788u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14278c: 0x8e460000  lw          $a2, 0x0($s2)
    ctx->pc = 0x14278cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x142790: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x142790u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142794: 0x8e450004  lw          $a1, 0x4($s2)
    ctx->pc = 0x142794u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x142798: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x142798u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x14279c: 0xafa60000  sw          $a2, 0x0($sp)
    ctx->pc = 0x14279cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 6));
    // 0x1427a0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1427a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1427a4: 0x3a21821  addu        $v1, $sp, $v0
    ctx->pc = 0x1427a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 2)));
    // 0x1427a8: 0xafa50008  sw          $a1, 0x8($sp)
    ctx->pc = 0x1427a8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 5));
    // 0x1427ac: 0x8c650030  lw          $a1, 0x30($v1)
    ctx->pc = 0x1427acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 48)));
    // 0x1427b0: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1427b0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1427b4: 0xafa00010  sw          $zero, 0x10($sp)
    ctx->pc = 0x1427b4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x1427b8: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1427b8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1427bc: 0x10000061  b           . + 4 + (0x61 << 2)
    ctx->pc = 0x1427BCu;
    {
        const bool branch_taken_0x1427bc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1427C0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1427BCu;
            // 0x1427c0: 0xafa00018  sw          $zero, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1427bc) {
            ctx->pc = 0x142944u;
            goto label_142944;
        }
    }
    ctx->pc = 0x1427C4u;
label_1427c4:
    // 0x1427c4: 0x16820033  bne         $s4, $v0, . + 4 + (0x33 << 2)
    ctx->pc = 0x1427C4u;
    {
        const bool branch_taken_0x1427c4 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 2));
        ctx->pc = 0x1427C8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1427C4u;
            // 0x1427c8: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1427c4) {
            ctx->pc = 0x142894u;
            goto label_142894;
        }
    }
    ctx->pc = 0x1427CCu;
    // 0x1427cc: 0x8fc20000  lw          $v0, 0x0($fp)
    ctx->pc = 0x1427ccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1427d0: 0x1328c0  sll         $a1, $s3, 3
    ctx->pc = 0x1427d0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x1427d4: 0x8e440004  lw          $a0, 0x4($s2)
    ctx->pc = 0x1427d4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x1427d8: 0x27b00030  addiu       $s0, $sp, 0x30
    ctx->pc = 0x1427d8u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1427dc: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x1427dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1427e0: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1427e0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1427e4: 0x451021  addu        $v0, $v0, $a1
    ctx->pc = 0x1427e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1427e8: 0xafa40008  sw          $a0, 0x8($sp)
    ctx->pc = 0x1427e8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 4));
    // 0x1427ec: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x1427ecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x1427f0: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x1427f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1427f4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1427f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1427f8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1427f8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1427fc: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1427fcu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x142800: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x142800u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142804: 0xafa00010  sw          $zero, 0x10($sp)
    ctx->pc = 0x142804u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x142808: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x142808u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14280c: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x14280cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x142810: 0x24090008  addiu       $t1, $zero, 0x8
    ctx->pc = 0x142810u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x142814: 0x2a0502d  daddu       $t2, $s5, $zero
    ctx->pc = 0x142814u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142818: 0xc050ae6  jal         func_142B98
    ctx->pc = 0x142818u;
    SET_GPR_U32(ctx, 31, 0x142820u);
    ctx->pc = 0x14281Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x142818u;
            // 0x14281c: 0x2c0582d  daddu       $t3, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142B98u;
    if (runtime->hasFunction(0x142B98u)) {
        auto targetFn = runtime->lookupFunction(0x142B98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142820u; }
        if (ctx->pc != 0x142820u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142B98_0x142b98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142820u; }
        if (ctx->pc != 0x142820u) { return; }
    }
    ctx->pc = 0x142820u;
label_142820:
    // 0x142820: 0x8e220168  lw          $v0, 0x168($s1)
    ctx->pc = 0x142820u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 360)));
    // 0x142824: 0x14540008  bne         $v0, $s4, . + 4 + (0x8 << 2)
    ctx->pc = 0x142824u;
    {
        const bool branch_taken_0x142824 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 20));
        ctx->pc = 0x142828u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142824u;
            // 0x142828: 0x982d  daddu       $s3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142824) {
            ctx->pc = 0x142848u;
            goto label_142848;
        }
    }
    ctx->pc = 0x14282Cu;
    // 0x14282c: 0x8e220138  lw          $v0, 0x138($s1)
    ctx->pc = 0x14282cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 312)));
    // 0x142830: 0x10400006  beqz        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x142830u;
    {
        const bool branch_taken_0x142830 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x142834u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142830u;
            // 0x142834: 0x8fc30008  lw          $v1, 0x8($fp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142830) {
            ctx->pc = 0x14284Cu;
            goto label_14284c;
        }
    }
    ctx->pc = 0x142838u;
    // 0x142838: 0x24130001  addiu       $s3, $zero, 0x1
    ctx->pc = 0x142838u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x14283c: 0x2e31026  xor         $v0, $s7, $v1
    ctx->pc = 0x14283cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 23) ^ GPR_U64(ctx, 3));
    // 0x142840: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x142840u;
    {
        const bool branch_taken_0x142840 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x142844u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142840u;
            // 0x142844: 0x2980a  movz        $s3, $zero, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 19, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142840) {
            ctx->pc = 0x14284Cu;
            goto label_14284c;
        }
    }
    ctx->pc = 0x142848u;
label_142848:
    // 0x142848: 0x8fc30008  lw          $v1, 0x8($fp)
    ctx->pc = 0x142848u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 8)));
label_14284c:
    // 0x14284c: 0x31080  sll         $v0, $v1, 2
    ctx->pc = 0x14284cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x142850: 0x8e460010  lw          $a2, 0x10($s2)
    ctx->pc = 0x142850u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 16)));
    // 0x142854: 0x1318c0  sll         $v1, $s3, 3
    ctx->pc = 0x142854u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x142858: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x142858u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14285c: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x14285cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x142860: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x142860u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142864: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x142864u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x142868: 0x8e430014  lw          $v1, 0x14($s2)
    ctx->pc = 0x142868u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 20)));
    // 0x14286c: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x14286cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x142870: 0x24080008  addiu       $t0, $zero, 0x8
    ctx->pc = 0x142870u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x142874: 0xafa60000  sw          $a2, 0x0($sp)
    ctx->pc = 0x142874u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 6));
    // 0x142878: 0x24090008  addiu       $t1, $zero, 0x8
    ctx->pc = 0x142878u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x14287c: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x14287cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142880: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x142880u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x142884: 0xafa00010  sw          $zero, 0x10($sp)
    ctx->pc = 0x142884u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x142888: 0x2a0502d  daddu       $t2, $s5, $zero
    ctx->pc = 0x142888u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14288c: 0x10000030  b           . + 4 + (0x30 << 2)
    ctx->pc = 0x14288Cu;
    {
        const bool branch_taken_0x14288c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x142890u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14288Cu;
            // 0x142890: 0xafa00018  sw          $zero, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14288c) {
            ctx->pc = 0x142950u;
            goto label_142950;
        }
    }
    ctx->pc = 0x142894u;
label_142894:
    // 0x142894: 0x16820032  bne         $s4, $v0, . + 4 + (0x32 << 2)
    ctx->pc = 0x142894u;
    {
        const bool branch_taken_0x142894 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 2));
        ctx->pc = 0x142898u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142894u;
            // 0x142898: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142894) {
            ctx->pc = 0x142960u;
            goto label_142960;
        }
    }
    ctx->pc = 0x14289Cu;
    // 0x14289c: 0x8e220138  lw          $v0, 0x138($s1)
    ctx->pc = 0x14289cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 312)));
    // 0x1428a0: 0x24130001  addiu       $s3, $zero, 0x1
    ctx->pc = 0x1428a0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1428a4: 0x8e470000  lw          $a3, 0x0($s2)
    ctx->pc = 0x1428a4u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1428a8: 0x160302d  daddu       $a2, $t3, $zero
    ctx->pc = 0x1428a8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1428ac: 0x8e480004  lw          $t0, 0x4($s2)
    ctx->pc = 0x1428acu;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x1428b0: 0x2980a  movz        $s3, $zero, $v0
    ctx->pc = 0x1428b0u;
    if (GPR_U64(ctx, 2) == 0) SET_GPR_VEC(ctx, 19, GPR_VEC(ctx, 0));
    // 0x1428b4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1428b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1428b8: 0xc05109a  jal         func_144268
    ctx->pc = 0x1428B8u;
    SET_GPR_U32(ctx, 31, 0x1428C0u);
    ctx->pc = 0x1428BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1428B8u;
            // 0x1428bc: 0x27a50020  addiu       $a1, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x144268u;
    if (runtime->hasFunction(0x144268u)) {
        auto targetFn = runtime->lookupFunction(0x144268u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1428C0u; }
        if (ctx->pc != 0x1428C0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00144268_0x144268(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1428C0u; }
        if (ctx->pc != 0x1428C0u) { return; }
    }
    ctx->pc = 0x1428C0u;
label_1428c0:
    // 0x1428c0: 0x27b00030  addiu       $s0, $sp, 0x30
    ctx->pc = 0x1428c0u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
    // 0x1428c4: 0x171080  sll         $v0, $s7, 2
    ctx->pc = 0x1428c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 23), 2));
    // 0x1428c8: 0x8e480004  lw          $t0, 0x4($s2)
    ctx->pc = 0x1428c8u;
    SET_GPR_S32(ctx, 8, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 4)));
    // 0x1428cc: 0x2021021  addu        $v0, $s0, $v0
    ctx->pc = 0x1428ccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x1428d0: 0x8e430000  lw          $v1, 0x0($s2)
    ctx->pc = 0x1428d0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1428d4: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1428d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1428d8: 0x8c450000  lw          $a1, 0x0($v0)
    ctx->pc = 0x1428d8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1428dc: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1428dcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1428e0: 0xafa80008  sw          $t0, 0x8($sp)
    ctx->pc = 0x1428e0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 8));
    // 0x1428e4: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1428e4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1428e8: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x1428e8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x1428ec: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1428ecu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1428f0: 0xafa00010  sw          $zero, 0x10($sp)
    ctx->pc = 0x1428f0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x1428f4: 0x24090010  addiu       $t1, $zero, 0x10
    ctx->pc = 0x1428f4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1428f8: 0xafa00018  sw          $zero, 0x18($sp)
    ctx->pc = 0x1428f8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 0));
    // 0x1428fc: 0x2a0502d  daddu       $t2, $s5, $zero
    ctx->pc = 0x1428fcu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142900: 0xc050ae6  jal         func_142B98
    ctx->pc = 0x142900u;
    SET_GPR_U32(ctx, 31, 0x142908u);
    ctx->pc = 0x142904u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x142900u;
            // 0x142904: 0x2c0582d  daddu       $t3, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142B98u;
    if (runtime->hasFunction(0x142B98u)) {
        auto targetFn = runtime->lookupFunction(0x142B98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142908u; }
        if (ctx->pc != 0x142908u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142B98_0x142b98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142908u; }
        if (ctx->pc != 0x142908u) { return; }
    }
    ctx->pc = 0x142908u;
label_142908:
    // 0x142908: 0x1318c0  sll         $v1, $s3, 3
    ctx->pc = 0x142908u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14290c: 0x8fa40020  lw          $a0, 0x20($sp)
    ctx->pc = 0x14290cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x142910: 0x24620004  addiu       $v0, $v1, 0x4
    ctx->pc = 0x142910u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4));
    // 0x142914: 0x8fa50024  lw          $a1, 0x24($sp)
    ctx->pc = 0x142914u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x142918: 0x77100b  movn        $v0, $v1, $s7
    ctx->pc = 0x142918u;
    if (GPR_U64(ctx, 23) != 0) SET_GPR_VEC(ctx, 2, GPR_VEC(ctx, 3));
    // 0x14291c: 0xafa40000  sw          $a0, 0x0($sp)
    ctx->pc = 0x14291cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x142920: 0x2028021  addu        $s0, $s0, $v0
    ctx->pc = 0x142920u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x142924: 0xafa50008  sw          $a1, 0x8($sp)
    ctx->pc = 0x142924u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 5));
    // 0x142928: 0x8e050000  lw          $a1, 0x0($s0)
    ctx->pc = 0x142928u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x14292c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x14292cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x142930: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x142930u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142934: 0xafa30018  sw          $v1, 0x18($sp)
    ctx->pc = 0x142934u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 3));
    // 0x142938: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x142938u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14293c: 0xafa00010  sw          $zero, 0x10($sp)
    ctx->pc = 0x14293cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x142940: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x142940u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_142944:
    // 0x142944: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x142944u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142948: 0x24090010  addiu       $t1, $zero, 0x10
    ctx->pc = 0x142948u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x14294c: 0x2a0502d  daddu       $t2, $s5, $zero
    ctx->pc = 0x14294cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
label_142950:
    // 0x142950: 0xc050ae6  jal         func_142B98
    ctx->pc = 0x142950u;
    SET_GPR_U32(ctx, 31, 0x142958u);
    ctx->pc = 0x142954u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x142950u;
            // 0x142954: 0x2c0582d  daddu       $t3, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142B98u;
    if (runtime->hasFunction(0x142B98u)) {
        auto targetFn = runtime->lookupFunction(0x142B98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142958u; }
        if (ctx->pc != 0x142958u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142B98_0x142b98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142958u; }
        if (ctx->pc != 0x142958u) { return; }
    }
    ctx->pc = 0x142958u;
label_142958:
    // 0x142958: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x142958u;
    {
        const bool branch_taken_0x142958 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x14295Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142958u;
            // 0x14295c: 0x24100001  addiu       $s0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142958) {
            ctx->pc = 0x142974u;
            goto label_142974;
        }
    }
    ctx->pc = 0x142960u;
label_142960:
    // 0x142960: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x142960u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142964: 0x24a5dd70  addiu       $a1, $a1, -0x2290
    ctx->pc = 0x142964u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294958448));
    // 0x142968: 0xc05220e  jal         func_148838
    ctx->pc = 0x142968u;
    SET_GPR_U32(ctx, 31, 0x142970u);
    ctx->pc = 0x14296Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x142968u;
            // 0x14296c: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148838u;
    if (runtime->hasFunction(0x148838u)) {
        auto targetFn = runtime->lookupFunction(0x148838u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142970u; }
        if (ctx->pc != 0x142970u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148838_0x148838(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142970u; }
        if (ctx->pc != 0x142970u) { return; }
    }
    ctx->pc = 0x142970u;
label_142970:
    // 0x142970: 0x24100001  addiu       $s0, $zero, 0x1
    ctx->pc = 0x142970u;
    SET_GPR_S32(ctx, 16, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_142974:
    // 0x142974: 0x8fa40040  lw          $a0, 0x40($sp)
    ctx->pc = 0x142974u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 64)));
label_142978:
    // 0x142978: 0x30820004  andi        $v0, $a0, 0x4
    ctx->pc = 0x142978u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)4);
    // 0x14297c: 0x10400079  beqz        $v0, . + 4 + (0x79 << 2)
    ctx->pc = 0x14297Cu;
    {
        const bool branch_taken_0x14297c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x142980u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14297Cu;
            // 0x142980: 0x24020003  addiu       $v0, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x14297c) {
            ctx->pc = 0x142B64u;
            goto label_142b64;
        }
    }
    ctx->pc = 0x142984u;
    // 0x142984: 0x8e23018c  lw          $v1, 0x18C($s1)
    ctx->pc = 0x142984u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 396)));
    // 0x142988: 0x14620034  bne         $v1, $v0, . + 4 + (0x34 << 2)
    ctx->pc = 0x142988u;
    {
        const bool branch_taken_0x142988 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x14298Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142988u;
            // 0x14298c: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142988) {
            ctx->pc = 0x142A5Cu;
            goto label_142a5c;
        }
    }
    ctx->pc = 0x142990u;
    // 0x142990: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x142990u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x142994: 0x1682000f  bne         $s4, $v0, . + 4 + (0xF << 2)
    ctx->pc = 0x142994u;
    {
        const bool branch_taken_0x142994 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 2));
        ctx->pc = 0x142998u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142994u;
            // 0x142998: 0x24130001  addiu       $s3, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142994) {
            ctx->pc = 0x1429D4u;
            goto label_1429d4;
        }
    }
    ctx->pc = 0x14299Cu;
    // 0x14299c: 0x8e42000c  lw          $v0, 0xC($s2)
    ctx->pc = 0x14299cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x1429a0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1429a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1429a4: 0x8e430008  lw          $v1, 0x8($s2)
    ctx->pc = 0x1429a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x1429a8: 0x2a0502d  daddu       $t2, $s5, $zero
    ctx->pc = 0x1429a8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1429ac: 0xafa20008  sw          $v0, 0x8($sp)
    ctx->pc = 0x1429acu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
    // 0x1429b0: 0x2c0582d  daddu       $t3, $s6, $zero
    ctx->pc = 0x1429b0u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1429b4: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x1429b4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x1429b8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1429b8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1429bc: 0xafb00018  sw          $s0, 0x18($sp)
    ctx->pc = 0x1429bcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x1429c0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1429c0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1429c4: 0xafa00010  sw          $zero, 0x10($sp)
    ctx->pc = 0x1429c4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x1429c8: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1429c8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1429cc: 0x1000001f  b           . + 4 + (0x1F << 2)
    ctx->pc = 0x1429CCu;
    {
        const bool branch_taken_0x1429cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1429D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1429CCu;
            // 0x1429d0: 0x24090010  addiu       $t1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1429cc) {
            ctx->pc = 0x142A4Cu;
            goto label_142a4c;
        }
    }
    ctx->pc = 0x1429D4u;
label_1429d4:
    // 0x1429d4: 0x8e42000c  lw          $v0, 0xC($s2)
    ctx->pc = 0x1429d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x1429d8: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x1429d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1429dc: 0x8e430008  lw          $v1, 0x8($s2)
    ctx->pc = 0x1429dcu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x1429e0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1429e0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1429e4: 0x8e2501d4  lw          $a1, 0x1D4($s1)
    ctx->pc = 0x1429e4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 468)));
    // 0x1429e8: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x1429e8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x1429ec: 0x8fc60004  lw          $a2, 0x4($fp)
    ctx->pc = 0x1429ecu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1429f0: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x1429f0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1429f4: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x1429f4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x1429f8: 0x24090008  addiu       $t1, $zero, 0x8
    ctx->pc = 0x1429f8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1429fc: 0xafa20008  sw          $v0, 0x8($sp)
    ctx->pc = 0x1429fcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
    // 0x142a00: 0x2a0502d  daddu       $t2, $s5, $zero
    ctx->pc = 0x142a00u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142a04: 0xafb30010  sw          $s3, 0x10($sp)
    ctx->pc = 0x142a04u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 19));
    // 0x142a08: 0x2c0582d  daddu       $t3, $s6, $zero
    ctx->pc = 0x142a08u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142a0c: 0xc050ae6  jal         func_142B98
    ctx->pc = 0x142A0Cu;
    SET_GPR_U32(ctx, 31, 0x142A14u);
    ctx->pc = 0x142A10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x142A0Cu;
            // 0x142a10: 0xafb00018  sw          $s0, 0x18($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142B98u;
    if (runtime->hasFunction(0x142B98u)) {
        auto targetFn = runtime->lookupFunction(0x142B98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142A14u; }
        if (ctx->pc != 0x142A14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142B98_0x142b98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142A14u; }
        if (ctx->pc != 0x142A14u) { return; }
    }
    ctx->pc = 0x142A14u;
label_142a14:
    // 0x142a14: 0x8e42001c  lw          $v0, 0x1C($s2)
    ctx->pc = 0x142a14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 28)));
    // 0x142a18: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x142a18u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142a1c: 0x8e430018  lw          $v1, 0x18($s2)
    ctx->pc = 0x142a1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 24)));
    // 0x142a20: 0x2a0502d  daddu       $t2, $s5, $zero
    ctx->pc = 0x142a20u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142a24: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x142a24u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x142a28: 0xafb30010  sw          $s3, 0x10($sp)
    ctx->pc = 0x142a28u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 19));
    // 0x142a2c: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x142a2cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x142a30: 0x2c0582d  daddu       $t3, $s6, $zero
    ctx->pc = 0x142a30u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142a34: 0xafa20008  sw          $v0, 0x8($sp)
    ctx->pc = 0x142a34u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
    // 0x142a38: 0x24070001  addiu       $a3, $zero, 0x1
    ctx->pc = 0x142a38u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x142a3c: 0xafb00018  sw          $s0, 0x18($sp)
    ctx->pc = 0x142a3cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x142a40: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x142a40u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142a44: 0x24090008  addiu       $t1, $zero, 0x8
    ctx->pc = 0x142a44u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x142a48: 0x8fc6000c  lw          $a2, 0xC($fp)
    ctx->pc = 0x142a48u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
label_142a4c:
    // 0x142a4c: 0xc050ae6  jal         func_142B98
    ctx->pc = 0x142A4Cu;
    SET_GPR_U32(ctx, 31, 0x142A54u);
    ctx->pc = 0x142A50u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x142A4Cu;
            // 0x142a50: 0x8c8501d4  lw          $a1, 0x1D4($a0) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 4), 468)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142B98u;
    if (runtime->hasFunction(0x142B98u)) {
        auto targetFn = runtime->lookupFunction(0x142B98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142A54u; }
        if (ctx->pc != 0x142A54u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142B98_0x142b98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142A54u; }
        if (ctx->pc != 0x142A54u) { return; }
    }
    ctx->pc = 0x142A54u;
label_142a54:
    // 0x142a54: 0x10000044  b           . + 4 + (0x44 << 2)
    ctx->pc = 0x142A54u;
    {
        const bool branch_taken_0x142a54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x142A58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142A54u;
            // 0x142a58: 0xdfbf00e0  ld          $ra, 0xE0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 224)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142a54) {
            ctx->pc = 0x142B68u;
            goto label_142b68;
        }
    }
    ctx->pc = 0x142A5Cu;
label_142a5c:
    // 0x142a5c: 0x16820015  bne         $s4, $v0, . + 4 + (0x15 << 2)
    ctx->pc = 0x142A5Cu;
    {
        const bool branch_taken_0x142a5c = (GPR_U64(ctx, 20) != GPR_U64(ctx, 2));
        ctx->pc = 0x142A60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142A5Cu;
            // 0x142a60: 0x24020002  addiu       $v0, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142a5c) {
            ctx->pc = 0x142AB4u;
            goto label_142ab4;
        }
    }
    ctx->pc = 0x142A64u;
    // 0x142a64: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x142a64u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x142a68: 0x50400002  beql        $v0, $zero, . + 4 + (0x2 << 2)
    ctx->pc = 0x142A68u;
    {
        const bool branch_taken_0x142a68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x142a68) {
            ctx->pc = 0x142A6Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x142A68u;
            // 0x142a6c: 0x8e2501e4  lw          $a1, 0x1E4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 484)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x142A74u;
            goto label_142a74;
        }
    }
    ctx->pc = 0x142A70u;
    // 0x142a70: 0x8e2501f4  lw          $a1, 0x1F4($s1)
    ctx->pc = 0x142a70u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 500)));
label_142a74:
    // 0x142a74: 0x8e42000c  lw          $v0, 0xC($s2)
    ctx->pc = 0x142a74u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x142a78: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x142a78u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142a7c: 0x8e430008  lw          $v1, 0x8($s2)
    ctx->pc = 0x142a7cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x142a80: 0x2a0502d  daddu       $t2, $s5, $zero
    ctx->pc = 0x142a80u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142a84: 0xafa20008  sw          $v0, 0x8($sp)
    ctx->pc = 0x142a84u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
    // 0x142a88: 0x2c0582d  daddu       $t3, $s6, $zero
    ctx->pc = 0x142a88u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142a8c: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x142a8cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x142a90: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x142a90u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142a94: 0xafb00018  sw          $s0, 0x18($sp)
    ctx->pc = 0x142a94u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x142a98: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x142a98u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142a9c: 0xafa00010  sw          $zero, 0x10($sp)
    ctx->pc = 0x142a9cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x142aa0: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x142aa0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142aa4: 0xc050ae6  jal         func_142B98
    ctx->pc = 0x142AA4u;
    SET_GPR_U32(ctx, 31, 0x142AACu);
    ctx->pc = 0x142AA8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x142AA4u;
            // 0x142aa8: 0x24090010  addiu       $t1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142B98u;
    if (runtime->hasFunction(0x142B98u)) {
        auto targetFn = runtime->lookupFunction(0x142B98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142AACu; }
        if (ctx->pc != 0x142AACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142B98_0x142b98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142AACu; }
        if (ctx->pc != 0x142AACu) { return; }
    }
    ctx->pc = 0x142AACu;
label_142aac:
    // 0x142aac: 0x1000002e  b           . + 4 + (0x2E << 2)
    ctx->pc = 0x142AACu;
    {
        const bool branch_taken_0x142aac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x142AB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142AACu;
            // 0x142ab0: 0xdfbf00e0  ld          $ra, 0xE0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 224)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142aac) {
            ctx->pc = 0x142B68u;
            goto label_142b68;
        }
    }
    ctx->pc = 0x142AB4u;
label_142ab4:
    // 0x142ab4: 0x16820027  bne         $s4, $v0, . + 4 + (0x27 << 2)
    ctx->pc = 0x142AB4u;
    {
        const bool branch_taken_0x142ab4 = (GPR_U64(ctx, 20) != GPR_U64(ctx, 2));
        ctx->pc = 0x142AB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142AB4u;
            // 0x142ab8: 0x3c050024  lui         $a1, 0x24 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142ab4) {
            ctx->pc = 0x142B54u;
            goto label_142b54;
        }
    }
    ctx->pc = 0x142ABCu;
    // 0x142abc: 0x8fc20004  lw          $v0, 0x4($fp)
    ctx->pc = 0x142abcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x142ac0: 0x50400002  beql        $v0, $zero, . + 4 + (0x2 << 2)
    ctx->pc = 0x142AC0u;
    {
        const bool branch_taken_0x142ac0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x142ac0) {
            ctx->pc = 0x142AC4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x142AC0u;
            // 0x142ac4: 0x8e2501e4  lw          $a1, 0x1E4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 484)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x142ACCu;
            goto label_142acc;
        }
    }
    ctx->pc = 0x142AC8u;
    // 0x142ac8: 0x8e2501f4  lw          $a1, 0x1F4($s1)
    ctx->pc = 0x142ac8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 500)));
label_142acc:
    // 0x142acc: 0x8e420008  lw          $v0, 0x8($s2)
    ctx->pc = 0x142accu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 8)));
    // 0x142ad0: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x142ad0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142ad4: 0x8e43000c  lw          $v1, 0xC($s2)
    ctx->pc = 0x142ad4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 12)));
    // 0x142ad8: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x142ad8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142adc: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x142adcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x142ae0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x142ae0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142ae4: 0xafa30008  sw          $v1, 0x8($sp)
    ctx->pc = 0x142ae4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 3));
    // 0x142ae8: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x142ae8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142aec: 0xafa00010  sw          $zero, 0x10($sp)
    ctx->pc = 0x142aecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x142af0: 0x24090008  addiu       $t1, $zero, 0x8
    ctx->pc = 0x142af0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x142af4: 0xafb00018  sw          $s0, 0x18($sp)
    ctx->pc = 0x142af4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x142af8: 0x2a0502d  daddu       $t2, $s5, $zero
    ctx->pc = 0x142af8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142afc: 0xc050ae6  jal         func_142B98
    ctx->pc = 0x142AFCu;
    SET_GPR_U32(ctx, 31, 0x142B04u);
    ctx->pc = 0x142B00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x142AFCu;
            // 0x142b00: 0x2c0582d  daddu       $t3, $s6, $zero (Delay Slot)
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142B98u;
    if (runtime->hasFunction(0x142B98u)) {
        auto targetFn = runtime->lookupFunction(0x142B98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142B04u; }
        if (ctx->pc != 0x142B04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142B98_0x142b98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142B04u; }
        if (ctx->pc != 0x142B04u) { return; }
    }
    ctx->pc = 0x142B04u;
label_142b04:
    // 0x142b04: 0x8fc2000c  lw          $v0, 0xC($fp)
    ctx->pc = 0x142b04u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 30), 12)));
    // 0x142b08: 0x50400002  beql        $v0, $zero, . + 4 + (0x2 << 2)
    ctx->pc = 0x142B08u;
    {
        const bool branch_taken_0x142b08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x142b08) {
            ctx->pc = 0x142B0Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x142B08u;
            // 0x142b0c: 0x8e2501e4  lw          $a1, 0x1E4($s1) (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 484)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x142B14u;
            goto label_142b14;
        }
    }
    ctx->pc = 0x142B10u;
    // 0x142b10: 0x8e2501f4  lw          $a1, 0x1F4($s1)
    ctx->pc = 0x142b10u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 500)));
label_142b14:
    // 0x142b14: 0x8e42001c  lw          $v0, 0x1C($s2)
    ctx->pc = 0x142b14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 28)));
    // 0x142b18: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x142b18u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142b1c: 0x8e430018  lw          $v1, 0x18($s2)
    ctx->pc = 0x142b1cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 24)));
    // 0x142b20: 0x2a0502d  daddu       $t2, $s5, $zero
    ctx->pc = 0x142b20u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142b24: 0xafa20008  sw          $v0, 0x8($sp)
    ctx->pc = 0x142b24u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 2));
    // 0x142b28: 0x2c0582d  daddu       $t3, $s6, $zero
    ctx->pc = 0x142b28u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142b2c: 0xafa30000  sw          $v1, 0x0($sp)
    ctx->pc = 0x142b2cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x142b30: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x142b30u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142b34: 0xafb00018  sw          $s0, 0x18($sp)
    ctx->pc = 0x142b34u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 16));
    // 0x142b38: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x142b38u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142b3c: 0xafa00010  sw          $zero, 0x10($sp)
    ctx->pc = 0x142b3cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 0));
    // 0x142b40: 0x24080008  addiu       $t0, $zero, 0x8
    ctx->pc = 0x142b40u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x142b44: 0xc050ae6  jal         func_142B98
    ctx->pc = 0x142B44u;
    SET_GPR_U32(ctx, 31, 0x142B4Cu);
    ctx->pc = 0x142B48u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x142B44u;
            // 0x142b48: 0x24090008  addiu       $t1, $zero, 0x8 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
        ctx->in_delay_slot = false;
    ctx->pc = 0x142B98u;
    if (runtime->hasFunction(0x142B98u)) {
        auto targetFn = runtime->lookupFunction(0x142B98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142B4Cu; }
        if (ctx->pc != 0x142B4Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00142B98_0x142b98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142B4Cu; }
        if (ctx->pc != 0x142B4Cu) { return; }
    }
    ctx->pc = 0x142B4Cu;
label_142b4c:
    // 0x142b4c: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x142B4Cu;
    {
        const bool branch_taken_0x142b4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x142B50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142B4Cu;
            // 0x142b50: 0xdfbf00e0  ld          $ra, 0xE0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 224)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x142b4c) {
            ctx->pc = 0x142B68u;
            goto label_142b68;
        }
    }
    ctx->pc = 0x142B54u;
label_142b54:
    // 0x142b54: 0x220202d  daddu       $a0, $s1, $zero
    ctx->pc = 0x142b54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x142b58: 0x24a5dd90  addiu       $a1, $a1, -0x2270
    ctx->pc = 0x142b58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294958480));
    // 0x142b5c: 0xc05220e  jal         func_148838
    ctx->pc = 0x142B5Cu;
    SET_GPR_U32(ctx, 31, 0x142B64u);
    ctx->pc = 0x142B60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x142B5Cu;
            // 0x142b60: 0x280302d  daddu       $a2, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x148838u;
    if (runtime->hasFunction(0x148838u)) {
        auto targetFn = runtime->lookupFunction(0x148838u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142B64u; }
        if (ctx->pc != 0x142B64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00148838_0x148838(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x142B64u; }
        if (ctx->pc != 0x142B64u) { return; }
    }
    ctx->pc = 0x142B64u;
label_142b64:
    // 0x142b64: 0xdfbf00e0  ld          $ra, 0xE0($sp)
    ctx->pc = 0x142b64u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 224)));
label_142b68:
    // 0x142b68: 0xdfbe00d0  ld          $fp, 0xD0($sp)
    ctx->pc = 0x142b68u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x142b6c: 0xdfb700c0  ld          $s7, 0xC0($sp)
    ctx->pc = 0x142b6cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x142b70: 0xdfb600b0  ld          $s6, 0xB0($sp)
    ctx->pc = 0x142b70u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x142b74: 0xdfb500a0  ld          $s5, 0xA0($sp)
    ctx->pc = 0x142b74u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x142b78: 0xdfb40090  ld          $s4, 0x90($sp)
    ctx->pc = 0x142b78u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x142b7c: 0xdfb30080  ld          $s3, 0x80($sp)
    ctx->pc = 0x142b7cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x142b80: 0xdfb20070  ld          $s2, 0x70($sp)
    ctx->pc = 0x142b80u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x142b84: 0xdfb10060  ld          $s1, 0x60($sp)
    ctx->pc = 0x142b84u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x142b88: 0xdfb00050  ld          $s0, 0x50($sp)
    ctx->pc = 0x142b88u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x142b8c: 0x3e00008  jr          $ra
    ctx->pc = 0x142B8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x142B90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x142B8Cu;
            // 0x142b90: 0x27bd00f0  addiu       $sp, $sp, 0xF0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 240));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x14250Cu: goto label_14250c;
            case 0x142534u: goto label_142534;
            case 0x142568u: goto label_142568;
            case 0x1425ACu: goto label_1425ac;
            case 0x1425ECu: goto label_1425ec;
            case 0x1425F4u: goto label_1425f4;
            case 0x142618u: goto label_142618;
            case 0x142658u: goto label_142658;
            case 0x142694u: goto label_142694;
            case 0x1426D4u: goto label_1426d4;
            case 0x14270Cu: goto label_14270c;
            case 0x14271Cu: goto label_14271c;
            case 0x142724u: goto label_142724;
            case 0x142770u: goto label_142770;
            case 0x142774u: goto label_142774;
            case 0x142788u: goto label_142788;
            case 0x1427C4u: goto label_1427c4;
            case 0x142820u: goto label_142820;
            case 0x142848u: goto label_142848;
            case 0x14284Cu: goto label_14284c;
            case 0x142894u: goto label_142894;
            case 0x1428C0u: goto label_1428c0;
            case 0x142908u: goto label_142908;
            case 0x142944u: goto label_142944;
            case 0x142950u: goto label_142950;
            case 0x142958u: goto label_142958;
            case 0x142960u: goto label_142960;
            case 0x142970u: goto label_142970;
            case 0x142974u: goto label_142974;
            case 0x142978u: goto label_142978;
            case 0x1429D4u: goto label_1429d4;
            case 0x142A14u: goto label_142a14;
            case 0x142A4Cu: goto label_142a4c;
            case 0x142A54u: goto label_142a54;
            case 0x142A5Cu: goto label_142a5c;
            case 0x142A74u: goto label_142a74;
            case 0x142AACu: goto label_142aac;
            case 0x142AB4u: goto label_142ab4;
            case 0x142ACCu: goto label_142acc;
            case 0x142B04u: goto label_142b04;
            case 0x142B14u: goto label_142b14;
            case 0x142B4Cu: goto label_142b4c;
            case 0x142B54u: goto label_142b54;
            case 0x142B64u: goto label_142b64;
            case 0x142B68u: goto label_142b68;
            default: break;
        }
        return;
    }
    ctx->pc = 0x142B94u;
    // 0x142b94: 0x0  nop
    ctx->pc = 0x142b94u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
