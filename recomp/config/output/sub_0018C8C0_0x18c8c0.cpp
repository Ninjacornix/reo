#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0018C8C0
// Address: 0x18c8c0 - 0x18cd00
void sub_0018C8C0_0x18c8c0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x18c8c0u;

    // 0x18c8c0: 0x27bdff00
    ctx->pc = 0x18c8c0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967040));
    // 0x18c8c4: 0x3c030007
    ctx->pc = 0x18c8c4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)7 << 16));
    // 0x18c8c8: 0xffbf0090
    ctx->pc = 0x18c8c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x18c8cc: 0x7fbe0080
    ctx->pc = 0x18c8ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 30));
    // 0x18c8d0: 0x7fb70070
    ctx->pc = 0x18c8d0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x18c8d4: 0x7fb60060
    ctx->pc = 0x18c8d4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x18c8d8: 0xc0b82d
    ctx->pc = 0x18c8d8u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c8dc: 0x7fb50050
    ctx->pc = 0x18c8dcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x18c8e0: 0xe0a82d
    ctx->pc = 0x18c8e0u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18c8e4: 0x7fb40040
    ctx->pc = 0x18c8e4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x18c8e8: 0x2a3001b
    ctx->pc = 0x18c8e8u;
    { uint32_t divisor = GPR_U32(ctx, 3); if (divisor != 0) { ctx->lo = GPR_U32(ctx, 21) / divisor; ctx->hi = GPR_U32(ctx, 3) % divisor; } else { ctx->lo = 0xFFFFFFFF; ctx->hi = GPR_U32(ctx,21); } }
    // 0x18c8ec: 0x7fb30030
    ctx->pc = 0x18c8ecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x18c8f0: 0x7fb20020
    ctx->pc = 0x18c8f0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x18c8f4: 0x7fb10010
    ctx->pc = 0x18c8f4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x18c8f8: 0x7fb00000
    ctx->pc = 0x18c8f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x18c8fc: 0x87a20108
    ctx->pc = 0x18c8fcu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 264)));
    // 0x18c900: 0x9812
    ctx->pc = 0x18c900u;
    SET_GPR_U32(ctx, 19, ctx->lo);
    // 0x18c904: 0x2a3001b
    ctx->pc = 0x18c904u;
    { uint32_t divisor = GPR_U32(ctx, 3); if (divisor != 0) { ctx->lo = GPR_U32(ctx, 21) / divisor; ctx->hi = GPR_U32(ctx, 3) % divisor; } else { ctx->lo = 0xFFFFFFFF; ctx->hi = GPR_U32(ctx,21); } }
    // 0x18c908: 0x0
    ctx->pc = 0x18c908u;
    // NOP
    // 0x18c90c: 0x0
    ctx->pc = 0x18c90cu;
    // NOP
    // 0x18c910: 0x1810
    ctx->pc = 0x18c910u;
    SET_GPR_U32(ctx, 3, ctx->hi);
    // 0x18c914: 0x10600002
    ctx->pc = 0x18C914u;
    {
        const bool branch_taken_0x18c914 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x18C918u;
        WRITE32(ADD32(GPR_U32(ctx, 29), 240), GPR_U32(ctx, 0));
        if (branch_taken_0x18c914) {
            ctx->pc = 0x18C920u;
            goto label_18c920;
        }
    }
    ctx->pc = 0x18C91Cu;
    // 0x18c91c: 0x26730001
    ctx->pc = 0x18c91cu;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 19), 1));
label_18c920:
    // 0x18c920: 0x24070001
    ctx->pc = 0x18c920u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 1));
    // 0x18c924: 0x16670003
    ctx->pc = 0x18C924u;
    {
        const bool branch_taken_0x18c924 = (GPR_U32(ctx, 19) != GPR_U32(ctx, 7));
        ctx->pc = 0x18C928u;
        SET_GPR_U64(ctx, 6, GPR_U64(ctx, 10) << (32 + 16));
        if (branch_taken_0x18c924) {
            ctx->pc = 0x18C934u;
            goto label_18c934;
        }
    }
    ctx->pc = 0x18C92Cu;
    // 0x18c92c: 0x1000003c
    ctx->pc = 0x18C92Cu;
    {
        const bool branch_taken_0x18c92c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18C930u;
        SET_GPR_S32(ctx, 17, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 272)));
        if (branch_taken_0x18c92c) {
            ctx->pc = 0x18CA20u;
            goto label_18ca20;
        }
    }
    ctx->pc = 0x18C934u;
