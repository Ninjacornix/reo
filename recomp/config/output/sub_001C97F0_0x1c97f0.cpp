#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C97F0
// Address: 0x1c97f0 - 0x1cb180
void sub_001C97F0_0x1c97f0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C97F0_0x1c97f0");
#endif

    switch (ctx->pc) {
        case 0x1c98e8u: goto label_1c98e8;
        case 0x1c9924u: goto label_1c9924;
        case 0x1c999cu: goto label_1c999c;
        case 0x1c9b28u: goto label_1c9b28;
        case 0x1c9c78u: goto label_1c9c78;
        case 0x1c9cccu: goto label_1c9ccc;
        case 0x1c9d20u: goto label_1c9d20;
        case 0x1c9d68u: goto label_1c9d68;
        case 0x1c9dacu: goto label_1c9dac;
        case 0x1c9e08u: goto label_1c9e08;
        case 0x1c9e50u: goto label_1c9e50;
        case 0x1c9f6cu: goto label_1c9f6c;
        case 0x1ca0f4u: goto label_1ca0f4;
        case 0x1ca1d8u: goto label_1ca1d8;
        case 0x1ca308u: goto label_1ca308;
        case 0x1ca310u: goto label_1ca310;
        case 0x1ca318u: goto label_1ca318;
        case 0x1ca384u: goto label_1ca384;
        case 0x1ca43cu: goto label_1ca43c;
        case 0x1ca5d8u: goto label_1ca5d8;
        case 0x1ca630u: goto label_1ca630;
        case 0x1ca6ecu: goto label_1ca6ec;
        case 0x1ca740u: goto label_1ca740;
        case 0x1ca820u: goto label_1ca820;
        case 0x1ca9a4u: goto label_1ca9a4;
        case 0x1ca9b4u: goto label_1ca9b4;
        case 0x1caa24u: goto label_1caa24;
        case 0x1cab04u: goto label_1cab04;
        case 0x1cabb8u: goto label_1cabb8;
        case 0x1cabf8u: goto label_1cabf8;
        case 0x1cac60u: goto label_1cac60;
        case 0x1cace0u: goto label_1cace0;
        case 0x1cad00u: goto label_1cad00;
        case 0x1cad34u: goto label_1cad34;
        case 0x1cad90u: goto label_1cad90;
        case 0x1cadbcu: goto label_1cadbc;
        case 0x1cae78u: goto label_1cae78;
        case 0x1cae84u: goto label_1cae84;
        case 0x1caed8u: goto label_1caed8;
        case 0x1caf24u: goto label_1caf24;
        case 0x1caf38u: goto label_1caf38;
        case 0x1cb00cu: goto label_1cb00c;
        case 0x1cb124u: goto label_1cb124;
        default: break;
    }

    ctx->pc = 0x1c97f0u;

label_1c97f0:
    // 0x1c97f0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c97f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c97f4: 0x8424d9e0  lh          $a0, -0x2620($at)
    ctx->pc = 0x1c97f4u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294957536)));
    // 0x1c97f8: 0x10800012  beqz        $a0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1C97F8u;
    {
        const bool branch_taken_0x1c97f8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C97FCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C97F8u;
            // 0x1c97fc: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c97f8) {
            ctx->pc = 0x1C9844u;
            goto label_1c9844;
        }
    }
    ctx->pc = 0x1C9800u;
    // 0x1c9800: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1c9800u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c9804: 0x1082000d  beq         $a0, $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1C9804u;
    {
        const bool branch_taken_0x1c9804 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C9808u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9804u;
            // 0x1c9808: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9804) {
            ctx->pc = 0x1C983Cu;
            goto label_1c983c;
        }
    }
    ctx->pc = 0x1C980Cu;
    // 0x1c980c: 0x24030003  addiu       $v1, $zero, 0x3
    ctx->pc = 0x1c980cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1c9810: 0x10830008  beq         $a0, $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C9810u;
    {
        const bool branch_taken_0x1c9810 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C9814u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9810u;
            // 0x1c9814: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9810) {
            ctx->pc = 0x1C9834u;
            goto label_1c9834;
        }
    }
    ctx->pc = 0x1C9818u;
    // 0x1c9818: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c9818u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c981c: 0x10820003  beq         $a0, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C981Cu;
    {
        const bool branch_taken_0x1c981c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C9820u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C981Cu;
            // 0x1c9820: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c981c) {
            ctx->pc = 0x1C982Cu;
            goto label_1c982c;
        }
    }
    ctx->pc = 0x1C9824u;
    // 0x1c9824: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1C9824u;
    {
        const bool branch_taken_0x1c9824 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c9824) {
            ctx->pc = 0x1C984Cu;
            goto label_1c984c;
        }
    }
    ctx->pc = 0x1C982Cu;
label_1c982c:
    // 0x1c982c: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C982Cu;
    {
        const bool branch_taken_0x1c982c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9830u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C982Cu;
            // 0x1c9830: 0xa423d9e0  sh          $v1, -0x2620($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 4294957536), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c982c) {
            ctx->pc = 0x1C984Cu;
            goto label_1c984c;
        }
    }
    ctx->pc = 0x1C9834u;
label_1c9834:
    // 0x1c9834: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1C9834u;
    {
        const bool branch_taken_0x1c9834 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9838u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9834u;
            // 0x1c9838: 0xa422d9e0  sh          $v0, -0x2620($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 4294957536), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9834) {
            ctx->pc = 0x1C984Cu;
            goto label_1c984c;
        }
    }
    ctx->pc = 0x1C983Cu;
label_1c983c:
    // 0x1c983c: 0x10000003  b           . + 4 + (0x3 << 2)
    ctx->pc = 0x1C983Cu;
    {
        const bool branch_taken_0x1c983c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9840u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C983Cu;
            // 0x1c9840: 0xa420d9e0  sh          $zero, -0x2620($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 4294957536), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c983c) {
            ctx->pc = 0x1C984Cu;
            goto label_1c984c;
        }
    }
    ctx->pc = 0x1C9844u;
label_1c9844:
    // 0x1c9844: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9844u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9848: 0xa422d9e0  sh          $v0, -0x2620($at)
    ctx->pc = 0x1c9848u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294957536), (uint16_t)GPR_U32(ctx, 2));
label_1c984c:
    // 0x1c984c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c984cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9850: 0x9023c818  lbu         $v1, -0x37E8($at)
    ctx->pc = 0x1c9850u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952984)));
    // 0x1c9854: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9854u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9858: 0x8422d9e0  lh          $v0, -0x2620($at)
    ctx->pc = 0x1c9858u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294957536)));
    // 0x1c985c: 0x621026  xor         $v0, $v1, $v0
    ctx->pc = 0x1c985cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 3) ^ GPR_U64(ctx, 2));
    // 0x1c9860: 0x2c420001  sltiu       $v0, $v0, 0x1
    ctx->pc = 0x1c9860u;
    SET_GPR_U64(ctx, 2, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x1c9864: 0x3e00008  jr          $ra
    ctx->pc = 0x1C9864u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C9868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9864u;
            // 0x1c9868: 0x21023  negu        $v0, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)SUB32(GPR_U32(ctx, 0), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C97F0u: goto label_1c97f0;
            case 0x1C982Cu: goto label_1c982c;
            case 0x1C9834u: goto label_1c9834;
            case 0x1C983Cu: goto label_1c983c;
            case 0x1C9844u: goto label_1c9844;
            case 0x1C984Cu: goto label_1c984c;
            case 0x1C98E8u: goto label_1c98e8;
            case 0x1C9924u: goto label_1c9924;
            case 0x1C999Cu: goto label_1c999c;
            case 0x1C99D4u: goto label_1c99d4;
            case 0x1C99F0u: goto label_1c99f0;
            case 0x1C9A74u: goto label_1c9a74;
            case 0x1C9A88u: goto label_1c9a88;
            case 0x1C9AECu: goto label_1c9aec;
            case 0x1C9AF4u: goto label_1c9af4;
            case 0x1C9B00u: goto label_1c9b00;
            case 0x1C9B04u: goto label_1c9b04;
            case 0x1C9B08u: goto label_1c9b08;
            case 0x1C9B10u: goto label_1c9b10;
            case 0x1C9B28u: goto label_1c9b28;
            case 0x1C9C4Cu: goto label_1c9c4c;
            case 0x1C9C64u: goto label_1c9c64;
            case 0x1C9C78u: goto label_1c9c78;
            case 0x1C9C90u: goto label_1c9c90;
            case 0x1C9CACu: goto label_1c9cac;
            case 0x1C9CCCu: goto label_1c9ccc;
            case 0x1C9D04u: goto label_1c9d04;
            case 0x1C9D18u: goto label_1c9d18;
            case 0x1C9D20u: goto label_1c9d20;
            case 0x1C9D58u: goto label_1c9d58;
            case 0x1C9D68u: goto label_1c9d68;
            case 0x1C9D80u: goto label_1c9d80;
            case 0x1C9DA4u: goto label_1c9da4;
            case 0x1C9DACu: goto label_1c9dac;
            case 0x1C9DFCu: goto label_1c9dfc;
            case 0x1C9E08u: goto label_1c9e08;
            case 0x1C9E40u: goto label_1c9e40;
            case 0x1C9E50u: goto label_1c9e50;
            case 0x1C9E6Cu: goto label_1c9e6c;
            case 0x1C9EACu: goto label_1c9eac;
            case 0x1C9EC0u: goto label_1c9ec0;
            case 0x1C9EFCu: goto label_1c9efc;
            case 0x1C9F38u: goto label_1c9f38;
            case 0x1C9F40u: goto label_1c9f40;
            case 0x1C9F5Cu: goto label_1c9f5c;
            case 0x1C9F6Cu: goto label_1c9f6c;
            case 0x1C9FA4u: goto label_1c9fa4;
            case 0x1C9FD0u: goto label_1c9fd0;
            case 0x1CA000u: goto label_1ca000;
            case 0x1CA02Cu: goto label_1ca02c;
            case 0x1CA058u: goto label_1ca058;
            case 0x1CA080u: goto label_1ca080;
            case 0x1CA090u: goto label_1ca090;
            case 0x1CA0ECu: goto label_1ca0ec;
            case 0x1CA0F4u: goto label_1ca0f4;
            case 0x1CA108u: goto label_1ca108;
            case 0x1CA130u: goto label_1ca130;
            case 0x1CA178u: goto label_1ca178;
            case 0x1CA180u: goto label_1ca180;
            case 0x1CA1C8u: goto label_1ca1c8;
            case 0x1CA1D0u: goto label_1ca1d0;
            case 0x1CA1D8u: goto label_1ca1d8;
            case 0x1CA1ECu: goto label_1ca1ec;
            case 0x1CA214u: goto label_1ca214;
            case 0x1CA23Cu: goto label_1ca23c;
            case 0x1CA264u: goto label_1ca264;
            case 0x1CA28Cu: goto label_1ca28c;
            case 0x1CA2ACu: goto label_1ca2ac;
            case 0x1CA2B8u: goto label_1ca2b8;
            case 0x1CA2DCu: goto label_1ca2dc;
            case 0x1CA2E0u: goto label_1ca2e0;
            case 0x1CA2ECu: goto label_1ca2ec;
            case 0x1CA308u: goto label_1ca308;
            case 0x1CA310u: goto label_1ca310;
            case 0x1CA318u: goto label_1ca318;
            case 0x1CA330u: goto label_1ca330;
            case 0x1CA35Cu: goto label_1ca35c;
            case 0x1CA364u: goto label_1ca364;
            case 0x1CA378u: goto label_1ca378;
            case 0x1CA384u: goto label_1ca384;
            case 0x1CA3BCu: goto label_1ca3bc;
            case 0x1CA3C0u: goto label_1ca3c0;
            case 0x1CA3C4u: goto label_1ca3c4;
            case 0x1CA43Cu: goto label_1ca43c;
            case 0x1CA474u: goto label_1ca474;
            case 0x1CA490u: goto label_1ca490;
            case 0x1CA558u: goto label_1ca558;
            case 0x1CA57Cu: goto label_1ca57c;
            case 0x1CA598u: goto label_1ca598;
            case 0x1CA5C0u: goto label_1ca5c0;
            case 0x1CA5D8u: goto label_1ca5d8;
            case 0x1CA610u: goto label_1ca610;
            case 0x1CA624u: goto label_1ca624;
            case 0x1CA630u: goto label_1ca630;
            case 0x1CA668u: goto label_1ca668;
            case 0x1CA688u: goto label_1ca688;
            case 0x1CA690u: goto label_1ca690;
            case 0x1CA694u: goto label_1ca694;
            case 0x1CA698u: goto label_1ca698;
            case 0x1CA6A0u: goto label_1ca6a0;
            case 0x1CA6C0u: goto label_1ca6c0;
            case 0x1CA6ECu: goto label_1ca6ec;
            case 0x1CA724u: goto label_1ca724;
            case 0x1CA738u: goto label_1ca738;
            case 0x1CA740u: goto label_1ca740;
            case 0x1CA778u: goto label_1ca778;
            case 0x1CA790u: goto label_1ca790;
            case 0x1CA7D0u: goto label_1ca7d0;
            case 0x1CA808u: goto label_1ca808;
            case 0x1CA810u: goto label_1ca810;
            case 0x1CA820u: goto label_1ca820;
            case 0x1CA84Cu: goto label_1ca84c;
            case 0x1CA86Cu: goto label_1ca86c;
            case 0x1CA8B8u: goto label_1ca8b8;
            case 0x1CA8C8u: goto label_1ca8c8;
            case 0x1CA8CCu: goto label_1ca8cc;
            case 0x1CA8D4u: goto label_1ca8d4;
            case 0x1CA914u: goto label_1ca914;
            case 0x1CA94Cu: goto label_1ca94c;
            case 0x1CA954u: goto label_1ca954;
            case 0x1CA970u: goto label_1ca970;
            case 0x1CA99Cu: goto label_1ca99c;
            case 0x1CA9A4u: goto label_1ca9a4;
            case 0x1CA9B4u: goto label_1ca9b4;
            case 0x1CA9ECu: goto label_1ca9ec;
            case 0x1CA9F8u: goto label_1ca9f8;
            case 0x1CAA18u: goto label_1caa18;
            case 0x1CAA24u: goto label_1caa24;
            case 0x1CAA5Cu: goto label_1caa5c;
            case 0x1CAA74u: goto label_1caa74;
            case 0x1CAAB4u: goto label_1caab4;
            case 0x1CAAECu: goto label_1caaec;
            case 0x1CAAF4u: goto label_1caaf4;
            case 0x1CAB04u: goto label_1cab04;
            case 0x1CAB30u: goto label_1cab30;
            case 0x1CAB48u: goto label_1cab48;
            case 0x1CAB94u: goto label_1cab94;
            case 0x1CABA4u: goto label_1caba4;
            case 0x1CABA8u: goto label_1caba8;
            case 0x1CABB0u: goto label_1cabb0;
            case 0x1CABB8u: goto label_1cabb8;
            case 0x1CABF0u: goto label_1cabf0;
            case 0x1CABF8u: goto label_1cabf8;
            case 0x1CAC30u: goto label_1cac30;
            case 0x1CAC48u: goto label_1cac48;
            case 0x1CAC60u: goto label_1cac60;
            case 0x1CAC90u: goto label_1cac90;
            case 0x1CACC8u: goto label_1cacc8;
            case 0x1CACD0u: goto label_1cacd0;
            case 0x1CACE0u: goto label_1cace0;
            case 0x1CAD00u: goto label_1cad00;
            case 0x1CAD2Cu: goto label_1cad2c;
            case 0x1CAD34u: goto label_1cad34;
            case 0x1CAD48u: goto label_1cad48;
            case 0x1CAD50u: goto label_1cad50;
            case 0x1CAD60u: goto label_1cad60;
            case 0x1CAD88u: goto label_1cad88;
            case 0x1CAD90u: goto label_1cad90;
            case 0x1CADBCu: goto label_1cadbc;
            case 0x1CADD4u: goto label_1cadd4;
            case 0x1CADDCu: goto label_1caddc;
            case 0x1CAE14u: goto label_1cae14;
            case 0x1CAE1Cu: goto label_1cae1c;
            case 0x1CAE44u: goto label_1cae44;
            case 0x1CAE70u: goto label_1cae70;
            case 0x1CAE78u: goto label_1cae78;
            case 0x1CAE84u: goto label_1cae84;
            case 0x1CAEBCu: goto label_1caebc;
            case 0x1CAED8u: goto label_1caed8;
            case 0x1CAF10u: goto label_1caf10;
            case 0x1CAF1Cu: goto label_1caf1c;
            case 0x1CAF24u: goto label_1caf24;
            case 0x1CAF38u: goto label_1caf38;
            case 0x1CAF4Cu: goto label_1caf4c;
            case 0x1CAF7Cu: goto label_1caf7c;
            case 0x1CAFB4u: goto label_1cafb4;
            case 0x1CAFE0u: goto label_1cafe0;
            case 0x1CAFE8u: goto label_1cafe8;
            case 0x1CB000u: goto label_1cb000;
            case 0x1CB00Cu: goto label_1cb00c;
            case 0x1CB044u: goto label_1cb044;
            case 0x1CB048u: goto label_1cb048;
            case 0x1CB04Cu: goto label_1cb04c;
            case 0x1CB0DCu: goto label_1cb0dc;
            case 0x1CB104u: goto label_1cb104;
            case 0x1CB11Cu: goto label_1cb11c;
            case 0x1CB124u: goto label_1cb124;
            case 0x1CB150u: goto label_1cb150;
            case 0x1CB154u: goto label_1cb154;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C986Cu;
    // 0x1c986c: 0x0  nop
    ctx->pc = 0x1c986cu;
    // NOP
    // 0x1c9870: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1c9870u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1c9874: 0xffbf0090  sd          $ra, 0x90($sp)
    ctx->pc = 0x1c9874u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 144), GPR_U64(ctx, 31));
    // 0x1c9878: 0x7fb70080  sq          $s7, 0x80($sp)
    ctx->pc = 0x1c9878u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 128), GPR_VEC(ctx, 23));
    // 0x1c987c: 0x7fb60070  sq          $s6, 0x70($sp)
    ctx->pc = 0x1c987cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 22));
    // 0x1c9880: 0x160b82d  daddu       $s7, $t3, $zero
    ctx->pc = 0x1c9880u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9884: 0x7fb50060  sq          $s5, 0x60($sp)
    ctx->pc = 0x1c9884u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 21));
    // 0x1c9888: 0x140b02d  daddu       $s6, $t2, $zero
    ctx->pc = 0x1c9888u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c988c: 0x7fb40050  sq          $s4, 0x50($sp)
    ctx->pc = 0x1c988cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 20));
    // 0x1c9890: 0x80a82d  daddu       $s5, $a0, $zero
    ctx->pc = 0x1c9890u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9894: 0x7fb30040  sq          $s3, 0x40($sp)
    ctx->pc = 0x1c9894u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 19));
    // 0x1c9898: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x1c9898u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c989c: 0x7fb20030  sq          $s2, 0x30($sp)
    ctx->pc = 0x1c989cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 18));
    // 0x1c98a0: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x1c98a0u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c98a4: 0x7fb10020  sq          $s1, 0x20($sp)
    ctx->pc = 0x1c98a4u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 17));
    // 0x1c98a8: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x1c98a8u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c98ac: 0x7fb00010  sq          $s0, 0x10($sp)
    ctx->pc = 0x1c98acu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 16));
    // 0x1c98b0: 0x100882d  daddu       $s1, $t0, $zero
    ctx->pc = 0x1c98b0u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c98b4: 0x81620000  lb          $v0, 0x0($t3)
    ctx->pc = 0x1c98b4u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 11), 0)));
    // 0x1c98b8: 0x120802d  daddu       $s0, $t1, $zero
    ctx->pc = 0x1c98b8u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c98bc: 0xffa20000  sd          $v0, 0x0($sp)
    ctx->pc = 0x1c98bcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 2));
    // 0x1c98c0: 0x84e80000  lh          $t0, 0x0($a3)
    ctx->pc = 0x1c98c0u;
    SET_GPR_S32(ctx, 8, (int16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x1c98c4: 0x80890000  lb          $t1, 0x0($a0)
    ctx->pc = 0x1c98c4u;
    SET_GPR_S32(ctx, 9, (int8_t)READ8(ADD32(GPR_U32(ctx, 4), 0)));
    // 0x1c98c8: 0x80aa0000  lb          $t2, 0x0($a1)
    ctx->pc = 0x1c98c8u;
    SET_GPR_S32(ctx, 10, (int8_t)READ8(ADD32(GPR_U32(ctx, 5), 0)));
    // 0x1c98cc: 0x80cb0000  lb          $t3, 0x0($a2)
    ctx->pc = 0x1c98ccu;
    SET_GPR_S32(ctx, 11, (int8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x1c98d0: 0x3c070025  lui         $a3, 0x25
    ctx->pc = 0x1c98d0u;
    SET_GPR_S32(ctx, 7, (int32_t)((uint32_t)37 << 16));
    // 0x1c98d4: 0x24040001  addiu       $a0, $zero, 0x1
    ctx->pc = 0x1c98d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c98d8: 0x24e72e00  addiu       $a3, $a3, 0x2E00
    ctx->pc = 0x1c98d8u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 11776));
    // 0x1c98dc: 0x2405001b  addiu       $a1, $zero, 0x1B
    ctx->pc = 0x1c98dcu;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 27));
    // 0x1c98e0: 0xc072420  jal         func_1C9080
    ctx->pc = 0x1C98E0u;
    SET_GPR_U32(ctx, 31, 0x1C98E8u);
    ctx->pc = 0x1C98E4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C98E0u;
            // 0x1c98e4: 0x80302d  daddu       $a2, $a0, $zero (Delay Slot)
        SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C9080u;
    if (runtime->hasFunction(0x1C9080u)) {
        auto targetFn = runtime->lookupFunction(0x1C9080u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C98E8u; }
        if (ctx->pc != 0x1C98E8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C9080_0x1c9080(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C98E8u; }
        if (ctx->pc != 0x1C98E8u) { return; }
    }
    ctx->pc = 0x1C98E8u;
label_1c98e8:
    // 0x1c98e8: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1c98e8u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1c98ec: 0x3c020023  lui         $v0, 0x23
    ctx->pc = 0x1c98ecu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)35 << 16));
    // 0x1c98f0: 0x24425fd8  addiu       $v0, $v0, 0x5FD8
    ctx->pc = 0x1c98f0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 24536));
    // 0x1c98f4: 0x280282d  daddu       $a1, $s4, $zero
    ctx->pc = 0x1c98f4u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c98f8: 0x260302d  daddu       $a2, $s3, $zero
    ctx->pc = 0x1c98f8u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c98fc: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x1c98fcu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9900: 0x220402d  daddu       $t0, $s1, $zero
    ctx->pc = 0x1c9900u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9904: 0x200482d  daddu       $t1, $s0, $zero
    ctx->pc = 0x1c9904u;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 16) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9908: 0x2c0502d  daddu       $t2, $s6, $zero
    ctx->pc = 0x1c9908u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 22) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c990c: 0x2e0582d  daddu       $t3, $s7, $zero
    ctx->pc = 0x1c990cu;
    SET_GPR_U64(ctx, 11, (uint64_t)GPR_U64(ctx, 23) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9910: 0x31880  sll         $v1, $v1, 2
    ctx->pc = 0x1c9910u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 2));
    // 0x1c9914: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c9914u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c9918: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1c9918u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c991c: 0x40f809  jalr        $v0
    ctx->pc = 0x1C991Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1C9924u);
        ctx->pc = 0x1C9920u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C991Cu;
            // 0x1c9920: 0x2a0202d  daddu       $a0, $s5, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 21) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1C9924u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C97F0u: goto label_1c97f0;
            case 0x1C982Cu: goto label_1c982c;
            case 0x1C9834u: goto label_1c9834;
            case 0x1C983Cu: goto label_1c983c;
            case 0x1C9844u: goto label_1c9844;
            case 0x1C984Cu: goto label_1c984c;
            case 0x1C98E8u: goto label_1c98e8;
            case 0x1C9924u: goto label_1c9924;
            case 0x1C999Cu: goto label_1c999c;
            case 0x1C99D4u: goto label_1c99d4;
            case 0x1C99F0u: goto label_1c99f0;
            case 0x1C9A74u: goto label_1c9a74;
            case 0x1C9A88u: goto label_1c9a88;
            case 0x1C9AECu: goto label_1c9aec;
            case 0x1C9AF4u: goto label_1c9af4;
            case 0x1C9B00u: goto label_1c9b00;
            case 0x1C9B04u: goto label_1c9b04;
            case 0x1C9B08u: goto label_1c9b08;
            case 0x1C9B10u: goto label_1c9b10;
            case 0x1C9B28u: goto label_1c9b28;
            case 0x1C9C4Cu: goto label_1c9c4c;
            case 0x1C9C64u: goto label_1c9c64;
            case 0x1C9C78u: goto label_1c9c78;
            case 0x1C9C90u: goto label_1c9c90;
            case 0x1C9CACu: goto label_1c9cac;
            case 0x1C9CCCu: goto label_1c9ccc;
            case 0x1C9D04u: goto label_1c9d04;
            case 0x1C9D18u: goto label_1c9d18;
            case 0x1C9D20u: goto label_1c9d20;
            case 0x1C9D58u: goto label_1c9d58;
            case 0x1C9D68u: goto label_1c9d68;
            case 0x1C9D80u: goto label_1c9d80;
            case 0x1C9DA4u: goto label_1c9da4;
            case 0x1C9DACu: goto label_1c9dac;
            case 0x1C9DFCu: goto label_1c9dfc;
            case 0x1C9E08u: goto label_1c9e08;
            case 0x1C9E40u: goto label_1c9e40;
            case 0x1C9E50u: goto label_1c9e50;
            case 0x1C9E6Cu: goto label_1c9e6c;
            case 0x1C9EACu: goto label_1c9eac;
            case 0x1C9EC0u: goto label_1c9ec0;
            case 0x1C9EFCu: goto label_1c9efc;
            case 0x1C9F38u: goto label_1c9f38;
            case 0x1C9F40u: goto label_1c9f40;
            case 0x1C9F5Cu: goto label_1c9f5c;
            case 0x1C9F6Cu: goto label_1c9f6c;
            case 0x1C9FA4u: goto label_1c9fa4;
            case 0x1C9FD0u: goto label_1c9fd0;
            case 0x1CA000u: goto label_1ca000;
            case 0x1CA02Cu: goto label_1ca02c;
            case 0x1CA058u: goto label_1ca058;
            case 0x1CA080u: goto label_1ca080;
            case 0x1CA090u: goto label_1ca090;
            case 0x1CA0ECu: goto label_1ca0ec;
            case 0x1CA0F4u: goto label_1ca0f4;
            case 0x1CA108u: goto label_1ca108;
            case 0x1CA130u: goto label_1ca130;
            case 0x1CA178u: goto label_1ca178;
            case 0x1CA180u: goto label_1ca180;
            case 0x1CA1C8u: goto label_1ca1c8;
            case 0x1CA1D0u: goto label_1ca1d0;
            case 0x1CA1D8u: goto label_1ca1d8;
            case 0x1CA1ECu: goto label_1ca1ec;
            case 0x1CA214u: goto label_1ca214;
            case 0x1CA23Cu: goto label_1ca23c;
            case 0x1CA264u: goto label_1ca264;
            case 0x1CA28Cu: goto label_1ca28c;
            case 0x1CA2ACu: goto label_1ca2ac;
            case 0x1CA2B8u: goto label_1ca2b8;
            case 0x1CA2DCu: goto label_1ca2dc;
            case 0x1CA2E0u: goto label_1ca2e0;
            case 0x1CA2ECu: goto label_1ca2ec;
            case 0x1CA308u: goto label_1ca308;
            case 0x1CA310u: goto label_1ca310;
            case 0x1CA318u: goto label_1ca318;
            case 0x1CA330u: goto label_1ca330;
            case 0x1CA35Cu: goto label_1ca35c;
            case 0x1CA364u: goto label_1ca364;
            case 0x1CA378u: goto label_1ca378;
            case 0x1CA384u: goto label_1ca384;
            case 0x1CA3BCu: goto label_1ca3bc;
            case 0x1CA3C0u: goto label_1ca3c0;
            case 0x1CA3C4u: goto label_1ca3c4;
            case 0x1CA43Cu: goto label_1ca43c;
            case 0x1CA474u: goto label_1ca474;
            case 0x1CA490u: goto label_1ca490;
            case 0x1CA558u: goto label_1ca558;
            case 0x1CA57Cu: goto label_1ca57c;
            case 0x1CA598u: goto label_1ca598;
            case 0x1CA5C0u: goto label_1ca5c0;
            case 0x1CA5D8u: goto label_1ca5d8;
            case 0x1CA610u: goto label_1ca610;
            case 0x1CA624u: goto label_1ca624;
            case 0x1CA630u: goto label_1ca630;
            case 0x1CA668u: goto label_1ca668;
            case 0x1CA688u: goto label_1ca688;
            case 0x1CA690u: goto label_1ca690;
            case 0x1CA694u: goto label_1ca694;
            case 0x1CA698u: goto label_1ca698;
            case 0x1CA6A0u: goto label_1ca6a0;
            case 0x1CA6C0u: goto label_1ca6c0;
            case 0x1CA6ECu: goto label_1ca6ec;
            case 0x1CA724u: goto label_1ca724;
            case 0x1CA738u: goto label_1ca738;
            case 0x1CA740u: goto label_1ca740;
            case 0x1CA778u: goto label_1ca778;
            case 0x1CA790u: goto label_1ca790;
            case 0x1CA7D0u: goto label_1ca7d0;
            case 0x1CA808u: goto label_1ca808;
            case 0x1CA810u: goto label_1ca810;
            case 0x1CA820u: goto label_1ca820;
            case 0x1CA84Cu: goto label_1ca84c;
            case 0x1CA86Cu: goto label_1ca86c;
            case 0x1CA8B8u: goto label_1ca8b8;
            case 0x1CA8C8u: goto label_1ca8c8;
            case 0x1CA8CCu: goto label_1ca8cc;
            case 0x1CA8D4u: goto label_1ca8d4;
            case 0x1CA914u: goto label_1ca914;
            case 0x1CA94Cu: goto label_1ca94c;
            case 0x1CA954u: goto label_1ca954;
            case 0x1CA970u: goto label_1ca970;
            case 0x1CA99Cu: goto label_1ca99c;
            case 0x1CA9A4u: goto label_1ca9a4;
            case 0x1CA9B4u: goto label_1ca9b4;
            case 0x1CA9ECu: goto label_1ca9ec;
            case 0x1CA9F8u: goto label_1ca9f8;
            case 0x1CAA18u: goto label_1caa18;
            case 0x1CAA24u: goto label_1caa24;
            case 0x1CAA5Cu: goto label_1caa5c;
            case 0x1CAA74u: goto label_1caa74;
            case 0x1CAAB4u: goto label_1caab4;
            case 0x1CAAECu: goto label_1caaec;
            case 0x1CAAF4u: goto label_1caaf4;
            case 0x1CAB04u: goto label_1cab04;
            case 0x1CAB30u: goto label_1cab30;
            case 0x1CAB48u: goto label_1cab48;
            case 0x1CAB94u: goto label_1cab94;
            case 0x1CABA4u: goto label_1caba4;
            case 0x1CABA8u: goto label_1caba8;
            case 0x1CABB0u: goto label_1cabb0;
            case 0x1CABB8u: goto label_1cabb8;
            case 0x1CABF0u: goto label_1cabf0;
            case 0x1CABF8u: goto label_1cabf8;
            case 0x1CAC30u: goto label_1cac30;
            case 0x1CAC48u: goto label_1cac48;
            case 0x1CAC60u: goto label_1cac60;
            case 0x1CAC90u: goto label_1cac90;
            case 0x1CACC8u: goto label_1cacc8;
            case 0x1CACD0u: goto label_1cacd0;
            case 0x1CACE0u: goto label_1cace0;
            case 0x1CAD00u: goto label_1cad00;
            case 0x1CAD2Cu: goto label_1cad2c;
            case 0x1CAD34u: goto label_1cad34;
            case 0x1CAD48u: goto label_1cad48;
            case 0x1CAD50u: goto label_1cad50;
            case 0x1CAD60u: goto label_1cad60;
            case 0x1CAD88u: goto label_1cad88;
            case 0x1CAD90u: goto label_1cad90;
            case 0x1CADBCu: goto label_1cadbc;
            case 0x1CADD4u: goto label_1cadd4;
            case 0x1CADDCu: goto label_1caddc;
            case 0x1CAE14u: goto label_1cae14;
            case 0x1CAE1Cu: goto label_1cae1c;
            case 0x1CAE44u: goto label_1cae44;
            case 0x1CAE70u: goto label_1cae70;
            case 0x1CAE78u: goto label_1cae78;
            case 0x1CAE84u: goto label_1cae84;
            case 0x1CAEBCu: goto label_1caebc;
            case 0x1CAED8u: goto label_1caed8;
            case 0x1CAF10u: goto label_1caf10;
            case 0x1CAF1Cu: goto label_1caf1c;
            case 0x1CAF24u: goto label_1caf24;
            case 0x1CAF38u: goto label_1caf38;
            case 0x1CAF4Cu: goto label_1caf4c;
            case 0x1CAF7Cu: goto label_1caf7c;
            case 0x1CAFB4u: goto label_1cafb4;
            case 0x1CAFE0u: goto label_1cafe0;
            case 0x1CAFE8u: goto label_1cafe8;
            case 0x1CB000u: goto label_1cb000;
            case 0x1CB00Cu: goto label_1cb00c;
            case 0x1CB044u: goto label_1cb044;
            case 0x1CB048u: goto label_1cb048;
            case 0x1CB04Cu: goto label_1cb04c;
            case 0x1CB0DCu: goto label_1cb0dc;
            case 0x1CB104u: goto label_1cb104;
            case 0x1CB11Cu: goto label_1cb11c;
            case 0x1CB124u: goto label_1cb124;
            case 0x1CB150u: goto label_1cb150;
            case 0x1CB154u: goto label_1cb154;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1C9924u; }
            if (ctx->pc != 0x1C9924u) { return; }
        }
        }
    }
    ctx->pc = 0x1C9924u;
