#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0013C0A0
// Address: 0x13c0a0 - 0x13c240
void sub_0013C0A0_0x13c0a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x13c0a0u;

    // 0x13c0a0: 0x27bdffa0
    ctx->pc = 0x13c0a0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x13c0a4: 0xffb20020
    ctx->pc = 0x13c0a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x13c0a8: 0x902d
    ctx->pc = 0x13c0a8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c0ac: 0xffb30028
    ctx->pc = 0x13c0acu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x13c0b0: 0xa0982d
    ctx->pc = 0x13c0b0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c0b4: 0xffb40030
    ctx->pc = 0x13c0b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x13c0b8: 0xa02d
    ctx->pc = 0x13c0b8u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c0bc: 0xffb50038
    ctx->pc = 0x13c0bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x13c0c0: 0xc0a82d
    ctx->pc = 0x13c0c0u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c0c4: 0xffbe0050
    ctx->pc = 0x13c0c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x13c0c8: 0xe0f02d
    ctx->pc = 0x13c0c8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c0cc: 0xffb00010
    ctx->pc = 0x13c0ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x13c0d0: 0xffb10018
    ctx->pc = 0x13c0d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x13c0d4: 0xffb60040
    ctx->pc = 0x13c0d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x13c0d8: 0xffb70048
    ctx->pc = 0x13c0d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x13c0dc: 0xffbf0058
    ctx->pc = 0x13c0dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x13c0e0: 0xafa40000
    ctx->pc = 0x13c0e0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x13c0e4: 0x82620000
    ctx->pc = 0x13c0e4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x13c0e8: 0x1040003d
    ctx->pc = 0x13C0E8u;
    {
        const bool branch_taken_0x13c0e8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x13C0ECu;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x13c0e8) {
            ctx->pc = 0x13C1E0u;
            goto label_13c1e0;
        }
    }
    ctx->pc = 0x13C0F0u;
    // 0x13c0f0: 0x1510c0
    ctx->pc = 0x13c0f0u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 21), 3));
    // 0x13c0f4: 0x260202d
    ctx->pc = 0x13c0f4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c0f8: 0xafa20004
    ctx->pc = 0x13c0f8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x13c0fc: 0x2417000a
    ctx->pc = 0x13c0fcu;
    SET_GPR_S32(ctx, 23, ADD32(GPR_U32(ctx, 0), 10));
    // 0x13c100: 0x2416000d
    ctx->pc = 0x13c100u;
    SET_GPR_S32(ctx, 22, ADD32(GPR_U32(ctx, 0), 13));
    // 0x13c104: 0x80820000
    ctx->pc = 0x13c104u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
label_13c108:
    // 0x13c108: 0x2406005c
    ctx->pc = 0x13c108u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 92));
    // 0x13c10c: 0x14460004
    ctx->pc = 0x13C10Cu;
    {
        const bool branch_taken_0x13c10c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 6));
        ctx->pc = 0x13C110u;
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
        if (branch_taken_0x13c10c) {
            ctx->pc = 0x13C120u;
            goto label_13c120;
        }
    }
    ctx->pc = 0x13C114u;
    // 0x13c114: 0x2402002f
    ctx->pc = 0x13c114u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 47));
    // 0x13c118: 0x2403002f
    ctx->pc = 0x13c118u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 47));
    // 0x13c11c: 0xa0820000
    ctx->pc = 0x13c11cu;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 2));
label_13c120:
    // 0x13c120: 0x31600
    ctx->pc = 0x13c120u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 3), 24));
    // 0x13c124: 0x21603
    ctx->pc = 0x13c124u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x13c128: 0x50570006
    ctx->pc = 0x13C128u;
    {
        const bool branch_taken_0x13c128 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 23));
        if (branch_taken_0x13c128) {
            ctx->pc = 0x13C12Cu;
            SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
            ctx->pc = 0x13C144u;
            goto label_13c144;
        }
    }
    ctx->pc = 0x13C130u;
    // 0x13c130: 0x50560004
    ctx->pc = 0x13C130u;
    {
        const bool branch_taken_0x13c130 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 22));
        if (branch_taken_0x13c130) {
            ctx->pc = 0x13C134u;
            SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
            ctx->pc = 0x13C144u;
            goto label_13c144;
        }
    }
    ctx->pc = 0x13C138u;
    // 0x13c138: 0x14400023
    ctx->pc = 0x13C138u;
    {
        const bool branch_taken_0x13c138 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x13C13Cu;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 18), 1));
        if (branch_taken_0x13c138) {
            ctx->pc = 0x13C1C8u;
            goto label_13c1c8;
        }
    }
    ctx->pc = 0x13C140u;
    // 0x13c140: 0x80820001
    ctx->pc = 0x13c140u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
