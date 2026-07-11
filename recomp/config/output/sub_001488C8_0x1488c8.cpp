#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001488C8
// Address: 0x1488c8 - 0x1489c8
void sub_001488C8_0x1488c8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1488c8u;

    // 0x1488c8: 0x27bdffe0
    ctx->pc = 0x1488c8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1488cc: 0x2484088f
    ctx->pc = 0x1488ccu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 2191));
    // 0x1488d0: 0xffb00000
    ctx->pc = 0x1488d0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1488d4: 0x42102
    ctx->pc = 0x1488d4u;
    SET_GPR_U32(ctx, 4, SRL32(GPR_U32(ctx, 4), 4));
    // 0x1488d8: 0x48100
    ctx->pc = 0x1488d8u;
    SET_GPR_U32(ctx, 16, SLL32(GPR_U32(ctx, 4), 4));
    // 0x1488dc: 0xffbf0010
    ctx->pc = 0x1488dcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
    // 0x1488e0: 0xa0582d
    ctx->pc = 0x1488e0u;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1488e4: 0xc0402d
    ctx->pc = 0x1488e4u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1488e8: 0x1900001e
    ctx->pc = 0x1488E8u;
    {
        const bool branch_taken_0x1488e8 = (GPR_S32(ctx, 8) <= 0);
        ctx->pc = 0x1488ECu;
        SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x1488e8) {
            ctx->pc = 0x148964u;
            goto label_148964;
        }
    }
    ctx->pc = 0x1488F0u;
    // 0x1488f0: 0x3c09000f
    ctx->pc = 0x1488f0u;
    SET_GPR_U32(ctx, 9, ((uint32_t)15 << 16));
    // 0x1488f4: 0x3c0c0fff
    ctx->pc = 0x1488f4u;
    SET_GPR_U32(ctx, 12, ((uint32_t)4095 << 16));
    // 0x1488f8: 0x3529ff40
    ctx->pc = 0x1488f8u;
    SET_GPR_U32(ctx, 9, OR32(GPR_U32(ctx, 9), 65344));
    // 0x1488fc: 0x358cffff
    ctx->pc = 0x1488fcu;
    SET_GPR_U32(ctx, 12, OR32(GPR_U32(ctx, 12), 65535));
    // 0x148900: 0x240e0003
    ctx->pc = 0x148900u;
    SET_GPR_S32(ctx, 14, ADD32(GPR_U32(ctx, 0), 3));
    // 0x148904: 0x240dffff
    ctx->pc = 0x148904u;
    SET_GPR_S32(ctx, 13, ADD32(GPR_U32(ctx, 0), 4294967295));
label_148908:
    // 0x148908: 0x128102a
    ctx->pc = 0x148908u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 9), GPR_S32(ctx, 8)));
    // 0x14890c: 0x120382d
    ctx->pc = 0x14890cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148910: 0x102380a
    ctx->pc = 0x148910u;
    if (GPR_U32(ctx, 2) == 0) SET_GPR_U32(ctx, 7, GPR_U32(ctx, 8));
    // 0x148914: 0x182d
    ctx->pc = 0x148914u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x148918: 0x24e6000f
    ctx->pc = 0x148918u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 7), 15));
    // 0x14891c: 0x24e2001e
    ctx->pc = 0x14891cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 7), 30));
    // 0x148920: 0x1a6282a
    ctx->pc = 0x148920u;
    SET_GPR_U32(ctx, 5, SLT32(GPR_S32(ctx, 13), GPR_S32(ctx, 6)));
    // 0x148924: 0x1074023
    ctx->pc = 0x148924u;
    SET_GPR_U32(ctx, 8, SUB32(GPR_U32(ctx, 8), GPR_U32(ctx, 7)));
    // 0x148928: 0xc5100b
    ctx->pc = 0x148928u;
    if (GPR_U32(ctx, 5) != 0) SET_GPR_U32(ctx, 2, GPR_U32(ctx, 6));
    // 0x14892c: 0x16c2024
    ctx->pc = 0x14892cu;
    SET_GPR_U32(ctx, 4, AND32(GPR_U32(ctx, 11), GPR_U32(ctx, 12)));
    // 0x148930: 0x1c8180b
    ctx->pc = 0x148930u;
    if (GPR_U32(ctx, 8) != 0) SET_GPR_U32(ctx, 3, GPR_U32(ctx, 14));
    // 0x148934: 0x21103
    ctx->pc = 0x148934u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 4));
    // 0x148938: 0x4203c
    ctx->pc = 0x148938u;
    SET_GPR_U64(ctx, 4, GPR_U64(ctx, 4) << (32 + 0));
    // 0x14893c: 0x31f38
    ctx->pc = 0x14893cu;
    SET_GPR_U64(ctx, 3, GPR_U64(ctx, 3) << 28);
    // 0x148940: 0x2103c
    ctx->pc = 0x148940u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 0));
    // 0x148944: 0x832025
    ctx->pc = 0x148944u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x148948: 0x2103e
    ctx->pc = 0x148948u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) >> (32 + 0));
    // 0x14894c: 0x822025
    ctx->pc = 0x14894cu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), GPR_U32(ctx, 2)));
    // 0x148950: 0xfd440000
    ctx->pc = 0x148950u;
    WRITE64(ADD32(GPR_U32(ctx, 10), 0), GPR_U64(ctx, 4));
    // 0x148954: 0xf
    ctx->pc = 0x148954u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x148958: 0x1675821
    ctx->pc = 0x148958u;
    SET_GPR_U32(ctx, 11, ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 7)));
    // 0x14895c: 0x1d00ffea
    ctx->pc = 0x14895Cu;
    {
        const bool branch_taken_0x14895c = (GPR_S32(ctx, 8) > 0);
        ctx->pc = 0x148960u;
        SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 10), 16));
        if (branch_taken_0x14895c) {
            ctx->pc = 0x148908u;
            goto label_148908;
        }
    }
    ctx->pc = 0x148964u;
