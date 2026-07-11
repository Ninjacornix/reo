#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001DF99C
// Address: 0x1df99c - 0x1dfda8
void sub_001DF99C_0x1df99c(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1df99cu;

    // 0x1df99c: 0x27bdff40
    ctx->pc = 0x1df99cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x1df9a0: 0xffbe00b0
    ctx->pc = 0x1df9a0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 30));
    // 0x1df9a4: 0xffbf00b8
    ctx->pc = 0x1df9a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 184), GPR_U64(ctx, 31));
    // 0x1df9a8: 0x3a0f02d
    ctx->pc = 0x1df9a8u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df9ac: 0xafc40000
    ctx->pc = 0x1df9acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1df9b0: 0xafc50004
    ctx->pc = 0x1df9b0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 5));
    // 0x1df9b4: 0x8fc30000
    ctx->pc = 0x1df9b4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df9b8: 0x8fc20000
    ctx->pc = 0x1df9b8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df9bc: 0x8c4204fc
    ctx->pc = 0x1df9bcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 1276)));
    // 0x1df9c0: 0xac62007c
    ctx->pc = 0x1df9c0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 124), GPR_U32(ctx, 2));
    // 0x1df9c4: 0x8fc20004
    ctx->pc = 0x1df9c4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1df9c8: 0x2442003c
    ctx->pc = 0x1df9c8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 60));
    // 0x1df9cc: 0xafc200a0
    ctx->pc = 0x1df9ccu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 160), GPR_U32(ctx, 2));
    // 0x1df9d0: 0x8fc20000
    ctx->pc = 0x1df9d0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df9d4: 0x244204d4
    ctx->pc = 0x1df9d4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1236));
    // 0x1df9d8: 0x40202d
    ctx->pc = 0x1df9d8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df9dc: 0xc042c56
    ctx->pc = 0x1DF9DCu;
    SET_GPR_U32(ctx, 31, 0x1DF9E4u);
    ctx->pc = 0x10B158u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DF9E4u; }
    }
    if (ctx->pc != 0x1DF9E4u) { return; }
    ctx->pc = 0x1DF9E4u;
    // 0x1df9e4: 0x40382d
    ctx->pc = 0x1df9e4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1df9e8: 0x8fc20000
    ctx->pc = 0x1df9e8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1df9ec: 0x244304d4
    ctx->pc = 0x1df9ecu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 2), 1236));
    // 0x1df9f0: 0x8fc20004
    ctx->pc = 0x1df9f0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1df9f4: 0x2442002c
    ctx->pc = 0x1df9f4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 44));
    // 0x1df9f8: 0x94420000
    ctx->pc = 0x1df9f8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1df9fc: 0x304203ff
    ctx->pc = 0x1df9fcu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 1023));
    // 0x1dfa00: 0x3042ffff
    ctx->pc = 0x1dfa00u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 65535));
    // 0x1dfa04: 0x2442fff0
    ctx->pc = 0x1dfa04u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967280));
    // 0x1dfa08: 0x8fc400a0
    ctx->pc = 0x1dfa08u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 30), 160)));
    // 0x1dfa0c: 0x60282d
    ctx->pc = 0x1dfa0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dfa10: 0x40302d
    ctx->pc = 0x1dfa10u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dfa14: 0x24080114
    ctx->pc = 0x1dfa14u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 276));
    // 0x1dfa18: 0xc07acda
    ctx->pc = 0x1DFA18u;
    SET_GPR_U32(ctx, 31, 0x1DFA20u);
    ctx->pc = 0x1EB368u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001EB368_0x1eb368(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DFA20u; }
    }
    if (ctx->pc != 0x1DFA20u) { return; }
    ctx->pc = 0x1DFA20u;
    // 0x1dfa20: 0xafc20008
    ctx->pc = 0x1dfa20u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 2));
    // 0x1dfa24: 0x8fc50008
    ctx->pc = 0x1dfa24u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfa28: 0x8fc20008
    ctx->pc = 0x1dfa28u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfa2c: 0x8c420000
    ctx->pc = 0x1dfa2cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dfa30: 0x304200ff
    ctx->pc = 0x1dfa30u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 255));
    // 0x1dfa34: 0x21e00
    ctx->pc = 0x1dfa34u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 24));
    // 0x1dfa38: 0x8fc20008
    ctx->pc = 0x1dfa38u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfa3c: 0x8c420000
    ctx->pc = 0x1dfa3cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dfa40: 0x3042ff00
    ctx->pc = 0x1dfa40u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 65280));
    // 0x1dfa44: 0x21200
    ctx->pc = 0x1dfa44u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 8));
    // 0x1dfa48: 0x622025
    ctx->pc = 0x1dfa48u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dfa4c: 0x8fc20008
    ctx->pc = 0x1dfa4cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfa50: 0x8c430000
    ctx->pc = 0x1dfa50u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dfa54: 0x3c0200ff
    ctx->pc = 0x1dfa54u;
    SET_GPR_U32(ctx, 2, ((uint32_t)255 << 16));
    // 0x1dfa58: 0x621024
    ctx->pc = 0x1dfa58u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dfa5c: 0x21202
    ctx->pc = 0x1dfa5cu;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 8));
    // 0x1dfa60: 0x822025
    ctx->pc = 0x1dfa60u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1dfa64: 0x8fc20008
    ctx->pc = 0x1dfa64u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfa68: 0x8c430000
    ctx->pc = 0x1dfa68u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dfa6c: 0x3c02ff00
    ctx->pc = 0x1dfa6cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)65280 << 16));
    // 0x1dfa70: 0x621024
    ctx->pc = 0x1dfa70u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dfa74: 0x21602
    ctx->pc = 0x1dfa74u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 24));
    // 0x1dfa78: 0x821025
    ctx->pc = 0x1dfa78u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1dfa7c: 0xaca20000
    ctx->pc = 0x1dfa7cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
    // 0x1dfa80: 0x8fc50008
    ctx->pc = 0x1dfa80u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfa84: 0x8fc20008
    ctx->pc = 0x1dfa84u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfa88: 0x8c420004
    ctx->pc = 0x1dfa88u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1dfa8c: 0x304200ff
    ctx->pc = 0x1dfa8cu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 255));
    // 0x1dfa90: 0x21e00
    ctx->pc = 0x1dfa90u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 24));
    // 0x1dfa94: 0x8fc20008
    ctx->pc = 0x1dfa94u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfa98: 0x8c420004
    ctx->pc = 0x1dfa98u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1dfa9c: 0x3042ff00
    ctx->pc = 0x1dfa9cu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 65280));
    // 0x1dfaa0: 0x21200
    ctx->pc = 0x1dfaa0u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 8));
    // 0x1dfaa4: 0x622025
    ctx->pc = 0x1dfaa4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dfaa8: 0x8fc20008
    ctx->pc = 0x1dfaa8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfaac: 0x8c430004
    ctx->pc = 0x1dfaacu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1dfab0: 0x3c0200ff
    ctx->pc = 0x1dfab0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)255 << 16));
    // 0x1dfab4: 0x621024
    ctx->pc = 0x1dfab4u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dfab8: 0x21202
    ctx->pc = 0x1dfab8u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 8));
    // 0x1dfabc: 0x822025
    ctx->pc = 0x1dfabcu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1dfac0: 0x8fc20008
    ctx->pc = 0x1dfac0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfac4: 0x8c430004
    ctx->pc = 0x1dfac4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1dfac8: 0x3c02ff00
    ctx->pc = 0x1dfac8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)65280 << 16));
    // 0x1dfacc: 0x621024
    ctx->pc = 0x1dfaccu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dfad0: 0x21602
    ctx->pc = 0x1dfad0u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 24));
    // 0x1dfad4: 0x821025
    ctx->pc = 0x1dfad4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1dfad8: 0xaca20004
    ctx->pc = 0x1dfad8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x1dfadc: 0x8fc50008
    ctx->pc = 0x1dfadcu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfae0: 0x8fc20008
    ctx->pc = 0x1dfae0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfae4: 0x8c420088
    ctx->pc = 0x1dfae4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 136)));
    // 0x1dfae8: 0x304200ff
    ctx->pc = 0x1dfae8u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 255));
    // 0x1dfaec: 0x21e00
    ctx->pc = 0x1dfaecu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 24));
    // 0x1dfaf0: 0x8fc20008
    ctx->pc = 0x1dfaf0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfaf4: 0x8c420088
    ctx->pc = 0x1dfaf4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 136)));
    // 0x1dfaf8: 0x3042ff00
    ctx->pc = 0x1dfaf8u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 65280));
    // 0x1dfafc: 0x21200
    ctx->pc = 0x1dfafcu;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 8));
    // 0x1dfb00: 0x622025
    ctx->pc = 0x1dfb00u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dfb04: 0x8fc20008
    ctx->pc = 0x1dfb04u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfb08: 0x8c430088
    ctx->pc = 0x1dfb08u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 136)));
    // 0x1dfb0c: 0x3c0200ff
    ctx->pc = 0x1dfb0cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)255 << 16));
    // 0x1dfb10: 0x621024
    ctx->pc = 0x1dfb10u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dfb14: 0x21202
    ctx->pc = 0x1dfb14u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 8));
    // 0x1dfb18: 0x822025
    ctx->pc = 0x1dfb18u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1dfb1c: 0x8fc20008
    ctx->pc = 0x1dfb1cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfb20: 0x8c430088
    ctx->pc = 0x1dfb20u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 136)));
    // 0x1dfb24: 0x3c02ff00
    ctx->pc = 0x1dfb24u;
    SET_GPR_U32(ctx, 2, ((uint32_t)65280 << 16));
    // 0x1dfb28: 0x621024
    ctx->pc = 0x1dfb28u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dfb2c: 0x21602
    ctx->pc = 0x1dfb2cu;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 24));
    // 0x1dfb30: 0x821025
    ctx->pc = 0x1dfb30u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1dfb34: 0xaca20088
    ctx->pc = 0x1dfb34u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 136), GPR_U32(ctx, 2));
    // 0x1dfb38: 0x8fc50008
    ctx->pc = 0x1dfb38u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfb3c: 0x8fc20008
    ctx->pc = 0x1dfb3cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfb40: 0x8c42008c
    ctx->pc = 0x1dfb40u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 140)));
    // 0x1dfb44: 0x304200ff
    ctx->pc = 0x1dfb44u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 255));
    // 0x1dfb48: 0x21e00
    ctx->pc = 0x1dfb48u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 24));
    // 0x1dfb4c: 0x8fc20008
    ctx->pc = 0x1dfb4cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfb50: 0x8c42008c
    ctx->pc = 0x1dfb50u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 140)));
    // 0x1dfb54: 0x3042ff00
    ctx->pc = 0x1dfb54u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 65280));
    // 0x1dfb58: 0x21200
    ctx->pc = 0x1dfb58u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 8));
    // 0x1dfb5c: 0x622025
    ctx->pc = 0x1dfb5cu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dfb60: 0x8fc20008
    ctx->pc = 0x1dfb60u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfb64: 0x8c43008c
    ctx->pc = 0x1dfb64u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 140)));
    // 0x1dfb68: 0x3c0200ff
    ctx->pc = 0x1dfb68u;
    SET_GPR_U32(ctx, 2, ((uint32_t)255 << 16));
    // 0x1dfb6c: 0x621024
    ctx->pc = 0x1dfb6cu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dfb70: 0x21202
    ctx->pc = 0x1dfb70u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 8));
    // 0x1dfb74: 0x822025
    ctx->pc = 0x1dfb74u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1dfb78: 0x8fc20008
    ctx->pc = 0x1dfb78u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfb7c: 0x8c43008c
    ctx->pc = 0x1dfb7cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 140)));
    // 0x1dfb80: 0x3c02ff00
    ctx->pc = 0x1dfb80u;
    SET_GPR_U32(ctx, 2, ((uint32_t)65280 << 16));
    // 0x1dfb84: 0x621024
    ctx->pc = 0x1dfb84u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dfb88: 0x21602
    ctx->pc = 0x1dfb88u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 24));
    // 0x1dfb8c: 0x821025
    ctx->pc = 0x1dfb8cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1dfb90: 0xaca2008c
    ctx->pc = 0x1dfb90u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 140), GPR_U32(ctx, 2));
    // 0x1dfb94: 0x8fc20008
    ctx->pc = 0x1dfb94u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfb98: 0x94420000
    ctx->pc = 0x1dfb98u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dfb9c: 0x8fc40000
    ctx->pc = 0x1dfb9cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dfba0: 0x282d
    ctx->pc = 0x1dfba0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dfba4: 0x40302d
    ctx->pc = 0x1dfba4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dfba8: 0xc076bab
    ctx->pc = 0x1DFBA8u;
    SET_GPR_U32(ctx, 31, 0x1DFBB0u);
    ctx->pc = 0x1DAEACu;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001DAEAC_0x1daeac(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DFBB0u; }
    }
    if (ctx->pc != 0x1DFBB0u) { return; }
    ctx->pc = 0x1DFBB0u;
    // 0x1dfbb0: 0x8fc20000
    ctx->pc = 0x1dfbb0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dfbb4: 0x24420484
    ctx->pc = 0x1dfbb4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1156));
    // 0x1dfbb8: 0x40202d
    ctx->pc = 0x1dfbb8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dfbbc: 0xc042c56
    ctx->pc = 0x1DFBBCu;
    SET_GPR_U32(ctx, 31, 0x1DFBC4u);
    ctx->pc = 0x10B158u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DFBC4u; }
    }
    if (ctx->pc != 0x1DFBC4u) { return; }
    ctx->pc = 0x1DFBC4u;
    // 0x1dfbc4: 0x40382d
    ctx->pc = 0x1dfbc4u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dfbc8: 0x8fc20008
    ctx->pc = 0x1dfbc8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfbcc: 0x24440094
    ctx->pc = 0x1dfbccu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 148));
    // 0x1dfbd0: 0x8fc50008
    ctx->pc = 0x1dfbd0u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfbd4: 0x8fc20000
    ctx->pc = 0x1dfbd4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dfbd8: 0x24430484
    ctx->pc = 0x1dfbd8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 2), 1156));
    // 0x1dfbdc: 0x8fc20008
    ctx->pc = 0x1dfbdcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfbe0: 0x24420008
    ctx->pc = 0x1dfbe0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 8));
    // 0x1dfbe4: 0x8fc90008
    ctx->pc = 0x1dfbe4u;
    SET_GPR_U32(ctx, 9, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfbe8: 0x8ca50088
    ctx->pc = 0x1dfbe8u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 5), 136)));
    // 0x1dfbec: 0x60302d
    ctx->pc = 0x1dfbecu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dfbf0: 0x40402d
    ctx->pc = 0x1dfbf0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dfbf4: 0x8d290004
    ctx->pc = 0x1dfbf4u;
    SET_GPR_U32(ctx, 9, READ32(ADD32(GPR_U32(ctx, 9), 4)));
    // 0x1dfbf8: 0xc07c1c6
    ctx->pc = 0x1DFBF8u;
    SET_GPR_U32(ctx, 31, 0x1DFC00u);
    ctx->pc = 0x1F0718u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001F0718_0x1f0718(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DFC00u; }
    }
    if (ctx->pc != 0x1DFC00u) { return; }
    ctx->pc = 0x1DFC00u;
    // 0x1dfc00: 0x8fc40000
    ctx->pc = 0x1dfc00u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dfc04: 0xc076c5b
    ctx->pc = 0x1DFC04u;
    SET_GPR_U32(ctx, 31, 0x1DFC0Cu);
    ctx->pc = 0x1DB16Cu;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB16C_0x1db16c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DFC0Cu; }
    }
    if (ctx->pc != 0x1DFC0Cu) { return; }
    ctx->pc = 0x1DFC0Cu;
    // 0x1dfc0c: 0xafc200a4
    ctx->pc = 0x1dfc0cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 164), GPR_U32(ctx, 2));
    // 0x1dfc10: 0x8fc200a4
    ctx->pc = 0x1dfc10u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 164)));
    // 0x1dfc14: 0x14400006
    ctx->pc = 0x1DFC14u;
    {
        const bool branch_taken_0x1dfc14 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1dfc14) {
            ctx->pc = 0x1DFC30u;
            goto label_1dfc30;
        }
    }
    ctx->pc = 0x1DFC1Cu;
    // 0x1dfc1c: 0x24020065
    ctx->pc = 0x1dfc1cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 101));
    // 0x1dfc20: 0x3c010026
    ctx->pc = 0x1dfc20u;
    SET_GPR_U32(ctx, 1, ((uint32_t)38 << 16));
    // 0x1dfc24: 0xac229d10
    ctx->pc = 0x1dfc24u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294941968), GPR_U32(ctx, 2));
    // 0x1dfc28: 0x10000059
    ctx->pc = 0x1DFC28u;
    {
        const bool branch_taken_0x1dfc28 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dfc28) {
            ctx->pc = 0x1DFD90u;
            goto label_1dfd90;
        }
    }
    ctx->pc = 0x1DFC30u;
