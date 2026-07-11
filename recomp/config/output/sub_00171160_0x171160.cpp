#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00171160
// Address: 0x171160 - 0x171478
void sub_00171160_0x171160(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x171160u;

    // 0x171160: 0x27bdffc0
    ctx->pc = 0x171160u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x171164: 0xffb00000
    ctx->pc = 0x171164u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x171168: 0x80802d
    ctx->pc = 0x171168u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x17116c: 0xffb20010
    ctx->pc = 0x17116cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x171170: 0xffb30018
    ctx->pc = 0x171170u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x171174: 0xffb40020
    ctx->pc = 0x171174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x171178: 0xffb50028
    ctx->pc = 0x171178u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x17117c: 0xffb60030
    ctx->pc = 0x17117cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x171180: 0xffb10008
    ctx->pc = 0x171180u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x171184: 0xffbf0038
    ctx->pc = 0x171184u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x171188: 0xc045198
    ctx->pc = 0x171188u;
    SET_GPR_U32(ctx, 31, 0x171190u);
    ctx->pc = 0x17118Cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 64)));
    ctx->pc = 0x114660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171190u; }
    }
    if (ctx->pc != 0x171190u) { return; }
    ctx->pc = 0x171190u;
    // 0x171190: 0x8e040038
    ctx->pc = 0x171190u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 56)));
    // 0x171194: 0x8e09001c
    ctx->pc = 0x171194u;
    SET_GPR_U32(ctx, 9, READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x171198: 0x41202
    ctx->pc = 0x171198u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 4), 8));
    // 0x17119c: 0x41c02
    ctx->pc = 0x17119cu;
    SET_GPR_U32(ctx, 3, SRL32(GPR_U32(ctx, 4), 16));
    // 0x1711a0: 0x3042000f
    ctx->pc = 0x1711a0u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 15));
    // 0x1711a4: 0x30630003
    ctx->pc = 0x1711a4u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), 3));
    // 0x1711a8: 0x621821
    ctx->pc = 0x1711a8u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1711ac: 0x8e070000
    ctx->pc = 0x1711acu;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1711b0: 0x31100
    ctx->pc = 0x1711b0u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 3), 4));
    // 0x1711b4: 0x8e050024
    ctx->pc = 0x1711b4u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x1711b8: 0x1229023
    ctx->pc = 0x1711b8u;
    SET_GPR_U32(ctx, 18, SUB32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
    // 0x1711bc: 0x8e0a0028
    ctx->pc = 0x1711bcu;
    SET_GPR_U32(ctx, 10, READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x1711c0: 0x247102b
    ctx->pc = 0x1711c0u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 18), GPR_U32(ctx, 7)));
    // 0x1711c4: 0xa3a821
    ctx->pc = 0x1711c4u;
    SET_GPR_U32(ctx, 21, ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x1711c8: 0x3096007f
    ctx->pc = 0x1711c8u;
    SET_GPR_U32(ctx, 22, AND32(GPR_U32(ctx, 4), 127));
    // 0x1711cc: 0x8e140020
    ctx->pc = 0x1711ccu;
    SET_GPR_U32(ctx, 20, READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x1711d0: 0x1040002b
    ctx->pc = 0x1711D0u;
    {
        const bool branch_taken_0x1711d0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1711D4u;
        SET_GPR_U32(ctx, 19, OR32(GPR_U32(ctx, 10), 256));
        if (branch_taken_0x1711d0) {
            ctx->pc = 0x171280u;
            goto label_171280;
        }
    }
    ctx->pc = 0x1711D8u;
    // 0x1711d8: 0x8e060008
    ctx->pc = 0x1711d8u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1711dc: 0x3c020fff
    ctx->pc = 0x1711dcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4095 << 16));
    // 0x1711e0: 0x8e030004
    ctx->pc = 0x1711e0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1711e4: 0xf22023
    ctx->pc = 0x1711e4u;
    SET_GPR_U32(ctx, 4, SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 18)));
    // 0x1711e8: 0x642c0
    ctx->pc = 0x1711e8u;
    SET_GPR_U32(ctx, 8, SLL32(GPR_U32(ctx, 6), 11));
    // 0x1711ec: 0x3442ffff
    ctx->pc = 0x1711ecu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65535));
    // 0x1711f0: 0x62a024
    ctx->pc = 0x1711f0u;
    SET_GPR_U32(ctx, 20, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1711f4: 0x4a902
    ctx->pc = 0x1711f4u;
    SET_GPR_U32(ctx, 21, SRL32(GPR_U32(ctx, 4), 4));
    // 0x1711f8: 0x11270004
    ctx->pc = 0x1711F8u;
    {
        const bool branch_taken_0x1711f8 = (GPR_U32(ctx, 9) == GPR_U32(ctx, 7));
        ctx->pc = 0x1711FCu;
        SET_GPR_U32(ctx, 18, ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 8)));
        if (branch_taken_0x1711f8) {
            ctx->pc = 0x17120Cu;
            goto label_17120c;
        }
    }
    ctx->pc = 0x171200u;
    // 0x171200: 0xe81021
    ctx->pc = 0x171200u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
    // 0x171204: 0x15220002
    ctx->pc = 0x171204u;
    {
        const bool branch_taken_0x171204 = (GPR_U32(ctx, 9) != GPR_U32(ctx, 2));
        ctx->pc = 0x171208u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x171204) {
            ctx->pc = 0x171210u;
            goto label_171210;
        }
    }
    ctx->pc = 0x17120Cu;
