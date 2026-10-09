#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001276D8
// Address: 0x1276d8 - 0x127fc8
void sub_001276D8_0x1276d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001276D8_0x1276d8");
#endif

    switch (ctx->pc) {
        case 0x127748u: goto label_127748;
        case 0x1277a8u: goto label_1277a8;
        case 0x127948u: goto label_127948;
        case 0x127a18u: goto label_127a18;
        case 0x127d08u: goto label_127d08;
        case 0x127dd8u: goto label_127dd8;
        default: break;
    }

    ctx->pc = 0x1276d8u;

    // 0x1276d8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1276d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1276dc: 0x84400  sll         $t0, $t0, 16
    ctx->pc = 0x1276dcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 16));
    // 0x1276e0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1276e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1276e4: 0x94c00  sll         $t1, $t1, 16
    ctx->pc = 0x1276e4u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 16));
    // 0x1276e8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1276e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1276ec: 0x88c03  sra         $s1, $t0, 16
    ctx->pc = 0x1276ecu;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 8), 16));
    // 0x1276f0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1276f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1276f4: 0x140902d  daddu       $s2, $t2, $zero
    ctx->pc = 0x1276f4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1276f8: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x1276f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1276fc: 0xa0982d  daddu       $s3, $a1, $zero
    ctx->pc = 0x1276fcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127700: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x127700u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x127704: 0xe0a02d  daddu       $s4, $a3, $zero
    ctx->pc = 0x127704u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127708: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x127708u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x12770c: 0xb5c00  sll         $t3, $t3, 16
    ctx->pc = 0x12770cu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 16));
    // 0x127710: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x127710u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x127714: 0xbb403  sra         $s6, $t3, 16
    ctx->pc = 0x127714u;
    SET_GPR_S32(ctx, 22, SRA32(GPR_S32(ctx, 11), 16));
    // 0x127718: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x127718u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x12771c: 0x98403  sra         $s0, $t1, 16
    ctx->pc = 0x12771cu;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 9), 16));
    // 0x127720: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x127720u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x127724: 0x80682d  daddu       $t5, $a0, $zero
    ctx->pc = 0x127724u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127728: 0x87b50050  lh          $s5, 0x50($sp)
    ctx->pc = 0x127728u;
    SET_GPR_S32(ctx, 21, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x12772c: 0x502d  daddu       $t2, $zero, $zero
    ctx->pc = 0x12772cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127730: 0x86850000  lh          $a1, 0x0($s4)
    ctx->pc = 0x127730u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x127734: 0x1a600051  blez        $s3, . + 4 + (0x51 << 2)
    ctx->pc = 0x127734u;
    {
        const bool branch_taken_0x127734 = (GPR_S64(ctx, 19) <= 0);
        ctx->pc = 0x127738u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127734u;
            // 0x127738: 0x868e0002  lh          $t6, 0x2($s4) (Delay Slot)
        SET_GPR_S32(ctx, 14, (int16_t)READ16(ADD32(GPR_U32(ctx, 20), 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127734) {
            ctx->pc = 0x12787Cu;
            goto label_12787c;
        }
    }
    ctx->pc = 0x12773Cu;
    // 0x12773c: 0x241eff00  addiu       $fp, $zero, -0x100
    ctx->pc = 0x12773cu;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x127740: 0x3c170024  lui         $s7, 0x24
    ctx->pc = 0x127740u;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)36 << 16));
    // 0x127744: 0x95a30000  lhu         $v1, 0x0($t5)
    ctx->pc = 0x127744u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 13), 0)));
label_127748:
    // 0x127748: 0x91a40001  lbu         $a0, 0x1($t5)
    ctx->pc = 0x127748u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 13), 1)));
    // 0x12774c: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x12774cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x127750: 0x7e1824  and         $v1, $v1, $fp
    ctx->pc = 0x127750u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 30));
    // 0x127754: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x127754u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x127758: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x127758u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x12775c: 0x42403  sra         $a0, $a0, 16
    ctx->pc = 0x12775cu;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x127760: 0x30838000  andi        $v1, $a0, 0x8000
    ctx->pc = 0x127760u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)32768);
    // 0x127764: 0x14600048  bnez        $v1, . + 4 + (0x48 << 2)
    ctx->pc = 0x127764u;
    {
        const bool branch_taken_0x127764 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x127768u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127764u;
            // 0x127768: 0x140102d  daddu       $v0, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127764) {
            ctx->pc = 0x127888u;
            goto label_127888;
        }
    }
    ctx->pc = 0x12776Cu;
    // 0x12776c: 0x96420000  lhu         $v0, 0x0($s2)
    ctx->pc = 0x12776cu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x127770: 0x25ad0002  addiu       $t5, $t5, 0x2
    ctx->pc = 0x127770u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 2));
    // 0x127774: 0x34098000  ori         $t1, $zero, 0x8000
    ctx->pc = 0x127774u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x127778: 0x3408ffff  ori         $t0, $zero, 0xFFFF
    ctx->pc = 0x127778u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x12777c: 0x563818  mult        $a3, $v0, $s6
    ctx->pc = 0x12777cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 22); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 7, (int32_t)result); }
    // 0x127780: 0x821026  xor         $v0, $a0, $v0
    ctx->pc = 0x127780u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) ^ GPR_U64(ctx, 2));
    // 0x127784: 0x30421fff  andi        $v0, $v0, 0x1FFF
    ctx->pc = 0x127784u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)8191);
    // 0x127788: 0x24197fff  addiu       $t9, $zero, 0x7FFF
    ctx->pc = 0x127788u;
    SET_GPR_S32(ctx, 25, (int32_t)ADD32(GPR_U32(ctx, 0), 32767));
    // 0x12778c: 0x244f0001  addiu       $t7, $v0, 0x1
    ctx->pc = 0x12778cu;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x127790: 0x26eb9be8  addiu       $t3, $s7, -0x6418
    ctx->pc = 0x127790u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 23), 4294941672));
    // 0x127794: 0xf51821  addu        $v1, $a3, $s5
    ctx->pc = 0x127794u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 21)));
    // 0x127798: 0x2407001e  addiu       $a3, $zero, 0x1E
    ctx->pc = 0x127798u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
    // 0x12779c: 0x30637fff  andi        $v1, $v1, 0x7FFF
    ctx->pc = 0x12779cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)32767);
    // 0x1277a0: 0xa6430000  sh          $v1, 0x0($s2)
    ctx->pc = 0x1277a0u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1277a4: 0x0  nop
    ctx->pc = 0x1277a4u;
    // NOP
label_1277a8:
    // 0x1277a8: 0x91a30000  lbu         $v1, 0x0($t5)
    ctx->pc = 0x1277a8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 13), 0)));
    // 0x1277ac: 0x25ad0001  addiu       $t5, $t5, 0x1
    ctx->pc = 0x1277acu;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), 1));
    // 0x1277b0: 0x20e1018  mult        $v0, $s0, $t6
    ctx->pc = 0x1277b0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 14); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1277b4: 0xa0702d  daddu       $t6, $a1, $zero
    ctx->pc = 0x1277b4u;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1277b8: 0x72252018  mult1       $a0, $s1, $a1
    ctx->pc = 0x1277b8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 5); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x1277bc: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x1277bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1277c0: 0x32f03  sra         $a1, $v1, 28
    ctx->pc = 0x1277c0u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 3), 28));
    // 0x1277c4: 0x31e03  sra         $v1, $v1, 24
    ctx->pc = 0x1277c4u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 24));
    // 0x1277c8: 0xaf2818  mult        $a1, $a1, $t7
    ctx->pc = 0x1277c8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 15); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x1277cc: 0x20ec018  mult        $t8, $s0, $t6
    ctx->pc = 0x1277ccu;
    { int64_t result = (int64_t)GPR_S32(ctx, 16) * (int64_t)GPR_S32(ctx, 14); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 24, (int32_t)result); }
    // 0x1277d0: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x1277d0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1277d4: 0x3062000f  andi        $v0, $v1, 0xF
    ctx->pc = 0x1277d4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)15);
    // 0x1277d8: 0x42303  sra         $a0, $a0, 12
    ctx->pc = 0x1277d8u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 12));
    // 0x1277dc: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1277dcu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1277e0: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x1277e0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x1277e4: 0x4b6021  addu        $t4, $v0, $t3
    ctx->pc = 0x1277e4u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 11)));
    // 0x1277e8: 0x891021  addu        $v0, $a0, $t1
    ctx->pc = 0x1277e8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 9)));
    // 0x1277ec: 0x28838000  slti        $v1, $a0, -0x8000
    ctx->pc = 0x1277ecu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4294934528) ? 1 : 0);
    // 0x1277f0: 0x102102b  sltu        $v0, $t0, $v0
    ctx->pc = 0x1277f0u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x1277f4: 0x324282a  slt         $a1, $t9, $a0
    ctx->pc = 0x1277f4u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 25) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x1277f8: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1277F8u;
    {
        const bool branch_taken_0x1277f8 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1277FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1277F8u;
            // 0x1277fc: 0x38630000  xori        $v1, $v1, 0x0 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x1277f8) {
            ctx->pc = 0x12780Cu;
            goto label_12780c;
        }
    }
    ctx->pc = 0x127800u;
    // 0x127800: 0x325200b  movn        $a0, $t9, $a1
    ctx->pc = 0x127800u;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 25));
    // 0x127804: 0x24028000  addiu       $v0, $zero, -0x8000
    ctx->pc = 0x127804u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294934528));
    // 0x127808: 0x43200b  movn        $a0, $v0, $v1
    ctx->pc = 0x127808u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 2));