label_18c934:
    // 0x18c934: 0x24030014
    ctx->pc = 0x18c934u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 20));
    // 0x18c938: 0x6343f
    ctx->pc = 0x18c938u;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
    // 0x18c93c: 0x10c3002e
    ctx->pc = 0x18C93Cu;
    {
        const bool branch_taken_0x18c93c = (GPR_U32(ctx, 6) == GPR_U32(ctx, 3));
        ctx->pc = 0x18C940u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 19));
        if (branch_taken_0x18c93c) {
            ctx->pc = 0x18C9F8u;
            goto label_18c9f8;
        }
    }
    ctx->pc = 0x18C944u;
    // 0x18c944: 0x10c30022
    ctx->pc = 0x18C944u;
    {
        const bool branch_taken_0x18c944 = (GPR_U32(ctx, 6) == GPR_U32(ctx, 3));
        if (branch_taken_0x18c944) {
            ctx->pc = 0x18C9D0u;
            goto label_18c9d0;
        }
    }
    ctx->pc = 0x18C94Cu;
    // 0x18c94c: 0x2403000a
    ctx->pc = 0x18c94cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 10));
    // 0x18c950: 0x10c30014
    ctx->pc = 0x18C950u;
    {
        const bool branch_taken_0x18c950 = (GPR_U32(ctx, 6) == GPR_U32(ctx, 3));
        ctx->pc = 0x18C954u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x18c950) {
            ctx->pc = 0x18C9A4u;
            goto label_18c9a4;
        }
    }
    ctx->pc = 0x18C958u;
    // 0x18c958: 0x10c30012
    ctx->pc = 0x18C958u;
    {
        const bool branch_taken_0x18c958 = (GPR_U32(ctx, 6) == GPR_U32(ctx, 3));
        if (branch_taken_0x18c958) {
            ctx->pc = 0x18C9A4u;
            goto label_18c9a4;
        }
    }
    ctx->pc = 0x18C960u;
    // 0x18c960: 0x10c70005
    ctx->pc = 0x18C960u;
    {
        const bool branch_taken_0x18c960 = (GPR_U32(ctx, 6) == GPR_U32(ctx, 7));
        if (branch_taken_0x18c960) {
            ctx->pc = 0x18C978u;
            goto label_18c978;
        }
    }
    ctx->pc = 0x18C968u;
    // 0x18c968: 0x10c00003
    ctx->pc = 0x18C968u;
    {
        const bool branch_taken_0x18c968 = (GPR_U32(ctx, 6) == GPR_U32(ctx, 0));
        if (branch_taken_0x18c968) {
            ctx->pc = 0x18C978u;
            goto label_18c978;
        }
    }
    ctx->pc = 0x18C970u;
    // 0x18c970: 0x1000002c
    ctx->pc = 0x18C970u;
    {
        const bool branch_taken_0x18c970 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18C974u;
        SET_GPR_U64(ctx, 3, GPR_U64(ctx, 9) << (32 + 16));
        if (branch_taken_0x18c970) {
            ctx->pc = 0x18CA24u;
            goto label_18ca24;
        }
    }
    ctx->pc = 0x18C978u;
label_18c978:
    // 0x18c978: 0x2343c
    ctx->pc = 0x18c978u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18c97c: 0x3c030007
    ctx->pc = 0x18c97cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)7 << 16));
    // 0x18c980: 0x6343f
    ctx->pc = 0x18c980u;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
    // 0x18c984: 0x63080
    ctx->pc = 0x18c984u;
    SET_GPR_U32(ctx, 6, SLL32(GPR_U32(ctx, 6), 2));
    // 0x18c988: 0x66001a
    ctx->pc = 0x18c988u;
    { int32_t divisor = GPR_S32(ctx, 6);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint32_t)(dividend / divisor);            ctx->hi = (uint32_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1 : -1; ctx->hi = dividend;    } }
    // 0x18c98c: 0x0
    ctx->pc = 0x18c98cu;
    // NOP
    // 0x18c990: 0x0
    ctx->pc = 0x18c990u;
    // NOP
    // 0x18c994: 0x1812
    ctx->pc = 0x18c994u;
    SET_GPR_U32(ctx, 3, ctx->lo);
    // 0x18c998: 0x38c3c
    ctx->pc = 0x18c998u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 3) << (32 + 16));
    // 0x18c99c: 0x10000020
    ctx->pc = 0x18C99Cu;
    {
        const bool branch_taken_0x18c99c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18C9A0u;
        SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
        if (branch_taken_0x18c99c) {
            ctx->pc = 0x18CA20u;
            goto label_18ca20;
        }
    }
    ctx->pc = 0x18C9A4u;
label_18c9a4:
    // 0x18c9a4: 0x2343c
    ctx->pc = 0x18c9a4u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18c9a8: 0x3c030007
    ctx->pc = 0x18c9a8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)7 << 16));
    // 0x18c9ac: 0x6343f
    ctx->pc = 0x18c9acu;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
    // 0x18c9b0: 0x63040
    ctx->pc = 0x18c9b0u;
    SET_GPR_U32(ctx, 6, SLL32(GPR_U32(ctx, 6), 1));
    // 0x18c9b4: 0x66001a
    ctx->pc = 0x18c9b4u;
    { int32_t divisor = GPR_S32(ctx, 6);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint32_t)(dividend / divisor);            ctx->hi = (uint32_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1 : -1; ctx->hi = dividend;    } }
    // 0x18c9b8: 0x0
    ctx->pc = 0x18c9b8u;
    // NOP
    // 0x18c9bc: 0x0
    ctx->pc = 0x18c9bcu;
    // NOP
    // 0x18c9c0: 0x1812
    ctx->pc = 0x18c9c0u;
    SET_GPR_U32(ctx, 3, ctx->lo);
    // 0x18c9c4: 0x38c3c
    ctx->pc = 0x18c9c4u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 3) << (32 + 16));
    // 0x18c9c8: 0x10000015
    ctx->pc = 0x18C9C8u;
    {
        const bool branch_taken_0x18c9c8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18C9CCu;
        SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
        if (branch_taken_0x18c9c8) {
            ctx->pc = 0x18CA20u;
            goto label_18ca20;
        }
    }
    ctx->pc = 0x18C9D0u;
