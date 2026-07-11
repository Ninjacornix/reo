#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00113488
// Address: 0x113488 - 0x1137a0
void sub_00113488_0x113488(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x113488u;

    // 0x113488: 0x27bdfff0
    ctx->pc = 0x113488u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11348c: 0x282d
    ctx->pc = 0x11348cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113490: 0x148000a2
    ctx->pc = 0x113490u;
    {
        const bool branch_taken_0x113490 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x113494u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        if (branch_taken_0x113490) {
            ctx->pc = 0x11371Cu;
            goto label_11371c;
        }
    }
    ctx->pc = 0x113498u;
    // 0x113498: 0x3c021000
    ctx->pc = 0x113498u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x11349c: 0x34429000
    ctx->pc = 0x11349cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 36864));
    // 0x1134a0: 0x8c430000
    ctx->pc = 0x1134a0u;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x1134a4: 0x30630100
    ctx->pc = 0x1134a4u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), 256));
    // 0x1134a8: 0x1060000c
    ctx->pc = 0x1134A8u;
    {
        const bool branch_taken_0x1134a8 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x1134ACu;
        SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
        if (branch_taken_0x1134a8) {
            ctx->pc = 0x1134DCu;
            goto label_1134dc;
        }
    }
    ctx->pc = 0x1134B0u;
    // 0x1134b0: 0x3c040100
    ctx->pc = 0x1134b0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)256 << 16));
    // 0x1134b4: 0x34639000
    ctx->pc = 0x1134b4u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 36864));
    // 0x1134b8: 0xa0102d
    ctx->pc = 0x1134b8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1134bc: 0x0
    ctx->pc = 0x1134bcu;
    // NOP
label_1134c0:
    // 0x1134c0: 0x82102b
    ctx->pc = 0x1134c0u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1134c4: 0x14400047
    ctx->pc = 0x1134C4u;
    {
        const bool branch_taken_0x1134c4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1134C8u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 1));
        if (branch_taken_0x1134c4) {
            ctx->pc = 0x1135E4u;
            goto label_1135e4;
        }
    }
    ctx->pc = 0x1134CCu;
    // 0x1134cc: 0x8c620000
    ctx->pc = 0x1134ccu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1134d0: 0x30420100
    ctx->pc = 0x1134d0u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 256));
    // 0x1134d4: 0x1440fffa
    ctx->pc = 0x1134D4u;
    {
        const bool branch_taken_0x1134d4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1134D8u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1134d4) {
            ctx->pc = 0x1134C0u;
            goto label_1134c0;
        }
    }
    ctx->pc = 0x1134DCu;
label_1134dc:
    // 0x1134dc: 0x3c021000
    ctx->pc = 0x1134dcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1134e0: 0x3442a000
    ctx->pc = 0x1134e0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 40960));
    // 0x1134e4: 0x8c430000
    ctx->pc = 0x1134e4u;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x1134e8: 0x30630100
    ctx->pc = 0x1134e8u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), 256));
    // 0x1134ec: 0x1060000b
    ctx->pc = 0x1134ECu;
    {
        const bool branch_taken_0x1134ec = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x1134F0u;
        SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
        if (branch_taken_0x1134ec) {
            ctx->pc = 0x11351Cu;
            goto label_11351c;
        }
    }
    ctx->pc = 0x1134F4u;
    // 0x1134f4: 0x3c040100
    ctx->pc = 0x1134f4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)256 << 16));
    // 0x1134f8: 0x3463a000
    ctx->pc = 0x1134f8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 40960));
    // 0x1134fc: 0xa0102d
    ctx->pc = 0x1134fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_113500:
    // 0x113500: 0x82102b
    ctx->pc = 0x113500u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x113504: 0x1440003a
    ctx->pc = 0x113504u;
    {
        const bool branch_taken_0x113504 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x113508u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 1));
        if (branch_taken_0x113504) {
            ctx->pc = 0x1135F0u;
            goto label_1135f0;
        }
    }
    ctx->pc = 0x11350Cu;
    // 0x11350c: 0x8c620000
    ctx->pc = 0x11350cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x113510: 0x30420100
    ctx->pc = 0x113510u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 256));
    // 0x113514: 0x1440fffa
    ctx->pc = 0x113514u;
    {
        const bool branch_taken_0x113514 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x113518u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x113514) {
            ctx->pc = 0x113500u;
            goto label_113500;
        }
    }
    ctx->pc = 0x11351Cu;