label_12780c:
    // 0x12780c: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x12780cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127810: 0x8d830000  lw          $v1, 0x0($t4)
    ctx->pc = 0x127810u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x127814: 0x2251018  mult        $v0, $s1, $a1
    ctx->pc = 0x127814u;
    { int64_t result = (int64_t)GPR_S32(ctx, 17) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x127818: 0xa4c50000  sh          $a1, 0x0($a2)
    ctx->pc = 0x127818u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x12781c: 0x6f2018  mult        $a0, $v1, $t7
    ctx->pc = 0x12781cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 15); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x127820: 0xa0702d  daddu       $t6, $a1, $zero
    ctx->pc = 0x127820u;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127824: 0x24c60002  addiu       $a2, $a2, 0x2
    ctx->pc = 0x127824u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
    // 0x127828: 0x581021  addu        $v0, $v0, $t8
    ctx->pc = 0x127828u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 24)));
    // 0x12782c: 0x21303  sra         $v0, $v0, 12
    ctx->pc = 0x12782cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 12));
    // 0x127830: 0x442021  addu        $a0, $v0, $a0
    ctx->pc = 0x127830u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x127834: 0x891821  addu        $v1, $a0, $t1
    ctx->pc = 0x127834u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 9)));
    // 0x127838: 0x28828000  slti        $v0, $a0, -0x8000
    ctx->pc = 0x127838u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 4) < (int64_t)(int32_t)4294934528) ? 1 : 0);
    // 0x12783c: 0x103182b  sltu        $v1, $t0, $v1
    ctx->pc = 0x12783cu;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 8) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x127840: 0x324282a  slt         $a1, $t9, $a0
    ctx->pc = 0x127840u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 25) < (int64_t)GPR_S64(ctx, 4)) ? 1 : 0);
    // 0x127844: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x127844u;
    {
        const bool branch_taken_0x127844 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x127848u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127844u;
            // 0x127848: 0x384c0000  xori        $t4, $v0, 0x0 (Delay Slot)
        SET_GPR_U64(ctx, 12, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x127844) {
            ctx->pc = 0x127858u;
            goto label_127858;
        }
    }
    ctx->pc = 0x12784Cu;
    // 0x12784c: 0x325200b  movn        $a0, $t9, $a1
    ctx->pc = 0x12784cu;
    if (GPR_U64(ctx, 5) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 25));
    // 0x127850: 0x24028000  addiu       $v0, $zero, -0x8000
    ctx->pc = 0x127850u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294934528));
    // 0x127854: 0x4c200b  movn        $a0, $v0, $t4
    ctx->pc = 0x127854u;
    if (GPR_U64(ctx, 12) != 0) SET_GPR_VEC(ctx, 4, GPR_VEC(ctx, 2));
label_127858:
    // 0x127858: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x127858u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12785c: 0x24e7fffe  addiu       $a3, $a3, -0x2
    ctx->pc = 0x12785cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4294967294));
    // 0x127860: 0xa4c50000  sh          $a1, 0x0($a2)
    ctx->pc = 0x127860u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x127864: 0x4e1ffd0  bgez        $a3, . + 4 + (-0x30 << 2)
    ctx->pc = 0x127864u;
    {
        const bool branch_taken_0x127864 = (GPR_S64(ctx, 7) >= 0);
        ctx->pc = 0x127868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127864u;
            // 0x127868: 0x24c60002  addiu       $a2, $a2, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127864) {
            ctx->pc = 0x1277A8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1277a8;
        }
    }
    ctx->pc = 0x12786Cu;
    // 0x12786c: 0x254a0001  addiu       $t2, $t2, 0x1
    ctx->pc = 0x12786cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 10), 1));
    // 0x127870: 0x153102a  slt         $v0, $t2, $s3
    ctx->pc = 0x127870u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 10) < (int64_t)GPR_S64(ctx, 19)) ? 1 : 0);
    // 0x127874: 0x5440ffb4  bnel        $v0, $zero, . + 4 + (-0x4C << 2)
    ctx->pc = 0x127874u;
    {
        const bool branch_taken_0x127874 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x127874) {
            ctx->pc = 0x127878u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x127874u;
            // 0x127878: 0x95a30000  lhu         $v1, 0x0($t5) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 13), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x127748u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_127748;
        }
    }
    ctx->pc = 0x12787Cu;
label_12787c:
    // 0x12787c: 0xa68e0002  sh          $t6, 0x2($s4)
    ctx->pc = 0x12787cu;
    WRITE16(ADD32(GPR_U32(ctx, 20), 2), (uint16_t)GPR_U32(ctx, 14));
    // 0x127880: 0x260102d  daddu       $v0, $s3, $zero
    ctx->pc = 0x127880u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127884: 0xa6850000  sh          $a1, 0x0($s4)
    ctx->pc = 0x127884u;
    WRITE16(ADD32(GPR_U32(ctx, 20), 0), (uint16_t)GPR_U32(ctx, 5));
