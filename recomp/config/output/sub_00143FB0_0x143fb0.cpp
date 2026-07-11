#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00143FB0
// Address: 0x143fb0 - 0x144248
void sub_00143FB0_0x143fb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x143fb0u;

    // 0x143fb0: 0x27bdff10
    ctx->pc = 0x143fb0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967056));
    // 0x143fb4: 0x24020001
    ctx->pc = 0x143fb4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x143fb8: 0xffb10060
    ctx->pc = 0x143fb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 17));
    // 0x143fbc: 0x80882d
    ctx->pc = 0x143fbcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x143fc0: 0xffbf00e0
    ctx->pc = 0x143fc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 224), GPR_U64(ctx, 31));
    // 0x143fc4: 0xffbe00d0
    ctx->pc = 0x143fc4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 208), GPR_U64(ctx, 30));
    // 0x143fc8: 0xffb700c0
    ctx->pc = 0x143fc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 23));
    // 0x143fcc: 0xffb600b0
    ctx->pc = 0x143fccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 22));
    // 0x143fd0: 0xffb500a0
    ctx->pc = 0x143fd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 21));
    // 0x143fd4: 0xffb40090
    ctx->pc = 0x143fd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 20));
    // 0x143fd8: 0xffb30080
    ctx->pc = 0x143fd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 19));
    // 0x143fdc: 0xffb20070
    ctx->pc = 0x143fdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 18));
    // 0x143fe0: 0xffb00050
    ctx->pc = 0x143fe0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 16));
    // 0x143fe4: 0xc051496
    ctx->pc = 0x143FE4u;
    SET_GPR_U32(ctx, 31, 0x143FECu);
    ctx->pc = 0x143FE8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 2));
    ctx->pc = 0x145258u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x143FECu; }
    }
    if (ctx->pc != 0x143FECu) { return; }
    ctx->pc = 0x143FECu;
    // 0x143fec: 0x3c021000
    ctx->pc = 0x143fecu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x143ff0: 0x3442b020
    ctx->pc = 0x143ff0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 45088));
    // 0x143ff4: 0x8c430000
    ctx->pc = 0x143ff4u;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x143ff8: 0x10600042
    ctx->pc = 0x143FF8u;
    {
        const bool branch_taken_0x143ff8 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x143FFCu;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x143ff8) {
            ctx->pc = 0x144104u;
            goto label_144104;
        }
    }
    ctx->pc = 0x144000u;
    // 0x144000: 0x34422010
    ctx->pc = 0x144000u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8208));
    // 0x144004: 0x8c430000
    ctx->pc = 0x144004u;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x144008: 0x30634000
    ctx->pc = 0x144008u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), 16384));
    // 0x14400c: 0x1460003e
    ctx->pc = 0x14400Cu;
    {
        const bool branch_taken_0x14400c = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x144010u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x14400c) {
            ctx->pc = 0x144108u;
            goto label_144108;
        }
    }
    ctx->pc = 0x144014u;
    // 0x144014: 0x3c171000
    ctx->pc = 0x144014u;
    SET_GPR_U32(ctx, 23, ((uint32_t)4096 << 16));
    // 0x144018: 0x3c101000
    ctx->pc = 0x144018u;
    SET_GPR_U32(ctx, 16, ((uint32_t)4096 << 16));
    // 0x14401c: 0x3c131000
    ctx->pc = 0x14401cu;
    SET_GPR_U32(ctx, 19, ((uint32_t)4096 << 16));
    // 0x144020: 0x3c121000
    ctx->pc = 0x144020u;
    SET_GPR_U32(ctx, 18, ((uint32_t)4096 << 16));
    // 0x144024: 0x3c141000
    ctx->pc = 0x144024u;
    SET_GPR_U32(ctx, 20, ((uint32_t)4096 << 16));
    // 0x144028: 0x3c151000
    ctx->pc = 0x144028u;
    SET_GPR_U32(ctx, 21, ((uint32_t)4096 << 16));
    // 0x14402c: 0x3c161000
    ctx->pc = 0x14402cu;
    SET_GPR_U32(ctx, 22, ((uint32_t)4096 << 16));
    // 0x144030: 0x3c1efffe
    ctx->pc = 0x144030u;
    SET_GPR_U32(ctx, 30, ((uint32_t)65534 << 16));
    // 0x144034: 0x36f7b420
    ctx->pc = 0x144034u;
    SET_GPR_U32(ctx, 23, OR32(GPR_U32(ctx, 23), 46112));
    // 0x144038: 0x3610b400
    ctx->pc = 0x144038u;
    SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 16), 46080));
    // 0x14403c: 0x3673f590
    ctx->pc = 0x14403cu;
    SET_GPR_U32(ctx, 19, OR32(GPR_U32(ctx, 19), 62864));
    // 0x144040: 0x3652f520
    ctx->pc = 0x144040u;
    SET_GPR_U32(ctx, 18, OR32(GPR_U32(ctx, 18), 62752));
    // 0x144044: 0x3694b020
    ctx->pc = 0x144044u;
    SET_GPR_U32(ctx, 20, OR32(GPR_U32(ctx, 20), 45088));
    // 0x144048: 0x36b52010
    ctx->pc = 0x144048u;
    SET_GPR_U32(ctx, 21, OR32(GPR_U32(ctx, 21), 8208));
    // 0x14404c: 0x36d6b000
    ctx->pc = 0x14404cu;
    SET_GPR_U32(ctx, 22, OR32(GPR_U32(ctx, 22), 45056));
    // 0x144050: 0x37deffff
    ctx->pc = 0x144050u;
    SET_GPR_U32(ctx, 30, OR32(GPR_U32(ctx, 30), 65535));
    // 0x144054: 0x0
    ctx->pc = 0x144054u;
    // NOP