label_17120c:
    // 0x17120c: 0x202d
    ctx->pc = 0x17120cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_171210:
    // 0x171210: 0x8e03000c
    ctx->pc = 0x171210u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x171214: 0x3c020fff
    ctx->pc = 0x171214u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4095 << 16));
    // 0x171218: 0x3442ffff
    ctx->pc = 0x171218u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65535));
    // 0x17121c: 0x42700
    ctx->pc = 0x17121cu;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 28));
    // 0x171220: 0xc31823
    ctx->pc = 0x171220u;
    SET_GPR_U32(ctx, 3, SUB32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
    // 0x171224: 0x1421024
    ctx->pc = 0x171224u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 10), GPR_U32(ctx, 2)));
    // 0x171228: 0x66001a
    ctx->pc = 0x171228u;
    { int32_t divisor = GPR_S32(ctx, 6);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint32_t)(dividend / divisor);            ctx->hi = (uint32_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1 : -1; ctx->hi = dividend;    } }
    // 0x17122c: 0x441025
    ctx->pc = 0x17122cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x171230: 0x34530100
    ctx->pc = 0x171230u;
    SET_GPR_U32(ctx, 19, OR32(GPR_U32(ctx, 2), 256));
    // 0x171234: 0x50c00001
    ctx->pc = 0x171234u;
    {
        const bool branch_taken_0x171234 = (GPR_U32(ctx, 6) == GPR_U32(ctx, 0));
        if (branch_taken_0x171234) {
            ctx->pc = 0x171238u;
            runtime->handleBreak(rdram, ctx);
            ctx->pc = 0x17123Cu;
            goto label_17123c;
        }
    }
    ctx->pc = 0x17123Cu;
label_17123c:
    // 0x17123c: 0x2810
    ctx->pc = 0x17123cu;
    SET_GPR_U32(ctx, 5, ctx->hi);
    // 0x171240: 0x4a20009
    ctx->pc = 0x171240u;
    {
        const bool branch_taken_0x171240 = (GPR_S32(ctx, 5) < 0);
        if (branch_taken_0x171240) {
            ctx->pc = 0x171244u;
            SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 16)));
            ctx->pc = 0x171268u;
            goto label_171268;
        }
    }
    ctx->pc = 0x171248u;
    // 0x171248: 0x50c00001
    ctx->pc = 0x171248u;
    {
        const bool branch_taken_0x171248 = (GPR_U32(ctx, 6) == GPR_U32(ctx, 0));
        if (branch_taken_0x171248) {
            ctx->pc = 0x17124Cu;
            runtime->handleBreak(rdram, ctx);
            ctx->pc = 0x171250u;
            goto label_171250;
        }
    }
    ctx->pc = 0x171250u;
