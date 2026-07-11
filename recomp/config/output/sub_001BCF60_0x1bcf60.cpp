#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001BCF60
// Address: 0x1bcf60 - 0x1bd040
void sub_001BCF60_0x1bcf60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1bcf60u;

    // 0x1bcf60: 0x27bdfff0
    ctx->pc = 0x1bcf60u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1bcf64: 0x3c040025
    ctx->pc = 0x1bcf64u;
    SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
    // 0x1bcf68: 0xffbf0000
    ctx->pc = 0x1bcf68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1bcf6c: 0x3c010032
    ctx->pc = 0x1bcf6cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)50 << 16));
    // 0x1bcf70: 0xac2044e0
    ctx->pc = 0x1bcf70u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 17632), GPR_U32(ctx, 0));
    // 0x1bcf74: 0x24020003
    ctx->pc = 0x1bcf74u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
    // 0x1bcf78: 0x3c010023
    ctx->pc = 0x1bcf78u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
    // 0x1bcf7c: 0x24840370
    ctx->pc = 0x1bcf7cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 880));
    // 0x1bcf80: 0xc0470f8
    ctx->pc = 0x1BCF80u;
    SET_GPR_U32(ctx, 31, 0x1BCF88u);
    ctx->pc = 0x1BCF84u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20488), GPR_U32(ctx, 2));
    ctx->pc = 0x11C3E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011C3E0_0x11c3e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCF88u; }
    }
    if (ctx->pc != 0x1BCF88u) { return; }
    ctx->pc = 0x1BCF88u;
    // 0x1bcf88: 0x4410008
    ctx->pc = 0x1BCF88u;
    {
        const bool branch_taken_0x1bcf88 = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x1bcf88) {
            ctx->pc = 0x1BCFACu;
            goto label_1bcfac;
        }
    }
    ctx->pc = 0x1BCF90u;
    // 0x1bcf90: 0x3c040025
    ctx->pc = 0x1bcf90u;
    SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
    // 0x1bcf94: 0x282d
    ctx->pc = 0x1bcf94u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bcf98: 0x24840380
    ctx->pc = 0x1bcf98u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 896));
    // 0x1bcf9c: 0xc06f410
    ctx->pc = 0x1BCF9Cu;
    SET_GPR_U32(ctx, 31, 0x1BCFA4u);
    ctx->pc = 0x1BCFA0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1BD040u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD040_0x1bd040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCFA4u; }
    }
    if (ctx->pc != 0x1BCFA4u) { return; }
    ctx->pc = 0x1BCFA4u;
    // 0x1bcfa4: 0x4400023
    ctx->pc = 0x1BCFA4u;
    {
        const bool branch_taken_0x1bcfa4 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x1bcfa4) {
            ctx->pc = 0x1BD034u;
            goto label_1bd034;
        }
    }
    ctx->pc = 0x1BCFACu;
