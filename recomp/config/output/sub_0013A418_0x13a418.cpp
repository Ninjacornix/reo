#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0013A418
// Address: 0x13a418 - 0x13a5b0
void sub_0013A418_0x13a418(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x13a418u;

    // 0x13a418: 0x27bdffa0
    ctx->pc = 0x13a418u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x13a41c: 0xffb20020
    ctx->pc = 0x13a41cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x13a420: 0x902d
    ctx->pc = 0x13a420u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a424: 0xffb30028
    ctx->pc = 0x13a424u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x13a428: 0xa0982d
    ctx->pc = 0x13a428u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a42c: 0xffb50038
    ctx->pc = 0x13a42cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x13a430: 0xa82d
    ctx->pc = 0x13a430u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a434: 0xffb60040
    ctx->pc = 0x13a434u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x13a438: 0xe0b02d
    ctx->pc = 0x13a438u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a43c: 0xffb70048
    ctx->pc = 0x13a43cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x13a440: 0x100b82d
    ctx->pc = 0x13a440u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a444: 0xafa40000
    ctx->pc = 0x13a444u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x13a448: 0x202d
    ctx->pc = 0x13a448u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a44c: 0xffb00010
    ctx->pc = 0x13a44cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x13a450: 0xffb10018
    ctx->pc = 0x13a450u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x13a454: 0xffb40030
    ctx->pc = 0x13a454u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x13a458: 0xffbe0050
    ctx->pc = 0x13a458u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x13a45c: 0xffbf0058
    ctx->pc = 0x13a45cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x13a460: 0x82620000
    ctx->pc = 0x13a460u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x13a464: 0x1040003a
    ctx->pc = 0x13A464u;
    {
        const bool branch_taken_0x13a464 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x13A468u;
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 6));
        if (branch_taken_0x13a464) {
            ctx->pc = 0x13A550u;
            goto label_13a550;
        }
    }
    ctx->pc = 0x13A46Cu;
    // 0x13a46c: 0x8fa30000
    ctx->pc = 0x13a46cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13a470: 0x1610c0
    ctx->pc = 0x13a470u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 22), 3));
    // 0x13a474: 0x2414000a
    ctx->pc = 0x13a474u;
    SET_GPR_S32(ctx, 20, ADD32(GPR_U32(ctx, 0), 10));
    // 0x13a478: 0x241e000d
    ctx->pc = 0x13a478u;
    SET_GPR_S32(ctx, 30, ADD32(GPR_U32(ctx, 0), 13));
    // 0x13a47c: 0x438021
    ctx->pc = 0x13a47cu;
    SET_GPR_U32(ctx, 16, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x13a480: 0x80a20000
    ctx->pc = 0x13a480u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x13a484: 0x0
    ctx->pc = 0x13a484u;
    // NOP
label_13a488:
    // 0x13a488: 0x50540004
    ctx->pc = 0x13A488u;
    {
        const bool branch_taken_0x13a488 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 20));
        if (branch_taken_0x13a488) {
            ctx->pc = 0x13A48Cu;
            SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
            ctx->pc = 0x13A49Cu;
            goto label_13a49c;
        }
    }
    ctx->pc = 0x13A490u;
    // 0x13a490: 0x14400026
    ctx->pc = 0x13A490u;
    {
        const bool branch_taken_0x13a490 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x13A494u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 18), 1));
        if (branch_taken_0x13a490) {
            ctx->pc = 0x13A52Cu;
            goto label_13a52c;
        }
    }
    ctx->pc = 0x13A498u;
    // 0x13a498: 0x80a20001
    ctx->pc = 0x13a498u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 1)));
label_13a49c:
    // 0x13a49c: 0x50540004
    ctx->pc = 0x13A49Cu;
    {
        const bool branch_taken_0x13a49c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 20));
        if (branch_taken_0x13a49c) {
            ctx->pc = 0x13A4A0u;
            SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 1));
            ctx->pc = 0x13A4B0u;
            goto label_13a4b0;
        }
    }
    ctx->pc = 0x13A4A4u;
    // 0x13a4a4: 0x14400004
    ctx->pc = 0x13A4A4u;
    {
        const bool branch_taken_0x13a4a4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x13A4A8u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 5), 4294967295));
        if (branch_taken_0x13a4a4) {
            ctx->pc = 0x13A4B8u;
            goto label_13a4b8;
        }
    }
    ctx->pc = 0x13A4ACu;
    // 0x13a4ac: 0x26520001
    ctx->pc = 0x13a4acu;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 1));
