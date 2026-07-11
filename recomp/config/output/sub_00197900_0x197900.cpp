#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00197900
// Address: 0x197900 - 0x197bb0
void sub_00197900_0x197900(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x197900u;

    // 0x197900: 0x27bdffd0
    ctx->pc = 0x197900u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x197904: 0x3c01002a
    ctx->pc = 0x197904u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x197908: 0xffbf0020
    ctx->pc = 0x197908u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
    // 0x19790c: 0x240200ff
    ctx->pc = 0x19790cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 255));
    // 0x197910: 0x7fb10010
    ctx->pc = 0x197910u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x197914: 0x7fb00000
    ctx->pc = 0x197914u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x197918: 0x8c27fe20
    ctx->pc = 0x197918u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 1), 4294966816)));
    // 0x19791c: 0x14e20003
    ctx->pc = 0x19791Cu;
    {
        const bool branch_taken_0x19791c = (GPR_U32(ctx, 7) != GPR_U32(ctx, 2));
        ctx->pc = 0x197920u;
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x19791c) {
            ctx->pc = 0x19792Cu;
            goto label_19792c;
        }
    }
    ctx->pc = 0x197924u;
    // 0x197924: 0x10000007
    ctx->pc = 0x197924u;
    {
        const bool branch_taken_0x197924 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197928u;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 128));
        if (branch_taken_0x197924) {
            ctx->pc = 0x197944u;
            goto label_197944;
        }
    }
    ctx->pc = 0x19792Cu;
label_19792c:
    // 0x19792c: 0x10e00006
    ctx->pc = 0x19792Cu;
    {
        const bool branch_taken_0x19792c = (GPR_U32(ctx, 7) == GPR_U32(ctx, 0));
        ctx->pc = 0x197930u;
        SET_GPR_U32(ctx, 5, ((uint32_t)56 << 16));
        if (branch_taken_0x19792c) {
            ctx->pc = 0x197948u;
            goto label_197948;
        }
    }
    ctx->pc = 0x197934u;
    // 0x197934: 0x73843
    ctx->pc = 0x197934u;
    SET_GPR_S32(ctx, 7, SRA32(GPR_S32(ctx, 7), 1));
    // 0x197938: 0x14e00002
    ctx->pc = 0x197938u;
    {
        const bool branch_taken_0x197938 = (GPR_U32(ctx, 7) != GPR_U32(ctx, 0));
        if (branch_taken_0x197938) {
            ctx->pc = 0x197944u;
            goto label_197944;
        }
    }
    ctx->pc = 0x197940u;
    // 0x197940: 0x24070001
    ctx->pc = 0x197940u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 1));
label_197944:
    // 0x197944: 0x3c050038
    ctx->pc = 0x197944u;
    SET_GPR_U32(ctx, 5, ((uint32_t)56 << 16));
