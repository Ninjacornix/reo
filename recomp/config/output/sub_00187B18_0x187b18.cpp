#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00187B18
// Address: 0x187b18 - 0x187d38
void sub_00187B18_0x187b18(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x187b18u;

    // 0x187b18: 0x418c0
    ctx->pc = 0x187b18u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 4), 3));
    // 0x187b1c: 0x641823
    ctx->pc = 0x187b1cu;
    SET_GPR_U32(ctx, 3, SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x187b20: 0x31880
    ctx->pc = 0x187b20u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 2));
    // 0x187b24: 0x68a40007
    ctx->pc = 0x187b24u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 7); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & ~mask) | ((aligned_data << shift) & mask)); }
    // 0x187b28: 0x6ca40000
    ctx->pc = 0x187b28u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 0); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & ~mask) | ((aligned_data >> shift) & mask)); }
    // 0x187b2c: 0x68a6000f
    ctx->pc = 0x187b2cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 15); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & ~mask) | ((aligned_data << shift) & mask)); }
    // 0x187b30: 0x6ca60008
    ctx->pc = 0x187b30u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 5), 8); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 6, (GPR_U64(ctx, 6) & ~mask) | ((aligned_data >> shift) & mask)); }
    // 0x187b34: 0x3c010029
    ctx->pc = 0x187b34u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x187b38: 0x230821
    ctx->pc = 0x187b38u;
    SET_GPR_U32(ctx, 1, ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x187b3c: 0xb024b8d7
    ctx->pc = 0x187b3cu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 1), 4294949079); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 4) >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187b40: 0x3c010029
    ctx->pc = 0x187b40u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x187b44: 0x230821
    ctx->pc = 0x187b44u;
    SET_GPR_U32(ctx, 1, ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x187b48: 0xb424b8d0
    ctx->pc = 0x187b48u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 1), 4294949072); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 4) << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187b4c: 0x3c010029
    ctx->pc = 0x187b4cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x187b50: 0x230821
    ctx->pc = 0x187b50u;
    SET_GPR_U32(ctx, 1, ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x187b54: 0xb026b8df
    ctx->pc = 0x187b54u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 1), 4294949087); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 6) >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187b58: 0x3c010029
    ctx->pc = 0x187b58u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x187b5c: 0x230821
    ctx->pc = 0x187b5cu;
    SET_GPR_U32(ctx, 1, ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 3)));
    // 0x187b60: 0xb426b8d8
    ctx->pc = 0x187b60u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 1), 4294949080); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 6) << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187b64: 0x3e00008
    ctx->pc = 0x187B64u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x187B68u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x187BE0u: goto label_187be0;
            case 0x187C30u: goto label_187c30;
            case 0x187D08u: goto label_187d08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x187B6Cu;
    // 0x187b6c: 0x0
    ctx->pc = 0x187b6cu;
    // NOP
    // 0x187b70: 0x27bdffa0
    ctx->pc = 0x187b70u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x187b74: 0xffb20020
    ctx->pc = 0x187b74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x187b78: 0x80902d
    ctx->pc = 0x187b78u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187b7c: 0xffb60040
    ctx->pc = 0x187b7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x187b80: 0x12b0c0
    ctx->pc = 0x187b80u;
    SET_GPR_U32(ctx, 22, SLL32(GPR_U32(ctx, 18), 3));
    // 0x187b84: 0xffb70048
    ctx->pc = 0x187b84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 23));
    // 0x187b88: 0x3c170029
    ctx->pc = 0x187b88u;
    SET_GPR_U32(ctx, 23, ((uint32_t)41 << 16));
    // 0x187b8c: 0x26e3b8c8
    ctx->pc = 0x187b8cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 23), 4294949064));
    // 0x187b90: 0x2d21023
    ctx->pc = 0x187b90u;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 22), GPR_U32(ctx, 18)));
    // 0x187b94: 0xffb10018
    ctx->pc = 0x187b94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x187b98: 0x24630004
    ctx->pc = 0x187b98u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4));
    // 0x187b9c: 0xffb30028
    ctx->pc = 0x187b9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x187ba0: 0x24130003
    ctx->pc = 0x187ba0u;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 0), 3));
    // 0x187ba4: 0xffbe0050
    ctx->pc = 0x187ba4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 30));
    // 0x187ba8: 0xa0f02d
    ctx->pc = 0x187ba8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187bac: 0xffb00010
    ctx->pc = 0x187bacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x187bb0: 0x21080
    ctx->pc = 0x187bb0u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 2));
    // 0x187bb4: 0xffb40030
    ctx->pc = 0x187bb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x187bb8: 0x438821
    ctx->pc = 0x187bb8u;
    SET_GPR_U32(ctx, 17, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x187bbc: 0xffb50038
    ctx->pc = 0x187bbcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x187bc0: 0xffbf0058
    ctx->pc = 0x187bc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 88), GPR_U64(ctx, 31));
    // 0x187bc4: 0xc0623b6
    ctx->pc = 0x187BC4u;
    SET_GPR_U32(ctx, 31, 0x187BCCu);
    ctx->pc = 0x187BC8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    ctx->pc = 0x188ED8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00188ED8_0x188ed8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187BCCu; }
    }
    if (ctx->pc != 0x187BCCu) { return; }
    ctx->pc = 0x187BCCu;
    // 0x187bcc: 0x14530004
    ctx->pc = 0x187BCCu;
    {
        const bool branch_taken_0x187bcc = (GPR_U32(ctx, 2) != GPR_U32(ctx, 19));
        ctx->pc = 0x187BD0u;
        SET_GPR_U32(ctx, 21, ((uint32_t)41 << 16));
        if (branch_taken_0x187bcc) {
            ctx->pc = 0x187BE0u;
            goto label_187be0;
        }
    }
    ctx->pc = 0x187BD4u;
    // 0x187bd4: 0x1000004c
    ctx->pc = 0x187BD4u;
    {
        const bool branch_taken_0x187bd4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x187BD8u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x187bd4) {
            ctx->pc = 0x187D08u;
            goto label_187d08;
        }
    }
    ctx->pc = 0x187BDCu;
    // 0x187bdc: 0x0
    ctx->pc = 0x187bdcu;
    // NOP