label_13a4b0:
    // 0x13a4b0: 0x2722821
    ctx->pc = 0x13a4b0u;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 18)));
    // 0x13a4b4: 0x24a3ffff
    ctx->pc = 0x13a4b4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 5), 4294967295));
label_13a4b8:
    // 0x13a4b8: 0x80620000
    ctx->pc = 0x13a4b8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x13a4bc: 0x10540003
    ctx->pc = 0x13A4BCu;
    {
        const bool branch_taken_0x13a4bc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 20));
        ctx->pc = 0x13A4C0u;
        SET_GPR_U32(ctx, 17, SUB32(GPR_U32(ctx, 18), GPR_U32(ctx, 4)));
        if (branch_taken_0x13a4bc) {
            ctx->pc = 0x13A4CCu;
            goto label_13a4cc;
        }
    }
    ctx->pc = 0x13A4C4u;
    // 0x13a4c4: 0x145e0003
    ctx->pc = 0x13A4C4u;
    {
        const bool branch_taken_0x13a4c4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 30));
        ctx->pc = 0x13A4C8u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 5), 4294967294));
        if (branch_taken_0x13a4c4) {
            ctx->pc = 0x13A4D4u;
            goto label_13a4d4;
        }
    }
    ctx->pc = 0x13A4CCu;
label_13a4cc:
    // 0x13a4cc: 0xa0600000
    ctx->pc = 0x13a4ccu;
    WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x13a4d0: 0x24a2fffe
    ctx->pc = 0x13a4d0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 5), 4294967294));
label_13a4d4:
    // 0x13a4d4: 0x80430000
    ctx->pc = 0x13a4d4u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x13a4d8: 0x50740004
    ctx->pc = 0x13A4D8u;
    {
        const bool branch_taken_0x13a4d8 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 20));
        if (branch_taken_0x13a4d8) {
            ctx->pc = 0x13A4DCu;
            WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
            ctx->pc = 0x13A4ECu;
            goto label_13a4ec;
        }
    }
    ctx->pc = 0x13A4E0u;
    // 0x13a4e0: 0x147e0003
    ctx->pc = 0x13A4E0u;
    {
        const bool branch_taken_0x13a4e0 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 30));
        ctx->pc = 0x13A4E4u;
        SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 4)));
        if (branch_taken_0x13a4e0) {
            ctx->pc = 0x13A4F0u;
            goto label_13a4f0;
        }
    }
    ctx->pc = 0x13A4E8u;
    // 0x13a4e8: 0xa0400000
    ctx->pc = 0x13a4e8u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
label_13a4ec:
    // 0x13a4ec: 0x2642821
    ctx->pc = 0x13a4ecu;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 4)));
label_13a4f0:
    // 0x13a4f0: 0x200202d
    ctx->pc = 0x13a4f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a4f4: 0xc041eac
    ctx->pc = 0x13A4F4u;
    SET_GPR_U32(ctx, 31, 0x13A4FCu);
    ctx->pc = 0x13A4F8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x107AB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A4FCu; }
    }
    if (ctx->pc != 0x13A4FCu) { return; }
    ctx->pc = 0x13A4FCu;
    // 0x13a4fc: 0xc04e60a
    ctx->pc = 0x13A4FCu;
    SET_GPR_U32(ctx, 31, 0x13A504u);
    ctx->pc = 0x13A500u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x139828u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00139828_0x139828(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13A504u; }
    }
    if (ctx->pc != 0x13A504u) { return; }
    ctx->pc = 0x13A504u;
    // 0x13a504: 0x2113021
    ctx->pc = 0x13a504u;
    SET_GPR_U32(ctx, 6, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x13a508: 0x80c2ffff
    ctx->pc = 0x13a508u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 6), 4294967295)));
    // 0x13a50c: 0x54400001
    ctx->pc = 0x13A50Cu;
    {
        const bool branch_taken_0x13a50c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x13a50c) {
            ctx->pc = 0x13A510u;
            WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 0));
            ctx->pc = 0x13A514u;
            goto label_13a514;
        }
    }
    ctx->pc = 0x13A514u;
