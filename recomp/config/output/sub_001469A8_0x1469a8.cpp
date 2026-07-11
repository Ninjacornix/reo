#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001469A8
// Address: 0x1469a8 - 0x146c60
void sub_001469A8_0x1469a8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1469a8u;

    // 0x1469a8: 0x27bdff50
    ctx->pc = 0x1469a8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x1469ac: 0x3c020fff
    ctx->pc = 0x1469acu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4095 << 16));
    // 0x1469b0: 0xffb60070
    ctx->pc = 0x1469b0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 22));
    // 0x1469b4: 0x3442ffff
    ctx->pc = 0x1469b4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65535));
    // 0x1469b8: 0xffb20030
    ctx->pc = 0x1469b8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x1469bc: 0xa0b02d
    ctx->pc = 0x1469bcu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1469c0: 0xafa40000
    ctx->pc = 0x1469c0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 4));
    // 0x1469c4: 0xffbf00a0
    ctx->pc = 0x1469c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 160), GPR_U64(ctx, 31));
    // 0x1469c8: 0xffbe0090
    ctx->pc = 0x1469c8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 30));
    // 0x1469cc: 0xffb70080
    ctx->pc = 0x1469ccu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 23));
    // 0x1469d0: 0xffb50060
    ctx->pc = 0x1469d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 96), GPR_U64(ctx, 21));
    // 0x1469d4: 0xffb40050
    ctx->pc = 0x1469d4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 20));
    // 0x1469d8: 0xffb30040
    ctx->pc = 0x1469d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 19));
    // 0x1469dc: 0xffb10020
    ctx->pc = 0x1469dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x1469e0: 0xffb00010
    ctx->pc = 0x1469e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x1469e4: 0x8fa60000
    ctx->pc = 0x1469e4u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1469e8: 0x8ec30000
    ctx->pc = 0x1469e8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x1469ec: 0x8c8400f0
    ctx->pc = 0x1469ecu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 240)));
    // 0x1469f0: 0x8cc5018c
    ctx->pc = 0x1469f0u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 6), 396)));
    // 0x1469f4: 0x629024
    ctx->pc = 0x1469f4u;
    SET_GPR_U32(ctx, 18, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1469f8: 0x822024
    ctx->pc = 0x1469f8u;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x1469fc: 0x24030003
    ctx->pc = 0x1469fcu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 3));
    // 0x146a00: 0x10a30006
    ctx->pc = 0x146A00u;
    {
        const bool branch_taken_0x146a00 = (GPR_U32(ctx, 5) == GPR_U32(ctx, 3));
        ctx->pc = 0x146A04u;
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 4));
        if (branch_taken_0x146a00) {
            ctx->pc = 0x146A1Cu;
            goto label_146a1c;
        }
    }
    ctx->pc = 0x146A08u;
    // 0x146a08: 0x8cc400f8
    ctx->pc = 0x146a08u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 6), 248)));
    // 0x146a0c: 0x14800011
    ctx->pc = 0x146A0Cu;
    {
        const bool branch_taken_0x146a0c = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x146A10u;
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x146a0c) {
            ctx->pc = 0x146A54u;
            goto label_146a54;
        }
    }
    ctx->pc = 0x146A14u;
    // 0x146a14: 0x10000004
    ctx->pc = 0x146A14u;
    {
        const bool branch_taken_0x146a14 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x146A18u;
        SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 22), 16)));
        if (branch_taken_0x146a14) {
            ctx->pc = 0x146A28u;
            goto label_146a28;
        }
    }
    ctx->pc = 0x146A1Cu;
label_146a1c:
    // 0x146a1c: 0x8fa70000
    ctx->pc = 0x146a1cu;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x146a20: 0x8ce300f8
    ctx->pc = 0x146a20u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 248)));
    // 0x146a24: 0x8ec20010
    ctx->pc = 0x146a24u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 22), 16)));
