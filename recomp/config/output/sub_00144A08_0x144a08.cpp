#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00144A08
// Address: 0x144a08 - 0x144eb0
void sub_00144A08_0x144a08(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x144a08u;

    // 0x144a08: 0x27bdff30
    ctx->pc = 0x144a08u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967088));
    // 0x144a0c: 0x3c0b1000
    ctx->pc = 0x144a0cu;
    SET_GPR_U32(ctx, 11, ((uint32_t)4096 << 16));
    // 0x144a10: 0xffb60090
    ctx->pc = 0x144a10u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 22));
    // 0x144a14: 0x356b2010
    ctx->pc = 0x144a14u;
    SET_GPR_U32(ctx, 11, OR32(GPR_U32(ctx, 11), 8208));
    // 0x144a18: 0xffb50080
    ctx->pc = 0x144a18u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 21));
    // 0x144a1c: 0x3c02f8ff
    ctx->pc = 0x144a1cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)63743 << 16));
    // 0x144a20: 0xffb20050
    ctx->pc = 0x144a20u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 18));
    // 0x144a24: 0x3442ffff
    ctx->pc = 0x144a24u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65535));
    // 0x144a28: 0xffb10040
    ctx->pc = 0x144a28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 17));
    // 0x144a2c: 0xa0902d
    ctx->pc = 0x144a2cu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144a30: 0xffb00030
    ctx->pc = 0x144a30u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x144a34: 0xc0a82d
    ctx->pc = 0x144a34u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144a38: 0xffbf00c0
    ctx->pc = 0x144a38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 192), GPR_U64(ctx, 31));
    // 0x144a3c: 0x80802d
    ctx->pc = 0x144a3cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144a40: 0xffbe00b0
    ctx->pc = 0x144a40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 176), GPR_U64(ctx, 30));
    // 0x144a44: 0x100882d
    ctx->pc = 0x144a44u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144a48: 0xffb700a0
    ctx->pc = 0x144a48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 23));
    // 0x144a4c: 0x140b02d
    ctx->pc = 0x144a4cu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144a50: 0xffb40070
    ctx->pc = 0x144a50u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 20));
    // 0x144a54: 0x24050001
    ctx->pc = 0x144a54u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    // 0x144a58: 0xffb30060
    ctx->pc = 0x144a58u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 19));
    // 0x144a5c: 0x8e040168
    ctx->pc = 0x144a5cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 360)));
    // 0x144a60: 0x8d630000
    ctx->pc = 0x144a60u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x144a64: 0x42600
    ctx->pc = 0x144a64u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 24));
    // 0x144a68: 0x621824
    ctx->pc = 0x144a68u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x144a6c: 0x641825
    ctx->pc = 0x144a6cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x144a70: 0xad630000
    ctx->pc = 0x144a70u;
    WRITE32(ADD32(GPR_U32(ctx, 11), 0), GPR_U32(ctx, 3));
    // 0x144a74: 0x200202d
    ctx->pc = 0x144a74u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144a78: 0xafa70020
    ctx->pc = 0x144a78u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 32), GPR_U32(ctx, 7));
    // 0x144a7c: 0xc051552
    ctx->pc = 0x144A7Cu;
    SET_GPR_U32(ctx, 31, 0x144A84u);
    ctx->pc = 0x144A80u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 36), GPR_U32(ctx, 9));
    ctx->pc = 0x145548u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00145548_0x145548(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144A84u; }
    }
    if (ctx->pc != 0x144A84u) { return; }
    ctx->pc = 0x144A84u;
    // 0x144a84: 0x40182d
    ctx->pc = 0x144a84u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144a88: 0x14600009
    ctx->pc = 0x144A88u;
    {
        const bool branch_taken_0x144a88 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x144A8Cu;
        WRITE32(ADD32(GPR_U32(ctx, 18), 0), GPR_U32(ctx, 3));
        if (branch_taken_0x144a88) {
            ctx->pc = 0x144AB0u;
            goto label_144ab0;
        }
    }
    ctx->pc = 0x144A90u;
    // 0x144a90: 0x3c050024
    ctx->pc = 0x144a90u;
    SET_GPR_U32(ctx, 5, ((uint32_t)36 << 16));
    // 0x144a94: 0x200202d
    ctx->pc = 0x144a94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144a98: 0xc05221c
    ctx->pc = 0x144A98u;
    SET_GPR_U32(ctx, 31, 0x144AA0u);
    ctx->pc = 0x144A9Cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294958808));
    ctx->pc = 0x148870u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00148870_0x148870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144AA0u; }
    }
    if (ctx->pc != 0x144AA0u) { return; }
    ctx->pc = 0x144AA0u;
    // 0x144aa0: 0x24030001
    ctx->pc = 0x144aa0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x144aa4: 0x102d
    ctx->pc = 0x144aa4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144aa8: 0x100000f5
    ctx->pc = 0x144AA8u;
    {
        const bool branch_taken_0x144aa8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x144AACu;
        WRITE32(ADD32(GPR_U32(ctx, 16), 308), GPR_U32(ctx, 3));
        if (branch_taken_0x144aa8) {
            ctx->pc = 0x144E80u;
            goto label_144e80;
        }
    }
    ctx->pc = 0x144AB0u;
