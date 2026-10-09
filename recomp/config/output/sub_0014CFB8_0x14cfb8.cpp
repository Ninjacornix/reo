#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0014CFB8
// Address: 0x14cfb8 - 0x14f6b0
void sub_0014CFB8_0x14cfb8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0014CFB8_0x14cfb8");
#endif

    ctx->pc = 0x14cfb8u;

    // 0x14cfb8: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x14cfb8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x14cfbc: 0xc0102d  daddu       $v0, $a2, $zero
    ctx->pc = 0x14cfbcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14cfc0: 0xffb40040  sd          $s4, 0x40($sp)
    ctx->pc = 0x14cfc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x14cfc4: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x14cfc4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14cfc8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x14cfc8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x14cfcc: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x14cfccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x14cfd0: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x14cfd0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x14cfd4: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x14cfd4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x14cfd8: 0x3c0300ff  lui         $v1, 0xFF
    ctx->pc = 0x14cfd8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)255 << 16));
    // 0x14cfdc: 0x346800ff  ori         $t0, $v1, 0xFF
    ctx->pc = 0x14cfdcu;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 3) | (uint64_t)(uint16_t)255);
    // 0x14cfe0: 0x8183c  dsll32      $v1, $t0, 0
    ctx->pc = 0x14cfe0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 8) << (32 + 0));
    // 0x14cfe4: 0x1031825  or          $v1, $t0, $v1
    ctx->pc = 0x14cfe4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 8) | GPR_U64(ctx, 3));
    // 0x14cfe8: 0x7063cb89  pcpyld      $t9, $v1, $v1
    ctx->pc = 0x14cfe8u;
    SET_GPR_VEC(ctx, 25, PS2_PCPYLD(GPR_VEC(ctx, 3), GPR_VEC(ctx, 3)));
    // 0x14cfec: 0x721084c9  pxor        $s0, $s0, $s0
    ctx->pc = 0x14cfecu;
    SET_GPR_VEC(ctx, 16, PS2_PXOR(GPR_VEC(ctx, 16), GPR_VEC(ctx, 16)));
    // 0x14cff0: 0xcc800100  pref        0x00, 0x100($a0)
    ctx->pc = 0x14cff0u;
    // PREF instruction (ignored)
    // 0x14cff4: 0xcc800140  pref        0x00, 0x140($a0)
    ctx->pc = 0x14cff4u;
    // PREF instruction (ignored)
    // 0x14cff8: 0x141840  sll         $v1, $s4, 1
    ctx->pc = 0x14cff8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 20), 1));
    // 0x14cffc: 0x546821  addu        $t5, $v0, $s4
    ctx->pc = 0x14cffcu;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 20)));
    // 0x14d000: 0x248e0100  addiu       $t6, $a0, 0x100
    ctx->pc = 0x14d000u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 4), 256));
    // 0x14d004: 0xcc800000  pref        0x00, 0x0($a0)
    ctx->pc = 0x14d004u;
    // PREF instruction (ignored)
    // 0x14d008: 0x25ce0008  addiu       $t6, $t6, 0x8
    ctx->pc = 0x14d008u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 8));
    // 0x14d00c: 0x908c0001  lbu         $t4, 0x1($a0)
    ctx->pc = 0x14d00cu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x14d010: 0x908b0000  lbu         $t3, 0x0($a0)
    ctx->pc = 0x14d010u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14d014: 0x908a0011  lbu         $t2, 0x11($a0)
    ctx->pc = 0x14d014u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 17)));
    // 0x14d018: 0x90890010  lbu         $t1, 0x10($a0)
    ctx->pc = 0x14d018u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x14d01c: 0x90880100  lbu         $t0, 0x100($a0)
    ctx->pc = 0x14d01cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 256)));
    // 0x14d020: 0x90850140  lbu         $a1, 0x140($a0)
    ctx->pc = 0x14d020u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 320)));
    // 0x14d024: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14d024u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14d028: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14d028u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14d02c: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14d02cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14d030: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14d030u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14d034: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14d034u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14d038: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14d038u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14d03c: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14d03cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14d040: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14d040u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14d044: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14d044u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14d048: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14d048u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14d04c: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14d04cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14d050: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14d050u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14d054: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14d054u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14d058: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14d058u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14d05c: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14d05cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14d060: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14d060u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14d064: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14d064u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14d068: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14d068u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14d06c: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14d06cu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14d070: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14d070u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14d074: 0x90890012  lbu         $t1, 0x12($a0)
    ctx->pc = 0x14d074u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 18)));
    // 0x14d078: 0x90880101  lbu         $t0, 0x101($a0)
    ctx->pc = 0x14d078u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 257)));
    // 0x14d07c: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14d07cu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14d080: 0x90850141  lbu         $a1, 0x141($a0)
    ctx->pc = 0x14d080u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 321)));
    // 0x14d084: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14d084u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14d088: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14d088u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14d08c: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14d08cu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14d090: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14d090u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14d094: 0x908c0003  lbu         $t4, 0x3($a0)
    ctx->pc = 0x14d094u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x14d098: 0x908b0002  lbu         $t3, 0x2($a0)
    ctx->pc = 0x14d098u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x14d09c: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14d09cu;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14d0a0: 0x908a0013  lbu         $t2, 0x13($a0)
    ctx->pc = 0x14d0a0u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 19)));
    // 0x14d0a4: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14d0a4u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14d0a8: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14d0a8u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14d0ac: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14d0acu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14d0b0: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14d0b0u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14d0b4: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14d0b4u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14d0b8: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14d0b8u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14d0bc: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14d0bcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14d0c0: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14d0c0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14d0c4: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14d0c4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14d0c8: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14d0c8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14d0cc: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14d0ccu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14d0d0: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14d0d0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14d0d4: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14d0d4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14d0d8: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14d0d8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14d0dc: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14d0dcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14d0e0: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14d0e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14d0e4: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14d0e4u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14d0e8: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14d0e8u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14d0ec: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14d0ecu;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14d0f0: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14d0f0u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14d0f4: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14d0f4u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14d0f8: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14d0f8u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14d0fc: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14d0fcu;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14d100: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14d100u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14d104: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14d104u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14d108: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14d108u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14d10c: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14d10cu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14d110: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14d110u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14d114: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14d114u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14d118: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14d118u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14d11c: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14d11cu;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14d120: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14d120u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14d124: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14d124u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14d128: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14d128u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14d12c: 0x7c450000  sq          $a1, 0x0($v0)
    ctx->pc = 0x14d12cu;
    WRITE128(ADD32(GPR_U32(ctx, 2), 0), GPR_VEC(ctx, 5));
    // 0x14d130: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14d130u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14d134: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14d134u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14d138: 0x7da50000  sq          $a1, 0x0($t5)
    ctx->pc = 0x14d138u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 0), GPR_VEC(ctx, 5));
    // 0x14d13c: 0x908c0005  lbu         $t4, 0x5($a0)
    ctx->pc = 0x14d13cu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 5)));
    // 0x14d140: 0x908b0004  lbu         $t3, 0x4($a0)
    ctx->pc = 0x14d140u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x14d144: 0x908a0015  lbu         $t2, 0x15($a0)
    ctx->pc = 0x14d144u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 21)));
    // 0x14d148: 0x90890014  lbu         $t1, 0x14($a0)
    ctx->pc = 0x14d148u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x14d14c: 0x90880102  lbu         $t0, 0x102($a0)
    ctx->pc = 0x14d14cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 258)));
    // 0x14d150: 0x90850142  lbu         $a1, 0x142($a0)
    ctx->pc = 0x14d150u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 322)));
    // 0x14d154: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14d154u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14d158: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14d158u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14d15c: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14d15cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14d160: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14d160u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14d164: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14d164u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14d168: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14d168u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14d16c: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14d16cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14d170: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14d170u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14d174: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14d174u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14d178: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14d178u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14d17c: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14d17cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14d180: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14d180u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14d184: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14d184u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14d188: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14d188u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14d18c: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14d18cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14d190: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14d190u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14d194: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14d194u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14d198: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14d198u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14d19c: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14d19cu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14d1a0: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14d1a0u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14d1a4: 0x90890016  lbu         $t1, 0x16($a0)
    ctx->pc = 0x14d1a4u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 22)));
    // 0x14d1a8: 0x90880103  lbu         $t0, 0x103($a0)
    ctx->pc = 0x14d1a8u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 259)));
    // 0x14d1ac: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14d1acu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14d1b0: 0x90850143  lbu         $a1, 0x143($a0)
    ctx->pc = 0x14d1b0u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 323)));
    // 0x14d1b4: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14d1b4u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14d1b8: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14d1b8u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14d1bc: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14d1bcu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14d1c0: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14d1c0u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14d1c4: 0x908c0007  lbu         $t4, 0x7($a0)
    ctx->pc = 0x14d1c4u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 7)));
    // 0x14d1c8: 0x908b0006  lbu         $t3, 0x6($a0)
    ctx->pc = 0x14d1c8u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 6)));
    // 0x14d1cc: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14d1ccu;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14d1d0: 0x908a0017  lbu         $t2, 0x17($a0)
    ctx->pc = 0x14d1d0u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 23)));
    // 0x14d1d4: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14d1d4u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14d1d8: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14d1d8u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14d1dc: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14d1dcu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14d1e0: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14d1e0u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14d1e4: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14d1e4u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14d1e8: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14d1e8u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14d1ec: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14d1ecu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14d1f0: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14d1f0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14d1f4: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14d1f4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14d1f8: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14d1f8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14d1fc: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14d1fcu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14d200: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14d200u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14d204: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14d204u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14d208: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14d208u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14d20c: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14d20cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14d210: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14d210u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14d214: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14d214u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14d218: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14d218u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14d21c: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14d21cu;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14d220: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14d220u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14d224: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14d224u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14d228: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14d228u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14d22c: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14d22cu;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14d230: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14d230u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14d234: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14d234u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14d238: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14d238u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14d23c: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14d23cu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14d240: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14d240u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14d244: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14d244u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14d248: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14d248u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14d24c: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14d24cu;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14d250: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14d250u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14d254: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14d254u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14d258: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14d258u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14d25c: 0x7c450010  sq          $a1, 0x10($v0)
    ctx->pc = 0x14d25cu;
    WRITE128(ADD32(GPR_U32(ctx, 2), 16), GPR_VEC(ctx, 5));
    // 0x14d260: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14d260u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14d264: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14d264u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14d268: 0x7da50010  sq          $a1, 0x10($t5)
    ctx->pc = 0x14d268u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 16), GPR_VEC(ctx, 5));
    // 0x14d26c: 0x908c0009  lbu         $t4, 0x9($a0)
    ctx->pc = 0x14d26cu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 9)));
    // 0x14d270: 0x908b0008  lbu         $t3, 0x8($a0)
    ctx->pc = 0x14d270u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x14d274: 0x908a0019  lbu         $t2, 0x19($a0)
    ctx->pc = 0x14d274u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 25)));
    // 0x14d278: 0x90890018  lbu         $t1, 0x18($a0)
    ctx->pc = 0x14d278u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x14d27c: 0x90880104  lbu         $t0, 0x104($a0)
    ctx->pc = 0x14d27cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 260)));
    // 0x14d280: 0x90850144  lbu         $a1, 0x144($a0)
    ctx->pc = 0x14d280u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 324)));
    // 0x14d284: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14d284u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14d288: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14d288u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14d28c: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14d28cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14d290: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14d290u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14d294: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14d294u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14d298: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14d298u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14d29c: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14d29cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14d2a0: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14d2a0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14d2a4: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14d2a4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14d2a8: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14d2a8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14d2ac: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14d2acu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14d2b0: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14d2b0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14d2b4: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14d2b4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14d2b8: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14d2b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14d2bc: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14d2bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14d2c0: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14d2c0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14d2c4: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14d2c4u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14d2c8: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14d2c8u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14d2cc: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14d2ccu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14d2d0: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14d2d0u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14d2d4: 0x9089001a  lbu         $t1, 0x1A($a0)
    ctx->pc = 0x14d2d4u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 26)));
    // 0x14d2d8: 0x90880105  lbu         $t0, 0x105($a0)
    ctx->pc = 0x14d2d8u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 261)));
    // 0x14d2dc: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14d2dcu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14d2e0: 0x90850145  lbu         $a1, 0x145($a0)
    ctx->pc = 0x14d2e0u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 325)));
    // 0x14d2e4: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14d2e4u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14d2e8: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14d2e8u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14d2ec: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14d2ecu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14d2f0: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14d2f0u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14d2f4: 0x908c000b  lbu         $t4, 0xB($a0)
    ctx->pc = 0x14d2f4u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 11)));
    // 0x14d2f8: 0x908b000a  lbu         $t3, 0xA($a0)
    ctx->pc = 0x14d2f8u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 10)));
    // 0x14d2fc: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14d2fcu;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14d300: 0x908a001b  lbu         $t2, 0x1B($a0)
    ctx->pc = 0x14d300u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 27)));
    // 0x14d304: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14d304u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14d308: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14d308u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14d30c: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14d30cu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14d310: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14d310u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14d314: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14d314u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14d318: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14d318u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14d31c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14d31cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14d320: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14d320u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14d324: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14d324u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14d328: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14d328u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14d32c: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14d32cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14d330: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14d330u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14d334: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14d334u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14d338: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14d338u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14d33c: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14d33cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14d340: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14d340u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14d344: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14d344u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14d348: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14d348u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14d34c: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14d34cu;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14d350: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14d350u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14d354: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14d354u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14d358: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14d358u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14d35c: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14d35cu;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14d360: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14d360u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14d364: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14d364u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14d368: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14d368u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14d36c: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14d36cu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14d370: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14d370u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14d374: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14d374u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14d378: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14d378u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14d37c: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14d37cu;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14d380: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14d380u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14d384: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14d384u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14d388: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14d388u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14d38c: 0x7c450020  sq          $a1, 0x20($v0)
    ctx->pc = 0x14d38cu;
    WRITE128(ADD32(GPR_U32(ctx, 2), 32), GPR_VEC(ctx, 5));
    // 0x14d390: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14d390u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14d394: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14d394u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14d398: 0x7da50020  sq          $a1, 0x20($t5)
    ctx->pc = 0x14d398u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 32), GPR_VEC(ctx, 5));
    // 0x14d39c: 0x908c000d  lbu         $t4, 0xD($a0)
    ctx->pc = 0x14d39cu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 13)));
    // 0x14d3a0: 0x908b000c  lbu         $t3, 0xC($a0)
    ctx->pc = 0x14d3a0u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x14d3a4: 0x908a001d  lbu         $t2, 0x1D($a0)
    ctx->pc = 0x14d3a4u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 29)));
    // 0x14d3a8: 0x9089001c  lbu         $t1, 0x1C($a0)
    ctx->pc = 0x14d3a8u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x14d3ac: 0x90880106  lbu         $t0, 0x106($a0)
    ctx->pc = 0x14d3acu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 262)));
    // 0x14d3b0: 0x90850146  lbu         $a1, 0x146($a0)
    ctx->pc = 0x14d3b0u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 326)));
    // 0x14d3b4: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14d3b4u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14d3b8: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14d3b8u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14d3bc: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14d3bcu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14d3c0: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14d3c0u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14d3c4: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14d3c4u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14d3c8: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14d3c8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14d3cc: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14d3ccu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14d3d0: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14d3d0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14d3d4: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14d3d4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14d3d8: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14d3d8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14d3dc: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14d3dcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14d3e0: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14d3e0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14d3e4: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14d3e4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14d3e8: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14d3e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14d3ec: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14d3ecu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14d3f0: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14d3f0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14d3f4: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14d3f4u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14d3f8: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14d3f8u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14d3fc: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14d3fcu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14d400: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14d400u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14d404: 0x9089001e  lbu         $t1, 0x1E($a0)
    ctx->pc = 0x14d404u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 30)));
    // 0x14d408: 0x90880107  lbu         $t0, 0x107($a0)
    ctx->pc = 0x14d408u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 263)));
    // 0x14d40c: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14d40cu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14d410: 0x90850147  lbu         $a1, 0x147($a0)
    ctx->pc = 0x14d410u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 327)));
    // 0x14d414: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14d414u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14d418: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14d418u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14d41c: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14d41cu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14d420: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14d420u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14d424: 0x908c000f  lbu         $t4, 0xF($a0)
    ctx->pc = 0x14d424u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 15)));
    // 0x14d428: 0x908b000e  lbu         $t3, 0xE($a0)
    ctx->pc = 0x14d428u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 14)));
    // 0x14d42c: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14d42cu;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14d430: 0x908a001f  lbu         $t2, 0x1F($a0)
    ctx->pc = 0x14d430u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 31)));
    // 0x14d434: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14d434u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14d438: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14d438u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14d43c: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14d43cu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14d440: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14d440u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14d444: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14d444u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14d448: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14d448u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14d44c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14d44cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14d450: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14d450u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14d454: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14d454u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14d458: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14d458u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14d45c: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14d45cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14d460: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14d460u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14d464: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14d464u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14d468: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14d468u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14d46c: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14d46cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14d470: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14d470u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14d474: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14d474u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14d478: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14d478u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14d47c: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14d47cu;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14d480: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14d480u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14d484: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14d484u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14d488: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14d488u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14d48c: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14d48cu;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14d490: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14d490u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14d494: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14d494u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14d498: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14d498u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14d49c: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14d49cu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14d4a0: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14d4a0u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14d4a4: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14d4a4u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14d4a8: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14d4a8u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14d4ac: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14d4acu;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14d4b0: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14d4b0u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14d4b4: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14d4b4u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14d4b8: 0x7c450030  sq          $a1, 0x30($v0)
    ctx->pc = 0x14d4b8u;
    WRITE128(ADD32(GPR_U32(ctx, 2), 48), GPR_VEC(ctx, 5));
    // 0x14d4bc: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14d4bcu;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14d4c0: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14d4c0u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14d4c4: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14d4c4u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14d4c8: 0x7da50030  sq          $a1, 0x30($t5)
    ctx->pc = 0x14d4c8u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 48), GPR_VEC(ctx, 5));
    // 0x14d4cc: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x14d4ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x14d4d0: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x14d4d0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14d4d4: 0x1a36821  addu        $t5, $t5, $v1
    ctx->pc = 0x14d4d4u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), GPR_U32(ctx, 3)));
    // 0x14d4d8: 0xcc800020  pref        0x00, 0x20($a0)
    ctx->pc = 0x14d4d8u;
    // PREF instruction (ignored)
    // 0x14d4dc: 0x908c0001  lbu         $t4, 0x1($a0)
    ctx->pc = 0x14d4dcu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x14d4e0: 0x908b0000  lbu         $t3, 0x0($a0)
    ctx->pc = 0x14d4e0u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14d4e4: 0x908a0011  lbu         $t2, 0x11($a0)
    ctx->pc = 0x14d4e4u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 17)));
    // 0x14d4e8: 0x90890010  lbu         $t1, 0x10($a0)
    ctx->pc = 0x14d4e8u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x14d4ec: 0x91c80000  lbu         $t0, 0x0($t6)
    ctx->pc = 0x14d4ecu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x14d4f0: 0x91c50040  lbu         $a1, 0x40($t6)
    ctx->pc = 0x14d4f0u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 64)));
    // 0x14d4f4: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14d4f4u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14d4f8: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14d4f8u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14d4fc: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14d4fcu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14d500: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14d500u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14d504: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14d504u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14d508: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14d508u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14d50c: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14d50cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14d510: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14d510u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14d514: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14d514u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14d518: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14d518u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14d51c: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14d51cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14d520: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14d520u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14d524: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14d524u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14d528: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14d528u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14d52c: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14d52cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14d530: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14d530u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14d534: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14d534u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14d538: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14d538u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14d53c: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14d53cu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14d540: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14d540u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14d544: 0x90890012  lbu         $t1, 0x12($a0)
    ctx->pc = 0x14d544u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 18)));
    // 0x14d548: 0x91c80001  lbu         $t0, 0x1($t6)
    ctx->pc = 0x14d548u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 1)));
    // 0x14d54c: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14d54cu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14d550: 0x91c50041  lbu         $a1, 0x41($t6)
    ctx->pc = 0x14d550u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 65)));
    // 0x14d554: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14d554u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14d558: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14d558u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14d55c: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14d55cu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14d560: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14d560u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14d564: 0x908c0003  lbu         $t4, 0x3($a0)
    ctx->pc = 0x14d564u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x14d568: 0x908b0002  lbu         $t3, 0x2($a0)
    ctx->pc = 0x14d568u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x14d56c: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14d56cu;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14d570: 0x908a0013  lbu         $t2, 0x13($a0)
    ctx->pc = 0x14d570u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 19)));
    // 0x14d574: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14d574u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14d578: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14d578u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14d57c: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14d57cu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14d580: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14d580u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14d584: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14d584u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14d588: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14d588u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14d58c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14d58cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14d590: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14d590u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14d594: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14d594u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14d598: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14d598u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14d59c: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14d59cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14d5a0: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14d5a0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14d5a4: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14d5a4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14d5a8: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14d5a8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14d5ac: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14d5acu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14d5b0: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14d5b0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14d5b4: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14d5b4u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14d5b8: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14d5b8u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14d5bc: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14d5bcu;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14d5c0: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14d5c0u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14d5c4: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14d5c4u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14d5c8: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14d5c8u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14d5cc: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14d5ccu;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14d5d0: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14d5d0u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14d5d4: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14d5d4u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14d5d8: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14d5d8u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14d5dc: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14d5dcu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14d5e0: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14d5e0u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14d5e4: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14d5e4u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14d5e8: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14d5e8u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14d5ec: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14d5ecu;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14d5f0: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14d5f0u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14d5f4: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14d5f4u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14d5f8: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14d5f8u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14d5fc: 0x7cc50000  sq          $a1, 0x0($a2)
    ctx->pc = 0x14d5fcu;
    WRITE128(ADD32(GPR_U32(ctx, 6), 0), GPR_VEC(ctx, 5));
    // 0x14d600: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14d600u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14d604: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14d604u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14d608: 0x7da50000  sq          $a1, 0x0($t5)
    ctx->pc = 0x14d608u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 0), GPR_VEC(ctx, 5));
    // 0x14d60c: 0x908c0005  lbu         $t4, 0x5($a0)
    ctx->pc = 0x14d60cu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 5)));
    // 0x14d610: 0x908b0004  lbu         $t3, 0x4($a0)
    ctx->pc = 0x14d610u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x14d614: 0x908a0015  lbu         $t2, 0x15($a0)
    ctx->pc = 0x14d614u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 21)));
    // 0x14d618: 0x90890014  lbu         $t1, 0x14($a0)
    ctx->pc = 0x14d618u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x14d61c: 0x91c80002  lbu         $t0, 0x2($t6)
    ctx->pc = 0x14d61cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 2)));
    // 0x14d620: 0x91c50042  lbu         $a1, 0x42($t6)
    ctx->pc = 0x14d620u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 66)));
    // 0x14d624: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14d624u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14d628: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14d628u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14d62c: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14d62cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14d630: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14d630u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14d634: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14d634u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14d638: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14d638u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14d63c: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14d63cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14d640: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14d640u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14d644: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14d644u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14d648: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14d648u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14d64c: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14d64cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14d650: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14d650u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14d654: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14d654u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14d658: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14d658u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14d65c: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14d65cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14d660: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14d660u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14d664: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14d664u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14d668: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14d668u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14d66c: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14d66cu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14d670: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14d670u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14d674: 0x90890016  lbu         $t1, 0x16($a0)
    ctx->pc = 0x14d674u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 22)));
    // 0x14d678: 0x91c80003  lbu         $t0, 0x3($t6)
    ctx->pc = 0x14d678u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 3)));
    // 0x14d67c: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14d67cu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14d680: 0x91c50043  lbu         $a1, 0x43($t6)
    ctx->pc = 0x14d680u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 67)));
    // 0x14d684: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14d684u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14d688: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14d688u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14d68c: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14d68cu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14d690: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14d690u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14d694: 0x908c0007  lbu         $t4, 0x7($a0)
    ctx->pc = 0x14d694u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 7)));
    // 0x14d698: 0x908b0006  lbu         $t3, 0x6($a0)
    ctx->pc = 0x14d698u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 6)));
    // 0x14d69c: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14d69cu;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14d6a0: 0x908a0017  lbu         $t2, 0x17($a0)
    ctx->pc = 0x14d6a0u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 23)));
    // 0x14d6a4: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14d6a4u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14d6a8: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14d6a8u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14d6ac: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14d6acu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14d6b0: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14d6b0u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14d6b4: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14d6b4u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14d6b8: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14d6b8u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14d6bc: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14d6bcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14d6c0: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14d6c0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14d6c4: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14d6c4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14d6c8: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14d6c8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14d6cc: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14d6ccu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14d6d0: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14d6d0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14d6d4: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14d6d4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14d6d8: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14d6d8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14d6dc: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14d6dcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14d6e0: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14d6e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14d6e4: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14d6e4u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14d6e8: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14d6e8u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14d6ec: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14d6ecu;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14d6f0: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14d6f0u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14d6f4: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14d6f4u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14d6f8: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14d6f8u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14d6fc: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14d6fcu;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14d700: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14d700u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14d704: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14d704u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14d708: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14d708u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14d70c: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14d70cu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14d710: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14d710u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14d714: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14d714u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14d718: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14d718u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14d71c: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14d71cu;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14d720: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14d720u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14d724: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14d724u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14d728: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14d728u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14d72c: 0x7cc50010  sq          $a1, 0x10($a2)
    ctx->pc = 0x14d72cu;
    WRITE128(ADD32(GPR_U32(ctx, 6), 16), GPR_VEC(ctx, 5));
    // 0x14d730: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14d730u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14d734: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14d734u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14d738: 0x7da50010  sq          $a1, 0x10($t5)
    ctx->pc = 0x14d738u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 16), GPR_VEC(ctx, 5));
    // 0x14d73c: 0x908c0009  lbu         $t4, 0x9($a0)
    ctx->pc = 0x14d73cu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 9)));
    // 0x14d740: 0x908b0008  lbu         $t3, 0x8($a0)
    ctx->pc = 0x14d740u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x14d744: 0x908a0019  lbu         $t2, 0x19($a0)
    ctx->pc = 0x14d744u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 25)));
    // 0x14d748: 0x90890018  lbu         $t1, 0x18($a0)
    ctx->pc = 0x14d748u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x14d74c: 0x91c80004  lbu         $t0, 0x4($t6)
    ctx->pc = 0x14d74cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 4)));
    // 0x14d750: 0x91c50044  lbu         $a1, 0x44($t6)
    ctx->pc = 0x14d750u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 68)));
    // 0x14d754: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14d754u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14d758: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14d758u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14d75c: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14d75cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14d760: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14d760u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14d764: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14d764u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14d768: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14d768u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14d76c: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14d76cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14d770: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14d770u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14d774: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14d774u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14d778: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14d778u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14d77c: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14d77cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14d780: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14d780u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14d784: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14d784u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14d788: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14d788u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14d78c: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14d78cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14d790: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14d790u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14d794: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14d794u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14d798: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14d798u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14d79c: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14d79cu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14d7a0: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14d7a0u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14d7a4: 0x9089001a  lbu         $t1, 0x1A($a0)
    ctx->pc = 0x14d7a4u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 26)));
    // 0x14d7a8: 0x91c80005  lbu         $t0, 0x5($t6)
    ctx->pc = 0x14d7a8u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 5)));
    // 0x14d7ac: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14d7acu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14d7b0: 0x91c50045  lbu         $a1, 0x45($t6)
    ctx->pc = 0x14d7b0u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 69)));
    // 0x14d7b4: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14d7b4u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14d7b8: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14d7b8u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14d7bc: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14d7bcu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14d7c0: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14d7c0u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14d7c4: 0x908c000b  lbu         $t4, 0xB($a0)
    ctx->pc = 0x14d7c4u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 11)));
    // 0x14d7c8: 0x908b000a  lbu         $t3, 0xA($a0)
    ctx->pc = 0x14d7c8u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 10)));
    // 0x14d7cc: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14d7ccu;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14d7d0: 0x908a001b  lbu         $t2, 0x1B($a0)
    ctx->pc = 0x14d7d0u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 27)));
    // 0x14d7d4: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14d7d4u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14d7d8: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14d7d8u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14d7dc: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14d7dcu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14d7e0: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14d7e0u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14d7e4: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14d7e4u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14d7e8: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14d7e8u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14d7ec: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14d7ecu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14d7f0: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14d7f0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14d7f4: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14d7f4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14d7f8: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14d7f8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14d7fc: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14d7fcu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14d800: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14d800u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14d804: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14d804u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14d808: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14d808u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14d80c: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14d80cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14d810: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14d810u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14d814: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14d814u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14d818: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14d818u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14d81c: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14d81cu;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14d820: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14d820u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14d824: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14d824u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14d828: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14d828u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14d82c: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14d82cu;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14d830: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14d830u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14d834: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14d834u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14d838: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14d838u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14d83c: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14d83cu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14d840: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14d840u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14d844: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14d844u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14d848: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14d848u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14d84c: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14d84cu;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14d850: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14d850u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14d854: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14d854u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14d858: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14d858u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14d85c: 0x7cc50020  sq          $a1, 0x20($a2)
    ctx->pc = 0x14d85cu;
    WRITE128(ADD32(GPR_U32(ctx, 6), 32), GPR_VEC(ctx, 5));
    // 0x14d860: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14d860u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14d864: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14d864u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14d868: 0x7da50020  sq          $a1, 0x20($t5)
    ctx->pc = 0x14d868u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 32), GPR_VEC(ctx, 5));
    // 0x14d86c: 0x908c000d  lbu         $t4, 0xD($a0)
    ctx->pc = 0x14d86cu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 13)));
    // 0x14d870: 0x908b000c  lbu         $t3, 0xC($a0)
    ctx->pc = 0x14d870u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x14d874: 0x908a001d  lbu         $t2, 0x1D($a0)
    ctx->pc = 0x14d874u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 29)));
    // 0x14d878: 0x9089001c  lbu         $t1, 0x1C($a0)
    ctx->pc = 0x14d878u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x14d87c: 0x91c80006  lbu         $t0, 0x6($t6)
    ctx->pc = 0x14d87cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 6)));
    // 0x14d880: 0x91c50046  lbu         $a1, 0x46($t6)
    ctx->pc = 0x14d880u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 70)));
    // 0x14d884: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14d884u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14d888: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14d888u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14d88c: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14d88cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14d890: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14d890u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14d894: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14d894u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14d898: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14d898u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14d89c: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14d89cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14d8a0: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14d8a0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14d8a4: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14d8a4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14d8a8: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14d8a8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14d8ac: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14d8acu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14d8b0: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14d8b0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14d8b4: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14d8b4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14d8b8: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14d8b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14d8bc: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14d8bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14d8c0: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14d8c0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14d8c4: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14d8c4u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14d8c8: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14d8c8u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14d8cc: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14d8ccu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14d8d0: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14d8d0u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14d8d4: 0x9089001e  lbu         $t1, 0x1E($a0)
    ctx->pc = 0x14d8d4u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 30)));
    // 0x14d8d8: 0x91c80007  lbu         $t0, 0x7($t6)
    ctx->pc = 0x14d8d8u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 7)));
    // 0x14d8dc: 0x91c50047  lbu         $a1, 0x47($t6)
    ctx->pc = 0x14d8dcu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 71)));
    // 0x14d8e0: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14d8e0u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14d8e4: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14d8e4u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14d8e8: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14d8e8u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14d8ec: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14d8ecu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14d8f0: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14d8f0u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14d8f4: 0x908c000f  lbu         $t4, 0xF($a0)
    ctx->pc = 0x14d8f4u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 15)));
    // 0x14d8f8: 0x908b000e  lbu         $t3, 0xE($a0)
    ctx->pc = 0x14d8f8u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 14)));
    // 0x14d8fc: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14d8fcu;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14d900: 0x908a001f  lbu         $t2, 0x1F($a0)
    ctx->pc = 0x14d900u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 31)));
    // 0x14d904: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14d904u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14d908: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14d908u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14d90c: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14d90cu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14d910: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14d910u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14d914: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14d914u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14d918: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14d918u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14d91c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14d91cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14d920: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14d920u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14d924: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14d924u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14d928: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14d928u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14d92c: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14d92cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14d930: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14d930u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14d934: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14d934u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14d938: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14d938u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14d93c: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14d93cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14d940: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14d940u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14d944: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14d944u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14d948: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14d948u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14d94c: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14d94cu;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14d950: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14d950u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14d954: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14d954u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14d958: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14d958u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14d95c: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14d95cu;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14d960: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14d960u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14d964: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14d964u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14d968: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14d968u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14d96c: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14d96cu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14d970: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14d970u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14d974: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14d974u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14d978: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14d978u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14d97c: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14d97cu;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14d980: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14d980u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14d984: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14d984u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14d988: 0x7cc50030  sq          $a1, 0x30($a2)
    ctx->pc = 0x14d988u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 48), GPR_VEC(ctx, 5));
    // 0x14d98c: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14d98cu;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14d990: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14d990u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14d994: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14d994u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14d998: 0x7da50030  sq          $a1, 0x30($t5)
    ctx->pc = 0x14d998u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 48), GPR_VEC(ctx, 5));
    // 0x14d99c: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x14d99cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x14d9a0: 0x25ce0008  addiu       $t6, $t6, 0x8
    ctx->pc = 0x14d9a0u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 8));
    // 0x14d9a4: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x14d9a4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14d9a8: 0x1a36821  addu        $t5, $t5, $v1
    ctx->pc = 0x14d9a8u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), GPR_U32(ctx, 3)));
    // 0x14d9ac: 0xcc800040  pref        0x00, 0x40($a0)
    ctx->pc = 0x14d9acu;
    // PREF instruction (ignored)
    // 0x14d9b0: 0x908c0001  lbu         $t4, 0x1($a0)
    ctx->pc = 0x14d9b0u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x14d9b4: 0x908b0000  lbu         $t3, 0x0($a0)
    ctx->pc = 0x14d9b4u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14d9b8: 0x908a0011  lbu         $t2, 0x11($a0)
    ctx->pc = 0x14d9b8u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 17)));
    // 0x14d9bc: 0x90890010  lbu         $t1, 0x10($a0)
    ctx->pc = 0x14d9bcu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x14d9c0: 0x91c80000  lbu         $t0, 0x0($t6)
    ctx->pc = 0x14d9c0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x14d9c4: 0x91c50040  lbu         $a1, 0x40($t6)
    ctx->pc = 0x14d9c4u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 64)));
    // 0x14d9c8: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14d9c8u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14d9cc: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14d9ccu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14d9d0: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14d9d0u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14d9d4: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14d9d4u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14d9d8: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14d9d8u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14d9dc: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14d9dcu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14d9e0: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14d9e0u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14d9e4: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14d9e4u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14d9e8: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14d9e8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14d9ec: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14d9ecu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14d9f0: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14d9f0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14d9f4: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14d9f4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14d9f8: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14d9f8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14d9fc: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14d9fcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14da00: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14da00u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14da04: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14da04u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14da08: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14da08u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14da0c: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14da0cu;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14da10: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14da10u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14da14: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14da14u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14da18: 0x90890012  lbu         $t1, 0x12($a0)
    ctx->pc = 0x14da18u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 18)));
    // 0x14da1c: 0x91c80001  lbu         $t0, 0x1($t6)
    ctx->pc = 0x14da1cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 1)));
    // 0x14da20: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14da20u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14da24: 0x91c50041  lbu         $a1, 0x41($t6)
    ctx->pc = 0x14da24u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 65)));
    // 0x14da28: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14da28u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14da2c: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14da2cu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14da30: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14da30u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14da34: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14da34u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14da38: 0x908c0003  lbu         $t4, 0x3($a0)
    ctx->pc = 0x14da38u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x14da3c: 0x908b0002  lbu         $t3, 0x2($a0)
    ctx->pc = 0x14da3cu;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x14da40: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14da40u;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14da44: 0x908a0013  lbu         $t2, 0x13($a0)
    ctx->pc = 0x14da44u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 19)));
    // 0x14da48: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14da48u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14da4c: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14da4cu;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14da50: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14da50u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14da54: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14da54u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14da58: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14da58u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14da5c: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14da5cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14da60: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14da60u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14da64: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14da64u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14da68: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14da68u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14da6c: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14da6cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14da70: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14da70u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14da74: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14da74u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14da78: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14da78u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14da7c: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14da7cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14da80: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14da80u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14da84: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14da84u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14da88: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14da88u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14da8c: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14da8cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14da90: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14da90u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14da94: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14da94u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14da98: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14da98u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14da9c: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14da9cu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14daa0: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14daa0u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14daa4: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14daa4u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14daa8: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14daa8u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14daac: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14daacu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14dab0: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14dab0u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14dab4: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14dab4u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14dab8: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14dab8u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14dabc: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14dabcu;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14dac0: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14dac0u;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14dac4: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14dac4u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14dac8: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14dac8u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14dacc: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14daccu;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14dad0: 0x7cc50000  sq          $a1, 0x0($a2)
    ctx->pc = 0x14dad0u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 0), GPR_VEC(ctx, 5));
    // 0x14dad4: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14dad4u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14dad8: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14dad8u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14dadc: 0x7da50000  sq          $a1, 0x0($t5)
    ctx->pc = 0x14dadcu;
    WRITE128(ADD32(GPR_U32(ctx, 13), 0), GPR_VEC(ctx, 5));
    // 0x14dae0: 0x908c0005  lbu         $t4, 0x5($a0)
    ctx->pc = 0x14dae0u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 5)));
    // 0x14dae4: 0x908b0004  lbu         $t3, 0x4($a0)
    ctx->pc = 0x14dae4u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x14dae8: 0x908a0015  lbu         $t2, 0x15($a0)
    ctx->pc = 0x14dae8u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 21)));
    // 0x14daec: 0x90890014  lbu         $t1, 0x14($a0)
    ctx->pc = 0x14daecu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x14daf0: 0x91c80002  lbu         $t0, 0x2($t6)
    ctx->pc = 0x14daf0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 2)));
    // 0x14daf4: 0x91c50042  lbu         $a1, 0x42($t6)
    ctx->pc = 0x14daf4u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 66)));
    // 0x14daf8: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14daf8u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14dafc: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14dafcu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14db00: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14db00u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14db04: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14db04u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14db08: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14db08u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14db0c: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14db0cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14db10: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14db10u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14db14: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14db14u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14db18: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14db18u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14db1c: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14db1cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14db20: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14db20u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14db24: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14db24u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14db28: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14db28u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14db2c: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14db2cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14db30: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14db30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14db34: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14db34u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14db38: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14db38u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14db3c: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14db3cu;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14db40: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14db40u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14db44: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14db44u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14db48: 0x90890016  lbu         $t1, 0x16($a0)
    ctx->pc = 0x14db48u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 22)));
    // 0x14db4c: 0x91c80003  lbu         $t0, 0x3($t6)
    ctx->pc = 0x14db4cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 3)));
    // 0x14db50: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14db50u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14db54: 0x91c50043  lbu         $a1, 0x43($t6)
    ctx->pc = 0x14db54u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 67)));
    // 0x14db58: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14db58u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14db5c: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14db5cu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14db60: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14db60u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14db64: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14db64u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14db68: 0x908c0007  lbu         $t4, 0x7($a0)
    ctx->pc = 0x14db68u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 7)));
    // 0x14db6c: 0x908b0006  lbu         $t3, 0x6($a0)
    ctx->pc = 0x14db6cu;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 6)));
    // 0x14db70: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14db70u;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14db74: 0x908a0017  lbu         $t2, 0x17($a0)
    ctx->pc = 0x14db74u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 23)));
    // 0x14db78: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14db78u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14db7c: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14db7cu;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14db80: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14db80u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14db84: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14db84u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14db88: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14db88u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14db8c: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14db8cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14db90: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14db90u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14db94: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14db94u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14db98: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14db98u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14db9c: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14db9cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14dba0: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14dba0u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14dba4: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14dba4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14dba8: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14dba8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14dbac: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14dbacu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14dbb0: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14dbb0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14dbb4: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14dbb4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14dbb8: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14dbb8u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14dbbc: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14dbbcu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14dbc0: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14dbc0u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14dbc4: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14dbc4u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14dbc8: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14dbc8u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14dbcc: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14dbccu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14dbd0: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14dbd0u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14dbd4: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14dbd4u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14dbd8: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14dbd8u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14dbdc: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14dbdcu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14dbe0: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14dbe0u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14dbe4: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14dbe4u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14dbe8: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14dbe8u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14dbec: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14dbecu;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14dbf0: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14dbf0u;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14dbf4: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14dbf4u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14dbf8: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14dbf8u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14dbfc: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14dbfcu;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14dc00: 0x7cc50010  sq          $a1, 0x10($a2)
    ctx->pc = 0x14dc00u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 16), GPR_VEC(ctx, 5));
    // 0x14dc04: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14dc04u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14dc08: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14dc08u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14dc0c: 0x7da50010  sq          $a1, 0x10($t5)
    ctx->pc = 0x14dc0cu;
    WRITE128(ADD32(GPR_U32(ctx, 13), 16), GPR_VEC(ctx, 5));
    // 0x14dc10: 0x908c0009  lbu         $t4, 0x9($a0)
    ctx->pc = 0x14dc10u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 9)));
    // 0x14dc14: 0x908b0008  lbu         $t3, 0x8($a0)
    ctx->pc = 0x14dc14u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x14dc18: 0x908a0019  lbu         $t2, 0x19($a0)
    ctx->pc = 0x14dc18u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 25)));
    // 0x14dc1c: 0x90890018  lbu         $t1, 0x18($a0)
    ctx->pc = 0x14dc1cu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x14dc20: 0x91c80004  lbu         $t0, 0x4($t6)
    ctx->pc = 0x14dc20u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 4)));
    // 0x14dc24: 0x91c50044  lbu         $a1, 0x44($t6)
    ctx->pc = 0x14dc24u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 68)));
    // 0x14dc28: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14dc28u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14dc2c: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14dc2cu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14dc30: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14dc30u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14dc34: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14dc34u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14dc38: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14dc38u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14dc3c: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14dc3cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14dc40: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14dc40u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14dc44: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14dc44u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14dc48: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14dc48u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14dc4c: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14dc4cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14dc50: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14dc50u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14dc54: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14dc54u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14dc58: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14dc58u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14dc5c: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14dc5cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14dc60: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14dc60u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14dc64: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14dc64u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14dc68: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14dc68u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14dc6c: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14dc6cu;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14dc70: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14dc70u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14dc74: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14dc74u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14dc78: 0x9089001a  lbu         $t1, 0x1A($a0)
    ctx->pc = 0x14dc78u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 26)));
    // 0x14dc7c: 0x91c80005  lbu         $t0, 0x5($t6)
    ctx->pc = 0x14dc7cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 5)));
    // 0x14dc80: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14dc80u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14dc84: 0x91c50045  lbu         $a1, 0x45($t6)
    ctx->pc = 0x14dc84u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 69)));
    // 0x14dc88: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14dc88u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14dc8c: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14dc8cu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14dc90: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14dc90u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14dc94: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14dc94u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14dc98: 0x908c000b  lbu         $t4, 0xB($a0)
    ctx->pc = 0x14dc98u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 11)));
    // 0x14dc9c: 0x908b000a  lbu         $t3, 0xA($a0)
    ctx->pc = 0x14dc9cu;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 10)));
    // 0x14dca0: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14dca0u;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14dca4: 0x908a001b  lbu         $t2, 0x1B($a0)
    ctx->pc = 0x14dca4u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 27)));
    // 0x14dca8: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14dca8u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14dcac: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14dcacu;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14dcb0: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14dcb0u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14dcb4: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14dcb4u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14dcb8: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14dcb8u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14dcbc: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14dcbcu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14dcc0: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14dcc0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14dcc4: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14dcc4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14dcc8: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14dcc8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14dccc: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14dcccu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14dcd0: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14dcd0u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14dcd4: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14dcd4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14dcd8: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14dcd8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14dcdc: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14dcdcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14dce0: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14dce0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14dce4: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14dce4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14dce8: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14dce8u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14dcec: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14dcecu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14dcf0: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14dcf0u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14dcf4: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14dcf4u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14dcf8: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14dcf8u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14dcfc: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14dcfcu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14dd00: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14dd00u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14dd04: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14dd04u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14dd08: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14dd08u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14dd0c: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14dd0cu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14dd10: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14dd10u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14dd14: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14dd14u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14dd18: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14dd18u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14dd1c: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14dd1cu;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14dd20: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14dd20u;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14dd24: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14dd24u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14dd28: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14dd28u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14dd2c: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14dd2cu;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14dd30: 0x7cc50020  sq          $a1, 0x20($a2)
    ctx->pc = 0x14dd30u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 32), GPR_VEC(ctx, 5));
    // 0x14dd34: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14dd34u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14dd38: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14dd38u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14dd3c: 0x7da50020  sq          $a1, 0x20($t5)
    ctx->pc = 0x14dd3cu;
    WRITE128(ADD32(GPR_U32(ctx, 13), 32), GPR_VEC(ctx, 5));
    // 0x14dd40: 0x908c000d  lbu         $t4, 0xD($a0)
    ctx->pc = 0x14dd40u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 13)));
    // 0x14dd44: 0x908b000c  lbu         $t3, 0xC($a0)
    ctx->pc = 0x14dd44u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x14dd48: 0x908a001d  lbu         $t2, 0x1D($a0)
    ctx->pc = 0x14dd48u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 29)));
    // 0x14dd4c: 0x9089001c  lbu         $t1, 0x1C($a0)
    ctx->pc = 0x14dd4cu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x14dd50: 0x91c80006  lbu         $t0, 0x6($t6)
    ctx->pc = 0x14dd50u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 6)));
    // 0x14dd54: 0x91c50046  lbu         $a1, 0x46($t6)
    ctx->pc = 0x14dd54u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 70)));
    // 0x14dd58: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14dd58u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14dd5c: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14dd5cu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14dd60: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14dd60u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14dd64: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14dd64u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14dd68: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14dd68u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14dd6c: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14dd6cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14dd70: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14dd70u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14dd74: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14dd74u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14dd78: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14dd78u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14dd7c: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14dd7cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14dd80: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14dd80u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14dd84: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14dd84u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14dd88: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14dd88u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14dd8c: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14dd8cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14dd90: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14dd90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14dd94: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14dd94u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14dd98: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14dd98u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14dd9c: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14dd9cu;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14dda0: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14dda0u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14dda4: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14dda4u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14dda8: 0x9089001e  lbu         $t1, 0x1E($a0)
    ctx->pc = 0x14dda8u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 30)));
    // 0x14ddac: 0x91c80007  lbu         $t0, 0x7($t6)
    ctx->pc = 0x14ddacu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 7)));
    // 0x14ddb0: 0x91c50047  lbu         $a1, 0x47($t6)
    ctx->pc = 0x14ddb0u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 71)));
    // 0x14ddb4: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14ddb4u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14ddb8: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14ddb8u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14ddbc: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14ddbcu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14ddc0: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14ddc0u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14ddc4: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14ddc4u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14ddc8: 0x908c000f  lbu         $t4, 0xF($a0)
    ctx->pc = 0x14ddc8u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 15)));
    // 0x14ddcc: 0x908b000e  lbu         $t3, 0xE($a0)
    ctx->pc = 0x14ddccu;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 14)));
    // 0x14ddd0: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14ddd0u;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14ddd4: 0x908a001f  lbu         $t2, 0x1F($a0)
    ctx->pc = 0x14ddd4u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 31)));
    // 0x14ddd8: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14ddd8u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14dddc: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14dddcu;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14dde0: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14dde0u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14dde4: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14dde4u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14dde8: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14dde8u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14ddec: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14ddecu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14ddf0: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14ddf0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14ddf4: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14ddf4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14ddf8: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14ddf8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14ddfc: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14ddfcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14de00: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14de00u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14de04: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14de04u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14de08: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14de08u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14de0c: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14de0cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14de10: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14de10u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14de14: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14de14u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14de18: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14de18u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14de1c: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14de1cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14de20: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14de20u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14de24: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14de24u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14de28: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14de28u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14de2c: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14de2cu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14de30: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14de30u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14de34: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14de34u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14de38: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14de38u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14de3c: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14de3cu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14de40: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14de40u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14de44: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14de44u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14de48: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14de48u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14de4c: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14de4cu;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14de50: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14de50u;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14de54: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14de54u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14de58: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14de58u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14de5c: 0x7cc50030  sq          $a1, 0x30($a2)
    ctx->pc = 0x14de5cu;
    WRITE128(ADD32(GPR_U32(ctx, 6), 48), GPR_VEC(ctx, 5));
    // 0x14de60: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14de60u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14de64: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14de64u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14de68: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14de68u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14de6c: 0x7da50030  sq          $a1, 0x30($t5)
    ctx->pc = 0x14de6cu;
    WRITE128(ADD32(GPR_U32(ctx, 13), 48), GPR_VEC(ctx, 5));
    // 0x14de70: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x14de70u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x14de74: 0x25ce0008  addiu       $t6, $t6, 0x8
    ctx->pc = 0x14de74u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 8));
    // 0x14de78: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x14de78u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14de7c: 0x1a36821  addu        $t5, $t5, $v1
    ctx->pc = 0x14de7cu;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), GPR_U32(ctx, 3)));
    // 0x14de80: 0xcc800060  pref        0x00, 0x60($a0)
    ctx->pc = 0x14de80u;
    // PREF instruction (ignored)
    // 0x14de84: 0x908c0001  lbu         $t4, 0x1($a0)
    ctx->pc = 0x14de84u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x14de88: 0x908b0000  lbu         $t3, 0x0($a0)
    ctx->pc = 0x14de88u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14de8c: 0x908a0011  lbu         $t2, 0x11($a0)
    ctx->pc = 0x14de8cu;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 17)));
    // 0x14de90: 0x90890010  lbu         $t1, 0x10($a0)
    ctx->pc = 0x14de90u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x14de94: 0x91c80000  lbu         $t0, 0x0($t6)
    ctx->pc = 0x14de94u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x14de98: 0x91c50040  lbu         $a1, 0x40($t6)
    ctx->pc = 0x14de98u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 64)));
    // 0x14de9c: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14de9cu;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14dea0: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14dea0u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14dea4: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14dea4u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14dea8: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14dea8u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14deac: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14deacu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14deb0: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14deb0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14deb4: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14deb4u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14deb8: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14deb8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14debc: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14debcu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14dec0: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14dec0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14dec4: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14dec4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14dec8: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14dec8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14decc: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14deccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14ded0: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14ded0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14ded4: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14ded4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14ded8: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14ded8u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14dedc: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14dedcu;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14dee0: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14dee0u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14dee4: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14dee4u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14dee8: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14dee8u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14deec: 0x90890012  lbu         $t1, 0x12($a0)
    ctx->pc = 0x14deecu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 18)));
    // 0x14def0: 0x91c80001  lbu         $t0, 0x1($t6)
    ctx->pc = 0x14def0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 1)));
    // 0x14def4: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14def4u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14def8: 0x91c50041  lbu         $a1, 0x41($t6)
    ctx->pc = 0x14def8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 65)));
    // 0x14defc: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14defcu;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14df00: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14df00u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14df04: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14df04u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14df08: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14df08u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14df0c: 0x908c0003  lbu         $t4, 0x3($a0)
    ctx->pc = 0x14df0cu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x14df10: 0x908b0002  lbu         $t3, 0x2($a0)
    ctx->pc = 0x14df10u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x14df14: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14df14u;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14df18: 0x908a0013  lbu         $t2, 0x13($a0)
    ctx->pc = 0x14df18u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 19)));
    // 0x14df1c: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14df1cu;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14df20: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14df20u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14df24: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14df24u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14df28: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14df28u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14df2c: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14df2cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14df30: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14df30u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14df34: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14df34u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14df38: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14df38u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14df3c: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14df3cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14df40: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14df40u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14df44: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14df44u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14df48: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14df48u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14df4c: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14df4cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14df50: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14df50u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14df54: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14df54u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14df58: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14df58u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14df5c: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14df5cu;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14df60: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14df60u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14df64: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14df64u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14df68: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14df68u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14df6c: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14df6cu;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14df70: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14df70u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14df74: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14df74u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14df78: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14df78u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14df7c: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14df7cu;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14df80: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14df80u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14df84: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14df84u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14df88: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14df88u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14df8c: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14df8cu;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14df90: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14df90u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14df94: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14df94u;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14df98: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14df98u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14df9c: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14df9cu;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14dfa0: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14dfa0u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14dfa4: 0x7cc50000  sq          $a1, 0x0($a2)
    ctx->pc = 0x14dfa4u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 0), GPR_VEC(ctx, 5));
    // 0x14dfa8: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14dfa8u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14dfac: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14dfacu;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14dfb0: 0x7da50000  sq          $a1, 0x0($t5)
    ctx->pc = 0x14dfb0u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 0), GPR_VEC(ctx, 5));
    // 0x14dfb4: 0x908c0005  lbu         $t4, 0x5($a0)
    ctx->pc = 0x14dfb4u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 5)));
    // 0x14dfb8: 0x908b0004  lbu         $t3, 0x4($a0)
    ctx->pc = 0x14dfb8u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x14dfbc: 0x908a0015  lbu         $t2, 0x15($a0)
    ctx->pc = 0x14dfbcu;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 21)));
    // 0x14dfc0: 0x90890014  lbu         $t1, 0x14($a0)
    ctx->pc = 0x14dfc0u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x14dfc4: 0x91c80002  lbu         $t0, 0x2($t6)
    ctx->pc = 0x14dfc4u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 2)));
    // 0x14dfc8: 0x91c50042  lbu         $a1, 0x42($t6)
    ctx->pc = 0x14dfc8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 66)));
    // 0x14dfcc: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14dfccu;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14dfd0: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14dfd0u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14dfd4: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14dfd4u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14dfd8: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14dfd8u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14dfdc: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14dfdcu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14dfe0: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14dfe0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14dfe4: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14dfe4u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14dfe8: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14dfe8u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14dfec: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14dfecu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14dff0: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14dff0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14dff4: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14dff4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14dff8: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14dff8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14dffc: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14dffcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14e000: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14e000u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14e004: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14e004u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14e008: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14e008u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14e00c: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14e00cu;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14e010: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14e010u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14e014: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14e014u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14e018: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14e018u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14e01c: 0x90890016  lbu         $t1, 0x16($a0)
    ctx->pc = 0x14e01cu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 22)));
    // 0x14e020: 0x91c80003  lbu         $t0, 0x3($t6)
    ctx->pc = 0x14e020u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 3)));
    // 0x14e024: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14e024u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14e028: 0x91c50043  lbu         $a1, 0x43($t6)
    ctx->pc = 0x14e028u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 67)));
    // 0x14e02c: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14e02cu;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14e030: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14e030u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14e034: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14e034u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14e038: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14e038u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14e03c: 0x908c0007  lbu         $t4, 0x7($a0)
    ctx->pc = 0x14e03cu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 7)));
    // 0x14e040: 0x908b0006  lbu         $t3, 0x6($a0)
    ctx->pc = 0x14e040u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 6)));
    // 0x14e044: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14e044u;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14e048: 0x908a0017  lbu         $t2, 0x17($a0)
    ctx->pc = 0x14e048u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 23)));
    // 0x14e04c: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14e04cu;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14e050: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14e050u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14e054: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14e054u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14e058: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14e058u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14e05c: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14e05cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14e060: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14e060u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14e064: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14e064u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14e068: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14e068u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14e06c: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14e06cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14e070: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14e070u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14e074: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14e074u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14e078: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14e078u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14e07c: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14e07cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14e080: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14e080u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14e084: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14e084u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14e088: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14e088u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14e08c: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14e08cu;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14e090: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14e090u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14e094: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14e094u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14e098: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14e098u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14e09c: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14e09cu;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14e0a0: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14e0a0u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14e0a4: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14e0a4u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14e0a8: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14e0a8u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14e0ac: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14e0acu;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14e0b0: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14e0b0u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14e0b4: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14e0b4u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14e0b8: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14e0b8u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14e0bc: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14e0bcu;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14e0c0: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14e0c0u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14e0c4: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14e0c4u;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14e0c8: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14e0c8u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14e0cc: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14e0ccu;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14e0d0: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14e0d0u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14e0d4: 0x7cc50010  sq          $a1, 0x10($a2)
    ctx->pc = 0x14e0d4u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 16), GPR_VEC(ctx, 5));
    // 0x14e0d8: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14e0d8u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14e0dc: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14e0dcu;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14e0e0: 0x7da50010  sq          $a1, 0x10($t5)
    ctx->pc = 0x14e0e0u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 16), GPR_VEC(ctx, 5));
    // 0x14e0e4: 0x908c0009  lbu         $t4, 0x9($a0)
    ctx->pc = 0x14e0e4u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 9)));
    // 0x14e0e8: 0x908b0008  lbu         $t3, 0x8($a0)
    ctx->pc = 0x14e0e8u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x14e0ec: 0x908a0019  lbu         $t2, 0x19($a0)
    ctx->pc = 0x14e0ecu;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 25)));
    // 0x14e0f0: 0x90890018  lbu         $t1, 0x18($a0)
    ctx->pc = 0x14e0f0u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x14e0f4: 0x91c80004  lbu         $t0, 0x4($t6)
    ctx->pc = 0x14e0f4u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 4)));
    // 0x14e0f8: 0x91c50044  lbu         $a1, 0x44($t6)
    ctx->pc = 0x14e0f8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 68)));
    // 0x14e0fc: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14e0fcu;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14e100: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14e100u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14e104: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14e104u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14e108: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14e108u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14e10c: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14e10cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14e110: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14e110u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14e114: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14e114u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14e118: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14e118u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14e11c: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14e11cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14e120: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14e120u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14e124: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14e124u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14e128: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14e128u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14e12c: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14e12cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14e130: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14e130u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14e134: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14e134u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14e138: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14e138u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14e13c: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14e13cu;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14e140: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14e140u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14e144: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14e144u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14e148: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14e148u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14e14c: 0x9089001a  lbu         $t1, 0x1A($a0)
    ctx->pc = 0x14e14cu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 26)));
    // 0x14e150: 0x91c80005  lbu         $t0, 0x5($t6)
    ctx->pc = 0x14e150u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 5)));
    // 0x14e154: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14e154u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14e158: 0x91c50045  lbu         $a1, 0x45($t6)
    ctx->pc = 0x14e158u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 69)));
    // 0x14e15c: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14e15cu;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14e160: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14e160u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14e164: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14e164u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14e168: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14e168u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14e16c: 0x908c000b  lbu         $t4, 0xB($a0)
    ctx->pc = 0x14e16cu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 11)));
    // 0x14e170: 0x908b000a  lbu         $t3, 0xA($a0)
    ctx->pc = 0x14e170u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 10)));
    // 0x14e174: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14e174u;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14e178: 0x908a001b  lbu         $t2, 0x1B($a0)
    ctx->pc = 0x14e178u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 27)));
    // 0x14e17c: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14e17cu;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14e180: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14e180u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14e184: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14e184u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14e188: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14e188u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14e18c: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14e18cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14e190: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14e190u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14e194: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14e194u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14e198: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14e198u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14e19c: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14e19cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14e1a0: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14e1a0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14e1a4: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14e1a4u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14e1a8: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14e1a8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14e1ac: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14e1acu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14e1b0: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14e1b0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14e1b4: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14e1b4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14e1b8: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14e1b8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14e1bc: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14e1bcu;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14e1c0: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14e1c0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14e1c4: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14e1c4u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14e1c8: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14e1c8u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14e1cc: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14e1ccu;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14e1d0: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14e1d0u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14e1d4: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14e1d4u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14e1d8: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14e1d8u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14e1dc: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14e1dcu;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14e1e0: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14e1e0u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14e1e4: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14e1e4u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14e1e8: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14e1e8u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14e1ec: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14e1ecu;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14e1f0: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14e1f0u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14e1f4: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14e1f4u;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14e1f8: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14e1f8u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14e1fc: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14e1fcu;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14e200: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14e200u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14e204: 0x7cc50020  sq          $a1, 0x20($a2)
    ctx->pc = 0x14e204u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 32), GPR_VEC(ctx, 5));
    // 0x14e208: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14e208u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14e20c: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14e20cu;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14e210: 0x7da50020  sq          $a1, 0x20($t5)
    ctx->pc = 0x14e210u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 32), GPR_VEC(ctx, 5));
    // 0x14e214: 0x908c000d  lbu         $t4, 0xD($a0)
    ctx->pc = 0x14e214u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 13)));
    // 0x14e218: 0x908b000c  lbu         $t3, 0xC($a0)
    ctx->pc = 0x14e218u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x14e21c: 0x908a001d  lbu         $t2, 0x1D($a0)
    ctx->pc = 0x14e21cu;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 29)));
    // 0x14e220: 0x9089001c  lbu         $t1, 0x1C($a0)
    ctx->pc = 0x14e220u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x14e224: 0x91c80006  lbu         $t0, 0x6($t6)
    ctx->pc = 0x14e224u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 6)));
    // 0x14e228: 0x91c50046  lbu         $a1, 0x46($t6)
    ctx->pc = 0x14e228u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 70)));
    // 0x14e22c: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14e22cu;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14e230: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14e230u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14e234: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14e234u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14e238: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14e238u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14e23c: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14e23cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14e240: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14e240u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14e244: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14e244u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14e248: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14e248u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14e24c: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14e24cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14e250: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14e250u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14e254: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14e254u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14e258: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14e258u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14e25c: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14e25cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14e260: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14e260u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14e264: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14e264u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14e268: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14e268u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14e26c: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14e26cu;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14e270: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14e270u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14e274: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14e274u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14e278: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14e278u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14e27c: 0x9089001e  lbu         $t1, 0x1E($a0)
    ctx->pc = 0x14e27cu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 30)));
    // 0x14e280: 0x91c80007  lbu         $t0, 0x7($t6)
    ctx->pc = 0x14e280u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 7)));
    // 0x14e284: 0x91c50047  lbu         $a1, 0x47($t6)
    ctx->pc = 0x14e284u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 71)));
    // 0x14e288: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14e288u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14e28c: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14e28cu;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14e290: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14e290u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14e294: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14e294u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14e298: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14e298u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14e29c: 0x908c000f  lbu         $t4, 0xF($a0)
    ctx->pc = 0x14e29cu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 15)));
    // 0x14e2a0: 0x908b000e  lbu         $t3, 0xE($a0)
    ctx->pc = 0x14e2a0u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 14)));
    // 0x14e2a4: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14e2a4u;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14e2a8: 0x908a001f  lbu         $t2, 0x1F($a0)
    ctx->pc = 0x14e2a8u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 31)));
    // 0x14e2ac: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14e2acu;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14e2b0: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14e2b0u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14e2b4: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14e2b4u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14e2b8: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14e2b8u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14e2bc: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14e2bcu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14e2c0: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14e2c0u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14e2c4: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14e2c4u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14e2c8: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14e2c8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14e2cc: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14e2ccu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14e2d0: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14e2d0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14e2d4: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14e2d4u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14e2d8: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14e2d8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14e2dc: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14e2dcu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14e2e0: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14e2e0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14e2e4: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14e2e4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14e2e8: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14e2e8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14e2ec: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14e2ecu;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14e2f0: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14e2f0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14e2f4: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14e2f4u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14e2f8: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14e2f8u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14e2fc: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14e2fcu;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14e300: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14e300u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14e304: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14e304u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14e308: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14e308u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14e30c: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14e30cu;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14e310: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14e310u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14e314: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14e314u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14e318: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14e318u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14e31c: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14e31cu;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14e320: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14e320u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14e324: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14e324u;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14e328: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14e328u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14e32c: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14e32cu;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14e330: 0x7cc50030  sq          $a1, 0x30($a2)
    ctx->pc = 0x14e330u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 48), GPR_VEC(ctx, 5));
    // 0x14e334: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14e334u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14e338: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14e338u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14e33c: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14e33cu;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14e340: 0x7da50030  sq          $a1, 0x30($t5)
    ctx->pc = 0x14e340u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 48), GPR_VEC(ctx, 5));
    // 0x14e344: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x14e344u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x14e348: 0x25ce0008  addiu       $t6, $t6, 0x8
    ctx->pc = 0x14e348u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 8));
    // 0x14e34c: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x14e34cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14e350: 0x1a36821  addu        $t5, $t5, $v1
    ctx->pc = 0x14e350u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), GPR_U32(ctx, 3)));
    // 0x14e354: 0xcc800080  pref        0x00, 0x80($a0)
    ctx->pc = 0x14e354u;
    // PREF instruction (ignored)
    // 0x14e358: 0x908c0001  lbu         $t4, 0x1($a0)
    ctx->pc = 0x14e358u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x14e35c: 0x908b0000  lbu         $t3, 0x0($a0)
    ctx->pc = 0x14e35cu;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14e360: 0x908a0011  lbu         $t2, 0x11($a0)
    ctx->pc = 0x14e360u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 17)));
    // 0x14e364: 0x90890010  lbu         $t1, 0x10($a0)
    ctx->pc = 0x14e364u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x14e368: 0x91c80000  lbu         $t0, 0x0($t6)
    ctx->pc = 0x14e368u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x14e36c: 0x91c50040  lbu         $a1, 0x40($t6)
    ctx->pc = 0x14e36cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 64)));
    // 0x14e370: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14e370u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14e374: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14e374u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14e378: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14e378u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14e37c: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14e37cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14e380: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14e380u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14e384: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14e384u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14e388: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14e388u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14e38c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14e38cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14e390: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14e390u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14e394: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14e394u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14e398: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14e398u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14e39c: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14e39cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14e3a0: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14e3a0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14e3a4: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14e3a4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14e3a8: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14e3a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14e3ac: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14e3acu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14e3b0: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14e3b0u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14e3b4: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14e3b4u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14e3b8: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14e3b8u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14e3bc: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14e3bcu;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14e3c0: 0x90890012  lbu         $t1, 0x12($a0)
    ctx->pc = 0x14e3c0u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 18)));
    // 0x14e3c4: 0x91c80001  lbu         $t0, 0x1($t6)
    ctx->pc = 0x14e3c4u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 1)));
    // 0x14e3c8: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14e3c8u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14e3cc: 0x91c50041  lbu         $a1, 0x41($t6)
    ctx->pc = 0x14e3ccu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 65)));
    // 0x14e3d0: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14e3d0u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14e3d4: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14e3d4u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14e3d8: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14e3d8u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14e3dc: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14e3dcu;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14e3e0: 0x908c0003  lbu         $t4, 0x3($a0)
    ctx->pc = 0x14e3e0u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x14e3e4: 0x908b0002  lbu         $t3, 0x2($a0)
    ctx->pc = 0x14e3e4u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x14e3e8: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14e3e8u;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14e3ec: 0x908a0013  lbu         $t2, 0x13($a0)
    ctx->pc = 0x14e3ecu;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 19)));
    // 0x14e3f0: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14e3f0u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14e3f4: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14e3f4u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14e3f8: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14e3f8u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14e3fc: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14e3fcu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14e400: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14e400u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14e404: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14e404u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14e408: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14e408u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14e40c: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14e40cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14e410: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14e410u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14e414: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14e414u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14e418: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14e418u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14e41c: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14e41cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14e420: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14e420u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14e424: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14e424u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14e428: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14e428u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14e42c: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14e42cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14e430: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14e430u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14e434: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14e434u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14e438: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14e438u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14e43c: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14e43cu;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14e440: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14e440u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14e444: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14e444u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14e448: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14e448u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14e44c: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14e44cu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14e450: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14e450u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14e454: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14e454u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14e458: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14e458u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14e45c: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14e45cu;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14e460: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14e460u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14e464: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14e464u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14e468: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14e468u;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14e46c: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14e46cu;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14e470: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14e470u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14e474: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14e474u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14e478: 0x7cc50000  sq          $a1, 0x0($a2)
    ctx->pc = 0x14e478u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 0), GPR_VEC(ctx, 5));
    // 0x14e47c: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14e47cu;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14e480: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14e480u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14e484: 0x7da50000  sq          $a1, 0x0($t5)
    ctx->pc = 0x14e484u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 0), GPR_VEC(ctx, 5));
    // 0x14e488: 0x908c0005  lbu         $t4, 0x5($a0)
    ctx->pc = 0x14e488u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 5)));
    // 0x14e48c: 0x908b0004  lbu         $t3, 0x4($a0)
    ctx->pc = 0x14e48cu;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x14e490: 0x908a0015  lbu         $t2, 0x15($a0)
    ctx->pc = 0x14e490u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 21)));
    // 0x14e494: 0x90890014  lbu         $t1, 0x14($a0)
    ctx->pc = 0x14e494u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x14e498: 0x91c80002  lbu         $t0, 0x2($t6)
    ctx->pc = 0x14e498u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 2)));
    // 0x14e49c: 0x91c50042  lbu         $a1, 0x42($t6)
    ctx->pc = 0x14e49cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 66)));
    // 0x14e4a0: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14e4a0u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14e4a4: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14e4a4u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14e4a8: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14e4a8u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14e4ac: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14e4acu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14e4b0: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14e4b0u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14e4b4: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14e4b4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14e4b8: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14e4b8u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14e4bc: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14e4bcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14e4c0: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14e4c0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14e4c4: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14e4c4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14e4c8: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14e4c8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14e4cc: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14e4ccu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14e4d0: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14e4d0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14e4d4: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14e4d4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14e4d8: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14e4d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14e4dc: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14e4dcu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14e4e0: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14e4e0u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14e4e4: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14e4e4u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14e4e8: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14e4e8u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14e4ec: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14e4ecu;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14e4f0: 0x90890016  lbu         $t1, 0x16($a0)
    ctx->pc = 0x14e4f0u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 22)));
    // 0x14e4f4: 0x91c80003  lbu         $t0, 0x3($t6)
    ctx->pc = 0x14e4f4u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 3)));
    // 0x14e4f8: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14e4f8u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14e4fc: 0x91c50043  lbu         $a1, 0x43($t6)
    ctx->pc = 0x14e4fcu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 67)));
    // 0x14e500: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14e500u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14e504: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14e504u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14e508: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14e508u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14e50c: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14e50cu;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14e510: 0x908c0007  lbu         $t4, 0x7($a0)
    ctx->pc = 0x14e510u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 7)));
    // 0x14e514: 0x908b0006  lbu         $t3, 0x6($a0)
    ctx->pc = 0x14e514u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 6)));
    // 0x14e518: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14e518u;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14e51c: 0x908a0017  lbu         $t2, 0x17($a0)
    ctx->pc = 0x14e51cu;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 23)));
    // 0x14e520: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14e520u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14e524: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14e524u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14e528: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14e528u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14e52c: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14e52cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14e530: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14e530u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14e534: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14e534u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14e538: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14e538u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14e53c: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14e53cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14e540: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14e540u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14e544: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14e544u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14e548: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14e548u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14e54c: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14e54cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14e550: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14e550u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14e554: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14e554u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14e558: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14e558u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14e55c: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14e55cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14e560: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14e560u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14e564: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14e564u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14e568: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14e568u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14e56c: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14e56cu;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14e570: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14e570u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14e574: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14e574u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14e578: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14e578u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14e57c: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14e57cu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14e580: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14e580u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14e584: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14e584u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14e588: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14e588u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14e58c: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14e58cu;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14e590: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14e590u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14e594: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14e594u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14e598: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14e598u;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14e59c: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14e59cu;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14e5a0: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14e5a0u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14e5a4: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14e5a4u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14e5a8: 0x7cc50010  sq          $a1, 0x10($a2)
    ctx->pc = 0x14e5a8u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 16), GPR_VEC(ctx, 5));
    // 0x14e5ac: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14e5acu;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14e5b0: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14e5b0u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14e5b4: 0x7da50010  sq          $a1, 0x10($t5)
    ctx->pc = 0x14e5b4u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 16), GPR_VEC(ctx, 5));
    // 0x14e5b8: 0x908c0009  lbu         $t4, 0x9($a0)
    ctx->pc = 0x14e5b8u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 9)));
    // 0x14e5bc: 0x908b0008  lbu         $t3, 0x8($a0)
    ctx->pc = 0x14e5bcu;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x14e5c0: 0x908a0019  lbu         $t2, 0x19($a0)
    ctx->pc = 0x14e5c0u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 25)));
    // 0x14e5c4: 0x90890018  lbu         $t1, 0x18($a0)
    ctx->pc = 0x14e5c4u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x14e5c8: 0x91c80004  lbu         $t0, 0x4($t6)
    ctx->pc = 0x14e5c8u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 4)));
    // 0x14e5cc: 0x91c50044  lbu         $a1, 0x44($t6)
    ctx->pc = 0x14e5ccu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 68)));
    // 0x14e5d0: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14e5d0u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14e5d4: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14e5d4u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14e5d8: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14e5d8u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14e5dc: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14e5dcu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14e5e0: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14e5e0u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14e5e4: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14e5e4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14e5e8: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14e5e8u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14e5ec: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14e5ecu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14e5f0: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14e5f0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14e5f4: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14e5f4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14e5f8: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14e5f8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14e5fc: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14e5fcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14e600: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14e600u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14e604: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14e604u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14e608: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14e608u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14e60c: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14e60cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14e610: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14e610u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14e614: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14e614u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14e618: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14e618u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14e61c: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14e61cu;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14e620: 0x9089001a  lbu         $t1, 0x1A($a0)
    ctx->pc = 0x14e620u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 26)));
    // 0x14e624: 0x91c80005  lbu         $t0, 0x5($t6)
    ctx->pc = 0x14e624u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 5)));
    // 0x14e628: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14e628u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14e62c: 0x91c50045  lbu         $a1, 0x45($t6)
    ctx->pc = 0x14e62cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 69)));
    // 0x14e630: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14e630u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14e634: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14e634u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14e638: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14e638u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14e63c: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14e63cu;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14e640: 0x908c000b  lbu         $t4, 0xB($a0)
    ctx->pc = 0x14e640u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 11)));
    // 0x14e644: 0x908b000a  lbu         $t3, 0xA($a0)
    ctx->pc = 0x14e644u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 10)));
    // 0x14e648: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14e648u;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14e64c: 0x908a001b  lbu         $t2, 0x1B($a0)
    ctx->pc = 0x14e64cu;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 27)));
    // 0x14e650: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14e650u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14e654: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14e654u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14e658: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14e658u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14e65c: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14e65cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14e660: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14e660u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14e664: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14e664u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14e668: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14e668u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14e66c: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14e66cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14e670: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14e670u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14e674: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14e674u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14e678: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14e678u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14e67c: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14e67cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14e680: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14e680u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14e684: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14e684u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14e688: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14e688u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14e68c: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14e68cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14e690: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14e690u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14e694: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14e694u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14e698: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14e698u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14e69c: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14e69cu;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14e6a0: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14e6a0u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14e6a4: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14e6a4u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14e6a8: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14e6a8u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14e6ac: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14e6acu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14e6b0: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14e6b0u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14e6b4: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14e6b4u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14e6b8: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14e6b8u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14e6bc: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14e6bcu;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14e6c0: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14e6c0u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14e6c4: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14e6c4u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14e6c8: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14e6c8u;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14e6cc: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14e6ccu;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14e6d0: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14e6d0u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14e6d4: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14e6d4u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14e6d8: 0x7cc50020  sq          $a1, 0x20($a2)
    ctx->pc = 0x14e6d8u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 32), GPR_VEC(ctx, 5));
    // 0x14e6dc: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14e6dcu;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14e6e0: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14e6e0u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14e6e4: 0x7da50020  sq          $a1, 0x20($t5)
    ctx->pc = 0x14e6e4u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 32), GPR_VEC(ctx, 5));
    // 0x14e6e8: 0x908c000d  lbu         $t4, 0xD($a0)
    ctx->pc = 0x14e6e8u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 13)));
    // 0x14e6ec: 0x908b000c  lbu         $t3, 0xC($a0)
    ctx->pc = 0x14e6ecu;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x14e6f0: 0x908a001d  lbu         $t2, 0x1D($a0)
    ctx->pc = 0x14e6f0u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 29)));
    // 0x14e6f4: 0x9089001c  lbu         $t1, 0x1C($a0)
    ctx->pc = 0x14e6f4u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x14e6f8: 0x91c80006  lbu         $t0, 0x6($t6)
    ctx->pc = 0x14e6f8u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 6)));
    // 0x14e6fc: 0x91c50046  lbu         $a1, 0x46($t6)
    ctx->pc = 0x14e6fcu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 70)));
    // 0x14e700: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14e700u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14e704: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14e704u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14e708: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14e708u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14e70c: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14e70cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14e710: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14e710u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14e714: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14e714u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14e718: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14e718u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14e71c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14e71cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14e720: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14e720u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14e724: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14e724u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14e728: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14e728u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14e72c: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14e72cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14e730: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14e730u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14e734: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14e734u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14e738: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14e738u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14e73c: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14e73cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14e740: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14e740u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14e744: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14e744u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14e748: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14e748u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14e74c: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14e74cu;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14e750: 0x9089001e  lbu         $t1, 0x1E($a0)
    ctx->pc = 0x14e750u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 30)));
    // 0x14e754: 0x91c80007  lbu         $t0, 0x7($t6)
    ctx->pc = 0x14e754u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 7)));
    // 0x14e758: 0x91c50047  lbu         $a1, 0x47($t6)
    ctx->pc = 0x14e758u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 71)));
    // 0x14e75c: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14e75cu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14e760: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14e760u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14e764: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14e764u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14e768: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14e768u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14e76c: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14e76cu;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14e770: 0x908c000f  lbu         $t4, 0xF($a0)
    ctx->pc = 0x14e770u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 15)));
    // 0x14e774: 0x908b000e  lbu         $t3, 0xE($a0)
    ctx->pc = 0x14e774u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 14)));
    // 0x14e778: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14e778u;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14e77c: 0x908a001f  lbu         $t2, 0x1F($a0)
    ctx->pc = 0x14e77cu;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 31)));
    // 0x14e780: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14e780u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14e784: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14e784u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14e788: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14e788u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14e78c: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14e78cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14e790: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14e790u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14e794: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14e794u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14e798: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14e798u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14e79c: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14e79cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14e7a0: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14e7a0u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14e7a4: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14e7a4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14e7a8: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14e7a8u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14e7ac: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14e7acu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14e7b0: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14e7b0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14e7b4: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14e7b4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14e7b8: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14e7b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14e7bc: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14e7bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14e7c0: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14e7c0u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14e7c4: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14e7c4u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14e7c8: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14e7c8u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14e7cc: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14e7ccu;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14e7d0: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14e7d0u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14e7d4: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14e7d4u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14e7d8: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14e7d8u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14e7dc: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14e7dcu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14e7e0: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14e7e0u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14e7e4: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14e7e4u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14e7e8: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14e7e8u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14e7ec: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14e7ecu;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14e7f0: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14e7f0u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14e7f4: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14e7f4u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14e7f8: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14e7f8u;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14e7fc: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14e7fcu;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14e800: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14e800u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14e804: 0x7cc50030  sq          $a1, 0x30($a2)
    ctx->pc = 0x14e804u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 48), GPR_VEC(ctx, 5));
    // 0x14e808: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14e808u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14e80c: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14e80cu;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14e810: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14e810u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14e814: 0x7da50030  sq          $a1, 0x30($t5)
    ctx->pc = 0x14e814u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 48), GPR_VEC(ctx, 5));
    // 0x14e818: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x14e818u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x14e81c: 0x25ce0008  addiu       $t6, $t6, 0x8
    ctx->pc = 0x14e81cu;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 8));
    // 0x14e820: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x14e820u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14e824: 0x1a36821  addu        $t5, $t5, $v1
    ctx->pc = 0x14e824u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), GPR_U32(ctx, 3)));
    // 0x14e828: 0xcc8000a0  pref        0x00, 0xA0($a0)
    ctx->pc = 0x14e828u;
    // PREF instruction (ignored)
    // 0x14e82c: 0x908c0001  lbu         $t4, 0x1($a0)
    ctx->pc = 0x14e82cu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x14e830: 0x908b0000  lbu         $t3, 0x0($a0)
    ctx->pc = 0x14e830u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14e834: 0x908a0011  lbu         $t2, 0x11($a0)
    ctx->pc = 0x14e834u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 17)));
    // 0x14e838: 0x90890010  lbu         $t1, 0x10($a0)
    ctx->pc = 0x14e838u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x14e83c: 0x91c80000  lbu         $t0, 0x0($t6)
    ctx->pc = 0x14e83cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x14e840: 0x91c50040  lbu         $a1, 0x40($t6)
    ctx->pc = 0x14e840u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 64)));
    // 0x14e844: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14e844u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14e848: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14e848u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14e84c: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14e84cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14e850: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14e850u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14e854: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14e854u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14e858: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14e858u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14e85c: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14e85cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14e860: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14e860u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14e864: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14e864u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14e868: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14e868u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14e86c: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14e86cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14e870: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14e870u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14e874: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14e874u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14e878: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14e878u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14e87c: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14e87cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14e880: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14e880u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14e884: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14e884u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14e888: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14e888u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14e88c: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14e88cu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14e890: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14e890u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14e894: 0x90890012  lbu         $t1, 0x12($a0)
    ctx->pc = 0x14e894u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 18)));
    // 0x14e898: 0x91c80001  lbu         $t0, 0x1($t6)
    ctx->pc = 0x14e898u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 1)));
    // 0x14e89c: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14e89cu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14e8a0: 0x91c50041  lbu         $a1, 0x41($t6)
    ctx->pc = 0x14e8a0u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 65)));
    // 0x14e8a4: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14e8a4u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14e8a8: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14e8a8u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14e8ac: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14e8acu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14e8b0: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14e8b0u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14e8b4: 0x908c0003  lbu         $t4, 0x3($a0)
    ctx->pc = 0x14e8b4u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x14e8b8: 0x908b0002  lbu         $t3, 0x2($a0)
    ctx->pc = 0x14e8b8u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x14e8bc: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14e8bcu;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14e8c0: 0x908a0013  lbu         $t2, 0x13($a0)
    ctx->pc = 0x14e8c0u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 19)));
    // 0x14e8c4: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14e8c4u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14e8c8: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14e8c8u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14e8cc: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14e8ccu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14e8d0: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14e8d0u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14e8d4: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14e8d4u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14e8d8: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14e8d8u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14e8dc: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14e8dcu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14e8e0: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14e8e0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14e8e4: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14e8e4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14e8e8: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14e8e8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14e8ec: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14e8ecu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14e8f0: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14e8f0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14e8f4: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14e8f4u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14e8f8: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14e8f8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14e8fc: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14e8fcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14e900: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14e900u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14e904: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14e904u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14e908: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14e908u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14e90c: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14e90cu;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14e910: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14e910u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14e914: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14e914u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14e918: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14e918u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14e91c: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14e91cu;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14e920: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14e920u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14e924: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14e924u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14e928: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14e928u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14e92c: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14e92cu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14e930: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14e930u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14e934: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14e934u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14e938: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14e938u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14e93c: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14e93cu;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14e940: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14e940u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14e944: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14e944u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14e948: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14e948u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14e94c: 0x7cc50000  sq          $a1, 0x0($a2)
    ctx->pc = 0x14e94cu;
    WRITE128(ADD32(GPR_U32(ctx, 6), 0), GPR_VEC(ctx, 5));
    // 0x14e950: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14e950u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14e954: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14e954u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14e958: 0x7da50000  sq          $a1, 0x0($t5)
    ctx->pc = 0x14e958u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 0), GPR_VEC(ctx, 5));
    // 0x14e95c: 0x908c0005  lbu         $t4, 0x5($a0)
    ctx->pc = 0x14e95cu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 5)));
    // 0x14e960: 0x908b0004  lbu         $t3, 0x4($a0)
    ctx->pc = 0x14e960u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x14e964: 0x908a0015  lbu         $t2, 0x15($a0)
    ctx->pc = 0x14e964u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 21)));
    // 0x14e968: 0x90890014  lbu         $t1, 0x14($a0)
    ctx->pc = 0x14e968u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x14e96c: 0x91c80002  lbu         $t0, 0x2($t6)
    ctx->pc = 0x14e96cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 2)));
    // 0x14e970: 0x91c50042  lbu         $a1, 0x42($t6)
    ctx->pc = 0x14e970u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 66)));
    // 0x14e974: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14e974u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14e978: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14e978u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14e97c: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14e97cu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14e980: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14e980u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14e984: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14e984u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14e988: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14e988u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14e98c: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14e98cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14e990: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14e990u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14e994: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14e994u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14e998: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14e998u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14e99c: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14e99cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14e9a0: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14e9a0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14e9a4: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14e9a4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14e9a8: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14e9a8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14e9ac: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14e9acu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14e9b0: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14e9b0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14e9b4: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14e9b4u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14e9b8: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14e9b8u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14e9bc: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14e9bcu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14e9c0: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14e9c0u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14e9c4: 0x90890016  lbu         $t1, 0x16($a0)
    ctx->pc = 0x14e9c4u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 22)));
    // 0x14e9c8: 0x91c80003  lbu         $t0, 0x3($t6)
    ctx->pc = 0x14e9c8u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 3)));
    // 0x14e9cc: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14e9ccu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14e9d0: 0x91c50043  lbu         $a1, 0x43($t6)
    ctx->pc = 0x14e9d0u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 67)));
    // 0x14e9d4: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14e9d4u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14e9d8: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14e9d8u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14e9dc: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14e9dcu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14e9e0: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14e9e0u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14e9e4: 0x908c0007  lbu         $t4, 0x7($a0)
    ctx->pc = 0x14e9e4u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 7)));
    // 0x14e9e8: 0x908b0006  lbu         $t3, 0x6($a0)
    ctx->pc = 0x14e9e8u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 6)));
    // 0x14e9ec: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14e9ecu;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14e9f0: 0x908a0017  lbu         $t2, 0x17($a0)
    ctx->pc = 0x14e9f0u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 23)));
    // 0x14e9f4: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14e9f4u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14e9f8: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14e9f8u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14e9fc: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14e9fcu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14ea00: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14ea00u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14ea04: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14ea04u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14ea08: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14ea08u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14ea0c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14ea0cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14ea10: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14ea10u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14ea14: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14ea14u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14ea18: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14ea18u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14ea1c: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14ea1cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14ea20: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14ea20u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14ea24: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14ea24u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14ea28: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14ea28u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14ea2c: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14ea2cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14ea30: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14ea30u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14ea34: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14ea34u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14ea38: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14ea38u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14ea3c: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14ea3cu;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14ea40: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14ea40u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14ea44: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14ea44u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14ea48: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14ea48u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14ea4c: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14ea4cu;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14ea50: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14ea50u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14ea54: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14ea54u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14ea58: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14ea58u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14ea5c: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14ea5cu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14ea60: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14ea60u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14ea64: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14ea64u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14ea68: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14ea68u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14ea6c: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14ea6cu;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14ea70: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14ea70u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14ea74: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14ea74u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14ea78: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14ea78u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14ea7c: 0x7cc50010  sq          $a1, 0x10($a2)
    ctx->pc = 0x14ea7cu;
    WRITE128(ADD32(GPR_U32(ctx, 6), 16), GPR_VEC(ctx, 5));
    // 0x14ea80: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14ea80u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14ea84: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14ea84u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14ea88: 0x7da50010  sq          $a1, 0x10($t5)
    ctx->pc = 0x14ea88u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 16), GPR_VEC(ctx, 5));
    // 0x14ea8c: 0x908c0009  lbu         $t4, 0x9($a0)
    ctx->pc = 0x14ea8cu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 9)));
    // 0x14ea90: 0x908b0008  lbu         $t3, 0x8($a0)
    ctx->pc = 0x14ea90u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x14ea94: 0x908a0019  lbu         $t2, 0x19($a0)
    ctx->pc = 0x14ea94u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 25)));
    // 0x14ea98: 0x90890018  lbu         $t1, 0x18($a0)
    ctx->pc = 0x14ea98u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x14ea9c: 0x91c80004  lbu         $t0, 0x4($t6)
    ctx->pc = 0x14ea9cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 4)));
    // 0x14eaa0: 0x91c50044  lbu         $a1, 0x44($t6)
    ctx->pc = 0x14eaa0u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 68)));
    // 0x14eaa4: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14eaa4u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14eaa8: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14eaa8u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14eaac: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14eaacu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14eab0: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14eab0u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14eab4: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14eab4u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14eab8: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14eab8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14eabc: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14eabcu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14eac0: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14eac0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14eac4: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14eac4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14eac8: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14eac8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14eacc: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14eaccu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14ead0: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14ead0u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14ead4: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14ead4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14ead8: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14ead8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14eadc: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14eadcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14eae0: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14eae0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14eae4: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14eae4u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14eae8: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14eae8u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14eaec: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14eaecu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14eaf0: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14eaf0u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14eaf4: 0x9089001a  lbu         $t1, 0x1A($a0)
    ctx->pc = 0x14eaf4u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 26)));
    // 0x14eaf8: 0x91c80005  lbu         $t0, 0x5($t6)
    ctx->pc = 0x14eaf8u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 5)));
    // 0x14eafc: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14eafcu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14eb00: 0x91c50045  lbu         $a1, 0x45($t6)
    ctx->pc = 0x14eb00u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 69)));
    // 0x14eb04: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14eb04u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14eb08: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14eb08u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14eb0c: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14eb0cu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14eb10: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14eb10u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14eb14: 0x908c000b  lbu         $t4, 0xB($a0)
    ctx->pc = 0x14eb14u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 11)));
    // 0x14eb18: 0x908b000a  lbu         $t3, 0xA($a0)
    ctx->pc = 0x14eb18u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 10)));
    // 0x14eb1c: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14eb1cu;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14eb20: 0x908a001b  lbu         $t2, 0x1B($a0)
    ctx->pc = 0x14eb20u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 27)));
    // 0x14eb24: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14eb24u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14eb28: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14eb28u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14eb2c: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14eb2cu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14eb30: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14eb30u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14eb34: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14eb34u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14eb38: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14eb38u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14eb3c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14eb3cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14eb40: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14eb40u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14eb44: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14eb44u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14eb48: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14eb48u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14eb4c: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14eb4cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14eb50: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14eb50u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14eb54: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14eb54u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14eb58: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14eb58u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14eb5c: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14eb5cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14eb60: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14eb60u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14eb64: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14eb64u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14eb68: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14eb68u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14eb6c: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14eb6cu;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14eb70: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14eb70u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14eb74: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14eb74u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14eb78: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14eb78u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14eb7c: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14eb7cu;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14eb80: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14eb80u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14eb84: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14eb84u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14eb88: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14eb88u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14eb8c: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14eb8cu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14eb90: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14eb90u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14eb94: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14eb94u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14eb98: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14eb98u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14eb9c: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14eb9cu;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14eba0: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14eba0u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14eba4: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14eba4u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14eba8: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14eba8u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14ebac: 0x7cc50020  sq          $a1, 0x20($a2)
    ctx->pc = 0x14ebacu;
    WRITE128(ADD32(GPR_U32(ctx, 6), 32), GPR_VEC(ctx, 5));
    // 0x14ebb0: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14ebb0u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14ebb4: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14ebb4u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14ebb8: 0x7da50020  sq          $a1, 0x20($t5)
    ctx->pc = 0x14ebb8u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 32), GPR_VEC(ctx, 5));
    // 0x14ebbc: 0x908c000d  lbu         $t4, 0xD($a0)
    ctx->pc = 0x14ebbcu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 13)));
    // 0x14ebc0: 0x908b000c  lbu         $t3, 0xC($a0)
    ctx->pc = 0x14ebc0u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x14ebc4: 0x908a001d  lbu         $t2, 0x1D($a0)
    ctx->pc = 0x14ebc4u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 29)));
    // 0x14ebc8: 0x9089001c  lbu         $t1, 0x1C($a0)
    ctx->pc = 0x14ebc8u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x14ebcc: 0x91c80006  lbu         $t0, 0x6($t6)
    ctx->pc = 0x14ebccu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 6)));
    // 0x14ebd0: 0x91c50046  lbu         $a1, 0x46($t6)
    ctx->pc = 0x14ebd0u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 70)));
    // 0x14ebd4: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14ebd4u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14ebd8: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14ebd8u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14ebdc: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14ebdcu;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14ebe0: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14ebe0u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14ebe4: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14ebe4u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14ebe8: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14ebe8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14ebec: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14ebecu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14ebf0: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14ebf0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14ebf4: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14ebf4u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14ebf8: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14ebf8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14ebfc: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14ebfcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14ec00: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14ec00u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14ec04: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14ec04u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14ec08: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14ec08u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14ec0c: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14ec0cu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14ec10: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14ec10u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14ec14: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14ec14u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14ec18: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14ec18u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14ec1c: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14ec1cu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14ec20: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14ec20u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14ec24: 0x9089001e  lbu         $t1, 0x1E($a0)
    ctx->pc = 0x14ec24u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 30)));
    // 0x14ec28: 0x91c80007  lbu         $t0, 0x7($t6)
    ctx->pc = 0x14ec28u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 7)));
    // 0x14ec2c: 0x91c50047  lbu         $a1, 0x47($t6)
    ctx->pc = 0x14ec2cu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 71)));
    // 0x14ec30: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14ec30u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14ec34: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14ec34u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14ec38: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14ec38u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14ec3c: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14ec3cu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14ec40: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14ec40u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14ec44: 0x908c000f  lbu         $t4, 0xF($a0)
    ctx->pc = 0x14ec44u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 15)));
    // 0x14ec48: 0x908b000e  lbu         $t3, 0xE($a0)
    ctx->pc = 0x14ec48u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 14)));
    // 0x14ec4c: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14ec4cu;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14ec50: 0x908a001f  lbu         $t2, 0x1F($a0)
    ctx->pc = 0x14ec50u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 31)));
    // 0x14ec54: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14ec54u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14ec58: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14ec58u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14ec5c: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14ec5cu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14ec60: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14ec60u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14ec64: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14ec64u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14ec68: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14ec68u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14ec6c: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14ec6cu;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14ec70: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14ec70u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14ec74: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14ec74u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14ec78: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14ec78u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14ec7c: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14ec7cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14ec80: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14ec80u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14ec84: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14ec84u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14ec88: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14ec88u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14ec8c: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14ec8cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14ec90: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14ec90u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14ec94: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14ec94u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14ec98: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14ec98u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14ec9c: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14ec9cu;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14eca0: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14eca0u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14eca4: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14eca4u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14eca8: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14eca8u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14ecac: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14ecacu;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14ecb0: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14ecb0u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14ecb4: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14ecb4u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14ecb8: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14ecb8u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14ecbc: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14ecbcu;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14ecc0: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14ecc0u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14ecc4: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14ecc4u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14ecc8: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14ecc8u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14eccc: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14ecccu;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14ecd0: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14ecd0u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14ecd4: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14ecd4u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14ecd8: 0x7cc50030  sq          $a1, 0x30($a2)
    ctx->pc = 0x14ecd8u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 48), GPR_VEC(ctx, 5));
    // 0x14ecdc: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14ecdcu;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14ece0: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14ece0u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14ece4: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14ece4u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14ece8: 0x7da50030  sq          $a1, 0x30($t5)
    ctx->pc = 0x14ece8u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 48), GPR_VEC(ctx, 5));
    // 0x14ecec: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x14ececu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x14ecf0: 0x25ce0008  addiu       $t6, $t6, 0x8
    ctx->pc = 0x14ecf0u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 8));
    // 0x14ecf4: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x14ecf4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14ecf8: 0x1a36821  addu        $t5, $t5, $v1
    ctx->pc = 0x14ecf8u;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), GPR_U32(ctx, 3)));
    // 0x14ecfc: 0xcc8000c0  pref        0x00, 0xC0($a0)
    ctx->pc = 0x14ecfcu;
    // PREF instruction (ignored)
    // 0x14ed00: 0x908c0001  lbu         $t4, 0x1($a0)
    ctx->pc = 0x14ed00u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x14ed04: 0x908b0000  lbu         $t3, 0x0($a0)
    ctx->pc = 0x14ed04u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14ed08: 0x908a0011  lbu         $t2, 0x11($a0)
    ctx->pc = 0x14ed08u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 17)));
    // 0x14ed0c: 0x90890010  lbu         $t1, 0x10($a0)
    ctx->pc = 0x14ed0cu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x14ed10: 0x91c80000  lbu         $t0, 0x0($t6)
    ctx->pc = 0x14ed10u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x14ed14: 0x91c50040  lbu         $a1, 0x40($t6)
    ctx->pc = 0x14ed14u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 64)));
    // 0x14ed18: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14ed18u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14ed1c: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14ed1cu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14ed20: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14ed20u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14ed24: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14ed24u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14ed28: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14ed28u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14ed2c: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14ed2cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14ed30: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14ed30u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14ed34: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14ed34u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14ed38: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14ed38u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14ed3c: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14ed3cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14ed40: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14ed40u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14ed44: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14ed44u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14ed48: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14ed48u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14ed4c: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14ed4cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14ed50: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14ed50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14ed54: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14ed54u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14ed58: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14ed58u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14ed5c: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14ed5cu;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14ed60: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14ed60u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14ed64: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14ed64u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14ed68: 0x90890012  lbu         $t1, 0x12($a0)
    ctx->pc = 0x14ed68u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 18)));
    // 0x14ed6c: 0x91c80001  lbu         $t0, 0x1($t6)
    ctx->pc = 0x14ed6cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 1)));
    // 0x14ed70: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14ed70u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14ed74: 0x91c50041  lbu         $a1, 0x41($t6)
    ctx->pc = 0x14ed74u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 65)));
    // 0x14ed78: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14ed78u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14ed7c: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14ed7cu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14ed80: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14ed80u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14ed84: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14ed84u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14ed88: 0x908c0003  lbu         $t4, 0x3($a0)
    ctx->pc = 0x14ed88u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x14ed8c: 0x908b0002  lbu         $t3, 0x2($a0)
    ctx->pc = 0x14ed8cu;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x14ed90: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14ed90u;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14ed94: 0x908a0013  lbu         $t2, 0x13($a0)
    ctx->pc = 0x14ed94u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 19)));
    // 0x14ed98: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14ed98u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14ed9c: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14ed9cu;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14eda0: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14eda0u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14eda4: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14eda4u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14eda8: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14eda8u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14edac: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14edacu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14edb0: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14edb0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14edb4: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14edb4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14edb8: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14edb8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14edbc: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14edbcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14edc0: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14edc0u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14edc4: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14edc4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14edc8: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14edc8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14edcc: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14edccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14edd0: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14edd0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14edd4: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14edd4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14edd8: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14edd8u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14eddc: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14eddcu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14ede0: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14ede0u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14ede4: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14ede4u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14ede8: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14ede8u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14edec: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14edecu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14edf0: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14edf0u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14edf4: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14edf4u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14edf8: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14edf8u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14edfc: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14edfcu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14ee00: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14ee00u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14ee04: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14ee04u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14ee08: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14ee08u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14ee0c: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14ee0cu;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14ee10: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14ee10u;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14ee14: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14ee14u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14ee18: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14ee18u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14ee1c: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14ee1cu;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14ee20: 0x7cc50000  sq          $a1, 0x0($a2)
    ctx->pc = 0x14ee20u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 0), GPR_VEC(ctx, 5));
    // 0x14ee24: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14ee24u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14ee28: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14ee28u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14ee2c: 0x7da50000  sq          $a1, 0x0($t5)
    ctx->pc = 0x14ee2cu;
    WRITE128(ADD32(GPR_U32(ctx, 13), 0), GPR_VEC(ctx, 5));
    // 0x14ee30: 0x908c0005  lbu         $t4, 0x5($a0)
    ctx->pc = 0x14ee30u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 5)));
    // 0x14ee34: 0x908b0004  lbu         $t3, 0x4($a0)
    ctx->pc = 0x14ee34u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x14ee38: 0x908a0015  lbu         $t2, 0x15($a0)
    ctx->pc = 0x14ee38u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 21)));
    // 0x14ee3c: 0x90890014  lbu         $t1, 0x14($a0)
    ctx->pc = 0x14ee3cu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x14ee40: 0x91c80002  lbu         $t0, 0x2($t6)
    ctx->pc = 0x14ee40u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 2)));
    // 0x14ee44: 0x91c50042  lbu         $a1, 0x42($t6)
    ctx->pc = 0x14ee44u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 66)));
    // 0x14ee48: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14ee48u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14ee4c: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14ee4cu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14ee50: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14ee50u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14ee54: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14ee54u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14ee58: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14ee58u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14ee5c: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14ee5cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14ee60: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14ee60u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14ee64: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14ee64u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14ee68: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14ee68u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14ee6c: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14ee6cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14ee70: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14ee70u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14ee74: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14ee74u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14ee78: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14ee78u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14ee7c: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14ee7cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14ee80: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14ee80u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14ee84: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14ee84u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14ee88: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14ee88u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14ee8c: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14ee8cu;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14ee90: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14ee90u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14ee94: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14ee94u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14ee98: 0x90890016  lbu         $t1, 0x16($a0)
    ctx->pc = 0x14ee98u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 22)));
    // 0x14ee9c: 0x91c80003  lbu         $t0, 0x3($t6)
    ctx->pc = 0x14ee9cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 3)));
    // 0x14eea0: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14eea0u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14eea4: 0x91c50043  lbu         $a1, 0x43($t6)
    ctx->pc = 0x14eea4u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 67)));
    // 0x14eea8: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14eea8u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14eeac: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14eeacu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14eeb0: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14eeb0u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14eeb4: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14eeb4u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14eeb8: 0x908c0007  lbu         $t4, 0x7($a0)
    ctx->pc = 0x14eeb8u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 7)));
    // 0x14eebc: 0x908b0006  lbu         $t3, 0x6($a0)
    ctx->pc = 0x14eebcu;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 6)));
    // 0x14eec0: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14eec0u;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14eec4: 0x908a0017  lbu         $t2, 0x17($a0)
    ctx->pc = 0x14eec4u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 23)));
    // 0x14eec8: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14eec8u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14eecc: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14eeccu;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14eed0: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14eed0u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14eed4: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14eed4u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14eed8: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14eed8u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14eedc: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14eedcu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14eee0: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14eee0u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14eee4: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14eee4u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14eee8: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14eee8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14eeec: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14eeecu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14eef0: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14eef0u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14eef4: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14eef4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14eef8: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14eef8u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14eefc: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14eefcu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14ef00: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14ef00u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14ef04: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14ef04u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14ef08: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14ef08u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14ef0c: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14ef0cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14ef10: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14ef10u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14ef14: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14ef14u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14ef18: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14ef18u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14ef1c: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14ef1cu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14ef20: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14ef20u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14ef24: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14ef24u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14ef28: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14ef28u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14ef2c: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14ef2cu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14ef30: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14ef30u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14ef34: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14ef34u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14ef38: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14ef38u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14ef3c: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14ef3cu;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14ef40: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14ef40u;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14ef44: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14ef44u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14ef48: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14ef48u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14ef4c: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14ef4cu;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14ef50: 0x7cc50010  sq          $a1, 0x10($a2)
    ctx->pc = 0x14ef50u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 16), GPR_VEC(ctx, 5));
    // 0x14ef54: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14ef54u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14ef58: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14ef58u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14ef5c: 0x7da50010  sq          $a1, 0x10($t5)
    ctx->pc = 0x14ef5cu;
    WRITE128(ADD32(GPR_U32(ctx, 13), 16), GPR_VEC(ctx, 5));
    // 0x14ef60: 0x908c0009  lbu         $t4, 0x9($a0)
    ctx->pc = 0x14ef60u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 9)));
    // 0x14ef64: 0x908b0008  lbu         $t3, 0x8($a0)
    ctx->pc = 0x14ef64u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x14ef68: 0x908a0019  lbu         $t2, 0x19($a0)
    ctx->pc = 0x14ef68u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 25)));
    // 0x14ef6c: 0x90890018  lbu         $t1, 0x18($a0)
    ctx->pc = 0x14ef6cu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x14ef70: 0x91c80004  lbu         $t0, 0x4($t6)
    ctx->pc = 0x14ef70u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 4)));
    // 0x14ef74: 0x91c50044  lbu         $a1, 0x44($t6)
    ctx->pc = 0x14ef74u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 68)));
    // 0x14ef78: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14ef78u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14ef7c: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14ef7cu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14ef80: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14ef80u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14ef84: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14ef84u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14ef88: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14ef88u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14ef8c: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14ef8cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14ef90: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14ef90u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14ef94: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14ef94u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14ef98: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14ef98u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14ef9c: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14ef9cu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14efa0: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14efa0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14efa4: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14efa4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14efa8: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14efa8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14efac: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14efacu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14efb0: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14efb0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14efb4: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14efb4u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14efb8: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14efb8u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14efbc: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14efbcu;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14efc0: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14efc0u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14efc4: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14efc4u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14efc8: 0x9089001a  lbu         $t1, 0x1A($a0)
    ctx->pc = 0x14efc8u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 26)));
    // 0x14efcc: 0x91c80005  lbu         $t0, 0x5($t6)
    ctx->pc = 0x14efccu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 5)));
    // 0x14efd0: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14efd0u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14efd4: 0x91c50045  lbu         $a1, 0x45($t6)
    ctx->pc = 0x14efd4u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 69)));
    // 0x14efd8: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14efd8u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14efdc: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14efdcu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14efe0: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14efe0u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14efe4: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14efe4u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14efe8: 0x908c000b  lbu         $t4, 0xB($a0)
    ctx->pc = 0x14efe8u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 11)));
    // 0x14efec: 0x908b000a  lbu         $t3, 0xA($a0)
    ctx->pc = 0x14efecu;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 10)));
    // 0x14eff0: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14eff0u;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14eff4: 0x908a001b  lbu         $t2, 0x1B($a0)
    ctx->pc = 0x14eff4u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 27)));
    // 0x14eff8: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14eff8u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14effc: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14effcu;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14f000: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14f000u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14f004: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14f004u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14f008: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14f008u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14f00c: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14f00cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14f010: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14f010u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14f014: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14f014u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14f018: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14f018u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14f01c: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14f01cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14f020: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14f020u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14f024: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14f024u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14f028: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14f028u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14f02c: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14f02cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14f030: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14f030u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14f034: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14f034u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14f038: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14f038u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14f03c: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14f03cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14f040: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14f040u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14f044: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14f044u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14f048: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14f048u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14f04c: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14f04cu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14f050: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14f050u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14f054: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14f054u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14f058: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14f058u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14f05c: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14f05cu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14f060: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14f060u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14f064: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14f064u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14f068: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14f068u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14f06c: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14f06cu;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14f070: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14f070u;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14f074: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14f074u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14f078: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14f078u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14f07c: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14f07cu;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14f080: 0x7cc50020  sq          $a1, 0x20($a2)
    ctx->pc = 0x14f080u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 32), GPR_VEC(ctx, 5));
    // 0x14f084: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14f084u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14f088: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14f088u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14f08c: 0x7da50020  sq          $a1, 0x20($t5)
    ctx->pc = 0x14f08cu;
    WRITE128(ADD32(GPR_U32(ctx, 13), 32), GPR_VEC(ctx, 5));
    // 0x14f090: 0x908c000d  lbu         $t4, 0xD($a0)
    ctx->pc = 0x14f090u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 13)));
    // 0x14f094: 0x908b000c  lbu         $t3, 0xC($a0)
    ctx->pc = 0x14f094u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x14f098: 0x908a001d  lbu         $t2, 0x1D($a0)
    ctx->pc = 0x14f098u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 29)));
    // 0x14f09c: 0x9089001c  lbu         $t1, 0x1C($a0)
    ctx->pc = 0x14f09cu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x14f0a0: 0x91c80006  lbu         $t0, 0x6($t6)
    ctx->pc = 0x14f0a0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 6)));
    // 0x14f0a4: 0x91c50046  lbu         $a1, 0x46($t6)
    ctx->pc = 0x14f0a4u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 70)));
    // 0x14f0a8: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14f0a8u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14f0ac: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14f0acu;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14f0b0: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14f0b0u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14f0b4: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14f0b4u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14f0b8: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14f0b8u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14f0bc: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14f0bcu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14f0c0: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14f0c0u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14f0c4: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14f0c4u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14f0c8: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14f0c8u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14f0cc: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14f0ccu;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14f0d0: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14f0d0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14f0d4: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14f0d4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14f0d8: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14f0d8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14f0dc: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14f0dcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14f0e0: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14f0e0u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14f0e4: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14f0e4u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14f0e8: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14f0e8u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14f0ec: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14f0ecu;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14f0f0: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14f0f0u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14f0f4: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14f0f4u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14f0f8: 0x9089001e  lbu         $t1, 0x1E($a0)
    ctx->pc = 0x14f0f8u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 30)));
    // 0x14f0fc: 0x91c80007  lbu         $t0, 0x7($t6)
    ctx->pc = 0x14f0fcu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 7)));
    // 0x14f100: 0x91c50047  lbu         $a1, 0x47($t6)
    ctx->pc = 0x14f100u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 71)));
    // 0x14f104: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14f104u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14f108: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14f108u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14f10c: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14f10cu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14f110: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14f110u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14f114: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14f114u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14f118: 0x908c000f  lbu         $t4, 0xF($a0)
    ctx->pc = 0x14f118u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 15)));
    // 0x14f11c: 0x908b000e  lbu         $t3, 0xE($a0)
    ctx->pc = 0x14f11cu;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 14)));
    // 0x14f120: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14f120u;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14f124: 0x908a001f  lbu         $t2, 0x1F($a0)
    ctx->pc = 0x14f124u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 31)));
    // 0x14f128: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14f128u;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14f12c: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14f12cu;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14f130: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14f130u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14f134: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14f134u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14f138: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14f138u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14f13c: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14f13cu;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14f140: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14f140u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14f144: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14f144u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14f148: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14f148u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14f14c: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14f14cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14f150: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14f150u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14f154: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14f154u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14f158: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14f158u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14f15c: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14f15cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14f160: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14f160u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14f164: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14f164u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14f168: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14f168u;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14f16c: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14f16cu;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14f170: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14f170u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14f174: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14f174u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14f178: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14f178u;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14f17c: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14f17cu;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14f180: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14f180u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14f184: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14f184u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14f188: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14f188u;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14f18c: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14f18cu;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14f190: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14f190u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14f194: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14f194u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14f198: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14f198u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14f19c: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14f19cu;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14f1a0: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14f1a0u;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14f1a4: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14f1a4u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14f1a8: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14f1a8u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14f1ac: 0x7cc50030  sq          $a1, 0x30($a2)
    ctx->pc = 0x14f1acu;
    WRITE128(ADD32(GPR_U32(ctx, 6), 48), GPR_VEC(ctx, 5));
    // 0x14f1b0: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14f1b0u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14f1b4: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14f1b4u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14f1b8: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14f1b8u;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14f1bc: 0x7da50030  sq          $a1, 0x30($t5)
    ctx->pc = 0x14f1bcu;
    WRITE128(ADD32(GPR_U32(ctx, 13), 48), GPR_VEC(ctx, 5));
    // 0x14f1c0: 0x24840020  addiu       $a0, $a0, 0x20
    ctx->pc = 0x14f1c0u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 32));
    // 0x14f1c4: 0x25ce0008  addiu       $t6, $t6, 0x8
    ctx->pc = 0x14f1c4u;
    SET_GPR_S32(ctx, 14, (int32_t)ADD32(GPR_U32(ctx, 14), 8));
    // 0x14f1c8: 0xc33021  addu        $a2, $a2, $v1
    ctx->pc = 0x14f1c8u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14f1cc: 0x1a36821  addu        $t5, $t5, $v1
    ctx->pc = 0x14f1ccu;
    SET_GPR_S32(ctx, 13, (int32_t)ADD32(GPR_U32(ctx, 13), GPR_U32(ctx, 3)));
    // 0x14f1d0: 0xcc8000e0  pref        0x00, 0xE0($a0)
    ctx->pc = 0x14f1d0u;
    // PREF instruction (ignored)
    // 0x14f1d4: 0x908c0001  lbu         $t4, 0x1($a0)
    ctx->pc = 0x14f1d4u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
    // 0x14f1d8: 0x908b0000  lbu         $t3, 0x0($a0)
    ctx->pc = 0x14f1d8u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14f1dc: 0x908a0011  lbu         $t2, 0x11($a0)
    ctx->pc = 0x14f1dcu;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 17)));
    // 0x14f1e0: 0x90890010  lbu         $t1, 0x10($a0)
    ctx->pc = 0x14f1e0u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 16)));
    // 0x14f1e4: 0x91c80000  lbu         $t0, 0x0($t6)
    ctx->pc = 0x14f1e4u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x14f1e8: 0x91c50040  lbu         $a1, 0x40($t6)
    ctx->pc = 0x14f1e8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 64)));
    // 0x14f1ec: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14f1ecu;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14f1f0: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14f1f0u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14f1f4: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14f1f4u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14f1f8: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14f1f8u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14f1fc: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14f1fcu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14f200: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14f200u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14f204: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14f204u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14f208: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14f208u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14f20c: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14f20cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14f210: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14f210u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14f214: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14f214u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14f218: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14f218u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14f21c: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14f21cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14f220: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14f220u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14f224: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14f224u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14f228: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14f228u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14f22c: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14f22cu;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14f230: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14f230u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14f234: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14f234u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14f238: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14f238u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14f23c: 0x90890012  lbu         $t1, 0x12($a0)
    ctx->pc = 0x14f23cu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 18)));
    // 0x14f240: 0x91c80001  lbu         $t0, 0x1($t6)
    ctx->pc = 0x14f240u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 1)));
    // 0x14f244: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14f244u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14f248: 0x91c50041  lbu         $a1, 0x41($t6)
    ctx->pc = 0x14f248u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 65)));
    // 0x14f24c: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14f24cu;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14f250: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14f250u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14f254: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14f254u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14f258: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14f258u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14f25c: 0x908c0003  lbu         $t4, 0x3($a0)
    ctx->pc = 0x14f25cu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 3)));
    // 0x14f260: 0x908b0002  lbu         $t3, 0x2($a0)
    ctx->pc = 0x14f260u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
    // 0x14f264: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14f264u;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14f268: 0x908a0013  lbu         $t2, 0x13($a0)
    ctx->pc = 0x14f268u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 19)));
    // 0x14f26c: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14f26cu;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14f270: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14f270u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14f274: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14f274u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14f278: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14f278u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14f27c: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14f27cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14f280: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14f280u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14f284: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14f284u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14f288: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14f288u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14f28c: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14f28cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14f290: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14f290u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14f294: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14f294u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14f298: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14f298u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14f29c: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14f29cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14f2a0: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14f2a0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14f2a4: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14f2a4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14f2a8: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14f2a8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14f2ac: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14f2acu;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14f2b0: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14f2b0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14f2b4: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14f2b4u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14f2b8: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14f2b8u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14f2bc: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14f2bcu;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14f2c0: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14f2c0u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14f2c4: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14f2c4u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14f2c8: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14f2c8u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14f2cc: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14f2ccu;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14f2d0: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14f2d0u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14f2d4: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14f2d4u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14f2d8: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14f2d8u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14f2dc: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14f2dcu;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14f2e0: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14f2e0u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14f2e4: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14f2e4u;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14f2e8: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14f2e8u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14f2ec: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14f2ecu;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14f2f0: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14f2f0u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14f2f4: 0x7cc50000  sq          $a1, 0x0($a2)
    ctx->pc = 0x14f2f4u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 0), GPR_VEC(ctx, 5));
    // 0x14f2f8: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14f2f8u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14f2fc: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14f2fcu;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14f300: 0x7da50000  sq          $a1, 0x0($t5)
    ctx->pc = 0x14f300u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 0), GPR_VEC(ctx, 5));
    // 0x14f304: 0x908c0005  lbu         $t4, 0x5($a0)
    ctx->pc = 0x14f304u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 5)));
    // 0x14f308: 0x908b0004  lbu         $t3, 0x4($a0)
    ctx->pc = 0x14f308u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x14f30c: 0x908a0015  lbu         $t2, 0x15($a0)
    ctx->pc = 0x14f30cu;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 21)));
    // 0x14f310: 0x90890014  lbu         $t1, 0x14($a0)
    ctx->pc = 0x14f310u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 20)));
    // 0x14f314: 0x91c80002  lbu         $t0, 0x2($t6)
    ctx->pc = 0x14f314u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 2)));
    // 0x14f318: 0x91c50042  lbu         $a1, 0x42($t6)
    ctx->pc = 0x14f318u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 66)));
    // 0x14f31c: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14f31cu;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14f320: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14f320u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14f324: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14f324u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14f328: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14f328u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14f32c: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14f32cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14f330: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14f330u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14f334: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14f334u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14f338: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14f338u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14f33c: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14f33cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14f340: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14f340u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14f344: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14f344u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14f348: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14f348u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14f34c: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14f34cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14f350: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14f350u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14f354: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14f354u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14f358: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14f358u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14f35c: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14f35cu;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14f360: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14f360u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14f364: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14f364u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14f368: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14f368u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14f36c: 0x90890016  lbu         $t1, 0x16($a0)
    ctx->pc = 0x14f36cu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 22)));
    // 0x14f370: 0x91c80003  lbu         $t0, 0x3($t6)
    ctx->pc = 0x14f370u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 3)));
    // 0x14f374: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14f374u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14f378: 0x91c50043  lbu         $a1, 0x43($t6)
    ctx->pc = 0x14f378u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 67)));
    // 0x14f37c: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14f37cu;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14f380: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14f380u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14f384: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14f384u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14f388: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14f388u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14f38c: 0x908c0007  lbu         $t4, 0x7($a0)
    ctx->pc = 0x14f38cu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 7)));
    // 0x14f390: 0x908b0006  lbu         $t3, 0x6($a0)
    ctx->pc = 0x14f390u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 6)));
    // 0x14f394: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14f394u;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14f398: 0x908a0017  lbu         $t2, 0x17($a0)
    ctx->pc = 0x14f398u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 23)));
    // 0x14f39c: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14f39cu;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14f3a0: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14f3a0u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14f3a4: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14f3a4u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14f3a8: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14f3a8u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14f3ac: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14f3acu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14f3b0: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14f3b0u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14f3b4: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14f3b4u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14f3b8: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14f3b8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14f3bc: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14f3bcu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14f3c0: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14f3c0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14f3c4: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14f3c4u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14f3c8: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14f3c8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14f3cc: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14f3ccu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14f3d0: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14f3d0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14f3d4: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14f3d4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14f3d8: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14f3d8u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14f3dc: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14f3dcu;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14f3e0: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14f3e0u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14f3e4: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14f3e4u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14f3e8: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14f3e8u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14f3ec: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14f3ecu;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14f3f0: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14f3f0u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14f3f4: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14f3f4u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14f3f8: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14f3f8u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14f3fc: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14f3fcu;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14f400: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14f400u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14f404: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14f404u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14f408: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14f408u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14f40c: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14f40cu;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14f410: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14f410u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14f414: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14f414u;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14f418: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14f418u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14f41c: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14f41cu;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14f420: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14f420u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14f424: 0x7cc50010  sq          $a1, 0x10($a2)
    ctx->pc = 0x14f424u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 16), GPR_VEC(ctx, 5));
    // 0x14f428: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14f428u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14f42c: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14f42cu;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14f430: 0x7da50010  sq          $a1, 0x10($t5)
    ctx->pc = 0x14f430u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 16), GPR_VEC(ctx, 5));
    // 0x14f434: 0x908c0009  lbu         $t4, 0x9($a0)
    ctx->pc = 0x14f434u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 9)));
    // 0x14f438: 0x908b0008  lbu         $t3, 0x8($a0)
    ctx->pc = 0x14f438u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x14f43c: 0x908a0019  lbu         $t2, 0x19($a0)
    ctx->pc = 0x14f43cu;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 25)));
    // 0x14f440: 0x90890018  lbu         $t1, 0x18($a0)
    ctx->pc = 0x14f440u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 24)));
    // 0x14f444: 0x91c80004  lbu         $t0, 0x4($t6)
    ctx->pc = 0x14f444u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 4)));
    // 0x14f448: 0x91c50044  lbu         $a1, 0x44($t6)
    ctx->pc = 0x14f448u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 68)));
    // 0x14f44c: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14f44cu;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14f450: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14f450u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14f454: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14f454u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14f458: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14f458u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14f45c: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14f45cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14f460: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14f460u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14f464: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14f464u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14f468: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14f468u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14f46c: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14f46cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14f470: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14f470u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14f474: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14f474u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14f478: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14f478u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14f47c: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14f47cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14f480: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14f480u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14f484: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14f484u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14f488: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14f488u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14f48c: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14f48cu;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14f490: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14f490u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14f494: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14f494u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14f498: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14f498u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14f49c: 0x9089001a  lbu         $t1, 0x1A($a0)
    ctx->pc = 0x14f49cu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 26)));
    // 0x14f4a0: 0x91c80005  lbu         $t0, 0x5($t6)
    ctx->pc = 0x14f4a0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 5)));
    // 0x14f4a4: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14f4a4u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14f4a8: 0x91c50045  lbu         $a1, 0x45($t6)
    ctx->pc = 0x14f4a8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 69)));
    // 0x14f4ac: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14f4acu;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14f4b0: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14f4b0u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14f4b4: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14f4b4u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14f4b8: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14f4b8u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14f4bc: 0x908c000b  lbu         $t4, 0xB($a0)
    ctx->pc = 0x14f4bcu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 11)));
    // 0x14f4c0: 0x908b000a  lbu         $t3, 0xA($a0)
    ctx->pc = 0x14f4c0u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 10)));
    // 0x14f4c4: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14f4c4u;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14f4c8: 0x908a001b  lbu         $t2, 0x1B($a0)
    ctx->pc = 0x14f4c8u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 27)));
    // 0x14f4cc: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14f4ccu;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14f4d0: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14f4d0u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14f4d4: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14f4d4u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14f4d8: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14f4d8u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14f4dc: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14f4dcu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14f4e0: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14f4e0u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14f4e4: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14f4e4u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14f4e8: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14f4e8u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14f4ec: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14f4ecu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14f4f0: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14f4f0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14f4f4: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14f4f4u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14f4f8: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14f4f8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14f4fc: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14f4fcu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14f500: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14f500u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14f504: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14f504u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14f508: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14f508u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14f50c: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14f50cu;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14f510: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14f510u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14f514: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14f514u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14f518: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14f518u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14f51c: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14f51cu;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14f520: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14f520u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14f524: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14f524u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14f528: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14f528u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14f52c: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14f52cu;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14f530: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14f530u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14f534: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14f534u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14f538: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14f538u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14f53c: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14f53cu;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14f540: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14f540u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14f544: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14f544u;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14f548: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14f548u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14f54c: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14f54cu;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14f550: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14f550u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14f554: 0x7cc50020  sq          $a1, 0x20($a2)
    ctx->pc = 0x14f554u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 32), GPR_VEC(ctx, 5));
    // 0x14f558: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14f558u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14f55c: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14f55cu;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14f560: 0x7da50020  sq          $a1, 0x20($t5)
    ctx->pc = 0x14f560u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 32), GPR_VEC(ctx, 5));
    // 0x14f564: 0x908c000d  lbu         $t4, 0xD($a0)
    ctx->pc = 0x14f564u;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 13)));
    // 0x14f568: 0x908b000c  lbu         $t3, 0xC($a0)
    ctx->pc = 0x14f568u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x14f56c: 0x908a001d  lbu         $t2, 0x1D($a0)
    ctx->pc = 0x14f56cu;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 29)));
    // 0x14f570: 0x9089001c  lbu         $t1, 0x1C($a0)
    ctx->pc = 0x14f570u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 28)));
    // 0x14f574: 0x91c80006  lbu         $t0, 0x6($t6)
    ctx->pc = 0x14f574u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 6)));
    // 0x14f578: 0x91c50046  lbu         $a1, 0x46($t6)
    ctx->pc = 0x14f578u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 70)));
    // 0x14f57c: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14f57cu;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14f580: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14f580u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14f584: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14f584u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14f588: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14f588u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14f58c: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14f58cu;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14f590: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14f590u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14f594: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14f594u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14f598: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14f598u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14f59c: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14f59cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14f5a0: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14f5a0u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14f5a4: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14f5a4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14f5a8: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14f5a8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14f5ac: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14f5acu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14f5b0: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14f5b0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14f5b4: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14f5b4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14f5b8: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14f5b8u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14f5bc: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14f5bcu;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14f5c0: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14f5c0u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14f5c4: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14f5c4u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14f5c8: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14f5c8u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14f5cc: 0x9089001e  lbu         $t1, 0x1E($a0)
    ctx->pc = 0x14f5ccu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 30)));
    // 0x14f5d0: 0x91c80007  lbu         $t0, 0x7($t6)
    ctx->pc = 0x14f5d0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 7)));
    // 0x14f5d4: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14f5d4u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14f5d8: 0x91c50047  lbu         $a1, 0x47($t6)
    ctx->pc = 0x14f5d8u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 14), 71)));
    // 0x14f5dc: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14f5dcu;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14f5e0: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14f5e0u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14f5e4: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14f5e4u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14f5e8: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14f5e8u;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14f5ec: 0x908c000f  lbu         $t4, 0xF($a0)
    ctx->pc = 0x14f5ecu;
    SET_GPR_U32(ctx, 12, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 15)));
    // 0x14f5f0: 0x908b000e  lbu         $t3, 0xE($a0)
    ctx->pc = 0x14f5f0u;
    SET_GPR_U32(ctx, 11, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 14)));
    // 0x14f5f4: 0x7159c1e8  pminh       $t8, $t2, $t9
    ctx->pc = 0x14f5f4u;
    SET_GPR_VEC(ctx, 24, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14f5f8: 0x908a001f  lbu         $t2, 0x1F($a0)
    ctx->pc = 0x14f5f8u;
    SET_GPR_U32(ctx, 10, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 31)));
    // 0x14f5fc: 0xc60c0  sll         $t4, $t4, 3
    ctx->pc = 0x14f5fcu;
    SET_GPR_S32(ctx, 12, (int32_t)SLL32(GPR_U32(ctx, 12), 3));
    // 0x14f600: 0x72517d08  paddsh      $t7, $s2, $s1
    ctx->pc = 0x14f600u;
    SET_GPR_VEC(ctx, 15, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14f604: 0xb58c0  sll         $t3, $t3, 3
    ctx->pc = 0x14f604u;
    SET_GPR_S32(ctx, 11, (int32_t)SLL32(GPR_U32(ctx, 11), 3));
    // 0x14f608: 0xec6021  addu        $t4, $a3, $t4
    ctx->pc = 0x14f608u;
    SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 12)));
    // 0x14f60c: 0xeb5821  addu        $t3, $a3, $t3
    ctx->pc = 0x14f60cu;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 11)));
    // 0x14f610: 0x948c0  sll         $t1, $t1, 3
    ctx->pc = 0x14f610u;
    SET_GPR_S32(ctx, 9, (int32_t)SLL32(GPR_U32(ctx, 9), 3));
    // 0x14f614: 0x840c0  sll         $t0, $t0, 3
    ctx->pc = 0x14f614u;
    SET_GPR_S32(ctx, 8, (int32_t)SLL32(GPR_U32(ctx, 8), 3));
    // 0x14f618: 0x528c0  sll         $a1, $a1, 3
    ctx->pc = 0x14f618u;
    SET_GPR_S32(ctx, 5, (int32_t)SLL32(GPR_U32(ctx, 5), 3));
    // 0x14f61c: 0xe94821  addu        $t1, $a3, $t1
    ctx->pc = 0x14f61cu;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 9)));
    // 0x14f620: 0xdd930000  ld          $s3, 0x0($t4)
    ctx->pc = 0x14f620u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 12), 0)));
    // 0x14f624: 0xa50c0  sll         $t2, $t2, 3
    ctx->pc = 0x14f624u;
    SET_GPR_S32(ctx, 10, (int32_t)SLL32(GPR_U32(ctx, 10), 3));
    // 0x14f628: 0xe84021  addu        $t0, $a3, $t0
    ctx->pc = 0x14f628u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x14f62c: 0xea5021  addu        $t2, $a3, $t2
    ctx->pc = 0x14f62cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 10)));
    // 0x14f630: 0xdd720000  ld          $s2, 0x0($t3)
    ctx->pc = 0x14f630u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x14f634: 0xdd510000  ld          $s1, 0x0($t2)
    ctx->pc = 0x14f634u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x14f638: 0xe52821  addu        $a1, $a3, $a1
    ctx->pc = 0x14f638u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 5)));
    // 0x14f63c: 0x700f79b7  psrah       $t7, $t7, 6
    ctx->pc = 0x14f63cu;
    SET_GPR_VEC(ctx, 15, _mm_srai_epi16(GPR_VEC(ctx, 15), 6));
    // 0x14f640: 0xdd290000  ld          $t1, 0x0($t1)
    ctx->pc = 0x14f640u;
    SET_GPR_U64(ctx, 9, READ64(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x14f644: 0xdd0c0800  ld          $t4, 0x800($t0)
    ctx->pc = 0x14f644u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 8), 2048)));
    // 0x14f648: 0xdcab1000  ld          $t3, 0x1000($a1)
    ctx->pc = 0x14f648u;
    SET_GPR_U64(ctx, 11, READ64(ADD32(GPR_U32(ctx, 5), 4096)));
    // 0x14f64c: 0x71f079c8  pmaxh       $t7, $t7, $s0
    ctx->pc = 0x14f64cu;
    SET_GPR_VEC(ctx, 15, PS2_PMAXH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 16)));
    // 0x14f650: 0x72725389  pcpyld      $t2, $s3, $s2
    ctx->pc = 0x14f650u;
    SET_GPR_VEC(ctx, 10, PS2_PCPYLD(GPR_VEC(ctx, 19), GPR_VEC(ctx, 18)));
    // 0x14f654: 0x72299389  pcpyld      $s2, $s1, $t1
    ctx->pc = 0x14f654u;
    SET_GPR_VEC(ctx, 18, PS2_PCPYLD(GPR_VEC(ctx, 17), GPR_VEC(ctx, 9)));
    // 0x14f658: 0x718b6508  paddsh      $t4, $t4, $t3
    ctx->pc = 0x14f658u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 12), GPR_VEC(ctx, 11)));
    // 0x14f65c: 0x718c8b89  pcpyld      $s1, $t4, $t4
    ctx->pc = 0x14f65cu;
    SET_GPR_VEC(ctx, 17, PS2_PCPYLD(GPR_VEC(ctx, 12), GPR_VEC(ctx, 12)));
    // 0x14f660: 0x71516508  paddsh      $t4, $t2, $s1
    ctx->pc = 0x14f660u;
    SET_GPR_VEC(ctx, 12, _mm_adds_epi16(GPR_VEC(ctx, 10), GPR_VEC(ctx, 17)));
    // 0x14f664: 0x700c59b7  psrah       $t3, $t4, 6
    ctx->pc = 0x14f664u;
    SET_GPR_VEC(ctx, 11, _mm_srai_epi16(GPR_VEC(ctx, 12), 6));
    // 0x14f668: 0x72514508  paddsh      $t0, $s2, $s1
    ctx->pc = 0x14f668u;
    SET_GPR_VEC(ctx, 8, _mm_adds_epi16(GPR_VEC(ctx, 18), GPR_VEC(ctx, 17)));
    // 0x14f66c: 0x717051c8  pmaxh       $t2, $t3, $s0
    ctx->pc = 0x14f66cu;
    SET_GPR_VEC(ctx, 10, PS2_PMAXH(GPR_VEC(ctx, 11), GPR_VEC(ctx, 16)));
    // 0x14f670: 0x700841b7  psrah       $t0, $t0, 6
    ctx->pc = 0x14f670u;
    SET_GPR_VEC(ctx, 8, _mm_srai_epi16(GPR_VEC(ctx, 8), 6));
    // 0x14f674: 0x715929e8  pminh       $a1, $t2, $t9
    ctx->pc = 0x14f674u;
    SET_GPR_VEC(ctx, 5, PS2_PMINH(GPR_VEC(ctx, 10), GPR_VEC(ctx, 25)));
    // 0x14f678: 0x711041c8  pmaxh       $t0, $t0, $s0
    ctx->pc = 0x14f678u;
    SET_GPR_VEC(ctx, 8, PS2_PMAXH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 16)));
    // 0x14f67c: 0x70b82ec8  ppacb       $a1, $a1, $t8
    ctx->pc = 0x14f67cu;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 5), GPR_VEC(ctx, 24)));
    // 0x14f680: 0x71f979e8  pminh       $t7, $t7, $t9
    ctx->pc = 0x14f680u;
    SET_GPR_VEC(ctx, 15, PS2_PMINH(GPR_VEC(ctx, 15), GPR_VEC(ctx, 25)));
    // 0x14f684: 0x7cc50030  sq          $a1, 0x30($a2)
    ctx->pc = 0x14f684u;
    WRITE128(ADD32(GPR_U32(ctx, 6), 48), GPR_VEC(ctx, 5));
    // 0x14f688: 0x711941e8  pminh       $t0, $t0, $t9
    ctx->pc = 0x14f688u;
    SET_GPR_VEC(ctx, 8, PS2_PMINH(GPR_VEC(ctx, 8), GPR_VEC(ctx, 25)));
    // 0x14f68c: 0x710f2ec8  ppacb       $a1, $t0, $t7
    ctx->pc = 0x14f68cu;
    SET_GPR_VEC(ctx, 5, PS2_PPACB(GPR_VEC(ctx, 8), GPR_VEC(ctx, 15)));
    // 0x14f690: 0x7da50030  sq          $a1, 0x30($t5)
    ctx->pc = 0x14f690u;
    WRITE128(ADD32(GPR_U32(ctx, 13), 48), GPR_VEC(ctx, 5));
    // 0x14f694: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x14f694u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14f698: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x14f698u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x14f69c: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x14f69cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x14f6a0: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x14f6a0u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x14f6a4: 0xdfb40040  ld          $s4, 0x40($sp)
    ctx->pc = 0x14f6a4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x14f6a8: 0x3e00008  jr          $ra
    ctx->pc = 0x14F6A8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14F6ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x14F6A8u;
            // 0x14f6ac: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x14F6B0u;
    ctx->pc = GPR_U32(ctx, 31); return;
}
