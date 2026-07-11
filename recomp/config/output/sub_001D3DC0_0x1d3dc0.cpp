#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001D3DC0
// Address: 0x1d3dc0 - 0x1d4ca0
void sub_001D3DC0_0x1d3dc0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1d3dc0u;

label_1d3dc0:
    // 0x1d3dc0: 0x27bdff40
    ctx->pc = 0x1d3dc0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x1d3dc4: 0x80102d
    ctx->pc = 0x1d3dc4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3dc8: 0xffbf0030
    ctx->pc = 0x1d3dc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1d3dcc: 0x27a40040
    ctx->pc = 0x1d3dccu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d3dd0: 0x7fb20020
    ctx->pc = 0x1d3dd0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d3dd4: 0xa0902d
    ctx->pc = 0x1d3dd4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3dd8: 0x7fb10010
    ctx->pc = 0x1d3dd8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d3ddc: 0x40282d
    ctx->pc = 0x1d3ddcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3de0: 0xc042bf0
    ctx->pc = 0x1D3DE0u;
    SET_GPR_U32(ctx, 31, 0x1D3DE8u);
    ctx->pc = 0x1D3DE4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    ctx->pc = 0x10AFC0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3DE8u; }
    }
    if (ctx->pc != 0x1D3DE8u) { return; }
    ctx->pc = 0x1D3DE8u;
    // 0x1d3de8: 0x3c050025
    ctx->pc = 0x1d3de8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d3dec: 0x27a40040
    ctx->pc = 0x1d3decu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d3df0: 0xc042aee
    ctx->pc = 0x1D3DF0u;
    SET_GPR_U32(ctx, 31, 0x1D3DF8u);
    ctx->pc = 0x1D3DF4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26296));
    ctx->pc = 0x10ABB8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010ABB8_0x10abb8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3DF8u; }
    }
    if (ctx->pc != 0x1D3DF8u) { return; }
    ctx->pc = 0x1D3DF8u;
    // 0x1d3df8: 0xc06acc4
    ctx->pc = 0x1D3DF8u;
    SET_GPR_U32(ctx, 31, 0x1D3E00u);
    ctx->pc = 0x1D3DFCu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 64));
    ctx->pc = 0x1AB310u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AB310_0x1ab310(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3E00u; }
    }
    if (ctx->pc != 0x1D3E00u) { return; }
    ctx->pc = 0x1D3E00u;
    // 0x1d3e00: 0x40282d
    ctx->pc = 0x1d3e00u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3e04: 0x4a00019
    ctx->pc = 0x1D3E04u;
    {
        const bool branch_taken_0x1d3e04 = (GPR_S32(ctx, 5) < 0);
        ctx->pc = 0x1D3E08u;
        SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
        if (branch_taken_0x1d3e04) {
            ctx->pc = 0x1D3E6Cu;
            goto label_1d3e6c;
        }
    }
    ctx->pc = 0x1D3E0Cu;
    // 0x1d3e0c: 0x8c31440c
    ctx->pc = 0x1d3e0cu;
    SET_GPR_U32(ctx, 17, READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d3e10: 0xc04a490
    ctx->pc = 0x1D3E10u;
    SET_GPR_U32(ctx, 31, 0x1D3E18u);
    ctx->pc = 0x1D3E14u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0x129240u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00129240_0x129240(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3E18u; }
    }
    if (ctx->pc != 0x1D3E18u) { return; }
    ctx->pc = 0x1D3E18u;
    // 0x1d3e18: 0x40802d
    ctx->pc = 0x1d3e18u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3e1c: 0x12000013
    ctx->pc = 0x1D3E1Cu;
    {
        const bool branch_taken_0x1d3e1c = (GPR_U32(ctx, 16) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D3E20u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1d3e1c) {
            ctx->pc = 0x1D3E6Cu;
            goto label_1d3e6c;
        }
    }
    ctx->pc = 0x1D3E24u;
    // 0x1d3e24: 0xc04a702
    ctx->pc = 0x1D3E24u;
    SET_GPR_U32(ctx, 31, 0x1D3E2Cu);
    ctx->pc = 0x129C08u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00129C08_0x129c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3E2Cu; }
    }
    if (ctx->pc != 0x1D3E2Cu) { return; }
    ctx->pc = 0x1D3E2Cu;
    // 0x1d3e2c: 0x40282d
    ctx->pc = 0x1d3e2cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3e30: 0x200202d
    ctx->pc = 0x1d3e30u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3e34: 0xc04a5e8
    ctx->pc = 0x1D3E34u;
    SET_GPR_U32(ctx, 31, 0x1D3E3Cu);
    ctx->pc = 0x1D3E38u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1297A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001297A0_0x1297a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3E3Cu; }
    }
    if (ctx->pc != 0x1D3E3Cu) { return; }
    ctx->pc = 0x1D3E3Cu;
label_1d3e3c:
    // 0x1d3e3c: 0xc04a752
    ctx->pc = 0x1D3E3Cu;
    SET_GPR_U32(ctx, 31, 0x1D3E44u);
    ctx->pc = 0x1D3E40u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x129D48u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00129D48_0x129d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3E44u; }
    }
    if (ctx->pc != 0x1D3E44u) { return; }
    ctx->pc = 0x1D3E44u;
    // 0x1d3e44: 0x24030003
    ctx->pc = 0x1d3e44u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 3));
    // 0x1d3e48: 0x0
    ctx->pc = 0x1d3e48u;
    // NOP
    // 0x1d3e4c: 0x0
    ctx->pc = 0x1d3e4cu;
    // NOP
    // 0x1d3e50: 0x1443fffa
    ctx->pc = 0x1D3E50u;
    {
        const bool branch_taken_0x1d3e50 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        if (branch_taken_0x1d3e50) {
            ctx->pc = 0x1D3E3Cu;
            goto label_1d3e3c;
        }
    }
    ctx->pc = 0x1D3E58u;
    // 0x1d3e58: 0xc04a4d4
    ctx->pc = 0x1D3E58u;
    SET_GPR_U32(ctx, 31, 0x1D3E60u);
    ctx->pc = 0x1D3E5Cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x129350u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00129350_0x129350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3E60u; }
    }
    if (ctx->pc != 0x1D3E60u) { return; }
    ctx->pc = 0x1D3E60u;
    // 0x1d3e60: 0x220202d
    ctx->pc = 0x1d3e60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3e64: 0xc06b1cc
    ctx->pc = 0x1D3E64u;
    SET_GPR_U32(ctx, 31, 0x1D3E6Cu);
    ctx->pc = 0x1D3E68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1AC730u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AC730_0x1ac730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3E6Cu; }
    }
    if (ctx->pc != 0x1D3E6Cu) { return; }
    ctx->pc = 0x1D3E6Cu;
label_1d3e6c:
    // 0x1d3e6c: 0xdfbf0030
    ctx->pc = 0x1d3e6cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d3e70: 0x7bb20020
    ctx->pc = 0x1d3e70u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d3e74: 0x7bb10010
    ctx->pc = 0x1d3e74u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d3e78: 0x7bb00000
    ctx->pc = 0x1d3e78u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d3e7c: 0x3e00008
    ctx->pc = 0x1D3E7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D3E80u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 192));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3DC0u: goto label_1d3dc0;
            case 0x1D3E3Cu: goto label_1d3e3c;
            case 0x1D3E6Cu: goto label_1d3e6c;
            case 0x1D3F00u: goto label_1d3f00;
            case 0x1D3F10u: goto label_1d3f10;
            case 0x1D3F48u: goto label_1d3f48;
            case 0x1D3F50u: goto label_1d3f50;
            case 0x1D3F54u: goto label_1d3f54;
            case 0x1D3FCCu: goto label_1d3fcc;
            case 0x1D3FECu: goto label_1d3fec;
            case 0x1D3FFCu: goto label_1d3ffc;
            case 0x1D400Cu: goto label_1d400c;
            case 0x1D407Cu: goto label_1d407c;
            case 0x1D409Cu: goto label_1d409c;
            case 0x1D40BCu: goto label_1d40bc;
            case 0x1D40E8u: goto label_1d40e8;
            case 0x1D4100u: goto label_1d4100;
            case 0x1D4114u: goto label_1d4114;
            case 0x1D415Cu: goto label_1d415c;
            case 0x1D4164u: goto label_1d4164;
            case 0x1D41ACu: goto label_1d41ac;
            case 0x1D41CCu: goto label_1d41cc;
            case 0x1D41D8u: goto label_1d41d8;
            case 0x1D4250u: goto label_1d4250;
            case 0x1D42A4u: goto label_1d42a4;
            case 0x1D42E0u: goto label_1d42e0;
            case 0x1D4308u: goto label_1d4308;
            case 0x1D4318u: goto label_1d4318;
            case 0x1D4368u: goto label_1d4368;
            case 0x1D4384u: goto label_1d4384;
            case 0x1D43C0u: goto label_1d43c0;
            case 0x1D43DCu: goto label_1d43dc;
            case 0x1D4430u: goto label_1d4430;
            case 0x1D446Cu: goto label_1d446c;
            case 0x1D4494u: goto label_1d4494;
            case 0x1D449Cu: goto label_1d449c;
            case 0x1D44F4u: goto label_1d44f4;
            case 0x1D4510u: goto label_1d4510;
            case 0x1D4548u: goto label_1d4548;
            case 0x1D4550u: goto label_1d4550;
            case 0x1D45A8u: goto label_1d45a8;
            case 0x1D45BCu: goto label_1d45bc;
            case 0x1D4678u: goto label_1d4678;
            case 0x1D46A0u: goto label_1d46a0;
            case 0x1D46B8u: goto label_1d46b8;
            case 0x1D46D4u: goto label_1d46d4;
            case 0x1D4790u: goto label_1d4790;
            case 0x1D47BCu: goto label_1d47bc;
            case 0x1D47E0u: goto label_1d47e0;
            case 0x1D47ECu: goto label_1d47ec;
            case 0x1D4814u: goto label_1d4814;
            case 0x1D4818u: goto label_1d4818;
            case 0x1D481Cu: goto label_1d481c;
            case 0x1D482Cu: goto label_1d482c;
            case 0x1D4830u: goto label_1d4830;
            case 0x1D483Cu: goto label_1d483c;
            case 0x1D4840u: goto label_1d4840;
            case 0x1D48F0u: goto label_1d48f0;
            case 0x1D4944u: goto label_1d4944;
            case 0x1D497Cu: goto label_1d497c;
            case 0x1D49B4u: goto label_1d49b4;
            case 0x1D4A3Cu: goto label_1d4a3c;
            case 0x1D4A70u: goto label_1d4a70;
            case 0x1D4AB8u: goto label_1d4ab8;
            case 0x1D4B30u: goto label_1d4b30;
            case 0x1D4B58u: goto label_1d4b58;
            case 0x1D4B94u: goto label_1d4b94;
            case 0x1D4BD8u: goto label_1d4bd8;
            case 0x1D4C18u: goto label_1d4c18;
            case 0x1D4C28u: goto label_1d4c28;
            case 0x1D4C70u: goto label_1d4c70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D3E84u;
    // 0x1d3e84: 0x0
    ctx->pc = 0x1d3e84u;
    // NOP
    // 0x1d3e88: 0x0
    ctx->pc = 0x1d3e88u;
    // NOP
    // 0x1d3e8c: 0x0
    ctx->pc = 0x1d3e8cu;
    // NOP
    // 0x1d3e90: 0x27bdff60
    ctx->pc = 0x1d3e90u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1d3e94: 0x3c030032
    ctx->pc = 0x1d3e94u;
    SET_GPR_U32(ctx, 3, ((uint32_t)50 << 16));
    // 0x1d3e98: 0xffbf0010
    ctx->pc = 0x1d3e98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d3e9c: 0x3c010032
    ctx->pc = 0x1d3e9cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d3ea0: 0x7fb00000
    ctx->pc = 0x1d3ea0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d3ea4: 0x8c304424
    ctx->pc = 0x1d3ea4u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 1), 17444)));
    // 0x1d3ea8: 0x3c010032
    ctx->pc = 0x1d3ea8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d3eac: 0x802243d7
    ctx->pc = 0x1d3eacu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d3eb0: 0x14400017
    ctx->pc = 0x1D3EB0u;
    {
        const bool branch_taken_0x1d3eb0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D3EB4u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 17344));
        if (branch_taken_0x1d3eb0) {
            ctx->pc = 0x1D3F10u;
            goto label_1d3f10;
        }
    }
    ctx->pc = 0x1D3EB8u;
    // 0x1d3eb8: 0x9467001a
    ctx->pc = 0x1d3eb8u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 26)));
    // 0x1d3ebc: 0x3c050025
    ctx->pc = 0x1d3ebcu;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d3ec0: 0x3c060025
    ctx->pc = 0x1d3ec0u;
    SET_GPR_U32(ctx, 6, ((uint32_t)37 << 16));
    // 0x1d3ec4: 0x27a40020
    ctx->pc = 0x1d3ec4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d3ec8: 0x24a566c0
    ctx->pc = 0x1d3ec8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26304));
    // 0x1d3ecc: 0xc042a0c
    ctx->pc = 0x1D3ECCu;
    SET_GPR_U32(ctx, 31, 0x1D3ED4u);
    ctx->pc = 0x1D3ED0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 26320));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3ED4u; }
    }
    if (ctx->pc != 0x1D3ED4u) { return; }
    ctx->pc = 0x1D3ED4u;
    // 0x1d3ed4: 0x200282d
    ctx->pc = 0x1d3ed4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3ed8: 0x27a40020
    ctx->pc = 0x1d3ed8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d3edc: 0x24060001
    ctx->pc = 0x1d3edcu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d3ee0: 0xc07323c
    ctx->pc = 0x1D3EE0u;
    SET_GPR_U32(ctx, 31, 0x1D3EE8u);
    ctx->pc = 0x1D3EE4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1CC8F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3EE8u; }
    }
    if (ctx->pc != 0x1D3EE8u) { return; }
    ctx->pc = 0x1D3EE8u;
    // 0x1d3ee8: 0x18400005
    ctx->pc = 0x1D3EE8u;
    {
        const bool branch_taken_0x1d3ee8 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x1d3ee8) {
            ctx->pc = 0x1D3F00u;
            goto label_1d3f00;
        }
    }
    ctx->pc = 0x1D3EF0u;
    // 0x1d3ef0: 0xc1a3098
    ctx->pc = 0x1D3EF0u;
    SET_GPR_U32(ctx, 31, 0x1D3EF8u);
    ctx->pc = 0x68C260u;
    {
        auto targetFn = runtime->lookupFunction(0x68C260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3EF8u; }
        if (ctx->pc != 0x1D3EF8u) { return; }
    }
    ctx->pc = 0x1D3EF8u;
    // 0x1d3ef8: 0x10000016
    ctx->pc = 0x1D3EF8u;
    {
        const bool branch_taken_0x1d3ef8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D3EFCu;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        if (branch_taken_0x1d3ef8) {
            ctx->pc = 0x1D3F54u;
            goto label_1d3f54;
        }
    }
    ctx->pc = 0x1D3F00u;
label_1d3f00:
    // 0x1d3f00: 0xc1a3068
    ctx->pc = 0x1D3F00u;
    SET_GPR_U32(ctx, 31, 0x1D3F08u);
    ctx->pc = 0x68C1A0u;
    {
        auto targetFn = runtime->lookupFunction(0x68C1A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3F08u; }
        if (ctx->pc != 0x1D3F08u) { return; }
    }
    ctx->pc = 0x1D3F08u;
    // 0x1d3f08: 0x10000011
    ctx->pc = 0x1D3F08u;
    {
        const bool branch_taken_0x1d3f08 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1d3f08) {
            ctx->pc = 0x1D3F50u;
            goto label_1d3f50;
        }
    }
    ctx->pc = 0x1D3F10u;
label_1d3f10:
    // 0x1d3f10: 0x9466001a
    ctx->pc = 0x1d3f10u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 26)));
    // 0x1d3f14: 0x3c050025
    ctx->pc = 0x1d3f14u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d3f18: 0x27a40020
    ctx->pc = 0x1d3f18u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d3f1c: 0xc042a0c
    ctx->pc = 0x1D3F1Cu;
    SET_GPR_U32(ctx, 31, 0x1D3F24u);
    ctx->pc = 0x1D3F20u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26344));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3F24u; }
    }
    if (ctx->pc != 0x1D3F24u) { return; }
    ctx->pc = 0x1D3F24u;
    // 0x1d3f24: 0x200282d
    ctx->pc = 0x1d3f24u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3f28: 0xc06a8f8
    ctx->pc = 0x1D3F28u;
    SET_GPR_U32(ctx, 31, 0x1D3F30u);
    ctx->pc = 0x1D3F2Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x1AA3E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA3E0_0x1aa3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3F30u; }
    }
    if (ctx->pc != 0x1D3F30u) { return; }
    ctx->pc = 0x1D3F30u;
    // 0x1d3f30: 0x10400005
    ctx->pc = 0x1D3F30u;
    {
        const bool branch_taken_0x1d3f30 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1d3f30) {
            ctx->pc = 0x1D3F48u;
            goto label_1d3f48;
        }
    }
    ctx->pc = 0x1D3F38u;
    // 0x1d3f38: 0xc1a3098
    ctx->pc = 0x1D3F38u;
    SET_GPR_U32(ctx, 31, 0x1D3F40u);
    ctx->pc = 0x68C260u;
    {
        auto targetFn = runtime->lookupFunction(0x68C260u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3F40u; }
        if (ctx->pc != 0x1D3F40u) { return; }
    }
    ctx->pc = 0x1D3F40u;
    // 0x1d3f40: 0x10000003
    ctx->pc = 0x1D3F40u;
    {
        const bool branch_taken_0x1d3f40 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1d3f40) {
            ctx->pc = 0x1D3F50u;
            goto label_1d3f50;
        }
    }
    ctx->pc = 0x1D3F48u;
label_1d3f48:
    // 0x1d3f48: 0xc1a3068
    ctx->pc = 0x1D3F48u;
    SET_GPR_U32(ctx, 31, 0x1D3F50u);
    ctx->pc = 0x68C1A0u;
    {
        auto targetFn = runtime->lookupFunction(0x68C1A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3F50u; }
        if (ctx->pc != 0x1D3F50u) { return; }
    }
    ctx->pc = 0x1D3F50u;
label_1d3f50:
    // 0x1d3f50: 0xdfbf0010
    ctx->pc = 0x1d3f50u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1d3f54:
    // 0x1d3f54: 0x7bb00000
    ctx->pc = 0x1d3f54u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d3f58: 0x3e00008
    ctx->pc = 0x1D3F58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D3F5Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 160));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3DC0u: goto label_1d3dc0;
            case 0x1D3E3Cu: goto label_1d3e3c;
            case 0x1D3E6Cu: goto label_1d3e6c;
            case 0x1D3F00u: goto label_1d3f00;
            case 0x1D3F10u: goto label_1d3f10;
            case 0x1D3F48u: goto label_1d3f48;
            case 0x1D3F50u: goto label_1d3f50;
            case 0x1D3F54u: goto label_1d3f54;
            case 0x1D3FCCu: goto label_1d3fcc;
            case 0x1D3FECu: goto label_1d3fec;
            case 0x1D3FFCu: goto label_1d3ffc;
            case 0x1D400Cu: goto label_1d400c;
            case 0x1D407Cu: goto label_1d407c;
            case 0x1D409Cu: goto label_1d409c;
            case 0x1D40BCu: goto label_1d40bc;
            case 0x1D40E8u: goto label_1d40e8;
            case 0x1D4100u: goto label_1d4100;
            case 0x1D4114u: goto label_1d4114;
            case 0x1D415Cu: goto label_1d415c;
            case 0x1D4164u: goto label_1d4164;
            case 0x1D41ACu: goto label_1d41ac;
            case 0x1D41CCu: goto label_1d41cc;
            case 0x1D41D8u: goto label_1d41d8;
            case 0x1D4250u: goto label_1d4250;
            case 0x1D42A4u: goto label_1d42a4;
            case 0x1D42E0u: goto label_1d42e0;
            case 0x1D4308u: goto label_1d4308;
            case 0x1D4318u: goto label_1d4318;
            case 0x1D4368u: goto label_1d4368;
            case 0x1D4384u: goto label_1d4384;
            case 0x1D43C0u: goto label_1d43c0;
            case 0x1D43DCu: goto label_1d43dc;
            case 0x1D4430u: goto label_1d4430;
            case 0x1D446Cu: goto label_1d446c;
            case 0x1D4494u: goto label_1d4494;
            case 0x1D449Cu: goto label_1d449c;
            case 0x1D44F4u: goto label_1d44f4;
            case 0x1D4510u: goto label_1d4510;
            case 0x1D4548u: goto label_1d4548;
            case 0x1D4550u: goto label_1d4550;
            case 0x1D45A8u: goto label_1d45a8;
            case 0x1D45BCu: goto label_1d45bc;
            case 0x1D4678u: goto label_1d4678;
            case 0x1D46A0u: goto label_1d46a0;
            case 0x1D46B8u: goto label_1d46b8;
            case 0x1D46D4u: goto label_1d46d4;
            case 0x1D4790u: goto label_1d4790;
            case 0x1D47BCu: goto label_1d47bc;
            case 0x1D47E0u: goto label_1d47e0;
            case 0x1D47ECu: goto label_1d47ec;
            case 0x1D4814u: goto label_1d4814;
            case 0x1D4818u: goto label_1d4818;
            case 0x1D481Cu: goto label_1d481c;
            case 0x1D482Cu: goto label_1d482c;
            case 0x1D4830u: goto label_1d4830;
            case 0x1D483Cu: goto label_1d483c;
            case 0x1D4840u: goto label_1d4840;
            case 0x1D48F0u: goto label_1d48f0;
            case 0x1D4944u: goto label_1d4944;
            case 0x1D497Cu: goto label_1d497c;
            case 0x1D49B4u: goto label_1d49b4;
            case 0x1D4A3Cu: goto label_1d4a3c;
            case 0x1D4A70u: goto label_1d4a70;
            case 0x1D4AB8u: goto label_1d4ab8;
            case 0x1D4B30u: goto label_1d4b30;
            case 0x1D4B58u: goto label_1d4b58;
            case 0x1D4B94u: goto label_1d4b94;
            case 0x1D4BD8u: goto label_1d4bd8;
            case 0x1D4C18u: goto label_1d4c18;
            case 0x1D4C28u: goto label_1d4c28;
            case 0x1D4C70u: goto label_1d4c70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D3F60u;
    // 0x1d3f60: 0x27bdff50
    ctx->pc = 0x1d3f60u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x1d3f64: 0xffbf0020
    ctx->pc = 0x1d3f64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d3f68: 0x7fb10010
    ctx->pc = 0x1d3f68u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d3f6c: 0x3c110032
    ctx->pc = 0x1d3f6cu;
    SET_GPR_U32(ctx, 17, ((uint32_t)50 << 16));
    // 0x1d3f70: 0x7fb00000
    ctx->pc = 0x1d3f70u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d3f74: 0xc06c0b4
    ctx->pc = 0x1D3F74u;
    SET_GPR_U32(ctx, 31, 0x1D3F7Cu);
    ctx->pc = 0x1D3F78u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 17344));
    ctx->pc = 0x1B02D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001B02D0_0x1b02d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3F7Cu; }
    }
    if (ctx->pc != 0x1D3F7Cu) { return; }
    ctx->pc = 0x1D3F7Cu;
    // 0x1d3f7c: 0x10400023
    ctx->pc = 0x1D3F7Cu;
    {
        const bool branch_taken_0x1d3f7c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D3F80u;
        SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
        if (branch_taken_0x1d3f7c) {
            ctx->pc = 0x1D400Cu;
            goto label_1d400c;
        }
    }
    ctx->pc = 0x1D3F84u;
    // 0x1d3f84: 0x3c100084
    ctx->pc = 0x1d3f84u;
    SET_GPR_U32(ctx, 16, ((uint32_t)132 << 16));
    // 0x1d3f88: 0x802243d7
    ctx->pc = 0x1d3f88u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d3f8c: 0x1440000f
    ctx->pc = 0x1D3F8Cu;
    {
        const bool branch_taken_0x1d3f8c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D3F90u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 14208));
        if (branch_taken_0x1d3f8c) {
            ctx->pc = 0x1D3FCCu;
            goto label_1d3fcc;
        }
    }
    ctx->pc = 0x1D3F94u;
    // 0x1d3f94: 0x9627001a
    ctx->pc = 0x1d3f94u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 26)));
    // 0x1d3f98: 0x3c050025
    ctx->pc = 0x1d3f98u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d3f9c: 0x3c060025
    ctx->pc = 0x1d3f9cu;
    SET_GPR_U32(ctx, 6, ((uint32_t)37 << 16));
    // 0x1d3fa0: 0x27a40030
    ctx->pc = 0x1d3fa0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d3fa4: 0x24a566f8
    ctx->pc = 0x1d3fa4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26360));
    // 0x1d3fa8: 0xc042a0c
    ctx->pc = 0x1D3FA8u;
    SET_GPR_U32(ctx, 31, 0x1D3FB0u);
    ctx->pc = 0x1D3FACu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 26384));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3FB0u; }
    }
    if (ctx->pc != 0x1D3FB0u) { return; }
    ctx->pc = 0x1D3FB0u;
    // 0x1d3fb0: 0x27a40030
    ctx->pc = 0x1d3fb0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d3fb4: 0x200282d
    ctx->pc = 0x1d3fb4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d3fb8: 0x24060001
    ctx->pc = 0x1d3fb8u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d3fbc: 0xc07323c
    ctx->pc = 0x1D3FBCu;
    SET_GPR_U32(ctx, 31, 0x1D3FC4u);
    ctx->pc = 0x1D3FC0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1CC8F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3FC4u; }
    }
    if (ctx->pc != 0x1D3FC4u) { return; }
    ctx->pc = 0x1D3FC4u;
    // 0x1d3fc4: 0x10000009
    ctx->pc = 0x1D3FC4u;
    {
        const bool branch_taken_0x1d3fc4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1d3fc4) {
            ctx->pc = 0x1D3FECu;
            goto label_1d3fec;
        }
    }
    ctx->pc = 0x1D3FCCu;