label_127888:
    // 0x127888: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x127888u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12788c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12788cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x127890: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x127890u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x127894: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x127894u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x127898: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x127898u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12789c: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x12789cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1278a0: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x1278a0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1278a4: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x1278a4u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1278a8: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x1278a8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1278ac: 0x3e00008  jr          $ra
    ctx->pc = 0x1278ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1278B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1278ACu;
            // 0x1278b0: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x127748u: goto label_127748;
            case 0x1277A8u: goto label_1277a8;
            case 0x12780Cu: goto label_12780c;
            case 0x127858u: goto label_127858;
            case 0x12787Cu: goto label_12787c;
            case 0x127888u: goto label_127888;
            case 0x127948u: goto label_127948;
            case 0x127A18u: goto label_127a18;
            case 0x127A78u: goto label_127a78;
            case 0x127AC0u: goto label_127ac0;
            case 0x127AD0u: goto label_127ad0;
            case 0x127B10u: goto label_127b10;
            case 0x127B78u: goto label_127b78;
            case 0x127BC0u: goto label_127bc0;
            case 0x127BD0u: goto label_127bd0;
            case 0x127C0Cu: goto label_127c0c;
            case 0x127C34u: goto label_127c34;
            case 0x127C50u: goto label_127c50;
            case 0x127D08u: goto label_127d08;
            case 0x127DD8u: goto label_127dd8;
            case 0x127E5Cu: goto label_127e5c;
            case 0x127EB0u: goto label_127eb0;
            case 0x127F1Cu: goto label_127f1c;
            case 0x127F48u: goto label_127f48;
            case 0x127F80u: goto label_127f80;
            case 0x127F9Cu: goto label_127f9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1278B4u;
    // 0x1278b4: 0x0  nop
    ctx->pc = 0x1278b4u;
    // NOP
    // 0x1278b8: 0x517c2  srl         $v0, $a1, 31
    ctx->pc = 0x1278b8u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 5), 31));
    // 0x1278bc: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x1278bcu;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x1278c0: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x1278c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x1278c4: 0xafa90008  sw          $t1, 0x8($sp)
    ctx->pc = 0x1278c4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 9));
    // 0x1278c8: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x1278c8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x1278cc: 0x87a30078  lh          $v1, 0x78($sp)
    ctx->pc = 0x1278ccu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x1278d0: 0xafa20014  sw          $v0, 0x14($sp)
    ctx->pc = 0x1278d0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 2));
    // 0x1278d4: 0xc0482d  daddu       $t1, $a2, $zero
    ctx->pc = 0x1278d4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1278d8: 0x87a20080  lh          $v0, 0x80($sp)
    ctx->pc = 0x1278d8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1278dc: 0xa5400  sll         $t2, $t2, 16
    ctx->pc = 0x1278dcu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 16));
    // 0x1278e0: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x1278e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1278e4: 0xb5c00  sll         $t3, $t3, 16
    ctx->pc = 0x1278e4u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 16));
    // 0x1278e8: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x1278e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x1278ec: 0xa9c03  sra         $s3, $t2, 16
    ctx->pc = 0x1278ecu;
    SET_GPR_S32(ctx, 19, SRA32(GPR_S32(ctx, 10), 16));
    // 0x1278f0: 0xffb70058  sd          $s7, 0x58($sp)
    ctx->pc = 0x1278f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 23));
    // 0x1278f4: 0xb82d  daddu       $s7, $zero, $zero
    ctx->pc = 0x1278f4u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1278f8: 0xafa50000  sw          $a1, 0x0($sp)
    ctx->pc = 0x1278f8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 5));
    // 0x1278fc: 0xb9403  sra         $s2, $t3, 16
    ctx->pc = 0x1278fcu;
    SET_GPR_S32(ctx, 18, SRA32(GPR_S32(ctx, 11), 16));
    // 0x127900: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x127900u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x127904: 0x80782d  daddu       $t7, $a0, $zero
    ctx->pc = 0x127904u;
    SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127908: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x127908u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x12790c: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x12790cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x127910: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x127910u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x127914: 0xffb60050  sd          $s6, 0x50($sp)
    ctx->pc = 0x127914u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 22));
    // 0x127918: 0xffbe0060  sd          $fp, 0x60($sp)
    ctx->pc = 0x127918u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 30));
    // 0x12791c: 0xafa70004  sw          $a3, 0x4($sp)
    ctx->pc = 0x12791cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 7));
    // 0x127920: 0xafa20010  sw          $v0, 0x10($sp)
    ctx->pc = 0x127920u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x127924: 0xafa3000c  sw          $v1, 0xC($sp)
    ctx->pc = 0x127924u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 3));
    // 0x127928: 0x8fa50008  lw          $a1, 0x8($sp)
    ctx->pc = 0x127928u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12792c: 0x8fa60014  lw          $a2, 0x14($sp)
    ctx->pc = 0x12792cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x127930: 0x84f80000  lh          $t8, 0x0($a3)
    ctx->pc = 0x127930u;
    SET_GPR_S32(ctx, 24, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x127934: 0x84ec0002  lh          $t4, 0x2($a3)
    ctx->pc = 0x127934u;
    SET_GPR_S32(ctx, 12, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x127938: 0x84b90000  lh          $t9, 0x0($a1)
    ctx->pc = 0x127938u;
    SET_GPR_S32(ctx, 25, (int16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x12793c: 0x18c000bd  blez        $a2, . + 4 + (0xBD << 2)
    ctx->pc = 0x12793Cu;
    {
        const bool branch_taken_0x12793c = (GPR_S64(ctx, 6) <= 0);
        ctx->pc = 0x127940u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12793Cu;
            // 0x127940: 0x84b10002  lh          $s1, 0x2($a1) (Delay Slot)
        SET_GPR_S32(ctx, 17, (int16_t)READ16(ADD32(GPR_U32(ctx, 5), 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12793c) {
            ctx->pc = 0x127C34u;
            goto label_127c34;
        }
    }
    ctx->pc = 0x127944u;
    // 0x127944: 0x0  nop
    ctx->pc = 0x127944u;
    // NOP
label_127948:
    // 0x127948: 0x95e30000  lhu         $v1, 0x0($t7)
    ctx->pc = 0x127948u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 15), 0)));
    // 0x12794c: 0x2405ff00  addiu       $a1, $zero, -0x100
    ctx->pc = 0x12794cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x127950: 0x91e40001  lbu         $a0, 0x1($t7)
    ctx->pc = 0x127950u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 15), 1)));
    // 0x127954: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x127954u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x127958: 0x651824  and         $v1, $v1, $a1
    ctx->pc = 0x127958u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 5));
    // 0x12795c: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x12795cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x127960: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x127960u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x127964: 0x42c03  sra         $a1, $a0, 16
    ctx->pc = 0x127964u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 4), 16));
    // 0x127968: 0x30a38000  andi        $v1, $a1, 0x8000
    ctx->pc = 0x127968u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)32768);
    // 0x12796c: 0x146000b8  bnez        $v1, . + 4 + (0xB8 << 2)
    ctx->pc = 0x12796Cu;
    {
        const bool branch_taken_0x12796c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x127970u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12796Cu;
            // 0x127970: 0x171040  sll         $v0, $s7, 1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 23), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12796c) {
            ctx->pc = 0x127C50u;
            goto label_127c50;
        }
    }
    ctx->pc = 0x127974u;
    // 0x127974: 0x8fa60070  lw          $a2, 0x70($sp)
    ctx->pc = 0x127974u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x127978: 0x94c30000  lhu         $v1, 0x0($a2)
    ctx->pc = 0x127978u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x12797c: 0x8fa60010  lw          $a2, 0x10($sp)
    ctx->pc = 0x12797cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x127980: 0xc00013  mtlo        $a2
    ctx->pc = 0x127980u;
    ctx->lo = GPR_U64(ctx, 6);
    // 0x127984: 0x8fa6000c  lw          $a2, 0xC($sp)
    ctx->pc = 0x127984u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x127988: 0x70662000  madd        $a0, $v1, $a2
    ctx->pc = 0x127988u;
    { uint64_t acc = Ps2HiLoToU64(ctx->hi, ctx->lo); int64_t prod = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 6); int64_t result = acc + prod; ctx->lo = Ps2SignExt32ToU64((uint32_t)result); ctx->hi = Ps2SignExt32ToU64((uint32_t)(result >> 32)); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x12798c: 0xa31826  xor         $v1, $a1, $v1
    ctx->pc = 0x12798cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) ^ GPR_U64(ctx, 3));
    // 0x127990: 0x30631fff  andi        $v1, $v1, 0x1FFF
    ctx->pc = 0x127990u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)8191);
    // 0x127994: 0x2405ff00  addiu       $a1, $zero, -0x100
    ctx->pc = 0x127994u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x127998: 0x24750001  addiu       $s5, $v1, 0x1
    ctx->pc = 0x127998u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x12799c: 0x8fa30070  lw          $v1, 0x70($sp)
    ctx->pc = 0x12799cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1279a0: 0x30867fff  andi        $a2, $a0, 0x7FFF
    ctx->pc = 0x1279a0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)32767);
    // 0x1279a4: 0xa4660000  sh          $a2, 0x0($v1)
    ctx->pc = 0x1279a4u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 6));
    // 0x1279a8: 0x95e30012  lhu         $v1, 0x12($t7)
    ctx->pc = 0x1279a8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 15), 18)));
    // 0x1279ac: 0x91e40013  lbu         $a0, 0x13($t7)
    ctx->pc = 0x1279acu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 15), 19)));
    // 0x1279b0: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x1279b0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x1279b4: 0x651824  and         $v1, $v1, $a1
    ctx->pc = 0x1279b4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 5));
    // 0x1279b8: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x1279b8u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x1279bc: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x1279bcu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x1279c0: 0x42c03  sra         $a1, $a0, 16
    ctx->pc = 0x1279c0u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 4), 16));
    // 0x1279c4: 0x30a38000  andi        $v1, $a1, 0x8000
    ctx->pc = 0x1279c4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)32768);
    // 0x1279c8: 0x146000a1  bnez        $v1, . + 4 + (0xA1 << 2)
    ctx->pc = 0x1279C8u;
    {
        const bool branch_taken_0x1279c8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1279CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1279C8u;
            // 0x1279cc: 0x8fa30010  lw          $v1, 0x10($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1279c8) {
            ctx->pc = 0x127C50u;
            goto label_127c50;
        }
    }
    ctx->pc = 0x1279D0u;
    // 0x1279d0: 0x3c040024  lui         $a0, 0x24
    ctx->pc = 0x1279d0u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)36 << 16));
    // 0x1279d4: 0x249e9be8  addiu       $fp, $a0, -0x6418
    ctx->pc = 0x1279d4u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 4), 4294941672));
    // 0x1279d8: 0x25ef0002  addiu       $t7, $t7, 0x2
    ctx->pc = 0x1279d8u;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 15), 2));
    // 0x1279dc: 0x600013  mtlo        $v1
    ctx->pc = 0x1279dcu;
    ctx->lo = GPR_U64(ctx, 3);
    // 0x1279e0: 0x8fa3000c  lw          $v1, 0xC($sp)
    ctx->pc = 0x1279e0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x1279e4: 0x34108000  ori         $s0, $zero, 0x8000
    ctx->pc = 0x1279e4u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x1279e8: 0x340bffff  ori         $t3, $zero, 0xFFFF
    ctx->pc = 0x1279e8u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x1279ec: 0x70661000  madd        $v0, $v1, $a2
    ctx->pc = 0x1279ecu;
    { uint64_t acc = Ps2HiLoToU64(ctx->hi, ctx->lo); int64_t prod = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 6); int64_t result = acc + prod; ctx->lo = Ps2SignExt32ToU64((uint32_t)result); ctx->hi = Ps2SignExt32ToU64((uint32_t)(result >> 32)); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x1279f0: 0xa61826  xor         $v1, $a1, $a2
    ctx->pc = 0x1279f0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) ^ GPR_U64(ctx, 6));
    // 0x1279f4: 0x8fa50070  lw          $a1, 0x70($sp)
    ctx->pc = 0x1279f4u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1279f8: 0x30631fff  andi        $v1, $v1, 0x1FFF
    ctx->pc = 0x1279f8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)8191);
    // 0x1279fc: 0x24740001  addiu       $s4, $v1, 0x1
    ctx->pc = 0x1279fcu;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x127a00: 0x240d7fff  addiu       $t5, $zero, 0x7FFF
    ctx->pc = 0x127a00u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 0), 32767));
    // 0x127a04: 0x240a000a  addiu       $t2, $zero, 0xA
    ctx->pc = 0x127a04u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x127a08: 0x2416001e  addiu       $s6, $zero, 0x1E
    ctx->pc = 0x127a08u;
    SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
    // 0x127a0c: 0x30427fff  andi        $v0, $v0, 0x7FFF
    ctx->pc = 0x127a0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32767);
    // 0x127a10: 0xa4a20000  sh          $v0, 0x0($a1)
    ctx->pc = 0x127a10u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127a14: 0x0  nop
    ctx->pc = 0x127a14u;
    // NOP
label_127a18:
    // 0x127a18: 0x91e20000  lbu         $v0, 0x0($t7)
    ctx->pc = 0x127a18u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 15), 0)));
    // 0x127a1c: 0x24c3018  mult        $a2, $s2, $t4
    ctx->pc = 0x127a1cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 12); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 6, (int32_t)result); }
    // 0x127a20: 0x72781818  mult1       $v1, $s3, $t8
    ctx->pc = 0x127a20u;
    { int64_t result = (int64_t)GPR_S32(ctx, 19) * (int64_t)GPR_S32(ctx, 24); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x127a24: 0x91e40012  lbu         $a0, 0x12($t7)
    ctx->pc = 0x127a24u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 15), 18)));
    // 0x127a28: 0x21600  sll         $v0, $v0, 24
    ctx->pc = 0x127a28u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 24));
    // 0x127a2c: 0x25ef0001  addiu       $t7, $t7, 0x1
    ctx->pc = 0x127a2cu;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 15), 1));
    // 0x127a30: 0x22f03  sra         $a1, $v0, 28
    ctx->pc = 0x127a30u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 2), 28));
    // 0x127a34: 0x27603  sra         $t6, $v0, 24
    ctx->pc = 0x127a34u;
    SET_GPR_S32(ctx, 14, SRA32(GPR_S32(ctx, 2), 24));
    // 0x127a38: 0xb52818  mult        $a1, $a1, $s5
    ctx->pc = 0x127a38u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 21); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x127a3c: 0x42600  sll         $a0, $a0, 24
    ctx->pc = 0x127a3cu;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 24));
    // 0x127a40: 0x661821  addu        $v1, $v1, $a2
    ctx->pc = 0x127a40u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x127a44: 0x46703  sra         $t4, $a0, 28
    ctx->pc = 0x127a44u;
    SET_GPR_S32(ctx, 12, SRA32(GPR_S32(ctx, 4), 28));
    // 0x127a48: 0x31b03  sra         $v1, $v1, 12
    ctx->pc = 0x127a48u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 12));
    // 0x127a4c: 0x653021  addu        $a2, $v1, $a1
    ctx->pc = 0x127a4cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x127a50: 0xd01021  addu        $v0, $a2, $s0
    ctx->pc = 0x127a50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 16)));
    // 0x127a54: 0x162102b  sltu        $v0, $t3, $v0
    ctx->pc = 0x127a54u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x127a58: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x127A58u;
    {
        const bool branch_taken_0x127a58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x127A5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127A58u;
            // 0x127a5c: 0x43e03  sra         $a3, $a0, 24 (Delay Slot)
        SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 4), 24));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127a58) {
            ctx->pc = 0x127A78u;
            goto label_127a78;
        }
    }
    ctx->pc = 0x127A60u;
    // 0x127a60: 0x28c28000  slti        $v0, $a2, -0x8000
    ctx->pc = 0x127a60u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)4294934528) ? 1 : 0);
    // 0x127a64: 0x1a6182a  slt         $v1, $t5, $a2
    ctx->pc = 0x127a64u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 13) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x127a68: 0x1a3300b  movn        $a2, $t5, $v1
    ctx->pc = 0x127a68u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 13));
    // 0x127a6c: 0x24038000  addiu       $v1, $zero, -0x8000
    ctx->pc = 0x127a6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294934528));
    // 0x127a70: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x127a70u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x127a74: 0x62300b  movn        $a2, $v1, $v0
    ctx->pc = 0x127a74u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 3));
