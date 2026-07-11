#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: entry_178440
// Address: 0x178440 - 0x1785a0
void entry_178440_0x1785a0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x178440u;

    // 0x178440: 0x3c030024
    ctx->pc = 0x178440u;
    SET_GPR_U32(ctx, 3, ((uint32_t)36 << 16));
    // 0x178444: 0x27bdfec0
    ctx->pc = 0x178444u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294966976));
    // 0x178448: 0x24630b60
    ctx->pc = 0x178448u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 2912));
    // 0x17844c: 0xffb00120
    ctx->pc = 0x17844cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 288), GPR_U64(ctx, 16));
    // 0x178450: 0x30620007
    ctx->pc = 0x178450u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), 7));
    // 0x178454: 0xffb10128
    ctx->pc = 0x178454u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 296), GPR_U64(ctx, 17));
    // 0x178458: 0xffbf0130
    ctx->pc = 0x178458u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 304), GPR_U64(ctx, 31));
    // 0x17845c: 0x1040001a
    ctx->pc = 0x17845Cu;
    {
        const bool branch_taken_0x17845c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x178460u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x17845c) {
            ctx->pc = 0x1784C8u;
            goto label_1784c8;
        }
    }
    ctx->pc = 0x178464u;
    // 0x178464: 0x24620100
    ctx->pc = 0x178464u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 3), 256));
label_178468:
    // 0x178468: 0x68650007
    ctx->pc = 0x178468u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & ~mask) | ((aligned_data << shift) & mask)); }
    // 0x17846c: 0x6c650000
    ctx->pc = 0x17846cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & ~mask) | ((aligned_data >> shift) & mask)); }
    // 0x178470: 0x6866000f
    ctx->pc = 0x178470u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & ~mask) | ((aligned_data << shift) & mask)); }
    // 0x178474: 0x6c660008
    ctx->pc = 0x178474u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & ~mask) | ((aligned_data >> shift) & mask)); }
    // 0x178478: 0x68670017
    ctx->pc = 0x178478u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 23); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & ~mask) | ((aligned_data << shift) & mask)); }
    // 0x17847c: 0x6c670010
    ctx->pc = 0x17847cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 16); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 7, (GPR_U64(ctx, 7) & ~mask) | ((aligned_data >> shift) & mask)); }
    // 0x178480: 0x6868001f
    ctx->pc = 0x178480u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 31); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & ~mask) | ((aligned_data << shift) & mask)); }
    // 0x178484: 0x6c680018
    ctx->pc = 0x178484u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 24); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 8, (GPR_U64(ctx, 8) & ~mask) | ((aligned_data >> shift) & mask)); }
    // 0x178488: 0xb0850007
    ctx->pc = 0x178488u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 5) >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x17848c: 0xb4850000
    ctx->pc = 0x17848cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 5) << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x178490: 0xb086000f
    ctx->pc = 0x178490u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 6) >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x178494: 0xb4860008
    ctx->pc = 0x178494u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 6) << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x178498: 0xb0870017
    ctx->pc = 0x178498u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 23); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 7) >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x17849c: 0xb4870010
    ctx->pc = 0x17849cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 16); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 7) << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1784a0: 0xb088001f
    ctx->pc = 0x1784a0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 31); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 8) >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1784a4: 0xb4880018
    ctx->pc = 0x1784a4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 24); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 8) << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x1784a8: 0x24630020
    ctx->pc = 0x1784a8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 32));
    // 0x1784ac: 0x0
    ctx->pc = 0x1784acu;
    // NOP
    // 0x1784b0: 0x0
    ctx->pc = 0x1784b0u;
    // NOP
    // 0x1784b4: 0x1462ffec
    ctx->pc = 0x1784B4u;
    {
        const bool branch_taken_0x1784b4 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x1784B8u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 32));
        if (branch_taken_0x1784b4) {
            ctx->pc = 0x178468u;
            goto label_178468;
        }
    }
    ctx->pc = 0x1784BCu;
    // 0x1784bc: 0x10000010
    ctx->pc = 0x1784BCu;
    {
        const bool branch_taken_0x1784bc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1784bc) {
            ctx->pc = 0x178500u;
            goto label_178500;
        }
    }
    ctx->pc = 0x1784C4u;
    // 0x1784c4: 0x0
    ctx->pc = 0x1784c4u;
    // NOP
label_1784c8:
    // 0x1784c8: 0x24620100
    ctx->pc = 0x1784c8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 3), 256));
label_1784cc:
    // 0x1784cc: 0xdc650000
    ctx->pc = 0x1784ccu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1784d0: 0xdc660008
    ctx->pc = 0x1784d0u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 3), 8)));
    // 0x1784d4: 0xdc670010
    ctx->pc = 0x1784d4u;
    SET_GPR_U64(ctx, 7, READ64(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x1784d8: 0xdc680018
    ctx->pc = 0x1784d8u;
    SET_GPR_U64(ctx, 8, READ64(ADD32(GPR_U32(ctx, 3), 24)));
    // 0x1784dc: 0xfc850000
    ctx->pc = 0x1784dcu;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 5));
    // 0x1784e0: 0xfc860008
    ctx->pc = 0x1784e0u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 8), GPR_U64(ctx, 6));
    // 0x1784e4: 0xfc870010
    ctx->pc = 0x1784e4u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 16), GPR_U64(ctx, 7));
    // 0x1784e8: 0xfc880018
    ctx->pc = 0x1784e8u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 24), GPR_U64(ctx, 8));
    // 0x1784ec: 0x24630020
    ctx->pc = 0x1784ecu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 32));
    // 0x1784f0: 0x0
    ctx->pc = 0x1784f0u;
    // NOP
    // 0x1784f4: 0x0
    ctx->pc = 0x1784f4u;
    // NOP
    // 0x1784f8: 0x1462fff4
    ctx->pc = 0x1784F8u;
    {
        const bool branch_taken_0x1784f8 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x1784FCu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 32));
        if (branch_taken_0x1784f8) {
            ctx->pc = 0x1784CCu;
            goto label_1784cc;
        }
    }
    ctx->pc = 0x178500u;
