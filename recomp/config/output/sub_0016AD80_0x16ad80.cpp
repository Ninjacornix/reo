#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_0016AD80
// Address: 0x16ad80 - 0x16ae28
void sub_0016AD80_0x16ad80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x16ad80u;

label_16ad80:
    // 0x16ad80: 0x27bdffe0
    ctx->pc = 0x16ad80u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
label_16ad84:
    // 0x16ad84: 0xffb00000
    ctx->pc = 0x16ad84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_16ad88:
    // 0x16ad88: 0xc0802d
    ctx->pc = 0x16ad88u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_16ad8c:
    // 0x16ad8c: 0xffb10008
    ctx->pc = 0x16ad8cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
label_16ad90:
    // 0x16ad90: 0xa0882d
    ctx->pc = 0x16ad90u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_16ad94:
    // 0x16ad94: 0xffb20010
    ctx->pc = 0x16ad94u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
label_16ad98:
    // 0x16ad98: 0x80902d
    ctx->pc = 0x16ad98u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_16ad9c:
    // 0x16ad9c: 0xffbf0018
    ctx->pc = 0x16ad9cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
label_16ada0:
    // 0x16ada0: 0x8e430000
    ctx->pc = 0x16ada0u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 18), 0)));
label_16ada4:
    // 0x16ada4: 0x8c620024
    ctx->pc = 0x16ada4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 36)));
label_16ada8:
    // 0x16ada8: 0x40f809
label_16adac:
    if (ctx->pc == 0x16ADACu) {
        ctx->pc = 0x16ADACu;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x16ADB0u;
        goto label_16adb0;
    }
    ctx->pc = 0x16ADA8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x16ADB0u);
        ctx->pc = 0x16ADACu;
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16AD80u: goto label_16ad80;
            case 0x16AD84u: goto label_16ad84;
            case 0x16AD88u: goto label_16ad88;
            case 0x16AD8Cu: goto label_16ad8c;
            case 0x16AD90u: goto label_16ad90;
            case 0x16AD94u: goto label_16ad94;
            case 0x16AD98u: goto label_16ad98;
            case 0x16AD9Cu: goto label_16ad9c;
            case 0x16ADA0u: goto label_16ada0;
            case 0x16ADA4u: goto label_16ada4;
            case 0x16ADA8u: goto label_16ada8;
            case 0x16ADACu: goto label_16adac;
            case 0x16ADB0u: goto label_16adb0;
            case 0x16ADB4u: goto label_16adb4;
            case 0x16ADB8u: goto label_16adb8;
            case 0x16ADBCu: goto label_16adbc;
            case 0x16ADC0u: goto label_16adc0;
            case 0x16ADC4u: goto label_16adc4;
            case 0x16ADC8u: goto label_16adc8;
            case 0x16ADCCu: goto label_16adcc;
            case 0x16ADD0u: goto label_16add0;
            case 0x16ADD4u: goto label_16add4;
            case 0x16ADD8u: goto label_16add8;
            case 0x16ADDCu: goto label_16addc;
            case 0x16ADE0u: goto label_16ade0;
            case 0x16ADE4u: goto label_16ade4;
            case 0x16ADE8u: goto label_16ade8;
            case 0x16ADECu: goto label_16adec;
            case 0x16ADF0u: goto label_16adf0;
            case 0x16ADF4u: goto label_16adf4;
            case 0x16ADF8u: goto label_16adf8;
            case 0x16ADFCu: goto label_16adfc;
            case 0x16AE00u: goto label_16ae00;
            case 0x16AE04u: goto label_16ae04;
            case 0x16AE08u: goto label_16ae08;
            case 0x16AE0Cu: goto label_16ae0c;
            case 0x16AE10u: goto label_16ae10;
            case 0x16AE14u: goto label_16ae14;
            case 0x16AE18u: goto label_16ae18;
            case 0x16AE1Cu: goto label_16ae1c;
            case 0x16AE20u: goto label_16ae20;
            case 0x16AE24u: goto label_16ae24;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x16ADB0u; }
            if (ctx->pc != 0x16ADB0u) { return; }
        }
    }
    ctx->pc = 0x16ADB0u;
