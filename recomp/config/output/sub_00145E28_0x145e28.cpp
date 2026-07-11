#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00145E28
// Address: 0x145e28 - 0x146140
void sub_00145E28_0x145e28(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x145e28u;

label_145e28:
    // 0x145e28: 0x27bdff80
    ctx->pc = 0x145e28u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967168));
label_145e2c:
    // 0x145e2c: 0x3c020024
    ctx->pc = 0x145e2cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)36 << 16));
label_145e30:
    // 0x145e30: 0xffb00030
    ctx->pc = 0x145e30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
label_145e34:
    // 0x145e34: 0xffb30060
    ctx->pc = 0x145e34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 19));
label_145e38:
    // 0x145e38: 0x80802d
    ctx->pc = 0x145e38u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_145e3c:
    // 0x145e3c: 0xffb20050
    ctx->pc = 0x145e3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 18));
label_145e40:
    // 0x145e40: 0xffb10040
    ctx->pc = 0x145e40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 17));
label_145e44:
    // 0x145e44: 0x241301b2
    ctx->pc = 0x145e44u;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 0), 434));
label_145e48:
    // 0x145e48: 0xffbf0070
    ctx->pc = 0x145e48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
label_145e4c:
    // 0x145e4c: 0x241101b5
    ctx->pc = 0x145e4cu;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 0), 437));
label_145e50:
    // 0x145e50: 0x2447def8
    ctx->pc = 0x145e50u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 2), 4294958840));
label_145e54:
    // 0x145e54: 0x68e30007
    ctx->pc = 0x145e54u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 7); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & ~mask) | ((aligned_data << shift) & mask)); }
label_145e58:
    // 0x145e58: 0x6ce30000
    ctx->pc = 0x145e58u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 0); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & ~mask) | ((aligned_data >> shift) & mask)); }
label_145e5c:
    // 0x145e5c: 0x68e5000f
    ctx->pc = 0x145e5cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 15); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & ~mask) | ((aligned_data << shift) & mask)); }
label_145e60:
    // 0x145e60: 0x6ce50008
    ctx->pc = 0x145e60u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 8); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & ~mask) | ((aligned_data >> shift) & mask)); }
label_145e64:
    // 0x145e64: 0x68e60017
    ctx->pc = 0x145e64u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 23); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & ~mask) | ((aligned_data << shift) & mask)); }
label_145e68:
    // 0x145e68: 0x6ce60010
    ctx->pc = 0x145e68u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 16); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & ~mask) | ((aligned_data >> shift) & mask)); }
label_145e6c:
    // 0x145e6c: 0xb3a30007
    ctx->pc = 0x145e6cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 7); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 3) >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_145e70:
    // 0x145e70: 0xb7a30000
    ctx->pc = 0x145e70u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 0); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 3) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_145e74:
    // 0x145e74: 0xb3a5000f
    ctx->pc = 0x145e74u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 15); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 5) >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_145e78:
    // 0x145e78: 0xb7a50008
    ctx->pc = 0x145e78u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 8); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 5) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_145e7c:
    // 0x145e7c: 0xb3a60017
    ctx->pc = 0x145e7cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 23); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 6) >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_145e80:
    // 0x145e80: 0xb7a60010
    ctx->pc = 0x145e80u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 16); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 6) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_145e84:
    // 0x145e84: 0x68e3001f
    ctx->pc = 0x145e84u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 31); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & ~mask) | ((aligned_data << shift) & mask)); }
label_145e88:
    // 0x145e88: 0x6ce30018
    ctx->pc = 0x145e88u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 24); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & ~mask) | ((aligned_data >> shift) & mask)); }
label_145e8c:
    // 0x145e8c: 0x68e50027
    ctx->pc = 0x145e8cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 39); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & ~mask) | ((aligned_data << shift) & mask)); }
label_145e90:
    // 0x145e90: 0x6ce50020
    ctx->pc = 0x145e90u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 7), 32); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 5, (GPR_U64(ctx, 5) & ~mask) | ((aligned_data >> shift) & mask)); }
label_145e94:
    // 0x145e94: 0x8ce60028
    ctx->pc = 0x145e94u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 7), 40)));
label_145e98:
    // 0x145e98: 0xb3a3001f
    ctx->pc = 0x145e98u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 31); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 3) >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_145e9c:
    // 0x145e9c: 0xb7a30018
    ctx->pc = 0x145e9cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 24); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 3) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_145ea0:
    // 0x145ea0: 0xb3a50027
    ctx->pc = 0x145ea0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 39); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 5) >> shift) & mask); WRITE64(aligned_addr, new_data); }
label_145ea4:
    // 0x145ea4: 0xb7a50020
    ctx->pc = 0x145ea4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 29), 32); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 5) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_145ea8:
    // 0x145ea8: 0xafa60028
    ctx->pc = 0x145ea8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 40), GPR_U32(ctx, 6));
label_145eac:
    // 0x145eac: 0xc0516d6
label_145eb0:
    if (ctx->pc == 0x145EB0u) {
        ctx->pc = 0x145EB0u;
        SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 0), 10));
        ctx->pc = 0x145EB4u;
        goto label_145eb4;
    }
    ctx->pc = 0x145EACu;
    SET_GPR_U32(ctx, 31, 0x145EB4u);
    ctx->pc = 0x145EB0u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 0), 10));
    ctx->pc = 0x145B58u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00145B58_0x145b58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145EB4u; }
    }
    if (ctx->pc != 0x145EB4u) { return; }
    ctx->pc = 0x145EB4u;
label_145eb4:
    // 0x145eb4: 0x10000019
label_145eb8:
    if (ctx->pc == 0x145EB8u) {
        ctx->pc = 0x145EB8u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x145EBCu;
        goto label_145ebc;
    }
    ctx->pc = 0x145EB4u;
    {
        const bool branch_taken_0x145eb4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x145EB8u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x145eb4) {
            ctx->pc = 0x145F1Cu;
            goto label_145f1c;
        }
    }
    ctx->pc = 0x145EBCu;
label_145ebc:
    // 0x145ebc: 0x0
    ctx->pc = 0x145ebcu;
    // NOP
label_145ec0:
    // 0x145ec0: 0x54510011
label_145ec4:
    if (ctx->pc == 0x145EC4u) {
        ctx->pc = 0x145EC4u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x145EC8u;
        goto label_145ec8;
    }
    ctx->pc = 0x145EC0u;
    {
        const bool branch_taken_0x145ec0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 17));
        if (branch_taken_0x145ec0) {
            ctx->pc = 0x145EC4u;
            SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
            ctx->pc = 0x145F08u;
            goto label_145f08;
        }
    }
    ctx->pc = 0x145EC8u;
label_145ec8:
    // 0x145ec8: 0xc051636
label_145ecc:
    if (ctx->pc == 0x145ECCu) {
        ctx->pc = 0x145ED0u;
        goto label_145ed0;
    }
    ctx->pc = 0x145EC8u;
    SET_GPR_U32(ctx, 31, 0x145ED0u);
    ctx->pc = 0x1458D8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001458D8_0x1458d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145ED0u; }
    }
    if (ctx->pc != 0x145ED0u) { return; }
    ctx->pc = 0x145ED0u;
label_145ed0:
    // 0x145ed0: 0x200202d
    ctx->pc = 0x145ed0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_145ed4:
    // 0x145ed4: 0xc05167a
label_145ed8:
    if (ctx->pc == 0x145ED8u) {
        ctx->pc = 0x145ED8u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4));
        ctx->pc = 0x145EDCu;
        goto label_145edc;
    }
    ctx->pc = 0x145ED4u;
    SET_GPR_U32(ctx, 31, 0x145EDCu);
    ctx->pc = 0x145ED8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145EDCu; }
    }
    if (ctx->pc != 0x145EDCu) { return; }
    ctx->pc = 0x145EDCu;