label_127a78:
    // 0x127a78: 0x2511018  mult        $v0, $s2, $s1
    ctx->pc = 0x127a78u;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 17); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x127a7c: 0x72791818  mult1       $v1, $s3, $t9
    ctx->pc = 0x127a7cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 19) * (int64_t)GPR_S32(ctx, 25); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x127a80: 0x1942018  mult        $a0, $t4, $s4
    ctx->pc = 0x127a80u;
    { int64_t result = (int64_t)GPR_S32(ctx, 12) * (int64_t)GPR_S32(ctx, 20); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x127a84: 0x300602d  daddu       $t4, $t8, $zero
    ctx->pc = 0x127a84u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 24) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127a88: 0xc0c02d  daddu       $t8, $a2, $zero
    ctx->pc = 0x127a88u;
    SET_GPR_U64(ctx, 24, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127a8c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x127a8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x127a90: 0x31b03  sra         $v1, $v1, 12
    ctx->pc = 0x127a90u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 12));
    // 0x127a94: 0x643021  addu        $a2, $v1, $a0
    ctx->pc = 0x127a94u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x127a98: 0xd01021  addu        $v0, $a2, $s0
    ctx->pc = 0x127a98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 16)));
    // 0x127a9c: 0x162102b  sltu        $v0, $t3, $v0
    ctx->pc = 0x127a9cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x127aa0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x127AA0u;
    {
        const bool branch_taken_0x127aa0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x127AA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127AA0u;
            // 0x127aa4: 0x320882d  daddu       $s1, $t9, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 25) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127aa0) {
            ctx->pc = 0x127AC0u;
            goto label_127ac0;
        }
    }
    ctx->pc = 0x127AA8u;
    // 0x127aa8: 0x28c28000  slti        $v0, $a2, -0x8000
    ctx->pc = 0x127aa8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)4294934528) ? 1 : 0);
    // 0x127aac: 0x1a6182a  slt         $v1, $t5, $a2
    ctx->pc = 0x127aacu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 13) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x127ab0: 0x1a3300b  movn        $a2, $t5, $v1
    ctx->pc = 0x127ab0u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 13));
    // 0x127ab4: 0x24038000  addiu       $v1, $zero, -0x8000
    ctx->pc = 0x127ab4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294934528));
    // 0x127ab8: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x127ab8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x127abc: 0x62300b  movn        $a2, $v1, $v0
    ctx->pc = 0x127abcu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 3));
label_127ac0:
    // 0x127ac0: 0xc0c82d  daddu       $t9, $a2, $zero
    ctx->pc = 0x127ac0u;
    SET_GPR_U64(ctx, 25, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127ac4: 0x3191821  addu        $v1, $t8, $t9
    ctx->pc = 0x127ac4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 24), GPR_U32(ctx, 25)));
    // 0x127ac8: 0x51400001  beql        $t2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x127AC8u;
    {
        const bool branch_taken_0x127ac8 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        if (branch_taken_0x127ac8) {
            ctx->pc = 0x127ACCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x127AC8u;
            // 0x127acc: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x127AD0u;
            goto label_127ad0;
        }
    }
    ctx->pc = 0x127AD0u;
label_127ad0:
    // 0x127ad0: 0x310c0  sll         $v0, $v1, 3
    ctx->pc = 0x127ad0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x127ad4: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x127ad4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x127ad8: 0x4a001a  div         $zero, $v0, $t2
    ctx->pc = 0x127ad8u;
    { int32_t divisor = GPR_S32(ctx, 10);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x127adc: 0x1012  mflo        $v0
    ctx->pc = 0x127adcu;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x127ae0: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x127ae0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127ae4: 0xd01821  addu        $v1, $a2, $s0
    ctx->pc = 0x127ae4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 16)));
    // 0x127ae8: 0x163182b  sltu        $v1, $t3, $v1
    ctx->pc = 0x127ae8u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x127aec: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x127AECu;
    {
        const bool branch_taken_0x127aec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x127AF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127AECu;
            // 0x127af0: 0x31c2000f  andi        $v0, $t6, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 14) & (uint64_t)(uint16_t)15);
        ctx->in_delay_slot = false;
        if (branch_taken_0x127aec) {
            ctx->pc = 0x127B10u;
            goto label_127b10;
        }
    }
    ctx->pc = 0x127AF4u;
    // 0x127af4: 0x28c28000  slti        $v0, $a2, -0x8000
    ctx->pc = 0x127af4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)4294934528) ? 1 : 0);
    // 0x127af8: 0x1a6182a  slt         $v1, $t5, $a2
    ctx->pc = 0x127af8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 13) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x127afc: 0x1a3300b  movn        $a2, $t5, $v1
    ctx->pc = 0x127afcu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 13));
    // 0x127b00: 0x24038000  addiu       $v1, $zero, -0x8000
    ctx->pc = 0x127b00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294934528));
    // 0x127b04: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x127b04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x127b08: 0x62300b  movn        $a2, $v1, $v0
    ctx->pc = 0x127b08u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 3));
    // 0x127b0c: 0x31c2000f  andi        $v0, $t6, 0xF
    ctx->pc = 0x127b0cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 14) & (uint64_t)(uint16_t)15);
label_127b10:
    // 0x127b10: 0x24c2818  mult        $a1, $s2, $t4
    ctx->pc = 0x127b10u;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 12); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x127b14: 0x72782018  mult1       $a0, $s3, $t8
    ctx->pc = 0x127b14u;
    { int64_t result = (int64_t)GPR_S32(ctx, 19) * (int64_t)GPR_S32(ctx, 24); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x127b18: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x127b18u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x127b1c: 0x5e1021  addu        $v0, $v0, $fp
    ctx->pc = 0x127b1cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 30)));
    // 0x127b20: 0xa5060000  sh          $a2, 0x0($t0)
    ctx->pc = 0x127b20u;
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 6));
    // 0x127b24: 0x8c4e0000  lw          $t6, 0x0($v0)
    ctx->pc = 0x127b24u;
    SET_GPR_S32(ctx, 14, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x127b28: 0x30e3000f  andi        $v1, $a3, 0xF
    ctx->pc = 0x127b28u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) & (uint64_t)(uint16_t)15);
    // 0x127b2c: 0xa5260000  sh          $a2, 0x0($t1)
    ctx->pc = 0x127b2cu;
    WRITE16(ADD32(GPR_U32(ctx, 9), 0), (uint16_t)GPR_U32(ctx, 6));
    // 0x127b30: 0x25290002  addiu       $t1, $t1, 0x2
    ctx->pc = 0x127b30u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 2));
    // 0x127b34: 0x852021  addu        $a0, $a0, $a1
    ctx->pc = 0x127b34u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x127b38: 0x1d52818  mult        $a1, $t6, $s5
    ctx->pc = 0x127b38u;
    { int64_t result = (int64_t)GPR_S32(ctx, 14) * (int64_t)GPR_S32(ctx, 21); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x127b3c: 0x42303  sra         $a0, $a0, 12
    ctx->pc = 0x127b3cu;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 12));
    // 0x127b40: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x127b40u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x127b44: 0x7e1821  addu        $v1, $v1, $fp
    ctx->pc = 0x127b44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 30)));
    // 0x127b48: 0x25080002  addiu       $t0, $t0, 0x2
    ctx->pc = 0x127b48u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 2));
    // 0x127b4c: 0x853021  addu        $a2, $a0, $a1
    ctx->pc = 0x127b4cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x127b50: 0xd01021  addu        $v0, $a2, $s0
    ctx->pc = 0x127b50u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 16)));
    // 0x127b54: 0x162102b  sltu        $v0, $t3, $v0
    ctx->pc = 0x127b54u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x127b58: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x127B58u;
    {
        const bool branch_taken_0x127b58 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x127B5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127B58u;
            // 0x127b5c: 0x8c670000  lw          $a3, 0x0($v1) (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127b58) {
            ctx->pc = 0x127B78u;
            goto label_127b78;
        }
    }
    ctx->pc = 0x127B60u;
    // 0x127b60: 0x28c28000  slti        $v0, $a2, -0x8000
    ctx->pc = 0x127b60u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)4294934528) ? 1 : 0);
    // 0x127b64: 0x1a6182a  slt         $v1, $t5, $a2
    ctx->pc = 0x127b64u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 13) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x127b68: 0x1a3300b  movn        $a2, $t5, $v1
    ctx->pc = 0x127b68u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 13));
    // 0x127b6c: 0x24038000  addiu       $v1, $zero, -0x8000
    ctx->pc = 0x127b6cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294934528));
    // 0x127b70: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x127b70u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x127b74: 0x62300b  movn        $a2, $v1, $v0
    ctx->pc = 0x127b74u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 3));
label_127b78:
    // 0x127b78: 0x2511018  mult        $v0, $s2, $s1
    ctx->pc = 0x127b78u;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 17); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x127b7c: 0x72791818  mult1       $v1, $s3, $t9
    ctx->pc = 0x127b7cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 19) * (int64_t)GPR_S32(ctx, 25); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x127b80: 0xf42018  mult        $a0, $a3, $s4
    ctx->pc = 0x127b80u;
    { int64_t result = (int64_t)GPR_S32(ctx, 7) * (int64_t)GPR_S32(ctx, 20); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x127b84: 0x300602d  daddu       $t4, $t8, $zero
    ctx->pc = 0x127b84u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 24) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127b88: 0xc0c02d  daddu       $t8, $a2, $zero
    ctx->pc = 0x127b88u;
    SET_GPR_U64(ctx, 24, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127b8c: 0x621821  addu        $v1, $v1, $v0
    ctx->pc = 0x127b8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x127b90: 0x31b03  sra         $v1, $v1, 12
    ctx->pc = 0x127b90u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 12));
    // 0x127b94: 0x643021  addu        $a2, $v1, $a0
    ctx->pc = 0x127b94u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x127b98: 0xd01021  addu        $v0, $a2, $s0
    ctx->pc = 0x127b98u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 16)));
    // 0x127b9c: 0x162102b  sltu        $v0, $t3, $v0
    ctx->pc = 0x127b9cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x127ba0: 0x10400007  beqz        $v0, . + 4 + (0x7 << 2)
    ctx->pc = 0x127BA0u;
    {
        const bool branch_taken_0x127ba0 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x127BA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127BA0u;
            // 0x127ba4: 0x320882d  daddu       $s1, $t9, $zero (Delay Slot)
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 25) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127ba0) {
            ctx->pc = 0x127BC0u;
            goto label_127bc0;
        }
    }
    ctx->pc = 0x127BA8u;
    // 0x127ba8: 0x28c28000  slti        $v0, $a2, -0x8000
    ctx->pc = 0x127ba8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)4294934528) ? 1 : 0);
    // 0x127bac: 0x1a6182a  slt         $v1, $t5, $a2
    ctx->pc = 0x127bacu;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 13) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x127bb0: 0x1a3300b  movn        $a2, $t5, $v1
    ctx->pc = 0x127bb0u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 13));
    // 0x127bb4: 0x24038000  addiu       $v1, $zero, -0x8000
    ctx->pc = 0x127bb4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294934528));
    // 0x127bb8: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x127bb8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x127bbc: 0x62300b  movn        $a2, $v1, $v0
    ctx->pc = 0x127bbcu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 3));
