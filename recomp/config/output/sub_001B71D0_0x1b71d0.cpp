#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001B71D0
// Address: 0x1b71d0 - 0x1b74d0
void sub_001B71D0_0x1b71d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1b71d0u;

    // 0x1b71d0: 0x27bdffc0
    ctx->pc = 0x1b71d0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1b71d4: 0x24080014
    ctx->pc = 0x1b71d4u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 20));
    // 0x1b71d8: 0xffbf0030
    ctx->pc = 0x1b71d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1b71dc: 0x482d
    ctx->pc = 0x1b71dcu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b71e0: 0x7fb10020
    ctx->pc = 0x1b71e0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x1b71e4: 0x502d
    ctx->pc = 0x1b71e4u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b71e8: 0x7fb00010
    ctx->pc = 0x1b71e8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1b71ec: 0x80882d
    ctx->pc = 0x1b71ecu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b71f0: 0x8c8b000c
    ctx->pc = 0x1b71f0u;
    SET_GPR_U32(ctx, 11, READ32(ADD32(GPR_U32(ctx, 4), 12)));
    // 0x1b71f4: 0xe0802d
    ctx->pc = 0x1b71f4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b71f8: 0xa0202d
    ctx->pc = 0x1b71f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b71fc: 0xffab0000
    ctx->pc = 0x1b71fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 11));
    // 0x1b7200: 0xc0282d
    ctx->pc = 0x1b7200u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7204: 0x8e260054
    ctx->pc = 0x1b7204u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 17), 84)));
    // 0x1b7208: 0xc06dbf4
    ctx->pc = 0x1B7208u;
    SET_GPR_U32(ctx, 31, 0x1B7210u);
    ctx->pc = 0x1B720Cu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1B6FD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001B6FD0_0x1b6fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1B7210u; }
    }
    if (ctx->pc != 0x1B7210u) { return; }
    ctx->pc = 0x1B7210u;
    // 0x1b7210: 0x3c01002a
    ctx->pc = 0x1b7210u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1b7214: 0x40282d
    ctx->pc = 0x1b7214u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1b7218: 0x8c26f9bc
    ctx->pc = 0x1b7218u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 1), 4294965692)));
    // 0x1b721c: 0x24021000
    ctx->pc = 0x1b721cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1b7220: 0x461823
    ctx->pc = 0x1b7220u;
    SET_GPR_U32(ctx, 3, SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x1b7224: 0x4610003
    ctx->pc = 0x1B7224u;
    {
        const bool branch_taken_0x1b7224 = (GPR_S32(ctx, 3) >= 0);
        ctx->pc = 0x1B7228u;
        SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 1));
        if (branch_taken_0x1b7224) {
            ctx->pc = 0x1B7234u;
            goto label_1b7234;
        }
    }
    ctx->pc = 0x1B722Cu;
    // 0x1b722c: 0x24620001
    ctx->pc = 0x1b722cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 3), 1));
    // 0x1b7230: 0x21043
    ctx->pc = 0x1b7230u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
label_1b7234:
    // 0x1b7234: 0x3c01002a
    ctx->pc = 0x1b7234u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1b7238: 0x24041000
    ctx->pc = 0x1b7238u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1b723c: 0x8c23f9c0
    ctx->pc = 0x1b723cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 4294965696)));
    // 0x1b7240: 0x21100
    ctx->pc = 0x1b7240u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 4));
    // 0x1b7244: 0x832023
    ctx->pc = 0x1b7244u;
    SET_GPR_U32(ctx, 4, SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1b7248: 0x4810003
    ctx->pc = 0x1B7248u;
    {
        const bool branch_taken_0x1b7248 = (GPR_S32(ctx, 4) >= 0);
        ctx->pc = 0x1B724Cu;
        SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 4), 1));
        if (branch_taken_0x1b7248) {
            ctx->pc = 0x1B7258u;
            goto label_1b7258;
        }
    }
    ctx->pc = 0x1B7250u;
    // 0x1b7250: 0x24830001
    ctx->pc = 0x1b7250u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 4), 1));
    // 0x1b7254: 0x31843
    ctx->pc = 0x1b7254u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 1));
