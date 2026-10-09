#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_001C9950
// Address: 0x1c9950 - 0x1ca3ec
void sub_001C9950_0x1c9950(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_001C9950_0x1c9950");
#endif

    switch (ctx->pc) {
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
        default: break;
    }

    ctx->pc = 0x1c9950u;

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
    if (runtime->hasFunction(0x1C97F0u)) {
        auto targetFn = runtime->lookupFunction(0x1C97F0u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA1D8u; }
        if (ctx->pc != 0x1CA1D8u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_001C97F0_0x1c97f0(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x1CA1D8u; }
        if (ctx->pc != 0x1CA1D8u) { return; }
    }
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
            default: break;
        }
        return;
    }
    ctx->pc = 0x1CA3ECu;
    ctx->pc = GPR_U32(ctx, 31); return;
}