label_1d3fcc:
    // 0x1d3fcc: 0x9626001a
    ctx->pc = 0x1d3fccu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 26)));
    // 0x1d3fd0: 0x3c050025
    ctx->pc = 0x1d3fd0u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d3fd4: 0x27a40030
    ctx->pc = 0x1d3fd4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d3fd8: 0xc042a0c
    ctx->pc = 0x1D3FD8u;
    SET_GPR_U32(ctx, 31, 0x1D3FE0u);
    ctx->pc = 0x1D3FDCu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26408));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3FE0u; }
    }
    if (ctx->pc != 0x1D3FE0u) { return; }
    ctx->pc = 0x1D3FE0u;
    // 0x1d3fe0: 0x27a40030
    ctx->pc = 0x1d3fe0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 48));
    // 0x1d3fe4: 0xc06a8f8
    ctx->pc = 0x1D3FE4u;
    SET_GPR_U32(ctx, 31, 0x1D3FECu);
    ctx->pc = 0x1D3FE8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1AA3E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA3E0_0x1aa3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D3FECu; }
    }
    if (ctx->pc != 0x1D3FECu) { return; }
    ctx->pc = 0x1D3FECu;
label_1d3fec:
    // 0x1d3fec: 0x1c400003
    ctx->pc = 0x1D3FECu;
    {
        const bool branch_taken_0x1d3fec = (GPR_S32(ctx, 2) > 0);
        if (branch_taken_0x1d3fec) {
            ctx->pc = 0x1D3FFCu;
            goto label_1d3ffc;
        }
    }
    ctx->pc = 0x1D3FF4u;
    // 0x1d3ff4: 0x10000005
    ctx->pc = 0x1D3FF4u;
    {
        const bool branch_taken_0x1d3ff4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D3FF8u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        if (branch_taken_0x1d3ff4) {
            ctx->pc = 0x1D400Cu;
            goto label_1d400c;
        }
    }
    ctx->pc = 0x1D3FFCu;
label_1d3ffc:
    // 0x1d3ffc: 0xc2058fc
    ctx->pc = 0x1D3FFCu;
    SET_GPR_U32(ctx, 31, 0x1D4004u);
    ctx->pc = 0x8163F0u;
    {
        auto targetFn = runtime->lookupFunction(0x8163F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4004u; }
        if (ctx->pc != 0x1D4004u) { return; }
    }
    ctx->pc = 0x1D4004u;
    // 0x1d4004: 0xc20579c
    ctx->pc = 0x1D4004u;
    SET_GPR_U32(ctx, 31, 0x1D400Cu);
    ctx->pc = 0x1D4008u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x815E70u;
    {
        auto targetFn = runtime->lookupFunction(0x815E70u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D400Cu; }
        if (ctx->pc != 0x1D400Cu) { return; }
    }
    ctx->pc = 0x1D400Cu;
label_1d400c:
    // 0x1d400c: 0xdfbf0020
    ctx->pc = 0x1d400cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d4010: 0x7bb10010
    ctx->pc = 0x1d4010u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d4014: 0x7bb00000
    ctx->pc = 0x1d4014u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4018: 0x3e00008
    ctx->pc = 0x1D4018u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D401Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 176));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3DC0u: goto label_1d3dc0;
            case 0x1D3E3Cu: goto label_1d3e3c;
            case 0x1D3E6Cu: goto label_1d3e6c;
            case 0x1D3F00u: goto label_1d3f00;
            case 0x1D3F10u: goto label_1d3f10;
            case 0x1D3F48u: goto label_1d3f48;
            case 0x1D3F50u: goto label_1d3f50;
            case 0x1D3F54u: goto label_1d3f54;
            case 0x1D3FCCu: goto label_1d3fcc;
            case 0x1D3FECu: goto label_1d3fec;
            case 0x1D3FFCu: goto label_1d3ffc;
            case 0x1D400Cu: goto label_1d400c;
            case 0x1D407Cu: goto label_1d407c;
            case 0x1D409Cu: goto label_1d409c;
            case 0x1D40BCu: goto label_1d40bc;
            case 0x1D40E8u: goto label_1d40e8;
            case 0x1D4100u: goto label_1d4100;
            case 0x1D4114u: goto label_1d4114;
            case 0x1D415Cu: goto label_1d415c;
            case 0x1D4164u: goto label_1d4164;
            case 0x1D41ACu: goto label_1d41ac;
            case 0x1D41CCu: goto label_1d41cc;
            case 0x1D41D8u: goto label_1d41d8;
            case 0x1D4250u: goto label_1d4250;
            case 0x1D42A4u: goto label_1d42a4;
            case 0x1D42E0u: goto label_1d42e0;
            case 0x1D4308u: goto label_1d4308;
            case 0x1D4318u: goto label_1d4318;
            case 0x1D4368u: goto label_1d4368;
            case 0x1D4384u: goto label_1d4384;
            case 0x1D43C0u: goto label_1d43c0;
            case 0x1D43DCu: goto label_1d43dc;
            case 0x1D4430u: goto label_1d4430;
            case 0x1D446Cu: goto label_1d446c;
            case 0x1D4494u: goto label_1d4494;
            case 0x1D449Cu: goto label_1d449c;
            case 0x1D44F4u: goto label_1d44f4;
            case 0x1D4510u: goto label_1d4510;
            case 0x1D4548u: goto label_1d4548;
            case 0x1D4550u: goto label_1d4550;
            case 0x1D45A8u: goto label_1d45a8;
            case 0x1D45BCu: goto label_1d45bc;
            case 0x1D4678u: goto label_1d4678;
            case 0x1D46A0u: goto label_1d46a0;
            case 0x1D46B8u: goto label_1d46b8;
            case 0x1D46D4u: goto label_1d46d4;
            case 0x1D4790u: goto label_1d4790;
            case 0x1D47BCu: goto label_1d47bc;
            case 0x1D47E0u: goto label_1d47e0;
            case 0x1D47ECu: goto label_1d47ec;
            case 0x1D4814u: goto label_1d4814;
            case 0x1D4818u: goto label_1d4818;
            case 0x1D481Cu: goto label_1d481c;
            case 0x1D482Cu: goto label_1d482c;
            case 0x1D4830u: goto label_1d4830;
            case 0x1D483Cu: goto label_1d483c;
            case 0x1D4840u: goto label_1d4840;
            case 0x1D48F0u: goto label_1d48f0;
            case 0x1D4944u: goto label_1d4944;
            case 0x1D497Cu: goto label_1d497c;
            case 0x1D49B4u: goto label_1d49b4;
            case 0x1D4A3Cu: goto label_1d4a3c;
            case 0x1D4A70u: goto label_1d4a70;
            case 0x1D4AB8u: goto label_1d4ab8;
            case 0x1D4B30u: goto label_1d4b30;
            case 0x1D4B58u: goto label_1d4b58;
            case 0x1D4B94u: goto label_1d4b94;
            case 0x1D4BD8u: goto label_1d4bd8;
            case 0x1D4C18u: goto label_1d4c18;
            case 0x1D4C28u: goto label_1d4c28;
            case 0x1D4C70u: goto label_1d4c70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4020u;
    // 0x1d4020: 0x27bdff60
    ctx->pc = 0x1d4020u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1d4024: 0x3c030032
    ctx->pc = 0x1d4024u;
    SET_GPR_U32(ctx, 3, ((uint32_t)50 << 16));
    // 0x1d4028: 0xffbf0010
    ctx->pc = 0x1d4028u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d402c: 0x3c010032
    ctx->pc = 0x1d402cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d4030: 0x7fb00000
    ctx->pc = 0x1d4030u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d4034: 0x8c30443c
    ctx->pc = 0x1d4034u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 1), 17468)));
    // 0x1d4038: 0x3c010032
    ctx->pc = 0x1d4038u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d403c: 0x802243d7
    ctx->pc = 0x1d403cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d4040: 0x1440001e
    ctx->pc = 0x1D4040u;
    {
        const bool branch_taken_0x1d4040 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D4044u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 17344));
        if (branch_taken_0x1d4040) {
            ctx->pc = 0x1D40BCu;
            goto label_1d40bc;
        }
    }
    ctx->pc = 0x1D4048u;
    // 0x1d4048: 0x3c010032
    ctx->pc = 0x1d4048u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d404c: 0x902243fd
    ctx->pc = 0x1d404cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17405)));
    // 0x1d4050: 0x1440000a
    ctx->pc = 0x1D4050u;
    {
        const bool branch_taken_0x1d4050 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1d4050) {
            ctx->pc = 0x1D407Cu;
            goto label_1d407c;
        }
    }
    ctx->pc = 0x1D4058u;
    // 0x1d4058: 0x9467001a
    ctx->pc = 0x1d4058u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 26)));
    // 0x1d405c: 0x3c050025
    ctx->pc = 0x1d405cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d4060: 0x3c060025
    ctx->pc = 0x1d4060u;
    SET_GPR_U32(ctx, 6, ((uint32_t)37 << 16));
    // 0x1d4064: 0x27a40020
    ctx->pc = 0x1d4064u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d4068: 0x24a56738
    ctx->pc = 0x1d4068u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26424));
    // 0x1d406c: 0xc042a0c
    ctx->pc = 0x1D406Cu;
    SET_GPR_U32(ctx, 31, 0x1D4074u);
    ctx->pc = 0x1D4070u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 26448));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4074u; }
    }
    if (ctx->pc != 0x1D4074u) { return; }
    ctx->pc = 0x1D4074u;
    // 0x1d4074: 0x10000009
    ctx->pc = 0x1D4074u;
    {
        const bool branch_taken_0x1d4074 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D4078u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
        if (branch_taken_0x1d4074) {
            ctx->pc = 0x1D409Cu;
            goto label_1d409c;
        }
    }
    ctx->pc = 0x1D407Cu;
label_1d407c:
    // 0x1d407c: 0x9467001a
    ctx->pc = 0x1d407cu;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 26)));
    // 0x1d4080: 0x3c050025
    ctx->pc = 0x1d4080u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d4084: 0x3c060025
    ctx->pc = 0x1d4084u;
    SET_GPR_U32(ctx, 6, ((uint32_t)37 << 16));
    // 0x1d4088: 0x27a40020
    ctx->pc = 0x1d4088u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d408c: 0x24a56768
    ctx->pc = 0x1d408cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26472));
    // 0x1d4090: 0xc042a0c
    ctx->pc = 0x1D4090u;
    SET_GPR_U32(ctx, 31, 0x1D4098u);
    ctx->pc = 0x1D4094u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 26448));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4098u; }
    }
    if (ctx->pc != 0x1D4098u) { return; }
    ctx->pc = 0x1D4098u;
    // 0x1d4098: 0x27a40020
    ctx->pc = 0x1d4098u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
label_1d409c:
    // 0x1d409c: 0x200282d
    ctx->pc = 0x1d409cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d40a0: 0x24060001
    ctx->pc = 0x1d40a0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d40a4: 0xc07323c
    ctx->pc = 0x1D40A4u;
    SET_GPR_U32(ctx, 31, 0x1D40ACu);
    ctx->pc = 0x1D40A8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1CC8F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D40ACu; }
    }
    if (ctx->pc != 0x1D40ACu) { return; }
    ctx->pc = 0x1D40ACu;
    // 0x1d40ac: 0x1c400019
    ctx->pc = 0x1D40ACu;
    {
        const bool branch_taken_0x1d40ac = (GPR_S32(ctx, 2) > 0);
        if (branch_taken_0x1d40ac) {
            ctx->pc = 0x1D4114u;
            goto label_1d4114;
        }
    }
    ctx->pc = 0x1D40B4u;
    // 0x1d40b4: 0x10000017
    ctx->pc = 0x1D40B4u;
    {
        const bool branch_taken_0x1d40b4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D40B8u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
        if (branch_taken_0x1d40b4) {
            ctx->pc = 0x1D4114u;
            goto label_1d4114;
        }
    }
    ctx->pc = 0x1D40BCu;
label_1d40bc:
    // 0x1d40bc: 0x3c010032
    ctx->pc = 0x1d40bcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d40c0: 0x902243fd
    ctx->pc = 0x1d40c0u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 17405)));
    // 0x1d40c4: 0x14400008
    ctx->pc = 0x1D40C4u;
    {
        const bool branch_taken_0x1d40c4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1d40c4) {
            ctx->pc = 0x1D40E8u;
            goto label_1d40e8;
        }
    }
    ctx->pc = 0x1D40CCu;
    // 0x1d40cc: 0x9466001a
    ctx->pc = 0x1d40ccu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 26)));
    // 0x1d40d0: 0x3c050025
    ctx->pc = 0x1d40d0u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d40d4: 0x27a40020
    ctx->pc = 0x1d40d4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d40d8: 0xc042a0c
    ctx->pc = 0x1D40D8u;
    SET_GPR_U32(ctx, 31, 0x1D40E0u);
    ctx->pc = 0x1D40DCu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26488));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D40E0u; }
    }
    if (ctx->pc != 0x1D40E0u) { return; }
    ctx->pc = 0x1D40E0u;
    // 0x1d40e0: 0x10000007
    ctx->pc = 0x1D40E0u;
    {
        const bool branch_taken_0x1d40e0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D40E4u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
        if (branch_taken_0x1d40e0) {
            ctx->pc = 0x1D4100u;
            goto label_1d4100;
        }
    }
    ctx->pc = 0x1D40E8u;
label_1d40e8:
    // 0x1d40e8: 0x9466001a
    ctx->pc = 0x1d40e8u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 3), 26)));
    // 0x1d40ec: 0x3c050025
    ctx->pc = 0x1d40ecu;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d40f0: 0x27a40020
    ctx->pc = 0x1d40f0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d40f4: 0xc042a0c
    ctx->pc = 0x1D40F4u;
    SET_GPR_U32(ctx, 31, 0x1D40FCu);
    ctx->pc = 0x1D40F8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26504));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D40FCu; }
    }
    if (ctx->pc != 0x1D40FCu) { return; }
    ctx->pc = 0x1D40FCu;
    // 0x1d40fc: 0x27a40020
    ctx->pc = 0x1d40fcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
label_1d4100:
    // 0x1d4100: 0xc06a8f8
    ctx->pc = 0x1D4100u;
    SET_GPR_U32(ctx, 31, 0x1D4108u);
    ctx->pc = 0x1D4104u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1AA3E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA3E0_0x1aa3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4108u; }
    }
    if (ctx->pc != 0x1D4108u) { return; }
    ctx->pc = 0x1D4108u;
    // 0x1d4108: 0x1c400002
    ctx->pc = 0x1D4108u;
    {
        const bool branch_taken_0x1d4108 = (GPR_S32(ctx, 2) > 0);
        if (branch_taken_0x1d4108) {
            ctx->pc = 0x1D4114u;
            goto label_1d4114;
        }
    }
    ctx->pc = 0x1D4110u;
    // 0x1d4110: 0xae000000
    ctx->pc = 0x1d4110u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
label_1d4114:
    // 0x1d4114: 0xdfbf0010
    ctx->pc = 0x1d4114u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d4118: 0x7bb00000
    ctx->pc = 0x1d4118u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d411c: 0x3e00008
    ctx->pc = 0x1D411Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4120u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 160));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3DC0u: goto label_1d3dc0;
            case 0x1D3E3Cu: goto label_1d3e3c;
            case 0x1D3E6Cu: goto label_1d3e6c;
            case 0x1D3F00u: goto label_1d3f00;
            case 0x1D3F10u: goto label_1d3f10;
            case 0x1D3F48u: goto label_1d3f48;
            case 0x1D3F50u: goto label_1d3f50;
            case 0x1D3F54u: goto label_1d3f54;
            case 0x1D3FCCu: goto label_1d3fcc;
            case 0x1D3FECu: goto label_1d3fec;
            case 0x1D3FFCu: goto label_1d3ffc;
            case 0x1D400Cu: goto label_1d400c;
            case 0x1D407Cu: goto label_1d407c;
            case 0x1D409Cu: goto label_1d409c;
            case 0x1D40BCu: goto label_1d40bc;
            case 0x1D40E8u: goto label_1d40e8;
            case 0x1D4100u: goto label_1d4100;
            case 0x1D4114u: goto label_1d4114;
            case 0x1D415Cu: goto label_1d415c;
            case 0x1D4164u: goto label_1d4164;
            case 0x1D41ACu: goto label_1d41ac;
            case 0x1D41CCu: goto label_1d41cc;
            case 0x1D41D8u: goto label_1d41d8;
            case 0x1D4250u: goto label_1d4250;
            case 0x1D42A4u: goto label_1d42a4;
            case 0x1D42E0u: goto label_1d42e0;
            case 0x1D4308u: goto label_1d4308;
            case 0x1D4318u: goto label_1d4318;
            case 0x1D4368u: goto label_1d4368;
            case 0x1D4384u: goto label_1d4384;
            case 0x1D43C0u: goto label_1d43c0;
            case 0x1D43DCu: goto label_1d43dc;
            case 0x1D4430u: goto label_1d4430;
            case 0x1D446Cu: goto label_1d446c;
            case 0x1D4494u: goto label_1d4494;
            case 0x1D449Cu: goto label_1d449c;
            case 0x1D44F4u: goto label_1d44f4;
            case 0x1D4510u: goto label_1d4510;
            case 0x1D4548u: goto label_1d4548;
            case 0x1D4550u: goto label_1d4550;
            case 0x1D45A8u: goto label_1d45a8;
            case 0x1D45BCu: goto label_1d45bc;
            case 0x1D4678u: goto label_1d4678;
            case 0x1D46A0u: goto label_1d46a0;
            case 0x1D46B8u: goto label_1d46b8;
            case 0x1D46D4u: goto label_1d46d4;
            case 0x1D4790u: goto label_1d4790;
            case 0x1D47BCu: goto label_1d47bc;
            case 0x1D47E0u: goto label_1d47e0;
            case 0x1D47ECu: goto label_1d47ec;
            case 0x1D4814u: goto label_1d4814;
            case 0x1D4818u: goto label_1d4818;
            case 0x1D481Cu: goto label_1d481c;
            case 0x1D482Cu: goto label_1d482c;
            case 0x1D4830u: goto label_1d4830;
            case 0x1D483Cu: goto label_1d483c;
            case 0x1D4840u: goto label_1d4840;
            case 0x1D48F0u: goto label_1d48f0;
            case 0x1D4944u: goto label_1d4944;
            case 0x1D497Cu: goto label_1d497c;
            case 0x1D49B4u: goto label_1d49b4;
            case 0x1D4A3Cu: goto label_1d4a3c;
            case 0x1D4A70u: goto label_1d4a70;
            case 0x1D4AB8u: goto label_1d4ab8;
            case 0x1D4B30u: goto label_1d4b30;
            case 0x1D4B58u: goto label_1d4b58;
            case 0x1D4B94u: goto label_1d4b94;
            case 0x1D4BD8u: goto label_1d4bd8;
            case 0x1D4C18u: goto label_1d4c18;
            case 0x1D4C28u: goto label_1d4c28;
            case 0x1D4C70u: goto label_1d4c70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4124u;
    // 0x1d4124: 0x0
    ctx->pc = 0x1d4124u;
    // NOP
    // 0x1d4128: 0x0
    ctx->pc = 0x1d4128u;
    // NOP
    // 0x1d412c: 0x0
    ctx->pc = 0x1d412cu;
    // NOP
    // 0x1d4130: 0x27bdff60
    ctx->pc = 0x1d4130u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1d4134: 0x3c050032
    ctx->pc = 0x1d4134u;
    SET_GPR_U32(ctx, 5, ((uint32_t)50 << 16));
    // 0x1d4138: 0xffbf0010
    ctx->pc = 0x1d4138u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d413c: 0x24a543c0
    ctx->pc = 0x1d413cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 17344));
    // 0x1d4140: 0x10800006
    ctx->pc = 0x1D4140u;
    {
        const bool branch_taken_0x1d4140 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D4144u;
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        if (branch_taken_0x1d4140) {
            ctx->pc = 0x1D415Cu;
            goto label_1d415c;
        }
    }
    ctx->pc = 0x1D4148u;
    // 0x1d4148: 0x3c010032
    ctx->pc = 0x1d4148u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d414c: 0x3c020001
    ctx->pc = 0x1d414cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)1 << 16));
    // 0x1d4150: 0x8c23442c
    ctx->pc = 0x1d4150u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 17452)));
    // 0x1d4154: 0x10000003
    ctx->pc = 0x1D4154u;
    {
        const bool branch_taken_0x1d4154 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D4158u;
        SET_GPR_U32(ctx, 16, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        if (branch_taken_0x1d4154) {
            ctx->pc = 0x1D4164u;
            goto label_1d4164;
        }
    }
    ctx->pc = 0x1D415Cu;
label_1d415c:
    // 0x1d415c: 0x3c010032
    ctx->pc = 0x1d415cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d4160: 0x8c304438
    ctx->pc = 0x1d4160u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 1), 17464)));
