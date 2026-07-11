#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00128860
// Address: 0x128860 - 0x128a60
void sub_00128860_0x128860(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x128860u;

    // 0x128860: 0x27bdffb0
    ctx->pc = 0x128860u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x128864: 0xffb40030
    ctx->pc = 0x128864u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x128868: 0x140a02d
    ctx->pc = 0x128868u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12886c: 0xffb00010
    ctx->pc = 0x12886cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x128870: 0xe0802d
    ctx->pc = 0x128870u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128874: 0xffb10018
    ctx->pc = 0x128874u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x128878: 0x120882d
    ctx->pc = 0x128878u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12887c: 0xffb20020
    ctx->pc = 0x12887cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x128880: 0x160902d
    ctx->pc = 0x128880u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128884: 0xffb30028
    ctx->pc = 0x128884u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x128888: 0x80982d
    ctx->pc = 0x128888u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12888c: 0xffb50038
    ctx->pc = 0x12888cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x128890: 0xa0a82d
    ctx->pc = 0x128890u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128894: 0xffb60040
    ctx->pc = 0x128894u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x128898: 0xc0b02d
    ctx->pc = 0x128898u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12889c: 0xffbf0048
    ctx->pc = 0x12889cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x1288a0: 0x16800005
    ctx->pc = 0x1288A0u;
    {
        const bool branch_taken_0x1288a0 = (GPR_U32(ctx, 20) != GPR_U32(ctx, 0));
        ctx->pc = 0x1288A4u;
        WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 8));
        if (branch_taken_0x1288a0) {
            ctx->pc = 0x1288B8u;
            goto label_1288b8;
        }
    }
    ctx->pc = 0x1288A8u;
    // 0x1288a8: 0x3c040024
    ctx->pc = 0x1288a8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x1288ac: 0x10000006
    ctx->pc = 0x1288ACu;
    {
        const bool branch_taken_0x1288ac = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1288B0u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294941904));
        if (branch_taken_0x1288ac) {
            ctx->pc = 0x1288C8u;
            goto label_1288c8;
        }
    }
    ctx->pc = 0x1288B4u;
    // 0x1288b4: 0x0
    ctx->pc = 0x1288b4u;
    // NOP
label_1288b8:
    // 0x1288b8: 0x1e400007
    ctx->pc = 0x1288B8u;
    {
        const bool branch_taken_0x1288b8 = (GPR_S32(ctx, 18) > 0);
        if (branch_taken_0x1288b8) {
            ctx->pc = 0x1288D8u;
            goto label_1288d8;
        }
    }
    ctx->pc = 0x1288C0u;
    // 0x1288c0: 0x3c040024
    ctx->pc = 0x1288c0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x1288c4: 0x24849d00
    ctx->pc = 0x1288c4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294941952));
label_1288c8:
    // 0x1288c8: 0xc04a034
    ctx->pc = 0x1288C8u;
    SET_GPR_U32(ctx, 31, 0x1288D0u);
    ctx->pc = 0x1280D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1288D0u; }
    }
    if (ctx->pc != 0x1288D0u) { return; }
    ctx->pc = 0x1288D0u;
    // 0x1288d0: 0x10000058
    ctx->pc = 0x1288D0u;
    {
        const bool branch_taken_0x1288d0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1288D4u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967293));
        if (branch_taken_0x1288d0) {
            ctx->pc = 0x128A34u;
            goto label_128a34;
        }
    }
    ctx->pc = 0x1288D8u;
