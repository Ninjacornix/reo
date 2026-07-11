#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00147508
// Address: 0x147508 - 0x1477a0
void sub_00147508_0x147508(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x147508u;

    // 0x147508: 0x240703ff
    ctx->pc = 0x147508u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 1023));
    // 0x14750c: 0x27bdff80
    ctx->pc = 0x14750cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x147510: 0xc7001a
    ctx->pc = 0x147510u;
    { int32_t divisor = GPR_S32(ctx, 7);    int32_t dividend = GPR_S32(ctx, 6);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint32_t)(dividend / divisor);            ctx->hi = (uint32_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1 : -1; ctx->hi = dividend;    } }
    // 0x147514: 0xffb00040
    ctx->pc = 0x147514u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 16));
    // 0x147518: 0x3c02000f
    ctx->pc = 0x147518u;
    SET_GPR_U32(ctx, 2, ((uint32_t)15 << 16));
    // 0x14751c: 0xa0802d
    ctx->pc = 0x14751cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147520: 0x3442fc00
    ctx->pc = 0x147520u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 64512));
    // 0x147524: 0x3c030fff
    ctx->pc = 0x147524u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4095 << 16));
    // 0x147528: 0xffb10050
    ctx->pc = 0x147528u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 17));
    // 0x14752c: 0x3463ffff
    ctx->pc = 0x14752cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 65535));
    // 0x147530: 0xffbf0070
    ctx->pc = 0x147530u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x147534: 0x2021021
    ctx->pc = 0x147534u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x147538: 0xffb20060
    ctx->pc = 0x147538u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 18));
    // 0x14753c: 0x431024
    ctx->pc = 0x14753cu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x147540: 0x50e00001
    ctx->pc = 0x147540u;
    {
        const bool branch_taken_0x147540 = (GPR_U32(ctx, 7) == GPR_U32(ctx, 0));
        if (branch_taken_0x147540) {
            ctx->pc = 0x147544u;
            runtime->handleBreak(rdram, ctx);
            ctx->pc = 0x147548u;
            goto label_147548;
        }
    }
    ctx->pc = 0x147548u;
label_147548:
    // 0x147548: 0x3c031000
    ctx->pc = 0x147548u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x14754c: 0xafa60028
    ctx->pc = 0x14754cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 6));
    // 0x147550: 0x80882d
    ctx->pc = 0x147550u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147554: 0xafa2002c
    ctx->pc = 0x147554u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
    // 0x147558: 0x27a70020
    ctx->pc = 0x147558u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 29), 32));
    // 0x14755c: 0xafa00024
    ctx->pc = 0x14755cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 0));
    // 0x147560: 0x34632010
    ctx->pc = 0x147560u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 8208));
    // 0x147564: 0xafa00020
    ctx->pc = 0x147564u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 0));
    // 0x147568: 0x4012
    ctx->pc = 0x147568u;
    SET_GPR_U32(ctx, 8, ctx->lo);
    // 0x14756c: 0x25080001
    ctx->pc = 0x14756cu;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 1));
    // 0x147570: 0xafa80030
    ctx->pc = 0x147570u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 8));
    // 0x147574: 0x0
    ctx->pc = 0x147574u;
    // NOP