label_171250:
    // 0x171250: 0x8e030010
    ctx->pc = 0x171250u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x171254: 0xa3102a
    ctx->pc = 0x171254u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 5), GPR_S32(ctx, 3)));
    // 0x171258: 0x54400043
    ctx->pc = 0x171258u;
    {
        const bool branch_taken_0x171258 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x171258) {
            ctx->pc = 0x17125Cu;
            SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 44)));
            ctx->pc = 0x171368u;
            goto label_171368;
        }
    }
    ctx->pc = 0x171260u;
    // 0x171260: 0x10000002
    ctx->pc = 0x171260u;
    {
        const bool branch_taken_0x171260 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x171264u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 6), 4294967295));
        if (branch_taken_0x171260) {
            ctx->pc = 0x17126Cu;
            goto label_17126c;
        }
    }
    ctx->pc = 0x171268u;
label_171268:
    // 0x171268: 0x24c2ffff
    ctx->pc = 0x171268u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 6), 4294967295));
label_17126c:
    // 0x17126c: 0x24630001
    ctx->pc = 0x17126cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 1));
    // 0x171270: 0xae02000c
    ctx->pc = 0x171270u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 2));
    // 0x171274: 0x1000003b
    ctx->pc = 0x171274u;
    {
        const bool branch_taken_0x171274 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x171278u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 3));
        if (branch_taken_0x171274) {
            ctx->pc = 0x171364u;
            goto label_171364;
        }
    }
    ctx->pc = 0x17127Cu;
    // 0x17127c: 0x0
    ctx->pc = 0x17127cu;
    // NOP
label_171280:
    // 0x171280: 0x120282d
    ctx->pc = 0x171280u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171284: 0xc05c268
    ctx->pc = 0x171284u;
    SET_GPR_U32(ctx, 31, 0x17128Cu);
    ctx->pc = 0x171288u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1709A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001709A0_0x1709a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17128Cu; }
    }
    if (ctx->pc != 0x17128Cu) { return; }
    ctx->pc = 0x17128Cu;
    // 0x17128c: 0x200202d
    ctx->pc = 0x17128cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171290: 0x240282d
    ctx->pc = 0x171290u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x171294: 0xc05c268
    ctx->pc = 0x171294u;
    SET_GPR_U32(ctx, 31, 0x17129Cu);
    ctx->pc = 0x171298u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1709A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001709A0_0x1709a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17129Cu; }
    }
    if (ctx->pc != 0x17129Cu) { return; }
    ctx->pc = 0x17129Cu;
    // 0x17129c: 0x40702d
    ctx->pc = 0x17129cu;
    SET_GPR_U64(ctx, 14, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1712a0: 0x122e0030
    ctx->pc = 0x1712A0u;
    {
        const bool branch_taken_0x1712a0 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 14));
        ctx->pc = 0x1712A4u;
        SET_GPR_U32(ctx, 9, ((uint32_t)4095 << 16));
        if (branch_taken_0x1712a0) {
            ctx->pc = 0x171364u;
            goto label_171364;
        }
    }
    ctx->pc = 0x1712A8u;
    // 0x1712a8: 0x8e0c0008
    ctx->pc = 0x1712a8u;
    SET_GPR_U32(ctx, 12, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x1712ac: 0x8e080000
    ctx->pc = 0x1712acu;
    SET_GPR_U32(ctx, 8, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1712b0: 0x240b0003
    ctx->pc = 0x1712b0u;
    SET_GPR_S32(ctx, 11, ADD32(GPR_U32(ctx, 0), 3));
    // 0x1712b4: 0x8e02001c
    ctx->pc = 0x1712b4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x1712b8: 0xc1ac0
    ctx->pc = 0x1712b8u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 12), 11));
    // 0x1712bc: 0x50600001
    ctx->pc = 0x1712BCu;
    {
        const bool branch_taken_0x1712bc = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        if (branch_taken_0x1712bc) {
            ctx->pc = 0x1712C0u;
            runtime->handleBreak(rdram, ctx);
            ctx->pc = 0x1712C4u;
            goto label_1712c4;
        }
    }
    ctx->pc = 0x1712C4u;
