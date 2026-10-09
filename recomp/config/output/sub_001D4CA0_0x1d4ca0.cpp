#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001D4CA0
// Address: 0x1d4ca0 - 0x1d50c0
void sub_001D4CA0_0x1d4ca0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001D4CA0_0x1d4ca0");
#endif

    switch (ctx->pc) {
        case 0x1d4d14u: goto label_1d4d14;
        case 0x1d4d9cu: goto label_1d4d9c;
        case 0x1d4dc0u: goto label_1d4dc0;
        case 0x1d4e64u: goto label_1d4e64;
        case 0x1d4e74u: goto label_1d4e74;
        case 0x1d4e8cu: goto label_1d4e8c;
        case 0x1d4ea4u: goto label_1d4ea4;
        case 0x1d4f0cu: goto label_1d4f0c;
        case 0x1d4f24u: goto label_1d4f24;
        case 0x1d4fe4u: goto label_1d4fe4;
        case 0x1d4ff4u: goto label_1d4ff4;
        case 0x1d5014u: goto label_1d5014;
        case 0x1d502cu: goto label_1d502c;
        case 0x1d5038u: goto label_1d5038;
        case 0x1d5090u: goto label_1d5090;
        default: break;
    }

    ctx->pc = 0x1d4ca0u;

label_1d4ca0:
    // 0x1d4ca0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4ca0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
label_1d4ca4:
    // 0x1d4ca4: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d4ca4u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
label_1d4ca8:
    // 0x1d4ca8: 0x80232648  lb          $v1, 0x2648($at)
    ctx->pc = 0x1d4ca8u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 9800)));
label_1d4cac:
    // 0x1d4cac: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1d4cacu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
label_1d4cb0:
    // 0x1d4cb0: 0x24426940  addiu       $v0, $v0, 0x6940
    ctx->pc = 0x1d4cb0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26944));
label_1d4cb4:
    // 0x1d4cb4: 0x24842648  addiu       $a0, $a0, 0x2648
    ctx->pc = 0x1d4cb4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9800));
label_1d4cb8:
    // 0x1d4cb8: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1d4cb8u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_1d4cbc:
    // 0x1d4cbc: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d4cbcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_1d4cc0:
    // 0x1d4cc0: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1d4cc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_1d4cc4:
    // 0x1d4cc4: 0x400008  jr          $v0
label_1d4cc8:
    if (ctx->pc == 0x1D4CC8u) {
        ctx->pc = 0x1D4CCCu;
        goto label_1d4ccc;
    }
    ctx->pc = 0x1D4CC4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4CA0u: goto label_1d4ca0;
            case 0x1D4CA4u: goto label_1d4ca4;
            case 0x1D4CA8u: goto label_1d4ca8;
            case 0x1D4CACu: goto label_1d4cac;
            case 0x1D4CB0u: goto label_1d4cb0;
            case 0x1D4CB4u: goto label_1d4cb4;
            case 0x1D4CB8u: goto label_1d4cb8;
            case 0x1D4CBCu: goto label_1d4cbc;
            case 0x1D4CC0u: goto label_1d4cc0;
            case 0x1D4CC4u: goto label_1d4cc4;
            case 0x1D4CC8u: goto label_1d4cc8;
            case 0x1D4CCCu: goto label_1d4ccc;
            case 0x1D4CD0u: goto label_1d4cd0;
            case 0x1D4CD4u: goto label_1d4cd4;
            case 0x1D4CD8u: goto label_1d4cd8;
            case 0x1D4CDCu: goto label_1d4cdc;
            case 0x1D4CE0u: goto label_1d4ce0;
            case 0x1D4CE4u: goto label_1d4ce4;
            case 0x1D4CE8u: goto label_1d4ce8;
            case 0x1D4CECu: goto label_1d4cec;
            case 0x1D4CF0u: goto label_1d4cf0;
            case 0x1D4CF4u: goto label_1d4cf4;
            case 0x1D4CF8u: goto label_1d4cf8;
            case 0x1D4CFCu: goto label_1d4cfc;
            case 0x1D4D00u: goto label_1d4d00;
            case 0x1D4D04u: goto label_1d4d04;
            case 0x1D4D08u: goto label_1d4d08;
            case 0x1D4D0Cu: goto label_1d4d0c;
            case 0x1D4D10u: goto label_1d4d10;
            case 0x1D4D14u: goto label_1d4d14;
            case 0x1D4D18u: goto label_1d4d18;
            case 0x1D4D1Cu: goto label_1d4d1c;
            case 0x1D4D20u: goto label_1d4d20;
            case 0x1D4D24u: goto label_1d4d24;
            case 0x1D4D28u: goto label_1d4d28;
            case 0x1D4D2Cu: goto label_1d4d2c;
            case 0x1D4D30u: goto label_1d4d30;
            case 0x1D4D34u: goto label_1d4d34;
            case 0x1D4D38u: goto label_1d4d38;
            case 0x1D4D3Cu: goto label_1d4d3c;
            case 0x1D4D40u: goto label_1d4d40;
            case 0x1D4D44u: goto label_1d4d44;
            case 0x1D4D48u: goto label_1d4d48;
            case 0x1D4D4Cu: goto label_1d4d4c;
            case 0x1D4D50u: goto label_1d4d50;
            case 0x1D4D54u: goto label_1d4d54;
            case 0x1D4D58u: goto label_1d4d58;
            case 0x1D4D5Cu: goto label_1d4d5c;
            case 0x1D4D60u: goto label_1d4d60;
            case 0x1D4D64u: goto label_1d4d64;
            case 0x1D4D68u: goto label_1d4d68;
            case 0x1D4D6Cu: goto label_1d4d6c;
            case 0x1D4D70u: goto label_1d4d70;
            case 0x1D4D74u: goto label_1d4d74;
            case 0x1D4D78u: goto label_1d4d78;
            case 0x1D4D7Cu: goto label_1d4d7c;
            case 0x1D4D80u: goto label_1d4d80;
            case 0x1D4D84u: goto label_1d4d84;
            case 0x1D4D88u: goto label_1d4d88;
            case 0x1D4D8Cu: goto label_1d4d8c;
            case 0x1D4D90u: goto label_1d4d90;
            case 0x1D4D94u: goto label_1d4d94;
            case 0x1D4D98u: goto label_1d4d98;
            case 0x1D4D9Cu: goto label_1d4d9c;
            case 0x1D4DA0u: goto label_1d4da0;
            case 0x1D4DA4u: goto label_1d4da4;
            case 0x1D4DA8u: goto label_1d4da8;
            case 0x1D4DACu: goto label_1d4dac;
            case 0x1D4DB0u: goto label_1d4db0;
            case 0x1D4DB4u: goto label_1d4db4;
            case 0x1D4DB8u: goto label_1d4db8;
            case 0x1D4DBCu: goto label_1d4dbc;
            case 0x1D4DC0u: goto label_1d4dc0;
            case 0x1D4DC4u: goto label_1d4dc4;
            case 0x1D4DC8u: goto label_1d4dc8;
            case 0x1D4DCCu: goto label_1d4dcc;
            case 0x1D4DD0u: goto label_1d4dd0;
            case 0x1D4DD4u: goto label_1d4dd4;
            case 0x1D4DD8u: goto label_1d4dd8;
            case 0x1D4DDCu: goto label_1d4ddc;
            case 0x1D4DE0u: goto label_1d4de0;
            case 0x1D4DE4u: goto label_1d4de4;
            case 0x1D4DE8u: goto label_1d4de8;
            case 0x1D4DECu: goto label_1d4dec;
            case 0x1D4DF0u: goto label_1d4df0;
            case 0x1D4DF4u: goto label_1d4df4;
            case 0x1D4DF8u: goto label_1d4df8;
            case 0x1D4DFCu: goto label_1d4dfc;
            case 0x1D4E00u: goto label_1d4e00;
            case 0x1D4E04u: goto label_1d4e04;
            case 0x1D4E08u: goto label_1d4e08;
            case 0x1D4E0Cu: goto label_1d4e0c;
            case 0x1D4E10u: goto label_1d4e10;
            case 0x1D4E14u: goto label_1d4e14;
            case 0x1D4E18u: goto label_1d4e18;
            case 0x1D4E1Cu: goto label_1d4e1c;
            case 0x1D4E20u: goto label_1d4e20;
            case 0x1D4E24u: goto label_1d4e24;
            case 0x1D4E28u: goto label_1d4e28;
            case 0x1D4E2Cu: goto label_1d4e2c;
            case 0x1D4E30u: goto label_1d4e30;
            case 0x1D4E34u: goto label_1d4e34;
            case 0x1D4E38u: goto label_1d4e38;
            case 0x1D4E3Cu: goto label_1d4e3c;
            case 0x1D4E40u: goto label_1d4e40;
            case 0x1D4E44u: goto label_1d4e44;
            case 0x1D4E48u: goto label_1d4e48;
            case 0x1D4E4Cu: goto label_1d4e4c;
            case 0x1D4E50u: goto label_1d4e50;
            case 0x1D4E54u: goto label_1d4e54;
            case 0x1D4E58u: goto label_1d4e58;
            case 0x1D4E5Cu: goto label_1d4e5c;
            case 0x1D4E60u: goto label_1d4e60;
            case 0x1D4E64u: goto label_1d4e64;
            case 0x1D4E68u: goto label_1d4e68;
            case 0x1D4E6Cu: goto label_1d4e6c;
            case 0x1D4E70u: goto label_1d4e70;
            case 0x1D4E74u: goto label_1d4e74;
            case 0x1D4E78u: goto label_1d4e78;
            case 0x1D4E7Cu: goto label_1d4e7c;
            case 0x1D4E80u: goto label_1d4e80;
            case 0x1D4E84u: goto label_1d4e84;
            case 0x1D4E88u: goto label_1d4e88;
            case 0x1D4E8Cu: goto label_1d4e8c;
            case 0x1D4E90u: goto label_1d4e90;
            case 0x1D4E94u: goto label_1d4e94;
            case 0x1D4E98u: goto label_1d4e98;
            case 0x1D4E9Cu: goto label_1d4e9c;
            case 0x1D4EA0u: goto label_1d4ea0;
            case 0x1D4EA4u: goto label_1d4ea4;
            case 0x1D4EA8u: goto label_1d4ea8;
            case 0x1D4EACu: goto label_1d4eac;
            case 0x1D4EB0u: goto label_1d4eb0;
            case 0x1D4EB4u: goto label_1d4eb4;
            case 0x1D4EB8u: goto label_1d4eb8;
            case 0x1D4EBCu: goto label_1d4ebc;
            case 0x1D4EC0u: goto label_1d4ec0;
            case 0x1D4EC4u: goto label_1d4ec4;
            case 0x1D4EC8u: goto label_1d4ec8;
            case 0x1D4ECCu: goto label_1d4ecc;
            case 0x1D4ED0u: goto label_1d4ed0;
            case 0x1D4ED4u: goto label_1d4ed4;
            case 0x1D4ED8u: goto label_1d4ed8;
            case 0x1D4EDCu: goto label_1d4edc;
            case 0x1D4EE0u: goto label_1d4ee0;
            case 0x1D4EE4u: goto label_1d4ee4;
            case 0x1D4EE8u: goto label_1d4ee8;
            case 0x1D4EECu: goto label_1d4eec;
            case 0x1D4EF0u: goto label_1d4ef0;
            case 0x1D4EF4u: goto label_1d4ef4;
            case 0x1D4EF8u: goto label_1d4ef8;
            case 0x1D4EFCu: goto label_1d4efc;
            case 0x1D4F00u: goto label_1d4f00;
            case 0x1D4F04u: goto label_1d4f04;
            case 0x1D4F08u: goto label_1d4f08;
            case 0x1D4F0Cu: goto label_1d4f0c;
            case 0x1D4F10u: goto label_1d4f10;
            case 0x1D4F14u: goto label_1d4f14;
            case 0x1D4F18u: goto label_1d4f18;
            case 0x1D4F1Cu: goto label_1d4f1c;
            case 0x1D4F20u: goto label_1d4f20;
            case 0x1D4F24u: goto label_1d4f24;
            case 0x1D4F28u: goto label_1d4f28;
            case 0x1D4F2Cu: goto label_1d4f2c;
            case 0x1D4F30u: goto label_1d4f30;
            case 0x1D4F34u: goto label_1d4f34;
            case 0x1D4F38u: goto label_1d4f38;
            case 0x1D4F3Cu: goto label_1d4f3c;
            case 0x1D4F40u: goto label_1d4f40;
            case 0x1D4F44u: goto label_1d4f44;
            case 0x1D4F48u: goto label_1d4f48;
            case 0x1D4F4Cu: goto label_1d4f4c;
            case 0x1D4F50u: goto label_1d4f50;
            case 0x1D4F54u: goto label_1d4f54;
            case 0x1D4F58u: goto label_1d4f58;
            case 0x1D4F5Cu: goto label_1d4f5c;
            case 0x1D4F60u: goto label_1d4f60;
            case 0x1D4F64u: goto label_1d4f64;
            case 0x1D4F68u: goto label_1d4f68;
            case 0x1D4F6Cu: goto label_1d4f6c;
            case 0x1D4F70u: goto label_1d4f70;
            case 0x1D4F74u: goto label_1d4f74;
            case 0x1D4F78u: goto label_1d4f78;
            case 0x1D4F7Cu: goto label_1d4f7c;
            case 0x1D4F80u: goto label_1d4f80;
            case 0x1D4F84u: goto label_1d4f84;
            case 0x1D4F88u: goto label_1d4f88;
            case 0x1D4F8Cu: goto label_1d4f8c;
            case 0x1D4F90u: goto label_1d4f90;
            case 0x1D4F94u: goto label_1d4f94;
            case 0x1D4F98u: goto label_1d4f98;
            case 0x1D4F9Cu: goto label_1d4f9c;
            case 0x1D4FA0u: goto label_1d4fa0;
            case 0x1D4FA4u: goto label_1d4fa4;
            case 0x1D4FA8u: goto label_1d4fa8;
            case 0x1D4FACu: goto label_1d4fac;
            case 0x1D4FB0u: goto label_1d4fb0;
            case 0x1D4FB4u: goto label_1d4fb4;
            case 0x1D4FB8u: goto label_1d4fb8;
            case 0x1D4FBCu: goto label_1d4fbc;
            case 0x1D4FC0u: goto label_1d4fc0;
            case 0x1D4FC4u: goto label_1d4fc4;
            case 0x1D4FC8u: goto label_1d4fc8;
            case 0x1D4FCCu: goto label_1d4fcc;
            case 0x1D4FD0u: goto label_1d4fd0;
            case 0x1D4FD4u: goto label_1d4fd4;
            case 0x1D4FD8u: goto label_1d4fd8;
            case 0x1D4FDCu: goto label_1d4fdc;
            case 0x1D4FE0u: goto label_1d4fe0;
            case 0x1D4FE4u: goto label_1d4fe4;
            case 0x1D4FE8u: goto label_1d4fe8;
            case 0x1D4FECu: goto label_1d4fec;
            case 0x1D4FF0u: goto label_1d4ff0;
            case 0x1D4FF4u: goto label_1d4ff4;
            case 0x1D4FF8u: goto label_1d4ff8;
            case 0x1D4FFCu: goto label_1d4ffc;
            case 0x1D5000u: goto label_1d5000;
            case 0x1D5004u: goto label_1d5004;
            case 0x1D5008u: goto label_1d5008;
            case 0x1D500Cu: goto label_1d500c;
            case 0x1D5010u: goto label_1d5010;
            case 0x1D5014u: goto label_1d5014;
            case 0x1D5018u: goto label_1d5018;
            case 0x1D501Cu: goto label_1d501c;
            case 0x1D5020u: goto label_1d5020;
            case 0x1D5024u: goto label_1d5024;
            case 0x1D5028u: goto label_1d5028;
            case 0x1D502Cu: goto label_1d502c;
            case 0x1D5030u: goto label_1d5030;
            case 0x1D5034u: goto label_1d5034;
            case 0x1D5038u: goto label_1d5038;
            case 0x1D503Cu: goto label_1d503c;
            case 0x1D5040u: goto label_1d5040;
            case 0x1D5044u: goto label_1d5044;
            case 0x1D5048u: goto label_1d5048;
            case 0x1D504Cu: goto label_1d504c;
            case 0x1D5050u: goto label_1d5050;
            case 0x1D5054u: goto label_1d5054;
            case 0x1D5058u: goto label_1d5058;
            case 0x1D505Cu: goto label_1d505c;
            case 0x1D5060u: goto label_1d5060;
            case 0x1D5064u: goto label_1d5064;
            case 0x1D5068u: goto label_1d5068;
            case 0x1D506Cu: goto label_1d506c;
            case 0x1D5070u: goto label_1d5070;
            case 0x1D5074u: goto label_1d5074;
            case 0x1D5078u: goto label_1d5078;
            case 0x1D507Cu: goto label_1d507c;
            case 0x1D5080u: goto label_1d5080;
            case 0x1D5084u: goto label_1d5084;
            case 0x1D5088u: goto label_1d5088;
            case 0x1D508Cu: goto label_1d508c;
            case 0x1D5090u: goto label_1d5090;
            case 0x1D5094u: goto label_1d5094;
            case 0x1D5098u: goto label_1d5098;
            case 0x1D509Cu: goto label_1d509c;
            case 0x1D50A0u: goto label_1d50a0;
            case 0x1D50A4u: goto label_1d50a4;
            case 0x1D50A8u: goto label_1d50a8;
            case 0x1D50ACu: goto label_1d50ac;
            case 0x1D50B0u: goto label_1d50b0;
            case 0x1D50B4u: goto label_1d50b4;
            case 0x1D50B8u: goto label_1d50b8;
            case 0x1D50BCu: goto label_1d50bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4CCCu;
label_1d4ccc:
    // 0x1d4ccc: 0x0  nop
    ctx->pc = 0x1d4cccu;
    // NOP
label_1d4cd0:
    // 0x1d4cd0: 0x80830000  lb          $v1, 0x0($a0)
    ctx->pc = 0x1d4cd0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
label_1d4cd4:
    // 0x1d4cd4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d4cd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1d4cd8:
    // 0x1d4cd8: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1d4cd8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
label_1d4cdc:
    // 0x1d4cdc: 0x3e00008  jr          $ra
