#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00187FF8
// Address: 0x187ff8 - 0x188138
void sub_00187FF8_0x187ff8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x187ff8u;

    // 0x187ff8: 0x27bdffa0
    ctx->pc = 0x187ff8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x187ffc: 0xffb20020
    ctx->pc = 0x187ffcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x188000: 0x80902d
    ctx->pc = 0x188000u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188004: 0xffb60040
    ctx->pc = 0x188004u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x188008: 0x12b0c0
    ctx->pc = 0x188008u;
    SET_GPR_U32(ctx, 22, SLL32(GPR_U32(ctx, 18), 3));
    // 0x18800c: 0xffbe0050
    ctx->pc = 0x18800cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x188010: 0x3c1e0029
    ctx->pc = 0x188010u;
    SET_GPR_U32(ctx, 30, ((uint32_t)41 << 16));
    // 0x188014: 0x27c2b8c8
    ctx->pc = 0x188014u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 30), 4294949064));
    // 0x188018: 0x2d21823
    ctx->pc = 0x188018u;
    SET_GPR_U32(ctx, 3, SUB32(GPR_U32(ctx, 22), GPR_U32(ctx, 18)));
    // 0x18801c: 0xffb10018
    ctx->pc = 0x18801cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x188020: 0x31880
    ctx->pc = 0x188020u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 2));
    // 0x188024: 0xffb70048
    ctx->pc = 0x188024u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x188028: 0xa0b82d
    ctx->pc = 0x188028u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18802c: 0xffb00010
    ctx->pc = 0x18802cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x188030: 0x24420004
    ctx->pc = 0x188030u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4));
    // 0x188034: 0xffb30028
    ctx->pc = 0x188034u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x188038: 0x628821
    ctx->pc = 0x188038u;
    SET_GPR_U32(ctx, 17, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x18803c: 0xffb40030
    ctx->pc = 0x18803cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x188040: 0xffb50038
    ctx->pc = 0x188040u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x188044: 0xffbf0058
    ctx->pc = 0x188044u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x188048: 0xc0623b6
    ctx->pc = 0x188048u;
    SET_GPR_U32(ctx, 31, 0x188050u);
    ctx->pc = 0x18804Cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    ctx->pc = 0x188ED8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00188ED8_0x188ed8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188050u; }
    }
    if (ctx->pc != 0x188050u) { return; }
    ctx->pc = 0x188050u;
    // 0x188050: 0x24030003
    ctx->pc = 0x188050u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 3));
    // 0x188054: 0x14430004
    ctx->pc = 0x188054u;
    {
        const bool branch_taken_0x188054 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        ctx->pc = 0x188058u;
        SET_GPR_U32(ctx, 21, ((uint32_t)41 << 16));
        if (branch_taken_0x188054) {
            ctx->pc = 0x188068u;
            goto label_188068;
        }
    }
    ctx->pc = 0x18805Cu;
    // 0x18805c: 0x1000002a
    ctx->pc = 0x18805Cu;
    {
        const bool branch_taken_0x18805c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x188060u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x18805c) {
            ctx->pc = 0x188108u;
            goto label_188108;
        }
    }
    ctx->pc = 0x188064u;
    // 0x188064: 0x0
    ctx->pc = 0x188064u;
    // NOP
label_188068:
    // 0x188068: 0x282d
    ctx->pc = 0x188068u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18806c: 0x26a4b900
    ctx->pc = 0x18806cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 21), 4294949120));
    // 0x188070: 0xc041f1a
    ctx->pc = 0x188070u;
    SET_GPR_U32(ctx, 31, 0x188078u);
    ctx->pc = 0x188074u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 8320));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188078u; }
    }
    if (ctx->pc != 0x188078u) { return; }
    ctx->pc = 0x188078u;
    // 0x188078: 0x3c040029
    ctx->pc = 0x188078u;
    SET_GPR_U32(ctx, 4, ((uint32_t)41 << 16));
    // 0x18807c: 0x24022080
    ctx->pc = 0x18807cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 8320));
    // 0x188080: 0x2484d980
    ctx->pc = 0x188080u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294957440));
    // 0x188084: 0x282d
    ctx->pc = 0x188084u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x188088: 0x24060100
    ctx->pc = 0x188088u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 256));
    // 0x18808c: 0xc041f1a
    ctx->pc = 0x18808Cu;
    SET_GPR_U32(ctx, 31, 0x188094u);
    ctx->pc = 0x188090u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x188094u; }
    }
    if (ctx->pc != 0x188094u) { return; }
    ctx->pc = 0x188094u;
    // 0x188094: 0x3c100023
    ctx->pc = 0x188094u;
    SET_GPR_U32(ctx, 16, ((uint32_t)35 << 16));
    // 0x188098: 0x2402000a
    ctx->pc = 0x188098u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 10));
    // 0x18809c: 0xae02fd24
    ctx->pc = 0x18809cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294966564), GPR_U32(ctx, 2));
    // 0x1880a0: 0x3c140018
    ctx->pc = 0x1880a0u;
    SET_GPR_U32(ctx, 20, ((uint32_t)24 << 16));
    // 0x1880a4: 0x24130001
    ctx->pc = 0x1880a4u;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1880a8: 0x8e240000
    ctx->pc = 0x1880a8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1880ac: 0x0
    ctx->pc = 0x1880acu;
    // NOP