label_127bc0:
    // 0x127bc0: 0xc0c82d  daddu       $t9, $a2, $zero
    ctx->pc = 0x127bc0u;
    SET_GPR_U64(ctx, 25, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127bc4: 0x3191821  addu        $v1, $t8, $t9
    ctx->pc = 0x127bc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 24), GPR_U32(ctx, 25)));
    // 0x127bc8: 0x51400001  beql        $t2, $zero, . + 4 + (0x1 << 2)
    ctx->pc = 0x127BC8u;
    {
        const bool branch_taken_0x127bc8 = (GPR_U64(ctx, 10) == GPR_U64(ctx, 0));
        if (branch_taken_0x127bc8) {
            ctx->pc = 0x127BCCu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x127BC8u;
            // 0x127bcc: 0x1cd  break       0, 7 (Delay Slot)
        runtime->handleBreak(rdram, ctx);
        ctx->in_delay_slot = false;
            ctx->pc = 0x127BD0u;
            goto label_127bd0;
        }
    }
    ctx->pc = 0x127BD0u;
label_127bd0:
    // 0x127bd0: 0x310c0  sll         $v0, $v1, 3
    ctx->pc = 0x127bd0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x127bd4: 0x431023  subu        $v0, $v0, $v1
    ctx->pc = 0x127bd4u;
    SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x127bd8: 0x4a001a  div         $zero, $v0, $t2
    ctx->pc = 0x127bd8u;
    { int32_t divisor = GPR_S32(ctx, 10);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x127bdc: 0x1012  mflo        $v0
    ctx->pc = 0x127bdcu;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x127be0: 0x40302d  daddu       $a2, $v0, $zero
    ctx->pc = 0x127be0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127be4: 0xd01821  addu        $v1, $a2, $s0
    ctx->pc = 0x127be4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 16)));
    // 0x127be8: 0x163182b  sltu        $v1, $t3, $v1
    ctx->pc = 0x127be8u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 11) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x127bec: 0x10600007  beqz        $v1, . + 4 + (0x7 << 2)
    ctx->pc = 0x127BECu;
    {
        const bool branch_taken_0x127bec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x127BF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127BECu;
            // 0x127bf0: 0x26d6fffe  addiu       $s6, $s6, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 22, (int32_t)ADD32(GPR_U32(ctx, 22), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127bec) {
            ctx->pc = 0x127C0Cu;
            goto label_127c0c;
        }
    }
    ctx->pc = 0x127BF4u;
    // 0x127bf4: 0x28c28000  slti        $v0, $a2, -0x8000
    ctx->pc = 0x127bf4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)(int32_t)4294934528) ? 1 : 0);
    // 0x127bf8: 0x1a6182a  slt         $v1, $t5, $a2
    ctx->pc = 0x127bf8u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 13) < (int64_t)GPR_S64(ctx, 6)) ? 1 : 0);
    // 0x127bfc: 0x1a3300b  movn        $a2, $t5, $v1
    ctx->pc = 0x127bfcu;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 13));
    // 0x127c00: 0x24038000  addiu       $v1, $zero, -0x8000
    ctx->pc = 0x127c00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294934528));
    // 0x127c04: 0x38420000  xori        $v0, $v0, 0x0
    ctx->pc = 0x127c04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
    // 0x127c08: 0x62300b  movn        $a2, $v1, $v0
    ctx->pc = 0x127c08u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 6, GPR_VEC(ctx, 3));
label_127c0c:
    // 0x127c0c: 0xa5060000  sh          $a2, 0x0($t0)
    ctx->pc = 0x127c0cu;
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 6));
    // 0x127c10: 0xa5260000  sh          $a2, 0x0($t1)
    ctx->pc = 0x127c10u;
    WRITE16(ADD32(GPR_U32(ctx, 9), 0), (uint16_t)GPR_U32(ctx, 6));
    // 0x127c14: 0x25290002  addiu       $t1, $t1, 0x2
    ctx->pc = 0x127c14u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 2));
    // 0x127c18: 0x6c1ff7f  bgez        $s6, . + 4 + (-0x81 << 2)
    ctx->pc = 0x127C18u;
    {
        const bool branch_taken_0x127c18 = (GPR_S64(ctx, 22) >= 0);
        ctx->pc = 0x127C1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127C18u;
            // 0x127c1c: 0x25080002  addiu       $t0, $t0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127c18) {
            ctx->pc = 0x127A18u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_127a18;
        }
    }
    ctx->pc = 0x127C20u;
    // 0x127c20: 0x8fa30014  lw          $v1, 0x14($sp)
    ctx->pc = 0x127c20u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x127c24: 0x26f70001  addiu       $s7, $s7, 0x1
    ctx->pc = 0x127c24u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 23), 1));
    // 0x127c28: 0x2e3102a  slt         $v0, $s7, $v1
    ctx->pc = 0x127c28u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 23) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x127c2c: 0x1440ff46  bnez        $v0, . + 4 + (-0xBA << 2)
    ctx->pc = 0x127C2Cu;
    {
        const bool branch_taken_0x127c2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x127C30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127C2Cu;
            // 0x127c30: 0x25ef0012  addiu       $t7, $t7, 0x12 (Delay Slot)
        SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 15), 18));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127c2c) {
            ctx->pc = 0x127948u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_127948;
        }
    }
    ctx->pc = 0x127C34u;
label_127c34:
    // 0x127c34: 0x8fa50004  lw          $a1, 0x4($sp)
    ctx->pc = 0x127c34u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x127c38: 0xa4ac0002  sh          $t4, 0x2($a1)
    ctx->pc = 0x127c38u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 2), (uint16_t)GPR_U32(ctx, 12));
    // 0x127c3c: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x127c3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x127c40: 0xa4b80000  sh          $t8, 0x0($a1)
    ctx->pc = 0x127c40u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 24));
    // 0x127c44: 0x8fa60008  lw          $a2, 0x8($sp)
    ctx->pc = 0x127c44u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x127c48: 0xa4d10002  sh          $s1, 0x2($a2)
    ctx->pc = 0x127c48u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 2), (uint16_t)GPR_U32(ctx, 17));
    // 0x127c4c: 0xa4d90000  sh          $t9, 0x0($a2)
    ctx->pc = 0x127c4cu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 25));