label_144ab0:
    // 0x144ab0: 0x3062000c
    ctx->pc = 0x144ab0u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), 12));
    // 0x144ab4: 0x1040000d
    ctx->pc = 0x144AB4u;
    {
        const bool branch_taken_0x144ab4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x144AB8u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
        if (branch_taken_0x144ab4) {
            ctx->pc = 0x144AECu;
            goto label_144aec;
        }
    }
    ctx->pc = 0x144ABCu;
    // 0x144abc: 0x8e03018c
    ctx->pc = 0x144abcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 396)));
    // 0x144ac0: 0x14620006
    ctx->pc = 0x144AC0u;
    {
        const bool branch_taken_0x144ac0 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x144AC4u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x144ac0) {
            ctx->pc = 0x144ADCu;
            goto label_144adc;
        }
    }
    ctx->pc = 0x144AC8u;
    // 0x144ac8: 0x8e020194
    ctx->pc = 0x144ac8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 404)));
    // 0x144acc: 0x10400003
    ctx->pc = 0x144ACCu;
    {
        const bool branch_taken_0x144acc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x144AD0u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
        if (branch_taken_0x144acc) {
            ctx->pc = 0x144ADCu;
            goto label_144adc;
        }
    }
    ctx->pc = 0x144AD4u;
    // 0x144ad4: 0x10000010
    ctx->pc = 0x144AD4u;
    {
        const bool branch_taken_0x144ad4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x144AD8u;
        WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x144ad4) {
            ctx->pc = 0x144B18u;
            goto label_144b18;
        }
    }
    ctx->pc = 0x144ADCu;
label_144adc:
    // 0x144adc: 0xc05167a
    ctx->pc = 0x144ADCu;
    SET_GPR_U32(ctx, 31, 0x144AE4u);
    ctx->pc = 0x144AE0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144AE4u; }
    }
    if (ctx->pc != 0x144AE4u) { return; }
    ctx->pc = 0x144AE4u;
    // 0x144ae4: 0x1000000c
    ctx->pc = 0x144AE4u;
    {
        const bool branch_taken_0x144ae4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x144AE8u;
        WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x144ae4) {
            ctx->pc = 0x144B18u;
            goto label_144b18;
        }
    }
    ctx->pc = 0x144AECu;
label_144aec:
    // 0x144aec: 0x30620001
    ctx->pc = 0x144aecu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), 1));
    // 0x144af0: 0x5040000a
    ctx->pc = 0x144AF0u;
    {
        const bool branch_taken_0x144af0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x144af0) {
            ctx->pc = 0x144AF4u;
            SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 16), 396)));
            ctx->pc = 0x144B1Cu;
            goto label_144b1c;
        }
    }
    ctx->pc = 0x144AF8u;
    // 0x144af8: 0x8e020198
    ctx->pc = 0x144af8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 408)));
    // 0x144afc: 0x10400006
    ctx->pc = 0x144AFCu;
    {
        const bool branch_taken_0x144afc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x144B00u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x144afc) {
            ctx->pc = 0x144B18u;
            goto label_144b18;
        }
    }
    ctx->pc = 0x144B04u;
    // 0x144b04: 0x8e02018c
    ctx->pc = 0x144b04u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 396)));
    // 0x144b08: 0x24040002
    ctx->pc = 0x144b08u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 2));
    // 0x144b0c: 0x38420003
    ctx->pc = 0x144b0cu;
    SET_GPR_U32(ctx, 2, XOR32(GPR_U32(ctx, 2), 3));
    // 0x144b10: 0x82180a
    ctx->pc = 0x144b10u;
    if (GPR_U32(ctx, 2) == 0) SET_GPR_U32(ctx, 3, GPR_U32(ctx, 4));
    // 0x144b14: 0xaea30000
    ctx->pc = 0x144b14u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 3));
label_144b18:
    // 0x144b18: 0x8e06018c
    ctx->pc = 0x144b18u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 16), 396)));
label_144b1c:
    // 0x144b1c: 0x24020003
    ctx->pc = 0x144b1cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
    // 0x144b20: 0x14c20008
    ctx->pc = 0x144B20u;
    {
        const bool branch_taken_0x144b20 = (GPR_U32(ctx, 6) != GPR_U32(ctx, 2));
        ctx->pc = 0x144B24u;
        SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 21), 0)));
        if (branch_taken_0x144b20) {
            ctx->pc = 0x144B44u;
            goto label_144b44;
        }
    }
    ctx->pc = 0x144B28u;
    // 0x144b28: 0x24130001
    ctx->pc = 0x144b28u;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 0), 1));
    // 0x144b2c: 0x24020002
    ctx->pc = 0x144b2cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
    // 0x144b30: 0x38a30001
    ctx->pc = 0x144b30u;
    SET_GPR_U32(ctx, 3, XOR32(GPR_U32(ctx, 5), 1));
    // 0x144b34: 0x38a40002
    ctx->pc = 0x144b34u;
    SET_GPR_U32(ctx, 4, XOR32(GPR_U32(ctx, 5), 2));
    // 0x144b38: 0x43980a
    ctx->pc = 0x144b38u;
    if (GPR_U32(ctx, 3) == 0) SET_GPR_U32(ctx, 19, GPR_U32(ctx, 2));
    // 0x144b3c: 0x10000006
    ctx->pc = 0x144B3Cu;
    {
        const bool branch_taken_0x144b3c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x144B40u;
        SET_GPR_U32(ctx, 20, SLTU32(GPR_U32(ctx, 4), 1));
        if (branch_taken_0x144b3c) {
            ctx->pc = 0x144B58u;
            goto label_144b58;
        }
    }
    ctx->pc = 0x144B44u;
