#include "ps2_runtime_macros.h"
#include "ps2_runtime.h"
#include "ps2_recompiled_functions.h"
#include "ps2_recompiled_stubs.h"

#include "ps2_syscalls.h"
#include "ps2_stubs.h"

#ifdef PS2_FUNCTION_LOG_TRACKER
#include "ps2_log.h"
#endif

// Function: sub_00123DB0
// Address: 0x123db0 - 0x124518
void sub_00123DB0_0x123db0(uint8_t* rdram, R5900Context* ctx, PS2Runtime *runtime) {
#ifdef PS2_FUNCTION_LOG_TRACKER
    PS_LOG_ENTRY("sub_00123DB0_0x123db0");
#endif

    switch (ctx->pc) {
        case 0x123e20u: goto label_123e20;
        case 0x123f28u: goto label_123f28;
        case 0x123fc0u: goto label_123fc0;
        case 0x123ff4u: goto label_123ff4;
        case 0x124014u: goto label_124014;
        case 0x124070u: goto label_124070;
        case 0x1240c8u: goto label_1240c8;
        case 0x124138u: goto label_124138;
        case 0x124158u: goto label_124158;
        case 0x12418cu: goto label_12418c;
        case 0x1241acu: goto label_1241ac;
        case 0x124208u: goto label_124208;
        case 0x124258u: goto label_124258;
        case 0x1242b8u: goto label_1242b8;
        case 0x1242d8u: goto label_1242d8;
        case 0x12430cu: goto label_12430c;
        case 0x12432cu: goto label_12432c;
        case 0x124390u: goto label_124390;
        case 0x1243f8u: goto label_1243f8;
        case 0x124460u: goto label_124460;
        case 0x124504u: goto label_124504;
        default: break;
    }

    ctx->pc = 0x123db0u;

label_123db0:
    // 0x123db0: 0x27bdffb0  addiu       $sp, $sp, -0x50
    ctx->pc = 0x123db0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967216));
    // 0x123db4: 0x28a20008  slti        $v0, $a1, 0x8
    ctx->pc = 0x123db4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)(int32_t)8) ? 1 : 0);
    // 0x123db8: 0xffb00010  sd          $s0, 0x10($sp)
    ctx->pc = 0x123db8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 16));
    // 0x123dbc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x123dbcu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123dc0: 0xffb10018  sd          $s1, 0x18($sp)
    ctx->pc = 0x123dc0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 17));
    // 0x123dc4: 0xc0882d  daddu       $s1, $a2, $zero
    ctx->pc = 0x123dc4u;
    SET_GPR_U64(ctx, 17, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123dc8: 0xffb20020  sd          $s2, 0x20($sp)
    ctx->pc = 0x123dc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 32), GPR_U64(ctx, 18));
    // 0x123dcc: 0x140902d  daddu       $s2, $t2, $zero
    ctx->pc = 0x123dccu;
    SET_GPR_U64(ctx, 18, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123dd0: 0xffb30028  sd          $s3, 0x28($sp)
    ctx->pc = 0x123dd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 40), GPR_U64(ctx, 19));
    // 0x123dd4: 0x160982d  daddu       $s3, $t3, $zero
    ctx->pc = 0x123dd4u;
    SET_GPR_U64(ctx, 19, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123dd8: 0xffb40030  sd          $s4, 0x30($sp)
    ctx->pc = 0x123dd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 20));
    // 0x123ddc: 0x100a02d  daddu       $s4, $t0, $zero
    ctx->pc = 0x123ddcu;
    SET_GPR_U64(ctx, 20, (uint64_t)GPR_U64(ctx, 8) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123de0: 0xffb50038  sd          $s5, 0x38($sp)
    ctx->pc = 0x123de0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 21));
    // 0x123de4: 0xe0a82d  daddu       $s5, $a3, $zero
    ctx->pc = 0x123de4u;
    SET_GPR_U64(ctx, 21, (uint64_t)GPR_U64(ctx, 7) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123de8: 0xffb60040  sd          $s6, 0x40($sp)
    ctx->pc = 0x123de8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 22));
    // 0x123dec: 0x120b02d  daddu       $s6, $t1, $zero
    ctx->pc = 0x123decu;
    SET_GPR_U64(ctx, 22, (uint64_t)GPR_U64(ctx, 9) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123df0: 0xffbf0048  sd          $ra, 0x48($sp)
    ctx->pc = 0x123df0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 31));
    // 0x123df4: 0x3a0302d  daddu       $a2, $sp, $zero
    ctx->pc = 0x123df4u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 29) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123df8: 0x27a80008  addiu       $t0, $sp, 0x8
    ctx->pc = 0x123df8u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 29), 8));
    // 0x123dfc: 0x27a70004  addiu       $a3, $sp, 0x4
    ctx->pc = 0x123dfcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 29), 4));
    // 0x123e00: 0x27a9000c  addiu       $t1, $sp, 0xC
    ctx->pc = 0x123e00u;
    SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 29), 12));
    // 0x123e04: 0x10400004  beqz        $v0, . + 4 + (0x4 << 2)
    ctx->pc = 0x123E04u;
    {
        const bool branch_taken_0x123e04 = (GPR_U64(ctx, 2) == GPR_U64(ctx, 0));
        ctx->pc = 0x123E08u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123E04u;
            // 0x123e08: 0x8faa0060  lw          $t2, 0x60($sp) (Delay Slot)
        SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 96)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123e04) {
            ctx->pc = 0x123E18u;
            goto label_123e18;
        }
    }
    ctx->pc = 0x123E0Cu;
    // 0x123e0c: 0xa6200000  sh          $zero, 0x0($s1)
    ctx->pc = 0x123e0cu;
    WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 0));
    // 0x123e10: 0x10000021  b           . + 4 + (0x21 << 2)
    ctx->pc = 0x123E10u;
    {
        const bool branch_taken_0x123e10 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x123E14u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123E10u;
            // 0x123e14: 0x2402ffff  addiu       $v0, $zero, -0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123e10) {
            ctx->pc = 0x123E98u;
            goto label_123e98;
        }
    }
    ctx->pc = 0x123E18u;
label_123e18:
    // 0x123e18: 0xc048e90  jal         func_123A40
    ctx->pc = 0x123E18u;
    SET_GPR_U32(ctx, 31, 0x123E20u);
    ctx->pc = 0x123A40u;
    if (runtime->hasFunction(0x123A40u)) {
        auto targetFn = runtime->lookupFunction(0x123A40u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x123E20u; }
        if (ctx->pc != 0x123E20u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00123A40_0x123a40(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x123E20u; }
        if (ctx->pc != 0x123E20u) { return; }
    }
    ctx->pc = 0x123E20u;
label_123e20:
    // 0x123e20: 0x40182d  daddu       $v1, $v0, $zero
    ctx->pc = 0x123e20u;
    SET_GPR_U64(ctx, 3, (uint64_t)GPR_U64(ctx, 2) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123e24: 0x2402ffff  addiu       $v0, $zero, -0x1
    ctx->pc = 0x123e24u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x123e28: 0x1060001b  beqz        $v1, . + 4 + (0x1B << 2)
    ctx->pc = 0x123E28u;
    {
        const bool branch_taken_0x123e28 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x123E2Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123E28u;
            // 0x123e2c: 0x702023  subu        $a0, $v1, $s0 (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)SUB32(GPR_U32(ctx, 3), GPR_U32(ctx, 16)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123e28) {
            ctx->pc = 0x123E98u;
            goto label_123e98;
        }
    }
    ctx->pc = 0x123E30u;
    // 0x123e30: 0x41c00  sll         $v1, $a0, 16
    ctx->pc = 0x123e30u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 4), 16));
    // 0x123e34: 0x18600018  blez        $v1, . + 4 + (0x18 << 2)
    ctx->pc = 0x123E34u;
    {
        const bool branch_taken_0x123e34 = (GPR_S64(ctx, 3) <= 0);
        ctx->pc = 0x123E38u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123E34u;
            // 0x123e38: 0xa6240000  sh          $a0, 0x0($s1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 17), 0), (uint16_t)GPR_U32(ctx, 4));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123e34) {
            ctx->pc = 0x123E98u;
            goto label_123e98;
        }
    }
    ctx->pc = 0x123E3Cu;
    // 0x123e3c: 0x8fa60000  lw          $a2, 0x0($sp)
    ctx->pc = 0x123e3cu;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x123e40: 0x2407ffff  addiu       $a3, $zero, -0x1
    ctx->pc = 0x123e40u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 0), 4294967295));
    // 0x123e44: 0x93a30004  lbu         $v1, 0x4($sp)
    ctx->pc = 0x123e44u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 4)));
    // 0x123e48: 0x24080001  addiu       $t0, $zero, 0x1
    ctx->pc = 0x123e48u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x123e4c: 0x93a40008  lbu         $a0, 0x8($sp)
    ctx->pc = 0x123e4cu;
    SET_GPR_U32(ctx, 4, (uint8_t)READ8(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x123e50: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x123e50u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123e54: 0xae660000  sw          $a2, 0x0($s3)
    ctx->pc = 0x123e54u;
    WRITE32(ADD32(GPR_U32(ctx, 19), 0), GPR_U32(ctx, 6));
    // 0x123e58: 0x8fa5000c  lw          $a1, 0xC($sp)
    ctx->pc = 0x123e58u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 12)));
    // 0x123e5c: 0xa2430000  sb          $v1, 0x0($s2)
    ctx->pc = 0x123e5cu;
    WRITE8(ADD32(GPR_U32(ctx, 18), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x123e60: 0xa2840000  sb          $a0, 0x0($s4)
    ctx->pc = 0x123e60u;
    WRITE8(ADD32(GPR_U32(ctx, 20), 0), (uint8_t)GPR_U32(ctx, 4));
    // 0x123e64: 0x8fa30050  lw          $v1, 0x50($sp)
    ctx->pc = 0x123e64u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x123e68: 0xac650000  sw          $a1, 0x0($v1)
    ctx->pc = 0x123e68u;
    WRITE32(ADD32(GPR_U32(ctx, 3), 0), GPR_U32(ctx, 5));
    // 0x123e6c: 0xa2a70000  sb          $a3, 0x0($s5)
    ctx->pc = 0x123e6cu;
    WRITE8(ADD32(GPR_U32(ctx, 21), 0), (uint8_t)GPR_U32(ctx, 7));
    // 0x123e70: 0x82840000  lb          $a0, 0x0($s4)
    ctx->pc = 0x123e70u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 20), 0)));
    // 0x123e74: 0x82430000  lb          $v1, 0x0($s2)
    ctx->pc = 0x123e74u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x123e78: 0x641818  mult        $v1, $v1, $a0
    ctx->pc = 0x123e78u;
    { int64_t result = (int64_t)GPR_S32(ctx, 3) * (int64_t)GPR_S32(ctx, 4); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 3, (int32_t)result); }
    // 0x123e7c: 0x28640000  slti        $a0, $v1, 0x0
    ctx->pc = 0x123e7cu;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 3) < (int64_t)(int32_t)0) ? 1 : 0);
    // 0x123e80: 0x24650007  addiu       $a1, $v1, 0x7
    ctx->pc = 0x123e80u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 3), 7));
    // 0x123e84: 0xa4180b  movn        $v1, $a1, $a0
    ctx->pc = 0x123e84u;
    if (GPR_U64(ctx, 4) != 0) SET_GPR_VEC(ctx, 3, GPR_VEC(ctx, 5));
    // 0x123e88: 0x318c3  sra         $v1, $v1, 3
    ctx->pc = 0x123e88u;
    SET_GPR_S32(ctx, 3, SRA32(GPR_S32(ctx, 3), 3));
    // 0x123e8c: 0xa2c30000  sb          $v1, 0x0($s6)
    ctx->pc = 0x123e8cu;
    WRITE8(ADD32(GPR_U32(ctx, 22), 0), (uint8_t)GPR_U32(ctx, 3));
    // 0x123e90: 0x8fa40058  lw          $a0, 0x58($sp)
    ctx->pc = 0x123e90u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 29), 88)));
    // 0x123e94: 0xac880000  sw          $t0, 0x0($a0)
    ctx->pc = 0x123e94u;
    WRITE32(ADD32(GPR_U32(ctx, 4), 0), GPR_U32(ctx, 8));