label_1c9924:
    // 0x1c9924: 0xdfbf0090  ld          $ra, 0x90($sp)
    ctx->pc = 0x1c9924u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x1c9928: 0x7bb70080  lq          $s7, 0x80($sp)
    ctx->pc = 0x1c9928u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 128)));
    // 0x1c992c: 0x7bb60070  lq          $s6, 0x70($sp)
    ctx->pc = 0x1c992cu;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1c9930: 0x7bb50060  lq          $s5, 0x60($sp)
    ctx->pc = 0x1c9930u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1c9934: 0x7bb40050  lq          $s4, 0x50($sp)
    ctx->pc = 0x1c9934u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1c9938: 0x7bb30040  lq          $s3, 0x40($sp)
    ctx->pc = 0x1c9938u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1c993c: 0x7bb20030  lq          $s2, 0x30($sp)
    ctx->pc = 0x1c993cu;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1c9940: 0x7bb10020  lq          $s1, 0x20($sp)
    ctx->pc = 0x1c9940u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1c9944: 0x7bb00010  lq          $s0, 0x10($sp)
    ctx->pc = 0x1c9944u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1c9948: 0x3e00008  jr          $ra
    ctx->pc = 0x1C9948u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1C994Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9948u;
            // 0x1c994c: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C97F0u: goto label_1c97f0;
            case 0x1C982Cu: goto label_1c982c;
            case 0x1C9834u: goto label_1c9834;
            case 0x1C983Cu: goto label_1c983c;
            case 0x1C9844u: goto label_1c9844;
            case 0x1C984Cu: goto label_1c984c;
            case 0x1C98E8u: goto label_1c98e8;
            case 0x1C9924u: goto label_1c9924;
            case 0x1C999Cu: goto label_1c999c;
            case 0x1C99D4u: goto label_1c99d4;
            case 0x1C99F0u: goto label_1c99f0;
            case 0x1C9A74u: goto label_1c9a74;
            case 0x1C9A88u: goto label_1c9a88;
            case 0x1C9AECu: goto label_1c9aec;
            case 0x1C9AF4u: goto label_1c9af4;
            case 0x1C9B00u: goto label_1c9b00;
            case 0x1C9B04u: goto label_1c9b04;
            case 0x1C9B08u: goto label_1c9b08;
            case 0x1C9B10u: goto label_1c9b10;
            case 0x1C9B28u: goto label_1c9b28;
            case 0x1C9C4Cu: goto label_1c9c4c;
            case 0x1C9C64u: goto label_1c9c64;
            case 0x1C9C78u: goto label_1c9c78;
            case 0x1C9C90u: goto label_1c9c90;
            case 0x1C9CACu: goto label_1c9cac;
            case 0x1C9CCCu: goto label_1c9ccc;
            case 0x1C9D04u: goto label_1c9d04;
            case 0x1C9D18u: goto label_1c9d18;
            case 0x1C9D20u: goto label_1c9d20;
            case 0x1C9D58u: goto label_1c9d58;
            case 0x1C9D68u: goto label_1c9d68;
            case 0x1C9D80u: goto label_1c9d80;
            case 0x1C9DA4u: goto label_1c9da4;
            case 0x1C9DACu: goto label_1c9dac;
            case 0x1C9DFCu: goto label_1c9dfc;
            case 0x1C9E08u: goto label_1c9e08;
            case 0x1C9E40u: goto label_1c9e40;
            case 0x1C9E50u: goto label_1c9e50;
            case 0x1C9E6Cu: goto label_1c9e6c;
            case 0x1C9EACu: goto label_1c9eac;
            case 0x1C9EC0u: goto label_1c9ec0;
            case 0x1C9EFCu: goto label_1c9efc;
            case 0x1C9F38u: goto label_1c9f38;
            case 0x1C9F40u: goto label_1c9f40;
            case 0x1C9F5Cu: goto label_1c9f5c;
            case 0x1C9F6Cu: goto label_1c9f6c;
            case 0x1C9FA4u: goto label_1c9fa4;
            case 0x1C9FD0u: goto label_1c9fd0;
            case 0x1CA000u: goto label_1ca000;
            case 0x1CA02Cu: goto label_1ca02c;
            case 0x1CA058u: goto label_1ca058;
            case 0x1CA080u: goto label_1ca080;
            case 0x1CA090u: goto label_1ca090;
            case 0x1CA0ECu: goto label_1ca0ec;
            case 0x1CA0F4u: goto label_1ca0f4;
            case 0x1CA108u: goto label_1ca108;
            case 0x1CA130u: goto label_1ca130;
            case 0x1CA178u: goto label_1ca178;
            case 0x1CA180u: goto label_1ca180;
            case 0x1CA1C8u: goto label_1ca1c8;
            case 0x1CA1D0u: goto label_1ca1d0;
            case 0x1CA1D8u: goto label_1ca1d8;
            case 0x1CA1ECu: goto label_1ca1ec;
            case 0x1CA214u: goto label_1ca214;
            case 0x1CA23Cu: goto label_1ca23c;
            case 0x1CA264u: goto label_1ca264;
            case 0x1CA28Cu: goto label_1ca28c;
            case 0x1CA2ACu: goto label_1ca2ac;
            case 0x1CA2B8u: goto label_1ca2b8;
            case 0x1CA2DCu: goto label_1ca2dc;
            case 0x1CA2E0u: goto label_1ca2e0;
            case 0x1CA2ECu: goto label_1ca2ec;
            case 0x1CA308u: goto label_1ca308;
            case 0x1CA310u: goto label_1ca310;
            case 0x1CA318u: goto label_1ca318;
            case 0x1CA330u: goto label_1ca330;
            case 0x1CA35Cu: goto label_1ca35c;
            case 0x1CA364u: goto label_1ca364;
            case 0x1CA378u: goto label_1ca378;
            case 0x1CA384u: goto label_1ca384;
            case 0x1CA3BCu: goto label_1ca3bc;
            case 0x1CA3C0u: goto label_1ca3c0;
            case 0x1CA3C4u: goto label_1ca3c4;
            case 0x1CA43Cu: goto label_1ca43c;
            case 0x1CA474u: goto label_1ca474;
            case 0x1CA490u: goto label_1ca490;
            case 0x1CA558u: goto label_1ca558;
            case 0x1CA57Cu: goto label_1ca57c;
            case 0x1CA598u: goto label_1ca598;
            case 0x1CA5C0u: goto label_1ca5c0;
            case 0x1CA5D8u: goto label_1ca5d8;
            case 0x1CA610u: goto label_1ca610;
            case 0x1CA624u: goto label_1ca624;
            case 0x1CA630u: goto label_1ca630;
            case 0x1CA668u: goto label_1ca668;
            case 0x1CA688u: goto label_1ca688;
            case 0x1CA690u: goto label_1ca690;
            case 0x1CA694u: goto label_1ca694;
            case 0x1CA698u: goto label_1ca698;
            case 0x1CA6A0u: goto label_1ca6a0;
            case 0x1CA6C0u: goto label_1ca6c0;
            case 0x1CA6ECu: goto label_1ca6ec;
            case 0x1CA724u: goto label_1ca724;
            case 0x1CA738u: goto label_1ca738;
            case 0x1CA740u: goto label_1ca740;
            case 0x1CA778u: goto label_1ca778;
            case 0x1CA790u: goto label_1ca790;
            case 0x1CA7D0u: goto label_1ca7d0;
            case 0x1CA808u: goto label_1ca808;
            case 0x1CA810u: goto label_1ca810;
            case 0x1CA820u: goto label_1ca820;
            case 0x1CA84Cu: goto label_1ca84c;
            case 0x1CA86Cu: goto label_1ca86c;
            case 0x1CA8B8u: goto label_1ca8b8;
            case 0x1CA8C8u: goto label_1ca8c8;
            case 0x1CA8CCu: goto label_1ca8cc;
            case 0x1CA8D4u: goto label_1ca8d4;
            case 0x1CA914u: goto label_1ca914;
            case 0x1CA94Cu: goto label_1ca94c;
            case 0x1CA954u: goto label_1ca954;
            case 0x1CA970u: goto label_1ca970;
            case 0x1CA99Cu: goto label_1ca99c;
            case 0x1CA9A4u: goto label_1ca9a4;
            case 0x1CA9B4u: goto label_1ca9b4;
            case 0x1CA9ECu: goto label_1ca9ec;
            case 0x1CA9F8u: goto label_1ca9f8;
            case 0x1CAA18u: goto label_1caa18;
            case 0x1CAA24u: goto label_1caa24;
            case 0x1CAA5Cu: goto label_1caa5c;
            case 0x1CAA74u: goto label_1caa74;
            case 0x1CAAB4u: goto label_1caab4;
            case 0x1CAAECu: goto label_1caaec;
            case 0x1CAAF4u: goto label_1caaf4;
            case 0x1CAB04u: goto label_1cab04;
            case 0x1CAB30u: goto label_1cab30;
            case 0x1CAB48u: goto label_1cab48;
            case 0x1CAB94u: goto label_1cab94;
            case 0x1CABA4u: goto label_1caba4;
            case 0x1CABA8u: goto label_1caba8;
            case 0x1CABB0u: goto label_1cabb0;
            case 0x1CABB8u: goto label_1cabb8;
            case 0x1CABF0u: goto label_1cabf0;
            case 0x1CABF8u: goto label_1cabf8;
            case 0x1CAC30u: goto label_1cac30;
            case 0x1CAC48u: goto label_1cac48;
            case 0x1CAC60u: goto label_1cac60;
            case 0x1CAC90u: goto label_1cac90;
            case 0x1CACC8u: goto label_1cacc8;
            case 0x1CACD0u: goto label_1cacd0;
            case 0x1CACE0u: goto label_1cace0;
            case 0x1CAD00u: goto label_1cad00;
            case 0x1CAD2Cu: goto label_1cad2c;
            case 0x1CAD34u: goto label_1cad34;
            case 0x1CAD48u: goto label_1cad48;
            case 0x1CAD50u: goto label_1cad50;
            case 0x1CAD60u: goto label_1cad60;
            case 0x1CAD88u: goto label_1cad88;
            case 0x1CAD90u: goto label_1cad90;
            case 0x1CADBCu: goto label_1cadbc;
            case 0x1CADD4u: goto label_1cadd4;
            case 0x1CADDCu: goto label_1caddc;
            case 0x1CAE14u: goto label_1cae14;
            case 0x1CAE1Cu: goto label_1cae1c;
            case 0x1CAE44u: goto label_1cae44;
            case 0x1CAE70u: goto label_1cae70;
            case 0x1CAE78u: goto label_1cae78;
            case 0x1CAE84u: goto label_1cae84;
            case 0x1CAEBCu: goto label_1caebc;
            case 0x1CAED8u: goto label_1caed8;
            case 0x1CAF10u: goto label_1caf10;
            case 0x1CAF1Cu: goto label_1caf1c;
            case 0x1CAF24u: goto label_1caf24;
            case 0x1CAF38u: goto label_1caf38;
            case 0x1CAF4Cu: goto label_1caf4c;
            case 0x1CAF7Cu: goto label_1caf7c;
            case 0x1CAFB4u: goto label_1cafb4;
            case 0x1CAFE0u: goto label_1cafe0;
            case 0x1CAFE8u: goto label_1cafe8;
            case 0x1CB000u: goto label_1cb000;
            case 0x1CB00Cu: goto label_1cb00c;
            case 0x1CB044u: goto label_1cb044;
            case 0x1CB048u: goto label_1cb048;
            case 0x1CB04Cu: goto label_1cb04c;
            case 0x1CB0DCu: goto label_1cb0dc;
            case 0x1CB104u: goto label_1cb104;
            case 0x1CB11Cu: goto label_1cb11c;
            case 0x1CB124u: goto label_1cb124;
            case 0x1CB150u: goto label_1cb150;
            case 0x1CB154u: goto label_1cb154;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C9950u;
    // 0x1c9950: 0x27bdff60  addiu       $sp, $sp, -0xA0
    ctx->pc = 0x1c9950u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967136));
    // 0x1c9954: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x1c9954u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x1c9958: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x1c9958u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x1c995c: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1c995cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1c9960: 0x160b82d  daddu       $s7, $t3, $zero
    ctx->pc = 0x1c9960u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9964: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1c9964u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1c9968: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x1c9968u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c996c: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1c996cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1c9970: 0x140a82d  daddu       $s5, $t2, $zero
    ctx->pc = 0x1c9970u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9974: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1c9974u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1c9978: 0xa0a02d  daddu       $s4, $a1, $zero
    ctx->pc = 0x1c9978u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c997c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1c997cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1c9980: 0xc0982d  daddu       $s3, $a2, $zero
    ctx->pc = 0x1c9980u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9984: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1c9984u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1c9988: 0xe0902d  daddu       $s2, $a3, $zero
    ctx->pc = 0x1c9988u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c998c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1c998cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1c9990: 0x100882d  daddu       $s1, $t0, $zero
    ctx->pc = 0x1c9990u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9994: 0xc0725ac  jal         func_1C96B0
    ctx->pc = 0x1C9994u;
    SET_GPR_U32(ctx, 31, 0x1C999Cu);
    ctx->pc = 0x1C9998u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9994u;
            // 0x1c9998: 0x120802d  daddu       $s0, $t1, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C96B0u;
    if (runtime->hasFunction(0x1C96B0u)) {
        auto targetFn = runtime->lookupFunction(0x1C96B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C999Cu; }
        if (ctx->pc != 0x1C999Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C96B0_0x1c96b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C999Cu; }
        if (ctx->pc != 0x1C999Cu) { return; }
    }
    ctx->pc = 0x1C999Cu;
label_1c999c:
    // 0x1c999c: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1C999Cu;
    {
        const bool branch_taken_0x1c999c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1C99A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C999Cu;
            // 0x1c99a0: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c999c) {
            ctx->pc = 0x1C99D4u;
            goto label_1c99d4;
        }
    }
    ctx->pc = 0x1C99A4u;
    // 0x1c99a4: 0x2402ffaf  addiu       $v0, $zero, -0x51
    ctx->pc = 0x1c99a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967215));
    // 0x1c99a8: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c99a8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c99ac: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1c99acu;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c99b0: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1c99b0u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c99b4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c99b4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c99b8: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1c99b8u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c99bc: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1c99bcu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c99c0: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1c99c0u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c99c4: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1c99c4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c99c8: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1c99c8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c99cc: 0x1000027c  b           . + 4 + (0x27C << 2)
    ctx->pc = 0x1C99CCu;
    {
        const bool branch_taken_0x1c99cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C99D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C99CCu;
            // 0x1c99d0: 0xa6a00000  sh          $zero, 0x0($s5) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c99cc) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1C99D4u;
label_1c99d4:
    // 0x1c99d4: 0x9023c6ec  lbu         $v1, -0x3914($at)
    ctx->pc = 0x1c99d4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1c99d8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c99d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c99dc: 0x9022c6ed  lbu         $v0, -0x3913($at)
    ctx->pc = 0x1c99dcu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952685)));
    // 0x1c99e0: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1c99e0u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1c99e4: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C99E4u;
    {
        const bool branch_taken_0x1c99e4 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c99e4) {
            ctx->pc = 0x1C99F0u;
            goto label_1c99f0;
        }
    }
    ctx->pc = 0x1C99ECu;
    // 0x1c99ec: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1c99ecu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1c99f0:
    // 0x1c99f0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c99f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c99f4: 0x24040064  addiu       $a0, $zero, 0x64
    ctx->pc = 0x1c99f4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1c99f8: 0xa023c6ed  sb          $v1, -0x3913($at)
    ctx->pc = 0x1c99f8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952685), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c99fc: 0x82880000  lb          $t0, 0x0($s4)
    ctx->pc = 0x1c99fcu;
    SET_GPR_S32(ctx, 8, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1c9a00: 0x1104025d  beq         $t0, $a0, . + 4 + (0x25D << 2)
    ctx->pc = 0x1C9A00u;
    {
        const bool branch_taken_0x1c9a00 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 4));
        ctx->pc = 0x1C9A04u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9A00u;
            // 0x1c9a04: 0x24020063  addiu       $v0, $zero, 0x63 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9a00) {
            ctx->pc = 0x1CA378u;
            goto label_1ca378;
        }
    }
    ctx->pc = 0x1C9A08u;
    // 0x1c9a08: 0x11020256  beq         $t0, $v0, . + 4 + (0x256 << 2)
    ctx->pc = 0x1C9A08u;
    {
        const bool branch_taken_0x1c9a08 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C9A0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9A08u;
            // 0x1c9a0c: 0x25030001  addiu       $v1, $t0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9a08) {
            ctx->pc = 0x1CA364u;
            goto label_1ca364;
        }
    }
    ctx->pc = 0x1C9A10u;
    // 0x1c9a10: 0x24020007  addiu       $v0, $zero, 0x7
    ctx->pc = 0x1c9a10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 7));
    // 0x1c9a14: 0x11020246  beq         $t0, $v0, . + 4 + (0x246 << 2)
    ctx->pc = 0x1C9A14u;
    {
        const bool branch_taken_0x1c9a14 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C9A18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9A14u;
            // 0x1c9a18: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9a14) {
            ctx->pc = 0x1CA330u;
            goto label_1ca330;
        }
    }
    ctx->pc = 0x1C9A1Cu;
    // 0x1c9a1c: 0x24030006  addiu       $v1, $zero, 0x6
    ctx->pc = 0x1c9a1cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1c9a20: 0x11030232  beq         $t0, $v1, . + 4 + (0x232 << 2)
    ctx->pc = 0x1C9A20u;
    {
        const bool branch_taken_0x1c9a20 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 3));
        ctx->pc = 0x1C9A24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9A20u;
            // 0x1c9a24: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9a20) {
            ctx->pc = 0x1CA2ECu;
            goto label_1ca2ec;
        }
    }
    ctx->pc = 0x1C9A28u;
    // 0x1c9a28: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1c9a28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1c9a2c: 0x11020124  beq         $t0, $v0, . + 4 + (0x124 << 2)
    ctx->pc = 0x1C9A2Cu;
    {
        const bool branch_taken_0x1c9a2c = (GPR_U64(ctx, 8) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C9A30u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9A2Cu;
            // 0x1c9a30: 0x24020004  addiu       $v0, $zero, 0x4 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9a2c) {
            ctx->pc = 0x1C9EC0u;
            goto label_1c9ec0;
        }
    }
    ctx->pc = 0x1C9A34u;
    // 0x1c9a34: 0x1102010d  beq         $t0, $v0, . + 4 + (0x10D << 2)
    ctx->pc = 0x1C9A34u;
    {
        const bool branch_taken_0x1c9a34 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 2));
        ctx->pc = 0x1C9A38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9A34u;
            // 0x1c9a38: 0x24060003  addiu       $a2, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9a34) {
            ctx->pc = 0x1C9E6Cu;
            goto label_1c9e6c;
        }
    }
    ctx->pc = 0x1C9A3Cu;
    // 0x1c9a3c: 0x110600d0  beq         $t0, $a2, . + 4 + (0xD0 << 2)
    ctx->pc = 0x1C9A3Cu;
    {
        const bool branch_taken_0x1c9a3c = (GPR_U64(ctx, 8) == GPR_U64(ctx, 6));
        ctx->pc = 0x1C9A40u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9A3Cu;
            // 0x1c9a40: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9a3c) {
            ctx->pc = 0x1C9D80u;
            goto label_1c9d80;
        }
    }
    ctx->pc = 0x1C9A44u;
    // 0x1c9a44: 0x24070002  addiu       $a3, $zero, 0x2
    ctx->pc = 0x1c9a44u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c9a48: 0x110700b3  beq         $t0, $a3, . + 4 + (0xB3 << 2)
    ctx->pc = 0x1C9A48u;
    {
        const bool branch_taken_0x1c9a48 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 7));
        ctx->pc = 0x1C9A4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9A48u;
            // 0x1c9a4c: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9a48) {
            ctx->pc = 0x1C9D18u;
            goto label_1c9d18;
        }
    }
    ctx->pc = 0x1C9A50u;
    // 0x1c9a50: 0x24050001  addiu       $a1, $zero, 0x1
    ctx->pc = 0x1c9a50u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c9a54: 0x1105008e  beq         $t0, $a1, . + 4 + (0x8E << 2)
    ctx->pc = 0x1C9A54u;
    {
        const bool branch_taken_0x1c9a54 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 5));
        ctx->pc = 0x1C9A58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9A54u;
            // 0x1c9a58: 0x2404000a  addiu       $a0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9a54) {
            ctx->pc = 0x1C9C90u;
            goto label_1c9c90;
        }
    }
    ctx->pc = 0x1C9A5Cu;
    // 0x1c9a5c: 0x1104002c  beq         $t0, $a0, . + 4 + (0x2C << 2)
    ctx->pc = 0x1C9A5Cu;
    {
        const bool branch_taken_0x1c9a5c = (GPR_U64(ctx, 8) == GPR_U64(ctx, 4));
        ctx->pc = 0x1C9A60u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9A5Cu;
            // 0x1c9a60: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9a5c) {
            ctx->pc = 0x1C9B10u;
            goto label_1c9b10;
        }
    }
    ctx->pc = 0x1C9A64u;
    // 0x1c9a64: 0x11000003  beqz        $t0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C9A64u;
    {
        const bool branch_taken_0x1c9a64 = (GPR_U64(ctx, 8) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9A68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9A64u;
            // 0x1c9a68: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9a64) {
            ctx->pc = 0x1C9A74u;
            goto label_1c9a74;
        }
    }
    ctx->pc = 0x1C9A6Cu;
    // 0x1c9a6c: 0x10000254  b           . + 4 + (0x254 << 2)
    ctx->pc = 0x1C9A6Cu;
    {
        const bool branch_taken_0x1c9a6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9A70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9A6Cu;
            // 0x1c9a70: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9a6c) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1C9A74u;
label_1c9a74:
    // 0x1c9a74: 0x8c23d158  lw          $v1, -0x2EA8($at)
    ctx->pc = 0x1c9a74u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1c9a78: 0x14600003  bnez        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C9A78u;
    {
        const bool branch_taken_0x1c9a78 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C9A7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9A78u;
            // 0x1c9a7c: 0x2403ffaf  addiu       $v1, $zero, -0x51 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967215));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9a78) {
            ctx->pc = 0x1C9A88u;
            goto label_1c9a88;
        }
    }
    ctx->pc = 0x1C9A80u;
    // 0x1c9a80: 0x1000024f  b           . + 4 + (0x24F << 2)
    ctx->pc = 0x1C9A80u;
    {
        const bool branch_taken_0x1c9a80 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9A84u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9A80u;
            // 0x1c9a84: 0xa2e30000  sb          $v1, 0x0($s7) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9a80) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1C9A88u;
label_1c9a88:
    // 0x1c9a88: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9a88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9a8c: 0xa024c6ee  sb          $a0, -0x3912($at)
    ctx->pc = 0x1c9a8cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 4));
    // 0x1c9a90: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9a90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9a94: 0xa020c6ec  sb          $zero, -0x3914($at)
    ctx->pc = 0x1c9a94u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c9a98: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9a98u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9a9c: 0xa020c6ed  sb          $zero, -0x3913($at)
    ctx->pc = 0x1c9a9cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952685), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c9aa0: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1c9aa0u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c9aa4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9aa4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9aa8: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1c9aa8u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9aac: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1c9aacu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9ab0: 0xa6060000  sh          $a2, 0x0($s0)
    ctx->pc = 0x1c9ab0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 6));
    // 0x1c9ab4: 0xa6a70000  sh          $a3, 0x0($s5)
    ctx->pc = 0x1c9ab4u;
    WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 7));
    // 0x1c9ab8: 0x8c22d158  lw          $v0, -0x2EA8($at)
    ctx->pc = 0x1c9ab8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1c9abc: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1c9abcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c9ac0: 0x1445000f  bne         $v0, $a1, . + 4 + (0xF << 2)
    ctx->pc = 0x1C9AC0u;
    {
        const bool branch_taken_0x1c9ac0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 5));
        ctx->pc = 0x1C9AC4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9AC0u;
            // 0x1c9ac4: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9ac0) {
            ctx->pc = 0x1C9B00u;
            goto label_1c9b00;
        }
    }
    ctx->pc = 0x1C9AC8u;
    // 0x1c9ac8: 0x8022cc48  lb          $v0, -0x33B8($at)
    ctx->pc = 0x1c9ac8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294954056)));
    // 0x1c9acc: 0x10400009  beqz        $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1C9ACCu;
    {
        const bool branch_taken_0x1c9acc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c9acc) {
            ctx->pc = 0x1C9AF4u;
            goto label_1c9af4;
        }
    }
    ctx->pc = 0x1C9AD4u;
    // 0x1c9ad4: 0x10450007  beq         $v0, $a1, . + 4 + (0x7 << 2)
    ctx->pc = 0x1C9AD4u;
    {
        const bool branch_taken_0x1c9ad4 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 5));
        if (branch_taken_0x1c9ad4) {
            ctx->pc = 0x1C9AF4u;
            goto label_1c9af4;
        }
    }
    ctx->pc = 0x1C9ADCu;
    // 0x1c9adc: 0x10470003  beq         $v0, $a3, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C9ADCu;
    {
        const bool branch_taken_0x1c9adc = (GPR_U64(ctx, 2) == GPR_U64(ctx, 7));
        if (branch_taken_0x1c9adc) {
            ctx->pc = 0x1C9AECu;
            goto label_1c9aec;
        }
    }
    ctx->pc = 0x1C9AE4u;
    // 0x1c9ae4: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1C9AE4u;
    {
        const bool branch_taken_0x1c9ae4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9AE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9AE4u;
            // 0x1c9ae8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9ae4) {
            ctx->pc = 0x1C9B08u;
            goto label_1c9b08;
        }
    }
    ctx->pc = 0x1C9AECu;
label_1c9aec:
    // 0x1c9aec: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1C9AECu;
    {
        const bool branch_taken_0x1c9aec = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9AF0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9AECu;
            // 0x1c9af0: 0xa2840000  sb          $a0, 0x0($s4) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9aec) {
            ctx->pc = 0x1C9B04u;
            goto label_1c9b04;
        }
    }
    ctx->pc = 0x1C9AF4u;
label_1c9af4:
    // 0x1c9af4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1c9af4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c9af8: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1C9AF8u;
    {
        const bool branch_taken_0x1c9af8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9AFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9AF8u;
            // 0x1c9afc: 0xa2c20000  sb          $v0, 0x0($s6) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9af8) {
            ctx->pc = 0x1C9B04u;
            goto label_1c9b04;
        }
    }
    ctx->pc = 0x1C9B00u;
label_1c9b00:
    // 0x1c9b00: 0xa2840000  sb          $a0, 0x0($s4)
    ctx->pc = 0x1c9b00u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 4));
label_1c9b04:
    // 0x1c9b04: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c9b04u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1c9b08:
    // 0x1c9b08: 0x1000022e  b           . + 4 + (0x22E << 2)
    ctx->pc = 0x1C9B08u;
    {
        const bool branch_taken_0x1c9b08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9B0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9B08u;
            // 0x1c9b0c: 0xdfbf0080  ld          $ra, 0x80($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9b08) {
            ctx->pc = 0x1CA3C4u;
            goto label_1ca3c4;
        }
    }
    ctx->pc = 0x1C9B10u;
label_1c9b10:
    // 0x1c9b10: 0x302d  daddu       $a2, $zero, $zero
    ctx->pc = 0x1c9b10u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9b14: 0x8c22d158  lw          $v0, -0x2EA8($at)
    ctx->pc = 0x1c9b14u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1c9b18: 0x8c440000  lw          $a0, 0x0($v0)
    ctx->pc = 0x1c9b18u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c9b1c: 0x8c450004  lw          $a1, 0x4($v0)
    ctx->pc = 0x1c9b1cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1c9b20: 0xc075bac  jal         func_1D6EB0
    ctx->pc = 0x1C9B20u;
    SET_GPR_U32(ctx, 31, 0x1C9B28u);
    ctx->pc = 0x1C9B24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9B20u;
            // 0x1c9b24: 0x27a80090  addiu       $t0, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6EB0u;
    if (runtime->hasFunction(0x1D6EB0u)) {
        auto targetFn = runtime->lookupFunction(0x1D6EB0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9B28u; }
        if (ctx->pc != 0x1C9B28u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6EB0_0x1d6eb0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9B28u; }
        if (ctx->pc != 0x1C9B28u) { return; }
    }
    ctx->pc = 0x1C9B28u;