label_1d4ce0:
    if (ctx->pc == 0x1D4CE0u) {
        ctx->pc = 0x1D4CE0u;
            // 0x1d4ce0: 0xa0830000  sb          $v1, 0x0($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->pc = 0x1D4CE4u;
        goto label_1d4ce4;
    }
    ctx->pc = 0x1D4CDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4CE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4CDCu;
            // 0x1d4ce0: 0xa0830000  sb          $v1, 0x0($a0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4CA0u: goto label_1d4ca0;
            case 0x1D4CA4u: goto label_1d4ca4;
            case 0x1D4CA8u: goto label_1d4ca8;
            case 0x1D4CACu: goto label_1d4cac;
            case 0x1D4CB0u: goto label_1d4cb0;
            case 0x1D4CB4u: goto label_1d4cb4;
            case 0x1D4CB8u: goto label_1d4cb8;
            case 0x1D4CBCu: goto label_1d4cbc;
            case 0x1D4CC0u: goto label_1d4cc0;
            case 0x1D4CC4u: goto label_1d4cc4;
            case 0x1D4CC8u: goto label_1d4cc8;
            case 0x1D4CCCu: goto label_1d4ccc;
            case 0x1D4CD0u: goto label_1d4cd0;
            case 0x1D4CD4u: goto label_1d4cd4;
            case 0x1D4CD8u: goto label_1d4cd8;
            case 0x1D4CDCu: goto label_1d4cdc;
            case 0x1D4CE0u: goto label_1d4ce0;
            case 0x1D4CE4u: goto label_1d4ce4;
            case 0x1D4CE8u: goto label_1d4ce8;
            case 0x1D4CECu: goto label_1d4cec;
            case 0x1D4CF0u: goto label_1d4cf0;
            case 0x1D4CF4u: goto label_1d4cf4;
            case 0x1D4CF8u: goto label_1d4cf8;
            case 0x1D4CFCu: goto label_1d4cfc;
            case 0x1D4D00u: goto label_1d4d00;
            case 0x1D4D04u: goto label_1d4d04;
            case 0x1D4D08u: goto label_1d4d08;
            case 0x1D4D0Cu: goto label_1d4d0c;
            case 0x1D4D10u: goto label_1d4d10;
            case 0x1D4D14u: goto label_1d4d14;
            case 0x1D4D18u: goto label_1d4d18;
            case 0x1D4D1Cu: goto label_1d4d1c;
            case 0x1D4D20u: goto label_1d4d20;
            case 0x1D4D24u: goto label_1d4d24;
            case 0x1D4D28u: goto label_1d4d28;
            case 0x1D4D2Cu: goto label_1d4d2c;
            case 0x1D4D30u: goto label_1d4d30;
            case 0x1D4D34u: goto label_1d4d34;
            case 0x1D4D38u: goto label_1d4d38;
            case 0x1D4D3Cu: goto label_1d4d3c;
            case 0x1D4D40u: goto label_1d4d40;
            case 0x1D4D44u: goto label_1d4d44;
            case 0x1D4D48u: goto label_1d4d48;
            case 0x1D4D4Cu: goto label_1d4d4c;
            case 0x1D4D50u: goto label_1d4d50;
            case 0x1D4D54u: goto label_1d4d54;
            case 0x1D4D58u: goto label_1d4d58;
            case 0x1D4D5Cu: goto label_1d4d5c;
            case 0x1D4D60u: goto label_1d4d60;
            case 0x1D4D64u: goto label_1d4d64;
            case 0x1D4D68u: goto label_1d4d68;
            case 0x1D4D6Cu: goto label_1d4d6c;
            case 0x1D4D70u: goto label_1d4d70;
            case 0x1D4D74u: goto label_1d4d74;
            case 0x1D4D78u: goto label_1d4d78;
            case 0x1D4D7Cu: goto label_1d4d7c;
            case 0x1D4D80u: goto label_1d4d80;
            case 0x1D4D84u: goto label_1d4d84;
            case 0x1D4D88u: goto label_1d4d88;
            case 0x1D4D8Cu: goto label_1d4d8c;
            case 0x1D4D90u: goto label_1d4d90;
            case 0x1D4D94u: goto label_1d4d94;
            case 0x1D4D98u: goto label_1d4d98;
            case 0x1D4D9Cu: goto label_1d4d9c;
            case 0x1D4DA0u: goto label_1d4da0;
            case 0x1D4DA4u: goto label_1d4da4;
            case 0x1D4DA8u: goto label_1d4da8;
            case 0x1D4DACu: goto label_1d4dac;
            case 0x1D4DB0u: goto label_1d4db0;
            case 0x1D4DB4u: goto label_1d4db4;
            case 0x1D4DB8u: goto label_1d4db8;
            case 0x1D4DBCu: goto label_1d4dbc;
            case 0x1D4DC0u: goto label_1d4dc0;
            case 0x1D4DC4u: goto label_1d4dc4;
            case 0x1D4DC8u: goto label_1d4dc8;
            case 0x1D4DCCu: goto label_1d4dcc;
            case 0x1D4DD0u: goto label_1d4dd0;
            case 0x1D4DD4u: goto label_1d4dd4;
            case 0x1D4DD8u: goto label_1d4dd8;
            case 0x1D4DDCu: goto label_1d4ddc;
            case 0x1D4DE0u: goto label_1d4de0;
            case 0x1D4DE4u: goto label_1d4de4;
            case 0x1D4DE8u: goto label_1d4de8;
            case 0x1D4DECu: goto label_1d4dec;
            case 0x1D4DF0u: goto label_1d4df0;
            case 0x1D4DF4u: goto label_1d4df4;
            case 0x1D4DF8u: goto label_1d4df8;
            case 0x1D4DFCu: goto label_1d4dfc;
            case 0x1D4E00u: goto label_1d4e00;
            case 0x1D4E04u: goto label_1d4e04;
            case 0x1D4E08u: goto label_1d4e08;
            case 0x1D4E0Cu: goto label_1d4e0c;
            case 0x1D4E10u: goto label_1d4e10;
            case 0x1D4E14u: goto label_1d4e14;
            case 0x1D4E18u: goto label_1d4e18;
            case 0x1D4E1Cu: goto label_1d4e1c;
            case 0x1D4E20u: goto label_1d4e20;
            case 0x1D4E24u: goto label_1d4e24;
            case 0x1D4E28u: goto label_1d4e28;
            case 0x1D4E2Cu: goto label_1d4e2c;
            case 0x1D4E30u: goto label_1d4e30;
            case 0x1D4E34u: goto label_1d4e34;
            case 0x1D4E38u: goto label_1d4e38;
            case 0x1D4E3Cu: goto label_1d4e3c;
            case 0x1D4E40u: goto label_1d4e40;
            case 0x1D4E44u: goto label_1d4e44;
            case 0x1D4E48u: goto label_1d4e48;
            case 0x1D4E4Cu: goto label_1d4e4c;
            case 0x1D4E50u: goto label_1d4e50;
            case 0x1D4E54u: goto label_1d4e54;
            case 0x1D4E58u: goto label_1d4e58;
            case 0x1D4E5Cu: goto label_1d4e5c;
            case 0x1D4E60u: goto label_1d4e60;
            case 0x1D4E64u: goto label_1d4e64;
            case 0x1D4E68u: goto label_1d4e68;
            case 0x1D4E6Cu: goto label_1d4e6c;
            case 0x1D4E70u: goto label_1d4e70;
            case 0x1D4E74u: goto label_1d4e74;
            case 0x1D4E78u: goto label_1d4e78;
            case 0x1D4E7Cu: goto label_1d4e7c;
            case 0x1D4E80u: goto label_1d4e80;
            case 0x1D4E84u: goto label_1d4e84;
            case 0x1D4E88u: goto label_1d4e88;
            case 0x1D4E8Cu: goto label_1d4e8c;
            case 0x1D4E90u: goto label_1d4e90;
            case 0x1D4E94u: goto label_1d4e94;
            case 0x1D4E98u: goto label_1d4e98;
            case 0x1D4E9Cu: goto label_1d4e9c;
            case 0x1D4EA0u: goto label_1d4ea0;
            case 0x1D4EA4u: goto label_1d4ea4;
            case 0x1D4EA8u: goto label_1d4ea8;
            case 0x1D4EACu: goto label_1d4eac;
            case 0x1D4EB0u: goto label_1d4eb0;
            case 0x1D4EB4u: goto label_1d4eb4;
            case 0x1D4EB8u: goto label_1d4eb8;
            case 0x1D4EBCu: goto label_1d4ebc;
            case 0x1D4EC0u: goto label_1d4ec0;
            case 0x1D4EC4u: goto label_1d4ec4;
            case 0x1D4EC8u: goto label_1d4ec8;
            case 0x1D4ECCu: goto label_1d4ecc;
            case 0x1D4ED0u: goto label_1d4ed0;
            case 0x1D4ED4u: goto label_1d4ed4;
            case 0x1D4ED8u: goto label_1d4ed8;
            case 0x1D4EDCu: goto label_1d4edc;
            case 0x1D4EE0u: goto label_1d4ee0;
            case 0x1D4EE4u: goto label_1d4ee4;
            case 0x1D4EE8u: goto label_1d4ee8;
            case 0x1D4EECu: goto label_1d4eec;
            case 0x1D4EF0u: goto label_1d4ef0;
            case 0x1D4EF4u: goto label_1d4ef4;
            case 0x1D4EF8u: goto label_1d4ef8;
            case 0x1D4EFCu: goto label_1d4efc;
            case 0x1D4F00u: goto label_1d4f00;
            case 0x1D4F04u: goto label_1d4f04;
            case 0x1D4F08u: goto label_1d4f08;
            case 0x1D4F0Cu: goto label_1d4f0c;
            case 0x1D4F10u: goto label_1d4f10;
            case 0x1D4F14u: goto label_1d4f14;
            case 0x1D4F18u: goto label_1d4f18;
            case 0x1D4F1Cu: goto label_1d4f1c;
            case 0x1D4F20u: goto label_1d4f20;
            case 0x1D4F24u: goto label_1d4f24;
            case 0x1D4F28u: goto label_1d4f28;
            case 0x1D4F2Cu: goto label_1d4f2c;
            case 0x1D4F30u: goto label_1d4f30;
            case 0x1D4F34u: goto label_1d4f34;
            case 0x1D4F38u: goto label_1d4f38;
            case 0x1D4F3Cu: goto label_1d4f3c;
            case 0x1D4F40u: goto label_1d4f40;
            case 0x1D4F44u: goto label_1d4f44;
            case 0x1D4F48u: goto label_1d4f48;
            case 0x1D4F4Cu: goto label_1d4f4c;
            case 0x1D4F50u: goto label_1d4f50;
            case 0x1D4F54u: goto label_1d4f54;
            case 0x1D4F58u: goto label_1d4f58;
            case 0x1D4F5Cu: goto label_1d4f5c;
            case 0x1D4F60u: goto label_1d4f60;
            case 0x1D4F64u: goto label_1d4f64;
            case 0x1D4F68u: goto label_1d4f68;
            case 0x1D4F6Cu: goto label_1d4f6c;
            case 0x1D4F70u: goto label_1d4f70;
            case 0x1D4F74u: goto label_1d4f74;
            case 0x1D4F78u: goto label_1d4f78;
            case 0x1D4F7Cu: goto label_1d4f7c;
            case 0x1D4F80u: goto label_1d4f80;
            case 0x1D4F84u: goto label_1d4f84;
            case 0x1D4F88u: goto label_1d4f88;
            case 0x1D4F8Cu: goto label_1d4f8c;
            case 0x1D4F90u: goto label_1d4f90;
            case 0x1D4F94u: goto label_1d4f94;
            case 0x1D4F98u: goto label_1d4f98;
            case 0x1D4F9Cu: goto label_1d4f9c;
            case 0x1D4FA0u: goto label_1d4fa0;
            case 0x1D4FA4u: goto label_1d4fa4;
            case 0x1D4FA8u: goto label_1d4fa8;
            case 0x1D4FACu: goto label_1d4fac;
            case 0x1D4FB0u: goto label_1d4fb0;
            case 0x1D4FB4u: goto label_1d4fb4;
            case 0x1D4FB8u: goto label_1d4fb8;
            case 0x1D4FBCu: goto label_1d4fbc;
            case 0x1D4FC0u: goto label_1d4fc0;
            case 0x1D4FC4u: goto label_1d4fc4;
            case 0x1D4FC8u: goto label_1d4fc8;
            case 0x1D4FCCu: goto label_1d4fcc;
            case 0x1D4FD0u: goto label_1d4fd0;
            case 0x1D4FD4u: goto label_1d4fd4;
            case 0x1D4FD8u: goto label_1d4fd8;
            case 0x1D4FDCu: goto label_1d4fdc;
            case 0x1D4FE0u: goto label_1d4fe0;
            case 0x1D4FE4u: goto label_1d4fe4;
            case 0x1D4FE8u: goto label_1d4fe8;
            case 0x1D4FECu: goto label_1d4fec;
            case 0x1D4FF0u: goto label_1d4ff0;
            case 0x1D4FF4u: goto label_1d4ff4;
            case 0x1D4FF8u: goto label_1d4ff8;
            case 0x1D4FFCu: goto label_1d4ffc;
            case 0x1D5000u: goto label_1d5000;
            case 0x1D5004u: goto label_1d5004;
            case 0x1D5008u: goto label_1d5008;
            case 0x1D500Cu: goto label_1d500c;
            case 0x1D5010u: goto label_1d5010;
            case 0x1D5014u: goto label_1d5014;
            case 0x1D5018u: goto label_1d5018;
            case 0x1D501Cu: goto label_1d501c;
            case 0x1D5020u: goto label_1d5020;
            case 0x1D5024u: goto label_1d5024;
            case 0x1D5028u: goto label_1d5028;
            case 0x1D502Cu: goto label_1d502c;
            case 0x1D5030u: goto label_1d5030;
            case 0x1D5034u: goto label_1d5034;
            case 0x1D5038u: goto label_1d5038;
            case 0x1D503Cu: goto label_1d503c;
            case 0x1D5040u: goto label_1d5040;
            case 0x1D5044u: goto label_1d5044;
            case 0x1D5048u: goto label_1d5048;
            case 0x1D504Cu: goto label_1d504c;
            case 0x1D5050u: goto label_1d5050;
            case 0x1D5054u: goto label_1d5054;
            case 0x1D5058u: goto label_1d5058;
            case 0x1D505Cu: goto label_1d505c;
            case 0x1D5060u: goto label_1d5060;
            case 0x1D5064u: goto label_1d5064;
            case 0x1D5068u: goto label_1d5068;
            case 0x1D506Cu: goto label_1d506c;
            case 0x1D5070u: goto label_1d5070;
            case 0x1D5074u: goto label_1d5074;
            case 0x1D5078u: goto label_1d5078;
            case 0x1D507Cu: goto label_1d507c;
            case 0x1D5080u: goto label_1d5080;
            case 0x1D5084u: goto label_1d5084;
            case 0x1D5088u: goto label_1d5088;
            case 0x1D508Cu: goto label_1d508c;
            case 0x1D5090u: goto label_1d5090;
            case 0x1D5094u: goto label_1d5094;
            case 0x1D5098u: goto label_1d5098;
            case 0x1D509Cu: goto label_1d509c;
            case 0x1D50A0u: goto label_1d50a0;
            case 0x1D50A4u: goto label_1d50a4;
            case 0x1D50A8u: goto label_1d50a8;
            case 0x1D50ACu: goto label_1d50ac;
            case 0x1D50B0u: goto label_1d50b0;
            case 0x1D50B4u: goto label_1d50b4;
            case 0x1D50B8u: goto label_1d50b8;
            case 0x1D50BCu: goto label_1d50bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4CE4u;
label_1d4ce4:
    // 0x1d4ce4: 0x0  nop
    ctx->pc = 0x1d4ce4u;
    // NOP
label_1d4ce8:
    // 0x1d4ce8: 0x0  nop
    ctx->pc = 0x1d4ce8u;
    // NOP
label_1d4cec:
    // 0x1d4cec: 0x0  nop
    ctx->pc = 0x1d4cecu;
    // NOP
label_1d4cf0:
    // 0x1d4cf0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d4cf0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
label_1d4cf4:
    // 0x1d4cf4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4cf4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
label_1d4cf8:
    // 0x1d4cf8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d4cf8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
label_1d4cfc:
    // 0x1d4cfc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d4cfcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
label_1d4d00:
    // 0x1d4d00: 0x80222650  lb          $v0, 0x2650($at)
    ctx->pc = 0x1d4d00u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 9808)));
label_1d4d04:
    // 0x1d4d04: 0x14400016  bnez        $v0, . + 4 + (0x16 << 2)
label_1d4d08:
    if (ctx->pc == 0x1D4D08u) {
        ctx->pc = 0x1D4D08u;
            // 0x1d4d08: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1D4D0Cu;
        goto label_1d4d0c;
    }
    ctx->pc = 0x1D4D04u;
    {
        const bool branch_taken_0x1d4d04 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4D08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4D04u;
            // 0x1d4d08: 0x80802d  daddu       $s0, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4d04) {
            ctx->pc = 0x1D4D60u;
            goto label_1d4d60;
        }
    }
    ctx->pc = 0x1D4D0Cu;
label_1d4d0c:
    // 0x1d4d0c: 0xc07544c  jal         func_1D5130
label_1d4d10:
    if (ctx->pc == 0x1D4D10u) {
        ctx->pc = 0x1D4D10u;
            // 0x1d4d10: 0x27a4002c  addiu       $a0, $sp, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
        ctx->pc = 0x1D4D14u;
        goto label_1d4d14;
    }
    ctx->pc = 0x1D4D0Cu;
    SET_GPR_U32(ctx, 31, 0x1D4D14u);
    ctx->pc = 0x1D4D10u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4D0Cu;
            // 0x1d4d10: 0x27a4002c  addiu       $a0, $sp, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D5130u;
    if (runtime->hasFunction(0x1D5130u)) {
        auto targetFn = runtime->lookupFunction(0x1D5130u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4D14u; }
        if (ctx->pc != 0x1D4D14u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D5130_0x1d5130(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4D14u; }
        if (ctx->pc != 0x1D4D14u) { return; }
    }
    ctx->pc = 0x1D4D14u;
label_1d4d14:
    // 0x1d4d14: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_1d4d18:
    if (ctx->pc == 0x1D4D18u) {
        ctx->pc = 0x1D4D1Cu;
        goto label_1d4d1c;
    }
    ctx->pc = 0x1D4D14u;
    {
        const bool branch_taken_0x1d4d14 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1d4d14) {
            ctx->pc = 0x1D4D28u;
            goto label_1d4d28;
        }
    }
    ctx->pc = 0x1D4D1Cu;
label_1d4d1c:
    // 0x1d4d1c: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1d4d1cu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
label_1d4d20:
    // 0x1d4d20: 0x10000011  b           . + 4 + (0x11 << 2)
label_1d4d24:
    if (ctx->pc == 0x1D4D24u) {
        ctx->pc = 0x1D4D24u;
            // 0x1d4d24: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1D4D28u;
        goto label_1d4d28;
    }
    ctx->pc = 0x1D4D20u;
    {
        const bool branch_taken_0x1d4d20 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4D24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4D20u;
            // 0x1d4d24: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4d20) {
            ctx->pc = 0x1D4D68u;
            goto label_1d4d68;
        }
    }
    ctx->pc = 0x1D4D28u;
label_1d4d28:
    // 0x1d4d28: 0x8fa2002c  lw          $v0, 0x2C($sp)
    ctx->pc = 0x1d4d28u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_1d4d2c:
    // 0x1d4d2c: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
label_1d4d30:
    if (ctx->pc == 0x1D4D30u) {
        ctx->pc = 0x1D4D30u;
            // 0x1d4d30: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->pc = 0x1D4D34u;
        goto label_1d4d34;
    }
    ctx->pc = 0x1D4D2Cu;
    {
        const bool branch_taken_0x1d4d2c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4D30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4D2Cu;
            // 0x1d4d30: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4d2c) {
            ctx->pc = 0x1D4D40u;
            goto label_1d4d40;
        }
    }
    ctx->pc = 0x1D4D34u;
label_1d4d34:
    // 0x1d4d34: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1d4d34u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
label_1d4d38:
    // 0x1d4d38: 0x1000000b  b           . + 4 + (0xB << 2)
label_1d4d3c:
    if (ctx->pc == 0x1D4D3Cu) {
        ctx->pc = 0x1D4D3Cu;
            // 0x1d4d3c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1D4D40u;
        goto label_1d4d40;
    }
    ctx->pc = 0x1D4D38u;
    {
        const bool branch_taken_0x1d4d38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4D3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4D38u;
            // 0x1d4d3c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4d38) {
            ctx->pc = 0x1D4D68u;
            goto label_1d4d68;
        }
    }
    ctx->pc = 0x1D4D40u;
label_1d4d40:
    // 0x1d4d40: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d4d40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1d4d44:
    // 0x1d4d44: 0xac202678  sw          $zero, 0x2678($at)
    ctx->pc = 0x1d4d44u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 9848), GPR_U32(ctx, 0));
label_1d4d48:
    // 0x1d4d48: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4d48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
label_1d4d4c:
    // 0x1d4d4c: 0xa0222650  sb          $v0, 0x2650($at)
    ctx->pc = 0x1d4d4cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 9808), (uint8_t)GPR_U32(ctx, 2));
label_1d4d50:
    // 0x1d4d50: 0x82030000  lb          $v1, 0x0($s0)
    ctx->pc = 0x1d4d50u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
label_1d4d54:
    // 0x1d4d54: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1d4d54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
label_1d4d58:
    // 0x1d4d58: 0x10000003  b           . + 4 + (0x3 << 2)
label_1d4d5c:
    if (ctx->pc == 0x1D4D5Cu) {
        ctx->pc = 0x1D4D5Cu;
            // 0x1d4d5c: 0xa2030000  sb          $v1, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->pc = 0x1D4D60u;
        goto label_1d4d60;
    }
    ctx->pc = 0x1D4D58u;
    {
        const bool branch_taken_0x1d4d58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4D5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4D58u;
            // 0x1d4d5c: 0xa2030000  sb          $v1, 0x0($s0) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4d58) {
            ctx->pc = 0x1D4D68u;
            goto label_1d4d68;
        }
    }
    ctx->pc = 0x1D4D60u;
label_1d4d60:
    // 0x1d4d60: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1d4d60u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
label_1d4d64:
    // 0x1d4d64: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d4d64u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d4d68:
    // 0x1d4d68: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d4d68u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1d4d6c:
    // 0x1d4d6c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d4d6cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
label_1d4d70:
    // 0x1d4d70: 0x3e00008  jr          $ra
