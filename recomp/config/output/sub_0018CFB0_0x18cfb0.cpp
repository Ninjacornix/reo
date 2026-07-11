#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0018CFB0
// Address: 0x18cfb0 - 0x18d470
void sub_0018CFB0_0x18cfb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x18cfb0u;

label_18cfb0:
    // 0x18cfb0: 0x27bdffa0
    ctx->pc = 0x18cfb0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967200));
label_18cfb4:
    // 0x18cfb4: 0x24020002
    ctx->pc = 0x18cfb4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
label_18cfb8:
    // 0x18cfb8: 0xffbf0050
    ctx->pc = 0x18cfb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
label_18cfbc:
    // 0x18cfbc: 0x7fb40040
    ctx->pc = 0x18cfbcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
label_18cfc0:
    // 0x18cfc0: 0x7fb30030
    ctx->pc = 0x18cfc0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
label_18cfc4:
    // 0x18cfc4: 0xa0a02d
    ctx->pc = 0x18cfc4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_18cfc8:
    // 0x18cfc8: 0x7fb20020
    ctx->pc = 0x18cfc8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
label_18cfcc:
    // 0x18cfcc: 0xc0982d
    ctx->pc = 0x18cfccu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_18cfd0:
    // 0x18cfd0: 0x7fb10010
    ctx->pc = 0x18cfd0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
label_18cfd4:
    // 0x18cfd4: 0xe0902d
    ctx->pc = 0x18cfd4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
label_18cfd8:
    // 0x18cfd8: 0x14820020
label_18cfdc:
    if (ctx->pc == 0x18CFDCu) {
        ctx->pc = 0x18CFDCu;
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        ctx->pc = 0x18CFE0u;
        goto label_18cfe0;
    }
    ctx->pc = 0x18CFD8u;
    {
        const bool branch_taken_0x18cfd8 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 2));
        ctx->pc = 0x18CFDCu;
        WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
        if (branch_taken_0x18cfd8) {
            ctx->pc = 0x18D05Cu;
            goto label_18d05c;
        }
    }
    ctx->pc = 0x18CFE0u;
label_18cfe0:
    // 0x18cfe0: 0x3c01002a
    ctx->pc = 0x18cfe0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
label_18cfe4:
    // 0x18cfe4: 0x8e420004
    ctx->pc = 0x18cfe4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 4)));
label_18cfe8:
    // 0x18cfe8: 0x8c23fdb4
    ctx->pc = 0x18cfe8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 4294966708)));
label_18cfec:
    // 0x18cfec: 0x2442ffff
    ctx->pc = 0x18cfecu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
label_18cff0:
    // 0x18cff0: 0x38080
    ctx->pc = 0x18cff0u;
    SET_GPR_U32(ctx, 16, SLL32(GPR_U32(ctx, 3), 2));
label_18cff4:
    // 0x18cff4: 0x2122021
    ctx->pc = 0x18cff4u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
label_18cff8:
    // 0x18cff8: 0x8c830014
    ctx->pc = 0x18cff8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 4), 20)));
label_18cffc:
    // 0x18cffc: 0x43082b
    ctx->pc = 0x18cffcu;
    SET_GPR_U32(ctx, 1, SLTU32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_18d000:
    // 0x18d000: 0x1420004c
label_18d004:
    if (ctx->pc == 0x18D004u) {
        ctx->pc = 0x18D004u;
        SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 4), 20));
        ctx->pc = 0x18D008u;
        goto label_18d008;
    }
    ctx->pc = 0x18D000u;
    {
        const bool branch_taken_0x18d000 = (GPR_U32(ctx, 1) != GPR_U32(ctx, 0));
        ctx->pc = 0x18D004u;
        SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 4), 20));
        if (branch_taken_0x18d000) {
            ctx->pc = 0x18D134u;
            goto label_18d134;
        }
    }
    ctx->pc = 0x18D008u;
label_18d008:
    // 0x18d008: 0xc063728
label_18d00c:
    if (ctx->pc == 0x18D00Cu) {
        ctx->pc = 0x18D00Cu;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 12)));
        ctx->pc = 0x18D010u;
        goto label_18d010;
    }
    ctx->pc = 0x18D008u;
    SET_GPR_U32(ctx, 31, 0x18D010u);
    ctx->pc = 0x18D00Cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 12)));
    ctx->pc = 0x18DCA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D010u; }
    }
    if (ctx->pc != 0x18D010u) { return; }
    ctx->pc = 0x18D010u;
label_18d010:
    // 0x18d010: 0x8e230000
    ctx->pc = 0x18d010u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_18d014:
    // 0x18d014: 0x2122821
    ctx->pc = 0x18d014u;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 16), GPR_U32(ctx, 18)));
label_18d018:
    // 0x18d018: 0x24630001
    ctx->pc = 0x18d018u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 1));
label_18d01c:
    // 0x18d01c: 0xae230000
    ctx->pc = 0x18d01cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 3));
label_18d020:
    // 0x18d020: 0x8ca3001c
    ctx->pc = 0x18d020u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 5), 28)));
label_18d024:
    // 0x18d024: 0x24640001
    ctx->pc = 0x18d024u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 3), 1));
label_18d028:
    // 0x18d028: 0x31880
    ctx->pc = 0x18d028u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 2));
label_18d02c:
    // 0x18d02c: 0xaca4001c
    ctx->pc = 0x18d02cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 28), GPR_U32(ctx, 4));
label_18d030:
    // 0x18d030: 0x431021
    ctx->pc = 0x18d030u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_18d034:
    // 0x18d034: 0xac540000
    ctx->pc = 0x18d034u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 20));
label_18d038:
    // 0x18d038: 0x8ca3001c
    ctx->pc = 0x18d038u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 5), 28)));
label_18d03c:
    // 0x18d03c: 0x8e420004
    ctx->pc = 0x18d03cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 4)));
label_18d040:
    // 0x18d040: 0x14620002
label_18d044:
    if (ctx->pc == 0x18D044u) {
        ctx->pc = 0x18D044u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 5), 28));
        ctx->pc = 0x18D048u;
        goto label_18d048;
    }
    ctx->pc = 0x18D040u;
    {
        const bool branch_taken_0x18d040 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x18D044u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 5), 28));
        if (branch_taken_0x18d040) {
            ctx->pc = 0x18D04Cu;
            goto label_18d04c;
        }
    }
    ctx->pc = 0x18D048u;
label_18d048:
    // 0x18d048: 0xacc00000
    ctx->pc = 0x18d048u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 0));
label_18d04c:
    // 0x18d04c: 0xae540034
    ctx->pc = 0x18d04cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 52), GPR_U32(ctx, 20));
label_18d050:
    // 0x18d050: 0x102d
    ctx->pc = 0x18d050u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18d054:
    // 0x18d054: 0x1000003a
label_18d058:
    if (ctx->pc == 0x18D058u) {
        ctx->pc = 0x18D058u;
        WRITE32(ADD32(GPR_U32(ctx, 18), 56), GPR_U32(ctx, 19));
        ctx->pc = 0x18D05Cu;
        goto label_18d05c;
    }
    ctx->pc = 0x18D054u;
    {
        const bool branch_taken_0x18d054 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18D058u;
        WRITE32(ADD32(GPR_U32(ctx, 18), 56), GPR_U32(ctx, 19));
        if (branch_taken_0x18d054) {
            ctx->pc = 0x18D140u;
            goto label_18d140;
        }
    }
    ctx->pc = 0x18D05Cu;
label_18d05c:
    // 0x18d05c: 0x8e450034
    ctx->pc = 0x18d05cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 18), 52)));
label_18d060:
    // 0x18d060: 0x10a0ffdf
label_18d064:
    if (ctx->pc == 0x18D064u) {
        ctx->pc = 0x18D068u;
        goto label_18d068;
    }
    ctx->pc = 0x18D060u;
    {
        const bool branch_taken_0x18d060 = (GPR_U32(ctx, 5) == GPR_U32(ctx, 0));
        if (branch_taken_0x18d060) {
            ctx->pc = 0x18CFE0u;
            goto label_18cfe0;
        }
    }
    ctx->pc = 0x18D068u;
label_18d068:
    // 0x18d068: 0x8e420038
    ctx->pc = 0x18d068u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 56)));
label_18d06c:
    // 0x18d06c: 0x1040ffdc
label_18d070:
    if (ctx->pc == 0x18D070u) {
        ctx->pc = 0x18D074u;
        goto label_18d074;
    }
    ctx->pc = 0x18D06Cu;
    {
        const bool branch_taken_0x18d06c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x18d06c) {
            ctx->pc = 0x18CFE0u;
            goto label_18cfe0;
        }
    }
    ctx->pc = 0x18D074u;
label_18d074:
    // 0x18d074: 0x3c03f000
    ctx->pc = 0x18d074u;
    SET_GPR_U32(ctx, 3, ((uint32_t)61440 << 16));
label_18d078:
    // 0x18d078: 0xa31824
    ctx->pc = 0x18d078u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
label_18d07c:
    // 0x18d07c: 0x31f02
    ctx->pc = 0x18d07cu;
    SET_GPR_U32(ctx, 3, SRL32(GPR_U32(ctx, 3), 28));
label_18d080:
    // 0x18d080: 0x2c610006
    ctx->pc = 0x18d080u;
    SET_GPR_U32(ctx, 1, SLTU32(GPR_U32(ctx, 3), 6));
label_18d084:
    // 0x18d084: 0x1020ffd6
label_18d088:
    if (ctx->pc == 0x18D088u) {
        ctx->pc = 0x18D08Cu;
        goto label_18d08c;
    }
    ctx->pc = 0x18D084u;
    {
        const bool branch_taken_0x18d084 = (GPR_U32(ctx, 1) == GPR_U32(ctx, 0));
        if (branch_taken_0x18d084) {
            ctx->pc = 0x18CFE0u;
            goto label_18cfe0;
        }
    }
    ctx->pc = 0x18D08Cu;
label_18d08c:
    // 0x18d08c: 0x3c050024
    ctx->pc = 0x18d08cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
label_18d090:
    // 0x18d090: 0x31880
    ctx->pc = 0x18d090u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 2));
label_18d094:
    // 0x18d094: 0x24a51bf0
    ctx->pc = 0x18d094u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 7152));
label_18d098:
    // 0x18d098: 0x651821
    ctx->pc = 0x18d098u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
label_18d09c:
    // 0x18d09c: 0x8c630000
    ctx->pc = 0x18d09cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_18d0a0:
    // 0x18d0a0: 0x600008
