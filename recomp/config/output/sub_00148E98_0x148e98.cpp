#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00148E98
// Address: 0x148e98 - 0x1491c8
void sub_00148E98_0x148e98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x148e98u;

    // 0x148e98: 0x27bdffa0
    ctx->pc = 0x148e98u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x148e9c: 0x24020002
    ctx->pc = 0x148e9cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
    // 0x148ea0: 0xffb20040
    ctx->pc = 0x148ea0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x148ea4: 0xffb10030
    ctx->pc = 0x148ea4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 17));
    // 0x148ea8: 0xa0902d
    ctx->pc = 0x148ea8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148eac: 0xffb00020
    ctx->pc = 0x148eacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
    // 0x148eb0: 0x80882d
    ctx->pc = 0x148eb0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148eb4: 0xffbf0050
    ctx->pc = 0x148eb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x148eb8: 0xc0802d
    ctx->pc = 0x148eb8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148ebc: 0x3a0282d
    ctx->pc = 0x148ebcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148ec0: 0x8e240870
    ctx->pc = 0x148ec0u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 2160)));
    // 0x148ec4: 0xc051fda
    ctx->pc = 0x148EC4u;
    SET_GPR_U32(ctx, 31, 0x148ECCu);
    ctx->pc = 0x148EC8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x147F68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F68_0x147f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148ECCu; }
    }
    if (ctx->pc != 0x148ECCu) { return; }
    ctx->pc = 0x148ECCu;
    // 0x148ecc: 0xc051496
    ctx->pc = 0x148ECCu;
    SET_GPR_U32(ctx, 31, 0x148ED4u);
    ctx->pc = 0x148ED0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x145258u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148ED4u; }
    }
    if (ctx->pc != 0x148ED4u) { return; }
    ctx->pc = 0x148ED4u;
    // 0x148ed4: 0x3c021000
    ctx->pc = 0x148ed4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x148ed8: 0x220202d
    ctx->pc = 0x148ed8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148edc: 0x34422000
    ctx->pc = 0x148edcu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8192));
    // 0x148ee0: 0xc051496
    ctx->pc = 0x148EE0u;
    SET_GPR_U32(ctx, 31, 0x148EE8u);
    ctx->pc = 0x148EE4u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0));
    ctx->pc = 0x145258u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148EE8u; }
    }
    if (ctx->pc != 0x148EE8u) { return; }
    ctx->pc = 0x148EE8u;
    // 0x148ee8: 0xc047598
    ctx->pc = 0x148EE8u;
    SET_GPR_U32(ctx, 31, 0x148EF0u);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148EF0u; }
    }
    if (ctx->pc != 0x148EF0u) { return; }
    ctx->pc = 0x148EF0u;
    // 0x148ef0: 0x3c030fff
    ctx->pc = 0x148ef0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4095 << 16));
    // 0x148ef4: 0x3c041000
    ctx->pc = 0x148ef4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x148ef8: 0x3463ffff
    ctx->pc = 0x148ef8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 65535));
    // 0x148efc: 0x3484b410
    ctx->pc = 0x148efcu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 46096));
    // 0x148f00: 0x2038024
    ctx->pc = 0x148f00u;
    SET_GPR_U32(ctx, 16, AND32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x148f04: 0x3c051000
    ctx->pc = 0x148f04u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x148f08: 0xac900000
    ctx->pc = 0x148f08u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 16)); // MMIO: 0x10000000
    // 0x148f0c: 0x34a5b420
    ctx->pc = 0x148f0cu;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 46112));
    // 0x148f10: 0x24040004
    ctx->pc = 0x148f10u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4));
    // 0x148f14: 0x3c031000
    ctx->pc = 0x148f14u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x148f18: 0xaca40000
    ctx->pc = 0x148f18u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x148f1c: 0x3463b400
    ctx->pc = 0x148f1cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 46080));
    // 0x148f20: 0x24040101
    ctx->pc = 0x148f20u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 257));
    // 0x148f24: 0xac640000
    ctx->pc = 0x148f24u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x148f28: 0x50400004
    ctx->pc = 0x148F28u;
    {
        const bool branch_taken_0x148f28 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x148f28) {
            ctx->pc = 0x148F2Cu;
            SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
            ctx->pc = 0x148F3Cu;
            goto label_148f3c;
        }
    }
    ctx->pc = 0x148F30u;
    // 0x148f30: 0xc0475ae
    ctx->pc = 0x148F30u;
    SET_GPR_U32(ctx, 31, 0x148F38u);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148F38u; }
    }
    if (ctx->pc != 0x148F38u) { return; }
    ctx->pc = 0x148F38u;
    // 0x148f38: 0x240282d
    ctx->pc = 0x148f38u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_148f3c:
    // 0x148f3c: 0xc05148a
    ctx->pc = 0x148F3Cu;
    SET_GPR_U32(ctx, 31, 0x148F44u);
    ctx->pc = 0x148F40u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x145228u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00145228_0x145228(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148F44u; }
    }
    if (ctx->pc != 0x148F44u) { return; }
    ctx->pc = 0x148F44u;
    // 0x148f44: 0xc051496
    ctx->pc = 0x148F44u;
    SET_GPR_U32(ctx, 31, 0x148F4Cu);
    ctx->pc = 0x148F48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x145258u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148F4Cu; }
    }
    if (ctx->pc != 0x148F4Cu) { return; }
    ctx->pc = 0x148F4Cu;
    // 0x148f4c: 0x8e240870
    ctx->pc = 0x148f4cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 2160)));
    // 0x148f50: 0x24020003
    ctx->pc = 0x148f50u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
    // 0x148f54: 0xafa20000
    ctx->pc = 0x148f54u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x148f58: 0xc051fda
    ctx->pc = 0x148F58u;
    SET_GPR_U32(ctx, 31, 0x148F60u);
    ctx->pc = 0x148F5Cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x147F68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F68_0x147f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148F60u; }
    }
    if (ctx->pc != 0x148F60u) { return; }
    ctx->pc = 0x148F60u;
    // 0x148f60: 0xdfbf0050
    ctx->pc = 0x148f60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x148f64: 0xdfb20040
    ctx->pc = 0x148f64u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x148f68: 0xdfb10030
    ctx->pc = 0x148f68u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x148f6c: 0xdfb00020
    ctx->pc = 0x148f6cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x148f70: 0x3e00008
    ctx->pc = 0x148F70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x148F74u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x148F3Cu: goto label_148f3c;
            case 0x148FF4u: goto label_148ff4;
            case 0x14903Cu: goto label_14903c;
            case 0x1490F8u: goto label_1490f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x148F78u;
    // 0x148f78: 0x27bdff90
    ctx->pc = 0x148f78u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x148f7c: 0xffb10010
    ctx->pc = 0x148f7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x148f80: 0xffb00000
    ctx->pc = 0x148f80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x148f84: 0x80882d
    ctx->pc = 0x148f84u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148f88: 0xffb50050
    ctx->pc = 0x148f88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 21));
    // 0x148f8c: 0x24100001
    ctx->pc = 0x148f8cu;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 0), 1));
    // 0x148f90: 0xffb40040
    ctx->pc = 0x148f90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 20));
    // 0x148f94: 0x202d
    ctx->pc = 0x148f94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148f98: 0xffb30030
    ctx->pc = 0x148f98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x148f9c: 0xffb20020
    ctx->pc = 0x148f9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x148fa0: 0xffbf0060
    ctx->pc = 0x148fa0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 31));
    // 0x148fa4: 0xc050fe2
    ctx->pc = 0x148FA4u;
    SET_GPR_U32(ctx, 31, 0x148FACu);
    ctx->pc = 0x148FA8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2144), GPR_U32(ctx, 16));
    ctx->pc = 0x143F88u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00143F88_0x143f88(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148FACu; }
    }
    if (ctx->pc != 0x148FACu) { return; }
    ctx->pc = 0x148FACu;
    // 0x148fac: 0x220202d
    ctx->pc = 0x148facu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148fb0: 0xc05167a
    ctx->pc = 0x148FB0u;
    SET_GPR_U32(ctx, 31, 0x148FB8u);
    ctx->pc = 0x148FB4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 28));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148FB8u; }
    }
    if (ctx->pc != 0x148FB8u) { return; }
    ctx->pc = 0x148FB8u;
    // 0x148fb8: 0x40902d
    ctx->pc = 0x148fb8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148fbc: 0x121842
    ctx->pc = 0x148fbcu;
    SET_GPR_U32(ctx, 3, SRL32(GPR_U32(ctx, 18), 1));
    // 0x148fc0: 0x121442
    ctx->pc = 0x148fc0u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 18), 17));
    // 0x148fc4: 0x30750fff
    ctx->pc = 0x148fc4u;
    SET_GPR_U32(ctx, 21, AND32(GPR_U32(ctx, 3), 4095));
    // 0x148fc8: 0x30420003
    ctx->pc = 0x148fc8u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 3));
    // 0x148fcc: 0x122342
    ctx->pc = 0x148fccu;
    SET_GPR_U32(ctx, 4, SRL32(GPR_U32(ctx, 18), 13));
    // 0x148fd0: 0x121bc2
    ctx->pc = 0x148fd0u;
    SET_GPR_U32(ctx, 3, SRL32(GPR_U32(ctx, 18), 15));
    // 0x148fd4: 0x30940003
    ctx->pc = 0x148fd4u;
    SET_GPR_U32(ctx, 20, AND32(GPR_U32(ctx, 4), 3));
    // 0x148fd8: 0x30730003
    ctx->pc = 0x148fd8u;
    SET_GPR_U32(ctx, 19, AND32(GPR_U32(ctx, 3), 3));
    // 0x148fdc: 0x10500005
    ctx->pc = 0x148FDCu;
    {
        const bool branch_taken_0x148fdc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 16));
        ctx->pc = 0x148FE0u;
        WRITE32(ADD32(GPR_U32(ctx, 17), 344), GPR_U32(ctx, 2));
        if (branch_taken_0x148fdc) {
            ctx->pc = 0x148FF4u;
            goto label_148ff4;
        }
    }
    ctx->pc = 0x148FE4u;
    // 0x148fe4: 0x3c050024
    ctx->pc = 0x148fe4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x148fe8: 0x220202d
    ctx->pc = 0x148fe8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148fec: 0xc05221c
    ctx->pc = 0x148FECu;
    SET_GPR_U32(ctx, 31, 0x148FF4u);
    ctx->pc = 0x148FF0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294959456));
    ctx->pc = 0x148870u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148FF4u; }
    }
    if (ctx->pc != 0x148FF4u) { return; }
    ctx->pc = 0x148FF4u;
