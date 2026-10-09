#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00155800
// Address: 0x155800 - 0x155a88
void sub_00155800_0x155800(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00155800_0x155800");
#endif

    switch (ctx->pc) {
        case 0x1559e0u: goto label_1559e0;
        case 0x1559ecu: goto label_1559ec;
        case 0x155a10u: goto label_155a10;
        case 0x155a18u: goto label_155a18;
        case 0x155a28u: goto label_155a28;
        case 0x155a60u: goto label_155a60;
        default: break;
    }

    ctx->pc = 0x155800u;

    // 0x155800: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x155800u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x155804: 0x3c020015  lui         $v0, 0x15
    ctx->pc = 0x155804u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)21 << 16));
    // 0x155808: 0xffb60030  sd          $s6, 0x30($sp)
    ctx->pc = 0x155808u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x15580c: 0x3c160023  lui         $s6, 0x23
    ctx->pc = 0x15580cu;
    SET_GPR_S32(ctx, 22, (int32_t)((uint32_t)35 << 16));
    // 0x155810: 0x244259a0  addiu       $v0, $v0, 0x59A0
    ctx->pc = 0x155810u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22944));
    // 0x155814: 0xffb70038  sd          $s7, 0x38($sp)
    ctx->pc = 0x155814u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x155818: 0xaec2d80c  sw          $v0, -0x27F4($s6)
    ctx->pc = 0x155818u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 4294957068), GPR_U32(ctx, 2));
    // 0x15581c: 0x3c020015  lui         $v0, 0x15
    ctx->pc = 0x15581cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)21 << 16));
    // 0x155820: 0x3c170023  lui         $s7, 0x23
    ctx->pc = 0x155820u;
    SET_GPR_S32(ctx, 23, (int32_t)((uint32_t)35 << 16));
    // 0x155824: 0x244259b0  addiu       $v0, $v0, 0x59B0
    ctx->pc = 0x155824u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 22960));
    // 0x155828: 0xaee2d810  sw          $v0, -0x27F0($s7)
    ctx->pc = 0x155828u;
    WRITE32(ADD32(GPR_U32(ctx, 23), 4294957072), GPR_U32(ctx, 2));
    // 0x15582c: 0x3c020015  lui         $v0, 0x15
    ctx->pc = 0x15582cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)21 << 16));
    // 0x155830: 0x3c180023  lui         $t8, 0x23
    ctx->pc = 0x155830u;
    SET_GPR_S32(ctx, 24, (int32_t)((uint32_t)35 << 16));
    // 0x155834: 0x24425b88  addiu       $v0, $v0, 0x5B88
    ctx->pc = 0x155834u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 23432));
    // 0x155838: 0xaf02d814  sw          $v0, -0x27EC($t8)
    ctx->pc = 0x155838u;
    WRITE32(ADD32(GPR_U32(ctx, 24), 4294957076), GPR_U32(ctx, 2));
    // 0x15583c: 0x3c020015  lui         $v0, 0x15
    ctx->pc = 0x15583cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)21 << 16));
    // 0x155840: 0x3c190023  lui         $t9, 0x23
    ctx->pc = 0x155840u;
    SET_GPR_S32(ctx, 25, (int32_t)((uint32_t)35 << 16));
    // 0x155844: 0x24425b90  addiu       $v0, $v0, 0x5B90
    ctx->pc = 0x155844u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 23440));
    // 0x155848: 0xaf22d818  sw          $v0, -0x27E8($t9)
    ctx->pc = 0x155848u;
    WRITE32(ADD32(GPR_U32(ctx, 25), 4294957080), GPR_U32(ctx, 2));
    // 0x15584c: 0x3c020015  lui         $v0, 0x15
    ctx->pc = 0x15584cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)21 << 16));
    // 0x155850: 0xffbe0040  sd          $fp, 0x40($sp)
    ctx->pc = 0x155850u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 30));
    // 0x155854: 0x3c1e0023  lui         $fp, 0x23
    ctx->pc = 0x155854u;
    SET_GPR_S32(ctx, 30, (int32_t)((uint32_t)35 << 16));
    // 0x155858: 0x24425cd8  addiu       $v0, $v0, 0x5CD8
    ctx->pc = 0x155858u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 23768));
    // 0x15585c: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x15585cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x155860: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x155860u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x155864: 0x3c110023  lui         $s1, 0x23
    ctx->pc = 0x155864u;
    SET_GPR_S32(ctx, 17, (int32_t)((uint32_t)35 << 16));
    // 0x155868: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x155868u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x15586c: 0x3c120023  lui         $s2, 0x23
    ctx->pc = 0x15586cu;
    SET_GPR_S32(ctx, 18, (int32_t)((uint32_t)35 << 16));
    // 0x155870: 0xffb30018  sd          $s3, 0x18($sp)
    ctx->pc = 0x155870u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x155874: 0x3c130023  lui         $s3, 0x23
    ctx->pc = 0x155874u;
    SET_GPR_S32(ctx, 19, (int32_t)((uint32_t)35 << 16));
    // 0x155878: 0xffb40020  sd          $s4, 0x20($sp)
    ctx->pc = 0x155878u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x15587c: 0x3c140023  lui         $s4, 0x23
    ctx->pc = 0x15587cu;
    SET_GPR_S32(ctx, 20, (int32_t)((uint32_t)35 << 16));
    // 0x155880: 0xffb50028  sd          $s5, 0x28($sp)
    ctx->pc = 0x155880u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x155884: 0x24150001  addiu       $s5, $zero, 0x1
    ctx->pc = 0x155884u;
    SET_GPR_S32(ctx, 21, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x155888: 0xafc2d81c  sw          $v0, -0x27E4($fp)
    ctx->pc = 0x155888u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4294957084), GPR_U32(ctx, 2));
    // 0x15588c: 0x3c020015  lui         $v0, 0x15
    ctx->pc = 0x15588cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)21 << 16));
    // 0x155890: 0x24425d30  addiu       $v0, $v0, 0x5D30
    ctx->pc = 0x155890u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 23856));
    // 0x155894: 0x3c050015  lui         $a1, 0x15
    ctx->pc = 0x155894u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)21 << 16));
    // 0x155898: 0xae82d820  sw          $v0, -0x27E0($s4)
    ctx->pc = 0x155898u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 4294957088), GPR_U32(ctx, 2));
    // 0x15589c: 0x3c020015  lui         $v0, 0x15
    ctx->pc = 0x15589cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)21 << 16));
    // 0x1558a0: 0x24425d28  addiu       $v0, $v0, 0x5D28
    ctx->pc = 0x1558a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 23848));
    // 0x1558a4: 0x3c100023  lui         $s0, 0x23
    ctx->pc = 0x1558a4u;
    SET_GPR_S32(ctx, 16, (int32_t)((uint32_t)35 << 16));
    // 0x1558a8: 0xae62d824  sw          $v0, -0x27DC($s3)
    ctx->pc = 0x1558a8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 4294957092), GPR_U32(ctx, 2));
    // 0x1558ac: 0x3c020015  lui         $v0, 0x15
    ctx->pc = 0x1558acu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)21 << 16));
    // 0x1558b0: 0x24420580  addiu       $v0, $v0, 0x580
    ctx->pc = 0x1558b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1408));
    // 0x1558b4: 0x3c040015  lui         $a0, 0x15
    ctx->pc = 0x1558b4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)21 << 16));
    // 0x1558b8: 0xae42d828  sw          $v0, -0x27D8($s2)
    ctx->pc = 0x1558b8u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4294957096), GPR_U32(ctx, 2));
    // 0x1558bc: 0x3c020015  lui         $v0, 0x15
    ctx->pc = 0x1558bcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)21 << 16));
    // 0x1558c0: 0x244205f0  addiu       $v0, $v0, 0x5F0
    ctx->pc = 0x1558c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1520));
    // 0x1558c4: 0x3c0f0023  lui         $t7, 0x23
    ctx->pc = 0x1558c4u;
    SET_GPR_S32(ctx, 15, (int32_t)((uint32_t)35 << 16));
    // 0x1558c8: 0xae22d82c  sw          $v0, -0x27D4($s1)
    ctx->pc = 0x1558c8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4294957100), GPR_U32(ctx, 2));
    // 0x1558cc: 0x3c020015  lui         $v0, 0x15
    ctx->pc = 0x1558ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)21 << 16));
    // 0x1558d0: 0x244207b0  addiu       $v0, $v0, 0x7B0
    ctx->pc = 0x1558d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1968));
    // 0x1558d4: 0x3c030015  lui         $v1, 0x15
    ctx->pc = 0x1558d4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)21 << 16));
    // 0x1558d8: 0xae02d830  sw          $v0, -0x27D0($s0)
    ctx->pc = 0x1558d8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294957104), GPR_U32(ctx, 2));
    // 0x1558dc: 0xa0102d  daddu       $v0, $a1, $zero
    ctx->pc = 0x1558dcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1558e0: 0x244206f8  addiu       $v0, $v0, 0x6F8
    ctx->pc = 0x1558e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1784));
    // 0x1558e4: 0x3c0e0023  lui         $t6, 0x23
    ctx->pc = 0x1558e4u;
    SET_GPR_S32(ctx, 14, (int32_t)((uint32_t)35 << 16));
    // 0x1558e8: 0xade2d834  sw          $v0, -0x27CC($t7)
    ctx->pc = 0x1558e8u;
    WRITE32(ADD32(GPR_U32(ctx, 15), 4294957108), GPR_U32(ctx, 2));
    // 0x1558ec: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x1558ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1558f0: 0x24420ac8  addiu       $v0, $v0, 0xAC8
    ctx->pc = 0x1558f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2760));
    // 0x1558f4: 0x3c0d0023  lui         $t5, 0x23
    ctx->pc = 0x1558f4u;
    SET_GPR_S32(ctx, 13, (int32_t)((uint32_t)35 << 16));
    // 0x1558f8: 0xadc2d838  sw          $v0, -0x27C8($t6)
    ctx->pc = 0x1558f8u;
    WRITE32(ADD32(GPR_U32(ctx, 14), 4294957112), GPR_U32(ctx, 2));
    // 0x1558fc: 0x60102d  daddu       $v0, $v1, $zero
    ctx->pc = 0x1558fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155900: 0x24420af0  addiu       $v0, $v0, 0xAF0
    ctx->pc = 0x155900u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2800));
    // 0x155904: 0x3c0c0023  lui         $t4, 0x23
    ctx->pc = 0x155904u;
    SET_GPR_S32(ctx, 12, (int32_t)((uint32_t)35 << 16));
    // 0x155908: 0xada2d83c  sw          $v0, -0x27C4($t5)
    ctx->pc = 0x155908u;
    WRITE32(ADD32(GPR_U32(ctx, 13), 4294957116), GPR_U32(ctx, 2));
    // 0x15590c: 0x3c020015  lui         $v0, 0x15
    ctx->pc = 0x15590cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)21 << 16));
    // 0x155910: 0x24420b08  addiu       $v0, $v0, 0xB08
    ctx->pc = 0x155910u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2824));
    // 0x155914: 0x3c0b0023  lui         $t3, 0x23
    ctx->pc = 0x155914u;
    SET_GPR_S32(ctx, 11, (int32_t)((uint32_t)35 << 16));
    // 0x155918: 0xad82d840  sw          $v0, -0x27C0($t4)
    ctx->pc = 0x155918u;
    WRITE32(ADD32(GPR_U32(ctx, 12), 4294957120), GPR_U32(ctx, 2));
    // 0x15591c: 0x3c020015  lui         $v0, 0x15
    ctx->pc = 0x15591cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)21 << 16));
    // 0x155920: 0x24420b30  addiu       $v0, $v0, 0xB30
    ctx->pc = 0x155920u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2864));
    // 0x155924: 0x3c0a0023  lui         $t2, 0x23
    ctx->pc = 0x155924u;
    SET_GPR_S32(ctx, 10, (int32_t)((uint32_t)35 << 16));
    // 0x155928: 0xad62d844  sw          $v0, -0x27BC($t3)
    ctx->pc = 0x155928u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 4294957124), GPR_U32(ctx, 2));
    // 0x15592c: 0x3c020015  lui         $v0, 0x15
    ctx->pc = 0x15592cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)21 << 16));
    // 0x155930: 0x244207b8  addiu       $v0, $v0, 0x7B8
    ctx->pc = 0x155930u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1976));
    // 0x155934: 0x3c090023  lui         $t1, 0x23
    ctx->pc = 0x155934u;
    SET_GPR_S32(ctx, 9, (int32_t)((uint32_t)35 << 16));
    // 0x155938: 0xad42d848  sw          $v0, -0x27B8($t2)
    ctx->pc = 0x155938u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 4294957128), GPR_U32(ctx, 2));
    // 0x15593c: 0x3c020015  lui         $v0, 0x15
    ctx->pc = 0x15593cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)21 << 16));
    // 0x155940: 0x244208e0  addiu       $v0, $v0, 0x8E0
    ctx->pc = 0x155940u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2272));
    // 0x155944: 0x3c080023  lui         $t0, 0x23
    ctx->pc = 0x155944u;
    SET_GPR_S32(ctx, 8, (int32_t)((uint32_t)35 << 16));
    // 0x155948: 0xad22d84c  sw          $v0, -0x27B4($t1)
    ctx->pc = 0x155948u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 4294957132), GPR_U32(ctx, 2));
    // 0x15594c: 0x3c020015  lui         $v0, 0x15
    ctx->pc = 0x15594cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)21 << 16));
    // 0x155950: 0x3c060023  lui         $a2, 0x23
    ctx->pc = 0x155950u;
    SET_GPR_S32(ctx, 6, (int32_t)((uint32_t)35 << 16));
    // 0x155954: 0x24420940  addiu       $v0, $v0, 0x940
    ctx->pc = 0x155954u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2368));
    // 0x155958: 0xad02d850  sw          $v0, -0x27B0($t0)
    ctx->pc = 0x155958u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 4294957136), GPR_U32(ctx, 2));
    // 0x15595c: 0x3c020015  lui         $v0, 0x15
    ctx->pc = 0x15595cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)21 << 16));
    // 0x155960: 0xacd5d808  sw          $s5, -0x27F8($a2)
    ctx->pc = 0x155960u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4294957064), GPR_U32(ctx, 21));
    // 0x155964: 0x3c070023  lui         $a3, 0x23
    ctx->pc = 0x155964u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)35 << 16));
    // 0x155968: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x155968u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x15596c: 0x244209d0  addiu       $v0, $v0, 0x9D0
    ctx->pc = 0x15596cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 2512));
    // 0x155970: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x155970u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x155974: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x155974u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x155978: 0xdfb30018  ld          $s3, 0x18($sp)
    ctx->pc = 0x155978u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x15597c: 0xdfb40020  ld          $s4, 0x20($sp)
    ctx->pc = 0x15597cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x155980: 0xdfb50028  ld          $s5, 0x28($sp)
    ctx->pc = 0x155980u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x155984: 0xdfb60030  ld          $s6, 0x30($sp)
    ctx->pc = 0x155984u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x155988: 0xdfb70038  ld          $s7, 0x38($sp)
    ctx->pc = 0x155988u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x15598c: 0xdfbe0040  ld          $fp, 0x40($sp)
    ctx->pc = 0x15598cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x155990: 0xace2d854  sw          $v0, -0x27AC($a3)
    ctx->pc = 0x155990u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4294957140), GPR_U32(ctx, 2));
    // 0x155994: 0x3e00008  jr          $ra
    ctx->pc = 0x155994u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x155998u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155994u;
            // 0x155998: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1559E0u: goto label_1559e0;
            case 0x1559ECu: goto label_1559ec;
            case 0x1559F8u: goto label_1559f8;
            case 0x155A10u: goto label_155a10;
            case 0x155A18u: goto label_155a18;
            case 0x155A28u: goto label_155a28;
            case 0x155A40u: goto label_155a40;
            case 0x155A60u: goto label_155a60;
            case 0x155A7Cu: goto label_155a7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x15599Cu;
    // 0x15599c: 0x0  nop
    ctx->pc = 0x15599cu;
    // NOP
    // 0x1559a0: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x1559a0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x1559a4: 0x3e00008  jr          $ra
    ctx->pc = 0x1559A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1559A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1559A4u;
            // 0x1559a8: 0x2442e4a8  addiu       $v0, $v0, -0x1B58 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294960296));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1559E0u: goto label_1559e0;
            case 0x1559ECu: goto label_1559ec;
            case 0x1559F8u: goto label_1559f8;
            case 0x155A10u: goto label_155a10;
            case 0x155A18u: goto label_155a18;
            case 0x155A28u: goto label_155a28;
            case 0x155A40u: goto label_155a40;
            case 0x155A60u: goto label_155a60;
            case 0x155A7Cu: goto label_155a7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1559ACu;
    // 0x1559ac: 0x0  nop
    ctx->pc = 0x1559acu;
    // NOP
    // 0x1559b0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1559b0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1559b4: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1559b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1559b8: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1559b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1559bc: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1559bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1559c0: 0xa0882d  daddu       $s1, $a1, $zero
    ctx->pc = 0x1559c0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1559c4: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1559c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1559c8: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1559c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1559cc: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x1559ccu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x1559d0: 0x9043e544  lbu         $v1, -0x1ABC($v0)
    ctx->pc = 0x1559d0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 4294960452)));
    // 0x1559d4: 0x24040004  addiu       $a0, $zero, 0x4
    ctx->pc = 0x1559d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1559d8: 0x10640007  beq         $v1, $a0, . + 4 + (0x7 << 2)
    ctx->pc = 0x1559D8u;
    {
        const bool branch_taken_0x1559d8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1559DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1559D8u;
            // 0x1559dc: 0xc0902d  daddu       $s2, $a2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1559d8) {
            ctx->pc = 0x1559F8u;
            goto label_1559f8;
        }
    }
    ctx->pc = 0x1559E0u;
