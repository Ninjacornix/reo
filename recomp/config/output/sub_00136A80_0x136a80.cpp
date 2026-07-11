#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_00136A80
// Address: 0x136a80 - 0x136f98
void sub_00136A80_0x136a80(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x136a80u;

label_136a80:
    // 0x136a80: 0x14800005
label_136a84:
    if (ctx->pc == 0x136A84u) {
        ctx->pc = 0x136A84u;
        SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
        ctx->pc = 0x136A88u;
        goto label_136a88;
    }
    ctx->pc = 0x136A80u;
    {
        const bool branch_taken_0x136a80 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x136A84u;
        SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
        if (branch_taken_0x136a80) {
            ctx->pc = 0x136A98u;
            goto label_136a98;
        }
    }
    ctx->pc = 0x136A88u;
label_136a88:
    // 0x136a88: 0x3c030022
    ctx->pc = 0x136a88u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
label_136a8c:
    // 0x136a8c: 0xac40bb7c
    ctx->pc = 0x136a8cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294949756), GPR_U32(ctx, 0));
label_136a90:
    // 0x136a90: 0x3e00008
label_136a94:
    if (ctx->pc == 0x136A94u) {
        ctx->pc = 0x136A94u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294949760), GPR_U32(ctx, 0));
        ctx->pc = 0x136A98u;
        goto label_136a98;
    }
    ctx->pc = 0x136A90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136A94u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294949760), GPR_U32(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A80u: goto label_136a80;
            case 0x136A84u: goto label_136a84;
            case 0x136A88u: goto label_136a88;
            case 0x136A8Cu: goto label_136a8c;
            case 0x136A90u: goto label_136a90;
            case 0x136A94u: goto label_136a94;
            case 0x136A98u: goto label_136a98;
            case 0x136A9Cu: goto label_136a9c;
            case 0x136AA0u: goto label_136aa0;
            case 0x136AA4u: goto label_136aa4;
            case 0x136AA8u: goto label_136aa8;
            case 0x136AACu: goto label_136aac;
            case 0x136AB0u: goto label_136ab0;
            case 0x136AB4u: goto label_136ab4;
            case 0x136AB8u: goto label_136ab8;
            case 0x136ABCu: goto label_136abc;
            case 0x136AC0u: goto label_136ac0;
            case 0x136AC4u: goto label_136ac4;
            case 0x136AC8u: goto label_136ac8;
            case 0x136ACCu: goto label_136acc;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AD4u: goto label_136ad4;
            case 0x136AD8u: goto label_136ad8;
            case 0x136ADCu: goto label_136adc;
            case 0x136AE0u: goto label_136ae0;
            case 0x136AE4u: goto label_136ae4;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AECu: goto label_136aec;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF4u: goto label_136af4;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B00u: goto label_136b00;
            case 0x136B04u: goto label_136b04;
            case 0x136B08u: goto label_136b08;
            case 0x136B0Cu: goto label_136b0c;
            case 0x136B10u: goto label_136b10;
            case 0x136B14u: goto label_136b14;
            case 0x136B18u: goto label_136b18;
            case 0x136B1Cu: goto label_136b1c;
            case 0x136B20u: goto label_136b20;
            case 0x136B24u: goto label_136b24;
            case 0x136B28u: goto label_136b28;
            case 0x136B2Cu: goto label_136b2c;
            case 0x136B30u: goto label_136b30;
            case 0x136B34u: goto label_136b34;
            case 0x136B38u: goto label_136b38;
            case 0x136B3Cu: goto label_136b3c;
            case 0x136B40u: goto label_136b40;
            case 0x136B44u: goto label_136b44;
            case 0x136B48u: goto label_136b48;
            case 0x136B4Cu: goto label_136b4c;
            case 0x136B50u: goto label_136b50;
            case 0x136B54u: goto label_136b54;
            case 0x136B58u: goto label_136b58;
            case 0x136B5Cu: goto label_136b5c;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136B68u: goto label_136b68;
            case 0x136B6Cu: goto label_136b6c;
            case 0x136B70u: goto label_136b70;
            case 0x136B74u: goto label_136b74;
            case 0x136B78u: goto label_136b78;
            case 0x136B7Cu: goto label_136b7c;
            case 0x136B80u: goto label_136b80;
            case 0x136B84u: goto label_136b84;
            case 0x136B88u: goto label_136b88;
            case 0x136B8Cu: goto label_136b8c;
            case 0x136B90u: goto label_136b90;
            case 0x136B94u: goto label_136b94;
            case 0x136B98u: goto label_136b98;
            case 0x136B9Cu: goto label_136b9c;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BA4u: goto label_136ba4;
            case 0x136BA8u: goto label_136ba8;
            case 0x136BACu: goto label_136bac;
            case 0x136BB0u: goto label_136bb0;
            case 0x136BB4u: goto label_136bb4;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BBCu: goto label_136bbc;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BC4u: goto label_136bc4;
            case 0x136BC8u: goto label_136bc8;
            case 0x136BCCu: goto label_136bcc;
            case 0x136BD0u: goto label_136bd0;
            case 0x136BD4u: goto label_136bd4;
            case 0x136BD8u: goto label_136bd8;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE0u: goto label_136be0;
            case 0x136BE4u: goto label_136be4;
            case 0x136BE8u: goto label_136be8;
            case 0x136BECu: goto label_136bec;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF4u: goto label_136bf4;
            case 0x136BF8u: goto label_136bf8;
            case 0x136BFCu: goto label_136bfc;
            case 0x136C00u: goto label_136c00;
            case 0x136C04u: goto label_136c04;
            case 0x136C08u: goto label_136c08;
            case 0x136C0Cu: goto label_136c0c;
            case 0x136C10u: goto label_136c10;
            case 0x136C14u: goto label_136c14;
            case 0x136C18u: goto label_136c18;
            case 0x136C1Cu: goto label_136c1c;
            case 0x136C20u: goto label_136c20;
            case 0x136C24u: goto label_136c24;
            case 0x136C28u: goto label_136c28;
            case 0x136C2Cu: goto label_136c2c;
            case 0x136C30u: goto label_136c30;
            case 0x136C34u: goto label_136c34;
            case 0x136C38u: goto label_136c38;
            case 0x136C3Cu: goto label_136c3c;
            case 0x136C40u: goto label_136c40;
            case 0x136C44u: goto label_136c44;
            case 0x136C48u: goto label_136c48;
            case 0x136C4Cu: goto label_136c4c;
            case 0x136C50u: goto label_136c50;
            case 0x136C54u: goto label_136c54;
            case 0x136C58u: goto label_136c58;
            case 0x136C5Cu: goto label_136c5c;
            case 0x136C60u: goto label_136c60;
            case 0x136C64u: goto label_136c64;
            case 0x136C68u: goto label_136c68;
            case 0x136C6Cu: goto label_136c6c;
            case 0x136C70u: goto label_136c70;
            case 0x136C74u: goto label_136c74;
            case 0x136C78u: goto label_136c78;
            case 0x136C7Cu: goto label_136c7c;
            case 0x136C80u: goto label_136c80;
            case 0x136C84u: goto label_136c84;
            case 0x136C88u: goto label_136c88;
            case 0x136C8Cu: goto label_136c8c;
            case 0x136C90u: goto label_136c90;
            case 0x136C94u: goto label_136c94;
            case 0x136C98u: goto label_136c98;
            case 0x136C9Cu: goto label_136c9c;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CA4u: goto label_136ca4;
            case 0x136CA8u: goto label_136ca8;
            case 0x136CACu: goto label_136cac;
            case 0x136CB0u: goto label_136cb0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CB8u: goto label_136cb8;
            case 0x136CBCu: goto label_136cbc;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC4u: goto label_136cc4;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CCCu: goto label_136ccc;
            case 0x136CD0u: goto label_136cd0;
            case 0x136CD4u: goto label_136cd4;
            case 0x136CD8u: goto label_136cd8;
            case 0x136CDCu: goto label_136cdc;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE4u: goto label_136ce4;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CECu: goto label_136cec;
            case 0x136CF0u: goto label_136cf0;
            case 0x136CF4u: goto label_136cf4;
            case 0x136CF8u: goto label_136cf8;
            case 0x136CFCu: goto label_136cfc;
            case 0x136D00u: goto label_136d00;
            case 0x136D04u: goto label_136d04;
            case 0x136D08u: goto label_136d08;
            case 0x136D0Cu: goto label_136d0c;
            case 0x136D10u: goto label_136d10;
            case 0x136D14u: goto label_136d14;
            case 0x136D18u: goto label_136d18;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D20u: goto label_136d20;
            case 0x136D24u: goto label_136d24;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D34u: goto label_136d34;
            case 0x136D38u: goto label_136d38;
            case 0x136D3Cu: goto label_136d3c;
            case 0x136D40u: goto label_136d40;
            case 0x136D44u: goto label_136d44;
            case 0x136D48u: goto label_136d48;
            case 0x136D4Cu: goto label_136d4c;
            case 0x136D50u: goto label_136d50;
            case 0x136D54u: goto label_136d54;
            case 0x136D58u: goto label_136d58;
            case 0x136D5Cu: goto label_136d5c;
            case 0x136D60u: goto label_136d60;
            case 0x136D64u: goto label_136d64;
            case 0x136D68u: goto label_136d68;
            case 0x136D6Cu: goto label_136d6c;
            case 0x136D70u: goto label_136d70;
            case 0x136D74u: goto label_136d74;
            case 0x136D78u: goto label_136d78;
            case 0x136D7Cu: goto label_136d7c;
            case 0x136D80u: goto label_136d80;
            case 0x136D84u: goto label_136d84;
            case 0x136D88u: goto label_136d88;
            case 0x136D8Cu: goto label_136d8c;
            case 0x136D90u: goto label_136d90;
            case 0x136D94u: goto label_136d94;
            case 0x136D98u: goto label_136d98;
            case 0x136D9Cu: goto label_136d9c;
            case 0x136DA0u: goto label_136da0;
            case 0x136DA4u: goto label_136da4;
            case 0x136DA8u: goto label_136da8;
            case 0x136DACu: goto label_136dac;
            case 0x136DB0u: goto label_136db0;
            case 0x136DB4u: goto label_136db4;
            case 0x136DB8u: goto label_136db8;
            case 0x136DBCu: goto label_136dbc;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC4u: goto label_136dc4;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DCCu: goto label_136dcc;
            case 0x136DD0u: goto label_136dd0;
            case 0x136DD4u: goto label_136dd4;
            case 0x136DD8u: goto label_136dd8;
            case 0x136DDCu: goto label_136ddc;
            case 0x136DE0u: goto label_136de0;
            case 0x136DE4u: goto label_136de4;
            case 0x136DE8u: goto label_136de8;
            case 0x136DECu: goto label_136dec;
            case 0x136DF0u: goto label_136df0;
            case 0x136DF4u: goto label_136df4;
            case 0x136DF8u: goto label_136df8;
            case 0x136DFCu: goto label_136dfc;
            case 0x136E00u: goto label_136e00;
            case 0x136E04u: goto label_136e04;
            case 0x136E08u: goto label_136e08;
            case 0x136E0Cu: goto label_136e0c;
            case 0x136E10u: goto label_136e10;
            case 0x136E14u: goto label_136e14;
            case 0x136E18u: goto label_136e18;
            case 0x136E1Cu: goto label_136e1c;
            case 0x136E20u: goto label_136e20;
            case 0x136E24u: goto label_136e24;
            case 0x136E28u: goto label_136e28;
            case 0x136E2Cu: goto label_136e2c;
            case 0x136E30u: goto label_136e30;
            case 0x136E34u: goto label_136e34;
            case 0x136E38u: goto label_136e38;
            case 0x136E3Cu: goto label_136e3c;
            case 0x136E40u: goto label_136e40;
            case 0x136E44u: goto label_136e44;
            case 0x136E48u: goto label_136e48;
            case 0x136E4Cu: goto label_136e4c;
            case 0x136E50u: goto label_136e50;
            case 0x136E54u: goto label_136e54;
            case 0x136E58u: goto label_136e58;
            case 0x136E5Cu: goto label_136e5c;
            case 0x136E60u: goto label_136e60;
            case 0x136E64u: goto label_136e64;
            case 0x136E68u: goto label_136e68;
            case 0x136E6Cu: goto label_136e6c;
            case 0x136E70u: goto label_136e70;
            case 0x136E74u: goto label_136e74;
            case 0x136E78u: goto label_136e78;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E80u: goto label_136e80;
            case 0x136E84u: goto label_136e84;
            case 0x136E88u: goto label_136e88;
            case 0x136E8Cu: goto label_136e8c;
            case 0x136E90u: goto label_136e90;
            case 0x136E94u: goto label_136e94;
            case 0x136E98u: goto label_136e98;
            case 0x136E9Cu: goto label_136e9c;
            case 0x136EA0u: goto label_136ea0;
            case 0x136EA4u: goto label_136ea4;
            case 0x136EA8u: goto label_136ea8;
            case 0x136EACu: goto label_136eac;
            case 0x136EB0u: goto label_136eb0;
            case 0x136EB4u: goto label_136eb4;
            case 0x136EB8u: goto label_136eb8;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EC0u: goto label_136ec0;
            case 0x136EC4u: goto label_136ec4;
            case 0x136EC8u: goto label_136ec8;
            case 0x136ECCu: goto label_136ecc;
            case 0x136ED0u: goto label_136ed0;
            case 0x136ED4u: goto label_136ed4;
            case 0x136ED8u: goto label_136ed8;
            case 0x136EDCu: goto label_136edc;
            case 0x136EE0u: goto label_136ee0;
            case 0x136EE4u: goto label_136ee4;
            case 0x136EE8u: goto label_136ee8;
            case 0x136EECu: goto label_136eec;
            case 0x136EF0u: goto label_136ef0;
            case 0x136EF4u: goto label_136ef4;
            case 0x136EF8u: goto label_136ef8;
            case 0x136EFCu: goto label_136efc;
            case 0x136F00u: goto label_136f00;
            case 0x136F04u: goto label_136f04;
            case 0x136F08u: goto label_136f08;
            case 0x136F0Cu: goto label_136f0c;
            case 0x136F10u: goto label_136f10;
            case 0x136F14u: goto label_136f14;
            case 0x136F18u: goto label_136f18;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F20u: goto label_136f20;
            case 0x136F24u: goto label_136f24;
            case 0x136F28u: goto label_136f28;
            case 0x136F2Cu: goto label_136f2c;
            case 0x136F30u: goto label_136f30;
            case 0x136F34u: goto label_136f34;
            case 0x136F38u: goto label_136f38;
            case 0x136F3Cu: goto label_136f3c;
            case 0x136F40u: goto label_136f40;
            case 0x136F44u: goto label_136f44;
            case 0x136F48u: goto label_136f48;
            case 0x136F4Cu: goto label_136f4c;
            case 0x136F50u: goto label_136f50;
            case 0x136F54u: goto label_136f54;
            case 0x136F58u: goto label_136f58;
            case 0x136F5Cu: goto label_136f5c;
            case 0x136F60u: goto label_136f60;
            case 0x136F64u: goto label_136f64;
            case 0x136F68u: goto label_136f68;
            case 0x136F6Cu: goto label_136f6c;
            case 0x136F70u: goto label_136f70;
            case 0x136F74u: goto label_136f74;
            case 0x136F78u: goto label_136f78;
            case 0x136F7Cu: goto label_136f7c;
            case 0x136F80u: goto label_136f80;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            case 0x136F8Cu: goto label_136f8c;
            case 0x136F90u: goto label_136f90;
            case 0x136F94u: goto label_136f94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136A98u;
label_136a98:
    // 0x136a98: 0x3c030022
    ctx->pc = 0x136a98u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
label_136a9c:
    // 0x136a9c: 0xac44bb7c
    ctx->pc = 0x136a9cu;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294949756), GPR_U32(ctx, 4));
label_136aa0:
    // 0x136aa0: 0x3e00008
label_136aa4:
    if (ctx->pc == 0x136AA4u) {
        ctx->pc = 0x136AA4u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294949760), GPR_U32(ctx, 5));
        ctx->pc = 0x136AA8u;
        goto label_136aa8;
    }
    ctx->pc = 0x136AA0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136AA4u;
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294949760), GPR_U32(ctx, 5));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A80u: goto label_136a80;
            case 0x136A84u: goto label_136a84;
            case 0x136A88u: goto label_136a88;
            case 0x136A8Cu: goto label_136a8c;
            case 0x136A90u: goto label_136a90;
            case 0x136A94u: goto label_136a94;
            case 0x136A98u: goto label_136a98;
            case 0x136A9Cu: goto label_136a9c;
            case 0x136AA0u: goto label_136aa0;
            case 0x136AA4u: goto label_136aa4;
            case 0x136AA8u: goto label_136aa8;
            case 0x136AACu: goto label_136aac;
            case 0x136AB0u: goto label_136ab0;
            case 0x136AB4u: goto label_136ab4;
            case 0x136AB8u: goto label_136ab8;
            case 0x136ABCu: goto label_136abc;
            case 0x136AC0u: goto label_136ac0;
            case 0x136AC4u: goto label_136ac4;
            case 0x136AC8u: goto label_136ac8;
            case 0x136ACCu: goto label_136acc;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AD4u: goto label_136ad4;
            case 0x136AD8u: goto label_136ad8;
            case 0x136ADCu: goto label_136adc;
            case 0x136AE0u: goto label_136ae0;
            case 0x136AE4u: goto label_136ae4;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AECu: goto label_136aec;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF4u: goto label_136af4;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B00u: goto label_136b00;
            case 0x136B04u: goto label_136b04;
            case 0x136B08u: goto label_136b08;
            case 0x136B0Cu: goto label_136b0c;
            case 0x136B10u: goto label_136b10;
            case 0x136B14u: goto label_136b14;
            case 0x136B18u: goto label_136b18;
            case 0x136B1Cu: goto label_136b1c;
            case 0x136B20u: goto label_136b20;
            case 0x136B24u: goto label_136b24;
            case 0x136B28u: goto label_136b28;
            case 0x136B2Cu: goto label_136b2c;
            case 0x136B30u: goto label_136b30;
            case 0x136B34u: goto label_136b34;
            case 0x136B38u: goto label_136b38;
            case 0x136B3Cu: goto label_136b3c;
            case 0x136B40u: goto label_136b40;
            case 0x136B44u: goto label_136b44;
            case 0x136B48u: goto label_136b48;
            case 0x136B4Cu: goto label_136b4c;
            case 0x136B50u: goto label_136b50;
            case 0x136B54u: goto label_136b54;
            case 0x136B58u: goto label_136b58;
            case 0x136B5Cu: goto label_136b5c;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136B68u: goto label_136b68;
            case 0x136B6Cu: goto label_136b6c;
            case 0x136B70u: goto label_136b70;
            case 0x136B74u: goto label_136b74;
            case 0x136B78u: goto label_136b78;
            case 0x136B7Cu: goto label_136b7c;
            case 0x136B80u: goto label_136b80;
            case 0x136B84u: goto label_136b84;
            case 0x136B88u: goto label_136b88;
            case 0x136B8Cu: goto label_136b8c;
            case 0x136B90u: goto label_136b90;
            case 0x136B94u: goto label_136b94;
            case 0x136B98u: goto label_136b98;
            case 0x136B9Cu: goto label_136b9c;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BA4u: goto label_136ba4;
            case 0x136BA8u: goto label_136ba8;
            case 0x136BACu: goto label_136bac;
            case 0x136BB0u: goto label_136bb0;
            case 0x136BB4u: goto label_136bb4;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BBCu: goto label_136bbc;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BC4u: goto label_136bc4;
            case 0x136BC8u: goto label_136bc8;
            case 0x136BCCu: goto label_136bcc;
            case 0x136BD0u: goto label_136bd0;
            case 0x136BD4u: goto label_136bd4;
            case 0x136BD8u: goto label_136bd8;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE0u: goto label_136be0;
            case 0x136BE4u: goto label_136be4;
            case 0x136BE8u: goto label_136be8;
            case 0x136BECu: goto label_136bec;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF4u: goto label_136bf4;
            case 0x136BF8u: goto label_136bf8;
            case 0x136BFCu: goto label_136bfc;
            case 0x136C00u: goto label_136c00;
            case 0x136C04u: goto label_136c04;
            case 0x136C08u: goto label_136c08;
            case 0x136C0Cu: goto label_136c0c;
            case 0x136C10u: goto label_136c10;
            case 0x136C14u: goto label_136c14;
            case 0x136C18u: goto label_136c18;
            case 0x136C1Cu: goto label_136c1c;
            case 0x136C20u: goto label_136c20;
            case 0x136C24u: goto label_136c24;
            case 0x136C28u: goto label_136c28;
            case 0x136C2Cu: goto label_136c2c;
            case 0x136C30u: goto label_136c30;
            case 0x136C34u: goto label_136c34;
            case 0x136C38u: goto label_136c38;
            case 0x136C3Cu: goto label_136c3c;
            case 0x136C40u: goto label_136c40;
            case 0x136C44u: goto label_136c44;
            case 0x136C48u: goto label_136c48;
            case 0x136C4Cu: goto label_136c4c;
            case 0x136C50u: goto label_136c50;
            case 0x136C54u: goto label_136c54;
            case 0x136C58u: goto label_136c58;
            case 0x136C5Cu: goto label_136c5c;
            case 0x136C60u: goto label_136c60;
            case 0x136C64u: goto label_136c64;
            case 0x136C68u: goto label_136c68;
            case 0x136C6Cu: goto label_136c6c;
            case 0x136C70u: goto label_136c70;
            case 0x136C74u: goto label_136c74;
            case 0x136C78u: goto label_136c78;
            case 0x136C7Cu: goto label_136c7c;
            case 0x136C80u: goto label_136c80;
            case 0x136C84u: goto label_136c84;
            case 0x136C88u: goto label_136c88;
            case 0x136C8Cu: goto label_136c8c;
            case 0x136C90u: goto label_136c90;
            case 0x136C94u: goto label_136c94;
            case 0x136C98u: goto label_136c98;
            case 0x136C9Cu: goto label_136c9c;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CA4u: goto label_136ca4;
            case 0x136CA8u: goto label_136ca8;
            case 0x136CACu: goto label_136cac;
            case 0x136CB0u: goto label_136cb0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CB8u: goto label_136cb8;
            case 0x136CBCu: goto label_136cbc;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC4u: goto label_136cc4;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CCCu: goto label_136ccc;
            case 0x136CD0u: goto label_136cd0;
            case 0x136CD4u: goto label_136cd4;
            case 0x136CD8u: goto label_136cd8;
            case 0x136CDCu: goto label_136cdc;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE4u: goto label_136ce4;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CECu: goto label_136cec;
            case 0x136CF0u: goto label_136cf0;
            case 0x136CF4u: goto label_136cf4;
            case 0x136CF8u: goto label_136cf8;
            case 0x136CFCu: goto label_136cfc;
            case 0x136D00u: goto label_136d00;
            case 0x136D04u: goto label_136d04;
            case 0x136D08u: goto label_136d08;
            case 0x136D0Cu: goto label_136d0c;
            case 0x136D10u: goto label_136d10;
            case 0x136D14u: goto label_136d14;
            case 0x136D18u: goto label_136d18;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D20u: goto label_136d20;
            case 0x136D24u: goto label_136d24;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D34u: goto label_136d34;
            case 0x136D38u: goto label_136d38;
            case 0x136D3Cu: goto label_136d3c;
            case 0x136D40u: goto label_136d40;
            case 0x136D44u: goto label_136d44;
            case 0x136D48u: goto label_136d48;
            case 0x136D4Cu: goto label_136d4c;
            case 0x136D50u: goto label_136d50;
            case 0x136D54u: goto label_136d54;
            case 0x136D58u: goto label_136d58;
            case 0x136D5Cu: goto label_136d5c;
            case 0x136D60u: goto label_136d60;
            case 0x136D64u: goto label_136d64;
            case 0x136D68u: goto label_136d68;
            case 0x136D6Cu: goto label_136d6c;
            case 0x136D70u: goto label_136d70;
            case 0x136D74u: goto label_136d74;
            case 0x136D78u: goto label_136d78;
            case 0x136D7Cu: goto label_136d7c;
            case 0x136D80u: goto label_136d80;
            case 0x136D84u: goto label_136d84;
            case 0x136D88u: goto label_136d88;
            case 0x136D8Cu: goto label_136d8c;
            case 0x136D90u: goto label_136d90;
            case 0x136D94u: goto label_136d94;
            case 0x136D98u: goto label_136d98;
            case 0x136D9Cu: goto label_136d9c;
            case 0x136DA0u: goto label_136da0;
            case 0x136DA4u: goto label_136da4;
            case 0x136DA8u: goto label_136da8;
            case 0x136DACu: goto label_136dac;
            case 0x136DB0u: goto label_136db0;
            case 0x136DB4u: goto label_136db4;
            case 0x136DB8u: goto label_136db8;
            case 0x136DBCu: goto label_136dbc;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC4u: goto label_136dc4;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DCCu: goto label_136dcc;
            case 0x136DD0u: goto label_136dd0;
            case 0x136DD4u: goto label_136dd4;
            case 0x136DD8u: goto label_136dd8;
            case 0x136DDCu: goto label_136ddc;
            case 0x136DE0u: goto label_136de0;
            case 0x136DE4u: goto label_136de4;
            case 0x136DE8u: goto label_136de8;
            case 0x136DECu: goto label_136dec;
            case 0x136DF0u: goto label_136df0;
            case 0x136DF4u: goto label_136df4;
            case 0x136DF8u: goto label_136df8;
            case 0x136DFCu: goto label_136dfc;
            case 0x136E00u: goto label_136e00;
            case 0x136E04u: goto label_136e04;
            case 0x136E08u: goto label_136e08;
            case 0x136E0Cu: goto label_136e0c;
            case 0x136E10u: goto label_136e10;
            case 0x136E14u: goto label_136e14;
            case 0x136E18u: goto label_136e18;
            case 0x136E1Cu: goto label_136e1c;
            case 0x136E20u: goto label_136e20;
            case 0x136E24u: goto label_136e24;
            case 0x136E28u: goto label_136e28;
            case 0x136E2Cu: goto label_136e2c;
            case 0x136E30u: goto label_136e30;
            case 0x136E34u: goto label_136e34;
            case 0x136E38u: goto label_136e38;
            case 0x136E3Cu: goto label_136e3c;
            case 0x136E40u: goto label_136e40;
            case 0x136E44u: goto label_136e44;
            case 0x136E48u: goto label_136e48;
            case 0x136E4Cu: goto label_136e4c;
            case 0x136E50u: goto label_136e50;
            case 0x136E54u: goto label_136e54;
            case 0x136E58u: goto label_136e58;
            case 0x136E5Cu: goto label_136e5c;
            case 0x136E60u: goto label_136e60;
            case 0x136E64u: goto label_136e64;
            case 0x136E68u: goto label_136e68;
            case 0x136E6Cu: goto label_136e6c;
            case 0x136E70u: goto label_136e70;
            case 0x136E74u: goto label_136e74;
            case 0x136E78u: goto label_136e78;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E80u: goto label_136e80;
            case 0x136E84u: goto label_136e84;
            case 0x136E88u: goto label_136e88;
            case 0x136E8Cu: goto label_136e8c;
            case 0x136E90u: goto label_136e90;
            case 0x136E94u: goto label_136e94;
            case 0x136E98u: goto label_136e98;
            case 0x136E9Cu: goto label_136e9c;
            case 0x136EA0u: goto label_136ea0;
            case 0x136EA4u: goto label_136ea4;
            case 0x136EA8u: goto label_136ea8;
            case 0x136EACu: goto label_136eac;
            case 0x136EB0u: goto label_136eb0;
            case 0x136EB4u: goto label_136eb4;
            case 0x136EB8u: goto label_136eb8;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EC0u: goto label_136ec0;
            case 0x136EC4u: goto label_136ec4;
            case 0x136EC8u: goto label_136ec8;
            case 0x136ECCu: goto label_136ecc;
            case 0x136ED0u: goto label_136ed0;
            case 0x136ED4u: goto label_136ed4;
            case 0x136ED8u: goto label_136ed8;
            case 0x136EDCu: goto label_136edc;
            case 0x136EE0u: goto label_136ee0;
            case 0x136EE4u: goto label_136ee4;
            case 0x136EE8u: goto label_136ee8;
            case 0x136EECu: goto label_136eec;
            case 0x136EF0u: goto label_136ef0;
            case 0x136EF4u: goto label_136ef4;
            case 0x136EF8u: goto label_136ef8;
            case 0x136EFCu: goto label_136efc;
            case 0x136F00u: goto label_136f00;
            case 0x136F04u: goto label_136f04;
            case 0x136F08u: goto label_136f08;
            case 0x136F0Cu: goto label_136f0c;
            case 0x136F10u: goto label_136f10;
            case 0x136F14u: goto label_136f14;
            case 0x136F18u: goto label_136f18;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F20u: goto label_136f20;
            case 0x136F24u: goto label_136f24;
            case 0x136F28u: goto label_136f28;
            case 0x136F2Cu: goto label_136f2c;
            case 0x136F30u: goto label_136f30;
            case 0x136F34u: goto label_136f34;
            case 0x136F38u: goto label_136f38;
            case 0x136F3Cu: goto label_136f3c;
            case 0x136F40u: goto label_136f40;
            case 0x136F44u: goto label_136f44;
            case 0x136F48u: goto label_136f48;
            case 0x136F4Cu: goto label_136f4c;
            case 0x136F50u: goto label_136f50;
            case 0x136F54u: goto label_136f54;
            case 0x136F58u: goto label_136f58;
            case 0x136F5Cu: goto label_136f5c;
            case 0x136F60u: goto label_136f60;
            case 0x136F64u: goto label_136f64;
            case 0x136F68u: goto label_136f68;
            case 0x136F6Cu: goto label_136f6c;
            case 0x136F70u: goto label_136f70;
            case 0x136F74u: goto label_136f74;
            case 0x136F78u: goto label_136f78;
            case 0x136F7Cu: goto label_136f7c;
            case 0x136F80u: goto label_136f80;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            case 0x136F8Cu: goto label_136f8c;
            case 0x136F90u: goto label_136f90;
            case 0x136F94u: goto label_136f94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136AA8u;
label_136aa8:
    // 0x136aa8: 0x27bdfff0
    ctx->pc = 0x136aa8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
label_136aac:
    // 0x136aac: 0xffb00000
    ctx->pc = 0x136aacu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_136ab0:
    // 0x136ab0: 0x802d
    ctx->pc = 0x136ab0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_136ab4:
    // 0x136ab4: 0x14800006
label_136ab8:
    if (ctx->pc == 0x136AB8u) {
        ctx->pc = 0x136AB8u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->pc = 0x136ABCu;
        goto label_136abc;
    }
    ctx->pc = 0x136AB4u;
    {
        const bool branch_taken_0x136ab4 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x136AB8u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        if (branch_taken_0x136ab4) {
            ctx->pc = 0x136AD0u;
            goto label_136ad0;
        }
    }
    ctx->pc = 0x136ABCu;
label_136abc:
    // 0x136abc: 0x3c040024
    ctx->pc = 0x136abcu;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_136ac0:
    // 0x136ac0: 0xc04d480
label_136ac4:
    if (ctx->pc == 0x136AC4u) {
        ctx->pc = 0x136AC4u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951104));
        ctx->pc = 0x136AC8u;
        goto label_136ac8;
    }
    ctx->pc = 0x136AC0u;
    SET_GPR_U32(ctx, 31, 0x136AC8u);
    ctx->pc = 0x136AC4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951104));
    ctx->pc = 0x135200u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136AC8u; }
    }
    if (ctx->pc != 0x136AC8u) { return; }
    ctx->pc = 0x136AC8u;
label_136ac8:
    // 0x136ac8: 0x1000000c
label_136acc:
    if (ctx->pc == 0x136ACCu) {
        ctx->pc = 0x136ACCu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x136AD0u;
        goto label_136ad0;
    }
    ctx->pc = 0x136AC8u;
    {
        const bool branch_taken_0x136ac8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136ACCu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x136ac8) {
            ctx->pc = 0x136AFCu;
            goto label_136afc;
        }
    }
    ctx->pc = 0x136AD0u;
label_136ad0:
    // 0x136ad0: 0x8c820000
    ctx->pc = 0x136ad0u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_136ad4:
    // 0x136ad4: 0x8c420060
    ctx->pc = 0x136ad4u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 96)));
label_136ad8:
    // 0x136ad8: 0x50400005
label_136adc:
    if (ctx->pc == 0x136ADCu) {
        ctx->pc = 0x136ADCu;
        SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
        ctx->pc = 0x136AE0u;
        goto label_136ae0;
    }
    ctx->pc = 0x136AD8u;
    {
        const bool branch_taken_0x136ad8 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x136ad8) {
            ctx->pc = 0x136ADCu;
            SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
            ctx->pc = 0x136AF0u;
            goto label_136af0;
        }
    }
    ctx->pc = 0x136AE0u;
label_136ae0:
    // 0x136ae0: 0x40f809
