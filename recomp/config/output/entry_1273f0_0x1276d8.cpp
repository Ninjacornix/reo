#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: entry_1273f0
// Address: 0x1273f0 - 0x1276d8
void entry_1273f0_0x1276d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1273f0u;

label_1273f0:
    // 0x1273f0: 0x27bdffe0
    ctx->pc = 0x1273f0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1273f4: 0xa5400
    ctx->pc = 0x1273f4u;
    SET_GPR_U32(ctx, 10, SLL32(GPR_U32(ctx, 10), 16));
    // 0x1273f8: 0xb5c00
    ctx->pc = 0x1273f8u;
    SET_GPR_U32(ctx, 11, SLL32(GPR_U32(ctx, 11), 16));
    // 0x1273fc: 0xffb00000
    ctx->pc = 0x1273fcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x127400: 0xffb10008
    ctx->pc = 0x127400u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x127404: 0xa5303
    ctx->pc = 0x127404u;
    SET_GPR_S32(ctx, 10, SRA32(GPR_S32(ctx, 10), 12));
    // 0x127408: 0xffb20010
    ctx->pc = 0x127408u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x12740c: 0xb5b03
    ctx->pc = 0x12740cu;
    SET_GPR_S32(ctx, 11, SRA32(GPR_S32(ctx, 11), 12));
    // 0x127410: 0xa0c02d
    ctx->pc = 0x127410u;
    SET_GPR_U64(ctx, 24, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127414: 0xe0702d
    ctx->pc = 0x127414u;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127418: 0x120782d
    ctx->pc = 0x127418u;
    SET_GPR_U64(ctx, 15, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12741c: 0x448a1000
    ctx->pc = 0x12741cu;
    *(uint32_t*)&ctx->f[2] = GPR_U32(ctx, 10);
    // 0x127420: 0x468010a0
    ctx->pc = 0x127420u;
    ctx->f[2] = FPU_CVT_S_W(*(int32_t*)&ctx->f[2]);
    // 0x127424: 0x448b0800
    ctx->pc = 0x127424u;
    *(uint32_t*)&ctx->f[1] = GPR_U32(ctx, 11);
    // 0x127428: 0x46800860
    ctx->pc = 0x127428u;
    ctx->f[1] = FPU_CVT_S_W(*(int32_t*)&ctx->f[1]);
    // 0x12742c: 0x85c30000
    ctx->pc = 0x12742cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 14), 0)));
    // 0x127430: 0x85c70002
    ctx->pc = 0x127430u;
    SET_GPR_S32(ctx, 7, (int16_t)READ16(ADD32(GPR_U32(ctx, 14), 2)));
    // 0x127434: 0x1817c2
    ctx->pc = 0x127434u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 24), 31));
    // 0x127438: 0x85e90000
    ctx->pc = 0x127438u;
    SET_GPR_S32(ctx, 9, (int16_t)READ16(ADD32(GPR_U32(ctx, 15), 0)));
    // 0x12743c: 0x3021021
    ctx->pc = 0x12743cu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 24), GPR_U32(ctx, 2)));
    // 0x127440: 0x85e50002
    ctx->pc = 0x127440u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 15), 2)));
    // 0x127444: 0x31c00
    ctx->pc = 0x127444u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 16));
    // 0x127448: 0x3c013780
    ctx->pc = 0x127448u;
    SET_GPR_U32(ctx, 1, ((uint32_t)14208 << 16));
    // 0x12744c: 0x44810000
    ctx->pc = 0x12744cu;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 1);
    // 0x127450: 0x73c00
    ctx->pc = 0x127450u;
    SET_GPR_U32(ctx, 7, SLL32(GPR_U32(ctx, 7), 16));
    // 0x127454: 0x94c00
    ctx->pc = 0x127454u;
    SET_GPR_U32(ctx, 9, SLL32(GPR_U32(ctx, 9), 16));
    // 0x127458: 0x52c00
    ctx->pc = 0x127458u;
    SET_GPR_U32(ctx, 5, SLL32(GPR_U32(ctx, 5), 16));
    // 0x12745c: 0x21043
    ctx->pc = 0x12745cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x127460: 0x46000b82
    ctx->pc = 0x127460u;
    ctx->f[14] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x127464: 0x44834800
    ctx->pc = 0x127464u;
    *(uint32_t*)&ctx->f[9] = GPR_U32(ctx, 3);
    // 0x127468: 0x46804a60
    ctx->pc = 0x127468u;
    ctx->f[9] = FPU_CVT_S_W(*(int32_t*)&ctx->f[9]);
    // 0x12746c: 0x80502d
    ctx->pc = 0x12746cu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127470: 0x44875800
    ctx->pc = 0x127470u;
    *(uint32_t*)&ctx->f[11] = GPR_U32(ctx, 7);
    // 0x127474: 0x46805ae0
    ctx->pc = 0x127474u;
    ctx->f[11] = FPU_CVT_S_W(*(int32_t*)&ctx->f[11]);
    // 0x127478: 0x682d
    ctx->pc = 0x127478u;
    SET_GPR_U64(ctx, 13, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12747c: 0x44894000
    ctx->pc = 0x12747cu;
    *(uint32_t*)&ctx->f[8] = GPR_U32(ctx, 9);
    // 0x127480: 0x46804220
    ctx->pc = 0x127480u;
    ctx->f[8] = FPU_CVT_S_W(*(int32_t*)&ctx->f[8]);
    // 0x127484: 0x44855000
    ctx->pc = 0x127484u;
    *(uint32_t*)&ctx->f[10] = GPR_U32(ctx, 5);
    // 0x127488: 0x468052a0
    ctx->pc = 0x127488u;
    ctx->f[10] = FPU_CVT_S_W(*(int32_t*)&ctx->f[10]);
    // 0x12748c: 0x1840006a
    ctx->pc = 0x12748Cu;
    {
        const bool branch_taken_0x12748c = (GPR_S32(ctx, 2) <= 0);
        ctx->pc = 0x127490u;
        ctx->f[12] = FPU_MUL_S(ctx->f[2], ctx->f[0]);
        if (branch_taken_0x12748c) {
            ctx->pc = 0x127638u;
            goto label_127638;
        }
    }
    ctx->pc = 0x127494u;
    // 0x127494: 0x40802d
    ctx->pc = 0x127494u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127498: 0x2419ff00
    ctx->pc = 0x127498u;
    SET_GPR_S32(ctx, 25, ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x12749c: 0x3c120024
    ctx->pc = 0x12749cu;
    SET_GPR_U32(ctx, 18, ((uint32_t)36 << 16));
    // 0x1274a0: 0x3c110024
    ctx->pc = 0x1274a0u;
    SET_GPR_U32(ctx, 17, ((uint32_t)36 << 16));
    // 0x1274a4: 0x140382d
    ctx->pc = 0x1274a4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
label_1274a8:
    // 0x1274a8: 0x254a0012
    ctx->pc = 0x1274a8u;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 10), 18));
    // 0x1274ac: 0x94e30000
    ctx->pc = 0x1274acu;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1274b0: 0x90e40001
    ctx->pc = 0x1274b0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 1)));
    // 0x1274b4: 0x31a00
    ctx->pc = 0x1274b4u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 8));
    // 0x1274b8: 0x791824
    ctx->pc = 0x1274b8u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 25)));
    // 0x1274bc: 0x832025
    ctx->pc = 0x1274bcu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1274c0: 0x42400
    ctx->pc = 0x1274c0u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 16));
    // 0x1274c4: 0x42403
    ctx->pc = 0x1274c4u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x1274c8: 0x30838000
    ctx->pc = 0x1274c8u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 4), 32768));
    // 0x1274cc: 0x1460006b
    ctx->pc = 0x1274CCu;
    {
        const bool branch_taken_0x1274cc = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x1274D0u;
        SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 13), 1));
        if (branch_taken_0x1274cc) {
            ctx->pc = 0x12767Cu;
            goto label_12767c;
        }
    }
    ctx->pc = 0x1274D4u;
    // 0x1274d4: 0x95430000
    ctx->pc = 0x1274d4u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x1274d8: 0x30821fff
    ctx->pc = 0x1274d8u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), 8191));
    // 0x1274dc: 0x91440001
    ctx->pc = 0x1274dcu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 1)));
    // 0x1274e0: 0x24420001
    ctx->pc = 0x1274e0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x1274e4: 0x31a00
    ctx->pc = 0x1274e4u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 8));
    // 0x1274e8: 0x44827800
    ctx->pc = 0x1274e8u;
    *(uint32_t*)&ctx->f[15] = GPR_U32(ctx, 2);
    // 0x1274ec: 0x46807be0
    ctx->pc = 0x1274ecu;
    ctx->f[15] = FPU_CVT_S_W(*(int32_t*)&ctx->f[15]);
    // 0x1274f0: 0x791824
    ctx->pc = 0x1274f0u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 25)));
    // 0x1274f4: 0x832025
    ctx->pc = 0x1274f4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x1274f8: 0x42400
    ctx->pc = 0x1274f8u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 16));
    // 0x1274fc: 0x42403
    ctx->pc = 0x1274fcu;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x127500: 0x30838000
    ctx->pc = 0x127500u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 4), 32768));
    // 0x127504: 0x1460005d
    ctx->pc = 0x127504u;
    {
        const bool branch_taken_0x127504 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x127508u;
        SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 13), 1));
        if (branch_taken_0x127504) {
            ctx->pc = 0x12767Cu;
            goto label_12767c;
        }
    }
    ctx->pc = 0x12750Cu;
    // 0x12750c: 0x30821fff
    ctx->pc = 0x12750cu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), 8191));
    // 0x127510: 0x3c013f33
    ctx->pc = 0x127510u;
    SET_GPR_U32(ctx, 1, ((uint32_t)16179 << 16));
    // 0x127514: 0x34213333
    ctx->pc = 0x127514u;
    SET_GPR_U32(ctx, 1, OR32(GPR_U32(ctx, 1), 13107));
    // 0x127518: 0x44818000
    ctx->pc = 0x127518u;
    *(uint32_t*)&ctx->f[16] = GPR_U32(ctx, 1);
    // 0x12751c: 0x24420001
    ctx->pc = 0x12751cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x127520: 0x24e70002
    ctx->pc = 0x127520u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 2));
    // 0x127524: 0x44826800
    ctx->pc = 0x127524u;
    *(uint32_t*)&ctx->f[13] = GPR_U32(ctx, 2);
    // 0x127528: 0x46806b60
    ctx->pc = 0x127528u;
    ctx->f[13] = FPU_CVT_S_W(*(int32_t*)&ctx->f[13]);
    // 0x12752c: 0x254a0002
    ctx->pc = 0x12752cu;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 10), 2));
    // 0x127530: 0x264ca528
    ctx->pc = 0x127530u;
    SET_GPR_S32(ctx, 12, ADD32(GPR_U32(ctx, 18), 4294944040));
    // 0x127534: 0x262ba928
    ctx->pc = 0x127534u;
    SET_GPR_S32(ctx, 11, ADD32(GPR_U32(ctx, 17), 4294945064));
    // 0x127538: 0x2409001e
    ctx->pc = 0x127538u;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 0), 30));
    // 0x12753c: 0x0
    ctx->pc = 0x12753cu;
    // NOP