label_144058:
    // 0x144058: 0x8ee20000
    ctx->pc = 0x144058u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 23), 0)));
    // 0x14405c: 0x5440000b
    ctx->pc = 0x14405Cu;
    {
        const bool branch_taken_0x14405c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x14405c) {
            ctx->pc = 0x144060u;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 4256)));
            ctx->pc = 0x14408Cu;
            goto label_14408c;
        }
    }
    ctx->pc = 0x144064u;
    // 0x144064: 0x8e020000
    ctx->pc = 0x144064u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x144068: 0x30420100
    ctx->pc = 0x144068u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 256));
    // 0x14406c: 0x54400007
    ctx->pc = 0x14406Cu;
    {
        const bool branch_taken_0x14406c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x14406c) {
            ctx->pc = 0x144070u;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 4256)));
            ctx->pc = 0x14408Cu;
            goto label_14408c;
        }
    }
    ctx->pc = 0x144074u;
    // 0x144074: 0x8e240870
    ctx->pc = 0x144074u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 2160)));
    // 0x144078: 0x24030001
    ctx->pc = 0x144078u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x14407c: 0x3a0282d
    ctx->pc = 0x14407cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144080: 0xc051fda
    ctx->pc = 0x144080u;
    SET_GPR_U32(ctx, 31, 0x144088u);
    ctx->pc = 0x144084u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x147F68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F68_0x147f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144088u; }
    }
    if (ctx->pc != 0x144088u) { return; }
    ctx->pc = 0x144088u;
    // 0x144088: 0x8e2210a0
    ctx->pc = 0x144088u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 4256)));
label_14408c:
    // 0x14408c: 0x10400016
    ctx->pc = 0x14408Cu;
    {
        const bool branch_taken_0x14408c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x14408c) {
            ctx->pc = 0x1440E8u;
            goto label_1440e8;
        }
    }
    ctx->pc = 0x144094u;
    // 0x144094: 0xc047598
    ctx->pc = 0x144094u;
    SET_GPR_U32(ctx, 31, 0x14409Cu);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14409Cu; }
    }
    if (ctx->pc != 0x14409Cu) { return; }
    ctx->pc = 0x14409Cu;
    // 0x14409c: 0x8e430000
    ctx->pc = 0x14409cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1440a0: 0x3c040001
    ctx->pc = 0x1440a0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)1 << 16));
    // 0x1440a4: 0x641825
    ctx->pc = 0x1440a4u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1440a8: 0xae630000
    ctx->pc = 0x1440a8u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
    // 0x1440ac: 0xae000000
    ctx->pc = 0x1440acu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x1440b0: 0xaec00000
    ctx->pc = 0x1440b0u;
    WRITE32(ADD32(GPR_U32(ctx, 22), 0), GPR_U32(ctx, 0));
    // 0x1440b4: 0x8e430000
    ctx->pc = 0x1440b4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1440b8: 0x7e1824
    ctx->pc = 0x1440b8u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 30)));
    // 0x1440bc: 0x10400003
    ctx->pc = 0x1440BCu;
    {
        const bool branch_taken_0x1440bc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1440C0u;
        WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 3));
        if (branch_taken_0x1440bc) {
            ctx->pc = 0x1440CCu;
            goto label_1440cc;
        }
    }
    ctx->pc = 0x1440C4u;
    // 0x1440c4: 0xc0475ae
    ctx->pc = 0x1440C4u;
    SET_GPR_U32(ctx, 31, 0x1440CCu);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1440CCu; }
    }
    if (ctx->pc != 0x1440CCu) { return; }
    ctx->pc = 0x1440CCu;