label_136ae4:
    if (ctx->pc == 0x136AE4u) {
        ctx->pc = 0x136AE4u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->pc = 0x136AE8u;
        goto label_136ae8;
    }
    ctx->pc = 0x136AE0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136AE8u);
        ctx->pc = 0x136AE4u;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A80u: goto label_136a80;
            case 0x136A84u: goto label_136a84;
            case 0x136A88u: goto label_136a88;
            case 0x136A8Cu: goto label_136a8c;
            case 0x136A90u: goto label_136a90;
            case 0x136A94u: goto label_136a94;
            case 0x136A98u: goto label_136a98;
            case 0x136A9Cu: goto label_136a9c;
            case 0x136AA0u: goto label_136aa0;
            case 0x136AA4u: goto label_136aa4;
            case 0x136AA8u: goto label_136aa8;
            case 0x136AACu: goto label_136aac;
            case 0x136AB0u: goto label_136ab0;
            case 0x136AB4u: goto label_136ab4;
            case 0x136AB8u: goto label_136ab8;
            case 0x136ABCu: goto label_136abc;
            case 0x136AC0u: goto label_136ac0;
            case 0x136AC4u: goto label_136ac4;
            case 0x136AC8u: goto label_136ac8;
            case 0x136ACCu: goto label_136acc;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AD4u: goto label_136ad4;
            case 0x136AD8u: goto label_136ad8;
            case 0x136ADCu: goto label_136adc;
            case 0x136AE0u: goto label_136ae0;
            case 0x136AE4u: goto label_136ae4;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AECu: goto label_136aec;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF4u: goto label_136af4;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B00u: goto label_136b00;
            case 0x136B04u: goto label_136b04;
            case 0x136B08u: goto label_136b08;
            case 0x136B0Cu: goto label_136b0c;
            case 0x136B10u: goto label_136b10;
            case 0x136B14u: goto label_136b14;
            case 0x136B18u: goto label_136b18;
            case 0x136B1Cu: goto label_136b1c;
            case 0x136B20u: goto label_136b20;
            case 0x136B24u: goto label_136b24;
            case 0x136B28u: goto label_136b28;
            case 0x136B2Cu: goto label_136b2c;
            case 0x136B30u: goto label_136b30;
            case 0x136B34u: goto label_136b34;
            case 0x136B38u: goto label_136b38;
            case 0x136B3Cu: goto label_136b3c;
            case 0x136B40u: goto label_136b40;
            case 0x136B44u: goto label_136b44;
            case 0x136B48u: goto label_136b48;
            case 0x136B4Cu: goto label_136b4c;
            case 0x136B50u: goto label_136b50;
            case 0x136B54u: goto label_136b54;
            case 0x136B58u: goto label_136b58;
            case 0x136B5Cu: goto label_136b5c;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136B68u: goto label_136b68;
            case 0x136B6Cu: goto label_136b6c;
            case 0x136B70u: goto label_136b70;
            case 0x136B74u: goto label_136b74;
            case 0x136B78u: goto label_136b78;
            case 0x136B7Cu: goto label_136b7c;
            case 0x136B80u: goto label_136b80;
            case 0x136B84u: goto label_136b84;
            case 0x136B88u: goto label_136b88;
            case 0x136B8Cu: goto label_136b8c;
            case 0x136B90u: goto label_136b90;
            case 0x136B94u: goto label_136b94;
            case 0x136B98u: goto label_136b98;
            case 0x136B9Cu: goto label_136b9c;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BA4u: goto label_136ba4;
            case 0x136BA8u: goto label_136ba8;
            case 0x136BACu: goto label_136bac;
            case 0x136BB0u: goto label_136bb0;
            case 0x136BB4u: goto label_136bb4;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BBCu: goto label_136bbc;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BC4u: goto label_136bc4;
            case 0x136BC8u: goto label_136bc8;
            case 0x136BCCu: goto label_136bcc;
            case 0x136BD0u: goto label_136bd0;
            case 0x136BD4u: goto label_136bd4;
            case 0x136BD8u: goto label_136bd8;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE0u: goto label_136be0;
            case 0x136BE4u: goto label_136be4;
            case 0x136BE8u: goto label_136be8;
            case 0x136BECu: goto label_136bec;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF4u: goto label_136bf4;
            case 0x136BF8u: goto label_136bf8;
            case 0x136BFCu: goto label_136bfc;
            case 0x136C00u: goto label_136c00;
            case 0x136C04u: goto label_136c04;
            case 0x136C08u: goto label_136c08;
            case 0x136C0Cu: goto label_136c0c;
            case 0x136C10u: goto label_136c10;
            case 0x136C14u: goto label_136c14;
            case 0x136C18u: goto label_136c18;
            case 0x136C1Cu: goto label_136c1c;
            case 0x136C20u: goto label_136c20;
            case 0x136C24u: goto label_136c24;
            case 0x136C28u: goto label_136c28;
            case 0x136C2Cu: goto label_136c2c;
            case 0x136C30u: goto label_136c30;
            case 0x136C34u: goto label_136c34;
            case 0x136C38u: goto label_136c38;
            case 0x136C3Cu: goto label_136c3c;
            case 0x136C40u: goto label_136c40;
            case 0x136C44u: goto label_136c44;
            case 0x136C48u: goto label_136c48;
            case 0x136C4Cu: goto label_136c4c;
            case 0x136C50u: goto label_136c50;
            case 0x136C54u: goto label_136c54;
            case 0x136C58u: goto label_136c58;
            case 0x136C5Cu: goto label_136c5c;
            case 0x136C60u: goto label_136c60;
            case 0x136C64u: goto label_136c64;
            case 0x136C68u: goto label_136c68;
            case 0x136C6Cu: goto label_136c6c;
            case 0x136C70u: goto label_136c70;
            case 0x136C74u: goto label_136c74;
            case 0x136C78u: goto label_136c78;
            case 0x136C7Cu: goto label_136c7c;
            case 0x136C80u: goto label_136c80;
            case 0x136C84u: goto label_136c84;
            case 0x136C88u: goto label_136c88;
            case 0x136C8Cu: goto label_136c8c;
            case 0x136C90u: goto label_136c90;
            case 0x136C94u: goto label_136c94;
            case 0x136C98u: goto label_136c98;
            case 0x136C9Cu: goto label_136c9c;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CA4u: goto label_136ca4;
            case 0x136CA8u: goto label_136ca8;
            case 0x136CACu: goto label_136cac;
            case 0x136CB0u: goto label_136cb0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CB8u: goto label_136cb8;
            case 0x136CBCu: goto label_136cbc;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC4u: goto label_136cc4;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CCCu: goto label_136ccc;
            case 0x136CD0u: goto label_136cd0;
            case 0x136CD4u: goto label_136cd4;
            case 0x136CD8u: goto label_136cd8;
            case 0x136CDCu: goto label_136cdc;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE4u: goto label_136ce4;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CECu: goto label_136cec;
            case 0x136CF0u: goto label_136cf0;
            case 0x136CF4u: goto label_136cf4;
            case 0x136CF8u: goto label_136cf8;
            case 0x136CFCu: goto label_136cfc;
            case 0x136D00u: goto label_136d00;
            case 0x136D04u: goto label_136d04;
            case 0x136D08u: goto label_136d08;
            case 0x136D0Cu: goto label_136d0c;
            case 0x136D10u: goto label_136d10;
            case 0x136D14u: goto label_136d14;
            case 0x136D18u: goto label_136d18;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D20u: goto label_136d20;
            case 0x136D24u: goto label_136d24;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D34u: goto label_136d34;
            case 0x136D38u: goto label_136d38;
            case 0x136D3Cu: goto label_136d3c;
            case 0x136D40u: goto label_136d40;
            case 0x136D44u: goto label_136d44;
            case 0x136D48u: goto label_136d48;
            case 0x136D4Cu: goto label_136d4c;
            case 0x136D50u: goto label_136d50;
            case 0x136D54u: goto label_136d54;
            case 0x136D58u: goto label_136d58;
            case 0x136D5Cu: goto label_136d5c;
            case 0x136D60u: goto label_136d60;
            case 0x136D64u: goto label_136d64;
            case 0x136D68u: goto label_136d68;
            case 0x136D6Cu: goto label_136d6c;
            case 0x136D70u: goto label_136d70;
            case 0x136D74u: goto label_136d74;
            case 0x136D78u: goto label_136d78;
            case 0x136D7Cu: goto label_136d7c;
            case 0x136D80u: goto label_136d80;
            case 0x136D84u: goto label_136d84;
            case 0x136D88u: goto label_136d88;
            case 0x136D8Cu: goto label_136d8c;
            case 0x136D90u: goto label_136d90;
            case 0x136D94u: goto label_136d94;
            case 0x136D98u: goto label_136d98;
            case 0x136D9Cu: goto label_136d9c;
            case 0x136DA0u: goto label_136da0;
            case 0x136DA4u: goto label_136da4;
            case 0x136DA8u: goto label_136da8;
            case 0x136DACu: goto label_136dac;
            case 0x136DB0u: goto label_136db0;
            case 0x136DB4u: goto label_136db4;
            case 0x136DB8u: goto label_136db8;
            case 0x136DBCu: goto label_136dbc;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC4u: goto label_136dc4;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DCCu: goto label_136dcc;
            case 0x136DD0u: goto label_136dd0;
            case 0x136DD4u: goto label_136dd4;
            case 0x136DD8u: goto label_136dd8;
            case 0x136DDCu: goto label_136ddc;
            case 0x136DE0u: goto label_136de0;
            case 0x136DE4u: goto label_136de4;
            case 0x136DE8u: goto label_136de8;
            case 0x136DECu: goto label_136dec;
            case 0x136DF0u: goto label_136df0;
            case 0x136DF4u: goto label_136df4;
            case 0x136DF8u: goto label_136df8;
            case 0x136DFCu: goto label_136dfc;
            case 0x136E00u: goto label_136e00;
            case 0x136E04u: goto label_136e04;
            case 0x136E08u: goto label_136e08;
            case 0x136E0Cu: goto label_136e0c;
            case 0x136E10u: goto label_136e10;
            case 0x136E14u: goto label_136e14;
            case 0x136E18u: goto label_136e18;
            case 0x136E1Cu: goto label_136e1c;
            case 0x136E20u: goto label_136e20;
            case 0x136E24u: goto label_136e24;
            case 0x136E28u: goto label_136e28;
            case 0x136E2Cu: goto label_136e2c;
            case 0x136E30u: goto label_136e30;
            case 0x136E34u: goto label_136e34;
            case 0x136E38u: goto label_136e38;
            case 0x136E3Cu: goto label_136e3c;
            case 0x136E40u: goto label_136e40;
            case 0x136E44u: goto label_136e44;
            case 0x136E48u: goto label_136e48;
            case 0x136E4Cu: goto label_136e4c;
            case 0x136E50u: goto label_136e50;
            case 0x136E54u: goto label_136e54;
            case 0x136E58u: goto label_136e58;
            case 0x136E5Cu: goto label_136e5c;
            case 0x136E60u: goto label_136e60;
            case 0x136E64u: goto label_136e64;
            case 0x136E68u: goto label_136e68;
            case 0x136E6Cu: goto label_136e6c;
            case 0x136E70u: goto label_136e70;
            case 0x136E74u: goto label_136e74;
            case 0x136E78u: goto label_136e78;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E80u: goto label_136e80;
            case 0x136E84u: goto label_136e84;
            case 0x136E88u: goto label_136e88;
            case 0x136E8Cu: goto label_136e8c;
            case 0x136E90u: goto label_136e90;
            case 0x136E94u: goto label_136e94;
            case 0x136E98u: goto label_136e98;
            case 0x136E9Cu: goto label_136e9c;
            case 0x136EA0u: goto label_136ea0;
            case 0x136EA4u: goto label_136ea4;
            case 0x136EA8u: goto label_136ea8;
            case 0x136EACu: goto label_136eac;
            case 0x136EB0u: goto label_136eb0;
            case 0x136EB4u: goto label_136eb4;
            case 0x136EB8u: goto label_136eb8;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EC0u: goto label_136ec0;
            case 0x136EC4u: goto label_136ec4;
            case 0x136EC8u: goto label_136ec8;
            case 0x136ECCu: goto label_136ecc;
            case 0x136ED0u: goto label_136ed0;
            case 0x136ED4u: goto label_136ed4;
            case 0x136ED8u: goto label_136ed8;
            case 0x136EDCu: goto label_136edc;
            case 0x136EE0u: goto label_136ee0;
            case 0x136EE4u: goto label_136ee4;
            case 0x136EE8u: goto label_136ee8;
            case 0x136EECu: goto label_136eec;
            case 0x136EF0u: goto label_136ef0;
            case 0x136EF4u: goto label_136ef4;
            case 0x136EF8u: goto label_136ef8;
            case 0x136EFCu: goto label_136efc;
            case 0x136F00u: goto label_136f00;
            case 0x136F04u: goto label_136f04;
            case 0x136F08u: goto label_136f08;
            case 0x136F0Cu: goto label_136f0c;
            case 0x136F10u: goto label_136f10;
            case 0x136F14u: goto label_136f14;
            case 0x136F18u: goto label_136f18;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F20u: goto label_136f20;
            case 0x136F24u: goto label_136f24;
            case 0x136F28u: goto label_136f28;
            case 0x136F2Cu: goto label_136f2c;
            case 0x136F30u: goto label_136f30;
            case 0x136F34u: goto label_136f34;
            case 0x136F38u: goto label_136f38;
            case 0x136F3Cu: goto label_136f3c;
            case 0x136F40u: goto label_136f40;
            case 0x136F44u: goto label_136f44;
            case 0x136F48u: goto label_136f48;
            case 0x136F4Cu: goto label_136f4c;
            case 0x136F50u: goto label_136f50;
            case 0x136F54u: goto label_136f54;
            case 0x136F58u: goto label_136f58;
            case 0x136F5Cu: goto label_136f5c;
            case 0x136F60u: goto label_136f60;
            case 0x136F64u: goto label_136f64;
            case 0x136F68u: goto label_136f68;
            case 0x136F6Cu: goto label_136f6c;
            case 0x136F70u: goto label_136f70;
            case 0x136F74u: goto label_136f74;
            case 0x136F78u: goto label_136f78;
            case 0x136F7Cu: goto label_136f7c;
            case 0x136F80u: goto label_136f80;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            case 0x136F8Cu: goto label_136f8c;
            case 0x136F90u: goto label_136f90;
            case 0x136F94u: goto label_136f94;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136AE8u; }
            if (ctx->pc != 0x136AE8u) { return; }
        }
    }
    ctx->pc = 0x136AE8u;
label_136ae8:
    // 0x136ae8: 0x10000003
label_136aec:
    if (ctx->pc == 0x136AECu) {
        ctx->pc = 0x136AECu;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x136AF0u;
        goto label_136af0;
    }
    ctx->pc = 0x136AE8u;
    {
        const bool branch_taken_0x136ae8 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136AECu;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x136ae8) {
            ctx->pc = 0x136AF8u;
            goto label_136af8;
        }
    }
    ctx->pc = 0x136AF0u;
label_136af0:
    // 0x136af0: 0xc04d480
label_136af4:
    if (ctx->pc == 0x136AF4u) {
        ctx->pc = 0x136AF4u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951136));
        ctx->pc = 0x136AF8u;
        goto label_136af8;
    }
    ctx->pc = 0x136AF0u;
    SET_GPR_U32(ctx, 31, 0x136AF8u);
    ctx->pc = 0x136AF4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951136));
    ctx->pc = 0x135200u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136AF8u; }
    }
    if (ctx->pc != 0x136AF8u) { return; }
    ctx->pc = 0x136AF8u;
label_136af8:
    // 0x136af8: 0x200102d
    ctx->pc = 0x136af8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_136afc:
    // 0x136afc: 0xdfb00000
    ctx->pc = 0x136afcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_136b00:
    // 0x136b00: 0xdfbf0008
    ctx->pc = 0x136b00u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_136b04:
    // 0x136b04: 0x3e00008
label_136b08:
    if (ctx->pc == 0x136B08u) {
        ctx->pc = 0x136B08u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = 0x136B0Cu;
        goto label_136b0c;
    }
    ctx->pc = 0x136B04u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136B08u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A80u: goto label_136a80;
            case 0x136A84u: goto label_136a84;
            case 0x136A88u: goto label_136a88;
            case 0x136A8Cu: goto label_136a8c;
            case 0x136A90u: goto label_136a90;
            case 0x136A94u: goto label_136a94;
            case 0x136A98u: goto label_136a98;
            case 0x136A9Cu: goto label_136a9c;
            case 0x136AA0u: goto label_136aa0;
            case 0x136AA4u: goto label_136aa4;
            case 0x136AA8u: goto label_136aa8;
            case 0x136AACu: goto label_136aac;
            case 0x136AB0u: goto label_136ab0;
            case 0x136AB4u: goto label_136ab4;
            case 0x136AB8u: goto label_136ab8;
            case 0x136ABCu: goto label_136abc;
            case 0x136AC0u: goto label_136ac0;
            case 0x136AC4u: goto label_136ac4;
            case 0x136AC8u: goto label_136ac8;
            case 0x136ACCu: goto label_136acc;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AD4u: goto label_136ad4;
            case 0x136AD8u: goto label_136ad8;
            case 0x136ADCu: goto label_136adc;
            case 0x136AE0u: goto label_136ae0;
            case 0x136AE4u: goto label_136ae4;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AECu: goto label_136aec;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF4u: goto label_136af4;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B00u: goto label_136b00;
            case 0x136B04u: goto label_136b04;
            case 0x136B08u: goto label_136b08;
            case 0x136B0Cu: goto label_136b0c;
            case 0x136B10u: goto label_136b10;
            case 0x136B14u: goto label_136b14;
            case 0x136B18u: goto label_136b18;
            case 0x136B1Cu: goto label_136b1c;
            case 0x136B20u: goto label_136b20;
            case 0x136B24u: goto label_136b24;
            case 0x136B28u: goto label_136b28;
            case 0x136B2Cu: goto label_136b2c;
            case 0x136B30u: goto label_136b30;
            case 0x136B34u: goto label_136b34;
            case 0x136B38u: goto label_136b38;
            case 0x136B3Cu: goto label_136b3c;
            case 0x136B40u: goto label_136b40;
            case 0x136B44u: goto label_136b44;
            case 0x136B48u: goto label_136b48;
            case 0x136B4Cu: goto label_136b4c;
            case 0x136B50u: goto label_136b50;
            case 0x136B54u: goto label_136b54;
            case 0x136B58u: goto label_136b58;
            case 0x136B5Cu: goto label_136b5c;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136B68u: goto label_136b68;
            case 0x136B6Cu: goto label_136b6c;
            case 0x136B70u: goto label_136b70;
            case 0x136B74u: goto label_136b74;
            case 0x136B78u: goto label_136b78;
            case 0x136B7Cu: goto label_136b7c;
            case 0x136B80u: goto label_136b80;
            case 0x136B84u: goto label_136b84;
            case 0x136B88u: goto label_136b88;
            case 0x136B8Cu: goto label_136b8c;
            case 0x136B90u: goto label_136b90;
            case 0x136B94u: goto label_136b94;
            case 0x136B98u: goto label_136b98;
            case 0x136B9Cu: goto label_136b9c;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BA4u: goto label_136ba4;
            case 0x136BA8u: goto label_136ba8;
            case 0x136BACu: goto label_136bac;
            case 0x136BB0u: goto label_136bb0;
            case 0x136BB4u: goto label_136bb4;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BBCu: goto label_136bbc;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BC4u: goto label_136bc4;
            case 0x136BC8u: goto label_136bc8;
            case 0x136BCCu: goto label_136bcc;
            case 0x136BD0u: goto label_136bd0;
            case 0x136BD4u: goto label_136bd4;
            case 0x136BD8u: goto label_136bd8;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE0u: goto label_136be0;
            case 0x136BE4u: goto label_136be4;
            case 0x136BE8u: goto label_136be8;
            case 0x136BECu: goto label_136bec;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF4u: goto label_136bf4;
            case 0x136BF8u: goto label_136bf8;
            case 0x136BFCu: goto label_136bfc;
            case 0x136C00u: goto label_136c00;
            case 0x136C04u: goto label_136c04;
            case 0x136C08u: goto label_136c08;
            case 0x136C0Cu: goto label_136c0c;
            case 0x136C10u: goto label_136c10;
            case 0x136C14u: goto label_136c14;
            case 0x136C18u: goto label_136c18;
            case 0x136C1Cu: goto label_136c1c;
            case 0x136C20u: goto label_136c20;
            case 0x136C24u: goto label_136c24;
            case 0x136C28u: goto label_136c28;
            case 0x136C2Cu: goto label_136c2c;
            case 0x136C30u: goto label_136c30;
            case 0x136C34u: goto label_136c34;
            case 0x136C38u: goto label_136c38;
            case 0x136C3Cu: goto label_136c3c;
            case 0x136C40u: goto label_136c40;
            case 0x136C44u: goto label_136c44;
            case 0x136C48u: goto label_136c48;
            case 0x136C4Cu: goto label_136c4c;
            case 0x136C50u: goto label_136c50;
            case 0x136C54u: goto label_136c54;
            case 0x136C58u: goto label_136c58;
            case 0x136C5Cu: goto label_136c5c;
            case 0x136C60u: goto label_136c60;
            case 0x136C64u: goto label_136c64;
            case 0x136C68u: goto label_136c68;
            case 0x136C6Cu: goto label_136c6c;
            case 0x136C70u: goto label_136c70;
            case 0x136C74u: goto label_136c74;
            case 0x136C78u: goto label_136c78;
            case 0x136C7Cu: goto label_136c7c;
            case 0x136C80u: goto label_136c80;
            case 0x136C84u: goto label_136c84;
            case 0x136C88u: goto label_136c88;
            case 0x136C8Cu: goto label_136c8c;
            case 0x136C90u: goto label_136c90;
            case 0x136C94u: goto label_136c94;
            case 0x136C98u: goto label_136c98;
            case 0x136C9Cu: goto label_136c9c;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CA4u: goto label_136ca4;
            case 0x136CA8u: goto label_136ca8;
            case 0x136CACu: goto label_136cac;
            case 0x136CB0u: goto label_136cb0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CB8u: goto label_136cb8;
            case 0x136CBCu: goto label_136cbc;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC4u: goto label_136cc4;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CCCu: goto label_136ccc;
            case 0x136CD0u: goto label_136cd0;
            case 0x136CD4u: goto label_136cd4;
            case 0x136CD8u: goto label_136cd8;
            case 0x136CDCu: goto label_136cdc;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE4u: goto label_136ce4;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CECu: goto label_136cec;
            case 0x136CF0u: goto label_136cf0;
            case 0x136CF4u: goto label_136cf4;
            case 0x136CF8u: goto label_136cf8;
            case 0x136CFCu: goto label_136cfc;
            case 0x136D00u: goto label_136d00;
            case 0x136D04u: goto label_136d04;
            case 0x136D08u: goto label_136d08;
            case 0x136D0Cu: goto label_136d0c;
            case 0x136D10u: goto label_136d10;
            case 0x136D14u: goto label_136d14;
            case 0x136D18u: goto label_136d18;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D20u: goto label_136d20;
            case 0x136D24u: goto label_136d24;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D34u: goto label_136d34;
            case 0x136D38u: goto label_136d38;
            case 0x136D3Cu: goto label_136d3c;
            case 0x136D40u: goto label_136d40;
            case 0x136D44u: goto label_136d44;
            case 0x136D48u: goto label_136d48;
            case 0x136D4Cu: goto label_136d4c;
            case 0x136D50u: goto label_136d50;
            case 0x136D54u: goto label_136d54;
            case 0x136D58u: goto label_136d58;
            case 0x136D5Cu: goto label_136d5c;
            case 0x136D60u: goto label_136d60;
            case 0x136D64u: goto label_136d64;
            case 0x136D68u: goto label_136d68;
            case 0x136D6Cu: goto label_136d6c;
            case 0x136D70u: goto label_136d70;
            case 0x136D74u: goto label_136d74;
            case 0x136D78u: goto label_136d78;
            case 0x136D7Cu: goto label_136d7c;
            case 0x136D80u: goto label_136d80;
            case 0x136D84u: goto label_136d84;
            case 0x136D88u: goto label_136d88;
            case 0x136D8Cu: goto label_136d8c;
            case 0x136D90u: goto label_136d90;
            case 0x136D94u: goto label_136d94;
            case 0x136D98u: goto label_136d98;
            case 0x136D9Cu: goto label_136d9c;
            case 0x136DA0u: goto label_136da0;
            case 0x136DA4u: goto label_136da4;
            case 0x136DA8u: goto label_136da8;
            case 0x136DACu: goto label_136dac;
            case 0x136DB0u: goto label_136db0;
            case 0x136DB4u: goto label_136db4;
            case 0x136DB8u: goto label_136db8;
            case 0x136DBCu: goto label_136dbc;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC4u: goto label_136dc4;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DCCu: goto label_136dcc;
            case 0x136DD0u: goto label_136dd0;
            case 0x136DD4u: goto label_136dd4;
            case 0x136DD8u: goto label_136dd8;
            case 0x136DDCu: goto label_136ddc;
            case 0x136DE0u: goto label_136de0;
            case 0x136DE4u: goto label_136de4;
            case 0x136DE8u: goto label_136de8;
            case 0x136DECu: goto label_136dec;
            case 0x136DF0u: goto label_136df0;
            case 0x136DF4u: goto label_136df4;
            case 0x136DF8u: goto label_136df8;
            case 0x136DFCu: goto label_136dfc;
            case 0x136E00u: goto label_136e00;
            case 0x136E04u: goto label_136e04;
            case 0x136E08u: goto label_136e08;
            case 0x136E0Cu: goto label_136e0c;
            case 0x136E10u: goto label_136e10;
            case 0x136E14u: goto label_136e14;
            case 0x136E18u: goto label_136e18;
            case 0x136E1Cu: goto label_136e1c;
            case 0x136E20u: goto label_136e20;
            case 0x136E24u: goto label_136e24;
            case 0x136E28u: goto label_136e28;
            case 0x136E2Cu: goto label_136e2c;
            case 0x136E30u: goto label_136e30;
            case 0x136E34u: goto label_136e34;
            case 0x136E38u: goto label_136e38;
            case 0x136E3Cu: goto label_136e3c;
            case 0x136E40u: goto label_136e40;
            case 0x136E44u: goto label_136e44;
            case 0x136E48u: goto label_136e48;
            case 0x136E4Cu: goto label_136e4c;
            case 0x136E50u: goto label_136e50;
            case 0x136E54u: goto label_136e54;
            case 0x136E58u: goto label_136e58;
            case 0x136E5Cu: goto label_136e5c;
            case 0x136E60u: goto label_136e60;
            case 0x136E64u: goto label_136e64;
            case 0x136E68u: goto label_136e68;
            case 0x136E6Cu: goto label_136e6c;
            case 0x136E70u: goto label_136e70;
            case 0x136E74u: goto label_136e74;
            case 0x136E78u: goto label_136e78;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E80u: goto label_136e80;
            case 0x136E84u: goto label_136e84;
            case 0x136E88u: goto label_136e88;
            case 0x136E8Cu: goto label_136e8c;
            case 0x136E90u: goto label_136e90;
            case 0x136E94u: goto label_136e94;
            case 0x136E98u: goto label_136e98;
            case 0x136E9Cu: goto label_136e9c;
            case 0x136EA0u: goto label_136ea0;
            case 0x136EA4u: goto label_136ea4;
            case 0x136EA8u: goto label_136ea8;
            case 0x136EACu: goto label_136eac;
            case 0x136EB0u: goto label_136eb0;
            case 0x136EB4u: goto label_136eb4;
            case 0x136EB8u: goto label_136eb8;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EC0u: goto label_136ec0;
            case 0x136EC4u: goto label_136ec4;
            case 0x136EC8u: goto label_136ec8;
            case 0x136ECCu: goto label_136ecc;
            case 0x136ED0u: goto label_136ed0;
            case 0x136ED4u: goto label_136ed4;
            case 0x136ED8u: goto label_136ed8;
            case 0x136EDCu: goto label_136edc;
            case 0x136EE0u: goto label_136ee0;
            case 0x136EE4u: goto label_136ee4;
            case 0x136EE8u: goto label_136ee8;
            case 0x136EECu: goto label_136eec;
            case 0x136EF0u: goto label_136ef0;
            case 0x136EF4u: goto label_136ef4;
            case 0x136EF8u: goto label_136ef8;
            case 0x136EFCu: goto label_136efc;
            case 0x136F00u: goto label_136f00;
            case 0x136F04u: goto label_136f04;
            case 0x136F08u: goto label_136f08;
            case 0x136F0Cu: goto label_136f0c;
            case 0x136F10u: goto label_136f10;
            case 0x136F14u: goto label_136f14;
            case 0x136F18u: goto label_136f18;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F20u: goto label_136f20;
            case 0x136F24u: goto label_136f24;
            case 0x136F28u: goto label_136f28;
            case 0x136F2Cu: goto label_136f2c;
            case 0x136F30u: goto label_136f30;
            case 0x136F34u: goto label_136f34;
            case 0x136F38u: goto label_136f38;
            case 0x136F3Cu: goto label_136f3c;
            case 0x136F40u: goto label_136f40;
            case 0x136F44u: goto label_136f44;
            case 0x136F48u: goto label_136f48;
            case 0x136F4Cu: goto label_136f4c;
            case 0x136F50u: goto label_136f50;
            case 0x136F54u: goto label_136f54;
            case 0x136F58u: goto label_136f58;
            case 0x136F5Cu: goto label_136f5c;
            case 0x136F60u: goto label_136f60;
            case 0x136F64u: goto label_136f64;
            case 0x136F68u: goto label_136f68;
            case 0x136F6Cu: goto label_136f6c;
            case 0x136F70u: goto label_136f70;
            case 0x136F74u: goto label_136f74;
            case 0x136F78u: goto label_136f78;
            case 0x136F7Cu: goto label_136f7c;
            case 0x136F80u: goto label_136f80;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            case 0x136F8Cu: goto label_136f8c;
            case 0x136F90u: goto label_136f90;
            case 0x136F94u: goto label_136f94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136B0Cu;
label_136b0c:
    // 0x136b0c: 0x0
    ctx->pc = 0x136b0cu;
    // NOP
label_136b10:
    // 0x136b10: 0x27bdfff0
    ctx->pc = 0x136b10u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967280));
label_136b14:
    // 0x136b14: 0xffb00000
    ctx->pc = 0x136b14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_136b18:
    // 0x136b18: 0x802d
    ctx->pc = 0x136b18u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_136b1c:
    // 0x136b1c: 0x14800006
label_136b20:
    if (ctx->pc == 0x136B20u) {
        ctx->pc = 0x136B20u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        ctx->pc = 0x136B24u;
        goto label_136b24;
    }
    ctx->pc = 0x136B1Cu;
    {
        const bool branch_taken_0x136b1c = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x136B20u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 31));
        if (branch_taken_0x136b1c) {
            ctx->pc = 0x136B38u;
            goto label_136b38;
        }
    }
    ctx->pc = 0x136B24u;
label_136b24:
    // 0x136b24: 0x3c040024
    ctx->pc = 0x136b24u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_136b28:
    // 0x136b28: 0xc04d480
label_136b2c:
    if (ctx->pc == 0x136B2Cu) {
        ctx->pc = 0x136B2Cu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951168));
        ctx->pc = 0x136B30u;
        goto label_136b30;
    }
    ctx->pc = 0x136B28u;
    SET_GPR_U32(ctx, 31, 0x136B30u);
    ctx->pc = 0x136B2Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951168));
    ctx->pc = 0x135200u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136B30u; }
    }
    if (ctx->pc != 0x136B30u) { return; }
    ctx->pc = 0x136B30u;
label_136b30:
    // 0x136b30: 0x1000000c
label_136b34:
    if (ctx->pc == 0x136B34u) {
        ctx->pc = 0x136B34u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x136B38u;
        goto label_136b38;
    }
    ctx->pc = 0x136B30u;
    {
        const bool branch_taken_0x136b30 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136B34u;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x136b30) {
            ctx->pc = 0x136B64u;
            goto label_136b64;
        }
    }
    ctx->pc = 0x136B38u;
label_136b38:
    // 0x136b38: 0x8c820000
    ctx->pc = 0x136b38u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 4), 0)));
label_136b3c:
    // 0x136b3c: 0x8c420064
    ctx->pc = 0x136b3cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 2), 100)));
label_136b40:
    // 0x136b40: 0x50400005
label_136b44:
    if (ctx->pc == 0x136B44u) {
        ctx->pc = 0x136B44u;
        SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
        ctx->pc = 0x136B48u;
        goto label_136b48;
    }
    ctx->pc = 0x136B40u;
    {
        const bool branch_taken_0x136b40 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x136b40) {
            ctx->pc = 0x136B44u;
            SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
            ctx->pc = 0x136B58u;
            goto label_136b58;
        }
    }
    ctx->pc = 0x136B48u;
label_136b48:
    // 0x136b48: 0x40f809
label_136b4c:
    if (ctx->pc == 0x136B4Cu) {
        ctx->pc = 0x136B4Cu;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->pc = 0x136B50u;
        goto label_136b50;
    }
    ctx->pc = 0x136B48u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136B50u);
        ctx->pc = 0x136B4Cu;
        SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 4), 4)));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A80u: goto label_136a80;
            case 0x136A84u: goto label_136a84;
            case 0x136A88u: goto label_136a88;
            case 0x136A8Cu: goto label_136a8c;
            case 0x136A90u: goto label_136a90;
            case 0x136A94u: goto label_136a94;
            case 0x136A98u: goto label_136a98;
            case 0x136A9Cu: goto label_136a9c;
            case 0x136AA0u: goto label_136aa0;
            case 0x136AA4u: goto label_136aa4;
            case 0x136AA8u: goto label_136aa8;
            case 0x136AACu: goto label_136aac;
            case 0x136AB0u: goto label_136ab0;
            case 0x136AB4u: goto label_136ab4;
            case 0x136AB8u: goto label_136ab8;
            case 0x136ABCu: goto label_136abc;
            case 0x136AC0u: goto label_136ac0;
            case 0x136AC4u: goto label_136ac4;
            case 0x136AC8u: goto label_136ac8;
            case 0x136ACCu: goto label_136acc;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AD4u: goto label_136ad4;
            case 0x136AD8u: goto label_136ad8;
            case 0x136ADCu: goto label_136adc;
            case 0x136AE0u: goto label_136ae0;
            case 0x136AE4u: goto label_136ae4;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AECu: goto label_136aec;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF4u: goto label_136af4;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B00u: goto label_136b00;
            case 0x136B04u: goto label_136b04;
            case 0x136B08u: goto label_136b08;
            case 0x136B0Cu: goto label_136b0c;
            case 0x136B10u: goto label_136b10;
            case 0x136B14u: goto label_136b14;
            case 0x136B18u: goto label_136b18;
            case 0x136B1Cu: goto label_136b1c;
            case 0x136B20u: goto label_136b20;
            case 0x136B24u: goto label_136b24;
            case 0x136B28u: goto label_136b28;
            case 0x136B2Cu: goto label_136b2c;
            case 0x136B30u: goto label_136b30;
            case 0x136B34u: goto label_136b34;
            case 0x136B38u: goto label_136b38;
            case 0x136B3Cu: goto label_136b3c;
            case 0x136B40u: goto label_136b40;
            case 0x136B44u: goto label_136b44;
            case 0x136B48u: goto label_136b48;
            case 0x136B4Cu: goto label_136b4c;
            case 0x136B50u: goto label_136b50;
            case 0x136B54u: goto label_136b54;
            case 0x136B58u: goto label_136b58;
            case 0x136B5Cu: goto label_136b5c;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136B68u: goto label_136b68;
            case 0x136B6Cu: goto label_136b6c;
            case 0x136B70u: goto label_136b70;
            case 0x136B74u: goto label_136b74;
            case 0x136B78u: goto label_136b78;
            case 0x136B7Cu: goto label_136b7c;
            case 0x136B80u: goto label_136b80;
            case 0x136B84u: goto label_136b84;
            case 0x136B88u: goto label_136b88;
            case 0x136B8Cu: goto label_136b8c;
            case 0x136B90u: goto label_136b90;
            case 0x136B94u: goto label_136b94;
            case 0x136B98u: goto label_136b98;
            case 0x136B9Cu: goto label_136b9c;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BA4u: goto label_136ba4;
            case 0x136BA8u: goto label_136ba8;
            case 0x136BACu: goto label_136bac;
            case 0x136BB0u: goto label_136bb0;
            case 0x136BB4u: goto label_136bb4;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BBCu: goto label_136bbc;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BC4u: goto label_136bc4;
            case 0x136BC8u: goto label_136bc8;
            case 0x136BCCu: goto label_136bcc;
            case 0x136BD0u: goto label_136bd0;
            case 0x136BD4u: goto label_136bd4;
            case 0x136BD8u: goto label_136bd8;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE0u: goto label_136be0;
            case 0x136BE4u: goto label_136be4;
            case 0x136BE8u: goto label_136be8;
            case 0x136BECu: goto label_136bec;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF4u: goto label_136bf4;
            case 0x136BF8u: goto label_136bf8;
            case 0x136BFCu: goto label_136bfc;
            case 0x136C00u: goto label_136c00;
            case 0x136C04u: goto label_136c04;
            case 0x136C08u: goto label_136c08;
            case 0x136C0Cu: goto label_136c0c;
            case 0x136C10u: goto label_136c10;
            case 0x136C14u: goto label_136c14;
            case 0x136C18u: goto label_136c18;
            case 0x136C1Cu: goto label_136c1c;
            case 0x136C20u: goto label_136c20;
            case 0x136C24u: goto label_136c24;
            case 0x136C28u: goto label_136c28;
            case 0x136C2Cu: goto label_136c2c;
            case 0x136C30u: goto label_136c30;
            case 0x136C34u: goto label_136c34;
            case 0x136C38u: goto label_136c38;
            case 0x136C3Cu: goto label_136c3c;
            case 0x136C40u: goto label_136c40;
            case 0x136C44u: goto label_136c44;
            case 0x136C48u: goto label_136c48;
            case 0x136C4Cu: goto label_136c4c;
            case 0x136C50u: goto label_136c50;
            case 0x136C54u: goto label_136c54;
            case 0x136C58u: goto label_136c58;
            case 0x136C5Cu: goto label_136c5c;
            case 0x136C60u: goto label_136c60;
            case 0x136C64u: goto label_136c64;
            case 0x136C68u: goto label_136c68;
            case 0x136C6Cu: goto label_136c6c;
            case 0x136C70u: goto label_136c70;
            case 0x136C74u: goto label_136c74;
            case 0x136C78u: goto label_136c78;
            case 0x136C7Cu: goto label_136c7c;
            case 0x136C80u: goto label_136c80;
            case 0x136C84u: goto label_136c84;
            case 0x136C88u: goto label_136c88;
            case 0x136C8Cu: goto label_136c8c;
            case 0x136C90u: goto label_136c90;
            case 0x136C94u: goto label_136c94;
            case 0x136C98u: goto label_136c98;
            case 0x136C9Cu: goto label_136c9c;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CA4u: goto label_136ca4;
            case 0x136CA8u: goto label_136ca8;
            case 0x136CACu: goto label_136cac;
            case 0x136CB0u: goto label_136cb0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CB8u: goto label_136cb8;
            case 0x136CBCu: goto label_136cbc;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC4u: goto label_136cc4;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CCCu: goto label_136ccc;
            case 0x136CD0u: goto label_136cd0;
            case 0x136CD4u: goto label_136cd4;
            case 0x136CD8u: goto label_136cd8;
            case 0x136CDCu: goto label_136cdc;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE4u: goto label_136ce4;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CECu: goto label_136cec;
            case 0x136CF0u: goto label_136cf0;
            case 0x136CF4u: goto label_136cf4;
            case 0x136CF8u: goto label_136cf8;
            case 0x136CFCu: goto label_136cfc;
            case 0x136D00u: goto label_136d00;
            case 0x136D04u: goto label_136d04;
            case 0x136D08u: goto label_136d08;
            case 0x136D0Cu: goto label_136d0c;
            case 0x136D10u: goto label_136d10;
            case 0x136D14u: goto label_136d14;
            case 0x136D18u: goto label_136d18;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D20u: goto label_136d20;
            case 0x136D24u: goto label_136d24;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D34u: goto label_136d34;
            case 0x136D38u: goto label_136d38;
            case 0x136D3Cu: goto label_136d3c;
            case 0x136D40u: goto label_136d40;
            case 0x136D44u: goto label_136d44;
            case 0x136D48u: goto label_136d48;
            case 0x136D4Cu: goto label_136d4c;
            case 0x136D50u: goto label_136d50;
            case 0x136D54u: goto label_136d54;
            case 0x136D58u: goto label_136d58;
            case 0x136D5Cu: goto label_136d5c;
            case 0x136D60u: goto label_136d60;
            case 0x136D64u: goto label_136d64;
            case 0x136D68u: goto label_136d68;
            case 0x136D6Cu: goto label_136d6c;
            case 0x136D70u: goto label_136d70;
            case 0x136D74u: goto label_136d74;
            case 0x136D78u: goto label_136d78;
            case 0x136D7Cu: goto label_136d7c;
            case 0x136D80u: goto label_136d80;
            case 0x136D84u: goto label_136d84;
            case 0x136D88u: goto label_136d88;
            case 0x136D8Cu: goto label_136d8c;
            case 0x136D90u: goto label_136d90;
            case 0x136D94u: goto label_136d94;
            case 0x136D98u: goto label_136d98;
            case 0x136D9Cu: goto label_136d9c;
            case 0x136DA0u: goto label_136da0;
            case 0x136DA4u: goto label_136da4;
            case 0x136DA8u: goto label_136da8;
            case 0x136DACu: goto label_136dac;
            case 0x136DB0u: goto label_136db0;
            case 0x136DB4u: goto label_136db4;
            case 0x136DB8u: goto label_136db8;
            case 0x136DBCu: goto label_136dbc;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC4u: goto label_136dc4;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DCCu: goto label_136dcc;
            case 0x136DD0u: goto label_136dd0;
            case 0x136DD4u: goto label_136dd4;
            case 0x136DD8u: goto label_136dd8;
            case 0x136DDCu: goto label_136ddc;
            case 0x136DE0u: goto label_136de0;
            case 0x136DE4u: goto label_136de4;
            case 0x136DE8u: goto label_136de8;
            case 0x136DECu: goto label_136dec;
            case 0x136DF0u: goto label_136df0;
            case 0x136DF4u: goto label_136df4;
            case 0x136DF8u: goto label_136df8;
            case 0x136DFCu: goto label_136dfc;
            case 0x136E00u: goto label_136e00;
            case 0x136E04u: goto label_136e04;
            case 0x136E08u: goto label_136e08;
            case 0x136E0Cu: goto label_136e0c;
            case 0x136E10u: goto label_136e10;
            case 0x136E14u: goto label_136e14;
            case 0x136E18u: goto label_136e18;
            case 0x136E1Cu: goto label_136e1c;
            case 0x136E20u: goto label_136e20;
            case 0x136E24u: goto label_136e24;
            case 0x136E28u: goto label_136e28;
            case 0x136E2Cu: goto label_136e2c;
            case 0x136E30u: goto label_136e30;
            case 0x136E34u: goto label_136e34;
            case 0x136E38u: goto label_136e38;
            case 0x136E3Cu: goto label_136e3c;
            case 0x136E40u: goto label_136e40;
            case 0x136E44u: goto label_136e44;
            case 0x136E48u: goto label_136e48;
            case 0x136E4Cu: goto label_136e4c;
            case 0x136E50u: goto label_136e50;
            case 0x136E54u: goto label_136e54;
            case 0x136E58u: goto label_136e58;
            case 0x136E5Cu: goto label_136e5c;
            case 0x136E60u: goto label_136e60;
            case 0x136E64u: goto label_136e64;
            case 0x136E68u: goto label_136e68;
            case 0x136E6Cu: goto label_136e6c;
            case 0x136E70u: goto label_136e70;
            case 0x136E74u: goto label_136e74;
            case 0x136E78u: goto label_136e78;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E80u: goto label_136e80;
            case 0x136E84u: goto label_136e84;
            case 0x136E88u: goto label_136e88;
            case 0x136E8Cu: goto label_136e8c;
            case 0x136E90u: goto label_136e90;
            case 0x136E94u: goto label_136e94;
            case 0x136E98u: goto label_136e98;
            case 0x136E9Cu: goto label_136e9c;
            case 0x136EA0u: goto label_136ea0;
            case 0x136EA4u: goto label_136ea4;
            case 0x136EA8u: goto label_136ea8;
            case 0x136EACu: goto label_136eac;
            case 0x136EB0u: goto label_136eb0;
            case 0x136EB4u: goto label_136eb4;
            case 0x136EB8u: goto label_136eb8;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EC0u: goto label_136ec0;
            case 0x136EC4u: goto label_136ec4;
            case 0x136EC8u: goto label_136ec8;
            case 0x136ECCu: goto label_136ecc;
            case 0x136ED0u: goto label_136ed0;
            case 0x136ED4u: goto label_136ed4;
            case 0x136ED8u: goto label_136ed8;
            case 0x136EDCu: goto label_136edc;
            case 0x136EE0u: goto label_136ee0;
            case 0x136EE4u: goto label_136ee4;
            case 0x136EE8u: goto label_136ee8;
            case 0x136EECu: goto label_136eec;
            case 0x136EF0u: goto label_136ef0;
            case 0x136EF4u: goto label_136ef4;
            case 0x136EF8u: goto label_136ef8;
            case 0x136EFCu: goto label_136efc;
            case 0x136F00u: goto label_136f00;
            case 0x136F04u: goto label_136f04;
            case 0x136F08u: goto label_136f08;
            case 0x136F0Cu: goto label_136f0c;
            case 0x136F10u: goto label_136f10;
            case 0x136F14u: goto label_136f14;
            case 0x136F18u: goto label_136f18;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F20u: goto label_136f20;
            case 0x136F24u: goto label_136f24;
            case 0x136F28u: goto label_136f28;
            case 0x136F2Cu: goto label_136f2c;
            case 0x136F30u: goto label_136f30;
            case 0x136F34u: goto label_136f34;
            case 0x136F38u: goto label_136f38;
            case 0x136F3Cu: goto label_136f3c;
            case 0x136F40u: goto label_136f40;
            case 0x136F44u: goto label_136f44;
            case 0x136F48u: goto label_136f48;
            case 0x136F4Cu: goto label_136f4c;
            case 0x136F50u: goto label_136f50;
            case 0x136F54u: goto label_136f54;
            case 0x136F58u: goto label_136f58;
            case 0x136F5Cu: goto label_136f5c;
            case 0x136F60u: goto label_136f60;
            case 0x136F64u: goto label_136f64;
            case 0x136F68u: goto label_136f68;
            case 0x136F6Cu: goto label_136f6c;
            case 0x136F70u: goto label_136f70;
            case 0x136F74u: goto label_136f74;
            case 0x136F78u: goto label_136f78;
            case 0x136F7Cu: goto label_136f7c;
            case 0x136F80u: goto label_136f80;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            case 0x136F8Cu: goto label_136f8c;
            case 0x136F90u: goto label_136f90;
            case 0x136F94u: goto label_136f94;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136B50u; }
            if (ctx->pc != 0x136B50u) { return; }
        }
    }
    ctx->pc = 0x136B50u;