label_16adb0:
    // 0x16adb0: 0x240202d
    ctx->pc = 0x16adb0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_16adb4:
    // 0x16adb4: 0x50182a
    ctx->pc = 0x16adb4u;
    SET_GPR_U32(ctx, 3, SLT32(GPR_S32(ctx, 2), GPR_S32(ctx, 16)));
label_16adb8:
    // 0x16adb8: 0x102d
    ctx->pc = 0x16adb8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_16adbc:
    // 0x16adbc: 0x220282d
    ctx->pc = 0x16adbcu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_16adc0:
    // 0x16adc0: 0x14600013
label_16adc4:
    if (ctx->pc == 0x16ADC4u) {
        ctx->pc = 0x16ADC4u;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x16ADC8u;
        goto label_16adc8;
    }
    ctx->pc = 0x16ADC0u;
    {
        const bool branch_taken_0x16adc0 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 0));
        ctx->pc = 0x16ADC4u;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x16adc0) {
            ctx->pc = 0x16AE10u;
            goto label_16ae10;
        }
    }
    ctx->pc = 0x16ADC8u;
label_16adc8:
    // 0x16adc8: 0xc05ab8a
label_16adcc:
    if (ctx->pc == 0x16ADCCu) {
        ctx->pc = 0x16ADD0u;
        goto label_16add0;
    }
    ctx->pc = 0x16ADC8u;
    SET_GPR_U32(ctx, 31, 0x16ADD0u);
    ctx->pc = 0x16AE28u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0016AE28_0x16ae28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ADD0u; }
    }
    if (ctx->pc != 0x16ADD0u) { return; }
    ctx->pc = 0x16ADD0u;
label_16add0:
    // 0x16add0: 0x40182d
    ctx->pc = 0x16add0u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_16add4:
    // 0x16add4: 0x1060000e
label_16add8:
    if (ctx->pc == 0x16ADD8u) {
        ctx->pc = 0x16ADD8u;
        SET_GPR_U32(ctx, 16, SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        ctx->pc = 0x16ADDCu;
        goto label_16addc;
    }
    ctx->pc = 0x16ADD4u;
    {
        const bool branch_taken_0x16add4 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x16ADD8u;
        SET_GPR_U32(ctx, 16, SUB32(GPR_U32(ctx, 16), GPR_U32(ctx, 3)));
        if (branch_taken_0x16add4) {
            ctx->pc = 0x16AE10u;
            goto label_16ae10;
        }
    }
    ctx->pc = 0x16ADDCu;
label_16addc:
    // 0x16addc: 0x1a00000b
label_16ade0:
    if (ctx->pc == 0x16ADE0u) {
        ctx->pc = 0x16ADE0u;
        SET_GPR_U32(ctx, 17, ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
        ctx->pc = 0x16ADE4u;
        goto label_16ade4;
    }
    ctx->pc = 0x16ADDCu;
    {
        const bool branch_taken_0x16addc = (GPR_S32(ctx, 16) <= 0);
        ctx->pc = 0x16ADE0u;
        SET_GPR_U32(ctx, 17, ADD32(GPR_U32(ctx, 17), GPR_U32(ctx, 3)));
        if (branch_taken_0x16addc) {
            ctx->pc = 0x16AE0Cu;
            goto label_16ae0c;
        }
    }
    ctx->pc = 0x16ADE4u;
label_16ade4:
    // 0x16ade4: 0x240202d
    ctx->pc = 0x16ade4u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_16ade8:
    // 0x16ade8: 0x220282d
    ctx->pc = 0x16ade8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
label_16adec:
    // 0x16adec: 0xc05ab8a
label_16adf0:
    if (ctx->pc == 0x16ADF0u) {
        ctx->pc = 0x16ADF0u;
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x16ADF4u;
        goto label_16adf4;
    }
    ctx->pc = 0x16ADECu;
    SET_GPR_U32(ctx, 31, 0x16ADF4u);
    ctx->pc = 0x16ADF0u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x16AE28u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_0016AE28_0x16ae28(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x16ADF4u; }
    }
    if (ctx->pc != 0x16ADF4u) { return; }
    ctx->pc = 0x16ADF4u;
label_16adf4:
    // 0x16adf4: 0x3c030023
    ctx->pc = 0x16adf4u;
    SET_GPR_U32(ctx, 3, ((uint32_t)35 << 16));
label_16adf8:
    // 0x16adf8: 0x10500004
label_16adfc:
    if (ctx->pc == 0x16ADFCu) {
        ctx->pc = 0x16ADFCu;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294963632));
        ctx->pc = 0x16AE00u;
        goto label_16ae00;
    }
    ctx->pc = 0x16ADF8u;
    {
        const bool branch_taken_0x16adf8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 16));
        ctx->pc = 0x16ADFCu;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294963632));
        if (branch_taken_0x16adf8) {
            ctx->pc = 0x16AE0Cu;
            goto label_16ae0c;
        }
    }
    ctx->pc = 0x16AE00u;
