#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00145548
// Address: 0x145548 - 0x1457b8
void sub_00145548_0x145548(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x145548u;

    // 0x145548: 0x27bdff40
    ctx->pc = 0x145548u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x14554c: 0x3c021000
    ctx->pc = 0x14554cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x145550: 0xffb00020
    ctx->pc = 0x145550u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x145554: 0x34422010
    ctx->pc = 0x145554u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8208));
    // 0x145558: 0xffbf00b0
    ctx->pc = 0x145558u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 31));
    // 0x14555c: 0x3c038000
    ctx->pc = 0x14555cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)32768 << 16));
    // 0x145560: 0xffbe00a0
    ctx->pc = 0x145560u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 30));
    // 0x145564: 0x34634000
    ctx->pc = 0x145564u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 16384));
    // 0x145568: 0xffb70090
    ctx->pc = 0x145568u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 23));
    // 0x14556c: 0x80802d
    ctx->pc = 0x14556cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145570: 0xffb60080
    ctx->pc = 0x145570u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 22));
    // 0x145574: 0x402d
    ctx->pc = 0x145574u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145578: 0xffb50070
    ctx->pc = 0x145578u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 21));
    // 0x14557c: 0x382d
    ctx->pc = 0x14557cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145580: 0xffb40060
    ctx->pc = 0x145580u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 20));
    // 0x145584: 0xffb30050
    ctx->pc = 0x145584u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 19));
    // 0x145588: 0xffb20040
    ctx->pc = 0x145588u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x14558c: 0xffb10030
    ctx->pc = 0x14558cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x145590: 0x8c460000
    ctx->pc = 0x145590u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x145594: 0x3c028000
    ctx->pc = 0x145594u;
    SET_GPR_U32(ctx, 2, ((uint32_t)32768 << 16));
    // 0x145598: 0xc33024
    ctx->pc = 0x145598u;
    SET_GPR_U32(ctx, 6, AND32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x14559c: 0x14c2001c
    ctx->pc = 0x14559Cu;
    {
        const bool branch_taken_0x14559c = (GPR_U32(ctx, 6) != GPR_U32(ctx, 2));
        ctx->pc = 0x1455A0u;
        SET_GPR_U32(ctx, 17, SLL32(GPR_U32(ctx, 5), 26));
        if (branch_taken_0x14559c) {
            ctx->pc = 0x145610u;
            goto label_145610;
        }
    }
    ctx->pc = 0x1455A4u;
    // 0x1455a4: 0x8e0210a0
    ctx->pc = 0x1455a4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 4256)));
    // 0x1455a8: 0x1440001a
    ctx->pc = 0x1455A8u;
    {
        const bool branch_taken_0x1455a8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1455ACu;
        SET_GPR_U32(ctx, 18, ((uint32_t)35 << 16));
        if (branch_taken_0x1455a8) {
            ctx->pc = 0x145614u;
            goto label_145614;
        }
    }
    ctx->pc = 0x1455B0u;
    // 0x1455b0: 0x58e80
    ctx->pc = 0x1455b0u;
    SET_GPR_U32(ctx, 17, SLL32(GPR_U32(ctx, 5), 26));
    // 0x1455b4: 0xe0102d
    ctx->pc = 0x1455b4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
