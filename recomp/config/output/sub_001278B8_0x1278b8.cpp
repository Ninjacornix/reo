#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001278B8
// Address: 0x1278b8 - 0x127c7c
void sub_001278B8_0x1278b8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001278B8_0x1278b8");
#endif

    switch (ctx->pc) {
        case 0x127948u: goto label_127948;
        case 0x127a18u: goto label_127a18;
        default: break;
    }

    ctx->pc = 0x1278b8u;

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
            default: break;
        }
        return;
    }
    ctx->pc = 0x127C7Cu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
