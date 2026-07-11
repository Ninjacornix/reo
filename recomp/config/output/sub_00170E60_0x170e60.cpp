#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00170E60
// Address: 0x170e60 - 0x171060
void sub_00170E60_0x170e60(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x170e60u;

    // 0x170e60: 0x27bdffb0
    ctx->pc = 0x170e60u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x170e64: 0xffb10008
    ctx->pc = 0x170e64u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x170e68: 0x80882d
    ctx->pc = 0x170e68u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170e6c: 0xffb70038
    ctx->pc = 0x170e6cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 23));
    // 0x170e70: 0xb82d
    ctx->pc = 0x170e70u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170e74: 0xffb00000
    ctx->pc = 0x170e74u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x170e78: 0xffb20010
    ctx->pc = 0x170e78u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x170e7c: 0xffb30018
    ctx->pc = 0x170e7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 19));
    // 0x170e80: 0xffb40020
    ctx->pc = 0x170e80u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 20));
    // 0x170e84: 0xffb50028
    ctx->pc = 0x170e84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 21));
    // 0x170e88: 0xffb60030
    ctx->pc = 0x170e88u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 22));
    // 0x170e8c: 0xffbf0040
    ctx->pc = 0x170e8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
    // 0x170e90: 0xc045198
    ctx->pc = 0x170E90u;
    SET_GPR_U32(ctx, 31, 0x170E98u);
    ctx->pc = 0x170E94u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 64)));
    ctx->pc = 0x114660u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114660_0x114660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170E98u; }
    }
    if (ctx->pc != 0x170E98u) { return; }
    ctx->pc = 0x170E98u;
    // 0x170e98: 0x8e230044
    ctx->pc = 0x170e98u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 68)));
    // 0x170e9c: 0x14600006
    ctx->pc = 0x170E9Cu;
    {
        const bool branch_taken_0x170e9c = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        if (branch_taken_0x170e9c) {
            ctx->pc = 0x170EB8u;
            goto label_170eb8;
        }
    }
    ctx->pc = 0x170EA4u;
    // 0x170ea4: 0xc045190
    ctx->pc = 0x170EA4u;
    SET_GPR_U32(ctx, 31, 0x170EACu);
    ctx->pc = 0x170EA8u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 64)));
    ctx->pc = 0x114640u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170EACu; }
    }
    if (ctx->pc != 0x170EACu) { return; }
    ctx->pc = 0x170EACu;
    // 0x170eac: 0x10000060
    ctx->pc = 0x170EACu;
    {
        const bool branch_taken_0x170eac = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x170EB0u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x170eac) {
            ctx->pc = 0x171030u;
            goto label_171030;
        }
    }
    ctx->pc = 0x170EB4u;
    // 0x170eb4: 0x0
    ctx->pc = 0x170eb4u;
    // NOP
label_170eb8:
    // 0x170eb8: 0xc05c296
    ctx->pc = 0x170EB8u;
    SET_GPR_U32(ctx, 31, 0x170EC0u);
    ctx->pc = 0x170EBCu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 5));
    ctx->pc = 0x170A58u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00170A58_0x170a58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170EC0u; }
    }
    if (ctx->pc != 0x170EC0u) { return; }
    ctx->pc = 0x170EC0u;
    // 0x170ec0: 0x3c021000
    ctx->pc = 0x170ec0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)4096 << 16));
    // 0x170ec4: 0x3c031000
    ctx->pc = 0x170ec4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)4096 << 16));
    // 0x170ec8: 0x3442b400
    ctx->pc = 0x170ec8u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 46080));
    // 0x170ecc: 0x3463b410
    ctx->pc = 0x170eccu;
    SET_GPR_U32(ctx, 3, OR32(GPR_U32(ctx, 3), 46096));
    // 0x170ed0: 0x8c550000
    ctx->pc = 0x170ed0u;
    SET_GPR_U32(ctx, 21, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 2), 0))); // MMIO: 0x10000000
    // 0x170ed4: 0x8c650000
    ctx->pc = 0x170ed4u;
    SET_GPR_U32(ctx, 5, runtime->Load32(rdram, ctx, ADD32(GPR_U32(ctx, 3), 0))); // MMIO: 0x10000000
    // 0x170ed8: 0xc05c268
    ctx->pc = 0x170ED8u;
    SET_GPR_U32(ctx, 31, 0x170EE0u);
    ctx->pc = 0x170EDCu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1709A0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001709A0_0x1709a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170EE0u; }
    }
    if (ctx->pc != 0x170EE0u) { return; }
    ctx->pc = 0x170EE0u;
    // 0x170ee0: 0x8e260008
    ctx->pc = 0x170ee0u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x170ee4: 0x8e23000c
    ctx->pc = 0x170ee4u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 12)));
    // 0x170ee8: 0x461021
    ctx->pc = 0x170ee8u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x170eec: 0x50c00001
    ctx->pc = 0x170EECu;
    {
        const bool branch_taken_0x170eec = (GPR_U32(ctx, 6) == GPR_U32(ctx, 0));
        if (branch_taken_0x170eec) {
            ctx->pc = 0x170EF0u;
            runtime->handleBreak(rdram, ctx);
            ctx->pc = 0x170EF4u;
            goto label_170ef4;
        }
    }
    ctx->pc = 0x170EF4u;