label_1c9b28:
    // 0x1c9b28: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x1c9b28u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1c9b2c: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1c9b2cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1c9b30: 0xa2880000  sb          $t0, 0x0($s4)
    ctx->pc = 0x1c9b30u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 8));
    // 0x1c9b34: 0x2463d9b0  addiu       $v1, $v1, -0x2650
    ctx->pc = 0x1c9b34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294957488));
    // 0x1c9b38: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9b38u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9b3c: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1c9b3cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1c9b40: 0xac23d9d0  sw          $v1, -0x2630($at)
    ctx->pc = 0x1c9b40u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957520), GPR_U32(ctx, 3));
    // 0x1c9b44: 0x2442d9a0  addiu       $v0, $v0, -0x2660
    ctx->pc = 0x1c9b44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294957472));
    // 0x1c9b48: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9b48u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9b4c: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1c9b4cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1c9b50: 0xac22d9b0  sw          $v0, -0x2650($at)
    ctx->pc = 0x1c9b50u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957488), GPR_U32(ctx, 2));
    // 0x1c9b54: 0x2463d998  addiu       $v1, $v1, -0x2668
    ctx->pc = 0x1c9b54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294957464));
    // 0x1c9b58: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9b58u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9b5c: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1c9b5cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1c9b60: 0xac23d9b4  sw          $v1, -0x264C($at)
    ctx->pc = 0x1c9b60u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957492), GPR_U32(ctx, 3));
    // 0x1c9b64: 0x2442d9e0  addiu       $v0, $v0, -0x2620
    ctx->pc = 0x1c9b64u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294957536));
    // 0x1c9b68: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9b68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9b6c: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1c9b6cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1c9b70: 0xac22d9b8  sw          $v0, -0x2648($at)
    ctx->pc = 0x1c9b70u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957496), GPR_U32(ctx, 2));
    // 0x1c9b74: 0x2463cb50  addiu       $v1, $v1, -0x34B0
    ctx->pc = 0x1c9b74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294953808));
    // 0x1c9b78: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9b78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9b7c: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1c9b7cu;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1c9b80: 0xac23d9c4  sw          $v1, -0x263C($at)
    ctx->pc = 0x1c9b80u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957508), GPR_U32(ctx, 3));
    // 0x1c9b84: 0x2442c930  addiu       $v0, $v0, -0x36D0
    ctx->pc = 0x1c9b84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294953264));
    // 0x1c9b88: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9b88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9b8c: 0x3c030034  lui         $v1, 0x34
    ctx->pc = 0x1c9b8cu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)52 << 16));
    // 0x1c9b90: 0xac22d9c8  sw          $v0, -0x2638($at)
    ctx->pc = 0x1c9b90u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957512), GPR_U32(ctx, 2));
    // 0x1c9b94: 0x2463c830  addiu       $v1, $v1, -0x37D0
    ctx->pc = 0x1c9b94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 4294953008));
    // 0x1c9b98: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9b98u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9b9c: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1c9b9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1c9ba0: 0xac23d9cc  sw          $v1, -0x2634($at)
    ctx->pc = 0x1c9ba0u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957516), GPR_U32(ctx, 3));
    // 0x1c9ba4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9ba4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9ba8: 0x8fa50090  lw          $a1, 0x90($sp)
    ctx->pc = 0x1c9ba8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 144)));
    // 0x1c9bac: 0xa422d9a0  sh          $v0, -0x2660($at)
    ctx->pc = 0x1c9bacu;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294957472), (uint16_t)GPR_U32(ctx, 2));
    // 0x1c9bb0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9bb0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9bb4: 0x8fa40094  lw          $a0, 0x94($sp)
    ctx->pc = 0x1c9bb4u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 148)));
    // 0x1c9bb8: 0xa420d9d4  sh          $zero, -0x262C($at)
    ctx->pc = 0x1c9bb8u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294957524), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9bbc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9bbcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9bc0: 0xa420d9a2  sh          $zero, -0x265E($at)
    ctx->pc = 0x1c9bc0u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294957474), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9bc4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9bc4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9bc8: 0xa420d9a4  sh          $zero, -0x265C($at)
    ctx->pc = 0x1c9bc8u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294957476), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9bcc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9bccu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9bd0: 0xa428d9a6  sh          $t0, -0x265A($at)
    ctx->pc = 0x1c9bd0u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294957478), (uint16_t)GPR_U32(ctx, 8));
    // 0x1c9bd4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9bd4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9bd8: 0xa428d9a8  sh          $t0, -0x2658($at)
    ctx->pc = 0x1c9bd8u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294957480), (uint16_t)GPR_U32(ctx, 8));
    // 0x1c9bdc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9bdcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9be0: 0x8027cc48  lb          $a3, -0x33B8($at)
    ctx->pc = 0x1c9be0u;
    SET_GPR_S32(ctx, 7, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294954056)));
    // 0x1c9be4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9be4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9be8: 0x38e70002  xori        $a3, $a3, 0x2
    ctx->pc = 0x1c9be8u;
    SET_GPR_U64(ctx, 7, GPR_U64(ctx, 7) ^ (uint64_t)(uint16_t)2);
    // 0x1c9bec: 0x9026c820  lbu         $a2, -0x37E0($at)
    ctx->pc = 0x1c9becu;
    SET_GPR_U32(ctx, 6, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952992)));
    // 0x1c9bf0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9bf0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9bf4: 0x9023cc40  lbu         $v1, -0x33C0($at)
    ctx->pc = 0x1c9bf4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294954048)));
    // 0x1c9bf8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9bf8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9bfc: 0x8022cb40  lb          $v0, -0x34C0($at)
    ctx->pc = 0x1c9bfcu;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294953792)));
    // 0x1c9c00: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9c00u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9c04: 0xa026d9d7  sb          $a2, -0x2629($at)
    ctx->pc = 0x1c9c04u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294957527), (uint8_t)GPR_U32(ctx, 6));
    // 0x1c9c08: 0x2ce60001  sltiu       $a2, $a3, 0x1
    ctx->pc = 0x1c9c08u;
    SET_GPR_U64(ctx, 6, ((uint64_t)GPR_U64(ctx, 7) < (uint64_t)(int64_t)(int32_t)1) ? 1 : 0);
    // 0x1c9c0c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9c0cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9c10: 0xa026d9d6  sb          $a2, -0x262A($at)
    ctx->pc = 0x1c9c10u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294957526), (uint8_t)GPR_U32(ctx, 6));
    // 0x1c9c14: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9c14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9c18: 0xac25d9bc  sw          $a1, -0x2644($at)
    ctx->pc = 0x1c9c18u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957500), GPR_U32(ctx, 5));
    // 0x1c9c1c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9c1cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9c20: 0xac24d9c0  sw          $a0, -0x2640($at)
    ctx->pc = 0x1c9c20u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957504), GPR_U32(ctx, 4));
    // 0x1c9c24: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9c24u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9c28: 0x14400008  bnez        $v0, . + 4 + (0x8 << 2)
    ctx->pc = 0x1C9C28u;
    {
        const bool branch_taken_0x1c9c28 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C9C2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9C28u;
            // 0x1c9c2c: 0xa423d998  sh          $v1, -0x2668($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 4294957464), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9c28) {
            ctx->pc = 0x1C9C4Cu;
            goto label_1c9c4c;
        }
    }
    ctx->pc = 0x1C9C30u;
    // 0x1c9c30: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9c30u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9c34: 0x3c020025  lui         $v0, 0x25
    ctx->pc = 0x1c9c34u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)37 << 16));
    // 0x1c9c38: 0xa420d99a  sh          $zero, -0x2666($at)
    ctx->pc = 0x1c9c38u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294957466), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9c3c: 0x24422e28  addiu       $v0, $v0, 0x2E28
    ctx->pc = 0x1c9c3cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 11816));
    // 0x1c9c40: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9c40u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9c44: 0x10000007  b           . + 4 + (0x7 << 2)
    ctx->pc = 0x1C9C44u;
    {
        const bool branch_taken_0x1c9c44 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9C48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9C44u;
            // 0x1c9c48: 0xac22d99c  sw          $v0, -0x2664($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294957468), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9c44) {
            ctx->pc = 0x1C9C64u;
            goto label_1c9c64;
        }
    }
    ctx->pc = 0x1C9C4Cu;
label_1c9c4c:
    // 0x1c9c4c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9c4cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9c50: 0x3c020034  lui         $v0, 0x34
    ctx->pc = 0x1c9c50u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)52 << 16));
    // 0x1c9c54: 0xa428d99a  sh          $t0, -0x2666($at)
    ctx->pc = 0x1c9c54u;
    WRITE16(ADD32(GPR_U32(ctx, 1), 4294957466), (uint16_t)GPR_U32(ctx, 8));
    // 0x1c9c58: 0x2442cb40  addiu       $v0, $v0, -0x34C0
    ctx->pc = 0x1c9c58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294953792));
    // 0x1c9c5c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9c5cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9c60: 0xac22d99c  sw          $v0, -0x2664($at)
    ctx->pc = 0x1c9c60u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294957468), GPR_U32(ctx, 2));
label_1c9c64:
    // 0x1c9c64: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1c9c64u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1c9c68: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c9c68u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9c6c: 0x2484d9e0  addiu       $a0, $a0, -0x2620
    ctx->pc = 0x1c9c6cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957536));
    // 0x1c9c70: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1C9C70u;
    SET_GPR_U32(ctx, 31, 0x1C9C78u);
    ctx->pc = 0x1C9C74u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9C70u;
            // 0x1c9c74: 0x24060010  addiu       $a2, $zero, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9C78u; }
        if (ctx->pc != 0x1C9C78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9C78u; }
        if (ctx->pc != 0x1C9C78u) { return; }
    }
    ctx->pc = 0x1C9C78u;
label_1c9c78:
    // 0x1c9c78: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9c78u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9c7c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c9c7cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9c80: 0x9023c818  lbu         $v1, -0x37E8($at)
    ctx->pc = 0x1c9c80u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952984)));
    // 0x1c9c84: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9c84u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9c88: 0x100001cd  b           . + 4 + (0x1CD << 2)
    ctx->pc = 0x1C9C88u;
    {
        const bool branch_taken_0x1c9c88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9C8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9C88u;
            // 0x1c9c8c: 0xa423d9e0  sh          $v1, -0x2620($at) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 1), 4294957536), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9c88) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1C9C90u;
label_1c9c90:
    // 0x1c9c90: 0x86430000  lh          $v1, 0x0($s2)
    ctx->pc = 0x1c9c90u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1c9c94: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x1c9c94u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1c9c98: 0x3082a  slt         $at, $zero, $v1
    ctx->pc = 0x1c9c98u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1c9c9c: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C9C9Cu;
    {
        const bool branch_taken_0x1c9c9c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9CA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9C9Cu;
            // 0x1c9ca0: 0xa6420000  sh          $v0, 0x0($s2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9c9c) {
            ctx->pc = 0x1C9CACu;
            goto label_1c9cac;
        }
    }
    ctx->pc = 0x1C9CA4u;
    // 0x1c9ca4: 0x100001c6  b           . + 4 + (0x1C6 << 2)
    ctx->pc = 0x1C9CA4u;
    {
        const bool branch_taken_0x1c9ca4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9CA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9CA4u;
            // 0x1c9ca8: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9ca4) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1C9CACu;
label_1c9cac:
    // 0x1c9cac: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1c9cacu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9cb0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9cb0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9cb4: 0xa027c6ec  sb          $a3, -0x3914($at)
    ctx->pc = 0x1c9cb4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 7));
    // 0x1c9cb8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9cb8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9cbc: 0x8c22d158  lw          $v0, -0x2EA8($at)
    ctx->pc = 0x1c9cbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1c9cc0: 0x8c450004  lw          $a1, 0x4($v0)
    ctx->pc = 0x1c9cc0u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1c9cc4: 0xc075a2c  jal         func_1D68B0
    ctx->pc = 0x1C9CC4u;
    SET_GPR_U32(ctx, 31, 0x1C9CCCu);
    ctx->pc = 0x1C9CC8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9CC4u;
            // 0x1c9cc8: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D68B0u;
    if (runtime->hasFunction(0x1D68B0u)) {
        auto targetFn = runtime->lookupFunction(0x1D68B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9CCCu; }
        if (ctx->pc != 0x1C9CCCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D68B0_0x1d68b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9CCCu; }
        if (ctx->pc != 0x1C9CCCu) { return; }
    }
    ctx->pc = 0x1C9CCCu;
label_1c9ccc:
    // 0x1c9ccc: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1C9CCCu;
    {
        const bool branch_taken_0x1c9ccc = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1c9ccc) {
            ctx->pc = 0x1C9D04u;
            goto label_1c9d04;
        }
    }
    ctx->pc = 0x1C9CD4u;
    // 0x1c9cd4: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1c9cd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1c9cd8: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c9cd8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c9cdc: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1c9cdcu;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c9ce0: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1c9ce0u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c9ce4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c9ce4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9ce8: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1c9ce8u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c9cec: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1c9cecu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c9cf0: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1c9cf0u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9cf4: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1c9cf4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9cf8: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1c9cf8u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9cfc: 0x100001b0  b           . + 4 + (0x1B0 << 2)
    ctx->pc = 0x1C9CFCu;
    {
        const bool branch_taken_0x1c9cfc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9D00u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9CFCu;
            // 0x1c9d00: 0xa6a00000  sh          $zero, 0x0($s5) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9cfc) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1C9D04u;
label_1c9d04:
    // 0x1c9d04: 0x82830000  lb          $v1, 0x0($s4)
    ctx->pc = 0x1c9d04u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1c9d08: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c9d08u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9d0c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1c9d0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1c9d10: 0x100001ab  b           . + 4 + (0x1AB << 2)
    ctx->pc = 0x1C9D10u;
    {
        const bool branch_taken_0x1c9d10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9D14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9D10u;
            // 0x1c9d14: 0xa2830000  sb          $v1, 0x0($s4) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9d10) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1C9D18u;
label_1c9d18:
    // 0x1c9d18: 0xc075b74  jal         func_1D6DD0
    ctx->pc = 0x1C9D18u;
    SET_GPR_U32(ctx, 31, 0x1C9D20u);
    ctx->pc = 0x1C9D1Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9D18u;
            // 0x1c9d1c: 0xa022c6ec  sb          $v0, -0x3914($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6DD0u;
    if (runtime->hasFunction(0x1D6DD0u)) {
        auto targetFn = runtime->lookupFunction(0x1D6DD0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9D20u; }
        if (ctx->pc != 0x1C9D20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6DD0_0x1d6dd0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9D20u; }
        if (ctx->pc != 0x1C9D20u) { return; }
    }
    ctx->pc = 0x1C9D20u;
label_1c9d20:
    // 0x1c9d20: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1C9D20u;
    {
        const bool branch_taken_0x1c9d20 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1c9d20) {
            ctx->pc = 0x1C9D58u;
            goto label_1c9d58;
        }
    }
    ctx->pc = 0x1C9D28u;
    // 0x1c9d28: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1c9d28u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1c9d2c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c9d2cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c9d30: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1c9d30u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c9d34: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1c9d34u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c9d38: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c9d38u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9d3c: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1c9d3cu;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c9d40: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1c9d40u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c9d44: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1c9d44u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9d48: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1c9d48u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9d4c: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1c9d4cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9d50: 0x1000019b  b           . + 4 + (0x19B << 2)
    ctx->pc = 0x1C9D50u;
    {
        const bool branch_taken_0x1c9d50 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9D54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9D50u;
            // 0x1c9d54: 0xa6a00000  sh          $zero, 0x0($s5) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9d50) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1C9D58u;
label_1c9d58:
    // 0x1c9d58: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x1c9d58u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1c9d5c: 0x27a4009c  addiu       $a0, $sp, 0x9C
    ctx->pc = 0x1c9d5cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 29), 156));
    // 0x1c9d60: 0xc075b80  jal         func_1D6E00
    ctx->pc = 0x1C9D60u;
    SET_GPR_U32(ctx, 31, 0x1C9D68u);
    ctx->pc = 0x1C9D64u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9D60u;
            // 0x1c9d64: 0xafa2009c  sw          $v0, 0x9C($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 156), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6E00u;
    if (runtime->hasFunction(0x1D6E00u)) {
        auto targetFn = runtime->lookupFunction(0x1D6E00u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9D68u; }
        if (ctx->pc != 0x1C9D68u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6E00_0x1d6e00(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9D68u; }
        if (ctx->pc != 0x1C9D68u) { return; }
    }
    ctx->pc = 0x1C9D68u;
label_1c9d68:
    // 0x1c9d68: 0x82830000  lb          $v1, 0x0($s4)
    ctx->pc = 0x1c9d68u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1c9d6c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c9d6cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9d70: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1c9d70u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1c9d74: 0xa2830000  sb          $v1, 0x0($s4)
    ctx->pc = 0x1c9d74u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c9d78: 0x10000191  b           . + 4 + (0x191 << 2)
    ctx->pc = 0x1C9D78u;
    {
        const bool branch_taken_0x1c9d78 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9D7Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9D78u;
            // 0x1c9d7c: 0xa6400000  sh          $zero, 0x0($s2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9d78) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1C9D80u;
label_1c9d80:
    // 0x1c9d80: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1c9d80u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c9d84: 0xa023c6ec  sb          $v1, -0x3914($at)
    ctx->pc = 0x1c9d84u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c9d88: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9d88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9d8c: 0x8c23d158  lw          $v1, -0x2EA8($at)
    ctx->pc = 0x1c9d8cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1c9d90: 0x8c630000  lw          $v1, 0x0($v1)
    ctx->pc = 0x1c9d90u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x1c9d94: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C9D94u;
    {
        const bool branch_taken_0x1c9d94 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1c9d94) {
            ctx->pc = 0x1C9DA4u;
            goto label_1c9da4;
        }
    }
    ctx->pc = 0x1C9D9Cu;
    // 0x1c9d9c: 0x14660017  bne         $v1, $a2, . + 4 + (0x17 << 2)
    ctx->pc = 0x1C9D9Cu;
    {
        const bool branch_taken_0x1c9d9c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 6));
        if (branch_taken_0x1c9d9c) {
            ctx->pc = 0x1C9DFCu;
            goto label_1c9dfc;
        }
    }
    ctx->pc = 0x1C9DA4u;
label_1c9da4:
    // 0x1c9da4: 0xc075bb4  jal         func_1D6ED0
    ctx->pc = 0x1C9DA4u;
    SET_GPR_U32(ctx, 31, 0x1C9DACu);
    ctx->pc = 0x1D6ED0u;
    if (runtime->hasFunction(0x1D6ED0u)) {
        auto targetFn = runtime->lookupFunction(0x1D6ED0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9DACu; }
        if (ctx->pc != 0x1C9DACu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6ED0_0x1d6ed0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9DACu; }
        if (ctx->pc != 0x1C9DACu) { return; }
    }
    ctx->pc = 0x1C9DACu;
label_1c9dac:
    // 0x1c9dac: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9dacu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9db0: 0x8c23d158  lw          $v1, -0x2EA8($at)
    ctx->pc = 0x1c9db0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1c9db4: 0xac620010  sw          $v0, 0x10($v1)
    ctx->pc = 0x1c9db4u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 16), GPR_U32(ctx, 2));
    // 0x1c9db8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9db8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9dbc: 0x8c22d158  lw          $v0, -0x2EA8($at)
    ctx->pc = 0x1c9dbcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1c9dc0: 0x8c420010  lw          $v0, 0x10($v0)
    ctx->pc = 0x1c9dc0u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 16)));
    // 0x1c9dc4: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1C9DC4u;
    {
        const bool branch_taken_0x1c9dc4 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1c9dc4) {
            ctx->pc = 0x1C9DFCu;
            goto label_1c9dfc;
        }
    }
    ctx->pc = 0x1C9DCCu;
    // 0x1c9dcc: 0x2402ffaf  addiu       $v0, $zero, -0x51
    ctx->pc = 0x1c9dccu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967215));
    // 0x1c9dd0: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c9dd0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c9dd4: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1c9dd4u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c9dd8: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1c9dd8u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c9ddc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c9ddcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9de0: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1c9de0u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c9de4: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1c9de4u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c9de8: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1c9de8u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9dec: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1c9decu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9df0: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1c9df0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9df4: 0x10000172  b           . + 4 + (0x172 << 2)
    ctx->pc = 0x1C9DF4u;
    {
        const bool branch_taken_0x1c9df4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9DF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9DF4u;
            // 0x1c9df8: 0xa6a00000  sh          $zero, 0x0($s5) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9df4) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1C9DFCu;
label_1c9dfc:
    // 0x1c9dfc: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1c9dfcu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1c9e00: 0xc075bc4  jal         func_1D6F10
    ctx->pc = 0x1C9E00u;
    SET_GPR_U32(ctx, 31, 0x1C9E08u);
    ctx->pc = 0x1C9E04u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9E00u;
            // 0x1c9e04: 0x2484d9d0  addiu       $a0, $a0, -0x2630 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294957520));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D6F10u;
    if (runtime->hasFunction(0x1D6F10u)) {
        auto targetFn = runtime->lookupFunction(0x1D6F10u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9E08u; }
        if (ctx->pc != 0x1C9E08u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D6F10_0x1d6f10(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9E08u; }
        if (ctx->pc != 0x1C9E08u) { return; }
    }
    ctx->pc = 0x1C9E08u;
label_1c9e08:
    // 0x1c9e08: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1C9E08u;
    {
        const bool branch_taken_0x1c9e08 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1C9E0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9E08u;
            // 0x1c9e0c: 0x3c040034  lui         $a0, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9e08) {
            ctx->pc = 0x1C9E40u;
            goto label_1c9e40;
        }
    }
    ctx->pc = 0x1C9E10u;
    // 0x1c9e10: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1c9e10u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1c9e14: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c9e14u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c9e18: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1c9e18u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c9e1c: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1c9e1cu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c9e20: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c9e20u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9e24: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1c9e24u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c9e28: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1c9e28u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c9e2c: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1c9e2cu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9e30: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1c9e30u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9e34: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1c9e34u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9e38: 0x10000161  b           . + 4 + (0x161 << 2)
    ctx->pc = 0x1C9E38u;
    {
        const bool branch_taken_0x1c9e38 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9E3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9E38u;
            // 0x1c9e3c: 0xa6a00000  sh          $zero, 0x0($s5) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9e38) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1C9E40u;
label_1c9e40:
    // 0x1c9e40: 0x282d  daddu       $a1, $zero, $zero
    ctx->pc = 0x1c9e40u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9e44: 0x2484b670  addiu       $a0, $a0, -0x4990
    ctx->pc = 0x1c9e44u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948464));
    // 0x1c9e48: 0xc041f1a  jal         func_107C68
    ctx->pc = 0x1C9E48u;
    SET_GPR_U32(ctx, 31, 0x1C9E50u);
    ctx->pc = 0x1C9E4Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9E48u;
            // 0x1c9e4c: 0x24060014  addiu       $a2, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
    ctx->pc = 0x107C68u;
    if (runtime->hasFunction(0x107C68u)) {
        auto targetFn = runtime->lookupFunction(0x107C68u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9E50u; }
        if (ctx->pc != 0x1C9E50u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00107C68_0x107c68(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9E50u; }
        if (ctx->pc != 0x1C9E50u) { return; }
    }
    ctx->pc = 0x1C9E50u;
label_1c9e50:
    // 0x1c9e50: 0x82840000  lb          $a0, 0x0($s4)
    ctx->pc = 0x1c9e50u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1c9e54: 0x2403003b  addiu       $v1, $zero, 0x3B
    ctx->pc = 0x1c9e54u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 59));
    // 0x1c9e58: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c9e58u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9e5c: 0x24840002  addiu       $a0, $a0, 0x2
    ctx->pc = 0x1c9e5cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 2));
    // 0x1c9e60: 0xa2840000  sb          $a0, 0x0($s4)
    ctx->pc = 0x1c9e60u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1c9e64: 0x10000156  b           . + 4 + (0x156 << 2)
    ctx->pc = 0x1C9E64u;
    {
        const bool branch_taken_0x1c9e64 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9E68u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9E64u;
            // 0x1c9e68: 0xa6430000  sh          $v1, 0x0($s2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9e64) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1C9E6Cu;
label_1c9e6c:
    // 0x1c9e6c: 0x86220000  lh          $v0, 0x0($s1)
    ctx->pc = 0x1c9e6cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1c9e70: 0x2841001f  slti        $at, $v0, 0x1F
    ctx->pc = 0x1c9e70u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x1c9e74: 0x1420000d  bnez        $at, . + 4 + (0xD << 2)
    ctx->pc = 0x1C9E74u;
    {
        const bool branch_taken_0x1c9e74 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C9E78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9E74u;
            // 0x1c9e78: 0x25020001  addiu       $v0, $t0, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9e74) {
            ctx->pc = 0x1C9EACu;
            goto label_1c9eac;
        }
    }
    ctx->pc = 0x1C9E7Cu;
    // 0x1c9e7c: 0x2402ffaa  addiu       $v0, $zero, -0x56
    ctx->pc = 0x1c9e7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967210));
    // 0x1c9e80: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c9e80u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c9e84: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1c9e84u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c9e88: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1c9e88u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c9e8c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c9e8cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9e90: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1c9e90u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c9e94: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1c9e94u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c9e98: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1c9e98u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9e9c: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1c9e9cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9ea0: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1c9ea0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9ea4: 0x10000146  b           . + 4 + (0x146 << 2)
    ctx->pc = 0x1C9EA4u;
    {
        const bool branch_taken_0x1c9ea4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9EA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9EA4u;
            // 0x1c9ea8: 0xa6a00000  sh          $zero, 0x0($s5) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9ea4) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1C9EACu;
label_1c9eac:
    // 0x1c9eac: 0x2403001d  addiu       $v1, $zero, 0x1D
    ctx->pc = 0x1c9eacu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 29));
    // 0x1c9eb0: 0xa2820000  sb          $v0, 0x0($s4)
    ctx->pc = 0x1c9eb0u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c9eb4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c9eb4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9eb8: 0x10000141  b           . + 4 + (0x141 << 2)
    ctx->pc = 0x1C9EB8u;
    {
        const bool branch_taken_0x1c9eb8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9EBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9EB8u;
            // 0x1c9ebc: 0xa6430000  sh          $v1, 0x0($s2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9eb8) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1C9EC0u;
label_1c9ec0:
    // 0x1c9ec0: 0x86220000  lh          $v0, 0x0($s1)
    ctx->pc = 0x1c9ec0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1c9ec4: 0x2841001f  slti        $at, $v0, 0x1F
    ctx->pc = 0x1c9ec4u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x1c9ec8: 0x1420000c  bnez        $at, . + 4 + (0xC << 2)
    ctx->pc = 0x1C9EC8u;
    {
        const bool branch_taken_0x1c9ec8 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C9ECCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9EC8u;
            // 0x1c9ecc: 0x2402ffaa  addiu       $v0, $zero, -0x56 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967210));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9ec8) {
            ctx->pc = 0x1C9EFCu;
            goto label_1c9efc;
        }
    }
    ctx->pc = 0x1C9ED0u;
    // 0x1c9ed0: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c9ed0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c9ed4: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1c9ed4u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c9ed8: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1c9ed8u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c9edc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c9edcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9ee0: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1c9ee0u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c9ee4: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1c9ee4u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c9ee8: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1c9ee8u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9eec: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1c9eecu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9ef0: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1c9ef0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9ef4: 0x10000132  b           . + 4 + (0x132 << 2)
    ctx->pc = 0x1C9EF4u;
    {
        const bool branch_taken_0x1c9ef4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9EF8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9EF4u;
            // 0x1c9ef8: 0xa6a00000  sh          $zero, 0x0($s5) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9ef4) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1C9EFCu;
label_1c9efc:
    // 0x1c9efc: 0x86430000  lh          $v1, 0x0($s2)
    ctx->pc = 0x1c9efcu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1c9f00: 0x2402001e  addiu       $v0, $zero, 0x1E
    ctx->pc = 0x1c9f00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
    // 0x1c9f04: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x1c9f04u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1c9f08: 0x0  nop
    ctx->pc = 0x1c9f08u;
    // NOP
    // 0x1c9f0c: 0x0  nop
    ctx->pc = 0x1c9f0cu;
    // NOP
    // 0x1c9f10: 0x1010  mfhi        $v0
    ctx->pc = 0x1c9f10u;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x1c9f14: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1C9F14u;
    {
        const bool branch_taken_0x1c9f14 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1C9F18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9F14u;
            // 0x1c9f18: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9f14) {
            ctx->pc = 0x1C9F40u;
            goto label_1c9f40;
        }
    }
    ctx->pc = 0x1C9F1Cu;
    // 0x1c9f1c: 0x9023c6ee  lbu         $v1, -0x3912($at)
    ctx->pc = 0x1c9f1cu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952686)));
    // 0x1c9f20: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9f20u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9f24: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1c9f24u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1c9f28: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1c9f28u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1c9f2c: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1C9F2Cu;
    {
        const bool branch_taken_0x1c9f2c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1c9f2c) {
            ctx->pc = 0x1C9F38u;
            goto label_1c9f38;
        }
    }
    ctx->pc = 0x1C9F34u;
    // 0x1c9f34: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1c9f34u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1c9f38:
    // 0x1c9f38: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9f38u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9f3c: 0xa023c6ec  sb          $v1, -0x3914($at)
    ctx->pc = 0x1c9f3cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 3));
label_1c9f40:
    // 0x1c9f40: 0x86430000  lh          $v1, 0x0($s2)
    ctx->pc = 0x1c9f40u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1c9f44: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x1c9f44u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1c9f48: 0x3082a  slt         $at, $zero, $v1
    ctx->pc = 0x1c9f48u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1c9f4c: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1C9F4Cu;
    {
        const bool branch_taken_0x1c9f4c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9F50u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9F4Cu;
            // 0x1c9f50: 0xa6420000  sh          $v0, 0x0($s2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9f4c) {
            ctx->pc = 0x1C9F5Cu;
            goto label_1c9f5c;
        }
    }
    ctx->pc = 0x1C9F54u;
    // 0x1c9f54: 0x1000011a  b           . + 4 + (0x11A << 2)
    ctx->pc = 0x1C9F54u;
    {
        const bool branch_taken_0x1c9f54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9F58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9F54u;
            // 0x1c9f58: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9f54) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1C9F5Cu;
label_1c9f5c:
    // 0x1c9f5c: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1c9f5cu;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1c9f60: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1c9f60u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9f64: 0xc075c14  jal         func_1D7050
    ctx->pc = 0x1C9F64u;
    SET_GPR_U32(ctx, 31, 0x1C9F6Cu);
    ctx->pc = 0x1C9F68u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9F64u;
            // 0x1c9f68: 0x2484b670  addiu       $a0, $a0, -0x4990 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948464));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7050u;
    if (runtime->hasFunction(0x1D7050u)) {
        auto targetFn = runtime->lookupFunction(0x1D7050u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9F6Cu; }
        if (ctx->pc != 0x1C9F6Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7050_0x1d7050(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1C9F6Cu; }
        if (ctx->pc != 0x1C9F6Cu) { return; }
    }
    ctx->pc = 0x1C9F6Cu;
label_1c9f6c:
    // 0x1c9f6c: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1C9F6Cu;
    {
        const bool branch_taken_0x1c9f6c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1C9F70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9F6Cu;
            // 0x1c9f70: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9f6c) {
            ctx->pc = 0x1C9FA4u;
            goto label_1c9fa4;
        }
    }
    ctx->pc = 0x1C9F74u;
    // 0x1c9f74: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1c9f74u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1c9f78: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1c9f78u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1c9f7c: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1c9f7cu;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1c9f80: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1c9f80u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c9f84: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1c9f84u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1c9f88: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1c9f88u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c9f8c: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1c9f8cu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1c9f90: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1c9f90u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9f94: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1c9f94u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9f98: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1c9f98u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1c9f9c: 0x10000108  b           . + 4 + (0x108 << 2)
    ctx->pc = 0x1C9F9Cu;
    {
        const bool branch_taken_0x1c9f9c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9FA0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9F9Cu;
            // 0x1c9fa0: 0xa6a00000  sh          $zero, 0x0($s5) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9f9c) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1C9FA4u;
label_1c9fa4:
    // 0x1c9fa4: 0x8422b67c  lh          $v0, -0x4984($at)
    ctx->pc = 0x1c9fa4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294948476)));
    // 0x1c9fa8: 0x2c41000a  sltiu       $at, $v0, 0xA
    ctx->pc = 0x1c9fa8u;
    SET_GPR_U64(ctx, 1, ((uint64_t)GPR_U64(ctx, 2) < (uint64_t)(int64_t)(int32_t)10) ? 1 : 0);
    // 0x1c9fac: 0x102000c2  beqz        $at, . + 4 + (0xC2 << 2)
    ctx->pc = 0x1C9FACu;
    {
        const bool branch_taken_0x1c9fac = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9FB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9FACu;
            // 0x1c9fb0: 0x2403ffae  addiu       $v1, $zero, -0x52 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9fac) {
            ctx->pc = 0x1CA2B8u;
            goto label_1ca2b8;
        }
    }
    ctx->pc = 0x1C9FB4u;
    // 0x1c9fb4: 0x3c030025  lui         $v1, 0x25
    ctx->pc = 0x1c9fb4u;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)37 << 16));
    // 0x1c9fb8: 0x21080  sll         $v0, $v0, 2
    ctx->pc = 0x1c9fb8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 2));
    // 0x1c9fbc: 0x24632e30  addiu       $v1, $v1, 0x2E30
    ctx->pc = 0x1c9fbcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 11824));
    // 0x1c9fc0: 0x431021  addu        $v0, $v0, $v1
    ctx->pc = 0x1c9fc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 3)));
    // 0x1c9fc4: 0x8c420000  lw          $v0, 0x0($v0)
    ctx->pc = 0x1c9fc4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1c9fc8: 0x400008  jr          $v0
    ctx->pc = 0x1C9FC8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C9FD0u: goto label_1c9fd0;
            case 0x1CA000u: goto label_1ca000;
            case 0x1CA02Cu: goto label_1ca02c;
            case 0x1CA058u: goto label_1ca058;
            case 0x1CA090u: goto label_1ca090;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1C9FD0u;
label_1c9fd0:
    // 0x1c9fd0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9fd0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9fd4: 0x2403000c  addiu       $v1, $zero, 0xC
    ctx->pc = 0x1c9fd4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1c9fd8: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1c9fd8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1c9fdc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9fdcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9fe0: 0xa023c6ee  sb          $v1, -0x3912($at)
    ctx->pc = 0x1c9fe0u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 3));
    // 0x1c9fe4: 0x2841000b  slti        $at, $v0, 0xB
    ctx->pc = 0x1c9fe4u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)11) ? 1 : 0);
    // 0x1c9fe8: 0x102000bd  beqz        $at, . + 4 + (0xBD << 2)
    ctx->pc = 0x1C9FE8u;
    {
        const bool branch_taken_0x1c9fe8 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9FECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9FE8u;
            // 0x1c9fec: 0x2403001d  addiu       $v1, $zero, 0x1D (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 29));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9fe8) {
            ctx->pc = 0x1CA2E0u;
            goto label_1ca2e0;
        }
    }
    ctx->pc = 0x1C9FF0u;
    // 0x1c9ff0: 0x2402000b  addiu       $v0, $zero, 0xB
    ctx->pc = 0x1c9ff0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x1c9ff4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1c9ff4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1c9ff8: 0x100000b8  b           . + 4 + (0xB8 << 2)
    ctx->pc = 0x1C9FF8u;
    {
        const bool branch_taken_0x1c9ff8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1C9FFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1C9FF8u;
            // 0x1c9ffc: 0xa022c6ec  sb          $v0, -0x3914($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1c9ff8) {
            ctx->pc = 0x1CA2DCu;
            goto label_1ca2dc;
        }
    }
    ctx->pc = 0x1CA000u;
