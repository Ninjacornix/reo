#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00199D00
// Address: 0x199d00 - 0x19c8e0
void sub_00199D00_0x199d00(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x199d00u;

label_199d00:
    // 0x199d00: 0x3c037000
    ctx->pc = 0x199d00u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x199d04: 0x240a0001
    ctx->pc = 0x199d04u;
    SET_GPR_S32(ctx, 10, ADD32(GPR_U32(ctx, 0), 1));
    // 0x199d08: 0x346b3700
    ctx->pc = 0x199d08u;
    SET_GPR_U32(ctx, 11, OR32(GPR_U32(ctx, 3), 14080));
label_199d0c:
    // 0x199d0c: 0xaa1824
    ctx->pc = 0x199d0cu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 5), GPR_U32(ctx, 10)));
    // 0x199d10: 0x10600009
    ctx->pc = 0x199D10u;
    {
        const bool branch_taken_0x199d10 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        if (branch_taken_0x199d10) {
            ctx->pc = 0x199D38u;
            goto label_199d38;
        }
    }
    ctx->pc = 0x199D18u;
    // 0x199d18: 0x79660000
    ctx->pc = 0x199d18u;
    SET_GPR_VEC(ctx, 6, READ128(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x199d1c: 0x79670010
    ctx->pc = 0x199d1cu;
    SET_GPR_VEC(ctx, 7, READ128(ADD32(GPR_U32(ctx, 11), 16)));
    // 0x199d20: 0x79680020
    ctx->pc = 0x199d20u;
    SET_GPR_VEC(ctx, 8, READ128(ADD32(GPR_U32(ctx, 11), 32)));
    // 0x199d24: 0x79690030
    ctx->pc = 0x199d24u;
    SET_GPR_VEC(ctx, 9, READ128(ADD32(GPR_U32(ctx, 11), 48)));
    // 0x199d28: 0x7c860000
    ctx->pc = 0x199d28u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 0), GPR_VEC(ctx, 6));
    // 0x199d2c: 0x7c870010
    ctx->pc = 0x199d2cu;
    WRITE128(ADD32(GPR_U32(ctx, 4), 16), GPR_VEC(ctx, 7));
    // 0x199d30: 0x7c880020
    ctx->pc = 0x199d30u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 32), GPR_VEC(ctx, 8));
    // 0x199d34: 0x7c890030
    ctx->pc = 0x199d34u;
    WRITE128(ADD32(GPR_U32(ctx, 4), 48), GPR_VEC(ctx, 9));
