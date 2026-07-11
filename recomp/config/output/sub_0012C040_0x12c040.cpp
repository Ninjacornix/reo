#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0012C040
// Address: 0x12c040 - 0x12c4a0
void sub_0012C040_0x12c040(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x12c040u;

label_12c040:
    // 0x12c040: 0x27bdfff0
    ctx->pc = 0x12c040u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c044: 0xffbf0000
    ctx->pc = 0x12c044u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c048: 0xc04afc4
    ctx->pc = 0x12C048u;
    SET_GPR_U32(ctx, 31, 0x12C050u);
    ctx->pc = 0x12BF10u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BF10_0x12bf10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C050u; }
    }
    if (ctx->pc != 0x12C050u) { return; }
    ctx->pc = 0x12C050u;
    // 0x12c050: 0xdfbf0000
    ctx->pc = 0x12c050u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c054: 0x804b006
    ctx->pc = 0x12C054u;
    ctx->pc = 0x12C058u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x12C018u;
    entry_12c018_0x12c040(rdram, ctx, runtime); return;
    ctx->pc = 0x12C05Cu;
    // 0x12c05c: 0x0
    ctx->pc = 0x12c05cu;
    // NOP
    // 0x12c060: 0x27bdfff0
    ctx->pc = 0x12c060u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c064: 0xffbf0000
    ctx->pc = 0x12c064u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c068: 0xdfbf0000
    ctx->pc = 0x12c068u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c06c: 0x804b010
    ctx->pc = 0x12C06Cu;
    ctx->pc = 0x12C070u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x12C040u;
    goto label_12c040;
    ctx->pc = 0x12C074u;
    // 0x12c074: 0x0
    ctx->pc = 0x12c074u;
    // NOP
    // 0x12c078: 0x27bdfff0
    ctx->pc = 0x12c078u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c07c: 0x3c020021
    ctx->pc = 0x12c07cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x12c080: 0xffb00000
    ctx->pc = 0x12c080u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12c084: 0x24500558
    ctx->pc = 0x12c084u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 2), 1368));
    // 0x12c088: 0x8e030000
    ctx->pc = 0x12c088u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12c08c: 0x14600007
    ctx->pc = 0x12C08Cu;
    {
        const bool branch_taken_0x12c08c = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x12C090u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        if (branch_taken_0x12c08c) {
            ctx->pc = 0x12C0ACu;
            goto label_12c0ac;
        }
    }
    ctx->pc = 0x12C094u;
    // 0x12c094: 0x24020001
    ctx->pc = 0x12c094u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x12c098: 0xc04cb02
    ctx->pc = 0x12C098u;
    SET_GPR_U32(ctx, 31, 0x12C0A0u);
    ctx->pc = 0x132C08u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00132C08_0x132c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C0A0u; }
    }
    if (ctx->pc != 0x12C0A0u) { return; }
    ctx->pc = 0x12C0A0u;
    // 0x12c0a0: 0xc04a808
    ctx->pc = 0x12C0A0u;
    SET_GPR_U32(ctx, 31, 0x12C0A8u);
    ctx->pc = 0x12A020u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A020_0x12a020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C0A8u; }
    }
    if (ctx->pc != 0x12C0A8u) { return; }
    ctx->pc = 0x12C0A8u;
    // 0x12c0a8: 0xae000000
    ctx->pc = 0x12c0a8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
