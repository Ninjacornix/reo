#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: entry_1785a0
// Address: 0x1785a0 - 0x178910
void entry_1785a0_0x178910(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1785a0u;

    // 0x1785a0: 0x27bdfe00
    ctx->pc = 0x1785a0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294966784));
    // 0x1785a4: 0x3c030023
    ctx->pc = 0x1785a4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x1785a8: 0xffbe01f0
    ctx->pc = 0x1785a8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 496), GPR_U64(ctx, 30));
    // 0x1785ac: 0xffb001b0
    ctx->pc = 0x1785acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 432), GPR_U64(ctx, 16));
    // 0x1785b0: 0x2463f1dc
    ctx->pc = 0x1785b0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294963676));
    // 0x1785b4: 0xffb101b8
    ctx->pc = 0x1785b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 440), GPR_U64(ctx, 17));
    // 0x1785b8: 0xffb201c0
    ctx->pc = 0x1785b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 448), GPR_U64(ctx, 18));
    // 0x1785bc: 0xffb301c8
    ctx->pc = 0x1785bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 456), GPR_U64(ctx, 19));
    // 0x1785c0: 0xffb401d0
    ctx->pc = 0x1785c0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 464), GPR_U64(ctx, 20));
    // 0x1785c4: 0xffb501d8
    ctx->pc = 0x1785c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 472), GPR_U64(ctx, 21));
    // 0x1785c8: 0xffb601e0
    ctx->pc = 0x1785c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 480), GPR_U64(ctx, 22));
    // 0x1785cc: 0xffb701e8
    ctx->pc = 0x1785ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 488), GPR_U64(ctx, 23));
    // 0x1785d0: 0xffbf01f8
    ctx->pc = 0x1785d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 504), GPR_U64(ctx, 31));
    // 0x1785d4: 0x8c620000
    ctx->pc = 0x1785d4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1785d8: 0x10400077
    ctx->pc = 0x1785D8u;
    {
        const bool branch_taken_0x1785d8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1785DCu;
        SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1785d8) {
            ctx->pc = 0x1787B8u;
            goto label_1787b8;
        }
    }
    ctx->pc = 0x1785E0u;
    // 0x1785e0: 0xdfd20118
    ctx->pc = 0x1785e0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 30), 280)));
    // 0x1785e4: 0x3c020024
    ctx->pc = 0x1785e4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)36 << 16));
    // 0x1785e8: 0xdfd10120
    ctx->pc = 0x1785e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 30), 288)));
    // 0x1785ec: 0x24540c78
    ctx->pc = 0x1785ecu;
    SET_GPR_S32(ctx, 20, ADD32(GPR_U32(ctx, 2), 3192));
    // 0x1785f0: 0x240202d
    ctx->pc = 0x1785f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1785f4: 0xc043ec6
    ctx->pc = 0x1785F4u;
    SET_GPR_U32(ctx, 31, 0x1785FCu);
    ctx->pc = 0x1785F8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10FB18u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1785FCu; }
    }
    if (ctx->pc != 0x1785FCu) { return; }
    ctx->pc = 0x1785FCu;
    // 0x1785fc: 0x240202d
    ctx->pc = 0x1785fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178600: 0x2103c
    ctx->pc = 0x178600u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x178604: 0x2103f
    ctx->pc = 0x178604u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x178608: 0xc0444ca
    ctx->pc = 0x178608u;
    SET_GPR_U32(ctx, 31, 0x178610u);
    ctx->pc = 0x17860Cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 416), GPR_U32(ctx, 2));
    ctx->pc = 0x111328u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00111328_0x111328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178610u; }
    }
    if (ctx->pc != 0x178610u) { return; }
    ctx->pc = 0x178610u;
    // 0x178610: 0x40802d
    ctx->pc = 0x178610u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178614: 0xc0444ca
    ctx->pc = 0x178614u;
    SET_GPR_U32(ctx, 31, 0x17861Cu);
    ctx->pc = 0x178618u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x111328u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00111328_0x111328(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17861Cu; }
    }
    if (ctx->pc != 0x17861Cu) { return; }
    ctx->pc = 0x17861Cu;
    // 0x17861c: 0x200202d
    ctx->pc = 0x17861cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178620: 0xc04480e
    ctx->pc = 0x178620u;
    SET_GPR_U32(ctx, 31, 0x178628u);
    ctx->pc = 0x178624u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x112038u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00112038_0x112038(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178628u; }
    }
    if (ctx->pc != 0x178628u) { return; }
    ctx->pc = 0x178628u;
    // 0x178628: 0x3c010024
    ctx->pc = 0x178628u;
    SET_GPR_U32(ctx, 1, ((uint32_t)36 << 16));
    // 0x17862c: 0xdc250cf0
    ctx->pc = 0x17862cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 1), 3312)));
    // 0x178630: 0xc04476c
    ctx->pc = 0x178630u;
    SET_GPR_U32(ctx, 31, 0x178638u);
    ctx->pc = 0x178634u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x111DB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00111DB0_0x111db0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178638u; }
    }
    if (ctx->pc != 0x178638u) { return; }
    ctx->pc = 0x178638u;
    // 0x178638: 0x3405ff80
    ctx->pc = 0x178638u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 0), 65408));
    // 0x17863c: 0x52bbc
    ctx->pc = 0x17863cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 14));
    // 0x178640: 0xc04473c
    ctx->pc = 0x178640u;
    SET_GPR_U32(ctx, 31, 0x178648u);
    ctx->pc = 0x178644u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x111CF0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00111CF0_0x111cf0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178648u; }
    }
    if (ctx->pc != 0x178648u) { return; }
    ctx->pc = 0x178648u;
    // 0x178648: 0x40802d
    ctx->pc = 0x178648u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17864c: 0xc0448e8
    ctx->pc = 0x17864Cu;
    SET_GPR_U32(ctx, 31, 0x178654u);
    ctx->pc = 0x178650u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1123A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001123A0_0x1123a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178654u; }
    }
    if (ctx->pc != 0x178654u) { return; }
    ctx->pc = 0x178654u;
    // 0x178654: 0x40882d
    ctx->pc = 0x178654u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178658: 0xc0448ba
    ctx->pc = 0x178658u;
    SET_GPR_U32(ctx, 31, 0x178660u);
    ctx->pc = 0x17865Cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1122E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001122E8_0x1122e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178660u; }
    }
    if (ctx->pc != 0x178660u) { return; }
    ctx->pc = 0x178660u;
    // 0x178660: 0x200282d
    ctx->pc = 0x178660u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178664: 0xc0448a6
    ctx->pc = 0x178664u;
    SET_GPR_U32(ctx, 31, 0x17866Cu);
    ctx->pc = 0x178668u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x112298u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00112298_0x112298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17866Cu; }
    }
    if (ctx->pc != 0x17866Cu) { return; }
    ctx->pc = 0x17866Cu;
    // 0x17866c: 0x2628ffff
    ctx->pc = 0x17866cu;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 17), 4294967295));
    // 0x178670: 0xdfc30128
    ctx->pc = 0x178670u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 30), 296)));
    // 0x178674: 0x2102a
    ctx->pc = 0x178674u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 0), GPR_S32(ctx, 2)));
    // 0x178678: 0xdfcd0108
    ctx->pc = 0x178678u;
    SET_GPR_U64(ctx, 13, READ64(ADD32(GPR_U32(ctx, 30), 264)));
    // 0x17867c: 0x3c0b7fff
    ctx->pc = 0x17867cu;
    SET_GPR_U32(ctx, 11, ((uint32_t)32767 << 16));
    // 0x178680: 0x356bffff
    ctx->pc = 0x178680u;
    SET_GPR_U32(ctx, 11, OR32(GPR_U32(ctx, 11), 65535));
    // 0x178684: 0xdfcc0188
    ctx->pc = 0x178684u;
    SET_GPR_U64(ctx, 12, READ64(ADD32(GPR_U32(ctx, 30), 392)));
    // 0x178688: 0x222400a
    ctx->pc = 0x178688u;
    if (GPR_U32(ctx, 2) == 0) SET_GPR_U32(ctx, 8, GPR_U32(ctx, 17));
    // 0x17868c: 0x8fd90128
    ctx->pc = 0x17868cu;
    SET_GPR_U32(ctx, 25, READ32(ADD32(GPR_U32(ctx, 30), 296)));
    // 0x178690: 0x280282d
    ctx->pc = 0x178690u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178694: 0x8fd801b0
    ctx->pc = 0x178694u;
    SET_GPR_U32(ctx, 24, READ32(ADD32(GPR_U32(ctx, 30), 432)));
    // 0x178698: 0x12483f
    ctx->pc = 0x178698u;
    SET_GPR_S64(ctx, 9, GPR_S64(ctx, 18) >> (32 + 0));
    // 0x17869c: 0x8fcf01a0
    ctx->pc = 0x17869cu;
    SET_GPR_U32(ctx, 15, READ32(ADD32(GPR_U32(ctx, 30), 416)));
    // 0x1786a0: 0x1a3682f
    ctx->pc = 0x1786a0u;
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 13) - GPR_U64(ctx, 3));
    // 0x1786a4: 0x8fce0190
    ctx->pc = 0x1786a4u;
    SET_GPR_U32(ctx, 14, READ32(ADD32(GPR_U32(ctx, 30), 400)));
    // 0x1786a8: 0x183602f
    ctx->pc = 0x1786a8u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) - GPR_U64(ctx, 3));
    // 0x1786ac: 0x8fd10008
    ctx->pc = 0x1786acu;
    SET_GPR_U32(ctx, 17, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1786b0: 0x24b5824
    ctx->pc = 0x1786b0u;
    SET_GPR_U32(ctx, 11, AND32(GPR_U32(ctx, 18), GPR_U32(ctx, 11)));
    // 0x1786b4: 0x8fc30198
    ctx->pc = 0x1786b4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 408)));
    // 0x1786b8: 0xd683c
    ctx->pc = 0x1786b8u;
    SET_GPR_U64(ctx, 13, GPR_U64(ctx, 13) << (32 + 0));
    // 0x1786bc: 0xd683f
    ctx->pc = 0x1786bcu;
    SET_GPR_S64(ctx, 13, GPR_S64(ctx, 13) >> (32 + 0));
    // 0x1786c0: 0x8fd0019c
    ctx->pc = 0x1786c0u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 30), 412)));
    // 0x1786c4: 0xc603c
    ctx->pc = 0x1786c4u;
    SET_GPR_U64(ctx, 12, GPR_U64(ctx, 12) << (32 + 0));
    // 0x1786c8: 0xc603f
    ctx->pc = 0x1786c8u;
    SET_GPR_S64(ctx, 12, GPR_S64(ctx, 12) >> (32 + 0));
    // 0x1786cc: 0x8fc20194
    ctx->pc = 0x1786ccu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 404)));
    // 0x1786d0: 0x27a400a0
    ctx->pc = 0x1786d0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 160));
    // 0x1786d4: 0x8fd60108
    ctx->pc = 0x1786d4u;
    SET_GPR_U32(ctx, 22, READ32(ADD32(GPR_U32(ctx, 30), 264)));
    // 0x1786d8: 0x3c0302d
    ctx->pc = 0x1786d8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1786dc: 0x8fd301ac
    ctx->pc = 0x1786dcu;
    SET_GPR_U32(ctx, 19, READ32(ADD32(GPR_U32(ctx, 30), 428)));
    // 0x1786e0: 0xb583c
    ctx->pc = 0x1786e0u;
    SET_GPR_U64(ctx, 11, GPR_U64(ctx, 11) << (32 + 0));
    // 0x1786e4: 0xb583f
    ctx->pc = 0x1786e4u;
    SET_GPR_S64(ctx, 11, GPR_S64(ctx, 11) >> (32 + 0));
    // 0x1786e8: 0x8fd701b4
    ctx->pc = 0x1786e8u;
    SET_GPR_U32(ctx, 23, READ32(ADD32(GPR_U32(ctx, 30), 436)));
    // 0x1786ec: 0x8fd501b8
    ctx->pc = 0x1786ecu;
    SET_GPR_U32(ctx, 21, READ32(ADD32(GPR_U32(ctx, 30), 440)));
    // 0x1786f0: 0x8fd40004
    ctx->pc = 0x1786f0u;
    SET_GPR_U32(ctx, 20, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1786f4: 0x8fd20188
    ctx->pc = 0x1786f4u;
    SET_GPR_U32(ctx, 18, READ32(ADD32(GPR_U32(ctx, 30), 392)));
    // 0x1786f8: 0x8fca0118
    ctx->pc = 0x1786f8u;
    SET_GPR_U32(ctx, 10, READ32(ADD32(GPR_U32(ctx, 30), 280)));
    // 0x1786fc: 0x8fa701a0
    ctx->pc = 0x1786fcu;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 29), 416)));
    // 0x178700: 0xafac0020
    ctx->pc = 0x178700u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 12));
    // 0x178704: 0xafb10050
    ctx->pc = 0x178704u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 80), GPR_U32(ctx, 17));
    // 0x178708: 0xafb00058
    ctx->pc = 0x178708u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 88), GPR_U32(ctx, 16));
    // 0x17870c: 0xafb20000
    ctx->pc = 0x17870cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 18));
    // 0x178710: 0xafb60008
    ctx->pc = 0x178710u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 22));
    // 0x178714: 0xafb90010
    ctx->pc = 0x178714u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 25));
    // 0x178718: 0xafad0018
    ctx->pc = 0x178718u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 24), GPR_U32(ctx, 13));
    // 0x17871c: 0xafb30028
    ctx->pc = 0x17871cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 19));
    // 0x178720: 0xafb80030
    ctx->pc = 0x178720u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 48), GPR_U32(ctx, 24));
    // 0x178724: 0xafb70038
    ctx->pc = 0x178724u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 56), GPR_U32(ctx, 23));
    // 0x178728: 0xafb50040
    ctx->pc = 0x178728u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 64), GPR_U32(ctx, 21));
    // 0x17872c: 0xafb40048
    ctx->pc = 0x17872cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 72), GPR_U32(ctx, 20));
    // 0x178730: 0xafaf0060
    ctx->pc = 0x178730u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 96), GPR_U32(ctx, 15));
    // 0x178734: 0xafae0068
    ctx->pc = 0x178734u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 104), GPR_U32(ctx, 14));
    // 0x178738: 0xafa20070
    ctx->pc = 0x178738u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 112), GPR_U32(ctx, 2));
    // 0x17873c: 0x3c020023
    ctx->pc = 0x17873cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x178740: 0xafa30078
    ctx->pc = 0x178740u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 120), GPR_U32(ctx, 3));
    // 0x178744: 0x8c4cef68
    ctx->pc = 0x178744u;
    SET_GPR_U32(ctx, 12, READ32(ADD32(GPR_U32(ctx, 2), 4294963048)));
    // 0x178748: 0x8fc301a8
    ctx->pc = 0x178748u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 424)));
    // 0x17874c: 0x8fc201a4
    ctx->pc = 0x17874cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 420)));
    // 0x178750: 0xafa30088
    ctx->pc = 0x178750u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 136), GPR_U32(ctx, 3));
    // 0x178754: 0xafa20080
    ctx->pc = 0x178754u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 128), GPR_U32(ctx, 2));
    // 0x178758: 0xc042a0c
    ctx->pc = 0x178758u;
    SET_GPR_U32(ctx, 31, 0x178760u);
    ctx->pc = 0x17875Cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 144), GPR_U32(ctx, 12));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178760u; }
    }
    if (ctx->pc != 0x178760u) { return; }
    ctx->pc = 0x178760u;
    // 0x178760: 0x40802d
    ctx->pc = 0x178760u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178764: 0x3c020023
    ctx->pc = 0x178764u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x178768: 0x2451f1e4
    ctx->pc = 0x178768u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 2), 4294963684));
    // 0x17876c: 0x27a500a0
    ctx->pc = 0x17876cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 160));
    // 0x178770: 0xc042bf0
    ctx->pc = 0x178770u;
    SET_GPR_U32(ctx, 31, 0x178778u);
    ctx->pc = 0x178774u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    ctx->pc = 0x10AFC0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178778u; }
    }
    if (ctx->pc != 0x178778u) { return; }
    ctx->pc = 0x178778u;
    // 0x178778: 0x8e230000
    ctx->pc = 0x178778u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17877c: 0x3c050023
    ctx->pc = 0x17877cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)35 << 16));
    // 0x178780: 0x3c040023
    ctx->pc = 0x178780u;
    SET_GPR_U32(ctx, 4, ((uint32_t)35 << 16));
    // 0x178784: 0x24a5f1dc
    ctx->pc = 0x178784u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294963676));
    // 0x178788: 0x701821
    ctx->pc = 0x178788u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x17878c: 0x8ca20000
    ctx->pc = 0x17878cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x178790: 0x8c85f1d8
    ctx->pc = 0x178790u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 4), 4294963672)));
    // 0x178794: 0xae230000
    ctx->pc = 0x178794u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
    // 0x178798: 0x451021
    ctx->pc = 0x178798u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x17879c: 0x2442fc00
    ctx->pc = 0x17879cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294966272));
    // 0x1787a0: 0x62182b
    ctx->pc = 0x1787a0u;
    SET_GPR_U32(ctx, 3, SLTU32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1787a4: 0x14600005
    ctx->pc = 0x1787A4u;
    {
        const bool branch_taken_0x1787a4 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x1787A8u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 432)));
        if (branch_taken_0x1787a4) {
            ctx->pc = 0x1787BCu;
            goto label_1787bc;
        }
    }
    ctx->pc = 0x1787ACu;
    // 0x1787ac: 0x3c020023
    ctx->pc = 0x1787acu;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x1787b0: 0x8c43f1e8
    ctx->pc = 0x1787b0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 4294963688)));
    // 0x1787b4: 0xae230000
    ctx->pc = 0x1787b4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