label_199d38:
    // 0x199d38: 0xa5040
    ctx->pc = 0x199d38u;
    SET_GPR_U32(ctx, 10, SLL32(GPR_U32(ctx, 10), 1));
    // 0x199d3c: 0x24840040
    ctx->pc = 0x199d3cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 64));
    // 0x199d40: 0x1540fff2
    ctx->pc = 0x199D40u;
    {
        const bool branch_taken_0x199d40 = (GPR_U32(ctx, 10) != GPR_U32(ctx, 0));
        ctx->pc = 0x199D44u;
        SET_GPR_S32(ctx, 11, ADD32(GPR_U32(ctx, 11), 64));
        if (branch_taken_0x199d40) {
            ctx->pc = 0x199D0Cu;
            goto label_199d0c;
        }
    }
    ctx->pc = 0x199D48u;
    // 0x199d48: 0x3e00008
    ctx->pc = 0x199D48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x199D50u;
    // 0x199d50: 0x27bdff80
    ctx->pc = 0x199d50u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x199d54: 0xffbf0030
    ctx->pc = 0x199d54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x199d58: 0x7fb20020
    ctx->pc = 0x199d58u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x199d5c: 0x7fb10010
    ctx->pc = 0x199d5cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x199d60: 0x80902d
    ctx->pc = 0x199d60u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x199d64: 0x7fb00000
    ctx->pc = 0x199d64u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x199d68: 0xa0882d
    ctx->pc = 0x199d68u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x199d6c: 0xc0802d
    ctx->pc = 0x199d6cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x199d70: 0x240400c0
    ctx->pc = 0x199d70u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 192));
    // 0x199d74: 0xc063774
    ctx->pc = 0x199D74u;
    SET_GPR_U32(ctx, 31, 0x199D7Cu);
    ctx->pc = 0x199D78u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199D7Cu; }
    }
    if (ctx->pc != 0x199D7Cu) { return; }
    ctx->pc = 0x199D7Cu;
    // 0x199d7c: 0x3c032000
    ctx->pc = 0x199d7cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x199d80: 0x3c080029
    ctx->pc = 0x199d80u;
    SET_GPR_U32(ctx, 8, ((uint32_t)41 << 16));
    // 0x199d84: 0x3464000b
    ctx->pc = 0x199d84u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 11));
    // 0x199d88: 0x3c051300
    ctx->pc = 0x199d88u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4864 << 16));
    // 0x199d8c: 0xac440000
    ctx->pc = 0x199d8cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x199d90: 0x3c030100
    ctx->pc = 0x199d90u;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x199d94: 0xac500004
    ctx->pc = 0x199d94u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x199d98: 0x34660404
    ctx->pc = 0x199d98u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 1028));
    // 0x199d9c: 0xfc400008
    ctx->pc = 0x199d9cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x199da0: 0x3c076c09
    ctx->pc = 0x199da0u;
    SET_GPR_U32(ctx, 7, ((uint32_t)27657 << 16));
    // 0x199da4: 0xac450010
    ctx->pc = 0x199da4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x199da8: 0x3c037000
    ctx->pc = 0x199da8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x199dac: 0xac400014
    ctx->pc = 0x199dacu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x199db0: 0x3c010029
    ctx->pc = 0x199db0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x199db4: 0xac460018
    ctx->pc = 0x199db4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x199db8: 0x24440030
    ctx->pc = 0x199db8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 48));
    // 0x199dbc: 0xac47001c
    ctx->pc = 0x199dbcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x199dc0: 0x34663700
    ctx->pc = 0x199dc0u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 14080));
    // 0x199dc4: 0x34673f40
    ctx->pc = 0x199dc4u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    // 0x199dc8: 0x27a50040
    ctx->pc = 0x199dc8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 64));
    // 0x199dcc: 0x8e43004c
    ctx->pc = 0x199dccu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x199dd0: 0xc4214e50
    ctx->pc = 0x199dd0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199dd4: 0x25084d40
    ctx->pc = 0x199dd4u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 19776));
    // 0x199dd8: 0xc4600024
    ctx->pc = 0x199dd8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199ddc: 0x3c010029
    ctx->pc = 0x199ddcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x199de0: 0x46000802
    ctx->pc = 0x199de0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x199de4: 0xe4400020
    ctx->pc = 0x199de4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x199de8: 0x8e43004c
    ctx->pc = 0x199de8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x199dec: 0xc4214e54
    ctx->pc = 0x199decu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199df0: 0xc4600024
    ctx->pc = 0x199df0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199df4: 0x3c010029
    ctx->pc = 0x199df4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x199df8: 0x46000802
    ctx->pc = 0x199df8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x199dfc: 0xe4400024
    ctx->pc = 0x199dfcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x199e00: 0x8e43004c
    ctx->pc = 0x199e00u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x199e04: 0xc4214e58
    ctx->pc = 0x199e04u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199e08: 0xc4600024
    ctx->pc = 0x199e08u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199e0c: 0x3c010029
    ctx->pc = 0x199e0cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x199e10: 0x46000802
    ctx->pc = 0x199e10u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x199e14: 0xe4400028
    ctx->pc = 0x199e14u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x199e18: 0xc4204e5c
    ctx->pc = 0x199e18u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199e1c: 0xc066500
    ctx->pc = 0x199E1Cu;
    SET_GPR_U32(ctx, 31, 0x199E24u);
    ctx->pc = 0x199E20u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    ctx->pc = 0x199400u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199E24u; }
    }
    if (ctx->pc != 0x199E24u) { return; }
    ctx->pc = 0x199E24u;
    // 0x199e24: 0x3c060029
    ctx->pc = 0x199e24u;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x199e28: 0x24440070
    ctx->pc = 0x199e28u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 112));
    // 0x199e2c: 0xc0664e0
    ctx->pc = 0x199E2Cu;
    SET_GPR_U32(ctx, 31, 0x199E34u);
    ctx->pc = 0x199E30u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19712));
    ctx->pc = 0x199380u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199E34u; }
    }
    if (ctx->pc != 0x199E34u) { return; }
    ctx->pc = 0x199E34u;
    // 0x199e34: 0x3c031500
    ctx->pc = 0x199e34u;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x199e38: 0x2231825
    ctx->pc = 0x199e38u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x199e3c: 0xac4300b0
    ctx->pc = 0x199e3cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 176), GPR_U32(ctx, 3));
    // 0x199e40: 0xac4000b4
    ctx->pc = 0x199e40u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 180), GPR_U32(ctx, 0));
    // 0x199e44: 0xac4000b8
    ctx->pc = 0x199e44u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 184), GPR_U32(ctx, 0));
    // 0x199e48: 0xac4000bc
    ctx->pc = 0x199e48u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 188), GPR_U32(ctx, 0));
    // 0x199e4c: 0xdfbf0030
    ctx->pc = 0x199e4cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x199e50: 0x7bb20020
    ctx->pc = 0x199e50u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x199e54: 0x7bb10010
    ctx->pc = 0x199e54u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x199e58: 0x7bb00000
    ctx->pc = 0x199e58u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x199e5c: 0x3e00008
    ctx->pc = 0x199E5Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x199E60u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 128));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x199E64u;
    // 0x199e64: 0x0
    ctx->pc = 0x199e64u;
    // NOP
    // 0x199e68: 0x0
    ctx->pc = 0x199e68u;
    // NOP
    // 0x199e6c: 0x0
    ctx->pc = 0x199e6cu;
    // NOP
    // 0x199e70: 0x27bdff50
    ctx->pc = 0x199e70u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x199e74: 0xffbf0030
    ctx->pc = 0x199e74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x199e78: 0x7fb20020
    ctx->pc = 0x199e78u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x199e7c: 0x7fb10010
    ctx->pc = 0x199e7cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x199e80: 0x80902d
    ctx->pc = 0x199e80u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x199e84: 0x7fb00000
    ctx->pc = 0x199e84u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x199e88: 0xa0882d
    ctx->pc = 0x199e88u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x199e8c: 0xc0802d
    ctx->pc = 0x199e8cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x199e90: 0x24040160
    ctx->pc = 0x199e90u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 352));
    // 0x199e94: 0xc063774
    ctx->pc = 0x199E94u;
    SET_GPR_U32(ctx, 31, 0x199E9Cu);
    ctx->pc = 0x199E98u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199E9Cu; }
    }
    if (ctx->pc != 0x199E9Cu) { return; }
    ctx->pc = 0x199E9Cu;
    // 0x199e9c: 0x3c032000
    ctx->pc = 0x199e9cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x199ea0: 0x3c080029
    ctx->pc = 0x199ea0u;
    SET_GPR_U32(ctx, 8, ((uint32_t)41 << 16));
    // 0x199ea4: 0x34640015
    ctx->pc = 0x199ea4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 21));
    // 0x199ea8: 0x3c051300
    ctx->pc = 0x199ea8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4864 << 16));
    // 0x199eac: 0xac440000
    ctx->pc = 0x199eacu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x199eb0: 0x3c030100
    ctx->pc = 0x199eb0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x199eb4: 0xac500004
    ctx->pc = 0x199eb4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x199eb8: 0x34660404
    ctx->pc = 0x199eb8u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 1028));
    // 0x199ebc: 0xfc400008
    ctx->pc = 0x199ebcu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x199ec0: 0x3c076c13
    ctx->pc = 0x199ec0u;
    SET_GPR_U32(ctx, 7, ((uint32_t)27667 << 16));
    // 0x199ec4: 0xac450010
    ctx->pc = 0x199ec4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x199ec8: 0x3c037000
    ctx->pc = 0x199ec8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x199ecc: 0xac400014
    ctx->pc = 0x199eccu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x199ed0: 0x3c010029
    ctx->pc = 0x199ed0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x199ed4: 0xac460018
    ctx->pc = 0x199ed4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x199ed8: 0x24440030
    ctx->pc = 0x199ed8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 48));
    // 0x199edc: 0xac47001c
    ctx->pc = 0x199edcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x199ee0: 0x34663700
    ctx->pc = 0x199ee0u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 14080));
    // 0x199ee4: 0x34673f40
    ctx->pc = 0x199ee4u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    // 0x199ee8: 0x27a50070
    ctx->pc = 0x199ee8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 112));
    // 0x199eec: 0x8e43004c
    ctx->pc = 0x199eecu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x199ef0: 0xc4214e50
    ctx->pc = 0x199ef0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199ef4: 0x25084d40
    ctx->pc = 0x199ef4u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 19776));
    // 0x199ef8: 0xc4600024
    ctx->pc = 0x199ef8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199efc: 0x3c010029
    ctx->pc = 0x199efcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x199f00: 0x46000802
    ctx->pc = 0x199f00u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x199f04: 0xe4400020
    ctx->pc = 0x199f04u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x199f08: 0x8e43004c
    ctx->pc = 0x199f08u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x199f0c: 0xc4214e54
    ctx->pc = 0x199f0cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199f10: 0xc4600024
    ctx->pc = 0x199f10u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199f14: 0x3c010029
    ctx->pc = 0x199f14u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x199f18: 0x46000802
    ctx->pc = 0x199f18u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x199f1c: 0xe4400024
    ctx->pc = 0x199f1cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x199f20: 0x8e43004c
    ctx->pc = 0x199f20u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x199f24: 0xc4214e58
    ctx->pc = 0x199f24u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199f28: 0xc4600024
    ctx->pc = 0x199f28u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199f2c: 0x3c010029
    ctx->pc = 0x199f2cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x199f30: 0x46000802
    ctx->pc = 0x199f30u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x199f34: 0xe4400028
    ctx->pc = 0x199f34u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x199f38: 0xc4204e5c
    ctx->pc = 0x199f38u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199f3c: 0xc066500
    ctx->pc = 0x199F3Cu;
    SET_GPR_U32(ctx, 31, 0x199F44u);
    ctx->pc = 0x199F40u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    ctx->pc = 0x199400u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199F44u; }
    }
    if (ctx->pc != 0x199F44u) { return; }
    ctx->pc = 0x199F44u;
    // 0x199f44: 0x3c060029
    ctx->pc = 0x199f44u;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x199f48: 0x24440070
    ctx->pc = 0x199f48u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 112));
    // 0x199f4c: 0xc0664e0
    ctx->pc = 0x199F4Cu;
    SET_GPR_U32(ctx, 31, 0x199F54u);
    ctx->pc = 0x199F50u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19712));
    ctx->pc = 0x199380u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199F54u; }
    }
    if (ctx->pc != 0x199F54u) { return; }
    ctx->pc = 0x199F54u;
    // 0x199f54: 0x3c010029
    ctx->pc = 0x199f54u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x199f58: 0x3c037000
    ctx->pc = 0x199f58u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x199f5c: 0xc4204234
    ctx->pc = 0x199f5cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199f60: 0x244400b0
    ctx->pc = 0x199f60u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 176));
    // 0x199f64: 0x34653700
    ctx->pc = 0x199f64u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 3), 14080));
    // 0x199f68: 0x27a60040
    ctx->pc = 0x199f68u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 29), 64));
    // 0x199f6c: 0x3c010029
    ctx->pc = 0x199f6cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x199f70: 0xc4254238
    ctx->pc = 0x199f70u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[5] = f; }
    // 0x199f74: 0x46000187
    ctx->pc = 0x199f74u;
    ctx->f[6] = FPU_NEG_S(ctx->f[0]);
    // 0x199f78: 0xe7a60040
    ctx->pc = 0x199f78u;
    { float f = ctx->f[6]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x199f7c: 0x3c010029
    ctx->pc = 0x199f7cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x199f80: 0xc424423c
    ctx->pc = 0x199f80u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x199f84: 0x46002947
    ctx->pc = 0x199f84u;
    ctx->f[5] = FPU_NEG_S(ctx->f[5]);
    // 0x199f88: 0xe7a50044
    ctx->pc = 0x199f88u;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 68), bits); }
    // 0x199f8c: 0x3c010029
    ctx->pc = 0x199f8cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x199f90: 0xc423429c
    ctx->pc = 0x199f90u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x199f94: 0x46002107
    ctx->pc = 0x199f94u;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x199f98: 0xe7a40048
    ctx->pc = 0x199f98u;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 72), bits); }
    // 0x199f9c: 0x3c010029
    ctx->pc = 0x199f9cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x199fa0: 0xc42242a0
    ctx->pc = 0x199fa0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x199fa4: 0x460018c7
    ctx->pc = 0x199fa4u;
    ctx->f[3] = FPU_NEG_S(ctx->f[3]);
    // 0x199fa8: 0xe7a30050
    ctx->pc = 0x199fa8u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x199fac: 0x3c010029
    ctx->pc = 0x199facu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x199fb0: 0xc42142a4
    ctx->pc = 0x199fb0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199fb4: 0x46001087
    ctx->pc = 0x199fb4u;
    ctx->f[2] = FPU_NEG_S(ctx->f[2]);
    // 0x199fb8: 0xe7a20054
    ctx->pc = 0x199fb8u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x199fbc: 0x3c010029
    ctx->pc = 0x199fbcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x199fc0: 0xc4204304
    ctx->pc = 0x199fc0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17156)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199fc4: 0x46000847
    ctx->pc = 0x199fc4u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x199fc8: 0xe7a10058
    ctx->pc = 0x199fc8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x199fcc: 0x3c010029
    ctx->pc = 0x199fccu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x199fd0: 0xc4214308
    ctx->pc = 0x199fd0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17160)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x199fd4: 0x46000007
    ctx->pc = 0x199fd4u;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x199fd8: 0xe7a00060
    ctx->pc = 0x199fd8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x199fdc: 0x3c010029
    ctx->pc = 0x199fdcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x199fe0: 0xc420430c
    ctx->pc = 0x199fe0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17164)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x199fe4: 0x46000847
    ctx->pc = 0x199fe4u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x199fe8: 0xe7a10064
    ctx->pc = 0x199fe8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x199fec: 0x46000007
    ctx->pc = 0x199fecu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x199ff0: 0xc066570
    ctx->pc = 0x199FF0u;
    SET_GPR_U32(ctx, 31, 0x199FF8u);
    ctx->pc = 0x199FF4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
    ctx->pc = 0x1995C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001995C0_0x1995c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x199FF8u; }
    }
    if (ctx->pc != 0x199FF8u) { return; }
    ctx->pc = 0x199FF8u;
    // 0x199ff8: 0x8e43004c
    ctx->pc = 0x199ff8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x199ffc: 0xc46c0024
    ctx->pc = 0x199ffcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19a000: 0xc066648
    ctx->pc = 0x19A000u;
    SET_GPR_U32(ctx, 31, 0x19A008u);
    ctx->pc = 0x19A004u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 224));
    ctx->pc = 0x199920u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199920_0x199920(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A008u; }
    }
    if (ctx->pc != 0x19A008u) { return; }
    ctx->pc = 0x19A008u;
    // 0x19a008: 0xc066734
    ctx->pc = 0x19A008u;
    SET_GPR_U32(ctx, 31, 0x19A010u);
    ctx->pc = 0x19A00Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 288));
    ctx->pc = 0x199CD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A010u; }
    }
    if (ctx->pc != 0x19A010u) { return; }
    ctx->pc = 0x19A010u;
    // 0x19a010: 0x3c031500
    ctx->pc = 0x19a010u;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19a014: 0x2231825
    ctx->pc = 0x19a014u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x19a018: 0xac430150
    ctx->pc = 0x19a018u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 336), GPR_U32(ctx, 3));
    // 0x19a01c: 0xac400154
    ctx->pc = 0x19a01cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 340), GPR_U32(ctx, 0));
    // 0x19a020: 0xac400158
    ctx->pc = 0x19a020u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 344), GPR_U32(ctx, 0));
    // 0x19a024: 0xac40015c
    ctx->pc = 0x19a024u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 348), GPR_U32(ctx, 0));
    // 0x19a028: 0xdfbf0030
    ctx->pc = 0x19a028u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19a02c: 0x7bb20020
    ctx->pc = 0x19a02cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19a030: 0x7bb10010
    ctx->pc = 0x19a030u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19a034: 0x7bb00000
    ctx->pc = 0x19a034u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19a038: 0x3e00008
    ctx->pc = 0x19A038u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19A03Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 176));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19A040u;
    // 0x19a040: 0x27bdff80
    ctx->pc = 0x19a040u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x19a044: 0xffbf0030
    ctx->pc = 0x19a044u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19a048: 0x7fb20020
    ctx->pc = 0x19a048u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19a04c: 0x7fb10010
    ctx->pc = 0x19a04cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19a050: 0x80902d
    ctx->pc = 0x19a050u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a054: 0x7fb00000
    ctx->pc = 0x19a054u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19a058: 0xa0882d
    ctx->pc = 0x19a058u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a05c: 0xc0802d
    ctx->pc = 0x19a05cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a060: 0x240400f0
    ctx->pc = 0x19a060u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 240));
    // 0x19a064: 0xc063774
    ctx->pc = 0x19A064u;
    SET_GPR_U32(ctx, 31, 0x19A06Cu);
    ctx->pc = 0x19A068u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A06Cu; }
    }
    if (ctx->pc != 0x19A06Cu) { return; }
    ctx->pc = 0x19A06Cu;
    // 0x19a06c: 0x3c032000
    ctx->pc = 0x19a06cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x19a070: 0x3c080029
    ctx->pc = 0x19a070u;
    SET_GPR_U32(ctx, 8, ((uint32_t)41 << 16));
    // 0x19a074: 0x3464000e
    ctx->pc = 0x19a074u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 14));
    // 0x19a078: 0x3c051300
    ctx->pc = 0x19a078u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4864 << 16));
    // 0x19a07c: 0xac440000
    ctx->pc = 0x19a07cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19a080: 0x3c030100
    ctx->pc = 0x19a080u;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x19a084: 0xac500004
    ctx->pc = 0x19a084u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19a088: 0x34660404
    ctx->pc = 0x19a088u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 1028));
    // 0x19a08c: 0xfc400008
    ctx->pc = 0x19a08cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19a090: 0x3c076c0c
    ctx->pc = 0x19a090u;
    SET_GPR_U32(ctx, 7, ((uint32_t)27660 << 16));
    // 0x19a094: 0xac450010
    ctx->pc = 0x19a094u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x19a098: 0x3c037000
    ctx->pc = 0x19a098u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19a09c: 0xac400014
    ctx->pc = 0x19a09cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19a0a0: 0x3c010029
    ctx->pc = 0x19a0a0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a0a4: 0xac460018
    ctx->pc = 0x19a0a4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x19a0a8: 0x24440030
    ctx->pc = 0x19a0a8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 48));
    // 0x19a0ac: 0xac47001c
    ctx->pc = 0x19a0acu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x19a0b0: 0x34663700
    ctx->pc = 0x19a0b0u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 14080));
    // 0x19a0b4: 0x34673f40
    ctx->pc = 0x19a0b4u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19a0b8: 0x27a50040
    ctx->pc = 0x19a0b8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 64));
    // 0x19a0bc: 0x8e43004c
    ctx->pc = 0x19a0bcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a0c0: 0xc4214e50
    ctx->pc = 0x19a0c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a0c4: 0x25084d40
    ctx->pc = 0x19a0c4u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19a0c8: 0xc4600024
    ctx->pc = 0x19a0c8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a0cc: 0x3c010029
    ctx->pc = 0x19a0ccu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a0d0: 0x46000802
    ctx->pc = 0x19a0d0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a0d4: 0xe4400020
    ctx->pc = 0x19a0d4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19a0d8: 0x8e43004c
    ctx->pc = 0x19a0d8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a0dc: 0xc4214e54
    ctx->pc = 0x19a0dcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a0e0: 0xc4600024
    ctx->pc = 0x19a0e0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a0e4: 0x3c010029
    ctx->pc = 0x19a0e4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a0e8: 0x46000802
    ctx->pc = 0x19a0e8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a0ec: 0xe4400024
    ctx->pc = 0x19a0ecu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19a0f0: 0x8e43004c
    ctx->pc = 0x19a0f0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a0f4: 0xc4214e58
    ctx->pc = 0x19a0f4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a0f8: 0xc4600024
    ctx->pc = 0x19a0f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a0fc: 0x3c010029
    ctx->pc = 0x19a0fcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a100: 0x46000802
    ctx->pc = 0x19a100u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a104: 0xe4400028
    ctx->pc = 0x19a104u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19a108: 0xc4204e5c
    ctx->pc = 0x19a108u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a10c: 0xc066500
    ctx->pc = 0x19A10Cu;
    SET_GPR_U32(ctx, 31, 0x19A114u);
    ctx->pc = 0x19A110u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    ctx->pc = 0x199400u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A114u; }
    }
    if (ctx->pc != 0x19A114u) { return; }
    ctx->pc = 0x19A114u;
    // 0x19a114: 0x3c060029
    ctx->pc = 0x19a114u;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x19a118: 0x24440070
    ctx->pc = 0x19a118u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 112));
    // 0x19a11c: 0xc0664e0
    ctx->pc = 0x19A11Cu;
    SET_GPR_U32(ctx, 31, 0x19A124u);
    ctx->pc = 0x19A120u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19712));
    ctx->pc = 0x199380u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A124u; }
    }
    if (ctx->pc != 0x19A124u) { return; }
    ctx->pc = 0x19A124u;
    // 0x19a124: 0xc066734
    ctx->pc = 0x19A124u;
    SET_GPR_U32(ctx, 31, 0x19A12Cu);
    ctx->pc = 0x19A128u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 176));
    ctx->pc = 0x199CD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A12Cu; }
    }
    if (ctx->pc != 0x19A12Cu) { return; }
    ctx->pc = 0x19A12Cu;
    // 0x19a12c: 0x3c031500
    ctx->pc = 0x19a12cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19a130: 0x2231825
    ctx->pc = 0x19a130u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x19a134: 0xac4300e0
    ctx->pc = 0x19a134u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 224), GPR_U32(ctx, 3));
    // 0x19a138: 0xac4000e4
    ctx->pc = 0x19a138u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 228), GPR_U32(ctx, 0));
    // 0x19a13c: 0xac4000e8
    ctx->pc = 0x19a13cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 232), GPR_U32(ctx, 0));
    // 0x19a140: 0xac4000ec
    ctx->pc = 0x19a140u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 236), GPR_U32(ctx, 0));
    // 0x19a144: 0xdfbf0030
    ctx->pc = 0x19a144u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19a148: 0x7bb20020
    ctx->pc = 0x19a148u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19a14c: 0x7bb10010
    ctx->pc = 0x19a14cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19a150: 0x7bb00000
    ctx->pc = 0x19a150u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19a154: 0x3e00008
    ctx->pc = 0x19A154u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19A158u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 128));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19A15Cu;
    // 0x19a15c: 0x0
    ctx->pc = 0x19a15cu;
    // NOP
    // 0x19a160: 0x27bdff50
    ctx->pc = 0x19a160u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967120));
    // 0x19a164: 0xffbf0030
    ctx->pc = 0x19a164u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19a168: 0x7fb20020
    ctx->pc = 0x19a168u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19a16c: 0x7fb10010
    ctx->pc = 0x19a16cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19a170: 0x80902d
    ctx->pc = 0x19a170u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a174: 0x7fb00000
    ctx->pc = 0x19a174u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19a178: 0xa0882d
    ctx->pc = 0x19a178u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a17c: 0xc0802d
    ctx->pc = 0x19a17cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a180: 0x24040170
    ctx->pc = 0x19a180u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 368));
    // 0x19a184: 0xc063774
    ctx->pc = 0x19A184u;
    SET_GPR_U32(ctx, 31, 0x19A18Cu);
    ctx->pc = 0x19A188u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A18Cu; }
    }
    if (ctx->pc != 0x19A18Cu) { return; }
    ctx->pc = 0x19A18Cu;
    // 0x19a18c: 0x3c032000
    ctx->pc = 0x19a18cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x19a190: 0x3c080029
    ctx->pc = 0x19a190u;
    SET_GPR_U32(ctx, 8, ((uint32_t)41 << 16));
    // 0x19a194: 0x34640016
    ctx->pc = 0x19a194u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 22));
    // 0x19a198: 0x3c051300
    ctx->pc = 0x19a198u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4864 << 16));
    // 0x19a19c: 0xac440000
    ctx->pc = 0x19a19cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19a1a0: 0x3c030100
    ctx->pc = 0x19a1a0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x19a1a4: 0xac500004
    ctx->pc = 0x19a1a4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19a1a8: 0x34660404
    ctx->pc = 0x19a1a8u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 1028));
    // 0x19a1ac: 0xfc400008
    ctx->pc = 0x19a1acu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19a1b0: 0x3c076c14
    ctx->pc = 0x19a1b0u;
    SET_GPR_U32(ctx, 7, ((uint32_t)27668 << 16));
    // 0x19a1b4: 0xac450010
    ctx->pc = 0x19a1b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x19a1b8: 0x3c037000
    ctx->pc = 0x19a1b8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19a1bc: 0xac400014
    ctx->pc = 0x19a1bcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19a1c0: 0x3c010029
    ctx->pc = 0x19a1c0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a1c4: 0xac460018
    ctx->pc = 0x19a1c4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x19a1c8: 0x24440030
    ctx->pc = 0x19a1c8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 48));
    // 0x19a1cc: 0xac47001c
    ctx->pc = 0x19a1ccu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x19a1d0: 0x34663700
    ctx->pc = 0x19a1d0u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 14080));
    // 0x19a1d4: 0x34673f40
    ctx->pc = 0x19a1d4u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19a1d8: 0x27a50070
    ctx->pc = 0x19a1d8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 112));
    // 0x19a1dc: 0x8e43004c
    ctx->pc = 0x19a1dcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a1e0: 0xc4214e50
    ctx->pc = 0x19a1e0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a1e4: 0x25084d40
    ctx->pc = 0x19a1e4u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19a1e8: 0xc4600024
    ctx->pc = 0x19a1e8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a1ec: 0x3c010029
    ctx->pc = 0x19a1ecu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a1f0: 0x46000802
    ctx->pc = 0x19a1f0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a1f4: 0xe4400020
    ctx->pc = 0x19a1f4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19a1f8: 0x8e43004c
    ctx->pc = 0x19a1f8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a1fc: 0xc4214e54
    ctx->pc = 0x19a1fcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a200: 0xc4600024
    ctx->pc = 0x19a200u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a204: 0x3c010029
    ctx->pc = 0x19a204u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a208: 0x46000802
    ctx->pc = 0x19a208u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a20c: 0xe4400024
    ctx->pc = 0x19a20cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19a210: 0x8e43004c
    ctx->pc = 0x19a210u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a214: 0xc4214e58
    ctx->pc = 0x19a214u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a218: 0xc4600024
    ctx->pc = 0x19a218u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a21c: 0x3c010029
    ctx->pc = 0x19a21cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a220: 0x46000802
    ctx->pc = 0x19a220u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a224: 0xe4400028
    ctx->pc = 0x19a224u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19a228: 0xc4204e5c
    ctx->pc = 0x19a228u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a22c: 0xc066500
    ctx->pc = 0x19A22Cu;
    SET_GPR_U32(ctx, 31, 0x19A234u);
    ctx->pc = 0x19A230u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    ctx->pc = 0x199400u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A234u; }
    }
    if (ctx->pc != 0x19A234u) { return; }
    ctx->pc = 0x19A234u;
    // 0x19a234: 0x3c060029
    ctx->pc = 0x19a234u;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x19a238: 0x24440070
    ctx->pc = 0x19a238u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 112));
    // 0x19a23c: 0xc0664e0
    ctx->pc = 0x19A23Cu;
    SET_GPR_U32(ctx, 31, 0x19A244u);
    ctx->pc = 0x19A240u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19712));
    ctx->pc = 0x199380u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A244u; }
    }
    if (ctx->pc != 0x19A244u) { return; }
    ctx->pc = 0x19A244u;
    // 0x19a244: 0x3c010029
    ctx->pc = 0x19a244u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a248: 0x3c037000
    ctx->pc = 0x19a248u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19a24c: 0xc4204234
    ctx->pc = 0x19a24cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a250: 0x244400b0
    ctx->pc = 0x19a250u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 176));
    // 0x19a254: 0x34653700
    ctx->pc = 0x19a254u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 3), 14080));
    // 0x19a258: 0x27a60040
    ctx->pc = 0x19a258u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 29), 64));
    // 0x19a25c: 0x3c010029
    ctx->pc = 0x19a25cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a260: 0xc4254238
    ctx->pc = 0x19a260u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[5] = f; }
    // 0x19a264: 0x46000187
    ctx->pc = 0x19a264u;
    ctx->f[6] = FPU_NEG_S(ctx->f[0]);
    // 0x19a268: 0xe7a60040
    ctx->pc = 0x19a268u;
    { float f = ctx->f[6]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x19a26c: 0x3c010029
    ctx->pc = 0x19a26cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a270: 0xc424423c
    ctx->pc = 0x19a270u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x19a274: 0x46002947
    ctx->pc = 0x19a274u;
    ctx->f[5] = FPU_NEG_S(ctx->f[5]);
    // 0x19a278: 0xe7a50044
    ctx->pc = 0x19a278u;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 68), bits); }
    // 0x19a27c: 0x3c010029
    ctx->pc = 0x19a27cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a280: 0xc423429c
    ctx->pc = 0x19a280u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19a284: 0x46002107
    ctx->pc = 0x19a284u;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x19a288: 0xe7a40048
    ctx->pc = 0x19a288u;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 72), bits); }
    // 0x19a28c: 0x3c010029
    ctx->pc = 0x19a28cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a290: 0xc42242a0
    ctx->pc = 0x19a290u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19a294: 0x460018c7
    ctx->pc = 0x19a294u;
    ctx->f[3] = FPU_NEG_S(ctx->f[3]);
    // 0x19a298: 0xe7a30050
    ctx->pc = 0x19a298u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19a29c: 0x3c010029
    ctx->pc = 0x19a29cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a2a0: 0xc42142a4
    ctx->pc = 0x19a2a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a2a4: 0x46001087
    ctx->pc = 0x19a2a4u;
    ctx->f[2] = FPU_NEG_S(ctx->f[2]);
    // 0x19a2a8: 0xe7a20054
    ctx->pc = 0x19a2a8u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19a2ac: 0x3c010029
    ctx->pc = 0x19a2acu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a2b0: 0xc4204304
    ctx->pc = 0x19a2b0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17156)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a2b4: 0x46000847
    ctx->pc = 0x19a2b4u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19a2b8: 0xe7a10058
    ctx->pc = 0x19a2b8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x19a2bc: 0x3c010029
    ctx->pc = 0x19a2bcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a2c0: 0xc4214308
    ctx->pc = 0x19a2c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17160)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a2c4: 0x46000007
    ctx->pc = 0x19a2c4u;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19a2c8: 0xe7a00060
    ctx->pc = 0x19a2c8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x19a2cc: 0x3c010029
    ctx->pc = 0x19a2ccu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a2d0: 0xc420430c
    ctx->pc = 0x19a2d0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17164)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a2d4: 0x46000847
    ctx->pc = 0x19a2d4u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19a2d8: 0xe7a10064
    ctx->pc = 0x19a2d8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x19a2dc: 0x46000007
    ctx->pc = 0x19a2dcu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19a2e0: 0xc066570
    ctx->pc = 0x19A2E0u;
    SET_GPR_U32(ctx, 31, 0x19A2E8u);
    ctx->pc = 0x19A2E4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
    ctx->pc = 0x1995C0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001995C0_0x1995c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A2E8u; }
    }
    if (ctx->pc != 0x19A2E8u) { return; }
    ctx->pc = 0x19A2E8u;
    // 0x19a2e8: 0x8e43004c
    ctx->pc = 0x19a2e8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a2ec: 0xc46c0024
    ctx->pc = 0x19a2ecu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19a2f0: 0xc066648
    ctx->pc = 0x19A2F0u;
    SET_GPR_U32(ctx, 31, 0x19A2F8u);
    ctx->pc = 0x19A2F4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 224));
    ctx->pc = 0x199920u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199920_0x199920(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A2F8u; }
    }
    if (ctx->pc != 0x19A2F8u) { return; }
    ctx->pc = 0x19A2F8u;
    // 0x19a2f8: 0xc066734
    ctx->pc = 0x19A2F8u;
    SET_GPR_U32(ctx, 31, 0x19A300u);
    ctx->pc = 0x19A2FCu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 288));
    ctx->pc = 0x199CD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A300u; }
    }
    if (ctx->pc != 0x19A300u) { return; }
    ctx->pc = 0x19A300u;
    // 0x19a300: 0x3c01002a
    ctx->pc = 0x19a300u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19a304: 0x3c033f80
    ctx->pc = 0x19a304u;
    SET_GPR_U32(ctx, 3, ((uint32_t)16256 << 16));
    // 0x19a308: 0xc421fe40
    ctx->pc = 0x19a308u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a30c: 0x44830000
    ctx->pc = 0x19a30cu;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 3);
    // 0x19a310: 0x3c031500
    ctx->pc = 0x19a310u;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19a314: 0x2231825
    ctx->pc = 0x19a314u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x19a318: 0xe4410150
    ctx->pc = 0x19a318u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 336), bits); }
    // 0x19a31c: 0x3c01002a
    ctx->pc = 0x19a31cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19a320: 0xc422fe40
    ctx->pc = 0x19a320u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19a324: 0x3c01002a
    ctx->pc = 0x19a324u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19a328: 0xc421fe48
    ctx->pc = 0x19a328u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a32c: 0x46011041
    ctx->pc = 0x19a32cu;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19a330: 0x46010003
    ctx->pc = 0x19a330u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ ctx->f[0] = copysignf(INFINITY, ctx->f[0] * 0.0f); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19a334: 0xe4400154
    ctx->pc = 0x19a334u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 340), bits); }
    // 0x19a338: 0xac400158
    ctx->pc = 0x19a338u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 344), GPR_U32(ctx, 0));
    // 0x19a33c: 0xac40015c
    ctx->pc = 0x19a33cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 348), GPR_U32(ctx, 0));
    // 0x19a340: 0xac430160
    ctx->pc = 0x19a340u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 352), GPR_U32(ctx, 3));
    // 0x19a344: 0xac400164
    ctx->pc = 0x19a344u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 356), GPR_U32(ctx, 0));
    // 0x19a348: 0xac400168
    ctx->pc = 0x19a348u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 360), GPR_U32(ctx, 0));
    // 0x19a34c: 0xac40016c
    ctx->pc = 0x19a34cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 364), GPR_U32(ctx, 0));
    // 0x19a350: 0xdfbf0030
    ctx->pc = 0x19a350u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19a354: 0x7bb20020
    ctx->pc = 0x19a354u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19a358: 0x7bb10010
    ctx->pc = 0x19a358u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19a35c: 0x7bb00000
    ctx->pc = 0x19a35cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19a360: 0x3e00008
    ctx->pc = 0x19A360u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19A364u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 176));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19A368u;
    // 0x19a368: 0x0
    ctx->pc = 0x19a368u;
    // NOP
    // 0x19a36c: 0x0
    ctx->pc = 0x19a36cu;
    // NOP
    // 0x19a370: 0x27bdff80
    ctx->pc = 0x19a370u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x19a374: 0xffbf0030
    ctx->pc = 0x19a374u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19a378: 0x7fb20020
    ctx->pc = 0x19a378u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19a37c: 0x7fb10010
    ctx->pc = 0x19a37cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19a380: 0x80902d
    ctx->pc = 0x19a380u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a384: 0x7fb00000
    ctx->pc = 0x19a384u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19a388: 0xa0882d
    ctx->pc = 0x19a388u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a38c: 0xc0802d
    ctx->pc = 0x19a38cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a390: 0x240400d0
    ctx->pc = 0x19a390u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 208));
    // 0x19a394: 0xc063774
    ctx->pc = 0x19A394u;
    SET_GPR_U32(ctx, 31, 0x19A39Cu);
    ctx->pc = 0x19A398u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A39Cu; }
    }
    if (ctx->pc != 0x19A39Cu) { return; }
    ctx->pc = 0x19A39Cu;
    // 0x19a39c: 0x3c032000
    ctx->pc = 0x19a39cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x19a3a0: 0x3c080029
    ctx->pc = 0x19a3a0u;
    SET_GPR_U32(ctx, 8, ((uint32_t)41 << 16));
    // 0x19a3a4: 0x3464000c
    ctx->pc = 0x19a3a4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 12));
    // 0x19a3a8: 0x3c051300
    ctx->pc = 0x19a3a8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4864 << 16));
    // 0x19a3ac: 0xac440000
    ctx->pc = 0x19a3acu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19a3b0: 0x3c030100
    ctx->pc = 0x19a3b0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x19a3b4: 0xac500004
    ctx->pc = 0x19a3b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19a3b8: 0x34660404
    ctx->pc = 0x19a3b8u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 1028));
    // 0x19a3bc: 0xfc400008
    ctx->pc = 0x19a3bcu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19a3c0: 0x3c076c0a
    ctx->pc = 0x19a3c0u;
    SET_GPR_U32(ctx, 7, ((uint32_t)27658 << 16));
    // 0x19a3c4: 0xac450010
    ctx->pc = 0x19a3c4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x19a3c8: 0x3c037000
    ctx->pc = 0x19a3c8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19a3cc: 0xac400014
    ctx->pc = 0x19a3ccu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19a3d0: 0x3c010029
    ctx->pc = 0x19a3d0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a3d4: 0xac460018
    ctx->pc = 0x19a3d4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x19a3d8: 0x24440040
    ctx->pc = 0x19a3d8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 64));
    // 0x19a3dc: 0xac47001c
    ctx->pc = 0x19a3dcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x19a3e0: 0x34663700
    ctx->pc = 0x19a3e0u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 14080));
    // 0x19a3e4: 0x34673f40
    ctx->pc = 0x19a3e4u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19a3e8: 0x27a50040
    ctx->pc = 0x19a3e8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 64));
    // 0x19a3ec: 0x8e43004c
    ctx->pc = 0x19a3ecu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a3f0: 0xc4214e50
    ctx->pc = 0x19a3f0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a3f4: 0x25084d40
    ctx->pc = 0x19a3f4u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19a3f8: 0xc4600024
    ctx->pc = 0x19a3f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a3fc: 0x3c010029
    ctx->pc = 0x19a3fcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a400: 0x46000802
    ctx->pc = 0x19a400u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a404: 0xe4400020
    ctx->pc = 0x19a404u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19a408: 0x8e43004c
    ctx->pc = 0x19a408u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a40c: 0xc4214e54
    ctx->pc = 0x19a40cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a410: 0xc4600024
    ctx->pc = 0x19a410u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a414: 0x3c010029
    ctx->pc = 0x19a414u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a418: 0x46000802
    ctx->pc = 0x19a418u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a41c: 0xe4400024
    ctx->pc = 0x19a41cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19a420: 0x8e43004c
    ctx->pc = 0x19a420u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a424: 0xc4214e58
    ctx->pc = 0x19a424u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a428: 0xc4600024
    ctx->pc = 0x19a428u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a42c: 0x3c010029
    ctx->pc = 0x19a42cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a430: 0x46000802
    ctx->pc = 0x19a430u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a434: 0xe4400028
    ctx->pc = 0x19a434u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19a438: 0xc4204e5c
    ctx->pc = 0x19a438u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a43c: 0xe440002c
    ctx->pc = 0x19a43cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19a440: 0x3c010029
    ctx->pc = 0x19a440u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a444: 0xc4204e40
    ctx->pc = 0x19a444u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a448: 0xe4400030
    ctx->pc = 0x19a448u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19a44c: 0x3c010029
    ctx->pc = 0x19a44cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a450: 0xc4204e44
    ctx->pc = 0x19a450u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a454: 0xe4400034
    ctx->pc = 0x19a454u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19a458: 0x3c010029
    ctx->pc = 0x19a458u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a45c: 0xc4204e48
    ctx->pc = 0x19a45cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a460: 0xe4400038
    ctx->pc = 0x19a460u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19a464: 0x3c010029
    ctx->pc = 0x19a464u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a468: 0xc4204e4c
    ctx->pc = 0x19a468u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a46c: 0xc066500
    ctx->pc = 0x19A46Cu;
    SET_GPR_U32(ctx, 31, 0x19A474u);
    ctx->pc = 0x19A470u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
    ctx->pc = 0x199400u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A474u; }
    }
    if (ctx->pc != 0x19A474u) { return; }
    ctx->pc = 0x19A474u;
    // 0x19a474: 0x3c060029
    ctx->pc = 0x19a474u;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x19a478: 0x24440080
    ctx->pc = 0x19a478u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 128));
    // 0x19a47c: 0xc0664e0
    ctx->pc = 0x19A47Cu;
    SET_GPR_U32(ctx, 31, 0x19A484u);
    ctx->pc = 0x19A480u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19712));
    ctx->pc = 0x199380u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A484u; }
    }
    if (ctx->pc != 0x19A484u) { return; }
    ctx->pc = 0x19A484u;
    // 0x19a484: 0x3c031500
    ctx->pc = 0x19a484u;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19a488: 0x2231825
    ctx->pc = 0x19a488u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x19a48c: 0xac4300c0
    ctx->pc = 0x19a48cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 192), GPR_U32(ctx, 3));
    // 0x19a490: 0xac4000c4
    ctx->pc = 0x19a490u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 196), GPR_U32(ctx, 0));
    // 0x19a494: 0xac4000c8
    ctx->pc = 0x19a494u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 200), GPR_U32(ctx, 0));
    // 0x19a498: 0xac4000cc
    ctx->pc = 0x19a498u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 204), GPR_U32(ctx, 0));
    // 0x19a49c: 0xdfbf0030
    ctx->pc = 0x19a49cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19a4a0: 0x7bb20020
    ctx->pc = 0x19a4a0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19a4a4: 0x7bb10010
    ctx->pc = 0x19a4a4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19a4a8: 0x7bb00000
    ctx->pc = 0x19a4a8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19a4ac: 0x3e00008
    ctx->pc = 0x19A4ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19A4B0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 128));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19A4B4u;
    // 0x19a4b4: 0x0
    ctx->pc = 0x19a4b4u;
    // NOP
    // 0x19a4b8: 0x0
    ctx->pc = 0x19a4b8u;
    // NOP
    // 0x19a4bc: 0x0
    ctx->pc = 0x19a4bcu;
    // NOP
    // 0x19a4c0: 0x27bdff80
    ctx->pc = 0x19a4c0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x19a4c4: 0xffbf0030
    ctx->pc = 0x19a4c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19a4c8: 0x7fb20020
    ctx->pc = 0x19a4c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19a4cc: 0x7fb10010
    ctx->pc = 0x19a4ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19a4d0: 0x80902d
    ctx->pc = 0x19a4d0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a4d4: 0x7fb00000
    ctx->pc = 0x19a4d4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19a4d8: 0xa0882d
    ctx->pc = 0x19a4d8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a4dc: 0xc0802d
    ctx->pc = 0x19a4dcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a4e0: 0x24040100
    ctx->pc = 0x19a4e0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 256));
    // 0x19a4e4: 0xc063774
    ctx->pc = 0x19A4E4u;
    SET_GPR_U32(ctx, 31, 0x19A4ECu);
    ctx->pc = 0x19A4E8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A4ECu; }
    }
    if (ctx->pc != 0x19A4ECu) { return; }
    ctx->pc = 0x19A4ECu;
    // 0x19a4ec: 0x3c032000
    ctx->pc = 0x19a4ecu;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x19a4f0: 0x3c080029
    ctx->pc = 0x19a4f0u;
    SET_GPR_U32(ctx, 8, ((uint32_t)41 << 16));
    // 0x19a4f4: 0x3464000f
    ctx->pc = 0x19a4f4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 15));
    // 0x19a4f8: 0x3c051300
    ctx->pc = 0x19a4f8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4864 << 16));
    // 0x19a4fc: 0xac440000
    ctx->pc = 0x19a4fcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19a500: 0x3c030100
    ctx->pc = 0x19a500u;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x19a504: 0xac500004
    ctx->pc = 0x19a504u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19a508: 0x34660404
    ctx->pc = 0x19a508u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 1028));
    // 0x19a50c: 0xfc400008
    ctx->pc = 0x19a50cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19a510: 0x3c076c0d
    ctx->pc = 0x19a510u;
    SET_GPR_U32(ctx, 7, ((uint32_t)27661 << 16));
    // 0x19a514: 0xac450010
    ctx->pc = 0x19a514u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x19a518: 0x3c037000
    ctx->pc = 0x19a518u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19a51c: 0xac400014
    ctx->pc = 0x19a51cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19a520: 0x3c010029
    ctx->pc = 0x19a520u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a524: 0xac460018
    ctx->pc = 0x19a524u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x19a528: 0x24440040
    ctx->pc = 0x19a528u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 64));
    // 0x19a52c: 0xac47001c
    ctx->pc = 0x19a52cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x19a530: 0x34663700
    ctx->pc = 0x19a530u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 14080));
    // 0x19a534: 0x34673f40
    ctx->pc = 0x19a534u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19a538: 0x27a50040
    ctx->pc = 0x19a538u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 64));
    // 0x19a53c: 0x8e43004c
    ctx->pc = 0x19a53cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a540: 0xc4214e50
    ctx->pc = 0x19a540u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a544: 0x25084d40
    ctx->pc = 0x19a544u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19a548: 0xc4600024
    ctx->pc = 0x19a548u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a54c: 0x3c010029
    ctx->pc = 0x19a54cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a550: 0x46000802
    ctx->pc = 0x19a550u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a554: 0xe4400020
    ctx->pc = 0x19a554u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19a558: 0x8e43004c
    ctx->pc = 0x19a558u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a55c: 0xc4214e54
    ctx->pc = 0x19a55cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a560: 0xc4600024
    ctx->pc = 0x19a560u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a564: 0x3c010029
    ctx->pc = 0x19a564u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a568: 0x46000802
    ctx->pc = 0x19a568u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a56c: 0xe4400024
    ctx->pc = 0x19a56cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19a570: 0x8e43004c
    ctx->pc = 0x19a570u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a574: 0xc4214e58
    ctx->pc = 0x19a574u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a578: 0xc4600024
    ctx->pc = 0x19a578u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a57c: 0x3c010029
    ctx->pc = 0x19a57cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a580: 0x46000802
    ctx->pc = 0x19a580u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a584: 0xe4400028
    ctx->pc = 0x19a584u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19a588: 0xc4204e5c
    ctx->pc = 0x19a588u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a58c: 0xe440002c
    ctx->pc = 0x19a58cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19a590: 0x3c010029
    ctx->pc = 0x19a590u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a594: 0xc4204e40
    ctx->pc = 0x19a594u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a598: 0xe4400030
    ctx->pc = 0x19a598u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19a59c: 0x3c010029
    ctx->pc = 0x19a59cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a5a0: 0xc4204e44
    ctx->pc = 0x19a5a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a5a4: 0xe4400034
    ctx->pc = 0x19a5a4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19a5a8: 0x3c010029
    ctx->pc = 0x19a5a8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a5ac: 0xc4204e48
    ctx->pc = 0x19a5acu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a5b0: 0xe4400038
    ctx->pc = 0x19a5b0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19a5b4: 0x3c010029
    ctx->pc = 0x19a5b4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a5b8: 0xc4204e4c
    ctx->pc = 0x19a5b8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a5bc: 0xc066500
    ctx->pc = 0x19A5BCu;
    SET_GPR_U32(ctx, 31, 0x19A5C4u);
    ctx->pc = 0x19A5C0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
    ctx->pc = 0x199400u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A5C4u; }
    }
    if (ctx->pc != 0x19A5C4u) { return; }
    ctx->pc = 0x19A5C4u;
    // 0x19a5c4: 0x3c060029
    ctx->pc = 0x19a5c4u;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x19a5c8: 0x24440080
    ctx->pc = 0x19a5c8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 128));
    // 0x19a5cc: 0xc0664e0
    ctx->pc = 0x19A5CCu;
    SET_GPR_U32(ctx, 31, 0x19A5D4u);
    ctx->pc = 0x19A5D0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19712));
    ctx->pc = 0x199380u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A5D4u; }
    }
    if (ctx->pc != 0x19A5D4u) { return; }
    ctx->pc = 0x19A5D4u;
    // 0x19a5d4: 0xc066734
    ctx->pc = 0x19A5D4u;
    SET_GPR_U32(ctx, 31, 0x19A5DCu);
    ctx->pc = 0x19A5D8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 192));
    ctx->pc = 0x199CD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A5DCu; }
    }
    if (ctx->pc != 0x19A5DCu) { return; }
    ctx->pc = 0x19A5DCu;
    // 0x19a5dc: 0x3c031500
    ctx->pc = 0x19a5dcu;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19a5e0: 0x2231825
    ctx->pc = 0x19a5e0u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x19a5e4: 0xac4300f0
    ctx->pc = 0x19a5e4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 240), GPR_U32(ctx, 3));
    // 0x19a5e8: 0xac4000f4
    ctx->pc = 0x19a5e8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 244), GPR_U32(ctx, 0));
    // 0x19a5ec: 0xac4000f8
    ctx->pc = 0x19a5ecu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 248), GPR_U32(ctx, 0));
    // 0x19a5f0: 0xac4000fc
    ctx->pc = 0x19a5f0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 252), GPR_U32(ctx, 0));
    // 0x19a5f4: 0xdfbf0030
    ctx->pc = 0x19a5f4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19a5f8: 0x7bb20020
    ctx->pc = 0x19a5f8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19a5fc: 0x7bb10010
    ctx->pc = 0x19a5fcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19a600: 0x7bb00000
    ctx->pc = 0x19a600u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19a604: 0x3e00008
    ctx->pc = 0x19A604u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19A608u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 128));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19A60Cu;
    // 0x19a60c: 0x0
    ctx->pc = 0x19a60cu;
    // NOP
    // 0x19a610: 0x27bdff80
    ctx->pc = 0x19a610u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x19a614: 0xffbf0030
    ctx->pc = 0x19a614u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19a618: 0x7fb20020
    ctx->pc = 0x19a618u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19a61c: 0x7fb10010
    ctx->pc = 0x19a61cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19a620: 0x80902d
    ctx->pc = 0x19a620u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a624: 0x7fb00000
    ctx->pc = 0x19a624u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19a628: 0xa0882d
    ctx->pc = 0x19a628u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a62c: 0xc0802d
    ctx->pc = 0x19a62cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a630: 0x24040110
    ctx->pc = 0x19a630u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 272));
    // 0x19a634: 0xc063774
    ctx->pc = 0x19A634u;
    SET_GPR_U32(ctx, 31, 0x19A63Cu);
    ctx->pc = 0x19A638u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A63Cu; }
    }
    if (ctx->pc != 0x19A63Cu) { return; }
    ctx->pc = 0x19A63Cu;
    // 0x19a63c: 0x3c032000
    ctx->pc = 0x19a63cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x19a640: 0x3c080029
    ctx->pc = 0x19a640u;
    SET_GPR_U32(ctx, 8, ((uint32_t)41 << 16));
    // 0x19a644: 0x34640010
    ctx->pc = 0x19a644u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 16));
    // 0x19a648: 0x3c051300
    ctx->pc = 0x19a648u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4864 << 16));
    // 0x19a64c: 0xac440000
    ctx->pc = 0x19a64cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19a650: 0x3c030100
    ctx->pc = 0x19a650u;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x19a654: 0xac500004
    ctx->pc = 0x19a654u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19a658: 0x34660404
    ctx->pc = 0x19a658u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 1028));
    // 0x19a65c: 0xfc400008
    ctx->pc = 0x19a65cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19a660: 0x3c076c0e
    ctx->pc = 0x19a660u;
    SET_GPR_U32(ctx, 7, ((uint32_t)27662 << 16));
    // 0x19a664: 0xac450010
    ctx->pc = 0x19a664u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x19a668: 0x3c037000
    ctx->pc = 0x19a668u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19a66c: 0xac400014
    ctx->pc = 0x19a66cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19a670: 0x3c010029
    ctx->pc = 0x19a670u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a674: 0xac460018
    ctx->pc = 0x19a674u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x19a678: 0x24440040
    ctx->pc = 0x19a678u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 64));
    // 0x19a67c: 0xac47001c
    ctx->pc = 0x19a67cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x19a680: 0x34663700
    ctx->pc = 0x19a680u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 14080));
    // 0x19a684: 0x34673f40
    ctx->pc = 0x19a684u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19a688: 0x27a50040
    ctx->pc = 0x19a688u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 64));
    // 0x19a68c: 0x8e43004c
    ctx->pc = 0x19a68cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a690: 0xc4214e50
    ctx->pc = 0x19a690u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a694: 0x25084d40
    ctx->pc = 0x19a694u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19a698: 0xc4600024
    ctx->pc = 0x19a698u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a69c: 0x3c010029
    ctx->pc = 0x19a69cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a6a0: 0x46000802
    ctx->pc = 0x19a6a0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a6a4: 0xe4400020
    ctx->pc = 0x19a6a4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19a6a8: 0x8e43004c
    ctx->pc = 0x19a6a8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a6ac: 0xc4214e54
    ctx->pc = 0x19a6acu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a6b0: 0xc4600024
    ctx->pc = 0x19a6b0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a6b4: 0x3c010029
    ctx->pc = 0x19a6b4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a6b8: 0x46000802
    ctx->pc = 0x19a6b8u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a6bc: 0xe4400024
    ctx->pc = 0x19a6bcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19a6c0: 0x8e43004c
    ctx->pc = 0x19a6c0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a6c4: 0xc4214e58
    ctx->pc = 0x19a6c4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a6c8: 0xc4600024
    ctx->pc = 0x19a6c8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a6cc: 0x3c010029
    ctx->pc = 0x19a6ccu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a6d0: 0x46000802
    ctx->pc = 0x19a6d0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a6d4: 0xe4400028
    ctx->pc = 0x19a6d4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19a6d8: 0xc4204e5c
    ctx->pc = 0x19a6d8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a6dc: 0xe440002c
    ctx->pc = 0x19a6dcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19a6e0: 0x3c010029
    ctx->pc = 0x19a6e0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a6e4: 0xc4204e40
    ctx->pc = 0x19a6e4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a6e8: 0xe4400030
    ctx->pc = 0x19a6e8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19a6ec: 0x3c010029
    ctx->pc = 0x19a6ecu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a6f0: 0xc4204e44
    ctx->pc = 0x19a6f0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a6f4: 0xe4400034
    ctx->pc = 0x19a6f4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19a6f8: 0x3c010029
    ctx->pc = 0x19a6f8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a6fc: 0xc4204e48
    ctx->pc = 0x19a6fcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a700: 0xe4400038
    ctx->pc = 0x19a700u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19a704: 0x3c010029
    ctx->pc = 0x19a704u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a708: 0xc4204e4c
    ctx->pc = 0x19a708u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a70c: 0xc066500
    ctx->pc = 0x19A70Cu;
    SET_GPR_U32(ctx, 31, 0x19A714u);
    ctx->pc = 0x19A710u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
    ctx->pc = 0x199400u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A714u; }
    }
    if (ctx->pc != 0x19A714u) { return; }
    ctx->pc = 0x19A714u;
    // 0x19a714: 0x3c060029
    ctx->pc = 0x19a714u;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x19a718: 0x24440080
    ctx->pc = 0x19a718u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 128));
    // 0x19a71c: 0xc0664e0
    ctx->pc = 0x19A71Cu;
    SET_GPR_U32(ctx, 31, 0x19A724u);
    ctx->pc = 0x19A720u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19712));
    ctx->pc = 0x199380u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A724u; }
    }
    if (ctx->pc != 0x19A724u) { return; }
    ctx->pc = 0x19A724u;
    // 0x19a724: 0xc066734
    ctx->pc = 0x19A724u;
    SET_GPR_U32(ctx, 31, 0x19A72Cu);
    ctx->pc = 0x19A728u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 192));
    ctx->pc = 0x199CD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A72Cu; }
    }
    if (ctx->pc != 0x19A72Cu) { return; }
    ctx->pc = 0x19A72Cu;
    // 0x19a72c: 0x3c01002a
    ctx->pc = 0x19a72cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19a730: 0x3c033f80
    ctx->pc = 0x19a730u;
    SET_GPR_U32(ctx, 3, ((uint32_t)16256 << 16));
    // 0x19a734: 0xc421fe40
    ctx->pc = 0x19a734u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a738: 0x44830000
    ctx->pc = 0x19a738u;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 3);
    // 0x19a73c: 0x3c031500
    ctx->pc = 0x19a73cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19a740: 0x2231825
    ctx->pc = 0x19a740u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x19a744: 0xe44100f0
    ctx->pc = 0x19a744u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 240), bits); }
    // 0x19a748: 0x3c01002a
    ctx->pc = 0x19a748u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19a74c: 0xc422fe40
    ctx->pc = 0x19a74cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19a750: 0x3c01002a
    ctx->pc = 0x19a750u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19a754: 0xc421fe48
    ctx->pc = 0x19a754u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a758: 0x46011041
    ctx->pc = 0x19a758u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19a75c: 0x46010003
    ctx->pc = 0x19a75cu;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ ctx->f[0] = copysignf(INFINITY, ctx->f[0] * 0.0f); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19a760: 0xe44000f4
    ctx->pc = 0x19a760u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 244), bits); }
    // 0x19a764: 0xac4000f8
    ctx->pc = 0x19a764u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 248), GPR_U32(ctx, 0));
    // 0x19a768: 0xac4000fc
    ctx->pc = 0x19a768u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 252), GPR_U32(ctx, 0));
    // 0x19a76c: 0xac430100
    ctx->pc = 0x19a76cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 256), GPR_U32(ctx, 3));
    // 0x19a770: 0xac400104
    ctx->pc = 0x19a770u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 260), GPR_U32(ctx, 0));
    // 0x19a774: 0xac400108
    ctx->pc = 0x19a774u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 264), GPR_U32(ctx, 0));
    // 0x19a778: 0xac40010c
    ctx->pc = 0x19a778u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 268), GPR_U32(ctx, 0));
    // 0x19a77c: 0xdfbf0030
    ctx->pc = 0x19a77cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19a780: 0x7bb20020
    ctx->pc = 0x19a780u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19a784: 0x7bb10010
    ctx->pc = 0x19a784u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19a788: 0x7bb00000
    ctx->pc = 0x19a788u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19a78c: 0x3e00008
    ctx->pc = 0x19A78Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19A790u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 128));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19A794u;
    // 0x19a794: 0x0
    ctx->pc = 0x19a794u;
    // NOP
    // 0x19a798: 0x0
    ctx->pc = 0x19a798u;
    // NOP
    // 0x19a79c: 0x0
    ctx->pc = 0x19a79cu;
    // NOP
    // 0x19a7a0: 0x27bdff80
    ctx->pc = 0x19a7a0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x19a7a4: 0xffbf0030
    ctx->pc = 0x19a7a4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19a7a8: 0x7fb20020
    ctx->pc = 0x19a7a8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19a7ac: 0x7fb10010
    ctx->pc = 0x19a7acu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19a7b0: 0x80902d
    ctx->pc = 0x19a7b0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a7b4: 0x7fb00000
    ctx->pc = 0x19a7b4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19a7b8: 0xa0882d
    ctx->pc = 0x19a7b8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a7bc: 0xc0802d
    ctx->pc = 0x19a7bcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a7c0: 0x24040150
    ctx->pc = 0x19a7c0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 336));
    // 0x19a7c4: 0xc063774
    ctx->pc = 0x19A7C4u;
    SET_GPR_U32(ctx, 31, 0x19A7CCu);
    ctx->pc = 0x19A7C8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A7CCu; }
    }
    if (ctx->pc != 0x19A7CCu) { return; }
    ctx->pc = 0x19A7CCu;
    // 0x19a7cc: 0x3c032000
    ctx->pc = 0x19a7ccu;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x19a7d0: 0x3c080029
    ctx->pc = 0x19a7d0u;
    SET_GPR_U32(ctx, 8, ((uint32_t)41 << 16));
    // 0x19a7d4: 0x34640014
    ctx->pc = 0x19a7d4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 20));
    // 0x19a7d8: 0x3c051300
    ctx->pc = 0x19a7d8u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4864 << 16));
    // 0x19a7dc: 0xac440000
    ctx->pc = 0x19a7dcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19a7e0: 0x3c030100
    ctx->pc = 0x19a7e0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x19a7e4: 0xac500004
    ctx->pc = 0x19a7e4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19a7e8: 0x34660404
    ctx->pc = 0x19a7e8u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 1028));
    // 0x19a7ec: 0xfc400008
    ctx->pc = 0x19a7ecu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19a7f0: 0x3c076c12
    ctx->pc = 0x19a7f0u;
    SET_GPR_U32(ctx, 7, ((uint32_t)27666 << 16));
    // 0x19a7f4: 0xac450010
    ctx->pc = 0x19a7f4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x19a7f8: 0x3c037000
    ctx->pc = 0x19a7f8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19a7fc: 0xac400014
    ctx->pc = 0x19a7fcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19a800: 0x3c010029
    ctx->pc = 0x19a800u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a804: 0xac460018
    ctx->pc = 0x19a804u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x19a808: 0x24440040
    ctx->pc = 0x19a808u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 64));
    // 0x19a80c: 0xac47001c
    ctx->pc = 0x19a80cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x19a810: 0x34663700
    ctx->pc = 0x19a810u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 14080));
    // 0x19a814: 0x34673f40
    ctx->pc = 0x19a814u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19a818: 0x27a50040
    ctx->pc = 0x19a818u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 64));
    // 0x19a81c: 0x8e43004c
    ctx->pc = 0x19a81cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a820: 0xc4214e50
    ctx->pc = 0x19a820u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a824: 0x25084d40
    ctx->pc = 0x19a824u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19a828: 0xc4600024
    ctx->pc = 0x19a828u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a82c: 0x3c010029
    ctx->pc = 0x19a82cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a830: 0x46000802
    ctx->pc = 0x19a830u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a834: 0xe4400020
    ctx->pc = 0x19a834u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19a838: 0x8e43004c
    ctx->pc = 0x19a838u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a83c: 0xc4214e54
    ctx->pc = 0x19a83cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a840: 0xc4600024
    ctx->pc = 0x19a840u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a844: 0x3c010029
    ctx->pc = 0x19a844u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a848: 0x46000802
    ctx->pc = 0x19a848u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a84c: 0xe4400024
    ctx->pc = 0x19a84cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19a850: 0x8e43004c
    ctx->pc = 0x19a850u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a854: 0xc4214e58
    ctx->pc = 0x19a854u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a858: 0xc4600024
    ctx->pc = 0x19a858u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a85c: 0x3c010029
    ctx->pc = 0x19a85cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a860: 0x46000802
    ctx->pc = 0x19a860u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a864: 0xe4400028
    ctx->pc = 0x19a864u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19a868: 0xc4204e5c
    ctx->pc = 0x19a868u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a86c: 0xe440002c
    ctx->pc = 0x19a86cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19a870: 0x3c010029
    ctx->pc = 0x19a870u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a874: 0xc4204e40
    ctx->pc = 0x19a874u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a878: 0xe4400030
    ctx->pc = 0x19a878u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19a87c: 0x3c010029
    ctx->pc = 0x19a87cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a880: 0xc4204e44
    ctx->pc = 0x19a880u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a884: 0xe4400034
    ctx->pc = 0x19a884u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19a888: 0x3c010029
    ctx->pc = 0x19a888u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a88c: 0xc4204e48
    ctx->pc = 0x19a88cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a890: 0xe4400038
    ctx->pc = 0x19a890u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19a894: 0x3c010029
    ctx->pc = 0x19a894u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a898: 0xc4204e4c
    ctx->pc = 0x19a898u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a89c: 0xc066500
    ctx->pc = 0x19A89Cu;
    SET_GPR_U32(ctx, 31, 0x19A8A4u);
    ctx->pc = 0x19A8A0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
    ctx->pc = 0x199400u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A8A4u; }
    }
    if (ctx->pc != 0x19A8A4u) { return; }
    ctx->pc = 0x19A8A4u;
    // 0x19a8a4: 0x3c060029
    ctx->pc = 0x19a8a4u;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x19a8a8: 0x24440080
    ctx->pc = 0x19a8a8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 128));
    // 0x19a8ac: 0xc0664e0
    ctx->pc = 0x19A8ACu;
    SET_GPR_U32(ctx, 31, 0x19A8B4u);
    ctx->pc = 0x19A8B0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19712));
    ctx->pc = 0x199380u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A8B4u; }
    }
    if (ctx->pc != 0x19A8B4u) { return; }
    ctx->pc = 0x19A8B4u;
    // 0x19a8b4: 0xc066734
    ctx->pc = 0x19A8B4u;
    SET_GPR_U32(ctx, 31, 0x19A8BCu);
    ctx->pc = 0x19A8B8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 192));
    ctx->pc = 0x199CD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A8BCu; }
    }
    if (ctx->pc != 0x19A8BCu) { return; }
    ctx->pc = 0x19A8BCu;
    // 0x19a8bc: 0x3c070029
    ctx->pc = 0x19a8bcu;
    SET_GPR_U32(ctx, 7, ((uint32_t)41 << 16));
    // 0x19a8c0: 0x24460100
    ctx->pc = 0x19a8c0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 2), 256));
    // 0x19a8c4: 0x24e74cc0
    ctx->pc = 0x19a8c4u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 19648));
    // 0x19a8c8: 0x24050008
    ctx->pc = 0x19a8c8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
