#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00110840
// Address: 0x110840 - 0x110dc0
void sub_00110840_0x110840(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00110840_0x110840");
#endif

    ctx->pc = 0x110840u;

    // 0x110840: 0x5403f  dsra32      $t0, $a1, 0
    ctx->pc = 0x110840u;
    SET_GPR_S64(ctx, 8, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x110844: 0x4503f  dsra32      $t2, $a0, 0
    ctx->pc = 0x110844u;
    SET_GPR_S64(ctx, 10, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x110848: 0x5483c  dsll32      $t1, $a1, 0
    ctx->pc = 0x110848u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 5) << (32 + 0));
    // 0x11084c: 0x9483f  dsra32      $t1, $t1, 0
    ctx->pc = 0x11084cu;
    SET_GPR_S64(ctx, 9, GPR_S64(ctx, 9) >> (32 + 0));
    // 0x110850: 0x4583c  dsll32      $t3, $a0, 0
    ctx->pc = 0x110850u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 4) << (32 + 0));
    // 0x110854: 0xb583f  dsra32      $t3, $t3, 0
    ctx->pc = 0x110854u;
    SET_GPR_S64(ctx, 11, GPR_S64(ctx, 11) >> (32 + 0));
    // 0x110858: 0x150000e1  bnez        $t0, . + 4 + (0xE1 << 2)
    ctx->pc = 0x110858u;
    {
        const bool branch_taken_0x110858 = (GPR_U64(ctx, 8) != GPR_U64(ctx, 0));
        ctx->pc = 0x11085Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110858u;
            // 0x11085c: 0x148102b  sltu        $v0, $t2, $t0 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 10) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x110858) {
            ctx->pc = 0x110BE0u;
            goto label_110be0;
        }
    }
    ctx->pc = 0x110860u;
    // 0x110860: 0x149102b  sltu        $v0, $t2, $t1
    ctx->pc = 0x110860u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 10) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x110864: 0x1040004e  beqz        $v0, . + 4 + (0x4E << 2)
    ctx->pc = 0x110864u;
    {
        const bool branch_taken_0x110864 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x110868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110864u;
            // 0x110868: 0x3402ffff  ori         $v0, $zero, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x110864) {
            ctx->pc = 0x1109A0u;
            goto label_1109a0;
        }
    }
    ctx->pc = 0x11086Cu;
    // 0x11086c: 0x49102b  sltu        $v0, $v0, $t1
    ctx->pc = 0x11086cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x110870: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x110870u;
    {
        const bool branch_taken_0x110870 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x110874u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110870u;
            // 0x110874: 0x3c0200ff  lui         $v0, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110870) {
            ctx->pc = 0x110888u;
            goto label_110888;
        }
    }
    ctx->pc = 0x110878u;
    // 0x110878: 0x2d220100  sltiu       $v0, $t1, 0x100
    ctx->pc = 0x110878u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 9) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
    // 0x11087c: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x11087cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x110880: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x110880u;
    {
        const bool branch_taken_0x110880 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x110884u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110880u;
            // 0x110884: 0x2200b  movn        $a0, $zero, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110880) {
            ctx->pc = 0x11089Cu;
            goto label_11089c;
        }
    }
    ctx->pc = 0x110888u;
label_110888:
    // 0x110888: 0x24030018  addiu       $v1, $zero, 0x18
    ctx->pc = 0x110888u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x11088c: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x11088cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x110890: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x110890u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x110894: 0x49102b  sltu        $v0, $v0, $t1
    ctx->pc = 0x110894u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x110898: 0x62200b  movn        $a0, $v1, $v0
    ctx->pc = 0x110898u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
label_11089c:
    // 0x11089c: 0x891806  srlv        $v1, $t1, $a0
    ctx->pc = 0x11089cu;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 9), GPR_U32(ctx, 4) & 0x1F));
    // 0x1108a0: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x1108a0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1108a4: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x1108a4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x1108a8: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1108a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1108ac: 0x904283a0  lbu         $v0, -0x7C60($v0)
    ctx->pc = 0x1108acu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294935456)));
    // 0x1108b0: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x1108b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1108b4: 0xa23023  subu        $a2, $a1, $v0
    ctx->pc = 0x1108b4u;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1108b8: 0x10c00006  beqz        $a2, . + 4 + (0x6 << 2)
    ctx->pc = 0x1108B8u;
    {
        const bool branch_taken_0x1108b8 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        ctx->pc = 0x1108BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1108B8u;
            // 0x1108bc: 0xa61023  subu        $v0, $a1, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1108b8) {
            ctx->pc = 0x1108D4u;
            goto label_1108d4;
        }
    }
    ctx->pc = 0x1108C0u;
    // 0x1108c0: 0xca1804  sllv        $v1, $t2, $a2
    ctx->pc = 0x1108c0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 10), GPR_U32(ctx, 6) & 0x1F));
    // 0x1108c4: 0x4b1006  srlv        $v0, $t3, $v0
    ctx->pc = 0x1108c4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 11), GPR_U32(ctx, 2) & 0x1F));
    // 0x1108c8: 0xcb5804  sllv        $t3, $t3, $a2
    ctx->pc = 0x1108c8u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), GPR_U32(ctx, 6) & 0x1F));
    // 0x1108cc: 0x625025  or          $t2, $v1, $v0
    ctx->pc = 0x1108ccu;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x1108d0: 0xc94804  sllv        $t1, $t1, $a2
    ctx->pc = 0x1108d0u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), GPR_U32(ctx, 6) & 0x1F));
label_1108d4:
    // 0x1108d4: 0x93402  srl         $a2, $t1, 16
    ctx->pc = 0x1108d4u;
    SET_GPR_S32(ctx, 6, (int32_t)SRL32(GPR_U32(ctx, 9), 16));
    // 0x1108d8: 0x3128ffff  andi        $t0, $t1, 0xFFFF
    ctx->pc = 0x1108d8u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)65535);
    // 0x1108dc: 0x146001b  divu        $zero, $t2, $a2
    ctx->pc = 0x1108dcu;
    { uint32_t divisor = GPR_U32(ctx, 6); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 10) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 10) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,10); } }
    // 0x1108e0: 0xb2402  srl         $a0, $t3, 16
    ctx->pc = 0x1108e0u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 11), 16));
    // 0x1108e4: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1108E4u;
    {
        const bool branch_taken_0x1108e4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x1108e4) {
            ctx->pc = 0x1108E8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1108E4u;
            // 0x1108e8: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1108ECu;
            goto label_1108ec;
        }
    }
    ctx->pc = 0x1108ECu;