label_12c0ac:
    // 0x12c0ac: 0xdfb00000
    ctx->pc = 0x12c0acu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c0b0: 0x102d
    ctx->pc = 0x12c0b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c0b4: 0xdfbf0008
    ctx->pc = 0x12c0b4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12c0b8: 0x3e00008
    ctx->pc = 0x12C0B8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C0BCu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C040u: goto label_12c040;
            case 0x12C0ACu: goto label_12c0ac;
            case 0x12C108u: goto label_12c108;
            case 0x12C10Cu: goto label_12c10c;
            case 0x12C190u: goto label_12c190;
            case 0x12C280u: goto label_12c280;
            case 0x12C2C4u: goto label_12c2c4;
            case 0x12C360u: goto label_12c360;
            case 0x12C428u: goto label_12c428;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C0C0u;
    // 0x12c0c0: 0x27bdffd0
    ctx->pc = 0x12c0c0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967248));
    // 0x12c0c4: 0x80102d
    ctx->pc = 0x12c0c4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c0c8: 0x1040000f
    ctx->pc = 0x12C0C8u;
    {
        const bool branch_taken_0x12c0c8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x12C0CCu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 31));
        if (branch_taken_0x12c0c8) {
            ctx->pc = 0x12C108u;
            goto label_12c108;
        }
    }
    ctx->pc = 0x12C0D0u;
    // 0x12c0d0: 0x8c460008
    ctx->pc = 0x12c0d0u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 2), 8)));
    // 0x12c0d4: 0x24070019
    ctx->pc = 0x12c0d4u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 25));
    // 0x12c0d8: 0x8c44000c
    ctx->pc = 0x12c0d8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 12)));
    // 0x12c0dc: 0x3a0402d
    ctx->pc = 0x12c0dcu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c0e0: 0x8c430000
    ctx->pc = 0x12c0e0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12c0e4: 0x24c50001
    ctx->pc = 0x12c0e4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 6), 1));
    // 0x12c0e8: 0x8c420004
    ctx->pc = 0x12c0e8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x12c0ec: 0xafa40010
    ctx->pc = 0x12c0ecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 4));
    // 0x12c0f0: 0xafa30000
    ctx->pc = 0x12c0f0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x12c0f4: 0xafa20004
    ctx->pc = 0x12c0f4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
    // 0x12c0f8: 0xafa5000c
    ctx->pc = 0x12c0f8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 12), GPR_U32(ctx, 5));
    // 0x12c0fc: 0xafa70014
    ctx->pc = 0x12c0fcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 20), GPR_U32(ctx, 7));
    // 0x12c100: 0x10000002
    ctx->pc = 0x12C100u;
    {
        const bool branch_taken_0x12c100 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x12C104u;
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 6));
        if (branch_taken_0x12c100) {
            ctx->pc = 0x12C10Cu;
            goto label_12c10c;
        }
    }
    ctx->pc = 0x12C108u;
label_12c108:
    // 0x12c108: 0x402d
    ctx->pc = 0x12c108u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_12c10c:
    // 0x12c10c: 0xc04ad8e
    ctx->pc = 0x12C10Cu;
    SET_GPR_U32(ctx, 31, 0x12C114u);
    ctx->pc = 0x12C110u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x12B638u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B638_0x12b638(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C114u; }
    }
    if (ctx->pc != 0x12C114u) { return; }
    ctx->pc = 0x12C114u;
    // 0x12c114: 0xdfbf0020
    ctx->pc = 0x12c114u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x12c118: 0x3e00008
    ctx->pc = 0x12C118u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C11Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C040u: goto label_12c040;
            case 0x12C0ACu: goto label_12c0ac;
            case 0x12C108u: goto label_12c108;
            case 0x12C10Cu: goto label_12c10c;
            case 0x12C190u: goto label_12c190;
            case 0x12C280u: goto label_12c280;
            case 0x12C2C4u: goto label_12c2c4;
            case 0x12C360u: goto label_12c360;
            case 0x12C428u: goto label_12c428;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C120u;
    // 0x12c120: 0x27bdfff0
    ctx->pc = 0x12c120u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c124: 0xffbf0000
    ctx->pc = 0x12c124u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c128: 0xdfbf0000
    ctx->pc = 0x12c128u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c12c: 0x804ae00
    ctx->pc = 0x12C12Cu;
    ctx->pc = 0x12C130u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x12B800u;
    sub_0012B800_0x12b800(rdram, ctx, runtime); return;
    ctx->pc = 0x12C134u;
    // 0x12c134: 0x0
    ctx->pc = 0x12c134u;
    // NOP
    // 0x12c138: 0x27bdfff0
    ctx->pc = 0x12c138u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c13c: 0xffb00000
    ctx->pc = 0x12c13cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x12c140: 0xffbf0008
    ctx->pc = 0x12c140u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
    // 0x12c144: 0xc04af5e
    ctx->pc = 0x12C144u;
    SET_GPR_U32(ctx, 31, 0x12C14Cu);
    ctx->pc = 0x12BD78u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BD78_0x12bd78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C14Cu; }
    }
    if (ctx->pc != 0x12C14Cu) { return; }
    ctx->pc = 0x12C14Cu;
    // 0x12c14c: 0x3c020021
    ctx->pc = 0x12c14cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x12c150: 0x24500558
    ctx->pc = 0x12c150u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 2), 1368));
    // 0x12c154: 0x8e030000
    ctx->pc = 0x12c154u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12c158: 0x5460000d
    ctx->pc = 0x12C158u;
    {
        const bool branch_taken_0x12c158 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x12c158) {
            ctx->pc = 0x12C15Cu;
            SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
            ctx->pc = 0x12C190u;
            goto label_12c190;
        }
    }
    ctx->pc = 0x12C160u;
    // 0x12c160: 0x24020001
    ctx->pc = 0x12c160u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x12c164: 0xc04af64
    ctx->pc = 0x12C164u;
    SET_GPR_U32(ctx, 31, 0x12C16Cu);
    ctx->pc = 0x12C168u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 2));
    ctx->pc = 0x12BD90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BD90_0x12bd90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C16Cu; }
    }
    if (ctx->pc != 0x12C16Cu) { return; }
    ctx->pc = 0x12C16Cu;
    // 0x12c16c: 0xc04cb02
    ctx->pc = 0x12C16Cu;
    SET_GPR_U32(ctx, 31, 0x12C174u);
    ctx->pc = 0x132C08u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00132C08_0x132c08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C174u; }
    }
    if (ctx->pc != 0x12C174u) { return; }
    ctx->pc = 0x12C174u;
    // 0x12c174: 0xc04a808
    ctx->pc = 0x12C174u;
    SET_GPR_U32(ctx, 31, 0x12C17Cu);
    ctx->pc = 0x12A020u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012A020_0x12a020(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C17Cu; }
    }
    if (ctx->pc != 0x12C17Cu) { return; }
    ctx->pc = 0x12C17Cu;
    // 0x12c17c: 0xae000000
    ctx->pc = 0x12c17cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 0), GPR_U32(ctx, 0));
    // 0x12c180: 0xdfbf0008
    ctx->pc = 0x12c180u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12c184: 0xdfb00000
    ctx->pc = 0x12c184u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c188: 0x3e00008
    ctx->pc = 0x12C188u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C18Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C040u: goto label_12c040;
            case 0x12C0ACu: goto label_12c0ac;
            case 0x12C108u: goto label_12c108;
            case 0x12C10Cu: goto label_12c10c;
            case 0x12C190u: goto label_12c190;
            case 0x12C280u: goto label_12c280;
            case 0x12C2C4u: goto label_12c2c4;
            case 0x12C360u: goto label_12c360;
            case 0x12C428u: goto label_12c428;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C190u;
