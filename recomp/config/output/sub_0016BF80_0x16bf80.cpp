#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0016BF80
// Address: 0x16bf80 - 0x16c308
void sub_0016BF80_0x16bf80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x16bf80u;

    // 0x16bf80: 0x27bdffe0
    ctx->pc = 0x16bf80u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x16bf84: 0xffb00000
    ctx->pc = 0x16bf84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16bf88: 0xa0802d
    ctx->pc = 0x16bf88u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bf8c: 0xffb10008
    ctx->pc = 0x16bf8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16bf90: 0x80882d
    ctx->pc = 0x16bf90u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bf94: 0xffbf0010
    ctx->pc = 0x16bf94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x16bf98: 0xc05a78c
    ctx->pc = 0x16BF98u;
    SET_GPR_U32(ctx, 31, 0x16BFA0u);
    ctx->pc = 0x16BF9Cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    ctx->pc = 0x169E30u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BFA0u; }
    }
    if (ctx->pc != 0x16BFA0u) { return; }
    ctx->pc = 0x16BFA0u;
    // 0x16bfa0: 0x3c05ff00
    ctx->pc = 0x16bfa0u;
    SET_GPR_U32(ctx, 5, ((uint32_t)65280 << 16));
    // 0x16bfa4: 0x10400008
    ctx->pc = 0x16BFA4u;
    {
        const bool branch_taken_0x16bfa4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x16BFA8u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x16bfa4) {
            ctx->pc = 0x16BFC8u;
            goto label_16bfc8;
        }
    }
    ctx->pc = 0x16BFACu;
    // 0x16bfac: 0xdfb00000
    ctx->pc = 0x16bfacu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16bfb0: 0x34a50182
    ctx->pc = 0x16bfb0u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 386));
    // 0x16bfb4: 0xdfb10008
    ctx->pc = 0x16bfb4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16bfb8: 0xdfbf0010
    ctx->pc = 0x16bfb8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16bfbc: 0x805a704
    ctx->pc = 0x16BFBCu;
    ctx->pc = 0x16BFC0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x169C10u;
    sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    ctx->pc = 0x16BFC4u;
    // 0x16bfc4: 0x0
    ctx->pc = 0x16bfc4u;
    // NOP