label_148ff4:
    // 0x148ff4: 0x1214c2
    ctx->pc = 0x148ff4u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 18), 19));
    // 0x148ff8: 0x220202d
    ctx->pc = 0x148ff8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148ffc: 0x30420001
    ctx->pc = 0x148ffcu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 1));
    // 0x149000: 0x24050010
    ctx->pc = 0x149000u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    // 0x149004: 0xae220154
    ctx->pc = 0x149004u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 340), GPR_U32(ctx, 2));
    // 0x149008: 0xc05167a
    ctx->pc = 0x149008u;
    SET_GPR_U32(ctx, 31, 0x149010u);
    ctx->pc = 0x14900Cu;
    SET_GPR_U32(ctx, 16, SRL32(GPR_U32(ctx, 18), 20));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149010u; }
    }
    if (ctx->pc != 0x149010u) { return; }
    ctx->pc = 0x149010u;
    // 0x149010: 0x29202
    ctx->pc = 0x149010u;
    SET_GPR_U32(ctx, 18, SRL32(GPR_U32(ctx, 2), 8));
    // 0x149014: 0x24020048
    ctx->pc = 0x149014u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 72));
    // 0x149018: 0x12020008
    ctx->pc = 0x149018u;
    {
        const bool branch_taken_0x149018 = (GPR_U32(ctx, 16) == GPR_U32(ctx, 2));
        ctx->pc = 0x14901Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 88));
        if (branch_taken_0x149018) {
            ctx->pc = 0x14903Cu;
            goto label_14903c;
        }
    }
    ctx->pc = 0x149020u;
    // 0x149020: 0x12020006
    ctx->pc = 0x149020u;
    {
        const bool branch_taken_0x149020 = (GPR_U32(ctx, 16) == GPR_U32(ctx, 2));
        ctx->pc = 0x149024u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 68));
        if (branch_taken_0x149020) {
            ctx->pc = 0x14903Cu;
            goto label_14903c;
        }
    }
    ctx->pc = 0x149028u;
    // 0x149028: 0x12020004
    ctx->pc = 0x149028u;
    {
        const bool branch_taken_0x149028 = (GPR_U32(ctx, 16) == GPR_U32(ctx, 2));
        ctx->pc = 0x14902Cu;
        SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
        if (branch_taken_0x149028) {
            ctx->pc = 0x14903Cu;
            goto label_14903c;
        }
    }
    ctx->pc = 0x149030u;
    // 0x149030: 0x220202d
    ctx->pc = 0x149030u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x149034: 0xc05221c
    ctx->pc = 0x149034u;
    SET_GPR_U32(ctx, 31, 0x14903Cu);
    ctx->pc = 0x149038u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294959496));
    ctx->pc = 0x148870u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14903Cu; }
    }
    if (ctx->pc != 0x14903Cu) { return; }
    ctx->pc = 0x14903Cu;