label_146a28:
    // 0x146a28: 0x24040180
    ctx->pc = 0x146a28u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 384));
    // 0x146a2c: 0x44a818
    ctx->pc = 0x146a2cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 21, (int32_t)(uint32_t)result); }
    // 0x146a30: 0x10600004
    ctx->pc = 0x146A30u;
    {
        const bool branch_taken_0x146a30 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x146A34u;
        SET_GPR_S32(ctx, 20, SRA32(GPR_S32(ctx, 21), 4));
        if (branch_taken_0x146a30) {
            ctx->pc = 0x146A44u;
            goto label_146a44;
        }
    }
    ctx->pc = 0x146A38u;
    // 0x146a38: 0x31103
    ctx->pc = 0x146a38u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 3), 4));
    // 0x146a3c: 0x10000002
    ctx->pc = 0x146A3Cu;
    {
        const bool branch_taken_0x146a3c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x146A40u;
        { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 30, (int32_t)(uint32_t)result); }
        if (branch_taken_0x146a3c) {
            ctx->pc = 0x146A48u;
            goto label_146a48;
        }
    }
    ctx->pc = 0x146A44u;
label_146a44:
    // 0x146a44: 0x2a0f02d
    ctx->pc = 0x146a44u;
    SET_GPR_U64(ctx, 30, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
label_146a48:
    // 0x146a48: 0x24020001
    ctx->pc = 0x146a48u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x146a4c: 0x1000000b
    ctx->pc = 0x146A4Cu;
    {
        const bool branch_taken_0x146a4c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x146A50u;
        WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 2));
        if (branch_taken_0x146a4c) {
            ctx->pc = 0x146A7Cu;
            goto label_146a7c;
        }
    }
    ctx->pc = 0x146A54u;
label_146a54:
    // 0x146a54: 0x8ec20010
    ctx->pc = 0x146a54u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 22), 16)));
    // 0x146a58: 0x24050180
    ctx->pc = 0x146a58u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 384));
    // 0x146a5c: 0x240300c0
    ctx->pc = 0x146a5cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 192));
    // 0x146a60: 0x42103
    ctx->pc = 0x146a60u;
    SET_GPR_S32(ctx, 4, SRA32(GPR_S32(ctx, 4), 4));
    // 0x146a64: 0x21043
    ctx->pc = 0x146a64u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 1));
    // 0x146a68: 0x83f018
    ctx->pc = 0x146a68u;
    { int64_t result = (int64_t)GPR_S32(ctx, 4) * (int64_t)GPR_S32(ctx, 3); ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); SET_GPR_S32(ctx, 30, (int32_t)(uint32_t)result); }
    // 0x146a6c: 0x7045a818
    ctx->pc = 0x146a6cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 5); ctx->lo1 = (uint32_t)result; ctx->hi1 = (uint32_t)(result >> 32); }
    // 0x146a70: 0x24030002
    ctx->pc = 0x146a70u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
    // 0x146a74: 0xafa30004
    ctx->pc = 0x146a74u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 3));
    // 0x146a78: 0x15a103
    ctx->pc = 0x146a78u;
    SET_GPR_S32(ctx, 20, SRA32(GPR_S32(ctx, 21), 4));
label_146a7c:
    // 0x146a7c: 0x8fa60004
    ctx->pc = 0x146a7cu;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x146a80: 0x10c00061
    ctx->pc = 0x146A80u;
    {
        const bool branch_taken_0x146a80 = (GPR_U32(ctx, 6) == GPR_U32(ctx, 0));
        ctx->pc = 0x146A84u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x146a80) {
            ctx->pc = 0x146C08u;
            goto label_146c08;
        }
    }
    ctx->pc = 0x146A88u;
    // 0x146a88: 0x8ec6000c
    ctx->pc = 0x146a88u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 22), 12)));
    // 0x146a8c: 0x0
    ctx->pc = 0x146a8cu;
    // NOP