label_18d0a4:
    if (ctx->pc == 0x18D0A4u) {
        ctx->pc = 0x18D0A8u;
        goto label_18d0a8;
    }
    ctx->pc = 0x18D0A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18CFB0u: goto label_18cfb0;
            case 0x18CFB4u: goto label_18cfb4;
            case 0x18CFB8u: goto label_18cfb8;
            case 0x18CFBCu: goto label_18cfbc;
            case 0x18CFC0u: goto label_18cfc0;
            case 0x18CFC4u: goto label_18cfc4;
            case 0x18CFC8u: goto label_18cfc8;
            case 0x18CFCCu: goto label_18cfcc;
            case 0x18CFD0u: goto label_18cfd0;
            case 0x18CFD4u: goto label_18cfd4;
            case 0x18CFD8u: goto label_18cfd8;
            case 0x18CFDCu: goto label_18cfdc;
            case 0x18CFE0u: goto label_18cfe0;
            case 0x18CFE4u: goto label_18cfe4;
            case 0x18CFE8u: goto label_18cfe8;
            case 0x18CFECu: goto label_18cfec;
            case 0x18CFF0u: goto label_18cff0;
            case 0x18CFF4u: goto label_18cff4;
            case 0x18CFF8u: goto label_18cff8;
            case 0x18CFFCu: goto label_18cffc;
            case 0x18D000u: goto label_18d000;
            case 0x18D004u: goto label_18d004;
            case 0x18D008u: goto label_18d008;
            case 0x18D00Cu: goto label_18d00c;
            case 0x18D010u: goto label_18d010;
            case 0x18D014u: goto label_18d014;
            case 0x18D018u: goto label_18d018;
            case 0x18D01Cu: goto label_18d01c;
            case 0x18D020u: goto label_18d020;
            case 0x18D024u: goto label_18d024;
            case 0x18D028u: goto label_18d028;
            case 0x18D02Cu: goto label_18d02c;
            case 0x18D030u: goto label_18d030;
            case 0x18D034u: goto label_18d034;
            case 0x18D038u: goto label_18d038;
            case 0x18D03Cu: goto label_18d03c;
            case 0x18D040u: goto label_18d040;
            case 0x18D044u: goto label_18d044;
            case 0x18D048u: goto label_18d048;
            case 0x18D04Cu: goto label_18d04c;
            case 0x18D050u: goto label_18d050;
            case 0x18D054u: goto label_18d054;
            case 0x18D058u: goto label_18d058;
            case 0x18D05Cu: goto label_18d05c;
            case 0x18D060u: goto label_18d060;
            case 0x18D064u: goto label_18d064;
            case 0x18D068u: goto label_18d068;
            case 0x18D06Cu: goto label_18d06c;
            case 0x18D070u: goto label_18d070;
            case 0x18D074u: goto label_18d074;
            case 0x18D078u: goto label_18d078;
            case 0x18D07Cu: goto label_18d07c;
            case 0x18D080u: goto label_18d080;
            case 0x18D084u: goto label_18d084;
            case 0x18D088u: goto label_18d088;
            case 0x18D08Cu: goto label_18d08c;
            case 0x18D090u: goto label_18d090;
            case 0x18D094u: goto label_18d094;
            case 0x18D098u: goto label_18d098;
            case 0x18D09Cu: goto label_18d09c;
            case 0x18D0A0u: goto label_18d0a0;
            case 0x18D0A4u: goto label_18d0a4;
            case 0x18D0A8u: goto label_18d0a8;
            case 0x18D0ACu: goto label_18d0ac;
            case 0x18D0B0u: goto label_18d0b0;
            case 0x18D0B4u: goto label_18d0b4;
            case 0x18D0B8u: goto label_18d0b8;
            case 0x18D0BCu: goto label_18d0bc;
            case 0x18D0C0u: goto label_18d0c0;
            case 0x18D0C4u: goto label_18d0c4;
            case 0x18D0C8u: goto label_18d0c8;
            case 0x18D0CCu: goto label_18d0cc;
            case 0x18D0D0u: goto label_18d0d0;
            case 0x18D0D4u: goto label_18d0d4;
            case 0x18D0D8u: goto label_18d0d8;
            case 0x18D0DCu: goto label_18d0dc;
            case 0x18D0E0u: goto label_18d0e0;
            case 0x18D0E4u: goto label_18d0e4;
            case 0x18D0E8u: goto label_18d0e8;
            case 0x18D0ECu: goto label_18d0ec;
            case 0x18D0F0u: goto label_18d0f0;
            case 0x18D0F4u: goto label_18d0f4;
            case 0x18D0F8u: goto label_18d0f8;
            case 0x18D0FCu: goto label_18d0fc;
            case 0x18D100u: goto label_18d100;
            case 0x18D104u: goto label_18d104;
            case 0x18D108u: goto label_18d108;
            case 0x18D10Cu: goto label_18d10c;
            case 0x18D110u: goto label_18d110;
            case 0x18D114u: goto label_18d114;
            case 0x18D118u: goto label_18d118;
            case 0x18D11Cu: goto label_18d11c;
            case 0x18D120u: goto label_18d120;
            case 0x18D124u: goto label_18d124;
            case 0x18D128u: goto label_18d128;
            case 0x18D12Cu: goto label_18d12c;
            case 0x18D130u: goto label_18d130;
            case 0x18D134u: goto label_18d134;
            case 0x18D138u: goto label_18d138;
            case 0x18D13Cu: goto label_18d13c;
            case 0x18D140u: goto label_18d140;
            case 0x18D144u: goto label_18d144;
            case 0x18D148u: goto label_18d148;
            case 0x18D14Cu: goto label_18d14c;
            case 0x18D150u: goto label_18d150;
            case 0x18D154u: goto label_18d154;
            case 0x18D158u: goto label_18d158;
            case 0x18D15Cu: goto label_18d15c;
            case 0x18D160u: goto label_18d160;
            case 0x18D164u: goto label_18d164;
            case 0x18D168u: goto label_18d168;
            case 0x18D16Cu: goto label_18d16c;
            case 0x18D170u: goto label_18d170;
            case 0x18D174u: goto label_18d174;
            case 0x18D178u: goto label_18d178;
            case 0x18D17Cu: goto label_18d17c;
            case 0x18D180u: goto label_18d180;
            case 0x18D184u: goto label_18d184;
            case 0x18D188u: goto label_18d188;
            case 0x18D18Cu: goto label_18d18c;
            case 0x18D190u: goto label_18d190;
            case 0x18D194u: goto label_18d194;
            case 0x18D198u: goto label_18d198;
            case 0x18D19Cu: goto label_18d19c;
            case 0x18D1A0u: goto label_18d1a0;
            case 0x18D1A4u: goto label_18d1a4;
            case 0x18D1A8u: goto label_18d1a8;
            case 0x18D1ACu: goto label_18d1ac;
            case 0x18D1B0u: goto label_18d1b0;
            case 0x18D1B4u: goto label_18d1b4;
            case 0x18D1B8u: goto label_18d1b8;
            case 0x18D1BCu: goto label_18d1bc;
            case 0x18D1C0u: goto label_18d1c0;
            case 0x18D1C4u: goto label_18d1c4;
            case 0x18D1C8u: goto label_18d1c8;
            case 0x18D1CCu: goto label_18d1cc;
            case 0x18D1D0u: goto label_18d1d0;
            case 0x18D1D4u: goto label_18d1d4;
            case 0x18D1D8u: goto label_18d1d8;
            case 0x18D1DCu: goto label_18d1dc;
            case 0x18D1E0u: goto label_18d1e0;
            case 0x18D1E4u: goto label_18d1e4;
            case 0x18D1E8u: goto label_18d1e8;
            case 0x18D1ECu: goto label_18d1ec;
            case 0x18D1F0u: goto label_18d1f0;
            case 0x18D1F4u: goto label_18d1f4;
            case 0x18D1F8u: goto label_18d1f8;
            case 0x18D1FCu: goto label_18d1fc;
            case 0x18D200u: goto label_18d200;
            case 0x18D204u: goto label_18d204;
            case 0x18D208u: goto label_18d208;
            case 0x18D20Cu: goto label_18d20c;
            case 0x18D210u: goto label_18d210;
            case 0x18D214u: goto label_18d214;
            case 0x18D218u: goto label_18d218;
            case 0x18D21Cu: goto label_18d21c;
            case 0x18D220u: goto label_18d220;
            case 0x18D224u: goto label_18d224;
            case 0x18D228u: goto label_18d228;
            case 0x18D22Cu: goto label_18d22c;
            case 0x18D230u: goto label_18d230;
            case 0x18D234u: goto label_18d234;
            case 0x18D238u: goto label_18d238;
            case 0x18D23Cu: goto label_18d23c;
            case 0x18D240u: goto label_18d240;
            case 0x18D244u: goto label_18d244;
            case 0x18D248u: goto label_18d248;
            case 0x18D24Cu: goto label_18d24c;
            case 0x18D250u: goto label_18d250;
            case 0x18D254u: goto label_18d254;
            case 0x18D258u: goto label_18d258;
            case 0x18D25Cu: goto label_18d25c;
            case 0x18D260u: goto label_18d260;
            case 0x18D264u: goto label_18d264;
            case 0x18D268u: goto label_18d268;
            case 0x18D26Cu: goto label_18d26c;
            case 0x18D270u: goto label_18d270;
            case 0x18D274u: goto label_18d274;
            case 0x18D278u: goto label_18d278;
            case 0x18D27Cu: goto label_18d27c;
            case 0x18D280u: goto label_18d280;
            case 0x18D284u: goto label_18d284;
            case 0x18D288u: goto label_18d288;
            case 0x18D28Cu: goto label_18d28c;
            case 0x18D290u: goto label_18d290;
            case 0x18D294u: goto label_18d294;
            case 0x18D298u: goto label_18d298;
            case 0x18D29Cu: goto label_18d29c;
            case 0x18D2A0u: goto label_18d2a0;
            case 0x18D2A4u: goto label_18d2a4;
            case 0x18D2A8u: goto label_18d2a8;
            case 0x18D2ACu: goto label_18d2ac;
            case 0x18D2B0u: goto label_18d2b0;
            case 0x18D2B4u: goto label_18d2b4;
            case 0x18D2B8u: goto label_18d2b8;
            case 0x18D2BCu: goto label_18d2bc;
            case 0x18D2C0u: goto label_18d2c0;
            case 0x18D2C4u: goto label_18d2c4;
            case 0x18D2C8u: goto label_18d2c8;
            case 0x18D2CCu: goto label_18d2cc;
            case 0x18D2D0u: goto label_18d2d0;
            case 0x18D2D4u: goto label_18d2d4;
            case 0x18D2D8u: goto label_18d2d8;
            case 0x18D2DCu: goto label_18d2dc;
            case 0x18D2E0u: goto label_18d2e0;
            case 0x18D2E4u: goto label_18d2e4;
            case 0x18D2E8u: goto label_18d2e8;
            case 0x18D2ECu: goto label_18d2ec;
            case 0x18D2F0u: goto label_18d2f0;
            case 0x18D2F4u: goto label_18d2f4;
            case 0x18D2F8u: goto label_18d2f8;
            case 0x18D2FCu: goto label_18d2fc;
            case 0x18D300u: goto label_18d300;
            case 0x18D304u: goto label_18d304;
            case 0x18D308u: goto label_18d308;
            case 0x18D30Cu: goto label_18d30c;
            case 0x18D310u: goto label_18d310;
            case 0x18D314u: goto label_18d314;
            case 0x18D318u: goto label_18d318;
            case 0x18D31Cu: goto label_18d31c;
            case 0x18D320u: goto label_18d320;
            case 0x18D324u: goto label_18d324;
            case 0x18D328u: goto label_18d328;
            case 0x18D32Cu: goto label_18d32c;
            case 0x18D330u: goto label_18d330;
            case 0x18D334u: goto label_18d334;
            case 0x18D338u: goto label_18d338;
            case 0x18D33Cu: goto label_18d33c;
            case 0x18D340u: goto label_18d340;
            case 0x18D344u: goto label_18d344;
            case 0x18D348u: goto label_18d348;
            case 0x18D34Cu: goto label_18d34c;
            case 0x18D350u: goto label_18d350;
            case 0x18D354u: goto label_18d354;
            case 0x18D358u: goto label_18d358;
            case 0x18D35Cu: goto label_18d35c;
            case 0x18D360u: goto label_18d360;
            case 0x18D364u: goto label_18d364;
            case 0x18D368u: goto label_18d368;
            case 0x18D36Cu: goto label_18d36c;
            case 0x18D370u: goto label_18d370;
            case 0x18D374u: goto label_18d374;
            case 0x18D378u: goto label_18d378;
            case 0x18D37Cu: goto label_18d37c;
            case 0x18D380u: goto label_18d380;
            case 0x18D384u: goto label_18d384;
            case 0x18D388u: goto label_18d388;
            case 0x18D38Cu: goto label_18d38c;
            case 0x18D390u: goto label_18d390;
            case 0x18D394u: goto label_18d394;
            case 0x18D398u: goto label_18d398;
            case 0x18D39Cu: goto label_18d39c;
            case 0x18D3A0u: goto label_18d3a0;
            case 0x18D3A4u: goto label_18d3a4;
            case 0x18D3A8u: goto label_18d3a8;
            case 0x18D3ACu: goto label_18d3ac;
            case 0x18D3B0u: goto label_18d3b0;
            case 0x18D3B4u: goto label_18d3b4;
            case 0x18D3B8u: goto label_18d3b8;
            case 0x18D3BCu: goto label_18d3bc;
            case 0x18D3C0u: goto label_18d3c0;
            case 0x18D3C4u: goto label_18d3c4;
            case 0x18D3C8u: goto label_18d3c8;
            case 0x18D3CCu: goto label_18d3cc;
            case 0x18D3D0u: goto label_18d3d0;
            case 0x18D3D4u: goto label_18d3d4;
            case 0x18D3D8u: goto label_18d3d8;
            case 0x18D3DCu: goto label_18d3dc;
            case 0x18D3E0u: goto label_18d3e0;
            case 0x18D3E4u: goto label_18d3e4;
            case 0x18D3E8u: goto label_18d3e8;
            case 0x18D3ECu: goto label_18d3ec;
            case 0x18D3F0u: goto label_18d3f0;
            case 0x18D3F4u: goto label_18d3f4;
            case 0x18D3F8u: goto label_18d3f8;
            case 0x18D3FCu: goto label_18d3fc;
            case 0x18D400u: goto label_18d400;
            case 0x18D404u: goto label_18d404;
            case 0x18D408u: goto label_18d408;
            case 0x18D40Cu: goto label_18d40c;
            case 0x18D410u: goto label_18d410;
            case 0x18D414u: goto label_18d414;
            case 0x18D418u: goto label_18d418;
            case 0x18D41Cu: goto label_18d41c;
            case 0x18D420u: goto label_18d420;
            case 0x18D424u: goto label_18d424;
            case 0x18D428u: goto label_18d428;
            case 0x18D42Cu: goto label_18d42c;
            case 0x18D430u: goto label_18d430;
            case 0x18D434u: goto label_18d434;
            case 0x18D438u: goto label_18d438;
            case 0x18D43Cu: goto label_18d43c;
            case 0x18D440u: goto label_18d440;
            case 0x18D444u: goto label_18d444;
            case 0x18D448u: goto label_18d448;
            case 0x18D44Cu: goto label_18d44c;
            case 0x18D450u: goto label_18d450;
            case 0x18D454u: goto label_18d454;
            case 0x18D458u: goto label_18d458;
            case 0x18D45Cu: goto label_18d45c;
            case 0x18D460u: goto label_18d460;
            case 0x18D464u: goto label_18d464;
            case 0x18D468u: goto label_18d468;
            case 0x18D46Cu: goto label_18d46c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18D0A8u;
label_18d0a8:
    // 0x18d0a8: 0x8c460000
    ctx->pc = 0x18d0a8u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_18d0ac:
    // 0x18d0ac: 0x3c057000
    ctx->pc = 0x18d0acu;
    SET_GPR_U32(ctx, 5, ((uint32_t)28672 << 16));
label_18d0b0:
    // 0x18d0b0: 0xc51824
    ctx->pc = 0x18d0b0u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 6), GPR_U32(ctx, 5)));
label_18d0b4:
    // 0x18d0b4: 0x10650003
label_18d0b8:
    if (ctx->pc == 0x18D0B8u) {
        ctx->pc = 0x18D0B8u;
        SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 6), 65535));
        ctx->pc = 0x18D0BCu;
        goto label_18d0bc;
    }
    ctx->pc = 0x18D0B4u;
    {
        const bool branch_taken_0x18d0b4 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 5));
        ctx->pc = 0x18D0B8u;
        SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 6), 65535));
        if (branch_taken_0x18d0b4) {
            ctx->pc = 0x18D0C4u;
            goto label_18d0c4;
        }
    }
    ctx->pc = 0x18D0BCu;
label_18d0bc:
    // 0x18d0bc: 0x1000ffc8
label_18d0c0:
    if (ctx->pc == 0x18D0C0u) {
        ctx->pc = 0x18D0C4u;
        goto label_18d0c4;
    }
    ctx->pc = 0x18D0BCu;
    {
        const bool branch_taken_0x18d0bc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x18d0bc) {
            ctx->pc = 0x18CFE0u;
            goto label_18cfe0;
        }
    }
    ctx->pc = 0x18D0C4u;
label_18d0c4:
    // 0x18d0c4: 0x3c032000
    ctx->pc = 0x18d0c4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
label_18d0c8:
    // 0x18d0c8: 0xa32821
    ctx->pc = 0x18d0c8u;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
label_18d0cc:
    // 0x18d0cc: 0x14193c
    ctx->pc = 0x18d0ccu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 20) << (32 + 4));
label_18d0d0:
    // 0x18d0d0: 0xac450000
    ctx->pc = 0x18d0d0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 5));