label_1108ec:
    // 0x1108ec: 0x1012  mflo        $v0
    ctx->pc = 0x1108ecu;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x1108f0: 0x1810  mfhi        $v1
    ctx->pc = 0x1108f0u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x1108f4: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x1108f4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1108f8: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x1108f8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x1108fc: 0xe82818  mult        $a1, $a3, $t0
    ctx->pc = 0x1108fcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x110900: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x110900u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x110904: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x110904u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x110908: 0x5040000c  beql        $v0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x110908u;
    {
        const bool branch_taken_0x110908 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x110908) {
            ctx->pc = 0x11090Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110908u;
            // 0x11090c: 0x651823  subu        $v1, $v1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11093Cu;
            goto label_11093c;
        }
    }
    ctx->pc = 0x110910u;
    // 0x110910: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x110910u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x110914: 0x69102b  sltu        $v0, $v1, $t1
    ctx->pc = 0x110914u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x110918: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x110918u;
    {
        const bool branch_taken_0x110918 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11091Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110918u;
            // 0x11091c: 0x24e7ffff  addiu       $a3, $a3, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110918) {
            ctx->pc = 0x110938u;
            goto label_110938;
        }
    }
    ctx->pc = 0x110920u;
    // 0x110920: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x110920u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x110924: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x110924u;
    {
        const bool branch_taken_0x110924 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x110924) {
            ctx->pc = 0x110928u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110924u;
            // 0x110928: 0x651823  subu        $v1, $v1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x11093Cu;
            goto label_11093c;
        }
    }
    ctx->pc = 0x11092Cu;
    // 0x11092c: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x11092cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x110930: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x110930u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x110934: 0x0  nop
    ctx->pc = 0x110934u;
    // NOP
label_110938:
    // 0x110938: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x110938u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
label_11093c:
    // 0x11093c: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x11093Cu;
    {
        const bool branch_taken_0x11093c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x11093c) {
            ctx->pc = 0x110940u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x11093Cu;
            // 0x110940: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x110944u;
            goto label_110944;
        }
    }
    ctx->pc = 0x110944u;
label_110944:
    // 0x110944: 0x66001b  divu        $zero, $v1, $a2
    ctx->pc = 0x110944u;
    { uint32_t divisor = GPR_U32(ctx, 6); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,3); } }
    // 0x110948: 0x3164ffff  andi        $a0, $t3, 0xFFFF
    ctx->pc = 0x110948u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)65535);
    // 0x11094c: 0x1012  mflo        $v0
    ctx->pc = 0x11094cu;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x110950: 0x1810  mfhi        $v1
    ctx->pc = 0x110950u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x110954: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x110954u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x110958: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x110958u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x11095c: 0xc82818  mult        $a1, $a2, $t0
    ctx->pc = 0x11095cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x110960: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x110960u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x110964: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x110964u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x110968: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x110968u;
    {
        const bool branch_taken_0x110968 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x11096Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110968u;
            // 0x11096c: 0x71400  sll         $v0, $a3, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110968) {
            ctx->pc = 0x110994u;
            goto label_110994;
        }
    }
    ctx->pc = 0x110970u;
    // 0x110970: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x110970u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x110974: 0x69102b  sltu        $v0, $v1, $t1
    ctx->pc = 0x110974u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x110978: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x110978u;
    {
        const bool branch_taken_0x110978 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x11097Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110978u;
            // 0x11097c: 0x24c6ffff  addiu       $a2, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110978) {
            ctx->pc = 0x110990u;
            goto label_110990;
        }
    }
    ctx->pc = 0x110980u;
    // 0x110980: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x110980u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x110984: 0x24c3ffff  addiu       $v1, $a2, -0x1
    ctx->pc = 0x110984u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x110988: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x110988u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x11098c: 0x62300b  movn        $a2, $v1, $v0
    ctx->pc = 0x11098cu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 3));
label_110990:
    // 0x110990: 0x71400  sll         $v0, $a3, 16
    ctx->pc = 0x110990u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
label_110994:
    // 0x110994: 0x100000fc  b           . + 4 + (0xFC << 2)
    ctx->pc = 0x110994u;
    {
        const bool branch_taken_0x110994 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x110998u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110994u;
            // 0x110998: 0x463025  or          $a2, $v0, $a2 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110994) {
            ctx->pc = 0x110D88u;
            goto label_110d88;
        }
    }
    ctx->pc = 0x11099Cu;
    // 0x11099c: 0x0  nop
    ctx->pc = 0x11099cu;
    // NOP
label_1109a0:
    // 0x1109a0: 0x15200009  bnez        $t1, . + 4 + (0x9 << 2)
    ctx->pc = 0x1109A0u;
    {
        const bool branch_taken_0x1109a0 = (GPR_U64(ctx, 9) != GPR_U64(ctx, 0));
        ctx->pc = 0x1109A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1109A0u;
            // 0x1109a4: 0x49102b  sltu        $v0, $v0, $t1 (Delay Slot)
        SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1109a0) {
            ctx->pc = 0x1109C8u;
            goto label_1109c8;
        }
    }
    ctx->pc = 0x1109A8u;
    // 0x1109a8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1109a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1109ac: 0x51200001  beql        $t1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x1109ACu;
    {
        const bool branch_taken_0x1109ac = (GPR_U64(ctx, 9) == GPR_U64(ctx, 0));
        if (branch_taken_0x1109ac) {
            ctx->pc = 0x1109B0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x1109ACu;
            // 0x1109b0: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x1109B4u;
            goto label_1109b4;
        }
    }
    ctx->pc = 0x1109B4u;
label_1109b4:
    // 0x1109b4: 0x48001b  divu        $zero, $v0, $t0
    ctx->pc = 0x1109b4u;
    { uint32_t divisor = GPR_U32(ctx, 8); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 2) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,2); } }
    // 0x1109b8: 0x1012  mflo        $v0
    ctx->pc = 0x1109b8u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x1109bc: 0x40482d  daddu       $t1, $v0, $zero
    ctx->pc = 0x1109bcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1109c0: 0x3402ffff  ori         $v0, $zero, 0xFFFF
    ctx->pc = 0x1109c0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1109c4: 0x49102b  sltu        $v0, $v0, $t1
    ctx->pc = 0x1109c4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