label_1712c4:
    // 0x1712c4: 0x8e04000c
    ctx->pc = 0x1712c4u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x1712c8: 0x481023
    ctx->pc = 0x1712c8u;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 8)));
    // 0x1712cc: 0x8e0d0010
    ctx->pc = 0x1712ccu;
    SET_GPR_U32(ctx, 13, READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x1712d0: 0x43001b
    ctx->pc = 0x1712d0u;
    { uint32_t divisor = GPR_U32(ctx, 3); if (divisor != 0) { ctx->lo = GPR_U32(ctx, 2) / divisor; ctx->hi = GPR_U32(ctx, 3) % divisor; } else { ctx->lo = 0xFFFFFFFF; ctx->hi = GPR_U32(ctx,2); } }
    // 0x1712d4: 0x111ac0
    ctx->pc = 0x1712d4u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 17), 11));
    // 0x1712d8: 0x8d1021
    ctx->pc = 0x1712d8u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 13)));
    // 0x1712dc: 0x1cc2821
    ctx->pc = 0x1712dcu;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 14), GPR_U32(ctx, 12)));
    // 0x1712e0: 0xa42823
    ctx->pc = 0x1712e0u;
    SET_GPR_U32(ctx, 5, SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x1712e4: 0x1031821
    ctx->pc = 0x1712e4u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 3)));
    // 0x1712e8: 0x8e040028
    ctx->pc = 0x1712e8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x1712ec: 0x8e0a0004
    ctx->pc = 0x1712ecu;
    SET_GPR_U32(ctx, 10, READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1712f0: 0x3529ffff
    ctx->pc = 0x1712f0u;
    SET_GPR_U32(ctx, 9, OR32(GPR_U32(ctx, 9), 65535));
    // 0x1712f4: 0x892024
    ctx->pc = 0x1712f4u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 4), GPR_U32(ctx, 9)));
    // 0x1712f8: 0x721823
    ctx->pc = 0x1712f8u;
    SET_GPR_U32(ctx, 3, SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 18)));
    // 0x1712fc: 0x3a902
    ctx->pc = 0x1712fcu;
    SET_GPR_U32(ctx, 21, SRL32(GPR_U32(ctx, 3), 4));
    // 0x171300: 0x3010
    ctx->pc = 0x171300u;
    SET_GPR_U32(ctx, 6, ctx->hi);
    // 0x171304: 0x4c001a
    ctx->pc = 0x171304u;
    { int32_t divisor = GPR_S32(ctx, 12);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint32_t)(dividend / divisor);            ctx->hi = (uint32_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1 : -1; ctx->hi = dividend;    } }
    // 0x171308: 0x1063021
    ctx->pc = 0x171308u;
    SET_GPR_U32(ctx, 6, ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 6)));
    // 0x17130c: 0x111100
    ctx->pc = 0x17130cu;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 17), 4));
    // 0x171310: 0x4a1021
    ctx->pc = 0x171310u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x171314: 0x49a024
    ctx->pc = 0x171314u;
    SET_GPR_U32(ctx, 20, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x171318: 0x3810
    ctx->pc = 0x171318u;
    SET_GPR_U32(ctx, 7, ctx->hi);
    // 0x17131c: 0xac001a
    ctx->pc = 0x17131cu;
    { int32_t divisor = GPR_S32(ctx, 12);    int32_t dividend = GPR_S32(ctx, 5);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint32_t)(dividend / divisor);            ctx->hi = (uint32_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1 : -1; ctx->hi = dividend;    } }
    // 0x171320: 0x73ac0
    ctx->pc = 0x171320u;
    SET_GPR_U32(ctx, 7, SLL32(GPR_U32(ctx, 7), 11));
    // 0x171324: 0x1074021
    ctx->pc = 0x171324u;
    SET_GPR_U32(ctx, 8, ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 7)));
    // 0x171328: 0xc83026
    ctx->pc = 0x171328u;
    SET_GPR_U32(ctx, 6, XOR32(GPR_U32(ctx, 6), GPR_U32(ctx, 8)));
    // 0x17132c: 0x6580a
    ctx->pc = 0x17132cu;
    if (GPR_U32(ctx, 6) == 0) SET_GPR_U32(ctx, 11, GPR_U32(ctx, 0));
    // 0x171330: 0xb5f00
    ctx->pc = 0x171330u;
    SET_GPR_U32(ctx, 11, SLL32(GPR_U32(ctx, 11), 28));
    // 0x171334: 0x8b2025
    ctx->pc = 0x171334u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
    // 0x171338: 0x1010
    ctx->pc = 0x171338u;
    SET_GPR_U32(ctx, 2, ctx->hi);
    // 0x17133c: 0x4400006
    ctx->pc = 0x17133Cu;
    {
        const bool branch_taken_0x17133c = (GPR_S32(ctx, 2) < 0);
        ctx->pc = 0x171340u;
        SET_GPR_U32(ctx, 19, OR32(GPR_U32(ctx, 4), 256));
        if (branch_taken_0x17133c) {
            ctx->pc = 0x171358u;
            goto label_171358;
        }
    }
    ctx->pc = 0x171344u;
    // 0x171344: 0x4d102a
    ctx->pc = 0x171344u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 2), GPR_S32(ctx, 13)));
    // 0x171348: 0x51800001
    ctx->pc = 0x171348u;
    {
        const bool branch_taken_0x171348 = (GPR_U32(ctx, 12) == GPR_U32(ctx, 0));
        if (branch_taken_0x171348) {
            ctx->pc = 0x17134Cu;
            runtime->handleBreak(rdram, ctx);
            ctx->pc = 0x171350u;
            goto label_171350;
        }
    }
    ctx->pc = 0x171350u;
