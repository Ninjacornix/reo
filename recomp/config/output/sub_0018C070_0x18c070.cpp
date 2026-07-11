#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0018C070
// Address: 0x18c070 - 0x18c4a0
void sub_0018C070_0x18c070(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x18c070u;

label_18c070:
    // 0x18c070: 0x27bdffd0
    ctx->pc = 0x18c070u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
label_18c074:
    // 0x18c074: 0xffbf0020
    ctx->pc = 0x18c074u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
label_18c078:
    // 0x18c078: 0x7fb10010
    ctx->pc = 0x18c078u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
label_18c07c:
    // 0x18c07c: 0x7fb00000
    ctx->pc = 0x18c07cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
label_18c080:
    // 0x18c080: 0x80882d
    ctx->pc = 0x18c080u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_18c084:
    // 0x18c084: 0x8c900020
    ctx->pc = 0x18c084u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 4), 32)));
label_18c088:
    // 0x18c088: 0xc063728
label_18c08c:
    if (ctx->pc == 0x18C08Cu) {
        ctx->pc = 0x18C08Cu;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 28)));
        ctx->pc = 0x18C090u;
        goto label_18c090;
    }
    ctx->pc = 0x18C088u;
    SET_GPR_U32(ctx, 31, 0x18C090u);
    ctx->pc = 0x18C08Cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 28)));
    ctx->pc = 0x18DCA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C090u; }
    }
    if (ctx->pc != 0x18C090u) { return; }
    ctx->pc = 0x18C090u;
label_18c090:
    // 0x18c090: 0xae220020
    ctx->pc = 0x18c090u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 32), GPR_U32(ctx, 2));
label_18c094:
    // 0x18c094: 0x202d
    ctx->pc = 0x18c094u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18c098:
    // 0x18c098: 0x8e23002c
    ctx->pc = 0x18c098u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 44)));
label_18c09c:
    // 0x18c09c: 0x3c061000
    ctx->pc = 0x18c09cu;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
label_18c0a0:
    // 0x18c0a0: 0x8e250024
    ctx->pc = 0x18c0a0u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 17), 36)));
label_18c0a4:
    // 0x18c0a4: 0x3c072000
    ctx->pc = 0x18c0a4u;
    SET_GPR_U32(ctx, 7, ((uint32_t)8192 << 16));
label_18c0a8:
    // 0x18c0a8: 0x3c097000
    ctx->pc = 0x18c0a8u;
    SET_GPR_U32(ctx, 9, ((uint32_t)28672 << 16));
label_18c0ac:
    // 0x18c0ac: 0x3c086000
    ctx->pc = 0x18c0acu;
    SET_GPR_U32(ctx, 8, ((uint32_t)24576 << 16));
label_18c0b0:
    // 0x18c0b0: 0x431821
    ctx->pc = 0x18c0b0u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_18c0b4:
    // 0x18c0b4: 0x10000023
label_18c0b8:
    if (ctx->pc == 0x18C0B8u) {
        ctx->pc = 0x18C0B8u;
        SET_GPR_U32(ctx, 13, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
        ctx->pc = 0x18C0BCu;
        goto label_18c0bc;
    }
    ctx->pc = 0x18C0B4u;
    {
        const bool branch_taken_0x18c0b4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18C0B8u;
        SET_GPR_U32(ctx, 13, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
        if (branch_taken_0x18c0b4) {
            ctx->pc = 0x18C144u;
            goto label_18c144;
        }
    }
    ctx->pc = 0x18C0BCu;
label_18c0bc:
    // 0x18c0bc: 0x8c650000
    ctx->pc = 0x18c0bcu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_18c0c0:
    // 0x18c0c0: 0x456021
    ctx->pc = 0x18c0c0u;
    SET_GPR_U32(ctx, 12, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
label_18c0c4:
    // 0x18c0c4: 0xadac0004
    ctx->pc = 0x18c0c4u;
    WRITE32(ADD32(GPR_U32(ctx, 13), 4), GPR_U32(ctx, 12));
label_18c0c8:
    // 0x18c0c8: 0x180502d
    ctx->pc = 0x18c0c8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 12) + (uint64_t)GPR_U64(ctx, 0));
label_18c0cc:
    // 0x18c0cc: 0x95a50000
    ctx->pc = 0x18c0ccu;
    SET_GPR_U32(ctx, 5, (uint16_t)READ16(ADD32(GPR_U32(ctx, 13), 0)));
label_18c0d0:
    // 0x18c0d0: 0x24a50001
    ctx->pc = 0x18c0d0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 1));
label_18c0d4:
    // 0x18c0d4: 0x52900
    ctx->pc = 0x18c0d4u;
    SET_GPR_U32(ctx, 5, SLL32(GPR_U32(ctx, 5), 4));
label_18c0d8:
    // 0x18c0d8: 0x1a56821
    ctx->pc = 0x18c0d8u;
    SET_GPR_U32(ctx, 13, ADD32(GPR_U32(ctx, 13), GPR_U32(ctx, 5)));
label_18c0dc:
    // 0x18c0dc: 0x8d4b0000
    ctx->pc = 0x18c0dcu;
    SET_GPR_U32(ctx, 11, READ32(ADD32(GPR_U32(ctx, 10), 0)));
label_18c0e0:
    // 0x18c0e0: 0x1692824
    ctx->pc = 0x18c0e0u;
    SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 11), GPR_U32(ctx, 9)));
label_18c0e4:
    // 0x18c0e4: 0x10a80012
label_18c0e8:
    if (ctx->pc == 0x18C0E8u) {
        ctx->pc = 0x18C0ECu;
        goto label_18c0ec;
    }
    ctx->pc = 0x18C0E4u;
    {
        const bool branch_taken_0x18c0e4 = (GPR_U32(ctx, 5) == GPR_U32(ctx, 8));
        if (branch_taken_0x18c0e4) {
            ctx->pc = 0x18C130u;
            goto label_18c130;
        }
    }
    ctx->pc = 0x18C0ECu;
label_18c0ec:
    // 0x18c0ec: 0x10a7000a
label_18c0f0:
    if (ctx->pc == 0x18C0F0u) {
        ctx->pc = 0x18C0F4u;
        goto label_18c0f4;
    }
    ctx->pc = 0x18C0ECu;
    {
        const bool branch_taken_0x18c0ec = (GPR_U32(ctx, 5) == GPR_U32(ctx, 7));
        if (branch_taken_0x18c0ec) {
            ctx->pc = 0x18C118u;
            goto label_18c118;
        }
    }
    ctx->pc = 0x18C0F4u;
label_18c0f4:
    // 0x18c0f4: 0x10a60003
label_18c0f8:
    if (ctx->pc == 0x18C0F8u) {
        ctx->pc = 0x18C0FCu;
        goto label_18c0fc;
    }
    ctx->pc = 0x18C0F4u;
    {
        const bool branch_taken_0x18c0f4 = (GPR_U32(ctx, 5) == GPR_U32(ctx, 6));
        if (branch_taken_0x18c0f4) {
            ctx->pc = 0x18C104u;
            goto label_18c104;
        }
    }
    ctx->pc = 0x18C0FCu;
label_18c0fc:
    // 0x18c0fc: 0x1000000d
label_18c100:
    if (ctx->pc == 0x18C100u) {
        ctx->pc = 0x18C104u;
        goto label_18c104;
    }
    ctx->pc = 0x18C0FCu;
    {
        const bool branch_taken_0x18c0fc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x18c0fc) {
            ctx->pc = 0x18C134u;
            goto label_18c134;
        }
    }
    ctx->pc = 0x18C104u;
label_18c104:
    // 0x18c104: 0x3165ffff
    ctx->pc = 0x18c104u;
    SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 11), 65535));
label_18c108:
    // 0x18c108: 0x24a50001
    ctx->pc = 0x18c108u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 1));
label_18c10c:
    // 0x18c10c: 0x52900
    ctx->pc = 0x18c10cu;
    SET_GPR_U32(ctx, 5, SLL32(GPR_U32(ctx, 5), 4));
label_18c110:
    // 0x18c110: 0x10000008
label_18c114:
    if (ctx->pc == 0x18C114u) {
        ctx->pc = 0x18C114u;
        SET_GPR_U32(ctx, 10, ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 5)));
        ctx->pc = 0x18C118u;
        goto label_18c118;
    }
    ctx->pc = 0x18C110u;
    {
        const bool branch_taken_0x18c110 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18C114u;
        SET_GPR_U32(ctx, 10, ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 5)));
        if (branch_taken_0x18c110) {
            ctx->pc = 0x18C134u;
            goto label_18c134;
        }
    }
    ctx->pc = 0x18C118u;
label_18c118:
    // 0x18c118: 0x8d450004
    ctx->pc = 0x18c118u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 10), 4)));
label_18c11c:
    // 0x18c11c: 0xb02823
    ctx->pc = 0x18c11cu;
    SET_GPR_U32(ctx, 5, SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 16)));
label_18c120:
    // 0x18c120: 0xa22821
    ctx->pc = 0x18c120u;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
label_18c124:
    // 0x18c124: 0xad450004
    ctx->pc = 0x18c124u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 4), GPR_U32(ctx, 5));
label_18c128:
    // 0x18c128: 0x10000002
label_18c12c:
    if (ctx->pc == 0x18C12Cu) {
        ctx->pc = 0x18C12Cu;
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18C130u;
        goto label_18c130;
    }
    ctx->pc = 0x18C128u;
    {
        const bool branch_taken_0x18c128 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18C12Cu;
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x18c128) {
            ctx->pc = 0x18C134u;
            goto label_18c134;
        }
    }
    ctx->pc = 0x18C130u;
label_18c130:
    // 0x18c130: 0x602d
    ctx->pc = 0x18c130u;
    SET_GPR_U64(ctx, 12, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18c134:
    // 0x18c134: 0x1580ffe9
label_18c138:
    if (ctx->pc == 0x18C138u) {
        ctx->pc = 0x18C13Cu;
        goto label_18c13c;
    }
    ctx->pc = 0x18C134u;
    {
        const bool branch_taken_0x18c134 = (GPR_U32(ctx, 12) != GPR_U32(ctx, 0));
        if (branch_taken_0x18c134) {
            ctx->pc = 0x18C0DCu;
            goto label_18c0dc;
        }
    }
    ctx->pc = 0x18C13Cu;
label_18c13c:
    // 0x18c13c: 0x24630004
    ctx->pc = 0x18c13cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4));
label_18c140:
    // 0x18c140: 0x24840001
    ctx->pc = 0x18c140u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 1));
label_18c144:
    // 0x18c144: 0x8e250034
    ctx->pc = 0x18c144u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 17), 52)));