label_14903c:
    // 0x14903c: 0x8e24013c
    ctx->pc = 0x14903cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 316)));
    // 0x149040: 0x154480
    ctx->pc = 0x149040u;
    SET_GPR_U32(ctx, 8, SLL32(GPR_U32(ctx, 21), 18));
    // 0x149044: 0x8e230140
    ctx->pc = 0x149044u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 320)));
    // 0x149048: 0x124a80
    ctx->pc = 0x149048u;
    SET_GPR_U32(ctx, 9, SLL32(GPR_U32(ctx, 18), 10));
    // 0x14904c: 0x8e26014c
    ctx->pc = 0x14904cu;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 17), 332)));
    // 0x149050: 0x133b00
    ctx->pc = 0x149050u;
    SET_GPR_U32(ctx, 7, SLL32(GPR_U32(ctx, 19), 12));
    // 0x149054: 0x8e220150
    ctx->pc = 0x149054u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 336)));
    // 0x149058: 0x142b00
    ctx->pc = 0x149058u;
    SET_GPR_U32(ctx, 5, SLL32(GPR_U32(ctx, 20), 12));
    // 0x14905c: 0x30840fff
    ctx->pc = 0x14905cu;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 4), 4095));
    // 0x149060: 0x30630fff
    ctx->pc = 0x149060u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), 4095));
    // 0x149064: 0xe43825
    ctx->pc = 0x149064u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
    // 0x149068: 0xa32825
    ctx->pc = 0x149068u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x14906c: 0xc83021
    ctx->pc = 0x14906cu;
    SET_GPR_U32(ctx, 6, ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x149070: 0x491021
    ctx->pc = 0x149070u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x149074: 0xae220150
    ctx->pc = 0x149074u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 336), GPR_U32(ctx, 2));
    // 0x149078: 0xae27013c
    ctx->pc = 0x149078u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 316), GPR_U32(ctx, 7));
    // 0x14907c: 0xae250140
    ctx->pc = 0x14907cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 320), GPR_U32(ctx, 5));
    // 0x149080: 0xae26014c
    ctx->pc = 0x149080u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 332), GPR_U32(ctx, 6));
    // 0x149084: 0xdfbf0060
    ctx->pc = 0x149084u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x149088: 0xdfb50050
    ctx->pc = 0x149088u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x14908c: 0xdfb40040
    ctx->pc = 0x14908cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x149090: 0xdfb30030
    ctx->pc = 0x149090u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x149094: 0xdfb20020
    ctx->pc = 0x149094u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x149098: 0xdfb10010
    ctx->pc = 0x149098u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x14909c: 0xdfb00000
    ctx->pc = 0x14909cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1490a0: 0x3e00008
    ctx->pc = 0x1490A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1490A4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 112));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x148F3Cu: goto label_148f3c;
            case 0x148FF4u: goto label_148ff4;
            case 0x14903Cu: goto label_14903c;
            case 0x1490F8u: goto label_1490f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1490A8u;
    // 0x1490a8: 0x27bdffe0
    ctx->pc = 0x1490a8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1490ac: 0x24050003
    ctx->pc = 0x1490acu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 3));
    // 0x1490b0: 0xffb00000
    ctx->pc = 0x1490b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1490b4: 0xffbf0010
    ctx->pc = 0x1490b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1490b8: 0xc05167a
    ctx->pc = 0x1490B8u;
    SET_GPR_U32(ctx, 31, 0x1490C0u);
    ctx->pc = 0x1490BCu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490C0u; }
    }
    if (ctx->pc != 0x1490C0u) { return; }
    ctx->pc = 0x1490C0u;
    // 0x1490c0: 0x200202d
    ctx->pc = 0x1490c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1490c4: 0xc05167a
    ctx->pc = 0x1490C4u;
    SET_GPR_U32(ctx, 31, 0x1490CCu);
    ctx->pc = 0x1490C8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490CCu; }
    }
    if (ctx->pc != 0x1490CCu) { return; }
    ctx->pc = 0x1490CCu;
    // 0x1490cc: 0x1040000a
    ctx->pc = 0x1490CCu;
    {
        const bool branch_taken_0x1490cc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1490D0u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1490cc) {
            ctx->pc = 0x1490F8u;
            goto label_1490f8;
        }
    }
    ctx->pc = 0x1490D4u;
    // 0x1490d4: 0xc05167a
    ctx->pc = 0x1490D4u;
    SET_GPR_U32(ctx, 31, 0x1490DCu);
    ctx->pc = 0x1490D8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490DCu; }
    }
    if (ctx->pc != 0x1490DCu) { return; }
    ctx->pc = 0x1490DCu;
    // 0x1490dc: 0x200202d
    ctx->pc = 0x1490dcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1490e0: 0xc05167a
    ctx->pc = 0x1490E0u;
    SET_GPR_U32(ctx, 31, 0x1490E8u);
    ctx->pc = 0x1490E4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490E8u; }
    }
    if (ctx->pc != 0x1490E8u) { return; }
    ctx->pc = 0x1490E8u;
    // 0x1490e8: 0x200202d
    ctx->pc = 0x1490e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1490ec: 0xc05167a
    ctx->pc = 0x1490ECu;
    SET_GPR_U32(ctx, 31, 0x1490F4u);
    ctx->pc = 0x1490F0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1490F4u; }
    }
    if (ctx->pc != 0x1490F4u) { return; }
    ctx->pc = 0x1490F4u;
    // 0x1490f4: 0xae02015c
    ctx->pc = 0x1490f4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 348), GPR_U32(ctx, 2));
