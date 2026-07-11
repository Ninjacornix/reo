#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00105BD0
// Address: 0x105bd0 - 0x105d40
void sub_00105BD0_0x105bd0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x105bd0u;

    // 0x105bd0: 0x27bdffd0
    ctx->pc = 0x105bd0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x105bd4: 0xffb00000
    ctx->pc = 0x105bd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x105bd8: 0xa0802d
    ctx->pc = 0x105bd8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105bdc: 0xffb10008
    ctx->pc = 0x105bdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x105be0: 0x80882d
    ctx->pc = 0x105be0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105be4: 0xffb20010
    ctx->pc = 0x105be4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x105be8: 0x10803c
    ctx->pc = 0x105be8u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << (32 + 0));
    // 0x105bec: 0xffb40020
    ctx->pc = 0x105becu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x105bf0: 0xffb30018
    ctx->pc = 0x105bf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x105bf4: 0xffbf0028
    ctx->pc = 0x105bf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 31));
    // 0x105bf8: 0xc041f4a
    ctx->pc = 0x105BF8u;
    SET_GPR_U32(ctx, 31, 0x105C00u);
    ctx->pc = 0x105BFCu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) >> (32 + 0));
    ctx->pc = 0x107D28u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107D28_0x107d28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105C00u; }
    }
    if (ctx->pc != 0x105C00u) { return; }
    ctx->pc = 0x105C00u;
    // 0x105c00: 0x3c020021
    ctx->pc = 0x105c00u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x105c04: 0x2406fffc
    ctx->pc = 0x105c04u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 4294967292));
    // 0x105c08: 0x24549800
    ctx->pc = 0x105c08u;
    SET_GPR_S32(ctx, 20, ADD32(GPR_U32(ctx, 2), 4294940672));
    // 0x105c0c: 0x220202d
    ctx->pc = 0x105c0cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105c10: 0x8e830008
    ctx->pc = 0x105c10u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 20), 8)));
    // 0x105c14: 0x8c620004
    ctx->pc = 0x105c14u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x105c18: 0x461024
    ctx->pc = 0x105c18u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x105c1c: 0x2103c
    ctx->pc = 0x105c1cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x105c20: 0x2903e
    ctx->pc = 0x105c20u;
    SET_GPR_U64(ctx, 18, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x105c24: 0x250802f
    ctx->pc = 0x105c24u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 18) - GPR_U64(ctx, 16));
    // 0x105c28: 0x66100fef
    ctx->pc = 0x105c28u;
    SET_GPR_S64(ctx, 16, (int64_t)GPR_S64(ctx, 16) + (int64_t)4079);
    // 0x105c2c: 0x10833a
    ctx->pc = 0x105c2cu;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) >> 12);
    // 0x105c30: 0x6610ffff
    ctx->pc = 0x105c30u;
    SET_GPR_S64(ctx, 16, (int64_t)GPR_S64(ctx, 16) + (int64_t)4294967295);
    // 0x105c34: 0x108338
    ctx->pc = 0x105c34u;
    SET_GPR_U64(ctx, 16, GPR_U64(ctx, 16) << 12);
    // 0x105c38: 0x2a021000
    ctx->pc = 0x105c38u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 16), 4096));
    // 0x105c3c: 0x14400026
    ctx->pc = 0x105C3Cu;
    {
        const bool branch_taken_0x105c3c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x105C40u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x105c3c) {
            ctx->pc = 0x105CD8u;
            goto label_105cd8;
        }
    }
    ctx->pc = 0x105C44u;
    // 0x105c44: 0xc042896
    ctx->pc = 0x105C44u;
    SET_GPR_U32(ctx, 31, 0x105C4Cu);
    ctx->pc = 0x105C48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10A258u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A258_0x10a258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105C4Cu; }
    }
    if (ctx->pc != 0x105C4Cu) { return; }
    ctx->pc = 0x105C4Cu;
    // 0x105c4c: 0x8e830008
    ctx->pc = 0x105c4cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 20), 8)));
    // 0x105c50: 0x12283c
    ctx->pc = 0x105c50u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 18) << (32 + 0));
    // 0x105c54: 0x5283f
    ctx->pc = 0x105c54u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x105c58: 0x651821
    ctx->pc = 0x105c58u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    // 0x105c5c: 0x1443001e
    ctx->pc = 0x105C5Cu;
    {
        const bool branch_taken_0x105c5c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        ctx->pc = 0x105C60u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x105c5c) {
            ctx->pc = 0x105CD8u;
            goto label_105cd8;
        }
    }
    ctx->pc = 0x105C64u;
    // 0x105c64: 0x10983c
    ctx->pc = 0x105c64u;
    SET_GPR_U64(ctx, 19, GPR_U64(ctx, 16) << (32 + 0));
    // 0x105c68: 0x13983f
    ctx->pc = 0x105c68u;
    SET_GPR_S64(ctx, 19, GPR_S64(ctx, 19) >> (32 + 0));
    // 0x105c6c: 0x220202d
    ctx->pc = 0x105c6cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105c70: 0xc042896
    ctx->pc = 0x105C70u;
    SET_GPR_U32(ctx, 31, 0x105C78u);
    ctx->pc = 0x105C74u;
    SET_GPR_U32(ctx, 5, SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 19)));
    ctx->pc = 0x10A258u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A258_0x10a258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105C78u; }
    }
    if (ctx->pc != 0x105C78u) { return; }
    ctx->pc = 0x105C78u;
    // 0x105c78: 0x220202d
    ctx->pc = 0x105c78u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105c7c: 0x3c030021
    ctx->pc = 0x105c7cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x105c80: 0x2406ffff
    ctx->pc = 0x105c80u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x105c84: 0x282d
    ctx->pc = 0x105c84u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105c88: 0x14460017
    ctx->pc = 0x105C88u;
    {
        const bool branch_taken_0x105c88 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 6));
        ctx->pc = 0x105C8Cu;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 3), 4294941744));
        if (branch_taken_0x105c88) {
            ctx->pc = 0x105CE8u;
            goto label_105ce8;
        }
    }
    ctx->pc = 0x105C90u;
    // 0x105c90: 0xc042896
    ctx->pc = 0x105C90u;
    SET_GPR_U32(ctx, 31, 0x105C98u);
    ctx->pc = 0x10A258u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010A258_0x10a258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105C98u; }
    }
    if (ctx->pc != 0x105C98u) { return; }
    ctx->pc = 0x105C98u;
    // 0x105c98: 0x8e860008
    ctx->pc = 0x105c98u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 20), 8)));
    // 0x105c9c: 0x40382d
    ctx->pc = 0x105c9cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105ca0: 0x24020001
    ctx->pc = 0x105ca0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x105ca4: 0xe69023
    ctx->pc = 0x105ca4u;
    SET_GPR_U32(ctx, 18, SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 6)));
    // 0x105ca8: 0x2421025
    ctx->pc = 0x105ca8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 18), GPR_U32(ctx, 2)));
    // 0x105cac: 0x2a430010
    ctx->pc = 0x105cacu;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 18), 16));
    // 0x105cb0: 0x2283c
    ctx->pc = 0x105cb0u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) << (32 + 0));
    // 0x105cb4: 0x5283f
    ctx->pc = 0x105cb4u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x105cb8: 0x14600007
    ctx->pc = 0x105CB8u;
    {
        const bool branch_taken_0x105cb8 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x105CBCu;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x105cb8) {
            ctx->pc = 0x105CD8u;
            goto label_105cd8;
        }
    }
    ctx->pc = 0x105CC0u;
    // 0x105cc0: 0x3c020021
    ctx->pc = 0x105cc0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x105cc4: 0x8c439c18
    ctx->pc = 0x105cc4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 4294941720)));
    // 0x105cc8: 0x3c020021
    ctx->pc = 0x105cc8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x105ccc: 0xe31823
    ctx->pc = 0x105cccu;
    SET_GPR_U32(ctx, 3, SUB32(GPR_U32(ctx, 7), GPR_U32(ctx, 3)));
    // 0x105cd0: 0xac439c30
    ctx->pc = 0x105cd0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294941744), GPR_U32(ctx, 3));
    // 0x105cd4: 0xacc50004
    ctx->pc = 0x105cd4u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 5));
