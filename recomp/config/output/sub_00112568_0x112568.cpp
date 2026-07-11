#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00112568
// Address: 0x112568 - 0x1126f8
void sub_00112568_0x112568(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x112568u;

    // 0x112568: 0x27bdffb0
    ctx->pc = 0x112568u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x11256c: 0x42400
    ctx->pc = 0x11256cu;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 16));
    // 0x112570: 0xffb30030
    ctx->pc = 0x112570u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x112574: 0x52c00
    ctx->pc = 0x112574u;
    SET_GPR_U32(ctx, 5, SLL32(GPR_U32(ctx, 5), 16));
    // 0x112578: 0xffb20020
    ctx->pc = 0x112578u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11257c: 0x63400
    ctx->pc = 0x11257cu;
    SET_GPR_U32(ctx, 6, SLL32(GPR_U32(ctx, 6), 16));
    // 0x112580: 0xffb10010
    ctx->pc = 0x112580u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x112584: 0x73c00
    ctx->pc = 0x112584u;
    SET_GPR_U32(ctx, 7, SLL32(GPR_U32(ctx, 7), 16));
    // 0x112588: 0xffbf0040
    ctx->pc = 0x112588u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x11258c: 0x42403
    ctx->pc = 0x11258cu;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 16));
    // 0x112590: 0xffb00000
    ctx->pc = 0x112590u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x112594: 0x58c03
    ctx->pc = 0x112594u;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 5), 16));
    // 0x112598: 0x69403
    ctx->pc = 0x112598u;
    SET_GPR_S32(ctx, 18, SRA32(GPR_S32(ctx, 6), 16));
    // 0x11259c: 0x24020001
    ctx->pc = 0x11259cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1125a0: 0x10820031
    ctx->pc = 0x1125A0u;
    {
        const bool branch_taken_0x1125a0 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        ctx->pc = 0x1125A4u;
        SET_GPR_S32(ctx, 19, SRA32(GPR_S32(ctx, 7), 16));
        if (branch_taken_0x1125a0) {
            ctx->pc = 0x112668u;
            goto label_112668;
        }
    }
    ctx->pc = 0x1125A8u;
    // 0x1125a8: 0x28820002
    ctx->pc = 0x1125a8u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 4), 2));
    // 0x1125ac: 0x50400005
    ctx->pc = 0x1125ACu;
    {
        const bool branch_taken_0x1125ac = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1125ac) {
            ctx->pc = 0x1125B0u;
            SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 5));
            ctx->pc = 0x1125C4u;
            goto label_1125c4;
        }
    }
    ctx->pc = 0x1125B4u;
    // 0x1125b4: 0x10800007
    ctx->pc = 0x1125B4u;
    {
        const bool branch_taken_0x1125b4 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x1125B8u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        if (branch_taken_0x1125b4) {
            ctx->pc = 0x1125D4u;
            goto label_1125d4;
        }
    }
    ctx->pc = 0x1125BCu;
    // 0x1125bc: 0x10000049
    ctx->pc = 0x1125BCu;
    {
        const bool branch_taken_0x1125bc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1125C0u;
        SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        if (branch_taken_0x1125bc) {
            ctx->pc = 0x1126E4u;
            goto label_1126e4;
        }
    }
    ctx->pc = 0x1125C4u;
label_1125c4:
    // 0x1125c4: 0x1082002e
    ctx->pc = 0x1125C4u;
    {
        const bool branch_taken_0x1125c4 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        ctx->pc = 0x1125C8u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        if (branch_taken_0x1125c4) {
            ctx->pc = 0x112680u;
            goto label_112680;
        }
    }
    ctx->pc = 0x1125CCu;
    // 0x1125cc: 0x10000045
    ctx->pc = 0x1125CCu;
    {
        const bool branch_taken_0x1125cc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1125D0u;
        SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        if (branch_taken_0x1125cc) {
            ctx->pc = 0x1126E4u;
            goto label_1126e4;
        }
    }
    ctx->pc = 0x1125D4u;
