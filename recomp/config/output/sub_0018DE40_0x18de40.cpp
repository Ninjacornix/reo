#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0018DE40
// Address: 0x18de40 - 0x18e1b0
void sub_0018DE40_0x18de40(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x18de40u;

    // 0x18de40: 0x27bdfd00
    ctx->pc = 0x18de40u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294966528));
    // 0x18de44: 0xffbf0090
    ctx->pc = 0x18de44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x18de48: 0x7fbe0080
    ctx->pc = 0x18de48u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 30));
    // 0x18de4c: 0x7fb70070
    ctx->pc = 0x18de4cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x18de50: 0xa0f02d
    ctx->pc = 0x18de50u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18de54: 0x7fb60060
    ctx->pc = 0x18de54u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x18de58: 0xb82d
    ctx->pc = 0x18de58u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18de5c: 0x7fb50050
    ctx->pc = 0x18de5cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x18de60: 0x7fb40040
    ctx->pc = 0x18de60u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x18de64: 0x80a82d
    ctx->pc = 0x18de64u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18de68: 0x7fb30030
    ctx->pc = 0x18de68u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x18de6c: 0x7fb20020
    ctx->pc = 0x18de6cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x18de70: 0x7fb10010
    ctx->pc = 0x18de70u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x18de74: 0xc067448
    ctx->pc = 0x18DE74u;
    SET_GPR_U32(ctx, 31, 0x18DE7Cu);
    ctx->pc = 0x18DE78u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    ctx->pc = 0x19D120u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D120_0x19d120(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DE7Cu; }
    }
    if (ctx->pc != 0x18DE7Cu) { return; }
    ctx->pc = 0x18DE7Cu;
    // 0x18de7c: 0xafa200ac
    ctx->pc = 0x18de7cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 172), GPR_U32(ctx, 2));
    // 0x18de80: 0x2a0202d
    ctx->pc = 0x18de80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18de84: 0x3042ffff
    ctx->pc = 0x18de84u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 65535));
    // 0x18de88: 0x2445ffff
    ctx->pc = 0x18de88u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x18de8c: 0x518c0
    ctx->pc = 0x18de8cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 5), 3));
    // 0x18de90: 0x3c02002a
    ctx->pc = 0x18de90u;
    SET_GPR_U32(ctx, 2, ((uint32_t)42 << 16));
    // 0x18de94: 0x651823
    ctx->pc = 0x18de94u;
    SET_GPR_U32(ctx, 3, SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x18de98: 0x24428680
    ctx->pc = 0x18de98u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294936192));
    // 0x18de9c: 0x318c0
    ctx->pc = 0x18de9cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 3));
    // 0x18dea0: 0xc0694a0
    ctx->pc = 0x18DEA0u;
    SET_GPR_U32(ctx, 31, 0x18DEA8u);
    ctx->pc = 0x18DEA4u;
    SET_GPR_U32(ctx, 22, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    ctx->pc = 0x1A5280u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5280_0x1a5280(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DEA8u; }
    }
    if (ctx->pc != 0x18DEA8u) { return; }
    ctx->pc = 0x18DEA8u;
    // 0x18dea8: 0xafa200a8
    ctx->pc = 0x18dea8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 168), GPR_U32(ctx, 2));
    // 0x18deac: 0x27a40100
    ctx->pc = 0x18deacu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 256));
    // 0x18deb0: 0xc0694b4
    ctx->pc = 0x18DEB0u;
    SET_GPR_U32(ctx, 31, 0x18DEB8u);
    ctx->pc = 0x18DEB4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1A52D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A52D0_0x1a52d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DEB8u; }
    }
    if (ctx->pc != 0x18DEB8u) { return; }
    ctx->pc = 0x18DEB8u;
    // 0x18deb8: 0x14400003
    ctx->pc = 0x18DEB8u;
    {
        const bool branch_taken_0x18deb8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x18deb8) {
            ctx->pc = 0x18DEC8u;
            goto label_18dec8;
        }
    }
    ctx->pc = 0x18DEC0u;
    // 0x18dec0: 0x100000ad
    ctx->pc = 0x18DEC0u;
    {
        const bool branch_taken_0x18dec0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18DEC4u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x18dec0) {
            ctx->pc = 0x18E178u;
            goto label_18e178;
        }
    }
    ctx->pc = 0x18DEC8u;
