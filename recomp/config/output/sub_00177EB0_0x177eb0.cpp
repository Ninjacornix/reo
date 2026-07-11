#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00177EB0
// Address: 0x177eb0 - 0x178318
void sub_00177EB0_0x177eb0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x177eb0u;

    // 0x177eb0: 0x27bdffc0
    ctx->pc = 0x177eb0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
    // 0x177eb4: 0x24030001
    ctx->pc = 0x177eb4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
    // 0x177eb8: 0xffb00000
    ctx->pc = 0x177eb8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x177ebc: 0x80802d
    ctx->pc = 0x177ebcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177ec0: 0xffb30018
    ctx->pc = 0x177ec0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x177ec4: 0xa0982d
    ctx->pc = 0x177ec4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177ec8: 0xffb50028
    ctx->pc = 0x177ec8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x177ecc: 0xc0a82d
    ctx->pc = 0x177eccu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177ed0: 0xffb60030
    ctx->pc = 0x177ed0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x177ed4: 0xffb10008
    ctx->pc = 0x177ed4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x177ed8: 0xffb20010
    ctx->pc = 0x177ed8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x177edc: 0xffb40020
    ctx->pc = 0x177edcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x177ee0: 0xffbf0038
    ctx->pc = 0x177ee0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
    // 0x177ee4: 0xdea20008
    ctx->pc = 0x177ee4u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 8)));
    // 0x177ee8: 0x10430004
    ctx->pc = 0x177EE8u;
    {
        const bool branch_taken_0x177ee8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 3));
        ctx->pc = 0x177EECu;
        SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x177ee8) {
            ctx->pc = 0x177EFCu;
            goto label_177efc;
        }
    }
    ctx->pc = 0x177EF0u;
    // 0x177ef0: 0x8e020000
    ctx->pc = 0x177ef0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x177ef4: 0x54400010
    ctx->pc = 0x177EF4u;
    {
        const bool branch_taken_0x177ef4 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x177ef4) {
            ctx->pc = 0x177EF8u;
            SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 19), 0)));
            ctx->pc = 0x177F38u;
            goto label_177f38;
        }
    }
    ctx->pc = 0x177EFCu;
label_177efc:
    // 0x177efc: 0xde620000
    ctx->pc = 0x177efcu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x177f00: 0xdfb00000
    ctx->pc = 0x177f00u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x177f04: 0xfec20000
    ctx->pc = 0x177f04u;
    WRITE64(ADD32(GPR_U32(ctx, 22), 0), GPR_U64(ctx, 2));
    // 0x177f08: 0xdfb10008
    ctx->pc = 0x177f08u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x177f0c: 0xde630008
    ctx->pc = 0x177f0cu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x177f10: 0xdfb20010
    ctx->pc = 0x177f10u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x177f14: 0xfec30008
    ctx->pc = 0x177f14u;
    WRITE64(ADD32(GPR_U32(ctx, 22), 8), GPR_U64(ctx, 3));
    // 0x177f18: 0xdfb30018
    ctx->pc = 0x177f18u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x177f1c: 0xdfb40020
    ctx->pc = 0x177f1cu;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x177f20: 0xdfb50028
    ctx->pc = 0x177f20u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x177f24: 0xdfb60030
    ctx->pc = 0x177f24u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x177f28: 0xdfbf0038
    ctx->pc = 0x177f28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x177f2c: 0x3e00008
    ctx->pc = 0x177F2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x177F30u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x177EFCu: goto label_177efc;
            case 0x177F38u: goto label_177f38;
            case 0x177F60u: goto label_177f60;
            case 0x177FA0u: goto label_177fa0;
            case 0x177FB0u: goto label_177fb0;
            case 0x177FE8u: goto label_177fe8;
            case 0x178000u: goto label_178000;
            case 0x178004u: goto label_178004;
            case 0x178008u: goto label_178008;
            case 0x178048u: goto label_178048;
            case 0x17804Cu: goto label_17804c;
            case 0x178080u: goto label_178080;
            case 0x17808Cu: goto label_17808c;
            case 0x1780A0u: goto label_1780a0;
            case 0x1780E8u: goto label_1780e8;
            case 0x1780FCu: goto label_1780fc;
            case 0x178128u: goto label_178128;
            case 0x178164u: goto label_178164;
            case 0x1781A0u: goto label_1781a0;
            case 0x1781C0u: goto label_1781c0;
            case 0x1781F8u: goto label_1781f8;
            case 0x1781FCu: goto label_1781fc;
            case 0x178200u: goto label_178200;
            case 0x17822Cu: goto label_17822c;
            case 0x178258u: goto label_178258;
            case 0x1782C8u: goto label_1782c8;
            case 0x1782E4u: goto label_1782e4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x177F34u;
    // 0x177f34: 0x0
    ctx->pc = 0x177f34u;
    // NOP