label_16bfc8:
    // 0x16bfc8: 0xc05c164
    ctx->pc = 0x16BFC8u;
    SET_GPR_U32(ctx, 31, 0x16BFD0u);
    ctx->pc = 0x16BFCCu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x170590u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00170590_0x170590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16BFD0u; }
    }
    if (ctx->pc != 0x16BFD0u) { return; }
    ctx->pc = 0x16BFD0u;
    // 0x16bfd0: 0xae020000
    ctx->pc = 0x16bfd0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    // 0x16bfd4: 0x102d
    ctx->pc = 0x16bfd4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16bfd8: 0xdfb00000
    ctx->pc = 0x16bfd8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16bfdc: 0xdfb10008
    ctx->pc = 0x16bfdcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16bfe0: 0xdfbf0010
    ctx->pc = 0x16bfe0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16bfe4: 0x3e00008
    ctx->pc = 0x16BFE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16BFE8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16BFC8u: goto label_16bfc8;
            case 0x16C030u: goto label_16c030;
            case 0x16C0B0u: goto label_16c0b0;
            case 0x16C140u: goto label_16c140;
            case 0x16C15Cu: goto label_16c15c;
            case 0x16C170u: goto label_16c170;
            case 0x16C1A8u: goto label_16c1a8;
            case 0x16C1D8u: goto label_16c1d8;
            case 0x16C1F4u: goto label_16c1f4;
            case 0x16C20Cu: goto label_16c20c;
            case 0x16C248u: goto label_16c248;
            case 0x16C268u: goto label_16c268;
            case 0x16C2B0u: goto label_16c2b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16BFECu;
    // 0x16bfec: 0x0
    ctx->pc = 0x16bfecu;
    // NOP
    // 0x16bff0: 0x27bdfff0
    ctx->pc = 0x16bff0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16bff4: 0xffb00000
    ctx->pc = 0x16bff4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16bff8: 0xffbf0008
    ctx->pc = 0x16bff8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x16bffc: 0xc05a78c
    ctx->pc = 0x16BFFCu;
    SET_GPR_U32(ctx, 31, 0x16C004u);
    ctx->pc = 0x16C000u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x169E30u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C004u; }
    }
    if (ctx->pc != 0x16C004u) { return; }
    ctx->pc = 0x16C004u;
    // 0x16c004: 0x3c05ff00
    ctx->pc = 0x16c004u;
    SET_GPR_U32(ctx, 5, ((uint32_t)65280 << 16));
    // 0x16c008: 0x200202d
    ctx->pc = 0x16c008u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c00c: 0x10400008
    ctx->pc = 0x16C00Cu;
    {
        const bool branch_taken_0x16c00c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x16C010u;
        SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 387));
        if (branch_taken_0x16c00c) {
            ctx->pc = 0x16C030u;
            goto label_16c030;
        }
    }
    ctx->pc = 0x16C014u;
    // 0x16c014: 0xc05a704
    ctx->pc = 0x16C014u;
    SET_GPR_U32(ctx, 31, 0x16C01Cu);
    ctx->pc = 0x16C018u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x169C10u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00169C10_0x169c10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C01Cu; }
    }
    if (ctx->pc != 0x16C01Cu) { return; }
    ctx->pc = 0x16C01Cu;
    // 0x16c01c: 0x102d
    ctx->pc = 0x16c01cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c020: 0xdfb00000
    ctx->pc = 0x16c020u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c024: 0xdfbf0008
    ctx->pc = 0x16c024u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c028: 0x3e00008
    ctx->pc = 0x16C028u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16C02Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16BFC8u: goto label_16bfc8;
            case 0x16C030u: goto label_16c030;
            case 0x16C0B0u: goto label_16c0b0;
            case 0x16C140u: goto label_16c140;
            case 0x16C15Cu: goto label_16c15c;
            case 0x16C170u: goto label_16c170;
            case 0x16C1A8u: goto label_16c1a8;
            case 0x16C1D8u: goto label_16c1d8;
            case 0x16C1F4u: goto label_16c1f4;
            case 0x16C20Cu: goto label_16c20c;
            case 0x16C248u: goto label_16c248;
            case 0x16C268u: goto label_16c268;
            case 0x16C2B0u: goto label_16c2b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16C030u;
label_16c030:
    // 0x16c030: 0xdfb00000
    ctx->pc = 0x16c030u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c034: 0xdfbf0008
    ctx->pc = 0x16c034u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c038: 0x805c212
    ctx->pc = 0x16C038u;
    ctx->pc = 0x16C03Cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x170848u;
    entry_170848_0x170980(rdram, ctx, runtime); return;
    ctx->pc = 0x16C040u;
    // 0x16c040: 0x27bdffd0
    ctx->pc = 0x16c040u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16c044: 0xffb00000
    ctx->pc = 0x16c044u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16c048: 0xc0802d
    ctx->pc = 0x16c048u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c04c: 0xffb10008
    ctx->pc = 0x16c04cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16c050: 0xe0882d
    ctx->pc = 0x16c050u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c054: 0xffb20010
    ctx->pc = 0x16c054u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16c058: 0x100902d
    ctx->pc = 0x16c058u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c05c: 0xffb30018
    ctx->pc = 0x16c05cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16c060: 0x80982d
    ctx->pc = 0x16c060u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c064: 0xffb40020
    ctx->pc = 0x16c064u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x16c068: 0xffbf0028
    ctx->pc = 0x16c068u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x16c06c: 0xc05a78c
    ctx->pc = 0x16C06Cu;
    SET_GPR_U32(ctx, 31, 0x16C074u);
    ctx->pc = 0x16C070u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x169E30u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C074u; }
    }
    if (ctx->pc != 0x16C074u) { return; }
    ctx->pc = 0x16C074u;
    // 0x16c074: 0x3c05ff00
    ctx->pc = 0x16c074u;
    SET_GPR_U32(ctx, 5, ((uint32_t)65280 << 16));
    // 0x16c078: 0x200302d
    ctx->pc = 0x16c078u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c07c: 0x220382d
    ctx->pc = 0x16c07cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c080: 0x240402d
    ctx->pc = 0x16c080u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c084: 0x202d
    ctx->pc = 0x16c084u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c088: 0x10400009
    ctx->pc = 0x16C088u;
    {
        const bool branch_taken_0x16c088 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x16C08Cu;
        SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 388));
        if (branch_taken_0x16c088) {
            ctx->pc = 0x16C0B0u;
            goto label_16c0b0;
        }
    }
    ctx->pc = 0x16C090u;
    // 0x16c090: 0xdfb00000
    ctx->pc = 0x16c090u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c094: 0xdfb10008
    ctx->pc = 0x16c094u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c098: 0xdfb20010
    ctx->pc = 0x16c098u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16c09c: 0xdfb30018
    ctx->pc = 0x16c09cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16c0a0: 0xdfb40020
    ctx->pc = 0x16c0a0u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16c0a4: 0xdfbf0028
    ctx->pc = 0x16c0a4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16c0a8: 0x805a704
    ctx->pc = 0x16C0A8u;
    ctx->pc = 0x16C0ACu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
    ctx->pc = 0x169C10u;
    sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    ctx->pc = 0x16C0B0u;