label_13c144:
    // 0x13c144: 0x50570006
    ctx->pc = 0x13C144u;
    {
        const bool branch_taken_0x13c144 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 23));
        if (branch_taken_0x13c144) {
            ctx->pc = 0x13C148u;
            SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 1));
            ctx->pc = 0x13C160u;
            goto label_13c160;
        }
    }
    ctx->pc = 0x13C14Cu;
    // 0x13c14c: 0x50560004
    ctx->pc = 0x13C14Cu;
    {
        const bool branch_taken_0x13c14c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 22));
        if (branch_taken_0x13c14c) {
            ctx->pc = 0x13C150u;
            SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 1));
            ctx->pc = 0x13C160u;
            goto label_13c160;
        }
    }
    ctx->pc = 0x13C154u;
    // 0x13c154: 0x14400004
    ctx->pc = 0x13C154u;
    {
        const bool branch_taken_0x13c154 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x13C158u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 4), 4294967295));
        if (branch_taken_0x13c154) {
            ctx->pc = 0x13C168u;
            goto label_13c168;
        }
    }
    ctx->pc = 0x13C15Cu;
    // 0x13c15c: 0x26520001
    ctx->pc = 0x13c15cu;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 1));
label_13c160:
    // 0x13c160: 0x2722021
    ctx->pc = 0x13c160u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 18)));
    // 0x13c164: 0x2482ffff
    ctx->pc = 0x13c164u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 4), 4294967295));
label_13c168:
    // 0x13c168: 0x80430000
    ctx->pc = 0x13c168u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x13c16c: 0x10770003
    ctx->pc = 0x13C16Cu;
    {
        const bool branch_taken_0x13c16c = (GPR_U32(ctx, 3) == GPR_U32(ctx, 23));
        ctx->pc = 0x13C170u;
        SET_GPR_U32(ctx, 17, SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
        if (branch_taken_0x13c16c) {
            ctx->pc = 0x13C17Cu;
            goto label_13c17c;
        }
    }
    ctx->pc = 0x13C174u;
    // 0x13c174: 0x54760003
    ctx->pc = 0x13C174u;
    {
        const bool branch_taken_0x13c174 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 22));
        if (branch_taken_0x13c174) {
            ctx->pc = 0x13C178u;
            { int64_t result = (int64_t)GPR_S32(ctx, 30) * (int64_t)GPR_S32(ctx, 20); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
            ctx->pc = 0x13C184u;
            goto label_13c184;
        }
    }
    ctx->pc = 0x13C17Cu;
label_13c17c:
    // 0x13c17c: 0xa0400000
    ctx->pc = 0x13c17cu;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x13c180: 0x3d41018
    ctx->pc = 0x13c180u;
    { int64_t result = (int64_t)GPR_S32(ctx, 30) * (int64_t)GPR_S32(ctx, 20); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
label_13c184:
    // 0x13c184: 0x8fa30004
    ctx->pc = 0x13c184u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x13c188: 0x220302d
    ctx->pc = 0x13c188u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c18c: 0x2652821
    ctx->pc = 0x13c18cu;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 5)));
    // 0x13c190: 0x548021
    ctx->pc = 0x13c190u;
    SET_GPR_U32(ctx, 16, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 20)));
    // 0x13c194: 0x8fa20000
    ctx->pc = 0x13c194u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13c198: 0x708021
    ctx->pc = 0x13c198u;
    SET_GPR_U32(ctx, 16, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
    // 0x13c19c: 0x508021
    ctx->pc = 0x13c19cu;
    SET_GPR_U32(ctx, 16, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x13c1a0: 0xc041eac
    ctx->pc = 0x13C1A0u;
    SET_GPR_U32(ctx, 31, 0x13C1A8u);
    ctx->pc = 0x13C1A4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x107AB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13C1A8u; }
    }
    if (ctx->pc != 0x13C1A8u) { return; }
    ctx->pc = 0x13C1A8u;
    // 0x13c1a8: 0x2113021
    ctx->pc = 0x13c1a8u;
    SET_GPR_U32(ctx, 6, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x13c1ac: 0x80c2ffff
    ctx->pc = 0x13c1acu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 6), 4294967295)));
    // 0x13c1b0: 0x54400001
    ctx->pc = 0x13C1B0u;
    {
        const bool branch_taken_0x13c1b0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x13c1b0) {
            ctx->pc = 0x13C1B4u;
            WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 0));
            ctx->pc = 0x13C1B8u;
            goto label_13c1b8;
        }
    }
    ctx->pc = 0x13C1B8u;