label_197948:
    // 0x197948: 0x3c020028
    ctx->pc = 0x197948u;
    SET_GPR_U32(ctx, 2, ((uint32_t)40 << 16));
    // 0x19794c: 0x851824
    ctx->pc = 0x19794cu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x197950: 0x1062001d
    ctx->pc = 0x197950u;
    {
        const bool branch_taken_0x197950 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x197954u;
        SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
        if (branch_taken_0x197950) {
            ctx->pc = 0x1979C8u;
            goto label_1979c8;
        }
    }
    ctx->pc = 0x197958u;
    // 0x197958: 0x10620019
    ctx->pc = 0x197958u;
    {
        const bool branch_taken_0x197958 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        if (branch_taken_0x197958) {
            ctx->pc = 0x1979C0u;
            goto label_1979c0;
        }
    }
    ctx->pc = 0x197960u;
    // 0x197960: 0x3c020030
    ctx->pc = 0x197960u;
    SET_GPR_U32(ctx, 2, ((uint32_t)48 << 16));
    // 0x197964: 0x10620014
    ctx->pc = 0x197964u;
    {
        const bool branch_taken_0x197964 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x197968u;
        SET_GPR_U32(ctx, 2, ((uint32_t)16 << 16));
        if (branch_taken_0x197964) {
            ctx->pc = 0x1979B8u;
            goto label_1979b8;
        }
    }
    ctx->pc = 0x19796Cu;
    // 0x19796c: 0x10620010
    ctx->pc = 0x19796Cu;
    {
        const bool branch_taken_0x19796c = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        if (branch_taken_0x19796c) {
            ctx->pc = 0x1979B0u;
            goto label_1979b0;
        }
    }
    ctx->pc = 0x197974u;
    // 0x197974: 0x3c020018
    ctx->pc = 0x197974u;
    SET_GPR_U32(ctx, 2, ((uint32_t)24 << 16));
    // 0x197978: 0x1062000b
    ctx->pc = 0x197978u;
    {
        const bool branch_taken_0x197978 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x19797Cu;
        SET_GPR_U32(ctx, 2, ((uint32_t)8 << 16));
        if (branch_taken_0x197978) {
            ctx->pc = 0x1979A8u;
            goto label_1979a8;
        }
    }
    ctx->pc = 0x197980u;
    // 0x197980: 0x10620007
    ctx->pc = 0x197980u;
    {
        const bool branch_taken_0x197980 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        if (branch_taken_0x197980) {
            ctx->pc = 0x1979A0u;
            goto label_1979a0;
        }
    }
    ctx->pc = 0x197988u;
    // 0x197988: 0x10650003
    ctx->pc = 0x197988u;
    {
        const bool branch_taken_0x197988 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 5));
        if (branch_taken_0x197988) {
            ctx->pc = 0x197998u;
            goto label_197998;
        }
    }
    ctx->pc = 0x197990u;
    // 0x197990: 0x1000000e
    ctx->pc = 0x197990u;
    {
        const bool branch_taken_0x197990 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197994u;
        if (GPR_U32(ctx, 3) == 0) SET_GPR_U32(ctx, 8, GPR_U32(ctx, 0));
        if (branch_taken_0x197990) {
            ctx->pc = 0x1979CCu;
            goto label_1979cc;
        }
    }
    ctx->pc = 0x197998u;
label_197998:
    // 0x197998: 0x1000000c
    ctx->pc = 0x197998u;
    {
        const bool branch_taken_0x197998 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x19799Cu;
        SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x197998) {
            ctx->pc = 0x1979CCu;
            goto label_1979cc;
        }
    }
    ctx->pc = 0x1979A0u;
label_1979a0:
    // 0x1979a0: 0x1000000a
    ctx->pc = 0x1979A0u;
    {
        const bool branch_taken_0x1979a0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1979A4u;
        SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x1979a0) {
            ctx->pc = 0x1979CCu;
            goto label_1979cc;
        }
    }
    ctx->pc = 0x1979A8u;
label_1979a8:
    // 0x1979a8: 0x10000008
    ctx->pc = 0x1979A8u;
    {
        const bool branch_taken_0x1979a8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1979ACu;
        SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x1979a8) {
            ctx->pc = 0x1979CCu;
            goto label_1979cc;
        }
    }
    ctx->pc = 0x1979B0u;
label_1979b0:
    // 0x1979b0: 0x10000006
    ctx->pc = 0x1979B0u;
    {
        const bool branch_taken_0x1979b0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1979B4u;
        SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 4));
        if (branch_taken_0x1979b0) {
            ctx->pc = 0x1979CCu;
            goto label_1979cc;
        }
    }
    ctx->pc = 0x1979B8u;
label_1979b8:
    // 0x1979b8: 0x10000004
    ctx->pc = 0x1979B8u;
    {
        const bool branch_taken_0x1979b8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1979BCu;
        SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 5));
        if (branch_taken_0x1979b8) {
            ctx->pc = 0x1979CCu;
            goto label_1979cc;
        }
    }
    ctx->pc = 0x1979C0u;
label_1979c0:
    // 0x1979c0: 0x10000002
    ctx->pc = 0x1979C0u;
    {
        const bool branch_taken_0x1979c0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1979C4u;
        SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 6));
        if (branch_taken_0x1979c0) {
            ctx->pc = 0x1979CCu;
            goto label_1979cc;
        }
    }
    ctx->pc = 0x1979C8u;
label_1979c8:
    // 0x1979c8: 0x24080007
    ctx->pc = 0x1979c8u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 7));