label_187be0:
    // 0x187be0: 0x3c100029
    ctx->pc = 0x187be0u;
    SET_GPR_U32(ctx, 16, ((uint32_t)41 << 16));
    // 0x187be4: 0x2610d980
    ctx->pc = 0x187be4u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 4294957440));
    // 0x187be8: 0x282d
    ctx->pc = 0x187be8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187bec: 0x26a4b900
    ctx->pc = 0x187becu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 21), 4294949120));
    // 0x187bf0: 0xc041f1a
    ctx->pc = 0x187BF0u;
    SET_GPR_U32(ctx, 31, 0x187BF8u);
    ctx->pc = 0x187BF4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 8320));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187BF8u; }
    }
    if (ctx->pc != 0x187BF8u) { return; }
    ctx->pc = 0x187BF8u;
    // 0x187bf8: 0x282d
    ctx->pc = 0x187bf8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187bfc: 0x200202d
    ctx->pc = 0x187bfcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187c00: 0x24060100
    ctx->pc = 0x187c00u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 256));
    // 0x187c04: 0x24022080
    ctx->pc = 0x187c04u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 8320));
    // 0x187c08: 0x3c140018
    ctx->pc = 0x187c08u;
    SET_GPR_U32(ctx, 20, ((uint32_t)24 << 16));
    // 0x187c0c: 0xc041f1a
    ctx->pc = 0x187C0Cu;
    SET_GPR_U32(ctx, 31, 0x187C14u);
    ctx->pc = 0x187C10u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187C14u; }
    }
    if (ctx->pc != 0x187C14u) { return; }
    ctx->pc = 0x187C14u;
    // 0x187c14: 0x200202d
    ctx->pc = 0x187c14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187c18: 0x3c100023
    ctx->pc = 0x187c18u;
    SET_GPR_U32(ctx, 16, ((uint32_t)35 << 16));
    // 0x187c1c: 0xc0453c6
    ctx->pc = 0x187C1Cu;
    SET_GPR_U32(ctx, 31, 0x187C24u);
    ctx->pc = 0x187C20u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 4), 255));
    ctx->pc = 0x114F18u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114F18_0x114f18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187C24u; }
    }
    if (ctx->pc != 0x187C24u) { return; }
    ctx->pc = 0x187C24u;
    // 0x187c24: 0xae13fd24
    ctx->pc = 0x187c24u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4294966564), GPR_U32(ctx, 19));
    // 0x187c28: 0x24130001
    ctx->pc = 0x187c28u;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 0), 1));
    // 0x187c2c: 0x8e240000
    ctx->pc = 0x187c2cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_187c30:
    // 0x187c30: 0x3a0302d
    ctx->pc = 0x187c30u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187c34: 0x8e05fd24
    ctx->pc = 0x187c34u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 4294966564)));
    // 0x187c38: 0x26a7b900
    ctx->pc = 0x187c38u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 21), 4294949120));
    // 0x187c3c: 0xc062560
    ctx->pc = 0x187C3Cu;
    SET_GPR_U32(ctx, 31, 0x187C44u);
    ctx->pc = 0x187C40u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 20), 30728));
    ctx->pc = 0x189580u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00189580_0x189580(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187C44u; }
    }
    if (ctx->pc != 0x187C44u) { return; }
    ctx->pc = 0x187C44u;
    // 0x187c44: 0x5453fffa
    ctx->pc = 0x187C44u;
    {
        const bool branch_taken_0x187c44 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 19));
        if (branch_taken_0x187c44) {
            ctx->pc = 0x187C48u;
            SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
            ctx->pc = 0x187C30u;
            goto label_187c30;
        }
    }
    ctx->pc = 0x187C4Cu;
    // 0x187c4c: 0x2d21023
    ctx->pc = 0x187c4cu;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 22), GPR_U32(ctx, 18)));
    // 0x187c50: 0x26f1b8c8
    ctx->pc = 0x187c50u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 23), 4294949064));
    // 0x187c54: 0x28080
    ctx->pc = 0x187c54u;
    SET_GPR_U32(ctx, 16, SLL32(GPR_U32(ctx, 2), 2));
    // 0x187c58: 0x2301821
    ctx->pc = 0x187c58u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x187c5c: 0xc061db2
    ctx->pc = 0x187C5Cu;
    SET_GPR_U32(ctx, 31, 0x187C64u);
    ctx->pc = 0x187C60u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 3), 4)));
    ctx->pc = 0x1876C8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001876C8_0x1876c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x187C64u; }
    }
    if (ctx->pc != 0x187C64u) { return; }
    ctx->pc = 0x187C64u;
    // 0x187c64: 0x40582d
    ctx->pc = 0x187c64u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187c68: 0x8d630008
    ctx->pc = 0x187c68u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 11), 8)));
    // 0x187c6c: 0x10600026
    ctx->pc = 0x187C6Cu;
    {
        const bool branch_taken_0x187c6c = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x187C70u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x187c6c) {
            ctx->pc = 0x187D08u;
            goto label_187d08;
        }
    }
    ctx->pc = 0x187C74u;
    // 0x187c74: 0x9162000d
    ctx->pc = 0x187c74u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 13)));
    // 0x187c78: 0x2302021
    ctx->pc = 0x187c78u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 16)));
    // 0x187c7c: 0x9163000c
    ctx->pc = 0x187c7cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 12)));
    // 0x187c80: 0x80282d
    ctx->pc = 0x187c80u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187c84: 0x21200
    ctx->pc = 0x187c84u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 8));
    // 0x187c88: 0xa0502d
    ctx->pc = 0x187c88u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187c8c: 0x621821
    ctx->pc = 0x187c8cu;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x187c90: 0x24020001
    ctx->pc = 0x187c90u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x187c94: 0xac830008
    ctx->pc = 0x187c94u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 3));
    // 0x187c98: 0x140482d
    ctx->pc = 0x187c98u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x187c9c: 0x24070001
    ctx->pc = 0x187c9cu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 1));
    // 0x187ca0: 0x2114021
    ctx->pc = 0x187ca0u;
    SET_GPR_U32(ctx, 8, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 17)));
    // 0x187ca4: 0x9163000f
    ctx->pc = 0x187ca4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 15)));
    // 0x187ca8: 0x9164000e
    ctx->pc = 0x187ca8u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 14)));
    // 0x187cac: 0x31a00
    ctx->pc = 0x187cacu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 8));
    // 0x187cb0: 0x832021
    ctx->pc = 0x187cb0u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x187cb4: 0xaca4000c
    ctx->pc = 0x187cb4u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 12), GPR_U32(ctx, 4));
    // 0x187cb8: 0x91660011
    ctx->pc = 0x187cb8u;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 17)));
    // 0x187cbc: 0x91650013
    ctx->pc = 0x187cbcu;
    SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 19)));
    // 0x187cc0: 0x91640012
    ctx->pc = 0x187cc0u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 18)));
    // 0x187cc4: 0x63200
    ctx->pc = 0x187cc4u;
    SET_GPR_U32(ctx, 6, SLL32(GPR_U32(ctx, 6), 8));
    // 0x187cc8: 0x91630010
    ctx->pc = 0x187cc8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 11), 16)));
    // 0x187ccc: 0x52e00
    ctx->pc = 0x187cccu;
    SET_GPR_U32(ctx, 5, SLL32(GPR_U32(ctx, 5), 24));
    // 0x187cd0: 0x42400
    ctx->pc = 0x187cd0u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 16));
    // 0x187cd4: 0x651821
    ctx->pc = 0x187cd4u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x187cd8: 0x862021
    ctx->pc = 0x187cd8u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
    // 0x187cdc: 0x641821
    ctx->pc = 0x187cdcu;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x187ce0: 0xad430010
    ctx->pc = 0x187ce0u;
    WRITE32(ADD32(GPR_U32(ctx, 10), 16), GPR_U32(ctx, 3));
    // 0x187ce4: 0xad270014
    ctx->pc = 0x187ce4u;
    WRITE32(ADD32(GPR_U32(ctx, 9), 20), GPR_U32(ctx, 7));
    // 0x187ce8: 0x6903000f
    ctx->pc = 0x187ce8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 15); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & ~mask) | ((aligned_data << shift) & mask)); }
    // 0x187cec: 0x6d030008
    ctx->pc = 0x187cecu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 8); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 3, (GPR_U64(ctx, 3) & ~mask) | ((aligned_data >> shift) & mask)); }
    // 0x187cf0: 0x69040017
    ctx->pc = 0x187cf0u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 23); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & ~mask) | ((aligned_data << shift) & mask)); }
    // 0x187cf4: 0x6d040010
    ctx->pc = 0x187cf4u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 8), 16); uint32_t shift = (addr & 7) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_data = READ64(addr & ~7ULL); SET_GPR_U64(ctx, 4, (GPR_U64(ctx, 4) & ~mask) | ((aligned_data >> shift) & mask)); }
    // 0x187cf8: 0xb3c30007
    ctx->pc = 0x187cf8u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 30), 7); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 3) >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187cfc: 0xb7c30000
    ctx->pc = 0x187cfcu;
    { uint32_t addr = ADD32(GPR_U32(ctx, 30), 0); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 3) << shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187d00: 0xb3c4000f
    ctx->pc = 0x187d00u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 30), 15); uint32_t shift = (7 - (addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL >> shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 4) >> shift) & mask); WRITE64(aligned_addr, new_data); }
    // 0x187d04: 0xb7c40008
    ctx->pc = 0x187d04u;
    { uint32_t addr = ADD32(GPR_U32(ctx, 30), 8); uint32_t shift = ((addr & 7)) << 3; uint64_t mask = 0xFFFFFFFFFFFFFFFFULL << shift; uint64_t aligned_addr = addr & ~7ULL; uint64_t old_data = READ64(aligned_addr); uint64_t new_data = (old_data & ~mask) | ((GPR_U64(ctx, 4) << shift) & mask); WRITE64(aligned_addr, new_data); }
label_187d08:
    // 0x187d08: 0xdfb00010
    ctx->pc = 0x187d08u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x187d0c: 0xdfb10018
    ctx->pc = 0x187d0cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x187d10: 0xdfb20020
    ctx->pc = 0x187d10u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x187d14: 0xdfb30028
    ctx->pc = 0x187d14u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x187d18: 0xdfb40030
    ctx->pc = 0x187d18u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x187d1c: 0xdfb50038
    ctx->pc = 0x187d1cu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x187d20: 0xdfb60040
    ctx->pc = 0x187d20u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x187d24: 0xdfb70048
    ctx->pc = 0x187d24u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x187d28: 0xdfbe0050
    ctx->pc = 0x187d28u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x187d2c: 0xdfbf0058
    ctx->pc = 0x187d2cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x187d30: 0x3e00008
    ctx->pc = 0x187D30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x187D34u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x187BE0u: goto label_187be0;
            case 0x187C30u: goto label_187c30;
            case 0x187D08u: goto label_187d08;
            default: break;
        }
        return;
    }
    ctx->pc = 0x187D38u;
}