label_18c9d0:
    // 0x18c9d0: 0x21c3c
    ctx->pc = 0x18c9d0u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18c9d4: 0x3c060007
    ctx->pc = 0x18c9d4u;
    SET_GPR_U32(ctx, 6, ((uint32_t)7 << 16));
    // 0x18c9d8: 0x31c3f
    ctx->pc = 0x18c9d8u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x18c9dc: 0xc3001a
    ctx->pc = 0x18c9dcu;
    { int32_t divisor = GPR_S32(ctx, 3);    int32_t dividend = GPR_S32(ctx, 6);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint32_t)(dividend / divisor);            ctx->hi = (uint32_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1 : -1; ctx->hi = dividend;    } }
    // 0x18c9e0: 0x0
    ctx->pc = 0x18c9e0u;
    // NOP
    // 0x18c9e4: 0x0
    ctx->pc = 0x18c9e4u;
    // NOP
    // 0x18c9e8: 0x1812
    ctx->pc = 0x18c9e8u;
    SET_GPR_U32(ctx, 3, ctx->lo);
    // 0x18c9ec: 0x38c3c
    ctx->pc = 0x18c9ecu;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 3) << (32 + 16));
    // 0x18c9f0: 0x1000000b
    ctx->pc = 0x18C9F0u;
    {
        const bool branch_taken_0x18c9f0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18C9F4u;
        SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
        if (branch_taken_0x18c9f0) {
            ctx->pc = 0x18CA20u;
            goto label_18ca20;
        }
    }
    ctx->pc = 0x18C9F8u;
label_18c9f8:
    // 0x18c9f8: 0x2343c
    ctx->pc = 0x18c9f8u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18c9fc: 0x3c030007
    ctx->pc = 0x18c9fcu;
    SET_GPR_U32(ctx, 3, ((uint32_t)7 << 16));
    // 0x18ca00: 0x6343f
    ctx->pc = 0x18ca00u;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 16));
    // 0x18ca04: 0x63043
    ctx->pc = 0x18ca04u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 1));
    // 0x18ca08: 0x66001a
    ctx->pc = 0x18ca08u;
    { int32_t divisor = GPR_S32(ctx, 6);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint32_t)(dividend / divisor);            ctx->hi = (uint32_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1 : -1; ctx->hi = dividend;    } }
    // 0x18ca0c: 0x0
    ctx->pc = 0x18ca0cu;
    // NOP
    // 0x18ca10: 0x0
    ctx->pc = 0x18ca10u;
    // NOP
    // 0x18ca14: 0x1812
    ctx->pc = 0x18ca14u;
    SET_GPR_U32(ctx, 3, ctx->lo);
    // 0x18ca18: 0x38c3c
    ctx->pc = 0x18ca18u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 3) << (32 + 16));
    // 0x18ca1c: 0x118c3f
    ctx->pc = 0x18ca1cu;
    SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
label_18ca20:
    // 0x18ca20: 0x91c3c
    ctx->pc = 0x18ca20u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 9) << (32 + 16));
label_18ca24:
    // 0x18ca24: 0x31c3f
    ctx->pc = 0x18ca24u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x18ca28: 0x14600002
    ctx->pc = 0x18CA28u;
    {
        const bool branch_taken_0x18ca28 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x18CA2Cu;
        SET_GPR_U64(ctx, 22, GPR_U64(ctx, 2) << (32 + 16));
        if (branch_taken_0x18ca28) {
            ctx->pc = 0x18CA34u;
            goto label_18ca34;
        }
    }
    ctx->pc = 0x18CA30u;
    // 0x18ca30: 0x24090001
    ctx->pc = 0x18ca30u;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 0), 1));