label_177f38:
    // 0x177f38: 0x24070001
    ctx->pc = 0x177f38u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 1));
    // 0x177f3c: 0xde020188
    ctx->pc = 0x177f3cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 16), 392)));
    // 0x177f40: 0x8e040004
    ctx->pc = 0x177f40u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x177f44: 0xa2182a
    ctx->pc = 0x177f44u;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 5), GPR_S32(ctx, 2)));
    // 0x177f48: 0x43280b
    ctx->pc = 0x177f48u;
    if (GPR_U32(ctx, 3) != 0) SET_GPR_U32(ctx, 5, GPR_U32(ctx, 2));
    // 0x177f4c: 0x14870004
    ctx->pc = 0x177F4Cu;
    {
        const bool branch_taken_0x177f4c = (GPR_U32(ctx, 4) != GPR_U32(ctx, 7));
        ctx->pc = 0x177F50u;
        WRITE64(ADD32(GPR_U32(ctx, 19), 0), GPR_U64(ctx, 5));
        if (branch_taken_0x177f4c) {
            ctx->pc = 0x177F60u;
            goto label_177f60;
        }
    }
    ctx->pc = 0x177F54u;
    // 0x177f54: 0xae000008
    ctx->pc = 0x177f54u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 0));
    // 0x177f58: 0x10000029
    ctx->pc = 0x177F58u;
    {
        const bool branch_taken_0x177f58 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x177F5Cu;
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x177f58) {
            ctx->pc = 0x178000u;
            goto label_178000;
        }
    }
    ctx->pc = 0x177F60u;
label_177f60:
    // 0x177f60: 0x8e120008
    ctx->pc = 0x177f60u;
    SET_GPR_U32(ctx, 18, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x177f64: 0x16400027
    ctx->pc = 0x177F64u;
    {
        const bool branch_taken_0x177f64 = (GPR_U32(ctx, 18) != GPR_U32(ctx, 0));
        ctx->pc = 0x177F68u;
        SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 16), 392)));
        if (branch_taken_0x177f64) {
            ctx->pc = 0x178004u;
            goto label_178004;
        }
    }
    ctx->pc = 0x177F6Cu;
    // 0x177f6c: 0xc5102a
    ctx->pc = 0x177f6cu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 6), GPR_S32(ctx, 5)));
    // 0x177f70: 0x5040001d
    ctx->pc = 0x177F70u;
    {
        const bool branch_taken_0x177f70 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x177f70) {
            ctx->pc = 0x177F74u;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 12)));
            ctx->pc = 0x177FE8u;
            goto label_177fe8;
        }
    }
    ctx->pc = 0x177F78u;
    // 0x177f78: 0xde030178
    ctx->pc = 0x177f78u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 376)));
    // 0x177f7c: 0x2402ffff
    ctx->pc = 0x177f7cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x177f80: 0x14620007
    ctx->pc = 0x177F80u;
    {
        const bool branch_taken_0x177f80 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x177F84u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 7));
        if (branch_taken_0x177f80) {
            ctx->pc = 0x177FA0u;
            goto label_177fa0;
        }
    }
    ctx->pc = 0x177F88u;
    // 0x177f88: 0xde050158
    ctx->pc = 0x177f88u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 344)));
    // 0x177f8c: 0xc043ea8
    ctx->pc = 0x177F8Cu;
    SET_GPR_U32(ctx, 31, 0x177F94u);
    ctx->pc = 0x177F90u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 19), 8)));
    ctx->pc = 0x10FAA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177F94u; }
    }
    if (ctx->pc != 0x177F94u) { return; }
    ctx->pc = 0x177F94u;
    // 0x177f94: 0x10000006
    ctx->pc = 0x177F94u;
    {
        const bool branch_taken_0x177f94 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x177F98u;
        SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 352)));
        if (branch_taken_0x177f94) {
            ctx->pc = 0x177FB0u;
            goto label_177fb0;
        }
    }
    ctx->pc = 0x177F9Cu;
    // 0x177f9c: 0x0
    ctx->pc = 0x177f9cu;
    // NOP
label_177fa0:
    // 0x177fa0: 0xde050168
    ctx->pc = 0x177fa0u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 360)));
    // 0x177fa4: 0xc043ea8
    ctx->pc = 0x177FA4u;
    SET_GPR_U32(ctx, 31, 0x177FACu);
    ctx->pc = 0x177FA8u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 19), 8)));
    ctx->pc = 0x10FAA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177FACu; }
    }
    if (ctx->pc != 0x177FACu) { return; }
    ctx->pc = 0x177FACu;
    // 0x177fac: 0xde050170
    ctx->pc = 0x177facu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 368)));