label_16c0b0:
    // 0x16c0b0: 0x8e621b30
    ctx->pc = 0x16c0b0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 19), 6960)));
    // 0x16c0b4: 0x280282d
    ctx->pc = 0x16c0b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c0b8: 0xc05652e
    ctx->pc = 0x16C0B8u;
    SET_GPR_U32(ctx, 31, 0x16C0C0u);
    ctx->pc = 0x16C0BCu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    ctx->pc = 0x1594B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001594B8_0x1594b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C0C0u; }
    }
    if (ctx->pc != 0x16C0C0u) { return; }
    ctx->pc = 0x16C0C0u;
    // 0x16c0c0: 0x102d
    ctx->pc = 0x16c0c0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c0c4: 0xdfb00000
    ctx->pc = 0x16c0c4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c0c8: 0xdfb10008
    ctx->pc = 0x16c0c8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c0cc: 0xdfb20010
    ctx->pc = 0x16c0ccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16c0d0: 0xdfb30018
    ctx->pc = 0x16c0d0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16c0d4: 0xdfb40020
    ctx->pc = 0x16c0d4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16c0d8: 0xdfbf0028
    ctx->pc = 0x16c0d8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16c0dc: 0x3e00008
    ctx->pc = 0x16C0DCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16C0E0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16BFC8u: goto label_16bfc8;
            case 0x16C030u: goto label_16c030;
            case 0x16C0B0u: goto label_16c0b0;
            case 0x16C140u: goto label_16c140;
            case 0x16C15Cu: goto label_16c15c;
            case 0x16C170u: goto label_16c170;
            case 0x16C1A8u: goto label_16c1a8;
            case 0x16C1D8u: goto label_16c1d8;
            case 0x16C1F4u: goto label_16c1f4;
            case 0x16C20Cu: goto label_16c20c;
            case 0x16C248u: goto label_16c248;
            case 0x16C268u: goto label_16c268;
            case 0x16C2B0u: goto label_16c2b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16C0E4u;
    // 0x16c0e4: 0x0
    ctx->pc = 0x16c0e4u;
    // NOP
    // 0x16c0e8: 0x27bdffd0
    ctx->pc = 0x16c0e8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x16c0ec: 0xffb00000
    ctx->pc = 0x16c0ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16c0f0: 0xa0802d
    ctx->pc = 0x16c0f0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c0f4: 0xffb10008
    ctx->pc = 0x16c0f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x16c0f8: 0xc0882d
    ctx->pc = 0x16c0f8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c0fc: 0xffb20010
    ctx->pc = 0x16c0fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16c100: 0x80902d
    ctx->pc = 0x16c100u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c104: 0xffb30018
    ctx->pc = 0x16c104u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16c108: 0xffbf0020
    ctx->pc = 0x16c108u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x16c10c: 0xc05a78c
    ctx->pc = 0x16C10Cu;
    SET_GPR_U32(ctx, 31, 0x16C114u);
    ctx->pc = 0x16C110u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x169E30u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C114u; }
    }
    if (ctx->pc != 0x16C114u) { return; }
    ctx->pc = 0x16C114u;
    // 0x16c114: 0x1040000a
    ctx->pc = 0x16C114u;
    {
        const bool branch_taken_0x16c114 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x16C118u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x16c114) {
            ctx->pc = 0x16C140u;
            goto label_16c140;
        }
    }
    ctx->pc = 0x16C11Cu;
    // 0x16c11c: 0x3c05ff00
    ctx->pc = 0x16c11cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)65280 << 16));
    // 0x16c120: 0xdfb00000
    ctx->pc = 0x16c120u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c124: 0xdfb10008
    ctx->pc = 0x16c124u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c128: 0xdfb20010
    ctx->pc = 0x16c128u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16c12c: 0x34a50185
    ctx->pc = 0x16c12cu;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 389));
    // 0x16c130: 0xdfb30018
    ctx->pc = 0x16c130u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16c134: 0xdfbf0020
    ctx->pc = 0x16c134u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16c138: 0x805a704
    ctx->pc = 0x16C138u;
    ctx->pc = 0x16C13Cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
    ctx->pc = 0x169C10u;
    sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    ctx->pc = 0x16C140u;