label_171350:
    // 0x171350: 0x54400005
    ctx->pc = 0x171350u;
    {
        const bool branch_taken_0x171350 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x171350) {
            ctx->pc = 0x171354u;
            SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 44)));
            ctx->pc = 0x171368u;
            goto label_171368;
        }
    }
    ctx->pc = 0x171358u;
label_171358:
    // 0x171358: 0x25a20001
    ctx->pc = 0x171358u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 13), 1));
    // 0x17135c: 0xae0e000c
    ctx->pc = 0x17135cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 12), GPR_U32(ctx, 14));
    // 0x171360: 0xae020010
    ctx->pc = 0x171360u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 16), GPR_U32(ctx, 2));
label_171364:
    // 0x171364: 0x8e03002c
    ctx->pc = 0x171364u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 44)));
label_171368:
    // 0x171368: 0x5060000e
    ctx->pc = 0x171368u;
    {
        const bool branch_taken_0x171368 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        if (branch_taken_0x171368) {
            ctx->pc = 0x17136Cu;
            SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
            ctx->pc = 0x1713A4u;
            goto label_1713a4;
        }
    }
    ctx->pc = 0x171370u;
    // 0x171370: 0x8e020030
    ctx->pc = 0x171370u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x171374: 0x1040000a
    ctx->pc = 0x171374u;
    {
        const bool branch_taken_0x171374 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x171378u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x171374) {
            ctx->pc = 0x1713A0u;
            goto label_1713a0;
        }
    }
    ctx->pc = 0x17137Cu;
    // 0x17137c: 0x3c041000
    ctx->pc = 0x17137cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x171380: 0x3442b010
    ctx->pc = 0x171380u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 45072));
    // 0x171384: 0x3484b020
    ctx->pc = 0x171384u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 45088));
    // 0x171388: 0xac430000
    ctx->pc = 0x171388u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x17138c: 0x8e030030
    ctx->pc = 0x17138cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 48)));
    // 0x171390: 0xac830000
    ctx->pc = 0x171390u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x171394: 0x8e040034
    ctx->pc = 0x171394u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 52)));
    // 0x171398: 0xc05c27c
    ctx->pc = 0x171398u;
    SET_GPR_U32(ctx, 31, 0x1713A0u);
    ctx->pc = 0x17139Cu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 256));
    ctx->pc = 0x1709F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001709F0_0x1709f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1713A0u; }
    }
    if (ctx->pc != 0x1713A0u) { return; }
    ctx->pc = 0x1713A0u;