label_144b44:
    // 0x144b44: 0x24030002
    ctx->pc = 0x144b44u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
    // 0x144b48: 0x24130001
    ctx->pc = 0x144b48u;
    SET_GPR_S32(ctx, 19, ADD32(GPR_U32(ctx, 0), 1));
    // 0x144b4c: 0xa02d
    ctx->pc = 0x144b4cu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144b50: 0x38a20002
    ctx->pc = 0x144b50u;
    SET_GPR_U32(ctx, 2, XOR32(GPR_U32(ctx, 5), 2));
    // 0x144b54: 0x62980a
    ctx->pc = 0x144b54u;
    if (GPR_U32(ctx, 2) == 0) SET_GPR_U32(ctx, 19, GPR_U32(ctx, 3));
label_144b58:
    // 0x144b58: 0x38a20003
    ctx->pc = 0x144b58u;
    SET_GPR_U32(ctx, 2, XOR32(GPR_U32(ctx, 5), 3));
    // 0x144b5c: 0xb82d
    ctx->pc = 0x144b5cu;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144b60: 0x16800003
    ctx->pc = 0x144B60u;
    {
        const bool branch_taken_0x144b60 = (GPR_U32(ctx, 20) != GPR_U32(ctx, 0));
        ctx->pc = 0x144B64u;
        SET_GPR_U32(ctx, 30, SLTU32(GPR_U32(ctx, 2), 1));
        if (branch_taken_0x144b60) {
            ctx->pc = 0x144B70u;
            goto label_144b70;
        }
    }
    ctx->pc = 0x144B68u;
    // 0x144b68: 0x38c20003
    ctx->pc = 0x144b68u;
    SET_GPR_U32(ctx, 2, XOR32(GPR_U32(ctx, 6), 3));
    // 0x144b6c: 0x2c570001
    ctx->pc = 0x144b6cu;
    SET_GPR_U32(ctx, 23, SLTU32(GPR_U32(ctx, 2), 1));
label_144b70:
    // 0x144b70: 0x24020003
    ctx->pc = 0x144b70u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
    // 0x144b74: 0x14c2000d
    ctx->pc = 0x144B74u;
    {
        const bool branch_taken_0x144b74 = (GPR_U32(ctx, 6) != GPR_U32(ctx, 2));
        ctx->pc = 0x144B78u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x144b74) {
            ctx->pc = 0x144BACu;
            goto label_144bac;
        }
    }
    ctx->pc = 0x144B7Cu;
    // 0x144b7c: 0x8e020194
    ctx->pc = 0x144b7cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 404)));
    // 0x144b80: 0x1440000a
    ctx->pc = 0x144B80u;
    {
        const bool branch_taken_0x144b80 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x144B84u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x144b80) {
            ctx->pc = 0x144BACu;
            goto label_144bac;
        }
    }
    ctx->pc = 0x144B88u;
    // 0x144b88: 0x8e420000
    ctx->pc = 0x144b88u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x144b8c: 0x30420003
    ctx->pc = 0x144b8cu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 3));
    // 0x144b90: 0x10400005
    ctx->pc = 0x144B90u;
    {
        const bool branch_taken_0x144b90 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x144B94u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x144b90) {
            ctx->pc = 0x144BA8u;
            goto label_144ba8;
        }
    }
    ctx->pc = 0x144B98u;
    // 0x144b98: 0xc05167a
    ctx->pc = 0x144B98u;
    SET_GPR_U32(ctx, 31, 0x144BA0u);
    ctx->pc = 0x144B9Cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144BA0u; }
    }
    if (ctx->pc != 0x144BA0u) { return; }
    ctx->pc = 0x144BA0u;
    // 0x144ba0: 0x10000003
    ctx->pc = 0x144BA0u;
    {
        const bool branch_taken_0x144ba0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x144BA4u;
        SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 32)));
        if (branch_taken_0x144ba0) {
            ctx->pc = 0x144BB0u;
            goto label_144bb0;
        }
    }
    ctx->pc = 0x144BA8u;
label_144ba8:
    // 0x144ba8: 0x102d
    ctx->pc = 0x144ba8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_144bac:
    // 0x144bac: 0x8fa30020
    ctx->pc = 0x144bacu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 29), 32)));