label_145edc:
    // 0x145edc: 0x242182b
    ctx->pc = 0x145edcu;
    SET_GPR_U32(ctx, 3, SLTU32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
label_145ee0:
    // 0x145ee0: 0x3100b
    ctx->pc = 0x145ee0u;
    if (GPR_U32(ctx, 3) != 0) SET_GPR_U32(ctx, 2, GPR_U32(ctx, 0));
label_145ee4:
    // 0x145ee4: 0x21080
    ctx->pc = 0x145ee4u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 2));
label_145ee8:
    // 0x145ee8: 0x3a21821
    ctx->pc = 0x145ee8u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 29), GPR_U32(ctx, 2)));
label_145eec:
    // 0x145eec: 0x8c620000
    ctx->pc = 0x145eecu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_145ef0:
    // 0x145ef0: 0x40f809
label_145ef4:
    if (ctx->pc == 0x145EF4u) {
        ctx->pc = 0x145EF4u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x145EF8u;
        goto label_145ef8;
    }
    ctx->pc = 0x145EF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x145EF8u);
        ctx->pc = 0x145EF4u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x145E28u: goto label_145e28;
            case 0x145E2Cu: goto label_145e2c;
            case 0x145E30u: goto label_145e30;
            case 0x145E34u: goto label_145e34;
            case 0x145E38u: goto label_145e38;
            case 0x145E3Cu: goto label_145e3c;
            case 0x145E40u: goto label_145e40;
            case 0x145E44u: goto label_145e44;
            case 0x145E48u: goto label_145e48;
            case 0x145E4Cu: goto label_145e4c;
            case 0x145E50u: goto label_145e50;
            case 0x145E54u: goto label_145e54;
            case 0x145E58u: goto label_145e58;
            case 0x145E5Cu: goto label_145e5c;
            case 0x145E60u: goto label_145e60;
            case 0x145E64u: goto label_145e64;
            case 0x145E68u: goto label_145e68;
            case 0x145E6Cu: goto label_145e6c;
            case 0x145E70u: goto label_145e70;
            case 0x145E74u: goto label_145e74;
            case 0x145E78u: goto label_145e78;
            case 0x145E7Cu: goto label_145e7c;
            case 0x145E80u: goto label_145e80;
            case 0x145E84u: goto label_145e84;
            case 0x145E88u: goto label_145e88;
            case 0x145E8Cu: goto label_145e8c;
            case 0x145E90u: goto label_145e90;
            case 0x145E94u: goto label_145e94;
            case 0x145E98u: goto label_145e98;
            case 0x145E9Cu: goto label_145e9c;
            case 0x145EA0u: goto label_145ea0;
            case 0x145EA4u: goto label_145ea4;
            case 0x145EA8u: goto label_145ea8;
            case 0x145EACu: goto label_145eac;
            case 0x145EB0u: goto label_145eb0;
            case 0x145EB4u: goto label_145eb4;
            case 0x145EB8u: goto label_145eb8;
            case 0x145EBCu: goto label_145ebc;
            case 0x145EC0u: goto label_145ec0;
            case 0x145EC4u: goto label_145ec4;
            case 0x145EC8u: goto label_145ec8;
            case 0x145ECCu: goto label_145ecc;
            case 0x145ED0u: goto label_145ed0;
            case 0x145ED4u: goto label_145ed4;
            case 0x145ED8u: goto label_145ed8;
            case 0x145EDCu: goto label_145edc;
            case 0x145EE0u: goto label_145ee0;
            case 0x145EE4u: goto label_145ee4;
            case 0x145EE8u: goto label_145ee8;
            case 0x145EECu: goto label_145eec;
            case 0x145EF0u: goto label_145ef0;
            case 0x145EF4u: goto label_145ef4;
            case 0x145EF8u: goto label_145ef8;
            case 0x145EFCu: goto label_145efc;
            case 0x145F00u: goto label_145f00;
            case 0x145F04u: goto label_145f04;
            case 0x145F08u: goto label_145f08;
            case 0x145F0Cu: goto label_145f0c;
            case 0x145F10u: goto label_145f10;
            case 0x145F14u: goto label_145f14;
            case 0x145F18u: goto label_145f18;
            case 0x145F1Cu: goto label_145f1c;
            case 0x145F20u: goto label_145f20;
            case 0x145F24u: goto label_145f24;
            case 0x145F28u: goto label_145f28;
            case 0x145F2Cu: goto label_145f2c;
            case 0x145F30u: goto label_145f30;
            case 0x145F34u: goto label_145f34;
            case 0x145F38u: goto label_145f38;
            case 0x145F3Cu: goto label_145f3c;
            case 0x145F40u: goto label_145f40;
            case 0x145F44u: goto label_145f44;
            case 0x145F48u: goto label_145f48;
            case 0x145F4Cu: goto label_145f4c;
            case 0x145F50u: goto label_145f50;
            case 0x145F54u: goto label_145f54;
            case 0x145F58u: goto label_145f58;
            case 0x145F5Cu: goto label_145f5c;
            case 0x145F60u: goto label_145f60;
            case 0x145F64u: goto label_145f64;
            case 0x145F68u: goto label_145f68;
            case 0x145F6Cu: goto label_145f6c;
            case 0x145F70u: goto label_145f70;
            case 0x145F74u: goto label_145f74;
            case 0x145F78u: goto label_145f78;
            case 0x145F7Cu: goto label_145f7c;
            case 0x145F80u: goto label_145f80;
            case 0x145F84u: goto label_145f84;
            case 0x145F88u: goto label_145f88;
            case 0x145F8Cu: goto label_145f8c;
            case 0x145F90u: goto label_145f90;
            case 0x145F94u: goto label_145f94;
            case 0x145F98u: goto label_145f98;
            case 0x145F9Cu: goto label_145f9c;
            case 0x145FA0u: goto label_145fa0;
            case 0x145FA4u: goto label_145fa4;
            case 0x145FA8u: goto label_145fa8;
            case 0x145FACu: goto label_145fac;
            case 0x145FB0u: goto label_145fb0;
            case 0x145FB4u: goto label_145fb4;
            case 0x145FB8u: goto label_145fb8;
            case 0x145FBCu: goto label_145fbc;
            case 0x145FC0u: goto label_145fc0;
            case 0x145FC4u: goto label_145fc4;
            case 0x145FC8u: goto label_145fc8;
            case 0x145FCCu: goto label_145fcc;
            case 0x145FD0u: goto label_145fd0;
            case 0x145FD4u: goto label_145fd4;
            case 0x145FD8u: goto label_145fd8;
            case 0x145FDCu: goto label_145fdc;
            case 0x145FE0u: goto label_145fe0;
            case 0x145FE4u: goto label_145fe4;
            case 0x145FE8u: goto label_145fe8;
            case 0x145FECu: goto label_145fec;
            case 0x145FF0u: goto label_145ff0;
            case 0x145FF4u: goto label_145ff4;
            case 0x145FF8u: goto label_145ff8;
            case 0x145FFCu: goto label_145ffc;
            case 0x146000u: goto label_146000;
            case 0x146004u: goto label_146004;
            case 0x146008u: goto label_146008;
            case 0x14600Cu: goto label_14600c;
            case 0x146010u: goto label_146010;
            case 0x146014u: goto label_146014;
            case 0x146018u: goto label_146018;
            case 0x14601Cu: goto label_14601c;
            case 0x146020u: goto label_146020;
            case 0x146024u: goto label_146024;
            case 0x146028u: goto label_146028;
            case 0x14602Cu: goto label_14602c;
            case 0x146030u: goto label_146030;
            case 0x146034u: goto label_146034;
            case 0x146038u: goto label_146038;
            case 0x14603Cu: goto label_14603c;
            case 0x146040u: goto label_146040;
            case 0x146044u: goto label_146044;
            case 0x146048u: goto label_146048;
            case 0x14604Cu: goto label_14604c;
            case 0x146050u: goto label_146050;
            case 0x146054u: goto label_146054;
            case 0x146058u: goto label_146058;
            case 0x14605Cu: goto label_14605c;
            case 0x146060u: goto label_146060;
            case 0x146064u: goto label_146064;
            case 0x146068u: goto label_146068;
            case 0x14606Cu: goto label_14606c;
            case 0x146070u: goto label_146070;
            case 0x146074u: goto label_146074;
            case 0x146078u: goto label_146078;
            case 0x14607Cu: goto label_14607c;
            case 0x146080u: goto label_146080;
            case 0x146084u: goto label_146084;
            case 0x146088u: goto label_146088;
            case 0x14608Cu: goto label_14608c;
            case 0x146090u: goto label_146090;
            case 0x146094u: goto label_146094;
            case 0x146098u: goto label_146098;
            case 0x14609Cu: goto label_14609c;
            case 0x1460A0u: goto label_1460a0;
            case 0x1460A4u: goto label_1460a4;
            case 0x1460A8u: goto label_1460a8;
            case 0x1460ACu: goto label_1460ac;
            case 0x1460B0u: goto label_1460b0;
            case 0x1460B4u: goto label_1460b4;
            case 0x1460B8u: goto label_1460b8;
            case 0x1460BCu: goto label_1460bc;
            case 0x1460C0u: goto label_1460c0;
            case 0x1460C4u: goto label_1460c4;
            case 0x1460C8u: goto label_1460c8;
            case 0x1460CCu: goto label_1460cc;
            case 0x1460D0u: goto label_1460d0;
            case 0x1460D4u: goto label_1460d4;
            case 0x1460D8u: goto label_1460d8;
            case 0x1460DCu: goto label_1460dc;
            case 0x1460E0u: goto label_1460e0;
            case 0x1460E4u: goto label_1460e4;
            case 0x1460E8u: goto label_1460e8;
            case 0x1460ECu: goto label_1460ec;
            case 0x1460F0u: goto label_1460f0;
            case 0x1460F4u: goto label_1460f4;
            case 0x1460F8u: goto label_1460f8;
            case 0x1460FCu: goto label_1460fc;
            case 0x146100u: goto label_146100;
            case 0x146104u: goto label_146104;
            case 0x146108u: goto label_146108;
            case 0x14610Cu: goto label_14610c;
            case 0x146110u: goto label_146110;
            case 0x146114u: goto label_146114;
            case 0x146118u: goto label_146118;
            case 0x14611Cu: goto label_14611c;
            case 0x146120u: goto label_146120;
            case 0x146124u: goto label_146124;
            case 0x146128u: goto label_146128;
            case 0x14612Cu: goto label_14612c;
            case 0x146130u: goto label_146130;
            case 0x146134u: goto label_146134;
            case 0x146138u: goto label_146138;
            case 0x14613Cu: goto label_14613c;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x145EF8u; }
            if (ctx->pc != 0x145EF8u) { return; }
        }
    }
    ctx->pc = 0x145EF8u;