label_1713a0:
    // 0x1713a0: 0x3c031000
    ctx->pc = 0x1713a0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
label_1713a4:
    // 0x1713a4: 0x34632010
    ctx->pc = 0x1713a4u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 8208));
label_1713a8:
    // 0x1713a8: 0x8c620000
    ctx->pc = 0x1713a8u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x1713ac: 0x0
    ctx->pc = 0x1713acu;
    // NOP
    // 0x1713b0: 0x0
    ctx->pc = 0x1713b0u;
    // NOP
    // 0x1713b4: 0x0
    ctx->pc = 0x1713b4u;
    // NOP
    // 0x1713b8: 0x0
    ctx->pc = 0x1713b8u;
    // NOP
    // 0x1713bc: 0x440fffa
    ctx->pc = 0x1713BCu;
    {
        const bool branch_taken_0x1713bc = (GPR_S32(ctx, 2) < 0);
        ctx->pc = 0x1713C0u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x1713bc) {
            ctx->pc = 0x1713A8u;
            goto label_1713a8;
        }
    }
    ctx->pc = 0x1713C4u;
    // 0x1713c4: 0x3c031000
    ctx->pc = 0x1713c4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1713c8: 0x34422000
    ctx->pc = 0x1713c8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8192));
    // 0x1713cc: 0x34632010
    ctx->pc = 0x1713ccu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 8208));
    // 0x1713d0: 0xac560000
    ctx->pc = 0x1713d0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 22)); // MMIO: 0x10000000
    // 0x1713d4: 0x0
    ctx->pc = 0x1713d4u;
    // NOP