label_127c50:
    // 0x127c50: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x127c50u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x127c54: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x127c54u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x127c58: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x127c58u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x127c5c: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x127c5cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x127c60: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x127c60u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x127c64: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x127c64u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x127c68: 0xdfb60050  ld          $s6, 0x50($sp)
    ctx->pc = 0x127c68u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x127c6c: 0xdfb70058  ld          $s7, 0x58($sp)
    ctx->pc = 0x127c6cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x127c70: 0xdfbe0060  ld          $fp, 0x60($sp)
    ctx->pc = 0x127c70u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x127c74: 0x3e00008  jr          $ra
    ctx->pc = 0x127C74u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x127C78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127C74u;
            // 0x127c78: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x127748u: goto label_127748;
            case 0x1277A8u: goto label_1277a8;
            case 0x12780Cu: goto label_12780c;
            case 0x127858u: goto label_127858;
            case 0x12787Cu: goto label_12787c;
            case 0x127888u: goto label_127888;
            case 0x127948u: goto label_127948;
            case 0x127A18u: goto label_127a18;
            case 0x127A78u: goto label_127a78;
            case 0x127AC0u: goto label_127ac0;
            case 0x127AD0u: goto label_127ad0;
            case 0x127B10u: goto label_127b10;
            case 0x127B78u: goto label_127b78;
            case 0x127BC0u: goto label_127bc0;
            case 0x127BD0u: goto label_127bd0;
            case 0x127C0Cu: goto label_127c0c;
            case 0x127C34u: goto label_127c34;
            case 0x127C50u: goto label_127c50;
            case 0x127D08u: goto label_127d08;
            case 0x127DD8u: goto label_127dd8;
            case 0x127E5Cu: goto label_127e5c;
            case 0x127EB0u: goto label_127eb0;
            case 0x127F1Cu: goto label_127f1c;
            case 0x127F48u: goto label_127f48;
            case 0x127F80u: goto label_127f80;
            case 0x127F9Cu: goto label_127f9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x127C7Cu;
    // 0x127c7c: 0x0  nop
    ctx->pc = 0x127c7cu;
    // NOP
    // 0x127c80: 0x517c2  srl         $v0, $a1, 31
    ctx->pc = 0x127c80u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 5), 31));
    // 0x127c84: 0x27bdff90  addiu       $sp, $sp, -0x70
    ctx->pc = 0x127c84u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x127c88: 0xa21021  addu        $v0, $a1, $v0
    ctx->pc = 0x127c88u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x127c8c: 0x87a30078  lh          $v1, 0x78($sp)
    ctx->pc = 0x127c8cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 120)));
    // 0x127c90: 0x21043  sra         $v0, $v0, 1
    ctx->pc = 0x127c90u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x127c94: 0xffb20030  sd          $s2, 0x30($sp)
    ctx->pc = 0x127c94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x127c98: 0xafa20018  sw          $v0, 0x18($sp)
    ctx->pc = 0x127c98u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 2));
    // 0x127c9c: 0x80782d  daddu       $t7, $a0, $zero
    ctx->pc = 0x127c9cu;
    SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127ca0: 0x87a20080  lh          $v0, 0x80($sp)
    ctx->pc = 0x127ca0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x127ca4: 0xa5400  sll         $t2, $t2, 16
    ctx->pc = 0x127ca4u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 16));
    // 0x127ca8: 0xffb30038  sd          $s3, 0x38($sp)
    ctx->pc = 0x127ca8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
    // 0x127cac: 0xa9c03  sra         $s3, $t2, 16
    ctx->pc = 0x127cacu;
    SET_GPR_S32(ctx, 19, SRA32(GPR_S32(ctx, 10), 16));
    // 0x127cb0: 0xffb00020  sd          $s0, 0x20($sp)
    ctx->pc = 0x127cb0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x127cb4: 0xb5c00  sll         $t3, $t3, 16
    ctx->pc = 0x127cb4u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 16));
    // 0x127cb8: 0xffb10028  sd          $s1, 0x28($sp)
    ctx->pc = 0x127cb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
    // 0x127cbc: 0xc0c82d  daddu       $t9, $a2, $zero
    ctx->pc = 0x127cbcu;
    SET_GPR_U64(ctx, 25, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127cc0: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x127cc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x127cc4: 0xb9403  sra         $s2, $t3, 16
    ctx->pc = 0x127cc4u;
    SET_GPR_S32(ctx, 18, SRA32(GPR_S32(ctx, 11), 16));
    // 0x127cc8: 0xffb50048  sd          $s5, 0x48($sp)
    ctx->pc = 0x127cc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 21));
    // 0x127ccc: 0xffb60050  sd          $s6, 0x50($sp)
    ctx->pc = 0x127cccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 22));
    // 0x127cd0: 0xffb70058  sd          $s7, 0x58($sp)
    ctx->pc = 0x127cd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 23));
    // 0x127cd4: 0xffbe0060  sd          $fp, 0x60($sp)
    ctx->pc = 0x127cd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 30));
    // 0x127cd8: 0xafa50000  sw          $a1, 0x0($sp)
    ctx->pc = 0x127cd8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 5));
    // 0x127cdc: 0xafa70004  sw          $a3, 0x4($sp)
    ctx->pc = 0x127cdcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 7));
    // 0x127ce0: 0xafa90008  sw          $t1, 0x8($sp)
    ctx->pc = 0x127ce0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 9));
    // 0x127ce4: 0xafa20010  sw          $v0, 0x10($sp)
    ctx->pc = 0x127ce4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 2));
    // 0x127ce8: 0xafa00014  sw          $zero, 0x14($sp)
    ctx->pc = 0x127ce8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 0));
    // 0x127cec: 0xafa3000c  sw          $v1, 0xC($sp)
    ctx->pc = 0x127cecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 3));
    // 0x127cf0: 0x8fa40018  lw          $a0, 0x18($sp)
    ctx->pc = 0x127cf0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x127cf4: 0x84ed0000  lh          $t5, 0x0($a3)
    ctx->pc = 0x127cf4u;
    SET_GPR_S32(ctx, 13, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x127cf8: 0x84ea0002  lh          $t2, 0x2($a3)
    ctx->pc = 0x127cf8u;
    SET_GPR_S32(ctx, 10, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x127cfc: 0x852e0000  lh          $t6, 0x0($t1)
    ctx->pc = 0x127cfcu;
    SET_GPR_S32(ctx, 14, (int16_t)READ16(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x127d00: 0x1880009f  blez        $a0, . + 4 + (0x9F << 2)
    ctx->pc = 0x127D00u;
    {
        const bool branch_taken_0x127d00 = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x127D04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127D00u;
            // 0x127d04: 0x85300002  lh          $s0, 0x2($t1) (Delay Slot)
        SET_GPR_S32(ctx, 16, (int16_t)READ16(ADD32(GPR_U32(ctx, 9), 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127d00) {
            ctx->pc = 0x127F80u;
            goto label_127f80;
        }
    }
    ctx->pc = 0x127D08u;
label_127d08:
    // 0x127d08: 0x95e30000  lhu         $v1, 0x0($t7)
    ctx->pc = 0x127d08u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 15), 0)));
    // 0x127d0c: 0x2406ff00  addiu       $a2, $zero, -0x100
    ctx->pc = 0x127d0cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x127d10: 0x91e40001  lbu         $a0, 0x1($t7)
    ctx->pc = 0x127d10u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 15), 1)));
    // 0x127d14: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x127d14u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x127d18: 0x8fa50014  lw          $a1, 0x14($sp)
    ctx->pc = 0x127d18u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x127d1c: 0x661824  and         $v1, $v1, $a2
    ctx->pc = 0x127d1cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 6));
    // 0x127d20: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x127d20u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x127d24: 0x51040  sll         $v0, $a1, 1
    ctx->pc = 0x127d24u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 5), 1));
    // 0x127d28: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x127d28u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x127d2c: 0x42c03  sra         $a1, $a0, 16
    ctx->pc = 0x127d2cu;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 4), 16));
    // 0x127d30: 0x30a38000  andi        $v1, $a1, 0x8000
    ctx->pc = 0x127d30u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)32768);
    // 0x127d34: 0x14600099  bnez        $v1, . + 4 + (0x99 << 2)
    ctx->pc = 0x127D34u;
    {
        const bool branch_taken_0x127d34 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x127D38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127D34u;
            // 0x127d38: 0x8fa40014  lw          $a0, 0x14($sp) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127d34) {
            ctx->pc = 0x127F9Cu;
            goto label_127f9c;
        }
    }
    ctx->pc = 0x127D3Cu;
    // 0x127d3c: 0x8fa20070  lw          $v0, 0x70($sp)
    ctx->pc = 0x127d3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x127d40: 0x8fa60010  lw          $a2, 0x10($sp)
    ctx->pc = 0x127d40u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x127d44: 0x94430000  lhu         $v1, 0x0($v0)
    ctx->pc = 0x127d44u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x127d48: 0xc00013  mtlo        $a2
    ctx->pc = 0x127d48u;
    ctx->lo = GPR_U64(ctx, 6);
    // 0x127d4c: 0x8fa6000c  lw          $a2, 0xC($sp)
    ctx->pc = 0x127d4cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x127d50: 0x41040  sll         $v0, $a0, 1
    ctx->pc = 0x127d50u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 4), 1));
    // 0x127d54: 0x70662000  madd        $a0, $v1, $a2
    ctx->pc = 0x127d54u;
    { uint64_t acc = Ps2HiLoToU64(ctx->hi, ctx->lo); int64_t prod = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 6); int64_t result = acc + prod; ctx->lo = Ps2SignExt32ToU64((uint32_t)result); ctx->hi = Ps2SignExt32ToU64((uint32_t)(result >> 32)); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x127d58: 0xa31826  xor         $v1, $a1, $v1
    ctx->pc = 0x127d58u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) ^ GPR_U64(ctx, 3));
    // 0x127d5c: 0x30631fff  andi        $v1, $v1, 0x1FFF
    ctx->pc = 0x127d5cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)8191);
    // 0x127d60: 0x2405ff00  addiu       $a1, $zero, -0x100
    ctx->pc = 0x127d60u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x127d64: 0x24770001  addiu       $s7, $v1, 0x1
    ctx->pc = 0x127d64u;
    SET_GPR_S32(ctx, 23, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x127d68: 0x8fa30070  lw          $v1, 0x70($sp)
    ctx->pc = 0x127d68u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x127d6c: 0x30867fff  andi        $a2, $a0, 0x7FFF
    ctx->pc = 0x127d6cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) & (uint64_t)(uint16_t)32767);
    // 0x127d70: 0xa4660000  sh          $a2, 0x0($v1)
    ctx->pc = 0x127d70u;
    WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 6));
    // 0x127d74: 0x95e30012  lhu         $v1, 0x12($t7)
    ctx->pc = 0x127d74u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 15), 18)));
    // 0x127d78: 0x91e40013  lbu         $a0, 0x13($t7)
    ctx->pc = 0x127d78u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 15), 19)));
    // 0x127d7c: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x127d7cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x127d80: 0x651824  and         $v1, $v1, $a1
    ctx->pc = 0x127d80u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & GPR_U64(ctx, 5));
    // 0x127d84: 0x832025  or          $a0, $a0, $v1
    ctx->pc = 0x127d84u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x127d88: 0x42400  sll         $a0, $a0, 16
    ctx->pc = 0x127d88u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x127d8c: 0x42c03  sra         $a1, $a0, 16
    ctx->pc = 0x127d8cu;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 4), 16));
    // 0x127d90: 0x30a38000  andi        $v1, $a1, 0x8000
    ctx->pc = 0x127d90u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) & (uint64_t)(uint16_t)32768);
    // 0x127d94: 0x14600081  bnez        $v1, . + 4 + (0x81 << 2)
    ctx->pc = 0x127D94u;
    {
        const bool branch_taken_0x127d94 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x127D98u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127D94u;
            // 0x127d98: 0x8fa30010  lw          $v1, 0x10($sp) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127d94) {
            ctx->pc = 0x127F9Cu;
            goto label_127f9c;
        }
    }
    ctx->pc = 0x127D9Cu;
    // 0x127d9c: 0x25ef0002  addiu       $t7, $t7, 0x2
    ctx->pc = 0x127d9cu;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 15), 2));
    // 0x127da0: 0x8fa40070  lw          $a0, 0x70($sp)
    ctx->pc = 0x127da0u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x127da4: 0x34168000  ori         $s6, $zero, 0x8000
    ctx->pc = 0x127da4u;
    SET_GPR_U64(ctx, 22, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)32768);
    // 0x127da8: 0x600013  mtlo        $v1
    ctx->pc = 0x127da8u;
    ctx->lo = GPR_U64(ctx, 3);
    // 0x127dac: 0x8fa3000c  lw          $v1, 0xC($sp)
    ctx->pc = 0x127dacu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x127db0: 0x3415ffff  ori         $s5, $zero, 0xFFFF
    ctx->pc = 0x127db0u;
    SET_GPR_U64(ctx, 21, GPR_U64(ctx, 0) | (uint64_t)(uint16_t)65535);
    // 0x127db4: 0x24187fff  addiu       $t8, $zero, 0x7FFF
    ctx->pc = 0x127db4u;
    SET_GPR_S32(ctx, 24, (int32_t)ADD32(GPR_U32(ctx, 0), 32767));
    // 0x127db8: 0x70661000  madd        $v0, $v1, $a2
    ctx->pc = 0x127db8u;
    { uint64_t acc = Ps2HiLoToU64(ctx->hi, ctx->lo); int64_t prod = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 6); int64_t result = acc + prod; ctx->lo = Ps2SignExt32ToU64((uint32_t)result); ctx->hi = Ps2SignExt32ToU64((uint32_t)(result >> 32)); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x127dbc: 0xa61826  xor         $v1, $a1, $a2
    ctx->pc = 0x127dbcu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 5) ^ GPR_U64(ctx, 6));
    // 0x127dc0: 0x30631fff  andi        $v1, $v1, 0x1FFF
    ctx->pc = 0x127dc0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) & (uint64_t)(uint16_t)8191);
    // 0x127dc4: 0x241e001e  addiu       $fp, $zero, 0x1E
    ctx->pc = 0x127dc4u;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
    // 0x127dc8: 0x24740001  addiu       $s4, $v1, 0x1
    ctx->pc = 0x127dc8u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x127dcc: 0x30427fff  andi        $v0, $v0, 0x7FFF
    ctx->pc = 0x127dccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) & (uint64_t)(uint16_t)32767);
    // 0x127dd0: 0xa4820000  sh          $v0, 0x0($a0)
    ctx->pc = 0x127dd0u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127dd4: 0x0  nop
    ctx->pc = 0x127dd4u;
    // NOP