label_1455b8:
    // 0x1455b8: 0x28421389
    ctx->pc = 0x1455b8u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 2), 5001));
    // 0x1455bc: 0x14400006
    ctx->pc = 0x1455BCu;
    {
        const bool branch_taken_0x1455bc = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1455C0u;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 1));
        if (branch_taken_0x1455bc) {
            ctx->pc = 0x1455D8u;
            goto label_1455d8;
        }
    }
    ctx->pc = 0x1455C4u;
    // 0x1455c4: 0x8e040870
    ctx->pc = 0x1455c4u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 2160)));
    // 0x1455c8: 0xc051ff8
    ctx->pc = 0x1455C8u;
    SET_GPR_U32(ctx, 31, 0x1455D0u);
    ctx->pc = 0x1455CCu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 8));
    ctx->pc = 0x147FE0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00147FE0_0x147fe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1455D0u; }
    }
    if (ctx->pc != 0x1455D0u) { return; }
    ctx->pc = 0x1455D0u;
    // 0x1455d0: 0x7ba80010
    ctx->pc = 0x1455d0u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1455d4: 0x382d
    ctx->pc = 0x1455d4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1455d8:
    // 0x1455d8: 0x3c031000
    ctx->pc = 0x1455d8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1455dc: 0x3c048000
    ctx->pc = 0x1455dcu;
    SET_GPR_U32(ctx, 4, ((uint32_t)32768 << 16));
    // 0x1455e0: 0x34632010
    ctx->pc = 0x1455e0u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 8208));
    // 0x1455e4: 0x34844000
    ctx->pc = 0x1455e4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 16384));
    // 0x1455e8: 0x8c620000
    ctx->pc = 0x1455e8u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x1455ec: 0x3c058000
    ctx->pc = 0x1455ecu;
    SET_GPR_U32(ctx, 5, ((uint32_t)32768 << 16));
    // 0x1455f0: 0x441024
    ctx->pc = 0x1455f0u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1455f4: 0x14450008
    ctx->pc = 0x1455F4u;
    {
        const bool branch_taken_0x1455f4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 5));
        ctx->pc = 0x1455F8u;
        SET_GPR_U32(ctx, 3, ((uint32_t)12288 << 16));
        if (branch_taken_0x1455f4) {
            ctx->pc = 0x145618u;
            goto label_145618;
        }
    }
    ctx->pc = 0x1455FCu;
    // 0x1455fc: 0x8e0210a0
    ctx->pc = 0x1455fcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 4256)));
    // 0x145600: 0x1040ffed
    ctx->pc = 0x145600u;
    {
        const bool branch_taken_0x145600 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x145604u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x145600) {
            ctx->pc = 0x1455B8u;
            goto label_1455b8;
        }
    }
    ctx->pc = 0x145608u;
    // 0x145608: 0x10000004
    ctx->pc = 0x145608u;
    {
        const bool branch_taken_0x145608 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x14560Cu;
        SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
        if (branch_taken_0x145608) {
            ctx->pc = 0x14561Cu;
            goto label_14561c;
        }
    }
    ctx->pc = 0x145610u;
label_145610:
    // 0x145610: 0x3c120023
    ctx->pc = 0x145610u;
    SET_GPR_U32(ctx, 18, ((uint32_t)35 << 16));
label_145614:
    // 0x145614: 0x3c033000
    ctx->pc = 0x145614u;
    SET_GPR_U32(ctx, 3, ((uint32_t)12288 << 16));
label_145618:
    // 0x145618: 0x3c041000
    ctx->pc = 0x145618u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