label_170ef4:
    // 0x170ef4: 0x431023
    ctx->pc = 0x170ef4u;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x170ef8: 0x46001a
    ctx->pc = 0x170ef8u;
    { int32_t divisor = GPR_S32(ctx, 6);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint32_t)(dividend / divisor);            ctx->hi = (uint32_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1 : -1; ctx->hi = dividend;    } }
    // 0x170efc: 0x8e220010
    ctx->pc = 0x170efcu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x170f00: 0x2010
    ctx->pc = 0x170f00u;
    SET_GPR_U32(ctx, 4, ctx->hi);
    // 0x170f04: 0x641821
    ctx->pc = 0x170f04u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x170f08: 0x441023
    ctx->pc = 0x170f08u;
    SET_GPR_U32(ctx, 2, SUB32(GPR_U32(ctx, 2), GPR_U32(ctx, 4)));
    // 0x170f0c: 0x66001a
    ctx->pc = 0x170f0cu;
    { int32_t divisor = GPR_S32(ctx, 6);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint32_t)(dividend / divisor);            ctx->hi = (uint32_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1 : -1; ctx->hi = dividend;    } }
    // 0x170f10: 0xae220010
    ctx->pc = 0x170f10u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 2));
    // 0x170f14: 0x2810
    ctx->pc = 0x170f14u;
    SET_GPR_U32(ctx, 5, ctx->hi);
    // 0x170f18: 0xa23821
    ctx->pc = 0x170f18u;
    SET_GPR_U32(ctx, 7, ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 2)));
    // 0x170f1c: 0xae25000c
    ctx->pc = 0x170f1cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 12), GPR_U32(ctx, 5));
    // 0x170f20: 0xe6001a
    ctx->pc = 0x170f20u;
    { int32_t divisor = GPR_S32(ctx, 6);    int32_t dividend = GPR_S32(ctx, 7);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint32_t)(dividend / divisor);            ctx->hi = (uint32_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1 : -1; ctx->hi = dividend;    } }
    // 0x170f24: 0x8e240014
    ctx->pc = 0x170f24u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x170f28: 0x28830000
    ctx->pc = 0x170f28u;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 4), 0));
    // 0x170f2c: 0x248507ff
    ctx->pc = 0x170f2cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 4), 2047));
    // 0x170f30: 0x80102d
    ctx->pc = 0x170f30u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170f34: 0xa3100b
    ctx->pc = 0x170f34u;
    if (GPR_U32(ctx, 3) != 0) SET_GPR_U32(ctx, 2, GPR_U32(ctx, 5));
    // 0x170f38: 0x29ac3
    ctx->pc = 0x170f38u;
    SET_GPR_S32(ctx, 19, SRA32(GPR_S32(ctx, 2), 11));
    // 0x170f3c: 0x131ac0
    ctx->pc = 0x170f3cu;
    SET_GPR_U32(ctx, 3, SLL32(GPR_U32(ctx, 19), 11));
    // 0x170f40: 0x832023
    ctx->pc = 0x170f40u;
    SET_GPR_U32(ctx, 4, SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 3)));
    // 0x170f44: 0x8010
    ctx->pc = 0x170f44u;
    SET_GPR_U32(ctx, 16, ctx->hi);
    // 0x170f48: 0x1a600011
    ctx->pc = 0x170F48u;
    {
        const bool branch_taken_0x170f48 = (GPR_S32(ctx, 19) <= 0);
        ctx->pc = 0x170F4Cu;
        WRITE32(ADD32(GPR_U32(ctx, 17), 20), GPR_U32(ctx, 4));
        if (branch_taken_0x170f48) {
            ctx->pc = 0x170F90u;
            goto label_170f90;
        }
    }
    ctx->pc = 0x170F50u;
    // 0x170f50: 0xe61021
    ctx->pc = 0x170f50u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 7), GPR_U32(ctx, 6)));
    // 0x170f54: 0x24070080
    ctx->pc = 0x170f54u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 128));
    // 0x170f58: 0x2442ffff
    ctx->pc = 0x170f58u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x170f5c: 0x50c00001
    ctx->pc = 0x170F5Cu;
    {
        const bool branch_taken_0x170f5c = (GPR_U32(ctx, 6) == GPR_U32(ctx, 0));
        if (branch_taken_0x170f5c) {
            ctx->pc = 0x170F60u;
            runtime->handleBreak(rdram, ctx);
            ctx->pc = 0x170F64u;
            goto label_170f64;
        }
    }
    ctx->pc = 0x170F64u;