label_1109c8:
    // 0x1109c8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x1109C8u;
    {
        const bool branch_taken_0x1109c8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1109CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1109C8u;
            // 0x1109cc: 0x3c0200ff  lui         $v0, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1109c8) {
            ctx->pc = 0x1109E0u;
            goto label_1109e0;
        }
    }
    ctx->pc = 0x1109D0u;
    // 0x1109d0: 0x2d220100  sltiu       $v0, $t1, 0x100
    ctx->pc = 0x1109d0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 9) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
    // 0x1109d4: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x1109d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x1109d8: 0x10000006  b           . + 4 + (0x6 << 2)
    ctx->pc = 0x1109D8u;
    {
        const bool branch_taken_0x1109d8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1109DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1109D8u;
            // 0x1109dc: 0x2200b  movn        $a0, $zero, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1109d8) {
            ctx->pc = 0x1109F4u;
            goto label_1109f4;
        }
    }
    ctx->pc = 0x1109E0u;
label_1109e0:
    // 0x1109e0: 0x24030018  addiu       $v1, $zero, 0x18
    ctx->pc = 0x1109e0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1109e4: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x1109e4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x1109e8: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x1109e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x1109ec: 0x49102b  sltu        $v0, $v0, $t1
    ctx->pc = 0x1109ecu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x1109f0: 0x62200b  movn        $a0, $v1, $v0
    ctx->pc = 0x1109f0u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
label_1109f4:
    // 0x1109f4: 0x891806  srlv        $v1, $t1, $a0
    ctx->pc = 0x1109f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 9), GPR_U32(ctx, 4) & 0x1F));
    // 0x1109f8: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x1109f8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x1109fc: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x1109fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x110a00: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x110a00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x110a04: 0x904283a0  lbu         $v0, -0x7C60($v0)
    ctx->pc = 0x110a04u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294935456)));
    // 0x110a08: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x110a08u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x110a0c: 0xa23023  subu        $a2, $a1, $v0
    ctx->pc = 0x110a0cu;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x110a10: 0x14c00007  bnez        $a2, . + 4 + (0x7 << 2)
    ctx->pc = 0x110A10u;
    {
        const bool branch_taken_0x110a10 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x110A14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110A10u;
            // 0x110a14: 0xa63823  subu        $a3, $a1, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110a10) {
            ctx->pc = 0x110A30u;
            goto label_110a30;
        }
    }
    ctx->pc = 0x110A18u;
    // 0x110a18: 0x1495023  subu        $t2, $t2, $t1
    ctx->pc = 0x110a18u;
    SET_GPR_S32(ctx, 10, (int32_t)SUB32(GPR_U32(ctx, 10), GPR_U32(ctx, 9)));
    // 0x110a1c: 0x240d0001  addiu       $t5, $zero, 0x1
    ctx->pc = 0x110a1cu;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x110a20: 0x94402  srl         $t0, $t1, 16
    ctx->pc = 0x110a20u;
    SET_GPR_S32(ctx, 8, (int32_t)SRL32(GPR_U32(ctx, 9), 16));
    // 0x110a24: 0x1000003c  b           . + 4 + (0x3C << 2)
    ctx->pc = 0x110A24u;
    {
        const bool branch_taken_0x110a24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x110A28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110A24u;
            // 0x110a28: 0x312cffff  andi        $t4, $t1, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 12, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
        if (branch_taken_0x110a24) {
            ctx->pc = 0x110B18u;
            goto label_110b18;
        }
    }
    ctx->pc = 0x110A2Cu;
    // 0x110a2c: 0x0  nop
    ctx->pc = 0x110a2cu;
    // NOP
label_110a30:
    // 0x110a30: 0xca1804  sllv        $v1, $t2, $a2
    ctx->pc = 0x110a30u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 10), GPR_U32(ctx, 6) & 0x1F));
    // 0x110a34: 0xeb1006  srlv        $v0, $t3, $a3
    ctx->pc = 0x110a34u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 11), GPR_U32(ctx, 7) & 0x1F));
    // 0x110a38: 0xcb5804  sllv        $t3, $t3, $a2
    ctx->pc = 0x110a38u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), GPR_U32(ctx, 6) & 0x1F));
    // 0x110a3c: 0xea2006  srlv        $a0, $t2, $a3
    ctx->pc = 0x110a3cu;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 10), GPR_U32(ctx, 7) & 0x1F));
    // 0x110a40: 0x625025  or          $t2, $v1, $v0
    ctx->pc = 0x110a40u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 3) | GPR_U64(ctx, 2));
    // 0x110a44: 0xc94804  sllv        $t1, $t1, $a2
    ctx->pc = 0x110a44u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), GPR_U32(ctx, 6) & 0x1F));
    // 0x110a48: 0x94402  srl         $t0, $t1, 16
    ctx->pc = 0x110a48u;
    SET_GPR_S32(ctx, 8, (int32_t)SRL32(GPR_U32(ctx, 9), 16));
    // 0x110a4c: 0x88001b  divu        $zero, $a0, $t0
    ctx->pc = 0x110a4cu;
    { uint32_t divisor = GPR_U32(ctx, 8); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,4); } }
    // 0x110a50: 0xa2402  srl         $a0, $t2, 16
    ctx->pc = 0x110a50u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 10), 16));
    // 0x110a54: 0x312cffff  andi        $t4, $t1, 0xFFFF
    ctx->pc = 0x110a54u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 9) & (uint64_t)(uint16_t)65535);
    // 0x110a58: 0x100302d  daddu       $a2, $t0, $zero
    ctx->pc = 0x110a58u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x110a5c: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x110A5Cu;
    {
        const bool branch_taken_0x110a5c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x110a5c) {
            ctx->pc = 0x110A60u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110A5Cu;
            // 0x110a60: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x110A64u;
            goto label_110a64;
        }
    }
    ctx->pc = 0x110A64u;