label_1d4164:
    // 0x1d4164: 0x3c010032
    ctx->pc = 0x1d4164u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d4168: 0x802243d7
    ctx->pc = 0x1d4168u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d416c: 0x1440000f
    ctx->pc = 0x1D416Cu;
    {
        const bool branch_taken_0x1d416c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1d416c) {
            ctx->pc = 0x1D41ACu;
            goto label_1d41ac;
        }
    }
    ctx->pc = 0x1D4174u;
    // 0x1d4174: 0x94a7001a
    ctx->pc = 0x1d4174u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 26)));
    // 0x1d4178: 0x3c060025
    ctx->pc = 0x1d4178u;
    SET_GPR_U32(ctx, 6, ((uint32_t)37 << 16));
    // 0x1d417c: 0x27a40020
    ctx->pc = 0x1d417cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d4180: 0x24c667a8
    ctx->pc = 0x1d4180u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 26536));
    // 0x1d4184: 0x3c050025
    ctx->pc = 0x1d4184u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d4188: 0xc042a0c
    ctx->pc = 0x1D4188u;
    SET_GPR_U32(ctx, 31, 0x1D4190u);
    ctx->pc = 0x1D418Cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26520));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4190u; }
    }
    if (ctx->pc != 0x1D4190u) { return; }
    ctx->pc = 0x1D4190u;
    // 0x1d4190: 0x27a40020
    ctx->pc = 0x1d4190u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d4194: 0x200282d
    ctx->pc = 0x1d4194u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4198: 0x24060001
    ctx->pc = 0x1d4198u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d419c: 0xc07323c
    ctx->pc = 0x1D419Cu;
    SET_GPR_U32(ctx, 31, 0x1D41A4u);
    ctx->pc = 0x1D41A0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1CC8F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D41A4u; }
    }
    if (ctx->pc != 0x1D41A4u) { return; }
    ctx->pc = 0x1D41A4u;
    // 0x1d41a4: 0x10000009
    ctx->pc = 0x1D41A4u;
    {
        const bool branch_taken_0x1d41a4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1d41a4) {
            ctx->pc = 0x1D41CCu;
            goto label_1d41cc;
        }
    }
    ctx->pc = 0x1D41ACu;
label_1d41ac:
    // 0x1d41ac: 0x94a6001a
    ctx->pc = 0x1d41acu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 26)));
    // 0x1d41b0: 0x27a40020
    ctx->pc = 0x1d41b0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d41b4: 0x3c050025
    ctx->pc = 0x1d41b4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d41b8: 0xc042a0c
    ctx->pc = 0x1D41B8u;
    SET_GPR_U32(ctx, 31, 0x1D41C0u);
    ctx->pc = 0x1D41BCu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26552));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D41C0u; }
    }
    if (ctx->pc != 0x1D41C0u) { return; }
    ctx->pc = 0x1D41C0u;
    // 0x1d41c0: 0x27a40020
    ctx->pc = 0x1d41c0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d41c4: 0xc06a8f8
    ctx->pc = 0x1D41C4u;
    SET_GPR_U32(ctx, 31, 0x1D41CCu);
    ctx->pc = 0x1D41C8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1AA3E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA3E0_0x1aa3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D41CCu; }
    }
    if (ctx->pc != 0x1D41CCu) { return; }
    ctx->pc = 0x1D41CCu;
label_1d41cc:
    // 0x1d41cc: 0x1c400002
    ctx->pc = 0x1D41CCu;
    {
        const bool branch_taken_0x1d41cc = (GPR_S32(ctx, 2) > 0);
        if (branch_taken_0x1d41cc) {
            ctx->pc = 0x1D41D8u;
            goto label_1d41d8;
        }
    }
    ctx->pc = 0x1D41D4u;
    // 0x1d41d4: 0xae000000
    ctx->pc = 0x1d41d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
label_1d41d8:
    // 0x1d41d8: 0xdfbf0010
    ctx->pc = 0x1d41d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d41dc: 0x7bb00000
    ctx->pc = 0x1d41dcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d41e0: 0x3e00008
    ctx->pc = 0x1D41E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D41E4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 160));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3DC0u: goto label_1d3dc0;
            case 0x1D3E3Cu: goto label_1d3e3c;
            case 0x1D3E6Cu: goto label_1d3e6c;
            case 0x1D3F00u: goto label_1d3f00;
            case 0x1D3F10u: goto label_1d3f10;
            case 0x1D3F48u: goto label_1d3f48;
            case 0x1D3F50u: goto label_1d3f50;
            case 0x1D3F54u: goto label_1d3f54;
            case 0x1D3FCCu: goto label_1d3fcc;
            case 0x1D3FECu: goto label_1d3fec;
            case 0x1D3FFCu: goto label_1d3ffc;
            case 0x1D400Cu: goto label_1d400c;
            case 0x1D407Cu: goto label_1d407c;
            case 0x1D409Cu: goto label_1d409c;
            case 0x1D40BCu: goto label_1d40bc;
            case 0x1D40E8u: goto label_1d40e8;
            case 0x1D4100u: goto label_1d4100;
            case 0x1D4114u: goto label_1d4114;
            case 0x1D415Cu: goto label_1d415c;
            case 0x1D4164u: goto label_1d4164;
            case 0x1D41ACu: goto label_1d41ac;
            case 0x1D41CCu: goto label_1d41cc;
            case 0x1D41D8u: goto label_1d41d8;
            case 0x1D4250u: goto label_1d4250;
            case 0x1D42A4u: goto label_1d42a4;
            case 0x1D42E0u: goto label_1d42e0;
            case 0x1D4308u: goto label_1d4308;
            case 0x1D4318u: goto label_1d4318;
            case 0x1D4368u: goto label_1d4368;
            case 0x1D4384u: goto label_1d4384;
            case 0x1D43C0u: goto label_1d43c0;
            case 0x1D43DCu: goto label_1d43dc;
            case 0x1D4430u: goto label_1d4430;
            case 0x1D446Cu: goto label_1d446c;
            case 0x1D4494u: goto label_1d4494;
            case 0x1D449Cu: goto label_1d449c;
            case 0x1D44F4u: goto label_1d44f4;
            case 0x1D4510u: goto label_1d4510;
            case 0x1D4548u: goto label_1d4548;
            case 0x1D4550u: goto label_1d4550;
            case 0x1D45A8u: goto label_1d45a8;
            case 0x1D45BCu: goto label_1d45bc;
            case 0x1D4678u: goto label_1d4678;
            case 0x1D46A0u: goto label_1d46a0;
            case 0x1D46B8u: goto label_1d46b8;
            case 0x1D46D4u: goto label_1d46d4;
            case 0x1D4790u: goto label_1d4790;
            case 0x1D47BCu: goto label_1d47bc;
            case 0x1D47E0u: goto label_1d47e0;
            case 0x1D47ECu: goto label_1d47ec;
            case 0x1D4814u: goto label_1d4814;
            case 0x1D4818u: goto label_1d4818;
            case 0x1D481Cu: goto label_1d481c;
            case 0x1D482Cu: goto label_1d482c;
            case 0x1D4830u: goto label_1d4830;
            case 0x1D483Cu: goto label_1d483c;
            case 0x1D4840u: goto label_1d4840;
            case 0x1D48F0u: goto label_1d48f0;
            case 0x1D4944u: goto label_1d4944;
            case 0x1D497Cu: goto label_1d497c;
            case 0x1D49B4u: goto label_1d49b4;
            case 0x1D4A3Cu: goto label_1d4a3c;
            case 0x1D4A70u: goto label_1d4a70;
            case 0x1D4AB8u: goto label_1d4ab8;
            case 0x1D4B30u: goto label_1d4b30;
            case 0x1D4B58u: goto label_1d4b58;
            case 0x1D4B94u: goto label_1d4b94;
            case 0x1D4BD8u: goto label_1d4bd8;
            case 0x1D4C18u: goto label_1d4c18;
            case 0x1D4C28u: goto label_1d4c28;
            case 0x1D4C70u: goto label_1d4c70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D41E8u;
    // 0x1d41e8: 0x0
    ctx->pc = 0x1d41e8u;
    // NOP
    // 0x1d41ec: 0x0
    ctx->pc = 0x1d41ecu;
    // NOP
    // 0x1d41f0: 0x27bdff20
    ctx->pc = 0x1d41f0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967072));
    // 0x1d41f4: 0xffbf0050
    ctx->pc = 0x1d41f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x1d41f8: 0x7fb40040
    ctx->pc = 0x1d41f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d41fc: 0x7fb30030
    ctx->pc = 0x1d41fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d4200: 0x7fb20020
    ctx->pc = 0x1d4200u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d4204: 0x7fb10010
    ctx->pc = 0x1d4204u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d4208: 0x3c120032
    ctx->pc = 0x1d4208u;
    SET_GPR_U32(ctx, 18, ((uint32_t)50 << 16));
    // 0x1d420c: 0x7fb00000
    ctx->pc = 0x1d420cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d4210: 0xc1adcfc
    ctx->pc = 0x1D4210u;
    SET_GPR_U32(ctx, 31, 0x1D4218u);
    ctx->pc = 0x1D4214u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 17344));
    ctx->pc = 0x6B73F0u;
    {
        auto targetFn = runtime->lookupFunction(0x6B73F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4218u; }
        if (ctx->pc != 0x1D4218u) { return; }
    }
    ctx->pc = 0x1D4218u;
    // 0x1d4218: 0x3c01004c
    ctx->pc = 0x1d4218u;
    SET_GPR_U32(ctx, 1, ((uint32_t)76 << 16));
    // 0x1d421c: 0x40882d
    ctx->pc = 0x1d421cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4220: 0x90239d14
    ctx->pc = 0x1d4220u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294941972)));
    // 0x1d4224: 0x107100ca
    ctx->pc = 0x1D4224u;
    {
        const bool branch_taken_0x1d4224 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 17));
        if (branch_taken_0x1d4224) {
            ctx->pc = 0x1D4550u;
            goto label_1d4550;
        }
    }
    ctx->pc = 0x1D422Cu;
    // 0x1d422c: 0xc1addc8
    ctx->pc = 0x1D422Cu;
    SET_GPR_U32(ctx, 31, 0x1D4234u);
    ctx->pc = 0x6B7720u;
    {
        auto targetFn = runtime->lookupFunction(0x6B7720u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4234u; }
        if (ctx->pc != 0x1D4234u) { return; }
    }
    ctx->pc = 0x1D4234u;
    // 0x1d4234: 0x62000c6
    ctx->pc = 0x1D4234u;
    {
        const bool branch_taken_0x1d4234 = (GPR_S32(ctx, 17) < 0);
        ctx->pc = 0x1D4238u;
        SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
        if (branch_taken_0x1d4234) {
            ctx->pc = 0x1D4550u;
            goto label_1d4550;
        }
    }
    ctx->pc = 0x1D423Cu;
    // 0x1d423c: 0xa02d
    ctx->pc = 0x1d423cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4240: 0x8c224438
    ctx->pc = 0x1d4240u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 17464)));
    // 0x1d4244: 0x27b00060
    ctx->pc = 0x1d4244u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d4248: 0x10000033
    ctx->pc = 0x1D4248u;
    {
        const bool branch_taken_0x1d4248 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D424Cu;
        SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 2), 24576));
        if (branch_taken_0x1d4248) {
            ctx->pc = 0x1D4318u;
            goto label_1d4318;
        }
    }
    ctx->pc = 0x1D4250u;
label_1d4250:
    // 0x1d4250: 0x802243d7
    ctx->pc = 0x1d4250u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d4254: 0x14400013
    ctx->pc = 0x1D4254u;
    {
        const bool branch_taken_0x1d4254 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D4258u;
        SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 20), 4));
        if (branch_taken_0x1d4254) {
            ctx->pc = 0x1D42A4u;
            goto label_1d42a4;
        }
    }
    ctx->pc = 0x1D425Cu;
    // 0x1d425c: 0x141100
    ctx->pc = 0x1d425cu;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 20), 4));
    // 0x1d4260: 0x9646001a
    ctx->pc = 0x1d4260u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 26)));
    // 0x1d4264: 0x542823
    ctx->pc = 0x1d4264u;
    SET_GPR_U32(ctx, 5, SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 20)));
    // 0x1d4268: 0x27a40060
    ctx->pc = 0x1d4268u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d426c: 0x518c0
    ctx->pc = 0x1d426cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 5), 3));
    // 0x1d4270: 0x3c02004a
    ctx->pc = 0x1d4270u;
    SET_GPR_U32(ctx, 2, ((uint32_t)74 << 16));
    // 0x1d4274: 0xa31821
    ctx->pc = 0x1d4274u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1d4278: 0x24425c30
    ctx->pc = 0x1d4278u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 23600));
    // 0x1d427c: 0x31940
    ctx->pc = 0x1d427cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 5));
    // 0x1d4280: 0x3c050025
    ctx->pc = 0x1d4280u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d4284: 0x431021
    ctx->pc = 0x1d4284u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d4288: 0x24a567d0
    ctx->pc = 0x1d4288u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26576));
    // 0x1d428c: 0x90490b98
    ctx->pc = 0x1d428cu;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2968)));
    // 0x1d4290: 0x220402d
    ctx->pc = 0x1d4290u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4294: 0xc042a0c
    ctx->pc = 0x1D4294u;
    SET_GPR_U32(ctx, 31, 0x1D429Cu);
    ctx->pc = 0x1D4298u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D429Cu; }
    }
    if (ctx->pc != 0x1D429Cu) { return; }
    ctx->pc = 0x1D429Cu;
    // 0x1d429c: 0x10000010
    ctx->pc = 0x1D429Cu;
    {
        const bool branch_taken_0x1d429c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D42A0u;
        SET_GPR_U32(ctx, 2, ((uint32_t)1 << 16));
        if (branch_taken_0x1d429c) {
            ctx->pc = 0x1D42E0u;
            goto label_1d42e0;
        }
    }
    ctx->pc = 0x1D42A4u;
label_1d42a4:
    // 0x1d42a4: 0x9646001a
    ctx->pc = 0x1d42a4u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 26)));
    // 0x1d42a8: 0x542823
    ctx->pc = 0x1d42a8u;
    SET_GPR_U32(ctx, 5, SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 20)));
    // 0x1d42ac: 0x27a40060
    ctx->pc = 0x1d42acu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d42b0: 0x518c0
    ctx->pc = 0x1d42b0u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 5), 3));
    // 0x1d42b4: 0x3c02004a
    ctx->pc = 0x1d42b4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)74 << 16));
    // 0x1d42b8: 0xa31821
    ctx->pc = 0x1d42b8u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1d42bc: 0x24425c30
    ctx->pc = 0x1d42bcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 23600));
    // 0x1d42c0: 0x31940
    ctx->pc = 0x1d42c0u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 5));
    // 0x1d42c4: 0x3c050025
    ctx->pc = 0x1d42c4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d42c8: 0x431021
    ctx->pc = 0x1d42c8u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d42cc: 0x24a56800
    ctx->pc = 0x1d42ccu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26624));
    // 0x1d42d0: 0x90480b98
    ctx->pc = 0x1d42d0u;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2968)));
    // 0x1d42d4: 0xc042a0c
    ctx->pc = 0x1D42D4u;
    SET_GPR_U32(ctx, 31, 0x1D42DCu);
    ctx->pc = 0x1D42D8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D42DCu; }
    }
    if (ctx->pc != 0x1D42DCu) { return; }
    ctx->pc = 0x1D42DCu;
    // 0x1d42dc: 0x3c020001
    ctx->pc = 0x1d42dcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)1 << 16));
label_1d42e0:
    // 0x1d42e0: 0x200202d
    ctx->pc = 0x1d42e0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d42e4: 0x260282d
    ctx->pc = 0x1d42e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d42e8: 0x382d
    ctx->pc = 0x1d42e8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d42ec: 0xc07323c
    ctx->pc = 0x1D42ECu;
    SET_GPR_U32(ctx, 31, 0x1D42F4u);
    ctx->pc = 0x1D42F0u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 2), 1));
    ctx->pc = 0x1CC8F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D42F4u; }
    }
    if (ctx->pc != 0x1D42F4u) { return; }
    ctx->pc = 0x1D42F4u;
    // 0x1d42f4: 0x18400004
    ctx->pc = 0x1D42F4u;
    {
        const bool branch_taken_0x1d42f4 = (GPR_S32(ctx, 2) <= 0);
        ctx->pc = 0x1D42F8u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1d42f4) {
            ctx->pc = 0x1D4308u;
            goto label_1d4308;
        }
    }
    ctx->pc = 0x1D42FCu;
    // 0x1d42fc: 0x282d
    ctx->pc = 0x1d42fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4300: 0xc1adcd4
    ctx->pc = 0x1D4300u;
    SET_GPR_U32(ctx, 31, 0x1D4308u);
    ctx->pc = 0x1D4304u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x6B7350u;
    {
        auto targetFn = runtime->lookupFunction(0x6B7350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4308u; }
        if (ctx->pc != 0x1D4308u) { return; }
    }
    ctx->pc = 0x1D4308u;
label_1d4308:
    // 0x1d4308: 0x3c020001
    ctx->pc = 0x1d4308u;
    SET_GPR_U32(ctx, 2, ((uint32_t)1 << 16));
    // 0x1d430c: 0x26940001
    ctx->pc = 0x1d430cu;
    SET_GPR_S32(ctx, 20, ADD32(GPR_U32(ctx, 20), 1));
    // 0x1d4310: 0x34422800
    ctx->pc = 0x1d4310u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 10240));
    // 0x1d4314: 0x2629821
    ctx->pc = 0x1d4314u;
    SET_GPR_U32(ctx, 19, ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
label_1d4318:
    // 0x1d4318: 0x3c01004c
    ctx->pc = 0x1d4318u;
    SET_GPR_U32(ctx, 1, ((uint32_t)76 << 16));
    // 0x1d431c: 0x8c22aea0
    ctx->pc = 0x1d431cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 4294946464)));
    // 0x1d4320: 0x282102a
    ctx->pc = 0x1d4320u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 20), GPR_S32(ctx, 2)));
    // 0x1d4324: 0x1440ffca
    ctx->pc = 0x1D4324u;
    {
        const bool branch_taken_0x1d4324 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D4328u;
        SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
        if (branch_taken_0x1d4324) {
            ctx->pc = 0x1D4250u;
            goto label_1d4250;
        }
    }
    ctx->pc = 0x1D432Cu;
    // 0x1d432c: 0x3c010032
    ctx->pc = 0x1d432cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d4330: 0x8c234438
    ctx->pc = 0x1d4330u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 17464)));
    // 0x1d4334: 0x3c010032
    ctx->pc = 0x1d4334u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d4338: 0x802243d7
    ctx->pc = 0x1d4338u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d433c: 0x1440000a
    ctx->pc = 0x1D433Cu;
    {
        const bool branch_taken_0x1d433c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D4340u;
        SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 3), 24576));
        if (branch_taken_0x1d433c) {
            ctx->pc = 0x1D4368u;
            goto label_1d4368;
        }
    }
    ctx->pc = 0x1D4344u;
    // 0x1d4344: 0x9646001a
    ctx->pc = 0x1d4344u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 26)));
    // 0x1d4348: 0x3c050025
    ctx->pc = 0x1d4348u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d434c: 0x27a40060
    ctx->pc = 0x1d434cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d4350: 0x24a56820
    ctx->pc = 0x1d4350u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26656));
    // 0x1d4354: 0x220402d
    ctx->pc = 0x1d4354u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4358: 0xc042a0c
    ctx->pc = 0x1D4358u;
    SET_GPR_U32(ctx, 31, 0x1D4360u);
    ctx->pc = 0x1D435Cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4360u; }
    }
    if (ctx->pc != 0x1D4360u) { return; }
    ctx->pc = 0x1D4360u;
    // 0x1d4360: 0x10000008
    ctx->pc = 0x1D4360u;
    {
        const bool branch_taken_0x1d4360 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D4364u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4 << 16));
        if (branch_taken_0x1d4360) {
            ctx->pc = 0x1D4384u;
            goto label_1d4384;
        }
    }
    ctx->pc = 0x1D4368u;
label_1d4368:
    // 0x1d4368: 0x9646001a
    ctx->pc = 0x1d4368u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 26)));
    // 0x1d436c: 0x3c050025
    ctx->pc = 0x1d436cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d4370: 0x27a40060
    ctx->pc = 0x1d4370u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d4374: 0x24a56850
    ctx->pc = 0x1d4374u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26704));
    // 0x1d4378: 0xc042a0c
    ctx->pc = 0x1D4378u;
    SET_GPR_U32(ctx, 31, 0x1D4380u);
    ctx->pc = 0x1D437Cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4380u; }
    }
    if (ctx->pc != 0x1D4380u) { return; }
    ctx->pc = 0x1D4380u;
    // 0x1d4380: 0x3c020004
    ctx->pc = 0x1d4380u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4 << 16));
