#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00100E88
// Address: 0x100e88 - 0x1010a8
void sub_00100E88_0x100e88(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x100e88u;

    // 0x100e88: 0x27bdffc0
    ctx->pc = 0x100e88u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x100e8c: 0xffb10010
    ctx->pc = 0x100e8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 17));
    // 0x100e90: 0xffb00000
    ctx->pc = 0x100e90u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x100e94: 0x80882d
    ctx->pc = 0x100e94u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100e98: 0xffbf0030
    ctx->pc = 0x100e98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x100e9c: 0x3c100020
    ctx->pc = 0x100e9cu;
    SET_GPR_U32(ctx, 16, ((uint32_t)32 << 16));
    // 0x100ea0: 0xc040164
    ctx->pc = 0x100EA0u;
    SET_GPR_U32(ctx, 31, 0x100EA8u);
    ctx->pc = 0x100EA4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    ctx->pc = 0x100590u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00100590_0x100590(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100EA8u; }
    }
    if (ctx->pc != 0x100EA8u) { return; }
    ctx->pc = 0x100EA8u;
    // 0x100ea8: 0x8e04792c
    ctx->pc = 0x100ea8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 31020)));
    // 0x100eac: 0xc04519c
    ctx->pc = 0x100EACu;
    SET_GPR_U32(ctx, 31, 0x100EB4u);
    ctx->pc = 0x114670u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114670_0x114670(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100EB4u; }
    }
    if (ctx->pc != 0x100EB4u) { return; }
    ctx->pc = 0x100EB4u;
    // 0x100eb4: 0x8e03792c
    ctx->pc = 0x100eb4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 31020)));
    // 0x100eb8: 0x1062000b
    ctx->pc = 0x100EB8u;
    {
        const bool branch_taken_0x100eb8 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 2));
        ctx->pc = 0x100EBCu;
        SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
        if (branch_taken_0x100eb8) {
            ctx->pc = 0x100EE8u;
            goto label_100ee8;
        }
    }
    ctx->pc = 0x100EC0u;
    // 0x100ec0: 0x8c437910
    ctx->pc = 0x100ec0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 30992)));
    // 0x100ec4: 0x18600016
    ctx->pc = 0x100EC4u;
    {
        const bool branch_taken_0x100ec4 = (GPR_S32(ctx, 3) <= 0);
        ctx->pc = 0x100EC8u;
        SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
        if (branch_taken_0x100ec4) {
            ctx->pc = 0x100F20u;
            goto label_100f20;
        }
    }
    ctx->pc = 0x100ECCu;
    // 0x100ecc: 0x3c040023
    ctx->pc = 0x100eccu;
    SET_GPR_U32(ctx, 4, ((uint32_t)35 << 16));
    // 0x100ed0: 0x8c467918
    ctx->pc = 0x100ed0u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 2), 31000)));
    // 0x100ed4: 0x24847578
    ctx->pc = 0x100ed4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 30072));
    // 0x100ed8: 0xc045a12
    ctx->pc = 0x100ED8u;
    SET_GPR_U32(ctx, 31, 0x100EE0u);
    ctx->pc = 0x100EDCu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100EE0u; }
    }
    if (ctx->pc != 0x100EE0u) { return; }
    ctx->pc = 0x100EE0u;
    // 0x100ee0: 0x1000003f
    ctx->pc = 0x100EE0u;
    {
        const bool branch_taken_0x100ee0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x100EE4u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x100ee0) {
            ctx->pc = 0x100FE0u;
            goto label_100fe0;
        }
    }
    ctx->pc = 0x100EE8u;