label_147578:
    // 0x147578: 0x8c620000
    ctx->pc = 0x147578u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x14757c: 0x0
    ctx->pc = 0x14757cu;
    // NOP
    // 0x147580: 0x0
    ctx->pc = 0x147580u;
    // NOP
    // 0x147584: 0x0
    ctx->pc = 0x147584u;
    // NOP
    // 0x147588: 0x0
    ctx->pc = 0x147588u;
    // NOP
    // 0x14758c: 0x440fffa
    ctx->pc = 0x14758Cu;
    {
        const bool branch_taken_0x14758c = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x14758c) {
            ctx->pc = 0x147578u;
            goto label_147578;
        }
    }
    ctx->pc = 0x147594u;
    // 0x147594: 0x3c050014
    ctx->pc = 0x147594u;
    SET_GPR_U32(ctx, 5, ((uint32_t)20 << 16));
    // 0x147598: 0x24040003
    ctx->pc = 0x147598u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 3));
    // 0x14759c: 0x24a573c0
    ctx->pc = 0x14759cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 29632));
    // 0x1475a0: 0xc0450d0
    ctx->pc = 0x1475A0u;
    SET_GPR_U32(ctx, 31, 0x1475A8u);
    ctx->pc = 0x1475A4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x114340u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114340_0x114340(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1475A8u; }
    }
    if (ctx->pc != 0x1475A8u) { return; }
    ctx->pc = 0x1475A8u;
    // 0x1475a8: 0x40902d
    ctx->pc = 0x1475a8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1475ac: 0x24030008
    ctx->pc = 0x1475acu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 8));
    // 0x1475b0: 0x3c021000
    ctx->pc = 0x1475b0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1475b4: 0x24040003
    ctx->pc = 0x1475b4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 3));
    // 0x1475b8: 0x3442e010
    ctx->pc = 0x1475b8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 57360));
    // 0x1475bc: 0xc04548e
    ctx->pc = 0x1475BCu;
    SET_GPR_U32(ctx, 31, 0x1475C4u);
    ctx->pc = 0x1475C0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x115238u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00115238_0x115238(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1475C4u; }
    }
    if (ctx->pc != 0x1475C4u) { return; }
    ctx->pc = 0x1475C4u;
    // 0x1475c4: 0xc047598
    ctx->pc = 0x1475C4u;
    SET_GPR_U32(ctx, 31, 0x1475CCu);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1475CCu; }
    }
    if (ctx->pc != 0x1475CCu) { return; }
    ctx->pc = 0x1475CCu;
    // 0x1475cc: 0x3c030fff
    ctx->pc = 0x1475ccu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4095 << 16));
    // 0x1475d0: 0x3c041000
    ctx->pc = 0x1475d0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x1475d4: 0x3463ffff
    ctx->pc = 0x1475d4u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 65535));
    // 0x1475d8: 0x3484b010
    ctx->pc = 0x1475d8u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 45072));
    // 0x1475dc: 0x2031824
    ctx->pc = 0x1475dcu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x1475e0: 0x3c051000
    ctx->pc = 0x1475e0u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x1475e4: 0xac830000
    ctx->pc = 0x1475e4u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x1475e8: 0x34a5b020
    ctx->pc = 0x1475e8u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 45088));
    // 0x1475ec: 0x3403ffc0
    ctx->pc = 0x1475ecu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 0), 65472));
    // 0x1475f0: 0x3c041000
    ctx->pc = 0x1475f0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x1475f4: 0xaca30000
    ctx->pc = 0x1475f4u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x1475f8: 0x3484b000
    ctx->pc = 0x1475f8u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 45056));
    // 0x1475fc: 0x24030100
    ctx->pc = 0x1475fcu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 256));
    // 0x147600: 0xac830000
    ctx->pc = 0x147600u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x147604: 0x10400004
    ctx->pc = 0x147604u;
    {
        const bool branch_taken_0x147604 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x147608u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x147604) {
            ctx->pc = 0x147618u;
            goto label_147618;
        }
    }
    ctx->pc = 0x14760Cu;
    // 0x14760c: 0xc0475ae
    ctx->pc = 0x14760Cu;
    SET_GPR_U32(ctx, 31, 0x147614u);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147614u; }
    }
    if (ctx->pc != 0x147614u) { return; }
    ctx->pc = 0x147614u;
    // 0x147614: 0x3c021000
    ctx->pc = 0x147614u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
label_147618:
    // 0x147618: 0x3c037000
    ctx->pc = 0x147618u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x14761c: 0x34422000
    ctx->pc = 0x14761cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8192));
    // 0x147620: 0x346303ff
    ctx->pc = 0x147620u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 1023));
    // 0x147624: 0xac430000
    ctx->pc = 0x147624u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x147628: 0x24060004
    ctx->pc = 0x147628u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 4));
    // 0x14762c: 0x8e240870
    ctx->pc = 0x14762cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 2160)));
    // 0x147630: 0x3a0282d
    ctx->pc = 0x147630u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x147634: 0xc051fda
    ctx->pc = 0x147634u;
    SET_GPR_U32(ctx, 31, 0x14763Cu);
    ctx->pc = 0x147638u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 6));
    ctx->pc = 0x147F68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F68_0x147f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14763Cu; }
    }
    if (ctx->pc != 0x14763Cu) { return; }
    ctx->pc = 0x14763Cu;
    // 0x14763c: 0x8fa40024
    ctx->pc = 0x14763cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x147640: 0x8fa30030
    ctx->pc = 0x147640u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x147644: 0x0
    ctx->pc = 0x147644u;
    // NOP