label_18dec8:
    // 0x18dec8: 0x8fa200a8
    ctx->pc = 0x18dec8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x18decc: 0x27a40100
    ctx->pc = 0x18deccu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 256));
    // 0x18ded0: 0x8fa600ac
    ctx->pc = 0x18ded0u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x18ded4: 0x3c0382d
    ctx->pc = 0x18ded4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18ded8: 0xc0672cc
    ctx->pc = 0x18DED8u;
    SET_GPR_U32(ctx, 31, 0x18DEE0u);
    ctx->pc = 0x18DEDCu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 2), 1));
    ctx->pc = 0x19CB30u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0019CB30_0x19cb30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DEE0u; }
    }
    if (ctx->pc != 0x18DEE0u) { return; }
    ctx->pc = 0x18DEE0u;
    // 0x18dee0: 0x8ec40008
    ctx->pc = 0x18dee0u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 22), 8)));
    // 0x18dee4: 0xc063714
    ctx->pc = 0x18DEE4u;
    SET_GPR_U32(ctx, 31, 0x18DEECu);
    ctx->pc = 0x18DEE8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x18DC50u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC50_0x18dc50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DEECu; }
    }
    if (ctx->pc != 0x18DEECu) { return; }
    ctx->pc = 0x18DEECu;
    // 0x18deec: 0xaec20024
    ctx->pc = 0x18deecu;
    WRITE32(ADD32(GPR_U32(ctx, 22), 36), GPR_U32(ctx, 2));
    // 0x18def0: 0xc063728
    ctx->pc = 0x18DEF0u;
    SET_GPR_U32(ctx, 31, 0x18DEF8u);
    ctx->pc = 0x18DEF4u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 22), 36)));
    ctx->pc = 0x18DCA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DEF8u; }
    }
    if (ctx->pc != 0x18DEF8u) { return; }
    ctx->pc = 0x18DEF8u;
    // 0x18def8: 0x86d2001a
    ctx->pc = 0x18def8u;
    SET_GPR_S32(ctx, 18, (int16_t)READ16(ADD32(GPR_U32(ctx, 22), 26)));
    // 0x18defc: 0x40a02d
    ctx->pc = 0x18defcu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18df00: 0x86d1001c
    ctx->pc = 0x18df00u;
    SET_GPR_S32(ctx, 17, (int16_t)READ16(ADD32(GPR_U32(ctx, 22), 28)));
    // 0x18df04: 0x10000061
    ctx->pc = 0x18DF04u;
    {
        const bool branch_taken_0x18df04 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18DF08u;
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x18df04) {
            ctx->pc = 0x18E08Cu;
            goto label_18e08c;
        }
    }
    ctx->pc = 0x18DF0Cu;
