#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001A90B0
// Address: 0x1a90b0 - 0x1a9180
void sub_001A90B0_0x1a90b0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1a90b0u;

    // 0x1a90b0: 0x27bdfff0
    ctx->pc = 0x1a90b0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1a90b4: 0xffbf0000
    ctx->pc = 0x1a90b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x1a90b8: 0xc06b1c4
    ctx->pc = 0x1A90B8u;
    SET_GPR_U32(ctx, 31, 0x1A90C0u);
    ctx->pc = 0x1A90BCu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1AC710u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001AC710_0x1ac710(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A90C0u; }
    }
    if (ctx->pc != 0x1A90C0u) { return; }
    ctx->pc = 0x1A90C0u;
    // 0x1a90c0: 0x3c01002a
    ctx->pc = 0x1a90c0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a90c4: 0x8c23fa0c
    ctx->pc = 0x1a90c4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 4294965772)));
    // 0x1a90c8: 0x3c01002a
    ctx->pc = 0x1a90c8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a90cc: 0x8c22fa04
    ctx->pc = 0x1a90ccu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 4294965764)));
    // 0x1a90d0: 0x43082a
    ctx->pc = 0x1a90d0u;
    SET_GPR_U32(ctx, 1, SLT32(GPR_S32(ctx, 2), GPR_S32(ctx, 3)));
    // 0x1a90d4: 0x14200019
    ctx->pc = 0x1A90D4u;
    {
        const bool branch_taken_0x1a90d4 = (GPR_U32(ctx, 1) != GPR_U32(ctx, 0));
        ctx->pc = 0x1A90D8u;
        SET_GPR_U32(ctx, 1, ((uint32_t)4608 << 16));
        if (branch_taken_0x1a90d4) {
            ctx->pc = 0x1A913Cu;
            goto label_1a913c;
        }
    }
    ctx->pc = 0x1A90DCu;
    // 0x1a90dc: 0xdc221000
    ctx->pc = 0x1a90dcu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 1), 4096)));
    // 0x1a90e0: 0x2137a
    ctx->pc = 0x1a90e0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> 13);
    // 0x1a90e4: 0x3c01002a
    ctx->pc = 0x1a90e4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a90e8: 0x30420001
    ctx->pc = 0x1a90e8u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 1));
    // 0x1a90ec: 0x2103c
    ctx->pc = 0x1a90ecu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1a90f0: 0x2103f
    ctx->pc = 0x1a90f0u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1a90f4: 0xc06a41c
    ctx->pc = 0x1A90F4u;
    SET_GPR_U32(ctx, 31, 0x1A90FCu);
    ctx->pc = 0x1A90F8u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294965756), GPR_U32(ctx, 2));
    ctx->pc = 0x1A9070u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9070_0x1a9070(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A90FCu; }
    }
    if (ctx->pc != 0x1A90FCu) { return; }
    ctx->pc = 0x1A90FCu;
label_1a90fc:
    // 0x1a90fc: 0x3c01002b
    ctx->pc = 0x1a90fcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)43 << 16));
    // 0x1a9100: 0x8c220ec0
    ctx->pc = 0x1a9100u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 3776)));
    // 0x1a9104: 0x10400005
    ctx->pc = 0x1A9104u;
    {
        const bool branch_taken_0x1a9104 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1A9108u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1a9104) {
            ctx->pc = 0x1A911Cu;
            goto label_1a911c;
        }
    }
    ctx->pc = 0x1A910Cu;
    // 0x1a910c: 0xc057e94
    ctx->pc = 0x1A910Cu;
    SET_GPR_U32(ctx, 31, 0x1A9114u);
    ctx->pc = 0x15FA50u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FA50_0x15fa50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9114u; }
    }
    if (ctx->pc != 0x1A9114u) { return; }
    ctx->pc = 0x1A9114u;
    // 0x1a9114: 0x10000003
    ctx->pc = 0x1A9114u;
    {
        const bool branch_taken_0x1a9114 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1a9114) {
            ctx->pc = 0x1A9124u;
            goto label_1a9124;
        }
    }
    ctx->pc = 0x1A911Cu;