label_12c190:
    // 0x12c190: 0xdfbf0008
    ctx->pc = 0x12c190u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x12c194: 0x804af64
    ctx->pc = 0x12C194u;
    ctx->pc = 0x12C198u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x12BD90u;
    sub_0012BD90_0x12bd90(rdram, ctx, runtime); return;
    ctx->pc = 0x12C19Cu;
    // 0x12c19c: 0x0
    ctx->pc = 0x12c19cu;
    // NOP
    // 0x12c1a0: 0x27bdfff0
    ctx->pc = 0x12c1a0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c1a4: 0xffbf0000
    ctx->pc = 0x12c1a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c1a8: 0xdfbf0000
    ctx->pc = 0x12c1a8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c1ac: 0x80505b4
    ctx->pc = 0x12C1ACu;
    ctx->pc = 0x12C1B0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x1416D0u;
    sub_001416D0_0x1416d0(rdram, ctx, runtime); return;
    ctx->pc = 0x12C1B4u;
    // 0x12c1b4: 0x0
    ctx->pc = 0x12c1b4u;
    // NOP
    // 0x12c1b8: 0x27bdfff0
    ctx->pc = 0x12c1b8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c1bc: 0xffbf0000
    ctx->pc = 0x12c1bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c1c0: 0xdfbf0000
    ctx->pc = 0x12c1c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c1c4: 0x80505ba
    ctx->pc = 0x12C1C4u;
    ctx->pc = 0x12C1C8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x1416E8u;
    sub_001416E8_0x1416e8(rdram, ctx, runtime); return;
    ctx->pc = 0x12C1CCu;
    // 0x12c1cc: 0x0
    ctx->pc = 0x12c1ccu;
    // NOP
    // 0x12c1d0: 0x27bdffb0
    ctx->pc = 0x12c1d0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x12c1d4: 0x3c020021
    ctx->pc = 0x12c1d4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x12c1d8: 0xffb20040
    ctx->pc = 0x12c1d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x12c1dc: 0x3c120021
    ctx->pc = 0x12c1dcu;
    SET_GPR_U32(ctx, 18, ((uint32_t)33 << 16));
    // 0x12c1e0: 0xffb00030
    ctx->pc = 0x12c1e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x12c1e4: 0x80802d
    ctx->pc = 0x12c1e4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c1e8: 0xffb10038
    ctx->pc = 0x12c1e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x12c1ec: 0x24420450
    ctx->pc = 0x12c1ecu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1104));
    // 0x12c1f0: 0xffbf0048
    ctx->pc = 0x12c1f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x12c1f4: 0x8e430454
    ctx->pc = 0x12c1f4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 1108)));
    // 0x12c1f8: 0x8c450000
    ctx->pc = 0x12c1f8u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x12c1fc: 0x54600058
    ctx->pc = 0x12C1FCu;
    {
        const bool branch_taken_0x12c1fc = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x12c1fc) {
            ctx->pc = 0x12C200u;
            SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 18), 1108));
            ctx->pc = 0x12C360u;
            goto label_12c360;
        }
    }
    ctx->pc = 0x12C204u;
    // 0x12c204: 0xc05083e
    ctx->pc = 0x12C204u;
    SET_GPR_U32(ctx, 31, 0x12C20Cu);
    ctx->pc = 0x1420F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001420F8_0x1420f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C20Cu; }
    }
    if (ctx->pc != 0x12C20Cu) { return; }
    ctx->pc = 0x12C20Cu;
    // 0x12c20c: 0x3c040013
    ctx->pc = 0x12c20cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)19 << 16));
    // 0x12c210: 0x282d
    ctx->pc = 0x12c210u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c214: 0xc05077c
    ctx->pc = 0x12C214u;
    SET_GPR_U32(ctx, 31, 0x12C21Cu);
    ctx->pc = 0x12C218u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294945128));
    ctx->pc = 0x141DF0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00141DF0_0x141df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C21Cu; }
    }
    if (ctx->pc != 0x12C21Cu) { return; }
    ctx->pc = 0x12C21Cu;
    // 0x12c21c: 0x3c040013
    ctx->pc = 0x12c21cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)19 << 16));
    // 0x12c220: 0x2484a9f0
    ctx->pc = 0x12c220u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294945264));
    // 0x12c224: 0xc050782
    ctx->pc = 0x12C224u;
    SET_GPR_U32(ctx, 31, 0x12C22Cu);
    ctx->pc = 0x12C228u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x141E08u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00141E08_0x141e08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C22Cu; }
    }
    if (ctx->pc != 0x12C22Cu) { return; }
    ctx->pc = 0x12C22Cu;
    // 0x12c22c: 0x56000014
    ctx->pc = 0x12C22Cu;
    {
        const bool branch_taken_0x12c22c = (GPR_U32(ctx, 16) != GPR_U32(ctx, 0));
        if (branch_taken_0x12c22c) {
            ctx->pc = 0x12C230u;
            SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 20)));
            ctx->pc = 0x12C280u;
            goto label_12c280;
        }
    }
    ctx->pc = 0x12C234u;
    // 0x12c234: 0x3c110021
    ctx->pc = 0x12c234u;
    SET_GPR_U32(ctx, 17, ((uint32_t)33 << 16));
    // 0x12c238: 0x24020018
    ctx->pc = 0x12c238u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 24));
    // 0x12c23c: 0x26240460
    ctx->pc = 0x12c23cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 17), 1120));
    // 0x12c240: 0x2403001a
    ctx->pc = 0x12c240u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 26));
    // 0x12c244: 0xac820014
    ctx->pc = 0x12c244u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 2));
    // 0x12c248: 0x24020001
    ctx->pc = 0x12c248u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x12c24c: 0xac83001c
    ctx->pc = 0x12c24cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 3));
    // 0x12c250: 0x24030008
    ctx->pc = 0x12c250u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 8));
    // 0x12c254: 0xac820000
    ctx->pc = 0x12c254u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x12c258: 0x2402000f
    ctx->pc = 0x12c258u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 15));
    // 0x12c25c: 0xac830004
    ctx->pc = 0x12c25cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
    // 0x12c260: 0x24030010
    ctx->pc = 0x12c260u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 16));
    // 0x12c264: 0xac820008
    ctx->pc = 0x12c264u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
    // 0x12c268: 0x24020012
    ctx->pc = 0x12c268u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 18));
    // 0x12c26c: 0xac83000c
    ctx->pc = 0x12c26cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 3));
    // 0x12c270: 0x24030019
    ctx->pc = 0x12c270u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 25));
    // 0x12c274: 0xac820010
    ctx->pc = 0x12c274u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 2));
    // 0x12c278: 0x10000012
    ctx->pc = 0x12C278u;
    {
        const bool branch_taken_0x12c278 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x12C27Cu;
        WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 3));
        if (branch_taken_0x12c278) {
            ctx->pc = 0x12C2C4u;
            goto label_12c2c4;
        }
    }
    ctx->pc = 0x12C280u;
