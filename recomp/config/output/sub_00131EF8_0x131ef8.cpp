#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00131EF8
// Address: 0x131ef8 - 0x132028
void sub_00131EF8_0x131ef8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x131ef8u;

    // 0x131ef8: 0x27bdfff0
    ctx->pc = 0x131ef8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x131efc: 0x14800006
    ctx->pc = 0x131EFCu;
    {
        const bool branch_taken_0x131efc = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x131F00u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        if (branch_taken_0x131efc) {
            ctx->pc = 0x131F18u;
            goto label_131f18;
        }
    }
    ctx->pc = 0x131F04u;
    // 0x131f04: 0x3c040024
    ctx->pc = 0x131f04u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
    // 0x131f08: 0xc04a034
    ctx->pc = 0x131F08u;
    SET_GPR_U32(ctx, 31, 0x131F10u);
    ctx->pc = 0x131F0Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294946632));
    ctx->pc = 0x1280D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001280D0_0x1280d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131F10u; }
    }
    if (ctx->pc != 0x131F10u) { return; }
    ctx->pc = 0x131F10u;
    // 0x131f10: 0x10000002
    ctx->pc = 0x131F10u;
    {
        const bool branch_taken_0x131f10 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x131F14u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x131f10) {
            ctx->pc = 0x131F1Cu;
            goto label_131f1c;
        }
    }
    ctx->pc = 0x131F18u;
label_131f18:
    // 0x131f18: 0x80820001
    ctx->pc = 0x131f18u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 1)));
label_131f1c:
    // 0x131f1c: 0xdfbf0000
    ctx->pc = 0x131f1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x131f20: 0x3e00008
    ctx->pc = 0x131F20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x131F24u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x131F18u: goto label_131f18;
            case 0x131F1Cu: goto label_131f1c;
            case 0x131F40u: goto label_131f40;
            case 0x131F50u: goto label_131f50;
            case 0x131F58u: goto label_131f58;
            case 0x131FA8u: goto label_131fa8;
            case 0x131FE4u: goto label_131fe4;
            case 0x131FF8u: goto label_131ff8;
            case 0x132000u: goto label_132000;
            case 0x132004u: goto label_132004;
            default: break;
        }
        return;
    }
    ctx->pc = 0x131F28u;
    // 0x131f28: 0x24020001
    ctx->pc = 0x131f28u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x131f2c: 0x54820004
    ctx->pc = 0x131F2Cu;
    {
        const bool branch_taken_0x131f2c = (GPR_U32(ctx, 4) != GPR_U32(ctx, 2));
        if (branch_taken_0x131f2c) {
            ctx->pc = 0x131F30u;
            SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
            ctx->pc = 0x131F40u;
            goto label_131f40;
        }
    }
    ctx->pc = 0x131F34u;
    // 0x131f34: 0x3c030022
    ctx->pc = 0x131f34u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x131f38: 0x10000005
    ctx->pc = 0x131F38u;
    {
        const bool branch_taken_0x131f38 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x131F3Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 5994));
        if (branch_taken_0x131f38) {
            ctx->pc = 0x131F50u;
            goto label_131f50;
        }
    }
    ctx->pc = 0x131F40u;
label_131f40:
    // 0x131f40: 0x54820005
    ctx->pc = 0x131F40u;
    {
        const bool branch_taken_0x131f40 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 2));
        if (branch_taken_0x131f40) {
            ctx->pc = 0x131F44u;
            SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
            ctx->pc = 0x131F58u;
            goto label_131f58;
        }
    }
    ctx->pc = 0x131F48u;
    // 0x131f48: 0x3c030022
    ctx->pc = 0x131f48u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x131f4c: 0x24021388
    ctx->pc = 0x131f4cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 5000));
label_131f50:
    // 0x131f50: 0xac62b788
    ctx->pc = 0x131f50u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 4294948744), GPR_U32(ctx, 2));
    // 0x131f54: 0x3c020022
    ctx->pc = 0x131f54u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
label_131f58:
    // 0x131f58: 0x3e00008
    ctx->pc = 0x131F58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x131F5Cu;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294948688), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x131F18u: goto label_131f18;
            case 0x131F1Cu: goto label_131f1c;
            case 0x131F40u: goto label_131f40;
            case 0x131F50u: goto label_131f50;
            case 0x131F58u: goto label_131f58;
            case 0x131FA8u: goto label_131fa8;
            case 0x131FE4u: goto label_131fe4;
            case 0x131FF8u: goto label_131ff8;
            case 0x132000u: goto label_132000;
            case 0x132004u: goto label_132004;
            default: break;
        }
        return;
    }
    ctx->pc = 0x131F60u;
    // 0x131f60: 0x27bdffe0
    ctx->pc = 0x131f60u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x131f64: 0xffb00000
    ctx->pc = 0x131f64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x131f68: 0x80802d
    ctx->pc = 0x131f68u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131f6c: 0xffb10008
    ctx->pc = 0x131f6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x131f70: 0xa0882d
    ctx->pc = 0x131f70u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131f74: 0xffb20010
    ctx->pc = 0x131f74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x131f78: 0xc0902d
    ctx->pc = 0x131f78u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x131f7c: 0xffbf0018
    ctx->pc = 0x131f7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x131f80: 0x92020001
    ctx->pc = 0x131f80u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 1)));
    // 0x131f84: 0x21e00
    ctx->pc = 0x131f84u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 24));
    // 0x131f88: 0x2442fffd
    ctx->pc = 0x131f88u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967293));
    // 0x131f8c: 0x2c420002
    ctx->pc = 0x131f8cu;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 2), 2));
    // 0x131f90: 0x10400005
    ctx->pc = 0x131F90u;
    {
        const bool branch_taken_0x131f90 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x131F94u;
        SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 24));
        if (branch_taken_0x131f90) {
            ctx->pc = 0x131FA8u;
            goto label_131fa8;
        }
    }
    ctx->pc = 0x131F98u;
    // 0x131f98: 0xc04b1c6
    ctx->pc = 0x131F98u;
    SET_GPR_U32(ctx, 31, 0x131FA0u);
    ctx->pc = 0x131F9Cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 12)));
    ctx->pc = 0x12C718u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012C718_0x12c718(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131FA0u; }
    }
    if (ctx->pc != 0x131FA0u) { return; }
    ctx->pc = 0x131FA0u;
    // 0x131fa0: 0x10000018
    ctx->pc = 0x131FA0u;
    {
        const bool branch_taken_0x131fa0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x131FA4u;
        SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 136)));
        if (branch_taken_0x131fa0) {
            ctx->pc = 0x132004u;
            goto label_132004;
        }
    }
    ctx->pc = 0x131FA8u;