label_19a8cc:
    // 0x19a8cc: 0x8ce40000
    ctx->pc = 0x19a8ccu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19a8d0: 0x24a5ffff
    ctx->pc = 0x19a8d0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19a8d4: 0x8ce30004
    ctx->pc = 0x19a8d4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19a8d8: 0xacc40000
    ctx->pc = 0x19a8d8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19a8dc: 0x24e70008
    ctx->pc = 0x19a8dcu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 8));
    // 0x19a8e0: 0xacc30004
    ctx->pc = 0x19a8e0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19a8e4: 0x1ca0fff9
    ctx->pc = 0x19A8E4u;
    {
        const bool branch_taken_0x19a8e4 = (GPR_S32(ctx, 5) > 0);
        ctx->pc = 0x19A8E8u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 8));
        if (branch_taken_0x19a8e4) {
            ctx->pc = 0x19A8CCu;
            goto label_19a8cc;
        }
    }
    ctx->pc = 0x19A8ECu;
    // 0x19a8ec: 0x3c01002a
    ctx->pc = 0x19a8ecu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19a8f0: 0x3c033f80
    ctx->pc = 0x19a8f0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)16256 << 16));
    // 0x19a8f4: 0xc421fe40
    ctx->pc = 0x19a8f4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a8f8: 0x44830000
    ctx->pc = 0x19a8f8u;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 3);
    // 0x19a8fc: 0x3c031500
    ctx->pc = 0x19a8fcu;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19a900: 0x2231825
    ctx->pc = 0x19a900u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x19a904: 0xe44100f0
    ctx->pc = 0x19a904u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 240), bits); }
    // 0x19a908: 0x3c01002a
    ctx->pc = 0x19a908u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19a90c: 0xc422fe40
    ctx->pc = 0x19a90cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19a910: 0x3c01002a
    ctx->pc = 0x19a910u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19a914: 0xc421fe48
    ctx->pc = 0x19a914u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a918: 0x46011041
    ctx->pc = 0x19a918u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19a91c: 0x46010003
    ctx->pc = 0x19a91cu;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ ctx->f[0] = copysignf(INFINITY, ctx->f[0] * 0.0f); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19a920: 0xe44000f4
    ctx->pc = 0x19a920u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 244), bits); }
    // 0x19a924: 0xac4000f8
    ctx->pc = 0x19a924u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 248), GPR_U32(ctx, 0));
    // 0x19a928: 0xac4000fc
    ctx->pc = 0x19a928u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 252), GPR_U32(ctx, 0));
    // 0x19a92c: 0xac430140
    ctx->pc = 0x19a92cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 320), GPR_U32(ctx, 3));
    // 0x19a930: 0xac400144
    ctx->pc = 0x19a930u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 324), GPR_U32(ctx, 0));
    // 0x19a934: 0xac400148
    ctx->pc = 0x19a934u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 328), GPR_U32(ctx, 0));
    // 0x19a938: 0xac40014c
    ctx->pc = 0x19a938u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 332), GPR_U32(ctx, 0));
    // 0x19a93c: 0xdfbf0030
    ctx->pc = 0x19a93cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19a940: 0x7bb20020
    ctx->pc = 0x19a940u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19a944: 0x7bb10010
    ctx->pc = 0x19a944u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19a948: 0x7bb00000
    ctx->pc = 0x19a948u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19a94c: 0x3e00008
    ctx->pc = 0x19A94Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19A950u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 128));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19A954u;
    // 0x19a954: 0x0
    ctx->pc = 0x19a954u;
    // NOP
    // 0x19a958: 0x0
    ctx->pc = 0x19a958u;
    // NOP
    // 0x19a95c: 0x0
    ctx->pc = 0x19a95cu;
    // NOP
    // 0x19a960: 0x27bdff80
    ctx->pc = 0x19a960u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x19a964: 0xffbf0030
    ctx->pc = 0x19a964u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19a968: 0x7fb20020
    ctx->pc = 0x19a968u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19a96c: 0x7fb10010
    ctx->pc = 0x19a96cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19a970: 0x80902d
    ctx->pc = 0x19a970u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a974: 0x7fb00000
    ctx->pc = 0x19a974u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19a978: 0xa0882d
    ctx->pc = 0x19a978u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a97c: 0xc0802d
    ctx->pc = 0x19a97cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19a980: 0x24040110
    ctx->pc = 0x19a980u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 272));
    // 0x19a984: 0xc063774
    ctx->pc = 0x19A984u;
    SET_GPR_U32(ctx, 31, 0x19A98Cu);
    ctx->pc = 0x19A988u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19A98Cu; }
    }
    if (ctx->pc != 0x19A98Cu) { return; }
    ctx->pc = 0x19A98Cu;
    // 0x19a98c: 0x3c032000
    ctx->pc = 0x19a98cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x19a990: 0x3c080029
    ctx->pc = 0x19a990u;
    SET_GPR_U32(ctx, 8, ((uint32_t)41 << 16));
    // 0x19a994: 0x34640010
    ctx->pc = 0x19a994u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 16));
    // 0x19a998: 0x3c051300
    ctx->pc = 0x19a998u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4864 << 16));
    // 0x19a99c: 0xac440000
    ctx->pc = 0x19a99cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19a9a0: 0x3c030100
    ctx->pc = 0x19a9a0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x19a9a4: 0xac500004
    ctx->pc = 0x19a9a4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19a9a8: 0x34660404
    ctx->pc = 0x19a9a8u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 1028));
    // 0x19a9ac: 0xfc400008
    ctx->pc = 0x19a9acu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19a9b0: 0x3c076c0e
    ctx->pc = 0x19a9b0u;
    SET_GPR_U32(ctx, 7, ((uint32_t)27662 << 16));
    // 0x19a9b4: 0xac450010
    ctx->pc = 0x19a9b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x19a9b8: 0x3c037000
    ctx->pc = 0x19a9b8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19a9bc: 0xac400014
    ctx->pc = 0x19a9bcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19a9c0: 0x3c010029
    ctx->pc = 0x19a9c0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a9c4: 0xac460018
    ctx->pc = 0x19a9c4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x19a9c8: 0x24440040
    ctx->pc = 0x19a9c8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 64));
    // 0x19a9cc: 0xac47001c
    ctx->pc = 0x19a9ccu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x19a9d0: 0x34663700
    ctx->pc = 0x19a9d0u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 14080));
    // 0x19a9d4: 0x34673f40
    ctx->pc = 0x19a9d4u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19a9d8: 0x27a50040
    ctx->pc = 0x19a9d8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 64));
    // 0x19a9dc: 0x8e43004c
    ctx->pc = 0x19a9dcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a9e0: 0xc4214e50
    ctx->pc = 0x19a9e0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19a9e4: 0x25084d40
    ctx->pc = 0x19a9e4u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19a9e8: 0xc4600024
    ctx->pc = 0x19a9e8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19a9ec: 0x3c010029
    ctx->pc = 0x19a9ecu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19a9f0: 0x46000802
    ctx->pc = 0x19a9f0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19a9f4: 0xe4400020
    ctx->pc = 0x19a9f4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19a9f8: 0x8e43004c
    ctx->pc = 0x19a9f8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19a9fc: 0xc4214e54
    ctx->pc = 0x19a9fcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19aa00: 0xc4600024
    ctx->pc = 0x19aa00u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19aa04: 0x3c010029
    ctx->pc = 0x19aa04u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19aa08: 0x46000802
    ctx->pc = 0x19aa08u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19aa0c: 0xe4400024
    ctx->pc = 0x19aa0cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19aa10: 0x8e43004c
    ctx->pc = 0x19aa10u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19aa14: 0xc4214e58
    ctx->pc = 0x19aa14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19aa18: 0xc4600024
    ctx->pc = 0x19aa18u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19aa1c: 0x3c010029
    ctx->pc = 0x19aa1cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19aa20: 0x46000802
    ctx->pc = 0x19aa20u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19aa24: 0xe4400028
    ctx->pc = 0x19aa24u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19aa28: 0xc4204e5c
    ctx->pc = 0x19aa28u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19aa2c: 0xe440002c
    ctx->pc = 0x19aa2cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19aa30: 0x3c010029
    ctx->pc = 0x19aa30u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19aa34: 0xc4204e40
    ctx->pc = 0x19aa34u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19aa38: 0xe4400030
    ctx->pc = 0x19aa38u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19aa3c: 0x3c010029
    ctx->pc = 0x19aa3cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19aa40: 0xc4204e44
    ctx->pc = 0x19aa40u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19aa44: 0xe4400034
    ctx->pc = 0x19aa44u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19aa48: 0x3c010029
    ctx->pc = 0x19aa48u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19aa4c: 0xc4204e48
    ctx->pc = 0x19aa4cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19aa50: 0xe4400038
    ctx->pc = 0x19aa50u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19aa54: 0x3c010029
    ctx->pc = 0x19aa54u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19aa58: 0xc4204e4c
    ctx->pc = 0x19aa58u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19aa5c: 0xc066500
    ctx->pc = 0x19AA5Cu;
    SET_GPR_U32(ctx, 31, 0x19AA64u);
    ctx->pc = 0x19AA60u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
    ctx->pc = 0x199400u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AA64u; }
    }
    if (ctx->pc != 0x19AA64u) { return; }
    ctx->pc = 0x19AA64u;
    // 0x19aa64: 0x3c060029
    ctx->pc = 0x19aa64u;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x19aa68: 0x24440080
    ctx->pc = 0x19aa68u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 128));
    // 0x19aa6c: 0xc0664e0
    ctx->pc = 0x19AA6Cu;
    SET_GPR_U32(ctx, 31, 0x19AA74u);
    ctx->pc = 0x19AA70u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19712));
    ctx->pc = 0x199380u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AA74u; }
    }
    if (ctx->pc != 0x19AA74u) { return; }
    ctx->pc = 0x19AA74u;
    // 0x19aa74: 0x3c070029
    ctx->pc = 0x19aa74u;
    SET_GPR_U32(ctx, 7, ((uint32_t)41 << 16));
    // 0x19aa78: 0x244600c0
    ctx->pc = 0x19aa78u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 2), 192));
    // 0x19aa7c: 0x24e74cc0
    ctx->pc = 0x19aa7cu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 19648));
    // 0x19aa80: 0x24050008
    ctx->pc = 0x19aa80u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
label_19aa84:
    // 0x19aa84: 0x8ce40000
    ctx->pc = 0x19aa84u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19aa88: 0x24a5ffff
    ctx->pc = 0x19aa88u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19aa8c: 0x8ce30004
    ctx->pc = 0x19aa8cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19aa90: 0xacc40000
    ctx->pc = 0x19aa90u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19aa94: 0x24e70008
    ctx->pc = 0x19aa94u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 8));
    // 0x19aa98: 0xacc30004
    ctx->pc = 0x19aa98u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19aa9c: 0x1ca0fff9
    ctx->pc = 0x19AA9Cu;
    {
        const bool branch_taken_0x19aa9c = (GPR_S32(ctx, 5) > 0);
        ctx->pc = 0x19AAA0u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 8));
        if (branch_taken_0x19aa9c) {
            ctx->pc = 0x19AA84u;
            goto label_19aa84;
        }
    }
    ctx->pc = 0x19AAA4u;
    // 0x19aaa4: 0x3c031500
    ctx->pc = 0x19aaa4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19aaa8: 0x2231825
    ctx->pc = 0x19aaa8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x19aaac: 0xac430100
    ctx->pc = 0x19aaacu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 256), GPR_U32(ctx, 3));
    // 0x19aab0: 0xac400104
    ctx->pc = 0x19aab0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 260), GPR_U32(ctx, 0));
    // 0x19aab4: 0xac400108
    ctx->pc = 0x19aab4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 264), GPR_U32(ctx, 0));
    // 0x19aab8: 0xac40010c
    ctx->pc = 0x19aab8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 268), GPR_U32(ctx, 0));
    // 0x19aabc: 0xdfbf0030
    ctx->pc = 0x19aabcu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19aac0: 0x7bb20020
    ctx->pc = 0x19aac0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19aac4: 0x7bb10010
    ctx->pc = 0x19aac4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19aac8: 0x7bb00000
    ctx->pc = 0x19aac8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19aacc: 0x3e00008
    ctx->pc = 0x19AACCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19AAD0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 128));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19AAD4u;
    // 0x19aad4: 0x0
    ctx->pc = 0x19aad4u;
    // NOP
    // 0x19aad8: 0x0
    ctx->pc = 0x19aad8u;
    // NOP
    // 0x19aadc: 0x0
    ctx->pc = 0x19aadcu;
    // NOP
    // 0x19aae0: 0x27bdff40
    ctx->pc = 0x19aae0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x19aae4: 0xffbf0040
    ctx->pc = 0x19aae4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x19aae8: 0x7fb30030
    ctx->pc = 0x19aae8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19aaec: 0x7fb20020
    ctx->pc = 0x19aaecu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19aaf0: 0x80982d
    ctx->pc = 0x19aaf0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19aaf4: 0x7fb10010
    ctx->pc = 0x19aaf4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19aaf8: 0xa0902d
    ctx->pc = 0x19aaf8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19aafc: 0xc0882d
    ctx->pc = 0x19aafcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ab00: 0x24040170
    ctx->pc = 0x19ab00u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 368));
    // 0x19ab04: 0x24050010
    ctx->pc = 0x19ab04u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    // 0x19ab08: 0xc063774
    ctx->pc = 0x19AB08u;
    SET_GPR_U32(ctx, 31, 0x19AB10u);
    ctx->pc = 0x19AB0Cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AB10u; }
    }
    if (ctx->pc != 0x19AB10u) { return; }
    ctx->pc = 0x19AB10u;
    // 0x19ab10: 0x3c032000
    ctx->pc = 0x19ab10u;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x19ab14: 0x3c080029
    ctx->pc = 0x19ab14u;
    SET_GPR_U32(ctx, 8, ((uint32_t)41 << 16));
    // 0x19ab18: 0x34630016
    ctx->pc = 0x19ab18u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 22));
    // 0x19ab1c: 0x3c061300
    ctx->pc = 0x19ab1cu;
    SET_GPR_U32(ctx, 6, ((uint32_t)4864 << 16));
    // 0x19ab20: 0xac430000
    ctx->pc = 0x19ab20u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x19ab24: 0x3c056c14
    ctx->pc = 0x19ab24u;
    SET_GPR_U32(ctx, 5, ((uint32_t)27668 << 16));
    // 0x19ab28: 0xac510004
    ctx->pc = 0x19ab28u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 17));
    // 0x19ab2c: 0x3c030100
    ctx->pc = 0x19ab2cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x19ab30: 0xfc400008
    ctx->pc = 0x19ab30u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19ab34: 0x34640404
    ctx->pc = 0x19ab34u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 1028));
    // 0x19ab38: 0xac460010
    ctx->pc = 0x19ab38u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 6));
    // 0x19ab3c: 0x3c033f80
    ctx->pc = 0x19ab3cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)16256 << 16));
    // 0x19ab40: 0xac400014
    ctx->pc = 0x19ab40u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19ab44: 0x44830000
    ctx->pc = 0x19ab44u;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 3);
    // 0x19ab48: 0xac440018
    ctx->pc = 0x19ab48u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 4));
    // 0x19ab4c: 0x40802d
    ctx->pc = 0x19ab4cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ab50: 0xac45001c
    ctx->pc = 0x19ab50u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 5));
    // 0x19ab54: 0x3c037000
    ctx->pc = 0x19ab54u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19ab58: 0x8e69004c
    ctx->pc = 0x19ab58u;
    SET_GPR_U32(ctx, 9, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19ab5c: 0x3c010029
    ctx->pc = 0x19ab5cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ab60: 0xc4224e50
    ctx->pc = 0x19ab60u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19ab64: 0x34663700
    ctx->pc = 0x19ab64u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 14080));
    // 0x19ab68: 0x34673f40
    ctx->pc = 0x19ab68u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19ab6c: 0x26040040
    ctx->pc = 0x19ab6cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 64));
    // 0x19ab70: 0x27a50080
    ctx->pc = 0x19ab70u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 128));
    // 0x19ab74: 0x25084d40
    ctx->pc = 0x19ab74u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19ab78: 0xc5210024
    ctx->pc = 0x19ab78u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 9), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ab7c: 0x3c010029
    ctx->pc = 0x19ab7cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ab80: 0x46011042
    ctx->pc = 0x19ab80u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19ab84: 0xe4410020
    ctx->pc = 0x19ab84u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19ab88: 0x8e63004c
    ctx->pc = 0x19ab88u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19ab8c: 0xc4224e54
    ctx->pc = 0x19ab8cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19ab90: 0xc4610024
    ctx->pc = 0x19ab90u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ab94: 0x3c010029
    ctx->pc = 0x19ab94u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ab98: 0x46011042
    ctx->pc = 0x19ab98u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19ab9c: 0xe4410024
    ctx->pc = 0x19ab9cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19aba0: 0x8e63004c
    ctx->pc = 0x19aba0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19aba4: 0xc4224e58
    ctx->pc = 0x19aba4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19aba8: 0xc4610024
    ctx->pc = 0x19aba8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19abac: 0x3c010029
    ctx->pc = 0x19abacu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19abb0: 0x46011042
    ctx->pc = 0x19abb0u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19abb4: 0xe4410028
    ctx->pc = 0x19abb4u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19abb8: 0xc4214e5c
    ctx->pc = 0x19abb8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19abbc: 0xe441002c
    ctx->pc = 0x19abbcu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19abc0: 0x3c01002a
    ctx->pc = 0x19abc0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19abc4: 0xc421fe40
    ctx->pc = 0x19abc4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19abc8: 0xe4410030
    ctx->pc = 0x19abc8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19abcc: 0x3c01002a
    ctx->pc = 0x19abccu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19abd0: 0xc422fe40
    ctx->pc = 0x19abd0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19abd4: 0x3c01002a
    ctx->pc = 0x19abd4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19abd8: 0xc421fe48
    ctx->pc = 0x19abd8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19abdc: 0x46011041
    ctx->pc = 0x19abdcu;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19abe0: 0x46010003
    ctx->pc = 0x19abe0u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ ctx->f[0] = copysignf(INFINITY, ctx->f[0] * 0.0f); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19abe4: 0xe4400034
    ctx->pc = 0x19abe4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19abe8: 0xac400038
    ctx->pc = 0x19abe8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 56), GPR_U32(ctx, 0));
    // 0x19abec: 0xc066500
    ctx->pc = 0x19ABECu;
    SET_GPR_U32(ctx, 31, 0x19ABF4u);
    ctx->pc = 0x19ABF0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 60), GPR_U32(ctx, 0));
    ctx->pc = 0x199400u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19ABF4u; }
    }
    if (ctx->pc != 0x19ABF4u) { return; }
    ctx->pc = 0x19ABF4u;
    // 0x19abf4: 0x3c060029
    ctx->pc = 0x19abf4u;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x19abf8: 0x26040080
    ctx->pc = 0x19abf8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 128));
    // 0x19abfc: 0xc0664e0
    ctx->pc = 0x19ABFCu;
    SET_GPR_U32(ctx, 31, 0x19AC04u);
    ctx->pc = 0x19AC00u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19712));
    ctx->pc = 0x199380u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AC04u; }
    }
    if (ctx->pc != 0x19AC04u) { return; }
    ctx->pc = 0x19AC04u;
    // 0x19ac04: 0x3c010029
    ctx->pc = 0x19ac04u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ac08: 0x3c023f80
    ctx->pc = 0x19ac08u;
    SET_GPR_U32(ctx, 2, ((uint32_t)16256 << 16));
    // 0x19ac0c: 0xc4214234
    ctx->pc = 0x19ac0cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ac10: 0xafa2005c
    ctx->pc = 0x19ac10u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 2));
    // 0x19ac14: 0xafa2006c
    ctx->pc = 0x19ac14u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 2));
    // 0x19ac18: 0x260400c0
    ctx->pc = 0x19ac18u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 192));
    // 0x19ac1c: 0xafa2007c
    ctx->pc = 0x19ac1cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 124), GPR_U32(ctx, 2));
    // 0x19ac20: 0x260500f0
    ctx->pc = 0x19ac20u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 240));
    // 0x19ac24: 0x3c027000
    ctx->pc = 0x19ac24u;
    SET_GPR_U32(ctx, 2, ((uint32_t)28672 << 16));
    // 0x19ac28: 0x27a70050
    ctx->pc = 0x19ac28u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 29), 80));
    // 0x19ac2c: 0x34463700
    ctx->pc = 0x19ac2cu;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 2), 14080));
    // 0x19ac30: 0x3c010029
    ctx->pc = 0x19ac30u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ac34: 0xc4204238
    ctx->pc = 0x19ac34u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19ac38: 0x46000847
    ctx->pc = 0x19ac38u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19ac3c: 0xe7a10050
    ctx->pc = 0x19ac3cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19ac40: 0x3c010029
    ctx->pc = 0x19ac40u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ac44: 0xc424423c
    ctx->pc = 0x19ac44u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x19ac48: 0x46000147
    ctx->pc = 0x19ac48u;
    ctx->f[5] = FPU_NEG_S(ctx->f[0]);
    // 0x19ac4c: 0xe7a50054
    ctx->pc = 0x19ac4cu;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19ac50: 0x3c010029
    ctx->pc = 0x19ac50u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ac54: 0xc42342a8
    ctx->pc = 0x19ac54u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17064)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19ac58: 0x46002107
    ctx->pc = 0x19ac58u;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x19ac5c: 0xe7a40058
    ctx->pc = 0x19ac5cu;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x19ac60: 0x3c010029
    ctx->pc = 0x19ac60u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ac64: 0xc42242ac
    ctx->pc = 0x19ac64u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17068)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19ac68: 0xe7a30060
    ctx->pc = 0x19ac68u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x19ac6c: 0x3c010029
    ctx->pc = 0x19ac6cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ac70: 0xc42142b0
    ctx->pc = 0x19ac70u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17072)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ac74: 0xe7a20064
    ctx->pc = 0x19ac74u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x19ac78: 0x3c010029
    ctx->pc = 0x19ac78u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ac7c: 0xc4204310
    ctx->pc = 0x19ac7cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17168)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19ac80: 0xe7a10068
    ctx->pc = 0x19ac80u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
    // 0x19ac84: 0x3c010029
    ctx->pc = 0x19ac84u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ac88: 0xc4214314
    ctx->pc = 0x19ac88u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17172)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ac8c: 0xe7a00070
    ctx->pc = 0x19ac8cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 112), bits); }
    // 0x19ac90: 0x3c010029
    ctx->pc = 0x19ac90u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ac94: 0xc4204318
    ctx->pc = 0x19ac94u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19ac98: 0xe7a10074
    ctx->pc = 0x19ac98u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 116), bits); }
    // 0x19ac9c: 0xc0665d0
    ctx->pc = 0x19AC9Cu;
    SET_GPR_U32(ctx, 31, 0x19ACA4u);
    ctx->pc = 0x19ACA0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 120), bits); }
    ctx->pc = 0x199740u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199740_0x199740(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19ACA4u; }
    }
    if (ctx->pc != 0x19ACA4u) { return; }
    ctx->pc = 0x19ACA4u;
    // 0x19aca4: 0x8e62004c
    ctx->pc = 0x19aca4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19aca8: 0xc44c0024
    ctx->pc = 0x19aca8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19acac: 0xc0666a4
    ctx->pc = 0x19ACACu;
    SET_GPR_U32(ctx, 31, 0x19ACB4u);
    ctx->pc = 0x19ACB0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 256));
    ctx->pc = 0x199A90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199A90_0x199a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19ACB4u; }
    }
    if (ctx->pc != 0x19ACB4u) { return; }
    ctx->pc = 0x19ACB4u;
    // 0x19acb4: 0x3c031500
    ctx->pc = 0x19acb4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19acb8: 0x200102d
    ctx->pc = 0x19acb8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19acbc: 0x2431825
    ctx->pc = 0x19acbcu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x19acc0: 0xae030160
    ctx->pc = 0x19acc0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 352), GPR_U32(ctx, 3));
    // 0x19acc4: 0xae000164
    ctx->pc = 0x19acc4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 356), GPR_U32(ctx, 0));
    // 0x19acc8: 0xae000168
    ctx->pc = 0x19acc8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 360), GPR_U32(ctx, 0));
    // 0x19accc: 0xae00016c
    ctx->pc = 0x19acccu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 364), GPR_U32(ctx, 0));
    // 0x19acd0: 0xdfbf0040
    ctx->pc = 0x19acd0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19acd4: 0x7bb30030
    ctx->pc = 0x19acd4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19acd8: 0x7bb20020
    ctx->pc = 0x19acd8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19acdc: 0x7bb10010
    ctx->pc = 0x19acdcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19ace0: 0x7bb00000
    ctx->pc = 0x19ace0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19ace4: 0x3e00008
    ctx->pc = 0x19ACE4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19ACE8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 192));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19ACECu;
    // 0x19acec: 0x0
    ctx->pc = 0x19acecu;
    // NOP
    // 0x19acf0: 0x27bdff90
    ctx->pc = 0x19acf0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x19acf4: 0xffbf0030
    ctx->pc = 0x19acf4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19acf8: 0x7fb20020
    ctx->pc = 0x19acf8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19acfc: 0x7fb10010
    ctx->pc = 0x19acfcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19ad00: 0x80902d
    ctx->pc = 0x19ad00u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ad04: 0x7fb00000
    ctx->pc = 0x19ad04u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19ad08: 0xa0882d
    ctx->pc = 0x19ad08u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ad0c: 0xc0802d
    ctx->pc = 0x19ad0cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19ad10: 0x24040f70
    ctx->pc = 0x19ad10u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 3952));
    // 0x19ad14: 0xc063774
    ctx->pc = 0x19AD14u;
    SET_GPR_U32(ctx, 31, 0x19AD1Cu);
    ctx->pc = 0x19AD18u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AD1Cu; }
    }
    if (ctx->pc != 0x19AD1Cu) { return; }
    ctx->pc = 0x19AD1Cu;
    // 0x19ad1c: 0x3c032000
    ctx->pc = 0x19ad1cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x19ad20: 0x3c070029
    ctx->pc = 0x19ad20u;
    SET_GPR_U32(ctx, 7, ((uint32_t)41 << 16));
    // 0x19ad24: 0x346400f6
    ctx->pc = 0x19ad24u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 246));
    // 0x19ad28: 0x3c061300
    ctx->pc = 0x19ad28u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4864 << 16));
    // 0x19ad2c: 0xac440000
    ctx->pc = 0x19ad2cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19ad30: 0x3c030100
    ctx->pc = 0x19ad30u;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x19ad34: 0xac500004
    ctx->pc = 0x19ad34u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19ad38: 0x34650404
    ctx->pc = 0x19ad38u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 3), 1028));
    // 0x19ad3c: 0xfc400008
    ctx->pc = 0x19ad3cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19ad40: 0x3c033f80
    ctx->pc = 0x19ad40u;
    SET_GPR_U32(ctx, 3, ((uint32_t)16256 << 16));
    // 0x19ad44: 0xac460010
    ctx->pc = 0x19ad44u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 6));
    // 0x19ad48: 0x3c046cf4
    ctx->pc = 0x19ad48u;
    SET_GPR_U32(ctx, 4, ((uint32_t)27892 << 16));
    // 0x19ad4c: 0xac400014
    ctx->pc = 0x19ad4cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19ad50: 0x44830000
    ctx->pc = 0x19ad50u;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 3);
    // 0x19ad54: 0xac450018
    ctx->pc = 0x19ad54u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 5));
    // 0x19ad58: 0x3c010029
    ctx->pc = 0x19ad58u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ad5c: 0xac44001c
    ctx->pc = 0x19ad5cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 4));
    // 0x19ad60: 0x24e74d40
    ctx->pc = 0x19ad60u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 19776));
    // 0x19ad64: 0x8e43004c
    ctx->pc = 0x19ad64u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19ad68: 0xc4224e50
    ctx->pc = 0x19ad68u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19ad6c: 0x24460040
    ctx->pc = 0x19ad6cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 2), 64));
    // 0x19ad70: 0x24050008
    ctx->pc = 0x19ad70u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
    // 0x19ad74: 0xc4610024
    ctx->pc = 0x19ad74u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ad78: 0x3c010029
    ctx->pc = 0x19ad78u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ad7c: 0x46011042
    ctx->pc = 0x19ad7cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19ad80: 0xe4410020
    ctx->pc = 0x19ad80u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19ad84: 0x8e43004c
    ctx->pc = 0x19ad84u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19ad88: 0xc4224e54
    ctx->pc = 0x19ad88u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19ad8c: 0xc4610024
    ctx->pc = 0x19ad8cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ad90: 0x3c010029
    ctx->pc = 0x19ad90u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ad94: 0x46011042
    ctx->pc = 0x19ad94u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19ad98: 0xe4410024
    ctx->pc = 0x19ad98u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19ad9c: 0x8e43004c
    ctx->pc = 0x19ad9cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19ada0: 0xc4224e58
    ctx->pc = 0x19ada0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19ada4: 0xc4610024
    ctx->pc = 0x19ada4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ada8: 0x3c010029
    ctx->pc = 0x19ada8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19adac: 0x46011042
    ctx->pc = 0x19adacu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19adb0: 0xe4410028
    ctx->pc = 0x19adb0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19adb4: 0xc4214e5c
    ctx->pc = 0x19adb4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19adb8: 0xe441002c
    ctx->pc = 0x19adb8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19adbc: 0x3c01002a
    ctx->pc = 0x19adbcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19adc0: 0xc421fe40
    ctx->pc = 0x19adc0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19adc4: 0xe4410030
    ctx->pc = 0x19adc4u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19adc8: 0x3c01002a
    ctx->pc = 0x19adc8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19adcc: 0xc422fe40
    ctx->pc = 0x19adccu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19add0: 0x3c01002a
    ctx->pc = 0x19add0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19add4: 0xc421fe48
    ctx->pc = 0x19add4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19add8: 0x46011041
    ctx->pc = 0x19add8u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19addc: 0x46010003
    ctx->pc = 0x19addcu;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ ctx->f[0] = copysignf(INFINITY, ctx->f[0] * 0.0f); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19ade0: 0xe4400034
    ctx->pc = 0x19ade0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19ade4: 0xac400038
    ctx->pc = 0x19ade4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 56), GPR_U32(ctx, 0));
    // 0x19ade8: 0xac40003c
    ctx->pc = 0x19ade8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 60), GPR_U32(ctx, 0));
label_19adec:
    // 0x19adec: 0x8ce40000
    ctx->pc = 0x19adecu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19adf0: 0x24a5ffff
    ctx->pc = 0x19adf0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19adf4: 0x8ce30004
    ctx->pc = 0x19adf4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19adf8: 0xacc40000
    ctx->pc = 0x19adf8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19adfc: 0x24e70008
    ctx->pc = 0x19adfcu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 8));
    // 0x19ae00: 0xacc30004
    ctx->pc = 0x19ae00u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19ae04: 0x1ca0fff9
    ctx->pc = 0x19AE04u;
    {
        const bool branch_taken_0x19ae04 = (GPR_S32(ctx, 5) > 0);
        ctx->pc = 0x19AE08u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 8));
        if (branch_taken_0x19ae04) {
            ctx->pc = 0x19ADECu;
            goto label_19adec;
        }
    }
    ctx->pc = 0x19AE0Cu;
    // 0x19ae0c: 0x3c070029
    ctx->pc = 0x19ae0cu;
    SET_GPR_U32(ctx, 7, ((uint32_t)41 << 16));
    // 0x19ae10: 0x24460080
    ctx->pc = 0x19ae10u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 2), 128));
    // 0x19ae14: 0x24e74d00
    ctx->pc = 0x19ae14u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 19712));
    // 0x19ae18: 0x24050008
    ctx->pc = 0x19ae18u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