label_145ef8:
    // 0x145ef8: 0xc0516d6
label_145efc:
    if (ctx->pc == 0x145EFCu) {
        ctx->pc = 0x145EFCu;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x145F00u;
        goto label_145f00;
    }
    ctx->pc = 0x145EF8u;
    SET_GPR_U32(ctx, 31, 0x145F00u);
    ctx->pc = 0x145EFCu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x145B58u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00145B58_0x145b58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145F00u; }
    }
    if (ctx->pc != 0x145F00u) { return; }
    ctx->pc = 0x145F00u;
label_145f00:
    // 0x145f00: 0x10000006
label_145f04:
    if (ctx->pc == 0x145F04u) {
        ctx->pc = 0x145F04u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x145F08u;
        goto label_145f08;
    }
    ctx->pc = 0x145F00u;
    {
        const bool branch_taken_0x145f00 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x145F04u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x145f00) {
            ctx->pc = 0x145F1Cu;
            goto label_145f1c;
        }
    }
    ctx->pc = 0x145F08u;
label_145f08:
    // 0x145f08: 0xc051636
label_145f0c:
    if (ctx->pc == 0x145F0Cu) {
        ctx->pc = 0x145F0Cu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 32));
        ctx->pc = 0x145F10u;
        goto label_145f10;
    }
    ctx->pc = 0x145F08u;
    SET_GPR_U32(ctx, 31, 0x145F10u);
    ctx->pc = 0x145F0Cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 32));
    ctx->pc = 0x1458D8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001458D8_0x1458d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145F10u; }
    }
    if (ctx->pc != 0x145F10u) { return; }
    ctx->pc = 0x145F10u;
label_145f10:
    // 0x145f10: 0xc0516d6
label_145f14:
    if (ctx->pc == 0x145F14u) {
        ctx->pc = 0x145F14u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x145F18u;
        goto label_145f18;
    }
    ctx->pc = 0x145F10u;
    SET_GPR_U32(ctx, 31, 0x145F18u);
    ctx->pc = 0x145F14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x145B58u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00145B58_0x145b58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145F18u; }
    }
    if (ctx->pc != 0x145F18u) { return; }
    ctx->pc = 0x145F18u;
label_145f18:
    // 0x145f18: 0x200202d
    ctx->pc = 0x145f18u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_145f1c:
    // 0x145f1c: 0xc0515ee
label_145f20:
    if (ctx->pc == 0x145F20u) {
        ctx->pc = 0x145F20u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 32));
        ctx->pc = 0x145F24u;
        goto label_145f24;
    }
    ctx->pc = 0x145F1Cu;
    SET_GPR_U32(ctx, 31, 0x145F24u);
    ctx->pc = 0x145F20u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 32));
    ctx->pc = 0x1457B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001457B8_0x1457b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145F24u; }
    }
    if (ctx->pc != 0x145F24u) { return; }
    ctx->pc = 0x145F24u;
label_145f24:
    // 0x145f24: 0x200202d
    ctx->pc = 0x145f24u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_145f28:
    // 0x145f28: 0x1051ffe7
label_145f2c:
    if (ctx->pc == 0x145F2Cu) {
        ctx->pc = 0x145F2Cu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 32));
        ctx->pc = 0x145F30u;
        goto label_145f30;
    }
    ctx->pc = 0x145F28u;
    {
        const bool branch_taken_0x145f28 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 17));
        ctx->pc = 0x145F2Cu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 32));
        if (branch_taken_0x145f28) {
            ctx->pc = 0x145EC8u;
            goto label_145ec8;
        }
    }
    ctx->pc = 0x145F30u;
label_145f30:
    // 0x145f30: 0x1053ffe3
label_145f34:
    if (ctx->pc == 0x145F34u) {
        ctx->pc = 0x145F34u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
        ctx->pc = 0x145F38u;
        goto label_145f38;
    }
    ctx->pc = 0x145F30u;
    {
        const bool branch_taken_0x145f30 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 19));
        ctx->pc = 0x145F34u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
        if (branch_taken_0x145f30) {
            ctx->pc = 0x145EC0u;
            goto label_145ec0;
        }
    }
    ctx->pc = 0x145F38u;
label_145f38:
    // 0x145f38: 0xdfb30060
    ctx->pc = 0x145f38u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 96)));
label_145f3c:
    // 0x145f3c: 0xdfb20050
    ctx->pc = 0x145f3cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 80)));
label_145f40:
    // 0x145f40: 0xdfb10040
    ctx->pc = 0x145f40u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_145f44:
    // 0x145f44: 0xdfb00030
    ctx->pc = 0x145f44u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_145f48:
    // 0x145f48: 0x3e00008
