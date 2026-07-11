#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00138E58
// Address: 0x138e58 - 0x138f78
void sub_00138E58_0x138e58(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x138e58u;

    // 0x138e58: 0x3c070026
    ctx->pc = 0x138e58u;
    SET_GPR_U32(ctx, 7, ((uint32_t)38 << 16));
    // 0x138e5c: 0x27bdffe0
    ctx->pc = 0x138e5cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x138e60: 0x24e723c0
    ctx->pc = 0x138e60u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 9152));
    // 0x138e64: 0xffbf0010
    ctx->pc = 0x138e64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x138e68: 0x3c020022
    ctx->pc = 0x138e68u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
    // 0x138e6c: 0x3c090026
    ctx->pc = 0x138e6cu;
    SET_GPR_U32(ctx, 9, ((uint32_t)38 << 16));
    // 0x138e70: 0xace40000
    ctx->pc = 0x138e70u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 4));
    // 0x138e74: 0x2444c870
    ctx->pc = 0x138e74u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 4294953072));
    // 0x138e78: 0x252924c0
    ctx->pc = 0x138e78u;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 9), 9408));
    // 0x138e7c: 0x24050003
    ctx->pc = 0x138e7cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 3));
    // 0x138e80: 0x302d
    ctx->pc = 0x138e80u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138e84: 0x24080004
    ctx->pc = 0x138e84u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 4));
    // 0x138e88: 0x502d
    ctx->pc = 0x138e88u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138e8c: 0x582d
    ctx->pc = 0x138e8cu;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138e90: 0xc045e7a
    ctx->pc = 0x138E90u;
    SET_GPR_U32(ctx, 31, 0x138E98u);
    ctx->pc = 0x138E94u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 0));
    ctx->pc = 0x1179E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138E98u; }
    }
    if (ctx->pc != 0x138E98u) { return; }
    ctx->pc = 0x138E98u;
    // 0x138e98: 0xdfbf0010
    ctx->pc = 0x138e98u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x138e9c: 0x3e00008
    ctx->pc = 0x138E9Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138EA0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138EE0u: goto label_138ee0;
            case 0x138EFCu: goto label_138efc;
            case 0x138F54u: goto label_138f54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138EA4u;
    // 0x138ea4: 0x0
    ctx->pc = 0x138ea4u;
    // NOP
    // 0x138ea8: 0x3c030022
    ctx->pc = 0x138ea8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
    // 0x138eac: 0x2463c420
    ctx->pc = 0x138eacu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294951968));
    // 0x138eb0: 0x8c620000
    ctx->pc = 0x138eb0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x138eb4: 0x24420001
    ctx->pc = 0x138eb4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x138eb8: 0x3e00008
    ctx->pc = 0x138EB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138EBCu;
        WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138EE0u: goto label_138ee0;
            case 0x138EFCu: goto label_138efc;
            case 0x138F54u: goto label_138f54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138EC0u;
    // 0x138ec0: 0x27bdfff0
    ctx->pc = 0x138ec0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x138ec4: 0xa0202d
    ctx->pc = 0x138ec4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138ec8: 0xffb00000
    ctx->pc = 0x138ec8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x138ecc: 0x282d
    ctx->pc = 0x138eccu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138ed0: 0x18c0000a
    ctx->pc = 0x138ED0u;
    {
        const bool branch_taken_0x138ed0 = (GPR_S32(ctx, 6) <= 0);
        ctx->pc = 0x138ED4u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        if (branch_taken_0x138ed0) {
            ctx->pc = 0x138EFCu;
            goto label_138efc;
        }
    }
    ctx->pc = 0x138ED8u;
    // 0x138ed8: 0x2407ffaa
    ctx->pc = 0x138ed8u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 4294967210));
    // 0x138edc: 0x0
    ctx->pc = 0x138edcu;
    // NOP
label_138ee0:
    // 0x138ee0: 0x851821
    ctx->pc = 0x138ee0u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 5)));
    // 0x138ee4: 0x24a50001
    ctx->pc = 0x138ee4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 1));
    // 0x138ee8: 0xa6102a
    ctx->pc = 0x138ee8u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 5), GPR_S32(ctx, 6)));
    // 0x138eec: 0x0
    ctx->pc = 0x138eecu;
    // NOP
    // 0x138ef0: 0x0
    ctx->pc = 0x138ef0u;
    // NOP
    // 0x138ef4: 0x1440fffa
    ctx->pc = 0x138EF4u;
    {
        const bool branch_taken_0x138ef4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x138EF8u;
        WRITE8(ADD32(GPR_U32(ctx, 3), 0), (uint8_t)GPR_U32(ctx, 7));
        if (branch_taken_0x138ef4) {
            ctx->pc = 0x138EE0u;
            goto label_138ee0;
        }
    }
    ctx->pc = 0x138EFCu;
