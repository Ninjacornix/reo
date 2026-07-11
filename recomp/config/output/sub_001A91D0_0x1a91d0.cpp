#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001A91D0
// Address: 0x1a91d0 - 0x1a9400
void sub_001A91D0_0x1a91d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1a91d0u;

    // 0x1a91d0: 0x27bdfd50
    ctx->pc = 0x1a91d0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294966608));
    // 0x1a91d4: 0xffbf0010
    ctx->pc = 0x1a91d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1a91d8: 0xc0409fc
    ctx->pc = 0x1A91D8u;
    SET_GPR_U32(ctx, 31, 0x1A91E0u);
    ctx->pc = 0x1A91DCu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    ctx->pc = 0x1027F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001027F0_0x1027f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A91E0u; }
    }
    if (ctx->pc != 0x1A91E0u) { return; }
    ctx->pc = 0x1A91E0u;
    // 0x1a91e0: 0xc040ac8
    ctx->pc = 0x1A91E0u;
    SET_GPR_U32(ctx, 31, 0x1A91E8u);
    ctx->pc = 0x102B20u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00102B20_0x102b20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A91E8u; }
    }
    if (ctx->pc != 0x1A91E8u) { return; }
    ctx->pc = 0x1A91E8u;
    // 0x1a91e8: 0xc040786
    ctx->pc = 0x1A91E8u;
    SET_GPR_U32(ctx, 31, 0x1A91F0u);
    ctx->pc = 0x101E18u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00101E18_0x101e18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A91F0u; }
    }
    if (ctx->pc != 0x1A91F0u) { return; }
    ctx->pc = 0x1A91F0u;
    // 0x1a91f0: 0xc0408d4
    ctx->pc = 0x1A91F0u;
    SET_GPR_U32(ctx, 31, 0x1A91F8u);
    ctx->pc = 0x102350u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00102350_0x102350(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A91F8u; }
    }
    if (ctx->pc != 0x1A91F8u) { return; }
    ctx->pc = 0x1A91F8u;
    // 0x1a91f8: 0xc0449c2
    ctx->pc = 0x1A91F8u;
    SET_GPR_U32(ctx, 31, 0x1A9200u);
    ctx->pc = 0x112708u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00112708_0x112708(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9200u; }
    }
    if (ctx->pc != 0x1A9200u) { return; }
    ctx->pc = 0x1A9200u;
    // 0x1a9200: 0xc040c22
    ctx->pc = 0x1A9200u;
    SET_GPR_U32(ctx, 31, 0x1A9208u);
    ctx->pc = 0x1A9204u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x103088u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00103088_0x103088(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9208u; }
    }
    if (ctx->pc != 0x1A9208u) { return; }
    ctx->pc = 0x1A9208u;
    // 0x1a9208: 0x3c040100
    ctx->pc = 0x1a9208u;
    SET_GPR_U32(ctx, 4, ((uint32_t)256 << 16));
    // 0x1a920c: 0x282d
    ctx->pc = 0x1a920cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9210: 0xc041f1a
    ctx->pc = 0x1A9210u;
    SET_GPR_U32(ctx, 31, 0x1A9218u);
    ctx->pc = 0x1A9214u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4 << 16));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9218u; }
    }
    if (ctx->pc != 0x1A9218u) { return; }
    ctx->pc = 0x1A9218u;
    // 0x1a9218: 0x802d
    ctx->pc = 0x1a9218u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a921c: 0x101180
    ctx->pc = 0x1a921cu;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 16), 6));