label_1ca000:
    // 0x1ca000: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca000u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca004: 0x2403003c  addiu       $v1, $zero, 0x3C
    ctx->pc = 0x1ca004u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1ca008: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1ca008u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1ca00c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca00cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca010: 0xa023c6ee  sb          $v1, -0x3912($at)
    ctx->pc = 0x1ca010u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca014: 0x2841000c  slti        $at, $v0, 0xC
    ctx->pc = 0x1ca014u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)12) ? 1 : 0);
    // 0x1ca018: 0x102000b0  beqz        $at, . + 4 + (0xB0 << 2)
    ctx->pc = 0x1CA018u;
    {
        const bool branch_taken_0x1ca018 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA01Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA018u;
            // 0x1ca01c: 0x2402000c  addiu       $v0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca018) {
            ctx->pc = 0x1CA2DCu;
            goto label_1ca2dc;
        }
    }
    ctx->pc = 0x1CA020u;
    // 0x1ca020: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca020u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca024: 0x100000ad  b           . + 4 + (0xAD << 2)
    ctx->pc = 0x1CA024u;
    {
        const bool branch_taken_0x1ca024 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA028u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA024u;
            // 0x1ca028: 0xa022c6ec  sb          $v0, -0x3914($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca024) {
            ctx->pc = 0x1CA2DCu;
            goto label_1ca2dc;
        }
    }
    ctx->pc = 0x1CA02Cu;
label_1ca02c:
    // 0x1ca02c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca02cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca030: 0x24030046  addiu       $v1, $zero, 0x46
    ctx->pc = 0x1ca030u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 70));
    // 0x1ca034: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1ca034u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1ca038: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca038u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca03c: 0xa023c6ee  sb          $v1, -0x3912($at)
    ctx->pc = 0x1ca03cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca040: 0x2841003c  slti        $at, $v0, 0x3C
    ctx->pc = 0x1ca040u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)60) ? 1 : 0);
    // 0x1ca044: 0x102000a5  beqz        $at, . + 4 + (0xA5 << 2)
    ctx->pc = 0x1CA044u;
    {
        const bool branch_taken_0x1ca044 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA048u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA044u;
            // 0x1ca048: 0x2402003c  addiu       $v0, $zero, 0x3C (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca044) {
            ctx->pc = 0x1CA2DCu;
            goto label_1ca2dc;
        }
    }
    ctx->pc = 0x1CA04Cu;
    // 0x1ca04c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca04cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca050: 0x100000a2  b           . + 4 + (0xA2 << 2)
    ctx->pc = 0x1CA050u;
    {
        const bool branch_taken_0x1ca050 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA054u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA050u;
            // 0x1ca054: 0xa022c6ec  sb          $v0, -0x3914($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca050) {
            ctx->pc = 0x1CA2DCu;
            goto label_1ca2dc;
        }
    }
    ctx->pc = 0x1CA058u;
label_1ca058:
    // 0x1ca058: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca058u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca05c: 0x24030050  addiu       $v1, $zero, 0x50
    ctx->pc = 0x1ca05cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 80));
    // 0x1ca060: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1ca060u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1ca064: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca064u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca068: 0xa023c6ee  sb          $v1, -0x3912($at)
    ctx->pc = 0x1ca068u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca06c: 0x28410046  slti        $at, $v0, 0x46
    ctx->pc = 0x1ca06cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)70) ? 1 : 0);
    // 0x1ca070: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CA070u;
    {
        const bool branch_taken_0x1ca070 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA074u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA070u;
            // 0x1ca074: 0x24020046  addiu       $v0, $zero, 0x46 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 70));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca070) {
            ctx->pc = 0x1CA080u;
            goto label_1ca080;
        }
    }
    ctx->pc = 0x1CA078u;
    // 0x1ca078: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca078u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca07c: 0xa022c6ec  sb          $v0, -0x3914($at)
    ctx->pc = 0x1ca07cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
label_1ca080:
    // 0x1ca080: 0x82820000  lb          $v0, 0x0($s4)
    ctx->pc = 0x1ca080u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1ca084: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1ca084u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1ca088: 0x10000094  b           . + 4 + (0x94 << 2)
    ctx->pc = 0x1CA088u;
    {
        const bool branch_taken_0x1ca088 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA08Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA088u;
            // 0x1ca08c: 0xa2820000  sb          $v0, 0x0($s4) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca088) {
            ctx->pc = 0x1CA2DCu;
            goto label_1ca2dc;
        }
    }
    ctx->pc = 0x1CA090u;
label_1ca090:
    // 0x1ca090: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca090u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca094: 0x2402000d  addiu       $v0, $zero, 0xD
    ctx->pc = 0x1ca094u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1ca098: 0x8424b680  lh          $a0, -0x4980($at)
    ctx->pc = 0x1ca098u;
    SET_GPR_S32(ctx, 4, (int16_t)READ16(ADD32(GPR_U32(ctx, 1), 4294948480)));
    // 0x1ca09c: 0x10820071  beq         $a0, $v0, . + 4 + (0x71 << 2)
    ctx->pc = 0x1CA09Cu;
    {
        const bool branch_taken_0x1ca09c = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CA0A0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA09Cu;
            // 0x1ca0a0: 0x2403fffe  addiu       $v1, $zero, -0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca09c) {
            ctx->pc = 0x1CA264u;
            goto label_1ca264;
        }
    }
    ctx->pc = 0x1CA0A4u;
    // 0x1ca0a4: 0x24020006  addiu       $v0, $zero, 0x6
    ctx->pc = 0x1ca0a4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
    // 0x1ca0a8: 0x10820064  beq         $a0, $v0, . + 4 + (0x64 << 2)
    ctx->pc = 0x1CA0A8u;
    {
        const bool branch_taken_0x1ca0a8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CA0ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA0A8u;
            // 0x1ca0ac: 0x2403ffab  addiu       $v1, $zero, -0x55 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967211));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca0a8) {
            ctx->pc = 0x1CA23Cu;
            goto label_1ca23c;
        }
    }
    ctx->pc = 0x1CA0B0u;
    // 0x1ca0b0: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1ca0b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1ca0b4: 0x10820057  beq         $a0, $v0, . + 4 + (0x57 << 2)
    ctx->pc = 0x1CA0B4u;
    {
        const bool branch_taken_0x1ca0b4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CA0B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA0B4u;
            // 0x1ca0b8: 0x2403fffb  addiu       $v1, $zero, -0x5 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967291));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca0b4) {
            ctx->pc = 0x1CA214u;
            goto label_1ca214;
        }
    }
    ctx->pc = 0x1CA0BCu;
    // 0x1ca0bc: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1ca0bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1ca0c0: 0x10820043  beq         $a0, $v0, . + 4 + (0x43 << 2)
    ctx->pc = 0x1CA0C0u;
    {
        const bool branch_taken_0x1ca0c0 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CA0C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA0C0u;
            // 0x1ca0c4: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca0c0) {
            ctx->pc = 0x1CA1D0u;
            goto label_1ca1d0;
        }
    }
    ctx->pc = 0x1CA0C8u;
    // 0x1ca0c8: 0x1082002d  beq         $a0, $v0, . + 4 + (0x2D << 2)
    ctx->pc = 0x1CA0C8u;
    {
        const bool branch_taken_0x1ca0c8 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        if (branch_taken_0x1ca0c8) {
            ctx->pc = 0x1CA180u;
            goto label_1ca180;
        }
    }
    ctx->pc = 0x1CA0D0u;
    // 0x1ca0d0: 0x2402000c  addiu       $v0, $zero, 0xC
    ctx->pc = 0x1ca0d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
    // 0x1ca0d4: 0x10820016  beq         $a0, $v0, . + 4 + (0x16 << 2)
    ctx->pc = 0x1CA0D4u;
    {
        const bool branch_taken_0x1ca0d4 = (GPR_U64(ctx, 4) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CA0D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA0D4u;
            // 0x1ca0d8: 0x24030002  addiu       $v1, $zero, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca0d4) {
            ctx->pc = 0x1CA130u;
            goto label_1ca130;
        }
    }
    ctx->pc = 0x1CA0DCu;
    // 0x1ca0dc: 0x10830003  beq         $a0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CA0DCu;
    {
        const bool branch_taken_0x1ca0dc = (GPR_U64(ctx, 4) == GPR_U64(ctx, 3));
        if (branch_taken_0x1ca0dc) {
            ctx->pc = 0x1CA0ECu;
            goto label_1ca0ec;
        }
    }
    ctx->pc = 0x1CA0E4u;
    // 0x1ca0e4: 0x10000069  b           . + 4 + (0x69 << 2)
    ctx->pc = 0x1CA0E4u;
    {
        const bool branch_taken_0x1ca0e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA0E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA0E4u;
            // 0x1ca0e8: 0x2402ffae  addiu       $v0, $zero, -0x52 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca0e4) {
            ctx->pc = 0x1CA28Cu;
            goto label_1ca28c;
        }
    }
    ctx->pc = 0x1CA0ECu;
label_1ca0ec:
    // 0x1ca0ec: 0xc0725dc  jal         func_1C9770
    ctx->pc = 0x1CA0ECu;
    SET_GPR_U32(ctx, 31, 0x1CA0F4u);
    ctx->pc = 0x1C9770u;
    if (runtime->hasFunction(0x1C9770u)) {
        auto targetFn = runtime->lookupFunction(0x1C9770u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA0F4u; }
        if (ctx->pc != 0x1CA0F4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C9770_0x1c9770(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA0F4u; }
        if (ctx->pc != 0x1CA0F4u) { return; }
    }
    ctx->pc = 0x1CA0F4u;
label_1ca0f4:
    // 0x1ca0f4: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1CA0F4u;
    {
        const bool branch_taken_0x1ca0f4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CA0F8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA0F4u;
            // 0x1ca0f8: 0x2403fffd  addiu       $v1, $zero, -0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967293));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca0f4) {
            ctx->pc = 0x1CA108u;
            goto label_1ca108;
        }
    }
    ctx->pc = 0x1CA0FCu;
    // 0x1ca0fc: 0x24020063  addiu       $v0, $zero, 0x63
    ctx->pc = 0x1ca0fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1ca100: 0x1000006a  b           . + 4 + (0x6A << 2)
    ctx->pc = 0x1CA100u;
    {
        const bool branch_taken_0x1ca100 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA104u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA100u;
            // 0x1ca104: 0xa2820000  sb          $v0, 0x0($s4) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca100) {
            ctx->pc = 0x1CA2ACu;
            goto label_1ca2ac;
        }
    }
    ctx->pc = 0x1CA108u;
label_1ca108:
    // 0x1ca108: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1ca108u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca10c: 0xa2e30000  sb          $v1, 0x0($s7)
    ctx->pc = 0x1ca10cu;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca110: 0xa2c20000  sb          $v0, 0x0($s6)
    ctx->pc = 0x1ca110u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca114: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca114u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca118: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1ca118u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca11c: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca11cu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca120: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca120u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca124: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1ca124u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca128: 0x10000060  b           . + 4 + (0x60 << 2)
    ctx->pc = 0x1CA128u;
    {
        const bool branch_taken_0x1ca128 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA12Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA128u;
            // 0x1ca12c: 0xa6a00000  sh          $zero, 0x0($s5) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca128) {
            ctx->pc = 0x1CA2ACu;
            goto label_1ca2ac;
        }
    }
    ctx->pc = 0x1CA130u;
label_1ca130:
    // 0x1ca130: 0x86a20000  lh          $v0, 0x0($s5)
    ctx->pc = 0x1ca130u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1ca134: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1ca134u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1ca138: 0xa6a20000  sh          $v0, 0x0($s5)
    ctx->pc = 0x1ca138u;
    WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1ca13c: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1ca13cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1ca140: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1ca140u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1ca144: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1CA144u;
    {
        const bool branch_taken_0x1ca144 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CA148u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA144u;
            // 0x1ca148: 0x24020063  addiu       $v0, $zero, 0x63 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca144) {
            ctx->pc = 0x1CA178u;
            goto label_1ca178;
        }
    }
    ctx->pc = 0x1CA14Cu;
    // 0x1ca14c: 0x2403fffe  addiu       $v1, $zero, -0x2
    ctx->pc = 0x1ca14cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967294));
    // 0x1ca150: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1ca150u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca154: 0xa2e30000  sb          $v1, 0x0($s7)
    ctx->pc = 0x1ca154u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca158: 0xa2c20000  sb          $v0, 0x0($s6)
    ctx->pc = 0x1ca158u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca15c: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca15cu;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca160: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1ca160u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca164: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca164u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca168: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca168u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca16c: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1ca16cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca170: 0x1000004e  b           . + 4 + (0x4E << 2)
    ctx->pc = 0x1CA170u;
    {
        const bool branch_taken_0x1ca170 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA174u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA170u;
            // 0x1ca174: 0xa6a00000  sh          $zero, 0x0($s5) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca170) {
            ctx->pc = 0x1CA2ACu;
            goto label_1ca2ac;
        }
    }
    ctx->pc = 0x1CA178u;
label_1ca178:
    // 0x1ca178: 0x1000004c  b           . + 4 + (0x4C << 2)
    ctx->pc = 0x1CA178u;
    {
        const bool branch_taken_0x1ca178 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA17Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA178u;
            // 0x1ca17c: 0xa2820000  sb          $v0, 0x0($s4) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca178) {
            ctx->pc = 0x1CA2ACu;
            goto label_1ca2ac;
        }
    }
    ctx->pc = 0x1CA180u;
label_1ca180:
    // 0x1ca180: 0x86020000  lh          $v0, 0x0($s0)
    ctx->pc = 0x1ca180u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 16), 0)));
    // 0x1ca184: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1ca184u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1ca188: 0xa6020000  sh          $v0, 0x0($s0)
    ctx->pc = 0x1ca188u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1ca18c: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1ca18cu;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1ca190: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1ca190u;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1ca194: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1CA194u;
    {
        const bool branch_taken_0x1ca194 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CA198u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA194u;
            // 0x1ca198: 0x24020063  addiu       $v0, $zero, 0x63 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca194) {
            ctx->pc = 0x1CA1C8u;
            goto label_1ca1c8;
        }
    }
    ctx->pc = 0x1CA19Cu;
    // 0x1ca19c: 0x2403ffae  addiu       $v1, $zero, -0x52
    ctx->pc = 0x1ca19cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1ca1a0: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1ca1a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca1a4: 0xa2e30000  sb          $v1, 0x0($s7)
    ctx->pc = 0x1ca1a4u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca1a8: 0xa2c20000  sb          $v0, 0x0($s6)
    ctx->pc = 0x1ca1a8u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca1ac: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca1acu;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca1b0: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1ca1b0u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca1b4: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca1b4u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca1b8: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca1b8u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca1bc: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1ca1bcu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca1c0: 0x1000003a  b           . + 4 + (0x3A << 2)
    ctx->pc = 0x1CA1C0u;
    {
        const bool branch_taken_0x1ca1c0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA1C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA1C0u;
            // 0x1ca1c4: 0xa6a00000  sh          $zero, 0x0($s5) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca1c0) {
            ctx->pc = 0x1CA2ACu;
            goto label_1ca2ac;
        }
    }
    ctx->pc = 0x1CA1C8u;
label_1ca1c8:
    // 0x1ca1c8: 0x10000038  b           . + 4 + (0x38 << 2)
    ctx->pc = 0x1CA1C8u;
    {
        const bool branch_taken_0x1ca1c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA1CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA1C8u;
            // 0x1ca1cc: 0xa2820000  sb          $v0, 0x0($s4) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca1c8) {
            ctx->pc = 0x1CA2ACu;
            goto label_1ca2ac;
        }
    }
    ctx->pc = 0x1CA1D0u;
label_1ca1d0:
    // 0x1ca1d0: 0xc0725fc  jal         func_1C97F0
    ctx->pc = 0x1CA1D0u;
    SET_GPR_U32(ctx, 31, 0x1CA1D8u);
    ctx->pc = 0x1C97F0u;
    goto label_1c97f0;
    ctx->pc = 0x1CA1D8u;
label_1ca1d8:
    // 0x1ca1d8: 0x14400004  bnez        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1CA1D8u;
    {
        const bool branch_taken_0x1ca1d8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CA1DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA1D8u;
            // 0x1ca1dc: 0x2403ffae  addiu       $v1, $zero, -0x52 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca1d8) {
            ctx->pc = 0x1CA1ECu;
            goto label_1ca1ec;
        }
    }
    ctx->pc = 0x1CA1E0u;
    // 0x1ca1e0: 0x24020063  addiu       $v0, $zero, 0x63
    ctx->pc = 0x1ca1e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1ca1e4: 0x10000031  b           . + 4 + (0x31 << 2)
    ctx->pc = 0x1CA1E4u;
    {
        const bool branch_taken_0x1ca1e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA1E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA1E4u;
            // 0x1ca1e8: 0xa2820000  sb          $v0, 0x0($s4) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca1e4) {
            ctx->pc = 0x1CA2ACu;
            goto label_1ca2ac;
        }
    }
    ctx->pc = 0x1CA1ECu;
label_1ca1ec:
    // 0x1ca1ec: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1ca1ecu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca1f0: 0xa2e30000  sb          $v1, 0x0($s7)
    ctx->pc = 0x1ca1f0u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca1f4: 0xa2c20000  sb          $v0, 0x0($s6)
    ctx->pc = 0x1ca1f4u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca1f8: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca1f8u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca1fc: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1ca1fcu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca200: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca200u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca204: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca204u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca208: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1ca208u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca20c: 0x10000027  b           . + 4 + (0x27 << 2)
    ctx->pc = 0x1CA20Cu;
    {
        const bool branch_taken_0x1ca20c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA210u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA20Cu;
            // 0x1ca210: 0xa6a00000  sh          $zero, 0x0($s5) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca20c) {
            ctx->pc = 0x1CA2ACu;
            goto label_1ca2ac;
        }
    }
    ctx->pc = 0x1CA214u;
label_1ca214:
    // 0x1ca214: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1ca214u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca218: 0xa2e30000  sb          $v1, 0x0($s7)
    ctx->pc = 0x1ca218u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca21c: 0xa2c20000  sb          $v0, 0x0($s6)
    ctx->pc = 0x1ca21cu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca220: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca220u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca224: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1ca224u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca228: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca228u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca22c: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca22cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca230: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1ca230u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca234: 0x1000001d  b           . + 4 + (0x1D << 2)
    ctx->pc = 0x1CA234u;
    {
        const bool branch_taken_0x1ca234 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA238u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA234u;
            // 0x1ca238: 0xa6a00000  sh          $zero, 0x0($s5) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca234) {
            ctx->pc = 0x1CA2ACu;
            goto label_1ca2ac;
        }
    }
    ctx->pc = 0x1CA23Cu;
label_1ca23c:
    // 0x1ca23c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1ca23cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca240: 0xa2e30000  sb          $v1, 0x0($s7)
    ctx->pc = 0x1ca240u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca244: 0xa2c20000  sb          $v0, 0x0($s6)
    ctx->pc = 0x1ca244u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca248: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca248u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca24c: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1ca24cu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca250: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca250u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca254: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca254u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca258: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1ca258u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca25c: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1CA25Cu;
    {
        const bool branch_taken_0x1ca25c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA260u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA25Cu;
            // 0x1ca260: 0xa6a00000  sh          $zero, 0x0($s5) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca25c) {
            ctx->pc = 0x1CA2ACu;
            goto label_1ca2ac;
        }
    }
    ctx->pc = 0x1CA264u;
label_1ca264:
    // 0x1ca264: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1ca264u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca268: 0xa2e30000  sb          $v1, 0x0($s7)
    ctx->pc = 0x1ca268u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca26c: 0xa2c20000  sb          $v0, 0x0($s6)
    ctx->pc = 0x1ca26cu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca270: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca270u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca274: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1ca274u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca278: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca278u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca27c: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca27cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca280: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1ca280u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca284: 0x10000009  b           . + 4 + (0x9 << 2)
    ctx->pc = 0x1CA284u;
    {
        const bool branch_taken_0x1ca284 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA288u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA284u;
            // 0x1ca288: 0xa6a00000  sh          $zero, 0x0($s5) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca284) {
            ctx->pc = 0x1CA2ACu;
            goto label_1ca2ac;
        }
    }
    ctx->pc = 0x1CA28Cu;
label_1ca28c:
    // 0x1ca28c: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1ca28cu;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca290: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1ca290u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca294: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca294u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca298: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1ca298u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca29c: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca29cu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca2a0: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca2a0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca2a4: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1ca2a4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca2a8: 0xa6a00000  sh          $zero, 0x0($s5)
    ctx->pc = 0x1ca2a8u;
    WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 0));
label_1ca2ac:
    // 0x1ca2ac: 0x10000044  b           . + 4 + (0x44 << 2)
    ctx->pc = 0x1CA2ACu;
    {
        const bool branch_taken_0x1ca2ac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA2B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA2ACu;
            // 0x1ca2b0: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca2ac) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1CA2B4u;
    // 0x1ca2b4: 0x2403ffae  addiu       $v1, $zero, -0x52
    ctx->pc = 0x1ca2b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
label_1ca2b8:
    // 0x1ca2b8: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1ca2b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca2bc: 0xa2e30000  sb          $v1, 0x0($s7)
    ctx->pc = 0x1ca2bcu;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca2c0: 0xa2c20000  sb          $v0, 0x0($s6)
    ctx->pc = 0x1ca2c0u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca2c4: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca2c4u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca2c8: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1ca2c8u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca2cc: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca2ccu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca2d0: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca2d0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca2d4: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1ca2d4u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca2d8: 0xa6a00000  sh          $zero, 0x0($s5)
    ctx->pc = 0x1ca2d8u;
    WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 0));
label_1ca2dc:
    // 0x1ca2dc: 0x2403001d  addiu       $v1, $zero, 0x1D
    ctx->pc = 0x1ca2dcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 29));
label_1ca2e0:
    // 0x1ca2e0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca2e0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca2e4: 0x10000036  b           . + 4 + (0x36 << 2)
    ctx->pc = 0x1CA2E4u;
    {
        const bool branch_taken_0x1ca2e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA2E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA2E4u;
            // 0x1ca2e8: 0xa6430000  sh          $v1, 0x0($s2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca2e4) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1CA2ECu;
label_1ca2ec:
    // 0x1ca2ec: 0xa024c6ee  sb          $a0, -0x3912($at)
    ctx->pc = 0x1ca2ecu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 4));
    // 0x1ca2f0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca2f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca2f4: 0xa024c6ec  sb          $a0, -0x3914($at)
    ctx->pc = 0x1ca2f4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 4));
    // 0x1ca2f8: 0x82820000  lb          $v0, 0x0($s4)
    ctx->pc = 0x1ca2f8u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x1ca2fc: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1ca2fcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1ca300: 0xc0725f4  jal         func_1C97D0
    ctx->pc = 0x1CA300u;
    SET_GPR_U32(ctx, 31, 0x1CA308u);
    ctx->pc = 0x1CA304u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA300u;
            // 0x1ca304: 0xa2820000  sb          $v0, 0x0($s4) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C97D0u;
    if (runtime->hasFunction(0x1C97D0u)) {
        auto targetFn = runtime->lookupFunction(0x1C97D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA308u; }
        if (ctx->pc != 0x1CA308u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C97D0_0x1c97d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA308u; }
        if (ctx->pc != 0x1CA308u) { return; }
    }
    ctx->pc = 0x1CA308u;
label_1ca308:
    // 0x1ca308: 0xc07254c  jal         func_1C9530
    ctx->pc = 0x1CA308u;
    SET_GPR_U32(ctx, 31, 0x1CA310u);
    ctx->pc = 0x1C9530u;
    if (runtime->hasFunction(0x1C9530u)) {
        auto targetFn = runtime->lookupFunction(0x1C9530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA310u; }
        if (ctx->pc != 0x1CA310u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C9530_0x1c9530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA310u; }
        if (ctx->pc != 0x1CA310u) { return; }
    }
    ctx->pc = 0x1CA310u;