label_1d4384:
    // 0x1d4384: 0x200202d
    ctx->pc = 0x1d4384u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4388: 0x3443a000
    ctx->pc = 0x1d4388u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 2), 40960));
    // 0x1d438c: 0x382d
    ctx->pc = 0x1d438cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4390: 0x3c020001
    ctx->pc = 0x1d4390u;
    SET_GPR_U32(ctx, 2, ((uint32_t)1 << 16));
    // 0x1d4394: 0x2632821
    ctx->pc = 0x1d4394u;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 3)));
    // 0x1d4398: 0xc07323c
    ctx->pc = 0x1D4398u;
    SET_GPR_U32(ctx, 31, 0x1D43A0u);
    ctx->pc = 0x1D439Cu;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 2), 1));
    ctx->pc = 0x1CC8F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D43A0u; }
    }
    if (ctx->pc != 0x1D43A0u) { return; }
    ctx->pc = 0x1D43A0u;
    // 0x1d43a0: 0x18400007
    ctx->pc = 0x1D43A0u;
    {
        const bool branch_taken_0x1d43a0 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x1d43a0) {
            ctx->pc = 0x1D43C0u;
            goto label_1d43c0;
        }
    }
    ctx->pc = 0x1D43A8u;
    // 0x1d43a8: 0x3c020004
    ctx->pc = 0x1d43a8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4 << 16));
    // 0x1d43ac: 0x282d
    ctx->pc = 0x1d43acu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d43b0: 0x3442a000
    ctx->pc = 0x1d43b0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 40960));
    // 0x1d43b4: 0x24060004
    ctx->pc = 0x1d43b4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d43b8: 0xc1adcd4
    ctx->pc = 0x1D43B8u;
    SET_GPR_U32(ctx, 31, 0x1D43C0u);
    ctx->pc = 0x1D43BCu;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    ctx->pc = 0x6B7350u;
    {
        auto targetFn = runtime->lookupFunction(0x6B7350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D43C0u; }
        if (ctx->pc != 0x1D43C0u) { return; }
    }
    ctx->pc = 0x1D43C0u;
label_1d43c0:
    // 0x1d43c0: 0x3c010032
    ctx->pc = 0x1d43c0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d43c4: 0x3c020005
    ctx->pc = 0x1d43c4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)5 << 16));
    // 0x1d43c8: 0x8c234438
    ctx->pc = 0x1d43c8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 17464)));
    // 0x1d43cc: 0x3442c000
    ctx->pc = 0x1d43ccu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 49152));
    // 0x1d43d0: 0x982d
    ctx->pc = 0x1d43d0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d43d4: 0x10000031
    ctx->pc = 0x1D43D4u;
    {
        const bool branch_taken_0x1d43d4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D43D8u;
        SET_GPR_U32(ctx, 20, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        if (branch_taken_0x1d43d4) {
            ctx->pc = 0x1D449Cu;
            goto label_1d449c;
        }
    }
    ctx->pc = 0x1D43DCu;
label_1d43dc:
    // 0x1d43dc: 0x802243d7
    ctx->pc = 0x1d43dcu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d43e0: 0x14400013
    ctx->pc = 0x1D43E0u;
    {
        const bool branch_taken_0x1d43e0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D43E4u;
        SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 19), 4));
        if (branch_taken_0x1d43e0) {
            ctx->pc = 0x1D4430u;
            goto label_1d4430;
        }
    }
    ctx->pc = 0x1D43E8u;
    // 0x1d43e8: 0x131100
    ctx->pc = 0x1d43e8u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 19), 4));
    // 0x1d43ec: 0x9646001a
    ctx->pc = 0x1d43ecu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 26)));
    // 0x1d43f0: 0x532823
    ctx->pc = 0x1d43f0u;
    SET_GPR_U32(ctx, 5, SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1d43f4: 0x27a40060
    ctx->pc = 0x1d43f4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d43f8: 0x518c0
    ctx->pc = 0x1d43f8u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 5), 3));
    // 0x1d43fc: 0x3c02004a
    ctx->pc = 0x1d43fcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)74 << 16));
    // 0x1d4400: 0xa31821
    ctx->pc = 0x1d4400u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1d4404: 0x24425c30
    ctx->pc = 0x1d4404u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 23600));
    // 0x1d4408: 0x31940
    ctx->pc = 0x1d4408u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 5));
    // 0x1d440c: 0x3c050025
    ctx->pc = 0x1d440cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d4410: 0x431021
    ctx->pc = 0x1d4410u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d4414: 0x24a56870
    ctx->pc = 0x1d4414u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26736));
    // 0x1d4418: 0x90490b98
    ctx->pc = 0x1d4418u;
    SET_GPR_U32(ctx, 9, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2968)));
    // 0x1d441c: 0x220402d
    ctx->pc = 0x1d441cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4420: 0xc042a0c
    ctx->pc = 0x1D4420u;
    SET_GPR_U32(ctx, 31, 0x1D4428u);
    ctx->pc = 0x1D4424u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4428u; }
    }
    if (ctx->pc != 0x1D4428u) { return; }
    ctx->pc = 0x1D4428u;
    // 0x1d4428: 0x10000010
    ctx->pc = 0x1D4428u;
    {
        const bool branch_taken_0x1d4428 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D442Cu;
        SET_GPR_U32(ctx, 2, ((uint32_t)1 << 16));
        if (branch_taken_0x1d4428) {
            ctx->pc = 0x1D446Cu;
            goto label_1d446c;
        }
    }
    ctx->pc = 0x1D4430u;
label_1d4430:
    // 0x1d4430: 0x9646001a
    ctx->pc = 0x1d4430u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 26)));
    // 0x1d4434: 0x532823
    ctx->pc = 0x1d4434u;
    SET_GPR_U32(ctx, 5, SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x1d4438: 0x27a40060
    ctx->pc = 0x1d4438u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d443c: 0x518c0
    ctx->pc = 0x1d443cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 5), 3));
    // 0x1d4440: 0x3c02004a
    ctx->pc = 0x1d4440u;
    SET_GPR_U32(ctx, 2, ((uint32_t)74 << 16));
    // 0x1d4444: 0xa31821
    ctx->pc = 0x1d4444u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1d4448: 0x24425c30
    ctx->pc = 0x1d4448u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 23600));
    // 0x1d444c: 0x31940
    ctx->pc = 0x1d444cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 5));
    // 0x1d4450: 0x3c050025
    ctx->pc = 0x1d4450u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d4454: 0x431021
    ctx->pc = 0x1d4454u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d4458: 0x24a568a0
    ctx->pc = 0x1d4458u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26784));
    // 0x1d445c: 0x90480b98
    ctx->pc = 0x1d445cu;
    SET_GPR_U32(ctx, 8, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 2968)));
    // 0x1d4460: 0xc042a0c
    ctx->pc = 0x1D4460u;
    SET_GPR_U32(ctx, 31, 0x1D4468u);
    ctx->pc = 0x1D4464u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4468u; }
    }
    if (ctx->pc != 0x1D4468u) { return; }
    ctx->pc = 0x1D4468u;
    // 0x1d4468: 0x3c020001
    ctx->pc = 0x1d4468u;
    SET_GPR_U32(ctx, 2, ((uint32_t)1 << 16));
label_1d446c:
    // 0x1d446c: 0x200202d
    ctx->pc = 0x1d446cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4470: 0x280282d
    ctx->pc = 0x1d4470u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4474: 0x382d
    ctx->pc = 0x1d4474u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4478: 0xc07323c
    ctx->pc = 0x1D4478u;
    SET_GPR_U32(ctx, 31, 0x1D4480u);
    ctx->pc = 0x1D447Cu;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 2), 1));
    ctx->pc = 0x1CC8F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4480u; }
    }
    if (ctx->pc != 0x1D4480u) { return; }
    ctx->pc = 0x1D4480u;
    // 0x1d4480: 0x18400004
    ctx->pc = 0x1D4480u;
    {
        const bool branch_taken_0x1d4480 = (GPR_S32(ctx, 2) <= 0);
        ctx->pc = 0x1D4484u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1d4480) {
            ctx->pc = 0x1D4494u;
            goto label_1d4494;
        }
    }
    ctx->pc = 0x1D4488u;
    // 0x1d4488: 0x24050001
    ctx->pc = 0x1d4488u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d448c: 0xc1adcd4
    ctx->pc = 0x1D448Cu;
    SET_GPR_U32(ctx, 31, 0x1D4494u);
    ctx->pc = 0x1D4490u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x6B7350u;
    {
        auto targetFn = runtime->lookupFunction(0x6B7350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4494u; }
        if (ctx->pc != 0x1D4494u) { return; }
    }
    ctx->pc = 0x1D4494u;
label_1d4494:
    // 0x1d4494: 0x26730001
    ctx->pc = 0x1d4494u;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 19), 1));
    // 0x1d4498: 0x26945c00
    ctx->pc = 0x1d4498u;
    SET_GPR_S32(ctx, 20, ADD32(GPR_U32(ctx, 20), 23552));
label_1d449c:
    // 0x1d449c: 0x3c01004c
    ctx->pc = 0x1d449cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)76 << 16));
    // 0x1d44a0: 0x8c22aea0
    ctx->pc = 0x1d44a0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 4294946464)));
    // 0x1d44a4: 0x262102a
    ctx->pc = 0x1d44a4u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 19), GPR_S32(ctx, 2)));
    // 0x1d44a8: 0x1440ffcc
    ctx->pc = 0x1D44A8u;
    {
        const bool branch_taken_0x1d44a8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D44ACu;
        SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
        if (branch_taken_0x1d44a8) {
            ctx->pc = 0x1D43DCu;
            goto label_1d43dc;
        }
    }
    ctx->pc = 0x1D44B0u;
    // 0x1d44b0: 0x3c010032
    ctx->pc = 0x1d44b0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d44b4: 0x3c020005
    ctx->pc = 0x1d44b4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)5 << 16));
    // 0x1d44b8: 0x8c244438
    ctx->pc = 0x1d44b8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 1), 17464)));
    // 0x1d44bc: 0x3443c000
    ctx->pc = 0x1d44bcu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 2), 49152));
    // 0x1d44c0: 0x3c010032
    ctx->pc = 0x1d44c0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d44c4: 0x802243d7
    ctx->pc = 0x1d44c4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d44c8: 0x1440000a
    ctx->pc = 0x1D44C8u;
    {
        const bool branch_taken_0x1d44c8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D44CCu;
        SET_GPR_U32(ctx, 19, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
        if (branch_taken_0x1d44c8) {
            ctx->pc = 0x1D44F4u;
            goto label_1d44f4;
        }
    }
    ctx->pc = 0x1D44D0u;
    // 0x1d44d0: 0x9646001a
    ctx->pc = 0x1d44d0u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 26)));
    // 0x1d44d4: 0x3c050025
    ctx->pc = 0x1d44d4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d44d8: 0x27a40060
    ctx->pc = 0x1d44d8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d44dc: 0x24a568c0
    ctx->pc = 0x1d44dcu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26816));
    // 0x1d44e0: 0x220402d
    ctx->pc = 0x1d44e0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d44e4: 0xc042a0c
    ctx->pc = 0x1D44E4u;
    SET_GPR_U32(ctx, 31, 0x1D44ECu);
    ctx->pc = 0x1D44E8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D44ECu; }
    }
    if (ctx->pc != 0x1D44ECu) { return; }
    ctx->pc = 0x1D44ECu;
    // 0x1d44ec: 0x10000008
    ctx->pc = 0x1D44ECu;
    {
        const bool branch_taken_0x1d44ec = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D44F0u;
        SET_GPR_U32(ctx, 2, ((uint32_t)1 << 16));
        if (branch_taken_0x1d44ec) {
            ctx->pc = 0x1D4510u;
            goto label_1d4510;
        }
    }
    ctx->pc = 0x1D44F4u;
label_1d44f4:
    // 0x1d44f4: 0x9646001a
    ctx->pc = 0x1d44f4u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 18), 26)));
    // 0x1d44f8: 0x3c050025
    ctx->pc = 0x1d44f8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d44fc: 0x27a40060
    ctx->pc = 0x1d44fcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 96));
    // 0x1d4500: 0x24a568f0
    ctx->pc = 0x1d4500u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26864));
    // 0x1d4504: 0xc042a0c
    ctx->pc = 0x1D4504u;
    SET_GPR_U32(ctx, 31, 0x1D450Cu);
    ctx->pc = 0x1D4508u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D450Cu; }
    }
    if (ctx->pc != 0x1D450Cu) { return; }
    ctx->pc = 0x1D450Cu;
    // 0x1d450c: 0x3c020001
    ctx->pc = 0x1d450cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)1 << 16));
label_1d4510:
    // 0x1d4510: 0x200202d
    ctx->pc = 0x1d4510u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4514: 0x34437000
    ctx->pc = 0x1d4514u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 2), 28672));
    // 0x1d4518: 0x34460001
    ctx->pc = 0x1d4518u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 2), 1));
    // 0x1d451c: 0x2632821
    ctx->pc = 0x1d451cu;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 3)));
    // 0x1d4520: 0xc07323c
    ctx->pc = 0x1D4520u;
    SET_GPR_U32(ctx, 31, 0x1D4528u);
    ctx->pc = 0x1D4524u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1CC8F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4528u; }
    }
    if (ctx->pc != 0x1D4528u) { return; }
    ctx->pc = 0x1D4528u;
    // 0x1d4528: 0x18400007
    ctx->pc = 0x1D4528u;
    {
        const bool branch_taken_0x1d4528 = (GPR_S32(ctx, 2) <= 0);
        if (branch_taken_0x1d4528) {
            ctx->pc = 0x1D4548u;
            goto label_1d4548;
        }
    }
    ctx->pc = 0x1D4530u;
    // 0x1d4530: 0x3c020001
    ctx->pc = 0x1d4530u;
    SET_GPR_U32(ctx, 2, ((uint32_t)1 << 16));
    // 0x1d4534: 0x24050001
    ctx->pc = 0x1d4534u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d4538: 0x34427000
    ctx->pc = 0x1d4538u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 28672));
    // 0x1d453c: 0x24060004
    ctx->pc = 0x1d453cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d4540: 0xc1adcd4
    ctx->pc = 0x1D4540u;
    SET_GPR_U32(ctx, 31, 0x1D4548u);
    ctx->pc = 0x1D4544u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 2)));
    ctx->pc = 0x6B7350u;
    {
        auto targetFn = runtime->lookupFunction(0x6B7350u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4548u; }
        if (ctx->pc != 0x1D4548u) { return; }
    }
    ctx->pc = 0x1D4548u;
label_1d4548:
    // 0x1d4548: 0x3c01004c
    ctx->pc = 0x1d4548u;
    SET_GPR_U32(ctx, 1, ((uint32_t)76 << 16));
    // 0x1d454c: 0xa0319d14
    ctx->pc = 0x1d454cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294941972), (uint8_t)GPR_U32(ctx, 17));
label_1d4550:
    // 0x1d4550: 0xdfbf0050
    ctx->pc = 0x1d4550u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d4554: 0x7bb40040
    ctx->pc = 0x1d4554u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d4558: 0x7bb30030
    ctx->pc = 0x1d4558u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d455c: 0x7bb20020
    ctx->pc = 0x1d455cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d4560: 0x7bb10010
    ctx->pc = 0x1d4560u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d4564: 0x7bb00000
    ctx->pc = 0x1d4564u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4568: 0x3e00008
    ctx->pc = 0x1D4568u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D456Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 224));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3DC0u: goto label_1d3dc0;
            case 0x1D3E3Cu: goto label_1d3e3c;
            case 0x1D3E6Cu: goto label_1d3e6c;
            case 0x1D3F00u: goto label_1d3f00;
            case 0x1D3F10u: goto label_1d3f10;
            case 0x1D3F48u: goto label_1d3f48;
            case 0x1D3F50u: goto label_1d3f50;
            case 0x1D3F54u: goto label_1d3f54;
            case 0x1D3FCCu: goto label_1d3fcc;
            case 0x1D3FECu: goto label_1d3fec;
            case 0x1D3FFCu: goto label_1d3ffc;
            case 0x1D400Cu: goto label_1d400c;
            case 0x1D407Cu: goto label_1d407c;
            case 0x1D409Cu: goto label_1d409c;
            case 0x1D40BCu: goto label_1d40bc;
            case 0x1D40E8u: goto label_1d40e8;
            case 0x1D4100u: goto label_1d4100;
            case 0x1D4114u: goto label_1d4114;
            case 0x1D415Cu: goto label_1d415c;
            case 0x1D4164u: goto label_1d4164;
            case 0x1D41ACu: goto label_1d41ac;
            case 0x1D41CCu: goto label_1d41cc;
            case 0x1D41D8u: goto label_1d41d8;
            case 0x1D4250u: goto label_1d4250;
            case 0x1D42A4u: goto label_1d42a4;
            case 0x1D42E0u: goto label_1d42e0;
            case 0x1D4308u: goto label_1d4308;
            case 0x1D4318u: goto label_1d4318;
            case 0x1D4368u: goto label_1d4368;
            case 0x1D4384u: goto label_1d4384;
            case 0x1D43C0u: goto label_1d43c0;
            case 0x1D43DCu: goto label_1d43dc;
            case 0x1D4430u: goto label_1d4430;
            case 0x1D446Cu: goto label_1d446c;
            case 0x1D4494u: goto label_1d4494;
            case 0x1D449Cu: goto label_1d449c;
            case 0x1D44F4u: goto label_1d44f4;
            case 0x1D4510u: goto label_1d4510;
            case 0x1D4548u: goto label_1d4548;
            case 0x1D4550u: goto label_1d4550;
            case 0x1D45A8u: goto label_1d45a8;
            case 0x1D45BCu: goto label_1d45bc;
            case 0x1D4678u: goto label_1d4678;
            case 0x1D46A0u: goto label_1d46a0;
            case 0x1D46B8u: goto label_1d46b8;
            case 0x1D46D4u: goto label_1d46d4;
            case 0x1D4790u: goto label_1d4790;
            case 0x1D47BCu: goto label_1d47bc;
            case 0x1D47E0u: goto label_1d47e0;
            case 0x1D47ECu: goto label_1d47ec;
            case 0x1D4814u: goto label_1d4814;
            case 0x1D4818u: goto label_1d4818;
            case 0x1D481Cu: goto label_1d481c;
            case 0x1D482Cu: goto label_1d482c;
            case 0x1D4830u: goto label_1d4830;
            case 0x1D483Cu: goto label_1d483c;
            case 0x1D4840u: goto label_1d4840;
            case 0x1D48F0u: goto label_1d48f0;
            case 0x1D4944u: goto label_1d4944;
            case 0x1D497Cu: goto label_1d497c;
            case 0x1D49B4u: goto label_1d49b4;
            case 0x1D4A3Cu: goto label_1d4a3c;
            case 0x1D4A70u: goto label_1d4a70;
            case 0x1D4AB8u: goto label_1d4ab8;
            case 0x1D4B30u: goto label_1d4b30;
            case 0x1D4B58u: goto label_1d4b58;
            case 0x1D4B94u: goto label_1d4b94;
            case 0x1D4BD8u: goto label_1d4bd8;
            case 0x1D4C18u: goto label_1d4c18;
            case 0x1D4C28u: goto label_1d4c28;
            case 0x1D4C70u: goto label_1d4c70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4570u;
    // 0x1d4570: 0x27bdffc0
    ctx->pc = 0x1d4570u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1d4574: 0x3c010032
    ctx->pc = 0x1d4574u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d4578: 0xffbf0000
    ctx->pc = 0x1d4578u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d457c: 0x802243d7
    ctx->pc = 0x1d457cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d4580: 0x14400009
    ctx->pc = 0x1D4580u;
    {
        const bool branch_taken_0x1d4580 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D4584u;
        SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
        if (branch_taken_0x1d4580) {
            ctx->pc = 0x1D45A8u;
            goto label_1d45a8;
        }
    }
    ctx->pc = 0x1D4588u;
    // 0x1d4588: 0x3c010032
    ctx->pc = 0x1d4588u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d458c: 0x3c050025
    ctx->pc = 0x1d458cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d4590: 0x942643da
    ctx->pc = 0x1d4590u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d4594: 0x27a40010
    ctx->pc = 0x1d4594u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 16));
    // 0x1d4598: 0xc042a0c
    ctx->pc = 0x1D4598u;
    SET_GPR_U32(ctx, 31, 0x1D45A0u);
    ctx->pc = 0x1D459Cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26896));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D45A0u; }
    }
    if (ctx->pc != 0x1D45A0u) { return; }
    ctx->pc = 0x1D45A0u;
    // 0x1d45a0: 0x10000006
    ctx->pc = 0x1D45A0u;
    {
        const bool branch_taken_0x1d45a0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1d45a0) {
            ctx->pc = 0x1D45BCu;
            goto label_1d45bc;
        }
    }
    ctx->pc = 0x1D45A8u;
label_1d45a8:
    // 0x1d45a8: 0x3c050025
    ctx->pc = 0x1d45a8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d45ac: 0x942643da
    ctx->pc = 0x1d45acu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d45b0: 0x27a40010
    ctx->pc = 0x1d45b0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 16));
    // 0x1d45b4: 0xc042a0c
    ctx->pc = 0x1D45B4u;
    SET_GPR_U32(ctx, 31, 0x1D45BCu);
    ctx->pc = 0x1D45B8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26928));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D45BCu; }
    }
    if (ctx->pc != 0x1D45BCu) { return; }
    ctx->pc = 0x1D45BCu;