label_18df0c:
    // 0x18df0c: 0x24020004
    ctx->pc = 0x18df0cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
    // 0x18df10: 0x731821
    ctx->pc = 0x18df10u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 19)));
    // 0x18df14: 0x318c0
    ctx->pc = 0x18df14u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 3));
    // 0x18df18: 0x7d1821
    ctx->pc = 0x18df18u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 29)));
    // 0x18df1c: 0x8c630114
    ctx->pc = 0x18df1cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 3), 276)));
    // 0x18df20: 0x1062004a
    ctx->pc = 0x18DF20u;
    {
        const bool branch_taken_0x18df20 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x18DF24u;
        { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 17); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
        if (branch_taken_0x18df20) {
            ctx->pc = 0x18E04Cu;
            goto label_18e04c;
        }
    }
    ctx->pc = 0x18DF28u;
    // 0x18df28: 0x24020003
    ctx->pc = 0x18df28u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
    // 0x18df2c: 0x1062003d
    ctx->pc = 0x18DF2Cu;
    {
        const bool branch_taken_0x18df2c = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x18DF30u;
        { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 17); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
        if (branch_taken_0x18df2c) {
            ctx->pc = 0x18E024u;
            goto label_18e024;
        }
    }
    ctx->pc = 0x18DF34u;
    // 0x18df34: 0x24020002
    ctx->pc = 0x18df34u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
    // 0x18df38: 0x10620030
    ctx->pc = 0x18DF38u;
    {
        const bool branch_taken_0x18df38 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x18DF3Cu;
        { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 17); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
        if (branch_taken_0x18df38) {
            ctx->pc = 0x18DFFCu;
            goto label_18dffc;
        }
    }
    ctx->pc = 0x18DF40u;
    // 0x18df40: 0x24020001
    ctx->pc = 0x18df40u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x18df44: 0x10620019
    ctx->pc = 0x18DF44u;
    {
        const bool branch_taken_0x18df44 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        if (branch_taken_0x18df44) {
            ctx->pc = 0x18DFACu;
            goto label_18dfac;
        }
    }
    ctx->pc = 0x18DF4Cu;
    // 0x18df4c: 0x10600003
    ctx->pc = 0x18DF4Cu;
    {
        const bool branch_taken_0x18df4c = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x18DF50u;
        { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 17); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
        if (branch_taken_0x18df4c) {
            ctx->pc = 0x18DF5Cu;
            goto label_18df5c;
        }
    }
    ctx->pc = 0x18DF54u;
    // 0x18df54: 0x1000004a
    ctx->pc = 0x18DF54u;
    {
        const bool branch_taken_0x18df54 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18DF58u;
        SET_GPR_S32(ctx, 18, SRA32(GPR_S32(ctx, 18), 1));
        if (branch_taken_0x18df54) {
            ctx->pc = 0x18E080u;
            goto label_18e080;
        }
    }
    ctx->pc = 0x18DF5Cu;
label_18df5c:
    // 0x18df5c: 0x2a0202d
    ctx->pc = 0x18df5cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18df60: 0x260282d
    ctx->pc = 0x18df60u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18df64: 0xc0695e4
    ctx->pc = 0x18DF64u;
    SET_GPR_U32(ctx, 31, 0x18DF6Cu);
    ctx->pc = 0x18DF68u;
    SET_GPR_S32(ctx, 16, SRA32(GPR_S32(ctx, 2), 1));
    ctx->pc = 0x1A5790u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5790_0x1a5790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DF6Cu; }
    }
    if (ctx->pc != 0x18DF6Cu) { return; }
    ctx->pc = 0x18DF6Cu;
    // 0x18df6c: 0x82c30036
    ctx->pc = 0x18df6cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 22), 54)));
    // 0x18df70: 0x14600007
    ctx->pc = 0x18DF70u;
    {
        const bool branch_taken_0x18df70 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x18DF74u;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x18df70) {
            ctx->pc = 0x18DF90u;
            goto label_18df90;
        }
    }
    ctx->pc = 0x18DF78u;
    // 0x18df78: 0x40282d
    ctx->pc = 0x18df78u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18df7c: 0x280202d
    ctx->pc = 0x18df7cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18df80: 0xc0636ec
    ctx->pc = 0x18DF80u;
    SET_GPR_U32(ctx, 31, 0x18DF88u);
    ctx->pc = 0x18DF84u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18DBB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DBB0_0x18dbb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DF88u; }
    }
    if (ctx->pc != 0x18DF88u) { return; }
    ctx->pc = 0x18DF88u;
    // 0x18df88: 0x1000003c
    ctx->pc = 0x18DF88u;
    {
        const bool branch_taken_0x18df88 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x18df88) {
            ctx->pc = 0x18E07Cu;
            goto label_18e07c;
        }
    }
    ctx->pc = 0x18DF90u;