label_123e98:
    // 0x123e98: 0xdfb00010  ld          $s0, 0x10($sp)
    ctx->pc = 0x123e98u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x123e9c: 0xdfb10018  ld          $s1, 0x18($sp)
    ctx->pc = 0x123e9cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x123ea0: 0xdfb20020  ld          $s2, 0x20($sp)
    ctx->pc = 0x123ea0u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x123ea4: 0xdfb30028  ld          $s3, 0x28($sp)
    ctx->pc = 0x123ea4u;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 40)));
    // 0x123ea8: 0xdfb40030  ld          $s4, 0x30($sp)
    ctx->pc = 0x123ea8u;
    SET_GPR_U64(ctx, 20, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x123eac: 0xdfb50038  ld          $s5, 0x38($sp)
    ctx->pc = 0x123eacu;
    SET_GPR_U64(ctx, 21, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x123eb0: 0xdfb60040  ld          $s6, 0x40($sp)
    ctx->pc = 0x123eb0u;
    SET_GPR_U64(ctx, 22, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x123eb4: 0xdfbf0048  ld          $ra, 0x48($sp)
    ctx->pc = 0x123eb4u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x123eb8: 0x3e00008  jr          $ra
    ctx->pc = 0x123EB8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x123EBCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123EB8u;
            // 0x123ebc: 0x27bd0050  addiu       $sp, $sp, 0x50 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 80));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123E18u: goto label_123e18;
            case 0x123E20u: goto label_123e20;
            case 0x123E98u: goto label_123e98;
            case 0x123F28u: goto label_123f28;
            case 0x123F38u: goto label_123f38;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FF4u: goto label_123ff4;
            case 0x124014u: goto label_124014;
            case 0x124070u: goto label_124070;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240F8u: goto label_1240f8;
            case 0x124118u: goto label_124118;
            case 0x124138u: goto label_124138;
            case 0x124144u: goto label_124144;
            case 0x124158u: goto label_124158;
            case 0x12418Cu: goto label_12418c;
            case 0x1241ACu: goto label_1241ac;
            case 0x124208u: goto label_124208;
            case 0x124248u: goto label_124248;
            case 0x124258u: goto label_124258;
            case 0x12427Cu: goto label_12427c;
            case 0x124298u: goto label_124298;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242D8u: goto label_1242d8;
            case 0x12430Cu: goto label_12430c;
            case 0x12432Cu: goto label_12432c;
            case 0x124390u: goto label_124390;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243F8u: goto label_1243f8;
            case 0x124424u: goto label_124424;
            case 0x124440u: goto label_124440;
            case 0x124460u: goto label_124460;
            case 0x12446Cu: goto label_12446c;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244B8u: goto label_1244b8;
            case 0x124504u: goto label_124504;
            default: break;
        }
        return;
    }
    ctx->pc = 0x123EC0u;
    // 0x123ec0: 0x27bdffa0  addiu       $sp, $sp, -0x60
    ctx->pc = 0x123ec0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967200));
    // 0x123ec4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x123ec4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x123ec8: 0xffb00030  sd          $s0, 0x30($sp)
    ctx->pc = 0x123ec8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 48), GPR_U64(ctx, 16));
    // 0x123ecc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x123eccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123ed0: 0xffb10038  sd          $s1, 0x38($sp)
    ctx->pc = 0x123ed0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 56), GPR_U64(ctx, 17));
    // 0x123ed4: 0x2611000e  addiu       $s1, $s0, 0xE
    ctx->pc = 0x123ed4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 14));
    // 0x123ed8: 0xffb20040  sd          $s2, 0x40($sp)
    ctx->pc = 0x123ed8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 64), GPR_U64(ctx, 18));
    // 0x123edc: 0x26120010  addiu       $s2, $s0, 0x10
    ctx->pc = 0x123edcu;
    SET_GPR_S32(ctx, 18, (int32_t)ADD32(GPR_U32(ctx, 16), 16));
    // 0x123ee0: 0xffb30048  sd          $s3, 0x48($sp)
    ctx->pc = 0x123ee0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 72), GPR_U64(ctx, 19));
    // 0x123ee4: 0x2613000f  addiu       $s3, $s0, 0xF
    ctx->pc = 0x123ee4u;
    SET_GPR_S32(ctx, 19, (int32_t)ADD32(GPR_U32(ctx, 16), 15));
    // 0x123ee8: 0xffbf0050  sd          $ra, 0x50($sp)
    ctx->pc = 0x123ee8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 80), GPR_U64(ctx, 31));
    // 0x123eec: 0xa0202d  daddu       $a0, $a1, $zero
    ctx->pc = 0x123eecu;
    SET_GPR_U64(ctx, 4, (uint64_t)GPR_U64(ctx, 5) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123ef0: 0xa6020002  sh          $v0, 0x2($s0)
    ctx->pc = 0x123ef0u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 2), (uint16_t)GPR_U32(ctx, 2));
    // 0x123ef4: 0x26020018  addiu       $v0, $s0, 0x18
    ctx->pc = 0x123ef4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 16), 24));
    // 0x123ef8: 0xc0282d  daddu       $a1, $a2, $zero
    ctx->pc = 0x123ef8u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 6) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123efc: 0x27a60020  addiu       $a2, $sp, 0x20
    ctx->pc = 0x123efcu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
    // 0x123f00: 0x27a30024  addiu       $v1, $sp, 0x24
    ctx->pc = 0x123f00u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 29), 36));
    // 0x123f04: 0x2607000c  addiu       $a3, $s0, 0xC
    ctx->pc = 0x123f04u;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 12));
    // 0x123f08: 0x2608000d  addiu       $t0, $s0, 0xD
    ctx->pc = 0x123f08u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 16), 13));
    // 0x123f0c: 0x260482d  daddu       $t1, $s3, $zero
    ctx->pc = 0x123f0cu;
    SET_GPR_U64(ctx, 9, (uint64_t)GPR_U64(ctx, 19) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123f10: 0x220502d  daddu       $t2, $s1, $zero
    ctx->pc = 0x123f10u;
    SET_GPR_U64(ctx, 10, (uint64_t)GPR_U64(ctx, 17) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123f14: 0x260b0014  addiu       $t3, $s0, 0x14
    ctx->pc = 0x123f14u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 16), 20));
    // 0x123f18: 0xafa20000  sw          $v0, 0x0($sp)
    ctx->pc = 0x123f18u;
    WRITE32(ADD32(GPR_U32(ctx, 29), 0), GPR_U32(ctx, 2));
    // 0x123f1c: 0xafa30010  sw          $v1, 0x10($sp)
    ctx->pc = 0x123f1cu;
    WRITE32(ADD32(GPR_U32(ctx, 29), 16), GPR_U32(ctx, 3));
    // 0x123f20: 0xc048f6c  jal         func_123DB0
    ctx->pc = 0x123F20u;
    SET_GPR_U32(ctx, 31, 0x123F28u);
    ctx->pc = 0x123F24u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x123F20u;
            // 0x123f24: 0xafb20008  sw          $s2, 0x8($sp) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 29), 8), GPR_U32(ctx, 18));
        ctx->in_delay_slot = false;
    ctx->pc = 0x123DB0u;
    goto label_123db0;
    ctx->pc = 0x123F28u;
label_123f28:
    // 0x123f28: 0x4430003  bgezl       $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x123F28u;
    {
        const bool branch_taken_0x123f28 = (GPR_S64(ctx, 2) >= 0);
        if (branch_taken_0x123f28) {
            ctx->pc = 0x123F2Cu;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x123F28u;
            // 0x123f2c: 0xae000034  sw          $zero, 0x34($s0) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 16), 52), GPR_U32(ctx, 0));
        ctx->in_delay_slot = false;
            ctx->pc = 0x123F38u;
            goto label_123f38;
        }
    }
    ctx->pc = 0x123F30u;
    // 0x123f30: 0x1000001b  b           . + 4 + (0x1B << 2)
    ctx->pc = 0x123F30u;
    {
        const bool branch_taken_0x123f30 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x123F34u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123F30u;
            // 0x123f34: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123f30) {
            ctx->pc = 0x123FA0u;
            goto label_123fa0;
        }
    }
    ctx->pc = 0x123F38u;
label_123f38:
    // 0x123f38: 0xae000030  sw          $zero, 0x30($s0)
    ctx->pc = 0x123f38u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 48), GPR_U32(ctx, 0));
    // 0x123f3c: 0xae00002c  sw          $zero, 0x2C($s0)
    ctx->pc = 0x123f3cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 44), GPR_U32(ctx, 0));
    // 0x123f40: 0xae000028  sw          $zero, 0x28($s0)
    ctx->pc = 0x123f40u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 40), GPR_U32(ctx, 0));
    // 0x123f44: 0xae000020  sw          $zero, 0x20($s0)
    ctx->pc = 0x123f44u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 32), GPR_U32(ctx, 0));
    // 0x123f48: 0xa600001c  sh          $zero, 0x1C($s0)
    ctx->pc = 0x123f48u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 28), (uint16_t)GPR_U32(ctx, 0));
    // 0x123f4c: 0xa6000026  sh          $zero, 0x26($s0)
    ctx->pc = 0x123f4cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 38), (uint16_t)GPR_U32(ctx, 0));
    // 0x123f50: 0xa6000024  sh          $zero, 0x24($s0)
    ctx->pc = 0x123f50u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 36), (uint16_t)GPR_U32(ctx, 0));
    // 0x123f54: 0x8e05003c  lw          $a1, 0x3C($s0)
    ctx->pc = 0x123f54u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 60)));
    // 0x123f58: 0x82220000  lb          $v0, 0x0($s1)
    ctx->pc = 0x123f58u;
    SET_GPR_S32(ctx, 2, (int8_t)READ8(ADD32(GPR_U32(ctx, 17), 0)));
    // 0x123f5c: 0x97a40024  lhu         $a0, 0x24($sp)
    ctx->pc = 0x123f5cu;
    SET_GPR_U32(ctx, 4, (uint16_t)READ16(ADD32(GPR_U32(ctx, 29), 36)));
    // 0x123f60: 0xae020050  sw          $v0, 0x50($s0)
    ctx->pc = 0x123f60u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 80), GPR_U32(ctx, 2));
    // 0x123f64: 0x8e060040  lw          $a2, 0x40($s0)
    ctx->pc = 0x123f64u;
    SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 64)));
    // 0x123f68: 0x82630000  lb          $v1, 0x0($s3)
    ctx->pc = 0x123f68u;
    SET_GPR_S32(ctx, 3, (int8_t)READ8(ADD32(GPR_U32(ctx, 19), 0)));
    // 0x123f6c: 0x87a20020  lh          $v0, 0x20($sp)
    ctx->pc = 0x123f6cu;
    SET_GPR_S32(ctx, 2, (int16_t)READ16(ADD32(GPR_U32(ctx, 29), 32)));
    // 0x123f70: 0xae030054  sw          $v1, 0x54($s0)
    ctx->pc = 0x123f70u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 84), GPR_U32(ctx, 3));
    // 0x123f74: 0x24030004  addiu       $v1, $zero, 0x4
    ctx->pc = 0x123f74u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 4));
    // 0x123f78: 0x8e070044  lw          $a3, 0x44($s0)
    ctx->pc = 0x123f78u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 68)));
    // 0x123f7c: 0xa604009a  sh          $a0, 0x9A($s0)
    ctx->pc = 0x123f7cu;
    WRITE16(ADD32(GPR_U32(ctx, 16), 154), (uint16_t)GPR_U32(ctx, 4));
    // 0x123f80: 0x8e440000  lw          $a0, 0x0($s2)
    ctx->pc = 0x123f80u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 18), 0)));
    // 0x123f84: 0xae05005c  sw          $a1, 0x5C($s0)
    ctx->pc = 0x123f84u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 92), GPR_U32(ctx, 5));
    // 0x123f88: 0xa6030098  sh          $v1, 0x98($s0)
    ctx->pc = 0x123f88u;
    WRITE16(ADD32(GPR_U32(ctx, 16), 152), (uint16_t)GPR_U32(ctx, 3));
    // 0x123f8c: 0xae040058  sw          $a0, 0x58($s0)
    ctx->pc = 0x123f8cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 88), GPR_U32(ctx, 4));
    // 0x123f90: 0xae060060  sw          $a2, 0x60($s0)
    ctx->pc = 0x123f90u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 96), GPR_U32(ctx, 6));
    // 0x123f94: 0xae070064  sw          $a3, 0x64($s0)
    ctx->pc = 0x123f94u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 100), GPR_U32(ctx, 7));
    // 0x123f98: 0xae00008c  sw          $zero, 0x8C($s0)
    ctx->pc = 0x123f98u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 140), GPR_U32(ctx, 0));
    // 0x123f9c: 0xae000088  sw          $zero, 0x88($s0)
    ctx->pc = 0x123f9cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 136), GPR_U32(ctx, 0));