label_1d4d74:
    if (ctx->pc == 0x1D4D74u) {
        ctx->pc = 0x1D4D74u;
            // 0x1d4d74: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = 0x1D4D78u;
        goto label_1d4d78;
    }
    ctx->pc = 0x1D4D70u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4D74u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4D70u;
            // 0x1d4d74: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4CA0u: goto label_1d4ca0;
            case 0x1D4CA4u: goto label_1d4ca4;
            case 0x1D4CA8u: goto label_1d4ca8;
            case 0x1D4CACu: goto label_1d4cac;
            case 0x1D4CB0u: goto label_1d4cb0;
            case 0x1D4CB4u: goto label_1d4cb4;
            case 0x1D4CB8u: goto label_1d4cb8;
            case 0x1D4CBCu: goto label_1d4cbc;
            case 0x1D4CC0u: goto label_1d4cc0;
            case 0x1D4CC4u: goto label_1d4cc4;
            case 0x1D4CC8u: goto label_1d4cc8;
            case 0x1D4CCCu: goto label_1d4ccc;
            case 0x1D4CD0u: goto label_1d4cd0;
            case 0x1D4CD4u: goto label_1d4cd4;
            case 0x1D4CD8u: goto label_1d4cd8;
            case 0x1D4CDCu: goto label_1d4cdc;
            case 0x1D4CE0u: goto label_1d4ce0;
            case 0x1D4CE4u: goto label_1d4ce4;
            case 0x1D4CE8u: goto label_1d4ce8;
            case 0x1D4CECu: goto label_1d4cec;
            case 0x1D4CF0u: goto label_1d4cf0;
            case 0x1D4CF4u: goto label_1d4cf4;
            case 0x1D4CF8u: goto label_1d4cf8;
            case 0x1D4CFCu: goto label_1d4cfc;
            case 0x1D4D00u: goto label_1d4d00;
            case 0x1D4D04u: goto label_1d4d04;
            case 0x1D4D08u: goto label_1d4d08;
            case 0x1D4D0Cu: goto label_1d4d0c;
            case 0x1D4D10u: goto label_1d4d10;
            case 0x1D4D14u: goto label_1d4d14;
            case 0x1D4D18u: goto label_1d4d18;
            case 0x1D4D1Cu: goto label_1d4d1c;
            case 0x1D4D20u: goto label_1d4d20;
            case 0x1D4D24u: goto label_1d4d24;
            case 0x1D4D28u: goto label_1d4d28;
            case 0x1D4D2Cu: goto label_1d4d2c;
            case 0x1D4D30u: goto label_1d4d30;
            case 0x1D4D34u: goto label_1d4d34;
            case 0x1D4D38u: goto label_1d4d38;
            case 0x1D4D3Cu: goto label_1d4d3c;
            case 0x1D4D40u: goto label_1d4d40;
            case 0x1D4D44u: goto label_1d4d44;
            case 0x1D4D48u: goto label_1d4d48;
            case 0x1D4D4Cu: goto label_1d4d4c;
            case 0x1D4D50u: goto label_1d4d50;
            case 0x1D4D54u: goto label_1d4d54;
            case 0x1D4D58u: goto label_1d4d58;
            case 0x1D4D5Cu: goto label_1d4d5c;
            case 0x1D4D60u: goto label_1d4d60;
            case 0x1D4D64u: goto label_1d4d64;
            case 0x1D4D68u: goto label_1d4d68;
            case 0x1D4D6Cu: goto label_1d4d6c;
            case 0x1D4D70u: goto label_1d4d70;
            case 0x1D4D74u: goto label_1d4d74;
            case 0x1D4D78u: goto label_1d4d78;
            case 0x1D4D7Cu: goto label_1d4d7c;
            case 0x1D4D80u: goto label_1d4d80;
            case 0x1D4D84u: goto label_1d4d84;
            case 0x1D4D88u: goto label_1d4d88;
            case 0x1D4D8Cu: goto label_1d4d8c;
            case 0x1D4D90u: goto label_1d4d90;
            case 0x1D4D94u: goto label_1d4d94;
            case 0x1D4D98u: goto label_1d4d98;
            case 0x1D4D9Cu: goto label_1d4d9c;
            case 0x1D4DA0u: goto label_1d4da0;
            case 0x1D4DA4u: goto label_1d4da4;
            case 0x1D4DA8u: goto label_1d4da8;
            case 0x1D4DACu: goto label_1d4dac;
            case 0x1D4DB0u: goto label_1d4db0;
            case 0x1D4DB4u: goto label_1d4db4;
            case 0x1D4DB8u: goto label_1d4db8;
            case 0x1D4DBCu: goto label_1d4dbc;
            case 0x1D4DC0u: goto label_1d4dc0;
            case 0x1D4DC4u: goto label_1d4dc4;
            case 0x1D4DC8u: goto label_1d4dc8;
            case 0x1D4DCCu: goto label_1d4dcc;
            case 0x1D4DD0u: goto label_1d4dd0;
            case 0x1D4DD4u: goto label_1d4dd4;
            case 0x1D4DD8u: goto label_1d4dd8;
            case 0x1D4DDCu: goto label_1d4ddc;
            case 0x1D4DE0u: goto label_1d4de0;
            case 0x1D4DE4u: goto label_1d4de4;
            case 0x1D4DE8u: goto label_1d4de8;
            case 0x1D4DECu: goto label_1d4dec;
            case 0x1D4DF0u: goto label_1d4df0;
            case 0x1D4DF4u: goto label_1d4df4;
            case 0x1D4DF8u: goto label_1d4df8;
            case 0x1D4DFCu: goto label_1d4dfc;
            case 0x1D4E00u: goto label_1d4e00;
            case 0x1D4E04u: goto label_1d4e04;
            case 0x1D4E08u: goto label_1d4e08;
            case 0x1D4E0Cu: goto label_1d4e0c;
            case 0x1D4E10u: goto label_1d4e10;
            case 0x1D4E14u: goto label_1d4e14;
            case 0x1D4E18u: goto label_1d4e18;
            case 0x1D4E1Cu: goto label_1d4e1c;
            case 0x1D4E20u: goto label_1d4e20;
            case 0x1D4E24u: goto label_1d4e24;
            case 0x1D4E28u: goto label_1d4e28;
            case 0x1D4E2Cu: goto label_1d4e2c;
            case 0x1D4E30u: goto label_1d4e30;
            case 0x1D4E34u: goto label_1d4e34;
            case 0x1D4E38u: goto label_1d4e38;
            case 0x1D4E3Cu: goto label_1d4e3c;
            case 0x1D4E40u: goto label_1d4e40;
            case 0x1D4E44u: goto label_1d4e44;
            case 0x1D4E48u: goto label_1d4e48;
            case 0x1D4E4Cu: goto label_1d4e4c;
            case 0x1D4E50u: goto label_1d4e50;
            case 0x1D4E54u: goto label_1d4e54;
            case 0x1D4E58u: goto label_1d4e58;
            case 0x1D4E5Cu: goto label_1d4e5c;
            case 0x1D4E60u: goto label_1d4e60;
            case 0x1D4E64u: goto label_1d4e64;
            case 0x1D4E68u: goto label_1d4e68;
            case 0x1D4E6Cu: goto label_1d4e6c;
            case 0x1D4E70u: goto label_1d4e70;
            case 0x1D4E74u: goto label_1d4e74;
            case 0x1D4E78u: goto label_1d4e78;
            case 0x1D4E7Cu: goto label_1d4e7c;
            case 0x1D4E80u: goto label_1d4e80;
            case 0x1D4E84u: goto label_1d4e84;
            case 0x1D4E88u: goto label_1d4e88;
            case 0x1D4E8Cu: goto label_1d4e8c;
            case 0x1D4E90u: goto label_1d4e90;
            case 0x1D4E94u: goto label_1d4e94;
            case 0x1D4E98u: goto label_1d4e98;
            case 0x1D4E9Cu: goto label_1d4e9c;
            case 0x1D4EA0u: goto label_1d4ea0;
            case 0x1D4EA4u: goto label_1d4ea4;
            case 0x1D4EA8u: goto label_1d4ea8;
            case 0x1D4EACu: goto label_1d4eac;
            case 0x1D4EB0u: goto label_1d4eb0;
            case 0x1D4EB4u: goto label_1d4eb4;
            case 0x1D4EB8u: goto label_1d4eb8;
            case 0x1D4EBCu: goto label_1d4ebc;
            case 0x1D4EC0u: goto label_1d4ec0;
            case 0x1D4EC4u: goto label_1d4ec4;
            case 0x1D4EC8u: goto label_1d4ec8;
            case 0x1D4ECCu: goto label_1d4ecc;
            case 0x1D4ED0u: goto label_1d4ed0;
            case 0x1D4ED4u: goto label_1d4ed4;
            case 0x1D4ED8u: goto label_1d4ed8;
            case 0x1D4EDCu: goto label_1d4edc;
            case 0x1D4EE0u: goto label_1d4ee0;
            case 0x1D4EE4u: goto label_1d4ee4;
            case 0x1D4EE8u: goto label_1d4ee8;
            case 0x1D4EECu: goto label_1d4eec;
            case 0x1D4EF0u: goto label_1d4ef0;
            case 0x1D4EF4u: goto label_1d4ef4;
            case 0x1D4EF8u: goto label_1d4ef8;
            case 0x1D4EFCu: goto label_1d4efc;
            case 0x1D4F00u: goto label_1d4f00;
            case 0x1D4F04u: goto label_1d4f04;
            case 0x1D4F08u: goto label_1d4f08;
            case 0x1D4F0Cu: goto label_1d4f0c;
            case 0x1D4F10u: goto label_1d4f10;
            case 0x1D4F14u: goto label_1d4f14;
            case 0x1D4F18u: goto label_1d4f18;
            case 0x1D4F1Cu: goto label_1d4f1c;
            case 0x1D4F20u: goto label_1d4f20;
            case 0x1D4F24u: goto label_1d4f24;
            case 0x1D4F28u: goto label_1d4f28;
            case 0x1D4F2Cu: goto label_1d4f2c;
            case 0x1D4F30u: goto label_1d4f30;
            case 0x1D4F34u: goto label_1d4f34;
            case 0x1D4F38u: goto label_1d4f38;
            case 0x1D4F3Cu: goto label_1d4f3c;
            case 0x1D4F40u: goto label_1d4f40;
            case 0x1D4F44u: goto label_1d4f44;
            case 0x1D4F48u: goto label_1d4f48;
            case 0x1D4F4Cu: goto label_1d4f4c;
            case 0x1D4F50u: goto label_1d4f50;
            case 0x1D4F54u: goto label_1d4f54;
            case 0x1D4F58u: goto label_1d4f58;
            case 0x1D4F5Cu: goto label_1d4f5c;
            case 0x1D4F60u: goto label_1d4f60;
            case 0x1D4F64u: goto label_1d4f64;
            case 0x1D4F68u: goto label_1d4f68;
            case 0x1D4F6Cu: goto label_1d4f6c;
            case 0x1D4F70u: goto label_1d4f70;
            case 0x1D4F74u: goto label_1d4f74;
            case 0x1D4F78u: goto label_1d4f78;
            case 0x1D4F7Cu: goto label_1d4f7c;
            case 0x1D4F80u: goto label_1d4f80;
            case 0x1D4F84u: goto label_1d4f84;
            case 0x1D4F88u: goto label_1d4f88;
            case 0x1D4F8Cu: goto label_1d4f8c;
            case 0x1D4F90u: goto label_1d4f90;
            case 0x1D4F94u: goto label_1d4f94;
            case 0x1D4F98u: goto label_1d4f98;
            case 0x1D4F9Cu: goto label_1d4f9c;
            case 0x1D4FA0u: goto label_1d4fa0;
            case 0x1D4FA4u: goto label_1d4fa4;
            case 0x1D4FA8u: goto label_1d4fa8;
            case 0x1D4FACu: goto label_1d4fac;
            case 0x1D4FB0u: goto label_1d4fb0;
            case 0x1D4FB4u: goto label_1d4fb4;
            case 0x1D4FB8u: goto label_1d4fb8;
            case 0x1D4FBCu: goto label_1d4fbc;
            case 0x1D4FC0u: goto label_1d4fc0;
            case 0x1D4FC4u: goto label_1d4fc4;
            case 0x1D4FC8u: goto label_1d4fc8;
            case 0x1D4FCCu: goto label_1d4fcc;
            case 0x1D4FD0u: goto label_1d4fd0;
            case 0x1D4FD4u: goto label_1d4fd4;
            case 0x1D4FD8u: goto label_1d4fd8;
            case 0x1D4FDCu: goto label_1d4fdc;
            case 0x1D4FE0u: goto label_1d4fe0;
            case 0x1D4FE4u: goto label_1d4fe4;
            case 0x1D4FE8u: goto label_1d4fe8;
            case 0x1D4FECu: goto label_1d4fec;
            case 0x1D4FF0u: goto label_1d4ff0;
            case 0x1D4FF4u: goto label_1d4ff4;
            case 0x1D4FF8u: goto label_1d4ff8;
            case 0x1D4FFCu: goto label_1d4ffc;
            case 0x1D5000u: goto label_1d5000;
            case 0x1D5004u: goto label_1d5004;
            case 0x1D5008u: goto label_1d5008;
            case 0x1D500Cu: goto label_1d500c;
            case 0x1D5010u: goto label_1d5010;
            case 0x1D5014u: goto label_1d5014;
            case 0x1D5018u: goto label_1d5018;
            case 0x1D501Cu: goto label_1d501c;
            case 0x1D5020u: goto label_1d5020;
            case 0x1D5024u: goto label_1d5024;
            case 0x1D5028u: goto label_1d5028;
            case 0x1D502Cu: goto label_1d502c;
            case 0x1D5030u: goto label_1d5030;
            case 0x1D5034u: goto label_1d5034;
            case 0x1D5038u: goto label_1d5038;
            case 0x1D503Cu: goto label_1d503c;
            case 0x1D5040u: goto label_1d5040;
            case 0x1D5044u: goto label_1d5044;
            case 0x1D5048u: goto label_1d5048;
            case 0x1D504Cu: goto label_1d504c;
            case 0x1D5050u: goto label_1d5050;
            case 0x1D5054u: goto label_1d5054;
            case 0x1D5058u: goto label_1d5058;
            case 0x1D505Cu: goto label_1d505c;
            case 0x1D5060u: goto label_1d5060;
            case 0x1D5064u: goto label_1d5064;
            case 0x1D5068u: goto label_1d5068;
            case 0x1D506Cu: goto label_1d506c;
            case 0x1D5070u: goto label_1d5070;
            case 0x1D5074u: goto label_1d5074;
            case 0x1D5078u: goto label_1d5078;
            case 0x1D507Cu: goto label_1d507c;
            case 0x1D5080u: goto label_1d5080;
            case 0x1D5084u: goto label_1d5084;
            case 0x1D5088u: goto label_1d5088;
            case 0x1D508Cu: goto label_1d508c;
            case 0x1D5090u: goto label_1d5090;
            case 0x1D5094u: goto label_1d5094;
            case 0x1D5098u: goto label_1d5098;
            case 0x1D509Cu: goto label_1d509c;
            case 0x1D50A0u: goto label_1d50a0;
            case 0x1D50A4u: goto label_1d50a4;
            case 0x1D50A8u: goto label_1d50a8;
            case 0x1D50ACu: goto label_1d50ac;
            case 0x1D50B0u: goto label_1d50b0;
            case 0x1D50B4u: goto label_1d50b4;
            case 0x1D50B8u: goto label_1d50b8;
            case 0x1D50BCu: goto label_1d50bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4D78u;
label_1d4d78:
    // 0x1d4d78: 0x0  nop
    ctx->pc = 0x1d4d78u;
    // NOP
label_1d4d7c:
    // 0x1d4d7c: 0x0  nop
    ctx->pc = 0x1d4d7cu;
    // NOP
label_1d4d80:
    // 0x1d4d80: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d4d80u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
label_1d4d84:
    // 0x1d4d84: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d4d84u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
label_1d4d88:
    // 0x1d4d88: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d4d88u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
label_1d4d8c:
    // 0x1d4d8c: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1d4d8cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_1d4d90:
    // 0x1d4d90: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1d4d90u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
label_1d4d94:
    // 0x1d4d94: 0xc0754fc  jal         func_1D53F0
label_1d4d98:
    if (ctx->pc == 0x1D4D98u) {
        ctx->pc = 0x1D4D98u;
            // 0x1d4d98: 0x24842720  addiu       $a0, $a0, 0x2720 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10016));
        ctx->pc = 0x1D4D9Cu;
        goto label_1d4d9c;
    }
    ctx->pc = 0x1D4D94u;
    SET_GPR_U32(ctx, 31, 0x1D4D9Cu);
    ctx->pc = 0x1D4D98u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4D94u;
            // 0x1d4d98: 0x24842720  addiu       $a0, $a0, 0x2720 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10016));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D53F0u;
    if (runtime->hasFunction(0x1D53F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D53F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4D9Cu; }
        if (ctx->pc != 0x1D4D9Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D53F0_0x1d53f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4D9Cu; }
        if (ctx->pc != 0x1D4D9Cu) { return; }
    }
    ctx->pc = 0x1D4D9Cu;
label_1d4d9c:
    // 0x1d4d9c: 0xafa2002c  sw          $v0, 0x2C($sp)
    ctx->pc = 0x1d4d9cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
label_1d4da0:
    // 0x1d4da0: 0x8fa2002c  lw          $v0, 0x2C($sp)
    ctx->pc = 0x1d4da0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_1d4da4:
    // 0x1d4da4: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
label_1d4da8:
    if (ctx->pc == 0x1D4DA8u) {
        ctx->pc = 0x1D4DA8u;
            // 0x1d4da8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1D4DACu;
        goto label_1d4dac;
    }
    ctx->pc = 0x1D4DA4u;
    {
        const bool branch_taken_0x1d4da4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4DA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4DA4u;
            // 0x1d4da8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4da4) {
            ctx->pc = 0x1D4DB8u;
            goto label_1d4db8;
        }
    }
    ctx->pc = 0x1D4DACu;
label_1d4dac:
    // 0x1d4dac: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1d4dacu;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
label_1d4db0:
    // 0x1d4db0: 0x10000017  b           . + 4 + (0x17 << 2)
label_1d4db4:
    if (ctx->pc == 0x1D4DB4u) {
        ctx->pc = 0x1D4DB4u;
            // 0x1d4db4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1D4DB8u;
        goto label_1d4db8;
    }
    ctx->pc = 0x1D4DB0u;
    {
        const bool branch_taken_0x1d4db0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4DB4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4DB0u;
            // 0x1d4db4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4db0) {
            ctx->pc = 0x1D4E10u;
            goto label_1d4e10;
        }
    }
    ctx->pc = 0x1D4DB8u;
label_1d4db8:
    // 0x1d4db8: 0xc075646  jal         func_1D5918
label_1d4dbc:
    if (ctx->pc == 0x1D4DBCu) {
        ctx->pc = 0x1D4DBCu;
            // 0x1d4dbc: 0x27a5002c  addiu       $a1, $sp, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
        ctx->pc = 0x1D4DC0u;
        goto label_1d4dc0;
    }
    ctx->pc = 0x1D4DB8u;
    SET_GPR_U32(ctx, 31, 0x1D4DC0u);
    ctx->pc = 0x1D4DBCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4DB8u;
            // 0x1d4dbc: 0x27a5002c  addiu       $a1, $sp, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D5918u;
    if (runtime->hasFunction(0x1D5918u)) {
        auto targetFn = runtime->lookupFunction(0x1D5918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4DC0u; }
        if (ctx->pc != 0x1D4DC0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D5918_0x1d5918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4DC0u; }
        if (ctx->pc != 0x1D4DC0u) { return; }
    }
    ctx->pc = 0x1D4DC0u;
label_1d4dc0:
    // 0x1d4dc0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4dc0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
label_1d4dc4:
    // 0x1d4dc4: 0xac222678  sw          $v0, 0x2678($at)
    ctx->pc = 0x1d4dc4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 9848), GPR_U32(ctx, 2));
label_1d4dc8:
    // 0x1d4dc8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4dc8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
label_1d4dcc:
    // 0x1d4dcc: 0x8c222678  lw          $v0, 0x2678($at)
    ctx->pc = 0x1d4dccu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 9848)));
label_1d4dd0:
    // 0x1d4dd0: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
label_1d4dd4:
    if (ctx->pc == 0x1D4DD4u) {
        ctx->pc = 0x1D4DD8u;
        goto label_1d4dd8;
    }
    ctx->pc = 0x1D4DD0u;
    {
        const bool branch_taken_0x1d4dd0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d4dd0) {
            ctx->pc = 0x1D4E0Cu;
            goto label_1d4e0c;
        }
    }
    ctx->pc = 0x1D4DD8u;
label_1d4dd8:
    // 0x1d4dd8: 0x8fa2002c  lw          $v0, 0x2C($sp)
    ctx->pc = 0x1d4dd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_1d4ddc:
    // 0x1d4ddc: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
label_1d4de0:
    if (ctx->pc == 0x1D4DE0u) {
        ctx->pc = 0x1D4DE0u;
            // 0x1d4de0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x1D4DE4u;
        goto label_1d4de4;
    }
    ctx->pc = 0x1D4DDCu;
    {
        const bool branch_taken_0x1d4ddc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4DE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4DDCu;
            // 0x1d4de0: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4ddc) {
            ctx->pc = 0x1D4E10u;
            goto label_1d4e10;
        }
    }
    ctx->pc = 0x1D4DE4u;
label_1d4de4:
    // 0x1d4de4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4de4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
label_1d4de8:
    // 0x1d4de8: 0x8c222724  lw          $v0, 0x2724($at)
    ctx->pc = 0x1d4de8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 10020)));
label_1d4dec:
    // 0x1d4dec: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
label_1d4df0:
    if (ctx->pc == 0x1D4DF0u) {
        ctx->pc = 0x1D4DF4u;
        goto label_1d4df4;
    }
    ctx->pc = 0x1D4DECu;
    {
        const bool branch_taken_0x1d4dec = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d4dec) {
            ctx->pc = 0x1D4E00u;
            goto label_1d4e00;
        }
    }
    ctx->pc = 0x1D4DF4u;
label_1d4df4:
    // 0x1d4df4: 0xa2000000  sb          $zero, 0x0($s0)
    ctx->pc = 0x1d4df4u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 0));
label_1d4df8:
    // 0x1d4df8: 0x10000005  b           . + 4 + (0x5 << 2)
label_1d4dfc:
    if (ctx->pc == 0x1D4DFCu) {
        ctx->pc = 0x1D4DFCu;
            // 0x1d4dfc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1D4E00u;
        goto label_1d4e00;
    }
    ctx->pc = 0x1D4DF8u;
    {
        const bool branch_taken_0x1d4df8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4DFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4DF8u;
            // 0x1d4dfc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4df8) {
            ctx->pc = 0x1D4E10u;
            goto label_1d4e10;
        }
    }
    ctx->pc = 0x1D4E00u;
label_1d4e00:
    // 0x1d4e00: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x1d4e00u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
label_1d4e04:
    // 0x1d4e04: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1d4e04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1d4e08:
    // 0x1d4e08: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1d4e08u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
label_1d4e0c:
    // 0x1d4e0c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d4e0cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1d4e10:
    // 0x1d4e10: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d4e10u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1d4e14:
    // 0x1d4e14: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d4e14u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
label_1d4e18:
    // 0x1d4e18: 0x3e00008  jr          $ra