label_18c148:
    // 0x18c148: 0x85282b
    ctx->pc = 0x18c148u;
    SET_GPR_U32(ctx, 5, SLTU32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
label_18c14c:
    // 0x18c14c: 0x14a0ffdb
label_18c150:
    if (ctx->pc == 0x18C150u) {
        ctx->pc = 0x18C154u;
        goto label_18c154;
    }
    ctx->pc = 0x18C14Cu;
    {
        const bool branch_taken_0x18c14c = (GPR_U32(ctx, 5) != GPR_U32(ctx, 0));
        if (branch_taken_0x18c14c) {
            ctx->pc = 0x18C0BCu;
            goto label_18c0bc;
        }
    }
    ctx->pc = 0x18C154u;
label_18c154:
    // 0x18c154: 0xdfbf0020
    ctx->pc = 0x18c154u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_18c158:
    // 0x18c158: 0x7bb10010
    ctx->pc = 0x18c158u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
label_18c15c:
    // 0x18c15c: 0x7bb00000
    ctx->pc = 0x18c15cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
label_18c160:
    // 0x18c160: 0x3e00008
label_18c164:
    if (ctx->pc == 0x18C164u) {
        ctx->pc = 0x18C164u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = 0x18C168u;
        goto label_18c168;
    }
    ctx->pc = 0x18C160u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18C164u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18C070u: goto label_18c070;
            case 0x18C074u: goto label_18c074;
            case 0x18C078u: goto label_18c078;
            case 0x18C07Cu: goto label_18c07c;
            case 0x18C080u: goto label_18c080;
            case 0x18C084u: goto label_18c084;
            case 0x18C088u: goto label_18c088;
            case 0x18C08Cu: goto label_18c08c;
            case 0x18C090u: goto label_18c090;
            case 0x18C094u: goto label_18c094;
            case 0x18C098u: goto label_18c098;
            case 0x18C09Cu: goto label_18c09c;
            case 0x18C0A0u: goto label_18c0a0;
            case 0x18C0A4u: goto label_18c0a4;
            case 0x18C0A8u: goto label_18c0a8;
            case 0x18C0ACu: goto label_18c0ac;
            case 0x18C0B0u: goto label_18c0b0;
            case 0x18C0B4u: goto label_18c0b4;
            case 0x18C0B8u: goto label_18c0b8;
            case 0x18C0BCu: goto label_18c0bc;
            case 0x18C0C0u: goto label_18c0c0;
            case 0x18C0C4u: goto label_18c0c4;
            case 0x18C0C8u: goto label_18c0c8;
            case 0x18C0CCu: goto label_18c0cc;
            case 0x18C0D0u: goto label_18c0d0;
            case 0x18C0D4u: goto label_18c0d4;
            case 0x18C0D8u: goto label_18c0d8;
            case 0x18C0DCu: goto label_18c0dc;
            case 0x18C0E0u: goto label_18c0e0;
            case 0x18C0E4u: goto label_18c0e4;
            case 0x18C0E8u: goto label_18c0e8;
            case 0x18C0ECu: goto label_18c0ec;
            case 0x18C0F0u: goto label_18c0f0;
            case 0x18C0F4u: goto label_18c0f4;
            case 0x18C0F8u: goto label_18c0f8;
            case 0x18C0FCu: goto label_18c0fc;
            case 0x18C100u: goto label_18c100;
            case 0x18C104u: goto label_18c104;
            case 0x18C108u: goto label_18c108;
            case 0x18C10Cu: goto label_18c10c;
            case 0x18C110u: goto label_18c110;
            case 0x18C114u: goto label_18c114;
            case 0x18C118u: goto label_18c118;
            case 0x18C11Cu: goto label_18c11c;
            case 0x18C120u: goto label_18c120;
            case 0x18C124u: goto label_18c124;
            case 0x18C128u: goto label_18c128;
            case 0x18C12Cu: goto label_18c12c;
            case 0x18C130u: goto label_18c130;
            case 0x18C134u: goto label_18c134;
            case 0x18C138u: goto label_18c138;
            case 0x18C13Cu: goto label_18c13c;
            case 0x18C140u: goto label_18c140;
            case 0x18C144u: goto label_18c144;
            case 0x18C148u: goto label_18c148;
            case 0x18C14Cu: goto label_18c14c;
            case 0x18C150u: goto label_18c150;
            case 0x18C154u: goto label_18c154;
            case 0x18C158u: goto label_18c158;
            case 0x18C15Cu: goto label_18c15c;
            case 0x18C160u: goto label_18c160;
            case 0x18C164u: goto label_18c164;
            case 0x18C168u: goto label_18c168;
            case 0x18C16Cu: goto label_18c16c;
            case 0x18C170u: goto label_18c170;
            case 0x18C174u: goto label_18c174;
            case 0x18C178u: goto label_18c178;
            case 0x18C17Cu: goto label_18c17c;
            case 0x18C180u: goto label_18c180;
            case 0x18C184u: goto label_18c184;
            case 0x18C188u: goto label_18c188;
            case 0x18C18Cu: goto label_18c18c;
            case 0x18C190u: goto label_18c190;
            case 0x18C194u: goto label_18c194;
            case 0x18C198u: goto label_18c198;
            case 0x18C19Cu: goto label_18c19c;
            case 0x18C1A0u: goto label_18c1a0;
            case 0x18C1A4u: goto label_18c1a4;
            case 0x18C1A8u: goto label_18c1a8;
            case 0x18C1ACu: goto label_18c1ac;
            case 0x18C1B0u: goto label_18c1b0;
            case 0x18C1B4u: goto label_18c1b4;
            case 0x18C1B8u: goto label_18c1b8;
            case 0x18C1BCu: goto label_18c1bc;
            case 0x18C1C0u: goto label_18c1c0;
            case 0x18C1C4u: goto label_18c1c4;
            case 0x18C1C8u: goto label_18c1c8;
            case 0x18C1CCu: goto label_18c1cc;
            case 0x18C1D0u: goto label_18c1d0;
            case 0x18C1D4u: goto label_18c1d4;
            case 0x18C1D8u: goto label_18c1d8;
            case 0x18C1DCu: goto label_18c1dc;
            case 0x18C1E0u: goto label_18c1e0;
            case 0x18C1E4u: goto label_18c1e4;
            case 0x18C1E8u: goto label_18c1e8;
            case 0x18C1ECu: goto label_18c1ec;
            case 0x18C1F0u: goto label_18c1f0;
            case 0x18C1F4u: goto label_18c1f4;
            case 0x18C1F8u: goto label_18c1f8;
            case 0x18C1FCu: goto label_18c1fc;
            case 0x18C200u: goto label_18c200;
            case 0x18C204u: goto label_18c204;
            case 0x18C208u: goto label_18c208;
            case 0x18C20Cu: goto label_18c20c;
            case 0x18C210u: goto label_18c210;
            case 0x18C214u: goto label_18c214;
            case 0x18C218u: goto label_18c218;
            case 0x18C21Cu: goto label_18c21c;
            case 0x18C220u: goto label_18c220;
            case 0x18C224u: goto label_18c224;
            case 0x18C228u: goto label_18c228;
            case 0x18C22Cu: goto label_18c22c;
            case 0x18C230u: goto label_18c230;
            case 0x18C234u: goto label_18c234;
            case 0x18C238u: goto label_18c238;
            case 0x18C23Cu: goto label_18c23c;
            case 0x18C240u: goto label_18c240;
            case 0x18C244u: goto label_18c244;
            case 0x18C248u: goto label_18c248;
            case 0x18C24Cu: goto label_18c24c;
            case 0x18C250u: goto label_18c250;
            case 0x18C254u: goto label_18c254;
            case 0x18C258u: goto label_18c258;
            case 0x18C25Cu: goto label_18c25c;
            case 0x18C260u: goto label_18c260;
            case 0x18C264u: goto label_18c264;
            case 0x18C268u: goto label_18c268;
            case 0x18C26Cu: goto label_18c26c;
            case 0x18C270u: goto label_18c270;
            case 0x18C274u: goto label_18c274;
            case 0x18C278u: goto label_18c278;
            case 0x18C27Cu: goto label_18c27c;
            case 0x18C280u: goto label_18c280;
            case 0x18C284u: goto label_18c284;
            case 0x18C288u: goto label_18c288;
            case 0x18C28Cu: goto label_18c28c;
            case 0x18C290u: goto label_18c290;
            case 0x18C294u: goto label_18c294;
            case 0x18C298u: goto label_18c298;
            case 0x18C29Cu: goto label_18c29c;
            case 0x18C2A0u: goto label_18c2a0;
            case 0x18C2A4u: goto label_18c2a4;
            case 0x18C2A8u: goto label_18c2a8;
            case 0x18C2ACu: goto label_18c2ac;
            case 0x18C2B0u: goto label_18c2b0;
            case 0x18C2B4u: goto label_18c2b4;
            case 0x18C2B8u: goto label_18c2b8;
            case 0x18C2BCu: goto label_18c2bc;
            case 0x18C2C0u: goto label_18c2c0;
            case 0x18C2C4u: goto label_18c2c4;
            case 0x18C2C8u: goto label_18c2c8;
            case 0x18C2CCu: goto label_18c2cc;
            case 0x18C2D0u: goto label_18c2d0;
            case 0x18C2D4u: goto label_18c2d4;
            case 0x18C2D8u: goto label_18c2d8;
            case 0x18C2DCu: goto label_18c2dc;
            case 0x18C2E0u: goto label_18c2e0;
            case 0x18C2E4u: goto label_18c2e4;
            case 0x18C2E8u: goto label_18c2e8;
            case 0x18C2ECu: goto label_18c2ec;
            case 0x18C2F0u: goto label_18c2f0;
            case 0x18C2F4u: goto label_18c2f4;
            case 0x18C2F8u: goto label_18c2f8;
            case 0x18C2FCu: goto label_18c2fc;
            case 0x18C300u: goto label_18c300;
            case 0x18C304u: goto label_18c304;
            case 0x18C308u: goto label_18c308;
            case 0x18C30Cu: goto label_18c30c;
            case 0x18C310u: goto label_18c310;
            case 0x18C314u: goto label_18c314;
            case 0x18C318u: goto label_18c318;
            case 0x18C31Cu: goto label_18c31c;
            case 0x18C320u: goto label_18c320;
            case 0x18C324u: goto label_18c324;
            case 0x18C328u: goto label_18c328;
            case 0x18C32Cu: goto label_18c32c;
            case 0x18C330u: goto label_18c330;
            case 0x18C334u: goto label_18c334;
            case 0x18C338u: goto label_18c338;
            case 0x18C33Cu: goto label_18c33c;
            case 0x18C340u: goto label_18c340;
            case 0x18C344u: goto label_18c344;
            case 0x18C348u: goto label_18c348;
            case 0x18C34Cu: goto label_18c34c;
            case 0x18C350u: goto label_18c350;
            case 0x18C354u: goto label_18c354;
            case 0x18C358u: goto label_18c358;
            case 0x18C35Cu: goto label_18c35c;
            case 0x18C360u: goto label_18c360;
            case 0x18C364u: goto label_18c364;
            case 0x18C368u: goto label_18c368;
            case 0x18C36Cu: goto label_18c36c;
            case 0x18C370u: goto label_18c370;
            case 0x18C374u: goto label_18c374;
            case 0x18C378u: goto label_18c378;
            case 0x18C37Cu: goto label_18c37c;
            case 0x18C380u: goto label_18c380;
            case 0x18C384u: goto label_18c384;
            case 0x18C388u: goto label_18c388;
            case 0x18C38Cu: goto label_18c38c;
            case 0x18C390u: goto label_18c390;
            case 0x18C394u: goto label_18c394;
            case 0x18C398u: goto label_18c398;
            case 0x18C39Cu: goto label_18c39c;
            case 0x18C3A0u: goto label_18c3a0;
            case 0x18C3A4u: goto label_18c3a4;
            case 0x18C3A8u: goto label_18c3a8;
            case 0x18C3ACu: goto label_18c3ac;
            case 0x18C3B0u: goto label_18c3b0;
            case 0x18C3B4u: goto label_18c3b4;
            case 0x18C3B8u: goto label_18c3b8;
            case 0x18C3BCu: goto label_18c3bc;
            case 0x18C3C0u: goto label_18c3c0;
            case 0x18C3C4u: goto label_18c3c4;
            case 0x18C3C8u: goto label_18c3c8;
            case 0x18C3CCu: goto label_18c3cc;
            case 0x18C3D0u: goto label_18c3d0;
            case 0x18C3D4u: goto label_18c3d4;
            case 0x18C3D8u: goto label_18c3d8;
            case 0x18C3DCu: goto label_18c3dc;
            case 0x18C3E0u: goto label_18c3e0;
            case 0x18C3E4u: goto label_18c3e4;
            case 0x18C3E8u: goto label_18c3e8;
            case 0x18C3ECu: goto label_18c3ec;
            case 0x18C3F0u: goto label_18c3f0;
            case 0x18C3F4u: goto label_18c3f4;
            case 0x18C3F8u: goto label_18c3f8;
            case 0x18C3FCu: goto label_18c3fc;
            case 0x18C400u: goto label_18c400;
            case 0x18C404u: goto label_18c404;
            case 0x18C408u: goto label_18c408;
            case 0x18C40Cu: goto label_18c40c;
            case 0x18C410u: goto label_18c410;
            case 0x18C414u: goto label_18c414;
            case 0x18C418u: goto label_18c418;
            case 0x18C41Cu: goto label_18c41c;
            case 0x18C420u: goto label_18c420;
            case 0x18C424u: goto label_18c424;
            case 0x18C428u: goto label_18c428;
            case 0x18C42Cu: goto label_18c42c;
            case 0x18C430u: goto label_18c430;
            case 0x18C434u: goto label_18c434;
            case 0x18C438u: goto label_18c438;
            case 0x18C43Cu: goto label_18c43c;
            case 0x18C440u: goto label_18c440;
            case 0x18C444u: goto label_18c444;
            case 0x18C448u: goto label_18c448;
            case 0x18C44Cu: goto label_18c44c;
            case 0x18C450u: goto label_18c450;
            case 0x18C454u: goto label_18c454;
            case 0x18C458u: goto label_18c458;
            case 0x18C45Cu: goto label_18c45c;
            case 0x18C460u: goto label_18c460;
            case 0x18C464u: goto label_18c464;
            case 0x18C468u: goto label_18c468;
            case 0x18C46Cu: goto label_18c46c;
            case 0x18C470u: goto label_18c470;
            case 0x18C474u: goto label_18c474;
            case 0x18C478u: goto label_18c478;
            case 0x18C47Cu: goto label_18c47c;
            case 0x18C480u: goto label_18c480;
            case 0x18C484u: goto label_18c484;
            case 0x18C488u: goto label_18c488;
            case 0x18C48Cu: goto label_18c48c;
            case 0x18C490u: goto label_18c490;
            case 0x18C494u: goto label_18c494;
            case 0x18C498u: goto label_18c498;
            case 0x18C49Cu: goto label_18c49c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18C168u;
label_18c168:
    // 0x18c168: 0x0
    ctx->pc = 0x18c168u;
    // NOP
label_18c16c:
    // 0x18c16c: 0x0
    ctx->pc = 0x18c16cu;
    // NOP
label_18c170:
    // 0x18c170: 0x27bdff90
    ctx->pc = 0x18c170u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967184));