label_136b50:
    // 0x136b50: 0x10000003
label_136b54:
    if (ctx->pc == 0x136B54u) {
        ctx->pc = 0x136B54u;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x136B58u;
        goto label_136b58;
    }
    ctx->pc = 0x136B50u;
    {
        const bool branch_taken_0x136b50 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136B54u;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x136b50) {
            ctx->pc = 0x136B60u;
            goto label_136b60;
        }
    }
    ctx->pc = 0x136B58u;
label_136b58:
    // 0x136b58: 0xc04d480
label_136b5c:
    if (ctx->pc == 0x136B5Cu) {
        ctx->pc = 0x136B5Cu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951200));
        ctx->pc = 0x136B60u;
        goto label_136b60;
    }
    ctx->pc = 0x136B58u;
    SET_GPR_U32(ctx, 31, 0x136B60u);
    ctx->pc = 0x136B5Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951200));
    ctx->pc = 0x135200u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136B60u; }
    }
    if (ctx->pc != 0x136B60u) { return; }
    ctx->pc = 0x136B60u;
label_136b60:
    // 0x136b60: 0x200102d
    ctx->pc = 0x136b60u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
label_136b64:
    // 0x136b64: 0xdfb00000
    ctx->pc = 0x136b64u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_136b68:
    // 0x136b68: 0xdfbf0008
    ctx->pc = 0x136b68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_136b6c:
    // 0x136b6c: 0x3e00008
label_136b70:
    if (ctx->pc == 0x136B70u) {
        ctx->pc = 0x136B70u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = 0x136B74u;
        goto label_136b74;
    }
    ctx->pc = 0x136B6Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136B70u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 16));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A80u: goto label_136a80;
            case 0x136A84u: goto label_136a84;
            case 0x136A88u: goto label_136a88;
            case 0x136A8Cu: goto label_136a8c;
            case 0x136A90u: goto label_136a90;
            case 0x136A94u: goto label_136a94;
            case 0x136A98u: goto label_136a98;
            case 0x136A9Cu: goto label_136a9c;
            case 0x136AA0u: goto label_136aa0;
            case 0x136AA4u: goto label_136aa4;
            case 0x136AA8u: goto label_136aa8;
            case 0x136AACu: goto label_136aac;
            case 0x136AB0u: goto label_136ab0;
            case 0x136AB4u: goto label_136ab4;
            case 0x136AB8u: goto label_136ab8;
            case 0x136ABCu: goto label_136abc;
            case 0x136AC0u: goto label_136ac0;
            case 0x136AC4u: goto label_136ac4;
            case 0x136AC8u: goto label_136ac8;
            case 0x136ACCu: goto label_136acc;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AD4u: goto label_136ad4;
            case 0x136AD8u: goto label_136ad8;
            case 0x136ADCu: goto label_136adc;
            case 0x136AE0u: goto label_136ae0;
            case 0x136AE4u: goto label_136ae4;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AECu: goto label_136aec;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF4u: goto label_136af4;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B00u: goto label_136b00;
            case 0x136B04u: goto label_136b04;
            case 0x136B08u: goto label_136b08;
            case 0x136B0Cu: goto label_136b0c;
            case 0x136B10u: goto label_136b10;
            case 0x136B14u: goto label_136b14;
            case 0x136B18u: goto label_136b18;
            case 0x136B1Cu: goto label_136b1c;
            case 0x136B20u: goto label_136b20;
            case 0x136B24u: goto label_136b24;
            case 0x136B28u: goto label_136b28;
            case 0x136B2Cu: goto label_136b2c;
            case 0x136B30u: goto label_136b30;
            case 0x136B34u: goto label_136b34;
            case 0x136B38u: goto label_136b38;
            case 0x136B3Cu: goto label_136b3c;
            case 0x136B40u: goto label_136b40;
            case 0x136B44u: goto label_136b44;
            case 0x136B48u: goto label_136b48;
            case 0x136B4Cu: goto label_136b4c;
            case 0x136B50u: goto label_136b50;
            case 0x136B54u: goto label_136b54;
            case 0x136B58u: goto label_136b58;
            case 0x136B5Cu: goto label_136b5c;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136B68u: goto label_136b68;
            case 0x136B6Cu: goto label_136b6c;
            case 0x136B70u: goto label_136b70;
            case 0x136B74u: goto label_136b74;
            case 0x136B78u: goto label_136b78;
            case 0x136B7Cu: goto label_136b7c;
            case 0x136B80u: goto label_136b80;
            case 0x136B84u: goto label_136b84;
            case 0x136B88u: goto label_136b88;
            case 0x136B8Cu: goto label_136b8c;
            case 0x136B90u: goto label_136b90;
            case 0x136B94u: goto label_136b94;
            case 0x136B98u: goto label_136b98;
            case 0x136B9Cu: goto label_136b9c;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BA4u: goto label_136ba4;
            case 0x136BA8u: goto label_136ba8;
            case 0x136BACu: goto label_136bac;
            case 0x136BB0u: goto label_136bb0;
            case 0x136BB4u: goto label_136bb4;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BBCu: goto label_136bbc;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BC4u: goto label_136bc4;
            case 0x136BC8u: goto label_136bc8;
            case 0x136BCCu: goto label_136bcc;
            case 0x136BD0u: goto label_136bd0;
            case 0x136BD4u: goto label_136bd4;
            case 0x136BD8u: goto label_136bd8;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE0u: goto label_136be0;
            case 0x136BE4u: goto label_136be4;
            case 0x136BE8u: goto label_136be8;
            case 0x136BECu: goto label_136bec;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF4u: goto label_136bf4;
            case 0x136BF8u: goto label_136bf8;
            case 0x136BFCu: goto label_136bfc;
            case 0x136C00u: goto label_136c00;
            case 0x136C04u: goto label_136c04;
            case 0x136C08u: goto label_136c08;
            case 0x136C0Cu: goto label_136c0c;
            case 0x136C10u: goto label_136c10;
            case 0x136C14u: goto label_136c14;
            case 0x136C18u: goto label_136c18;
            case 0x136C1Cu: goto label_136c1c;
            case 0x136C20u: goto label_136c20;
            case 0x136C24u: goto label_136c24;
            case 0x136C28u: goto label_136c28;
            case 0x136C2Cu: goto label_136c2c;
            case 0x136C30u: goto label_136c30;
            case 0x136C34u: goto label_136c34;
            case 0x136C38u: goto label_136c38;
            case 0x136C3Cu: goto label_136c3c;
            case 0x136C40u: goto label_136c40;
            case 0x136C44u: goto label_136c44;
            case 0x136C48u: goto label_136c48;
            case 0x136C4Cu: goto label_136c4c;
            case 0x136C50u: goto label_136c50;
            case 0x136C54u: goto label_136c54;
            case 0x136C58u: goto label_136c58;
            case 0x136C5Cu: goto label_136c5c;
            case 0x136C60u: goto label_136c60;
            case 0x136C64u: goto label_136c64;
            case 0x136C68u: goto label_136c68;
            case 0x136C6Cu: goto label_136c6c;
            case 0x136C70u: goto label_136c70;
            case 0x136C74u: goto label_136c74;
            case 0x136C78u: goto label_136c78;
            case 0x136C7Cu: goto label_136c7c;
            case 0x136C80u: goto label_136c80;
            case 0x136C84u: goto label_136c84;
            case 0x136C88u: goto label_136c88;
            case 0x136C8Cu: goto label_136c8c;
            case 0x136C90u: goto label_136c90;
            case 0x136C94u: goto label_136c94;
            case 0x136C98u: goto label_136c98;
            case 0x136C9Cu: goto label_136c9c;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CA4u: goto label_136ca4;
            case 0x136CA8u: goto label_136ca8;
            case 0x136CACu: goto label_136cac;
            case 0x136CB0u: goto label_136cb0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CB8u: goto label_136cb8;
            case 0x136CBCu: goto label_136cbc;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC4u: goto label_136cc4;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CCCu: goto label_136ccc;
            case 0x136CD0u: goto label_136cd0;
            case 0x136CD4u: goto label_136cd4;
            case 0x136CD8u: goto label_136cd8;
            case 0x136CDCu: goto label_136cdc;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE4u: goto label_136ce4;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CECu: goto label_136cec;
            case 0x136CF0u: goto label_136cf0;
            case 0x136CF4u: goto label_136cf4;
            case 0x136CF8u: goto label_136cf8;
            case 0x136CFCu: goto label_136cfc;
            case 0x136D00u: goto label_136d00;
            case 0x136D04u: goto label_136d04;
            case 0x136D08u: goto label_136d08;
            case 0x136D0Cu: goto label_136d0c;
            case 0x136D10u: goto label_136d10;
            case 0x136D14u: goto label_136d14;
            case 0x136D18u: goto label_136d18;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D20u: goto label_136d20;
            case 0x136D24u: goto label_136d24;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D34u: goto label_136d34;
            case 0x136D38u: goto label_136d38;
            case 0x136D3Cu: goto label_136d3c;
            case 0x136D40u: goto label_136d40;
            case 0x136D44u: goto label_136d44;
            case 0x136D48u: goto label_136d48;
            case 0x136D4Cu: goto label_136d4c;
            case 0x136D50u: goto label_136d50;
            case 0x136D54u: goto label_136d54;
            case 0x136D58u: goto label_136d58;
            case 0x136D5Cu: goto label_136d5c;
            case 0x136D60u: goto label_136d60;
            case 0x136D64u: goto label_136d64;
            case 0x136D68u: goto label_136d68;
            case 0x136D6Cu: goto label_136d6c;
            case 0x136D70u: goto label_136d70;
            case 0x136D74u: goto label_136d74;
            case 0x136D78u: goto label_136d78;
            case 0x136D7Cu: goto label_136d7c;
            case 0x136D80u: goto label_136d80;
            case 0x136D84u: goto label_136d84;
            case 0x136D88u: goto label_136d88;
            case 0x136D8Cu: goto label_136d8c;
            case 0x136D90u: goto label_136d90;
            case 0x136D94u: goto label_136d94;
            case 0x136D98u: goto label_136d98;
            case 0x136D9Cu: goto label_136d9c;
            case 0x136DA0u: goto label_136da0;
            case 0x136DA4u: goto label_136da4;
            case 0x136DA8u: goto label_136da8;
            case 0x136DACu: goto label_136dac;
            case 0x136DB0u: goto label_136db0;
            case 0x136DB4u: goto label_136db4;
            case 0x136DB8u: goto label_136db8;
            case 0x136DBCu: goto label_136dbc;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC4u: goto label_136dc4;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DCCu: goto label_136dcc;
            case 0x136DD0u: goto label_136dd0;
            case 0x136DD4u: goto label_136dd4;
            case 0x136DD8u: goto label_136dd8;
            case 0x136DDCu: goto label_136ddc;
            case 0x136DE0u: goto label_136de0;
            case 0x136DE4u: goto label_136de4;
            case 0x136DE8u: goto label_136de8;
            case 0x136DECu: goto label_136dec;
            case 0x136DF0u: goto label_136df0;
            case 0x136DF4u: goto label_136df4;
            case 0x136DF8u: goto label_136df8;
            case 0x136DFCu: goto label_136dfc;
            case 0x136E00u: goto label_136e00;
            case 0x136E04u: goto label_136e04;
            case 0x136E08u: goto label_136e08;
            case 0x136E0Cu: goto label_136e0c;
            case 0x136E10u: goto label_136e10;
            case 0x136E14u: goto label_136e14;
            case 0x136E18u: goto label_136e18;
            case 0x136E1Cu: goto label_136e1c;
            case 0x136E20u: goto label_136e20;
            case 0x136E24u: goto label_136e24;
            case 0x136E28u: goto label_136e28;
            case 0x136E2Cu: goto label_136e2c;
            case 0x136E30u: goto label_136e30;
            case 0x136E34u: goto label_136e34;
            case 0x136E38u: goto label_136e38;
            case 0x136E3Cu: goto label_136e3c;
            case 0x136E40u: goto label_136e40;
            case 0x136E44u: goto label_136e44;
            case 0x136E48u: goto label_136e48;
            case 0x136E4Cu: goto label_136e4c;
            case 0x136E50u: goto label_136e50;
            case 0x136E54u: goto label_136e54;
            case 0x136E58u: goto label_136e58;
            case 0x136E5Cu: goto label_136e5c;
            case 0x136E60u: goto label_136e60;
            case 0x136E64u: goto label_136e64;
            case 0x136E68u: goto label_136e68;
            case 0x136E6Cu: goto label_136e6c;
            case 0x136E70u: goto label_136e70;
            case 0x136E74u: goto label_136e74;
            case 0x136E78u: goto label_136e78;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E80u: goto label_136e80;
            case 0x136E84u: goto label_136e84;
            case 0x136E88u: goto label_136e88;
            case 0x136E8Cu: goto label_136e8c;
            case 0x136E90u: goto label_136e90;
            case 0x136E94u: goto label_136e94;
            case 0x136E98u: goto label_136e98;
            case 0x136E9Cu: goto label_136e9c;
            case 0x136EA0u: goto label_136ea0;
            case 0x136EA4u: goto label_136ea4;
            case 0x136EA8u: goto label_136ea8;
            case 0x136EACu: goto label_136eac;
            case 0x136EB0u: goto label_136eb0;
            case 0x136EB4u: goto label_136eb4;
            case 0x136EB8u: goto label_136eb8;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EC0u: goto label_136ec0;
            case 0x136EC4u: goto label_136ec4;
            case 0x136EC8u: goto label_136ec8;
            case 0x136ECCu: goto label_136ecc;
            case 0x136ED0u: goto label_136ed0;
            case 0x136ED4u: goto label_136ed4;
            case 0x136ED8u: goto label_136ed8;
            case 0x136EDCu: goto label_136edc;
            case 0x136EE0u: goto label_136ee0;
            case 0x136EE4u: goto label_136ee4;
            case 0x136EE8u: goto label_136ee8;
            case 0x136EECu: goto label_136eec;
            case 0x136EF0u: goto label_136ef0;
            case 0x136EF4u: goto label_136ef4;
            case 0x136EF8u: goto label_136ef8;
            case 0x136EFCu: goto label_136efc;
            case 0x136F00u: goto label_136f00;
            case 0x136F04u: goto label_136f04;
            case 0x136F08u: goto label_136f08;
            case 0x136F0Cu: goto label_136f0c;
            case 0x136F10u: goto label_136f10;
            case 0x136F14u: goto label_136f14;
            case 0x136F18u: goto label_136f18;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F20u: goto label_136f20;
            case 0x136F24u: goto label_136f24;
            case 0x136F28u: goto label_136f28;
            case 0x136F2Cu: goto label_136f2c;
            case 0x136F30u: goto label_136f30;
            case 0x136F34u: goto label_136f34;
            case 0x136F38u: goto label_136f38;
            case 0x136F3Cu: goto label_136f3c;
            case 0x136F40u: goto label_136f40;
            case 0x136F44u: goto label_136f44;
            case 0x136F48u: goto label_136f48;
            case 0x136F4Cu: goto label_136f4c;
            case 0x136F50u: goto label_136f50;
            case 0x136F54u: goto label_136f54;
            case 0x136F58u: goto label_136f58;
            case 0x136F5Cu: goto label_136f5c;
            case 0x136F60u: goto label_136f60;
            case 0x136F64u: goto label_136f64;
            case 0x136F68u: goto label_136f68;
            case 0x136F6Cu: goto label_136f6c;
            case 0x136F70u: goto label_136f70;
            case 0x136F74u: goto label_136f74;
            case 0x136F78u: goto label_136f78;
            case 0x136F7Cu: goto label_136f7c;
            case 0x136F80u: goto label_136f80;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            case 0x136F8Cu: goto label_136f8c;
            case 0x136F90u: goto label_136f90;
            case 0x136F94u: goto label_136f94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136B74u;
label_136b74:
    // 0x136b74: 0x0
    ctx->pc = 0x136b74u;
    // NOP
label_136b78:
    // 0x136b78: 0x27bdffc0
    ctx->pc = 0x136b78u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
label_136b7c:
    // 0x136b7c: 0xffb00020
    ctx->pc = 0x136b7cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
label_136b80:
    // 0x136b80: 0xa0802d
    ctx->pc = 0x136b80u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_136b84:
    // 0x136b84: 0xffb10028
    ctx->pc = 0x136b84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
label_136b88:
    // 0x136b88: 0x14800005
label_136b8c:
    if (ctx->pc == 0x136B8Cu) {
        ctx->pc = 0x136B8Cu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        ctx->pc = 0x136B90u;
        goto label_136b90;
    }
    ctx->pc = 0x136B88u;
    {
        const bool branch_taken_0x136b88 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x136B8Cu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        if (branch_taken_0x136b88) {
            ctx->pc = 0x136BA0u;
            goto label_136ba0;
        }
    }
    ctx->pc = 0x136B90u;
label_136b90:
    // 0x136b90: 0x3c040024
    ctx->pc = 0x136b90u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_136b94:
    // 0x136b94: 0x10000011
label_136b98:
    if (ctx->pc == 0x136B98u) {
        ctx->pc = 0x136B98u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951232));
        ctx->pc = 0x136B9Cu;
        goto label_136b9c;
    }
    ctx->pc = 0x136B94u;
    {
        const bool branch_taken_0x136b94 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136B98u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951232));
        if (branch_taken_0x136b94) {
            ctx->pc = 0x136BDCu;
            goto label_136bdc;
        }
    }
    ctx->pc = 0x136B9Cu;
label_136b9c:
    // 0x136b9c: 0x0
    ctx->pc = 0x136b9cu;
    // NOP
label_136ba0:
    // 0x136ba0: 0x16000005
label_136ba4:
    if (ctx->pc == 0x136BA4u) {
        ctx->pc = 0x136BA8u;
        goto label_136ba8;
    }
    ctx->pc = 0x136BA0u;
    {
        const bool branch_taken_0x136ba0 = (GPR_U32(ctx, 16) != GPR_U32(ctx, 0));
        if (branch_taken_0x136ba0) {
            ctx->pc = 0x136BB8u;
            goto label_136bb8;
        }
    }
    ctx->pc = 0x136BA8u;
label_136ba8:
    // 0x136ba8: 0x3c040024
    ctx->pc = 0x136ba8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_136bac:
    // 0x136bac: 0x1000000b
label_136bb0:
    if (ctx->pc == 0x136BB0u) {
        ctx->pc = 0x136BB0u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951272));
        ctx->pc = 0x136BB4u;
        goto label_136bb4;
    }
    ctx->pc = 0x136BACu;
    {
        const bool branch_taken_0x136bac = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136BB0u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951272));
        if (branch_taken_0x136bac) {
            ctx->pc = 0x136BDCu;
            goto label_136bdc;
        }
    }
    ctx->pc = 0x136BB4u;
label_136bb4:
    // 0x136bb4: 0x0
    ctx->pc = 0x136bb4u;
    // NOP
label_136bb8:
    // 0x136bb8: 0xc04d558
label_136bbc:
    if (ctx->pc == 0x136BBCu) {
        ctx->pc = 0x136BC0u;
        goto label_136bc0;
    }
    ctx->pc = 0x136BB8u;
    SET_GPR_U32(ctx, 31, 0x136BC0u);
    ctx->pc = 0x135560u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136BC0u; }
    }
    if (ctx->pc != 0x136BC0u) { return; }
    ctx->pc = 0x136BC0u;
label_136bc0:
    // 0x136bc0: 0x282d
    ctx->pc = 0x136bc0u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_136bc4:
    // 0x136bc4: 0x40882d
    ctx->pc = 0x136bc4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_136bc8:
    // 0x136bc8: 0x3a0202d
    ctx->pc = 0x136bc8u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_136bcc:
    // 0x136bcc: 0x16200008
label_136bd0:
    if (ctx->pc == 0x136BD0u) {
        ctx->pc = 0x136BD0u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 20));
        ctx->pc = 0x136BD4u;
        goto label_136bd4;
    }
    ctx->pc = 0x136BCCu;
    {
        const bool branch_taken_0x136bcc = (GPR_U32(ctx, 17) != GPR_U32(ctx, 0));
        ctx->pc = 0x136BD0u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 20));
        if (branch_taken_0x136bcc) {
            ctx->pc = 0x136BF0u;
            goto label_136bf0;
        }
    }
    ctx->pc = 0x136BD4u;
label_136bd4:
    // 0x136bd4: 0x3c040024
    ctx->pc = 0x136bd4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_136bd8:
    // 0x136bd8: 0x2484c198
    ctx->pc = 0x136bd8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951320));
label_136bdc:
    // 0x136bdc: 0xc04d480
label_136be0:
    if (ctx->pc == 0x136BE0u) {
        ctx->pc = 0x136BE4u;
        goto label_136be4;
    }
    ctx->pc = 0x136BDCu;
    SET_GPR_U32(ctx, 31, 0x136BE4u);
    ctx->pc = 0x135200u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136BE4u; }
    }
    if (ctx->pc != 0x136BE4u) { return; }
    ctx->pc = 0x136BE4u;
label_136be4:
    // 0x136be4: 0x1000000e
label_136be8:
    if (ctx->pc == 0x136BE8u) {
        ctx->pc = 0x136BE8u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = 0x136BECu;
        goto label_136bec;
    }
    ctx->pc = 0x136BE4u;
    {
        const bool branch_taken_0x136be4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136BE8u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x136be4) {
            ctx->pc = 0x136C20u;
            goto label_136c20;
        }
    }
    ctx->pc = 0x136BECu;
label_136bec:
    // 0x136bec: 0x0
    ctx->pc = 0x136becu;
    // NOP
label_136bf0:
    // 0x136bf0: 0xc041f1a
label_136bf4:
    if (ctx->pc == 0x136BF4u) {
        ctx->pc = 0x136BF8u;
        goto label_136bf8;
    }
    ctx->pc = 0x136BF0u;
    SET_GPR_U32(ctx, 31, 0x136BF8u);
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136BF8u; }
    }
    if (ctx->pc != 0x136BF8u) { return; }
    ctx->pc = 0x136BF8u;
label_136bf8:
    // 0x136bf8: 0x2402ffff
    ctx->pc = 0x136bf8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
label_136bfc:
    // 0x136bfc: 0xafb00000
    ctx->pc = 0x136bfcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 16));
label_136c00:
    // 0x136c00: 0x3a0202d
    ctx->pc = 0x136c00u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_136c04:
    // 0x136c04: 0x24050001
    ctx->pc = 0x136c04u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 1));
label_136c08:
    // 0x136c08: 0x302d
    ctx->pc = 0x136c08u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_136c0c:
    // 0x136c0c: 0x8e230060
    ctx->pc = 0x136c0cu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 96)));
label_136c10:
    // 0x136c10: 0x10600003
label_136c14:
    if (ctx->pc == 0x136C14u) {
        ctx->pc = 0x136C14u;
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x136C18u;
        goto label_136c18;
    }
    ctx->pc = 0x136C10u;
    {
        const bool branch_taken_0x136c10 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x136C14u;
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x136c10) {
            ctx->pc = 0x136C20u;
            goto label_136c20;
        }
    }
    ctx->pc = 0x136C18u;
label_136c18:
    // 0x136c18: 0x60f809
label_136c1c:
    if (ctx->pc == 0x136C1Cu) {
        ctx->pc = 0x136C20u;
        goto label_136c20;
    }
    ctx->pc = 0x136C18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x136C20u);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A80u: goto label_136a80;
            case 0x136A84u: goto label_136a84;
            case 0x136A88u: goto label_136a88;
            case 0x136A8Cu: goto label_136a8c;
            case 0x136A90u: goto label_136a90;
            case 0x136A94u: goto label_136a94;
            case 0x136A98u: goto label_136a98;
            case 0x136A9Cu: goto label_136a9c;
            case 0x136AA0u: goto label_136aa0;
            case 0x136AA4u: goto label_136aa4;
            case 0x136AA8u: goto label_136aa8;
            case 0x136AACu: goto label_136aac;
            case 0x136AB0u: goto label_136ab0;
            case 0x136AB4u: goto label_136ab4;
            case 0x136AB8u: goto label_136ab8;
            case 0x136ABCu: goto label_136abc;
            case 0x136AC0u: goto label_136ac0;
            case 0x136AC4u: goto label_136ac4;
            case 0x136AC8u: goto label_136ac8;
            case 0x136ACCu: goto label_136acc;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AD4u: goto label_136ad4;
            case 0x136AD8u: goto label_136ad8;
            case 0x136ADCu: goto label_136adc;
            case 0x136AE0u: goto label_136ae0;
            case 0x136AE4u: goto label_136ae4;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AECu: goto label_136aec;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF4u: goto label_136af4;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B00u: goto label_136b00;
            case 0x136B04u: goto label_136b04;
            case 0x136B08u: goto label_136b08;
            case 0x136B0Cu: goto label_136b0c;
            case 0x136B10u: goto label_136b10;
            case 0x136B14u: goto label_136b14;
            case 0x136B18u: goto label_136b18;
            case 0x136B1Cu: goto label_136b1c;
            case 0x136B20u: goto label_136b20;
            case 0x136B24u: goto label_136b24;
            case 0x136B28u: goto label_136b28;
            case 0x136B2Cu: goto label_136b2c;
            case 0x136B30u: goto label_136b30;
            case 0x136B34u: goto label_136b34;
            case 0x136B38u: goto label_136b38;
            case 0x136B3Cu: goto label_136b3c;
            case 0x136B40u: goto label_136b40;
            case 0x136B44u: goto label_136b44;
            case 0x136B48u: goto label_136b48;
            case 0x136B4Cu: goto label_136b4c;
            case 0x136B50u: goto label_136b50;
            case 0x136B54u: goto label_136b54;
            case 0x136B58u: goto label_136b58;
            case 0x136B5Cu: goto label_136b5c;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136B68u: goto label_136b68;
            case 0x136B6Cu: goto label_136b6c;
            case 0x136B70u: goto label_136b70;
            case 0x136B74u: goto label_136b74;
            case 0x136B78u: goto label_136b78;
            case 0x136B7Cu: goto label_136b7c;
            case 0x136B80u: goto label_136b80;
            case 0x136B84u: goto label_136b84;
            case 0x136B88u: goto label_136b88;
            case 0x136B8Cu: goto label_136b8c;
            case 0x136B90u: goto label_136b90;
            case 0x136B94u: goto label_136b94;
            case 0x136B98u: goto label_136b98;
            case 0x136B9Cu: goto label_136b9c;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BA4u: goto label_136ba4;
            case 0x136BA8u: goto label_136ba8;
            case 0x136BACu: goto label_136bac;
            case 0x136BB0u: goto label_136bb0;
            case 0x136BB4u: goto label_136bb4;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BBCu: goto label_136bbc;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BC4u: goto label_136bc4;
            case 0x136BC8u: goto label_136bc8;
            case 0x136BCCu: goto label_136bcc;
            case 0x136BD0u: goto label_136bd0;
            case 0x136BD4u: goto label_136bd4;
            case 0x136BD8u: goto label_136bd8;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE0u: goto label_136be0;
            case 0x136BE4u: goto label_136be4;
            case 0x136BE8u: goto label_136be8;
            case 0x136BECu: goto label_136bec;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF4u: goto label_136bf4;
            case 0x136BF8u: goto label_136bf8;
            case 0x136BFCu: goto label_136bfc;
            case 0x136C00u: goto label_136c00;
            case 0x136C04u: goto label_136c04;
            case 0x136C08u: goto label_136c08;
            case 0x136C0Cu: goto label_136c0c;
            case 0x136C10u: goto label_136c10;
            case 0x136C14u: goto label_136c14;
            case 0x136C18u: goto label_136c18;
            case 0x136C1Cu: goto label_136c1c;
            case 0x136C20u: goto label_136c20;
            case 0x136C24u: goto label_136c24;
            case 0x136C28u: goto label_136c28;
            case 0x136C2Cu: goto label_136c2c;
            case 0x136C30u: goto label_136c30;
            case 0x136C34u: goto label_136c34;
            case 0x136C38u: goto label_136c38;
            case 0x136C3Cu: goto label_136c3c;
            case 0x136C40u: goto label_136c40;
            case 0x136C44u: goto label_136c44;
            case 0x136C48u: goto label_136c48;
            case 0x136C4Cu: goto label_136c4c;
            case 0x136C50u: goto label_136c50;
            case 0x136C54u: goto label_136c54;
            case 0x136C58u: goto label_136c58;
            case 0x136C5Cu: goto label_136c5c;
            case 0x136C60u: goto label_136c60;
            case 0x136C64u: goto label_136c64;
            case 0x136C68u: goto label_136c68;
            case 0x136C6Cu: goto label_136c6c;
            case 0x136C70u: goto label_136c70;
            case 0x136C74u: goto label_136c74;
            case 0x136C78u: goto label_136c78;
            case 0x136C7Cu: goto label_136c7c;
            case 0x136C80u: goto label_136c80;
            case 0x136C84u: goto label_136c84;
            case 0x136C88u: goto label_136c88;
            case 0x136C8Cu: goto label_136c8c;
            case 0x136C90u: goto label_136c90;
            case 0x136C94u: goto label_136c94;
            case 0x136C98u: goto label_136c98;
            case 0x136C9Cu: goto label_136c9c;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CA4u: goto label_136ca4;
            case 0x136CA8u: goto label_136ca8;
            case 0x136CACu: goto label_136cac;
            case 0x136CB0u: goto label_136cb0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CB8u: goto label_136cb8;
            case 0x136CBCu: goto label_136cbc;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC4u: goto label_136cc4;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CCCu: goto label_136ccc;
            case 0x136CD0u: goto label_136cd0;
            case 0x136CD4u: goto label_136cd4;
            case 0x136CD8u: goto label_136cd8;
            case 0x136CDCu: goto label_136cdc;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE4u: goto label_136ce4;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CECu: goto label_136cec;
            case 0x136CF0u: goto label_136cf0;
            case 0x136CF4u: goto label_136cf4;
            case 0x136CF8u: goto label_136cf8;
            case 0x136CFCu: goto label_136cfc;
            case 0x136D00u: goto label_136d00;
            case 0x136D04u: goto label_136d04;
            case 0x136D08u: goto label_136d08;
            case 0x136D0Cu: goto label_136d0c;
            case 0x136D10u: goto label_136d10;
            case 0x136D14u: goto label_136d14;
            case 0x136D18u: goto label_136d18;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D20u: goto label_136d20;
            case 0x136D24u: goto label_136d24;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D34u: goto label_136d34;
            case 0x136D38u: goto label_136d38;
            case 0x136D3Cu: goto label_136d3c;
            case 0x136D40u: goto label_136d40;
            case 0x136D44u: goto label_136d44;
            case 0x136D48u: goto label_136d48;
            case 0x136D4Cu: goto label_136d4c;
            case 0x136D50u: goto label_136d50;
            case 0x136D54u: goto label_136d54;
            case 0x136D58u: goto label_136d58;
            case 0x136D5Cu: goto label_136d5c;
            case 0x136D60u: goto label_136d60;
            case 0x136D64u: goto label_136d64;
            case 0x136D68u: goto label_136d68;
            case 0x136D6Cu: goto label_136d6c;
            case 0x136D70u: goto label_136d70;
            case 0x136D74u: goto label_136d74;
            case 0x136D78u: goto label_136d78;
            case 0x136D7Cu: goto label_136d7c;
            case 0x136D80u: goto label_136d80;
            case 0x136D84u: goto label_136d84;
            case 0x136D88u: goto label_136d88;
            case 0x136D8Cu: goto label_136d8c;
            case 0x136D90u: goto label_136d90;
            case 0x136D94u: goto label_136d94;
            case 0x136D98u: goto label_136d98;
            case 0x136D9Cu: goto label_136d9c;
            case 0x136DA0u: goto label_136da0;
            case 0x136DA4u: goto label_136da4;
            case 0x136DA8u: goto label_136da8;
            case 0x136DACu: goto label_136dac;
            case 0x136DB0u: goto label_136db0;
            case 0x136DB4u: goto label_136db4;
            case 0x136DB8u: goto label_136db8;
            case 0x136DBCu: goto label_136dbc;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC4u: goto label_136dc4;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DCCu: goto label_136dcc;
            case 0x136DD0u: goto label_136dd0;
            case 0x136DD4u: goto label_136dd4;
            case 0x136DD8u: goto label_136dd8;
            case 0x136DDCu: goto label_136ddc;
            case 0x136DE0u: goto label_136de0;
            case 0x136DE4u: goto label_136de4;
            case 0x136DE8u: goto label_136de8;
            case 0x136DECu: goto label_136dec;
            case 0x136DF0u: goto label_136df0;
            case 0x136DF4u: goto label_136df4;
            case 0x136DF8u: goto label_136df8;
            case 0x136DFCu: goto label_136dfc;
            case 0x136E00u: goto label_136e00;
            case 0x136E04u: goto label_136e04;
            case 0x136E08u: goto label_136e08;
            case 0x136E0Cu: goto label_136e0c;
            case 0x136E10u: goto label_136e10;
            case 0x136E14u: goto label_136e14;
            case 0x136E18u: goto label_136e18;
            case 0x136E1Cu: goto label_136e1c;
            case 0x136E20u: goto label_136e20;
            case 0x136E24u: goto label_136e24;
            case 0x136E28u: goto label_136e28;
            case 0x136E2Cu: goto label_136e2c;
            case 0x136E30u: goto label_136e30;
            case 0x136E34u: goto label_136e34;
            case 0x136E38u: goto label_136e38;
            case 0x136E3Cu: goto label_136e3c;
            case 0x136E40u: goto label_136e40;
            case 0x136E44u: goto label_136e44;
            case 0x136E48u: goto label_136e48;
            case 0x136E4Cu: goto label_136e4c;
            case 0x136E50u: goto label_136e50;
            case 0x136E54u: goto label_136e54;
            case 0x136E58u: goto label_136e58;
            case 0x136E5Cu: goto label_136e5c;
            case 0x136E60u: goto label_136e60;
            case 0x136E64u: goto label_136e64;
            case 0x136E68u: goto label_136e68;
            case 0x136E6Cu: goto label_136e6c;
            case 0x136E70u: goto label_136e70;
            case 0x136E74u: goto label_136e74;
            case 0x136E78u: goto label_136e78;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E80u: goto label_136e80;
            case 0x136E84u: goto label_136e84;
            case 0x136E88u: goto label_136e88;
            case 0x136E8Cu: goto label_136e8c;
            case 0x136E90u: goto label_136e90;
            case 0x136E94u: goto label_136e94;
            case 0x136E98u: goto label_136e98;
            case 0x136E9Cu: goto label_136e9c;
            case 0x136EA0u: goto label_136ea0;
            case 0x136EA4u: goto label_136ea4;
            case 0x136EA8u: goto label_136ea8;
            case 0x136EACu: goto label_136eac;
            case 0x136EB0u: goto label_136eb0;
            case 0x136EB4u: goto label_136eb4;
            case 0x136EB8u: goto label_136eb8;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EC0u: goto label_136ec0;
            case 0x136EC4u: goto label_136ec4;
            case 0x136EC8u: goto label_136ec8;
            case 0x136ECCu: goto label_136ecc;
            case 0x136ED0u: goto label_136ed0;
            case 0x136ED4u: goto label_136ed4;
            case 0x136ED8u: goto label_136ed8;
            case 0x136EDCu: goto label_136edc;
            case 0x136EE0u: goto label_136ee0;
            case 0x136EE4u: goto label_136ee4;
            case 0x136EE8u: goto label_136ee8;
            case 0x136EECu: goto label_136eec;
            case 0x136EF0u: goto label_136ef0;
            case 0x136EF4u: goto label_136ef4;
            case 0x136EF8u: goto label_136ef8;
            case 0x136EFCu: goto label_136efc;
            case 0x136F00u: goto label_136f00;
            case 0x136F04u: goto label_136f04;
            case 0x136F08u: goto label_136f08;
            case 0x136F0Cu: goto label_136f0c;
            case 0x136F10u: goto label_136f10;
            case 0x136F14u: goto label_136f14;
            case 0x136F18u: goto label_136f18;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F20u: goto label_136f20;
            case 0x136F24u: goto label_136f24;
            case 0x136F28u: goto label_136f28;
            case 0x136F2Cu: goto label_136f2c;
            case 0x136F30u: goto label_136f30;
            case 0x136F34u: goto label_136f34;
            case 0x136F38u: goto label_136f38;
            case 0x136F3Cu: goto label_136f3c;
            case 0x136F40u: goto label_136f40;
            case 0x136F44u: goto label_136f44;
            case 0x136F48u: goto label_136f48;
            case 0x136F4Cu: goto label_136f4c;
            case 0x136F50u: goto label_136f50;
            case 0x136F54u: goto label_136f54;
            case 0x136F58u: goto label_136f58;
            case 0x136F5Cu: goto label_136f5c;
            case 0x136F60u: goto label_136f60;
            case 0x136F64u: goto label_136f64;
            case 0x136F68u: goto label_136f68;
            case 0x136F6Cu: goto label_136f6c;
            case 0x136F70u: goto label_136f70;
            case 0x136F74u: goto label_136f74;
            case 0x136F78u: goto label_136f78;
            case 0x136F7Cu: goto label_136f7c;
            case 0x136F80u: goto label_136f80;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            case 0x136F8Cu: goto label_136f8c;
            case 0x136F90u: goto label_136f90;
            case 0x136F94u: goto label_136f94;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136C20u; }
            if (ctx->pc != 0x136C20u) { return; }
        }
    }
    ctx->pc = 0x136C20u;
