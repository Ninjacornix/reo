#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00169FF0
// Address: 0x169ff0 - 0x16a110
void sub_00169FF0_0x169ff0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x169ff0u;

    // 0x169ff0: 0x27bdffd0
    ctx->pc = 0x169ff0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x169ff4: 0xffb10008
    ctx->pc = 0x169ff4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x169ff8: 0xa0882d
    ctx->pc = 0x169ff8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x169ffc: 0xffb00000
    ctx->pc = 0x169ffcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x16a000: 0x80802d
    ctx->pc = 0x16a000u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a004: 0xffb20010
    ctx->pc = 0x16a004u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x16a008: 0xc0902d
    ctx->pc = 0x16a008u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a00c: 0xffb30018
    ctx->pc = 0x16a00cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x16a010: 0xe0982d
    ctx->pc = 0x16a010u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a014: 0xffb40020
    ctx->pc = 0x16a014u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x16a018: 0xffbf0028
    ctx->pc = 0x16a018u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x16a01c: 0xc05a78c
    ctx->pc = 0x16A01Cu;
    SET_GPR_U32(ctx, 31, 0x16A024u);
    ctx->pc = 0x16A020u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x169E30u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00169E30_0x169e30(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A024u; }
    }
    if (ctx->pc != 0x16A024u) { return; }
    ctx->pc = 0x16A024u;
    // 0x16a024: 0x3c05ff00
    ctx->pc = 0x16a024u;
    SET_GPR_U32(ctx, 5, ((uint32_t)65280 << 16));
    // 0x16a028: 0x2623ff44
    ctx->pc = 0x16a028u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 17), 4294967108));
    // 0x16a02c: 0x202d
    ctx->pc = 0x16a02cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a030: 0x34a50171
    ctx->pc = 0x16a030u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 369));
    // 0x16a034: 0x1040000a
    ctx->pc = 0x16A034u;
    {
        const bool branch_taken_0x16a034 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x16A038u;
        SET_GPR_U32(ctx, 3, SLTU32(GPR_U32(ctx, 3), 68));
        if (branch_taken_0x16a034) {
            ctx->pc = 0x16A060u;
            goto label_16a060;
        }
    }
    ctx->pc = 0x16A03Cu;
    // 0x16a03c: 0xdfb00000
    ctx->pc = 0x16a03cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x16a040: 0xdfb10008
    ctx->pc = 0x16a040u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16a044: 0xdfb20010
    ctx->pc = 0x16a044u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16a048: 0xdfb30018
    ctx->pc = 0x16a048u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16a04c: 0xdfb40020
    ctx->pc = 0x16a04cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16a050: 0xdfbf0028
    ctx->pc = 0x16a050u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16a054: 0x805a704
    ctx->pc = 0x16A054u;
    ctx->pc = 0x16A058u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
    ctx->pc = 0x169C10u;
    sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    ctx->pc = 0x16A05Cu;
    // 0x16a05c: 0x0
    ctx->pc = 0x16a05cu;
    // NOP
label_16a060:
    // 0x16a060: 0x50600008
    ctx->pc = 0x16A060u;
    {
        const bool branch_taken_0x16a060 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        if (branch_taken_0x16a060) {
            ctx->pc = 0x16A064u;
            SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
            ctx->pc = 0x16A084u;
            goto label_16a084;
        }
    }
    ctx->pc = 0x16A068u;
    // 0x16a068: 0x8e041aec
    ctx->pc = 0x16a068u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 6892)));
    // 0x16a06c: 0x111880
    ctx->pc = 0x16a06cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 17), 2));
    // 0x16a070: 0x641821
    ctx->pc = 0x16a070u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x16a074: 0xac930144
    ctx->pc = 0x16a074u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 324), GPR_U32(ctx, 19));
    // 0x16a078: 0xac72fd44
    ctx->pc = 0x16a078u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294966596), GPR_U32(ctx, 18));
    // 0x16a07c: 0xac940148
    ctx->pc = 0x16a07cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 328), GPR_U32(ctx, 20));
    // 0x16a080: 0xdfb00000
    ctx->pc = 0x16a080u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_16a084:
    // 0x16a084: 0xdfb10008
    ctx->pc = 0x16a084u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x16a088: 0xdfb20010
    ctx->pc = 0x16a088u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x16a08c: 0xdfb30018
    ctx->pc = 0x16a08cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x16a090: 0xdfb40020
    ctx->pc = 0x16a090u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x16a094: 0xdfbf0028
    ctx->pc = 0x16a094u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x16a098: 0x3e00008
    ctx->pc = 0x16A098u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16A09Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16A060u: goto label_16a060;
            case 0x16A084u: goto label_16a084;
            case 0x16A0B8u: goto label_16a0b8;
            case 0x16A0D8u: goto label_16a0d8;
            case 0x16A100u: goto label_16a100;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16A0A0u;
    // 0x16a0a0: 0x27bdfff0
    ctx->pc = 0x16a0a0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x16a0a4: 0xffbf0000
    ctx->pc = 0x16a0a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x16a0a8: 0xc05a844
    ctx->pc = 0x16A0A8u;
    SET_GPR_U32(ctx, 31, 0x16A0B0u);
    ctx->pc = 0x16A110u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0016A110_0x16a110(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A0B0u; }
    }
    if (ctx->pc != 0x16A0B0u) { return; }
    ctx->pc = 0x16A0B0u;
    // 0x16a0b0: 0x10400009
    ctx->pc = 0x16A0B0u;
    {
        const bool branch_taken_0x16a0b0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x16A0B4u;
        SET_GPR_U32(ctx, 5, ((uint32_t)39 << 16));
        if (branch_taken_0x16a0b0) {
            ctx->pc = 0x16A0D8u;
            goto label_16a0d8;
        }
    }
    ctx->pc = 0x16A0B8u;
