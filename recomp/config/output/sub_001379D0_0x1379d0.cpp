#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

// Function: sub_001379D0
// Address: 0x1379d0 - 0x137ba0
void sub_001379D0_0x1379d0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {

    ctx->pc = 0x1379d0u;

label_1379d0:
    // 0x1379d0: 0x27bdffe0
    ctx->pc = 0x1379d0u;
    SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 4294967264));
label_1379d4:
    // 0x1379d4: 0x24030001
    ctx->pc = 0x1379d4u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
label_1379d8:
    // 0x1379d8: 0xffb10008
    ctx->pc = 0x1379d8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
label_1379dc:
    // 0x1379dc: 0x80882d
    ctx->pc = 0x1379dcu;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
label_1379e0:
    // 0x1379e0: 0xffb00000
    ctx->pc = 0x1379e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
label_1379e4:
    // 0x1379e4: 0xffb20010
    ctx->pc = 0x1379e4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
label_1379e8:
    // 0x1379e8: 0xffbf0018
    ctx->pc = 0x1379e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
label_1379ec:
    // 0x1379ec: 0x8e220004
    ctx->pc = 0x1379ecu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 17), 4)));
label_1379f0:
    // 0x1379f0: 0x1443002c
label_1379f4:
    if (ctx->pc == 0x1379F4u) {
        ctx->pc = 0x1379F4u;
        SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
        ctx->pc = 0x1379F8u;
        goto label_1379f8;
    }
    ctx->pc = 0x1379F0u;
    {
        const bool branch_taken_0x1379f0 = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        ctx->pc = 0x1379F4u;
        SET_GPR_U32(ctx, 5, (uint8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
        if (branch_taken_0x1379f0) {
            ctx->pc = 0x137AA4u;
            goto label_137aa4;
        }
    }
    ctx->pc = 0x1379F8u;
label_1379f8:
    // 0x1379f8: 0x82230002
    ctx->pc = 0x1379f8u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 2)));
label_1379fc:
    // 0x1379fc: 0x2c62000a
    ctx->pc = 0x1379fcu;
    SET_GPR_U32(ctx, 2, SLTU32(GPR_U32(ctx, 3), 10));
label_137a00:
    // 0x137a00: 0x50400028
label_137a04:
    if (ctx->pc == 0x137A04u) {
        ctx->pc = 0x137A04u;
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->pc = 0x137A08u;
        goto label_137a08;
    }
    ctx->pc = 0x137A00u;
    {
        const bool branch_taken_0x137a00 = (GPR_U32(ctx, 2) == GPR_U32(ctx, 0));
        if (branch_taken_0x137a00) {
            ctx->pc = 0x137A04u;
            WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
            ctx->pc = 0x137AA4u;
            goto label_137aa4;
        }
    }
    ctx->pc = 0x137A08u;
label_137a08:
    // 0x137a08: 0x31080
    ctx->pc = 0x137a08u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 3), 2));
label_137a0c:
    // 0x137a0c: 0x3c030024
    ctx->pc = 0x137a0cu;
    SET_GPR_U32(ctx, 3, ((uint32_t)36 << 16));
label_137a10:
    // 0x137a10: 0x621821
    ctx->pc = 0x137a10u;
    SET_GPR_U32(ctx, 3, ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 2)));
label_137a14:
    // 0x137a14: 0x8c63c570
    ctx->pc = 0x137a14u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 3), 4294952304)));
label_137a18:
    // 0x137a18: 0x600008