label_16c140:
    // 0x16c140: 0x8e421b30
    ctx->pc = 0x16c140u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 6960)));
    // 0x16c144: 0x12000005
    ctx->pc = 0x16C144u;
    {
        const bool branch_taken_0x16c144 = (GPR_U32(ctx, 16) == GPR_U32(ctx, 0));
        ctx->pc = 0x16C148u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 2364));
        if (branch_taken_0x16c144) {
            ctx->pc = 0x16C15Cu;
            goto label_16c15c;
        }
    }
    ctx->pc = 0x16C14Cu;
    // 0x16c14c: 0x12200003
    ctx->pc = 0x16C14Cu;
    {
        const bool branch_taken_0x16c14c = (GPR_U32(ctx, 17) == GPR_U32(ctx, 0));
        if (branch_taken_0x16c14c) {
            ctx->pc = 0x16C15Cu;
            goto label_16c15c;
        }
    }
    ctx->pc = 0x16C154u;
    // 0x16c154: 0x56600006
    ctx->pc = 0x16C154u;
    {
        const bool branch_taken_0x16c154 = (GPR_U32(ctx, 19) != GPR_U32(ctx, 0));
        if (branch_taken_0x16c154) {
            ctx->pc = 0x16C158u;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 44)));
            ctx->pc = 0x16C170u;
            goto label_16c170;
        }
    }
    ctx->pc = 0x16C15Cu;
label_16c15c:
    // 0x16c15c: 0xc05bf28
    ctx->pc = 0x16C15Cu;
    SET_GPR_U32(ctx, 31, 0x16C164u);
    ctx->pc = 0x16FCA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0016FCA0_0x16fca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C164u; }
    }
    if (ctx->pc != 0x16C164u) { return; }
    ctx->pc = 0x16C164u;
    // 0x16c164: 0x10000029
    ctx->pc = 0x16C164u;
    {
        const bool branch_taken_0x16c164 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x16C168u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x16c164) {
            ctx->pc = 0x16C20Cu;
            goto label_16c20c;
        }
    }
    ctx->pc = 0x16C16Cu;
    // 0x16c16c: 0x0
    ctx->pc = 0x16c16cu;
    // NOP
label_16c170:
    // 0x16c170: 0x24420004
    ctx->pc = 0x16c170u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4));
    // 0x16c174: 0x222102a
    ctx->pc = 0x16c174u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 17), GPR_S32(ctx, 2)));
    // 0x16c178: 0x5040000b
    ctx->pc = 0x16C178u;
    {
        const bool branch_taken_0x16c178 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x16c178) {
            ctx->pc = 0x16C17Cu;
            WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 16));
            ctx->pc = 0x16C1A8u;
            goto label_16c1a8;
        }
    }
    ctx->pc = 0x16C180u;
    // 0x16c180: 0x240202d
    ctx->pc = 0x16c180u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c184: 0xdfb20010
    ctx->pc = 0x16c184u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16c188: 0x3c05ff00
    ctx->pc = 0x16c188u;
    SET_GPR_U32(ctx, 5, ((uint32_t)65280 << 16));
    // 0x16c18c: 0xdfb00000
    ctx->pc = 0x16c18cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c190: 0xdfb10008
    ctx->pc = 0x16c190u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c194: 0x34a50f1d
    ctx->pc = 0x16c194u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 3869));
    // 0x16c198: 0xdfb30018
    ctx->pc = 0x16c198u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16c19c: 0xdfbf0020
    ctx->pc = 0x16c19cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16c1a0: 0x805a704
    ctx->pc = 0x16C1A0u;
    ctx->pc = 0x16C1A4u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
    ctx->pc = 0x169C10u;
    sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    ctx->pc = 0x16C1A8u;
