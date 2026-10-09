#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D540
// Address: 0x11d540 - 0x11d63c
void sub_0011D540_0x11d540(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D540_0x11d540");
#endif

    ctx->pc = 0x11d540u;

    // 0x11d540: 0x3c1a0026  lui         $k0, 0x26
    ctx->pc = 0x11d540u;
    SET_GPR_S32(ctx, 26, (int32_t)((uint32_t)38 << 16));
    // 0x11d544: 0x275af6c0  addiu       $k0, $k0, -0x940
    ctx->pc = 0x11d544u;
    SET_GPR_S32(ctx, 26, (int32_t)ADD32(GPR_U32(ctx, 26), 4294964928));
    // 0x11d548: 0x7f410010  sq          $at, 0x10($k0)
    ctx->pc = 0x11d548u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 16), GPR_VEC(ctx, 1));
    // 0x11d54c: 0x7f420020  sq          $v0, 0x20($k0)
    ctx->pc = 0x11d54cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 32), GPR_VEC(ctx, 2));
    // 0x11d550: 0x7f430030  sq          $v1, 0x30($k0)
    ctx->pc = 0x11d550u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 48), GPR_VEC(ctx, 3));
    // 0x11d554: 0x7f440040  sq          $a0, 0x40($k0)
    ctx->pc = 0x11d554u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 64), GPR_VEC(ctx, 4));
    // 0x11d558: 0x7f450050  sq          $a1, 0x50($k0)
    ctx->pc = 0x11d558u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 80), GPR_VEC(ctx, 5));
    // 0x11d55c: 0x7f460060  sq          $a2, 0x60($k0)
    ctx->pc = 0x11d55cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 96), GPR_VEC(ctx, 6));
    // 0x11d560: 0x7f470070  sq          $a3, 0x70($k0)
    ctx->pc = 0x11d560u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 112), GPR_VEC(ctx, 7));
    // 0x11d564: 0x7f480080  sq          $t0, 0x80($k0)
    ctx->pc = 0x11d564u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 128), GPR_VEC(ctx, 8));
    // 0x11d568: 0x7f490090  sq          $t1, 0x90($k0)
    ctx->pc = 0x11d568u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 144), GPR_VEC(ctx, 9));
    // 0x11d56c: 0x7f4a00a0  sq          $t2, 0xA0($k0)
    ctx->pc = 0x11d56cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 160), GPR_VEC(ctx, 10));
    // 0x11d570: 0x7f4b00b0  sq          $t3, 0xB0($k0)
    ctx->pc = 0x11d570u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 176), GPR_VEC(ctx, 11));
    // 0x11d574: 0x7f4c00c0  sq          $t4, 0xC0($k0)
    ctx->pc = 0x11d574u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 192), GPR_VEC(ctx, 12));
    // 0x11d578: 0x7f4d00d0  sq          $t5, 0xD0($k0)
    ctx->pc = 0x11d578u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 208), GPR_VEC(ctx, 13));
    // 0x11d57c: 0x7f4e00e0  sq          $t6, 0xE0($k0)
    ctx->pc = 0x11d57cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 224), GPR_VEC(ctx, 14));
    // 0x11d580: 0x7f4f00f0  sq          $t7, 0xF0($k0)
    ctx->pc = 0x11d580u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 240), GPR_VEC(ctx, 15));
    // 0x11d584: 0x7f500100  sq          $s0, 0x100($k0)
    ctx->pc = 0x11d584u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 256), GPR_VEC(ctx, 16));
    // 0x11d588: 0x7f510110  sq          $s1, 0x110($k0)
    ctx->pc = 0x11d588u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 272), GPR_VEC(ctx, 17));
    // 0x11d58c: 0x7f520120  sq          $s2, 0x120($k0)
    ctx->pc = 0x11d58cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 288), GPR_VEC(ctx, 18));
    // 0x11d590: 0x7f530130  sq          $s3, 0x130($k0)
    ctx->pc = 0x11d590u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 304), GPR_VEC(ctx, 19));
    // 0x11d594: 0x7f540140  sq          $s4, 0x140($k0)
    ctx->pc = 0x11d594u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 320), GPR_VEC(ctx, 20));
    // 0x11d598: 0x7f550150  sq          $s5, 0x150($k0)
    ctx->pc = 0x11d598u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 336), GPR_VEC(ctx, 21));
    // 0x11d59c: 0x7f560160  sq          $s6, 0x160($k0)
    ctx->pc = 0x11d59cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 352), GPR_VEC(ctx, 22));
    // 0x11d5a0: 0x7f570170  sq          $s7, 0x170($k0)
    ctx->pc = 0x11d5a0u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 368), GPR_VEC(ctx, 23));
    // 0x11d5a4: 0x7f580180  sq          $t8, 0x180($k0)
    ctx->pc = 0x11d5a4u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 384), GPR_VEC(ctx, 24));
    // 0x11d5a8: 0x7f590190  sq          $t9, 0x190($k0)
    ctx->pc = 0x11d5a8u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 400), GPR_VEC(ctx, 25));
    // 0x11d5ac: 0x7f5c01c0  sq          $gp, 0x1C0($k0)
    ctx->pc = 0x11d5acu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 448), GPR_VEC(ctx, 28));
    // 0x11d5b0: 0x7f5d01d0  sq          $sp, 0x1D0($k0)
    ctx->pc = 0x11d5b0u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 464), GPR_VEC(ctx, 29));
    // 0x11d5b4: 0x7f5e01e0  sq          $fp, 0x1E0($k0)
    ctx->pc = 0x11d5b4u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 480), GPR_VEC(ctx, 30));
    // 0x11d5b8: 0x7f5f01f0  sq          $ra, 0x1F0($k0)
    ctx->pc = 0x11d5b8u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 496), GPR_VEC(ctx, 31));
    // 0x11d5bc: 0x1010  mfhi        $v0
    ctx->pc = 0x11d5bcu;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x11d5c0: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d5c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d5c4: 0xfc22f8c0  sd          $v0, -0x740($at)
    ctx->pc = 0x11d5c4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965440), GPR_U64(ctx, 2));
    // 0x11d5c8: 0x70001010  mfhi1       $v0
    ctx->pc = 0x11d5c8u;
    SET_GPR_U64(ctx, 2, ctx->hi1);
    // 0x11d5cc: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d5ccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d5d0: 0xfc22f8c8  sd          $v0, -0x738($at)
    ctx->pc = 0x11d5d0u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965448), GPR_U64(ctx, 2));
    // 0x11d5d4: 0x1012  mflo        $v0
    ctx->pc = 0x11d5d4u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x11d5d8: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d5d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d5dc: 0xfc22f8d0  sd          $v0, -0x730($at)
    ctx->pc = 0x11d5dcu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965456), GPR_U64(ctx, 2));
    // 0x11d5e0: 0x70001012  mflo1       $v0
    ctx->pc = 0x11d5e0u;
    SET_GPR_U64(ctx, 2, ctx->lo1);
    // 0x11d5e4: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d5e4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d5e8: 0xfc22f8d8  sd          $v0, -0x728($at)
    ctx->pc = 0x11d5e8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965464), GPR_U64(ctx, 2));
    // 0x11d5ec: 0x1028  mfsa        $v0
    ctx->pc = 0x11d5ecu;
    SET_GPR_U32(ctx, 2, ctx->sa);
    // 0x11d5f0: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d5f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d5f4: 0xfc22f8e0  sd          $v0, -0x720($at)
    ctx->pc = 0x11d5f4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965472), GPR_U64(ctx, 2));
    // 0x11d5f8: 0x40046000  mfc0        $a0, Status
    ctx->pc = 0x11d5f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ctx->cop0_status);
    // 0x11d5fc: 0x40056800  mfc0        $a1, Cause
    ctx->pc = 0x11d5fcu;
    SET_GPR_S32(ctx, 5, (int32_t)ctx->cop0_cause);
    // 0x11d600: 0x40067000  mfc0        $a2, EPC
    ctx->pc = 0x11d600u;
    SET_GPR_S32(ctx, 6, (int32_t)ctx->cop0_epc);
    // 0x11d604: 0x40074000  mfc0        $a3, BadVaddr
    ctx->pc = 0x11d604u;
    SET_GPR_S32(ctx, 7, (int32_t)ctx->cop0_badvaddr);
    // 0x11d608: 0x4008b800  mfc0        $t0, Reserved23
    ctx->pc = 0x11d608u;
    SET_GPR_S32(ctx, 8, (int32_t)ctx->cop0_badpaddr);
    // 0x11d60c: 0x3c090026  lui         $t1, 0x26
    ctx->pc = 0x11d60cu;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)38 << 16));
    // 0x11d610: 0x2529f6c0  addiu       $t1, $t1, -0x940
    ctx->pc = 0x11d610u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 9), 4294964928));
    // 0x11d614: 0x3c010012  lui         $at, 0x12
    ctx->pc = 0x11d614u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)18 << 16));
    // 0x11d618: 0x2421d63c  addiu       $at, $at, -0x29C4
    ctx->pc = 0x11d618u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), 4294956604));
    // 0x11d61c: 0x40817000  mtc0        $at, EPC
    ctx->pc = 0x11d61cu;
    ctx->cop0_epc = GPR_U32(ctx, 1);
    // 0x11d620: 0x40f  sync.p
    ctx->pc = 0x11d620u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11d624: 0x40016000  mfc0        $at, Status
    ctx->pc = 0x11d624u;
    SET_GPR_S32(ctx, 1, (int32_t)ctx->cop0_status);
    // 0x11d628: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x11d628u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x11d62c: 0x220824  and         $at, $at, $v0
    ctx->pc = 0x11d62cu;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) & GPR_U64(ctx, 2));
    // 0x11d630: 0x40816000  mtc0        $at, Status
    ctx->pc = 0x11d630u;
    ctx->cop0_status = GPR_U32(ctx, 1) & 0xFF57FFFF;
    // 0x11d634: 0x40f  sync.p
    ctx->pc = 0x11d634u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11d638: 0x42000018  eret
    ctx->pc = 0x11d638u;
    if (ctx->cop0_status & 0x4) { 
    ctx->pc = ctx->cop0_errorepc; 
    ctx->cop0_status &= ~0x4; 
} else { 
    ctx->pc = ctx->cop0_epc; 
    ctx->cop0_status &= ~0x2; 
} 
runtime->clearLLBit(ctx); 
return;
    ctx->pc = GPR_U32(ctx, 31); return;
}