label_100ee8:
    // 0x100ee8: 0x3c020026
    ctx->pc = 0x100ee8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)38 << 16));
    // 0x100eec: 0x3c030020
    ctx->pc = 0x100eecu;
    SET_GPR_U32(ctx, 3, ((uint32_t)32 << 16));
    // 0x100ef0: 0x8c449f98
    ctx->pc = 0x100ef0u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 2), 4294942616)));
    // 0x100ef4: 0x3c050026
    ctx->pc = 0x100ef4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)38 << 16));
    // 0x100ef8: 0x0
    ctx->pc = 0x100ef8u;
    // NOP
    // 0x100efc: 0xc045148
    ctx->pc = 0x100EFCu;
    SET_GPR_U32(ctx, 31, 0x100F04u);
    ctx->pc = 0x100F00u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294942624));
    ctx->pc = 0x114520u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114520_0x114520(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100F04u; }
    }
    if (ctx->pc != 0x100F04u) { return; }
    ctx->pc = 0x100F04u;
    // 0x100f04: 0xc040386
    ctx->pc = 0x100F04u;
    SET_GPR_U32(ctx, 31, 0x100F0Cu);
    ctx->pc = 0x100F08u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x100E18u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00100E18_0x100e18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100F0Cu; }
    }
    if (ctx->pc != 0x100F0Cu) { return; }
    ctx->pc = 0x100F0Cu;
    // 0x100f0c: 0x10400006
    ctx->pc = 0x100F0Cu;
    {
        const bool branch_taken_0x100f0c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x100F10u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x100f0c) {
            ctx->pc = 0x100F28u;
            goto label_100f28;
        }
    }
    ctx->pc = 0x100F14u;
    // 0x100f14: 0x8e04792c
    ctx->pc = 0x100f14u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 31020)));
    // 0x100f18: 0xc045190
    ctx->pc = 0x100F18u;
    SET_GPR_U32(ctx, 31, 0x100F20u);
    ctx->pc = 0x114640u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100F20u; }
    }
    if (ctx->pc != 0x100F20u) { return; }
    ctx->pc = 0x100F20u;
label_100f20:
    // 0x100f20: 0x1000002f
    ctx->pc = 0x100F20u;
    {
        const bool branch_taken_0x100f20 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x100F24u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x100f20) {
            ctx->pc = 0x100FE0u;
            goto label_100fe0;
        }
    }
    ctx->pc = 0x100F28u;
label_100f28:
    // 0x100f28: 0xc045c20
    ctx->pc = 0x100F28u;
    SET_GPR_U32(ctx, 31, 0x100F30u);
    ctx->pc = 0x100F2Cu;
    SET_GPR_U32(ctx, 18, ((uint32_t)32 << 16));
    ctx->pc = 0x117080u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00117080_0x117080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100F30u; }
    }
    if (ctx->pc != 0x100F30u) { return; }
    ctx->pc = 0x100F30u;
    // 0x100f30: 0x8e42794c
    ctx->pc = 0x100f30u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 31052)));
    // 0x100f34: 0x441002a
    ctx->pc = 0x100F34u;
    {
        const bool branch_taken_0x100f34 = (GPR_S32(ctx, 2) >= 0);
        ctx->pc = 0x100F38u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x100f34) {
            ctx->pc = 0x100FE0u;
            goto label_100fe0;
        }
    }
    ctx->pc = 0x100F3Cu;
    // 0x100f3c: 0x1000000b
    ctx->pc = 0x100F3Cu;
    {
        const bool branch_taken_0x100f3c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x100F40u;
        SET_GPR_U32(ctx, 17, ((uint32_t)33 << 16));
        if (branch_taken_0x100f3c) {
            ctx->pc = 0x100F6Cu;
            goto label_100f6c;
        }
    }
    ctx->pc = 0x100F44u;
    // 0x100f44: 0x0
    ctx->pc = 0x100f44u;
    // NOP
label_100f48:
    // 0x100f48: 0x3c020010
    ctx->pc = 0x100f48u;
    SET_GPR_U32(ctx, 2, ((uint32_t)16 << 16));
    // 0x100f4c: 0x2403ffff
    ctx->pc = 0x100f4cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
label_100f50:
    // 0x100f50: 0x2442ffff
    ctx->pc = 0x100f50u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x100f54: 0x0
    ctx->pc = 0x100f54u;
    // NOP
    // 0x100f58: 0x0
    ctx->pc = 0x100f58u;
    // NOP
    // 0x100f5c: 0x0
    ctx->pc = 0x100f5cu;
    // NOP
    // 0x100f60: 0x0
    ctx->pc = 0x100f60u;
    // NOP
    // 0x100f64: 0x1443fffa
    ctx->pc = 0x100F64u;
    {
        const bool branch_taken_0x100f64 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        if (branch_taken_0x100f64) {
            ctx->pc = 0x100F50u;
            goto label_100f50;
        }
    }
    ctx->pc = 0x100F6Cu;