label_18ca34:
    // 0x18ca34: 0xa843c
    ctx->pc = 0x18ca34u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 10) << (32 + 16));
    // 0x18ca38: 0x8143c
    ctx->pc = 0x18ca38u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 8) << (32 + 16));
    // 0x18ca3c: 0x80a02d
    ctx->pc = 0x18ca3cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ca40: 0x2143f
    ctx->pc = 0x18ca40u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x18ca44: 0x10843f
    ctx->pc = 0x18ca44u;
    SET_GPR_S64(ctx, 16, GPR_S64(ctx, 16) >> (32 + 16));
    // 0x18ca48: 0x2203c
    ctx->pc = 0x18ca48u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 0));
    // 0x18ca4c: 0x16b43f
    ctx->pc = 0x18ca4cu;
    SET_GPR_S64(ctx, 22, GPR_S64(ctx, 22) >> (32 + 16));
    // 0x18ca50: 0x9143c
    ctx->pc = 0x18ca50u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 9) << (32 + 16));
    // 0x18ca54: 0xafa500cc
    ctx->pc = 0x18ca54u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 204), GPR_U32(ctx, 5));
    // 0x18ca58: 0x2143f
    ctx->pc = 0x18ca58u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x18ca5c: 0xf02d
    ctx->pc = 0x18ca5cu;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ca60: 0x21c3c
    ctx->pc = 0x18ca60u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18ca64: 0xb143c
    ctx->pc = 0x18ca64u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 11) << (32 + 16));
    // 0x18ca68: 0x832025
    ctx->pc = 0x18ca68u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x18ca6c: 0x2143f
    ctx->pc = 0x18ca6cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x18ca70: 0x101e3c
    ctx->pc = 0x18ca70u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 16) << (32 + 24));
    // 0x18ca74: 0x2103c
    ctx->pc = 0x18ca74u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x18ca78: 0xffa200d0
    ctx->pc = 0x18ca78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 208), GPR_U64(ctx, 2));
    // 0x18ca7c: 0x87a20110
    ctx->pc = 0x18ca7cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 272)));
    // 0x18ca80: 0xafa200b0
    ctx->pc = 0x18ca80u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 176), GPR_U32(ctx, 2));
    // 0x18ca84: 0x641025
    ctx->pc = 0x18ca84u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x18ca88: 0x1000008b
    ctx->pc = 0x18CA88u;
    {
        const bool branch_taken_0x18ca88 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18CA8Cu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 224), GPR_U64(ctx, 2));
        if (branch_taken_0x18ca88) {
            ctx->pc = 0x18CCB8u;
            goto label_18ccb8;
        }
    }
    ctx->pc = 0x18CA90u;
label_18ca90:
    // 0x18ca90: 0x1202001d
    ctx->pc = 0x18CA90u;
    {
        const bool branch_taken_0x18ca90 = (GPR_U32(ctx, 16) == GPR_U32(ctx, 2));
        ctx->pc = 0x18CA94u;
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) << (32 + 16));
        if (branch_taken_0x18ca90) {
            ctx->pc = 0x18CB08u;
            goto label_18cb08;
        }
    }
    ctx->pc = 0x18CA98u;
    // 0x18ca98: 0x24020013
    ctx->pc = 0x18ca98u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 19));
    // 0x18ca9c: 0x12020017
    ctx->pc = 0x18CA9Cu;
    {
        const bool branch_taken_0x18ca9c = (GPR_U32(ctx, 16) == GPR_U32(ctx, 2));
        ctx->pc = 0x18CAA0u;
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) << (32 + 16));
        if (branch_taken_0x18ca9c) {
            ctx->pc = 0x18CAFCu;
            goto label_18cafc;
        }
    }
    ctx->pc = 0x18CAA4u;
    // 0x18caa4: 0x2402000a
    ctx->pc = 0x18caa4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 10));
    // 0x18caa8: 0x12020010
    ctx->pc = 0x18CAA8u;
    {
        const bool branch_taken_0x18caa8 = (GPR_U32(ctx, 16) == GPR_U32(ctx, 2));
        ctx->pc = 0x18CAACu;
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) << (32 + 16));
        if (branch_taken_0x18caa8) {
            ctx->pc = 0x18CAECu;
            goto label_18caec;
        }
    }
    ctx->pc = 0x18CAB0u;
    // 0x18cab0: 0x24020002
    ctx->pc = 0x18cab0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
    // 0x18cab4: 0x1202000c
    ctx->pc = 0x18CAB4u;
    {
        const bool branch_taken_0x18cab4 = (GPR_U32(ctx, 16) == GPR_U32(ctx, 2));
        ctx->pc = 0x18CAB8u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x18cab4) {
            ctx->pc = 0x18CAE8u;
            goto label_18cae8;
        }
    }
    ctx->pc = 0x18CABCu;
    // 0x18cabc: 0x12020005
    ctx->pc = 0x18CABCu;
    {
        const bool branch_taken_0x18cabc = (GPR_U32(ctx, 16) == GPR_U32(ctx, 2));
        if (branch_taken_0x18cabc) {
            ctx->pc = 0x18CAD4u;
            goto label_18cad4;
        }
    }
    ctx->pc = 0x18CAC4u;
    // 0x18cac4: 0x12000004
    ctx->pc = 0x18CAC4u;
    {
        const bool branch_taken_0x18cac4 = (GPR_U32(ctx, 16) == GPR_U32(ctx, 0));
        ctx->pc = 0x18CAC8u;
        SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) << (32 + 16));
        if (branch_taken_0x18cac4) {
            ctx->pc = 0x18CAD8u;
            goto label_18cad8;
        }
    }
    ctx->pc = 0x18CACCu;
    // 0x18cacc: 0x10000015
    ctx->pc = 0x18CACCu;
    {
        const bool branch_taken_0x18cacc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18CAD0u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x18cacc) {
            ctx->pc = 0x18CB24u;
            goto label_18cb24;
        }
    }
    ctx->pc = 0x18CAD4u;