label_123fa0:
    // 0x123fa0: 0xdfb00030  ld          $s0, 0x30($sp)
    ctx->pc = 0x123fa0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 48)));
    // 0x123fa4: 0xdfb10038  ld          $s1, 0x38($sp)
    ctx->pc = 0x123fa4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 56)));
    // 0x123fa8: 0xdfb20040  ld          $s2, 0x40($sp)
    ctx->pc = 0x123fa8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 64)));
    // 0x123fac: 0xdfb30048  ld          $s3, 0x48($sp)
    ctx->pc = 0x123facu;
    SET_GPR_U64(ctx, 19, READ64(ADD32(GPR_U32(ctx, 29), 72)));
    // 0x123fb0: 0xdfbf0050  ld          $ra, 0x50($sp)
    ctx->pc = 0x123fb0u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 80)));
    // 0x123fb4: 0x3e00008  jr          $ra
    ctx->pc = 0x123FB4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x123FB8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123FB4u;
            // 0x123fb8: 0x27bd0060  addiu       $sp, $sp, 0x60 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 96));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123E18u: goto label_123e18;
            case 0x123E20u: goto label_123e20;
            case 0x123E98u: goto label_123e98;
            case 0x123F28u: goto label_123f28;
            case 0x123F38u: goto label_123f38;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FF4u: goto label_123ff4;
            case 0x124014u: goto label_124014;
            case 0x124070u: goto label_124070;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240F8u: goto label_1240f8;
            case 0x124118u: goto label_124118;
            case 0x124138u: goto label_124138;
            case 0x124144u: goto label_124144;
            case 0x124158u: goto label_124158;
            case 0x12418Cu: goto label_12418c;
            case 0x1241ACu: goto label_1241ac;
            case 0x124208u: goto label_124208;
            case 0x124248u: goto label_124248;
            case 0x124258u: goto label_124258;
            case 0x12427Cu: goto label_12427c;
            case 0x124298u: goto label_124298;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242D8u: goto label_1242d8;
            case 0x12430Cu: goto label_12430c;
            case 0x12432Cu: goto label_12432c;
            case 0x124390u: goto label_124390;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243F8u: goto label_1243f8;
            case 0x124424u: goto label_124424;
            case 0x124440u: goto label_124440;
            case 0x124460u: goto label_124460;
            case 0x12446Cu: goto label_12446c;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244B8u: goto label_1244b8;
            case 0x124504u: goto label_124504;
            default: break;
        }
        return;
    }
    ctx->pc = 0x123FBCu;
    // 0x123fbc: 0x0  nop
    ctx->pc = 0x123fbcu;
    // NOP
label_123fc0:
    // 0x123fc0: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x123fc0u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x123fc4: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x123fc4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x123fc8: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x123fc8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x123fcc: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x123fccu;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x123fd0: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x123fd0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x123fd4: 0x26110048  addiu       $s1, $s0, 0x48
    ctx->pc = 0x123fd4u;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
    // 0x123fd8: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x123fd8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x123fdc: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x123fdcu;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x123fe0: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x123fe0u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x123fe4: 0x1462004c  bne         $v1, $v0, . + 4 + (0x4C << 2)
    ctx->pc = 0x123FE4u;
    {
        const bool branch_taken_0x123fe4 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x123FE8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x123FE4u;
            // 0x123fe8: 0x8e320000  lw          $s2, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x123fe4) {
            ctx->pc = 0x124118u;
            goto label_124118;
        }
    }
    ctx->pc = 0x123FECu;
    // 0x123fec: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x123FECu;
    SET_GPR_U32(ctx, 31, 0x123FF4u);
    ctx->pc = 0x123FF0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x123FECu;
            // 0x123ff0: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x123FF4u; }
        if (ctx->pc != 0x123FF4u) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x123FF4u; }
        if (ctx->pc != 0x123FF4u) { return; }
    }
    ctx->pc = 0x123FF4u;
label_123ff4:
    // 0x123ff4: 0x54400048  bnel        $v0, $zero, . + 4 + (0x48 << 2)
    ctx->pc = 0x123FF4u;
    {
        const bool branch_taken_0x123ff4 = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x123ff4) {
            ctx->pc = 0x123FF8u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x123FF4u;
            // 0x123ff8: 0x8e030004  lw          $v1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x124118u;
            goto label_124118;
        }
    }
    ctx->pc = 0x123FFCu;
    // 0x123ffc: 0x8e04007c  lw          $a0, 0x7C($s0)
    ctx->pc = 0x123ffcu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x124000: 0x26050068  addiu       $a1, $s0, 0x68
    ctx->pc = 0x124000u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 104));
    // 0x124004: 0x8e020078  lw          $v0, 0x78($s0)
    ctx->pc = 0x124004u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x124008: 0x2606006c  addiu       $a2, $s0, 0x6C
    ctx->pc = 0x124008u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 108));
    // 0x12400c: 0x40f809  jalr        $v0
    ctx->pc = 0x12400Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x124014u);
        ctx->pc = 0x124010u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12400Cu;
            // 0x124010: 0x26070070  addiu       $a3, $s0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x124014u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123E18u: goto label_123e18;
            case 0x123E20u: goto label_123e20;
            case 0x123E98u: goto label_123e98;
            case 0x123F28u: goto label_123f28;
            case 0x123F38u: goto label_123f38;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FF4u: goto label_123ff4;
            case 0x124014u: goto label_124014;
            case 0x124070u: goto label_124070;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240F8u: goto label_1240f8;
            case 0x124118u: goto label_124118;
            case 0x124138u: goto label_124138;
            case 0x124144u: goto label_124144;
            case 0x124158u: goto label_124158;
            case 0x12418Cu: goto label_12418c;
            case 0x1241ACu: goto label_1241ac;
            case 0x124208u: goto label_124208;
            case 0x124248u: goto label_124248;
            case 0x124258u: goto label_124258;
            case 0x12427Cu: goto label_12427c;
            case 0x124298u: goto label_124298;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242D8u: goto label_1242d8;
            case 0x12430Cu: goto label_12430c;
            case 0x12432Cu: goto label_12432c;
            case 0x124390u: goto label_124390;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243F8u: goto label_1243f8;
            case 0x124424u: goto label_124424;
            case 0x124440u: goto label_124440;
            case 0x124460u: goto label_124460;
            case 0x12446Cu: goto label_12446c;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244B8u: goto label_1244b8;
            case 0x124504u: goto label_124504;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x124014u; }
            if (ctx->pc != 0x124014u) { return; }
        }
        }
    }
    ctx->pc = 0x124014u;
label_124014:
    // 0x124014: 0x8e240018  lw          $a0, 0x18($s1)
    ctx->pc = 0x124014u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x124018: 0x8e270020  lw          $a3, 0x20($s1)
    ctx->pc = 0x124018u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x12401c: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x12401cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x124020: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x124020u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x124024: 0x874823  subu        $t1, $a0, $a3
    ctx->pc = 0x124024u;
    SET_GPR_S32(ctx, 9, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x124028: 0x8204000e  lb          $a0, 0xE($s0)
    ctx->pc = 0x124028u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x12402c: 0x69102a  slt         $v0, $v1, $t1
    ctx->pc = 0x12402cu;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x124030: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x124030u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x124034: 0x62480b  movn        $t1, $v1, $v0
    ctx->pc = 0x124034u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 3));
    // 0x124038: 0x71840  sll         $v1, $a3, 1
    ctx->pc = 0x124038u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x12403c: 0x8e2b0014  lw          $t3, 0x14($s1)
    ctx->pc = 0x12403cu;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x124040: 0xa9102a  slt         $v0, $a1, $t1
    ctx->pc = 0x124040u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x124044: 0xa2480b  movn        $t1, $a1, $v0
    ctx->pc = 0x124044u;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 5));
    // 0x124048: 0x1635021  addu        $t2, $t3, $v1
    ctx->pc = 0x124048u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 3)));
    // 0x12404c: 0x1486001c  bne         $a0, $a2, . + 4 + (0x1C << 2)
    ctx->pc = 0x12404Cu;
    {
        const bool branch_taken_0x12404c = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        ctx->pc = 0x124050u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12404Cu;
            // 0x124050: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12404c) {
            ctx->pc = 0x1240C0u;
            goto label_1240c0;
        }
    }
    ctx->pc = 0x124054u;
    // 0x124054: 0x8e22001c  lw          $v0, 0x1C($s1)
    ctx->pc = 0x124054u;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x124058: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x124058u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12405c: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x12405cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x124060: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x124060u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x124064: 0x19200024  blez        $t1, . + 4 + (0x24 << 2)
    ctx->pc = 0x124064u;
    {
        const bool branch_taken_0x124064 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x124068u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124064u;
            // 0x124068: 0x1625821  addu        $t3, $t3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124064) {
            ctx->pc = 0x1240F8u;
            goto label_1240f8;
        }
    }
    ctx->pc = 0x12406Cu;
    // 0x12406c: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x12406cu;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_124070:
    // 0x124070: 0x94e20000  lhu         $v0, 0x0($a3)
    ctx->pc = 0x124070u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x124074: 0x82040  sll         $a0, $t0, 1
    ctx->pc = 0x124074u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x124078: 0x8a2821  addu        $a1, $a0, $t2
    ctx->pc = 0x124078u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 10)));
    // 0x12407c: 0x8b2021  addu        $a0, $a0, $t3
    ctx->pc = 0x12407cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
    // 0x124080: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x124080u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x124084: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x124084u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x124088: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x124088u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x12408c: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x12408cu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x124090: 0xa4a20000  sh          $v0, 0x0($a1)
    ctx->pc = 0x124090u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x124094: 0x109302a  slt         $a2, $t0, $t1
    ctx->pc = 0x124094u;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x124098: 0x94e20002  lhu         $v0, 0x2($a3)
    ctx->pc = 0x124098u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 7), 2)));
    // 0x12409c: 0x24e70004  addiu       $a3, $a3, 0x4
    ctx->pc = 0x12409cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 4));
    // 0x1240a0: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x1240a0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1240a4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1240a4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1240a8: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1240a8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1240ac: 0x14c0fff0  bnez        $a2, . + 4 + (-0x10 << 2)
    ctx->pc = 0x1240ACu;
    {
        const bool branch_taken_0x1240ac = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1240B0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1240ACu;
            // 0x1240b0: 0xa4820000  sh          $v0, 0x0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1240ac) {
            ctx->pc = 0x124070u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_124070;
        }
    }
    ctx->pc = 0x1240B4u;
    // 0x1240b4: 0x10000010  b           . + 4 + (0x10 << 2)
    ctx->pc = 0x1240B4u;
    {
        const bool branch_taken_0x1240b4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1240B8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1240B4u;
            // 0x1240b8: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1240b4) {
            ctx->pc = 0x1240F8u;
            goto label_1240f8;
        }
    }
    ctx->pc = 0x1240BCu;
    // 0x1240bc: 0x0  nop
    ctx->pc = 0x1240bcu;
    // NOP
label_1240c0:
    // 0x1240c0: 0x1920000d  blez        $t1, . + 4 + (0xD << 2)
    ctx->pc = 0x1240C0u;
    {
        const bool branch_taken_0x1240c0 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x1240C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1240C0u;
            // 0x1240c4: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1240c0) {
            ctx->pc = 0x1240F8u;
            goto label_1240f8;
        }
    }
    ctx->pc = 0x1240C8u;