label_12c280:
    // 0x12c280: 0x3c110021
    ctx->pc = 0x12c280u;
    SET_GPR_U32(ctx, 17, ((uint32_t)33 << 16));
    // 0x12c284: 0x26240460
    ctx->pc = 0x12c284u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 17), 1120));
    // 0x12c288: 0xac830014
    ctx->pc = 0x12c288u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 20), GPR_U32(ctx, 3));
    // 0x12c28c: 0x8e020000
    ctx->pc = 0x12c28cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12c290: 0xac820000
    ctx->pc = 0x12c290u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 2));
    // 0x12c294: 0x8e030004
    ctx->pc = 0x12c294u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x12c298: 0xac830004
    ctx->pc = 0x12c298u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 4), GPR_U32(ctx, 3));
    // 0x12c29c: 0x8e020008
    ctx->pc = 0x12c29cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x12c2a0: 0xac820008
    ctx->pc = 0x12c2a0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 2));
    // 0x12c2a4: 0x8e03000c
    ctx->pc = 0x12c2a4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x12c2a8: 0xac83000c
    ctx->pc = 0x12c2a8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 3));
    // 0x12c2ac: 0x8e020010
    ctx->pc = 0x12c2acu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 16)));
    // 0x12c2b0: 0xac820010
    ctx->pc = 0x12c2b0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 2));
    // 0x12c2b4: 0x8e030018
    ctx->pc = 0x12c2b4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 24)));
    // 0x12c2b8: 0xac830018
    ctx->pc = 0x12c2b8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 24), GPR_U32(ctx, 3));
    // 0x12c2bc: 0x8e02001c
    ctx->pc = 0x12c2bcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 28)));
    // 0x12c2c0: 0xac82001c
    ctx->pc = 0x12c2c0u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 28), GPR_U32(ctx, 2));