label_16c1a8:
    // 0x16c1a8: 0x282d
    ctx->pc = 0x16c1a8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c1ac: 0xac90000c
    ctx->pc = 0x16c1acu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 16));
    // 0x16c1b0: 0x2138021
    ctx->pc = 0x16c1b0u;
    SET_GPR_U32(ctx, 16, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
    // 0x16c1b4: 0xac910004
    ctx->pc = 0x16c1b4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 17));
    // 0x16c1b8: 0x2631fffe
    ctx->pc = 0x16c1b8u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 4294967294));
    // 0x16c1bc: 0xac900014
    ctx->pc = 0x16c1bcu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 16));
    // 0x16c1c0: 0x2138021
    ctx->pc = 0x16c1c0u;
    SET_GPR_U32(ctx, 16, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
    // 0x16c1c4: 0xac930008
    ctx->pc = 0x16c1c4u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 19));
    // 0x16c1c8: 0xac800010
    ctx->pc = 0x16c1c8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 0));
    // 0x16c1cc: 0xac800018
    ctx->pc = 0x16c1ccu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 0));
    // 0x16c1d0: 0x10000008
    ctx->pc = 0x16C1D0u;
    {
        const bool branch_taken_0x16c1d0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x16C1D4u;
        SET_GPR_U32(ctx, 6, SLT32(GPR_S32(ctx, 17), 17));
        if (branch_taken_0x16c1d0) {
            ctx->pc = 0x16C1F4u;
            goto label_16c1f4;
        }
    }
    ctx->pc = 0x16C1D8u;
label_16c1d8:
    // 0x16c1d8: 0x24a50001
    ctx->pc = 0x16c1d8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 1));
    // 0x16c1dc: 0x24420010
    ctx->pc = 0x16c1dcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 16));
    // 0x16c1e0: 0x821821
    ctx->pc = 0x16c1e0u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x16c1e4: 0x60102d
    ctx->pc = 0x16c1e4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c1e8: 0xac600010
    ctx->pc = 0x16c1e8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 0));
    // 0x16c1ec: 0xac50000c
    ctx->pc = 0x16c1ecu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 16));
    // 0x16c1f0: 0x2138021
    ctx->pc = 0x16c1f0u;
    SET_GPR_U32(ctx, 16, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 19)));
