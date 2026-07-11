#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0012A020
// Address: 0x12a020 - 0x12a158
void sub_0012A020_0x12a020(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x12a020u;

label_12a020:
    // 0x12a020: 0x27bdfff0
    ctx->pc = 0x12a020u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a024: 0xffb00000
    ctx->pc = 0x12a024u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12a028: 0xffbf0008
    ctx->pc = 0x12a028u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12a02c: 0xc049938
    ctx->pc = 0x12A02Cu;
    SET_GPR_U32(ctx, 31, 0x12A034u);
    ctx->pc = 0x1264E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A034u; }
    }
    if (ctx->pc != 0x12A034u) { return; }
    ctx->pc = 0x12A034u;
    // 0x12a034: 0x3c020021
    ctx->pc = 0x12a034u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x12a038: 0x2450f390
    ctx->pc = 0x12a038u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 2), 4294964112));
    // 0x12a03c: 0x8e030000
    ctx->pc = 0x12a03cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12a040: 0x10600005
    ctx->pc = 0x12A040u;
    {
        const bool branch_taken_0x12a040 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x12A044u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
        if (branch_taken_0x12a040) {
            ctx->pc = 0x12A058u;
            goto label_12a058;
        }
    }
    ctx->pc = 0x12A048u;
    // 0x12a048: 0xdfb00000
    ctx->pc = 0x12a048u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a04c: 0x804993e
    ctx->pc = 0x12A04Cu;
    ctx->pc = 0x12A050u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x1264F8u;
    sub_001264F8_0x1264f8(rdram, ctx, runtime); return;
    ctx->pc = 0x12A054u;
    // 0x12a054: 0x0
    ctx->pc = 0x12a054u;
    // NOP