label_13a514:
    // 0x13a514: 0x26430001
    ctx->pc = 0x13a514u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 18), 1));
    // 0x13a518: 0x2f01021
    ctx->pc = 0x13a518u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 23), GPR_U32(ctx, 16)));
    // 0x13a51c: 0x26b50001
    ctx->pc = 0x13a51cu;
    SET_GPR_S32(ctx, 21, ADD32(GPR_U32(ctx, 21), 1));
    // 0x13a520: 0x24500001
    ctx->pc = 0x13a520u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 2), 1));
    // 0x13a524: 0x12b6000a
    ctx->pc = 0x13A524u;
    {
        const bool branch_taken_0x13a524 = (GPR_U32(ctx, 21) == GPR_U32(ctx, 22));
        ctx->pc = 0x13A528u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x13a524) {
            ctx->pc = 0x13A550u;
            goto label_13a550;
        }
    }
    ctx->pc = 0x13A52Cu;
label_13a52c:
    // 0x13a52c: 0x8fa50004
    ctx->pc = 0x13a52cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x13a530: 0xa3102a
    ctx->pc = 0x13a530u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 5), GPR_S32(ctx, 3)));
    // 0x13a534: 0x14400006
    ctx->pc = 0x13A534u;
    {
        const bool branch_taken_0x13a534 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x13A538u;
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x13a534) {
            ctx->pc = 0x13A550u;
            goto label_13a550;
        }
    }
    ctx->pc = 0x13A53Cu;
    // 0x13a53c: 0x2631021
    ctx->pc = 0x13a53cu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 19), GPR_U32(ctx, 3)));
    // 0x13a540: 0x40282d
    ctx->pc = 0x13a540u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13a544: 0x80a30000
    ctx->pc = 0x13a544u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x13a548: 0x5460ffcf
    ctx->pc = 0x13A548u;
    {
        const bool branch_taken_0x13a548 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x13a548) {
            ctx->pc = 0x13A54Cu;
            SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
            ctx->pc = 0x13A488u;
            goto label_13a488;
        }
    }
    ctx->pc = 0x13A550u;
label_13a550:
    // 0x13a550: 0x3c020022
    ctx->pc = 0x13a550u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
    // 0x13a554: 0x2442d8d0
    ctx->pc = 0x13a554u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294957264));
    // 0x13a558: 0x8c430000
    ctx->pc = 0x13a558u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x13a55c: 0x54600007
    ctx->pc = 0x13A55Cu;
    {
        const bool branch_taken_0x13a55c = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x13a55c) {
            ctx->pc = 0x13A560u;
            SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
            ctx->pc = 0x13A57Cu;
            goto label_13a57c;
        }
    }
    ctx->pc = 0x13A564u;
    // 0x13a564: 0xac57000c
    ctx->pc = 0x13a564u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 12), GPR_U32(ctx, 23));
    // 0x13a568: 0x8fa30000
    ctx->pc = 0x13a568u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13a56c: 0xac560008
    ctx->pc = 0x13a56cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 8), GPR_U32(ctx, 22));
    // 0x13a570: 0xac430000
    ctx->pc = 0x13a570u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x13a574: 0xac550004
    ctx->pc = 0x13a574u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 21));
    // 0x13a578: 0x2a0102d
    ctx->pc = 0x13a578u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
label_13a57c:
    // 0x13a57c: 0xdfb00010
    ctx->pc = 0x13a57cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13a580: 0xdfb10018
    ctx->pc = 0x13a580u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13a584: 0xdfb20020
    ctx->pc = 0x13a584u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x13a588: 0xdfb30028
    ctx->pc = 0x13a588u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x13a58c: 0xdfb40030
    ctx->pc = 0x13a58cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x13a590: 0xdfb50038
    ctx->pc = 0x13a590u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x13a594: 0xdfb60040
    ctx->pc = 0x13a594u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x13a598: 0xdfb70048
    ctx->pc = 0x13a598u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x13a59c: 0xdfbe0050
    ctx->pc = 0x13a59cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x13a5a0: 0xdfbf0058
    ctx->pc = 0x13a5a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x13a5a4: 0x3e00008
    ctx->pc = 0x13A5A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13A5A8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13A488u: goto label_13a488;
            case 0x13A49Cu: goto label_13a49c;
            case 0x13A4B0u: goto label_13a4b0;
            case 0x13A4B8u: goto label_13a4b8;
            case 0x13A4CCu: goto label_13a4cc;
            case 0x13A4D4u: goto label_13a4d4;
            case 0x13A4ECu: goto label_13a4ec;
            case 0x13A4F0u: goto label_13a4f0;
            case 0x13A514u: goto label_13a514;
            case 0x13A52Cu: goto label_13a52c;
            case 0x13A550u: goto label_13a550;
            case 0x13A57Cu: goto label_13a57c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13A5ACu;
    // 0x13a5ac: 0x0
    ctx->pc = 0x13a5acu;
    // NOP
}