label_177fb0:
    // 0x177fb0: 0xc043ec6
    ctx->pc = 0x177FB0u;
    SET_GPR_U32(ctx, 31, 0x177FB8u);
    ctx->pc = 0x177FB4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10FB18u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177FB8u; }
    }
    if (ctx->pc != 0x177FB8u) { return; }
    ctx->pc = 0x177FB8u;
    // 0x177fb8: 0x40282d
    ctx->pc = 0x177fb8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177fbc: 0xdea30000
    ctx->pc = 0x177fbcu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x177fc0: 0x200202d
    ctx->pc = 0x177fc0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x177fc4: 0xfe030178
    ctx->pc = 0x177fc4u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 376), GPR_U64(ctx, 3));
    // 0x177fc8: 0xde620000
    ctx->pc = 0x177fc8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x177fcc: 0x45102d
    ctx->pc = 0x177fccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 5));
    // 0x177fd0: 0xc05df64
    ctx->pc = 0x177FD0u;
    SET_GPR_U32(ctx, 31, 0x177FD8u);
    ctx->pc = 0x177FD4u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 384), GPR_U64(ctx, 2));
    ctx->pc = 0x177D90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00177D90_0x177d90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x177FD8u; }
    }
    if (ctx->pc != 0x177FD8u) { return; }
    ctx->pc = 0x177FD8u;
    // 0x177fd8: 0xde060188
    ctx->pc = 0x177fd8u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 16), 392)));
    // 0x177fdc: 0x10000009
    ctx->pc = 0x177FDCu;
    {
        const bool branch_taken_0x177fdc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x177FE0u;
        SET_GPR_U32(ctx, 18, READ32(ADD32(GPR_U32(ctx, 16), 8)));
        if (branch_taken_0x177fdc) {
            ctx->pc = 0x178004u;
            goto label_178004;
        }
    }
    ctx->pc = 0x177FE4u;
    // 0x177fe4: 0x0
    ctx->pc = 0x177fe4u;
    // NOP
label_177fe8:
    // 0x177fe8: 0x54400007
    ctx->pc = 0x177FE8u;
    {
        const bool branch_taken_0x177fe8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x177fe8) {
            ctx->pc = 0x177FECu;
            SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
            ctx->pc = 0x178008u;
            goto label_178008;
        }
    }
    ctx->pc = 0x177FF0u;
    // 0x177ff0: 0xae070008
    ctx->pc = 0x177ff0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 8), GPR_U32(ctx, 7));
    // 0x177ff4: 0x10000003
    ctx->pc = 0x177FF4u;
    {
        const bool branch_taken_0x177ff4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x177FF8u;
        SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 0), 1));
        if (branch_taken_0x177ff4) {
            ctx->pc = 0x178004u;
            goto label_178004;
        }
    }
    ctx->pc = 0x177FFCu;
    // 0x177ffc: 0x0
    ctx->pc = 0x177ffcu;
    // NOP
label_178000:
    // 0x178000: 0xde060188
    ctx->pc = 0x178000u;
    SET_GPR_U64(ctx, 6, READ64(ADD32(GPR_U32(ctx, 16), 392)));
label_178004:
    // 0x178004: 0xde620000
    ctx->pc = 0x178004u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
label_178008:
    // 0x178008: 0x2404ffff
    ctx->pc = 0x178008u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x17800c: 0xde110178
    ctx->pc = 0x17800cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 16), 376)));
    // 0x178010: 0x46182a
    ctx->pc = 0x178010u;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 2), GPR_S32(ctx, 6)));
    // 0x178014: 0xc3100b
    ctx->pc = 0x178014u;
    if (GPR_U32(ctx, 3) != 0) SET_GPR_U32(ctx, 2, GPR_U32(ctx, 6));
    // 0x178018: 0x1224000b
    ctx->pc = 0x178018u;
    {
        const bool branch_taken_0x178018 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 4));
        ctx->pc = 0x17801Cu;
        WRITE64(ADD32(GPR_U32(ctx, 16), 392), GPR_U64(ctx, 2));
        if (branch_taken_0x178018) {
            ctx->pc = 0x178048u;
            goto label_178048;
        }
    }
    ctx->pc = 0x178020u;
    // 0x178020: 0xdea50000
    ctx->pc = 0x178020u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x178024: 0xde640008
    ctx->pc = 0x178024u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x178028: 0xc043ea8
    ctx->pc = 0x178028u;
    SET_GPR_U32(ctx, 31, 0x178030u);
    ctx->pc = 0x17802Cu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) - GPR_U64(ctx, 17));
    ctx->pc = 0x10FAA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178030u; }
    }
    if (ctx->pc != 0x178030u) { return; }
    ctx->pc = 0x178030u;
    // 0x178030: 0xdea50008
    ctx->pc = 0x178030u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 21), 8)));
    // 0x178034: 0xc043ec6
    ctx->pc = 0x178034u;
    SET_GPR_U32(ctx, 31, 0x17803Cu);
    ctx->pc = 0x178038u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10FB18u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17803Cu; }
    }
    if (ctx->pc != 0x17803Cu) { return; }
    ctx->pc = 0x17803Cu;
    // 0x17803c: 0xde030180
    ctx->pc = 0x17803cu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 384)));
    // 0x178040: 0x10000002
    ctx->pc = 0x178040u;
    {
        const bool branch_taken_0x178040 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x178044u;
        SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 2));
        if (branch_taken_0x178040) {
            ctx->pc = 0x17804Cu;
            goto label_17804c;
        }
    }
    ctx->pc = 0x178048u;