label_1125d4:
    // 0x1125d4: 0xc0449be
    ctx->pc = 0x1125D4u;
    SET_GPR_U32(ctx, 31, 0x1125DCu);
    ctx->pc = 0x1126F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001126F8_0x1126f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1125DCu; }
    }
    if (ctx->pc != 0x1125DCu) { return; }
    ctx->pc = 0x1125DCu;
    // 0x1125dc: 0x3c031200
    ctx->pc = 0x1125dcu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4608 << 16));
    // 0x1125e0: 0x24040200
    ctx->pc = 0x1125e0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 512));
    // 0x1125e4: 0x34631000
    ctx->pc = 0x1125e4u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 4096));
    // 0x1125e8: 0x40802d
    ctx->pc = 0x1125e8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1125ec: 0xfc640000
    ctx->pc = 0x1125ecu;
    WRITE64(ADD32(GPR_U32(ctx, 3), 0), GPR_U64(ctx, 4));
    // 0x1125f0: 0xa6110000
    ctx->pc = 0x1125f0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 17));
    // 0x1125f4: 0x3404ff00
    ctx->pc = 0x1125f4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 0), 65280));
    // 0x1125f8: 0xdc620000
    ctx->pc = 0x1125f8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1125fc: 0xa6120002
    ctx->pc = 0x1125fcu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 18));
    // 0x112600: 0x2143a
    ctx->pc = 0x112600u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 16);
    // 0x112604: 0x304200ff
    ctx->pc = 0x112604u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 255));
    // 0x112608: 0x3042ffff
    ctx->pc = 0x112608u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 65535));
    // 0x11260c: 0xc045258
    ctx->pc = 0x11260Cu;
    SET_GPR_U32(ctx, 31, 0x112614u);
    ctx->pc = 0x112610u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 2));
    ctx->pc = 0x114960u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114960_0x114960(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112614u; }
    }
    if (ctx->pc != 0x112614u) { return; }
    ctx->pc = 0x112614u;
    // 0x112614: 0x13182b
    ctx->pc = 0x112614u;
    SET_GPR_U32(ctx, 3, SLTU32(GPR_U32(ctx, 0), GPR_U32(ctx, 19)));
    // 0x112618: 0x8e020008
    ctx->pc = 0x112618u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11261c: 0x10400008
    ctx->pc = 0x11261Cu;
    {
        const bool branch_taken_0x11261c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x112620u;
        WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 3));
        if (branch_taken_0x11261c) {
            ctx->pc = 0x112640u;
            goto label_112640;
        }
    }
    ctx->pc = 0x112624u;
    // 0x112624: 0xc045440
    ctx->pc = 0x112624u;
    SET_GPR_U32(ctx, 31, 0x11262Cu);
    ctx->pc = 0x112628u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x115100u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00115100_0x115100(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11262Cu; }
    }
    if (ctx->pc != 0x11262Cu) { return; }
    ctx->pc = 0x11262Cu;
    // 0x11262c: 0x8e05000c
    ctx->pc = 0x11262cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x112630: 0xc0450c8
    ctx->pc = 0x112630u;
    SET_GPR_U32(ctx, 31, 0x112638u);
    ctx->pc = 0x112634u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x114320u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114320_0x114320(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112638u; }
    }
    if (ctx->pc != 0x112638u) { return; }
    ctx->pc = 0x112638u;
    // 0x112638: 0xae00000c
    ctx->pc = 0x112638u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 0));
    // 0x11263c: 0xae000008
    ctx->pc = 0x11263cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
label_112640:
    // 0x112640: 0x32240001
    ctx->pc = 0x112640u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 17), 1));
    // 0x112644: 0x324500ff
    ctx->pc = 0x112644u;
    SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 18), 255));
    // 0x112648: 0x32660001
    ctx->pc = 0x112648u;
    SET_GPR_U32(ctx, 6, AND32(GPR_U32(ctx, 19), 1));
    // 0x11264c: 0xdfbf0040
    ctx->pc = 0x11264cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x112650: 0xdfb30030
    ctx->pc = 0x112650u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x112654: 0xdfb20020
    ctx->pc = 0x112654u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x112658: 0xdfb10010
    ctx->pc = 0x112658u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11265c: 0xdfb00000
    ctx->pc = 0x11265cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x112660: 0x8045088
    ctx->pc = 0x112660u;
    ctx->pc = 0x112664u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
    ctx->pc = 0x114220u;
    entry_114220_0x114240(rdram, ctx, runtime); return;
    ctx->pc = 0x112668u;