label_1787b8:
    // 0x1787b8: 0xdfb001b0
    ctx->pc = 0x1787b8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 432)));
label_1787bc:
    // 0x1787bc: 0xdfb101b8
    ctx->pc = 0x1787bcu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 440)));
    // 0x1787c0: 0xdfb201c0
    ctx->pc = 0x1787c0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 448)));
    // 0x1787c4: 0xdfb301c8
    ctx->pc = 0x1787c4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 456)));
    // 0x1787c8: 0xdfb401d0
    ctx->pc = 0x1787c8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 464)));
    // 0x1787cc: 0xdfb501d8
    ctx->pc = 0x1787ccu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 472)));
    // 0x1787d0: 0xdfb601e0
    ctx->pc = 0x1787d0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 480)));
    // 0x1787d4: 0xdfb701e8
    ctx->pc = 0x1787d4u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 488)));
    // 0x1787d8: 0xdfbe01f0
    ctx->pc = 0x1787d8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 496)));
    // 0x1787dc: 0xdfbf01f8
    ctx->pc = 0x1787dcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 504)));
    // 0x1787e0: 0x3e00008
    ctx->pc = 0x1787E0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1787E4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 512));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1787B8u: goto label_1787b8;
            case 0x1787BCu: goto label_1787bc;
            case 0x178868u: goto label_178868;
            case 0x1788A8u: goto label_1788a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1787E8u;
    // 0x1787e8: 0x27bdffc0
    ctx->pc = 0x1787e8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x1787ec: 0xffb00000
    ctx->pc = 0x1787ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1787f0: 0xffb10008
    ctx->pc = 0x1787f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1787f4: 0x80882d
    ctx->pc = 0x1787f4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1787f8: 0xffb30018
    ctx->pc = 0x1787f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x1787fc: 0x100982d
    ctx->pc = 0x1787fcu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178800: 0xffb40020
    ctx->pc = 0x178800u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x178804: 0xc0a02d
    ctx->pc = 0x178804u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178808: 0xffb50028
    ctx->pc = 0x178808u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x17880c: 0xe0a82d
    ctx->pc = 0x17880cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178810: 0xffb60030
    ctx->pc = 0x178810u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x178814: 0xa0b02d
    ctx->pc = 0x178814u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178818: 0xffb20010
    ctx->pc = 0x178818u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x17881c: 0xffbf0038
    ctx->pc = 0x17881cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x178820: 0xc05a78c
    ctx->pc = 0x178820u;
    SET_GPR_U32(ctx, 31, 0x178828u);
    ctx->pc = 0x178824u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 17), 7360));
    ctx->pc = 0x169E30u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178828u; }
    }
    if (ctx->pc != 0x178828u) { return; }
    ctx->pc = 0x178828u;
    // 0x178828: 0x3c05ff00
    ctx->pc = 0x178828u;
    SET_GPR_U32(ctx, 5, ((uint32_t)65280 << 16));
    // 0x17882c: 0x202d
    ctx->pc = 0x17882cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178830: 0x34a50192
    ctx->pc = 0x178830u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 402));
    // 0x178834: 0x1040000c
    ctx->pc = 0x178834u;
    {
        const bool branch_taken_0x178834 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x178838u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 8));
        if (branch_taken_0x178834) {
            ctx->pc = 0x178868u;
            goto label_178868;
        }
    }
    ctx->pc = 0x17883Cu;
    // 0x17883c: 0xdfb00000
    ctx->pc = 0x17883cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178840: 0xdfb10008
    ctx->pc = 0x178840u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x178844: 0xdfb20010
    ctx->pc = 0x178844u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x178848: 0xdfb30018
    ctx->pc = 0x178848u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17884c: 0xdfb40020
    ctx->pc = 0x17884cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x178850: 0xdfb50028
    ctx->pc = 0x178850u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x178854: 0xdfb60030
    ctx->pc = 0x178854u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x178858: 0xdfbf0038
    ctx->pc = 0x178858u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x17885c: 0x805a704
    ctx->pc = 0x17885Cu;
    ctx->pc = 0x178860u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
    ctx->pc = 0x169C10u;
    sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    ctx->pc = 0x178864u;
    // 0x178864: 0x0
    ctx->pc = 0x178864u;
    // NOP