label_178048:
    // 0x178048: 0xa02d
    ctx->pc = 0x178048u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_17804c:
    // 0x17804c: 0x56400014
    ctx->pc = 0x17804Cu;
    {
        const bool branch_taken_0x17804c = (GPR_U32(ctx, 18) != GPR_U32(ctx, 0));
        if (branch_taken_0x17804c) {
            ctx->pc = 0x178050u;
            SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 12)));
            ctx->pc = 0x1780A0u;
            goto label_1780a0;
        }
    }
    ctx->pc = 0x178054u;
    // 0x178054: 0xde030188
    ctx->pc = 0x178054u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 392)));
    // 0x178058: 0x74102a
    ctx->pc = 0x178058u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 3), GPR_S32(ctx, 20)));
    // 0x17805c: 0x10400068
    ctx->pc = 0x17805Cu;
    {
        const bool branch_taken_0x17805c = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x178060u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x17805c) {
            ctx->pc = 0x178200u;
            goto label_178200;
        }
    }
    ctx->pc = 0x178064u;
    // 0x178064: 0x8e02000c
    ctx->pc = 0x178064u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 12)));
    // 0x178068: 0x10400005
    ctx->pc = 0x178068u;
    {
        const bool branch_taken_0x178068 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x17806Cu;
        SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 0)));
        if (branch_taken_0x178068) {
            ctx->pc = 0x178080u;
            goto label_178080;
        }
    }
    ctx->pc = 0x178070u;
    // 0x178070: 0xfe030180
    ctx->pc = 0x178070u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 384), GPR_U64(ctx, 3));
    // 0x178074: 0x10000005
    ctx->pc = 0x178074u;
    {
        const bool branch_taken_0x178074 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x178078u;
        WRITE64(ADD32(GPR_U32(ctx, 16), 376), GPR_U64(ctx, 2));
        if (branch_taken_0x178074) {
            ctx->pc = 0x17808Cu;
            goto label_17808c;
        }
    }
    ctx->pc = 0x17807Cu;
    // 0x17807c: 0x0
    ctx->pc = 0x17807cu;
    // NOP
label_178080:
    // 0x178080: 0xde030128
    ctx->pc = 0x178080u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 296)));
    // 0x178084: 0xfe020178
    ctx->pc = 0x178084u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 376), GPR_U64(ctx, 2));
    // 0x178088: 0xfe030180
    ctx->pc = 0x178088u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 384), GPR_U64(ctx, 3));
label_17808c:
    // 0x17808c: 0x8e020190
    ctx->pc = 0x17808cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 400)));
    // 0x178090: 0xde110178
    ctx->pc = 0x178090u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 16), 376)));
    // 0x178094: 0x24420001
    ctx->pc = 0x178094u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x178098: 0x10000058
    ctx->pc = 0x178098u;
    {
        const bool branch_taken_0x178098 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x17809Cu;
        WRITE32(ADD32(GPR_U32(ctx, 16), 400), GPR_U32(ctx, 2));
        if (branch_taken_0x178098) {
            ctx->pc = 0x1781FCu;
            goto label_1781fc;
        }
    }
    ctx->pc = 0x1780A0u;
label_1780a0:
    // 0x1780a0: 0x24020001
    ctx->pc = 0x1780a0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
    // 0x1780a4: 0x14620056
    ctx->pc = 0x1780A4u;
    {
        const bool branch_taken_0x1780a4 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        ctx->pc = 0x1780A8u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x1780a4) {
            ctx->pc = 0x178200u;
            goto label_178200;
        }
    }
    ctx->pc = 0x1780ACu;
    // 0x1780ac: 0xde050148
    ctx->pc = 0x1780acu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 328)));
    // 0x1780b0: 0xc043ea8
    ctx->pc = 0x1780B0u;
    SET_GPR_U32(ctx, 31, 0x1780B8u);
    ctx->pc = 0x1780B4u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 19), 8)));
    ctx->pc = 0x10FAA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1780B8u; }
    }
    if (ctx->pc != 0x1780B8u) { return; }
    ctx->pc = 0x1780B8u;
    // 0x1780b8: 0xde050150
    ctx->pc = 0x1780b8u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 336)));
    // 0x1780bc: 0xc043ec6
    ctx->pc = 0x1780BCu;
    SET_GPR_U32(ctx, 31, 0x1780C4u);
    ctx->pc = 0x1780C0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10FB18u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1780C4u; }
    }
    if (ctx->pc != 0x1780C4u) { return; }
    ctx->pc = 0x1780C4u;
    // 0x1780c4: 0xde650000
    ctx->pc = 0x1780c4u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1780c8: 0x40182d
    ctx->pc = 0x1780c8u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1780cc: 0xb4102f
    ctx->pc = 0x1780ccu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 5) - GPR_U64(ctx, 20));
    // 0x1780d0: 0x4400005
    ctx->pc = 0x1780D0u;
    {
        const bool branch_taken_0x1780d0 = (GPR_S32(ctx, 2) < 0);
        ctx->pc = 0x1780D4u;
        SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 3), GPR_S32(ctx, 2)));
        if (branch_taken_0x1780d0) {
            ctx->pc = 0x1780E8u;
            goto label_1780e8;
        }
    }
    ctx->pc = 0x1780D8u;
    // 0x1780d8: 0x54400008
    ctx->pc = 0x1780D8u;
    {
        const bool branch_taken_0x1780d8 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 0));
        if (branch_taken_0x1780d8) {
            ctx->pc = 0x1780DCu;
            SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 0)));
            ctx->pc = 0x1780FCu;
            goto label_1780fc;
        }
    }
    ctx->pc = 0x1780E0u;
    // 0x1780e0: 0x10000011
    ctx->pc = 0x1780E0u;
    {
        const bool branch_taken_0x1780e0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1780E4u;
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) - GPR_U64(ctx, 20));
        if (branch_taken_0x1780e0) {
            ctx->pc = 0x178128u;
            goto label_178128;
        }
    }
    ctx->pc = 0x1780E8u;