label_145f4c:
    if (ctx->pc == 0x145F4Cu) {
        ctx->pc = 0x145F4Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 128));
        ctx->pc = 0x145F50u;
        goto label_145f50;
    }
    ctx->pc = 0x145F48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x145F4Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 128));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x145E28u: goto label_145e28;
            case 0x145E2Cu: goto label_145e2c;
            case 0x145E30u: goto label_145e30;
            case 0x145E34u: goto label_145e34;
            case 0x145E38u: goto label_145e38;
            case 0x145E3Cu: goto label_145e3c;
            case 0x145E40u: goto label_145e40;
            case 0x145E44u: goto label_145e44;
            case 0x145E48u: goto label_145e48;
            case 0x145E4Cu: goto label_145e4c;
            case 0x145E50u: goto label_145e50;
            case 0x145E54u: goto label_145e54;
            case 0x145E58u: goto label_145e58;
            case 0x145E5Cu: goto label_145e5c;
            case 0x145E60u: goto label_145e60;
            case 0x145E64u: goto label_145e64;
            case 0x145E68u: goto label_145e68;
            case 0x145E6Cu: goto label_145e6c;
            case 0x145E70u: goto label_145e70;
            case 0x145E74u: goto label_145e74;
            case 0x145E78u: goto label_145e78;
            case 0x145E7Cu: goto label_145e7c;
            case 0x145E80u: goto label_145e80;
            case 0x145E84u: goto label_145e84;
            case 0x145E88u: goto label_145e88;
            case 0x145E8Cu: goto label_145e8c;
            case 0x145E90u: goto label_145e90;
            case 0x145E94u: goto label_145e94;
            case 0x145E98u: goto label_145e98;
            case 0x145E9Cu: goto label_145e9c;
            case 0x145EA0u: goto label_145ea0;
            case 0x145EA4u: goto label_145ea4;
            case 0x145EA8u: goto label_145ea8;
            case 0x145EACu: goto label_145eac;
            case 0x145EB0u: goto label_145eb0;
            case 0x145EB4u: goto label_145eb4;
            case 0x145EB8u: goto label_145eb8;
            case 0x145EBCu: goto label_145ebc;
            case 0x145EC0u: goto label_145ec0;
            case 0x145EC4u: goto label_145ec4;
            case 0x145EC8u: goto label_145ec8;
            case 0x145ECCu: goto label_145ecc;
            case 0x145ED0u: goto label_145ed0;
            case 0x145ED4u: goto label_145ed4;
            case 0x145ED8u: goto label_145ed8;
            case 0x145EDCu: goto label_145edc;
            case 0x145EE0u: goto label_145ee0;
            case 0x145EE4u: goto label_145ee4;
            case 0x145EE8u: goto label_145ee8;
            case 0x145EECu: goto label_145eec;
            case 0x145EF0u: goto label_145ef0;
            case 0x145EF4u: goto label_145ef4;
            case 0x145EF8u: goto label_145ef8;
            case 0x145EFCu: goto label_145efc;
            case 0x145F00u: goto label_145f00;
            case 0x145F04u: goto label_145f04;
            case 0x145F08u: goto label_145f08;
            case 0x145F0Cu: goto label_145f0c;
            case 0x145F10u: goto label_145f10;
            case 0x145F14u: goto label_145f14;
            case 0x145F18u: goto label_145f18;
            case 0x145F1Cu: goto label_145f1c;
            case 0x145F20u: goto label_145f20;
            case 0x145F24u: goto label_145f24;
            case 0x145F28u: goto label_145f28;
            case 0x145F2Cu: goto label_145f2c;
            case 0x145F30u: goto label_145f30;
            case 0x145F34u: goto label_145f34;
            case 0x145F38u: goto label_145f38;
            case 0x145F3Cu: goto label_145f3c;
            case 0x145F40u: goto label_145f40;
            case 0x145F44u: goto label_145f44;
            case 0x145F48u: goto label_145f48;
            case 0x145F4Cu: goto label_145f4c;
            case 0x145F50u: goto label_145f50;
            case 0x145F54u: goto label_145f54;
            case 0x145F58u: goto label_145f58;
            case 0x145F5Cu: goto label_145f5c;
            case 0x145F60u: goto label_145f60;
            case 0x145F64u: goto label_145f64;
            case 0x145F68u: goto label_145f68;
            case 0x145F6Cu: goto label_145f6c;
            case 0x145F70u: goto label_145f70;
            case 0x145F74u: goto label_145f74;
            case 0x145F78u: goto label_145f78;
            case 0x145F7Cu: goto label_145f7c;
            case 0x145F80u: goto label_145f80;
            case 0x145F84u: goto label_145f84;
            case 0x145F88u: goto label_145f88;
            case 0x145F8Cu: goto label_145f8c;
            case 0x145F90u: goto label_145f90;
            case 0x145F94u: goto label_145f94;
            case 0x145F98u: goto label_145f98;
            case 0x145F9Cu: goto label_145f9c;
            case 0x145FA0u: goto label_145fa0;
            case 0x145FA4u: goto label_145fa4;
            case 0x145FA8u: goto label_145fa8;
            case 0x145FACu: goto label_145fac;
            case 0x145FB0u: goto label_145fb0;
            case 0x145FB4u: goto label_145fb4;
            case 0x145FB8u: goto label_145fb8;
            case 0x145FBCu: goto label_145fbc;
            case 0x145FC0u: goto label_145fc0;
            case 0x145FC4u: goto label_145fc4;
            case 0x145FC8u: goto label_145fc8;
            case 0x145FCCu: goto label_145fcc;
            case 0x145FD0u: goto label_145fd0;
            case 0x145FD4u: goto label_145fd4;
            case 0x145FD8u: goto label_145fd8;
            case 0x145FDCu: goto label_145fdc;
            case 0x145FE0u: goto label_145fe0;
            case 0x145FE4u: goto label_145fe4;
            case 0x145FE8u: goto label_145fe8;
            case 0x145FECu: goto label_145fec;
            case 0x145FF0u: goto label_145ff0;
            case 0x145FF4u: goto label_145ff4;
            case 0x145FF8u: goto label_145ff8;
            case 0x145FFCu: goto label_145ffc;
            case 0x146000u: goto label_146000;
            case 0x146004u: goto label_146004;
            case 0x146008u: goto label_146008;
            case 0x14600Cu: goto label_14600c;
            case 0x146010u: goto label_146010;
            case 0x146014u: goto label_146014;
            case 0x146018u: goto label_146018;
            case 0x14601Cu: goto label_14601c;
            case 0x146020u: goto label_146020;
            case 0x146024u: goto label_146024;
            case 0x146028u: goto label_146028;
            case 0x14602Cu: goto label_14602c;
            case 0x146030u: goto label_146030;
            case 0x146034u: goto label_146034;
            case 0x146038u: goto label_146038;
            case 0x14603Cu: goto label_14603c;
            case 0x146040u: goto label_146040;
            case 0x146044u: goto label_146044;
            case 0x146048u: goto label_146048;
            case 0x14604Cu: goto label_14604c;
            case 0x146050u: goto label_146050;
            case 0x146054u: goto label_146054;
            case 0x146058u: goto label_146058;
            case 0x14605Cu: goto label_14605c;
            case 0x146060u: goto label_146060;
            case 0x146064u: goto label_146064;
            case 0x146068u: goto label_146068;
            case 0x14606Cu: goto label_14606c;
            case 0x146070u: goto label_146070;
            case 0x146074u: goto label_146074;
            case 0x146078u: goto label_146078;
            case 0x14607Cu: goto label_14607c;
            case 0x146080u: goto label_146080;
            case 0x146084u: goto label_146084;
            case 0x146088u: goto label_146088;
            case 0x14608Cu: goto label_14608c;
            case 0x146090u: goto label_146090;
            case 0x146094u: goto label_146094;
            case 0x146098u: goto label_146098;
            case 0x14609Cu: goto label_14609c;
            case 0x1460A0u: goto label_1460a0;
            case 0x1460A4u: goto label_1460a4;
            case 0x1460A8u: goto label_1460a8;
            case 0x1460ACu: goto label_1460ac;
            case 0x1460B0u: goto label_1460b0;
            case 0x1460B4u: goto label_1460b4;
            case 0x1460B8u: goto label_1460b8;
            case 0x1460BCu: goto label_1460bc;
            case 0x1460C0u: goto label_1460c0;
            case 0x1460C4u: goto label_1460c4;
            case 0x1460C8u: goto label_1460c8;
            case 0x1460CCu: goto label_1460cc;
            case 0x1460D0u: goto label_1460d0;
            case 0x1460D4u: goto label_1460d4;
            case 0x1460D8u: goto label_1460d8;
            case 0x1460DCu: goto label_1460dc;
            case 0x1460E0u: goto label_1460e0;
            case 0x1460E4u: goto label_1460e4;
            case 0x1460E8u: goto label_1460e8;
            case 0x1460ECu: goto label_1460ec;
            case 0x1460F0u: goto label_1460f0;
            case 0x1460F4u: goto label_1460f4;
            case 0x1460F8u: goto label_1460f8;
            case 0x1460FCu: goto label_1460fc;
            case 0x146100u: goto label_146100;
            case 0x146104u: goto label_146104;
            case 0x146108u: goto label_146108;
            case 0x14610Cu: goto label_14610c;
            case 0x146110u: goto label_146110;
            case 0x146114u: goto label_146114;
            case 0x146118u: goto label_146118;
            case 0x14611Cu: goto label_14611c;
            case 0x146120u: goto label_146120;
            case 0x146124u: goto label_146124;
            case 0x146128u: goto label_146128;
            case 0x14612Cu: goto label_14612c;
            case 0x146130u: goto label_146130;
            case 0x146134u: goto label_146134;
            case 0x146138u: goto label_146138;
            case 0x14613Cu: goto label_14613c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x145F50u;