label_12c2c4:
    // 0x12c2c4: 0xc045144
    ctx->pc = 0x12C2C4u;
    SET_GPR_U32(ctx, 31, 0x12C2CCu);
    ctx->pc = 0x12C2C8u;
    SET_GPR_U32(ctx, 16, ((uint32_t)33 << 16));
    ctx->pc = 0x114510u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114510_0x114510(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C2CCu; }
    }
    if (ctx->pc != 0x12C2CCu) { return; }
    ctx->pc = 0x12C2CCu;
    // 0x12c2cc: 0x261004e8
    ctx->pc = 0x12c2ccu;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 1256));
    // 0x12c2d0: 0x3a0282d
    ctx->pc = 0x12c2d0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c2d4: 0x0
    ctx->pc = 0x12c2d4u;
    // NOP
    // 0x12c2d8: 0xc045148
    ctx->pc = 0x12C2D8u;
    SET_GPR_U32(ctx, 31, 0x12C2E0u);
    ctx->pc = 0x12C2DCu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    ctx->pc = 0x114520u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114520_0x114520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C2E0u; }
    }
    if (ctx->pc != 0x12C2E0u) { return; }
    ctx->pc = 0x12C2E0u;
    // 0x12c2e0: 0x3c030021
    ctx->pc = 0x12c2e0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x12c2e4: 0x8fa20018
    ctx->pc = 0x12c2e4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x12c2e8: 0xc04ac6e
    ctx->pc = 0x12C2E8u;
    SET_GPR_U32(ctx, 31, 0x12C2F0u);
    ctx->pc = 0x12B1B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B1B8_0x12b1b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C2F0u; }
    }
    if (ctx->pc != 0x12C2F0u) { return; }
    ctx->pc = 0x12C2F0u;
    // 0x12c2f0: 0xc04ac98
    ctx->pc = 0x12C2F0u;
    SET_GPR_U32(ctx, 31, 0x12C2F8u);
    ctx->pc = 0x12B260u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B260_0x12b260(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C2F8u; }
    }
    if (ctx->pc != 0x12C2F8u) { return; }
    ctx->pc = 0x12C2F8u;
    // 0x12c2f8: 0xc04acba
    ctx->pc = 0x12C2F8u;
    SET_GPR_U32(ctx, 31, 0x12C300u);
    ctx->pc = 0x12B2E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B2E8_0x12b2e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C300u; }
    }
    if (ctx->pc != 0x12C300u) { return; }
    ctx->pc = 0x12C300u;
    // 0x12c300: 0xc04acdc
    ctx->pc = 0x12C300u;
    SET_GPR_U32(ctx, 31, 0x12C308u);
    ctx->pc = 0x12B370u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B370_0x12b370(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C308u; }
    }
    if (ctx->pc != 0x12C308u) { return; }
    ctx->pc = 0x12C308u;
    // 0x12c308: 0xc04acfe
    ctx->pc = 0x12C308u;
    SET_GPR_U32(ctx, 31, 0x12C310u);
    ctx->pc = 0x12B3F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B3F8_0x12b3f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C310u; }
    }
    if (ctx->pc != 0x12C310u) { return; }
    ctx->pc = 0x12C310u;
    // 0x12c310: 0xc04ad24
    ctx->pc = 0x12C310u;
    SET_GPR_U32(ctx, 31, 0x12C318u);
    ctx->pc = 0x12B490u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B490_0x12b490(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C318u; }
    }
    if (ctx->pc != 0x12C318u) { return; }
    ctx->pc = 0x12C318u;
    // 0x12c318: 0x8e040000
    ctx->pc = 0x12c318u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x12c31c: 0x26220460
    ctx->pc = 0x12c31cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 17), 1120));
    // 0x12c320: 0xc04512c
    ctx->pc = 0x12C320u;
    SET_GPR_U32(ctx, 31, 0x12C328u);
    ctx->pc = 0x12C324u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 2), 20)));
    ctx->pc = 0x1144B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C328u; }
    }
    if (ctx->pc != 0x12C328u) { return; }
    ctx->pc = 0x12C328u;
    // 0x12c328: 0x3c050013
    ctx->pc = 0x12c328u;
    SET_GPR_U32(ctx, 5, ((uint32_t)19 << 16));
    // 0x12c32c: 0x24a5ab38
    ctx->pc = 0x12c32cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294945592));
    // 0x12c330: 0x24040006
    ctx->pc = 0x12c330u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 6));
    // 0x12c334: 0xc050746
    ctx->pc = 0x12C334u;
    SET_GPR_U32(ctx, 31, 0x12C33Cu);
    ctx->pc = 0x12C338u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x141D18u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00141D18_0x141d18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C33Cu; }
    }
    if (ctx->pc != 0x12C33Cu) { return; }
    ctx->pc = 0x12C33Cu;
    // 0x12c33c: 0x3c050013
    ctx->pc = 0x12c33cu;
    SET_GPR_U32(ctx, 5, ((uint32_t)19 << 16));
    // 0x12c340: 0x24a5ab60
    ctx->pc = 0x12c340u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294945632));
    // 0x12c344: 0x24040007
    ctx->pc = 0x12c344u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 7));
    // 0x12c348: 0xc050746
    ctx->pc = 0x12C348u;
    SET_GPR_U32(ctx, 31, 0x12C350u);
    ctx->pc = 0x12C34Cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x141D18u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00141D18_0x141d18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C350u; }
    }
    if (ctx->pc != 0x12C350u) { return; }
    ctx->pc = 0x12C350u;
    // 0x12c350: 0x3c030021
    ctx->pc = 0x12c350u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x12c354: 0x24020001
    ctx->pc = 0x12c354u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x12c358: 0xac620458
    ctx->pc = 0x12c358u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1112), GPR_U32(ctx, 2));
    // 0x12c35c: 0x26430454
    ctx->pc = 0x12c35cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 18), 1108));