label_1780e8:
    // 0x1780e8: 0x285102f
    ctx->pc = 0x1780e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 20) - GPR_U64(ctx, 5));
    // 0x1780ec: 0x62102a
    ctx->pc = 0x1780ecu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 3), GPR_S32(ctx, 2)));
    // 0x1780f0: 0x1040000d
    ctx->pc = 0x1780F0u;
    {
        const bool branch_taken_0x1780f0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x1780F4u;
        SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) - GPR_U64(ctx, 20));
        if (branch_taken_0x1780f0) {
            ctx->pc = 0x178128u;
            goto label_178128;
        }
    }
    ctx->pc = 0x1780F8u;
    // 0x1780f8: 0xdea20000
    ctx->pc = 0x1780f8u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 0)));
label_1780fc:
    // 0x1780fc: 0x200202d
    ctx->pc = 0x1780fcu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178100: 0xfe020178
    ctx->pc = 0x178100u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 376), GPR_U64(ctx, 2));
    // 0x178104: 0xde630000
    ctx->pc = 0x178104u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x178108: 0xc05df64
    ctx->pc = 0x178108u;
    SET_GPR_U32(ctx, 31, 0x178110u);
    ctx->pc = 0x17810Cu;
    WRITE64(ADD32(GPR_U32(ctx, 16), 384), GPR_U64(ctx, 3));
    ctx->pc = 0x177D90u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00177D90_0x177d90(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178110u; }
    }
    if (ctx->pc != 0x178110u) { return; }
    ctx->pc = 0x178110u;
    // 0x178110: 0x8e0201a0
    ctx->pc = 0x178110u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 416)));
    // 0x178114: 0x8e120008
    ctx->pc = 0x178114u;
    SET_GPR_U32(ctx, 18, READ32(ADD32(GPR_U32(ctx, 16), 8)));
    // 0x178118: 0x24420001
    ctx->pc = 0x178118u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
    // 0x17811c: 0xde110178
    ctx->pc = 0x17811cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 16), 376)));
    // 0x178120: 0x10000036
    ctx->pc = 0x178120u;
    {
        const bool branch_taken_0x178120 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x178124u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 416), GPR_U32(ctx, 2));
        if (branch_taken_0x178120) {
            ctx->pc = 0x1781FCu;
            goto label_1781fc;
        }
    }
    ctx->pc = 0x178128u;
label_178128:
    // 0x178128: 0x5283c
    ctx->pc = 0x178128u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x17812c: 0x5283f
    ctx->pc = 0x17812cu;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x178130: 0xc05e0c6
    ctx->pc = 0x178130u;
    SET_GPR_U32(ctx, 31, 0x178138u);
    ctx->pc = 0x178134u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x178318u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00178318_0x178318(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178138u; }
    }
    if (ctx->pc != 0x178138u) { return; }
    ctx->pc = 0x178138u;
    // 0x178138: 0xde640008
    ctx->pc = 0x178138u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x17813c: 0xde050138
    ctx->pc = 0x17813cu;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 312)));
    // 0x178140: 0xc043ea8
    ctx->pc = 0x178140u;
    SET_GPR_U32(ctx, 31, 0x178148u);
    ctx->pc = 0x178144u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10FAA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178148u; }
    }
    if (ctx->pc != 0x178148u) { return; }
    ctx->pc = 0x178148u;
    // 0x178148: 0xde050140
    ctx->pc = 0x178148u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 16), 320)));
    // 0x17814c: 0xc043ec6
    ctx->pc = 0x17814Cu;
    SET_GPR_U32(ctx, 31, 0x178154u);
    ctx->pc = 0x178150u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10FB18u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178154u; }
    }
    if (ctx->pc != 0x178154u) { return; }
    ctx->pc = 0x178154u;
    // 0x178154: 0x40902d
    ctx->pc = 0x178154u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x178158: 0x6210002
    ctx->pc = 0x178158u;
    {
        const bool branch_taken_0x178158 = (GPR_S32(ctx, 17) >= 0);
        ctx->pc = 0x17815Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x178158) {
            ctx->pc = 0x178164u;
            goto label_178164;
        }
    }
    ctx->pc = 0x178160u;
    // 0x178160: 0x2102f
    ctx->pc = 0x178160u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 0) - GPR_U64(ctx, 2));
