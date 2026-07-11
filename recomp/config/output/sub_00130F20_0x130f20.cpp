#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00130F20
// Address: 0x130f20 - 0x130fe8
void sub_00130F20_0x130f20(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x130f20u;

label_130f20:
    // 0x130f20: 0x27bdffe0
    ctx->pc = 0x130f20u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
label_130f24:
    // 0x130f24: 0xffb00000
    ctx->pc = 0x130f24u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_130f28:
    // 0x130f28: 0xa0802d
    ctx->pc = 0x130f28u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_130f2c:
    // 0x130f2c: 0xffb20010
    ctx->pc = 0x130f2cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
label_130f30:
    // 0x130f30: 0x80902d
    ctx->pc = 0x130f30u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_130f34:
    // 0x130f34: 0xffb10008
    ctx->pc = 0x130f34u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
label_130f38:
    // 0x130f38: 0xffbf0018
    ctx->pc = 0x130f38u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
label_130f3c:
    // 0x130f3c: 0xc049938
label_130f40:
    if (ctx->pc == 0x130F40u) {
        ctx->pc = 0x130F40u;
        WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 16));
        ctx->pc = 0x130F44u;
        goto label_130f44;
    }
    ctx->pc = 0x130F3Cu;
    SET_GPR_U32(ctx, 31, 0x130F44u);
    ctx->pc = 0x130F40u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 4), GPR_U32(ctx, 16));
    ctx->pc = 0x1264E0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001264E0_0x1264e0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130F44u; }
    }
    if (ctx->pc != 0x130F44u) { return; }
    ctx->pc = 0x130F44u;
label_130f44:
    // 0x130f44: 0x8e030000
    ctx->pc = 0x130f44u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_130f48:
    // 0x130f48: 0x200202d
    ctx->pc = 0x130f48u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_130f4c:
    // 0x130f4c: 0x8c620024
    ctx->pc = 0x130f4cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 36)));
label_130f50:
    // 0x130f50: 0x40f809
label_130f54:
    if (ctx->pc == 0x130F54u) {
        ctx->pc = 0x130F54u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x130F58u;
        goto label_130f58;
    }
    ctx->pc = 0x130F50u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x130F58u);
        ctx->pc = 0x130F54u;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130F20u: goto label_130f20;
            case 0x130F24u: goto label_130f24;
            case 0x130F28u: goto label_130f28;
            case 0x130F2Cu: goto label_130f2c;
            case 0x130F30u: goto label_130f30;
            case 0x130F34u: goto label_130f34;
            case 0x130F38u: goto label_130f38;
            case 0x130F3Cu: goto label_130f3c;
            case 0x130F40u: goto label_130f40;
            case 0x130F44u: goto label_130f44;
            case 0x130F48u: goto label_130f48;
            case 0x130F4Cu: goto label_130f4c;
            case 0x130F50u: goto label_130f50;
            case 0x130F54u: goto label_130f54;
            case 0x130F58u: goto label_130f58;
            case 0x130F5Cu: goto label_130f5c;
            case 0x130F60u: goto label_130f60;
            case 0x130F64u: goto label_130f64;
            case 0x130F68u: goto label_130f68;
            case 0x130F6Cu: goto label_130f6c;
            case 0x130F70u: goto label_130f70;
            case 0x130F74u: goto label_130f74;
            case 0x130F78u: goto label_130f78;
            case 0x130F7Cu: goto label_130f7c;
            case 0x130F80u: goto label_130f80;
            case 0x130F84u: goto label_130f84;
            case 0x130F88u: goto label_130f88;
            case 0x130F8Cu: goto label_130f8c;
            case 0x130F90u: goto label_130f90;
            case 0x130F94u: goto label_130f94;
            case 0x130F98u: goto label_130f98;
            case 0x130F9Cu: goto label_130f9c;
            case 0x130FA0u: goto label_130fa0;
            case 0x130FA4u: goto label_130fa4;
            case 0x130FA8u: goto label_130fa8;
            case 0x130FACu: goto label_130fac;
            case 0x130FB0u: goto label_130fb0;
            case 0x130FB4u: goto label_130fb4;
            case 0x130FB8u: goto label_130fb8;
            case 0x130FBCu: goto label_130fbc;
            case 0x130FC0u: goto label_130fc0;
            case 0x130FC4u: goto label_130fc4;
            case 0x130FC8u: goto label_130fc8;
            case 0x130FCCu: goto label_130fcc;
            case 0x130FD0u: goto label_130fd0;
            case 0x130FD4u: goto label_130fd4;
            case 0x130FD8u: goto label_130fd8;
            case 0x130FDCu: goto label_130fdc;
            case 0x130FE0u: goto label_130fe0;
            case 0x130FE4u: goto label_130fe4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x130F58u; }
            if (ctx->pc != 0x130F58u) { return; }
        }
    }
    ctx->pc = 0x130F58u;
