#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: entry_127158
// Address: 0x127158 - 0x1273f0
void entry_127158_0x1273f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x127158u;

    // 0x127158: 0x27bdfff0
    ctx->pc = 0x127158u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12715c: 0xa5400
    ctx->pc = 0x12715cu;
    SET_GPR_U32(ctx, 10, SLL32(GPR_U32(ctx, 10), 16));
    // 0x127160: 0xb5c00
    ctx->pc = 0x127160u;
    SET_GPR_U32(ctx, 11, SLL32(GPR_U32(ctx, 11), 16));
    // 0x127164: 0xffb00000
    ctx->pc = 0x127164u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x127168: 0xffb10008
    ctx->pc = 0x127168u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12716c: 0xa5303
    ctx->pc = 0x12716cu;
    SET_GPR_S32(ctx, 10, SRA32(GPR_S32(ctx, 10), 12));
    // 0x127170: 0xb5b03
    ctx->pc = 0x127170u;
    SET_GPR_S32(ctx, 11, SRA32(GPR_S32(ctx, 11), 12));
    // 0x127174: 0xa0782d
    ctx->pc = 0x127174u;
    SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127178: 0xe0682d
    ctx->pc = 0x127178u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12717c: 0x120702d
    ctx->pc = 0x12717cu;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127180: 0x448a1000
    ctx->pc = 0x127180u;
    *(uint32_t*)&ctx->f[2] = GPR_U32(ctx, 10);
    // 0x127184: 0x468010a0
    ctx->pc = 0x127184u;
    ctx->f[2] = FPU_CVT_S_W(*(int32_t*)&ctx->f[2]);
    // 0x127188: 0x80502d
    ctx->pc = 0x127188u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12718c: 0x448b0800
    ctx->pc = 0x12718cu;
    *(uint32_t*)&ctx->f[1] = GPR_U32(ctx, 11);
    // 0x127190: 0x46800860
    ctx->pc = 0x127190u;
    ctx->f[1] = FPU_CVT_S_W(*(int32_t*)&ctx->f[1]);
    // 0x127194: 0x85a30000
    ctx->pc = 0x127194u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 13), 0)));
    // 0x127198: 0x85a70002
    ctx->pc = 0x127198u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 13), 2)));
    // 0x12719c: 0xf17c2
    ctx->pc = 0x12719cu;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 15), 31));
    // 0x1271a0: 0x85c90000
    ctx->pc = 0x1271a0u;
    SET_GPR_S32(ctx, 9, (int16_t)READ16(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x1271a4: 0x1e21021
    ctx->pc = 0x1271a4u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 15), GPR_U32(ctx, 2)));
    // 0x1271a8: 0x85c50002
    ctx->pc = 0x1271a8u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 14), 2)));
    // 0x1271ac: 0x31c00
    ctx->pc = 0x1271acu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 16));
    // 0x1271b0: 0x3c013780
    ctx->pc = 0x1271b0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)14208 << 16));
    // 0x1271b4: 0x44810000
    ctx->pc = 0x1271b4u;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 1);
    // 0x1271b8: 0x73c00
    ctx->pc = 0x1271b8u;
    SET_GPR_U32(ctx, 7, SLL32(GPR_U32(ctx, 7), 16));
    // 0x1271bc: 0x94c00
    ctx->pc = 0x1271bcu;
    SET_GPR_U32(ctx, 9, SLL32(GPR_U32(ctx, 9), 16));
    // 0x1271c0: 0x52c00
    ctx->pc = 0x1271c0u;
    SET_GPR_U32(ctx, 5, SLL32(GPR_U32(ctx, 5), 16));
    // 0x1271c4: 0x21043
    ctx->pc = 0x1271c4u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x1271c8: 0x46000b82
    ctx->pc = 0x1271c8u;
    ctx->f[14] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x1271cc: 0x44834000
    ctx->pc = 0x1271ccu;
    *(uint32_t*)&ctx->f[8] = GPR_U32(ctx, 3);
    // 0x1271d0: 0x46804220
    ctx->pc = 0x1271d0u;
    ctx->f[8] = FPU_CVT_S_W(*(int32_t*)&ctx->f[8]);
    // 0x1271d4: 0x602d
    ctx->pc = 0x1271d4u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1271d8: 0x44875800
    ctx->pc = 0x1271d8u;
    *(uint32_t*)&ctx->f[11] = GPR_U32(ctx, 7);
    // 0x1271dc: 0x46805ae0
    ctx->pc = 0x1271dcu;
    ctx->f[11] = FPU_CVT_S_W(*(int32_t*)&ctx->f[11]);
    // 0x1271e0: 0x44894800
    ctx->pc = 0x1271e0u;
    *(uint32_t*)&ctx->f[9] = GPR_U32(ctx, 9);
    // 0x1271e4: 0x46804a60
    ctx->pc = 0x1271e4u;
    ctx->f[9] = FPU_CVT_S_W(*(int32_t*)&ctx->f[9]);
    // 0x1271e8: 0x44855000
    ctx->pc = 0x1271e8u;
    *(uint32_t*)&ctx->f[10] = GPR_U32(ctx, 5);
    // 0x1271ec: 0x468052a0
    ctx->pc = 0x1271ecu;
    ctx->f[10] = FPU_CVT_S_W(*(int32_t*)&ctx->f[10]);
    // 0x1271f0: 0x18400069
    ctx->pc = 0x1271F0u;
    {
        const bool branch_taken_0x1271f0 = (GPR_S32(ctx, 2) <= 0);
        ctx->pc = 0x1271F4u;
        ctx->f[13] = FPU_MUL_S(ctx->f[2], ctx->f[0]);
        if (branch_taken_0x1271f0) {
            ctx->pc = 0x127398u;
            goto label_127398;
        }
    }
    ctx->pc = 0x1271F8u;
    // 0x1271f8: 0x40c82d
    ctx->pc = 0x1271f8u;
    SET_GPR_U64(ctx, 25, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1271fc: 0x2418ff00
    ctx->pc = 0x1271fcu;
    SET_GPR_S32(ctx, 24, ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x127200: 0x3c110024
    ctx->pc = 0x127200u;
    SET_GPR_U32(ctx, 17, ((uint32_t)36 << 16));
    // 0x127204: 0x3c100024
    ctx->pc = 0x127204u;
    SET_GPR_U32(ctx, 16, ((uint32_t)36 << 16));
    // 0x127208: 0x140282d
    ctx->pc = 0x127208u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12720c: 0x0
    ctx->pc = 0x12720cu;
    // NOP
label_127210:
    // 0x127210: 0x254a0012
    ctx->pc = 0x127210u;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 10), 18));
    // 0x127214: 0x94a30000
    ctx->pc = 0x127214u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x127218: 0x90a40001
    ctx->pc = 0x127218u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
    // 0x12721c: 0x31a00
    ctx->pc = 0x12721cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 8));
    // 0x127220: 0x781824
    ctx->pc = 0x127220u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 24)));
    // 0x127224: 0x832025
    ctx->pc = 0x127224u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x127228: 0x42400
    ctx->pc = 0x127228u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 16));
    // 0x12722c: 0x42403
    ctx->pc = 0x12722cu;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x127230: 0x30838000
    ctx->pc = 0x127230u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 4), 32768));
    // 0x127234: 0x14600069
    ctx->pc = 0x127234u;
    {
        const bool branch_taken_0x127234 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x127238u;
        SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 12), 1));
        if (branch_taken_0x127234) {
            ctx->pc = 0x1273DCu;
            goto label_1273dc;
        }
    }
    ctx->pc = 0x12723Cu;
    // 0x12723c: 0x95430000
    ctx->pc = 0x12723cu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x127240: 0x30821fff
    ctx->pc = 0x127240u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), 8191));
    // 0x127244: 0x91440001
    ctx->pc = 0x127244u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 1)));
    // 0x127248: 0x24420001
    ctx->pc = 0x127248u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x12724c: 0x31a00
    ctx->pc = 0x12724cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 8));
    // 0x127250: 0x44827800
    ctx->pc = 0x127250u;
    *(uint32_t*)&ctx->f[15] = GPR_U32(ctx, 2);
    // 0x127254: 0x46807be0
    ctx->pc = 0x127254u;
    ctx->f[15] = FPU_CVT_S_W(*(int32_t*)&ctx->f[15]);
    // 0x127258: 0x781824
    ctx->pc = 0x127258u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 24)));
    // 0x12725c: 0x832025
    ctx->pc = 0x12725cu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x127260: 0x42400
    ctx->pc = 0x127260u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 16));
    // 0x127264: 0x42403
    ctx->pc = 0x127264u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x127268: 0x30838000
    ctx->pc = 0x127268u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 4), 32768));
    // 0x12726c: 0x1460005b
    ctx->pc = 0x12726Cu;
    {
        const bool branch_taken_0x12726c = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x127270u;
        SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 12), 1));
        if (branch_taken_0x12726c) {
            ctx->pc = 0x1273DCu;
            goto label_1273dc;
        }
    }
    ctx->pc = 0x127274u;
    // 0x127274: 0x30821fff
    ctx->pc = 0x127274u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), 8191));
    // 0x127278: 0x24a50002
    ctx->pc = 0x127278u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 2));
    // 0x12727c: 0x24420001
    ctx->pc = 0x12727cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x127280: 0x254a0002
    ctx->pc = 0x127280u;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 10), 2));
    // 0x127284: 0x44826000
    ctx->pc = 0x127284u;
    *(uint32_t*)&ctx->f[12] = GPR_U32(ctx, 2);
    // 0x127288: 0x46806320
    ctx->pc = 0x127288u;
    ctx->f[12] = FPU_CVT_S_W(*(int32_t*)&ctx->f[12]);
    // 0x12728c: 0x262ba528
    ctx->pc = 0x12728cu;
    SET_GPR_S32(ctx, 11, ADD32(GPR_U32(ctx, 17), 4294944040));
    // 0x127290: 0x2609a928
    ctx->pc = 0x127290u;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 16), 4294945064));
    // 0x127294: 0x2407001e
    ctx->pc = 0x127294u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 30));