label_136c20:
    // 0x136c20: 0xdfb00020
    ctx->pc = 0x136c20u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_136c24:
    // 0x136c24: 0xdfb10028
    ctx->pc = 0x136c24u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
label_136c28:
    // 0x136c28: 0xdfbf0030
    ctx->pc = 0x136c28u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_136c2c:
    // 0x136c2c: 0x3e00008
label_136c30:
    if (ctx->pc == 0x136C30u) {
        ctx->pc = 0x136C30u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = 0x136C34u;
        goto label_136c34;
    }
    ctx->pc = 0x136C2Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136C30u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A80u: goto label_136a80;
            case 0x136A84u: goto label_136a84;
            case 0x136A88u: goto label_136a88;
            case 0x136A8Cu: goto label_136a8c;
            case 0x136A90u: goto label_136a90;
            case 0x136A94u: goto label_136a94;
            case 0x136A98u: goto label_136a98;
            case 0x136A9Cu: goto label_136a9c;
            case 0x136AA0u: goto label_136aa0;
            case 0x136AA4u: goto label_136aa4;
            case 0x136AA8u: goto label_136aa8;
            case 0x136AACu: goto label_136aac;
            case 0x136AB0u: goto label_136ab0;
            case 0x136AB4u: goto label_136ab4;
            case 0x136AB8u: goto label_136ab8;
            case 0x136ABCu: goto label_136abc;
            case 0x136AC0u: goto label_136ac0;
            case 0x136AC4u: goto label_136ac4;
            case 0x136AC8u: goto label_136ac8;
            case 0x136ACCu: goto label_136acc;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AD4u: goto label_136ad4;
            case 0x136AD8u: goto label_136ad8;
            case 0x136ADCu: goto label_136adc;
            case 0x136AE0u: goto label_136ae0;
            case 0x136AE4u: goto label_136ae4;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AECu: goto label_136aec;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF4u: goto label_136af4;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B00u: goto label_136b00;
            case 0x136B04u: goto label_136b04;
            case 0x136B08u: goto label_136b08;
            case 0x136B0Cu: goto label_136b0c;
            case 0x136B10u: goto label_136b10;
            case 0x136B14u: goto label_136b14;
            case 0x136B18u: goto label_136b18;
            case 0x136B1Cu: goto label_136b1c;
            case 0x136B20u: goto label_136b20;
            case 0x136B24u: goto label_136b24;
            case 0x136B28u: goto label_136b28;
            case 0x136B2Cu: goto label_136b2c;
            case 0x136B30u: goto label_136b30;
            case 0x136B34u: goto label_136b34;
            case 0x136B38u: goto label_136b38;
            case 0x136B3Cu: goto label_136b3c;
            case 0x136B40u: goto label_136b40;
            case 0x136B44u: goto label_136b44;
            case 0x136B48u: goto label_136b48;
            case 0x136B4Cu: goto label_136b4c;
            case 0x136B50u: goto label_136b50;
            case 0x136B54u: goto label_136b54;
            case 0x136B58u: goto label_136b58;
            case 0x136B5Cu: goto label_136b5c;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136B68u: goto label_136b68;
            case 0x136B6Cu: goto label_136b6c;
            case 0x136B70u: goto label_136b70;
            case 0x136B74u: goto label_136b74;
            case 0x136B78u: goto label_136b78;
            case 0x136B7Cu: goto label_136b7c;
            case 0x136B80u: goto label_136b80;
            case 0x136B84u: goto label_136b84;
            case 0x136B88u: goto label_136b88;
            case 0x136B8Cu: goto label_136b8c;
            case 0x136B90u: goto label_136b90;
            case 0x136B94u: goto label_136b94;
            case 0x136B98u: goto label_136b98;
            case 0x136B9Cu: goto label_136b9c;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BA4u: goto label_136ba4;
            case 0x136BA8u: goto label_136ba8;
            case 0x136BACu: goto label_136bac;
            case 0x136BB0u: goto label_136bb0;
            case 0x136BB4u: goto label_136bb4;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BBCu: goto label_136bbc;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BC4u: goto label_136bc4;
            case 0x136BC8u: goto label_136bc8;
            case 0x136BCCu: goto label_136bcc;
            case 0x136BD0u: goto label_136bd0;
            case 0x136BD4u: goto label_136bd4;
            case 0x136BD8u: goto label_136bd8;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE0u: goto label_136be0;
            case 0x136BE4u: goto label_136be4;
            case 0x136BE8u: goto label_136be8;
            case 0x136BECu: goto label_136bec;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF4u: goto label_136bf4;
            case 0x136BF8u: goto label_136bf8;
            case 0x136BFCu: goto label_136bfc;
            case 0x136C00u: goto label_136c00;
            case 0x136C04u: goto label_136c04;
            case 0x136C08u: goto label_136c08;
            case 0x136C0Cu: goto label_136c0c;
            case 0x136C10u: goto label_136c10;
            case 0x136C14u: goto label_136c14;
            case 0x136C18u: goto label_136c18;
            case 0x136C1Cu: goto label_136c1c;
            case 0x136C20u: goto label_136c20;
            case 0x136C24u: goto label_136c24;
            case 0x136C28u: goto label_136c28;
            case 0x136C2Cu: goto label_136c2c;
            case 0x136C30u: goto label_136c30;
            case 0x136C34u: goto label_136c34;
            case 0x136C38u: goto label_136c38;
            case 0x136C3Cu: goto label_136c3c;
            case 0x136C40u: goto label_136c40;
            case 0x136C44u: goto label_136c44;
            case 0x136C48u: goto label_136c48;
            case 0x136C4Cu: goto label_136c4c;
            case 0x136C50u: goto label_136c50;
            case 0x136C54u: goto label_136c54;
            case 0x136C58u: goto label_136c58;
            case 0x136C5Cu: goto label_136c5c;
            case 0x136C60u: goto label_136c60;
            case 0x136C64u: goto label_136c64;
            case 0x136C68u: goto label_136c68;
            case 0x136C6Cu: goto label_136c6c;
            case 0x136C70u: goto label_136c70;
            case 0x136C74u: goto label_136c74;
            case 0x136C78u: goto label_136c78;
            case 0x136C7Cu: goto label_136c7c;
            case 0x136C80u: goto label_136c80;
            case 0x136C84u: goto label_136c84;
            case 0x136C88u: goto label_136c88;
            case 0x136C8Cu: goto label_136c8c;
            case 0x136C90u: goto label_136c90;
            case 0x136C94u: goto label_136c94;
            case 0x136C98u: goto label_136c98;
            case 0x136C9Cu: goto label_136c9c;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CA4u: goto label_136ca4;
            case 0x136CA8u: goto label_136ca8;
            case 0x136CACu: goto label_136cac;
            case 0x136CB0u: goto label_136cb0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CB8u: goto label_136cb8;
            case 0x136CBCu: goto label_136cbc;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC4u: goto label_136cc4;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CCCu: goto label_136ccc;
            case 0x136CD0u: goto label_136cd0;
            case 0x136CD4u: goto label_136cd4;
            case 0x136CD8u: goto label_136cd8;
            case 0x136CDCu: goto label_136cdc;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE4u: goto label_136ce4;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CECu: goto label_136cec;
            case 0x136CF0u: goto label_136cf0;
            case 0x136CF4u: goto label_136cf4;
            case 0x136CF8u: goto label_136cf8;
            case 0x136CFCu: goto label_136cfc;
            case 0x136D00u: goto label_136d00;
            case 0x136D04u: goto label_136d04;
            case 0x136D08u: goto label_136d08;
            case 0x136D0Cu: goto label_136d0c;
            case 0x136D10u: goto label_136d10;
            case 0x136D14u: goto label_136d14;
            case 0x136D18u: goto label_136d18;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D20u: goto label_136d20;
            case 0x136D24u: goto label_136d24;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D34u: goto label_136d34;
            case 0x136D38u: goto label_136d38;
            case 0x136D3Cu: goto label_136d3c;
            case 0x136D40u: goto label_136d40;
            case 0x136D44u: goto label_136d44;
            case 0x136D48u: goto label_136d48;
            case 0x136D4Cu: goto label_136d4c;
            case 0x136D50u: goto label_136d50;
            case 0x136D54u: goto label_136d54;
            case 0x136D58u: goto label_136d58;
            case 0x136D5Cu: goto label_136d5c;
            case 0x136D60u: goto label_136d60;
            case 0x136D64u: goto label_136d64;
            case 0x136D68u: goto label_136d68;
            case 0x136D6Cu: goto label_136d6c;
            case 0x136D70u: goto label_136d70;
            case 0x136D74u: goto label_136d74;
            case 0x136D78u: goto label_136d78;
            case 0x136D7Cu: goto label_136d7c;
            case 0x136D80u: goto label_136d80;
            case 0x136D84u: goto label_136d84;
            case 0x136D88u: goto label_136d88;
            case 0x136D8Cu: goto label_136d8c;
            case 0x136D90u: goto label_136d90;
            case 0x136D94u: goto label_136d94;
            case 0x136D98u: goto label_136d98;
            case 0x136D9Cu: goto label_136d9c;
            case 0x136DA0u: goto label_136da0;
            case 0x136DA4u: goto label_136da4;
            case 0x136DA8u: goto label_136da8;
            case 0x136DACu: goto label_136dac;
            case 0x136DB0u: goto label_136db0;
            case 0x136DB4u: goto label_136db4;
            case 0x136DB8u: goto label_136db8;
            case 0x136DBCu: goto label_136dbc;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC4u: goto label_136dc4;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DCCu: goto label_136dcc;
            case 0x136DD0u: goto label_136dd0;
            case 0x136DD4u: goto label_136dd4;
            case 0x136DD8u: goto label_136dd8;
            case 0x136DDCu: goto label_136ddc;
            case 0x136DE0u: goto label_136de0;
            case 0x136DE4u: goto label_136de4;
            case 0x136DE8u: goto label_136de8;
            case 0x136DECu: goto label_136dec;
            case 0x136DF0u: goto label_136df0;
            case 0x136DF4u: goto label_136df4;
            case 0x136DF8u: goto label_136df8;
            case 0x136DFCu: goto label_136dfc;
            case 0x136E00u: goto label_136e00;
            case 0x136E04u: goto label_136e04;
            case 0x136E08u: goto label_136e08;
            case 0x136E0Cu: goto label_136e0c;
            case 0x136E10u: goto label_136e10;
            case 0x136E14u: goto label_136e14;
            case 0x136E18u: goto label_136e18;
            case 0x136E1Cu: goto label_136e1c;
            case 0x136E20u: goto label_136e20;
            case 0x136E24u: goto label_136e24;
            case 0x136E28u: goto label_136e28;
            case 0x136E2Cu: goto label_136e2c;
            case 0x136E30u: goto label_136e30;
            case 0x136E34u: goto label_136e34;
            case 0x136E38u: goto label_136e38;
            case 0x136E3Cu: goto label_136e3c;
            case 0x136E40u: goto label_136e40;
            case 0x136E44u: goto label_136e44;
            case 0x136E48u: goto label_136e48;
            case 0x136E4Cu: goto label_136e4c;
            case 0x136E50u: goto label_136e50;
            case 0x136E54u: goto label_136e54;
            case 0x136E58u: goto label_136e58;
            case 0x136E5Cu: goto label_136e5c;
            case 0x136E60u: goto label_136e60;
            case 0x136E64u: goto label_136e64;
            case 0x136E68u: goto label_136e68;
            case 0x136E6Cu: goto label_136e6c;
            case 0x136E70u: goto label_136e70;
            case 0x136E74u: goto label_136e74;
            case 0x136E78u: goto label_136e78;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E80u: goto label_136e80;
            case 0x136E84u: goto label_136e84;
            case 0x136E88u: goto label_136e88;
            case 0x136E8Cu: goto label_136e8c;
            case 0x136E90u: goto label_136e90;
            case 0x136E94u: goto label_136e94;
            case 0x136E98u: goto label_136e98;
            case 0x136E9Cu: goto label_136e9c;
            case 0x136EA0u: goto label_136ea0;
            case 0x136EA4u: goto label_136ea4;
            case 0x136EA8u: goto label_136ea8;
            case 0x136EACu: goto label_136eac;
            case 0x136EB0u: goto label_136eb0;
            case 0x136EB4u: goto label_136eb4;
            case 0x136EB8u: goto label_136eb8;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EC0u: goto label_136ec0;
            case 0x136EC4u: goto label_136ec4;
            case 0x136EC8u: goto label_136ec8;
            case 0x136ECCu: goto label_136ecc;
            case 0x136ED0u: goto label_136ed0;
            case 0x136ED4u: goto label_136ed4;
            case 0x136ED8u: goto label_136ed8;
            case 0x136EDCu: goto label_136edc;
            case 0x136EE0u: goto label_136ee0;
            case 0x136EE4u: goto label_136ee4;
            case 0x136EE8u: goto label_136ee8;
            case 0x136EECu: goto label_136eec;
            case 0x136EF0u: goto label_136ef0;
            case 0x136EF4u: goto label_136ef4;
            case 0x136EF8u: goto label_136ef8;
            case 0x136EFCu: goto label_136efc;
            case 0x136F00u: goto label_136f00;
            case 0x136F04u: goto label_136f04;
            case 0x136F08u: goto label_136f08;
            case 0x136F0Cu: goto label_136f0c;
            case 0x136F10u: goto label_136f10;
            case 0x136F14u: goto label_136f14;
            case 0x136F18u: goto label_136f18;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F20u: goto label_136f20;
            case 0x136F24u: goto label_136f24;
            case 0x136F28u: goto label_136f28;
            case 0x136F2Cu: goto label_136f2c;
            case 0x136F30u: goto label_136f30;
            case 0x136F34u: goto label_136f34;
            case 0x136F38u: goto label_136f38;
            case 0x136F3Cu: goto label_136f3c;
            case 0x136F40u: goto label_136f40;
            case 0x136F44u: goto label_136f44;
            case 0x136F48u: goto label_136f48;
            case 0x136F4Cu: goto label_136f4c;
            case 0x136F50u: goto label_136f50;
            case 0x136F54u: goto label_136f54;
            case 0x136F58u: goto label_136f58;
            case 0x136F5Cu: goto label_136f5c;
            case 0x136F60u: goto label_136f60;
            case 0x136F64u: goto label_136f64;
            case 0x136F68u: goto label_136f68;
            case 0x136F6Cu: goto label_136f6c;
            case 0x136F70u: goto label_136f70;
            case 0x136F74u: goto label_136f74;
            case 0x136F78u: goto label_136f78;
            case 0x136F7Cu: goto label_136f7c;
            case 0x136F80u: goto label_136f80;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            case 0x136F8Cu: goto label_136f8c;
            case 0x136F90u: goto label_136f90;
            case 0x136F94u: goto label_136f94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136C34u;
label_136c34:
    // 0x136c34: 0x0
    ctx->pc = 0x136c34u;
    // NOP
label_136c38:
    // 0x136c38: 0x3e00008
label_136c3c:
    if (ctx->pc == 0x136C3Cu) {
        ctx->pc = 0x136C3Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x136C40u;
        goto label_136c40;
    }
    ctx->pc = 0x136C38u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136C3Cu;
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A80u: goto label_136a80;
            case 0x136A84u: goto label_136a84;
            case 0x136A88u: goto label_136a88;
            case 0x136A8Cu: goto label_136a8c;
            case 0x136A90u: goto label_136a90;
            case 0x136A94u: goto label_136a94;
            case 0x136A98u: goto label_136a98;
            case 0x136A9Cu: goto label_136a9c;
            case 0x136AA0u: goto label_136aa0;
            case 0x136AA4u: goto label_136aa4;
            case 0x136AA8u: goto label_136aa8;
            case 0x136AACu: goto label_136aac;
            case 0x136AB0u: goto label_136ab0;
            case 0x136AB4u: goto label_136ab4;
            case 0x136AB8u: goto label_136ab8;
            case 0x136ABCu: goto label_136abc;
            case 0x136AC0u: goto label_136ac0;
            case 0x136AC4u: goto label_136ac4;
            case 0x136AC8u: goto label_136ac8;
            case 0x136ACCu: goto label_136acc;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AD4u: goto label_136ad4;
            case 0x136AD8u: goto label_136ad8;
            case 0x136ADCu: goto label_136adc;
            case 0x136AE0u: goto label_136ae0;
            case 0x136AE4u: goto label_136ae4;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AECu: goto label_136aec;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF4u: goto label_136af4;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B00u: goto label_136b00;
            case 0x136B04u: goto label_136b04;
            case 0x136B08u: goto label_136b08;
            case 0x136B0Cu: goto label_136b0c;
            case 0x136B10u: goto label_136b10;
            case 0x136B14u: goto label_136b14;
            case 0x136B18u: goto label_136b18;
            case 0x136B1Cu: goto label_136b1c;
            case 0x136B20u: goto label_136b20;
            case 0x136B24u: goto label_136b24;
            case 0x136B28u: goto label_136b28;
            case 0x136B2Cu: goto label_136b2c;
            case 0x136B30u: goto label_136b30;
            case 0x136B34u: goto label_136b34;
            case 0x136B38u: goto label_136b38;
            case 0x136B3Cu: goto label_136b3c;
            case 0x136B40u: goto label_136b40;
            case 0x136B44u: goto label_136b44;
            case 0x136B48u: goto label_136b48;
            case 0x136B4Cu: goto label_136b4c;
            case 0x136B50u: goto label_136b50;
            case 0x136B54u: goto label_136b54;
            case 0x136B58u: goto label_136b58;
            case 0x136B5Cu: goto label_136b5c;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136B68u: goto label_136b68;
            case 0x136B6Cu: goto label_136b6c;
            case 0x136B70u: goto label_136b70;
            case 0x136B74u: goto label_136b74;
            case 0x136B78u: goto label_136b78;
            case 0x136B7Cu: goto label_136b7c;
            case 0x136B80u: goto label_136b80;
            case 0x136B84u: goto label_136b84;
            case 0x136B88u: goto label_136b88;
            case 0x136B8Cu: goto label_136b8c;
            case 0x136B90u: goto label_136b90;
            case 0x136B94u: goto label_136b94;
            case 0x136B98u: goto label_136b98;
            case 0x136B9Cu: goto label_136b9c;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BA4u: goto label_136ba4;
            case 0x136BA8u: goto label_136ba8;
            case 0x136BACu: goto label_136bac;
            case 0x136BB0u: goto label_136bb0;
            case 0x136BB4u: goto label_136bb4;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BBCu: goto label_136bbc;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BC4u: goto label_136bc4;
            case 0x136BC8u: goto label_136bc8;
            case 0x136BCCu: goto label_136bcc;
            case 0x136BD0u: goto label_136bd0;
            case 0x136BD4u: goto label_136bd4;
            case 0x136BD8u: goto label_136bd8;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE0u: goto label_136be0;
            case 0x136BE4u: goto label_136be4;
            case 0x136BE8u: goto label_136be8;
            case 0x136BECu: goto label_136bec;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF4u: goto label_136bf4;
            case 0x136BF8u: goto label_136bf8;
            case 0x136BFCu: goto label_136bfc;
            case 0x136C00u: goto label_136c00;
            case 0x136C04u: goto label_136c04;
            case 0x136C08u: goto label_136c08;
            case 0x136C0Cu: goto label_136c0c;
            case 0x136C10u: goto label_136c10;
            case 0x136C14u: goto label_136c14;
            case 0x136C18u: goto label_136c18;
            case 0x136C1Cu: goto label_136c1c;
            case 0x136C20u: goto label_136c20;
            case 0x136C24u: goto label_136c24;
            case 0x136C28u: goto label_136c28;
            case 0x136C2Cu: goto label_136c2c;
            case 0x136C30u: goto label_136c30;
            case 0x136C34u: goto label_136c34;
            case 0x136C38u: goto label_136c38;
            case 0x136C3Cu: goto label_136c3c;
            case 0x136C40u: goto label_136c40;
            case 0x136C44u: goto label_136c44;
            case 0x136C48u: goto label_136c48;
            case 0x136C4Cu: goto label_136c4c;
            case 0x136C50u: goto label_136c50;
            case 0x136C54u: goto label_136c54;
            case 0x136C58u: goto label_136c58;
            case 0x136C5Cu: goto label_136c5c;
            case 0x136C60u: goto label_136c60;
            case 0x136C64u: goto label_136c64;
            case 0x136C68u: goto label_136c68;
            case 0x136C6Cu: goto label_136c6c;
            case 0x136C70u: goto label_136c70;
            case 0x136C74u: goto label_136c74;
            case 0x136C78u: goto label_136c78;
            case 0x136C7Cu: goto label_136c7c;
            case 0x136C80u: goto label_136c80;
            case 0x136C84u: goto label_136c84;
            case 0x136C88u: goto label_136c88;
            case 0x136C8Cu: goto label_136c8c;
            case 0x136C90u: goto label_136c90;
            case 0x136C94u: goto label_136c94;
            case 0x136C98u: goto label_136c98;
            case 0x136C9Cu: goto label_136c9c;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CA4u: goto label_136ca4;
            case 0x136CA8u: goto label_136ca8;
            case 0x136CACu: goto label_136cac;
            case 0x136CB0u: goto label_136cb0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CB8u: goto label_136cb8;
            case 0x136CBCu: goto label_136cbc;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC4u: goto label_136cc4;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CCCu: goto label_136ccc;
            case 0x136CD0u: goto label_136cd0;
            case 0x136CD4u: goto label_136cd4;
            case 0x136CD8u: goto label_136cd8;
            case 0x136CDCu: goto label_136cdc;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE4u: goto label_136ce4;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CECu: goto label_136cec;
            case 0x136CF0u: goto label_136cf0;
            case 0x136CF4u: goto label_136cf4;
            case 0x136CF8u: goto label_136cf8;
            case 0x136CFCu: goto label_136cfc;
            case 0x136D00u: goto label_136d00;
            case 0x136D04u: goto label_136d04;
            case 0x136D08u: goto label_136d08;
            case 0x136D0Cu: goto label_136d0c;
            case 0x136D10u: goto label_136d10;
            case 0x136D14u: goto label_136d14;
            case 0x136D18u: goto label_136d18;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D20u: goto label_136d20;
            case 0x136D24u: goto label_136d24;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D34u: goto label_136d34;
            case 0x136D38u: goto label_136d38;
            case 0x136D3Cu: goto label_136d3c;
            case 0x136D40u: goto label_136d40;
            case 0x136D44u: goto label_136d44;
            case 0x136D48u: goto label_136d48;
            case 0x136D4Cu: goto label_136d4c;
            case 0x136D50u: goto label_136d50;
            case 0x136D54u: goto label_136d54;
            case 0x136D58u: goto label_136d58;
            case 0x136D5Cu: goto label_136d5c;
            case 0x136D60u: goto label_136d60;
            case 0x136D64u: goto label_136d64;
            case 0x136D68u: goto label_136d68;
            case 0x136D6Cu: goto label_136d6c;
            case 0x136D70u: goto label_136d70;
            case 0x136D74u: goto label_136d74;
            case 0x136D78u: goto label_136d78;
            case 0x136D7Cu: goto label_136d7c;
            case 0x136D80u: goto label_136d80;
            case 0x136D84u: goto label_136d84;
            case 0x136D88u: goto label_136d88;
            case 0x136D8Cu: goto label_136d8c;
            case 0x136D90u: goto label_136d90;
            case 0x136D94u: goto label_136d94;
            case 0x136D98u: goto label_136d98;
            case 0x136D9Cu: goto label_136d9c;
            case 0x136DA0u: goto label_136da0;
            case 0x136DA4u: goto label_136da4;
            case 0x136DA8u: goto label_136da8;
            case 0x136DACu: goto label_136dac;
            case 0x136DB0u: goto label_136db0;
            case 0x136DB4u: goto label_136db4;
            case 0x136DB8u: goto label_136db8;
            case 0x136DBCu: goto label_136dbc;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC4u: goto label_136dc4;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DCCu: goto label_136dcc;
            case 0x136DD0u: goto label_136dd0;
            case 0x136DD4u: goto label_136dd4;
            case 0x136DD8u: goto label_136dd8;
            case 0x136DDCu: goto label_136ddc;
            case 0x136DE0u: goto label_136de0;
            case 0x136DE4u: goto label_136de4;
            case 0x136DE8u: goto label_136de8;
            case 0x136DECu: goto label_136dec;
            case 0x136DF0u: goto label_136df0;
            case 0x136DF4u: goto label_136df4;
            case 0x136DF8u: goto label_136df8;
            case 0x136DFCu: goto label_136dfc;
            case 0x136E00u: goto label_136e00;
            case 0x136E04u: goto label_136e04;
            case 0x136E08u: goto label_136e08;
            case 0x136E0Cu: goto label_136e0c;
            case 0x136E10u: goto label_136e10;
            case 0x136E14u: goto label_136e14;
            case 0x136E18u: goto label_136e18;
            case 0x136E1Cu: goto label_136e1c;
            case 0x136E20u: goto label_136e20;
            case 0x136E24u: goto label_136e24;
            case 0x136E28u: goto label_136e28;
            case 0x136E2Cu: goto label_136e2c;
            case 0x136E30u: goto label_136e30;
            case 0x136E34u: goto label_136e34;
            case 0x136E38u: goto label_136e38;
            case 0x136E3Cu: goto label_136e3c;
            case 0x136E40u: goto label_136e40;
            case 0x136E44u: goto label_136e44;
            case 0x136E48u: goto label_136e48;
            case 0x136E4Cu: goto label_136e4c;
            case 0x136E50u: goto label_136e50;
            case 0x136E54u: goto label_136e54;
            case 0x136E58u: goto label_136e58;
            case 0x136E5Cu: goto label_136e5c;
            case 0x136E60u: goto label_136e60;
            case 0x136E64u: goto label_136e64;
            case 0x136E68u: goto label_136e68;
            case 0x136E6Cu: goto label_136e6c;
            case 0x136E70u: goto label_136e70;
            case 0x136E74u: goto label_136e74;
            case 0x136E78u: goto label_136e78;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E80u: goto label_136e80;
            case 0x136E84u: goto label_136e84;
            case 0x136E88u: goto label_136e88;
            case 0x136E8Cu: goto label_136e8c;
            case 0x136E90u: goto label_136e90;
            case 0x136E94u: goto label_136e94;
            case 0x136E98u: goto label_136e98;
            case 0x136E9Cu: goto label_136e9c;
            case 0x136EA0u: goto label_136ea0;
            case 0x136EA4u: goto label_136ea4;
            case 0x136EA8u: goto label_136ea8;
            case 0x136EACu: goto label_136eac;
            case 0x136EB0u: goto label_136eb0;
            case 0x136EB4u: goto label_136eb4;
            case 0x136EB8u: goto label_136eb8;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EC0u: goto label_136ec0;
            case 0x136EC4u: goto label_136ec4;
            case 0x136EC8u: goto label_136ec8;
            case 0x136ECCu: goto label_136ecc;
            case 0x136ED0u: goto label_136ed0;
            case 0x136ED4u: goto label_136ed4;
            case 0x136ED8u: goto label_136ed8;
            case 0x136EDCu: goto label_136edc;
            case 0x136EE0u: goto label_136ee0;
            case 0x136EE4u: goto label_136ee4;
            case 0x136EE8u: goto label_136ee8;
            case 0x136EECu: goto label_136eec;
            case 0x136EF0u: goto label_136ef0;
            case 0x136EF4u: goto label_136ef4;
            case 0x136EF8u: goto label_136ef8;
            case 0x136EFCu: goto label_136efc;
            case 0x136F00u: goto label_136f00;
            case 0x136F04u: goto label_136f04;
            case 0x136F08u: goto label_136f08;
            case 0x136F0Cu: goto label_136f0c;
            case 0x136F10u: goto label_136f10;
            case 0x136F14u: goto label_136f14;
            case 0x136F18u: goto label_136f18;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F20u: goto label_136f20;
            case 0x136F24u: goto label_136f24;
            case 0x136F28u: goto label_136f28;
            case 0x136F2Cu: goto label_136f2c;
            case 0x136F30u: goto label_136f30;
            case 0x136F34u: goto label_136f34;
            case 0x136F38u: goto label_136f38;
            case 0x136F3Cu: goto label_136f3c;
            case 0x136F40u: goto label_136f40;
            case 0x136F44u: goto label_136f44;
            case 0x136F48u: goto label_136f48;
            case 0x136F4Cu: goto label_136f4c;
            case 0x136F50u: goto label_136f50;
            case 0x136F54u: goto label_136f54;
            case 0x136F58u: goto label_136f58;
            case 0x136F5Cu: goto label_136f5c;
            case 0x136F60u: goto label_136f60;
            case 0x136F64u: goto label_136f64;
            case 0x136F68u: goto label_136f68;
            case 0x136F6Cu: goto label_136f6c;
            case 0x136F70u: goto label_136f70;
            case 0x136F74u: goto label_136f74;
            case 0x136F78u: goto label_136f78;
            case 0x136F7Cu: goto label_136f7c;
            case 0x136F80u: goto label_136f80;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            case 0x136F8Cu: goto label_136f8c;
            case 0x136F90u: goto label_136f90;
            case 0x136F94u: goto label_136f94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136C40u;
label_136c40:
    // 0x136c40: 0x27bdffb0
    ctx->pc = 0x136c40u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967216));
label_136c44:
    // 0x136c44: 0xffb10028
    ctx->pc = 0x136c44u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
label_136c48:
    // 0x136c48: 0xc0882d
    ctx->pc = 0x136c48u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_136c4c:
    // 0x136c4c: 0xffb20030
    ctx->pc = 0x136c4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
label_136c50:
    // 0x136c50: 0xa0902d
    ctx->pc = 0x136c50u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_136c54:
    // 0x136c54: 0xffb30038
    ctx->pc = 0x136c54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 19));
label_136c58:
    // 0x136c58: 0xe0982d
    ctx->pc = 0x136c58u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
label_136c5c:
    // 0x136c5c: 0xffb00020
    ctx->pc = 0x136c5cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
label_136c60:
    // 0x136c60: 0x14800007
label_136c64:
    if (ctx->pc == 0x136C64u) {
        ctx->pc = 0x136C64u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
        ctx->pc = 0x136C68u;
        goto label_136c68;
    }
    ctx->pc = 0x136C60u;
    {
        const bool branch_taken_0x136c60 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x136C64u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
        if (branch_taken_0x136c60) {
            ctx->pc = 0x136C80u;
            goto label_136c80;
        }
    }
    ctx->pc = 0x136C68u;
label_136c68:
    // 0x136c68: 0x3c040024
    ctx->pc = 0x136c68u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_136c6c:
    // 0x136c6c: 0xc04d480
label_136c70:
    if (ctx->pc == 0x136C70u) {
        ctx->pc = 0x136C70u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951360));
        ctx->pc = 0x136C74u;
        goto label_136c74;
    }
    ctx->pc = 0x136C6Cu;
    SET_GPR_U32(ctx, 31, 0x136C74u);
    ctx->pc = 0x136C70u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951360));
    ctx->pc = 0x135200u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136C74u; }
    }
    if (ctx->pc != 0x136C74u) { return; }
    ctx->pc = 0x136C74u;
label_136c74:
    // 0x136c74: 0x1000002d
label_136c78:
    if (ctx->pc == 0x136C78u) {
        ctx->pc = 0x136C78u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = 0x136C7Cu;
        goto label_136c7c;
    }
    ctx->pc = 0x136C74u;
    {
        const bool branch_taken_0x136c74 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136C78u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x136c74) {
            ctx->pc = 0x136D2Cu;
            goto label_136d2c;
        }
    }
    ctx->pc = 0x136C7Cu;
label_136c7c:
    // 0x136c7c: 0x0
    ctx->pc = 0x136c7cu;
    // NOP
label_136c80:
    // 0x136c80: 0x16400007
label_136c84:
    if (ctx->pc == 0x136C84u) {
        ctx->pc = 0x136C88u;
        goto label_136c88;
    }
    ctx->pc = 0x136C80u;
    {
        const bool branch_taken_0x136c80 = (GPR_U32(ctx, 18) != GPR_U32(ctx, 0));
        if (branch_taken_0x136c80) {
            ctx->pc = 0x136CA0u;
            goto label_136ca0;
        }
    }
    ctx->pc = 0x136C88u;