label_18c174:
    // 0x18c174: 0x2484ffff
    ctx->pc = 0x18c174u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294967295));
label_18c178:
    // 0x18c178: 0xffbf0030
    ctx->pc = 0x18c178u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
label_18c17c:
    // 0x18c17c: 0x41040
    ctx->pc = 0x18c17cu;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 4), 1));
label_18c180:
    // 0x18c180: 0x7fb20020
    ctx->pc = 0x18c180u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
label_18c184:
    // 0x18c184: 0x442021
    ctx->pc = 0x18c184u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_18c188:
    // 0x18c188: 0x7fb10010
    ctx->pc = 0x18c188u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
label_18c18c:
    // 0x18c18c: 0x3c010029
    ctx->pc = 0x18c18cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
label_18c190:
    // 0x18c190: 0x7fb00000
    ctx->pc = 0x18c190u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
label_18c194:
    // 0x18c194: 0x421c0
    ctx->pc = 0x18c194u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 7));
label_18c198:
    // 0x18c198: 0x8c2341a0
    ctx->pc = 0x18c198u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 16800)));
label_18c19c:
    // 0x18c19c: 0x3c01002a
    ctx->pc = 0x18c19cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
label_18c1a0:
    // 0x18c1a0: 0x649021
    ctx->pc = 0x18c1a0u;
    SET_GPR_U32(ctx, 18, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
label_18c1a4:
    // 0x18c1a4: 0x8c22fda4
    ctx->pc = 0x18c1a4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 4294966692)));
label_18c1a8:
    // 0x18c1a8: 0x10400003
label_18c1ac:
    if (ctx->pc == 0x18C1ACu) {
        ctx->pc = 0x18C1ACu;
        SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 18), 32)));
        ctx->pc = 0x18C1B0u;
        goto label_18c1b0;
    }
    ctx->pc = 0x18C1A8u;
    {
        const bool branch_taken_0x18c1a8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x18C1ACu;
        SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 18), 32)));
        if (branch_taken_0x18c1a8) {
            ctx->pc = 0x18C1B8u;
            goto label_18c1b8;
        }
    }
    ctx->pc = 0x18C1B0u;
label_18c1b0:
    // 0x18c1b0: 0x100000b2
label_18c1b4:
    if (ctx->pc == 0x18C1B4u) {
        ctx->pc = 0x18C1B4u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x18C1B8u;
        goto label_18c1b8;
    }
    ctx->pc = 0x18C1B0u;
    {
        const bool branch_taken_0x18c1b0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18C1B4u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x18c1b0) {
            ctx->pc = 0x18C47Cu;
            goto label_18c47c;
        }
    }
    ctx->pc = 0x18C1B8u;
label_18c1b8:
    // 0x18c1b8: 0x8e440000
    ctx->pc = 0x18c1b8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_18c1bc:
    // 0x18c1bc: 0x30820004
    ctx->pc = 0x18c1bcu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), 4));
label_18c1c0:
    // 0x18c1c0: 0x14400040
label_18c1c4:
    if (ctx->pc == 0x18C1C4u) {
        ctx->pc = 0x18C1C4u;
        SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), 2));
        ctx->pc = 0x18C1C8u;
        goto label_18c1c8;
    }
    ctx->pc = 0x18C1C0u;
    {
        const bool branch_taken_0x18c1c0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x18C1C4u;
        SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), 2));
        if (branch_taken_0x18c1c0) {
            ctx->pc = 0x18C2C4u;
            goto label_18c2c4;
        }
    }
    ctx->pc = 0x18C1C8u;
label_18c1c8:
    // 0x18c1c8: 0x3c01002a
    ctx->pc = 0x18c1c8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
label_18c1cc:
    // 0x18c1cc: 0x8e43000c
    ctx->pc = 0x18c1ccu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 12)));
label_18c1d0:
    // 0x18c1d0: 0x8c22fe70
    ctx->pc = 0x18c1d0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
label_18c1d4:
    // 0x18c1d4: 0x1062001b
label_18c1d8:
    if (ctx->pc == 0x18C1D8u) {
        ctx->pc = 0x18C1D8u;
        SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), 2));
        ctx->pc = 0x18C1DCu;
        goto label_18c1dc;
    }
    ctx->pc = 0x18C1D4u;
    {
        const bool branch_taken_0x18c1d4 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x18C1D8u;
        SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), 2));
        if (branch_taken_0x18c1d4) {
            ctx->pc = 0x18C244u;
            goto label_18c244;
        }
    }
    ctx->pc = 0x18C1DCu;
label_18c1dc:
    // 0x18c1dc: 0xc0635b0
label_18c1e0:
    if (ctx->pc == 0x18C1E0u) {
        ctx->pc = 0x18C1E4u;
        goto label_18c1e4;
    }
    ctx->pc = 0x18C1DCu;
    SET_GPR_U32(ctx, 31, 0x18C1E4u);
    ctx->pc = 0x18D6C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018D6C0_0x18d6c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C1E4u; }
    }
    if (ctx->pc != 0x18C1E4u) { return; }
    ctx->pc = 0x18C1E4u;
label_18c1e4:
    // 0x18c1e4: 0x3c01002a
    ctx->pc = 0x18c1e4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
label_18c1e8:
    // 0x18c1e8: 0x8c22fe70
    ctx->pc = 0x18c1e8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 4294966896)));
label_18c1ec:
    // 0x18c1ec: 0xae42000c
    ctx->pc = 0x18c1ecu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 12), GPR_U32(ctx, 2));
label_18c1f0:
    // 0x18c1f0: 0x8e44001c
    ctx->pc = 0x18c1f0u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 18), 28)));
label_18c1f4:
    // 0x18c1f4: 0x10800003
label_18c1f8:
    if (ctx->pc == 0x18C1F8u) {
        ctx->pc = 0x18C1FCu;
        goto label_18c1fc;
    }
    ctx->pc = 0x18C1F4u;
    {
        const bool branch_taken_0x18c1f4 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        if (branch_taken_0x18c1f4) {
            ctx->pc = 0x18C204u;
            goto label_18c204;
        }
    }
    ctx->pc = 0x18C1FCu;
label_18c1fc:
    // 0x18c1fc: 0xc063724
label_18c200:
    if (ctx->pc == 0x18C200u) {
        ctx->pc = 0x18C204u;
        goto label_18c204;
    }
    ctx->pc = 0x18C1FCu;
    SET_GPR_U32(ctx, 31, 0x18C204u);
    ctx->pc = 0x18DC90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC90_0x18dc90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C204u; }
    }
    if (ctx->pc != 0x18C204u) { return; }
    ctx->pc = 0x18C204u;
label_18c204:
    // 0x18c204: 0x240202d
    ctx->pc = 0x18c204u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_18c208:
    // 0x18c208: 0xc0627b4
label_18c20c:
    if (ctx->pc == 0x18C20Cu) {
        ctx->pc = 0x18C20Cu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = 0x18C210u;
        goto label_18c210;
    }
    ctx->pc = 0x18C208u;
    SET_GPR_U32(ctx, 31, 0x18C210u);
    ctx->pc = 0x18C20Cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 64));
    ctx->pc = 0x189ED0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00189ED0_0x189ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C210u; }
    }
    if (ctx->pc != 0x18C210u) { return; }
    ctx->pc = 0x18C210u;
label_18c210:
    // 0x18c210: 0x240202d
    ctx->pc = 0x18c210u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_18c214:
    // 0x18c214: 0xc062784
label_18c218:
    if (ctx->pc == 0x18C218u) {
        ctx->pc = 0x18C218u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = 0x18C21Cu;
        goto label_18c21c;
    }
    ctx->pc = 0x18C214u;
    SET_GPR_U32(ctx, 31, 0x18C21Cu);
    ctx->pc = 0x18C218u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 64));
    ctx->pc = 0x189E10u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00189E10_0x189e10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C21Cu; }
    }
    if (ctx->pc != 0x18C21Cu) { return; }
    ctx->pc = 0x18C21Cu;
label_18c21c:
    // 0x18c21c: 0x14400003
label_18c220:
    if (ctx->pc == 0x18C220u) {
        ctx->pc = 0x18C224u;
        goto label_18c224;
    }
    ctx->pc = 0x18C21Cu;
    {
        const bool branch_taken_0x18c21c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x18c21c) {
            ctx->pc = 0x18C22Cu;
            goto label_18c22c;
        }
    }
    ctx->pc = 0x18C224u;