label_1713d8:
    // 0x1713d8: 0x8c620000
    ctx->pc = 0x1713d8u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x1713dc: 0x0
    ctx->pc = 0x1713dcu;
    // NOP
    // 0x1713e0: 0x0
    ctx->pc = 0x1713e0u;
    // NOP
    // 0x1713e4: 0x0
    ctx->pc = 0x1713e4u;
    // NOP
    // 0x1713e8: 0x0
    ctx->pc = 0x1713e8u;
    // NOP
    // 0x1713ec: 0x440fffa
    ctx->pc = 0x1713ECu;
    {
        const bool branch_taken_0x1713ec = (GPR_S32(ctx, 2) < 0);
        ctx->pc = 0x1713F0u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x1713ec) {
            ctx->pc = 0x1713D8u;
            goto label_1713d8;
        }
    }
    ctx->pc = 0x1713F4u;
    // 0x1713f4: 0x3c031000
    ctx->pc = 0x1713f4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x1713f8: 0x3c041000
    ctx->pc = 0x1713f8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x1713fc: 0x3442b410
    ctx->pc = 0x1713fcu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 46096));
    // 0x171400: 0x3463b430
    ctx->pc = 0x171400u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 46128));
    // 0x171404: 0x3484b420
    ctx->pc = 0x171404u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 46112));
    // 0x171408: 0xac520000
    ctx->pc = 0x171408u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 18));
    // 0x17140c: 0xac740000
    ctx->pc = 0x17140cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 20));
    // 0x171410: 0xac950000
    ctx->pc = 0x171410u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 21));
    // 0x171414: 0x8e020010
    ctx->pc = 0x171414u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x171418: 0x50400004
    ctx->pc = 0x171418u;
    {
        const bool branch_taken_0x171418 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x171418) {
            ctx->pc = 0x17141Cu;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 60)));
            ctx->pc = 0x17142Cu;
            goto label_17142c;
        }
    }
    ctx->pc = 0x171420u;
    // 0x171420: 0xc05c296
    ctx->pc = 0x171420u;
    SET_GPR_U32(ctx, 31, 0x171428u);
    ctx->pc = 0x171424u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x170A58u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00170A58_0x170a58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171428u; }
    }
    if (ctx->pc != 0x171428u) { return; }
    ctx->pc = 0x171428u;
    // 0x171428: 0x8e02003c
    ctx->pc = 0x171428u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 60)));
label_17142c:
    // 0x17142c: 0x3c031000
    ctx->pc = 0x17142cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x171430: 0x34632010
    ctx->pc = 0x171430u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 8208));
    // 0x171434: 0x24040001
    ctx->pc = 0x171434u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    // 0x171438: 0xac620000
    ctx->pc = 0x171438u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2)); // MMIO: 0x10000000
    // 0x17143c: 0xae040044
    ctx->pc = 0x17143cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 68), GPR_U32(ctx, 4));
    // 0x171440: 0xc045190
    ctx->pc = 0x171440u;
    SET_GPR_U32(ctx, 31, 0x171448u);
    ctx->pc = 0x171444u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 64)));
    ctx->pc = 0x114640u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171448u; }
    }
    if (ctx->pc != 0x171448u) { return; }
    ctx->pc = 0x171448u;
    // 0x171448: 0x24020001
    ctx->pc = 0x171448u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x17144c: 0xdfb00000
    ctx->pc = 0x17144cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x171450: 0xdfb10008
    ctx->pc = 0x171450u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x171454: 0xdfb20010
    ctx->pc = 0x171454u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x171458: 0xdfb30018
    ctx->pc = 0x171458u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x17145c: 0xdfb40020
    ctx->pc = 0x17145cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x171460: 0xdfb50028
    ctx->pc = 0x171460u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x171464: 0xdfb60030
    ctx->pc = 0x171464u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x171468: 0xdfbf0038
    ctx->pc = 0x171468u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x17146c: 0x3e00008
    ctx->pc = 0x17146Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x171470u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x17120Cu: goto label_17120c;
            case 0x171210u: goto label_171210;
            case 0x17123Cu: goto label_17123c;
            case 0x171250u: goto label_171250;
            case 0x171268u: goto label_171268;
            case 0x17126Cu: goto label_17126c;
            case 0x171280u: goto label_171280;
            case 0x1712C4u: goto label_1712c4;
            case 0x171350u: goto label_171350;
            case 0x171358u: goto label_171358;
            case 0x171364u: goto label_171364;
            case 0x171368u: goto label_171368;
            case 0x1713A0u: goto label_1713a0;
            case 0x1713A4u: goto label_1713a4;
            case 0x1713A8u: goto label_1713a8;
            case 0x1713D8u: goto label_1713d8;
            case 0x17142Cu: goto label_17142c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x171474u;
    // 0x171474: 0x0
    ctx->pc = 0x171474u;
    // NOP
}