label_1240c8:
    // 0x1240c8: 0x82040  sll         $a0, $t0, 1
    ctx->pc = 0x1240c8u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x1240cc: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1240ccu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1240d0: 0x921021  addu        $v0, $a0, $s2
    ctx->pc = 0x1240d0u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 18)));
    // 0x1240d4: 0x8a2021  addu        $a0, $a0, $t2
    ctx->pc = 0x1240d4u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 10)));
    // 0x1240d8: 0x94420000  lhu         $v0, 0x0($v0)
    ctx->pc = 0x1240d8u;
    SET_GPR_U32(ctx, 2, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1240dc: 0x109282a  slt         $a1, $t0, $t1
    ctx->pc = 0x1240dcu;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x1240e0: 0x21a00  sll         $v1, $v0, 8
    ctx->pc = 0x1240e0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x1240e4: 0x21202  srl         $v0, $v0, 8
    ctx->pc = 0x1240e4u;
    SET_GPR_S32(ctx, 2, (int32_t)SRL32(GPR_U32(ctx, 2), 8));
    // 0x1240e8: 0x431025  or          $v0, $v0, $v1
    ctx->pc = 0x1240e8u;
    SET_GPR_U64(ctx, 2, GPR_U64(ctx, 2) | GPR_U64(ctx, 3));
    // 0x1240ec: 0x14a0fff6  bnez        $a1, . + 4 + (-0xA << 2)
    ctx->pc = 0x1240ECu;
    {
        const bool branch_taken_0x1240ec = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x1240F0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1240ECu;
            // 0x1240f0: 0xa4820000  sh          $v0, 0x0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1240ec) {
            ctx->pc = 0x1240C8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1240c8;
        }
    }
    ctx->pc = 0x1240F4u;
    // 0x1240f4: 0x9203000e  lbu         $v1, 0xE($s0)
    ctx->pc = 0x1240f4u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_1240f8:
    // 0x1240f8: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x1240f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x1240fc: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x1240fcu;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x124100: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x124100u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x124104: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x124104u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x124108: 0x1221018  mult        $v0, $t1, $v0
    ctx->pc = 0x124108u;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x12410c: 0xae090090  sw          $t1, 0x90($s0)
    ctx->pc = 0x12410cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 9));
    // 0x124110: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x124110u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x124114: 0xae020094  sw          $v0, 0x94($s0)
    ctx->pc = 0x124114u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
label_124118:
    // 0x124118: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x124118u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12411c: 0x54620009  bnel        $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x12411Cu;
    {
        const bool branch_taken_0x12411c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x12411c) {
            ctx->pc = 0x124120u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12411Cu;
            // 0x124120: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x124144u;
            goto label_124144;
        }
    }
    ctx->pc = 0x124124u;
    // 0x124124: 0x8e030080  lw          $v1, 0x80($s0)
    ctx->pc = 0x124124u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x124128: 0x8e040084  lw          $a0, 0x84($s0)
    ctx->pc = 0x124128u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x12412c: 0x8e050094  lw          $a1, 0x94($s0)
    ctx->pc = 0x12412cu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x124130: 0x60f809  jalr        $v1
    ctx->pc = 0x124130u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x124138u);
        ctx->pc = 0x124134u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124130u;
            // 0x124134: 0x8e060090  lw          $a2, 0x90($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x124138u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123E18u: goto label_123e18;
            case 0x123E20u: goto label_123e20;
            case 0x123E98u: goto label_123e98;
            case 0x123F28u: goto label_123f28;
            case 0x123F38u: goto label_123f38;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FF4u: goto label_123ff4;
            case 0x124014u: goto label_124014;
            case 0x124070u: goto label_124070;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240F8u: goto label_1240f8;
            case 0x124118u: goto label_124118;
            case 0x124138u: goto label_124138;
            case 0x124144u: goto label_124144;
            case 0x124158u: goto label_124158;
            case 0x12418Cu: goto label_12418c;
            case 0x1241ACu: goto label_1241ac;
            case 0x124208u: goto label_124208;
            case 0x124248u: goto label_124248;
            case 0x124258u: goto label_124258;
            case 0x12427Cu: goto label_12427c;
            case 0x124298u: goto label_124298;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242D8u: goto label_1242d8;
            case 0x12430Cu: goto label_12430c;
            case 0x12432Cu: goto label_12432c;
            case 0x124390u: goto label_124390;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243F8u: goto label_1243f8;
            case 0x124424u: goto label_124424;
            case 0x124440u: goto label_124440;
            case 0x124460u: goto label_124460;
            case 0x12446Cu: goto label_12446c;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244B8u: goto label_1244b8;
            case 0x124504u: goto label_124504;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x124138u; }
            if (ctx->pc != 0x124138u) { return; }
        }
        }
    }
    ctx->pc = 0x124138u;
label_124138:
    // 0x124138: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x124138u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x12413c: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x12413cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x124140: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x124140u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_124144:
    // 0x124144: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x124144u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x124148: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x124148u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x12414c: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x12414cu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x124150: 0x3e00008  jr          $ra
    ctx->pc = 0x124150u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124154u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124150u;
            // 0x124154: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123E18u: goto label_123e18;
            case 0x123E20u: goto label_123e20;
            case 0x123E98u: goto label_123e98;
            case 0x123F28u: goto label_123f28;
            case 0x123F38u: goto label_123f38;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FF4u: goto label_123ff4;
            case 0x124014u: goto label_124014;
            case 0x124070u: goto label_124070;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240F8u: goto label_1240f8;
            case 0x124118u: goto label_124118;
            case 0x124138u: goto label_124138;
            case 0x124144u: goto label_124144;
            case 0x124158u: goto label_124158;
            case 0x12418Cu: goto label_12418c;
            case 0x1241ACu: goto label_1241ac;
            case 0x124208u: goto label_124208;
            case 0x124248u: goto label_124248;
            case 0x124258u: goto label_124258;
            case 0x12427Cu: goto label_12427c;
            case 0x124298u: goto label_124298;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242D8u: goto label_1242d8;
            case 0x12430Cu: goto label_12430c;
            case 0x12432Cu: goto label_12432c;
            case 0x124390u: goto label_124390;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243F8u: goto label_1243f8;
            case 0x124424u: goto label_124424;
            case 0x124440u: goto label_124440;
            case 0x124460u: goto label_124460;
            case 0x12446Cu: goto label_12446c;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244B8u: goto label_1244b8;
            case 0x124504u: goto label_124504;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124158u;
label_124158:
    // 0x124158: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x124158u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x12415c: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x12415cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x124160: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x124160u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x124164: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x124164u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124168: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x124168u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x12416c: 0x26110048  addiu       $s1, $s0, 0x48
    ctx->pc = 0x12416cu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
    // 0x124170: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x124170u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x124174: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x124174u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x124178: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x124178u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x12417c: 0x14620046  bne         $v1, $v0, . + 4 + (0x46 << 2)
    ctx->pc = 0x12417Cu;
    {
        const bool branch_taken_0x12417c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x124180u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12417Cu;
            // 0x124180: 0x8e320000  lw          $s2, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12417c) {
            ctx->pc = 0x124298u;
            goto label_124298;
        }
    }
    ctx->pc = 0x124184u;
    // 0x124184: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x124184u;
    SET_GPR_U32(ctx, 31, 0x12418Cu);
    ctx->pc = 0x124188u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124184u;
            // 0x124188: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12418Cu; }
        if (ctx->pc != 0x12418Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12418Cu; }
        if (ctx->pc != 0x12418Cu) { return; }
    }
    ctx->pc = 0x12418Cu;
label_12418c:
    // 0x12418c: 0x54400042  bnel        $v0, $zero, . + 4 + (0x42 << 2)
    ctx->pc = 0x12418Cu;
    {
        const bool branch_taken_0x12418c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12418c) {
            ctx->pc = 0x124190u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12418Cu;
            // 0x124190: 0x8e030004  lw          $v1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x124298u;
            goto label_124298;
        }
    }
    ctx->pc = 0x124194u;
    // 0x124194: 0x8e04007c  lw          $a0, 0x7C($s0)
    ctx->pc = 0x124194u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x124198: 0x26050068  addiu       $a1, $s0, 0x68
    ctx->pc = 0x124198u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 104));
    // 0x12419c: 0x8e020078  lw          $v0, 0x78($s0)
    ctx->pc = 0x12419cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x1241a0: 0x2606006c  addiu       $a2, $s0, 0x6C
    ctx->pc = 0x1241a0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 108));
    // 0x1241a4: 0x40f809  jalr        $v0
    ctx->pc = 0x1241A4u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x1241ACu);
        ctx->pc = 0x1241A8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1241A4u;
            // 0x1241a8: 0x26070070  addiu       $a3, $s0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1241ACu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123E18u: goto label_123e18;
            case 0x123E20u: goto label_123e20;
            case 0x123E98u: goto label_123e98;
            case 0x123F28u: goto label_123f28;
            case 0x123F38u: goto label_123f38;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FF4u: goto label_123ff4;
            case 0x124014u: goto label_124014;
            case 0x124070u: goto label_124070;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240F8u: goto label_1240f8;
            case 0x124118u: goto label_124118;
            case 0x124138u: goto label_124138;
            case 0x124144u: goto label_124144;
            case 0x124158u: goto label_124158;
            case 0x12418Cu: goto label_12418c;
            case 0x1241ACu: goto label_1241ac;
            case 0x124208u: goto label_124208;
            case 0x124248u: goto label_124248;
            case 0x124258u: goto label_124258;
            case 0x12427Cu: goto label_12427c;
            case 0x124298u: goto label_124298;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242D8u: goto label_1242d8;
            case 0x12430Cu: goto label_12430c;
            case 0x12432Cu: goto label_12432c;
            case 0x124390u: goto label_124390;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243F8u: goto label_1243f8;
            case 0x124424u: goto label_124424;
            case 0x124440u: goto label_124440;
            case 0x124460u: goto label_124460;
            case 0x12446Cu: goto label_12446c;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244B8u: goto label_1244b8;
            case 0x124504u: goto label_124504;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1241ACu; }
            if (ctx->pc != 0x1241ACu) { return; }
        }
        }
    }
    ctx->pc = 0x1241ACu;