label_18c224:
    // 0x18c224: 0x10000095
label_18c228:
    if (ctx->pc == 0x18C228u) {
        ctx->pc = 0x18C228u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18C22Cu;
        goto label_18c22c;
    }
    ctx->pc = 0x18C224u;
    {
        const bool branch_taken_0x18c224 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18C228u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x18c224) {
            ctx->pc = 0x18C47Cu;
            goto label_18c47c;
        }
    }
    ctx->pc = 0x18C22Cu;
label_18c22c:
    // 0x18c22c: 0xc06372c
label_18c230:
    if (ctx->pc == 0x18C230u) {
        ctx->pc = 0x18C234u;
        goto label_18c234;
    }
    ctx->pc = 0x18C22Cu;
    SET_GPR_U32(ctx, 31, 0x18C234u);
    ctx->pc = 0x18DCB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCB0_0x18dcb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C234u; }
    }
    if (ctx->pc != 0x18C234u) { return; }
    ctx->pc = 0x18C234u;
label_18c234:
    // 0x18c234: 0x8e430020
    ctx->pc = 0x18c234u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 32)));
label_18c238:
    // 0x18c238: 0x8e420024
    ctx->pc = 0x18c238u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 36)));
label_18c23c:
    // 0x18c23c: 0x10000014
label_18c240:
    if (ctx->pc == 0x18C240u) {
        ctx->pc = 0x18C240u;
        SET_GPR_U32(ctx, 17, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        ctx->pc = 0x18C244u;
        goto label_18c244;
    }
    ctx->pc = 0x18C23Cu;
    {
        const bool branch_taken_0x18c23c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18C240u;
        SET_GPR_U32(ctx, 17, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
        if (branch_taken_0x18c23c) {
            ctx->pc = 0x18C290u;
            goto label_18c290;
        }
    }
    ctx->pc = 0x18C244u;
label_18c244:
    // 0x18c244: 0x10400004
label_18c248:
    if (ctx->pc == 0x18C248u) {
        ctx->pc = 0x18C24Cu;
        goto label_18c24c;
    }
    ctx->pc = 0x18C244u;
    {
        const bool branch_taken_0x18c244 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x18c244) {
            ctx->pc = 0x18C258u;
            goto label_18c258;
        }
    }
    ctx->pc = 0x18C24Cu;
label_18c24c:
    // 0x18c24c: 0x8e420024
    ctx->pc = 0x18c24cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 36)));
label_18c250:
    // 0x18c250: 0x1000000f
label_18c254:
    if (ctx->pc == 0x18C254u) {
        ctx->pc = 0x18C254u;
        SET_GPR_U32(ctx, 17, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        ctx->pc = 0x18C258u;
        goto label_18c258;
    }
    ctx->pc = 0x18C250u;
    {
        const bool branch_taken_0x18c250 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18C254u;
        SET_GPR_U32(ctx, 17, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
        if (branch_taken_0x18c250) {
            ctx->pc = 0x18C290u;
            goto label_18c290;
        }
    }
    ctx->pc = 0x18C258u;
label_18c258:
    // 0x18c258: 0x8e440028
    ctx->pc = 0x18c258u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 18), 40)));
label_18c25c:
    // 0x18c25c: 0xc063774
label_18c260:
    if (ctx->pc == 0x18C260u) {
        ctx->pc = 0x18C260u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
        ctx->pc = 0x18C264u;
        goto label_18c264;
    }
    ctx->pc = 0x18C25Cu;
    SET_GPR_U32(ctx, 31, 0x18C264u);
    ctx->pc = 0x18C260u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C264u; }
    }
    if (ctx->pc != 0x18C264u) { return; }
    ctx->pc = 0x18C264u;
label_18c264:
    // 0x18c264: 0x40882d
    ctx->pc = 0x18c264u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_18c268:
    // 0x18c268: 0x8e450034
    ctx->pc = 0x18c268u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 18), 52)));
label_18c26c:
    // 0x18c26c: 0x8e42004c
    ctx->pc = 0x18c26cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 76)));
label_18c270:
    // 0x18c270: 0x240202d
    ctx->pc = 0x18c270u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_18c274:
    // 0x18c274: 0x220382d
    ctx->pc = 0x18c274u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_18c278:
    // 0x18c278: 0x8c460014
    ctx->pc = 0x18c278u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 2), 20)));
label_18c27c:
    // 0x18c27c: 0xc062cec
label_18c280:
    if (ctx->pc == 0x18C280u) {
        ctx->pc = 0x18C280u;
        SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 18), 96));
        ctx->pc = 0x18C284u;
        goto label_18c284;
    }
    ctx->pc = 0x18C27Cu;
    SET_GPR_U32(ctx, 31, 0x18C284u);
    ctx->pc = 0x18C280u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 18), 96));
    ctx->pc = 0x18B3B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B3B0_0x18b3b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C284u; }
    }
    if (ctx->pc != 0x18C284u) { return; }
    ctx->pc = 0x18C284u;
label_18c284:
    // 0x18c284: 0x240202d
    ctx->pc = 0x18c284u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_18c288:
    // 0x18c288: 0xc062fd0
label_18c28c:
    if (ctx->pc == 0x18C28Cu) {
        ctx->pc = 0x18C28Cu;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18C290u;
        goto label_18c290;
    }
    ctx->pc = 0x18C288u;
    SET_GPR_U32(ctx, 31, 0x18C290u);
    ctx->pc = 0x18C28Cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18BF40u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BF40_0x18bf40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C290u; }
    }
    if (ctx->pc != 0x18C290u) { return; }
    ctx->pc = 0x18C290u;
label_18c290:
    // 0x18c290: 0x8e440038
    ctx->pc = 0x18c290u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 18), 56)));
label_18c294:
    // 0x18c294: 0x10800037
label_18c298:
    if (ctx->pc == 0x18C298u) {
        ctx->pc = 0x18C298u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 18), 256));
        ctx->pc = 0x18C29Cu;
        goto label_18c29c;
    }
    ctx->pc = 0x18C294u;
    {
        const bool branch_taken_0x18c294 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x18C298u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 18), 256));
        if (branch_taken_0x18c294) {
            ctx->pc = 0x18C374u;
            goto label_18c374;
        }
    }
    ctx->pc = 0x18C29Cu;
label_18c29c:
    // 0x18c29c: 0xc0675cc
label_18c2a0:
    if (ctx->pc == 0x18C2A0u) {
        ctx->pc = 0x18C2A4u;
        goto label_18c2a4;
    }
    ctx->pc = 0x18C29Cu;
    SET_GPR_U32(ctx, 31, 0x18C2A4u);
    ctx->pc = 0x19D730u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D730_0x19d730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C2A4u; }
    }
    if (ctx->pc != 0x18C2A4u) { return; }
    ctx->pc = 0x18C2A4u;
label_18c2a4:
    // 0x18c2a4: 0x8e42004c
    ctx->pc = 0x18c2a4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 76)));
label_18c2a8:
    // 0x18c2a8: 0x220302d
    ctx->pc = 0x18c2a8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_18c2ac:
    // 0x18c2ac: 0x8e440034
    ctx->pc = 0x18c2acu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 18), 52)));
label_18c2b0:
    // 0x18c2b0: 0x8c450014
    ctx->pc = 0x18c2b0u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 2), 20)));
label_18c2b4:
    // 0x18c2b4: 0xc062ea8
label_18c2b8:
    if (ctx->pc == 0x18C2B8u) {
        ctx->pc = 0x18C2B8u;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 18), 128));
        ctx->pc = 0x18C2BCu;
        goto label_18c2bc;
    }
    ctx->pc = 0x18C2B4u;
    SET_GPR_U32(ctx, 31, 0x18C2BCu);
    ctx->pc = 0x18C2B8u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 18), 128));
    ctx->pc = 0x18BAA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BAA0_0x18baa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C2BCu; }
    }
    if (ctx->pc != 0x18C2BCu) { return; }
    ctx->pc = 0x18C2BCu;
label_18c2bc:
    // 0x18c2bc: 0x1000002e
label_18c2c0:
    if (ctx->pc == 0x18C2C0u) {
        ctx->pc = 0x18C2C0u;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 76)));
        ctx->pc = 0x18C2C4u;
        goto label_18c2c4;
    }
    ctx->pc = 0x18C2BCu;
    {
        const bool branch_taken_0x18c2bc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18C2C0u;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 76)));
        if (branch_taken_0x18c2bc) {
            ctx->pc = 0x18C378u;
            goto label_18c378;
        }
    }
    ctx->pc = 0x18C2C4u;
label_18c2c4:
    // 0x18c2c4: 0x10400018
label_18c2c8:
    if (ctx->pc == 0x18C2C8u) {
        ctx->pc = 0x18C2CCu;
        goto label_18c2cc;
    }
    ctx->pc = 0x18C2C4u;
    {
        const bool branch_taken_0x18c2c4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x18c2c4) {
            ctx->pc = 0x18C328u;
            goto label_18c328;
        }
    }
    ctx->pc = 0x18C2CCu;
label_18c2cc:
    // 0x18c2cc: 0x8e440028
    ctx->pc = 0x18c2ccu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 18), 40)));
label_18c2d0:
    // 0x18c2d0: 0xc063774
label_18c2d4:
    if (ctx->pc == 0x18C2D4u) {
        ctx->pc = 0x18C2D4u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
        ctx->pc = 0x18C2D8u;
        goto label_18c2d8;
    }
    ctx->pc = 0x18C2D0u;
    SET_GPR_U32(ctx, 31, 0x18C2D8u);
    ctx->pc = 0x18C2D4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C2D8u; }
    }
    if (ctx->pc != 0x18C2D8u) { return; }
    ctx->pc = 0x18C2D8u;
label_18c2d8:
    // 0x18c2d8: 0x40882d
    ctx->pc = 0x18c2d8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_18c2dc:
    // 0x18c2dc: 0x8e430024
    ctx->pc = 0x18c2dcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 36)));
label_18c2e0:
    // 0x18c2e0: 0x8e420028
    ctx->pc = 0x18c2e0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 40)));
label_18c2e4:
    // 0x18c2e4: 0x220282d
    ctx->pc = 0x18c2e4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_18c2e8:
    // 0x18c2e8: 0x2032021
    ctx->pc = 0x18c2e8u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
label_18c2ec:
    // 0x18c2ec: 0xc0626c2
label_18c2f0:
    if (ctx->pc == 0x18C2F0u) {
        ctx->pc = 0x18C2F0u;
        SET_GPR_U32(ctx, 6, SRL32(GPR_U32(ctx, 2), 4));
        ctx->pc = 0x18C2F4u;
        goto label_18c2f4;
    }
    ctx->pc = 0x18C2ECu;
    SET_GPR_U32(ctx, 31, 0x18C2F4u);
    ctx->pc = 0x18C2F0u;
    SET_GPR_U32(ctx, 6, SRL32(GPR_U32(ctx, 2), 4));
    ctx->pc = 0x189B08u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00189B08_0x189b08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C2F4u; }
    }
    if (ctx->pc != 0x18C2F4u) { return; }
    ctx->pc = 0x18C2F4u;
label_18c2f4:
    // 0x18c2f4: 0x8e440038
    ctx->pc = 0x18c2f4u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 18), 56)));
label_18c2f8:
    // 0x18c2f8: 0x1080001e
