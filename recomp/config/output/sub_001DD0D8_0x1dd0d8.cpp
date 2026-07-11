#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001DD0D8
// Address: 0x1dd0d8 - 0x1dd8e0
void sub_001DD0D8_0x1dd0d8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1dd0d8u;

    // 0x1dd0d8: 0x27bdff50
    ctx->pc = 0x1dd0d8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x1dd0dc: 0xffbe00a0
    ctx->pc = 0x1dd0dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 30));
    // 0x1dd0e0: 0xffbf00a8
    ctx->pc = 0x1dd0e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 168), GPR_U64(ctx, 31));
    // 0x1dd0e4: 0x3a0f02d
    ctx->pc = 0x1dd0e4u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd0e8: 0xafc40000
    ctx->pc = 0x1dd0e8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 0), GPR_U32(ctx, 4));
    // 0x1dd0ec: 0xafc00008
    ctx->pc = 0x1dd0ecu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 0));
    // 0x1dd0f0: 0x8fc30000
    ctx->pc = 0x1dd0f0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dd0f4: 0x24020001
    ctx->pc = 0x1dd0f4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1dd0f8: 0x14620009
    ctx->pc = 0x1DD0F8u;
    {
        const bool branch_taken_0x1dd0f8 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        if (branch_taken_0x1dd0f8) {
            ctx->pc = 0x1DD120u;
            goto label_1dd120;
        }
    }
    ctx->pc = 0x1DD100u;
    // 0x1dd100: 0x8fc20000
    ctx->pc = 0x1dd100u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dd104: 0x21880
    ctx->pc = 0x1dd104u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 2));
    // 0x1dd108: 0x3c020026
    ctx->pc = 0x1dd108u;
    SET_GPR_U32(ctx, 2, ((uint32_t)38 << 16));
    // 0x1dd10c: 0x24429d08
    ctx->pc = 0x1dd10cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1dd110: 0x431021
    ctx->pc = 0x1dd110u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dd114: 0x8c420000
    ctx->pc = 0x1dd114u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dd118: 0x14400004
    ctx->pc = 0x1DD118u;
    {
        const bool branch_taken_0x1dd118 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1dd118) {
            ctx->pc = 0x1DD12Cu;
            goto label_1dd12c;
        }
    }
    ctx->pc = 0x1DD120u;
label_1dd120:
    // 0x1dd120: 0x2402ffff
    ctx->pc = 0x1dd120u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x1dd124: 0x100001e7
    ctx->pc = 0x1DD124u;
    {
        const bool branch_taken_0x1dd124 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd124) {
            ctx->pc = 0x1DD8C4u;
            goto label_1dd8c4;
        }
    }
    ctx->pc = 0x1DD12Cu;
label_1dd12c:
    // 0x1dd12c: 0x8fc20000
    ctx->pc = 0x1dd12cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 0)));
    // 0x1dd130: 0x21880
    ctx->pc = 0x1dd130u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 2));
    // 0x1dd134: 0x3c020026
    ctx->pc = 0x1dd134u;
    SET_GPR_U32(ctx, 2, ((uint32_t)38 << 16));
    // 0x1dd138: 0x24429d08
    ctx->pc = 0x1dd138u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294941960));
    // 0x1dd13c: 0x431021
    ctx->pc = 0x1dd13cu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dd140: 0x8c420000
    ctx->pc = 0x1dd140u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dd144: 0xafc20004
    ctx->pc = 0x1dd144u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 4), GPR_U32(ctx, 2));
    // 0x1dd148: 0x27c20030
    ctx->pc = 0x1dd148u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 30), 48));
    // 0x1dd14c: 0xafc20070
    ctx->pc = 0x1dd14cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 112), GPR_U32(ctx, 2));
    // 0x1dd150: 0xafc0006c
    ctx->pc = 0x1dd150u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 108), GPR_U32(ctx, 0));
label_1dd154:
    // 0x1dd154: 0x8fc2006c
    ctx->pc = 0x1dd154u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 108)));
    // 0x1dd158: 0x2c420008
    ctx->pc = 0x1dd158u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 2), 8));
    // 0x1dd15c: 0x14400003
    ctx->pc = 0x1DD15Cu;
    {
        const bool branch_taken_0x1dd15c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1dd15c) {
            ctx->pc = 0x1DD16Cu;
            goto label_1dd16c;
        }
    }
    ctx->pc = 0x1DD164u;
    // 0x1dd164: 0x1000000b
    ctx->pc = 0x1DD164u;
    {
        const bool branch_taken_0x1dd164 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd164) {
            ctx->pc = 0x1DD194u;
            goto label_1dd194;
        }
    }
    ctx->pc = 0x1DD16Cu;
label_1dd16c:
    // 0x1dd16c: 0x27c30070
    ctx->pc = 0x1dd16cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 30), 112));
    // 0x1dd170: 0x8c620000
    ctx->pc = 0x1dd170u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1dd174: 0xa0400000
    ctx->pc = 0x1dd174u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1dd178: 0x24420001
    ctx->pc = 0x1dd178u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x1dd17c: 0xac620000
    ctx->pc = 0x1dd17cu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1dd180: 0x8fc2006c
    ctx->pc = 0x1dd180u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 108)));
    // 0x1dd184: 0x24420001
    ctx->pc = 0x1dd184u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x1dd188: 0xafc2006c
    ctx->pc = 0x1dd188u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 108), GPR_U32(ctx, 2));
    // 0x1dd18c: 0x1000fff1
    ctx->pc = 0x1DD18Cu;
    {
        const bool branch_taken_0x1dd18c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd18c) {
            ctx->pc = 0x1DD154u;
            goto label_1dd154;
        }
    }
    ctx->pc = 0x1DD194u;
label_1dd194:
    // 0x1dd194: 0x27c20038
    ctx->pc = 0x1dd194u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 30), 56));
    // 0x1dd198: 0xafc2006c
    ctx->pc = 0x1dd198u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 108), GPR_U32(ctx, 2));
    // 0x1dd19c: 0xafc00070
    ctx->pc = 0x1dd19cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 112), GPR_U32(ctx, 0));
label_1dd1a0:
    // 0x1dd1a0: 0x8fc20070
    ctx->pc = 0x1dd1a0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 112)));
    // 0x1dd1a4: 0x2c420008
    ctx->pc = 0x1dd1a4u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 2), 8));
    // 0x1dd1a8: 0x14400003
    ctx->pc = 0x1DD1A8u;
    {
        const bool branch_taken_0x1dd1a8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1dd1a8) {
            ctx->pc = 0x1DD1B8u;
            goto label_1dd1b8;
        }
    }
    ctx->pc = 0x1DD1B0u;
    // 0x1dd1b0: 0x1000000b
    ctx->pc = 0x1DD1B0u;
    {
        const bool branch_taken_0x1dd1b0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd1b0) {
            ctx->pc = 0x1DD1E0u;
            goto label_1dd1e0;
        }
    }
    ctx->pc = 0x1DD1B8u;
label_1dd1b8:
    // 0x1dd1b8: 0x27c3006c
    ctx->pc = 0x1dd1b8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 30), 108));
    // 0x1dd1bc: 0x8c620000
    ctx->pc = 0x1dd1bcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1dd1c0: 0xa0400000
    ctx->pc = 0x1dd1c0u;
    WRITE8(ADD32(GPR_U32(ctx, 2), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1dd1c4: 0x24420001
    ctx->pc = 0x1dd1c4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x1dd1c8: 0xac620000
    ctx->pc = 0x1dd1c8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x1dd1cc: 0x8fc20070
    ctx->pc = 0x1dd1ccu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 112)));
    // 0x1dd1d0: 0x24420001
    ctx->pc = 0x1dd1d0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x1dd1d4: 0xafc20070
    ctx->pc = 0x1dd1d4u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 112), GPR_U32(ctx, 2));
    // 0x1dd1d8: 0x1000fff1
    ctx->pc = 0x1DD1D8u;
    {
        const bool branch_taken_0x1dd1d8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd1d8) {
            ctx->pc = 0x1DD1A0u;
            goto label_1dd1a0;
        }
    }
    ctx->pc = 0x1DD1E0u;