label_145f50:
    // 0x145f50: 0x27bdffe0
    ctx->pc = 0x145f50u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
label_145f54:
    // 0x145f54: 0x24050004
    ctx->pc = 0x145f54u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4));
label_145f58:
    // 0x145f58: 0xffb00000
    ctx->pc = 0x145f58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_145f5c:
    // 0x145f5c: 0xffbf0010
    ctx->pc = 0x145f5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
label_145f60:
    // 0x145f60: 0xc05167a
label_145f64:
    if (ctx->pc == 0x145F64u) {
        ctx->pc = 0x145F64u;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x145F68u;
        goto label_145f68;
    }
    ctx->pc = 0x145F60u;
    SET_GPR_U32(ctx, 31, 0x145F68u);
    ctx->pc = 0x145F64u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145F68u; }
    }
    if (ctx->pc != 0x145F68u) { return; }
    ctx->pc = 0x145F68u;
label_145f68:
    // 0x145f68: 0xae02017c
    ctx->pc = 0x145f68u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 380), GPR_U32(ctx, 2));
label_145f6c:
    // 0x145f6c: 0x200202d
    ctx->pc = 0x145f6cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_145f70:
    // 0x145f70: 0xc05167a
label_145f74:
    if (ctx->pc == 0x145F74u) {
        ctx->pc = 0x145F74u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4));
        ctx->pc = 0x145F78u;
        goto label_145f78;
    }
    ctx->pc = 0x145F70u;
    SET_GPR_U32(ctx, 31, 0x145F78u);
    ctx->pc = 0x145F74u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145F78u; }
    }
    if (ctx->pc != 0x145F78u) { return; }
    ctx->pc = 0x145F78u;
label_145f78:
    // 0x145f78: 0xae020180
    ctx->pc = 0x145f78u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 384), GPR_U32(ctx, 2));
label_145f7c:
    // 0x145f7c: 0x200202d
    ctx->pc = 0x145f7cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_145f80:
    // 0x145f80: 0xc05167a
label_145f84:
    if (ctx->pc == 0x145F84u) {
        ctx->pc = 0x145F84u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4));
        ctx->pc = 0x145F88u;
        goto label_145f88;
    }
    ctx->pc = 0x145F80u;
    SET_GPR_U32(ctx, 31, 0x145F88u);
    ctx->pc = 0x145F84u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145F88u; }
    }
    if (ctx->pc != 0x145F88u) { return; }
    ctx->pc = 0x145F88u;
label_145f88:
    // 0x145f88: 0xae020184
    ctx->pc = 0x145f88u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 388), GPR_U32(ctx, 2));
label_145f8c:
    // 0x145f8c: 0x200202d
    ctx->pc = 0x145f8cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_145f90:
    // 0x145f90: 0xc05167a
label_145f94:
    if (ctx->pc == 0x145F94u) {
        ctx->pc = 0x145F94u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4));
        ctx->pc = 0x145F98u;
        goto label_145f98;
    }
    ctx->pc = 0x145F90u;
    SET_GPR_U32(ctx, 31, 0x145F98u);
    ctx->pc = 0x145F94u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145F98u; }
    }
    if (ctx->pc != 0x145F98u) { return; }
    ctx->pc = 0x145F98u;
label_145f98:
    // 0x145f98: 0xae020188
    ctx->pc = 0x145f98u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 392), GPR_U32(ctx, 2));
label_145f9c:
    // 0x145f9c: 0x200202d
    ctx->pc = 0x145f9cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_145fa0:
    // 0x145fa0: 0xc05167a
label_145fa4:
    if (ctx->pc == 0x145FA4u) {
        ctx->pc = 0x145FA4u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 2));
        ctx->pc = 0x145FA8u;
        goto label_145fa8;
    }
    ctx->pc = 0x145FA0u;
    SET_GPR_U32(ctx, 31, 0x145FA8u);
    ctx->pc = 0x145FA4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145FA8u; }
    }
    if (ctx->pc != 0x145FA8u) { return; }
    ctx->pc = 0x145FA8u;
label_145fa8:
    // 0x145fa8: 0x3c071000
    ctx->pc = 0x145fa8u;
    SET_GPR_U32(ctx, 7, ((uint32_t)4096 << 16));
label_145fac:
    // 0x145fac: 0x3c06fffc
    ctx->pc = 0x145facu;
    SET_GPR_U32(ctx, 6, ((uint32_t)65532 << 16));
label_145fb0:
    // 0x145fb0: 0x34e72010
    ctx->pc = 0x145fb0u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 7), 8208));
label_145fb4:
    // 0x145fb4: 0x34c6ffff
    ctx->pc = 0x145fb4u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 65535));
label_145fb8:
    // 0x145fb8: 0x8ce30000
    ctx->pc = 0x145fb8u;
    SET_GPR_U32(ctx, 3, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 7), 0))); // MMIO: 0x10000000
label_145fbc:
    // 0x145fbc: 0x21400
    ctx->pc = 0x145fbcu;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 16));
label_145fc0:
    // 0x145fc0: 0x200202d
    ctx->pc = 0x145fc0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_145fc4:
    // 0x145fc4: 0x24050002
    ctx->pc = 0x145fc4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 2));
label_145fc8:
    // 0x145fc8: 0x661824
    ctx->pc = 0x145fc8u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
label_145fcc:
    // 0x145fcc: 0x621825
    ctx->pc = 0x145fccu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_145fd0:
    // 0x145fd0: 0xc05167a
label_145fd4:
    if (ctx->pc == 0x145FD4u) {
        ctx->pc = 0x145FD4u;
        WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
        ctx->pc = 0x145FD8u;
        goto label_145fd8;
    }
    ctx->pc = 0x145FD0u;
    SET_GPR_U32(ctx, 31, 0x145FD8u);
    ctx->pc = 0x145FD4u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 3));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145FD8u; }
    }
    if (ctx->pc != 0x145FD8u) { return; }
    ctx->pc = 0x145FD8u;
label_145fd8:
    // 0x145fd8: 0x40182d
    ctx->pc = 0x145fd8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_145fdc:
    // 0x145fdc: 0x8e0200ec
    ctx->pc = 0x145fdcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 236)));
label_145fe0:
    // 0x145fe0: 0x14400002
label_145fe4:
    if (ctx->pc == 0x145FE4u) {
        ctx->pc = 0x145FE4u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 396), GPR_U32(ctx, 3));
        ctx->pc = 0x145FE8u;
        goto label_145fe8;
    }
    ctx->pc = 0x145FE0u;
    {
        const bool branch_taken_0x145fe0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x145FE4u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 396), GPR_U32(ctx, 3));
        if (branch_taken_0x145fe0) {
            ctx->pc = 0x145FECu;
            goto label_145fec;
        }
    }
    ctx->pc = 0x145FE8u;
label_145fe8:
    // 0x145fe8: 0xae0300ec
    ctx->pc = 0x145fe8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 236), GPR_U32(ctx, 3));
label_145fec:
    // 0x145fec: 0x200202d
    ctx->pc = 0x145fecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_145ff0:
    // 0x145ff0: 0xc05167a