label_130f58:
    // 0x130f58: 0x8e030000
    ctx->pc = 0x130f58u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 16), 0)));
label_130f5c:
    // 0x130f5c: 0x40882d
    ctx->pc = 0x130f5cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_130f60:
    // 0x130f60: 0x200202d
    ctx->pc = 0x130f60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_130f64:
    // 0x130f64: 0x8c620024
    ctx->pc = 0x130f64u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 36)));
label_130f68:
    // 0x130f68: 0x40f809
label_130f6c:
    if (ctx->pc == 0x130F6Cu) {
        ctx->pc = 0x130F6Cu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x130F70u;
        goto label_130f70;
    }
    ctx->pc = 0x130F68u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x130F70u);
        ctx->pc = 0x130F6Cu;
        SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130F20u: goto label_130f20;
            case 0x130F24u: goto label_130f24;
            case 0x130F28u: goto label_130f28;
            case 0x130F2Cu: goto label_130f2c;
            case 0x130F30u: goto label_130f30;
            case 0x130F34u: goto label_130f34;
            case 0x130F38u: goto label_130f38;
            case 0x130F3Cu: goto label_130f3c;
            case 0x130F40u: goto label_130f40;
            case 0x130F44u: goto label_130f44;
            case 0x130F48u: goto label_130f48;
            case 0x130F4Cu: goto label_130f4c;
            case 0x130F50u: goto label_130f50;
            case 0x130F54u: goto label_130f54;
            case 0x130F58u: goto label_130f58;
            case 0x130F5Cu: goto label_130f5c;
            case 0x130F60u: goto label_130f60;
            case 0x130F64u: goto label_130f64;
            case 0x130F68u: goto label_130f68;
            case 0x130F6Cu: goto label_130f6c;
            case 0x130F70u: goto label_130f70;
            case 0x130F74u: goto label_130f74;
            case 0x130F78u: goto label_130f78;
            case 0x130F7Cu: goto label_130f7c;
            case 0x130F80u: goto label_130f80;
            case 0x130F84u: goto label_130f84;
            case 0x130F88u: goto label_130f88;
            case 0x130F8Cu: goto label_130f8c;
            case 0x130F90u: goto label_130f90;
            case 0x130F94u: goto label_130f94;
            case 0x130F98u: goto label_130f98;
            case 0x130F9Cu: goto label_130f9c;
            case 0x130FA0u: goto label_130fa0;
            case 0x130FA4u: goto label_130fa4;
            case 0x130FA8u: goto label_130fa8;
            case 0x130FACu: goto label_130fac;
            case 0x130FB0u: goto label_130fb0;
            case 0x130FB4u: goto label_130fb4;
            case 0x130FB8u: goto label_130fb8;
            case 0x130FBCu: goto label_130fbc;
            case 0x130FC0u: goto label_130fc0;
            case 0x130FC4u: goto label_130fc4;
            case 0x130FC8u: goto label_130fc8;
            case 0x130FCCu: goto label_130fcc;
            case 0x130FD0u: goto label_130fd0;
            case 0x130FD4u: goto label_130fd4;
            case 0x130FD8u: goto label_130fd8;
            case 0x130FDCu: goto label_130fdc;
            case 0x130FE0u: goto label_130fe0;
            case 0x130FE4u: goto label_130fe4;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x130F70u; }
            if (ctx->pc != 0x130F70u) { return; }
        }
    }
    ctx->pc = 0x130F70u;