label_146a90:
    // 0x146a90: 0x8fb10008
    ctx->pc = 0x146a90u;
    SET_GPR_U32(ctx, 17, READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x146a94: 0x18c0004f
    ctx->pc = 0x146A94u;
    {
        const bool branch_taken_0x146a94 = (GPR_S32(ctx, 6) <= 0);
        ctx->pc = 0x146A98u;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x146a94) {
            ctx->pc = 0x146BD4u;
            goto label_146bd4;
        }
    }
    ctx->pc = 0x146A9Cu;
    // 0x146a9c: 0x24b70001
    ctx->pc = 0x146a9cu;
    SET_GPR_S32(ctx, 23, ADD32(GPR_U32(ctx, 5), 1));
label_146aa0:
    // 0x146aa0: 0xc047598
    ctx->pc = 0x146AA0u;
    SET_GPR_U32(ctx, 31, 0x146AA8u);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146AA8u; }
    }
    if (ctx->pc != 0x146AA8u) { return; }
    ctx->pc = 0x146AA8u;
    // 0x146aa8: 0x3c031000
    ctx->pc = 0x146aa8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x146aac: 0x3c051000
    ctx->pc = 0x146aacu;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x146ab0: 0x3463d480
    ctx->pc = 0x146ab0u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 54400));
    // 0x146ab4: 0x34a5d410
    ctx->pc = 0x146ab4u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 54288));
    // 0x146ab8: 0xac600000
    ctx->pc = 0x146ab8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x146abc: 0x3c041000
    ctx->pc = 0x146abcu;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x146ac0: 0xacb20000
    ctx->pc = 0x146ac0u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 18)); // MMIO: 0x10000000
    // 0x146ac4: 0x3484d420
    ctx->pc = 0x146ac4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 54304));
    // 0x146ac8: 0x3c051000
    ctx->pc = 0x146ac8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x146acc: 0xac940000
    ctx->pc = 0x146accu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 20)); // MMIO: 0x10000000
    // 0x146ad0: 0x34a5d400
    ctx->pc = 0x146ad0u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 54272));
    // 0x146ad4: 0x24030101
    ctx->pc = 0x146ad4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 257));
    // 0x146ad8: 0xaca30000
    ctx->pc = 0x146ad8u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x146adc: 0x10400004
    ctx->pc = 0x146ADCu;
    {
        const bool branch_taken_0x146adc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x146AE0u;
        SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
        if (branch_taken_0x146adc) {
            ctx->pc = 0x146AF0u;
            goto label_146af0;
        }
    }
    ctx->pc = 0x146AE4u;
    // 0x146ae4: 0xc0475ae
    ctx->pc = 0x146AE4u;
    SET_GPR_U32(ctx, 31, 0x146AECu);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146AECu; }
    }
    if (ctx->pc != 0x146AECu) { return; }
    ctx->pc = 0x146AECu;
    // 0x146aec: 0x3c031000
    ctx->pc = 0x146aecu;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
label_146af0:
    // 0x146af0: 0x2559821
    ctx->pc = 0x146af0u;
    SET_GPR_U32(ctx, 19, ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 21)));
    // 0x146af4: 0x26100001
    ctx->pc = 0x146af4u;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 16), 1));
    // 0x146af8: 0x23e9021
    ctx->pc = 0x146af8u;
    SET_GPR_U32(ctx, 18, ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 30)));
    // 0x146afc: 0x3463d400
    ctx->pc = 0x146afcu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 54272));