label_18c2fc:
    if (ctx->pc == 0x18C2FCu) {
        ctx->pc = 0x18C2FCu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 18), 256));
        ctx->pc = 0x18C300u;
        goto label_18c300;
    }
    ctx->pc = 0x18C2F8u;
    {
        const bool branch_taken_0x18c2f8 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x18C2FCu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 18), 256));
        if (branch_taken_0x18c2f8) {
            ctx->pc = 0x18C374u;
            goto label_18c374;
        }
    }
    ctx->pc = 0x18C300u;
label_18c300:
    // 0x18c300: 0xc0675cc
label_18c304:
    if (ctx->pc == 0x18C304u) {
        ctx->pc = 0x18C308u;
        goto label_18c308;
    }
    ctx->pc = 0x18C300u;
    SET_GPR_U32(ctx, 31, 0x18C308u);
    ctx->pc = 0x19D730u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D730_0x19d730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C308u; }
    }
    if (ctx->pc != 0x18C308u) { return; }
    ctx->pc = 0x18C308u;
label_18c308:
    // 0x18c308: 0x8e42004c
    ctx->pc = 0x18c308u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 76)));
label_18c30c:
    // 0x18c30c: 0x220302d
    ctx->pc = 0x18c30cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_18c310:
    // 0x18c310: 0x8e440034
    ctx->pc = 0x18c310u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 18), 52)));
label_18c314:
    // 0x18c314: 0x8c450014
    ctx->pc = 0x18c314u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 2), 20)));
label_18c318:
    // 0x18c318: 0xc062ea8
label_18c31c:
    if (ctx->pc == 0x18C31Cu) {
        ctx->pc = 0x18C31Cu;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 18), 128));
        ctx->pc = 0x18C320u;
        goto label_18c320;
    }
    ctx->pc = 0x18C318u;
    SET_GPR_U32(ctx, 31, 0x18C320u);
    ctx->pc = 0x18C31Cu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 18), 128));
    ctx->pc = 0x18BAA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BAA0_0x18baa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C320u; }
    }
    if (ctx->pc != 0x18C320u) { return; }
    ctx->pc = 0x18C320u;
label_18c320:
    // 0x18c320: 0x10000014
label_18c324:
    if (ctx->pc == 0x18C324u) {
        ctx->pc = 0x18C328u;
        goto label_18c328;
    }
    ctx->pc = 0x18C320u;
    {
        const bool branch_taken_0x18c320 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x18c320) {
            ctx->pc = 0x18C374u;
            goto label_18c374;
        }
    }
    ctx->pc = 0x18C328u;
label_18c328:
    // 0x18c328: 0x8e440028
    ctx->pc = 0x18c328u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 18), 40)));
label_18c32c:
    // 0x18c32c: 0xc063774
label_18c330:
    if (ctx->pc == 0x18C330u) {
        ctx->pc = 0x18C330u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
        ctx->pc = 0x18C334u;
        goto label_18c334;
    }
    ctx->pc = 0x18C32Cu;
    SET_GPR_U32(ctx, 31, 0x18C334u);
    ctx->pc = 0x18C330u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C334u; }
    }
    if (ctx->pc != 0x18C334u) { return; }
    ctx->pc = 0x18C334u;
label_18c334:
    // 0x18c334: 0x240202d
    ctx->pc = 0x18c334u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_18c338:
    // 0x18c338: 0x282d
    ctx->pc = 0x18c338u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18c33c:
    // 0x18c33c: 0xc062fd0
label_18c340:
    if (ctx->pc == 0x18C340u) {
        ctx->pc = 0x18C340u;
        SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18C344u;
        goto label_18c344;
    }
    ctx->pc = 0x18C33Cu;
    SET_GPR_U32(ctx, 31, 0x18C344u);
    ctx->pc = 0x18C340u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18BF40u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018BF40_0x18bf40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C344u; }
    }
    if (ctx->pc != 0x18C344u) { return; }
    ctx->pc = 0x18C344u;
label_18c344:
    // 0x18c344: 0x8e440038
    ctx->pc = 0x18c344u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 18), 56)));
label_18c348:
    // 0x18c348: 0x10800003
label_18c34c:
    if (ctx->pc == 0x18C34Cu) {
        ctx->pc = 0x18C34Cu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 18), 256));
        ctx->pc = 0x18C350u;
        goto label_18c350;
    }
    ctx->pc = 0x18C348u;
    {
        const bool branch_taken_0x18c348 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x18C34Cu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 18), 256));
        if (branch_taken_0x18c348) {
            ctx->pc = 0x18C358u;
            goto label_18c358;
        }
    }
    ctx->pc = 0x18C350u;
label_18c350:
    // 0x18c350: 0xc0675cc
label_18c354:
    if (ctx->pc == 0x18C354u) {
        ctx->pc = 0x18C358u;
        goto label_18c358;
    }
    ctx->pc = 0x18C350u;
    SET_GPR_U32(ctx, 31, 0x18C358u);
    ctx->pc = 0x19D730u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D730_0x19d730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C358u; }
    }
    if (ctx->pc != 0x18C358u) { return; }
    ctx->pc = 0x18C358u;
label_18c358:
    // 0x18c358: 0x8e42004c
    ctx->pc = 0x18c358u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 76)));
label_18c35c:
    // 0x18c35c: 0x240202d
    ctx->pc = 0x18c35cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_18c360:
    // 0x18c360: 0x8e450034
    ctx->pc = 0x18c360u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 18), 52)));
label_18c364:
    // 0x18c364: 0x220382d
    ctx->pc = 0x18c364u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_18c368:
    // 0x18c368: 0x8c460014
    ctx->pc = 0x18c368u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 2), 20)));
label_18c36c:
    // 0x18c36c: 0xc062cec
label_18c370:
    if (ctx->pc == 0x18C370u) {
        ctx->pc = 0x18C370u;
        SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 18), 96));
        ctx->pc = 0x18C374u;
        goto label_18c374;
    }
    ctx->pc = 0x18C36Cu;
    SET_GPR_U32(ctx, 31, 0x18C374u);
    ctx->pc = 0x18C370u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 18), 96));
    ctx->pc = 0x18B3B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018B3B0_0x18b3b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C374u; }
    }
    if (ctx->pc != 0x18C374u) { return; }
    ctx->pc = 0x18C374u;
label_18c374:
    // 0x18c374: 0x8e42004c
    ctx->pc = 0x18c374u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 76)));
label_18c378:
    // 0x18c378: 0x3c070023
    ctx->pc = 0x18c378u;
    SET_GPR_U32(ctx, 7, ((uint32_t)35 << 16));
label_18c37c:
    // 0x18c37c: 0x24e7fd40
    ctx->pc = 0x18c37cu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 4294966592));
label_18c380:
    // 0x18c380: 0x8e450034
    ctx->pc = 0x18c380u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 18), 52)));
label_18c384:
    // 0x18c384: 0x3c01002a
    ctx->pc = 0x18c384u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
label_18c388:
    // 0x18c388: 0x240202d
    ctx->pc = 0x18c388u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_18c38c:
    // 0x18c38c: 0x220302d
    ctx->pc = 0x18c38cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_18c390:
    // 0x18c390: 0x8c480014
    ctx->pc = 0x18c390u;
    SET_GPR_U32(ctx, 8, READ32(ADD32(GPR_U32(ctx, 2), 20)));
label_18c394:
    // 0x18c394: 0x8c43000c
    ctx->pc = 0x18c394u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 12)));
label_18c398:
    // 0x18c398: 0x84080
    ctx->pc = 0x18c398u;
    SET_GPR_U32(ctx, 8, SLL32(GPR_U32(ctx, 8), 2));
label_18c39c:
    // 0x18c39c: 0x8c420008
    ctx->pc = 0x18c39cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 8)));
label_18c3a0:
    // 0x18c3a0: 0xe83821
    ctx->pc = 0x18c3a0u;
    SET_GPR_U32(ctx, 7, ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 8)));
label_18c3a4:
    // 0x18c3a4: 0x621023
    ctx->pc = 0x18c3a4u;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_18c3a8:
    // 0x18c3a8: 0x8ce30000
    ctx->pc = 0x18c3a8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 0)));
label_18c3ac:
    // 0x18c3ac: 0x210c2
    ctx->pc = 0x18c3acu;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 3));
label_18c3b0:
    // 0x18c3b0: 0xac22fda0
    ctx->pc = 0x18c3b0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966688), GPR_U32(ctx, 2));
label_18c3b4:
    // 0x18c3b4: 0xa31818
    ctx->pc = 0x18c3b4u;
    { int64_t result = (int64_t)GPR_S32(ctx, 5) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)(uint32_t)result); }
label_18c3b8:
    // 0x18c3b8: 0x8e42004c
    ctx->pc = 0x18c3b8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 76)));
label_18c3bc:
    // 0x18c3bc: 0x2238021
    ctx->pc = 0x18c3bcu;
    SET_GPR_U32(ctx, 16, ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
label_18c3c0:
    // 0x18c3c0: 0x8c450004
    ctx->pc = 0x18c3c0u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 2), 4)));
label_18c3c4:
    // 0x18c3c4: 0x8c430008
    ctx->pc = 0x18c3c4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 8)));
label_18c3c8:
    // 0x18c3c8: 0x8c420010
    ctx->pc = 0x18c3c8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 16)));