label_1288d8:
    // 0x1288d8: 0xc04a176
    ctx->pc = 0x1288D8u;
    SET_GPR_U32(ctx, 31, 0x1288E0u);
    ctx->pc = 0x1288DCu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1285D8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001285D8_0x1285d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1288E0u; }
    }
    if (ctx->pc != 0x1288E0u) { return; }
    ctx->pc = 0x1288E0u;
    // 0x1288e0: 0x4420055
    ctx->pc = 0x1288E0u;
    {
        const bool branch_taken_0x1288e0 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x1288e0) {
            ctx->pc = 0x1288E4u;
            SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
            ctx->pc = 0x128A38u;
            goto label_128a38;
        }
    }
    ctx->pc = 0x1288E8u;
    // 0x1288e8: 0x3c020021
    ctx->pc = 0x1288e8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x1288ec: 0x2447d234
    ctx->pc = 0x1288ecu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 2), 4294955572));
    // 0x1288f0: 0x8ce30000
    ctx->pc = 0x1288f0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1288f4: 0x4600004
    ctx->pc = 0x1288F4u;
    {
        const bool branch_taken_0x1288f4 = (GPR_S32(ctx, 3) < 0);
        ctx->pc = 0x1288F8u;
        SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
        if (branch_taken_0x1288f4) {
            ctx->pc = 0x128908u;
            goto label_128908;
        }
    }
    ctx->pc = 0x1288FCu;
    // 0x1288fc: 0x1000002a
    ctx->pc = 0x1288FCu;
    {
        const bool branch_taken_0x1288fc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x128900u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294941992));
        if (branch_taken_0x1288fc) {
            ctx->pc = 0x1289A8u;
            goto label_1289a8;
        }
    }
    ctx->pc = 0x128904u;
    // 0x128904: 0x0
    ctx->pc = 0x128904u;
    // NOP
label_128908:
    // 0x128908: 0xacf30000
    ctx->pc = 0x128908u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 19));
    // 0x12890c: 0x3c020021
    ctx->pc = 0x12890cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x128910: 0x220202d
    ctx->pc = 0x128910u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128914: 0x282d
    ctx->pc = 0x128914u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128918: 0x2406011c
    ctx->pc = 0x128918u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 284));
    // 0x12891c: 0xc041f1a
    ctx->pc = 0x12891Cu;
    SET_GPR_U32(ctx, 31, 0x128924u);
    ctx->pc = 0x128920u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294955564), GPR_U32(ctx, 0));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128924u; }
    }
    if (ctx->pc != 0x128924u) { return; }
    ctx->pc = 0x128924u;
    // 0x128924: 0x131880
    ctx->pc = 0x128924u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 19), 2));
    // 0x128928: 0x3c010021
    ctx->pc = 0x128928u;
    SET_GPR_U32(ctx, 1, ((uint32_t)33 << 16));
    // 0x12892c: 0x230821
    ctx->pc = 0x12892cu;
    SET_GPR_U32(ctx, 1, ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x128930: 0xac31cd00
    ctx->pc = 0x128930u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294954240), GPR_U32(ctx, 17));
    // 0x128934: 0x16000014
    ctx->pc = 0x128934u;
    {
        const bool branch_taken_0x128934 = (GPR_U32(ctx, 16) != GPR_U32(ctx, 0));
        ctx->pc = 0x128938u;
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
        if (branch_taken_0x128934) {
            ctx->pc = 0x128988u;
            goto label_128988;
        }
    }
    ctx->pc = 0x12893Cu;
    // 0x12893c: 0x2a0202d
    ctx->pc = 0x12893cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128940: 0xc04a490
    ctx->pc = 0x128940u;
    SET_GPR_U32(ctx, 31, 0x128948u);
    ctx->pc = 0x128944u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x129240u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00129240_0x129240(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128948u; }
    }
    if (ctx->pc != 0x128948u) { return; }
    ctx->pc = 0x128948u;
    // 0x128948: 0x3c130021
    ctx->pc = 0x128948u;
    SET_GPR_U32(ctx, 19, ((uint32_t)33 << 16));
    // 0x12894c: 0x10400014
    ctx->pc = 0x12894Cu;
    {
        const bool branch_taken_0x12894c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x128950u;
        WRITE32(ADD32(GPR_U32(ctx, 19), 4294955568), GPR_U32(ctx, 2));
        if (branch_taken_0x12894c) {
            ctx->pc = 0x1289A0u;
            goto label_1289a0;
        }
    }
    ctx->pc = 0x128954u;
    // 0x128954: 0x2a0202d
    ctx->pc = 0x128954u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128958: 0x2c0282d
    ctx->pc = 0x128958u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12895c: 0x26260010
    ctx->pc = 0x12895cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 17), 16));
    // 0x128960: 0x3a0382d
    ctx->pc = 0x128960u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128964: 0x27a80004
    ctx->pc = 0x128964u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 29), 4));
    // 0x128968: 0xc04a786
    ctx->pc = 0x128968u;
    SET_GPR_U32(ctx, 31, 0x128970u);
    ctx->pc = 0x12896Cu;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 29), 8));
    ctx->pc = 0x129E18u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00129E18_0x129e18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128970u; }
    }
    if (ctx->pc != 0x128970u) { return; }
    ctx->pc = 0x128970u;
    // 0x128970: 0x4420031
    ctx->pc = 0x128970u;
    {
        const bool branch_taken_0x128970 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x128970) {
            ctx->pc = 0x128974u;
            SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
            ctx->pc = 0x128A38u;
            goto label_128a38;
        }
    }
    ctx->pc = 0x128978u;
    // 0x128978: 0x8fa20004
    ctx->pc = 0x128978u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x12897c: 0x10000012
    ctx->pc = 0x12897Cu;
    {
        const bool branch_taken_0x12897c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x128980u;
        WRITE32(ADD32(GPR_U32(ctx, 17), 276), GPR_U32(ctx, 2));
        if (branch_taken_0x12897c) {
            ctx->pc = 0x1289C8u;
            goto label_1289c8;
        }
    }
    ctx->pc = 0x128984u;
    // 0x128984: 0x0
    ctx->pc = 0x128984u;
    // NOP