label_1d45bc:
    // 0x1d45bc: 0x3c010032
    ctx->pc = 0x1d45bcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d45c0: 0x3c020001
    ctx->pc = 0x1d45c0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)1 << 16));
    // 0x1d45c4: 0x8c254464
    ctx->pc = 0x1d45c4u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 1), 17508)));
    // 0x1d45c8: 0x27a40010
    ctx->pc = 0x1d45c8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 16));
    // 0x1d45cc: 0x382d
    ctx->pc = 0x1d45ccu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d45d0: 0xc07323c
    ctx->pc = 0x1D45D0u;
    SET_GPR_U32(ctx, 31, 0x1D45D8u);
    ctx->pc = 0x1D45D4u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 2), 1));
    ctx->pc = 0x1CC8F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D45D8u; }
    }
    if (ctx->pc != 0x1D45D8u) { return; }
    ctx->pc = 0x1D45D8u;
    // 0x1d45d8: 0xdfbf0000
    ctx->pc = 0x1d45d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d45dc: 0x3e00008
    ctx->pc = 0x1D45DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D45E0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3DC0u: goto label_1d3dc0;
            case 0x1D3E3Cu: goto label_1d3e3c;
            case 0x1D3E6Cu: goto label_1d3e6c;
            case 0x1D3F00u: goto label_1d3f00;
            case 0x1D3F10u: goto label_1d3f10;
            case 0x1D3F48u: goto label_1d3f48;
            case 0x1D3F50u: goto label_1d3f50;
            case 0x1D3F54u: goto label_1d3f54;
            case 0x1D3FCCu: goto label_1d3fcc;
            case 0x1D3FECu: goto label_1d3fec;
            case 0x1D3FFCu: goto label_1d3ffc;
            case 0x1D400Cu: goto label_1d400c;
            case 0x1D407Cu: goto label_1d407c;
            case 0x1D409Cu: goto label_1d409c;
            case 0x1D40BCu: goto label_1d40bc;
            case 0x1D40E8u: goto label_1d40e8;
            case 0x1D4100u: goto label_1d4100;
            case 0x1D4114u: goto label_1d4114;
            case 0x1D415Cu: goto label_1d415c;
            case 0x1D4164u: goto label_1d4164;
            case 0x1D41ACu: goto label_1d41ac;
            case 0x1D41CCu: goto label_1d41cc;
            case 0x1D41D8u: goto label_1d41d8;
            case 0x1D4250u: goto label_1d4250;
            case 0x1D42A4u: goto label_1d42a4;
            case 0x1D42E0u: goto label_1d42e0;
            case 0x1D4308u: goto label_1d4308;
            case 0x1D4318u: goto label_1d4318;
            case 0x1D4368u: goto label_1d4368;
            case 0x1D4384u: goto label_1d4384;
            case 0x1D43C0u: goto label_1d43c0;
            case 0x1D43DCu: goto label_1d43dc;
            case 0x1D4430u: goto label_1d4430;
            case 0x1D446Cu: goto label_1d446c;
            case 0x1D4494u: goto label_1d4494;
            case 0x1D449Cu: goto label_1d449c;
            case 0x1D44F4u: goto label_1d44f4;
            case 0x1D4510u: goto label_1d4510;
            case 0x1D4548u: goto label_1d4548;
            case 0x1D4550u: goto label_1d4550;
            case 0x1D45A8u: goto label_1d45a8;
            case 0x1D45BCu: goto label_1d45bc;
            case 0x1D4678u: goto label_1d4678;
            case 0x1D46A0u: goto label_1d46a0;
            case 0x1D46B8u: goto label_1d46b8;
            case 0x1D46D4u: goto label_1d46d4;
            case 0x1D4790u: goto label_1d4790;
            case 0x1D47BCu: goto label_1d47bc;
            case 0x1D47E0u: goto label_1d47e0;
            case 0x1D47ECu: goto label_1d47ec;
            case 0x1D4814u: goto label_1d4814;
            case 0x1D4818u: goto label_1d4818;
            case 0x1D481Cu: goto label_1d481c;
            case 0x1D482Cu: goto label_1d482c;
            case 0x1D4830u: goto label_1d4830;
            case 0x1D483Cu: goto label_1d483c;
            case 0x1D4840u: goto label_1d4840;
            case 0x1D48F0u: goto label_1d48f0;
            case 0x1D4944u: goto label_1d4944;
            case 0x1D497Cu: goto label_1d497c;
            case 0x1D49B4u: goto label_1d49b4;
            case 0x1D4A3Cu: goto label_1d4a3c;
            case 0x1D4A70u: goto label_1d4a70;
            case 0x1D4AB8u: goto label_1d4ab8;
            case 0x1D4B30u: goto label_1d4b30;
            case 0x1D4B58u: goto label_1d4b58;
            case 0x1D4B94u: goto label_1d4b94;
            case 0x1D4BD8u: goto label_1d4bd8;
            case 0x1D4C18u: goto label_1d4c18;
            case 0x1D4C28u: goto label_1d4c28;
            case 0x1D4C70u: goto label_1d4c70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D45E4u;
    // 0x1d45e4: 0x0
    ctx->pc = 0x1d45e4u;
    // NOP
    // 0x1d45e8: 0x0
    ctx->pc = 0x1d45e8u;
    // NOP
    // 0x1d45ec: 0x0
    ctx->pc = 0x1d45ecu;
    // NOP
    // 0x1d45f0: 0x27bdfe50
    ctx->pc = 0x1d45f0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294966864));
    // 0x1d45f4: 0x3c010032
    ctx->pc = 0x1d45f4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d45f8: 0xffbf0090
    ctx->pc = 0x1d45f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x1d45fc: 0x7fbe0080
    ctx->pc = 0x1d45fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 30));
    // 0x1d4600: 0x7fb70070
    ctx->pc = 0x1d4600u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x1d4604: 0x7fb60060
    ctx->pc = 0x1d4604u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1d4608: 0x7fb50050
    ctx->pc = 0x1d4608u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1d460c: 0x7fb40040
    ctx->pc = 0x1d460cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1d4610: 0x7fb30030
    ctx->pc = 0x1d4610u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1d4614: 0x7fb20020
    ctx->pc = 0x1d4614u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d4618: 0x7fb10010
    ctx->pc = 0x1d4618u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d461c: 0x7fb00000
    ctx->pc = 0x1d461cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d4620: 0x8c34440c
    ctx->pc = 0x1d4620u;
    SET_GPR_U32(ctx, 20, READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d4624: 0x3c010032
    ctx->pc = 0x1d4624u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d4628: 0x802243d7
    ctx->pc = 0x1d4628u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d462c: 0x14400012
    ctx->pc = 0x1D462Cu;
    {
        const bool branch_taken_0x1d462c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D4630u;
        SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
        if (branch_taken_0x1d462c) {
            ctx->pc = 0x1D4678u;
            goto label_1d4678;
        }
    }
    ctx->pc = 0x1D4634u;
    // 0x1d4634: 0x3c010032
    ctx->pc = 0x1d4634u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d4638: 0x3c050025
    ctx->pc = 0x1d4638u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d463c: 0x942743da
    ctx->pc = 0x1d463cu;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d4640: 0x3c060025
    ctx->pc = 0x1d4640u;
    SET_GPR_U32(ctx, 6, ((uint32_t)37 << 16));
    // 0x1d4644: 0x27a400b0
    ctx->pc = 0x1d4644u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 176));
    // 0x1d4648: 0x24a56940
    ctx->pc = 0x1d4648u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26944));
    // 0x1d464c: 0xc042a0c
    ctx->pc = 0x1D464Cu;
    SET_GPR_U32(ctx, 31, 0x1D4654u);
    ctx->pc = 0x1D4650u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 26960));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4654u; }
    }
    if (ctx->pc != 0x1D4654u) { return; }
    ctx->pc = 0x1D4654u;
    // 0x1d4654: 0x27a400b0
    ctx->pc = 0x1d4654u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 176));
    // 0x1d4658: 0x280282d
    ctx->pc = 0x1d4658u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d465c: 0x24060001
    ctx->pc = 0x1d465cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d4660: 0xc07323c
    ctx->pc = 0x1D4660u;
    SET_GPR_U32(ctx, 31, 0x1D4668u);
    ctx->pc = 0x1D4664u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1CC8F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4668u; }
    }
    if (ctx->pc != 0x1D4668u) { return; }
    ctx->pc = 0x1D4668u;
    // 0x1d4668: 0x1c40000d
    ctx->pc = 0x1D4668u;
    {
        const bool branch_taken_0x1d4668 = (GPR_S32(ctx, 2) > 0);
        if (branch_taken_0x1d4668) {
            ctx->pc = 0x1D46A0u;
            goto label_1d46a0;
        }
    }
    ctx->pc = 0x1D4670u;
    // 0x1d4670: 0x10000073
    ctx->pc = 0x1D4670u;
    {
        const bool branch_taken_0x1d4670 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D4674u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
        if (branch_taken_0x1d4670) {
            ctx->pc = 0x1D4840u;
            goto label_1d4840;
        }
    }
    ctx->pc = 0x1D4678u;
label_1d4678:
    // 0x1d4678: 0x3c050025
    ctx->pc = 0x1d4678u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d467c: 0x942643da
    ctx->pc = 0x1d467cu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d4680: 0x27a400b0
    ctx->pc = 0x1d4680u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 176));
    // 0x1d4684: 0xc042a0c
    ctx->pc = 0x1D4684u;
    SET_GPR_U32(ctx, 31, 0x1D468Cu);
    ctx->pc = 0x1D4688u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 26984));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D468Cu; }
    }
    if (ctx->pc != 0x1D468Cu) { return; }
    ctx->pc = 0x1D468Cu;
    // 0x1d468c: 0x27a400b0
    ctx->pc = 0x1d468cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 176));
    // 0x1d4690: 0xc06a8f8
    ctx->pc = 0x1D4690u;
    SET_GPR_U32(ctx, 31, 0x1D4698u);
    ctx->pc = 0x1D4694u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1AA3E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA3E0_0x1aa3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4698u; }
    }
    if (ctx->pc != 0x1D4698u) { return; }
    ctx->pc = 0x1D4698u;
    // 0x1d4698: 0x10400068
    ctx->pc = 0x1D4698u;
    {
        const bool branch_taken_0x1d4698 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1d4698) {
            ctx->pc = 0x1D483Cu;
            goto label_1d483c;
        }
    }
    ctx->pc = 0x1D46A0u;
label_1d46a0:
    // 0x1d46a0: 0x8e830000
    ctx->pc = 0x1d46a0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1d46a4: 0x882d
    ctx->pc = 0x1d46a4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d46a8: 0x982d
    ctx->pc = 0x1d46a8u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d46ac: 0x31842
    ctx->pc = 0x1d46acu;
    SET_GPR_U32(ctx, 3, SRL32(GPR_U32(ctx, 3), 1));
    // 0x1d46b0: 0x1000005f
    ctx->pc = 0x1D46B0u;
    {
        const bool branch_taken_0x1d46b0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D46B4u;
        SET_GPR_U32(ctx, 30, SRL32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x1d46b0) {
            ctx->pc = 0x1D4830u;
            goto label_1d4830;
        }
    }
    ctx->pc = 0x1D46B8u;
label_1d46b8:
    // 0x1d46b8: 0x902d
    ctx->pc = 0x1d46b8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d46bc: 0x2831821
    ctx->pc = 0x1d46bcu;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 3)));
    // 0x1d46c0: 0x8c630000
    ctx->pc = 0x1d46c0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1d46c4: 0x283b021
    ctx->pc = 0x1d46c4u;
    SET_GPR_U32(ctx, 22, ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 3)));
    // 0x1d46c8: 0x8ec30000
    ctx->pc = 0x1d46c8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x1d46cc: 0x10000053
    ctx->pc = 0x1D46CCu;
    {
        const bool branch_taken_0x1d46cc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D46D0u;
        WRITE32(ADD32(GPR_U32(ctx, 29), 160), GPR_U32(ctx, 3));
        if (branch_taken_0x1d46cc) {
            ctx->pc = 0x1D481Cu;
            goto label_1d481c;
        }
    }
    ctx->pc = 0x1D46D4u;
label_1d46d4:
    // 0x1d46d4: 0x10200055
    ctx->pc = 0x1D46D4u;
    {
        const bool branch_taken_0x1d46d4 = (GPR_U32(ctx, 1) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D46D8u;
        SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 18), 2));
        if (branch_taken_0x1d46d4) {
            ctx->pc = 0x1D482Cu;
            goto label_1d482c;
        }
    }
    ctx->pc = 0x1D46DCu;
    // 0x1d46dc: 0x111900
    ctx->pc = 0x1d46dcu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 17), 4));
    // 0x1d46e0: 0x2c42021
    ctx->pc = 0x1d46e0u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 4)));
    // 0x1d46e4: 0x711823
    ctx->pc = 0x1d46e4u;
    SET_GPR_U32(ctx, 3, SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 17)));
    // 0x1d46e8: 0x8c860004
    ctx->pc = 0x1d46e8u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 4), 4)));
    // 0x1d46ec: 0x2405ffff
    ctx->pc = 0x1d46ecu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d46f0: 0x2c6a821
    ctx->pc = 0x1d46f0u;
    SET_GPR_U32(ctx, 21, ADD32(GPR_U32(ctx, 22), GPR_U32(ctx, 6)));
    // 0x1d46f4: 0x320c0
    ctx->pc = 0x1d46f4u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 3), 3));
    // 0x1d46f8: 0x8ea60000
    ctx->pc = 0x1d46f8u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1d46fc: 0x3c030039
    ctx->pc = 0x1d46fcu;
    SET_GPR_U32(ctx, 3, ((uint32_t)57 << 16));
    // 0x1d4700: 0x24630210
    ctx->pc = 0x1d4700u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 528));
    // 0x1d4704: 0x648021
    ctx->pc = 0x1d4704u;
    SET_GPR_U32(ctx, 16, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1d4708: 0x2404001d
    ctx->pc = 0x1d4708u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 29));
    // 0x1d470c: 0xa2060000
    ctx->pc = 0x1d470cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 6));
    // 0x1d4710: 0x8ea60004
    ctx->pc = 0x1d4710u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 21), 4)));
    // 0x1d4714: 0xa2060001
    ctx->pc = 0x1d4714u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 1), (uint8_t)GPR_U32(ctx, 6));
    // 0x1d4718: 0x8ea60008
    ctx->pc = 0x1d4718u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 21), 8)));
    // 0x1d471c: 0xa2060002
    ctx->pc = 0x1d471cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 6));
    // 0x1d4720: 0x8ea60020
    ctx->pc = 0x1d4720u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 21), 32)));
    // 0x1d4724: 0xa2060003
    ctx->pc = 0x1d4724u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 3), (uint8_t)GPR_U32(ctx, 6));
    // 0x1d4728: 0x8ea6000c
    ctx->pc = 0x1d4728u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 21), 12)));
    // 0x1d472c: 0xa6060004
    ctx->pc = 0x1d472cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 6));
    // 0x1d4730: 0x8ea60024
    ctx->pc = 0x1d4730u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 21), 36)));
    // 0x1d4734: 0xa2060006
    ctx->pc = 0x1d4734u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 6), (uint8_t)GPR_U32(ctx, 6));
    // 0x1d4738: 0xc6a20010
    ctx->pc = 0x1d4738u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 16)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x1d473c: 0xc6a10014
    ctx->pc = 0x1d473cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 20)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x1d4740: 0xc6a00018
    ctx->pc = 0x1d4740u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 21), 24)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1d4744: 0xe6020008
    ctx->pc = 0x1d4744u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 8), bits); }
    // 0x1d4748: 0xe601000c
    ctx->pc = 0x1d4748u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 12), bits); }
    // 0x1d474c: 0xe6000010
    ctx->pc = 0x1d474cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 16), 16), bits); }
    // 0x1d4750: 0x8ea6001c
    ctx->pc = 0x1d4750u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 21), 28)));
    // 0x1d4754: 0xa6060014
    ctx->pc = 0x1d4754u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 20), (uint16_t)GPR_U32(ctx, 6));
    // 0x1d4758: 0x8ea60048
    ctx->pc = 0x1d4758u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 21), 72)));
    // 0x1d475c: 0xa6060016
    ctx->pc = 0x1d475cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 22), (uint16_t)GPR_U32(ctx, 6));
    // 0x1d4760: 0x8ea6004c
    ctx->pc = 0x1d4760u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 21), 76)));
    // 0x1d4764: 0xa6060022
    ctx->pc = 0x1d4764u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 34), (uint16_t)GPR_U32(ctx, 6));
    // 0x1d4768: 0xa200001e
    ctx->pc = 0x1d4768u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 30), (uint8_t)GPR_U32(ctx, 0));
    // 0x1d476c: 0x8ea60050
    ctx->pc = 0x1d476cu;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 21), 80)));
    // 0x1d4770: 0xa2060034
    ctx->pc = 0x1d4770u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 52), (uint8_t)GPR_U32(ctx, 6));
    // 0x1d4774: 0xae050028
    ctx->pc = 0x1d4774u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 5));
    // 0x1d4778: 0xae050030
    ctx->pc = 0x1d4778u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 5));
    // 0x1d477c: 0x96050004
    ctx->pc = 0x1d477cu;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1d4780: 0x10a40003
    ctx->pc = 0x1D4780u;
    {
        const bool branch_taken_0x1d4780 = (GPR_U32(ctx, 5) == GPR_U32(ctx, 4));
        ctx->pc = 0x1D4784u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 16), 6));
        if (branch_taken_0x1d4780) {
            ctx->pc = 0x1D4790u;
            goto label_1d4790;
        }
    }
    ctx->pc = 0x1D4788u;
    // 0x1d4788: 0xaea00024
    ctx->pc = 0x1d4788u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 36), GPR_U32(ctx, 0));
    // 0x1d478c: 0xa0600000
    ctx->pc = 0x1d478cu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
label_1d4790:
    // 0x1d4790: 0x8ea40024
    ctx->pc = 0x1d4790u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 21), 36)));
    // 0x1d4794: 0x24030002
    ctx->pc = 0x1d4794u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
    // 0x1d4798: 0x10830014
    ctx->pc = 0x1D4798u;
    {
        const bool branch_taken_0x1d4798 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x1D479Cu;
        SET_GPR_S32(ctx, 23, ADD32(GPR_U32(ctx, 16), 92));
        if (branch_taken_0x1d4798) {
            ctx->pc = 0x1D47ECu;
            goto label_1d47ec;
        }
    }
    ctx->pc = 0x1D47A0u;
    // 0x1d47a0: 0x24030001
    ctx->pc = 0x1d47a0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d47a4: 0x1083000e
    ctx->pc = 0x1D47A4u;
    {
        const bool branch_taken_0x1d47a4 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        if (branch_taken_0x1d47a4) {
            ctx->pc = 0x1D47E0u;
            goto label_1d47e0;
        }
    }
    ctx->pc = 0x1D47ACu;
    // 0x1d47ac: 0x10800003
    ctx->pc = 0x1D47ACu;
    {
        const bool branch_taken_0x1d47ac = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        if (branch_taken_0x1d47ac) {
            ctx->pc = 0x1D47BCu;
            goto label_1d47bc;
        }
    }
    ctx->pc = 0x1D47B4u;
    // 0x1d47b4: 0x10000018
    ctx->pc = 0x1D47B4u;
    {
        const bool branch_taken_0x1d47b4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D47B8u;
        SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 1));
        if (branch_taken_0x1d47b4) {
            ctx->pc = 0x1D4818u;
            goto label_1d4818;
        }
    }
    ctx->pc = 0x1D47BCu;
label_1d47bc:
    // 0x1d47bc: 0x8ea3002c
    ctx->pc = 0x1d47bcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 21), 44)));
    // 0x1d47c0: 0xa6030054
    ctx->pc = 0x1d47c0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 84), (uint16_t)GPR_U32(ctx, 3));
    // 0x1d47c4: 0x8ea30030
    ctx->pc = 0x1d47c4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 21), 48)));
    // 0x1d47c8: 0xa6030056
    ctx->pc = 0x1d47c8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 86), (uint16_t)GPR_U32(ctx, 3));
    // 0x1d47cc: 0x8ea30028
    ctx->pc = 0x1d47ccu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 21), 40)));
    // 0x1d47d0: 0xa2030058
    ctx->pc = 0x1d47d0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 88), (uint8_t)GPR_U32(ctx, 3));
    // 0x1d47d4: 0x8ea30034
    ctx->pc = 0x1d47d4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 21), 52)));
    // 0x1d47d8: 0x1000000e
    ctx->pc = 0x1D47D8u;
    {
        const bool branch_taken_0x1d47d8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D47DCu;
        WRITE8(ADD32(GPR_U32(ctx, 16), 31), (uint8_t)GPR_U32(ctx, 3));
        if (branch_taken_0x1d47d8) {
            ctx->pc = 0x1D4814u;
            goto label_1d4814;
        }
    }
    ctx->pc = 0x1D47E0u;
label_1d47e0:
    // 0x1d47e0: 0x8ea30028
    ctx->pc = 0x1d47e0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 21), 40)));
    // 0x1d47e4: 0x1000000b
    ctx->pc = 0x1D47E4u;
    {
        const bool branch_taken_0x1d47e4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D47E8u;
        WRITE8(ADD32(GPR_U32(ctx, 16), 88), (uint8_t)GPR_U32(ctx, 3));
        if (branch_taken_0x1d47e4) {
            ctx->pc = 0x1D4814u;
            goto label_1d4814;
        }
    }
    ctx->pc = 0x1D47ECu;
label_1d47ec:
    // 0x1d47ec: 0x26a50034
    ctx->pc = 0x1d47ecu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 21), 52));
    // 0x1d47f0: 0x2e0202d
    ctx->pc = 0x1d47f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d47f4: 0xc0636ec
    ctx->pc = 0x1D47F4u;
    SET_GPR_U32(ctx, 31, 0x1D47FCu);
    ctx->pc = 0x1D47F8u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x18DBB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DBB0_0x18dbb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D47FCu; }
    }
    if (ctx->pc != 0x1D47FCu) { return; }
    ctx->pc = 0x1D47FCu;
    // 0x1d47fc: 0x8ea30044
    ctx->pc = 0x1d47fcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 21), 68)));
    // 0x1d4800: 0xae03006c
    ctx->pc = 0x1d4800u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 108), GPR_U32(ctx, 3));
    // 0x1d4804: 0x8ea30028
    ctx->pc = 0x1d4804u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 21), 40)));
    // 0x1d4808: 0xa2030058
    ctx->pc = 0x1d4808u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 88), (uint8_t)GPR_U32(ctx, 3));
    // 0x1d480c: 0x8ee30000
    ctx->pc = 0x1d480cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 23), 0)));
    // 0x1d4810: 0xa603001a
    ctx->pc = 0x1d4810u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 26), (uint16_t)GPR_U32(ctx, 3));
label_1d4814:
    // 0x1d4814: 0x26520001
    ctx->pc = 0x1d4814u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 1));
label_1d4818:
    // 0x1d4818: 0x26310001
    ctx->pc = 0x1d4818u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 1));