label_146b00:
    // 0x146b00: 0x8c620000
    ctx->pc = 0x146b00u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x146b04: 0x30420100
    ctx->pc = 0x146b04u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 256));
    // 0x146b08: 0x0
    ctx->pc = 0x146b08u;
    // NOP
    // 0x146b0c: 0x0
    ctx->pc = 0x146b0cu;
    // NOP
    // 0x146b10: 0x0
    ctx->pc = 0x146b10u;
    // NOP
    // 0x146b14: 0x1440fffa
    ctx->pc = 0x146B14u;
    {
        const bool branch_taken_0x146b14 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x146b14) {
            ctx->pc = 0x146B00u;
            goto label_146b00;
        }
    }
    ctx->pc = 0x146B1Cu;
    // 0x146b1c: 0xc047598
    ctx->pc = 0x146B1Cu;
    SET_GPR_U32(ctx, 31, 0x146B24u);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146B24u; }
    }
    if (ctx->pc != 0x146B24u) { return; }
    ctx->pc = 0x146B24u;
    // 0x146b24: 0x3c031000
    ctx->pc = 0x146b24u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x146b28: 0x3c051000
    ctx->pc = 0x146b28u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x146b2c: 0x3463d080
    ctx->pc = 0x146b2cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 53376));
    // 0x146b30: 0x34a5d010
    ctx->pc = 0x146b30u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 53264));
    // 0x146b34: 0xac600000
    ctx->pc = 0x146b34u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x146b38: 0x3c041000
    ctx->pc = 0x146b38u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x146b3c: 0xacb10000
    ctx->pc = 0x146b3cu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 17)); // MMIO: 0x10000000
    // 0x146b40: 0x3484d020
    ctx->pc = 0x146b40u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 53280));
    // 0x146b44: 0x3c051000
    ctx->pc = 0x146b44u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x146b48: 0xac940000
    ctx->pc = 0x146b48u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 20)); // MMIO: 0x10000000
    // 0x146b4c: 0x34a5d000
    ctx->pc = 0x146b4cu;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 53248));
    // 0x146b50: 0x24030100
    ctx->pc = 0x146b50u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 256));
    // 0x146b54: 0xaca30000
    ctx->pc = 0x146b54u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x146b58: 0x10400004
    ctx->pc = 0x146B58u;
    {
        const bool branch_taken_0x146b58 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x146B5Cu;
        SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
        if (branch_taken_0x146b58) {
            ctx->pc = 0x146B6Cu;
            goto label_146b6c;
        }
    }
    ctx->pc = 0x146B60u;
    // 0x146b60: 0xc0475ae
    ctx->pc = 0x146B60u;
    SET_GPR_U32(ctx, 31, 0x146B68u);
    ctx->pc = 0x11D6B8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D6B8_0x11d6b8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x146B68u; }
    }
    if (ctx->pc != 0x146B68u) { return; }
    ctx->pc = 0x146B68u;
    // 0x146b68: 0x3c031000
    ctx->pc = 0x146b68u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
label_146b6c:
    // 0x146b6c: 0x8ec6000c
    ctx->pc = 0x146b6cu;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 22), 12)));
    // 0x146b70: 0x3463d000
    ctx->pc = 0x146b70u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 53248));
    // 0x146b74: 0x0
    ctx->pc = 0x146b74u;
    // NOP
label_146b78:
    // 0x146b78: 0x8c620000
    ctx->pc = 0x146b78u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x146b7c: 0x30420100
    ctx->pc = 0x146b7cu;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), 256));
    // 0x146b80: 0x0
    ctx->pc = 0x146b80u;
    // NOP
    // 0x146b84: 0x0
    ctx->pc = 0x146b84u;
    // NOP
    // 0x146b88: 0x0
    ctx->pc = 0x146b88u;
    // NOP
    // 0x146b8c: 0x1440fffa
    ctx->pc = 0x146B8Cu;
    {
        const bool branch_taken_0x146b8c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x146b8c) {
            ctx->pc = 0x146B78u;
            goto label_146b78;
        }
    }
    ctx->pc = 0x146B94u;
    // 0x146b94: 0x3c031000
    ctx->pc = 0x146b94u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x146b98: 0x3463d020
    ctx->pc = 0x146b98u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 53280));
    // 0x146b9c: 0x0
    ctx->pc = 0x146b9cu;
    // NOP