label_19ae1c:
    // 0x19ae1c: 0x8ce40000
    ctx->pc = 0x19ae1cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19ae20: 0x24a5ffff
    ctx->pc = 0x19ae20u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19ae24: 0x8ce30004
    ctx->pc = 0x19ae24u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19ae28: 0xacc40000
    ctx->pc = 0x19ae28u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19ae2c: 0x24e70008
    ctx->pc = 0x19ae2cu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 8));
    // 0x19ae30: 0xacc30004
    ctx->pc = 0x19ae30u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19ae34: 0x1ca0fff9
    ctx->pc = 0x19AE34u;
    {
        const bool branch_taken_0x19ae34 = (GPR_S32(ctx, 5) > 0);
        ctx->pc = 0x19AE38u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 8));
        if (branch_taken_0x19ae34) {
            ctx->pc = 0x19AE1Cu;
            goto label_19ae1c;
        }
    }
    ctx->pc = 0x19AE3Cu;
    // 0x19ae3c: 0x402d
    ctx->pc = 0x19ae3cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_19ae40:
    // 0x19ae40: 0x8e430054
    ctx->pc = 0x19ae40u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 84)));
    // 0x19ae44: 0x24040001
    ctx->pc = 0x19ae44u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    // 0x19ae48: 0x1042004
    ctx->pc = 0x19ae48u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), GPR_U32(ctx, 8) & 0x1F));
    // 0x19ae4c: 0x641824
    ctx->pc = 0x19ae4cu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x19ae50: 0x1060000e
    ctx->pc = 0x19AE50u;
    {
        const bool branch_taken_0x19ae50 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x19AE54u;
        SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 8), 1));
        if (branch_taken_0x19ae50) {
            ctx->pc = 0x19AE8Cu;
            goto label_19ae8c;
        }
    }
    ctx->pc = 0x19AE58u;
    // 0x19ae58: 0x3c017000
    ctx->pc = 0x19ae58u;
    SET_GPR_U32(ctx, 1, ((uint32_t)28672 << 16));
    // 0x19ae5c: 0x682021
    ctx->pc = 0x19ae5cu;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x19ae60: 0x83180
    ctx->pc = 0x19ae60u;
    SET_GPR_U32(ctx, 6, SLL32(GPR_U32(ctx, 8), 6));
    // 0x19ae64: 0x461821
    ctx->pc = 0x19ae64u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x19ae68: 0x34213700
    ctx->pc = 0x19ae68u;
    SET_GPR_U32(ctx, 1, OR32(GPR_U32(ctx, 1), 14080));
    // 0x19ae6c: 0x42100
    ctx->pc = 0x19ae6cu;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 4));
    // 0x19ae70: 0x24650160
    ctx->pc = 0x19ae70u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 3), 352));
    // 0x19ae74: 0x441821
    ctx->pc = 0x19ae74u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x19ae78: 0xc13021
    ctx->pc = 0x19ae78u;
    SET_GPR_U32(ctx, 6, ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 1)));
    // 0x19ae7c: 0x24640960
    ctx->pc = 0x19ae7cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 3), 2400));
    // 0x19ae80: 0x3c037000
    ctx->pc = 0x19ae80u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19ae84: 0xc066538
    ctx->pc = 0x19AE84u;
    SET_GPR_U32(ctx, 31, 0x19AE8Cu);
    ctx->pc = 0x19AE88u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    ctx->pc = 0x1994E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001994E0_0x1994e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AE8Cu; }
    }
    if (ctx->pc != 0x19AE8Cu) { return; }
    ctx->pc = 0x19AE8Cu;
label_19ae8c:
    // 0x19ae8c: 0x25080001
    ctx->pc = 0x19ae8cu;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 1));
    // 0x19ae90: 0x29030020
    ctx->pc = 0x19ae90u;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 8), 32));
    // 0x19ae94: 0x1460ffea
    ctx->pc = 0x19AE94u;
    {
        const bool branch_taken_0x19ae94 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x19AE98u;
        SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
        if (branch_taken_0x19ae94) {
            ctx->pc = 0x19AE40u;
            goto label_19ae40;
        }
    }
    ctx->pc = 0x19AE9Cu;
    // 0x19ae9c: 0x3c033f80
    ctx->pc = 0x19ae9cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)16256 << 16));
    // 0x19aea0: 0xc4214234
    ctx->pc = 0x19aea0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19aea4: 0xafa3004c
    ctx->pc = 0x19aea4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 3));
    // 0x19aea8: 0xafa3005c
    ctx->pc = 0x19aea8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 3));
    // 0x19aeac: 0x244400c0
    ctx->pc = 0x19aeacu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 192));
    // 0x19aeb0: 0xafa3006c
    ctx->pc = 0x19aeb0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 3));
    // 0x19aeb4: 0x244500f0
    ctx->pc = 0x19aeb4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 2), 240));
    // 0x19aeb8: 0x3c037000
    ctx->pc = 0x19aeb8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19aebc: 0x27a70040
    ctx->pc = 0x19aebcu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 29), 64));
    // 0x19aec0: 0x34663f40
    ctx->pc = 0x19aec0u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19aec4: 0x3c010029
    ctx->pc = 0x19aec4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19aec8: 0xc4204238
    ctx->pc = 0x19aec8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19aecc: 0x46000847
    ctx->pc = 0x19aeccu;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19aed0: 0xe7a10040
    ctx->pc = 0x19aed0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x19aed4: 0x3c010029
    ctx->pc = 0x19aed4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19aed8: 0xc424423c
    ctx->pc = 0x19aed8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x19aedc: 0x46000147
    ctx->pc = 0x19aedcu;
    ctx->f[5] = FPU_NEG_S(ctx->f[0]);
    // 0x19aee0: 0xe7a50044
    ctx->pc = 0x19aee0u;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 68), bits); }
    // 0x19aee4: 0x3c010029
    ctx->pc = 0x19aee4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19aee8: 0xc42342a8
    ctx->pc = 0x19aee8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17064)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19aeec: 0x46002107
    ctx->pc = 0x19aeecu;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x19aef0: 0xe7a40048
    ctx->pc = 0x19aef0u;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 72), bits); }
    // 0x19aef4: 0x3c010029
    ctx->pc = 0x19aef4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19aef8: 0xc42242ac
    ctx->pc = 0x19aef8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17068)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19aefc: 0xe7a30050
    ctx->pc = 0x19aefcu;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19af00: 0x3c010029
    ctx->pc = 0x19af00u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19af04: 0xc42142b0
    ctx->pc = 0x19af04u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17072)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19af08: 0xe7a20054
    ctx->pc = 0x19af08u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19af0c: 0x3c010029
    ctx->pc = 0x19af0cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19af10: 0xc4204310
    ctx->pc = 0x19af10u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17168)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19af14: 0xe7a10058
    ctx->pc = 0x19af14u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x19af18: 0x3c010029
    ctx->pc = 0x19af18u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19af1c: 0xc4214314
    ctx->pc = 0x19af1cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17172)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19af20: 0xe7a00060
    ctx->pc = 0x19af20u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x19af24: 0x3c010029
    ctx->pc = 0x19af24u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19af28: 0xc4204318
    ctx->pc = 0x19af28u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19af2c: 0xe7a10064
    ctx->pc = 0x19af2cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x19af30: 0xc06661c
    ctx->pc = 0x19AF30u;
    SET_GPR_U32(ctx, 31, 0x19AF38u);
    ctx->pc = 0x19AF34u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
    ctx->pc = 0x199870u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199870_0x199870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AF38u; }
    }
    if (ctx->pc != 0x19AF38u) { return; }
    ctx->pc = 0x19AF38u;
    // 0x19af38: 0x8e43004c
    ctx->pc = 0x19af38u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19af3c: 0xc46c0024
    ctx->pc = 0x19af3cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19af40: 0xc0666a4
    ctx->pc = 0x19AF40u;
    SET_GPR_U32(ctx, 31, 0x19AF48u);
    ctx->pc = 0x19AF44u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 256));
    ctx->pc = 0x199A90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199A90_0x199a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AF48u; }
    }
    if (ctx->pc != 0x19AF48u) { return; }
    ctx->pc = 0x19AF48u;
    // 0x19af48: 0x3c031500
    ctx->pc = 0x19af48u;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19af4c: 0x2231825
    ctx->pc = 0x19af4cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x19af50: 0xac430f60
    ctx->pc = 0x19af50u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3936), GPR_U32(ctx, 3));
    // 0x19af54: 0xac400f64
    ctx->pc = 0x19af54u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3940), GPR_U32(ctx, 0));
    // 0x19af58: 0xac400f68
    ctx->pc = 0x19af58u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3944), GPR_U32(ctx, 0));
    // 0x19af5c: 0xac400f6c
    ctx->pc = 0x19af5cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3948), GPR_U32(ctx, 0));
    // 0x19af60: 0xdfbf0030
    ctx->pc = 0x19af60u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19af64: 0x7bb20020
    ctx->pc = 0x19af64u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19af68: 0x7bb10010
    ctx->pc = 0x19af68u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19af6c: 0x7bb00000
    ctx->pc = 0x19af6cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19af70: 0x3e00008
    ctx->pc = 0x19AF70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19AF74u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 112));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19AF78u;
    // 0x19af78: 0x0
    ctx->pc = 0x19af78u;
    // NOP
    // 0x19af7c: 0x0
    ctx->pc = 0x19af7cu;
    // NOP
    // 0x19af80: 0x27bdff40
    ctx->pc = 0x19af80u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x19af84: 0xffbf0040
    ctx->pc = 0x19af84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x19af88: 0x7fb30030
    ctx->pc = 0x19af88u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19af8c: 0x7fb20020
    ctx->pc = 0x19af8cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19af90: 0x80982d
    ctx->pc = 0x19af90u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19af94: 0x7fb10010
    ctx->pc = 0x19af94u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19af98: 0xa0902d
    ctx->pc = 0x19af98u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19af9c: 0xc0882d
    ctx->pc = 0x19af9cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19afa0: 0x240401b0
    ctx->pc = 0x19afa0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 432));
    // 0x19afa4: 0x24050010
    ctx->pc = 0x19afa4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    // 0x19afa8: 0xc063774
    ctx->pc = 0x19AFA8u;
    SET_GPR_U32(ctx, 31, 0x19AFB0u);
    ctx->pc = 0x19AFACu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19AFB0u; }
    }
    if (ctx->pc != 0x19AFB0u) { return; }
    ctx->pc = 0x19AFB0u;
    // 0x19afb0: 0x3c032000
    ctx->pc = 0x19afb0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x19afb4: 0x3c080029
    ctx->pc = 0x19afb4u;
    SET_GPR_U32(ctx, 8, ((uint32_t)41 << 16));
    // 0x19afb8: 0x3463001a
    ctx->pc = 0x19afb8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 26));
    // 0x19afbc: 0x3c061300
    ctx->pc = 0x19afbcu;
    SET_GPR_U32(ctx, 6, ((uint32_t)4864 << 16));
    // 0x19afc0: 0xac430000
    ctx->pc = 0x19afc0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x19afc4: 0x3c056c18
    ctx->pc = 0x19afc4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)27672 << 16));
    // 0x19afc8: 0xac510004
    ctx->pc = 0x19afc8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 17));
    // 0x19afcc: 0x3c030100
    ctx->pc = 0x19afccu;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x19afd0: 0xfc400008
    ctx->pc = 0x19afd0u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19afd4: 0x34640404
    ctx->pc = 0x19afd4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 1028));
    // 0x19afd8: 0xac460010
    ctx->pc = 0x19afd8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 6));
    // 0x19afdc: 0x3c033f80
    ctx->pc = 0x19afdcu;
    SET_GPR_U32(ctx, 3, ((uint32_t)16256 << 16));
    // 0x19afe0: 0xac400014
    ctx->pc = 0x19afe0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19afe4: 0x44830000
    ctx->pc = 0x19afe4u;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 3);
    // 0x19afe8: 0xac440018
    ctx->pc = 0x19afe8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 4));
    // 0x19afec: 0x40802d
    ctx->pc = 0x19afecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19aff0: 0xac45001c
    ctx->pc = 0x19aff0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 5));
    // 0x19aff4: 0x3c037000
    ctx->pc = 0x19aff4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19aff8: 0x8e69004c
    ctx->pc = 0x19aff8u;
    SET_GPR_U32(ctx, 9, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19affc: 0x3c010029
    ctx->pc = 0x19affcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b000: 0xc4224e50
    ctx->pc = 0x19b000u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b004: 0x34663700
    ctx->pc = 0x19b004u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 14080));
    // 0x19b008: 0x34673f40
    ctx->pc = 0x19b008u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19b00c: 0x26040040
    ctx->pc = 0x19b00cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 64));
    // 0x19b010: 0x27a50080
    ctx->pc = 0x19b010u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 128));
    // 0x19b014: 0x25084d40
    ctx->pc = 0x19b014u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19b018: 0xc5210024
    ctx->pc = 0x19b018u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 9), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b01c: 0x3c010029
    ctx->pc = 0x19b01cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b020: 0x46011042
    ctx->pc = 0x19b020u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b024: 0xe4410020
    ctx->pc = 0x19b024u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19b028: 0x8e63004c
    ctx->pc = 0x19b028u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19b02c: 0xc4224e54
    ctx->pc = 0x19b02cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b030: 0xc4610024
    ctx->pc = 0x19b030u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b034: 0x3c010029
    ctx->pc = 0x19b034u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b038: 0x46011042
    ctx->pc = 0x19b038u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b03c: 0xe4410024
    ctx->pc = 0x19b03cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19b040: 0x8e63004c
    ctx->pc = 0x19b040u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19b044: 0xc4224e58
    ctx->pc = 0x19b044u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b048: 0xc4610024
    ctx->pc = 0x19b048u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b04c: 0x3c010029
    ctx->pc = 0x19b04cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b050: 0x46011042
    ctx->pc = 0x19b050u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b054: 0xe4410028
    ctx->pc = 0x19b054u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19b058: 0xc4214e5c
    ctx->pc = 0x19b058u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b05c: 0xe441002c
    ctx->pc = 0x19b05cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19b060: 0x3c01002a
    ctx->pc = 0x19b060u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19b064: 0xc421fe40
    ctx->pc = 0x19b064u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b068: 0xe4410030
    ctx->pc = 0x19b068u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19b06c: 0x3c01002a
    ctx->pc = 0x19b06cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19b070: 0xc422fe40
    ctx->pc = 0x19b070u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b074: 0x3c01002a
    ctx->pc = 0x19b074u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19b078: 0xc421fe48
    ctx->pc = 0x19b078u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b07c: 0x46011041
    ctx->pc = 0x19b07cu;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19b080: 0x46010003
    ctx->pc = 0x19b080u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ ctx->f[0] = copysignf(INFINITY, ctx->f[0] * 0.0f); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19b084: 0xe4400034
    ctx->pc = 0x19b084u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19b088: 0xac400038
    ctx->pc = 0x19b088u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 56), GPR_U32(ctx, 0));
    // 0x19b08c: 0xc066500
    ctx->pc = 0x19B08Cu;
    SET_GPR_U32(ctx, 31, 0x19B094u);
    ctx->pc = 0x19B090u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 60), GPR_U32(ctx, 0));
    ctx->pc = 0x199400u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B094u; }
    }
    if (ctx->pc != 0x19B094u) { return; }
    ctx->pc = 0x19B094u;
    // 0x19b094: 0x3c060029
    ctx->pc = 0x19b094u;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x19b098: 0x26040080
    ctx->pc = 0x19b098u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 128));
    // 0x19b09c: 0xc0664e0
    ctx->pc = 0x19B09Cu;
    SET_GPR_U32(ctx, 31, 0x19B0A4u);
    ctx->pc = 0x19B0A0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19712));
    ctx->pc = 0x199380u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B0A4u; }
    }
    if (ctx->pc != 0x19B0A4u) { return; }
    ctx->pc = 0x19B0A4u;
    // 0x19b0a4: 0x3c060029
    ctx->pc = 0x19b0a4u;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x19b0a8: 0x260500c0
    ctx->pc = 0x19b0a8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 192));
    // 0x19b0ac: 0x24c64cc0
    ctx->pc = 0x19b0acu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19648));
    // 0x19b0b0: 0x24040008
    ctx->pc = 0x19b0b0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 8));
label_19b0b4:
    // 0x19b0b4: 0x8cc30000
    ctx->pc = 0x19b0b4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x19b0b8: 0x2484ffff
    ctx->pc = 0x19b0b8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x19b0bc: 0x8cc20004
    ctx->pc = 0x19b0bcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x19b0c0: 0xaca30000
    ctx->pc = 0x19b0c0u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x19b0c4: 0x24c60008
    ctx->pc = 0x19b0c4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 8));
    // 0x19b0c8: 0xaca20004
    ctx->pc = 0x19b0c8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x19b0cc: 0x1c80fff9
    ctx->pc = 0x19B0CCu;
    {
        const bool branch_taken_0x19b0cc = (GPR_S32(ctx, 4) > 0);
        ctx->pc = 0x19B0D0u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 8));
        if (branch_taken_0x19b0cc) {
            ctx->pc = 0x19B0B4u;
            goto label_19b0b4;
        }
    }
    ctx->pc = 0x19B0D4u;
    // 0x19b0d4: 0x3c010029
    ctx->pc = 0x19b0d4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b0d8: 0x3c023f80
    ctx->pc = 0x19b0d8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)16256 << 16));
    // 0x19b0dc: 0xc4214234
    ctx->pc = 0x19b0dcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b0e0: 0xafa2005c
    ctx->pc = 0x19b0e0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 2));
    // 0x19b0e4: 0xafa2006c
    ctx->pc = 0x19b0e4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 2));
    // 0x19b0e8: 0x26040100
    ctx->pc = 0x19b0e8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 256));
    // 0x19b0ec: 0xafa2007c
    ctx->pc = 0x19b0ecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 124), GPR_U32(ctx, 2));
    // 0x19b0f0: 0x26050130
    ctx->pc = 0x19b0f0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 304));
    // 0x19b0f4: 0x3c027000
    ctx->pc = 0x19b0f4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)28672 << 16));
    // 0x19b0f8: 0x27a70050
    ctx->pc = 0x19b0f8u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 29), 80));
    // 0x19b0fc: 0x34463700
    ctx->pc = 0x19b0fcu;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 2), 14080));
    // 0x19b100: 0x3c010029
    ctx->pc = 0x19b100u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b104: 0xc4204238
    ctx->pc = 0x19b104u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b108: 0x46000847
    ctx->pc = 0x19b108u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19b10c: 0xe7a10050
    ctx->pc = 0x19b10cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19b110: 0x3c010029
    ctx->pc = 0x19b110u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b114: 0xc424423c
    ctx->pc = 0x19b114u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x19b118: 0x46000147
    ctx->pc = 0x19b118u;
    ctx->f[5] = FPU_NEG_S(ctx->f[0]);
    // 0x19b11c: 0xe7a50054
    ctx->pc = 0x19b11cu;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19b120: 0x3c010029
    ctx->pc = 0x19b120u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b124: 0xc42342a8
    ctx->pc = 0x19b124u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17064)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19b128: 0x46002107
    ctx->pc = 0x19b128u;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x19b12c: 0xe7a40058
    ctx->pc = 0x19b12cu;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x19b130: 0x3c010029
    ctx->pc = 0x19b130u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b134: 0xc42242ac
    ctx->pc = 0x19b134u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17068)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b138: 0xe7a30060
    ctx->pc = 0x19b138u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x19b13c: 0x3c010029
    ctx->pc = 0x19b13cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b140: 0xc42142b0
    ctx->pc = 0x19b140u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17072)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b144: 0xe7a20064
    ctx->pc = 0x19b144u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x19b148: 0x3c010029
    ctx->pc = 0x19b148u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b14c: 0xc4204310
    ctx->pc = 0x19b14cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17168)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b150: 0xe7a10068
    ctx->pc = 0x19b150u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
    // 0x19b154: 0x3c010029
    ctx->pc = 0x19b154u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b158: 0xc4214314
    ctx->pc = 0x19b158u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17172)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b15c: 0xe7a00070
    ctx->pc = 0x19b15cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 112), bits); }
    // 0x19b160: 0x3c010029
    ctx->pc = 0x19b160u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b164: 0xc4204318
    ctx->pc = 0x19b164u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b168: 0xe7a10074
    ctx->pc = 0x19b168u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 116), bits); }
    // 0x19b16c: 0xc0665d0
    ctx->pc = 0x19B16Cu;
    SET_GPR_U32(ctx, 31, 0x19B174u);
    ctx->pc = 0x19B170u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 120), bits); }
    ctx->pc = 0x199740u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199740_0x199740(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B174u; }
    }
    if (ctx->pc != 0x19B174u) { return; }
    ctx->pc = 0x19B174u;
    // 0x19b174: 0x8e62004c
    ctx->pc = 0x19b174u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19b178: 0xc44c0024
    ctx->pc = 0x19b178u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19b17c: 0xc0666a4
    ctx->pc = 0x19B17Cu;
    SET_GPR_U32(ctx, 31, 0x19B184u);
    ctx->pc = 0x19B180u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 320));
    ctx->pc = 0x199A90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199A90_0x199a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B184u; }
    }
    if (ctx->pc != 0x19B184u) { return; }
    ctx->pc = 0x19B184u;
    // 0x19b184: 0x3c031500
    ctx->pc = 0x19b184u;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19b188: 0x200102d
    ctx->pc = 0x19b188u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b18c: 0x2431825
    ctx->pc = 0x19b18cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x19b190: 0xae0301a0
    ctx->pc = 0x19b190u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 416), GPR_U32(ctx, 3));
    // 0x19b194: 0xae0001a4
    ctx->pc = 0x19b194u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 420), GPR_U32(ctx, 0));
    // 0x19b198: 0xae0001a8
    ctx->pc = 0x19b198u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 424), GPR_U32(ctx, 0));
    // 0x19b19c: 0xae0001ac
    ctx->pc = 0x19b19cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 428), GPR_U32(ctx, 0));
    // 0x19b1a0: 0xdfbf0040
    ctx->pc = 0x19b1a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19b1a4: 0x7bb30030
    ctx->pc = 0x19b1a4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19b1a8: 0x7bb20020
    ctx->pc = 0x19b1a8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19b1ac: 0x7bb10010
    ctx->pc = 0x19b1acu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19b1b0: 0x7bb00000
    ctx->pc = 0x19b1b0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19b1b4: 0x3e00008
    ctx->pc = 0x19B1B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19B1B8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 192));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19B1BCu;
    // 0x19b1bc: 0x0
    ctx->pc = 0x19b1bcu;
    // NOP
    // 0x19b1c0: 0x27bdff90
    ctx->pc = 0x19b1c0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x19b1c4: 0xffbf0030
    ctx->pc = 0x19b1c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19b1c8: 0x7fb20020
    ctx->pc = 0x19b1c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19b1cc: 0x7fb10010
    ctx->pc = 0x19b1ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19b1d0: 0x80902d
    ctx->pc = 0x19b1d0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b1d4: 0x7fb00000
    ctx->pc = 0x19b1d4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19b1d8: 0xa0882d
    ctx->pc = 0x19b1d8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b1dc: 0xc0802d
    ctx->pc = 0x19b1dcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b1e0: 0x24040fb0
    ctx->pc = 0x19b1e0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4016));
    // 0x19b1e4: 0xc063774
    ctx->pc = 0x19B1E4u;
    SET_GPR_U32(ctx, 31, 0x19B1ECu);
    ctx->pc = 0x19B1E8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B1ECu; }
    }
    if (ctx->pc != 0x19B1ECu) { return; }
    ctx->pc = 0x19B1ECu;
    // 0x19b1ec: 0x3c032000
    ctx->pc = 0x19b1ecu;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x19b1f0: 0x3c070029
    ctx->pc = 0x19b1f0u;
    SET_GPR_U32(ctx, 7, ((uint32_t)41 << 16));
    // 0x19b1f4: 0x346400fa
    ctx->pc = 0x19b1f4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 250));
    // 0x19b1f8: 0x3c061300
    ctx->pc = 0x19b1f8u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4864 << 16));
    // 0x19b1fc: 0xac440000
    ctx->pc = 0x19b1fcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19b200: 0x3c030100
    ctx->pc = 0x19b200u;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x19b204: 0xac500004
    ctx->pc = 0x19b204u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19b208: 0x34650404
    ctx->pc = 0x19b208u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 3), 1028));
    // 0x19b20c: 0xfc400008
    ctx->pc = 0x19b20cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19b210: 0x3c033f80
    ctx->pc = 0x19b210u;
    SET_GPR_U32(ctx, 3, ((uint32_t)16256 << 16));
    // 0x19b214: 0xac460010
    ctx->pc = 0x19b214u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 6));
    // 0x19b218: 0x3c046cf8
    ctx->pc = 0x19b218u;
    SET_GPR_U32(ctx, 4, ((uint32_t)27896 << 16));
    // 0x19b21c: 0xac400014
    ctx->pc = 0x19b21cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19b220: 0x44830000
    ctx->pc = 0x19b220u;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 3);
    // 0x19b224: 0xac450018
    ctx->pc = 0x19b224u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 5));
    // 0x19b228: 0x3c010029
    ctx->pc = 0x19b228u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b22c: 0xac44001c
    ctx->pc = 0x19b22cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 4));
    // 0x19b230: 0x24e74d40
    ctx->pc = 0x19b230u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 19776));
    // 0x19b234: 0x8e43004c
    ctx->pc = 0x19b234u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19b238: 0xc4224e50
    ctx->pc = 0x19b238u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b23c: 0x24460040
    ctx->pc = 0x19b23cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 2), 64));
    // 0x19b240: 0x24050008
    ctx->pc = 0x19b240u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
    // 0x19b244: 0xc4610024
    ctx->pc = 0x19b244u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b248: 0x3c010029
    ctx->pc = 0x19b248u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b24c: 0x46011042
    ctx->pc = 0x19b24cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b250: 0xe4410020
    ctx->pc = 0x19b250u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19b254: 0x8e43004c
    ctx->pc = 0x19b254u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19b258: 0xc4224e54
    ctx->pc = 0x19b258u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b25c: 0xc4610024
    ctx->pc = 0x19b25cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b260: 0x3c010029
    ctx->pc = 0x19b260u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b264: 0x46011042
    ctx->pc = 0x19b264u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b268: 0xe4410024
    ctx->pc = 0x19b268u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19b26c: 0x8e43004c
    ctx->pc = 0x19b26cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19b270: 0xc4224e58
    ctx->pc = 0x19b270u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b274: 0xc4610024
    ctx->pc = 0x19b274u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b278: 0x3c010029
    ctx->pc = 0x19b278u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b27c: 0x46011042
    ctx->pc = 0x19b27cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b280: 0xe4410028
    ctx->pc = 0x19b280u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19b284: 0xc4214e5c
    ctx->pc = 0x19b284u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b288: 0xe441002c
    ctx->pc = 0x19b288u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19b28c: 0x3c01002a
    ctx->pc = 0x19b28cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19b290: 0xc421fe40
    ctx->pc = 0x19b290u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b294: 0xe4410030
    ctx->pc = 0x19b294u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19b298: 0x3c01002a
    ctx->pc = 0x19b298u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19b29c: 0xc422fe40
    ctx->pc = 0x19b29cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b2a0: 0x3c01002a
    ctx->pc = 0x19b2a0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19b2a4: 0xc421fe48
    ctx->pc = 0x19b2a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b2a8: 0x46011041
    ctx->pc = 0x19b2a8u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19b2ac: 0x46010003
    ctx->pc = 0x19b2acu;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ ctx->f[0] = copysignf(INFINITY, ctx->f[0] * 0.0f); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19b2b0: 0xe4400034
    ctx->pc = 0x19b2b0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19b2b4: 0xac400038
    ctx->pc = 0x19b2b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 56), GPR_U32(ctx, 0));
    // 0x19b2b8: 0xac40003c
    ctx->pc = 0x19b2b8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 60), GPR_U32(ctx, 0));
label_19b2bc:
    // 0x19b2bc: 0x8ce40000
    ctx->pc = 0x19b2bcu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19b2c0: 0x24a5ffff
    ctx->pc = 0x19b2c0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19b2c4: 0x8ce30004
    ctx->pc = 0x19b2c4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19b2c8: 0xacc40000
    ctx->pc = 0x19b2c8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19b2cc: 0x24e70008
    ctx->pc = 0x19b2ccu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 8));
    // 0x19b2d0: 0xacc30004
    ctx->pc = 0x19b2d0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19b2d4: 0x1ca0fff9
    ctx->pc = 0x19B2D4u;
    {
        const bool branch_taken_0x19b2d4 = (GPR_S32(ctx, 5) > 0);
        ctx->pc = 0x19B2D8u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 8));
        if (branch_taken_0x19b2d4) {
            ctx->pc = 0x19B2BCu;
            goto label_19b2bc;
        }
    }
    ctx->pc = 0x19B2DCu;
    // 0x19b2dc: 0x3c070029
    ctx->pc = 0x19b2dcu;
    SET_GPR_U32(ctx, 7, ((uint32_t)41 << 16));
    // 0x19b2e0: 0x24460080
    ctx->pc = 0x19b2e0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 2), 128));
    // 0x19b2e4: 0x24e74d00
    ctx->pc = 0x19b2e4u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 19712));
    // 0x19b2e8: 0x24050008
    ctx->pc = 0x19b2e8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
label_19b2ec:
    // 0x19b2ec: 0x8ce40000
    ctx->pc = 0x19b2ecu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19b2f0: 0x24a5ffff
    ctx->pc = 0x19b2f0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19b2f4: 0x8ce30004
    ctx->pc = 0x19b2f4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19b2f8: 0xacc40000
    ctx->pc = 0x19b2f8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19b2fc: 0x24e70008
    ctx->pc = 0x19b2fcu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 8));
    // 0x19b300: 0xacc30004
    ctx->pc = 0x19b300u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19b304: 0x1ca0fff9
    ctx->pc = 0x19B304u;
    {
        const bool branch_taken_0x19b304 = (GPR_S32(ctx, 5) > 0);
        ctx->pc = 0x19B308u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 8));
        if (branch_taken_0x19b304) {
            ctx->pc = 0x19B2ECu;
            goto label_19b2ec;
        }
    }
    ctx->pc = 0x19B30Cu;
    // 0x19b30c: 0x3c070029
    ctx->pc = 0x19b30cu;
    SET_GPR_U32(ctx, 7, ((uint32_t)41 << 16));
    // 0x19b310: 0x244600c0
    ctx->pc = 0x19b310u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 2), 192));
    // 0x19b314: 0x24e74cc0
    ctx->pc = 0x19b314u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 19648));
    // 0x19b318: 0x24050008
    ctx->pc = 0x19b318u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
label_19b31c:
    // 0x19b31c: 0x8ce40000
    ctx->pc = 0x19b31cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19b320: 0x24a5ffff
    ctx->pc = 0x19b320u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19b324: 0x8ce30004
    ctx->pc = 0x19b324u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19b328: 0xacc40000
    ctx->pc = 0x19b328u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19b32c: 0x24e70008
    ctx->pc = 0x19b32cu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 8));
    // 0x19b330: 0xacc30004
    ctx->pc = 0x19b330u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19b334: 0x1ca0fff9
    ctx->pc = 0x19B334u;
    {
        const bool branch_taken_0x19b334 = (GPR_S32(ctx, 5) > 0);
        ctx->pc = 0x19B338u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 8));
        if (branch_taken_0x19b334) {
            ctx->pc = 0x19B31Cu;
            goto label_19b31c;
        }
    }
    ctx->pc = 0x19B33Cu;
    // 0x19b33c: 0x402d
    ctx->pc = 0x19b33cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_19b340:
    // 0x19b340: 0x8e430054
    ctx->pc = 0x19b340u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 84)));
    // 0x19b344: 0x24040001
    ctx->pc = 0x19b344u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    // 0x19b348: 0x1042004
    ctx->pc = 0x19b348u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), GPR_U32(ctx, 8) & 0x1F));
    // 0x19b34c: 0x641824
    ctx->pc = 0x19b34cu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x19b350: 0x1060000e
    ctx->pc = 0x19B350u;
    {
        const bool branch_taken_0x19b350 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x19B354u;
        SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 8), 1));
        if (branch_taken_0x19b350) {
            ctx->pc = 0x19B38Cu;
            goto label_19b38c;
        }
    }
    ctx->pc = 0x19B358u;
    // 0x19b358: 0x3c017000
    ctx->pc = 0x19b358u;
    SET_GPR_U32(ctx, 1, ((uint32_t)28672 << 16));
    // 0x19b35c: 0x682021
    ctx->pc = 0x19b35cu;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x19b360: 0x83180
    ctx->pc = 0x19b360u;
    SET_GPR_U32(ctx, 6, SLL32(GPR_U32(ctx, 8), 6));
    // 0x19b364: 0x461821
    ctx->pc = 0x19b364u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x19b368: 0x34213700
    ctx->pc = 0x19b368u;
    SET_GPR_U32(ctx, 1, OR32(GPR_U32(ctx, 1), 14080));
    // 0x19b36c: 0x42100
    ctx->pc = 0x19b36cu;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 4));
    // 0x19b370: 0x246501a0
    ctx->pc = 0x19b370u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 3), 416));
    // 0x19b374: 0x441821
    ctx->pc = 0x19b374u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x19b378: 0xc13021
    ctx->pc = 0x19b378u;
    SET_GPR_U32(ctx, 6, ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 1)));
    // 0x19b37c: 0x246409a0
    ctx->pc = 0x19b37cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 3), 2464));
    // 0x19b380: 0x3c037000
    ctx->pc = 0x19b380u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19b384: 0xc066538
    ctx->pc = 0x19B384u;
    SET_GPR_U32(ctx, 31, 0x19B38Cu);
    ctx->pc = 0x19B388u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    ctx->pc = 0x1994E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001994E0_0x1994e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B38Cu; }
    }
    if (ctx->pc != 0x19B38Cu) { return; }
    ctx->pc = 0x19B38Cu;