label_137a1c:
    if (ctx->pc == 0x137A1Cu) {
        ctx->pc = 0x137A20u;
        goto label_137a20;
    }
    ctx->pc = 0x137A18u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1379D0u: goto label_1379d0;
            case 0x1379D4u: goto label_1379d4;
            case 0x1379D8u: goto label_1379d8;
            case 0x1379DCu: goto label_1379dc;
            case 0x1379E0u: goto label_1379e0;
            case 0x1379E4u: goto label_1379e4;
            case 0x1379E8u: goto label_1379e8;
            case 0x1379ECu: goto label_1379ec;
            case 0x1379F0u: goto label_1379f0;
            case 0x1379F4u: goto label_1379f4;
            case 0x1379F8u: goto label_1379f8;
            case 0x1379FCu: goto label_1379fc;
            case 0x137A00u: goto label_137a00;
            case 0x137A04u: goto label_137a04;
            case 0x137A08u: goto label_137a08;
            case 0x137A0Cu: goto label_137a0c;
            case 0x137A10u: goto label_137a10;
            case 0x137A14u: goto label_137a14;
            case 0x137A18u: goto label_137a18;
            case 0x137A1Cu: goto label_137a1c;
            case 0x137A20u: goto label_137a20;
            case 0x137A24u: goto label_137a24;
            case 0x137A28u: goto label_137a28;
            case 0x137A2Cu: goto label_137a2c;
            case 0x137A30u: goto label_137a30;
            case 0x137A34u: goto label_137a34;
            case 0x137A38u: goto label_137a38;
            case 0x137A3Cu: goto label_137a3c;
            case 0x137A40u: goto label_137a40;
            case 0x137A44u: goto label_137a44;
            case 0x137A48u: goto label_137a48;
            case 0x137A4Cu: goto label_137a4c;
            case 0x137A50u: goto label_137a50;
            case 0x137A54u: goto label_137a54;
            case 0x137A58u: goto label_137a58;
            case 0x137A5Cu: goto label_137a5c;
            case 0x137A60u: goto label_137a60;
            case 0x137A64u: goto label_137a64;
            case 0x137A68u: goto label_137a68;
            case 0x137A6Cu: goto label_137a6c;
            case 0x137A70u: goto label_137a70;
            case 0x137A74u: goto label_137a74;
            case 0x137A78u: goto label_137a78;
            case 0x137A7Cu: goto label_137a7c;
            case 0x137A80u: goto label_137a80;
            case 0x137A84u: goto label_137a84;
            case 0x137A88u: goto label_137a88;
            case 0x137A8Cu: goto label_137a8c;
            case 0x137A90u: goto label_137a90;
            case 0x137A94u: goto label_137a94;
            case 0x137A98u: goto label_137a98;
            case 0x137A9Cu: goto label_137a9c;
            case 0x137AA0u: goto label_137aa0;
            case 0x137AA4u: goto label_137aa4;
            case 0x137AA8u: goto label_137aa8;
            case 0x137AACu: goto label_137aac;
            case 0x137AB0u: goto label_137ab0;
            case 0x137AB4u: goto label_137ab4;
            case 0x137AB8u: goto label_137ab8;
            case 0x137ABCu: goto label_137abc;
            case 0x137AC0u: goto label_137ac0;
            case 0x137AC4u: goto label_137ac4;
            case 0x137AC8u: goto label_137ac8;
            case 0x137ACCu: goto label_137acc;
            case 0x137AD0u: goto label_137ad0;
            case 0x137AD4u: goto label_137ad4;
            case 0x137AD8u: goto label_137ad8;
            case 0x137ADCu: goto label_137adc;
            case 0x137AE0u: goto label_137ae0;
            case 0x137AE4u: goto label_137ae4;
            case 0x137AE8u: goto label_137ae8;
            case 0x137AECu: goto label_137aec;
            case 0x137AF0u: goto label_137af0;
            case 0x137AF4u: goto label_137af4;
            case 0x137AF8u: goto label_137af8;
            case 0x137AFCu: goto label_137afc;
            case 0x137B00u: goto label_137b00;
            case 0x137B04u: goto label_137b04;
            case 0x137B08u: goto label_137b08;
            case 0x137B0Cu: goto label_137b0c;
            case 0x137B10u: goto label_137b10;
            case 0x137B14u: goto label_137b14;
            case 0x137B18u: goto label_137b18;
            case 0x137B1Cu: goto label_137b1c;
            case 0x137B20u: goto label_137b20;
            case 0x137B24u: goto label_137b24;
            case 0x137B28u: goto label_137b28;
            case 0x137B2Cu: goto label_137b2c;
            case 0x137B30u: goto label_137b30;
            case 0x137B34u: goto label_137b34;
            case 0x137B38u: goto label_137b38;
            case 0x137B3Cu: goto label_137b3c;
            case 0x137B40u: goto label_137b40;
            case 0x137B44u: goto label_137b44;
            case 0x137B48u: goto label_137b48;
            case 0x137B4Cu: goto label_137b4c;
            case 0x137B50u: goto label_137b50;
            case 0x137B54u: goto label_137b54;
            case 0x137B58u: goto label_137b58;
            case 0x137B5Cu: goto label_137b5c;
            case 0x137B60u: goto label_137b60;
            case 0x137B64u: goto label_137b64;
            case 0x137B68u: goto label_137b68;
            case 0x137B6Cu: goto label_137b6c;
            case 0x137B70u: goto label_137b70;
            case 0x137B74u: goto label_137b74;
            case 0x137B78u: goto label_137b78;
            case 0x137B7Cu: goto label_137b7c;
            case 0x137B80u: goto label_137b80;
            case 0x137B84u: goto label_137b84;
            case 0x137B88u: goto label_137b88;
            case 0x137B8Cu: goto label_137b8c;
            case 0x137B90u: goto label_137b90;
            case 0x137B94u: goto label_137b94;
            case 0x137B98u: goto label_137b98;
            case 0x137B9Cu: goto label_137b9c;
            default: break;
        }
        return;
    }
    ctx->pc = 0x137A20u;