label_14561c:
    // 0x14561c: 0x2231825
    ctx->pc = 0x14561cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x145620: 0x34842000
    ctx->pc = 0x145620u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 8192));
    // 0x145624: 0x31703
    ctx->pc = 0x145624u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 28));
    // 0x145628: 0xac830000
    ctx->pc = 0x145628u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x14562c: 0x2645a6f8
    ctx->pc = 0x14562cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 18), 4294944504));
    // 0x145630: 0x21080
    ctx->pc = 0x145630u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 2));
    // 0x145634: 0x451021
    ctx->pc = 0x145634u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x145638: 0xdc860000
    ctx->pc = 0x145638u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x14563c: 0x8c430000
    ctx->pc = 0x14563cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x145640: 0x4c1003a
    ctx->pc = 0x145640u;
    {
        const bool branch_taken_0x145640 = (GPR_S32(ctx, 6) >= 0);
        ctx->pc = 0x145644u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 2096), GPR_U32(ctx, 3));
        if (branch_taken_0x145640) {
            ctx->pc = 0x14572Cu;
            goto label_14572c;
        }
    }
    ctx->pc = 0x145648u;
    // 0x145648: 0x3c021000
    ctx->pc = 0x145648u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x14564c: 0x3c131000
    ctx->pc = 0x14564cu;
    SET_GPR_U32(ctx, 19, ((uint32_t)4096 << 16));
    // 0x145650: 0xafa20000
    ctx->pc = 0x145650u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x145654: 0x3c121000
    ctx->pc = 0x145654u;
    SET_GPR_U32(ctx, 18, ((uint32_t)4096 << 16));
    // 0x145658: 0x34422010
    ctx->pc = 0x145658u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8208));
    // 0x14565c: 0x3c141000
    ctx->pc = 0x14565cu;
    SET_GPR_U32(ctx, 20, ((uint32_t)4096 << 16));
    // 0x145660: 0x3c151000
    ctx->pc = 0x145660u;
    SET_GPR_U32(ctx, 21, ((uint32_t)4096 << 16));
    // 0x145664: 0x3c16fffe
    ctx->pc = 0x145664u;
    SET_GPR_U32(ctx, 22, ((uint32_t)65534 << 16));
    // 0x145668: 0x3c171000
    ctx->pc = 0x145668u;
    SET_GPR_U32(ctx, 23, ((uint32_t)4096 << 16));
    // 0x14566c: 0x3c1e1000
    ctx->pc = 0x14566cu;
    SET_GPR_U32(ctx, 30, ((uint32_t)4096 << 16));
    // 0x145670: 0x3c111000
    ctx->pc = 0x145670u;
    SET_GPR_U32(ctx, 17, ((uint32_t)4096 << 16));
    // 0x145674: 0xafa20000
    ctx->pc = 0x145674u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x145678: 0x3673f590
    ctx->pc = 0x145678u;
    SET_GPR_U32(ctx, 19, OR32(GPR_U32(ctx, 19), 62864));
    // 0x14567c: 0x3652f520
    ctx->pc = 0x14567cu;
    SET_GPR_U32(ctx, 18, OR32(GPR_U32(ctx, 18), 62752));
    // 0x145680: 0x3694b400
    ctx->pc = 0x145680u;
    SET_GPR_U32(ctx, 20, OR32(GPR_U32(ctx, 20), 46080));
    // 0x145684: 0x36b5b000
    ctx->pc = 0x145684u;
    SET_GPR_U32(ctx, 21, OR32(GPR_U32(ctx, 21), 45056));
    // 0x145688: 0x36d6ffff
    ctx->pc = 0x145688u;
    SET_GPR_U32(ctx, 22, OR32(GPR_U32(ctx, 22), 65535));
    // 0x14568c: 0x36f7b020
    ctx->pc = 0x14568cu;
    SET_GPR_U32(ctx, 23, OR32(GPR_U32(ctx, 23), 45088));
    // 0x145690: 0x37deb420
    ctx->pc = 0x145690u;
    SET_GPR_U32(ctx, 30, OR32(GPR_U32(ctx, 30), 46112));
    // 0x145694: 0x36312000
    ctx->pc = 0x145694u;
    SET_GPR_U32(ctx, 17, OR32(GPR_U32(ctx, 17), 8192));
    // 0x145698: 0x8e0210a0
    ctx->pc = 0x145698u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 4256)));
    // 0x14569c: 0x0
    ctx->pc = 0x14569cu;
    // NOP