label_144bb0:
    // 0x144bb0: 0xac620000
    ctx->pc = 0x144bb0u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
    // 0x144bb4: 0x8e430000
    ctx->pc = 0x144bb4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x144bb8: 0x30620010
    ctx->pc = 0x144bb8u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), 16));
    // 0x144bbc: 0x10400005
    ctx->pc = 0x144BBCu;
    {
        const bool branch_taken_0x144bbc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x144BC0u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x144bbc) {
            ctx->pc = 0x144BD4u;
            goto label_144bd4;
        }
    }
    ctx->pc = 0x144BC4u;
    // 0x144bc4: 0xc05167a
    ctx->pc = 0x144BC4u;
    SET_GPR_U32(ctx, 31, 0x144BCCu);
    ctx->pc = 0x144BC8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 5));
    ctx->pc = 0x1459E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001459E8_0x1459e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144BCCu; }
    }
    if (ctx->pc != 0x144BCCu) { return; }
    ctx->pc = 0x144BCCu;
    // 0x144bcc: 0xae0201cc
    ctx->pc = 0x144bccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 460), GPR_U32(ctx, 2));
    // 0x144bd0: 0x8e430000
    ctx->pc = 0x144bd0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_144bd4:
    // 0x144bd4: 0x30620008
    ctx->pc = 0x144bd4u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), 8));
    // 0x144bd8: 0x54400008
    ctx->pc = 0x144BD8u;
    {
        const bool branch_taken_0x144bd8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x144bd8) {
            ctx->pc = 0x144BDCu;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 2144)));
            ctx->pc = 0x144BFCu;
            goto label_144bfc;
        }
    }
    ctx->pc = 0x144BE0u;
    // 0x144be0: 0x30620001
    ctx->pc = 0x144be0u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), 1));
    // 0x144be4: 0x50400021
    ctx->pc = 0x144BE4u;
    {
        const bool branch_taken_0x144be4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x144be4) {
            ctx->pc = 0x144BE8u;
            SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 308)));
            ctx->pc = 0x144C6Cu;
            goto label_144c6c;
        }
    }
    ctx->pc = 0x144BECu;
    // 0x144bec: 0x8e020198
    ctx->pc = 0x144becu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 408)));
    // 0x144bf0: 0x5040001e
    ctx->pc = 0x144BF0u;
    {
        const bool branch_taken_0x144bf0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x144bf0) {
            ctx->pc = 0x144BF4u;
            SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 308)));
            ctx->pc = 0x144C6Cu;
            goto label_144c6c;
        }
    }
    ctx->pc = 0x144BF8u;
    // 0x144bf8: 0x8e020860
    ctx->pc = 0x144bf8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 2144)));
label_144bfc:
    // 0x144bfc: 0x10400011
    ctx->pc = 0x144BFCu;
    {
        const bool branch_taken_0x144bfc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x144C00u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x144bfc) {
            ctx->pc = 0x144C44u;
            goto label_144c44;
        }
    }
    ctx->pc = 0x144C04u;
    // 0x144c04: 0x8e020180
    ctx->pc = 0x144c04u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 384)));
    // 0x144c08: 0x8e0b017c
    ctx->pc = 0x144c08u;
    SET_GPR_U32(ctx, 11, READ32(ADD32(GPR_U32(ctx, 16), 380)));
    // 0x144c0c: 0x220282d
    ctx->pc = 0x144c0cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144c10: 0x2442ffff
    ctx->pc = 0x144c10u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x144c14: 0x8fa70024
    ctx->pc = 0x144c14u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x144c18: 0xafbe0008
    ctx->pc = 0x144c18u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 30));
    // 0x144c1c: 0x256bffff
    ctx->pc = 0x144c1cu;
    SET_GPR_S32(ctx, 11, ADD32(GPR_U32(ctx, 11), 4294967295));
    // 0x144c20: 0xafa20000
    ctx->pc = 0x144c20u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x144c24: 0x2c0302d
    ctx->pc = 0x144c24u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144c28: 0xafb70010
    ctx->pc = 0x144c28u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 23));
    // 0x144c2c: 0x402d
    ctx->pc = 0x144c2cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144c30: 0x260482d
    ctx->pc = 0x144c30u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144c34: 0xc0513ce
    ctx->pc = 0x144C34u;
    SET_GPR_U32(ctx, 31, 0x144C3Cu);
    ctx->pc = 0x144C38u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x144F38u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00144F38_0x144f38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144C3Cu; }
    }
    if (ctx->pc != 0x144C3Cu) { return; }
    ctx->pc = 0x144C3Cu;
    // 0x144c3c: 0x1000000b
    ctx->pc = 0x144C3Cu;
    {
        const bool branch_taken_0x144c3c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x144C40u;
        SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 308)));
        if (branch_taken_0x144c3c) {
            ctx->pc = 0x144C6Cu;
            goto label_144c6c;
        }
    }
    ctx->pc = 0x144C44u;