label_11351c:
    // 0x11351c: 0x3c021000
    ctx->pc = 0x11351cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x113520: 0x3c041f00
    ctx->pc = 0x113520u;
    SET_GPR_U32(ctx, 4, ((uint32_t)7936 << 16));
    // 0x113524: 0x34423c00
    ctx->pc = 0x113524u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 15360));
    // 0x113528: 0x34840003
    ctx->pc = 0x113528u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 3));
    // 0x11352c: 0x8c430000
    ctx->pc = 0x11352cu;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x113530: 0x641824
    ctx->pc = 0x113530u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x113534: 0x1060000d
    ctx->pc = 0x113534u;
    {
        const bool branch_taken_0x113534 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x113538u;
        SET_GPR_U32(ctx, 3, ((uint32_t)7936 << 16));
        if (branch_taken_0x113534) {
            ctx->pc = 0x11356Cu;
            goto label_11356c;
        }
    }
    ctx->pc = 0x11353Cu;
    // 0x11353c: 0x3c041000
    ctx->pc = 0x11353cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x113540: 0x3c060100
    ctx->pc = 0x113540u;
    SET_GPR_U32(ctx, 6, ((uint32_t)256 << 16));
    // 0x113544: 0x34843c00
    ctx->pc = 0x113544u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 15360));
    // 0x113548: 0x34630003
    ctx->pc = 0x113548u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 3));
    // 0x11354c: 0xa0102d
    ctx->pc = 0x11354cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_113550:
    // 0x113550: 0xc2102b
    ctx->pc = 0x113550u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x113554: 0x14400029
    ctx->pc = 0x113554u;
    {
        const bool branch_taken_0x113554 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x113558u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 1));
        if (branch_taken_0x113554) {
            ctx->pc = 0x1135FCu;
            goto label_1135fc;
        }
    }
    ctx->pc = 0x11355Cu;
    // 0x11355c: 0x8c820000
    ctx->pc = 0x11355cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x113560: 0x431024
    ctx->pc = 0x113560u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x113564: 0x1440fffa
    ctx->pc = 0x113564u;
    {
        const bool branch_taken_0x113564 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x113568u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x113564) {
            ctx->pc = 0x113550u;
            goto label_113550;
        }
    }
    ctx->pc = 0x11356Cu;
label_11356c:
    // 0x11356c: 0x4846e800
    ctx->pc = 0x11356cu;
    SET_GPR_U32(ctx, 6, ctx->vu0_vpu_stat);
    // 0x113570: 0x30c20100
    ctx->pc = 0x113570u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 6), 256));
    // 0x113574: 0x10400009
    ctx->pc = 0x113574u;
    {
        const bool branch_taken_0x113574 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x113578u;
        SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
        if (branch_taken_0x113574) {
            ctx->pc = 0x11359Cu;
            goto label_11359c;
        }
    }
    ctx->pc = 0x11357Cu;
    // 0x11357c: 0xa0102d
    ctx->pc = 0x11357cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_113580:
    // 0x113580: 0x62102b
    ctx->pc = 0x113580u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x113584: 0x14400020
    ctx->pc = 0x113584u;
    {
        const bool branch_taken_0x113584 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x113588u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 1));
        if (branch_taken_0x113584) {
            ctx->pc = 0x113608u;
            goto label_113608;
        }
    }
    ctx->pc = 0x11358Cu;
    // 0x11358c: 0x4846e800
    ctx->pc = 0x11358cu;
    SET_GPR_U32(ctx, 6, ctx->vu0_vpu_stat);
    // 0x113590: 0x30c20100
    ctx->pc = 0x113590u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 6), 256));
    // 0x113594: 0x1440fffa
    ctx->pc = 0x113594u;
    {
        const bool branch_taken_0x113594 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x113598u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x113594) {
            ctx->pc = 0x113580u;
            goto label_113580;
        }
    }
    ctx->pc = 0x11359Cu;