label_145ff4:
    if (ctx->pc == 0x145FF4u) {
        ctx->pc = 0x145FF4u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x145FF8u;
        goto label_145ff8;
    }
    ctx->pc = 0x145FF0u;
    SET_GPR_U32(ctx, 31, 0x145FF8u);
    ctx->pc = 0x145FF4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145FF8u; }
    }
    if (ctx->pc != 0x145FF8u) { return; }
    ctx->pc = 0x145FF8u;
label_145ff8:
    // 0x145ff8: 0xae020190
    ctx->pc = 0x145ff8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 400), GPR_U32(ctx, 2));
label_145ffc:
    // 0x145ffc: 0x200202d
    ctx->pc = 0x145ffcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_146000:
    // 0x146000: 0xc05167a
label_146004:
    if (ctx->pc == 0x146004u) {
        ctx->pc = 0x146004u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x146008u;
        goto label_146008;
    }
    ctx->pc = 0x146000u;
    SET_GPR_U32(ctx, 31, 0x146008u);
    ctx->pc = 0x146004u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146008u; }
    }
    if (ctx->pc != 0x146008u) { return; }
    ctx->pc = 0x146008u;
label_146008:
    // 0x146008: 0xae020194
    ctx->pc = 0x146008u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 404), GPR_U32(ctx, 2));
label_14600c:
    // 0x14600c: 0x200202d
    ctx->pc = 0x14600cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_146010:
    // 0x146010: 0xc05167a
label_146014:
    if (ctx->pc == 0x146014u) {
        ctx->pc = 0x146014u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x146018u;
        goto label_146018;
    }
    ctx->pc = 0x146010u;
    SET_GPR_U32(ctx, 31, 0x146018u);
    ctx->pc = 0x146014u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146018u; }
    }
    if (ctx->pc != 0x146018u) { return; }
    ctx->pc = 0x146018u;
label_146018:
    // 0x146018: 0xae020198
    ctx->pc = 0x146018u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 408), GPR_U32(ctx, 2));
label_14601c:
    // 0x14601c: 0x200202d
    ctx->pc = 0x14601cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_146020:
    // 0x146020: 0xc05167a
label_146024:
    if (ctx->pc == 0x146024u) {
        ctx->pc = 0x146024u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x146028u;
        goto label_146028;
    }
    ctx->pc = 0x146020u;
    SET_GPR_U32(ctx, 31, 0x146028u);
    ctx->pc = 0x146024u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146028u; }
    }
    if (ctx->pc != 0x146028u) { return; }
    ctx->pc = 0x146028u;
label_146028:
    // 0x146028: 0x3c061000
    ctx->pc = 0x146028u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
label_14602c:
    // 0x14602c: 0x8cc62010
    ctx->pc = 0x14602cu;
    SET_GPR_U32(ctx, 6, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 6), 8208))); // MMIO: 0x10002010
label_146030:
    // 0x146030: 0x3c03ffbf
    ctx->pc = 0x146030u;
    SET_GPR_U32(ctx, 3, ((uint32_t)65471 << 16));
label_146034:
    // 0x146034: 0x3463ffff
    ctx->pc = 0x146034u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 65535));
label_146038:
    // 0x146038: 0x21580
    ctx->pc = 0x146038u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 22));
label_14603c:
    // 0x14603c: 0xc33024
    ctx->pc = 0x14603cu;
    SET_GPR_U32(ctx, 6, AND32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
label_146040:
    // 0x146040: 0x200202d
    ctx->pc = 0x146040u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_146044:
    // 0x146044: 0xc23025
    ctx->pc = 0x146044u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
label_146048:
    // 0x146048: 0x24050001
    ctx->pc = 0x146048u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
label_14604c:
    // 0x14604c: 0x3c011000
    ctx->pc = 0x14604cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4096 << 16));
label_146050:
    // 0x146050: 0xc05167a
label_146054:
    if (ctx->pc == 0x146054u) {
        ctx->pc = 0x146054u;
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8208), GPR_U32(ctx, 6));
        ctx->pc = 0x146058u;
        goto label_146058;
    }
    ctx->pc = 0x146050u;
    SET_GPR_U32(ctx, 31, 0x146058u);
    ctx->pc = 0x146054u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8208), GPR_U32(ctx, 6));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146058u; }
    }
    if (ctx->pc != 0x146058u) { return; }
    ctx->pc = 0x146058u;
label_146058:
    // 0x146058: 0x3c061000
    ctx->pc = 0x146058u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
label_14605c:
    // 0x14605c: 0x8cc62010
    ctx->pc = 0x14605cu;
    SET_GPR_U32(ctx, 6, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 6), 8208))); // MMIO: 0x10002010
label_146060:
    // 0x146060: 0x3c03ffdf
    ctx->pc = 0x146060u;
    SET_GPR_U32(ctx, 3, ((uint32_t)65503 << 16));
label_146064:
    // 0x146064: 0x3463ffff
    ctx->pc = 0x146064u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 65535));
label_146068:
    // 0x146068: 0x21540
    ctx->pc = 0x146068u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 21));
label_14606c:
    // 0x14606c: 0xc33024
    ctx->pc = 0x14606cu;
    SET_GPR_U32(ctx, 6, AND32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
label_146070:
    // 0x146070: 0x200202d
    ctx->pc = 0x146070u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_146074:
    // 0x146074: 0xc23025
    ctx->pc = 0x146074u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
label_146078:
    // 0x146078: 0x24050001
    ctx->pc = 0x146078u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
label_14607c:
    // 0x14607c: 0x3c011000
    ctx->pc = 0x14607cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4096 << 16));
label_146080:
    // 0x146080: 0xc05167a
label_146084:
    if (ctx->pc == 0x146084u) {
        ctx->pc = 0x146084u;
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8208), GPR_U32(ctx, 6));
        ctx->pc = 0x146088u;
        goto label_146088;
    }
    ctx->pc = 0x146080u;
    SET_GPR_U32(ctx, 31, 0x146088u);
    ctx->pc = 0x146084u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8208), GPR_U32(ctx, 6));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146088u; }
    }
    if (ctx->pc != 0x146088u) { return; }
    ctx->pc = 0x146088u;
label_146088:
    // 0x146088: 0x3c061000
    ctx->pc = 0x146088u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4096 << 16));
label_14608c:
    // 0x14608c: 0x8cc62010
    ctx->pc = 0x14608cu;
    SET_GPR_U32(ctx, 6, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 6), 8208))); // MMIO: 0x10002010
label_146090:
    // 0x146090: 0x3c03ffef
    ctx->pc = 0x146090u;
    SET_GPR_U32(ctx, 3, ((uint32_t)65519 << 16));
label_146094:
    // 0x146094: 0x3463ffff
    ctx->pc = 0x146094u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 65535));
label_146098:
    // 0x146098: 0x21500
    ctx->pc = 0x146098u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 20));
label_14609c:
    // 0x14609c: 0xc33024
    ctx->pc = 0x14609cu;
    SET_GPR_U32(ctx, 6, AND32(GPR_U32(ctx, 6), GPR_U32(ctx, 3)));
label_1460a0:
    // 0x1460a0: 0x200202d
    ctx->pc = 0x1460a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1460a4:
    // 0x1460a4: 0xc23025
    ctx->pc = 0x1460a4u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), GPR_U32(ctx, 2)));
label_1460a8:
    // 0x1460a8: 0x24050001
    ctx->pc = 0x1460a8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
label_1460ac:
    // 0x1460ac: 0x3c011000
    ctx->pc = 0x1460acu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4096 << 16));
label_1460b0:
    // 0x1460b0: 0xc05167a
label_1460b4:
    if (ctx->pc == 0x1460B4u) {
        ctx->pc = 0x1460B4u;
        runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8208), GPR_U32(ctx, 6));
        ctx->pc = 0x1460B8u;
        goto label_1460b8;
    }
    ctx->pc = 0x1460B0u;
    SET_GPR_U32(ctx, 31, 0x1460B8u);
    ctx->pc = 0x1460B4u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 8208), GPR_U32(ctx, 6));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1460B8u; }
    }
    if (ctx->pc != 0x1460B8u) { return; }
    ctx->pc = 0x1460B8u;