label_18d0d4:
    // 0x18d0d4: 0x3193e
    ctx->pc = 0x18d0d4u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) >> (32 + 4));
label_18d0d8:
    // 0x18d0d8: 0x1000000c
label_18d0dc:
    if (ctx->pc == 0x18D0DCu) {
        ctx->pc = 0x18D0DCu;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 3));
        ctx->pc = 0x18D0E0u;
        goto label_18d0e0;
    }
    ctx->pc = 0x18D0D8u;
    {
        const bool branch_taken_0x18d0d8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18D0DCu;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 3));
        if (branch_taken_0x18d0d8) {
            ctx->pc = 0x18D10Cu;
            goto label_18d10c;
        }
    }
    ctx->pc = 0x18D0E0u;
label_18d0e0:
    // 0x18d0e0: 0x8c450000
    ctx->pc = 0x18d0e0u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_18d0e4:
    // 0x18d0e4: 0x3c037000
    ctx->pc = 0x18d0e4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
label_18d0e8:
    // 0x18d0e8: 0xa31824
    ctx->pc = 0x18d0e8u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
label_18d0ec:
    // 0x18d0ec: 0x10600003
label_18d0f0:
    if (ctx->pc == 0x18D0F0u) {
        ctx->pc = 0x18D0F4u;
        goto label_18d0f4;
    }
    ctx->pc = 0x18D0ECu;
    {
        const bool branch_taken_0x18d0ec = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        if (branch_taken_0x18d0ec) {
            ctx->pc = 0x18D0FCu;
            goto label_18d0fc;
        }
    }
    ctx->pc = 0x18D0F4u;
label_18d0f4:
    // 0x18d0f4: 0x1000ffba
label_18d0f8:
    if (ctx->pc == 0x18D0F8u) {
        ctx->pc = 0x18D0FCu;
        goto label_18d0fc;
    }
    ctx->pc = 0x18D0F4u;
    {
        const bool branch_taken_0x18d0f4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x18d0f4) {
            ctx->pc = 0x18CFE0u;
            goto label_18cfe0;
        }
    }
    ctx->pc = 0x18D0FCu;
label_18d0fc:
    // 0x18d0fc: 0x30a5ffff
    ctx->pc = 0x18d0fcu;
    SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 5), 65535));
label_18d100:
    // 0x18d100: 0x3c033000
    ctx->pc = 0x18d100u;
    SET_GPR_U32(ctx, 3, ((uint32_t)12288 << 16));
label_18d104:
    // 0x18d104: 0xa31821
    ctx->pc = 0x18d104u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
label_18d108:
    // 0x18d108: 0xac430000
    ctx->pc = 0x18d108u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
label_18d10c:
    // 0x18d10c: 0x24020001
    ctx->pc = 0x18d10cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_18d110:
    // 0x18d110: 0x14820004
label_18d114:
    if (ctx->pc == 0x18D114u) {
        ctx->pc = 0x18D118u;
        goto label_18d118;
    }
    ctx->pc = 0x18D110u;
    {
        const bool branch_taken_0x18d110 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 2));
        if (branch_taken_0x18d110) {
            ctx->pc = 0x18D124u;
            goto label_18d124;
        }
    }
    ctx->pc = 0x18D118u;
label_18d118:
    // 0x18d118: 0xae400034
    ctx->pc = 0x18d118u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 52), GPR_U32(ctx, 0));
label_18d11c:
    // 0x18d11c: 0x10000003
label_18d120:
    if (ctx->pc == 0x18D120u) {
        ctx->pc = 0x18D120u;
        WRITE32(ADD32(GPR_U32(ctx, 18), 56), GPR_U32(ctx, 0));
        ctx->pc = 0x18D124u;
        goto label_18d124;
    }
    ctx->pc = 0x18D11Cu;
    {
        const bool branch_taken_0x18d11c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18D120u;
        WRITE32(ADD32(GPR_U32(ctx, 18), 56), GPR_U32(ctx, 0));
        if (branch_taken_0x18d11c) {
            ctx->pc = 0x18D12Cu;
            goto label_18d12c;
        }
    }
    ctx->pc = 0x18D124u;
label_18d124:
    // 0x18d124: 0xae540034
    ctx->pc = 0x18d124u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 52), GPR_U32(ctx, 20));
label_18d128:
    // 0x18d128: 0xae530038
    ctx->pc = 0x18d128u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 56), GPR_U32(ctx, 19));
label_18d12c:
    // 0x18d12c: 0x10000004
label_18d130:
    if (ctx->pc == 0x18D130u) {
        ctx->pc = 0x18D130u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18D134u;
        goto label_18d134;
    }
    ctx->pc = 0x18D12Cu;
    {
        const bool branch_taken_0x18d12c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18D130u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x18d12c) {
            ctx->pc = 0x18D140u;
            goto label_18d140;
        }
    }
    ctx->pc = 0x18D134u;
label_18d134:
    // 0x18d134: 0xae400034
    ctx->pc = 0x18d134u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 52), GPR_U32(ctx, 0));
label_18d138:
    // 0x18d138: 0x2402ffff
    ctx->pc = 0x18d138u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
label_18d13c:
    // 0x18d13c: 0xae400038
    ctx->pc = 0x18d13cu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 56), GPR_U32(ctx, 0));
label_18d140:
    // 0x18d140: 0xdfbf0050
    ctx->pc = 0x18d140u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
label_18d144:
    // 0x18d144: 0x7bb40040
    ctx->pc = 0x18d144u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
label_18d148:
    // 0x18d148: 0x7bb30030
    ctx->pc = 0x18d148u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
label_18d14c:
    // 0x18d14c: 0x7bb20020
    ctx->pc = 0x18d14cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
label_18d150:
    // 0x18d150: 0x7bb10010
    ctx->pc = 0x18d150u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
label_18d154:
    // 0x18d154: 0x7bb00000
    ctx->pc = 0x18d154u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
label_18d158:
    // 0x18d158: 0x3e00008
label_18d15c:
    if (ctx->pc == 0x18D15Cu) {
        ctx->pc = 0x18D15Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = 0x18D160u;
        goto label_18d160;
    }
    ctx->pc = 0x18D158u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18D15Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 96));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18CFB0u: goto label_18cfb0;
            case 0x18CFB4u: goto label_18cfb4;
            case 0x18CFB8u: goto label_18cfb8;
            case 0x18CFBCu: goto label_18cfbc;
            case 0x18CFC0u: goto label_18cfc0;
            case 0x18CFC4u: goto label_18cfc4;
            case 0x18CFC8u: goto label_18cfc8;
            case 0x18CFCCu: goto label_18cfcc;
            case 0x18CFD0u: goto label_18cfd0;
            case 0x18CFD4u: goto label_18cfd4;
            case 0x18CFD8u: goto label_18cfd8;
            case 0x18CFDCu: goto label_18cfdc;
            case 0x18CFE0u: goto label_18cfe0;
            case 0x18CFE4u: goto label_18cfe4;
            case 0x18CFE8u: goto label_18cfe8;
            case 0x18CFECu: goto label_18cfec;
            case 0x18CFF0u: goto label_18cff0;
            case 0x18CFF4u: goto label_18cff4;
            case 0x18CFF8u: goto label_18cff8;
            case 0x18CFFCu: goto label_18cffc;
            case 0x18D000u: goto label_18d000;
            case 0x18D004u: goto label_18d004;
            case 0x18D008u: goto label_18d008;
            case 0x18D00Cu: goto label_18d00c;
            case 0x18D010u: goto label_18d010;
            case 0x18D014u: goto label_18d014;
            case 0x18D018u: goto label_18d018;
            case 0x18D01Cu: goto label_18d01c;
            case 0x18D020u: goto label_18d020;
            case 0x18D024u: goto label_18d024;
            case 0x18D028u: goto label_18d028;
            case 0x18D02Cu: goto label_18d02c;
            case 0x18D030u: goto label_18d030;
            case 0x18D034u: goto label_18d034;
            case 0x18D038u: goto label_18d038;
            case 0x18D03Cu: goto label_18d03c;
            case 0x18D040u: goto label_18d040;
            case 0x18D044u: goto label_18d044;
            case 0x18D048u: goto label_18d048;
            case 0x18D04Cu: goto label_18d04c;
            case 0x18D050u: goto label_18d050;
            case 0x18D054u: goto label_18d054;
            case 0x18D058u: goto label_18d058;
            case 0x18D05Cu: goto label_18d05c;
            case 0x18D060u: goto label_18d060;
            case 0x18D064u: goto label_18d064;
            case 0x18D068u: goto label_18d068;
            case 0x18D06Cu: goto label_18d06c;
            case 0x18D070u: goto label_18d070;
            case 0x18D074u: goto label_18d074;
            case 0x18D078u: goto label_18d078;
            case 0x18D07Cu: goto label_18d07c;
            case 0x18D080u: goto label_18d080;
            case 0x18D084u: goto label_18d084;
            case 0x18D088u: goto label_18d088;
            case 0x18D08Cu: goto label_18d08c;
            case 0x18D090u: goto label_18d090;
            case 0x18D094u: goto label_18d094;
            case 0x18D098u: goto label_18d098;
            case 0x18D09Cu: goto label_18d09c;
            case 0x18D0A0u: goto label_18d0a0;
            case 0x18D0A4u: goto label_18d0a4;
            case 0x18D0A8u: goto label_18d0a8;
            case 0x18D0ACu: goto label_18d0ac;
            case 0x18D0B0u: goto label_18d0b0;
            case 0x18D0B4u: goto label_18d0b4;
            case 0x18D0B8u: goto label_18d0b8;
            case 0x18D0BCu: goto label_18d0bc;
            case 0x18D0C0u: goto label_18d0c0;
            case 0x18D0C4u: goto label_18d0c4;
            case 0x18D0C8u: goto label_18d0c8;
            case 0x18D0CCu: goto label_18d0cc;
            case 0x18D0D0u: goto label_18d0d0;
            case 0x18D0D4u: goto label_18d0d4;
            case 0x18D0D8u: goto label_18d0d8;
            case 0x18D0DCu: goto label_18d0dc;
            case 0x18D0E0u: goto label_18d0e0;
            case 0x18D0E4u: goto label_18d0e4;
            case 0x18D0E8u: goto label_18d0e8;
            case 0x18D0ECu: goto label_18d0ec;
            case 0x18D0F0u: goto label_18d0f0;
            case 0x18D0F4u: goto label_18d0f4;
            case 0x18D0F8u: goto label_18d0f8;
            case 0x18D0FCu: goto label_18d0fc;
            case 0x18D100u: goto label_18d100;
            case 0x18D104u: goto label_18d104;
            case 0x18D108u: goto label_18d108;
            case 0x18D10Cu: goto label_18d10c;
            case 0x18D110u: goto label_18d110;
            case 0x18D114u: goto label_18d114;
            case 0x18D118u: goto label_18d118;
            case 0x18D11Cu: goto label_18d11c;
            case 0x18D120u: goto label_18d120;
            case 0x18D124u: goto label_18d124;
            case 0x18D128u: goto label_18d128;
            case 0x18D12Cu: goto label_18d12c;
            case 0x18D130u: goto label_18d130;
            case 0x18D134u: goto label_18d134;
            case 0x18D138u: goto label_18d138;
            case 0x18D13Cu: goto label_18d13c;
            case 0x18D140u: goto label_18d140;
            case 0x18D144u: goto label_18d144;
            case 0x18D148u: goto label_18d148;
            case 0x18D14Cu: goto label_18d14c;
            case 0x18D150u: goto label_18d150;
            case 0x18D154u: goto label_18d154;
            case 0x18D158u: goto label_18d158;
            case 0x18D15Cu: goto label_18d15c;
            case 0x18D160u: goto label_18d160;
            case 0x18D164u: goto label_18d164;
            case 0x18D168u: goto label_18d168;
            case 0x18D16Cu: goto label_18d16c;
            case 0x18D170u: goto label_18d170;
            case 0x18D174u: goto label_18d174;
            case 0x18D178u: goto label_18d178;
            case 0x18D17Cu: goto label_18d17c;
            case 0x18D180u: goto label_18d180;
            case 0x18D184u: goto label_18d184;
            case 0x18D188u: goto label_18d188;
            case 0x18D18Cu: goto label_18d18c;
            case 0x18D190u: goto label_18d190;
            case 0x18D194u: goto label_18d194;
            case 0x18D198u: goto label_18d198;
            case 0x18D19Cu: goto label_18d19c;
            case 0x18D1A0u: goto label_18d1a0;
            case 0x18D1A4u: goto label_18d1a4;
            case 0x18D1A8u: goto label_18d1a8;
            case 0x18D1ACu: goto label_18d1ac;
            case 0x18D1B0u: goto label_18d1b0;
            case 0x18D1B4u: goto label_18d1b4;
            case 0x18D1B8u: goto label_18d1b8;
            case 0x18D1BCu: goto label_18d1bc;
            case 0x18D1C0u: goto label_18d1c0;
            case 0x18D1C4u: goto label_18d1c4;
            case 0x18D1C8u: goto label_18d1c8;
            case 0x18D1CCu: goto label_18d1cc;
            case 0x18D1D0u: goto label_18d1d0;
            case 0x18D1D4u: goto label_18d1d4;
            case 0x18D1D8u: goto label_18d1d8;
            case 0x18D1DCu: goto label_18d1dc;
            case 0x18D1E0u: goto label_18d1e0;
            case 0x18D1E4u: goto label_18d1e4;
            case 0x18D1E8u: goto label_18d1e8;
            case 0x18D1ECu: goto label_18d1ec;
            case 0x18D1F0u: goto label_18d1f0;
            case 0x18D1F4u: goto label_18d1f4;
            case 0x18D1F8u: goto label_18d1f8;
            case 0x18D1FCu: goto label_18d1fc;
            case 0x18D200u: goto label_18d200;
            case 0x18D204u: goto label_18d204;
            case 0x18D208u: goto label_18d208;
            case 0x18D20Cu: goto label_18d20c;
            case 0x18D210u: goto label_18d210;
            case 0x18D214u: goto label_18d214;
            case 0x18D218u: goto label_18d218;
            case 0x18D21Cu: goto label_18d21c;
            case 0x18D220u: goto label_18d220;
            case 0x18D224u: goto label_18d224;
            case 0x18D228u: goto label_18d228;
            case 0x18D22Cu: goto label_18d22c;
            case 0x18D230u: goto label_18d230;
            case 0x18D234u: goto label_18d234;
            case 0x18D238u: goto label_18d238;
            case 0x18D23Cu: goto label_18d23c;
            case 0x18D240u: goto label_18d240;
            case 0x18D244u: goto label_18d244;
            case 0x18D248u: goto label_18d248;
            case 0x18D24Cu: goto label_18d24c;
            case 0x18D250u: goto label_18d250;
            case 0x18D254u: goto label_18d254;
            case 0x18D258u: goto label_18d258;
            case 0x18D25Cu: goto label_18d25c;
            case 0x18D260u: goto label_18d260;
            case 0x18D264u: goto label_18d264;
            case 0x18D268u: goto label_18d268;
            case 0x18D26Cu: goto label_18d26c;
            case 0x18D270u: goto label_18d270;
            case 0x18D274u: goto label_18d274;
            case 0x18D278u: goto label_18d278;
            case 0x18D27Cu: goto label_18d27c;
            case 0x18D280u: goto label_18d280;
            case 0x18D284u: goto label_18d284;
            case 0x18D288u: goto label_18d288;
            case 0x18D28Cu: goto label_18d28c;
            case 0x18D290u: goto label_18d290;
            case 0x18D294u: goto label_18d294;
            case 0x18D298u: goto label_18d298;
            case 0x18D29Cu: goto label_18d29c;
            case 0x18D2A0u: goto label_18d2a0;
            case 0x18D2A4u: goto label_18d2a4;
            case 0x18D2A8u: goto label_18d2a8;
            case 0x18D2ACu: goto label_18d2ac;
            case 0x18D2B0u: goto label_18d2b0;
            case 0x18D2B4u: goto label_18d2b4;
            case 0x18D2B8u: goto label_18d2b8;
            case 0x18D2BCu: goto label_18d2bc;
            case 0x18D2C0u: goto label_18d2c0;
            case 0x18D2C4u: goto label_18d2c4;
            case 0x18D2C8u: goto label_18d2c8;
            case 0x18D2CCu: goto label_18d2cc;
            case 0x18D2D0u: goto label_18d2d0;
            case 0x18D2D4u: goto label_18d2d4;
            case 0x18D2D8u: goto label_18d2d8;
            case 0x18D2DCu: goto label_18d2dc;
            case 0x18D2E0u: goto label_18d2e0;
            case 0x18D2E4u: goto label_18d2e4;
            case 0x18D2E8u: goto label_18d2e8;
            case 0x18D2ECu: goto label_18d2ec;
            case 0x18D2F0u: goto label_18d2f0;
            case 0x18D2F4u: goto label_18d2f4;
            case 0x18D2F8u: goto label_18d2f8;
            case 0x18D2FCu: goto label_18d2fc;
            case 0x18D300u: goto label_18d300;
            case 0x18D304u: goto label_18d304;
            case 0x18D308u: goto label_18d308;
            case 0x18D30Cu: goto label_18d30c;
            case 0x18D310u: goto label_18d310;
            case 0x18D314u: goto label_18d314;
            case 0x18D318u: goto label_18d318;
            case 0x18D31Cu: goto label_18d31c;
            case 0x18D320u: goto label_18d320;
            case 0x18D324u: goto label_18d324;
            case 0x18D328u: goto label_18d328;
            case 0x18D32Cu: goto label_18d32c;
            case 0x18D330u: goto label_18d330;
            case 0x18D334u: goto label_18d334;
            case 0x18D338u: goto label_18d338;
            case 0x18D33Cu: goto label_18d33c;
            case 0x18D340u: goto label_18d340;
            case 0x18D344u: goto label_18d344;
            case 0x18D348u: goto label_18d348;
            case 0x18D34Cu: goto label_18d34c;
            case 0x18D350u: goto label_18d350;
            case 0x18D354u: goto label_18d354;
            case 0x18D358u: goto label_18d358;
            case 0x18D35Cu: goto label_18d35c;
            case 0x18D360u: goto label_18d360;
            case 0x18D364u: goto label_18d364;
            case 0x18D368u: goto label_18d368;
            case 0x18D36Cu: goto label_18d36c;
            case 0x18D370u: goto label_18d370;
            case 0x18D374u: goto label_18d374;
            case 0x18D378u: goto label_18d378;
            case 0x18D37Cu: goto label_18d37c;
            case 0x18D380u: goto label_18d380;
            case 0x18D384u: goto label_18d384;
            case 0x18D388u: goto label_18d388;
            case 0x18D38Cu: goto label_18d38c;
            case 0x18D390u: goto label_18d390;
            case 0x18D394u: goto label_18d394;
            case 0x18D398u: goto label_18d398;
            case 0x18D39Cu: goto label_18d39c;
            case 0x18D3A0u: goto label_18d3a0;
            case 0x18D3A4u: goto label_18d3a4;
            case 0x18D3A8u: goto label_18d3a8;
            case 0x18D3ACu: goto label_18d3ac;
            case 0x18D3B0u: goto label_18d3b0;
            case 0x18D3B4u: goto label_18d3b4;
            case 0x18D3B8u: goto label_18d3b8;
            case 0x18D3BCu: goto label_18d3bc;
            case 0x18D3C0u: goto label_18d3c0;
            case 0x18D3C4u: goto label_18d3c4;
            case 0x18D3C8u: goto label_18d3c8;
            case 0x18D3CCu: goto label_18d3cc;
            case 0x18D3D0u: goto label_18d3d0;
            case 0x18D3D4u: goto label_18d3d4;
            case 0x18D3D8u: goto label_18d3d8;
            case 0x18D3DCu: goto label_18d3dc;
            case 0x18D3E0u: goto label_18d3e0;
            case 0x18D3E4u: goto label_18d3e4;
            case 0x18D3E8u: goto label_18d3e8;
            case 0x18D3ECu: goto label_18d3ec;
            case 0x18D3F0u: goto label_18d3f0;
            case 0x18D3F4u: goto label_18d3f4;
            case 0x18D3F8u: goto label_18d3f8;
            case 0x18D3FCu: goto label_18d3fc;
            case 0x18D400u: goto label_18d400;
            case 0x18D404u: goto label_18d404;
            case 0x18D408u: goto label_18d408;
            case 0x18D40Cu: goto label_18d40c;
            case 0x18D410u: goto label_18d410;
            case 0x18D414u: goto label_18d414;
            case 0x18D418u: goto label_18d418;
            case 0x18D41Cu: goto label_18d41c;
            case 0x18D420u: goto label_18d420;
            case 0x18D424u: goto label_18d424;
            case 0x18D428u: goto label_18d428;
            case 0x18D42Cu: goto label_18d42c;
            case 0x18D430u: goto label_18d430;
            case 0x18D434u: goto label_18d434;
            case 0x18D438u: goto label_18d438;
            case 0x18D43Cu: goto label_18d43c;
            case 0x18D440u: goto label_18d440;
            case 0x18D444u: goto label_18d444;
            case 0x18D448u: goto label_18d448;
            case 0x18D44Cu: goto label_18d44c;
            case 0x18D450u: goto label_18d450;
            case 0x18D454u: goto label_18d454;
            case 0x18D458u: goto label_18d458;
            case 0x18D45Cu: goto label_18d45c;
            case 0x18D460u: goto label_18d460;
            case 0x18D464u: goto label_18d464;
            case 0x18D468u: goto label_18d468;
            case 0x18D46Cu: goto label_18d46c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18D160u;