label_128988:
    // 0x128988: 0x8fa50000
    ctx->pc = 0x128988u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12898c: 0x200202d
    ctx->pc = 0x12898cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128990: 0xc04a432
    ctx->pc = 0x128990u;
    SET_GPR_U32(ctx, 31, 0x128998u);
    ctx->pc = 0x128994u;
    SET_GPR_U32(ctx, 19, ((uint32_t)33 << 16));
    ctx->pc = 0x1290C8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001290C8_0x1290c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128998u; }
    }
    if (ctx->pc != 0x128998u) { return; }
    ctx->pc = 0x128998u;
    // 0x128998: 0x14400007
    ctx->pc = 0x128998u;
    {
        const bool branch_taken_0x128998 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x12899Cu;
        WRITE32(ADD32(GPR_U32(ctx, 19), 4294955568), GPR_U32(ctx, 2));
        if (branch_taken_0x128998) {
            ctx->pc = 0x1289B8u;
            goto label_1289b8;
        }
    }
    ctx->pc = 0x1289A0u;
label_1289a0:
    // 0x1289a0: 0x3c040024
    ctx->pc = 0x1289a0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x1289a4: 0x24849d58
    ctx->pc = 0x1289a4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294942040));
label_1289a8:
    // 0x1289a8: 0xc04a034
    ctx->pc = 0x1289A8u;
    SET_GPR_U32(ctx, 31, 0x1289B0u);
    ctx->pc = 0x1280D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1289B0u; }
    }
    if (ctx->pc != 0x1289B0u) { return; }
    ctx->pc = 0x1289B0u;
    // 0x1289b0: 0x10000020
    ctx->pc = 0x1289B0u;
    {
        const bool branch_taken_0x1289b0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1289B4u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1289b0) {
            ctx->pc = 0x128A34u;
            goto label_128a34;
        }
    }
    ctx->pc = 0x1289B8u;
label_1289b8:
    // 0x1289b8: 0x200282d
    ctx->pc = 0x1289b8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1289bc: 0x26240010
    ctx->pc = 0x1289bcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 17), 16));
    // 0x1289c0: 0xc042d7e
    ctx->pc = 0x1289C0u;
    SET_GPR_U32(ctx, 31, 0x1289C8u);
    ctx->pc = 0x1289C4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 256));
    ctx->pc = 0x10B5F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B5F8_0x10b5f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1289C8u; }
    }
    if (ctx->pc != 0x1289C8u) { return; }
    ctx->pc = 0x1289C8u;