label_1440cc:
    // 0x1440cc: 0xae800000
    ctx->pc = 0x1440ccu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 0), GPR_U32(ctx, 0));
    // 0x1440d0: 0x3c034000
    ctx->pc = 0x1440d0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)16384 << 16));
    // 0x1440d4: 0xaee00000
    ctx->pc = 0x1440d4u;
    WRITE32(ADD32(GPR_U32(ctx, 23), 0), GPR_U32(ctx, 0));
    // 0x1440d8: 0x102d
    ctx->pc = 0x1440d8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1440dc: 0xaea30000
    ctx->pc = 0x1440dcu;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 3));
    // 0x1440e0: 0x1000004d
    ctx->pc = 0x1440E0u;
    {
        const bool branch_taken_0x1440e0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1440E4u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 224)));
        if (branch_taken_0x1440e0) {
            ctx->pc = 0x144218u;
            goto label_144218;
        }
    }
    ctx->pc = 0x1440E8u;
label_1440e8:
    // 0x1440e8: 0x8e820000
    ctx->pc = 0x1440e8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1440ec: 0x10400006
    ctx->pc = 0x1440ECu;
    {
        const bool branch_taken_0x1440ec = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1440F0u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x1440ec) {
            ctx->pc = 0x144108u;
            goto label_144108;
        }
    }
    ctx->pc = 0x1440F4u;
    // 0x1440f4: 0x8ea20000
    ctx->pc = 0x1440f4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1440f8: 0x30424000
    ctx->pc = 0x1440f8u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 16384));
    // 0x1440fc: 0x1040ffd6
    ctx->pc = 0x1440FCu;
    {
        const bool branch_taken_0x1440fc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1440fc) {
            ctx->pc = 0x144058u;
            goto label_144058;
        }
    }
    ctx->pc = 0x144104u;
label_144104:
    // 0x144104: 0x3c021000
    ctx->pc = 0x144104u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
label_144108:
    // 0x144108: 0x3c041000
    ctx->pc = 0x144108u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x14410c: 0xdc842030
    ctx->pc = 0x14410cu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 4), 8240)));
    // 0x144110: 0x34422020
    ctx->pc = 0x144110u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8224));
    // 0x144114: 0x8c420000
    ctx->pc = 0x144114u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x144118: 0x4183c
    ctx->pc = 0x144118u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 4) << (32 + 0));
    // 0x14411c: 0x3183f
    ctx->pc = 0x14411cu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x144120: 0x4810008
    ctx->pc = 0x144120u;
    {
        const bool branch_taken_0x144120 = (GPR_S32(ctx, 4) >= 0);
        ctx->pc = 0x144124u;
        WRITE32(ADD32(GPR_U32(ctx, 17), 2128), GPR_U32(ctx, 3));
        if (branch_taken_0x144120) {
            ctx->pc = 0x144144u;
            goto label_144144;
        }
    }
    ctx->pc = 0x144128u;
    // 0x144128: 0x3043001f
    ctx->pc = 0x144128u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 2), 31));
    // 0x14412c: 0x10600003
    ctx->pc = 0x14412Cu;
    {
        const bool branch_taken_0x14412c = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x144130u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 32));
        if (branch_taken_0x14412c) {
            ctx->pc = 0x14413Cu;
            goto label_14413c;
        }
    }
    ctx->pc = 0x144134u;
    // 0x144134: 0x10000004
    ctx->pc = 0x144134u;
    {
        const bool branch_taken_0x144134 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x144138u;
        SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
        if (branch_taken_0x144134) {
            ctx->pc = 0x144148u;
            goto label_144148;
        }
    }
    ctx->pc = 0x14413Cu;