label_18d160:
    // 0x18d160: 0x27bdffc0
    ctx->pc = 0x18d160u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
label_18d164:
    // 0x18d164: 0x24020001
    ctx->pc = 0x18d164u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_18d168:
    // 0x18d168: 0xffbf0030
    ctx->pc = 0x18d168u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
label_18d16c:
    // 0x18d16c: 0x7fb20020
    ctx->pc = 0x18d16cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
label_18d170:
    // 0x18d170: 0x7fb10010
    ctx->pc = 0x18d170u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
label_18d174:
    // 0x18d174: 0x3c12002a
    ctx->pc = 0x18d174u;
    SET_GPR_U32(ctx, 18, ((uint32_t)42 << 16));
label_18d178:
    // 0x18d178: 0x7fb00000
    ctx->pc = 0x18d178u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
label_18d17c:
    // 0x18d17c: 0x10820003
label_18d180:
    if (ctx->pc == 0x18D180u) {
        ctx->pc = 0x18D180u;
        SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 4294964976));
        ctx->pc = 0x18D184u;
        goto label_18d184;
    }
    ctx->pc = 0x18D17Cu;
    {
        const bool branch_taken_0x18d17c = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        ctx->pc = 0x18D180u;
        SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 4294964976));
        if (branch_taken_0x18d17c) {
            ctx->pc = 0x18D18Cu;
            goto label_18d18c;
        }
    }
    ctx->pc = 0x18D184u;
label_18d184:
    // 0x18d184: 0x100000b0
label_18d188:
    if (ctx->pc == 0x18D188u) {
        ctx->pc = 0x18D18Cu;
        goto label_18d18c;
    }
    ctx->pc = 0x18D184u;
    {
        const bool branch_taken_0x18d184 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x18d184) {
            ctx->pc = 0x18D448u;
            goto label_18d448;
        }
    }
    ctx->pc = 0x18D18Cu;
label_18d18c:
    // 0x18d18c: 0x8e430000
    ctx->pc = 0x18d18cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_18d190:
    // 0x18d190: 0x3c020023
    ctx->pc = 0x18d190u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
label_18d194:
    // 0x18d194: 0x2442fdf0
    ctx->pc = 0x18d194u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294966768));
label_18d198:
    // 0x18d198: 0x31880
    ctx->pc = 0x18d198u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 2));
label_18d19c:
    // 0x18d19c: 0x431021
    ctx->pc = 0x18d19cu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_18d1a0:
    // 0x18d1a0: 0x8c420000
    ctx->pc = 0x18d1a0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_18d1a4:
    // 0x18d1a4: 0x8c440000
    ctx->pc = 0x18d1a4u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_18d1a8:
    // 0x18d1a8: 0x30820100
    ctx->pc = 0x18d1a8u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), 256));
label_18d1ac:
    // 0x18d1ac: 0x144000a6
label_18d1b0:
    if (ctx->pc == 0x18D1B0u) {
        ctx->pc = 0x18D1B0u;
        SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 4), 12));
        ctx->pc = 0x18D1B4u;
        goto label_18d1b4;
    }
    ctx->pc = 0x18D1ACu;
    {
        const bool branch_taken_0x18d1ac = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x18D1B0u;
        SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 4), 12));
        if (branch_taken_0x18d1ac) {
            ctx->pc = 0x18D448u;
            goto label_18d448;
        }
    }
    ctx->pc = 0x18D1B4u;
label_18d1b4:
    // 0x18d1b4: 0x24020004
    ctx->pc = 0x18d1b4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
label_18d1b8:
    // 0x18d1b8: 0x14620009
label_18d1bc:
    if (ctx->pc == 0x18D1BCu) {
        ctx->pc = 0x18D1BCu;
        SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), 128));
        ctx->pc = 0x18D1C0u;
        goto label_18d1c0;
    }
    ctx->pc = 0x18D1B8u;
    {
        const bool branch_taken_0x18d1b8 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x18D1BCu;
        SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), 128));
        if (branch_taken_0x18d1b8) {
            ctx->pc = 0x18D1E0u;
            goto label_18d1e0;
        }
    }
    ctx->pc = 0x18D1C0u;
label_18d1c0:
    // 0x18d1c0: 0x104000a1
label_18d1c4:
    if (ctx->pc == 0x18D1C4u) {
        ctx->pc = 0x18D1C8u;
        goto label_18d1c8;
    }
    ctx->pc = 0x18D1C0u;
    {
        const bool branch_taken_0x18d1c0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x18d1c0) {
            ctx->pc = 0x18D448u;
            goto label_18d448;
        }
    }
    ctx->pc = 0x18D1C8u;
label_18d1c8:
    // 0x18d1c8: 0x3c028000
    ctx->pc = 0x18d1c8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)32768 << 16));
label_18d1cc:
    // 0x18d1cc: 0x821024
    ctx->pc = 0x18d1ccu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_18d1d0:
    // 0x18d1d0: 0x14400009
label_18d1d4:
    if (ctx->pc == 0x18D1D4u) {
        ctx->pc = 0x18D1D8u;
        goto label_18d1d8;
    }
    ctx->pc = 0x18D1D0u;
    {
        const bool branch_taken_0x18d1d0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x18d1d0) {
            ctx->pc = 0x18D1F8u;
            goto label_18d1f8;
        }
    }
    ctx->pc = 0x18D1D8u;
label_18d1d8:
    // 0x18d1d8: 0x1000009b
label_18d1dc:
    if (ctx->pc == 0x18D1DCu) {
        ctx->pc = 0x18D1E0u;
        goto label_18d1e0;
    }
    ctx->pc = 0x18D1D8u;
    {
        const bool branch_taken_0x18d1d8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x18d1d8) {
            ctx->pc = 0x18D448u;
            goto label_18d448;
        }
    }
    ctx->pc = 0x18D1E0u;
label_18d1e0:
    // 0x18d1e0: 0x14600099
label_18d1e4:
    if (ctx->pc == 0x18D1E4u) {
        ctx->pc = 0x18D1E8u;
        goto label_18d1e8;
    }
    ctx->pc = 0x18D1E0u;
    {
        const bool branch_taken_0x18d1e0 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x18d1e0) {
            ctx->pc = 0x18D448u;
            goto label_18d448;
        }
    }
    ctx->pc = 0x18D1E8u;
label_18d1e8:
    // 0x18d1e8: 0x8e420030
    ctx->pc = 0x18d1e8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 48)));
label_18d1ec:
    // 0x18d1ec: 0x30420001
    ctx->pc = 0x18d1ecu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 1));
label_18d1f0:
    // 0x18d1f0: 0x10400095