label_16a0b8:
    // 0x16a0b8: 0x0
    ctx->pc = 0x16a0b8u;
    // NOP
    // 0x16a0bc: 0x0
    ctx->pc = 0x16a0bcu;
    // NOP
    // 0x16a0c0: 0x0
    ctx->pc = 0x16a0c0u;
    // NOP
    // 0x16a0c4: 0x0
    ctx->pc = 0x16a0c4u;
    // NOP
    // 0x16a0c8: 0x0
    ctx->pc = 0x16a0c8u;
    // NOP
    // 0x16a0cc: 0x1000fffa
    ctx->pc = 0x16A0CCu;
    {
        const bool branch_taken_0x16a0cc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x16a0cc) {
            ctx->pc = 0x16A0B8u;
            goto label_16a0b8;
        }
    }
    ctx->pc = 0x16A0D4u;
    // 0x16a0d4: 0x0
    ctx->pc = 0x16a0d4u;
    // NOP
label_16a0d8:
    // 0x16a0d8: 0x24040008
    ctx->pc = 0x16a0d8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 8));
    // 0x16a0dc: 0xc05600c
    ctx->pc = 0x16A0DCu;
    SET_GPR_U32(ctx, 31, 0x16A0E4u);
    ctx->pc = 0x16A0E0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 6680));
    ctx->pc = 0x158030u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00158030_0x158030(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16A0E4u; }
    }
    if (ctx->pc != 0x16A0E4u) { return; }
    ctx->pc = 0x16A0E4u;
    // 0x16a0e4: 0x10400006
    ctx->pc = 0x16A0E4u;
    {
        const bool branch_taken_0x16a0e4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x16A0E8u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x16a0e4) {
            ctx->pc = 0x16A100u;
            goto label_16a100;
        }
    }
    ctx->pc = 0x16A0ECu;
    // 0x16a0ec: 0x3c05ff00
    ctx->pc = 0x16a0ecu;
    SET_GPR_U32(ctx, 5, ((uint32_t)65280 << 16));
    // 0x16a0f0: 0x202d
    ctx->pc = 0x16a0f0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x16a0f4: 0x34a50d01
    ctx->pc = 0x16a0f4u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 3329));
    // 0x16a0f8: 0x805a704
    ctx->pc = 0x16A0F8u;
    ctx->pc = 0x16A0FCu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x169C10u;
    sub_00169C10_0x169c10(rdram, ctx, runtime); return;
    ctx->pc = 0x16A100u;
label_16a100:
    // 0x16a100: 0x3c030023
    ctx->pc = 0x16a100u;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
    // 0x16a104: 0xac60f1b0
    ctx->pc = 0x16a104u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294963632), GPR_U32(ctx, 0));
    // 0x16a108: 0x3e00008
    ctx->pc = 0x16A108u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16A10Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16A060u: goto label_16a060;
            case 0x16A084u: goto label_16a084;
            case 0x16A0B8u: goto label_16a0b8;
            case 0x16A0D8u: goto label_16a0d8;
            case 0x16A100u: goto label_16a100;
            default: break;
        }
        return;
    }
    ctx->pc = 0x16A110u;
}