label_138efc:
    // 0x138efc: 0x3c100022
    ctx->pc = 0x138efcu;
    SET_GPR_U32(ctx, 16, ((uint32_t)34 << 16));
    // 0x138f00: 0x3c050024
    ctx->pc = 0x138f00u;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x138f04: 0x2610c424
    ctx->pc = 0x138f04u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 4294951972));
    // 0x138f08: 0x24a5c950
    ctx->pc = 0x138f08u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294953296));
    // 0x138f0c: 0xc042a0c
    ctx->pc = 0x138F0Cu;
    SET_GPR_U32(ctx, 31, 0x138F14u);
    ctx->pc = 0x138F10u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    ctx->pc = 0x10A830u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A830_0x10a830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x138F14u; }
    }
    if (ctx->pc != 0x138F14u) { return; }
    ctx->pc = 0x138F14u;
    // 0x138f14: 0x8e030000
    ctx->pc = 0x138f14u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x138f18: 0xdfbf0008
    ctx->pc = 0x138f18u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x138f1c: 0x24630001
    ctx->pc = 0x138f1cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 1));
    // 0x138f20: 0xae030000
    ctx->pc = 0x138f20u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 3));
    // 0x138f24: 0xdfb00000
    ctx->pc = 0x138f24u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x138f28: 0x3e00008
    ctx->pc = 0x138F28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138F2Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138EE0u: goto label_138ee0;
            case 0x138EFCu: goto label_138efc;
            case 0x138F54u: goto label_138f54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138F30u;
    // 0x138f30: 0x41900
    ctx->pc = 0x138f30u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 4), 4));
    // 0x138f34: 0x2c850008
    ctx->pc = 0x138f34u;
    SET_GPR_U32(ctx, 5, SLTU32(GPR_U32(ctx, 4), 8));
    // 0x138f38: 0x102d
    ctx->pc = 0x138f38u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x138f3c: 0x10a00005
    ctx->pc = 0x138F3Cu;
    {
        const bool branch_taken_0x138f3c = (GPR_U32(ctx, 5) == GPR_U32(ctx, 0));
        ctx->pc = 0x138F40u;
        SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
        if (branch_taken_0x138f3c) {
            ctx->pc = 0x138F54u;
            goto label_138f54;
        }
    }
    ctx->pc = 0x138F44u;
    // 0x138f44: 0x31080
    ctx->pc = 0x138f44u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 3), 2));
    // 0x138f48: 0x3c010022
    ctx->pc = 0x138f48u;
    SET_GPR_U32(ctx, 1, ((uint32_t)34 << 16));
    // 0x138f4c: 0x2421c430
    ctx->pc = 0x138f4cu;
    SET_GPR_S32(ctx, 1, ADD32(GPR_U32(ctx, 1), 4294951984));
    // 0x138f50: 0x221021
    ctx->pc = 0x138f50u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 1), GPR_U32(ctx, 2)));
label_138f54:
    // 0x138f54: 0x3e00008
    ctx->pc = 0x138F54u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138EE0u: goto label_138ee0;
            case 0x138EFCu: goto label_138efc;
            case 0x138F54u: goto label_138f54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138F5Cu;
    // 0x138f5c: 0x0
    ctx->pc = 0x138f5cu;
    // NOP
    // 0x138f60: 0xac80002c
    ctx->pc = 0x138f60u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 44), GPR_U32(ctx, 0));
    // 0x138f64: 0xac800020
    ctx->pc = 0x138f64u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 32), GPR_U32(ctx, 0));
    // 0x138f68: 0xac800024
    ctx->pc = 0x138f68u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 36), GPR_U32(ctx, 0));
    // 0x138f6c: 0x3e00008
    ctx->pc = 0x138F6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x138F70u;
        WRITE32(ADD32(GPR_U32(ctx, 4), 40), GPR_U32(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x138EE0u: goto label_138ee0;
            case 0x138EFCu: goto label_138efc;
            case 0x138F54u: goto label_138f54;
            default: break;
        }
        return;
    }
    ctx->pc = 0x138F74u;
    // 0x138f74: 0x0
    ctx->pc = 0x138f74u;
    // NOP
}