label_178164:
    // 0x178164: 0x242102a
    ctx->pc = 0x178164u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 18), GPR_S32(ctx, 2)));
    // 0x178168: 0x50400023
    ctx->pc = 0x178168u;
    {
        const bool branch_taken_0x178168 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x178168) {
            ctx->pc = 0x17816Cu;
            SET_GPR_U32(ctx, 18, READ32(ADD32(GPR_U32(ctx, 16), 8)));
            ctx->pc = 0x1781F8u;
            goto label_1781f8;
        }
    }
    ctx->pc = 0x178170u;
    // 0x178170: 0x251102a
    ctx->pc = 0x178170u;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 18), GPR_S32(ctx, 17)));
    // 0x178174: 0x1040000a
    ctx->pc = 0x178174u;
    {
        const bool branch_taken_0x178174 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x178178u;
        SET_GPR_U64(ctx, 4, GPR_U64(ctx, 17) << 1);
        if (branch_taken_0x178174) {
            ctx->pc = 0x1781A0u;
            goto label_1781a0;
        }
    }
    ctx->pc = 0x17817Cu;
    // 0x17817c: 0xc043ec6
    ctx->pc = 0x17817Cu;
    SET_GPR_U32(ctx, 31, 0x178184u);
    ctx->pc = 0x178180u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10FB18u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178184u; }
    }
    if (ctx->pc != 0x178184u) { return; }
    ctx->pc = 0x178184u;
    // 0x178184: 0x8e030194
    ctx->pc = 0x178184u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 404)));
    // 0x178188: 0x6444ffff
    ctx->pc = 0x178188u;
    SET_GPR_S64(ctx, 4, (int64_t)GPR_S64(ctx, 2) + (int64_t)4294967295);
    // 0x17818c: 0x4103c
    ctx->pc = 0x17818cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) << (32 + 0));
    // 0x178190: 0x2103f
    ctx->pc = 0x178190u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x178194: 0x621821
    ctx->pc = 0x178194u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x178198: 0x10000009
    ctx->pc = 0x178198u;
    {
        const bool branch_taken_0x178198 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x17819Cu;
        WRITE32(ADD32(GPR_U32(ctx, 16), 404), GPR_U32(ctx, 3));
        if (branch_taken_0x178198) {
            ctx->pc = 0x1781C0u;
            goto label_1781c0;
        }
    }
    ctx->pc = 0x1781A0u;
label_1781a0:
    // 0x1781a0: 0xc043ec6
    ctx->pc = 0x1781A0u;
    SET_GPR_U32(ctx, 31, 0x1781A8u);
    ctx->pc = 0x1781A4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10FB18u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1781A8u; }
    }
    if (ctx->pc != 0x1781A8u) { return; }
    ctx->pc = 0x1781A8u;
    // 0x1781a8: 0x8e030198
    ctx->pc = 0x1781a8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 408)));
    // 0x1781ac: 0x64440001
    ctx->pc = 0x1781acu;
    SET_GPR_S64(ctx, 4, (int64_t)GPR_S64(ctx, 2) + (int64_t)1);
    // 0x1781b0: 0x4103c
    ctx->pc = 0x1781b0u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 4) << (32 + 0));
    // 0x1781b4: 0x2103f
    ctx->pc = 0x1781b4u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 0));
    // 0x1781b8: 0x621823
    ctx->pc = 0x1781b8u;
    SET_GPR_U32(ctx, 3, SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
    // 0x1781bc: 0xae030198
    ctx->pc = 0x1781bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 408), GPR_U32(ctx, 3));
label_1781c0:
    // 0x1781c0: 0xc043ea8
    ctx->pc = 0x1781C0u;
    SET_GPR_U32(ctx, 31, 0x1781C8u);
    ctx->pc = 0x1781C4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10FAA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1781C8u; }
    }
    if (ctx->pc != 0x1781C8u) { return; }
    ctx->pc = 0x1781C8u;
    // 0x1781c8: 0xdea30000
    ctx->pc = 0x1781c8u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1781cc: 0x22ffe
    ctx->pc = 0x1781ccu;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 2) >> (32 + 31));
    // 0x1781d0: 0x200202d
    ctx->pc = 0x1781d0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1781d4: 0xa2282d
    ctx->pc = 0x1781d4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 2));
    // 0x1781d8: 0xfe030178
    ctx->pc = 0x1781d8u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 376), GPR_U64(ctx, 3));
    // 0x1781dc: 0x5287b
    ctx->pc = 0x1781dcu;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> 1);
    // 0x1781e0: 0x285102d
    ctx->pc = 0x1781e0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 5));
    // 0x1781e4: 0x5283c
    ctx->pc = 0x1781e4u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) << (32 + 0));
    // 0x1781e8: 0x5283f
    ctx->pc = 0x1781e8u;
    SET_GPR_S64(ctx, 5, GPR_S64(ctx, 5) >> (32 + 0));
    // 0x1781ec: 0xc05e0de
    ctx->pc = 0x1781ECu;
    SET_GPR_U32(ctx, 31, 0x1781F4u);
    ctx->pc = 0x1781F0u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 384), GPR_U64(ctx, 2));
    ctx->pc = 0x178378u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00178378_0x178378(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1781F4u; }
    }
    if (ctx->pc != 0x1781F4u) { return; }
    ctx->pc = 0x1781F4u;
    // 0x1781f4: 0x8e120008
    ctx->pc = 0x1781f4u;
    SET_GPR_U32(ctx, 18, READ32(ADD32(GPR_U32(ctx, 16), 8)));
label_1781f8:
    // 0x1781f8: 0xde110178
    ctx->pc = 0x1781f8u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 16), 376)));
label_1781fc:
    // 0x1781fc: 0x2402ffff
    ctx->pc = 0x1781fcu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