label_1d4e1c:
    if (ctx->pc == 0x1D4E1Cu) {
        ctx->pc = 0x1D4E1Cu;
            // 0x1d4e1c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = 0x1D4E20u;
        goto label_1d4e20;
    }
    ctx->pc = 0x1D4E18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4E1Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4E18u;
            // 0x1d4e1c: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4CA0u: goto label_1d4ca0;
            case 0x1D4CA4u: goto label_1d4ca4;
            case 0x1D4CA8u: goto label_1d4ca8;
            case 0x1D4CACu: goto label_1d4cac;
            case 0x1D4CB0u: goto label_1d4cb0;
            case 0x1D4CB4u: goto label_1d4cb4;
            case 0x1D4CB8u: goto label_1d4cb8;
            case 0x1D4CBCu: goto label_1d4cbc;
            case 0x1D4CC0u: goto label_1d4cc0;
            case 0x1D4CC4u: goto label_1d4cc4;
            case 0x1D4CC8u: goto label_1d4cc8;
            case 0x1D4CCCu: goto label_1d4ccc;
            case 0x1D4CD0u: goto label_1d4cd0;
            case 0x1D4CD4u: goto label_1d4cd4;
            case 0x1D4CD8u: goto label_1d4cd8;
            case 0x1D4CDCu: goto label_1d4cdc;
            case 0x1D4CE0u: goto label_1d4ce0;
            case 0x1D4CE4u: goto label_1d4ce4;
            case 0x1D4CE8u: goto label_1d4ce8;
            case 0x1D4CECu: goto label_1d4cec;
            case 0x1D4CF0u: goto label_1d4cf0;
            case 0x1D4CF4u: goto label_1d4cf4;
            case 0x1D4CF8u: goto label_1d4cf8;
            case 0x1D4CFCu: goto label_1d4cfc;
            case 0x1D4D00u: goto label_1d4d00;
            case 0x1D4D04u: goto label_1d4d04;
            case 0x1D4D08u: goto label_1d4d08;
            case 0x1D4D0Cu: goto label_1d4d0c;
            case 0x1D4D10u: goto label_1d4d10;
            case 0x1D4D14u: goto label_1d4d14;
            case 0x1D4D18u: goto label_1d4d18;
            case 0x1D4D1Cu: goto label_1d4d1c;
            case 0x1D4D20u: goto label_1d4d20;
            case 0x1D4D24u: goto label_1d4d24;
            case 0x1D4D28u: goto label_1d4d28;
            case 0x1D4D2Cu: goto label_1d4d2c;
            case 0x1D4D30u: goto label_1d4d30;
            case 0x1D4D34u: goto label_1d4d34;
            case 0x1D4D38u: goto label_1d4d38;
            case 0x1D4D3Cu: goto label_1d4d3c;
            case 0x1D4D40u: goto label_1d4d40;
            case 0x1D4D44u: goto label_1d4d44;
            case 0x1D4D48u: goto label_1d4d48;
            case 0x1D4D4Cu: goto label_1d4d4c;
            case 0x1D4D50u: goto label_1d4d50;
            case 0x1D4D54u: goto label_1d4d54;
            case 0x1D4D58u: goto label_1d4d58;
            case 0x1D4D5Cu: goto label_1d4d5c;
            case 0x1D4D60u: goto label_1d4d60;
            case 0x1D4D64u: goto label_1d4d64;
            case 0x1D4D68u: goto label_1d4d68;
            case 0x1D4D6Cu: goto label_1d4d6c;
            case 0x1D4D70u: goto label_1d4d70;
            case 0x1D4D74u: goto label_1d4d74;
            case 0x1D4D78u: goto label_1d4d78;
            case 0x1D4D7Cu: goto label_1d4d7c;
            case 0x1D4D80u: goto label_1d4d80;
            case 0x1D4D84u: goto label_1d4d84;
            case 0x1D4D88u: goto label_1d4d88;
            case 0x1D4D8Cu: goto label_1d4d8c;
            case 0x1D4D90u: goto label_1d4d90;
            case 0x1D4D94u: goto label_1d4d94;
            case 0x1D4D98u: goto label_1d4d98;
            case 0x1D4D9Cu: goto label_1d4d9c;
            case 0x1D4DA0u: goto label_1d4da0;
            case 0x1D4DA4u: goto label_1d4da4;
            case 0x1D4DA8u: goto label_1d4da8;
            case 0x1D4DACu: goto label_1d4dac;
            case 0x1D4DB0u: goto label_1d4db0;
            case 0x1D4DB4u: goto label_1d4db4;
            case 0x1D4DB8u: goto label_1d4db8;
            case 0x1D4DBCu: goto label_1d4dbc;
            case 0x1D4DC0u: goto label_1d4dc0;
            case 0x1D4DC4u: goto label_1d4dc4;
            case 0x1D4DC8u: goto label_1d4dc8;
            case 0x1D4DCCu: goto label_1d4dcc;
            case 0x1D4DD0u: goto label_1d4dd0;
            case 0x1D4DD4u: goto label_1d4dd4;
            case 0x1D4DD8u: goto label_1d4dd8;
            case 0x1D4DDCu: goto label_1d4ddc;
            case 0x1D4DE0u: goto label_1d4de0;
            case 0x1D4DE4u: goto label_1d4de4;
            case 0x1D4DE8u: goto label_1d4de8;
            case 0x1D4DECu: goto label_1d4dec;
            case 0x1D4DF0u: goto label_1d4df0;
            case 0x1D4DF4u: goto label_1d4df4;
            case 0x1D4DF8u: goto label_1d4df8;
            case 0x1D4DFCu: goto label_1d4dfc;
            case 0x1D4E00u: goto label_1d4e00;
            case 0x1D4E04u: goto label_1d4e04;
            case 0x1D4E08u: goto label_1d4e08;
            case 0x1D4E0Cu: goto label_1d4e0c;
            case 0x1D4E10u: goto label_1d4e10;
            case 0x1D4E14u: goto label_1d4e14;
            case 0x1D4E18u: goto label_1d4e18;
            case 0x1D4E1Cu: goto label_1d4e1c;
            case 0x1D4E20u: goto label_1d4e20;
            case 0x1D4E24u: goto label_1d4e24;
            case 0x1D4E28u: goto label_1d4e28;
            case 0x1D4E2Cu: goto label_1d4e2c;
            case 0x1D4E30u: goto label_1d4e30;
            case 0x1D4E34u: goto label_1d4e34;
            case 0x1D4E38u: goto label_1d4e38;
            case 0x1D4E3Cu: goto label_1d4e3c;
            case 0x1D4E40u: goto label_1d4e40;
            case 0x1D4E44u: goto label_1d4e44;
            case 0x1D4E48u: goto label_1d4e48;
            case 0x1D4E4Cu: goto label_1d4e4c;
            case 0x1D4E50u: goto label_1d4e50;
            case 0x1D4E54u: goto label_1d4e54;
            case 0x1D4E58u: goto label_1d4e58;
            case 0x1D4E5Cu: goto label_1d4e5c;
            case 0x1D4E60u: goto label_1d4e60;
            case 0x1D4E64u: goto label_1d4e64;
            case 0x1D4E68u: goto label_1d4e68;
            case 0x1D4E6Cu: goto label_1d4e6c;
            case 0x1D4E70u: goto label_1d4e70;
            case 0x1D4E74u: goto label_1d4e74;
            case 0x1D4E78u: goto label_1d4e78;
            case 0x1D4E7Cu: goto label_1d4e7c;
            case 0x1D4E80u: goto label_1d4e80;
            case 0x1D4E84u: goto label_1d4e84;
            case 0x1D4E88u: goto label_1d4e88;
            case 0x1D4E8Cu: goto label_1d4e8c;
            case 0x1D4E90u: goto label_1d4e90;
            case 0x1D4E94u: goto label_1d4e94;
            case 0x1D4E98u: goto label_1d4e98;
            case 0x1D4E9Cu: goto label_1d4e9c;
            case 0x1D4EA0u: goto label_1d4ea0;
            case 0x1D4EA4u: goto label_1d4ea4;
            case 0x1D4EA8u: goto label_1d4ea8;
            case 0x1D4EACu: goto label_1d4eac;
            case 0x1D4EB0u: goto label_1d4eb0;
            case 0x1D4EB4u: goto label_1d4eb4;
            case 0x1D4EB8u: goto label_1d4eb8;
            case 0x1D4EBCu: goto label_1d4ebc;
            case 0x1D4EC0u: goto label_1d4ec0;
            case 0x1D4EC4u: goto label_1d4ec4;
            case 0x1D4EC8u: goto label_1d4ec8;
            case 0x1D4ECCu: goto label_1d4ecc;
            case 0x1D4ED0u: goto label_1d4ed0;
            case 0x1D4ED4u: goto label_1d4ed4;
            case 0x1D4ED8u: goto label_1d4ed8;
            case 0x1D4EDCu: goto label_1d4edc;
            case 0x1D4EE0u: goto label_1d4ee0;
            case 0x1D4EE4u: goto label_1d4ee4;
            case 0x1D4EE8u: goto label_1d4ee8;
            case 0x1D4EECu: goto label_1d4eec;
            case 0x1D4EF0u: goto label_1d4ef0;
            case 0x1D4EF4u: goto label_1d4ef4;
            case 0x1D4EF8u: goto label_1d4ef8;
            case 0x1D4EFCu: goto label_1d4efc;
            case 0x1D4F00u: goto label_1d4f00;
            case 0x1D4F04u: goto label_1d4f04;
            case 0x1D4F08u: goto label_1d4f08;
            case 0x1D4F0Cu: goto label_1d4f0c;
            case 0x1D4F10u: goto label_1d4f10;
            case 0x1D4F14u: goto label_1d4f14;
            case 0x1D4F18u: goto label_1d4f18;
            case 0x1D4F1Cu: goto label_1d4f1c;
            case 0x1D4F20u: goto label_1d4f20;
            case 0x1D4F24u: goto label_1d4f24;
            case 0x1D4F28u: goto label_1d4f28;
            case 0x1D4F2Cu: goto label_1d4f2c;
            case 0x1D4F30u: goto label_1d4f30;
            case 0x1D4F34u: goto label_1d4f34;
            case 0x1D4F38u: goto label_1d4f38;
            case 0x1D4F3Cu: goto label_1d4f3c;
            case 0x1D4F40u: goto label_1d4f40;
            case 0x1D4F44u: goto label_1d4f44;
            case 0x1D4F48u: goto label_1d4f48;
            case 0x1D4F4Cu: goto label_1d4f4c;
            case 0x1D4F50u: goto label_1d4f50;
            case 0x1D4F54u: goto label_1d4f54;
            case 0x1D4F58u: goto label_1d4f58;
            case 0x1D4F5Cu: goto label_1d4f5c;
            case 0x1D4F60u: goto label_1d4f60;
            case 0x1D4F64u: goto label_1d4f64;
            case 0x1D4F68u: goto label_1d4f68;
            case 0x1D4F6Cu: goto label_1d4f6c;
            case 0x1D4F70u: goto label_1d4f70;
            case 0x1D4F74u: goto label_1d4f74;
            case 0x1D4F78u: goto label_1d4f78;
            case 0x1D4F7Cu: goto label_1d4f7c;
            case 0x1D4F80u: goto label_1d4f80;
            case 0x1D4F84u: goto label_1d4f84;
            case 0x1D4F88u: goto label_1d4f88;
            case 0x1D4F8Cu: goto label_1d4f8c;
            case 0x1D4F90u: goto label_1d4f90;
            case 0x1D4F94u: goto label_1d4f94;
            case 0x1D4F98u: goto label_1d4f98;
            case 0x1D4F9Cu: goto label_1d4f9c;
            case 0x1D4FA0u: goto label_1d4fa0;
            case 0x1D4FA4u: goto label_1d4fa4;
            case 0x1D4FA8u: goto label_1d4fa8;
            case 0x1D4FACu: goto label_1d4fac;
            case 0x1D4FB0u: goto label_1d4fb0;
            case 0x1D4FB4u: goto label_1d4fb4;
            case 0x1D4FB8u: goto label_1d4fb8;
            case 0x1D4FBCu: goto label_1d4fbc;
            case 0x1D4FC0u: goto label_1d4fc0;
            case 0x1D4FC4u: goto label_1d4fc4;
            case 0x1D4FC8u: goto label_1d4fc8;
            case 0x1D4FCCu: goto label_1d4fcc;
            case 0x1D4FD0u: goto label_1d4fd0;
            case 0x1D4FD4u: goto label_1d4fd4;
            case 0x1D4FD8u: goto label_1d4fd8;
            case 0x1D4FDCu: goto label_1d4fdc;
            case 0x1D4FE0u: goto label_1d4fe0;
            case 0x1D4FE4u: goto label_1d4fe4;
            case 0x1D4FE8u: goto label_1d4fe8;
            case 0x1D4FECu: goto label_1d4fec;
            case 0x1D4FF0u: goto label_1d4ff0;
            case 0x1D4FF4u: goto label_1d4ff4;
            case 0x1D4FF8u: goto label_1d4ff8;
            case 0x1D4FFCu: goto label_1d4ffc;
            case 0x1D5000u: goto label_1d5000;
            case 0x1D5004u: goto label_1d5004;
            case 0x1D5008u: goto label_1d5008;
            case 0x1D500Cu: goto label_1d500c;
            case 0x1D5010u: goto label_1d5010;
            case 0x1D5014u: goto label_1d5014;
            case 0x1D5018u: goto label_1d5018;
            case 0x1D501Cu: goto label_1d501c;
            case 0x1D5020u: goto label_1d5020;
            case 0x1D5024u: goto label_1d5024;
            case 0x1D5028u: goto label_1d5028;
            case 0x1D502Cu: goto label_1d502c;
            case 0x1D5030u: goto label_1d5030;
            case 0x1D5034u: goto label_1d5034;
            case 0x1D5038u: goto label_1d5038;
            case 0x1D503Cu: goto label_1d503c;
            case 0x1D5040u: goto label_1d5040;
            case 0x1D5044u: goto label_1d5044;
            case 0x1D5048u: goto label_1d5048;
            case 0x1D504Cu: goto label_1d504c;
            case 0x1D5050u: goto label_1d5050;
            case 0x1D5054u: goto label_1d5054;
            case 0x1D5058u: goto label_1d5058;
            case 0x1D505Cu: goto label_1d505c;
            case 0x1D5060u: goto label_1d5060;
            case 0x1D5064u: goto label_1d5064;
            case 0x1D5068u: goto label_1d5068;
            case 0x1D506Cu: goto label_1d506c;
            case 0x1D5070u: goto label_1d5070;
            case 0x1D5074u: goto label_1d5074;
            case 0x1D5078u: goto label_1d5078;
            case 0x1D507Cu: goto label_1d507c;
            case 0x1D5080u: goto label_1d5080;
            case 0x1D5084u: goto label_1d5084;
            case 0x1D5088u: goto label_1d5088;
            case 0x1D508Cu: goto label_1d508c;
            case 0x1D5090u: goto label_1d5090;
            case 0x1D5094u: goto label_1d5094;
            case 0x1D5098u: goto label_1d5098;
            case 0x1D509Cu: goto label_1d509c;
            case 0x1D50A0u: goto label_1d50a0;
            case 0x1D50A4u: goto label_1d50a4;
            case 0x1D50A8u: goto label_1d50a8;
            case 0x1D50ACu: goto label_1d50ac;
            case 0x1D50B0u: goto label_1d50b0;
            case 0x1D50B4u: goto label_1d50b4;
            case 0x1D50B8u: goto label_1d50b8;
            case 0x1D50BCu: goto label_1d50bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4E20u;
label_1d4e20:
    // 0x1d4e20: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x1d4e20u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
label_1d4e24:
    // 0x1d4e24: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4e24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
label_1d4e28:
    // 0x1d4e28: 0xffbf0040  sd          $ra, 0x40($sp)
    ctx->pc = 0x1d4e28u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 31));
label_1d4e2c:
    // 0x1d4e2c: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1d4e2cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
label_1d4e30:
    // 0x1d4e30: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1d4e30u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
label_1d4e34:
    // 0x1d4e34: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1d4e34u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
label_1d4e38:
    // 0x1d4e38: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d4e38u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
label_1d4e3c:
    // 0x1d4e3c: 0x90222728  lbu         $v0, 0x2728($at)
    ctx->pc = 0x1d4e3cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 10024)));
label_1d4e40:
    // 0x1d4e40: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
label_1d4e44:
    if (ctx->pc == 0x1D4E44u) {
        ctx->pc = 0x1D4E44u;
            // 0x1d4e44: 0x80982d  daddu       $s3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1D4E48u;
        goto label_1d4e48;
    }
    ctx->pc = 0x1D4E40u;
    {
        const bool branch_taken_0x1d4e40 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4E44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4E40u;
            // 0x1d4e44: 0x80982d  daddu       $s3, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4e40) {
            ctx->pc = 0x1D4E54u;
            goto label_1d4e54;
        }
    }
    ctx->pc = 0x1D4E48u;
label_1d4e48:
    // 0x1d4e48: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1d4e48u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
label_1d4e4c:
    // 0x1d4e4c: 0x10000021  b           . + 4 + (0x21 << 2)
label_1d4e50:
    if (ctx->pc == 0x1D4E50u) {
        ctx->pc = 0x1D4E50u;
            // 0x1d4e50: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1D4E54u;
        goto label_1d4e54;
    }
    ctx->pc = 0x1D4E4Cu;
    {
        const bool branch_taken_0x1d4e4c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4E50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4E4Cu;
            // 0x1d4e50: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4e4c) {
            ctx->pc = 0x1D4ED4u;
            goto label_1d4ed4;
        }
    }
    ctx->pc = 0x1D4E54u;
label_1d4e54:
    // 0x1d4e54: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d4e54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d4e58:
    // 0x1d4e58: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d4e58u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d4e5c:
    // 0x1d4e5c: 0xc07560c  jal         func_1D5830
label_1d4e60:
    if (ctx->pc == 0x1D4E60u) {
        ctx->pc = 0x1D4E60u;
            // 0x1d4e60: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1D4E64u;
        goto label_1d4e64;
    }
    ctx->pc = 0x1D4E5Cu;
    SET_GPR_U32(ctx, 31, 0x1D4E64u);
    ctx->pc = 0x1D4E60u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4E5Cu;
            // 0x1d4e60: 0x302d  daddu       $a2, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D5830u;
    if (runtime->hasFunction(0x1D5830u)) {
        auto targetFn = runtime->lookupFunction(0x1D5830u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4E64u; }
        if (ctx->pc != 0x1D4E64u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D5830_0x1d5830(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4E64u; }
        if (ctx->pc != 0x1D4E64u) { return; }
    }
    ctx->pc = 0x1D4E64u;
label_1d4e64:
    // 0x1d4e64: 0x40902d  daddu       $s2, $v0, $zero
    ctx->pc = 0x1d4e64u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1d4e68:
    // 0x1d4e68: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d4e68u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d4e6c:
    // 0x1d4e6c: 0xc07561e  jal         func_1D5878
label_1d4e70:
    if (ctx->pc == 0x1D4E70u) {
        ctx->pc = 0x1D4E70u;
            // 0x1d4e70: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1D4E74u;
        goto label_1d4e74;
    }
    ctx->pc = 0x1D4E6Cu;
    SET_GPR_U32(ctx, 31, 0x1D4E74u);
    ctx->pc = 0x1D4E70u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4E6Cu;
            // 0x1d4e70: 0x282d  daddu       $a1, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D5878u;
    if (runtime->hasFunction(0x1D5878u)) {
        auto targetFn = runtime->lookupFunction(0x1D5878u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4E74u; }
        if (ctx->pc != 0x1D4E74u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D5878_0x1d5878(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4E74u; }
        if (ctx->pc != 0x1D4E74u) { return; }
    }
    ctx->pc = 0x1D4E74u;
label_1d4e74:
    // 0x1d4e74: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1d4e74u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1d4e78:
    // 0x1d4e78: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4e78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
label_1d4e7c:
    // 0x1d4e7c: 0x40882d  daddu       $s1, $v0, $zero
    ctx->pc = 0x1d4e7cu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1d4e80:
    // 0x1d4e80: 0xac252688  sw          $a1, 0x2688($at)
    ctx->pc = 0x1d4e80u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 9864), GPR_U32(ctx, 5));
label_1d4e84:
    // 0x1d4e84: 0xc075632  jal         func_1D58C8
label_1d4e88:
    if (ctx->pc == 0x1D4E88u) {
        ctx->pc = 0x1D4E88u;
            // 0x1d4e88: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1D4E8Cu;
        goto label_1d4e8c;
    }
    ctx->pc = 0x1D4E84u;
    SET_GPR_U32(ctx, 31, 0x1D4E8Cu);
    ctx->pc = 0x1D4E88u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4E84u;
            // 0x1d4e88: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D58C8u;
    if (runtime->hasFunction(0x1D58C8u)) {
        auto targetFn = runtime->lookupFunction(0x1D58C8u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4E8Cu; }
        if (ctx->pc != 0x1D4E8Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D58C8_0x1d58c8(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4E8Cu; }
        if (ctx->pc != 0x1D4E8Cu) { return; }
    }
    ctx->pc = 0x1D4E8Cu;
label_1d4e8c:
    // 0x1d4e8c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4e8cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
label_1d4e90:
    // 0x1d4e90: 0x40802d  daddu       $s0, $v0, $zero
    ctx->pc = 0x1d4e90u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_1d4e94:
    // 0x1d4e94: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d4e94u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d4e98:
    // 0x1d4e98: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1d4e98u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d4e9c:
    // 0x1d4e9c: 0xc07594e  jal         func_1D6538
label_1d4ea0:
    if (ctx->pc == 0x1D4EA0u) {
        ctx->pc = 0x1D4EA0u;
            // 0x1d4ea0: 0xac202680  sw          $zero, 0x2680($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 9856), GPR_U32(ctx, 0));
        ctx->pc = 0x1D4EA4u;
        goto label_1d4ea4;
    }
    ctx->pc = 0x1D4E9Cu;
    SET_GPR_U32(ctx, 31, 0x1D4EA4u);
    ctx->pc = 0x1D4EA0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4E9Cu;
            // 0x1d4ea0: 0xac202680  sw          $zero, 0x2680($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 9856), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6538u;
    if (runtime->hasFunction(0x1D6538u)) {
        auto targetFn = runtime->lookupFunction(0x1D6538u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4EA4u; }
        if (ctx->pc != 0x1D4EA4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6538_0x1d6538(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4EA4u; }
        if (ctx->pc != 0x1D4EA4u) { return; }
    }
    ctx->pc = 0x1D4EA4u;
label_1d4ea4:
    // 0x1d4ea4: 0x1640000a  bnez        $s2, . + 4 + (0xA << 2)
label_1d4ea8:
    if (ctx->pc == 0x1D4EA8u) {
        ctx->pc = 0x1D4EACu;
        goto label_1d4eac;
    }
    ctx->pc = 0x1D4EA4u;
    {
        const bool branch_taken_0x1d4ea4 = (GPR_U64(ctx, 18) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d4ea4) {
            ctx->pc = 0x1D4ED0u;
            goto label_1d4ed0;
        }
    }
    ctx->pc = 0x1D4EACu;
label_1d4eac:
    // 0x1d4eac: 0x16200008  bnez        $s1, . + 4 + (0x8 << 2)
label_1d4eb0:
    if (ctx->pc == 0x1D4EB0u) {
        ctx->pc = 0x1D4EB4u;
        goto label_1d4eb4;
    }
    ctx->pc = 0x1D4EACu;
    {
        const bool branch_taken_0x1d4eac = (GPR_U64(ctx, 17) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d4eac) {
            ctx->pc = 0x1D4ED0u;
            goto label_1d4ed0;
        }
    }
    ctx->pc = 0x1D4EB4u;
label_1d4eb4:
    // 0x1d4eb4: 0x16000006  bnez        $s0, . + 4 + (0x6 << 2)
label_1d4eb8:
    if (ctx->pc == 0x1D4EB8u) {
        ctx->pc = 0x1D4EBCu;
        goto label_1d4ebc;
    }
    ctx->pc = 0x1D4EB4u;
    {
        const bool branch_taken_0x1d4eb4 = (GPR_U64(ctx, 16) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d4eb4) {
            ctx->pc = 0x1D4ED0u;
            goto label_1d4ed0;
        }
    }
    ctx->pc = 0x1D4EBCu;
label_1d4ebc:
    // 0x1d4ebc: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
label_1d4ec0:
    if (ctx->pc == 0x1D4EC0u) {
        ctx->pc = 0x1D4EC4u;
        goto label_1d4ec4;
    }
    ctx->pc = 0x1D4EBCu;
    {
        const bool branch_taken_0x1d4ebc = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d4ebc) {
            ctx->pc = 0x1D4ED0u;
            goto label_1d4ed0;
        }
    }
    ctx->pc = 0x1D4EC4u;
label_1d4ec4:
    // 0x1d4ec4: 0x82620000  lb          $v0, 0x0($s3)
    ctx->pc = 0x1d4ec4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
label_1d4ec8:
    // 0x1d4ec8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1d4ec8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1d4ecc:
    // 0x1d4ecc: 0xa2620000  sb          $v0, 0x0($s3)
    ctx->pc = 0x1d4eccu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 2));
label_1d4ed0:
    // 0x1d4ed0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d4ed0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1d4ed4:
    // 0x1d4ed4: 0xdfbf0040  ld          $ra, 0x40($sp)
    ctx->pc = 0x1d4ed4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 64)));
label_1d4ed8:
    // 0x1d4ed8: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1d4ed8u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
label_1d4edc:
    // 0x1d4edc: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1d4edcu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
label_1d4ee0:
    // 0x1d4ee0: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1d4ee0u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
label_1d4ee4:
    // 0x1d4ee4: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d4ee4u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
label_1d4ee8:
    // 0x1d4ee8: 0x3e00008  jr          $ra