label_14413c:
    // 0x14413c: 0x10000002
    ctx->pc = 0x14413Cu;
    {
        const bool branch_taken_0x14413c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x144140u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x14413c) {
            ctx->pc = 0x144148u;
            goto label_144148;
        }
    }
    ctx->pc = 0x144144u;
label_144144:
    // 0x144144: 0x24020020
    ctx->pc = 0x144144u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 32));
label_144148:
    // 0x144148: 0xae220854
    ctx->pc = 0x144148u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2132), GPR_U32(ctx, 2));
    // 0x14414c: 0x3c021000
    ctx->pc = 0x14414cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x144150: 0x34422010
    ctx->pc = 0x144150u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8208));
    // 0x144154: 0x8c430000
    ctx->pc = 0x144154u;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x144158: 0x30634000
    ctx->pc = 0x144158u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), 16384));
    // 0x14415c: 0x1060002c
    ctx->pc = 0x14415Cu;
    {
        const bool branch_taken_0x14415c = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x144160u;
        SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
        if (branch_taken_0x14415c) {
            ctx->pc = 0x144210u;
            goto label_144210;
        }
    }
    ctx->pc = 0x144164u;
    // 0x144164: 0x220202d
    ctx->pc = 0x144164u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144168: 0xc05221c
    ctx->pc = 0x144168u;
    SET_GPR_U32(ctx, 31, 0x144170u);
    ctx->pc = 0x14416Cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294958536));
    ctx->pc = 0x148870u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144170u; }
    }
    if (ctx->pc != 0x144170u) { return; }
    ctx->pc = 0x144170u;
    // 0x144170: 0x27b00020
    ctx->pc = 0x144170u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 29), 32));
    // 0x144174: 0x24020002
    ctx->pc = 0x144174u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
    // 0x144178: 0x8e240870
    ctx->pc = 0x144178u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 2160)));
    // 0x14417c: 0x200282d
    ctx->pc = 0x14417cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144180: 0xc051fda
    ctx->pc = 0x144180u;
    SET_GPR_U32(ctx, 31, 0x144188u);
    ctx->pc = 0x144184u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    ctx->pc = 0x147F68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F68_0x147f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144188u; }
    }
    if (ctx->pc != 0x144188u) { return; }
    ctx->pc = 0x144188u;
    // 0x144188: 0x3c034000
    ctx->pc = 0x144188u;
    SET_GPR_U32(ctx, 3, ((uint32_t)16384 << 16));
    // 0x14418c: 0x8e240870
    ctx->pc = 0x14418cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 2160)));
    // 0x144190: 0x3c011000
    ctx->pc = 0x144190u;
    SET_GPR_U32(ctx, 1, ((uint32_t)4096 << 16));
    // 0x144194: 0xac232010
    ctx->pc = 0x144194u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8208), GPR_U32(ctx, 3)); // MMIO: 0x10002010
    // 0x144198: 0x24020003
    ctx->pc = 0x144198u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
    // 0x14419c: 0xafa20020
    ctx->pc = 0x14419cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 2));
    // 0x1441a0: 0xc051fda
    ctx->pc = 0x1441A0u;
    SET_GPR_U32(ctx, 31, 0x1441A8u);
    ctx->pc = 0x1441A4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x147F68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00147F68_0x147f68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1441A8u; }
    }
    if (ctx->pc != 0x1441A8u) { return; }
    ctx->pc = 0x1441A8u;
    // 0x1441a8: 0xc047598
    ctx->pc = 0x1441A8u;
    SET_GPR_U32(ctx, 31, 0x1441B0u);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1441B0u; }
    }
    if (ctx->pc != 0x1441B0u) { return; }
    ctx->pc = 0x1441B0u;
    // 0x1441b0: 0x3c061000
    ctx->pc = 0x1441b0u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x1441b4: 0x3c071000
    ctx->pc = 0x1441b4u;
    SET_GPR_U32(ctx, 7, ((uint32_t)4096 << 16));
    // 0x1441b8: 0x34c6f520
    ctx->pc = 0x1441b8u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 62752));
    // 0x1441bc: 0x3c080001
    ctx->pc = 0x1441bcu;
    SET_GPR_U32(ctx, 8, ((uint32_t)1 << 16));
    // 0x1441c0: 0x8cc30000
    ctx->pc = 0x1441c0u;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 6), 0))); // MMIO: 0x10000000
    // 0x1441c4: 0x34e7f590
    ctx->pc = 0x1441c4u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 7), 62864));
    // 0x1441c8: 0x3c041000
    ctx->pc = 0x1441c8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x1441cc: 0x3c05fffe
    ctx->pc = 0x1441ccu;
    SET_GPR_U32(ctx, 5, ((uint32_t)65534 << 16));
    // 0x1441d0: 0x681825
    ctx->pc = 0x1441d0u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x1441d4: 0x3484b000
    ctx->pc = 0x1441d4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 45056));
    // 0x1441d8: 0xace30000
    ctx->pc = 0x1441d8u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
    // 0x1441dc: 0x34a5ffff
    ctx->pc = 0x1441dcu;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 65535));
    // 0x1441e0: 0xac800000
    ctx->pc = 0x1441e0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x1441e4: 0x8cc30000
    ctx->pc = 0x1441e4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1441e8: 0x651824
    ctx->pc = 0x1441e8u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x1441ec: 0xace30000
    ctx->pc = 0x1441ecu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
    // 0x1441f0: 0x10400004
    ctx->pc = 0x1441F0u;
    {
        const bool branch_taken_0x1441f0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1441F4u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x1441f0) {
            ctx->pc = 0x144204u;
            goto label_144204;
        }
    }
    ctx->pc = 0x1441F8u;
    // 0x1441f8: 0xc0475ae
    ctx->pc = 0x1441F8u;
    SET_GPR_U32(ctx, 31, 0x144200u);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144200u; }
    }
    if (ctx->pc != 0x144200u) { return; }
    ctx->pc = 0x144200u;
    // 0x144200: 0x3c021000
    ctx->pc = 0x144200u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