label_1460b8:
    // 0x1460b8: 0xae02019c
    ctx->pc = 0x1460b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 412), GPR_U32(ctx, 2));
label_1460bc:
    // 0x1460bc: 0x200202d
    ctx->pc = 0x1460bcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1460c0:
    // 0x1460c0: 0xc05167a
label_1460c4:
    if (ctx->pc == 0x1460C4u) {
        ctx->pc = 0x1460C4u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x1460C8u;
        goto label_1460c8;
    }
    ctx->pc = 0x1460C0u;
    SET_GPR_U32(ctx, 31, 0x1460C8u);
    ctx->pc = 0x1460C4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1460C8u; }
    }
    if (ctx->pc != 0x1460C8u) { return; }
    ctx->pc = 0x1460C8u;
label_1460c8:
    // 0x1460c8: 0x200202d
    ctx->pc = 0x1460c8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1460cc:
    // 0x1460cc: 0xc05167a
label_1460d0:
    if (ctx->pc == 0x1460D0u) {
        ctx->pc = 0x1460D0u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x1460D4u;
        goto label_1460d4;
    }
    ctx->pc = 0x1460CCu;
    SET_GPR_U32(ctx, 31, 0x1460D4u);
    ctx->pc = 0x1460D0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1460D4u; }
    }
    if (ctx->pc != 0x1460D4u) { return; }
    ctx->pc = 0x1460D4u;
label_1460d4:
    // 0x1460d4: 0xae0201a0
    ctx->pc = 0x1460d4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 416), GPR_U32(ctx, 2));
label_1460d8:
    // 0x1460d8: 0x200202d
    ctx->pc = 0x1460d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1460dc:
    // 0x1460dc: 0xc05167a
label_1460e0:
    if (ctx->pc == 0x1460E0u) {
        ctx->pc = 0x1460E0u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x1460E4u;
        goto label_1460e4;
    }
    ctx->pc = 0x1460DCu;
    SET_GPR_U32(ctx, 31, 0x1460E4u);
    ctx->pc = 0x1460E0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1460E4u; }
    }
    if (ctx->pc != 0x1460E4u) { return; }
    ctx->pc = 0x1460E4u;
label_1460e4:
    // 0x1460e4: 0x10400013
label_1460e8:
    if (ctx->pc == 0x1460E8u) {
        ctx->pc = 0x1460E8u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        ctx->pc = 0x1460ECu;
        goto label_1460ec;
    }
    ctx->pc = 0x1460E4u;
    {
        const bool branch_taken_0x1460e4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1460E8u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        if (branch_taken_0x1460e4) {
            ctx->pc = 0x146134u;
            goto label_146134;
        }
    }
    ctx->pc = 0x1460ECu;
label_1460ec:
    // 0x1460ec: 0x200202d
    ctx->pc = 0x1460ecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1460f0:
    // 0x1460f0: 0xc05167a
label_1460f4:
    if (ctx->pc == 0x1460F4u) {
        ctx->pc = 0x1460F4u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x1460F8u;
        goto label_1460f8;
    }
    ctx->pc = 0x1460F0u;
    SET_GPR_U32(ctx, 31, 0x1460F8u);
    ctx->pc = 0x1460F4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1460F8u; }
    }
    if (ctx->pc != 0x1460F8u) { return; }
    ctx->pc = 0x1460F8u;
label_1460f8:
    // 0x1460f8: 0x200202d
    ctx->pc = 0x1460f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_1460fc:
    // 0x1460fc: 0xc05167a
label_146100:
    if (ctx->pc == 0x146100u) {
        ctx->pc = 0x146100u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 3));
        ctx->pc = 0x146104u;
        goto label_146104;
    }
    ctx->pc = 0x1460FCu;
    SET_GPR_U32(ctx, 31, 0x146104u);
    ctx->pc = 0x146100u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 3));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146104u; }
    }
    if (ctx->pc != 0x146104u) { return; }
    ctx->pc = 0x146104u;
label_146104:
    // 0x146104: 0x200202d
    ctx->pc = 0x146104u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_146108:
    // 0x146108: 0xc05167a
label_14610c:
    if (ctx->pc == 0x14610Cu) {
        ctx->pc = 0x14610Cu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x146110u;
        goto label_146110;
    }
    ctx->pc = 0x146108u;
    SET_GPR_U32(ctx, 31, 0x146110u);
    ctx->pc = 0x14610Cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146110u; }
    }
    if (ctx->pc != 0x146110u) { return; }
    ctx->pc = 0x146110u;
label_146110:
    // 0x146110: 0x200202d
    ctx->pc = 0x146110u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_146114:
    // 0x146114: 0xc05167a
label_146118:
    if (ctx->pc == 0x146118u) {
        ctx->pc = 0x146118u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 7));
        ctx->pc = 0x14611Cu;
        goto label_14611c;
    }
    ctx->pc = 0x146114u;
    SET_GPR_U32(ctx, 31, 0x14611Cu);
    ctx->pc = 0x146118u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 7));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14611Cu; }
    }
    if (ctx->pc != 0x14611Cu) { return; }
    ctx->pc = 0x14611Cu;
label_14611c:
    // 0x14611c: 0x200202d
    ctx->pc = 0x14611cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_146120:
    // 0x146120: 0xdfbf0010
    ctx->pc = 0x146120u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_146124:
    // 0x146124: 0xdfb00000
    ctx->pc = 0x146124u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_146128:
    // 0x146128: 0x24050008
    ctx->pc = 0x146128u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
label_14612c:
    // 0x14612c: 0x805167a
label_146130:
    if (ctx->pc == 0x146130u) {
        ctx->pc = 0x146130u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x146134u;
        goto label_146134;
    }
    ctx->pc = 0x14612Cu;
    ctx->pc = 0x146130u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x1459E8u;
    sub_001459E8_0x1459e8(rdram, ctx, runtime); return;
    ctx->pc = 0x146134u;
label_146134:
    // 0x146134: 0xdfb00000
    ctx->pc = 0x146134u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_146138:
    // 0x146138: 0x3e00008