label_127540:
    // 0x127540: 0x90e20000
    ctx->pc = 0x127540u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x127544: 0x24e70001
    ctx->pc = 0x127544u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 1));
    // 0x127548: 0x91430000
    ctx->pc = 0x127548u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 10), 0)));
    // 0x12754c: 0x254a0001
    ctx->pc = 0x12754cu;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 10), 1));
    // 0x127550: 0x460b7042
    ctx->pc = 0x127550u;
    ctx->f[1] = FPU_MUL_S(ctx->f[14], ctx->f[11]);
    // 0x127554: 0x46004ac6
    ctx->pc = 0x127554u;
    ctx->f[11] = FPU_MOV_S(ctx->f[9]);
    // 0x127558: 0x460a70c2
    ctx->pc = 0x127558u;
    ctx->f[3] = FPU_MUL_S(ctx->f[14], ctx->f[10]);
    // 0x12755c: 0x46004286
    ctx->pc = 0x12755cu;
    ctx->f[10] = FPU_MOV_S(ctx->f[8]);
    // 0x127560: 0x21080
    ctx->pc = 0x127560u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 2));
    // 0x127564: 0x31880
    ctx->pc = 0x127564u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 2));
    // 0x127568: 0x46096082
    ctx->pc = 0x127568u;
    ctx->f[2] = FPU_MUL_S(ctx->f[12], ctx->f[9]);
    // 0x12756c: 0x4c2021
    ctx->pc = 0x12756cu;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 12)));
    // 0x127570: 0x46086002
    ctx->pc = 0x127570u;
    ctx->f[0] = FPU_MUL_S(ctx->f[12], ctx->f[8]);
    // 0x127574: 0x6c2821
    ctx->pc = 0x127574u;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 12)));
    // 0x127578: 0xc4870000
    ctx->pc = 0x127578u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 4), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[7] = f; }
    // 0x12757c: 0x460b7182
    ctx->pc = 0x12757cu;
    ctx->f[6] = FPU_MUL_S(ctx->f[14], ctx->f[11]);
    // 0x127580: 0xc4a40000
    ctx->pc = 0x127580u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 5), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x127584: 0x460a7142
    ctx->pc = 0x127584u;
    ctx->f[5] = FPU_MUL_S(ctx->f[14], ctx->f[10]);
    // 0x127588: 0x46011080
    ctx->pc = 0x127588u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[1]);
    // 0x12758c: 0x6b1821
    ctx->pc = 0x12758cu;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 11)));
    // 0x127590: 0x46030000
    ctx->pc = 0x127590u;
    ctx->f[0] = FPU_ADD_S(ctx->f[0], ctx->f[3]);
    // 0x127594: 0x4b1021
    ctx->pc = 0x127594u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 11)));
    // 0x127598: 0x460f38c2
    ctx->pc = 0x127598u;
    ctx->f[3] = FPU_MUL_S(ctx->f[7], ctx->f[15]);
    // 0x12759c: 0xc4470000
    ctx->pc = 0x12759cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[7] = f; }
    // 0x1275a0: 0x460d2042
    ctx->pc = 0x1275a0u;
    ctx->f[1] = FPU_MUL_S(ctx->f[4], ctx->f[13]);
    // 0x1275a4: 0xc4640000
    ctx->pc = 0x1275a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 0)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x1275a8: 0x2529fffe
    ctx->pc = 0x1275a8u;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 9), 4294967294));
    // 0x1275ac: 0x460d2102
    ctx->pc = 0x1275acu;
    ctx->f[4] = FPU_MUL_S(ctx->f[4], ctx->f[13]);
    // 0x1275b0: 0x46031240
    ctx->pc = 0x1275b0u;
    ctx->f[9] = FPU_ADD_S(ctx->f[2], ctx->f[3]);
    // 0x1275b4: 0x46010200
    ctx->pc = 0x1275b4u;
    ctx->f[8] = FPU_ADD_S(ctx->f[0], ctx->f[1]);
    // 0x1275b8: 0x460f38c2
    ctx->pc = 0x1275b8u;
    ctx->f[3] = FPU_MUL_S(ctx->f[7], ctx->f[15]);
    // 0x1275bc: 0x46096082
    ctx->pc = 0x1275bcu;
    ctx->f[2] = FPU_MUL_S(ctx->f[12], ctx->f[9]);
    // 0x1275c0: 0x46004ac6
    ctx->pc = 0x1275c0u;
    ctx->f[11] = FPU_MOV_S(ctx->f[9]);
    // 0x1275c4: 0x46086042
    ctx->pc = 0x1275c4u;
    ctx->f[1] = FPU_MUL_S(ctx->f[12], ctx->f[8]);
    // 0x1275c8: 0x46004286
    ctx->pc = 0x1275c8u;
    ctx->f[10] = FPU_MOV_S(ctx->f[8]);
    // 0x1275cc: 0x46084800
    ctx->pc = 0x1275ccu;
    ctx->f[0] = FPU_ADD_S(ctx->f[9], ctx->f[8]);
    // 0x1275d0: 0x46061080
    ctx->pc = 0x1275d0u;
    ctx->f[2] = FPU_ADD_S(ctx->f[2], ctx->f[6]);
    // 0x1275d4: 0x46050840
    ctx->pc = 0x1275d4u;
    ctx->f[1] = FPU_ADD_S(ctx->f[1], ctx->f[5]);
    // 0x1275d8: 0x46100002
    ctx->pc = 0x1275d8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[0], ctx->f[16]);
    // 0x1275dc: 0x46031240
    ctx->pc = 0x1275dcu;
    ctx->f[9] = FPU_ADD_S(ctx->f[2], ctx->f[3]);
    // 0x1275e0: 0x46040a00
    ctx->pc = 0x1275e0u;
    ctx->f[8] = FPU_ADD_S(ctx->f[1], ctx->f[4]);
    // 0x1275e4: 0x46000064
    ctx->pc = 0x1275e4u;
    *(int32_t*)&ctx->f[1] = FPU_CVT_W_S(ctx->f[0]);
    // 0x1275e8: 0x44020800
    ctx->pc = 0x1275e8u;
    SET_GPR_U32(ctx, 2, *(uint32_t*)&ctx->f[1]);
    // 0x1275ec: 0x46084840
    ctx->pc = 0x1275ecu;
    ctx->f[1] = FPU_ADD_S(ctx->f[9], ctx->f[8]);
    // 0x1275f0: 0x21403
    ctx->pc = 0x1275f0u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x1275f4: 0xa5020000
    ctx->pc = 0x1275f4u;
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1275f8: 0x25080002
    ctx->pc = 0x1275f8u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 2));
    // 0x1275fc: 0xa4c20000
    ctx->pc = 0x1275fcu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127600: 0x24c60002
    ctx->pc = 0x127600u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 2));
    // 0x127604: 0x46100842
    ctx->pc = 0x127604u;
    ctx->f[1] = FPU_MUL_S(ctx->f[1], ctx->f[16]);
    // 0x127608: 0x46000824
    ctx->pc = 0x127608u;
    *(int32_t*)&ctx->f[0] = FPU_CVT_W_S(ctx->f[1]);
    // 0x12760c: 0x44020000
    ctx->pc = 0x12760cu;
    SET_GPR_U32(ctx, 2, *(uint32_t*)&ctx->f[0]);
    // 0x127610: 0x21403
    ctx->pc = 0x127610u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 16));
    // 0x127614: 0xa5020000
    ctx->pc = 0x127614u;
    WRITE16(ADD32(GPR_U32(ctx, 8), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127618: 0x25080002
    ctx->pc = 0x127618u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 2));
    // 0x12761c: 0xa4c20000
    ctx->pc = 0x12761cu;
    WRITE16(ADD32(GPR_U32(ctx, 6), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x127620: 0x521ffc7
    ctx->pc = 0x127620u;
    {
        const bool branch_taken_0x127620 = (GPR_S32(ctx, 9) >= 0);
        ctx->pc = 0x127624u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 2));
        if (branch_taken_0x127620) {
            ctx->pc = 0x127540u;
            goto label_127540;
        }
    }
    ctx->pc = 0x127628u;
    // 0x127628: 0x25ad0001
    ctx->pc = 0x127628u;
    SET_GPR_S32(ctx, 13, ADD32(GPR_U32(ctx, 13), 1));
    // 0x12762c: 0x1b0102a
    ctx->pc = 0x12762cu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 13), GPR_S32(ctx, 16)));
    // 0x127630: 0x1440ff9d
    ctx->pc = 0x127630u;
    {
        const bool branch_taken_0x127630 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x127634u;
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x127630) {
            ctx->pc = 0x1274A8u;
            goto label_1274a8;
        }
    }
    ctx->pc = 0x127638u;