label_110a64:
    // 0x110a64: 0x1012  mflo        $v0
    ctx->pc = 0x110a64u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x110a68: 0x1810  mfhi        $v1
    ctx->pc = 0x110a68u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x110a6c: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x110a6cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x110a70: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x110a70u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x110a74: 0xec2818  mult        $a1, $a3, $t4
    ctx->pc = 0x110a74u;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 12); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x110a78: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x110a78u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x110a7c: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x110a7cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x110a80: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x110A80u;
    {
        const bool branch_taken_0x110a80 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x110A84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110A80u;
            // 0x110a84: 0x180682d  daddu       $t5, $t4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110a80) {
            ctx->pc = 0x110AB0u;
            goto label_110ab0;
        }
    }
    ctx->pc = 0x110A88u;
    // 0x110a88: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x110a88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x110a8c: 0x69102b  sltu        $v0, $v1, $t1
    ctx->pc = 0x110a8cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x110a90: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x110A90u;
    {
        const bool branch_taken_0x110a90 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x110A94u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110A90u;
            // 0x110a94: 0x24e7ffff  addiu       $a3, $a3, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110a90) {
            ctx->pc = 0x110AB0u;
            goto label_110ab0;
        }
    }
    ctx->pc = 0x110A98u;
    // 0x110a98: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x110a98u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x110a9c: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x110A9Cu;
    {
        const bool branch_taken_0x110a9c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x110a9c) {
            ctx->pc = 0x110AA0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110A9Cu;
            // 0x110aa0: 0x651823  subu        $v1, $v1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x110AB4u;
            goto label_110ab4;
        }
    }
    ctx->pc = 0x110AA4u;
    // 0x110aa4: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x110aa4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x110aa8: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x110aa8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x110aac: 0x0  nop
    ctx->pc = 0x110aacu;
    // NOP
label_110ab0:
    // 0x110ab0: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x110ab0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
label_110ab4:
    // 0x110ab4: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x110AB4u;
    {
        const bool branch_taken_0x110ab4 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x110ab4) {
            ctx->pc = 0x110AB8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110AB4u;
            // 0x110ab8: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x110ABCu;
            goto label_110abc;
        }
    }
    ctx->pc = 0x110ABCu;
label_110abc:
    // 0x110abc: 0x66001b  divu        $zero, $v1, $a2
    ctx->pc = 0x110abcu;
    { uint32_t divisor = GPR_U32(ctx, 6); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,3); } }
    // 0x110ac0: 0x3144ffff  andi        $a0, $t2, 0xFFFF
    ctx->pc = 0x110ac0u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 10) & (uint64_t)(uint16_t)65535);
    // 0x110ac4: 0x1012  mflo        $v0
    ctx->pc = 0x110ac4u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x110ac8: 0x1810  mfhi        $v1
    ctx->pc = 0x110ac8u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x110acc: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x110accu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x110ad0: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x110ad0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x110ad4: 0xcd2818  mult        $a1, $a2, $t5
    ctx->pc = 0x110ad4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 13); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x110ad8: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x110ad8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x110adc: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x110adcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x110ae0: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x110AE0u;
    {
        const bool branch_taken_0x110ae0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x110AE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110AE0u;
            // 0x110ae4: 0x71400  sll         $v0, $a3, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110ae0) {
            ctx->pc = 0x110B10u;
            goto label_110b10;
        }
    }
    ctx->pc = 0x110AE8u;
    // 0x110ae8: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x110ae8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x110aec: 0x69102b  sltu        $v0, $v1, $t1
    ctx->pc = 0x110aecu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x110af0: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x110AF0u;
    {
        const bool branch_taken_0x110af0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x110AF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110AF0u;
            // 0x110af4: 0x24c6ffff  addiu       $a2, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110af0) {
            ctx->pc = 0x110B0Cu;
            goto label_110b0c;
        }
    }
    ctx->pc = 0x110AF8u;
    // 0x110af8: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x110af8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x110afc: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x110AFCu;
    {
        const bool branch_taken_0x110afc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x110B00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110AFCu;
            // 0x110b00: 0x71400  sll         $v0, $a3, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110afc) {
            ctx->pc = 0x110B10u;
            goto label_110b10;
        }
    }
    ctx->pc = 0x110B04u;
    // 0x110b04: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x110b04u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x110b08: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x110b08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
label_110b0c:
    // 0x110b0c: 0x71400  sll         $v0, $a3, 16
    ctx->pc = 0x110b0cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
label_110b10:
    // 0x110b10: 0x655023  subu        $t2, $v1, $a1
    ctx->pc = 0x110b10u;
    SET_GPR_S32(ctx, 10, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x110b14: 0x466825  or          $t5, $v0, $a2
    ctx->pc = 0x110b14u;
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
label_110b18:
    // 0x110b18: 0x100302d  daddu       $a2, $t0, $zero
    ctx->pc = 0x110b18u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x110b1c: 0x180402d  daddu       $t0, $t4, $zero
    ctx->pc = 0x110b1cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
    // 0x110b20: 0x146001b  divu        $zero, $t2, $a2
    ctx->pc = 0x110b20u;
    { uint32_t divisor = GPR_U32(ctx, 6); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 10) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 10) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,10); } }
    // 0x110b24: 0xb2402  srl         $a0, $t3, 16
    ctx->pc = 0x110b24u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 11), 16));
    // 0x110b28: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x110B28u;
    {
        const bool branch_taken_0x110b28 = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x110b28) {
            ctx->pc = 0x110B2Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110B28u;
            // 0x110b2c: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x110B30u;
            goto label_110b30;
        }
    }
    ctx->pc = 0x110B30u;
label_110b30:
    // 0x110b30: 0x1012  mflo        $v0
    ctx->pc = 0x110b30u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x110b34: 0x1810  mfhi        $v1
    ctx->pc = 0x110b34u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x110b38: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x110b38u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x110b3c: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x110b3cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x110b40: 0xe82818  mult        $a1, $a3, $t0
    ctx->pc = 0x110b40u;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x110b44: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x110b44u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x110b48: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x110b48u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x110b4c: 0x5040000b  beql        $v0, $zero, . + 4 + (0xB << 2)
    ctx->pc = 0x110B4Cu;
    {
        const bool branch_taken_0x110b4c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x110b4c) {
            ctx->pc = 0x110B50u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110B4Cu;
            // 0x110b50: 0x651823  subu        $v1, $v1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x110B7Cu;
            goto label_110b7c;
        }
    }
    ctx->pc = 0x110B54u;
    // 0x110b54: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x110b54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x110b58: 0x69102b  sltu        $v0, $v1, $t1
    ctx->pc = 0x110b58u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x110b5c: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x110B5Cu;
    {
        const bool branch_taken_0x110b5c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x110B60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110B5Cu;
            // 0x110b60: 0x24e7ffff  addiu       $a3, $a3, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110b5c) {
            ctx->pc = 0x110B78u;
            goto label_110b78;
        }
    }
    ctx->pc = 0x110B64u;
    // 0x110b64: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x110b64u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x110b68: 0x50400004  beql        $v0, $zero, . + 4 + (0x4 << 2)
    ctx->pc = 0x110B68u;
    {
        const bool branch_taken_0x110b68 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x110b68) {
            ctx->pc = 0x110B6Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110B68u;
            // 0x110b6c: 0x651823  subu        $v1, $v1, $a1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x110B7Cu;
            goto label_110b7c;
        }
    }
    ctx->pc = 0x110B70u;
    // 0x110b70: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x110b70u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x110b74: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x110b74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
