#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00197780
// Address: 0x197780 - 0x197900
void sub_00197780_0x197780(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00197780_0x197780");
#endif

    switch (ctx->pc) {
        case 0x1977e0u: goto label_1977e0;
        case 0x1977f4u: goto label_1977f4;
        case 0x1978e4u: goto label_1978e4;
        default: break;
    }

    ctx->pc = 0x197780u;

    // 0x197780: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x197780u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x197784: 0x30828000  andi        $v0, $a0, 0x8000
    ctx->pc = 0x197784u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)32768);
    // 0x197788: 0xffbf0020  sd          $ra, 0x20($sp)
    ctx->pc = 0x197788u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x19778c: 0x38428000  xori        $v0, $v0, 0x8000
    ctx->pc = 0x19778cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)32768);
    // 0x197790: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x197790u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x197794: 0x2182b  sltu        $v1, $zero, $v0
    ctx->pc = 0x197794u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 0) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x197798: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x197798u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19779c: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x19779cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1977a0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1977a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1977a4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1977a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1977a8: 0x8c25f9f0  lw          $a1, -0x610($at)
    ctx->pc = 0x1977a8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965744)));
    // 0x1977ac: 0x3183c  dsll32      $v1, $v1, 0
    ctx->pc = 0x1977acu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1977b0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1977b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1977b4: 0x52942  srl         $a1, $a1, 5
    ctx->pc = 0x1977b4u;
    SET_GPR_S32(ctx, 5, (int32_t)SRL32(GPR_U32(ctx, 5), 5));
    // 0x1977b8: 0x8c24f9e4  lw          $a0, -0x61C($at)
    ctx->pc = 0x1977b8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294965732)));
    // 0x1977bc: 0x5283c  dsll32      $a1, $a1, 0
    ctx->pc = 0x1977bcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x1977c0: 0x5283f  dsra32      $a1, $a1, 0
    ctx->pc = 0x1977c0u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x1977c4: 0x42638  dsll        $a0, $a0, 24
    ctx->pc = 0x1977c4u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 24);
    // 0x1977c8: 0xa42025  or          $a0, $a1, $a0
    ctx->pc = 0x1977c8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 5) | GPR_U64(ctx, 4));
    // 0x1977cc: 0x12220006  beq         $s1, $v0, . + 4 + (0x6 << 2)
    ctx->pc = 0x1977CCu;
    {
        const bool branch_taken_0x1977cc = (GPR_U64(ctx, 17) == GPR_U64(ctx, 2));
        ctx->pc = 0x1977D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1977CCu;
            // 0x1977d0: 0x648025  or          $s0, $v1, $a0 (Delay Slot)
        SET_GPR_U64(ctx, 16, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1977cc) {
            ctx->pc = 0x1977E8u;
            goto label_1977e8;
        }
    }
    ctx->pc = 0x1977D4u;
    // 0x1977d4: 0x24040030  addiu       $a0, $zero, 0x30
    ctx->pc = 0x1977d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 48));
    // 0x1977d8: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x1977D8u;
    SET_GPR_U32(ctx, 31, 0x1977E0u);
    ctx->pc = 0x1977DCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1977D8u;
            // 0x1977dc: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1977E0u; }
        if (ctx->pc != 0x1977E0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1977E0u; }
        if (ctx->pc != 0x1977E0u) { return; }
    }
    ctx->pc = 0x1977E0u;
label_1977e0:
    // 0x1977e0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1977E0u;
    {
        const bool branch_taken_0x1977e0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1977E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1977E0u;
            // 0x1977e4: 0x24070002  addiu       $a3, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1977e0) {
            ctx->pc = 0x1977F8u;
            goto label_1977f8;
        }
    }
    ctx->pc = 0x1977E8u;
label_1977e8:
    // 0x1977e8: 0x24040040  addiu       $a0, $zero, 0x40
    ctx->pc = 0x1977e8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 64));
    // 0x1977ec: 0xc063774  jal         func_18DDD0
    ctx->pc = 0x1977ECu;
    SET_GPR_U32(ctx, 31, 0x1977F4u);
    ctx->pc = 0x1977F0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1977ECu;
            // 0x1977f0: 0x24050010  addiu       $a1, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18DDD0u;
    if (runtime->hasFunction(0x18DDD0u)) {
        auto targetFn = runtime->lookupFunction(0x18DDD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1977F4u; }
        if (ctx->pc != 0x1977F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1977F4u; }
        if (ctx->pc != 0x1977F4u) { return; }
    }
    ctx->pc = 0x1977F4u;
label_1977f4:
    // 0x1977f4: 0x24070003  addiu       $a3, $zero, 0x3
    ctx->pc = 0x1977f4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