label_137a20:
    // 0x137a20: 0xc04e082
label_137a24:
    if (ctx->pc == 0x137A24u) {
        ctx->pc = 0x137A24u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 5632));
        ctx->pc = 0x137A28u;
        goto label_137a28;
    }
    ctx->pc = 0x137A20u;
    SET_GPR_U32(ctx, 31, 0x137A28u);
    ctx->pc = 0x137A24u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 5632));
    ctx->pc = 0x138208u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A28u; }
    }
    if (ctx->pc != 0x137A28u) { return; }
    ctx->pc = 0x137A28u;
label_137a28:
    // 0x137a28: 0xc0406e0
label_137a2c:
    if (ctx->pc == 0x137A2Cu) {
        ctx->pc = 0x137A30u;
        goto label_137a30;
    }
    ctx->pc = 0x137A28u;
    SET_GPR_U32(ctx, 31, 0x137A30u);
    ctx->pc = 0x101B80u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00101B80_0x101b80(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A30u; }
    }
    if (ctx->pc != 0x137A30u) { return; }
    ctx->pc = 0x137A30u;
label_137a30:
    // 0x137a30: 0x40802d
    ctx->pc = 0x137a30u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
label_137a34:
    // 0x137a34: 0xc04e082
label_137a38:
    if (ctx->pc == 0x137A38u) {
        ctx->pc = 0x137A38u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 5633));
        ctx->pc = 0x137A3Cu;
        goto label_137a3c;
    }
    ctx->pc = 0x137A34u;
    SET_GPR_U32(ctx, 31, 0x137A3Cu);
    ctx->pc = 0x137A38u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 5633));
    ctx->pc = 0x138208u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A3Cu; }
    }
    if (ctx->pc != 0x137A3Cu) { return; }
    ctx->pc = 0x137A3Cu;
label_137a3c:
    // 0x137a3c: 0x16000006
label_137a40:
    if (ctx->pc == 0x137A40u) {
        ctx->pc = 0x137A40u;
        SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
        ctx->pc = 0x137A44u;
        goto label_137a44;
    }
    ctx->pc = 0x137A3Cu;
    {
        const bool branch_taken_0x137a3c = (GPR_U32(ctx, 16) != GPR_U32(ctx, 0));
        ctx->pc = 0x137A40u;
        SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
        if (branch_taken_0x137a3c) {
            ctx->pc = 0x137A58u;
            goto label_137a58;
        }
    }
    ctx->pc = 0x137A44u;
label_137a44:
    // 0x137a44: 0x3c040024
    ctx->pc = 0x137a44u;
    SET_GPR_U32(ctx, 4, ((uint32_t)36 << 16));
label_137a48:
    // 0x137a48: 0x2442bbdc
    ctx->pc = 0x137a48u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294949852));
label_137a4c:
    // 0x137a4c: 0x2484c550
    ctx->pc = 0x137a4cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 4), 4294952272));
label_137a50:
    // 0x137a50: 0xc045a12
label_137a54:
    if (ctx->pc == 0x137A54u) {
        ctx->pc = 0x137A54u;
        SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 2), 0)));
        ctx->pc = 0x137A58u;
        goto label_137a58;
    }
    ctx->pc = 0x137A50u;
    SET_GPR_U32(ctx, 31, 0x137A58u);
    ctx->pc = 0x137A54u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 2), 0)));
    ctx->pc = 0x116848u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00116848_0x116848(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A58u; }
    }
    if (ctx->pc != 0x137A58u) { return; }
    ctx->pc = 0x137A58u;
label_137a58:
    // 0x137a58: 0xc04e082
label_137a5c:
    if (ctx->pc == 0x137A5Cu) {
        ctx->pc = 0x137A5Cu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 5888));
        ctx->pc = 0x137A60u;
        goto label_137a60;
    }
    ctx->pc = 0x137A58u;
    SET_GPR_U32(ctx, 31, 0x137A60u);
    ctx->pc = 0x137A5Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 5888));
    ctx->pc = 0x138208u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A60u; }
    }
    if (ctx->pc != 0x137A60u) { return; }
    ctx->pc = 0x137A60u;
label_137a60:
    // 0x137a60: 0xc04035e