label_130f70:
    // 0x130f70: 0x2228821
    ctx->pc = 0x130f70u;
    SET_GPR_U32(ctx, 17, ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 2)));
label_130f74:
    // 0x130f74: 0xc04993e
label_130f78:
    if (ctx->pc == 0x130F78u) {
        ctx->pc = 0x130F78u;
        WRITE32(ADD32(GPR_U32(ctx, 18), 60), GPR_U32(ctx, 17));
        ctx->pc = 0x130F7Cu;
        goto label_130f7c;
    }
    ctx->pc = 0x130F74u;
    SET_GPR_U32(ctx, 31, 0x130F7Cu);
    ctx->pc = 0x130F78u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 60), GPR_U32(ctx, 17));
    ctx->pc = 0x1264F8u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001264F8_0x1264f8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x130F7Cu; }
    }
    if (ctx->pc != 0x130F7Cu) { return; }
    ctx->pc = 0x130F7Cu;
label_130f7c:
    // 0x130f7c: 0x8e42003c
    ctx->pc = 0x130f7cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 18), 60)));
label_130f80:
    // 0x130f80: 0xdfb00000
    ctx->pc = 0x130f80u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_130f84:
    // 0x130f84: 0xae420018
    ctx->pc = 0x130f84u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 24), GPR_U32(ctx, 2));
label_130f88:
    // 0x130f88: 0xae420014
    ctx->pc = 0x130f88u;
    WRITE32(ADD32(GPR_U32(ctx, 18), 20), GPR_U32(ctx, 2));
label_130f8c:
    // 0x130f8c: 0xdfb10008
    ctx->pc = 0x130f8cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_130f90:
    // 0x130f90: 0xdfb20010
    ctx->pc = 0x130f90u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_130f94:
    // 0x130f94: 0xdfbf0018
    ctx->pc = 0x130f94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_130f98:
    // 0x130f98: 0x3e00008
label_130f9c:
    if (ctx->pc == 0x130F9Cu) {
        ctx->pc = 0x130F9Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x130FA0u;
        goto label_130fa0;
    }
    ctx->pc = 0x130F98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130F9Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130F20u: goto label_130f20;
            case 0x130F24u: goto label_130f24;
            case 0x130F28u: goto label_130f28;
            case 0x130F2Cu: goto label_130f2c;
            case 0x130F30u: goto label_130f30;
            case 0x130F34u: goto label_130f34;
            case 0x130F38u: goto label_130f38;
            case 0x130F3Cu: goto label_130f3c;
            case 0x130F40u: goto label_130f40;
            case 0x130F44u: goto label_130f44;
            case 0x130F48u: goto label_130f48;
            case 0x130F4Cu: goto label_130f4c;
            case 0x130F50u: goto label_130f50;
            case 0x130F54u: goto label_130f54;
            case 0x130F58u: goto label_130f58;
            case 0x130F5Cu: goto label_130f5c;
            case 0x130F60u: goto label_130f60;
            case 0x130F64u: goto label_130f64;
            case 0x130F68u: goto label_130f68;
            case 0x130F6Cu: goto label_130f6c;
            case 0x130F70u: goto label_130f70;
            case 0x130F74u: goto label_130f74;
            case 0x130F78u: goto label_130f78;
            case 0x130F7Cu: goto label_130f7c;
            case 0x130F80u: goto label_130f80;
            case 0x130F84u: goto label_130f84;
            case 0x130F88u: goto label_130f88;
            case 0x130F8Cu: goto label_130f8c;
            case 0x130F90u: goto label_130f90;
            case 0x130F94u: goto label_130f94;
            case 0x130F98u: goto label_130f98;
            case 0x130F9Cu: goto label_130f9c;
            case 0x130FA0u: goto label_130fa0;
            case 0x130FA4u: goto label_130fa4;
            case 0x130FA8u: goto label_130fa8;
            case 0x130FACu: goto label_130fac;
            case 0x130FB0u: goto label_130fb0;
            case 0x130FB4u: goto label_130fb4;
            case 0x130FB8u: goto label_130fb8;
            case 0x130FBCu: goto label_130fbc;
            case 0x130FC0u: goto label_130fc0;
            case 0x130FC4u: goto label_130fc4;
            case 0x130FC8u: goto label_130fc8;
            case 0x130FCCu: goto label_130fcc;
            case 0x130FD0u: goto label_130fd0;
            case 0x130FD4u: goto label_130fd4;
            case 0x130FD8u: goto label_130fd8;
            case 0x130FDCu: goto label_130fdc;
            case 0x130FE0u: goto label_130fe0;
            case 0x130FE4u: goto label_130fe4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130FA0u;