label_1289c8:
    // 0x1289c8: 0x8fa20050
    ctx->pc = 0x1289c8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1289cc: 0x264307ff
    ctx->pc = 0x1289ccu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 18), 2047));
    // 0x1289d0: 0xa220000e
    ctx->pc = 0x1289d0u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 14), (uint8_t)GPR_U32(ctx, 0));
    // 0x1289d4: 0x2673d230
    ctx->pc = 0x1289d4u;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 19), 4294955568));
    // 0x1289d8: 0xa222000f
    ctx->pc = 0x1289d8u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 15), (uint8_t)GPR_U32(ctx, 2));
    // 0x1289dc: 0x2a420000
    ctx->pc = 0x1289dcu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 18), 0));
    // 0x1289e0: 0x62900b
    ctx->pc = 0x1289e0u;
    if (GPR_U32(ctx, 2) != 0) SET_GPR_U32(ctx, 18, GPR_U32(ctx, 3));
    // 0x1289e4: 0x3c020021
    ctx->pc = 0x1289e4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x1289e8: 0x8fa40000
    ctx->pc = 0x1289e8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1289ec: 0x123ac3
    ctx->pc = 0x1289ecu;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 18), 11));
    // 0x1289f0: 0x3c030021
    ctx->pc = 0x1289f0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x1289f4: 0xe0282d
    ctx->pc = 0x1289f4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1289f8: 0xae240110
    ctx->pc = 0x1289f8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 272), GPR_U32(ctx, 4));
    // 0x1289fc: 0x280302d
    ctx->pc = 0x1289fcu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128a00: 0x8e640000
    ctx->pc = 0x128a00u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x128a04: 0x0
    ctx->pc = 0x128a04u;
    // NOP
    // 0x128a08: 0xc04a5e8
    ctx->pc = 0x128A08u;
    SET_GPR_U32(ctx, 31, 0x128A10u);
    ctx->pc = 0x128A0Cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294955580), GPR_U32(ctx, 7));
    ctx->pc = 0x1297A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001297A0_0x1297a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128A10u; }
    }
    if (ctx->pc != 0x128A10u) { return; }
    ctx->pc = 0x128A10u;
    // 0x128a10: 0x40802d
    ctx->pc = 0x128a10u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x128a14: 0x6030006
    ctx->pc = 0x128A14u;
    {
        const bool branch_taken_0x128a14 = (GPR_S32(ctx, 16) >= 0);
        if (branch_taken_0x128a14) {
            ctx->pc = 0x128A18u;
            WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 0));
            ctx->pc = 0x128A30u;
            goto label_128a30;
        }
    }
    ctx->pc = 0x128A1Cu;
    // 0x128a1c: 0xc04a4d4
    ctx->pc = 0x128A1Cu;
    SET_GPR_U32(ctx, 31, 0x128A24u);
    ctx->pc = 0x128A20u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 19), 0)));
    ctx->pc = 0x129350u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00129350_0x129350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x128A24u; }
    }
    if (ctx->pc != 0x128A24u) { return; }
    ctx->pc = 0x128A24u;
    // 0x128a24: 0x10000003
    ctx->pc = 0x128A24u;
    {
        const bool branch_taken_0x128a24 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x128A28u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x128a24) {
            ctx->pc = 0x128A34u;
            goto label_128a34;
        }
    }
    ctx->pc = 0x128A2Cu;
    // 0x128a2c: 0x0
    ctx->pc = 0x128a2cu;
    // NOP
label_128a30:
    // 0x128a30: 0x102d
    ctx->pc = 0x128a30u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_128a34:
    // 0x128a34: 0xdfb00010
    ctx->pc = 0x128a34u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_128a38:
    // 0x128a38: 0xdfb10018
    ctx->pc = 0x128a38u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x128a3c: 0xdfb20020
    ctx->pc = 0x128a3cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x128a40: 0xdfb30028
    ctx->pc = 0x128a40u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x128a44: 0xdfb40030
    ctx->pc = 0x128a44u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x128a48: 0xdfb50038
    ctx->pc = 0x128a48u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x128a4c: 0xdfb60040
    ctx->pc = 0x128a4cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x128a50: 0xdfbf0048
    ctx->pc = 0x128a50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x128a54: 0x3e00008
    ctx->pc = 0x128A54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x128A58u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1288B8u: goto label_1288b8;
            case 0x1288C8u: goto label_1288c8;
            case 0x1288D8u: goto label_1288d8;
            case 0x128908u: goto label_128908;
            case 0x128988u: goto label_128988;
            case 0x1289A0u: goto label_1289a0;
            case 0x1289A8u: goto label_1289a8;
            case 0x1289B8u: goto label_1289b8;
            case 0x1289C8u: goto label_1289c8;
            case 0x128A30u: goto label_128a30;
            case 0x128A34u: goto label_128a34;
            case 0x128A38u: goto label_128a38;
            default: break;
        }
        return;
    }
    ctx->pc = 0x128A5Cu;
    // 0x128a5c: 0x0
    ctx->pc = 0x128a5cu;
    // NOP
}
