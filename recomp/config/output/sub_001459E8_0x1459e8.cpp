#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001459E8
// Address: 0x1459e8 - 0x145b58
void sub_001459E8_0x1459e8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1459e8u;

    // 0x1459e8: 0x27bdffb0
    ctx->pc = 0x1459e8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x1459ec: 0x3c021000
    ctx->pc = 0x1459ecu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x1459f0: 0xffb20020
    ctx->pc = 0x1459f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x1459f4: 0x34422010
    ctx->pc = 0x1459f4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8208));
    // 0x1459f8: 0xffb10010
    ctx->pc = 0x1459f8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x1459fc: 0x3c068000
    ctx->pc = 0x1459fcu;
    SET_GPR_U32(ctx, 6, ((uint32_t)32768 << 16));
    // 0x145a00: 0xffbf0040
    ctx->pc = 0x145a00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x145a04: 0x34c64000
    ctx->pc = 0x145a04u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 6), 16384));
    // 0x145a08: 0xffb30030
    ctx->pc = 0x145a08u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 19));
    // 0x145a0c: 0x80882d
    ctx->pc = 0x145a0cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145a10: 0xffb00000
    ctx->pc = 0x145a10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x145a14: 0xa0902d
    ctx->pc = 0x145a14u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145a18: 0x382d
    ctx->pc = 0x145a18u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145a1c: 0x8c430000
    ctx->pc = 0x145a1cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x145a20: 0x3c028000
    ctx->pc = 0x145a20u;
    SET_GPR_U32(ctx, 2, ((uint32_t)32768 << 16));
    // 0x145a24: 0x661824
    ctx->pc = 0x145a24u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 6)));
    // 0x145a28: 0x1462001b
    ctx->pc = 0x145A28u;
    {
        const bool branch_taken_0x145a28 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x145A2Cu;
        SET_GPR_U32(ctx, 19, ((uint32_t)35 << 16));
        if (branch_taken_0x145a28) {
            ctx->pc = 0x145A98u;
            goto label_145a98;
        }
    }
    ctx->pc = 0x145A30u;
    // 0x145a30: 0x8e2210a0
    ctx->pc = 0x145a30u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 4256)));
    // 0x145a34: 0x54400019
    ctx->pc = 0x145A34u;
    {
        const bool branch_taken_0x145a34 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x145a34) {
            ctx->pc = 0x145A38u;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 2096)));
            ctx->pc = 0x145A9Cu;
            goto label_145a9c;
        }
    }
    ctx->pc = 0x145A3Cu;
    // 0x145a3c: 0x3c130023
    ctx->pc = 0x145a3cu;
    SET_GPR_U32(ctx, 19, ((uint32_t)35 << 16));
    // 0x145a40: 0xe0102d
    ctx->pc = 0x145a40u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145a44: 0x0
    ctx->pc = 0x145a44u;
    // NOP