label_136c88:
    // 0x136c88: 0x3c040024
    ctx->pc = 0x136c88u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_136c8c:
    // 0x136c8c: 0xc04d480
label_136c90:
    if (ctx->pc == 0x136C90u) {
        ctx->pc = 0x136C90u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951400));
        ctx->pc = 0x136C94u;
        goto label_136c94;
    }
    ctx->pc = 0x136C8Cu;
    SET_GPR_U32(ctx, 31, 0x136C94u);
    ctx->pc = 0x136C90u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951400));
    ctx->pc = 0x135200u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136C94u; }
    }
    if (ctx->pc != 0x136C94u) { return; }
    ctx->pc = 0x136C94u;
label_136c94:
    // 0x136c94: 0x10000025
label_136c98:
    if (ctx->pc == 0x136C98u) {
        ctx->pc = 0x136C98u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = 0x136C9Cu;
        goto label_136c9c;
    }
    ctx->pc = 0x136C94u;
    {
        const bool branch_taken_0x136c94 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136C98u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x136c94) {
            ctx->pc = 0x136D2Cu;
            goto label_136d2c;
        }
    }
    ctx->pc = 0x136C9Cu;
label_136c9c:
    // 0x136c9c: 0x0
    ctx->pc = 0x136c9cu;
    // NOP
label_136ca0:
    // 0x136ca0: 0x16200007
label_136ca4:
    if (ctx->pc == 0x136CA4u) {
        ctx->pc = 0x136CA8u;
        goto label_136ca8;
    }
    ctx->pc = 0x136CA0u;
    {
        const bool branch_taken_0x136ca0 = (GPR_U32(ctx, 17) != GPR_U32(ctx, 0));
        if (branch_taken_0x136ca0) {
            ctx->pc = 0x136CC0u;
            goto label_136cc0;
        }
    }
    ctx->pc = 0x136CA8u;
label_136ca8:
    // 0x136ca8: 0x3c040024
    ctx->pc = 0x136ca8u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_136cac:
    // 0x136cac: 0xc04d480
label_136cb0:
    if (ctx->pc == 0x136CB0u) {
        ctx->pc = 0x136CB0u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951440));
        ctx->pc = 0x136CB4u;
        goto label_136cb4;
    }
    ctx->pc = 0x136CACu;
    SET_GPR_U32(ctx, 31, 0x136CB4u);
    ctx->pc = 0x136CB0u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951440));
    ctx->pc = 0x135200u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136CB4u; }
    }
    if (ctx->pc != 0x136CB4u) { return; }
    ctx->pc = 0x136CB4u;
label_136cb4:
    // 0x136cb4: 0x1000001d
label_136cb8:
    if (ctx->pc == 0x136CB8u) {
        ctx->pc = 0x136CB8u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = 0x136CBCu;
        goto label_136cbc;
    }
    ctx->pc = 0x136CB4u;
    {
        const bool branch_taken_0x136cb4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136CB8u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x136cb4) {
            ctx->pc = 0x136D2Cu;
            goto label_136d2c;
        }
    }
    ctx->pc = 0x136CBCu;
label_136cbc:
    // 0x136cbc: 0x0
    ctx->pc = 0x136cbcu;
    // NOP
label_136cc0:
    // 0x136cc0: 0xc04d558
label_136cc4:
    if (ctx->pc == 0x136CC4u) {
        ctx->pc = 0x136CC8u;
        goto label_136cc8;
    }
    ctx->pc = 0x136CC0u;
    SET_GPR_U32(ctx, 31, 0x136CC8u);
    ctx->pc = 0x135560u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136CC8u; }
    }
    if (ctx->pc != 0x136CC8u) { return; }
    ctx->pc = 0x136CC8u;
label_136cc8:
    // 0x136cc8: 0x40802d
    ctx->pc = 0x136cc8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_136ccc:
    // 0x136ccc: 0x56000006
label_136cd0:
    if (ctx->pc == 0x136CD0u) {
        ctx->pc = 0x136CD0u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x136CD4u;
        goto label_136cd4;
    }
    ctx->pc = 0x136CCCu;
    {
        const bool branch_taken_0x136ccc = (GPR_U32(ctx, 16) != GPR_U32(ctx, 0));
        if (branch_taken_0x136ccc) {
            ctx->pc = 0x136CD0u;
            SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
            ctx->pc = 0x136CE8u;
            goto label_136ce8;
        }
    }
    ctx->pc = 0x136CD4u;
label_136cd4:
    // 0x136cd4: 0x3c040024
    ctx->pc = 0x136cd4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_136cd8:
    // 0x136cd8: 0xc04d480
label_136cdc:
    if (ctx->pc == 0x136CDCu) {
        ctx->pc = 0x136CDCu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951480));
        ctx->pc = 0x136CE0u;
        goto label_136ce0;
    }
    ctx->pc = 0x136CD8u;
    SET_GPR_U32(ctx, 31, 0x136CE0u);
    ctx->pc = 0x136CDCu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951480));
    ctx->pc = 0x135200u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136CE0u; }
    }
    if (ctx->pc != 0x136CE0u) { return; }
    ctx->pc = 0x136CE0u;
label_136ce0:
    // 0x136ce0: 0x10000012
label_136ce4:
    if (ctx->pc == 0x136CE4u) {
        ctx->pc = 0x136CE4u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = 0x136CE8u;
        goto label_136ce8;
    }
    ctx->pc = 0x136CE0u;
    {
        const bool branch_taken_0x136ce0 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136CE4u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x136ce0) {
            ctx->pc = 0x136D2Cu;
            goto label_136d2c;
        }
    }
    ctx->pc = 0x136CE8u;
label_136ce8:
    // 0x136ce8: 0x282d
    ctx->pc = 0x136ce8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_136cec:
    // 0x136cec: 0xc041f1a
label_136cf0:
    if (ctx->pc == 0x136CF0u) {
        ctx->pc = 0x136CF0u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 20));
        ctx->pc = 0x136CF4u;
        goto label_136cf4;
    }
    ctx->pc = 0x136CECu;
    SET_GPR_U32(ctx, 31, 0x136CF4u);
    ctx->pc = 0x136CF0u;
    SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 20));
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136CF4u; }
    }
    if (ctx->pc != 0x136CF4u) { return; }
    ctx->pc = 0x136CF4u;
label_136cf4:
    // 0x136cf4: 0xafb10000
    ctx->pc = 0x136cf4u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 17));
label_136cf8:
    // 0x136cf8: 0xafb20004
    ctx->pc = 0x136cf8u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 18));
label_136cfc:
    // 0x136cfc: 0xafb30008
    ctx->pc = 0x136cfcu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 19));
label_136d00:
    // 0x136d00: 0x8e020060
    ctx->pc = 0x136d00u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 16), 96)));
label_136d04:
    // 0x136d04: 0x10400008
label_136d08:
    if (ctx->pc == 0x136D08u) {
        ctx->pc = 0x136D08u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x136D0Cu;
        goto label_136d0c;
    }
    ctx->pc = 0x136D04u;
    {
        const bool branch_taken_0x136d04 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x136D08u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x136d04) {
            ctx->pc = 0x136D28u;
            goto label_136d28;
        }
    }
    ctx->pc = 0x136D0Cu;
label_136d0c:
    // 0x136d0c: 0x24050002
    ctx->pc = 0x136d0cu;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 2));
label_136d10:
    // 0x136d10: 0x302d
    ctx->pc = 0x136d10u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_136d14:
    // 0x136d14: 0x40f809
label_136d18:
    if (ctx->pc == 0x136D18u) {
        ctx->pc = 0x136D18u;
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x136D1Cu;
        goto label_136d1c;
    }
    ctx->pc = 0x136D14u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136D1Cu);
        ctx->pc = 0x136D18u;
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A80u: goto label_136a80;
            case 0x136A84u: goto label_136a84;
            case 0x136A88u: goto label_136a88;
            case 0x136A8Cu: goto label_136a8c;
            case 0x136A90u: goto label_136a90;
            case 0x136A94u: goto label_136a94;
            case 0x136A98u: goto label_136a98;
            case 0x136A9Cu: goto label_136a9c;
            case 0x136AA0u: goto label_136aa0;
            case 0x136AA4u: goto label_136aa4;
            case 0x136AA8u: goto label_136aa8;
            case 0x136AACu: goto label_136aac;
            case 0x136AB0u: goto label_136ab0;
            case 0x136AB4u: goto label_136ab4;
            case 0x136AB8u: goto label_136ab8;
            case 0x136ABCu: goto label_136abc;
            case 0x136AC0u: goto label_136ac0;
            case 0x136AC4u: goto label_136ac4;
            case 0x136AC8u: goto label_136ac8;
            case 0x136ACCu: goto label_136acc;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AD4u: goto label_136ad4;
            case 0x136AD8u: goto label_136ad8;
            case 0x136ADCu: goto label_136adc;
            case 0x136AE0u: goto label_136ae0;
            case 0x136AE4u: goto label_136ae4;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AECu: goto label_136aec;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF4u: goto label_136af4;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B00u: goto label_136b00;
            case 0x136B04u: goto label_136b04;
            case 0x136B08u: goto label_136b08;
            case 0x136B0Cu: goto label_136b0c;
            case 0x136B10u: goto label_136b10;
            case 0x136B14u: goto label_136b14;
            case 0x136B18u: goto label_136b18;
            case 0x136B1Cu: goto label_136b1c;
            case 0x136B20u: goto label_136b20;
            case 0x136B24u: goto label_136b24;
            case 0x136B28u: goto label_136b28;
            case 0x136B2Cu: goto label_136b2c;
            case 0x136B30u: goto label_136b30;
            case 0x136B34u: goto label_136b34;
            case 0x136B38u: goto label_136b38;
            case 0x136B3Cu: goto label_136b3c;
            case 0x136B40u: goto label_136b40;
            case 0x136B44u: goto label_136b44;
            case 0x136B48u: goto label_136b48;
            case 0x136B4Cu: goto label_136b4c;
            case 0x136B50u: goto label_136b50;
            case 0x136B54u: goto label_136b54;
            case 0x136B58u: goto label_136b58;
            case 0x136B5Cu: goto label_136b5c;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136B68u: goto label_136b68;
            case 0x136B6Cu: goto label_136b6c;
            case 0x136B70u: goto label_136b70;
            case 0x136B74u: goto label_136b74;
            case 0x136B78u: goto label_136b78;
            case 0x136B7Cu: goto label_136b7c;
            case 0x136B80u: goto label_136b80;
            case 0x136B84u: goto label_136b84;
            case 0x136B88u: goto label_136b88;
            case 0x136B8Cu: goto label_136b8c;
            case 0x136B90u: goto label_136b90;
            case 0x136B94u: goto label_136b94;
            case 0x136B98u: goto label_136b98;
            case 0x136B9Cu: goto label_136b9c;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BA4u: goto label_136ba4;
            case 0x136BA8u: goto label_136ba8;
            case 0x136BACu: goto label_136bac;
            case 0x136BB0u: goto label_136bb0;
            case 0x136BB4u: goto label_136bb4;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BBCu: goto label_136bbc;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BC4u: goto label_136bc4;
            case 0x136BC8u: goto label_136bc8;
            case 0x136BCCu: goto label_136bcc;
            case 0x136BD0u: goto label_136bd0;
            case 0x136BD4u: goto label_136bd4;
            case 0x136BD8u: goto label_136bd8;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE0u: goto label_136be0;
            case 0x136BE4u: goto label_136be4;
            case 0x136BE8u: goto label_136be8;
            case 0x136BECu: goto label_136bec;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF4u: goto label_136bf4;
            case 0x136BF8u: goto label_136bf8;
            case 0x136BFCu: goto label_136bfc;
            case 0x136C00u: goto label_136c00;
            case 0x136C04u: goto label_136c04;
            case 0x136C08u: goto label_136c08;
            case 0x136C0Cu: goto label_136c0c;
            case 0x136C10u: goto label_136c10;
            case 0x136C14u: goto label_136c14;
            case 0x136C18u: goto label_136c18;
            case 0x136C1Cu: goto label_136c1c;
            case 0x136C20u: goto label_136c20;
            case 0x136C24u: goto label_136c24;
            case 0x136C28u: goto label_136c28;
            case 0x136C2Cu: goto label_136c2c;
            case 0x136C30u: goto label_136c30;
            case 0x136C34u: goto label_136c34;
            case 0x136C38u: goto label_136c38;
            case 0x136C3Cu: goto label_136c3c;
            case 0x136C40u: goto label_136c40;
            case 0x136C44u: goto label_136c44;
            case 0x136C48u: goto label_136c48;
            case 0x136C4Cu: goto label_136c4c;
            case 0x136C50u: goto label_136c50;
            case 0x136C54u: goto label_136c54;
            case 0x136C58u: goto label_136c58;
            case 0x136C5Cu: goto label_136c5c;
            case 0x136C60u: goto label_136c60;
            case 0x136C64u: goto label_136c64;
            case 0x136C68u: goto label_136c68;
            case 0x136C6Cu: goto label_136c6c;
            case 0x136C70u: goto label_136c70;
            case 0x136C74u: goto label_136c74;
            case 0x136C78u: goto label_136c78;
            case 0x136C7Cu: goto label_136c7c;
            case 0x136C80u: goto label_136c80;
            case 0x136C84u: goto label_136c84;
            case 0x136C88u: goto label_136c88;
            case 0x136C8Cu: goto label_136c8c;
            case 0x136C90u: goto label_136c90;
            case 0x136C94u: goto label_136c94;
            case 0x136C98u: goto label_136c98;
            case 0x136C9Cu: goto label_136c9c;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CA4u: goto label_136ca4;
            case 0x136CA8u: goto label_136ca8;
            case 0x136CACu: goto label_136cac;
            case 0x136CB0u: goto label_136cb0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CB8u: goto label_136cb8;
            case 0x136CBCu: goto label_136cbc;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC4u: goto label_136cc4;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CCCu: goto label_136ccc;
            case 0x136CD0u: goto label_136cd0;
            case 0x136CD4u: goto label_136cd4;
            case 0x136CD8u: goto label_136cd8;
            case 0x136CDCu: goto label_136cdc;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE4u: goto label_136ce4;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CECu: goto label_136cec;
            case 0x136CF0u: goto label_136cf0;
            case 0x136CF4u: goto label_136cf4;
            case 0x136CF8u: goto label_136cf8;
            case 0x136CFCu: goto label_136cfc;
            case 0x136D00u: goto label_136d00;
            case 0x136D04u: goto label_136d04;
            case 0x136D08u: goto label_136d08;
            case 0x136D0Cu: goto label_136d0c;
            case 0x136D10u: goto label_136d10;
            case 0x136D14u: goto label_136d14;
            case 0x136D18u: goto label_136d18;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D20u: goto label_136d20;
            case 0x136D24u: goto label_136d24;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D34u: goto label_136d34;
            case 0x136D38u: goto label_136d38;
            case 0x136D3Cu: goto label_136d3c;
            case 0x136D40u: goto label_136d40;
            case 0x136D44u: goto label_136d44;
            case 0x136D48u: goto label_136d48;
            case 0x136D4Cu: goto label_136d4c;
            case 0x136D50u: goto label_136d50;
            case 0x136D54u: goto label_136d54;
            case 0x136D58u: goto label_136d58;
            case 0x136D5Cu: goto label_136d5c;
            case 0x136D60u: goto label_136d60;
            case 0x136D64u: goto label_136d64;
            case 0x136D68u: goto label_136d68;
            case 0x136D6Cu: goto label_136d6c;
            case 0x136D70u: goto label_136d70;
            case 0x136D74u: goto label_136d74;
            case 0x136D78u: goto label_136d78;
            case 0x136D7Cu: goto label_136d7c;
            case 0x136D80u: goto label_136d80;
            case 0x136D84u: goto label_136d84;
            case 0x136D88u: goto label_136d88;
            case 0x136D8Cu: goto label_136d8c;
            case 0x136D90u: goto label_136d90;
            case 0x136D94u: goto label_136d94;
            case 0x136D98u: goto label_136d98;
            case 0x136D9Cu: goto label_136d9c;
            case 0x136DA0u: goto label_136da0;
            case 0x136DA4u: goto label_136da4;
            case 0x136DA8u: goto label_136da8;
            case 0x136DACu: goto label_136dac;
            case 0x136DB0u: goto label_136db0;
            case 0x136DB4u: goto label_136db4;
            case 0x136DB8u: goto label_136db8;
            case 0x136DBCu: goto label_136dbc;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC4u: goto label_136dc4;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DCCu: goto label_136dcc;
            case 0x136DD0u: goto label_136dd0;
            case 0x136DD4u: goto label_136dd4;
            case 0x136DD8u: goto label_136dd8;
            case 0x136DDCu: goto label_136ddc;
            case 0x136DE0u: goto label_136de0;
            case 0x136DE4u: goto label_136de4;
            case 0x136DE8u: goto label_136de8;
            case 0x136DECu: goto label_136dec;
            case 0x136DF0u: goto label_136df0;
            case 0x136DF4u: goto label_136df4;
            case 0x136DF8u: goto label_136df8;
            case 0x136DFCu: goto label_136dfc;
            case 0x136E00u: goto label_136e00;
            case 0x136E04u: goto label_136e04;
            case 0x136E08u: goto label_136e08;
            case 0x136E0Cu: goto label_136e0c;
            case 0x136E10u: goto label_136e10;
            case 0x136E14u: goto label_136e14;
            case 0x136E18u: goto label_136e18;
            case 0x136E1Cu: goto label_136e1c;
            case 0x136E20u: goto label_136e20;
            case 0x136E24u: goto label_136e24;
            case 0x136E28u: goto label_136e28;
            case 0x136E2Cu: goto label_136e2c;
            case 0x136E30u: goto label_136e30;
            case 0x136E34u: goto label_136e34;
            case 0x136E38u: goto label_136e38;
            case 0x136E3Cu: goto label_136e3c;
            case 0x136E40u: goto label_136e40;
            case 0x136E44u: goto label_136e44;
            case 0x136E48u: goto label_136e48;
            case 0x136E4Cu: goto label_136e4c;
            case 0x136E50u: goto label_136e50;
            case 0x136E54u: goto label_136e54;
            case 0x136E58u: goto label_136e58;
            case 0x136E5Cu: goto label_136e5c;
            case 0x136E60u: goto label_136e60;
            case 0x136E64u: goto label_136e64;
            case 0x136E68u: goto label_136e68;
            case 0x136E6Cu: goto label_136e6c;
            case 0x136E70u: goto label_136e70;
            case 0x136E74u: goto label_136e74;
            case 0x136E78u: goto label_136e78;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E80u: goto label_136e80;
            case 0x136E84u: goto label_136e84;
            case 0x136E88u: goto label_136e88;
            case 0x136E8Cu: goto label_136e8c;
            case 0x136E90u: goto label_136e90;
            case 0x136E94u: goto label_136e94;
            case 0x136E98u: goto label_136e98;
            case 0x136E9Cu: goto label_136e9c;
            case 0x136EA0u: goto label_136ea0;
            case 0x136EA4u: goto label_136ea4;
            case 0x136EA8u: goto label_136ea8;
            case 0x136EACu: goto label_136eac;
            case 0x136EB0u: goto label_136eb0;
            case 0x136EB4u: goto label_136eb4;
            case 0x136EB8u: goto label_136eb8;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EC0u: goto label_136ec0;
            case 0x136EC4u: goto label_136ec4;
            case 0x136EC8u: goto label_136ec8;
            case 0x136ECCu: goto label_136ecc;
            case 0x136ED0u: goto label_136ed0;
            case 0x136ED4u: goto label_136ed4;
            case 0x136ED8u: goto label_136ed8;
            case 0x136EDCu: goto label_136edc;
            case 0x136EE0u: goto label_136ee0;
            case 0x136EE4u: goto label_136ee4;
            case 0x136EE8u: goto label_136ee8;
            case 0x136EECu: goto label_136eec;
            case 0x136EF0u: goto label_136ef0;
            case 0x136EF4u: goto label_136ef4;
            case 0x136EF8u: goto label_136ef8;
            case 0x136EFCu: goto label_136efc;
            case 0x136F00u: goto label_136f00;
            case 0x136F04u: goto label_136f04;
            case 0x136F08u: goto label_136f08;
            case 0x136F0Cu: goto label_136f0c;
            case 0x136F10u: goto label_136f10;
            case 0x136F14u: goto label_136f14;
            case 0x136F18u: goto label_136f18;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F20u: goto label_136f20;
            case 0x136F24u: goto label_136f24;
            case 0x136F28u: goto label_136f28;
            case 0x136F2Cu: goto label_136f2c;
            case 0x136F30u: goto label_136f30;
            case 0x136F34u: goto label_136f34;
            case 0x136F38u: goto label_136f38;
            case 0x136F3Cu: goto label_136f3c;
            case 0x136F40u: goto label_136f40;
            case 0x136F44u: goto label_136f44;
            case 0x136F48u: goto label_136f48;
            case 0x136F4Cu: goto label_136f4c;
            case 0x136F50u: goto label_136f50;
            case 0x136F54u: goto label_136f54;
            case 0x136F58u: goto label_136f58;
            case 0x136F5Cu: goto label_136f5c;
            case 0x136F60u: goto label_136f60;
            case 0x136F64u: goto label_136f64;
            case 0x136F68u: goto label_136f68;
            case 0x136F6Cu: goto label_136f6c;
            case 0x136F70u: goto label_136f70;
            case 0x136F74u: goto label_136f74;
            case 0x136F78u: goto label_136f78;
            case 0x136F7Cu: goto label_136f7c;
            case 0x136F80u: goto label_136f80;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            case 0x136F8Cu: goto label_136f8c;
            case 0x136F90u: goto label_136f90;
            case 0x136F94u: goto label_136f94;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136D1Cu; }
            if (ctx->pc != 0x136D1Cu) { return; }
        }
    }
    ctx->pc = 0x136D1Cu;
label_136d1c:
    // 0x136d1c: 0x10000004
label_136d20:
    if (ctx->pc == 0x136D20u) {
        ctx->pc = 0x136D20u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->pc = 0x136D24u;
        goto label_136d24;
    }
    ctx->pc = 0x136D1Cu;
    {
        const bool branch_taken_0x136d1c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136D20u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        if (branch_taken_0x136d1c) {
            ctx->pc = 0x136D30u;
            goto label_136d30;
        }
    }
    ctx->pc = 0x136D24u;
label_136d24:
    // 0x136d24: 0x0
    ctx->pc = 0x136d24u;
    // NOP
label_136d28:
    // 0x136d28: 0x2402ffff
    ctx->pc = 0x136d28u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
label_136d2c:
    // 0x136d2c: 0xdfb00020
    ctx->pc = 0x136d2cu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_136d30:
    // 0x136d30: 0xdfb10028
    ctx->pc = 0x136d30u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
label_136d34:
    // 0x136d34: 0xdfb20030
    ctx->pc = 0x136d34u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_136d38:
    // 0x136d38: 0xdfb30038
    ctx->pc = 0x136d38u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 56)));
label_136d3c:
    // 0x136d3c: 0xdfbf0040
    ctx->pc = 0x136d3cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_136d40:
    // 0x136d40: 0x3e00008
label_136d44:
    if (ctx->pc == 0x136D44u) {
        ctx->pc = 0x136D44u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = 0x136D48u;
        goto label_136d48;
    }
    ctx->pc = 0x136D40u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136D44u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A80u: goto label_136a80;
            case 0x136A84u: goto label_136a84;
            case 0x136A88u: goto label_136a88;
            case 0x136A8Cu: goto label_136a8c;
            case 0x136A90u: goto label_136a90;
            case 0x136A94u: goto label_136a94;
            case 0x136A98u: goto label_136a98;
            case 0x136A9Cu: goto label_136a9c;
            case 0x136AA0u: goto label_136aa0;
            case 0x136AA4u: goto label_136aa4;
            case 0x136AA8u: goto label_136aa8;
            case 0x136AACu: goto label_136aac;
            case 0x136AB0u: goto label_136ab0;
            case 0x136AB4u: goto label_136ab4;
            case 0x136AB8u: goto label_136ab8;
            case 0x136ABCu: goto label_136abc;
            case 0x136AC0u: goto label_136ac0;
            case 0x136AC4u: goto label_136ac4;
            case 0x136AC8u: goto label_136ac8;
            case 0x136ACCu: goto label_136acc;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AD4u: goto label_136ad4;
            case 0x136AD8u: goto label_136ad8;
            case 0x136ADCu: goto label_136adc;
            case 0x136AE0u: goto label_136ae0;
            case 0x136AE4u: goto label_136ae4;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AECu: goto label_136aec;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF4u: goto label_136af4;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B00u: goto label_136b00;
            case 0x136B04u: goto label_136b04;
            case 0x136B08u: goto label_136b08;
            case 0x136B0Cu: goto label_136b0c;
            case 0x136B10u: goto label_136b10;
            case 0x136B14u: goto label_136b14;
            case 0x136B18u: goto label_136b18;
            case 0x136B1Cu: goto label_136b1c;
            case 0x136B20u: goto label_136b20;
            case 0x136B24u: goto label_136b24;
            case 0x136B28u: goto label_136b28;
            case 0x136B2Cu: goto label_136b2c;
            case 0x136B30u: goto label_136b30;
            case 0x136B34u: goto label_136b34;
            case 0x136B38u: goto label_136b38;
            case 0x136B3Cu: goto label_136b3c;
            case 0x136B40u: goto label_136b40;
            case 0x136B44u: goto label_136b44;
            case 0x136B48u: goto label_136b48;
            case 0x136B4Cu: goto label_136b4c;
            case 0x136B50u: goto label_136b50;
            case 0x136B54u: goto label_136b54;
            case 0x136B58u: goto label_136b58;
            case 0x136B5Cu: goto label_136b5c;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136B68u: goto label_136b68;
            case 0x136B6Cu: goto label_136b6c;
            case 0x136B70u: goto label_136b70;
            case 0x136B74u: goto label_136b74;
            case 0x136B78u: goto label_136b78;
            case 0x136B7Cu: goto label_136b7c;
            case 0x136B80u: goto label_136b80;
            case 0x136B84u: goto label_136b84;
            case 0x136B88u: goto label_136b88;
            case 0x136B8Cu: goto label_136b8c;
            case 0x136B90u: goto label_136b90;
            case 0x136B94u: goto label_136b94;
            case 0x136B98u: goto label_136b98;
            case 0x136B9Cu: goto label_136b9c;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BA4u: goto label_136ba4;
            case 0x136BA8u: goto label_136ba8;
            case 0x136BACu: goto label_136bac;
            case 0x136BB0u: goto label_136bb0;
            case 0x136BB4u: goto label_136bb4;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BBCu: goto label_136bbc;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BC4u: goto label_136bc4;
            case 0x136BC8u: goto label_136bc8;
            case 0x136BCCu: goto label_136bcc;
            case 0x136BD0u: goto label_136bd0;
            case 0x136BD4u: goto label_136bd4;
            case 0x136BD8u: goto label_136bd8;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE0u: goto label_136be0;
            case 0x136BE4u: goto label_136be4;
            case 0x136BE8u: goto label_136be8;
            case 0x136BECu: goto label_136bec;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF4u: goto label_136bf4;
            case 0x136BF8u: goto label_136bf8;
            case 0x136BFCu: goto label_136bfc;
            case 0x136C00u: goto label_136c00;
            case 0x136C04u: goto label_136c04;
            case 0x136C08u: goto label_136c08;
            case 0x136C0Cu: goto label_136c0c;
            case 0x136C10u: goto label_136c10;
            case 0x136C14u: goto label_136c14;
            case 0x136C18u: goto label_136c18;
            case 0x136C1Cu: goto label_136c1c;
            case 0x136C20u: goto label_136c20;
            case 0x136C24u: goto label_136c24;
            case 0x136C28u: goto label_136c28;
            case 0x136C2Cu: goto label_136c2c;
            case 0x136C30u: goto label_136c30;
            case 0x136C34u: goto label_136c34;
            case 0x136C38u: goto label_136c38;
            case 0x136C3Cu: goto label_136c3c;
            case 0x136C40u: goto label_136c40;
            case 0x136C44u: goto label_136c44;
            case 0x136C48u: goto label_136c48;
            case 0x136C4Cu: goto label_136c4c;
            case 0x136C50u: goto label_136c50;
            case 0x136C54u: goto label_136c54;
            case 0x136C58u: goto label_136c58;
            case 0x136C5Cu: goto label_136c5c;
            case 0x136C60u: goto label_136c60;
            case 0x136C64u: goto label_136c64;
            case 0x136C68u: goto label_136c68;
            case 0x136C6Cu: goto label_136c6c;
            case 0x136C70u: goto label_136c70;
            case 0x136C74u: goto label_136c74;
            case 0x136C78u: goto label_136c78;
            case 0x136C7Cu: goto label_136c7c;
            case 0x136C80u: goto label_136c80;
            case 0x136C84u: goto label_136c84;
            case 0x136C88u: goto label_136c88;
            case 0x136C8Cu: goto label_136c8c;
            case 0x136C90u: goto label_136c90;
            case 0x136C94u: goto label_136c94;
            case 0x136C98u: goto label_136c98;
            case 0x136C9Cu: goto label_136c9c;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CA4u: goto label_136ca4;
            case 0x136CA8u: goto label_136ca8;
            case 0x136CACu: goto label_136cac;
            case 0x136CB0u: goto label_136cb0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CB8u: goto label_136cb8;
            case 0x136CBCu: goto label_136cbc;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC4u: goto label_136cc4;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CCCu: goto label_136ccc;
            case 0x136CD0u: goto label_136cd0;
            case 0x136CD4u: goto label_136cd4;
            case 0x136CD8u: goto label_136cd8;
            case 0x136CDCu: goto label_136cdc;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE4u: goto label_136ce4;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CECu: goto label_136cec;
            case 0x136CF0u: goto label_136cf0;
            case 0x136CF4u: goto label_136cf4;
            case 0x136CF8u: goto label_136cf8;
            case 0x136CFCu: goto label_136cfc;
            case 0x136D00u: goto label_136d00;
            case 0x136D04u: goto label_136d04;
            case 0x136D08u: goto label_136d08;
            case 0x136D0Cu: goto label_136d0c;
            case 0x136D10u: goto label_136d10;
            case 0x136D14u: goto label_136d14;
            case 0x136D18u: goto label_136d18;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D20u: goto label_136d20;
            case 0x136D24u: goto label_136d24;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D34u: goto label_136d34;
            case 0x136D38u: goto label_136d38;
            case 0x136D3Cu: goto label_136d3c;
            case 0x136D40u: goto label_136d40;
            case 0x136D44u: goto label_136d44;
            case 0x136D48u: goto label_136d48;
            case 0x136D4Cu: goto label_136d4c;
            case 0x136D50u: goto label_136d50;
            case 0x136D54u: goto label_136d54;
            case 0x136D58u: goto label_136d58;
            case 0x136D5Cu: goto label_136d5c;
            case 0x136D60u: goto label_136d60;
            case 0x136D64u: goto label_136d64;
            case 0x136D68u: goto label_136d68;
            case 0x136D6Cu: goto label_136d6c;
            case 0x136D70u: goto label_136d70;
            case 0x136D74u: goto label_136d74;
            case 0x136D78u: goto label_136d78;
            case 0x136D7Cu: goto label_136d7c;
            case 0x136D80u: goto label_136d80;
            case 0x136D84u: goto label_136d84;
            case 0x136D88u: goto label_136d88;
            case 0x136D8Cu: goto label_136d8c;
            case 0x136D90u: goto label_136d90;
            case 0x136D94u: goto label_136d94;
            case 0x136D98u: goto label_136d98;
            case 0x136D9Cu: goto label_136d9c;
            case 0x136DA0u: goto label_136da0;
            case 0x136DA4u: goto label_136da4;
            case 0x136DA8u: goto label_136da8;
            case 0x136DACu: goto label_136dac;
            case 0x136DB0u: goto label_136db0;
            case 0x136DB4u: goto label_136db4;
            case 0x136DB8u: goto label_136db8;
            case 0x136DBCu: goto label_136dbc;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC4u: goto label_136dc4;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DCCu: goto label_136dcc;
            case 0x136DD0u: goto label_136dd0;
            case 0x136DD4u: goto label_136dd4;
            case 0x136DD8u: goto label_136dd8;
            case 0x136DDCu: goto label_136ddc;
            case 0x136DE0u: goto label_136de0;
            case 0x136DE4u: goto label_136de4;
            case 0x136DE8u: goto label_136de8;
            case 0x136DECu: goto label_136dec;
            case 0x136DF0u: goto label_136df0;
            case 0x136DF4u: goto label_136df4;
            case 0x136DF8u: goto label_136df8;
            case 0x136DFCu: goto label_136dfc;
            case 0x136E00u: goto label_136e00;
            case 0x136E04u: goto label_136e04;
            case 0x136E08u: goto label_136e08;
            case 0x136E0Cu: goto label_136e0c;
            case 0x136E10u: goto label_136e10;
            case 0x136E14u: goto label_136e14;
            case 0x136E18u: goto label_136e18;
            case 0x136E1Cu: goto label_136e1c;
            case 0x136E20u: goto label_136e20;
            case 0x136E24u: goto label_136e24;
            case 0x136E28u: goto label_136e28;
            case 0x136E2Cu: goto label_136e2c;
            case 0x136E30u: goto label_136e30;
            case 0x136E34u: goto label_136e34;
            case 0x136E38u: goto label_136e38;
            case 0x136E3Cu: goto label_136e3c;
            case 0x136E40u: goto label_136e40;
            case 0x136E44u: goto label_136e44;
            case 0x136E48u: goto label_136e48;
            case 0x136E4Cu: goto label_136e4c;
            case 0x136E50u: goto label_136e50;
            case 0x136E54u: goto label_136e54;
            case 0x136E58u: goto label_136e58;
            case 0x136E5Cu: goto label_136e5c;
            case 0x136E60u: goto label_136e60;
            case 0x136E64u: goto label_136e64;
            case 0x136E68u: goto label_136e68;
            case 0x136E6Cu: goto label_136e6c;
            case 0x136E70u: goto label_136e70;
            case 0x136E74u: goto label_136e74;
            case 0x136E78u: goto label_136e78;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E80u: goto label_136e80;
            case 0x136E84u: goto label_136e84;
            case 0x136E88u: goto label_136e88;
            case 0x136E8Cu: goto label_136e8c;
            case 0x136E90u: goto label_136e90;
            case 0x136E94u: goto label_136e94;
            case 0x136E98u: goto label_136e98;
            case 0x136E9Cu: goto label_136e9c;
            case 0x136EA0u: goto label_136ea0;
            case 0x136EA4u: goto label_136ea4;
            case 0x136EA8u: goto label_136ea8;
            case 0x136EACu: goto label_136eac;
            case 0x136EB0u: goto label_136eb0;
            case 0x136EB4u: goto label_136eb4;
            case 0x136EB8u: goto label_136eb8;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EC0u: goto label_136ec0;
            case 0x136EC4u: goto label_136ec4;
            case 0x136EC8u: goto label_136ec8;
            case 0x136ECCu: goto label_136ecc;
            case 0x136ED0u: goto label_136ed0;
            case 0x136ED4u: goto label_136ed4;
            case 0x136ED8u: goto label_136ed8;
            case 0x136EDCu: goto label_136edc;
            case 0x136EE0u: goto label_136ee0;
            case 0x136EE4u: goto label_136ee4;
            case 0x136EE8u: goto label_136ee8;
            case 0x136EECu: goto label_136eec;
            case 0x136EF0u: goto label_136ef0;
            case 0x136EF4u: goto label_136ef4;
            case 0x136EF8u: goto label_136ef8;
            case 0x136EFCu: goto label_136efc;
            case 0x136F00u: goto label_136f00;
            case 0x136F04u: goto label_136f04;
            case 0x136F08u: goto label_136f08;
            case 0x136F0Cu: goto label_136f0c;
            case 0x136F10u: goto label_136f10;
            case 0x136F14u: goto label_136f14;
            case 0x136F18u: goto label_136f18;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F20u: goto label_136f20;
            case 0x136F24u: goto label_136f24;
            case 0x136F28u: goto label_136f28;
            case 0x136F2Cu: goto label_136f2c;
            case 0x136F30u: goto label_136f30;
            case 0x136F34u: goto label_136f34;
            case 0x136F38u: goto label_136f38;
            case 0x136F3Cu: goto label_136f3c;
            case 0x136F40u: goto label_136f40;
            case 0x136F44u: goto label_136f44;
            case 0x136F48u: goto label_136f48;
            case 0x136F4Cu: goto label_136f4c;
            case 0x136F50u: goto label_136f50;
            case 0x136F54u: goto label_136f54;
            case 0x136F58u: goto label_136f58;
            case 0x136F5Cu: goto label_136f5c;
            case 0x136F60u: goto label_136f60;
            case 0x136F64u: goto label_136f64;
            case 0x136F68u: goto label_136f68;
            case 0x136F6Cu: goto label_136f6c;
            case 0x136F70u: goto label_136f70;
            case 0x136F74u: goto label_136f74;
            case 0x136F78u: goto label_136f78;
            case 0x136F7Cu: goto label_136f7c;
            case 0x136F80u: goto label_136f80;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            case 0x136F8Cu: goto label_136f8c;
            case 0x136F90u: goto label_136f90;
            case 0x136F94u: goto label_136f94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136D48u;
label_136d48:
    // 0x136d48: 0x27bdffc0
    ctx->pc = 0x136d48u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
label_136d4c:
    // 0x136d4c: 0xffb00020
    ctx->pc = 0x136d4cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