label_19b38c:
    // 0x19b38c: 0x25080001
    ctx->pc = 0x19b38cu;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 1));
    // 0x19b390: 0x29030020
    ctx->pc = 0x19b390u;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 8), 32));
    // 0x19b394: 0x1460ffea
    ctx->pc = 0x19B394u;
    {
        const bool branch_taken_0x19b394 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x19B398u;
        SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
        if (branch_taken_0x19b394) {
            ctx->pc = 0x19B340u;
            goto label_19b340;
        }
    }
    ctx->pc = 0x19B39Cu;
    // 0x19b39c: 0x3c033f80
    ctx->pc = 0x19b39cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)16256 << 16));
    // 0x19b3a0: 0xc4214234
    ctx->pc = 0x19b3a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b3a4: 0xafa3004c
    ctx->pc = 0x19b3a4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 3));
    // 0x19b3a8: 0xafa3005c
    ctx->pc = 0x19b3a8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 3));
    // 0x19b3ac: 0x24440100
    ctx->pc = 0x19b3acu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 256));
    // 0x19b3b0: 0xafa3006c
    ctx->pc = 0x19b3b0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 3));
    // 0x19b3b4: 0x24450130
    ctx->pc = 0x19b3b4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 2), 304));
    // 0x19b3b8: 0x3c037000
    ctx->pc = 0x19b3b8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19b3bc: 0x27a70040
    ctx->pc = 0x19b3bcu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 29), 64));
    // 0x19b3c0: 0x34663f40
    ctx->pc = 0x19b3c0u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19b3c4: 0x3c010029
    ctx->pc = 0x19b3c4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b3c8: 0xc4204238
    ctx->pc = 0x19b3c8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b3cc: 0x46000847
    ctx->pc = 0x19b3ccu;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19b3d0: 0xe7a10040
    ctx->pc = 0x19b3d0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x19b3d4: 0x3c010029
    ctx->pc = 0x19b3d4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b3d8: 0xc424423c
    ctx->pc = 0x19b3d8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x19b3dc: 0x46000147
    ctx->pc = 0x19b3dcu;
    ctx->f[5] = FPU_NEG_S(ctx->f[0]);
    // 0x19b3e0: 0xe7a50044
    ctx->pc = 0x19b3e0u;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 68), bits); }
    // 0x19b3e4: 0x3c010029
    ctx->pc = 0x19b3e4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b3e8: 0xc42342a8
    ctx->pc = 0x19b3e8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17064)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19b3ec: 0x46002107
    ctx->pc = 0x19b3ecu;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x19b3f0: 0xe7a40048
    ctx->pc = 0x19b3f0u;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 72), bits); }
    // 0x19b3f4: 0x3c010029
    ctx->pc = 0x19b3f4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b3f8: 0xc42242ac
    ctx->pc = 0x19b3f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17068)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b3fc: 0xe7a30050
    ctx->pc = 0x19b3fcu;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19b400: 0x3c010029
    ctx->pc = 0x19b400u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b404: 0xc42142b0
    ctx->pc = 0x19b404u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17072)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b408: 0xe7a20054
    ctx->pc = 0x19b408u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19b40c: 0x3c010029
    ctx->pc = 0x19b40cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b410: 0xc4204310
    ctx->pc = 0x19b410u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17168)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b414: 0xe7a10058
    ctx->pc = 0x19b414u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x19b418: 0x3c010029
    ctx->pc = 0x19b418u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b41c: 0xc4214314
    ctx->pc = 0x19b41cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17172)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b420: 0xe7a00060
    ctx->pc = 0x19b420u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x19b424: 0x3c010029
    ctx->pc = 0x19b424u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b428: 0xc4204318
    ctx->pc = 0x19b428u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b42c: 0xe7a10064
    ctx->pc = 0x19b42cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x19b430: 0xc06661c
    ctx->pc = 0x19B430u;
    SET_GPR_U32(ctx, 31, 0x19B438u);
    ctx->pc = 0x19B434u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
    ctx->pc = 0x199870u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199870_0x199870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B438u; }
    }
    if (ctx->pc != 0x19B438u) { return; }
    ctx->pc = 0x19B438u;
    // 0x19b438: 0x8e43004c
    ctx->pc = 0x19b438u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19b43c: 0xc46c0024
    ctx->pc = 0x19b43cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19b440: 0xc0666a4
    ctx->pc = 0x19B440u;
    SET_GPR_U32(ctx, 31, 0x19B448u);
    ctx->pc = 0x19B444u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 320));
    ctx->pc = 0x199A90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199A90_0x199a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B448u; }
    }
    if (ctx->pc != 0x19B448u) { return; }
    ctx->pc = 0x19B448u;
    // 0x19b448: 0x3c031500
    ctx->pc = 0x19b448u;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19b44c: 0x2231825
    ctx->pc = 0x19b44cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x19b450: 0xac430fa0
    ctx->pc = 0x19b450u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4000), GPR_U32(ctx, 3));
    // 0x19b454: 0xac400fa4
    ctx->pc = 0x19b454u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4004), GPR_U32(ctx, 0));
    // 0x19b458: 0xac400fa8
    ctx->pc = 0x19b458u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4008), GPR_U32(ctx, 0));
    // 0x19b45c: 0xac400fac
    ctx->pc = 0x19b45cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4012), GPR_U32(ctx, 0));
    // 0x19b460: 0xdfbf0030
    ctx->pc = 0x19b460u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19b464: 0x7bb20020
    ctx->pc = 0x19b464u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19b468: 0x7bb10010
    ctx->pc = 0x19b468u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19b46c: 0x7bb00000
    ctx->pc = 0x19b46cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19b470: 0x3e00008
    ctx->pc = 0x19B470u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19B474u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 112));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19B478u;
    // 0x19b478: 0x0
    ctx->pc = 0x19b478u;
    // NOP
    // 0x19b47c: 0x0
    ctx->pc = 0x19b47cu;
    // NOP
    // 0x19b480: 0x27bdff40
    ctx->pc = 0x19b480u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x19b484: 0xffbf0040
    ctx->pc = 0x19b484u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x19b488: 0x7fb30030
    ctx->pc = 0x19b488u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19b48c: 0x7fb20020
    ctx->pc = 0x19b48cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19b490: 0x80982d
    ctx->pc = 0x19b490u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b494: 0x7fb10010
    ctx->pc = 0x19b494u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19b498: 0xa0902d
    ctx->pc = 0x19b498u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b49c: 0xc0882d
    ctx->pc = 0x19b49cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b4a0: 0x24040180
    ctx->pc = 0x19b4a0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 384));
    // 0x19b4a4: 0x24050010
    ctx->pc = 0x19b4a4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    // 0x19b4a8: 0xc063774
    ctx->pc = 0x19B4A8u;
    SET_GPR_U32(ctx, 31, 0x19B4B0u);
    ctx->pc = 0x19B4ACu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B4B0u; }
    }
    if (ctx->pc != 0x19B4B0u) { return; }
    ctx->pc = 0x19B4B0u;
    // 0x19b4b0: 0x3c032000
    ctx->pc = 0x19b4b0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x19b4b4: 0x3c080029
    ctx->pc = 0x19b4b4u;
    SET_GPR_U32(ctx, 8, ((uint32_t)41 << 16));
    // 0x19b4b8: 0x34630017
    ctx->pc = 0x19b4b8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 23));
    // 0x19b4bc: 0x3c061300
    ctx->pc = 0x19b4bcu;
    SET_GPR_U32(ctx, 6, ((uint32_t)4864 << 16));
    // 0x19b4c0: 0xac430000
    ctx->pc = 0x19b4c0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x19b4c4: 0x3c056c15
    ctx->pc = 0x19b4c4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)27669 << 16));
    // 0x19b4c8: 0xac510004
    ctx->pc = 0x19b4c8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 17));
    // 0x19b4cc: 0x3c030100
    ctx->pc = 0x19b4ccu;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x19b4d0: 0xfc400008
    ctx->pc = 0x19b4d0u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19b4d4: 0x34640404
    ctx->pc = 0x19b4d4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 1028));
    // 0x19b4d8: 0xac460010
    ctx->pc = 0x19b4d8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 6));
    // 0x19b4dc: 0x3c033f80
    ctx->pc = 0x19b4dcu;
    SET_GPR_U32(ctx, 3, ((uint32_t)16256 << 16));
    // 0x19b4e0: 0xac400014
    ctx->pc = 0x19b4e0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19b4e4: 0x44830000
    ctx->pc = 0x19b4e4u;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 3);
    // 0x19b4e8: 0xac440018
    ctx->pc = 0x19b4e8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 4));
    // 0x19b4ec: 0x40802d
    ctx->pc = 0x19b4ecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b4f0: 0xac45001c
    ctx->pc = 0x19b4f0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 5));
    // 0x19b4f4: 0x3c037000
    ctx->pc = 0x19b4f4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19b4f8: 0x8e69004c
    ctx->pc = 0x19b4f8u;
    SET_GPR_U32(ctx, 9, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19b4fc: 0x3c010029
    ctx->pc = 0x19b4fcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b500: 0xc4224e50
    ctx->pc = 0x19b500u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b504: 0x34663700
    ctx->pc = 0x19b504u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 14080));
    // 0x19b508: 0x34673f40
    ctx->pc = 0x19b508u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19b50c: 0x26040050
    ctx->pc = 0x19b50cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 80));
    // 0x19b510: 0x27a50080
    ctx->pc = 0x19b510u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 128));
    // 0x19b514: 0x25084d40
    ctx->pc = 0x19b514u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19b518: 0xc5210024
    ctx->pc = 0x19b518u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 9), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b51c: 0x3c010029
    ctx->pc = 0x19b51cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b520: 0x46011042
    ctx->pc = 0x19b520u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b524: 0xe4410020
    ctx->pc = 0x19b524u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19b528: 0x8e63004c
    ctx->pc = 0x19b528u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19b52c: 0xc4224e54
    ctx->pc = 0x19b52cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b530: 0xc4610024
    ctx->pc = 0x19b530u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b534: 0x3c010029
    ctx->pc = 0x19b534u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b538: 0x46011042
    ctx->pc = 0x19b538u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b53c: 0xe4410024
    ctx->pc = 0x19b53cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19b540: 0x8e63004c
    ctx->pc = 0x19b540u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19b544: 0xc4224e58
    ctx->pc = 0x19b544u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b548: 0xc4610024
    ctx->pc = 0x19b548u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b54c: 0x3c010029
    ctx->pc = 0x19b54cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b550: 0x46011042
    ctx->pc = 0x19b550u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b554: 0xe4410028
    ctx->pc = 0x19b554u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19b558: 0xc4214e5c
    ctx->pc = 0x19b558u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b55c: 0xe441002c
    ctx->pc = 0x19b55cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19b560: 0x3c010029
    ctx->pc = 0x19b560u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b564: 0xc4214e40
    ctx->pc = 0x19b564u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b568: 0xe4410030
    ctx->pc = 0x19b568u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19b56c: 0x3c010029
    ctx->pc = 0x19b56cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b570: 0xc4214e44
    ctx->pc = 0x19b570u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b574: 0xe4410034
    ctx->pc = 0x19b574u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19b578: 0x3c010029
    ctx->pc = 0x19b578u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b57c: 0xc4214e48
    ctx->pc = 0x19b57cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b580: 0xe4410038
    ctx->pc = 0x19b580u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19b584: 0x3c010029
    ctx->pc = 0x19b584u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b588: 0xc4214e4c
    ctx->pc = 0x19b588u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b58c: 0xe441003c
    ctx->pc = 0x19b58cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
    // 0x19b590: 0x3c01002a
    ctx->pc = 0x19b590u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19b594: 0xc421fe40
    ctx->pc = 0x19b594u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b598: 0xe4410040
    ctx->pc = 0x19b598u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 64), bits); }
    // 0x19b59c: 0x3c01002a
    ctx->pc = 0x19b59cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19b5a0: 0xc422fe40
    ctx->pc = 0x19b5a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b5a4: 0x3c01002a
    ctx->pc = 0x19b5a4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19b5a8: 0xc421fe48
    ctx->pc = 0x19b5a8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b5ac: 0x46011041
    ctx->pc = 0x19b5acu;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19b5b0: 0x46010003
    ctx->pc = 0x19b5b0u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ ctx->f[0] = copysignf(INFINITY, ctx->f[0] * 0.0f); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19b5b4: 0xe4400044
    ctx->pc = 0x19b5b4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 68), bits); }
    // 0x19b5b8: 0xac400048
    ctx->pc = 0x19b5b8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 72), GPR_U32(ctx, 0));
    // 0x19b5bc: 0xc066500
    ctx->pc = 0x19B5BCu;
    SET_GPR_U32(ctx, 31, 0x19B5C4u);
    ctx->pc = 0x19B5C0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 76), GPR_U32(ctx, 0));
    ctx->pc = 0x199400u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B5C4u; }
    }
    if (ctx->pc != 0x19B5C4u) { return; }
    ctx->pc = 0x19B5C4u;
    // 0x19b5c4: 0x3c060029
    ctx->pc = 0x19b5c4u;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x19b5c8: 0x26040090
    ctx->pc = 0x19b5c8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 144));
    // 0x19b5cc: 0xc0664e0
    ctx->pc = 0x19B5CCu;
    SET_GPR_U32(ctx, 31, 0x19B5D4u);
    ctx->pc = 0x19B5D0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19712));
    ctx->pc = 0x199380u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B5D4u; }
    }
    if (ctx->pc != 0x19B5D4u) { return; }
    ctx->pc = 0x19B5D4u;
    // 0x19b5d4: 0x3c010029
    ctx->pc = 0x19b5d4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b5d8: 0x3c023f80
    ctx->pc = 0x19b5d8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)16256 << 16));
    // 0x19b5dc: 0xc4214234
    ctx->pc = 0x19b5dcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b5e0: 0xafa2005c
    ctx->pc = 0x19b5e0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 2));
    // 0x19b5e4: 0xafa2006c
    ctx->pc = 0x19b5e4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 2));
    // 0x19b5e8: 0x260400d0
    ctx->pc = 0x19b5e8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 208));
    // 0x19b5ec: 0xafa2007c
    ctx->pc = 0x19b5ecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 124), GPR_U32(ctx, 2));
    // 0x19b5f0: 0x26050100
    ctx->pc = 0x19b5f0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 256));
    // 0x19b5f4: 0x3c027000
    ctx->pc = 0x19b5f4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)28672 << 16));
    // 0x19b5f8: 0x27a70050
    ctx->pc = 0x19b5f8u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 29), 80));
    // 0x19b5fc: 0x34463700
    ctx->pc = 0x19b5fcu;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 2), 14080));
    // 0x19b600: 0x3c010029
    ctx->pc = 0x19b600u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b604: 0xc4204238
    ctx->pc = 0x19b604u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b608: 0x46000847
    ctx->pc = 0x19b608u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19b60c: 0xe7a10050
    ctx->pc = 0x19b60cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19b610: 0x3c010029
    ctx->pc = 0x19b610u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b614: 0xc424423c
    ctx->pc = 0x19b614u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x19b618: 0x46000147
    ctx->pc = 0x19b618u;
    ctx->f[5] = FPU_NEG_S(ctx->f[0]);
    // 0x19b61c: 0xe7a50054
    ctx->pc = 0x19b61cu;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19b620: 0x3c010029
    ctx->pc = 0x19b620u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b624: 0xc42342a8
    ctx->pc = 0x19b624u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17064)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19b628: 0x46002107
    ctx->pc = 0x19b628u;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x19b62c: 0xe7a40058
    ctx->pc = 0x19b62cu;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x19b630: 0x3c010029
    ctx->pc = 0x19b630u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b634: 0xc42242ac
    ctx->pc = 0x19b634u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17068)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b638: 0xe7a30060
    ctx->pc = 0x19b638u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x19b63c: 0x3c010029
    ctx->pc = 0x19b63cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b640: 0xc42142b0
    ctx->pc = 0x19b640u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17072)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b644: 0xe7a20064
    ctx->pc = 0x19b644u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x19b648: 0x3c010029
    ctx->pc = 0x19b648u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b64c: 0xc4204310
    ctx->pc = 0x19b64cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17168)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b650: 0xe7a10068
    ctx->pc = 0x19b650u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
    // 0x19b654: 0x3c010029
    ctx->pc = 0x19b654u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b658: 0xc4214314
    ctx->pc = 0x19b658u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17172)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b65c: 0xe7a00070
    ctx->pc = 0x19b65cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 112), bits); }
    // 0x19b660: 0x3c010029
    ctx->pc = 0x19b660u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b664: 0xc4204318
    ctx->pc = 0x19b664u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b668: 0xe7a10074
    ctx->pc = 0x19b668u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 116), bits); }
    // 0x19b66c: 0xc0665d0
    ctx->pc = 0x19B66Cu;
    SET_GPR_U32(ctx, 31, 0x19B674u);
    ctx->pc = 0x19B670u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 120), bits); }
    ctx->pc = 0x199740u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199740_0x199740(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B674u; }
    }
    if (ctx->pc != 0x19B674u) { return; }
    ctx->pc = 0x19B674u;
    // 0x19b674: 0x8e62004c
    ctx->pc = 0x19b674u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19b678: 0xc44c0024
    ctx->pc = 0x19b678u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19b67c: 0xc0666a4
    ctx->pc = 0x19B67Cu;
    SET_GPR_U32(ctx, 31, 0x19B684u);
    ctx->pc = 0x19B680u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 272));
    ctx->pc = 0x199A90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199A90_0x199a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B684u; }
    }
    if (ctx->pc != 0x19B684u) { return; }
    ctx->pc = 0x19B684u;
    // 0x19b684: 0x3c031500
    ctx->pc = 0x19b684u;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19b688: 0x200102d
    ctx->pc = 0x19b688u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b68c: 0x2431825
    ctx->pc = 0x19b68cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x19b690: 0xae030170
    ctx->pc = 0x19b690u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 368), GPR_U32(ctx, 3));
    // 0x19b694: 0xae000174
    ctx->pc = 0x19b694u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 372), GPR_U32(ctx, 0));
    // 0x19b698: 0xae000178
    ctx->pc = 0x19b698u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 376), GPR_U32(ctx, 0));
    // 0x19b69c: 0xae00017c
    ctx->pc = 0x19b69cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 380), GPR_U32(ctx, 0));
    // 0x19b6a0: 0xdfbf0040
    ctx->pc = 0x19b6a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19b6a4: 0x7bb30030
    ctx->pc = 0x19b6a4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19b6a8: 0x7bb20020
    ctx->pc = 0x19b6a8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19b6ac: 0x7bb10010
    ctx->pc = 0x19b6acu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19b6b0: 0x7bb00000
    ctx->pc = 0x19b6b0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19b6b4: 0x3e00008
    ctx->pc = 0x19B6B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19B6B8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 192));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19B6BCu;
    // 0x19b6bc: 0x0
    ctx->pc = 0x19b6bcu;
    // NOP
    // 0x19b6c0: 0x27bdff90
    ctx->pc = 0x19b6c0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x19b6c4: 0xffbf0030
    ctx->pc = 0x19b6c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19b6c8: 0x7fb20020
    ctx->pc = 0x19b6c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19b6cc: 0x7fb10010
    ctx->pc = 0x19b6ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19b6d0: 0x80902d
    ctx->pc = 0x19b6d0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b6d4: 0x7fb00000
    ctx->pc = 0x19b6d4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19b6d8: 0xa0882d
    ctx->pc = 0x19b6d8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b6dc: 0xc0802d
    ctx->pc = 0x19b6dcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b6e0: 0x24040f80
    ctx->pc = 0x19b6e0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 3968));
    // 0x19b6e4: 0xc063774
    ctx->pc = 0x19B6E4u;
    SET_GPR_U32(ctx, 31, 0x19B6ECu);
    ctx->pc = 0x19B6E8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B6ECu; }
    }
    if (ctx->pc != 0x19B6ECu) { return; }
    ctx->pc = 0x19B6ECu;
    // 0x19b6ec: 0x3c032000
    ctx->pc = 0x19b6ecu;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x19b6f0: 0x3c070029
    ctx->pc = 0x19b6f0u;
    SET_GPR_U32(ctx, 7, ((uint32_t)41 << 16));
    // 0x19b6f4: 0x346400f7
    ctx->pc = 0x19b6f4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 247));
    // 0x19b6f8: 0x3c061300
    ctx->pc = 0x19b6f8u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4864 << 16));
    // 0x19b6fc: 0xac440000
    ctx->pc = 0x19b6fcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19b700: 0x3c030100
    ctx->pc = 0x19b700u;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x19b704: 0xac500004
    ctx->pc = 0x19b704u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19b708: 0x34650404
    ctx->pc = 0x19b708u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 3), 1028));
    // 0x19b70c: 0xfc400008
    ctx->pc = 0x19b70cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19b710: 0x3c033f80
    ctx->pc = 0x19b710u;
    SET_GPR_U32(ctx, 3, ((uint32_t)16256 << 16));
    // 0x19b714: 0xac460010
    ctx->pc = 0x19b714u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 6));
    // 0x19b718: 0x3c046cf5
    ctx->pc = 0x19b718u;
    SET_GPR_U32(ctx, 4, ((uint32_t)27893 << 16));
    // 0x19b71c: 0xac400014
    ctx->pc = 0x19b71cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19b720: 0x44830000
    ctx->pc = 0x19b720u;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 3);
    // 0x19b724: 0xac450018
    ctx->pc = 0x19b724u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 5));
    // 0x19b728: 0x3c010029
    ctx->pc = 0x19b728u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b72c: 0xac44001c
    ctx->pc = 0x19b72cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 4));
    // 0x19b730: 0x24e74d40
    ctx->pc = 0x19b730u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 19776));
    // 0x19b734: 0x8e43004c
    ctx->pc = 0x19b734u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19b738: 0xc4224e50
    ctx->pc = 0x19b738u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b73c: 0x24460050
    ctx->pc = 0x19b73cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 2), 80));
    // 0x19b740: 0x24050008
    ctx->pc = 0x19b740u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
    // 0x19b744: 0xc4610024
    ctx->pc = 0x19b744u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b748: 0x3c010029
    ctx->pc = 0x19b748u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b74c: 0x46011042
    ctx->pc = 0x19b74cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b750: 0xe4410020
    ctx->pc = 0x19b750u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19b754: 0x8e43004c
    ctx->pc = 0x19b754u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19b758: 0xc4224e54
    ctx->pc = 0x19b758u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b75c: 0xc4610024
    ctx->pc = 0x19b75cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b760: 0x3c010029
    ctx->pc = 0x19b760u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b764: 0x46011042
    ctx->pc = 0x19b764u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b768: 0xe4410024
    ctx->pc = 0x19b768u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19b76c: 0x8e43004c
    ctx->pc = 0x19b76cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19b770: 0xc4224e58
    ctx->pc = 0x19b770u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b774: 0xc4610024
    ctx->pc = 0x19b774u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b778: 0x3c010029
    ctx->pc = 0x19b778u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b77c: 0x46011042
    ctx->pc = 0x19b77cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19b780: 0xe4410028
    ctx->pc = 0x19b780u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19b784: 0xc4214e5c
    ctx->pc = 0x19b784u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b788: 0xe441002c
    ctx->pc = 0x19b788u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19b78c: 0x3c010029
    ctx->pc = 0x19b78cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b790: 0xc4214e40
    ctx->pc = 0x19b790u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b794: 0xe4410030
    ctx->pc = 0x19b794u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19b798: 0x3c010029
    ctx->pc = 0x19b798u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b79c: 0xc4214e44
    ctx->pc = 0x19b79cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b7a0: 0xe4410034
    ctx->pc = 0x19b7a0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19b7a4: 0x3c010029
    ctx->pc = 0x19b7a4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b7a8: 0xc4214e48
    ctx->pc = 0x19b7a8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b7ac: 0xe4410038
    ctx->pc = 0x19b7acu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19b7b0: 0x3c010029
    ctx->pc = 0x19b7b0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b7b4: 0xc4214e4c
    ctx->pc = 0x19b7b4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b7b8: 0xe441003c
    ctx->pc = 0x19b7b8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
    // 0x19b7bc: 0x3c01002a
    ctx->pc = 0x19b7bcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19b7c0: 0xc421fe40
    ctx->pc = 0x19b7c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b7c4: 0xe4410040
    ctx->pc = 0x19b7c4u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 64), bits); }
    // 0x19b7c8: 0x3c01002a
    ctx->pc = 0x19b7c8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19b7cc: 0xc422fe40
    ctx->pc = 0x19b7ccu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b7d0: 0x3c01002a
    ctx->pc = 0x19b7d0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19b7d4: 0xc421fe48
    ctx->pc = 0x19b7d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b7d8: 0x46011041
    ctx->pc = 0x19b7d8u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19b7dc: 0x46010003
    ctx->pc = 0x19b7dcu;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ ctx->f[0] = copysignf(INFINITY, ctx->f[0] * 0.0f); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19b7e0: 0xe4400044
    ctx->pc = 0x19b7e0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 68), bits); }
    // 0x19b7e4: 0xac400048
    ctx->pc = 0x19b7e4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 72), GPR_U32(ctx, 0));
    // 0x19b7e8: 0xac40004c
    ctx->pc = 0x19b7e8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 76), GPR_U32(ctx, 0));
label_19b7ec:
    // 0x19b7ec: 0x8ce40000
    ctx->pc = 0x19b7ecu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19b7f0: 0x24a5ffff
    ctx->pc = 0x19b7f0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19b7f4: 0x8ce30004
    ctx->pc = 0x19b7f4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19b7f8: 0xacc40000
    ctx->pc = 0x19b7f8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19b7fc: 0x24e70008
    ctx->pc = 0x19b7fcu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 8));
    // 0x19b800: 0xacc30004
    ctx->pc = 0x19b800u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19b804: 0x1ca0fff9
    ctx->pc = 0x19B804u;
    {
        const bool branch_taken_0x19b804 = (GPR_S32(ctx, 5) > 0);
        ctx->pc = 0x19B808u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 8));
        if (branch_taken_0x19b804) {
            ctx->pc = 0x19B7ECu;
            goto label_19b7ec;
        }
    }
    ctx->pc = 0x19B80Cu;
    // 0x19b80c: 0x3c070029
    ctx->pc = 0x19b80cu;
    SET_GPR_U32(ctx, 7, ((uint32_t)41 << 16));
    // 0x19b810: 0x24460090
    ctx->pc = 0x19b810u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 2), 144));
    // 0x19b814: 0x24e74d00
    ctx->pc = 0x19b814u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 19712));
    // 0x19b818: 0x24050008
    ctx->pc = 0x19b818u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
label_19b81c:
    // 0x19b81c: 0x8ce40000
    ctx->pc = 0x19b81cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19b820: 0x24a5ffff
    ctx->pc = 0x19b820u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19b824: 0x8ce30004
    ctx->pc = 0x19b824u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19b828: 0xacc40000
    ctx->pc = 0x19b828u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19b82c: 0x24e70008
    ctx->pc = 0x19b82cu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 8));
    // 0x19b830: 0xacc30004
    ctx->pc = 0x19b830u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19b834: 0x1ca0fff9
    ctx->pc = 0x19B834u;
    {
        const bool branch_taken_0x19b834 = (GPR_S32(ctx, 5) > 0);
        ctx->pc = 0x19B838u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 8));
        if (branch_taken_0x19b834) {
            ctx->pc = 0x19B81Cu;
            goto label_19b81c;
        }
    }
    ctx->pc = 0x19B83Cu;
    // 0x19b83c: 0x402d
    ctx->pc = 0x19b83cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_19b840:
    // 0x19b840: 0x8e430054
    ctx->pc = 0x19b840u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 84)));
    // 0x19b844: 0x24040001
    ctx->pc = 0x19b844u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    // 0x19b848: 0x1042004
    ctx->pc = 0x19b848u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), GPR_U32(ctx, 8) & 0x1F));
    // 0x19b84c: 0x641824
    ctx->pc = 0x19b84cu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x19b850: 0x1060000e
    ctx->pc = 0x19B850u;
    {
        const bool branch_taken_0x19b850 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x19B854u;
        SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 8), 1));
        if (branch_taken_0x19b850) {
            ctx->pc = 0x19B88Cu;
            goto label_19b88c;
        }
    }
    ctx->pc = 0x19B858u;
    // 0x19b858: 0x3c017000
    ctx->pc = 0x19b858u;
    SET_GPR_U32(ctx, 1, ((uint32_t)28672 << 16));
    // 0x19b85c: 0x682021
    ctx->pc = 0x19b85cu;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x19b860: 0x83180
    ctx->pc = 0x19b860u;
    SET_GPR_U32(ctx, 6, SLL32(GPR_U32(ctx, 8), 6));
    // 0x19b864: 0x461821
    ctx->pc = 0x19b864u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x19b868: 0x34213700
    ctx->pc = 0x19b868u;
    SET_GPR_U32(ctx, 1, OR32(GPR_U32(ctx, 1), 14080));
    // 0x19b86c: 0x42100
    ctx->pc = 0x19b86cu;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 4));
    // 0x19b870: 0x24650170
    ctx->pc = 0x19b870u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 3), 368));
    // 0x19b874: 0x441821
    ctx->pc = 0x19b874u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x19b878: 0xc13021
    ctx->pc = 0x19b878u;
    SET_GPR_U32(ctx, 6, ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 1)));
    // 0x19b87c: 0x24640970
    ctx->pc = 0x19b87cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 3), 2416));
    // 0x19b880: 0x3c037000
    ctx->pc = 0x19b880u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19b884: 0xc066538
    ctx->pc = 0x19B884u;
    SET_GPR_U32(ctx, 31, 0x19B88Cu);
    ctx->pc = 0x19B888u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    ctx->pc = 0x1994E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001994E0_0x1994e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B88Cu; }
    }
    if (ctx->pc != 0x19B88Cu) { return; }
    ctx->pc = 0x19B88Cu;