label_1dd1e0:
    // 0x1dd1e0: 0x8fc20004
    ctx->pc = 0x1dd1e0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd1e4: 0x8c420004
    ctx->pc = 0x1dd1e4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1dd1e8: 0x22182
    ctx->pc = 0x1dd1e8u;
    SET_GPR_U32(ctx, 4, SRL32(GPR_U32(ctx, 2), 6));
    // 0x1dd1ec: 0x80102d
    ctx->pc = 0x1dd1ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd1f0: 0x218c0
    ctx->pc = 0x1dd1f0u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 3));
    // 0x1dd1f4: 0x27c20030
    ctx->pc = 0x1dd1f4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 30), 48));
    // 0x1dd1f8: 0x432821
    ctx->pc = 0x1dd1f8u;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dd1fc: 0x80102d
    ctx->pc = 0x1dd1fcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd200: 0x218c0
    ctx->pc = 0x1dd200u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 3));
    // 0x1dd204: 0x27c20030
    ctx->pc = 0x1dd204u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 30), 48));
    // 0x1dd208: 0x432021
    ctx->pc = 0x1dd208u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dd20c: 0x8fc20004
    ctx->pc = 0x1dd20cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd210: 0x8c420004
    ctx->pc = 0x1dd210u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1dd214: 0x3043003f
    ctx->pc = 0x1dd214u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 2), 63));
    // 0x1dd218: 0x24020001
    ctx->pc = 0x1dd218u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1dd21c: 0x621814
    ctx->pc = 0x1dd21cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (GPR_U32(ctx, 3) & 0x3F));
    // 0x1dd220: 0xdc820000
    ctx->pc = 0x1dd220u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1dd224: 0x431025
    ctx->pc = 0x1dd224u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dd228: 0xfca20000
    ctx->pc = 0x1dd228u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 2));
    // 0x1dd22c: 0xffc00020
    ctx->pc = 0x1dd22cu;
    WRITE64(ADD32(GPR_U32(ctx, 30), 32), GPR_U64(ctx, 0));
    // 0x1dd230: 0xffc00028
    ctx->pc = 0x1dd230u;
    WRITE64(ADD32(GPR_U32(ctx, 30), 40), GPR_U64(ctx, 0));
    // 0x1dd234: 0xc076c7f
    ctx->pc = 0x1DD234u;
    SET_GPR_U32(ctx, 31, 0x1DD23Cu);
    ctx->pc = 0x1DB1FCu;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB1FC_0x1db1fc(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD23Cu; }
    }
    if (ctx->pc != 0x1DD23Cu) { return; }
    ctx->pc = 0x1DD23Cu;
    // 0x1dd23c: 0xafc20050
    ctx->pc = 0x1dd23cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 80), GPR_U32(ctx, 2));
    // 0x1dd240: 0x8fc30004
    ctx->pc = 0x1dd240u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd244: 0x8fc20050
    ctx->pc = 0x1dd244u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 80)));
    // 0x1dd248: 0xac6204fc
    ctx->pc = 0x1dd248u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1276), GPR_U32(ctx, 2));
    // 0x1dd24c: 0x8fc40004
    ctx->pc = 0x1dd24cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd250: 0xc0773cd
    ctx->pc = 0x1DD250u;
    SET_GPR_U32(ctx, 31, 0x1DD258u);
    ctx->pc = 0x1DCF34u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001DCF34_0x1dcf34(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD258u; }
    }
    if (ctx->pc != 0x1DD258u) { return; }
    ctx->pc = 0x1DD258u;
    // 0x1dd258: 0x8fc20004
    ctx->pc = 0x1dd258u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd25c: 0x8c42050c
    ctx->pc = 0x1dd25cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1dd260: 0x10400008
    ctx->pc = 0x1DD260u;
    {
        const bool branch_taken_0x1dd260 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd260) {
            ctx->pc = 0x1DD284u;
            goto label_1dd284;
        }
    }
    ctx->pc = 0x1DD268u;
    // 0x1dd268: 0x8fc20004
    ctx->pc = 0x1dd268u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd26c: 0x8c42050c
    ctx->pc = 0x1dd26cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1dd270: 0x3c010026
    ctx->pc = 0x1dd270u;
    SET_GPR_U32(ctx, 1, ((uint32_t)38 << 16));
    // 0x1dd274: 0xac229d10
    ctx->pc = 0x1dd274u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294941968), GPR_U32(ctx, 2));
    // 0x1dd278: 0x24020027
    ctx->pc = 0x1dd278u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 39));
    // 0x1dd27c: 0x10000191
    ctx->pc = 0x1DD27Cu;
    {
        const bool branch_taken_0x1dd27c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd27c) {
            ctx->pc = 0x1DD8C4u;
            goto label_1dd8c4;
        }
    }
    ctx->pc = 0x1DD284u;
