#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001470A0
// Address: 0x1470a0 - 0x147210
void sub_001470A0_0x1470a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1470a0u;

    // 0x1470a0: 0x27bdffc0
    ctx->pc = 0x1470a0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1470a4: 0x24050140
    ctx->pc = 0x1470a4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 320));
    // 0x1470a8: 0xffb20020
    ctx->pc = 0x1470a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1470ac: 0x3c020fff
    ctx->pc = 0x1470acu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4095 << 16));
    // 0x1470b0: 0xffb00000
    ctx->pc = 0x1470b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1470b4: 0x3c120026
    ctx->pc = 0x1470b4u;
    SET_GPR_U32(ctx, 18, ((uint32_t)38 << 16));
    // 0x1470b8: 0xffbf0030
    ctx->pc = 0x1470b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x1470bc: 0x80802d
    ctx->pc = 0x1470bcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1470c0: 0xffb10010
    ctx->pc = 0x1470c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1470c4: 0x26444a00
    ctx->pc = 0x1470c4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 18), 18944));
    // 0x1470c8: 0x3442ffff
    ctx->pc = 0x1470c8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65535));
    // 0x1470cc: 0x582d
    ctx->pc = 0x1470ccu;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1470d0: 0x8e180828
    ctx->pc = 0x1470d0u;
    SET_GPR_U32(ctx, 24, READ32(ADD32(GPR_U32(ctx, 16), 2088)));
    // 0x1470d4: 0x822024
    ctx->pc = 0x1470d4u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1470d8: 0x3051818
    ctx->pc = 0x1470d8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 24) * (int64_t)GPR_S32(ctx, 5); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)(uint32_t)result); }
    // 0x1470dc: 0x702821
    ctx->pc = 0x1470dcu;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x1470e0: 0x3c032000
    ctx->pc = 0x1470e0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x1470e4: 0x8cac06d4
    ctx->pc = 0x1470e4u;
    SET_GPR_U32(ctx, 12, READ32(ADD32(GPR_U32(ctx, 5), 1748)));
    // 0x1470e8: 0x19800025
    ctx->pc = 0x1470E8u;
    {
        const bool branch_taken_0x1470e8 = (GPR_S32(ctx, 12) <= 0);
        ctx->pc = 0x1470ECu;
        SET_GPR_U32(ctx, 10, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
        if (branch_taken_0x1470e8) {
            ctx->pc = 0x147180u;
            goto label_147180;
        }
    }
    ctx->pc = 0x1470F0u;
    // 0x1470f0: 0x260f05b0
    ctx->pc = 0x1470f0u;
    SET_GPR_S32(ctx, 15, ADD32(GPR_U32(ctx, 16), 1456));
    // 0x1470f4: 0x260e05c0
    ctx->pc = 0x1470f4u;
    SET_GPR_S32(ctx, 14, ADD32(GPR_U32(ctx, 16), 1472));
    // 0x1470f8: 0x258dffff
    ctx->pc = 0x1470f8u;
    SET_GPR_S32(ctx, 13, ADD32(GPR_U32(ctx, 12), 4294967295));
    // 0x1470fc: 0x261105a8
    ctx->pc = 0x1470fcu;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 16), 1448));
label_147100:
    // 0x147100: 0x24030140
    ctx->pc = 0x147100u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 320));
    // 0x147104: 0x16d1026
    ctx->pc = 0x147104u;
    SET_GPR_U32(ctx, 2, XOR32(GPR_U32(ctx, 11), GPR_U32(ctx, 13)));
    // 0x147108: 0x3031818
    ctx->pc = 0x147108u;
    { int64_t result = (int64_t)GPR_S32(ctx, 24) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)(uint32_t)result); }
    // 0x14710c: 0xb2080
    ctx->pc = 0x14710cu;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 11), 2));
    // 0x147110: 0x24050003
    ctx->pc = 0x147110u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 3));
    // 0x147114: 0x3c060fff
    ctx->pc = 0x147114u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4095 << 16));
    // 0x147118: 0x2280a
    ctx->pc = 0x147118u;
    if (GPR_U32(ctx, 2) == 0) SET_GPR_U32(ctx, 5, GPR_U32(ctx, 0));
    // 0x14711c: 0x34c6ffff
    ctx->pc = 0x14711cu;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 65535));
    // 0x147120: 0x52f38
    ctx->pc = 0x147120u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << 28);
    // 0x147124: 0x3c093000
    ctx->pc = 0x147124u;
    SET_GPR_U32(ctx, 9, ((uint32_t)12288 << 16));
    // 0x147128: 0x35290030
    ctx->pc = 0x147128u;
    SET_GPR_U32(ctx, 9, OR32(GPR_U32(ctx, 9), 48));
    // 0x14712c: 0x832021
    ctx->pc = 0x14712cu;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x147130: 0x24080030
    ctx->pc = 0x147130u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 48));
    // 0x147134: 0x1c41021
    ctx->pc = 0x147134u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 4)));
    // 0x147138: 0x256b0001
    ctx->pc = 0x147138u;
    SET_GPR_S32(ctx, 11, ADD32(GPR_U32(ctx, 11), 1));
    // 0x14713c: 0x8c430000
    ctx->pc = 0x14713cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x147140: 0x1e42021
    ctx->pc = 0x147140u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 15), GPR_U32(ctx, 4)));
    // 0x147144: 0x8c820000
    ctx->pc = 0x147144u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x147148: 0x16c382a
    ctx->pc = 0x147148u;
    SET_GPR_U32(ctx, 7, SLT32(GPR_S32(ctx, 11), GPR_S32(ctx, 12)));
    // 0x14714c: 0x661824
    ctx->pc = 0x14714cu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x147150: 0x461024
    ctx->pc = 0x147150u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x147154: 0x3183c
    ctx->pc = 0x147154u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x147158: 0x651825
    ctx->pc = 0x147158u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x14715c: 0x2103c
    ctx->pc = 0x14715cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x147160: 0x491025
    ctx->pc = 0x147160u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x147164: 0x681825
    ctx->pc = 0x147164u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x147168: 0xfd420000
    ctx->pc = 0x147168u;
    WRITE64(ADD32(GPR_U32(ctx, 10), 0), GPR_U64(ctx, 2));
    // 0x14716c: 0xfd430010
    ctx->pc = 0x14716cu;
    WRITE64(ADD32(GPR_U32(ctx, 10), 16), GPR_U64(ctx, 3));
    // 0x147170: 0x14e0ffe3
    ctx->pc = 0x147170u;
    {
        const bool branch_taken_0x147170 = (GPR_U32(ctx, 7) != GPR_U32(ctx, 0));
        ctx->pc = 0x147174u;
        SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 10), 32));
        if (branch_taken_0x147170) {
            ctx->pc = 0x147100u;
            goto label_147100;
        }
    }
    ctx->pc = 0x147178u;
    // 0x147178: 0x10000002
    ctx->pc = 0x147178u;
    {
        const bool branch_taken_0x147178 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x147178) {
            ctx->pc = 0x147184u;
            goto label_147184;
        }
    }
    ctx->pc = 0x147180u;