label_110b78:
    // 0x110b78: 0x651823  subu        $v1, $v1, $a1
    ctx->pc = 0x110b78u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
label_110b7c:
    // 0x110b7c: 0x50c00001  beql        $a2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x110B7Cu;
    {
        const bool branch_taken_0x110b7c = (GPR_U64(ctx, 6) == GPR_U64(ctx, 0));
        if (branch_taken_0x110b7c) {
            ctx->pc = 0x110B80u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110B7Cu;
            // 0x110b80: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x110B84u;
            goto label_110b84;
        }
    }
    ctx->pc = 0x110B84u;
label_110b84:
    // 0x110b84: 0x66001b  divu        $zero, $v1, $a2
    ctx->pc = 0x110b84u;
    { uint32_t divisor = GPR_U32(ctx, 6); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,3); } }
    // 0x110b88: 0x3164ffff  andi        $a0, $t3, 0xFFFF
    ctx->pc = 0x110b88u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)65535);
    // 0x110b8c: 0x1012  mflo        $v0
    ctx->pc = 0x110b8cu;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x110b90: 0x1810  mfhi        $v1
    ctx->pc = 0x110b90u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x110b94: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x110b94u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x110b98: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x110b98u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x110b9c: 0xc82818  mult        $a1, $a2, $t0
    ctx->pc = 0x110b9cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 8); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x110ba0: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x110ba0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x110ba4: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x110ba4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x110ba8: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x110BA8u;
    {
        const bool branch_taken_0x110ba8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x110BACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110BA8u;
            // 0x110bac: 0x71400  sll         $v0, $a3, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110ba8) {
            ctx->pc = 0x110BD4u;
            goto label_110bd4;
        }
    }
    ctx->pc = 0x110BB0u;
    // 0x110bb0: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x110bb0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x110bb4: 0x69102b  sltu        $v0, $v1, $t1
    ctx->pc = 0x110bb4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x110bb8: 0x14400005  bnez        $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x110BB8u;
    {
        const bool branch_taken_0x110bb8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x110BBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110BB8u;
            // 0x110bbc: 0x24c6ffff  addiu       $a2, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110bb8) {
            ctx->pc = 0x110BD0u;
            goto label_110bd0;
        }
    }
    ctx->pc = 0x110BC0u;
    // 0x110bc0: 0x65102b  sltu        $v0, $v1, $a1
    ctx->pc = 0x110bc0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 5)) ? 1 : 0);
    // 0x110bc4: 0x24c3ffff  addiu       $v1, $a2, -0x1
    ctx->pc = 0x110bc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
    // 0x110bc8: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x110bc8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x110bcc: 0x62300b  movn        $a2, $v1, $v0
    ctx->pc = 0x110bccu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 3));
label_110bd0:
    // 0x110bd0: 0x71400  sll         $v0, $a3, 16
    ctx->pc = 0x110bd0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
label_110bd4:
    // 0x110bd4: 0x1000006d  b           . + 4 + (0x6D << 2)
    ctx->pc = 0x110BD4u;
    {
        const bool branch_taken_0x110bd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x110BD8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110BD4u;
            // 0x110bd8: 0x463025  or          $a2, $v0, $a2 (Delay Slot)
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | GPR_U64(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110bd4) {
            ctx->pc = 0x110D8Cu;
            goto label_110d8c;
        }
    }
    ctx->pc = 0x110BDCu;
    // 0x110bdc: 0x0  nop
    ctx->pc = 0x110bdcu;
    // NOP
label_110be0:
    // 0x110be0: 0x50400003  beql        $v0, $zero, . + 4 + (0x3 << 2)
    ctx->pc = 0x110BE0u;
    {
        const bool branch_taken_0x110be0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x110be0) {
            ctx->pc = 0x110BE4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110BE0u;
            // 0x110be4: 0x3402ffff  ori         $v0, $zero, 0xFFFF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
        ctx->in_delay_slot = false;
            ctx->pc = 0x110BF0u;
            goto label_110bf0;
        }
    }
    ctx->pc = 0x110BE8u;
    // 0x110be8: 0x10000067  b           . + 4 + (0x67 << 2)
    ctx->pc = 0x110BE8u;
    {
        const bool branch_taken_0x110be8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x110BECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110BE8u;
            // 0x110bec: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110be8) {
            ctx->pc = 0x110D88u;
            goto label_110d88;
        }
    }
    ctx->pc = 0x110BF0u;
label_110bf0:
    // 0x110bf0: 0x48102b  sltu        $v0, $v0, $t0
    ctx->pc = 0x110bf0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x110bf4: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x110BF4u;
    {
        const bool branch_taken_0x110bf4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x110BF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110BF4u;
            // 0x110bf8: 0x3c0200ff  lui         $v0, 0xFF (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)255 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110bf4) {
            ctx->pc = 0x110C10u;
            goto label_110c10;
        }
    }
    ctx->pc = 0x110BFCu;
    // 0x110bfc: 0x2d020100  sltiu       $v0, $t0, 0x100
    ctx->pc = 0x110bfcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)(int64_t)(int32_t)256) ? 1 : 0);
    // 0x110c00: 0x24040008  addiu       $a0, $zero, 0x8
    ctx->pc = 0x110c00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 8));
    // 0x110c04: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x110C04u;
    {
        const bool branch_taken_0x110c04 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x110C08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110C04u;
            // 0x110c08: 0x2200b  movn        $a0, $zero, $v0 (Delay Slot)
        if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110c04) {
            ctx->pc = 0x110C24u;
            goto label_110c24;
        }
    }
    ctx->pc = 0x110C0Cu;
    // 0x110c0c: 0x0  nop
    ctx->pc = 0x110c0cu;
    // NOP