label_18d1f4:
    if (ctx->pc == 0x18D1F4u) {
        ctx->pc = 0x18D1F8u;
        goto label_18d1f8;
    }
    ctx->pc = 0x18D1F0u;
    {
        const bool branch_taken_0x18d1f0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x18d1f0) {
            ctx->pc = 0x18D448u;
            goto label_18d448;
        }
    }
    ctx->pc = 0x18D1F8u;
label_18d1f8:
    // 0x18d1f8: 0x3c01002a
    ctx->pc = 0x18d1f8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
label_18d1fc:
    // 0x18d1fc: 0x8c22fdb4
    ctx->pc = 0x18d1fcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 4294966708)));
label_18d200:
    // 0x18d200: 0x38500001
    ctx->pc = 0x18d200u;
    SET_GPR_U32(ctx, 16, XOR32(GPR_U32(ctx, 2), 1));
label_18d204:
    // 0x18d204: 0x101080
    ctx->pc = 0x18d204u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 16), 2));
label_18d208:
    // 0x18d208: 0x521021
    ctx->pc = 0x18d208u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 18)));
label_18d20c:
    // 0x18d20c: 0xc063728
label_18d210:
    if (ctx->pc == 0x18D210u) {
        ctx->pc = 0x18D210u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 12)));
        ctx->pc = 0x18D214u;
        goto label_18d214;
    }
    ctx->pc = 0x18D20Cu;
    SET_GPR_U32(ctx, 31, 0x18D214u);
    ctx->pc = 0x18D210u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 12)));
    ctx->pc = 0x18DCA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D214u; }
    }
    if (ctx->pc != 0x18D214u) { return; }
    ctx->pc = 0x18D214u;
label_18d214:
    // 0x18d214: 0x101880
    ctx->pc = 0x18d214u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 16), 2));
label_18d218:
    // 0x18d218: 0x722821
    ctx->pc = 0x18d218u;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 18)));
label_18d21c:
    // 0x18d21c: 0x8ca30014
    ctx->pc = 0x18d21cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 5), 20)));
label_18d220:
    // 0x18d220: 0x2463ffff
    ctx->pc = 0x18d220u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294967295));
label_18d224:
    // 0x18d224: 0xaca30014
    ctx->pc = 0x18d224u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 20), GPR_U32(ctx, 3));
label_18d228:
    // 0x18d228: 0x8ca30024
    ctx->pc = 0x18d228u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 5), 36)));
label_18d22c:
    // 0x18d22c: 0x24640001
    ctx->pc = 0x18d22cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 3), 1));
label_18d230:
    // 0x18d230: 0x31880
    ctx->pc = 0x18d230u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 2));
label_18d234:
    // 0x18d234: 0xaca40024
    ctx->pc = 0x18d234u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 36), GPR_U32(ctx, 4));
label_18d238:
    // 0x18d238: 0x431821
    ctx->pc = 0x18d238u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_18d23c:
    // 0x18d23c: 0x8ca40024
    ctx->pc = 0x18d23cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 5), 36)));
label_18d240:
    // 0x18d240: 0x8c710000
    ctx->pc = 0x18d240u;
    SET_GPR_U32(ctx, 17, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_18d244:
    // 0x18d244: 0x8e430004
    ctx->pc = 0x18d244u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 4)));
label_18d248:
    // 0x18d248: 0x14830002
label_18d24c:
    if (ctx->pc == 0x18D24Cu) {
        ctx->pc = 0x18D24Cu;
        SET_GPR_U32(ctx, 4, ((uint32_t)61440 << 16));
        ctx->pc = 0x18D250u;
        goto label_18d250;
    }
    ctx->pc = 0x18D248u;
    {
        const bool branch_taken_0x18d248 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 3));
        ctx->pc = 0x18D24Cu;
        SET_GPR_U32(ctx, 4, ((uint32_t)61440 << 16));
        if (branch_taken_0x18d248) {
            ctx->pc = 0x18D254u;
            goto label_18d254;
        }
    }
    ctx->pc = 0x18D250u;
label_18d250:
    // 0x18d250: 0xaca00024
    ctx->pc = 0x18d250u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 36), GPR_U32(ctx, 0));
label_18d254:
    // 0x18d254: 0x24030002
    ctx->pc = 0x18d254u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
label_18d258:
    // 0x18d258: 0x2242024
    ctx->pc = 0x18d258u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 17), GPR_U32(ctx, 4)));
label_18d25c:
    // 0x18d25c: 0x42702
    ctx->pc = 0x18d25cu;
    SET_GPR_U32(ctx, 4, SRL32(GPR_U32(ctx, 4), 28));
label_18d260:
    // 0x18d260: 0x10830003
label_18d264:
    if (ctx->pc == 0x18D264u) {
        ctx->pc = 0x18D268u;
        goto label_18d268;
    }
    ctx->pc = 0x18D260u;
    {
        const bool branch_taken_0x18d260 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        if (branch_taken_0x18d260) {
            ctx->pc = 0x18D270u;
            goto label_18d270;
        }
    }
    ctx->pc = 0x18D268u;
label_18d268:
    // 0x18d268: 0x1000000f
label_18d26c:
    if (ctx->pc == 0x18D26Cu) {
        ctx->pc = 0x18D26Cu;
        SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 16), 2));
        ctx->pc = 0x18D270u;
        goto label_18d270;
    }
    ctx->pc = 0x18D268u;
    {
        const bool branch_taken_0x18d268 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x18D26Cu;
        SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 16), 2));
        if (branch_taken_0x18d268) {
            ctx->pc = 0x18D2A8u;
            goto label_18d2a8;
        }
    }
    ctx->pc = 0x18D270u;
label_18d270:
    // 0x18d270: 0xae400030
    ctx->pc = 0x18d270u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 48), GPR_U32(ctx, 0));
label_18d274:
    // 0x18d274: 0x3c011000
    ctx->pc = 0x18d274u;
    SET_GPR_U32(ctx, 1, ((uint32_t)4096 << 16));
label_18d278:
    // 0x18d278: 0xac203c00
    ctx->pc = 0x18d278u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 1), 15360), GPR_U32(ctx, 0)); // MMIO: 0x10003c00
label_18d27c:
    // 0x18d27c: 0x3c011200
    ctx->pc = 0x18d27cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4608 << 16));
label_18d280:
    // 0x18d280: 0xfc201040
    ctx->pc = 0x18d280u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4160), GPR_U64(ctx, 0));
label_18d284:
    // 0x18d284: 0x3c010029
    ctx->pc = 0x18d284u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
label_18d288:
    // 0x18d288: 0xdc234158
    ctx->pc = 0x18d288u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 1), 16728)));
label_18d28c:
    // 0x18d28c: 0x3c011200
    ctx->pc = 0x18d28cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4608 << 16));
label_18d290:
    // 0x18d290: 0xfc231010
    ctx->pc = 0x18d290u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4112), GPR_U64(ctx, 3));
label_18d294:
    // 0x18d294: 0x3c010023
    ctx->pc = 0x18d294u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
label_18d298:
    // 0x18d298: 0x7823fde0
    ctx->pc = 0x18d298u;
    SET_GPR_VEC(ctx, 3, READ128(ADD32(GPR_U32(ctx, 1), 4294966752)));
label_18d29c:
    // 0x18d29c: 0x3c011000
    ctx->pc = 0x18d29cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4096 << 16));
label_18d2a0:
    // 0x18d2a0: 0x7c235000
    ctx->pc = 0x18d2a0u;
    WRITE128(ADD32(GPR_U32(ctx, 1), 20480), GPR_VEC(ctx, 3));
label_18d2a4:
    // 0x18d2a4: 0x101880
    ctx->pc = 0x18d2a4u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 16), 2));
label_18d2a8:
    // 0x18d2a8: 0x721821
    ctx->pc = 0x18d2a8u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 18)));
label_18d2ac:
    // 0x18d2ac: 0x8c64001c
    ctx->pc = 0x18d2acu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 3), 28)));
label_18d2b0:
    // 0x18d2b0: 0x8c630024
    ctx->pc = 0x18d2b0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 3), 36)));
label_18d2b4:
    // 0x18d2b4: 0x10830064
label_18d2b8:
    if (ctx->pc == 0x18D2B8u) {
        ctx->pc = 0x18D2B8u;
        SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 3), 2));
        ctx->pc = 0x18D2BCu;
        goto label_18d2bc;
    }
    ctx->pc = 0x18D2B4u;
    {
        const bool branch_taken_0x18d2b4 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 3));
        ctx->pc = 0x18D2B8u;
        SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 3), 2));
        if (branch_taken_0x18d2b4) {
            ctx->pc = 0x18D448u;
            goto label_18d448;
        }
    }
    ctx->pc = 0x18D2BCu;
label_18d2bc:
    // 0x18d2bc: 0x441021
    ctx->pc = 0x18d2bcu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
label_18d2c0:
    // 0x18d2c0: 0x3c03f000
    ctx->pc = 0x18d2c0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)61440 << 16));
label_18d2c4:
    // 0x18d2c4: 0x8c510000
    ctx->pc = 0x18d2c4u;
    SET_GPR_U32(ctx, 17, READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_18d2c8:
    // 0x18d2c8: 0x2231024
    ctx->pc = 0x18d2c8u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
label_18d2cc:
    // 0x18d2cc: 0xae51002c
    ctx->pc = 0x18d2ccu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 44), GPR_U32(ctx, 17));
label_18d2d0:
    // 0x18d2d0: 0x11893c
    ctx->pc = 0x18d2d0u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) << (32 + 4));
label_18d2d4:
    // 0x18d2d4: 0x11893e
    ctx->pc = 0x18d2d4u;
    SET_GPR_U64(ctx, 17, GPR_U64(ctx, 17) >> (32 + 4));
label_18d2d8:
    // 0x18d2d8: 0x1220005b
label_18d2dc:
    if (ctx->pc == 0x18D2DCu) {
        ctx->pc = 0x18D2DCu;
        SET_GPR_U32(ctx, 4, SRL32(GPR_U32(ctx, 2), 28));
        ctx->pc = 0x18D2E0u;
        goto label_18d2e0;
    }
    ctx->pc = 0x18D2D8u;
    {
        const bool branch_taken_0x18d2d8 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 0));
        ctx->pc = 0x18D2DCu;
        SET_GPR_U32(ctx, 4, SRL32(GPR_U32(ctx, 2), 28));
        if (branch_taken_0x18d2d8) {
            ctx->pc = 0x18D448u;
            goto label_18d448;
        }
    }
    ctx->pc = 0x18D2E0u;
label_18d2e0:
    // 0x18d2e0: 0x2c810006
    ctx->pc = 0x18d2e0u;
    SET_GPR_U32(ctx, 1, SLTU32(GPR_U32(ctx, 4), 6));
label_18d2e4:
    // 0x18d2e4: 0x10200058
label_18d2e8:
    if (ctx->pc == 0x18D2E8u) {
        ctx->pc = 0x18D2E8u;
        SET_GPR_U32(ctx, 3, ((uint32_t)36 << 16));
        ctx->pc = 0x18D2ECu;
        goto label_18d2ec;
    }
    ctx->pc = 0x18D2E4u;
    {
        const bool branch_taken_0x18d2e4 = (GPR_U32(ctx, 1) == GPR_U32(ctx, 0));
        ctx->pc = 0x18D2E8u;
        SET_GPR_U32(ctx, 3, ((uint32_t)36 << 16));
        if (branch_taken_0x18d2e4) {
            ctx->pc = 0x18D448u;
            goto label_18d448;
        }
    }
    ctx->pc = 0x18D2ECu;
label_18d2ec:
    // 0x18d2ec: 0x41080
    ctx->pc = 0x18d2ecu;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 4), 2));
label_18d2f0:
    // 0x18d2f0: 0x24631c10
    ctx->pc = 0x18d2f0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 7184));
label_18d2f4:
    // 0x18d2f4: 0x431021
    ctx->pc = 0x18d2f4u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_18d2f8:
    // 0x18d2f8: 0x8c420000
    ctx->pc = 0x18d2f8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_18d2fc:
    // 0x18d2fc: 0x400008
