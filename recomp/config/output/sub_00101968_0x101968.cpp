#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00101968
// Address: 0x101968 - 0x101ae8
void sub_00101968_0x101968(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x101968u;

    // 0x101968: 0x27bdffb0
    ctx->pc = 0x101968u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x10196c: 0xffb00010
    ctx->pc = 0x10196cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x101970: 0xffb20030
    ctx->pc = 0x101970u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
    // 0x101974: 0x80802d
    ctx->pc = 0x101974u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101978: 0xffb10020
    ctx->pc = 0x101978u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x10197c: 0xffbf0040
    ctx->pc = 0x10197cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x101980: 0xc040338
    ctx->pc = 0x101980u;
    SET_GPR_U32(ctx, 31, 0x101988u);
    ctx->pc = 0x101984u;
    SET_GPR_U32(ctx, 17, ((uint32_t)32 << 16));
    ctx->pc = 0x100CE0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00100CE0_0x100ce0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101988u; }
    }
    if (ctx->pc != 0x101988u) { return; }
    ctx->pc = 0x101988u;
    // 0x101988: 0x24030006
    ctx->pc = 0x101988u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 6));
    // 0x10198c: 0x10430022
    ctx->pc = 0x10198Cu;
    {
        const bool branch_taken_0x10198c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 3));
        ctx->pc = 0x101990u;
        SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 17), 31232));
        if (branch_taken_0x10198c) {
            ctx->pc = 0x101A18u;
            goto label_101a18;
        }
    }
    ctx->pc = 0x101994u;
    // 0x101994: 0xc0402dc
    ctx->pc = 0x101994u;
    SET_GPR_U32(ctx, 31, 0x10199Cu);
    ctx->pc = 0x101998u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 9));
    ctx->pc = 0x100B70u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00100B70_0x100b70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x10199Cu; }
    }
    if (ctx->pc != 0x10199Cu) { return; }
    ctx->pc = 0x10199Cu;
    // 0x10199c: 0x1040001e
    ctx->pc = 0x10199Cu;
    {
        const bool branch_taken_0x10199c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1019A0u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x10199c) {
            ctx->pc = 0x101A18u;
            goto label_101a18;
        }
    }
    ctx->pc = 0x1019A4u;
    // 0x1019a4: 0xae307a00
    ctx->pc = 0x1019a4u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 31232), GPR_U32(ctx, 16));
    // 0x1019a8: 0x24050004
    ctx->pc = 0x1019a8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 4));
    // 0x1019ac: 0xc045bf4
    ctx->pc = 0x1019ACu;
    SET_GPR_U32(ctx, 31, 0x1019B4u);
    ctx->pc = 0x1019B0u;
    SET_GPR_U32(ctx, 16, ((uint32_t)32 << 16));
    ctx->pc = 0x116FD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116FD0_0x116fd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1019B4u; }
    }
    if (ctx->pc != 0x1019B4u) { return; }
    ctx->pc = 0x1019B4u;
    // 0x1019b4: 0x3c110020
    ctx->pc = 0x1019b4u;
    SET_GPR_U32(ctx, 17, ((uint32_t)32 << 16));
    // 0x1019b8: 0x26057958
    ctx->pc = 0x1019b8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 31064));
    // 0x1019bc: 0x24020004
    ctx->pc = 0x1019bcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4));
    // 0x1019c0: 0xae027958
    ctx->pc = 0x1019c0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 2));
    // 0x1019c4: 0x24030001
    ctx->pc = 0x1019c4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1019c8: 0x3c040021
    ctx->pc = 0x1019c8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)33 << 16));
    // 0x1019cc: 0x3c0b0010
    ctx->pc = 0x1019ccu;
    SET_GPR_U32(ctx, 11, ((uint32_t)16 << 16));
    // 0x1019d0: 0xafa50000
    ctx->pc = 0x1019d0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 5));
    // 0x1019d4: 0x24848ad0
    ctx->pc = 0x1019d4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294937296));
    // 0x1019d8: 0xae237934
    ctx->pc = 0x1019d8u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 31028), GPR_U32(ctx, 3));
    // 0x1019dc: 0x240382d
    ctx->pc = 0x1019dcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1019e0: 0x256b0298
    ctx->pc = 0x1019e0u;
    SET_GPR_S32(ctx, 11, ADD32(GPR_U32(ctx, 11), 664));
    // 0x1019e4: 0x24050005
    ctx->pc = 0x1019e4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 5));
    // 0x1019e8: 0x24060001
    ctx->pc = 0x1019e8u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1019ec: 0x24080004
    ctx->pc = 0x1019ecu;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 0), 4));
    // 0x1019f0: 0x482d
    ctx->pc = 0x1019f0u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1019f4: 0xc045e7a
    ctx->pc = 0x1019F4u;
    SET_GPR_U32(ctx, 31, 0x1019FCu);
    ctx->pc = 0x1019F8u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1179E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1019FCu; }
    }
    if (ctx->pc != 0x1019FCu) { return; }
    ctx->pc = 0x1019FCu;
    // 0x1019fc: 0x4430007
    ctx->pc = 0x1019FCu;
    {
        const bool branch_taken_0x1019fc = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x1019fc) {
            ctx->pc = 0x101A00u;
            SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
            ctx->pc = 0x101A1Cu;
            goto label_101a1c;
        }
    }
    ctx->pc = 0x101A04u;
    // 0x101a04: 0xae007958
    ctx->pc = 0x101a04u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 0));
    // 0x101a08: 0x3c020020
    ctx->pc = 0x101a08u;
    SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
    // 0x101a0c: 0xae207934
    ctx->pc = 0x101a0cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 31028), GPR_U32(ctx, 0));
    // 0x101a10: 0xc045190
    ctx->pc = 0x101A10u;
    SET_GPR_U32(ctx, 31, 0x101A18u);
    ctx->pc = 0x101A14u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 31016)));
    ctx->pc = 0x114640u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101A18u; }
    }
    if (ctx->pc != 0x101A18u) { return; }
    ctx->pc = 0x101A18u;