label_130fa0:
    // 0x130fa0: 0x52ac0
    ctx->pc = 0x130fa0u;
    SET_GPR_U32(ctx, 5, SLL32(GPR_U32(ctx, 5), 11));
label_130fa4:
    // 0x130fa4: 0x3e00008
label_130fa8:
    if (ctx->pc == 0x130FA8u) {
        ctx->pc = 0x130FA8u;
        WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 5));
        ctx->pc = 0x130FACu;
        goto label_130fac;
    }
    ctx->pc = 0x130FA4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130FA8u;
        WRITE32(ADD32(GPR_U32(ctx, 4), 16), GPR_U32(ctx, 5));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130F20u: goto label_130f20;
            case 0x130F24u: goto label_130f24;
            case 0x130F28u: goto label_130f28;
            case 0x130F2Cu: goto label_130f2c;
            case 0x130F30u: goto label_130f30;
            case 0x130F34u: goto label_130f34;
            case 0x130F38u: goto label_130f38;
            case 0x130F3Cu: goto label_130f3c;
            case 0x130F40u: goto label_130f40;
            case 0x130F44u: goto label_130f44;
            case 0x130F48u: goto label_130f48;
            case 0x130F4Cu: goto label_130f4c;
            case 0x130F50u: goto label_130f50;
            case 0x130F54u: goto label_130f54;
            case 0x130F58u: goto label_130f58;
            case 0x130F5Cu: goto label_130f5c;
            case 0x130F60u: goto label_130f60;
            case 0x130F64u: goto label_130f64;
            case 0x130F68u: goto label_130f68;
            case 0x130F6Cu: goto label_130f6c;
            case 0x130F70u: goto label_130f70;
            case 0x130F74u: goto label_130f74;
            case 0x130F78u: goto label_130f78;
            case 0x130F7Cu: goto label_130f7c;
            case 0x130F80u: goto label_130f80;
            case 0x130F84u: goto label_130f84;
            case 0x130F88u: goto label_130f88;
            case 0x130F8Cu: goto label_130f8c;
            case 0x130F90u: goto label_130f90;
            case 0x130F94u: goto label_130f94;
            case 0x130F98u: goto label_130f98;
            case 0x130F9Cu: goto label_130f9c;
            case 0x130FA0u: goto label_130fa0;
            case 0x130FA4u: goto label_130fa4;
            case 0x130FA8u: goto label_130fa8;
            case 0x130FACu: goto label_130fac;
            case 0x130FB0u: goto label_130fb0;
            case 0x130FB4u: goto label_130fb4;
            case 0x130FB8u: goto label_130fb8;
            case 0x130FBCu: goto label_130fbc;
            case 0x130FC0u: goto label_130fc0;
            case 0x130FC4u: goto label_130fc4;
            case 0x130FC8u: goto label_130fc8;
            case 0x130FCCu: goto label_130fcc;
            case 0x130FD0u: goto label_130fd0;
            case 0x130FD4u: goto label_130fd4;
            case 0x130FD8u: goto label_130fd8;
            case 0x130FDCu: goto label_130fdc;
            case 0x130FE0u: goto label_130fe0;
            case 0x130FE4u: goto label_130fe4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130FACu;