label_18df90:
    // 0x18df90: 0x240202d
    ctx->pc = 0x18df90u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18df94: 0x220282d
    ctx->pc = 0x18df94u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18df98: 0x280382d
    ctx->pc = 0x18df98u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18df9c: 0xc067910
    ctx->pc = 0x18DF9Cu;
    SET_GPR_U32(ctx, 31, 0x18DFA4u);
    ctx->pc = 0x18DFA0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x19E440u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0019E440_0x19e440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DFA4u; }
    }
    if (ctx->pc != 0x18DFA4u) { return; }
    ctx->pc = 0x18DFA4u;
    // 0x18dfa4: 0x10000035
    ctx->pc = 0x18DFA4u;
    {
        const bool branch_taken_0x18dfa4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x18dfa4) {
            ctx->pc = 0x18E07Cu;
            goto label_18e07c;
        }
    }
    ctx->pc = 0x18DFACu;
label_18dfac:
    // 0x18dfac: 0x2518018
    ctx->pc = 0x18dfacu;
    { int64_t result = (int64_t)GPR_S32(ctx, 18) * (int64_t)GPR_S32(ctx, 17); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 16, (int32_t)(uint32_t)result); }
    // 0x18dfb0: 0x2a0202d
    ctx->pc = 0x18dfb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18dfb4: 0xc0695e4
    ctx->pc = 0x18DFB4u;
    SET_GPR_U32(ctx, 31, 0x18DFBCu);
    ctx->pc = 0x18DFB8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1A5790u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5790_0x1a5790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DFBCu; }
    }
    if (ctx->pc != 0x18DFBCu) { return; }
    ctx->pc = 0x18DFBCu;
    // 0x18dfbc: 0x82c30036
    ctx->pc = 0x18dfbcu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 22), 54)));
    // 0x18dfc0: 0x14600007
    ctx->pc = 0x18DFC0u;
    {
        const bool branch_taken_0x18dfc0 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x18DFC4u;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x18dfc0) {
            ctx->pc = 0x18DFE0u;
            goto label_18dfe0;
        }
    }
    ctx->pc = 0x18DFC8u;
    // 0x18dfc8: 0x40282d
    ctx->pc = 0x18dfc8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18dfcc: 0x280202d
    ctx->pc = 0x18dfccu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18dfd0: 0xc0636ec
    ctx->pc = 0x18DFD0u;
    SET_GPR_U32(ctx, 31, 0x18DFD8u);
    ctx->pc = 0x18DFD4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18DBB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DBB0_0x18dbb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DFD8u; }
    }
    if (ctx->pc != 0x18DFD8u) { return; }
    ctx->pc = 0x18DFD8u;
    // 0x18dfd8: 0x10000028
    ctx->pc = 0x18DFD8u;
    {
        const bool branch_taken_0x18dfd8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x18dfd8) {
            ctx->pc = 0x18E07Cu;
            goto label_18e07c;
        }
    }
    ctx->pc = 0x18DFE0u;
label_18dfe0:
    // 0x18dfe0: 0x240202d
    ctx->pc = 0x18dfe0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18dfe4: 0x220282d
    ctx->pc = 0x18dfe4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18dfe8: 0x280382d
    ctx->pc = 0x18dfe8u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18dfec: 0xc067910
    ctx->pc = 0x18DFECu;
    SET_GPR_U32(ctx, 31, 0x18DFF4u);
    ctx->pc = 0x18DFF0u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x19E440u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0019E440_0x19e440(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18DFF4u; }
    }
    if (ctx->pc != 0x18DFF4u) { return; }
    ctx->pc = 0x18DFF4u;
    // 0x18dff4: 0x10000021
    ctx->pc = 0x18DFF4u;
    {
        const bool branch_taken_0x18dff4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x18dff4) {
            ctx->pc = 0x18E07Cu;
            goto label_18e07c;
        }
    }
    ctx->pc = 0x18DFFCu;
