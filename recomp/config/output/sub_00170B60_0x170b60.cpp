#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00170B60
// Address: 0x170b60 - 0x170ca0
void sub_00170B60_0x170b60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x170b60u;

    // 0x170b60: 0x27bdffe0
    ctx->pc = 0x170b60u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x170b64: 0x24020001
    ctx->pc = 0x170b64u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x170b68: 0xffb10008
    ctx->pc = 0x170b68u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x170b6c: 0x80882d
    ctx->pc = 0x170b6cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170b70: 0xffb20010
    ctx->pc = 0x170b70u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x170b74: 0x902d
    ctx->pc = 0x170b74u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170b78: 0xffb00000
    ctx->pc = 0x170b78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x170b7c: 0xffbf0018
    ctx->pc = 0x170b7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x170b80: 0xae220044
    ctx->pc = 0x170b80u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 68), GPR_U32(ctx, 2));
    // 0x170b84: 0x8e230054
    ctx->pc = 0x170b84u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 84)));
    // 0x170b88: 0xae20000c
    ctx->pc = 0x170b88u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 0));
    // 0x170b8c: 0xae200010
    ctx->pc = 0x170b8cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 0));
    // 0x170b90: 0xae200014
    ctx->pc = 0x170b90u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 0));
    // 0x170b94: 0xae200058
    ctx->pc = 0x170b94u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 88), GPR_U32(ctx, 0));
    // 0x170b98: 0x1860000c
    ctx->pc = 0x170B98u;
    {
        const bool branch_taken_0x170b98 = (GPR_S32(ctx, 3) <= 0);
        ctx->pc = 0x170B9Cu;
        WRITE32(ADD32(GPR_U32(ctx, 17), 92), GPR_U32(ctx, 0));
        if (branch_taken_0x170b98) {
            ctx->pc = 0x170BCCu;
            goto label_170bcc;
        }
    }
    ctx->pc = 0x170BA0u;
    // 0x170ba0: 0x8e230050
    ctx->pc = 0x170ba0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 80)));
    // 0x170ba4: 0x2404ffff
    ctx->pc = 0x170ba4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4294967295));
label_170ba8:
    // 0x170ba8: 0xac600010
    ctx->pc = 0x170ba8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 0));
    // 0x170bac: 0x26520001
    ctx->pc = 0x170bacu;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 1));
    // 0x170bb0: 0xac600014
    ctx->pc = 0x170bb0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 20), GPR_U32(ctx, 0));
    // 0x170bb4: 0xfc640000
    ctx->pc = 0x170bb4u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 0), GPR_U64(ctx, 4));
    // 0x170bb8: 0x8e220054
    ctx->pc = 0x170bb8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 84)));
    // 0x170bbc: 0xfc640008
    ctx->pc = 0x170bbcu;
    WRITE64(ADD32(GPR_U32(ctx, 3), 8), GPR_U64(ctx, 4));
    // 0x170bc0: 0x242102a
    ctx->pc = 0x170bc0u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 18), GPR_S32(ctx, 2)));
    // 0x170bc4: 0x1440fff8
    ctx->pc = 0x170BC4u;
    {
        const bool branch_taken_0x170bc4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x170BC8u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 24));
        if (branch_taken_0x170bc4) {
            ctx->pc = 0x170BA8u;
            goto label_170ba8;
        }
    }
    ctx->pc = 0x170BCCu;
label_170bcc:
    // 0x170bcc: 0x8e220008
    ctx->pc = 0x170bccu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x170bd0: 0x18400013
    ctx->pc = 0x170BD0u;
    {
        const bool branch_taken_0x170bd0 = (GPR_S32(ctx, 2) <= 0);
        ctx->pc = 0x170BD4u;
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x170bd0) {
            ctx->pc = 0x170C20u;
            goto label_170c20;
        }
    }
    ctx->pc = 0x170BD8u;
    // 0x170bd8: 0x3c100fff
    ctx->pc = 0x170bd8u;
    SET_GPR_U32(ctx, 16, ((uint32_t)4095 << 16));
    // 0x170bdc: 0x3610ffff
    ctx->pc = 0x170bdcu;
    SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 16), 65535));
    // 0x170be0: 0x8e220000
    ctx->pc = 0x170be0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x170be4: 0x0
    ctx->pc = 0x170be4u;
    // NOP