label_18c3cc:
    // 0x18c3cc: 0xa31823
    ctx->pc = 0x18c3ccu;
    SET_GPR_U32(ctx, 3, SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
label_18c3d0:
    // 0x18c3d0: 0x40f809
label_18c3d4:
    if (ctx->pc == 0x18C3D4u) {
        ctx->pc = 0x18C3D4u;
        SET_GPR_U32(ctx, 5, SRL32(GPR_U32(ctx, 3), 3));
        ctx->pc = 0x18C3D8u;
        goto label_18c3d8;
    }
    ctx->pc = 0x18C3D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x18C3D8u);
        ctx->pc = 0x18C3D4u;
        SET_GPR_U32(ctx, 5, SRL32(GPR_U32(ctx, 3), 3));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18C070u: goto label_18c070;
            case 0x18C074u: goto label_18c074;
            case 0x18C078u: goto label_18c078;
            case 0x18C07Cu: goto label_18c07c;
            case 0x18C080u: goto label_18c080;
            case 0x18C084u: goto label_18c084;
            case 0x18C088u: goto label_18c088;
            case 0x18C08Cu: goto label_18c08c;
            case 0x18C090u: goto label_18c090;
            case 0x18C094u: goto label_18c094;
            case 0x18C098u: goto label_18c098;
            case 0x18C09Cu: goto label_18c09c;
            case 0x18C0A0u: goto label_18c0a0;
            case 0x18C0A4u: goto label_18c0a4;
            case 0x18C0A8u: goto label_18c0a8;
            case 0x18C0ACu: goto label_18c0ac;
            case 0x18C0B0u: goto label_18c0b0;
            case 0x18C0B4u: goto label_18c0b4;
            case 0x18C0B8u: goto label_18c0b8;
            case 0x18C0BCu: goto label_18c0bc;
            case 0x18C0C0u: goto label_18c0c0;
            case 0x18C0C4u: goto label_18c0c4;
            case 0x18C0C8u: goto label_18c0c8;
            case 0x18C0CCu: goto label_18c0cc;
            case 0x18C0D0u: goto label_18c0d0;
            case 0x18C0D4u: goto label_18c0d4;
            case 0x18C0D8u: goto label_18c0d8;
            case 0x18C0DCu: goto label_18c0dc;
            case 0x18C0E0u: goto label_18c0e0;
            case 0x18C0E4u: goto label_18c0e4;
            case 0x18C0E8u: goto label_18c0e8;
            case 0x18C0ECu: goto label_18c0ec;
            case 0x18C0F0u: goto label_18c0f0;
            case 0x18C0F4u: goto label_18c0f4;
            case 0x18C0F8u: goto label_18c0f8;
            case 0x18C0FCu: goto label_18c0fc;
            case 0x18C100u: goto label_18c100;
            case 0x18C104u: goto label_18c104;
            case 0x18C108u: goto label_18c108;
            case 0x18C10Cu: goto label_18c10c;
            case 0x18C110u: goto label_18c110;
            case 0x18C114u: goto label_18c114;
            case 0x18C118u: goto label_18c118;
            case 0x18C11Cu: goto label_18c11c;
            case 0x18C120u: goto label_18c120;
            case 0x18C124u: goto label_18c124;
            case 0x18C128u: goto label_18c128;
            case 0x18C12Cu: goto label_18c12c;
            case 0x18C130u: goto label_18c130;
            case 0x18C134u: goto label_18c134;
            case 0x18C138u: goto label_18c138;
            case 0x18C13Cu: goto label_18c13c;
            case 0x18C140u: goto label_18c140;
            case 0x18C144u: goto label_18c144;
            case 0x18C148u: goto label_18c148;
            case 0x18C14Cu: goto label_18c14c;
            case 0x18C150u: goto label_18c150;
            case 0x18C154u: goto label_18c154;
            case 0x18C158u: goto label_18c158;
            case 0x18C15Cu: goto label_18c15c;
            case 0x18C160u: goto label_18c160;
            case 0x18C164u: goto label_18c164;
            case 0x18C168u: goto label_18c168;
            case 0x18C16Cu: goto label_18c16c;
            case 0x18C170u: goto label_18c170;
            case 0x18C174u: goto label_18c174;
            case 0x18C178u: goto label_18c178;
            case 0x18C17Cu: goto label_18c17c;
            case 0x18C180u: goto label_18c180;
            case 0x18C184u: goto label_18c184;
            case 0x18C188u: goto label_18c188;
            case 0x18C18Cu: goto label_18c18c;
            case 0x18C190u: goto label_18c190;
            case 0x18C194u: goto label_18c194;
            case 0x18C198u: goto label_18c198;
            case 0x18C19Cu: goto label_18c19c;
            case 0x18C1A0u: goto label_18c1a0;
            case 0x18C1A4u: goto label_18c1a4;
            case 0x18C1A8u: goto label_18c1a8;
            case 0x18C1ACu: goto label_18c1ac;
            case 0x18C1B0u: goto label_18c1b0;
            case 0x18C1B4u: goto label_18c1b4;
            case 0x18C1B8u: goto label_18c1b8;
            case 0x18C1BCu: goto label_18c1bc;
            case 0x18C1C0u: goto label_18c1c0;
            case 0x18C1C4u: goto label_18c1c4;
            case 0x18C1C8u: goto label_18c1c8;
            case 0x18C1CCu: goto label_18c1cc;
            case 0x18C1D0u: goto label_18c1d0;
            case 0x18C1D4u: goto label_18c1d4;
            case 0x18C1D8u: goto label_18c1d8;
            case 0x18C1DCu: goto label_18c1dc;
            case 0x18C1E0u: goto label_18c1e0;
            case 0x18C1E4u: goto label_18c1e4;
            case 0x18C1E8u: goto label_18c1e8;
            case 0x18C1ECu: goto label_18c1ec;
            case 0x18C1F0u: goto label_18c1f0;
            case 0x18C1F4u: goto label_18c1f4;
            case 0x18C1F8u: goto label_18c1f8;
            case 0x18C1FCu: goto label_18c1fc;
            case 0x18C200u: goto label_18c200;
            case 0x18C204u: goto label_18c204;
            case 0x18C208u: goto label_18c208;
            case 0x18C20Cu: goto label_18c20c;
            case 0x18C210u: goto label_18c210;
            case 0x18C214u: goto label_18c214;
            case 0x18C218u: goto label_18c218;
            case 0x18C21Cu: goto label_18c21c;
            case 0x18C220u: goto label_18c220;
            case 0x18C224u: goto label_18c224;
            case 0x18C228u: goto label_18c228;
            case 0x18C22Cu: goto label_18c22c;
            case 0x18C230u: goto label_18c230;
            case 0x18C234u: goto label_18c234;
            case 0x18C238u: goto label_18c238;
            case 0x18C23Cu: goto label_18c23c;
            case 0x18C240u: goto label_18c240;
            case 0x18C244u: goto label_18c244;
            case 0x18C248u: goto label_18c248;
            case 0x18C24Cu: goto label_18c24c;
            case 0x18C250u: goto label_18c250;
            case 0x18C254u: goto label_18c254;
            case 0x18C258u: goto label_18c258;
            case 0x18C25Cu: goto label_18c25c;
            case 0x18C260u: goto label_18c260;
            case 0x18C264u: goto label_18c264;
            case 0x18C268u: goto label_18c268;
            case 0x18C26Cu: goto label_18c26c;
            case 0x18C270u: goto label_18c270;
            case 0x18C274u: goto label_18c274;
            case 0x18C278u: goto label_18c278;
            case 0x18C27Cu: goto label_18c27c;
            case 0x18C280u: goto label_18c280;
            case 0x18C284u: goto label_18c284;
            case 0x18C288u: goto label_18c288;
            case 0x18C28Cu: goto label_18c28c;
            case 0x18C290u: goto label_18c290;
            case 0x18C294u: goto label_18c294;
            case 0x18C298u: goto label_18c298;
            case 0x18C29Cu: goto label_18c29c;
            case 0x18C2A0u: goto label_18c2a0;
            case 0x18C2A4u: goto label_18c2a4;
            case 0x18C2A8u: goto label_18c2a8;
            case 0x18C2ACu: goto label_18c2ac;
            case 0x18C2B0u: goto label_18c2b0;
            case 0x18C2B4u: goto label_18c2b4;
            case 0x18C2B8u: goto label_18c2b8;
            case 0x18C2BCu: goto label_18c2bc;
            case 0x18C2C0u: goto label_18c2c0;
            case 0x18C2C4u: goto label_18c2c4;
            case 0x18C2C8u: goto label_18c2c8;
            case 0x18C2CCu: goto label_18c2cc;
            case 0x18C2D0u: goto label_18c2d0;
            case 0x18C2D4u: goto label_18c2d4;
            case 0x18C2D8u: goto label_18c2d8;
            case 0x18C2DCu: goto label_18c2dc;
            case 0x18C2E0u: goto label_18c2e0;
            case 0x18C2E4u: goto label_18c2e4;
            case 0x18C2E8u: goto label_18c2e8;
            case 0x18C2ECu: goto label_18c2ec;
            case 0x18C2F0u: goto label_18c2f0;
            case 0x18C2F4u: goto label_18c2f4;
            case 0x18C2F8u: goto label_18c2f8;
            case 0x18C2FCu: goto label_18c2fc;
            case 0x18C300u: goto label_18c300;
            case 0x18C304u: goto label_18c304;
            case 0x18C308u: goto label_18c308;
            case 0x18C30Cu: goto label_18c30c;
            case 0x18C310u: goto label_18c310;
            case 0x18C314u: goto label_18c314;
            case 0x18C318u: goto label_18c318;
            case 0x18C31Cu: goto label_18c31c;
            case 0x18C320u: goto label_18c320;
            case 0x18C324u: goto label_18c324;
            case 0x18C328u: goto label_18c328;
            case 0x18C32Cu: goto label_18c32c;
            case 0x18C330u: goto label_18c330;
            case 0x18C334u: goto label_18c334;
            case 0x18C338u: goto label_18c338;
            case 0x18C33Cu: goto label_18c33c;
            case 0x18C340u: goto label_18c340;
            case 0x18C344u: goto label_18c344;
            case 0x18C348u: goto label_18c348;
            case 0x18C34Cu: goto label_18c34c;
            case 0x18C350u: goto label_18c350;
            case 0x18C354u: goto label_18c354;
            case 0x18C358u: goto label_18c358;
            case 0x18C35Cu: goto label_18c35c;
            case 0x18C360u: goto label_18c360;
            case 0x18C364u: goto label_18c364;
            case 0x18C368u: goto label_18c368;
            case 0x18C36Cu: goto label_18c36c;
            case 0x18C370u: goto label_18c370;
            case 0x18C374u: goto label_18c374;
            case 0x18C378u: goto label_18c378;
            case 0x18C37Cu: goto label_18c37c;
            case 0x18C380u: goto label_18c380;
            case 0x18C384u: goto label_18c384;
            case 0x18C388u: goto label_18c388;
            case 0x18C38Cu: goto label_18c38c;
            case 0x18C390u: goto label_18c390;
            case 0x18C394u: goto label_18c394;
            case 0x18C398u: goto label_18c398;
            case 0x18C39Cu: goto label_18c39c;
            case 0x18C3A0u: goto label_18c3a0;
            case 0x18C3A4u: goto label_18c3a4;
            case 0x18C3A8u: goto label_18c3a8;
            case 0x18C3ACu: goto label_18c3ac;
            case 0x18C3B0u: goto label_18c3b0;
            case 0x18C3B4u: goto label_18c3b4;
            case 0x18C3B8u: goto label_18c3b8;
            case 0x18C3BCu: goto label_18c3bc;
            case 0x18C3C0u: goto label_18c3c0;
            case 0x18C3C4u: goto label_18c3c4;
            case 0x18C3C8u: goto label_18c3c8;
            case 0x18C3CCu: goto label_18c3cc;
            case 0x18C3D0u: goto label_18c3d0;
            case 0x18C3D4u: goto label_18c3d4;
            case 0x18C3D8u: goto label_18c3d8;
            case 0x18C3DCu: goto label_18c3dc;
            case 0x18C3E0u: goto label_18c3e0;
            case 0x18C3E4u: goto label_18c3e4;
            case 0x18C3E8u: goto label_18c3e8;
            case 0x18C3ECu: goto label_18c3ec;
            case 0x18C3F0u: goto label_18c3f0;
            case 0x18C3F4u: goto label_18c3f4;
            case 0x18C3F8u: goto label_18c3f8;
            case 0x18C3FCu: goto label_18c3fc;
            case 0x18C400u: goto label_18c400;
            case 0x18C404u: goto label_18c404;
            case 0x18C408u: goto label_18c408;
            case 0x18C40Cu: goto label_18c40c;
            case 0x18C410u: goto label_18c410;
            case 0x18C414u: goto label_18c414;
            case 0x18C418u: goto label_18c418;
            case 0x18C41Cu: goto label_18c41c;
            case 0x18C420u: goto label_18c420;
            case 0x18C424u: goto label_18c424;
            case 0x18C428u: goto label_18c428;
            case 0x18C42Cu: goto label_18c42c;
            case 0x18C430u: goto label_18c430;
            case 0x18C434u: goto label_18c434;
            case 0x18C438u: goto label_18c438;
            case 0x18C43Cu: goto label_18c43c;
            case 0x18C440u: goto label_18c440;
            case 0x18C444u: goto label_18c444;
            case 0x18C448u: goto label_18c448;
            case 0x18C44Cu: goto label_18c44c;
            case 0x18C450u: goto label_18c450;
            case 0x18C454u: goto label_18c454;
            case 0x18C458u: goto label_18c458;
            case 0x18C45Cu: goto label_18c45c;
            case 0x18C460u: goto label_18c460;
            case 0x18C464u: goto label_18c464;
            case 0x18C468u: goto label_18c468;
            case 0x18C46Cu: goto label_18c46c;
            case 0x18C470u: goto label_18c470;
            case 0x18C474u: goto label_18c474;
            case 0x18C478u: goto label_18c478;
            case 0x18C47Cu: goto label_18c47c;
            case 0x18C480u: goto label_18c480;
            case 0x18C484u: goto label_18c484;
            case 0x18C488u: goto label_18c488;
            case 0x18C48Cu: goto label_18c48c;
            case 0x18C490u: goto label_18c490;
            case 0x18C494u: goto label_18c494;
            case 0x18C498u: goto label_18c498;
            case 0x18C49Cu: goto label_18c49c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x18C3D8u; }
            if (ctx->pc != 0x18C3D8u) { return; }
        }
    }
    ctx->pc = 0x18C3D8u;
