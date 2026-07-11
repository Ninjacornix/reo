#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00113FB0
// Address: 0x113fb0 - 0x114270
void sub_00113FB0_0x113fb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x113fb0u;

    // 0x113fb0: 0x27bdfff0
    ctx->pc = 0x113fb0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x113fb4: 0xffbf0000
    ctx->pc = 0x113fb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x113fb8: 0xc044fce
    ctx->pc = 0x113FB8u;
    SET_GPR_U32(ctx, 31, 0x113FC0u);
    ctx->pc = 0x113FBCu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x113F38u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00113F38_0x113f38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x113FC0u; }
    }
    if (ctx->pc != 0x113FC0u) { return; }
    ctx->pc = 0x113FC0u;
    // 0x113fc0: 0x3c021000
    ctx->pc = 0x113fc0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x113fc4: 0x3c034000
    ctx->pc = 0x113fc4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)16384 << 16));
    // 0x113fc8: 0x34422010
    ctx->pc = 0x113fc8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8208));
    // 0x113fcc: 0x3c041000
    ctx->pc = 0x113fccu;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x113fd0: 0xac430000
    ctx->pc = 0x113fd0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x113fd4: 0x34842010
    ctx->pc = 0x113fd4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 8208));
label_113fd8:
    // 0x113fd8: 0x8c820000
    ctx->pc = 0x113fd8u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0))); // MMIO: 0x10000000
    // 0x113fdc: 0x0
    ctx->pc = 0x113fdcu;
    // NOP
    // 0x113fe0: 0x0
    ctx->pc = 0x113fe0u;
    // NOP
    // 0x113fe4: 0x0
    ctx->pc = 0x113fe4u;
    // NOP
    // 0x113fe8: 0x0
    ctx->pc = 0x113fe8u;
    // NOP
    // 0x113fec: 0x440fffa
    ctx->pc = 0x113FECu;
    {
        const bool branch_taken_0x113fec = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x113fec) {
            ctx->pc = 0x113FD8u;
            goto label_113fd8;
        }
    }
    ctx->pc = 0x113FF4u;
    // 0x113ff4: 0x3c021000
    ctx->pc = 0x113ff4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x113ff8: 0x3c031000
    ctx->pc = 0x113ff8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x113ffc: 0x34422000
    ctx->pc = 0x113ffcu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8192));
    // 0x114000: 0x34632010
    ctx->pc = 0x114000u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 8208));
    // 0x114004: 0xac400000
    ctx->pc = 0x114004u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