label_144c44:
    // 0x144c44: 0x8e070170
    ctx->pc = 0x144c44u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 16), 368)));
    // 0x144c48: 0x8e0b016c
    ctx->pc = 0x144c48u;
    SET_GPR_U32(ctx, 11, READ32(ADD32(GPR_U32(ctx, 16), 364)));
    // 0x144c4c: 0x220282d
    ctx->pc = 0x144c4cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144c50: 0x24e7ffff
    ctx->pc = 0x144c50u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x144c54: 0x2c0302d
    ctx->pc = 0x144c54u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144c58: 0x482d
    ctx->pc = 0x144c58u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144c5c: 0xe0402d
    ctx->pc = 0x144c5cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144c60: 0xc051436
    ctx->pc = 0x144C60u;
    SET_GPR_U32(ctx, 31, 0x144C68u);
    ctx->pc = 0x144C64u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1450D8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001450D8_0x1450d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144C68u; }
    }
    if (ctx->pc != 0x144C68u) { return; }
    ctx->pc = 0x144C68u;
    // 0x144c68: 0x8e030134
    ctx->pc = 0x144c68u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 308)));
label_144c6c:
    // 0x144c6c: 0x14600084
    ctx->pc = 0x144C6Cu;
    {
        const bool branch_taken_0x144c6c = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x144C70u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x144c6c) {
            ctx->pc = 0x144E80u;
            goto label_144e80;
        }
    }
    ctx->pc = 0x144C74u;
    // 0x144c74: 0x8e420000
    ctx->pc = 0x144c74u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x144c78: 0x30420004
    ctx->pc = 0x144c78u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 4));
    // 0x144c7c: 0x1040001e
    ctx->pc = 0x144C7Cu;
    {
        const bool branch_taken_0x144c7c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x144c7c) {
            ctx->pc = 0x144CF8u;
            goto label_144cf8;
        }
    }
    ctx->pc = 0x144C84u;
    // 0x144c84: 0x8e020860
    ctx->pc = 0x144c84u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 2144)));
    // 0x144c88: 0x10400011
    ctx->pc = 0x144C88u;
    {
        const bool branch_taken_0x144c88 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x144C8Cu;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x144c88) {
            ctx->pc = 0x144CD0u;
            goto label_144cd0;
        }
    }
    ctx->pc = 0x144C90u;
    // 0x144c90: 0x8e020188
    ctx->pc = 0x144c90u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 392)));
    // 0x144c94: 0x8e0b0184
    ctx->pc = 0x144c94u;
    SET_GPR_U32(ctx, 11, READ32(ADD32(GPR_U32(ctx, 16), 388)));
    // 0x144c98: 0x260482d
    ctx->pc = 0x144c98u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144c9c: 0x2442ffff
    ctx->pc = 0x144c9cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x144ca0: 0x8fa70024
    ctx->pc = 0x144ca0u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x144ca4: 0xafb70010
    ctx->pc = 0x144ca4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 23));
    // 0x144ca8: 0x280502d
    ctx->pc = 0x144ca8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144cac: 0xafa20000
    ctx->pc = 0x144cacu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x144cb0: 0x256bffff
    ctx->pc = 0x144cb0u;
    SET_GPR_S32(ctx, 11, ADD32(GPR_U32(ctx, 11), 4294967295));
    // 0x144cb4: 0xafa00008
    ctx->pc = 0x144cb4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 0));
    // 0x144cb8: 0x200202d
    ctx->pc = 0x144cb8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144cbc: 0x220282d
    ctx->pc = 0x144cbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144cc0: 0xc0513ce
    ctx->pc = 0x144CC0u;
    SET_GPR_U32(ctx, 31, 0x144CC8u);
    ctx->pc = 0x144CC4u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x144F38u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00144F38_0x144f38(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144CC8u; }
    }
    if (ctx->pc != 0x144CC8u) { return; }
    ctx->pc = 0x144CC8u;
    // 0x144cc8: 0x1000000b
    ctx->pc = 0x144CC8u;
    {
        const bool branch_taken_0x144cc8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x144CCCu;
        SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 308)));
        if (branch_taken_0x144cc8) {
            ctx->pc = 0x144CF8u;
            goto label_144cf8;
        }
    }
    ctx->pc = 0x144CD0u;
label_144cd0:
    // 0x144cd0: 0x8e070178
    ctx->pc = 0x144cd0u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 16), 376)));
    // 0x144cd4: 0x8e0b0174
    ctx->pc = 0x144cd4u;
    SET_GPR_U32(ctx, 11, READ32(ADD32(GPR_U32(ctx, 16), 372)));
    // 0x144cd8: 0x200202d
    ctx->pc = 0x144cd8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144cdc: 0x24e7ffff
    ctx->pc = 0x144cdcu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 4294967295));
    // 0x144ce0: 0x26250008
    ctx->pc = 0x144ce0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 17), 8));
    // 0x144ce4: 0x482d
    ctx->pc = 0x144ce4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144ce8: 0xe0402d
    ctx->pc = 0x144ce8u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144cec: 0xc051436
    ctx->pc = 0x144CECu;
    SET_GPR_U32(ctx, 31, 0x144CF4u);
    ctx->pc = 0x144CF0u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1450D8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001450D8_0x1450d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144CF4u; }
    }
    if (ctx->pc != 0x144CF4u) { return; }
    ctx->pc = 0x144CF4u;
    // 0x144cf4: 0x8e030134
    ctx->pc = 0x144cf4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 308)));