label_1a911c:
    // 0x1a911c: 0xc044cfc
    ctx->pc = 0x1A911Cu;
    SET_GPR_U32(ctx, 31, 0x1A9124u);
    ctx->pc = 0x1133F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001133F0_0x1133f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9124u; }
    }
    if (ctx->pc != 0x1A9124u) { return; }
    ctx->pc = 0x1A9124u;
label_1a9124:
    // 0x1a9124: 0x3c01002a
    ctx->pc = 0x1a9124u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x1a9128: 0x8c23fa10
    ctx->pc = 0x1a9128u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 1), 4294965776)));
    // 0x1a912c: 0x1460fff3
    ctx->pc = 0x1A912Cu;
    {
        const bool branch_taken_0x1a912c = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x1a912c) {
            ctx->pc = 0x1A90FCu;
            goto label_1a90fc;
        }
    }
    ctx->pc = 0x1A9134u;
    // 0x1a9134: 0x1000000e
    ctx->pc = 0x1A9134u;
    {
        const bool branch_taken_0x1a9134 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1A9138u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x1a9134) {
            ctx->pc = 0x1A9170u;
            goto label_1a9170;
        }
    }
    ctx->pc = 0x1A913Cu;
label_1a913c:
    // 0x1a913c: 0xc06a41c
    ctx->pc = 0x1A913Cu;
    SET_GPR_U32(ctx, 31, 0x1A9144u);
    ctx->pc = 0x1A9070u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001A9070_0x1a9070(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A9144u; }
    }
    if (ctx->pc != 0x1A9144u) { return; }
    ctx->pc = 0x1A9144u;
    // 0x1a9144: 0x3c01002b
    ctx->pc = 0x1a9144u;
    SET_GPR_U32(ctx, 1, ((uint32_t)43 << 16));
    // 0x1a9148: 0x8c220ec0
    ctx->pc = 0x1a9148u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 1), 3776)));
    // 0x1a914c: 0x10400005
    ctx->pc = 0x1A914Cu;
    {
        const bool branch_taken_0x1a914c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1A9150u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1a914c) {
            ctx->pc = 0x1A9164u;
            goto label_1a9164;
        }
    }
    ctx->pc = 0x1A9154u;
    // 0x1a9154: 0xc057e94
    ctx->pc = 0x1A9154u;
    SET_GPR_U32(ctx, 31, 0x1A915Cu);
    ctx->pc = 0x15FA50u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0015FA50_0x15fa50(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A915Cu; }
    }
    if (ctx->pc != 0x1A915Cu) { return; }
    ctx->pc = 0x1A915Cu;
    // 0x1a915c: 0x10000003
    ctx->pc = 0x1A915Cu;
    {
        const bool branch_taken_0x1a915c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1a915c) {
            ctx->pc = 0x1A916Cu;
            goto label_1a916c;
        }
    }
    ctx->pc = 0x1A9164u;
label_1a9164:
    // 0x1a9164: 0xc044cfc
    ctx->pc = 0x1A9164u;
    SET_GPR_U32(ctx, 31, 0x1A916Cu);
    ctx->pc = 0x1133F0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001133F0_0x1133f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1A916Cu; }
    }
    if (ctx->pc != 0x1A916Cu) { return; }
    ctx->pc = 0x1A916Cu;
label_1a916c:
    // 0x1a916c: 0xdfbf0000
    ctx->pc = 0x1a916cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1a9170:
    // 0x1a9170: 0x3e00008
    ctx->pc = 0x1A9170u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1A9174u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1A90FCu: goto label_1a90fc;
            case 0x1A911Cu: goto label_1a911c;
            case 0x1A9124u: goto label_1a9124;
            case 0x1A913Cu: goto label_1a913c;
            case 0x1A9164u: goto label_1a9164;
            case 0x1A916Cu: goto label_1a916c;
            case 0x1A9170u: goto label_1a9170;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1A9178u;
    // 0x1a9178: 0x0
    ctx->pc = 0x1a9178u;
    // NOP
    // 0x1a917c: 0x0
    ctx->pc = 0x1a917cu;
    // NOP
}