label_1dd284:
    // 0x1dd284: 0x8fc20004
    ctx->pc = 0x1dd284u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd288: 0x8c420004
    ctx->pc = 0x1dd288u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1dd28c: 0x2442000a
    ctx->pc = 0x1dd28cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 10));
    // 0x1dd290: 0xafc2004c
    ctx->pc = 0x1dd290u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 76), GPR_U32(ctx, 2));
    // 0x1dd294: 0x8fc20004
    ctx->pc = 0x1dd294u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd298: 0x8c420060
    ctx->pc = 0x1dd298u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1dd29c: 0x24420008
    ctx->pc = 0x1dd29cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 8));
    // 0x1dd2a0: 0x40202d
    ctx->pc = 0x1dd2a0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd2a4: 0xc07c441
    ctx->pc = 0x1DD2A4u;
    SET_GPR_U32(ctx, 31, 0x1DD2ACu);
    ctx->pc = 0x1F1104u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1104_0x1f1104(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD2ACu; }
    }
    if (ctx->pc != 0x1DD2ACu) { return; }
    ctx->pc = 0x1DD2ACu;
    // 0x1dd2ac: 0x1040004f
    ctx->pc = 0x1DD2ACu;
    {
        const bool branch_taken_0x1dd2ac = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd2ac) {
            ctx->pc = 0x1DD3ECu;
            goto label_1dd3ec;
        }
    }
    ctx->pc = 0x1DD2B4u;
    // 0x1dd2b4: 0x8fc30004
    ctx->pc = 0x1dd2b4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd2b8: 0x8fc20004
    ctx->pc = 0x1dd2b8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd2bc: 0x8c420538
    ctx->pc = 0x1dd2bcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 1336)));
    // 0x1dd2c0: 0x24420001
    ctx->pc = 0x1dd2c0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x1dd2c4: 0xac620538
    ctx->pc = 0x1dd2c4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1336), GPR_U32(ctx, 2));
    // 0x1dd2c8: 0x8fc20004
    ctx->pc = 0x1dd2c8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd2cc: 0x8c420060
    ctx->pc = 0x1dd2ccu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1dd2d0: 0x24420008
    ctx->pc = 0x1dd2d0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 8));
    // 0x1dd2d4: 0x40202d
    ctx->pc = 0x1dd2d4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd2d8: 0xc07c6e1
    ctx->pc = 0x1DD2D8u;
    SET_GPR_U32(ctx, 31, 0x1DD2E0u);
    ctx->pc = 0x1F1B84u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1B84_0x1f1b84(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD2E0u; }
    }
    if (ctx->pc != 0x1DD2E0u) { return; }
    ctx->pc = 0x1DD2E0u;
    // 0x1dd2e0: 0xafc20054
    ctx->pc = 0x1dd2e0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 84), GPR_U32(ctx, 2));
    // 0x1dd2e4: 0x8fc40054
    ctx->pc = 0x1dd2e4u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 30), 84)));
    // 0x1dd2e8: 0x24051000
    ctx->pc = 0x1dd2e8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4096));
    // 0x1dd2ec: 0xc07c670
    ctx->pc = 0x1DD2ECu;
    SET_GPR_U32(ctx, 31, 0x1DD2F4u);
    ctx->pc = 0x1F19C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001F19C0_0x1f19c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD2F4u; }
    }
    if (ctx->pc != 0x1DD2F4u) { return; }
    ctx->pc = 0x1DD2F4u;
    // 0x1dd2f4: 0x14400017
    ctx->pc = 0x1DD2F4u;
    {
        const bool branch_taken_0x1dd2f4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1dd2f4) {
            ctx->pc = 0x1DD354u;
            goto label_1dd354;
        }
    }
    ctx->pc = 0x1DD2FCu;
    // 0x1dd2fc: 0x8fc20004
    ctx->pc = 0x1dd2fcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd300: 0x8c430060
    ctx->pc = 0x1dd300u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1dd304: 0x8fc20004
    ctx->pc = 0x1dd304u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd308: 0x8c420060
    ctx->pc = 0x1dd308u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 96)));
    // 0x1dd30c: 0x8c630000
    ctx->pc = 0x1dd30cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1dd310: 0x8c420004
    ctx->pc = 0x1dd310u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1dd314: 0x621821
    ctx->pc = 0x1dd314u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dd318: 0x8fc20050
    ctx->pc = 0x1dd318u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 80)));
    // 0x1dd31c: 0x62102b
    ctx->pc = 0x1dd31cu;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dd320: 0x1040002b
    ctx->pc = 0x1DD320u;
    {
        const bool branch_taken_0x1dd320 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd320) {
            ctx->pc = 0x1DD3D0u;
            goto label_1dd3d0;
        }
    }
    ctx->pc = 0x1DD328u;
    // 0x1dd328: 0x8fc20004
    ctx->pc = 0x1dd328u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd32c: 0x8c420058
    ctx->pc = 0x1dd32cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 88)));
    // 0x1dd330: 0x24420008
    ctx->pc = 0x1dd330u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 8));
    // 0x1dd334: 0x40202d
    ctx->pc = 0x1dd334u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd338: 0xc07c441
    ctx->pc = 0x1DD338u;
    SET_GPR_U32(ctx, 31, 0x1DD340u);
    ctx->pc = 0x1F1104u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1104_0x1f1104(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD340u; }
    }
    if (ctx->pc != 0x1DD340u) { return; }
    ctx->pc = 0x1DD340u;
    // 0x1dd340: 0x2c42000a
    ctx->pc = 0x1dd340u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 2), 10));
    // 0x1dd344: 0x14400003
    ctx->pc = 0x1DD344u;
    {
        const bool branch_taken_0x1dd344 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1dd344) {
            ctx->pc = 0x1DD354u;
            goto label_1dd354;
        }
    }
    ctx->pc = 0x1DD34Cu;
    // 0x1dd34c: 0x10000020
    ctx->pc = 0x1DD34Cu;
    {
        const bool branch_taken_0x1dd34c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd34c) {
            ctx->pc = 0x1DD3D0u;
            goto label_1dd3d0;
        }
    }
    ctx->pc = 0x1DD354u;
label_1dd354:
    // 0x1dd354: 0x8fc20004
    ctx->pc = 0x1dd354u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd358: 0x8fc3004c
    ctx->pc = 0x1dd358u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 76)));
    // 0x1dd35c: 0x8c420000
    ctx->pc = 0x1dd35cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dd360: 0x43102b
    ctx->pc = 0x1dd360u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dd364: 0x14400005
    ctx->pc = 0x1DD364u;
    {
        const bool branch_taken_0x1dd364 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1dd364) {
            ctx->pc = 0x1DD37Cu;
            goto label_1dd37c;
        }
    }
    ctx->pc = 0x1DD36Cu;
    // 0x1dd36c: 0x8fc20004
    ctx->pc = 0x1dd36cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd370: 0x8c420000
    ctx->pc = 0x1dd370u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dd374: 0x24420001
    ctx->pc = 0x1dd374u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x1dd378: 0xafc2004c
    ctx->pc = 0x1dd378u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 76), GPR_U32(ctx, 2));
label_1dd37c:
    // 0x1dd37c: 0x8fc20004
    ctx->pc = 0x1dd37cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd380: 0x8c420000
    ctx->pc = 0x1dd380u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dd384: 0x22182
    ctx->pc = 0x1dd384u;
    SET_GPR_U32(ctx, 4, SRL32(GPR_U32(ctx, 2), 6));
    // 0x1dd388: 0x80102d
    ctx->pc = 0x1dd388u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd38c: 0x218c0
    ctx->pc = 0x1dd38cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 3));
    // 0x1dd390: 0x27c20038
    ctx->pc = 0x1dd390u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 30), 56));
    // 0x1dd394: 0x432821
    ctx->pc = 0x1dd394u;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dd398: 0x80102d
    ctx->pc = 0x1dd398u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd39c: 0x218c0
    ctx->pc = 0x1dd39cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 3));
    // 0x1dd3a0: 0x27c20038
    ctx->pc = 0x1dd3a0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 30), 56));
    // 0x1dd3a4: 0x432021
    ctx->pc = 0x1dd3a4u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dd3a8: 0x8fc20004
    ctx->pc = 0x1dd3a8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd3ac: 0x8c420000
    ctx->pc = 0x1dd3acu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dd3b0: 0x3043003f
    ctx->pc = 0x1dd3b0u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 2), 63));
    // 0x1dd3b4: 0x24020001
    ctx->pc = 0x1dd3b4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1dd3b8: 0x621814
    ctx->pc = 0x1dd3b8u;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 2) << (GPR_U32(ctx, 3) & 0x3F));
    // 0x1dd3bc: 0xdc820000
    ctx->pc = 0x1dd3bcu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1dd3c0: 0x431025
    ctx->pc = 0x1dd3c0u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dd3c4: 0xfca20000
    ctx->pc = 0x1dd3c4u;
    WRITE64(ADD32(GPR_U32(ctx, 5), 0), GPR_U64(ctx, 2));
    // 0x1dd3c8: 0x1000000d
    ctx->pc = 0x1DD3C8u;
    {
        const bool branch_taken_0x1dd3c8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd3c8) {
            ctx->pc = 0x1DD400u;
            goto label_1dd400;
        }
    }
    ctx->pc = 0x1DD3D0u;
label_1dd3d0:
    // 0x1dd3d0: 0x8fc30004
    ctx->pc = 0x1dd3d0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd3d4: 0x8fc20004
    ctx->pc = 0x1dd3d4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd3d8: 0x8c42053c
    ctx->pc = 0x1dd3d8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 1340)));
    // 0x1dd3dc: 0x24420001
    ctx->pc = 0x1dd3dcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x1dd3e0: 0xac62053c
    ctx->pc = 0x1dd3e0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1340), GPR_U32(ctx, 2));
    // 0x1dd3e4: 0x10000006
    ctx->pc = 0x1DD3E4u;
    {
        const bool branch_taken_0x1dd3e4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd3e4) {
            ctx->pc = 0x1DD400u;
            goto label_1dd400;
        }
    }
    ctx->pc = 0x1DD3ECu;
label_1dd3ec:
    // 0x1dd3ec: 0x8fc30004
    ctx->pc = 0x1dd3ecu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd3f0: 0x8fc20004
    ctx->pc = 0x1dd3f0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd3f4: 0x8c420540
    ctx->pc = 0x1dd3f4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 1344)));
    // 0x1dd3f8: 0x24420001
    ctx->pc = 0x1dd3f8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x1dd3fc: 0xac620540
    ctx->pc = 0x1dd3fcu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1344), GPR_U32(ctx, 2));