label_1241ac:
    // 0x1241ac: 0x8e240018  lw          $a0, 0x18($s1)
    ctx->pc = 0x1241acu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x1241b0: 0x8e290020  lw          $t1, 0x20($s1)
    ctx->pc = 0x1241b0u;
    SET_GPR_S32(ctx, 9, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x1241b4: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x1241b4u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x1241b8: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x1241b8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x1241bc: 0x894023  subu        $t0, $a0, $t1
    ctx->pc = 0x1241bcu;
    SET_GPR_S32(ctx, 8, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 9)));
    // 0x1241c0: 0x8204000e  lb          $a0, 0xE($s0)
    ctx->pc = 0x1241c0u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x1241c4: 0x68102a  slt         $v0, $v1, $t0
    ctx->pc = 0x1241c4u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x1241c8: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x1241c8u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x1241cc: 0x62400b  movn        $t0, $v1, $v0
    ctx->pc = 0x1241ccu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 8, GPR_VEC(ctx, 3));
    // 0x1241d0: 0x91840  sll         $v1, $t1, 1
    ctx->pc = 0x1241d0u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 9), 1));
    // 0x1241d4: 0x8e2b0014  lw          $t3, 0x14($s1)
    ctx->pc = 0x1241d4u;
    SET_GPR_S32(ctx, 11, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x1241d8: 0xa8102a  slt         $v0, $a1, $t0
    ctx->pc = 0x1241d8u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x1241dc: 0xa2400b  movn        $t0, $a1, $v0
    ctx->pc = 0x1241dcu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 8, GPR_VEC(ctx, 5));
    // 0x1241e0: 0x1635021  addu        $t2, $t3, $v1
    ctx->pc = 0x1241e0u;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 3)));
    // 0x1241e4: 0x14860018  bne         $a0, $a2, . + 4 + (0x18 << 2)
    ctx->pc = 0x1241E4u;
    {
        const bool branch_taken_0x1241e4 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        ctx->pc = 0x1241E8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1241E4u;
            // 0x1241e8: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1241e4) {
            ctx->pc = 0x124248u;
            goto label_124248;
        }
    }
    ctx->pc = 0x1241ECu;
    // 0x1241ec: 0x8e22001c  lw          $v0, 0x1C($s1)
    ctx->pc = 0x1241ecu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x1241f0: 0x382d  daddu       $a3, $zero, $zero
    ctx->pc = 0x1241f0u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1241f4: 0x491021  addu        $v0, $v0, $t1
    ctx->pc = 0x1241f4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 9)));
    // 0x1241f8: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1241f8u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1241fc: 0x1900001f  blez        $t0, . + 4 + (0x1F << 2)
    ctx->pc = 0x1241FCu;
    {
        const bool branch_taken_0x1241fc = (GPR_S64(ctx, 8) <= 0);
        ctx->pc = 0x124200u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1241FCu;
            // 0x124200: 0x1624821  addu        $t1, $t3, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 9, (int32_t)ADD32(GPR_U32(ctx, 11), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1241fc) {
            ctx->pc = 0x12427Cu;
            goto label_12427c;
        }
    }
    ctx->pc = 0x124204u;
    // 0x124204: 0x240302d  daddu       $a2, $s2, $zero
    ctx->pc = 0x124204u;
    SET_GPR_U64(ctx, 6, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
label_124208:
    // 0x124208: 0x90c20000  lbu         $v0, 0x0($a2)
    ctx->pc = 0x124208u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 0)));
    // 0x12420c: 0x71840  sll         $v1, $a3, 1
    ctx->pc = 0x12420cu;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x124210: 0x6a2021  addu        $a0, $v1, $t2
    ctx->pc = 0x124210u;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 10)));
    // 0x124214: 0x691821  addu        $v1, $v1, $t1
    ctx->pc = 0x124214u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 3), GPR_U32(ctx, 9)));
    // 0x124218: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x124218u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x12421c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x12421cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x124220: 0xa4820000  sh          $v0, 0x0($a0)
    ctx->pc = 0x124220u;
    WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 2));
    // 0x124224: 0xe8282a  slt         $a1, $a3, $t0
    ctx->pc = 0x124224u;
    SET_GPR_U64(ctx, 5, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x124228: 0x90c20001  lbu         $v0, 0x1($a2)
    ctx->pc = 0x124228u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 6), 1)));
    // 0x12422c: 0x24c60002  addiu       $a2, $a2, 0x2
    ctx->pc = 0x12422cu;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 6), 2));
    // 0x124230: 0x21200  sll         $v0, $v0, 8
    ctx->pc = 0x124230u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 8));
    // 0x124234: 0x14a0fff4  bnez        $a1, . + 4 + (-0xC << 2)
    ctx->pc = 0x124234u;
    {
        const bool branch_taken_0x124234 = (GPR_U64(ctx, 5) != GPR_U64(ctx, 0));
        ctx->pc = 0x124238u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124234u;
            // 0x124238: 0xa4620000  sh          $v0, 0x0($v1) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 3), 0), (uint16_t)GPR_U32(ctx, 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124234) {
            ctx->pc = 0x124208u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_124208;
        }
    }
    ctx->pc = 0x12423Cu;
    // 0x12423c: 0x1000000f  b           . + 4 + (0xF << 2)
    ctx->pc = 0x12423Cu;
    {
        const bool branch_taken_0x12423c = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x124240u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12423Cu;
            // 0x124240: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12423c) {
            ctx->pc = 0x12427Cu;
            goto label_12427c;
        }
    }
    ctx->pc = 0x124244u;
    // 0x124244: 0x0  nop
    ctx->pc = 0x124244u;
    // NOP
label_124248:
    // 0x124248: 0x1900000c  blez        $t0, . + 4 + (0xC << 2)
    ctx->pc = 0x124248u;
    {
        const bool branch_taken_0x124248 = (GPR_S64(ctx, 8) <= 0);
        ctx->pc = 0x12424Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124248u;
            // 0x12424c: 0x382d  daddu       $a3, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124248) {
            ctx->pc = 0x12427Cu;
            goto label_12427c;
        }
    }
    ctx->pc = 0x124250u;
    // 0x124250: 0x140282d  daddu       $a1, $t2, $zero
    ctx->pc = 0x124250u;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 10) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124254: 0x0  nop
    ctx->pc = 0x124254u;
    // NOP
label_124258:
    // 0x124258: 0x2471021  addu        $v0, $s2, $a3
    ctx->pc = 0x124258u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 7)));
    // 0x12425c: 0x24e70001  addiu       $a3, $a3, 0x1
    ctx->pc = 0x12425cu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 1));
    // 0x124260: 0x90430000  lbu         $v1, 0x0($v0)
    ctx->pc = 0x124260u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x124264: 0xe8202a  slt         $a0, $a3, $t0
    ctx->pc = 0x124264u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 7) < (int64_t)GPR_S64(ctx, 8)) ? 1 : 0);
    // 0x124268: 0x31a00  sll         $v1, $v1, 8
    ctx->pc = 0x124268u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 3), 8));
    // 0x12426c: 0xa4a30000  sh          $v1, 0x0($a1)
    ctx->pc = 0x12426cu;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x124270: 0x1480fff9  bnez        $a0, . + 4 + (-0x7 << 2)
    ctx->pc = 0x124270u;
    {
        const bool branch_taken_0x124270 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x124274u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124270u;
            // 0x124274: 0x24a50002  addiu       $a1, $a1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124270) {
            ctx->pc = 0x124258u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_124258;
        }
    }
    ctx->pc = 0x124278u;
    // 0x124278: 0x9203000e  lbu         $v1, 0xE($s0)
    ctx->pc = 0x124278u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_12427c:
    // 0x12427c: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x12427cu;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x124280: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x124280u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x124284: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x124284u;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x124288: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x124288u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x12428c: 0x1021018  mult        $v0, $t0, $v0
    ctx->pc = 0x12428cu;
    { int64_t result = (int64_t)GPR_S32(ctx, 8) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x124290: 0xae080090  sw          $t0, 0x90($s0)
    ctx->pc = 0x124290u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 8));
    // 0x124294: 0xae020094  sw          $v0, 0x94($s0)
    ctx->pc = 0x124294u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
label_124298:
    // 0x124298: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x124298u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12429c: 0x54620009  bnel        $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x12429Cu;
    {
        const bool branch_taken_0x12429c = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x12429c) {
            ctx->pc = 0x1242A0u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12429Cu;
            // 0x1242a0: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x1242C4u;
            goto label_1242c4;
        }
    }
    ctx->pc = 0x1242A4u;
    // 0x1242a4: 0x8e030080  lw          $v1, 0x80($s0)
    ctx->pc = 0x1242a4u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x1242a8: 0x8e040084  lw          $a0, 0x84($s0)
    ctx->pc = 0x1242a8u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x1242ac: 0x8e050094  lw          $a1, 0x94($s0)
    ctx->pc = 0x1242acu;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x1242b0: 0x60f809  jalr        $v1
    ctx->pc = 0x1242B0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x1242B8u);
        ctx->pc = 0x1242B4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1242B0u;
            // 0x1242b4: 0x8e060090  lw          $a2, 0x90($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x1242B8u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123E18u: goto label_123e18;
            case 0x123E20u: goto label_123e20;
            case 0x123E98u: goto label_123e98;
            case 0x123F28u: goto label_123f28;
            case 0x123F38u: goto label_123f38;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FF4u: goto label_123ff4;
            case 0x124014u: goto label_124014;
            case 0x124070u: goto label_124070;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240F8u: goto label_1240f8;
            case 0x124118u: goto label_124118;
            case 0x124138u: goto label_124138;
            case 0x124144u: goto label_124144;
            case 0x124158u: goto label_124158;
            case 0x12418Cu: goto label_12418c;
            case 0x1241ACu: goto label_1241ac;
            case 0x124208u: goto label_124208;
            case 0x124248u: goto label_124248;
            case 0x124258u: goto label_124258;
            case 0x12427Cu: goto label_12427c;
            case 0x124298u: goto label_124298;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242D8u: goto label_1242d8;
            case 0x12430Cu: goto label_12430c;
            case 0x12432Cu: goto label_12432c;
            case 0x124390u: goto label_124390;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243F8u: goto label_1243f8;
            case 0x124424u: goto label_124424;
            case 0x124440u: goto label_124440;
            case 0x124460u: goto label_124460;
            case 0x12446Cu: goto label_12446c;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244B8u: goto label_1244b8;
            case 0x124504u: goto label_124504;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x1242B8u; }
            if (ctx->pc != 0x1242B8u) { return; }
        }
        }
    }
    ctx->pc = 0x1242B8u;
label_1242b8:
    // 0x1242b8: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x1242b8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x1242bc: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x1242bcu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x1242c0: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x1242c0u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_1242c4:
    // 0x1242c4: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x1242c4u;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x1242c8: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x1242c8u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x1242cc: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x1242ccu;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x1242d0: 0x3e00008  jr          $ra
    ctx->pc = 0x1242D0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1242D4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1242D0u;
            // 0x1242d4: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123E18u: goto label_123e18;
            case 0x123E20u: goto label_123e20;
            case 0x123E98u: goto label_123e98;
            case 0x123F28u: goto label_123f28;
            case 0x123F38u: goto label_123f38;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FF4u: goto label_123ff4;
            case 0x124014u: goto label_124014;
            case 0x124070u: goto label_124070;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240F8u: goto label_1240f8;
            case 0x124118u: goto label_124118;
            case 0x124138u: goto label_124138;
            case 0x124144u: goto label_124144;
            case 0x124158u: goto label_124158;
            case 0x12418Cu: goto label_12418c;
            case 0x1241ACu: goto label_1241ac;
            case 0x124208u: goto label_124208;
            case 0x124248u: goto label_124248;
            case 0x124258u: goto label_124258;
            case 0x12427Cu: goto label_12427c;
            case 0x124298u: goto label_124298;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242D8u: goto label_1242d8;
            case 0x12430Cu: goto label_12430c;
            case 0x12432Cu: goto label_12432c;
            case 0x124390u: goto label_124390;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243F8u: goto label_1243f8;
            case 0x124424u: goto label_124424;
            case 0x124440u: goto label_124440;
            case 0x124460u: goto label_124460;
            case 0x12446Cu: goto label_12446c;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244B8u: goto label_1244b8;
            case 0x124504u: goto label_124504;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1242D8u;
label_1242d8:
    // 0x1242d8: 0x27bdffe0  addiu       $sp, $sp, -0x20
    ctx->pc = 0x1242d8u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967264));
    // 0x1242dc: 0x24020001  addiu       $v0, $zero, 0x1
    ctx->pc = 0x1242dcu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
    // 0x1242e0: 0xffb00000  sd          $s0, 0x0($sp)
    ctx->pc = 0x1242e0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 16));
    // 0x1242e4: 0x80802d  daddu       $s0, $a0, $zero
    ctx->pc = 0x1242e4u;
    SET_GPR_U64(ctx, 16, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1242e8: 0xffb10008  sd          $s1, 0x8($sp)
    ctx->pc = 0x1242e8u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 8), GPR_U64(ctx, 17));
    // 0x1242ec: 0x26110048  addiu       $s1, $s0, 0x48
    ctx->pc = 0x1242ecu;
    SET_GPR_S32(ctx, 17, (int32_t)ADD32(GPR_U32(ctx, 16), 72));
    // 0x1242f0: 0xffb20010  sd          $s2, 0x10($sp)
    ctx->pc = 0x1242f0u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 16), GPR_U64(ctx, 18));
    // 0x1242f4: 0xffbf0018  sd          $ra, 0x18($sp)
    ctx->pc = 0x1242f4u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 24), GPR_U64(ctx, 31));
    // 0x1242f8: 0x8e030004  lw          $v1, 0x4($s0)
    ctx->pc = 0x1242f8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
    // 0x1242fc: 0x14620050  bne         $v1, $v0, . + 4 + (0x50 << 2)
    ctx->pc = 0x1242FCu;
    {
        const bool branch_taken_0x1242fc = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x124300u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1242FCu;
            // 0x124300: 0x8e320000  lw          $s2, 0x0($s1) (Delay Slot)
        SET_GPR_S32(ctx, 18, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1242fc) {
            ctx->pc = 0x124440u;
            goto label_124440;
        }
    }
    ctx->pc = 0x124304u;
    // 0x124304: 0xc04d3e6  jal         func_134F98
    ctx->pc = 0x124304u;
    SET_GPR_U32(ctx, 31, 0x12430Cu);
    ctx->pc = 0x124308u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x124304u;
            // 0x124308: 0x8e040008  lw          $a0, 0x8($s0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 8)));
        ctx->in_delay_slot = false;
    ctx->pc = 0x134F98u;
    if (runtime->hasFunction(0x134F98u)) {
        auto targetFn = runtime->lookupFunction(0x134F98u);
        const uint32_t __entryPc = ctx->pc;
        targetFn(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12430Cu; }
        if (ctx->pc != 0x12430Cu) { return; }
    } else {
        const uint32_t __entryPc = ctx->pc;
        sub_00134F98_0x134f98(rdram, ctx, runtime);
        if (ctx->pc == __entryPc) { ctx->pc = 0x12430Cu; }
        if (ctx->pc != 0x12430Cu) { return; }
    }
    ctx->pc = 0x12430Cu;