label_137a64:
    if (ctx->pc == 0x137A64u) {
        ctx->pc = 0x137A64u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x137A68u;
        goto label_137a68;
    }
    ctx->pc = 0x137A60u;
    SET_GPR_U32(ctx, 31, 0x137A68u);
    ctx->pc = 0x137A64u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x100D78u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00100D78_0x100d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A68u; }
    }
    if (ctx->pc != 0x137A68u) { return; }
    ctx->pc = 0x137A68u;
label_137a68:
    // 0x137a68: 0xc04e082
label_137a6c:
    if (ctx->pc == 0x137A6Cu) {
        ctx->pc = 0x137A6Cu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 5889));
        ctx->pc = 0x137A70u;
        goto label_137a70;
    }
    ctx->pc = 0x137A68u;
    SET_GPR_U32(ctx, 31, 0x137A70u);
    ctx->pc = 0x137A6Cu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 5889));
    ctx->pc = 0x138208u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137A70u; }
    }
    if (ctx->pc != 0x137A70u) { return; }
    ctx->pc = 0x137A70u;
label_137a70:
    // 0x137a70: 0xa2200002
    ctx->pc = 0x137a70u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
label_137a74:
    // 0x137a74: 0x3c030022
    ctx->pc = 0x137a74u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
label_137a78:
    // 0x137a78: 0x282d
    ctx->pc = 0x137a78u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_137a7c:
    // 0x137a7c: 0x2463bbe4
    ctx->pc = 0x137a7cu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294949860));
label_137a80:
    // 0x137a80: 0x8c620000
    ctx->pc = 0x137a80u;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_137a84:
    // 0x137a84: 0x24420001
    ctx->pc = 0x137a84u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
label_137a88:
    // 0x137a88: 0xac620000
    ctx->pc = 0x137a88u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_137a8c:
    // 0x137a8c: 0x10000005
label_137a90:
    if (ctx->pc == 0x137A90u) {
        ctx->pc = 0x137A90u;
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        ctx->pc = 0x137A94u;
        goto label_137a94;
    }
    ctx->pc = 0x137A8Cu;
    {
        const bool branch_taken_0x137a8c = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x137A90u;
        WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
        if (branch_taken_0x137a8c) {
            ctx->pc = 0x137AA4u;
            goto label_137aa4;
        }
    }
    ctx->pc = 0x137A94u;
label_137a94:
    // 0x137a94: 0x0
    ctx->pc = 0x137a94u;
    // NOP
label_137a98:
    // 0x137a98: 0xa2200002
    ctx->pc = 0x137a98u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 0));
label_137a9c:
    // 0x137a9c: 0x282d
    ctx->pc = 0x137a9cu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
label_137aa0:
    // 0x137aa0: 0xae200004
    ctx->pc = 0x137aa0u;
    WRITE32(ADD32(GPR_U32(ctx, 17), 4), GPR_U32(ctx, 0));
label_137aa4:
    // 0x137aa4: 0x51600
    ctx->pc = 0x137aa4u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 5), 24));
label_137aa8:
    // 0x137aa8: 0x24030001
    ctx->pc = 0x137aa8u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 1));
label_137aac:
    // 0x137aac: 0x29603
    ctx->pc = 0x137aacu;
    SET_GPR_S32(ctx, 18, SRA32(GPR_S32(ctx, 2), 24));
label_137ab0:
    // 0x137ab0: 0x5643001d
label_137ab4:
    if (ctx->pc == 0x137AB4u) {
        ctx->pc = 0x137AB4u;
        SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
        ctx->pc = 0x137AB8u;
        goto label_137ab8;
    }
    ctx->pc = 0x137AB0u;
    {
        const bool branch_taken_0x137ab0 = (GPR_U32(ctx, 18) != GPR_U32(ctx, 3));
        if (branch_taken_0x137ab0) {
            ctx->pc = 0x137AB4u;
            SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
            ctx->pc = 0x137B28u;
            goto label_137b28;
        }
    }
    ctx->pc = 0x137AB8u;
label_137ab8:
    // 0x137ab8: 0xc04e082
label_137abc:
    if (ctx->pc == 0x137ABCu) {
        ctx->pc = 0x137ABCu;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 6144));
        ctx->pc = 0x137AC0u;
        goto label_137ac0;
    }
    ctx->pc = 0x137AB8u;
    SET_GPR_U32(ctx, 31, 0x137AC0u);
    ctx->pc = 0x137ABCu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 6144));
    ctx->pc = 0x138208u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137AC0u; }
    }
    if (ctx->pc != 0x137AC0u) { return; }
    ctx->pc = 0x137AC0u;