label_1d4eec:
    if (ctx->pc == 0x1D4EECu) {
        ctx->pc = 0x1D4EECu;
            // 0x1d4eec: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->pc = 0x1D4EF0u;
        goto label_1d4ef0;
    }
    ctx->pc = 0x1D4EE8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4EECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4EE8u;
            // 0x1d4eec: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4CA0u: goto label_1d4ca0;
            case 0x1D4CA4u: goto label_1d4ca4;
            case 0x1D4CA8u: goto label_1d4ca8;
            case 0x1D4CACu: goto label_1d4cac;
            case 0x1D4CB0u: goto label_1d4cb0;
            case 0x1D4CB4u: goto label_1d4cb4;
            case 0x1D4CB8u: goto label_1d4cb8;
            case 0x1D4CBCu: goto label_1d4cbc;
            case 0x1D4CC0u: goto label_1d4cc0;
            case 0x1D4CC4u: goto label_1d4cc4;
            case 0x1D4CC8u: goto label_1d4cc8;
            case 0x1D4CCCu: goto label_1d4ccc;
            case 0x1D4CD0u: goto label_1d4cd0;
            case 0x1D4CD4u: goto label_1d4cd4;
            case 0x1D4CD8u: goto label_1d4cd8;
            case 0x1D4CDCu: goto label_1d4cdc;
            case 0x1D4CE0u: goto label_1d4ce0;
            case 0x1D4CE4u: goto label_1d4ce4;
            case 0x1D4CE8u: goto label_1d4ce8;
            case 0x1D4CECu: goto label_1d4cec;
            case 0x1D4CF0u: goto label_1d4cf0;
            case 0x1D4CF4u: goto label_1d4cf4;
            case 0x1D4CF8u: goto label_1d4cf8;
            case 0x1D4CFCu: goto label_1d4cfc;
            case 0x1D4D00u: goto label_1d4d00;
            case 0x1D4D04u: goto label_1d4d04;
            case 0x1D4D08u: goto label_1d4d08;
            case 0x1D4D0Cu: goto label_1d4d0c;
            case 0x1D4D10u: goto label_1d4d10;
            case 0x1D4D14u: goto label_1d4d14;
            case 0x1D4D18u: goto label_1d4d18;
            case 0x1D4D1Cu: goto label_1d4d1c;
            case 0x1D4D20u: goto label_1d4d20;
            case 0x1D4D24u: goto label_1d4d24;
            case 0x1D4D28u: goto label_1d4d28;
            case 0x1D4D2Cu: goto label_1d4d2c;
            case 0x1D4D30u: goto label_1d4d30;
            case 0x1D4D34u: goto label_1d4d34;
            case 0x1D4D38u: goto label_1d4d38;
            case 0x1D4D3Cu: goto label_1d4d3c;
            case 0x1D4D40u: goto label_1d4d40;
            case 0x1D4D44u: goto label_1d4d44;
            case 0x1D4D48u: goto label_1d4d48;
            case 0x1D4D4Cu: goto label_1d4d4c;
            case 0x1D4D50u: goto label_1d4d50;
            case 0x1D4D54u: goto label_1d4d54;
            case 0x1D4D58u: goto label_1d4d58;
            case 0x1D4D5Cu: goto label_1d4d5c;
            case 0x1D4D60u: goto label_1d4d60;
            case 0x1D4D64u: goto label_1d4d64;
            case 0x1D4D68u: goto label_1d4d68;
            case 0x1D4D6Cu: goto label_1d4d6c;
            case 0x1D4D70u: goto label_1d4d70;
            case 0x1D4D74u: goto label_1d4d74;
            case 0x1D4D78u: goto label_1d4d78;
            case 0x1D4D7Cu: goto label_1d4d7c;
            case 0x1D4D80u: goto label_1d4d80;
            case 0x1D4D84u: goto label_1d4d84;
            case 0x1D4D88u: goto label_1d4d88;
            case 0x1D4D8Cu: goto label_1d4d8c;
            case 0x1D4D90u: goto label_1d4d90;
            case 0x1D4D94u: goto label_1d4d94;
            case 0x1D4D98u: goto label_1d4d98;
            case 0x1D4D9Cu: goto label_1d4d9c;
            case 0x1D4DA0u: goto label_1d4da0;
            case 0x1D4DA4u: goto label_1d4da4;
            case 0x1D4DA8u: goto label_1d4da8;
            case 0x1D4DACu: goto label_1d4dac;
            case 0x1D4DB0u: goto label_1d4db0;
            case 0x1D4DB4u: goto label_1d4db4;
            case 0x1D4DB8u: goto label_1d4db8;
            case 0x1D4DBCu: goto label_1d4dbc;
            case 0x1D4DC0u: goto label_1d4dc0;
            case 0x1D4DC4u: goto label_1d4dc4;
            case 0x1D4DC8u: goto label_1d4dc8;
            case 0x1D4DCCu: goto label_1d4dcc;
            case 0x1D4DD0u: goto label_1d4dd0;
            case 0x1D4DD4u: goto label_1d4dd4;
            case 0x1D4DD8u: goto label_1d4dd8;
            case 0x1D4DDCu: goto label_1d4ddc;
            case 0x1D4DE0u: goto label_1d4de0;
            case 0x1D4DE4u: goto label_1d4de4;
            case 0x1D4DE8u: goto label_1d4de8;
            case 0x1D4DECu: goto label_1d4dec;
            case 0x1D4DF0u: goto label_1d4df0;
            case 0x1D4DF4u: goto label_1d4df4;
            case 0x1D4DF8u: goto label_1d4df8;
            case 0x1D4DFCu: goto label_1d4dfc;
            case 0x1D4E00u: goto label_1d4e00;
            case 0x1D4E04u: goto label_1d4e04;
            case 0x1D4E08u: goto label_1d4e08;
            case 0x1D4E0Cu: goto label_1d4e0c;
            case 0x1D4E10u: goto label_1d4e10;
            case 0x1D4E14u: goto label_1d4e14;
            case 0x1D4E18u: goto label_1d4e18;
            case 0x1D4E1Cu: goto label_1d4e1c;
            case 0x1D4E20u: goto label_1d4e20;
            case 0x1D4E24u: goto label_1d4e24;
            case 0x1D4E28u: goto label_1d4e28;
            case 0x1D4E2Cu: goto label_1d4e2c;
            case 0x1D4E30u: goto label_1d4e30;
            case 0x1D4E34u: goto label_1d4e34;
            case 0x1D4E38u: goto label_1d4e38;
            case 0x1D4E3Cu: goto label_1d4e3c;
            case 0x1D4E40u: goto label_1d4e40;
            case 0x1D4E44u: goto label_1d4e44;
            case 0x1D4E48u: goto label_1d4e48;
            case 0x1D4E4Cu: goto label_1d4e4c;
            case 0x1D4E50u: goto label_1d4e50;
            case 0x1D4E54u: goto label_1d4e54;
            case 0x1D4E58u: goto label_1d4e58;
            case 0x1D4E5Cu: goto label_1d4e5c;
            case 0x1D4E60u: goto label_1d4e60;
            case 0x1D4E64u: goto label_1d4e64;
            case 0x1D4E68u: goto label_1d4e68;
            case 0x1D4E6Cu: goto label_1d4e6c;
            case 0x1D4E70u: goto label_1d4e70;
            case 0x1D4E74u: goto label_1d4e74;
            case 0x1D4E78u: goto label_1d4e78;
            case 0x1D4E7Cu: goto label_1d4e7c;
            case 0x1D4E80u: goto label_1d4e80;
            case 0x1D4E84u: goto label_1d4e84;
            case 0x1D4E88u: goto label_1d4e88;
            case 0x1D4E8Cu: goto label_1d4e8c;
            case 0x1D4E90u: goto label_1d4e90;
            case 0x1D4E94u: goto label_1d4e94;
            case 0x1D4E98u: goto label_1d4e98;
            case 0x1D4E9Cu: goto label_1d4e9c;
            case 0x1D4EA0u: goto label_1d4ea0;
            case 0x1D4EA4u: goto label_1d4ea4;
            case 0x1D4EA8u: goto label_1d4ea8;
            case 0x1D4EACu: goto label_1d4eac;
            case 0x1D4EB0u: goto label_1d4eb0;
            case 0x1D4EB4u: goto label_1d4eb4;
            case 0x1D4EB8u: goto label_1d4eb8;
            case 0x1D4EBCu: goto label_1d4ebc;
            case 0x1D4EC0u: goto label_1d4ec0;
            case 0x1D4EC4u: goto label_1d4ec4;
            case 0x1D4EC8u: goto label_1d4ec8;
            case 0x1D4ECCu: goto label_1d4ecc;
            case 0x1D4ED0u: goto label_1d4ed0;
            case 0x1D4ED4u: goto label_1d4ed4;
            case 0x1D4ED8u: goto label_1d4ed8;
            case 0x1D4EDCu: goto label_1d4edc;
            case 0x1D4EE0u: goto label_1d4ee0;
            case 0x1D4EE4u: goto label_1d4ee4;
            case 0x1D4EE8u: goto label_1d4ee8;
            case 0x1D4EECu: goto label_1d4eec;
            case 0x1D4EF0u: goto label_1d4ef0;
            case 0x1D4EF4u: goto label_1d4ef4;
            case 0x1D4EF8u: goto label_1d4ef8;
            case 0x1D4EFCu: goto label_1d4efc;
            case 0x1D4F00u: goto label_1d4f00;
            case 0x1D4F04u: goto label_1d4f04;
            case 0x1D4F08u: goto label_1d4f08;
            case 0x1D4F0Cu: goto label_1d4f0c;
            case 0x1D4F10u: goto label_1d4f10;
            case 0x1D4F14u: goto label_1d4f14;
            case 0x1D4F18u: goto label_1d4f18;
            case 0x1D4F1Cu: goto label_1d4f1c;
            case 0x1D4F20u: goto label_1d4f20;
            case 0x1D4F24u: goto label_1d4f24;
            case 0x1D4F28u: goto label_1d4f28;
            case 0x1D4F2Cu: goto label_1d4f2c;
            case 0x1D4F30u: goto label_1d4f30;
            case 0x1D4F34u: goto label_1d4f34;
            case 0x1D4F38u: goto label_1d4f38;
            case 0x1D4F3Cu: goto label_1d4f3c;
            case 0x1D4F40u: goto label_1d4f40;
            case 0x1D4F44u: goto label_1d4f44;
            case 0x1D4F48u: goto label_1d4f48;
            case 0x1D4F4Cu: goto label_1d4f4c;
            case 0x1D4F50u: goto label_1d4f50;
            case 0x1D4F54u: goto label_1d4f54;
            case 0x1D4F58u: goto label_1d4f58;
            case 0x1D4F5Cu: goto label_1d4f5c;
            case 0x1D4F60u: goto label_1d4f60;
            case 0x1D4F64u: goto label_1d4f64;
            case 0x1D4F68u: goto label_1d4f68;
            case 0x1D4F6Cu: goto label_1d4f6c;
            case 0x1D4F70u: goto label_1d4f70;
            case 0x1D4F74u: goto label_1d4f74;
            case 0x1D4F78u: goto label_1d4f78;
            case 0x1D4F7Cu: goto label_1d4f7c;
            case 0x1D4F80u: goto label_1d4f80;
            case 0x1D4F84u: goto label_1d4f84;
            case 0x1D4F88u: goto label_1d4f88;
            case 0x1D4F8Cu: goto label_1d4f8c;
            case 0x1D4F90u: goto label_1d4f90;
            case 0x1D4F94u: goto label_1d4f94;
            case 0x1D4F98u: goto label_1d4f98;
            case 0x1D4F9Cu: goto label_1d4f9c;
            case 0x1D4FA0u: goto label_1d4fa0;
            case 0x1D4FA4u: goto label_1d4fa4;
            case 0x1D4FA8u: goto label_1d4fa8;
            case 0x1D4FACu: goto label_1d4fac;
            case 0x1D4FB0u: goto label_1d4fb0;
            case 0x1D4FB4u: goto label_1d4fb4;
            case 0x1D4FB8u: goto label_1d4fb8;
            case 0x1D4FBCu: goto label_1d4fbc;
            case 0x1D4FC0u: goto label_1d4fc0;
            case 0x1D4FC4u: goto label_1d4fc4;
            case 0x1D4FC8u: goto label_1d4fc8;
            case 0x1D4FCCu: goto label_1d4fcc;
            case 0x1D4FD0u: goto label_1d4fd0;
            case 0x1D4FD4u: goto label_1d4fd4;
            case 0x1D4FD8u: goto label_1d4fd8;
            case 0x1D4FDCu: goto label_1d4fdc;
            case 0x1D4FE0u: goto label_1d4fe0;
            case 0x1D4FE4u: goto label_1d4fe4;
            case 0x1D4FE8u: goto label_1d4fe8;
            case 0x1D4FECu: goto label_1d4fec;
            case 0x1D4FF0u: goto label_1d4ff0;
            case 0x1D4FF4u: goto label_1d4ff4;
            case 0x1D4FF8u: goto label_1d4ff8;
            case 0x1D4FFCu: goto label_1d4ffc;
            case 0x1D5000u: goto label_1d5000;
            case 0x1D5004u: goto label_1d5004;
            case 0x1D5008u: goto label_1d5008;
            case 0x1D500Cu: goto label_1d500c;
            case 0x1D5010u: goto label_1d5010;
            case 0x1D5014u: goto label_1d5014;
            case 0x1D5018u: goto label_1d5018;
            case 0x1D501Cu: goto label_1d501c;
            case 0x1D5020u: goto label_1d5020;
            case 0x1D5024u: goto label_1d5024;
            case 0x1D5028u: goto label_1d5028;
            case 0x1D502Cu: goto label_1d502c;
            case 0x1D5030u: goto label_1d5030;
            case 0x1D5034u: goto label_1d5034;
            case 0x1D5038u: goto label_1d5038;
            case 0x1D503Cu: goto label_1d503c;
            case 0x1D5040u: goto label_1d5040;
            case 0x1D5044u: goto label_1d5044;
            case 0x1D5048u: goto label_1d5048;
            case 0x1D504Cu: goto label_1d504c;
            case 0x1D5050u: goto label_1d5050;
            case 0x1D5054u: goto label_1d5054;
            case 0x1D5058u: goto label_1d5058;
            case 0x1D505Cu: goto label_1d505c;
            case 0x1D5060u: goto label_1d5060;
            case 0x1D5064u: goto label_1d5064;
            case 0x1D5068u: goto label_1d5068;
            case 0x1D506Cu: goto label_1d506c;
            case 0x1D5070u: goto label_1d5070;
            case 0x1D5074u: goto label_1d5074;
            case 0x1D5078u: goto label_1d5078;
            case 0x1D507Cu: goto label_1d507c;
            case 0x1D5080u: goto label_1d5080;
            case 0x1D5084u: goto label_1d5084;
            case 0x1D5088u: goto label_1d5088;
            case 0x1D508Cu: goto label_1d508c;
            case 0x1D5090u: goto label_1d5090;
            case 0x1D5094u: goto label_1d5094;
            case 0x1D5098u: goto label_1d5098;
            case 0x1D509Cu: goto label_1d509c;
            case 0x1D50A0u: goto label_1d50a0;
            case 0x1D50A4u: goto label_1d50a4;
            case 0x1D50A8u: goto label_1d50a8;
            case 0x1D50ACu: goto label_1d50ac;
            case 0x1D50B0u: goto label_1d50b0;
            case 0x1D50B4u: goto label_1d50b4;
            case 0x1D50B8u: goto label_1d50b8;
            case 0x1D50BCu: goto label_1d50bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4EF0u;
label_1d4ef0:
    // 0x1d4ef0: 0x27bdffd0  addiu       $sp, $sp, -0x30
    ctx->pc = 0x1d4ef0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967248));
label_1d4ef4:
    // 0x1d4ef4: 0x24050002  addiu       $a1, $zero, 0x2
    ctx->pc = 0x1d4ef4u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
label_1d4ef8:
    // 0x1d4ef8: 0xffbf0010  sd          $ra, 0x10($sp)
    ctx->pc = 0x1d4ef8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 31));
label_1d4efc:
    // 0x1d4efc: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1d4efcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
label_1d4f00:
    // 0x1d4f00: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1d4f00u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_1d4f04:
    // 0x1d4f04: 0xc0755cc  jal         func_1D5730
label_1d4f08:
    if (ctx->pc == 0x1D4F08u) {
        ctx->pc = 0x1D4F08u;
            // 0x1d4f08: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1D4F0Cu;
        goto label_1d4f0c;
    }
    ctx->pc = 0x1D4F04u;
    SET_GPR_U32(ctx, 31, 0x1D4F0Cu);
    ctx->pc = 0x1D4F08u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4F04u;
            // 0x1d4f08: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D5730u;
    if (runtime->hasFunction(0x1D5730u)) {
        auto targetFn = runtime->lookupFunction(0x1D5730u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4F0Cu; }
        if (ctx->pc != 0x1D4F0Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D5730_0x1d5730(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4F0Cu; }
        if (ctx->pc != 0x1D4F0Cu) { return; }
    }
    ctx->pc = 0x1D4F0Cu;
label_1d4f0c:
    // 0x1d4f0c: 0xafa2002c  sw          $v0, 0x2C($sp)
    ctx->pc = 0x1d4f0cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 44), GPR_U32(ctx, 2));
label_1d4f10:
    // 0x1d4f10: 0x8fa2002c  lw          $v0, 0x2C($sp)
    ctx->pc = 0x1d4f10u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_1d4f14:
    // 0x1d4f14: 0x1440000f  bnez        $v0, . + 4 + (0xF << 2)
label_1d4f18:
    if (ctx->pc == 0x1D4F18u) {
        ctx->pc = 0x1D4F18u;
            // 0x1d4f18: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1D4F1Cu;
        goto label_1d4f1c;
    }
    ctx->pc = 0x1D4F14u;
    {
        const bool branch_taken_0x1d4f14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4F18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4F14u;
            // 0x1d4f18: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4f14) {
            ctx->pc = 0x1D4F54u;
            goto label_1d4f54;
        }
    }
    ctx->pc = 0x1D4F1Cu;
label_1d4f1c:
    // 0x1d4f1c: 0xc075646  jal         func_1D5918
label_1d4f20:
    if (ctx->pc == 0x1D4F20u) {
        ctx->pc = 0x1D4F20u;
            // 0x1d4f20: 0x27a5002c  addiu       $a1, $sp, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
        ctx->pc = 0x1D4F24u;
        goto label_1d4f24;
    }
    ctx->pc = 0x1D4F1Cu;
    SET_GPR_U32(ctx, 31, 0x1D4F24u);
    ctx->pc = 0x1D4F20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4F1Cu;
            // 0x1d4f20: 0x27a5002c  addiu       $a1, $sp, 0x2C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 44));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D5918u;
    if (runtime->hasFunction(0x1D5918u)) {
        auto targetFn = runtime->lookupFunction(0x1D5918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4F24u; }
        if (ctx->pc != 0x1D4F24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D5918_0x1d5918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4F24u; }
        if (ctx->pc != 0x1D4F24u) { return; }
    }
    ctx->pc = 0x1D4F24u;
label_1d4f24:
    // 0x1d4f24: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4f24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
label_1d4f28:
    // 0x1d4f28: 0xac222678  sw          $v0, 0x2678($at)
    ctx->pc = 0x1d4f28u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 9848), GPR_U32(ctx, 2));
label_1d4f2c:
    // 0x1d4f2c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4f2cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
label_1d4f30:
    // 0x1d4f30: 0x8c222678  lw          $v0, 0x2678($at)
    ctx->pc = 0x1d4f30u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 9848)));
label_1d4f34:
    // 0x1d4f34: 0x14400007  bnez        $v0, . + 4 + (0x7 << 2)
label_1d4f38:
    if (ctx->pc == 0x1D4F38u) {
        ctx->pc = 0x1D4F3Cu;
        goto label_1d4f3c;
    }
    ctx->pc = 0x1D4F34u;
    {
        const bool branch_taken_0x1d4f34 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d4f34) {
            ctx->pc = 0x1D4F54u;
            goto label_1d4f54;
        }
    }
    ctx->pc = 0x1D4F3Cu;
label_1d4f3c:
    // 0x1d4f3c: 0x8fa2002c  lw          $v0, 0x2C($sp)
    ctx->pc = 0x1d4f3cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 44)));
label_1d4f40:
    // 0x1d4f40: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
label_1d4f44:
    if (ctx->pc == 0x1D4F44u) {
        ctx->pc = 0x1D4F48u;
        goto label_1d4f48;
    }
    ctx->pc = 0x1D4F40u;
    {
        const bool branch_taken_0x1d4f40 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1d4f40) {
            ctx->pc = 0x1D4F54u;
            goto label_1d4f54;
        }
    }
    ctx->pc = 0x1D4F48u;
label_1d4f48:
    // 0x1d4f48: 0x82020000  lb          $v0, 0x0($s0)
    ctx->pc = 0x1d4f48u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 0)));
label_1d4f4c:
    // 0x1d4f4c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1d4f4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1d4f50:
    // 0x1d4f50: 0xa2020000  sb          $v0, 0x0($s0)
    ctx->pc = 0x1d4f50u;
    WRITE8(ADD32(GPR_U32(ctx, 16), 0), (uint8_t)GPR_U32(ctx, 2));
label_1d4f54:
    // 0x1d4f54: 0xdfbf0010  ld          $ra, 0x10($sp)
    ctx->pc = 0x1d4f54u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_1d4f58:
    // 0x1d4f58: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1d4f58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1d4f5c:
    // 0x1d4f5c: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1d4f5cu;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
label_1d4f60:
    // 0x1d4f60: 0x3e00008  jr          $ra