label_1dfc30:
    // 0x1dfc30: 0x8fc400a4
    ctx->pc = 0x1dfc30u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 30), 164)));
    // 0x1dfc34: 0x24050088
    ctx->pc = 0x1dfc34u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 136));
    // 0x1dfc38: 0xc07cc3c
    ctx->pc = 0x1DFC38u;
    SET_GPR_U32(ctx, 31, 0x1DFC40u);
    ctx->pc = 0x1F30F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001F30F0_0x1f30f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DFC40u; }
    }
    if (ctx->pc != 0x1DFC40u) { return; }
    ctx->pc = 0x1DFC40u;
    // 0x1dfc40: 0xafc200a0
    ctx->pc = 0x1dfc40u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 160), GPR_U32(ctx, 2));
    // 0x1dfc44: 0x8fc200a0
    ctx->pc = 0x1dfc44u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 160)));
    // 0x1dfc48: 0x1440000b
    ctx->pc = 0x1DFC48u;
    {
        const bool branch_taken_0x1dfc48 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1dfc48) {
            ctx->pc = 0x1DFC78u;
            goto label_1dfc78;
        }
    }
    ctx->pc = 0x1DFC50u;
    // 0x1dfc50: 0x8fc20000
    ctx->pc = 0x1dfc50u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dfc54: 0x8c440520
    ctx->pc = 0x1dfc54u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1dfc58: 0x8fc500a4
    ctx->pc = 0x1dfc58u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 30), 164)));
    // 0x1dfc5c: 0xc07ca04
    ctx->pc = 0x1DFC5Cu;
    SET_GPR_U32(ctx, 31, 0x1DFC64u);
    ctx->pc = 0x1F2810u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DFC64u; }
    }
    if (ctx->pc != 0x1DFC64u) { return; }
    ctx->pc = 0x1DFC64u;
    // 0x1dfc64: 0x24020065
    ctx->pc = 0x1dfc64u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 101));
    // 0x1dfc68: 0x3c010026
    ctx->pc = 0x1dfc68u;
    SET_GPR_U32(ctx, 1, ((uint32_t)38 << 16));
    // 0x1dfc6c: 0xac229d10
    ctx->pc = 0x1dfc6cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294941968), GPR_U32(ctx, 2));
    // 0x1dfc70: 0x10000047
    ctx->pc = 0x1DFC70u;
    {
        const bool branch_taken_0x1dfc70 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dfc70) {
            ctx->pc = 0x1DFD90u;
            goto label_1dfd90;
        }
    }
    ctx->pc = 0x1DFC78u;