label_100f6c:
    // 0x100f6c: 0x26309480
    ctx->pc = 0x100f6cu;
    SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 17), 4294939776));
label_100f70:
    // 0x100f70: 0x3c058000
    ctx->pc = 0x100f70u;
    SET_GPR_U32(ctx, 5, ((uint32_t)32768 << 16));
    // 0x100f74: 0x200202d
    ctx->pc = 0x100f74u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x100f78: 0x34a50593
    ctx->pc = 0x100f78u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 5), 1427));
    // 0x100f7c: 0xc045e06
    ctx->pc = 0x100F7Cu;
    SET_GPR_U32(ctx, 31, 0x100F84u);
    ctx->pc = 0x100F80u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x117818u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00117818_0x117818(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100F84u; }
    }
    if (ctx->pc != 0x100F84u) { return; }
    ctx->pc = 0x100F84u;
    // 0x100f84: 0x4430013
    ctx->pc = 0x100F84u;
    {
        const bool branch_taken_0x100f84 = (GPR_S32(ctx, 2) >= 0);
        if (branch_taken_0x100f84) {
            ctx->pc = 0x100F88u;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 36)));
            ctx->pc = 0x100FD4u;
            goto label_100fd4;
        }
    }
    ctx->pc = 0x100F8Cu;
    // 0x100f8c: 0x3c020020
    ctx->pc = 0x100f8cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
    // 0x100f90: 0x8c437910
    ctx->pc = 0x100f90u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 30992)));
    // 0x100f94: 0x18600005
    ctx->pc = 0x100F94u;
    {
        const bool branch_taken_0x100f94 = (GPR_S32(ctx, 3) <= 0);
        ctx->pc = 0x100F98u;
        SET_GPR_U32(ctx, 2, ((uint32_t)16 << 16));
        if (branch_taken_0x100f94) {
            ctx->pc = 0x100FACu;
            goto label_100fac;
        }
    }
    ctx->pc = 0x100F9Cu;
    // 0x100f9c: 0x3c040023
    ctx->pc = 0x100f9cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)35 << 16));
    // 0x100fa0: 0xc045a12
    ctx->pc = 0x100FA0u;
    SET_GPR_U32(ctx, 31, 0x100FA8u);
    ctx->pc = 0x100FA4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 30112));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x100FA8u; }
    }
    if (ctx->pc != 0x100FA8u) { return; }
    ctx->pc = 0x100FA8u;
    // 0x100fa8: 0x3c020010
    ctx->pc = 0x100fa8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)16 << 16));
label_100fac:
    // 0x100fac: 0x2403ffff
    ctx->pc = 0x100facu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
label_100fb0:
    // 0x100fb0: 0x2442ffff
    ctx->pc = 0x100fb0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x100fb4: 0x0
    ctx->pc = 0x100fb4u;
    // NOP
    // 0x100fb8: 0x0
    ctx->pc = 0x100fb8u;
    // NOP
    // 0x100fbc: 0x0
    ctx->pc = 0x100fbcu;
    // NOP
    // 0x100fc0: 0x0
    ctx->pc = 0x100fc0u;
    // NOP
    // 0x100fc4: 0x1443fffa
    ctx->pc = 0x100FC4u;
    {
        const bool branch_taken_0x100fc4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        if (branch_taken_0x100fc4) {
            ctx->pc = 0x100FB0u;
            goto label_100fb0;
        }
    }
    ctx->pc = 0x100FCCu;
    // 0x100fcc: 0x1000ffe8
    ctx->pc = 0x100FCCu;
    {
        const bool branch_taken_0x100fcc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x100FD0u;
        SET_GPR_S32(ctx, 16, ADD32(GPR_U32(ctx, 17), 4294939776));
        if (branch_taken_0x100fcc) {
            ctx->pc = 0x100F70u;
            goto label_100f70;
        }
    }
    ctx->pc = 0x100FD4u;
label_100fd4:
    // 0x100fd4: 0x1040ffdc
    ctx->pc = 0x100FD4u;
    {
        const bool branch_taken_0x100fd4 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x100FD8u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x100fd4) {
            ctx->pc = 0x100F48u;
            goto label_100f48;
        }
    }
    ctx->pc = 0x100FDCu;
    // 0x100fdc: 0xae40794c
    ctx->pc = 0x100fdcu;
    WRITE32(ADD32(GPR_U32(ctx, 18), 31052), GPR_U32(ctx, 0));