label_130fac:
    // 0x130fac: 0x0
    ctx->pc = 0x130facu;
    // NOP
label_130fb0:
    // 0x130fb0: 0x27bdfff0
    ctx->pc = 0x130fb0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
label_130fb4:
    // 0x130fb4: 0xffbf0000
    ctx->pc = 0x130fb4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
label_130fb8:
    // 0x130fb8: 0xac85000c
    ctx->pc = 0x130fb8u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 12), GPR_U32(ctx, 5));
label_130fbc:
    // 0x130fbc: 0x282d
    ctx->pc = 0x130fbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_130fc0:
    // 0x130fc0: 0xdfbf0000
    ctx->pc = 0x130fc0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_130fc4:
    // 0x130fc4: 0x804c170
label_130fc8:
    if (ctx->pc == 0x130FC8u) {
        ctx->pc = 0x130FC8u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = 0x130FCCu;
        goto label_130fcc;
    }
    ctx->pc = 0x130FC4u;
    ctx->pc = 0x130FC8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
    ctx->pc = 0x1305C0u;
    sub_001305C0_0x1305c0(rdram, ctx, runtime); return;
    ctx->pc = 0x130FCCu;
label_130fcc:
    // 0x130fcc: 0x0
    ctx->pc = 0x130fccu;
    // NOP
label_130fd0:
    // 0x130fd0: 0x3c020022
    ctx->pc = 0x130fd0u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
label_130fd4:
    // 0x130fd4: 0x3e00008
label_130fd8:
    if (ctx->pc == 0x130FD8u) {
        ctx->pc = 0x130FD8u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294944948), GPR_U32(ctx, 4));
        ctx->pc = 0x130FDCu;
        goto label_130fdc;
    }
    ctx->pc = 0x130FD4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130FD8u;
        WRITE32(ADD32(GPR_U32(ctx, 2), 4294944948), GPR_U32(ctx, 4));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130F20u: goto label_130f20;
            case 0x130F24u: goto label_130f24;
            case 0x130F28u: goto label_130f28;
            case 0x130F2Cu: goto label_130f2c;
            case 0x130F30u: goto label_130f30;
            case 0x130F34u: goto label_130f34;
            case 0x130F38u: goto label_130f38;
            case 0x130F3Cu: goto label_130f3c;
            case 0x130F40u: goto label_130f40;
            case 0x130F44u: goto label_130f44;
            case 0x130F48u: goto label_130f48;
            case 0x130F4Cu: goto label_130f4c;
            case 0x130F50u: goto label_130f50;
            case 0x130F54u: goto label_130f54;
            case 0x130F58u: goto label_130f58;
            case 0x130F5Cu: goto label_130f5c;
            case 0x130F60u: goto label_130f60;
            case 0x130F64u: goto label_130f64;
            case 0x130F68u: goto label_130f68;
            case 0x130F6Cu: goto label_130f6c;
            case 0x130F70u: goto label_130f70;
            case 0x130F74u: goto label_130f74;
            case 0x130F78u: goto label_130f78;
            case 0x130F7Cu: goto label_130f7c;
            case 0x130F80u: goto label_130f80;
            case 0x130F84u: goto label_130f84;
            case 0x130F88u: goto label_130f88;
            case 0x130F8Cu: goto label_130f8c;
            case 0x130F90u: goto label_130f90;
            case 0x130F94u: goto label_130f94;
            case 0x130F98u: goto label_130f98;
            case 0x130F9Cu: goto label_130f9c;
            case 0x130FA0u: goto label_130fa0;
            case 0x130FA4u: goto label_130fa4;
            case 0x130FA8u: goto label_130fa8;
            case 0x130FACu: goto label_130fac;
            case 0x130FB0u: goto label_130fb0;
            case 0x130FB4u: goto label_130fb4;
            case 0x130FB8u: goto label_130fb8;
            case 0x130FBCu: goto label_130fbc;
            case 0x130FC0u: goto label_130fc0;
            case 0x130FC4u: goto label_130fc4;
            case 0x130FC8u: goto label_130fc8;
            case 0x130FCCu: goto label_130fcc;
            case 0x130FD0u: goto label_130fd0;
            case 0x130FD4u: goto label_130fd4;
            case 0x130FD8u: goto label_130fd8;
            case 0x130FDCu: goto label_130fdc;
            case 0x130FE0u: goto label_130fe0;
            case 0x130FE4u: goto label_130fe4;
            default: break;
        }
        return;
    }
    ctx->pc = 0x130FDCu;
