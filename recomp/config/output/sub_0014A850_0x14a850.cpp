#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0014A850
// Address: 0x14a850 - 0x14cfb8
void sub_0014A850_0x14a850(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0014A850_0x14a850");
#endif

    ctx->pc = 0x14a850u;

    // 0x14a850: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x14a850u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x14a854: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x14a854u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14a858: 0xffb50050  sd          $s5, 0x50($sp)
    ctx->pc = 0x14a858u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x14a85c: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x14a85cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14a860: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x14a860u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x14a864: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x14a864u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x14a868: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x14a868u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x14a86c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x14a86cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x14a870: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x14a870u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x14a874: 0x15c03c  dsll32      $t8, $s5, 0
    ctx->pc = 0x14a874u;
    SET_GPR_U64(ctx, 24, GPR_U64(ctx, 21) << (32 + 0));
    // 0x14a878: 0x3c0300ff  lui         $v1, 0xFF
    ctx->pc = 0x14a878u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)255 << 16));
    // 0x14a87c: 0x346400ff  ori         $a0, $v1, 0xFF
    ctx->pc = 0x14a87cu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)255);
    // 0x14a880: 0x4183c  dsll32      $v1, $a0, 0
    ctx->pc = 0x14a880u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) << (32 + 0));
    // 0x14a884: 0x2783c  dsll32      $t7, $v0, 0
    ctx->pc = 0x14a884u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 2) << (32 + 0));
    // 0x14a888: 0x831825  or          $v1, $a0, $v1
    ctx->pc = 0x14a888u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) | GPR_U64(ctx, 3));
    // 0x14a88c: 0x18c03e  dsrl32      $t8, $t8, 0
    ctx->pc = 0x14a88cu;
    SET_GPR_U64(ctx, 24, GPR_U64(ctx, 24) >> (32 + 0));
    // 0x14a890: 0xf783e  dsrl32      $t7, $t7, 0
    ctx->pc = 0x14a890u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 15) >> (32 + 0));
    // 0x14a894: 0x316b0000  andi        $t3, $t3, 0x0
    ctx->pc = 0x14a894u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) & (uint64_t)(uint16_t)0);
    // 0x14a898: 0x716b5b89  pcpyld      $t3, $t3, $t3
    ctx->pc = 0x14a898u;
    SET_GPR_VEC(ctx, 11, PS2_PCPYLD(GPR_VEC(ctx, 11), GPR_VEC(ctx, 11)));
    // 0x14a89c: 0x700b5ee9  pcpyh       $t3, $t3
    ctx->pc = 0x14a89cu;
    { __m128i src = GPR_VEC(ctx, 0); uint16_t l = _mm_extract_epi16(src, 0); uint16_t h = _mm_extract_epi16(src, 4); 
   SET_GPR_VEC(ctx, 11, _mm_set_epi16(h,h,h,h, l,l,l,l)); }
    // 0x14a8a0: 0x67100100  daddiu      $s0, $t8, 0x100
    ctx->pc = 0x14a8a0u;
    SET_GPR_S64(ctx, 16, (int64_t)GPR_S64(ctx, 24) + (int64_t)(int32_t)256);
    // 0x14a8a4: 0x70636389  pcpyld      $t4, $v1, $v1
    ctx->pc = 0x14a8a4u;
    SET_GPR_VEC(ctx, 12, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 3)));
    // 0x14a8a8: 0xcf000000  pref        0x00, 0x0($t8)
    ctx->pc = 0x14a8a8u;
    // PREF instruction (ignored)
    // 0x14a8ac: 0xcf000100  pref        0x00, 0x100($t8)
    ctx->pc = 0x14a8acu;
    // PREF instruction (ignored)
    // 0x14a8b0: 0xcf000140  pref        0x00, 0x140($t8)
    ctx->pc = 0x14a8b0u;
    // PREF instruction (ignored)
    // 0x14a8b4: 0x24540080  addiu       $s4, $v0, 0x80
    ctx->pc = 0x14a8b4u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 128));
    // 0x14a8b8: 0x93070000  lbu         $a3, 0x0($t8)
    ctx->pc = 0x14a8b8u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 0)));
    // 0x14a8bc: 0x67190020  daddiu      $t9, $t8, 0x20
    ctx->pc = 0x14a8bcu;
    SET_GPR_S64(ctx, 25, (int64_t)GPR_S64(ctx, 24) + (int64_t)(int32_t)32);
    // 0x14a8c0: 0x93080011  lbu         $t0, 0x11($t8)
    ctx->pc = 0x14a8c0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 17)));
    // 0x14a8c4: 0x92120000  lbu         $s2, 0x0($s0)
    ctx->pc = 0x14a8c4u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x14a8c8: 0x92130040  lbu         $s3, 0x40($s0)
    ctx->pc = 0x14a8c8u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x14a8cc: 0x93030001  lbu         $v1, 0x1($t8)
    ctx->pc = 0x14a8ccu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 1)));
    // 0x14a8d0: 0x93110010  lbu         $s1, 0x10($t8)
    ctx->pc = 0x14a8d0u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 16)));
    // 0x14a8d4: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14a8d4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14a8d8: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14a8d8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14a8dc: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14a8dcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14a8e0: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14a8e0u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14a8e4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14a8e4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14a8e8: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14a8e8u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14a8ec: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14a8ecu;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14a8f0: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14a8f0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14a8f4: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14a8f4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14a8f8: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14a8f8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14a8fc: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14a8fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14a900: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14a900u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14a904: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14a904u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14a908: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14a908u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14a90c: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14a90cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14a910: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14a910u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14a914: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14a914u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14a918: 0x92120001  lbu         $s2, 0x1($s0)
    ctx->pc = 0x14a918u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x14a91c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14a91cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14a920: 0x92130041  lbu         $s3, 0x41($s0)
    ctx->pc = 0x14a920u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 65)));
    // 0x14a924: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14a924u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14a928: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14a928u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14a92c: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14a92cu;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14a930: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14a930u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14a934: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14a934u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14a938: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14a938u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14a93c: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14a93cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14a940: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14a940u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14a944: 0x93110012  lbu         $s1, 0x12($t8)
    ctx->pc = 0x14a944u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 18)));
    // 0x14a948: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14a948u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14a94c: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14a94cu;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14a950: 0x93030003  lbu         $v1, 0x3($t8)
    ctx->pc = 0x14a950u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 3)));
    // 0x14a954: 0x93070002  lbu         $a3, 0x2($t8)
    ctx->pc = 0x14a954u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 2)));
    // 0x14a958: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14a958u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14a95c: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14a95cu;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14a960: 0x93080013  lbu         $t0, 0x13($t8)
    ctx->pc = 0x14a960u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 19)));
    // 0x14a964: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14a964u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14a968: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14a968u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14a96c: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14a96cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14a970: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14a970u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14a974: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14a974u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14a978: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14a978u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14a97c: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14a97cu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14a980: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14a980u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14a984: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14a984u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14a988: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14a988u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14a98c: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14a98cu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14a990: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14a990u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14a994: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14a994u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14a998: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14a998u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14a99c: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14a99cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14a9a0: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14a9a0u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14a9a4: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14a9a4u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14a9a8: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14a9a8u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14a9ac: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14a9acu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14a9b0: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14a9b0u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14a9b4: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14a9b4u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14a9b8: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14a9b8u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14a9bc: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14a9bcu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14a9c0: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14a9c0u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14a9c4: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14a9c4u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14a9c8: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14a9c8u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14a9cc: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14a9ccu;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14a9d0: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14a9d0u;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14a9d4: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14a9d4u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14a9d8: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14a9d8u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14a9dc: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14a9dcu;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14a9e0: 0x7de30000  sq          $v1, 0x0($t7)
    ctx->pc = 0x14a9e0u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 0), GPR_VEC(ctx, 3));
    // 0x14a9e4: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14a9e4u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14a9e8: 0x7de30040  sq          $v1, 0x40($t7)
    ctx->pc = 0x14a9e8u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 64), GPR_VEC(ctx, 3));
    // 0x14a9ec: 0x93070004  lbu         $a3, 0x4($t8)
    ctx->pc = 0x14a9ecu;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 4)));
    // 0x14a9f0: 0x93080015  lbu         $t0, 0x15($t8)
    ctx->pc = 0x14a9f0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 21)));
    // 0x14a9f4: 0x92120002  lbu         $s2, 0x2($s0)
    ctx->pc = 0x14a9f4u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x14a9f8: 0x92130042  lbu         $s3, 0x42($s0)
    ctx->pc = 0x14a9f8u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x14a9fc: 0x93030005  lbu         $v1, 0x5($t8)
    ctx->pc = 0x14a9fcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 5)));
    // 0x14aa00: 0x93110014  lbu         $s1, 0x14($t8)
    ctx->pc = 0x14aa00u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 20)));
    // 0x14aa04: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14aa04u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14aa08: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14aa08u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14aa0c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14aa0cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14aa10: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14aa10u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14aa14: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14aa14u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14aa18: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14aa18u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14aa1c: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14aa1cu;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14aa20: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14aa20u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14aa24: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14aa24u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14aa28: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14aa28u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14aa2c: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14aa2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14aa30: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14aa30u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14aa34: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14aa34u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14aa38: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14aa38u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14aa3c: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14aa3cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14aa40: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14aa40u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14aa44: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14aa44u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14aa48: 0x92120003  lbu         $s2, 0x3($s0)
    ctx->pc = 0x14aa48u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x14aa4c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14aa4cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14aa50: 0x92130043  lbu         $s3, 0x43($s0)
    ctx->pc = 0x14aa50u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 67)));
    // 0x14aa54: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14aa54u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14aa58: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14aa58u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14aa5c: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14aa5cu;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14aa60: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14aa60u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14aa64: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14aa64u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14aa68: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14aa68u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14aa6c: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14aa6cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14aa70: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14aa70u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14aa74: 0x93110016  lbu         $s1, 0x16($t8)
    ctx->pc = 0x14aa74u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 22)));
    // 0x14aa78: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14aa78u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14aa7c: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14aa7cu;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14aa80: 0x93030007  lbu         $v1, 0x7($t8)
    ctx->pc = 0x14aa80u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 7)));
    // 0x14aa84: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14aa84u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14aa88: 0x93070006  lbu         $a3, 0x6($t8)
    ctx->pc = 0x14aa88u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 6)));
    // 0x14aa8c: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14aa8cu;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14aa90: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14aa90u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14aa94: 0x93080017  lbu         $t0, 0x17($t8)
    ctx->pc = 0x14aa94u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 23)));
    // 0x14aa98: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14aa98u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14aa9c: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14aa9cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14aaa0: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14aaa0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14aaa4: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14aaa4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14aaa8: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14aaa8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14aaac: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14aaacu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14aab0: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14aab0u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14aab4: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14aab4u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14aab8: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14aab8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14aabc: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14aabcu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14aac0: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14aac0u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14aac4: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14aac4u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14aac8: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14aac8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14aacc: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14aaccu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14aad0: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14aad0u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14aad4: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14aad4u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14aad8: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14aad8u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14aadc: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14aadcu;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14aae0: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14aae0u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14aae4: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14aae4u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14aae8: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14aae8u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14aaec: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14aaecu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14aaf0: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14aaf0u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14aaf4: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14aaf4u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14aaf8: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14aaf8u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14aafc: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14aafcu;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14ab00: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14ab00u;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14ab04: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14ab04u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14ab08: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14ab08u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14ab0c: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14ab0cu;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14ab10: 0x7de30010  sq          $v1, 0x10($t7)
    ctx->pc = 0x14ab10u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 16), GPR_VEC(ctx, 3));
    // 0x14ab14: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14ab14u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14ab18: 0x7de30050  sq          $v1, 0x50($t7)
    ctx->pc = 0x14ab18u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 80), GPR_VEC(ctx, 3));
    // 0x14ab1c: 0x93070008  lbu         $a3, 0x8($t8)
    ctx->pc = 0x14ab1cu;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 8)));
    // 0x14ab20: 0x93080019  lbu         $t0, 0x19($t8)
    ctx->pc = 0x14ab20u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 25)));
    // 0x14ab24: 0x92120004  lbu         $s2, 0x4($s0)
    ctx->pc = 0x14ab24u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x14ab28: 0x92130044  lbu         $s3, 0x44($s0)
    ctx->pc = 0x14ab28u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x14ab2c: 0x93030009  lbu         $v1, 0x9($t8)
    ctx->pc = 0x14ab2cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 9)));
    // 0x14ab30: 0x93110018  lbu         $s1, 0x18($t8)
    ctx->pc = 0x14ab30u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 24)));
    // 0x14ab34: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14ab34u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14ab38: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14ab38u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14ab3c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14ab3cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14ab40: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14ab40u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14ab44: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14ab44u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14ab48: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14ab48u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14ab4c: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14ab4cu;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14ab50: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14ab50u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14ab54: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14ab54u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14ab58: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14ab58u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14ab5c: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14ab5cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14ab60: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14ab60u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14ab64: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14ab64u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14ab68: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14ab68u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14ab6c: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14ab6cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14ab70: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14ab70u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14ab74: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14ab74u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14ab78: 0x92120005  lbu         $s2, 0x5($s0)
    ctx->pc = 0x14ab78u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 5)));
    // 0x14ab7c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14ab7cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14ab80: 0x92130045  lbu         $s3, 0x45($s0)
    ctx->pc = 0x14ab80u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 69)));
    // 0x14ab84: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14ab84u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14ab88: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14ab88u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14ab8c: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14ab8cu;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14ab90: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14ab90u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14ab94: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14ab94u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14ab98: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14ab98u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14ab9c: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14ab9cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14aba0: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14aba0u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14aba4: 0x9311001a  lbu         $s1, 0x1A($t8)
    ctx->pc = 0x14aba4u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 26)));
    // 0x14aba8: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14aba8u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14abac: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14abacu;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14abb0: 0x9303000b  lbu         $v1, 0xB($t8)
    ctx->pc = 0x14abb0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 11)));
    // 0x14abb4: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14abb4u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14abb8: 0x9307000a  lbu         $a3, 0xA($t8)
    ctx->pc = 0x14abb8u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 10)));
    // 0x14abbc: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14abbcu;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14abc0: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14abc0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14abc4: 0x9308001b  lbu         $t0, 0x1B($t8)
    ctx->pc = 0x14abc4u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 27)));
    // 0x14abc8: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14abc8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14abcc: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14abccu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14abd0: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14abd0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14abd4: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14abd4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14abd8: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14abd8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14abdc: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14abdcu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14abe0: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14abe0u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14abe4: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14abe4u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14abe8: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14abe8u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14abec: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14abecu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14abf0: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14abf0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14abf4: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14abf4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14abf8: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14abf8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14abfc: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14abfcu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14ac00: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14ac00u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14ac04: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14ac04u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14ac08: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14ac08u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14ac0c: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14ac0cu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14ac10: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14ac10u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14ac14: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14ac14u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14ac18: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14ac18u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14ac1c: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14ac1cu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14ac20: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14ac20u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14ac24: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14ac24u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14ac28: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14ac28u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14ac2c: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14ac2cu;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14ac30: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14ac30u;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14ac34: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14ac34u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14ac38: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14ac38u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14ac3c: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14ac3cu;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14ac40: 0x7de30020  sq          $v1, 0x20($t7)
    ctx->pc = 0x14ac40u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 32), GPR_VEC(ctx, 3));
    // 0x14ac44: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14ac44u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14ac48: 0x7de30060  sq          $v1, 0x60($t7)
    ctx->pc = 0x14ac48u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 96), GPR_VEC(ctx, 3));
    // 0x14ac4c: 0x9307000c  lbu         $a3, 0xC($t8)
    ctx->pc = 0x14ac4cu;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 12)));
    // 0x14ac50: 0x9308001d  lbu         $t0, 0x1D($t8)
    ctx->pc = 0x14ac50u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 29)));
    // 0x14ac54: 0x92120006  lbu         $s2, 0x6($s0)
    ctx->pc = 0x14ac54u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x14ac58: 0x92130046  lbu         $s3, 0x46($s0)
    ctx->pc = 0x14ac58u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 70)));
    // 0x14ac5c: 0x9303000d  lbu         $v1, 0xD($t8)
    ctx->pc = 0x14ac5cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 13)));
    // 0x14ac60: 0x9311001c  lbu         $s1, 0x1C($t8)
    ctx->pc = 0x14ac60u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 28)));
    // 0x14ac64: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14ac64u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14ac68: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14ac68u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14ac6c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14ac6cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14ac70: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14ac70u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14ac74: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14ac74u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14ac78: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14ac78u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14ac7c: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14ac7cu;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14ac80: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14ac80u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14ac84: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14ac84u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14ac88: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14ac88u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14ac8c: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14ac8cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14ac90: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14ac90u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14ac94: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14ac94u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14ac98: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14ac98u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14ac9c: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14ac9cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14aca0: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14aca0u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14aca4: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14aca4u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14aca8: 0x92120007  lbu         $s2, 0x7($s0)
    ctx->pc = 0x14aca8u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 7)));
    // 0x14acac: 0x92130047  lbu         $s3, 0x47($s0)
    ctx->pc = 0x14acacu;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 71)));
    // 0x14acb0: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14acb0u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14acb4: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14acb4u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14acb8: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14acb8u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14acbc: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14acbcu;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14acc0: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14acc0u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14acc4: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14acc4u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14acc8: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14acc8u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14accc: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14acccu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14acd0: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14acd0u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14acd4: 0x9311001e  lbu         $s1, 0x1E($t8)
    ctx->pc = 0x14acd4u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 30)));
    // 0x14acd8: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14acd8u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14acdc: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14acdcu;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14ace0: 0x9303000f  lbu         $v1, 0xF($t8)
    ctx->pc = 0x14ace0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 15)));
    // 0x14ace4: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14ace4u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14ace8: 0x9307000e  lbu         $a3, 0xE($t8)
    ctx->pc = 0x14ace8u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 14)));
    // 0x14acec: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14acecu;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14acf0: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14acf0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14acf4: 0x9308001f  lbu         $t0, 0x1F($t8)
    ctx->pc = 0x14acf4u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 24), 31)));
    // 0x14acf8: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14acf8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14acfc: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14acfcu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14ad00: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14ad00u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14ad04: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14ad04u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14ad08: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14ad08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14ad0c: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14ad0cu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14ad10: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14ad10u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14ad14: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14ad14u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14ad18: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14ad18u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14ad1c: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14ad1cu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14ad20: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14ad20u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14ad24: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14ad24u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14ad28: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14ad28u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14ad2c: 0x66100008  daddiu      $s0, $s0, 0x8
    ctx->pc = 0x14ad2cu;
    SET_GPR_S64(ctx, 16, (int64_t)GPR_S64(ctx, 16) + (int64_t)(int32_t)8);
    // 0x14ad30: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14ad30u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14ad34: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14ad34u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14ad38: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14ad38u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14ad3c: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14ad3cu;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14ad40: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14ad40u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14ad44: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14ad44u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14ad48: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14ad48u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14ad4c: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14ad4cu;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14ad50: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14ad50u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14ad54: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14ad54u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14ad58: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14ad58u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14ad5c: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14ad5cu;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14ad60: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14ad60u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14ad64: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14ad64u;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14ad68: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14ad68u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14ad6c: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14ad6cu;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14ad70: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14ad70u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14ad74: 0x7de30030  sq          $v1, 0x30($t7)
    ctx->pc = 0x14ad74u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 48), GPR_VEC(ctx, 3));
    // 0x14ad78: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14ad78u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14ad7c: 0x7de30070  sq          $v1, 0x70($t7)
    ctx->pc = 0x14ad7cu;
    WRITE128(ADD32(GPR_U32(ctx, 15), 112), GPR_VEC(ctx, 3));
    // 0x14ad80: 0x14783c  dsll32      $t7, $s4, 0
    ctx->pc = 0x14ad80u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 20) << (32 + 0));
    // 0x14ad84: 0xf783e  dsrl32      $t7, $t7, 0
    ctx->pc = 0x14ad84u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 15) >> (32 + 0));
    // 0x14ad88: 0xcf200020  pref        0x00, 0x20($t9)
    ctx->pc = 0x14ad88u;
    // PREF instruction (ignored)
    // 0x14ad8c: 0xcf000100  pref        0x00, 0x100($t8)
    ctx->pc = 0x14ad8cu;
    // PREF instruction (ignored)
    // 0x14ad90: 0xcf000140  pref        0x00, 0x140($t8)
    ctx->pc = 0x14ad90u;
    // PREF instruction (ignored)
    // 0x14ad94: 0x24540100  addiu       $s4, $v0, 0x100
    ctx->pc = 0x14ad94u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 256));
    // 0x14ad98: 0x93270000  lbu         $a3, 0x0($t9)
    ctx->pc = 0x14ad98u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 0)));
    // 0x14ad9c: 0x93280011  lbu         $t0, 0x11($t9)
    ctx->pc = 0x14ad9cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 17)));
    // 0x14ada0: 0x92120000  lbu         $s2, 0x0($s0)
    ctx->pc = 0x14ada0u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x14ada4: 0x92130040  lbu         $s3, 0x40($s0)
    ctx->pc = 0x14ada4u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x14ada8: 0x93230001  lbu         $v1, 0x1($t9)
    ctx->pc = 0x14ada8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 1)));
    // 0x14adac: 0x93310010  lbu         $s1, 0x10($t9)
    ctx->pc = 0x14adacu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 16)));
    // 0x14adb0: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14adb0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14adb4: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14adb4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14adb8: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14adb8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14adbc: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14adbcu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14adc0: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14adc0u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14adc4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14adc4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14adc8: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14adc8u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14adcc: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14adccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14add0: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14add0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14add4: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14add4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14add8: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14add8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14addc: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14addcu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14ade0: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14ade0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14ade4: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14ade4u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14ade8: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14ade8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14adec: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14adecu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14adf0: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14adf0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14adf4: 0x92120001  lbu         $s2, 0x1($s0)
    ctx->pc = 0x14adf4u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x14adf8: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14adf8u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14adfc: 0x92130041  lbu         $s3, 0x41($s0)
    ctx->pc = 0x14adfcu;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 65)));
    // 0x14ae00: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14ae00u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14ae04: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14ae04u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14ae08: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14ae08u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14ae0c: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14ae0cu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14ae10: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14ae10u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14ae14: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14ae14u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14ae18: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14ae18u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14ae1c: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14ae1cu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14ae20: 0x93310012  lbu         $s1, 0x12($t9)
    ctx->pc = 0x14ae20u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 18)));
    // 0x14ae24: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14ae24u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14ae28: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14ae28u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14ae2c: 0x93230003  lbu         $v1, 0x3($t9)
    ctx->pc = 0x14ae2cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 3)));
    // 0x14ae30: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14ae30u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14ae34: 0x93270002  lbu         $a3, 0x2($t9)
    ctx->pc = 0x14ae34u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 2)));
    // 0x14ae38: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14ae38u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14ae3c: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14ae3cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14ae40: 0x93280013  lbu         $t0, 0x13($t9)
    ctx->pc = 0x14ae40u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 19)));
    // 0x14ae44: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14ae44u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14ae48: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14ae48u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14ae4c: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14ae4cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14ae50: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14ae50u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14ae54: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14ae54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14ae58: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14ae58u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14ae5c: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14ae5cu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14ae60: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14ae60u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14ae64: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14ae64u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14ae68: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14ae68u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14ae6c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14ae6cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14ae70: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14ae70u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14ae74: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14ae74u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14ae78: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14ae78u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14ae7c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14ae7cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14ae80: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14ae80u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14ae84: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14ae84u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14ae88: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14ae88u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14ae8c: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14ae8cu;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14ae90: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14ae90u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14ae94: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14ae94u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14ae98: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14ae98u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14ae9c: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14ae9cu;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14aea0: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14aea0u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14aea4: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14aea4u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14aea8: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14aea8u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14aeac: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14aeacu;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14aeb0: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14aeb0u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14aeb4: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14aeb4u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14aeb8: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14aeb8u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14aebc: 0x7de30000  sq          $v1, 0x0($t7)
    ctx->pc = 0x14aebcu;
    WRITE128(ADD32(GPR_U32(ctx, 15), 0), GPR_VEC(ctx, 3));
    // 0x14aec0: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14aec0u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14aec4: 0x7de30040  sq          $v1, 0x40($t7)
    ctx->pc = 0x14aec4u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 64), GPR_VEC(ctx, 3));
    // 0x14aec8: 0x93270004  lbu         $a3, 0x4($t9)
    ctx->pc = 0x14aec8u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 4)));
    // 0x14aecc: 0x93280015  lbu         $t0, 0x15($t9)
    ctx->pc = 0x14aeccu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 21)));
    // 0x14aed0: 0x92120002  lbu         $s2, 0x2($s0)
    ctx->pc = 0x14aed0u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x14aed4: 0x92130042  lbu         $s3, 0x42($s0)
    ctx->pc = 0x14aed4u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x14aed8: 0x93230005  lbu         $v1, 0x5($t9)
    ctx->pc = 0x14aed8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 5)));
    // 0x14aedc: 0x93310014  lbu         $s1, 0x14($t9)
    ctx->pc = 0x14aedcu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 20)));
    // 0x14aee0: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14aee0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14aee4: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14aee4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14aee8: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14aee8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14aeec: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14aeecu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14aef0: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14aef0u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14aef4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14aef4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14aef8: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14aef8u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14aefc: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14aefcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14af00: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14af00u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14af04: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14af04u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14af08: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14af08u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14af0c: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14af0cu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14af10: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14af10u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14af14: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14af14u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14af18: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14af18u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14af1c: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14af1cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14af20: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14af20u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14af24: 0x92120003  lbu         $s2, 0x3($s0)
    ctx->pc = 0x14af24u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x14af28: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14af28u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14af2c: 0x92130043  lbu         $s3, 0x43($s0)
    ctx->pc = 0x14af2cu;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 67)));
    // 0x14af30: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14af30u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14af34: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14af34u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14af38: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14af38u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14af3c: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14af3cu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14af40: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14af40u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14af44: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14af44u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14af48: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14af48u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14af4c: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14af4cu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14af50: 0x93310016  lbu         $s1, 0x16($t9)
    ctx->pc = 0x14af50u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 22)));
    // 0x14af54: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14af54u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14af58: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14af58u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14af5c: 0x93230007  lbu         $v1, 0x7($t9)
    ctx->pc = 0x14af5cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 7)));
    // 0x14af60: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14af60u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14af64: 0x93270006  lbu         $a3, 0x6($t9)
    ctx->pc = 0x14af64u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 6)));
    // 0x14af68: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14af68u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14af6c: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14af6cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14af70: 0x93280017  lbu         $t0, 0x17($t9)
    ctx->pc = 0x14af70u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 23)));
    // 0x14af74: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14af74u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14af78: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14af78u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14af7c: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14af7cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14af80: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14af80u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14af84: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14af84u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14af88: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14af88u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14af8c: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14af8cu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14af90: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14af90u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14af94: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14af94u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14af98: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14af98u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14af9c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14af9cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14afa0: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14afa0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14afa4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14afa4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14afa8: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14afa8u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14afac: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14afacu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14afb0: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14afb0u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14afb4: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14afb4u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14afb8: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14afb8u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14afbc: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14afbcu;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14afc0: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14afc0u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14afc4: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14afc4u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14afc8: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14afc8u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14afcc: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14afccu;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14afd0: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14afd0u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14afd4: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14afd4u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14afd8: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14afd8u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14afdc: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14afdcu;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14afe0: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14afe0u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14afe4: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14afe4u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14afe8: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14afe8u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14afec: 0x7de30010  sq          $v1, 0x10($t7)
    ctx->pc = 0x14afecu;
    WRITE128(ADD32(GPR_U32(ctx, 15), 16), GPR_VEC(ctx, 3));
    // 0x14aff0: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14aff0u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14aff4: 0x7de30050  sq          $v1, 0x50($t7)
    ctx->pc = 0x14aff4u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 80), GPR_VEC(ctx, 3));
    // 0x14aff8: 0x93270008  lbu         $a3, 0x8($t9)
    ctx->pc = 0x14aff8u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 8)));
    // 0x14affc: 0x93280019  lbu         $t0, 0x19($t9)
    ctx->pc = 0x14affcu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 25)));
    // 0x14b000: 0x92120004  lbu         $s2, 0x4($s0)
    ctx->pc = 0x14b000u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x14b004: 0x92130044  lbu         $s3, 0x44($s0)
    ctx->pc = 0x14b004u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x14b008: 0x93230009  lbu         $v1, 0x9($t9)
    ctx->pc = 0x14b008u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 9)));
    // 0x14b00c: 0x93310018  lbu         $s1, 0x18($t9)
    ctx->pc = 0x14b00cu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 24)));
    // 0x14b010: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14b010u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14b014: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14b014u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14b018: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14b018u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14b01c: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14b01cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14b020: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14b020u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14b024: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14b024u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14b028: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14b028u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14b02c: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14b02cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14b030: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14b030u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14b034: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14b034u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14b038: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14b038u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14b03c: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14b03cu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14b040: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14b040u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14b044: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14b044u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14b048: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14b048u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14b04c: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14b04cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14b050: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14b050u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14b054: 0x92120005  lbu         $s2, 0x5($s0)
    ctx->pc = 0x14b054u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 5)));
    // 0x14b058: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14b058u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14b05c: 0x92130045  lbu         $s3, 0x45($s0)
    ctx->pc = 0x14b05cu;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 69)));
    // 0x14b060: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14b060u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14b064: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14b064u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14b068: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14b068u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14b06c: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14b06cu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14b070: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14b070u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14b074: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14b074u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14b078: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14b078u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14b07c: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14b07cu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14b080: 0x9331001a  lbu         $s1, 0x1A($t9)
    ctx->pc = 0x14b080u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 26)));
    // 0x14b084: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14b084u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14b088: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14b088u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14b08c: 0x9323000b  lbu         $v1, 0xB($t9)
    ctx->pc = 0x14b08cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 11)));
    // 0x14b090: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14b090u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14b094: 0x9327000a  lbu         $a3, 0xA($t9)
    ctx->pc = 0x14b094u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 10)));
    // 0x14b098: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14b098u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14b09c: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14b09cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14b0a0: 0x9328001b  lbu         $t0, 0x1B($t9)
    ctx->pc = 0x14b0a0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 27)));
    // 0x14b0a4: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14b0a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14b0a8: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14b0a8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14b0ac: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14b0acu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14b0b0: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14b0b0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14b0b4: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14b0b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14b0b8: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14b0b8u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14b0bc: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14b0bcu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14b0c0: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14b0c0u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14b0c4: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14b0c4u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14b0c8: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14b0c8u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14b0cc: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14b0ccu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14b0d0: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14b0d0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14b0d4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14b0d4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14b0d8: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14b0d8u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14b0dc: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14b0dcu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14b0e0: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14b0e0u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14b0e4: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14b0e4u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14b0e8: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14b0e8u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14b0ec: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14b0ecu;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14b0f0: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14b0f0u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14b0f4: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14b0f4u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14b0f8: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14b0f8u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14b0fc: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14b0fcu;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14b100: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14b100u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14b104: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14b104u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14b108: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14b108u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14b10c: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14b10cu;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14b110: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14b110u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14b114: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14b114u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14b118: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14b118u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14b11c: 0x7de30020  sq          $v1, 0x20($t7)
    ctx->pc = 0x14b11cu;
    WRITE128(ADD32(GPR_U32(ctx, 15), 32), GPR_VEC(ctx, 3));
    // 0x14b120: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14b120u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14b124: 0x7de30060  sq          $v1, 0x60($t7)
    ctx->pc = 0x14b124u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 96), GPR_VEC(ctx, 3));
    // 0x14b128: 0x9327000c  lbu         $a3, 0xC($t9)
    ctx->pc = 0x14b128u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 12)));
    // 0x14b12c: 0x9328001d  lbu         $t0, 0x1D($t9)
    ctx->pc = 0x14b12cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 29)));
    // 0x14b130: 0x92120006  lbu         $s2, 0x6($s0)
    ctx->pc = 0x14b130u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x14b134: 0x92130046  lbu         $s3, 0x46($s0)
    ctx->pc = 0x14b134u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 70)));
    // 0x14b138: 0x9323000d  lbu         $v1, 0xD($t9)
    ctx->pc = 0x14b138u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 13)));
    // 0x14b13c: 0x9331001c  lbu         $s1, 0x1C($t9)
    ctx->pc = 0x14b13cu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 28)));
    // 0x14b140: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14b140u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14b144: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14b144u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14b148: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14b148u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14b14c: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14b14cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14b150: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14b150u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14b154: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14b154u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14b158: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14b158u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14b15c: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14b15cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14b160: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14b160u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14b164: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14b164u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14b168: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14b168u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14b16c: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14b16cu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14b170: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14b170u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14b174: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14b174u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14b178: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14b178u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14b17c: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14b17cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14b180: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14b180u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14b184: 0x92120007  lbu         $s2, 0x7($s0)
    ctx->pc = 0x14b184u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 7)));
    // 0x14b188: 0x92130047  lbu         $s3, 0x47($s0)
    ctx->pc = 0x14b188u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 71)));
    // 0x14b18c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14b18cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14b190: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14b190u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14b194: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14b194u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14b198: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14b198u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14b19c: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14b19cu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14b1a0: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14b1a0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14b1a4: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14b1a4u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14b1a8: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14b1a8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14b1ac: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14b1acu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14b1b0: 0x9331001e  lbu         $s1, 0x1E($t9)
    ctx->pc = 0x14b1b0u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 30)));
    // 0x14b1b4: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14b1b4u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14b1b8: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14b1b8u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14b1bc: 0x9323000f  lbu         $v1, 0xF($t9)
    ctx->pc = 0x14b1bcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 15)));
    // 0x14b1c0: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14b1c0u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14b1c4: 0x9327000e  lbu         $a3, 0xE($t9)
    ctx->pc = 0x14b1c4u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 14)));
    // 0x14b1c8: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14b1c8u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14b1cc: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14b1ccu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14b1d0: 0x9328001f  lbu         $t0, 0x1F($t9)
    ctx->pc = 0x14b1d0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 31)));
    // 0x14b1d4: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14b1d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14b1d8: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14b1d8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14b1dc: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14b1dcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14b1e0: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14b1e0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14b1e4: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14b1e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14b1e8: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14b1e8u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14b1ec: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14b1ecu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14b1f0: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14b1f0u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14b1f4: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14b1f4u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14b1f8: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14b1f8u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14b1fc: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14b1fcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14b200: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14b200u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14b204: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14b204u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14b208: 0x67390020  daddiu      $t9, $t9, 0x20
    ctx->pc = 0x14b208u;
    SET_GPR_S64(ctx, 25, (int64_t)GPR_S64(ctx, 25) + (int64_t)(int32_t)32);
    // 0x14b20c: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14b20cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14b210: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14b210u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14b214: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14b214u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14b218: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14b218u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14b21c: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14b21cu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14b220: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14b220u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14b224: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14b224u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14b228: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14b228u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14b22c: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14b22cu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14b230: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14b230u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14b234: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14b234u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14b238: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14b238u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14b23c: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14b23cu;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14b240: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14b240u;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14b244: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14b244u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14b248: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14b248u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14b24c: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14b24cu;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14b250: 0x7de30030  sq          $v1, 0x30($t7)
    ctx->pc = 0x14b250u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 48), GPR_VEC(ctx, 3));
    // 0x14b254: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14b254u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14b258: 0x7de30070  sq          $v1, 0x70($t7)
    ctx->pc = 0x14b258u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 112), GPR_VEC(ctx, 3));
    // 0x14b25c: 0x66100008  daddiu      $s0, $s0, 0x8
    ctx->pc = 0x14b25cu;
    SET_GPR_S64(ctx, 16, (int64_t)GPR_S64(ctx, 16) + (int64_t)(int32_t)8);
    // 0x14b260: 0x14783c  dsll32      $t7, $s4, 0
    ctx->pc = 0x14b260u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 20) << (32 + 0));
    // 0x14b264: 0xf783e  dsrl32      $t7, $t7, 0
    ctx->pc = 0x14b264u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 15) >> (32 + 0));
    // 0x14b268: 0xcf200040  pref        0x00, 0x40($t9)
    ctx->pc = 0x14b268u;
    // PREF instruction (ignored)
    // 0x14b26c: 0xcf000100  pref        0x00, 0x100($t8)
    ctx->pc = 0x14b26cu;
    // PREF instruction (ignored)
    // 0x14b270: 0xcf000140  pref        0x00, 0x140($t8)
    ctx->pc = 0x14b270u;
    // PREF instruction (ignored)
    // 0x14b274: 0x24540180  addiu       $s4, $v0, 0x180
    ctx->pc = 0x14b274u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 384));
    // 0x14b278: 0x93270000  lbu         $a3, 0x0($t9)
    ctx->pc = 0x14b278u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 0)));
    // 0x14b27c: 0x93280011  lbu         $t0, 0x11($t9)
    ctx->pc = 0x14b27cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 17)));
    // 0x14b280: 0x92120000  lbu         $s2, 0x0($s0)
    ctx->pc = 0x14b280u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x14b284: 0x92130040  lbu         $s3, 0x40($s0)
    ctx->pc = 0x14b284u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x14b288: 0x93230001  lbu         $v1, 0x1($t9)
    ctx->pc = 0x14b288u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 1)));
    // 0x14b28c: 0x93310010  lbu         $s1, 0x10($t9)
    ctx->pc = 0x14b28cu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 16)));
    // 0x14b290: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14b290u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14b294: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14b294u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14b298: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14b298u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14b29c: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14b29cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14b2a0: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14b2a0u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14b2a4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14b2a4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14b2a8: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14b2a8u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14b2ac: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14b2acu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14b2b0: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14b2b0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14b2b4: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14b2b4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14b2b8: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14b2b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14b2bc: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14b2bcu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14b2c0: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14b2c0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14b2c4: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14b2c4u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14b2c8: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14b2c8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14b2cc: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14b2ccu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14b2d0: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14b2d0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14b2d4: 0x92120001  lbu         $s2, 0x1($s0)
    ctx->pc = 0x14b2d4u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x14b2d8: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14b2d8u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14b2dc: 0x92130041  lbu         $s3, 0x41($s0)
    ctx->pc = 0x14b2dcu;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 65)));
    // 0x14b2e0: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14b2e0u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14b2e4: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14b2e4u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14b2e8: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14b2e8u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14b2ec: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14b2ecu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14b2f0: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14b2f0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14b2f4: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14b2f4u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14b2f8: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14b2f8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14b2fc: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14b2fcu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14b300: 0x93310012  lbu         $s1, 0x12($t9)
    ctx->pc = 0x14b300u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 18)));
    // 0x14b304: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14b304u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14b308: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14b308u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14b30c: 0x93230003  lbu         $v1, 0x3($t9)
    ctx->pc = 0x14b30cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 3)));
    // 0x14b310: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14b310u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14b314: 0x93270002  lbu         $a3, 0x2($t9)
    ctx->pc = 0x14b314u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 2)));
    // 0x14b318: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14b318u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14b31c: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14b31cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14b320: 0x93280013  lbu         $t0, 0x13($t9)
    ctx->pc = 0x14b320u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 19)));
    // 0x14b324: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14b324u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14b328: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14b328u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14b32c: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14b32cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14b330: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14b330u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14b334: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14b334u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14b338: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14b338u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14b33c: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14b33cu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14b340: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14b340u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14b344: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14b344u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14b348: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14b348u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14b34c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14b34cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14b350: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14b350u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14b354: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14b354u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14b358: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14b358u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14b35c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14b35cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14b360: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14b360u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14b364: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14b364u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14b368: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14b368u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14b36c: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14b36cu;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14b370: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14b370u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14b374: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14b374u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14b378: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14b378u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14b37c: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14b37cu;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14b380: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14b380u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14b384: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14b384u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14b388: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14b388u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14b38c: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14b38cu;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14b390: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14b390u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14b394: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14b394u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14b398: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14b398u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14b39c: 0x7de30000  sq          $v1, 0x0($t7)
    ctx->pc = 0x14b39cu;
    WRITE128(ADD32(GPR_U32(ctx, 15), 0), GPR_VEC(ctx, 3));
    // 0x14b3a0: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14b3a0u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14b3a4: 0x7de30040  sq          $v1, 0x40($t7)
    ctx->pc = 0x14b3a4u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 64), GPR_VEC(ctx, 3));
    // 0x14b3a8: 0x93270004  lbu         $a3, 0x4($t9)
    ctx->pc = 0x14b3a8u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 4)));
    // 0x14b3ac: 0x93280015  lbu         $t0, 0x15($t9)
    ctx->pc = 0x14b3acu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 21)));
    // 0x14b3b0: 0x92120002  lbu         $s2, 0x2($s0)
    ctx->pc = 0x14b3b0u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x14b3b4: 0x92130042  lbu         $s3, 0x42($s0)
    ctx->pc = 0x14b3b4u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x14b3b8: 0x93230005  lbu         $v1, 0x5($t9)
    ctx->pc = 0x14b3b8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 5)));
    // 0x14b3bc: 0x93310014  lbu         $s1, 0x14($t9)
    ctx->pc = 0x14b3bcu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 20)));
    // 0x14b3c0: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14b3c0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14b3c4: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14b3c4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14b3c8: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14b3c8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14b3cc: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14b3ccu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14b3d0: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14b3d0u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14b3d4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14b3d4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14b3d8: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14b3d8u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14b3dc: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14b3dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14b3e0: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14b3e0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14b3e4: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14b3e4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14b3e8: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14b3e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14b3ec: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14b3ecu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14b3f0: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14b3f0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14b3f4: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14b3f4u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14b3f8: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14b3f8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14b3fc: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14b3fcu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14b400: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14b400u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14b404: 0x92120003  lbu         $s2, 0x3($s0)
    ctx->pc = 0x14b404u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x14b408: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14b408u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14b40c: 0x92130043  lbu         $s3, 0x43($s0)
    ctx->pc = 0x14b40cu;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 67)));
    // 0x14b410: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14b410u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14b414: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14b414u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14b418: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14b418u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14b41c: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14b41cu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14b420: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14b420u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14b424: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14b424u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14b428: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14b428u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14b42c: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14b42cu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14b430: 0x93310016  lbu         $s1, 0x16($t9)
    ctx->pc = 0x14b430u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 22)));
    // 0x14b434: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14b434u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14b438: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14b438u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14b43c: 0x93230007  lbu         $v1, 0x7($t9)
    ctx->pc = 0x14b43cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 7)));
    // 0x14b440: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14b440u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14b444: 0x93270006  lbu         $a3, 0x6($t9)
    ctx->pc = 0x14b444u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 6)));
    // 0x14b448: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14b448u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14b44c: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14b44cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14b450: 0x93280017  lbu         $t0, 0x17($t9)
    ctx->pc = 0x14b450u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 23)));
    // 0x14b454: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14b454u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14b458: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14b458u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14b45c: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14b45cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14b460: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14b460u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14b464: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14b464u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14b468: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14b468u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14b46c: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14b46cu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14b470: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14b470u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14b474: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14b474u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14b478: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14b478u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14b47c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14b47cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14b480: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14b480u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14b484: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14b484u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14b488: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14b488u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14b48c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14b48cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14b490: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14b490u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14b494: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14b494u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14b498: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14b498u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14b49c: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14b49cu;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14b4a0: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14b4a0u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14b4a4: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14b4a4u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14b4a8: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14b4a8u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14b4ac: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14b4acu;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14b4b0: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14b4b0u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14b4b4: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14b4b4u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14b4b8: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14b4b8u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14b4bc: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14b4bcu;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14b4c0: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14b4c0u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14b4c4: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14b4c4u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14b4c8: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14b4c8u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14b4cc: 0x7de30010  sq          $v1, 0x10($t7)
    ctx->pc = 0x14b4ccu;
    WRITE128(ADD32(GPR_U32(ctx, 15), 16), GPR_VEC(ctx, 3));
    // 0x14b4d0: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14b4d0u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14b4d4: 0x7de30050  sq          $v1, 0x50($t7)
    ctx->pc = 0x14b4d4u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 80), GPR_VEC(ctx, 3));
    // 0x14b4d8: 0x93270008  lbu         $a3, 0x8($t9)
    ctx->pc = 0x14b4d8u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 8)));
    // 0x14b4dc: 0x93280019  lbu         $t0, 0x19($t9)
    ctx->pc = 0x14b4dcu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 25)));
    // 0x14b4e0: 0x92120004  lbu         $s2, 0x4($s0)
    ctx->pc = 0x14b4e0u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x14b4e4: 0x92130044  lbu         $s3, 0x44($s0)
    ctx->pc = 0x14b4e4u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x14b4e8: 0x93230009  lbu         $v1, 0x9($t9)
    ctx->pc = 0x14b4e8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 9)));
    // 0x14b4ec: 0x93310018  lbu         $s1, 0x18($t9)
    ctx->pc = 0x14b4ecu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 24)));
    // 0x14b4f0: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14b4f0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14b4f4: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14b4f4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14b4f8: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14b4f8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14b4fc: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14b4fcu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14b500: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14b500u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14b504: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14b504u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14b508: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14b508u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14b50c: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14b50cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14b510: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14b510u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14b514: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14b514u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14b518: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14b518u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14b51c: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14b51cu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14b520: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14b520u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14b524: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14b524u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14b528: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14b528u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14b52c: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14b52cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14b530: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14b530u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14b534: 0x92120005  lbu         $s2, 0x5($s0)
    ctx->pc = 0x14b534u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 5)));
    // 0x14b538: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14b538u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14b53c: 0x92130045  lbu         $s3, 0x45($s0)
    ctx->pc = 0x14b53cu;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 69)));
    // 0x14b540: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14b540u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14b544: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14b544u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14b548: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14b548u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14b54c: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14b54cu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14b550: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14b550u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14b554: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14b554u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14b558: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14b558u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14b55c: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14b55cu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14b560: 0x9331001a  lbu         $s1, 0x1A($t9)
    ctx->pc = 0x14b560u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 26)));
    // 0x14b564: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14b564u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14b568: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14b568u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14b56c: 0x9323000b  lbu         $v1, 0xB($t9)
    ctx->pc = 0x14b56cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 11)));
    // 0x14b570: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14b570u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14b574: 0x9327000a  lbu         $a3, 0xA($t9)
    ctx->pc = 0x14b574u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 10)));
    // 0x14b578: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14b578u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14b57c: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14b57cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14b580: 0x9328001b  lbu         $t0, 0x1B($t9)
    ctx->pc = 0x14b580u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 27)));
    // 0x14b584: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14b584u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14b588: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14b588u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14b58c: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14b58cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14b590: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14b590u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14b594: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14b594u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14b598: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14b598u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14b59c: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14b59cu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14b5a0: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14b5a0u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14b5a4: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14b5a4u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14b5a8: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14b5a8u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14b5ac: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14b5acu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14b5b0: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14b5b0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14b5b4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14b5b4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14b5b8: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14b5b8u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14b5bc: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14b5bcu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14b5c0: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14b5c0u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14b5c4: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14b5c4u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14b5c8: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14b5c8u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14b5cc: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14b5ccu;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14b5d0: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14b5d0u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14b5d4: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14b5d4u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14b5d8: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14b5d8u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14b5dc: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14b5dcu;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14b5e0: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14b5e0u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14b5e4: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14b5e4u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14b5e8: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14b5e8u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14b5ec: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14b5ecu;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14b5f0: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14b5f0u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14b5f4: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14b5f4u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14b5f8: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14b5f8u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14b5fc: 0x7de30020  sq          $v1, 0x20($t7)
    ctx->pc = 0x14b5fcu;
    WRITE128(ADD32(GPR_U32(ctx, 15), 32), GPR_VEC(ctx, 3));
    // 0x14b600: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14b600u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14b604: 0x7de30060  sq          $v1, 0x60($t7)
    ctx->pc = 0x14b604u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 96), GPR_VEC(ctx, 3));
    // 0x14b608: 0x9327000c  lbu         $a3, 0xC($t9)
    ctx->pc = 0x14b608u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 12)));
    // 0x14b60c: 0x9328001d  lbu         $t0, 0x1D($t9)
    ctx->pc = 0x14b60cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 29)));
    // 0x14b610: 0x92120006  lbu         $s2, 0x6($s0)
    ctx->pc = 0x14b610u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x14b614: 0x92130046  lbu         $s3, 0x46($s0)
    ctx->pc = 0x14b614u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 70)));
    // 0x14b618: 0x9323000d  lbu         $v1, 0xD($t9)
    ctx->pc = 0x14b618u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 13)));
    // 0x14b61c: 0x9331001c  lbu         $s1, 0x1C($t9)
    ctx->pc = 0x14b61cu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 28)));
    // 0x14b620: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14b620u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14b624: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14b624u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14b628: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14b628u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14b62c: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14b62cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14b630: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14b630u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14b634: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14b634u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14b638: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14b638u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14b63c: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14b63cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14b640: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14b640u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14b644: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14b644u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14b648: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14b648u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14b64c: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14b64cu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14b650: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14b650u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14b654: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14b654u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14b658: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14b658u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14b65c: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14b65cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14b660: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14b660u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14b664: 0x92120007  lbu         $s2, 0x7($s0)
    ctx->pc = 0x14b664u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 7)));
    // 0x14b668: 0x92130047  lbu         $s3, 0x47($s0)
    ctx->pc = 0x14b668u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 71)));
    // 0x14b66c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14b66cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14b670: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14b670u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14b674: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14b674u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14b678: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14b678u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14b67c: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14b67cu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14b680: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14b680u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14b684: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14b684u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14b688: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14b688u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14b68c: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14b68cu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14b690: 0x9331001e  lbu         $s1, 0x1E($t9)
    ctx->pc = 0x14b690u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 30)));
    // 0x14b694: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14b694u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14b698: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14b698u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14b69c: 0x9323000f  lbu         $v1, 0xF($t9)
    ctx->pc = 0x14b69cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 15)));
    // 0x14b6a0: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14b6a0u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14b6a4: 0x9327000e  lbu         $a3, 0xE($t9)
    ctx->pc = 0x14b6a4u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 14)));
    // 0x14b6a8: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14b6a8u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14b6ac: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14b6acu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14b6b0: 0x9328001f  lbu         $t0, 0x1F($t9)
    ctx->pc = 0x14b6b0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 31)));
    // 0x14b6b4: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14b6b4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14b6b8: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14b6b8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14b6bc: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14b6bcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14b6c0: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14b6c0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14b6c4: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14b6c4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14b6c8: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14b6c8u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14b6cc: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14b6ccu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14b6d0: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14b6d0u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14b6d4: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14b6d4u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14b6d8: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14b6d8u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14b6dc: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14b6dcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14b6e0: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14b6e0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14b6e4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14b6e4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14b6e8: 0x67390020  daddiu      $t9, $t9, 0x20
    ctx->pc = 0x14b6e8u;
    SET_GPR_S64(ctx, 25, (int64_t)GPR_S64(ctx, 25) + (int64_t)(int32_t)32);
    // 0x14b6ec: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14b6ecu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14b6f0: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14b6f0u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14b6f4: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14b6f4u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14b6f8: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14b6f8u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14b6fc: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14b6fcu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14b700: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14b700u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14b704: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14b704u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14b708: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14b708u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14b70c: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14b70cu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14b710: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14b710u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14b714: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14b714u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14b718: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14b718u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14b71c: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14b71cu;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14b720: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14b720u;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14b724: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14b724u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14b728: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14b728u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14b72c: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14b72cu;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14b730: 0x7de30030  sq          $v1, 0x30($t7)
    ctx->pc = 0x14b730u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 48), GPR_VEC(ctx, 3));
    // 0x14b734: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14b734u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14b738: 0x7de30070  sq          $v1, 0x70($t7)
    ctx->pc = 0x14b738u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 112), GPR_VEC(ctx, 3));
    // 0x14b73c: 0x66100008  daddiu      $s0, $s0, 0x8
    ctx->pc = 0x14b73cu;
    SET_GPR_S64(ctx, 16, (int64_t)GPR_S64(ctx, 16) + (int64_t)(int32_t)8);
    // 0x14b740: 0x14783c  dsll32      $t7, $s4, 0
    ctx->pc = 0x14b740u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 20) << (32 + 0));
    // 0x14b744: 0xf783e  dsrl32      $t7, $t7, 0
    ctx->pc = 0x14b744u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 15) >> (32 + 0));
    // 0x14b748: 0xcf200060  pref        0x00, 0x60($t9)
    ctx->pc = 0x14b748u;
    // PREF instruction (ignored)
    // 0x14b74c: 0xcf000100  pref        0x00, 0x100($t8)
    ctx->pc = 0x14b74cu;
    // PREF instruction (ignored)
    // 0x14b750: 0xcf000140  pref        0x00, 0x140($t8)
    ctx->pc = 0x14b750u;
    // PREF instruction (ignored)
    // 0x14b754: 0x24540200  addiu       $s4, $v0, 0x200
    ctx->pc = 0x14b754u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 512));
    // 0x14b758: 0x93270000  lbu         $a3, 0x0($t9)
    ctx->pc = 0x14b758u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 0)));
    // 0x14b75c: 0x93280011  lbu         $t0, 0x11($t9)
    ctx->pc = 0x14b75cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 17)));
    // 0x14b760: 0x92120000  lbu         $s2, 0x0($s0)
    ctx->pc = 0x14b760u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x14b764: 0x92130040  lbu         $s3, 0x40($s0)
    ctx->pc = 0x14b764u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x14b768: 0x93230001  lbu         $v1, 0x1($t9)
    ctx->pc = 0x14b768u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 1)));
    // 0x14b76c: 0x93310010  lbu         $s1, 0x10($t9)
    ctx->pc = 0x14b76cu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 16)));
    // 0x14b770: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14b770u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14b774: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14b774u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14b778: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14b778u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14b77c: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14b77cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14b780: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14b780u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14b784: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14b784u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14b788: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14b788u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14b78c: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14b78cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14b790: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14b790u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14b794: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14b794u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14b798: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14b798u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14b79c: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14b79cu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14b7a0: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14b7a0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14b7a4: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14b7a4u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14b7a8: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14b7a8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14b7ac: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14b7acu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14b7b0: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14b7b0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14b7b4: 0x92120001  lbu         $s2, 0x1($s0)
    ctx->pc = 0x14b7b4u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x14b7b8: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14b7b8u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14b7bc: 0x92130041  lbu         $s3, 0x41($s0)
    ctx->pc = 0x14b7bcu;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 65)));
    // 0x14b7c0: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14b7c0u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14b7c4: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14b7c4u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14b7c8: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14b7c8u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14b7cc: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14b7ccu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14b7d0: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14b7d0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14b7d4: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14b7d4u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14b7d8: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14b7d8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14b7dc: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14b7dcu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14b7e0: 0x93310012  lbu         $s1, 0x12($t9)
    ctx->pc = 0x14b7e0u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 18)));
    // 0x14b7e4: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14b7e4u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14b7e8: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14b7e8u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14b7ec: 0x93230003  lbu         $v1, 0x3($t9)
    ctx->pc = 0x14b7ecu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 3)));
    // 0x14b7f0: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14b7f0u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14b7f4: 0x93270002  lbu         $a3, 0x2($t9)
    ctx->pc = 0x14b7f4u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 2)));
    // 0x14b7f8: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14b7f8u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14b7fc: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14b7fcu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14b800: 0x93280013  lbu         $t0, 0x13($t9)
    ctx->pc = 0x14b800u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 19)));
    // 0x14b804: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14b804u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14b808: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14b808u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14b80c: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14b80cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14b810: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14b810u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14b814: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14b814u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14b818: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14b818u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14b81c: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14b81cu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14b820: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14b820u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14b824: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14b824u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14b828: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14b828u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14b82c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14b82cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14b830: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14b830u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14b834: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14b834u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14b838: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14b838u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14b83c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14b83cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14b840: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14b840u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14b844: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14b844u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14b848: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14b848u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14b84c: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14b84cu;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14b850: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14b850u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14b854: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14b854u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14b858: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14b858u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14b85c: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14b85cu;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14b860: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14b860u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14b864: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14b864u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14b868: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14b868u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14b86c: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14b86cu;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14b870: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14b870u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14b874: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14b874u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14b878: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14b878u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14b87c: 0x7de30000  sq          $v1, 0x0($t7)
    ctx->pc = 0x14b87cu;
    WRITE128(ADD32(GPR_U32(ctx, 15), 0), GPR_VEC(ctx, 3));
    // 0x14b880: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14b880u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14b884: 0x7de30040  sq          $v1, 0x40($t7)
    ctx->pc = 0x14b884u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 64), GPR_VEC(ctx, 3));
    // 0x14b888: 0x93270004  lbu         $a3, 0x4($t9)
    ctx->pc = 0x14b888u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 4)));
    // 0x14b88c: 0x93280015  lbu         $t0, 0x15($t9)
    ctx->pc = 0x14b88cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 21)));
    // 0x14b890: 0x92120002  lbu         $s2, 0x2($s0)
    ctx->pc = 0x14b890u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x14b894: 0x92130042  lbu         $s3, 0x42($s0)
    ctx->pc = 0x14b894u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x14b898: 0x93230005  lbu         $v1, 0x5($t9)
    ctx->pc = 0x14b898u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 5)));
    // 0x14b89c: 0x93310014  lbu         $s1, 0x14($t9)
    ctx->pc = 0x14b89cu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 20)));
    // 0x14b8a0: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14b8a0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14b8a4: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14b8a4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14b8a8: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14b8a8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14b8ac: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14b8acu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14b8b0: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14b8b0u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14b8b4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14b8b4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14b8b8: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14b8b8u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14b8bc: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14b8bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14b8c0: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14b8c0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14b8c4: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14b8c4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14b8c8: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14b8c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14b8cc: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14b8ccu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14b8d0: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14b8d0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14b8d4: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14b8d4u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14b8d8: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14b8d8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14b8dc: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14b8dcu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14b8e0: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14b8e0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14b8e4: 0x92120003  lbu         $s2, 0x3($s0)
    ctx->pc = 0x14b8e4u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x14b8e8: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14b8e8u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14b8ec: 0x92130043  lbu         $s3, 0x43($s0)
    ctx->pc = 0x14b8ecu;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 67)));
    // 0x14b8f0: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14b8f0u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14b8f4: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14b8f4u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14b8f8: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14b8f8u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14b8fc: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14b8fcu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14b900: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14b900u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14b904: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14b904u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14b908: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14b908u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14b90c: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14b90cu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14b910: 0x93310016  lbu         $s1, 0x16($t9)
    ctx->pc = 0x14b910u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 22)));
    // 0x14b914: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14b914u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14b918: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14b918u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14b91c: 0x93230007  lbu         $v1, 0x7($t9)
    ctx->pc = 0x14b91cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 7)));
    // 0x14b920: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14b920u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14b924: 0x93270006  lbu         $a3, 0x6($t9)
    ctx->pc = 0x14b924u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 6)));
    // 0x14b928: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14b928u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14b92c: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14b92cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14b930: 0x93280017  lbu         $t0, 0x17($t9)
    ctx->pc = 0x14b930u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 23)));
    // 0x14b934: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14b934u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14b938: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14b938u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14b93c: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14b93cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14b940: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14b940u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14b944: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14b944u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14b948: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14b948u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14b94c: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14b94cu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14b950: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14b950u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14b954: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14b954u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14b958: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14b958u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14b95c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14b95cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14b960: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14b960u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14b964: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14b964u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14b968: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14b968u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14b96c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14b96cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14b970: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14b970u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14b974: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14b974u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14b978: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14b978u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14b97c: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14b97cu;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14b980: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14b980u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14b984: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14b984u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14b988: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14b988u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14b98c: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14b98cu;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14b990: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14b990u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14b994: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14b994u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14b998: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14b998u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14b99c: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14b99cu;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14b9a0: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14b9a0u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14b9a4: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14b9a4u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14b9a8: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14b9a8u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14b9ac: 0x7de30010  sq          $v1, 0x10($t7)
    ctx->pc = 0x14b9acu;
    WRITE128(ADD32(GPR_U32(ctx, 15), 16), GPR_VEC(ctx, 3));
    // 0x14b9b0: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14b9b0u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14b9b4: 0x7de30050  sq          $v1, 0x50($t7)
    ctx->pc = 0x14b9b4u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 80), GPR_VEC(ctx, 3));
    // 0x14b9b8: 0x93270008  lbu         $a3, 0x8($t9)
    ctx->pc = 0x14b9b8u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 8)));
    // 0x14b9bc: 0x93280019  lbu         $t0, 0x19($t9)
    ctx->pc = 0x14b9bcu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 25)));
    // 0x14b9c0: 0x92120004  lbu         $s2, 0x4($s0)
    ctx->pc = 0x14b9c0u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x14b9c4: 0x92130044  lbu         $s3, 0x44($s0)
    ctx->pc = 0x14b9c4u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x14b9c8: 0x93230009  lbu         $v1, 0x9($t9)
    ctx->pc = 0x14b9c8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 9)));
    // 0x14b9cc: 0x93310018  lbu         $s1, 0x18($t9)
    ctx->pc = 0x14b9ccu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 24)));
    // 0x14b9d0: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14b9d0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14b9d4: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14b9d4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14b9d8: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14b9d8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14b9dc: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14b9dcu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14b9e0: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14b9e0u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14b9e4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14b9e4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14b9e8: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14b9e8u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14b9ec: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14b9ecu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14b9f0: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14b9f0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14b9f4: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14b9f4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14b9f8: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14b9f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14b9fc: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14b9fcu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14ba00: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14ba00u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14ba04: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14ba04u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14ba08: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14ba08u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14ba0c: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14ba0cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14ba10: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14ba10u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14ba14: 0x92120005  lbu         $s2, 0x5($s0)
    ctx->pc = 0x14ba14u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 5)));
    // 0x14ba18: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14ba18u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14ba1c: 0x92130045  lbu         $s3, 0x45($s0)
    ctx->pc = 0x14ba1cu;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 69)));
    // 0x14ba20: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14ba20u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14ba24: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14ba24u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14ba28: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14ba28u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14ba2c: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14ba2cu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14ba30: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14ba30u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14ba34: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14ba34u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14ba38: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14ba38u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14ba3c: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14ba3cu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14ba40: 0x9331001a  lbu         $s1, 0x1A($t9)
    ctx->pc = 0x14ba40u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 26)));
    // 0x14ba44: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14ba44u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14ba48: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14ba48u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14ba4c: 0x9323000b  lbu         $v1, 0xB($t9)
    ctx->pc = 0x14ba4cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 11)));
    // 0x14ba50: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14ba50u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14ba54: 0x9327000a  lbu         $a3, 0xA($t9)
    ctx->pc = 0x14ba54u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 10)));
    // 0x14ba58: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14ba58u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14ba5c: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14ba5cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14ba60: 0x9328001b  lbu         $t0, 0x1B($t9)
    ctx->pc = 0x14ba60u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 27)));
    // 0x14ba64: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14ba64u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14ba68: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14ba68u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14ba6c: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14ba6cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14ba70: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14ba70u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14ba74: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14ba74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14ba78: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14ba78u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14ba7c: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14ba7cu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14ba80: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14ba80u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14ba84: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14ba84u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14ba88: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14ba88u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14ba8c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14ba8cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14ba90: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14ba90u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14ba94: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14ba94u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14ba98: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14ba98u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14ba9c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14ba9cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14baa0: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14baa0u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14baa4: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14baa4u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14baa8: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14baa8u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14baac: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14baacu;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14bab0: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14bab0u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14bab4: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14bab4u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14bab8: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14bab8u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14babc: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14babcu;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14bac0: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14bac0u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14bac4: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14bac4u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14bac8: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14bac8u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14bacc: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14baccu;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14bad0: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14bad0u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14bad4: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14bad4u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14bad8: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14bad8u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14badc: 0x7de30020  sq          $v1, 0x20($t7)
    ctx->pc = 0x14badcu;
    WRITE128(ADD32(GPR_U32(ctx, 15), 32), GPR_VEC(ctx, 3));
    // 0x14bae0: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14bae0u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14bae4: 0x7de30060  sq          $v1, 0x60($t7)
    ctx->pc = 0x14bae4u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 96), GPR_VEC(ctx, 3));
    // 0x14bae8: 0x9327000c  lbu         $a3, 0xC($t9)
    ctx->pc = 0x14bae8u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 12)));
    // 0x14baec: 0x9328001d  lbu         $t0, 0x1D($t9)
    ctx->pc = 0x14baecu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 29)));
    // 0x14baf0: 0x92120006  lbu         $s2, 0x6($s0)
    ctx->pc = 0x14baf0u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x14baf4: 0x92130046  lbu         $s3, 0x46($s0)
    ctx->pc = 0x14baf4u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 70)));
    // 0x14baf8: 0x9323000d  lbu         $v1, 0xD($t9)
    ctx->pc = 0x14baf8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 13)));
    // 0x14bafc: 0x9331001c  lbu         $s1, 0x1C($t9)
    ctx->pc = 0x14bafcu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 28)));
    // 0x14bb00: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14bb00u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14bb04: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14bb04u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14bb08: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14bb08u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14bb0c: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14bb0cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14bb10: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14bb10u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14bb14: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14bb14u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14bb18: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14bb18u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14bb1c: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14bb1cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14bb20: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14bb20u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14bb24: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14bb24u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14bb28: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14bb28u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14bb2c: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14bb2cu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14bb30: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14bb30u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14bb34: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14bb34u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14bb38: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14bb38u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14bb3c: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14bb3cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14bb40: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14bb40u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14bb44: 0x92120007  lbu         $s2, 0x7($s0)
    ctx->pc = 0x14bb44u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 7)));
    // 0x14bb48: 0x92130047  lbu         $s3, 0x47($s0)
    ctx->pc = 0x14bb48u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 71)));
    // 0x14bb4c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14bb4cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14bb50: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14bb50u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14bb54: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14bb54u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14bb58: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14bb58u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14bb5c: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14bb5cu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14bb60: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14bb60u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14bb64: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14bb64u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14bb68: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14bb68u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14bb6c: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14bb6cu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14bb70: 0x9331001e  lbu         $s1, 0x1E($t9)
    ctx->pc = 0x14bb70u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 30)));
    // 0x14bb74: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14bb74u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14bb78: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14bb78u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14bb7c: 0x9323000f  lbu         $v1, 0xF($t9)
    ctx->pc = 0x14bb7cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 15)));
    // 0x14bb80: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14bb80u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14bb84: 0x9327000e  lbu         $a3, 0xE($t9)
    ctx->pc = 0x14bb84u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 14)));
    // 0x14bb88: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14bb88u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14bb8c: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14bb8cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14bb90: 0x9328001f  lbu         $t0, 0x1F($t9)
    ctx->pc = 0x14bb90u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 31)));
    // 0x14bb94: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14bb94u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14bb98: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14bb98u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14bb9c: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14bb9cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14bba0: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14bba0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14bba4: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14bba4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14bba8: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14bba8u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14bbac: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14bbacu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14bbb0: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14bbb0u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14bbb4: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14bbb4u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14bbb8: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14bbb8u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14bbbc: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14bbbcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14bbc0: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14bbc0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14bbc4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14bbc4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14bbc8: 0x67390020  daddiu      $t9, $t9, 0x20
    ctx->pc = 0x14bbc8u;
    SET_GPR_S64(ctx, 25, (int64_t)GPR_S64(ctx, 25) + (int64_t)(int32_t)32);
    // 0x14bbcc: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14bbccu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14bbd0: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14bbd0u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14bbd4: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14bbd4u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14bbd8: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14bbd8u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14bbdc: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14bbdcu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14bbe0: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14bbe0u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14bbe4: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14bbe4u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14bbe8: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14bbe8u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14bbec: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14bbecu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14bbf0: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14bbf0u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14bbf4: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14bbf4u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14bbf8: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14bbf8u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14bbfc: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14bbfcu;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14bc00: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14bc00u;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14bc04: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14bc04u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14bc08: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14bc08u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14bc0c: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14bc0cu;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14bc10: 0x7de30030  sq          $v1, 0x30($t7)
    ctx->pc = 0x14bc10u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 48), GPR_VEC(ctx, 3));
    // 0x14bc14: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14bc14u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14bc18: 0x7de30070  sq          $v1, 0x70($t7)
    ctx->pc = 0x14bc18u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 112), GPR_VEC(ctx, 3));
    // 0x14bc1c: 0x66100008  daddiu      $s0, $s0, 0x8
    ctx->pc = 0x14bc1cu;
    SET_GPR_S64(ctx, 16, (int64_t)GPR_S64(ctx, 16) + (int64_t)(int32_t)8);
    // 0x14bc20: 0x14783c  dsll32      $t7, $s4, 0
    ctx->pc = 0x14bc20u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 20) << (32 + 0));
    // 0x14bc24: 0xf783e  dsrl32      $t7, $t7, 0
    ctx->pc = 0x14bc24u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 15) >> (32 + 0));
    // 0x14bc28: 0xcf200080  pref        0x00, 0x80($t9)
    ctx->pc = 0x14bc28u;
    // PREF instruction (ignored)
    // 0x14bc2c: 0xcf000100  pref        0x00, 0x100($t8)
    ctx->pc = 0x14bc2cu;
    // PREF instruction (ignored)
    // 0x14bc30: 0xcf000140  pref        0x00, 0x140($t8)
    ctx->pc = 0x14bc30u;
    // PREF instruction (ignored)
    // 0x14bc34: 0x24540280  addiu       $s4, $v0, 0x280
    ctx->pc = 0x14bc34u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 640));
    // 0x14bc38: 0x93270000  lbu         $a3, 0x0($t9)
    ctx->pc = 0x14bc38u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 0)));
    // 0x14bc3c: 0x93280011  lbu         $t0, 0x11($t9)
    ctx->pc = 0x14bc3cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 17)));
    // 0x14bc40: 0x92120000  lbu         $s2, 0x0($s0)
    ctx->pc = 0x14bc40u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x14bc44: 0x92130040  lbu         $s3, 0x40($s0)
    ctx->pc = 0x14bc44u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x14bc48: 0x93230001  lbu         $v1, 0x1($t9)
    ctx->pc = 0x14bc48u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 1)));
    // 0x14bc4c: 0x93310010  lbu         $s1, 0x10($t9)
    ctx->pc = 0x14bc4cu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 16)));
    // 0x14bc50: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14bc50u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14bc54: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14bc54u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14bc58: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14bc58u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14bc5c: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14bc5cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14bc60: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14bc60u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14bc64: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14bc64u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14bc68: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14bc68u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14bc6c: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14bc6cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14bc70: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14bc70u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14bc74: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14bc74u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14bc78: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14bc78u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14bc7c: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14bc7cu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14bc80: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14bc80u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14bc84: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14bc84u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14bc88: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14bc88u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14bc8c: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14bc8cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14bc90: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14bc90u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14bc94: 0x92120001  lbu         $s2, 0x1($s0)
    ctx->pc = 0x14bc94u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x14bc98: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14bc98u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14bc9c: 0x92130041  lbu         $s3, 0x41($s0)
    ctx->pc = 0x14bc9cu;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 65)));
    // 0x14bca0: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14bca0u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14bca4: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14bca4u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14bca8: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14bca8u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14bcac: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14bcacu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14bcb0: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14bcb0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14bcb4: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14bcb4u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14bcb8: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14bcb8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14bcbc: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14bcbcu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14bcc0: 0x93310012  lbu         $s1, 0x12($t9)
    ctx->pc = 0x14bcc0u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 18)));
    // 0x14bcc4: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14bcc4u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14bcc8: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14bcc8u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14bccc: 0x93230003  lbu         $v1, 0x3($t9)
    ctx->pc = 0x14bcccu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 3)));
    // 0x14bcd0: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14bcd0u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14bcd4: 0x93270002  lbu         $a3, 0x2($t9)
    ctx->pc = 0x14bcd4u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 2)));
    // 0x14bcd8: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14bcd8u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14bcdc: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14bcdcu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14bce0: 0x93280013  lbu         $t0, 0x13($t9)
    ctx->pc = 0x14bce0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 19)));
    // 0x14bce4: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14bce4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14bce8: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14bce8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14bcec: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14bcecu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14bcf0: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14bcf0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14bcf4: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14bcf4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14bcf8: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14bcf8u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14bcfc: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14bcfcu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14bd00: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14bd00u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14bd04: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14bd04u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14bd08: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14bd08u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14bd0c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14bd0cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14bd10: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14bd10u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14bd14: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14bd14u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14bd18: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14bd18u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14bd1c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14bd1cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14bd20: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14bd20u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14bd24: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14bd24u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14bd28: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14bd28u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14bd2c: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14bd2cu;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14bd30: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14bd30u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14bd34: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14bd34u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14bd38: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14bd38u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14bd3c: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14bd3cu;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14bd40: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14bd40u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14bd44: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14bd44u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14bd48: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14bd48u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14bd4c: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14bd4cu;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14bd50: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14bd50u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14bd54: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14bd54u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14bd58: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14bd58u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14bd5c: 0x7de30000  sq          $v1, 0x0($t7)
    ctx->pc = 0x14bd5cu;
    WRITE128(ADD32(GPR_U32(ctx, 15), 0), GPR_VEC(ctx, 3));
    // 0x14bd60: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14bd60u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14bd64: 0x7de30040  sq          $v1, 0x40($t7)
    ctx->pc = 0x14bd64u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 64), GPR_VEC(ctx, 3));
    // 0x14bd68: 0x93270004  lbu         $a3, 0x4($t9)
    ctx->pc = 0x14bd68u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 4)));
    // 0x14bd6c: 0x93280015  lbu         $t0, 0x15($t9)
    ctx->pc = 0x14bd6cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 21)));
    // 0x14bd70: 0x92120002  lbu         $s2, 0x2($s0)
    ctx->pc = 0x14bd70u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x14bd74: 0x92130042  lbu         $s3, 0x42($s0)
    ctx->pc = 0x14bd74u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x14bd78: 0x93230005  lbu         $v1, 0x5($t9)
    ctx->pc = 0x14bd78u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 5)));
    // 0x14bd7c: 0x93310014  lbu         $s1, 0x14($t9)
    ctx->pc = 0x14bd7cu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 20)));
    // 0x14bd80: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14bd80u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14bd84: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14bd84u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14bd88: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14bd88u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14bd8c: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14bd8cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14bd90: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14bd90u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14bd94: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14bd94u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14bd98: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14bd98u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14bd9c: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14bd9cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14bda0: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14bda0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14bda4: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14bda4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14bda8: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14bda8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14bdac: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14bdacu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14bdb0: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14bdb0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14bdb4: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14bdb4u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14bdb8: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14bdb8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14bdbc: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14bdbcu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14bdc0: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14bdc0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14bdc4: 0x92120003  lbu         $s2, 0x3($s0)
    ctx->pc = 0x14bdc4u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x14bdc8: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14bdc8u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14bdcc: 0x92130043  lbu         $s3, 0x43($s0)
    ctx->pc = 0x14bdccu;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 67)));
    // 0x14bdd0: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14bdd0u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14bdd4: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14bdd4u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14bdd8: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14bdd8u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14bddc: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14bddcu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14bde0: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14bde0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14bde4: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14bde4u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14bde8: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14bde8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14bdec: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14bdecu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14bdf0: 0x93310016  lbu         $s1, 0x16($t9)
    ctx->pc = 0x14bdf0u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 22)));
    // 0x14bdf4: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14bdf4u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14bdf8: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14bdf8u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14bdfc: 0x93230007  lbu         $v1, 0x7($t9)
    ctx->pc = 0x14bdfcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 7)));
    // 0x14be00: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14be00u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14be04: 0x93270006  lbu         $a3, 0x6($t9)
    ctx->pc = 0x14be04u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 6)));
    // 0x14be08: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14be08u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14be0c: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14be0cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14be10: 0x93280017  lbu         $t0, 0x17($t9)
    ctx->pc = 0x14be10u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 23)));
    // 0x14be14: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14be14u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14be18: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14be18u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14be1c: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14be1cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14be20: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14be20u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14be24: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14be24u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14be28: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14be28u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14be2c: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14be2cu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14be30: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14be30u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14be34: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14be34u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14be38: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14be38u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14be3c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14be3cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14be40: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14be40u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14be44: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14be44u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14be48: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14be48u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14be4c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14be4cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14be50: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14be50u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14be54: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14be54u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14be58: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14be58u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14be5c: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14be5cu;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14be60: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14be60u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14be64: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14be64u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14be68: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14be68u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14be6c: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14be6cu;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14be70: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14be70u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14be74: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14be74u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14be78: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14be78u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14be7c: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14be7cu;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14be80: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14be80u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14be84: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14be84u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14be88: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14be88u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14be8c: 0x7de30010  sq          $v1, 0x10($t7)
    ctx->pc = 0x14be8cu;
    WRITE128(ADD32(GPR_U32(ctx, 15), 16), GPR_VEC(ctx, 3));
    // 0x14be90: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14be90u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14be94: 0x7de30050  sq          $v1, 0x50($t7)
    ctx->pc = 0x14be94u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 80), GPR_VEC(ctx, 3));
    // 0x14be98: 0x93270008  lbu         $a3, 0x8($t9)
    ctx->pc = 0x14be98u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 8)));
    // 0x14be9c: 0x93280019  lbu         $t0, 0x19($t9)
    ctx->pc = 0x14be9cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 25)));
    // 0x14bea0: 0x92120004  lbu         $s2, 0x4($s0)
    ctx->pc = 0x14bea0u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x14bea4: 0x92130044  lbu         $s3, 0x44($s0)
    ctx->pc = 0x14bea4u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x14bea8: 0x93230009  lbu         $v1, 0x9($t9)
    ctx->pc = 0x14bea8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 9)));
    // 0x14beac: 0x93310018  lbu         $s1, 0x18($t9)
    ctx->pc = 0x14beacu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 24)));
    // 0x14beb0: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14beb0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14beb4: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14beb4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14beb8: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14beb8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14bebc: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14bebcu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14bec0: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14bec0u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14bec4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14bec4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14bec8: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14bec8u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14becc: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14beccu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14bed0: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14bed0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14bed4: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14bed4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14bed8: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14bed8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14bedc: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14bedcu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14bee0: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14bee0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14bee4: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14bee4u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14bee8: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14bee8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14beec: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14beecu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14bef0: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14bef0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14bef4: 0x92120005  lbu         $s2, 0x5($s0)
    ctx->pc = 0x14bef4u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 5)));
    // 0x14bef8: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14bef8u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14befc: 0x92130045  lbu         $s3, 0x45($s0)
    ctx->pc = 0x14befcu;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 69)));
    // 0x14bf00: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14bf00u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14bf04: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14bf04u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14bf08: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14bf08u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14bf0c: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14bf0cu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14bf10: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14bf10u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14bf14: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14bf14u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14bf18: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14bf18u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14bf1c: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14bf1cu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14bf20: 0x9331001a  lbu         $s1, 0x1A($t9)
    ctx->pc = 0x14bf20u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 26)));
    // 0x14bf24: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14bf24u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14bf28: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14bf28u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14bf2c: 0x9323000b  lbu         $v1, 0xB($t9)
    ctx->pc = 0x14bf2cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 11)));
    // 0x14bf30: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14bf30u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14bf34: 0x9327000a  lbu         $a3, 0xA($t9)
    ctx->pc = 0x14bf34u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 10)));
    // 0x14bf38: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14bf38u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14bf3c: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14bf3cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14bf40: 0x9328001b  lbu         $t0, 0x1B($t9)
    ctx->pc = 0x14bf40u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 27)));
    // 0x14bf44: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14bf44u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14bf48: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14bf48u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14bf4c: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14bf4cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14bf50: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14bf50u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14bf54: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14bf54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14bf58: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14bf58u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14bf5c: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14bf5cu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14bf60: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14bf60u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14bf64: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14bf64u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14bf68: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14bf68u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14bf6c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14bf6cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14bf70: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14bf70u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14bf74: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14bf74u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14bf78: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14bf78u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14bf7c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14bf7cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14bf80: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14bf80u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14bf84: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14bf84u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14bf88: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14bf88u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14bf8c: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14bf8cu;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14bf90: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14bf90u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14bf94: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14bf94u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14bf98: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14bf98u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14bf9c: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14bf9cu;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14bfa0: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14bfa0u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14bfa4: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14bfa4u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14bfa8: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14bfa8u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14bfac: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14bfacu;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14bfb0: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14bfb0u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14bfb4: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14bfb4u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14bfb8: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14bfb8u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14bfbc: 0x7de30020  sq          $v1, 0x20($t7)
    ctx->pc = 0x14bfbcu;
    WRITE128(ADD32(GPR_U32(ctx, 15), 32), GPR_VEC(ctx, 3));
    // 0x14bfc0: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14bfc0u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14bfc4: 0x7de30060  sq          $v1, 0x60($t7)
    ctx->pc = 0x14bfc4u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 96), GPR_VEC(ctx, 3));
    // 0x14bfc8: 0x9327000c  lbu         $a3, 0xC($t9)
    ctx->pc = 0x14bfc8u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 12)));
    // 0x14bfcc: 0x9328001d  lbu         $t0, 0x1D($t9)
    ctx->pc = 0x14bfccu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 29)));
    // 0x14bfd0: 0x92120006  lbu         $s2, 0x6($s0)
    ctx->pc = 0x14bfd0u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x14bfd4: 0x92130046  lbu         $s3, 0x46($s0)
    ctx->pc = 0x14bfd4u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 70)));
    // 0x14bfd8: 0x9323000d  lbu         $v1, 0xD($t9)
    ctx->pc = 0x14bfd8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 13)));
    // 0x14bfdc: 0x9331001c  lbu         $s1, 0x1C($t9)
    ctx->pc = 0x14bfdcu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 28)));
    // 0x14bfe0: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14bfe0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14bfe4: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14bfe4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14bfe8: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14bfe8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14bfec: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14bfecu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14bff0: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14bff0u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14bff4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14bff4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14bff8: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14bff8u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14bffc: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14bffcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14c000: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14c000u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14c004: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14c004u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14c008: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14c008u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14c00c: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14c00cu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14c010: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14c010u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14c014: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14c014u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14c018: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14c018u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14c01c: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14c01cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14c020: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14c020u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14c024: 0x92120007  lbu         $s2, 0x7($s0)
    ctx->pc = 0x14c024u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 7)));
    // 0x14c028: 0x92130047  lbu         $s3, 0x47($s0)
    ctx->pc = 0x14c028u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 71)));
    // 0x14c02c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14c02cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14c030: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14c030u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14c034: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14c034u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14c038: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14c038u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14c03c: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14c03cu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14c040: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14c040u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14c044: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14c044u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14c048: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14c048u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14c04c: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14c04cu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14c050: 0x9331001e  lbu         $s1, 0x1E($t9)
    ctx->pc = 0x14c050u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 30)));
    // 0x14c054: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14c054u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14c058: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14c058u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14c05c: 0x9323000f  lbu         $v1, 0xF($t9)
    ctx->pc = 0x14c05cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 15)));
    // 0x14c060: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14c060u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14c064: 0x9327000e  lbu         $a3, 0xE($t9)
    ctx->pc = 0x14c064u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 14)));
    // 0x14c068: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14c068u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14c06c: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14c06cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14c070: 0x9328001f  lbu         $t0, 0x1F($t9)
    ctx->pc = 0x14c070u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 31)));
    // 0x14c074: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14c074u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14c078: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14c078u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14c07c: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14c07cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14c080: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14c080u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14c084: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14c084u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14c088: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14c088u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14c08c: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14c08cu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14c090: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14c090u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14c094: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14c094u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14c098: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14c098u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14c09c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14c09cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14c0a0: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14c0a0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14c0a4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14c0a4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14c0a8: 0x67390020  daddiu      $t9, $t9, 0x20
    ctx->pc = 0x14c0a8u;
    SET_GPR_S64(ctx, 25, (int64_t)GPR_S64(ctx, 25) + (int64_t)(int32_t)32);
    // 0x14c0ac: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14c0acu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14c0b0: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14c0b0u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14c0b4: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14c0b4u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14c0b8: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14c0b8u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14c0bc: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14c0bcu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14c0c0: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14c0c0u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14c0c4: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14c0c4u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14c0c8: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14c0c8u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14c0cc: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14c0ccu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14c0d0: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14c0d0u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14c0d4: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14c0d4u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14c0d8: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14c0d8u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14c0dc: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14c0dcu;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14c0e0: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14c0e0u;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14c0e4: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14c0e4u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14c0e8: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14c0e8u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14c0ec: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14c0ecu;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14c0f0: 0x7de30030  sq          $v1, 0x30($t7)
    ctx->pc = 0x14c0f0u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 48), GPR_VEC(ctx, 3));
    // 0x14c0f4: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14c0f4u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14c0f8: 0x7de30070  sq          $v1, 0x70($t7)
    ctx->pc = 0x14c0f8u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 112), GPR_VEC(ctx, 3));
    // 0x14c0fc: 0x66100008  daddiu      $s0, $s0, 0x8
    ctx->pc = 0x14c0fcu;
    SET_GPR_S64(ctx, 16, (int64_t)GPR_S64(ctx, 16) + (int64_t)(int32_t)8);
    // 0x14c100: 0x14783c  dsll32      $t7, $s4, 0
    ctx->pc = 0x14c100u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 20) << (32 + 0));
    // 0x14c104: 0xf783e  dsrl32      $t7, $t7, 0
    ctx->pc = 0x14c104u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 15) >> (32 + 0));
    // 0x14c108: 0xcf2000a0  pref        0x00, 0xA0($t9)
    ctx->pc = 0x14c108u;
    // PREF instruction (ignored)
    // 0x14c10c: 0xcf000100  pref        0x00, 0x100($t8)
    ctx->pc = 0x14c10cu;
    // PREF instruction (ignored)
    // 0x14c110: 0xcf000140  pref        0x00, 0x140($t8)
    ctx->pc = 0x14c110u;
    // PREF instruction (ignored)
    // 0x14c114: 0x24540300  addiu       $s4, $v0, 0x300
    ctx->pc = 0x14c114u;
    SET_GPR_S32(ctx, 20, (int32_t)ADD32(GPR_U32(ctx, 2), 768));
    // 0x14c118: 0x93270000  lbu         $a3, 0x0($t9)
    ctx->pc = 0x14c118u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 0)));
    // 0x14c11c: 0x93280011  lbu         $t0, 0x11($t9)
    ctx->pc = 0x14c11cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 17)));
    // 0x14c120: 0x92120000  lbu         $s2, 0x0($s0)
    ctx->pc = 0x14c120u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x14c124: 0x92130040  lbu         $s3, 0x40($s0)
    ctx->pc = 0x14c124u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x14c128: 0x93230001  lbu         $v1, 0x1($t9)
    ctx->pc = 0x14c128u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 1)));
    // 0x14c12c: 0x93310010  lbu         $s1, 0x10($t9)
    ctx->pc = 0x14c12cu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 16)));
    // 0x14c130: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14c130u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14c134: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14c134u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14c138: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14c138u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14c13c: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14c13cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14c140: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14c140u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14c144: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14c144u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14c148: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14c148u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14c14c: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14c14cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14c150: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14c150u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14c154: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14c154u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14c158: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14c158u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14c15c: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14c15cu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14c160: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14c160u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14c164: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14c164u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14c168: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14c168u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14c16c: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14c16cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14c170: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14c170u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14c174: 0x92120001  lbu         $s2, 0x1($s0)
    ctx->pc = 0x14c174u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x14c178: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14c178u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14c17c: 0x92130041  lbu         $s3, 0x41($s0)
    ctx->pc = 0x14c17cu;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 65)));
    // 0x14c180: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14c180u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14c184: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14c184u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14c188: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14c188u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14c18c: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14c18cu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14c190: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14c190u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14c194: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14c194u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14c198: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14c198u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14c19c: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14c19cu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14c1a0: 0x93310012  lbu         $s1, 0x12($t9)
    ctx->pc = 0x14c1a0u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 18)));
    // 0x14c1a4: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14c1a4u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14c1a8: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14c1a8u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14c1ac: 0x93230003  lbu         $v1, 0x3($t9)
    ctx->pc = 0x14c1acu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 3)));
    // 0x14c1b0: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14c1b0u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14c1b4: 0x93270002  lbu         $a3, 0x2($t9)
    ctx->pc = 0x14c1b4u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 2)));
    // 0x14c1b8: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14c1b8u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14c1bc: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14c1bcu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14c1c0: 0x93280013  lbu         $t0, 0x13($t9)
    ctx->pc = 0x14c1c0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 19)));
    // 0x14c1c4: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14c1c4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14c1c8: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14c1c8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14c1cc: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14c1ccu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14c1d0: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14c1d0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14c1d4: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14c1d4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14c1d8: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14c1d8u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14c1dc: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14c1dcu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14c1e0: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14c1e0u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14c1e4: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14c1e4u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14c1e8: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14c1e8u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14c1ec: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14c1ecu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14c1f0: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14c1f0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14c1f4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14c1f4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14c1f8: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14c1f8u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14c1fc: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14c1fcu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14c200: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14c200u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14c204: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14c204u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14c208: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14c208u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14c20c: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14c20cu;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14c210: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14c210u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14c214: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14c214u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14c218: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14c218u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14c21c: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14c21cu;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14c220: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14c220u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14c224: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14c224u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14c228: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14c228u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14c22c: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14c22cu;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14c230: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14c230u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14c234: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14c234u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14c238: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14c238u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14c23c: 0x7de30000  sq          $v1, 0x0($t7)
    ctx->pc = 0x14c23cu;
    WRITE128(ADD32(GPR_U32(ctx, 15), 0), GPR_VEC(ctx, 3));
    // 0x14c240: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14c240u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14c244: 0x7de30040  sq          $v1, 0x40($t7)
    ctx->pc = 0x14c244u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 64), GPR_VEC(ctx, 3));
    // 0x14c248: 0x93270004  lbu         $a3, 0x4($t9)
    ctx->pc = 0x14c248u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 4)));
    // 0x14c24c: 0x93280015  lbu         $t0, 0x15($t9)
    ctx->pc = 0x14c24cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 21)));
    // 0x14c250: 0x92120002  lbu         $s2, 0x2($s0)
    ctx->pc = 0x14c250u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x14c254: 0x92130042  lbu         $s3, 0x42($s0)
    ctx->pc = 0x14c254u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x14c258: 0x93230005  lbu         $v1, 0x5($t9)
    ctx->pc = 0x14c258u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 5)));
    // 0x14c25c: 0x93310014  lbu         $s1, 0x14($t9)
    ctx->pc = 0x14c25cu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 20)));
    // 0x14c260: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14c260u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14c264: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14c264u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14c268: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14c268u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14c26c: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14c26cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14c270: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14c270u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14c274: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14c274u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14c278: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14c278u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14c27c: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14c27cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14c280: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14c280u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14c284: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14c284u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14c288: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14c288u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14c28c: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14c28cu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14c290: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14c290u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14c294: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14c294u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14c298: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14c298u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14c29c: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14c29cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14c2a0: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14c2a0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14c2a4: 0x92120003  lbu         $s2, 0x3($s0)
    ctx->pc = 0x14c2a4u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x14c2a8: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14c2a8u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14c2ac: 0x92130043  lbu         $s3, 0x43($s0)
    ctx->pc = 0x14c2acu;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 67)));
    // 0x14c2b0: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14c2b0u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14c2b4: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14c2b4u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14c2b8: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14c2b8u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14c2bc: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14c2bcu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14c2c0: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14c2c0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14c2c4: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14c2c4u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14c2c8: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14c2c8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14c2cc: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14c2ccu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14c2d0: 0x93310016  lbu         $s1, 0x16($t9)
    ctx->pc = 0x14c2d0u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 22)));
    // 0x14c2d4: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14c2d4u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14c2d8: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14c2d8u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14c2dc: 0x93230007  lbu         $v1, 0x7($t9)
    ctx->pc = 0x14c2dcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 7)));
    // 0x14c2e0: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14c2e0u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14c2e4: 0x93270006  lbu         $a3, 0x6($t9)
    ctx->pc = 0x14c2e4u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 6)));
    // 0x14c2e8: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14c2e8u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14c2ec: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14c2ecu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14c2f0: 0x93280017  lbu         $t0, 0x17($t9)
    ctx->pc = 0x14c2f0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 23)));
    // 0x14c2f4: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14c2f4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14c2f8: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14c2f8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14c2fc: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14c2fcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14c300: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14c300u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14c304: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14c304u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14c308: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14c308u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14c30c: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14c30cu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14c310: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14c310u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14c314: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14c314u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14c318: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14c318u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14c31c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14c31cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14c320: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14c320u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14c324: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14c324u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14c328: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14c328u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14c32c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14c32cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14c330: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14c330u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14c334: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14c334u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14c338: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14c338u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14c33c: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14c33cu;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14c340: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14c340u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14c344: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14c344u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14c348: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14c348u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14c34c: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14c34cu;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14c350: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14c350u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14c354: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14c354u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14c358: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14c358u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14c35c: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14c35cu;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14c360: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14c360u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14c364: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14c364u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14c368: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14c368u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14c36c: 0x7de30010  sq          $v1, 0x10($t7)
    ctx->pc = 0x14c36cu;
    WRITE128(ADD32(GPR_U32(ctx, 15), 16), GPR_VEC(ctx, 3));
    // 0x14c370: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14c370u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14c374: 0x7de30050  sq          $v1, 0x50($t7)
    ctx->pc = 0x14c374u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 80), GPR_VEC(ctx, 3));
    // 0x14c378: 0x93270008  lbu         $a3, 0x8($t9)
    ctx->pc = 0x14c378u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 8)));
    // 0x14c37c: 0x93280019  lbu         $t0, 0x19($t9)
    ctx->pc = 0x14c37cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 25)));
    // 0x14c380: 0x92120004  lbu         $s2, 0x4($s0)
    ctx->pc = 0x14c380u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x14c384: 0x92130044  lbu         $s3, 0x44($s0)
    ctx->pc = 0x14c384u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x14c388: 0x93230009  lbu         $v1, 0x9($t9)
    ctx->pc = 0x14c388u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 9)));
    // 0x14c38c: 0x93310018  lbu         $s1, 0x18($t9)
    ctx->pc = 0x14c38cu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 24)));
    // 0x14c390: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14c390u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14c394: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14c394u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14c398: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14c398u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14c39c: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14c39cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14c3a0: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14c3a0u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14c3a4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14c3a4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14c3a8: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14c3a8u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14c3ac: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14c3acu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14c3b0: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14c3b0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14c3b4: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14c3b4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14c3b8: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14c3b8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14c3bc: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14c3bcu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14c3c0: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14c3c0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14c3c4: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14c3c4u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14c3c8: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14c3c8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14c3cc: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14c3ccu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14c3d0: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14c3d0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14c3d4: 0x92120005  lbu         $s2, 0x5($s0)
    ctx->pc = 0x14c3d4u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 5)));
    // 0x14c3d8: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14c3d8u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14c3dc: 0x92130045  lbu         $s3, 0x45($s0)
    ctx->pc = 0x14c3dcu;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 69)));
    // 0x14c3e0: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14c3e0u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14c3e4: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14c3e4u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14c3e8: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14c3e8u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14c3ec: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14c3ecu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14c3f0: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14c3f0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14c3f4: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14c3f4u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14c3f8: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14c3f8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14c3fc: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14c3fcu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14c400: 0x9331001a  lbu         $s1, 0x1A($t9)
    ctx->pc = 0x14c400u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 26)));
    // 0x14c404: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14c404u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14c408: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14c408u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14c40c: 0x9323000b  lbu         $v1, 0xB($t9)
    ctx->pc = 0x14c40cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 11)));
    // 0x14c410: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14c410u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14c414: 0x9327000a  lbu         $a3, 0xA($t9)
    ctx->pc = 0x14c414u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 10)));
    // 0x14c418: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14c418u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14c41c: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14c41cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14c420: 0x9328001b  lbu         $t0, 0x1B($t9)
    ctx->pc = 0x14c420u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 27)));
    // 0x14c424: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14c424u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14c428: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14c428u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14c42c: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14c42cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14c430: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14c430u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14c434: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14c434u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14c438: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14c438u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14c43c: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14c43cu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14c440: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14c440u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14c444: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14c444u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14c448: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14c448u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14c44c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14c44cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14c450: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14c450u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14c454: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14c454u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14c458: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14c458u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14c45c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14c45cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14c460: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14c460u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14c464: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14c464u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14c468: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14c468u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14c46c: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14c46cu;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14c470: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14c470u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14c474: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14c474u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14c478: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14c478u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14c47c: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14c47cu;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14c480: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14c480u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14c484: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14c484u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14c488: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14c488u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14c48c: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14c48cu;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14c490: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14c490u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14c494: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14c494u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14c498: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14c498u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14c49c: 0x7de30020  sq          $v1, 0x20($t7)
    ctx->pc = 0x14c49cu;
    WRITE128(ADD32(GPR_U32(ctx, 15), 32), GPR_VEC(ctx, 3));
    // 0x14c4a0: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14c4a0u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14c4a4: 0x7de30060  sq          $v1, 0x60($t7)
    ctx->pc = 0x14c4a4u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 96), GPR_VEC(ctx, 3));
    // 0x14c4a8: 0x9327000c  lbu         $a3, 0xC($t9)
    ctx->pc = 0x14c4a8u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 12)));
    // 0x14c4ac: 0x9328001d  lbu         $t0, 0x1D($t9)
    ctx->pc = 0x14c4acu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 29)));
    // 0x14c4b0: 0x92120006  lbu         $s2, 0x6($s0)
    ctx->pc = 0x14c4b0u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x14c4b4: 0x92130046  lbu         $s3, 0x46($s0)
    ctx->pc = 0x14c4b4u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 70)));
    // 0x14c4b8: 0x9323000d  lbu         $v1, 0xD($t9)
    ctx->pc = 0x14c4b8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 13)));
    // 0x14c4bc: 0x9331001c  lbu         $s1, 0x1C($t9)
    ctx->pc = 0x14c4bcu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 28)));
    // 0x14c4c0: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14c4c0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14c4c4: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14c4c4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14c4c8: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14c4c8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14c4cc: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14c4ccu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14c4d0: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14c4d0u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14c4d4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14c4d4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14c4d8: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14c4d8u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14c4dc: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14c4dcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14c4e0: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14c4e0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14c4e4: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14c4e4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14c4e8: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14c4e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14c4ec: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14c4ecu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14c4f0: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14c4f0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14c4f4: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14c4f4u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14c4f8: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14c4f8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14c4fc: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14c4fcu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14c500: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14c500u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14c504: 0x92120007  lbu         $s2, 0x7($s0)
    ctx->pc = 0x14c504u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 7)));
    // 0x14c508: 0x92130047  lbu         $s3, 0x47($s0)
    ctx->pc = 0x14c508u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 71)));
    // 0x14c50c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14c50cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14c510: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14c510u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14c514: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14c514u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14c518: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14c518u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14c51c: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14c51cu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14c520: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14c520u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14c524: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14c524u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14c528: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14c528u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14c52c: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14c52cu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14c530: 0x9331001e  lbu         $s1, 0x1E($t9)
    ctx->pc = 0x14c530u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 30)));
    // 0x14c534: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14c534u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14c538: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14c538u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14c53c: 0x9323000f  lbu         $v1, 0xF($t9)
    ctx->pc = 0x14c53cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 15)));
    // 0x14c540: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14c540u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14c544: 0x9327000e  lbu         $a3, 0xE($t9)
    ctx->pc = 0x14c544u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 14)));
    // 0x14c548: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14c548u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14c54c: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14c54cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14c550: 0x9328001f  lbu         $t0, 0x1F($t9)
    ctx->pc = 0x14c550u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 31)));
    // 0x14c554: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14c554u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14c558: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14c558u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14c55c: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14c55cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14c560: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14c560u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14c564: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14c564u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14c568: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14c568u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14c56c: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14c56cu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14c570: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14c570u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14c574: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14c574u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14c578: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14c578u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14c57c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14c57cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14c580: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14c580u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14c584: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14c584u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14c588: 0x67390020  daddiu      $t9, $t9, 0x20
    ctx->pc = 0x14c588u;
    SET_GPR_S64(ctx, 25, (int64_t)GPR_S64(ctx, 25) + (int64_t)(int32_t)32);
    // 0x14c58c: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14c58cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14c590: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14c590u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14c594: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14c594u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14c598: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14c598u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14c59c: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14c59cu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14c5a0: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14c5a0u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14c5a4: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14c5a4u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14c5a8: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14c5a8u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14c5ac: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14c5acu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14c5b0: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14c5b0u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14c5b4: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14c5b4u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14c5b8: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14c5b8u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14c5bc: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14c5bcu;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14c5c0: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14c5c0u;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14c5c4: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14c5c4u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14c5c8: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14c5c8u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14c5cc: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14c5ccu;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14c5d0: 0x7de30030  sq          $v1, 0x30($t7)
    ctx->pc = 0x14c5d0u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 48), GPR_VEC(ctx, 3));
    // 0x14c5d4: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14c5d4u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14c5d8: 0x7de30070  sq          $v1, 0x70($t7)
    ctx->pc = 0x14c5d8u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 112), GPR_VEC(ctx, 3));
    // 0x14c5dc: 0x66100008  daddiu      $s0, $s0, 0x8
    ctx->pc = 0x14c5dcu;
    SET_GPR_S64(ctx, 16, (int64_t)GPR_S64(ctx, 16) + (int64_t)(int32_t)8);
    // 0x14c5e0: 0x14783c  dsll32      $t7, $s4, 0
    ctx->pc = 0x14c5e0u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 20) << (32 + 0));
    // 0x14c5e4: 0xf783e  dsrl32      $t7, $t7, 0
    ctx->pc = 0x14c5e4u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 15) >> (32 + 0));
    // 0x14c5e8: 0xcf2000c0  pref        0x00, 0xC0($t9)
    ctx->pc = 0x14c5e8u;
    // PREF instruction (ignored)
    // 0x14c5ec: 0xcf000100  pref        0x00, 0x100($t8)
    ctx->pc = 0x14c5ecu;
    // PREF instruction (ignored)
    // 0x14c5f0: 0xcf000140  pref        0x00, 0x140($t8)
    ctx->pc = 0x14c5f0u;
    // PREF instruction (ignored)
    // 0x14c5f4: 0x24450380  addiu       $a1, $v0, 0x380
    ctx->pc = 0x14c5f4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 2), 896));
    // 0x14c5f8: 0x93270000  lbu         $a3, 0x0($t9)
    ctx->pc = 0x14c5f8u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 0)));
    // 0x14c5fc: 0x93280011  lbu         $t0, 0x11($t9)
    ctx->pc = 0x14c5fcu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 17)));
    // 0x14c600: 0x92120000  lbu         $s2, 0x0($s0)
    ctx->pc = 0x14c600u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x14c604: 0x92130040  lbu         $s3, 0x40($s0)
    ctx->pc = 0x14c604u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x14c608: 0x93230001  lbu         $v1, 0x1($t9)
    ctx->pc = 0x14c608u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 1)));
    // 0x14c60c: 0x93310010  lbu         $s1, 0x10($t9)
    ctx->pc = 0x14c60cu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 16)));
    // 0x14c610: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14c610u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14c614: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14c614u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14c618: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14c618u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14c61c: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14c61cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14c620: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14c620u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14c624: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14c624u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14c628: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14c628u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14c62c: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14c62cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14c630: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14c630u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14c634: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14c634u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14c638: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14c638u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14c63c: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14c63cu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14c640: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14c640u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14c644: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14c644u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14c648: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14c648u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14c64c: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14c64cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14c650: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14c650u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14c654: 0x92120001  lbu         $s2, 0x1($s0)
    ctx->pc = 0x14c654u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x14c658: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14c658u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14c65c: 0x92130041  lbu         $s3, 0x41($s0)
    ctx->pc = 0x14c65cu;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 65)));
    // 0x14c660: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14c660u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14c664: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14c664u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14c668: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14c668u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14c66c: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14c66cu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14c670: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14c670u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14c674: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14c674u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14c678: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14c678u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14c67c: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14c67cu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14c680: 0x93310012  lbu         $s1, 0x12($t9)
    ctx->pc = 0x14c680u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 18)));
    // 0x14c684: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14c684u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14c688: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14c688u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14c68c: 0x93230003  lbu         $v1, 0x3($t9)
    ctx->pc = 0x14c68cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 3)));
    // 0x14c690: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14c690u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14c694: 0x93270002  lbu         $a3, 0x2($t9)
    ctx->pc = 0x14c694u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 2)));
    // 0x14c698: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14c698u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14c69c: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14c69cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14c6a0: 0x93280013  lbu         $t0, 0x13($t9)
    ctx->pc = 0x14c6a0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 19)));
    // 0x14c6a4: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14c6a4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14c6a8: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14c6a8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14c6ac: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14c6acu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14c6b0: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14c6b0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14c6b4: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14c6b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14c6b8: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14c6b8u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14c6bc: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14c6bcu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14c6c0: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14c6c0u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14c6c4: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14c6c4u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14c6c8: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14c6c8u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14c6cc: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14c6ccu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14c6d0: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14c6d0u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14c6d4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14c6d4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14c6d8: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14c6d8u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14c6dc: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14c6dcu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14c6e0: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14c6e0u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14c6e4: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14c6e4u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14c6e8: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14c6e8u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14c6ec: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14c6ecu;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14c6f0: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14c6f0u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14c6f4: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14c6f4u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14c6f8: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14c6f8u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14c6fc: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14c6fcu;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14c700: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14c700u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14c704: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14c704u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14c708: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14c708u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14c70c: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14c70cu;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14c710: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14c710u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14c714: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14c714u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14c718: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14c718u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14c71c: 0x7de30000  sq          $v1, 0x0($t7)
    ctx->pc = 0x14c71cu;
    WRITE128(ADD32(GPR_U32(ctx, 15), 0), GPR_VEC(ctx, 3));
    // 0x14c720: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14c720u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14c724: 0x7de30040  sq          $v1, 0x40($t7)
    ctx->pc = 0x14c724u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 64), GPR_VEC(ctx, 3));
    // 0x14c728: 0x93270004  lbu         $a3, 0x4($t9)
    ctx->pc = 0x14c728u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 4)));
    // 0x14c72c: 0x93280015  lbu         $t0, 0x15($t9)
    ctx->pc = 0x14c72cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 21)));
    // 0x14c730: 0x92120002  lbu         $s2, 0x2($s0)
    ctx->pc = 0x14c730u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x14c734: 0x92130042  lbu         $s3, 0x42($s0)
    ctx->pc = 0x14c734u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x14c738: 0x93230005  lbu         $v1, 0x5($t9)
    ctx->pc = 0x14c738u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 5)));
    // 0x14c73c: 0x93310014  lbu         $s1, 0x14($t9)
    ctx->pc = 0x14c73cu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 20)));
    // 0x14c740: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14c740u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14c744: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14c744u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14c748: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14c748u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14c74c: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14c74cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14c750: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14c750u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14c754: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14c754u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14c758: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14c758u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14c75c: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14c75cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14c760: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14c760u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14c764: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14c764u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14c768: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14c768u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14c76c: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14c76cu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14c770: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14c770u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14c774: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14c774u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14c778: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14c778u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14c77c: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14c77cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14c780: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14c780u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14c784: 0x92120003  lbu         $s2, 0x3($s0)
    ctx->pc = 0x14c784u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x14c788: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14c788u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14c78c: 0x92130043  lbu         $s3, 0x43($s0)
    ctx->pc = 0x14c78cu;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 67)));
    // 0x14c790: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14c790u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14c794: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14c794u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14c798: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14c798u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14c79c: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14c79cu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14c7a0: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14c7a0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14c7a4: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14c7a4u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14c7a8: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14c7a8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14c7ac: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14c7acu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14c7b0: 0x93310016  lbu         $s1, 0x16($t9)
    ctx->pc = 0x14c7b0u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 22)));
    // 0x14c7b4: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14c7b4u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14c7b8: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14c7b8u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14c7bc: 0x93230007  lbu         $v1, 0x7($t9)
    ctx->pc = 0x14c7bcu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 7)));
    // 0x14c7c0: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14c7c0u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14c7c4: 0x93270006  lbu         $a3, 0x6($t9)
    ctx->pc = 0x14c7c4u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 6)));
    // 0x14c7c8: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14c7c8u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14c7cc: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14c7ccu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14c7d0: 0x93280017  lbu         $t0, 0x17($t9)
    ctx->pc = 0x14c7d0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 23)));
    // 0x14c7d4: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14c7d4u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14c7d8: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14c7d8u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14c7dc: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14c7dcu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14c7e0: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14c7e0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14c7e4: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14c7e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14c7e8: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14c7e8u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14c7ec: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14c7ecu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14c7f0: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14c7f0u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14c7f4: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14c7f4u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14c7f8: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14c7f8u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14c7fc: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14c7fcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14c800: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14c800u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14c804: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14c804u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14c808: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14c808u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14c80c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14c80cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14c810: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14c810u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14c814: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14c814u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14c818: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14c818u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14c81c: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14c81cu;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14c820: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14c820u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14c824: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14c824u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14c828: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14c828u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14c82c: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14c82cu;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14c830: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14c830u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14c834: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14c834u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14c838: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14c838u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14c83c: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14c83cu;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14c840: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14c840u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14c844: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14c844u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14c848: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14c848u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14c84c: 0x7de30010  sq          $v1, 0x10($t7)
    ctx->pc = 0x14c84cu;
    WRITE128(ADD32(GPR_U32(ctx, 15), 16), GPR_VEC(ctx, 3));
    // 0x14c850: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14c850u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14c854: 0x7de30050  sq          $v1, 0x50($t7)
    ctx->pc = 0x14c854u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 80), GPR_VEC(ctx, 3));
    // 0x14c858: 0x93270008  lbu         $a3, 0x8($t9)
    ctx->pc = 0x14c858u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 8)));
    // 0x14c85c: 0x93280019  lbu         $t0, 0x19($t9)
    ctx->pc = 0x14c85cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 25)));
    // 0x14c860: 0x92120004  lbu         $s2, 0x4($s0)
    ctx->pc = 0x14c860u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x14c864: 0x92130044  lbu         $s3, 0x44($s0)
    ctx->pc = 0x14c864u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x14c868: 0x93230009  lbu         $v1, 0x9($t9)
    ctx->pc = 0x14c868u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 9)));
    // 0x14c86c: 0x93310018  lbu         $s1, 0x18($t9)
    ctx->pc = 0x14c86cu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 24)));
    // 0x14c870: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14c870u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14c874: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14c874u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14c878: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14c878u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14c87c: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14c87cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14c880: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14c880u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14c884: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14c884u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14c888: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14c888u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14c88c: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14c88cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14c890: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14c890u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14c894: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14c894u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14c898: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14c898u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14c89c: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14c89cu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14c8a0: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14c8a0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14c8a4: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14c8a4u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14c8a8: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14c8a8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14c8ac: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14c8acu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14c8b0: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14c8b0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14c8b4: 0x92120005  lbu         $s2, 0x5($s0)
    ctx->pc = 0x14c8b4u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 5)));
    // 0x14c8b8: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14c8b8u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14c8bc: 0x92130045  lbu         $s3, 0x45($s0)
    ctx->pc = 0x14c8bcu;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 69)));
    // 0x14c8c0: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14c8c0u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14c8c4: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14c8c4u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14c8c8: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14c8c8u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14c8cc: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14c8ccu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14c8d0: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14c8d0u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14c8d4: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14c8d4u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14c8d8: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14c8d8u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14c8dc: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14c8dcu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14c8e0: 0x9331001a  lbu         $s1, 0x1A($t9)
    ctx->pc = 0x14c8e0u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 26)));
    // 0x14c8e4: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14c8e4u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14c8e8: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14c8e8u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14c8ec: 0x9323000b  lbu         $v1, 0xB($t9)
    ctx->pc = 0x14c8ecu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 11)));
    // 0x14c8f0: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14c8f0u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14c8f4: 0x9327000a  lbu         $a3, 0xA($t9)
    ctx->pc = 0x14c8f4u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 10)));
    // 0x14c8f8: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14c8f8u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14c8fc: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14c8fcu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14c900: 0x9328001b  lbu         $t0, 0x1B($t9)
    ctx->pc = 0x14c900u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 27)));
    // 0x14c904: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14c904u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14c908: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14c908u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14c90c: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14c90cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14c910: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14c910u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14c914: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14c914u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14c918: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14c918u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14c91c: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14c91cu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14c920: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14c920u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14c924: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14c924u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14c928: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14c928u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14c92c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14c92cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14c930: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14c930u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14c934: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14c934u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14c938: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14c938u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14c93c: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14c93cu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14c940: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14c940u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14c944: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14c944u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14c948: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14c948u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14c94c: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14c94cu;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14c950: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14c950u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14c954: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14c954u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14c958: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14c958u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14c95c: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14c95cu;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14c960: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14c960u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14c964: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14c964u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14c968: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14c968u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14c96c: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14c96cu;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14c970: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14c970u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14c974: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14c974u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14c978: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14c978u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14c97c: 0x7de30020  sq          $v1, 0x20($t7)
    ctx->pc = 0x14c97cu;
    WRITE128(ADD32(GPR_U32(ctx, 15), 32), GPR_VEC(ctx, 3));
    // 0x14c980: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14c980u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14c984: 0x7de30060  sq          $v1, 0x60($t7)
    ctx->pc = 0x14c984u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 96), GPR_VEC(ctx, 3));
    // 0x14c988: 0x9327000c  lbu         $a3, 0xC($t9)
    ctx->pc = 0x14c988u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 12)));
    // 0x14c98c: 0x9328001d  lbu         $t0, 0x1D($t9)
    ctx->pc = 0x14c98cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 29)));
    // 0x14c990: 0x92120006  lbu         $s2, 0x6($s0)
    ctx->pc = 0x14c990u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x14c994: 0x92130046  lbu         $s3, 0x46($s0)
    ctx->pc = 0x14c994u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 70)));
    // 0x14c998: 0x9323000d  lbu         $v1, 0xD($t9)
    ctx->pc = 0x14c998u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 13)));
    // 0x14c99c: 0x9331001c  lbu         $s1, 0x1C($t9)
    ctx->pc = 0x14c99cu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 28)));
    // 0x14c9a0: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14c9a0u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14c9a4: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14c9a4u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14c9a8: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14c9a8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14c9ac: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14c9acu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14c9b0: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14c9b0u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14c9b4: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14c9b4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14c9b8: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14c9b8u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14c9bc: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14c9bcu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14c9c0: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14c9c0u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14c9c4: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14c9c4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14c9c8: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14c9c8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14c9cc: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14c9ccu;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14c9d0: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14c9d0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14c9d4: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14c9d4u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14c9d8: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14c9d8u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14c9dc: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14c9dcu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14c9e0: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14c9e0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14c9e4: 0x92120007  lbu         $s2, 0x7($s0)
    ctx->pc = 0x14c9e4u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 7)));
    // 0x14c9e8: 0x92130047  lbu         $s3, 0x47($s0)
    ctx->pc = 0x14c9e8u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 71)));
    // 0x14c9ec: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14c9ecu;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14c9f0: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14c9f0u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14c9f4: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14c9f4u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14c9f8: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14c9f8u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14c9fc: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14c9fcu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14ca00: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14ca00u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14ca04: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14ca04u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14ca08: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14ca08u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14ca0c: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14ca0cu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14ca10: 0x9331001e  lbu         $s1, 0x1E($t9)
    ctx->pc = 0x14ca10u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 30)));
    // 0x14ca14: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14ca14u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14ca18: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14ca18u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14ca1c: 0x9323000f  lbu         $v1, 0xF($t9)
    ctx->pc = 0x14ca1cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 15)));
    // 0x14ca20: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14ca20u;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14ca24: 0x9327000e  lbu         $a3, 0xE($t9)
    ctx->pc = 0x14ca24u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 14)));
    // 0x14ca28: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14ca28u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14ca2c: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14ca2cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14ca30: 0x9328001f  lbu         $t0, 0x1F($t9)
    ctx->pc = 0x14ca30u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 31)));
    // 0x14ca34: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14ca34u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14ca38: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14ca38u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14ca3c: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14ca3cu;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14ca40: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14ca40u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14ca44: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14ca44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14ca48: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14ca48u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14ca4c: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14ca4cu;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14ca50: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14ca50u;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14ca54: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14ca54u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14ca58: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14ca58u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14ca5c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14ca5cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14ca60: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14ca60u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14ca64: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14ca64u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14ca68: 0x67390020  daddiu      $t9, $t9, 0x20
    ctx->pc = 0x14ca68u;
    SET_GPR_S64(ctx, 25, (int64_t)GPR_S64(ctx, 25) + (int64_t)(int32_t)32);
    // 0x14ca6c: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14ca6cu;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14ca70: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14ca70u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14ca74: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14ca74u;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14ca78: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14ca78u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14ca7c: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14ca7cu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14ca80: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14ca80u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14ca84: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14ca84u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14ca88: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14ca88u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14ca8c: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14ca8cu;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14ca90: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14ca90u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14ca94: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14ca94u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14ca98: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14ca98u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14ca9c: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14ca9cu;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14caa0: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14caa0u;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14caa4: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14caa4u;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14caa8: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14caa8u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14caac: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14caacu;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14cab0: 0x7de30030  sq          $v1, 0x30($t7)
    ctx->pc = 0x14cab0u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 48), GPR_VEC(ctx, 3));
    // 0x14cab4: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14cab4u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14cab8: 0x7de30070  sq          $v1, 0x70($t7)
    ctx->pc = 0x14cab8u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 112), GPR_VEC(ctx, 3));
    // 0x14cabc: 0x66100008  daddiu      $s0, $s0, 0x8
    ctx->pc = 0x14cabcu;
    SET_GPR_S64(ctx, 16, (int64_t)GPR_S64(ctx, 16) + (int64_t)(int32_t)8);
    // 0x14cac0: 0x5783c  dsll32      $t7, $a1, 0
    ctx->pc = 0x14cac0u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 5) << (32 + 0));
    // 0x14cac4: 0xf783e  dsrl32      $t7, $t7, 0
    ctx->pc = 0x14cac4u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 15) >> (32 + 0));
    // 0x14cac8: 0xcf2000e0  pref        0x00, 0xE0($t9)
    ctx->pc = 0x14cac8u;
    // PREF instruction (ignored)
    // 0x14cacc: 0xcf000100  pref        0x00, 0x100($t8)
    ctx->pc = 0x14caccu;
    // PREF instruction (ignored)
    // 0x14cad0: 0xcf000140  pref        0x00, 0x140($t8)
    ctx->pc = 0x14cad0u;
    // PREF instruction (ignored)
    // 0x14cad4: 0x93270000  lbu         $a3, 0x0($t9)
    ctx->pc = 0x14cad4u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 0)));
    // 0x14cad8: 0x93280011  lbu         $t0, 0x11($t9)
    ctx->pc = 0x14cad8u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 17)));
    // 0x14cadc: 0x92120000  lbu         $s2, 0x0($s0)
    ctx->pc = 0x14cadcu;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x14cae0: 0x92130040  lbu         $s3, 0x40($s0)
    ctx->pc = 0x14cae0u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x14cae4: 0x93230001  lbu         $v1, 0x1($t9)
    ctx->pc = 0x14cae4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 1)));
    // 0x14cae8: 0x93310010  lbu         $s1, 0x10($t9)
    ctx->pc = 0x14cae8u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 16)));
    // 0x14caec: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14caecu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14caf0: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14caf0u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14caf4: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14caf4u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14caf8: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14caf8u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14cafc: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14cafcu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14cb00: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14cb00u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14cb04: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14cb04u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14cb08: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14cb08u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14cb0c: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14cb0cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14cb10: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14cb10u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14cb14: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14cb14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14cb18: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14cb18u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14cb1c: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14cb1cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14cb20: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14cb20u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14cb24: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14cb24u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14cb28: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14cb28u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14cb2c: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14cb2cu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14cb30: 0x92120001  lbu         $s2, 0x1($s0)
    ctx->pc = 0x14cb30u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x14cb34: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14cb34u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14cb38: 0x92130041  lbu         $s3, 0x41($s0)
    ctx->pc = 0x14cb38u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 65)));
    // 0x14cb3c: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14cb3cu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14cb40: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14cb40u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14cb44: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14cb44u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14cb48: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14cb48u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14cb4c: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14cb4cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14cb50: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14cb50u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14cb54: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14cb54u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14cb58: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14cb58u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14cb5c: 0x93310012  lbu         $s1, 0x12($t9)
    ctx->pc = 0x14cb5cu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 18)));
    // 0x14cb60: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14cb60u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14cb64: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14cb64u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14cb68: 0x93230003  lbu         $v1, 0x3($t9)
    ctx->pc = 0x14cb68u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 3)));
    // 0x14cb6c: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14cb6cu;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14cb70: 0x93270002  lbu         $a3, 0x2($t9)
    ctx->pc = 0x14cb70u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 2)));
    // 0x14cb74: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14cb74u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14cb78: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14cb78u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14cb7c: 0x93280013  lbu         $t0, 0x13($t9)
    ctx->pc = 0x14cb7cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 19)));
    // 0x14cb80: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14cb80u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14cb84: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14cb84u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14cb88: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14cb88u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14cb8c: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14cb8cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14cb90: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14cb90u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14cb94: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14cb94u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14cb98: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14cb98u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14cb9c: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14cb9cu;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14cba0: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14cba0u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14cba4: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14cba4u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14cba8: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14cba8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14cbac: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14cbacu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14cbb0: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14cbb0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14cbb4: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14cbb4u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14cbb8: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14cbb8u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14cbbc: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14cbbcu;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14cbc0: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14cbc0u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14cbc4: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14cbc4u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14cbc8: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14cbc8u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14cbcc: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14cbccu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14cbd0: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14cbd0u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14cbd4: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14cbd4u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14cbd8: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14cbd8u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14cbdc: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14cbdcu;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14cbe0: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14cbe0u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14cbe4: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14cbe4u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14cbe8: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14cbe8u;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14cbec: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14cbecu;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14cbf0: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14cbf0u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14cbf4: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14cbf4u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14cbf8: 0x7de30000  sq          $v1, 0x0($t7)
    ctx->pc = 0x14cbf8u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 0), GPR_VEC(ctx, 3));
    // 0x14cbfc: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14cbfcu;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14cc00: 0x7de30040  sq          $v1, 0x40($t7)
    ctx->pc = 0x14cc00u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 64), GPR_VEC(ctx, 3));
    // 0x14cc04: 0x93270004  lbu         $a3, 0x4($t9)
    ctx->pc = 0x14cc04u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 4)));
    // 0x14cc08: 0x93280015  lbu         $t0, 0x15($t9)
    ctx->pc = 0x14cc08u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 21)));
    // 0x14cc0c: 0x92120002  lbu         $s2, 0x2($s0)
    ctx->pc = 0x14cc0cu;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 2)));
    // 0x14cc10: 0x92130042  lbu         $s3, 0x42($s0)
    ctx->pc = 0x14cc10u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 66)));
    // 0x14cc14: 0x93230005  lbu         $v1, 0x5($t9)
    ctx->pc = 0x14cc14u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 5)));
    // 0x14cc18: 0x93310014  lbu         $s1, 0x14($t9)
    ctx->pc = 0x14cc18u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 20)));
    // 0x14cc1c: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14cc1cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14cc20: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14cc20u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14cc24: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14cc24u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14cc28: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14cc28u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14cc2c: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14cc2cu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14cc30: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14cc30u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14cc34: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14cc34u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14cc38: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14cc38u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14cc3c: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14cc3cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14cc40: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14cc40u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14cc44: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14cc44u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14cc48: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14cc48u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14cc4c: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14cc4cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14cc50: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14cc50u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14cc54: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14cc54u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14cc58: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14cc58u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14cc5c: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14cc5cu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14cc60: 0x92120003  lbu         $s2, 0x3($s0)
    ctx->pc = 0x14cc60u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 3)));
    // 0x14cc64: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14cc64u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14cc68: 0x92130043  lbu         $s3, 0x43($s0)
    ctx->pc = 0x14cc68u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 67)));
    // 0x14cc6c: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14cc6cu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14cc70: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14cc70u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14cc74: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14cc74u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14cc78: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14cc78u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14cc7c: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14cc7cu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14cc80: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14cc80u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14cc84: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14cc84u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14cc88: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14cc88u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14cc8c: 0x93310016  lbu         $s1, 0x16($t9)
    ctx->pc = 0x14cc8cu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 22)));
    // 0x14cc90: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14cc90u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14cc94: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14cc94u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14cc98: 0x93230007  lbu         $v1, 0x7($t9)
    ctx->pc = 0x14cc98u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 7)));
    // 0x14cc9c: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14cc9cu;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14cca0: 0x93270006  lbu         $a3, 0x6($t9)
    ctx->pc = 0x14cca0u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 6)));
    // 0x14cca4: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14cca4u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14cca8: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14cca8u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14ccac: 0x93280017  lbu         $t0, 0x17($t9)
    ctx->pc = 0x14ccacu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 23)));
    // 0x14ccb0: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14ccb0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14ccb4: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14ccb4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14ccb8: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14ccb8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14ccbc: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14ccbcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14ccc0: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14ccc0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14ccc4: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14ccc4u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14ccc8: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14ccc8u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14cccc: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14ccccu;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14ccd0: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14ccd0u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14ccd4: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14ccd4u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14ccd8: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14ccd8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14ccdc: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14ccdcu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14cce0: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14cce0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14cce4: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14cce4u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14cce8: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14cce8u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14ccec: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14ccecu;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14ccf0: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14ccf0u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14ccf4: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14ccf4u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14ccf8: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14ccf8u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14ccfc: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14ccfcu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14cd00: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14cd00u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14cd04: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14cd04u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14cd08: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14cd08u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14cd0c: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14cd0cu;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14cd10: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14cd10u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14cd14: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14cd14u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14cd18: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14cd18u;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14cd1c: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14cd1cu;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14cd20: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14cd20u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14cd24: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14cd24u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14cd28: 0x7de30010  sq          $v1, 0x10($t7)
    ctx->pc = 0x14cd28u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 16), GPR_VEC(ctx, 3));
    // 0x14cd2c: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14cd2cu;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14cd30: 0x7de30050  sq          $v1, 0x50($t7)
    ctx->pc = 0x14cd30u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 80), GPR_VEC(ctx, 3));
    // 0x14cd34: 0x93270008  lbu         $a3, 0x8($t9)
    ctx->pc = 0x14cd34u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 8)));
    // 0x14cd38: 0x93280019  lbu         $t0, 0x19($t9)
    ctx->pc = 0x14cd38u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 25)));
    // 0x14cd3c: 0x92120004  lbu         $s2, 0x4($s0)
    ctx->pc = 0x14cd3cu;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x14cd40: 0x92130044  lbu         $s3, 0x44($s0)
    ctx->pc = 0x14cd40u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x14cd44: 0x93230009  lbu         $v1, 0x9($t9)
    ctx->pc = 0x14cd44u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 9)));
    // 0x14cd48: 0x93310018  lbu         $s1, 0x18($t9)
    ctx->pc = 0x14cd48u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 24)));
    // 0x14cd4c: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14cd4cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14cd50: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14cd50u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14cd54: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14cd54u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14cd58: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14cd58u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14cd5c: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14cd5cu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14cd60: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14cd60u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14cd64: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14cd64u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14cd68: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14cd68u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14cd6c: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14cd6cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14cd70: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14cd70u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14cd74: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14cd74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14cd78: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14cd78u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14cd7c: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14cd7cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14cd80: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14cd80u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14cd84: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14cd84u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14cd88: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14cd88u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14cd8c: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14cd8cu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14cd90: 0x92120005  lbu         $s2, 0x5($s0)
    ctx->pc = 0x14cd90u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 5)));
    // 0x14cd94: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14cd94u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14cd98: 0x92130045  lbu         $s3, 0x45($s0)
    ctx->pc = 0x14cd98u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 69)));
    // 0x14cd9c: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14cd9cu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14cda0: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14cda0u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14cda4: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14cda4u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14cda8: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14cda8u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14cdac: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14cdacu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14cdb0: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14cdb0u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14cdb4: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14cdb4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14cdb8: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14cdb8u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14cdbc: 0x9331001a  lbu         $s1, 0x1A($t9)
    ctx->pc = 0x14cdbcu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 26)));
    // 0x14cdc0: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14cdc0u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14cdc4: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14cdc4u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14cdc8: 0x9323000b  lbu         $v1, 0xB($t9)
    ctx->pc = 0x14cdc8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 11)));
    // 0x14cdcc: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14cdccu;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14cdd0: 0x9327000a  lbu         $a3, 0xA($t9)
    ctx->pc = 0x14cdd0u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 10)));
    // 0x14cdd4: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14cdd4u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14cdd8: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14cdd8u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14cddc: 0x9328001b  lbu         $t0, 0x1B($t9)
    ctx->pc = 0x14cddcu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 27)));
    // 0x14cde0: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14cde0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14cde4: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14cde4u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14cde8: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14cde8u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14cdec: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14cdecu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14cdf0: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14cdf0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14cdf4: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14cdf4u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14cdf8: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14cdf8u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14cdfc: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14cdfcu;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14ce00: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14ce00u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14ce04: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14ce04u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14ce08: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14ce08u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14ce0c: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14ce0cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14ce10: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14ce10u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14ce14: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14ce14u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14ce18: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14ce18u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14ce1c: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14ce1cu;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14ce20: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14ce20u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14ce24: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14ce24u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14ce28: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14ce28u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14ce2c: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14ce2cu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14ce30: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14ce30u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14ce34: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14ce34u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14ce38: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14ce38u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14ce3c: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14ce3cu;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14ce40: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14ce40u;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14ce44: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14ce44u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14ce48: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14ce48u;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14ce4c: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14ce4cu;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14ce50: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14ce50u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14ce54: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14ce54u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14ce58: 0x7de30020  sq          $v1, 0x20($t7)
    ctx->pc = 0x14ce58u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 32), GPR_VEC(ctx, 3));
    // 0x14ce5c: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14ce5cu;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14ce60: 0x7de30060  sq          $v1, 0x60($t7)
    ctx->pc = 0x14ce60u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 96), GPR_VEC(ctx, 3));
    // 0x14ce64: 0x9327000c  lbu         $a3, 0xC($t9)
    ctx->pc = 0x14ce64u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 12)));
    // 0x14ce68: 0x9328001d  lbu         $t0, 0x1D($t9)
    ctx->pc = 0x14ce68u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 29)));
    // 0x14ce6c: 0x92120006  lbu         $s2, 0x6($s0)
    ctx->pc = 0x14ce6cu;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 6)));
    // 0x14ce70: 0x92130046  lbu         $s3, 0x46($s0)
    ctx->pc = 0x14ce70u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 70)));
    // 0x14ce74: 0x9323000d  lbu         $v1, 0xD($t9)
    ctx->pc = 0x14ce74u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 13)));
    // 0x14ce78: 0x9331001c  lbu         $s1, 0x1C($t9)
    ctx->pc = 0x14ce78u;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 28)));
    // 0x14ce7c: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14ce7cu;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14ce80: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14ce80u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14ce84: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14ce84u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14ce88: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14ce88u;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14ce8c: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14ce8cu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14ce90: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14ce90u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14ce94: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14ce94u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14ce98: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14ce98u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14ce9c: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14ce9cu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14cea0: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14cea0u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14cea4: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14cea4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14cea8: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14cea8u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14ceac: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14ceacu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14ceb0: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14ceb0u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14ceb4: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14ceb4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14ceb8: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14ceb8u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14cebc: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14cebcu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14cec0: 0x92120007  lbu         $s2, 0x7($s0)
    ctx->pc = 0x14cec0u;
    SET_GPR_U32(ctx, 18, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 7)));
    // 0x14cec4: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14cec4u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14cec8: 0x92130047  lbu         $s3, 0x47($s0)
    ctx->pc = 0x14cec8u;
    SET_GPR_U32(ctx, 19, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 71)));
    // 0x14cecc: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14ceccu;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14ced0: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14ced0u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14ced4: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14ced4u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14ced8: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14ced8u;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14cedc: 0x1290c0  sll         $s2, $s2, 3
    ctx->pc = 0x14cedcu;
    SET_GPR_S32(ctx, 18, (int32_t)SLL32(GPR_U32(ctx, 18), 3));
    // 0x14cee0: 0x1398c0  sll         $s3, $s3, 3
    ctx->pc = 0x14cee0u;
    SET_GPR_S32(ctx, 19, (int32_t)SLL32(GPR_U32(ctx, 19), 3));
    // 0x14cee4: 0xd29021  addu        $s2, $a2, $s2
    ctx->pc = 0x14cee4u;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 18)));
    // 0x14cee8: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14cee8u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14ceec: 0x9331001e  lbu         $s1, 0x1E($t9)
    ctx->pc = 0x14ceecu;
    SET_GPR_U32(ctx, 17, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 30)));
    // 0x14cef0: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14cef0u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14cef4: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14cef4u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14cef8: 0x9323000f  lbu         $v1, 0xF($t9)
    ctx->pc = 0x14cef8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 15)));
    // 0x14cefc: 0x70897508  paddsh      $t6, $a0, $t1
    ctx->pc = 0x14cefcu;
    SET_GPR_VEC(ctx, 14, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14cf00: 0x9327000e  lbu         $a3, 0xE($t9)
    ctx->pc = 0x14cf00u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 14)));
    // 0x14cf04: 0x710c69e8  pminh       $t5, $t0, $t4
    ctx->pc = 0x14cf04u;
    SET_GPR_VEC(ctx, 13, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14cf08: 0xde490800  ld          $t1, 0x800($s2)
    ctx->pc = 0x14cf08u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 18), 2048)));
    // 0x14cf0c: 0x9328001f  lbu         $t0, 0x1F($t9)
    ctx->pc = 0x14cf0cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 25), 31)));
    // 0x14cf10: 0x318c0  sll         $v1, $v1, 3
    ctx->pc = 0x14cf10u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 3));
    // 0x14cf14: 0x738c0  sll         $a3, $a3, 3
    ctx->pc = 0x14cf14u;
    SET_GPR_S32(ctx, 7, (int32_t)SLL32(GPR_U32(ctx, 7), 3));
    // 0x14cf18: 0xd39821  addu        $s3, $a2, $s3
    ctx->pc = 0x14cf18u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 19)));
    // 0x14cf1c: 0xc73821  addu        $a3, $a2, $a3
    ctx->pc = 0x14cf1cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 7)));
    // 0x14cf20: 0xc31821  addu        $v1, $a2, $v1
    ctx->pc = 0x14cf20u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14cf24: 0x1188c0  sll         $s1, $s1, 3
    ctx->pc = 0x14cf24u;
    SET_GPR_S32(ctx, 17, (int32_t)SLL32(GPR_U32(ctx, 17), 3));
    // 0x14cf28: 0xde6a1000  ld          $t2, 0x1000($s3)
    ctx->pc = 0x14cf28u;
    SET_GPR_U64(ctx, 10, READ64(ADD32(GPR_U32(ctx, 19), 4096)));
    // 0x14cf2c: 0x700e71b7  psrah       $t6, $t6, 6
    ctx->pc = 0x14cf2cu;
    SET_GPR_VEC(ctx, 14, _mm_srai_epi16(GPR_VEC(ctx, 14), 6));
    // 0x14cf30: 0xdce40000  ld          $a0, 0x0($a3)
    ctx->pc = 0x14cf30u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x14cf34: 0xdc630000  ld          $v1, 0x0($v1)
    ctx->pc = 0x14cf34u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14cf38: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14cf38u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14cf3c: 0xd18821  addu        $s1, $a2, $s1
    ctx->pc = 0x14cf3cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 17)));
    // 0x14cf40: 0xc84021  addu        $t0, $a2, $t0
    ctx->pc = 0x14cf40u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x14cf44: 0xdd070000  ld          $a3, 0x0($t0)
    ctx->pc = 0x14cf44u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x14cf48: 0x712a4d08  paddsh      $t1, $t1, $t2
    ctx->pc = 0x14cf48u;
    SET_GPR_VEC(ctx, 9, _mm_adds_epi16(GPR_VEC(ctx, 9), GPR_VEC(ctx, 10)));
    // 0x14cf4c: 0x71cb71c8  pmaxh       $t6, $t6, $t3
    ctx->pc = 0x14cf4cu;
    SET_GPR_VEC(ctx, 14, PS2_PMAXH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 11)));
    // 0x14cf50: 0x70641b89  pcpyld      $v1, $v1, $a0
    ctx->pc = 0x14cf50u;
    SET_GPR_VEC(ctx, 3, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 4)));
    // 0x14cf54: 0xde280000  ld          $t0, 0x0($s1)
    ctx->pc = 0x14cf54u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x14cf58: 0x71294b89  pcpyld      $t1, $t1, $t1
    ctx->pc = 0x14cf58u;
    SET_GPR_VEC(ctx, 9, PS2_PCPYLD(GPR_VEC(ctx, 9), GPR_VEC(ctx, 9)));
    // 0x14cf5c: 0x70691d08  paddsh      $v1, $v1, $t1
    ctx->pc = 0x14cf5cu;
    SET_GPR_VEC(ctx, 3, _mm_adds_epi16(GPR_VEC(ctx, 3), GPR_VEC(ctx, 9)));
    // 0x14cf60: 0x71cc71e8  pminh       $t6, $t6, $t4
    ctx->pc = 0x14cf60u;
    SET_GPR_VEC(ctx, 14, PS2_PMINH(GPR_VEC(ctx, 14), GPR_VEC(ctx, 12)));
    // 0x14cf64: 0x70e82389  pcpyld      $a0, $a3, $t0
    ctx->pc = 0x14cf64u;
    SET_GPR_VEC(ctx, 4, PS2_PCPYLD(GPR_VEC(ctx, 7), GPR_VEC(ctx, 8)));
    // 0x14cf68: 0x700339b7  psrah       $a3, $v1, 6
    ctx->pc = 0x14cf68u;
    SET_GPR_VEC(ctx, 7, _mm_srai_epi16(GPR_VEC(ctx, 3), 6));
    // 0x14cf6c: 0x70892508  paddsh      $a0, $a0, $t1
    ctx->pc = 0x14cf6cu;
    SET_GPR_VEC(ctx, 4, _mm_adds_epi16(GPR_VEC(ctx, 4), GPR_VEC(ctx, 9)));
    // 0x14cf70: 0x70eb41c8  pmaxh       $t0, $a3, $t3
    ctx->pc = 0x14cf70u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 7), GPR_VEC(ctx, 11)));
    // 0x14cf74: 0x700421b7  psrah       $a0, $a0, 6
    ctx->pc = 0x14cf74u;
    SET_GPR_VEC(ctx, 4, _mm_srai_epi16(GPR_VEC(ctx, 4), 6));
    // 0x14cf78: 0x710c19e8  pminh       $v1, $t0, $t4
    ctx->pc = 0x14cf78u;
    SET_GPR_VEC(ctx, 3, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 12)));
    // 0x14cf7c: 0x708b21c8  pmaxh       $a0, $a0, $t3
    ctx->pc = 0x14cf7cu;
    SET_GPR_VEC(ctx, 4, PS2_PMAXH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 11)));
    // 0x14cf80: 0x706d1ec8  ppacb       $v1, $v1, $t5
    ctx->pc = 0x14cf80u;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 3), GPR_VEC(ctx, 13)));
    // 0x14cf84: 0x708c21e8  pminh       $a0, $a0, $t4
    ctx->pc = 0x14cf84u;
    SET_GPR_VEC(ctx, 4, PS2_PMINH(GPR_VEC(ctx, 4), GPR_VEC(ctx, 12)));
    // 0x14cf88: 0x7de30030  sq          $v1, 0x30($t7)
    ctx->pc = 0x14cf88u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 48), GPR_VEC(ctx, 3));
    // 0x14cf8c: 0x708e1ec8  ppacb       $v1, $a0, $t6
    ctx->pc = 0x14cf8cu;
    SET_GPR_VEC(ctx, 3, PS2_PPACB(GPR_VEC(ctx, 4), GPR_VEC(ctx, 14)));
    // 0x14cf90: 0x7de30070  sq          $v1, 0x70($t7)
    ctx->pc = 0x14cf90u;
    WRITE128(ADD32(GPR_U32(ctx, 15), 112), GPR_VEC(ctx, 3));
    // 0x14cf94: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x14cf94u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14cf98: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x14cf98u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x14cf9c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x14cf9cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x14cfa0: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x14cfa0u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x14cfa4: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x14cfa4u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x14cfa8: 0xdfb50050  ld          $s5, 0x50($sp)
    ctx->pc = 0x14cfa8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x14cfac: 0x3e00008  jr          $ra
    ctx->pc = 0x14CFACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14CFB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14CFACu;
            // 0x14cfb0: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x14CFB4u;
    // 0x14cfb4: 0x0  nop
    ctx->pc = 0x14cfb4u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