label_1456a0:
    // 0x1456a0: 0x10400017
    ctx->pc = 0x1456A0u;
    {
        const bool branch_taken_0x1456a0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1456A4u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1456a0) {
            ctx->pc = 0x145700u;
            goto label_145700;
        }
    }
    ctx->pc = 0x1456A8u;
    // 0x1456a8: 0xc047598
    ctx->pc = 0x1456A8u;
    SET_GPR_U32(ctx, 31, 0x1456B0u);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1456B0u; }
    }
    if (ctx->pc != 0x1456B0u) { return; }
    ctx->pc = 0x1456B0u;
    // 0x1456b0: 0x8e430000
    ctx->pc = 0x1456b0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1456b4: 0x3c040001
    ctx->pc = 0x1456b4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)1 << 16));
    // 0x1456b8: 0x641825
    ctx->pc = 0x1456b8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1456bc: 0xae630000
    ctx->pc = 0x1456bcu;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x1456c0: 0xae800000
    ctx->pc = 0x1456c0u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 0));
    // 0x1456c4: 0xaea00000
    ctx->pc = 0x1456c4u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 0));
    // 0x1456c8: 0x8e430000
    ctx->pc = 0x1456c8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1456cc: 0x761824
    ctx->pc = 0x1456ccu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 22)));
    // 0x1456d0: 0x10400003
    ctx->pc = 0x1456D0u;
    {
        const bool branch_taken_0x1456d0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1456D4u;
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
        if (branch_taken_0x1456d0) {
            ctx->pc = 0x1456E0u;
            goto label_1456e0;
        }
    }
    ctx->pc = 0x1456D8u;
    // 0x1456d8: 0xc0475ae
    ctx->pc = 0x1456D8u;
    SET_GPR_U32(ctx, 31, 0x1456E0u);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1456E0u; }
    }
    if (ctx->pc != 0x1456E0u) { return; }
    ctx->pc = 0x1456E0u;
label_1456e0:
    // 0x1456e0: 0xaee00000
    ctx->pc = 0x1456e0u;
    WRITE32(ADD32(GPR_U32(ctx, 23), 0), GPR_U32(ctx, 0));
    // 0x1456e4: 0x3c044000
    ctx->pc = 0x1456e4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)16384 << 16));
    // 0x1456e8: 0xafc00000
    ctx->pc = 0x1456e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 0));
    // 0x1456ec: 0x102d
    ctx->pc = 0x1456ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1456f0: 0x8fa30000
    ctx->pc = 0x1456f0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1456f4: 0xac640000
    ctx->pc = 0x1456f4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
    // 0x1456f8: 0x10000023
    ctx->pc = 0x1456F8u;
    {
        const bool branch_taken_0x1456f8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1456FCu;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
        if (branch_taken_0x1456f8) {
            ctx->pc = 0x145788u;
            goto label_145788;
        }
    }
    ctx->pc = 0x145700u;
label_145700:
    // 0x145700: 0x28421389
    ctx->pc = 0x145700u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 2), 5001));
    // 0x145704: 0x14400006
    ctx->pc = 0x145704u;
    {
        const bool branch_taken_0x145704 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x145708u;
        SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 1));
        if (branch_taken_0x145704) {
            ctx->pc = 0x145720u;
            goto label_145720;
        }
    }
    ctx->pc = 0x14570Cu;
    // 0x14570c: 0x8e040870
    ctx->pc = 0x14570cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 2160)));
    // 0x145710: 0x402d
    ctx->pc = 0x145710u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145714: 0xc051ff8
    ctx->pc = 0x145714u;
    SET_GPR_U32(ctx, 31, 0x14571Cu);
    ctx->pc = 0x145718u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 8));
    ctx->pc = 0x147FE0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00147FE0_0x147fe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14571Cu; }
    }
    if (ctx->pc != 0x14571Cu) { return; }
    ctx->pc = 0x14571Cu;
    // 0x14571c: 0x7ba80010
    ctx->pc = 0x14571cu;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 29), 16)));
label_145720:
    // 0x145720: 0xde260000
    ctx->pc = 0x145720u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x145724: 0x4c2ffde
    ctx->pc = 0x145724u;
    {
        const bool branch_taken_0x145724 = (GPR_S32(ctx, 6) < 0);
        if (branch_taken_0x145724) {
            ctx->pc = 0x145728u;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 4256)));
            ctx->pc = 0x1456A0u;
            goto label_1456a0;
        }
    }
    ctx->pc = 0x14572Cu;