label_18c3d8:
    // 0x18c3d8: 0x40882d
    ctx->pc = 0x18c3d8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_18c3dc:
    // 0x18c3dc: 0x3c01002a
    ctx->pc = 0x18c3dcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
label_18c3e0:
    // 0x18c3e0: 0x8e430048
    ctx->pc = 0x18c3e0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 72)));
label_18c3e4:
    // 0x18c3e4: 0x8c22fd9c
    ctx->pc = 0x18c3e4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 4294966684)));
label_18c3e8:
    // 0x18c3e8: 0x1043001a
label_18c3ec:
    if (ctx->pc == 0x18C3ECu) {
        ctx->pc = 0x18C3ECu;
        SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
        ctx->pc = 0x18C3F0u;
        goto label_18c3f0;
    }
    ctx->pc = 0x18C3E8u;
    {
        const bool branch_taken_0x18c3e8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 3));
        ctx->pc = 0x18C3ECu;
        SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
        if (branch_taken_0x18c3e8) {
            ctx->pc = 0x18C454u;
            goto label_18c454;
        }
    }
    ctx->pc = 0x18C3F0u;
label_18c3f0:
    // 0x18c3f0: 0x24040040
    ctx->pc = 0x18c3f0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 64));
label_18c3f4:
    // 0x18c3f4: 0xac23fd9c
    ctx->pc = 0x18c3f4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294966684), GPR_U32(ctx, 3));
label_18c3f8:
    // 0x18c3f8: 0xc063774
label_18c3fc:
    if (ctx->pc == 0x18C3FCu) {
        ctx->pc = 0x18C3FCu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
        ctx->pc = 0x18C400u;
        goto label_18c400;
    }
    ctx->pc = 0x18C3F8u;
    SET_GPR_U32(ctx, 31, 0x18C400u);
    ctx->pc = 0x18C3FCu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C400u; }
    }
    if (ctx->pc != 0x18C400u) { return; }
    ctx->pc = 0x18C400u;
label_18c400:
    // 0x18c400: 0x3c035000
    ctx->pc = 0x18c400u;
    SET_GPR_U32(ctx, 3, ((uint32_t)20480 << 16));
label_18c404:
    // 0x18c404: 0x2293c
    ctx->pc = 0x18c404u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 4));
label_18c408:
    // 0x18c408: 0x34640001
    ctx->pc = 0x18c408u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 1));
label_18c40c:
    // 0x18c40c: 0x3c07002a
    ctx->pc = 0x18c40cu;
    SET_GPR_U32(ctx, 7, ((uint32_t)42 << 16));
label_18c410:
    // 0x18c410: 0xac440000
    ctx->pc = 0x18c410u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
label_18c414:
    // 0x18c414: 0x3c03f000
    ctx->pc = 0x18c414u;
    SET_GPR_U32(ctx, 3, ((uint32_t)61440 << 16));
label_18c418:
    // 0x18c418: 0x8e48004c
    ctx->pc = 0x18c418u;
    SET_GPR_U32(ctx, 8, READ32(ADD32(GPR_U32(ctx, 18), 76)));
label_18c41c:
    // 0x18c41c: 0x34630001
    ctx->pc = 0x18c41cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 1));
label_18c420:
    // 0x18c420: 0x24460020
    ctx->pc = 0x18c420u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 2), 32));
label_18c424:
    // 0x18c424: 0x5293e
    ctx->pc = 0x18c424u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) >> (32 + 4));
label_18c428:
    // 0x18c428: 0x202d
    ctx->pc = 0x18c428u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18c42c:
    // 0x18c42c: 0x24e7f6f0
    ctx->pc = 0x18c42cu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 4294964976));
label_18c430:
    // 0x18c430: 0x8d080000
    ctx->pc = 0x18c430u;
    SET_GPR_U32(ctx, 8, READ32(ADD32(GPR_U32(ctx, 8), 0)));
label_18c434:
    // 0x18c434: 0xac480004
    ctx->pc = 0x18c434u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 8));
label_18c438:
    // 0x18c438: 0xfc400008
    ctx->pc = 0x18c438u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
label_18c43c:
    // 0x18c43c: 0xac430020
    ctx->pc = 0x18c43cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 32), GPR_U32(ctx, 3));
label_18c440:
    // 0x18c440: 0xac400024
    ctx->pc = 0x18c440u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 36), GPR_U32(ctx, 0));
label_18c444:
    // 0x18c444: 0xfc400028
    ctx->pc = 0x18c444u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 40), GPR_U64(ctx, 0));
label_18c448:
    // 0x18c448: 0x7c400030
    ctx->pc = 0x18c448u;
    WRITE128(ADD32(GPR_U32(ctx, 2), 48), GPR_VEC(ctx, 0));
label_18c44c:
    // 0x18c44c: 0xc0633ec
label_18c450:
    if (ctx->pc == 0x18C450u) {
        ctx->pc = 0x18C450u;
        WRITE128(ADD32(GPR_U32(ctx, 2), 16), GPR_VEC(ctx, 0));
        ctx->pc = 0x18C454u;
        goto label_18c454;
    }
    ctx->pc = 0x18C44Cu;
    SET_GPR_U32(ctx, 31, 0x18C454u);
    ctx->pc = 0x18C450u;
    WRITE128(ADD32(GPR_U32(ctx, 2), 16), GPR_VEC(ctx, 0));
    ctx->pc = 0x18CFB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C454u; }
    }
    if (ctx->pc != 0x18C454u) { return; }
    ctx->pc = 0x18C454u;
label_18c454:
    // 0x18c454: 0x11193c
    ctx->pc = 0x18c454u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 17) << (32 + 4));
label_18c458:
    // 0x18c458: 0x3c07002a
    ctx->pc = 0x18c458u;
    SET_GPR_U32(ctx, 7, ((uint32_t)42 << 16));
label_18c45c:
    // 0x18c45c: 0x3193e
    ctx->pc = 0x18c45cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 4));
label_18c460:
    // 0x18c460: 0x3c025000
    ctx->pc = 0x18c460u;
    SET_GPR_U32(ctx, 2, ((uint32_t)20480 << 16));
label_18c464:
    // 0x18c464: 0x200302d
    ctx->pc = 0x18c464u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_18c468:
    // 0x18c468: 0x202d
    ctx->pc = 0x18c468u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18c46c:
    // 0x18c46c: 0x622825
    ctx->pc = 0x18c46cu;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_18c470:
    // 0x18c470: 0xc0633ec
label_18c474:
    if (ctx->pc == 0x18C474u) {
        ctx->pc = 0x18C474u;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 4294964976));
        ctx->pc = 0x18C478u;
        goto label_18c478;
    }
    ctx->pc = 0x18C470u;
    SET_GPR_U32(ctx, 31, 0x18C478u);
    ctx->pc = 0x18C474u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 4294964976));
    ctx->pc = 0x18CFB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018CFB0_0x18cfb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18C478u; }
    }
    if (ctx->pc != 0x18C478u) { return; }
    ctx->pc = 0x18C478u;
label_18c478:
    // 0x18c478: 0x24020001
    ctx->pc = 0x18c478u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_18c47c:
    // 0x18c47c: 0xdfbf0030
    ctx->pc = 0x18c47cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_18c480:
    // 0x18c480: 0x7bb20020
    ctx->pc = 0x18c480u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
label_18c484:
    // 0x18c484: 0x7bb10010
    ctx->pc = 0x18c484u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
label_18c488:
    // 0x18c488: 0x7bb00000
    ctx->pc = 0x18c488u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
label_18c48c:
    // 0x18c48c: 0x3e00008