label_110c10:
    // 0x110c10: 0x24030018  addiu       $v1, $zero, 0x18
    ctx->pc = 0x110c10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x110c14: 0x3442ffff  ori         $v0, $v0, 0xFFFF
    ctx->pc = 0x110c14u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | (uint64_t)(uint16_t)65535);
    // 0x110c18: 0x24040010  addiu       $a0, $zero, 0x10
    ctx->pc = 0x110c18u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
    // 0x110c1c: 0x48102b  sltu        $v0, $v0, $t0
    ctx->pc = 0x110c1cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x110c20: 0x62200b  movn        $a0, $v1, $v0
    ctx->pc = 0x110c20u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 3));
label_110c24:
    // 0x110c24: 0x881806  srlv        $v1, $t0, $a0
    ctx->pc = 0x110c24u;
    SET_GPR_S32(ctx, 3, (int32_t)SRL32(GPR_U32(ctx, 8), GPR_U32(ctx, 4) & 0x1F));
    // 0x110c28: 0x24050020  addiu       $a1, $zero, 0x20
    ctx->pc = 0x110c28u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 32));
    // 0x110c2c: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x110c2cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x110c30: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x110c30u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x110c34: 0x904283a0  lbu         $v0, -0x7C60($v0)
    ctx->pc = 0x110c34u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294935456)));
    // 0x110c38: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x110c38u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x110c3c: 0xa23023  subu        $a2, $a1, $v0
    ctx->pc = 0x110c3cu;
    SET_GPR_S32(ctx, 6, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x110c40: 0x14c00009  bnez        $a2, . + 4 + (0x9 << 2)
    ctx->pc = 0x110C40u;
    {
        const bool branch_taken_0x110c40 = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x110C44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110C40u;
            // 0x110c44: 0xa63823  subu        $a3, $a1, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110c40) {
            ctx->pc = 0x110C68u;
            goto label_110c68;
        }
    }
    ctx->pc = 0x110C48u;
    // 0x110c48: 0x10a102b  sltu        $v0, $t0, $t2
    ctx->pc = 0x110c48u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)GPR_U64(ctx, 10)) ? 1 : 0);
    // 0x110c4c: 0x1440004e  bnez        $v0, . + 4 + (0x4E << 2)
    ctx->pc = 0x110C4Cu;
    {
        const bool branch_taken_0x110c4c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x110C50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110C4Cu;
            // 0x110c50: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110c4c) {
            ctx->pc = 0x110D88u;
            goto label_110d88;
        }
    }
    ctx->pc = 0x110C54u;
    // 0x110c54: 0x169102b  sltu        $v0, $t3, $t1
    ctx->pc = 0x110c54u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)GPR_U64(ctx, 9)) ? 1 : 0);
    // 0x110c58: 0x1440004b  bnez        $v0, . + 4 + (0x4B << 2)
    ctx->pc = 0x110C58u;
    {
        const bool branch_taken_0x110c58 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x110C5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110C58u;
            // 0x110c5c: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110c58) {
            ctx->pc = 0x110D88u;
            goto label_110d88;
        }
    }
    ctx->pc = 0x110C60u;
    // 0x110c60: 0x10000049  b           . + 4 + (0x49 << 2)
    ctx->pc = 0x110C60u;
    {
        const bool branch_taken_0x110c60 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x110C64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110C60u;
            // 0x110c64: 0x24060001  addiu       $a2, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110c60) {
            ctx->pc = 0x110D88u;
            goto label_110d88;
        }
    }
    ctx->pc = 0x110C68u;
label_110c68:
    // 0x110c68: 0xc82004  sllv        $a0, $t0, $a2
    ctx->pc = 0x110c68u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), GPR_U32(ctx, 6) & 0x1F));
    // 0x110c6c: 0xeb2806  srlv        $a1, $t3, $a3
    ctx->pc = 0x110c6cu;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 11), GPR_U32(ctx, 7) & 0x1F));
    // 0x110c70: 0xcb5804  sllv        $t3, $t3, $a2
    ctx->pc = 0x110c70u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), GPR_U32(ctx, 6) & 0x1F));
    // 0x110c74: 0xe91006  srlv        $v0, $t1, $a3
    ctx->pc = 0x110c74u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 9), GPR_U32(ctx, 7) & 0x1F));
    // 0x110c78: 0xc94804  sllv        $t1, $t1, $a2
    ctx->pc = 0x110c78u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), GPR_U32(ctx, 6) & 0x1F));
    // 0x110c7c: 0xca1804  sllv        $v1, $t2, $a2
    ctx->pc = 0x110c7cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 10), GPR_U32(ctx, 6) & 0x1F));
    // 0x110c80: 0x824025  or          $t0, $a0, $v0
    ctx->pc = 0x110c80u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 4) | GPR_U64(ctx, 2));
    // 0x110c84: 0xea2006  srlv        $a0, $t2, $a3
    ctx->pc = 0x110c84u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 10), GPR_U32(ctx, 7) & 0x1F));
    // 0x110c88: 0x655025  or          $t2, $v1, $a1
    ctx->pc = 0x110c88u;
    SET_GPR_U64(ctx, 10, GPR_U64(ctx, 3) | GPR_U64(ctx, 5));
    // 0x110c8c: 0x82c02  srl         $a1, $t0, 16
    ctx->pc = 0x110c8cu;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 8), 16));
    // 0x110c90: 0x85001b  divu        $zero, $a0, $a1
    ctx->pc = 0x110c90u;
    { uint32_t divisor = GPR_U32(ctx, 5); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 4) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,4); } }
    // 0x110c94: 0xa2402  srl         $a0, $t2, 16
    ctx->pc = 0x110c94u;
    SET_GPR_S32(ctx, 4, (int32_t)SRL32(GPR_U32(ctx, 10), 16));
    // 0x110c98: 0x310cffff  andi        $t4, $t0, 0xFFFF
    ctx->pc = 0x110c98u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 8) & (uint64_t)(uint16_t)65535);
    // 0x110c9c: 0x50a00001  beql        $a1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x110C9Cu;
    {
        const bool branch_taken_0x110c9c = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x110c9c) {
            ctx->pc = 0x110CA0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110C9Cu;
            // 0x110ca0: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x110CA4u;
            goto label_110ca4;
        }
    }
    ctx->pc = 0x110CA4u;