label_1ca310:
    // 0x1ca310: 0xc075c00  jal         func_1D7000
    ctx->pc = 0x1CA310u;
    SET_GPR_U32(ctx, 31, 0x1CA318u);
    ctx->pc = 0x1CA314u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA310u;
            // 0x1ca314: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7000u;
    if (runtime->hasFunction(0x1D7000u)) {
        auto targetFn = runtime->lookupFunction(0x1D7000u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA318u; }
        if (ctx->pc != 0x1CA318u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7000_0x1d7000(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA318u; }
        if (ctx->pc != 0x1CA318u) { return; }
    }
    ctx->pc = 0x1CA318u;
label_1ca318:
    // 0x1ca318: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca318u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca31c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca31cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca320: 0x8c23b670  lw          $v1, -0x4990($at)
    ctx->pc = 0x1ca320u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294948464)));
    // 0x1ca324: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca324u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca328: 0x10000025  b           . + 4 + (0x25 << 2)
    ctx->pc = 0x1CA328u;
    {
        const bool branch_taken_0x1ca328 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA32Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA328u;
            // 0x1ca32c: 0xac23c810  sw          $v1, -0x37F0($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294952976), GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca328) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1CA330u;
label_1ca330:
    // 0x1ca330: 0x9022c6ed  lbu         $v0, -0x3913($at)
    ctx->pc = 0x1ca330u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952685)));
    // 0x1ca334: 0x14440009  bne         $v0, $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1CA334u;
    {
        const bool branch_taken_0x1ca334 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x1CA338u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA334u;
            // 0x1ca338: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca334) {
            ctx->pc = 0x1CA35Cu;
            goto label_1ca35c;
        }
    }
    ctx->pc = 0x1CA33Cu;
    // 0x1ca33c: 0xa2c00000  sb          $zero, 0x0($s6)
    ctx->pc = 0x1ca33cu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca340: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1ca340u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca344: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca344u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca348: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca348u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca34c: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca34cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca350: 0xa6000000  sh          $zero, 0x0($s0)
    ctx->pc = 0x1ca350u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca354: 0x1000001a  b           . + 4 + (0x1A << 2)
    ctx->pc = 0x1CA354u;
    {
        const bool branch_taken_0x1ca354 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA358u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA354u;
            // 0x1ca358: 0xa6a00000  sh          $zero, 0x0($s5) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 21), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca354) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1CA35Cu;
label_1ca35c:
    // 0x1ca35c: 0x10000018  b           . + 4 + (0x18 << 2)
    ctx->pc = 0x1CA35Cu;
    {
        const bool branch_taken_0x1ca35c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ca35c) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1CA364u;
label_1ca364:
    // 0x1ca364: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca364u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca368: 0xa2830000  sb          $v1, 0x0($s4)
    ctx->pc = 0x1ca368u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca36c: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1ca36cu;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca370: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1CA370u;
    {
        const bool branch_taken_0x1ca370 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA374u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA370u;
            // 0x1ca374: 0xa6400000  sh          $zero, 0x0($s2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca370) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1CA378u;
label_1ca378:
    // 0x1ca378: 0x260202d  daddu       $a0, $s3, $zero
    ctx->pc = 0x1ca378u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca37c: 0xc072c60  jal         func_1CB180
    ctx->pc = 0x1CA37Cu;
    SET_GPR_U32(ctx, 31, 0x1CA384u);
    ctx->pc = 0x1CA380u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA37Cu;
            // 0x1ca380: 0x240282d  daddu       $a1, $s2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CB180u;
    if (runtime->hasFunction(0x1CB180u)) {
        auto targetFn = runtime->lookupFunction(0x1CB180u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA384u; }
        if (ctx->pc != 0x1CA384u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CB180_0x1cb180(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA384u; }
        if (ctx->pc != 0x1CA384u) { return; }
    }
    ctx->pc = 0x1CA384u;
label_1ca384:
    // 0x1ca384: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CA384u;
    {
        const bool branch_taken_0x1ca384 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA388u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA384u;
            // 0x1ca388: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca384) {
            ctx->pc = 0x1CA3BCu;
            goto label_1ca3bc;
        }
    }
    ctx->pc = 0x1CA38Cu;
    // 0x1ca38c: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x1ca38cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1ca390: 0xa020c6ec  sb          $zero, -0x3914($at)
    ctx->pc = 0x1ca390u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca394: 0x2403005a  addiu       $v1, $zero, 0x5A
    ctx->pc = 0x1ca394u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 90));
    // 0x1ca398: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca398u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca39c: 0xa022c6ee  sb          $v0, -0x3912($at)
    ctx->pc = 0x1ca39cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca3a0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ca3a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ca3a4: 0xa2820000  sb          $v0, 0x0($s4)
    ctx->pc = 0x1ca3a4u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca3a8: 0xa2600000  sb          $zero, 0x0($s3)
    ctx->pc = 0x1ca3a8u;
    WRITE8(ADD32(GPR_U32(ctx, 19), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca3ac: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1ca3acu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1ca3b0: 0xa6430000  sh          $v1, 0x0($s2)
    ctx->pc = 0x1ca3b0u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1ca3b4: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1CA3B4u;
    {
        const bool branch_taken_0x1ca3b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA3B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA3B4u;
            // 0x1ca3b8: 0xa6200000  sh          $zero, 0x0($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca3b4) {
            ctx->pc = 0x1CA3C0u;
            goto label_1ca3c0;
        }
    }
    ctx->pc = 0x1CA3BCu;
label_1ca3bc:
    // 0x1ca3bc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca3bcu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ca3c0:
    // 0x1ca3c0: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x1ca3c0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
label_1ca3c4:
    // 0x1ca3c4: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x1ca3c4u;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1ca3c8: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1ca3c8u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1ca3cc: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1ca3ccu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1ca3d0: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1ca3d0u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1ca3d4: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1ca3d4u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1ca3d8: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1ca3d8u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1ca3dc: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1ca3dcu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1ca3e0: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1ca3e0u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1ca3e4: 0x3e00008  jr          $ra
    ctx->pc = 0x1CA3E4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CA3E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA3E4u;
            // 0x1ca3e8: 0x27bd00a0  addiu       $sp, $sp, 0xA0 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 160));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C97F0u: goto label_1c97f0;
            case 0x1C982Cu: goto label_1c982c;
            case 0x1C9834u: goto label_1c9834;
            case 0x1C983Cu: goto label_1c983c;
            case 0x1C9844u: goto label_1c9844;
            case 0x1C984Cu: goto label_1c984c;
            case 0x1C98E8u: goto label_1c98e8;
            case 0x1C9924u: goto label_1c9924;
            case 0x1C999Cu: goto label_1c999c;
            case 0x1C99D4u: goto label_1c99d4;
            case 0x1C99F0u: goto label_1c99f0;
            case 0x1C9A74u: goto label_1c9a74;
            case 0x1C9A88u: goto label_1c9a88;
            case 0x1C9AECu: goto label_1c9aec;
            case 0x1C9AF4u: goto label_1c9af4;
            case 0x1C9B00u: goto label_1c9b00;
            case 0x1C9B04u: goto label_1c9b04;
            case 0x1C9B08u: goto label_1c9b08;
            case 0x1C9B10u: goto label_1c9b10;
            case 0x1C9B28u: goto label_1c9b28;
            case 0x1C9C4Cu: goto label_1c9c4c;
            case 0x1C9C64u: goto label_1c9c64;
            case 0x1C9C78u: goto label_1c9c78;
            case 0x1C9C90u: goto label_1c9c90;
            case 0x1C9CACu: goto label_1c9cac;
            case 0x1C9CCCu: goto label_1c9ccc;
            case 0x1C9D04u: goto label_1c9d04;
            case 0x1C9D18u: goto label_1c9d18;
            case 0x1C9D20u: goto label_1c9d20;
            case 0x1C9D58u: goto label_1c9d58;
            case 0x1C9D68u: goto label_1c9d68;
            case 0x1C9D80u: goto label_1c9d80;
            case 0x1C9DA4u: goto label_1c9da4;
            case 0x1C9DACu: goto label_1c9dac;
            case 0x1C9DFCu: goto label_1c9dfc;
            case 0x1C9E08u: goto label_1c9e08;
            case 0x1C9E40u: goto label_1c9e40;
            case 0x1C9E50u: goto label_1c9e50;
            case 0x1C9E6Cu: goto label_1c9e6c;
            case 0x1C9EACu: goto label_1c9eac;
            case 0x1C9EC0u: goto label_1c9ec0;
            case 0x1C9EFCu: goto label_1c9efc;
            case 0x1C9F38u: goto label_1c9f38;
            case 0x1C9F40u: goto label_1c9f40;
            case 0x1C9F5Cu: goto label_1c9f5c;
            case 0x1C9F6Cu: goto label_1c9f6c;
            case 0x1C9FA4u: goto label_1c9fa4;
            case 0x1C9FD0u: goto label_1c9fd0;
            case 0x1CA000u: goto label_1ca000;
            case 0x1CA02Cu: goto label_1ca02c;
            case 0x1CA058u: goto label_1ca058;
            case 0x1CA080u: goto label_1ca080;
            case 0x1CA090u: goto label_1ca090;
            case 0x1CA0ECu: goto label_1ca0ec;
            case 0x1CA0F4u: goto label_1ca0f4;
            case 0x1CA108u: goto label_1ca108;
            case 0x1CA130u: goto label_1ca130;
            case 0x1CA178u: goto label_1ca178;
            case 0x1CA180u: goto label_1ca180;
            case 0x1CA1C8u: goto label_1ca1c8;
            case 0x1CA1D0u: goto label_1ca1d0;
            case 0x1CA1D8u: goto label_1ca1d8;
            case 0x1CA1ECu: goto label_1ca1ec;
            case 0x1CA214u: goto label_1ca214;
            case 0x1CA23Cu: goto label_1ca23c;
            case 0x1CA264u: goto label_1ca264;
            case 0x1CA28Cu: goto label_1ca28c;
            case 0x1CA2ACu: goto label_1ca2ac;
            case 0x1CA2B8u: goto label_1ca2b8;
            case 0x1CA2DCu: goto label_1ca2dc;
            case 0x1CA2E0u: goto label_1ca2e0;
            case 0x1CA2ECu: goto label_1ca2ec;
            case 0x1CA308u: goto label_1ca308;
            case 0x1CA310u: goto label_1ca310;
            case 0x1CA318u: goto label_1ca318;
            case 0x1CA330u: goto label_1ca330;
            case 0x1CA35Cu: goto label_1ca35c;
            case 0x1CA364u: goto label_1ca364;
            case 0x1CA378u: goto label_1ca378;
            case 0x1CA384u: goto label_1ca384;
            case 0x1CA3BCu: goto label_1ca3bc;
            case 0x1CA3C0u: goto label_1ca3c0;
            case 0x1CA3C4u: goto label_1ca3c4;
            case 0x1CA43Cu: goto label_1ca43c;
            case 0x1CA474u: goto label_1ca474;
            case 0x1CA490u: goto label_1ca490;
            case 0x1CA558u: goto label_1ca558;
            case 0x1CA57Cu: goto label_1ca57c;
            case 0x1CA598u: goto label_1ca598;
            case 0x1CA5C0u: goto label_1ca5c0;
            case 0x1CA5D8u: goto label_1ca5d8;
            case 0x1CA610u: goto label_1ca610;
            case 0x1CA624u: goto label_1ca624;
            case 0x1CA630u: goto label_1ca630;
            case 0x1CA668u: goto label_1ca668;
            case 0x1CA688u: goto label_1ca688;
            case 0x1CA690u: goto label_1ca690;
            case 0x1CA694u: goto label_1ca694;
            case 0x1CA698u: goto label_1ca698;
            case 0x1CA6A0u: goto label_1ca6a0;
            case 0x1CA6C0u: goto label_1ca6c0;
            case 0x1CA6ECu: goto label_1ca6ec;
            case 0x1CA724u: goto label_1ca724;
            case 0x1CA738u: goto label_1ca738;
            case 0x1CA740u: goto label_1ca740;
            case 0x1CA778u: goto label_1ca778;
            case 0x1CA790u: goto label_1ca790;
            case 0x1CA7D0u: goto label_1ca7d0;
            case 0x1CA808u: goto label_1ca808;
            case 0x1CA810u: goto label_1ca810;
            case 0x1CA820u: goto label_1ca820;
            case 0x1CA84Cu: goto label_1ca84c;
            case 0x1CA86Cu: goto label_1ca86c;
            case 0x1CA8B8u: goto label_1ca8b8;
            case 0x1CA8C8u: goto label_1ca8c8;
            case 0x1CA8CCu: goto label_1ca8cc;
            case 0x1CA8D4u: goto label_1ca8d4;
            case 0x1CA914u: goto label_1ca914;
            case 0x1CA94Cu: goto label_1ca94c;
            case 0x1CA954u: goto label_1ca954;
            case 0x1CA970u: goto label_1ca970;
            case 0x1CA99Cu: goto label_1ca99c;
            case 0x1CA9A4u: goto label_1ca9a4;
            case 0x1CA9B4u: goto label_1ca9b4;
            case 0x1CA9ECu: goto label_1ca9ec;
            case 0x1CA9F8u: goto label_1ca9f8;
            case 0x1CAA18u: goto label_1caa18;
            case 0x1CAA24u: goto label_1caa24;
            case 0x1CAA5Cu: goto label_1caa5c;
            case 0x1CAA74u: goto label_1caa74;
            case 0x1CAAB4u: goto label_1caab4;
            case 0x1CAAECu: goto label_1caaec;
            case 0x1CAAF4u: goto label_1caaf4;
            case 0x1CAB04u: goto label_1cab04;
            case 0x1CAB30u: goto label_1cab30;
            case 0x1CAB48u: goto label_1cab48;
            case 0x1CAB94u: goto label_1cab94;
            case 0x1CABA4u: goto label_1caba4;
            case 0x1CABA8u: goto label_1caba8;
            case 0x1CABB0u: goto label_1cabb0;
            case 0x1CABB8u: goto label_1cabb8;
            case 0x1CABF0u: goto label_1cabf0;
            case 0x1CABF8u: goto label_1cabf8;
            case 0x1CAC30u: goto label_1cac30;
            case 0x1CAC48u: goto label_1cac48;
            case 0x1CAC60u: goto label_1cac60;
            case 0x1CAC90u: goto label_1cac90;
            case 0x1CACC8u: goto label_1cacc8;
            case 0x1CACD0u: goto label_1cacd0;
            case 0x1CACE0u: goto label_1cace0;
            case 0x1CAD00u: goto label_1cad00;
            case 0x1CAD2Cu: goto label_1cad2c;
            case 0x1CAD34u: goto label_1cad34;
            case 0x1CAD48u: goto label_1cad48;
            case 0x1CAD50u: goto label_1cad50;
            case 0x1CAD60u: goto label_1cad60;
            case 0x1CAD88u: goto label_1cad88;
            case 0x1CAD90u: goto label_1cad90;
            case 0x1CADBCu: goto label_1cadbc;
            case 0x1CADD4u: goto label_1cadd4;
            case 0x1CADDCu: goto label_1caddc;
            case 0x1CAE14u: goto label_1cae14;
            case 0x1CAE1Cu: goto label_1cae1c;
            case 0x1CAE44u: goto label_1cae44;
            case 0x1CAE70u: goto label_1cae70;
            case 0x1CAE78u: goto label_1cae78;
            case 0x1CAE84u: goto label_1cae84;
            case 0x1CAEBCu: goto label_1caebc;
            case 0x1CAED8u: goto label_1caed8;
            case 0x1CAF10u: goto label_1caf10;
            case 0x1CAF1Cu: goto label_1caf1c;
            case 0x1CAF24u: goto label_1caf24;
            case 0x1CAF38u: goto label_1caf38;
            case 0x1CAF4Cu: goto label_1caf4c;
            case 0x1CAF7Cu: goto label_1caf7c;
            case 0x1CAFB4u: goto label_1cafb4;
            case 0x1CAFE0u: goto label_1cafe0;
            case 0x1CAFE8u: goto label_1cafe8;
            case 0x1CB000u: goto label_1cb000;
            case 0x1CB00Cu: goto label_1cb00c;
            case 0x1CB044u: goto label_1cb044;
            case 0x1CB048u: goto label_1cb048;
            case 0x1CB04Cu: goto label_1cb04c;
            case 0x1CB0DCu: goto label_1cb0dc;
            case 0x1CB104u: goto label_1cb104;
            case 0x1CB11Cu: goto label_1cb11c;
            case 0x1CB124u: goto label_1cb124;
            case 0x1CB150u: goto label_1cb150;
            case 0x1CB154u: goto label_1cb154;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CA3ECu;
    // 0x1ca3ec: 0x0  nop
    ctx->pc = 0x1ca3ecu;
    // NOP
    // 0x1ca3f0: 0x27bdff70  addiu       $sp, $sp, -0x90
    ctx->pc = 0x1ca3f0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967152));
    // 0x1ca3f4: 0xffbf0080  sd          $ra, 0x80($sp)
    ctx->pc = 0x1ca3f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 128), GPR_U64(ctx, 31));
    // 0x1ca3f8: 0x7fb70070  sq          $s7, 0x70($sp)
    ctx->pc = 0x1ca3f8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 112), GPR_VEC(ctx, 23));
    // 0x1ca3fc: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1ca3fcu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1ca400: 0x160b82d  daddu       $s7, $t3, $zero
    ctx->pc = 0x1ca400u;
    SET_GPR_U64(ctx, 23, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca404: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1ca404u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1ca408: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x1ca408u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca40c: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1ca40cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1ca410: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x1ca410u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca414: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1ca414u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1ca418: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x1ca418u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca41c: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1ca41cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1ca420: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x1ca420u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca424: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1ca424u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1ca428: 0x100902d  daddu       $s2, $t0, $zero
    ctx->pc = 0x1ca428u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca42c: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1ca42cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1ca430: 0x120882d  daddu       $s1, $t1, $zero
    ctx->pc = 0x1ca430u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca434: 0xc0725ac  jal         func_1C96B0
    ctx->pc = 0x1CA434u;
    SET_GPR_U32(ctx, 31, 0x1CA43Cu);
    ctx->pc = 0x1CA438u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA434u;
            // 0x1ca438: 0x140802d  daddu       $s0, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1C96B0u;
    if (runtime->hasFunction(0x1C96B0u)) {
        auto targetFn = runtime->lookupFunction(0x1C96B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA43Cu; }
        if (ctx->pc != 0x1CA43Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C96B0_0x1c96b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA43Cu; }
        if (ctx->pc != 0x1CA43Cu) { return; }
    }
    ctx->pc = 0x1CA43Cu;
label_1ca43c:
    // 0x1ca43c: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CA43Cu;
    {
        const bool branch_taken_0x1ca43c = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1CA440u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA43Cu;
            // 0x1ca440: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca43c) {
            ctx->pc = 0x1CA474u;
            goto label_1ca474;
        }
    }
    ctx->pc = 0x1CA444u;
    // 0x1ca444: 0x2402ffaf  addiu       $v0, $zero, -0x51
    ctx->pc = 0x1ca444u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967215));
    // 0x1ca448: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1ca448u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca44c: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1ca44cu;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca450: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1ca450u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca454: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca454u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca458: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1ca458u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca45c: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca45cu;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca460: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca460u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca464: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca464u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca468: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca468u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca46c: 0x100002f6  b           . + 4 + (0x2F6 << 2)
    ctx->pc = 0x1CA46Cu;
    {
        const bool branch_taken_0x1ca46c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA470u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA46Cu;
            // 0x1ca470: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca46c) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA474u;
label_1ca474:
    // 0x1ca474: 0x9023c6ec  lbu         $v1, -0x3914($at)
    ctx->pc = 0x1ca474u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1ca478: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca478u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca47c: 0x9022c6ed  lbu         $v0, -0x3913($at)
    ctx->pc = 0x1ca47cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952685)));
    // 0x1ca480: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1ca480u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1ca484: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CA484u;
    {
        const bool branch_taken_0x1ca484 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ca484) {
            ctx->pc = 0x1CA490u;
            goto label_1ca490;
        }
    }
    ctx->pc = 0x1CA48Cu;
    // 0x1ca48c: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1ca48cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1ca490:
    // 0x1ca490: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca490u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca494: 0x24040064  addiu       $a0, $zero, 0x64
    ctx->pc = 0x1ca494u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1ca498: 0xa023c6ed  sb          $v1, -0x3913($at)
    ctx->pc = 0x1ca498u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952685), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca49c: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1ca49cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1ca4a0: 0x106402d7  beq         $v1, $a0, . + 4 + (0x2D7 << 2)
    ctx->pc = 0x1CA4A0u;
    {
        const bool branch_taken_0x1ca4a0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1CA4A4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA4A0u;
            // 0x1ca4a4: 0x24020063  addiu       $v0, $zero, 0x63 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca4a0) {
            ctx->pc = 0x1CB000u;
            goto label_1cb000;
        }
    }
    ctx->pc = 0x1CA4A8u;
    // 0x1ca4a8: 0x106202cf  beq         $v1, $v0, . + 4 + (0x2CF << 2)
    ctx->pc = 0x1CA4A8u;
    {
        const bool branch_taken_0x1ca4a8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1ca4a8) {
            ctx->pc = 0x1CAFE8u;
            goto label_1cafe8;
        }
    }
    ctx->pc = 0x1CA4B0u;
    // 0x1ca4b0: 0x2402001f  addiu       $v0, $zero, 0x1F
    ctx->pc = 0x1ca4b0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 31));
    // 0x1ca4b4: 0x106202bf  beq         $v1, $v0, . + 4 + (0x2BF << 2)
    ctx->pc = 0x1CA4B4u;
    {
        const bool branch_taken_0x1ca4b4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CA4B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA4B4u;
            // 0x1ca4b8: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca4b4) {
            ctx->pc = 0x1CAFB4u;
            goto label_1cafb4;
        }
    }
    ctx->pc = 0x1CA4BCu;
    // 0x1ca4bc: 0x2402001e  addiu       $v0, $zero, 0x1E
    ctx->pc = 0x1ca4bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
    // 0x1ca4c0: 0x10620296  beq         $v1, $v0, . + 4 + (0x296 << 2)
    ctx->pc = 0x1CA4C0u;
    {
        const bool branch_taken_0x1ca4c0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CA4C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA4C0u;
            // 0x1ca4c4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca4c0) {
            ctx->pc = 0x1CAF1Cu;
            goto label_1caf1c;
        }
    }
    ctx->pc = 0x1CA4C8u;
    // 0x1ca4c8: 0x24040018  addiu       $a0, $zero, 0x18
    ctx->pc = 0x1ca4c8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 24));
    // 0x1ca4cc: 0x10640243  beq         $v1, $a0, . + 4 + (0x243 << 2)
    ctx->pc = 0x1CA4CCu;
    {
        const bool branch_taken_0x1ca4cc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1CA4D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA4CCu;
            // 0x1ca4d0: 0x24040017  addiu       $a0, $zero, 0x17 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 23));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca4cc) {
            ctx->pc = 0x1CADDCu;
            goto label_1caddc;
        }
    }
    ctx->pc = 0x1CA4D4u;
    // 0x1ca4d4: 0x106401dc  beq         $v1, $a0, . + 4 + (0x1DC << 2)
    ctx->pc = 0x1CA4D4u;
    {
        const bool branch_taken_0x1ca4d4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1ca4d4) {
            ctx->pc = 0x1CAC48u;
            goto label_1cac48;
        }
    }
    ctx->pc = 0x1CA4DCu;
    // 0x1ca4dc: 0x24040016  addiu       $a0, $zero, 0x16
    ctx->pc = 0x1ca4dcu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 22));
    // 0x1ca4e0: 0x106401b3  beq         $v1, $a0, . + 4 + (0x1B3 << 2)
    ctx->pc = 0x1CA4E0u;
    {
        const bool branch_taken_0x1ca4e0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1CA4E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA4E0u;
            // 0x1ca4e4: 0x24040015  addiu       $a0, $zero, 0x15 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 21));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca4e0) {
            ctx->pc = 0x1CABB0u;
            goto label_1cabb0;
        }
    }
    ctx->pc = 0x1CA4E8u;
    // 0x1ca4e8: 0x10640162  beq         $v1, $a0, . + 4 + (0x162 << 2)
    ctx->pc = 0x1CA4E8u;
    {
        const bool branch_taken_0x1ca4e8 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1CA4ECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA4E8u;
            // 0x1ca4ec: 0x24050014  addiu       $a1, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca4e8) {
            ctx->pc = 0x1CAA74u;
            goto label_1caa74;
        }
    }
    ctx->pc = 0x1CA4F0u;
    // 0x1ca4f0: 0x10650141  beq         $v1, $a1, . + 4 + (0x141 << 2)
    ctx->pc = 0x1CA4F0u;
    {
        const bool branch_taken_0x1ca4f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 5));
        ctx->pc = 0x1CA4F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA4F0u;
            // 0x1ca4f4: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca4f0) {
            ctx->pc = 0x1CA9F8u;
            goto label_1ca9f8;
        }
    }
    ctx->pc = 0x1CA4F8u;
    // 0x1ca4f8: 0x2404000d  addiu       $a0, $zero, 0xD
    ctx->pc = 0x1ca4f8u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 13));
    // 0x1ca4fc: 0x106400f5  beq         $v1, $a0, . + 4 + (0xF5 << 2)
    ctx->pc = 0x1CA4FCu;
    {
        const bool branch_taken_0x1ca4fc = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1CA500u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA4FCu;
            // 0x1ca500: 0x2404000c  addiu       $a0, $zero, 0xC (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 12));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca4fc) {
            ctx->pc = 0x1CA8D4u;
            goto label_1ca8d4;
        }
    }
    ctx->pc = 0x1CA504u;
    // 0x1ca504: 0x106400a2  beq         $v1, $a0, . + 4 + (0xA2 << 2)
    ctx->pc = 0x1CA504u;
    {
        const bool branch_taken_0x1ca504 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        if (branch_taken_0x1ca504) {
            ctx->pc = 0x1CA790u;
            goto label_1ca790;
        }
    }
    ctx->pc = 0x1CA50Cu;
    // 0x1ca50c: 0x2402000b  addiu       $v0, $zero, 0xB
    ctx->pc = 0x1ca50cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
    // 0x1ca510: 0x10620089  beq         $v1, $v0, . + 4 + (0x89 << 2)
    ctx->pc = 0x1CA510u;
    {
        const bool branch_taken_0x1ca510 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CA514u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA510u;
            // 0x1ca514: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca510) {
            ctx->pc = 0x1CA738u;
            goto label_1ca738;
        }
    }
    ctx->pc = 0x1CA518u;
    // 0x1ca518: 0x2404000a  addiu       $a0, $zero, 0xA
    ctx->pc = 0x1ca518u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1ca51c: 0x10640060  beq         $v1, $a0, . + 4 + (0x60 << 2)
    ctx->pc = 0x1CA51Cu;
    {
        const bool branch_taken_0x1ca51c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 4));
        ctx->pc = 0x1CA520u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA51Cu;
            // 0x1ca520: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca51c) {
            ctx->pc = 0x1CA6A0u;
            goto label_1ca6a0;
        }
    }
    ctx->pc = 0x1CA524u;
    // 0x1ca524: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1ca524u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1ca528: 0x1062003e  beq         $v1, $v0, . + 4 + (0x3E << 2)
    ctx->pc = 0x1CA528u;
    {
        const bool branch_taken_0x1ca528 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CA52Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA528u;
            // 0x1ca52c: 0x24020006  addiu       $v0, $zero, 0x6 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 6));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca528) {
            ctx->pc = 0x1CA624u;
            goto label_1ca624;
        }
    }
    ctx->pc = 0x1CA530u;
    // 0x1ca530: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1ca530u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca534: 0x10620022  beq         $v1, $v0, . + 4 + (0x22 << 2)
    ctx->pc = 0x1CA534u;
    {
        const bool branch_taken_0x1ca534 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CA538u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA534u;
            // 0x1ca538: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca534) {
            ctx->pc = 0x1CA5C0u;
            goto label_1ca5c0;
        }
    }
    ctx->pc = 0x1CA53Cu;
    // 0x1ca53c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ca53cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ca540: 0x1062000e  beq         $v1, $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1CA540u;
    {
        const bool branch_taken_0x1ca540 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        if (branch_taken_0x1ca540) {
            ctx->pc = 0x1CA57Cu;
            goto label_1ca57c;
        }
    }
    ctx->pc = 0x1CA548u;
    // 0x1ca548: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CA548u;
    {
        const bool branch_taken_0x1ca548 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ca548) {
            ctx->pc = 0x1CA558u;
            goto label_1ca558;
        }
    }
    ctx->pc = 0x1CA550u;
    // 0x1ca550: 0x100002bd  b           . + 4 + (0x2BD << 2)
    ctx->pc = 0x1CA550u;
    {
        const bool branch_taken_0x1ca550 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA554u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA550u;
            // 0x1ca554: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca550) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA558u;
label_1ca558:
    // 0x1ca558: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1ca558u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ca55c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca55cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca560: 0xa2a30000  sb          $v1, 0x0($s5)
    ctx->pc = 0x1ca560u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca564: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca564u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca568: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca568u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca56c: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca56cu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca570: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca570u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca574: 0x100002b4  b           . + 4 + (0x2B4 << 2)
    ctx->pc = 0x1CA574u;
    {
        const bool branch_taken_0x1ca574 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA578u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA574u;
            // 0x1ca578: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca574) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA57Cu;
label_1ca57c:
    // 0x1ca57c: 0x86630000  lh          $v1, 0x0($s3)
    ctx->pc = 0x1ca57cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1ca580: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x1ca580u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1ca584: 0x3082a  slt         $at, $zero, $v1
    ctx->pc = 0x1ca584u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1ca588: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CA588u;
    {
        const bool branch_taken_0x1ca588 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA58Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA588u;
            // 0x1ca58c: 0xa6620000  sh          $v0, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca588) {
            ctx->pc = 0x1CA598u;
            goto label_1ca598;
        }
    }
    ctx->pc = 0x1CA590u;
    // 0x1ca590: 0x100002ad  b           . + 4 + (0x2AD << 2)
    ctx->pc = 0x1CA590u;
    {
        const bool branch_taken_0x1ca590 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA594u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA590u;
            // 0x1ca594: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca590) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA598u;
label_1ca598:
    // 0x1ca598: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca598u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca59c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca59cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca5a0: 0xa024c6ee  sb          $a0, -0x3912($at)
    ctx->pc = 0x1ca5a0u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 4));
    // 0x1ca5a4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca5a4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca5a8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca5a8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca5ac: 0xa020c6ec  sb          $zero, -0x3914($at)
    ctx->pc = 0x1ca5acu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca5b0: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1ca5b0u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1ca5b4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1ca5b4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ca5b8: 0x100002a3  b           . + 4 + (0x2A3 << 2)
    ctx->pc = 0x1CA5B8u;
    {
        const bool branch_taken_0x1ca5b8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA5BCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA5B8u;
            // 0x1ca5bc: 0xa2a30000  sb          $v1, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca5b8) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA5C0u;
label_1ca5c0:
    // 0x1ca5c0: 0xa022c6ec  sb          $v0, -0x3914($at)
    ctx->pc = 0x1ca5c0u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca5c4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca5c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca5c8: 0x8c22d158  lw          $v0, -0x2EA8($at)
    ctx->pc = 0x1ca5c8u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294955352)));
    // 0x1ca5cc: 0x8c450004  lw          $a1, 0x4($v0)
    ctx->pc = 0x1ca5ccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4)));
    // 0x1ca5d0: 0xc075a2c  jal         func_1D68B0
    ctx->pc = 0x1CA5D0u;
    SET_GPR_U32(ctx, 31, 0x1CA5D8u);
    ctx->pc = 0x1CA5D4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA5D0u;
            // 0x1ca5d4: 0x8c440000  lw          $a0, 0x0($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D68B0u;
    if (runtime->hasFunction(0x1D68B0u)) {
        auto targetFn = runtime->lookupFunction(0x1D68B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA5D8u; }
        if (ctx->pc != 0x1CA5D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D68B0_0x1d68b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA5D8u; }
        if (ctx->pc != 0x1CA5D8u) { return; }
    }
    ctx->pc = 0x1CA5D8u;
label_1ca5d8:
    // 0x1ca5d8: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CA5D8u;
    {
        const bool branch_taken_0x1ca5d8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1ca5d8) {
            ctx->pc = 0x1CA610u;
            goto label_1ca610;
        }
    }
    ctx->pc = 0x1CA5E0u;
    // 0x1ca5e0: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1ca5e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1ca5e4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1ca5e4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca5e8: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1ca5e8u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca5ec: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1ca5ecu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca5f0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca5f0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca5f4: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1ca5f4u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca5f8: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca5f8u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca5fc: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca5fcu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca600: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca600u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca604: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca604u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca608: 0x1000028f  b           . + 4 + (0x28F << 2)
    ctx->pc = 0x1CA608u;
    {
        const bool branch_taken_0x1ca608 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA60Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA608u;
            // 0x1ca60c: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca608) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA610u;
label_1ca610:
    // 0x1ca610: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1ca610u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1ca614: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca614u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca618: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1ca618u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ca61c: 0x1000028a  b           . + 4 + (0x28A << 2)
    ctx->pc = 0x1CA61Cu;
    {
        const bool branch_taken_0x1ca61c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA620u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA61Cu;
            // 0x1ca620: 0xa2a30000  sb          $v1, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca61c) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA624u;
label_1ca624:
    // 0x1ca624: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca624u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca628: 0xc075cb0  jal         func_1D72C0
    ctx->pc = 0x1CA628u;
    SET_GPR_U32(ctx, 31, 0x1CA630u);
    ctx->pc = 0x1CA62Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA628u;
            // 0x1ca62c: 0xa022c6ec  sb          $v0, -0x3914($at) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D72C0u;
    if (runtime->hasFunction(0x1D72C0u)) {
        auto targetFn = runtime->lookupFunction(0x1D72C0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA630u; }
        if (ctx->pc != 0x1CA630u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D72C0_0x1d72c0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA630u; }
        if (ctx->pc != 0x1CA630u) { return; }
    }
    ctx->pc = 0x1CA630u;
label_1ca630:
    // 0x1ca630: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CA630u;
    {
        const bool branch_taken_0x1ca630 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1CA634u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA630u;
            // 0x1ca634: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca630) {
            ctx->pc = 0x1CA668u;
            goto label_1ca668;
        }
    }
    ctx->pc = 0x1CA638u;
    // 0x1ca638: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1ca638u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1ca63c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1ca63cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca640: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1ca640u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca644: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1ca644u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca648: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca648u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca64c: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1ca64cu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca650: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca650u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca654: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca654u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca658: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca658u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca65c: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca65cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca660: 0x10000279  b           . + 4 + (0x279 << 2)
    ctx->pc = 0x1CA660u;
    {
        const bool branch_taken_0x1ca660 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA664u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA660u;
            // 0x1ca664: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca660) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA668u;
label_1ca668:
    // 0x1ca668: 0x8023cc48  lb          $v1, -0x33B8($at)
    ctx->pc = 0x1ca668u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294954056)));
    // 0x1ca66c: 0x10600008  beqz        $v1, . + 4 + (0x8 << 2)
    ctx->pc = 0x1CA66Cu;
    {
        const bool branch_taken_0x1ca66c = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA670u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA66Cu;
            // 0x1ca670: 0x2402000a  addiu       $v0, $zero, 0xA (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca66c) {
            ctx->pc = 0x1CA690u;
            goto label_1ca690;
        }
    }
    ctx->pc = 0x1CA674u;
    // 0x1ca674: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1ca674u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1ca678: 0x10620003  beq         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CA678u;
    {
        const bool branch_taken_0x1ca678 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CA67Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA678u;
            // 0x1ca67c: 0x24020014  addiu       $v0, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca678) {
            ctx->pc = 0x1CA688u;
            goto label_1ca688;
        }
    }
    ctx->pc = 0x1CA680u;
    // 0x1ca680: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1CA680u;
    {
        const bool branch_taken_0x1ca680 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA684u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA680u;
            // 0x1ca684: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca680) {
            ctx->pc = 0x1CA698u;
            goto label_1ca698;
        }
    }
    ctx->pc = 0x1CA688u;
label_1ca688:
    // 0x1ca688: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1CA688u;
    {
        const bool branch_taken_0x1ca688 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA68Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA688u;
            // 0x1ca68c: 0xa2a20000  sb          $v0, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca688) {
            ctx->pc = 0x1CA694u;
            goto label_1ca694;
        }
    }
    ctx->pc = 0x1CA690u;
label_1ca690:
    // 0x1ca690: 0xa2a20000  sb          $v0, 0x0($s5)
    ctx->pc = 0x1ca690u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
label_1ca694:
    // 0x1ca694: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca694u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ca698:
    // 0x1ca698: 0x1000026c  b           . + 4 + (0x26C << 2)
    ctx->pc = 0x1CA698u;
    {
        const bool branch_taken_0x1ca698 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA69Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA698u;
            // 0x1ca69c: 0xdfbf0080  ld          $ra, 0x80($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca698) {
            ctx->pc = 0x1CB04Cu;
            goto label_1cb04c;
        }
    }
    ctx->pc = 0x1CA6A0u;
label_1ca6a0:
    // 0x1ca6a0: 0xa025c6ee  sb          $a1, -0x3912($at)
    ctx->pc = 0x1ca6a0u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 5));
    // 0x1ca6a4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca6a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca6a8: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1ca6a8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1ca6ac: 0x2841000a  slti        $at, $v0, 0xA
    ctx->pc = 0x1ca6acu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)10) ? 1 : 0);
    // 0x1ca6b0: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CA6B0u;
    {
        const bool branch_taken_0x1ca6b0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ca6b0) {
            ctx->pc = 0x1CA6C0u;
            goto label_1ca6c0;
        }
    }
    ctx->pc = 0x1CA6B8u;
    // 0x1ca6b8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca6b8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca6bc: 0xa024c6ec  sb          $a0, -0x3914($at)
    ctx->pc = 0x1ca6bcu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 4));
label_1ca6c0:
    // 0x1ca6c0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca6c0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca6c4: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1ca6c4u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1ca6c8: 0x8c23c810  lw          $v1, -0x37F0($at)
    ctx->pc = 0x1ca6c8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952976)));
    // 0x1ca6cc: 0x2484b660  addiu       $a0, $a0, -0x49A0
    ctx->pc = 0x1ca6ccu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948448));
    // 0x1ca6d0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca6d0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca6d4: 0x8c22c808  lw          $v0, -0x37F8($at)
    ctx->pc = 0x1ca6d4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952968)));
    // 0x1ca6d8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca6d8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca6dc: 0xac23b660  sw          $v1, -0x49A0($at)
    ctx->pc = 0x1ca6dcu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294948448), GPR_U32(ctx, 3));
    // 0x1ca6e0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca6e0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca6e4: 0xc075cbc  jal         func_1D72F0
    ctx->pc = 0x1CA6E4u;
    SET_GPR_U32(ctx, 31, 0x1CA6ECu);
    ctx->pc = 0x1CA6E8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA6E4u;
            // 0x1ca6e8: 0xac22b664  sw          $v0, -0x499C($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294948452), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D72F0u;
    if (runtime->hasFunction(0x1D72F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D72F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA6ECu; }
        if (ctx->pc != 0x1CA6ECu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D72F0_0x1d72f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA6ECu; }
        if (ctx->pc != 0x1CA6ECu) { return; }
    }
    ctx->pc = 0x1CA6ECu;