label_144cf8:
    // 0x144cf8: 0x14600061
    ctx->pc = 0x144CF8u;
    {
        const bool branch_taken_0x144cf8 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x144CFCu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x144cf8) {
            ctx->pc = 0x144E80u;
            goto label_144e80;
        }
    }
    ctx->pc = 0x144D00u;
    // 0x144d00: 0x8e430000
    ctx->pc = 0x144d00u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x144d04: 0x30620001
    ctx->pc = 0x144d04u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), 1));
    // 0x144d08: 0x10400008
    ctx->pc = 0x144D08u;
    {
        const bool branch_taken_0x144d08 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x144D0Cu;
        SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), 3));
        if (branch_taken_0x144d08) {
            ctx->pc = 0x144D2Cu;
            goto label_144d2c;
        }
    }
    ctx->pc = 0x144D10u;
    // 0x144d10: 0x8e020198
    ctx->pc = 0x144d10u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 408)));
    // 0x144d14: 0x10400004
    ctx->pc = 0x144D14u;
    {
        const bool branch_taken_0x144d14 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x144D18u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x144d14) {
            ctx->pc = 0x144D28u;
            goto label_144d28;
        }
    }
    ctx->pc = 0x144D1Cu;
    // 0x144d1c: 0xc051636
    ctx->pc = 0x144D1Cu;
    SET_GPR_U32(ctx, 31, 0x144D24u);
    ctx->pc = 0x144D20u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x1458D8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001458D8_0x1458d8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144D24u; }
    }
    if (ctx->pc != 0x144D24u) { return; }
    ctx->pc = 0x144D24u;
    // 0x144d24: 0x8e430000
    ctx->pc = 0x144d24u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_144d28:
    // 0x144d28: 0x30620003
    ctx->pc = 0x144d28u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 3), 3));
label_144d2c:
    // 0x144d2c: 0x1040001c
    ctx->pc = 0x144D2Cu;
    {
        const bool branch_taken_0x144d2c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x144D30u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 320));
        if (branch_taken_0x144d2c) {
            ctx->pc = 0x144DA0u;
            goto label_144da0;
        }
    }
    ctx->pc = 0x144D34u;
    // 0x144d34: 0x8e020828
    ctx->pc = 0x144d34u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 2088)));
    // 0x144d38: 0x24050300
    ctx->pc = 0x144d38u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 768));
    // 0x144d3c: 0x432018
    ctx->pc = 0x144d3cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 4, (int32_t)(uint32_t)result); }
    // 0x144d40: 0x901021
    ctx->pc = 0x144d40u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 16)));
    // 0x144d44: 0xc051c84
    ctx->pc = 0x144D44u;
    SET_GPR_U32(ctx, 31, 0x144D4Cu);
    ctx->pc = 0x144D48u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 1452)));
    ctx->pc = 0x147210u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00147210_0x147210(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144D4Cu; }
    }
    if (ctx->pc != 0x144D4Cu) { return; }
    ctx->pc = 0x144D4Cu;
    // 0x144d4c: 0xc051496
    ctx->pc = 0x144D4Cu;
    SET_GPR_U32(ctx, 31, 0x144D54u);
    ctx->pc = 0x144D50u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x145258u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00145258_0x145258(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144D54u; }
    }
    if (ctx->pc != 0x144D54u) { return; }
    ctx->pc = 0x144D54u;
    // 0x144d54: 0x8e450000
    ctx->pc = 0x144d54u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x144d58: 0x3c072000
    ctx->pc = 0x144d58u;
    SET_GPR_U32(ctx, 7, ((uint32_t)8192 << 16));
    // 0x144d5c: 0x8e0601cc
    ctx->pc = 0x144d5cu;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 16), 460)));
    // 0x144d60: 0x200202d
    ctx->pc = 0x144d60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x144d64: 0x8e0301c8
    ctx->pc = 0x144d64u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 456)));
    // 0x144d68: 0x30a50001
    ctx->pc = 0x144d68u;
    SET_GPR_U32(ctx, 5, AND32(GPR_U32(ctx, 5), 1));
    // 0x144d6c: 0x8fa80020
    ctx->pc = 0x144d6cu;
    SET_GPR_U32(ctx, 8, READ32(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x144d70: 0x52ec0
    ctx->pc = 0x144d70u;
    SET_GPR_U32(ctx, 5, SLL32(GPR_U32(ctx, 5), 27));
    // 0x144d74: 0x63400
    ctx->pc = 0x144d74u;
    SET_GPR_U32(ctx, 6, SLL32(GPR_U32(ctx, 6), 16));
    // 0x144d78: 0x31e80
    ctx->pc = 0x144d78u;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 3), 26));
    // 0x144d7c: 0x8d020000
    ctx->pc = 0x144d7cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 8), 0)));
    // 0x144d80: 0xa62825
    ctx->pc = 0x144d80u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), GPR_U32(ctx, 6)));
    // 0x144d84: 0x671825
    ctx->pc = 0x144d84u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), GPR_U32(ctx, 7)));
    // 0x144d88: 0xa32825
    ctx->pc = 0x144d88u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), GPR_U32(ctx, 3)));
    // 0x144d8c: 0x21640
    ctx->pc = 0x144d8cu;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 2), 25));
    // 0x144d90: 0xc05148a
    ctx->pc = 0x144D90u;
    SET_GPR_U32(ctx, 31, 0x144D98u);
    ctx->pc = 0x144D94u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    ctx->pc = 0x145228u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00145228_0x145228(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x144D98u; }
    }
    if (ctx->pc != 0x144D98u) { return; }
    ctx->pc = 0x144D98u;
    // 0x144d98: 0x10000007
    ctx->pc = 0x144D98u;
    {
        const bool branch_taken_0x144d98 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x144D9Cu;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 308)));
        if (branch_taken_0x144d98) {
            ctx->pc = 0x144DB8u;
            goto label_144db8;
        }
    }
    ctx->pc = 0x144DA0u;