label_127638:
    // 0x127638: 0x46004824
    ctx->pc = 0x127638u;
    *(int32_t*)&ctx->f[0] = FPU_CVT_W_S(ctx->f[9]);
    // 0x12763c: 0x44030000
    ctx->pc = 0x12763cu;
    SET_GPR_U32(ctx, 3, *(uint32_t*)&ctx->f[0]);
    // 0x127640: 0x300102d
    ctx->pc = 0x127640u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 24) + (uint64_t)GPR_U64(ctx, 0));
    // 0x127644: 0x46005824
    ctx->pc = 0x127644u;
    *(int32_t*)&ctx->f[0] = FPU_CVT_W_S(ctx->f[11]);
    // 0x127648: 0x44040000
    ctx->pc = 0x127648u;
    SET_GPR_U32(ctx, 4, *(uint32_t*)&ctx->f[0]);
    // 0x12764c: 0x46004024
    ctx->pc = 0x12764cu;
    *(int32_t*)&ctx->f[0] = FPU_CVT_W_S(ctx->f[8]);
    // 0x127650: 0x44050000
    ctx->pc = 0x127650u;
    SET_GPR_U32(ctx, 5, *(uint32_t*)&ctx->f[0]);
    // 0x127654: 0x46005024
    ctx->pc = 0x127654u;
    *(int32_t*)&ctx->f[0] = FPU_CVT_W_S(ctx->f[10]);
    // 0x127658: 0x44060000
    ctx->pc = 0x127658u;
    SET_GPR_U32(ctx, 6, *(uint32_t*)&ctx->f[0]);
    // 0x12765c: 0x31c03
    ctx->pc = 0x12765cu;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 16));
    // 0x127660: 0x42403
    ctx->pc = 0x127660u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x127664: 0xa5c30000
    ctx->pc = 0x127664u;
    WRITE16(ADD32(GPR_U32(ctx, 14), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x127668: 0x52c03
    ctx->pc = 0x127668u;
    SET_GPR_S32(ctx, 5, SRA32(GPR_S32(ctx, 5), 16));
    // 0x12766c: 0xa5c40002
    ctx->pc = 0x12766cu;
    WRITE16(ADD32(GPR_U32(ctx, 14), 2), (uint16_t)GPR_U32(ctx, 4));
    // 0x127670: 0x63403
    ctx->pc = 0x127670u;
    SET_GPR_S32(ctx, 6, SRA32(GPR_S32(ctx, 6), 16));
    // 0x127674: 0xa5e50000
    ctx->pc = 0x127674u;
    WRITE16(ADD32(GPR_U32(ctx, 15), 0), (uint16_t)GPR_U32(ctx, 5));
    // 0x127678: 0xa5e60002
    ctx->pc = 0x127678u;
    WRITE16(ADD32(GPR_U32(ctx, 15), 2), (uint16_t)GPR_U32(ctx, 6));
label_12767c:
    // 0x12767c: 0xdfb00000
    ctx->pc = 0x12767cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x127680: 0xdfb10008
    ctx->pc = 0x127680u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x127684: 0xdfb20010
    ctx->pc = 0x127684u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x127688: 0x3e00008
    ctx->pc = 0x127688u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12768Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1273F0u: goto label_1273f0;
            case 0x1274A8u: goto label_1274a8;
            case 0x127540u: goto label_127540;
            case 0x127638u: goto label_127638;
            case 0x12767Cu: goto label_12767c;
            case 0x1276C8u: goto label_1276c8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x127690u;
    // 0x127690: 0x3c020021
    ctx->pc = 0x127690u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x127694: 0xa5400
    ctx->pc = 0x127694u;
    SET_GPR_U32(ctx, 10, SLL32(GPR_U32(ctx, 10), 16));
    // 0x127698: 0xb5c00
    ctx->pc = 0x127698u;
    SET_GPR_U32(ctx, 11, SLL32(GPR_U32(ctx, 11), 16));
    // 0x12769c: 0x8c43c7a8
    ctx->pc = 0x12769cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 4294952872)));
    // 0x1276a0: 0x27bdfff0
    ctx->pc = 0x1276a0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1276a4: 0xb6403
    ctx->pc = 0x1276a4u;
    SET_GPR_S32(ctx, 12, SRA32(GPR_S32(ctx, 11), 16));
    // 0x1276a8: 0xa1403
    ctx->pc = 0x1276a8u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 10), 16));
    // 0x1276ac: 0xffbf0000
    ctx->pc = 0x1276acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1276b0: 0x40502d
    ctx->pc = 0x1276b0u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1276b4: 0x14600004
    ctx->pc = 0x1276B4u;
    {
        const bool branch_taken_0x1276b4 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x1276B8u;
        SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1276b4) {
            ctx->pc = 0x1276C8u;
            goto label_1276c8;
        }
    }
    ctx->pc = 0x1276BCu;
    // 0x1276bc: 0xdfbf0000
    ctx->pc = 0x1276bcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1276c0: 0x8049c56
    ctx->pc = 0x1276C0u;
    ctx->pc = 0x1276C4u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x127158u;
    entry_127158_0x1273f0(rdram, ctx, runtime); return;
    ctx->pc = 0x1276C8u;
label_1276c8:
    // 0x1276c8: 0xdfbf0000
    ctx->pc = 0x1276c8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1276cc: 0x40502d
    ctx->pc = 0x1276ccu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1276d0: 0x8049cfc
    ctx->pc = 0x1276D0u;
    ctx->pc = 0x1276D4u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x1273F0u;
    goto label_1273f0;
    ctx->pc = 0x1276D8u;
}