label_12430c:
    // 0x12430c: 0x5440004c  bnel        $v0, $zero, . + 4 + (0x4C << 2)
    ctx->pc = 0x12430Cu;
    {
        const bool branch_taken_0x12430c = (GPR_U64(ctx, 2) != GPR_U64(ctx, 0));
        if (branch_taken_0x12430c) {
            ctx->pc = 0x124310u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x12430Cu;
            // 0x124310: 0x8e030004  lw          $v1, 0x4($s0) (Delay Slot)
        SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 4)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x124440u;
            goto label_124440;
        }
    }
    ctx->pc = 0x124314u;
    // 0x124314: 0x8e04007c  lw          $a0, 0x7C($s0)
    ctx->pc = 0x124314u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 124)));
    // 0x124318: 0x26050068  addiu       $a1, $s0, 0x68
    ctx->pc = 0x124318u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 16), 104));
    // 0x12431c: 0x8e020078  lw          $v0, 0x78($s0)
    ctx->pc = 0x12431cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 120)));
    // 0x124320: 0x2606006c  addiu       $a2, $s0, 0x6C
    ctx->pc = 0x124320u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 16), 108));
    // 0x124324: 0x40f809  jalr        $v0
    ctx->pc = 0x124324u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 2);
        SET_GPR_U32(ctx, 31, 0x12432Cu);
        ctx->pc = 0x124328u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124324u;
            // 0x124328: 0x26070070  addiu       $a3, $s0, 0x70 (Delay Slot)
        SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 16), 112));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x12432Cu;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123E18u: goto label_123e18;
            case 0x123E20u: goto label_123e20;
            case 0x123E98u: goto label_123e98;
            case 0x123F28u: goto label_123f28;
            case 0x123F38u: goto label_123f38;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FF4u: goto label_123ff4;
            case 0x124014u: goto label_124014;
            case 0x124070u: goto label_124070;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240F8u: goto label_1240f8;
            case 0x124118u: goto label_124118;
            case 0x124138u: goto label_124138;
            case 0x124144u: goto label_124144;
            case 0x124158u: goto label_124158;
            case 0x12418Cu: goto label_12418c;
            case 0x1241ACu: goto label_1241ac;
            case 0x124208u: goto label_124208;
            case 0x124248u: goto label_124248;
            case 0x124258u: goto label_124258;
            case 0x12427Cu: goto label_12427c;
            case 0x124298u: goto label_124298;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242D8u: goto label_1242d8;
            case 0x12430Cu: goto label_12430c;
            case 0x12432Cu: goto label_12432c;
            case 0x124390u: goto label_124390;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243F8u: goto label_1243f8;
            case 0x124424u: goto label_124424;
            case 0x124440u: goto label_124440;
            case 0x124460u: goto label_124460;
            case 0x12446Cu: goto label_12446c;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244B8u: goto label_1244b8;
            case 0x124504u: goto label_124504;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x12432Cu; }
            if (ctx->pc != 0x12432Cu) { return; }
        }
        }
    }
    ctx->pc = 0x12432Cu;
label_12432c:
    // 0x12432c: 0x8e240018  lw          $a0, 0x18($s1)
    ctx->pc = 0x12432cu;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 24)));
    // 0x124330: 0x8e270020  lw          $a3, 0x20($s1)
    ctx->pc = 0x124330u;
    SET_GPR_S32(ctx, 7, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 32)));
    // 0x124334: 0x24060002  addiu       $a2, $zero, 0x2
    ctx->pc = 0x124334u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x124338: 0x8e230024  lw          $v1, 0x24($s1)
    ctx->pc = 0x124338u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 36)));
    // 0x12433c: 0x874823  subu        $t1, $a0, $a3
    ctx->pc = 0x12433cu;
    SET_GPR_S32(ctx, 9, (int32_t)SUB32(GPR_U32(ctx, 4), GPR_U32(ctx, 7)));
    // 0x124340: 0x8204000e  lb          $a0, 0xE($s0)
    ctx->pc = 0x124340u;
    SET_GPR_S32(ctx, 4, (int8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
    // 0x124344: 0x69102a  slt         $v0, $v1, $t1
    ctx->pc = 0x124344u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 3) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x124348: 0x8e250004  lw          $a1, 0x4($s1)
    ctx->pc = 0x124348u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 4)));
    // 0x12434c: 0x62480b  movn        $t1, $v1, $v0
    ctx->pc = 0x12434cu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 3));
    // 0x124350: 0x71840  sll         $v1, $a3, 1
    ctx->pc = 0x124350u;
    SET_GPR_S32(ctx, 3, (int32_t)SLL32(GPR_U32(ctx, 7), 1));
    // 0x124354: 0x8e2a0014  lw          $t2, 0x14($s1)
    ctx->pc = 0x124354u;
    SET_GPR_S32(ctx, 10, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 20)));
    // 0x124358: 0xa9102a  slt         $v0, $a1, $t1
    ctx->pc = 0x124358u;
    SET_GPR_U64(ctx, 2, ((int64_t)GPR_S64(ctx, 5) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x12435c: 0xa2480b  movn        $t1, $a1, $v0
    ctx->pc = 0x12435cu;
    if (GPR_U64(ctx, 2) != 0) SET_GPR_VEC(ctx, 9, GPR_VEC(ctx, 5));
    // 0x124360: 0x1435821  addu        $t3, $t2, $v1
    ctx->pc = 0x124360u;
    SET_GPR_S32(ctx, 11, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 3)));
    // 0x124364: 0x1486001e  bne         $a0, $a2, . + 4 + (0x1E << 2)
    ctx->pc = 0x124364u;
    {
        const bool branch_taken_0x124364 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 6));
        ctx->pc = 0x124368u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124364u;
            // 0x124368: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124364) {
            ctx->pc = 0x1243E0u;
            goto label_1243e0;
        }
    }
    ctx->pc = 0x12436Cu;
    // 0x12436c: 0x8e22001c  lw          $v0, 0x1C($s1)
    ctx->pc = 0x12436cu;
    SET_GPR_S32(ctx, 2, (int32_t)READ32(ADD32(GPR_U32(ctx, 17), 28)));
    // 0x124370: 0x402d  daddu       $t0, $zero, $zero
    ctx->pc = 0x124370u;
    SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x124374: 0x471021  addu        $v0, $v0, $a3
    ctx->pc = 0x124374u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 7)));
    // 0x124378: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x124378u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x12437c: 0x19200029  blez        $t1, . + 4 + (0x29 << 2)
    ctx->pc = 0x12437Cu;
    {
        const bool branch_taken_0x12437c = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x124380u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12437Cu;
            // 0x124380: 0x1426021  addu        $t4, $t2, $v0 (Delay Slot)
        SET_GPR_S32(ctx, 12, (int32_t)ADD32(GPR_U32(ctx, 10), GPR_U32(ctx, 2)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x12437c) {
            ctx->pc = 0x124424u;
            goto label_124424;
        }
    }
    ctx->pc = 0x124384u;
    // 0x124384: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x124384u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x124388: 0x240382d  daddu       $a3, $s2, $zero
    ctx->pc = 0x124388u;
    SET_GPR_U64(ctx, 7, (uint64_t)GPR_U64(ctx, 18) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12438c: 0x244ab738  addiu       $t2, $v0, -0x48C8
    ctx->pc = 0x12438cu;
    SET_GPR_S32(ctx, 10, (int32_t)ADD32(GPR_U32(ctx, 2), 4294948664));
label_124390:
    // 0x124390: 0x90e20000  lbu         $v0, 0x0($a3)
    ctx->pc = 0x124390u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 0)));
    // 0x124394: 0x82040  sll         $a0, $t0, 1
    ctx->pc = 0x124394u;
    SET_GPR_S32(ctx, 4, (int32_t)SLL32(GPR_U32(ctx, 8), 1));
    // 0x124398: 0x8b2821  addu        $a1, $a0, $t3
    ctx->pc = 0x124398u;
    SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 11)));
    // 0x12439c: 0x8c2021  addu        $a0, $a0, $t4
    ctx->pc = 0x12439cu;
    SET_GPR_S32(ctx, 4, (int32_t)ADD32(GPR_U32(ctx, 4), GPR_U32(ctx, 12)));
    // 0x1243a0: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1243a0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1243a4: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1243a4u;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x1243a8: 0x4a1021  addu        $v0, $v0, $t2
    ctx->pc = 0x1243a8u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x1243ac: 0x109302a  slt         $a2, $t0, $t1
    ctx->pc = 0x1243acu;
    SET_GPR_U64(ctx, 6, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x1243b0: 0x94430000  lhu         $v1, 0x0($v0)
    ctx->pc = 0x1243b0u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1243b4: 0xa4a30000  sh          $v1, 0x0($a1)
    ctx->pc = 0x1243b4u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x1243b8: 0x90e20001  lbu         $v0, 0x1($a3)
    ctx->pc = 0x1243b8u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 7), 1)));
    // 0x1243bc: 0x24e70002  addiu       $a3, $a3, 0x2
    ctx->pc = 0x1243bcu;
    SET_GPR_S32(ctx, 7, (int32_t)ADD32(GPR_U32(ctx, 7), 2));
    // 0x1243c0: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x1243c0u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x1243c4: 0x4a1021  addu        $v0, $v0, $t2
    ctx->pc = 0x1243c4u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 10)));
    // 0x1243c8: 0x94430000  lhu         $v1, 0x0($v0)
    ctx->pc = 0x1243c8u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x1243cc: 0x14c0fff0  bnez        $a2, . + 4 + (-0x10 << 2)
    ctx->pc = 0x1243CCu;
    {
        const bool branch_taken_0x1243cc = (GPR_U64(ctx, 6) != GPR_U64(ctx, 0));
        ctx->pc = 0x1243D0u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1243CCu;
            // 0x1243d0: 0xa4830000  sh          $v1, 0x0($a0) (Delay Slot)
        WRITE16(ADD32(GPR_U32(ctx, 4), 0), (uint16_t)GPR_U32(ctx, 3));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1243cc) {
            ctx->pc = 0x124390u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_124390;
        }
    }
    ctx->pc = 0x1243D4u;
    // 0x1243d4: 0x10000013  b           . + 4 + (0x13 << 2)
    ctx->pc = 0x1243D4u;
    {
        const bool branch_taken_0x1243d4 = (GPR_U64(ctx, 0) == GPR_U64(ctx, 0));
        ctx->pc = 0x1243D8u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1243D4u;
            // 0x1243d8: 0x9203000e  lbu         $v1, 0xE($s0) (Delay Slot)
        SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1243d4) {
            ctx->pc = 0x124424u;
            goto label_124424;
        }
    }
    ctx->pc = 0x1243DCu;
    // 0x1243dc: 0x0  nop
    ctx->pc = 0x1243dcu;
    // NOP
label_1243e0:
    // 0x1243e0: 0x19200010  blez        $t1, . + 4 + (0x10 << 2)
    ctx->pc = 0x1243E0u;
    {
        const bool branch_taken_0x1243e0 = (GPR_S64(ctx, 9) <= 0);
        ctx->pc = 0x1243E4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1243E0u;
            // 0x1243e4: 0x402d  daddu       $t0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 8, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1243e0) {
            ctx->pc = 0x124424u;
            goto label_124424;
        }
    }
    ctx->pc = 0x1243E8u;
    // 0x1243e8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1243e8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1243ec: 0x160282d  daddu       $a1, $t3, $zero
    ctx->pc = 0x1243ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 11) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1243f0: 0x2446b738  addiu       $a2, $v0, -0x48C8
    ctx->pc = 0x1243f0u;
    SET_GPR_S32(ctx, 6, (int32_t)ADD32(GPR_U32(ctx, 2), 4294948664));
    // 0x1243f4: 0x0  nop
    ctx->pc = 0x1243f4u;
    // NOP