label_12c360:
    // 0x12c360: 0xdfb20040
    ctx->pc = 0x12c360u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x12c364: 0x8c620000
    ctx->pc = 0x12c364u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12c368: 0xdfb00030
    ctx->pc = 0x12c368u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x12c36c: 0xdfb10038
    ctx->pc = 0x12c36cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x12c370: 0x24420001
    ctx->pc = 0x12c370u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x12c374: 0xdfbf0048
    ctx->pc = 0x12c374u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x12c378: 0xac620000
    ctx->pc = 0x12c378u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x12c37c: 0x3e00008
    ctx->pc = 0x12C37Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C380u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C040u: goto label_12c040;
            case 0x12C0ACu: goto label_12c0ac;
            case 0x12C108u: goto label_12c108;
            case 0x12C10Cu: goto label_12c10c;
            case 0x12C190u: goto label_12c190;
            case 0x12C280u: goto label_12c280;
            case 0x12C2C4u: goto label_12c2c4;
            case 0x12C360u: goto label_12c360;
            case 0x12C428u: goto label_12c428;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C384u;
    // 0x12c384: 0x0
    ctx->pc = 0x12c384u;
    // NOP
    // 0x12c388: 0x27bdfff0
    ctx->pc = 0x12c388u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c38c: 0x3c030021
    ctx->pc = 0x12c38cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x12c390: 0xffbf0000
    ctx->pc = 0x12c390u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c394: 0x24630454
    ctx->pc = 0x12c394u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 1108));
    // 0x12c398: 0x8c620000
    ctx->pc = 0x12c398u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x12c39c: 0x2442ffff
    ctx->pc = 0x12c39cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x12c3a0: 0x14400021
    ctx->pc = 0x12C3A0u;
    {
        const bool branch_taken_0x12c3a0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x12c3a0) {
            ctx->pc = 0x12C428u;
            goto label_12c428;
        }
    }
    ctx->pc = 0x12C3A8u;
    // 0x12c3a8: 0xc04adec
    ctx->pc = 0x12C3A8u;
    SET_GPR_U32(ctx, 31, 0x12C3B0u);
    ctx->pc = 0x12B7B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B7B0_0x12b7b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3B0u; }
    }
    if (ctx->pc != 0x12C3B0u) { return; }
    ctx->pc = 0x12C3B0u;
    // 0x12c3b0: 0xc04ae26
    ctx->pc = 0x12C3B0u;
    SET_GPR_U32(ctx, 31, 0x12C3B8u);
    ctx->pc = 0x12B898u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B898_0x12b898(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3B8u; }
    }
    if (ctx->pc != 0x12C3B8u) { return; }
    ctx->pc = 0x12C3B8u;
    // 0x12c3b8: 0xc04ae5a
    ctx->pc = 0x12C3B8u;
    SET_GPR_U32(ctx, 31, 0x12C3C0u);
    ctx->pc = 0x12B968u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012B968_0x12b968(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3C0u; }
    }
    if (ctx->pc != 0x12C3C0u) { return; }
    ctx->pc = 0x12C3C0u;
    // 0x12c3c0: 0xc04aec2
    ctx->pc = 0x12C3C0u;
    SET_GPR_U32(ctx, 31, 0x12C3C8u);
    ctx->pc = 0x12BB08u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BB08_0x12bb08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3C8u; }
    }
    if (ctx->pc != 0x12C3C8u) { return; }
    ctx->pc = 0x12C3C8u;
    // 0x12c3c8: 0xc04ae8e
    ctx->pc = 0x12C3C8u;
    SET_GPR_U32(ctx, 31, 0x12C3D0u);
    ctx->pc = 0x12BA38u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BA38_0x12ba38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3D0u; }
    }
    if (ctx->pc != 0x12C3D0u) { return; }
    ctx->pc = 0x12C3D0u;
    // 0x12c3d0: 0xc04aef6
    ctx->pc = 0x12C3D0u;
    SET_GPR_U32(ctx, 31, 0x12C3D8u);
    ctx->pc = 0x12BBD8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BBD8_0x12bbd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3D8u; }
    }
    if (ctx->pc != 0x12C3D8u) { return; }
    ctx->pc = 0x12C3D8u;
    // 0x12c3d8: 0xc04af2a
    ctx->pc = 0x12C3D8u;
    SET_GPR_U32(ctx, 31, 0x12C3E0u);
    ctx->pc = 0x12BCA8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0012BCA8_0x12bca8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3E0u; }
    }
    if (ctx->pc != 0x12C3E0u) { return; }
    ctx->pc = 0x12C3E0u;
    // 0x12c3e0: 0x3c020021
    ctx->pc = 0x12c3e0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x12c3e4: 0x3c030021
    ctx->pc = 0x12c3e4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)33 << 16));
    // 0x12c3e8: 0x244204e8
    ctx->pc = 0x12c3e8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1256));
    // 0x12c3ec: 0x8c657d78
    ctx->pc = 0x12c3ecu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 3), 32120)));
    // 0x12c3f0: 0xc04512c
    ctx->pc = 0x12C3F0u;
    SET_GPR_U32(ctx, 31, 0x12C3F8u);
    ctx->pc = 0x12C3F4u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    ctx->pc = 0x1144B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001144B0_0x1144b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C3F8u; }
    }
    if (ctx->pc != 0x12C3F8u) { return; }
    ctx->pc = 0x12C3F8u;
    // 0x12c3f8: 0x202d
    ctx->pc = 0x12c3f8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c3fc: 0xc05077c
    ctx->pc = 0x12C3FCu;
    SET_GPR_U32(ctx, 31, 0x12C404u);
    ctx->pc = 0x12C400u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x141DF0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00141DF0_0x141df0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C404u; }
    }
    if (ctx->pc != 0x12C404u) { return; }
    ctx->pc = 0x12C404u;
    // 0x12c404: 0x202d
    ctx->pc = 0x12c404u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c408: 0xc050782
    ctx->pc = 0x12C408u;
    SET_GPR_U32(ctx, 31, 0x12C410u);
    ctx->pc = 0x12C40Cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x141E08u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00141E08_0x141e08(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12C410u; }
    }
    if (ctx->pc != 0x12C410u) { return; }
    ctx->pc = 0x12C410u;
    // 0x12c410: 0x3c020021
    ctx->pc = 0x12c410u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x12c414: 0xdfbf0000
    ctx->pc = 0x12c414u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c418: 0x0
    ctx->pc = 0x12c418u;
    // NOP
    // 0x12c41c: 0x805084e
    ctx->pc = 0x12C41Cu;
    ctx->pc = 0x12C420u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x142138u;
    sub_00142138_0x142138(rdram, ctx, runtime); return;
    ctx->pc = 0x12C424u;
    // 0x12c424: 0x0
    ctx->pc = 0x12c424u;
    // NOP