label_148964:
    // 0x148964: 0xc045228
    ctx->pc = 0x148964u;
    SET_GPR_U32(ctx, 31, 0x14896Cu);
    ctx->pc = 0x148968u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1148A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x14896Cu; }
    }
    if (ctx->pc != 0x14896Cu) { return; }
    ctx->pc = 0x14896Cu;
    // 0x14896c: 0xc047598
    ctx->pc = 0x14896Cu;
    SET_GPR_U32(ctx, 31, 0x148974u);
    ctx->pc = 0x11D660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011D660_0x11d660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x148974u; }
    }
    if (ctx->pc != 0x148974u) { return; }
    ctx->pc = 0x148974u;
    // 0x148974: 0x3c030fff
    ctx->pc = 0x148974u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4095 << 16));
    // 0x148978: 0x3c051000
    ctx->pc = 0x148978u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4096 << 16));
    // 0x14897c: 0x3463ffff
    ctx->pc = 0x14897cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 65535));
    // 0x148980: 0x34a5b430
    ctx->pc = 0x148980u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 46128));
    // 0x148984: 0x2031824
    ctx->pc = 0x148984u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
    // 0x148988: 0x3c041000
    ctx->pc = 0x148988u;
    SET_GPR_U32(ctx, 4, ((uint32_t)4096 << 16));
    // 0x14898c: 0xaca30000
    ctx->pc = 0x14898cu;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3)); // MMIO: 0x10000000
    // 0x148990: 0x3484b420
    ctx->pc = 0x148990u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 46112));
    // 0x148994: 0xac800000
    ctx->pc = 0x148994u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 0)); // MMIO: 0x10000000
    // 0x148998: 0x3c031000
    ctx->pc = 0x148998u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x14899c: 0x3463b400
    ctx->pc = 0x14899cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 46080));
    // 0x1489a0: 0x24040105
    ctx->pc = 0x1489a0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 261));
    // 0x1489a4: 0xac640000
    ctx->pc = 0x1489a4u;
    runtime->Store32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 4)); // MMIO: 0x10000000
    // 0x1489a8: 0x10400004
    ctx->pc = 0x1489A8u;
    {
        const bool branch_taken_0x1489a8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1489ACu;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
        if (branch_taken_0x1489a8) {
            ctx->pc = 0x1489BCu;
            goto label_1489bc;
        }
    }
    ctx->pc = 0x1489B0u;
    // 0x1489b0: 0xdfb00000
    ctx->pc = 0x1489b0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1489b4: 0x80475ae
    ctx->pc = 0x1489B4u;
    ctx->pc = 0x1489B8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
    ctx->pc = 0x11D6B8u;
    sub_0011D6B8_0x11d6b8(rdram, ctx, runtime); return;
    ctx->pc = 0x1489BCu;
label_1489bc:
    // 0x1489bc: 0xdfb00000
    ctx->pc = 0x1489bcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1489c0: 0x3e00008
    ctx->pc = 0x1489C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1489C4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x148908u: goto label_148908;
            case 0x148964u: goto label_148964;
            case 0x1489BCu: goto label_1489bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1489C8u;
}