label_170be8:
    // 0x170be8: 0x122ac0
    ctx->pc = 0x170be8u;
    SET_GPR_U32(ctx, 5, SLL32(GPR_U32(ctx, 18), 11));
    // 0x170bec: 0x8e230004
    ctx->pc = 0x170becu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x170bf0: 0x122100
    ctx->pc = 0x170bf0u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 18), 4));
    // 0x170bf4: 0xa22821
    ctx->pc = 0x170bf4u;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x170bf8: 0x24060003
    ctx->pc = 0x170bf8u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 3));
    // 0x170bfc: 0x642021
    ctx->pc = 0x170bfcu;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x170c00: 0xb02824
    ctx->pc = 0x170c00u;
    SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 5), GPR_U32(ctx, 16)));
    // 0x170c04: 0x24070080
    ctx->pc = 0x170c04u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 128));
    // 0x170c08: 0xc05c2b0
    ctx->pc = 0x170C08u;
    SET_GPR_U32(ctx, 31, 0x170C10u);
    ctx->pc = 0x170C0Cu;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 1));
    ctx->pc = 0x170AC0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00170AC0_0x170ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170C10u; }
    }
    if (ctx->pc != 0x170C10u) { return; }
    ctx->pc = 0x170C10u;
    // 0x170c10: 0x8e220008
    ctx->pc = 0x170c10u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x170c14: 0x242102a
    ctx->pc = 0x170c14u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 18), GPR_S32(ctx, 2)));
    // 0x170c18: 0x5440fff3
    ctx->pc = 0x170C18u;
    {
        const bool branch_taken_0x170c18 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x170c18) {
            ctx->pc = 0x170C1Cu;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 0)));
            ctx->pc = 0x170BE8u;
            goto label_170be8;
        }
    }
    ctx->pc = 0x170C20u;
label_170c20:
    // 0x170c20: 0x8e250004
    ctx->pc = 0x170c20u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x170c24: 0x3c100fff
    ctx->pc = 0x170c24u;
    SET_GPR_U32(ctx, 16, ((uint32_t)4095 << 16));
    // 0x170c28: 0x3610ffff
    ctx->pc = 0x170c28u;
    SET_GPR_U32(ctx, 16, OR32(GPR_U32(ctx, 16), 65535));
    // 0x170c2c: 0x122100
    ctx->pc = 0x170c2cu;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 18), 4));
    // 0x170c30: 0xa42021
    ctx->pc = 0x170c30u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
    // 0x170c34: 0xb02824
    ctx->pc = 0x170c34u;
    SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 5), GPR_U32(ctx, 16)));
    // 0x170c38: 0x382d
    ctx->pc = 0x170c38u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170c3c: 0xc05c2b0
    ctx->pc = 0x170C3Cu;
    SET_GPR_U32(ctx, 31, 0x170C44u);
    ctx->pc = 0x170C40u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x170AC0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00170AC0_0x170ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170C44u; }
    }
    if (ctx->pc != 0x170C44u) { return; }
    ctx->pc = 0x170C44u;
    // 0x170c44: 0x3c041000
    ctx->pc = 0x170c44u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x170c48: 0x8e260004
    ctx->pc = 0x170c48u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x170c4c: 0x3c031000
    ctx->pc = 0x170c4cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x170c50: 0x8e220000
    ctx->pc = 0x170c50u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x170c54: 0x3c051000
    ctx->pc = 0x170c54u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x170c58: 0xd03024
    ctx->pc = 0x170c58u;
    SET_GPR_U32(ctx, 6, AND32(GPR_U32(ctx, 6), GPR_U32(ctx, 16)));
    // 0x170c5c: 0x3463b410
    ctx->pc = 0x170c5cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 46096));
    // 0x170c60: 0x501024
    ctx->pc = 0x170c60u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 16)));
    // 0x170c64: 0x34a5b430
    ctx->pc = 0x170c64u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 46128));
    // 0x170c68: 0x3484b420
    ctx->pc = 0x170c68u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 46112));
    // 0x170c6c: 0xac800000
    ctx->pc = 0x170c6cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0));
    // 0x170c70: 0x24040005
    ctx->pc = 0x170c70u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 5));
    // 0x170c74: 0xac620000
    ctx->pc = 0x170c74u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x170c78: 0xc05c296
    ctx->pc = 0x170C78u;
    SET_GPR_U32(ctx, 31, 0x170C80u);
    ctx->pc = 0x170C7Cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 6));
    ctx->pc = 0x170A58u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00170A58_0x170a58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170C80u; }
    }
    if (ctx->pc != 0x170C80u) { return; }
    ctx->pc = 0x170C80u;
    // 0x170c80: 0x24020001
    ctx->pc = 0x170c80u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x170c84: 0xdfb00000
    ctx->pc = 0x170c84u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x170c88: 0xdfb10008
    ctx->pc = 0x170c88u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x170c8c: 0xdfb20010
    ctx->pc = 0x170c8cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x170c90: 0xdfbf0018
    ctx->pc = 0x170c90u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x170c94: 0x3e00008
    ctx->pc = 0x170C94u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x170C98u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x170BA8u: goto label_170ba8;
            case 0x170BCCu: goto label_170bcc;
            case 0x170BE8u: goto label_170be8;
            case 0x170C20u: goto label_170c20;
            default: break;
        }
        return;
    }
    ctx->pc = 0x170C9Cu;
    // 0x170c9c: 0x0
    ctx->pc = 0x170c9cu;
    // NOP
}