label_137ac0:
    // 0x137ac0: 0x8e240008
    ctx->pc = 0x137ac0u;
    SET_GPR_U32(ctx, 4, READ32(ADD32(GPR_U32(ctx, 17), 8)));
label_137ac4:
    // 0x137ac4: 0x8e25000c
    ctx->pc = 0x137ac4u;
    SET_GPR_U32(ctx, 5, READ32(ADD32(GPR_U32(ctx, 17), 12)));
label_137ac8:
    // 0x137ac8: 0x26270014
    ctx->pc = 0x137ac8u;
    SET_GPR_S32(ctx, 7, ADD32(GPR_U32(ctx, 17), 20));
label_137acc:
    // 0x137acc: 0xc0405e2
label_137ad0:
    if (ctx->pc == 0x137AD0u) {
        ctx->pc = 0x137AD0u;
        SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 17), 16)));
        ctx->pc = 0x137AD4u;
        goto label_137ad4;
    }
    ctx->pc = 0x137ACCu;
    SET_GPR_U32(ctx, 31, 0x137AD4u);
    ctx->pc = 0x137AD0u;
    SET_GPR_U32(ctx, 6, READ32(ADD32(GPR_U32(ctx, 17), 16)));
    ctx->pc = 0x101788u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00101788_0x101788(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137AD4u; }
    }
    if (ctx->pc != 0x137AD4u) { return; }
    ctx->pc = 0x137AD4u;
label_137ad4:
    // 0x137ad4: 0x24041801
    ctx->pc = 0x137ad4u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 6145));
label_137ad8:
    // 0x137ad8: 0xc04e082
label_137adc:
    if (ctx->pc == 0x137ADCu) {
        ctx->pc = 0x137ADCu;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x137AE0u;
        goto label_137ae0;
    }
    ctx->pc = 0x137AD8u;
    SET_GPR_U32(ctx, 31, 0x137AE0u);
    ctx->pc = 0x137ADCu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x138208u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137AE0u; }
    }
    if (ctx->pc != 0x137AE0u) { return; }
    ctx->pc = 0x137AE0u;
label_137ae0:
    // 0x137ae0: 0x1612000b
label_137ae4:
    if (ctx->pc == 0x137AE4u) {
        ctx->pc = 0x137AE4u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 9));
        ctx->pc = 0x137AE8u;
        goto label_137ae8;
    }
    ctx->pc = 0x137AE0u;
    {
        const bool branch_taken_0x137ae0 = (GPR_U32(ctx, 16) != GPR_U32(ctx, 18));
        ctx->pc = 0x137AE4u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 9));
        if (branch_taken_0x137ae0) {
            ctx->pc = 0x137B10u;
            goto label_137b10;
        }
    }
    ctx->pc = 0x137AE8u;
label_137ae8:
    // 0x137ae8: 0x3c020022
    ctx->pc = 0x137ae8u;
    SET_GPR_U32(ctx, 2, ((uint32_t)34 << 16));
label_137aec:
    // 0x137aec: 0x24040002
    ctx->pc = 0x137aecu;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 2));
label_137af0:
    // 0x137af0: 0x2442bbe0
    ctx->pc = 0x137af0u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 4294949856));
label_137af4:
    // 0x137af4: 0x24050002
    ctx->pc = 0x137af4u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 2));
label_137af8:
    // 0x137af8: 0x8c430000
    ctx->pc = 0x137af8u;
    SET_GPR_U32(ctx, 3, READ32(ADD32(GPR_U32(ctx, 2), 0)));
label_137afc:
    // 0x137afc: 0x24630001
    ctx->pc = 0x137afcu;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 1));
label_137b00:
    // 0x137b00: 0xac430000
    ctx->pc = 0x137b00u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 0), GPR_U32(ctx, 3));
label_137b04:
    // 0x137b04: 0x10000006
label_137b08:
    if (ctx->pc == 0x137B08u) {
        ctx->pc = 0x137B08u;
        WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 4));
        ctx->pc = 0x137B0Cu;
        goto label_137b0c;
    }
    ctx->pc = 0x137B04u;
    {
        const bool branch_taken_0x137b04 = (GPR_U32(ctx, 0) == GPR_U32(ctx, 0));
        ctx->pc = 0x137B08u;
        WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 4));
        if (branch_taken_0x137b04) {
            ctx->pc = 0x137B20u;
            goto label_137b20;
        }
    }
    ctx->pc = 0x137B0Cu;
label_137b0c:
    // 0x137b0c: 0x0
    ctx->pc = 0x137b0cu;
    // NOP
label_137b10:
    // 0x137b10: 0x2403ffff
    ctx->pc = 0x137b10u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 4294967295));