label_131fa8:
    // 0x131fa8: 0x24020005
    ctx->pc = 0x131fa8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 5));
    // 0x131fac: 0x54620012
    ctx->pc = 0x131FACu;
    {
        const bool branch_taken_0x131fac = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        if (branch_taken_0x131fac) {
            ctx->pc = 0x131FB0u;
            SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
            ctx->pc = 0x131FF8u;
            goto label_131ff8;
        }
    }
    ctx->pc = 0x131FB4u;
    // 0x131fb4: 0xc04b602
    ctx->pc = 0x131FB4u;
    SET_GPR_U32(ctx, 31, 0x131FBCu);
    ctx->pc = 0x131FB8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 4)));
    ctx->pc = 0x12D808u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D808_0x12d808(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131FBCu; }
    }
    if (ctx->pc != 0x131FBCu) { return; }
    ctx->pc = 0x131FBCu;
    // 0x131fbc: 0x8e040004
    ctx->pc = 0x131fbcu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x131fc0: 0xc04b5e4
    ctx->pc = 0x131FC0u;
    SET_GPR_U32(ctx, 31, 0x131FC8u);
    ctx->pc = 0x131FC4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x12D790u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D790_0x12d790(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131FC8u; }
    }
    if (ctx->pc != 0x131FC8u) { return; }
    ctx->pc = 0x131FC8u;
    // 0x131fc8: 0x8e040004
    ctx->pc = 0x131fc8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x131fcc: 0xc04b5f0
    ctx->pc = 0x131FCCu;
    SET_GPR_U32(ctx, 31, 0x131FD4u);
    ctx->pc = 0x131FD0u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x12D7C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012D7C0_0x12d7c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x131FD4u; }
    }
    if (ctx->pc != 0x131FD4u) { return; }
    ctx->pc = 0x131FD4u;
    // 0x131fd4: 0x24030010
    ctx->pc = 0x131fd4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 16));
    // 0x131fd8: 0x62001a
    ctx->pc = 0x131fd8u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint32_t)(dividend / divisor);            ctx->hi = (uint32_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1 : -1; ctx->hi = dividend;    } }
    // 0x131fdc: 0x50400001
    ctx->pc = 0x131FDCu;
    {
        const bool branch_taken_0x131fdc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x131fdc) {
            ctx->pc = 0x131FE0u;
            runtime->handleBreak(rdram, ctx);
            ctx->pc = 0x131FE4u;
            goto label_131fe4;
        }
    }
    ctx->pc = 0x131FE4u;
label_131fe4:
    // 0x131fe4: 0x8e220000
    ctx->pc = 0x131fe4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x131fe8: 0x1812
    ctx->pc = 0x131fe8u;
    SET_GPR_U32(ctx, 3, ctx->lo);
    // 0x131fec: 0x431018
    ctx->pc = 0x131fecu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)(uint32_t)result); }
    // 0x131ff0: 0x10000003
    ctx->pc = 0x131FF0u;
    {
        const bool branch_taken_0x131ff0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x131FF4u;
        WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x131ff0) {
            ctx->pc = 0x132000u;
            goto label_132000;
        }
    }
    ctx->pc = 0x131FF8u;
label_131ff8:
    // 0x131ff8: 0xae200000
    ctx->pc = 0x131ff8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x131ffc: 0xae420000
    ctx->pc = 0x131ffcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 2));
label_132000:
    // 0x132000: 0x8e030088
    ctx->pc = 0x132000u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 136)));
label_132004:
    // 0x132004: 0x8e220000
    ctx->pc = 0x132004u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x132008: 0xdfb00000
    ctx->pc = 0x132008u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x13200c: 0x431021
    ctx->pc = 0x13200cu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x132010: 0xdfb20010
    ctx->pc = 0x132010u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x132014: 0xae220000
    ctx->pc = 0x132014u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 2));
    // 0x132018: 0xdfbf0018
    ctx->pc = 0x132018u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x13201c: 0xdfb10008
    ctx->pc = 0x13201cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x132020: 0x3e00008
    ctx->pc = 0x132020u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x132024u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x131F18u: goto label_131f18;
            case 0x131F1Cu: goto label_131f1c;
            case 0x131F40u: goto label_131f40;
            case 0x131F50u: goto label_131f50;
            case 0x131F58u: goto label_131f58;
            case 0x131FA8u: goto label_131fa8;
            case 0x131FE4u: goto label_131fe4;
            case 0x131FF8u: goto label_131ff8;
            case 0x132000u: goto label_132000;
            case 0x132004u: goto label_132004;
            default: break;
        }
        return;
    }
    ctx->pc = 0x132028u;
}