label_18d300:
    if (ctx->pc == 0x18D300u) {
        ctx->pc = 0x18D304u;
        goto label_18d304;
    }
    ctx->pc = 0x18D2FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18CFB0u: goto label_18cfb0;
            case 0x18CFB4u: goto label_18cfb4;
            case 0x18CFB8u: goto label_18cfb8;
            case 0x18CFBCu: goto label_18cfbc;
            case 0x18CFC0u: goto label_18cfc0;
            case 0x18CFC4u: goto label_18cfc4;
            case 0x18CFC8u: goto label_18cfc8;
            case 0x18CFCCu: goto label_18cfcc;
            case 0x18CFD0u: goto label_18cfd0;
            case 0x18CFD4u: goto label_18cfd4;
            case 0x18CFD8u: goto label_18cfd8;
            case 0x18CFDCu: goto label_18cfdc;
            case 0x18CFE0u: goto label_18cfe0;
            case 0x18CFE4u: goto label_18cfe4;
            case 0x18CFE8u: goto label_18cfe8;
            case 0x18CFECu: goto label_18cfec;
            case 0x18CFF0u: goto label_18cff0;
            case 0x18CFF4u: goto label_18cff4;
            case 0x18CFF8u: goto label_18cff8;
            case 0x18CFFCu: goto label_18cffc;
            case 0x18D000u: goto label_18d000;
            case 0x18D004u: goto label_18d004;
            case 0x18D008u: goto label_18d008;
            case 0x18D00Cu: goto label_18d00c;
            case 0x18D010u: goto label_18d010;
            case 0x18D014u: goto label_18d014;
            case 0x18D018u: goto label_18d018;
            case 0x18D01Cu: goto label_18d01c;
            case 0x18D020u: goto label_18d020;
            case 0x18D024u: goto label_18d024;
            case 0x18D028u: goto label_18d028;
            case 0x18D02Cu: goto label_18d02c;
            case 0x18D030u: goto label_18d030;
            case 0x18D034u: goto label_18d034;
            case 0x18D038u: goto label_18d038;
            case 0x18D03Cu: goto label_18d03c;
            case 0x18D040u: goto label_18d040;
            case 0x18D044u: goto label_18d044;
            case 0x18D048u: goto label_18d048;
            case 0x18D04Cu: goto label_18d04c;
            case 0x18D050u: goto label_18d050;
            case 0x18D054u: goto label_18d054;
            case 0x18D058u: goto label_18d058;
            case 0x18D05Cu: goto label_18d05c;
            case 0x18D060u: goto label_18d060;
            case 0x18D064u: goto label_18d064;
            case 0x18D068u: goto label_18d068;
            case 0x18D06Cu: goto label_18d06c;
            case 0x18D070u: goto label_18d070;
            case 0x18D074u: goto label_18d074;
            case 0x18D078u: goto label_18d078;
            case 0x18D07Cu: goto label_18d07c;
            case 0x18D080u: goto label_18d080;
            case 0x18D084u: goto label_18d084;
            case 0x18D088u: goto label_18d088;
            case 0x18D08Cu: goto label_18d08c;
            case 0x18D090u: goto label_18d090;
            case 0x18D094u: goto label_18d094;
            case 0x18D098u: goto label_18d098;
            case 0x18D09Cu: goto label_18d09c;
            case 0x18D0A0u: goto label_18d0a0;
            case 0x18D0A4u: goto label_18d0a4;
            case 0x18D0A8u: goto label_18d0a8;
            case 0x18D0ACu: goto label_18d0ac;
            case 0x18D0B0u: goto label_18d0b0;
            case 0x18D0B4u: goto label_18d0b4;
            case 0x18D0B8u: goto label_18d0b8;
            case 0x18D0BCu: goto label_18d0bc;
            case 0x18D0C0u: goto label_18d0c0;
            case 0x18D0C4u: goto label_18d0c4;
            case 0x18D0C8u: goto label_18d0c8;
            case 0x18D0CCu: goto label_18d0cc;
            case 0x18D0D0u: goto label_18d0d0;
            case 0x18D0D4u: goto label_18d0d4;
            case 0x18D0D8u: goto label_18d0d8;
            case 0x18D0DCu: goto label_18d0dc;
            case 0x18D0E0u: goto label_18d0e0;
            case 0x18D0E4u: goto label_18d0e4;
            case 0x18D0E8u: goto label_18d0e8;
            case 0x18D0ECu: goto label_18d0ec;
            case 0x18D0F0u: goto label_18d0f0;
            case 0x18D0F4u: goto label_18d0f4;
            case 0x18D0F8u: goto label_18d0f8;
            case 0x18D0FCu: goto label_18d0fc;
            case 0x18D100u: goto label_18d100;
            case 0x18D104u: goto label_18d104;
            case 0x18D108u: goto label_18d108;
            case 0x18D10Cu: goto label_18d10c;
            case 0x18D110u: goto label_18d110;
            case 0x18D114u: goto label_18d114;
            case 0x18D118u: goto label_18d118;
            case 0x18D11Cu: goto label_18d11c;
            case 0x18D120u: goto label_18d120;
            case 0x18D124u: goto label_18d124;
            case 0x18D128u: goto label_18d128;
            case 0x18D12Cu: goto label_18d12c;
            case 0x18D130u: goto label_18d130;
            case 0x18D134u: goto label_18d134;
            case 0x18D138u: goto label_18d138;
            case 0x18D13Cu: goto label_18d13c;
            case 0x18D140u: goto label_18d140;
            case 0x18D144u: goto label_18d144;
            case 0x18D148u: goto label_18d148;
            case 0x18D14Cu: goto label_18d14c;
            case 0x18D150u: goto label_18d150;
            case 0x18D154u: goto label_18d154;
            case 0x18D158u: goto label_18d158;
            case 0x18D15Cu: goto label_18d15c;
            case 0x18D160u: goto label_18d160;
            case 0x18D164u: goto label_18d164;
            case 0x18D168u: goto label_18d168;
            case 0x18D16Cu: goto label_18d16c;
            case 0x18D170u: goto label_18d170;
            case 0x18D174u: goto label_18d174;
            case 0x18D178u: goto label_18d178;
            case 0x18D17Cu: goto label_18d17c;
            case 0x18D180u: goto label_18d180;
            case 0x18D184u: goto label_18d184;
            case 0x18D188u: goto label_18d188;
            case 0x18D18Cu: goto label_18d18c;
            case 0x18D190u: goto label_18d190;
            case 0x18D194u: goto label_18d194;
            case 0x18D198u: goto label_18d198;
            case 0x18D19Cu: goto label_18d19c;
            case 0x18D1A0u: goto label_18d1a0;
            case 0x18D1A4u: goto label_18d1a4;
            case 0x18D1A8u: goto label_18d1a8;
            case 0x18D1ACu: goto label_18d1ac;
            case 0x18D1B0u: goto label_18d1b0;
            case 0x18D1B4u: goto label_18d1b4;
            case 0x18D1B8u: goto label_18d1b8;
            case 0x18D1BCu: goto label_18d1bc;
            case 0x18D1C0u: goto label_18d1c0;
            case 0x18D1C4u: goto label_18d1c4;
            case 0x18D1C8u: goto label_18d1c8;
            case 0x18D1CCu: goto label_18d1cc;
            case 0x18D1D0u: goto label_18d1d0;
            case 0x18D1D4u: goto label_18d1d4;
            case 0x18D1D8u: goto label_18d1d8;
            case 0x18D1DCu: goto label_18d1dc;
            case 0x18D1E0u: goto label_18d1e0;
            case 0x18D1E4u: goto label_18d1e4;
            case 0x18D1E8u: goto label_18d1e8;
            case 0x18D1ECu: goto label_18d1ec;
            case 0x18D1F0u: goto label_18d1f0;
            case 0x18D1F4u: goto label_18d1f4;
            case 0x18D1F8u: goto label_18d1f8;
            case 0x18D1FCu: goto label_18d1fc;
            case 0x18D200u: goto label_18d200;
            case 0x18D204u: goto label_18d204;
            case 0x18D208u: goto label_18d208;
            case 0x18D20Cu: goto label_18d20c;
            case 0x18D210u: goto label_18d210;
            case 0x18D214u: goto label_18d214;
            case 0x18D218u: goto label_18d218;
            case 0x18D21Cu: goto label_18d21c;
            case 0x18D220u: goto label_18d220;
            case 0x18D224u: goto label_18d224;
            case 0x18D228u: goto label_18d228;
            case 0x18D22Cu: goto label_18d22c;
            case 0x18D230u: goto label_18d230;
            case 0x18D234u: goto label_18d234;
            case 0x18D238u: goto label_18d238;
            case 0x18D23Cu: goto label_18d23c;
            case 0x18D240u: goto label_18d240;
            case 0x18D244u: goto label_18d244;
            case 0x18D248u: goto label_18d248;
            case 0x18D24Cu: goto label_18d24c;
            case 0x18D250u: goto label_18d250;
            case 0x18D254u: goto label_18d254;
            case 0x18D258u: goto label_18d258;
            case 0x18D25Cu: goto label_18d25c;
            case 0x18D260u: goto label_18d260;
            case 0x18D264u: goto label_18d264;
            case 0x18D268u: goto label_18d268;
            case 0x18D26Cu: goto label_18d26c;
            case 0x18D270u: goto label_18d270;
            case 0x18D274u: goto label_18d274;
            case 0x18D278u: goto label_18d278;
            case 0x18D27Cu: goto label_18d27c;
            case 0x18D280u: goto label_18d280;
            case 0x18D284u: goto label_18d284;
            case 0x18D288u: goto label_18d288;
            case 0x18D28Cu: goto label_18d28c;
            case 0x18D290u: goto label_18d290;
            case 0x18D294u: goto label_18d294;
            case 0x18D298u: goto label_18d298;
            case 0x18D29Cu: goto label_18d29c;
            case 0x18D2A0u: goto label_18d2a0;
            case 0x18D2A4u: goto label_18d2a4;
            case 0x18D2A8u: goto label_18d2a8;
            case 0x18D2ACu: goto label_18d2ac;
            case 0x18D2B0u: goto label_18d2b0;
            case 0x18D2B4u: goto label_18d2b4;
            case 0x18D2B8u: goto label_18d2b8;
            case 0x18D2BCu: goto label_18d2bc;
            case 0x18D2C0u: goto label_18d2c0;
            case 0x18D2C4u: goto label_18d2c4;
            case 0x18D2C8u: goto label_18d2c8;
            case 0x18D2CCu: goto label_18d2cc;
            case 0x18D2D0u: goto label_18d2d0;
            case 0x18D2D4u: goto label_18d2d4;
            case 0x18D2D8u: goto label_18d2d8;
            case 0x18D2DCu: goto label_18d2dc;
            case 0x18D2E0u: goto label_18d2e0;
            case 0x18D2E4u: goto label_18d2e4;
            case 0x18D2E8u: goto label_18d2e8;
            case 0x18D2ECu: goto label_18d2ec;
            case 0x18D2F0u: goto label_18d2f0;
            case 0x18D2F4u: goto label_18d2f4;
            case 0x18D2F8u: goto label_18d2f8;
            case 0x18D2FCu: goto label_18d2fc;
            case 0x18D300u: goto label_18d300;
            case 0x18D304u: goto label_18d304;
            case 0x18D308u: goto label_18d308;
            case 0x18D30Cu: goto label_18d30c;
            case 0x18D310u: goto label_18d310;
            case 0x18D314u: goto label_18d314;
            case 0x18D318u: goto label_18d318;
            case 0x18D31Cu: goto label_18d31c;
            case 0x18D320u: goto label_18d320;
            case 0x18D324u: goto label_18d324;
            case 0x18D328u: goto label_18d328;
            case 0x18D32Cu: goto label_18d32c;
            case 0x18D330u: goto label_18d330;
            case 0x18D334u: goto label_18d334;
            case 0x18D338u: goto label_18d338;
            case 0x18D33Cu: goto label_18d33c;
            case 0x18D340u: goto label_18d340;
            case 0x18D344u: goto label_18d344;
            case 0x18D348u: goto label_18d348;
            case 0x18D34Cu: goto label_18d34c;
            case 0x18D350u: goto label_18d350;
            case 0x18D354u: goto label_18d354;
            case 0x18D358u: goto label_18d358;
            case 0x18D35Cu: goto label_18d35c;
            case 0x18D360u: goto label_18d360;
            case 0x18D364u: goto label_18d364;
            case 0x18D368u: goto label_18d368;
            case 0x18D36Cu: goto label_18d36c;
            case 0x18D370u: goto label_18d370;
            case 0x18D374u: goto label_18d374;
            case 0x18D378u: goto label_18d378;
            case 0x18D37Cu: goto label_18d37c;
            case 0x18D380u: goto label_18d380;
            case 0x18D384u: goto label_18d384;
            case 0x18D388u: goto label_18d388;
            case 0x18D38Cu: goto label_18d38c;
            case 0x18D390u: goto label_18d390;
            case 0x18D394u: goto label_18d394;
            case 0x18D398u: goto label_18d398;
            case 0x18D39Cu: goto label_18d39c;
            case 0x18D3A0u: goto label_18d3a0;
            case 0x18D3A4u: goto label_18d3a4;
            case 0x18D3A8u: goto label_18d3a8;
            case 0x18D3ACu: goto label_18d3ac;
            case 0x18D3B0u: goto label_18d3b0;
            case 0x18D3B4u: goto label_18d3b4;
            case 0x18D3B8u: goto label_18d3b8;
            case 0x18D3BCu: goto label_18d3bc;
            case 0x18D3C0u: goto label_18d3c0;
            case 0x18D3C4u: goto label_18d3c4;
            case 0x18D3C8u: goto label_18d3c8;
            case 0x18D3CCu: goto label_18d3cc;
            case 0x18D3D0u: goto label_18d3d0;
            case 0x18D3D4u: goto label_18d3d4;
            case 0x18D3D8u: goto label_18d3d8;
            case 0x18D3DCu: goto label_18d3dc;
            case 0x18D3E0u: goto label_18d3e0;
            case 0x18D3E4u: goto label_18d3e4;
            case 0x18D3E8u: goto label_18d3e8;
            case 0x18D3ECu: goto label_18d3ec;
            case 0x18D3F0u: goto label_18d3f0;
            case 0x18D3F4u: goto label_18d3f4;
            case 0x18D3F8u: goto label_18d3f8;
            case 0x18D3FCu: goto label_18d3fc;
            case 0x18D400u: goto label_18d400;
            case 0x18D404u: goto label_18d404;
            case 0x18D408u: goto label_18d408;
            case 0x18D40Cu: goto label_18d40c;
            case 0x18D410u: goto label_18d410;
            case 0x18D414u: goto label_18d414;
            case 0x18D418u: goto label_18d418;
            case 0x18D41Cu: goto label_18d41c;
            case 0x18D420u: goto label_18d420;
            case 0x18D424u: goto label_18d424;
            case 0x18D428u: goto label_18d428;
            case 0x18D42Cu: goto label_18d42c;
            case 0x18D430u: goto label_18d430;
            case 0x18D434u: goto label_18d434;
            case 0x18D438u: goto label_18d438;
            case 0x18D43Cu: goto label_18d43c;
            case 0x18D440u: goto label_18d440;
            case 0x18D444u: goto label_18d444;
            case 0x18D448u: goto label_18d448;
            case 0x18D44Cu: goto label_18d44c;
            case 0x18D450u: goto label_18d450;
            case 0x18D454u: goto label_18d454;
            case 0x18D458u: goto label_18d458;
            case 0x18D45Cu: goto label_18d45c;
            case 0x18D460u: goto label_18d460;
            case 0x18D464u: goto label_18d464;
            case 0x18D468u: goto label_18d468;
            case 0x18D46Cu: goto label_18d46c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18D304u;
label_18d304:
    // 0x18d304: 0x8e470000
    ctx->pc = 0x18d304u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_18d308:
    // 0x18d308: 0x3c09002a
    ctx->pc = 0x18d308u;
    SET_GPR_U32(ctx, 9, ((uint32_t)42 << 16));
label_18d30c:
    // 0x18d30c: 0x2529fd74
    ctx->pc = 0x18d30cu;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 9), 4294966644));
label_18d310:
    // 0x18d310: 0x2404ffbf
    ctx->pc = 0x18d310u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4294967231));