label_178868:
    // 0x178868: 0x8e120010
    ctx->pc = 0x178868u;
    SET_GPR_U32(ctx, 18, READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x17886c: 0x1643000e
    ctx->pc = 0x17886Cu;
    {
        const bool branch_taken_0x17886c = (GPR_U32(ctx, 18) != GPR_U32(ctx, 3));
        ctx->pc = 0x178870u;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 8)));
        if (branch_taken_0x17886c) {
            ctx->pc = 0x1788A8u;
            goto label_1788a8;
        }
    }
    ctx->pc = 0x178874u;
    // 0x178874: 0x220202d
    ctx->pc = 0x178874u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178878: 0xdfb10008
    ctx->pc = 0x178878u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x17887c: 0x3c05ff00
    ctx->pc = 0x17887cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)65280 << 16));
    // 0x178880: 0xdfb00000
    ctx->pc = 0x178880u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x178884: 0xdfb20010
    ctx->pc = 0x178884u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x178888: 0x34a50602
    ctx->pc = 0x178888u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 1538));
    // 0x17888c: 0xdfb30018
    ctx->pc = 0x17888cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x178890: 0xdfb40020
    ctx->pc = 0x178890u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x178894: 0xdfb50028
    ctx->pc = 0x178894u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x178898: 0xdfb60030
    ctx->pc = 0x178898u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17889c: 0xdfbf0038
    ctx->pc = 0x17889cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x1788a0: 0x805a704
    ctx->pc = 0x1788A0u;
    ctx->pc = 0x1788A4u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
    ctx->pc = 0x169C10u;
    sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    ctx->pc = 0x1788A8u;