label_1b7258:
    // 0x1b7258: 0x44860800
    ctx->pc = 0x1b7258u;
    *(uint32_t*)&ctx->f[1] = GPR_U32(ctx, 6);
    // 0x1b725c: 0x34900
    ctx->pc = 0x1b725cu;
    SET_GPR_U32(ctx, 9, SLL32(GPR_U32(ctx, 3), 4));
    // 0x1b7260: 0xc6200070
    ctx->pc = 0x1b7260u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 17), 112)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x1b7264: 0x8e23006c
    ctx->pc = 0x1b7264u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 108)));
    // 0x1b7268: 0x468008a0
    ctx->pc = 0x1b7268u;
    ctx->f[2] = FPU_CVT_S_W(*(int32_t*)&ctx->f[1]);
    // 0x1b726c: 0x3c064420
    ctx->pc = 0x1b726cu;
    SET_GPR_U32(ctx, 6, ((uint32_t)17440 << 16));
    // 0x1b7270: 0x8e280074
    ctx->pc = 0x1b7270u;
    SET_GPR_U32(ctx, 8, READ32(ADD32(GPR_U32(ctx, 17), 116)));
    // 0x1b7274: 0x3c044180
    ctx->pc = 0x1b7274u;
    SET_GPR_U32(ctx, 4, ((uint32_t)16768 << 16));
    // 0x1b7278: 0x8e270098
    ctx->pc = 0x1b7278u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 17), 152)));
    // 0x1b727c: 0x2031806
    ctx->pc = 0x1b727cu;
    SET_GPR_U32(ctx, 3, SRL32(GPR_U32(ctx, 3), GPR_U32(ctx, 16) & 0x1F));
    // 0x1b7280: 0x44860800
    ctx->pc = 0x1b7280u;
    *(uint32_t*)&ctx->f[1] = GPR_U32(ctx, 6);
    // 0x1b7284: 0x0
    ctx->pc = 0x1b7284u;
    // NOP
    // 0x1b7288: 0x46800020
    ctx->pc = 0x1b7288u;
    ctx->f[0] = FPU_CVT_S_W(*(int32_t*)&ctx->f[0]);
    // 0x1b728c: 0x84100
    ctx->pc = 0x1b728cu;
    SET_GPR_U32(ctx, 8, SLL32(GPR_U32(ctx, 8), 4));
    // 0x1b7290: 0x46011083
    ctx->pc = 0x1b7290u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ ctx->f[2] = copysignf(INFINITY, ctx->f[2] * 0.0f); } else ctx->f[2] = ctx->f[2] / ctx->f[1];
    // 0x1b7294: 0x46020042
    ctx->pc = 0x1b7294u;
    ctx->f[1] = FPU_MUL_S(ctx->f[0], ctx->f[2]);
    // 0x1b7298: 0x44840000
    ctx->pc = 0x1b7298u;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 4);
    // 0x1b729c: 0x0
    ctx->pc = 0x1b729cu;
    // NOP
    // 0x1b72a0: 0x46010002
    ctx->pc = 0x1b72a0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[1]);
    // 0x1b72a4: 0x46000024
    ctx->pc = 0x1b72a4u;
    *(int32_t*)&ctx->f[0] = FPU_CVT_W_S(ctx->f[0]);
    // 0x1b72a8: 0x44060000
    ctx->pc = 0x1b72a8u;
    SET_GPR_U32(ctx, 6, *(uint32_t*)&ctx->f[0]);
    // 0x1b72ac: 0x4600004
    ctx->pc = 0x1B72ACu;
    {
        const bool branch_taken_0x1b72ac = (GPR_S32(ctx, 3) < 0);
        ctx->pc = 0x1B72B0u;
        SET_GPR_U32(ctx, 7, SLL32(GPR_U32(ctx, 7), 4));
        if (branch_taken_0x1b72ac) {
            ctx->pc = 0x1B72C0u;
            goto label_1b72c0;
        }
    }
    ctx->pc = 0x1B72B4u;
    // 0x1b72b4: 0x44830000
    ctx->pc = 0x1b72b4u;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 3);
    // 0x1b72b8: 0x10000008
    ctx->pc = 0x1B72B8u;
    {
        const bool branch_taken_0x1b72b8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1B72BCu;
        ctx->f[0] = FPU_CVT_S_W(*(int32_t*)&ctx->f[0]);
        if (branch_taken_0x1b72b8) {
            ctx->pc = 0x1B72DCu;
            goto label_1b72dc;
        }
    }
    ctx->pc = 0x1B72C0u;