label_1559e0:
    // 0x1559e0: 0x2401ffff  addiu       $at, $zero, -0x1
    ctx->pc = 0x1559e0u;
    SET_GPR_S32(ctx, 1, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1559e4: 0x20f809  jalr        $at
    ctx->pc = 0x1559E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 1);
        SET_GPR_U32(ctx, 31, 0x1559ECu);
        if (jumpTarget == 0u) {
            ctx->pc = 0x1559ECu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1559E0u: goto label_1559e0;
            case 0x1559ECu: goto label_1559ec;
            case 0x1559F8u: goto label_1559f8;
            case 0x155A10u: goto label_155a10;
            case 0x155A18u: goto label_155a18;
            case 0x155A28u: goto label_155a28;
            case 0x155A40u: goto label_155a40;
            case 0x155A60u: goto label_155a60;
            case 0x155A7Cu: goto label_155a7c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1559ECu; }
            if (ctx->pc != 0x1559ECu) { return; }
        }
        }
    }
    ctx->pc = 0x1559ECu;
label_1559ec:
    // 0x1559ec: 0x1000fffc  b           . + 4 + (-0x4 << 2)
    ctx->pc = 0x1559ECu;
    {
        const bool branch_taken_0x1559ec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1559ec) {
            ctx->pc = 0x1559E0u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1559e0;
        }
    }
    ctx->pc = 0x1559F4u;
    // 0x1559f4: 0x0  nop
    ctx->pc = 0x1559f4u;
    // NOP