label_144da0:
    // 0x144da0: 0x8e020828
    ctx->pc = 0x144da0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 2088)));
    // 0x144da4: 0x24040001
    ctx->pc = 0x144da4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    // 0x144da8: 0x432818
    ctx->pc = 0x144da8u;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 5, (int32_t)(uint32_t)result); }
    // 0x144dac: 0xb01021
    ctx->pc = 0x144dacu;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 16)));
    // 0x144db0: 0xac4406e4
    ctx->pc = 0x144db0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 1764), GPR_U32(ctx, 4));
    // 0x144db4: 0x8e020134
    ctx->pc = 0x144db4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 308)));
label_144db8:
    // 0x144db8: 0x10400003
    ctx->pc = 0x144DB8u;
    {
        const bool branch_taken_0x144db8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x144DBCu;
        WRITE32(ADD32(GPR_U32(ctx, 16), 456), GPR_U32(ctx, 0));
        if (branch_taken_0x144db8) {
            ctx->pc = 0x144DC8u;
            goto label_144dc8;
        }
    }
    ctx->pc = 0x144DC0u;
    // 0x144dc0: 0x1000002f
    ctx->pc = 0x144DC0u;
    {
        const bool branch_taken_0x144dc0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x144DC4u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x144dc0) {
            ctx->pc = 0x144E80u;
            goto label_144e80;
        }
    }
    ctx->pc = 0x144DC8u;
label_144dc8:
    // 0x144dc8: 0x8e420000
    ctx->pc = 0x144dc8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x144dcc: 0x30420001
    ctx->pc = 0x144dccu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 1));
    // 0x144dd0: 0x54400008
    ctx->pc = 0x144DD0u;
    {
        const bool branch_taken_0x144dd0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x144dd0) {
            ctx->pc = 0x144DD4u;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 408)));
            ctx->pc = 0x144DF4u;
            goto label_144df4;
        }
    }
    ctx->pc = 0x144DD8u;
    // 0x144dd8: 0x24030001
    ctx->pc = 0x144dd8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x144ddc: 0xae0301c8
    ctx->pc = 0x144ddcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 456), GPR_U32(ctx, 3));
    // 0x144de0: 0x8e420000
    ctx->pc = 0x144de0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x144de4: 0x30420001
    ctx->pc = 0x144de4u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 1));
    // 0x144de8: 0x5040000d
    ctx->pc = 0x144DE8u;
    {
        const bool branch_taken_0x144de8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x144de8) {
            ctx->pc = 0x144DECu;
            SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 360)));
            ctx->pc = 0x144E20u;
            goto label_144e20;
        }
    }
    ctx->pc = 0x144DF0u;
    // 0x144df0: 0x8e020198
    ctx->pc = 0x144df0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 408)));
label_144df4:
    // 0x144df4: 0x5440000a
    ctx->pc = 0x144DF4u;
    {
        const bool branch_taken_0x144df4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x144df4) {
            ctx->pc = 0x144DF8u;
            SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 360)));
            ctx->pc = 0x144E20u;
            goto label_144e20;
        }
    }
    ctx->pc = 0x144DFCu;
    // 0x144dfc: 0xae200014
    ctx->pc = 0x144dfcu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 0));
    // 0x144e00: 0xae200010
    ctx->pc = 0x144e00u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 0));
    // 0x144e04: 0xae200004
    ctx->pc = 0x144e04u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
    // 0x144e08: 0xae200000
    ctx->pc = 0x144e08u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x144e0c: 0xae20001c
    ctx->pc = 0x144e0cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 28), GPR_U32(ctx, 0));
    // 0x144e10: 0xae200018
    ctx->pc = 0x144e10u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 24), GPR_U32(ctx, 0));
    // 0x144e14: 0xae20000c
    ctx->pc = 0x144e14u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 0));
    // 0x144e18: 0xae200008
    ctx->pc = 0x144e18u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 8), GPR_U32(ctx, 0));
    // 0x144e1c: 0x8e040168
    ctx->pc = 0x144e1cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 360)));