label_18c490:
    if (ctx->pc == 0x18C490u) {
        ctx->pc = 0x18C490u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 112));
        ctx->pc = 0x18C494u;
        goto label_18c494;
    }
    ctx->pc = 0x18C48Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18C490u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 112));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18C070u: goto label_18c070;
            case 0x18C074u: goto label_18c074;
            case 0x18C078u: goto label_18c078;
            case 0x18C07Cu: goto label_18c07c;
            case 0x18C080u: goto label_18c080;
            case 0x18C084u: goto label_18c084;
            case 0x18C088u: goto label_18c088;
            case 0x18C08Cu: goto label_18c08c;
            case 0x18C090u: goto label_18c090;
            case 0x18C094u: goto label_18c094;
            case 0x18C098u: goto label_18c098;
            case 0x18C09Cu: goto label_18c09c;
            case 0x18C0A0u: goto label_18c0a0;
            case 0x18C0A4u: goto label_18c0a4;
            case 0x18C0A8u: goto label_18c0a8;
            case 0x18C0ACu: goto label_18c0ac;
            case 0x18C0B0u: goto label_18c0b0;
            case 0x18C0B4u: goto label_18c0b4;
            case 0x18C0B8u: goto label_18c0b8;
            case 0x18C0BCu: goto label_18c0bc;
            case 0x18C0C0u: goto label_18c0c0;
            case 0x18C0C4u: goto label_18c0c4;
            case 0x18C0C8u: goto label_18c0c8;
            case 0x18C0CCu: goto label_18c0cc;
            case 0x18C0D0u: goto label_18c0d0;
            case 0x18C0D4u: goto label_18c0d4;
            case 0x18C0D8u: goto label_18c0d8;
            case 0x18C0DCu: goto label_18c0dc;
            case 0x18C0E0u: goto label_18c0e0;
            case 0x18C0E4u: goto label_18c0e4;
            case 0x18C0E8u: goto label_18c0e8;
            case 0x18C0ECu: goto label_18c0ec;
            case 0x18C0F0u: goto label_18c0f0;
            case 0x18C0F4u: goto label_18c0f4;
            case 0x18C0F8u: goto label_18c0f8;
            case 0x18C0FCu: goto label_18c0fc;
            case 0x18C100u: goto label_18c100;
            case 0x18C104u: goto label_18c104;
            case 0x18C108u: goto label_18c108;
            case 0x18C10Cu: goto label_18c10c;
            case 0x18C110u: goto label_18c110;
            case 0x18C114u: goto label_18c114;
            case 0x18C118u: goto label_18c118;
            case 0x18C11Cu: goto label_18c11c;
            case 0x18C120u: goto label_18c120;
            case 0x18C124u: goto label_18c124;
            case 0x18C128u: goto label_18c128;
            case 0x18C12Cu: goto label_18c12c;
            case 0x18C130u: goto label_18c130;
            case 0x18C134u: goto label_18c134;
            case 0x18C138u: goto label_18c138;
            case 0x18C13Cu: goto label_18c13c;
            case 0x18C140u: goto label_18c140;
            case 0x18C144u: goto label_18c144;
            case 0x18C148u: goto label_18c148;
            case 0x18C14Cu: goto label_18c14c;
            case 0x18C150u: goto label_18c150;
            case 0x18C154u: goto label_18c154;
            case 0x18C158u: goto label_18c158;
            case 0x18C15Cu: goto label_18c15c;
            case 0x18C160u: goto label_18c160;
            case 0x18C164u: goto label_18c164;
            case 0x18C168u: goto label_18c168;
            case 0x18C16Cu: goto label_18c16c;
            case 0x18C170u: goto label_18c170;
            case 0x18C174u: goto label_18c174;
            case 0x18C178u: goto label_18c178;
            case 0x18C17Cu: goto label_18c17c;
            case 0x18C180u: goto label_18c180;
            case 0x18C184u: goto label_18c184;
            case 0x18C188u: goto label_18c188;
            case 0x18C18Cu: goto label_18c18c;
            case 0x18C190u: goto label_18c190;
            case 0x18C194u: goto label_18c194;
            case 0x18C198u: goto label_18c198;
            case 0x18C19Cu: goto label_18c19c;
            case 0x18C1A0u: goto label_18c1a0;
            case 0x18C1A4u: goto label_18c1a4;
            case 0x18C1A8u: goto label_18c1a8;
            case 0x18C1ACu: goto label_18c1ac;
            case 0x18C1B0u: goto label_18c1b0;
            case 0x18C1B4u: goto label_18c1b4;
            case 0x18C1B8u: goto label_18c1b8;
            case 0x18C1BCu: goto label_18c1bc;
            case 0x18C1C0u: goto label_18c1c0;
            case 0x18C1C4u: goto label_18c1c4;
            case 0x18C1C8u: goto label_18c1c8;
            case 0x18C1CCu: goto label_18c1cc;
            case 0x18C1D0u: goto label_18c1d0;
            case 0x18C1D4u: goto label_18c1d4;
            case 0x18C1D8u: goto label_18c1d8;
            case 0x18C1DCu: goto label_18c1dc;
            case 0x18C1E0u: goto label_18c1e0;
            case 0x18C1E4u: goto label_18c1e4;
            case 0x18C1E8u: goto label_18c1e8;
            case 0x18C1ECu: goto label_18c1ec;
            case 0x18C1F0u: goto label_18c1f0;
            case 0x18C1F4u: goto label_18c1f4;
            case 0x18C1F8u: goto label_18c1f8;
            case 0x18C1FCu: goto label_18c1fc;
            case 0x18C200u: goto label_18c200;
            case 0x18C204u: goto label_18c204;
            case 0x18C208u: goto label_18c208;
            case 0x18C20Cu: goto label_18c20c;
            case 0x18C210u: goto label_18c210;
            case 0x18C214u: goto label_18c214;
            case 0x18C218u: goto label_18c218;
            case 0x18C21Cu: goto label_18c21c;
            case 0x18C220u: goto label_18c220;
            case 0x18C224u: goto label_18c224;
            case 0x18C228u: goto label_18c228;
            case 0x18C22Cu: goto label_18c22c;
            case 0x18C230u: goto label_18c230;
            case 0x18C234u: goto label_18c234;
            case 0x18C238u: goto label_18c238;
            case 0x18C23Cu: goto label_18c23c;
            case 0x18C240u: goto label_18c240;
            case 0x18C244u: goto label_18c244;
            case 0x18C248u: goto label_18c248;
            case 0x18C24Cu: goto label_18c24c;
            case 0x18C250u: goto label_18c250;
            case 0x18C254u: goto label_18c254;
            case 0x18C258u: goto label_18c258;
            case 0x18C25Cu: goto label_18c25c;
            case 0x18C260u: goto label_18c260;
            case 0x18C264u: goto label_18c264;
            case 0x18C268u: goto label_18c268;
            case 0x18C26Cu: goto label_18c26c;
            case 0x18C270u: goto label_18c270;
            case 0x18C274u: goto label_18c274;
            case 0x18C278u: goto label_18c278;
            case 0x18C27Cu: goto label_18c27c;
            case 0x18C280u: goto label_18c280;
            case 0x18C284u: goto label_18c284;
            case 0x18C288u: goto label_18c288;
            case 0x18C28Cu: goto label_18c28c;
            case 0x18C290u: goto label_18c290;
            case 0x18C294u: goto label_18c294;
            case 0x18C298u: goto label_18c298;
            case 0x18C29Cu: goto label_18c29c;
            case 0x18C2A0u: goto label_18c2a0;
            case 0x18C2A4u: goto label_18c2a4;
            case 0x18C2A8u: goto label_18c2a8;
            case 0x18C2ACu: goto label_18c2ac;
            case 0x18C2B0u: goto label_18c2b0;
            case 0x18C2B4u: goto label_18c2b4;
            case 0x18C2B8u: goto label_18c2b8;
            case 0x18C2BCu: goto label_18c2bc;
            case 0x18C2C0u: goto label_18c2c0;
            case 0x18C2C4u: goto label_18c2c4;
            case 0x18C2C8u: goto label_18c2c8;
            case 0x18C2CCu: goto label_18c2cc;
            case 0x18C2D0u: goto label_18c2d0;
            case 0x18C2D4u: goto label_18c2d4;
            case 0x18C2D8u: goto label_18c2d8;
            case 0x18C2DCu: goto label_18c2dc;
            case 0x18C2E0u: goto label_18c2e0;
            case 0x18C2E4u: goto label_18c2e4;
            case 0x18C2E8u: goto label_18c2e8;
            case 0x18C2ECu: goto label_18c2ec;
            case 0x18C2F0u: goto label_18c2f0;
            case 0x18C2F4u: goto label_18c2f4;
            case 0x18C2F8u: goto label_18c2f8;
            case 0x18C2FCu: goto label_18c2fc;
            case 0x18C300u: goto label_18c300;
            case 0x18C304u: goto label_18c304;
            case 0x18C308u: goto label_18c308;
            case 0x18C30Cu: goto label_18c30c;
            case 0x18C310u: goto label_18c310;
            case 0x18C314u: goto label_18c314;
            case 0x18C318u: goto label_18c318;
            case 0x18C31Cu: goto label_18c31c;
            case 0x18C320u: goto label_18c320;
            case 0x18C324u: goto label_18c324;
            case 0x18C328u: goto label_18c328;
            case 0x18C32Cu: goto label_18c32c;
            case 0x18C330u: goto label_18c330;
            case 0x18C334u: goto label_18c334;
            case 0x18C338u: goto label_18c338;
            case 0x18C33Cu: goto label_18c33c;
            case 0x18C340u: goto label_18c340;
            case 0x18C344u: goto label_18c344;
            case 0x18C348u: goto label_18c348;
            case 0x18C34Cu: goto label_18c34c;
            case 0x18C350u: goto label_18c350;
            case 0x18C354u: goto label_18c354;
            case 0x18C358u: goto label_18c358;
            case 0x18C35Cu: goto label_18c35c;
            case 0x18C360u: goto label_18c360;
            case 0x18C364u: goto label_18c364;
            case 0x18C368u: goto label_18c368;
            case 0x18C36Cu: goto label_18c36c;
            case 0x18C370u: goto label_18c370;
            case 0x18C374u: goto label_18c374;
            case 0x18C378u: goto label_18c378;
            case 0x18C37Cu: goto label_18c37c;
            case 0x18C380u: goto label_18c380;
            case 0x18C384u: goto label_18c384;
            case 0x18C388u: goto label_18c388;
            case 0x18C38Cu: goto label_18c38c;
            case 0x18C390u: goto label_18c390;
            case 0x18C394u: goto label_18c394;
            case 0x18C398u: goto label_18c398;
            case 0x18C39Cu: goto label_18c39c;
            case 0x18C3A0u: goto label_18c3a0;
            case 0x18C3A4u: goto label_18c3a4;
            case 0x18C3A8u: goto label_18c3a8;
            case 0x18C3ACu: goto label_18c3ac;
            case 0x18C3B0u: goto label_18c3b0;
            case 0x18C3B4u: goto label_18c3b4;
            case 0x18C3B8u: goto label_18c3b8;
            case 0x18C3BCu: goto label_18c3bc;
            case 0x18C3C0u: goto label_18c3c0;
            case 0x18C3C4u: goto label_18c3c4;
            case 0x18C3C8u: goto label_18c3c8;
            case 0x18C3CCu: goto label_18c3cc;
            case 0x18C3D0u: goto label_18c3d0;
            case 0x18C3D4u: goto label_18c3d4;
            case 0x18C3D8u: goto label_18c3d8;
            case 0x18C3DCu: goto label_18c3dc;
            case 0x18C3E0u: goto label_18c3e0;
            case 0x18C3E4u: goto label_18c3e4;
            case 0x18C3E8u: goto label_18c3e8;
            case 0x18C3ECu: goto label_18c3ec;
            case 0x18C3F0u: goto label_18c3f0;
            case 0x18C3F4u: goto label_18c3f4;
            case 0x18C3F8u: goto label_18c3f8;
            case 0x18C3FCu: goto label_18c3fc;
            case 0x18C400u: goto label_18c400;
            case 0x18C404u: goto label_18c404;
            case 0x18C408u: goto label_18c408;
            case 0x18C40Cu: goto label_18c40c;
            case 0x18C410u: goto label_18c410;
            case 0x18C414u: goto label_18c414;
            case 0x18C418u: goto label_18c418;
            case 0x18C41Cu: goto label_18c41c;
            case 0x18C420u: goto label_18c420;
            case 0x18C424u: goto label_18c424;
            case 0x18C428u: goto label_18c428;
            case 0x18C42Cu: goto label_18c42c;
            case 0x18C430u: goto label_18c430;
            case 0x18C434u: goto label_18c434;
            case 0x18C438u: goto label_18c438;
            case 0x18C43Cu: goto label_18c43c;
            case 0x18C440u: goto label_18c440;
            case 0x18C444u: goto label_18c444;
            case 0x18C448u: goto label_18c448;
            case 0x18C44Cu: goto label_18c44c;
            case 0x18C450u: goto label_18c450;
            case 0x18C454u: goto label_18c454;
            case 0x18C458u: goto label_18c458;
            case 0x18C45Cu: goto label_18c45c;
            case 0x18C460u: goto label_18c460;
            case 0x18C464u: goto label_18c464;
            case 0x18C468u: goto label_18c468;
            case 0x18C46Cu: goto label_18c46c;
            case 0x18C470u: goto label_18c470;
            case 0x18C474u: goto label_18c474;
            case 0x18C478u: goto label_18c478;
            case 0x18C47Cu: goto label_18c47c;
            case 0x18C480u: goto label_18c480;
            case 0x18C484u: goto label_18c484;
            case 0x18C488u: goto label_18c488;
            case 0x18C48Cu: goto label_18c48c;
            case 0x18C490u: goto label_18c490;
            case 0x18C494u: goto label_18c494;
            case 0x18C498u: goto label_18c498;
            case 0x18C49Cu: goto label_18c49c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18C494u;
label_18c494:
    // 0x18c494: 0x0
    ctx->pc = 0x18c494u;
    // NOP
label_18c498:
    // 0x18c498: 0x0
    ctx->pc = 0x18c498u;
    // NOP
label_18c49c:
    // 0x18c49c: 0x0
    ctx->pc = 0x18c49cu;
    // NOP
}