label_178200:
    // 0x178200: 0x5222000a
    ctx->pc = 0x178200u;
    {
        const bool branch_taken_0x178200 = (GPR_U32(ctx, 17) == GPR_U32(ctx, 2));
        if (branch_taken_0x178200) {
            ctx->pc = 0x178204u;
            SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
            ctx->pc = 0x17822Cu;
            goto label_17822c;
        }
    }
    ctx->pc = 0x178208u;
    // 0x178208: 0xdea50000
    ctx->pc = 0x178208u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x17820c: 0xde640008
    ctx->pc = 0x17820cu;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x178210: 0xc043ea8
    ctx->pc = 0x178210u;
    SET_GPR_U32(ctx, 31, 0x178218u);
    ctx->pc = 0x178214u;
    SET_GPR_U64(ctx, 5, GPR_U64(ctx, 5) - GPR_U64(ctx, 17));
    ctx->pc = 0x10FAA0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FAA0_0x10faa0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178218u; }
    }
    if (ctx->pc != 0x178218u) { return; }
    ctx->pc = 0x178218u;
    // 0x178218: 0xdea50008
    ctx->pc = 0x178218u;
    SET_GPR_U64(ctx, 5, READ64(ADD32(GPR_U32(ctx, 21), 8)));
    // 0x17821c: 0xc043ec6
    ctx->pc = 0x17821Cu;
    SET_GPR_U32(ctx, 31, 0x178224u);
    ctx->pc = 0x178220u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x10FB18u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0010FB18_0x10fb18(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x178224u; }
    }
    if (ctx->pc != 0x178224u) { return; }
    ctx->pc = 0x178224u;
    // 0x178224: 0xde030180
    ctx->pc = 0x178224u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 16), 384)));
    // 0x178228: 0x62182d
    ctx->pc = 0x178228u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 3) + (uint64_t)GPR_U64(ctx, 2));
label_17822c:
    // 0x17822c: 0xfec30000
    ctx->pc = 0x17822cu;
    WRITE64(ADD32(GPR_U32(ctx, 22), 0), GPR_U64(ctx, 3));
    // 0x178230: 0xde620008
    ctx->pc = 0x178230u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x178234: 0xfec20008
    ctx->pc = 0x178234u;
    WRITE64(ADD32(GPR_U32(ctx, 22), 8), GPR_U64(ctx, 2));
    // 0x178238: 0xde040128
    ctx->pc = 0x178238u;
    SET_GPR_U64(ctx, 4, READ64(ADD32(GPR_U32(ctx, 16), 296)));
    // 0x17823c: 0x64102a
    ctx->pc = 0x17823cu;
    SET_GPR_U32(ctx, 2, SLT32(GPR_S32(ctx, 3), GPR_S32(ctx, 4)));
    // 0x178240: 0x50400005
    ctx->pc = 0x178240u;
    {
        const bool branch_taken_0x178240 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x178240) {
            ctx->pc = 0x178244u;
            SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
            ctx->pc = 0x178258u;
            goto label_178258;
        }
    }
    ctx->pc = 0x178248u;
    // 0x178248: 0xfec40000
    ctx->pc = 0x178248u;
    WRITE64(ADD32(GPR_U32(ctx, 22), 0), GPR_U64(ctx, 4));
    // 0x17824c: 0xde020130
    ctx->pc = 0x17824cu;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 16), 304)));
    // 0x178250: 0xfec20008
    ctx->pc = 0x178250u;
    WRITE64(ADD32(GPR_U32(ctx, 22), 8), GPR_U64(ctx, 2));
    // 0x178254: 0xde620000
    ctx->pc = 0x178254u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