label_170f64:
    // 0x170f64: 0x46001a
    ctx->pc = 0x170f64u;
    { int32_t divisor = GPR_S32(ctx, 6);    int32_t dividend = GPR_S32(ctx, 2);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint32_t)(dividend / divisor);            ctx->hi = (uint32_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1 : -1; ctx->hi = dividend;    } }
    // 0x170f68: 0x24060003
    ctx->pc = 0x170f68u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 3));
    // 0x170f6c: 0x8e280004
    ctx->pc = 0x170f6cu;
    SET_GPR_U32(ctx, 8, READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x170f70: 0x24170001
    ctx->pc = 0x170f70u;
    SET_GPR_S32(ctx, 23, ADD32(GPR_U32(ctx, 0), 1));
    // 0x170f74: 0x8e230000
    ctx->pc = 0x170f74u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x170f78: 0x2010
    ctx->pc = 0x170f78u;
    SET_GPR_U32(ctx, 4, ctx->hi);
    // 0x170f7c: 0x42ac0
    ctx->pc = 0x170f7cu;
    SET_GPR_U32(ctx, 5, SLL32(GPR_U32(ctx, 4), 11));
    // 0x170f80: 0x42100
    ctx->pc = 0x170f80u;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 4), 4));
    // 0x170f84: 0x1042021
    ctx->pc = 0x170f84u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 8), GPR_U32(ctx, 4)));
    // 0x170f88: 0xc05c2b0
    ctx->pc = 0x170F88u;
    SET_GPR_U32(ctx, 31, 0x170F90u);
    ctx->pc = 0x170F8Cu;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 5)));
    ctx->pc = 0x170AC0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00170AC0_0x170ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170F90u; }
    }
    if (ctx->pc != 0x170F90u) { return; }
    ctx->pc = 0x170F90u;
label_170f90:
    // 0x170f90: 0x1a600018
    ctx->pc = 0x170F90u;
    {
        const bool branch_taken_0x170f90 = (GPR_S32(ctx, 19) <= 0);
        ctx->pc = 0x170F94u;
        SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x170f90) {
            ctx->pc = 0x170FF4u;
            goto label_170ff4;
        }
    }
    ctx->pc = 0x170F98u;
    // 0x170f98: 0x2674ffff
    ctx->pc = 0x170f98u;
    SET_GPR_S32(ctx, 20, ADD32(GPR_U32(ctx, 19), 4294967295));
    // 0x170f9c: 0x24160003
    ctx->pc = 0x170f9cu;
    SET_GPR_S32(ctx, 22, ADD32(GPR_U32(ctx, 0), 3));