label_1d4f64:
    if (ctx->pc == 0x1D4F64u) {
        ctx->pc = 0x1D4F64u;
            // 0x1d4f64: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->pc = 0x1D4F68u;
        goto label_1d4f68;
    }
    ctx->pc = 0x1D4F60u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4F64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4F60u;
            // 0x1d4f64: 0x27bd0030  addiu       $sp, $sp, 0x30 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 48));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4CA0u: goto label_1d4ca0;
            case 0x1D4CA4u: goto label_1d4ca4;
            case 0x1D4CA8u: goto label_1d4ca8;
            case 0x1D4CACu: goto label_1d4cac;
            case 0x1D4CB0u: goto label_1d4cb0;
            case 0x1D4CB4u: goto label_1d4cb4;
            case 0x1D4CB8u: goto label_1d4cb8;
            case 0x1D4CBCu: goto label_1d4cbc;
            case 0x1D4CC0u: goto label_1d4cc0;
            case 0x1D4CC4u: goto label_1d4cc4;
            case 0x1D4CC8u: goto label_1d4cc8;
            case 0x1D4CCCu: goto label_1d4ccc;
            case 0x1D4CD0u: goto label_1d4cd0;
            case 0x1D4CD4u: goto label_1d4cd4;
            case 0x1D4CD8u: goto label_1d4cd8;
            case 0x1D4CDCu: goto label_1d4cdc;
            case 0x1D4CE0u: goto label_1d4ce0;
            case 0x1D4CE4u: goto label_1d4ce4;
            case 0x1D4CE8u: goto label_1d4ce8;
            case 0x1D4CECu: goto label_1d4cec;
            case 0x1D4CF0u: goto label_1d4cf0;
            case 0x1D4CF4u: goto label_1d4cf4;
            case 0x1D4CF8u: goto label_1d4cf8;
            case 0x1D4CFCu: goto label_1d4cfc;
            case 0x1D4D00u: goto label_1d4d00;
            case 0x1D4D04u: goto label_1d4d04;
            case 0x1D4D08u: goto label_1d4d08;
            case 0x1D4D0Cu: goto label_1d4d0c;
            case 0x1D4D10u: goto label_1d4d10;
            case 0x1D4D14u: goto label_1d4d14;
            case 0x1D4D18u: goto label_1d4d18;
            case 0x1D4D1Cu: goto label_1d4d1c;
            case 0x1D4D20u: goto label_1d4d20;
            case 0x1D4D24u: goto label_1d4d24;
            case 0x1D4D28u: goto label_1d4d28;
            case 0x1D4D2Cu: goto label_1d4d2c;
            case 0x1D4D30u: goto label_1d4d30;
            case 0x1D4D34u: goto label_1d4d34;
            case 0x1D4D38u: goto label_1d4d38;
            case 0x1D4D3Cu: goto label_1d4d3c;
            case 0x1D4D40u: goto label_1d4d40;
            case 0x1D4D44u: goto label_1d4d44;
            case 0x1D4D48u: goto label_1d4d48;
            case 0x1D4D4Cu: goto label_1d4d4c;
            case 0x1D4D50u: goto label_1d4d50;
            case 0x1D4D54u: goto label_1d4d54;
            case 0x1D4D58u: goto label_1d4d58;
            case 0x1D4D5Cu: goto label_1d4d5c;
            case 0x1D4D60u: goto label_1d4d60;
            case 0x1D4D64u: goto label_1d4d64;
            case 0x1D4D68u: goto label_1d4d68;
            case 0x1D4D6Cu: goto label_1d4d6c;
            case 0x1D4D70u: goto label_1d4d70;
            case 0x1D4D74u: goto label_1d4d74;
            case 0x1D4D78u: goto label_1d4d78;
            case 0x1D4D7Cu: goto label_1d4d7c;
            case 0x1D4D80u: goto label_1d4d80;
            case 0x1D4D84u: goto label_1d4d84;
            case 0x1D4D88u: goto label_1d4d88;
            case 0x1D4D8Cu: goto label_1d4d8c;
            case 0x1D4D90u: goto label_1d4d90;
            case 0x1D4D94u: goto label_1d4d94;
            case 0x1D4D98u: goto label_1d4d98;
            case 0x1D4D9Cu: goto label_1d4d9c;
            case 0x1D4DA0u: goto label_1d4da0;
            case 0x1D4DA4u: goto label_1d4da4;
            case 0x1D4DA8u: goto label_1d4da8;
            case 0x1D4DACu: goto label_1d4dac;
            case 0x1D4DB0u: goto label_1d4db0;
            case 0x1D4DB4u: goto label_1d4db4;
            case 0x1D4DB8u: goto label_1d4db8;
            case 0x1D4DBCu: goto label_1d4dbc;
            case 0x1D4DC0u: goto label_1d4dc0;
            case 0x1D4DC4u: goto label_1d4dc4;
            case 0x1D4DC8u: goto label_1d4dc8;
            case 0x1D4DCCu: goto label_1d4dcc;
            case 0x1D4DD0u: goto label_1d4dd0;
            case 0x1D4DD4u: goto label_1d4dd4;
            case 0x1D4DD8u: goto label_1d4dd8;
            case 0x1D4DDCu: goto label_1d4ddc;
            case 0x1D4DE0u: goto label_1d4de0;
            case 0x1D4DE4u: goto label_1d4de4;
            case 0x1D4DE8u: goto label_1d4de8;
            case 0x1D4DECu: goto label_1d4dec;
            case 0x1D4DF0u: goto label_1d4df0;
            case 0x1D4DF4u: goto label_1d4df4;
            case 0x1D4DF8u: goto label_1d4df8;
            case 0x1D4DFCu: goto label_1d4dfc;
            case 0x1D4E00u: goto label_1d4e00;
            case 0x1D4E04u: goto label_1d4e04;
            case 0x1D4E08u: goto label_1d4e08;
            case 0x1D4E0Cu: goto label_1d4e0c;
            case 0x1D4E10u: goto label_1d4e10;
            case 0x1D4E14u: goto label_1d4e14;
            case 0x1D4E18u: goto label_1d4e18;
            case 0x1D4E1Cu: goto label_1d4e1c;
            case 0x1D4E20u: goto label_1d4e20;
            case 0x1D4E24u: goto label_1d4e24;
            case 0x1D4E28u: goto label_1d4e28;
            case 0x1D4E2Cu: goto label_1d4e2c;
            case 0x1D4E30u: goto label_1d4e30;
            case 0x1D4E34u: goto label_1d4e34;
            case 0x1D4E38u: goto label_1d4e38;
            case 0x1D4E3Cu: goto label_1d4e3c;
            case 0x1D4E40u: goto label_1d4e40;
            case 0x1D4E44u: goto label_1d4e44;
            case 0x1D4E48u: goto label_1d4e48;
            case 0x1D4E4Cu: goto label_1d4e4c;
            case 0x1D4E50u: goto label_1d4e50;
            case 0x1D4E54u: goto label_1d4e54;
            case 0x1D4E58u: goto label_1d4e58;
            case 0x1D4E5Cu: goto label_1d4e5c;
            case 0x1D4E60u: goto label_1d4e60;
            case 0x1D4E64u: goto label_1d4e64;
            case 0x1D4E68u: goto label_1d4e68;
            case 0x1D4E6Cu: goto label_1d4e6c;
            case 0x1D4E70u: goto label_1d4e70;
            case 0x1D4E74u: goto label_1d4e74;
            case 0x1D4E78u: goto label_1d4e78;
            case 0x1D4E7Cu: goto label_1d4e7c;
            case 0x1D4E80u: goto label_1d4e80;
            case 0x1D4E84u: goto label_1d4e84;
            case 0x1D4E88u: goto label_1d4e88;
            case 0x1D4E8Cu: goto label_1d4e8c;
            case 0x1D4E90u: goto label_1d4e90;
            case 0x1D4E94u: goto label_1d4e94;
            case 0x1D4E98u: goto label_1d4e98;
            case 0x1D4E9Cu: goto label_1d4e9c;
            case 0x1D4EA0u: goto label_1d4ea0;
            case 0x1D4EA4u: goto label_1d4ea4;
            case 0x1D4EA8u: goto label_1d4ea8;
            case 0x1D4EACu: goto label_1d4eac;
            case 0x1D4EB0u: goto label_1d4eb0;
            case 0x1D4EB4u: goto label_1d4eb4;
            case 0x1D4EB8u: goto label_1d4eb8;
            case 0x1D4EBCu: goto label_1d4ebc;
            case 0x1D4EC0u: goto label_1d4ec0;
            case 0x1D4EC4u: goto label_1d4ec4;
            case 0x1D4EC8u: goto label_1d4ec8;
            case 0x1D4ECCu: goto label_1d4ecc;
            case 0x1D4ED0u: goto label_1d4ed0;
            case 0x1D4ED4u: goto label_1d4ed4;
            case 0x1D4ED8u: goto label_1d4ed8;
            case 0x1D4EDCu: goto label_1d4edc;
            case 0x1D4EE0u: goto label_1d4ee0;
            case 0x1D4EE4u: goto label_1d4ee4;
            case 0x1D4EE8u: goto label_1d4ee8;
            case 0x1D4EECu: goto label_1d4eec;
            case 0x1D4EF0u: goto label_1d4ef0;
            case 0x1D4EF4u: goto label_1d4ef4;
            case 0x1D4EF8u: goto label_1d4ef8;
            case 0x1D4EFCu: goto label_1d4efc;
            case 0x1D4F00u: goto label_1d4f00;
            case 0x1D4F04u: goto label_1d4f04;
            case 0x1D4F08u: goto label_1d4f08;
            case 0x1D4F0Cu: goto label_1d4f0c;
            case 0x1D4F10u: goto label_1d4f10;
            case 0x1D4F14u: goto label_1d4f14;
            case 0x1D4F18u: goto label_1d4f18;
            case 0x1D4F1Cu: goto label_1d4f1c;
            case 0x1D4F20u: goto label_1d4f20;
            case 0x1D4F24u: goto label_1d4f24;
            case 0x1D4F28u: goto label_1d4f28;
            case 0x1D4F2Cu: goto label_1d4f2c;
            case 0x1D4F30u: goto label_1d4f30;
            case 0x1D4F34u: goto label_1d4f34;
            case 0x1D4F38u: goto label_1d4f38;
            case 0x1D4F3Cu: goto label_1d4f3c;
            case 0x1D4F40u: goto label_1d4f40;
            case 0x1D4F44u: goto label_1d4f44;
            case 0x1D4F48u: goto label_1d4f48;
            case 0x1D4F4Cu: goto label_1d4f4c;
            case 0x1D4F50u: goto label_1d4f50;
            case 0x1D4F54u: goto label_1d4f54;
            case 0x1D4F58u: goto label_1d4f58;
            case 0x1D4F5Cu: goto label_1d4f5c;
            case 0x1D4F60u: goto label_1d4f60;
            case 0x1D4F64u: goto label_1d4f64;
            case 0x1D4F68u: goto label_1d4f68;
            case 0x1D4F6Cu: goto label_1d4f6c;
            case 0x1D4F70u: goto label_1d4f70;
            case 0x1D4F74u: goto label_1d4f74;
            case 0x1D4F78u: goto label_1d4f78;
            case 0x1D4F7Cu: goto label_1d4f7c;
            case 0x1D4F80u: goto label_1d4f80;
            case 0x1D4F84u: goto label_1d4f84;
            case 0x1D4F88u: goto label_1d4f88;
            case 0x1D4F8Cu: goto label_1d4f8c;
            case 0x1D4F90u: goto label_1d4f90;
            case 0x1D4F94u: goto label_1d4f94;
            case 0x1D4F98u: goto label_1d4f98;
            case 0x1D4F9Cu: goto label_1d4f9c;
            case 0x1D4FA0u: goto label_1d4fa0;
            case 0x1D4FA4u: goto label_1d4fa4;
            case 0x1D4FA8u: goto label_1d4fa8;
            case 0x1D4FACu: goto label_1d4fac;
            case 0x1D4FB0u: goto label_1d4fb0;
            case 0x1D4FB4u: goto label_1d4fb4;
            case 0x1D4FB8u: goto label_1d4fb8;
            case 0x1D4FBCu: goto label_1d4fbc;
            case 0x1D4FC0u: goto label_1d4fc0;
            case 0x1D4FC4u: goto label_1d4fc4;
            case 0x1D4FC8u: goto label_1d4fc8;
            case 0x1D4FCCu: goto label_1d4fcc;
            case 0x1D4FD0u: goto label_1d4fd0;
            case 0x1D4FD4u: goto label_1d4fd4;
            case 0x1D4FD8u: goto label_1d4fd8;
            case 0x1D4FDCu: goto label_1d4fdc;
            case 0x1D4FE0u: goto label_1d4fe0;
            case 0x1D4FE4u: goto label_1d4fe4;
            case 0x1D4FE8u: goto label_1d4fe8;
            case 0x1D4FECu: goto label_1d4fec;
            case 0x1D4FF0u: goto label_1d4ff0;
            case 0x1D4FF4u: goto label_1d4ff4;
            case 0x1D4FF8u: goto label_1d4ff8;
            case 0x1D4FFCu: goto label_1d4ffc;
            case 0x1D5000u: goto label_1d5000;
            case 0x1D5004u: goto label_1d5004;
            case 0x1D5008u: goto label_1d5008;
            case 0x1D500Cu: goto label_1d500c;
            case 0x1D5010u: goto label_1d5010;
            case 0x1D5014u: goto label_1d5014;
            case 0x1D5018u: goto label_1d5018;
            case 0x1D501Cu: goto label_1d501c;
            case 0x1D5020u: goto label_1d5020;
            case 0x1D5024u: goto label_1d5024;
            case 0x1D5028u: goto label_1d5028;
            case 0x1D502Cu: goto label_1d502c;
            case 0x1D5030u: goto label_1d5030;
            case 0x1D5034u: goto label_1d5034;
            case 0x1D5038u: goto label_1d5038;
            case 0x1D503Cu: goto label_1d503c;
            case 0x1D5040u: goto label_1d5040;
            case 0x1D5044u: goto label_1d5044;
            case 0x1D5048u: goto label_1d5048;
            case 0x1D504Cu: goto label_1d504c;
            case 0x1D5050u: goto label_1d5050;
            case 0x1D5054u: goto label_1d5054;
            case 0x1D5058u: goto label_1d5058;
            case 0x1D505Cu: goto label_1d505c;
            case 0x1D5060u: goto label_1d5060;
            case 0x1D5064u: goto label_1d5064;
            case 0x1D5068u: goto label_1d5068;
            case 0x1D506Cu: goto label_1d506c;
            case 0x1D5070u: goto label_1d5070;
            case 0x1D5074u: goto label_1d5074;
            case 0x1D5078u: goto label_1d5078;
            case 0x1D507Cu: goto label_1d507c;
            case 0x1D5080u: goto label_1d5080;
            case 0x1D5084u: goto label_1d5084;
            case 0x1D5088u: goto label_1d5088;
            case 0x1D508Cu: goto label_1d508c;
            case 0x1D5090u: goto label_1d5090;
            case 0x1D5094u: goto label_1d5094;
            case 0x1D5098u: goto label_1d5098;
            case 0x1D509Cu: goto label_1d509c;
            case 0x1D50A0u: goto label_1d50a0;
            case 0x1D50A4u: goto label_1d50a4;
            case 0x1D50A8u: goto label_1d50a8;
            case 0x1D50ACu: goto label_1d50ac;
            case 0x1D50B0u: goto label_1d50b0;
            case 0x1D50B4u: goto label_1d50b4;
            case 0x1D50B8u: goto label_1d50b8;
            case 0x1D50BCu: goto label_1d50bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4F68u;
label_1d4f68:
    // 0x1d4f68: 0x0  nop
    ctx->pc = 0x1d4f68u;
    // NOP
label_1d4f6c:
    // 0x1d4f6c: 0x0  nop
    ctx->pc = 0x1d4f6cu;
    // NOP
label_1d4f70:
    // 0x1d4f70: 0xa0800000  sb          $zero, 0x0($a0)
    ctx->pc = 0x1d4f70u;
    WRITE8(ADD32(GPR_U32(ctx, 4), 0), (uint8_t)GPR_U32(ctx, 0));
label_1d4f74:
    // 0x1d4f74: 0x24030001  addiu       $v1, $zero, 0x1
    ctx->pc = 0x1d4f74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
label_1d4f78:
    // 0x1d4f78: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4f78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
label_1d4f7c:
    // 0x1d4f7c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1d4f7cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d4f80:
    // 0x1d4f80: 0xa4232640  sh          $v1, 0x2640($at)
    ctx->pc = 0x1d4f80u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 9792), (uint16_t)GPR_U32(ctx, 3));
label_1d4f84:
    // 0x1d4f84: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4f84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
label_1d4f88:
    // 0x1d4f88: 0x3e00008  jr          $ra
label_1d4f8c:
    if (ctx->pc == 0x1D4F8Cu) {
        ctx->pc = 0x1D4F8Cu;
            // 0x1d4f8c: 0xa0232658  sb          $v1, 0x2658($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 9816), (uint8_t)GPR_U32(ctx, 3));
        ctx->pc = 0x1D4F90u;
        goto label_1d4f90;
    }
    ctx->pc = 0x1D4F88u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D4F8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4F88u;
            // 0x1d4f8c: 0xa0232658  sb          $v1, 0x2658($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 9816), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4CA0u: goto label_1d4ca0;
            case 0x1D4CA4u: goto label_1d4ca4;
            case 0x1D4CA8u: goto label_1d4ca8;
            case 0x1D4CACu: goto label_1d4cac;
            case 0x1D4CB0u: goto label_1d4cb0;
            case 0x1D4CB4u: goto label_1d4cb4;
            case 0x1D4CB8u: goto label_1d4cb8;
            case 0x1D4CBCu: goto label_1d4cbc;
            case 0x1D4CC0u: goto label_1d4cc0;
            case 0x1D4CC4u: goto label_1d4cc4;
            case 0x1D4CC8u: goto label_1d4cc8;
            case 0x1D4CCCu: goto label_1d4ccc;
            case 0x1D4CD0u: goto label_1d4cd0;
            case 0x1D4CD4u: goto label_1d4cd4;
            case 0x1D4CD8u: goto label_1d4cd8;
            case 0x1D4CDCu: goto label_1d4cdc;
            case 0x1D4CE0u: goto label_1d4ce0;
            case 0x1D4CE4u: goto label_1d4ce4;
            case 0x1D4CE8u: goto label_1d4ce8;
            case 0x1D4CECu: goto label_1d4cec;
            case 0x1D4CF0u: goto label_1d4cf0;
            case 0x1D4CF4u: goto label_1d4cf4;
            case 0x1D4CF8u: goto label_1d4cf8;
            case 0x1D4CFCu: goto label_1d4cfc;
            case 0x1D4D00u: goto label_1d4d00;
            case 0x1D4D04u: goto label_1d4d04;
            case 0x1D4D08u: goto label_1d4d08;
            case 0x1D4D0Cu: goto label_1d4d0c;
            case 0x1D4D10u: goto label_1d4d10;
            case 0x1D4D14u: goto label_1d4d14;
            case 0x1D4D18u: goto label_1d4d18;
            case 0x1D4D1Cu: goto label_1d4d1c;
            case 0x1D4D20u: goto label_1d4d20;
            case 0x1D4D24u: goto label_1d4d24;
            case 0x1D4D28u: goto label_1d4d28;
            case 0x1D4D2Cu: goto label_1d4d2c;
            case 0x1D4D30u: goto label_1d4d30;
            case 0x1D4D34u: goto label_1d4d34;
            case 0x1D4D38u: goto label_1d4d38;
            case 0x1D4D3Cu: goto label_1d4d3c;
            case 0x1D4D40u: goto label_1d4d40;
            case 0x1D4D44u: goto label_1d4d44;
            case 0x1D4D48u: goto label_1d4d48;
            case 0x1D4D4Cu: goto label_1d4d4c;
            case 0x1D4D50u: goto label_1d4d50;
            case 0x1D4D54u: goto label_1d4d54;
            case 0x1D4D58u: goto label_1d4d58;
            case 0x1D4D5Cu: goto label_1d4d5c;
            case 0x1D4D60u: goto label_1d4d60;
            case 0x1D4D64u: goto label_1d4d64;
            case 0x1D4D68u: goto label_1d4d68;
            case 0x1D4D6Cu: goto label_1d4d6c;
            case 0x1D4D70u: goto label_1d4d70;
            case 0x1D4D74u: goto label_1d4d74;
            case 0x1D4D78u: goto label_1d4d78;
            case 0x1D4D7Cu: goto label_1d4d7c;
            case 0x1D4D80u: goto label_1d4d80;
            case 0x1D4D84u: goto label_1d4d84;
            case 0x1D4D88u: goto label_1d4d88;
            case 0x1D4D8Cu: goto label_1d4d8c;
            case 0x1D4D90u: goto label_1d4d90;
            case 0x1D4D94u: goto label_1d4d94;
            case 0x1D4D98u: goto label_1d4d98;
            case 0x1D4D9Cu: goto label_1d4d9c;
            case 0x1D4DA0u: goto label_1d4da0;
            case 0x1D4DA4u: goto label_1d4da4;
            case 0x1D4DA8u: goto label_1d4da8;
            case 0x1D4DACu: goto label_1d4dac;
            case 0x1D4DB0u: goto label_1d4db0;
            case 0x1D4DB4u: goto label_1d4db4;
            case 0x1D4DB8u: goto label_1d4db8;
            case 0x1D4DBCu: goto label_1d4dbc;
            case 0x1D4DC0u: goto label_1d4dc0;
            case 0x1D4DC4u: goto label_1d4dc4;
            case 0x1D4DC8u: goto label_1d4dc8;
            case 0x1D4DCCu: goto label_1d4dcc;
            case 0x1D4DD0u: goto label_1d4dd0;
            case 0x1D4DD4u: goto label_1d4dd4;
            case 0x1D4DD8u: goto label_1d4dd8;
            case 0x1D4DDCu: goto label_1d4ddc;
            case 0x1D4DE0u: goto label_1d4de0;
            case 0x1D4DE4u: goto label_1d4de4;
            case 0x1D4DE8u: goto label_1d4de8;
            case 0x1D4DECu: goto label_1d4dec;
            case 0x1D4DF0u: goto label_1d4df0;
            case 0x1D4DF4u: goto label_1d4df4;
            case 0x1D4DF8u: goto label_1d4df8;
            case 0x1D4DFCu: goto label_1d4dfc;
            case 0x1D4E00u: goto label_1d4e00;
            case 0x1D4E04u: goto label_1d4e04;
            case 0x1D4E08u: goto label_1d4e08;
            case 0x1D4E0Cu: goto label_1d4e0c;
            case 0x1D4E10u: goto label_1d4e10;
            case 0x1D4E14u: goto label_1d4e14;
            case 0x1D4E18u: goto label_1d4e18;
            case 0x1D4E1Cu: goto label_1d4e1c;
            case 0x1D4E20u: goto label_1d4e20;
            case 0x1D4E24u: goto label_1d4e24;
            case 0x1D4E28u: goto label_1d4e28;
            case 0x1D4E2Cu: goto label_1d4e2c;
            case 0x1D4E30u: goto label_1d4e30;
            case 0x1D4E34u: goto label_1d4e34;
            case 0x1D4E38u: goto label_1d4e38;
            case 0x1D4E3Cu: goto label_1d4e3c;
            case 0x1D4E40u: goto label_1d4e40;
            case 0x1D4E44u: goto label_1d4e44;
            case 0x1D4E48u: goto label_1d4e48;
            case 0x1D4E4Cu: goto label_1d4e4c;
            case 0x1D4E50u: goto label_1d4e50;
            case 0x1D4E54u: goto label_1d4e54;
            case 0x1D4E58u: goto label_1d4e58;
            case 0x1D4E5Cu: goto label_1d4e5c;
            case 0x1D4E60u: goto label_1d4e60;
            case 0x1D4E64u: goto label_1d4e64;
            case 0x1D4E68u: goto label_1d4e68;
            case 0x1D4E6Cu: goto label_1d4e6c;
            case 0x1D4E70u: goto label_1d4e70;
            case 0x1D4E74u: goto label_1d4e74;
            case 0x1D4E78u: goto label_1d4e78;
            case 0x1D4E7Cu: goto label_1d4e7c;
            case 0x1D4E80u: goto label_1d4e80;
            case 0x1D4E84u: goto label_1d4e84;
            case 0x1D4E88u: goto label_1d4e88;
            case 0x1D4E8Cu: goto label_1d4e8c;
            case 0x1D4E90u: goto label_1d4e90;
            case 0x1D4E94u: goto label_1d4e94;
            case 0x1D4E98u: goto label_1d4e98;
            case 0x1D4E9Cu: goto label_1d4e9c;
            case 0x1D4EA0u: goto label_1d4ea0;
            case 0x1D4EA4u: goto label_1d4ea4;
            case 0x1D4EA8u: goto label_1d4ea8;
            case 0x1D4EACu: goto label_1d4eac;
            case 0x1D4EB0u: goto label_1d4eb0;
            case 0x1D4EB4u: goto label_1d4eb4;
            case 0x1D4EB8u: goto label_1d4eb8;
            case 0x1D4EBCu: goto label_1d4ebc;
            case 0x1D4EC0u: goto label_1d4ec0;
            case 0x1D4EC4u: goto label_1d4ec4;
            case 0x1D4EC8u: goto label_1d4ec8;
            case 0x1D4ECCu: goto label_1d4ecc;
            case 0x1D4ED0u: goto label_1d4ed0;
            case 0x1D4ED4u: goto label_1d4ed4;
            case 0x1D4ED8u: goto label_1d4ed8;
            case 0x1D4EDCu: goto label_1d4edc;
            case 0x1D4EE0u: goto label_1d4ee0;
            case 0x1D4EE4u: goto label_1d4ee4;
            case 0x1D4EE8u: goto label_1d4ee8;
            case 0x1D4EECu: goto label_1d4eec;
            case 0x1D4EF0u: goto label_1d4ef0;
            case 0x1D4EF4u: goto label_1d4ef4;
            case 0x1D4EF8u: goto label_1d4ef8;
            case 0x1D4EFCu: goto label_1d4efc;
            case 0x1D4F00u: goto label_1d4f00;
            case 0x1D4F04u: goto label_1d4f04;
            case 0x1D4F08u: goto label_1d4f08;
            case 0x1D4F0Cu: goto label_1d4f0c;
            case 0x1D4F10u: goto label_1d4f10;
            case 0x1D4F14u: goto label_1d4f14;
            case 0x1D4F18u: goto label_1d4f18;
            case 0x1D4F1Cu: goto label_1d4f1c;
            case 0x1D4F20u: goto label_1d4f20;
            case 0x1D4F24u: goto label_1d4f24;
            case 0x1D4F28u: goto label_1d4f28;
            case 0x1D4F2Cu: goto label_1d4f2c;
            case 0x1D4F30u: goto label_1d4f30;
            case 0x1D4F34u: goto label_1d4f34;
            case 0x1D4F38u: goto label_1d4f38;
            case 0x1D4F3Cu: goto label_1d4f3c;
            case 0x1D4F40u: goto label_1d4f40;
            case 0x1D4F44u: goto label_1d4f44;
            case 0x1D4F48u: goto label_1d4f48;
            case 0x1D4F4Cu: goto label_1d4f4c;
            case 0x1D4F50u: goto label_1d4f50;
            case 0x1D4F54u: goto label_1d4f54;
            case 0x1D4F58u: goto label_1d4f58;
            case 0x1D4F5Cu: goto label_1d4f5c;
            case 0x1D4F60u: goto label_1d4f60;
            case 0x1D4F64u: goto label_1d4f64;
            case 0x1D4F68u: goto label_1d4f68;
            case 0x1D4F6Cu: goto label_1d4f6c;
            case 0x1D4F70u: goto label_1d4f70;
            case 0x1D4F74u: goto label_1d4f74;
            case 0x1D4F78u: goto label_1d4f78;
            case 0x1D4F7Cu: goto label_1d4f7c;
            case 0x1D4F80u: goto label_1d4f80;
            case 0x1D4F84u: goto label_1d4f84;
            case 0x1D4F88u: goto label_1d4f88;
            case 0x1D4F8Cu: goto label_1d4f8c;
            case 0x1D4F90u: goto label_1d4f90;
            case 0x1D4F94u: goto label_1d4f94;
            case 0x1D4F98u: goto label_1d4f98;
            case 0x1D4F9Cu: goto label_1d4f9c;
            case 0x1D4FA0u: goto label_1d4fa0;
            case 0x1D4FA4u: goto label_1d4fa4;
            case 0x1D4FA8u: goto label_1d4fa8;
            case 0x1D4FACu: goto label_1d4fac;
            case 0x1D4FB0u: goto label_1d4fb0;
            case 0x1D4FB4u: goto label_1d4fb4;
            case 0x1D4FB8u: goto label_1d4fb8;
            case 0x1D4FBCu: goto label_1d4fbc;
            case 0x1D4FC0u: goto label_1d4fc0;
            case 0x1D4FC4u: goto label_1d4fc4;
            case 0x1D4FC8u: goto label_1d4fc8;
            case 0x1D4FCCu: goto label_1d4fcc;
            case 0x1D4FD0u: goto label_1d4fd0;
            case 0x1D4FD4u: goto label_1d4fd4;
            case 0x1D4FD8u: goto label_1d4fd8;
            case 0x1D4FDCu: goto label_1d4fdc;
            case 0x1D4FE0u: goto label_1d4fe0;
            case 0x1D4FE4u: goto label_1d4fe4;
            case 0x1D4FE8u: goto label_1d4fe8;
            case 0x1D4FECu: goto label_1d4fec;
            case 0x1D4FF0u: goto label_1d4ff0;
            case 0x1D4FF4u: goto label_1d4ff4;
            case 0x1D4FF8u: goto label_1d4ff8;
            case 0x1D4FFCu: goto label_1d4ffc;
            case 0x1D5000u: goto label_1d5000;
            case 0x1D5004u: goto label_1d5004;
            case 0x1D5008u: goto label_1d5008;
            case 0x1D500Cu: goto label_1d500c;
            case 0x1D5010u: goto label_1d5010;
            case 0x1D5014u: goto label_1d5014;
            case 0x1D5018u: goto label_1d5018;
            case 0x1D501Cu: goto label_1d501c;
            case 0x1D5020u: goto label_1d5020;
            case 0x1D5024u: goto label_1d5024;
            case 0x1D5028u: goto label_1d5028;
            case 0x1D502Cu: goto label_1d502c;
            case 0x1D5030u: goto label_1d5030;
            case 0x1D5034u: goto label_1d5034;
            case 0x1D5038u: goto label_1d5038;
            case 0x1D503Cu: goto label_1d503c;
            case 0x1D5040u: goto label_1d5040;
            case 0x1D5044u: goto label_1d5044;
            case 0x1D5048u: goto label_1d5048;
            case 0x1D504Cu: goto label_1d504c;
            case 0x1D5050u: goto label_1d5050;
            case 0x1D5054u: goto label_1d5054;
            case 0x1D5058u: goto label_1d5058;
            case 0x1D505Cu: goto label_1d505c;
            case 0x1D5060u: goto label_1d5060;
            case 0x1D5064u: goto label_1d5064;
            case 0x1D5068u: goto label_1d5068;
            case 0x1D506Cu: goto label_1d506c;
            case 0x1D5070u: goto label_1d5070;
            case 0x1D5074u: goto label_1d5074;
            case 0x1D5078u: goto label_1d5078;
            case 0x1D507Cu: goto label_1d507c;
            case 0x1D5080u: goto label_1d5080;
            case 0x1D5084u: goto label_1d5084;
            case 0x1D5088u: goto label_1d5088;
            case 0x1D508Cu: goto label_1d508c;
            case 0x1D5090u: goto label_1d5090;
            case 0x1D5094u: goto label_1d5094;
            case 0x1D5098u: goto label_1d5098;
            case 0x1D509Cu: goto label_1d509c;
            case 0x1D50A0u: goto label_1d50a0;
            case 0x1D50A4u: goto label_1d50a4;
            case 0x1D50A8u: goto label_1d50a8;
            case 0x1D50ACu: goto label_1d50ac;
            case 0x1D50B0u: goto label_1d50b0;
            case 0x1D50B4u: goto label_1d50b4;
            case 0x1D50B8u: goto label_1d50b8;
            case 0x1D50BCu: goto label_1d50bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D4F90u;