label_130fdc:
    // 0x130fdc: 0x0
    ctx->pc = 0x130fdcu;
    // NOP
label_130fe0:
    // 0x130fe0: 0x3e00008
label_130fe4:
    if (ctx->pc == 0x130FE4u) {
        ctx->pc = 0x130FE4u;
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
        ctx->pc = 0x130FE8u;
        goto label_fallthrough_0x130fe0;
    }
    ctx->pc = 0x130FE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x130FE4u;
        SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 2)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x130F20u: goto label_130f20;
            case 0x130F24u: goto label_130f24;
            case 0x130F28u: goto label_130f28;
            case 0x130F2Cu: goto label_130f2c;
            case 0x130F30u: goto label_130f30;
            case 0x130F34u: goto label_130f34;
            case 0x130F38u: goto label_130f38;
            case 0x130F3Cu: goto label_130f3c;
            case 0x130F40u: goto label_130f40;
            case 0x130F44u: goto label_130f44;
            case 0x130F48u: goto label_130f48;
            case 0x130F4Cu: goto label_130f4c;
            case 0x130F50u: goto label_130f50;
            case 0x130F54u: goto label_130f54;
            case 0x130F58u: goto label_130f58;
            case 0x130F5Cu: goto label_130f5c;
            case 0x130F60u: goto label_130f60;
            case 0x130F64u: goto label_130f64;
            case 0x130F68u: goto label_130f68;
            case 0x130F6Cu: goto label_130f6c;
            case 0x130F70u: goto label_130f70;
            case 0x130F74u: goto label_130f74;
            case 0x130F78u: goto label_130f78;
            case 0x130F7Cu: goto label_130f7c;
            case 0x130F80u: goto label_130f80;
            case 0x130F84u: goto label_130f84;
            case 0x130F88u: goto label_130f88;
            case 0x130F8Cu: goto label_130f8c;
            case 0x130F90u: goto label_130f90;
            case 0x130F94u: goto label_130f94;
            case 0x130F98u: goto label_130f98;
            case 0x130F9Cu: goto label_130f9c;
            case 0x130FA0u: goto label_130fa0;
            case 0x130FA4u: goto label_130fa4;
            case 0x130FA8u: goto label_130fa8;
            case 0x130FACu: goto label_130fac;
            case 0x130FB0u: goto label_130fb0;
            case 0x130FB4u: goto label_130fb4;
            case 0x130FB8u: goto label_130fb8;
            case 0x130FBCu: goto label_130fbc;
            case 0x130FC0u: goto label_130fc0;
            case 0x130FC4u: goto label_130fc4;
            case 0x130FC8u: goto label_130fc8;
            case 0x130FCCu: goto label_130fcc;
            case 0x130FD0u: goto label_130fd0;
            case 0x130FD4u: goto label_130fd4;
            case 0x130FD8u: goto label_130fd8;
            case 0x130FDCu: goto label_130fdc;
            case 0x130FE0u: goto label_130fe0;
            case 0x130FE4u: goto label_130fe4;
            default: break;
        }
        return;
    }
label_fallthrough_0x130fe0:
    ctx->pc = 0x130FE8u;
}