label_1559f8:
    // 0x1559f8: 0x3c030026  lui         $v1, 0x26
    ctx->pc = 0x1559f8u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)38 << 16));
    // 0x1559fc: 0x3c020024  lui         $v0, 0x24
    ctx->pc = 0x1559fcu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)36 << 16));
    // 0x155a00: 0x24634c08  addiu       $v1, $v1, 0x4C08
    ctx->pc = 0x155a00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 19464));
    // 0x155a04: 0x2442e4a8  addiu       $v0, $v0, -0x1B58
    ctx->pc = 0x155a04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294960296));
    // 0x155a08: 0xc054152  jal         func_150548
    ctx->pc = 0x155A08u;
    SET_GPR_U32(ctx, 31, 0x155A10u);
    ctx->pc = 0x155A0Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155A08u;
            // 0x155a0c: 0xac620000  sw          $v0, 0x0($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x150548u;
    if (runtime->hasFunction(0x150548u)) {
        auto targetFn = runtime->lookupFunction(0x150548u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155A10u; }
        if (ctx->pc != 0x155A10u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00150548_0x150548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155A10u; }
        if (ctx->pc != 0x155A10u) { return; }
    }
    ctx->pc = 0x155A10u;
label_155a10:
    // 0x155a10: 0xc054292  jal         func_150A48
    ctx->pc = 0x155A10u;
    SET_GPR_U32(ctx, 31, 0x155A18u);
    ctx->pc = 0x150A48u;
    if (runtime->hasFunction(0x150A48u)) {
        auto targetFn = runtime->lookupFunction(0x150A48u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155A18u; }
        if (ctx->pc != 0x155A18u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00150A48_0x150a48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155A18u; }
        if (ctx->pc != 0x155A18u) { return; }
    }
    ctx->pc = 0x155A18u;