label_178258:
    // 0x178258: 0xfe020108
    ctx->pc = 0x178258u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 264), GPR_U64(ctx, 2));
    // 0x17825c: 0xde630008
    ctx->pc = 0x17825cu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 19), 8)));
    // 0x178260: 0xfe030110
    ctx->pc = 0x178260u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 272), GPR_U64(ctx, 3));
    // 0x178264: 0xdea20000
    ctx->pc = 0x178264u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x178268: 0xfe020118
    ctx->pc = 0x178268u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 280), GPR_U64(ctx, 2));
    // 0x17826c: 0xdea30008
    ctx->pc = 0x17826cu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 21), 8)));
    // 0x178270: 0xfe030120
    ctx->pc = 0x178270u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 288), GPR_U64(ctx, 3));
    // 0x178274: 0xdec20000
    ctx->pc = 0x178274u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x178278: 0xfe020128
    ctx->pc = 0x178278u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 296), GPR_U64(ctx, 2));
    // 0x17827c: 0xdec30008
    ctx->pc = 0x17827cu;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 22), 8)));
    // 0x178280: 0xfe030130
    ctx->pc = 0x178280u;
    WRITE64(ADD32(GPR_U32(ctx, 16), 304), GPR_U64(ctx, 3));
    // 0x178284: 0xde620000
    ctx->pc = 0x178284u;
    SET_GPR_U64(ctx, 2, READ64(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x178288: 0xdec30000
    ctx->pc = 0x178288u;
    SET_GPR_U64(ctx, 3, READ64(ADD32(GPR_U32(ctx, 22), 0)));
    // 0x17828c: 0x43102f
    ctx->pc = 0x17828cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) - GPR_U64(ctx, 3));
    // 0x178290: 0x2383c
    ctx->pc = 0x178290u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 2) << (32 + 0));
    // 0x178294: 0x7383f
    ctx->pc = 0x178294u;
    SET_GPR_S64(ctx, 7, GPR_S64(ctx, 7) >> (32 + 0));
    // 0x178298: 0x5640000b
    ctx->pc = 0x178298u;
    {
        const bool branch_taken_0x178298 = (GPR_U32(ctx, 18) != GPR_U32(ctx, 0));
        if (branch_taken_0x178298) {
            ctx->pc = 0x17829Cu;
            SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 436)));
            ctx->pc = 0x1782C8u;
            goto label_1782c8;
        }
    }
    ctx->pc = 0x1782A0u;
    // 0x1782a0: 0x8e0201ac
    ctx->pc = 0x1782a0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 428)));
    // 0x1782a4: 0x8e0301b0
    ctx->pc = 0x1782a4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 432)));
    // 0x1782a8: 0xe2202a
    ctx->pc = 0x1782a8u;
    SET_GPR_U32(ctx, 4, SLT32(GPR_S32(ctx, 7), GPR_S32(ctx, 2)));
    // 0x1782ac: 0x67282a
    ctx->pc = 0x1782acu;
    SET_GPR_U32(ctx, 5, SLT32(GPR_S32(ctx, 3), GPR_S32(ctx, 7)));
    // 0x1782b0: 0xe4100a
    ctx->pc = 0x1782b0u;
    if (GPR_U32(ctx, 4) == 0) SET_GPR_U32(ctx, 2, GPR_U32(ctx, 7));
    // 0x1782b4: 0xe5180a
    ctx->pc = 0x1782b4u;
    if (GPR_U32(ctx, 5) == 0) SET_GPR_U32(ctx, 3, GPR_U32(ctx, 7));
    // 0x1782b8: 0xae0201ac
    ctx->pc = 0x1782b8u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 428), GPR_U32(ctx, 2));
    // 0x1782bc: 0x10000009
    ctx->pc = 0x1782BCu;
    {
        const bool branch_taken_0x1782bc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x1782C0u;
        WRITE32(ADD32(GPR_U32(ctx, 16), 432), GPR_U32(ctx, 3));
        if (branch_taken_0x1782bc) {
            ctx->pc = 0x1782E4u;
            goto label_1782e4;
        }
    }
    ctx->pc = 0x1782C4u;
    // 0x1782c4: 0x0
    ctx->pc = 0x1782c4u;
    // NOP
label_1782c8:
    // 0x1782c8: 0x8e0301b8
    ctx->pc = 0x1782c8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 440)));
    // 0x1782cc: 0xe2202a
    ctx->pc = 0x1782ccu;
    SET_GPR_U32(ctx, 4, SLT32(GPR_S32(ctx, 7), GPR_S32(ctx, 2)));
    // 0x1782d0: 0x67282a
    ctx->pc = 0x1782d0u;
    SET_GPR_U32(ctx, 5, SLT32(GPR_S32(ctx, 3), GPR_S32(ctx, 7)));
    // 0x1782d4: 0xe4100a
    ctx->pc = 0x1782d4u;
    if (GPR_U32(ctx, 4) == 0) SET_GPR_U32(ctx, 2, GPR_U32(ctx, 7));
    // 0x1782d8: 0xe5180a
    ctx->pc = 0x1782d8u;
    if (GPR_U32(ctx, 5) == 0) SET_GPR_U32(ctx, 3, GPR_U32(ctx, 7));
    // 0x1782dc: 0xae0201b4
    ctx->pc = 0x1782dcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 436), GPR_U32(ctx, 2));
    // 0x1782e0: 0xae0301b8
    ctx->pc = 0x1782e0u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 440), GPR_U32(ctx, 3));
label_1782e4:
    // 0x1782e4: 0x3c020023
    ctx->pc = 0x1782e4u;
    SET_GPR_U32(ctx, 2, ((uint32_t)35 << 16));
    // 0x1782e8: 0x200202d
    ctx->pc = 0x1782e8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1782ec: 0xac50f1e0
    ctx->pc = 0x1782ecu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294963680), GPR_U32(ctx, 16));
    // 0x1782f0: 0xdfb10008
    ctx->pc = 0x1782f0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1782f4: 0xdfb00000
    ctx->pc = 0x1782f4u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1782f8: 0xdfb20010
    ctx->pc = 0x1782f8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1782fc: 0xdfb30018
    ctx->pc = 0x1782fcu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x178300: 0xdfb40020
    ctx->pc = 0x178300u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x178304: 0xdfb50028
    ctx->pc = 0x178304u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x178308: 0xdfb60030
    ctx->pc = 0x178308u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17830c: 0xdfbf0038
    ctx->pc = 0x17830cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x178310: 0x805e168
    ctx->pc = 0x178310u;
    ctx->pc = 0x178314u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
    ctx->pc = 0x1785A0u;
    entry_1785a0_0x178910(rdram, ctx, runtime); return;
    ctx->pc = 0x178318u;
}