label_110ca4:
    // 0x110ca4: 0x1012  mflo        $v0
    ctx->pc = 0x110ca4u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x110ca8: 0x1810  mfhi        $v1
    ctx->pc = 0x110ca8u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x110cac: 0x40382d  daddu       $a3, $v0, $zero
    ctx->pc = 0x110cacu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x110cb0: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x110cb0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x110cb4: 0xec3018  mult        $a2, $a3, $t4
    ctx->pc = 0x110cb4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 12); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 6, (int32_t)result); }
    // 0x110cb8: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x110cb8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x110cbc: 0x66102b  sltu        $v0, $v1, $a2
    ctx->pc = 0x110cbcu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x110cc0: 0x5040000c  beql        $v0, $zero, . + 4 + (0xC << 2)
    ctx->pc = 0x110CC0u;
    {
        const bool branch_taken_0x110cc0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x110cc0) {
            ctx->pc = 0x110CC4u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110CC0u;
            // 0x110cc4: 0x661823  subu        $v1, $v1, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x110CF4u;
            goto label_110cf4;
        }
    }
    ctx->pc = 0x110CC8u;
    // 0x110cc8: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x110cc8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x110ccc: 0x68102b  sltu        $v0, $v1, $t0
    ctx->pc = 0x110cccu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x110cd0: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x110CD0u;
    {
        const bool branch_taken_0x110cd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x110CD4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110CD0u;
            // 0x110cd4: 0x24e7ffff  addiu       $a3, $a3, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110cd0) {
            ctx->pc = 0x110CF0u;
            goto label_110cf0;
        }
    }
    ctx->pc = 0x110CD8u;
    // 0x110cd8: 0x66102b  sltu        $v0, $v1, $a2
    ctx->pc = 0x110cd8u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x110cdc: 0x50400005  beql        $v0, $zero, . + 4 + (0x5 << 2)
    ctx->pc = 0x110CDCu;
    {
        const bool branch_taken_0x110cdc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x110cdc) {
            ctx->pc = 0x110CE0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110CDCu;
            // 0x110ce0: 0x661823  subu        $v1, $v1, $a2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x110CF4u;
            goto label_110cf4;
        }
    }
    ctx->pc = 0x110CE4u;
    // 0x110ce4: 0x24e7ffff  addiu       $a3, $a3, -0x1
    ctx->pc = 0x110ce4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x110ce8: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x110ce8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x110cec: 0x0  nop
    ctx->pc = 0x110cecu;
    // NOP
label_110cf0:
    // 0x110cf0: 0x661823  subu        $v1, $v1, $a2
    ctx->pc = 0x110cf0u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
label_110cf4:
    // 0x110cf4: 0x50a00001  beql        $a1, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x110CF4u;
    {
        const bool branch_taken_0x110cf4 = (GPR_U64(ctx, 5) == GPR_U64(ctx, 0));
        if (branch_taken_0x110cf4) {
            ctx->pc = 0x110CF8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110CF4u;
            // 0x110cf8: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x110CFCu;
            goto label_110cfc;
        }
    }
    ctx->pc = 0x110CFCu;
label_110cfc:
    // 0x110cfc: 0x65001b  divu        $zero, $v1, $a1
    ctx->pc = 0x110cfcu;
    { uint32_t divisor = GPR_U32(ctx, 5); if (divisor != 0) { ctx->lo = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) / divisor); ctx->hi = (uint64_t)(int64_t)(int32_t)(GPR_U32(ctx, 3) % divisor); } else { ctx->lo = 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)(int32_t)GPR_U32(ctx,3); } }
    // 0x110d00: 0x3144ffff  andi        $a0, $t2, 0xFFFF
    ctx->pc = 0x110d00u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 10) & (uint64_t)(uint16_t)65535);
    // 0x110d04: 0x1012  mflo        $v0
    ctx->pc = 0x110d04u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x110d08: 0x1810  mfhi        $v1
    ctx->pc = 0x110d08u;
    SET_GPR_U64(ctx, 3, ctx->hi);
    // 0x110d0c: 0x40282d  daddu       $a1, $v0, $zero
    ctx->pc = 0x110d0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x110d10: 0x31c00  sll         $v1, $v1, 16
    ctx->pc = 0x110d10u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 16));
    // 0x110d14: 0xac3018  mult        $a2, $a1, $t4
    ctx->pc = 0x110d14u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 12); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 6, (int32_t)result); }
    // 0x110d18: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x110d18u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x110d1c: 0x66102b  sltu        $v0, $v1, $a2
    ctx->pc = 0x110d1cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x110d20: 0x1040000b  beqz        $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x110D20u;
    {
        const bool branch_taken_0x110d20 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x110D24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110D20u;
            // 0x110d24: 0x71400  sll         $v0, $a3, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110d20) {
            ctx->pc = 0x110D50u;
            goto label_110d50;
        }
    }
    ctx->pc = 0x110D28u;
    // 0x110d28: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x110d28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x110d2c: 0x68102b  sltu        $v0, $v1, $t0
    ctx->pc = 0x110d2cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 8)) ? 1 : 0);
    // 0x110d30: 0x14400006  bnez        $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x110D30u;
    {
        const bool branch_taken_0x110d30 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x110D34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110D30u;
            // 0x110d34: 0x24a5ffff  addiu       $a1, $a1, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110d30) {
            ctx->pc = 0x110D4Cu;
            goto label_110d4c;
        }
    }
    ctx->pc = 0x110D38u;
    // 0x110d38: 0x66102b  sltu        $v0, $v1, $a2
    ctx->pc = 0x110d38u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 6)) ? 1 : 0);
    // 0x110d3c: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x110D3Cu;
    {
        const bool branch_taken_0x110d3c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x110D40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110D3Cu;
            // 0x110d40: 0x71400  sll         $v0, $a3, 16 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110d3c) {
            ctx->pc = 0x110D50u;
            goto label_110d50;
        }
    }
    ctx->pc = 0x110D44u;
    // 0x110d44: 0x681821  addu        $v1, $v1, $t0
    ctx->pc = 0x110d44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x110d48: 0x24a5ffff  addiu       $a1, $a1, -0x1
    ctx->pc = 0x110d48u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294967295));
label_110d4c:
    // 0x110d4c: 0x71400  sll         $v0, $a3, 16
    ctx->pc = 0x110d4cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 7), 16));