label_11359c:
    // 0x11359c: 0x3c021000
    ctx->pc = 0x11359cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1135a0: 0x34423020
    ctx->pc = 0x1135a0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 12320));
    // 0x1135a4: 0x8c430000
    ctx->pc = 0x1135a4u;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x1135a8: 0x30630c00
    ctx->pc = 0x1135a8u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), 3072));
    // 0x1135ac: 0x1060000b
    ctx->pc = 0x1135ACu;
    {
        const bool branch_taken_0x1135ac = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x1135B0u;
        SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
        if (branch_taken_0x1135ac) {
            ctx->pc = 0x1135DCu;
            goto label_1135dc;
        }
    }
    ctx->pc = 0x1135B4u;
    // 0x1135b4: 0x3c040100
    ctx->pc = 0x1135b4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)256 << 16));
    // 0x1135b8: 0x34633020
    ctx->pc = 0x1135b8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 12320));
    // 0x1135bc: 0xa0102d
    ctx->pc = 0x1135bcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_1135c0:
    // 0x1135c0: 0x82102b
    ctx->pc = 0x1135c0u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1135c4: 0x14400013
    ctx->pc = 0x1135C4u;
    {
        const bool branch_taken_0x1135c4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1135C8u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 1));
        if (branch_taken_0x1135c4) {
            ctx->pc = 0x113614u;
            goto label_113614;
        }
    }
    ctx->pc = 0x1135CCu;
    // 0x1135cc: 0x8c620000
    ctx->pc = 0x1135ccu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1135d0: 0x30420c00
    ctx->pc = 0x1135d0u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 3072));
    // 0x1135d4: 0x1440fffa
    ctx->pc = 0x1135D4u;
    {
        const bool branch_taken_0x1135d4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1135D8u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1135d4) {
            ctx->pc = 0x1135C0u;
            goto label_1135c0;
        }
    }
    ctx->pc = 0x1135DCu;
label_1135dc:
    // 0x1135dc: 0x1000006c
    ctx->pc = 0x1135DCu;
    {
        const bool branch_taken_0x1135dc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1135E0u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1135dc) {
            ctx->pc = 0x113790u;
            goto label_113790;
        }
    }
    ctx->pc = 0x1135E4u;
label_1135e4:
    // 0x1135e4: 0x3c040024
    ctx->pc = 0x1135e4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x1135e8: 0x1000000c
    ctx->pc = 0x1135E8u;
    {
        const bool branch_taken_0x1135e8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1135ECu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294936112));
        if (branch_taken_0x1135e8) {
            ctx->pc = 0x11361Cu;
            goto label_11361c;
        }
    }
    ctx->pc = 0x1135F0u;
label_1135f0:
    // 0x1135f0: 0x3c040024
    ctx->pc = 0x1135f0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x1135f4: 0x10000009
    ctx->pc = 0x1135F4u;
    {
        const bool branch_taken_0x1135f4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1135F8u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294936336));
        if (branch_taken_0x1135f4) {
            ctx->pc = 0x11361Cu;
            goto label_11361c;
        }
    }
    ctx->pc = 0x1135FCu;
label_1135fc:
    // 0x1135fc: 0x3c040024
    ctx->pc = 0x1135fcu;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x113600: 0x10000006
    ctx->pc = 0x113600u;
    {
        const bool branch_taken_0x113600 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x113604u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294936384));
        if (branch_taken_0x113600) {
            ctx->pc = 0x11361Cu;
            goto label_11361c;
        }
    }
    ctx->pc = 0x113608u;
label_113608:
    // 0x113608: 0x3c040024
    ctx->pc = 0x113608u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x11360c: 0x10000003
    ctx->pc = 0x11360Cu;
    {
        const bool branch_taken_0x11360c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x113610u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294936432));
        if (branch_taken_0x11360c) {
            ctx->pc = 0x11361Cu;
            goto label_11361c;
        }
    }
    ctx->pc = 0x113614u;
label_113614:
    // 0x113614: 0x3c040024
    ctx->pc = 0x113614u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x113618: 0x24848798
    ctx->pc = 0x113618u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294936472));