label_144e20:
    // 0x144e20: 0x24020002
    ctx->pc = 0x144e20u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 2));
    // 0x144e24: 0x14820016
    ctx->pc = 0x144E24u;
    {
        const bool branch_taken_0x144e24 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 2));
        ctx->pc = 0x144E28u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x144e24) {
            ctx->pc = 0x144E80u;
            goto label_144e80;
        }
    }
    ctx->pc = 0x144E2Cu;
    // 0x144e2c: 0x8e420000
    ctx->pc = 0x144e2cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x144e30: 0x30420009
    ctx->pc = 0x144e30u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 9));
    // 0x144e34: 0x14400012
    ctx->pc = 0x144E34u;
    {
        const bool branch_taken_0x144e34 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x144E38u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x144e34) {
            ctx->pc = 0x144E80u;
            goto label_144e80;
        }
    }
    ctx->pc = 0x144E3Cu;
    // 0x144e3c: 0xae200000
    ctx->pc = 0x144e3cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 0), GPR_U32(ctx, 0));
    // 0x144e40: 0x24030003
    ctx->pc = 0x144e40u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 3));
    // 0x144e44: 0xae200014
    ctx->pc = 0x144e44u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 0));
    // 0x144e48: 0xae200010
    ctx->pc = 0x144e48u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 0));
    // 0x144e4c: 0xae200004
    ctx->pc = 0x144e4cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
    // 0x144e50: 0x8e02018c
    ctx->pc = 0x144e50u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 396)));
    // 0x144e54: 0x14430003
    ctx->pc = 0x144E54u;
    {
        const bool branch_taken_0x144e54 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        ctx->pc = 0x144E58u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x144e54) {
            ctx->pc = 0x144E64u;
            goto label_144e64;
        }
    }
    ctx->pc = 0x144E5Cu;
    // 0x144e5c: 0x10000007
    ctx->pc = 0x144E5Cu;
    {
        const bool branch_taken_0x144e5c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x144E60u;
        WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 4));
        if (branch_taken_0x144e5c) {
            ctx->pc = 0x144E7Cu;
            goto label_144e7c;
        }
    }
    ctx->pc = 0x144E64u;
label_144e64:
    // 0x144e64: 0xaea30000
    ctx->pc = 0x144e64u;
    WRITE32(ADD32(GPR_U32(ctx, 21), 0), GPR_U32(ctx, 3));
    // 0x144e68: 0x8e02018c
    ctx->pc = 0x144e68u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 396)));
    // 0x144e6c: 0x8fa80024
    ctx->pc = 0x144e6cu;
    SET_GPR_U32(ctx, 8, READ32(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x144e70: 0x38420002
    ctx->pc = 0x144e70u;
    SET_GPR_U32(ctx, 2, XOR32(GPR_U32(ctx, 2), 2));
    // 0x144e74: 0x2c420001
    ctx->pc = 0x144e74u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 2), 1));
    // 0x144e78: 0xad020000
    ctx->pc = 0x144e78u;
    WRITE32(ADD32(GPR_U32(ctx, 8), 0), GPR_U32(ctx, 2));
label_144e7c:
    // 0x144e7c: 0x24020001
    ctx->pc = 0x144e7cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_144e80:
    // 0x144e80: 0xdfbf00c0
    ctx->pc = 0x144e80u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 192)));
    // 0x144e84: 0xdfbe00b0
    ctx->pc = 0x144e84u;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 176)));
    // 0x144e88: 0xdfb700a0
    ctx->pc = 0x144e88u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x144e8c: 0xdfb60090
    ctx->pc = 0x144e8cu;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x144e90: 0xdfb50080
    ctx->pc = 0x144e90u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x144e94: 0xdfb40070
    ctx->pc = 0x144e94u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x144e98: 0xdfb30060
    ctx->pc = 0x144e98u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x144e9c: 0xdfb20050
    ctx->pc = 0x144e9cu;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x144ea0: 0xdfb10040
    ctx->pc = 0x144ea0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x144ea4: 0xdfb00030
    ctx->pc = 0x144ea4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x144ea8: 0x3e00008
    ctx->pc = 0x144EA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x144EACu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 208));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x144AB0u: goto label_144ab0;
            case 0x144ADCu: goto label_144adc;
            case 0x144AECu: goto label_144aec;
            case 0x144B18u: goto label_144b18;
            case 0x144B1Cu: goto label_144b1c;
            case 0x144B44u: goto label_144b44;
            case 0x144B58u: goto label_144b58;
            case 0x144B70u: goto label_144b70;
            case 0x144BA8u: goto label_144ba8;
            case 0x144BACu: goto label_144bac;
            case 0x144BB0u: goto label_144bb0;
            case 0x144BD4u: goto label_144bd4;
            case 0x144BFCu: goto label_144bfc;
            case 0x144C44u: goto label_144c44;
            case 0x144C6Cu: goto label_144c6c;
            case 0x144CD0u: goto label_144cd0;
            case 0x144CF8u: goto label_144cf8;
            case 0x144D28u: goto label_144d28;
            case 0x144D2Cu: goto label_144d2c;
            case 0x144DA0u: goto label_144da0;
            case 0x144DB8u: goto label_144db8;
            case 0x144DC8u: goto label_144dc8;
            case 0x144DF4u: goto label_144df4;
            case 0x144E20u: goto label_144e20;
            case 0x144E64u: goto label_144e64;
            case 0x144E7Cu: goto label_144e7c;
            case 0x144E80u: goto label_144e80;
            default: break;
        }
        return;
    }
    ctx->pc = 0x144EB0u;
}