label_110d50:
    // 0x110d50: 0x661823  subu        $v1, $v1, $a2
    ctx->pc = 0x110d50u;
    SET_GPR_S32(ctx, 3, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x110d54: 0x453025  or          $a2, $v0, $a1
    ctx->pc = 0x110d54u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) | GPR_U64(ctx, 5));
    // 0x110d58: 0xc90019  multu       $a2, $t1
    ctx->pc = 0x110d58u;
    { uint64_t result = (uint64_t)GPR_U32(ctx, 6) * (uint64_t)GPR_U32(ctx, 9); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); }
    // 0x110d5c: 0x3810  mfhi        $a3
    ctx->pc = 0x110d5cu;
    SET_GPR_U64(ctx, 7, ctx->hi);
    // 0x110d60: 0x2012  mflo        $a0
    ctx->pc = 0x110d60u;
    SET_GPR_U64(ctx, 4, ctx->lo);
    // 0x110d64: 0x67102b  sltu        $v0, $v1, $a3
    ctx->pc = 0x110d64u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 3) < (uint64_t)GPR_U64(ctx, 7)) ? 1 : 0);
    // 0x110d68: 0x54400007  bnel        $v0, $zero, . + 4 + (0x7 << 2)
    ctx->pc = 0x110D68u;
    {
        const bool branch_taken_0x110d68 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x110d68) {
            ctx->pc = 0x110D6Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x110D68u;
            // 0x110d6c: 0x24c6ffff  addiu       $a2, $a2, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
        ctx->in_delay_slot = false;
            ctx->pc = 0x110D88u;
            goto label_110d88;
        }
    }
    ctx->pc = 0x110D70u;
    // 0x110d70: 0x14e30006  bne         $a3, $v1, . + 4 + (0x6 << 2)
    ctx->pc = 0x110D70u;
    {
        const bool branch_taken_0x110d70 = (GPR_U64(ctx, 7) != GPR_U64(ctx, 3));
        ctx->pc = 0x110D74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110D70u;
            // 0x110d74: 0x682d  daddu       $t5, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x110d70) {
            ctx->pc = 0x110D8Cu;
            goto label_110d8c;
        }
    }
    ctx->pc = 0x110D78u;
    // 0x110d78: 0x164102b  sltu        $v0, $t3, $a0
    ctx->pc = 0x110d78u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)GPR_U64(ctx, 4)) ? 1 : 0);
    // 0x110d7c: 0x10400003  beqz        $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x110D7Cu;
    {
        const bool branch_taken_0x110d7c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x110d7c) {
            ctx->pc = 0x110D8Cu;
            goto label_110d8c;
        }
    }
    ctx->pc = 0x110D84u;
    // 0x110d84: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x110d84u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
label_110d88:
    // 0x110d88: 0x682d  daddu       $t5, $zero, $zero
    ctx->pc = 0x110d88u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_110d8c:
    // 0x110d8c: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x110d8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x110d90: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x110d90u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x110d94: 0x6103c  dsll32      $v0, $a2, 0
    ctx->pc = 0x110d94u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) << (32 + 0));
    // 0x110d98: 0x2103e  dsrl32      $v0, $v0, 0
    ctx->pc = 0x110d98u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x110d9c: 0x1c37024  and         $t6, $t6, $v1
    ctx->pc = 0x110d9cu;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 14) & GPR_U64(ctx, 3));
    // 0x110da0: 0x1c27025  or          $t6, $t6, $v0
    ctx->pc = 0x110da0u;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 14) | GPR_U64(ctx, 2));
    // 0x110da4: 0xd103c  dsll32      $v0, $t5, 0
    ctx->pc = 0x110da4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 13) << (32 + 0));
    // 0x110da8: 0x3c03ffff  lui         $v1, 0xFFFF
    ctx->pc = 0x110da8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)65535 << 16));
    // 0x110dac: 0x3183e  dsrl32      $v1, $v1, 0
    ctx->pc = 0x110dacu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 0));
    // 0x110db0: 0x1c37024  and         $t6, $t6, $v1
    ctx->pc = 0x110db0u;
    SET_GPR_U64(ctx, 14, GPR_U64(ctx, 14) & GPR_U64(ctx, 3));
    // 0x110db4: 0x3e00008  jr          $ra
    ctx->pc = 0x110DB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x110DB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x110DB4u;
            // 0x110db8: 0x1c21025  or          $v0, $t6, $v0 (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 14) | GPR_U64(ctx, 2));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x110888u: goto label_110888;
            case 0x11089Cu: goto label_11089c;
            case 0x1108D4u: goto label_1108d4;
            case 0x1108ECu: goto label_1108ec;
            case 0x110938u: goto label_110938;
            case 0x11093Cu: goto label_11093c;
            case 0x110944u: goto label_110944;
            case 0x110990u: goto label_110990;
            case 0x110994u: goto label_110994;
            case 0x1109A0u: goto label_1109a0;
            case 0x1109B4u: goto label_1109b4;
            case 0x1109C8u: goto label_1109c8;
            case 0x1109E0u: goto label_1109e0;
            case 0x1109F4u: goto label_1109f4;
            case 0x110A30u: goto label_110a30;
            case 0x110A64u: goto label_110a64;
            case 0x110AB0u: goto label_110ab0;
            case 0x110AB4u: goto label_110ab4;
            case 0x110ABCu: goto label_110abc;
            case 0x110B0Cu: goto label_110b0c;
            case 0x110B10u: goto label_110b10;
            case 0x110B18u: goto label_110b18;
            case 0x110B30u: goto label_110b30;
            case 0x110B78u: goto label_110b78;
            case 0x110B7Cu: goto label_110b7c;
            case 0x110B84u: goto label_110b84;
            case 0x110BD0u: goto label_110bd0;
            case 0x110BD4u: goto label_110bd4;
            case 0x110BE0u: goto label_110be0;
            case 0x110BF0u: goto label_110bf0;
            case 0x110C10u: goto label_110c10;
            case 0x110C24u: goto label_110c24;
            case 0x110C68u: goto label_110c68;
            case 0x110CA4u: goto label_110ca4;
            case 0x110CF0u: goto label_110cf0;
            case 0x110CF4u: goto label_110cf4;
            case 0x110CFCu: goto label_110cfc;
            case 0x110D4Cu: goto label_110d4c;
            case 0x110D50u: goto label_110d50;
            case 0x110D88u: goto label_110d88;
            case 0x110D8Cu: goto label_110d8c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x110DBCu;
    // 0x110dbc: 0x0  nop
    ctx->pc = 0x110dbcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