label_1dfc78:
    // 0x1dfc78: 0x27c20010
    ctx->pc = 0x1dfc78u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 30), 16));
    // 0x1dfc7c: 0x24440008
    ctx->pc = 0x1dfc7cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 8));
    // 0x1dfc80: 0x8fc20008
    ctx->pc = 0x1dfc80u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfc84: 0x24420094
    ctx->pc = 0x1dfc84u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 148));
    // 0x1dfc88: 0x8fc30008
    ctx->pc = 0x1dfc88u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfc8c: 0x40282d
    ctx->pc = 0x1dfc8cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dfc90: 0x8c66008c
    ctx->pc = 0x1dfc90u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 3), 140)));
    // 0x1dfc94: 0xc041eac
    ctx->pc = 0x1DFC94u;
    SET_GPR_U32(ctx, 31, 0x1DFC9Cu);
    ctx->pc = 0x107AB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DFC9Cu; }
    }
    if (ctx->pc != 0x1DFC9Cu) { return; }
    ctx->pc = 0x1DFC9Cu;
    // 0x1dfc9c: 0x8fc20008
    ctx->pc = 0x1dfc9cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dfca0: 0x8c42008c
    ctx->pc = 0x1dfca0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 140)));
    // 0x1dfca4: 0xafc20010
    ctx->pc = 0x1dfca4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1dfca8: 0x8fc20010
    ctx->pc = 0x1dfca8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1dfcac: 0x304200ff
    ctx->pc = 0x1dfcacu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 255));
    // 0x1dfcb0: 0x21e00
    ctx->pc = 0x1dfcb0u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 24));
    // 0x1dfcb4: 0x8fc20010
    ctx->pc = 0x1dfcb4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1dfcb8: 0x3042ff00
    ctx->pc = 0x1dfcb8u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 65280));
    // 0x1dfcbc: 0x21200
    ctx->pc = 0x1dfcbcu;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 8));
    // 0x1dfcc0: 0x622025
    ctx->pc = 0x1dfcc0u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dfcc4: 0x8fc30010
    ctx->pc = 0x1dfcc4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1dfcc8: 0x3c0200ff
    ctx->pc = 0x1dfcc8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)255 << 16));
    // 0x1dfccc: 0x621024
    ctx->pc = 0x1dfcccu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dfcd0: 0x21202
    ctx->pc = 0x1dfcd0u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 8));
    // 0x1dfcd4: 0x822025
    ctx->pc = 0x1dfcd4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1dfcd8: 0x8fc30010
    ctx->pc = 0x1dfcd8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 16)));
    // 0x1dfcdc: 0x3c02ff00
    ctx->pc = 0x1dfcdcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)65280 << 16));
    // 0x1dfce0: 0x621024
    ctx->pc = 0x1dfce0u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dfce4: 0x21602
    ctx->pc = 0x1dfce4u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 24));
    // 0x1dfce8: 0x821025
    ctx->pc = 0x1dfce8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1dfcec: 0xafc20010
    ctx->pc = 0x1dfcecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 16), GPR_U32(ctx, 2));
    // 0x1dfcf0: 0x8fc20000
    ctx->pc = 0x1dfcf0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dfcf4: 0x244204d4
    ctx->pc = 0x1dfcf4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1236));
    // 0x1dfcf8: 0x40202d
    ctx->pc = 0x1dfcf8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dfcfc: 0xc042c56
    ctx->pc = 0x1DFCFCu;
    SET_GPR_U32(ctx, 31, 0x1DFD04u);
    ctx->pc = 0x10B158u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010B158_0x10b158(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DFD04u; }
    }
    if (ctx->pc != 0x1DFD04u) { return; }
    ctx->pc = 0x1DFD04u;
    // 0x1dfd04: 0x40402d
    ctx->pc = 0x1dfd04u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dfd08: 0x27c30010
    ctx->pc = 0x1dfd08u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 30), 16));
    // 0x1dfd0c: 0x8fc20000
    ctx->pc = 0x1dfd0cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dfd10: 0x244204d4
    ctx->pc = 0x1dfd10u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1236));
    // 0x1dfd14: 0x8fc400a0
    ctx->pc = 0x1dfd14u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 30), 160)));
    // 0x1dfd18: 0x60282d
    ctx->pc = 0x1dfd18u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dfd1c: 0x24060088
    ctx->pc = 0x1dfd1cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 136));
    // 0x1dfd20: 0x40382d
    ctx->pc = 0x1dfd20u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dfd24: 0xc07ad3e
    ctx->pc = 0x1DFD24u;
    SET_GPR_U32(ctx, 31, 0x1DFD2Cu);
    ctx->pc = 0x1EB4F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001EB4F8_0x1eb4f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DFD2Cu; }
    }
    if (ctx->pc != 0x1DFD2Cu) { return; }
    ctx->pc = 0x1DFD2Cu;
    // 0x1dfd2c: 0xafc200a8
    ctx->pc = 0x1dfd2cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 168), GPR_U32(ctx, 2));
    // 0x1dfd30: 0x97c200a8
    ctx->pc = 0x1dfd30u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 168)));
    // 0x1dfd34: 0x8fc40000
    ctx->pc = 0x1dfd34u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dfd38: 0x8fc500a4
    ctx->pc = 0x1dfd38u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 30), 164)));
    // 0x1dfd3c: 0x3406b000
    ctx->pc = 0x1dfd3cu;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 0), 45056));
    // 0x1dfd40: 0x40382d
    ctx->pc = 0x1dfd40u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dfd44: 0x24080041
    ctx->pc = 0x1dfd44u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 65));
    // 0x1dfd48: 0x482d
    ctx->pc = 0x1dfd48u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dfd4c: 0xc079d8f
    ctx->pc = 0x1DFD4Cu;
    SET_GPR_U32(ctx, 31, 0x1DFD54u);
    ctx->pc = 0x1E763Cu;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001E763C_0x1e763c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DFD54u; }
    }
    if (ctx->pc != 0x1DFD54u) { return; }
    ctx->pc = 0x1DFD54u;
    // 0x1dfd54: 0x10400006
    ctx->pc = 0x1DFD54u;
    {
        const bool branch_taken_0x1dfd54 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dfd54) {
            ctx->pc = 0x1DFD70u;
            goto label_1dfd70;
        }
    }
    ctx->pc = 0x1DFD5Cu;
    // 0x1dfd5c: 0x24020066
    ctx->pc = 0x1dfd5cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 102));
    // 0x1dfd60: 0x3c010026
    ctx->pc = 0x1dfd60u;
    SET_GPR_U32(ctx, 1, ((uint32_t)38 << 16));
    // 0x1dfd64: 0xac229d10
    ctx->pc = 0x1dfd64u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294941968), GPR_U32(ctx, 2));
    // 0x1dfd68: 0x10000009
    ctx->pc = 0x1DFD68u;
    {
        const bool branch_taken_0x1dfd68 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dfd68) {
            ctx->pc = 0x1DFD90u;
            goto label_1dfd90;
        }
    }
    ctx->pc = 0x1DFD70u;