label_1490f8:
    // 0x1490f8: 0x200202d
    ctx->pc = 0x1490f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1490fc: 0xc05167a
    ctx->pc = 0x1490FCu;
    SET_GPR_U32(ctx, 31, 0x149104u);
    ctx->pc = 0x149100u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 14));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149104u; }
    }
    if (ctx->pc != 0x149104u) { return; }
    ctx->pc = 0x149104u;
    // 0x149104: 0xae020160
    ctx->pc = 0x149104u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 352), GPR_U32(ctx, 2));
    // 0x149108: 0x200202d
    ctx->pc = 0x149108u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x14910c: 0xc05167a
    ctx->pc = 0x14910Cu;
    SET_GPR_U32(ctx, 31, 0x149114u);
    ctx->pc = 0x149110u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149114u; }
    }
    if (ctx->pc != 0x149114u) { return; }
    ctx->pc = 0x149114u;
    // 0x149114: 0x200202d
    ctx->pc = 0x149114u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x149118: 0xc05167a
    ctx->pc = 0x149118u;
    SET_GPR_U32(ctx, 31, 0x149120u);
    ctx->pc = 0x14911Cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 14));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x149120u; }
    }
    if (ctx->pc != 0x149120u) { return; }
    ctx->pc = 0x149120u;
    // 0x149120: 0xae020164
    ctx->pc = 0x149120u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 356), GPR_U32(ctx, 2));
    // 0x149124: 0xdfbf0010
    ctx->pc = 0x149124u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x149128: 0xdfb00000
    ctx->pc = 0x149128u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x14912c: 0x3e00008
    ctx->pc = 0x14912Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x149130u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x148F3Cu: goto label_148f3c;
            case 0x148FF4u: goto label_148ff4;
            case 0x14903Cu: goto label_14903c;
            case 0x1490F8u: goto label_1490f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x149134u;
    // 0x149134: 0x0
    ctx->pc = 0x149134u;
    // NOP
    // 0x149138: 0x3c050024
    ctx->pc = 0x149138u;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x14913c: 0x805221c
    ctx->pc = 0x14913Cu;
    ctx->pc = 0x149140u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294959528));
    ctx->pc = 0x148870u;
    sub_00148870_0x148870(rdram, ctx, runtime); return;
    ctx->pc = 0x149144u;
    // 0x149144: 0x0
    ctx->pc = 0x149144u;
    // NOP
    // 0x149148: 0x3c050024
    ctx->pc = 0x149148u;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x14914c: 0x805221c
    ctx->pc = 0x14914Cu;
    ctx->pc = 0x149150u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294959576));
    ctx->pc = 0x148870u;
    sub_00148870_0x148870(rdram, ctx, runtime); return;
    ctx->pc = 0x149154u;
    // 0x149154: 0x0
    ctx->pc = 0x149154u;
    // NOP
    // 0x149158: 0x3c050024
    ctx->pc = 0x149158u;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x14915c: 0x805221c
    ctx->pc = 0x14915Cu;
    ctx->pc = 0x149160u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294959600));
    ctx->pc = 0x148870u;
    sub_00148870_0x148870(rdram, ctx, runtime); return;
    ctx->pc = 0x149164u;
    // 0x149164: 0x0
    ctx->pc = 0x149164u;
    // NOP
    // 0x149168: 0x3c050024
    ctx->pc = 0x149168u;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x14916c: 0x805221c
    ctx->pc = 0x14916Cu;
    ctx->pc = 0x149170u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294959656));
    ctx->pc = 0x148870u;
    sub_00148870_0x148870(rdram, ctx, runtime); return;
    ctx->pc = 0x149174u;
    // 0x149174: 0x0
    ctx->pc = 0x149174u;
    // NOP
    // 0x149178: 0x27bdfff0
    ctx->pc = 0x149178u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x14917c: 0xffbf0000
    ctx->pc = 0x14917cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x149180: 0x8c840040
    ctx->pc = 0x149180u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x149184: 0xc044f26
    ctx->pc = 0x149184u;
    SET_GPR_U32(ctx, 31, 0x14918Cu);
    ctx->pc = 0x149188u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 104));
    ctx->pc = 0x113C98u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00113C98_0x113c98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14918Cu; }
    }
    if (ctx->pc != 0x14918Cu) { return; }
    ctx->pc = 0x14918Cu;
    // 0x14918c: 0xdfbf0000
    ctx->pc = 0x14918cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x149190: 0x24020001
    ctx->pc = 0x149190u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x149194: 0x3e00008
    ctx->pc = 0x149194u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x149198u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x148F3Cu: goto label_148f3c;
            case 0x148FF4u: goto label_148ff4;
            case 0x14903Cu: goto label_14903c;
            case 0x1490F8u: goto label_1490f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14919Cu;
    // 0x14919c: 0x0
    ctx->pc = 0x14919cu;
    // NOP
    // 0x1491a0: 0x27bdfff0
    ctx->pc = 0x1491a0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1491a4: 0xffbf0000
    ctx->pc = 0x1491a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1491a8: 0x8c840040
    ctx->pc = 0x1491a8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 64)));
    // 0x1491ac: 0xc044f60
    ctx->pc = 0x1491ACu;
    SET_GPR_U32(ctx, 31, 0x1491B4u);
    ctx->pc = 0x1491B0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 104));
    ctx->pc = 0x113D80u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00113D80_0x113d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1491B4u; }
    }
    if (ctx->pc != 0x1491B4u) { return; }
    ctx->pc = 0x1491B4u;
    // 0x1491b4: 0xdfbf0000
    ctx->pc = 0x1491b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1491b8: 0x24020001
    ctx->pc = 0x1491b8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1491bc: 0x3e00008
    ctx->pc = 0x1491BCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1491C0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x148F3Cu: goto label_148f3c;
            case 0x148FF4u: goto label_148ff4;
            case 0x14903Cu: goto label_14903c;
            case 0x1490F8u: goto label_1490f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1491C4u;
    // 0x1491c4: 0x0
    ctx->pc = 0x1491c4u;
    // NOP
}