label_114008:
    // 0x114008: 0x8c620000
    ctx->pc = 0x114008u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x11400c: 0x0
    ctx->pc = 0x11400cu;
    // NOP
    // 0x114010: 0x0
    ctx->pc = 0x114010u;
    // NOP
    // 0x114014: 0x0
    ctx->pc = 0x114014u;
    // NOP
    // 0x114018: 0x0
    ctx->pc = 0x114018u;
    // NOP
    // 0x11401c: 0x440fffa
    ctx->pc = 0x11401Cu;
    {
        const bool branch_taken_0x11401c = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x11401c) {
            ctx->pc = 0x114008u;
            goto label_114008;
        }
    }
    ctx->pc = 0x114024u;
    // 0x114024: 0x3c050021
    ctx->pc = 0x114024u;
    SET_GPR_U32(ctx, 5, ((uint32_t)33 << 16));
    // 0x114028: 0x3c041000
    ctx->pc = 0x114028u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x11402c: 0x24a59cb0
    ctx->pc = 0x11402cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294941872));
    // 0x114030: 0x34847010
    ctx->pc = 0x114030u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 28688));
    // 0x114034: 0x78a20000
    ctx->pc = 0x114034u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x114038: 0x3c061000
    ctx->pc = 0x114038u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
    // 0x11403c: 0x3c075000
    ctx->pc = 0x11403cu;
    SET_GPR_U32(ctx, 7, ((uint32_t)20480 << 16));
    // 0x114040: 0x34c62000
    ctx->pc = 0x114040u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 8192));
    // 0x114044: 0x7c820000
    ctx->pc = 0x114044u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 2));
    // 0x114048: 0x3c081000
    ctx->pc = 0x114048u;
    SET_GPR_U32(ctx, 8, ((uint32_t)4096 << 16));
    // 0x11404c: 0x35082010
    ctx->pc = 0x11404cu;
    SET_GPR_U32(ctx, 8, OR32(GPR_U32(ctx, 8), 8208));
    // 0x114050: 0x78a30010
    ctx->pc = 0x114050u;
    SET_GPR_VEC(ctx, 3, READ128(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x114054: 0x7c830000
    ctx->pc = 0x114054u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 3));
    // 0x114058: 0x78a20020
    ctx->pc = 0x114058u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 5), 32)));
    // 0x11405c: 0x7c820000
    ctx->pc = 0x11405cu;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 2));
    // 0x114060: 0x78a30030
    ctx->pc = 0x114060u;
    SET_GPR_VEC(ctx, 3, READ128(ADD32(GPR_U32(ctx, 5), 48)));
    // 0x114064: 0x7c830000
    ctx->pc = 0x114064u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 3));
    // 0x114068: 0x78a20040
    ctx->pc = 0x114068u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 5), 64)));
    // 0x11406c: 0x7c820000
    ctx->pc = 0x11406cu;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 2));
    // 0x114070: 0x78a30040
    ctx->pc = 0x114070u;
    SET_GPR_VEC(ctx, 3, READ128(ADD32(GPR_U32(ctx, 5), 64)));
    // 0x114074: 0x7c830000
    ctx->pc = 0x114074u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 3));
    // 0x114078: 0x78a20040
    ctx->pc = 0x114078u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 5), 64)));
    // 0x11407c: 0x7c820000
    ctx->pc = 0x11407cu;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 2));
    // 0x114080: 0x78a30040
    ctx->pc = 0x114080u;
    SET_GPR_VEC(ctx, 3, READ128(ADD32(GPR_U32(ctx, 5), 64)));
    // 0x114084: 0x7c830000
    ctx->pc = 0x114084u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 3));
    // 0x114088: 0xacc70000
    ctx->pc = 0x114088u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 7));
    // 0x11408c: 0x0
    ctx->pc = 0x11408cu;
    // NOP
label_114090:
    // 0x114090: 0x8d020000
    ctx->pc = 0x114090u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x114094: 0x0
    ctx->pc = 0x114094u;
    // NOP
    // 0x114098: 0x0
    ctx->pc = 0x114098u;
    // NOP
    // 0x11409c: 0x0
    ctx->pc = 0x11409cu;
    // NOP
    // 0x1140a0: 0x0
    ctx->pc = 0x1140a0u;
    // NOP
    // 0x1140a4: 0x440fffa
    ctx->pc = 0x1140A4u;
    {
        const bool branch_taken_0x1140a4 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x1140a4) {
            ctx->pc = 0x114090u;
            goto label_114090;
        }
    }
    ctx->pc = 0x1140ACu;
    // 0x1140ac: 0x3c021000
    ctx->pc = 0x1140acu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1140b0: 0x3c035800
    ctx->pc = 0x1140b0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)22528 << 16));
    // 0x1140b4: 0x34422000
    ctx->pc = 0x1140b4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8192));
    // 0x1140b8: 0x3c041000
    ctx->pc = 0x1140b8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x1140bc: 0xac430000
    ctx->pc = 0x1140bcu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x1140c0: 0x34842010
    ctx->pc = 0x1140c0u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 8208));
    // 0x1140c4: 0x0
    ctx->pc = 0x1140c4u;
    // NOP