label_147648:
    // 0x147648: 0x8fa20020
    ctx->pc = 0x147648u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x14764c: 0x43102a
    ctx->pc = 0x14764cu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 2), GPR_S32(ctx, 3)));
    // 0x147650: 0x0
    ctx->pc = 0x147650u;
    // NOP
    // 0x147654: 0x0
    ctx->pc = 0x147654u;
    // NOP
    // 0x147658: 0x0
    ctx->pc = 0x147658u;
    // NOP
    // 0x14765c: 0x1440fffa
    ctx->pc = 0x14765Cu;
    {
        const bool branch_taken_0x14765c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x14765c) {
            ctx->pc = 0x147648u;
            goto label_147648;
        }
    }
    ctx->pc = 0x147664u;
    // 0x147664: 0x10800004
    ctx->pc = 0x147664u;
    {
        const bool branch_taken_0x147664 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x147668u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x147664) {
            ctx->pc = 0x147678u;
            goto label_147678;
        }
    }
    ctx->pc = 0x14766Cu;
    // 0x14766c: 0x3c050024
    ctx->pc = 0x14766cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x147670: 0xc05221c
    ctx->pc = 0x147670u;
    SET_GPR_U32(ctx, 31, 0x147678u);
    ctx->pc = 0x147674u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294959088));
    ctx->pc = 0x148870u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x147678u; }
    }
    if (ctx->pc != 0x147678u) { return; }
    ctx->pc = 0x147678u;
label_147678:
    // 0x147678: 0x3c031000
    ctx->pc = 0x147678u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x14767c: 0x34632010
    ctx->pc = 0x14767cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 8208));
label_147680:
    // 0x147680: 0x8c620000
    ctx->pc = 0x147680u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x147684: 0x0
    ctx->pc = 0x147684u;
    // NOP
    // 0x147688: 0x0
    ctx->pc = 0x147688u;
    // NOP
    // 0x14768c: 0x0
    ctx->pc = 0x14768cu;
    // NOP
    // 0x147690: 0x0
    ctx->pc = 0x147690u;
    // NOP
    // 0x147694: 0x440fffa
    ctx->pc = 0x147694u;
    {
        const bool branch_taken_0x147694 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x147694) {
            ctx->pc = 0x147680u;
            goto label_147680;
        }
    }
    ctx->pc = 0x14769Cu;
    // 0x14769c: 0xc045474
    ctx->pc = 0x14769Cu;
    SET_GPR_U32(ctx, 31, 0x1476A4u);
    ctx->pc = 0x1476A0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0x1151D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001151D0_0x1151d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1476A4u; }
    }
    if (ctx->pc != 0x1476A4u) { return; }
    ctx->pc = 0x1476A4u;
    // 0x1476a4: 0x240282d
    ctx->pc = 0x1476a4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1476a8: 0xc0450d4
    ctx->pc = 0x1476A8u;
    SET_GPR_U32(ctx, 31, 0x1476B0u);
    ctx->pc = 0x1476ACu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0x114350u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114350_0x114350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1476B0u; }
    }
    if (ctx->pc != 0x1476B0u) { return; }
    ctx->pc = 0x1476B0u;
    // 0x1476b0: 0xdfbf0070
    ctx->pc = 0x1476b0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1476b4: 0xdfb20060
    ctx->pc = 0x1476b4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1476b8: 0xdfb10050
    ctx->pc = 0x1476b8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1476bc: 0xdfb00040
    ctx->pc = 0x1476bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1476c0: 0x3e00008
    ctx->pc = 0x1476C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1476C4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 128));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147548u: goto label_147548;
            case 0x147578u: goto label_147578;
            case 0x147618u: goto label_147618;
            case 0x147648u: goto label_147648;
            case 0x147678u: goto label_147678;
            case 0x147680u: goto label_147680;
            case 0x1476F8u: goto label_1476f8;
            case 0x14775Cu: goto label_14775c;
            case 0x14778Cu: goto label_14778c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1476C8u;
    // 0x1476c8: 0x3c021000
    ctx->pc = 0x1476c8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1476cc: 0x24030010
    ctx->pc = 0x1476ccu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 16));
    // 0x1476d0: 0x3442e010
    ctx->pc = 0x1476d0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 57360));
    // 0x1476d4: 0xa0302d
    ctx->pc = 0x1476d4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1476d8: 0xac430000
    ctx->pc = 0x1476d8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x1476dc: 0x8cc20000
    ctx->pc = 0x1476dcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1476e0: 0x14400005
    ctx->pc = 0x1476E0u;
    {
        const bool branch_taken_0x1476e0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1476E4u;
        SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 0), 65535));
        if (branch_taken_0x1476e0) {
            ctx->pc = 0x1476F8u;
            goto label_1476f8;
        }
    }
    ctx->pc = 0x1476E8u;
    // 0x1476e8: 0xf
    ctx->pc = 0x1476e8u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x1476ec: 0x42000038
    ctx->pc = 0x1476ecu;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x1476f0: 0x3e00008
    ctx->pc = 0x1476F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1476F4u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147548u: goto label_147548;
            case 0x147578u: goto label_147578;
            case 0x147618u: goto label_147618;
            case 0x147648u: goto label_147648;
            case 0x147678u: goto label_147678;
            case 0x147680u: goto label_147680;
            case 0x1476F8u: goto label_1476f8;
            case 0x14775Cu: goto label_14775c;
            case 0x14778Cu: goto label_14778c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1476F8u;