label_127dd8:
    // 0x127dd8: 0x91e30000  lbu         $v1, 0x0($t7)
    ctx->pc = 0x127dd8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 15), 0)));
    // 0x127ddc: 0x24a1018  mult        $v0, $s2, $t2
    ctx->pc = 0x127ddcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 10); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x127de0: 0x726d2018  mult1       $a0, $s3, $t5
    ctx->pc = 0x127de0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 19) * (int64_t)GPR_S32(ctx, 13); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x127de4: 0x91e60012  lbu         $a2, 0x12($t7)
    ctx->pc = 0x127de4u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 15), 18)));
    // 0x127de8: 0x31e00  sll         $v1, $v1, 24
    ctx->pc = 0x127de8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x127dec: 0x1a0502d  daddu       $t2, $t5, $zero
    ctx->pc = 0x127decu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 13) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127df0: 0x32f03  sra         $a1, $v1, 28
    ctx->pc = 0x127df0u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 3), 28));
    // 0x127df4: 0x63600  sll         $a2, $a2, 24
    ctx->pc = 0x127df4u;
    SET_GPR_S32(ctx, 6, (int32_t)SLL32(GPR_U32(ctx, 6), 24));
    // 0x127df8: 0xb72818  mult        $a1, $a1, $s7
    ctx->pc = 0x127df8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 23); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)result); }
    // 0x127dfc: 0x36603  sra         $t4, $v1, 24
    ctx->pc = 0x127dfcu;
    SET_GPR_S32(ctx, 12, SRA32(GPR_S32(ctx, 3), 24));
    // 0x127e00: 0x822021  addu        $a0, $a0, $v0
    ctx->pc = 0x127e00u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x127e04: 0x3182000f  andi        $v0, $t4, 0xF
    ctx->pc = 0x127e04u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 12) & (uint64_t)(uint16_t)15);
    // 0x127e08: 0x61f03  sra         $v1, $a2, 28
    ctx->pc = 0x127e08u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 6), 28));
    // 0x127e0c: 0x63603  sra         $a2, $a2, 24
    ctx->pc = 0x127e0cu;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 24));
    // 0x127e10: 0x42303  sra         $a0, $a0, 12
    ctx->pc = 0x127e10u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 12));
    // 0x127e14: 0x746018  mult        $t4, $v1, $s4
    ctx->pc = 0x127e14u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 20); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 12, (int32_t)result); }
    // 0x127e18: 0x3c030024  lui         $v1, 0x24
    ctx->pc = 0x127e18u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)36 << 16));
    // 0x127e1c: 0x852821  addu        $a1, $a0, $a1
    ctx->pc = 0x127e1cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x127e20: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x127e20u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x127e24: 0x24639be8  addiu       $v1, $v1, -0x6418
    ctx->pc = 0x127e24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294941672));
    // 0x127e28: 0x435821  addu        $t3, $v0, $v1
    ctx->pc = 0x127e28u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x127e2c: 0xb61021  addu        $v0, $a1, $s6
    ctx->pc = 0x127e2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 22)));
    // 0x127e30: 0x28a38000  slti        $v1, $a1, -0x8000
    ctx->pc = 0x127e30u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)4294934528) ? 1 : 0);
    // 0x127e34: 0x2a2102b  sltu        $v0, $s5, $v0
    ctx->pc = 0x127e34u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 21) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x127e38: 0x24a8818  mult        $s1, $s2, $t2
    ctx->pc = 0x127e38u;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 10); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 17, (int32_t)result); }
    // 0x127e3c: 0x25ef0001  addiu       $t7, $t7, 0x1
    ctx->pc = 0x127e3cu;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 15), 1));
    // 0x127e40: 0x305202a  slt         $a0, $t8, $a1
    ctx->pc = 0x127e40u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 24) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x127e44: 0x38630000  xori        $v1, $v1, 0x0
    ctx->pc = 0x127e44u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)0);
    // 0x127e48: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x127E48u;
    {
        const bool branch_taken_0x127e48 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x127E4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127E48u;
            // 0x127e4c: 0x30c9000f  andi        $t1, $a2, 0xF (Delay Slot)
        SET_GPR_U64(ctx, 9, GPR_U64(ctx, 6) & (uint64_t)(uint16_t)15);
        ctx->in_delay_slot = false;
        if (branch_taken_0x127e48) {
            ctx->pc = 0x127E5Cu;
            goto label_127e5c;
        }
    }
    ctx->pc = 0x127E50u;
    // 0x127e50: 0x304280b  movn        $a1, $t8, $a0
    ctx->pc = 0x127e50u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 24));
    // 0x127e54: 0x24028000  addiu       $v0, $zero, -0x8000
    ctx->pc = 0x127e54u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294934528));
    // 0x127e58: 0x43280b  movn        $a1, $v0, $v1
    ctx->pc = 0x127e58u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 2));
label_127e5c:
    // 0x127e5c: 0x2502018  mult        $a0, $s2, $s0
    ctx->pc = 0x127e5cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 16); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x127e60: 0x1c0802d  daddu       $s0, $t6, $zero
    ctx->pc = 0x127e60u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 14) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127e64: 0x726e1018  mult1       $v0, $s3, $t6
    ctx->pc = 0x127e64u;
    { int64_t result = (int64_t)GPR_S32(ctx, 19) * (int64_t)GPR_S32(ctx, 14); ctx->lo1 = (uint64_t)(int64_t)(int32_t)result; ctx->hi1 = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x127e68: 0xa0682d  daddu       $t5, $a1, $zero
    ctx->pc = 0x127e68u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127e6c: 0x26d1818  mult        $v1, $s3, $t5
    ctx->pc = 0x127e6cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 19) * (int64_t)GPR_S32(ctx, 13); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x127e70: 0x2503818  mult        $a3, $s2, $s0
    ctx->pc = 0x127e70u;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 16); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 7, (int32_t)result); }
    // 0x127e74: 0x1a0502d  daddu       $t2, $t5, $zero
    ctx->pc = 0x127e74u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 13) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127e78: 0x441021  addu        $v0, $v0, $a0
    ctx->pc = 0x127e78u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x127e7c: 0x21303  sra         $v0, $v0, 12
    ctx->pc = 0x127e7cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 12));
    // 0x127e80: 0x711821  addu        $v1, $v1, $s1
    ctx->pc = 0x127e80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x127e84: 0x4c2821  addu        $a1, $v0, $t4
    ctx->pc = 0x127e84u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 12)));
    // 0x127e88: 0x33303  sra         $a2, $v1, 12
    ctx->pc = 0x127e88u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 3), 12));
    // 0x127e8c: 0xb61821  addu        $v1, $a1, $s6
    ctx->pc = 0x127e8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 22)));
    // 0x127e90: 0x28a28000  slti        $v0, $a1, -0x8000
    ctx->pc = 0x127e90u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)4294934528) ? 1 : 0);
    // 0x127e94: 0x2a3182b  sltu        $v1, $s5, $v1
    ctx->pc = 0x127e94u;
    SET_GPR_U64(ctx, 3, ((uint64_t)GPR_U64(ctx, 21) < (uint64_t)GPR_U64(ctx, 3)) ? 1 : 0);
    // 0x127e98: 0x305202a  slt         $a0, $t8, $a1
    ctx->pc = 0x127e98u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 24) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x127e9c: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x127E9Cu;
    {
        const bool branch_taken_0x127e9c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x127EA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127E9Cu;
            // 0x127ea0: 0x384c0000  xori        $t4, $v0, 0x0 (Delay Slot)
        SET_GPR_U64(ctx, 12, GPR_U64(ctx, 2) ^ (uint64_t)(uint16_t)0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x127e9c) {
            ctx->pc = 0x127EB0u;
            goto label_127eb0;
        }
    }
    ctx->pc = 0x127EA4u;
    // 0x127ea4: 0x304280b  movn        $a1, $t8, $a0
    ctx->pc = 0x127ea4u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 24));
    // 0x127ea8: 0x24028000  addiu       $v0, $zero, -0x8000
    ctx->pc = 0x127ea8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294934528));
    // 0x127eac: 0x4c280b  movn        $a1, $v0, $t4
    ctx->pc = 0x127eacu;
    if (GPR_U64(ctx, 12) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 2));