label_145a48:
    // 0x145a48: 0x28421389
    ctx->pc = 0x145a48u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 2), 5001));
    // 0x145a4c: 0x14400004
    ctx->pc = 0x145A4Cu;
    {
        const bool branch_taken_0x145a4c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x145A50u;
        SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 1));
        if (branch_taken_0x145a4c) {
            ctx->pc = 0x145A60u;
            goto label_145a60;
        }
    }
    ctx->pc = 0x145A54u;
    // 0x145a54: 0xc051ff8
    ctx->pc = 0x145A54u;
    SET_GPR_U32(ctx, 31, 0x145A5Cu);
    ctx->pc = 0x145A58u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 2160)));
    ctx->pc = 0x147FE0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00147FE0_0x147fe0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145A5Cu; }
    }
    if (ctx->pc != 0x145A5Cu) { return; }
    ctx->pc = 0x145A5Cu;
    // 0x145a5c: 0x382d
    ctx->pc = 0x145a5cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_145a60:
    // 0x145a60: 0x3c031000
    ctx->pc = 0x145a60u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x145a64: 0x3c048000
    ctx->pc = 0x145a64u;
    SET_GPR_U32(ctx, 4, ((uint32_t)32768 << 16));
    // 0x145a68: 0x34632010
    ctx->pc = 0x145a68u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 8208));
    // 0x145a6c: 0x34844000
    ctx->pc = 0x145a6cu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 16384));
    // 0x145a70: 0x8c620000
    ctx->pc = 0x145a70u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x145a74: 0x3c058000
    ctx->pc = 0x145a74u;
    SET_GPR_U32(ctx, 5, ((uint32_t)32768 << 16));
    // 0x145a78: 0x441024
    ctx->pc = 0x145a78u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x145a7c: 0x54450007
    ctx->pc = 0x145A7Cu;
    {
        const bool branch_taken_0x145a7c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 5));
        if (branch_taken_0x145a7c) {
            ctx->pc = 0x145A80u;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 2096)));
            ctx->pc = 0x145A9Cu;
            goto label_145a9c;
        }
    }
    ctx->pc = 0x145A84u;
    // 0x145a84: 0x8e2210a0
    ctx->pc = 0x145a84u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 4256)));
    // 0x145a88: 0x1040ffef
    ctx->pc = 0x145A88u;
    {
        const bool branch_taken_0x145a88 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x145A8Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x145a88) {
            ctx->pc = 0x145A48u;
            goto label_145a48;
        }
    }
    ctx->pc = 0x145A90u;
    // 0x145a90: 0x10000002
    ctx->pc = 0x145A90u;
    {
        const bool branch_taken_0x145a90 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x145A94u;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 2096)));
        if (branch_taken_0x145a90) {
            ctx->pc = 0x145A9Cu;
            goto label_145a9c;
        }
    }
    ctx->pc = 0x145A98u;
label_145a98:
    // 0x145a98: 0x8e220830
    ctx->pc = 0x145a98u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 2096)));
label_145a9c:
    // 0x145a9c: 0x14400005
    ctx->pc = 0x145A9Cu;
    {
        const bool branch_taken_0x145a9c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x145AA0u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x145a9c) {
            ctx->pc = 0x145AB4u;
            goto label_145ab4;
        }
    }
    ctx->pc = 0x145AA4u;
    // 0x145aa4: 0x8e220854
    ctx->pc = 0x145aa4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 2132)));
    // 0x145aa8: 0x52102a
    ctx->pc = 0x145aa8u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 2), GPR_S32(ctx, 18)));
    // 0x145aac: 0x1040000c
    ctx->pc = 0x145AACu;
    {
        const bool branch_taken_0x145aac = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x145AB0u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
        if (branch_taken_0x145aac) {
            ctx->pc = 0x145AE0u;
            goto label_145ae0;
        }
    }
    ctx->pc = 0x145AB4u;
label_145ab4:
    // 0x145ab4: 0x3c034000
    ctx->pc = 0x145ab4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)16384 << 16));
    // 0x145ab8: 0x34422000
    ctx->pc = 0x145ab8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8192));
    // 0x145abc: 0x2665a6f8
    ctx->pc = 0x145abcu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 19), 4294944504));
    // 0x145ac0: 0xac430000
    ctx->pc = 0x145ac0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x145ac4: 0x220202d
    ctx->pc = 0x145ac4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145ac8: 0x8ca20010
    ctx->pc = 0x145ac8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 5), 16)));
    // 0x145acc: 0xc0514f0
    ctx->pc = 0x145ACCu;
    SET_GPR_U32(ctx, 31, 0x145AD4u);
    ctx->pc = 0x145AD0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2096), GPR_U32(ctx, 2));
    ctx->pc = 0x1453C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001453C0_0x1453c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145AD4u; }
    }
    if (ctx->pc != 0x145AD4u) { return; }
    ctx->pc = 0x145AD4u;
    // 0x145ad4: 0x2103c
    ctx->pc = 0x145ad4u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x145ad8: 0x2103f
    ctx->pc = 0x145ad8u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x145adc: 0xae220850
    ctx->pc = 0x145adcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2128), GPR_U32(ctx, 2));