label_1977f8:
    // 0x1977f8: 0x3c047000  lui         $a0, 0x7000
    ctx->pc = 0x1977f8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)28672 << 16));
    // 0x1977fc: 0x3c038000  lui         $v1, 0x8000
    ctx->pc = 0x1977fcu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)32768 << 16));
    // 0x197800: 0xe42021  addu        $a0, $a3, $a0
    ctx->pc = 0x197800u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
    // 0x197804: 0x3c051300  lui         $a1, 0x1300
    ctx->pc = 0x197804u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)4864 << 16));
    // 0x197808: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x197808u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x19780c: 0x4303c  dsll32      $a2, $a0, 0
    ctx->pc = 0x19780cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) << (32 + 0));
    // 0x197810: 0x3c035000  lui         $v1, 0x5000
    ctx->pc = 0x197810u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)20480 << 16));
    // 0x197814: 0x6303e  dsrl32      $a2, $a2, 0
    ctx->pc = 0x197814u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 0));
    // 0x197818: 0xe32025  or          $a0, $a3, $v1
    ctx->pc = 0x197818u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 7) | GPR_U64(ctx, 3));
    // 0x19781c: 0xfc460000  sd          $a2, 0x0($v0)
    ctx->pc = 0x19781cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 6));
    // 0x197820: 0x24e3ffff  addiu       $v1, $a3, -0x1
    ctx->pc = 0x197820u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x197824: 0xac450008  sw          $a1, 0x8($v0)
    ctx->pc = 0x197824u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 5));
    // 0x197828: 0x3283c  dsll32      $a1, $v1, 0
    ctx->pc = 0x197828u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) << (32 + 0));
    // 0x19782c: 0xac44000c  sw          $a0, 0xC($v0)
    ctx->pc = 0x19782cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 4));
    // 0x197830: 0x3c031000  lui         $v1, 0x1000
    ctx->pc = 0x197830u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)4096 << 16));
    // 0x197834: 0x5283e  dsrl32      $a1, $a1, 0
    ctx->pc = 0x197834u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 0));
    // 0x197838: 0x3203c  dsll32      $a0, $v1, 0
    ctx->pc = 0x197838u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << (32 + 0));
    // 0x19783c: 0x34038000  ori         $v1, $zero, 0x8000
    ctx->pc = 0x19783cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x197840: 0x641825  or          $v1, $v1, $a0
    ctx->pc = 0x197840u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) | GPR_U64(ctx, 4));
    // 0x197844: 0xa32825  or          $a1, $a1, $v1
    ctx->pc = 0x197844u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) | GPR_U64(ctx, 3));
    // 0x197848: 0x2404000e  addiu       $a0, $zero, 0xE
    ctx->pc = 0x197848u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 14));
    // 0x19784c: 0xfc450010  sd          $a1, 0x10($v0)
    ctx->pc = 0x19784cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 16), GPR_U64(ctx, 5));
    // 0x197850: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x197850u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x197854: 0x12230012  beq         $s1, $v1, . + 4 + (0x12 << 2)
    ctx->pc = 0x197854u;
    {
        const bool branch_taken_0x197854 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 3));
        ctx->pc = 0x197858u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197854u;
            // 0x197858: 0xfc440018  sd          $a0, 0x18($v0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 2), 24), GPR_U64(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197854) {
            ctx->pc = 0x1978A0u;
            goto label_1978a0;
        }
    }
    ctx->pc = 0x19785Cu;
    // 0x19785c: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x19785cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x197860: 0x1223000a  beq         $s1, $v1, . + 4 + (0xA << 2)
    ctx->pc = 0x197860u;
    {
        const bool branch_taken_0x197860 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 3));
        ctx->pc = 0x197864u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197860u;
            // 0x197864: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197860) {
            ctx->pc = 0x19788Cu;
            goto label_19788c;
        }
    }
    ctx->pc = 0x197868u;
    // 0x197868: 0x12200003  beqz        $s1, . + 4 + (0x3 << 2)
    ctx->pc = 0x197868u;
    {
        const bool branch_taken_0x197868 = (GPR_U64(ctx, 17) == GPR_U64(ctx, 0));
        ctx->pc = 0x19786Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197868u;
            // 0x19786c: 0x3c01002a  lui         $at, 0x2A (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197868) {
            ctx->pc = 0x197878u;
            goto label_197878;
        }
    }
    ctx->pc = 0x197870u;
    // 0x197870: 0x10000016  b           . + 4 + (0x16 << 2)
    ctx->pc = 0x197870u;
    {
        const bool branch_taken_0x197870 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197874u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197870u;
            // 0x197874: 0x2293c  dsll32      $a1, $v0, 4 (Delay Slot)
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197870) {
            ctx->pc = 0x1978CCu;
            goto label_1978cc;
        }
    }
    ctx->pc = 0x197878u;
label_197878:
    // 0x197878: 0x2403004e  addiu       $v1, $zero, 0x4E
    ctx->pc = 0x197878u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 78));
    // 0x19787c: 0xfc30fde0  sd          $s0, -0x220($at)
    ctx->pc = 0x19787cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294966752), GPR_U64(ctx, 16));
    // 0x197880: 0xfc500020  sd          $s0, 0x20($v0)
    ctx->pc = 0x197880u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 16));
    // 0x197884: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x197884u;
    {
        const bool branch_taken_0x197884 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x197888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197884u;
            // 0x197888: 0xfc430028  sd          $v1, 0x28($v0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197884) {
            ctx->pc = 0x1978C8u;
            goto label_1978c8;
        }
    }
    ctx->pc = 0x19788Cu;