label_127eb0:
    // 0x127eb0: 0x8d6c0000  lw          $t4, 0x0($t3)
    ctx->pc = 0x127eb0u;
    SET_GPR_S32(ctx, 12, (int32_t)READ32(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x127eb4: 0xa0702d  daddu       $t6, $a1, $zero
    ctx->pc = 0x127eb4u;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127eb8: 0x26e1018  mult        $v0, $s3, $t6
    ctx->pc = 0x127eb8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 19) * (int64_t)GPR_S32(ctx, 14); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x127ebc: 0x3c050024  lui         $a1, 0x24
    ctx->pc = 0x127ebcu;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)36 << 16));
    // 0x127ec0: 0x1972018  mult        $a0, $t4, $s7
    ctx->pc = 0x127ec0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 12) * (int64_t)GPR_S32(ctx, 23); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)result); }
    // 0x127ec4: 0x24a59be8  addiu       $a1, $a1, -0x6418
    ctx->pc = 0x127ec4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 4294941672));
    // 0x127ec8: 0x91880  sll         $v1, $t1, 2
    ctx->pc = 0x127ec8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 9), 2));
    // 0x127ecc: 0xa72d0000  sh          $t5, 0x0($t9)
    ctx->pc = 0x127eccu;
    WRITE16(ADD32(GPR_U32(ctx, 25), 0), (uint16_t)GPR_U32(ctx, 13));
    // 0x127ed0: 0x651821  addu        $v1, $v1, $a1
    ctx->pc = 0x127ed0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x127ed4: 0x1c0802d  daddu       $s0, $t6, $zero
    ctx->pc = 0x127ed4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 14) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127ed8: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x127ed8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x127edc: 0xa50e0000  sh          $t6, 0x0($t0)
    ctx->pc = 0x127edcu;
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 14));
    // 0x127ee0: 0xc42821  addu        $a1, $a2, $a0
    ctx->pc = 0x127ee0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x127ee4: 0x8c660000  lw          $a2, 0x0($v1)
    ctx->pc = 0x127ee4u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x127ee8: 0x26303  sra         $t4, $v0, 12
    ctx->pc = 0x127ee8u;
    SET_GPR_S32(ctx, 12, SRA32(GPR_S32(ctx, 2), 12));
    // 0x127eec: 0xb61021  addu        $v0, $a1, $s6
    ctx->pc = 0x127eecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 22)));
    // 0x127ef0: 0x28a38000  slti        $v1, $a1, -0x8000
    ctx->pc = 0x127ef0u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)4294934528) ? 1 : 0);
    // 0x127ef4: 0x2a2102b  sltu        $v0, $s5, $v0
    ctx->pc = 0x127ef4u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 21) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x127ef8: 0x27390002  addiu       $t9, $t9, 0x2
    ctx->pc = 0x127ef8u;
    SET_GPR_S32(ctx, 25, (int32_t)ADD32(GPR_U32(ctx, 25), 2));
    // 0x127efc: 0x25080002  addiu       $t0, $t0, 0x2
    ctx->pc = 0x127efcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 2));
    // 0x127f00: 0xd43018  mult        $a2, $a2, $s4
    ctx->pc = 0x127f00u;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 20); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 6, (int32_t)result); }
    // 0x127f04: 0x305202a  slt         $a0, $t8, $a1
    ctx->pc = 0x127f04u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 24) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x127f08: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x127F08u;
    {
        const bool branch_taken_0x127f08 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x127F0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127F08u;
            // 0x127f0c: 0x38630000  xori        $v1, $v1, 0x0 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x127f08) {
            ctx->pc = 0x127F1Cu;
            goto label_127f1c;
        }
    }
    ctx->pc = 0x127F10u;
    // 0x127f10: 0x304280b  movn        $a1, $t8, $a0
    ctx->pc = 0x127f10u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 24));
    // 0x127f14: 0x24028000  addiu       $v0, $zero, -0x8000
    ctx->pc = 0x127f14u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294934528));
    // 0x127f18: 0x43280b  movn        $a1, $v0, $v1
    ctx->pc = 0x127f18u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 2));
label_127f1c:
    // 0x127f1c: 0xa0682d  daddu       $t5, $a1, $zero
    ctx->pc = 0x127f1cu;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127f20: 0x1862821  addu        $a1, $t4, $a2
    ctx->pc = 0x127f20u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 12), GPR_U32(ctx, 6)));
    // 0x127f24: 0xb61021  addu        $v0, $a1, $s6
    ctx->pc = 0x127f24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 22)));
    // 0x127f28: 0x28a38000  slti        $v1, $a1, -0x8000
    ctx->pc = 0x127f28u;
    SET_GPR_U64(ctx, 3, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)4294934528) ? 1 : 0);
    // 0x127f2c: 0x2a2102b  sltu        $v0, $s5, $v0
    ctx->pc = 0x127f2cu;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 21) < (uint64_t)GPR_U64(ctx, 2)) ? 1 : 0);
    // 0x127f30: 0x305202a  slt         $a0, $t8, $a1
    ctx->pc = 0x127f30u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 24) < (int64_t)GPR_S64(ctx, 5)) ? 1 : 0);
    // 0x127f34: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x127F34u;
    {
        const bool branch_taken_0x127f34 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x127F38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127F34u;
            // 0x127f38: 0x38630000  xori        $v1, $v1, 0x0 (Delay Slot)
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) ^ (uint64_t)(uint16_t)0);
        ctx->in_delay_slot = false;
        if (branch_taken_0x127f34) {
            ctx->pc = 0x127F48u;
            goto label_127f48;
        }
    }
    ctx->pc = 0x127F3Cu;
    // 0x127f3c: 0x304280b  movn        $a1, $t8, $a0
    ctx->pc = 0x127f3cu;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 24));
    // 0x127f40: 0x24028000  addiu       $v0, $zero, -0x8000
    ctx->pc = 0x127f40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294934528));
    // 0x127f44: 0x43280b  movn        $a1, $v0, $v1
    ctx->pc = 0x127f44u;
    if (GPR_U64(ctx, 3) != 0) SET_GPR_VEC(ctx, 5, GPR_VEC(ctx, 2));
label_127f48:
    // 0x127f48: 0xa0702d  daddu       $t6, $a1, $zero
    ctx->pc = 0x127f48u;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127f4c: 0x27defffe  addiu       $fp, $fp, -0x2
    ctx->pc = 0x127f4cu;
    SET_GPR_S32(ctx, 30, (int32_t)ADD32(GPR_U32(ctx, 30), 4294967294));
    // 0x127f50: 0xa72d0000  sh          $t5, 0x0($t9)
    ctx->pc = 0x127f50u;
    WRITE16(ADD32(GPR_U32(ctx, 25), 0), (uint16_t)GPR_U32(ctx, 13));
    // 0x127f54: 0x27390002  addiu       $t9, $t9, 0x2
    ctx->pc = 0x127f54u;
    SET_GPR_S32(ctx, 25, (int32_t)ADD32(GPR_U32(ctx, 25), 2));
    // 0x127f58: 0xa50e0000  sh          $t6, 0x0($t0)
    ctx->pc = 0x127f58u;
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 14));
    // 0x127f5c: 0x7c1ff9e  bgez        $fp, . + 4 + (-0x62 << 2)
    ctx->pc = 0x127F5Cu;
    {
        const bool branch_taken_0x127f5c = (GPR_S64(ctx, 30) >= 0);
        ctx->pc = 0x127F60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127F5Cu;
            // 0x127f60: 0x25080002  addiu       $t0, $t0, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127f5c) {
            ctx->pc = 0x127DD8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_127dd8;
        }
    }
    ctx->pc = 0x127F64u;
    // 0x127f64: 0x8fa60014  lw          $a2, 0x14($sp)
    ctx->pc = 0x127f64u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 20)));
    // 0x127f68: 0x25ef0012  addiu       $t7, $t7, 0x12
    ctx->pc = 0x127f68u;
    SET_GPR_S32(ctx, 15, (int32_t)ADD32(GPR_U32(ctx, 15), 18));
    // 0x127f6c: 0x8fa30018  lw          $v1, 0x18($sp)
    ctx->pc = 0x127f6cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x127f70: 0x24c60001  addiu       $a2, $a2, 0x1
    ctx->pc = 0x127f70u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 1));
    // 0x127f74: 0xc3102a  slt         $v0, $a2, $v1
    ctx->pc = 0x127f74u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 6) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x127f78: 0x1440ff63  bnez        $v0, . + 4 + (-0x9D << 2)
    ctx->pc = 0x127F78u;
    {
        const bool branch_taken_0x127f78 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x127F7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127F78u;
            // 0x127f7c: 0xafa60014  sw          $a2, 0x14($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x127f78) {
            ctx->pc = 0x127D08u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_127d08;
        }
    }
    ctx->pc = 0x127F80u;
label_127f80:
    // 0x127f80: 0x8fa40004  lw          $a0, 0x4($sp)
    ctx->pc = 0x127f80u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x127f84: 0xa48a0002  sh          $t2, 0x2($a0)
    ctx->pc = 0x127f84u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 2), (uint16_t)GPR_U32(ctx, 10));
    // 0x127f88: 0x8fa20000  lw          $v0, 0x0($sp)
    ctx->pc = 0x127f88u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x127f8c: 0xa48d0000  sh          $t5, 0x0($a0)
    ctx->pc = 0x127f8cu;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 13));
    // 0x127f90: 0x8fa50008  lw          $a1, 0x8($sp)
    ctx->pc = 0x127f90u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x127f94: 0xa4b00002  sh          $s0, 0x2($a1)
    ctx->pc = 0x127f94u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 2), (uint16_t)GPR_U32(ctx, 16));
    // 0x127f98: 0xa4ae0000  sh          $t6, 0x0($a1)
    ctx->pc = 0x127f98u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 14));
label_127f9c:
    // 0x127f9c: 0xdfb00020  ld          $s0, 0x20($sp)
    ctx->pc = 0x127f9cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x127fa0: 0xdfb10028  ld          $s1, 0x28($sp)
    ctx->pc = 0x127fa0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x127fa4: 0xdfb20030  ld          $s2, 0x30($sp)
    ctx->pc = 0x127fa4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x127fa8: 0xdfb30038  ld          $s3, 0x38($sp)
    ctx->pc = 0x127fa8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x127fac: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x127facu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x127fb0: 0xdfb50048  ld          $s5, 0x48($sp)
    ctx->pc = 0x127fb0u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x127fb4: 0xdfb60050  ld          $s6, 0x50($sp)
    ctx->pc = 0x127fb4u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x127fb8: 0xdfb70058  ld          $s7, 0x58($sp)
    ctx->pc = 0x127fb8u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x127fbc: 0xdfbe0060  ld          $fp, 0x60($sp)
    ctx->pc = 0x127fbcu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x127fc0: 0x3e00008  jr          $ra
    ctx->pc = 0x127FC0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x127FC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x127FC0u;
            // 0x127fc4: 0x27bd0070  addiu       $sp, $sp, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 112));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x127748u: goto label_127748;
            case 0x1277A8u: goto label_1277a8;
            case 0x12780Cu: goto label_12780c;
            case 0x127858u: goto label_127858;
            case 0x12787Cu: goto label_12787c;
            case 0x127888u: goto label_127888;
            case 0x127948u: goto label_127948;
            case 0x127A18u: goto label_127a18;
            case 0x127A78u: goto label_127a78;
            case 0x127AC0u: goto label_127ac0;
            case 0x127AD0u: goto label_127ad0;
            case 0x127B10u: goto label_127b10;
            case 0x127B78u: goto label_127b78;
            case 0x127BC0u: goto label_127bc0;
            case 0x127BD0u: goto label_127bd0;
            case 0x127C0Cu: goto label_127c0c;
            case 0x127C34u: goto label_127c34;
            case 0x127C50u: goto label_127c50;
            case 0x127D08u: goto label_127d08;
            case 0x127DD8u: goto label_127dd8;
            case 0x127E5Cu: goto label_127e5c;
            case 0x127EB0u: goto label_127eb0;
            case 0x127F1Cu: goto label_127f1c;
            case 0x127F48u: goto label_127f48;
            case 0x127F80u: goto label_127f80;
            case 0x127F9Cu: goto label_127f9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x127FC8u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