label_18d314:
    // 0x18d314: 0x64060040
    ctx->pc = 0x18d314u;
    SET_GPR_S64(ctx, 6, (int64_t)GPR_S64(ctx, 0) + (int64_t)64);
label_18d318:
    // 0x18d318: 0x2402ff7f
    ctx->pc = 0x18d318u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967167));
label_18d31c:
    // 0x18d31c: 0x64030080
    ctx->pc = 0x18d31cu;
    SET_GPR_S64(ctx, 3, (int64_t)GPR_S64(ctx, 0) + (int64_t)128);
label_18d320:
    // 0x18d320: 0x73880
    ctx->pc = 0x18d320u;
    SET_GPR_U32(ctx, 7, SLL32(GPR_U32(ctx, 7), 2));
label_18d324:
    // 0x18d324: 0x1273821
    ctx->pc = 0x18d324u;
    SET_GPR_U32(ctx, 7, ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 7)));
label_18d328:
    // 0x18d328: 0x8ce80000
    ctx->pc = 0x18d328u;
    SET_GPR_U32(ctx, 8, READ32(ADD32(GPR_U32(ctx, 7), 0)));
label_18d32c:
    // 0x18d32c: 0x91070000
    ctx->pc = 0x18d32cu;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
label_18d330:
    // 0x18d330: 0xe42024
    ctx->pc = 0x18d330u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
label_18d334:
    // 0x18d334: 0x862025
    ctx->pc = 0x18d334u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
label_18d338:
    // 0x18d338: 0xa1040000
    ctx->pc = 0x18d338u;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 4));
label_18d33c:
    // 0x18d33c: 0x8e440000
    ctx->pc = 0x18d33cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_18d340:
    // 0x18d340: 0x42080
    ctx->pc = 0x18d340u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 2));
label_18d344:
    // 0x18d344: 0x1242021
    ctx->pc = 0x18d344u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 4)));
label_18d348:
    // 0x18d348: 0x8c860000
    ctx->pc = 0x18d348u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_18d34c:
    // 0x18d34c: 0x90c40000
    ctx->pc = 0x18d34cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
label_18d350:
    // 0x18d350: 0x821024
    ctx->pc = 0x18d350u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_18d354:
    // 0x18d354: 0x431025
    ctx->pc = 0x18d354u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_18d358:
    // 0x18d358: 0xa0c20000
    ctx->pc = 0x18d358u;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
label_18d35c:
    // 0x18d35c: 0x8e420000
    ctx->pc = 0x18d35cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_18d360:
    // 0x18d360: 0x21080
    ctx->pc = 0x18d360u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 2));
label_18d364:
    // 0x18d364: 0x1221021
    ctx->pc = 0x18d364u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
label_18d368:
    // 0x18d368: 0x8c440000
    ctx->pc = 0x18d368u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_18d36c:
    // 0x18d36c: 0xc040ce4
label_18d370:
    if (ctx->pc == 0x18D370u) {
        ctx->pc = 0x18D370u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18D374u;
        goto label_18d374;
    }
    ctx->pc = 0x18D36Cu;
    SET_GPR_U32(ctx, 31, 0x18D374u);
    ctx->pc = 0x18D370u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x103390u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00103390_0x103390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D374u; }
    }
    if (ctx->pc != 0x18D374u) { return; }
    ctx->pc = 0x18D374u;
label_18d374:
    // 0x18d374: 0x10000034
label_18d378:
    if (ctx->pc == 0x18D378u) {
        ctx->pc = 0x18D37Cu;
        goto label_18d37c;
    }
    ctx->pc = 0x18D374u;
    {
        const bool branch_taken_0x18d374 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x18d374) {
            ctx->pc = 0x18D448u;
            goto label_18d448;
        }
    }
    ctx->pc = 0x18D37Cu;
label_18d37c:
    // 0x18d37c: 0x8e250080
    ctx->pc = 0x18d37cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 17), 128)));
label_18d380:
    // 0x18d380: 0x3c010029
    ctx->pc = 0x18d380u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
label_18d384:
    // 0x18d384: 0x2402fdff
    ctx->pc = 0x18d384u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294966783));
label_18d388:
    // 0x18d388: 0x24030002
    ctx->pc = 0x18d388u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
label_18d38c:
    // 0x18d38c: 0x70021389
    ctx->pc = 0x18d38cu;
    SET_GPR_VEC(ctx, 2, _mm_unpacklo_epi64(GPR_VEC(ctx, 0), GPR_VEC(ctx, 2)));
label_18d390:
    // 0x18d390: 0x202d
    ctx->pc = 0x18d390u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18d394:
    // 0x18d394: 0xac254148
    ctx->pc = 0x18d394u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16712), GPR_U32(ctx, 5));
label_18d398:
    // 0x18d398: 0x8e250084
    ctx->pc = 0x18d398u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 17), 132)));
label_18d39c:
    // 0x18d39c: 0x3c010029
    ctx->pc = 0x18d39cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
label_18d3a0:
    // 0x18d3a0: 0xac254150
    ctx->pc = 0x18d3a0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16720), GPR_U32(ctx, 5));
label_18d3a4:
    // 0x18d3a4: 0x3c011200
    ctx->pc = 0x18d3a4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)4608 << 16));
label_18d3a8:
    // 0x18d3a8: 0xfc231000
    ctx->pc = 0x18d3a8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4096), GPR_U64(ctx, 3));
label_18d3ac:
    // 0x18d3ac: 0x3c011200
    ctx->pc = 0x18d3acu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4608 << 16));
label_18d3b0:
    // 0x18d3b0: 0xdc231010
    ctx->pc = 0x18d3b0u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 1), 4112)));
label_18d3b4:
    // 0x18d3b4: 0x3c010029
    ctx->pc = 0x18d3b4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
label_18d3b8:
    // 0x18d3b8: 0xfc234158
    ctx->pc = 0x18d3b8u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 16728), GPR_U64(ctx, 3));
label_18d3bc:
    // 0x18d3bc: 0x3c011200
    ctx->pc = 0x18d3bcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)4608 << 16));
label_18d3c0:
    // 0x18d3c0: 0xc0454a8
label_18d3c4:
    if (ctx->pc == 0x18D3C4u) {
        ctx->pc = 0x18D3C4u;
        WRITE64(ADD32(GPR_U32(ctx, 1), 4112), GPR_U64(ctx, 2));
        ctx->pc = 0x18D3C8u;
        goto label_18d3c8;
    }
    ctx->pc = 0x18D3C0u;
    SET_GPR_U32(ctx, 31, 0x18D3C8u);
    ctx->pc = 0x18D3C4u;
    WRITE64(ADD32(GPR_U32(ctx, 1), 4112), GPR_U64(ctx, 2));
    ctx->pc = 0x1152A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001152A0_0x1152a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D3C8u; }
    }
    if (ctx->pc != 0x18D3C8u) { return; }
    ctx->pc = 0x18D3C8u;
label_18d3c8:
    // 0x18d3c8: 0x8e470030
    ctx->pc = 0x18d3c8u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 18), 48)));
label_18d3cc:
    // 0x18d3cc: 0x30020001
    ctx->pc = 0x18d3ccu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 0), 1));
label_18d3d0:
    // 0x18d3d0: 0x3c09002a
    ctx->pc = 0x18d3d0u;
    SET_GPR_U32(ctx, 9, ((uint32_t)42 << 16));
label_18d3d4:
    // 0x18d3d4: 0x2404ffbf
    ctx->pc = 0x18d3d4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4294967231));
label_18d3d8:
    // 0x18d3d8: 0x2529fd74
    ctx->pc = 0x18d3d8u;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 9), 4294966644));
label_18d3dc:
    // 0x18d3dc: 0x23180
    ctx->pc = 0x18d3dcu;
    SET_GPR_U32(ctx, 6, SLL32(GPR_U32(ctx, 2), 6));
label_18d3e0:
    // 0x18d3e0: 0x219c0
    ctx->pc = 0x18d3e0u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 7));
label_18d3e4:
    // 0x18d3e4: 0x2402ff7f
    ctx->pc = 0x18d3e4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967167));
label_18d3e8:
    // 0x18d3e8: 0x34e70001
    ctx->pc = 0x18d3e8u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 7), 1));
label_18d3ec:
    // 0x18d3ec: 0xae470030
    ctx->pc = 0x18d3ecu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 48), GPR_U32(ctx, 7));
label_18d3f0:
    // 0x18d3f0: 0x8e470000
    ctx->pc = 0x18d3f0u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_18d3f4:
    // 0x18d3f4: 0x73880
    ctx->pc = 0x18d3f4u;
    SET_GPR_U32(ctx, 7, SLL32(GPR_U32(ctx, 7), 2));
label_18d3f8:
    // 0x18d3f8: 0x1273821
    ctx->pc = 0x18d3f8u;
    SET_GPR_U32(ctx, 7, ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 7)));
label_18d3fc:
    // 0x18d3fc: 0x8ce80000
    ctx->pc = 0x18d3fcu;
    SET_GPR_U32(ctx, 8, READ32(ADD32(GPR_U32(ctx, 7), 0)));
label_18d400:
    // 0x18d400: 0x91070000
    ctx->pc = 0x18d400u;
    SET_GPR_U32(ctx, 7, (uint8_t)READ8(ADD32(GPR_U32(ctx, 8), 0)));
label_18d404:
    // 0x18d404: 0xe42024
    ctx->pc = 0x18d404u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 7), GPR_U32(ctx, 4)));
label_18d408:
    // 0x18d408: 0x862025
    ctx->pc = 0x18d408u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 6)));
label_18d40c:
    // 0x18d40c: 0xa1040000
    ctx->pc = 0x18d40cu;
    WRITE8(ADD32(GPR_U32(ctx, 8), 0), (uint8_t)GPR_U32(ctx, 4));
label_18d410:
    // 0x18d410: 0x8e440000
    ctx->pc = 0x18d410u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_18d414:
    // 0x18d414: 0x42080
    ctx->pc = 0x18d414u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 2));
label_18d418:
    // 0x18d418: 0x1242021
    ctx->pc = 0x18d418u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 4)));
label_18d41c:
    // 0x18d41c: 0x8c860000
    ctx->pc = 0x18d41cu;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_18d420:
    // 0x18d420: 0x90c40000
    ctx->pc = 0x18d420u;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
label_18d424:
    // 0x18d424: 0x821024
    ctx->pc = 0x18d424u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
label_18d428:
    // 0x18d428: 0x431025
    ctx->pc = 0x18d428u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_18d42c:
    // 0x18d42c: 0xa0c20000
    ctx->pc = 0x18d42cu;
    WRITE8(ADD32(GPR_U32(ctx, 6), 0), (uint8_t)GPR_U32(ctx, 2));
label_18d430:
    // 0x18d430: 0x8e420000
    ctx->pc = 0x18d430u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_18d434:
    // 0x18d434: 0x21080
    ctx->pc = 0x18d434u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 2));
label_18d438:
    // 0x18d438: 0x1221021
    ctx->pc = 0x18d438u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 9), GPR_U32(ctx, 2)));
label_18d43c:
    // 0x18d43c: 0x8c440000
    ctx->pc = 0x18d43cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_18d440:
    // 0x18d440: 0xc040ce4
label_18d444:
    if (ctx->pc == 0x18D444u) {
        ctx->pc = 0x18D444u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x18D448u;
        goto label_18d448;
    }
    ctx->pc = 0x18D440u;
    SET_GPR_U32(ctx, 31, 0x18D448u);
    ctx->pc = 0x18D444u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x103390u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00103390_0x103390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x18D448u; }
    }
    if (ctx->pc != 0x18D448u) { return; }
    ctx->pc = 0x18D448u;
label_18d448:
    // 0x18d448: 0xf
    ctx->pc = 0x18d448u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
label_18d44c:
    // 0x18d44c: 0x42000038
    ctx->pc = 0x18d44cu;
    ctx->cop0_status |= 0x10000; // Enable interrupts
label_18d450:
    // 0x18d450: 0xdfbf0030
    ctx->pc = 0x18d450u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_18d454:
    // 0x18d454: 0x102d
    ctx->pc = 0x18d454u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_18d458:
    // 0x18d458: 0x7bb20020
    ctx->pc = 0x18d458u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
label_18d45c:
    // 0x18d45c: 0x7bb10010
    ctx->pc = 0x18d45cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
label_18d460:
    // 0x18d460: 0x7bb00000
    ctx->pc = 0x18d460u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
label_18d464:
    // 0x18d464: 0x3e00008