label_1b72c0:
    // 0x1b72c0: 0x32042
    ctx->pc = 0x1b72c0u;
    SET_GPR_U32(ctx, 4, SRL32(GPR_U32(ctx, 3), 1));
    // 0x1b72c4: 0x30630001
    ctx->pc = 0x1b72c4u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), 1));
    // 0x1b72c8: 0x832025
    ctx->pc = 0x1b72c8u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1b72cc: 0x44840000
    ctx->pc = 0x1b72ccu;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 4);
    // 0x1b72d0: 0x0
    ctx->pc = 0x1b72d0u;
    // NOP
    // 0x1b72d4: 0x46800020
    ctx->pc = 0x1b72d4u;
    ctx->f[0] = FPU_CVT_S_W(*(int32_t*)&ctx->f[0]);
    // 0x1b72d8: 0x46000000
    ctx->pc = 0x1b72d8u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[0]);
label_1b72dc:
    // 0x1b72dc: 0x46020082
    ctx->pc = 0x1b72dcu;
    ctx->f[2] = FPU_MUL_S(ctx->f[0], ctx->f[2]);
    // 0x1b72e0: 0x3c044180
    ctx->pc = 0x1b72e0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)16768 << 16));
    // 0x1b72e4: 0x3c034f00
    ctx->pc = 0x1b72e4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)20224 << 16));
    // 0x1b72e8: 0x44840800
    ctx->pc = 0x1b72e8u;
    *(uint32_t*)&ctx->f[1] = GPR_U32(ctx, 4);
    // 0x1b72ec: 0x44830000
    ctx->pc = 0x1b72ecu;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 3);
    // 0x1b72f0: 0x0
    ctx->pc = 0x1b72f0u;
    // NOP
    // 0x1b72f4: 0x46020842
    ctx->pc = 0x1b72f4u;
    ctx->f[1] = FPU_MUL_S(ctx->f[1], ctx->f[2]);
    // 0x1b72f8: 0x46010036
    ctx->pc = 0x1b72f8u;
    ctx->fcr31 = (FPU_C_OLE_S(ctx->f[0], ctx->f[1])) ? (ctx->fcr31 | 0x800000) : (ctx->fcr31 & ~0x800000);
    // 0x1b72fc: 0x45010005
    ctx->pc = 0x1B72FCu;
    {
        const bool branch_taken_0x1b72fc = ((ctx->fcr31 & 0x800000));
        if (branch_taken_0x1b72fc) {
            ctx->pc = 0x1B7314u;
            goto label_1b7314;
        }
    }
    ctx->pc = 0x1B7304u;
    // 0x1b7304: 0x46000864
    ctx->pc = 0x1b7304u;
    *(int32_t*)&ctx->f[1] = FPU_CVT_W_S(ctx->f[1]);
    // 0x1b7308: 0x44040800
    ctx->pc = 0x1b7308u;
    SET_GPR_U32(ctx, 4, *(uint32_t*)&ctx->f[1]);
    // 0x1b730c: 0x10000007
    ctx->pc = 0x1B730Cu;
    {
        const bool branch_taken_0x1b730c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1b730c) {
            ctx->pc = 0x1B732Cu;
            goto label_1b732c;
        }
    }
    ctx->pc = 0x1B7314u;
label_1b7314:
    // 0x1b7314: 0x46000841
    ctx->pc = 0x1b7314u;
    ctx->f[1] = FPU_SUB_S(ctx->f[1], ctx->f[0]);
    // 0x1b7318: 0x3c038000
    ctx->pc = 0x1b7318u;
    SET_GPR_U32(ctx, 3, ((uint32_t)32768 << 16));
    // 0x1b731c: 0x46000864
    ctx->pc = 0x1b731cu;
    *(int32_t*)&ctx->f[1] = FPU_CVT_W_S(ctx->f[1]);
    // 0x1b7320: 0x44040800
    ctx->pc = 0x1b7320u;
    SET_GPR_U32(ctx, 4, *(uint32_t*)&ctx->f[1]);
    // 0x1b7324: 0x0
    ctx->pc = 0x1b7324u;
    // NOP
    // 0x1b7328: 0x832025
    ctx->pc = 0x1b7328u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