label_19788c:
    // 0x19788c: 0x2403004f  addiu       $v1, $zero, 0x4F
    ctx->pc = 0x19788cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 79));
    // 0x197890: 0xfc30fde8  sd          $s0, -0x218($at)
    ctx->pc = 0x197890u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294966760), GPR_U64(ctx, 16));
    // 0x197894: 0xfc500020  sd          $s0, 0x20($v0)
    ctx->pc = 0x197894u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 16));
    // 0x197898: 0x1000000b  b           . + 4 + (0xB << 2)
    ctx->pc = 0x197898u;
    {
        const bool branch_taken_0x197898 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x19789Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x197898u;
            // 0x19789c: 0xfc430028  sd          $v1, 0x28($v0) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x197898) {
            ctx->pc = 0x1978C8u;
            goto label_1978c8;
        }
    }
    ctx->pc = 0x1978A0u;
label_1978a0:
    // 0x1978a0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1978a0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1978a4: 0x2404004e  addiu       $a0, $zero, 0x4E
    ctx->pc = 0x1978a4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 78));
    // 0x1978a8: 0xfc30fde0  sd          $s0, -0x220($at)
    ctx->pc = 0x1978a8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294966752), GPR_U64(ctx, 16));
    // 0x1978ac: 0x2403004f  addiu       $v1, $zero, 0x4F
    ctx->pc = 0x1978acu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 79));
    // 0x1978b0: 0x3c01002a  lui         $at, 0x2A
    ctx->pc = 0x1978b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)42 << 16));
    // 0x1978b4: 0xfc30fde8  sd          $s0, -0x218($at)
    ctx->pc = 0x1978b4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294966760), GPR_U64(ctx, 16));
    // 0x1978b8: 0xfc500020  sd          $s0, 0x20($v0)
    ctx->pc = 0x1978b8u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 16));
    // 0x1978bc: 0xfc440028  sd          $a0, 0x28($v0)
    ctx->pc = 0x1978bcu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 4));
    // 0x1978c0: 0xfc500030  sd          $s0, 0x30($v0)
    ctx->pc = 0x1978c0u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 48), GPR_U64(ctx, 16));
    // 0x1978c4: 0xfc430038  sd          $v1, 0x38($v0)
    ctx->pc = 0x1978c4u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 56), GPR_U64(ctx, 3));
label_1978c8:
    // 0x1978c8: 0x2293c  dsll32      $a1, $v0, 4
    ctx->pc = 0x1978c8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 4));
label_1978cc:
    // 0x1978cc: 0x3c07002a  lui         $a3, 0x2A
    ctx->pc = 0x1978ccu;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)42 << 16));
    // 0x1978d0: 0x5293e  dsrl32      $a1, $a1, 4
    ctx->pc = 0x1978d0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 4));
    // 0x1978d4: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x1978d4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1978d8: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1978d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1978dc: 0xc0633ec  jal         func_18CFB0
    ctx->pc = 0x1978DCu;
    SET_GPR_U32(ctx, 31, 0x1978E4u);
    ctx->pc = 0x1978E0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1978DCu;
            // 0x1978e0: 0x24e7f6f0  addiu       $a3, $a3, -0x910 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294964976));
        ctx->in_delay_slot = false;
    ctx->pc = 0x18CFB0u;
    if (runtime->hasFunction(0x18CFB0u)) {
        auto targetFn = runtime->lookupFunction(0x18CFB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1978E4u; }
        if (ctx->pc != 0x1978E4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1978E4u; }
        if (ctx->pc != 0x1978E4u) { return; }
    }
    ctx->pc = 0x1978E4u;
label_1978e4:
    // 0x1978e4: 0xdfbf0020  ld          $ra, 0x20($sp)
    ctx->pc = 0x1978e4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1978e8: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1978e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1978ec: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1978ecu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1978f0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1978f0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1978f4: 0x3e00008  jr          $ra
    ctx->pc = 0x1978F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1978F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1978F4u;
            // 0x1978f8: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1977E0u: goto label_1977e0;
            case 0x1977E8u: goto label_1977e8;
            case 0x1977F4u: goto label_1977f4;
            case 0x1977F8u: goto label_1977f8;
            case 0x197878u: goto label_197878;
            case 0x19788Cu: goto label_19788c;
            case 0x1978A0u: goto label_1978a0;
            case 0x1978C8u: goto label_1978c8;
            case 0x1978CCu: goto label_1978cc;
            case 0x1978E4u: goto label_1978e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1978FCu;
    // 0x1978fc: 0x0  nop
    ctx->pc = 0x1978fcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