label_13c1b8:
    // 0x13c1b8: 0x26430001
    ctx->pc = 0x13c1b8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 18), 1));
    // 0x13c1bc: 0x26940001
    ctx->pc = 0x13c1bcu;
    SET_GPR_S32(ctx, 20, ADD32(GPR_U32(ctx, 20), 1));
    // 0x13c1c0: 0x12950007
    ctx->pc = 0x13C1C0u;
    {
        const bool branch_taken_0x13c1c0 = (GPR_U32(ctx, 20) == GPR_U32(ctx, 21));
        ctx->pc = 0x13C1C4u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x13c1c0) {
            ctx->pc = 0x13C1E0u;
            goto label_13c1e0;
        }
    }
    ctx->pc = 0x13C1C8u;
label_13c1c8:
    // 0x13c1c8: 0x60902d
    ctx->pc = 0x13c1c8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c1cc: 0x2721021
    ctx->pc = 0x13c1ccu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 18)));
    // 0x13c1d0: 0x40202d
    ctx->pc = 0x13c1d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13c1d4: 0x80830000
    ctx->pc = 0x13c1d4u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x13c1d8: 0x5460ffcb
    ctx->pc = 0x13C1D8u;
    {
        const bool branch_taken_0x13c1d8 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x13c1d8) {
            ctx->pc = 0x13C1DCu;
            SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
            ctx->pc = 0x13C108u;
            goto label_13c108;
        }
    }
    ctx->pc = 0x13C1E0u;
label_13c1e0:
    // 0x13c1e0: 0x3c020022
    ctx->pc = 0x13c1e0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
    // 0x13c1e4: 0x2442de90
    ctx->pc = 0x13c1e4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294958736));
    // 0x13c1e8: 0x8c430000
    ctx->pc = 0x13c1e8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x13c1ec: 0x54600007
    ctx->pc = 0x13C1ECu;
    {
        const bool branch_taken_0x13c1ec = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x13c1ec) {
            ctx->pc = 0x13C1F0u;
            SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
            ctx->pc = 0x13C20Cu;
            goto label_13c20c;
        }
    }
    ctx->pc = 0x13C1F4u;
    // 0x13c1f4: 0xac5e000c
    ctx->pc = 0x13c1f4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 30));
    // 0x13c1f8: 0x8fa30000
    ctx->pc = 0x13c1f8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13c1fc: 0xac550008
    ctx->pc = 0x13c1fcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 21));
    // 0x13c200: 0xac430000
    ctx->pc = 0x13c200u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x13c204: 0xac540004
    ctx->pc = 0x13c204u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 20));
    // 0x13c208: 0x280102d
    ctx->pc = 0x13c208u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
label_13c20c:
    // 0x13c20c: 0xdfb00010
    ctx->pc = 0x13c20cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13c210: 0xdfb10018
    ctx->pc = 0x13c210u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13c214: 0xdfb20020
    ctx->pc = 0x13c214u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13c218: 0xdfb30028
    ctx->pc = 0x13c218u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13c21c: 0xdfb40030
    ctx->pc = 0x13c21cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13c220: 0xdfb50038
    ctx->pc = 0x13c220u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x13c224: 0xdfb60040
    ctx->pc = 0x13c224u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x13c228: 0xdfb70048
    ctx->pc = 0x13c228u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x13c22c: 0xdfbe0050
    ctx->pc = 0x13c22cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x13c230: 0xdfbf0058
    ctx->pc = 0x13c230u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x13c234: 0x3e00008
    ctx->pc = 0x13C234u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13C238u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13C108u: goto label_13c108;
            case 0x13C120u: goto label_13c120;
            case 0x13C144u: goto label_13c144;
            case 0x13C160u: goto label_13c160;
            case 0x13C168u: goto label_13c168;
            case 0x13C17Cu: goto label_13c17c;
            case 0x13C184u: goto label_13c184;
            case 0x13C1B8u: goto label_13c1b8;
            case 0x13C1C8u: goto label_13c1c8;
            case 0x13C1E0u: goto label_13c1e0;
            case 0x13C20Cu: goto label_13c20c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13C23Cu;
    // 0x13c23c: 0x0
    ctx->pc = 0x13c23cu;
    // NOP
}