label_127298:
    // 0x127298: 0x90a40000
    ctx->pc = 0x127298u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x12729c: 0x24a50001
    ctx->pc = 0x12729cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 1));
    // 0x1272a0: 0x460b7082
    ctx->pc = 0x1272a0u;
    ctx->f[2] = FPU_MUL_S(ctx->f[14], ctx->f[11]);
    // 0x1272a4: 0x460042c6
    ctx->pc = 0x1272a4u;
    ctx->f[11] = FPU_MOV_S(ctx->f[8]);
    // 0x1272a8: 0x42080
    ctx->pc = 0x1272a8u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 2));
    // 0x1272ac: 0x46086802
    ctx->pc = 0x1272acu;
    ctx->f[0] = FPU_MUL_S(ctx->f[13], ctx->f[8]);
    // 0x1272b0: 0x8b1021
    ctx->pc = 0x1272b0u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
    // 0x1272b4: 0x892021
    ctx->pc = 0x1272b4u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 9)));
    // 0x1272b8: 0x91430000
    ctx->pc = 0x1272b8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x1272bc: 0x254a0001
    ctx->pc = 0x1272bcu;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 10), 1));
    // 0x1272c0: 0xc4440000
    ctx->pc = 0x1272c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x1272c4: 0x460a70c2
    ctx->pc = 0x1272c4u;
    ctx->f[3] = FPU_MUL_S(ctx->f[14], ctx->f[10]);
    // 0x1272c8: 0x46020000
    ctx->pc = 0x1272c8u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[2]);
    // 0x1272cc: 0x31880
    ctx->pc = 0x1272ccu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 2));
    // 0x1272d0: 0x460f2082
    ctx->pc = 0x1272d0u;
    ctx->f[2] = FPU_MUL_S(ctx->f[4], ctx->f[15]);
    // 0x1272d4: 0xc4840000
    ctx->pc = 0x1272d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x1272d8: 0x46096842
    ctx->pc = 0x1272d8u;
    ctx->f[1] = FPU_MUL_S(ctx->f[13], ctx->f[9]);
    // 0x1272dc: 0x6b1021
    ctx->pc = 0x1272dcu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 11)));
    // 0x1272e0: 0xc4470000
    ctx->pc = 0x1272e0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[7] = f; }
    // 0x1272e4: 0x46004a86
    ctx->pc = 0x1272e4u;
    ctx->f[10] = FPU_MOV_S(ctx->f[9]);
    // 0x1272e8: 0x460b7182
    ctx->pc = 0x1272e8u;
    ctx->f[6] = FPU_MUL_S(ctx->f[14], ctx->f[11]);
    // 0x1272ec: 0x691821
    ctx->pc = 0x1272ecu;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x1272f0: 0x46020200
    ctx->pc = 0x1272f0u;
    ctx->f[8] = FPU_ADD_S(ctx->f[0], ctx->f[2]);
    // 0x1272f4: 0x24e7fffe
    ctx->pc = 0x1272f4u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 4294967294));
    // 0x1272f8: 0x46030840
    ctx->pc = 0x1272f8u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[3]);
    // 0x1272fc: 0x460c38c2
    ctx->pc = 0x1272fcu;
    ctx->f[3] = FPU_MUL_S(ctx->f[7], ctx->f[12]);
    // 0x127300: 0xc4670000
    ctx->pc = 0x127300u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[7] = f; }
    // 0x127304: 0x460a7142
    ctx->pc = 0x127304u;
    ctx->f[5] = FPU_MUL_S(ctx->f[14], ctx->f[10]);
    // 0x127308: 0x46086802
    ctx->pc = 0x127308u;
    ctx->f[0] = FPU_MUL_S(ctx->f[13], ctx->f[8]);
    // 0x12730c: 0x460042c6
    ctx->pc = 0x12730cu;
    ctx->f[11] = FPU_MOV_S(ctx->f[8]);
    // 0x127310: 0x460f2102
    ctx->pc = 0x127310u;
    ctx->f[4] = FPU_MUL_S(ctx->f[4], ctx->f[15]);
    // 0x127314: 0x46030a40
    ctx->pc = 0x127314u;
    ctx->f[9] = FPU_ADD_S(ctx->f[1], ctx->f[3]);
    // 0x127318: 0x46004064
    ctx->pc = 0x127318u;
    *(int32_t*)&ctx->f[1] = FPU_CVT_W_S(ctx->f[8]);
    // 0x12731c: 0x44030800
    ctx->pc = 0x12731cu;
    SET_GPR_U32(ctx, 3, *(uint32_t*)&ctx->f[1]);
    // 0x127320: 0x46060000
    ctx->pc = 0x127320u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[6]);
    // 0x127324: 0x460c3882
    ctx->pc = 0x127324u;
    ctx->f[2] = FPU_MUL_S(ctx->f[7], ctx->f[12]);
    // 0x127328: 0x46096842
    ctx->pc = 0x127328u;
    ctx->f[1] = FPU_MUL_S(ctx->f[13], ctx->f[9]);
    // 0x12732c: 0x46004a86
    ctx->pc = 0x12732cu;
    ctx->f[10] = FPU_MOV_S(ctx->f[9]);
    // 0x127330: 0x31403
    ctx->pc = 0x127330u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 16));
    // 0x127334: 0x460048e4
    ctx->pc = 0x127334u;
    *(int32_t*)&ctx->f[3] = FPU_CVT_W_S(ctx->f[9]);
    // 0x127338: 0x44031800
    ctx->pc = 0x127338u;
    SET_GPR_U32(ctx, 3, *(uint32_t*)&ctx->f[3]);
    // 0x12733c: 0x46040200
    ctx->pc = 0x12733cu;
    ctx->f[8] = FPU_ADD_S(ctx->f[0], ctx->f[4]);
    // 0x127340: 0xa4c20000
    ctx->pc = 0x127340u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127344: 0x24c60002
    ctx->pc = 0x127344u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 2));
    // 0x127348: 0x46050840
    ctx->pc = 0x127348u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[5]);
    // 0x12734c: 0x31403
    ctx->pc = 0x12734cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 16));
    // 0x127350: 0xa5020000
    ctx->pc = 0x127350u;
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127354: 0x25080002
    ctx->pc = 0x127354u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 2));
    // 0x127358: 0x46004024
    ctx->pc = 0x127358u;
    *(int32_t*)&ctx->f[0] = FPU_CVT_W_S(ctx->f[8]);
    // 0x12735c: 0x44030000
    ctx->pc = 0x12735cu;
    SET_GPR_U32(ctx, 3, *(uint32_t*)&ctx->f[0]);
    // 0x127360: 0x46020a40
    ctx->pc = 0x127360u;
    ctx->f[9] = FPU_ADD_S(ctx->f[1], ctx->f[2]);
    // 0x127364: 0x31403
    ctx->pc = 0x127364u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 16));
    // 0x127368: 0x46004824
    ctx->pc = 0x127368u;
    *(int32_t*)&ctx->f[0] = FPU_CVT_W_S(ctx->f[9]);
    // 0x12736c: 0x44030000
    ctx->pc = 0x12736cu;
    SET_GPR_U32(ctx, 3, *(uint32_t*)&ctx->f[0]);
    // 0x127370: 0xa4c20000
    ctx->pc = 0x127370u;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127374: 0x24c60002
    ctx->pc = 0x127374u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 2));
    // 0x127378: 0x31403
    ctx->pc = 0x127378u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 16));
    // 0x12737c: 0xa5020000
    ctx->pc = 0x12737cu;
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127380: 0x4e1ffc5
    ctx->pc = 0x127380u;
    {
        const bool branch_taken_0x127380 = (GPR_S32(ctx, 7) >= 0);
        ctx->pc = 0x127384u;
        SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 2));
        if (branch_taken_0x127380) {
            ctx->pc = 0x127298u;
            goto label_127298;
        }
    }
    ctx->pc = 0x127388u;
    // 0x127388: 0x258c0001
    ctx->pc = 0x127388u;
    SET_GPR_S32(ctx, 12, ADD32(GPR_U32(ctx, 12), 1));
    // 0x12738c: 0x199102a
    ctx->pc = 0x12738cu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 12), GPR_S32(ctx, 25)));
    // 0x127390: 0x1440ff9f
    ctx->pc = 0x127390u;
    {
        const bool branch_taken_0x127390 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x127394u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x127390) {
            ctx->pc = 0x127210u;
            goto label_127210;
        }
    }
    ctx->pc = 0x127398u;