label_147180:
    // 0x147180: 0x261105a8
    ctx->pc = 0x147180u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 16), 1448));
label_147184:
    // 0x147184: 0xc047598
    ctx->pc = 0x147184u;
    SET_GPR_U32(ctx, 31, 0x14718Cu);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14718Cu; }
    }
    if (ctx->pc != 0x14718Cu) { return; }
    ctx->pc = 0x14718Cu;
    // 0x14718c: 0xf
    ctx->pc = 0x14718cu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x147190: 0x8e060828
    ctx->pc = 0x147190u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 16), 2088)));
    // 0x147194: 0x24030140
    ctx->pc = 0x147194u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 320));
    // 0x147198: 0x3c071000
    ctx->pc = 0x147198u;
    SET_GPR_U32(ctx, 7, ((uint32_t)4096 << 16));
    // 0x14719c: 0x3c081000
    ctx->pc = 0x14719cu;
    SET_GPR_U32(ctx, 8, ((uint32_t)4096 << 16));
    // 0x1471a0: 0xc32018
    ctx->pc = 0x1471a0u;
    { int64_t result = (int64_t)GPR_S32(ctx, 6) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)(uint32_t)result); }
    // 0x1471a4: 0x34e7d480
    ctx->pc = 0x1471a4u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 7), 54400));
    // 0x1471a8: 0x264a4a00
    ctx->pc = 0x1471a8u;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 18), 18944));
    // 0x1471ac: 0x3508d430
    ctx->pc = 0x1471acu;
    SET_GPR_U32(ctx, 8, OR32(GPR_U32(ctx, 8), 54320));
    // 0x1471b0: 0x3c031000
    ctx->pc = 0x1471b0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1471b4: 0x24090105
    ctx->pc = 0x1471b4u;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 0), 261));
    // 0x1471b8: 0x3463d420
    ctx->pc = 0x1471b8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 54304));
    // 0x1471bc: 0x913021
    ctx->pc = 0x1471bcu;
    SET_GPR_U32(ctx, 6, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 17)));
    // 0x1471c0: 0x8cc50000
    ctx->pc = 0x1471c0u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1471c4: 0x3c041000
    ctx->pc = 0x1471c4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x1471c8: 0x3484d400
    ctx->pc = 0x1471c8u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 54272));
    // 0x1471cc: 0xace50000
    ctx->pc = 0x1471ccu;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 5));
    // 0x1471d0: 0xad0a0000
    ctx->pc = 0x1471d0u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 10));
    // 0x1471d4: 0xac600000
    ctx->pc = 0x1471d4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0));
    // 0x1471d8: 0xac890000
    ctx->pc = 0x1471d8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 9)); // MMIO: 0x10000000
    // 0x1471dc: 0x10400006
    ctx->pc = 0x1471DCu;
    {
        const bool branch_taken_0x1471dc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1471E0u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        if (branch_taken_0x1471dc) {
            ctx->pc = 0x1471F8u;
            goto label_1471f8;
        }
    }
    ctx->pc = 0x1471E4u;
    // 0x1471e4: 0xdfb20020
    ctx->pc = 0x1471e4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1471e8: 0xdfb10010
    ctx->pc = 0x1471e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1471ec: 0xdfb00000
    ctx->pc = 0x1471ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1471f0: 0x80475ae
    ctx->pc = 0x1471F0u;
    ctx->pc = 0x1471F4u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
    ctx->pc = 0x11D6B8u;
    sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    ctx->pc = 0x1471F8u;
label_1471f8:
    // 0x1471f8: 0xdfb20020
    ctx->pc = 0x1471f8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1471fc: 0xdfb10010
    ctx->pc = 0x1471fcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x147200: 0xdfb00000
    ctx->pc = 0x147200u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x147204: 0x3e00008
    ctx->pc = 0x147204u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x147208u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x147100u: goto label_147100;
            case 0x147180u: goto label_147180;
            case 0x147184u: goto label_147184;
            case 0x1471F8u: goto label_1471f8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x14720Cu;
    // 0x14720c: 0x0
    ctx->pc = 0x14720cu;
    // NOP
}