label_146ba0:
    // 0x146ba0: 0x8c620000
    ctx->pc = 0x146ba0u;
    SET_GPR_U32(ctx, 2, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x146ba4: 0x0
    ctx->pc = 0x146ba4u;
    // NOP
    // 0x146ba8: 0x0
    ctx->pc = 0x146ba8u;
    // NOP
    // 0x146bac: 0x0
    ctx->pc = 0x146bacu;
    // NOP
    // 0x146bb0: 0x0
    ctx->pc = 0x146bb0u;
    // NOP
    // 0x146bb4: 0x1440fffa
    ctx->pc = 0x146BB4u;
    {
        const bool branch_taken_0x146bb4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x146bb4) {
            ctx->pc = 0x146BA0u;
            goto label_146ba0;
        }
    }
    ctx->pc = 0x146BBCu;
    // 0x146bbc: 0x240882d
    ctx->pc = 0x146bbcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146bc0: 0x206102a
    ctx->pc = 0x146bc0u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 16), GPR_S32(ctx, 6)));
    // 0x146bc4: 0x1440ffb6
    ctx->pc = 0x146BC4u;
    {
        const bool branch_taken_0x146bc4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        ctx->pc = 0x146BC8u;
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x146bc4) {
            ctx->pc = 0x146AA0u;
            goto label_146aa0;
        }
    }
    ctx->pc = 0x146BCCu;
    // 0x146bcc: 0x10000003
    ctx->pc = 0x146BCCu;
    {
        const bool branch_taken_0x146bcc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x146BD0u;
        SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x146bcc) {
            ctx->pc = 0x146BDCu;
            goto label_146bdc;
        }
    }
    ctx->pc = 0x146BD4u;
label_146bd4:
    // 0x146bd4: 0x24b70001
    ctx->pc = 0x146bd4u;
    SET_GPR_S32(ctx, 23, ADD32(GPR_U32(ctx, 5), 1));
    // 0x146bd8: 0x8fa70000
    ctx->pc = 0x146bd8u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 29), 0)));
label_146bdc:
    // 0x146bdc: 0x2e0282d
    ctx->pc = 0x146bdcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x146be0: 0x240300c0
    ctx->pc = 0x146be0u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 192));
    // 0x146be4: 0x8ce200fc
    ctx->pc = 0x146be4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 7), 252)));
    // 0x146be8: 0x8fa70004
    ctx->pc = 0x146be8u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x146bec: 0xa7202a
    ctx->pc = 0x146becu;
    SET_GPR_U32(ctx, 4, SLT32(GPR_S32(ctx, 5), GPR_S32(ctx, 7)));
    // 0x146bf0: 0x8fa70008
    ctx->pc = 0x146bf0u;
    SET_GPR_U32(ctx, 7, READ32(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x146bf4: 0xe00013
    ctx->pc = 0x146bf4u;
    ctx->lo = GPR_U32(ctx, 7);
    // 0x146bf8: 0x70430000
    ctx->pc = 0x146bf8u;
    { int64_t acc = ((int64_t)ctx->hi << 32) | ctx->lo; int64_t prod = (int64_t)GPR_S32(ctx, 2) * (int64_t)GPR_S32(ctx, 3); int64_t result = acc + prod; ctx->lo = (uint32_t)result; ctx->hi = (uint32_t)(result >> 32); }
    // 0x146bfc: 0x3812
    ctx->pc = 0x146bfcu;
    SET_GPR_U32(ctx, 7, ctx->lo);
    // 0x146c00: 0x1480ffa3
    ctx->pc = 0x146C00u;
    {
        const bool branch_taken_0x146c00 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x146C04u;
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 7));
        if (branch_taken_0x146c00) {
            ctx->pc = 0x146A90u;
            goto label_146a90;
        }
    }
    ctx->pc = 0x146C08u;