label_170fa0:
    // 0x170fa0: 0x8e230004
    ctx->pc = 0x170fa0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x170fa4: 0x2543826
    ctx->pc = 0x170fa4u;
    SET_GPR_U32(ctx, 7, XOR32(GPR_U32(ctx, 18), GPR_U32(ctx, 20)));
    // 0x170fa8: 0x8e220000
    ctx->pc = 0x170fa8u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x170fac: 0x102100
    ctx->pc = 0x170facu;
    SET_GPR_U32(ctx, 4, SLL32(GPR_U32(ctx, 16), 4));
    // 0x170fb0: 0x102ac0
    ctx->pc = 0x170fb0u;
    SET_GPR_U32(ctx, 5, SLL32(GPR_U32(ctx, 16), 11));
    // 0x170fb4: 0x302d
    ctx->pc = 0x170fb4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x170fb8: 0x642021
    ctx->pc = 0x170fb8u;
    SET_GPR_U32(ctx, 4, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 4)));
    // 0x170fbc: 0x452821
    ctx->pc = 0x170fbcu;
    SET_GPR_U32(ctx, 5, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 5)));
    // 0x170fc0: 0x2c7300b
    ctx->pc = 0x170fc0u;
    if (GPR_U32(ctx, 7) != 0) SET_GPR_U32(ctx, 6, GPR_U32(ctx, 22));
    // 0x170fc4: 0xc05c2b0
    ctx->pc = 0x170FC4u;
    SET_GPR_U32(ctx, 31, 0x170FCCu);
    ctx->pc = 0x170FC8u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 0), 128));
    ctx->pc = 0x170AC0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00170AC0_0x170ac0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x170FCCu; }
    }
    if (ctx->pc != 0x170FCCu) { return; }
    ctx->pc = 0x170FCCu;
    // 0x170fcc: 0x26030001
    ctx->pc = 0x170fccu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 16), 1));
    // 0x170fd0: 0x8e220008
    ctx->pc = 0x170fd0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 8)));
    // 0x170fd4: 0x26520001
    ctx->pc = 0x170fd4u;
    SET_GPR_S32(ctx, 18, ADD32(GPR_U32(ctx, 18), 1));
    // 0x170fd8: 0x253282a
    ctx->pc = 0x170fd8u;
    SET_GPR_U32(ctx, 5, SLT32(GPR_S32(ctx, 18), GPR_S32(ctx, 19)));
    // 0x170fdc: 0x62001a
    ctx->pc = 0x170fdcu;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint32_t)(dividend / divisor);            ctx->hi = (uint32_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1 : -1; ctx->hi = dividend;    } }
    // 0x170fe0: 0x50400001
    ctx->pc = 0x170FE0u;
    {
        const bool branch_taken_0x170fe0 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x170fe0) {
            ctx->pc = 0x170FE4u;
            runtime->handleBreak(rdram, ctx);
            ctx->pc = 0x170FE8u;
            goto label_170fe8;
        }
    }
    ctx->pc = 0x170FE8u;
label_170fe8:
    // 0x170fe8: 0x2010
    ctx->pc = 0x170fe8u;
    SET_GPR_U32(ctx, 4, ctx->hi);
    // 0x170fec: 0x14a0ffec
    ctx->pc = 0x170FECu;
    {
        const bool branch_taken_0x170fec = (GPR_U32(ctx, 5) != GPR_U32(ctx, 0));
        ctx->pc = 0x170FF0u;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x170fec) {
            ctx->pc = 0x170FA0u;
            goto label_170fa0;
        }
    }
    ctx->pc = 0x170FF4u;