label_1243f8:
    // 0x1243f8: 0x2481821  addu        $v1, $s2, $t0
    ctx->pc = 0x1243f8u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 18), GPR_U32(ctx, 8)));
    // 0x1243fc: 0x25080001  addiu       $t0, $t0, 0x1
    ctx->pc = 0x1243fcu;
    SET_GPR_S32(ctx, 8, (int32_t)ADD32(GPR_U32(ctx, 8), 1));
    // 0x124400: 0x90620000  lbu         $v0, 0x0($v1)
    ctx->pc = 0x124400u;
    SET_GPR_U32(ctx, 2, (uint8_t)READ8(ADD32(GPR_U32(ctx, 3), 0)));
    // 0x124404: 0x109202a  slt         $a0, $t0, $t1
    ctx->pc = 0x124404u;
    SET_GPR_U64(ctx, 4, ((int64_t)GPR_S64(ctx, 8) < (int64_t)GPR_S64(ctx, 9)) ? 1 : 0);
    // 0x124408: 0x21040  sll         $v0, $v0, 1
    ctx->pc = 0x124408u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 2), 1));
    // 0x12440c: 0x461021  addu        $v0, $v0, $a2
    ctx->pc = 0x12440cu;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 2), GPR_U32(ctx, 6)));
    // 0x124410: 0x94430000  lhu         $v1, 0x0($v0)
    ctx->pc = 0x124410u;
    SET_GPR_U32(ctx, 3, (uint16_t)READ16(ADD32(GPR_U32(ctx, 2), 0)));
    // 0x124414: 0xa4a30000  sh          $v1, 0x0($a1)
    ctx->pc = 0x124414u;
    WRITE16(ADD32(GPR_U32(ctx, 5), 0), (uint16_t)GPR_U32(ctx, 3));
    // 0x124418: 0x1480fff7  bnez        $a0, . + 4 + (-0x9 << 2)
    ctx->pc = 0x124418u;
    {
        const bool branch_taken_0x124418 = (GPR_U64(ctx, 4) != GPR_U64(ctx, 0));
        ctx->pc = 0x12441Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124418u;
            // 0x12441c: 0x24a50002  addiu       $a1, $a1, 0x2 (Delay Slot)
        SET_GPR_S32(ctx, 5, (int32_t)ADD32(GPR_U32(ctx, 5), 2));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124418) {
            ctx->pc = 0x1243F8u;
            if (runtime->shouldPreemptGuestExecution()) {
                return;
            }
            goto label_1243f8;
        }
    }
    ctx->pc = 0x124420u;
    // 0x124420: 0x9203000e  lbu         $v1, 0xE($s0)
    ctx->pc = 0x124420u;
    SET_GPR_U32(ctx, 3, (uint8_t)READ8(ADD32(GPR_U32(ctx, 16), 14)));
label_124424:
    // 0x124424: 0x31600  sll         $v0, $v1, 24
    ctx->pc = 0x124424u;
    SET_GPR_S32(ctx, 2, (int32_t)SLL32(GPR_U32(ctx, 3), 24));
    // 0x124428: 0x24030002  addiu       $v1, $zero, 0x2
    ctx->pc = 0x124428u;
    SET_GPR_S32(ctx, 3, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x12442c: 0x21603  sra         $v0, $v0, 24
    ctx->pc = 0x12442cu;
    SET_GPR_S32(ctx, 2, SRA32(GPR_S32(ctx, 2), 24));
    // 0x124430: 0xae030004  sw          $v1, 0x4($s0)
    ctx->pc = 0x124430u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 3));
    // 0x124434: 0x1221018  mult        $v0, $t1, $v0
    ctx->pc = 0x124434u;
    { int64_t result = (int64_t)GPR_S32(ctx, 9) * (int64_t)GPR_S32(ctx, 2); ctx->lo = (uint64_t)(int64_t)(int32_t)result; ctx->hi = (uint64_t)(int64_t)(int32_t)(result >> 32); SET_GPR_S32(ctx, 2, (int32_t)result); }
    // 0x124438: 0xae090090  sw          $t1, 0x90($s0)
    ctx->pc = 0x124438u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 144), GPR_U32(ctx, 9));
    // 0x12443c: 0xae020094  sw          $v0, 0x94($s0)
    ctx->pc = 0x12443cu;
    WRITE32(ADD32(GPR_U32(ctx, 16), 148), GPR_U32(ctx, 2));
label_124440:
    // 0x124440: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x124440u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x124444: 0x54620009  bnel        $v1, $v0, . + 4 + (0x9 << 2)
    ctx->pc = 0x124444u;
    {
        const bool branch_taken_0x124444 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        if (branch_taken_0x124444) {
            ctx->pc = 0x124448u;
            ctx->in_delay_slot = true; ctx->branch_pc = 0x124444u;
            // 0x124448: 0xdfb00000  ld          $s0, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
            ctx->pc = 0x12446Cu;
            goto label_12446c;
        }
    }
    ctx->pc = 0x12444Cu;
    // 0x12444c: 0x8e030080  lw          $v1, 0x80($s0)
    ctx->pc = 0x12444cu;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 128)));
    // 0x124450: 0x8e040084  lw          $a0, 0x84($s0)
    ctx->pc = 0x124450u;
    SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 132)));
    // 0x124454: 0x8e050094  lw          $a1, 0x94($s0)
    ctx->pc = 0x124454u;
    SET_GPR_S32(ctx, 5, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 148)));
    // 0x124458: 0x60f809  jalr        $v1
    ctx->pc = 0x124458u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x124460u);
        ctx->pc = 0x12445Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124458u;
            // 0x12445c: 0x8e060090  lw          $a2, 0x90($s0) (Delay Slot)
        SET_GPR_S32(ctx, 6, (int32_t)READ32(ADD32(GPR_U32(ctx, 16), 144)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x124460u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123E18u: goto label_123e18;
            case 0x123E20u: goto label_123e20;
            case 0x123E98u: goto label_123e98;
            case 0x123F28u: goto label_123f28;
            case 0x123F38u: goto label_123f38;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FF4u: goto label_123ff4;
            case 0x124014u: goto label_124014;
            case 0x124070u: goto label_124070;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240F8u: goto label_1240f8;
            case 0x124118u: goto label_124118;
            case 0x124138u: goto label_124138;
            case 0x124144u: goto label_124144;
            case 0x124158u: goto label_124158;
            case 0x12418Cu: goto label_12418c;
            case 0x1241ACu: goto label_1241ac;
            case 0x124208u: goto label_124208;
            case 0x124248u: goto label_124248;
            case 0x124258u: goto label_124258;
            case 0x12427Cu: goto label_12427c;
            case 0x124298u: goto label_124298;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242D8u: goto label_1242d8;
            case 0x12430Cu: goto label_12430c;
            case 0x12432Cu: goto label_12432c;
            case 0x124390u: goto label_124390;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243F8u: goto label_1243f8;
            case 0x124424u: goto label_124424;
            case 0x124440u: goto label_124440;
            case 0x124460u: goto label_124460;
            case 0x12446Cu: goto label_12446c;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244B8u: goto label_1244b8;
            case 0x124504u: goto label_124504;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x124460u; }
            if (ctx->pc != 0x124460u) { return; }
        }
        }
    }
    ctx->pc = 0x124460u;
label_124460:
    // 0x124460: 0x24020003  addiu       $v0, $zero, 0x3
    ctx->pc = 0x124460u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 3));
    // 0x124464: 0xae020004  sw          $v0, 0x4($s0)
    ctx->pc = 0x124464u;
    WRITE32(ADD32(GPR_U32(ctx, 16), 4), GPR_U32(ctx, 2));
    // 0x124468: 0xdfb00000  ld          $s0, 0x0($sp)
    ctx->pc = 0x124468u;
    SET_GPR_U64(ctx, 16, READ64(ADD32(GPR_U32(ctx, 29), 0)));
label_12446c:
    // 0x12446c: 0xdfb10008  ld          $s1, 0x8($sp)
    ctx->pc = 0x12446cu;
    SET_GPR_U64(ctx, 17, READ64(ADD32(GPR_U32(ctx, 29), 8)));
    // 0x124470: 0xdfb20010  ld          $s2, 0x10($sp)
    ctx->pc = 0x124470u;
    SET_GPR_U64(ctx, 18, READ64(ADD32(GPR_U32(ctx, 29), 16)));
    // 0x124474: 0xdfbf0018  ld          $ra, 0x18($sp)
    ctx->pc = 0x124474u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 24)));
    // 0x124478: 0x3e00008  jr          $ra
    ctx->pc = 0x124478u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x12447Cu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124478u;
            // 0x12447c: 0x27bd0020  addiu       $sp, $sp, 0x20 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 32));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123E18u: goto label_123e18;
            case 0x123E20u: goto label_123e20;
            case 0x123E98u: goto label_123e98;
            case 0x123F28u: goto label_123f28;
            case 0x123F38u: goto label_123f38;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FF4u: goto label_123ff4;
            case 0x124014u: goto label_124014;
            case 0x124070u: goto label_124070;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240F8u: goto label_1240f8;
            case 0x124118u: goto label_124118;
            case 0x124138u: goto label_124138;
            case 0x124144u: goto label_124144;
            case 0x124158u: goto label_124158;
            case 0x12418Cu: goto label_12418c;
            case 0x1241ACu: goto label_1241ac;
            case 0x124208u: goto label_124208;
            case 0x124248u: goto label_124248;
            case 0x124258u: goto label_124258;
            case 0x12427Cu: goto label_12427c;
            case 0x124298u: goto label_124298;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242D8u: goto label_1242d8;
            case 0x12430Cu: goto label_12430c;
            case 0x12432Cu: goto label_12432c;
            case 0x124390u: goto label_124390;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243F8u: goto label_1243f8;
            case 0x124424u: goto label_124424;
            case 0x124440u: goto label_124440;
            case 0x124460u: goto label_124460;
            case 0x12446Cu: goto label_12446c;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244B8u: goto label_1244b8;
            case 0x124504u: goto label_124504;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124480u;
    // 0x124480: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x124480u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x124484: 0x24020002  addiu       $v0, $zero, 0x2
    ctx->pc = 0x124484u;
    SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 2));
    // 0x124488: 0xffbf0000  sd          $ra, 0x0($sp)
    ctx->pc = 0x124488u;
    WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
    // 0x12448c: 0x8483009a  lh          $v1, 0x9A($a0)
    ctx->pc = 0x12448cu;
    SET_GPR_S32(ctx, 3, (int16_t)READ16(ADD32(GPR_U32(ctx, 4), 154)));
    // 0x124490: 0x14620005  bne         $v1, $v0, . + 4 + (0x5 << 2)
    ctx->pc = 0x124490u;
    {
        const bool branch_taken_0x124490 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x124494u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x124490u;
            // 0x124494: 0x24020001  addiu       $v0, $zero, 0x1 (Delay Slot)
        SET_GPR_S32(ctx, 2, (int32_t)ADD32(GPR_U32(ctx, 0), 1));
        ctx->in_delay_slot = false;
        if (branch_taken_0x124490) {
            ctx->pc = 0x1244A8u;
            goto label_1244a8;
        }
    }
    ctx->pc = 0x124498u;
    // 0x124498: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x124498u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x12449c: 0x80490b6  j           func_1242D8
    ctx->pc = 0x12449Cu;
    ctx->pc = 0x1244A0u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x12449Cu;
            // 0x1244a0: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x1242D8u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_1242d8;
    ctx->pc = 0x1244A4u;
    // 0x1244a4: 0x0  nop
    ctx->pc = 0x1244a4u;
    // NOP