label_1d481c:
    // 0x1d481c: 0x8fa300a0
    ctx->pc = 0x1d481cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x1d4820: 0x243182b
    ctx->pc = 0x1d4820u;
    SET_GPR_U32(ctx, 3, SLTU32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x1d4824: 0x1460ffab
    ctx->pc = 0x1D4824u;
    {
        const bool branch_taken_0x1d4824 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D4828u;
        SET_GPR_U32(ctx, 1, SLTU32(GPR_U32(ctx, 17), 64));
        if (branch_taken_0x1d4824) {
            ctx->pc = 0x1D46D4u;
            goto label_1d46d4;
        }
    }
    ctx->pc = 0x1D482Cu;
label_1d482c:
    // 0x1d482c: 0x26730001
    ctx->pc = 0x1d482cu;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 19), 1));
label_1d4830:
    // 0x1d4830: 0x27e182b
    ctx->pc = 0x1d4830u;
    SET_GPR_U32(ctx, 3, SLTU32(GPR_U32(ctx, 19), GPR_U32(ctx, 30)));
    // 0x1d4834: 0x1460ffa0
    ctx->pc = 0x1D4834u;
    {
        const bool branch_taken_0x1d4834 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D4838u;
        SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 19), 3));
        if (branch_taken_0x1d4834) {
            ctx->pc = 0x1D46B8u;
            goto label_1d46b8;
        }
    }
    ctx->pc = 0x1D483Cu;
label_1d483c:
    // 0x1d483c: 0xdfbf0090
    ctx->pc = 0x1d483cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
label_1d4840:
    // 0x1d4840: 0x7bbe0080
    ctx->pc = 0x1d4840u;
    SET_GPR_VEC(ctx, 30, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1d4844: 0x7bb70070
    ctx->pc = 0x1d4844u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1d4848: 0x7bb60060
    ctx->pc = 0x1d4848u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1d484c: 0x7bb50050
    ctx->pc = 0x1d484cu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1d4850: 0x7bb40040
    ctx->pc = 0x1d4850u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1d4854: 0x7bb30030
    ctx->pc = 0x1d4854u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d4858: 0x7bb20020
    ctx->pc = 0x1d4858u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d485c: 0x7bb10010
    ctx->pc = 0x1d485cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d4860: 0x7bb00000
    ctx->pc = 0x1d4860u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4864: 0x3e00008
    ctx->pc = 0x1D4864u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4868u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 432));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3DC0u: goto label_1d3dc0;
            case 0x1D3E3Cu: goto label_1d3e3c;
            case 0x1D3E6Cu: goto label_1d3e6c;
            case 0x1D3F00u: goto label_1d3f00;
            case 0x1D3F10u: goto label_1d3f10;
            case 0x1D3F48u: goto label_1d3f48;
            case 0x1D3F50u: goto label_1d3f50;
            case 0x1D3F54u: goto label_1d3f54;
            case 0x1D3FCCu: goto label_1d3fcc;
            case 0x1D3FECu: goto label_1d3fec;
            case 0x1D3FFCu: goto label_1d3ffc;
            case 0x1D400Cu: goto label_1d400c;
            case 0x1D407Cu: goto label_1d407c;
            case 0x1D409Cu: goto label_1d409c;
            case 0x1D40BCu: goto label_1d40bc;
            case 0x1D40E8u: goto label_1d40e8;
            case 0x1D4100u: goto label_1d4100;
            case 0x1D4114u: goto label_1d4114;
            case 0x1D415Cu: goto label_1d415c;
            case 0x1D4164u: goto label_1d4164;
            case 0x1D41ACu: goto label_1d41ac;
            case 0x1D41CCu: goto label_1d41cc;
            case 0x1D41D8u: goto label_1d41d8;
            case 0x1D4250u: goto label_1d4250;
            case 0x1D42A4u: goto label_1d42a4;
            case 0x1D42E0u: goto label_1d42e0;
            case 0x1D4308u: goto label_1d4308;
            case 0x1D4318u: goto label_1d4318;
            case 0x1D4368u: goto label_1d4368;
            case 0x1D4384u: goto label_1d4384;
            case 0x1D43C0u: goto label_1d43c0;
            case 0x1D43DCu: goto label_1d43dc;
            case 0x1D4430u: goto label_1d4430;
            case 0x1D446Cu: goto label_1d446c;
            case 0x1D4494u: goto label_1d4494;
            case 0x1D449Cu: goto label_1d449c;
            case 0x1D44F4u: goto label_1d44f4;
            case 0x1D4510u: goto label_1d4510;
            case 0x1D4548u: goto label_1d4548;
            case 0x1D4550u: goto label_1d4550;
            case 0x1D45A8u: goto label_1d45a8;
            case 0x1D45BCu: goto label_1d45bc;
            case 0x1D4678u: goto label_1d4678;
            case 0x1D46A0u: goto label_1d46a0;
            case 0x1D46B8u: goto label_1d46b8;
            case 0x1D46D4u: goto label_1d46d4;
            case 0x1D4790u: goto label_1d4790;
            case 0x1D47BCu: goto label_1d47bc;
            case 0x1D47E0u: goto label_1d47e0;
            case 0x1D47ECu: goto label_1d47ec;
            case 0x1D4814u: goto label_1d4814;
            case 0x1D4818u: goto label_1d4818;
            case 0x1D481Cu: goto label_1d481c;
            case 0x1D482Cu: goto label_1d482c;
            case 0x1D4830u: goto label_1d4830;
            case 0x1D483Cu: goto label_1d483c;
            case 0x1D4840u: goto label_1d4840;
            case 0x1D48F0u: goto label_1d48f0;
            case 0x1D4944u: goto label_1d4944;
            case 0x1D497Cu: goto label_1d497c;
            case 0x1D49B4u: goto label_1d49b4;
            case 0x1D4A3Cu: goto label_1d4a3c;
            case 0x1D4A70u: goto label_1d4a70;
            case 0x1D4AB8u: goto label_1d4ab8;
            case 0x1D4B30u: goto label_1d4b30;
            case 0x1D4B58u: goto label_1d4b58;
            case 0x1D4B94u: goto label_1d4b94;
            case 0x1D4BD8u: goto label_1d4bd8;
            case 0x1D4C18u: goto label_1d4c18;
            case 0x1D4C28u: goto label_1d4c28;
            case 0x1D4C70u: goto label_1d4c70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D486Cu;
    // 0x1d486c: 0x0
    ctx->pc = 0x1d486cu;
    // NOP
    // 0x1d4870: 0x27bdfec0
    ctx->pc = 0x1d4870u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294966976));
    // 0x1d4874: 0x3c010032
    ctx->pc = 0x1d4874u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d4878: 0xffbf0030
    ctx->pc = 0x1d4878u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1d487c: 0x7fb20020
    ctx->pc = 0x1d487cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d4880: 0x7fb10010
    ctx->pc = 0x1d4880u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d4884: 0x7fb00000
    ctx->pc = 0x1d4884u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d4888: 0x3c110032
    ctx->pc = 0x1d4888u;
    SET_GPR_U32(ctx, 17, ((uint32_t)50 << 16));
    // 0x1d488c: 0x8c32440c
    ctx->pc = 0x1d488cu;
    SET_GPR_U32(ctx, 18, READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d4890: 0x3c010032
    ctx->pc = 0x1d4890u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d4894: 0x802243d7
    ctx->pc = 0x1d4894u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 17367)));
    // 0x1d4898: 0x1440002a
    ctx->pc = 0x1D4898u;
    {
        const bool branch_taken_0x1d4898 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D489Cu;
        SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 17344));
        if (branch_taken_0x1d4898) {
            ctx->pc = 0x1D4944u;
            goto label_1d4944;
        }
    }
    ctx->pc = 0x1D48A0u;
    // 0x1d48a0: 0x9627001a
    ctx->pc = 0x1d48a0u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 26)));
    // 0x1d48a4: 0x3c050025
    ctx->pc = 0x1d48a4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d48a8: 0x9629001c
    ctx->pc = 0x1d48a8u;
    SET_GPR_U32(ctx, 9, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x1d48ac: 0x3c060025
    ctx->pc = 0x1d48acu;
    SET_GPR_U32(ctx, 6, ((uint32_t)37 << 16));
    // 0x1d48b0: 0x962a001e
    ctx->pc = 0x1d48b0u;
    SET_GPR_U32(ctx, 10, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 30)));
    // 0x1d48b4: 0x27a40040
    ctx->pc = 0x1d48b4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d48b8: 0x24a56980
    ctx->pc = 0x1d48b8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 27008));
    // 0x1d48bc: 0x24c669a0
    ctx->pc = 0x1d48bcu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 27040));
    // 0x1d48c0: 0xc042a0c
    ctx->pc = 0x1D48C0u;
    SET_GPR_U32(ctx, 31, 0x1D48C8u);
    ctx->pc = 0x1D48C4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D48C8u; }
    }
    if (ctx->pc != 0x1D48C8u) { return; }
    ctx->pc = 0x1D48C8u;
    // 0x1d48c8: 0x27b00040
    ctx->pc = 0x1d48c8u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d48cc: 0x240282d
    ctx->pc = 0x1d48ccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d48d0: 0x200202d
    ctx->pc = 0x1d48d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d48d4: 0x24060001
    ctx->pc = 0x1d48d4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d48d8: 0xc07323c
    ctx->pc = 0x1D48D8u;
    SET_GPR_U32(ctx, 31, 0x1D48E0u);
    ctx->pc = 0x1D48DCu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1CC8F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D48E0u; }
    }
    if (ctx->pc != 0x1D48E0u) { return; }
    ctx->pc = 0x1D48E0u;
    // 0x1d48e0: 0x18400003
    ctx->pc = 0x1D48E0u;
    {
        const bool branch_taken_0x1d48e0 = (GPR_S32(ctx, 2) <= 0);
        ctx->pc = 0x1D48E4u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1d48e0) {
            ctx->pc = 0x1D48F0u;
            goto label_1d48f0;
        }
    }
    ctx->pc = 0x1D48E8u;
    // 0x1d48e8: 0xc1ac7b0
    ctx->pc = 0x1D48E8u;
    SET_GPR_U32(ctx, 31, 0x1D48F0u);
    ctx->pc = 0x1D48ECu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x6B1EC0u;
    {
        auto targetFn = runtime->lookupFunction(0x6B1EC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D48F0u; }
        if (ctx->pc != 0x1D48F0u) { return; }
    }
    ctx->pc = 0x1D48F0u;
label_1d48f0:
    // 0x1d48f0: 0x9627001a
    ctx->pc = 0x1d48f0u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 26)));
    // 0x1d48f4: 0x3c050025
    ctx->pc = 0x1d48f4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d48f8: 0x9629001c
    ctx->pc = 0x1d48f8u;
    SET_GPR_U32(ctx, 9, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x1d48fc: 0x3c060025
    ctx->pc = 0x1d48fcu;
    SET_GPR_U32(ctx, 6, ((uint32_t)37 << 16));
    // 0x1d4900: 0x962a001e
    ctx->pc = 0x1d4900u;
    SET_GPR_U32(ctx, 10, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 30)));
    // 0x1d4904: 0x27a40040
    ctx->pc = 0x1d4904u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d4908: 0x24a569c0
    ctx->pc = 0x1d4908u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 27072));
    // 0x1d490c: 0x24c669e0
    ctx->pc = 0x1d490cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 27104));
    // 0x1d4910: 0xc042a0c
    ctx->pc = 0x1D4910u;
    SET_GPR_U32(ctx, 31, 0x1D4918u);
    ctx->pc = 0x1D4914u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4918u; }
    }
    if (ctx->pc != 0x1D4918u) { return; }
    ctx->pc = 0x1D4918u;
    // 0x1d4918: 0x200202d
    ctx->pc = 0x1d4918u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d491c: 0x240282d
    ctx->pc = 0x1d491cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4920: 0x24060001
    ctx->pc = 0x1d4920u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d4924: 0xc07323c
    ctx->pc = 0x1D4924u;
    SET_GPR_U32(ctx, 31, 0x1D492Cu);
    ctx->pc = 0x1D4928u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1CC8F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D492Cu; }
    }
    if (ctx->pc != 0x1D492Cu) { return; }
    ctx->pc = 0x1D492Cu;
    // 0x1d492c: 0x18400021
    ctx->pc = 0x1D492Cu;
    {
        const bool branch_taken_0x1d492c = (GPR_S32(ctx, 2) <= 0);
        ctx->pc = 0x1D4930u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1d492c) {
            ctx->pc = 0x1D49B4u;
            goto label_1d49b4;
        }
    }
    ctx->pc = 0x1D4934u;
    // 0x1d4934: 0xc1ac8f8
    ctx->pc = 0x1D4934u;
    SET_GPR_U32(ctx, 31, 0x1D493Cu);
    ctx->pc = 0x1D4938u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x6B23E0u;
    {
        auto targetFn = runtime->lookupFunction(0x6B23E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D493Cu; }
        if (ctx->pc != 0x1D493Cu) { return; }
    }
    ctx->pc = 0x1D493Cu;
    // 0x1d493c: 0x1000001d
    ctx->pc = 0x1D493Cu;
    {
        const bool branch_taken_0x1d493c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1d493c) {
            ctx->pc = 0x1D49B4u;
            goto label_1d49b4;
        }
    }
    ctx->pc = 0x1D4944u;
label_1d4944:
    // 0x1d4944: 0x9626001a
    ctx->pc = 0x1d4944u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 26)));
    // 0x1d4948: 0x3c050025
    ctx->pc = 0x1d4948u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d494c: 0x9627001c
    ctx->pc = 0x1d494cu;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x1d4950: 0x27a40040
    ctx->pc = 0x1d4950u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d4954: 0x9628001e
    ctx->pc = 0x1d4954u;
    SET_GPR_U32(ctx, 8, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 30)));
    // 0x1d4958: 0xc042a0c
    ctx->pc = 0x1D4958u;
    SET_GPR_U32(ctx, 31, 0x1D4960u);
    ctx->pc = 0x1D495Cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 27136));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4960u; }
    }
    if (ctx->pc != 0x1D4960u) { return; }
    ctx->pc = 0x1D4960u;
    // 0x1d4960: 0x27a40040
    ctx->pc = 0x1d4960u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d4964: 0xc06a8f8
    ctx->pc = 0x1D4964u;
    SET_GPR_U32(ctx, 31, 0x1D496Cu);
    ctx->pc = 0x1D4968u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1AA3E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA3E0_0x1aa3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D496Cu; }
    }
    if (ctx->pc != 0x1D496Cu) { return; }
    ctx->pc = 0x1D496Cu;
    // 0x1d496c: 0x10400003
    ctx->pc = 0x1D496Cu;
    {
        const bool branch_taken_0x1d496c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D4970u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1d496c) {
            ctx->pc = 0x1D497Cu;
            goto label_1d497c;
        }
    }
    ctx->pc = 0x1D4974u;
    // 0x1d4974: 0xc1ac7b0
    ctx->pc = 0x1D4974u;
    SET_GPR_U32(ctx, 31, 0x1D497Cu);
    ctx->pc = 0x1D4978u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x6B1EC0u;
    {
        auto targetFn = runtime->lookupFunction(0x6B1EC0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D497Cu; }
        if (ctx->pc != 0x1D497Cu) { return; }
    }
    ctx->pc = 0x1D497Cu;
label_1d497c:
    // 0x1d497c: 0x9626001a
    ctx->pc = 0x1d497cu;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 26)));
    // 0x1d4980: 0x3c050025
    ctx->pc = 0x1d4980u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d4984: 0x9627001c
    ctx->pc = 0x1d4984u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x1d4988: 0x27a40040
    ctx->pc = 0x1d4988u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d498c: 0x9628001e
    ctx->pc = 0x1d498cu;
    SET_GPR_U32(ctx, 8, (uint16_t)READ16(ADD32(GPR_U32(ctx, 17), 30)));
    // 0x1d4990: 0xc042a0c
    ctx->pc = 0x1D4990u;
    SET_GPR_U32(ctx, 31, 0x1D4998u);
    ctx->pc = 0x1D4994u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 27168));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4998u; }
    }
    if (ctx->pc != 0x1D4998u) { return; }
    ctx->pc = 0x1D4998u;
    // 0x1d4998: 0x27a40040
    ctx->pc = 0x1d4998u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 64));
    // 0x1d499c: 0xc06a8f8
    ctx->pc = 0x1D499Cu;
    SET_GPR_U32(ctx, 31, 0x1D49A4u);
    ctx->pc = 0x1D49A0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1AA3E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AA3E0_0x1aa3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D49A4u; }
    }
    if (ctx->pc != 0x1D49A4u) { return; }
    ctx->pc = 0x1D49A4u;
    // 0x1d49a4: 0x10400003
    ctx->pc = 0x1D49A4u;
    {
        const bool branch_taken_0x1d49a4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D49A8u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1d49a4) {
            ctx->pc = 0x1D49B4u;
            goto label_1d49b4;
        }
    }
    ctx->pc = 0x1D49ACu;
    // 0x1d49ac: 0xc1ac8f8
    ctx->pc = 0x1D49ACu;
    SET_GPR_U32(ctx, 31, 0x1D49B4u);
    ctx->pc = 0x1D49B0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x6B23E0u;
    {
        auto targetFn = runtime->lookupFunction(0x6B23E0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D49B4u; }
        if (ctx->pc != 0x1D49B4u) { return; }
    }
    ctx->pc = 0x1D49B4u;
label_1d49b4:
    // 0x1d49b4: 0xc1ace0c
    ctx->pc = 0x1D49B4u;
    SET_GPR_U32(ctx, 31, 0x1D49BCu);
    ctx->pc = 0x6B3830u;
    {
        auto targetFn = runtime->lookupFunction(0x6B3830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D49BCu; }
        if (ctx->pc != 0x1D49BCu) { return; }
    }
    ctx->pc = 0x1D49BCu;
    // 0x1d49bc: 0xdfbf0030
    ctx->pc = 0x1d49bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d49c0: 0x7bb20020
    ctx->pc = 0x1d49c0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d49c4: 0x7bb10010
    ctx->pc = 0x1d49c4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d49c8: 0x7bb00000
    ctx->pc = 0x1d49c8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d49cc: 0x3e00008
    ctx->pc = 0x1D49CCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D49D0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 320));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3DC0u: goto label_1d3dc0;
            case 0x1D3E3Cu: goto label_1d3e3c;
            case 0x1D3E6Cu: goto label_1d3e6c;
            case 0x1D3F00u: goto label_1d3f00;
            case 0x1D3F10u: goto label_1d3f10;
            case 0x1D3F48u: goto label_1d3f48;
            case 0x1D3F50u: goto label_1d3f50;
            case 0x1D3F54u: goto label_1d3f54;
            case 0x1D3FCCu: goto label_1d3fcc;
            case 0x1D3FECu: goto label_1d3fec;
            case 0x1D3FFCu: goto label_1d3ffc;
            case 0x1D400Cu: goto label_1d400c;
            case 0x1D407Cu: goto label_1d407c;
            case 0x1D409Cu: goto label_1d409c;
            case 0x1D40BCu: goto label_1d40bc;
            case 0x1D40E8u: goto label_1d40e8;
            case 0x1D4100u: goto label_1d4100;
            case 0x1D4114u: goto label_1d4114;
            case 0x1D415Cu: goto label_1d415c;
            case 0x1D4164u: goto label_1d4164;
            case 0x1D41ACu: goto label_1d41ac;
            case 0x1D41CCu: goto label_1d41cc;
            case 0x1D41D8u: goto label_1d41d8;
            case 0x1D4250u: goto label_1d4250;
            case 0x1D42A4u: goto label_1d42a4;
            case 0x1D42E0u: goto label_1d42e0;
            case 0x1D4308u: goto label_1d4308;
            case 0x1D4318u: goto label_1d4318;
            case 0x1D4368u: goto label_1d4368;
            case 0x1D4384u: goto label_1d4384;
            case 0x1D43C0u: goto label_1d43c0;
            case 0x1D43DCu: goto label_1d43dc;
            case 0x1D4430u: goto label_1d4430;
            case 0x1D446Cu: goto label_1d446c;
            case 0x1D4494u: goto label_1d4494;
            case 0x1D449Cu: goto label_1d449c;
            case 0x1D44F4u: goto label_1d44f4;
            case 0x1D4510u: goto label_1d4510;
            case 0x1D4548u: goto label_1d4548;
            case 0x1D4550u: goto label_1d4550;
            case 0x1D45A8u: goto label_1d45a8;
            case 0x1D45BCu: goto label_1d45bc;
            case 0x1D4678u: goto label_1d4678;
            case 0x1D46A0u: goto label_1d46a0;
            case 0x1D46B8u: goto label_1d46b8;
            case 0x1D46D4u: goto label_1d46d4;
            case 0x1D4790u: goto label_1d4790;
            case 0x1D47BCu: goto label_1d47bc;
            case 0x1D47E0u: goto label_1d47e0;
            case 0x1D47ECu: goto label_1d47ec;
            case 0x1D4814u: goto label_1d4814;
            case 0x1D4818u: goto label_1d4818;
            case 0x1D481Cu: goto label_1d481c;
            case 0x1D482Cu: goto label_1d482c;
            case 0x1D4830u: goto label_1d4830;
            case 0x1D483Cu: goto label_1d483c;
            case 0x1D4840u: goto label_1d4840;
            case 0x1D48F0u: goto label_1d48f0;
            case 0x1D4944u: goto label_1d4944;
            case 0x1D497Cu: goto label_1d497c;
            case 0x1D49B4u: goto label_1d49b4;
            case 0x1D4A3Cu: goto label_1d4a3c;
            case 0x1D4A70u: goto label_1d4a70;
            case 0x1D4AB8u: goto label_1d4ab8;
            case 0x1D4B30u: goto label_1d4b30;
            case 0x1D4B58u: goto label_1d4b58;
            case 0x1D4B94u: goto label_1d4b94;
            case 0x1D4BD8u: goto label_1d4bd8;
            case 0x1D4C18u: goto label_1d4c18;
            case 0x1D4C28u: goto label_1d4c28;
            case 0x1D4C70u: goto label_1d4c70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D49D4u;
    // 0x1d49d4: 0x0
    ctx->pc = 0x1d49d4u;
    // NOP
    // 0x1d49d8: 0x0
    ctx->pc = 0x1d49d8u;
    // NOP
    // 0x1d49dc: 0x0
    ctx->pc = 0x1d49dcu;
    // NOP
    // 0x1d49e0: 0x27bdfee0
    ctx->pc = 0x1d49e0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967008));
    // 0x1d49e4: 0x3c050025
    ctx->pc = 0x1d49e4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d49e8: 0xffbf0010
    ctx->pc = 0x1d49e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d49ec: 0x3c060025
    ctx->pc = 0x1d49ecu;
    SET_GPR_U32(ctx, 6, ((uint32_t)37 << 16));
    // 0x1d49f0: 0x7fb00000
    ctx->pc = 0x1d49f0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d49f4: 0x3c010032
    ctx->pc = 0x1d49f4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d49f8: 0x8c30446c
    ctx->pc = 0x1d49f8u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 1), 17516)));
    // 0x1d49fc: 0x27a40020
    ctx->pc = 0x1d49fcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d4a00: 0x24a56a38
    ctx->pc = 0x1d4a00u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 27192));
    // 0x1d4a04: 0x3c010032
    ctx->pc = 0x1d4a04u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d4a08: 0x942743da
    ctx->pc = 0x1d4a08u;
    SET_GPR_U32(ctx, 7, (uint16_t)READ16(ADD32(GPR_U32(ctx, 1), 17370)));
    // 0x1d4a0c: 0xc042a0c
    ctx->pc = 0x1D4A0Cu;
    SET_GPR_U32(ctx, 31, 0x1D4A14u);
    ctx->pc = 0x1D4A10u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 27216));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4A14u; }
    }
    if (ctx->pc != 0x1D4A14u) { return; }
    ctx->pc = 0x1D4A14u;
    // 0x1d4a14: 0x3c020001
    ctx->pc = 0x1d4a14u;
    SET_GPR_U32(ctx, 2, ((uint32_t)1 << 16));
    // 0x1d4a18: 0x27a40020
    ctx->pc = 0x1d4a18u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d4a1c: 0x200282d
    ctx->pc = 0x1d4a1cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4a20: 0x382d
    ctx->pc = 0x1d4a20u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4a24: 0xc07323c
    ctx->pc = 0x1D4A24u;
    SET_GPR_U32(ctx, 31, 0x1D4A2Cu);
    ctx->pc = 0x1D4A28u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 2), 1));
    ctx->pc = 0x1CC8F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4A2Cu; }
    }
    if (ctx->pc != 0x1D4A2Cu) { return; }
    ctx->pc = 0x1D4A2Cu;
    // 0x1d4a2c: 0x1c400003
    ctx->pc = 0x1D4A2Cu;
    {
        const bool branch_taken_0x1d4a2c = (GPR_S32(ctx, 2) > 0);
        if (branch_taken_0x1d4a2c) {
            ctx->pc = 0x1D4A3Cu;
            goto label_1d4a3c;
        }
    }
    ctx->pc = 0x1D4A34u;
    // 0x1d4a34: 0x2403ffff
    ctx->pc = 0x1d4a34u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1d4a38: 0xa2030000
    ctx->pc = 0x1d4a38u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