label_170ff4:
    // 0x170ff4: 0x8e220010
    ctx->pc = 0x170ff4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 16)));
    // 0x170ff8: 0x531021
    ctx->pc = 0x170ff8u;
    SET_GPR_U32(ctx, 2, ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 19)));
    // 0x170ffc: 0x10400009
    ctx->pc = 0x170FFCu;
    {
        const bool branch_taken_0x170ffc = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x171000u;
        WRITE32(ADD32(GPR_U32(ctx, 17), 16), GPR_U32(ctx, 2));
        if (branch_taken_0x170ffc) {
            ctx->pc = 0x171024u;
            goto label_171024;
        }
    }
    ctx->pc = 0x171004u;
    // 0x171004: 0x12e00005
    ctx->pc = 0x171004u;
    {
        const bool branch_taken_0x171004 = (GPR_U32(ctx, 23) == GPR_U32(ctx, 0));
        ctx->pc = 0x171008u;
        SET_GPR_U32(ctx, 2, ((uint32_t)4095 << 16));
        if (branch_taken_0x171004) {
            ctx->pc = 0x17101Cu;
            goto label_17101c;
        }
    }
    ctx->pc = 0x17100Cu;
    // 0x17100c: 0x3c033000
    ctx->pc = 0x17100cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)12288 << 16));
    // 0x171010: 0x3442ffff
    ctx->pc = 0x171010u;
    SET_GPR_U32(ctx, 2, OR32(GPR_U32(ctx, 2), 65535));
    // 0x171014: 0x2a21024
    ctx->pc = 0x171014u;
    SET_GPR_U32(ctx, 2, AND32(GPR_U32(ctx, 21), GPR_U32(ctx, 2)));
    // 0x171018: 0x43a825
    ctx->pc = 0x171018u;
    SET_GPR_U32(ctx, 21, OR32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_17101c:
    // 0x17101c: 0xc05c296
    ctx->pc = 0x17101Cu;
    SET_GPR_U32(ctx, 31, 0x171024u);
    ctx->pc = 0x171020u;
    SET_GPR_U32(ctx, 4, OR32(GPR_U32(ctx, 21), 256));
    ctx->pc = 0x170A58u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00170A58_0x170a58(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x171024u; }
    }
    if (ctx->pc != 0x171024u) { return; }
    ctx->pc = 0x171024u;
label_171024:
    // 0x171024: 0xc045190
    ctx->pc = 0x171024u;
    SET_GPR_U32(ctx, 31, 0x17102Cu);
    ctx->pc = 0x171028u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 64)));
    ctx->pc = 0x114640u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00114640_0x114640(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x17102Cu; }
    }
    if (ctx->pc != 0x17102Cu) { return; }
    ctx->pc = 0x17102Cu;
    // 0x17102c: 0x24020001
    ctx->pc = 0x17102cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_171030:
    // 0x171030: 0xdfb00000
    ctx->pc = 0x171030u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x171034: 0xdfb10008
    ctx->pc = 0x171034u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x171038: 0xdfb20010
    ctx->pc = 0x171038u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x17103c: 0xdfb30018
    ctx->pc = 0x17103cu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x171040: 0xdfb40020
    ctx->pc = 0x171040u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x171044: 0xdfb50028
    ctx->pc = 0x171044u;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x171048: 0xdfb60030
    ctx->pc = 0x171048u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x17104c: 0xdfb70038
    ctx->pc = 0x17104cu;
    SET_GPR_U64(ctx, 23, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x171050: 0xdfbf0040
    ctx->pc = 0x171050u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x171054: 0x3e00008
    ctx->pc = 0x171054u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x171058u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x170EB8u: goto label_170eb8;
            case 0x170EF4u: goto label_170ef4;
            case 0x170F64u: goto label_170f64;
            case 0x170F90u: goto label_170f90;
            case 0x170FA0u: goto label_170fa0;
            case 0x170FE8u: goto label_170fe8;
            case 0x170FF4u: goto label_170ff4;
            case 0x17101Cu: goto label_17101c;
            case 0x171024u: goto label_171024;
            case 0x171030u: goto label_171030;
            default: break;
        }
        return;
    }
    ctx->pc = 0x17105Cu;
    // 0x17105c: 0x0
    ctx->pc = 0x17105cu;
    // NOP
}