label_127398:
    // 0x127398: 0x46004024
    ctx->pc = 0x127398u;
    *(int32_t*)&ctx->f[0] = FPU_CVT_W_S(ctx->f[8]);
    // 0x12739c: 0x44030000
    ctx->pc = 0x12739cu;
    SET_GPR_U32(ctx, 3, *(uint32_t*)&ctx->f[0]);
    // 0x1273a0: 0x1e0102d
    ctx->pc = 0x1273a0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 15) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1273a4: 0x46005824
    ctx->pc = 0x1273a4u;
    *(int32_t*)&ctx->f[0] = FPU_CVT_W_S(ctx->f[11]);
    // 0x1273a8: 0x44040000
    ctx->pc = 0x1273a8u;
    SET_GPR_U32(ctx, 4, *(uint32_t*)&ctx->f[0]);
    // 0x1273ac: 0x46004824
    ctx->pc = 0x1273acu;
    *(int32_t*)&ctx->f[0] = FPU_CVT_W_S(ctx->f[9]);
    // 0x1273b0: 0x44050000
    ctx->pc = 0x1273b0u;
    SET_GPR_U32(ctx, 5, *(uint32_t*)&ctx->f[0]);
    // 0x1273b4: 0x46005024
    ctx->pc = 0x1273b4u;
    *(int32_t*)&ctx->f[0] = FPU_CVT_W_S(ctx->f[10]);
    // 0x1273b8: 0x44060000
    ctx->pc = 0x1273b8u;
    SET_GPR_U32(ctx, 6, *(uint32_t*)&ctx->f[0]);
    // 0x1273bc: 0x31c03
    ctx->pc = 0x1273bcu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 16));
    // 0x1273c0: 0x42403
    ctx->pc = 0x1273c0u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x1273c4: 0xa5a30000
    ctx->pc = 0x1273c4u;
    WRITE16(ADD32(GPR_U32(ctx, 13), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1273c8: 0x52c03
    ctx->pc = 0x1273c8u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 16));
    // 0x1273cc: 0xa5a40002
    ctx->pc = 0x1273ccu;
    WRITE16(ADD32(GPR_U32(ctx, 13), 2), (uint16_t)GPR_U32(ctx, 4));
    // 0x1273d0: 0x63403
    ctx->pc = 0x1273d0u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 16));
    // 0x1273d4: 0xa5c50000
    ctx->pc = 0x1273d4u;
    WRITE16(ADD32(GPR_U32(ctx, 14), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x1273d8: 0xa5c60002
    ctx->pc = 0x1273d8u;
    WRITE16(ADD32(GPR_U32(ctx, 14), 2), (uint16_t)GPR_U32(ctx, 6));
label_1273dc:
    // 0x1273dc: 0xdfb00000
    ctx->pc = 0x1273dcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1273e0: 0xdfb10008
    ctx->pc = 0x1273e0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1273e4: 0x3e00008
    ctx->pc = 0x1273E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1273E8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x127210u: goto label_127210;
            case 0x127298u: goto label_127298;
            case 0x127398u: goto label_127398;
            case 0x1273DCu: goto label_1273dc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1273ECu;
    // 0x1273ec: 0x0
    ctx->pc = 0x1273ecu;
    // NOP
}