label_100fe0:
    // 0x100fe0: 0xdfbf0030
    ctx->pc = 0x100fe0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x100fe4: 0xdfb20020
    ctx->pc = 0x100fe4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x100fe8: 0xdfb10010
    ctx->pc = 0x100fe8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x100fec: 0xdfb00000
    ctx->pc = 0x100fecu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x100ff0: 0x3e00008
    ctx->pc = 0x100FF0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x100FF4u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100EE8u: goto label_100ee8;
            case 0x100F20u: goto label_100f20;
            case 0x100F28u: goto label_100f28;
            case 0x100F48u: goto label_100f48;
            case 0x100F50u: goto label_100f50;
            case 0x100F6Cu: goto label_100f6c;
            case 0x100F70u: goto label_100f70;
            case 0x100FACu: goto label_100fac;
            case 0x100FB0u: goto label_100fb0;
            case 0x100FD4u: goto label_100fd4;
            case 0x100FE0u: goto label_100fe0;
            case 0x101060u: goto label_101060;
            case 0x101068u: goto label_101068;
            case 0x101070u: goto label_101070;
            case 0x101080u: goto label_101080;
            case 0x101088u: goto label_101088;
            case 0x101090u: goto label_101090;
            case 0x101098u: goto label_101098;
            case 0x10109Cu: goto label_10109c;
            case 0x1010A0u: goto label_1010a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x100FF8u;
    // 0x100ff8: 0x34028001
    ctx->pc = 0x100ff8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 0), 32769));
    // 0x100ffc: 0x10820026
    ctx->pc = 0x100FFCu;
    {
        const bool branch_taken_0x100ffc = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        ctx->pc = 0x101000u;
        SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
        if (branch_taken_0x100ffc) {
            ctx->pc = 0x101098u;
            goto label_101098;
        }
    }
    ctx->pc = 0x101004u;
    // 0x101004: 0x34028003
    ctx->pc = 0x101004u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 0), 32771));
    // 0x101008: 0x10820021
    ctx->pc = 0x101008u;
    {
        const bool branch_taken_0x101008 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        ctx->pc = 0x10100Cu;
        SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
        if (branch_taken_0x101008) {
            ctx->pc = 0x101090u;
            goto label_101090;
        }
    }
    ctx->pc = 0x101010u;
    // 0x101010: 0x34028002
    ctx->pc = 0x101010u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 0), 32770));
    // 0x101014: 0x1082001c
    ctx->pc = 0x101014u;
    {
        const bool branch_taken_0x101014 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        ctx->pc = 0x101018u;
        SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
        if (branch_taken_0x101014) {
            ctx->pc = 0x101088u;
            goto label_101088;
        }
    }
    ctx->pc = 0x10101Cu;
    // 0x10101c: 0x34028004
    ctx->pc = 0x10101cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 0), 32772));
    // 0x101020: 0x10820017
    ctx->pc = 0x101020u;
    {
        const bool branch_taken_0x101020 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        ctx->pc = 0x101024u;
        SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
        if (branch_taken_0x101020) {
            ctx->pc = 0x101080u;
            goto label_101080;
        }
    }
    ctx->pc = 0x101028u;
    // 0x101028: 0x34028011
    ctx->pc = 0x101028u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 0), 32785));
    // 0x10102c: 0x10820010
    ctx->pc = 0x10102Cu;
    {
        const bool branch_taken_0x10102c = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        ctx->pc = 0x101030u;
        SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 0), 32787));
        if (branch_taken_0x10102c) {
            ctx->pc = 0x101070u;
            goto label_101070;
        }
    }
    ctx->pc = 0x101034u;
    // 0x101034: 0x1082000c
    ctx->pc = 0x101034u;
    {
        const bool branch_taken_0x101034 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        ctx->pc = 0x101038u;
        SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
        if (branch_taken_0x101034) {
            ctx->pc = 0x101068u;
            goto label_101068;
        }
    }
    ctx->pc = 0x10103Cu;
    // 0x10103c: 0x34028012
    ctx->pc = 0x10103cu;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 0), 32786));
    // 0x101040: 0x10820007
    ctx->pc = 0x101040u;
    {
        const bool branch_taken_0x101040 = (GPR_U32(ctx, 4) == GPR_U32(ctx, 2));
        ctx->pc = 0x101044u;
        SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
        if (branch_taken_0x101040) {
            ctx->pc = 0x101060u;
            goto label_101060;
        }
    }
    ctx->pc = 0x101048u;
    // 0x101048: 0x34028014
    ctx->pc = 0x101048u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 0), 32788));
    // 0x10104c: 0x54820013
    ctx->pc = 0x10104Cu;
    {
        const bool branch_taken_0x10104c = (GPR_U32(ctx, 4) != GPR_U32(ctx, 2));
        if (branch_taken_0x10104c) {
            ctx->pc = 0x101050u;
            SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101054u;
    // 0x101054: 0x3c020021
    ctx->pc = 0x101054u;
    SET_GPR_U32(ctx, 2, ((uint32_t)33 << 16));
    // 0x101058: 0x10000010
    ctx->pc = 0x101058u;
    {
        const bool branch_taken_0x101058 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x10105Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294939776));
        if (branch_taken_0x101058) {
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101060u;
label_101060:
    // 0x101060: 0x1000000e
    ctx->pc = 0x101060u;
    {
        const bool branch_taken_0x101060 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x101064u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294938432));
        if (branch_taken_0x101060) {
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101068u;
label_101068:
    // 0x101068: 0x1000000c
    ctx->pc = 0x101068u;
    {
        const bool branch_taken_0x101068 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x10106Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294937344));
        if (branch_taken_0x101068) {
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101070u;
label_101070:
    // 0x101070: 0x3c020020
    ctx->pc = 0x101070u;
    SET_GPR_U32(ctx, 2, ((uint32_t)32 << 16));
    // 0x101074: 0x8c42792c
    ctx->pc = 0x101074u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 31020)));
    // 0x101078: 0x10000009
    ctx->pc = 0x101078u;
    {
        const bool branch_taken_0x101078 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x10107Cu;
        WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
        if (branch_taken_0x101078) {
            ctx->pc = 0x1010A0u;
            goto label_1010a0;
        }
    }
    ctx->pc = 0x101080u;