label_1476f8:
    // 0x1476f8: 0xe2102b
    ctx->pc = 0x1476f8u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x1476fc: 0x10400017
    ctx->pc = 0x1476FCu;
    {
        const bool branch_taken_0x1476fc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x147700u;
        SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
        if (branch_taken_0x1476fc) {
            ctx->pc = 0x14775Cu;
            goto label_14775c;
        }
    }
    ctx->pc = 0x147704u;
    // 0x147704: 0x8cc40004
    ctx->pc = 0x147704u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x147708: 0x3c021000
    ctx->pc = 0x147708u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x14770c: 0x3442b410
    ctx->pc = 0x14770cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 46096));
    // 0x147710: 0xac440000
    ctx->pc = 0x147710u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x147714: 0x3463b420
    ctx->pc = 0x147714u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 46112));
    // 0x147718: 0xac670000
    ctx->pc = 0x147718u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 7));
    // 0x14771c: 0x3c021000
    ctx->pc = 0x14771cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x147720: 0x3442b400
    ctx->pc = 0x147720u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 46080));
    // 0x147724: 0x24030101
    ctx->pc = 0x147724u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 257));
    // 0x147728: 0xac430000
    ctx->pc = 0x147728u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x14772c: 0x3c05000f
    ctx->pc = 0x14772cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)15 << 16));
    // 0x147730: 0x34a5fff0
    ctx->pc = 0x147730u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 65520));
    // 0x147734: 0x3c040fff
    ctx->pc = 0x147734u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4095 << 16));
    // 0x147738: 0x8cc30004
    ctx->pc = 0x147738u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x14773c: 0x3484ffff
    ctx->pc = 0x14773cu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 65535));
    // 0x147740: 0x8cc20000
    ctx->pc = 0x147740u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x147744: 0x651821
    ctx->pc = 0x147744u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x147748: 0x641824
    ctx->pc = 0x147748u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x14774c: 0x471023
    ctx->pc = 0x14774cu;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x147750: 0xacc20000
    ctx->pc = 0x147750u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 2));
    // 0x147754: 0x1000000d
    ctx->pc = 0x147754u;
    {
        const bool branch_taken_0x147754 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x147758u;
        WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
        if (branch_taken_0x147754) {
            ctx->pc = 0x14778Cu;
            goto label_14778c;
        }
    }
    ctx->pc = 0x14775Cu;
label_14775c:
    // 0x14775c: 0x8cc40004
    ctx->pc = 0x14775cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x147760: 0x3c021000
    ctx->pc = 0x147760u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x147764: 0x3442b410
    ctx->pc = 0x147764u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 46096));
    // 0x147768: 0xac440000
    ctx->pc = 0x147768u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x14776c: 0x3463b420
    ctx->pc = 0x14776cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 46112));
    // 0x147770: 0x3c021000
    ctx->pc = 0x147770u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x147774: 0x24050101
    ctx->pc = 0x147774u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 257));
    // 0x147778: 0x8cc40000
    ctx->pc = 0x147778u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x14777c: 0x3442b400
    ctx->pc = 0x14777cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 46080));
    // 0x147780: 0xac640000
    ctx->pc = 0x147780u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4));
    // 0x147784: 0xac450000
    ctx->pc = 0x147784u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5)); // MMIO: 0x10000000
    // 0x147788: 0xacc00000
    ctx->pc = 0x147788u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
label_14778c:
    // 0x14778c: 0xf
    ctx->pc = 0x14778cu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x147790: 0x42000038
    ctx->pc = 0x147790u;
    ctx->cop0_status |= 0x10000; // Enable interrupts
    // 0x147794: 0x3e00008
    ctx->pc = 0x147794u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147798u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147548u: goto label_147548;
            case 0x147578u: goto label_147578;
            case 0x147618u: goto label_147618;
            case 0x147648u: goto label_147648;
            case 0x147678u: goto label_147678;
            case 0x147680u: goto label_147680;
            case 0x1476F8u: goto label_1476f8;
            case 0x14775Cu: goto label_14775c;
            case 0x14778Cu: goto label_14778c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14779Cu;
    // 0x14779c: 0x0
    ctx->pc = 0x14779cu;
    // NOP
}