label_1979cc:
    // 0x1979cc: 0x30837000
    ctx->pc = 0x1979ccu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 4), 28672));
    // 0x1979d0: 0x24026000
    ctx->pc = 0x1979d0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 24576));
    // 0x1979d4: 0x1062001b
    ctx->pc = 0x1979D4u;
    {
        const bool branch_taken_0x1979d4 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x1979D8u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 16384));
        if (branch_taken_0x1979d4) {
            ctx->pc = 0x197A44u;
            goto label_197a44;
        }
    }
    ctx->pc = 0x1979DCu;
    // 0x1979dc: 0x10620019
    ctx->pc = 0x1979DCu;
    {
        const bool branch_taken_0x1979dc = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        if (branch_taken_0x1979dc) {
            ctx->pc = 0x197A44u;
            goto label_197a44;
        }
    }
    ctx->pc = 0x1979E4u;
    // 0x1979e4: 0x24025000
    ctx->pc = 0x1979e4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 20480));
    // 0x1979e8: 0x10620016
    ctx->pc = 0x1979E8u;
    {
        const bool branch_taken_0x1979e8 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x1979ECu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 8192));
        if (branch_taken_0x1979e8) {
            ctx->pc = 0x197A44u;
            goto label_197a44;
        }
    }
    ctx->pc = 0x1979F0u;
    // 0x1979f0: 0x10620014
    ctx->pc = 0x1979F0u;
    {
        const bool branch_taken_0x1979f0 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        if (branch_taken_0x1979f0) {
            ctx->pc = 0x197A44u;
            goto label_197a44;
        }
    }
    ctx->pc = 0x1979F8u;
    // 0x1979f8: 0x10600010
    ctx->pc = 0x1979F8u;
    {
        const bool branch_taken_0x1979f8 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x1979FCu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 28672));
        if (branch_taken_0x1979f8) {
            ctx->pc = 0x197A3Cu;
            goto label_197a3c;
        }
    }
    ctx->pc = 0x197A00u;
    // 0x197a00: 0x1062000c
    ctx->pc = 0x197A00u;
    {
        const bool branch_taken_0x197a00 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        if (branch_taken_0x197a00) {
            ctx->pc = 0x197A34u;
            goto label_197a34;
        }
    }
    ctx->pc = 0x197A08u;
    // 0x197a08: 0x24023000
    ctx->pc = 0x197a08u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 12288));
    // 0x197a0c: 0x10620007
    ctx->pc = 0x197A0Cu;
    {
        const bool branch_taken_0x197a0c = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x197A10u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4096));
        if (branch_taken_0x197a0c) {
            ctx->pc = 0x197A2Cu;
            goto label_197a2c;
        }
    }
    ctx->pc = 0x197A14u;
    // 0x197a14: 0x10620003
    ctx->pc = 0x197A14u;
    {
        const bool branch_taken_0x197a14 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        if (branch_taken_0x197a14) {
            ctx->pc = 0x197A24u;
            goto label_197a24;
        }
    }
    ctx->pc = 0x197A1Cu;
    // 0x197a1c: 0x1000000b
    ctx->pc = 0x197A1Cu;
    {
        const bool branch_taken_0x197a1c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197A20u;
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) << (32 + 0));
        if (branch_taken_0x197a1c) {
            ctx->pc = 0x197A4Cu;
            goto label_197a4c;
        }
    }
    ctx->pc = 0x197A24u;
label_197a24:
    // 0x197a24: 0x10000008
    ctx->pc = 0x197A24u;
    {
        const bool branch_taken_0x197a24 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197A28u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x197a24) {
            ctx->pc = 0x197A48u;
            goto label_197a48;
        }
    }
    ctx->pc = 0x197A2Cu;
label_197a2c:
    // 0x197a2c: 0x10000006
    ctx->pc = 0x197A2Cu;
    {
        const bool branch_taken_0x197a2c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197A30u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x197a2c) {
            ctx->pc = 0x197A48u;
            goto label_197a48;
        }
    }
    ctx->pc = 0x197A34u;
label_197a34:
    // 0x197a34: 0x10000004
    ctx->pc = 0x197A34u;
    {
        const bool branch_taken_0x197a34 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197A38u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x197a34) {
            ctx->pc = 0x197A48u;
            goto label_197a48;
        }
    }
    ctx->pc = 0x197A3Cu;