label_16c1f4:
    // 0x16c1f4: 0x24020010
    ctx->pc = 0x16c1f4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 16));
    // 0x16c1f8: 0x226100b
    ctx->pc = 0x16c1f8u;
    if (GPR_U32(ctx, 6) != 0) SET_GPR_U32(ctx, 2, GPR_U32(ctx, 17));
    // 0x16c1fc: 0xa2102a
    ctx->pc = 0x16c1fcu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 5), GPR_S32(ctx, 2)));
    // 0x16c200: 0x1440fff5
    ctx->pc = 0x16C200u;
    {
        const bool branch_taken_0x16c200 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x16C204u;
        SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 5), 3));
        if (branch_taken_0x16c200) {
            ctx->pc = 0x16C1D8u;
            goto label_16c1d8;
        }
    }
    ctx->pc = 0x16C208u;
    // 0x16c208: 0x102d
    ctx->pc = 0x16c208u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_16c20c:
    // 0x16c20c: 0xdfb00000
    ctx->pc = 0x16c20cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c210: 0xdfb10008
    ctx->pc = 0x16c210u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16c214: 0xdfb20010
    ctx->pc = 0x16c214u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16c218: 0xdfb30018
    ctx->pc = 0x16c218u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16c21c: 0xdfbf0020
    ctx->pc = 0x16c21cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16c220: 0x3e00008
    ctx->pc = 0x16C220u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16C224u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16BFC8u: goto label_16bfc8;
            case 0x16C030u: goto label_16c030;
            case 0x16C0B0u: goto label_16c0b0;
            case 0x16C140u: goto label_16c140;
            case 0x16C15Cu: goto label_16c15c;
            case 0x16C170u: goto label_16c170;
            case 0x16C1A8u: goto label_16c1a8;
            case 0x16C1D8u: goto label_16c1d8;
            case 0x16C1F4u: goto label_16c1f4;
            case 0x16C20Cu: goto label_16c20c;
            case 0x16C248u: goto label_16c248;
            case 0x16C268u: goto label_16c268;
            case 0x16C2B0u: goto label_16c2b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16C228u;
    // 0x16c228: 0x27bdfff0
    ctx->pc = 0x16c228u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16c22c: 0xffbf0000
    ctx->pc = 0x16c22cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16c230: 0xc05c550
    ctx->pc = 0x16C230u;
    SET_GPR_U32(ctx, 31, 0x16C238u);
    ctx->pc = 0x171540u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00171540_0x171540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C238u; }
    }
    if (ctx->pc != 0x16C238u) { return; }
    ctx->pc = 0x16C238u;
    // 0x16c238: 0xc05b0c2
    ctx->pc = 0x16C238u;
    SET_GPR_U32(ctx, 31, 0x16C240u);
    ctx->pc = 0x16C308u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0016C308_0x16c308(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C240u; }
    }
    if (ctx->pc != 0x16C240u) { return; }
    ctx->pc = 0x16C240u;
    // 0x16c240: 0x10400009
    ctx->pc = 0x16C240u;
    {
        const bool branch_taken_0x16c240 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x16C244u;
        SET_GPR_U32(ctx, 5, ((uint32_t)39 << 16));
        if (branch_taken_0x16c240) {
            ctx->pc = 0x16C268u;
            goto label_16c268;
        }
    }
    ctx->pc = 0x16C248u;
label_16c248:
    // 0x16c248: 0x0
    ctx->pc = 0x16c248u;
    // NOP
    // 0x16c24c: 0x0
    ctx->pc = 0x16c24cu;
    // NOP
    // 0x16c250: 0x0
    ctx->pc = 0x16c250u;
    // NOP
    // 0x16c254: 0x0
    ctx->pc = 0x16c254u;
    // NOP
    // 0x16c258: 0x0
    ctx->pc = 0x16c258u;
    // NOP
    // 0x16c25c: 0x1000fffa
    ctx->pc = 0x16C25Cu;
    {
        const bool branch_taken_0x16c25c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x16c25c) {
            ctx->pc = 0x16C248u;
            goto label_16c248;
        }
    }
    ctx->pc = 0x16C264u;
    // 0x16c264: 0x0
    ctx->pc = 0x16c264u;
    // NOP
label_16c268:
    // 0x16c268: 0x24040008
    ctx->pc = 0x16c268u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 8));
    // 0x16c26c: 0xc056c1e
    ctx->pc = 0x16C26Cu;
    SET_GPR_U32(ctx, 31, 0x16C274u);
    ctx->pc = 0x16C270u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 8232));
    ctx->pc = 0x15B078u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0015B078_0x15b078(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C274u; }
    }
    if (ctx->pc != 0x16C274u) { return; }
    ctx->pc = 0x16C274u;
    // 0x16c274: 0x40202d
    ctx->pc = 0x16c274u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c278: 0x1080000d
    ctx->pc = 0x16C278u;
    {
        const bool branch_taken_0x16c278 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x16C27Cu;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x16c278) {
            ctx->pc = 0x16C2B0u;
            goto label_16c2b0;
        }
    }
    ctx->pc = 0x16C280u;
    // 0x16c280: 0x3c02ff03
    ctx->pc = 0x16c280u;
    SET_GPR_U32(ctx, 2, ((uint32_t)65283 << 16));
    // 0x16c284: 0x3c03ff00
    ctx->pc = 0x16c284u;
    SET_GPR_U32(ctx, 3, ((uint32_t)65280 << 16));
    // 0x16c288: 0x3442ff05
    ctx->pc = 0x16c288u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65285));
    // 0x16c28c: 0x3c05ff00
    ctx->pc = 0x16c28cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)65280 << 16));
    // 0x16c290: 0x821026
    ctx->pc = 0x16c290u;
    SET_GPR_U32(ctx, 2, XOR32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x16c294: 0x202d
    ctx->pc = 0x16c294u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c298: 0x34630f01
    ctx->pc = 0x16c298u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 3841));
    // 0x16c29c: 0x34a50f13
    ctx->pc = 0x16c29cu;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 3859));
    // 0x16c2a0: 0x62280b
    ctx->pc = 0x16c2a0u;
    if (GPR_U32(ctx, 2) != 0) SET_GPR_U32(ctx, 5, GPR_U32(ctx, 3));
    // 0x16c2a4: 0x805a704
    ctx->pc = 0x16C2A4u;
    ctx->pc = 0x16C2A8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x169C10u;
    sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    ctx->pc = 0x16C2ACu;
    // 0x16c2ac: 0x0
    ctx->pc = 0x16c2acu;
    // NOP
