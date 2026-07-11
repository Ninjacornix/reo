#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: entry_13d6d8
// Address: 0x13d6d8 - 0x13d800
void entry_13d6d8_0x13d800(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x13d6d8u;

    // 0x13d6d8: 0x27bdffe0
    ctx->pc = 0x13d6d8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x13d6dc: 0xffb00000
    ctx->pc = 0x13d6dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x13d6e0: 0x80802d
    ctx->pc = 0x13d6e0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d6e4: 0xffb10008
    ctx->pc = 0x13d6e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x13d6e8: 0xffb20010
    ctx->pc = 0x13d6e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x13d6ec: 0xffbf0018
    ctx->pc = 0x13d6ecu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x13d6f0: 0x8e020020
    ctx->pc = 0x13d6f0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x13d6f4: 0x8e030024
    ctx->pc = 0x13d6f4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 36)));
    // 0x13d6f8: 0x21140
    ctx->pc = 0x13d6f8u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 5));
    // 0x13d6fc: 0x2021021
    ctx->pc = 0x13d6fcu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 2)));
    // 0x13d700: 0x18600039
    ctx->pc = 0x13D700u;
    {
        const bool branch_taken_0x13d700 = (GPR_S32(ctx, 3) <= 0);
        ctx->pc = 0x13D704u;
        SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 2), 56));
        if (branch_taken_0x13d700) {
            ctx->pc = 0x13D7E8u;
            goto label_13d7e8;
        }
    }
    ctx->pc = 0x13D708u;
    // 0x13d708: 0xc04c1b8
    ctx->pc = 0x13D708u;
    SET_GPR_U32(ctx, 31, 0x13D710u);
    ctx->pc = 0x13D70Cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 40)));
    ctx->pc = 0x1306E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001306E0_0x1306e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D710u; }
    }
    if (ctx->pc != 0x13D710u) { return; }
    ctx->pc = 0x13D710u;
    // 0x13d710: 0xc04c148
    ctx->pc = 0x13D710u;
    SET_GPR_U32(ctx, 31, 0x13D718u);
    ctx->pc = 0x13D714u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 40)));
    ctx->pc = 0x130520u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00130520_0x130520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D718u; }
    }
    if (ctx->pc != 0x13D718u) { return; }
    ctx->pc = 0x13D718u;
    // 0x13d718: 0x8e320004
    ctx->pc = 0x13d718u;
    SET_GPR_U32(ctx, 18, READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13d71c: 0xc042c56
    ctx->pc = 0x13D71Cu;
    SET_GPR_U32(ctx, 31, 0x13D724u);
    ctx->pc = 0x13D720u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10B158u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D724u; }
    }
    if (ctx->pc != 0x13D724u) { return; }
    ctx->pc = 0x13D724u;
    // 0x13d724: 0x282d
    ctx->pc = 0x13d724u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d728: 0x40302d
    ctx->pc = 0x13d728u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x13d72c: 0x10c00009
    ctx->pc = 0x13D72Cu;
    {
        const bool branch_taken_0x13d72c = (GPR_U32(ctx, 6) == GPR_U32(ctx, 0));
        ctx->pc = 0x13D730u;
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x13d72c) {
            ctx->pc = 0x13D754u;
            goto label_13d754;
        }
    }
    ctx->pc = 0x13D734u;
    // 0x13d734: 0x0
    ctx->pc = 0x13d734u;
    // NOP
label_13d738:
    // 0x13d738: 0x2451021
    ctx->pc = 0x13d738u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 5)));
    // 0x13d73c: 0x24a50001
    ctx->pc = 0x13d73cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 1));
    // 0x13d740: 0x90430000
    ctx->pc = 0x13d740u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x13d744: 0xa6202b
    ctx->pc = 0x13d744u;
    SET_GPR_U32(ctx, 4, SLTU32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x13d748: 0x0
    ctx->pc = 0x13d748u;
    // NOP
    // 0x13d74c: 0x1480fffa
    ctx->pc = 0x13D74Cu;
    {
        const bool branch_taken_0x13d74c = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x13D750u;
        SET_GPR_U32(ctx, 7, ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 3)));
        if (branch_taken_0x13d74c) {
            ctx->pc = 0x13D738u;
            goto label_13d738;
        }
    }
    ctx->pc = 0x13D754u;
label_13d754:
    // 0x13d754: 0x8e220008
    ctx->pc = 0x13d754u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x13d758: 0x10e20009
    ctx->pc = 0x13D758u;
    {
        const bool branch_taken_0x13d758 = (GPR_U32(ctx, 7) == GPR_U32(ctx, 2));
        ctx->pc = 0x13D75Cu;
        SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
        if (branch_taken_0x13d758) {
            ctx->pc = 0x13D780u;
            goto label_13d780;
        }
    }
    ctx->pc = 0x13D760u;
    // 0x13d760: 0x8e250004
    ctx->pc = 0x13d760u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x13d764: 0xdfb00000
    ctx->pc = 0x13d764u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d768: 0x2484d458
    ctx->pc = 0x13d768u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294956120));
    // 0x13d76c: 0xdfb10008
    ctx->pc = 0x13d76cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13d770: 0xdfb20010
    ctx->pc = 0x13d770u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13d774: 0xdfbf0018
    ctx->pc = 0x13d774u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13d778: 0x804f53e
    ctx->pc = 0x13D778u;
    ctx->pc = 0x13D77Cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x13D4F8u;
    sub_0013D4F8_0x13d4f8(rdram, ctx, runtime); return;
    ctx->pc = 0x13D780u;