label_197a3c:
    // 0x197a3c: 0x10000002
    ctx->pc = 0x197A3Cu;
    {
        const bool branch_taken_0x197a3c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197A40u;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x197a3c) {
            ctx->pc = 0x197A48u;
            goto label_197a48;
        }
    }
    ctx->pc = 0x197A44u;
label_197a44:
    // 0x197a44: 0x24060001
    ctx->pc = 0x197a44u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
label_197a48:
    // 0x197a48: 0x7183c
    ctx->pc = 0x197a48u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 7) << (32 + 0));
label_197a4c:
    // 0x197a4c: 0x8103c
    ctx->pc = 0x197a4cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) << (32 + 0));
    // 0x197a50: 0x3183f
    ctx->pc = 0x197a50u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x197a54: 0x2103f
    ctx->pc = 0x197a54u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x197a58: 0x32138
    ctx->pc = 0x197a58u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << 4);
    // 0x197a5c: 0x21078
    ctx->pc = 0x197a5cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 1);
    // 0x197a60: 0x34430001
    ctx->pc = 0x197a60u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 2), 1));
    // 0x197a64: 0x6103c
    ctx->pc = 0x197a64u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 6) << (32 + 0));
    // 0x197a68: 0x832825
    ctx->pc = 0x197a68u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x197a6c: 0x2103f
    ctx->pc = 0x197a6cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x197a70: 0x3c040001
    ctx->pc = 0x197a70u;
    SET_GPR_U32(ctx, 4, ((uint32_t)1 << 16));
    // 0x197a74: 0x21c78
    ctx->pc = 0x197a74u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << 17);
    // 0x197a78: 0xa42025
    ctx->pc = 0x197a78u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x197a7c: 0x24020002
    ctx->pc = 0x197a7cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
    // 0x197a80: 0x12220006
    ctx->pc = 0x197A80u;
    {
        const bool branch_taken_0x197a80 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 2));
        ctx->pc = 0x197A84u;
        SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        if (branch_taken_0x197a80) {
            ctx->pc = 0x197A9Cu;
            goto label_197a9c;
        }
    }
    ctx->pc = 0x197A88u;
    // 0x197a88: 0x24040030
    ctx->pc = 0x197a88u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 48));
    // 0x197a8c: 0xc063774
    ctx->pc = 0x197A8Cu;
    SET_GPR_U32(ctx, 31, 0x197A94u);
    ctx->pc = 0x197A90u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197A94u; }
    }
    if (ctx->pc != 0x197A94u) { return; }
    ctx->pc = 0x197A94u;
    // 0x197a94: 0x10000005
    ctx->pc = 0x197A94u;
    {
        const bool branch_taken_0x197a94 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197A98u;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x197a94) {
            ctx->pc = 0x197AACu;
            goto label_197aac;
        }
    }
    ctx->pc = 0x197A9Cu;
label_197a9c:
    // 0x197a9c: 0x24040040
    ctx->pc = 0x197a9cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 64));
    // 0x197aa0: 0xc063774
    ctx->pc = 0x197AA0u;
    SET_GPR_U32(ctx, 31, 0x197AA8u);
    ctx->pc = 0x197AA4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197AA8u; }
    }
    if (ctx->pc != 0x197AA8u) { return; }
    ctx->pc = 0x197AA8u;
    // 0x197aa8: 0x24070003
    ctx->pc = 0x197aa8u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 3));