label_18cad4:
    // 0x18cad4: 0x11143c
    ctx->pc = 0x18cad4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) << (32 + 16));
label_18cad8:
    // 0x18cad8: 0x2143f
    ctx->pc = 0x18cad8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x18cadc: 0x2c21018
    ctx->pc = 0x18cadcu;
    { int64_t result = (int64_t)GPR_S32(ctx, 22) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
    // 0x18cae0: 0x1000000f
    ctx->pc = 0x18CAE0u;
    {
        const bool branch_taken_0x18cae0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18CAE4u;
        SET_GPR_U32(ctx, 18, SLL32(GPR_U32(ctx, 2), 2));
        if (branch_taken_0x18cae0) {
            ctx->pc = 0x18CB20u;
            goto label_18cb20;
        }
    }
    ctx->pc = 0x18CAE8u;
label_18cae8:
    // 0x18cae8: 0x11143c
    ctx->pc = 0x18cae8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) << (32 + 16));
label_18caec:
    // 0x18caec: 0x2143f
    ctx->pc = 0x18caecu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x18caf0: 0x2c21018
    ctx->pc = 0x18caf0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 22) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
    // 0x18caf4: 0x1000000a
    ctx->pc = 0x18CAF4u;
    {
        const bool branch_taken_0x18caf4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18CAF8u;
        SET_GPR_U32(ctx, 18, SLL32(GPR_U32(ctx, 2), 1));
        if (branch_taken_0x18caf4) {
            ctx->pc = 0x18CB20u;
            goto label_18cb20;
        }
    }
    ctx->pc = 0x18CAFCu;
label_18cafc:
    // 0x18cafc: 0x2143f
    ctx->pc = 0x18cafcu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x18cb00: 0x10000007
    ctx->pc = 0x18CB00u;
    {
        const bool branch_taken_0x18cb00 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18CB04u;
        { int64_t result = (int64_t)GPR_S32(ctx, 22) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 18, (int32_t)(uint32_t)result); }
        if (branch_taken_0x18cb00) {
            ctx->pc = 0x18CB20u;
            goto label_18cb20;
        }
    }
    ctx->pc = 0x18CB08u;
label_18cb08:
    // 0x18cb08: 0x2143f
    ctx->pc = 0x18cb08u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x18cb0c: 0x2c21018
    ctx->pc = 0x18cb0cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 22) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
    // 0x18cb10: 0x4410003
    ctx->pc = 0x18CB10u;
    {
        const bool branch_taken_0x18cb10 = (GPR_S32(ctx, 2) >= 0);
        ctx->pc = 0x18CB14u;
        SET_GPR_S32(ctx, 18, SRA32(GPR_S32(ctx, 2), 1));
        if (branch_taken_0x18cb10) {
            ctx->pc = 0x18CB20u;
            goto label_18cb20;
        }
    }
    ctx->pc = 0x18CB18u;
    // 0x18cb18: 0x24420001
    ctx->pc = 0x18cb18u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x18cb1c: 0x29043
    ctx->pc = 0x18cb1cu;
    SET_GPR_S32(ctx, 18, SRA32(GPR_S32(ctx, 2), 1));
label_18cb20:
    // 0x18cb20: 0x280202d
    ctx->pc = 0x18cb20u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