label_11361c:
    // 0x11361c: 0xc045a12
    ctx->pc = 0x11361Cu;
    SET_GPR_U32(ctx, 31, 0x113624u);
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113624u; }
    }
    if (ctx->pc != 0x113624u) { return; }
    ctx->pc = 0x113624u;
    // 0x113624: 0x3c021000
    ctx->pc = 0x113624u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x113628: 0x3c040024
    ctx->pc = 0x113628u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x11362c: 0x34429000
    ctx->pc = 0x11362cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 36864));
    // 0x113630: 0x24848660
    ctx->pc = 0x113630u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294936160));
    // 0x113634: 0xc045a12
    ctx->pc = 0x113634u;
    SET_GPR_U32(ctx, 31, 0x11363Cu);
    ctx->pc = 0x113638u;
    SET_GPR_U32(ctx, 5, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0)));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11363Cu; }
    }
    if (ctx->pc != 0x11363Cu) { return; }
    ctx->pc = 0x11363Cu;
    // 0x11363c: 0x3c021000
    ctx->pc = 0x11363cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x113640: 0x3c040024
    ctx->pc = 0x113640u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x113644: 0x34429030
    ctx->pc = 0x113644u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 36912));
    // 0x113648: 0x24848670
    ctx->pc = 0x113648u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294936176));
    // 0x11364c: 0xc045a12
    ctx->pc = 0x11364Cu;
    SET_GPR_U32(ctx, 31, 0x113654u);
    ctx->pc = 0x113650u;
    SET_GPR_U32(ctx, 5, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0)));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113654u; }
    }
    if (ctx->pc != 0x113654u) { return; }
    ctx->pc = 0x113654u;
    // 0x113654: 0x3c021000
    ctx->pc = 0x113654u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x113658: 0x3c040024
    ctx->pc = 0x113658u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x11365c: 0x34429010
    ctx->pc = 0x11365cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 36880));
    // 0x113660: 0x24848680
    ctx->pc = 0x113660u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294936192));
    // 0x113664: 0xc045a12
    ctx->pc = 0x113664u;
    SET_GPR_U32(ctx, 31, 0x11366Cu);
    ctx->pc = 0x113668u;
    SET_GPR_U32(ctx, 5, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0)));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11366Cu; }
    }
    if (ctx->pc != 0x11366Cu) { return; }
    ctx->pc = 0x11366Cu;
    // 0x11366c: 0x3c021000
    ctx->pc = 0x11366cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x113670: 0x3c040024
    ctx->pc = 0x113670u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x113674: 0x34429020
    ctx->pc = 0x113674u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 36896));
    // 0x113678: 0x24848690
    ctx->pc = 0x113678u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294936208));
    // 0x11367c: 0xc045a12
    ctx->pc = 0x11367Cu;
    SET_GPR_U32(ctx, 31, 0x113684u);
    ctx->pc = 0x113680u;
    SET_GPR_U32(ctx, 5, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0)));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113684u; }
    }
    if (ctx->pc != 0x113684u) { return; }
    ctx->pc = 0x113684u;
    // 0x113684: 0x3c021000
    ctx->pc = 0x113684u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x113688: 0x3c040024
    ctx->pc = 0x113688u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x11368c: 0x3442a000
    ctx->pc = 0x11368cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 40960));
    // 0x113690: 0x248486a0
    ctx->pc = 0x113690u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294936224));
    // 0x113694: 0xc045a12
    ctx->pc = 0x113694u;
    SET_GPR_U32(ctx, 31, 0x11369Cu);
    ctx->pc = 0x113698u;
    SET_GPR_U32(ctx, 5, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0)));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11369Cu; }
    }
    if (ctx->pc != 0x11369Cu) { return; }
    ctx->pc = 0x11369Cu;
    // 0x11369c: 0x3c021000
    ctx->pc = 0x11369cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1136a0: 0x3c040024
    ctx->pc = 0x1136a0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x1136a4: 0x3442a030
    ctx->pc = 0x1136a4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 41008));
    // 0x1136a8: 0x248486b0
    ctx->pc = 0x1136a8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294936240));
    // 0x1136ac: 0xc045a12
    ctx->pc = 0x1136ACu;
    SET_GPR_U32(ctx, 31, 0x1136B4u);
    ctx->pc = 0x1136B0u;
    SET_GPR_U32(ctx, 5, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0)));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1136B4u; }
    }
    if (ctx->pc != 0x1136B4u) { return; }
    ctx->pc = 0x1136B4u;
    // 0x1136b4: 0x3c021000
    ctx->pc = 0x1136b4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1136b8: 0x3c040024
    ctx->pc = 0x1136b8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x1136bc: 0x3442a010
    ctx->pc = 0x1136bcu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 40976));
    // 0x1136c0: 0x248486c0
    ctx->pc = 0x1136c0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294936256));
    // 0x1136c4: 0xc045a12
    ctx->pc = 0x1136C4u;
    SET_GPR_U32(ctx, 31, 0x1136CCu);
    ctx->pc = 0x1136C8u;
    SET_GPR_U32(ctx, 5, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0)));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1136CCu; }
    }
    if (ctx->pc != 0x1136CCu) { return; }
    ctx->pc = 0x1136CCu;
    // 0x1136cc: 0x3c021000
    ctx->pc = 0x1136ccu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1136d0: 0x3c040024
    ctx->pc = 0x1136d0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x1136d4: 0x3442a020
    ctx->pc = 0x1136d4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 40992));
    // 0x1136d8: 0x248486d0
    ctx->pc = 0x1136d8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294936272));
    // 0x1136dc: 0xc045a12
    ctx->pc = 0x1136DCu;
    SET_GPR_U32(ctx, 31, 0x1136E4u);
    ctx->pc = 0x1136E0u;
    SET_GPR_U32(ctx, 5, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0)));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1136E4u; }
    }
    if (ctx->pc != 0x1136E4u) { return; }
    ctx->pc = 0x1136E4u;
    // 0x1136e4: 0x3c021000
    ctx->pc = 0x1136e4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1136e8: 0x3c040024
    ctx->pc = 0x1136e8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x1136ec: 0x34423c00
    ctx->pc = 0x1136ecu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 15360));
    // 0x1136f0: 0x248486e0
    ctx->pc = 0x1136f0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294936288));
    // 0x1136f4: 0xc045a12
    ctx->pc = 0x1136F4u;
    SET_GPR_U32(ctx, 31, 0x1136FCu);
    ctx->pc = 0x1136F8u;
    SET_GPR_U32(ctx, 5, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0)));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1136FCu; }
    }
    if (ctx->pc != 0x1136FCu) { return; }
    ctx->pc = 0x1136FCu;
    // 0x1136fc: 0x3c021000
    ctx->pc = 0x1136fcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x113700: 0x3c040024
    ctx->pc = 0x113700u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x113704: 0x34423020
    ctx->pc = 0x113704u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 12320));
    // 0x113708: 0x248486f8
    ctx->pc = 0x113708u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294936312));
    // 0x11370c: 0xc045a12
    ctx->pc = 0x11370Cu;
    SET_GPR_U32(ctx, 31, 0x113714u);
    ctx->pc = 0x113710u;
    SET_GPR_U32(ctx, 5, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0)));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113714u; }
    }
    if (ctx->pc != 0x113714u) { return; }
    ctx->pc = 0x113714u;
    // 0x113714: 0x1000001e
    ctx->pc = 0x113714u;
    {
        const bool branch_taken_0x113714 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x113718u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x113714) {
            ctx->pc = 0x113790u;
            goto label_113790;
        }
    }
    ctx->pc = 0x11371Cu;