label_178500:
    // 0x178500: 0x68650007
    ctx->pc = 0x178500u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 7); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & ~mask) | ((aligned_data << shift) & mask)); }
    // 0x178504: 0x6c650000
    ctx->pc = 0x178504u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 0); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & ~mask) | ((aligned_data >> shift) & mask)); }
    // 0x178508: 0x6866000f
    ctx->pc = 0x178508u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 15); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & ~mask) | ((aligned_data << shift) & mask)); }
    // 0x17850c: 0x6c660008
    ctx->pc = 0x17850cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 3), 8); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & ~mask) | ((aligned_data >> shift) & mask)); }
    // 0x178510: 0x80670010
    ctx->pc = 0x178510u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 16)));
    // 0x178514: 0x80680011
    ctx->pc = 0x178514u;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 3), 17)));
    // 0x178518: 0xb0850007
    ctx->pc = 0x178518u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 7); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 5) >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x17851c: 0xb4850000
    ctx->pc = 0x17851cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 0); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 5) << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x178520: 0xb086000f
    ctx->pc = 0x178520u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 15); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 6) >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x178524: 0xb4860008
    ctx->pc = 0x178524u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 4), 8); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 6) << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x178528: 0xa0870010
    ctx->pc = 0x178528u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 16), (uint8_t)GPR_U32(ctx, 7));
    // 0x17852c: 0x3c020023
    ctx->pc = 0x17852cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x178530: 0x2451f1dc
    ctx->pc = 0x178530u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 2), 4294963676));
    // 0x178534: 0xa0880011
    ctx->pc = 0x178534u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 17), (uint8_t)GPR_U32(ctx, 8));
    // 0x178538: 0x8e240000
    ctx->pc = 0x178538u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17853c: 0x10800012
    ctx->pc = 0x17853Cu;
    {
        const bool branch_taken_0x17853c = (GPR_U32(ctx, 4) == GPR_U32(ctx, 0));
        ctx->pc = 0x178540u;
        SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
        if (branch_taken_0x17853c) {
            ctx->pc = 0x178588u;
            goto label_178588;
        }
    }
    ctx->pc = 0x178544u;
    // 0x178544: 0x282d
    ctx->pc = 0x178544u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178548: 0x8c46f1d8
    ctx->pc = 0x178548u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 2), 4294963672)));
    // 0x17854c: 0x3c100023
    ctx->pc = 0x17854cu;
    SET_GPR_U32(ctx, 16, ((uint32_t)35 << 16));
    // 0x178550: 0xc041f1a
    ctx->pc = 0x178550u;
    SET_GPR_U32(ctx, 31, 0x178558u);
    ctx->pc = 0x178554u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 4294963684));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178558u; }
    }
    if (ctx->pc != 0x178558u) { return; }
    ctx->pc = 0x178558u;
    // 0x178558: 0x8e220000
    ctx->pc = 0x178558u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x17855c: 0x3a0282d
    ctx->pc = 0x17855cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178560: 0x0
    ctx->pc = 0x178560u;
    // NOP
    // 0x178564: 0xc042bf0
    ctx->pc = 0x178564u;
    SET_GPR_U32(ctx, 31, 0x17856Cu);
    ctx->pc = 0x178568u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10AFC0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17856Cu; }
    }
    if (ctx->pc != 0x17856Cu) { return; }
    ctx->pc = 0x17856Cu;
    // 0x17856c: 0xc042c56
    ctx->pc = 0x17856Cu;
    SET_GPR_U32(ctx, 31, 0x178574u);
    ctx->pc = 0x178570u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10B158u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178574u; }
    }
    if (ctx->pc != 0x178574u) { return; }
    ctx->pc = 0x178574u;
    // 0x178574: 0x8e030000
    ctx->pc = 0x178574u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x178578: 0x3c040023
    ctx->pc = 0x178578u;
    SET_GPR_U32(ctx, 4, ((uint32_t)35 << 16));
    // 0x17857c: 0x621821
    ctx->pc = 0x17857cu;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x178580: 0xac83f1e8
    ctx->pc = 0x178580u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4294963688), GPR_U32(ctx, 3));
    // 0x178584: 0xae030000
    ctx->pc = 0x178584u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
label_178588:
    // 0x178588: 0xdfb00120
    ctx->pc = 0x178588u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 288)));
    // 0x17858c: 0xdfb10128
    ctx->pc = 0x17858cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 296)));
    // 0x178590: 0xdfbf0130
    ctx->pc = 0x178590u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 304)));
    // 0x178594: 0x3e00008
    ctx->pc = 0x178594u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x178598u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 320));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x178468u: goto label_178468;
            case 0x1784C8u: goto label_1784c8;
            case 0x1784CCu: goto label_1784cc;
            case 0x178500u: goto label_178500;
            case 0x178588u: goto label_178588;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17859Cu;
    // 0x17859c: 0x0
    ctx->pc = 0x17859cu;
    // NOP
}