label_18dffc:
    // 0x18dffc: 0x2a0202d
    ctx->pc = 0x18dffcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e000: 0x260282d
    ctx->pc = 0x18e000u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e004: 0xc0695e4
    ctx->pc = 0x18E004u;
    SET_GPR_U32(ctx, 31, 0x18E00Cu);
    ctx->pc = 0x18E008u;
    SET_GPR_U32(ctx, 16, SLL32(GPR_U32(ctx, 2), 1));
    ctx->pc = 0x1A5790u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5790_0x1a5790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E00Cu; }
    }
    if (ctx->pc != 0x18E00Cu) { return; }
    ctx->pc = 0x18E00Cu;
    // 0x18e00c: 0x40282d
    ctx->pc = 0x18e00cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e010: 0x280202d
    ctx->pc = 0x18e010u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e014: 0xc0636ec
    ctx->pc = 0x18E014u;
    SET_GPR_U32(ctx, 31, 0x18E01Cu);
    ctx->pc = 0x18E018u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18DBB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DBB0_0x18dbb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E01Cu; }
    }
    if (ctx->pc != 0x18E01Cu) { return; }
    ctx->pc = 0x18E01Cu;
    // 0x18e01c: 0x10000017
    ctx->pc = 0x18E01Cu;
    {
        const bool branch_taken_0x18e01c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x18e01c) {
            ctx->pc = 0x18E07Cu;
            goto label_18e07c;
        }
    }
    ctx->pc = 0x18E024u;
label_18e024:
    // 0x18e024: 0x2a0202d
    ctx->pc = 0x18e024u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e028: 0x260282d
    ctx->pc = 0x18e028u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e02c: 0xc0695e4
    ctx->pc = 0x18E02Cu;
    SET_GPR_U32(ctx, 31, 0x18E034u);
    ctx->pc = 0x18E030u;
    SET_GPR_U32(ctx, 16, SLL32(GPR_U32(ctx, 2), 2));
    ctx->pc = 0x1A5790u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5790_0x1a5790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E034u; }
    }
    if (ctx->pc != 0x18E034u) { return; }
    ctx->pc = 0x18E034u;
    // 0x18e034: 0x40282d
    ctx->pc = 0x18e034u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e038: 0x280202d
    ctx->pc = 0x18e038u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e03c: 0xc0636ec
    ctx->pc = 0x18E03Cu;
    SET_GPR_U32(ctx, 31, 0x18E044u);
    ctx->pc = 0x18E040u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18DBB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DBB0_0x18dbb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E044u; }
    }
    if (ctx->pc != 0x18E044u) { return; }
    ctx->pc = 0x18E044u;
    // 0x18e044: 0x1000000d
    ctx->pc = 0x18E044u;
    {
        const bool branch_taken_0x18e044 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x18e044) {
            ctx->pc = 0x18E07Cu;
            goto label_18e07c;
        }
    }
    ctx->pc = 0x18E04Cu;
label_18e04c:
    // 0x18e04c: 0x2a0202d
    ctx->pc = 0x18e04cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e050: 0x260282d
    ctx->pc = 0x18e050u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e054: 0xc0695e4
    ctx->pc = 0x18E054u;
    SET_GPR_U32(ctx, 31, 0x18E05Cu);
    ctx->pc = 0x18E058u;
    SET_GPR_U32(ctx, 16, SLL32(GPR_U32(ctx, 2), 2));
    ctx->pc = 0x1A5790u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5790_0x1a5790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E05Cu; }
    }
    if (ctx->pc != 0x18E05Cu) { return; }
    ctx->pc = 0x18E05Cu;
    // 0x18e05c: 0x40282d
    ctx->pc = 0x18e05cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e060: 0x280202d
    ctx->pc = 0x18e060u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e064: 0xc0636ec
    ctx->pc = 0x18E064u;
    SET_GPR_U32(ctx, 31, 0x18E06Cu);
    ctx->pc = 0x18E068u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18DBB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DBB0_0x18dbb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E06Cu; }
    }
    if (ctx->pc != 0x18E06Cu) { return; }
    ctx->pc = 0x18E06Cu;
    // 0x18e06c: 0x280202d
    ctx->pc = 0x18e06cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e070: 0x240282d
    ctx->pc = 0x18e070u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e074: 0xc06386c
    ctx->pc = 0x18E074u;
    SET_GPR_U32(ctx, 31, 0x18E07Cu);
    ctx->pc = 0x18E078u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18E1B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018E1B0_0x18e1b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E07Cu; }
    }
    if (ctx->pc != 0x18E07Cu) { return; }
    ctx->pc = 0x18E07Cu;