label_1a9220:
    // 0x1a9220: 0x27a40020
    ctx->pc = 0x1a9220u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1a9224: 0x24c3c
    ctx->pc = 0x1a9224u;
    SET_GPR_U64(ctx, 9, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1a9228: 0x282d
    ctx->pc = 0x1a9228u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a922c: 0x94c3f
    ctx->pc = 0x1a922cu;
    SET_GPR_S64(ctx, 9, GPR_S64(ctx, 9) >> (32 + 16));
    // 0x1a9230: 0x24060010
    ctx->pc = 0x1a9230u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 16));
    // 0x1a9234: 0x382d
    ctx->pc = 0x1a9234u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9238: 0x402d
    ctx->pc = 0x1a9238u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a923c: 0x240a0400
    ctx->pc = 0x1a923cu;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 0), 1024));
    // 0x1a9240: 0xc044de8
    ctx->pc = 0x1A9240u;
    SET_GPR_U32(ctx, 31, 0x1A9248u);
    ctx->pc = 0x1A9244u;
    SET_GPR_S32(ctx, 11, ADD32(GPR_U32(ctx, 0), 64));
    ctx->pc = 0x1137A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001137A0_0x1137a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9248u; }
    }
    if (ctx->pc != 0x1A9248u) { return; }
    ctx->pc = 0x1A9248u;
    // 0x1a9248: 0xc045228
    ctx->pc = 0x1A9248u;
    SET_GPR_U32(ctx, 31, 0x1A9250u);
    ctx->pc = 0x1A924Cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1148A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9250u; }
    }
    if (ctx->pc != 0x1A9250u) { return; }
    ctx->pc = 0x1A9250u;
    // 0x1a9250: 0x27a40020
    ctx->pc = 0x1a9250u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1a9254: 0xc044e62
    ctx->pc = 0x1A9254u;
    SET_GPR_U32(ctx, 31, 0x1A925Cu);
    ctx->pc = 0x1A9258u;
    SET_GPR_U32(ctx, 5, ((uint32_t)256 << 16));
    ctx->pc = 0x113988u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00113988_0x113988(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A925Cu; }
    }
    if (ctx->pc != 0x1A925Cu) { return; }
    ctx->pc = 0x1A925Cu;
    // 0x1a925c: 0x202d
    ctx->pc = 0x1a925cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9260: 0xc044d22
    ctx->pc = 0x1A9260u;
    SET_GPR_U32(ctx, 31, 0x1A9268u);
    ctx->pc = 0x1A9264u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x113488u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00113488_0x113488(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9268u; }
    }
    if (ctx->pc != 0x1A9268u) { return; }
    ctx->pc = 0x1A9268u;
    // 0x1a9268: 0x26100001
    ctx->pc = 0x1a9268u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 1));
    // 0x1a926c: 0x2a020010
    ctx->pc = 0x1a926cu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 16), 16));
    // 0x1a9270: 0x1440ffeb
    ctx->pc = 0x1A9270u;
    {
        const bool branch_taken_0x1a9270 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1A9274u;
        SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 16), 6));
        if (branch_taken_0x1a9270) {
            ctx->pc = 0x1A9220u;
            goto label_1a9220;
        }
    }
    ctx->pc = 0x1A9278u;
    // 0x1a9278: 0x202d
    ctx->pc = 0x1a9278u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a927c: 0x24050001
    ctx->pc = 0x1a927cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1a9280: 0x24060002
    ctx->pc = 0x1a9280u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 2));
    // 0x1a9284: 0xc04495a
    ctx->pc = 0x1A9284u;
    SET_GPR_U32(ctx, 31, 0x1A928Cu);
    ctx->pc = 0x1A9288u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x112568u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00112568_0x112568(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A928Cu; }
    }
    if (ctx->pc != 0x1A928Cu) { return; }
    ctx->pc = 0x1A928Cu;
    // 0x1a928c: 0x802d
    ctx->pc = 0x1a928cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a9290:
    // 0x1a9290: 0xc044cfc
    ctx->pc = 0x1A9290u;
    SET_GPR_U32(ctx, 31, 0x1A9298u);
    ctx->pc = 0x1A9294u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1133F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001133F0_0x1133f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9298u; }
    }
    if (ctx->pc != 0x1A9298u) { return; }
    ctx->pc = 0x1A9298u;
    // 0x1a9298: 0x26100001
    ctx->pc = 0x1a9298u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 1));
    // 0x1a929c: 0x2a020014
    ctx->pc = 0x1a929cu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 16), 20));
    // 0x1a92a0: 0x0
    ctx->pc = 0x1a92a0u;
    // NOP
    // 0x1a92a4: 0x1440fffa
    ctx->pc = 0x1A92A4u;
    {
        const bool branch_taken_0x1a92a4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1a92a4) {
            ctx->pc = 0x1A9290u;
            goto label_1a9290;
        }
    }
    ctx->pc = 0x1A92ACu;
    // 0x1a92ac: 0x27a40080
    ctx->pc = 0x1a92acu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 128));
    // 0x1a92b0: 0x282d
    ctx->pc = 0x1a92b0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a92b4: 0x24060280
    ctx->pc = 0x1a92b4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 640));
    // 0x1a92b8: 0x240701c0
    ctx->pc = 0x1a92b8u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 448));
    // 0x1a92bc: 0x402d
    ctx->pc = 0x1a92bcu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a92c0: 0x482d
    ctx->pc = 0x1a92c0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a92c4: 0xc044c3e
    ctx->pc = 0x1A92C4u;
    SET_GPR_U32(ctx, 31, 0x1A92CCu);
    ctx->pc = 0x1A92C8u;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1130F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001130F8_0x1130f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A92CCu; }
    }
    if (ctx->pc != 0x1A92CCu) { return; }
    ctx->pc = 0x1A92CCu;
    // 0x1a92cc: 0x97a300e0
    ctx->pc = 0x1a92ccu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 224)));
    // 0x1a92d0: 0x2404fe00
    ctx->pc = 0x1a92d0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4294966784));
    // 0x1a92d4: 0x97a200b8
    ctx->pc = 0x1a92d4u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x1a92d8: 0x6405008c
    ctx->pc = 0x1a92d8u;
    SET_GPR_S64(ctx, 5, (int64_t)GPR_S64(ctx, 0) + (int64_t)140);
    // 0x1a92dc: 0x641824
    ctx->pc = 0x1a92dcu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1a92e0: 0x651825
    ctx->pc = 0x1a92e0u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1a92e4: 0x441024
    ctx->pc = 0x1a92e4u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x1a92e8: 0xa7a300e0
    ctx->pc = 0x1a92e8u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 224), (uint16_t)GPR_U32(ctx, 3));
    // 0x1a92ec: 0x306301ff
    ctx->pc = 0x1a92ecu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), 511));
    // 0x1a92f0: 0x431025
    ctx->pc = 0x1a92f0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1a92f4: 0xa7a200b8
    ctx->pc = 0x1a92f4u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 184), (uint16_t)GPR_U32(ctx, 2));