label_18cb24:
    // 0x18cb24: 0x24050006
    ctx->pc = 0x18cb24u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 6));
    // 0x18cb28: 0x302d
    ctx->pc = 0x18cb28u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18cb2c: 0xc06317c
    ctx->pc = 0x18CB2Cu;
    SET_GPR_U32(ctx, 31, 0x18CB34u);
    ctx->pc = 0x18CB30u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18C5F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C5F0_0x18c5f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CB34u; }
    }
    if (ctx->pc != 0x18CB34u) { return; }
    ctx->pc = 0x18CB34u;
    // 0x18cb34: 0x3c031300
    ctx->pc = 0x18cb34u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4864 << 16));
    // 0x18cb38: 0x3c025100
    ctx->pc = 0x18cb38u;
    SET_GPR_U32(ctx, 2, ((uint32_t)20736 << 16));
    // 0x18cb3c: 0xae830008
    ctx->pc = 0x18cb3cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 8), GPR_U32(ctx, 3));
    // 0x18cb40: 0x34420006
    ctx->pc = 0x18cb40u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 6));
    // 0x18cb44: 0xae82000c
    ctx->pc = 0x18cb44u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 12), GPR_U32(ctx, 2));
    // 0x18cb48: 0x24040050
    ctx->pc = 0x18cb48u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 80));
    // 0x18cb4c: 0x3c021000
    ctx->pc = 0x18cb4cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x18cb50: 0x2183c
    ctx->pc = 0x18cb50u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x18cb54: 0x24020004
    ctx->pc = 0x18cb54u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
    // 0x18cb58: 0x431825
    ctx->pc = 0x18cb58u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18cb5c: 0x2402000e
    ctx->pc = 0x18cb5cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 14));
    // 0x18cb60: 0xfe830010
    ctx->pc = 0x18cb60u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 16), GPR_U64(ctx, 3));
    // 0x18cb64: 0xfe820018
    ctx->pc = 0x18cb64u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 24), GPR_U64(ctx, 2));
    // 0x18cb68: 0x87a20100
    ctx->pc = 0x18cb68u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 256)));
    // 0x18cb6c: 0x40102d
    ctx->pc = 0x18cb6cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18cb70: 0x21c3c
    ctx->pc = 0x18cb70u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18cb74: 0xdfa200e0
    ctx->pc = 0x18cb74u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 29), 224)));
    // 0x18cb78: 0xfe820020
    ctx->pc = 0x18cb78u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 32), GPR_U64(ctx, 2));
    // 0x18cb7c: 0xfe840028
    ctx->pc = 0x18cb7cu;
    WRITE64(ADD32(GPR_U32(ctx, 20), 40), GPR_U64(ctx, 4));
    // 0x18cb80: 0xdfa200d0
    ctx->pc = 0x18cb80u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 29), 208)));
    // 0x18cb84: 0x24040052
    ctx->pc = 0x18cb84u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 82));
    // 0x18cb88: 0x431025
    ctx->pc = 0x18cb88u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18cb8c: 0xfe820030
    ctx->pc = 0x18cb8cu;
    WRITE64(ADD32(GPR_U32(ctx, 20), 48), GPR_U64(ctx, 2));
    // 0x18cb90: 0x24030053
    ctx->pc = 0x18cb90u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 83));
    // 0x18cb94: 0x24020051
    ctx->pc = 0x18cb94u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 81));
    // 0x18cb98: 0xfe820038
    ctx->pc = 0x18cb98u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 56), GPR_U64(ctx, 2));
    // 0x18cb9c: 0x11143c
    ctx->pc = 0x18cb9cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 17) << (32 + 16));
    // 0x18cba0: 0x2143f
    ctx->pc = 0x18cba0u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x18cba4: 0x2103c
    ctx->pc = 0x18cba4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x18cba8: 0x2c21025
    ctx->pc = 0x18cba8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 22), GPR_U32(ctx, 2)));
    // 0x18cbac: 0xfe820040
    ctx->pc = 0x18cbacu;
    WRITE64(ADD32(GPR_U32(ctx, 20), 64), GPR_U64(ctx, 2));
    // 0x18cbb0: 0x2662ffff
    ctx->pc = 0x18cbb0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 19), 4294967295));
    // 0x18cbb4: 0xfe840048
    ctx->pc = 0x18cbb4u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 72), GPR_U64(ctx, 4));
    // 0x18cbb8: 0xfe800050
    ctx->pc = 0x18cbb8u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 80), GPR_U64(ctx, 0));
    // 0x18cbbc: 0x3c2102b
    ctx->pc = 0x18cbbcu;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 30), GPR_U32(ctx, 2)));
    // 0x18cbc0: 0x1440001a
    ctx->pc = 0x18CBC0u;
    {
        const bool branch_taken_0x18cbc0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x18CBC4u;
        WRITE64(ADD32(GPR_U32(ctx, 20), 88), GPR_U64(ctx, 3));
        if (branch_taken_0x18cbc0) {
            ctx->pc = 0x18CC2Cu;
            goto label_18cc2c;
        }
    }
    ctx->pc = 0x18CBC8u;
    // 0x18cbc8: 0x151102
    ctx->pc = 0x18cbc8u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 21), 4));
    // 0x18cbcc: 0x34038000
    ctx->pc = 0x18cbccu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 0), 32768));
    // 0x18cbd0: 0xafa200a0
    ctx->pc = 0x18cbd0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 160), GPR_U32(ctx, 2));
    // 0x18cbd4: 0x2e0302d
    ctx->pc = 0x18cbd4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18cbd8: 0x3c020800
    ctx->pc = 0x18cbd8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)2048 << 16));
    // 0x18cbdc: 0x2203c
    ctx->pc = 0x18cbdcu;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 2) << (32 + 0));
    // 0x18cbe0: 0x9fa200a0
    ctx->pc = 0x18cbe0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x18cbe4: 0x40282d
    ctx->pc = 0x18cbe4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18cbe8: 0x26820070
    ctx->pc = 0x18cbe8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 20), 112));
    // 0x18cbec: 0xafa200f0
    ctx->pc = 0x18cbecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 240), GPR_U32(ctx, 2));
    // 0x18cbf0: 0x641025
    ctx->pc = 0x18cbf0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x18cbf4: 0xa21025
    ctx->pc = 0x18cbf4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x18cbf8: 0x8fa400f0
    ctx->pc = 0x18cbf8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 29), 240)));
    // 0x18cbfc: 0x8fa500a0
    ctx->pc = 0x18cbfcu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x18cc00: 0xfe820060
    ctx->pc = 0x18cc00u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 96), GPR_U64(ctx, 2));
    // 0x18cc04: 0xfe800068
    ctx->pc = 0x18cc04u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 104), GPR_U64(ctx, 0));
    // 0x18cc08: 0x8fa700cc
    ctx->pc = 0x18cc08u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 29), 204)));
    // 0x18cc0c: 0xc0631b8
    ctx->pc = 0x18CC0Cu;
    SET_GPR_U32(ctx, 31, 0x18CC14u);
    ctx->pc = 0x18CC10u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18C6E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C6E0_0x18c6e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CC14u; }
    }
    if (ctx->pc != 0x18CC14u) { return; }
    ctx->pc = 0x18CC14u;
    // 0x18cc14: 0xae800078
    ctx->pc = 0x18cc14u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 120), GPR_U32(ctx, 0));
    // 0x18cc18: 0x3c035100
    ctx->pc = 0x18cc18u;
    SET_GPR_U32(ctx, 3, ((uint32_t)20736 << 16));
    // 0x18cc1c: 0x8fa200a0
    ctx->pc = 0x18cc1cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x18cc20: 0x431025
    ctx->pc = 0x18cc20u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18cc24: 0x10000023
    ctx->pc = 0x18CC24u;
    {
        const bool branch_taken_0x18cc24 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18CC28u;
        WRITE32(ADD32(GPR_U32(ctx, 20), 124), GPR_U32(ctx, 2));
        if (branch_taken_0x18cc24) {
            ctx->pc = 0x18CCB4u;
            goto label_18ccb4;
        }
    }
    ctx->pc = 0x18CC2Cu;