label_1140c8:
    // 0x1140c8: 0x8c820000
    ctx->pc = 0x1140c8u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0))); // MMIO: 0x10000000
    // 0x1140cc: 0x0
    ctx->pc = 0x1140ccu;
    // NOP
    // 0x1140d0: 0x0
    ctx->pc = 0x1140d0u;
    // NOP
    // 0x1140d4: 0x0
    ctx->pc = 0x1140d4u;
    // NOP
    // 0x1140d8: 0x0
    ctx->pc = 0x1140d8u;
    // NOP
    // 0x1140dc: 0x440fffa
    ctx->pc = 0x1140DCu;
    {
        const bool branch_taken_0x1140dc = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x1140dc) {
            ctx->pc = 0x1140C8u;
            goto label_1140c8;
        }
    }
    ctx->pc = 0x1140E4u;
    // 0x1140e4: 0x3c030021
    ctx->pc = 0x1140e4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x1140e8: 0x3c041000
    ctx->pc = 0x1140e8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x1140ec: 0x24639d00
    ctx->pc = 0x1140ecu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294941952));
    // 0x1140f0: 0x34847010
    ctx->pc = 0x1140f0u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 28688));
    // 0x1140f4: 0x78620000
    ctx->pc = 0x1140f4u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1140f8: 0x3c051000
    ctx->pc = 0x1140f8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x1140fc: 0x3c066000
    ctx->pc = 0x1140fcu;
    SET_GPR_U32(ctx, 6, ((uint32_t)24576 << 16));
    // 0x114100: 0x34a52000
    ctx->pc = 0x114100u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 8192));
    // 0x114104: 0x7c820000
    ctx->pc = 0x114104u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 2));
    // 0x114108: 0x3c071000
    ctx->pc = 0x114108u;
    SET_GPR_U32(ctx, 7, ((uint32_t)4096 << 16));
    // 0x11410c: 0x34e72010
    ctx->pc = 0x11410cu;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 7), 8208));
    // 0x114110: 0x78620010
    ctx->pc = 0x114110u;
    SET_GPR_VEC(ctx, 2, READ128(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x114114: 0x7c820000
    ctx->pc = 0x114114u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 2));
    // 0x114118: 0xaca60000
    ctx->pc = 0x114118u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 6));
    // 0x11411c: 0x0
    ctx->pc = 0x11411cu;
    // NOP
label_114120:
    // 0x114120: 0x8ce20000
    ctx->pc = 0x114120u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x114124: 0x0
    ctx->pc = 0x114124u;
    // NOP
    // 0x114128: 0x0
    ctx->pc = 0x114128u;
    // NOP
    // 0x11412c: 0x0
    ctx->pc = 0x11412cu;
    // NOP
    // 0x114130: 0x0
    ctx->pc = 0x114130u;
    // NOP
    // 0x114134: 0x440fffa
    ctx->pc = 0x114134u;
    {
        const bool branch_taken_0x114134 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x114134) {
            ctx->pc = 0x114120u;
            goto label_114120;
        }
    }
    ctx->pc = 0x11413Cu;
    // 0x11413c: 0x3c021000
    ctx->pc = 0x11413cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x114140: 0x3c039000
    ctx->pc = 0x114140u;
    SET_GPR_U32(ctx, 3, ((uint32_t)36864 << 16));
    // 0x114144: 0x34422000
    ctx->pc = 0x114144u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8192));
    // 0x114148: 0x3c041000
    ctx->pc = 0x114148u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x11414c: 0xac430000
    ctx->pc = 0x11414cu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x114150: 0x34842010
    ctx->pc = 0x114150u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 8208));
    // 0x114154: 0x0
    ctx->pc = 0x114154u;
    // NOP
label_114158:
    // 0x114158: 0x8c820000
    ctx->pc = 0x114158u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0))); // MMIO: 0x10000000
    // 0x11415c: 0x0
    ctx->pc = 0x11415cu;
    // NOP
    // 0x114160: 0x0
    ctx->pc = 0x114160u;
    // NOP
    // 0x114164: 0x0
    ctx->pc = 0x114164u;
    // NOP
    // 0x114168: 0x0
    ctx->pc = 0x114168u;
    // NOP
    // 0x11416c: 0x440fffa
    ctx->pc = 0x11416Cu;
    {
        const bool branch_taken_0x11416c = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x11416c) {
            ctx->pc = 0x114158u;
            goto label_114158;
        }
    }
    ctx->pc = 0x114174u;
    // 0x114174: 0x3c021000
    ctx->pc = 0x114174u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x114178: 0x3c034000
    ctx->pc = 0x114178u;
    SET_GPR_U32(ctx, 3, ((uint32_t)16384 << 16));
    // 0x11417c: 0x34422010
    ctx->pc = 0x11417cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8208));
    // 0x114180: 0x3c041000
    ctx->pc = 0x114180u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x114184: 0xac430000
    ctx->pc = 0x114184u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x114188: 0x34842010
    ctx->pc = 0x114188u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 8208));
    // 0x11418c: 0x0
    ctx->pc = 0x11418cu;
    // NOP