label_1b732c:
    // 0x1b732c: 0x3c01002a
    ctx->pc = 0x1b732cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1b7330: 0x8c23f9b4
    ctx->pc = 0x1b7330u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 4294965684)));
    // 0x1b7334: 0x14600003
    ctx->pc = 0x1B7334u;
    {
        const bool branch_taken_0x1b7334 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x1B7338u;
        SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
        if (branch_taken_0x1b7334) {
            ctx->pc = 0x1B7344u;
            goto label_1b7344;
        }
    }
    ctx->pc = 0x1B733Cu;
    // 0x1b733c: 0x84043
    ctx->pc = 0x1b733cu;
    SET_GPR_S32(ctx, 8, SRA32(GPR_S32(ctx, 8), 1));
    // 0x1b7340: 0x73842
    ctx->pc = 0x1b7340u;
    SET_GPR_U32(ctx, 7, SRL32(GPR_U32(ctx, 7), 1));
label_1b7344:
    // 0x1b7344: 0x1284021
    ctx->pc = 0x1b7344u;
    SET_GPR_U32(ctx, 8, ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 8)));
    // 0x1b7348: 0x641021
    ctx->pc = 0x1b7348u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b734c: 0x3303c
    ctx->pc = 0x1b734cu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1b7350: 0x2183c
    ctx->pc = 0x1b7350u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b7354: 0x8203c
    ctx->pc = 0x1b7354u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 8) << (32 + 0));
    // 0x1b7358: 0x1071021
    ctx->pc = 0x1b7358u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 7)));
    // 0x1b735c: 0x4203f
    ctx->pc = 0x1b735cu;
    SET_GPR_S64(ctx, 4, GPR_S64(ctx, 4) >> (32 + 0));
    // 0x1b7360: 0x2103c
    ctx->pc = 0x1b7360u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b7364: 0x8e2d000c
    ctx->pc = 0x1b7364u;
    SET_GPR_U32(ctx, 13, READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x1b7368: 0x2103f
    ctx->pc = 0x1b7368u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1b736c: 0x6303f
    ctx->pc = 0x1b736cu;
    SET_GPR_S64(ctx, 6, GPR_S64(ctx, 6) >> (32 + 0));
    // 0x1b7370: 0x42438
    ctx->pc = 0x1b7370u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << 16);
    // 0x1b7374: 0x3183f
    ctx->pc = 0x1b7374u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x1b7378: 0xc43825
    ctx->pc = 0x1b7378u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 6), GPR_U32(ctx, 4)));
    // 0x1b737c: 0x21438
    ctx->pc = 0x1b737cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1b7380: 0x622025
    ctx->pc = 0x1b7380u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1b7384: 0x3c065100
    ctx->pc = 0x1b7384u;
    SET_GPR_U32(ctx, 6, ((uint32_t)20736 << 16));
    // 0x1b7388: 0x3c021000
    ctx->pc = 0x1b7388u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1b738c: 0x34cb0008
    ctx->pc = 0x1b738cu;
    SET_GPR_U32(ctx, 11, OR32(GPR_U32(ctx, 6), 8));
    // 0x1b7390: 0x344c0008
    ctx->pc = 0x1b7390u;
    SET_GPR_U32(ctx, 12, OR32(GPR_U32(ctx, 2), 8));
    // 0x1b7394: 0x2183c
    ctx->pc = 0x1b7394u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b7398: 0xacac0000
    ctx->pc = 0x1b7398u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 12));
    // 0x1b739c: 0x24020003
    ctx->pc = 0x1b739cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
    // 0x1b73a0: 0xaca00004
    ctx->pc = 0x1b73a0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 0));
    // 0x1b73a4: 0x435025
    ctx->pc = 0x1b73a4u;
    SET_GPR_U32(ctx, 10, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b73a8: 0xaca00008
    ctx->pc = 0x1b73a8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 8), GPR_U32(ctx, 0));
    // 0x1b73ac: 0x24030005
    ctx->pc = 0x1b73acu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 5));
    // 0x1b73b0: 0xacab000c
    ctx->pc = 0x1b73b0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 11));
    // 0x1b73b4: 0x3c025540
    ctx->pc = 0x1b73b4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)21824 << 16));
    // 0x1b73b8: 0x2409000e
    ctx->pc = 0x1b73b8u;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 0), 14));
    // 0x1b73bc: 0xfcaa0010
    ctx->pc = 0x1b73bcu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 16), GPR_U64(ctx, 10));
    // 0x1b73c0: 0xfca90018
    ctx->pc = 0x1b73c0u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 24), GPR_U64(ctx, 9));
    // 0x1b73c4: 0xd6100
    ctx->pc = 0x1b73c4u;
    SET_GPR_U32(ctx, 12, SLL32(GPR_U32(ctx, 13), 4));
    // 0x1b73c8: 0x3183c
    ctx->pc = 0x1b73c8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1b73cc: 0x34424000
    ctx->pc = 0x1b73ccu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 16384));
    // 0x1b73d0: 0x431825
    ctx->pc = 0x1b73d0u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1b73d4: 0x2408003f
    ctx->pc = 0x1b73d4u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 63));
    // 0x1b73d8: 0xfca00020
    ctx->pc = 0x1b73d8u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 32), GPR_U64(ctx, 0));
    // 0x1b73dc: 0x20c1006
    ctx->pc = 0x1b73dcu;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 12), GPR_U32(ctx, 16) & 0x1F));
    // 0x1b73e0: 0xfca80028
    ctx->pc = 0x1b73e0u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 40), GPR_U64(ctx, 8));
    // 0x1b73e4: 0x24460008
    ctx->pc = 0x1b73e4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 2), 8));
    // 0x1b73e8: 0x9e300054
    ctx->pc = 0x1b73e8u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 17), 84)));
    // 0x1b73ec: 0x25820008
    ctx->pc = 0x1b73ecu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 12), 8));
    // 0x1b73f0: 0x8e390058
    ctx->pc = 0x1b73f0u;
    SET_GPR_U32(ctx, 25, READ32(ADD32(GPR_U32(ctx, 17), 88)));
    // 0x1b73f4: 0x2103c
    ctx->pc = 0x1b73f4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b73f8: 0x8e38007c
    ctx->pc = 0x1b73f8u;
    SET_GPR_U32(ctx, 24, READ32(ADD32(GPR_U32(ctx, 17), 124)));
    // 0x1b73fc: 0x6303c
    ctx->pc = 0x1b73fcu;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) << (32 + 0));
    // 0x1b7400: 0x2103e
    ctx->pc = 0x1b7400u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x1b7404: 0x6303e
    ctx->pc = 0x1b7404u;
    SET_GPR_U64(ctx, 6, GPR_U64(ctx, 6) >> (32 + 0));
    // 0x1b7408: 0x21438
    ctx->pc = 0x1b7408u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << 16);
    // 0x1b740c: 0x240e0006
    ctx->pc = 0x1b740cu;
    SET_GPR_S32(ctx, 14, ADD32(GPR_U32(ctx, 0), 6));
    // 0x1b7410: 0xc23025
    ctx->pc = 0x1b7410u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
    // 0x1b7414: 0x240d0060
    ctx->pc = 0x1b7414u;
    SET_GPR_S32(ctx, 13, ADD32(GPR_U32(ctx, 0), 96));
    // 0x1b7418: 0x3c022000
    ctx->pc = 0x1b7418u;
    SET_GPR_U32(ctx, 2, ((uint32_t)8192 << 16));
    // 0x1b741c: 0x2031825
    ctx->pc = 0x1b741cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x1b7420: 0x2783c
    ctx->pc = 0x1b7420u;
    SET_GPR_U64(ctx, 15, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b7424: 0x240c0014
    ctx->pc = 0x1b7424u;
    SET_GPR_S32(ctx, 12, ADD32(GPR_U32(ctx, 0), 20));
    // 0x1b7428: 0x338c021
    ctx->pc = 0x1b7428u;
    SET_GPR_U32(ctx, 24, ADD32(GPR_U32(ctx, 25), GPR_U32(ctx, 24)));
    // 0x1b742c: 0x3c026400
    ctx->pc = 0x1b742cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)25600 << 16));
    // 0x1b7430: 0x18803c
    ctx->pc = 0x1b7430u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 24) << (32 + 0));
    // 0x1b7434: 0x2403c
    ctx->pc = 0x1b7434u;
    SET_GPR_U64(ctx, 8, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1b7438: 0x10803e
    ctx->pc = 0x1b7438u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) >> (32 + 0));
    // 0x1b743c: 0x34028001
    ctx->pc = 0x1b743cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 0), 32769));
    // 0x1b7440: 0x485825
    ctx->pc = 0x1b7440u;
    SET_GPR_U32(ctx, 11, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1b7444: 0x10817c
    ctx->pc = 0x1b7444u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 5));
    // 0x1b7448: 0x701825
    ctx->pc = 0x1b7448u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1b744c: 0x3c020053
    ctx->pc = 0x1b744cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)83 << 16));
    // 0x1b7450: 0x6f1825
    ctx->pc = 0x1b7450u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 15)));
    // 0x1b7454: 0x344a5310
    ctx->pc = 0x1b7454u;
    SET_GPR_U32(ctx, 10, OR32(GPR_U32(ctx, 2), 21264));
    // 0x1b7458: 0xfca30030
    ctx->pc = 0x1b7458u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 48), GPR_U64(ctx, 3));
    // 0x1b745c: 0x24090156
    ctx->pc = 0x1b745cu;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 0), 342));
    // 0x1b7460: 0xfcae0038
    ctx->pc = 0x1b7460u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 56), GPR_U64(ctx, 14));
    // 0x1b7464: 0x3c080008
    ctx->pc = 0x1b7464u;
    SET_GPR_U32(ctx, 8, ((uint32_t)8 << 16));
    // 0x1b7468: 0xfcad0040
    ctx->pc = 0x1b7468u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 64), GPR_U64(ctx, 13));
    // 0x1b746c: 0x35080008
    ctx->pc = 0x1b746cu;
    SET_GPR_U32(ctx, 8, OR32(GPR_U32(ctx, 8), 8));
    // 0x1b7470: 0xfcac0048
    ctx->pc = 0x1b7470u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 72), GPR_U64(ctx, 12));
    // 0x1b7474: 0x24a20090
    ctx->pc = 0x1b7474u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 5), 144));
    // 0x1b7478: 0xfcab0050
    ctx->pc = 0x1b7478u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 80), GPR_U64(ctx, 11));
    // 0x1b747c: 0xfcaa0058
    ctx->pc = 0x1b747cu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 88), GPR_U64(ctx, 10));
    // 0x1b7480: 0xfca90060
    ctx->pc = 0x1b7480u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 96), GPR_U64(ctx, 9));
    // 0x1b7484: 0x9e230080
    ctx->pc = 0x1b7484u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 128)));
    // 0x1b7488: 0xfca30068
    ctx->pc = 0x1b7488u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 104), GPR_U64(ctx, 3));
    // 0x1b748c: 0xfca80070
    ctx->pc = 0x1b748cu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 112), GPR_U64(ctx, 8));
    // 0x1b7490: 0x9e230078
    ctx->pc = 0x1b7490u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 120)));
    // 0x1b7494: 0x3183c
    ctx->pc = 0x1b7494u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1b7498: 0x671825
    ctx->pc = 0x1b7498u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x1b749c: 0xfca30078
    ctx->pc = 0x1b749cu;
    WRITE64(ADD32(GPR_U32(ctx, 5), 120), GPR_U64(ctx, 3));
    // 0x1b74a0: 0xfca60080
    ctx->pc = 0x1b74a0u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 128), GPR_U64(ctx, 6));
    // 0x1b74a4: 0x9e230078
    ctx->pc = 0x1b74a4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 120)));
    // 0x1b74a8: 0x3183c
    ctx->pc = 0x1b74a8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x1b74ac: 0x641825
    ctx->pc = 0x1b74acu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x1b74b0: 0xfca30088
    ctx->pc = 0x1b74b0u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 136), GPR_U64(ctx, 3));
    // 0x1b74b4: 0xdfbf0030
    ctx->pc = 0x1b74b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1b74b8: 0x7bb10020
    ctx->pc = 0x1b74b8u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1b74bc: 0x7bb00010
    ctx->pc = 0x1b74bcu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1b74c0: 0x3e00008
    ctx->pc = 0x1B74C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1B74C4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1B7234u: goto label_1b7234;
            case 0x1B7258u: goto label_1b7258;
            case 0x1B72C0u: goto label_1b72c0;
            case 0x1B72DCu: goto label_1b72dc;
            case 0x1B7314u: goto label_1b7314;
            case 0x1B732Cu: goto label_1b732c;
            case 0x1B7344u: goto label_1b7344;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1B74C8u;
    // 0x1b74c8: 0x0
    ctx->pc = 0x1b74c8u;
    // NOP
    // 0x1b74cc: 0x0
    ctx->pc = 0x1b74ccu;
    // NOP
}