label_1dd400:
    // 0x1dd400: 0x27c20030
    ctx->pc = 0x1dd400u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 30), 48));
    // 0x1dd404: 0x27c30038
    ctx->pc = 0x1dd404u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 30), 56));
    // 0x1dd408: 0x27c80020
    ctx->pc = 0x1dd408u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 30), 32));
    // 0x1dd40c: 0x8fc4004c
    ctx->pc = 0x1dd40cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 30), 76)));
    // 0x1dd410: 0x40282d
    ctx->pc = 0x1dd410u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd414: 0x60302d
    ctx->pc = 0x1dd414u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd418: 0x382d
    ctx->pc = 0x1dd418u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd41c: 0xc07a676
    ctx->pc = 0x1DD41Cu;
    SET_GPR_U32(ctx, 31, 0x1DD424u);
    ctx->pc = 0x1E99D8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001E99D8_0x1e99d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD424u; }
    }
    if (ctx->pc != 0x1DD424u) { return; }
    ctx->pc = 0x1DD424u;
    // 0x1dd424: 0xafc20040
    ctx->pc = 0x1dd424u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 2));
label_1dd428:
    // 0x1dd428: 0x8fc20040
    ctx->pc = 0x1dd428u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 64)));
    // 0x1dd42c: 0x1c400003
    ctx->pc = 0x1DD42Cu;
    {
        const bool branch_taken_0x1dd42c = (GPR_S32(ctx, 2) > 0);
        if (branch_taken_0x1dd42c) {
            ctx->pc = 0x1DD43Cu;
            goto label_1dd43c;
        }
    }
    ctx->pc = 0x1DD434u;
    // 0x1dd434: 0x100000e7
    ctx->pc = 0x1DD434u;
    {
        const bool branch_taken_0x1dd434 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd434) {
            ctx->pc = 0x1DD7D4u;
            goto label_1dd7d4;
        }
    }
    ctx->pc = 0x1DD43Cu;
label_1dd43c:
    // 0x1dd43c: 0xafc00040
    ctx->pc = 0x1dd43cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 64), GPR_U32(ctx, 0));
    // 0x1dd440: 0x8fc20004
    ctx->pc = 0x1dd440u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd444: 0x8c420000
    ctx->pc = 0x1dd444u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dd448: 0x21182
    ctx->pc = 0x1dd448u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 6));
    // 0x1dd44c: 0x218c0
    ctx->pc = 0x1dd44cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 3));
    // 0x1dd450: 0x27c20038
    ctx->pc = 0x1dd450u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 30), 56));
    // 0x1dd454: 0x432021
    ctx->pc = 0x1dd454u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dd458: 0x8fc20004
    ctx->pc = 0x1dd458u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd45c: 0x8c420000
    ctx->pc = 0x1dd45cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1dd460: 0x3043003f
    ctx->pc = 0x1dd460u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 2), 63));
    // 0x1dd464: 0xdc820000
    ctx->pc = 0x1dd464u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1dd468: 0x621817
    ctx->pc = 0x1dd468u;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 2) >> (GPR_U32(ctx, 3) & 0x3F));
    // 0x1dd46c: 0x24020001
    ctx->pc = 0x1dd46cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1dd470: 0x621024
    ctx->pc = 0x1dd470u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dd474: 0x2103c
    ctx->pc = 0x1dd474u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1dd478: 0x2103f
    ctx->pc = 0x1dd478u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1dd47c: 0x10400015
    ctx->pc = 0x1DD47Cu;
    {
        const bool branch_taken_0x1dd47c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd47c) {
            ctx->pc = 0x1DD4D4u;
            goto label_1dd4d4;
        }
    }
    ctx->pc = 0x1DD484u;
    // 0x1dd484: 0x8fc30004
    ctx->pc = 0x1dd484u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd488: 0x8fc20004
    ctx->pc = 0x1dd488u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd48c: 0x8c420544
    ctx->pc = 0x1dd48cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 1348)));
    // 0x1dd490: 0x24420001
    ctx->pc = 0x1dd490u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x1dd494: 0xac620544
    ctx->pc = 0x1dd494u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1348), GPR_U32(ctx, 2));
    // 0x1dd498: 0x8fc40004
    ctx->pc = 0x1dd498u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd49c: 0x8fc50050
    ctx->pc = 0x1dd49cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 30), 80)));
    // 0x1dd4a0: 0xc0770a6
    ctx->pc = 0x1DD4A0u;
    SET_GPR_U32(ctx, 31, 0x1DD4A8u);
    ctx->pc = 0x1DC298u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001DC298_0x1dc298(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD4A8u; }
    }
    if (ctx->pc != 0x1DD4A8u) { return; }
    ctx->pc = 0x1DD4A8u;
    // 0x1dd4a8: 0x8fc20004
    ctx->pc = 0x1dd4a8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd4ac: 0x8c42050c
    ctx->pc = 0x1dd4acu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1dd4b0: 0x10400008
    ctx->pc = 0x1DD4B0u;
    {
        const bool branch_taken_0x1dd4b0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd4b0) {
            ctx->pc = 0x1DD4D4u;
            goto label_1dd4d4;
        }
    }
    ctx->pc = 0x1DD4B8u;
    // 0x1dd4b8: 0x8fc20004
    ctx->pc = 0x1dd4b8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd4bc: 0x8c42050c
    ctx->pc = 0x1dd4bcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1dd4c0: 0x3c010026
    ctx->pc = 0x1dd4c0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)38 << 16));
    // 0x1dd4c4: 0xac229d10
    ctx->pc = 0x1dd4c4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294941968), GPR_U32(ctx, 2));
    // 0x1dd4c8: 0x24020027
    ctx->pc = 0x1dd4c8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 39));
    // 0x1dd4cc: 0x100000fd
    ctx->pc = 0x1DD4CCu;
    {
        const bool branch_taken_0x1dd4cc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd4cc) {
            ctx->pc = 0x1DD8C4u;
            goto label_1dd8c4;
        }
    }
    ctx->pc = 0x1DD4D4u;
label_1dd4d4:
    // 0x1dd4d4: 0x8fc20004
    ctx->pc = 0x1dd4d4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd4d8: 0x8c420004
    ctx->pc = 0x1dd4d8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1dd4dc: 0x21182
    ctx->pc = 0x1dd4dcu;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 6));
    // 0x1dd4e0: 0x218c0
    ctx->pc = 0x1dd4e0u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 3));
    // 0x1dd4e4: 0x27c20030
    ctx->pc = 0x1dd4e4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 30), 48));
    // 0x1dd4e8: 0x432021
    ctx->pc = 0x1dd4e8u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1dd4ec: 0x8fc20004
    ctx->pc = 0x1dd4ecu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd4f0: 0x8c420004
    ctx->pc = 0x1dd4f0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1dd4f4: 0x3043003f
    ctx->pc = 0x1dd4f4u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 2), 63));
    // 0x1dd4f8: 0xdc820000
    ctx->pc = 0x1dd4f8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1dd4fc: 0x621817
    ctx->pc = 0x1dd4fcu;
    SET_GPR_S64(ctx, 3, GPR_S64(ctx, 2) >> (GPR_U32(ctx, 3) & 0x3F));
    // 0x1dd500: 0x24020001
    ctx->pc = 0x1dd500u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1dd504: 0x621024
    ctx->pc = 0x1dd504u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dd508: 0x2103c
    ctx->pc = 0x1dd508u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x1dd50c: 0x2103f
    ctx->pc = 0x1dd50cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1dd510: 0x104000a9
    ctx->pc = 0x1DD510u;
    {
        const bool branch_taken_0x1dd510 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd510) {
            ctx->pc = 0x1DD7B8u;
            goto label_1dd7b8;
        }
    }
    ctx->pc = 0x1DD518u;
    // 0x1dd518: 0x8fc30004
    ctx->pc = 0x1dd518u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd51c: 0x8fc20004
    ctx->pc = 0x1dd51cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd520: 0x8c420524
    ctx->pc = 0x1dd520u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 1316)));
    // 0x1dd524: 0x24420001
    ctx->pc = 0x1dd524u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x1dd528: 0xac620524
    ctx->pc = 0x1dd528u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1316), GPR_U32(ctx, 2));
    // 0x1dd52c: 0x8fc20004
    ctx->pc = 0x1dd52cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd530: 0x27c30064
    ctx->pc = 0x1dd530u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 30), 100));
    // 0x1dd534: 0x8c440004
    ctx->pc = 0x1dd534u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1dd538: 0x3c057104
    ctx->pc = 0x1dd538u;
    SET_GPR_U32(ctx, 5, ((uint32_t)28932 << 16));
    // 0x1dd53c: 0x34a55ead
    ctx->pc = 0x1dd53cu;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 24237));
    // 0x1dd540: 0x60302d
    ctx->pc = 0x1dd540u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd544: 0xc07a7b8
    ctx->pc = 0x1DD544u;
    SET_GPR_U32(ctx, 31, 0x1DD54Cu);
    ctx->pc = 0x1E9EE0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001E9EE0_0x1e9ee0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD54Cu; }
    }
    if (ctx->pc != 0x1DD54Cu) { return; }
    ctx->pc = 0x1DD54Cu;
    // 0x1dd54c: 0xafc20068
    ctx->pc = 0x1dd54cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 104), GPR_U32(ctx, 2));
    // 0x1dd550: 0x8fc20068
    ctx->pc = 0x1dd550u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 104)));
    // 0x1dd554: 0x10400003
    ctx->pc = 0x1DD554u;
    {
        const bool branch_taken_0x1dd554 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd554) {
            ctx->pc = 0x1DD564u;
            goto label_1dd564;
        }
    }
    ctx->pc = 0x1DD55Cu;
    // 0x1dd55c: 0x24020380
    ctx->pc = 0x1dd55cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 896));
    // 0x1dd560: 0xafc20064
    ctx->pc = 0x1dd560u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 100), GPR_U32(ctx, 2));