label_155a18:
    // 0x155a18: 0x200202d  daddu       $a0, $s0, $zero
    ctx->pc = 0x155a18u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155a1c: 0x220282d  daddu       $a1, $s1, $zero
    ctx->pc = 0x155a1cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155a20: 0xc0556a2  jal         func_155A88
    ctx->pc = 0x155A20u;
    SET_GPR_U32(ctx, 31, 0x155A28u);
    ctx->pc = 0x155A24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155A20u;
            // 0x155a24: 0x240302d  daddu       $a2, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155A88u;
    if (runtime->hasFunction(0x155A88u)) {
        auto targetFn = runtime->lookupFunction(0x155A88u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155A28u; }
        if (ctx->pc != 0x155A28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00155A88_0x155a88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x155A28u; }
        if (ctx->pc != 0x155A28u) { return; }
    }
    ctx->pc = 0x155A28u;
label_155a28:
    // 0x155a28: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x155a28u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x155a2c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x155a2cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x155a30: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x155a30u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x155a34: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x155a34u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x155a38: 0x8055690  j           func_155A40
    ctx->pc = 0x155A38u;
    ctx->pc = 0x155A3Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x155A38u;
            // 0x155a3c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
    ctx->pc = 0x155A40u;
    goto label_155a40;
    ctx->pc = 0x155A40u;