label_16ae00:
    // 0x16ae00: 0x8c620000
    ctx->pc = 0x16ae00u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_16ae04:
    // 0x16ae04: 0x24420001
    ctx->pc = 0x16ae04u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
label_16ae08:
    // 0x16ae08: 0xac620000
    ctx->pc = 0x16ae08u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_16ae0c:
    // 0x16ae0c: 0x24020001
    ctx->pc = 0x16ae0cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_16ae10:
    // 0x16ae10: 0xdfb00000
    ctx->pc = 0x16ae10u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_16ae14:
    // 0x16ae14: 0xdfb10008
    ctx->pc = 0x16ae14u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_16ae18:
    // 0x16ae18: 0xdfb20010
    ctx->pc = 0x16ae18u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_16ae1c:
    // 0x16ae1c: 0xdfbf0018
    ctx->pc = 0x16ae1cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_16ae20:
    // 0x16ae20: 0x3e00008
label_16ae24:
    if (ctx->pc == 0x16AE24u) {
        ctx->pc = 0x16AE24u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x16AE28u;
        goto label_fallthrough_0x16ae20;
    }
    ctx->pc = 0x16AE20u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x16AE24u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x16AD80u: goto label_16ad80;
            case 0x16AD84u: goto label_16ad84;
            case 0x16AD88u: goto label_16ad88;
            case 0x16AD8Cu: goto label_16ad8c;
            case 0x16AD90u: goto label_16ad90;
            case 0x16AD94u: goto label_16ad94;
            case 0x16AD98u: goto label_16ad98;
            case 0x16AD9Cu: goto label_16ad9c;
            case 0x16ADA0u: goto label_16ada0;
            case 0x16ADA4u: goto label_16ada4;
            case 0x16ADA8u: goto label_16ada8;
            case 0x16ADACu: goto label_16adac;
            case 0x16ADB0u: goto label_16adb0;
            case 0x16ADB4u: goto label_16adb4;
            case 0x16ADB8u: goto label_16adb8;
            case 0x16ADBCu: goto label_16adbc;
            case 0x16ADC0u: goto label_16adc0;
            case 0x16ADC4u: goto label_16adc4;
            case 0x16ADC8u: goto label_16adc8;
            case 0x16ADCCu: goto label_16adcc;
            case 0x16ADD0u: goto label_16add0;
            case 0x16ADD4u: goto label_16add4;
            case 0x16ADD8u: goto label_16add8;
            case 0x16ADDCu: goto label_16addc;
            case 0x16ADE0u: goto label_16ade0;
            case 0x16ADE4u: goto label_16ade4;
            case 0x16ADE8u: goto label_16ade8;
            case 0x16ADECu: goto label_16adec;
            case 0x16ADF0u: goto label_16adf0;
            case 0x16ADF4u: goto label_16adf4;
            case 0x16ADF8u: goto label_16adf8;
            case 0x16ADFCu: goto label_16adfc;
            case 0x16AE00u: goto label_16ae00;
            case 0x16AE04u: goto label_16ae04;
            case 0x16AE08u: goto label_16ae08;
            case 0x16AE0Cu: goto label_16ae0c;
            case 0x16AE10u: goto label_16ae10;
            case 0x16AE14u: goto label_16ae14;
            case 0x16AE18u: goto label_16ae18;
            case 0x16AE1Cu: goto label_16ae1c;
            case 0x16AE20u: goto label_16ae20;
            case 0x16AE24u: goto label_16ae24;
            default: break;
        }
        return;
    }
label_fallthrough_0x16ae20:
    ctx->pc = 0x16AE28u;
}