label_1880b0:
    // 0x1880b0: 0x3a0302d
    ctx->pc = 0x1880b0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1880b4: 0x8e05fd24
    ctx->pc = 0x1880b4u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 4294966564)));
    // 0x1880b8: 0x26a7b900
    ctx->pc = 0x1880b8u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 21), 4294949120));
    // 0x1880bc: 0xc062560
    ctx->pc = 0x1880BCu;
    SET_GPR_U32(ctx, 31, 0x1880C4u);
    ctx->pc = 0x1880C0u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 20), 30728));
    ctx->pc = 0x189580u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00189580_0x189580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1880C4u; }
    }
    if (ctx->pc != 0x1880C4u) { return; }
    ctx->pc = 0x1880C4u;
    // 0x1880c4: 0x5453fffa
    ctx->pc = 0x1880C4u;
    {
        const bool branch_taken_0x1880c4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 19));
        if (branch_taken_0x1880c4) {
            ctx->pc = 0x1880C8u;
            SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
            ctx->pc = 0x1880B0u;
            goto label_1880b0;
        }
    }
    ctx->pc = 0x1880CCu;
    // 0x1880cc: 0x2d21023
    ctx->pc = 0x1880ccu;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 22), GPR_U32(ctx, 18)));
    // 0x1880d0: 0x27c3b8c8
    ctx->pc = 0x1880d0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 30), 4294949064));
    // 0x1880d4: 0x21080
    ctx->pc = 0x1880d4u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 2));
    // 0x1880d8: 0x621821
    ctx->pc = 0x1880d8u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1880dc: 0xc061db2
    ctx->pc = 0x1880DCu;
    SET_GPR_U32(ctx, 31, 0x1880E4u);
    ctx->pc = 0x1880E0u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 3), 4)));
    ctx->pc = 0x1876C8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001876C8_0x1876c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1880E4u; }
    }
    if (ctx->pc != 0x1880E4u) { return; }
    ctx->pc = 0x1880E4u;
    // 0x1880e4: 0x40202d
    ctx->pc = 0x1880e4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1880e8: 0x8c830008
    ctx->pc = 0x1880e8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x1880ec: 0x10600006
    ctx->pc = 0x1880ECu;
    {
        const bool branch_taken_0x1880ec = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x1880F0u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1880ec) {
            ctx->pc = 0x188108u;
            goto label_188108;
        }
    }
    ctx->pc = 0x1880F4u;
    // 0x1880f4: 0x68820013
    ctx->pc = 0x1880f4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 19); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & ~mask) | ((aligned_data << shift) & mask)); }
    // 0x1880f8: 0x6c82000c
    ctx->pc = 0x1880f8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 12); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 2, (GPR_U64(ctx, 2) & ~mask) | ((aligned_data >> shift) & mask)); }
    // 0x1880fc: 0xb2e20007
    ctx->pc = 0x1880fcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 23), 7); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 2) >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188100: 0xb6e20000
    ctx->pc = 0x188100u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 23), 0); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 2) << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x188104: 0x8c820008
    ctx->pc = 0x188104u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 8)));
label_188108:
    // 0x188108: 0xdfb00010
    ctx->pc = 0x188108u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18810c: 0xdfb10018
    ctx->pc = 0x18810cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x188110: 0xdfb20020
    ctx->pc = 0x188110u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x188114: 0xdfb30028
    ctx->pc = 0x188114u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x188118: 0xdfb40030
    ctx->pc = 0x188118u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18811c: 0xdfb50038
    ctx->pc = 0x18811cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x188120: 0xdfb60040
    ctx->pc = 0x188120u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x188124: 0xdfb70048
    ctx->pc = 0x188124u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x188128: 0xdfbe0050
    ctx->pc = 0x188128u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x18812c: 0xdfbf0058
    ctx->pc = 0x18812cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x188130: 0x3e00008
    ctx->pc = 0x188130u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x188134u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x188068u: goto label_188068;
            case 0x1880B0u: goto label_1880b0;
            case 0x188108u: goto label_188108;
            default: break;
        }
        return;
    }
    ctx->pc = 0x188138u;
}