label_146c08:
    // 0x146c08: 0xdfbf00a0
    ctx->pc = 0x146c08u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 160)));
    // 0x146c0c: 0xdfbe0090
    ctx->pc = 0x146c0cu;
    SET_GPR_U64(ctx, 30, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x146c10: 0xdfb70080
    ctx->pc = 0x146c10u;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x146c14: 0xdfb60070
    ctx->pc = 0x146c14u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x146c18: 0xdfb50060
    ctx->pc = 0x146c18u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x146c1c: 0xdfb40050
    ctx->pc = 0x146c1cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x146c20: 0xdfb30040
    ctx->pc = 0x146c20u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x146c24: 0xdfb20030
    ctx->pc = 0x146c24u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x146c28: 0xdfb10020
    ctx->pc = 0x146c28u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x146c2c: 0xdfb00010
    ctx->pc = 0x146c2cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x146c30: 0x3e00008
    ctx->pc = 0x146C30u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x146C34u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 176));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x146A1Cu: goto label_146a1c;
            case 0x146A28u: goto label_146a28;
            case 0x146A44u: goto label_146a44;
            case 0x146A48u: goto label_146a48;
            case 0x146A54u: goto label_146a54;
            case 0x146A7Cu: goto label_146a7c;
            case 0x146A90u: goto label_146a90;
            case 0x146AA0u: goto label_146aa0;
            case 0x146AF0u: goto label_146af0;
            case 0x146B00u: goto label_146b00;
            case 0x146B6Cu: goto label_146b6c;
            case 0x146B78u: goto label_146b78;
            case 0x146BA0u: goto label_146ba0;
            case 0x146BD4u: goto label_146bd4;
            case 0x146BDCu: goto label_146bdc;
            case 0x146C08u: goto label_146c08;
            case 0x146C58u: goto label_146c58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x146C38u;
    // 0x146c38: 0x8c820008
    ctx->pc = 0x146c38u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 8)));
    // 0x146c3c: 0x24030002
    ctx->pc = 0x146c3cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
    // 0x146c40: 0x10430005
    ctx->pc = 0x146C40u;
    {
        const bool branch_taken_0x146c40 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 3));
        ctx->pc = 0x146C44u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x146c40) {
            ctx->pc = 0x146C58u;
            goto label_146c58;
        }
    }
    ctx->pc = 0x146C48u;
    // 0x146c48: 0x8c820130
    ctx->pc = 0x146c48u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 304)));
    // 0x146c4c: 0xac830008
    ctx->pc = 0x146c4cu;
    WRITE32(ADD32(GPR_U32(ctx, 4), 8), GPR_U32(ctx, 3));
    // 0x146c50: 0xac8200c4
    ctx->pc = 0x146c50u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 196), GPR_U32(ctx, 2));
    // 0x146c54: 0x24020001
    ctx->pc = 0x146c54u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_146c58:
    // 0x146c58: 0x3e00008
    ctx->pc = 0x146C58u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x146C5Cu;
        WRITE32(ADD32(GPR_U32(ctx, 4), 2104), GPR_U32(ctx, 2));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x146A1Cu: goto label_146a1c;
            case 0x146A28u: goto label_146a28;
            case 0x146A44u: goto label_146a44;
            case 0x146A48u: goto label_146a48;
            case 0x146A54u: goto label_146a54;
            case 0x146A7Cu: goto label_146a7c;
            case 0x146A90u: goto label_146a90;
            case 0x146AA0u: goto label_146aa0;
            case 0x146AF0u: goto label_146af0;
            case 0x146B00u: goto label_146b00;
            case 0x146B6Cu: goto label_146b6c;
            case 0x146B78u: goto label_146b78;
            case 0x146BA0u: goto label_146ba0;
            case 0x146BD4u: goto label_146bd4;
            case 0x146BDCu: goto label_146bdc;
            case 0x146C08u: goto label_146c08;
            case 0x146C58u: goto label_146c58;
            default: break;
        }
        return;
    }
    ctx->pc = 0x146C60u;
}