label_1dd564:
    // 0x1dd564: 0x8fc20064
    ctx->pc = 0x1dd564u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 100)));
    // 0x1dd568: 0x28420381
    ctx->pc = 0x1dd568u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 2), 897));
    // 0x1dd56c: 0x14400003
    ctx->pc = 0x1DD56Cu;
    {
        const bool branch_taken_0x1dd56c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1dd56c) {
            ctx->pc = 0x1DD57Cu;
            goto label_1dd57c;
        }
    }
    ctx->pc = 0x1DD574u;
    // 0x1dd574: 0x24020380
    ctx->pc = 0x1dd574u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 896));
    // 0x1dd578: 0xafc20064
    ctx->pc = 0x1dd578u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 100), GPR_U32(ctx, 2));
label_1dd57c:
    // 0x1dd57c: 0x8fc20004
    ctx->pc = 0x1dd57cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd580: 0x27c30008
    ctx->pc = 0x1dd580u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 30), 8));
    // 0x1dd584: 0x97c60064
    ctx->pc = 0x1dd584u;
    SET_GPR_U32(ctx, 6, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 100)));
    // 0x1dd588: 0x8c440520
    ctx->pc = 0x1dd588u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1dd58c: 0x60282d
    ctx->pc = 0x1dd58cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd590: 0x24070001
    ctx->pc = 0x1dd590u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1dd594: 0x402d
    ctx->pc = 0x1dd594u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd598: 0xc07c80a
    ctx->pc = 0x1DD598u;
    SET_GPR_U32(ctx, 31, 0x1DD5A0u);
    ctx->pc = 0x1F2028u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2028_0x1f2028(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD5A0u; }
    }
    if (ctx->pc != 0x1DD5A0u) { return; }
    ctx->pc = 0x1DD5A0u;
    // 0x1dd5a0: 0xafc20068
    ctx->pc = 0x1dd5a0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 104), GPR_U32(ctx, 2));
    // 0x1dd5a4: 0x8fc20068
    ctx->pc = 0x1dd5a4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 104)));
    // 0x1dd5a8: 0x10400008
    ctx->pc = 0x1DD5A8u;
    {
        const bool branch_taken_0x1dd5a8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd5a8) {
            ctx->pc = 0x1DD5CCu;
            goto label_1dd5cc;
        }
    }
    ctx->pc = 0x1DD5B0u;
    // 0x1dd5b0: 0x8fc30004
    ctx->pc = 0x1dd5b0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd5b4: 0x8fc20004
    ctx->pc = 0x1dd5b4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd5b8: 0x8c420528
    ctx->pc = 0x1dd5b8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 1320)));
    // 0x1dd5bc: 0x24420001
    ctx->pc = 0x1dd5bcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x1dd5c0: 0xac620528
    ctx->pc = 0x1dd5c0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1320), GPR_U32(ctx, 2));
    // 0x1dd5c4: 0x10000083
    ctx->pc = 0x1DD5C4u;
    {
        const bool branch_taken_0x1dd5c4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd5c4) {
            ctx->pc = 0x1DD7D4u;
            goto label_1dd7d4;
        }
    }
    ctx->pc = 0x1DD5CCu;
label_1dd5cc:
    // 0x1dd5cc: 0x24020010
    ctx->pc = 0x1dd5ccu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 16));
    // 0x1dd5d0: 0xafc20048
    ctx->pc = 0x1dd5d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 72), GPR_U32(ctx, 2));
    // 0x1dd5d4: 0x8fc40008
    ctx->pc = 0x1dd5d4u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dd5d8: 0xc07cd47
    ctx->pc = 0x1DD5D8u;
    SET_GPR_U32(ctx, 31, 0x1DD5E0u);
    ctx->pc = 0x1F351Cu;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001F351C_0x1f351c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD5E0u; }
    }
    if (ctx->pc != 0x1DD5E0u) { return; }
    ctx->pc = 0x1DD5E0u;
    // 0x1dd5e0: 0x40302d
    ctx->pc = 0x1dd5e0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd5e4: 0x8fc30004
    ctx->pc = 0x1dd5e4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd5e8: 0x8fc20008
    ctx->pc = 0x1dd5e8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dd5ec: 0x2442002c
    ctx->pc = 0x1dd5ecu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 44));
    // 0x1dd5f0: 0x27c80010
    ctx->pc = 0x1dd5f0u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 30), 16));
    // 0x1dd5f4: 0x27c90048
    ctx->pc = 0x1dd5f4u;
    SET_GPR_S32(ctx, 9, ADD32(GPR_U32(ctx, 30), 72));
    // 0x1dd5f8: 0x8c640004
    ctx->pc = 0x1dd5f8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 3), 4)));
    // 0x1dd5fc: 0x40282d
    ctx->pc = 0x1dd5fcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd600: 0x382d
    ctx->pc = 0x1dd600u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd604: 0xc07a5ac
    ctx->pc = 0x1DD604u;
    SET_GPR_U32(ctx, 31, 0x1DD60Cu);
    ctx->pc = 0x1E96B0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001E96B0_0x1e96b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD60Cu; }
    }
    if (ctx->pc != 0x1DD60Cu) { return; }
    ctx->pc = 0x1DD60Cu;
    // 0x1dd60c: 0xafc20044
    ctx->pc = 0x1dd60cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1dd610: 0x24020001
    ctx->pc = 0x1dd610u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1dd614: 0xafc20060
    ctx->pc = 0x1dd614u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 96), GPR_U32(ctx, 2));
    // 0x1dd618: 0x8fc30004
    ctx->pc = 0x1dd618u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd61c: 0x8fc20004
    ctx->pc = 0x1dd61cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd620: 0x8c42052c
    ctx->pc = 0x1dd620u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 1324)));
    // 0x1dd624: 0x24420001
    ctx->pc = 0x1dd624u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x1dd628: 0xac62052c
    ctx->pc = 0x1dd628u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1324), GPR_U32(ctx, 2));
    // 0x1dd62c: 0x8fc20004
    ctx->pc = 0x1dd62cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd630: 0x8fc30014
    ctx->pc = 0x1dd630u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 20)));
    // 0x1dd634: 0x8c42004c
    ctx->pc = 0x1dd634u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 76)));
    // 0x1dd638: 0x14620008
    ctx->pc = 0x1DD638u;
    {
        const bool branch_taken_0x1dd638 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        if (branch_taken_0x1dd638) {
            ctx->pc = 0x1DD65Cu;
            goto label_1dd65c;
        }
    }
    ctx->pc = 0x1DD640u;
    // 0x1dd640: 0x8fc20004
    ctx->pc = 0x1dd640u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd644: 0x97c30012
    ctx->pc = 0x1dd644u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 18)));
    // 0x1dd648: 0x9442004a
    ctx->pc = 0x1dd648u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 74)));
    // 0x1dd64c: 0x14620003
    ctx->pc = 0x1DD64Cu;
    {
        const bool branch_taken_0x1dd64c = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        if (branch_taken_0x1dd64c) {
            ctx->pc = 0x1DD65Cu;
            goto label_1dd65c;
        }
    }
    ctx->pc = 0x1DD654u;
    // 0x1dd654: 0x10000002
    ctx->pc = 0x1DD654u;
    {
        const bool branch_taken_0x1dd654 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd654) {
            ctx->pc = 0x1DD660u;
            goto label_1dd660;
        }
    }
    ctx->pc = 0x1DD65Cu;