label_144204:
    // 0x144204: 0xafa00040
    ctx->pc = 0x144204u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 0));
    // 0x144208: 0x3442b020
    ctx->pc = 0x144208u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 45088));
    // 0x14420c: 0xac400000
    ctx->pc = 0x14420cu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
label_144210:
    // 0x144210: 0x8fa20040
    ctx->pc = 0x144210u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x144214: 0xdfbf00e0
    ctx->pc = 0x144214u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 224)));
label_144218:
    // 0x144218: 0xdfbe00d0
    ctx->pc = 0x144218u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x14421c: 0xdfb700c0
    ctx->pc = 0x14421cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x144220: 0xdfb600b0
    ctx->pc = 0x144220u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x144224: 0xdfb500a0
    ctx->pc = 0x144224u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x144228: 0xdfb40090
    ctx->pc = 0x144228u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x14422c: 0xdfb30080
    ctx->pc = 0x14422cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x144230: 0xdfb20070
    ctx->pc = 0x144230u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x144234: 0xdfb10060
    ctx->pc = 0x144234u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x144238: 0xdfb00050
    ctx->pc = 0x144238u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x14423c: 0x3e00008
    ctx->pc = 0x14423Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x144240u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 240));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x144058u: goto label_144058;
            case 0x14408Cu: goto label_14408c;
            case 0x1440CCu: goto label_1440cc;
            case 0x1440E8u: goto label_1440e8;
            case 0x144104u: goto label_144104;
            case 0x144108u: goto label_144108;
            case 0x14413Cu: goto label_14413c;
            case 0x144144u: goto label_144144;
            case 0x144148u: goto label_144148;
            case 0x144204u: goto label_144204;
            case 0x144210u: goto label_144210;
            case 0x144218u: goto label_144218;
            default: break;
        }
        return;
    }
    ctx->pc = 0x144244u;
    // 0x144244: 0x0
    ctx->pc = 0x144244u;
    // NOP
}