label_18d468:
    if (ctx->pc == 0x18D468u) {
        ctx->pc = 0x18D468u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = 0x18D46Cu;
        goto label_18d46c;
    }
    ctx->pc = 0x18D464u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x18D468u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x18CFB0u: goto label_18cfb0;
            case 0x18CFB4u: goto label_18cfb4;
            case 0x18CFB8u: goto label_18cfb8;
            case 0x18CFBCu: goto label_18cfbc;
            case 0x18CFC0u: goto label_18cfc0;
            case 0x18CFC4u: goto label_18cfc4;
            case 0x18CFC8u: goto label_18cfc8;
            case 0x18CFCCu: goto label_18cfcc;
            case 0x18CFD0u: goto label_18cfd0;
            case 0x18CFD4u: goto label_18cfd4;
            case 0x18CFD8u: goto label_18cfd8;
            case 0x18CFDCu: goto label_18cfdc;
            case 0x18CFE0u: goto label_18cfe0;
            case 0x18CFE4u: goto label_18cfe4;
            case 0x18CFE8u: goto label_18cfe8;
            case 0x18CFECu: goto label_18cfec;
            case 0x18CFF0u: goto label_18cff0;
            case 0x18CFF4u: goto label_18cff4;
            case 0x18CFF8u: goto label_18cff8;
            case 0x18CFFCu: goto label_18cffc;
            case 0x18D000u: goto label_18d000;
            case 0x18D004u: goto label_18d004;
            case 0x18D008u: goto label_18d008;
            case 0x18D00Cu: goto label_18d00c;
            case 0x18D010u: goto label_18d010;
            case 0x18D014u: goto label_18d014;
            case 0x18D018u: goto label_18d018;
            case 0x18D01Cu: goto label_18d01c;
            case 0x18D020u: goto label_18d020;
            case 0x18D024u: goto label_18d024;
            case 0x18D028u: goto label_18d028;
            case 0x18D02Cu: goto label_18d02c;
            case 0x18D030u: goto label_18d030;
            case 0x18D034u: goto label_18d034;
            case 0x18D038u: goto label_18d038;
            case 0x18D03Cu: goto label_18d03c;
            case 0x18D040u: goto label_18d040;
            case 0x18D044u: goto label_18d044;
            case 0x18D048u: goto label_18d048;
            case 0x18D04Cu: goto label_18d04c;
            case 0x18D050u: goto label_18d050;
            case 0x18D054u: goto label_18d054;
            case 0x18D058u: goto label_18d058;
            case 0x18D05Cu: goto label_18d05c;
            case 0x18D060u: goto label_18d060;
            case 0x18D064u: goto label_18d064;
            case 0x18D068u: goto label_18d068;
            case 0x18D06Cu: goto label_18d06c;
            case 0x18D070u: goto label_18d070;
            case 0x18D074u: goto label_18d074;
            case 0x18D078u: goto label_18d078;
            case 0x18D07Cu: goto label_18d07c;
            case 0x18D080u: goto label_18d080;
            case 0x18D084u: goto label_18d084;
            case 0x18D088u: goto label_18d088;
            case 0x18D08Cu: goto label_18d08c;
            case 0x18D090u: goto label_18d090;
            case 0x18D094u: goto label_18d094;
            case 0x18D098u: goto label_18d098;
            case 0x18D09Cu: goto label_18d09c;
            case 0x18D0A0u: goto label_18d0a0;
            case 0x18D0A4u: goto label_18d0a4;
            case 0x18D0A8u: goto label_18d0a8;
            case 0x18D0ACu: goto label_18d0ac;
            case 0x18D0B0u: goto label_18d0b0;
            case 0x18D0B4u: goto label_18d0b4;
            case 0x18D0B8u: goto label_18d0b8;
            case 0x18D0BCu: goto label_18d0bc;
            case 0x18D0C0u: goto label_18d0c0;
            case 0x18D0C4u: goto label_18d0c4;
            case 0x18D0C8u: goto label_18d0c8;
            case 0x18D0CCu: goto label_18d0cc;
            case 0x18D0D0u: goto label_18d0d0;
            case 0x18D0D4u: goto label_18d0d4;
            case 0x18D0D8u: goto label_18d0d8;
            case 0x18D0DCu: goto label_18d0dc;
            case 0x18D0E0u: goto label_18d0e0;
            case 0x18D0E4u: goto label_18d0e4;
            case 0x18D0E8u: goto label_18d0e8;
            case 0x18D0ECu: goto label_18d0ec;
            case 0x18D0F0u: goto label_18d0f0;
            case 0x18D0F4u: goto label_18d0f4;
            case 0x18D0F8u: goto label_18d0f8;
            case 0x18D0FCu: goto label_18d0fc;
            case 0x18D100u: goto label_18d100;
            case 0x18D104u: goto label_18d104;
            case 0x18D108u: goto label_18d108;
            case 0x18D10Cu: goto label_18d10c;
            case 0x18D110u: goto label_18d110;
            case 0x18D114u: goto label_18d114;
            case 0x18D118u: goto label_18d118;
            case 0x18D11Cu: goto label_18d11c;
            case 0x18D120u: goto label_18d120;
            case 0x18D124u: goto label_18d124;
            case 0x18D128u: goto label_18d128;
            case 0x18D12Cu: goto label_18d12c;
            case 0x18D130u: goto label_18d130;
            case 0x18D134u: goto label_18d134;
            case 0x18D138u: goto label_18d138;
            case 0x18D13Cu: goto label_18d13c;
            case 0x18D140u: goto label_18d140;
            case 0x18D144u: goto label_18d144;
            case 0x18D148u: goto label_18d148;
            case 0x18D14Cu: goto label_18d14c;
            case 0x18D150u: goto label_18d150;
            case 0x18D154u: goto label_18d154;
            case 0x18D158u: goto label_18d158;
            case 0x18D15Cu: goto label_18d15c;
            case 0x18D160u: goto label_18d160;
            case 0x18D164u: goto label_18d164;
            case 0x18D168u: goto label_18d168;
            case 0x18D16Cu: goto label_18d16c;
            case 0x18D170u: goto label_18d170;
            case 0x18D174u: goto label_18d174;
            case 0x18D178u: goto label_18d178;
            case 0x18D17Cu: goto label_18d17c;
            case 0x18D180u: goto label_18d180;
            case 0x18D184u: goto label_18d184;
            case 0x18D188u: goto label_18d188;
            case 0x18D18Cu: goto label_18d18c;
            case 0x18D190u: goto label_18d190;
            case 0x18D194u: goto label_18d194;
            case 0x18D198u: goto label_18d198;
            case 0x18D19Cu: goto label_18d19c;
            case 0x18D1A0u: goto label_18d1a0;
            case 0x18D1A4u: goto label_18d1a4;
            case 0x18D1A8u: goto label_18d1a8;
            case 0x18D1ACu: goto label_18d1ac;
            case 0x18D1B0u: goto label_18d1b0;
            case 0x18D1B4u: goto label_18d1b4;
            case 0x18D1B8u: goto label_18d1b8;
            case 0x18D1BCu: goto label_18d1bc;
            case 0x18D1C0u: goto label_18d1c0;
            case 0x18D1C4u: goto label_18d1c4;
            case 0x18D1C8u: goto label_18d1c8;
            case 0x18D1CCu: goto label_18d1cc;
            case 0x18D1D0u: goto label_18d1d0;
            case 0x18D1D4u: goto label_18d1d4;
            case 0x18D1D8u: goto label_18d1d8;
            case 0x18D1DCu: goto label_18d1dc;
            case 0x18D1E0u: goto label_18d1e0;
            case 0x18D1E4u: goto label_18d1e4;
            case 0x18D1E8u: goto label_18d1e8;
            case 0x18D1ECu: goto label_18d1ec;
            case 0x18D1F0u: goto label_18d1f0;
            case 0x18D1F4u: goto label_18d1f4;
            case 0x18D1F8u: goto label_18d1f8;
            case 0x18D1FCu: goto label_18d1fc;
            case 0x18D200u: goto label_18d200;
            case 0x18D204u: goto label_18d204;
            case 0x18D208u: goto label_18d208;
            case 0x18D20Cu: goto label_18d20c;
            case 0x18D210u: goto label_18d210;
            case 0x18D214u: goto label_18d214;
            case 0x18D218u: goto label_18d218;
            case 0x18D21Cu: goto label_18d21c;
            case 0x18D220u: goto label_18d220;
            case 0x18D224u: goto label_18d224;
            case 0x18D228u: goto label_18d228;
            case 0x18D22Cu: goto label_18d22c;
            case 0x18D230u: goto label_18d230;
            case 0x18D234u: goto label_18d234;
            case 0x18D238u: goto label_18d238;
            case 0x18D23Cu: goto label_18d23c;
            case 0x18D240u: goto label_18d240;
            case 0x18D244u: goto label_18d244;
            case 0x18D248u: goto label_18d248;
            case 0x18D24Cu: goto label_18d24c;
            case 0x18D250u: goto label_18d250;
            case 0x18D254u: goto label_18d254;
            case 0x18D258u: goto label_18d258;
            case 0x18D25Cu: goto label_18d25c;
            case 0x18D260u: goto label_18d260;
            case 0x18D264u: goto label_18d264;
            case 0x18D268u: goto label_18d268;
            case 0x18D26Cu: goto label_18d26c;
            case 0x18D270u: goto label_18d270;
            case 0x18D274u: goto label_18d274;
            case 0x18D278u: goto label_18d278;
            case 0x18D27Cu: goto label_18d27c;
            case 0x18D280u: goto label_18d280;
            case 0x18D284u: goto label_18d284;
            case 0x18D288u: goto label_18d288;
            case 0x18D28Cu: goto label_18d28c;
            case 0x18D290u: goto label_18d290;
            case 0x18D294u: goto label_18d294;
            case 0x18D298u: goto label_18d298;
            case 0x18D29Cu: goto label_18d29c;
            case 0x18D2A0u: goto label_18d2a0;
            case 0x18D2A4u: goto label_18d2a4;
            case 0x18D2A8u: goto label_18d2a8;
            case 0x18D2ACu: goto label_18d2ac;
            case 0x18D2B0u: goto label_18d2b0;
            case 0x18D2B4u: goto label_18d2b4;
            case 0x18D2B8u: goto label_18d2b8;
            case 0x18D2BCu: goto label_18d2bc;
            case 0x18D2C0u: goto label_18d2c0;
            case 0x18D2C4u: goto label_18d2c4;
            case 0x18D2C8u: goto label_18d2c8;
            case 0x18D2CCu: goto label_18d2cc;
            case 0x18D2D0u: goto label_18d2d0;
            case 0x18D2D4u: goto label_18d2d4;
            case 0x18D2D8u: goto label_18d2d8;
            case 0x18D2DCu: goto label_18d2dc;
            case 0x18D2E0u: goto label_18d2e0;
            case 0x18D2E4u: goto label_18d2e4;
            case 0x18D2E8u: goto label_18d2e8;
            case 0x18D2ECu: goto label_18d2ec;
            case 0x18D2F0u: goto label_18d2f0;
            case 0x18D2F4u: goto label_18d2f4;
            case 0x18D2F8u: goto label_18d2f8;
            case 0x18D2FCu: goto label_18d2fc;
            case 0x18D300u: goto label_18d300;
            case 0x18D304u: goto label_18d304;
            case 0x18D308u: goto label_18d308;
            case 0x18D30Cu: goto label_18d30c;
            case 0x18D310u: goto label_18d310;
            case 0x18D314u: goto label_18d314;
            case 0x18D318u: goto label_18d318;
            case 0x18D31Cu: goto label_18d31c;
            case 0x18D320u: goto label_18d320;
            case 0x18D324u: goto label_18d324;
            case 0x18D328u: goto label_18d328;
            case 0x18D32Cu: goto label_18d32c;
            case 0x18D330u: goto label_18d330;
            case 0x18D334u: goto label_18d334;
            case 0x18D338u: goto label_18d338;
            case 0x18D33Cu: goto label_18d33c;
            case 0x18D340u: goto label_18d340;
            case 0x18D344u: goto label_18d344;
            case 0x18D348u: goto label_18d348;
            case 0x18D34Cu: goto label_18d34c;
            case 0x18D350u: goto label_18d350;
            case 0x18D354u: goto label_18d354;
            case 0x18D358u: goto label_18d358;
            case 0x18D35Cu: goto label_18d35c;
            case 0x18D360u: goto label_18d360;
            case 0x18D364u: goto label_18d364;
            case 0x18D368u: goto label_18d368;
            case 0x18D36Cu: goto label_18d36c;
            case 0x18D370u: goto label_18d370;
            case 0x18D374u: goto label_18d374;
            case 0x18D378u: goto label_18d378;
            case 0x18D37Cu: goto label_18d37c;
            case 0x18D380u: goto label_18d380;
            case 0x18D384u: goto label_18d384;
            case 0x18D388u: goto label_18d388;
            case 0x18D38Cu: goto label_18d38c;
            case 0x18D390u: goto label_18d390;
            case 0x18D394u: goto label_18d394;
            case 0x18D398u: goto label_18d398;
            case 0x18D39Cu: goto label_18d39c;
            case 0x18D3A0u: goto label_18d3a0;
            case 0x18D3A4u: goto label_18d3a4;
            case 0x18D3A8u: goto label_18d3a8;
            case 0x18D3ACu: goto label_18d3ac;
            case 0x18D3B0u: goto label_18d3b0;
            case 0x18D3B4u: goto label_18d3b4;
            case 0x18D3B8u: goto label_18d3b8;
            case 0x18D3BCu: goto label_18d3bc;
            case 0x18D3C0u: goto label_18d3c0;
            case 0x18D3C4u: goto label_18d3c4;
            case 0x18D3C8u: goto label_18d3c8;
            case 0x18D3CCu: goto label_18d3cc;
            case 0x18D3D0u: goto label_18d3d0;
            case 0x18D3D4u: goto label_18d3d4;
            case 0x18D3D8u: goto label_18d3d8;
            case 0x18D3DCu: goto label_18d3dc;
            case 0x18D3E0u: goto label_18d3e0;
            case 0x18D3E4u: goto label_18d3e4;
            case 0x18D3E8u: goto label_18d3e8;
            case 0x18D3ECu: goto label_18d3ec;
            case 0x18D3F0u: goto label_18d3f0;
            case 0x18D3F4u: goto label_18d3f4;
            case 0x18D3F8u: goto label_18d3f8;
            case 0x18D3FCu: goto label_18d3fc;
            case 0x18D400u: goto label_18d400;
            case 0x18D404u: goto label_18d404;
            case 0x18D408u: goto label_18d408;
            case 0x18D40Cu: goto label_18d40c;
            case 0x18D410u: goto label_18d410;
            case 0x18D414u: goto label_18d414;
            case 0x18D418u: goto label_18d418;
            case 0x18D41Cu: goto label_18d41c;
            case 0x18D420u: goto label_18d420;
            case 0x18D424u: goto label_18d424;
            case 0x18D428u: goto label_18d428;
            case 0x18D42Cu: goto label_18d42c;
            case 0x18D430u: goto label_18d430;
            case 0x18D434u: goto label_18d434;
            case 0x18D438u: goto label_18d438;
            case 0x18D43Cu: goto label_18d43c;
            case 0x18D440u: goto label_18d440;
            case 0x18D444u: goto label_18d444;
            case 0x18D448u: goto label_18d448;
            case 0x18D44Cu: goto label_18d44c;
            case 0x18D450u: goto label_18d450;
            case 0x18D454u: goto label_18d454;
            case 0x18D458u: goto label_18d458;
            case 0x18D45Cu: goto label_18d45c;
            case 0x18D460u: goto label_18d460;
            case 0x18D464u: goto label_18d464;
            case 0x18D468u: goto label_18d468;
            case 0x18D46Cu: goto label_18d46c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x18D46Cu;
label_18d46c:
    // 0x18d46c: 0x0
    ctx->pc = 0x18d46cu;
    // NOP
}