label_1d4f90:
    // 0x1d4f90: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1d4f90u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
label_1d4f94:
    // 0x1d4f94: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4f94u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
label_1d4f98:
    // 0x1d4f98: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x1d4f98u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
label_1d4f9c:
    // 0x1d4f9c: 0x80222650  lb          $v0, 0x2650($at)
    ctx->pc = 0x1d4f9cu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 9808)));
label_1d4fa0:
    // 0x1d4fa0: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_1d4fa4:
    if (ctx->pc == 0x1D4FA4u) {
        ctx->pc = 0x1D4FA4u;
            // 0x1d4fa4: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->pc = 0x1D4FA8u;
        goto label_1d4fa8;
    }
    ctx->pc = 0x1D4FA0u;
    {
        const bool branch_taken_0x1d4fa0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4FA4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4FA0u;
            // 0x1d4fa4: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4fa0) {
            ctx->pc = 0x1D4FB0u;
            goto label_1d4fb0;
        }
    }
    ctx->pc = 0x1D4FA8u;
label_1d4fa8:
    // 0x1d4fa8: 0x10000040  b           . + 4 + (0x40 << 2)
label_1d4fac:
    if (ctx->pc == 0x1D4FACu) {
        ctx->pc = 0x1D4FACu;
            // 0x1d4fac: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1D4FB0u;
        goto label_1d4fb0;
    }
    ctx->pc = 0x1D4FA8u;
    {
        const bool branch_taken_0x1d4fa8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4FACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4FA8u;
            // 0x1d4fac: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4fa8) {
            ctx->pc = 0x1D50ACu;
            goto label_1d50ac;
        }
    }
    ctx->pc = 0x1D4FB0u;
label_1d4fb0:
    // 0x1d4fb0: 0x84222640  lh          $v0, 0x2640($at)
    ctx->pc = 0x1d4fb0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 9792)));
label_1d4fb4:
    // 0x1d4fb4: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
label_1d4fb8:
    if (ctx->pc == 0x1D4FB8u) {
        ctx->pc = 0x1D4FB8u;
            // 0x1d4fb8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1D4FBCu;
        goto label_1d4fbc;
    }
    ctx->pc = 0x1D4FB4u;
    {
        const bool branch_taken_0x1d4fb4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D4FB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4FB4u;
            // 0x1d4fb8: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4fb4) {
            ctx->pc = 0x1D4FECu;
            goto label_1d4fec;
        }
    }
    ctx->pc = 0x1D4FBCu;
label_1d4fbc:
    // 0x1d4fbc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d4fbcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
label_1d4fc0:
    // 0x1d4fc0: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1d4fc0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
label_1d4fc4:
    // 0x1d4fc4: 0x80232648  lb          $v1, 0x2648($at)
    ctx->pc = 0x1d4fc4u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 9800)));
label_1d4fc8:
    // 0x1d4fc8: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1d4fc8u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
label_1d4fcc:
    // 0x1d4fcc: 0x24426960  addiu       $v0, $v0, 0x6960
    ctx->pc = 0x1d4fccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 26976));
label_1d4fd0:
    // 0x1d4fd0: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1d4fd0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
label_1d4fd4:
    // 0x1d4fd4: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1d4fd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
label_1d4fd8:
    // 0x1d4fd8: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1d4fd8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_1d4fdc:
    // 0x1d4fdc: 0x40f809  jalr        $v0
label_1d4fe0:
    if (ctx->pc == 0x1D4FE0u) {
        ctx->pc = 0x1D4FE0u;
            // 0x1d4fe0: 0x24842648  addiu       $a0, $a0, 0x2648 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9800));
        ctx->pc = 0x1D4FE4u;
        goto label_1d4fe4;
    }
    ctx->pc = 0x1D4FDCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1D4FE4u);
        ctx->pc = 0x1D4FE0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4FDCu;
            // 0x1d4fe0: 0x24842648  addiu       $a0, $a0, 0x2648 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 9800));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1D4FE4u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4CA0u: goto label_1d4ca0;
            case 0x1D4CA4u: goto label_1d4ca4;
            case 0x1D4CA8u: goto label_1d4ca8;
            case 0x1D4CACu: goto label_1d4cac;
            case 0x1D4CB0u: goto label_1d4cb0;
            case 0x1D4CB4u: goto label_1d4cb4;
            case 0x1D4CB8u: goto label_1d4cb8;
            case 0x1D4CBCu: goto label_1d4cbc;
            case 0x1D4CC0u: goto label_1d4cc0;
            case 0x1D4CC4u: goto label_1d4cc4;
            case 0x1D4CC8u: goto label_1d4cc8;
            case 0x1D4CCCu: goto label_1d4ccc;
            case 0x1D4CD0u: goto label_1d4cd0;
            case 0x1D4CD4u: goto label_1d4cd4;
            case 0x1D4CD8u: goto label_1d4cd8;
            case 0x1D4CDCu: goto label_1d4cdc;
            case 0x1D4CE0u: goto label_1d4ce0;
            case 0x1D4CE4u: goto label_1d4ce4;
            case 0x1D4CE8u: goto label_1d4ce8;
            case 0x1D4CECu: goto label_1d4cec;
            case 0x1D4CF0u: goto label_1d4cf0;
            case 0x1D4CF4u: goto label_1d4cf4;
            case 0x1D4CF8u: goto label_1d4cf8;
            case 0x1D4CFCu: goto label_1d4cfc;
            case 0x1D4D00u: goto label_1d4d00;
            case 0x1D4D04u: goto label_1d4d04;
            case 0x1D4D08u: goto label_1d4d08;
            case 0x1D4D0Cu: goto label_1d4d0c;
            case 0x1D4D10u: goto label_1d4d10;
            case 0x1D4D14u: goto label_1d4d14;
            case 0x1D4D18u: goto label_1d4d18;
            case 0x1D4D1Cu: goto label_1d4d1c;
            case 0x1D4D20u: goto label_1d4d20;
            case 0x1D4D24u: goto label_1d4d24;
            case 0x1D4D28u: goto label_1d4d28;
            case 0x1D4D2Cu: goto label_1d4d2c;
            case 0x1D4D30u: goto label_1d4d30;
            case 0x1D4D34u: goto label_1d4d34;
            case 0x1D4D38u: goto label_1d4d38;
            case 0x1D4D3Cu: goto label_1d4d3c;
            case 0x1D4D40u: goto label_1d4d40;
            case 0x1D4D44u: goto label_1d4d44;
            case 0x1D4D48u: goto label_1d4d48;
            case 0x1D4D4Cu: goto label_1d4d4c;
            case 0x1D4D50u: goto label_1d4d50;
            case 0x1D4D54u: goto label_1d4d54;
            case 0x1D4D58u: goto label_1d4d58;
            case 0x1D4D5Cu: goto label_1d4d5c;
            case 0x1D4D60u: goto label_1d4d60;
            case 0x1D4D64u: goto label_1d4d64;
            case 0x1D4D68u: goto label_1d4d68;
            case 0x1D4D6Cu: goto label_1d4d6c;
            case 0x1D4D70u: goto label_1d4d70;
            case 0x1D4D74u: goto label_1d4d74;
            case 0x1D4D78u: goto label_1d4d78;
            case 0x1D4D7Cu: goto label_1d4d7c;
            case 0x1D4D80u: goto label_1d4d80;
            case 0x1D4D84u: goto label_1d4d84;
            case 0x1D4D88u: goto label_1d4d88;
            case 0x1D4D8Cu: goto label_1d4d8c;
            case 0x1D4D90u: goto label_1d4d90;
            case 0x1D4D94u: goto label_1d4d94;
            case 0x1D4D98u: goto label_1d4d98;
            case 0x1D4D9Cu: goto label_1d4d9c;
            case 0x1D4DA0u: goto label_1d4da0;
            case 0x1D4DA4u: goto label_1d4da4;
            case 0x1D4DA8u: goto label_1d4da8;
            case 0x1D4DACu: goto label_1d4dac;
            case 0x1D4DB0u: goto label_1d4db0;
            case 0x1D4DB4u: goto label_1d4db4;
            case 0x1D4DB8u: goto label_1d4db8;
            case 0x1D4DBCu: goto label_1d4dbc;
            case 0x1D4DC0u: goto label_1d4dc0;
            case 0x1D4DC4u: goto label_1d4dc4;
            case 0x1D4DC8u: goto label_1d4dc8;
            case 0x1D4DCCu: goto label_1d4dcc;
            case 0x1D4DD0u: goto label_1d4dd0;
            case 0x1D4DD4u: goto label_1d4dd4;
            case 0x1D4DD8u: goto label_1d4dd8;
            case 0x1D4DDCu: goto label_1d4ddc;
            case 0x1D4DE0u: goto label_1d4de0;
            case 0x1D4DE4u: goto label_1d4de4;
            case 0x1D4DE8u: goto label_1d4de8;
            case 0x1D4DECu: goto label_1d4dec;
            case 0x1D4DF0u: goto label_1d4df0;
            case 0x1D4DF4u: goto label_1d4df4;
            case 0x1D4DF8u: goto label_1d4df8;
            case 0x1D4DFCu: goto label_1d4dfc;
            case 0x1D4E00u: goto label_1d4e00;
            case 0x1D4E04u: goto label_1d4e04;
            case 0x1D4E08u: goto label_1d4e08;
            case 0x1D4E0Cu: goto label_1d4e0c;
            case 0x1D4E10u: goto label_1d4e10;
            case 0x1D4E14u: goto label_1d4e14;
            case 0x1D4E18u: goto label_1d4e18;
            case 0x1D4E1Cu: goto label_1d4e1c;
            case 0x1D4E20u: goto label_1d4e20;
            case 0x1D4E24u: goto label_1d4e24;
            case 0x1D4E28u: goto label_1d4e28;
            case 0x1D4E2Cu: goto label_1d4e2c;
            case 0x1D4E30u: goto label_1d4e30;
            case 0x1D4E34u: goto label_1d4e34;
            case 0x1D4E38u: goto label_1d4e38;
            case 0x1D4E3Cu: goto label_1d4e3c;
            case 0x1D4E40u: goto label_1d4e40;
            case 0x1D4E44u: goto label_1d4e44;
            case 0x1D4E48u: goto label_1d4e48;
            case 0x1D4E4Cu: goto label_1d4e4c;
            case 0x1D4E50u: goto label_1d4e50;
            case 0x1D4E54u: goto label_1d4e54;
            case 0x1D4E58u: goto label_1d4e58;
            case 0x1D4E5Cu: goto label_1d4e5c;
            case 0x1D4E60u: goto label_1d4e60;
            case 0x1D4E64u: goto label_1d4e64;
            case 0x1D4E68u: goto label_1d4e68;
            case 0x1D4E6Cu: goto label_1d4e6c;
            case 0x1D4E70u: goto label_1d4e70;
            case 0x1D4E74u: goto label_1d4e74;
            case 0x1D4E78u: goto label_1d4e78;
            case 0x1D4E7Cu: goto label_1d4e7c;
            case 0x1D4E80u: goto label_1d4e80;
            case 0x1D4E84u: goto label_1d4e84;
            case 0x1D4E88u: goto label_1d4e88;
            case 0x1D4E8Cu: goto label_1d4e8c;
            case 0x1D4E90u: goto label_1d4e90;
            case 0x1D4E94u: goto label_1d4e94;
            case 0x1D4E98u: goto label_1d4e98;
            case 0x1D4E9Cu: goto label_1d4e9c;
            case 0x1D4EA0u: goto label_1d4ea0;
            case 0x1D4EA4u: goto label_1d4ea4;
            case 0x1D4EA8u: goto label_1d4ea8;
            case 0x1D4EACu: goto label_1d4eac;
            case 0x1D4EB0u: goto label_1d4eb0;
            case 0x1D4EB4u: goto label_1d4eb4;
            case 0x1D4EB8u: goto label_1d4eb8;
            case 0x1D4EBCu: goto label_1d4ebc;
            case 0x1D4EC0u: goto label_1d4ec0;
            case 0x1D4EC4u: goto label_1d4ec4;
            case 0x1D4EC8u: goto label_1d4ec8;
            case 0x1D4ECCu: goto label_1d4ecc;
            case 0x1D4ED0u: goto label_1d4ed0;
            case 0x1D4ED4u: goto label_1d4ed4;
            case 0x1D4ED8u: goto label_1d4ed8;
            case 0x1D4EDCu: goto label_1d4edc;
            case 0x1D4EE0u: goto label_1d4ee0;
            case 0x1D4EE4u: goto label_1d4ee4;
            case 0x1D4EE8u: goto label_1d4ee8;
            case 0x1D4EECu: goto label_1d4eec;
            case 0x1D4EF0u: goto label_1d4ef0;
            case 0x1D4EF4u: goto label_1d4ef4;
            case 0x1D4EF8u: goto label_1d4ef8;
            case 0x1D4EFCu: goto label_1d4efc;
            case 0x1D4F00u: goto label_1d4f00;
            case 0x1D4F04u: goto label_1d4f04;
            case 0x1D4F08u: goto label_1d4f08;
            case 0x1D4F0Cu: goto label_1d4f0c;
            case 0x1D4F10u: goto label_1d4f10;
            case 0x1D4F14u: goto label_1d4f14;
            case 0x1D4F18u: goto label_1d4f18;
            case 0x1D4F1Cu: goto label_1d4f1c;
            case 0x1D4F20u: goto label_1d4f20;
            case 0x1D4F24u: goto label_1d4f24;
            case 0x1D4F28u: goto label_1d4f28;
            case 0x1D4F2Cu: goto label_1d4f2c;
            case 0x1D4F30u: goto label_1d4f30;
            case 0x1D4F34u: goto label_1d4f34;
            case 0x1D4F38u: goto label_1d4f38;
            case 0x1D4F3Cu: goto label_1d4f3c;
            case 0x1D4F40u: goto label_1d4f40;
            case 0x1D4F44u: goto label_1d4f44;
            case 0x1D4F48u: goto label_1d4f48;
            case 0x1D4F4Cu: goto label_1d4f4c;
            case 0x1D4F50u: goto label_1d4f50;
            case 0x1D4F54u: goto label_1d4f54;
            case 0x1D4F58u: goto label_1d4f58;
            case 0x1D4F5Cu: goto label_1d4f5c;
            case 0x1D4F60u: goto label_1d4f60;
            case 0x1D4F64u: goto label_1d4f64;
            case 0x1D4F68u: goto label_1d4f68;
            case 0x1D4F6Cu: goto label_1d4f6c;
            case 0x1D4F70u: goto label_1d4f70;
            case 0x1D4F74u: goto label_1d4f74;
            case 0x1D4F78u: goto label_1d4f78;
            case 0x1D4F7Cu: goto label_1d4f7c;
            case 0x1D4F80u: goto label_1d4f80;
            case 0x1D4F84u: goto label_1d4f84;
            case 0x1D4F88u: goto label_1d4f88;
            case 0x1D4F8Cu: goto label_1d4f8c;
            case 0x1D4F90u: goto label_1d4f90;
            case 0x1D4F94u: goto label_1d4f94;
            case 0x1D4F98u: goto label_1d4f98;
            case 0x1D4F9Cu: goto label_1d4f9c;
            case 0x1D4FA0u: goto label_1d4fa0;
            case 0x1D4FA4u: goto label_1d4fa4;
            case 0x1D4FA8u: goto label_1d4fa8;
            case 0x1D4FACu: goto label_1d4fac;
            case 0x1D4FB0u: goto label_1d4fb0;
            case 0x1D4FB4u: goto label_1d4fb4;
            case 0x1D4FB8u: goto label_1d4fb8;
            case 0x1D4FBCu: goto label_1d4fbc;
            case 0x1D4FC0u: goto label_1d4fc0;
            case 0x1D4FC4u: goto label_1d4fc4;
            case 0x1D4FC8u: goto label_1d4fc8;
            case 0x1D4FCCu: goto label_1d4fcc;
            case 0x1D4FD0u: goto label_1d4fd0;
            case 0x1D4FD4u: goto label_1d4fd4;
            case 0x1D4FD8u: goto label_1d4fd8;
            case 0x1D4FDCu: goto label_1d4fdc;
            case 0x1D4FE0u: goto label_1d4fe0;
            case 0x1D4FE4u: goto label_1d4fe4;
            case 0x1D4FE8u: goto label_1d4fe8;
            case 0x1D4FECu: goto label_1d4fec;
            case 0x1D4FF0u: goto label_1d4ff0;
            case 0x1D4FF4u: goto label_1d4ff4;
            case 0x1D4FF8u: goto label_1d4ff8;
            case 0x1D4FFCu: goto label_1d4ffc;
            case 0x1D5000u: goto label_1d5000;
            case 0x1D5004u: goto label_1d5004;
            case 0x1D5008u: goto label_1d5008;
            case 0x1D500Cu: goto label_1d500c;
            case 0x1D5010u: goto label_1d5010;
            case 0x1D5014u: goto label_1d5014;
            case 0x1D5018u: goto label_1d5018;
            case 0x1D501Cu: goto label_1d501c;
            case 0x1D5020u: goto label_1d5020;
            case 0x1D5024u: goto label_1d5024;
            case 0x1D5028u: goto label_1d5028;
            case 0x1D502Cu: goto label_1d502c;
            case 0x1D5030u: goto label_1d5030;
            case 0x1D5034u: goto label_1d5034;
            case 0x1D5038u: goto label_1d5038;
            case 0x1D503Cu: goto label_1d503c;
            case 0x1D5040u: goto label_1d5040;
            case 0x1D5044u: goto label_1d5044;
            case 0x1D5048u: goto label_1d5048;
            case 0x1D504Cu: goto label_1d504c;
            case 0x1D5050u: goto label_1d5050;
            case 0x1D5054u: goto label_1d5054;
            case 0x1D5058u: goto label_1d5058;
            case 0x1D505Cu: goto label_1d505c;
            case 0x1D5060u: goto label_1d5060;
            case 0x1D5064u: goto label_1d5064;
            case 0x1D5068u: goto label_1d5068;
            case 0x1D506Cu: goto label_1d506c;
            case 0x1D5070u: goto label_1d5070;
            case 0x1D5074u: goto label_1d5074;
            case 0x1D5078u: goto label_1d5078;
            case 0x1D507Cu: goto label_1d507c;
            case 0x1D5080u: goto label_1d5080;
            case 0x1D5084u: goto label_1d5084;
            case 0x1D5088u: goto label_1d5088;
            case 0x1D508Cu: goto label_1d508c;
            case 0x1D5090u: goto label_1d5090;
            case 0x1D5094u: goto label_1d5094;
            case 0x1D5098u: goto label_1d5098;
            case 0x1D509Cu: goto label_1d509c;
            case 0x1D50A0u: goto label_1d50a0;
            case 0x1D50A4u: goto label_1d50a4;
            case 0x1D50A8u: goto label_1d50a8;
            case 0x1D50ACu: goto label_1d50ac;
            case 0x1D50B0u: goto label_1d50b0;
            case 0x1D50B4u: goto label_1d50b4;
            case 0x1D50B8u: goto label_1d50b8;
            case 0x1D50BCu: goto label_1d50bc;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1D4FE4u; }
            if (ctx->pc != 0x1D4FE4u) { return; }
        }
        }
    }
    ctx->pc = 0x1D4FE4u;
label_1d4fe4:
    // 0x1d4fe4: 0x10000031  b           . + 4 + (0x31 << 2)
label_1d4fe8:
    if (ctx->pc == 0x1D4FE8u) {
        ctx->pc = 0x1D4FE8u;
            // 0x1d4fe8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1D4FECu;
        goto label_1d4fec;
    }
    ctx->pc = 0x1D4FE4u;
    {
        const bool branch_taken_0x1d4fe4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D4FE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4FE4u;
            // 0x1d4fe8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4fe4) {
            ctx->pc = 0x1D50ACu;
            goto label_1d50ac;
        }
    }
    ctx->pc = 0x1D4FECu;
label_1d4fec:
    // 0x1d4fec: 0xc075430  jal         func_1D50C0
label_1d4ff0:
    if (ctx->pc == 0x1D4FF0u) {
        ctx->pc = 0x1D4FF4u;
        goto label_1d4ff4;
    }
    ctx->pc = 0x1D4FECu;
    SET_GPR_U32(ctx, 31, 0x1D4FF4u);
    ctx->pc = 0x1D50C0u;
    if (runtime->hasFunction(0x1D50C0u)) {
        auto targetFn = runtime->lookupFunction(0x1D50C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4FF4u; }
        if (ctx->pc != 0x1D4FF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D50C0_0x1d50c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D4FF4u; }
        if (ctx->pc != 0x1D4FF4u) { return; }
    }
    ctx->pc = 0x1D4FF4u;
label_1d4ff4:
    // 0x1d4ff4: 0x2403ffff  addiu       $v1, $zero, -0x1
    ctx->pc = 0x1d4ff4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
label_1d4ff8:
    // 0x1d4ff8: 0x14430003  bne         $v0, $v1, . + 4 + (0x3 << 2)
label_1d4ffc:
    if (ctx->pc == 0x1D4FFCu) {
        ctx->pc = 0x1D4FFCu;
            // 0x1d4ffc: 0x3c050034  lui         $a1, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
        ctx->pc = 0x1D5000u;
        goto label_1d5000;
    }
    ctx->pc = 0x1D4FF8u;
    {
        const bool branch_taken_0x1d4ff8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 3));
        ctx->pc = 0x1D4FFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D4FF8u;
            // 0x1d4ffc: 0x3c050034  lui         $a1, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d4ff8) {
            ctx->pc = 0x1D5008u;
            goto label_1d5008;
        }
    }
    ctx->pc = 0x1D5000u;
label_1d5000:
    // 0x1d5000: 0x1000002a  b           . + 4 + (0x2A << 2)
label_1d5004:
    if (ctx->pc == 0x1D5004u) {
        ctx->pc = 0x1D5004u;
            // 0x1d5004: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1D5008u;
        goto label_1d5008;
    }
    ctx->pc = 0x1D5000u;
    {
        const bool branch_taken_0x1d5000 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D5004u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5000u;
            // 0x1d5004: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5000) {
            ctx->pc = 0x1D50ACu;
            goto label_1d50ac;
        }
    }
    ctx->pc = 0x1D5008u;
label_1d5008:
    // 0x1d5008: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d5008u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d500c:
    // 0x1d500c: 0xc075526  jal         func_1D5498
label_1d5010:
    if (ctx->pc == 0x1D5010u) {
        ctx->pc = 0x1D5010u;
            // 0x1d5010: 0x24a52690  addiu       $a1, $a1, 0x2690 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 9872));
        ctx->pc = 0x1D5014u;
        goto label_1d5014;
    }
    ctx->pc = 0x1D500Cu;
    SET_GPR_U32(ctx, 31, 0x1D5014u);
    ctx->pc = 0x1D5010u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D500Cu;
            // 0x1d5010: 0x24a52690  addiu       $a1, $a1, 0x2690 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 9872));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D5498u;
    if (runtime->hasFunction(0x1D5498u)) {
        auto targetFn = runtime->lookupFunction(0x1D5498u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5014u; }
        if (ctx->pc != 0x1D5014u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D5498_0x1d5498(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5014u; }
        if (ctx->pc != 0x1D5014u) { return; }
    }
    ctx->pc = 0x1D5014u;
label_1d5014:
    // 0x1d5014: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1d5014u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
label_1d5018:
    // 0x1d5018: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d5018u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
label_1d501c:
    // 0x1d501c: 0x248427b0  addiu       $a0, $a0, 0x27B0
    ctx->pc = 0x1d501cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 10160));
