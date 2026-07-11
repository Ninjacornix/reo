#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0011DDE8
// Address: 0x11dde8 - 0x11df30
void sub_0011DDE8_0x11dde8(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x11dde8u;

    // 0x11dde8: 0x27bdffc0
    ctx->pc = 0x11dde8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x11ddec: 0x3c021000
    ctx->pc = 0x11ddecu;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x11ddf0: 0xffbf0030
    ctx->pc = 0x11ddf0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x11ddf4: 0x34421810
    ctx->pc = 0x11ddf4u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 6160));
    // 0x11ddf8: 0xffb20020
    ctx->pc = 0x11ddf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x11ddfc: 0xffb10010
    ctx->pc = 0x11ddfcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x11de00: 0xffb00000
    ctx->pc = 0x11de00u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x11de04: 0x8c430000
    ctx->pc = 0x11de04u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x11de08: 0x30630100
    ctx->pc = 0x11de08u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), 256));
    // 0x11de0c: 0x14600026
    ctx->pc = 0x11DE0Cu;
    {
        const bool branch_taken_0x11de0c = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x11DE10u;
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
        if (branch_taken_0x11de0c) {
            ctx->pc = 0x11DEA8u;
            goto label_11dea8;
        }
    }
    ctx->pc = 0x11DE14u;
    // 0x11de14: 0x3c020021
    ctx->pc = 0x11de14u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x11de18: 0x24120002
    ctx->pc = 0x11de18u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 0), 2));
    // 0x11de1c: 0x2450b3a8
    ctx->pc = 0x11de1cu;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 2), 4294947752));
    // 0x11de20: 0x8c44b3a8
    ctx->pc = 0x11de20u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 4294947752)));
    // 0x11de24: 0x8e050004
    ctx->pc = 0x11de24u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x11de28: 0xc047760
    ctx->pc = 0x11DE28u;
    SET_GPR_U32(ctx, 31, 0x11DE30u);
    ctx->pc = 0x11DE2Cu;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 16), 16));
    ctx->pc = 0x11DD80u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DD80_0x11dd80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE30u; }
    }
    if (ctx->pc != 0x11DE30u) { return; }
    ctx->pc = 0x11DE30u;
    // 0x11de30: 0x3c050021
    ctx->pc = 0x11de30u;
    SET_GPR_U32(ctx, 5, ((uint32_t)33 << 16));
    // 0x11de34: 0x3c048007
    ctx->pc = 0x11de34u;
    SET_GPR_U32(ctx, 4, ((uint32_t)32775 << 16));
    // 0x11de38: 0x24a5ac40
    ctx->pc = 0x11de38u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294945856));
    // 0x11de3c: 0x34846000
    ctx->pc = 0x11de3cu;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 24576));
    // 0x11de40: 0xc047764
    ctx->pc = 0x11DE40u;
    SET_GPR_U32(ctx, 31, 0x11DE48u);
    ctx->pc = 0x11DE44u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 1856));
    ctx->pc = 0x11DD90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DD90_0x11dd90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE48u; }
    }
    if (ctx->pc != 0x11DE48u) { return; }
    ctx->pc = 0x11DE48u;
    // 0x11de48: 0x3c050021
    ctx->pc = 0x11de48u;
    SET_GPR_U32(ctx, 5, ((uint32_t)33 << 16));
    // 0x11de4c: 0x3c040008
    ctx->pc = 0x11de4cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)8 << 16));
    // 0x11de50: 0x24a5b380
    ctx->pc = 0x11de50u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294947712));
    // 0x11de54: 0x34842000
    ctx->pc = 0x11de54u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 4), 8192));
    // 0x11de58: 0xc047764
    ctx->pc = 0x11DE58u;
    SET_GPR_U32(ctx, 31, 0x11DE60u);
    ctx->pc = 0x11DE5Cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 40));
    ctx->pc = 0x11DD90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DD90_0x11dd90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE60u; }
    }
    if (ctx->pc != 0x11DE60u) { return; }
    ctx->pc = 0x11DE60u;
    // 0x11de60: 0xc045228
    ctx->pc = 0x11DE60u;
    SET_GPR_U32(ctx, 31, 0x11DE68u);
    ctx->pc = 0x11DE64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1148A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE68u; }
    }
    if (ctx->pc != 0x11DE68u) { return; }
    ctx->pc = 0x11DE68u;
    // 0x11de68: 0xc045228
    ctx->pc = 0x11DE68u;
    SET_GPR_U32(ctx, 31, 0x11DE70u);
    ctx->pc = 0x11DE6Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 2));
    ctx->pc = 0x1148A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001148A0_0x1148a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE70u; }
    }
    if (ctx->pc != 0x11DE70u) { return; }
    ctx->pc = 0x11DE70u;
    // 0x11de70: 0x8e040008
    ctx->pc = 0x11de70u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x11de74: 0xc047760
    ctx->pc = 0x11DE74u;
    SET_GPR_U32(ctx, 31, 0x11DE7Cu);
    ctx->pc = 0x11DE78u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 16), 12)));
    ctx->pc = 0x11DD80u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DD80_0x11dd80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE7Cu; }
    }
    if (ctx->pc != 0x11DE7Cu) { return; }
    ctx->pc = 0x11DE7Cu;
    // 0x11de7c: 0x8e240000
    ctx->pc = 0x11de7cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