label_18cc2c:
    // 0x18cc2c: 0x3c030800
    ctx->pc = 0x18cc2cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)2048 << 16));
    // 0x18cc30: 0x3402f000
    ctx->pc = 0x18cc30u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 0), 61440));
    // 0x18cc34: 0x3183c
    ctx->pc = 0x18cc34u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x18cc38: 0x26840070
    ctx->pc = 0x18cc38u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 20), 112));
    // 0x18cc3c: 0x431025
    ctx->pc = 0x18cc3cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18cc40: 0x24057000
    ctx->pc = 0x18cc40u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 28672));
    // 0x18cc44: 0xfe820060
    ctx->pc = 0x18cc44u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 96), GPR_U64(ctx, 2));
    // 0x18cc48: 0x2e0302d
    ctx->pc = 0x18cc48u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18cc4c: 0x382d
    ctx->pc = 0x18cc4cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18cc50: 0x402d
    ctx->pc = 0x18cc50u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18cc54: 0xc0631a0
    ctx->pc = 0x18CC54u;
    SET_GPR_U32(ctx, 31, 0x18CC5Cu);
    ctx->pc = 0x18CC58u;
    WRITE64(ADD32(GPR_U32(ctx, 20), 104), GPR_U64(ctx, 0));
    ctx->pc = 0x18C680u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018C680_0x18c680(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18CC5Cu; }
    }
    if (ctx->pc != 0x18CC5Cu) { return; }
    ctx->pc = 0x18CC5Cu;
    // 0x18cc5c: 0x3c025100
    ctx->pc = 0x18cc5cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)20736 << 16));
    // 0x18cc60: 0x111c3c
    ctx->pc = 0x18cc60u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) << (32 + 16));
    // 0x18cc64: 0xae800078
    ctx->pc = 0x18cc64u;
    WRITE32(ADD32(GPR_U32(ctx, 20), 120), GPR_U32(ctx, 0));
    // 0x18cc68: 0x34427000
    ctx->pc = 0x18cc68u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 28672));
    // 0x18cc6c: 0xae82007c
    ctx->pc = 0x18cc6cu;
    WRITE32(ADD32(GPR_U32(ctx, 20), 124), GPR_U32(ctx, 2));
    // 0x18cc70: 0x31c3f
    ctx->pc = 0x18cc70u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 16));
    // 0x18cc74: 0x87a20100
    ctx->pc = 0x18cc74u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 256)));
    // 0x18cc78: 0x2f2b821
    ctx->pc = 0x18cc78u;
    SET_GPR_U32(ctx, 23, ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 18)));
    // 0x18cc7c: 0x511021
    ctx->pc = 0x18cc7cu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 17)));
    // 0x18cc80: 0xa7a20100
    ctx->pc = 0x18cc80u;
    WRITE16(ADD32(GPR_U32(ctx, 29), 256), (uint16_t)GPR_U32(ctx, 2));
    // 0x18cc84: 0x87a20100
    ctx->pc = 0x18cc84u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 256)));
    // 0x18cc88: 0x431821
    ctx->pc = 0x18cc88u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x18cc8c: 0x8fa200b0
    ctx->pc = 0x18cc8cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x18cc90: 0x43082a
    ctx->pc = 0x18cc90u;
    SET_GPR_U32(ctx, 1, SLT32(GPR_S32(ctx, 2), GPR_S32(ctx, 3)));
    // 0x18cc94: 0x10200006
    ctx->pc = 0x18CC94u;
    {
        const bool branch_taken_0x18cc94 = (GPR_U32(ctx, 1) == GPR_U32(ctx, 0));
        ctx->pc = 0x18CC98u;
        SET_GPR_S32(ctx, 20, ADD32(GPR_U32(ctx, 20), 128));
        if (branch_taken_0x18cc94) {
            ctx->pc = 0x18CCB0u;
            goto label_18ccb0;
        }
    }
    ctx->pc = 0x18CC9Cu;
    // 0x18cc9c: 0x40182d
    ctx->pc = 0x18cc9cu;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18cca0: 0x87a20100
    ctx->pc = 0x18cca0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 256)));
    // 0x18cca4: 0x621023
    ctx->pc = 0x18cca4u;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x18cca8: 0x28c3c
    ctx->pc = 0x18cca8u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 2) << (32 + 16));
    // 0x18ccac: 0x118c3f
    ctx->pc = 0x18ccacu;
    SET_GPR_S64(ctx, 17, GPR_S64(ctx, 17) >> (32 + 16));