label_1d4a3c:
    // 0x1d4a3c: 0xdfbf0010
    ctx->pc = 0x1d4a3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d4a40: 0x7bb00000
    ctx->pc = 0x1d4a40u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4a44: 0x3e00008
    ctx->pc = 0x1D4A44u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4A48u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 288));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3DC0u: goto label_1d3dc0;
            case 0x1D3E3Cu: goto label_1d3e3c;
            case 0x1D3E6Cu: goto label_1d3e6c;
            case 0x1D3F00u: goto label_1d3f00;
            case 0x1D3F10u: goto label_1d3f10;
            case 0x1D3F48u: goto label_1d3f48;
            case 0x1D3F50u: goto label_1d3f50;
            case 0x1D3F54u: goto label_1d3f54;
            case 0x1D3FCCu: goto label_1d3fcc;
            case 0x1D3FECu: goto label_1d3fec;
            case 0x1D3FFCu: goto label_1d3ffc;
            case 0x1D400Cu: goto label_1d400c;
            case 0x1D407Cu: goto label_1d407c;
            case 0x1D409Cu: goto label_1d409c;
            case 0x1D40BCu: goto label_1d40bc;
            case 0x1D40E8u: goto label_1d40e8;
            case 0x1D4100u: goto label_1d4100;
            case 0x1D4114u: goto label_1d4114;
            case 0x1D415Cu: goto label_1d415c;
            case 0x1D4164u: goto label_1d4164;
            case 0x1D41ACu: goto label_1d41ac;
            case 0x1D41CCu: goto label_1d41cc;
            case 0x1D41D8u: goto label_1d41d8;
            case 0x1D4250u: goto label_1d4250;
            case 0x1D42A4u: goto label_1d42a4;
            case 0x1D42E0u: goto label_1d42e0;
            case 0x1D4308u: goto label_1d4308;
            case 0x1D4318u: goto label_1d4318;
            case 0x1D4368u: goto label_1d4368;
            case 0x1D4384u: goto label_1d4384;
            case 0x1D43C0u: goto label_1d43c0;
            case 0x1D43DCu: goto label_1d43dc;
            case 0x1D4430u: goto label_1d4430;
            case 0x1D446Cu: goto label_1d446c;
            case 0x1D4494u: goto label_1d4494;
            case 0x1D449Cu: goto label_1d449c;
            case 0x1D44F4u: goto label_1d44f4;
            case 0x1D4510u: goto label_1d4510;
            case 0x1D4548u: goto label_1d4548;
            case 0x1D4550u: goto label_1d4550;
            case 0x1D45A8u: goto label_1d45a8;
            case 0x1D45BCu: goto label_1d45bc;
            case 0x1D4678u: goto label_1d4678;
            case 0x1D46A0u: goto label_1d46a0;
            case 0x1D46B8u: goto label_1d46b8;
            case 0x1D46D4u: goto label_1d46d4;
            case 0x1D4790u: goto label_1d4790;
            case 0x1D47BCu: goto label_1d47bc;
            case 0x1D47E0u: goto label_1d47e0;
            case 0x1D47ECu: goto label_1d47ec;
            case 0x1D4814u: goto label_1d4814;
            case 0x1D4818u: goto label_1d4818;
            case 0x1D481Cu: goto label_1d481c;
            case 0x1D482Cu: goto label_1d482c;
            case 0x1D4830u: goto label_1d4830;
            case 0x1D483Cu: goto label_1d483c;
            case 0x1D4840u: goto label_1d4840;
            case 0x1D48F0u: goto label_1d48f0;
            case 0x1D4944u: goto label_1d4944;
            case 0x1D497Cu: goto label_1d497c;
            case 0x1D49B4u: goto label_1d49b4;
            case 0x1D4A3Cu: goto label_1d4a3c;
            case 0x1D4A70u: goto label_1d4a70;
            case 0x1D4AB8u: goto label_1d4ab8;
            case 0x1D4B30u: goto label_1d4b30;
            case 0x1D4B58u: goto label_1d4b58;
            case 0x1D4B94u: goto label_1d4b94;
            case 0x1D4BD8u: goto label_1d4bd8;
            case 0x1D4C18u: goto label_1d4c18;
            case 0x1D4C28u: goto label_1d4c28;
            case 0x1D4C70u: goto label_1d4c70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4A4Cu;
    // 0x1d4a4c: 0x0
    ctx->pc = 0x1d4a4cu;
    // NOP
    // 0x1d4a50: 0x27bdffd0
    ctx->pc = 0x1d4a50u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x1d4a54: 0xffbf0020
    ctx->pc = 0x1d4a54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x1d4a58: 0x7fb10010
    ctx->pc = 0x1d4a58u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d4a5c: 0xc16e8e0
    ctx->pc = 0x1D4A5Cu;
    SET_GPR_U32(ctx, 31, 0x1D4A64u);
    ctx->pc = 0x1D4A60u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    ctx->pc = 0x5BA380u;
    {
        auto targetFn = runtime->lookupFunction(0x5BA380u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4A64u; }
        if (ctx->pc != 0x1D4A64u) { return; }
    }
    ctx->pc = 0x1D4A64u;
    // 0x1d4a64: 0x3c010032
    ctx->pc = 0x1d4a64u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d4a68: 0x802d
    ctx->pc = 0x1d4a68u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4a6c: 0x8c31440c
    ctx->pc = 0x1d4a6cu;
    SET_GPR_U32(ctx, 17, READ32(ADD32(GPR_U32(ctx, 1), 17420)));
label_1d4a70:
    // 0x1d4a70: 0xc073494
    ctx->pc = 0x1D4A70u;
    SET_GPR_U32(ctx, 31, 0x1D4A78u);
    ctx->pc = 0x1D4A74u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 16384));
    ctx->pc = 0x1CD250u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD250_0x1cd250(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4A78u; }
    }
    if (ctx->pc != 0x1D4A78u) { return; }
    ctx->pc = 0x1D4A78u;
    // 0x1d4a78: 0x1440000f
    ctx->pc = 0x1D4A78u;
    {
        const bool branch_taken_0x1d4a78 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1d4a78) {
            ctx->pc = 0x1D4AB8u;
            goto label_1d4ab8;
        }
    }
    ctx->pc = 0x1D4A80u;
    // 0x1d4a80: 0x3c020023
    ctx->pc = 0x1d4a80u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x1d4a84: 0x101880
    ctx->pc = 0x1d4a84u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 16), 2));
    // 0x1d4a88: 0x244268d0
    ctx->pc = 0x1d4a88u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 26832));
    // 0x1d4a8c: 0x220282d
    ctx->pc = 0x1d4a8cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4a90: 0x431021
    ctx->pc = 0x1d4a90u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d4a94: 0x382d
    ctx->pc = 0x1d4a94u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4a98: 0x8c440000
    ctx->pc = 0x1d4a98u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d4a9c: 0x3c020001
    ctx->pc = 0x1d4a9cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)1 << 16));
    // 0x1d4aa0: 0xc07323c
    ctx->pc = 0x1D4AA0u;
    SET_GPR_U32(ctx, 31, 0x1D4AA8u);
    ctx->pc = 0x1D4AA4u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 2), 1));
    ctx->pc = 0x1CC8F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4AA8u; }
    }
    if (ctx->pc != 0x1D4AA8u) { return; }
    ctx->pc = 0x1D4AA8u;
    // 0x1d4aa8: 0x10400003
    ctx->pc = 0x1D4AA8u;
    {
        const bool branch_taken_0x1d4aa8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D4AACu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 16384));
        if (branch_taken_0x1d4aa8) {
            ctx->pc = 0x1D4AB8u;
            goto label_1d4ab8;
        }
    }
    ctx->pc = 0x1D4AB0u;
    // 0x1d4ab0: 0xc0732e4
    ctx->pc = 0x1D4AB0u;
    SET_GPR_U32(ctx, 31, 0x1D4AB8u);
    ctx->pc = 0x1D4AB4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1CCB90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCB90_0x1ccb90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4AB8u; }
    }
    if (ctx->pc != 0x1D4AB8u) { return; }
    ctx->pc = 0x1D4AB8u;
label_1d4ab8:
    // 0x1d4ab8: 0x26100001
    ctx->pc = 0x1d4ab8u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 1));
    // 0x1d4abc: 0x2a030010
    ctx->pc = 0x1d4abcu;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 16), 16));
    // 0x1d4ac0: 0x1460ffeb
    ctx->pc = 0x1D4AC0u;
    {
        const bool branch_taken_0x1d4ac0 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x1d4ac0) {
            ctx->pc = 0x1D4A70u;
            goto label_1d4a70;
        }
    }
    ctx->pc = 0x1D4AC8u;
    // 0x1d4ac8: 0xdfbf0020
    ctx->pc = 0x1d4ac8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d4acc: 0x7bb10010
    ctx->pc = 0x1d4accu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d4ad0: 0x7bb00000
    ctx->pc = 0x1d4ad0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4ad4: 0x3e00008
    ctx->pc = 0x1D4AD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4AD8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3DC0u: goto label_1d3dc0;
            case 0x1D3E3Cu: goto label_1d3e3c;
            case 0x1D3E6Cu: goto label_1d3e6c;
            case 0x1D3F00u: goto label_1d3f00;
            case 0x1D3F10u: goto label_1d3f10;
            case 0x1D3F48u: goto label_1d3f48;
            case 0x1D3F50u: goto label_1d3f50;
            case 0x1D3F54u: goto label_1d3f54;
            case 0x1D3FCCu: goto label_1d3fcc;
            case 0x1D3FECu: goto label_1d3fec;
            case 0x1D3FFCu: goto label_1d3ffc;
            case 0x1D400Cu: goto label_1d400c;
            case 0x1D407Cu: goto label_1d407c;
            case 0x1D409Cu: goto label_1d409c;
            case 0x1D40BCu: goto label_1d40bc;
            case 0x1D40E8u: goto label_1d40e8;
            case 0x1D4100u: goto label_1d4100;
            case 0x1D4114u: goto label_1d4114;
            case 0x1D415Cu: goto label_1d415c;
            case 0x1D4164u: goto label_1d4164;
            case 0x1D41ACu: goto label_1d41ac;
            case 0x1D41CCu: goto label_1d41cc;
            case 0x1D41D8u: goto label_1d41d8;
            case 0x1D4250u: goto label_1d4250;
            case 0x1D42A4u: goto label_1d42a4;
            case 0x1D42E0u: goto label_1d42e0;
            case 0x1D4308u: goto label_1d4308;
            case 0x1D4318u: goto label_1d4318;
            case 0x1D4368u: goto label_1d4368;
            case 0x1D4384u: goto label_1d4384;
            case 0x1D43C0u: goto label_1d43c0;
            case 0x1D43DCu: goto label_1d43dc;
            case 0x1D4430u: goto label_1d4430;
            case 0x1D446Cu: goto label_1d446c;
            case 0x1D4494u: goto label_1d4494;
            case 0x1D449Cu: goto label_1d449c;
            case 0x1D44F4u: goto label_1d44f4;
            case 0x1D4510u: goto label_1d4510;
            case 0x1D4548u: goto label_1d4548;
            case 0x1D4550u: goto label_1d4550;
            case 0x1D45A8u: goto label_1d45a8;
            case 0x1D45BCu: goto label_1d45bc;
            case 0x1D4678u: goto label_1d4678;
            case 0x1D46A0u: goto label_1d46a0;
            case 0x1D46B8u: goto label_1d46b8;
            case 0x1D46D4u: goto label_1d46d4;
            case 0x1D4790u: goto label_1d4790;
            case 0x1D47BCu: goto label_1d47bc;
            case 0x1D47E0u: goto label_1d47e0;
            case 0x1D47ECu: goto label_1d47ec;
            case 0x1D4814u: goto label_1d4814;
            case 0x1D4818u: goto label_1d4818;
            case 0x1D481Cu: goto label_1d481c;
            case 0x1D482Cu: goto label_1d482c;
            case 0x1D4830u: goto label_1d4830;
            case 0x1D483Cu: goto label_1d483c;
            case 0x1D4840u: goto label_1d4840;
            case 0x1D48F0u: goto label_1d48f0;
            case 0x1D4944u: goto label_1d4944;
            case 0x1D497Cu: goto label_1d497c;
            case 0x1D49B4u: goto label_1d49b4;
            case 0x1D4A3Cu: goto label_1d4a3c;
            case 0x1D4A70u: goto label_1d4a70;
            case 0x1D4AB8u: goto label_1d4ab8;
            case 0x1D4B30u: goto label_1d4b30;
            case 0x1D4B58u: goto label_1d4b58;
            case 0x1D4B94u: goto label_1d4b94;
            case 0x1D4BD8u: goto label_1d4bd8;
            case 0x1D4C18u: goto label_1d4c18;
            case 0x1D4C28u: goto label_1d4c28;
            case 0x1D4C70u: goto label_1d4c70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4ADCu;
    // 0x1d4adc: 0x0
    ctx->pc = 0x1d4adcu;
    // NOP
    // 0x1d4ae0: 0x27bdff60
    ctx->pc = 0x1d4ae0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1d4ae4: 0xc0202d
    ctx->pc = 0x1d4ae4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4ae8: 0xffbf0010
    ctx->pc = 0x1d4ae8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1d4aec: 0xc0dee54
    ctx->pc = 0x1D4AECu;
    SET_GPR_U32(ctx, 31, 0x1D4AF4u);
    ctx->pc = 0x1D4AF0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    ctx->pc = 0x37B950u;
    {
        auto targetFn = runtime->lookupFunction(0x37B950u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4AF4u; }
        if (ctx->pc != 0x1D4AF4u) { return; }
    }
    ctx->pc = 0x1D4AF4u;
    // 0x1d4af4: 0x3c050025
    ctx->pc = 0x1d4af4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d4af8: 0x40302d
    ctx->pc = 0x1d4af8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4afc: 0x27a40020
    ctx->pc = 0x1d4afcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d4b00: 0xc042a0c
    ctx->pc = 0x1D4B00u;
    SET_GPR_U32(ctx, 31, 0x1D4B08u);
    ctx->pc = 0x1D4B04u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 28048));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4B08u; }
    }
    if (ctx->pc != 0x1D4B08u) { return; }
    ctx->pc = 0x1D4B08u;
    // 0x1d4b08: 0x3c010032
    ctx->pc = 0x1d4b08u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d4b0c: 0x8c30440c
    ctx->pc = 0x1d4b0cu;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d4b10: 0xc073494
    ctx->pc = 0x1D4B10u;
    SET_GPR_U32(ctx, 31, 0x1D4B18u);
    ctx->pc = 0x1D4B14u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 16400));
    ctx->pc = 0x1CD250u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD250_0x1cd250(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4B18u; }
    }
    if (ctx->pc != 0x1D4B18u) { return; }
    ctx->pc = 0x1D4B18u;
    // 0x1d4b18: 0x10400005
    ctx->pc = 0x1D4B18u;
    {
        const bool branch_taken_0x1d4b18 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D4B1Cu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 16400));
        if (branch_taken_0x1d4b18) {
            ctx->pc = 0x1D4B30u;
            goto label_1d4b30;
        }
    }
    ctx->pc = 0x1D4B20u;
    // 0x1d4b20: 0xc073420
    ctx->pc = 0x1D4B20u;
    SET_GPR_U32(ctx, 31, 0x1D4B28u);
    ctx->pc = 0x1D4B24u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1CD080u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CD080_0x1cd080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4B28u; }
    }
    if (ctx->pc != 0x1D4B28u) { return; }
    ctx->pc = 0x1D4B28u;
    // 0x1d4b28: 0xc06372c
    ctx->pc = 0x1D4B28u;
    SET_GPR_U32(ctx, 31, 0x1D4B30u);
    ctx->pc = 0x18DCB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4B30u; }
    }
    if (ctx->pc != 0x1D4B30u) { return; }
    ctx->pc = 0x1D4B30u;
label_1d4b30:
    // 0x1d4b30: 0x3c020001
    ctx->pc = 0x1d4b30u;
    SET_GPR_U32(ctx, 2, ((uint32_t)1 << 16));
    // 0x1d4b34: 0x27a40020
    ctx->pc = 0x1d4b34u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1d4b38: 0x200282d
    ctx->pc = 0x1d4b38u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4b3c: 0x382d
    ctx->pc = 0x1d4b3cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4b40: 0xc07323c
    ctx->pc = 0x1D4B40u;
    SET_GPR_U32(ctx, 31, 0x1D4B48u);
    ctx->pc = 0x1D4B44u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 2), 1));
    ctx->pc = 0x1CC8F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4B48u; }
    }
    if (ctx->pc != 0x1D4B48u) { return; }
    ctx->pc = 0x1D4B48u;
    // 0x1d4b48: 0x10400003
    ctx->pc = 0x1D4B48u;
    {
        const bool branch_taken_0x1d4b48 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D4B4Cu;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1d4b48) {
            ctx->pc = 0x1D4B58u;
            goto label_1d4b58;
        }
    }
    ctx->pc = 0x1D4B50u;
    // 0x1d4b50: 0xc0732e4
    ctx->pc = 0x1D4B50u;
    SET_GPR_U32(ctx, 31, 0x1D4B58u);
    ctx->pc = 0x1D4B54u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 16400));
    ctx->pc = 0x1CCB90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCB90_0x1ccb90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4B58u; }
    }
    if (ctx->pc != 0x1D4B58u) { return; }
    ctx->pc = 0x1D4B58u;