label_18e07c:
    // 0x18e07c: 0x129043
    ctx->pc = 0x18e07cu;
    SET_GPR_S32(ctx, 18, SRA32(GPR_S32(ctx, 18), 1));
label_18e080:
    // 0x18e080: 0x118843
    ctx->pc = 0x18e080u;
    SET_GPR_S32(ctx, 17, SRA32(GPR_S32(ctx, 17), 1));
    // 0x18e084: 0x290a021
    ctx->pc = 0x18e084u;
    SET_GPR_U32(ctx, 20, ADD32(GPR_U32(ctx, 20), GPR_U32(ctx, 16)));
    // 0x18e088: 0x26730001
    ctx->pc = 0x18e088u;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 19), 1));
label_18e08c:
    // 0x18e08c: 0x8fa200a8
    ctx->pc = 0x18e08cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x18e090: 0x53082a
    ctx->pc = 0x18e090u;
    SET_GPR_U32(ctx, 1, SLT32(GPR_S32(ctx, 2), GPR_S32(ctx, 19)));
    // 0x18e094: 0x1020ff9d
    ctx->pc = 0x18E094u;
    {
        const bool branch_taken_0x18e094 = (GPR_U32(ctx, 1) == GPR_U32(ctx, 0));
        ctx->pc = 0x18E098u;
        SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 19), 3));
        if (branch_taken_0x18e094) {
            ctx->pc = 0x18DF0Cu;
            goto label_18df0c;
        }
    }
    ctx->pc = 0x18E09Cu;
    // 0x18e09c: 0x8fa400ac
    ctx->pc = 0x18e09cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x18e0a0: 0xc067350
    ctx->pc = 0x18E0A0u;
    SET_GPR_U32(ctx, 31, 0x18E0A8u);
    ctx->pc = 0x18E0A4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x19CD40u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0019CD40_0x19cd40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E0A8u; }
    }
    if (ctx->pc != 0x18E0A8u) { return; }
    ctx->pc = 0x18E0A8u;
    // 0x18e0a8: 0x8ec30020
    ctx->pc = 0x18e0a8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 22), 32)));
    // 0x18e0ac: 0x24020014
    ctx->pc = 0x18e0acu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 20));
    // 0x18e0b0: 0x10620003
    ctx->pc = 0x18E0B0u;
    {
        const bool branch_taken_0x18e0b0 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x18E0B4u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 19));
        if (branch_taken_0x18e0b0) {
            ctx->pc = 0x18E0C0u;
            goto label_18e0c0;
        }
    }
    ctx->pc = 0x18E0B8u;
    // 0x18e0b8: 0x1462002d
    ctx->pc = 0x18E0B8u;
    {
        const bool branch_taken_0x18e0b8 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        if (branch_taken_0x18e0b8) {
            ctx->pc = 0x18E170u;
            goto label_18e170;
        }
    }
    ctx->pc = 0x18E0C0u;