label_18ccb0:
    // 0x18ccb0: 0x2b2a823
    ctx->pc = 0x18ccb0u;
    SET_GPR_U32(ctx, 21, SUB32(GPR_U32(ctx, 21), GPR_U32(ctx, 18)));
label_18ccb4:
    // 0x18ccb4: 0x27de0001
    ctx->pc = 0x18ccb4u;
    SET_GPR_S32(ctx, 30, ADD32(GPR_U32(ctx, 30), 1));
label_18ccb8:
    // 0x18ccb8: 0x3d3102b
    ctx->pc = 0x18ccb8u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 30), GPR_U32(ctx, 19)));
    // 0x18ccbc: 0x1440ff74
    ctx->pc = 0x18CCBCu;
    {
        const bool branch_taken_0x18ccbc = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x18CCC0u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 20));
        if (branch_taken_0x18ccbc) {
            ctx->pc = 0x18CA90u;
            goto label_18ca90;
        }
    }
    ctx->pc = 0x18CCC4u;
    // 0x18ccc4: 0x8fa200f0
    ctx->pc = 0x18ccc4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 240)));
    // 0x18ccc8: 0xdfbf0090
    ctx->pc = 0x18ccc8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x18cccc: 0x7bbe0080
    ctx->pc = 0x18ccccu;
    SET_GPR_VEC(ctx, 30, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x18ccd0: 0x7bb70070
    ctx->pc = 0x18ccd0u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x18ccd4: 0x7bb60060
    ctx->pc = 0x18ccd4u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x18ccd8: 0x7bb50050
    ctx->pc = 0x18ccd8u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x18ccdc: 0x7bb40040
    ctx->pc = 0x18ccdcu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x18cce0: 0x7bb30030
    ctx->pc = 0x18cce0u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18cce4: 0x7bb20020
    ctx->pc = 0x18cce4u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18cce8: 0x7bb10010
    ctx->pc = 0x18cce8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18ccec: 0x7bb00000
    ctx->pc = 0x18ccecu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18ccf0: 0x3e00008
    ctx->pc = 0x18CCF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18CCF4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 256));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18C920u: goto label_18c920;
            case 0x18C934u: goto label_18c934;
            case 0x18C978u: goto label_18c978;
            case 0x18C9A4u: goto label_18c9a4;
            case 0x18C9D0u: goto label_18c9d0;
            case 0x18C9F8u: goto label_18c9f8;
            case 0x18CA20u: goto label_18ca20;
            case 0x18CA24u: goto label_18ca24;
            case 0x18CA34u: goto label_18ca34;
            case 0x18CA90u: goto label_18ca90;
            case 0x18CAD4u: goto label_18cad4;
            case 0x18CAD8u: goto label_18cad8;
            case 0x18CAE8u: goto label_18cae8;
            case 0x18CAECu: goto label_18caec;
            case 0x18CAFCu: goto label_18cafc;
            case 0x18CB08u: goto label_18cb08;
            case 0x18CB20u: goto label_18cb20;
            case 0x18CB24u: goto label_18cb24;
            case 0x18CC2Cu: goto label_18cc2c;
            case 0x18CCB0u: goto label_18ccb0;
            case 0x18CCB4u: goto label_18ccb4;
            case 0x18CCB8u: goto label_18ccb8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18CCF8u;
    // 0x18ccf8: 0x0
    ctx->pc = 0x18ccf8u;
    // NOP
    // 0x18ccfc: 0x0
    ctx->pc = 0x18ccfcu;
    // NOP
}