label_12a058:
    // 0x12a058: 0x24020001
    ctx->pc = 0x12a058u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x12a05c: 0xc04993e
    ctx->pc = 0x12A05Cu;
    SET_GPR_U32(ctx, 31, 0x12A064u);
    ctx->pc = 0x12A060u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x1264F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A064u; }
    }
    if (ctx->pc != 0x12A064u) { return; }
    ctx->pc = 0x12A064u;
    // 0x12a064: 0xc04c352
    ctx->pc = 0x12A064u;
    SET_GPR_U32(ctx, 31, 0x12A06Cu);
    ctx->pc = 0x130D48u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00130D48_0x130d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A06Cu; }
    }
    if (ctx->pc != 0x12A06Cu) { return; }
    ctx->pc = 0x12A06Cu;
    // 0x12a06c: 0x24020002
    ctx->pc = 0x12a06cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
    // 0x12a070: 0xc04d7bc
    ctx->pc = 0x12A070u;
    SET_GPR_U32(ctx, 31, 0x12A078u);
    ctx->pc = 0x12A074u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x135EF0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135EF0_0x135ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A078u; }
    }
    if (ctx->pc != 0x12A078u) { return; }
    ctx->pc = 0x12A078u;
    // 0x12a078: 0x24020003
    ctx->pc = 0x12a078u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
    // 0x12a07c: 0xc04df60
    ctx->pc = 0x12A07Cu;
    SET_GPR_U32(ctx, 31, 0x12A084u);
    ctx->pc = 0x12A080u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x137D80u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00137D80_0x137d80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A084u; }
    }
    if (ctx->pc != 0x12A084u) { return; }
    ctx->pc = 0x12A084u;
    // 0x12a084: 0x24020004
    ctx->pc = 0x12a084u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
    // 0x12a088: 0xc04d7bc
    ctx->pc = 0x12A088u;
    SET_GPR_U32(ctx, 31, 0x12A090u);
    ctx->pc = 0x12A08Cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x135EF0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135EF0_0x135ef0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A090u; }
    }
    if (ctx->pc != 0x12A090u) { return; }
    ctx->pc = 0x12A090u;
    // 0x12a090: 0x24020005
    ctx->pc = 0x12a090u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 5));
    // 0x12a094: 0xc04c352
    ctx->pc = 0x12A094u;
    SET_GPR_U32(ctx, 31, 0x12A09Cu);
    ctx->pc = 0x12A098u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x130D48u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00130D48_0x130d48(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A09Cu; }
    }
    if (ctx->pc != 0x12A09Cu) { return; }
    ctx->pc = 0x12A09Cu;
    // 0x12a09c: 0x24020006
    ctx->pc = 0x12a09cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 6));
    // 0x12a0a0: 0xc04a698
    ctx->pc = 0x12A0A0u;
    SET_GPR_U32(ctx, 31, 0x12A0A8u);
    ctx->pc = 0x12A0A4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x129A60u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00129A60_0x129a60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12A0A8u; }
    }
    if (ctx->pc != 0x12A0A8u) { return; }
    ctx->pc = 0x12A0A8u;
    // 0x12a0a8: 0xae000000
    ctx->pc = 0x12a0a8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x12a0ac: 0xdfbf0008
    ctx->pc = 0x12a0acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12a0b0: 0xdfb00000
    ctx->pc = 0x12a0b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a0b4: 0x3e00008
    ctx->pc = 0x12A0B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A0B8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A020u: goto label_12a020;
            case 0x12A058u: goto label_12a058;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A0BCu;
    // 0x12a0bc: 0x0
    ctx->pc = 0x12a0bcu;
    // NOP
    // 0x12a0c0: 0x27bdfff0
    ctx->pc = 0x12a0c0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a0c4: 0xffbf0000
    ctx->pc = 0x12a0c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12a0c8: 0xdfbf0000
    ctx->pc = 0x12a0c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a0cc: 0x804a808
    ctx->pc = 0x12A0CCu;
    ctx->pc = 0x12A0D0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x12A020u;
    goto label_12a020;
    ctx->pc = 0x12A0D4u;
    // 0x12a0d4: 0x0
    ctx->pc = 0x12a0d4u;
    // NOP
    // 0x12a0d8: 0x3c030021
    ctx->pc = 0x12a0d8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x12a0dc: 0x2463f390
    ctx->pc = 0x12a0dcu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294964112));
    // 0x12a0e0: 0x8c620000
    ctx->pc = 0x12a0e0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12a0e4: 0x3e00008
    ctx->pc = 0x12A0E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A0E8u;
        SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A020u: goto label_12a020;
            case 0x12A058u: goto label_12a058;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A0ECu;
    // 0x12a0ec: 0x0
    ctx->pc = 0x12a0ecu;
    // NOP
    // 0x12a0f0: 0x3c020021
    ctx->pc = 0x12a0f0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x12a0f4: 0x3e00008
    ctx->pc = 0x12A0F4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12A0F8u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294964156), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12A020u: goto label_12a020;
            case 0x12A058u: goto label_12a058;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12A0FCu;
    // 0x12a0fc: 0x0
    ctx->pc = 0x12a0fcu;
    // NOP
    // 0x12a100: 0x27bdfff0
    ctx->pc = 0x12a100u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a104: 0xa0202d
    ctx->pc = 0x12a104u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a108: 0xffbf0000
    ctx->pc = 0x12a108u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12a10c: 0xdfbf0000
    ctx->pc = 0x12a10cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a110: 0x804a034
    ctx->pc = 0x12A110u;
    ctx->pc = 0x12A114u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x1280D0u;
    sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    ctx->pc = 0x12A118u;
    // 0x12a118: 0x27bdfff0
    ctx->pc = 0x12a118u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a11c: 0xa0202d
    ctx->pc = 0x12a11cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12a120: 0xffbf0000
    ctx->pc = 0x12a120u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12a124: 0xdfbf0000
    ctx->pc = 0x12a124u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a128: 0x804a034
    ctx->pc = 0x12A128u;
    ctx->pc = 0x12A12Cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x1280D0u;
    sub_001280D0_0x1280d0(rdram, ctx, runtime); return;
    ctx->pc = 0x12A130u;
    // 0x12a130: 0x27bdfff0
    ctx->pc = 0x12a130u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12a134: 0x3c030021
    ctx->pc = 0x12a134u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x12a138: 0xffbf0000
    ctx->pc = 0x12a138u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12a13c: 0x2463f3c4
    ctx->pc = 0x12a13cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294964164));
    // 0x12a140: 0x8c620000
    ctx->pc = 0x12a140u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12a144: 0xdfbf0000
    ctx->pc = 0x12a144u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12a148: 0x24420001
    ctx->pc = 0x12a148u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x12a14c: 0x0
    ctx->pc = 0x12a14cu;
    // NOP
    // 0x12a150: 0x804cb02
    ctx->pc = 0x12A150u;
    ctx->pc = 0x12A154u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x132C08u;
    sub_00132C08_0x132c08(rdram, ctx, runtime); return;
    ctx->pc = 0x12A158u;
}