label_1788a8:
    // 0x1788a8: 0x168100
    ctx->pc = 0x1788a8u;
    SET_GPR_U32(ctx, 16, SLL32(GPR_U32(ctx, 22), 4));
    // 0x1788ac: 0x260402d
    ctx->pc = 0x1788acu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788b0: 0x508021
    ctx->pc = 0x1788b0u;
    SET_GPR_U32(ctx, 16, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x1788b4: 0x280282d
    ctx->pc = 0x1788b4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788b8: 0x26100004
    ctx->pc = 0x1788b8u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 4));
    // 0x1788bc: 0x2a0382d
    ctx->pc = 0x1788bcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788c0: 0x200202d
    ctx->pc = 0x1788c0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788c4: 0xc05e318
    ctx->pc = 0x1788C4u;
    SET_GPR_U32(ctx, 31, 0x1788CCu);
    ctx->pc = 0x1788C8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x178C60u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00178C60_0x178c60(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1788CCu; }
    }
    if (ctx->pc != 0x1788CCu) { return; }
    ctx->pc = 0x1788CCu;
    // 0x1788cc: 0x220202d
    ctx->pc = 0x1788ccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788d0: 0x240282d
    ctx->pc = 0x1788d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788d4: 0x2c0302d
    ctx->pc = 0x1788d4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788d8: 0xc059bc6
    ctx->pc = 0x1788D8u;
    SET_GPR_U32(ctx, 31, 0x1788E0u);
    ctx->pc = 0x1788DCu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x166F18u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00166F18_0x166f18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1788E0u; }
    }
    if (ctx->pc != 0x1788E0u) { return; }
    ctx->pc = 0x1788E0u;
    // 0x1788e0: 0x102d
    ctx->pc = 0x1788e0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1788e4: 0xdfb00000
    ctx->pc = 0x1788e4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1788e8: 0xdfb10008
    ctx->pc = 0x1788e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1788ec: 0xdfb20010
    ctx->pc = 0x1788ecu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1788f0: 0xdfb30018
    ctx->pc = 0x1788f0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1788f4: 0xdfb40020
    ctx->pc = 0x1788f4u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1788f8: 0xdfb50028
    ctx->pc = 0x1788f8u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x1788fc: 0xdfb60030
    ctx->pc = 0x1788fcu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x178900: 0xdfbf0038
    ctx->pc = 0x178900u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x178904: 0x3e00008
    ctx->pc = 0x178904u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178908u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1787B8u: goto label_1787b8;
            case 0x1787BCu: goto label_1787bc;
            case 0x178868u: goto label_178868;
            case 0x1788A8u: goto label_1788a8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17890Cu;
    // 0x17890c: 0x0
    ctx->pc = 0x17890cu;
    // NOP
}