label_1ca6ec:
    // 0x1ca6ec: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CA6ECu;
    {
        const bool branch_taken_0x1ca6ec = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1ca6ec) {
            ctx->pc = 0x1CA724u;
            goto label_1ca724;
        }
    }
    ctx->pc = 0x1CA6F4u;
    // 0x1ca6f4: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1ca6f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1ca6f8: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1ca6f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca6fc: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1ca6fcu;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca700: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1ca700u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca704: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca704u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca708: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1ca708u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca70c: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca70cu;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca710: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca710u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca714: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca714u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca718: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca718u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca71c: 0x1000024a  b           . + 4 + (0x24A << 2)
    ctx->pc = 0x1CA71Cu;
    {
        const bool branch_taken_0x1ca71c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA720u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA71Cu;
            // 0x1ca720: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca71c) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA724u;
label_1ca724:
    // 0x1ca724: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1ca724u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1ca728: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca728u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca72c: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1ca72cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ca730: 0x10000245  b           . + 4 + (0x245 << 2)
    ctx->pc = 0x1CA730u;
    {
        const bool branch_taken_0x1ca730 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA734u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA730u;
            // 0x1ca734: 0xa2a30000  sb          $v1, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca730) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA738u;
label_1ca738:
    // 0x1ca738: 0xc075ccc  jal         func_1D7330
    ctx->pc = 0x1CA738u;
    SET_GPR_U32(ctx, 31, 0x1CA740u);
    ctx->pc = 0x1CA73Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA738u;
            // 0x1ca73c: 0x9024c820  lbu         $a0, -0x37E0($at) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952992)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7330u;
    if (runtime->hasFunction(0x1D7330u)) {
        auto targetFn = runtime->lookupFunction(0x1D7330u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA740u; }
        if (ctx->pc != 0x1CA740u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7330_0x1d7330(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA740u; }
        if (ctx->pc != 0x1CA740u) { return; }
    }
    ctx->pc = 0x1CA740u;
label_1ca740:
    // 0x1ca740: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CA740u;
    {
        const bool branch_taken_0x1ca740 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1ca740) {
            ctx->pc = 0x1CA778u;
            goto label_1ca778;
        }
    }
    ctx->pc = 0x1CA748u;
    // 0x1ca748: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1ca748u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1ca74c: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1ca74cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca750: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1ca750u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca754: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1ca754u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca758: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca758u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca75c: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1ca75cu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca760: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca760u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca764: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca764u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca768: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca768u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca76c: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca76cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca770: 0x10000235  b           . + 4 + (0x235 << 2)
    ctx->pc = 0x1CA770u;
    {
        const bool branch_taken_0x1ca770 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA774u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA770u;
            // 0x1ca774: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca770) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA778u;
label_1ca778:
    // 0x1ca778: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1ca778u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1ca77c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca77cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca780: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1ca780u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1ca784: 0xa2a30000  sb          $v1, 0x0($s5)
    ctx->pc = 0x1ca784u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca788: 0x1000022f  b           . + 4 + (0x22F << 2)
    ctx->pc = 0x1CA788u;
    {
        const bool branch_taken_0x1ca788 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA78Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA788u;
            // 0x1ca78c: 0xa6600000  sh          $zero, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca788) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA790u;
label_1ca790:
    // 0x1ca790: 0x86430000  lh          $v1, 0x0($s2)
    ctx->pc = 0x1ca790u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1ca794: 0x2861001f  slti        $at, $v1, 0x1F
    ctx->pc = 0x1ca794u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x1ca798: 0x1420000d  bnez        $at, . + 4 + (0xD << 2)
    ctx->pc = 0x1CA798u;
    {
        const bool branch_taken_0x1ca798 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ca798) {
            ctx->pc = 0x1CA7D0u;
            goto label_1ca7d0;
        }
    }
    ctx->pc = 0x1CA7A0u;
    // 0x1ca7a0: 0x2402ffaa  addiu       $v0, $zero, -0x56
    ctx->pc = 0x1ca7a0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967210));
    // 0x1ca7a4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1ca7a4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca7a8: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1ca7a8u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca7ac: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1ca7acu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca7b0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca7b0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca7b4: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1ca7b4u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca7b8: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca7b8u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca7bc: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca7bcu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca7c0: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca7c0u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca7c4: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca7c4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca7c8: 0x1000021f  b           . + 4 + (0x21F << 2)
    ctx->pc = 0x1CA7C8u;
    {
        const bool branch_taken_0x1ca7c8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA7CCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA7C8u;
            // 0x1ca7cc: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca7c8) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA7D0u;
label_1ca7d0:
    // 0x1ca7d0: 0x86630000  lh          $v1, 0x0($s3)
    ctx->pc = 0x1ca7d0u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1ca7d4: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x1ca7d4u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1ca7d8: 0x0  nop
    ctx->pc = 0x1ca7d8u;
    // NOP
    // 0x1ca7dc: 0x0  nop
    ctx->pc = 0x1ca7dcu;
    // NOP
    // 0x1ca7e0: 0x1010  mfhi        $v0
    ctx->pc = 0x1ca7e0u;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x1ca7e4: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1CA7E4u;
    {
        const bool branch_taken_0x1ca7e4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CA7E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA7E4u;
            // 0x1ca7e8: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca7e4) {
            ctx->pc = 0x1CA810u;
            goto label_1ca810;
        }
    }
    ctx->pc = 0x1CA7ECu;
    // 0x1ca7ec: 0x9023c6ee  lbu         $v1, -0x3912($at)
    ctx->pc = 0x1ca7ecu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952686)));
    // 0x1ca7f0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca7f0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca7f4: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1ca7f4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1ca7f8: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1ca7f8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1ca7fc: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CA7FCu;
    {
        const bool branch_taken_0x1ca7fc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ca7fc) {
            ctx->pc = 0x1CA808u;
            goto label_1ca808;
        }
    }
    ctx->pc = 0x1CA804u;
    // 0x1ca804: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1ca804u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1ca808:
    // 0x1ca808: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca808u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca80c: 0xa023c6ec  sb          $v1, -0x3914($at)
    ctx->pc = 0x1ca80cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 3));
label_1ca810:
    // 0x1ca810: 0x86620000  lh          $v0, 0x0($s3)
    ctx->pc = 0x1ca810u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1ca814: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1ca814u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1ca818: 0xc075cd8  jal         func_1D7360
    ctx->pc = 0x1CA818u;
    SET_GPR_U32(ctx, 31, 0x1CA820u);
    ctx->pc = 0x1CA81Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA818u;
            // 0x1ca81c: 0xa6620000  sh          $v0, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7360u;
    if (runtime->hasFunction(0x1D7360u)) {
        auto targetFn = runtime->lookupFunction(0x1D7360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA820u; }
        if (ctx->pc != 0x1CA820u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7360_0x1d7360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA820u; }
        if (ctx->pc != 0x1CA820u) { return; }
    }
    ctx->pc = 0x1CA820u;
label_1ca820:
    // 0x1ca820: 0x10400012  beqz        $v0, . + 4 + (0x12 << 2)
    ctx->pc = 0x1CA820u;
    {
        const bool branch_taken_0x1ca820 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA824u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA820u;
            // 0x1ca824: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca820) {
            ctx->pc = 0x1CA86Cu;
            goto label_1ca86c;
        }
    }
    ctx->pc = 0x1CA828u;
    // 0x1ca828: 0x24030046  addiu       $v1, $zero, 0x46
    ctx->pc = 0x1ca828u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 70));
    // 0x1ca82c: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1ca82cu;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1ca830: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca830u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca834: 0xa023c6ee  sb          $v1, -0x3912($at)
    ctx->pc = 0x1ca834u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca838: 0x28410014  slti        $at, $v0, 0x14
    ctx->pc = 0x1ca838u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)20) ? 1 : 0);
    // 0x1ca83c: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CA83Cu;
    {
        const bool branch_taken_0x1ca83c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA840u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA83Cu;
            // 0x1ca840: 0x24020014  addiu       $v0, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca83c) {
            ctx->pc = 0x1CA84Cu;
            goto label_1ca84c;
        }
    }
    ctx->pc = 0x1CA844u;
    // 0x1ca844: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca844u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca848: 0xa022c6ec  sb          $v0, -0x3914($at)
    ctx->pc = 0x1ca848u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
label_1ca84c:
    // 0x1ca84c: 0x82a40000  lb          $a0, 0x0($s5)
    ctx->pc = 0x1ca84cu;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1ca850: 0x24030096  addiu       $v1, $zero, 0x96
    ctx->pc = 0x1ca850u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 150));
    // 0x1ca854: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca854u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca858: 0x24840001  addiu       $a0, $a0, 0x1
    ctx->pc = 0x1ca858u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 1));
    // 0x1ca85c: 0xa2a40000  sb          $a0, 0x0($s5)
    ctx->pc = 0x1ca85cu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x1ca860: 0xa6630000  sh          $v1, 0x0($s3)
    ctx->pc = 0x1ca860u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1ca864: 0x100001f8  b           . + 4 + (0x1F8 << 2)
    ctx->pc = 0x1CA864u;
    {
        const bool branch_taken_0x1ca864 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA868u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA864u;
            // 0x1ca868: 0xa6200000  sh          $zero, 0x0($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca864) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA86Cu;
label_1ca86c:
    // 0x1ca86c: 0x86620000  lh          $v0, 0x0($s3)
    ctx->pc = 0x1ca86cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1ca870: 0x284101c3  slti        $at, $v0, 0x1C3
    ctx->pc = 0x1ca870u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)451) ? 1 : 0);
    // 0x1ca874: 0x14200015  bnez        $at, . + 4 + (0x15 << 2)
    ctx->pc = 0x1CA874u;
    {
        const bool branch_taken_0x1ca874 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CA878u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA874u;
            // 0x1ca878: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca874) {
            ctx->pc = 0x1CA8CCu;
            goto label_1ca8cc;
        }
    }
    ctx->pc = 0x1CA87Cu;
    // 0x1ca87c: 0x86220000  lh          $v0, 0x0($s1)
    ctx->pc = 0x1ca87cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ca880: 0x28420003  slti        $v0, $v0, 0x3
    ctx->pc = 0x1ca880u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1ca884: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1CA884u;
    {
        const bool branch_taken_0x1ca884 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CA888u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA884u;
            // 0x1ca888: 0x24020063  addiu       $v0, $zero, 0x63 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca884) {
            ctx->pc = 0x1CA8B8u;
            goto label_1ca8b8;
        }
    }
    ctx->pc = 0x1CA88Cu;
    // 0x1ca88c: 0x2403ffae  addiu       $v1, $zero, -0x52
    ctx->pc = 0x1ca88cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1ca890: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1ca890u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca894: 0xa2e30000  sb          $v1, 0x0($s7)
    ctx->pc = 0x1ca894u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca898: 0xa2c20000  sb          $v0, 0x0($s6)
    ctx->pc = 0x1ca898u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca89c: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1ca89cu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca8a0: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca8a0u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca8a4: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca8a4u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca8a8: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca8a8u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca8ac: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca8acu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca8b0: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1CA8B0u;
    {
        const bool branch_taken_0x1ca8b0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA8B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA8B0u;
            // 0x1ca8b4: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca8b0) {
            ctx->pc = 0x1CA8C8u;
            goto label_1ca8c8;
        }
    }
    ctx->pc = 0x1CA8B8u;
label_1ca8b8:
    // 0x1ca8b8: 0xa2a20000  sb          $v0, 0x0($s5)
    ctx->pc = 0x1ca8b8u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca8bc: 0x86220000  lh          $v0, 0x0($s1)
    ctx->pc = 0x1ca8bcu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1ca8c0: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1ca8c0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1ca8c4: 0xa6220000  sh          $v0, 0x0($s1)
    ctx->pc = 0x1ca8c4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 2));
label_1ca8c8:
    // 0x1ca8c8: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca8c8u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1ca8cc:
    // 0x1ca8cc: 0x100001de  b           . + 4 + (0x1DE << 2)
    ctx->pc = 0x1CA8CCu;
    {
        const bool branch_taken_0x1ca8cc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ca8cc) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA8D4u;
label_1ca8d4:
    // 0x1ca8d4: 0x86430000  lh          $v1, 0x0($s2)
    ctx->pc = 0x1ca8d4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1ca8d8: 0x2861001f  slti        $at, $v1, 0x1F
    ctx->pc = 0x1ca8d8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x1ca8dc: 0x1420000d  bnez        $at, . + 4 + (0xD << 2)
    ctx->pc = 0x1CA8DCu;
    {
        const bool branch_taken_0x1ca8dc = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1ca8dc) {
            ctx->pc = 0x1CA914u;
            goto label_1ca914;
        }
    }
    ctx->pc = 0x1CA8E4u;
    // 0x1ca8e4: 0x2402ffaa  addiu       $v0, $zero, -0x56
    ctx->pc = 0x1ca8e4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967210));
    // 0x1ca8e8: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1ca8e8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca8ec: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1ca8ecu;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca8f0: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1ca8f0u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca8f4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca8f4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca8f8: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1ca8f8u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca8fc: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca8fcu;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca900: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca900u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca904: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca904u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca908: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca908u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca90c: 0x100001ce  b           . + 4 + (0x1CE << 2)
    ctx->pc = 0x1CA90Cu;
    {
        const bool branch_taken_0x1ca90c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA910u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA90Cu;
            // 0x1ca910: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca90c) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA914u;
label_1ca914:
    // 0x1ca914: 0x86630000  lh          $v1, 0x0($s3)
    ctx->pc = 0x1ca914u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1ca918: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x1ca918u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1ca91c: 0x0  nop
    ctx->pc = 0x1ca91cu;
    // NOP
    // 0x1ca920: 0x0  nop
    ctx->pc = 0x1ca920u;
    // NOP
    // 0x1ca924: 0x1010  mfhi        $v0
    ctx->pc = 0x1ca924u;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x1ca928: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1CA928u;
    {
        const bool branch_taken_0x1ca928 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CA92Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA928u;
            // 0x1ca92c: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca928) {
            ctx->pc = 0x1CA954u;
            goto label_1ca954;
        }
    }
    ctx->pc = 0x1CA930u;
    // 0x1ca930: 0x9023c6ee  lbu         $v1, -0x3912($at)
    ctx->pc = 0x1ca930u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952686)));
    // 0x1ca934: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca934u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca938: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1ca938u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1ca93c: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1ca93cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1ca940: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CA940u;
    {
        const bool branch_taken_0x1ca940 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1ca940) {
            ctx->pc = 0x1CA94Cu;
            goto label_1ca94c;
        }
    }
    ctx->pc = 0x1CA948u;
    // 0x1ca948: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1ca948u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1ca94c:
    // 0x1ca94c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca94cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca950: 0xa023c6ec  sb          $v1, -0x3914($at)
    ctx->pc = 0x1ca950u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 3));
label_1ca954:
    // 0x1ca954: 0x86630000  lh          $v1, 0x0($s3)
    ctx->pc = 0x1ca954u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1ca958: 0x2462ffff  addiu       $v0, $v1, -0x1
    ctx->pc = 0x1ca958u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 3), 4294967295));
    // 0x1ca95c: 0x3082a  slt         $at, $zero, $v1
    ctx->pc = 0x1ca95cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1ca960: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CA960u;
    {
        const bool branch_taken_0x1ca960 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA964u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA960u;
            // 0x1ca964: 0xa6620000  sh          $v0, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca960) {
            ctx->pc = 0x1CA970u;
            goto label_1ca970;
        }
    }
    ctx->pc = 0x1CA968u;
    // 0x1ca968: 0x100001b7  b           . + 4 + (0x1B7 << 2)
    ctx->pc = 0x1CA968u;
    {
        const bool branch_taken_0x1ca968 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA96Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA968u;
            // 0x1ca96c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca968) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA970u;
label_1ca970:
    // 0x1ca970: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca970u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca974: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1ca974u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1ca978: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca978u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca97c: 0xa022c6ee  sb          $v0, -0x3912($at)
    ctx->pc = 0x1ca97cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca980: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca980u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca984: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1ca984u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1ca988: 0x28410046  slti        $at, $v0, 0x46
    ctx->pc = 0x1ca988u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)70) ? 1 : 0);
    // 0x1ca98c: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CA98Cu;
    {
        const bool branch_taken_0x1ca98c = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA990u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA98Cu;
            // 0x1ca990: 0x24020046  addiu       $v0, $zero, 0x46 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 70));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca98c) {
            ctx->pc = 0x1CA99Cu;
            goto label_1ca99c;
        }
    }
    ctx->pc = 0x1CA994u;
    // 0x1ca994: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca994u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca998: 0xa022c6ec  sb          $v0, -0x3914($at)
    ctx->pc = 0x1ca998u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
label_1ca99c:
    // 0x1ca99c: 0xc07254c  jal         func_1C9530
    ctx->pc = 0x1CA99Cu;
    SET_GPR_U32(ctx, 31, 0x1CA9A4u);
    ctx->pc = 0x1C9530u;
    if (runtime->hasFunction(0x1C9530u)) {
        auto targetFn = runtime->lookupFunction(0x1C9530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA9A4u; }
        if (ctx->pc != 0x1CA9A4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C9530_0x1c9530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA9A4u; }
        if (ctx->pc != 0x1CA9A4u) { return; }
    }
    ctx->pc = 0x1CA9A4u;
label_1ca9a4:
    // 0x1ca9a4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca9a4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1ca9a8: 0x8c25c800  lw          $a1, -0x3800($at)
    ctx->pc = 0x1ca9a8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952960)));
    // 0x1ca9ac: 0xc075d2c  jal         func_1D74B0
    ctx->pc = 0x1CA9ACu;
    SET_GPR_U32(ctx, 31, 0x1CA9B4u);
    ctx->pc = 0x1CA9B0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA9ACu;
            // 0x1ca9b0: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D74B0u;
    if (runtime->hasFunction(0x1D74B0u)) {
        auto targetFn = runtime->lookupFunction(0x1D74B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA9B4u; }
        if (ctx->pc != 0x1CA9B4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D74B0_0x1d74b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA9B4u; }
        if (ctx->pc != 0x1CA9B4u) { return; }
    }
    ctx->pc = 0x1CA9B4u;
label_1ca9b4:
    // 0x1ca9b4: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CA9B4u;
    {
        const bool branch_taken_0x1ca9b4 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1CA9B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA9B4u;
            // 0x1ca9b8: 0x2403001e  addiu       $v1, $zero, 0x1E (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca9b4) {
            ctx->pc = 0x1CA9ECu;
            goto label_1ca9ec;
        }
    }
    ctx->pc = 0x1CA9BCu;
    // 0x1ca9bc: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1ca9bcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1ca9c0: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1ca9c0u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1ca9c4: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1ca9c4u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1ca9c8: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1ca9c8u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1ca9cc: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca9ccu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca9d0: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1ca9d0u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca9d4: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1ca9d4u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1ca9d8: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1ca9d8u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca9dc: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1ca9dcu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca9e0: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1ca9e0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1ca9e4: 0x10000198  b           . + 4 + (0x198 << 2)
    ctx->pc = 0x1CA9E4u;
    {
        const bool branch_taken_0x1ca9e4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA9E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA9E4u;
            // 0x1ca9e8: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca9e4) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA9ECu;
label_1ca9ec:
    // 0x1ca9ec: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1ca9ecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1ca9f0: 0x10000195  b           . + 4 + (0x195 << 2)
    ctx->pc = 0x1CA9F0u;
    {
        const bool branch_taken_0x1ca9f0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CA9F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CA9F0u;
            // 0x1ca9f4: 0xa2a30000  sb          $v1, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1ca9f0) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CA9F8u;
label_1ca9f8:
    // 0x1ca9f8: 0xa025c6ee  sb          $a1, -0x3912($at)
    ctx->pc = 0x1ca9f8u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 5));
    // 0x1ca9fc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1ca9fcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caa00: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1caa00u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1caa04: 0x2841000b  slti        $at, $v0, 0xB
    ctx->pc = 0x1caa04u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)11) ? 1 : 0);
    // 0x1caa08: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CAA08u;
    {
        const bool branch_taken_0x1caa08 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAA0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAA08u;
            // 0x1caa0c: 0x2402000b  addiu       $v0, $zero, 0xB (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 11));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caa08) {
            ctx->pc = 0x1CAA18u;
            goto label_1caa18;
        }
    }
    ctx->pc = 0x1CAA10u;
    // 0x1caa10: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1caa10u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caa14: 0xa022c6ec  sb          $v0, -0x3914($at)
    ctx->pc = 0x1caa14u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
label_1caa18:
    // 0x1caa18: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1caa18u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caa1c: 0xc075ccc  jal         func_1D7330
    ctx->pc = 0x1CAA1Cu;
    SET_GPR_U32(ctx, 31, 0x1CAA24u);
    ctx->pc = 0x1CAA20u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAA1Cu;
            // 0x1caa20: 0x9024c820  lbu         $a0, -0x37E0($at) (Delay Slot)
        SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952992)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7330u;
    if (runtime->hasFunction(0x1D7330u)) {
        auto targetFn = runtime->lookupFunction(0x1D7330u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAA24u; }
        if (ctx->pc != 0x1CAA24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7330_0x1d7330(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAA24u; }
        if (ctx->pc != 0x1CAA24u) { return; }
    }
    ctx->pc = 0x1CAA24u;
label_1caa24:
    // 0x1caa24: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CAA24u;
    {
        const bool branch_taken_0x1caa24 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1caa24) {
            ctx->pc = 0x1CAA5Cu;
            goto label_1caa5c;
        }
    }
    ctx->pc = 0x1CAA2Cu;
    // 0x1caa2c: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1caa2cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1caa30: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1caa30u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1caa34: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1caa34u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1caa38: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1caa38u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1caa3c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1caa3cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1caa40: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1caa40u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caa44: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1caa44u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caa48: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1caa48u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caa4c: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1caa4cu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caa50: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1caa50u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caa54: 0x1000017c  b           . + 4 + (0x17C << 2)
    ctx->pc = 0x1CAA54u;
    {
        const bool branch_taken_0x1caa54 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAA58u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAA54u;
            // 0x1caa58: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caa54) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAA5Cu;
label_1caa5c:
    // 0x1caa5c: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1caa5cu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1caa60: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1caa60u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1caa64: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1caa64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1caa68: 0xa2a30000  sb          $v1, 0x0($s5)
    ctx->pc = 0x1caa68u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1caa6c: 0x10000176  b           . + 4 + (0x176 << 2)
    ctx->pc = 0x1CAA6Cu;
    {
        const bool branch_taken_0x1caa6c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAA70u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAA6Cu;
            // 0x1caa70: 0xa6600000  sh          $zero, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caa6c) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAA74u;
label_1caa74:
    // 0x1caa74: 0x86430000  lh          $v1, 0x0($s2)
    ctx->pc = 0x1caa74u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1caa78: 0x2861001f  slti        $at, $v1, 0x1F
    ctx->pc = 0x1caa78u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x1caa7c: 0x1420000d  bnez        $at, . + 4 + (0xD << 2)
    ctx->pc = 0x1CAA7Cu;
    {
        const bool branch_taken_0x1caa7c = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1caa7c) {
            ctx->pc = 0x1CAAB4u;
            goto label_1caab4;
        }
    }
    ctx->pc = 0x1CAA84u;
    // 0x1caa84: 0x2402ffaa  addiu       $v0, $zero, -0x56
    ctx->pc = 0x1caa84u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967210));
    // 0x1caa88: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1caa88u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1caa8c: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1caa8cu;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1caa90: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1caa90u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1caa94: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1caa94u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1caa98: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1caa98u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caa9c: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1caa9cu;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caaa0: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1caaa0u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caaa4: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1caaa4u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caaa8: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1caaa8u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caaac: 0x10000166  b           . + 4 + (0x166 << 2)
    ctx->pc = 0x1CAAACu;
    {
        const bool branch_taken_0x1caaac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAAB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAAACu;
            // 0x1caab0: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caaac) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAAB4u;
label_1caab4:
    // 0x1caab4: 0x86630000  lh          $v1, 0x0($s3)
    ctx->pc = 0x1caab4u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1caab8: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x1caab8u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1caabc: 0x0  nop
    ctx->pc = 0x1caabcu;
    // NOP
    // 0x1caac0: 0x0  nop
    ctx->pc = 0x1caac0u;
    // NOP
    // 0x1caac4: 0x1010  mfhi        $v0
    ctx->pc = 0x1caac4u;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x1caac8: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1CAAC8u;
    {
        const bool branch_taken_0x1caac8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CAACCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAAC8u;
            // 0x1caacc: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caac8) {
            ctx->pc = 0x1CAAF4u;
            goto label_1caaf4;
        }
    }
    ctx->pc = 0x1CAAD0u;
    // 0x1caad0: 0x9023c6ee  lbu         $v1, -0x3912($at)
    ctx->pc = 0x1caad0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952686)));
    // 0x1caad4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1caad4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caad8: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1caad8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1caadc: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1caadcu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1caae0: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CAAE0u;
    {
        const bool branch_taken_0x1caae0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1caae0) {
            ctx->pc = 0x1CAAECu;
            goto label_1caaec;
        }
    }
    ctx->pc = 0x1CAAE8u;
    // 0x1caae8: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1caae8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1caaec:
    // 0x1caaec: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1caaecu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caaf0: 0xa023c6ec  sb          $v1, -0x3914($at)
    ctx->pc = 0x1caaf0u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 3));
label_1caaf4:
    // 0x1caaf4: 0x86620000  lh          $v0, 0x0($s3)
    ctx->pc = 0x1caaf4u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1caaf8: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1caaf8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1caafc: 0xc075cd8  jal         func_1D7360
    ctx->pc = 0x1CAAFCu;
    SET_GPR_U32(ctx, 31, 0x1CAB04u);
    ctx->pc = 0x1CAB00u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAAFCu;
            // 0x1cab00: 0xa6620000  sh          $v0, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7360u;
    if (runtime->hasFunction(0x1D7360u)) {
        auto targetFn = runtime->lookupFunction(0x1D7360u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAB04u; }
        if (ctx->pc != 0x1CAB04u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7360_0x1d7360(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAB04u; }
        if (ctx->pc != 0x1CAB04u) { return; }
    }
    ctx->pc = 0x1CAB04u;
label_1cab04:
    // 0x1cab04: 0x10400010  beqz        $v0, . + 4 + (0x10 << 2)
    ctx->pc = 0x1CAB04u;
    {
        const bool branch_taken_0x1cab04 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAB08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAB04u;
            // 0x1cab08: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cab04) {
            ctx->pc = 0x1CAB48u;
            goto label_1cab48;
        }
    }
    ctx->pc = 0x1CAB0Cu;
    // 0x1cab0c: 0x2403003c  addiu       $v1, $zero, 0x3C
    ctx->pc = 0x1cab0cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1cab10: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1cab10u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1cab14: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cab14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cab18: 0xa023c6ee  sb          $v1, -0x3912($at)
    ctx->pc = 0x1cab18u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cab1c: 0x28410014  slti        $at, $v0, 0x14
    ctx->pc = 0x1cab1cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)20) ? 1 : 0);
    // 0x1cab20: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CAB20u;
    {
        const bool branch_taken_0x1cab20 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAB24u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAB20u;
            // 0x1cab24: 0x24020014  addiu       $v0, $zero, 0x14 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 20));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cab20) {
            ctx->pc = 0x1CAB30u;
            goto label_1cab30;
        }
    }
    ctx->pc = 0x1CAB28u;
    // 0x1cab28: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cab28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cab2c: 0xa022c6ec  sb          $v0, -0x3914($at)
    ctx->pc = 0x1cab2cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
label_1cab30:
    // 0x1cab30: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1cab30u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1cab34: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cab34u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cab38: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1cab38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1cab3c: 0xa2a30000  sb          $v1, 0x0($s5)
    ctx->pc = 0x1cab3cu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cab40: 0x10000141  b           . + 4 + (0x141 << 2)
    ctx->pc = 0x1CAB40u;
    {
        const bool branch_taken_0x1cab40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAB44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAB40u;
            // 0x1cab44: 0xa6600000  sh          $zero, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cab40) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAB48u;
label_1cab48:
    // 0x1cab48: 0x86620000  lh          $v0, 0x0($s3)
    ctx->pc = 0x1cab48u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1cab4c: 0x284101c3  slti        $at, $v0, 0x1C3
    ctx->pc = 0x1cab4cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)451) ? 1 : 0);
    // 0x1cab50: 0x14200015  bnez        $at, . + 4 + (0x15 << 2)
    ctx->pc = 0x1CAB50u;
    {
        const bool branch_taken_0x1cab50 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CAB54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAB50u;
            // 0x1cab54: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cab50) {
            ctx->pc = 0x1CABA8u;
            goto label_1caba8;
        }
    }
    ctx->pc = 0x1CAB58u;
    // 0x1cab58: 0x86220000  lh          $v0, 0x0($s1)
    ctx->pc = 0x1cab58u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cab5c: 0x28420003  slti        $v0, $v0, 0x3
    ctx->pc = 0x1cab5cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1cab60: 0x1440000c  bnez        $v0, . + 4 + (0xC << 2)
    ctx->pc = 0x1CAB60u;
    {
        const bool branch_taken_0x1cab60 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CAB64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAB60u;
            // 0x1cab64: 0x24020063  addiu       $v0, $zero, 0x63 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cab60) {
            ctx->pc = 0x1CAB94u;
            goto label_1cab94;
        }
    }
    ctx->pc = 0x1CAB68u;
    // 0x1cab68: 0x2403ffae  addiu       $v1, $zero, -0x52
    ctx->pc = 0x1cab68u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1cab6c: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1cab6cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cab70: 0xa2e30000  sb          $v1, 0x0($s7)
    ctx->pc = 0x1cab70u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cab74: 0xa2c20000  sb          $v0, 0x0($s6)
    ctx->pc = 0x1cab74u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cab78: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1cab78u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cab7c: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1cab7cu;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cab80: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1cab80u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cab84: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1cab84u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cab88: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1cab88u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cab8c: 0x10000005  b           . + 4 + (0x5 << 2)
    ctx->pc = 0x1CAB8Cu;
    {
        const bool branch_taken_0x1cab8c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAB90u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAB8Cu;
            // 0x1cab90: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cab8c) {
            ctx->pc = 0x1CABA4u;
            goto label_1caba4;
        }
    }
    ctx->pc = 0x1CAB94u;
label_1cab94:
    // 0x1cab94: 0xa2a20000  sb          $v0, 0x0($s5)
    ctx->pc = 0x1cab94u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cab98: 0x86220000  lh          $v0, 0x0($s1)
    ctx->pc = 0x1cab98u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cab9c: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1cab9cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1caba0: 0xa6220000  sh          $v0, 0x0($s1)
    ctx->pc = 0x1caba0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 2));
label_1caba4:
    // 0x1caba4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1caba4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1caba8:
    // 0x1caba8: 0x10000127  b           . + 4 + (0x127 << 2)
    ctx->pc = 0x1CABA8u;
    {
        const bool branch_taken_0x1caba8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1caba8) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CABB0u;
label_1cabb0:
    // 0x1cabb0: 0xc075d50  jal         func_1D7540
    ctx->pc = 0x1CABB0u;
    SET_GPR_U32(ctx, 31, 0x1CABB8u);
    ctx->pc = 0x1D7540u;
    if (runtime->hasFunction(0x1D7540u)) {
        auto targetFn = runtime->lookupFunction(0x1D7540u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CABB8u; }
        if (ctx->pc != 0x1CABB8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7540_0x1d7540(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CABB8u; }
        if (ctx->pc != 0x1CABB8u) { return; }
    }
    ctx->pc = 0x1CABB8u;
label_1cabb8:
    // 0x1cabb8: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CABB8u;
    {
        const bool branch_taken_0x1cabb8 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1CABBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CABB8u;
            // 0x1cabbc: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cabb8) {
            ctx->pc = 0x1CABF0u;
            goto label_1cabf0;
        }
    }
    ctx->pc = 0x1CABC0u;
    // 0x1cabc0: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1cabc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1cabc4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1cabc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cabc8: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1cabc8u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cabcc: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1cabccu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cabd0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cabd0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cabd4: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1cabd4u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cabd8: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1cabd8u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cabdc: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1cabdcu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cabe0: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1cabe0u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cabe4: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1cabe4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cabe8: 0x10000117  b           . + 4 + (0x117 << 2)
    ctx->pc = 0x1CABE8u;
    {
        const bool branch_taken_0x1cabe8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CABECu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CABE8u;
            // 0x1cabec: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cabe8) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CABF0u;
label_1cabf0:
    // 0x1cabf0: 0xc075d68  jal         func_1D75A0
    ctx->pc = 0x1CABF0u;
    SET_GPR_U32(ctx, 31, 0x1CABF8u);
    ctx->pc = 0x1CABF4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CABF0u;
            // 0x1cabf4: 0x24050005  addiu       $a1, $zero, 0x5 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D75A0u;
    if (runtime->hasFunction(0x1D75A0u)) {
        auto targetFn = runtime->lookupFunction(0x1D75A0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CABF8u; }
        if (ctx->pc != 0x1CABF8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D75A0_0x1d75a0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CABF8u; }
        if (ctx->pc != 0x1CABF8u) { return; }
    }
    ctx->pc = 0x1CABF8u;
label_1cabf8:
    // 0x1cabf8: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CABF8u;
    {
        const bool branch_taken_0x1cabf8 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x1cabf8) {
            ctx->pc = 0x1CAC30u;
            goto label_1cac30;
        }
    }
    ctx->pc = 0x1CAC00u;
    // 0x1cac00: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1cac00u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1cac04: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1cac04u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cac08: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1cac08u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cac0c: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1cac0cu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cac10: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cac10u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cac14: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1cac14u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cac18: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1cac18u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cac1c: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1cac1cu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cac20: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1cac20u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cac24: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1cac24u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cac28: 0x10000107  b           . + 4 + (0x107 << 2)
    ctx->pc = 0x1CAC28u;
    {
        const bool branch_taken_0x1cac28 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAC2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAC28u;
            // 0x1cac2c: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cac28) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAC30u;
label_1cac30:
    // 0x1cac30: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1cac30u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1cac34: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cac34u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cac38: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1cac38u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1cac3c: 0xa2a30000  sb          $v1, 0x0($s5)
    ctx->pc = 0x1cac3cu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cac40: 0x10000101  b           . + 4 + (0x101 << 2)
    ctx->pc = 0x1CAC40u;
    {
        const bool branch_taken_0x1cac40 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAC44u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAC40u;
            // 0x1cac44: 0xa6600000  sh          $zero, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cac40) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAC48u;
label_1cac48:
    // 0x1cac48: 0x86430000  lh          $v1, 0x0($s2)
    ctx->pc = 0x1cac48u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x1cac4c: 0x2861001f  slti        $at, $v1, 0x1F
    ctx->pc = 0x1cac4cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)31) ? 1 : 0);
    // 0x1cac50: 0x1420000f  bnez        $at, . + 4 + (0xF << 2)
    ctx->pc = 0x1CAC50u;
    {
        const bool branch_taken_0x1cac50 = (GPR_U64(ctx, 1) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cac50) {
            ctx->pc = 0x1CAC90u;
            goto label_1cac90;
        }
    }
    ctx->pc = 0x1CAC58u;
    // 0x1cac58: 0xc075d5c  jal         func_1D7570
    ctx->pc = 0x1CAC58u;
    SET_GPR_U32(ctx, 31, 0x1CAC60u);
    ctx->pc = 0x1D7570u;
    if (runtime->hasFunction(0x1D7570u)) {
        auto targetFn = runtime->lookupFunction(0x1D7570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAC60u; }
        if (ctx->pc != 0x1CAC60u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7570_0x1d7570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAC60u; }
        if (ctx->pc != 0x1CAC60u) { return; }
    }
    ctx->pc = 0x1CAC60u;