label_1d5020:
    // 0x1d5020: 0x24a52690  addiu       $a1, $a1, 0x2690
    ctx->pc = 0x1d5020u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 9872));
label_1d5024:
    // 0x1d5024: 0xc041eac  jal         func_107AB0
label_1d5028:
    if (ctx->pc == 0x1D5028u) {
        ctx->pc = 0x1D5028u;
            // 0x1d5028: 0x24060088  addiu       $a2, $zero, 0x88 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 136));
        ctx->pc = 0x1D502Cu;
        goto label_1d502c;
    }
    ctx->pc = 0x1D5024u;
    SET_GPR_U32(ctx, 31, 0x1D502Cu);
    ctx->pc = 0x1D5028u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5024u;
            // 0x1d5028: 0x24060088  addiu       $a2, $zero, 0x88 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 136));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107AB0u;
    if (runtime->hasFunction(0x107AB0u)) {
        auto targetFn = runtime->lookupFunction(0x107AB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D502Cu; }
        if (ctx->pc != 0x1D502Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107AB0_0x107ab0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D502Cu; }
        if (ctx->pc != 0x1D502Cu) { return; }
    }
    ctx->pc = 0x1D502Cu;
label_1d502c:
    // 0x1d502c: 0x202d  daddu       $a0, $zero, $zero
    ctx->pc = 0x1d502cu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1d5030:
    // 0x1d5030: 0xc075646  jal         func_1D5918
label_1d5034:
    if (ctx->pc == 0x1D5034u) {
        ctx->pc = 0x1D5034u;
            // 0x1d5034: 0x27a5001c  addiu       $a1, $sp, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 28));
        ctx->pc = 0x1D5038u;
        goto label_1d5038;
    }
    ctx->pc = 0x1D5030u;
    SET_GPR_U32(ctx, 31, 0x1D5038u);
    ctx->pc = 0x1D5034u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5030u;
            // 0x1d5034: 0x27a5001c  addiu       $a1, $sp, 0x1C (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 29), 28));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D5918u;
    if (runtime->hasFunction(0x1D5918u)) {
        auto targetFn = runtime->lookupFunction(0x1D5918u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5038u; }
        if (ctx->pc != 0x1D5038u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D5918_0x1d5918(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1D5038u; }
        if (ctx->pc != 0x1D5038u) { return; }
    }
    ctx->pc = 0x1D5038u;
label_1d5038:
    // 0x1d5038: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d5038u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
label_1d503c:
    // 0x1d503c: 0x8c222698  lw          $v0, 0x2698($at)
    ctx->pc = 0x1d503cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 9880)));
label_1d5040:
    // 0x1d5040: 0x14400003  bnez        $v0, . + 4 + (0x3 << 2)
label_1d5044:
    if (ctx->pc == 0x1D5044u) {
        ctx->pc = 0x1D5044u;
            // 0x1d5044: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->pc = 0x1D5048u;
        goto label_1d5048;
    }
    ctx->pc = 0x1D5040u;
    {
        const bool branch_taken_0x1d5040 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1D5044u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5040u;
            // 0x1d5044: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5040) {
            ctx->pc = 0x1D5050u;
            goto label_1d5050;
        }
    }
    ctx->pc = 0x1D5048u;
label_1d5048:
    // 0x1d5048: 0x10000018  b           . + 4 + (0x18 << 2)
label_1d504c:
    if (ctx->pc == 0x1D504Cu) {
        ctx->pc = 0x1D504Cu;
            // 0x1d504c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x1D5050u;
        goto label_1d5050;
    }
    ctx->pc = 0x1D5048u;
    {
        const bool branch_taken_0x1d5048 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1D504Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D5048u;
            // 0x1d504c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d5048) {
            ctx->pc = 0x1D50ACu;
            goto label_1d50ac;
        }
    }
    ctx->pc = 0x1D5050u;
label_1d5050:
    // 0x1d5050: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d5050u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
label_1d5054:
    // 0x1d5054: 0x8c232694  lw          $v1, 0x2694($at)
    ctx->pc = 0x1d5054u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 9876)));
label_1d5058:
    // 0x1d5058: 0x24422660  addiu       $v0, $v0, 0x2660
    ctx->pc = 0x1d5058u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 9824));
label_1d505c:
    // 0x1d505c: 0x24060006  addiu       $a2, $zero, 0x6
    ctx->pc = 0x1d505cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
label_1d5060:
    // 0x1d5060: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d5060u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
label_1d5064:
    // 0x1d5064: 0xac222670  sw          $v0, 0x2670($at)
    ctx->pc = 0x1d5064u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 9840), GPR_U32(ctx, 2));
label_1d5068:
    // 0x1d5068: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d5068u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
label_1d506c:
    // 0x1d506c: 0x8c222690  lw          $v0, 0x2690($at)
    ctx->pc = 0x1d506cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 9872)));
label_1d5070:
    // 0x1d5070: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d5070u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
label_1d5074:
    // 0x1d5074: 0xa0232668  sb          $v1, 0x2668($at)
    ctx->pc = 0x1d5074u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 9832), (uint8_t)GPR_U32(ctx, 3));
label_1d5078:
    // 0x1d5078: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1d5078u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
label_1d507c:
    // 0x1d507c: 0xa0222669  sb          $v0, 0x2669($at)
    ctx->pc = 0x1d507cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 9833), (uint8_t)GPR_U32(ctx, 2));
label_1d5080:
    // 0x1d5080: 0x3c050034  lui         $a1, 0x34
    ctx->pc = 0x1d5080u;
    SET_GPR_S32(ctx, 5, (int32_t)((uint32_t)52 << 16));
label_1d5084:
    // 0x1d5084: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1d5084u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
label_1d5088:
    // 0x1d5088: 0x24a52690  addiu       $a1, $a1, 0x2690
    ctx->pc = 0x1d5088u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 9872));
label_1d508c:
    // 0x1d508c: 0x24422668  addiu       $v0, $v0, 0x2668
    ctx->pc = 0x1d508cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 9832));
label_1d5090:
    // 0x1d5090: 0x62040  sll         $a0, $a2, 1
    ctx->pc = 0x1d5090u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 6), 1));
label_1d5094:
    // 0x1d5094: 0x461821  addu        $v1, $v0, $a2
    ctx->pc = 0x1d5094u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
label_1d5098:
    // 0x1d5098: 0xa42021  addu        $a0, $a1, $a0
    ctx->pc = 0x1d5098u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 5), GPR_U32(ctx, 4)));
label_1d509c:
    // 0x1d509c: 0x24c6ffff  addiu       $a2, $a2, -0x1
    ctx->pc = 0x1d509cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 4294967295));
label_1d50a0:
    // 0x1d50a0: 0x9484000c  lhu         $a0, 0xC($a0)
    ctx->pc = 0x1d50a0u;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 4), 12)));
label_1d50a4:
    // 0x1d50a4: 0x4c1fffa  bgez        $a2, . + 4 + (-0x6 << 2)
label_1d50a8:
    if (ctx->pc == 0x1D50A8u) {
        ctx->pc = 0x1D50A8u;
            // 0x1d50a8: 0xa0640002  sb          $a0, 0x2($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 4));
        ctx->pc = 0x1D50ACu;
        goto label_1d50ac;
    }
    ctx->pc = 0x1D50A4u;
    {
        const bool branch_taken_0x1d50a4 = (GPR_S64(ctx, 6) >= 0);
        ctx->pc = 0x1D50A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D50A4u;
            // 0x1d50a8: 0xa0640002  sb          $a0, 0x2($v1) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 3), 2), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1d50a4) {
            ctx->pc = 0x1D5090u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1d5090;
        }
    }
    ctx->pc = 0x1D50ACu;
label_1d50ac:
    // 0x1d50ac: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x1d50acu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1d50b0:
    // 0x1d50b0: 0x3e00008  jr          $ra
label_1d50b4:
    if (ctx->pc == 0x1D50B4u) {
        ctx->pc = 0x1D50B4u;
            // 0x1d50b4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x1D50B8u;
        goto label_1d50b8;
    }
    ctx->pc = 0x1D50B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1D50B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1D50B0u;
            // 0x1d50b4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1D4CA0u: goto label_1d4ca0;
            case 0x1D4CA4u: goto label_1d4ca4;
            case 0x1D4CA8u: goto label_1d4ca8;
            case 0x1D4CACu: goto label_1d4cac;
            case 0x1D4CB0u: goto label_1d4cb0;
            case 0x1D4CB4u: goto label_1d4cb4;
            case 0x1D4CB8u: goto label_1d4cb8;
            case 0x1D4CBCu: goto label_1d4cbc;
            case 0x1D4CC0u: goto label_1d4cc0;
            case 0x1D4CC4u: goto label_1d4cc4;
            case 0x1D4CC8u: goto label_1d4cc8;
            case 0x1D4CCCu: goto label_1d4ccc;
            case 0x1D4CD0u: goto label_1d4cd0;
            case 0x1D4CD4u: goto label_1d4cd4;
            case 0x1D4CD8u: goto label_1d4cd8;
            case 0x1D4CDCu: goto label_1d4cdc;
            case 0x1D4CE0u: goto label_1d4ce0;
            case 0x1D4CE4u: goto label_1d4ce4;
            case 0x1D4CE8u: goto label_1d4ce8;
            case 0x1D4CECu: goto label_1d4cec;
            case 0x1D4CF0u: goto label_1d4cf0;
            case 0x1D4CF4u: goto label_1d4cf4;
            case 0x1D4CF8u: goto label_1d4cf8;
            case 0x1D4CFCu: goto label_1d4cfc;
            case 0x1D4D00u: goto label_1d4d00;
            case 0x1D4D04u: goto label_1d4d04;
            case 0x1D4D08u: goto label_1d4d08;
            case 0x1D4D0Cu: goto label_1d4d0c;
            case 0x1D4D10u: goto label_1d4d10;
            case 0x1D4D14u: goto label_1d4d14;
            case 0x1D4D18u: goto label_1d4d18;
            case 0x1D4D1Cu: goto label_1d4d1c;
            case 0x1D4D20u: goto label_1d4d20;
            case 0x1D4D24u: goto label_1d4d24;
            case 0x1D4D28u: goto label_1d4d28;
            case 0x1D4D2Cu: goto label_1d4d2c;
            case 0x1D4D30u: goto label_1d4d30;
            case 0x1D4D34u: goto label_1d4d34;
            case 0x1D4D38u: goto label_1d4d38;
            case 0x1D4D3Cu: goto label_1d4d3c;
            case 0x1D4D40u: goto label_1d4d40;
            case 0x1D4D44u: goto label_1d4d44;
            case 0x1D4D48u: goto label_1d4d48;
            case 0x1D4D4Cu: goto label_1d4d4c;
            case 0x1D4D50u: goto label_1d4d50;
            case 0x1D4D54u: goto label_1d4d54;
            case 0x1D4D58u: goto label_1d4d58;
            case 0x1D4D5Cu: goto label_1d4d5c;
            case 0x1D4D60u: goto label_1d4d60;
            case 0x1D4D64u: goto label_1d4d64;
            case 0x1D4D68u: goto label_1d4d68;
            case 0x1D4D6Cu: goto label_1d4d6c;
            case 0x1D4D70u: goto label_1d4d70;
            case 0x1D4D74u: goto label_1d4d74;
            case 0x1D4D78u: goto label_1d4d78;
            case 0x1D4D7Cu: goto label_1d4d7c;
            case 0x1D4D80u: goto label_1d4d80;
            case 0x1D4D84u: goto label_1d4d84;
            case 0x1D4D88u: goto label_1d4d88;
            case 0x1D4D8Cu: goto label_1d4d8c;
            case 0x1D4D90u: goto label_1d4d90;
            case 0x1D4D94u: goto label_1d4d94;
            case 0x1D4D98u: goto label_1d4d98;
            case 0x1D4D9Cu: goto label_1d4d9c;
            case 0x1D4DA0u: goto label_1d4da0;
            case 0x1D4DA4u: goto label_1d4da4;
            case 0x1D4DA8u: goto label_1d4da8;
            case 0x1D4DACu: goto label_1d4dac;
            case 0x1D4DB0u: goto label_1d4db0;
            case 0x1D4DB4u: goto label_1d4db4;
            case 0x1D4DB8u: goto label_1d4db8;
            case 0x1D4DBCu: goto label_1d4dbc;
            case 0x1D4DC0u: goto label_1d4dc0;
            case 0x1D4DC4u: goto label_1d4dc4;
            case 0x1D4DC8u: goto label_1d4dc8;
            case 0x1D4DCCu: goto label_1d4dcc;
            case 0x1D4DD0u: goto label_1d4dd0;
            case 0x1D4DD4u: goto label_1d4dd4;
            case 0x1D4DD8u: goto label_1d4dd8;
            case 0x1D4DDCu: goto label_1d4ddc;
            case 0x1D4DE0u: goto label_1d4de0;
            case 0x1D4DE4u: goto label_1d4de4;
            case 0x1D4DE8u: goto label_1d4de8;
            case 0x1D4DECu: goto label_1d4dec;
            case 0x1D4DF0u: goto label_1d4df0;
            case 0x1D4DF4u: goto label_1d4df4;
            case 0x1D4DF8u: goto label_1d4df8;
            case 0x1D4DFCu: goto label_1d4dfc;
            case 0x1D4E00u: goto label_1d4e00;
            case 0x1D4E04u: goto label_1d4e04;
            case 0x1D4E08u: goto label_1d4e08;
            case 0x1D4E0Cu: goto label_1d4e0c;
            case 0x1D4E10u: goto label_1d4e10;
            case 0x1D4E14u: goto label_1d4e14;
            case 0x1D4E18u: goto label_1d4e18;
            case 0x1D4E1Cu: goto label_1d4e1c;
            case 0x1D4E20u: goto label_1d4e20;
            case 0x1D4E24u: goto label_1d4e24;
            case 0x1D4E28u: goto label_1d4e28;
            case 0x1D4E2Cu: goto label_1d4e2c;
            case 0x1D4E30u: goto label_1d4e30;
            case 0x1D4E34u: goto label_1d4e34;
            case 0x1D4E38u: goto label_1d4e38;
            case 0x1D4E3Cu: goto label_1d4e3c;
            case 0x1D4E40u: goto label_1d4e40;
            case 0x1D4E44u: goto label_1d4e44;
            case 0x1D4E48u: goto label_1d4e48;
            case 0x1D4E4Cu: goto label_1d4e4c;
            case 0x1D4E50u: goto label_1d4e50;
            case 0x1D4E54u: goto label_1d4e54;
            case 0x1D4E58u: goto label_1d4e58;
            case 0x1D4E5Cu: goto label_1d4e5c;
            case 0x1D4E60u: goto label_1d4e60;
            case 0x1D4E64u: goto label_1d4e64;
            case 0x1D4E68u: goto label_1d4e68;
            case 0x1D4E6Cu: goto label_1d4e6c;
            case 0x1D4E70u: goto label_1d4e70;
            case 0x1D4E74u: goto label_1d4e74;
            case 0x1D4E78u: goto label_1d4e78;
            case 0x1D4E7Cu: goto label_1d4e7c;
            case 0x1D4E80u: goto label_1d4e80;
            case 0x1D4E84u: goto label_1d4e84;
            case 0x1D4E88u: goto label_1d4e88;
            case 0x1D4E8Cu: goto label_1d4e8c;
            case 0x1D4E90u: goto label_1d4e90;
            case 0x1D4E94u: goto label_1d4e94;
            case 0x1D4E98u: goto label_1d4e98;
            case 0x1D4E9Cu: goto label_1d4e9c;
            case 0x1D4EA0u: goto label_1d4ea0;
            case 0x1D4EA4u: goto label_1d4ea4;
            case 0x1D4EA8u: goto label_1d4ea8;
            case 0x1D4EACu: goto label_1d4eac;
            case 0x1D4EB0u: goto label_1d4eb0;
            case 0x1D4EB4u: goto label_1d4eb4;
            case 0x1D4EB8u: goto label_1d4eb8;
            case 0x1D4EBCu: goto label_1d4ebc;
            case 0x1D4EC0u: goto label_1d4ec0;
            case 0x1D4EC4u: goto label_1d4ec4;
            case 0x1D4EC8u: goto label_1d4ec8;
            case 0x1D4ECCu: goto label_1d4ecc;
            case 0x1D4ED0u: goto label_1d4ed0;
            case 0x1D4ED4u: goto label_1d4ed4;
            case 0x1D4ED8u: goto label_1d4ed8;
            case 0x1D4EDCu: goto label_1d4edc;
            case 0x1D4EE0u: goto label_1d4ee0;
            case 0x1D4EE4u: goto label_1d4ee4;
            case 0x1D4EE8u: goto label_1d4ee8;
            case 0x1D4EECu: goto label_1d4eec;
            case 0x1D4EF0u: goto label_1d4ef0;
            case 0x1D4EF4u: goto label_1d4ef4;
            case 0x1D4EF8u: goto label_1d4ef8;
            case 0x1D4EFCu: goto label_1d4efc;
            case 0x1D4F00u: goto label_1d4f00;
            case 0x1D4F04u: goto label_1d4f04;
            case 0x1D4F08u: goto label_1d4f08;
            case 0x1D4F0Cu: goto label_1d4f0c;
            case 0x1D4F10u: goto label_1d4f10;
            case 0x1D4F14u: goto label_1d4f14;
            case 0x1D4F18u: goto label_1d4f18;
            case 0x1D4F1Cu: goto label_1d4f1c;
            case 0x1D4F20u: goto label_1d4f20;
            case 0x1D4F24u: goto label_1d4f24;
            case 0x1D4F28u: goto label_1d4f28;
            case 0x1D4F2Cu: goto label_1d4f2c;
            case 0x1D4F30u: goto label_1d4f30;
            case 0x1D4F34u: goto label_1d4f34;
            case 0x1D4F38u: goto label_1d4f38;
            case 0x1D4F3Cu: goto label_1d4f3c;
            case 0x1D4F40u: goto label_1d4f40;
            case 0x1D4F44u: goto label_1d4f44;
            case 0x1D4F48u: goto label_1d4f48;
            case 0x1D4F4Cu: goto label_1d4f4c;
            case 0x1D4F50u: goto label_1d4f50;
            case 0x1D4F54u: goto label_1d4f54;
            case 0x1D4F58u: goto label_1d4f58;
            case 0x1D4F5Cu: goto label_1d4f5c;
            case 0x1D4F60u: goto label_1d4f60;
            case 0x1D4F64u: goto label_1d4f64;
            case 0x1D4F68u: goto label_1d4f68;
            case 0x1D4F6Cu: goto label_1d4f6c;
            case 0x1D4F70u: goto label_1d4f70;
            case 0x1D4F74u: goto label_1d4f74;
            case 0x1D4F78u: goto label_1d4f78;
            case 0x1D4F7Cu: goto label_1d4f7c;
            case 0x1D4F80u: goto label_1d4f80;
            case 0x1D4F84u: goto label_1d4f84;
            case 0x1D4F88u: goto label_1d4f88;
            case 0x1D4F8Cu: goto label_1d4f8c;
            case 0x1D4F90u: goto label_1d4f90;
            case 0x1D4F94u: goto label_1d4f94;
            case 0x1D4F98u: goto label_1d4f98;
            case 0x1D4F9Cu: goto label_1d4f9c;
            case 0x1D4FA0u: goto label_1d4fa0;
            case 0x1D4FA4u: goto label_1d4fa4;
            case 0x1D4FA8u: goto label_1d4fa8;
            case 0x1D4FACu: goto label_1d4fac;
            case 0x1D4FB0u: goto label_1d4fb0;
            case 0x1D4FB4u: goto label_1d4fb4;
            case 0x1D4FB8u: goto label_1d4fb8;
            case 0x1D4FBCu: goto label_1d4fbc;
            case 0x1D4FC0u: goto label_1d4fc0;
            case 0x1D4FC4u: goto label_1d4fc4;
            case 0x1D4FC8u: goto label_1d4fc8;
            case 0x1D4FCCu: goto label_1d4fcc;
            case 0x1D4FD0u: goto label_1d4fd0;
            case 0x1D4FD4u: goto label_1d4fd4;
            case 0x1D4FD8u: goto label_1d4fd8;
            case 0x1D4FDCu: goto label_1d4fdc;
            case 0x1D4FE0u: goto label_1d4fe0;
            case 0x1D4FE4u: goto label_1d4fe4;
            case 0x1D4FE8u: goto label_1d4fe8;
            case 0x1D4FECu: goto label_1d4fec;
            case 0x1D4FF0u: goto label_1d4ff0;
            case 0x1D4FF4u: goto label_1d4ff4;
            case 0x1D4FF8u: goto label_1d4ff8;
            case 0x1D4FFCu: goto label_1d4ffc;
            case 0x1D5000u: goto label_1d5000;
            case 0x1D5004u: goto label_1d5004;
            case 0x1D5008u: goto label_1d5008;
            case 0x1D500Cu: goto label_1d500c;
            case 0x1D5010u: goto label_1d5010;
            case 0x1D5014u: goto label_1d5014;
            case 0x1D5018u: goto label_1d5018;
            case 0x1D501Cu: goto label_1d501c;
            case 0x1D5020u: goto label_1d5020;
            case 0x1D5024u: goto label_1d5024;
            case 0x1D5028u: goto label_1d5028;
            case 0x1D502Cu: goto label_1d502c;
            case 0x1D5030u: goto label_1d5030;
            case 0x1D5034u: goto label_1d5034;
            case 0x1D5038u: goto label_1d5038;
            case 0x1D503Cu: goto label_1d503c;
            case 0x1D5040u: goto label_1d5040;
            case 0x1D5044u: goto label_1d5044;
            case 0x1D5048u: goto label_1d5048;
            case 0x1D504Cu: goto label_1d504c;
            case 0x1D5050u: goto label_1d5050;
            case 0x1D5054u: goto label_1d5054;
            case 0x1D5058u: goto label_1d5058;
            case 0x1D505Cu: goto label_1d505c;
            case 0x1D5060u: goto label_1d5060;
            case 0x1D5064u: goto label_1d5064;
            case 0x1D5068u: goto label_1d5068;
            case 0x1D506Cu: goto label_1d506c;
            case 0x1D5070u: goto label_1d5070;
            case 0x1D5074u: goto label_1d5074;
            case 0x1D5078u: goto label_1d5078;
            case 0x1D507Cu: goto label_1d507c;
            case 0x1D5080u: goto label_1d5080;
            case 0x1D5084u: goto label_1d5084;
            case 0x1D5088u: goto label_1d5088;
            case 0x1D508Cu: goto label_1d508c;
            case 0x1D5090u: goto label_1d5090;
            case 0x1D5094u: goto label_1d5094;
            case 0x1D5098u: goto label_1d5098;
            case 0x1D509Cu: goto label_1d509c;
            case 0x1D50A0u: goto label_1d50a0;
            case 0x1D50A4u: goto label_1d50a4;
            case 0x1D50A8u: goto label_1d50a8;
            case 0x1D50ACu: goto label_1d50ac;
            case 0x1D50B0u: goto label_1d50b0;
            case 0x1D50B4u: goto label_1d50b4;
            case 0x1D50B8u: goto label_1d50b8;
            case 0x1D50BCu: goto label_1d50bc;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1D50B8u;
label_1d50b8:
    // 0x1d50b8: 0x0  nop
    ctx->pc = 0x1d50b8u;
    // NOP
label_1d50bc:
    // 0x1d50bc: 0x0  nop
    ctx->pc = 0x1d50bcu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