label_1244a8:
    // 0x1244a8: 0x14620003  bne         $v1, $v0, . + 4 + (0x3 << 2)
    ctx->pc = 0x1244A8u;
    {
        const bool branch_taken_0x1244a8 = (GPR_U64(ctx, 3) != GPR_U64(ctx, 2));
        ctx->pc = 0x1244ACu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1244A8u;
            // 0x1244ac: 0xdfbf0000  ld          $ra, 0x0($sp) (Delay Slot)
        SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1244a8) {
            ctx->pc = 0x1244B8u;
            goto label_1244b8;
        }
    }
    ctx->pc = 0x1244B0u;
    // 0x1244b0: 0x8049056  j           func_124158
    ctx->pc = 0x1244B0u;
    ctx->pc = 0x1244B4u;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1244B0u;
            // 0x1244b4: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x124158u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_124158;
    ctx->pc = 0x1244B8u;
label_1244b8:
    // 0x1244b8: 0x8048ff0  j           func_123FC0
    ctx->pc = 0x1244B8u;
    ctx->pc = 0x1244BCu;
    ctx->in_delay_slot = true; ctx->branch_pc = 0x1244B8u;
            // 0x1244bc: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
    ctx->pc = 0x123FC0u;
    if (runtime->shouldPreemptGuestExecution()) {
        return;
    }
    goto label_123fc0;
    ctx->pc = 0x1244C0u;
    // 0x1244c0: 0x3e00008  jr          $ra
    ctx->pc = 0x1244C0u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1244C4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1244C0u;
            // 0x1244c4: 0x102d  daddu       $v0, $zero, $zero (Delay Slot)
        SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123E18u: goto label_123e18;
            case 0x123E20u: goto label_123e20;
            case 0x123E98u: goto label_123e98;
            case 0x123F28u: goto label_123f28;
            case 0x123F38u: goto label_123f38;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FF4u: goto label_123ff4;
            case 0x124014u: goto label_124014;
            case 0x124070u: goto label_124070;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240F8u: goto label_1240f8;
            case 0x124118u: goto label_124118;
            case 0x124138u: goto label_124138;
            case 0x124144u: goto label_124144;
            case 0x124158u: goto label_124158;
            case 0x12418Cu: goto label_12418c;
            case 0x1241ACu: goto label_1241ac;
            case 0x124208u: goto label_124208;
            case 0x124248u: goto label_124248;
            case 0x124258u: goto label_124258;
            case 0x12427Cu: goto label_12427c;
            case 0x124298u: goto label_124298;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242D8u: goto label_1242d8;
            case 0x12430Cu: goto label_12430c;
            case 0x12432Cu: goto label_12432c;
            case 0x124390u: goto label_124390;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243F8u: goto label_1243f8;
            case 0x124424u: goto label_124424;
            case 0x124440u: goto label_124440;
            case 0x124460u: goto label_124460;
            case 0x12446Cu: goto label_12446c;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244B8u: goto label_1244b8;
            case 0x124504u: goto label_124504;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1244C8u;
    // 0x1244c8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1244c8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1244cc: 0x3c030021  lui         $v1, 0x21
    ctx->pc = 0x1244ccu;
    SET_GPR_S32(ctx, 3, (int32_t)((uint32_t)33 << 16));
    // 0x1244d0: 0xac44b940  sw          $a0, -0x46C0($v0)
    ctx->pc = 0x1244d0u;
    WRITE32(ADD32(GPR_U32(ctx, 2), 4294949184), GPR_U32(ctx, 4));
    // 0x1244d4: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x1244d4u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1244d8: 0x3e00008  jr          $ra
    ctx->pc = 0x1244D8u;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x1244DCu;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1244D8u;
            // 0x1244dc: 0xac65b944  sw          $a1, -0x46BC($v1) (Delay Slot)
        WRITE32(ADD32(GPR_U32(ctx, 3), 4294949188), GPR_U32(ctx, 5));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123E18u: goto label_123e18;
            case 0x123E20u: goto label_123e20;
            case 0x123E98u: goto label_123e98;
            case 0x123F28u: goto label_123f28;
            case 0x123F38u: goto label_123f38;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FF4u: goto label_123ff4;
            case 0x124014u: goto label_124014;
            case 0x124070u: goto label_124070;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240F8u: goto label_1240f8;
            case 0x124118u: goto label_124118;
            case 0x124138u: goto label_124138;
            case 0x124144u: goto label_124144;
            case 0x124158u: goto label_124158;
            case 0x12418Cu: goto label_12418c;
            case 0x1241ACu: goto label_1241ac;
            case 0x124208u: goto label_124208;
            case 0x124248u: goto label_124248;
            case 0x124258u: goto label_124258;
            case 0x12427Cu: goto label_12427c;
            case 0x124298u: goto label_124298;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242D8u: goto label_1242d8;
            case 0x12430Cu: goto label_12430c;
            case 0x12432Cu: goto label_12432c;
            case 0x124390u: goto label_124390;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243F8u: goto label_1243f8;
            case 0x124424u: goto label_124424;
            case 0x124440u: goto label_124440;
            case 0x124460u: goto label_124460;
            case 0x12446Cu: goto label_12446c;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244B8u: goto label_1244b8;
            case 0x124504u: goto label_124504;
            default: break;
        }
        return;
    }
    ctx->pc = 0x1244E0u;
    // 0x1244e0: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1244e0u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1244e4: 0x27bdfff0  addiu       $sp, $sp, -0x10
    ctx->pc = 0x1244e4u;
    SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 4294967280));
    // 0x1244e8: 0x8c43b940  lw          $v1, -0x46C0($v0)
    ctx->pc = 0x1244e8u;
    SET_GPR_S32(ctx, 3, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294949184)));
    // 0x1244ec: 0x80282d  daddu       $a1, $a0, $zero
    ctx->pc = 0x1244ecu;
    SET_GPR_U64(ctx, 5, (uint64_t)GPR_U64(ctx, 4) + (uint64_t)GPR_U64(ctx, 0));
    // 0x1244f0: 0x10600004  beqz        $v1, . + 4 + (0x4 << 2)
    ctx->pc = 0x1244F0u;
    {
        const bool branch_taken_0x1244f0 = (GPR_U64(ctx, 3) == GPR_U64(ctx, 0));
        ctx->pc = 0x1244F4u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1244F0u;
            // 0x1244f4: 0xffbf0000  sd          $ra, 0x0($sp) (Delay Slot)
        WRITE64(ADD32(GPR_U32(ctx, 29), 0), GPR_U64(ctx, 31));
        ctx->in_delay_slot = false;
        if (branch_taken_0x1244f0) {
            ctx->pc = 0x124504u;
            goto label_124504;
        }
    }
    ctx->pc = 0x1244F8u;
    // 0x1244f8: 0x3c020021  lui         $v0, 0x21
    ctx->pc = 0x1244f8u;
    SET_GPR_S32(ctx, 2, (int32_t)((uint32_t)33 << 16));
    // 0x1244fc: 0x60f809  jalr        $v1
    ctx->pc = 0x1244FCu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 3);
        SET_GPR_U32(ctx, 31, 0x124504u);
        ctx->pc = 0x124500u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x1244FCu;
            // 0x124500: 0x8c44b944  lw          $a0, -0x46BC($v0) (Delay Slot)
        SET_GPR_S32(ctx, 4, (int32_t)READ32(ADD32(GPR_U32(ctx, 2), 4294949188)));
        ctx->in_delay_slot = false;
        if (jumpTarget == 0u) {
            ctx->pc = 0x124504u;
        } else {
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123E18u: goto label_123e18;
            case 0x123E20u: goto label_123e20;
            case 0x123E98u: goto label_123e98;
            case 0x123F28u: goto label_123f28;
            case 0x123F38u: goto label_123f38;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FF4u: goto label_123ff4;
            case 0x124014u: goto label_124014;
            case 0x124070u: goto label_124070;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240F8u: goto label_1240f8;
            case 0x124118u: goto label_124118;
            case 0x124138u: goto label_124138;
            case 0x124144u: goto label_124144;
            case 0x124158u: goto label_124158;
            case 0x12418Cu: goto label_12418c;
            case 0x1241ACu: goto label_1241ac;
            case 0x124208u: goto label_124208;
            case 0x124248u: goto label_124248;
            case 0x124258u: goto label_124258;
            case 0x12427Cu: goto label_12427c;
            case 0x124298u: goto label_124298;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242D8u: goto label_1242d8;
            case 0x12430Cu: goto label_12430c;
            case 0x12432Cu: goto label_12432c;
            case 0x124390u: goto label_124390;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243F8u: goto label_1243f8;
            case 0x124424u: goto label_124424;
            case 0x124440u: goto label_124440;
            case 0x124460u: goto label_124460;
            case 0x12446Cu: goto label_12446c;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244B8u: goto label_1244b8;
            case 0x124504u: goto label_124504;
            default: break;
        }
        {
            auto targetFn = runtime->lookupFunction(jumpTarget);
            const uint32_t __entryPc = ctx->pc;
            targetFn(rdram, ctx, runtime);
            if (ctx->pc == __entryPc) { ctx->pc = 0x124504u; }
            if (ctx->pc != 0x124504u) { return; }
        }
        }
    }
    ctx->pc = 0x124504u;
label_124504:
    // 0x124504: 0xdfbf0000  ld          $ra, 0x0($sp)
    ctx->pc = 0x124504u;
    SET_GPR_U64(ctx, 31, READ64(ADD32(GPR_U32(ctx, 29), 0)));
    // 0x124508: 0x102d  daddu       $v0, $zero, $zero
    ctx->pc = 0x124508u;
    SET_GPR_U64(ctx, 2, (uint64_t)GPR_U64(ctx, 0) + (uint64_t)GPR_U64(ctx, 0));
    // 0x12450c: 0x3e00008  jr          $ra
    ctx->pc = 0x12450Cu;
    {
        uint32_t jumpTarget = GPR_U32(ctx, 31);
        ctx->pc = 0x124510u;
        ctx->in_delay_slot = true; ctx->branch_pc = 0x12450Cu;
            // 0x124510: 0x27bd0010  addiu       $sp, $sp, 0x10 (Delay Slot)
        SET_GPR_S32(ctx, 29, (int32_t)ADD32(GPR_U32(ctx, 29), 16));
        ctx->in_delay_slot = false;
        ctx->pc = jumpTarget;
        switch (jumpTarget) {
            case 0x123DB0u: goto label_123db0;
            case 0x123E18u: goto label_123e18;
            case 0x123E20u: goto label_123e20;
            case 0x123E98u: goto label_123e98;
            case 0x123F28u: goto label_123f28;
            case 0x123F38u: goto label_123f38;
            case 0x123FA0u: goto label_123fa0;
            case 0x123FC0u: goto label_123fc0;
            case 0x123FF4u: goto label_123ff4;
            case 0x124014u: goto label_124014;
            case 0x124070u: goto label_124070;
            case 0x1240C0u: goto label_1240c0;
            case 0x1240C8u: goto label_1240c8;
            case 0x1240F8u: goto label_1240f8;
            case 0x124118u: goto label_124118;
            case 0x124138u: goto label_124138;
            case 0x124144u: goto label_124144;
            case 0x124158u: goto label_124158;
            case 0x12418Cu: goto label_12418c;
            case 0x1241ACu: goto label_1241ac;
            case 0x124208u: goto label_124208;
            case 0x124248u: goto label_124248;
            case 0x124258u: goto label_124258;
            case 0x12427Cu: goto label_12427c;
            case 0x124298u: goto label_124298;
            case 0x1242B8u: goto label_1242b8;
            case 0x1242C4u: goto label_1242c4;
            case 0x1242D8u: goto label_1242d8;
            case 0x12430Cu: goto label_12430c;
            case 0x12432Cu: goto label_12432c;
            case 0x124390u: goto label_124390;
            case 0x1243E0u: goto label_1243e0;
            case 0x1243F8u: goto label_1243f8;
            case 0x124424u: goto label_124424;
            case 0x124440u: goto label_124440;
            case 0x124460u: goto label_124460;
            case 0x12446Cu: goto label_12446c;
            case 0x1244A8u: goto label_1244a8;
            case 0x1244B8u: goto label_1244b8;
            case 0x124504u: goto label_124504;
            default: break;
        }
        return;
    }
    ctx->pc = 0x124514u;
    // 0x124514: 0x0  nop
    ctx->pc = 0x124514u;
    // NOP
    ctx->pc = GPR_U32(ctx, 31); return;
}