label_1dd65c:
    // 0x1dd65c: 0xafc00060
    ctx->pc = 0x1dd65cu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 96), GPR_U32(ctx, 0));
label_1dd660:
    // 0x1dd660: 0x8fc20044
    ctx->pc = 0x1dd660u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1dd664: 0x2c420014
    ctx->pc = 0x1dd664u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 2), 20));
    // 0x1dd668: 0x10400002
    ctx->pc = 0x1DD668u;
    {
        const bool branch_taken_0x1dd668 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd668) {
            ctx->pc = 0x1DD674u;
            goto label_1dd674;
        }
    }
    ctx->pc = 0x1DD670u;
    // 0x1dd670: 0xafc00060
    ctx->pc = 0x1dd670u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 96), GPR_U32(ctx, 0));
label_1dd674:
    // 0x1dd674: 0x8fc20060
    ctx->pc = 0x1dd674u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 96)));
    // 0x1dd678: 0x1040003f
    ctx->pc = 0x1DD678u;
    {
        const bool branch_taken_0x1dd678 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd678) {
            ctx->pc = 0x1DD778u;
            goto label_1dd778;
        }
    }
    ctx->pc = 0x1DD680u;
    // 0x1dd680: 0x8fc40008
    ctx->pc = 0x1dd680u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dd684: 0x24054000
    ctx->pc = 0x1dd684u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16384));
    // 0x1dd688: 0xc07c680
    ctx->pc = 0x1DD688u;
    SET_GPR_U32(ctx, 31, 0x1DD690u);
    ctx->pc = 0x1F1A00u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1A00_0x1f1a00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD690u; }
    }
    if (ctx->pc != 0x1DD690u) { return; }
    ctx->pc = 0x1DD690u;
    // 0x1dd690: 0x8fc20008
    ctx->pc = 0x1dd690u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dd694: 0x2442002c
    ctx->pc = 0x1dd694u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 44));
    // 0x1dd698: 0xafc2005c
    ctx->pc = 0x1dd698u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 92), GPR_U32(ctx, 2));
    // 0x1dd69c: 0x8fc3005c
    ctx->pc = 0x1dd69cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 92)));
    // 0x1dd6a0: 0x8fc20044
    ctx->pc = 0x1dd6a0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1dd6a4: 0x621021
    ctx->pc = 0x1dd6a4u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dd6a8: 0x2442fffc
    ctx->pc = 0x1dd6a8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967292));
    // 0x1dd6ac: 0xafc2005c
    ctx->pc = 0x1dd6acu;
    WRITE32(ADD32(GPR_U32(ctx, 30), 92), GPR_U32(ctx, 2));
    // 0x1dd6b0: 0x27c20058
    ctx->pc = 0x1dd6b0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 30), 88));
    // 0x1dd6b4: 0x40202d
    ctx->pc = 0x1dd6b4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd6b8: 0x8fc5005c
    ctx->pc = 0x1dd6b8u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 30), 92)));
    // 0x1dd6bc: 0x24060004
    ctx->pc = 0x1dd6bcu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 4));
    // 0x1dd6c0: 0xc041eac
    ctx->pc = 0x1DD6C0u;
    SET_GPR_U32(ctx, 31, 0x1DD6C8u);
    ctx->pc = 0x107AB0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD6C8u; }
    }
    if (ctx->pc != 0x1DD6C8u) { return; }
    ctx->pc = 0x1DD6C8u;
    // 0x1dd6c8: 0x8fc20044
    ctx->pc = 0x1dd6c8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1dd6cc: 0x2442fffc
    ctx->pc = 0x1dd6ccu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967292));
    // 0x1dd6d0: 0xafc20044
    ctx->pc = 0x1dd6d0u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 68), GPR_U32(ctx, 2));
    // 0x1dd6d4: 0x8fc20058
    ctx->pc = 0x1dd6d4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 88)));
    // 0x1dd6d8: 0x304200ff
    ctx->pc = 0x1dd6d8u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 255));
    // 0x1dd6dc: 0x21e00
    ctx->pc = 0x1dd6dcu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 2), 24));
    // 0x1dd6e0: 0x8fc20058
    ctx->pc = 0x1dd6e0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 88)));
    // 0x1dd6e4: 0x3042ff00
    ctx->pc = 0x1dd6e4u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 65280));
    // 0x1dd6e8: 0x21200
    ctx->pc = 0x1dd6e8u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 8));
    // 0x1dd6ec: 0x622025
    ctx->pc = 0x1dd6ecu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dd6f0: 0x8fc30058
    ctx->pc = 0x1dd6f0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 88)));
    // 0x1dd6f4: 0x3c0200ff
    ctx->pc = 0x1dd6f4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)255 << 16));
    // 0x1dd6f8: 0x621024
    ctx->pc = 0x1dd6f8u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dd6fc: 0x21202
    ctx->pc = 0x1dd6fcu;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 8));
    // 0x1dd700: 0x822025
    ctx->pc = 0x1dd700u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1dd704: 0x8fc30058
    ctx->pc = 0x1dd704u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 88)));
    // 0x1dd708: 0x3c02ff00
    ctx->pc = 0x1dd708u;
    SET_GPR_U32(ctx, 2, ((uint32_t)65280 << 16));
    // 0x1dd70c: 0x621024
    ctx->pc = 0x1dd70cu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dd710: 0x21602
    ctx->pc = 0x1dd710u;
    SET_GPR_U32(ctx, 2, SRL32(GPR_U32(ctx, 2), 24));
    // 0x1dd714: 0x821025
    ctx->pc = 0x1dd714u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1dd718: 0xafc20058
    ctx->pc = 0x1dd718u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 88), GPR_U32(ctx, 2));
    // 0x1dd71c: 0x8fc30058
    ctx->pc = 0x1dd71cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 88)));
    // 0x1dd720: 0x2402ff00
    ctx->pc = 0x1dd720u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967040));
    // 0x1dd724: 0x621824
    ctx->pc = 0x1dd724u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1dd728: 0x3c02ba47
    ctx->pc = 0x1dd728u;
    SET_GPR_U32(ctx, 2, ((uint32_t)47687 << 16));
    // 0x1dd72c: 0x34426600
    ctx->pc = 0x1dd72cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 26112));
    // 0x1dd730: 0x10620004
    ctx->pc = 0x1DD730u;
    {
        const bool branch_taken_0x1dd730 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        if (branch_taken_0x1dd730) {
            ctx->pc = 0x1DD744u;
            goto label_1dd744;
        }
    }
    ctx->pc = 0x1DD738u;
    // 0x1dd738: 0xafc00060
    ctx->pc = 0x1dd738u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 96), GPR_U32(ctx, 0));
    // 0x1dd73c: 0x1000000e
    ctx->pc = 0x1DD73Cu;
    {
        const bool branch_taken_0x1dd73c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd73c) {
            ctx->pc = 0x1DD778u;
            goto label_1dd778;
        }
    }
    ctx->pc = 0x1DD744u;