label_19b88c:
    // 0x19b88c: 0x25080001
    ctx->pc = 0x19b88cu;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 1));
    // 0x19b890: 0x29030020
    ctx->pc = 0x19b890u;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 8), 32));
    // 0x19b894: 0x1460ffea
    ctx->pc = 0x19B894u;
    {
        const bool branch_taken_0x19b894 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x19B898u;
        SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
        if (branch_taken_0x19b894) {
            ctx->pc = 0x19B840u;
            goto label_19b840;
        }
    }
    ctx->pc = 0x19B89Cu;
    // 0x19b89c: 0x3c033f80
    ctx->pc = 0x19b89cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)16256 << 16));
    // 0x19b8a0: 0xc4214234
    ctx->pc = 0x19b8a0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b8a4: 0xafa3004c
    ctx->pc = 0x19b8a4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 3));
    // 0x19b8a8: 0xafa3005c
    ctx->pc = 0x19b8a8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 3));
    // 0x19b8ac: 0x244400d0
    ctx->pc = 0x19b8acu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 208));
    // 0x19b8b0: 0xafa3006c
    ctx->pc = 0x19b8b0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 3));
    // 0x19b8b4: 0x24450100
    ctx->pc = 0x19b8b4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 2), 256));
    // 0x19b8b8: 0x3c037000
    ctx->pc = 0x19b8b8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19b8bc: 0x27a70040
    ctx->pc = 0x19b8bcu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 29), 64));
    // 0x19b8c0: 0x34663f40
    ctx->pc = 0x19b8c0u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19b8c4: 0x3c010029
    ctx->pc = 0x19b8c4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b8c8: 0xc4204238
    ctx->pc = 0x19b8c8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b8cc: 0x46000847
    ctx->pc = 0x19b8ccu;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19b8d0: 0xe7a10040
    ctx->pc = 0x19b8d0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x19b8d4: 0x3c010029
    ctx->pc = 0x19b8d4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b8d8: 0xc424423c
    ctx->pc = 0x19b8d8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x19b8dc: 0x46000147
    ctx->pc = 0x19b8dcu;
    ctx->f[5] = FPU_NEG_S(ctx->f[0]);
    // 0x19b8e0: 0xe7a50044
    ctx->pc = 0x19b8e0u;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 68), bits); }
    // 0x19b8e4: 0x3c010029
    ctx->pc = 0x19b8e4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b8e8: 0xc42342a8
    ctx->pc = 0x19b8e8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17064)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19b8ec: 0x46002107
    ctx->pc = 0x19b8ecu;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x19b8f0: 0xe7a40048
    ctx->pc = 0x19b8f0u;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 72), bits); }
    // 0x19b8f4: 0x3c010029
    ctx->pc = 0x19b8f4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b8f8: 0xc42242ac
    ctx->pc = 0x19b8f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17068)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19b8fc: 0xe7a30050
    ctx->pc = 0x19b8fcu;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19b900: 0x3c010029
    ctx->pc = 0x19b900u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b904: 0xc42142b0
    ctx->pc = 0x19b904u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17072)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b908: 0xe7a20054
    ctx->pc = 0x19b908u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19b90c: 0x3c010029
    ctx->pc = 0x19b90cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b910: 0xc4204310
    ctx->pc = 0x19b910u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17168)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b914: 0xe7a10058
    ctx->pc = 0x19b914u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x19b918: 0x3c010029
    ctx->pc = 0x19b918u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b91c: 0xc4214314
    ctx->pc = 0x19b91cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17172)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19b920: 0xe7a00060
    ctx->pc = 0x19b920u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x19b924: 0x3c010029
    ctx->pc = 0x19b924u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19b928: 0xc4204318
    ctx->pc = 0x19b928u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19b92c: 0xe7a10064
    ctx->pc = 0x19b92cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x19b930: 0xc06661c
    ctx->pc = 0x19B930u;
    SET_GPR_U32(ctx, 31, 0x19B938u);
    ctx->pc = 0x19B934u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
    ctx->pc = 0x199870u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199870_0x199870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B938u; }
    }
    if (ctx->pc != 0x19B938u) { return; }
    ctx->pc = 0x19B938u;
    // 0x19b938: 0x8e43004c
    ctx->pc = 0x19b938u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19b93c: 0xc46c0024
    ctx->pc = 0x19b93cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19b940: 0xc0666a4
    ctx->pc = 0x19B940u;
    SET_GPR_U32(ctx, 31, 0x19B948u);
    ctx->pc = 0x19B944u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 272));
    ctx->pc = 0x199A90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199A90_0x199a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B948u; }
    }
    if (ctx->pc != 0x19B948u) { return; }
    ctx->pc = 0x19B948u;
    // 0x19b948: 0x3c031500
    ctx->pc = 0x19b948u;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19b94c: 0x2231825
    ctx->pc = 0x19b94cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x19b950: 0xac430f70
    ctx->pc = 0x19b950u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3952), GPR_U32(ctx, 3));
    // 0x19b954: 0xac400f74
    ctx->pc = 0x19b954u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3956), GPR_U32(ctx, 0));
    // 0x19b958: 0xac400f78
    ctx->pc = 0x19b958u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3960), GPR_U32(ctx, 0));
    // 0x19b95c: 0xac400f7c
    ctx->pc = 0x19b95cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3964), GPR_U32(ctx, 0));
    // 0x19b960: 0xdfbf0030
    ctx->pc = 0x19b960u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19b964: 0x7bb20020
    ctx->pc = 0x19b964u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19b968: 0x7bb10010
    ctx->pc = 0x19b968u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19b96c: 0x7bb00000
    ctx->pc = 0x19b96cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19b970: 0x3e00008
    ctx->pc = 0x19B970u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19B974u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 112));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19B978u;
    // 0x19b978: 0x0
    ctx->pc = 0x19b978u;
    // NOP
    // 0x19b97c: 0x0
    ctx->pc = 0x19b97cu;
    // NOP
    // 0x19b980: 0x27bdff40
    ctx->pc = 0x19b980u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967104));
    // 0x19b984: 0xffbf0040
    ctx->pc = 0x19b984u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x19b988: 0x7fb30030
    ctx->pc = 0x19b988u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19b98c: 0x7fb20020
    ctx->pc = 0x19b98cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19b990: 0x80982d
    ctx->pc = 0x19b990u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b994: 0x7fb10010
    ctx->pc = 0x19b994u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19b998: 0xa0902d
    ctx->pc = 0x19b998u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b99c: 0xc0882d
    ctx->pc = 0x19b99cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b9a0: 0x240401b0
    ctx->pc = 0x19b9a0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 432));
    // 0x19b9a4: 0x24050010
    ctx->pc = 0x19b9a4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    // 0x19b9a8: 0xc063774
    ctx->pc = 0x19B9A8u;
    SET_GPR_U32(ctx, 31, 0x19B9B0u);
    ctx->pc = 0x19B9ACu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19B9B0u; }
    }
    if (ctx->pc != 0x19B9B0u) { return; }
    ctx->pc = 0x19B9B0u;
    // 0x19b9b0: 0x3c032000
    ctx->pc = 0x19b9b0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x19b9b4: 0x3c080029
    ctx->pc = 0x19b9b4u;
    SET_GPR_U32(ctx, 8, ((uint32_t)41 << 16));
    // 0x19b9b8: 0x3463001a
    ctx->pc = 0x19b9b8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 26));
    // 0x19b9bc: 0x3c061300
    ctx->pc = 0x19b9bcu;
    SET_GPR_U32(ctx, 6, ((uint32_t)4864 << 16));
    // 0x19b9c0: 0xac430000
    ctx->pc = 0x19b9c0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x19b9c4: 0x3c056c18
    ctx->pc = 0x19b9c4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)27672 << 16));
    // 0x19b9c8: 0xac510004
    ctx->pc = 0x19b9c8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 17));
    // 0x19b9cc: 0x3c030100
    ctx->pc = 0x19b9ccu;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x19b9d0: 0xfc400008
    ctx->pc = 0x19b9d0u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19b9d4: 0x34640404
    ctx->pc = 0x19b9d4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 1028));
    // 0x19b9d8: 0xac460010
    ctx->pc = 0x19b9d8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 6));
    // 0x19b9dc: 0x3c033f80
    ctx->pc = 0x19b9dcu;
    SET_GPR_U32(ctx, 3, ((uint32_t)16256 << 16));
    // 0x19b9e0: 0xac400014
    ctx->pc = 0x19b9e0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19b9e4: 0x44830000
    ctx->pc = 0x19b9e4u;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 3);
    // 0x19b9e8: 0xac440018
    ctx->pc = 0x19b9e8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 4));
    // 0x19b9ec: 0x40802d
    ctx->pc = 0x19b9ecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19b9f0: 0xac45001c
    ctx->pc = 0x19b9f0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 5));
    // 0x19b9f4: 0x3c037000
    ctx->pc = 0x19b9f4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19b9f8: 0x8e69004c
    ctx->pc = 0x19b9f8u;
    SET_GPR_U32(ctx, 9, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19b9fc: 0x3c010029
    ctx->pc = 0x19b9fcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ba00: 0xc4224e50
    ctx->pc = 0x19ba00u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19ba04: 0x34663700
    ctx->pc = 0x19ba04u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 14080));
    // 0x19ba08: 0x34673f40
    ctx->pc = 0x19ba08u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19ba0c: 0x26040050
    ctx->pc = 0x19ba0cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 80));
    // 0x19ba10: 0x27a50080
    ctx->pc = 0x19ba10u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 128));
    // 0x19ba14: 0x25084d40
    ctx->pc = 0x19ba14u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19ba18: 0xc5210024
    ctx->pc = 0x19ba18u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 9), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ba1c: 0x3c010029
    ctx->pc = 0x19ba1cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ba20: 0x46011042
    ctx->pc = 0x19ba20u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19ba24: 0xe4410020
    ctx->pc = 0x19ba24u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19ba28: 0x8e63004c
    ctx->pc = 0x19ba28u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19ba2c: 0xc4224e54
    ctx->pc = 0x19ba2cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19ba30: 0xc4610024
    ctx->pc = 0x19ba30u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ba34: 0x3c010029
    ctx->pc = 0x19ba34u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ba38: 0x46011042
    ctx->pc = 0x19ba38u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19ba3c: 0xe4410024
    ctx->pc = 0x19ba3cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19ba40: 0x8e63004c
    ctx->pc = 0x19ba40u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19ba44: 0xc4224e58
    ctx->pc = 0x19ba44u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19ba48: 0xc4610024
    ctx->pc = 0x19ba48u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ba4c: 0x3c010029
    ctx->pc = 0x19ba4cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ba50: 0x46011042
    ctx->pc = 0x19ba50u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19ba54: 0xe4410028
    ctx->pc = 0x19ba54u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19ba58: 0xc4214e5c
    ctx->pc = 0x19ba58u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ba5c: 0xe441002c
    ctx->pc = 0x19ba5cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19ba60: 0x3c010029
    ctx->pc = 0x19ba60u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ba64: 0xc4214e40
    ctx->pc = 0x19ba64u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ba68: 0xe4410030
    ctx->pc = 0x19ba68u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19ba6c: 0x3c010029
    ctx->pc = 0x19ba6cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ba70: 0xc4214e44
    ctx->pc = 0x19ba70u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ba74: 0xe4410034
    ctx->pc = 0x19ba74u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19ba78: 0x3c010029
    ctx->pc = 0x19ba78u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ba7c: 0xc4214e48
    ctx->pc = 0x19ba7cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ba80: 0xe4410038
    ctx->pc = 0x19ba80u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19ba84: 0x3c010029
    ctx->pc = 0x19ba84u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19ba88: 0xc4214e4c
    ctx->pc = 0x19ba88u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ba8c: 0xe441003c
    ctx->pc = 0x19ba8cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
    // 0x19ba90: 0x3c01002a
    ctx->pc = 0x19ba90u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19ba94: 0xc421fe40
    ctx->pc = 0x19ba94u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19ba98: 0xe4410040
    ctx->pc = 0x19ba98u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 64), bits); }
    // 0x19ba9c: 0x3c01002a
    ctx->pc = 0x19ba9cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19baa0: 0xc422fe40
    ctx->pc = 0x19baa0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19baa4: 0x3c01002a
    ctx->pc = 0x19baa4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19baa8: 0xc421fe48
    ctx->pc = 0x19baa8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19baac: 0x46011041
    ctx->pc = 0x19baacu;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19bab0: 0x46010003
    ctx->pc = 0x19bab0u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ ctx->f[0] = copysignf(INFINITY, ctx->f[0] * 0.0f); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19bab4: 0xe4400044
    ctx->pc = 0x19bab4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 68), bits); }
    // 0x19bab8: 0xac400048
    ctx->pc = 0x19bab8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 72), GPR_U32(ctx, 0));
    // 0x19babc: 0xc066500
    ctx->pc = 0x19BABCu;
    SET_GPR_U32(ctx, 31, 0x19BAC4u);
    ctx->pc = 0x19BAC0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 76), GPR_U32(ctx, 0));
    ctx->pc = 0x199400u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BAC4u; }
    }
    if (ctx->pc != 0x19BAC4u) { return; }
    ctx->pc = 0x19BAC4u;
    // 0x19bac4: 0x3c060029
    ctx->pc = 0x19bac4u;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x19bac8: 0x26040090
    ctx->pc = 0x19bac8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 144));
    // 0x19bacc: 0xc0664e0
    ctx->pc = 0x19BACCu;
    SET_GPR_U32(ctx, 31, 0x19BAD4u);
    ctx->pc = 0x19BAD0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19712));
    ctx->pc = 0x199380u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BAD4u; }
    }
    if (ctx->pc != 0x19BAD4u) { return; }
    ctx->pc = 0x19BAD4u;
    // 0x19bad4: 0xc066734
    ctx->pc = 0x19BAD4u;
    SET_GPR_U32(ctx, 31, 0x19BADCu);
    ctx->pc = 0x19BAD8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 208));
    ctx->pc = 0x199CD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BADCu; }
    }
    if (ctx->pc != 0x19BADCu) { return; }
    ctx->pc = 0x19BADCu;
    // 0x19badc: 0x3c010029
    ctx->pc = 0x19badcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bae0: 0x3c023f80
    ctx->pc = 0x19bae0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)16256 << 16));
    // 0x19bae4: 0xc4214234
    ctx->pc = 0x19bae4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bae8: 0xafa2005c
    ctx->pc = 0x19bae8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 2));
    // 0x19baec: 0xafa2006c
    ctx->pc = 0x19baecu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 2));
    // 0x19baf0: 0x26040100
    ctx->pc = 0x19baf0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 256));
    // 0x19baf4: 0xafa2007c
    ctx->pc = 0x19baf4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 124), GPR_U32(ctx, 2));
    // 0x19baf8: 0x26050130
    ctx->pc = 0x19baf8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 304));
    // 0x19bafc: 0x3c027000
    ctx->pc = 0x19bafcu;
    SET_GPR_U32(ctx, 2, ((uint32_t)28672 << 16));
    // 0x19bb00: 0x27a70050
    ctx->pc = 0x19bb00u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 29), 80));
    // 0x19bb04: 0x34463700
    ctx->pc = 0x19bb04u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 2), 14080));
    // 0x19bb08: 0x3c010029
    ctx->pc = 0x19bb08u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bb0c: 0xc4204238
    ctx->pc = 0x19bb0cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19bb10: 0x46000847
    ctx->pc = 0x19bb10u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19bb14: 0xe7a10050
    ctx->pc = 0x19bb14u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19bb18: 0x3c010029
    ctx->pc = 0x19bb18u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bb1c: 0xc424423c
    ctx->pc = 0x19bb1cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x19bb20: 0x46000147
    ctx->pc = 0x19bb20u;
    ctx->f[5] = FPU_NEG_S(ctx->f[0]);
    // 0x19bb24: 0xe7a50054
    ctx->pc = 0x19bb24u;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19bb28: 0x3c010029
    ctx->pc = 0x19bb28u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bb2c: 0xc42342a8
    ctx->pc = 0x19bb2cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17064)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19bb30: 0x46002107
    ctx->pc = 0x19bb30u;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x19bb34: 0xe7a40058
    ctx->pc = 0x19bb34u;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x19bb38: 0x3c010029
    ctx->pc = 0x19bb38u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bb3c: 0xc42242ac
    ctx->pc = 0x19bb3cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17068)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19bb40: 0xe7a30060
    ctx->pc = 0x19bb40u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x19bb44: 0x3c010029
    ctx->pc = 0x19bb44u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bb48: 0xc42142b0
    ctx->pc = 0x19bb48u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17072)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bb4c: 0xe7a20064
    ctx->pc = 0x19bb4cu;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x19bb50: 0x3c010029
    ctx->pc = 0x19bb50u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bb54: 0xc4204310
    ctx->pc = 0x19bb54u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17168)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19bb58: 0xe7a10068
    ctx->pc = 0x19bb58u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
    // 0x19bb5c: 0x3c010029
    ctx->pc = 0x19bb5cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bb60: 0xc4214314
    ctx->pc = 0x19bb60u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17172)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bb64: 0xe7a00070
    ctx->pc = 0x19bb64u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 112), bits); }
    // 0x19bb68: 0x3c010029
    ctx->pc = 0x19bb68u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bb6c: 0xc4204318
    ctx->pc = 0x19bb6cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19bb70: 0xe7a10074
    ctx->pc = 0x19bb70u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 116), bits); }
    // 0x19bb74: 0xc0665d0
    ctx->pc = 0x19BB74u;
    SET_GPR_U32(ctx, 31, 0x19BB7Cu);
    ctx->pc = 0x19BB78u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 120), bits); }
    ctx->pc = 0x199740u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199740_0x199740(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BB7Cu; }
    }
    if (ctx->pc != 0x19BB7Cu) { return; }
    ctx->pc = 0x19BB7Cu;
    // 0x19bb7c: 0x8e62004c
    ctx->pc = 0x19bb7cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19bb80: 0xc44c0024
    ctx->pc = 0x19bb80u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19bb84: 0xc0666a4
    ctx->pc = 0x19BB84u;
    SET_GPR_U32(ctx, 31, 0x19BB8Cu);
    ctx->pc = 0x19BB88u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 320));
    ctx->pc = 0x199A90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199A90_0x199a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BB8Cu; }
    }
    if (ctx->pc != 0x19BB8Cu) { return; }
    ctx->pc = 0x19BB8Cu;
    // 0x19bb8c: 0x3c031500
    ctx->pc = 0x19bb8cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19bb90: 0x200102d
    ctx->pc = 0x19bb90u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19bb94: 0x2431825
    ctx->pc = 0x19bb94u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x19bb98: 0xae0301a0
    ctx->pc = 0x19bb98u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 416), GPR_U32(ctx, 3));
    // 0x19bb9c: 0xae0001a4
    ctx->pc = 0x19bb9cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 420), GPR_U32(ctx, 0));
    // 0x19bba0: 0xae0001a8
    ctx->pc = 0x19bba0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 424), GPR_U32(ctx, 0));
    // 0x19bba4: 0xae0001ac
    ctx->pc = 0x19bba4u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 428), GPR_U32(ctx, 0));
    // 0x19bba8: 0xdfbf0040
    ctx->pc = 0x19bba8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19bbac: 0x7bb30030
    ctx->pc = 0x19bbacu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19bbb0: 0x7bb20020
    ctx->pc = 0x19bbb0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19bbb4: 0x7bb10010
    ctx->pc = 0x19bbb4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19bbb8: 0x7bb00000
    ctx->pc = 0x19bbb8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19bbbc: 0x3e00008
    ctx->pc = 0x19BBBCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19BBC0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 192));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19BBC4u;
    // 0x19bbc4: 0x0
    ctx->pc = 0x19bbc4u;
    // NOP
    // 0x19bbc8: 0x0
    ctx->pc = 0x19bbc8u;
    // NOP
    // 0x19bbcc: 0x0
    ctx->pc = 0x19bbccu;
    // NOP
    // 0x19bbd0: 0x27bdff90
    ctx->pc = 0x19bbd0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x19bbd4: 0xffbf0030
    ctx->pc = 0x19bbd4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19bbd8: 0x7fb20020
    ctx->pc = 0x19bbd8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19bbdc: 0x7fb10010
    ctx->pc = 0x19bbdcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19bbe0: 0x80902d
    ctx->pc = 0x19bbe0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19bbe4: 0x7fb00000
    ctx->pc = 0x19bbe4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19bbe8: 0xa0882d
    ctx->pc = 0x19bbe8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19bbec: 0xc0802d
    ctx->pc = 0x19bbecu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19bbf0: 0x24040fb0
    ctx->pc = 0x19bbf0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4016));
    // 0x19bbf4: 0xc063774
    ctx->pc = 0x19BBF4u;
    SET_GPR_U32(ctx, 31, 0x19BBFCu);
    ctx->pc = 0x19BBF8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BBFCu; }
    }
    if (ctx->pc != 0x19BBFCu) { return; }
    ctx->pc = 0x19BBFCu;
    // 0x19bbfc: 0x3c032000
    ctx->pc = 0x19bbfcu;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x19bc00: 0x3c070029
    ctx->pc = 0x19bc00u;
    SET_GPR_U32(ctx, 7, ((uint32_t)41 << 16));
    // 0x19bc04: 0x346400fa
    ctx->pc = 0x19bc04u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 250));
    // 0x19bc08: 0x3c061300
    ctx->pc = 0x19bc08u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4864 << 16));
    // 0x19bc0c: 0xac440000
    ctx->pc = 0x19bc0cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19bc10: 0x3c030100
    ctx->pc = 0x19bc10u;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x19bc14: 0xac500004
    ctx->pc = 0x19bc14u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19bc18: 0x34650404
    ctx->pc = 0x19bc18u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 3), 1028));
    // 0x19bc1c: 0xfc400008
    ctx->pc = 0x19bc1cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19bc20: 0x3c033f80
    ctx->pc = 0x19bc20u;
    SET_GPR_U32(ctx, 3, ((uint32_t)16256 << 16));
    // 0x19bc24: 0xac460010
    ctx->pc = 0x19bc24u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 6));
    // 0x19bc28: 0x3c046cf8
    ctx->pc = 0x19bc28u;
    SET_GPR_U32(ctx, 4, ((uint32_t)27896 << 16));
    // 0x19bc2c: 0xac400014
    ctx->pc = 0x19bc2cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19bc30: 0x44830000
    ctx->pc = 0x19bc30u;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 3);
    // 0x19bc34: 0xac450018
    ctx->pc = 0x19bc34u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 5));
    // 0x19bc38: 0x3c010029
    ctx->pc = 0x19bc38u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bc3c: 0xac44001c
    ctx->pc = 0x19bc3cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 4));
    // 0x19bc40: 0x24e74d40
    ctx->pc = 0x19bc40u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 19776));
    // 0x19bc44: 0x8e43004c
    ctx->pc = 0x19bc44u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19bc48: 0xc4224e50
    ctx->pc = 0x19bc48u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19bc4c: 0x24460050
    ctx->pc = 0x19bc4cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 2), 80));
    // 0x19bc50: 0x24050008
    ctx->pc = 0x19bc50u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
    // 0x19bc54: 0xc4610024
    ctx->pc = 0x19bc54u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bc58: 0x3c010029
    ctx->pc = 0x19bc58u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bc5c: 0x46011042
    ctx->pc = 0x19bc5cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19bc60: 0xe4410020
    ctx->pc = 0x19bc60u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19bc64: 0x8e43004c
    ctx->pc = 0x19bc64u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19bc68: 0xc4224e54
    ctx->pc = 0x19bc68u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19bc6c: 0xc4610024
    ctx->pc = 0x19bc6cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bc70: 0x3c010029
    ctx->pc = 0x19bc70u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bc74: 0x46011042
    ctx->pc = 0x19bc74u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19bc78: 0xe4410024
    ctx->pc = 0x19bc78u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19bc7c: 0x8e43004c
    ctx->pc = 0x19bc7cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19bc80: 0xc4224e58
    ctx->pc = 0x19bc80u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19bc84: 0xc4610024
    ctx->pc = 0x19bc84u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bc88: 0x3c010029
    ctx->pc = 0x19bc88u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bc8c: 0x46011042
    ctx->pc = 0x19bc8cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19bc90: 0xe4410028
    ctx->pc = 0x19bc90u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19bc94: 0xc4214e5c
    ctx->pc = 0x19bc94u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bc98: 0xe441002c
    ctx->pc = 0x19bc98u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19bc9c: 0x3c010029
    ctx->pc = 0x19bc9cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bca0: 0xc4214e40
    ctx->pc = 0x19bca0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bca4: 0xe4410030
    ctx->pc = 0x19bca4u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19bca8: 0x3c010029
    ctx->pc = 0x19bca8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bcac: 0xc4214e44
    ctx->pc = 0x19bcacu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bcb0: 0xe4410034
    ctx->pc = 0x19bcb0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19bcb4: 0x3c010029
    ctx->pc = 0x19bcb4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bcb8: 0xc4214e48
    ctx->pc = 0x19bcb8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bcbc: 0xe4410038
    ctx->pc = 0x19bcbcu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19bcc0: 0x3c010029
    ctx->pc = 0x19bcc0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bcc4: 0xc4214e4c
    ctx->pc = 0x19bcc4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bcc8: 0xe441003c
    ctx->pc = 0x19bcc8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
    // 0x19bccc: 0x3c01002a
    ctx->pc = 0x19bcccu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19bcd0: 0xc421fe40
    ctx->pc = 0x19bcd0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bcd4: 0xe4410040
    ctx->pc = 0x19bcd4u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 64), bits); }
    // 0x19bcd8: 0x3c01002a
    ctx->pc = 0x19bcd8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19bcdc: 0xc422fe40
    ctx->pc = 0x19bcdcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19bce0: 0x3c01002a
    ctx->pc = 0x19bce0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19bce4: 0xc421fe48
    ctx->pc = 0x19bce4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bce8: 0x46011041
    ctx->pc = 0x19bce8u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19bcec: 0x46010003
    ctx->pc = 0x19bcecu;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ ctx->f[0] = copysignf(INFINITY, ctx->f[0] * 0.0f); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19bcf0: 0xe4400044
    ctx->pc = 0x19bcf0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 68), bits); }
    // 0x19bcf4: 0xac400048
    ctx->pc = 0x19bcf4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 72), GPR_U32(ctx, 0));
    // 0x19bcf8: 0xac40004c
    ctx->pc = 0x19bcf8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 76), GPR_U32(ctx, 0));
label_19bcfc:
    // 0x19bcfc: 0x8ce40000
    ctx->pc = 0x19bcfcu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19bd00: 0x24a5ffff
    ctx->pc = 0x19bd00u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19bd04: 0x8ce30004
    ctx->pc = 0x19bd04u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19bd08: 0xacc40000
    ctx->pc = 0x19bd08u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19bd0c: 0x24e70008
    ctx->pc = 0x19bd0cu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 8));
    // 0x19bd10: 0xacc30004
    ctx->pc = 0x19bd10u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19bd14: 0x1ca0fff9
    ctx->pc = 0x19BD14u;
    {
        const bool branch_taken_0x19bd14 = (GPR_S32(ctx, 5) > 0);
        ctx->pc = 0x19BD18u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 8));
        if (branch_taken_0x19bd14) {
            ctx->pc = 0x19BCFCu;
            goto label_19bcfc;
        }
    }
    ctx->pc = 0x19BD1Cu;
    // 0x19bd1c: 0x3c070029
    ctx->pc = 0x19bd1cu;
    SET_GPR_U32(ctx, 7, ((uint32_t)41 << 16));
    // 0x19bd20: 0x24460090
    ctx->pc = 0x19bd20u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 2), 144));
    // 0x19bd24: 0x24e74d00
    ctx->pc = 0x19bd24u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 19712));
    // 0x19bd28: 0x24050008
    ctx->pc = 0x19bd28u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
label_19bd2c:
    // 0x19bd2c: 0x8ce40000
    ctx->pc = 0x19bd2cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19bd30: 0x24a5ffff
    ctx->pc = 0x19bd30u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19bd34: 0x8ce30004
    ctx->pc = 0x19bd34u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19bd38: 0xacc40000
    ctx->pc = 0x19bd38u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19bd3c: 0x24e70008
    ctx->pc = 0x19bd3cu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 8));
    // 0x19bd40: 0xacc30004
    ctx->pc = 0x19bd40u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19bd44: 0x1ca0fff9
    ctx->pc = 0x19BD44u;
    {
        const bool branch_taken_0x19bd44 = (GPR_S32(ctx, 5) > 0);
        ctx->pc = 0x19BD48u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 8));
        if (branch_taken_0x19bd44) {
            ctx->pc = 0x19BD2Cu;
            goto label_19bd2c;
        }
    }
    ctx->pc = 0x19BD4Cu;
    // 0x19bd4c: 0x402d
    ctx->pc = 0x19bd4cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_19bd50:
    // 0x19bd50: 0x8e430054
    ctx->pc = 0x19bd50u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 84)));
    // 0x19bd54: 0x24040001
    ctx->pc = 0x19bd54u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    // 0x19bd58: 0x1042004
    ctx->pc = 0x19bd58u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), GPR_U32(ctx, 8) & 0x1F));
    // 0x19bd5c: 0x641824
    ctx->pc = 0x19bd5cu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x19bd60: 0x1060000e
    ctx->pc = 0x19BD60u;
    {
        const bool branch_taken_0x19bd60 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x19BD64u;
        SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 8), 1));
        if (branch_taken_0x19bd60) {
            ctx->pc = 0x19BD9Cu;
            goto label_19bd9c;
        }
    }
    ctx->pc = 0x19BD68u;
    // 0x19bd68: 0x3c017000
    ctx->pc = 0x19bd68u;
    SET_GPR_U32(ctx, 1, ((uint32_t)28672 << 16));
    // 0x19bd6c: 0x682021
    ctx->pc = 0x19bd6cu;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x19bd70: 0x83180
    ctx->pc = 0x19bd70u;
    SET_GPR_U32(ctx, 6, SLL32(GPR_U32(ctx, 8), 6));
    // 0x19bd74: 0x461821
    ctx->pc = 0x19bd74u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x19bd78: 0x34213700
    ctx->pc = 0x19bd78u;
    SET_GPR_U32(ctx, 1, OR32(GPR_U32(ctx, 1), 14080));
    // 0x19bd7c: 0x42100
    ctx->pc = 0x19bd7cu;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 4));
    // 0x19bd80: 0x246501a0
    ctx->pc = 0x19bd80u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 3), 416));
    // 0x19bd84: 0x441821
    ctx->pc = 0x19bd84u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x19bd88: 0xc13021
    ctx->pc = 0x19bd88u;
    SET_GPR_U32(ctx, 6, ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 1)));
    // 0x19bd8c: 0x246409a0
    ctx->pc = 0x19bd8cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 3), 2464));
    // 0x19bd90: 0x3c037000
    ctx->pc = 0x19bd90u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19bd94: 0xc066538
    ctx->pc = 0x19BD94u;
    SET_GPR_U32(ctx, 31, 0x19BD9Cu);
    ctx->pc = 0x19BD98u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    ctx->pc = 0x1994E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001994E0_0x1994e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BD9Cu; }
    }
    if (ctx->pc != 0x19BD9Cu) { return; }
    ctx->pc = 0x19BD9Cu;
