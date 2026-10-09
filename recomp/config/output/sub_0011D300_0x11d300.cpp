#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_0011D300
// Address: 0x11d300 - 0x11d400
void sub_0011D300_0x11d300(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_0011D300_0x11d300");
#endif

    ctx->pc = 0x11d300u;

    // 0x11d300: 0x3c1a0026  lui         $k0, 0x26
    ctx->pc = 0x11d300u;
    SET_GPR_S32(ctx, 26, (int32_t)((uint32_t)38 << 16));
    // 0x11d304: 0x275af6c0  addiu       $k0, $k0, -0x940
    ctx->pc = 0x11d304u;
    SET_GPR_S32(ctx, 26, (int32_t)ADD32(GPR_U32(ctx, 26), 4294964928));
    // 0x11d308: 0x7f410010  sq          $at, 0x10($k0)
    ctx->pc = 0x11d308u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 16), GPR_VEC(ctx, 1));
    // 0x11d30c: 0x7f420020  sq          $v0, 0x20($k0)
    ctx->pc = 0x11d30cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 32), GPR_VEC(ctx, 2));
    // 0x11d310: 0x7f430030  sq          $v1, 0x30($k0)
    ctx->pc = 0x11d310u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 48), GPR_VEC(ctx, 3));
    // 0x11d314: 0x7f440040  sq          $a0, 0x40($k0)
    ctx->pc = 0x11d314u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 64), GPR_VEC(ctx, 4));
    // 0x11d318: 0x7f450050  sq          $a1, 0x50($k0)
    ctx->pc = 0x11d318u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 80), GPR_VEC(ctx, 5));
    // 0x11d31c: 0x7f460060  sq          $a2, 0x60($k0)
    ctx->pc = 0x11d31cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 96), GPR_VEC(ctx, 6));
    // 0x11d320: 0x7f470070  sq          $a3, 0x70($k0)
    ctx->pc = 0x11d320u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 112), GPR_VEC(ctx, 7));
    // 0x11d324: 0x7f480080  sq          $t0, 0x80($k0)
    ctx->pc = 0x11d324u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 128), GPR_VEC(ctx, 8));
    // 0x11d328: 0x7f490090  sq          $t1, 0x90($k0)
    ctx->pc = 0x11d328u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 144), GPR_VEC(ctx, 9));
    // 0x11d32c: 0x7f4a00a0  sq          $t2, 0xA0($k0)
    ctx->pc = 0x11d32cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 160), GPR_VEC(ctx, 10));
    // 0x11d330: 0x7f4b00b0  sq          $t3, 0xB0($k0)
    ctx->pc = 0x11d330u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 176), GPR_VEC(ctx, 11));
    // 0x11d334: 0x7f4c00c0  sq          $t4, 0xC0($k0)
    ctx->pc = 0x11d334u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 192), GPR_VEC(ctx, 12));
    // 0x11d338: 0x7f4d00d0  sq          $t5, 0xD0($k0)
    ctx->pc = 0x11d338u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 208), GPR_VEC(ctx, 13));
    // 0x11d33c: 0x7f4e00e0  sq          $t6, 0xE0($k0)
    ctx->pc = 0x11d33cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 224), GPR_VEC(ctx, 14));
    // 0x11d340: 0x7f4f00f0  sq          $t7, 0xF0($k0)
    ctx->pc = 0x11d340u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 240), GPR_VEC(ctx, 15));
    // 0x11d344: 0x7f500100  sq          $s0, 0x100($k0)
    ctx->pc = 0x11d344u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 256), GPR_VEC(ctx, 16));
    // 0x11d348: 0x7f510110  sq          $s1, 0x110($k0)
    ctx->pc = 0x11d348u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 272), GPR_VEC(ctx, 17));
    // 0x11d34c: 0x7f520120  sq          $s2, 0x120($k0)
    ctx->pc = 0x11d34cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 288), GPR_VEC(ctx, 18));
    // 0x11d350: 0x7f530130  sq          $s3, 0x130($k0)
    ctx->pc = 0x11d350u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 304), GPR_VEC(ctx, 19));
    // 0x11d354: 0x7f540140  sq          $s4, 0x140($k0)
    ctx->pc = 0x11d354u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 320), GPR_VEC(ctx, 20));
    // 0x11d358: 0x7f550150  sq          $s5, 0x150($k0)
    ctx->pc = 0x11d358u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 336), GPR_VEC(ctx, 21));
    // 0x11d35c: 0x7f560160  sq          $s6, 0x160($k0)
    ctx->pc = 0x11d35cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 352), GPR_VEC(ctx, 22));
    // 0x11d360: 0x7f570170  sq          $s7, 0x170($k0)
    ctx->pc = 0x11d360u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 368), GPR_VEC(ctx, 23));
    // 0x11d364: 0x7f580180  sq          $t8, 0x180($k0)
    ctx->pc = 0x11d364u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 384), GPR_VEC(ctx, 24));
    // 0x11d368: 0x7f590190  sq          $t9, 0x190($k0)
    ctx->pc = 0x11d368u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 400), GPR_VEC(ctx, 25));
    // 0x11d36c: 0x7f5c01c0  sq          $gp, 0x1C0($k0)
    ctx->pc = 0x11d36cu;
    WRITE128(ADD32(GPR_U32(ctx, 26), 448), GPR_VEC(ctx, 28));
    // 0x11d370: 0x7f5d01d0  sq          $sp, 0x1D0($k0)
    ctx->pc = 0x11d370u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 464), GPR_VEC(ctx, 29));
    // 0x11d374: 0x7f5e01e0  sq          $fp, 0x1E0($k0)
    ctx->pc = 0x11d374u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 480), GPR_VEC(ctx, 30));
    // 0x11d378: 0x7f5f01f0  sq          $ra, 0x1F0($k0)
    ctx->pc = 0x11d378u;
    WRITE128(ADD32(GPR_U32(ctx, 26), 496), GPR_VEC(ctx, 31));
    // 0x11d37c: 0x1010  mfhi        $v0
    ctx->pc = 0x11d37cu;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x11d380: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d380u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d384: 0xfc22f8c0  sd          $v0, -0x740($at)
    ctx->pc = 0x11d384u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965440), GPR_U64(ctx, 2));
    // 0x11d388: 0x70001010  mfhi1       $v0
    ctx->pc = 0x11d388u;
    SET_GPR_U64(ctx, 2, ctx->hi1);
    // 0x11d38c: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d38cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d390: 0xfc22f8c8  sd          $v0, -0x738($at)
    ctx->pc = 0x11d390u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965448), GPR_U64(ctx, 2));
    // 0x11d394: 0x1012  mflo        $v0
    ctx->pc = 0x11d394u;
    SET_GPR_U64(ctx, 2, ctx->lo);
    // 0x11d398: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d398u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d39c: 0xfc22f8d0  sd          $v0, -0x730($at)
    ctx->pc = 0x11d39cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965456), GPR_U64(ctx, 2));
    // 0x11d3a0: 0x70001012  mflo1       $v0
    ctx->pc = 0x11d3a0u;
    SET_GPR_U64(ctx, 2, ctx->lo1);
    // 0x11d3a4: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d3a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d3a8: 0xfc22f8d8  sd          $v0, -0x728($at)
    ctx->pc = 0x11d3a8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965464), GPR_U64(ctx, 2));
    // 0x11d3ac: 0x1028  mfsa        $v0
    ctx->pc = 0x11d3acu;
    SET_GPR_U32(ctx, 2, ctx->sa);
    // 0x11d3b0: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d3b0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d3b4: 0xfc22f8e0  sd          $v0, -0x720($at)
    ctx->pc = 0x11d3b4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294965472), GPR_U64(ctx, 2));
    // 0x11d3b8: 0x40046000  mfc0        $a0, Status
    ctx->pc = 0x11d3b8u;
    SET_GPR_S32(ctx, 4, (int32_t)ctx->cop0_status);
    // 0x11d3bc: 0x40056800  mfc0        $a1, Cause
    ctx->pc = 0x11d3bcu;
    SET_GPR_S32(ctx, 5, (int32_t)ctx->cop0_cause);
    // 0x11d3c0: 0x40067000  mfc0        $a2, EPC
    ctx->pc = 0x11d3c0u;
    SET_GPR_S32(ctx, 6, (int32_t)ctx->cop0_epc);
    // 0x11d3c4: 0x40074000  mfc0        $a3, BadVaddr
    ctx->pc = 0x11d3c4u;
    SET_GPR_S32(ctx, 7, (int32_t)ctx->cop0_badvaddr);
    // 0x11d3c8: 0x3c080026  lui         $t0, 0x26
    ctx->pc = 0x11d3c8u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)38 << 16));
    // 0x11d3cc: 0x2508f6c0  addiu       $t0, $t0, -0x940
    ctx->pc = 0x11d3ccu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 4294964928));
    // 0x11d3d0: 0x3c010026  lui         $at, 0x26
    ctx->pc = 0x11d3d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)38 << 16));
    // 0x11d3d4: 0xac26f8e8  sw          $a2, -0x718($at)
    ctx->pc = 0x11d3d4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965480), GPR_U32(ctx, 6));
    // 0x11d3d8: 0x3c010012  lui         $at, 0x12
    ctx->pc = 0x11d3d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)18 << 16));
    // 0x11d3dc: 0x2421d400  addiu       $at, $at, -0x2C00
    ctx->pc = 0x11d3dcu;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 1), 4294956032));
    // 0x11d3e0: 0x40817000  mtc0        $at, EPC
    ctx->pc = 0x11d3e0u;
    ctx->cop0_epc = GPR_U32(ctx, 1);
    // 0x11d3e4: 0x40f  sync.p
    ctx->pc = 0x11d3e4u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11d3e8: 0x40016000  mfc0        $at, Status
    ctx->pc = 0x11d3e8u;
    SET_GPR_S32(ctx, 1, (int32_t)ctx->cop0_status);
    // 0x11d3ec: 0x2402fffe  addiu       $v0, $zero, -0x2
    ctx->pc = 0x11d3ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x11d3f0: 0x220824  and         $at, $at, $v0
    ctx->pc = 0x11d3f0u;
    SET_GPR_U64(ctx, 1, GPR_U64(ctx, 1) & GPR_U64(ctx, 2));
    // 0x11d3f4: 0x40816000  mtc0        $at, Status
    ctx->pc = 0x11d3f4u;
    ctx->cop0_status = GPR_U32(ctx, 1) & 0xFF57FFFF;
    // 0x11d3f8: 0x40f  sync.p
    ctx->pc = 0x11d3f8u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11d3fc: 0x42000018  eret
    ctx->pc = 0x11d3fcu;
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
