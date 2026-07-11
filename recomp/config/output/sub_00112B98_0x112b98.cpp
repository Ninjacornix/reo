#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00112B98
// Address: 0x112b98 - 0x112c58
void sub_00112B98_0x112b98(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x112b98u;

    // 0x112b98: 0x27bdffe0
    ctx->pc = 0x112b98u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x112b9c: 0xffb00000
    ctx->pc = 0x112b9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x112ba0: 0xffbf0010
    ctx->pc = 0x112ba0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x112ba4: 0xc0449be
    ctx->pc = 0x112BA4u;
    SET_GPR_U32(ctx, 31, 0x112BACu);
    ctx->pc = 0x112BA8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1126F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001126F8_0x1126f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x112BACu; }
    }
    if (ctx->pc != 0x112BACu) { return; }
    ctx->pc = 0x112BACu;
    // 0x112bac: 0x84430006
    ctx->pc = 0x112bacu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 2), 6)));
    // 0x112bb0: 0x24020001
    ctx->pc = 0x112bb0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x112bb4: 0x14620011
    ctx->pc = 0x112BB4u;
    {
        const bool branch_taken_0x112bb4 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x112BB8u;
        SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 16), 0)));
        if (branch_taken_0x112bb4) {
            ctx->pc = 0x112BFCu;
            goto label_112bfc;
        }
    }
    ctx->pc = 0x112BBCu;
    // 0x112bbc: 0x3c021200
    ctx->pc = 0x112bbcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4608 << 16));
    // 0x112bc0: 0x3c031200
    ctx->pc = 0x112bc0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4608 << 16));
    // 0x112bc4: 0x3c061200
    ctx->pc = 0x112bc4u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4608 << 16));
    // 0x112bc8: 0xfc440000
    ctx->pc = 0x112bc8u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 4));
    // 0x112bcc: 0x34630070
    ctx->pc = 0x112bccu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 112));
    // 0x112bd0: 0x34c60080
    ctx->pc = 0x112bd0u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 128));
    // 0x112bd4: 0x3c041200
    ctx->pc = 0x112bd4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4608 << 16));
    // 0x112bd8: 0xde050010
    ctx->pc = 0x112bd8u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x112bdc: 0x348400c0
    ctx->pc = 0x112bdcu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 192));
    // 0x112be0: 0xfc650000
    ctx->pc = 0x112be0u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 0), GPR_U64(ctx, 5));
    // 0x112be4: 0xde020018
    ctx->pc = 0x112be4u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x112be8: 0xfcc20000
    ctx->pc = 0x112be8u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 0), GPR_U64(ctx, 2));
    // 0x112bec: 0xde030020
    ctx->pc = 0x112becu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x112bf0: 0xfc830000
    ctx->pc = 0x112bf0u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 3));
    // 0x112bf4: 0x10000014
    ctx->pc = 0x112BF4u;
    {
        const bool branch_taken_0x112bf4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x112BF8u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        if (branch_taken_0x112bf4) {
            ctx->pc = 0x112C48u;
            goto label_112c48;
        }
    }
    ctx->pc = 0x112BFCu;
label_112bfc:
    // 0x112bfc: 0x3c031200
    ctx->pc = 0x112bfcu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4608 << 16));
    // 0x112c00: 0x3c021200
    ctx->pc = 0x112c00u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4608 << 16));
    // 0x112c04: 0x3c061200
    ctx->pc = 0x112c04u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4608 << 16));
    // 0x112c08: 0xfc640000
    ctx->pc = 0x112c08u;
    WRITE64(ADD32(GPR_U32(ctx, 3), 0), GPR_U64(ctx, 4));
    // 0x112c0c: 0x34420020
    ctx->pc = 0x112c0cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 32));
    // 0x112c10: 0x34c60090
    ctx->pc = 0x112c10u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 144));
    // 0x112c14: 0x3c051200
    ctx->pc = 0x112c14u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4608 << 16));
    // 0x112c18: 0xde030008
    ctx->pc = 0x112c18u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x112c1c: 0x34a500a0
    ctx->pc = 0x112c1cu;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 160));
    // 0x112c20: 0x3c041200
    ctx->pc = 0x112c20u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4608 << 16));
    // 0x112c24: 0xfc430000
    ctx->pc = 0x112c24u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 0), GPR_U64(ctx, 3));
    // 0x112c28: 0x348400e0
    ctx->pc = 0x112c28u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 224));
    // 0x112c2c: 0xde020010
    ctx->pc = 0x112c2cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x112c30: 0xfcc20000
    ctx->pc = 0x112c30u;
    WRITE64(ADD32(GPR_U32(ctx, 6), 0), GPR_U64(ctx, 2));
    // 0x112c34: 0xde030018
    ctx->pc = 0x112c34u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x112c38: 0xfca30000
    ctx->pc = 0x112c38u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 3));
    // 0x112c3c: 0xde020020
    ctx->pc = 0x112c3cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 16), 32)));
    // 0x112c40: 0xfc820000
    ctx->pc = 0x112c40u;
    WRITE64(ADD32(GPR_U32(ctx, 4), 0), GPR_U64(ctx, 2));
    // 0x112c44: 0xdfbf0010
    ctx->pc = 0x112c44u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_112c48:
    // 0x112c48: 0xdfb00000
    ctx->pc = 0x112c48u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x112c4c: 0x3e00008
    ctx->pc = 0x112C4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x112C50u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x112BFCu: goto label_112bfc;
            case 0x112C48u: goto label_112c48;
            default: break;
        }
        return;
    }
    ctx->pc = 0x112C54u;
    // 0x112c54: 0x0
    ctx->pc = 0x112c54u;
    // NOP
}