label_105cd8:
    // 0x105cd8: 0xc041f6a
    ctx->pc = 0x105CD8u;
    SET_GPR_U32(ctx, 31, 0x105CE0u);
    ctx->pc = 0x107DA8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DA8_0x107da8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105CE0u; }
    }
    if (ctx->pc != 0x105CE0u) { return; }
    ctx->pc = 0x105CE0u;
    // 0x105ce0: 0x1000000e
    ctx->pc = 0x105CE0u;
    {
        const bool branch_taken_0x105ce0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x105CE4u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x105ce0) {
            ctx->pc = 0x105D1Cu;
            goto label_105d1c;
        }
    }
    ctx->pc = 0x105CE8u;
label_105ce8:
    // 0x105ce8: 0x24020001
    ctx->pc = 0x105ce8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x105cec: 0x250182f
    ctx->pc = 0x105cecu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 18) - GPR_U64(ctx, 16));
    // 0x105cf0: 0x8e850008
    ctx->pc = 0x105cf0u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 20), 8)));
    // 0x105cf4: 0x621825
    ctx->pc = 0x105cf4u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x105cf8: 0x3183c
    ctx->pc = 0x105cf8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << (32 + 0));
    // 0x105cfc: 0x3183f
    ctx->pc = 0x105cfcu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 3) >> (32 + 0));
    // 0x105d00: 0x220202d
    ctx->pc = 0x105d00u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x105d04: 0xaca30004
    ctx->pc = 0x105d04u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 3));
    // 0x105d08: 0x8ce20000
    ctx->pc = 0x105d08u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x105d0c: 0x531023
    ctx->pc = 0x105d0cu;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x105d10: 0xc041f6a
    ctx->pc = 0x105D10u;
    SET_GPR_U32(ctx, 31, 0x105D18u);
    ctx->pc = 0x105D14u;
    WRITE32(ADD32(GPR_U32(ctx, 7), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x107DA8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107DA8_0x107da8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x105D18u; }
    }
    if (ctx->pc != 0x105D18u) { return; }
    ctx->pc = 0x105D18u;
    // 0x105d18: 0x24020001
    ctx->pc = 0x105d18u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_105d1c:
    // 0x105d1c: 0xdfb00000
    ctx->pc = 0x105d1cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x105d20: 0xdfb10008
    ctx->pc = 0x105d20u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x105d24: 0xdfb20010
    ctx->pc = 0x105d24u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x105d28: 0xdfb30018
    ctx->pc = 0x105d28u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x105d2c: 0xdfb40020
    ctx->pc = 0x105d2cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x105d30: 0xdfbf0028
    ctx->pc = 0x105d30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x105d34: 0x3e00008
    ctx->pc = 0x105D34u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x105D38u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x105CD8u: goto label_105cd8;
            case 0x105CE8u: goto label_105ce8;
            case 0x105D1Cu: goto label_105d1c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x105D3Cu;
    // 0x105d3c: 0x0
    ctx->pc = 0x105d3cu;
    // NOP
}
