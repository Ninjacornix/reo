#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00113988
// Address: 0x113988 - 0x113b08
void sub_00113988_0x113988(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x113988u;

    // 0x113988: 0x27bdfff0
    ctx->pc = 0x113988u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x11398c: 0x3c031000
    ctx->pc = 0x11398cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x113990: 0xffbf0000
    ctx->pc = 0x113990u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x113994: 0x3463a000
    ctx->pc = 0x113994u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 40960));
    // 0x113998: 0x80382d
    ctx->pc = 0x113998u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11399c: 0xa0402d
    ctx->pc = 0x11399cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1139a0: 0x8c620000
    ctx->pc = 0x1139a0u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x1139a4: 0x30420100
    ctx->pc = 0x1139a4u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 256));
    // 0x1139a8: 0x1040000c
    ctx->pc = 0x1139A8u;
    {
        const bool branch_taken_0x1139a8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1139ACu;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1139a8) {
            ctx->pc = 0x1139DCu;
            goto label_1139dc;
        }
    }
    ctx->pc = 0x1139B0u;
    // 0x1139b0: 0x3c031000
    ctx->pc = 0x1139b0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1139b4: 0x3c040100
    ctx->pc = 0x1139b4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)256 << 16));
    // 0x1139b8: 0x3463a000
    ctx->pc = 0x1139b8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 40960));
    // 0x1139bc: 0xc0102d
    ctx->pc = 0x1139bcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_1139c0:
    // 0x1139c0: 0x82102b
    ctx->pc = 0x1139c0u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1139c4: 0x1440003d
    ctx->pc = 0x1139C4u;
    {
        const bool branch_taken_0x1139c4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1139C8u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 1));
        if (branch_taken_0x1139c4) {
            ctx->pc = 0x113ABCu;
            goto label_113abc;
        }
    }
    ctx->pc = 0x1139CCu;
    // 0x1139cc: 0x8c620000
    ctx->pc = 0x1139ccu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1139d0: 0x30420100
    ctx->pc = 0x1139d0u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 256));
    // 0x1139d4: 0x1440fffa
    ctx->pc = 0x1139D4u;
    {
        const bool branch_taken_0x1139d4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x1139D8u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1139d4) {
            ctx->pc = 0x1139C0u;
            goto label_1139c0;
        }
    }
    ctx->pc = 0x1139DCu;
label_1139dc:
    // 0x1139dc: 0x3c021000
    ctx->pc = 0x1139dcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1139e0: 0x24050006
    ctx->pc = 0x1139e0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 6));
    // 0x1139e4: 0x3442a020
    ctx->pc = 0x1139e4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 40992));
    // 0x1139e8: 0x3c047000
    ctx->pc = 0x1139e8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)28672 << 16));
    // 0x1139ec: 0xac450000
    ctx->pc = 0x1139ecu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5)); // MMIO: 0x10000000
    // 0x1139f0: 0xe41824
    ctx->pc = 0x1139f0u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
    // 0x1139f4: 0x14640008
    ctx->pc = 0x1139F4u;
    {
        const bool branch_taken_0x1139f4 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 4));
        ctx->pc = 0x1139F8u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4095 << 16));
        if (branch_taken_0x1139f4) {
            ctx->pc = 0x113A18u;
            goto label_113a18;
        }
    }
    ctx->pc = 0x1139FCu;
    // 0x1139fc: 0x3c031000
    ctx->pc = 0x1139fcu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x113a00: 0x3442ffff
    ctx->pc = 0x113a00u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65535));
    // 0x113a04: 0x3c048000
    ctx->pc = 0x113a04u;
    SET_GPR_U32(ctx, 4, ((uint32_t)32768 << 16));
    // 0x113a08: 0xe21024
    ctx->pc = 0x113a08u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
    // 0x113a0c: 0x3463a010
    ctx->pc = 0x113a0cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 40976));
    // 0x113a10: 0x10000005
    ctx->pc = 0x113A10u;
    {
        const bool branch_taken_0x113a10 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x113A14u;
        SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
        if (branch_taken_0x113a10) {
            ctx->pc = 0x113A28u;
            goto label_113a28;
        }
    }
    ctx->pc = 0x113A18u;
label_113a18:
    // 0x113a18: 0x3c031000
    ctx->pc = 0x113a18u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x113a1c: 0x3442ffff
    ctx->pc = 0x113a1cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65535));
    // 0x113a20: 0x3463a010
    ctx->pc = 0x113a20u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 40976));
    // 0x113a24: 0xe21024
    ctx->pc = 0x113a24u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 7), GPR_U32(ctx, 2)));
label_113a28:
    // 0x113a28: 0xac620000
    ctx->pc = 0x113a28u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2)); // MMIO: 0x10000000
    // 0x113a2c: 0x3c021000
    ctx->pc = 0x113a2cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x113a30: 0x24040101
    ctx->pc = 0x113a30u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 257));
    // 0x113a34: 0x3442a000
    ctx->pc = 0x113a34u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 40960));
    // 0x113a38: 0xac440000
    ctx->pc = 0x113a38u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x113a3c: 0x8c430000
    ctx->pc = 0x113a3cu;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x113a40: 0x30630100
    ctx->pc = 0x113a40u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), 256));
    // 0x113a44: 0x1060000b
    ctx->pc = 0x113A44u;
    {
        const bool branch_taken_0x113a44 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x113A48u;
        SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
        if (branch_taken_0x113a44) {
            ctx->pc = 0x113A74u;
            goto label_113a74;
        }
    }
    ctx->pc = 0x113A4Cu;
    // 0x113a4c: 0x3c040100
    ctx->pc = 0x113a4cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)256 << 16));
    // 0x113a50: 0x3463a000
    ctx->pc = 0x113a50u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 40960));
    // 0x113a54: 0xc0102d
    ctx->pc = 0x113a54u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_113a58:
    // 0x113a58: 0x82102b
    ctx->pc = 0x113a58u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x113a5c: 0x14400017
    ctx->pc = 0x113A5Cu;
    {
        const bool branch_taken_0x113a5c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x113A60u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 1));
        if (branch_taken_0x113a5c) {
            ctx->pc = 0x113ABCu;
            goto label_113abc;
        }
    }
    ctx->pc = 0x113A64u;
    // 0x113a64: 0x8c620000
    ctx->pc = 0x113a64u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x113a68: 0x30420100
    ctx->pc = 0x113a68u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 256));
    // 0x113a6c: 0x1440fffa
    ctx->pc = 0x113A6Cu;
    {
        const bool branch_taken_0x113a6c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x113A70u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x113a6c) {
            ctx->pc = 0x113A58u;
            goto label_113a58;
        }
    }
    ctx->pc = 0x113A74u;