label_136d50:
    // 0x136d50: 0xa0802d
    ctx->pc = 0x136d50u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_136d54:
    // 0x136d54: 0xffb10028
    ctx->pc = 0x136d54u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
label_136d58:
    // 0x136d58: 0x14800005
label_136d5c:
    if (ctx->pc == 0x136D5Cu) {
        ctx->pc = 0x136D5Cu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        ctx->pc = 0x136D60u;
        goto label_136d60;
    }
    ctx->pc = 0x136D58u;
    {
        const bool branch_taken_0x136d58 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x136D5Cu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        if (branch_taken_0x136d58) {
            ctx->pc = 0x136D70u;
            goto label_136d70;
        }
    }
    ctx->pc = 0x136D60u;
label_136d60:
    // 0x136d60: 0x3c040024
    ctx->pc = 0x136d60u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_136d64:
    // 0x136d64: 0x10000011
label_136d68:
    if (ctx->pc == 0x136D68u) {
        ctx->pc = 0x136D68u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951520));
        ctx->pc = 0x136D6Cu;
        goto label_136d6c;
    }
    ctx->pc = 0x136D64u;
    {
        const bool branch_taken_0x136d64 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136D68u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951520));
        if (branch_taken_0x136d64) {
            ctx->pc = 0x136DACu;
            goto label_136dac;
        }
    }
    ctx->pc = 0x136D6Cu;
label_136d6c:
    // 0x136d6c: 0x0
    ctx->pc = 0x136d6cu;
    // NOP
label_136d70:
    // 0x136d70: 0x16000005
label_136d74:
    if (ctx->pc == 0x136D74u) {
        ctx->pc = 0x136D78u;
        goto label_136d78;
    }
    ctx->pc = 0x136D70u;
    {
        const bool branch_taken_0x136d70 = (GPR_U32(ctx, 16) != GPR_U32(ctx, 0));
        if (branch_taken_0x136d70) {
            ctx->pc = 0x136D88u;
            goto label_136d88;
        }
    }
    ctx->pc = 0x136D78u;
label_136d78:
    // 0x136d78: 0x3c040024
    ctx->pc = 0x136d78u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_136d7c:
    // 0x136d7c: 0x1000000b
label_136d80:
    if (ctx->pc == 0x136D80u) {
        ctx->pc = 0x136D80u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951560));
        ctx->pc = 0x136D84u;
        goto label_136d84;
    }
    ctx->pc = 0x136D7Cu;
    {
        const bool branch_taken_0x136d7c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136D80u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951560));
        if (branch_taken_0x136d7c) {
            ctx->pc = 0x136DACu;
            goto label_136dac;
        }
    }
    ctx->pc = 0x136D84u;
label_136d84:
    // 0x136d84: 0x0
    ctx->pc = 0x136d84u;
    // NOP
label_136d88:
    // 0x136d88: 0xc04d558
label_136d8c:
    if (ctx->pc == 0x136D8Cu) {
        ctx->pc = 0x136D90u;
        goto label_136d90;
    }
    ctx->pc = 0x136D88u;
    SET_GPR_U32(ctx, 31, 0x136D90u);
    ctx->pc = 0x135560u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136D90u; }
    }
    if (ctx->pc != 0x136D90u) { return; }
    ctx->pc = 0x136D90u;
label_136d90:
    // 0x136d90: 0x282d
    ctx->pc = 0x136d90u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_136d94:
    // 0x136d94: 0x40882d
    ctx->pc = 0x136d94u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_136d98:
    // 0x136d98: 0x3a0202d
    ctx->pc = 0x136d98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_136d9c:
    // 0x136d9c: 0x16200008
label_136da0:
    if (ctx->pc == 0x136DA0u) {
        ctx->pc = 0x136DA0u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 20));
        ctx->pc = 0x136DA4u;
        goto label_136da4;
    }
    ctx->pc = 0x136D9Cu;
    {
        const bool branch_taken_0x136d9c = (GPR_U32(ctx, 17) != GPR_U32(ctx, 0));
        ctx->pc = 0x136DA0u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 20));
        if (branch_taken_0x136d9c) {
            ctx->pc = 0x136DC0u;
            goto label_136dc0;
        }
    }
    ctx->pc = 0x136DA4u;
label_136da4:
    // 0x136da4: 0x3c040024
    ctx->pc = 0x136da4u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_136da8:
    // 0x136da8: 0x2484c2b0
    ctx->pc = 0x136da8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951600));
label_136dac:
    // 0x136dac: 0xc04d480
label_136db0:
    if (ctx->pc == 0x136DB0u) {
        ctx->pc = 0x136DB4u;
        goto label_136db4;
    }
    ctx->pc = 0x136DACu;
    SET_GPR_U32(ctx, 31, 0x136DB4u);
    ctx->pc = 0x135200u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136DB4u; }
    }
    if (ctx->pc != 0x136DB4u) { return; }
    ctx->pc = 0x136DB4u;
label_136db4:
    // 0x136db4: 0x1000000e
label_136db8:
    if (ctx->pc == 0x136DB8u) {
        ctx->pc = 0x136DB8u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = 0x136DBCu;
        goto label_136dbc;
    }
    ctx->pc = 0x136DB4u;
    {
        const bool branch_taken_0x136db4 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136DB8u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x136db4) {
            ctx->pc = 0x136DF0u;
            goto label_136df0;
        }
    }
    ctx->pc = 0x136DBCu;
label_136dbc:
    // 0x136dbc: 0x0
    ctx->pc = 0x136dbcu;
    // NOP
label_136dc0:
    // 0x136dc0: 0xc041f1a
label_136dc4:
    if (ctx->pc == 0x136DC4u) {
        ctx->pc = 0x136DC8u;
        goto label_136dc8;
    }
    ctx->pc = 0x136DC0u;
    SET_GPR_U32(ctx, 31, 0x136DC8u);
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136DC8u; }
    }
    if (ctx->pc != 0x136DC8u) { return; }
    ctx->pc = 0x136DC8u;
label_136dc8:
    // 0x136dc8: 0x2402ffff
    ctx->pc = 0x136dc8u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
label_136dcc:
    // 0x136dcc: 0xafb00004
    ctx->pc = 0x136dccu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 16));
label_136dd0:
    // 0x136dd0: 0x3a0202d
    ctx->pc = 0x136dd0u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_136dd4:
    // 0x136dd4: 0x24050003
    ctx->pc = 0x136dd4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 3));
label_136dd8:
    // 0x136dd8: 0x302d
    ctx->pc = 0x136dd8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_136ddc:
    // 0x136ddc: 0x8e230060
    ctx->pc = 0x136ddcu;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 96)));
label_136de0:
    // 0x136de0: 0x10600003
label_136de4:
    if (ctx->pc == 0x136DE4u) {
        ctx->pc = 0x136DE4u;
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x136DE8u;
        goto label_136de8;
    }
    ctx->pc = 0x136DE0u;
    {
        const bool branch_taken_0x136de0 = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x136DE4u;
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x136de0) {
            ctx->pc = 0x136DF0u;
            goto label_136df0;
        }
    }
    ctx->pc = 0x136DE8u;
label_136de8:
    // 0x136de8: 0x60f809
label_136dec:
    if (ctx->pc == 0x136DECu) {
        ctx->pc = 0x136DF0u;
        goto label_136df0;
    }
    ctx->pc = 0x136DE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x136DF0u);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A80u: goto label_136a80;
            case 0x136A84u: goto label_136a84;
            case 0x136A88u: goto label_136a88;
            case 0x136A8Cu: goto label_136a8c;
            case 0x136A90u: goto label_136a90;
            case 0x136A94u: goto label_136a94;
            case 0x136A98u: goto label_136a98;
            case 0x136A9Cu: goto label_136a9c;
            case 0x136AA0u: goto label_136aa0;
            case 0x136AA4u: goto label_136aa4;
            case 0x136AA8u: goto label_136aa8;
            case 0x136AACu: goto label_136aac;
            case 0x136AB0u: goto label_136ab0;
            case 0x136AB4u: goto label_136ab4;
            case 0x136AB8u: goto label_136ab8;
            case 0x136ABCu: goto label_136abc;
            case 0x136AC0u: goto label_136ac0;
            case 0x136AC4u: goto label_136ac4;
            case 0x136AC8u: goto label_136ac8;
            case 0x136ACCu: goto label_136acc;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AD4u: goto label_136ad4;
            case 0x136AD8u: goto label_136ad8;
            case 0x136ADCu: goto label_136adc;
            case 0x136AE0u: goto label_136ae0;
            case 0x136AE4u: goto label_136ae4;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AECu: goto label_136aec;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF4u: goto label_136af4;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B00u: goto label_136b00;
            case 0x136B04u: goto label_136b04;
            case 0x136B08u: goto label_136b08;
            case 0x136B0Cu: goto label_136b0c;
            case 0x136B10u: goto label_136b10;
            case 0x136B14u: goto label_136b14;
            case 0x136B18u: goto label_136b18;
            case 0x136B1Cu: goto label_136b1c;
            case 0x136B20u: goto label_136b20;
            case 0x136B24u: goto label_136b24;
            case 0x136B28u: goto label_136b28;
            case 0x136B2Cu: goto label_136b2c;
            case 0x136B30u: goto label_136b30;
            case 0x136B34u: goto label_136b34;
            case 0x136B38u: goto label_136b38;
            case 0x136B3Cu: goto label_136b3c;
            case 0x136B40u: goto label_136b40;
            case 0x136B44u: goto label_136b44;
            case 0x136B48u: goto label_136b48;
            case 0x136B4Cu: goto label_136b4c;
            case 0x136B50u: goto label_136b50;
            case 0x136B54u: goto label_136b54;
            case 0x136B58u: goto label_136b58;
            case 0x136B5Cu: goto label_136b5c;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136B68u: goto label_136b68;
            case 0x136B6Cu: goto label_136b6c;
            case 0x136B70u: goto label_136b70;
            case 0x136B74u: goto label_136b74;
            case 0x136B78u: goto label_136b78;
            case 0x136B7Cu: goto label_136b7c;
            case 0x136B80u: goto label_136b80;
            case 0x136B84u: goto label_136b84;
            case 0x136B88u: goto label_136b88;
            case 0x136B8Cu: goto label_136b8c;
            case 0x136B90u: goto label_136b90;
            case 0x136B94u: goto label_136b94;
            case 0x136B98u: goto label_136b98;
            case 0x136B9Cu: goto label_136b9c;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BA4u: goto label_136ba4;
            case 0x136BA8u: goto label_136ba8;
            case 0x136BACu: goto label_136bac;
            case 0x136BB0u: goto label_136bb0;
            case 0x136BB4u: goto label_136bb4;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BBCu: goto label_136bbc;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BC4u: goto label_136bc4;
            case 0x136BC8u: goto label_136bc8;
            case 0x136BCCu: goto label_136bcc;
            case 0x136BD0u: goto label_136bd0;
            case 0x136BD4u: goto label_136bd4;
            case 0x136BD8u: goto label_136bd8;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE0u: goto label_136be0;
            case 0x136BE4u: goto label_136be4;
            case 0x136BE8u: goto label_136be8;
            case 0x136BECu: goto label_136bec;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF4u: goto label_136bf4;
            case 0x136BF8u: goto label_136bf8;
            case 0x136BFCu: goto label_136bfc;
            case 0x136C00u: goto label_136c00;
            case 0x136C04u: goto label_136c04;
            case 0x136C08u: goto label_136c08;
            case 0x136C0Cu: goto label_136c0c;
            case 0x136C10u: goto label_136c10;
            case 0x136C14u: goto label_136c14;
            case 0x136C18u: goto label_136c18;
            case 0x136C1Cu: goto label_136c1c;
            case 0x136C20u: goto label_136c20;
            case 0x136C24u: goto label_136c24;
            case 0x136C28u: goto label_136c28;
            case 0x136C2Cu: goto label_136c2c;
            case 0x136C30u: goto label_136c30;
            case 0x136C34u: goto label_136c34;
            case 0x136C38u: goto label_136c38;
            case 0x136C3Cu: goto label_136c3c;
            case 0x136C40u: goto label_136c40;
            case 0x136C44u: goto label_136c44;
            case 0x136C48u: goto label_136c48;
            case 0x136C4Cu: goto label_136c4c;
            case 0x136C50u: goto label_136c50;
            case 0x136C54u: goto label_136c54;
            case 0x136C58u: goto label_136c58;
            case 0x136C5Cu: goto label_136c5c;
            case 0x136C60u: goto label_136c60;
            case 0x136C64u: goto label_136c64;
            case 0x136C68u: goto label_136c68;
            case 0x136C6Cu: goto label_136c6c;
            case 0x136C70u: goto label_136c70;
            case 0x136C74u: goto label_136c74;
            case 0x136C78u: goto label_136c78;
            case 0x136C7Cu: goto label_136c7c;
            case 0x136C80u: goto label_136c80;
            case 0x136C84u: goto label_136c84;
            case 0x136C88u: goto label_136c88;
            case 0x136C8Cu: goto label_136c8c;
            case 0x136C90u: goto label_136c90;
            case 0x136C94u: goto label_136c94;
            case 0x136C98u: goto label_136c98;
            case 0x136C9Cu: goto label_136c9c;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CA4u: goto label_136ca4;
            case 0x136CA8u: goto label_136ca8;
            case 0x136CACu: goto label_136cac;
            case 0x136CB0u: goto label_136cb0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CB8u: goto label_136cb8;
            case 0x136CBCu: goto label_136cbc;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC4u: goto label_136cc4;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CCCu: goto label_136ccc;
            case 0x136CD0u: goto label_136cd0;
            case 0x136CD4u: goto label_136cd4;
            case 0x136CD8u: goto label_136cd8;
            case 0x136CDCu: goto label_136cdc;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE4u: goto label_136ce4;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CECu: goto label_136cec;
            case 0x136CF0u: goto label_136cf0;
            case 0x136CF4u: goto label_136cf4;
            case 0x136CF8u: goto label_136cf8;
            case 0x136CFCu: goto label_136cfc;
            case 0x136D00u: goto label_136d00;
            case 0x136D04u: goto label_136d04;
            case 0x136D08u: goto label_136d08;
            case 0x136D0Cu: goto label_136d0c;
            case 0x136D10u: goto label_136d10;
            case 0x136D14u: goto label_136d14;
            case 0x136D18u: goto label_136d18;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D20u: goto label_136d20;
            case 0x136D24u: goto label_136d24;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D34u: goto label_136d34;
            case 0x136D38u: goto label_136d38;
            case 0x136D3Cu: goto label_136d3c;
            case 0x136D40u: goto label_136d40;
            case 0x136D44u: goto label_136d44;
            case 0x136D48u: goto label_136d48;
            case 0x136D4Cu: goto label_136d4c;
            case 0x136D50u: goto label_136d50;
            case 0x136D54u: goto label_136d54;
            case 0x136D58u: goto label_136d58;
            case 0x136D5Cu: goto label_136d5c;
            case 0x136D60u: goto label_136d60;
            case 0x136D64u: goto label_136d64;
            case 0x136D68u: goto label_136d68;
            case 0x136D6Cu: goto label_136d6c;
            case 0x136D70u: goto label_136d70;
            case 0x136D74u: goto label_136d74;
            case 0x136D78u: goto label_136d78;
            case 0x136D7Cu: goto label_136d7c;
            case 0x136D80u: goto label_136d80;
            case 0x136D84u: goto label_136d84;
            case 0x136D88u: goto label_136d88;
            case 0x136D8Cu: goto label_136d8c;
            case 0x136D90u: goto label_136d90;
            case 0x136D94u: goto label_136d94;
            case 0x136D98u: goto label_136d98;
            case 0x136D9Cu: goto label_136d9c;
            case 0x136DA0u: goto label_136da0;
            case 0x136DA4u: goto label_136da4;
            case 0x136DA8u: goto label_136da8;
            case 0x136DACu: goto label_136dac;
            case 0x136DB0u: goto label_136db0;
            case 0x136DB4u: goto label_136db4;
            case 0x136DB8u: goto label_136db8;
            case 0x136DBCu: goto label_136dbc;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC4u: goto label_136dc4;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DCCu: goto label_136dcc;
            case 0x136DD0u: goto label_136dd0;
            case 0x136DD4u: goto label_136dd4;
            case 0x136DD8u: goto label_136dd8;
            case 0x136DDCu: goto label_136ddc;
            case 0x136DE0u: goto label_136de0;
            case 0x136DE4u: goto label_136de4;
            case 0x136DE8u: goto label_136de8;
            case 0x136DECu: goto label_136dec;
            case 0x136DF0u: goto label_136df0;
            case 0x136DF4u: goto label_136df4;
            case 0x136DF8u: goto label_136df8;
            case 0x136DFCu: goto label_136dfc;
            case 0x136E00u: goto label_136e00;
            case 0x136E04u: goto label_136e04;
            case 0x136E08u: goto label_136e08;
            case 0x136E0Cu: goto label_136e0c;
            case 0x136E10u: goto label_136e10;
            case 0x136E14u: goto label_136e14;
            case 0x136E18u: goto label_136e18;
            case 0x136E1Cu: goto label_136e1c;
            case 0x136E20u: goto label_136e20;
            case 0x136E24u: goto label_136e24;
            case 0x136E28u: goto label_136e28;
            case 0x136E2Cu: goto label_136e2c;
            case 0x136E30u: goto label_136e30;
            case 0x136E34u: goto label_136e34;
            case 0x136E38u: goto label_136e38;
            case 0x136E3Cu: goto label_136e3c;
            case 0x136E40u: goto label_136e40;
            case 0x136E44u: goto label_136e44;
            case 0x136E48u: goto label_136e48;
            case 0x136E4Cu: goto label_136e4c;
            case 0x136E50u: goto label_136e50;
            case 0x136E54u: goto label_136e54;
            case 0x136E58u: goto label_136e58;
            case 0x136E5Cu: goto label_136e5c;
            case 0x136E60u: goto label_136e60;
            case 0x136E64u: goto label_136e64;
            case 0x136E68u: goto label_136e68;
            case 0x136E6Cu: goto label_136e6c;
            case 0x136E70u: goto label_136e70;
            case 0x136E74u: goto label_136e74;
            case 0x136E78u: goto label_136e78;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E80u: goto label_136e80;
            case 0x136E84u: goto label_136e84;
            case 0x136E88u: goto label_136e88;
            case 0x136E8Cu: goto label_136e8c;
            case 0x136E90u: goto label_136e90;
            case 0x136E94u: goto label_136e94;
            case 0x136E98u: goto label_136e98;
            case 0x136E9Cu: goto label_136e9c;
            case 0x136EA0u: goto label_136ea0;
            case 0x136EA4u: goto label_136ea4;
            case 0x136EA8u: goto label_136ea8;
            case 0x136EACu: goto label_136eac;
            case 0x136EB0u: goto label_136eb0;
            case 0x136EB4u: goto label_136eb4;
            case 0x136EB8u: goto label_136eb8;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EC0u: goto label_136ec0;
            case 0x136EC4u: goto label_136ec4;
            case 0x136EC8u: goto label_136ec8;
            case 0x136ECCu: goto label_136ecc;
            case 0x136ED0u: goto label_136ed0;
            case 0x136ED4u: goto label_136ed4;
            case 0x136ED8u: goto label_136ed8;
            case 0x136EDCu: goto label_136edc;
            case 0x136EE0u: goto label_136ee0;
            case 0x136EE4u: goto label_136ee4;
            case 0x136EE8u: goto label_136ee8;
            case 0x136EECu: goto label_136eec;
            case 0x136EF0u: goto label_136ef0;
            case 0x136EF4u: goto label_136ef4;
            case 0x136EF8u: goto label_136ef8;
            case 0x136EFCu: goto label_136efc;
            case 0x136F00u: goto label_136f00;
            case 0x136F04u: goto label_136f04;
            case 0x136F08u: goto label_136f08;
            case 0x136F0Cu: goto label_136f0c;
            case 0x136F10u: goto label_136f10;
            case 0x136F14u: goto label_136f14;
            case 0x136F18u: goto label_136f18;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F20u: goto label_136f20;
            case 0x136F24u: goto label_136f24;
            case 0x136F28u: goto label_136f28;
            case 0x136F2Cu: goto label_136f2c;
            case 0x136F30u: goto label_136f30;
            case 0x136F34u: goto label_136f34;
            case 0x136F38u: goto label_136f38;
            case 0x136F3Cu: goto label_136f3c;
            case 0x136F40u: goto label_136f40;
            case 0x136F44u: goto label_136f44;
            case 0x136F48u: goto label_136f48;
            case 0x136F4Cu: goto label_136f4c;
            case 0x136F50u: goto label_136f50;
            case 0x136F54u: goto label_136f54;
            case 0x136F58u: goto label_136f58;
            case 0x136F5Cu: goto label_136f5c;
            case 0x136F60u: goto label_136f60;
            case 0x136F64u: goto label_136f64;
            case 0x136F68u: goto label_136f68;
            case 0x136F6Cu: goto label_136f6c;
            case 0x136F70u: goto label_136f70;
            case 0x136F74u: goto label_136f74;
            case 0x136F78u: goto label_136f78;
            case 0x136F7Cu: goto label_136f7c;
            case 0x136F80u: goto label_136f80;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            case 0x136F8Cu: goto label_136f8c;
            case 0x136F90u: goto label_136f90;
            case 0x136F94u: goto label_136f94;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136DF0u; }
            if (ctx->pc != 0x136DF0u) { return; }
        }
    }
    ctx->pc = 0x136DF0u;
label_136df0:
    // 0x136df0: 0xdfb00020
    ctx->pc = 0x136df0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_136df4:
    // 0x136df4: 0xdfb10028
    ctx->pc = 0x136df4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
label_136df8:
    // 0x136df8: 0xdfbf0030
    ctx->pc = 0x136df8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_136dfc:
    // 0x136dfc: 0x3e00008
label_136e00:
    if (ctx->pc == 0x136E00u) {
        ctx->pc = 0x136E00u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = 0x136E04u;
        goto label_136e04;
    }
    ctx->pc = 0x136DFCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136E00u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A80u: goto label_136a80;
            case 0x136A84u: goto label_136a84;
            case 0x136A88u: goto label_136a88;
            case 0x136A8Cu: goto label_136a8c;
            case 0x136A90u: goto label_136a90;
            case 0x136A94u: goto label_136a94;
            case 0x136A98u: goto label_136a98;
            case 0x136A9Cu: goto label_136a9c;
            case 0x136AA0u: goto label_136aa0;
            case 0x136AA4u: goto label_136aa4;
            case 0x136AA8u: goto label_136aa8;
            case 0x136AACu: goto label_136aac;
            case 0x136AB0u: goto label_136ab0;
            case 0x136AB4u: goto label_136ab4;
            case 0x136AB8u: goto label_136ab8;
            case 0x136ABCu: goto label_136abc;
            case 0x136AC0u: goto label_136ac0;
            case 0x136AC4u: goto label_136ac4;
            case 0x136AC8u: goto label_136ac8;
            case 0x136ACCu: goto label_136acc;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AD4u: goto label_136ad4;
            case 0x136AD8u: goto label_136ad8;
            case 0x136ADCu: goto label_136adc;
            case 0x136AE0u: goto label_136ae0;
            case 0x136AE4u: goto label_136ae4;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AECu: goto label_136aec;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF4u: goto label_136af4;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B00u: goto label_136b00;
            case 0x136B04u: goto label_136b04;
            case 0x136B08u: goto label_136b08;
            case 0x136B0Cu: goto label_136b0c;
            case 0x136B10u: goto label_136b10;
            case 0x136B14u: goto label_136b14;
            case 0x136B18u: goto label_136b18;
            case 0x136B1Cu: goto label_136b1c;
            case 0x136B20u: goto label_136b20;
            case 0x136B24u: goto label_136b24;
            case 0x136B28u: goto label_136b28;
            case 0x136B2Cu: goto label_136b2c;
            case 0x136B30u: goto label_136b30;
            case 0x136B34u: goto label_136b34;
            case 0x136B38u: goto label_136b38;
            case 0x136B3Cu: goto label_136b3c;
            case 0x136B40u: goto label_136b40;
            case 0x136B44u: goto label_136b44;
            case 0x136B48u: goto label_136b48;
            case 0x136B4Cu: goto label_136b4c;
            case 0x136B50u: goto label_136b50;
            case 0x136B54u: goto label_136b54;
            case 0x136B58u: goto label_136b58;
            case 0x136B5Cu: goto label_136b5c;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136B68u: goto label_136b68;
            case 0x136B6Cu: goto label_136b6c;
            case 0x136B70u: goto label_136b70;
            case 0x136B74u: goto label_136b74;
            case 0x136B78u: goto label_136b78;
            case 0x136B7Cu: goto label_136b7c;
            case 0x136B80u: goto label_136b80;
            case 0x136B84u: goto label_136b84;
            case 0x136B88u: goto label_136b88;
            case 0x136B8Cu: goto label_136b8c;
            case 0x136B90u: goto label_136b90;
            case 0x136B94u: goto label_136b94;
            case 0x136B98u: goto label_136b98;
            case 0x136B9Cu: goto label_136b9c;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BA4u: goto label_136ba4;
            case 0x136BA8u: goto label_136ba8;
            case 0x136BACu: goto label_136bac;
            case 0x136BB0u: goto label_136bb0;
            case 0x136BB4u: goto label_136bb4;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BBCu: goto label_136bbc;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BC4u: goto label_136bc4;
            case 0x136BC8u: goto label_136bc8;
            case 0x136BCCu: goto label_136bcc;
            case 0x136BD0u: goto label_136bd0;
            case 0x136BD4u: goto label_136bd4;
            case 0x136BD8u: goto label_136bd8;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE0u: goto label_136be0;
            case 0x136BE4u: goto label_136be4;
            case 0x136BE8u: goto label_136be8;
            case 0x136BECu: goto label_136bec;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF4u: goto label_136bf4;
            case 0x136BF8u: goto label_136bf8;
            case 0x136BFCu: goto label_136bfc;
            case 0x136C00u: goto label_136c00;
            case 0x136C04u: goto label_136c04;
            case 0x136C08u: goto label_136c08;
            case 0x136C0Cu: goto label_136c0c;
            case 0x136C10u: goto label_136c10;
            case 0x136C14u: goto label_136c14;
            case 0x136C18u: goto label_136c18;
            case 0x136C1Cu: goto label_136c1c;
            case 0x136C20u: goto label_136c20;
            case 0x136C24u: goto label_136c24;
            case 0x136C28u: goto label_136c28;
            case 0x136C2Cu: goto label_136c2c;
            case 0x136C30u: goto label_136c30;
            case 0x136C34u: goto label_136c34;
            case 0x136C38u: goto label_136c38;
            case 0x136C3Cu: goto label_136c3c;
            case 0x136C40u: goto label_136c40;
            case 0x136C44u: goto label_136c44;
            case 0x136C48u: goto label_136c48;
            case 0x136C4Cu: goto label_136c4c;
            case 0x136C50u: goto label_136c50;
            case 0x136C54u: goto label_136c54;
            case 0x136C58u: goto label_136c58;
            case 0x136C5Cu: goto label_136c5c;
            case 0x136C60u: goto label_136c60;
            case 0x136C64u: goto label_136c64;
            case 0x136C68u: goto label_136c68;
            case 0x136C6Cu: goto label_136c6c;
            case 0x136C70u: goto label_136c70;
            case 0x136C74u: goto label_136c74;
            case 0x136C78u: goto label_136c78;
            case 0x136C7Cu: goto label_136c7c;
            case 0x136C80u: goto label_136c80;
            case 0x136C84u: goto label_136c84;
            case 0x136C88u: goto label_136c88;
            case 0x136C8Cu: goto label_136c8c;
            case 0x136C90u: goto label_136c90;
            case 0x136C94u: goto label_136c94;
            case 0x136C98u: goto label_136c98;
            case 0x136C9Cu: goto label_136c9c;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CA4u: goto label_136ca4;
            case 0x136CA8u: goto label_136ca8;
            case 0x136CACu: goto label_136cac;
            case 0x136CB0u: goto label_136cb0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CB8u: goto label_136cb8;
            case 0x136CBCu: goto label_136cbc;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC4u: goto label_136cc4;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CCCu: goto label_136ccc;
            case 0x136CD0u: goto label_136cd0;
            case 0x136CD4u: goto label_136cd4;
            case 0x136CD8u: goto label_136cd8;
            case 0x136CDCu: goto label_136cdc;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE4u: goto label_136ce4;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CECu: goto label_136cec;
            case 0x136CF0u: goto label_136cf0;
            case 0x136CF4u: goto label_136cf4;
            case 0x136CF8u: goto label_136cf8;
            case 0x136CFCu: goto label_136cfc;
            case 0x136D00u: goto label_136d00;
            case 0x136D04u: goto label_136d04;
            case 0x136D08u: goto label_136d08;
            case 0x136D0Cu: goto label_136d0c;
            case 0x136D10u: goto label_136d10;
            case 0x136D14u: goto label_136d14;
            case 0x136D18u: goto label_136d18;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D20u: goto label_136d20;
            case 0x136D24u: goto label_136d24;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D34u: goto label_136d34;
            case 0x136D38u: goto label_136d38;
            case 0x136D3Cu: goto label_136d3c;
            case 0x136D40u: goto label_136d40;
            case 0x136D44u: goto label_136d44;
            case 0x136D48u: goto label_136d48;
            case 0x136D4Cu: goto label_136d4c;
            case 0x136D50u: goto label_136d50;
            case 0x136D54u: goto label_136d54;
            case 0x136D58u: goto label_136d58;
            case 0x136D5Cu: goto label_136d5c;
            case 0x136D60u: goto label_136d60;
            case 0x136D64u: goto label_136d64;
            case 0x136D68u: goto label_136d68;
            case 0x136D6Cu: goto label_136d6c;
            case 0x136D70u: goto label_136d70;
            case 0x136D74u: goto label_136d74;
            case 0x136D78u: goto label_136d78;
            case 0x136D7Cu: goto label_136d7c;
            case 0x136D80u: goto label_136d80;
            case 0x136D84u: goto label_136d84;
            case 0x136D88u: goto label_136d88;
            case 0x136D8Cu: goto label_136d8c;
            case 0x136D90u: goto label_136d90;
            case 0x136D94u: goto label_136d94;
            case 0x136D98u: goto label_136d98;
            case 0x136D9Cu: goto label_136d9c;
            case 0x136DA0u: goto label_136da0;
            case 0x136DA4u: goto label_136da4;
            case 0x136DA8u: goto label_136da8;
            case 0x136DACu: goto label_136dac;
            case 0x136DB0u: goto label_136db0;
            case 0x136DB4u: goto label_136db4;
            case 0x136DB8u: goto label_136db8;
            case 0x136DBCu: goto label_136dbc;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC4u: goto label_136dc4;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DCCu: goto label_136dcc;
            case 0x136DD0u: goto label_136dd0;
            case 0x136DD4u: goto label_136dd4;
            case 0x136DD8u: goto label_136dd8;
            case 0x136DDCu: goto label_136ddc;
            case 0x136DE0u: goto label_136de0;
            case 0x136DE4u: goto label_136de4;
            case 0x136DE8u: goto label_136de8;
            case 0x136DECu: goto label_136dec;
            case 0x136DF0u: goto label_136df0;
            case 0x136DF4u: goto label_136df4;
            case 0x136DF8u: goto label_136df8;
            case 0x136DFCu: goto label_136dfc;
            case 0x136E00u: goto label_136e00;
            case 0x136E04u: goto label_136e04;
            case 0x136E08u: goto label_136e08;
            case 0x136E0Cu: goto label_136e0c;
            case 0x136E10u: goto label_136e10;
            case 0x136E14u: goto label_136e14;
            case 0x136E18u: goto label_136e18;
            case 0x136E1Cu: goto label_136e1c;
            case 0x136E20u: goto label_136e20;
            case 0x136E24u: goto label_136e24;
            case 0x136E28u: goto label_136e28;
            case 0x136E2Cu: goto label_136e2c;
            case 0x136E30u: goto label_136e30;
            case 0x136E34u: goto label_136e34;
            case 0x136E38u: goto label_136e38;
            case 0x136E3Cu: goto label_136e3c;
            case 0x136E40u: goto label_136e40;
            case 0x136E44u: goto label_136e44;
            case 0x136E48u: goto label_136e48;
            case 0x136E4Cu: goto label_136e4c;
            case 0x136E50u: goto label_136e50;
            case 0x136E54u: goto label_136e54;
            case 0x136E58u: goto label_136e58;
            case 0x136E5Cu: goto label_136e5c;
            case 0x136E60u: goto label_136e60;
            case 0x136E64u: goto label_136e64;
            case 0x136E68u: goto label_136e68;
            case 0x136E6Cu: goto label_136e6c;
            case 0x136E70u: goto label_136e70;
            case 0x136E74u: goto label_136e74;
            case 0x136E78u: goto label_136e78;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E80u: goto label_136e80;
            case 0x136E84u: goto label_136e84;
            case 0x136E88u: goto label_136e88;
            case 0x136E8Cu: goto label_136e8c;
            case 0x136E90u: goto label_136e90;
            case 0x136E94u: goto label_136e94;
            case 0x136E98u: goto label_136e98;
            case 0x136E9Cu: goto label_136e9c;
            case 0x136EA0u: goto label_136ea0;
            case 0x136EA4u: goto label_136ea4;
            case 0x136EA8u: goto label_136ea8;
            case 0x136EACu: goto label_136eac;
            case 0x136EB0u: goto label_136eb0;
            case 0x136EB4u: goto label_136eb4;
            case 0x136EB8u: goto label_136eb8;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EC0u: goto label_136ec0;
            case 0x136EC4u: goto label_136ec4;
            case 0x136EC8u: goto label_136ec8;
            case 0x136ECCu: goto label_136ecc;
            case 0x136ED0u: goto label_136ed0;
            case 0x136ED4u: goto label_136ed4;
            case 0x136ED8u: goto label_136ed8;
            case 0x136EDCu: goto label_136edc;
            case 0x136EE0u: goto label_136ee0;
            case 0x136EE4u: goto label_136ee4;
            case 0x136EE8u: goto label_136ee8;
            case 0x136EECu: goto label_136eec;
            case 0x136EF0u: goto label_136ef0;
            case 0x136EF4u: goto label_136ef4;
            case 0x136EF8u: goto label_136ef8;
            case 0x136EFCu: goto label_136efc;
            case 0x136F00u: goto label_136f00;
            case 0x136F04u: goto label_136f04;
            case 0x136F08u: goto label_136f08;
            case 0x136F0Cu: goto label_136f0c;
            case 0x136F10u: goto label_136f10;
            case 0x136F14u: goto label_136f14;
            case 0x136F18u: goto label_136f18;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F20u: goto label_136f20;
            case 0x136F24u: goto label_136f24;
            case 0x136F28u: goto label_136f28;
            case 0x136F2Cu: goto label_136f2c;
            case 0x136F30u: goto label_136f30;
            case 0x136F34u: goto label_136f34;
            case 0x136F38u: goto label_136f38;
            case 0x136F3Cu: goto label_136f3c;
            case 0x136F40u: goto label_136f40;
            case 0x136F44u: goto label_136f44;
            case 0x136F48u: goto label_136f48;
            case 0x136F4Cu: goto label_136f4c;
            case 0x136F50u: goto label_136f50;
            case 0x136F54u: goto label_136f54;
            case 0x136F58u: goto label_136f58;
            case 0x136F5Cu: goto label_136f5c;
            case 0x136F60u: goto label_136f60;
            case 0x136F64u: goto label_136f64;
            case 0x136F68u: goto label_136f68;
            case 0x136F6Cu: goto label_136f6c;
            case 0x136F70u: goto label_136f70;
            case 0x136F74u: goto label_136f74;
            case 0x136F78u: goto label_136f78;
            case 0x136F7Cu: goto label_136f7c;
            case 0x136F80u: goto label_136f80;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            case 0x136F8Cu: goto label_136f8c;
            case 0x136F90u: goto label_136f90;
            case 0x136F94u: goto label_136f94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136E04u;
label_136e04:
    // 0x136e04: 0x0
    ctx->pc = 0x136e04u;
    // NOP
label_136e08:
    // 0x136e08: 0x27bdffc0
    ctx->pc = 0x136e08u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
label_136e0c:
    // 0x136e0c: 0xffb00020
    ctx->pc = 0x136e0cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
label_136e10:
    // 0x136e10: 0xa0802d
    ctx->pc = 0x136e10u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_136e14:
    // 0x136e14: 0xffb20030
    ctx->pc = 0x136e14u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 18));
label_136e18:
    // 0x136e18: 0xc0902d
    ctx->pc = 0x136e18u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
label_136e1c:
    // 0x136e1c: 0xffb10028
    ctx->pc = 0x136e1cu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
label_136e20:
    // 0x136e20: 0x14800005
label_136e24:
    if (ctx->pc == 0x136E24u) {
        ctx->pc = 0x136E24u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
        ctx->pc = 0x136E28u;
        goto label_136e28;
    }
    ctx->pc = 0x136E20u;
    {
        const bool branch_taken_0x136e20 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x136E24u;
        WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 31));
        if (branch_taken_0x136e20) {
            ctx->pc = 0x136E38u;
            goto label_136e38;
        }
    }
    ctx->pc = 0x136E28u;
label_136e28:
    // 0x136e28: 0x3c040024
    ctx->pc = 0x136e28u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_136e2c:
    // 0x136e2c: 0x10000011
