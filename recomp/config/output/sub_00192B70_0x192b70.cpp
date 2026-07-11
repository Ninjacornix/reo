#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00192B70
// Address: 0x192b70 - 0x192c80
void sub_00192B70_0x192b70(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x192b70u;

    // 0x192b70: 0x30a3ffff
    ctx->pc = 0x192b70u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 5), 65535));
    // 0x192b74: 0x80282d
    ctx->pc = 0x192b74u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_192b78:
    // 0x192b78: 0x948200c6
    ctx->pc = 0x192b78u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 198)));
    // 0x192b7c: 0x14430008
    ctx->pc = 0x192B7Cu;
    {
        const bool branch_taken_0x192b7c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        if (branch_taken_0x192b7c) {
            ctx->pc = 0x192BA0u;
            goto label_192ba0;
        }
    }
    ctx->pc = 0x192B84u;
    // 0x192b84: 0xac8000d4
    ctx->pc = 0x192b84u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 212), GPR_U32(ctx, 0));
    // 0x192b88: 0xac8000d8
    ctx->pc = 0x192b88u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 216), GPR_U32(ctx, 0));
    // 0x192b8c: 0x8c8200d0
    ctx->pc = 0x192b8cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 208)));
    // 0x192b90: 0x10400003
    ctx->pc = 0x192B90u;
    {
        const bool branch_taken_0x192b90 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x192b90) {
            ctx->pc = 0x192BA0u;
            goto label_192ba0;
        }
    }
    ctx->pc = 0x192B98u;
    // 0x192b98: 0x1000fff7
    ctx->pc = 0x192B98u;
    {
        const bool branch_taken_0x192b98 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x192B9Cu;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x192b98) {
            ctx->pc = 0x192B78u;
            goto label_192b78;
        }
    }
    ctx->pc = 0x192BA0u;
label_192ba0:
    // 0x192ba0: 0x8c8200cc
    ctx->pc = 0x192ba0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 204)));
    // 0x192ba4: 0x1040000d
    ctx->pc = 0x192BA4u;
    {
        const bool branch_taken_0x192ba4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x192ba4) {
            ctx->pc = 0x192BDCu;
            goto label_192bdc;
        }
    }
    ctx->pc = 0x192BACu;
    // 0x192bac: 0x1085000b
    ctx->pc = 0x192BACu;
    {
        const bool branch_taken_0x192bac = (GPR_U32(ctx, 4) == GPR_U32(ctx, 5));
        if (branch_taken_0x192bac) {
            ctx->pc = 0x192BDCu;
            goto label_192bdc;
        }
    }
    ctx->pc = 0x192BB4u;
    // 0x192bb4: 0x1000fff0
    ctx->pc = 0x192BB4u;
    {
        const bool branch_taken_0x192bb4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x192BB8u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x192bb4) {
            ctx->pc = 0x192B78u;
            goto label_192b78;
        }
    }
    ctx->pc = 0x192BBCu;
label_192bbc:
    // 0x192bbc: 0x8c8200cc
    ctx->pc = 0x192bbcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 204)));
    // 0x192bc0: 0x10400005
    ctx->pc = 0x192BC0u;
    {
        const bool branch_taken_0x192bc0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x192bc0) {
            ctx->pc = 0x192BD8u;
            goto label_192bd8;
        }
    }
    ctx->pc = 0x192BC8u;
    // 0x192bc8: 0x40202d
    ctx->pc = 0x192bc8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192bcc: 0x944200c6
    ctx->pc = 0x192bccu;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 198)));
    // 0x192bd0: 0x1043ffe9
    ctx->pc = 0x192BD0u;
    {
        const bool branch_taken_0x192bd0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 3));
        if (branch_taken_0x192bd0) {
            ctx->pc = 0x192B78u;
            goto label_192b78;
        }
    }
    ctx->pc = 0x192BD8u;
label_192bd8:
    // 0x192bd8: 0x8c8400c8
    ctx->pc = 0x192bd8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 200)));