label_113a74:
    // 0x113a74: 0xdce20050
    ctx->pc = 0x113a74u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 7), 80)));
    // 0x113a78: 0x3c031000
    ctx->pc = 0x113a78u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x113a7c: 0x3463a020
    ctx->pc = 0x113a7cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 40992));
    // 0x113a80: 0x3c057000
    ctx->pc = 0x113a80u;
    SET_GPR_U32(ctx, 5, ((uint32_t)28672 << 16));
    // 0x113a84: 0x30427fff
    ctx->pc = 0x113a84u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 32767));
    // 0x113a88: 0x1052024
    ctx->pc = 0x113a88u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 8), GPR_U32(ctx, 5)));
    // 0x113a8c: 0x2103c
    ctx->pc = 0x113a8cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x113a90: 0x2103f
    ctx->pc = 0x113a90u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x113a94: 0xac620000
    ctx->pc = 0x113a94u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x113a98: 0x1485000d
    ctx->pc = 0x113A98u;
    {
        const bool branch_taken_0x113a98 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 5));
        ctx->pc = 0x113A9Cu;
        SET_GPR_U32(ctx, 2, ((uint32_t)4095 << 16));
        if (branch_taken_0x113a98) {
            ctx->pc = 0x113AD0u;
            goto label_113ad0;
        }
    }
    ctx->pc = 0x113AA0u;
    // 0x113aa0: 0x3c031000
    ctx->pc = 0x113aa0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x113aa4: 0x3442ffff
    ctx->pc = 0x113aa4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65535));
    // 0x113aa8: 0x3c048000
    ctx->pc = 0x113aa8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)32768 << 16));
    // 0x113aac: 0x1021024
    ctx->pc = 0x113aacu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
    // 0x113ab0: 0x3463a010
    ctx->pc = 0x113ab0u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 40976));
    // 0x113ab4: 0x1000000a
    ctx->pc = 0x113AB4u;
    {
        const bool branch_taken_0x113ab4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x113AB8u;
        SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
        if (branch_taken_0x113ab4) {
            ctx->pc = 0x113AE0u;
            goto label_113ae0;
        }
    }
    ctx->pc = 0x113ABCu;
label_113abc:
    // 0x113abc: 0x3c040024
    ctx->pc = 0x113abcu;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x113ac0: 0xc045a12
    ctx->pc = 0x113AC0u;
    SET_GPR_U32(ctx, 31, 0x113AC8u);
    ctx->pc = 0x113AC4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294936800));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113AC8u; }
    }
    if (ctx->pc != 0x113AC8u) { return; }
    ctx->pc = 0x113AC8u;
    // 0x113ac8: 0x1000000b
    ctx->pc = 0x113AC8u;
    {
        const bool branch_taken_0x113ac8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x113ACCu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x113ac8) {
            ctx->pc = 0x113AF8u;
            goto label_113af8;
        }
    }
    ctx->pc = 0x113AD0u;
label_113ad0:
    // 0x113ad0: 0x3c031000
    ctx->pc = 0x113ad0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x113ad4: 0x3442ffff
    ctx->pc = 0x113ad4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65535));
    // 0x113ad8: 0x3463a010
    ctx->pc = 0x113ad8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 40976));
    // 0x113adc: 0x1021024
    ctx->pc = 0x113adcu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 8), GPR_U32(ctx, 2)));
label_113ae0:
    // 0x113ae0: 0xac620000
    ctx->pc = 0x113ae0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2)); // MMIO: 0x10000000
    // 0x113ae4: 0x3c031000
    ctx->pc = 0x113ae4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x113ae8: 0x24040101
    ctx->pc = 0x113ae8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 257));
    // 0x113aec: 0x3463a000
    ctx->pc = 0x113aecu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 40960));
    // 0x113af0: 0x102d
    ctx->pc = 0x113af0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x113af4: 0xac640000
    ctx->pc = 0x113af4u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
label_113af8:
    // 0x113af8: 0xdfbf0000
    ctx->pc = 0x113af8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x113afc: 0x3e00008
    ctx->pc = 0x113AFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x113B00u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1139C0u: goto label_1139c0;
            case 0x1139DCu: goto label_1139dc;
            case 0x113A18u: goto label_113a18;
            case 0x113A28u: goto label_113a28;
            case 0x113A58u: goto label_113a58;
            case 0x113A74u: goto label_113a74;
            case 0x113ABCu: goto label_113abc;
            case 0x113AD0u: goto label_113ad0;
            case 0x113AE0u: goto label_113ae0;
            case 0x113AF8u: goto label_113af8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x113B04u;
    // 0x113b04: 0x0
    ctx->pc = 0x113b04u;
    // NOP
}