label_136e30:
    if (ctx->pc == 0x136E30u) {
        ctx->pc = 0x136E30u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951640));
        ctx->pc = 0x136E34u;
        goto label_136e34;
    }
    ctx->pc = 0x136E2Cu;
    {
        const bool branch_taken_0x136e2c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136E30u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951640));
        if (branch_taken_0x136e2c) {
            ctx->pc = 0x136E74u;
            goto label_136e74;
        }
    }
    ctx->pc = 0x136E34u;
label_136e34:
    // 0x136e34: 0x0
    ctx->pc = 0x136e34u;
    // NOP
label_136e38:
    // 0x136e38: 0x16000005
label_136e3c:
    if (ctx->pc == 0x136E3Cu) {
        ctx->pc = 0x136E40u;
        goto label_136e40;
    }
    ctx->pc = 0x136E38u;
    {
        const bool branch_taken_0x136e38 = (GPR_U32(ctx, 16) != GPR_U32(ctx, 0));
        if (branch_taken_0x136e38) {
            ctx->pc = 0x136E50u;
            goto label_136e50;
        }
    }
    ctx->pc = 0x136E40u;
label_136e40:
    // 0x136e40: 0x3c040024
    ctx->pc = 0x136e40u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_136e44:
    // 0x136e44: 0x1000000b
label_136e48:
    if (ctx->pc == 0x136E48u) {
        ctx->pc = 0x136E48u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951688));
        ctx->pc = 0x136E4Cu;
        goto label_136e4c;
    }
    ctx->pc = 0x136E44u;
    {
        const bool branch_taken_0x136e44 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136E48u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951688));
        if (branch_taken_0x136e44) {
            ctx->pc = 0x136E74u;
            goto label_136e74;
        }
    }
    ctx->pc = 0x136E4Cu;
label_136e4c:
    // 0x136e4c: 0x0
    ctx->pc = 0x136e4cu;
    // NOP
label_136e50:
    // 0x136e50: 0xc04d558
label_136e54:
    if (ctx->pc == 0x136E54u) {
        ctx->pc = 0x136E58u;
        goto label_136e58;
    }
    ctx->pc = 0x136E50u;
    SET_GPR_U32(ctx, 31, 0x136E58u);
    ctx->pc = 0x135560u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136E58u; }
    }
    if (ctx->pc != 0x136E58u) { return; }
    ctx->pc = 0x136E58u;
label_136e58:
    // 0x136e58: 0x282d
    ctx->pc = 0x136e58u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_136e5c:
    // 0x136e5c: 0x40882d
    ctx->pc = 0x136e5cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_136e60:
    // 0x136e60: 0x3a0202d
    ctx->pc = 0x136e60u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_136e64:
    // 0x136e64: 0x16200008
label_136e68:
    if (ctx->pc == 0x136E68u) {
        ctx->pc = 0x136E68u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 20));
        ctx->pc = 0x136E6Cu;
        goto label_136e6c;
    }
    ctx->pc = 0x136E64u;
    {
        const bool branch_taken_0x136e64 = (GPR_U32(ctx, 17) != GPR_U32(ctx, 0));
        ctx->pc = 0x136E68u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 20));
        if (branch_taken_0x136e64) {
            ctx->pc = 0x136E88u;
            goto label_136e88;
        }
    }
    ctx->pc = 0x136E6Cu;
label_136e6c:
    // 0x136e6c: 0x3c040024
    ctx->pc = 0x136e6cu;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_136e70:
    // 0x136e70: 0x2484c338
    ctx->pc = 0x136e70u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951736));
label_136e74:
    // 0x136e74: 0xc04d480
label_136e78:
    if (ctx->pc == 0x136E78u) {
        ctx->pc = 0x136E7Cu;
        goto label_136e7c;
    }
    ctx->pc = 0x136E74u;
    SET_GPR_U32(ctx, 31, 0x136E7Cu);
    ctx->pc = 0x135200u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136E7Cu; }
    }
    if (ctx->pc != 0x136E7Cu) { return; }
    ctx->pc = 0x136E7Cu;
label_136e7c:
    // 0x136e7c: 0x1000000f
label_136e80:
    if (ctx->pc == 0x136E80u) {
        ctx->pc = 0x136E80u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->pc = 0x136E84u;
        goto label_136e84;
    }
    ctx->pc = 0x136E7Cu;
    {
        const bool branch_taken_0x136e7c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136E80u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
        if (branch_taken_0x136e7c) {
            ctx->pc = 0x136EBCu;
            goto label_136ebc;
        }
    }
    ctx->pc = 0x136E84u;
label_136e84:
    // 0x136e84: 0x0
    ctx->pc = 0x136e84u;
    // NOP
label_136e88:
    // 0x136e88: 0xc041f1a
label_136e8c:
    if (ctx->pc == 0x136E8Cu) {
        ctx->pc = 0x136E90u;
        goto label_136e90;
    }
    ctx->pc = 0x136E88u;
    SET_GPR_U32(ctx, 31, 0x136E90u);
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136E90u; }
    }
    if (ctx->pc != 0x136E90u) { return; }
    ctx->pc = 0x136E90u;
label_136e90:
    // 0x136e90: 0x2402ffff
    ctx->pc = 0x136e90u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 4294967295));
label_136e94:
    // 0x136e94: 0xafb00004
    ctx->pc = 0x136e94u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 16));
label_136e98:
    // 0x136e98: 0x3a0202d
    ctx->pc = 0x136e98u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_136e9c:
    // 0x136e9c: 0xafb20008
    ctx->pc = 0x136e9cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 18));
label_136ea0:
    // 0x136ea0: 0x24050005
    ctx->pc = 0x136ea0u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 5));
label_136ea4:
    // 0x136ea4: 0x302d
    ctx->pc = 0x136ea4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_136ea8:
    // 0x136ea8: 0x8e230060
    ctx->pc = 0x136ea8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 17), 96)));
label_136eac:
    // 0x136eac: 0x10600003
label_136eb0:
    if (ctx->pc == 0x136EB0u) {
        ctx->pc = 0x136EB0u;
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x136EB4u;
        goto label_136eb4;
    }
    ctx->pc = 0x136EACu;
    {
        const bool branch_taken_0x136eac = (GPR_U32(ctx, 3) == GPR_U32(ctx, 0));
        ctx->pc = 0x136EB0u;
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x136eac) {
            ctx->pc = 0x136EBCu;
            goto label_136ebc;
        }
    }
    ctx->pc = 0x136EB4u;
label_136eb4:
    // 0x136eb4: 0x60f809
label_136eb8:
    if (ctx->pc == 0x136EB8u) {
        ctx->pc = 0x136EBCu;
        goto label_136ebc;
    }
    ctx->pc = 0x136EB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x136EBCu);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A80u: goto label_136a80;
            case 0x136A84u: goto label_136a84;
            case 0x136A88u: goto label_136a88;
            case 0x136A8Cu: goto label_136a8c;
            case 0x136A90u: goto label_136a90;
            case 0x136A94u: goto label_136a94;
            case 0x136A98u: goto label_136a98;
            case 0x136A9Cu: goto label_136a9c;
            case 0x136AA0u: goto label_136aa0;
            case 0x136AA4u: goto label_136aa4;
            case 0x136AA8u: goto label_136aa8;
            case 0x136AACu: goto label_136aac;
            case 0x136AB0u: goto label_136ab0;
            case 0x136AB4u: goto label_136ab4;
            case 0x136AB8u: goto label_136ab8;
            case 0x136ABCu: goto label_136abc;
            case 0x136AC0u: goto label_136ac0;
            case 0x136AC4u: goto label_136ac4;
            case 0x136AC8u: goto label_136ac8;
            case 0x136ACCu: goto label_136acc;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AD4u: goto label_136ad4;
            case 0x136AD8u: goto label_136ad8;
            case 0x136ADCu: goto label_136adc;
            case 0x136AE0u: goto label_136ae0;
            case 0x136AE4u: goto label_136ae4;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AECu: goto label_136aec;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF4u: goto label_136af4;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B00u: goto label_136b00;
            case 0x136B04u: goto label_136b04;
            case 0x136B08u: goto label_136b08;
            case 0x136B0Cu: goto label_136b0c;
            case 0x136B10u: goto label_136b10;
            case 0x136B14u: goto label_136b14;
            case 0x136B18u: goto label_136b18;
            case 0x136B1Cu: goto label_136b1c;
            case 0x136B20u: goto label_136b20;
            case 0x136B24u: goto label_136b24;
            case 0x136B28u: goto label_136b28;
            case 0x136B2Cu: goto label_136b2c;
            case 0x136B30u: goto label_136b30;
            case 0x136B34u: goto label_136b34;
            case 0x136B38u: goto label_136b38;
            case 0x136B3Cu: goto label_136b3c;
            case 0x136B40u: goto label_136b40;
            case 0x136B44u: goto label_136b44;
            case 0x136B48u: goto label_136b48;
            case 0x136B4Cu: goto label_136b4c;
            case 0x136B50u: goto label_136b50;
            case 0x136B54u: goto label_136b54;
            case 0x136B58u: goto label_136b58;
            case 0x136B5Cu: goto label_136b5c;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136B68u: goto label_136b68;
            case 0x136B6Cu: goto label_136b6c;
            case 0x136B70u: goto label_136b70;
            case 0x136B74u: goto label_136b74;
            case 0x136B78u: goto label_136b78;
            case 0x136B7Cu: goto label_136b7c;
            case 0x136B80u: goto label_136b80;
            case 0x136B84u: goto label_136b84;
            case 0x136B88u: goto label_136b88;
            case 0x136B8Cu: goto label_136b8c;
            case 0x136B90u: goto label_136b90;
            case 0x136B94u: goto label_136b94;
            case 0x136B98u: goto label_136b98;
            case 0x136B9Cu: goto label_136b9c;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BA4u: goto label_136ba4;
            case 0x136BA8u: goto label_136ba8;
            case 0x136BACu: goto label_136bac;
            case 0x136BB0u: goto label_136bb0;
            case 0x136BB4u: goto label_136bb4;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BBCu: goto label_136bbc;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BC4u: goto label_136bc4;
            case 0x136BC8u: goto label_136bc8;
            case 0x136BCCu: goto label_136bcc;
            case 0x136BD0u: goto label_136bd0;
            case 0x136BD4u: goto label_136bd4;
            case 0x136BD8u: goto label_136bd8;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE0u: goto label_136be0;
            case 0x136BE4u: goto label_136be4;
            case 0x136BE8u: goto label_136be8;
            case 0x136BECu: goto label_136bec;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF4u: goto label_136bf4;
            case 0x136BF8u: goto label_136bf8;
            case 0x136BFCu: goto label_136bfc;
            case 0x136C00u: goto label_136c00;
            case 0x136C04u: goto label_136c04;
            case 0x136C08u: goto label_136c08;
            case 0x136C0Cu: goto label_136c0c;
            case 0x136C10u: goto label_136c10;
            case 0x136C14u: goto label_136c14;
            case 0x136C18u: goto label_136c18;
            case 0x136C1Cu: goto label_136c1c;
            case 0x136C20u: goto label_136c20;
            case 0x136C24u: goto label_136c24;
            case 0x136C28u: goto label_136c28;
            case 0x136C2Cu: goto label_136c2c;
            case 0x136C30u: goto label_136c30;
            case 0x136C34u: goto label_136c34;
            case 0x136C38u: goto label_136c38;
            case 0x136C3Cu: goto label_136c3c;
            case 0x136C40u: goto label_136c40;
            case 0x136C44u: goto label_136c44;
            case 0x136C48u: goto label_136c48;
            case 0x136C4Cu: goto label_136c4c;
            case 0x136C50u: goto label_136c50;
            case 0x136C54u: goto label_136c54;
            case 0x136C58u: goto label_136c58;
            case 0x136C5Cu: goto label_136c5c;
            case 0x136C60u: goto label_136c60;
            case 0x136C64u: goto label_136c64;
            case 0x136C68u: goto label_136c68;
            case 0x136C6Cu: goto label_136c6c;
            case 0x136C70u: goto label_136c70;
            case 0x136C74u: goto label_136c74;
            case 0x136C78u: goto label_136c78;
            case 0x136C7Cu: goto label_136c7c;
            case 0x136C80u: goto label_136c80;
            case 0x136C84u: goto label_136c84;
            case 0x136C88u: goto label_136c88;
            case 0x136C8Cu: goto label_136c8c;
            case 0x136C90u: goto label_136c90;
            case 0x136C94u: goto label_136c94;
            case 0x136C98u: goto label_136c98;
            case 0x136C9Cu: goto label_136c9c;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CA4u: goto label_136ca4;
            case 0x136CA8u: goto label_136ca8;
            case 0x136CACu: goto label_136cac;
            case 0x136CB0u: goto label_136cb0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CB8u: goto label_136cb8;
            case 0x136CBCu: goto label_136cbc;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC4u: goto label_136cc4;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CCCu: goto label_136ccc;
            case 0x136CD0u: goto label_136cd0;
            case 0x136CD4u: goto label_136cd4;
            case 0x136CD8u: goto label_136cd8;
            case 0x136CDCu: goto label_136cdc;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE4u: goto label_136ce4;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CECu: goto label_136cec;
            case 0x136CF0u: goto label_136cf0;
            case 0x136CF4u: goto label_136cf4;
            case 0x136CF8u: goto label_136cf8;
            case 0x136CFCu: goto label_136cfc;
            case 0x136D00u: goto label_136d00;
            case 0x136D04u: goto label_136d04;
            case 0x136D08u: goto label_136d08;
            case 0x136D0Cu: goto label_136d0c;
            case 0x136D10u: goto label_136d10;
            case 0x136D14u: goto label_136d14;
            case 0x136D18u: goto label_136d18;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D20u: goto label_136d20;
            case 0x136D24u: goto label_136d24;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D34u: goto label_136d34;
            case 0x136D38u: goto label_136d38;
            case 0x136D3Cu: goto label_136d3c;
            case 0x136D40u: goto label_136d40;
            case 0x136D44u: goto label_136d44;
            case 0x136D48u: goto label_136d48;
            case 0x136D4Cu: goto label_136d4c;
            case 0x136D50u: goto label_136d50;
            case 0x136D54u: goto label_136d54;
            case 0x136D58u: goto label_136d58;
            case 0x136D5Cu: goto label_136d5c;
            case 0x136D60u: goto label_136d60;
            case 0x136D64u: goto label_136d64;
            case 0x136D68u: goto label_136d68;
            case 0x136D6Cu: goto label_136d6c;
            case 0x136D70u: goto label_136d70;
            case 0x136D74u: goto label_136d74;
            case 0x136D78u: goto label_136d78;
            case 0x136D7Cu: goto label_136d7c;
            case 0x136D80u: goto label_136d80;
            case 0x136D84u: goto label_136d84;
            case 0x136D88u: goto label_136d88;
            case 0x136D8Cu: goto label_136d8c;
            case 0x136D90u: goto label_136d90;
            case 0x136D94u: goto label_136d94;
            case 0x136D98u: goto label_136d98;
            case 0x136D9Cu: goto label_136d9c;
            case 0x136DA0u: goto label_136da0;
            case 0x136DA4u: goto label_136da4;
            case 0x136DA8u: goto label_136da8;
            case 0x136DACu: goto label_136dac;
            case 0x136DB0u: goto label_136db0;
            case 0x136DB4u: goto label_136db4;
            case 0x136DB8u: goto label_136db8;
            case 0x136DBCu: goto label_136dbc;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC4u: goto label_136dc4;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DCCu: goto label_136dcc;
            case 0x136DD0u: goto label_136dd0;
            case 0x136DD4u: goto label_136dd4;
            case 0x136DD8u: goto label_136dd8;
            case 0x136DDCu: goto label_136ddc;
            case 0x136DE0u: goto label_136de0;
            case 0x136DE4u: goto label_136de4;
            case 0x136DE8u: goto label_136de8;
            case 0x136DECu: goto label_136dec;
            case 0x136DF0u: goto label_136df0;
            case 0x136DF4u: goto label_136df4;
            case 0x136DF8u: goto label_136df8;
            case 0x136DFCu: goto label_136dfc;
            case 0x136E00u: goto label_136e00;
            case 0x136E04u: goto label_136e04;
            case 0x136E08u: goto label_136e08;
            case 0x136E0Cu: goto label_136e0c;
            case 0x136E10u: goto label_136e10;
            case 0x136E14u: goto label_136e14;
            case 0x136E18u: goto label_136e18;
            case 0x136E1Cu: goto label_136e1c;
            case 0x136E20u: goto label_136e20;
            case 0x136E24u: goto label_136e24;
            case 0x136E28u: goto label_136e28;
            case 0x136E2Cu: goto label_136e2c;
            case 0x136E30u: goto label_136e30;
            case 0x136E34u: goto label_136e34;
            case 0x136E38u: goto label_136e38;
            case 0x136E3Cu: goto label_136e3c;
            case 0x136E40u: goto label_136e40;
            case 0x136E44u: goto label_136e44;
            case 0x136E48u: goto label_136e48;
            case 0x136E4Cu: goto label_136e4c;
            case 0x136E50u: goto label_136e50;
            case 0x136E54u: goto label_136e54;
            case 0x136E58u: goto label_136e58;
            case 0x136E5Cu: goto label_136e5c;
            case 0x136E60u: goto label_136e60;
            case 0x136E64u: goto label_136e64;
            case 0x136E68u: goto label_136e68;
            case 0x136E6Cu: goto label_136e6c;
            case 0x136E70u: goto label_136e70;
            case 0x136E74u: goto label_136e74;
            case 0x136E78u: goto label_136e78;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E80u: goto label_136e80;
            case 0x136E84u: goto label_136e84;
            case 0x136E88u: goto label_136e88;
            case 0x136E8Cu: goto label_136e8c;
            case 0x136E90u: goto label_136e90;
            case 0x136E94u: goto label_136e94;
            case 0x136E98u: goto label_136e98;
            case 0x136E9Cu: goto label_136e9c;
            case 0x136EA0u: goto label_136ea0;
            case 0x136EA4u: goto label_136ea4;
            case 0x136EA8u: goto label_136ea8;
            case 0x136EACu: goto label_136eac;
            case 0x136EB0u: goto label_136eb0;
            case 0x136EB4u: goto label_136eb4;
            case 0x136EB8u: goto label_136eb8;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EC0u: goto label_136ec0;
            case 0x136EC4u: goto label_136ec4;
            case 0x136EC8u: goto label_136ec8;
            case 0x136ECCu: goto label_136ecc;
            case 0x136ED0u: goto label_136ed0;
            case 0x136ED4u: goto label_136ed4;
            case 0x136ED8u: goto label_136ed8;
            case 0x136EDCu: goto label_136edc;
            case 0x136EE0u: goto label_136ee0;
            case 0x136EE4u: goto label_136ee4;
            case 0x136EE8u: goto label_136ee8;
            case 0x136EECu: goto label_136eec;
            case 0x136EF0u: goto label_136ef0;
            case 0x136EF4u: goto label_136ef4;
            case 0x136EF8u: goto label_136ef8;
            case 0x136EFCu: goto label_136efc;
            case 0x136F00u: goto label_136f00;
            case 0x136F04u: goto label_136f04;
            case 0x136F08u: goto label_136f08;
            case 0x136F0Cu: goto label_136f0c;
            case 0x136F10u: goto label_136f10;
            case 0x136F14u: goto label_136f14;
            case 0x136F18u: goto label_136f18;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F20u: goto label_136f20;
            case 0x136F24u: goto label_136f24;
            case 0x136F28u: goto label_136f28;
            case 0x136F2Cu: goto label_136f2c;
            case 0x136F30u: goto label_136f30;
            case 0x136F34u: goto label_136f34;
            case 0x136F38u: goto label_136f38;
            case 0x136F3Cu: goto label_136f3c;
            case 0x136F40u: goto label_136f40;
            case 0x136F44u: goto label_136f44;
            case 0x136F48u: goto label_136f48;
            case 0x136F4Cu: goto label_136f4c;
            case 0x136F50u: goto label_136f50;
            case 0x136F54u: goto label_136f54;
            case 0x136F58u: goto label_136f58;
            case 0x136F5Cu: goto label_136f5c;
            case 0x136F60u: goto label_136f60;
            case 0x136F64u: goto label_136f64;
            case 0x136F68u: goto label_136f68;
            case 0x136F6Cu: goto label_136f6c;
            case 0x136F70u: goto label_136f70;
            case 0x136F74u: goto label_136f74;
            case 0x136F78u: goto label_136f78;
            case 0x136F7Cu: goto label_136f7c;
            case 0x136F80u: goto label_136f80;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            case 0x136F8Cu: goto label_136f8c;
            case 0x136F90u: goto label_136f90;
            case 0x136F94u: goto label_136f94;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136EBCu; }
            if (ctx->pc != 0x136EBCu) { return; }
        }
    }
    ctx->pc = 0x136EBCu;
label_136ebc:
    // 0x136ebc: 0xdfb00020
    ctx->pc = 0x136ebcu;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_136ec0:
    // 0x136ec0: 0xdfb10028
    ctx->pc = 0x136ec0u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
label_136ec4:
    // 0x136ec4: 0xdfb20030
    ctx->pc = 0x136ec4u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_136ec8:
    // 0x136ec8: 0xdfbf0038
    ctx->pc = 0x136ec8u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 56)));
label_136ecc:
    // 0x136ecc: 0x3e00008
label_136ed0:
    if (ctx->pc == 0x136ED0u) {
        ctx->pc = 0x136ED0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = 0x136ED4u;
        goto label_136ed4;
    }
    ctx->pc = 0x136ECCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136ED0u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A80u: goto label_136a80;
            case 0x136A84u: goto label_136a84;
            case 0x136A88u: goto label_136a88;
            case 0x136A8Cu: goto label_136a8c;
            case 0x136A90u: goto label_136a90;
            case 0x136A94u: goto label_136a94;
            case 0x136A98u: goto label_136a98;
            case 0x136A9Cu: goto label_136a9c;
            case 0x136AA0u: goto label_136aa0;
            case 0x136AA4u: goto label_136aa4;
            case 0x136AA8u: goto label_136aa8;
            case 0x136AACu: goto label_136aac;
            case 0x136AB0u: goto label_136ab0;
            case 0x136AB4u: goto label_136ab4;
            case 0x136AB8u: goto label_136ab8;
            case 0x136ABCu: goto label_136abc;
            case 0x136AC0u: goto label_136ac0;
            case 0x136AC4u: goto label_136ac4;
            case 0x136AC8u: goto label_136ac8;
            case 0x136ACCu: goto label_136acc;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AD4u: goto label_136ad4;
            case 0x136AD8u: goto label_136ad8;
            case 0x136ADCu: goto label_136adc;
            case 0x136AE0u: goto label_136ae0;
            case 0x136AE4u: goto label_136ae4;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AECu: goto label_136aec;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF4u: goto label_136af4;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B00u: goto label_136b00;
            case 0x136B04u: goto label_136b04;
            case 0x136B08u: goto label_136b08;
            case 0x136B0Cu: goto label_136b0c;
            case 0x136B10u: goto label_136b10;
            case 0x136B14u: goto label_136b14;
            case 0x136B18u: goto label_136b18;
            case 0x136B1Cu: goto label_136b1c;
            case 0x136B20u: goto label_136b20;
            case 0x136B24u: goto label_136b24;
            case 0x136B28u: goto label_136b28;
            case 0x136B2Cu: goto label_136b2c;
            case 0x136B30u: goto label_136b30;
            case 0x136B34u: goto label_136b34;
            case 0x136B38u: goto label_136b38;
            case 0x136B3Cu: goto label_136b3c;
            case 0x136B40u: goto label_136b40;
            case 0x136B44u: goto label_136b44;
            case 0x136B48u: goto label_136b48;
            case 0x136B4Cu: goto label_136b4c;
            case 0x136B50u: goto label_136b50;
            case 0x136B54u: goto label_136b54;
            case 0x136B58u: goto label_136b58;
            case 0x136B5Cu: goto label_136b5c;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136B68u: goto label_136b68;
            case 0x136B6Cu: goto label_136b6c;
            case 0x136B70u: goto label_136b70;
            case 0x136B74u: goto label_136b74;
            case 0x136B78u: goto label_136b78;
            case 0x136B7Cu: goto label_136b7c;
            case 0x136B80u: goto label_136b80;
            case 0x136B84u: goto label_136b84;
            case 0x136B88u: goto label_136b88;
            case 0x136B8Cu: goto label_136b8c;
            case 0x136B90u: goto label_136b90;
            case 0x136B94u: goto label_136b94;
            case 0x136B98u: goto label_136b98;
            case 0x136B9Cu: goto label_136b9c;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BA4u: goto label_136ba4;
            case 0x136BA8u: goto label_136ba8;
            case 0x136BACu: goto label_136bac;
            case 0x136BB0u: goto label_136bb0;
            case 0x136BB4u: goto label_136bb4;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BBCu: goto label_136bbc;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BC4u: goto label_136bc4;
            case 0x136BC8u: goto label_136bc8;
            case 0x136BCCu: goto label_136bcc;
            case 0x136BD0u: goto label_136bd0;
            case 0x136BD4u: goto label_136bd4;
            case 0x136BD8u: goto label_136bd8;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE0u: goto label_136be0;
            case 0x136BE4u: goto label_136be4;
            case 0x136BE8u: goto label_136be8;
            case 0x136BECu: goto label_136bec;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF4u: goto label_136bf4;
            case 0x136BF8u: goto label_136bf8;
            case 0x136BFCu: goto label_136bfc;
            case 0x136C00u: goto label_136c00;
            case 0x136C04u: goto label_136c04;
            case 0x136C08u: goto label_136c08;
            case 0x136C0Cu: goto label_136c0c;
            case 0x136C10u: goto label_136c10;
            case 0x136C14u: goto label_136c14;
            case 0x136C18u: goto label_136c18;
            case 0x136C1Cu: goto label_136c1c;
            case 0x136C20u: goto label_136c20;
            case 0x136C24u: goto label_136c24;
            case 0x136C28u: goto label_136c28;
            case 0x136C2Cu: goto label_136c2c;
            case 0x136C30u: goto label_136c30;
            case 0x136C34u: goto label_136c34;
            case 0x136C38u: goto label_136c38;
            case 0x136C3Cu: goto label_136c3c;
            case 0x136C40u: goto label_136c40;
            case 0x136C44u: goto label_136c44;
            case 0x136C48u: goto label_136c48;
            case 0x136C4Cu: goto label_136c4c;
            case 0x136C50u: goto label_136c50;
            case 0x136C54u: goto label_136c54;
            case 0x136C58u: goto label_136c58;
            case 0x136C5Cu: goto label_136c5c;
            case 0x136C60u: goto label_136c60;
            case 0x136C64u: goto label_136c64;
            case 0x136C68u: goto label_136c68;
            case 0x136C6Cu: goto label_136c6c;
            case 0x136C70u: goto label_136c70;
            case 0x136C74u: goto label_136c74;
            case 0x136C78u: goto label_136c78;
            case 0x136C7Cu: goto label_136c7c;
            case 0x136C80u: goto label_136c80;
            case 0x136C84u: goto label_136c84;
            case 0x136C88u: goto label_136c88;
            case 0x136C8Cu: goto label_136c8c;
            case 0x136C90u: goto label_136c90;
            case 0x136C94u: goto label_136c94;
            case 0x136C98u: goto label_136c98;
            case 0x136C9Cu: goto label_136c9c;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CA4u: goto label_136ca4;
            case 0x136CA8u: goto label_136ca8;
            case 0x136CACu: goto label_136cac;
            case 0x136CB0u: goto label_136cb0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CB8u: goto label_136cb8;
            case 0x136CBCu: goto label_136cbc;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC4u: goto label_136cc4;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CCCu: goto label_136ccc;
            case 0x136CD0u: goto label_136cd0;
            case 0x136CD4u: goto label_136cd4;
            case 0x136CD8u: goto label_136cd8;
            case 0x136CDCu: goto label_136cdc;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE4u: goto label_136ce4;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CECu: goto label_136cec;
            case 0x136CF0u: goto label_136cf0;
            case 0x136CF4u: goto label_136cf4;
            case 0x136CF8u: goto label_136cf8;
            case 0x136CFCu: goto label_136cfc;
            case 0x136D00u: goto label_136d00;
            case 0x136D04u: goto label_136d04;
            case 0x136D08u: goto label_136d08;
            case 0x136D0Cu: goto label_136d0c;
            case 0x136D10u: goto label_136d10;
            case 0x136D14u: goto label_136d14;
            case 0x136D18u: goto label_136d18;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D20u: goto label_136d20;
            case 0x136D24u: goto label_136d24;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D34u: goto label_136d34;
            case 0x136D38u: goto label_136d38;
            case 0x136D3Cu: goto label_136d3c;
            case 0x136D40u: goto label_136d40;
            case 0x136D44u: goto label_136d44;
            case 0x136D48u: goto label_136d48;
            case 0x136D4Cu: goto label_136d4c;
            case 0x136D50u: goto label_136d50;
            case 0x136D54u: goto label_136d54;
            case 0x136D58u: goto label_136d58;
            case 0x136D5Cu: goto label_136d5c;
            case 0x136D60u: goto label_136d60;
            case 0x136D64u: goto label_136d64;
            case 0x136D68u: goto label_136d68;
            case 0x136D6Cu: goto label_136d6c;
            case 0x136D70u: goto label_136d70;
            case 0x136D74u: goto label_136d74;
            case 0x136D78u: goto label_136d78;
            case 0x136D7Cu: goto label_136d7c;
            case 0x136D80u: goto label_136d80;
            case 0x136D84u: goto label_136d84;
            case 0x136D88u: goto label_136d88;
            case 0x136D8Cu: goto label_136d8c;
            case 0x136D90u: goto label_136d90;
            case 0x136D94u: goto label_136d94;
            case 0x136D98u: goto label_136d98;
            case 0x136D9Cu: goto label_136d9c;
            case 0x136DA0u: goto label_136da0;
            case 0x136DA4u: goto label_136da4;
            case 0x136DA8u: goto label_136da8;
            case 0x136DACu: goto label_136dac;
            case 0x136DB0u: goto label_136db0;
            case 0x136DB4u: goto label_136db4;
            case 0x136DB8u: goto label_136db8;
            case 0x136DBCu: goto label_136dbc;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC4u: goto label_136dc4;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DCCu: goto label_136dcc;
            case 0x136DD0u: goto label_136dd0;
            case 0x136DD4u: goto label_136dd4;
            case 0x136DD8u: goto label_136dd8;
            case 0x136DDCu: goto label_136ddc;
            case 0x136DE0u: goto label_136de0;
            case 0x136DE4u: goto label_136de4;
            case 0x136DE8u: goto label_136de8;
            case 0x136DECu: goto label_136dec;
            case 0x136DF0u: goto label_136df0;
            case 0x136DF4u: goto label_136df4;
            case 0x136DF8u: goto label_136df8;
            case 0x136DFCu: goto label_136dfc;
            case 0x136E00u: goto label_136e00;
            case 0x136E04u: goto label_136e04;
            case 0x136E08u: goto label_136e08;
            case 0x136E0Cu: goto label_136e0c;
            case 0x136E10u: goto label_136e10;
            case 0x136E14u: goto label_136e14;
            case 0x136E18u: goto label_136e18;
            case 0x136E1Cu: goto label_136e1c;
            case 0x136E20u: goto label_136e20;
            case 0x136E24u: goto label_136e24;
            case 0x136E28u: goto label_136e28;
            case 0x136E2Cu: goto label_136e2c;
            case 0x136E30u: goto label_136e30;
            case 0x136E34u: goto label_136e34;
            case 0x136E38u: goto label_136e38;
            case 0x136E3Cu: goto label_136e3c;
            case 0x136E40u: goto label_136e40;
            case 0x136E44u: goto label_136e44;
            case 0x136E48u: goto label_136e48;
            case 0x136E4Cu: goto label_136e4c;
            case 0x136E50u: goto label_136e50;
            case 0x136E54u: goto label_136e54;
            case 0x136E58u: goto label_136e58;
            case 0x136E5Cu: goto label_136e5c;
            case 0x136E60u: goto label_136e60;
            case 0x136E64u: goto label_136e64;
            case 0x136E68u: goto label_136e68;
            case 0x136E6Cu: goto label_136e6c;
            case 0x136E70u: goto label_136e70;
            case 0x136E74u: goto label_136e74;
            case 0x136E78u: goto label_136e78;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E80u: goto label_136e80;
            case 0x136E84u: goto label_136e84;
            case 0x136E88u: goto label_136e88;
            case 0x136E8Cu: goto label_136e8c;
            case 0x136E90u: goto label_136e90;
            case 0x136E94u: goto label_136e94;
            case 0x136E98u: goto label_136e98;
            case 0x136E9Cu: goto label_136e9c;
            case 0x136EA0u: goto label_136ea0;
            case 0x136EA4u: goto label_136ea4;
            case 0x136EA8u: goto label_136ea8;
            case 0x136EACu: goto label_136eac;
            case 0x136EB0u: goto label_136eb0;
            case 0x136EB4u: goto label_136eb4;
            case 0x136EB8u: goto label_136eb8;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EC0u: goto label_136ec0;
            case 0x136EC4u: goto label_136ec4;
            case 0x136EC8u: goto label_136ec8;
            case 0x136ECCu: goto label_136ecc;
            case 0x136ED0u: goto label_136ed0;
            case 0x136ED4u: goto label_136ed4;
            case 0x136ED8u: goto label_136ed8;
            case 0x136EDCu: goto label_136edc;
            case 0x136EE0u: goto label_136ee0;
            case 0x136EE4u: goto label_136ee4;
            case 0x136EE8u: goto label_136ee8;
            case 0x136EECu: goto label_136eec;
            case 0x136EF0u: goto label_136ef0;
            case 0x136EF4u: goto label_136ef4;
            case 0x136EF8u: goto label_136ef8;
            case 0x136EFCu: goto label_136efc;
            case 0x136F00u: goto label_136f00;
            case 0x136F04u: goto label_136f04;
            case 0x136F08u: goto label_136f08;
            case 0x136F0Cu: goto label_136f0c;
            case 0x136F10u: goto label_136f10;
            case 0x136F14u: goto label_136f14;
            case 0x136F18u: goto label_136f18;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F20u: goto label_136f20;
            case 0x136F24u: goto label_136f24;
            case 0x136F28u: goto label_136f28;
            case 0x136F2Cu: goto label_136f2c;
            case 0x136F30u: goto label_136f30;
            case 0x136F34u: goto label_136f34;
            case 0x136F38u: goto label_136f38;
            case 0x136F3Cu: goto label_136f3c;
            case 0x136F40u: goto label_136f40;
            case 0x136F44u: goto label_136f44;
            case 0x136F48u: goto label_136f48;
            case 0x136F4Cu: goto label_136f4c;
            case 0x136F50u: goto label_136f50;
            case 0x136F54u: goto label_136f54;
            case 0x136F58u: goto label_136f58;
            case 0x136F5Cu: goto label_136f5c;
            case 0x136F60u: goto label_136f60;
            case 0x136F64u: goto label_136f64;
            case 0x136F68u: goto label_136f68;
            case 0x136F6Cu: goto label_136f6c;
            case 0x136F70u: goto label_136f70;
            case 0x136F74u: goto label_136f74;
            case 0x136F78u: goto label_136f78;
            case 0x136F7Cu: goto label_136f7c;
            case 0x136F80u: goto label_136f80;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            case 0x136F8Cu: goto label_136f8c;
            case 0x136F90u: goto label_136f90;
            case 0x136F94u: goto label_136f94;
            default: break;
        }
        return;
    }
    ctx->pc = 0x136ED4u;
label_136ed4:
    // 0x136ed4: 0x0
    ctx->pc = 0x136ed4u;
    // NOP
label_136ed8:
    // 0x136ed8: 0x27bdffc0
    ctx->pc = 0x136ed8u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967232));
label_136edc:
    // 0x136edc: 0xffb00020
    ctx->pc = 0x136edcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 16));
label_136ee0:
    // 0x136ee0: 0xa0802d
    ctx->pc = 0x136ee0u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
label_136ee4:
    // 0x136ee4: 0xffb10028
    ctx->pc = 0x136ee4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 17));
label_136ee8:
    // 0x136ee8: 0x14800007
label_136eec:
    if (ctx->pc == 0x136EECu) {
        ctx->pc = 0x136EECu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        ctx->pc = 0x136EF0u;
        goto label_136ef0;
    }
    ctx->pc = 0x136EE8u;
    {
        const bool branch_taken_0x136ee8 = (GPR_U32(ctx, 4) != GPR_U32(ctx, 0));
        ctx->pc = 0x136EECu;
        WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 31));
        if (branch_taken_0x136ee8) {
            ctx->pc = 0x136F08u;
            goto label_136f08;
        }
    }
    ctx->pc = 0x136EF0u;
label_136ef0:
    // 0x136ef0: 0x3c040024
    ctx->pc = 0x136ef0u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_136ef4:
    // 0x136ef4: 0xc04d480
label_136ef8:
    if (ctx->pc == 0x136EF8u) {
        ctx->pc = 0x136EF8u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951776));
        ctx->pc = 0x136EFCu;
        goto label_136efc;
    }
    ctx->pc = 0x136EF4u;
    SET_GPR_U32(ctx, 31, 0x136EFCu);
    ctx->pc = 0x136EF8u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951776));
    ctx->pc = 0x135200u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136EFCu; }
    }
    if (ctx->pc != 0x136EFCu) { return; }
    ctx->pc = 0x136EFCu;
label_136efc:
    // 0x136efc: 0x10000022