label_137b14:
    // 0x137b14: 0xa2220002
    ctx->pc = 0x137b14u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 2));
label_137b18:
    // 0x137b18: 0x24050009
    ctx->pc = 0x137b18u;
    SET_GPR_S32(ctx, 5, ADD32(GPR_U32(ctx, 0), 9));
label_137b1c:
    // 0x137b1c: 0xae230034
    ctx->pc = 0x137b1cu;
    WRITE32(ADD32(GPR_U32(ctx, 17), 52), GPR_U32(ctx, 3));
label_137b20:
    // 0x137b20: 0x51600
    ctx->pc = 0x137b20u;
    SET_GPR_U32(ctx, 2, SLL32(GPR_U32(ctx, 5), 24));
label_137b24:
    // 0x137b24: 0x24030002
    ctx->pc = 0x137b24u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 0), 2));
label_137b28:
    // 0x137b28: 0x21603
    ctx->pc = 0x137b28u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
label_137b2c:
    // 0x137b2c: 0x14430017
label_137b30:
    if (ctx->pc == 0x137B30u) {
        ctx->pc = 0x137B30u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->pc = 0x137B34u;
        goto label_137b34;
    }
    ctx->pc = 0x137B2Cu;
    {
        const bool branch_taken_0x137b2c = (GPR_U32(ctx, 2) != GPR_U32(ctx, 3));
        ctx->pc = 0x137B30u;
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        if (branch_taken_0x137b2c) {
            ctx->pc = 0x137B8Cu;
            goto label_137b8c;
        }
    }
    ctx->pc = 0x137B34u;
label_137b34:
    // 0x137b34: 0xc04e082
label_137b38:
    if (ctx->pc == 0x137B38u) {
        ctx->pc = 0x137B38u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 6400));
        ctx->pc = 0x137B3Cu;
        goto label_137b3c;
    }
    ctx->pc = 0x137B34u;
    SET_GPR_U32(ctx, 31, 0x137B3Cu);
    ctx->pc = 0x137B38u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 6400));
    ctx->pc = 0x138208u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137B3Cu; }
    }
    if (ctx->pc != 0x137B3Cu) { return; }
    ctx->pc = 0x137B3Cu;
label_137b3c:
    // 0x137b3c: 0xc04035e
label_137b40:
    if (ctx->pc == 0x137B40u) {
        ctx->pc = 0x137B40u;
        SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
        ctx->pc = 0x137B44u;
        goto label_137b44;
    }
    ctx->pc = 0x137B3Cu;
    SET_GPR_U32(ctx, 31, 0x137B44u);
    ctx->pc = 0x137B40u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 1));
    ctx->pc = 0x100D78u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00100D78_0x100d78(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137B44u; }
    }
    if (ctx->pc != 0x137B44u) { return; }
    ctx->pc = 0x137B44u;
label_137b44:
    // 0x137b44: 0x24041901
    ctx->pc = 0x137b44u;
    SET_GPR_S32(ctx, 4, ADD32(GPR_U32(ctx, 0), 6401));
label_137b48:
    // 0x137b48: 0xc04e082
label_137b4c:
    if (ctx->pc == 0x137B4Cu) {
        ctx->pc = 0x137B4Cu;
        SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x137B50u;
        goto label_137b50;
    }
    ctx->pc = 0x137B48u;
    SET_GPR_U32(ctx, 31, 0x137B50u);
    ctx->pc = 0x137B4Cu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x138208u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_00138208_0x138208(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137B50u; }
    }
    if (ctx->pc != 0x137B50u) { return; }
    ctx->pc = 0x137B50u;
label_137b50:
    // 0x137b50: 0xc04de34
label_137b54:
    if (ctx->pc == 0x137B54u) {
        ctx->pc = 0x137B54u;
        SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x137B58u;
        goto label_137b58;
    }
    ctx->pc = 0x137B50u;
    SET_GPR_U32(ctx, 31, 0x137B58u);
    ctx->pc = 0x137B54u;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    ctx->pc = 0x1378D0u;
    {
        const uint32_t __entryPc = ctx->pc;
        sub_001378D0_0x1378d0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x137B58u; }
    }
    if (ctx->pc != 0x137B58u) { return; }
    ctx->pc = 0x137B58u;
label_137b58:
    // 0x137b58: 0x1600000b