label_1a92f8:
    // 0x1a92f8: 0xc044cfc
    ctx->pc = 0x1A92F8u;
    SET_GPR_U32(ctx, 31, 0x1A9300u);
    ctx->pc = 0x1A92FCu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1133F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001133F0_0x1133f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9300u; }
    }
    if (ctx->pc != 0x1A9300u) { return; }
    ctx->pc = 0x1A9300u;
    // 0x1a9300: 0x2102b
    ctx->pc = 0x1a9300u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x1a9304: 0x38420001
    ctx->pc = 0x1a9304u;
    SET_GPR_U32(ctx, 2, XOR32(GPR_U32(ctx, 2), 1));
    // 0x1a9308: 0x0
    ctx->pc = 0x1a9308u;
    // NOP
    // 0x1a930c: 0x1440fffa
    ctx->pc = 0x1A930Cu;
    {
        const bool branch_taken_0x1a930c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1a930c) {
            ctx->pc = 0x1A92F8u;
            goto label_1a92f8;
        }
    }
    ctx->pc = 0x1A9314u;
    // 0x1a9314: 0x202d
    ctx->pc = 0x1a9314u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9318: 0xc044d22
    ctx->pc = 0x1A9318u;
    SET_GPR_U32(ctx, 31, 0x1A9320u);
    ctx->pc = 0x1A931Cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x113488u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00113488_0x113488(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9320u; }
    }
    if (ctx->pc != 0x1A9320u) { return; }
    ctx->pc = 0x1A9320u;
    // 0x1a9320: 0x3c080023
    ctx->pc = 0x1a9320u;
    SET_GPR_U32(ctx, 8, ((uint32_t)35 << 16));
    // 0x1a9324: 0x3c090023
    ctx->pc = 0x1a9324u;
    SET_GPR_U32(ctx, 9, ((uint32_t)35 << 16));
    // 0x1a9328: 0x250811d0
    ctx->pc = 0x1a9328u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 4560));
    // 0x1a932c: 0x25291210
    ctx->pc = 0x1a932cu;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 9), 4624));
    // 0x1a9330: 0x3c070100
    ctx->pc = 0x1a9330u;
    SET_GPR_U32(ctx, 7, ((uint32_t)256 << 16));
    // 0x1a9334: 0x302d
    ctx->pc = 0x1a9334u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1a9338:
    // 0x1a9338: 0x91250000
    ctx->pc = 0x1a9338u;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 9), 0)));
    // 0x1a933c: 0x24c60001
    ctx->pc = 0x1a933cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 1));
    // 0x1a9340: 0x28c21000
    ctx->pc = 0x1a9340u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 6), 4096));
    // 0x1a9344: 0x51903
    ctx->pc = 0x1a9344u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 5), 4));
    // 0x1a9348: 0x25290001
    ctx->pc = 0x1a9348u;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 9), 1));
    // 0x1a934c: 0x306400ff
    ctx->pc = 0x1a934cu;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 3), 255));
    // 0x1a9350: 0x42080
    ctx->pc = 0x1a9350u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 2));
    // 0x1a9354: 0x30a3000f
    ctx->pc = 0x1a9354u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 5), 15));
    // 0x1a9358: 0x1042021
    ctx->pc = 0x1a9358u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 4)));
    // 0x1a935c: 0x31880
    ctx->pc = 0x1a935cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 2));
    // 0x1a9360: 0x8c840000
    ctx->pc = 0x1a9360u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1a9364: 0x1031821
    ctx->pc = 0x1a9364u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x1a9368: 0xace40000
    ctx->pc = 0x1a9368u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
    // 0x1a936c: 0x8c630000
    ctx->pc = 0x1a936cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1a9370: 0xace30004
    ctx->pc = 0x1a9370u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 4), GPR_U32(ctx, 3));
    // 0x1a9374: 0x1440fff0
    ctx->pc = 0x1A9374u;
    {
        const bool branch_taken_0x1a9374 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1A9378u;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 8));
        if (branch_taken_0x1a9374) {
            ctx->pc = 0x1A9338u;
            goto label_1a9338;
        }
    }
    ctx->pc = 0x1A937Cu;
    // 0x1a937c: 0x27a40020
    ctx->pc = 0x1a937cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1a9380: 0x282d
    ctx->pc = 0x1a9380u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a9384: 0x2406000a
    ctx->pc = 0x1a9384u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 10));
    // 0x1a9388: 0x382d
    ctx->pc = 0x1a9388u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a938c: 0x24080010
    ctx->pc = 0x1a938cu;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 16));
    // 0x1a9390: 0x24090190
    ctx->pc = 0x1a9390u;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 0), 400));
    // 0x1a9394: 0x240a0100
    ctx->pc = 0x1a9394u;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 0), 256));
    // 0x1a9398: 0xc044de8
    ctx->pc = 0x1A9398u;
    SET_GPR_U32(ctx, 31, 0x1A93A0u);
    ctx->pc = 0x1A939Cu;
    SET_GPR_S32(ctx, 11, ADD32(GPR_U32(ctx, 0), 32));
    ctx->pc = 0x1137A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001137A0_0x1137a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93A0u; }
    }
    if (ctx->pc != 0x1A93A0u) { return; }
    ctx->pc = 0x1A93A0u;
    // 0x1a93a0: 0xc045228
    ctx->pc = 0x1A93A0u;
    SET_GPR_U32(ctx, 31, 0x1A93A8u);
    ctx->pc = 0x1A93A4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1148A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93A8u; }
    }
    if (ctx->pc != 0x1A93A8u) { return; }
    ctx->pc = 0x1A93A8u;
    // 0x1a93a8: 0x27a40080
    ctx->pc = 0x1a93a8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 128));
    // 0x1a93ac: 0xc044ce4
    ctx->pc = 0x1A93ACu;
    SET_GPR_U32(ctx, 31, 0x1A93B4u);
    ctx->pc = 0x1A93B0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x113390u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00113390_0x113390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93B4u; }
    }
    if (ctx->pc != 0x1A93B4u) { return; }
    ctx->pc = 0x1A93B4u;
    // 0x1a93b4: 0x27a40020
    ctx->pc = 0x1a93b4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 32));
    // 0x1a93b8: 0xc044e62
    ctx->pc = 0x1A93B8u;
    SET_GPR_U32(ctx, 31, 0x1A93C0u);
    ctx->pc = 0x1A93BCu;
    SET_GPR_U32(ctx, 5, ((uint32_t)256 << 16));
    ctx->pc = 0x113988u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00113988_0x113988(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93C0u; }
    }
    if (ctx->pc != 0x1A93C0u) { return; }
    ctx->pc = 0x1A93C0u;
    // 0x1a93c0: 0xc044cfc
    ctx->pc = 0x1A93C0u;
    SET_GPR_U32(ctx, 31, 0x1A93C8u);
    ctx->pc = 0x1A93C4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1133F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001133F0_0x1133f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93C8u; }
    }
    if (ctx->pc != 0x1A93C8u) { return; }
    ctx->pc = 0x1A93C8u;
    // 0x1a93c8: 0xc045228
    ctx->pc = 0x1A93C8u;
    SET_GPR_U32(ctx, 31, 0x1A93D0u);
    ctx->pc = 0x1A93CCu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1148A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93D0u; }
    }
    if (ctx->pc != 0x1A93D0u) { return; }
    ctx->pc = 0x1A93D0u;
    // 0x1a93d0: 0x202d
    ctx->pc = 0x1a93d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1a93d4: 0xc044d22
    ctx->pc = 0x1A93D4u;
    SET_GPR_U32(ctx, 31, 0x1A93DCu);
    ctx->pc = 0x1A93D8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x113488u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00113488_0x113488(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93DCu; }
    }
    if (ctx->pc != 0x1A93DCu) { return; }
    ctx->pc = 0x1A93DCu;
    // 0x1a93dc: 0x27a40080
    ctx->pc = 0x1a93dcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 128));
    // 0x1a93e0: 0xc044ce4
    ctx->pc = 0x1A93E0u;
    SET_GPR_U32(ctx, 31, 0x1A93E8u);
    ctx->pc = 0x1A93E4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x113390u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00113390_0x113390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A93E8u; }
    }
    if (ctx->pc != 0x1A93E8u) { return; }
    ctx->pc = 0x1A93E8u;
    // 0x1a93e8: 0xdfbf0010
    ctx->pc = 0x1a93e8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1a93ec: 0x7bb00000
    ctx->pc = 0x1a93ecu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1a93f0: 0x3e00008
    ctx->pc = 0x1A93F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A93F4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 688));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A9220u: goto label_1a9220;
            case 0x1A9290u: goto label_1a9290;
            case 0x1A92F8u: goto label_1a92f8;
            case 0x1A9338u: goto label_1a9338;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A93F8u;
    // 0x1a93f8: 0x0
    ctx->pc = 0x1a93f8u;
    // NOP
    // 0x1a93fc: 0x0
    ctx->pc = 0x1a93fcu;
    // NOP
}