label_12c428:
    // 0x12c428: 0xdfbf0000
    ctx->pc = 0x12c428u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c42c: 0x3e00008
    ctx->pc = 0x12C42Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12C430u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x12C040u: goto label_12c040;
            case 0x12C0ACu: goto label_12c0ac;
            case 0x12C108u: goto label_12c108;
            case 0x12C10Cu: goto label_12c10c;
            case 0x12C190u: goto label_12c190;
            case 0x12C280u: goto label_12c280;
            case 0x12C2C4u: goto label_12c2c4;
            case 0x12C360u: goto label_12c360;
            case 0x12C428u: goto label_12c428;
            default: break;
        }
        return;
    }
    ctx->pc = 0x12C434u;
    // 0x12c434: 0x0
    ctx->pc = 0x12c434u;
    // NOP
    // 0x12c438: 0x27bdfff0
    ctx->pc = 0x12c438u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c43c: 0x80302d
    ctx->pc = 0x12c43cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c440: 0xffbf0000
    ctx->pc = 0x12c440u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c444: 0xa0382d
    ctx->pc = 0x12c444u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c448: 0x24040001
    ctx->pc = 0x12c448u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    // 0x12c44c: 0x282d
    ctx->pc = 0x12c44cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c450: 0xdfbf0000
    ctx->pc = 0x12c450u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c454: 0x8050716
    ctx->pc = 0x12C454u;
    ctx->pc = 0x12C458u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x141C58u;
    sub_00141C58_0x141c58(rdram, ctx, runtime); return;
    ctx->pc = 0x12C45Cu;
    // 0x12c45c: 0x0
    ctx->pc = 0x12c45cu;
    // NOP
    // 0x12c460: 0x27bdfff0
    ctx->pc = 0x12c460u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c464: 0x80302d
    ctx->pc = 0x12c464u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c468: 0xffbf0000
    ctx->pc = 0x12c468u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c46c: 0xa0382d
    ctx->pc = 0x12c46cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c470: 0x24040007
    ctx->pc = 0x12c470u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 7));
    // 0x12c474: 0x282d
    ctx->pc = 0x12c474u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12c478: 0xdfbf0000
    ctx->pc = 0x12c478u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c47c: 0x8050716
    ctx->pc = 0x12C47Cu;
    ctx->pc = 0x12C480u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x141C58u;
    sub_00141C58_0x141c58(rdram, ctx, runtime); return;
    ctx->pc = 0x12C484u;
    // 0x12c484: 0x0
    ctx->pc = 0x12c484u;
    // NOP
    // 0x12c488: 0x27bdfff0
    ctx->pc = 0x12c488u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x12c48c: 0x24040007
    ctx->pc = 0x12c48cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 7));
    // 0x12c490: 0xffbf0000
    ctx->pc = 0x12c490u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12c494: 0xdfbf0000
    ctx->pc = 0x12c494u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12c498: 0x805075c
    ctx->pc = 0x12C498u;
    ctx->pc = 0x12C49Cu;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x141D70u;
    entry_141d70_0x141db0(rdram, ctx, runtime); return;
    ctx->pc = 0x12C4A0u;
}