label_11de80:
    // 0x11de80: 0xc047776
    ctx->pc = 0x11DE80u;
    SET_GPR_U32(ctx, 31, 0x11DE88u);
    ctx->pc = 0x11DE84u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 1));
    ctx->pc = 0x11DDD8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DDD8_0x11ddd8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE88u; }
    }
    if (ctx->pc != 0x11DE88u) { return; }
    ctx->pc = 0x11DE88u;
    // 0x11de88: 0x8e240000
    ctx->pc = 0x11de88u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x11de8c: 0x40282d
    ctx->pc = 0x11de8cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x11de90: 0xc047760
    ctx->pc = 0x11DE90u;
    SET_GPR_U32(ctx, 31, 0x11DE98u);
    ctx->pc = 0x11DE94u;
    SET_GPR_S32(ctx, 17, ADD32(GPR_U32(ctx, 17), 8));
    ctx->pc = 0x11DD80u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0011DD80_0x11dd80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x11DE98u; }
    }
    if (ctx->pc != 0x11DE98u) { return; }
    ctx->pc = 0x11DE98u;
    // 0x11de98: 0x2e420008
    ctx->pc = 0x11de98u;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 18), 8));
    // 0x11de9c: 0x5440fff8
    ctx->pc = 0x11DE9Cu;
    {
        const bool branch_taken_0x11de9c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x11de9c) {
            ctx->pc = 0x11DEA0u;
            SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 0)));
            ctx->pc = 0x11DE80u;
            goto label_11de80;
        }
    }
    ctx->pc = 0x11DEA4u;
    // 0x11dea4: 0xdfbf0030
    ctx->pc = 0x11dea4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_11dea8:
    // 0x11dea8: 0xdfb20020
    ctx->pc = 0x11dea8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x11deac: 0xdfb10010
    ctx->pc = 0x11deacu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x11deb0: 0xdfb00000
    ctx->pc = 0x11deb0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x11deb4: 0x3e00008
    ctx->pc = 0x11DEB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x11DEB8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11DE80u: goto label_11de80;
            case 0x11DEA8u: goto label_11dea8;
            case 0x11DED8u: goto label_11ded8;
            case 0x11DEFCu: goto label_11defc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11DEBCu;
    // 0x11debc: 0x0
    ctx->pc = 0x11debcu;
    // NOP
    // 0x11dec0: 0x40036000
    ctx->pc = 0x11dec0u;
    SET_GPR_U32(ctx, 3, ctx->cop0_status);
    // 0x11dec4: 0x3c020001
    ctx->pc = 0x11dec4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)1 << 16));
    // 0x11dec8: 0x621824
    ctx->pc = 0x11dec8u;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x11decc: 0x1060000b
    ctx->pc = 0x11DECCu;
    {
        const bool branch_taken_0x11decc = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x11DED0u;
        SET_GPR_U32(ctx, 6, ((uint32_t)1 << 16));
        if (branch_taken_0x11decc) {
            ctx->pc = 0x11DEFCu;
            goto label_11defc;
        }
    }
    ctx->pc = 0x11DED4u;
    // 0x11ded4: 0x0
    ctx->pc = 0x11ded4u;
    // NOP
label_11ded8:
    // 0x11ded8: 0x42000039
    ctx->pc = 0x11ded8u;
    ctx->cop0_status &= ~0x10000; // Disable interrupts
    // 0x11dedc: 0x40f
    ctx->pc = 0x11dedcu;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11dee0: 0x40026000
    ctx->pc = 0x11dee0u;
    SET_GPR_U32(ctx, 2, ctx->cop0_status);
    // 0x11dee4: 0x461024
    ctx->pc = 0x11dee4u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x11dee8: 0x0
    ctx->pc = 0x11dee8u;
    // NOP
    // 0x11deec: 0x0
    ctx->pc = 0x11deecu;
    // NOP
    // 0x11def0: 0x0
    ctx->pc = 0x11def0u;
    // NOP
    // 0x11def4: 0x1440fff8
    ctx->pc = 0x11DEF4u;
    {
        const bool branch_taken_0x11def4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x11def4) {
            ctx->pc = 0x11DED8u;
            goto label_11ded8;
        }
    }
    ctx->pc = 0x11DEFCu;
label_11defc:
    // 0x11defc: 0x40026000
    ctx->pc = 0x11defcu;
    SET_GPR_U32(ctx, 2, ctx->cop0_status);
    // 0x11df00: 0x40f
    ctx->pc = 0x11df00u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11df04: 0x34420006
    ctx->pc = 0x11df04u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 6));
    // 0x11df08: 0x38420002
    ctx->pc = 0x11df08u;
    SET_GPR_U32(ctx, 2, XOR32(GPR_U32(ctx, 2), 2));
    // 0x11df0c: 0x431025
    ctx->pc = 0x11df0cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x11df10: 0x40826000
    ctx->pc = 0x11df10u;
    ctx->cop0_status = GPR_U32(ctx, 2) & 0xFF57FFFF;
    // 0x11df14: 0x40f
    ctx->pc = 0x11df14u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11df18: 0xac850000
    ctx->pc = 0x11df18u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 5));
    // 0x11df1c: 0x409ff000
    ctx->pc = 0x11df1cu;
    ctx->cop0_errorepc = GPR_U32(ctx, 31);
    // 0x11df20: 0x40f
    ctx->pc = 0x11df20u;
    // SYNC instruction - memory barrier
// In recompiled code, we don't need explicit memory barriers
    // 0x11df24: 0x42000018
    ctx->pc = 0x11df24u;
    if (ctx->cop0_status & 0x4) { 
    ctx->pc = ctx->cop0_errorepc; 
    ctx->cop0_status &= ~0x4; 
} else { 
    ctx->pc = ctx->cop0_epc; 
    ctx->cop0_status &= ~0x2; 
} 
runtime->clearLLBit(ctx); 
return;
    // 0x11df28: 0x3e00008
    ctx->pc = 0x11DF28u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x11DE80u: goto label_11de80;
            case 0x11DEA8u: goto label_11dea8;
            case 0x11DED8u: goto label_11ded8;
            case 0x11DEFCu: goto label_11defc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x11DF30u;
}