label_18e0c0:
    // 0x18e0c0: 0xc0674fc
    ctx->pc = 0x18E0C0u;
    SET_GPR_U32(ctx, 31, 0x18E0C8u);
    ctx->pc = 0x19D3F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D3F0_0x19d3f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E0C8u; }
    }
    if (ctx->pc != 0x18E0C8u) { return; }
    ctx->pc = 0x18E0C8u;
    // 0x18e0c8: 0x40b82d
    ctx->pc = 0x18e0c8u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e0cc: 0x27a400b0
    ctx->pc = 0x18e0ccu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 176));
    // 0x18e0d0: 0x3c02ffff
    ctx->pc = 0x18e0d0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)65535 << 16));
    // 0x18e0d4: 0x2a0282d
    ctx->pc = 0x18e0d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e0d8: 0x2e21824
    ctx->pc = 0x18e0d8u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 23), GPR_U32(ctx, 2)));
    // 0x18e0dc: 0x31c02
    ctx->pc = 0x18e0dcu;
    SET_GPR_U32(ctx, 3, SRL32(GPR_U32(ctx, 3), 16));
    // 0x18e0e0: 0x3c020029
    ctx->pc = 0x18e0e0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)41 << 16));
    // 0x18e0e4: 0x2466ffff
    ctx->pc = 0x18e0e4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x18e0e8: 0x24424e80
    ctx->pc = 0x18e0e8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 20096));
    // 0x18e0ec: 0x618c0
    ctx->pc = 0x18e0ecu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 6), 3));
    // 0x18e0f0: 0x661823
    ctx->pc = 0x18e0f0u;
    SET_GPR_U32(ctx, 3, SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x18e0f4: 0x318c0
    ctx->pc = 0x18e0f4u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 3));
    // 0x18e0f8: 0xc06955c
    ctx->pc = 0x18E0F8u;
    SET_GPR_U32(ctx, 31, 0x18E100u);
    ctx->pc = 0x18E0FCu;
    SET_GPR_U32(ctx, 16, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    ctx->pc = 0x1A5570u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A5570_0x1a5570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E100u; }
    }
    if (ctx->pc != 0x18E100u) { return; }
    ctx->pc = 0x18E100u;
    // 0x18e100: 0x27a400b0
    ctx->pc = 0x18e100u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 29), 176));
    // 0x18e104: 0x2e0282d
    ctx->pc = 0x18e104u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e108: 0xc06745c
    ctx->pc = 0x18E108u;
    SET_GPR_U32(ctx, 31, 0x18E110u);
    ctx->pc = 0x18E10Cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x19D170u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D170_0x19d170(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E110u; }
    }
    if (ctx->pc != 0x18E110u) { return; }
    ctx->pc = 0x18E110u;
    // 0x18e110: 0x8e040008
    ctx->pc = 0x18e110u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x18e114: 0xc063714
    ctx->pc = 0x18E114u;
    SET_GPR_U32(ctx, 31, 0x18E11Cu);
    ctx->pc = 0x18E118u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x18DC50u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DC50_0x18dc50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E11Cu; }
    }
    if (ctx->pc != 0x18E11Cu) { return; }
    ctx->pc = 0x18E11Cu;
    // 0x18e11c: 0xae020024
    ctx->pc = 0x18e11cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 36), GPR_U32(ctx, 2));
    // 0x18e120: 0xc063728
    ctx->pc = 0x18E120u;
    SET_GPR_U32(ctx, 31, 0x18E128u);
    ctx->pc = 0x18E124u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 36)));
    ctx->pc = 0x18DCA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E128u; }
    }
    if (ctx->pc != 0x18E128u) { return; }
    ctx->pc = 0x18E128u;
    // 0x18e128: 0x2a0202d
    ctx->pc = 0x18e128u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e12c: 0xc0695e8
    ctx->pc = 0x18E12Cu;
    SET_GPR_U32(ctx, 31, 0x18E134u);
    ctx->pc = 0x18E130u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1A57A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A57A0_0x1a57a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E134u; }
    }
    if (ctx->pc != 0x18E134u) { return; }
    ctx->pc = 0x18E134u;
    // 0x18e134: 0x8e060008
    ctx->pc = 0x18e134u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x18e138: 0x40282d
    ctx->pc = 0x18e138u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x18e13c: 0xc0636ec
    ctx->pc = 0x18E13Cu;
    SET_GPR_U32(ctx, 31, 0x18E144u);
    ctx->pc = 0x18E140u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18DBB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DBB0_0x18dbb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E144u; }
    }
    if (ctx->pc != 0x18E144u) { return; }
    ctx->pc = 0x18E144u;
    // 0x18e144: 0x8fa300c4
    ctx->pc = 0x18e144u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 196)));
    // 0x18e148: 0x24020004
    ctx->pc = 0x18e148u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
    // 0x18e14c: 0x14620006
    ctx->pc = 0x18E14Cu;
    {
        const bool branch_taken_0x18e14c = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x18E150u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x18e14c) {
            ctx->pc = 0x18E168u;
            goto label_18e168;
        }
    }
    ctx->pc = 0x18E154u;
    // 0x18e154: 0x8605001a
    ctx->pc = 0x18e154u;
    SET_GPR_S32(ctx, 5, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 26)));
    // 0x18e158: 0x8606001c
    ctx->pc = 0x18e158u;
    SET_GPR_S32(ctx, 6, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x18e15c: 0xc06386c
    ctx->pc = 0x18E15Cu;
    SET_GPR_U32(ctx, 31, 0x18E164u);
    ctx->pc = 0x18E160u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18E1B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018E1B0_0x18e1b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E164u; }
    }
    if (ctx->pc != 0x18E164u) { return; }
    ctx->pc = 0x18E164u;
    // 0x18e164: 0x3c0282d
    ctx->pc = 0x18e164u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