label_1cac60:
    // 0x1cac60: 0x2402ffaa  addiu       $v0, $zero, -0x56
    ctx->pc = 0x1cac60u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967210));
    // 0x1cac64: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1cac64u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cac68: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1cac68u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cac6c: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1cac6cu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cac70: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cac70u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cac74: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1cac74u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cac78: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1cac78u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cac7c: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1cac7cu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cac80: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1cac80u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cac84: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1cac84u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cac88: 0x100000ef  b           . + 4 + (0xEF << 2)
    ctx->pc = 0x1CAC88u;
    {
        const bool branch_taken_0x1cac88 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAC8Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAC88u;
            // 0x1cac8c: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cac88) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAC90u;
label_1cac90:
    // 0x1cac90: 0x86630000  lh          $v1, 0x0($s3)
    ctx->pc = 0x1cac90u;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1cac94: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x1cac94u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1cac98: 0x0  nop
    ctx->pc = 0x1cac98u;
    // NOP
    // 0x1cac9c: 0x0  nop
    ctx->pc = 0x1cac9cu;
    // NOP
    // 0x1caca0: 0x1010  mfhi        $v0
    ctx->pc = 0x1caca0u;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x1caca4: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1CACA4u;
    {
        const bool branch_taken_0x1caca4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CACA8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CACA4u;
            // 0x1caca8: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caca4) {
            ctx->pc = 0x1CACD0u;
            goto label_1cacd0;
        }
    }
    ctx->pc = 0x1CACACu;
    // 0x1cacac: 0x9023c6ee  lbu         $v1, -0x3912($at)
    ctx->pc = 0x1cacacu;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952686)));
    // 0x1cacb0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cacb0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cacb4: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1cacb4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1cacb8: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1cacb8u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1cacbc: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CACBCu;
    {
        const bool branch_taken_0x1cacbc = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cacbc) {
            ctx->pc = 0x1CACC8u;
            goto label_1cacc8;
        }
    }
    ctx->pc = 0x1CACC4u;
    // 0x1cacc4: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1cacc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1cacc8:
    // 0x1cacc8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cacc8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caccc: 0xa023c6ec  sb          $v1, -0x3914($at)
    ctx->pc = 0x1cacccu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 3));
label_1cacd0:
    // 0x1cacd0: 0x86620000  lh          $v0, 0x0($s3)
    ctx->pc = 0x1cacd0u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1cacd4: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1cacd4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1cacd8: 0xc075d74  jal         func_1D75D0
    ctx->pc = 0x1CACD8u;
    SET_GPR_U32(ctx, 31, 0x1CACE0u);
    ctx->pc = 0x1CACDCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CACD8u;
            // 0x1cacdc: 0xa6620000  sh          $v0, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D75D0u;
    if (runtime->hasFunction(0x1D75D0u)) {
        auto targetFn = runtime->lookupFunction(0x1D75D0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CACE0u; }
        if (ctx->pc != 0x1CACE0u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D75D0_0x1d75d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CACE0u; }
        if (ctx->pc != 0x1CACE0u) { return; }
    }
    ctx->pc = 0x1CACE0u;
label_1cace0:
    // 0x1cace0: 0x441001b  bgez        $v0, . + 4 + (0x1B << 2)
    ctx->pc = 0x1CACE0u;
    {
        const bool branch_taken_0x1cace0 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1CACE4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CACE0u;
            // 0x1cace4: 0x24030003  addiu       $v1, $zero, 0x3 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cace0) {
            ctx->pc = 0x1CAD50u;
            goto label_1cad50;
        }
    }
    ctx->pc = 0x1CACE8u;
    // 0x1cace8: 0x86220000  lh          $v0, 0x0($s1)
    ctx->pc = 0x1cace8u;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cacec: 0x28420003  slti        $v0, $v0, 0x3
    ctx->pc = 0x1cacecu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)3) ? 1 : 0);
    // 0x1cacf0: 0x1440000e  bnez        $v0, . + 4 + (0xE << 2)
    ctx->pc = 0x1CACF0u;
    {
        const bool branch_taken_0x1cacf0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x1cacf0) {
            ctx->pc = 0x1CAD2Cu;
            goto label_1cad2c;
        }
    }
    ctx->pc = 0x1CACF8u;
    // 0x1cacf8: 0xc075d5c  jal         func_1D7570
    ctx->pc = 0x1CACF8u;
    SET_GPR_U32(ctx, 31, 0x1CAD00u);
    ctx->pc = 0x1D7570u;
    if (runtime->hasFunction(0x1D7570u)) {
        auto targetFn = runtime->lookupFunction(0x1D7570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAD00u; }
        if (ctx->pc != 0x1CAD00u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7570_0x1d7570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAD00u; }
        if (ctx->pc != 0x1CAD00u) { return; }
    }
    ctx->pc = 0x1CAD00u;
label_1cad00:
    // 0x1cad00: 0x2403ffac  addiu       $v1, $zero, -0x54
    ctx->pc = 0x1cad00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967212));
    // 0x1cad04: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1cad04u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cad08: 0xa2e30000  sb          $v1, 0x0($s7)
    ctx->pc = 0x1cad08u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cad0c: 0xa2c20000  sb          $v0, 0x0($s6)
    ctx->pc = 0x1cad0cu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cad10: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1cad10u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cad14: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1cad14u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cad18: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1cad18u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cad1c: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1cad1cu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cad20: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1cad20u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cad24: 0x10000008  b           . + 4 + (0x8 << 2)
    ctx->pc = 0x1CAD24u;
    {
        const bool branch_taken_0x1cad24 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAD28u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAD24u;
            // 0x1cad28: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cad24) {
            ctx->pc = 0x1CAD48u;
            goto label_1cad48;
        }
    }
    ctx->pc = 0x1CAD2Cu;
label_1cad2c:
    // 0x1cad2c: 0xc075d5c  jal         func_1D7570
    ctx->pc = 0x1CAD2Cu;
    SET_GPR_U32(ctx, 31, 0x1CAD34u);
    ctx->pc = 0x1D7570u;
    if (runtime->hasFunction(0x1D7570u)) {
        auto targetFn = runtime->lookupFunction(0x1D7570u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAD34u; }
        if (ctx->pc != 0x1CAD34u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7570_0x1d7570(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAD34u; }
        if (ctx->pc != 0x1CAD34u) { return; }
    }
    ctx->pc = 0x1CAD34u;
label_1cad34:
    // 0x1cad34: 0x24020063  addiu       $v0, $zero, 0x63
    ctx->pc = 0x1cad34u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 99));
    // 0x1cad38: 0xa2a20000  sb          $v0, 0x0($s5)
    ctx->pc = 0x1cad38u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cad3c: 0x86220000  lh          $v0, 0x0($s1)
    ctx->pc = 0x1cad3cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x1cad40: 0x24420001  addiu       $v0, $v0, 0x1
    ctx->pc = 0x1cad40u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
    // 0x1cad44: 0xa6220000  sh          $v0, 0x0($s1)
    ctx->pc = 0x1cad44u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 2));
label_1cad48:
    // 0x1cad48: 0x100000bf  b           . + 4 + (0xBF << 2)
    ctx->pc = 0x1CAD48u;
    {
        const bool branch_taken_0x1cad48 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAD4Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAD48u;
            // 0x1cad4c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cad48) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAD50u;
label_1cad50:
    // 0x1cad50: 0x10430003  beq         $v0, $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CAD50u;
    {
        const bool branch_taken_0x1cad50 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 3));
        ctx->pc = 0x1CAD54u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAD50u;
            // 0x1cad54: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cad50) {
            ctx->pc = 0x1CAD60u;
            goto label_1cad60;
        }
    }
    ctx->pc = 0x1CAD58u;
    // 0x1cad58: 0x1000001e  b           . + 4 + (0x1E << 2)
    ctx->pc = 0x1CAD58u;
    {
        const bool branch_taken_0x1cad58 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAD5Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAD58u;
            // 0x1cad5c: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cad58) {
            ctx->pc = 0x1CADD4u;
            goto label_1cadd4;
        }
    }
    ctx->pc = 0x1CAD60u;
label_1cad60:
    // 0x1cad60: 0x24030046  addiu       $v1, $zero, 0x46
    ctx->pc = 0x1cad60u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 70));
    // 0x1cad64: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1cad64u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1cad68: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cad68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cad6c: 0xa023c6ee  sb          $v1, -0x3912($at)
    ctx->pc = 0x1cad6cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cad70: 0x2841003c  slti        $at, $v0, 0x3C
    ctx->pc = 0x1cad70u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)60) ? 1 : 0);
    // 0x1cad74: 0x10200004  beqz        $at, . + 4 + (0x4 << 2)
    ctx->pc = 0x1CAD74u;
    {
        const bool branch_taken_0x1cad74 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAD78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAD74u;
            // 0x1cad78: 0x3c040034  lui         $a0, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cad74) {
            ctx->pc = 0x1CAD88u;
            goto label_1cad88;
        }
    }
    ctx->pc = 0x1CAD7Cu;
    // 0x1cad7c: 0x2402003c  addiu       $v0, $zero, 0x3C
    ctx->pc = 0x1cad7cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 60));
    // 0x1cad80: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cad80u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cad84: 0xa022c6ec  sb          $v0, -0x3914($at)
    ctx->pc = 0x1cad84u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
label_1cad88:
    // 0x1cad88: 0xc075d80  jal         func_1D7600
    ctx->pc = 0x1CAD88u;
    SET_GPR_U32(ctx, 31, 0x1CAD90u);
    ctx->pc = 0x1CAD8Cu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAD88u;
            // 0x1cad8c: 0x2484b660  addiu       $a0, $a0, -0x49A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948448));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7600u;
    if (runtime->hasFunction(0x1D7600u)) {
        auto targetFn = runtime->lookupFunction(0x1D7600u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAD90u; }
        if (ctx->pc != 0x1CAD90u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7600_0x1d7600(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAD90u; }
        if (ctx->pc != 0x1CAD90u) { return; }
    }
    ctx->pc = 0x1CAD90u;
label_1cad90:
    // 0x1cad90: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cad90u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cad94: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cad94u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cad98: 0x8c23b660  lw          $v1, -0x49A0($at)
    ctx->pc = 0x1cad98u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294948448)));
    // 0x1cad9c: 0x2484b660  addiu       $a0, $a0, -0x49A0
    ctx->pc = 0x1cad9cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948448));
    // 0x1cada0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cada0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cada4: 0x8c22b664  lw          $v0, -0x499C($at)
    ctx->pc = 0x1cada4u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294948452)));
    // 0x1cada8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cada8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cadac: 0xac23c810  sw          $v1, -0x37F0($at)
    ctx->pc = 0x1cadacu;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294952976), GPR_U32(ctx, 3));
    // 0x1cadb0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cadb0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cadb4: 0xc075cbc  jal         func_1D72F0
    ctx->pc = 0x1CADB4u;
    SET_GPR_U32(ctx, 31, 0x1CADBCu);
    ctx->pc = 0x1CADB8u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CADB4u;
            // 0x1cadb8: 0xac22c808  sw          $v0, -0x37F8($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294952968), GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D72F0u;
    if (runtime->hasFunction(0x1D72F0u)) {
        auto targetFn = runtime->lookupFunction(0x1D72F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CADBCu; }
        if (ctx->pc != 0x1CADBCu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D72F0_0x1d72f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CADBCu; }
        if (ctx->pc != 0x1CADBCu) { return; }
    }
    ctx->pc = 0x1CADBCu;
label_1cadbc:
    // 0x1cadbc: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1cadbcu;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1cadc0: 0x2402005a  addiu       $v0, $zero, 0x5A
    ctx->pc = 0x1cadc0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 90));
    // 0x1cadc4: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1cadc4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1cadc8: 0xa2a30000  sb          $v1, 0x0($s5)
    ctx->pc = 0x1cadc8u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cadcc: 0xa6620000  sh          $v0, 0x0($s3)
    ctx->pc = 0x1cadccu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1cadd0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cadd0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cadd4:
    // 0x1cadd4: 0x1000009c  b           . + 4 + (0x9C << 2)
    ctx->pc = 0x1CADD4u;
    {
        const bool branch_taken_0x1cadd4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cadd4) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CADDCu;
label_1caddc:
    // 0x1caddc: 0x86630000  lh          $v1, 0x0($s3)
    ctx->pc = 0x1caddcu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1cade0: 0x62001a  div         $zero, $v1, $v0
    ctx->pc = 0x1cade0u;
    { int32_t divisor = GPR_S32(ctx, 2);    int32_t dividend = GPR_S32(ctx, 3);    if (divisor != 0) {        if (divisor == -1 && dividend == INT32_MIN) {            ctx->lo = (uint64_t)(int64_t)INT32_MIN; ctx->hi = 0;        } else {            ctx->lo = (uint64_t)(int64_t)(dividend / divisor);            ctx->hi = (uint64_t)(int64_t)(dividend % divisor);        }    } else {        ctx->lo = (dividend < 0) ? 1ull : 0xFFFFFFFFFFFFFFFFull; ctx->hi = (uint64_t)(int64_t)dividend;    } }
    // 0x1cade4: 0x0  nop
    ctx->pc = 0x1cade4u;
    // NOP
    // 0x1cade8: 0x0  nop
    ctx->pc = 0x1cade8u;
    // NOP
    // 0x1cadec: 0x1010  mfhi        $v0
    ctx->pc = 0x1cadecu;
    SET_GPR_U64(ctx, 2, ctx->hi);
    // 0x1cadf0: 0x1440000a  bnez        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1CADF0u;
    {
        const bool branch_taken_0x1cadf0 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CADF4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CADF0u;
            // 0x1cadf4: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cadf0) {
            ctx->pc = 0x1CAE1Cu;
            goto label_1cae1c;
        }
    }
    ctx->pc = 0x1CADF8u;
    // 0x1cadf8: 0x9023c6ee  lbu         $v1, -0x3912($at)
    ctx->pc = 0x1cadf8u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952686)));
    // 0x1cadfc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cadfcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cae00: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1cae00u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1cae04: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1cae04u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1cae08: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CAE08u;
    {
        const bool branch_taken_0x1cae08 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cae08) {
            ctx->pc = 0x1CAE14u;
            goto label_1cae14;
        }
    }
    ctx->pc = 0x1CAE10u;
    // 0x1cae10: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1cae10u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1cae14:
    // 0x1cae14: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cae14u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cae18: 0xa023c6ec  sb          $v1, -0x3914($at)
    ctx->pc = 0x1cae18u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 3));
label_1cae1c:
    // 0x1cae1c: 0x86620000  lh          $v0, 0x0($s3)
    ctx->pc = 0x1cae1cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x1cae20: 0x2442ffff  addiu       $v0, $v0, -0x1
    ctx->pc = 0x1cae20u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), 4294967295));
    // 0x1cae24: 0xa6620000  sh          $v0, 0x0($s3)
    ctx->pc = 0x1cae24u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x1cae28: 0x2143c  dsll32      $v0, $v0, 16
    ctx->pc = 0x1cae28u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) << (32 + 16));
    // 0x1cae2c: 0x2143f  dsra32      $v0, $v0, 16
    ctx->pc = 0x1cae2cu;
    SET_GPR_S64(ctx, 2, GPR_S64(ctx, 2) >> (32 + 16));
    // 0x1cae30: 0x2082a  slt         $at, $zero, $v0
    ctx->pc = 0x1cae30u;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 0) < (int64_t)GPR_S64(ctx, 2)) ? 1 : 0);
    // 0x1cae34: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CAE34u;
    {
        const bool branch_taken_0x1cae34 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAE38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAE34u;
            // 0x1cae38: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cae34) {
            ctx->pc = 0x1CAE44u;
            goto label_1cae44;
        }
    }
    ctx->pc = 0x1CAE3Cu;
    // 0x1cae3c: 0x10000082  b           . + 4 + (0x82 << 2)
    ctx->pc = 0x1CAE3Cu;
    {
        const bool branch_taken_0x1cae3c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cae3c) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAE44u;
label_1cae44:
    // 0x1cae44: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1cae44u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cae48: 0x24020064  addiu       $v0, $zero, 0x64
    ctx->pc = 0x1cae48u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
    // 0x1cae4c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cae4cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cae50: 0xa022c6ee  sb          $v0, -0x3912($at)
    ctx->pc = 0x1cae50u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cae54: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cae54u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cae58: 0x9022c6ec  lbu         $v0, -0x3914($at)
    ctx->pc = 0x1cae58u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1cae5c: 0x28410046  slti        $at, $v0, 0x46
    ctx->pc = 0x1cae5cu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)(int32_t)70) ? 1 : 0);
    // 0x1cae60: 0x10200003  beqz        $at, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CAE60u;
    {
        const bool branch_taken_0x1cae60 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAE64u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAE60u;
            // 0x1cae64: 0x24020046  addiu       $v0, $zero, 0x46 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 70));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cae60) {
            ctx->pc = 0x1CAE70u;
            goto label_1cae70;
        }
    }
    ctx->pc = 0x1CAE68u;
    // 0x1cae68: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cae68u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cae6c: 0xa022c6ec  sb          $v0, -0x3914($at)
    ctx->pc = 0x1cae6cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 2));
label_1cae70:
    // 0x1cae70: 0xc07254c  jal         func_1C9530
    ctx->pc = 0x1CAE70u;
    SET_GPR_U32(ctx, 31, 0x1CAE78u);
    ctx->pc = 0x1C9530u;
    if (runtime->hasFunction(0x1C9530u)) {
        auto targetFn = runtime->lookupFunction(0x1C9530u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAE78u; }
        if (ctx->pc != 0x1CAE78u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C9530_0x1c9530(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAE78u; }
        if (ctx->pc != 0x1CAE78u) { return; }
    }
    ctx->pc = 0x1CAE78u;
label_1cae78:
    // 0x1cae78: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1cae78u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1cae7c: 0xc075d98  jal         func_1D7660
    ctx->pc = 0x1CAE7Cu;
    SET_GPR_U32(ctx, 31, 0x1CAE84u);
    ctx->pc = 0x1CAE80u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAE7Cu;
            // 0x1cae80: 0x2484b660  addiu       $a0, $a0, -0x49A0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948448));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7660u;
    if (runtime->hasFunction(0x1D7660u)) {
        auto targetFn = runtime->lookupFunction(0x1D7660u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAE84u; }
        if (ctx->pc != 0x1CAE84u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7660_0x1d7660(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAE84u; }
        if (ctx->pc != 0x1CAE84u) { return; }
    }
    ctx->pc = 0x1CAE84u;
label_1cae84:
    // 0x1cae84: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CAE84u;
    {
        const bool branch_taken_0x1cae84 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1CAE88u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAE84u;
            // 0x1cae88: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cae84) {
            ctx->pc = 0x1CAEBCu;
            goto label_1caebc;
        }
    }
    ctx->pc = 0x1CAE8Cu;
    // 0x1cae8c: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1cae8cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1cae90: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1cae90u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cae94: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1cae94u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cae98: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1cae98u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cae9c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cae9cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1caea0: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1caea0u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caea4: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1caea4u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caea8: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1caea8u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caeac: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1caeacu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caeb0: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1caeb0u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caeb4: 0x10000064  b           . + 4 + (0x64 << 2)
    ctx->pc = 0x1CAEB4u;
    {
        const bool branch_taken_0x1caeb4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAEB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAEB4u;
            // 0x1caeb8: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caeb4) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAEBCu;
label_1caebc:
    // 0x1caebc: 0x8c22b660  lw          $v0, -0x49A0($at)
    ctx->pc = 0x1caebcu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294948448)));
    // 0x1caec0: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1caec0u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caec4: 0xac22c800  sw          $v0, -0x3800($at)
    ctx->pc = 0x1caec4u;
    WRITE32(ADD32(GPR_U32(ctx, 1), 4294952960), GPR_U32(ctx, 2));
    // 0x1caec8: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1caec8u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caecc: 0x8c25c800  lw          $a1, -0x3800($at)
    ctx->pc = 0x1caeccu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294952960)));
    // 0x1caed0: 0xc075d2c  jal         func_1D74B0
    ctx->pc = 0x1CAED0u;
    SET_GPR_U32(ctx, 31, 0x1CAED8u);
    ctx->pc = 0x1CAED4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAED0u;
            // 0x1caed4: 0x202d  daddu       $a0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D74B0u;
    if (runtime->hasFunction(0x1D74B0u)) {
        auto targetFn = runtime->lookupFunction(0x1D74B0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAED8u; }
        if (ctx->pc != 0x1CAED8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D74B0_0x1d74b0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAED8u; }
        if (ctx->pc != 0x1CAED8u) { return; }
    }
    ctx->pc = 0x1CAED8u;
label_1caed8:
    // 0x1caed8: 0x441000d  bgez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CAED8u;
    {
        const bool branch_taken_0x1caed8 = (GPR_S64(ctx, 2) >= 0);
        ctx->pc = 0x1CAEDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAED8u;
            // 0x1caedc: 0x2403001e  addiu       $v1, $zero, 0x1E (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 30));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caed8) {
            ctx->pc = 0x1CAF10u;
            goto label_1caf10;
        }
    }
    ctx->pc = 0x1CAEE0u;
    // 0x1caee0: 0x2402ffae  addiu       $v0, $zero, -0x52
    ctx->pc = 0x1caee0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967214));
    // 0x1caee4: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1caee4u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1caee8: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1caee8u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1caeec: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1caeecu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1caef0: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1caef0u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1caef4: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1caef4u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caef8: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1caef8u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caefc: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1caefcu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caf00: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1caf00u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caf04: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1caf04u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caf08: 0x1000004f  b           . + 4 + (0x4F << 2)
    ctx->pc = 0x1CAF08u;
    {
        const bool branch_taken_0x1caf08 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAF0Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAF08u;
            // 0x1caf0c: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caf08) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAF10u;
label_1caf10:
    // 0x1caf10: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1caf10u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1caf14: 0x1000004c  b           . + 4 + (0x4C << 2)
    ctx->pc = 0x1CAF14u;
    {
        const bool branch_taken_0x1caf14 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAF18u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAF14u;
            // 0x1caf18: 0xa2a30000  sb          $v1, 0x0($s5) (Delay Slot)
        WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caf14) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAF1Cu;
label_1caf1c:
    // 0x1caf1c: 0xc075ce4  jal         func_1D7390
    ctx->pc = 0x1CAF1Cu;
    SET_GPR_U32(ctx, 31, 0x1CAF24u);
    ctx->pc = 0x1D7390u;
    if (runtime->hasFunction(0x1D7390u)) {
        auto targetFn = runtime->lookupFunction(0x1D7390u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAF24u; }
        if (ctx->pc != 0x1CAF24u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7390_0x1d7390(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAF24u; }
        if (ctx->pc != 0x1CAF24u) { return; }
    }
    ctx->pc = 0x1CAF24u;
label_1caf24:
    // 0x1caf24: 0x3c040034  lui         $a0, 0x34
    ctx->pc = 0x1caf24u;
    SET_GPR_S32(ctx, 4, (int32_t)((uint32_t)52 << 16));
    // 0x1caf28: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1caf28u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caf2c: 0x2484b668  addiu       $a0, $a0, -0x4998
    ctx->pc = 0x1caf2cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), 4294948456));
    // 0x1caf30: 0xc075d00  jal         func_1D7400
    ctx->pc = 0x1CAF30u;
    SET_GPR_U32(ctx, 31, 0x1CAF38u);
    ctx->pc = 0x1CAF34u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAF30u;
            // 0x1caf34: 0xac20b668  sw          $zero, -0x4998($at) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 1), 4294948456), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1D7400u;
    if (runtime->hasFunction(0x1D7400u)) {
        auto targetFn = runtime->lookupFunction(0x1D7400u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAF38u; }
        if (ctx->pc != 0x1CAF38u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001D7400_0x1d7400(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CAF38u; }
        if (ctx->pc != 0x1CAF38u) { return; }
    }
    ctx->pc = 0x1CAF38u;
label_1caf38:
    // 0x1caf38: 0x4400004  bltz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x1CAF38u;
    {
        const bool branch_taken_0x1caf38 = (GPR_S64(ctx, 2) < 0);
        ctx->pc = 0x1CAF3Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAF38u;
            // 0x1caf3c: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caf38) {
            ctx->pc = 0x1CAF4Cu;
            goto label_1caf4c;
        }
    }
    ctx->pc = 0x1CAF40u;
    // 0x1caf40: 0x8c22b668  lw          $v0, -0x4998($at)
    ctx->pc = 0x1caf40u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 1), 4294948456)));
    // 0x1caf44: 0x1440000d  bnez        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CAF44u;
    {
        const bool branch_taken_0x1caf44 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        ctx->pc = 0x1CAF48u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAF44u;
            // 0x1caf48: 0x24030064  addiu       $v1, $zero, 0x64 (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 100));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caf44) {
            ctx->pc = 0x1CAF7Cu;
            goto label_1caf7c;
        }
    }
    ctx->pc = 0x1CAF4Cu;
label_1caf4c:
    // 0x1caf4c: 0x2402ffad  addiu       $v0, $zero, -0x53
    ctx->pc = 0x1caf4cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967213));
    // 0x1caf50: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1caf50u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1caf54: 0xa2e20000  sb          $v0, 0x0($s7)
    ctx->pc = 0x1caf54u;
    WRITE8(ADD32(GPR_U32(ctx, 23), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1caf58: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x1caf58u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1caf5c: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1caf5cu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1caf60: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1caf60u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caf64: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1caf64u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caf68: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1caf68u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caf6c: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1caf6cu;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caf70: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1caf70u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1caf74: 0x10000034  b           . + 4 + (0x34 << 2)
    ctx->pc = 0x1CAF74u;
    {
        const bool branch_taken_0x1caf74 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAF78u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAF74u;
            // 0x1caf78: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caf74) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAF7Cu;
label_1caf7c:
    // 0x1caf7c: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1caf7cu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caf80: 0xa023c6ee  sb          $v1, -0x3912($at)
    ctx->pc = 0x1caf80u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 3));
    // 0x1caf84: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1caf84u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1caf88: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1caf88u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1caf8c: 0xa023c6ec  sb          $v1, -0x3914($at)
    ctx->pc = 0x1caf8cu;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 3));
    // 0x1caf90: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1caf90u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1caf94: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1caf94u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1caf98: 0xa2a30000  sb          $v1, 0x0($s5)
    ctx->pc = 0x1caf98u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1caf9c: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1caf9cu;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cafa0: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1cafa0u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cafa4: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1cafa4u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cafa8: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1cafa8u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cafac: 0x10000026  b           . + 4 + (0x26 << 2)
    ctx->pc = 0x1CAFACu;
    {
        const bool branch_taken_0x1cafac = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAFB0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAFACu;
            // 0x1cafb0: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cafac) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAFB4u;
label_1cafb4:
    // 0x1cafb4: 0x9022c6ed  lbu         $v0, -0x3913($at)
    ctx->pc = 0x1cafb4u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952685)));
    // 0x1cafb8: 0x14440009  bne         $v0, $a0, . + 4 + (0x9 << 2)
    ctx->pc = 0x1CAFB8u;
    {
        const bool branch_taken_0x1cafb8 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 4));
        ctx->pc = 0x1CAFBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAFB8u;
            // 0x1cafbc: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cafb8) {
            ctx->pc = 0x1CAFE0u;
            goto label_1cafe0;
        }
    }
    ctx->pc = 0x1CAFC0u;
    // 0x1cafc0: 0xa2c00000  sb          $zero, 0x0($s6)
    ctx->pc = 0x1cafc0u;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cafc4: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x1cafc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1cafc8: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1cafc8u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cafcc: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1cafccu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cafd0: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1cafd0u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cafd4: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1cafd4u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cafd8: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x1CAFD8u;
    {
        const bool branch_taken_0x1cafd8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAFDCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAFD8u;
            // 0x1cafdc: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cafd8) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAFE0u;
label_1cafe0:
    // 0x1cafe0: 0x10000019  b           . + 4 + (0x19 << 2)
    ctx->pc = 0x1CAFE0u;
    {
        const bool branch_taken_0x1cafe0 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cafe0) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CAFE8u;
label_1cafe8:
    // 0x1cafe8: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1cafe8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1cafec: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cafecu;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1caff0: 0xa2a30000  sb          $v1, 0x0($s5)
    ctx->pc = 0x1caff0u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1caff4: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1caff4u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1caff8: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1CAFF8u;
    {
        const bool branch_taken_0x1caff8 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CAFFCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CAFF8u;
            // 0x1caffc: 0xa6600000  sh          $zero, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1caff8) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CB000u;
label_1cb000:
    // 0x1cb000: 0x280202d  daddu       $a0, $s4, $zero
    ctx->pc = 0x1cb000u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb004: 0xc072c60  jal         func_1CB180
    ctx->pc = 0x1CB004u;
    SET_GPR_U32(ctx, 31, 0x1CB00Cu);
    ctx->pc = 0x1CB008u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB004u;
            // 0x1cb008: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CB180u;
    if (runtime->hasFunction(0x1CB180u)) {
        auto targetFn = runtime->lookupFunction(0x1CB180u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB00Cu; }
        if (ctx->pc != 0x1CB00Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CB180_0x1cb180(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB00Cu; }
        if (ctx->pc != 0x1CB00Cu) { return; }
    }
    ctx->pc = 0x1CB00Cu;
label_1cb00c:
    // 0x1cb00c: 0x1040000d  beqz        $v0, . + 4 + (0xD << 2)
    ctx->pc = 0x1CB00Cu;
    {
        const bool branch_taken_0x1cb00c = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB010u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB00Cu;
            // 0x1cb010: 0x3c010034  lui         $at, 0x34 (Delay Slot)
        SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb00c) {
            ctx->pc = 0x1CB044u;
            goto label_1cb044;
        }
    }
    ctx->pc = 0x1CB014u;
    // 0x1cb014: 0x2402000a  addiu       $v0, $zero, 0xA
    ctx->pc = 0x1cb014u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 10));
    // 0x1cb018: 0xa020c6ec  sb          $zero, -0x3914($at)
    ctx->pc = 0x1cb018u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952684), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cb01c: 0x2403005a  addiu       $v1, $zero, 0x5A
    ctx->pc = 0x1cb01cu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 90));
    // 0x1cb020: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb020u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb024: 0xa022c6ee  sb          $v0, -0x3912($at)
    ctx->pc = 0x1cb024u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952686), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cb028: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cb028u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cb02c: 0xa2a20000  sb          $v0, 0x0($s5)
    ctx->pc = 0x1cb02cu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 2));
    // 0x1cb030: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1cb030u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cb034: 0x24020005  addiu       $v0, $zero, 0x5
    ctx->pc = 0x1cb034u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 5));
    // 0x1cb038: 0xa6630000  sh          $v1, 0x0($s3)
    ctx->pc = 0x1cb038u;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1cb03c: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1CB03Cu;
    {
        const bool branch_taken_0x1cb03c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB040u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB03Cu;
            // 0x1cb040: 0xa6400000  sh          $zero, 0x0($s2) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb03c) {
            ctx->pc = 0x1CB048u;
            goto label_1cb048;
        }
    }
    ctx->pc = 0x1CB044u;
