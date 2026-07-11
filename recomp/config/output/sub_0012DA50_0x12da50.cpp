#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0012DA50
// Address: 0x12da50 - 0x12dac0
void sub_0012DA50_0x12da50(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x12da50u;

label_12da50:
    // 0x12da50: 0x27bdfff0
    ctx->pc = 0x12da50u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
label_12da54:
    // 0x12da54: 0xffbf0000
    ctx->pc = 0x12da54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
label_12da58:
    // 0x12da58: 0x8c840004
    ctx->pc = 0x12da58u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 4)));
label_12da5c:
    // 0x12da5c: 0xdfbf0000
    ctx->pc = 0x12da5cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_12da60:
    // 0x12da60: 0x80493ec
label_12da64:
    if (ctx->pc == 0x12DA64u) {
        ctx->pc = 0x12DA64u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = 0x12DA68u;
        goto label_12da68;
    }
    ctx->pc = 0x12DA60u;
    ctx->pc = 0x12DA64u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x124FB0u;
    entry_124fb0_0x124ff0(rdram, ctx, runtime); return;
    ctx->pc = 0x12DA68u;
label_12da68:
    // 0x12da68: 0x3e00008
label_12da6c:
    if (ctx->pc == 0x12DA6Cu) {
        ctx->pc = 0x12DA6Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x12DA70u;
        goto label_12da70;
    }
    ctx->pc = 0x12DA68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12DA6Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12DA50u: goto label_12da50;
            case 0x12DA54u: goto label_12da54;
            case 0x12DA58u: goto label_12da58;
            case 0x12DA5Cu: goto label_12da5c;
            case 0x12DA60u: goto label_12da60;
            case 0x12DA64u: goto label_12da64;
            case 0x12DA68u: goto label_12da68;
            case 0x12DA6Cu: goto label_12da6c;
            case 0x12DA70u: goto label_12da70;
            case 0x12DA74u: goto label_12da74;
            case 0x12DA78u: goto label_12da78;
            case 0x12DA7Cu: goto label_12da7c;
            case 0x12DA80u: goto label_12da80;
            case 0x12DA84u: goto label_12da84;
            case 0x12DA88u: goto label_12da88;
            case 0x12DA8Cu: goto label_12da8c;
            case 0x12DA90u: goto label_12da90;
            case 0x12DA94u: goto label_12da94;
            case 0x12DA98u: goto label_12da98;
            case 0x12DA9Cu: goto label_12da9c;
            case 0x12DAA0u: goto label_12daa0;
            case 0x12DAA4u: goto label_12daa4;
            case 0x12DAA8u: goto label_12daa8;
            case 0x12DAACu: goto label_12daac;
            case 0x12DAB0u: goto label_12dab0;
            case 0x12DAB4u: goto label_12dab4;
            case 0x12DAB8u: goto label_12dab8;
            case 0x12DABCu: goto label_12dabc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12DA70u;
label_12da70:
    // 0x12da70: 0x3c020022
    ctx->pc = 0x12da70u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
label_12da74:
    // 0x12da74: 0x3c030022
    ctx->pc = 0x12da74u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
label_12da78:
    // 0x12da78: 0xac44874c
    ctx->pc = 0x12da78u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294936396), GPR_U32(ctx, 4));
label_12da7c:
    // 0x12da7c: 0x102d
    ctx->pc = 0x12da7cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_12da80:
    // 0x12da80: 0x3e00008
label_12da84:
    if (ctx->pc == 0x12DA84u) {
        ctx->pc = 0x12DA84u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294936400), GPR_U32(ctx, 5));
        ctx->pc = 0x12DA88u;
        goto label_12da88;
    }
    ctx->pc = 0x12DA80u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12DA84u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294936400), GPR_U32(ctx, 5));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12DA50u: goto label_12da50;
            case 0x12DA54u: goto label_12da54;
            case 0x12DA58u: goto label_12da58;
            case 0x12DA5Cu: goto label_12da5c;
            case 0x12DA60u: goto label_12da60;
            case 0x12DA64u: goto label_12da64;
            case 0x12DA68u: goto label_12da68;
            case 0x12DA6Cu: goto label_12da6c;
            case 0x12DA70u: goto label_12da70;
            case 0x12DA74u: goto label_12da74;
            case 0x12DA78u: goto label_12da78;
            case 0x12DA7Cu: goto label_12da7c;
            case 0x12DA80u: goto label_12da80;
            case 0x12DA84u: goto label_12da84;
            case 0x12DA88u: goto label_12da88;
            case 0x12DA8Cu: goto label_12da8c;
            case 0x12DA90u: goto label_12da90;
            case 0x12DA94u: goto label_12da94;
            case 0x12DA98u: goto label_12da98;
            case 0x12DA9Cu: goto label_12da9c;
            case 0x12DAA0u: goto label_12daa0;
            case 0x12DAA4u: goto label_12daa4;
            case 0x12DAA8u: goto label_12daa8;
            case 0x12DAACu: goto label_12daac;
            case 0x12DAB0u: goto label_12dab0;
            case 0x12DAB4u: goto label_12dab4;
            case 0x12DAB8u: goto label_12dab8;
            case 0x12DABCu: goto label_12dabc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12DA88u;