label_101080:
    // 0x101080: 0x10000006
    ctx->pc = 0x101080u;
    {
        const bool branch_taken_0x101080 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x101084u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294937296));
        if (branch_taken_0x101080) {
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101088u;
label_101088:
    // 0x101088: 0x10000004
    ctx->pc = 0x101088u;
    {
        const bool branch_taken_0x101088 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x10108Cu;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 31232));
        if (branch_taken_0x101088) {
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101090u;
label_101090:
    // 0x101090: 0x10000002
    ctx->pc = 0x101090u;
    {
        const bool branch_taken_0x101090 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x101094u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 31104));
        if (branch_taken_0x101090) {
            ctx->pc = 0x10109Cu;
            goto label_10109c;
        }
    }
    ctx->pc = 0x101098u;
label_101098:
    // 0x101098: 0x8c427928
    ctx->pc = 0x101098u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 31016)));
label_10109c:
    // 0x10109c: 0xaca20000
    ctx->pc = 0x10109cu;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 2));
label_1010a0:
    // 0x1010a0: 0x3e00008
    ctx->pc = 0x1010A0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1010A4u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x100EE8u: goto label_100ee8;
            case 0x100F20u: goto label_100f20;
            case 0x100F28u: goto label_100f28;
            case 0x100F48u: goto label_100f48;
            case 0x100F50u: goto label_100f50;
            case 0x100F6Cu: goto label_100f6c;
            case 0x100F70u: goto label_100f70;
            case 0x100FACu: goto label_100fac;
            case 0x100FB0u: goto label_100fb0;
            case 0x100FD4u: goto label_100fd4;
            case 0x100FE0u: goto label_100fe0;
            case 0x101060u: goto label_101060;
            case 0x101068u: goto label_101068;
            case 0x101070u: goto label_101070;
            case 0x101080u: goto label_101080;
            case 0x101088u: goto label_101088;
            case 0x101090u: goto label_101090;
            case 0x101098u: goto label_101098;
            case 0x10109Cu: goto label_10109c;
            case 0x1010A0u: goto label_1010a0;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1010A8u;
}