label_1cb044:
    // 0x1cb044: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cb044u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cb048:
    // 0x1cb048: 0xdfbf0080  ld          $ra, 0x80($sp)
    ctx->pc = 0x1cb048u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 128)));
label_1cb04c:
    // 0x1cb04c: 0x7bb70070  lq          $s7, 0x70($sp)
    ctx->pc = 0x1cb04cu;
    SET_GPR_VEC(ctx, 23, READ128(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1cb050: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1cb050u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1cb054: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1cb054u;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1cb058: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1cb058u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1cb05c: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1cb05cu;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1cb060: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1cb060u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cb064: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cb064u;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cb068: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cb068u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cb06c: 0x3e00008  jr          $ra
    ctx->pc = 0x1CB06Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CB070u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB06Cu;
            // 0x1cb070: 0x27bd0090  addiu       $sp, $sp, 0x90 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 144));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C97F0u: goto label_1c97f0;
            case 0x1C982Cu: goto label_1c982c;
            case 0x1C9834u: goto label_1c9834;
            case 0x1C983Cu: goto label_1c983c;
            case 0x1C9844u: goto label_1c9844;
            case 0x1C984Cu: goto label_1c984c;
            case 0x1C98E8u: goto label_1c98e8;
            case 0x1C9924u: goto label_1c9924;
            case 0x1C999Cu: goto label_1c999c;
            case 0x1C99D4u: goto label_1c99d4;
            case 0x1C99F0u: goto label_1c99f0;
            case 0x1C9A74u: goto label_1c9a74;
            case 0x1C9A88u: goto label_1c9a88;
            case 0x1C9AECu: goto label_1c9aec;
            case 0x1C9AF4u: goto label_1c9af4;
            case 0x1C9B00u: goto label_1c9b00;
            case 0x1C9B04u: goto label_1c9b04;
            case 0x1C9B08u: goto label_1c9b08;
            case 0x1C9B10u: goto label_1c9b10;
            case 0x1C9B28u: goto label_1c9b28;
            case 0x1C9C4Cu: goto label_1c9c4c;
            case 0x1C9C64u: goto label_1c9c64;
            case 0x1C9C78u: goto label_1c9c78;
            case 0x1C9C90u: goto label_1c9c90;
            case 0x1C9CACu: goto label_1c9cac;
            case 0x1C9CCCu: goto label_1c9ccc;
            case 0x1C9D04u: goto label_1c9d04;
            case 0x1C9D18u: goto label_1c9d18;
            case 0x1C9D20u: goto label_1c9d20;
            case 0x1C9D58u: goto label_1c9d58;
            case 0x1C9D68u: goto label_1c9d68;
            case 0x1C9D80u: goto label_1c9d80;
            case 0x1C9DA4u: goto label_1c9da4;
            case 0x1C9DACu: goto label_1c9dac;
            case 0x1C9DFCu: goto label_1c9dfc;
            case 0x1C9E08u: goto label_1c9e08;
            case 0x1C9E40u: goto label_1c9e40;
            case 0x1C9E50u: goto label_1c9e50;
            case 0x1C9E6Cu: goto label_1c9e6c;
            case 0x1C9EACu: goto label_1c9eac;
            case 0x1C9EC0u: goto label_1c9ec0;
            case 0x1C9EFCu: goto label_1c9efc;
            case 0x1C9F38u: goto label_1c9f38;
            case 0x1C9F40u: goto label_1c9f40;
            case 0x1C9F5Cu: goto label_1c9f5c;
            case 0x1C9F6Cu: goto label_1c9f6c;
            case 0x1C9FA4u: goto label_1c9fa4;
            case 0x1C9FD0u: goto label_1c9fd0;
            case 0x1CA000u: goto label_1ca000;
            case 0x1CA02Cu: goto label_1ca02c;
            case 0x1CA058u: goto label_1ca058;
            case 0x1CA080u: goto label_1ca080;
            case 0x1CA090u: goto label_1ca090;
            case 0x1CA0ECu: goto label_1ca0ec;
            case 0x1CA0F4u: goto label_1ca0f4;
            case 0x1CA108u: goto label_1ca108;
            case 0x1CA130u: goto label_1ca130;
            case 0x1CA178u: goto label_1ca178;
            case 0x1CA180u: goto label_1ca180;
            case 0x1CA1C8u: goto label_1ca1c8;
            case 0x1CA1D0u: goto label_1ca1d0;
            case 0x1CA1D8u: goto label_1ca1d8;
            case 0x1CA1ECu: goto label_1ca1ec;
            case 0x1CA214u: goto label_1ca214;
            case 0x1CA23Cu: goto label_1ca23c;
            case 0x1CA264u: goto label_1ca264;
            case 0x1CA28Cu: goto label_1ca28c;
            case 0x1CA2ACu: goto label_1ca2ac;
            case 0x1CA2B8u: goto label_1ca2b8;
            case 0x1CA2DCu: goto label_1ca2dc;
            case 0x1CA2E0u: goto label_1ca2e0;
            case 0x1CA2ECu: goto label_1ca2ec;
            case 0x1CA308u: goto label_1ca308;
            case 0x1CA310u: goto label_1ca310;
            case 0x1CA318u: goto label_1ca318;
            case 0x1CA330u: goto label_1ca330;
            case 0x1CA35Cu: goto label_1ca35c;
            case 0x1CA364u: goto label_1ca364;
            case 0x1CA378u: goto label_1ca378;
            case 0x1CA384u: goto label_1ca384;
            case 0x1CA3BCu: goto label_1ca3bc;
            case 0x1CA3C0u: goto label_1ca3c0;
            case 0x1CA3C4u: goto label_1ca3c4;
            case 0x1CA43Cu: goto label_1ca43c;
            case 0x1CA474u: goto label_1ca474;
            case 0x1CA490u: goto label_1ca490;
            case 0x1CA558u: goto label_1ca558;
            case 0x1CA57Cu: goto label_1ca57c;
            case 0x1CA598u: goto label_1ca598;
            case 0x1CA5C0u: goto label_1ca5c0;
            case 0x1CA5D8u: goto label_1ca5d8;
            case 0x1CA610u: goto label_1ca610;
            case 0x1CA624u: goto label_1ca624;
            case 0x1CA630u: goto label_1ca630;
            case 0x1CA668u: goto label_1ca668;
            case 0x1CA688u: goto label_1ca688;
            case 0x1CA690u: goto label_1ca690;
            case 0x1CA694u: goto label_1ca694;
            case 0x1CA698u: goto label_1ca698;
            case 0x1CA6A0u: goto label_1ca6a0;
            case 0x1CA6C0u: goto label_1ca6c0;
            case 0x1CA6ECu: goto label_1ca6ec;
            case 0x1CA724u: goto label_1ca724;
            case 0x1CA738u: goto label_1ca738;
            case 0x1CA740u: goto label_1ca740;
            case 0x1CA778u: goto label_1ca778;
            case 0x1CA790u: goto label_1ca790;
            case 0x1CA7D0u: goto label_1ca7d0;
            case 0x1CA808u: goto label_1ca808;
            case 0x1CA810u: goto label_1ca810;
            case 0x1CA820u: goto label_1ca820;
            case 0x1CA84Cu: goto label_1ca84c;
            case 0x1CA86Cu: goto label_1ca86c;
            case 0x1CA8B8u: goto label_1ca8b8;
            case 0x1CA8C8u: goto label_1ca8c8;
            case 0x1CA8CCu: goto label_1ca8cc;
            case 0x1CA8D4u: goto label_1ca8d4;
            case 0x1CA914u: goto label_1ca914;
            case 0x1CA94Cu: goto label_1ca94c;
            case 0x1CA954u: goto label_1ca954;
            case 0x1CA970u: goto label_1ca970;
            case 0x1CA99Cu: goto label_1ca99c;
            case 0x1CA9A4u: goto label_1ca9a4;
            case 0x1CA9B4u: goto label_1ca9b4;
            case 0x1CA9ECu: goto label_1ca9ec;
            case 0x1CA9F8u: goto label_1ca9f8;
            case 0x1CAA18u: goto label_1caa18;
            case 0x1CAA24u: goto label_1caa24;
            case 0x1CAA5Cu: goto label_1caa5c;
            case 0x1CAA74u: goto label_1caa74;
            case 0x1CAAB4u: goto label_1caab4;
            case 0x1CAAECu: goto label_1caaec;
            case 0x1CAAF4u: goto label_1caaf4;
            case 0x1CAB04u: goto label_1cab04;
            case 0x1CAB30u: goto label_1cab30;
            case 0x1CAB48u: goto label_1cab48;
            case 0x1CAB94u: goto label_1cab94;
            case 0x1CABA4u: goto label_1caba4;
            case 0x1CABA8u: goto label_1caba8;
            case 0x1CABB0u: goto label_1cabb0;
            case 0x1CABB8u: goto label_1cabb8;
            case 0x1CABF0u: goto label_1cabf0;
            case 0x1CABF8u: goto label_1cabf8;
            case 0x1CAC30u: goto label_1cac30;
            case 0x1CAC48u: goto label_1cac48;
            case 0x1CAC60u: goto label_1cac60;
            case 0x1CAC90u: goto label_1cac90;
            case 0x1CACC8u: goto label_1cacc8;
            case 0x1CACD0u: goto label_1cacd0;
            case 0x1CACE0u: goto label_1cace0;
            case 0x1CAD00u: goto label_1cad00;
            case 0x1CAD2Cu: goto label_1cad2c;
            case 0x1CAD34u: goto label_1cad34;
            case 0x1CAD48u: goto label_1cad48;
            case 0x1CAD50u: goto label_1cad50;
            case 0x1CAD60u: goto label_1cad60;
            case 0x1CAD88u: goto label_1cad88;
            case 0x1CAD90u: goto label_1cad90;
            case 0x1CADBCu: goto label_1cadbc;
            case 0x1CADD4u: goto label_1cadd4;
            case 0x1CADDCu: goto label_1caddc;
            case 0x1CAE14u: goto label_1cae14;
            case 0x1CAE1Cu: goto label_1cae1c;
            case 0x1CAE44u: goto label_1cae44;
            case 0x1CAE70u: goto label_1cae70;
            case 0x1CAE78u: goto label_1cae78;
            case 0x1CAE84u: goto label_1cae84;
            case 0x1CAEBCu: goto label_1caebc;
            case 0x1CAED8u: goto label_1caed8;
            case 0x1CAF10u: goto label_1caf10;
            case 0x1CAF1Cu: goto label_1caf1c;
            case 0x1CAF24u: goto label_1caf24;
            case 0x1CAF38u: goto label_1caf38;
            case 0x1CAF4Cu: goto label_1caf4c;
            case 0x1CAF7Cu: goto label_1caf7c;
            case 0x1CAFB4u: goto label_1cafb4;
            case 0x1CAFE0u: goto label_1cafe0;
            case 0x1CAFE8u: goto label_1cafe8;
            case 0x1CB000u: goto label_1cb000;
            case 0x1CB00Cu: goto label_1cb00c;
            case 0x1CB044u: goto label_1cb044;
            case 0x1CB048u: goto label_1cb048;
            case 0x1CB04Cu: goto label_1cb04c;
            case 0x1CB0DCu: goto label_1cb0dc;
            case 0x1CB104u: goto label_1cb104;
            case 0x1CB11Cu: goto label_1cb11c;
            case 0x1CB124u: goto label_1cb124;
            case 0x1CB150u: goto label_1cb150;
            case 0x1CB154u: goto label_1cb154;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CB074u;
    // 0x1cb074: 0x0  nop
    ctx->pc = 0x1cb074u;
    // NOP
    // 0x1cb078: 0x0  nop
    ctx->pc = 0x1cb078u;
    // NOP
    // 0x1cb07c: 0x0  nop
    ctx->pc = 0x1cb07cu;
    // NOP
    // 0x1cb080: 0x27bdff80  addiu       $sp, $sp, -0x80
    ctx->pc = 0x1cb080u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967168));
    // 0x1cb084: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb084u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb088: 0xffbf0070  sd          $ra, 0x70($sp)
    ctx->pc = 0x1cb088u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 112), GPR_U64(ctx, 31));
    // 0x1cb08c: 0x7fb60060  sq          $s6, 0x60($sp)
    ctx->pc = 0x1cb08cu;
    WRITE128(ADD32(GPR_U32(ctx, 29), 96), GPR_VEC(ctx, 22));
    // 0x1cb090: 0x7fb50050  sq          $s5, 0x50($sp)
    ctx->pc = 0x1cb090u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 80), GPR_VEC(ctx, 21));
    // 0x1cb094: 0x80b02d  daddu       $s6, $a0, $zero
    ctx->pc = 0x1cb094u;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb098: 0x7fb40040  sq          $s4, 0x40($sp)
    ctx->pc = 0x1cb098u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 64), GPR_VEC(ctx, 20));
    // 0x1cb09c: 0xa0a82d  daddu       $s5, $a1, $zero
    ctx->pc = 0x1cb09cu;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb0a0: 0x7fb30030  sq          $s3, 0x30($sp)
    ctx->pc = 0x1cb0a0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 48), GPR_VEC(ctx, 19));
    // 0x1cb0a4: 0xc0a02d  daddu       $s4, $a2, $zero
    ctx->pc = 0x1cb0a4u;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb0a8: 0x7fb20020  sq          $s2, 0x20($sp)
    ctx->pc = 0x1cb0a8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 32), GPR_VEC(ctx, 18));
    // 0x1cb0ac: 0xe0982d  daddu       $s3, $a3, $zero
    ctx->pc = 0x1cb0acu;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb0b0: 0x7fb10010  sq          $s1, 0x10($sp)
    ctx->pc = 0x1cb0b0u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 16), GPR_VEC(ctx, 17));
    // 0x1cb0b4: 0x100902d  daddu       $s2, $t0, $zero
    ctx->pc = 0x1cb0b4u;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb0b8: 0x7fb00000  sq          $s0, 0x0($sp)
    ctx->pc = 0x1cb0b8u;
    WRITE128(ADD32(GPR_U32(ctx, 29), 0), GPR_VEC(ctx, 16));
    // 0x1cb0bc: 0x120882d  daddu       $s1, $t1, $zero
    ctx->pc = 0x1cb0bcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb0c0: 0x9023c6ec  lbu         $v1, -0x3914($at)
    ctx->pc = 0x1cb0c0u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952684)));
    // 0x1cb0c4: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb0c4u;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb0c8: 0x9022c6ed  lbu         $v0, -0x3913($at)
    ctx->pc = 0x1cb0c8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 1), 4294952685)));
    // 0x1cb0cc: 0x43082a  slt         $at, $v0, $v1
    ctx->pc = 0x1cb0ccu;
    SET_GPR_U64(ctx, 1, ((int64_t)GPR_S64(ctx, 2) < (int64_t)GPR_S64(ctx, 3)) ? 1 : 0);
    // 0x1cb0d0: 0x10200002  beqz        $at, . + 4 + (0x2 << 2)
    ctx->pc = 0x1CB0D0u;
    {
        const bool branch_taken_0x1cb0d0 = (GPR_U64(ctx, 1) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB0D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB0D0u;
            // 0x1cb0d4: 0x140802d  daddu       $s0, $t2, $zero (Delay Slot)
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb0d0) {
            ctx->pc = 0x1CB0DCu;
            goto label_1cb0dc;
        }
    }
    ctx->pc = 0x1CB0D8u;
    // 0x1cb0d8: 0x24430001  addiu       $v1, $v0, 0x1
    ctx->pc = 0x1cb0d8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 2), 1));
label_1cb0dc:
    // 0x1cb0dc: 0x3c010034  lui         $at, 0x34
    ctx->pc = 0x1cb0dcu;
    SET_GPR_S32(ctx, 1, (int32_t)((uint32_t)52 << 16));
    // 0x1cb0e0: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1cb0e0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1cb0e4: 0xa023c6ed  sb          $v1, -0x3913($at)
    ctx->pc = 0x1cb0e4u;
    WRITE8(ADD32(GPR_U32(ctx, 1), 4294952685), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cb0e8: 0x82a30000  lb          $v1, 0x0($s5)
    ctx->pc = 0x1cb0e8u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 21), 0)));
    // 0x1cb0ec: 0x1062000b  beq         $v1, $v0, . + 4 + (0xB << 2)
    ctx->pc = 0x1CB0ECu;
    {
        const bool branch_taken_0x1cb0ec = (GPR_U64(ctx, 3) == GPR_U64(ctx, 2));
        ctx->pc = 0x1CB0F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB0ECu;
            // 0x1cb0f0: 0x280202d  daddu       $a0, $s4, $zero (Delay Slot)
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 20) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb0ec) {
            ctx->pc = 0x1CB11Cu;
            goto label_1cb11c;
        }
    }
    ctx->pc = 0x1CB0F4u;
    // 0x1cb0f4: 0x10600003  beqz        $v1, . + 4 + (0x3 << 2)
    ctx->pc = 0x1CB0F4u;
    {
        const bool branch_taken_0x1cb0f4 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cb0f4) {
            ctx->pc = 0x1CB104u;
            goto label_1cb104;
        }
    }
    ctx->pc = 0x1CB0FCu;
    // 0x1cb0fc: 0x10000015  b           . + 4 + (0x15 << 2)
    ctx->pc = 0x1CB0FCu;
    {
        const bool branch_taken_0x1cb0fc = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB100u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB0FCu;
            // 0x1cb100: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb0fc) {
            ctx->pc = 0x1CB154u;
            goto label_1cb154;
        }
    }
    ctx->pc = 0x1CB104u;
label_1cb104:
    // 0x1cb104: 0x24630001  addiu       $v1, $v1, 0x1
    ctx->pc = 0x1cb104u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), 1));
    // 0x1cb108: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cb108u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1cb10c: 0xa2a30000  sb          $v1, 0x0($s5)
    ctx->pc = 0x1cb10cu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x1cb110: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1cb110u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cb114: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x1CB114u;
    {
        const bool branch_taken_0x1cb114 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB118u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB114u;
            // 0x1cb118: 0xa6600000  sh          $zero, 0x0($s3) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb114) {
            ctx->pc = 0x1CB154u;
            goto label_1cb154;
        }
    }
    ctx->pc = 0x1CB11Cu;
label_1cb11c:
    // 0x1cb11c: 0xc072c60  jal         func_1CB180
    ctx->pc = 0x1CB11Cu;
    SET_GPR_U32(ctx, 31, 0x1CB124u);
    ctx->pc = 0x1CB120u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB11Cu;
            // 0x1cb120: 0x260282d  daddu       $a1, $s3, $zero (Delay Slot)
        SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1CB180u;
    if (runtime->hasFunction(0x1CB180u)) {
        auto targetFn = runtime->lookupFunction(0x1CB180u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB124u; }
        if (ctx->pc != 0x1CB124u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001CB180_0x1cb180(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CB124u; }
        if (ctx->pc != 0x1CB124u) { return; }
    }
    ctx->pc = 0x1CB124u;
label_1cb124:
    // 0x1cb124: 0x1040000a  beqz        $v0, . + 4 + (0xA << 2)
    ctx->pc = 0x1CB124u;
    {
        const bool branch_taken_0x1cb124 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        if (branch_taken_0x1cb124) {
            ctx->pc = 0x1CB150u;
            goto label_1cb150;
        }
    }
    ctx->pc = 0x1CB12Cu;
    // 0x1cb12c: 0xa2c00000  sb          $zero, 0x0($s6)
    ctx->pc = 0x1cb12cu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cb130: 0x24020004  addiu       $v0, $zero, 0x4
    ctx->pc = 0x1cb130u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x1cb134: 0xa2a00000  sb          $zero, 0x0($s5)
    ctx->pc = 0x1cb134u;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cb138: 0xa2800000  sb          $zero, 0x0($s4)
    ctx->pc = 0x1cb138u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 0));
    // 0x1cb13c: 0xa6600000  sh          $zero, 0x0($s3)
    ctx->pc = 0x1cb13cu;
    WRITE16(ADD32(GPR_U32(ctx, 19), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cb140: 0xa6400000  sh          $zero, 0x0($s2)
    ctx->pc = 0x1cb140u;
    WRITE16(ADD32(GPR_U32(ctx, 18), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cb144: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x1cb144u;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x1cb148: 0x10000002  b           . + 4 + (0x2 << 2)
    ctx->pc = 0x1CB148u;
    {
        const bool branch_taken_0x1cb148 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1CB14Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB148u;
            // 0x1cb14c: 0xa6000000  sh          $zero, 0x0($s0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 16), 0), (uint16_t)GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1cb148) {
            ctx->pc = 0x1CB154u;
            goto label_1cb154;
        }
    }
    ctx->pc = 0x1CB150u;
label_1cb150:
    // 0x1cb150: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1cb150u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_1cb154:
    // 0x1cb154: 0xdfbf0070  ld          $ra, 0x70($sp)
    ctx->pc = 0x1cb154u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 112)));
    // 0x1cb158: 0x7bb60060  lq          $s6, 0x60($sp)
    ctx->pc = 0x1cb158u;
    SET_GPR_VEC(ctx, 22, READ128(ADD32(GPR_U32(ctx, 29), 96)));
    // 0x1cb15c: 0x7bb50050  lq          $s5, 0x50($sp)
    ctx->pc = 0x1cb15cu;
    SET_GPR_VEC(ctx, 21, READ128(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x1cb160: 0x7bb40040  lq          $s4, 0x40($sp)
    ctx->pc = 0x1cb160u;
    SET_GPR_VEC(ctx, 20, READ128(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x1cb164: 0x7bb30030  lq          $s3, 0x30($sp)
    ctx->pc = 0x1cb164u;
    SET_GPR_VEC(ctx, 19, READ128(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x1cb168: 0x7bb20020  lq          $s2, 0x20($sp)
    ctx->pc = 0x1cb168u;
    SET_GPR_VEC(ctx, 18, READ128(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x1cb16c: 0x7bb10010  lq          $s1, 0x10($sp)
    ctx->pc = 0x1cb16cu;
    SET_GPR_VEC(ctx, 17, READ128(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1cb170: 0x7bb00000  lq          $s0, 0x0($sp)
    ctx->pc = 0x1cb170u;
    SET_GPR_VEC(ctx, 16, READ128(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x1cb174: 0x3e00008  jr          $ra
    ctx->pc = 0x1CB174u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1CB178u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1CB174u;
            // 0x1cb178: 0x27bd0080  addiu       $sp, $sp, 0x80 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 128));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1C97F0u: goto label_1c97f0;
            case 0x1C982Cu: goto label_1c982c;
            case 0x1C9834u: goto label_1c9834;
            case 0x1C983Cu: goto label_1c983c;
            case 0x1C9844u: goto label_1c9844;
            case 0x1C984Cu: goto label_1c984c;
            case 0x1C98E8u: goto label_1c98e8;
            case 0x1C9924u: goto label_1c9924;
            case 0x1C999Cu: goto label_1c999c;
            case 0x1C99D4u: goto label_1c99d4;
            case 0x1C99F0u: goto label_1c99f0;
            case 0x1C9A74u: goto label_1c9a74;
            case 0x1C9A88u: goto label_1c9a88;
            case 0x1C9AECu: goto label_1c9aec;
            case 0x1C9AF4u: goto label_1c9af4;
            case 0x1C9B00u: goto label_1c9b00;
            case 0x1C9B04u: goto label_1c9b04;
            case 0x1C9B08u: goto label_1c9b08;
            case 0x1C9B10u: goto label_1c9b10;
            case 0x1C9B28u: goto label_1c9b28;
            case 0x1C9C4Cu: goto label_1c9c4c;
            case 0x1C9C64u: goto label_1c9c64;
            case 0x1C9C78u: goto label_1c9c78;
            case 0x1C9C90u: goto label_1c9c90;
            case 0x1C9CACu: goto label_1c9cac;
            case 0x1C9CCCu: goto label_1c9ccc;
            case 0x1C9D04u: goto label_1c9d04;
            case 0x1C9D18u: goto label_1c9d18;
            case 0x1C9D20u: goto label_1c9d20;
            case 0x1C9D58u: goto label_1c9d58;
            case 0x1C9D68u: goto label_1c9d68;
            case 0x1C9D80u: goto label_1c9d80;
            case 0x1C9DA4u: goto label_1c9da4;
            case 0x1C9DACu: goto label_1c9dac;
            case 0x1C9DFCu: goto label_1c9dfc;
            case 0x1C9E08u: goto label_1c9e08;
            case 0x1C9E40u: goto label_1c9e40;
            case 0x1C9E50u: goto label_1c9e50;
            case 0x1C9E6Cu: goto label_1c9e6c;
            case 0x1C9EACu: goto label_1c9eac;
            case 0x1C9EC0u: goto label_1c9ec0;
            case 0x1C9EFCu: goto label_1c9efc;
            case 0x1C9F38u: goto label_1c9f38;
            case 0x1C9F40u: goto label_1c9f40;
            case 0x1C9F5Cu: goto label_1c9f5c;
            case 0x1C9F6Cu: goto label_1c9f6c;
            case 0x1C9FA4u: goto label_1c9fa4;
            case 0x1C9FD0u: goto label_1c9fd0;
            case 0x1CA000u: goto label_1ca000;
            case 0x1CA02Cu: goto label_1ca02c;
            case 0x1CA058u: goto label_1ca058;
            case 0x1CA080u: goto label_1ca080;
            case 0x1CA090u: goto label_1ca090;
            case 0x1CA0ECu: goto label_1ca0ec;
            case 0x1CA0F4u: goto label_1ca0f4;
            case 0x1CA108u: goto label_1ca108;
            case 0x1CA130u: goto label_1ca130;
            case 0x1CA178u: goto label_1ca178;
            case 0x1CA180u: goto label_1ca180;
            case 0x1CA1C8u: goto label_1ca1c8;
            case 0x1CA1D0u: goto label_1ca1d0;
            case 0x1CA1D8u: goto label_1ca1d8;
            case 0x1CA1ECu: goto label_1ca1ec;
            case 0x1CA214u: goto label_1ca214;
            case 0x1CA23Cu: goto label_1ca23c;
            case 0x1CA264u: goto label_1ca264;
            case 0x1CA28Cu: goto label_1ca28c;
            case 0x1CA2ACu: goto label_1ca2ac;
            case 0x1CA2B8u: goto label_1ca2b8;
            case 0x1CA2DCu: goto label_1ca2dc;
            case 0x1CA2E0u: goto label_1ca2e0;
            case 0x1CA2ECu: goto label_1ca2ec;
            case 0x1CA308u: goto label_1ca308;
            case 0x1CA310u: goto label_1ca310;
            case 0x1CA318u: goto label_1ca318;
            case 0x1CA330u: goto label_1ca330;
            case 0x1CA35Cu: goto label_1ca35c;
            case 0x1CA364u: goto label_1ca364;
            case 0x1CA378u: goto label_1ca378;
            case 0x1CA384u: goto label_1ca384;
            case 0x1CA3BCu: goto label_1ca3bc;
            case 0x1CA3C0u: goto label_1ca3c0;
            case 0x1CA3C4u: goto label_1ca3c4;
            case 0x1CA43Cu: goto label_1ca43c;
            case 0x1CA474u: goto label_1ca474;
            case 0x1CA490u: goto label_1ca490;
            case 0x1CA558u: goto label_1ca558;
            case 0x1CA57Cu: goto label_1ca57c;
            case 0x1CA598u: goto label_1ca598;
            case 0x1CA5C0u: goto label_1ca5c0;
            case 0x1CA5D8u: goto label_1ca5d8;
            case 0x1CA610u: goto label_1ca610;
            case 0x1CA624u: goto label_1ca624;
            case 0x1CA630u: goto label_1ca630;
            case 0x1CA668u: goto label_1ca668;
            case 0x1CA688u: goto label_1ca688;
            case 0x1CA690u: goto label_1ca690;
            case 0x1CA694u: goto label_1ca694;
            case 0x1CA698u: goto label_1ca698;
            case 0x1CA6A0u: goto label_1ca6a0;
            case 0x1CA6C0u: goto label_1ca6c0;
            case 0x1CA6ECu: goto label_1ca6ec;
            case 0x1CA724u: goto label_1ca724;
            case 0x1CA738u: goto label_1ca738;
            case 0x1CA740u: goto label_1ca740;
            case 0x1CA778u: goto label_1ca778;
            case 0x1CA790u: goto label_1ca790;
            case 0x1CA7D0u: goto label_1ca7d0;
            case 0x1CA808u: goto label_1ca808;
            case 0x1CA810u: goto label_1ca810;
            case 0x1CA820u: goto label_1ca820;
            case 0x1CA84Cu: goto label_1ca84c;
            case 0x1CA86Cu: goto label_1ca86c;
            case 0x1CA8B8u: goto label_1ca8b8;
            case 0x1CA8C8u: goto label_1ca8c8;
            case 0x1CA8CCu: goto label_1ca8cc;
            case 0x1CA8D4u: goto label_1ca8d4;
            case 0x1CA914u: goto label_1ca914;
            case 0x1CA94Cu: goto label_1ca94c;
            case 0x1CA954u: goto label_1ca954;
            case 0x1CA970u: goto label_1ca970;
            case 0x1CA99Cu: goto label_1ca99c;
            case 0x1CA9A4u: goto label_1ca9a4;
            case 0x1CA9B4u: goto label_1ca9b4;
            case 0x1CA9ECu: goto label_1ca9ec;
            case 0x1CA9F8u: goto label_1ca9f8;
            case 0x1CAA18u: goto label_1caa18;
            case 0x1CAA24u: goto label_1caa24;
            case 0x1CAA5Cu: goto label_1caa5c;
            case 0x1CAA74u: goto label_1caa74;
            case 0x1CAAB4u: goto label_1caab4;
            case 0x1CAAECu: goto label_1caaec;
            case 0x1CAAF4u: goto label_1caaf4;
            case 0x1CAB04u: goto label_1cab04;
            case 0x1CAB30u: goto label_1cab30;
            case 0x1CAB48u: goto label_1cab48;
            case 0x1CAB94u: goto label_1cab94;
            case 0x1CABA4u: goto label_1caba4;
            case 0x1CABA8u: goto label_1caba8;
            case 0x1CABB0u: goto label_1cabb0;
            case 0x1CABB8u: goto label_1cabb8;
            case 0x1CABF0u: goto label_1cabf0;
            case 0x1CABF8u: goto label_1cabf8;
            case 0x1CAC30u: goto label_1cac30;
            case 0x1CAC48u: goto label_1cac48;
            case 0x1CAC60u: goto label_1cac60;
            case 0x1CAC90u: goto label_1cac90;
            case 0x1CACC8u: goto label_1cacc8;
            case 0x1CACD0u: goto label_1cacd0;
            case 0x1CACE0u: goto label_1cace0;
            case 0x1CAD00u: goto label_1cad00;
            case 0x1CAD2Cu: goto label_1cad2c;
            case 0x1CAD34u: goto label_1cad34;
            case 0x1CAD48u: goto label_1cad48;
            case 0x1CAD50u: goto label_1cad50;
            case 0x1CAD60u: goto label_1cad60;
            case 0x1CAD88u: goto label_1cad88;
            case 0x1CAD90u: goto label_1cad90;
            case 0x1CADBCu: goto label_1cadbc;
            case 0x1CADD4u: goto label_1cadd4;
            case 0x1CADDCu: goto label_1caddc;
            case 0x1CAE14u: goto label_1cae14;
            case 0x1CAE1Cu: goto label_1cae1c;
            case 0x1CAE44u: goto label_1cae44;
            case 0x1CAE70u: goto label_1cae70;
            case 0x1CAE78u: goto label_1cae78;
            case 0x1CAE84u: goto label_1cae84;
            case 0x1CAEBCu: goto label_1caebc;
            case 0x1CAED8u: goto label_1caed8;
            case 0x1CAF10u: goto label_1caf10;
            case 0x1CAF1Cu: goto label_1caf1c;
            case 0x1CAF24u: goto label_1caf24;
            case 0x1CAF38u: goto label_1caf38;
            case 0x1CAF4Cu: goto label_1caf4c;
            case 0x1CAF7Cu: goto label_1caf7c;
            case 0x1CAFB4u: goto label_1cafb4;
            case 0x1CAFE0u: goto label_1cafe0;
            case 0x1CAFE8u: goto label_1cafe8;
            case 0x1CB000u: goto label_1cb000;
            case 0x1CB00Cu: goto label_1cb00c;
            case 0x1CB044u: goto label_1cb044;
            case 0x1CB048u: goto label_1cb048;
            case 0x1CB04Cu: goto label_1cb04c;
            case 0x1CB0DCu: goto label_1cb0dc;
            case 0x1CB104u: goto label_1cb104;
            case 0x1CB11Cu: goto label_1cb11c;
            case 0x1CB124u: goto label_1cb124;
            case 0x1CB150u: goto label_1cb150;
            case 0x1CB154u: goto label_1cb154;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CB17Cu;
    // 0x1cb17c: 0x0  nop
    ctx->pc = 0x1cb17cu;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