label_137b5c:
    if (ctx->pc == 0x137B5Cu) {
        ctx->pc = 0x137B5Cu;
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        ctx->pc = 0x137B60u;
        goto label_137b60;
    }
    ctx->pc = 0x137B58u;
    {
        const bool branch_taken_0x137b58 = (GPR_U32(ctx, 16) != GPR_U32(ctx, 0));
        ctx->pc = 0x137B5Cu;
        SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
        if (branch_taken_0x137b58) {
            ctx->pc = 0x137B88u;
            goto label_137b88;
        }
    }
    ctx->pc = 0x137B60u;
label_137b60:
    // 0x137b60: 0x24020001
    ctx->pc = 0x137b60u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 1));
label_137b64:
    // 0x137b64: 0x54620002
label_137b68:
    if (ctx->pc == 0x137B68u) {
        ctx->pc = 0x137B68u;
        SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
        ctx->pc = 0x137B6Cu;
        goto label_137b6c;
    }
    ctx->pc = 0x137B64u;
    {
        const bool branch_taken_0x137b64 = (GPR_U32(ctx, 3) != GPR_U32(ctx, 2));
        if (branch_taken_0x137b64) {
            ctx->pc = 0x137B68u;
            SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 3));
            ctx->pc = 0x137B70u;
            goto label_137b70;
        }
    }
    ctx->pc = 0x137B6Cu;
label_137b6c:
    // 0x137b6c: 0x24020009
    ctx->pc = 0x137b6cu;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 0), 9));
label_137b70:
    // 0x137b70: 0xa2220002
    ctx->pc = 0x137b70u;
    WRITE8(ADD32(GPR_U32(ctx, 17), 2), (uint8_t)GPR_U32(ctx, 2));
label_137b74:
    // 0x137b74: 0x3c030022
    ctx->pc = 0x137b74u;
    SET_GPR_U32(ctx, 3, ((uint32_t)34 << 16));
label_137b78:
    // 0x137b78: 0x2463bbe4
    ctx->pc = 0x137b78u;
    SET_GPR_S32(ctx, 3, ADD32(GPR_U32(ctx, 3), 4294949860));
label_137b7c:
    // 0x137b7c: 0x8c620000
    ctx->pc = 0x137b7cu;
    SET_GPR_U32(ctx, 2, READ32(ADD32(GPR_U32(ctx, 3), 0)));
label_137b80:
    // 0x137b80: 0x24420001
    ctx->pc = 0x137b80u;
    SET_GPR_S32(ctx, 2, ADD32(GPR_U32(ctx, 2), 1));
label_137b84:
    // 0x137b84: 0xac620000
    ctx->pc = 0x137b84u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 2));
label_137b88:
    // 0x137b88: 0xdfb00000
    ctx->pc = 0x137b88u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_137b8c:
    // 0x137b8c: 0xdfb10008
    ctx->pc = 0x137b8cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
label_137b90:
    // 0x137b90: 0xdfb20010
    ctx->pc = 0x137b90u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
label_137b94:
    // 0x137b94: 0xdfbf0018
    ctx->pc = 0x137b94u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
label_137b98:
    // 0x137b98: 0x3e00008