label_114190:
    // 0x114190: 0x8c820000
    ctx->pc = 0x114190u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0))); // MMIO: 0x10000000
    // 0x114194: 0x0
    ctx->pc = 0x114194u;
    // NOP
    // 0x114198: 0x0
    ctx->pc = 0x114198u;
    // NOP
    // 0x11419c: 0x0
    ctx->pc = 0x11419cu;
    // NOP
    // 0x1141a0: 0x0
    ctx->pc = 0x1141a0u;
    // NOP
    // 0x1141a4: 0x440fffa
    ctx->pc = 0x1141A4u;
    {
        const bool branch_taken_0x1141a4 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x1141a4) {
            ctx->pc = 0x114190u;
            goto label_114190;
        }
    }
    ctx->pc = 0x1141ACu;
    // 0x1141ac: 0x3c021000
    ctx->pc = 0x1141acu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1141b0: 0x3c031000
    ctx->pc = 0x1141b0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1141b4: 0x34422000
    ctx->pc = 0x1141b4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8192));
    // 0x1141b8: 0x34632010
    ctx->pc = 0x1141b8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 8208));
    // 0x1141bc: 0xac400000
    ctx->pc = 0x1141bcu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
label_1141c0:
    // 0x1141c0: 0x8c620000
    ctx->pc = 0x1141c0u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x1141c4: 0x0
    ctx->pc = 0x1141c4u;
    // NOP
    // 0x1141c8: 0x0
    ctx->pc = 0x1141c8u;
    // NOP
    // 0x1141cc: 0x0
    ctx->pc = 0x1141ccu;
    // NOP
    // 0x1141d0: 0x0
    ctx->pc = 0x1141d0u;
    // NOP
    // 0x1141d4: 0x440fffa
    ctx->pc = 0x1141D4u;
    {
        const bool branch_taken_0x1141d4 = (GPR_S32(ctx, 2) < 0);
        if (branch_taken_0x1141d4) {
            ctx->pc = 0x1141C0u;
            goto label_1141c0;
        }
    }
    ctx->pc = 0x1141DCu;
    // 0x1141dc: 0xdfbf0000
    ctx->pc = 0x1141dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1141e0: 0x3e00008
    ctx->pc = 0x1141E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1141E4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113FD8u: goto label_113fd8;
            case 0x114008u: goto label_114008;
            case 0x114090u: goto label_114090;
            case 0x1140C8u: goto label_1140c8;
            case 0x114120u: goto label_114120;
            case 0x114158u: goto label_114158;
            case 0x114190u: goto label_114190;
            case 0x1141C0u: goto label_1141c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1141E8u;
    // 0x1141e8: 0x0
    ctx->pc = 0x1141e8u;
    // NOP
    // 0x1141ec: 0x0
    ctx->pc = 0x1141ecu;
    // NOP
    // 0x1141f0: 0x0
    ctx->pc = 0x1141f0u;
    // NOP
    // 0x1141f4: 0x0
    ctx->pc = 0x1141f4u;
    // NOP
    // 0x1141f8: 0x0
    ctx->pc = 0x1141f8u;
    // NOP
    // 0x1141fc: 0x0
    ctx->pc = 0x1141fcu;
    // NOP
    // 0x114200: 0x24030000
    ctx->pc = 0x114200u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 0));
    // 0x114204: 0xc
    ctx->pc = 0x114204u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114208: 0x3e00008
    ctx->pc = 0x114208u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113FD8u: goto label_113fd8;
            case 0x114008u: goto label_114008;
            case 0x114090u: goto label_114090;
            case 0x1140C8u: goto label_1140c8;
            case 0x114120u: goto label_114120;
            case 0x114158u: goto label_114158;
            case 0x114190u: goto label_114190;
            case 0x1141C0u: goto label_1141c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x114210u;
    // 0x114210: 0x24030001
    ctx->pc = 0x114210u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x114214: 0xc
    ctx->pc = 0x114214u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114218: 0x3e00008
    ctx->pc = 0x114218u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113FD8u: goto label_113fd8;
            case 0x114008u: goto label_114008;
            case 0x114090u: goto label_114090;
            case 0x1140C8u: goto label_1140c8;
            case 0x114120u: goto label_114120;
            case 0x114158u: goto label_114158;
            case 0x114190u: goto label_114190;
            case 0x1141C0u: goto label_1141c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x114220u;
    // 0x114220: 0x24030002
    ctx->pc = 0x114220u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
    // 0x114224: 0xc
    ctx->pc = 0x114224u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114228: 0x3e00008
    ctx->pc = 0x114228u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113FD8u: goto label_113fd8;
            case 0x114008u: goto label_114008;
            case 0x114090u: goto label_114090;
            case 0x1140C8u: goto label_1140c8;
            case 0x114120u: goto label_114120;
            case 0x114158u: goto label_114158;
            case 0x114190u: goto label_114190;
            case 0x1141C0u: goto label_1141c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x114230u;
    // 0x114230: 0x24030003
    ctx->pc = 0x114230u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 3));
    // 0x114234: 0xc
    ctx->pc = 0x114234u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114238: 0x3e00008
    ctx->pc = 0x114238u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113FD8u: goto label_113fd8;
            case 0x114008u: goto label_114008;
            case 0x114090u: goto label_114090;
            case 0x1140C8u: goto label_1140c8;
            case 0x114120u: goto label_114120;
            case 0x114158u: goto label_114158;
            case 0x114190u: goto label_114190;
            case 0x1141C0u: goto label_1141c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x114240u;
    // 0x114240: 0x24030004
    ctx->pc = 0x114240u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4));
    // 0x114244: 0xc
    ctx->pc = 0x114244u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114248: 0x3e00008
    ctx->pc = 0x114248u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113FD8u: goto label_113fd8;
            case 0x114008u: goto label_114008;
            case 0x114090u: goto label_114090;
            case 0x1140C8u: goto label_1140c8;
            case 0x114120u: goto label_114120;
            case 0x114158u: goto label_114158;
            case 0x114190u: goto label_114190;
            case 0x1141C0u: goto label_1141c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x114250u;
    // 0x114250: 0x24030005
    ctx->pc = 0x114250u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 5));
    // 0x114254: 0xc
    ctx->pc = 0x114254u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114258: 0x3e00008
    ctx->pc = 0x114258u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113FD8u: goto label_113fd8;
            case 0x114008u: goto label_114008;
            case 0x114090u: goto label_114090;
            case 0x1140C8u: goto label_1140c8;
            case 0x114120u: goto label_114120;
            case 0x114158u: goto label_114158;
            case 0x114190u: goto label_114190;
            case 0x1141C0u: goto label_1141c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x114260u;
    // 0x114260: 0x24030006
    ctx->pc = 0x114260u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 6));
    // 0x114264: 0xc
    ctx->pc = 0x114264u;
    runtime->handleSyscall(rdram, ctx, 0x0u);
    // 0x114268: 0x3e00008
    ctx->pc = 0x114268u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x113FD8u: goto label_113fd8;
            case 0x114008u: goto label_114008;
            case 0x114090u: goto label_114090;
            case 0x1140C8u: goto label_1140c8;
            case 0x114120u: goto label_114120;
            case 0x114158u: goto label_114158;
            case 0x114190u: goto label_114190;
            case 0x1141C0u: goto label_1141c0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x114270u;
}