label_1dfd70:
    // 0x1dfd70: 0x8fc20000
    ctx->pc = 0x1dfd70u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dfd74: 0x24430484
    ctx->pc = 0x1dfd74u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 2), 1156));
    // 0x1dfd78: 0x8fc20000
    ctx->pc = 0x1dfd78u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dfd7c: 0x244204d4
    ctx->pc = 0x1dfd7cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1236));
    // 0x1dfd80: 0x60202d
    ctx->pc = 0x1dfd80u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dfd84: 0x40282d
    ctx->pc = 0x1dfd84u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dfd88: 0xc042bf0
    ctx->pc = 0x1DFD88u;
    SET_GPR_U32(ctx, 31, 0x1DFD90u);
    ctx->pc = 0x10AFC0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010AFC0_0x10afc0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DFD90u; }
    }
    if (ctx->pc != 0x1DFD90u) { return; }
    ctx->pc = 0x1DFD90u;
label_1dfd90:
    // 0x1dfd90: 0x3c0e82d
    ctx->pc = 0x1dfd90u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dfd94: 0xdfbe00b0
    ctx->pc = 0x1dfd94u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x1dfd98: 0xdfbf00b8
    ctx->pc = 0x1dfd98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 184)));
    // 0x1dfd9c: 0x27bd00c0
    ctx->pc = 0x1dfd9cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 192));
    // 0x1dfda0: 0x3e00008
    ctx->pc = 0x1DFDA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DFC30u: goto label_1dfc30;
            case 0x1DFC78u: goto label_1dfc78;
            case 0x1DFD70u: goto label_1dfd70;
            case 0x1DFD90u: goto label_1dfd90;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DFDA8u;
}