label_19bd9c:
    // 0x19bd9c: 0x25080001
    ctx->pc = 0x19bd9cu;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 1));
    // 0x19bda0: 0x29030020
    ctx->pc = 0x19bda0u;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 8), 32));
    // 0x19bda4: 0x1460ffea
    ctx->pc = 0x19BDA4u;
    {
        const bool branch_taken_0x19bda4 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x19BDA8u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 208));
        if (branch_taken_0x19bda4) {
            ctx->pc = 0x19BD50u;
            goto label_19bd50;
        }
    }
    ctx->pc = 0x19BDACu;
    // 0x19bdac: 0xc066734
    ctx->pc = 0x19BDACu;
    SET_GPR_U32(ctx, 31, 0x19BDB4u);
    ctx->pc = 0x199CD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BDB4u; }
    }
    if (ctx->pc != 0x19BDB4u) { return; }
    ctx->pc = 0x19BDB4u;
    // 0x19bdb4: 0x3c010029
    ctx->pc = 0x19bdb4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bdb8: 0x3c033f80
    ctx->pc = 0x19bdb8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)16256 << 16));
    // 0x19bdbc: 0xc4214234
    ctx->pc = 0x19bdbcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bdc0: 0xafa3004c
    ctx->pc = 0x19bdc0u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 3));
    // 0x19bdc4: 0xafa3005c
    ctx->pc = 0x19bdc4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 3));
    // 0x19bdc8: 0x24440100
    ctx->pc = 0x19bdc8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 256));
    // 0x19bdcc: 0xafa3006c
    ctx->pc = 0x19bdccu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 3));
    // 0x19bdd0: 0x24450130
    ctx->pc = 0x19bdd0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 2), 304));
    // 0x19bdd4: 0x3c037000
    ctx->pc = 0x19bdd4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19bdd8: 0x27a70040
    ctx->pc = 0x19bdd8u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 29), 64));
    // 0x19bddc: 0x34663f40
    ctx->pc = 0x19bddcu;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19bde0: 0x3c010029
    ctx->pc = 0x19bde0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bde4: 0xc4204238
    ctx->pc = 0x19bde4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19bde8: 0x46000847
    ctx->pc = 0x19bde8u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19bdec: 0xe7a10040
    ctx->pc = 0x19bdecu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x19bdf0: 0x3c010029
    ctx->pc = 0x19bdf0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bdf4: 0xc424423c
    ctx->pc = 0x19bdf4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x19bdf8: 0x46000147
    ctx->pc = 0x19bdf8u;
    ctx->f[5] = FPU_NEG_S(ctx->f[0]);
    // 0x19bdfc: 0xe7a50044
    ctx->pc = 0x19bdfcu;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 68), bits); }
    // 0x19be00: 0x3c010029
    ctx->pc = 0x19be00u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19be04: 0xc42342a8
    ctx->pc = 0x19be04u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17064)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19be08: 0x46002107
    ctx->pc = 0x19be08u;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x19be0c: 0xe7a40048
    ctx->pc = 0x19be0cu;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 72), bits); }
    // 0x19be10: 0x3c010029
    ctx->pc = 0x19be10u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19be14: 0xc42242ac
    ctx->pc = 0x19be14u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17068)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19be18: 0xe7a30050
    ctx->pc = 0x19be18u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19be1c: 0x3c010029
    ctx->pc = 0x19be1cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19be20: 0xc42142b0
    ctx->pc = 0x19be20u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17072)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19be24: 0xe7a20054
    ctx->pc = 0x19be24u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19be28: 0x3c010029
    ctx->pc = 0x19be28u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19be2c: 0xc4204310
    ctx->pc = 0x19be2cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17168)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19be30: 0xe7a10058
    ctx->pc = 0x19be30u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x19be34: 0x3c010029
    ctx->pc = 0x19be34u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19be38: 0xc4214314
    ctx->pc = 0x19be38u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17172)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19be3c: 0xe7a00060
    ctx->pc = 0x19be3cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x19be40: 0x3c010029
    ctx->pc = 0x19be40u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19be44: 0xc4204318
    ctx->pc = 0x19be44u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19be48: 0xe7a10064
    ctx->pc = 0x19be48u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x19be4c: 0xc06661c
    ctx->pc = 0x19BE4Cu;
    SET_GPR_U32(ctx, 31, 0x19BE54u);
    ctx->pc = 0x19BE50u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
    ctx->pc = 0x199870u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199870_0x199870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BE54u; }
    }
    if (ctx->pc != 0x19BE54u) { return; }
    ctx->pc = 0x19BE54u;
    // 0x19be54: 0x8e43004c
    ctx->pc = 0x19be54u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19be58: 0xc46c0024
    ctx->pc = 0x19be58u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19be5c: 0xc0666a4
    ctx->pc = 0x19BE5Cu;
    SET_GPR_U32(ctx, 31, 0x19BE64u);
    ctx->pc = 0x19BE60u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 320));
    ctx->pc = 0x199A90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199A90_0x199a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BE64u; }
    }
    if (ctx->pc != 0x19BE64u) { return; }
    ctx->pc = 0x19BE64u;
    // 0x19be64: 0x3c031500
    ctx->pc = 0x19be64u;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19be68: 0x2231825
    ctx->pc = 0x19be68u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x19be6c: 0xac430fa0
    ctx->pc = 0x19be6cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4000), GPR_U32(ctx, 3));
    // 0x19be70: 0xac400fa4
    ctx->pc = 0x19be70u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4004), GPR_U32(ctx, 0));
    // 0x19be74: 0xac400fa8
    ctx->pc = 0x19be74u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4008), GPR_U32(ctx, 0));
    // 0x19be78: 0xac400fac
    ctx->pc = 0x19be78u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4012), GPR_U32(ctx, 0));
    // 0x19be7c: 0xdfbf0030
    ctx->pc = 0x19be7cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19be80: 0x7bb20020
    ctx->pc = 0x19be80u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19be84: 0x7bb10010
    ctx->pc = 0x19be84u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19be88: 0x7bb00000
    ctx->pc = 0x19be88u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19be8c: 0x3e00008
    ctx->pc = 0x19BE8Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19BE90u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 112));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19BE94u;
    // 0x19be94: 0x0
    ctx->pc = 0x19be94u;
    // NOP
    // 0x19be98: 0x0
    ctx->pc = 0x19be98u;
    // NOP
    // 0x19be9c: 0x0
    ctx->pc = 0x19be9cu;
    // NOP
    // 0x19bea0: 0x27bdff60
    ctx->pc = 0x19bea0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x19bea4: 0xffbf0040
    ctx->pc = 0x19bea4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x19bea8: 0x7fb30030
    ctx->pc = 0x19bea8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19beac: 0x7fb20020
    ctx->pc = 0x19beacu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19beb0: 0x80982d
    ctx->pc = 0x19beb0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19beb4: 0x7fb10010
    ctx->pc = 0x19beb4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19beb8: 0xa0902d
    ctx->pc = 0x19beb8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19bebc: 0xc0882d
    ctx->pc = 0x19bebcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19bec0: 0x240401b0
    ctx->pc = 0x19bec0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 432));
    // 0x19bec4: 0x24050010
    ctx->pc = 0x19bec4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    // 0x19bec8: 0xc063774
    ctx->pc = 0x19BEC8u;
    SET_GPR_U32(ctx, 31, 0x19BED0u);
    ctx->pc = 0x19BECCu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BED0u; }
    }
    if (ctx->pc != 0x19BED0u) { return; }
    ctx->pc = 0x19BED0u;
    // 0x19bed0: 0x3c032000
    ctx->pc = 0x19bed0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x19bed4: 0x3c080029
    ctx->pc = 0x19bed4u;
    SET_GPR_U32(ctx, 8, ((uint32_t)41 << 16));
    // 0x19bed8: 0x3463001a
    ctx->pc = 0x19bed8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 26));
    // 0x19bedc: 0x3c061300
    ctx->pc = 0x19bedcu;
    SET_GPR_U32(ctx, 6, ((uint32_t)4864 << 16));
    // 0x19bee0: 0xac430000
    ctx->pc = 0x19bee0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x19bee4: 0x3c056c18
    ctx->pc = 0x19bee4u;
    SET_GPR_U32(ctx, 5, ((uint32_t)27672 << 16));
    // 0x19bee8: 0xac510004
    ctx->pc = 0x19bee8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 17));
    // 0x19beec: 0x3c030100
    ctx->pc = 0x19beecu;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x19bef0: 0xfc400008
    ctx->pc = 0x19bef0u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19bef4: 0x34640404
    ctx->pc = 0x19bef4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 1028));
    // 0x19bef8: 0xac460010
    ctx->pc = 0x19bef8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 6));
    // 0x19befc: 0x3c033f80
    ctx->pc = 0x19befcu;
    SET_GPR_U32(ctx, 3, ((uint32_t)16256 << 16));
    // 0x19bf00: 0xac400014
    ctx->pc = 0x19bf00u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19bf04: 0x44830000
    ctx->pc = 0x19bf04u;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 3);
    // 0x19bf08: 0xac440018
    ctx->pc = 0x19bf08u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 4));
    // 0x19bf0c: 0x40802d
    ctx->pc = 0x19bf0cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19bf10: 0xac45001c
    ctx->pc = 0x19bf10u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 5));
    // 0x19bf14: 0x3c037000
    ctx->pc = 0x19bf14u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19bf18: 0x8e69004c
    ctx->pc = 0x19bf18u;
    SET_GPR_U32(ctx, 9, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19bf1c: 0x3c010029
    ctx->pc = 0x19bf1cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bf20: 0xc4224e50
    ctx->pc = 0x19bf20u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19bf24: 0x34663700
    ctx->pc = 0x19bf24u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 14080));
    // 0x19bf28: 0x34673f40
    ctx->pc = 0x19bf28u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19bf2c: 0x26040050
    ctx->pc = 0x19bf2cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 80));
    // 0x19bf30: 0x27a50060
    ctx->pc = 0x19bf30u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 96));
    // 0x19bf34: 0x25084d40
    ctx->pc = 0x19bf34u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19bf38: 0xc5210024
    ctx->pc = 0x19bf38u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 9), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bf3c: 0x3c010029
    ctx->pc = 0x19bf3cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bf40: 0x46011042
    ctx->pc = 0x19bf40u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19bf44: 0xe4410020
    ctx->pc = 0x19bf44u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19bf48: 0x8e63004c
    ctx->pc = 0x19bf48u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19bf4c: 0xc4224e54
    ctx->pc = 0x19bf4cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19bf50: 0xc4610024
    ctx->pc = 0x19bf50u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bf54: 0x3c010029
    ctx->pc = 0x19bf54u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bf58: 0x46011042
    ctx->pc = 0x19bf58u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19bf5c: 0xe4410024
    ctx->pc = 0x19bf5cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19bf60: 0x8e63004c
    ctx->pc = 0x19bf60u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19bf64: 0xc4224e58
    ctx->pc = 0x19bf64u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19bf68: 0xc4610024
    ctx->pc = 0x19bf68u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bf6c: 0x3c010029
    ctx->pc = 0x19bf6cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bf70: 0x46011042
    ctx->pc = 0x19bf70u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19bf74: 0xe4410028
    ctx->pc = 0x19bf74u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19bf78: 0xc4214e5c
    ctx->pc = 0x19bf78u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bf7c: 0xe441002c
    ctx->pc = 0x19bf7cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19bf80: 0x3c010029
    ctx->pc = 0x19bf80u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bf84: 0xc4214e40
    ctx->pc = 0x19bf84u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bf88: 0xe4410030
    ctx->pc = 0x19bf88u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19bf8c: 0x3c010029
    ctx->pc = 0x19bf8cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bf90: 0xc4214e44
    ctx->pc = 0x19bf90u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bf94: 0xe4410034
    ctx->pc = 0x19bf94u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19bf98: 0x3c010029
    ctx->pc = 0x19bf98u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bf9c: 0xc4214e48
    ctx->pc = 0x19bf9cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bfa0: 0xe4410038
    ctx->pc = 0x19bfa0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19bfa4: 0x3c010029
    ctx->pc = 0x19bfa4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19bfa8: 0xc4214e4c
    ctx->pc = 0x19bfa8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bfac: 0xe441003c
    ctx->pc = 0x19bfacu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
    // 0x19bfb0: 0x3c01002a
    ctx->pc = 0x19bfb0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19bfb4: 0xc421fe40
    ctx->pc = 0x19bfb4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bfb8: 0xe4410040
    ctx->pc = 0x19bfb8u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 64), bits); }
    // 0x19bfbc: 0x3c01002a
    ctx->pc = 0x19bfbcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19bfc0: 0xc422fe40
    ctx->pc = 0x19bfc0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19bfc4: 0x3c01002a
    ctx->pc = 0x19bfc4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19bfc8: 0xc421fe48
    ctx->pc = 0x19bfc8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19bfcc: 0x46011041
    ctx->pc = 0x19bfccu;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19bfd0: 0x46010003
    ctx->pc = 0x19bfd0u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ ctx->f[0] = copysignf(INFINITY, ctx->f[0] * 0.0f); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19bfd4: 0xe4400044
    ctx->pc = 0x19bfd4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 68), bits); }
    // 0x19bfd8: 0xac400048
    ctx->pc = 0x19bfd8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 72), GPR_U32(ctx, 0));
    // 0x19bfdc: 0xc066500
    ctx->pc = 0x19BFDCu;
    SET_GPR_U32(ctx, 31, 0x19BFE4u);
    ctx->pc = 0x19BFE0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 76), GPR_U32(ctx, 0));
    ctx->pc = 0x199400u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BFE4u; }
    }
    if (ctx->pc != 0x19BFE4u) { return; }
    ctx->pc = 0x19BFE4u;
    // 0x19bfe4: 0x3c060029
    ctx->pc = 0x19bfe4u;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x19bfe8: 0x26040090
    ctx->pc = 0x19bfe8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 144));
    // 0x19bfec: 0xc0664e0
    ctx->pc = 0x19BFECu;
    SET_GPR_U32(ctx, 31, 0x19BFF4u);
    ctx->pc = 0x19BFF0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19712));
    ctx->pc = 0x199380u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19BFF4u; }
    }
    if (ctx->pc != 0x19BFF4u) { return; }
    ctx->pc = 0x19BFF4u;
    // 0x19bff4: 0x3c060029
    ctx->pc = 0x19bff4u;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x19bff8: 0x260500d0
    ctx->pc = 0x19bff8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 208));
    // 0x19bffc: 0x24c64cc0
    ctx->pc = 0x19bffcu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19648));
    // 0x19c000: 0x24040008
    ctx->pc = 0x19c000u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 8));
label_19c004:
    // 0x19c004: 0x8cc30000
    ctx->pc = 0x19c004u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x19c008: 0x2484ffff
    ctx->pc = 0x19c008u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x19c00c: 0x8cc20004
    ctx->pc = 0x19c00cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x19c010: 0xaca30000
    ctx->pc = 0x19c010u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x19c014: 0x24c60008
    ctx->pc = 0x19c014u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 8));
    // 0x19c018: 0xaca20004
    ctx->pc = 0x19c018u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x19c01c: 0x1c80fff9
    ctx->pc = 0x19C01Cu;
    {
        const bool branch_taken_0x19c01c = (GPR_S32(ctx, 4) > 0);
        ctx->pc = 0x19C020u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 8));
        if (branch_taken_0x19c01c) {
            ctx->pc = 0x19C004u;
            goto label_19c004;
        }
    }
    ctx->pc = 0x19C024u;
    // 0x19c024: 0xc066734
    ctx->pc = 0x19C024u;
    SET_GPR_U32(ctx, 31, 0x19C02Cu);
    ctx->pc = 0x19C028u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 272));
    ctx->pc = 0x199CD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C02Cu; }
    }
    if (ctx->pc != 0x19C02Cu) { return; }
    ctx->pc = 0x19C02Cu;
    // 0x19c02c: 0x3c010029
    ctx->pc = 0x19c02cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c030: 0x3c023f80
    ctx->pc = 0x19c030u;
    SET_GPR_U32(ctx, 2, ((uint32_t)16256 << 16));
    // 0x19c034: 0xc4224240
    ctx->pc = 0x19c034u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16960)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19c038: 0xafa2005c
    ctx->pc = 0x19c038u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 2));
    // 0x19c03c: 0x3c027000
    ctx->pc = 0x19c03cu;
    SET_GPR_U32(ctx, 2, ((uint32_t)28672 << 16));
    // 0x19c040: 0x26040140
    ctx->pc = 0x19c040u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 320));
    // 0x19c044: 0x26050170
    ctx->pc = 0x19c044u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 368));
    // 0x19c048: 0x34463700
    ctx->pc = 0x19c048u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 2), 14080));
    // 0x19c04c: 0x27a70050
    ctx->pc = 0x19c04cu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 29), 80));
    // 0x19c050: 0x3c010029
    ctx->pc = 0x19c050u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c054: 0xc4214244
    ctx->pc = 0x19c054u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16964)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c058: 0xe7a20050
    ctx->pc = 0x19c058u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19c05c: 0x3c010029
    ctx->pc = 0x19c05cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c060: 0xc4204248
    ctx->pc = 0x19c060u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16968)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c064: 0xe7a10054
    ctx->pc = 0x19c064u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19c068: 0xc0665a8
    ctx->pc = 0x19C068u;
    SET_GPR_U32(ctx, 31, 0x19C070u);
    ctx->pc = 0x19C06Cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    ctx->pc = 0x1996A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001996A0_0x1996a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C070u; }
    }
    if (ctx->pc != 0x19C070u) { return; }
    ctx->pc = 0x19C070u;
    // 0x19c070: 0x8e62004c
    ctx->pc = 0x19c070u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19c074: 0x26040180
    ctx->pc = 0x19c074u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 384));
    // 0x19c078: 0xc44c0024
    ctx->pc = 0x19c078u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19c07c: 0xc066708
    ctx->pc = 0x19C07Cu;
    SET_GPR_U32(ctx, 31, 0x19C084u);
    ctx->pc = 0x19C080u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 400));
    ctx->pc = 0x199C20u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199C20_0x199c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C084u; }
    }
    if (ctx->pc != 0x19C084u) { return; }
    ctx->pc = 0x19C084u;
    // 0x19c084: 0x3c031500
    ctx->pc = 0x19c084u;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19c088: 0x200102d
    ctx->pc = 0x19c088u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c08c: 0x2431825
    ctx->pc = 0x19c08cu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x19c090: 0xae0301a0
    ctx->pc = 0x19c090u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 416), GPR_U32(ctx, 3));
    // 0x19c094: 0xae0001a4
    ctx->pc = 0x19c094u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 420), GPR_U32(ctx, 0));
    // 0x19c098: 0xae0001a8
    ctx->pc = 0x19c098u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 424), GPR_U32(ctx, 0));
    // 0x19c09c: 0xae0001ac
    ctx->pc = 0x19c09cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 428), GPR_U32(ctx, 0));
    // 0x19c0a0: 0xdfbf0040
    ctx->pc = 0x19c0a0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19c0a4: 0x7bb30030
    ctx->pc = 0x19c0a4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19c0a8: 0x7bb20020
    ctx->pc = 0x19c0a8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19c0ac: 0x7bb10010
    ctx->pc = 0x19c0acu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19c0b0: 0x7bb00000
    ctx->pc = 0x19c0b0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19c0b4: 0x3e00008
    ctx->pc = 0x19C0B4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19C0B8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 160));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19C0BCu;
    // 0x19c0bc: 0x0
    ctx->pc = 0x19c0bcu;
    // NOP
    // 0x19c0c0: 0x27bdff60
    ctx->pc = 0x19c0c0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x19c0c4: 0xffbf0040
    ctx->pc = 0x19c0c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x19c0c8: 0x7fb30030
    ctx->pc = 0x19c0c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x19c0cc: 0x7fb20020
    ctx->pc = 0x19c0ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19c0d0: 0x80982d
    ctx->pc = 0x19c0d0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c0d4: 0x7fb10010
    ctx->pc = 0x19c0d4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19c0d8: 0xa0902d
    ctx->pc = 0x19c0d8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c0dc: 0xc0882d
    ctx->pc = 0x19c0dcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c0e0: 0x240401a0
    ctx->pc = 0x19c0e0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 416));
    // 0x19c0e4: 0x24050010
    ctx->pc = 0x19c0e4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    // 0x19c0e8: 0xc063774
    ctx->pc = 0x19C0E8u;
    SET_GPR_U32(ctx, 31, 0x19C0F0u);
    ctx->pc = 0x19C0ECu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C0F0u; }
    }
    if (ctx->pc != 0x19C0F0u) { return; }
    ctx->pc = 0x19C0F0u;
    // 0x19c0f0: 0x3c032000
    ctx->pc = 0x19c0f0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x19c0f4: 0x3c080029
    ctx->pc = 0x19c0f4u;
    SET_GPR_U32(ctx, 8, ((uint32_t)41 << 16));
    // 0x19c0f8: 0x34630019
    ctx->pc = 0x19c0f8u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 25));
    // 0x19c0fc: 0x3c041300
    ctx->pc = 0x19c0fcu;
    SET_GPR_U32(ctx, 4, ((uint32_t)4864 << 16));
    // 0x19c100: 0xac430000
    ctx->pc = 0x19c100u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
    // 0x19c104: 0x3c066c17
    ctx->pc = 0x19c104u;
    SET_GPR_U32(ctx, 6, ((uint32_t)27671 << 16));
    // 0x19c108: 0xac510004
    ctx->pc = 0x19c108u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 17));
    // 0x19c10c: 0x3c030100
    ctx->pc = 0x19c10cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x19c110: 0xfc400008
    ctx->pc = 0x19c110u;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19c114: 0x34630404
    ctx->pc = 0x19c114u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 1028));
    // 0x19c118: 0xac440010
    ctx->pc = 0x19c118u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 4));
    // 0x19c11c: 0x40802d
    ctx->pc = 0x19c11cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c120: 0xac400014
    ctx->pc = 0x19c120u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19c124: 0x3c010029
    ctx->pc = 0x19c124u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c128: 0xac430018
    ctx->pc = 0x19c128u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 3));
    // 0x19c12c: 0x26040040
    ctx->pc = 0x19c12cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 64));
    // 0x19c130: 0x3c037000
    ctx->pc = 0x19c130u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19c134: 0xac46001c
    ctx->pc = 0x19c134u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 6));
    // 0x19c138: 0x34663700
    ctx->pc = 0x19c138u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 14080));
    // 0x19c13c: 0x34673f40
    ctx->pc = 0x19c13cu;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19c140: 0x8e63004c
    ctx->pc = 0x19c140u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19c144: 0xc4214e50
    ctx->pc = 0x19c144u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c148: 0x27a50060
    ctx->pc = 0x19c148u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 96));
    // 0x19c14c: 0x25084d40
    ctx->pc = 0x19c14cu;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19c150: 0xc4600024
    ctx->pc = 0x19c150u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c154: 0x3c010029
    ctx->pc = 0x19c154u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c158: 0x46000802
    ctx->pc = 0x19c158u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19c15c: 0xe4400020
    ctx->pc = 0x19c15cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19c160: 0x8e63004c
    ctx->pc = 0x19c160u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19c164: 0xc4214e54
    ctx->pc = 0x19c164u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c168: 0xc4600024
    ctx->pc = 0x19c168u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c16c: 0x3c010029
    ctx->pc = 0x19c16cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c170: 0x46000802
    ctx->pc = 0x19c170u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19c174: 0xe4400024
    ctx->pc = 0x19c174u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19c178: 0x8e63004c
    ctx->pc = 0x19c178u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19c17c: 0xc4214e58
    ctx->pc = 0x19c17cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c180: 0xc4600024
    ctx->pc = 0x19c180u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c184: 0x3c010029
    ctx->pc = 0x19c184u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c188: 0x46000802
    ctx->pc = 0x19c188u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19c18c: 0xe4400028
    ctx->pc = 0x19c18cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19c190: 0xc4204e5c
    ctx->pc = 0x19c190u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c194: 0xe440002c
    ctx->pc = 0x19c194u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19c198: 0x3c010029
    ctx->pc = 0x19c198u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c19c: 0xc4204e40
    ctx->pc = 0x19c19cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c1a0: 0xe4400030
    ctx->pc = 0x19c1a0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19c1a4: 0x3c010029
    ctx->pc = 0x19c1a4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c1a8: 0xc4204e44
    ctx->pc = 0x19c1a8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c1ac: 0xe4400034
    ctx->pc = 0x19c1acu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19c1b0: 0x3c010029
    ctx->pc = 0x19c1b0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c1b4: 0xc4204e48
    ctx->pc = 0x19c1b4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c1b8: 0xe4400038
    ctx->pc = 0x19c1b8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19c1bc: 0x3c010029
    ctx->pc = 0x19c1bcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c1c0: 0xc4204e4c
    ctx->pc = 0x19c1c0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c1c4: 0xc066500
    ctx->pc = 0x19C1C4u;
    SET_GPR_U32(ctx, 31, 0x19C1CCu);
    ctx->pc = 0x19C1C8u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
    ctx->pc = 0x199400u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C1CCu; }
    }
    if (ctx->pc != 0x19C1CCu) { return; }
    ctx->pc = 0x19C1CCu;
    // 0x19c1cc: 0x3c060029
    ctx->pc = 0x19c1ccu;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x19c1d0: 0x26040080
    ctx->pc = 0x19c1d0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 128));
    // 0x19c1d4: 0xc0664e0
    ctx->pc = 0x19C1D4u;
    SET_GPR_U32(ctx, 31, 0x19C1DCu);
    ctx->pc = 0x19C1D8u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19712));
    ctx->pc = 0x199380u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C1DCu; }
    }
    if (ctx->pc != 0x19C1DCu) { return; }
    ctx->pc = 0x19C1DCu;
    // 0x19c1dc: 0x3c060029
    ctx->pc = 0x19c1dcu;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x19c1e0: 0x260500c0
    ctx->pc = 0x19c1e0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 192));
    // 0x19c1e4: 0x24c64cc0
    ctx->pc = 0x19c1e4u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19648));
    // 0x19c1e8: 0x24040008
    ctx->pc = 0x19c1e8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 8));
label_19c1ec:
    // 0x19c1ec: 0x8cc30000
    ctx->pc = 0x19c1ecu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x19c1f0: 0x2484ffff
    ctx->pc = 0x19c1f0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294967295));
    // 0x19c1f4: 0x8cc20004
    ctx->pc = 0x19c1f4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 6), 4)));
    // 0x19c1f8: 0xaca30000
    ctx->pc = 0x19c1f8u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 0), GPR_U32(ctx, 3));
    // 0x19c1fc: 0x24c60008
    ctx->pc = 0x19c1fcu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 8));
    // 0x19c200: 0xaca20004
    ctx->pc = 0x19c200u;
    WRITE32(ADD32(GPR_U32(ctx, 5), 4), GPR_U32(ctx, 2));
    // 0x19c204: 0x1c80fff9
    ctx->pc = 0x19C204u;
    {
        const bool branch_taken_0x19c204 = (GPR_S32(ctx, 4) > 0);
        ctx->pc = 0x19C208u;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 8));
        if (branch_taken_0x19c204) {
            ctx->pc = 0x19C1ECu;
            goto label_19c1ec;
        }
    }
    ctx->pc = 0x19C20Cu;
    // 0x19c20c: 0xc066734
    ctx->pc = 0x19C20Cu;
    SET_GPR_U32(ctx, 31, 0x19C214u);
    ctx->pc = 0x19C210u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 256));
    ctx->pc = 0x199CD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C214u; }
    }
    if (ctx->pc != 0x19C214u) { return; }
    ctx->pc = 0x19C214u;
    // 0x19c214: 0x3c010029
    ctx->pc = 0x19c214u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c218: 0x3c023f80
    ctx->pc = 0x19c218u;
    SET_GPR_U32(ctx, 2, ((uint32_t)16256 << 16));
    // 0x19c21c: 0xc4224240
    ctx->pc = 0x19c21cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16960)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19c220: 0xafa2005c
    ctx->pc = 0x19c220u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 2));
    // 0x19c224: 0x3c027000
    ctx->pc = 0x19c224u;
    SET_GPR_U32(ctx, 2, ((uint32_t)28672 << 16));
    // 0x19c228: 0x26040130
    ctx->pc = 0x19c228u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 304));
    // 0x19c22c: 0x26050160
    ctx->pc = 0x19c22cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 352));
    // 0x19c230: 0x34463700
    ctx->pc = 0x19c230u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 2), 14080));
    // 0x19c234: 0x27a70050
    ctx->pc = 0x19c234u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 29), 80));
    // 0x19c238: 0x3c010029
    ctx->pc = 0x19c238u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c23c: 0xc4214244
    ctx->pc = 0x19c23cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16964)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c240: 0xe7a20050
    ctx->pc = 0x19c240u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19c244: 0x3c010029
    ctx->pc = 0x19c244u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c248: 0xc4204248
    ctx->pc = 0x19c248u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16968)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c24c: 0xe7a10054
    ctx->pc = 0x19c24cu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19c250: 0xc0665a8
    ctx->pc = 0x19C250u;
    SET_GPR_U32(ctx, 31, 0x19C258u);
    ctx->pc = 0x19C254u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    ctx->pc = 0x1996A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001996A0_0x1996a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C258u; }
    }
    if (ctx->pc != 0x19C258u) { return; }
    ctx->pc = 0x19C258u;
    // 0x19c258: 0x8e62004c
    ctx->pc = 0x19c258u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 19), 76)));
    // 0x19c25c: 0x26040170
    ctx->pc = 0x19c25cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 16), 368));
    // 0x19c260: 0xc44c0024
    ctx->pc = 0x19c260u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 2), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19c264: 0xc066708
    ctx->pc = 0x19C264u;
    SET_GPR_U32(ctx, 31, 0x19C26Cu);
    ctx->pc = 0x19C268u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 16), 384));
    ctx->pc = 0x199C20u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199C20_0x199c20(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C26Cu; }
    }
    if (ctx->pc != 0x19C26Cu) { return; }
    ctx->pc = 0x19C26Cu;
    // 0x19c26c: 0x3c031500
    ctx->pc = 0x19c26cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19c270: 0x200102d
    ctx->pc = 0x19c270u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c274: 0x2431825
    ctx->pc = 0x19c274u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 18), GPR_U32(ctx, 3)));
    // 0x19c278: 0xae030190
    ctx->pc = 0x19c278u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 400), GPR_U32(ctx, 3));
    // 0x19c27c: 0xae000194
    ctx->pc = 0x19c27cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 404), GPR_U32(ctx, 0));
    // 0x19c280: 0xae000198
    ctx->pc = 0x19c280u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 408), GPR_U32(ctx, 0));
    // 0x19c284: 0xae00019c
    ctx->pc = 0x19c284u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 412), GPR_U32(ctx, 0));
    // 0x19c288: 0xdfbf0040
    ctx->pc = 0x19c288u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x19c28c: 0x7bb30030
    ctx->pc = 0x19c28cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19c290: 0x7bb20020
    ctx->pc = 0x19c290u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19c294: 0x7bb10010
    ctx->pc = 0x19c294u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19c298: 0x7bb00000
    ctx->pc = 0x19c298u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19c29c: 0x3e00008
    ctx->pc = 0x19C29Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19C2A0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 160));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19C2A4u;
    // 0x19c2a4: 0x0
    ctx->pc = 0x19c2a4u;
    // NOP
    // 0x19c2a8: 0x0
    ctx->pc = 0x19c2a8u;
    // NOP
    // 0x19c2ac: 0x0
    ctx->pc = 0x19c2acu;
    // NOP
    // 0x19c2b0: 0x27bdffc0
    ctx->pc = 0x19c2b0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x19c2b4: 0xffbf0030
    ctx->pc = 0x19c2b4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19c2b8: 0x7fb20020
    ctx->pc = 0x19c2b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19c2bc: 0x7fb10010
    ctx->pc = 0x19c2bcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19c2c0: 0x80902d
    ctx->pc = 0x19c2c0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c2c4: 0x7fb00000
    ctx->pc = 0x19c2c4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19c2c8: 0xa0882d
    ctx->pc = 0x19c2c8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c2cc: 0xc0802d
    ctx->pc = 0x19c2ccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c2d0: 0x24040f70
    ctx->pc = 0x19c2d0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 3952));
    // 0x19c2d4: 0xc063774
    ctx->pc = 0x19C2D4u;
    SET_GPR_U32(ctx, 31, 0x19C2DCu);
    ctx->pc = 0x19C2D8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C2DCu; }
    }
    if (ctx->pc != 0x19C2DCu) { return; }
    ctx->pc = 0x19C2DCu;
    // 0x19c2dc: 0x3c032000
    ctx->pc = 0x19c2dcu;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x19c2e0: 0x3c051300
    ctx->pc = 0x19c2e0u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4864 << 16));
    // 0x19c2e4: 0x346400f6
    ctx->pc = 0x19c2e4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 246));
    // 0x19c2e8: 0x3c076cf4
    ctx->pc = 0x19c2e8u;
    SET_GPR_U32(ctx, 7, ((uint32_t)27892 << 16));
    // 0x19c2ec: 0xac440000
    ctx->pc = 0x19c2ecu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19c2f0: 0x3c030100
    ctx->pc = 0x19c2f0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x19c2f4: 0xac500004
    ctx->pc = 0x19c2f4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19c2f8: 0x34660404
    ctx->pc = 0x19c2f8u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 1028));
    // 0x19c2fc: 0xfc400008
    ctx->pc = 0x19c2fcu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19c300: 0x3c037000
    ctx->pc = 0x19c300u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19c304: 0xac450010
    ctx->pc = 0x19c304u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x19c308: 0x3c010029
    ctx->pc = 0x19c308u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c30c: 0xac400014
    ctx->pc = 0x19c30cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19c310: 0x34653f40
    ctx->pc = 0x19c310u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19c314: 0xac460018
    ctx->pc = 0x19c314u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x19c318: 0x24440030
    ctx->pc = 0x19c318u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 48));
    // 0x19c31c: 0xac47001c
    ctx->pc = 0x19c31cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x19c320: 0x3c060029
    ctx->pc = 0x19c320u;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x19c324: 0x8e43004c
    ctx->pc = 0x19c324u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c328: 0xc4214e50
    ctx->pc = 0x19c328u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c32c: 0x24c64d40
    ctx->pc = 0x19c32cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19776));
    // 0x19c330: 0xc4600024
    ctx->pc = 0x19c330u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c334: 0x3c010029
    ctx->pc = 0x19c334u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c338: 0x46000802
    ctx->pc = 0x19c338u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19c33c: 0xe4400020
    ctx->pc = 0x19c33cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19c340: 0x8e43004c
    ctx->pc = 0x19c340u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c344: 0xc4214e54
    ctx->pc = 0x19c344u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c348: 0xc4600024
    ctx->pc = 0x19c348u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c34c: 0x3c010029
    ctx->pc = 0x19c34cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c350: 0x46000802
    ctx->pc = 0x19c350u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19c354: 0xe4400024
    ctx->pc = 0x19c354u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19c358: 0x8e43004c
    ctx->pc = 0x19c358u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c35c: 0xc4214e58
    ctx->pc = 0x19c35cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c360: 0xc4600024
    ctx->pc = 0x19c360u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c364: 0x3c010029
    ctx->pc = 0x19c364u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c368: 0x46000802
    ctx->pc = 0x19c368u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19c36c: 0xe4400028
    ctx->pc = 0x19c36cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19c370: 0xc4204e5c
    ctx->pc = 0x19c370u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c374: 0xc0664e0
    ctx->pc = 0x19C374u;
    SET_GPR_U32(ctx, 31, 0x19C37Cu);
    ctx->pc = 0x19C378u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    ctx->pc = 0x199380u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C37Cu; }
    }
    if (ctx->pc != 0x19C37Cu) { return; }
    ctx->pc = 0x19C37Cu;
    // 0x19c37c: 0x3c037000
    ctx->pc = 0x19c37cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19c380: 0x3c060029
    ctx->pc = 0x19c380u;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x19c384: 0x24440070
    ctx->pc = 0x19c384u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 112));
    // 0x19c388: 0x34653f40
    ctx->pc = 0x19c388u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19c38c: 0xc0664e0
    ctx->pc = 0x19C38Cu;
    SET_GPR_U32(ctx, 31, 0x19C394u);
    ctx->pc = 0x19C390u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19712));
    ctx->pc = 0x199380u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C394u; }
    }
    if (ctx->pc != 0x19C394u) { return; }
    ctx->pc = 0x19C394u;
    // 0x19c394: 0x3c010029
    ctx->pc = 0x19c394u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c398: 0xc4204234
    ctx->pc = 0x19c398u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c39c: 0x46000007
    ctx->pc = 0x19c39cu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19c3a0: 0x3c010029
    ctx->pc = 0x19c3a0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c3a4: 0xe44000b0
    ctx->pc = 0x19c3a4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 176), bits); }
    // 0x19c3a8: 0xc4204238
    ctx->pc = 0x19c3a8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c3ac: 0x46000007
    ctx->pc = 0x19c3acu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19c3b0: 0x3c010029
    ctx->pc = 0x19c3b0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c3b4: 0xe44000b4
    ctx->pc = 0x19c3b4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 180), bits); }
    // 0x19c3b8: 0xc420423c
    ctx->pc = 0x19c3b8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c3bc: 0x46000007
    ctx->pc = 0x19c3bcu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19c3c0: 0x3c010029
    ctx->pc = 0x19c3c0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c3c4: 0xe44000b8
    ctx->pc = 0x19c3c4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 184), bits); }
    // 0x19c3c8: 0xc420429c
    ctx->pc = 0x19c3c8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c3cc: 0x46000007
    ctx->pc = 0x19c3ccu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19c3d0: 0x3c010029
    ctx->pc = 0x19c3d0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c3d4: 0xe44000c0
    ctx->pc = 0x19c3d4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 192), bits); }
    // 0x19c3d8: 0xc42042a0
    ctx->pc = 0x19c3d8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c3dc: 0x46000007
    ctx->pc = 0x19c3dcu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19c3e0: 0x3c010029
    ctx->pc = 0x19c3e0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c3e4: 0xe44000c4
    ctx->pc = 0x19c3e4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 196), bits); }
    // 0x19c3e8: 0xc42042a4
    ctx->pc = 0x19c3e8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c3ec: 0x46000007
    ctx->pc = 0x19c3ecu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19c3f0: 0x3c010029
    ctx->pc = 0x19c3f0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c3f4: 0xe44000c8
    ctx->pc = 0x19c3f4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 200), bits); }
    // 0x19c3f8: 0xc4204304
    ctx->pc = 0x19c3f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17156)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c3fc: 0x46000007
    ctx->pc = 0x19c3fcu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19c400: 0x3c010029
    ctx->pc = 0x19c400u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c404: 0xe44000d0
    ctx->pc = 0x19c404u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 208), bits); }
    // 0x19c408: 0xc4204308
    ctx->pc = 0x19c408u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17160)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c40c: 0x46000007
    ctx->pc = 0x19c40cu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19c410: 0x3c010029
    ctx->pc = 0x19c410u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c414: 0xe44000d4
    ctx->pc = 0x19c414u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 212), bits); }
    // 0x19c418: 0xc420430c
    ctx->pc = 0x19c418u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17164)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c41c: 0x46000007
    ctx->pc = 0x19c41cu;
    ctx->f[0] = FPU_NEG_S(ctx->f[0]);
    // 0x19c420: 0xe44000d8
    ctx->pc = 0x19c420u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 216), bits); }
    // 0x19c424: 0x8e450054
    ctx->pc = 0x19c424u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 18), 84)));
    // 0x19c428: 0xc066740
    ctx->pc = 0x19C428u;
    SET_GPR_U32(ctx, 31, 0x19C430u);
    ctx->pc = 0x19C42Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 352));
    ctx->pc = 0x199D00u;
    goto label_199d00;
    ctx->pc = 0x19C430u;