label_13d780:
    // 0x13d780: 0x8e270010
    ctx->pc = 0x13d780u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x13d784: 0x8e280014
    ctx->pc = 0x13d784u;
    SET_GPR_U32(ctx, 8, READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x13d788: 0x8e26000c
    ctx->pc = 0x13d788u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x13d78c: 0x8e040028
    ctx->pc = 0x13d78cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x13d790: 0xc04c11e
    ctx->pc = 0x13D790u;
    SET_GPR_U32(ctx, 31, 0x13D798u);
    ctx->pc = 0x13D794u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 17), 4)));
    ctx->pc = 0x130478u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00130478_0x130478(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D798u; }
    }
    if (ctx->pc != 0x13D798u) { return; }
    ctx->pc = 0x13D798u;
    // 0x13d798: 0x8e040028
    ctx->pc = 0x13d798u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x13d79c: 0xc04c1ea
    ctx->pc = 0x13D79Cu;
    SET_GPR_U32(ctx, 31, 0x13D7A4u);
    ctx->pc = 0x13D7A0u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 17), 20)));
    ctx->pc = 0x1307A8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001307A8_0x1307a8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D7A4u; }
    }
    if (ctx->pc != 0x13D7A4u) { return; }
    ctx->pc = 0x13D7A4u;
    // 0x13d7a4: 0x8e220014
    ctx->pc = 0x13d7a4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x13d7a8: 0x8e040028
    ctx->pc = 0x13d7a8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x13d7ac: 0xae02002c
    ctx->pc = 0x13d7acu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 2));
    // 0x13d7b0: 0xae20001c
    ctx->pc = 0x13d7b0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 28), GPR_U32(ctx, 0));
    // 0x13d7b4: 0xa2000002
    ctx->pc = 0x13d7b4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 0));
    // 0x13d7b8: 0x8e060018
    ctx->pc = 0x13d7b8u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x13d7bc: 0xc04c386
    ctx->pc = 0x13D7BCu;
    SET_GPR_U32(ctx, 31, 0x13D7C4u);
    ctx->pc = 0x13D7C0u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 20)));
    ctx->pc = 0x130E18u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00130E18_0x130e18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D7C4u; }
    }
    if (ctx->pc != 0x13D7C4u) { return; }
    ctx->pc = 0x13D7C4u;
    // 0x13d7c4: 0x8e040028
    ctx->pc = 0x13d7c4u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 40)));
    // 0x13d7c8: 0xc04c170
    ctx->pc = 0x13D7C8u;
    SET_GPR_U32(ctx, 31, 0x13D7D0u);
    ctx->pc = 0x13D7CCu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1305C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001305C0_0x1305c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D7D0u; }
    }
    if (ctx->pc != 0x13D7D0u) { return; }
    ctx->pc = 0x13D7D0u;
    // 0x13d7d0: 0xc04c196
    ctx->pc = 0x13D7D0u;
    SET_GPR_U32(ctx, 31, 0x13D7D8u);
    ctx->pc = 0x13D7D4u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 40)));
    ctx->pc = 0x130658u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00130658_0x130658(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x13D7D8u; }
    }
    if (ctx->pc != 0x13D7D8u) { return; }
    ctx->pc = 0x13D7D8u;
    // 0x13d7d8: 0x24030001
    ctx->pc = 0x13d7d8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x13d7dc: 0x24020001
    ctx->pc = 0x13d7dcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x13d7e0: 0xa2030002
    ctx->pc = 0x13d7e0u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 2), (uint8_t)GPR_U32(ctx, 3));
    // 0x13d7e4: 0xae220018
    ctx->pc = 0x13d7e4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 2));
label_13d7e8:
    // 0x13d7e8: 0xdfb00000
    ctx->pc = 0x13d7e8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13d7ec: 0xdfb10008
    ctx->pc = 0x13d7ecu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x13d7f0: 0xdfb20010
    ctx->pc = 0x13d7f0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x13d7f4: 0xdfbf0018
    ctx->pc = 0x13d7f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13d7f8: 0x3e00008
    ctx->pc = 0x13D7F8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x13D7FCu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x13D738u: goto label_13d738;
            case 0x13D754u: goto label_13d754;
            case 0x13D780u: goto label_13d780;
            case 0x13D7E8u: goto label_13d7e8;
            default: break;
        }
        return;
    }
    ctx->pc = 0x13D800u;
}