label_14613c:
    if (ctx->pc == 0x14613Cu) {
        ctx->pc = 0x14613Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x146140u;
        goto label_fallthrough_0x146138;
    }
    ctx->pc = 0x146138u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x14613Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x145E28u: goto label_145e28;
            case 0x145E2Cu: goto label_145e2c;
            case 0x145E30u: goto label_145e30;
            case 0x145E34u: goto label_145e34;
            case 0x145E38u: goto label_145e38;
            case 0x145E3Cu: goto label_145e3c;
            case 0x145E40u: goto label_145e40;
            case 0x145E44u: goto label_145e44;
            case 0x145E48u: goto label_145e48;
            case 0x145E4Cu: goto label_145e4c;
            case 0x145E50u: goto label_145e50;
            case 0x145E54u: goto label_145e54;
            case 0x145E58u: goto label_145e58;
            case 0x145E5Cu: goto label_145e5c;
            case 0x145E60u: goto label_145e60;
            case 0x145E64u: goto label_145e64;
            case 0x145E68u: goto label_145e68;
            case 0x145E6Cu: goto label_145e6c;
            case 0x145E70u: goto label_145e70;
            case 0x145E74u: goto label_145e74;
            case 0x145E78u: goto label_145e78;
            case 0x145E7Cu: goto label_145e7c;
            case 0x145E80u: goto label_145e80;
            case 0x145E84u: goto label_145e84;
            case 0x145E88u: goto label_145e88;
            case 0x145E8Cu: goto label_145e8c;
            case 0x145E90u: goto label_145e90;
            case 0x145E94u: goto label_145e94;
            case 0x145E98u: goto label_145e98;
            case 0x145E9Cu: goto label_145e9c;
            case 0x145EA0u: goto label_145ea0;
            case 0x145EA4u: goto label_145ea4;
            case 0x145EA8u: goto label_145ea8;
            case 0x145EACu: goto label_145eac;
            case 0x145EB0u: goto label_145eb0;
            case 0x145EB4u: goto label_145eb4;
            case 0x145EB8u: goto label_145eb8;
            case 0x145EBCu: goto label_145ebc;
            case 0x145EC0u: goto label_145ec0;
            case 0x145EC4u: goto label_145ec4;
            case 0x145EC8u: goto label_145ec8;
            case 0x145ECCu: goto label_145ecc;
            case 0x145ED0u: goto label_145ed0;
            case 0x145ED4u: goto label_145ed4;
            case 0x145ED8u: goto label_145ed8;
            case 0x145EDCu: goto label_145edc;
            case 0x145EE0u: goto label_145ee0;
            case 0x145EE4u: goto label_145ee4;
            case 0x145EE8u: goto label_145ee8;
            case 0x145EECu: goto label_145eec;
            case 0x145EF0u: goto label_145ef0;
            case 0x145EF4u: goto label_145ef4;
            case 0x145EF8u: goto label_145ef8;
            case 0x145EFCu: goto label_145efc;
            case 0x145F00u: goto label_145f00;
            case 0x145F04u: goto label_145f04;
            case 0x145F08u: goto label_145f08;
            case 0x145F0Cu: goto label_145f0c;
            case 0x145F10u: goto label_145f10;
            case 0x145F14u: goto label_145f14;
            case 0x145F18u: goto label_145f18;
            case 0x145F1Cu: goto label_145f1c;
            case 0x145F20u: goto label_145f20;
            case 0x145F24u: goto label_145f24;
            case 0x145F28u: goto label_145f28;
            case 0x145F2Cu: goto label_145f2c;
            case 0x145F30u: goto label_145f30;
            case 0x145F34u: goto label_145f34;
            case 0x145F38u: goto label_145f38;
            case 0x145F3Cu: goto label_145f3c;
            case 0x145F40u: goto label_145f40;
            case 0x145F44u: goto label_145f44;
            case 0x145F48u: goto label_145f48;
            case 0x145F4Cu: goto label_145f4c;
            case 0x145F50u: goto label_145f50;
            case 0x145F54u: goto label_145f54;
            case 0x145F58u: goto label_145f58;
            case 0x145F5Cu: goto label_145f5c;
            case 0x145F60u: goto label_145f60;
            case 0x145F64u: goto label_145f64;
            case 0x145F68u: goto label_145f68;
            case 0x145F6Cu: goto label_145f6c;
            case 0x145F70u: goto label_145f70;
            case 0x145F74u: goto label_145f74;
            case 0x145F78u: goto label_145f78;
            case 0x145F7Cu: goto label_145f7c;
            case 0x145F80u: goto label_145f80;
            case 0x145F84u: goto label_145f84;
            case 0x145F88u: goto label_145f88;
            case 0x145F8Cu: goto label_145f8c;
            case 0x145F90u: goto label_145f90;
            case 0x145F94u: goto label_145f94;
            case 0x145F98u: goto label_145f98;
            case 0x145F9Cu: goto label_145f9c;
            case 0x145FA0u: goto label_145fa0;
            case 0x145FA4u: goto label_145fa4;
            case 0x145FA8u: goto label_145fa8;
            case 0x145FACu: goto label_145fac;
            case 0x145FB0u: goto label_145fb0;
            case 0x145FB4u: goto label_145fb4;
            case 0x145FB8u: goto label_145fb8;
            case 0x145FBCu: goto label_145fbc;
            case 0x145FC0u: goto label_145fc0;
            case 0x145FC4u: goto label_145fc4;
            case 0x145FC8u: goto label_145fc8;
            case 0x145FCCu: goto label_145fcc;
            case 0x145FD0u: goto label_145fd0;
            case 0x145FD4u: goto label_145fd4;
            case 0x145FD8u: goto label_145fd8;
            case 0x145FDCu: goto label_145fdc;
            case 0x145FE0u: goto label_145fe0;
            case 0x145FE4u: goto label_145fe4;
            case 0x145FE8u: goto label_145fe8;
            case 0x145FECu: goto label_145fec;
            case 0x145FF0u: goto label_145ff0;
            case 0x145FF4u: goto label_145ff4;
            case 0x145FF8u: goto label_145ff8;
            case 0x145FFCu: goto label_145ffc;
            case 0x146000u: goto label_146000;
            case 0x146004u: goto label_146004;
            case 0x146008u: goto label_146008;
            case 0x14600Cu: goto label_14600c;
            case 0x146010u: goto label_146010;
            case 0x146014u: goto label_146014;
            case 0x146018u: goto label_146018;
            case 0x14601Cu: goto label_14601c;
            case 0x146020u: goto label_146020;
            case 0x146024u: goto label_146024;
            case 0x146028u: goto label_146028;
            case 0x14602Cu: goto label_14602c;
            case 0x146030u: goto label_146030;
            case 0x146034u: goto label_146034;
            case 0x146038u: goto label_146038;
            case 0x14603Cu: goto label_14603c;
            case 0x146040u: goto label_146040;
            case 0x146044u: goto label_146044;
            case 0x146048u: goto label_146048;
            case 0x14604Cu: goto label_14604c;
            case 0x146050u: goto label_146050;
            case 0x146054u: goto label_146054;
            case 0x146058u: goto label_146058;
            case 0x14605Cu: goto label_14605c;
            case 0x146060u: goto label_146060;
            case 0x146064u: goto label_146064;
            case 0x146068u: goto label_146068;
            case 0x14606Cu: goto label_14606c;
            case 0x146070u: goto label_146070;
            case 0x146074u: goto label_146074;
            case 0x146078u: goto label_146078;
            case 0x14607Cu: goto label_14607c;
            case 0x146080u: goto label_146080;
            case 0x146084u: goto label_146084;
            case 0x146088u: goto label_146088;
            case 0x14608Cu: goto label_14608c;
            case 0x146090u: goto label_146090;
            case 0x146094u: goto label_146094;
            case 0x146098u: goto label_146098;
            case 0x14609Cu: goto label_14609c;
            case 0x1460A0u: goto label_1460a0;
            case 0x1460A4u: goto label_1460a4;
            case 0x1460A8u: goto label_1460a8;
            case 0x1460ACu: goto label_1460ac;
            case 0x1460B0u: goto label_1460b0;
            case 0x1460B4u: goto label_1460b4;
            case 0x1460B8u: goto label_1460b8;
            case 0x1460BCu: goto label_1460bc;
            case 0x1460C0u: goto label_1460c0;
            case 0x1460C4u: goto label_1460c4;
            case 0x1460C8u: goto label_1460c8;
            case 0x1460CCu: goto label_1460cc;
            case 0x1460D0u: goto label_1460d0;
            case 0x1460D4u: goto label_1460d4;
            case 0x1460D8u: goto label_1460d8;
            case 0x1460DCu: goto label_1460dc;
            case 0x1460E0u: goto label_1460e0;
            case 0x1460E4u: goto label_1460e4;
            case 0x1460E8u: goto label_1460e8;
            case 0x1460ECu: goto label_1460ec;
            case 0x1460F0u: goto label_1460f0;
            case 0x1460F4u: goto label_1460f4;
            case 0x1460F8u: goto label_1460f8;
            case 0x1460FCu: goto label_1460fc;
            case 0x146100u: goto label_146100;
            case 0x146104u: goto label_146104;
            case 0x146108u: goto label_146108;
            case 0x14610Cu: goto label_14610c;
            case 0x146110u: goto label_146110;
            case 0x146114u: goto label_146114;
            case 0x146118u: goto label_146118;
            case 0x14611Cu: goto label_14611c;
            case 0x146120u: goto label_146120;
            case 0x146124u: goto label_146124;
            case 0x146128u: goto label_146128;
            case 0x14612Cu: goto label_14612c;
            case 0x146130u: goto label_146130;
            case 0x146134u: goto label_146134;
            case 0x146138u: goto label_146138;
            case 0x14613Cu: goto label_14613c;
            default: break;
        }
        return;
    }
label_fallthrough_0x146138:
    ctx->pc = 0x146140u;
}