label_19c430:
    // 0x19c430: 0x8e43004c
    ctx->pc = 0x19c430u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c434: 0xc46c0024
    ctx->pc = 0x19c434u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19c438: 0xc066648
    ctx->pc = 0x19C438u;
    SET_GPR_U32(ctx, 31, 0x19C440u);
    ctx->pc = 0x19C43Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 224));
    ctx->pc = 0x199920u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199920_0x199920(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C440u; }
    }
    if (ctx->pc != 0x19C440u) { return; }
    ctx->pc = 0x19C440u;
    // 0x19c440: 0x3c01002a
    ctx->pc = 0x19c440u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19c444: 0x3c033f80
    ctx->pc = 0x19c444u;
    SET_GPR_U32(ctx, 3, ((uint32_t)16256 << 16));
    // 0x19c448: 0xc421fe40
    ctx->pc = 0x19c448u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c44c: 0x24440130
    ctx->pc = 0x19c44cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 304));
    // 0x19c450: 0x44830000
    ctx->pc = 0x19c450u;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 3);
    // 0x19c454: 0x0
    ctx->pc = 0x19c454u;
    // NOP
    // 0x19c458: 0xe4410120
    ctx->pc = 0x19c458u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 288), bits); }
    // 0x19c45c: 0x3c01002a
    ctx->pc = 0x19c45cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19c460: 0xc422fe40
    ctx->pc = 0x19c460u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19c464: 0x3c01002a
    ctx->pc = 0x19c464u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19c468: 0xc421fe48
    ctx->pc = 0x19c468u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c46c: 0x46011041
    ctx->pc = 0x19c46cu;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19c470: 0x46010003
    ctx->pc = 0x19c470u;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ ctx->f[0] = copysignf(INFINITY, ctx->f[0] * 0.0f); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19c474: 0xe4400124
    ctx->pc = 0x19c474u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 292), bits); }
    // 0x19c478: 0xac400128
    ctx->pc = 0x19c478u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 296), GPR_U32(ctx, 0));
    // 0x19c47c: 0xc066734
    ctx->pc = 0x19C47Cu;
    SET_GPR_U32(ctx, 31, 0x19C484u);
    ctx->pc = 0x19C480u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 300), GPR_U32(ctx, 0));
    ctx->pc = 0x199CD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C484u; }
    }
    if (ctx->pc != 0x19C484u) { return; }
    ctx->pc = 0x19C484u;
    // 0x19c484: 0x3c031500
    ctx->pc = 0x19c484u;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19c488: 0x2231825
    ctx->pc = 0x19c488u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x19c48c: 0xac430f60
    ctx->pc = 0x19c48cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3936), GPR_U32(ctx, 3));
    // 0x19c490: 0xac400f64
    ctx->pc = 0x19c490u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3940), GPR_U32(ctx, 0));
    // 0x19c494: 0xac400f68
    ctx->pc = 0x19c494u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3944), GPR_U32(ctx, 0));
    // 0x19c498: 0xac400f6c
    ctx->pc = 0x19c498u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3948), GPR_U32(ctx, 0));
    // 0x19c49c: 0xdfbf0030
    ctx->pc = 0x19c49cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19c4a0: 0x7bb20020
    ctx->pc = 0x19c4a0u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19c4a4: 0x7bb10010
    ctx->pc = 0x19c4a4u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19c4a8: 0x7bb00000
    ctx->pc = 0x19c4a8u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19c4ac: 0x3e00008
    ctx->pc = 0x19C4ACu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19C4B0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19C4B4u;
    // 0x19c4b4: 0x0
    ctx->pc = 0x19c4b4u;
    // NOP
    // 0x19c4b8: 0x0
    ctx->pc = 0x19c4b8u;
    // NOP
    // 0x19c4bc: 0x0
    ctx->pc = 0x19c4bcu;
    // NOP
    // 0x19c4c0: 0x27bdff90
    ctx->pc = 0x19c4c0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967184));
    // 0x19c4c4: 0xffbf0030
    ctx->pc = 0x19c4c4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19c4c8: 0x7fb20020
    ctx->pc = 0x19c4c8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19c4cc: 0x7fb10010
    ctx->pc = 0x19c4ccu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19c4d0: 0x80902d
    ctx->pc = 0x19c4d0u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c4d4: 0x7fb00000
    ctx->pc = 0x19c4d4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19c4d8: 0xa0882d
    ctx->pc = 0x19c4d8u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c4dc: 0xc0802d
    ctx->pc = 0x19c4dcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c4e0: 0x24040fa0
    ctx->pc = 0x19c4e0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4000));
    // 0x19c4e4: 0xc063774
    ctx->pc = 0x19C4E4u;
    SET_GPR_U32(ctx, 31, 0x19C4ECu);
    ctx->pc = 0x19C4E8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C4ECu; }
    }
    if (ctx->pc != 0x19C4ECu) { return; }
    ctx->pc = 0x19C4ECu;
    // 0x19c4ec: 0x3c032000
    ctx->pc = 0x19c4ecu;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x19c4f0: 0x3c070029
    ctx->pc = 0x19c4f0u;
    SET_GPR_U32(ctx, 7, ((uint32_t)41 << 16));
    // 0x19c4f4: 0x346400f9
    ctx->pc = 0x19c4f4u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 249));
    // 0x19c4f8: 0x3c061300
    ctx->pc = 0x19c4f8u;
    SET_GPR_U32(ctx, 6, ((uint32_t)4864 << 16));
    // 0x19c4fc: 0xac440000
    ctx->pc = 0x19c4fcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19c500: 0x3c030100
    ctx->pc = 0x19c500u;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x19c504: 0xac500004
    ctx->pc = 0x19c504u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19c508: 0x34650404
    ctx->pc = 0x19c508u;
    SET_GPR_U32(ctx, 5, OR32(GPR_U32(ctx, 3), 1028));
    // 0x19c50c: 0xfc400008
    ctx->pc = 0x19c50cu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19c510: 0x3c033f80
    ctx->pc = 0x19c510u;
    SET_GPR_U32(ctx, 3, ((uint32_t)16256 << 16));
    // 0x19c514: 0xac460010
    ctx->pc = 0x19c514u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 6));
    // 0x19c518: 0x3c046cf7
    ctx->pc = 0x19c518u;
    SET_GPR_U32(ctx, 4, ((uint32_t)27895 << 16));
    // 0x19c51c: 0xac400014
    ctx->pc = 0x19c51cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19c520: 0x44830000
    ctx->pc = 0x19c520u;
    *(uint32_t*)&ctx->f[0] = GPR_U32(ctx, 3);
    // 0x19c524: 0xac450018
    ctx->pc = 0x19c524u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 5));
    // 0x19c528: 0x3c010029
    ctx->pc = 0x19c528u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c52c: 0xac44001c
    ctx->pc = 0x19c52cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 4));
    // 0x19c530: 0x24e74d40
    ctx->pc = 0x19c530u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 19776));
    // 0x19c534: 0x8e43004c
    ctx->pc = 0x19c534u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c538: 0xc4224e50
    ctx->pc = 0x19c538u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19c53c: 0x24460040
    ctx->pc = 0x19c53cu;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 2), 64));
    // 0x19c540: 0x24050008
    ctx->pc = 0x19c540u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
    // 0x19c544: 0xc4610024
    ctx->pc = 0x19c544u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c548: 0x3c010029
    ctx->pc = 0x19c548u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c54c: 0x46011042
    ctx->pc = 0x19c54cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19c550: 0xe4410020
    ctx->pc = 0x19c550u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19c554: 0x8e43004c
    ctx->pc = 0x19c554u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c558: 0xc4224e54
    ctx->pc = 0x19c558u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19c55c: 0xc4610024
    ctx->pc = 0x19c55cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c560: 0x3c010029
    ctx->pc = 0x19c560u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c564: 0x46011042
    ctx->pc = 0x19c564u;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19c568: 0xe4410024
    ctx->pc = 0x19c568u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19c56c: 0x8e43004c
    ctx->pc = 0x19c56cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c570: 0xc4224e58
    ctx->pc = 0x19c570u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19c574: 0xc4610024
    ctx->pc = 0x19c574u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c578: 0x3c010029
    ctx->pc = 0x19c578u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c57c: 0x46011042
    ctx->pc = 0x19c57cu;
    ctx->f[1] = FPU_MUL_S(ctx->f[2], ctx->f[1]);
    // 0x19c580: 0xe4410028
    ctx->pc = 0x19c580u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19c584: 0xc4214e5c
    ctx->pc = 0x19c584u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c588: 0xe441002c
    ctx->pc = 0x19c588u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19c58c: 0x3c01002a
    ctx->pc = 0x19c58cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19c590: 0xc421fe40
    ctx->pc = 0x19c590u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c594: 0xe4410030
    ctx->pc = 0x19c594u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19c598: 0x3c01002a
    ctx->pc = 0x19c598u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19c59c: 0xc422fe40
    ctx->pc = 0x19c59cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966848)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19c5a0: 0x3c01002a
    ctx->pc = 0x19c5a0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)42 << 16));
    // 0x19c5a4: 0xc421fe48
    ctx->pc = 0x19c5a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 4294966856)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c5a8: 0x46011041
    ctx->pc = 0x19c5a8u;
    ctx->f[1] = FPU_SUB_S(ctx->f[2], ctx->f[1]);
    // 0x19c5ac: 0x46010003
    ctx->pc = 0x19c5acu;
    if (ctx->f[1] == 0.0f) { ctx->fcr31 |= 0x100000; /* DZ flag */ ctx->f[0] = copysignf(INFINITY, ctx->f[0] * 0.0f); } else ctx->f[0] = ctx->f[0] / ctx->f[1];
    // 0x19c5b0: 0xe4400034
    ctx->pc = 0x19c5b0u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19c5b4: 0xac400038
    ctx->pc = 0x19c5b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 56), GPR_U32(ctx, 0));
    // 0x19c5b8: 0xac40003c
    ctx->pc = 0x19c5b8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 60), GPR_U32(ctx, 0));
label_19c5bc:
    // 0x19c5bc: 0x8ce40000
    ctx->pc = 0x19c5bcu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19c5c0: 0x24a5ffff
    ctx->pc = 0x19c5c0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19c5c4: 0x8ce30004
    ctx->pc = 0x19c5c4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19c5c8: 0xacc40000
    ctx->pc = 0x19c5c8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19c5cc: 0x24e70008
    ctx->pc = 0x19c5ccu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 8));
    // 0x19c5d0: 0xacc30004
    ctx->pc = 0x19c5d0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19c5d4: 0x1ca0fff9
    ctx->pc = 0x19C5D4u;
    {
        const bool branch_taken_0x19c5d4 = (GPR_S32(ctx, 5) > 0);
        ctx->pc = 0x19C5D8u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 8));
        if (branch_taken_0x19c5d4) {
            ctx->pc = 0x19C5BCu;
            goto label_19c5bc;
        }
    }
    ctx->pc = 0x19C5DCu;
    // 0x19c5dc: 0x3c070029
    ctx->pc = 0x19c5dcu;
    SET_GPR_U32(ctx, 7, ((uint32_t)41 << 16));
    // 0x19c5e0: 0x24460080
    ctx->pc = 0x19c5e0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 2), 128));
    // 0x19c5e4: 0x24e74d00
    ctx->pc = 0x19c5e4u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 19712));
    // 0x19c5e8: 0x24050008
    ctx->pc = 0x19c5e8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
label_19c5ec:
    // 0x19c5ec: 0x8ce40000
    ctx->pc = 0x19c5ecu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19c5f0: 0x24a5ffff
    ctx->pc = 0x19c5f0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19c5f4: 0x8ce30004
    ctx->pc = 0x19c5f4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19c5f8: 0xacc40000
    ctx->pc = 0x19c5f8u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19c5fc: 0x24e70008
    ctx->pc = 0x19c5fcu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 8));
    // 0x19c600: 0xacc30004
    ctx->pc = 0x19c600u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19c604: 0x1ca0fff9
    ctx->pc = 0x19C604u;
    {
        const bool branch_taken_0x19c604 = (GPR_S32(ctx, 5) > 0);
        ctx->pc = 0x19C608u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 8));
        if (branch_taken_0x19c604) {
            ctx->pc = 0x19C5ECu;
            goto label_19c5ec;
        }
    }
    ctx->pc = 0x19C60Cu;
    // 0x19c60c: 0x402d
    ctx->pc = 0x19c60cu;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_19c610:
    // 0x19c610: 0x8e430054
    ctx->pc = 0x19c610u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 84)));
    // 0x19c614: 0x24040001
    ctx->pc = 0x19c614u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    // 0x19c618: 0x1042004
    ctx->pc = 0x19c618u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), GPR_U32(ctx, 8) & 0x1F));
    // 0x19c61c: 0x641824
    ctx->pc = 0x19c61cu;
    SET_GPR_U32(ctx, 3, AND32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x19c620: 0x1060000e
    ctx->pc = 0x19C620u;
    {
        const bool branch_taken_0x19c620 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x19C624u;
        SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 8), 1));
        if (branch_taken_0x19c620) {
            ctx->pc = 0x19C65Cu;
            goto label_19c65c;
        }
    }
    ctx->pc = 0x19C628u;
    // 0x19c628: 0x3c017000
    ctx->pc = 0x19c628u;
    SET_GPR_U32(ctx, 1, ((uint32_t)28672 << 16));
    // 0x19c62c: 0x682021
    ctx->pc = 0x19c62cu;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 8)));
    // 0x19c630: 0x83180
    ctx->pc = 0x19c630u;
    SET_GPR_U32(ctx, 6, SLL32(GPR_U32(ctx, 8), 6));
    // 0x19c634: 0x461821
    ctx->pc = 0x19c634u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x19c638: 0x34213700
    ctx->pc = 0x19c638u;
    SET_GPR_U32(ctx, 1, OR32(GPR_U32(ctx, 1), 14080));
    // 0x19c63c: 0x42100
    ctx->pc = 0x19c63cu;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 4));
    // 0x19c640: 0x24650190
    ctx->pc = 0x19c640u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 3), 400));
    // 0x19c644: 0x441821
    ctx->pc = 0x19c644u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x19c648: 0xc13021
    ctx->pc = 0x19c648u;
    SET_GPR_U32(ctx, 6, ADD32(GPR_U32(ctx, 6), GPR_U32(ctx, 1)));
    // 0x19c64c: 0x24640990
    ctx->pc = 0x19c64cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 3), 2448));
    // 0x19c650: 0x3c037000
    ctx->pc = 0x19c650u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19c654: 0xc066538
    ctx->pc = 0x19C654u;
    SET_GPR_U32(ctx, 31, 0x19C65Cu);
    ctx->pc = 0x19C658u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    ctx->pc = 0x1994E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001994E0_0x1994e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C65Cu; }
    }
    if (ctx->pc != 0x19C65Cu) { return; }
    ctx->pc = 0x19C65Cu;
label_19c65c:
    // 0x19c65c: 0x25080001
    ctx->pc = 0x19c65cu;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 1));
    // 0x19c660: 0x29030020
    ctx->pc = 0x19c660u;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 8), 32));
    // 0x19c664: 0x1460ffea
    ctx->pc = 0x19C664u;
    {
        const bool branch_taken_0x19c664 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x19C668u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 192));
        if (branch_taken_0x19c664) {
            ctx->pc = 0x19C610u;
            goto label_19c610;
        }
    }
    ctx->pc = 0x19C66Cu;
    // 0x19c66c: 0xc066734
    ctx->pc = 0x19C66Cu;
    SET_GPR_U32(ctx, 31, 0x19C674u);
    ctx->pc = 0x199CD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C674u; }
    }
    if (ctx->pc != 0x19C674u) { return; }
    ctx->pc = 0x19C674u;
    // 0x19c674: 0x3c010029
    ctx->pc = 0x19c674u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c678: 0x3c033f80
    ctx->pc = 0x19c678u;
    SET_GPR_U32(ctx, 3, ((uint32_t)16256 << 16));
    // 0x19c67c: 0xc4214234
    ctx->pc = 0x19c67cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16948)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c680: 0xafa3004c
    ctx->pc = 0x19c680u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 76), GPR_U32(ctx, 3));
    // 0x19c684: 0xafa3005c
    ctx->pc = 0x19c684u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 92), GPR_U32(ctx, 3));
    // 0x19c688: 0x244400f0
    ctx->pc = 0x19c688u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 240));
    // 0x19c68c: 0xafa3006c
    ctx->pc = 0x19c68cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 108), GPR_U32(ctx, 3));
    // 0x19c690: 0x24450120
    ctx->pc = 0x19c690u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 2), 288));
    // 0x19c694: 0x3c037000
    ctx->pc = 0x19c694u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19c698: 0x27a70040
    ctx->pc = 0x19c698u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 29), 64));
    // 0x19c69c: 0x34663f40
    ctx->pc = 0x19c69cu;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19c6a0: 0x3c010029
    ctx->pc = 0x19c6a0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c6a4: 0xc4204238
    ctx->pc = 0x19c6a4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16952)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c6a8: 0x46000847
    ctx->pc = 0x19c6a8u;
    ctx->f[1] = FPU_NEG_S(ctx->f[1]);
    // 0x19c6ac: 0xe7a10040
    ctx->pc = 0x19c6acu;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 64), bits); }
    // 0x19c6b0: 0x3c010029
    ctx->pc = 0x19c6b0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c6b4: 0xc424423c
    ctx->pc = 0x19c6b4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 16956)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[4] = f; }
    // 0x19c6b8: 0x46000147
    ctx->pc = 0x19c6b8u;
    ctx->f[5] = FPU_NEG_S(ctx->f[0]);
    // 0x19c6bc: 0xe7a50044
    ctx->pc = 0x19c6bcu;
    { float f = ctx->f[5]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 68), bits); }
    // 0x19c6c0: 0x3c010029
    ctx->pc = 0x19c6c0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c6c4: 0xc42342a8
    ctx->pc = 0x19c6c4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17064)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[3] = f; }
    // 0x19c6c8: 0x46002107
    ctx->pc = 0x19c6c8u;
    ctx->f[4] = FPU_NEG_S(ctx->f[4]);
    // 0x19c6cc: 0xe7a40048
    ctx->pc = 0x19c6ccu;
    { float f = ctx->f[4]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 72), bits); }
    // 0x19c6d0: 0x3c010029
    ctx->pc = 0x19c6d0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c6d4: 0xc42242ac
    ctx->pc = 0x19c6d4u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17068)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[2] = f; }
    // 0x19c6d8: 0xe7a30050
    ctx->pc = 0x19c6d8u;
    { float f = ctx->f[3]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 80), bits); }
    // 0x19c6dc: 0x3c010029
    ctx->pc = 0x19c6dcu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c6e0: 0xc42142b0
    ctx->pc = 0x19c6e0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17072)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c6e4: 0xe7a20054
    ctx->pc = 0x19c6e4u;
    { float f = ctx->f[2]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 84), bits); }
    // 0x19c6e8: 0x3c010029
    ctx->pc = 0x19c6e8u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c6ec: 0xc4204310
    ctx->pc = 0x19c6ecu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17168)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c6f0: 0xe7a10058
    ctx->pc = 0x19c6f0u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 88), bits); }
    // 0x19c6f4: 0x3c010029
    ctx->pc = 0x19c6f4u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c6f8: 0xc4214314
    ctx->pc = 0x19c6f8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17172)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c6fc: 0xe7a00060
    ctx->pc = 0x19c6fcu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 96), bits); }
    // 0x19c700: 0x3c010029
    ctx->pc = 0x19c700u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c704: 0xc4204318
    ctx->pc = 0x19c704u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 17176)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c708: 0xe7a10064
    ctx->pc = 0x19c708u;
    { float f = ctx->f[1]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 100), bits); }
    // 0x19c70c: 0xc06661c
    ctx->pc = 0x19C70Cu;
    SET_GPR_U32(ctx, 31, 0x19C714u);
    ctx->pc = 0x19C710u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 29), 104), bits); }
    ctx->pc = 0x199870u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199870_0x199870(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C714u; }
    }
    if (ctx->pc != 0x19C714u) { return; }
    ctx->pc = 0x19C714u;
    // 0x19c714: 0x8e43004c
    ctx->pc = 0x19c714u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c718: 0xc46c0024
    ctx->pc = 0x19c718u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[12] = f; }
    // 0x19c71c: 0xc0666a4
    ctx->pc = 0x19C71Cu;
    SET_GPR_U32(ctx, 31, 0x19C724u);
    ctx->pc = 0x19C720u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 304));
    ctx->pc = 0x199A90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199A90_0x199a90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C724u; }
    }
    if (ctx->pc != 0x19C724u) { return; }
    ctx->pc = 0x19C724u;
    // 0x19c724: 0x3c031500
    ctx->pc = 0x19c724u;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19c728: 0x2231825
    ctx->pc = 0x19c728u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x19c72c: 0xac430f90
    ctx->pc = 0x19c72cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3984), GPR_U32(ctx, 3));
    // 0x19c730: 0xac400f94
    ctx->pc = 0x19c730u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3988), GPR_U32(ctx, 0));
    // 0x19c734: 0xac400f98
    ctx->pc = 0x19c734u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3992), GPR_U32(ctx, 0));
    // 0x19c738: 0xac400f9c
    ctx->pc = 0x19c738u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 3996), GPR_U32(ctx, 0));
    // 0x19c73c: 0xdfbf0030
    ctx->pc = 0x19c73cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19c740: 0x7bb20020
    ctx->pc = 0x19c740u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19c744: 0x7bb10010
    ctx->pc = 0x19c744u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19c748: 0x7bb00000
    ctx->pc = 0x19c748u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19c74c: 0x3e00008
    ctx->pc = 0x19C74Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19C750u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 112));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19C754u;
    // 0x19c754: 0x0
    ctx->pc = 0x19c754u;
    // NOP
    // 0x19c758: 0x0
    ctx->pc = 0x19c758u;
    // NOP
    // 0x19c75c: 0x0
    ctx->pc = 0x19c75cu;
    // NOP
    // 0x19c760: 0x27bdff80
    ctx->pc = 0x19c760u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x19c764: 0xffbf0030
    ctx->pc = 0x19c764u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
    // 0x19c768: 0x7fb20020
    ctx->pc = 0x19c768u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x19c76c: 0x7fb10010
    ctx->pc = 0x19c76cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x19c770: 0x80902d
    ctx->pc = 0x19c770u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c774: 0x7fb00000
    ctx->pc = 0x19c774u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x19c778: 0xa0882d
    ctx->pc = 0x19c778u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c77c: 0xc0802d
    ctx->pc = 0x19c77cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x19c780: 0x24040140
    ctx->pc = 0x19c780u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 320));
    // 0x19c784: 0xc063774
    ctx->pc = 0x19C784u;
    SET_GPR_U32(ctx, 31, 0x19C78Cu);
    ctx->pc = 0x19C788u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 16));
    ctx->pc = 0x18DDD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0018DDD0_0x18ddd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C78Cu; }
    }
    if (ctx->pc != 0x19C78Cu) { return; }
    ctx->pc = 0x19C78Cu;
    // 0x19c78c: 0x3c032000
    ctx->pc = 0x19c78cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)8192 << 16));
    // 0x19c790: 0x3c080029
    ctx->pc = 0x19c790u;
    SET_GPR_U32(ctx, 8, ((uint32_t)41 << 16));
    // 0x19c794: 0x34640013
    ctx->pc = 0x19c794u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 3), 19));
    // 0x19c798: 0x3c051300
    ctx->pc = 0x19c798u;
    SET_GPR_U32(ctx, 5, ((uint32_t)4864 << 16));
    // 0x19c79c: 0xac440000
    ctx->pc = 0x19c79cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 4));
    // 0x19c7a0: 0x3c030100
    ctx->pc = 0x19c7a0u;
    SET_GPR_U32(ctx, 3, ((uint32_t)256 << 16));
    // 0x19c7a4: 0xac500004
    ctx->pc = 0x19c7a4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4), GPR_U32(ctx, 16));
    // 0x19c7a8: 0x34660404
    ctx->pc = 0x19c7a8u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 1028));
    // 0x19c7ac: 0xfc400008
    ctx->pc = 0x19c7acu;
    WRITE64(ADD32(GPR_U32(ctx, 2), 8), GPR_U64(ctx, 0));
    // 0x19c7b0: 0x3c076c11
    ctx->pc = 0x19c7b0u;
    SET_GPR_U32(ctx, 7, ((uint32_t)27665 << 16));
    // 0x19c7b4: 0xac450010
    ctx->pc = 0x19c7b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 16), GPR_U32(ctx, 5));
    // 0x19c7b8: 0x3c037000
    ctx->pc = 0x19c7b8u;
    SET_GPR_U32(ctx, 3, ((uint32_t)28672 << 16));
    // 0x19c7bc: 0xac400014
    ctx->pc = 0x19c7bcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 20), GPR_U32(ctx, 0));
    // 0x19c7c0: 0x3c010029
    ctx->pc = 0x19c7c0u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c7c4: 0xac460018
    ctx->pc = 0x19c7c4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 24), GPR_U32(ctx, 6));
    // 0x19c7c8: 0x24440040
    ctx->pc = 0x19c7c8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 64));
    // 0x19c7cc: 0xac47001c
    ctx->pc = 0x19c7ccu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 28), GPR_U32(ctx, 7));
    // 0x19c7d0: 0x34663700
    ctx->pc = 0x19c7d0u;
    SET_GPR_U32(ctx, 6, OR32(GPR_U32(ctx, 3), 14080));
    // 0x19c7d4: 0x34673f40
    ctx->pc = 0x19c7d4u;
    SET_GPR_U32(ctx, 7, OR32(GPR_U32(ctx, 3), 16192));
    // 0x19c7d8: 0x27a50040
    ctx->pc = 0x19c7d8u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 29), 64));
    // 0x19c7dc: 0x8e43004c
    ctx->pc = 0x19c7dcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c7e0: 0xc4214e50
    ctx->pc = 0x19c7e0u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20048)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c7e4: 0x25084d40
    ctx->pc = 0x19c7e4u;
    SET_GPR_S32(ctx, 8, ADD32(GPR_U32(ctx, 8), 19776));
    // 0x19c7e8: 0xc4600024
    ctx->pc = 0x19c7e8u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c7ec: 0x3c010029
    ctx->pc = 0x19c7ecu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c7f0: 0x46000802
    ctx->pc = 0x19c7f0u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19c7f4: 0xe4400020
    ctx->pc = 0x19c7f4u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 32), bits); }
    // 0x19c7f8: 0x8e43004c
    ctx->pc = 0x19c7f8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c7fc: 0xc4214e54
    ctx->pc = 0x19c7fcu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20052)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c800: 0xc4600024
    ctx->pc = 0x19c800u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c804: 0x3c010029
    ctx->pc = 0x19c804u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c808: 0x46000802
    ctx->pc = 0x19c808u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19c80c: 0xe4400024
    ctx->pc = 0x19c80cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 36), bits); }
    // 0x19c810: 0x8e43004c
    ctx->pc = 0x19c810u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 76)));
    // 0x19c814: 0xc4214e58
    ctx->pc = 0x19c814u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20056)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[1] = f; }
    // 0x19c818: 0xc4600024
    ctx->pc = 0x19c818u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 3), 36)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c81c: 0x3c010029
    ctx->pc = 0x19c81cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c820: 0x46000802
    ctx->pc = 0x19c820u;
    ctx->f[0] = FPU_MUL_S(ctx->f[1], ctx->f[0]);
    // 0x19c824: 0xe4400028
    ctx->pc = 0x19c824u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 40), bits); }
    // 0x19c828: 0xc4204e5c
    ctx->pc = 0x19c828u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20060)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c82c: 0xe440002c
    ctx->pc = 0x19c82cu;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 44), bits); }
    // 0x19c830: 0x3c010029
    ctx->pc = 0x19c830u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c834: 0xc4204e40
    ctx->pc = 0x19c834u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20032)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c838: 0xe4400030
    ctx->pc = 0x19c838u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 48), bits); }
    // 0x19c83c: 0x3c010029
    ctx->pc = 0x19c83cu;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c840: 0xc4204e44
    ctx->pc = 0x19c840u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20036)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c844: 0xe4400034
    ctx->pc = 0x19c844u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 52), bits); }
    // 0x19c848: 0x3c010029
    ctx->pc = 0x19c848u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c84c: 0xc4204e48
    ctx->pc = 0x19c84cu;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20040)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c850: 0xe4400038
    ctx->pc = 0x19c850u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 56), bits); }
    // 0x19c854: 0x3c010029
    ctx->pc = 0x19c854u;
    SET_GPR_U32(ctx, 1, ((uint32_t)41 << 16));
    // 0x19c858: 0xc4204e4c
    ctx->pc = 0x19c858u;
    { uint32_t bits = READ32(ADD32(GPR_U32(ctx, 1), 20044)); float f; std::memcpy(&f, &bits, sizeof(f)); ctx->f[0] = f; }
    // 0x19c85c: 0xc066500
    ctx->pc = 0x19C85Cu;
    SET_GPR_U32(ctx, 31, 0x19C864u);
    ctx->pc = 0x19C860u;
    { float f = ctx->f[0]; uint32_t bits; std::memcpy(&bits, &f, sizeof(bits)); WRITE32(ADD32(GPR_U32(ctx, 2), 60), bits); }
    ctx->pc = 0x199400u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199400_0x199400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C864u; }
    }
    if (ctx->pc != 0x19C864u) { return; }
    ctx->pc = 0x19C864u;
    // 0x19c864: 0x3c060029
    ctx->pc = 0x19c864u;
    SET_GPR_U32(ctx, 6, ((uint32_t)41 << 16));
    // 0x19c868: 0x24440080
    ctx->pc = 0x19c868u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 128));
    // 0x19c86c: 0xc0664e0
    ctx->pc = 0x19C86Cu;
    SET_GPR_U32(ctx, 31, 0x19C874u);
    ctx->pc = 0x19C870u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 19712));
    ctx->pc = 0x199380u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199380_0x199380(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C874u; }
    }
    if (ctx->pc != 0x19C874u) { return; }
    ctx->pc = 0x19C874u;
    // 0x19c874: 0xc066734
    ctx->pc = 0x19C874u;
    SET_GPR_U32(ctx, 31, 0x19C87Cu);
    ctx->pc = 0x19C878u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 2), 192));
    ctx->pc = 0x199CD0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00199CD0_0x199cd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x19C87Cu; }
    }
    if (ctx->pc != 0x19C87Cu) { return; }
    ctx->pc = 0x19C87Cu;
    // 0x19c87c: 0x3c070029
    ctx->pc = 0x19c87cu;
    SET_GPR_U32(ctx, 7, ((uint32_t)41 << 16));
    // 0x19c880: 0x244600f0
    ctx->pc = 0x19c880u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 2), 240));
    // 0x19c884: 0x24e74cc0
    ctx->pc = 0x19c884u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 19648));
    // 0x19c888: 0x24050008
    ctx->pc = 0x19c888u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 8));
label_19c88c:
    // 0x19c88c: 0x8ce40000
    ctx->pc = 0x19c88cu;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x19c890: 0x24a5ffff
    ctx->pc = 0x19c890u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 5), 4294967295));
    // 0x19c894: 0x8ce30004
    ctx->pc = 0x19c894u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 7), 4)));
    // 0x19c898: 0xacc40000
    ctx->pc = 0x19c898u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 0), GPR_U32(ctx, 4));
    // 0x19c89c: 0x24e70008
    ctx->pc = 0x19c89cu;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 7), 8));
    // 0x19c8a0: 0xacc30004
    ctx->pc = 0x19c8a0u;
    WRITE32(ADD32(GPR_U32(ctx, 6), 4), GPR_U32(ctx, 3));
    // 0x19c8a4: 0x1ca0fff9
    ctx->pc = 0x19C8A4u;
    {
        const bool branch_taken_0x19c8a4 = (GPR_S32(ctx, 5) > 0);
        ctx->pc = 0x19C8A8u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 6), 8));
        if (branch_taken_0x19c8a4) {
            ctx->pc = 0x19C88Cu;
            goto label_19c88c;
        }
    }
    ctx->pc = 0x19C8ACu;
    // 0x19c8ac: 0x3c031500
    ctx->pc = 0x19c8acu;
    SET_GPR_U32(ctx, 3, ((uint32_t)5376 << 16));
    // 0x19c8b0: 0x2231825
    ctx->pc = 0x19c8b0u;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
    // 0x19c8b4: 0xac430130
    ctx->pc = 0x19c8b4u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 304), GPR_U32(ctx, 3));
    // 0x19c8b8: 0xac400134
    ctx->pc = 0x19c8b8u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 308), GPR_U32(ctx, 0));
    // 0x19c8bc: 0xac400138
    ctx->pc = 0x19c8bcu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 312), GPR_U32(ctx, 0));
    // 0x19c8c0: 0xac40013c
    ctx->pc = 0x19c8c0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 316), GPR_U32(ctx, 0));
    // 0x19c8c4: 0xdfbf0030
    ctx->pc = 0x19c8c4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x19c8c8: 0x7bb20020
    ctx->pc = 0x19c8c8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x19c8cc: 0x7bb10010
    ctx->pc = 0x19c8ccu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x19c8d0: 0x7bb00000
    ctx->pc = 0x19c8d0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x19c8d4: 0x3e00008
    ctx->pc = 0x19C8D4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x19C8D8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 128));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x199D00u: goto label_199d00;
            case 0x199D0Cu: goto label_199d0c;
            case 0x199D38u: goto label_199d38;
            case 0x19A8CCu: goto label_19a8cc;
            case 0x19AA84u: goto label_19aa84;
            case 0x19ADECu: goto label_19adec;
            case 0x19AE1Cu: goto label_19ae1c;
            case 0x19AE40u: goto label_19ae40;
            case 0x19AE8Cu: goto label_19ae8c;
            case 0x19B0B4u: goto label_19b0b4;
            case 0x19B2BCu: goto label_19b2bc;
            case 0x19B2ECu: goto label_19b2ec;
            case 0x19B31Cu: goto label_19b31c;
            case 0x19B340u: goto label_19b340;
            case 0x19B38Cu: goto label_19b38c;
            case 0x19B7ECu: goto label_19b7ec;
            case 0x19B81Cu: goto label_19b81c;
            case 0x19B840u: goto label_19b840;
            case 0x19B88Cu: goto label_19b88c;
            case 0x19BCFCu: goto label_19bcfc;
            case 0x19BD2Cu: goto label_19bd2c;
            case 0x19BD50u: goto label_19bd50;
            case 0x19BD9Cu: goto label_19bd9c;
            case 0x19C004u: goto label_19c004;
            case 0x19C1ECu: goto label_19c1ec;
            case 0x19C430u: goto label_19c430;
            case 0x19C5BCu: goto label_19c5bc;
            case 0x19C5ECu: goto label_19c5ec;
            case 0x19C610u: goto label_19c610;
            case 0x19C65Cu: goto label_19c65c;
            case 0x19C88Cu: goto label_19c88c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x19C8DCu;
    // 0x19c8dc: 0x0
    ctx->pc = 0x19c8dcu;
    // NOP
}