label_112668:
    // 0x112668: 0x3c021200
    ctx->pc = 0x112668u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4608 << 16));
    // 0x11266c: 0x24030100
    ctx->pc = 0x11266cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 256));
    // 0x112670: 0x34421000
    ctx->pc = 0x112670u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 4096));
    // 0x112674: 0xfc430000
    ctx->pc = 0x112674u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 3));
    // 0x112678: 0x10000019
    ctx->pc = 0x112678u;
    {
        const bool branch_taken_0x112678 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x11267Cu;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
        if (branch_taken_0x112678) {
            ctx->pc = 0x1126E0u;
            goto label_1126e0;
        }
    }
    ctx->pc = 0x112680u;
label_112680:
    // 0x112680: 0xc0449be
    ctx->pc = 0x112680u;
    SET_GPR_U32(ctx, 31, 0x112688u);
    ctx->pc = 0x1126F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001126F8_0x1126f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112688u; }
    }
    if (ctx->pc != 0x112688u) { return; }
    ctx->pc = 0x112688u;
    // 0x112688: 0x3c031200
    ctx->pc = 0x112688u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4608 << 16));
    // 0x11268c: 0x40802d
    ctx->pc = 0x11268cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x112690: 0x34631000
    ctx->pc = 0x112690u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 4096));
    // 0x112694: 0x13302b
    ctx->pc = 0x112694u;
    SET_GPR_U32(ctx, 6, SLTU32(GPR_U32(ctx, 0), GPR_U32(ctx, 19)));
    // 0x112698: 0xdc620000
    ctx->pc = 0x112698u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x11269c: 0x32240001
    ctx->pc = 0x11269cu;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 17), 1));
    // 0x1126a0: 0xa6060004
    ctx->pc = 0x1126a0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 4), (uint16_t)GPR_U32(ctx, 6));
    // 0x1126a4: 0x324500ff
    ctx->pc = 0x1126a4u;
    SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 18), 255));
    // 0x1126a8: 0x2143a
    ctx->pc = 0x1126a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 16);
    // 0x1126ac: 0xa6110000
    ctx->pc = 0x1126acu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 17));
    // 0x1126b0: 0x304200ff
    ctx->pc = 0x1126b0u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 255));
    // 0x1126b4: 0xa6120002
    ctx->pc = 0x1126b4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 18));
    // 0x1126b8: 0x3042ffff
    ctx->pc = 0x1126b8u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 65535));
    // 0x1126bc: 0x32660001
    ctx->pc = 0x1126bcu;
    SET_GPR_U32(ctx, 6, AND32(GPR_U32(ctx, 19), 1));
    // 0x1126c0: 0xa6020006
    ctx->pc = 0x1126c0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 6), (uint16_t)GPR_U32(ctx, 2));
    // 0x1126c4: 0xdfbf0040
    ctx->pc = 0x1126c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1126c8: 0xdfb30030
    ctx->pc = 0x1126c8u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1126cc: 0xdfb20020
    ctx->pc = 0x1126ccu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1126d0: 0xdfb10010
    ctx->pc = 0x1126d0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1126d4: 0xdfb00000
    ctx->pc = 0x1126d4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1126d8: 0x8045088
    ctx->pc = 0x1126D8u;
    ctx->pc = 0x1126DCu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
    ctx->pc = 0x114220u;
    entry_114220_0x114240(rdram, ctx, runtime); return;
    ctx->pc = 0x1126E0u;
label_1126e0:
    // 0x1126e0: 0xdfb30030
    ctx->pc = 0x1126e0u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_1126e4:
    // 0x1126e4: 0xdfb20020
    ctx->pc = 0x1126e4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1126e8: 0xdfb10010
    ctx->pc = 0x1126e8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1126ec: 0xdfb00000
    ctx->pc = 0x1126ecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1126f0: 0x3e00008
    ctx->pc = 0x1126F0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1126F4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1125C4u: goto label_1125c4;
            case 0x1125D4u: goto label_1125d4;
            case 0x112640u: goto label_112640;
            case 0x112668u: goto label_112668;
            case 0x112680u: goto label_112680;
            case 0x1126E0u: goto label_1126e0;
            case 0x1126E4u: goto label_1126e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1126F8u;
}