label_197aac:
    // 0x197aac: 0x3c047000
    ctx->pc = 0x197aacu;
    SET_GPR_U32(ctx, 4, ((uint32_t)28672 << 16));
    // 0x197ab0: 0x3c038000
    ctx->pc = 0x197ab0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)32768 << 16));
    // 0x197ab4: 0xe42021
    ctx->pc = 0x197ab4u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
    // 0x197ab8: 0x3c051300
    ctx->pc = 0x197ab8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4864 << 16));
    // 0x197abc: 0x832025
    ctx->pc = 0x197abcu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x197ac0: 0x4303c
    ctx->pc = 0x197ac0u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 4) << (32 + 0));
    // 0x197ac4: 0x3c035000
    ctx->pc = 0x197ac4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)20480 << 16));
    // 0x197ac8: 0x6303e
    ctx->pc = 0x197ac8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 0));
    // 0x197acc: 0xe32025
    ctx->pc = 0x197accu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 7), GPR_U32(ctx, 3)));
    // 0x197ad0: 0xfc460000
    ctx->pc = 0x197ad0u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 6));
    // 0x197ad4: 0x24e3ffff
    ctx->pc = 0x197ad4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x197ad8: 0xac450008
    ctx->pc = 0x197ad8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 5));
    // 0x197adc: 0x3283c
    ctx->pc = 0x197adcu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 3) << (32 + 0));
    // 0x197ae0: 0xac44000c
    ctx->pc = 0x197ae0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 4));
    // 0x197ae4: 0x3c031000
    ctx->pc = 0x197ae4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x197ae8: 0x5283e
    ctx->pc = 0x197ae8u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 0));
    // 0x197aec: 0x3203c
    ctx->pc = 0x197aecu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 3) << (32 + 0));
    // 0x197af0: 0x34038000
    ctx->pc = 0x197af0u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 0), 32768));
    // 0x197af4: 0x641825
    ctx->pc = 0x197af4u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x197af8: 0xa32825
    ctx->pc = 0x197af8u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x197afc: 0x2404000e
    ctx->pc = 0x197afcu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 14));
    // 0x197b00: 0xfc450010
    ctx->pc = 0x197b00u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 16), GPR_U64(ctx, 5));
    // 0x197b04: 0x24030002
    ctx->pc = 0x197b04u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
    // 0x197b08: 0x12230012
    ctx->pc = 0x197B08u;
    {
        const bool branch_taken_0x197b08 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 3));
        ctx->pc = 0x197B0Cu;
        WRITE64(ADD32(GPR_U32(ctx, 2), 24), GPR_U64(ctx, 4));
        if (branch_taken_0x197b08) {
            ctx->pc = 0x197B54u;
            goto label_197b54;
        }
    }
    ctx->pc = 0x197B10u;
    // 0x197b10: 0x24030001
    ctx->pc = 0x197b10u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x197b14: 0x1223000a
    ctx->pc = 0x197B14u;
    {
        const bool branch_taken_0x197b14 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 3));
        ctx->pc = 0x197B18u;
        SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
        if (branch_taken_0x197b14) {
            ctx->pc = 0x197B40u;
            goto label_197b40;
        }
    }
    ctx->pc = 0x197B1Cu;
    // 0x197b1c: 0x12200003
    ctx->pc = 0x197B1Cu;
    {
        const bool branch_taken_0x197b1c = (GPR_U32(ctx, 17) == GPR_U32(ctx, 0));
        ctx->pc = 0x197B20u;
        SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
        if (branch_taken_0x197b1c) {
            ctx->pc = 0x197B2Cu;
            goto label_197b2c;
        }
    }
    ctx->pc = 0x197B24u;
    // 0x197b24: 0x10000016
    ctx->pc = 0x197B24u;
    {
        const bool branch_taken_0x197b24 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197B28u;
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 4));
        if (branch_taken_0x197b24) {
            ctx->pc = 0x197B80u;
            goto label_197b80;
        }
    }
    ctx->pc = 0x197B2Cu;
label_197b2c:
    // 0x197b2c: 0x24030047
    ctx->pc = 0x197b2cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 71));
    // 0x197b30: 0xfc30fdd0
    ctx->pc = 0x197b30u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294966736), GPR_U64(ctx, 16));
    // 0x197b34: 0xfc500020
    ctx->pc = 0x197b34u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 16));
    // 0x197b38: 0x10000010
    ctx->pc = 0x197B38u;
    {
        const bool branch_taken_0x197b38 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197B3Cu;
        WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
        if (branch_taken_0x197b38) {
            ctx->pc = 0x197B7Cu;
            goto label_197b7c;
        }
    }
    ctx->pc = 0x197B40u;