label_16c2b0:
    // 0x16c2b0: 0x3c040027
    ctx->pc = 0x16c2b0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)39 << 16));
    // 0x16c2b4: 0x282d
    ctx->pc = 0x16c2b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c2b8: 0x24846068
    ctx->pc = 0x16c2b8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 24680));
    // 0x16c2bc: 0xc041f1a
    ctx->pc = 0x16C2BCu;
    SET_GPR_U32(ctx, 31, 0x16C2C4u);
    ctx->pc = 0x16C2C0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 36));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C2C4u; }
    }
    if (ctx->pc != 0x16C2C4u) { return; }
    ctx->pc = 0x16C2C4u;
    // 0x16c2c4: 0x3c040027
    ctx->pc = 0x16c2c4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)39 << 16));
    // 0x16c2c8: 0x24846090
    ctx->pc = 0x16c2c8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 24720));
    // 0x16c2cc: 0x282d
    ctx->pc = 0x16c2ccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c2d0: 0xc041f1a
    ctx->pc = 0x16C2D0u;
    SET_GPR_U32(ctx, 31, 0x16C2D8u);
    ctx->pc = 0x16C2D4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 8));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C2D8u; }
    }
    if (ctx->pc != 0x16C2D8u) { return; }
    ctx->pc = 0x16C2D8u;
    // 0x16c2d8: 0x3c040027
    ctx->pc = 0x16c2d8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)39 << 16));
    // 0x16c2dc: 0x24846098
    ctx->pc = 0x16c2dcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 24728));
    // 0x16c2e0: 0x282d
    ctx->pc = 0x16c2e0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c2e4: 0xc041f1a
    ctx->pc = 0x16C2E4u;
    SET_GPR_U32(ctx, 31, 0x16C2ECu);
    ctx->pc = 0x16C2E8u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 64));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16C2ECu; }
    }
    if (ctx->pc != 0x16C2ECu) { return; }
    ctx->pc = 0x16C2ECu;
    // 0x16c2ec: 0x3c030023
    ctx->pc = 0x16c2ecu;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x16c2f0: 0xdfbf0000
    ctx->pc = 0x16c2f0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16c2f4: 0x102d
    ctx->pc = 0x16c2f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16c2f8: 0xac60f1b8
    ctx->pc = 0x16c2f8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294963640), GPR_U32(ctx, 0));
    // 0x16c2fc: 0x3e00008
    ctx->pc = 0x16C2FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16C300u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16BFC8u: goto label_16bfc8;
            case 0x16C030u: goto label_16c030;
            case 0x16C0B0u: goto label_16c0b0;
            case 0x16C140u: goto label_16c140;
            case 0x16C15Cu: goto label_16c15c;
            case 0x16C170u: goto label_16c170;
            case 0x16C1A8u: goto label_16c1a8;
            case 0x16C1D8u: goto label_16c1d8;
            case 0x16C1F4u: goto label_16c1f4;
            case 0x16C20Cu: goto label_16c20c;
            case 0x16C248u: goto label_16c248;
            case 0x16C268u: goto label_16c268;
            case 0x16C2B0u: goto label_16c2b0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16C304u;
    // 0x16c304: 0x0
    ctx->pc = 0x16c304u;
    // NOP
}