label_136f00:
    if (ctx->pc == 0x136F00u) {
        ctx->pc = 0x136F00u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->pc = 0x136F04u;
        goto label_136f04;
    }
    ctx->pc = 0x136EFCu;
    {
        const bool branch_taken_0x136efc = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136F00u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        if (branch_taken_0x136efc) {
            ctx->pc = 0x136F88u;
            goto label_136f88;
        }
    }
    ctx->pc = 0x136F04u;
label_136f04:
    // 0x136f04: 0x0
    ctx->pc = 0x136f04u;
    // NOP
label_136f08:
    // 0x136f08: 0x16000007
label_136f0c:
    if (ctx->pc == 0x136F0Cu) {
        ctx->pc = 0x136F10u;
        goto label_136f10;
    }
    ctx->pc = 0x136F08u;
    {
        const bool branch_taken_0x136f08 = (GPR_U32(ctx, 16) != GPR_U32(ctx, 0));
        if (branch_taken_0x136f08) {
            ctx->pc = 0x136F28u;
            goto label_136f28;
        }
    }
    ctx->pc = 0x136F10u;
label_136f10:
    // 0x136f10: 0x3c040024
    ctx->pc = 0x136f10u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_136f14:
    // 0x136f14: 0xc04d480
label_136f18:
    if (ctx->pc == 0x136F18u) {
        ctx->pc = 0x136F18u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951816));
        ctx->pc = 0x136F1Cu;
        goto label_136f1c;
    }
    ctx->pc = 0x136F14u;
    SET_GPR_U32(ctx, 31, 0x136F1Cu);
    ctx->pc = 0x136F18u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951816));
    ctx->pc = 0x135200u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136F1Cu; }
    }
    if (ctx->pc != 0x136F1Cu) { return; }
    ctx->pc = 0x136F1Cu;
label_136f1c:
    // 0x136f1c: 0x1000001a
label_136f20:
    if (ctx->pc == 0x136F20u) {
        ctx->pc = 0x136F20u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->pc = 0x136F24u;
        goto label_136f24;
    }
    ctx->pc = 0x136F1Cu;
    {
        const bool branch_taken_0x136f1c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136F20u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        if (branch_taken_0x136f1c) {
            ctx->pc = 0x136F88u;
            goto label_136f88;
        }
    }
    ctx->pc = 0x136F24u;
label_136f24:
    // 0x136f24: 0x0
    ctx->pc = 0x136f24u;
    // NOP
label_136f28:
    // 0x136f28: 0xc04d558
label_136f2c:
    if (ctx->pc == 0x136F2Cu) {
        ctx->pc = 0x136F30u;
        goto label_136f30;
    }
    ctx->pc = 0x136F28u;
    SET_GPR_U32(ctx, 31, 0x136F30u);
    ctx->pc = 0x135560u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135560_0x135560(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136F30u; }
    }
    if (ctx->pc != 0x136F30u) { return; }
    ctx->pc = 0x136F30u;
label_136f30:
    // 0x136f30: 0x282d
    ctx->pc = 0x136f30u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_136f34:
    // 0x136f34: 0x40882d
    ctx->pc = 0x136f34u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_136f38:
    // 0x136f38: 0x3a0202d
    ctx->pc = 0x136f38u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_136f3c:
    // 0x136f3c: 0x16200006
label_136f40:
    if (ctx->pc == 0x136F40u) {
        ctx->pc = 0x136F40u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 20));
        ctx->pc = 0x136F44u;
        goto label_136f44;
    }
    ctx->pc = 0x136F3Cu;
    {
        const bool branch_taken_0x136f3c = (GPR_U32(ctx, 17) != GPR_U32(ctx, 0));
        ctx->pc = 0x136F40u;
        SET_GPR_S32(ctx, 6, ADD32(GPR_U32(ctx, 0), 20));
        if (branch_taken_0x136f3c) {
            ctx->pc = 0x136F58u;
            goto label_136f58;
        }
    }
    ctx->pc = 0x136F44u;
label_136f44:
    // 0x136f44: 0x3c040024
    ctx->pc = 0x136f44u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_136f48:
    // 0x136f48: 0xc04d480
label_136f4c:
    if (ctx->pc == 0x136F4Cu) {
        ctx->pc = 0x136F4Cu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951856));
        ctx->pc = 0x136F50u;
        goto label_136f50;
    }
    ctx->pc = 0x136F48u;
    SET_GPR_U32(ctx, 31, 0x136F50u);
    ctx->pc = 0x136F4Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294951856));
    ctx->pc = 0x135200u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00135200_0x135200(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136F50u; }
    }
    if (ctx->pc != 0x136F50u) { return; }
    ctx->pc = 0x136F50u;
label_136f50:
    // 0x136f50: 0x1000000d
label_136f54:
    if (ctx->pc == 0x136F54u) {
        ctx->pc = 0x136F54u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        ctx->pc = 0x136F58u;
        goto label_136f58;
    }
    ctx->pc = 0x136F50u;
    {
        const bool branch_taken_0x136f50 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x136F54u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
        if (branch_taken_0x136f50) {
            ctx->pc = 0x136F88u;
            goto label_136f88;
        }
    }
    ctx->pc = 0x136F58u;
label_136f58:
    // 0x136f58: 0xc041f1a
label_136f5c:
    if (ctx->pc == 0x136F5Cu) {
        ctx->pc = 0x136F60u;
        goto label_136f60;
    }
    ctx->pc = 0x136F58u;
    SET_GPR_U32(ctx, 31, 0x136F60u);
    ctx->pc = 0x107C68u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x136F60u; }
    }
    if (ctx->pc != 0x136F60u) { return; }
    ctx->pc = 0x136F60u;
label_136f60:
    // 0x136f60: 0x24050006
    ctx->pc = 0x136f60u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 6));
label_136f64:
    // 0x136f64: 0xafb00004
    ctx->pc = 0x136f64u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 4), GPR_U32(ctx, 16));
label_136f68:
    // 0x136f68: 0x3a0202d
    ctx->pc = 0x136f68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
label_136f6c:
    // 0x136f6c: 0x302d
    ctx->pc = 0x136f6cu;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_136f70:
    // 0x136f70: 0x8e220060
    ctx->pc = 0x136f70u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 96)));
label_136f74:
    // 0x136f74: 0x10400003
label_136f78:
    if (ctx->pc == 0x136F78u) {
        ctx->pc = 0x136F78u;
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x136F7Cu;
        goto label_136f7c;
    }
    ctx->pc = 0x136F74u;
    {
        const bool branch_taken_0x136f74 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        ctx->pc = 0x136F78u;
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x136f74) {
            ctx->pc = 0x136F84u;
            goto label_136f84;
        }
    }
    ctx->pc = 0x136F7Cu;
label_136f7c:
    // 0x136f7c: 0x40f809
label_136f80:
    if (ctx->pc == 0x136F80u) {
        ctx->pc = 0x136F84u;
        goto label_136f84;
    }
    ctx->pc = 0x136F7Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x136F84u);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A80u: goto label_136a80;
            case 0x136A84u: goto label_136a84;
            case 0x136A88u: goto label_136a88;
            case 0x136A8Cu: goto label_136a8c;
            case 0x136A90u: goto label_136a90;
            case 0x136A94u: goto label_136a94;
            case 0x136A98u: goto label_136a98;
            case 0x136A9Cu: goto label_136a9c;
            case 0x136AA0u: goto label_136aa0;
            case 0x136AA4u: goto label_136aa4;
            case 0x136AA8u: goto label_136aa8;
            case 0x136AACu: goto label_136aac;
            case 0x136AB0u: goto label_136ab0;
            case 0x136AB4u: goto label_136ab4;
            case 0x136AB8u: goto label_136ab8;
            case 0x136ABCu: goto label_136abc;
            case 0x136AC0u: goto label_136ac0;
            case 0x136AC4u: goto label_136ac4;
            case 0x136AC8u: goto label_136ac8;
            case 0x136ACCu: goto label_136acc;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AD4u: goto label_136ad4;
            case 0x136AD8u: goto label_136ad8;
            case 0x136ADCu: goto label_136adc;
            case 0x136AE0u: goto label_136ae0;
            case 0x136AE4u: goto label_136ae4;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AECu: goto label_136aec;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF4u: goto label_136af4;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B00u: goto label_136b00;
            case 0x136B04u: goto label_136b04;
            case 0x136B08u: goto label_136b08;
            case 0x136B0Cu: goto label_136b0c;
            case 0x136B10u: goto label_136b10;
            case 0x136B14u: goto label_136b14;
            case 0x136B18u: goto label_136b18;
            case 0x136B1Cu: goto label_136b1c;
            case 0x136B20u: goto label_136b20;
            case 0x136B24u: goto label_136b24;
            case 0x136B28u: goto label_136b28;
            case 0x136B2Cu: goto label_136b2c;
            case 0x136B30u: goto label_136b30;
            case 0x136B34u: goto label_136b34;
            case 0x136B38u: goto label_136b38;
            case 0x136B3Cu: goto label_136b3c;
            case 0x136B40u: goto label_136b40;
            case 0x136B44u: goto label_136b44;
            case 0x136B48u: goto label_136b48;
            case 0x136B4Cu: goto label_136b4c;
            case 0x136B50u: goto label_136b50;
            case 0x136B54u: goto label_136b54;
            case 0x136B58u: goto label_136b58;
            case 0x136B5Cu: goto label_136b5c;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136B68u: goto label_136b68;
            case 0x136B6Cu: goto label_136b6c;
            case 0x136B70u: goto label_136b70;
            case 0x136B74u: goto label_136b74;
            case 0x136B78u: goto label_136b78;
            case 0x136B7Cu: goto label_136b7c;
            case 0x136B80u: goto label_136b80;
            case 0x136B84u: goto label_136b84;
            case 0x136B88u: goto label_136b88;
            case 0x136B8Cu: goto label_136b8c;
            case 0x136B90u: goto label_136b90;
            case 0x136B94u: goto label_136b94;
            case 0x136B98u: goto label_136b98;
            case 0x136B9Cu: goto label_136b9c;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BA4u: goto label_136ba4;
            case 0x136BA8u: goto label_136ba8;
            case 0x136BACu: goto label_136bac;
            case 0x136BB0u: goto label_136bb0;
            case 0x136BB4u: goto label_136bb4;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BBCu: goto label_136bbc;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BC4u: goto label_136bc4;
            case 0x136BC8u: goto label_136bc8;
            case 0x136BCCu: goto label_136bcc;
            case 0x136BD0u: goto label_136bd0;
            case 0x136BD4u: goto label_136bd4;
            case 0x136BD8u: goto label_136bd8;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE0u: goto label_136be0;
            case 0x136BE4u: goto label_136be4;
            case 0x136BE8u: goto label_136be8;
            case 0x136BECu: goto label_136bec;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF4u: goto label_136bf4;
            case 0x136BF8u: goto label_136bf8;
            case 0x136BFCu: goto label_136bfc;
            case 0x136C00u: goto label_136c00;
            case 0x136C04u: goto label_136c04;
            case 0x136C08u: goto label_136c08;
            case 0x136C0Cu: goto label_136c0c;
            case 0x136C10u: goto label_136c10;
            case 0x136C14u: goto label_136c14;
            case 0x136C18u: goto label_136c18;
            case 0x136C1Cu: goto label_136c1c;
            case 0x136C20u: goto label_136c20;
            case 0x136C24u: goto label_136c24;
            case 0x136C28u: goto label_136c28;
            case 0x136C2Cu: goto label_136c2c;
            case 0x136C30u: goto label_136c30;
            case 0x136C34u: goto label_136c34;
            case 0x136C38u: goto label_136c38;
            case 0x136C3Cu: goto label_136c3c;
            case 0x136C40u: goto label_136c40;
            case 0x136C44u: goto label_136c44;
            case 0x136C48u: goto label_136c48;
            case 0x136C4Cu: goto label_136c4c;
            case 0x136C50u: goto label_136c50;
            case 0x136C54u: goto label_136c54;
            case 0x136C58u: goto label_136c58;
            case 0x136C5Cu: goto label_136c5c;
            case 0x136C60u: goto label_136c60;
            case 0x136C64u: goto label_136c64;
            case 0x136C68u: goto label_136c68;
            case 0x136C6Cu: goto label_136c6c;
            case 0x136C70u: goto label_136c70;
            case 0x136C74u: goto label_136c74;
            case 0x136C78u: goto label_136c78;
            case 0x136C7Cu: goto label_136c7c;
            case 0x136C80u: goto label_136c80;
            case 0x136C84u: goto label_136c84;
            case 0x136C88u: goto label_136c88;
            case 0x136C8Cu: goto label_136c8c;
            case 0x136C90u: goto label_136c90;
            case 0x136C94u: goto label_136c94;
            case 0x136C98u: goto label_136c98;
            case 0x136C9Cu: goto label_136c9c;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CA4u: goto label_136ca4;
            case 0x136CA8u: goto label_136ca8;
            case 0x136CACu: goto label_136cac;
            case 0x136CB0u: goto label_136cb0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CB8u: goto label_136cb8;
            case 0x136CBCu: goto label_136cbc;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC4u: goto label_136cc4;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CCCu: goto label_136ccc;
            case 0x136CD0u: goto label_136cd0;
            case 0x136CD4u: goto label_136cd4;
            case 0x136CD8u: goto label_136cd8;
            case 0x136CDCu: goto label_136cdc;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE4u: goto label_136ce4;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CECu: goto label_136cec;
            case 0x136CF0u: goto label_136cf0;
            case 0x136CF4u: goto label_136cf4;
            case 0x136CF8u: goto label_136cf8;
            case 0x136CFCu: goto label_136cfc;
            case 0x136D00u: goto label_136d00;
            case 0x136D04u: goto label_136d04;
            case 0x136D08u: goto label_136d08;
            case 0x136D0Cu: goto label_136d0c;
            case 0x136D10u: goto label_136d10;
            case 0x136D14u: goto label_136d14;
            case 0x136D18u: goto label_136d18;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D20u: goto label_136d20;
            case 0x136D24u: goto label_136d24;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D34u: goto label_136d34;
            case 0x136D38u: goto label_136d38;
            case 0x136D3Cu: goto label_136d3c;
            case 0x136D40u: goto label_136d40;
            case 0x136D44u: goto label_136d44;
            case 0x136D48u: goto label_136d48;
            case 0x136D4Cu: goto label_136d4c;
            case 0x136D50u: goto label_136d50;
            case 0x136D54u: goto label_136d54;
            case 0x136D58u: goto label_136d58;
            case 0x136D5Cu: goto label_136d5c;
            case 0x136D60u: goto label_136d60;
            case 0x136D64u: goto label_136d64;
            case 0x136D68u: goto label_136d68;
            case 0x136D6Cu: goto label_136d6c;
            case 0x136D70u: goto label_136d70;
            case 0x136D74u: goto label_136d74;
            case 0x136D78u: goto label_136d78;
            case 0x136D7Cu: goto label_136d7c;
            case 0x136D80u: goto label_136d80;
            case 0x136D84u: goto label_136d84;
            case 0x136D88u: goto label_136d88;
            case 0x136D8Cu: goto label_136d8c;
            case 0x136D90u: goto label_136d90;
            case 0x136D94u: goto label_136d94;
            case 0x136D98u: goto label_136d98;
            case 0x136D9Cu: goto label_136d9c;
            case 0x136DA0u: goto label_136da0;
            case 0x136DA4u: goto label_136da4;
            case 0x136DA8u: goto label_136da8;
            case 0x136DACu: goto label_136dac;
            case 0x136DB0u: goto label_136db0;
            case 0x136DB4u: goto label_136db4;
            case 0x136DB8u: goto label_136db8;
            case 0x136DBCu: goto label_136dbc;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC4u: goto label_136dc4;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DCCu: goto label_136dcc;
            case 0x136DD0u: goto label_136dd0;
            case 0x136DD4u: goto label_136dd4;
            case 0x136DD8u: goto label_136dd8;
            case 0x136DDCu: goto label_136ddc;
            case 0x136DE0u: goto label_136de0;
            case 0x136DE4u: goto label_136de4;
            case 0x136DE8u: goto label_136de8;
            case 0x136DECu: goto label_136dec;
            case 0x136DF0u: goto label_136df0;
            case 0x136DF4u: goto label_136df4;
            case 0x136DF8u: goto label_136df8;
            case 0x136DFCu: goto label_136dfc;
            case 0x136E00u: goto label_136e00;
            case 0x136E04u: goto label_136e04;
            case 0x136E08u: goto label_136e08;
            case 0x136E0Cu: goto label_136e0c;
            case 0x136E10u: goto label_136e10;
            case 0x136E14u: goto label_136e14;
            case 0x136E18u: goto label_136e18;
            case 0x136E1Cu: goto label_136e1c;
            case 0x136E20u: goto label_136e20;
            case 0x136E24u: goto label_136e24;
            case 0x136E28u: goto label_136e28;
            case 0x136E2Cu: goto label_136e2c;
            case 0x136E30u: goto label_136e30;
            case 0x136E34u: goto label_136e34;
            case 0x136E38u: goto label_136e38;
            case 0x136E3Cu: goto label_136e3c;
            case 0x136E40u: goto label_136e40;
            case 0x136E44u: goto label_136e44;
            case 0x136E48u: goto label_136e48;
            case 0x136E4Cu: goto label_136e4c;
            case 0x136E50u: goto label_136e50;
            case 0x136E54u: goto label_136e54;
            case 0x136E58u: goto label_136e58;
            case 0x136E5Cu: goto label_136e5c;
            case 0x136E60u: goto label_136e60;
            case 0x136E64u: goto label_136e64;
            case 0x136E68u: goto label_136e68;
            case 0x136E6Cu: goto label_136e6c;
            case 0x136E70u: goto label_136e70;
            case 0x136E74u: goto label_136e74;
            case 0x136E78u: goto label_136e78;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E80u: goto label_136e80;
            case 0x136E84u: goto label_136e84;
            case 0x136E88u: goto label_136e88;
            case 0x136E8Cu: goto label_136e8c;
            case 0x136E90u: goto label_136e90;
            case 0x136E94u: goto label_136e94;
            case 0x136E98u: goto label_136e98;
            case 0x136E9Cu: goto label_136e9c;
            case 0x136EA0u: goto label_136ea0;
            case 0x136EA4u: goto label_136ea4;
            case 0x136EA8u: goto label_136ea8;
            case 0x136EACu: goto label_136eac;
            case 0x136EB0u: goto label_136eb0;
            case 0x136EB4u: goto label_136eb4;
            case 0x136EB8u: goto label_136eb8;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EC0u: goto label_136ec0;
            case 0x136EC4u: goto label_136ec4;
            case 0x136EC8u: goto label_136ec8;
            case 0x136ECCu: goto label_136ecc;
            case 0x136ED0u: goto label_136ed0;
            case 0x136ED4u: goto label_136ed4;
            case 0x136ED8u: goto label_136ed8;
            case 0x136EDCu: goto label_136edc;
            case 0x136EE0u: goto label_136ee0;
            case 0x136EE4u: goto label_136ee4;
            case 0x136EE8u: goto label_136ee8;
            case 0x136EECu: goto label_136eec;
            case 0x136EF0u: goto label_136ef0;
            case 0x136EF4u: goto label_136ef4;
            case 0x136EF8u: goto label_136ef8;
            case 0x136EFCu: goto label_136efc;
            case 0x136F00u: goto label_136f00;
            case 0x136F04u: goto label_136f04;
            case 0x136F08u: goto label_136f08;
            case 0x136F0Cu: goto label_136f0c;
            case 0x136F10u: goto label_136f10;
            case 0x136F14u: goto label_136f14;
            case 0x136F18u: goto label_136f18;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F20u: goto label_136f20;
            case 0x136F24u: goto label_136f24;
            case 0x136F28u: goto label_136f28;
            case 0x136F2Cu: goto label_136f2c;
            case 0x136F30u: goto label_136f30;
            case 0x136F34u: goto label_136f34;
            case 0x136F38u: goto label_136f38;
            case 0x136F3Cu: goto label_136f3c;
            case 0x136F40u: goto label_136f40;
            case 0x136F44u: goto label_136f44;
            case 0x136F48u: goto label_136f48;
            case 0x136F4Cu: goto label_136f4c;
            case 0x136F50u: goto label_136f50;
            case 0x136F54u: goto label_136f54;
            case 0x136F58u: goto label_136f58;
            case 0x136F5Cu: goto label_136f5c;
            case 0x136F60u: goto label_136f60;
            case 0x136F64u: goto label_136f64;
            case 0x136F68u: goto label_136f68;
            case 0x136F6Cu: goto label_136f6c;
            case 0x136F70u: goto label_136f70;
            case 0x136F74u: goto label_136f74;
            case 0x136F78u: goto label_136f78;
            case 0x136F7Cu: goto label_136f7c;
            case 0x136F80u: goto label_136f80;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            case 0x136F8Cu: goto label_136f8c;
            case 0x136F90u: goto label_136f90;
            case 0x136F94u: goto label_136f94;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x136F84u; }
            if (ctx->pc != 0x136F84u) { return; }
        }
    }
    ctx->pc = 0x136F84u;
label_136f84:
    // 0x136f84: 0xdfb00020
    ctx->pc = 0x136f84u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 32)));
label_136f88:
    // 0x136f88: 0xdfb10028
    ctx->pc = 0x136f88u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 40)));
label_136f8c:
    // 0x136f8c: 0xdfbf0030
    ctx->pc = 0x136f8cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 48)));
label_136f90:
    // 0x136f90: 0x3e00008
label_136f94:
    if (ctx->pc == 0x136F94u) {
        ctx->pc = 0x136F94u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = 0x136F98u;
        goto label_fallthrough_0x136f90;
    }
    ctx->pc = 0x136F90u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x136F94u;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 64));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x136A80u: goto label_136a80;
            case 0x136A84u: goto label_136a84;
            case 0x136A88u: goto label_136a88;
            case 0x136A8Cu: goto label_136a8c;
            case 0x136A90u: goto label_136a90;
            case 0x136A94u: goto label_136a94;
            case 0x136A98u: goto label_136a98;
            case 0x136A9Cu: goto label_136a9c;
            case 0x136AA0u: goto label_136aa0;
            case 0x136AA4u: goto label_136aa4;
            case 0x136AA8u: goto label_136aa8;
            case 0x136AACu: goto label_136aac;
            case 0x136AB0u: goto label_136ab0;
            case 0x136AB4u: goto label_136ab4;
            case 0x136AB8u: goto label_136ab8;
            case 0x136ABCu: goto label_136abc;
            case 0x136AC0u: goto label_136ac0;
            case 0x136AC4u: goto label_136ac4;
            case 0x136AC8u: goto label_136ac8;
            case 0x136ACCu: goto label_136acc;
            case 0x136AD0u: goto label_136ad0;
            case 0x136AD4u: goto label_136ad4;
            case 0x136AD8u: goto label_136ad8;
            case 0x136ADCu: goto label_136adc;
            case 0x136AE0u: goto label_136ae0;
            case 0x136AE4u: goto label_136ae4;
            case 0x136AE8u: goto label_136ae8;
            case 0x136AECu: goto label_136aec;
            case 0x136AF0u: goto label_136af0;
            case 0x136AF4u: goto label_136af4;
            case 0x136AF8u: goto label_136af8;
            case 0x136AFCu: goto label_136afc;
            case 0x136B00u: goto label_136b00;
            case 0x136B04u: goto label_136b04;
            case 0x136B08u: goto label_136b08;
            case 0x136B0Cu: goto label_136b0c;
            case 0x136B10u: goto label_136b10;
            case 0x136B14u: goto label_136b14;
            case 0x136B18u: goto label_136b18;
            case 0x136B1Cu: goto label_136b1c;
            case 0x136B20u: goto label_136b20;
            case 0x136B24u: goto label_136b24;
            case 0x136B28u: goto label_136b28;
            case 0x136B2Cu: goto label_136b2c;
            case 0x136B30u: goto label_136b30;
            case 0x136B34u: goto label_136b34;
            case 0x136B38u: goto label_136b38;
            case 0x136B3Cu: goto label_136b3c;
            case 0x136B40u: goto label_136b40;
            case 0x136B44u: goto label_136b44;
            case 0x136B48u: goto label_136b48;
            case 0x136B4Cu: goto label_136b4c;
            case 0x136B50u: goto label_136b50;
            case 0x136B54u: goto label_136b54;
            case 0x136B58u: goto label_136b58;
            case 0x136B5Cu: goto label_136b5c;
            case 0x136B60u: goto label_136b60;
            case 0x136B64u: goto label_136b64;
            case 0x136B68u: goto label_136b68;
            case 0x136B6Cu: goto label_136b6c;
            case 0x136B70u: goto label_136b70;
            case 0x136B74u: goto label_136b74;
            case 0x136B78u: goto label_136b78;
            case 0x136B7Cu: goto label_136b7c;
            case 0x136B80u: goto label_136b80;
            case 0x136B84u: goto label_136b84;
            case 0x136B88u: goto label_136b88;
            case 0x136B8Cu: goto label_136b8c;
            case 0x136B90u: goto label_136b90;
            case 0x136B94u: goto label_136b94;
            case 0x136B98u: goto label_136b98;
            case 0x136B9Cu: goto label_136b9c;
            case 0x136BA0u: goto label_136ba0;
            case 0x136BA4u: goto label_136ba4;
            case 0x136BA8u: goto label_136ba8;
            case 0x136BACu: goto label_136bac;
            case 0x136BB0u: goto label_136bb0;
            case 0x136BB4u: goto label_136bb4;
            case 0x136BB8u: goto label_136bb8;
            case 0x136BBCu: goto label_136bbc;
            case 0x136BC0u: goto label_136bc0;
            case 0x136BC4u: goto label_136bc4;
            case 0x136BC8u: goto label_136bc8;
            case 0x136BCCu: goto label_136bcc;
            case 0x136BD0u: goto label_136bd0;
            case 0x136BD4u: goto label_136bd4;
            case 0x136BD8u: goto label_136bd8;
            case 0x136BDCu: goto label_136bdc;
            case 0x136BE0u: goto label_136be0;
            case 0x136BE4u: goto label_136be4;
            case 0x136BE8u: goto label_136be8;
            case 0x136BECu: goto label_136bec;
            case 0x136BF0u: goto label_136bf0;
            case 0x136BF4u: goto label_136bf4;
            case 0x136BF8u: goto label_136bf8;
            case 0x136BFCu: goto label_136bfc;
            case 0x136C00u: goto label_136c00;
            case 0x136C04u: goto label_136c04;
            case 0x136C08u: goto label_136c08;
            case 0x136C0Cu: goto label_136c0c;
            case 0x136C10u: goto label_136c10;
            case 0x136C14u: goto label_136c14;
            case 0x136C18u: goto label_136c18;
            case 0x136C1Cu: goto label_136c1c;
            case 0x136C20u: goto label_136c20;
            case 0x136C24u: goto label_136c24;
            case 0x136C28u: goto label_136c28;
            case 0x136C2Cu: goto label_136c2c;
            case 0x136C30u: goto label_136c30;
            case 0x136C34u: goto label_136c34;
            case 0x136C38u: goto label_136c38;
            case 0x136C3Cu: goto label_136c3c;
            case 0x136C40u: goto label_136c40;
            case 0x136C44u: goto label_136c44;
            case 0x136C48u: goto label_136c48;
            case 0x136C4Cu: goto label_136c4c;
            case 0x136C50u: goto label_136c50;
            case 0x136C54u: goto label_136c54;
            case 0x136C58u: goto label_136c58;
            case 0x136C5Cu: goto label_136c5c;
            case 0x136C60u: goto label_136c60;
            case 0x136C64u: goto label_136c64;
            case 0x136C68u: goto label_136c68;
            case 0x136C6Cu: goto label_136c6c;
            case 0x136C70u: goto label_136c70;
            case 0x136C74u: goto label_136c74;
            case 0x136C78u: goto label_136c78;
            case 0x136C7Cu: goto label_136c7c;
            case 0x136C80u: goto label_136c80;
            case 0x136C84u: goto label_136c84;
            case 0x136C88u: goto label_136c88;
            case 0x136C8Cu: goto label_136c8c;
            case 0x136C90u: goto label_136c90;
            case 0x136C94u: goto label_136c94;
            case 0x136C98u: goto label_136c98;
            case 0x136C9Cu: goto label_136c9c;
            case 0x136CA0u: goto label_136ca0;
            case 0x136CA4u: goto label_136ca4;
            case 0x136CA8u: goto label_136ca8;
            case 0x136CACu: goto label_136cac;
            case 0x136CB0u: goto label_136cb0;
            case 0x136CB4u: goto label_136cb4;
            case 0x136CB8u: goto label_136cb8;
            case 0x136CBCu: goto label_136cbc;
            case 0x136CC0u: goto label_136cc0;
            case 0x136CC4u: goto label_136cc4;
            case 0x136CC8u: goto label_136cc8;
            case 0x136CCCu: goto label_136ccc;
            case 0x136CD0u: goto label_136cd0;
            case 0x136CD4u: goto label_136cd4;
            case 0x136CD8u: goto label_136cd8;
            case 0x136CDCu: goto label_136cdc;
            case 0x136CE0u: goto label_136ce0;
            case 0x136CE4u: goto label_136ce4;
            case 0x136CE8u: goto label_136ce8;
            case 0x136CECu: goto label_136cec;
            case 0x136CF0u: goto label_136cf0;
            case 0x136CF4u: goto label_136cf4;
            case 0x136CF8u: goto label_136cf8;
            case 0x136CFCu: goto label_136cfc;
            case 0x136D00u: goto label_136d00;
            case 0x136D04u: goto label_136d04;
            case 0x136D08u: goto label_136d08;
            case 0x136D0Cu: goto label_136d0c;
            case 0x136D10u: goto label_136d10;
            case 0x136D14u: goto label_136d14;
            case 0x136D18u: goto label_136d18;
            case 0x136D1Cu: goto label_136d1c;
            case 0x136D20u: goto label_136d20;
            case 0x136D24u: goto label_136d24;
            case 0x136D28u: goto label_136d28;
            case 0x136D2Cu: goto label_136d2c;
            case 0x136D30u: goto label_136d30;
            case 0x136D34u: goto label_136d34;
            case 0x136D38u: goto label_136d38;
            case 0x136D3Cu: goto label_136d3c;
            case 0x136D40u: goto label_136d40;
            case 0x136D44u: goto label_136d44;
            case 0x136D48u: goto label_136d48;
            case 0x136D4Cu: goto label_136d4c;
            case 0x136D50u: goto label_136d50;
            case 0x136D54u: goto label_136d54;
            case 0x136D58u: goto label_136d58;
            case 0x136D5Cu: goto label_136d5c;
            case 0x136D60u: goto label_136d60;
            case 0x136D64u: goto label_136d64;
            case 0x136D68u: goto label_136d68;
            case 0x136D6Cu: goto label_136d6c;
            case 0x136D70u: goto label_136d70;
            case 0x136D74u: goto label_136d74;
            case 0x136D78u: goto label_136d78;
            case 0x136D7Cu: goto label_136d7c;
            case 0x136D80u: goto label_136d80;
            case 0x136D84u: goto label_136d84;
            case 0x136D88u: goto label_136d88;
            case 0x136D8Cu: goto label_136d8c;
            case 0x136D90u: goto label_136d90;
            case 0x136D94u: goto label_136d94;
            case 0x136D98u: goto label_136d98;
            case 0x136D9Cu: goto label_136d9c;
            case 0x136DA0u: goto label_136da0;
            case 0x136DA4u: goto label_136da4;
            case 0x136DA8u: goto label_136da8;
            case 0x136DACu: goto label_136dac;
            case 0x136DB0u: goto label_136db0;
            case 0x136DB4u: goto label_136db4;
            case 0x136DB8u: goto label_136db8;
            case 0x136DBCu: goto label_136dbc;
            case 0x136DC0u: goto label_136dc0;
            case 0x136DC4u: goto label_136dc4;
            case 0x136DC8u: goto label_136dc8;
            case 0x136DCCu: goto label_136dcc;
            case 0x136DD0u: goto label_136dd0;
            case 0x136DD4u: goto label_136dd4;
            case 0x136DD8u: goto label_136dd8;
            case 0x136DDCu: goto label_136ddc;
            case 0x136DE0u: goto label_136de0;
            case 0x136DE4u: goto label_136de4;
            case 0x136DE8u: goto label_136de8;
            case 0x136DECu: goto label_136dec;
            case 0x136DF0u: goto label_136df0;
            case 0x136DF4u: goto label_136df4;
            case 0x136DF8u: goto label_136df8;
            case 0x136DFCu: goto label_136dfc;
            case 0x136E00u: goto label_136e00;
            case 0x136E04u: goto label_136e04;
            case 0x136E08u: goto label_136e08;
            case 0x136E0Cu: goto label_136e0c;
            case 0x136E10u: goto label_136e10;
            case 0x136E14u: goto label_136e14;
            case 0x136E18u: goto label_136e18;
            case 0x136E1Cu: goto label_136e1c;
            case 0x136E20u: goto label_136e20;
            case 0x136E24u: goto label_136e24;
            case 0x136E28u: goto label_136e28;
            case 0x136E2Cu: goto label_136e2c;
            case 0x136E30u: goto label_136e30;
            case 0x136E34u: goto label_136e34;
            case 0x136E38u: goto label_136e38;
            case 0x136E3Cu: goto label_136e3c;
            case 0x136E40u: goto label_136e40;
            case 0x136E44u: goto label_136e44;
            case 0x136E48u: goto label_136e48;
            case 0x136E4Cu: goto label_136e4c;
            case 0x136E50u: goto label_136e50;
            case 0x136E54u: goto label_136e54;
            case 0x136E58u: goto label_136e58;
            case 0x136E5Cu: goto label_136e5c;
            case 0x136E60u: goto label_136e60;
            case 0x136E64u: goto label_136e64;
            case 0x136E68u: goto label_136e68;
            case 0x136E6Cu: goto label_136e6c;
            case 0x136E70u: goto label_136e70;
            case 0x136E74u: goto label_136e74;
            case 0x136E78u: goto label_136e78;
            case 0x136E7Cu: goto label_136e7c;
            case 0x136E80u: goto label_136e80;
            case 0x136E84u: goto label_136e84;
            case 0x136E88u: goto label_136e88;
            case 0x136E8Cu: goto label_136e8c;
            case 0x136E90u: goto label_136e90;
            case 0x136E94u: goto label_136e94;
            case 0x136E98u: goto label_136e98;
            case 0x136E9Cu: goto label_136e9c;
            case 0x136EA0u: goto label_136ea0;
            case 0x136EA4u: goto label_136ea4;
            case 0x136EA8u: goto label_136ea8;
            case 0x136EACu: goto label_136eac;
            case 0x136EB0u: goto label_136eb0;
            case 0x136EB4u: goto label_136eb4;
            case 0x136EB8u: goto label_136eb8;
            case 0x136EBCu: goto label_136ebc;
            case 0x136EC0u: goto label_136ec0;
            case 0x136EC4u: goto label_136ec4;
            case 0x136EC8u: goto label_136ec8;
            case 0x136ECCu: goto label_136ecc;
            case 0x136ED0u: goto label_136ed0;
            case 0x136ED4u: goto label_136ed4;
            case 0x136ED8u: goto label_136ed8;
            case 0x136EDCu: goto label_136edc;
            case 0x136EE0u: goto label_136ee0;
            case 0x136EE4u: goto label_136ee4;
            case 0x136EE8u: goto label_136ee8;
            case 0x136EECu: goto label_136eec;
            case 0x136EF0u: goto label_136ef0;
            case 0x136EF4u: goto label_136ef4;
            case 0x136EF8u: goto label_136ef8;
            case 0x136EFCu: goto label_136efc;
            case 0x136F00u: goto label_136f00;
            case 0x136F04u: goto label_136f04;
            case 0x136F08u: goto label_136f08;
            case 0x136F0Cu: goto label_136f0c;
            case 0x136F10u: goto label_136f10;
            case 0x136F14u: goto label_136f14;
            case 0x136F18u: goto label_136f18;
            case 0x136F1Cu: goto label_136f1c;
            case 0x136F20u: goto label_136f20;
            case 0x136F24u: goto label_136f24;
            case 0x136F28u: goto label_136f28;
            case 0x136F2Cu: goto label_136f2c;
            case 0x136F30u: goto label_136f30;
            case 0x136F34u: goto label_136f34;
            case 0x136F38u: goto label_136f38;
            case 0x136F3Cu: goto label_136f3c;
            case 0x136F40u: goto label_136f40;
            case 0x136F44u: goto label_136f44;
            case 0x136F48u: goto label_136f48;
            case 0x136F4Cu: goto label_136f4c;
            case 0x136F50u: goto label_136f50;
            case 0x136F54u: goto label_136f54;
            case 0x136F58u: goto label_136f58;
            case 0x136F5Cu: goto label_136f5c;
            case 0x136F60u: goto label_136f60;
            case 0x136F64u: goto label_136f64;
            case 0x136F68u: goto label_136f68;
            case 0x136F6Cu: goto label_136f6c;
            case 0x136F70u: goto label_136f70;
            case 0x136F74u: goto label_136f74;
            case 0x136F78u: goto label_136f78;
            case 0x136F7Cu: goto label_136f7c;
            case 0x136F80u: goto label_136f80;
            case 0x136F84u: goto label_136f84;
            case 0x136F88u: goto label_136f88;
            case 0x136F8Cu: goto label_136f8c;
            case 0x136F90u: goto label_136f90;
            case 0x136F94u: goto label_136f94;
            default: break;
        }
        return;
    }
label_fallthrough_0x136f90:
    ctx->pc = 0x136F98u;
}