label_137b9c:
    if (ctx->pc == 0x137B9Cu) {
        ctx->pc = 0x137B9Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = 0x137BA0u;
        goto label_fallthrough_0x137b98;
    }
    ctx->pc = 0x137B98u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x137B9Cu;
        SET_GPR_S32(ctx, 29, ADD32(GPR_U32(ctx, 29), 32));
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x1379D0u: goto label_1379d0;
            case 0x1379D4u: goto label_1379d4;
            case 0x1379D8u: goto label_1379d8;
            case 0x1379DCu: goto label_1379dc;
            case 0x1379E0u: goto label_1379e0;
            case 0x1379E4u: goto label_1379e4;
            case 0x1379E8u: goto label_1379e8;
            case 0x1379ECu: goto label_1379ec;
            case 0x1379F0u: goto label_1379f0;
            case 0x1379F4u: goto label_1379f4;
            case 0x1379F8u: goto label_1379f8;
            case 0x1379FCu: goto label_1379fc;
            case 0x137A00u: goto label_137a00;
            case 0x137A04u: goto label_137a04;
            case 0x137A08u: goto label_137a08;
            case 0x137A0Cu: goto label_137a0c;
            case 0x137A10u: goto label_137a10;
            case 0x137A14u: goto label_137a14;
            case 0x137A18u: goto label_137a18;
            case 0x137A1Cu: goto label_137a1c;
            case 0x137A20u: goto label_137a20;
            case 0x137A24u: goto label_137a24;
            case 0x137A28u: goto label_137a28;
            case 0x137A2Cu: goto label_137a2c;
            case 0x137A30u: goto label_137a30;
            case 0x137A34u: goto label_137a34;
            case 0x137A38u: goto label_137a38;
            case 0x137A3Cu: goto label_137a3c;
            case 0x137A40u: goto label_137a40;
            case 0x137A44u: goto label_137a44;
            case 0x137A48u: goto label_137a48;
            case 0x137A4Cu: goto label_137a4c;
            case 0x137A50u: goto label_137a50;
            case 0x137A54u: goto label_137a54;
            case 0x137A58u: goto label_137a58;
            case 0x137A5Cu: goto label_137a5c;
            case 0x137A60u: goto label_137a60;
            case 0x137A64u: goto label_137a64;
            case 0x137A68u: goto label_137a68;
            case 0x137A6Cu: goto label_137a6c;
            case 0x137A70u: goto label_137a70;
            case 0x137A74u: goto label_137a74;
            case 0x137A78u: goto label_137a78;
            case 0x137A7Cu: goto label_137a7c;
            case 0x137A80u: goto label_137a80;
            case 0x137A84u: goto label_137a84;
            case 0x137A88u: goto label_137a88;
            case 0x137A8Cu: goto label_137a8c;
            case 0x137A90u: goto label_137a90;
            case 0x137A94u: goto label_137a94;
            case 0x137A98u: goto label_137a98;
            case 0x137A9Cu: goto label_137a9c;
            case 0x137AA0u: goto label_137aa0;
            case 0x137AA4u: goto label_137aa4;
            case 0x137AA8u: goto label_137aa8;
            case 0x137AACu: goto label_137aac;
            case 0x137AB0u: goto label_137ab0;
            case 0x137AB4u: goto label_137ab4;
            case 0x137AB8u: goto label_137ab8;
            case 0x137ABCu: goto label_137abc;
            case 0x137AC0u: goto label_137ac0;
            case 0x137AC4u: goto label_137ac4;
            case 0x137AC8u: goto label_137ac8;
            case 0x137ACCu: goto label_137acc;
            case 0x137AD0u: goto label_137ad0;
            case 0x137AD4u: goto label_137ad4;
            case 0x137AD8u: goto label_137ad8;
            case 0x137ADCu: goto label_137adc;
            case 0x137AE0u: goto label_137ae0;
            case 0x137AE4u: goto label_137ae4;
            case 0x137AE8u: goto label_137ae8;
            case 0x137AECu: goto label_137aec;
            case 0x137AF0u: goto label_137af0;
            case 0x137AF4u: goto label_137af4;
            case 0x137AF8u: goto label_137af8;
            case 0x137AFCu: goto label_137afc;
            case 0x137B00u: goto label_137b00;
            case 0x137B04u: goto label_137b04;
            case 0x137B08u: goto label_137b08;
            case 0x137B0Cu: goto label_137b0c;
            case 0x137B10u: goto label_137b10;
            case 0x137B14u: goto label_137b14;
            case 0x137B18u: goto label_137b18;
            case 0x137B1Cu: goto label_137b1c;
            case 0x137B20u: goto label_137b20;
            case 0x137B24u: goto label_137b24;
            case 0x137B28u: goto label_137b28;
            case 0x137B2Cu: goto label_137b2c;
            case 0x137B30u: goto label_137b30;
            case 0x137B34u: goto label_137b34;
            case 0x137B38u: goto label_137b38;
            case 0x137B3Cu: goto label_137b3c;
            case 0x137B40u: goto label_137b40;
            case 0x137B44u: goto label_137b44;
            case 0x137B48u: goto label_137b48;
            case 0x137B4Cu: goto label_137b4c;
            case 0x137B50u: goto label_137b50;
            case 0x137B54u: goto label_137b54;
            case 0x137B58u: goto label_137b58;
            case 0x137B5Cu: goto label_137b5c;
            case 0x137B60u: goto label_137b60;
            case 0x137B64u: goto label_137b64;
            case 0x137B68u: goto label_137b68;
            case 0x137B6Cu: goto label_137b6c;
            case 0x137B70u: goto label_137b70;
            case 0x137B74u: goto label_137b74;
            case 0x137B78u: goto label_137b78;
            case 0x137B7Cu: goto label_137b7c;
            case 0x137B80u: goto label_137b80;
            case 0x137B84u: goto label_137b84;
            case 0x137B88u: goto label_137b88;
            case 0x137B8Cu: goto label_137b8c;
            case 0x137B90u: goto label_137b90;
            case 0x137B94u: goto label_137b94;
            case 0x137B98u: goto label_137b98;
            case 0x137B9Cu: goto label_137b9c;
            default: break;
        }
        return;
    }
label_fallthrough_0x137b98:
    ctx->pc = 0x137BA0u;
}