label_1bcfac:
    // 0x1bcfac: 0x3c040025
    ctx->pc = 0x1bcfacu;
    SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
    // 0x1bcfb0: 0x282d
    ctx->pc = 0x1bcfb0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bcfb4: 0x248403a0
    ctx->pc = 0x1bcfb4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 928));
    // 0x1bcfb8: 0xc06f410
    ctx->pc = 0x1BCFB8u;
    SET_GPR_U32(ctx, 31, 0x1BCFC0u);
    ctx->pc = 0x1BCFBCu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1BD040u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD040_0x1bd040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCFC0u; }
    }
    if (ctx->pc != 0x1BCFC0u) { return; }
    ctx->pc = 0x1BCFC0u;
    // 0x1bcfc0: 0x440001c
    ctx->pc = 0x1BCFC0u;
    {
        const bool branch_taken_0x1bcfc0 = (GPR_S32(ctx, 2) < 0);
        ctx->pc = 0x1BCFC4u;
        SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
        if (branch_taken_0x1bcfc0) {
            ctx->pc = 0x1BD034u;
            goto label_1bd034;
        }
    }
    ctx->pc = 0x1BCFC8u;
    // 0x1bcfc8: 0x3c060023
    ctx->pc = 0x1bcfc8u;
    SET_GPR_U32(ctx, 6, ((uint32_t)35 << 16));
    // 0x1bcfcc: 0x248403c0
    ctx->pc = 0x1bcfccu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 960));
    // 0x1bcfd0: 0x2405000a
    ctx->pc = 0x1bcfd0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 10));
    // 0x1bcfd4: 0xc06f410
    ctx->pc = 0x1BCFD4u;
    SET_GPR_U32(ctx, 31, 0x1BCFDCu);
    ctx->pc = 0x1BCFD8u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 20232));
    ctx->pc = 0x1BD040u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD040_0x1bd040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCFDCu; }
    }
    if (ctx->pc != 0x1BCFDCu) { return; }
    ctx->pc = 0x1BCFDCu;
    // 0x1bcfdc: 0x4400015
    ctx->pc = 0x1BCFDCu;
    {
        const bool branch_taken_0x1bcfdc = (GPR_S32(ctx, 2) < 0);
        ctx->pc = 0x1BCFE0u;
        SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
        if (branch_taken_0x1bcfdc) {
            ctx->pc = 0x1BD034u;
            goto label_1bd034;
        }
    }
    ctx->pc = 0x1BCFE4u;
    // 0x1bcfe4: 0x3c060023
    ctx->pc = 0x1bcfe4u;
    SET_GPR_U32(ctx, 6, ((uint32_t)35 << 16));
    // 0x1bcfe8: 0x248403e0
    ctx->pc = 0x1bcfe8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 992));
    // 0x1bcfec: 0x24050010
    ctx->pc = 0x1bcfecu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    // 0x1bcff0: 0xc06f410
    ctx->pc = 0x1BCFF0u;
    SET_GPR_U32(ctx, 31, 0x1BCFF8u);
    ctx->pc = 0x1BCFF4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 20256));
    ctx->pc = 0x1BD040u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD040_0x1bd040(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BCFF8u; }
    }
    if (ctx->pc != 0x1BCFF8u) { return; }
    ctx->pc = 0x1BCFF8u;
    // 0x1bcff8: 0x440000e
    ctx->pc = 0x1BCFF8u;
    {
        const bool branch_taken_0x1bcff8 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x1bcff8) {
            ctx->pc = 0x1BD034u;
            goto label_1bd034;
        }
    }
    ctx->pc = 0x1BD000u;
    // 0x1bd000: 0xc06f42c
    ctx->pc = 0x1BD000u;
    SET_GPR_U32(ctx, 31, 0x1BD008u);
    ctx->pc = 0x1BD0B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD0B0_0x1bd0b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD008u; }
    }
    if (ctx->pc != 0x1BD008u) { return; }
    ctx->pc = 0x1BD008u;
    // 0x1bd008: 0x3c040025
    ctx->pc = 0x1bd008u;
    SET_GPR_U32(ctx, 4, ((uint32_t)37 << 16));
    // 0x1bd00c: 0x24054807
    ctx->pc = 0x1bd00cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 18439));
    // 0x1bd010: 0x24840400
    ctx->pc = 0x1bd010u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 1024));
    // 0x1bd014: 0x302d
    ctx->pc = 0x1bd014u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd018: 0x382d
    ctx->pc = 0x1bd018u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd01c: 0x402d
    ctx->pc = 0x1bd01cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1bd020: 0xc046c92
    ctx->pc = 0x1BD020u;
    SET_GPR_U32(ctx, 31, 0x1BD028u);
    ctx->pc = 0x1BD024u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x11B248u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011B248_0x11b248(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD028u; }
    }
    if (ctx->pc != 0x1BD028u) { return; }
    ctx->pc = 0x1BD028u;
    // 0x1bd028: 0x3c010023
    ctx->pc = 0x1bd028u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
    // 0x1bd02c: 0xc06f4bc
    ctx->pc = 0x1BD02Cu;
    SET_GPR_U32(ctx, 31, 0x1BD034u);
    ctx->pc = 0x1BD030u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 20488), GPR_U32(ctx, 2));
    ctx->pc = 0x1BD2F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001BD2F0_0x1bd2f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1BD034u; }
    }
    if (ctx->pc != 0x1BD034u) { return; }
    ctx->pc = 0x1BD034u;
label_1bd034:
    // 0x1bd034: 0xdfbf0000
    ctx->pc = 0x1bd034u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1bd038: 0x3e00008
    ctx->pc = 0x1BD038u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1BD03Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1BCFACu: goto label_1bcfac;
            case 0x1BD034u: goto label_1bd034;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1BD040u;
}