label_145ae0:
    // 0x145ae0: 0x24050020
    ctx->pc = 0x145ae0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 32));
    // 0x145ae4: 0x3c044000
    ctx->pc = 0x145ae4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)16384 << 16));
    // 0x145ae8: 0x3c021000
    ctx->pc = 0x145ae8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x145aec: 0x2442025
    ctx->pc = 0x145aecu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 18), GPR_U32(ctx, 4)));
    // 0x145af0: 0xae250854
    ctx->pc = 0x145af0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2132), GPR_U32(ctx, 5));
    // 0x145af4: 0x34422000
    ctx->pc = 0x145af4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 8192));
    // 0x145af8: 0x8e300850
    ctx->pc = 0x145af8u;
    SET_GPR_U32(ctx, 16, READ32(ADD32(GPR_U32(ctx, 17), 2128)));
    // 0x145afc: 0x41f02
    ctx->pc = 0x145afcu;
    SET_GPR_U32(ctx, 3, SRL32(GPR_U32(ctx, 4), 28));
    // 0x145b00: 0xac440000
    ctx->pc = 0x145b00u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x145b04: 0x31880
    ctx->pc = 0x145b04u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 2));
    // 0x145b08: 0x2662a6f8
    ctx->pc = 0x145b08u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 19), 4294944504));
    // 0x145b0c: 0xb22823
    ctx->pc = 0x145b0cu;
    SET_GPR_U32(ctx, 5, SUB32(GPR_U32(ctx, 5), GPR_U32(ctx, 18)));
    // 0x145b10: 0x621821
    ctx->pc = 0x145b10u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x145b14: 0xb08006
    ctx->pc = 0x145b14u;
    SET_GPR_U32(ctx, 16, SRL32(GPR_U32(ctx, 16), GPR_U32(ctx, 5) & 0x1F));
    // 0x145b18: 0x8c620000
    ctx->pc = 0x145b18u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x145b1c: 0x220202d
    ctx->pc = 0x145b1cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145b20: 0xc0514f0
    ctx->pc = 0x145B20u;
    SET_GPR_U32(ctx, 31, 0x145B28u);
    ctx->pc = 0x145B24u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2096), GPR_U32(ctx, 2));
    ctx->pc = 0x1453C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001453C0_0x1453c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x145B28u; }
    }
    if (ctx->pc != 0x145B28u) { return; }
    ctx->pc = 0x145B28u;
    // 0x145b28: 0x2103c
    ctx->pc = 0x145b28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x145b2c: 0x2103f
    ctx->pc = 0x145b2cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x145b30: 0xdfbf0040
    ctx->pc = 0x145b30u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x145b34: 0xae220850
    ctx->pc = 0x145b34u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 2128), GPR_U32(ctx, 2));
    // 0x145b38: 0x200102d
    ctx->pc = 0x145b38u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x145b3c: 0xdfb30030
    ctx->pc = 0x145b3cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x145b40: 0xdfb20020
    ctx->pc = 0x145b40u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x145b44: 0xdfb10010
    ctx->pc = 0x145b44u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x145b48: 0xdfb00000
    ctx->pc = 0x145b48u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x145b4c: 0x3e00008
    ctx->pc = 0x145B4Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x145B50u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x145A48u: goto label_145a48;
            case 0x145A60u: goto label_145a60;
            case 0x145A98u: goto label_145a98;
            case 0x145A9Cu: goto label_145a9c;
            case 0x145AB4u: goto label_145ab4;
            case 0x145AE0u: goto label_145ae0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x145B54u;
    // 0x145b54: 0x0
    ctx->pc = 0x145b54u;
    // NOP
}