label_1d4b58:
    // 0x1d4b58: 0xdfbf0010
    ctx->pc = 0x1d4b58u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d4b5c: 0x7bb00000
    ctx->pc = 0x1d4b5cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4b60: 0x3e00008
    ctx->pc = 0x1D4B60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4B64u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 160));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3DC0u: goto label_1d3dc0;
            case 0x1D3E3Cu: goto label_1d3e3c;
            case 0x1D3E6Cu: goto label_1d3e6c;
            case 0x1D3F00u: goto label_1d3f00;
            case 0x1D3F10u: goto label_1d3f10;
            case 0x1D3F48u: goto label_1d3f48;
            case 0x1D3F50u: goto label_1d3f50;
            case 0x1D3F54u: goto label_1d3f54;
            case 0x1D3FCCu: goto label_1d3fcc;
            case 0x1D3FECu: goto label_1d3fec;
            case 0x1D3FFCu: goto label_1d3ffc;
            case 0x1D400Cu: goto label_1d400c;
            case 0x1D407Cu: goto label_1d407c;
            case 0x1D409Cu: goto label_1d409c;
            case 0x1D40BCu: goto label_1d40bc;
            case 0x1D40E8u: goto label_1d40e8;
            case 0x1D4100u: goto label_1d4100;
            case 0x1D4114u: goto label_1d4114;
            case 0x1D415Cu: goto label_1d415c;
            case 0x1D4164u: goto label_1d4164;
            case 0x1D41ACu: goto label_1d41ac;
            case 0x1D41CCu: goto label_1d41cc;
            case 0x1D41D8u: goto label_1d41d8;
            case 0x1D4250u: goto label_1d4250;
            case 0x1D42A4u: goto label_1d42a4;
            case 0x1D42E0u: goto label_1d42e0;
            case 0x1D4308u: goto label_1d4308;
            case 0x1D4318u: goto label_1d4318;
            case 0x1D4368u: goto label_1d4368;
            case 0x1D4384u: goto label_1d4384;
            case 0x1D43C0u: goto label_1d43c0;
            case 0x1D43DCu: goto label_1d43dc;
            case 0x1D4430u: goto label_1d4430;
            case 0x1D446Cu: goto label_1d446c;
            case 0x1D4494u: goto label_1d4494;
            case 0x1D449Cu: goto label_1d449c;
            case 0x1D44F4u: goto label_1d44f4;
            case 0x1D4510u: goto label_1d4510;
            case 0x1D4548u: goto label_1d4548;
            case 0x1D4550u: goto label_1d4550;
            case 0x1D45A8u: goto label_1d45a8;
            case 0x1D45BCu: goto label_1d45bc;
            case 0x1D4678u: goto label_1d4678;
            case 0x1D46A0u: goto label_1d46a0;
            case 0x1D46B8u: goto label_1d46b8;
            case 0x1D46D4u: goto label_1d46d4;
            case 0x1D4790u: goto label_1d4790;
            case 0x1D47BCu: goto label_1d47bc;
            case 0x1D47E0u: goto label_1d47e0;
            case 0x1D47ECu: goto label_1d47ec;
            case 0x1D4814u: goto label_1d4814;
            case 0x1D4818u: goto label_1d4818;
            case 0x1D481Cu: goto label_1d481c;
            case 0x1D482Cu: goto label_1d482c;
            case 0x1D4830u: goto label_1d4830;
            case 0x1D483Cu: goto label_1d483c;
            case 0x1D4840u: goto label_1d4840;
            case 0x1D48F0u: goto label_1d48f0;
            case 0x1D4944u: goto label_1d4944;
            case 0x1D497Cu: goto label_1d497c;
            case 0x1D49B4u: goto label_1d49b4;
            case 0x1D4A3Cu: goto label_1d4a3c;
            case 0x1D4A70u: goto label_1d4a70;
            case 0x1D4AB8u: goto label_1d4ab8;
            case 0x1D4B30u: goto label_1d4b30;
            case 0x1D4B58u: goto label_1d4b58;
            case 0x1D4B94u: goto label_1d4b94;
            case 0x1D4BD8u: goto label_1d4bd8;
            case 0x1D4C18u: goto label_1d4c18;
            case 0x1D4C28u: goto label_1d4c28;
            case 0x1D4C70u: goto label_1d4c70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4B68u;
    // 0x1d4b68: 0x0
    ctx->pc = 0x1d4b68u;
    // NOP
    // 0x1d4b6c: 0x0
    ctx->pc = 0x1d4b6cu;
    // NOP
    // 0x1d4b70: 0x27bdffc0
    ctx->pc = 0x1d4b70u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1d4b74: 0x3c010032
    ctx->pc = 0x1d4b74u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1d4b78: 0xffbf0030
    ctx->pc = 0x1d4b78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1d4b7c: 0x7fb20020
    ctx->pc = 0x1d4b7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1d4b80: 0x7fb10010
    ctx->pc = 0x1d4b80u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1d4b84: 0x7fb00000
    ctx->pc = 0x1d4b84u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1d4b88: 0x882d
    ctx->pc = 0x1d4b88u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4b8c: 0x8c32440c
    ctx->pc = 0x1d4b8cu;
    SET_GPR_U32(ctx, 18, READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1d4b90: 0xc0802d
    ctx->pc = 0x1d4b90u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_1d4b94:
    // 0x1d4b94: 0x82030000
    ctx->pc = 0x1d4b94u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1d4b98: 0x460000f
    ctx->pc = 0x1D4B98u;
    {
        const bool branch_taken_0x1d4b98 = (GPR_S32(ctx, 3) < 0);
        if (branch_taken_0x1d4b98) {
            ctx->pc = 0x1D4BD8u;
            goto label_1d4bd8;
        }
    }
    ctx->pc = 0x1D4BA0u;
    // 0x1d4ba0: 0x3c020023
    ctx->pc = 0x1d4ba0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x1d4ba4: 0x31880
    ctx->pc = 0x1d4ba4u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 2));
    // 0x1d4ba8: 0x24426910
    ctx->pc = 0x1d4ba8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 26896));
    // 0x1d4bac: 0x240282d
    ctx->pc = 0x1d4bacu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4bb0: 0x431021
    ctx->pc = 0x1d4bb0u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1d4bb4: 0x382d
    ctx->pc = 0x1d4bb4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4bb8: 0x8c440000
    ctx->pc = 0x1d4bb8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1d4bbc: 0x3c020001
    ctx->pc = 0x1d4bbcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)1 << 16));
    // 0x1d4bc0: 0xc07323c
    ctx->pc = 0x1D4BC0u;
    SET_GPR_U32(ctx, 31, 0x1D4BC8u);
    ctx->pc = 0x1D4BC4u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 2), 1));
    ctx->pc = 0x1CC8F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CC8F0_0x1cc8f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4BC8u; }
    }
    if (ctx->pc != 0x1D4BC8u) { return; }
    ctx->pc = 0x1D4BC8u;
    // 0x1d4bc8: 0x10400003
    ctx->pc = 0x1D4BC8u;
    {
        const bool branch_taken_0x1d4bc8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1D4BCCu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 17), 16401));
        if (branch_taken_0x1d4bc8) {
            ctx->pc = 0x1D4BD8u;
            goto label_1d4bd8;
        }
    }
    ctx->pc = 0x1D4BD0u;
    // 0x1d4bd0: 0xc0732e4
    ctx->pc = 0x1D4BD0u;
    SET_GPR_U32(ctx, 31, 0x1D4BD8u);
    ctx->pc = 0x1D4BD4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1CCB90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001CCB90_0x1ccb90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4BD8u; }
    }
    if (ctx->pc != 0x1D4BD8u) { return; }
    ctx->pc = 0x1D4BD8u;
label_1d4bd8:
    // 0x1d4bd8: 0x26310001
    ctx->pc = 0x1d4bd8u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 1));
    // 0x1d4bdc: 0x2a230004
    ctx->pc = 0x1d4bdcu;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 17), 4));
    // 0x1d4be0: 0x1460ffec
    ctx->pc = 0x1D4BE0u;
    {
        const bool branch_taken_0x1d4be0 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x1D4BE4u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 1));
        if (branch_taken_0x1d4be0) {
            ctx->pc = 0x1D4B94u;
            goto label_1d4b94;
        }
    }
    ctx->pc = 0x1D4BE8u;
    // 0x1d4be8: 0xdfbf0030
    ctx->pc = 0x1d4be8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1d4bec: 0x7bb20020
    ctx->pc = 0x1d4becu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1d4bf0: 0x7bb10010
    ctx->pc = 0x1d4bf0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1d4bf4: 0x7bb00000
    ctx->pc = 0x1d4bf4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4bf8: 0x3e00008
    ctx->pc = 0x1D4BF8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4BFCu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3DC0u: goto label_1d3dc0;
            case 0x1D3E3Cu: goto label_1d3e3c;
            case 0x1D3E6Cu: goto label_1d3e6c;
            case 0x1D3F00u: goto label_1d3f00;
            case 0x1D3F10u: goto label_1d3f10;
            case 0x1D3F48u: goto label_1d3f48;
            case 0x1D3F50u: goto label_1d3f50;
            case 0x1D3F54u: goto label_1d3f54;
            case 0x1D3FCCu: goto label_1d3fcc;
            case 0x1D3FECu: goto label_1d3fec;
            case 0x1D3FFCu: goto label_1d3ffc;
            case 0x1D400Cu: goto label_1d400c;
            case 0x1D407Cu: goto label_1d407c;
            case 0x1D409Cu: goto label_1d409c;
            case 0x1D40BCu: goto label_1d40bc;
            case 0x1D40E8u: goto label_1d40e8;
            case 0x1D4100u: goto label_1d4100;
            case 0x1D4114u: goto label_1d4114;
            case 0x1D415Cu: goto label_1d415c;
            case 0x1D4164u: goto label_1d4164;
            case 0x1D41ACu: goto label_1d41ac;
            case 0x1D41CCu: goto label_1d41cc;
            case 0x1D41D8u: goto label_1d41d8;
            case 0x1D4250u: goto label_1d4250;
            case 0x1D42A4u: goto label_1d42a4;
            case 0x1D42E0u: goto label_1d42e0;
            case 0x1D4308u: goto label_1d4308;
            case 0x1D4318u: goto label_1d4318;
            case 0x1D4368u: goto label_1d4368;
            case 0x1D4384u: goto label_1d4384;
            case 0x1D43C0u: goto label_1d43c0;
            case 0x1D43DCu: goto label_1d43dc;
            case 0x1D4430u: goto label_1d4430;
            case 0x1D446Cu: goto label_1d446c;
            case 0x1D4494u: goto label_1d4494;
            case 0x1D449Cu: goto label_1d449c;
            case 0x1D44F4u: goto label_1d44f4;
            case 0x1D4510u: goto label_1d4510;
            case 0x1D4548u: goto label_1d4548;
            case 0x1D4550u: goto label_1d4550;
            case 0x1D45A8u: goto label_1d45a8;
            case 0x1D45BCu: goto label_1d45bc;
            case 0x1D4678u: goto label_1d4678;
            case 0x1D46A0u: goto label_1d46a0;
            case 0x1D46B8u: goto label_1d46b8;
            case 0x1D46D4u: goto label_1d46d4;
            case 0x1D4790u: goto label_1d4790;
            case 0x1D47BCu: goto label_1d47bc;
            case 0x1D47E0u: goto label_1d47e0;
            case 0x1D47ECu: goto label_1d47ec;
            case 0x1D4814u: goto label_1d4814;
            case 0x1D4818u: goto label_1d4818;
            case 0x1D481Cu: goto label_1d481c;
            case 0x1D482Cu: goto label_1d482c;
            case 0x1D4830u: goto label_1d4830;
            case 0x1D483Cu: goto label_1d483c;
            case 0x1D4840u: goto label_1d4840;
            case 0x1D48F0u: goto label_1d48f0;
            case 0x1D4944u: goto label_1d4944;
            case 0x1D497Cu: goto label_1d497c;
            case 0x1D49B4u: goto label_1d49b4;
            case 0x1D4A3Cu: goto label_1d4a3c;
            case 0x1D4A70u: goto label_1d4a70;
            case 0x1D4AB8u: goto label_1d4ab8;
            case 0x1D4B30u: goto label_1d4b30;
            case 0x1D4B58u: goto label_1d4b58;
            case 0x1D4B94u: goto label_1d4b94;
            case 0x1D4BD8u: goto label_1d4bd8;
            case 0x1D4C18u: goto label_1d4c18;
            case 0x1D4C28u: goto label_1d4c28;
            case 0x1D4C70u: goto label_1d4c70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4C00u;
    // 0x1d4c00: 0x27bdfff0
    ctx->pc = 0x1d4c00u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1d4c04: 0x3c040025
    ctx->pc = 0x1d4c04u;
    SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
    // 0x1d4c08: 0xffbf0000
    ctx->pc = 0x1d4c08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d4c0c: 0x24846db0
    ctx->pc = 0x1d4c0cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 28080));
    // 0x1d4c10: 0xc074f70
    ctx->pc = 0x1D4C10u;
    SET_GPR_U32(ctx, 31, 0x1D4C18u);
    ctx->pc = 0x1D4C14u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1D3DC0u;
    goto label_1d3dc0;
    ctx->pc = 0x1D4C18u;
label_1d4c18:
    // 0x1d4c18: 0x3c040025
    ctx->pc = 0x1d4c18u;
    SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
    // 0x1d4c1c: 0x2405000c
    ctx->pc = 0x1d4c1cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 12));
    // 0x1d4c20: 0xc074f70
    ctx->pc = 0x1D4C20u;
    SET_GPR_U32(ctx, 31, 0x1D4C28u);
    ctx->pc = 0x1D4C24u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 28088));
    ctx->pc = 0x1D3DC0u;
    goto label_1d3dc0;
    ctx->pc = 0x1D4C28u;
label_1d4c28:
    // 0x1d4c28: 0xdfbf0000
    ctx->pc = 0x1d4c28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4c2c: 0x3e00008
    ctx->pc = 0x1D4C2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4C30u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3DC0u: goto label_1d3dc0;
            case 0x1D3E3Cu: goto label_1d3e3c;
            case 0x1D3E6Cu: goto label_1d3e6c;
            case 0x1D3F00u: goto label_1d3f00;
            case 0x1D3F10u: goto label_1d3f10;
            case 0x1D3F48u: goto label_1d3f48;
            case 0x1D3F50u: goto label_1d3f50;
            case 0x1D3F54u: goto label_1d3f54;
            case 0x1D3FCCu: goto label_1d3fcc;
            case 0x1D3FECu: goto label_1d3fec;
            case 0x1D3FFCu: goto label_1d3ffc;
            case 0x1D400Cu: goto label_1d400c;
            case 0x1D407Cu: goto label_1d407c;
            case 0x1D409Cu: goto label_1d409c;
            case 0x1D40BCu: goto label_1d40bc;
            case 0x1D40E8u: goto label_1d40e8;
            case 0x1D4100u: goto label_1d4100;
            case 0x1D4114u: goto label_1d4114;
            case 0x1D415Cu: goto label_1d415c;
            case 0x1D4164u: goto label_1d4164;
            case 0x1D41ACu: goto label_1d41ac;
            case 0x1D41CCu: goto label_1d41cc;
            case 0x1D41D8u: goto label_1d41d8;
            case 0x1D4250u: goto label_1d4250;
            case 0x1D42A4u: goto label_1d42a4;
            case 0x1D42E0u: goto label_1d42e0;
            case 0x1D4308u: goto label_1d4308;
            case 0x1D4318u: goto label_1d4318;
            case 0x1D4368u: goto label_1d4368;
            case 0x1D4384u: goto label_1d4384;
            case 0x1D43C0u: goto label_1d43c0;
            case 0x1D43DCu: goto label_1d43dc;
            case 0x1D4430u: goto label_1d4430;
            case 0x1D446Cu: goto label_1d446c;
            case 0x1D4494u: goto label_1d4494;
            case 0x1D449Cu: goto label_1d449c;
            case 0x1D44F4u: goto label_1d44f4;
            case 0x1D4510u: goto label_1d4510;
            case 0x1D4548u: goto label_1d4548;
            case 0x1D4550u: goto label_1d4550;
            case 0x1D45A8u: goto label_1d45a8;
            case 0x1D45BCu: goto label_1d45bc;
            case 0x1D4678u: goto label_1d4678;
            case 0x1D46A0u: goto label_1d46a0;
            case 0x1D46B8u: goto label_1d46b8;
            case 0x1D46D4u: goto label_1d46d4;
            case 0x1D4790u: goto label_1d4790;
            case 0x1D47BCu: goto label_1d47bc;
            case 0x1D47E0u: goto label_1d47e0;
            case 0x1D47ECu: goto label_1d47ec;
            case 0x1D4814u: goto label_1d4814;
            case 0x1D4818u: goto label_1d4818;
            case 0x1D481Cu: goto label_1d481c;
            case 0x1D482Cu: goto label_1d482c;
            case 0x1D4830u: goto label_1d4830;
            case 0x1D483Cu: goto label_1d483c;
            case 0x1D4840u: goto label_1d4840;
            case 0x1D48F0u: goto label_1d48f0;
            case 0x1D4944u: goto label_1d4944;
            case 0x1D497Cu: goto label_1d497c;
            case 0x1D49B4u: goto label_1d49b4;
            case 0x1D4A3Cu: goto label_1d4a3c;
            case 0x1D4A70u: goto label_1d4a70;
            case 0x1D4AB8u: goto label_1d4ab8;
            case 0x1D4B30u: goto label_1d4b30;
            case 0x1D4B58u: goto label_1d4b58;
            case 0x1D4B94u: goto label_1d4b94;
            case 0x1D4BD8u: goto label_1d4bd8;
            case 0x1D4C18u: goto label_1d4c18;
            case 0x1D4C28u: goto label_1d4c28;
            case 0x1D4C70u: goto label_1d4c70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4C34u;
    // 0x1d4c34: 0x0
    ctx->pc = 0x1d4c34u;
    // NOP
    // 0x1d4c38: 0x0
    ctx->pc = 0x1d4c38u;
    // NOP
    // 0x1d4c3c: 0x0
    ctx->pc = 0x1d4c3cu;
    // NOP
    // 0x1d4c40: 0x27bdff70
    ctx->pc = 0x1d4c40u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x1d4c44: 0xffbf0000
    ctx->pc = 0x1d4c44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1d4c48: 0xc0dee54
    ctx->pc = 0x1D4C48u;
    SET_GPR_U32(ctx, 31, 0x1D4C50u);
    ctx->pc = 0x37B950u;
    {
        auto targetFn = runtime->lookupFunction(0x37B950u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4C50u; }
        if (ctx->pc != 0x1D4C50u) { return; }
    }
    ctx->pc = 0x1D4C50u;
    // 0x1d4c50: 0x3c050025
    ctx->pc = 0x1d4c50u;
    SET_GPR_U32(ctx, 5, ((uint32_t)37 << 16));
    // 0x1d4c54: 0x40302d
    ctx->pc = 0x1d4c54u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4c58: 0x27a40010
    ctx->pc = 0x1d4c58u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 16));
    // 0x1d4c5c: 0xc042a0c
    ctx->pc = 0x1D4C5Cu;
    SET_GPR_U32(ctx, 31, 0x1D4C64u);
    ctx->pc = 0x1D4C60u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 28096));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4C64u; }
    }
    if (ctx->pc != 0x1D4C64u) { return; }
    ctx->pc = 0x1D4C64u;
    // 0x1d4c64: 0x27a40010
    ctx->pc = 0x1d4c64u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 16));
    // 0x1d4c68: 0xc074f70
    ctx->pc = 0x1D4C68u;
    SET_GPR_U32(ctx, 31, 0x1D4C70u);
    ctx->pc = 0x1D4C6Cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 12));
    ctx->pc = 0x1D3DC0u;
    goto label_1d3dc0;
    ctx->pc = 0x1D4C70u;
label_1d4c70:
    // 0x1d4c70: 0x24040001
    ctx->pc = 0x1d4c70u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1d4c74: 0x24050004
    ctx->pc = 0x1d4c74u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4));
    // 0x1d4c78: 0x24062500
    ctx->pc = 0x1d4c78u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 9472));
    // 0x1d4c7c: 0x382d
    ctx->pc = 0x1d4c7cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1d4c80: 0xc06b3e0
    ctx->pc = 0x1D4C80u;
    SET_GPR_U32(ctx, 31, 0x1D4C88u);
    ctx->pc = 0x1D4C84u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1ACF80u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001ACF80_0x1acf80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4C88u; }
    }
    if (ctx->pc != 0x1D4C88u) { return; }
    ctx->pc = 0x1D4C88u;
    // 0x1d4c88: 0xdfbf0000
    ctx->pc = 0x1d4c88u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1d4c8c: 0x3e00008
    ctx->pc = 0x1D4C8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4C90u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 144));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D3DC0u: goto label_1d3dc0;
            case 0x1D3E3Cu: goto label_1d3e3c;
            case 0x1D3E6Cu: goto label_1d3e6c;
            case 0x1D3F00u: goto label_1d3f00;
            case 0x1D3F10u: goto label_1d3f10;
            case 0x1D3F48u: goto label_1d3f48;
            case 0x1D3F50u: goto label_1d3f50;
            case 0x1D3F54u: goto label_1d3f54;
            case 0x1D3FCCu: goto label_1d3fcc;
            case 0x1D3FECu: goto label_1d3fec;
            case 0x1D3FFCu: goto label_1d3ffc;
            case 0x1D400Cu: goto label_1d400c;
            case 0x1D407Cu: goto label_1d407c;
            case 0x1D409Cu: goto label_1d409c;
            case 0x1D40BCu: goto label_1d40bc;
            case 0x1D40E8u: goto label_1d40e8;
            case 0x1D4100u: goto label_1d4100;
            case 0x1D4114u: goto label_1d4114;
            case 0x1D415Cu: goto label_1d415c;
            case 0x1D4164u: goto label_1d4164;
            case 0x1D41ACu: goto label_1d41ac;
            case 0x1D41CCu: goto label_1d41cc;
            case 0x1D41D8u: goto label_1d41d8;
            case 0x1D4250u: goto label_1d4250;
            case 0x1D42A4u: goto label_1d42a4;
            case 0x1D42E0u: goto label_1d42e0;
            case 0x1D4308u: goto label_1d4308;
            case 0x1D4318u: goto label_1d4318;
            case 0x1D4368u: goto label_1d4368;
            case 0x1D4384u: goto label_1d4384;
            case 0x1D43C0u: goto label_1d43c0;
            case 0x1D43DCu: goto label_1d43dc;
            case 0x1D4430u: goto label_1d4430;
            case 0x1D446Cu: goto label_1d446c;
            case 0x1D4494u: goto label_1d4494;
            case 0x1D449Cu: goto label_1d449c;
            case 0x1D44F4u: goto label_1d44f4;
            case 0x1D4510u: goto label_1d4510;
            case 0x1D4548u: goto label_1d4548;
            case 0x1D4550u: goto label_1d4550;
            case 0x1D45A8u: goto label_1d45a8;
            case 0x1D45BCu: goto label_1d45bc;
            case 0x1D4678u: goto label_1d4678;
            case 0x1D46A0u: goto label_1d46a0;
            case 0x1D46B8u: goto label_1d46b8;
            case 0x1D46D4u: goto label_1d46d4;
            case 0x1D4790u: goto label_1d4790;
            case 0x1D47BCu: goto label_1d47bc;
            case 0x1D47E0u: goto label_1d47e0;
            case 0x1D47ECu: goto label_1d47ec;
            case 0x1D4814u: goto label_1d4814;
            case 0x1D4818u: goto label_1d4818;
            case 0x1D481Cu: goto label_1d481c;
            case 0x1D482Cu: goto label_1d482c;
            case 0x1D4830u: goto label_1d4830;
            case 0x1D483Cu: goto label_1d483c;
            case 0x1D4840u: goto label_1d4840;
            case 0x1D48F0u: goto label_1d48f0;
            case 0x1D4944u: goto label_1d4944;
            case 0x1D497Cu: goto label_1d497c;
            case 0x1D49B4u: goto label_1d49b4;
            case 0x1D4A3Cu: goto label_1d4a3c;
            case 0x1D4A70u: goto label_1d4a70;
            case 0x1D4AB8u: goto label_1d4ab8;
            case 0x1D4B30u: goto label_1d4b30;
            case 0x1D4B58u: goto label_1d4b58;
            case 0x1D4B94u: goto label_1d4b94;
            case 0x1D4BD8u: goto label_1d4bd8;
            case 0x1D4C18u: goto label_1d4c18;
            case 0x1D4C28u: goto label_1d4c28;
            case 0x1D4C70u: goto label_1d4c70;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4C94u;
    // 0x1d4c94: 0x0
    ctx->pc = 0x1d4c94u;
    // NOP
    // 0x1d4c98: 0x0
    ctx->pc = 0x1d4c98u;
    // NOP
    // 0x1d4c9c: 0x0
    ctx->pc = 0x1d4c9cu;
    // NOP
}
