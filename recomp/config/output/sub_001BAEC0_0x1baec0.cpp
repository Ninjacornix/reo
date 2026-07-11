#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001BAEC0
// Address: 0x1baec0 - 0x1bb110
void sub_001BAEC0_0x1baec0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1baec0u;

    // 0x1baec0: 0x27bdfff0
    ctx->pc = 0x1baec0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1baec4: 0xffbf0000
    ctx->pc = 0x1baec4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1baec8: 0xc06a470
    ctx->pc = 0x1BAEC8u;
    SET_GPR_U32(ctx, 31, 0x1BAED0u);
    ctx->pc = 0x1BAECCu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1A91C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A91C0_0x1a91c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAED0u; }
    }
    if (ctx->pc != 0x1BAED0u) { return; }
    ctx->pc = 0x1BAED0u;
    // 0x1baed0: 0x3c010032
    ctx->pc = 0x1baed0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1baed4: 0xc06c2a0
    ctx->pc = 0x1BAED4u;
    SET_GPR_U32(ctx, 31, 0x1BAEDCu);
    ctx->pc = 0x1BAED8u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 17600), (uint16_t)GPR_U32(ctx, 0));
    ctx->pc = 0x1B0A80u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001B0A80_0x1b0a80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAEDCu; }
    }
    if (ctx->pc != 0x1BAEDCu) { return; }
    ctx->pc = 0x1BAEDCu;
    // 0x1baedc: 0xc06baf8
    ctx->pc = 0x1BAEDCu;
    SET_GPR_U32(ctx, 31, 0x1BAEE4u);
    ctx->pc = 0x1AEBE0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEBE0_0x1aebe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAEE4u; }
    }
    if (ctx->pc != 0x1BAEE4u) { return; }
    ctx->pc = 0x1BAEE4u;
    // 0x1baee4: 0x3c010032
    ctx->pc = 0x1baee4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1baee8: 0xc06be40
    ctx->pc = 0x1BAEE8u;
    SET_GPR_U32(ctx, 31, 0x1BAEF0u);
    ctx->pc = 0x1BAEECu;
    WRITE16(ADD32(GPR_U32(ctx, 1), 16888), (uint16_t)GPR_U32(ctx, 0));
    ctx->pc = 0x1AF900u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF900_0x1af900(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAEF0u; }
    }
    if (ctx->pc != 0x1BAEF0u) { return; }
    ctx->pc = 0x1BAEF0u;
    // 0x1baef0: 0xc06833c
    ctx->pc = 0x1BAEF0u;
    SET_GPR_U32(ctx, 31, 0x1BAEF8u);
    ctx->pc = 0x1BAEF4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1A0CF0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A0CF0_0x1a0cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAEF8u; }
    }
    if (ctx->pc != 0x1BAEF8u) { return; }
    ctx->pc = 0x1BAEF8u;
    // 0x1baef8: 0x3c040031
    ctx->pc = 0x1baef8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)49 << 16));
    // 0x1baefc: 0xc06bde8
    ctx->pc = 0x1BAEFCu;
    SET_GPR_U32(ctx, 31, 0x1BAF04u);
    ctx->pc = 0x1BAF00u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 26016));
    ctx->pc = 0x1AF7A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF7A0_0x1af7a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAF04u; }
    }
    if (ctx->pc != 0x1BAF04u) { return; }
    ctx->pc = 0x1BAF04u;
    // 0x1baf04: 0xc06bdc4
    ctx->pc = 0x1BAF04u;
    SET_GPR_U32(ctx, 31, 0x1BAF0Cu);
    ctx->pc = 0x1BAF08u;
    SET_GPR_U32(ctx, 4, ((uint32_t)92 << 16));
    ctx->pc = 0x1AF710u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF710_0x1af710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAF0Cu; }
    }
    if (ctx->pc != 0x1BAF0Cu) { return; }
    ctx->pc = 0x1BAF0Cu;
    // 0x1baf0c: 0x3c010032
    ctx->pc = 0x1baf0cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1baf10: 0x282d
    ctx->pc = 0x1baf10u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1baf14: 0xac224410
    ctx->pc = 0x1baf14u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17424), GPR_U32(ctx, 2));
    // 0x1baf18: 0x3c010032
    ctx->pc = 0x1baf18u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1baf1c: 0x8c244410
    ctx->pc = 0x1baf1cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 1), 17424)));
    // 0x1baf20: 0xc041f1a
    ctx->pc = 0x1BAF20u;
    SET_GPR_U32(ctx, 31, 0x1BAF28u);
    ctx->pc = 0x1BAF24u;
    SET_GPR_U32(ctx, 6, ((uint32_t)92 << 16));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAF28u; }
    }
    if (ctx->pc != 0x1BAF28u) { return; }
    ctx->pc = 0x1BAF28u;
    // 0x1baf28: 0x3c010032
    ctx->pc = 0x1baf28u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1baf2c: 0x3c050024
    ctx->pc = 0x1baf2cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x1baf30: 0x8c224410
    ctx->pc = 0x1baf30u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 17424)));
    // 0x1baf34: 0x3c010032
    ctx->pc = 0x1baf34u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1baf38: 0xac224408
    ctx->pc = 0x1baf38u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17416), GPR_U32(ctx, 2));
    // 0x1baf3c: 0x451021
    ctx->pc = 0x1baf3cu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1baf40: 0x3c010032
    ctx->pc = 0x1baf40u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1baf44: 0xac22440c
    ctx->pc = 0x1baf44u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17420), GPR_U32(ctx, 2));
    // 0x1baf48: 0x3c010032
    ctx->pc = 0x1baf48u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1baf4c: 0xc06be44
    ctx->pc = 0x1BAF4Cu;
    SET_GPR_U32(ctx, 31, 0x1BAF54u);
    ctx->pc = 0x1BAF50u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 1), 17416)));
    ctx->pc = 0x1AF910u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF910_0x1af910(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAF54u; }
    }
    if (ctx->pc != 0x1BAF54u) { return; }
    ctx->pc = 0x1BAF54u;
    // 0x1baf54: 0x3c020003
    ctx->pc = 0x1baf54u;
    SET_GPR_U32(ctx, 2, ((uint32_t)3 << 16));
    // 0x1baf58: 0xc06be5c
    ctx->pc = 0x1BAF58u;
    SET_GPR_U32(ctx, 31, 0x1BAF60u);
    ctx->pc = 0x1BAF5Cu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 2), 49152));
    ctx->pc = 0x1AF970u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF970_0x1af970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAF60u; }
    }
    if (ctx->pc != 0x1BAF60u) { return; }
    ctx->pc = 0x1BAF60u;
    // 0x1baf60: 0x3c010032
    ctx->pc = 0x1baf60u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1baf64: 0xac224454
    ctx->pc = 0x1baf64u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17492), GPR_U32(ctx, 2));
    // 0x1baf68: 0x3c010032
    ctx->pc = 0x1baf68u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1baf6c: 0xc068340
    ctx->pc = 0x1BAF6Cu;
    SET_GPR_U32(ctx, 31, 0x1BAF74u);
    ctx->pc = 0x1BAF70u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 1), 17492)));
    ctx->pc = 0x1A0D00u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A0D00_0x1a0d00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAF74u; }
    }
    if (ctx->pc != 0x1BAF74u) { return; }
    ctx->pc = 0x1BAF74u;
    // 0x1baf74: 0xc06be5c
    ctx->pc = 0x1BAF74u;
    SET_GPR_U32(ctx, 31, 0x1BAF7Cu);
    ctx->pc = 0x1BAF78u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 0), 49152));
    ctx->pc = 0x1AF970u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF970_0x1af970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAF7Cu; }
    }
    if (ctx->pc != 0x1BAF7Cu) { return; }
    ctx->pc = 0x1BAF7Cu;
    // 0x1baf7c: 0x3c010032
    ctx->pc = 0x1baf7cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1baf80: 0x3404c000
    ctx->pc = 0x1baf80u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 0), 49152));
    // 0x1baf84: 0xc06be5c
    ctx->pc = 0x1BAF84u;
    SET_GPR_U32(ctx, 31, 0x1BAF8Cu);
    ctx->pc = 0x1BAF88u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17480), GPR_U32(ctx, 2));
    ctx->pc = 0x1AF970u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF970_0x1af970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAF8Cu; }
    }
    if (ctx->pc != 0x1BAF8Cu) { return; }
    ctx->pc = 0x1BAF8Cu;
    // 0x1baf8c: 0x3c010032
    ctx->pc = 0x1baf8cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1baf90: 0xac22444c
    ctx->pc = 0x1baf90u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17484), GPR_U32(ctx, 2));
    // 0x1baf94: 0x3c020001
    ctx->pc = 0x1baf94u;
    SET_GPR_U32(ctx, 2, ((uint32_t)1 << 16));
    // 0x1baf98: 0xc06be5c
    ctx->pc = 0x1BAF98u;
    SET_GPR_U32(ctx, 31, 0x1BAFA0u);
    ctx->pc = 0x1BAF9Cu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 2), 32768));
    ctx->pc = 0x1AF970u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF970_0x1af970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAFA0u; }
    }
    if (ctx->pc != 0x1BAFA0u) { return; }
    ctx->pc = 0x1BAFA0u;
    // 0x1bafa0: 0x3c010032
    ctx->pc = 0x1bafa0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bafa4: 0x3c040002
    ctx->pc = 0x1bafa4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)2 << 16));
    // 0x1bafa8: 0xc06be5c
    ctx->pc = 0x1BAFA8u;
    SET_GPR_U32(ctx, 31, 0x1BAFB0u);
    ctx->pc = 0x1BAFACu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17444), GPR_U32(ctx, 2));
    ctx->pc = 0x1AF970u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF970_0x1af970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAFB0u; }
    }
    if (ctx->pc != 0x1BAFB0u) { return; }
    ctx->pc = 0x1BAFB0u;
    // 0x1bafb0: 0x3c010032
    ctx->pc = 0x1bafb0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bafb4: 0xac22442c
    ctx->pc = 0x1bafb4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17452), GPR_U32(ctx, 2));
    // 0x1bafb8: 0x3c020001
    ctx->pc = 0x1bafb8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)1 << 16));
    // 0x1bafbc: 0xc06be5c
    ctx->pc = 0x1BAFBCu;
    SET_GPR_U32(ctx, 31, 0x1BAFC4u);
    ctx->pc = 0x1BAFC0u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 2), 32768));
    ctx->pc = 0x1AF970u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF970_0x1af970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAFC4u; }
    }
    if (ctx->pc != 0x1BAFC4u) { return; }
    ctx->pc = 0x1BAFC4u;
    // 0x1bafc4: 0x3c010032
    ctx->pc = 0x1bafc4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bafc8: 0x3c040001
    ctx->pc = 0x1bafc8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)1 << 16));
    // 0x1bafcc: 0xc06be5c
    ctx->pc = 0x1BAFCCu;
    SET_GPR_U32(ctx, 31, 0x1BAFD4u);
    ctx->pc = 0x1BAFD0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17500), GPR_U32(ctx, 2));
    ctx->pc = 0x1AF970u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF970_0x1af970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAFD4u; }
    }
    if (ctx->pc != 0x1BAFD4u) { return; }
    ctx->pc = 0x1BAFD4u;
    // 0x1bafd4: 0x3c010032
    ctx->pc = 0x1bafd4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bafd8: 0x3c040001
    ctx->pc = 0x1bafd8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)1 << 16));
    // 0x1bafdc: 0xc06be5c
    ctx->pc = 0x1BAFDCu;
    SET_GPR_U32(ctx, 31, 0x1BAFE4u);
    ctx->pc = 0x1BAFE0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17516), GPR_U32(ctx, 2));
    ctx->pc = 0x1AF970u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF970_0x1af970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAFE4u; }
    }
    if (ctx->pc != 0x1BAFE4u) { return; }
    ctx->pc = 0x1BAFE4u;
    // 0x1bafe4: 0x3c010032
    ctx->pc = 0x1bafe4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bafe8: 0x3c040008
    ctx->pc = 0x1bafe8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)8 << 16));
    // 0x1bafec: 0xc06be5c
    ctx->pc = 0x1BAFECu;
    SET_GPR_U32(ctx, 31, 0x1BAFF4u);
    ctx->pc = 0x1BAFF0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17468), GPR_U32(ctx, 2));
    ctx->pc = 0x1AF970u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF970_0x1af970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BAFF4u; }
    }
    if (ctx->pc != 0x1BAFF4u) { return; }
    ctx->pc = 0x1BAFF4u;
    // 0x1baff4: 0x3c010032
    ctx->pc = 0x1baff4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1baff8: 0x3c040001
    ctx->pc = 0x1baff8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)1 << 16));
    // 0x1baffc: 0xc06be5c
    ctx->pc = 0x1BAFFCu;
    SET_GPR_U32(ctx, 31, 0x1BB004u);
    ctx->pc = 0x1BB000u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17448), GPR_U32(ctx, 2));
    ctx->pc = 0x1AF970u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF970_0x1af970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB004u; }
    }
    if (ctx->pc != 0x1BB004u) { return; }
    ctx->pc = 0x1BB004u;
    // 0x1bb004: 0x3c010032
    ctx->pc = 0x1bb004u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bb008: 0xac224444
    ctx->pc = 0x1bb008u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17476), GPR_U32(ctx, 2));
    // 0x1bb00c: 0x3c020001
    ctx->pc = 0x1bb00cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)1 << 16));
    // 0x1bb010: 0xc06be5c
    ctx->pc = 0x1BB010u;
    SET_GPR_U32(ctx, 31, 0x1BB018u);
    ctx->pc = 0x1BB014u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 2), 32768));
    ctx->pc = 0x1AF970u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF970_0x1af970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB018u; }
    }
    if (ctx->pc != 0x1BB018u) { return; }
    ctx->pc = 0x1BB018u;
    // 0x1bb018: 0x3c010032
    ctx->pc = 0x1bb018u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bb01c: 0x3c040008
    ctx->pc = 0x1bb01cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)8 << 16));
    // 0x1bb020: 0xc06be5c
    ctx->pc = 0x1BB020u;
    SET_GPR_U32(ctx, 31, 0x1BB028u);
    ctx->pc = 0x1BB024u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17520), GPR_U32(ctx, 2));
    ctx->pc = 0x1AF970u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF970_0x1af970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB028u; }
    }
    if (ctx->pc != 0x1BB028u) { return; }
    ctx->pc = 0x1BB028u;
    // 0x1bb028: 0x3c010032
    ctx->pc = 0x1bb028u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bb02c: 0x24044000
    ctx->pc = 0x1bb02cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 16384));
    // 0x1bb030: 0xc06be5c
    ctx->pc = 0x1BB030u;
    SET_GPR_U32(ctx, 31, 0x1BB038u);
    ctx->pc = 0x1BB034u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17464), GPR_U32(ctx, 2));
    ctx->pc = 0x1AF970u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF970_0x1af970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB038u; }
    }
    if (ctx->pc != 0x1BB038u) { return; }
    ctx->pc = 0x1BB038u;
    // 0x1bb038: 0x3c010032
    ctx->pc = 0x1bb038u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bb03c: 0x3404c000
    ctx->pc = 0x1bb03cu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 0), 49152));
    // 0x1bb040: 0xc06be5c
    ctx->pc = 0x1BB040u;
    SET_GPR_U32(ctx, 31, 0x1BB048u);
    ctx->pc = 0x1BB044u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17496), GPR_U32(ctx, 2));
    ctx->pc = 0x1AF970u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF970_0x1af970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB048u; }
    }
    if (ctx->pc != 0x1BB048u) { return; }
    ctx->pc = 0x1BB048u;
    // 0x1bb048: 0x3c010032
    ctx->pc = 0x1bb048u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bb04c: 0x24045400
    ctx->pc = 0x1bb04cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 21504));
    // 0x1bb050: 0xc06be5c
    ctx->pc = 0x1BB050u;
    SET_GPR_U32(ctx, 31, 0x1BB058u);
    ctx->pc = 0x1BB054u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17508), GPR_U32(ctx, 2));
    ctx->pc = 0x1AF970u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AF970_0x1af970(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB058u; }
    }
    if (ctx->pc != 0x1BB058u) { return; }
    ctx->pc = 0x1BB058u;
    // 0x1bb058: 0x3c010032
    ctx->pc = 0x1bb058u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bb05c: 0x3c03000a
    ctx->pc = 0x1bb05cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)10 << 16));
    // 0x1bb060: 0xac224468
    ctx->pc = 0x1bb060u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17512), GPR_U32(ctx, 2));
    // 0x1bb064: 0x3c050018
    ctx->pc = 0x1bb064u;
    SET_GPR_U32(ctx, 5, ((uint32_t)24 << 16));
    // 0x1bb068: 0x3c010032
    ctx->pc = 0x1bb068u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bb06c: 0x3c020011
    ctx->pc = 0x1bb06cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)17 << 16));
    // 0x1bb070: 0x8c274424
    ctx->pc = 0x1bb070u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 1), 17444)));
    // 0x1bb074: 0x3444003f
    ctx->pc = 0x1bb074u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 2), 63));
    // 0x1bb078: 0x3c010032
    ctx->pc = 0x1bb078u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bb07c: 0x24e27fff
    ctx->pc = 0x1bb07cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 7), 32767));
    // 0x1bb080: 0x8c26440c
    ctx->pc = 0x1bb080u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 1), 17420)));
    // 0x1bb084: 0x24470001
    ctx->pc = 0x1bb084u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 2), 1));
    // 0x1bb088: 0x3c010032
    ctx->pc = 0x1bb088u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bb08c: 0xc31021
    ctx->pc = 0x1bb08cu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x1bb090: 0xac274434
    ctx->pc = 0x1bb090u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17460), GPR_U32(ctx, 7));
    // 0x1bb094: 0x3c010032
    ctx->pc = 0x1bb094u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bb098: 0xac264420
    ctx->pc = 0x1bb098u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17440), GPR_U32(ctx, 6));
    // 0x1bb09c: 0x3c010032
    ctx->pc = 0x1bb09cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bb0a0: 0xac224440
    ctx->pc = 0x1bb0a0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17472), GPR_U32(ctx, 2));
    // 0x1bb0a4: 0x3c010032
    ctx->pc = 0x1bb0a4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bb0a8: 0x8c224420
    ctx->pc = 0x1bb0a8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 17440)));
    // 0x1bb0ac: 0x451021
    ctx->pc = 0x1bb0acu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x1bb0b0: 0x3c010032
    ctx->pc = 0x1bb0b0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bb0b4: 0xc041bb8
    ctx->pc = 0x1BB0B4u;
    SET_GPR_U32(ctx, 31, 0x1BB0BCu);
    ctx->pc = 0x1BB0B8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17456), GPR_U32(ctx, 2));
    ctx->pc = 0x106EE0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00106EE0_0x106ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB0BCu; }
    }
    if (ctx->pc != 0x1BB0BCu) { return; }
    ctx->pc = 0x1BB0BCu;
    // 0x1bb0bc: 0x2443003f
    ctx->pc = 0x1bb0bcu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 2), 63));
    // 0x1bb0c0: 0x3c010032
    ctx->pc = 0x1bb0c0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bb0c4: 0x2402ffc0
    ctx->pc = 0x1bb0c4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967232));
    // 0x1bb0c8: 0x621824
    ctx->pc = 0x1bb0c8u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1bb0cc: 0x8c224440
    ctx->pc = 0x1bb0ccu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 17472)));
    // 0x1bb0d0: 0x3c010032
    ctx->pc = 0x1bb0d0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bb0d4: 0xac234460
    ctx->pc = 0x1bb0d4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17504), GPR_U32(ctx, 3));
    // 0x1bb0d8: 0x3c010001
    ctx->pc = 0x1bb0d8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)1 << 16));
    // 0x1bb0dc: 0x34218000
    ctx->pc = 0x1bb0dcu;
    SET_GPR_U32(ctx, 1, OR32(GPR_U32(ctx, 1), 32768));
    // 0x1bb0e0: 0x411021
    ctx->pc = 0x1bb0e0u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 1)));
    // 0x1bb0e4: 0x3c010032
    ctx->pc = 0x1bb0e4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bb0e8: 0xc06bbc0
    ctx->pc = 0x1BB0E8u;
    SET_GPR_U32(ctx, 31, 0x1BB0F0u);
    ctx->pc = 0x1BB0ECu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17488), GPR_U32(ctx, 2));
    ctx->pc = 0x1AEF00u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AEF00_0x1aef00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB0F0u; }
    }
    if (ctx->pc != 0x1BB0F0u) { return; }
    ctx->pc = 0x1BB0F0u;
    // 0x1bb0f0: 0xc06ecac
    ctx->pc = 0x1BB0F0u;
    SET_GPR_U32(ctx, 31, 0x1BB0F8u);
    ctx->pc = 0x1BB2B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001BB2B0_0x1bb2b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB0F8u; }
    }
    if (ctx->pc != 0x1BB0F8u) { return; }
    ctx->pc = 0x1BB0F8u;
    // 0x1bb0f8: 0xc07dc58
    ctx->pc = 0x1BB0F8u;
    SET_GPR_U32(ctx, 31, 0x1BB100u);
    ctx->pc = 0x1F7160u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001F7160_0x1f7160(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BB100u; }
    }
    if (ctx->pc != 0x1BB100u) { return; }
    ctx->pc = 0x1BB100u;
    // 0x1bb100: 0xdfbf0000
    ctx->pc = 0x1bb100u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bb104: 0x3e00008
    ctx->pc = 0x1BB104u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BB108u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        return;
    }
    ctx->pc = 0x1BB10Cu;
    // 0x1bb10c: 0x0
    ctx->pc = 0x1bb10cu;
    // NOP
}