label_11371c:
    // 0x11371c: 0x3c031000
    ctx->pc = 0x11371cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x113720: 0x3c051000
    ctx->pc = 0x113720u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x113724: 0x34639000
    ctx->pc = 0x113724u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 36864));
    // 0x113728: 0x34a5a000
    ctx->pc = 0x113728u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 40960));
    // 0x11372c: 0x8c620000
    ctx->pc = 0x11372cu;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x113730: 0x3c041000
    ctx->pc = 0x113730u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x113734: 0x8ca60000
    ctx->pc = 0x113734u;
    SET_GPR_U32(ctx, 6, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0))); // MMIO: 0x10000000
    // 0x113738: 0x34843c00
    ctx->pc = 0x113738u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 15360));
    // 0x11373c: 0x30420100
    ctx->pc = 0x11373cu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 256));
    // 0x113740: 0x8c850000
    ctx->pc = 0x113740u;
    SET_GPR_U32(ctx, 5, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0))); // MMIO: 0x10000000
    // 0x113744: 0x2102b
    ctx->pc = 0x113744u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
    // 0x113748: 0x30c60100
    ctx->pc = 0x113748u;
    SET_GPR_U32(ctx, 6, AND32(GPR_U32(ctx, 6), 256));
    // 0x11374c: 0x34440002
    ctx->pc = 0x11374cu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 2), 2));
    // 0x113750: 0x3c031f00
    ctx->pc = 0x113750u;
    SET_GPR_U32(ctx, 3, ((uint32_t)7936 << 16));
    // 0x113754: 0x86100b
    ctx->pc = 0x113754u;
    if (GPR_U32(ctx, 6) != 0) SET_GPR_U32(ctx, 2, GPR_U32(ctx, 4));
    // 0x113758: 0x34630003
    ctx->pc = 0x113758u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 3));
    // 0x11375c: 0xa32824
    ctx->pc = 0x11375cu;
    SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x113760: 0x34440004
    ctx->pc = 0x113760u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 2), 4));
    // 0x113764: 0x85100b
    ctx->pc = 0x113764u;
    if (GPR_U32(ctx, 5) != 0) SET_GPR_U32(ctx, 2, GPR_U32(ctx, 4));
    // 0x113768: 0x4846e800
    ctx->pc = 0x113768u;
    SET_GPR_U32(ctx, 6, ctx->vu0_vpu_stat);
    // 0x11376c: 0x3c031000
    ctx->pc = 0x11376cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x113770: 0x30c60100
    ctx->pc = 0x113770u;
    SET_GPR_U32(ctx, 6, AND32(GPR_U32(ctx, 6), 256));
    // 0x113774: 0x34633020
    ctx->pc = 0x113774u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 12320));
    // 0x113778: 0x34450008
    ctx->pc = 0x113778u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 2), 8));
    // 0x11377c: 0x8c640000
    ctx->pc = 0x11377cu;
    SET_GPR_U32(ctx, 4, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x113780: 0xa6100b
    ctx->pc = 0x113780u;
    if (GPR_U32(ctx, 6) != 0) SET_GPR_U32(ctx, 2, GPR_U32(ctx, 5));
    // 0x113784: 0x34430010
    ctx->pc = 0x113784u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 2), 16));
    // 0x113788: 0x30840c00
    ctx->pc = 0x113788u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 4), 3072));
    // 0x11378c: 0x64100b
    ctx->pc = 0x11378cu;
    if (GPR_U32(ctx, 4) != 0) SET_GPR_U32(ctx, 2, GPR_U32(ctx, 3));
label_113790:
    // 0x113790: 0xdfbf0000
    ctx->pc = 0x113790u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x113794: 0x3e00008
    ctx->pc = 0x113794u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x113798u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1134C0u: goto label_1134c0;
            case 0x1134DCu: goto label_1134dc;
            case 0x113500u: goto label_113500;
            case 0x11351Cu: goto label_11351c;
            case 0x113550u: goto label_113550;
            case 0x11356Cu: goto label_11356c;
            case 0x113580u: goto label_113580;
            case 0x11359Cu: goto label_11359c;
            case 0x1135C0u: goto label_1135c0;
            case 0x1135DCu: goto label_1135dc;
            case 0x1135E4u: goto label_1135e4;
            case 0x1135F0u: goto label_1135f0;
            case 0x1135FCu: goto label_1135fc;
            case 0x113608u: goto label_113608;
            case 0x113614u: goto label_113614;
            case 0x11361Cu: goto label_11361c;
            case 0x11371Cu: goto label_11371c;
            case 0x113790u: goto label_113790;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11379Cu;
    // 0x11379c: 0x0
    ctx->pc = 0x11379cu;
    // NOP
}