label_1dd744:
    // 0x1dd744: 0x97c20044
    ctx->pc = 0x1dd744u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1dd748: 0x8fc40008
    ctx->pc = 0x1dd748u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dd74c: 0x40282d
    ctx->pc = 0x1dd74cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd750: 0xc07c6c0
    ctx->pc = 0x1DD750u;
    SET_GPR_U32(ctx, 31, 0x1DD758u);
    ctx->pc = 0x1F1B00u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001F1B00_0x1f1b00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD758u; }
    }
    if (ctx->pc != 0x1DD758u) { return; }
    ctx->pc = 0x1DD758u;
    // 0x1dd758: 0x8fc40008
    ctx->pc = 0x1dd758u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dd75c: 0xc07cef3
    ctx->pc = 0x1DD75Cu;
    SET_GPR_U32(ctx, 31, 0x1DD764u);
    ctx->pc = 0x1F3BCCu;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001F3BCC_0x1f3bcc(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD764u; }
    }
    if (ctx->pc != 0x1DD764u) { return; }
    ctx->pc = 0x1DD764u;
    // 0x1dd764: 0xafc20068
    ctx->pc = 0x1dd764u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 104), GPR_U32(ctx, 2));
    // 0x1dd768: 0x8fc20068
    ctx->pc = 0x1dd768u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 104)));
    // 0x1dd76c: 0x10400002
    ctx->pc = 0x1DD76Cu;
    {
        const bool branch_taken_0x1dd76c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd76c) {
            ctx->pc = 0x1DD778u;
            goto label_1dd778;
        }
    }
    ctx->pc = 0x1DD774u;
    // 0x1dd774: 0xafc00060
    ctx->pc = 0x1dd774u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 96), GPR_U32(ctx, 0));
label_1dd778:
    // 0x1dd778: 0x8fc20060
    ctx->pc = 0x1dd778u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 96)));
    // 0x1dd77c: 0x1440ff2a
    ctx->pc = 0x1DD77Cu;
    {
        const bool branch_taken_0x1dd77c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1dd77c) {
            ctx->pc = 0x1DD428u;
            goto label_1dd428;
        }
    }
    ctx->pc = 0x1DD784u;
    // 0x1dd784: 0x8fc20004
    ctx->pc = 0x1dd784u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd788: 0x8c440520
    ctx->pc = 0x1dd788u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 1312)));
    // 0x1dd78c: 0x8fc50008
    ctx->pc = 0x1dd78cu;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dd790: 0xc07ca04
    ctx->pc = 0x1DD790u;
    SET_GPR_U32(ctx, 31, 0x1DD798u);
    ctx->pc = 0x1F2810u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001F2810_0x1f2810(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD798u; }
    }
    if (ctx->pc != 0x1DD798u) { return; }
    ctx->pc = 0x1DD798u;
    // 0x1dd798: 0xafc00008
    ctx->pc = 0x1dd798u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 8), GPR_U32(ctx, 0));
    // 0x1dd79c: 0x8fc30004
    ctx->pc = 0x1dd79cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd7a0: 0x8fc20004
    ctx->pc = 0x1dd7a0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd7a4: 0x8c420530
    ctx->pc = 0x1dd7a4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 1328)));
    // 0x1dd7a8: 0x24420001
    ctx->pc = 0x1dd7a8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x1dd7ac: 0xac620530
    ctx->pc = 0x1dd7acu;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1328), GPR_U32(ctx, 2));
    // 0x1dd7b0: 0x1000ff1d
    ctx->pc = 0x1DD7B0u;
    {
        const bool branch_taken_0x1dd7b0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd7b0) {
            ctx->pc = 0x1DD428u;
            goto label_1dd428;
        }
    }
    ctx->pc = 0x1DD7B8u;
label_1dd7b8:
    // 0x1dd7b8: 0x8fc30004
    ctx->pc = 0x1dd7b8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd7bc: 0x8fc20004
    ctx->pc = 0x1dd7bcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd7c0: 0x8c420534
    ctx->pc = 0x1dd7c0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 1332)));
    // 0x1dd7c4: 0x24420001
    ctx->pc = 0x1dd7c4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x1dd7c8: 0xac620534
    ctx->pc = 0x1dd7c8u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 1332), GPR_U32(ctx, 2));
    // 0x1dd7cc: 0x1000ff16
    ctx->pc = 0x1DD7CCu;
    {
        const bool branch_taken_0x1dd7cc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd7cc) {
            ctx->pc = 0x1DD428u;
            goto label_1dd428;
        }
    }
    ctx->pc = 0x1DD7D4u;
label_1dd7d4:
    // 0x1dd7d4: 0x8fc20008
    ctx->pc = 0x1dd7d4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dd7d8: 0x1040000e
    ctx->pc = 0x1DD7D8u;
    {
        const bool branch_taken_0x1dd7d8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd7d8) {
            ctx->pc = 0x1DD814u;
            goto label_1dd814;
        }
    }
    ctx->pc = 0x1DD7E0u;
    // 0x1dd7e0: 0x8fc40008
    ctx->pc = 0x1dd7e0u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 30), 8)));
    // 0x1dd7e4: 0x8fc50004
    ctx->pc = 0x1dd7e4u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd7e8: 0x8fc60050
    ctx->pc = 0x1dd7e8u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 30), 80)));
    // 0x1dd7ec: 0x8fc70044
    ctx->pc = 0x1dd7ecu;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 30), 68)));
    // 0x1dd7f0: 0xc0771ee
    ctx->pc = 0x1DD7F0u;
    SET_GPR_U32(ctx, 31, 0x1DD7F8u);
    ctx->pc = 0x1DC7B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001DC7B8_0x1dc7b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD7F8u; }
    }
    if (ctx->pc != 0x1DD7F8u) { return; }
    ctx->pc = 0x1DD7F8u;
    // 0x1dd7f8: 0xafc20068
    ctx->pc = 0x1dd7f8u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 104), GPR_U32(ctx, 2));
    // 0x1dd7fc: 0x8fc20068
    ctx->pc = 0x1dd7fcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 104)));
    // 0x1dd800: 0x10400004
    ctx->pc = 0x1DD800u;
    {
        const bool branch_taken_0x1dd800 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd800) {
            ctx->pc = 0x1DD814u;
            goto label_1dd814;
        }
    }
    ctx->pc = 0x1DD808u;
    // 0x1dd808: 0x24020027
    ctx->pc = 0x1dd808u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 39));
    // 0x1dd80c: 0x1000002d
    ctx->pc = 0x1DD80Cu;
    {
        const bool branch_taken_0x1dd80c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd80c) {
            ctx->pc = 0x1DD8C4u;
            goto label_1dd8c4;
        }
    }
    ctx->pc = 0x1DD814u;