label_12da88:
    // 0x12da88: 0x3c020022
    ctx->pc = 0x12da88u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
label_12da8c:
    // 0x12da8c: 0x27bdfff0
    ctx->pc = 0x12da8cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
label_12da90:
    // 0x12da90: 0x8c43874c
    ctx->pc = 0x12da90u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 4294936396)));
label_12da94:
    // 0x12da94: 0x80282d
    ctx->pc = 0x12da94u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_12da98:
    // 0x12da98: 0x10600004
label_12da9c:
    if (ctx->pc == 0x12DA9Cu) {
        ctx->pc = 0x12DA9Cu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->pc = 0x12DAA0u;
        goto label_12daa0;
    }
    ctx->pc = 0x12DA98u;
    {
        const bool branch_taken_0x12da98 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x12DA9Cu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        if (branch_taken_0x12da98) {
            ctx->pc = 0x12DAACu;
            goto label_12daac;
        }
    }
    ctx->pc = 0x12DAA0u;
label_12daa0:
    // 0x12daa0: 0x3c020022
    ctx->pc = 0x12daa0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
label_12daa4:
    // 0x12daa4: 0x60f809
label_12daa8:
    if (ctx->pc == 0x12DAA8u) {
        ctx->pc = 0x12DAA8u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 4294936400)));
        ctx->pc = 0x12DAACu;
        goto label_12daac;
    }
    ctx->pc = 0x12DAA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x12DAACu);
        ctx->pc = 0x12DAA8u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 4294936400)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12DA50u: goto label_12da50;
            case 0x12DA54u: goto label_12da54;
            case 0x12DA58u: goto label_12da58;
            case 0x12DA5Cu: goto label_12da5c;
            case 0x12DA60u: goto label_12da60;
            case 0x12DA64u: goto label_12da64;
            case 0x12DA68u: goto label_12da68;
            case 0x12DA6Cu: goto label_12da6c;
            case 0x12DA70u: goto label_12da70;
            case 0x12DA74u: goto label_12da74;
            case 0x12DA78u: goto label_12da78;
            case 0x12DA7Cu: goto label_12da7c;
            case 0x12DA80u: goto label_12da80;
            case 0x12DA84u: goto label_12da84;
            case 0x12DA88u: goto label_12da88;
            case 0x12DA8Cu: goto label_12da8c;
            case 0x12DA90u: goto label_12da90;
            case 0x12DA94u: goto label_12da94;
            case 0x12DA98u: goto label_12da98;
            case 0x12DA9Cu: goto label_12da9c;
            case 0x12DAA0u: goto label_12daa0;
            case 0x12DAA4u: goto label_12daa4;
            case 0x12DAA8u: goto label_12daa8;
            case 0x12DAACu: goto label_12daac;
            case 0x12DAB0u: goto label_12dab0;
            case 0x12DAB4u: goto label_12dab4;
            case 0x12DAB8u: goto label_12dab8;
            case 0x12DABCu: goto label_12dabc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12DAACu; }
            if (ctx->pc != 0x12DAACu) { return; }
        }
    }
    ctx->pc = 0x12DAACu;
label_12daac:
    // 0x12daac: 0xdfbf0000
    ctx->pc = 0x12daacu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_12dab0:
    // 0x12dab0: 0x102d
    ctx->pc = 0x12dab0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_12dab4:
    // 0x12dab4: 0x3e00008
label_12dab8:
    if (ctx->pc == 0x12DAB8u) {
        ctx->pc = 0x12DAB8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = 0x12DABCu;
        goto label_12dabc;
    }
    ctx->pc = 0x12DAB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12DAB8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12DA50u: goto label_12da50;
            case 0x12DA54u: goto label_12da54;
            case 0x12DA58u: goto label_12da58;
            case 0x12DA5Cu: goto label_12da5c;
            case 0x12DA60u: goto label_12da60;
            case 0x12DA64u: goto label_12da64;
            case 0x12DA68u: goto label_12da68;
            case 0x12DA6Cu: goto label_12da6c;
            case 0x12DA70u: goto label_12da70;
            case 0x12DA74u: goto label_12da74;
            case 0x12DA78u: goto label_12da78;
            case 0x12DA7Cu: goto label_12da7c;
            case 0x12DA80u: goto label_12da80;
            case 0x12DA84u: goto label_12da84;
            case 0x12DA88u: goto label_12da88;
            case 0x12DA8Cu: goto label_12da8c;
            case 0x12DA90u: goto label_12da90;
            case 0x12DA94u: goto label_12da94;
            case 0x12DA98u: goto label_12da98;
            case 0x12DA9Cu: goto label_12da9c;
            case 0x12DAA0u: goto label_12daa0;
            case 0x12DAA4u: goto label_12daa4;
            case 0x12DAA8u: goto label_12daa8;
            case 0x12DAACu: goto label_12daac;
            case 0x12DAB0u: goto label_12dab0;
            case 0x12DAB4u: goto label_12dab4;
            case 0x12DAB8u: goto label_12dab8;
            case 0x12DABCu: goto label_12dabc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12DABCu;
label_12dabc:
    // 0x12dabc: 0x0
    ctx->pc = 0x12dabcu;
    // NOP
}