label_101a18:
    // 0x101a18: 0x102d
    ctx->pc = 0x101a18u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_101a1c:
    // 0x101a1c: 0xdfbf0040
    ctx->pc = 0x101a1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x101a20: 0xdfb20030
    ctx->pc = 0x101a20u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x101a24: 0xdfb10020
    ctx->pc = 0x101a24u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x101a28: 0xdfb00010
    ctx->pc = 0x101a28u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x101a2c: 0x3e00008
    ctx->pc = 0x101A2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101A30u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101A18u: goto label_101a18;
            case 0x101A1Cu: goto label_101a1c;
            case 0x101ACCu: goto label_101acc;
            case 0x101AD0u: goto label_101ad0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101A34u;
    // 0x101a34: 0x0
    ctx->pc = 0x101a34u;
    // NOP
    // 0x101a38: 0x27bdffc0
    ctx->pc = 0x101a38u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x101a3c: 0xffbf0030
    ctx->pc = 0x101a3cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x101a40: 0xffb10020
    ctx->pc = 0x101a40u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 17));
    // 0x101a44: 0xc040338
    ctx->pc = 0x101A44u;
    SET_GPR_U32(ctx, 31, 0x101A4Cu);
    ctx->pc = 0x101A48u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    ctx->pc = 0x100CE0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00100CE0_0x100ce0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101A4Cu; }
    }
    if (ctx->pc != 0x101A4Cu) { return; }
    ctx->pc = 0x101A4Cu;
    // 0x101a4c: 0x24030006
    ctx->pc = 0x101a4cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 6));
    // 0x101a50: 0x1043001f
    ctx->pc = 0x101A50u;
    {
        const bool branch_taken_0x101a50 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 3));
        ctx->pc = 0x101A54u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x101a50) {
            ctx->pc = 0x101AD0u;
            goto label_101ad0;
        }
    }
    ctx->pc = 0x101A58u;
    // 0x101a58: 0xc0402dc
    ctx->pc = 0x101A58u;
    SET_GPR_U32(ctx, 31, 0x101A60u);
    ctx->pc = 0x101A5Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 10));
    ctx->pc = 0x100B70u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00100B70_0x100b70(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101A60u; }
    }
    if (ctx->pc != 0x101A60u) { return; }
    ctx->pc = 0x101A60u;
    // 0x101a60: 0x1040001a
    ctx->pc = 0x101A60u;
    {
        const bool branch_taken_0x101a60 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x101A64u;
        SET_GPR_U32(ctx, 16, ((uint32_t)32 << 16));
        if (branch_taken_0x101a60) {
            ctx->pc = 0x101ACCu;
            goto label_101acc;
        }
    }
    ctx->pc = 0x101A68u;
    // 0x101a68: 0x24020005
    ctx->pc = 0x101a68u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 5));
    // 0x101a6c: 0xae027958
    ctx->pc = 0x101a6cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 2));
    // 0x101a70: 0x26037958
    ctx->pc = 0x101a70u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 16), 31064));
    // 0x101a74: 0x3c110020
    ctx->pc = 0x101a74u;
    SET_GPR_U32(ctx, 17, ((uint32_t)32 << 16));
    // 0x101a78: 0x24020001
    ctx->pc = 0x101a78u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x101a7c: 0x3c040021
    ctx->pc = 0x101a7cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)33 << 16));
    // 0x101a80: 0x3c0b0010
    ctx->pc = 0x101a80u;
    SET_GPR_U32(ctx, 11, ((uint32_t)16 << 16));
    // 0x101a84: 0xae227934
    ctx->pc = 0x101a84u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 31028), GPR_U32(ctx, 2));
    // 0x101a88: 0x24848ad0
    ctx->pc = 0x101a88u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294937296));
    // 0x101a8c: 0xafa30000
    ctx->pc = 0x101a8cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 3));
    // 0x101a90: 0x256b0298
    ctx->pc = 0x101a90u;
    SET_GPR_S32(ctx, 11, ADD32(GPR_U32(ctx, 11), 664));
    // 0x101a94: 0x24050006
    ctx->pc = 0x101a94u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 6));
    // 0x101a98: 0x24060001
    ctx->pc = 0x101a98u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1));
    // 0x101a9c: 0x382d
    ctx->pc = 0x101a9cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101aa0: 0x402d
    ctx->pc = 0x101aa0u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101aa4: 0x482d
    ctx->pc = 0x101aa4u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x101aa8: 0xc045e7a
    ctx->pc = 0x101AA8u;
    SET_GPR_U32(ctx, 31, 0x101AB0u);
    ctx->pc = 0x101AACu;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1179E8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001179E8_0x1179e8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101AB0u; }
    }
    if (ctx->pc != 0x101AB0u) { return; }
    ctx->pc = 0x101AB0u;
    // 0x101ab0: 0x4430007
    ctx->pc = 0x101AB0u;
    {
        const bool branch_taken_0x101ab0 = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x101ab0) {
            ctx->pc = 0x101AB4u;
            SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
            ctx->pc = 0x101AD0u;
            goto label_101ad0;
        }
    }
    ctx->pc = 0x101AB8u;
    // 0x101ab8: 0xae007958
    ctx->pc = 0x101ab8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 31064), GPR_U32(ctx, 0));
    // 0x101abc: 0x3c020020
    ctx->pc = 0x101abcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
    // 0x101ac0: 0xae207934
    ctx->pc = 0x101ac0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 31028), GPR_U32(ctx, 0));
    // 0x101ac4: 0xc045190
    ctx->pc = 0x101AC4u;
    SET_GPR_U32(ctx, 31, 0x101ACCu);
    ctx->pc = 0x101AC8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 31016)));
    ctx->pc = 0x114640u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x101ACCu; }
    }
    if (ctx->pc != 0x101ACCu) { return; }
    ctx->pc = 0x101ACCu;
label_101acc:
    // 0x101acc: 0x102d
    ctx->pc = 0x101accu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_101ad0:
    // 0x101ad0: 0xdfbf0030
    ctx->pc = 0x101ad0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x101ad4: 0xdfb10020
    ctx->pc = 0x101ad4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x101ad8: 0xdfb00010
    ctx->pc = 0x101ad8u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x101adc: 0x3e00008
    ctx->pc = 0x101ADCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x101AE0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x101A18u: goto label_101a18;
            case 0x101A1Cu: goto label_101a1c;
            case 0x101ACCu: goto label_101acc;
            case 0x101AD0u: goto label_101ad0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x101AE4u;
    // 0x101ae4: 0x0
    ctx->pc = 0x101ae4u;
    // NOP
}