label_14572c:
    // 0x14572c: 0x3c021000
    ctx->pc = 0x14572cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x145730: 0x3c041000
    ctx->pc = 0x145730u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x145734: 0xdc842030
    ctx->pc = 0x145734u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 4), 8240)));
    // 0x145738: 0x34422020
    ctx->pc = 0x145738u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8224));
    // 0x14573c: 0x8c420000
    ctx->pc = 0x14573cu;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x145740: 0x4183c
    ctx->pc = 0x145740u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) << (32 + 0));
    // 0x145744: 0x3183f
    ctx->pc = 0x145744u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x145748: 0x4810005
    ctx->pc = 0x145748u;
    {
        const bool branch_taken_0x145748 = (GPR_S32(ctx, 4) >= 0);
        ctx->pc = 0x14574Cu;
        WRITE32(ADD32(GPR_U32(ctx, 16), 2128), GPR_U32(ctx, 3));
        if (branch_taken_0x145748) {
            ctx->pc = 0x145760u;
            goto label_145760;
        }
    }
    ctx->pc = 0x145750u;
    // 0x145750: 0x3042001f
    ctx->pc = 0x145750u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 31));
    // 0x145754: 0x21023
    ctx->pc = 0x145754u;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x145758: 0x10000002
    ctx->pc = 0x145758u;
    {
        const bool branch_taken_0x145758 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x14575Cu;
        SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 31));
        if (branch_taken_0x145758) {
            ctx->pc = 0x145764u;
            goto label_145764;
        }
    }
    ctx->pc = 0x145760u;
label_145760:
    // 0x145760: 0x24020020
    ctx->pc = 0x145760u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 32));
label_145764:
    // 0x145764: 0xae020854
    ctx->pc = 0x145764u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 2132), GPR_U32(ctx, 2));
    // 0x145768: 0x6183c
    ctx->pc = 0x145768u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 6) << (32 + 0));
    // 0x14576c: 0x3183f
    ctx->pc = 0x14576cu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x145770: 0x30c2ffff
    ctx->pc = 0x145770u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 6), 65535));
    // 0x145774: 0x2c630001
    ctx->pc = 0x145774u;
    SET_GPR_U32(ctx, 3, SLTU32(GPR_U32(ctx, 3), 1));
    // 0x145778: 0x21400
    ctx->pc = 0x145778u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 16));
    // 0x14577c: 0xae030134
    ctx->pc = 0x14577cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 308), GPR_U32(ctx, 3));
    // 0x145780: 0x21403
    ctx->pc = 0x145780u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x145784: 0xdfbf00b0
    ctx->pc = 0x145784u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 176)));
label_145788:
    // 0x145788: 0xdfbe00a0
    ctx->pc = 0x145788u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x14578c: 0xdfb70090
    ctx->pc = 0x14578cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x145790: 0xdfb60080
    ctx->pc = 0x145790u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x145794: 0xdfb50070
    ctx->pc = 0x145794u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x145798: 0xdfb40060
    ctx->pc = 0x145798u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x14579c: 0xdfb30050
    ctx->pc = 0x14579cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1457a0: 0xdfb20040
    ctx->pc = 0x1457a0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1457a4: 0xdfb10030
    ctx->pc = 0x1457a4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1457a8: 0xdfb00020
    ctx->pc = 0x1457a8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1457ac: 0x3e00008
    ctx->pc = 0x1457ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1457B0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 192));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1455B8u: goto label_1455b8;
            case 0x1455D8u: goto label_1455d8;
            case 0x145610u: goto label_145610;
            case 0x145614u: goto label_145614;
            case 0x145618u: goto label_145618;
            case 0x14561Cu: goto label_14561c;
            case 0x1456A0u: goto label_1456a0;
            case 0x1456E0u: goto label_1456e0;
            case 0x145700u: goto label_145700;
            case 0x145720u: goto label_145720;
            case 0x14572Cu: goto label_14572c;
            case 0x145760u: goto label_145760;
            case 0x145764u: goto label_145764;
            case 0x145788u: goto label_145788;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1457B4u;
    // 0x1457b4: 0x0
    ctx->pc = 0x1457b4u;
    // NOP
}