label_197b40:
    // 0x197b40: 0x24030048
    ctx->pc = 0x197b40u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 72));
    // 0x197b44: 0xfc30fdd8
    ctx->pc = 0x197b44u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294966744), GPR_U64(ctx, 16));
    // 0x197b48: 0xfc500020
    ctx->pc = 0x197b48u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 16));
    // 0x197b4c: 0x1000000b
    ctx->pc = 0x197B4Cu;
    {
        const bool branch_taken_0x197b4c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x197B50u;
        WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 3));
        if (branch_taken_0x197b4c) {
            ctx->pc = 0x197B7Cu;
            goto label_197b7c;
        }
    }
    ctx->pc = 0x197B54u;
label_197b54:
    // 0x197b54: 0x3c01002a
    ctx->pc = 0x197b54u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x197b58: 0x24040047
    ctx->pc = 0x197b58u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 71));
    // 0x197b5c: 0xfc30fdd0
    ctx->pc = 0x197b5cu;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294966736), GPR_U64(ctx, 16));
    // 0x197b60: 0x24030048
    ctx->pc = 0x197b60u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 72));
    // 0x197b64: 0x3c01002a
    ctx->pc = 0x197b64u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x197b68: 0xfc30fdd8
    ctx->pc = 0x197b68u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4294966744), GPR_U64(ctx, 16));
    // 0x197b6c: 0xfc500020
    ctx->pc = 0x197b6cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 32), GPR_U64(ctx, 16));
    // 0x197b70: 0xfc440028
    ctx->pc = 0x197b70u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 4));
    // 0x197b74: 0xfc500030
    ctx->pc = 0x197b74u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 48), GPR_U64(ctx, 16));
    // 0x197b78: 0xfc430038
    ctx->pc = 0x197b78u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 56), GPR_U64(ctx, 3));
label_197b7c:
    // 0x197b7c: 0x2293c
    ctx->pc = 0x197b7cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 4));
label_197b80:
    // 0x197b80: 0x3c07002a
    ctx->pc = 0x197b80u;
    SET_GPR_U32(ctx, 7, ((uint32_t)42 << 16));
    // 0x197b84: 0x5293e
    ctx->pc = 0x197b84u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 4));
    // 0x197b88: 0x40302d
    ctx->pc = 0x197b88u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x197b8c: 0x202d
    ctx->pc = 0x197b8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x197b90: 0xc0633ec
    ctx->pc = 0x197B90u;
    SET_GPR_U32(ctx, 31, 0x197B98u);
    ctx->pc = 0x197B94u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 4294964976));
    ctx->pc = 0x18CFB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x197B98u; }
    }
    if (ctx->pc != 0x197B98u) { return; }
    ctx->pc = 0x197B98u;
    // 0x197b98: 0xdfbf0020
    ctx->pc = 0x197b98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x197b9c: 0x24020001
    ctx->pc = 0x197b9cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x197ba0: 0x7bb10010
    ctx->pc = 0x197ba0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x197ba4: 0x7bb00000
    ctx->pc = 0x197ba4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x197ba8: 0x3e00008
    ctx->pc = 0x197BA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x197BACu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x19792Cu: goto label_19792c;
            case 0x197944u: goto label_197944;
            case 0x197948u: goto label_197948;
            case 0x197998u: goto label_197998;
            case 0x1979A0u: goto label_1979a0;
            case 0x1979A8u: goto label_1979a8;
            case 0x1979B0u: goto label_1979b0;
            case 0x1979B8u: goto label_1979b8;
            case 0x1979C0u: goto label_1979c0;
            case 0x1979C8u: goto label_1979c8;
            case 0x1979CCu: goto label_1979cc;
            case 0x197A24u: goto label_197a24;
            case 0x197A2Cu: goto label_197a2c;
            case 0x197A34u: goto label_197a34;
            case 0x197A3Cu: goto label_197a3c;
            case 0x197A44u: goto label_197a44;
            case 0x197A48u: goto label_197a48;
            case 0x197A4Cu: goto label_197a4c;
            case 0x197A9Cu: goto label_197a9c;
            case 0x197AACu: goto label_197aac;
            case 0x197B2Cu: goto label_197b2c;
            case 0x197B40u: goto label_197b40;
            case 0x197B54u: goto label_197b54;
            case 0x197B7Cu: goto label_197b7c;
            case 0x197B80u: goto label_197b80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x197BB0u;
}