label_192bdc:
    // 0x192bdc: 0x1485fff7
    ctx->pc = 0x192BDCu;
    {
        const bool branch_taken_0x192bdc = (GPR_U32(ctx, 4) != GPR_U32(ctx, 5));
        if (branch_taken_0x192bdc) {
            ctx->pc = 0x192BBCu;
            goto label_192bbc;
        }
    }
    ctx->pc = 0x192BE4u;
    // 0x192be4: 0x24020001
    ctx->pc = 0x192be4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x192be8: 0x3e00008
    ctx->pc = 0x192BE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192B78u: goto label_192b78;
            case 0x192BA0u: goto label_192ba0;
            case 0x192BBCu: goto label_192bbc;
            case 0x192BD8u: goto label_192bd8;
            case 0x192BDCu: goto label_192bdc;
            case 0x192C58u: goto label_192c58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192BF0u;
    // 0x192bf0: 0x27bdffc0
    ctx->pc = 0x192bf0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x192bf4: 0xffbf0030
    ctx->pc = 0x192bf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x192bf8: 0x7fb20020
    ctx->pc = 0x192bf8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x192bfc: 0x7fb10010
    ctx->pc = 0x192bfcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x192c00: 0x80902d
    ctx->pc = 0x192c00u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192c04: 0x7fb00000
    ctx->pc = 0x192c04u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x192c08: 0xc0882d
    ctx->pc = 0x192c08u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192c0c: 0xa0802d
    ctx->pc = 0x192c0cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192c10: 0xc063728
    ctx->pc = 0x192C10u;
    SET_GPR_U32(ctx, 31, 0x192C18u);
    ctx->pc = 0x192C14u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x18DCA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DCA0_0x18dca0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192C18u; }
    }
    if (ctx->pc != 0x192C18u) { return; }
    ctx->pc = 0x192C18u;
    // 0x192c18: 0x3c010029
    ctx->pc = 0x192c18u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x192c1c: 0x240202d
    ctx->pc = 0x192c1cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192c20: 0xac224168
    ctx->pc = 0x192c20u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 16744), GPR_U32(ctx, 2));
    // 0x192c24: 0x220282d
    ctx->pc = 0x192c24u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192c28: 0x8c430010
    ctx->pc = 0x192c28u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x192c2c: 0x3c010029
    ctx->pc = 0x192c2cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x192c30: 0x8c224168
    ctx->pc = 0x192c30u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 16744)));
    // 0x192c34: 0x3c010023
    ctx->pc = 0x192c34u;
    SET_GPR_U32(ctx, 1, ((uint32_t)35 << 16));
    // 0x192c38: 0x0
    ctx->pc = 0x192c38u;
    // NOP
    // 0x192c3c: 0xc064b44
    ctx->pc = 0x192C3Cu;
    SET_GPR_U32(ctx, 31, 0x192C44u);
    ctx->pc = 0x192C40u;
    SET_GPR_U32(ctx, 16, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    ctx->pc = 0x192D10u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00192D10_0x192d10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192C44u; }
    }
    if (ctx->pc != 0x192C44u) { return; }
    ctx->pc = 0x192C44u;
    // 0x192c44: 0x10400004
    ctx->pc = 0x192C44u;
    {
        const bool branch_taken_0x192c44 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x192C48u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x192c44) {
            ctx->pc = 0x192C58u;
            goto label_192c58;
        }
    }
    ctx->pc = 0x192C4Cu;
    // 0x192c4c: 0x200282d
    ctx->pc = 0x192c4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x192c50: 0xc064b20
    ctx->pc = 0x192C50u;
    SET_GPR_U32(ctx, 31, 0x192C58u);
    ctx->pc = 0x192C54u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x192C80u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00192C80_0x192c80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x192C58u; }
    }
    if (ctx->pc != 0x192C58u) { return; }
    ctx->pc = 0x192C58u;
label_192c58:
    // 0x192c58: 0xdfbf0030
    ctx->pc = 0x192c58u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x192c5c: 0x24020001
    ctx->pc = 0x192c5cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x192c60: 0x7bb20020
    ctx->pc = 0x192c60u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x192c64: 0x7bb10010
    ctx->pc = 0x192c64u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x192c68: 0x7bb00000
    ctx->pc = 0x192c68u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x192c6c: 0x3e00008
    ctx->pc = 0x192C6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x192C70u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x192B78u: goto label_192b78;
            case 0x192BA0u: goto label_192ba0;
            case 0x192BBCu: goto label_192bbc;
            case 0x192BD8u: goto label_192bd8;
            case 0x192BDCu: goto label_192bdc;
            case 0x192C58u: goto label_192c58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x192C74u;
    // 0x192c74: 0x0
    ctx->pc = 0x192c74u;
    // NOP
    // 0x192c78: 0x0
    ctx->pc = 0x192c78u;
    // NOP
    // 0x192c7c: 0x0
    ctx->pc = 0x192c7cu;
    // NOP
}