label_1dd814:
    // 0x1dd814: 0x8fc40004
    ctx->pc = 0x1dd814u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd818: 0xc079e90
    ctx->pc = 0x1DD818u;
    SET_GPR_U32(ctx, 31, 0x1DD820u);
    ctx->pc = 0x1E7A40u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001E7A40_0x1e7a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD820u; }
    }
    if (ctx->pc != 0x1DD820u) { return; }
    ctx->pc = 0x1DD820u;
    // 0x1dd820: 0xafc20068
    ctx->pc = 0x1dd820u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 104), GPR_U32(ctx, 2));
    // 0x1dd824: 0x8fc20068
    ctx->pc = 0x1dd824u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 104)));
    // 0x1dd828: 0x10400008
    ctx->pc = 0x1DD828u;
    {
        const bool branch_taken_0x1dd828 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd828) {
            ctx->pc = 0x1DD84Cu;
            goto label_1dd84c;
        }
    }
    ctx->pc = 0x1DD830u;
    // 0x1dd830: 0x8fc20068
    ctx->pc = 0x1dd830u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 104)));
    // 0x1dd834: 0x24421b58
    ctx->pc = 0x1dd834u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 7000));
    // 0x1dd838: 0x3c010026
    ctx->pc = 0x1dd838u;
    SET_GPR_U32(ctx, 1, ((uint32_t)38 << 16));
    // 0x1dd83c: 0xac229d10
    ctx->pc = 0x1dd83cu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294941968), GPR_U32(ctx, 2));
    // 0x1dd840: 0x24020027
    ctx->pc = 0x1dd840u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 39));
    // 0x1dd844: 0x1000001f
    ctx->pc = 0x1DD844u;
    {
        const bool branch_taken_0x1dd844 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd844) {
            ctx->pc = 0x1DD8C4u;
            goto label_1dd8c4;
        }
    }
    ctx->pc = 0x1DD84Cu;
label_1dd84c:
    // 0x1dd84c: 0x8fc40004
    ctx->pc = 0x1dd84cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd850: 0xc07730b
    ctx->pc = 0x1DD850u;
    SET_GPR_U32(ctx, 31, 0x1DD858u);
    ctx->pc = 0x1DCC2Cu;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001DCC2C_0x1dcc2c(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD858u; }
    }
    if (ctx->pc != 0x1DD858u) { return; }
    ctx->pc = 0x1DD858u;
    // 0x1dd858: 0xafc20068
    ctx->pc = 0x1dd858u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 104), GPR_U32(ctx, 2));
    // 0x1dd85c: 0x8fc20068
    ctx->pc = 0x1dd85cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 104)));
    // 0x1dd860: 0x10400008
    ctx->pc = 0x1DD860u;
    {
        const bool branch_taken_0x1dd860 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd860) {
            ctx->pc = 0x1DD884u;
            goto label_1dd884;
        }
    }
    ctx->pc = 0x1DD868u;
    // 0x1dd868: 0x8fc20068
    ctx->pc = 0x1dd868u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 104)));
    // 0x1dd86c: 0x24421f40
    ctx->pc = 0x1dd86cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 8000));
    // 0x1dd870: 0x3c010026
    ctx->pc = 0x1dd870u;
    SET_GPR_U32(ctx, 1, ((uint32_t)38 << 16));
    // 0x1dd874: 0xac229d10
    ctx->pc = 0x1dd874u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294941968), GPR_U32(ctx, 2));
    // 0x1dd878: 0x24020027
    ctx->pc = 0x1dd878u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 39));
    // 0x1dd87c: 0x10000011
    ctx->pc = 0x1DD87Cu;
    {
        const bool branch_taken_0x1dd87c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd87c) {
            ctx->pc = 0x1DD8C4u;
            goto label_1dd8c4;
        }
    }
    ctx->pc = 0x1DD884u;
label_1dd884:
    // 0x1dd884: 0x8fc40004
    ctx->pc = 0x1dd884u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd888: 0x8fc50050
    ctx->pc = 0x1dd888u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 30), 80)));
    // 0x1dd88c: 0xc076ca4
    ctx->pc = 0x1DD88Cu;
    SET_GPR_U32(ctx, 31, 0x1DD894u);
    ctx->pc = 0x1DB290u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001DB290_0x1db290(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1DD894u; }
    }
    if (ctx->pc != 0x1DD894u) { return; }
    ctx->pc = 0x1DD894u;
    // 0x1dd894: 0xafc20068
    ctx->pc = 0x1dd894u;
    WRITE32(ADD32(GPR_U32(ctx, 30), 104), GPR_U32(ctx, 2));
    // 0x1dd898: 0x8fc20068
    ctx->pc = 0x1dd898u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 104)));
    // 0x1dd89c: 0x10400008
    ctx->pc = 0x1DD89Cu;
    {
        const bool branch_taken_0x1dd89c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd89c) {
            ctx->pc = 0x1DD8C0u;
            goto label_1dd8c0;
        }
    }
    ctx->pc = 0x1DD8A4u;
    // 0x1dd8a4: 0x8fc20004
    ctx->pc = 0x1dd8a4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 30), 4)));
    // 0x1dd8a8: 0x8c42050c
    ctx->pc = 0x1dd8a8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 1292)));
    // 0x1dd8ac: 0x3c010026
    ctx->pc = 0x1dd8acu;
    SET_GPR_U32(ctx, 1, ((uint32_t)38 << 16));
    // 0x1dd8b0: 0xac229d10
    ctx->pc = 0x1dd8b0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294941968), GPR_U32(ctx, 2));
    // 0x1dd8b4: 0x24020027
    ctx->pc = 0x1dd8b4u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 39));
    // 0x1dd8b8: 0x10000002
    ctx->pc = 0x1DD8B8u;
    {
        const bool branch_taken_0x1dd8b8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        if (branch_taken_0x1dd8b8) {
            ctx->pc = 0x1DD8C4u;
            goto label_1dd8c4;
        }
    }
    ctx->pc = 0x1DD8C0u;
label_1dd8c0:
    // 0x1dd8c0: 0x102d
    ctx->pc = 0x1dd8c0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1dd8c4:
    // 0x1dd8c4: 0x3c0e82d
    ctx->pc = 0x1dd8c4u;
    SET_GPR_U64(ctx, 29, (uint64_t)GPR_U64(ctx, 30) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1dd8c8: 0xdfbe00a0
    ctx->pc = 0x1dd8c8u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x1dd8cc: 0xdfbf00a8
    ctx->pc = 0x1dd8ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 168)));
    // 0x1dd8d0: 0x27bd00b0
    ctx->pc = 0x1dd8d0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 176));
    // 0x1dd8d4: 0x3e00008
    ctx->pc = 0x1DD8D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1DD120u: goto label_1dd120;
            case 0x1DD12Cu: goto label_1dd12c;
            case 0x1DD154u: goto label_1dd154;
            case 0x1DD16Cu: goto label_1dd16c;
            case 0x1DD194u: goto label_1dd194;
            case 0x1DD1A0u: goto label_1dd1a0;
            case 0x1DD1B8u: goto label_1dd1b8;
            case 0x1DD1E0u: goto label_1dd1e0;
            case 0x1DD284u: goto label_1dd284;
            case 0x1DD354u: goto label_1dd354;
            case 0x1DD37Cu: goto label_1dd37c;
            case 0x1DD3D0u: goto label_1dd3d0;
            case 0x1DD3ECu: goto label_1dd3ec;
            case 0x1DD400u: goto label_1dd400;
            case 0x1DD428u: goto label_1dd428;
            case 0x1DD43Cu: goto label_1dd43c;
            case 0x1DD4D4u: goto label_1dd4d4;
            case 0x1DD564u: goto label_1dd564;
            case 0x1DD57Cu: goto label_1dd57c;
            case 0x1DD5CCu: goto label_1dd5cc;
            case 0x1DD65Cu: goto label_1dd65c;
            case 0x1DD660u: goto label_1dd660;
            case 0x1DD674u: goto label_1dd674;
            case 0x1DD744u: goto label_1dd744;
            case 0x1DD778u: goto label_1dd778;
            case 0x1DD7B8u: goto label_1dd7b8;
            case 0x1DD7D4u: goto label_1dd7d4;
            case 0x1DD814u: goto label_1dd814;
            case 0x1DD84Cu: goto label_1dd84c;
            case 0x1DD884u: goto label_1dd884;
            case 0x1DD8C0u: goto label_1dd8c0;
            case 0x1DD8C4u: goto label_1dd8c4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1DD8DCu;
    // 0x1dd8dc: 0x0
    ctx->pc = 0x1dd8dcu;
    // NOP
}