label_18e168:
    // 0x18e168: 0xc0674b8
    ctx->pc = 0x18E168u;
    SET_GPR_U32(ctx, 31, 0x18E170u);
    ctx->pc = 0x18E16Cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x19D2E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0019D2E0_0x19d2e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18E170u; }
    }
    if (ctx->pc != 0x18E170u) { return; }
    ctx->pc = 0x18E170u;
label_18e170:
    // 0x18e170: 0x8fa200ac
    ctx->pc = 0x18e170u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 172)));
    // 0x18e174: 0x571025
    ctx->pc = 0x18e174u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 23)));
label_18e178:
    // 0x18e178: 0xdfbf0090
    ctx->pc = 0x18e178u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x18e17c: 0x7bbe0080
    ctx->pc = 0x18e17cu;
    SET_GPR_VEC(ctx, 30, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x18e180: 0x7bb70070
    ctx->pc = 0x18e180u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x18e184: 0x7bb60060
    ctx->pc = 0x18e184u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x18e188: 0x7bb50050
    ctx->pc = 0x18e188u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x18e18c: 0x7bb40040
    ctx->pc = 0x18e18cu;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x18e190: 0x7bb30030
    ctx->pc = 0x18e190u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x18e194: 0x7bb20020
    ctx->pc = 0x18e194u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x18e198: 0x7bb10010
    ctx->pc = 0x18e198u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x18e19c: 0x7bb00000
    ctx->pc = 0x18e19cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x18e1a0: 0x3e00008
    ctx->pc = 0x18E1A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18E1A4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 768));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18DEC8u: goto label_18dec8;
            case 0x18DF0Cu: goto label_18df0c;
            case 0x18DF5Cu: goto label_18df5c;
            case 0x18DF90u: goto label_18df90;
            case 0x18DFACu: goto label_18dfac;
            case 0x18DFE0u: goto label_18dfe0;
            case 0x18DFFCu: goto label_18dffc;
            case 0x18E024u: goto label_18e024;
            case 0x18E04Cu: goto label_18e04c;
            case 0x18E07Cu: goto label_18e07c;
            case 0x18E080u: goto label_18e080;
            case 0x18E08Cu: goto label_18e08c;
            case 0x18E0C0u: goto label_18e0c0;
            case 0x18E168u: goto label_18e168;
            case 0x18E170u: goto label_18e170;
            case 0x18E178u: goto label_18e178;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18E1A8u;
    // 0x18e1a8: 0x0
    ctx->pc = 0x18e1a8u;
    // NOP
    // 0x18e1ac: 0x0
    ctx->pc = 0x18e1acu;
    // NOP
}