label_155a40:
    // 0x155a40: 0x3c020026  lui         $v0, 0x26
    ctx->pc = 0x155a40u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)38 << 16));
    // 0x155a44: 0x24424c10  addiu       $v0, $v0, 0x4C10
    ctx->pc = 0x155a44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 19472));
    // 0x155a48: 0x8c440040  lw          $a0, 0x40($v0)
    ctx->pc = 0x155a48u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 64)));
    // 0x155a4c: 0x1880000b  blez        $a0, . + 4 + (0xB << 2)
    ctx->pc = 0x155A4Cu;
    {
        const bool branch_taken_0x155a4c = (GPR_S64(ctx, 4) <= 0);
        ctx->pc = 0x155A50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155A4Cu;
            // 0x155a50: 0x8c430044  lw          $v1, 0x44($v0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 68)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155a4c) {
            ctx->pc = 0x155A7Cu;
            goto label_155a7c;
        }
    }
    ctx->pc = 0x155A54u;
    // 0x155a54: 0x80102d  daddu       $v0, $a0, $zero
    ctx->pc = 0x155a54u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x155a58: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x155a58u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x155a5c: 0x0  nop
    ctx->pc = 0x155a5cu;
    // NOP
label_155a60:
    // 0x155a60: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x155a60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x155a64: 0xac640000  sw          $a0, 0x0($v1)
    ctx->pc = 0x155a64u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
    // 0x155a68: 0x0  nop
    ctx->pc = 0x155a68u;
    // NOP
    // 0x155a6c: 0x0  nop
    ctx->pc = 0x155a6cu;
    // NOP
    // 0x155a70: 0x0  nop
    ctx->pc = 0x155a70u;
    // NOP
    // 0x155a74: 0x1440fffa  bnez        $v0, . + 4 + (-0x6 << 2)
    ctx->pc = 0x155A74u;
    {
        const bool branch_taken_0x155a74 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x155A78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x155A74u;
            // 0x155a78: 0x246306a0  addiu       $v1, $v1, 0x6A0 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1696));
        ctx->in_delay_slot = false;
        if (branch_taken_0x155a74) {
            ctx->pc = 0x155A60u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_155a60;
        }
    }
    ctx->pc = 0x155A7Cu;
label_155a7c:
    // 0x155a7c: 0x3e00008  jr          $ra
    ctx->pc = 0x155A7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1559E0u: goto label_1559e0;
            case 0x1559ECu: goto label_1559ec;
            case 0x1559F8u: goto label_1559f8;
            case 0x155A10u: goto label_155a10;
            case 0x155A18u: goto label_155a18;
            case 0x155A28u: goto label_155a28;
            case 0x155A40u: goto label_155a40;
            case 0x155A60u: goto label_155a60;
            case 0x155A7Cu: goto label_155a7c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x155A84u;
    // 0x155a84: 0x0  nop
    ctx->pc = 0x155a84u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
